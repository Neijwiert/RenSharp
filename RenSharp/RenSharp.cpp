/*
Copyright 2020 Neijwiert

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "general.h"
#include <engine.h>
#include <engine_da.h>
#include <da.h>
#include "RenSharp.h"
#include <da_settings.h>
#include <da_translation.h>
#include <da_vehicle.h>
#include <limits>
#include <metahost.h>
#include <comdef.h>
#include "RenSharpHostControl.h"

// We need this boolean to stop the FDS gracefully the same way 'quit' does
REF_DEF2(bool, cGameData::IsManualExit, 0x0082F125, 0x0082E30D);

static LPCWSTR AppDomainManagerTypeAssemblyName = L"ManagedRenSharp, Version=1.4.0.0, Culture=neutral, PublicKeyToken=c2f4cb925e8b2a8a";
static LPCWSTR AppDomainManagerTypeName = L"RenSharp.RenSharpAppDomainManager";

BOOL WINAPI ConsoleCtrlHandlerRoutine(_In_ DWORD dwCtrlType)
{
	if (dwCtrlType == CTRL_CLOSE_EVENT || dwCtrlType == CTRL_LOGOFF_EVENT || dwCtrlType == CTRL_SHUTDOWN_EVENT)
	{
		RenSharpRootEventClass::Get_Instance().Shutdown();
	}

	return TRUE;
}

RenSharpRootEventClass::RenSharpRootEventClass()
	: shutdown(false), shutdownPending(false), metaHost(nullptr), runtimeInfo(nullptr), clrRuntimeHost(nullptr), clrControl(nullptr), hostControl(nullptr)
{
	Register_Event(DAEvent::GAMEOVER, (std::numeric_limits<int>::min)());
	Register_Event(DAEvent::THINK, (std::numeric_limits<int>::max)());
}

RenSharpRootEventClass::~RenSharpRootEventClass()
{
	// Cannot call shutdown, since we don't know if the CLR engine will work here
}

void RenSharpRootEventClass::On_Fatal_Exception(const char *exception)
{
	Dump_Exception(exception);

	// Cannot shutdown CRL here or else we would return to the domain while we shut it down.
	// Whatever event went into the CLR domain should return a HRResult of failed which should already trigger a shutdown
	shutdown = true;
}

void RenSharpRootEventClass::On_Fatal_Exception_Callback(const char* exception)
{
	Dump_Exception(exception);

	// This exception occured in a callback (unmanaged side invoking a delegate on the managed side)
	// We need to a schedule a shutdown since it isn't going to happen automatically
	shutdown = true;
	shutdownPending = true;
}

HRESULT RenSharpRootEventClass::Init()
{
	HRESULT hr = S_OK;

	if (!shutdown)
	{
		// Create a metahost instance
		if (SUCCEEDED(hr = CLRCreateInstance(CLSID_CLRMetaHost, IID_ICLRMetaHost, reinterpret_cast<LPVOID *>(&metaHost))))
		{
			// Iterate runtimes
			IEnumUnknown *installedRuntimes = nullptr;
			if (SUCCEEDED(hr = metaHost->EnumerateInstalledRuntimes(&installedRuntimes)))
			{
				ICLRRuntimeInfo *currentRuntimeInfo = nullptr;
				ULONG fetched = 0;
				while (SUCCEEDED(hr = installedRuntimes->Next(1, reinterpret_cast<IUnknown **>(&currentRuntimeInfo), &fetched)) && fetched > 0)
				{
					// Get version string of current runtime
					DWORD versionStringSize;
					if (SUCCEEDED(hr = currentRuntimeInfo->GetVersionString(nullptr, &versionStringSize)))
					{
						LPWSTR versionString = new WCHAR[versionStringSize];
						if (SUCCEEDED(hr = currentRuntimeInfo->GetVersionString(versionString, &versionStringSize)))
						{
							// Check if it starts with v4 (we want a v4.xxx)
							if (versionStringSize >= 2 && versionString[0] == L'v' && versionString[1] == L'4')
							{
								// Use this runtime and see if there are any newer
								if (runtimeInfo != nullptr)
								{
									runtimeInfo->Release();
								}

								runtimeInfo = currentRuntimeInfo;
								currentRuntimeInfo = nullptr;
							}
							else
							{
								Console_Output("INFO: Skipped unsuitable runtime version '%ls'\n", versionString);
							}
						}
						else
						{
							Console_Output("WARNING: Failed to get the version string for the current enumerated runtime (HRESULT: %d)\n", hr);
						}

						delete[] versionString;
						versionString = nullptr;
					}
					else
					{
						Console_Output("WARNING: Failed to determine the size of the version string for the current enumerated runtime (HRESULT: %d)\n", hr);
					}

					if (currentRuntimeInfo != nullptr)
					{
						currentRuntimeInfo->Release();
						currentRuntimeInfo = nullptr;
					}
				}
			}
			else
			{
				Console_Output("ERROR: Failed to enumerate the installed runtimes (HRESULT: %d)\n", hr);
			}

			if (runtimeInfo != nullptr)
			{
				// Get the runtime host
				if (SUCCEEDED(hr = runtimeInfo->GetInterface(CLSID_CLRRuntimeHost, IID_ICLRRuntimeHost, reinterpret_cast<void **>(&clrRuntimeHost))))
				{
					// Set the host control
					hostControl = new RenSharpHostControl();
					if (SUCCEEDED(hr = clrRuntimeHost->SetHostControl(hostControl)))
					{
						if (SUCCEEDED(hr = clrRuntimeHost->GetCLRControl(&clrControl)))
						{
							// Set the app domain manager type
							if (SUCCEEDED(hr = clrControl->SetAppDomainManagerType(AppDomainManagerTypeAssemblyName, AppDomainManagerTypeName)))
							{
								// Start the runtime host
								if (SUCCEEDED(hr = clrRuntimeHost->Start()))
								{
									RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();

									BOOL initResult;
									if (SUCCEEDED(hr = rsInterface->Init(&initResult)))
									{
										if (initResult == FALSE)
										{
											// Something went wrong at the managed side
											hr = E_UNEXPECTED;
										}
									}
									else
									{
										Console_Output("ERROR: Failed to initialize RenSharp (HRESULT: %d)\n", hr);
									}

									rsInterface->Release();
									rsInterface = nullptr;
								}
								else
								{
									Console_Output("ERROR: Failed to start the runtime host (HRESULT: %d)\n", hr);
								}
							}
							else
							{
								Console_Output("ERROR: Failed to set the app domain manager type (HRESULT: %d)\n", hr);
							}
						}
						else
						{
							Console_Output("ERROR: Failed to get the CLR control (HRESULT: %d)\n", hr);
						}
					}
					else
					{
						Console_Output("ERROR: Failed to set the host control (HRESULT: %d)\n", hr);

						delete hostControl;
						hostControl = nullptr;
					}
				}
				else
				{
					Console_Output("ERROR: Failed to get the runtime host interface (HRESULT: %d)\n", hr);
				}
			}
			else
			{
				Console_Output("ERROR: No suitable runtime found\n");

				// No suitable runtime version found
				hr = E_UNEXPECTED;
			}
		}
		else
		{
			Console_Output("ERROR: Failed to create the meta host (HRESULT: %d)\n", hr);
		}
	}

	if (FAILED(hr))
	{
		Shutdown();
	}

	return hr;
}

void RenSharpRootEventClass::Shutdown(bool fatal)
{
	shutdown = true;
	
	SetConsoleCtrlHandler(ConsoleCtrlHandlerRoutine, FALSE);

	if (clrRuntimeHost != nullptr)
	{
		if (!fatal)
		{
			if (hostControl != nullptr)
			{
				// Call shutdown
				RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
				if (rsInterface != nullptr)
				{
					rsInterface->Shutdown();

					rsInterface->Release();
					rsInterface = nullptr;
				}
				
				delete hostControl;
				hostControl = nullptr;
			}

			clrRuntimeHost->Stop();
		}

		clrRuntimeHost->Release();
		clrRuntimeHost = nullptr;
	}

	if (runtimeInfo != nullptr)
	{
		runtimeInfo->Release();
		runtimeInfo = nullptr;
	}

	if (metaHost != nullptr)
	{
		metaHost->Release();
		metaHost = nullptr;
	}

	cGameData::Set_Manual_Exit(true);
}

bool RenSharpRootEventClass::Is_Shutting_Down() const
{
	return (shutdown || shutdownPending);
}

void RenSharpRootEventClass::Game_Over_Event()
{
	if (!shutdown && The_Game()->Get_Win_Type() == cGameData::WinTypeEnum::WIN_TYPE_SHUTDOWN && cGameData::Is_Manual_Exit())
	{
		Shutdown();
	}
}

void RenSharpRootEventClass::Think()
{
	if (shutdownPending)
	{
		shutdownPending = false;

		Shutdown(true);

		return;
	}

	/*
	if (!shutdown && cGameData::Is_Manual_Exit())
	{
		Shutdown();

		return;
	}
	*/
}

void RenSharpRootEventClass::EventClass_Destructed(RenSharpEventClass* eventClass)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassDestructed(eventClass)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassDestructed: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Settings_Loaded_Event(RenSharpEventClass* eventClass)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassSettingsLoadedEvent(eventClass)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassSettingsLoadedEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

bool RenSharpRootEventClass::EventClass_Chat_Event(RenSharpEventClass* eventClass, cPlayer *Player, TextMessageEnum Type, const wchar_t *Message, int ReceiverID)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassChatEvent(eventClass, Player, Type, Message, ReceiverID, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassChatEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

bool RenSharpRootEventClass::EventClass_Chat_Command_Event(RenSharpEventClass* eventClass, cPlayer *Player, TextMessageEnum Type, const StringClass &Command, const DATokenClass &Text, int ReceiverID)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassChatCommandEvent(eventClass, Player, Type, Command.Peek_Buffer(), &Text, ReceiverID, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassChatCommandEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

bool RenSharpRootEventClass::EventClass_Key_Hook_Event(RenSharpEventClass* eventClass, cPlayer *Player, const StringClass &Key)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassKeyHookEvent(eventClass, Player, Key.Peek_Buffer(), &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassKeyHookEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

bool RenSharpRootEventClass::EventClass_Host_Chat_Event(RenSharpEventClass* eventClass, int ID, TextMessageEnum Type, const char *Message)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassHostChatEvent(eventClass, ID, Type, Message, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassHostChatEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

bool RenSharpRootEventClass::EventClass_Radio_Event(RenSharpEventClass* eventClass, cPlayer *Player, int PlayerType, int AnnouncementID, int IconID, AnnouncementEnum AnnouncementType)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassRadioEvent(eventClass, Player, PlayerType, AnnouncementID, IconID, AnnouncementType, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassRadioEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

ConnectionAcceptanceFilter::STATUS RenSharpRootEventClass::EventClass_Connection_Request_Event(RenSharpEventClass* eventClass, ConnectionRequest &Request, WideStringClass &RefusalMessage)
{
	if (shutdown || hostControl == nullptr)
	{
		return ConnectionAcceptanceFilter::STATUS_ACCEPTING;
	}

	ConnectionAcceptanceFilter::STATUS result = ConnectionAcceptanceFilter::STATUS_ACCEPTING;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		wchar_t *tmpRefusalMessage = RefusalMessage.Peek_Buffer();

		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassConnectionRequestEvent(eventClass, &Request, &tmpRefusalMessage, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassConnectionRequestEvent: %s\n", error.ErrorMessage());
		}
		
		if (tmpRefusalMessage != RefusalMessage.Peek_Buffer())
		{
			RefusalMessage = tmpRefusalMessage;

			if (FAILED(hr = rsInterface->FreePointer(tmpRefusalMessage)))
			{
				_com_error error(hr);
				Console_Output("ERROR: Failed to call FreePointer: %s\n", error.ErrorMessage());
			}

			tmpRefusalMessage = nullptr;
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return result;
}

void RenSharpRootEventClass::EventClass_Player_Pre_Join_Event(RenSharpEventClass* eventClass, ConnectionRequest &Request)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassPlayerPreJoinEvent(eventClass, &Request)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassPlayerPreJoinEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Player_Join_Event(RenSharpEventClass* eventClass, cPlayer *Player)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassPlayerJoinEvent(eventClass, Player)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassPlayerJoinEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Player_Leave_Event(RenSharpEventClass* eventClass, cPlayer *Player)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassPlayerLeaveEvent(eventClass, Player)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassPlayerLeaveEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Player_Loaded_Event(RenSharpEventClass* eventClass, cPlayer *Player)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassPlayerLoadedEvent(eventClass, Player)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassPlayerLoadedEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Name_Change_Event(RenSharpEventClass* eventClass, cPlayer *Player)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassNameChangeEvent(eventClass, Player)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassNameChangeEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Level_Loaded_Event(RenSharpEventClass* eventClass)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassLevelLoadedEvent(eventClass)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassLevelLoadedEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Remix_Event(RenSharpEventClass* eventClass)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassRemixEvent(eventClass)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassRemixEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Rebalance_Event(RenSharpEventClass* eventClass)
{
	if(shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassRebalanceEvent(eventClass)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassRebalanceEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Swap_Event(RenSharpEventClass* eventClass)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassSwapEvent(eventClass)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassSwapEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Game_Over_Event(RenSharpEventClass* eventClass)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassGameOverEvent(eventClass)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassGameOverEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Console_Output_Event(RenSharpEventClass* eventClass, const char *Output)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassConsoleOutputEvent(eventClass, Output)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassConsoleOutputEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Ren_Log_Event(RenSharpEventClass* eventClass, const char *Output)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassRenLogEvent(eventClass, Output)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassRenLogEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_DA_Log_Event(RenSharpEventClass* eventClass, const char *Header, const char *Output)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassDALogEvent(eventClass, Header, Output)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassDALogEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

int RenSharpRootEventClass::EventClass_Character_Purchase_Request_Event(RenSharpEventClass* eventClass, BaseControllerClass *Base, cPlayer *Player, float &Cost, const SoldierGameObjDef *Item)
{
	if (shutdown || hostControl == nullptr)
	{
		return -1;
	}

	int result = -1;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassCharacterPurchaseRequestEvent(eventClass, Base, Player, &Cost, Item, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassCharacterPurchaseRequestEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return result;
}

int RenSharpRootEventClass::EventClass_Vehicle_Purchase_Request_Event(RenSharpEventClass* eventClass, BaseControllerClass *Base, cPlayer *Player, float &Cost, const VehicleGameObjDef *Item)
{
	if (shutdown || hostControl == nullptr)
	{
		return -1;
	}

	int result = -1;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassVehiclePurchaseRequestEvent(eventClass, Base, Player, &Cost, Item, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassVehiclePurchaseRequestEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return result;
}

int RenSharpRootEventClass::EventClass_PowerUp_Purchase_Request_Event(RenSharpEventClass* eventClass, BaseControllerClass *Base, cPlayer *Player, float &Cost, const PowerUpGameObjDef *Item)
{
	if (shutdown || hostControl == nullptr)
	{
		return -1;
	}

	int result = -1;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassPowerUpPurchaseRequestEvent(eventClass, Base, Player, &Cost, Item, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassPowerUpPurchaseRequestEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return result;
}

int RenSharpRootEventClass::EventClass_Custom_Purchase_Request_Event(RenSharpEventClass* eventClass, BaseControllerClass *Base, cPlayer *Player, float &Cost, unsigned int ID)
{
	if (shutdown || hostControl == nullptr)
	{
		return -1;
	}

	int result = -1;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassCustomPurchaseRequestEvent(eventClass, Base, Player, &Cost, ID, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassCustomPurchaseRequestEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return result;
}

void RenSharpRootEventClass::EventClass_Character_Purchase_Event(RenSharpEventClass* eventClass, cPlayer *Player, float Cost, const SoldierGameObjDef *Item)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassCharacterPurchaseEvent(eventClass, Player, Cost, Item)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassCharacterPurchaseEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Vehicle_Purchase_Event(RenSharpEventClass* eventClass, cPlayer *Player, float Cost, const VehicleGameObjDef *Item)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassVehiclePurchaseEvent(eventClass, Player, Cost, Item)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassVehiclePurchaseEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_PowerUp_Purchase_Event(RenSharpEventClass* eventClass, cPlayer *Player, float Cost, const PowerUpGameObjDef *Item)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassPowerUpPurchaseEvent(eventClass, Player, Cost, Item)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassPowerUpPurchaseEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Custom_Purchase_Event(RenSharpEventClass* eventClass, cPlayer *Player, float Cost, unsigned int ID)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassCustomPurchaseEvent(eventClass, Player, Cost, ID)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassCustomPurchaseEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

bool RenSharpRootEventClass::EventClass_Refill_Event(RenSharpEventClass* eventClass, cPlayer *Player)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassRefillEvent(eventClass, Player, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassRefillEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

bool RenSharpRootEventClass::EventClass_Suicide_Event(RenSharpEventClass* eventClass, cPlayer *Player)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassSuicideEvent(eventClass, Player, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassSuicideEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

bool RenSharpRootEventClass::EventClass_Team_Change_Request_Event(RenSharpEventClass* eventClass, cPlayer *Player)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassTeamChangeRequestEvent(eventClass, Player, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassTeamChangeRequestEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

void RenSharpRootEventClass::EventClass_Team_Change_Event(RenSharpEventClass* eventClass, cPlayer *Player)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassTeamChangeEvent(eventClass, Player)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassTeamChangeEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

bool RenSharpRootEventClass::EventClass_Vehicle_Entry_Request_Event(RenSharpEventClass* eventClass, VehicleGameObj *Vehicle, cPlayer *Player, int &Seat)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassVehicleEntryRequestEvent(eventClass, Vehicle, Player, &Seat, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassVehicleEntryRequestEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

void RenSharpRootEventClass::EventClass_Vehicle_Enter_Event(RenSharpEventClass* eventClass, VehicleGameObj *Vehicle, cPlayer *Player, int Seat)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassVehicleEnterEvent(eventClass, Vehicle, Player, Seat)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassVehicleEnterEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Vehicle_Exit_Event(RenSharpEventClass* eventClass, VehicleGameObj *Vehicle, cPlayer *Player, int Seat)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassVehicleExitEvent(eventClass, Vehicle, Player, Seat)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassVehicleExitEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

bool RenSharpRootEventClass::EventClass_PowerUp_Grant_Request_Event(RenSharpEventClass* eventClass, cPlayer *Player, const PowerUpGameObjDef *PowerUp, PowerUpGameObj *PowerUpObj)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassPowerUpGrantRequestEvent(eventClass, Player, PowerUp, PowerUpObj, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassPowerUpGrantRequestEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

void RenSharpRootEventClass::EventClass_PowerUp_Grant_Event(RenSharpEventClass* eventClass, cPlayer *Player, const PowerUpGameObjDef *PowerUp, PowerUpGameObj *PowerUpObj)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassPowerUpGrantEvent(eventClass, Player, PowerUp, PowerUpObj)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassPowerUpGrantEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

bool RenSharpRootEventClass::EventClass_Add_Weapon_Request_Event(RenSharpEventClass* eventClass, cPlayer *Player, const WeaponDefinitionClass *Weapon)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassAddWeaponRequestEvent(eventClass, Player, Weapon, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassAddWeaponRequestEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

void RenSharpRootEventClass::EventClass_Add_Weapon_Event(RenSharpEventClass* eventClass, cPlayer *Player, WeaponClass *Weapon)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassAddWeaponEvent(eventClass, Player, Weapon)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassAddWeaponEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Remove_Weapon_Event(RenSharpEventClass* eventClass, cPlayer *Player, WeaponClass *Weapon)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassRemoveWeaponEvent(eventClass, Player, Weapon)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassRemoveWeaponEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Clear_Weapons_Event(RenSharpEventClass* eventClass, cPlayer *Player)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassClearWeaponsEvent(eventClass, Player)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassClearWeaponsEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Beacon_Deploy_Event(RenSharpEventClass* eventClass, BeaconGameObj *Beacon)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassBeaconDeployEvent(eventClass, Beacon)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassBeaconDeployEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Beacon_Detonate_Event(RenSharpEventClass* eventClass, BeaconGameObj *Beacon)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassBeaconDetonateEvent(eventClass, Beacon)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassBeaconDetonateEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

bool RenSharpRootEventClass::EventClass_C4_Detonate_Request_Event(RenSharpEventClass* eventClass, C4GameObj *C4, SmartGameObj *Triggerer)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassC4DetonateRequestEvent(eventClass, C4, Triggerer, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassC4DetonateRequestEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

void RenSharpRootEventClass::EventClass_C4_Detonate_Event(RenSharpEventClass* eventClass, C4GameObj *C4)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassC4DetonateEvent(eventClass, C4)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassC4DetonateEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Change_Character_Event(RenSharpEventClass* eventClass, cPlayer *Player, const SoldierGameObjDef *Soldier)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassChangeCharacterEvent(eventClass, Player, Soldier)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassChangeCharacterEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

bool RenSharpRootEventClass::EventClass_Vehicle_Flip_Event(RenSharpEventClass* eventClass, VehicleGameObj *Vehicle)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassVehicleFlipEvent(eventClass, Vehicle, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassVehicleFlipEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

bool RenSharpRootEventClass::EventClass_Request_Vehicle_Event(RenSharpEventClass* eventClass, VehicleFactoryGameObj *Factory, const VehicleGameObjDef *Vehicle, cPlayer *Player, float Delay)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassRequestVehicleEvent(eventClass, Factory, Vehicle, Player, Delay, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassRequestVehicleEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

void RenSharpRootEventClass::EventClass_Think(RenSharpEventClass* eventClass)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassThink(eventClass)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassThink: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Object_Created_Event(RenSharpEventClass* eventClass, GameObject *obj)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassObjectCreatedEvent(eventClass, obj)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassObjectCreatedEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

bool RenSharpRootEventClass::EventClass_Stock_Client_Damage_Request_Event(RenSharpEventClass* eventClass, DamageableGameObj *Victim, ArmedGameObj *Damager, float Damage, uint Warhead)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassStockClientDamageRequestEvent(eventClass, Victim, Damager, Damage, Warhead, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassStockClientDamageRequestEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

bool RenSharpRootEventClass::EventClass_TT_Client_Damage_Request_Event(RenSharpEventClass* eventClass, DamageableGameObj *Victim, ArmedGameObj *Damager, const AmmoDefinitionClass *Ammo, const char *Bone)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassTTClientDamageRequestEvent(eventClass, Victim, Damager, Ammo, Bone, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassTTClientDamageRequestEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

bool RenSharpRootEventClass::EventClass_Damage_Request_Event(RenSharpEventClass* eventClass, DamageableGameObj *Victim, ArmedGameObj *Damager, float &Damage, unsigned int &Warhead, float Scale, DADamageType::Type Type)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassDamageRequestEvent(eventClass, Victim, Damager, &Damage, &Warhead, Scale, Type, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassDamageRequestEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

void RenSharpRootEventClass::EventClass_Damage_Event(RenSharpEventClass* eventClass, DamageableGameObj *Victim, ArmedGameObj *Damager, float Damage, unsigned int Warhead, float Scale, DADamageType::Type Type)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassDamageEvent(eventClass, Victim, Damager, Damage, Warhead, Scale, Type)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassDamageEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Kill_Event(RenSharpEventClass* eventClass, DamageableGameObj *Victim, ArmedGameObj *Killer, float Damage, unsigned int Warhead, float Scale, DADamageType::Type Type)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassKillEvent(eventClass, Victim, Killer, Damage, Warhead, Scale, Type)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassKillEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Custom_Event(RenSharpEventClass* eventClass, GameObject *obj, int Type, int Param, GameObject *Sender)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassCustomEvent(eventClass, obj, Type, Param, Sender)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassCustomEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Poke_Event(RenSharpEventClass* eventClass, cPlayer *Player, PhysicalGameObj *obj)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassPokeEvent(eventClass, Player, obj)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassPokeEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Zone_Enter_Event(RenSharpEventClass* eventClass, ScriptZoneGameObj *obj, PhysicalGameObj *Enterer)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassZoneEnterEvent(eventClass, obj, Enterer)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassZoneEnterEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Zone_Exit_Event(RenSharpEventClass* eventClass, ScriptZoneGameObj *obj, PhysicalGameObj *Exiter)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassZoneExitEvent(eventClass, obj, Exiter)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassZoneExitEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Object_Destroyed_Event(RenSharpEventClass* eventClass, GameObject *obj)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassObjectDestroyedEvent(eventClass, obj)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassObjectDestroyedEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::EventClass_Timer_Expired(RenSharpEventClass* eventClass, int Number, unsigned int Data)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->EventClassTimerExpired(eventClass, Number, Data)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call EventClassTimerExpired: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Observer_Destructed(RenSharpGameObjObserverClass *observer)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverDestructed(observer)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverDestructed: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Observer_Destroyed(RenSharpGameObjObserverClass *observer, GameObject *obj)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverDestroyed(observer, obj)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverDestroyed: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Observer_Custom(RenSharpGameObjObserverClass *observer, GameObject *obj, int message, int param, GameObject *sender)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverCustom(observer, obj, message, param, sender)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverCustom: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Observer_Poked(RenSharpGameObjObserverClass *observer, GameObject *obj, GameObject *poker)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverPoked(observer, obj, poker)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverPoked: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Observer_Entered(RenSharpGameObjObserverClass *observer, GameObject *obj, GameObject *enterer)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverEntered(observer, obj, enterer)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverEntered: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Observer_Exited(RenSharpGameObjObserverClass *observer, GameObject *obj, GameObject *exiter)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverExited(observer, obj, exiter)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverExited: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Observer_Sound_Heard(RenSharpGameObjObserverClass *observer, GameObject *obj, const CombatSound &sound)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverSoundHeard(observer, obj, &sound)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverSoundHeard: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Observer_Enemy_Seen(RenSharpGameObjObserverClass *observer, GameObject *obj, GameObject *enemy)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverEnemySeen(observer, obj, enemy)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverEnemySeen: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Observer_Action_Complete(RenSharpGameObjObserverClass *observer, GameObject *obj, int actionID, ActionCompleteReason completeReason)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverActionComplete(observer, obj, actionID, completeReason)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverActionComplete: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Observer_Timer_Expired(RenSharpGameObjObserverClass *observer, GameObject *obj, int number)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverTimerExpired(observer, obj, number)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverTimerExpired: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Observer_Animation_Complete(RenSharpGameObjObserverClass *observer, GameObject *obj, const char *name)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverAnimationComplete(observer, obj, name)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverAnimationComplete: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Observer_Init(RenSharpGameObjObserverClass *observer)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverInit(observer)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverInit: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

bool RenSharpRootEventClass::Observer_Vehicle_Entry_Request(RenSharpGameObjObserverClass *observer, cPlayer *player, int &seat)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverVehicleEntryRequest1(observer, player, &seat, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverVehicleEntryRequest1: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

bool RenSharpRootEventClass::Observer_Vehicle_Entry_Request(RenSharpGameObjObserverClass *observer, VehicleGameObj *vehicle, int &seat)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverVehicleEntryRequest2(observer, vehicle, &seat, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverVehicleEntryRequest2: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

void RenSharpRootEventClass::Observer_Vehicle_Enter(RenSharpGameObjObserverClass *observer, cPlayer *player, int seat)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverVehicleEnter1(observer, player, seat)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverVehicleEnter1: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Observer_Vehicle_Enter(RenSharpGameObjObserverClass *observer, VehicleGameObj *vehicle, int seat)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverVehicleEnter2(observer, vehicle, seat)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverVehicleEnter2: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Observer_Vehicle_Exit(RenSharpGameObjObserverClass *observer, cPlayer *player, int seat)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverVehicleExit1(observer, player, seat)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverVehicleExit1: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Observer_Vehicle_Exit(RenSharpGameObjObserverClass *observer, VehicleGameObj *vehicle, int seat)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverVehicleExit2(observer, vehicle, seat)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverVehicleExit2: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

bool RenSharpRootEventClass::Observer_Vehicle_Flip(RenSharpGameObjObserverClass *observer)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverVehicleFlip(observer, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverVehicleFlip: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

bool RenSharpRootEventClass::Observer_Damage_Dealt_Request(RenSharpGameObjObserverClass *observer, DamageableGameObj *victim, float &damage, unsigned int &warhead, float scale, DADamageType::Type type)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverDamageDealtRequest(observer, victim, &damage, &warhead, scale, type, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverDamageDealtRequest: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

bool RenSharpRootEventClass::Observer_Damage_Received_Request(RenSharpGameObjObserverClass *observer, ArmedGameObj *damager, float &damage, unsigned int &warhead, float scale, DADamageType::Type type)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverDamageReceivedRequest(observer, damager, &damage, &warhead, scale, type, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverDamageReceivedRequest: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

void RenSharpRootEventClass::Observer_Damage_Dealt(RenSharpGameObjObserverClass *observer, DamageableGameObj *victim, float damage, unsigned int warhead, float scale, DADamageType::Type type)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverDamageDealt(observer, victim, damage, warhead, scale, type)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverDamageDealt: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Observer_Damage_Received(RenSharpGameObjObserverClass *observer, ArmedGameObj *damager, float damage, unsigned int warhead, float scale, DADamageType::Type type)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverDamageReceived(observer, damager, damage, warhead, scale, type)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverDamageReceived: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Observer_Kill_Dealt(RenSharpGameObjObserverClass *observer, DamageableGameObj *victim, float damage, unsigned int warhead, float scale, DADamageType::Type type)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverKillDealt(observer, victim, damage, warhead, scale, type)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverKillDealt: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Observer_Kill_Received(RenSharpGameObjObserverClass *observer, ArmedGameObj *killer, float damage, unsigned int warhead, float scale, DADamageType::Type type)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverKillReceived(observer, killer, damage, warhead, scale, type)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverKillReceived: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

bool RenSharpRootEventClass::Observer_PowerUp_Grant_Request(RenSharpGameObjObserverClass *observer, cPlayer *player)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverPowerUpGrantRequest1(observer, player, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverPowerUpGrantRequest1: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

bool RenSharpRootEventClass::Observer_PowerUp_Grant_Request(RenSharpGameObjObserverClass *observer, const PowerUpGameObjDef *powerUp, PowerUpGameObj *powerUpObj)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverPowerUpGrantRequest2(observer, powerUp, powerUpObj, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverPowerUpGrantRequest2: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

void RenSharpRootEventClass::Observer_PowerUp_Grant(RenSharpGameObjObserverClass *observer, cPlayer *player)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverPowerUpGrant1(observer, player)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverPowerUpGrant1: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Observer_PowerUp_Grant(RenSharpGameObjObserverClass *observer, const PowerUpGameObjDef *powerUp, PowerUpGameObj *powerUpObj)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverPowerUpGrant2(observer, powerUp, powerUpObj)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverPowerUpGrant2: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

bool RenSharpRootEventClass::Observer_Add_Weapon_Request(RenSharpGameObjObserverClass *observer, const WeaponDefinitionClass *weapon)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverAddWeaponRequest(observer, weapon, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverAddWeaponRequest: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

void RenSharpRootEventClass::Observer_Add_Weapon(RenSharpGameObjObserverClass *observer, WeaponClass *weapon)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverAddWeapon(observer, weapon)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverAddWeapon: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Observer_Remove_Weapon(RenSharpGameObjObserverClass *observer, WeaponClass *weapon)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverRemoveWeapon(observer, weapon)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverRemoveWeapon: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Observer_Clear_Weapons(RenSharpGameObjObserverClass *observer)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ObserverClearWeapons(observer)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ObserverClearWeapons: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerObserver_Destructed(RenSharpPlayerObserverClass *observer)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverDestructed(observer)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverDestructed: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerObserver_Init(RenSharpPlayerObserverClass *observer)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverInit(observer)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverInit: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerObserver_Join(RenSharpPlayerObserverClass *observer)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverJoin(observer)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverJoin: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerObserver_Leave(RenSharpPlayerObserverClass *observer)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverLeave(observer)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverLeave: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerObserver_Level_Loaded(RenSharpPlayerObserverClass *observer)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverLevelLoaded(observer)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverLevelLoaded: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerObserver_Player_Loaded(RenSharpPlayerObserverClass *observer)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverPlayerLoaded(observer)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverPlayerLoaded: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerObserver_Name_Change(RenSharpPlayerObserverClass *observer)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverNameChange(observer)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverNameChange: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerObserver_Team_Change(RenSharpPlayerObserverClass *observer)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverTeamChange(observer)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverTeamChange: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

int RenSharpRootEventClass::PlayerObserver_Character_Purchase_Request(RenSharpPlayerObserverClass *observer, float &cost, const SoldierGameObjDef *item)
{
	if (shutdown || hostControl == nullptr)
	{
		return -1;
	}

	int result = -1;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverCharacterPurchaseRequest(observer, &cost, item, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverCharacterPurchase: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return result;
}

int RenSharpRootEventClass::PlayerObserver_Vehicle_Purchase_Request(RenSharpPlayerObserverClass *observer, float &cost, const VehicleGameObjDef *item)
{
	if (shutdown || hostControl == nullptr)
	{
		return -1;
	}

	int result = -1;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverVehiclePurchaseRequest(observer, &cost, item, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverVehiclePurchaseRequest: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return result;
}

int RenSharpRootEventClass::PlayerObserver_PowerUp_Purchase_Request(RenSharpPlayerObserverClass *observer, float &cost, const PowerUpGameObjDef *item)
{
	if (shutdown || hostControl == nullptr)
	{
		return -1;
	}

	int result = -1;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverPowerUpPurchaseRequest(observer, &cost, item, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverPowerUpPurchaseRequest: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return result;
}

int RenSharpRootEventClass::PlayerObserver_Custom_Purchase_Request(RenSharpPlayerObserverClass *observer, float &cost, unsigned int id)
{
	if (shutdown || hostControl == nullptr)
	{
		return -1;
	}

	int result = -1;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverCustomPurchaseRequest(observer, &cost, id, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverCustomPurchaseRequest: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return result;
}

void RenSharpRootEventClass::PlayerObserver_Character_Purchase(RenSharpPlayerObserverClass *observer, float cost, const SoldierGameObjDef *item)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverCharacterPurchase(observer, cost, item)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverCharacterPurchase: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerObserver_Vehicle_Purchase(RenSharpPlayerObserverClass *observer, float cost, const VehicleGameObjDef *item)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverVehiclePurchase(observer, cost, item)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverVehiclePurchase: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerObserver_PowerUp_Purchase(RenSharpPlayerObserverClass *observer, float cost, const PowerUpGameObjDef *item)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverPowerUpPurchase(observer, cost, item)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverPowerUpPurchase: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerObserver_Custom_Purchase(RenSharpPlayerObserverClass *observer, float cost, unsigned int id)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverCustomPurchase(observer, cost, id)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverCustomPurchase: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

bool RenSharpRootEventClass::PlayerObserver_Vehicle_Entry_Request(RenSharpPlayerObserverClass *observer, VehicleGameObj *vehicle, int &seat)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverVehicleEntryRequest(observer, vehicle, &seat, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverVehicleEntryRequest: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

void RenSharpRootEventClass::PlayerObserver_Vehicle_Enter(RenSharpPlayerObserverClass *observer, VehicleGameObj *vehicle, int seat)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverVehicleEnter(observer, vehicle, seat)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverVehicleEnter: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerObserver_Vehicle_Exit(RenSharpPlayerObserverClass *observer, VehicleGameObj *vehicle, int seat)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverVehicleExit(observer, vehicle, seat)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverVehicleExit: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

bool RenSharpRootEventClass::PlayerObserver_PowerUp_Grant_Request(RenSharpPlayerObserverClass *observer, const PowerUpGameObjDef *powerUp, PowerUpGameObj *powerUpObj)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverPowerUpGrantRequest(observer, powerUp, powerUpObj, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverPowerUpGrantRequest: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

void RenSharpRootEventClass::PlayerObserver_PowerUp_Grant(RenSharpPlayerObserverClass *observer, const PowerUpGameObjDef *powerUp, PowerUpGameObj *powerUpObj)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverPowerUpGrant(observer, powerUp, powerUpObj)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverPowerUpGrant: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

bool RenSharpRootEventClass::PlayerObserver_Add_Weapon_Request(RenSharpPlayerObserverClass *observer, const WeaponDefinitionClass *weapon)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverAddWeaponRequest(observer, weapon, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverAddWeaponRequest: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

void RenSharpRootEventClass::PlayerObserver_Add_Weapon(RenSharpPlayerObserverClass *observer, WeaponClass *weapon)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverAddWeapon(observer, weapon)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverAddWeapon: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerObserver_Remove_Weapon(RenSharpPlayerObserverClass *observer, WeaponClass *weapon)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverRemoveWeapon(observer, weapon)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverRemoveWeapon: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerObserver_Clear_Weapons(RenSharpPlayerObserverClass *observer)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverClearWeapons(observer)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverClearWeapons: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

bool RenSharpRootEventClass::PlayerObserver_C4_Detonate_Request(RenSharpPlayerObserverClass *observer, C4GameObj *c4)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverC4DetonateRequest(observer, c4, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverC4DetonateRequest: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

void RenSharpRootEventClass::PlayerObserver_C4_Detonate(RenSharpPlayerObserverClass *observer, C4GameObj *c4)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverC4Detonate(observer, c4)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverC4Detonate: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerObserver_Change_Character(RenSharpPlayerObserverClass *observer, const SoldierGameObjDef *soldier)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverChangeCharacter(observer, soldier)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverChangeCharacter: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerObserver_Created(RenSharpPlayerObserverClass *observer)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverCreated(observer)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverCreated: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerObserver_Destroyed(RenSharpPlayerObserverClass *observer)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverDestroyed(observer)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverDestroyed: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

bool RenSharpRootEventClass::PlayerObserver_Damage_Dealt_Request(RenSharpPlayerObserverClass *observer, DamageableGameObj *victim, float &damage, unsigned int &warhead, float scale, DADamageType::Type type)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverDamageDealtRequest(observer, victim, &damage, &warhead, scale, type, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverDamageDealtRequest: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

bool RenSharpRootEventClass::PlayerObserver_Damage_Received_Request(RenSharpPlayerObserverClass *observer, ArmedGameObj *damager, float &damage, unsigned int &warhead, float scale, DADamageType::Type type)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverDamageReceivedRequest(observer, damager, &damage, &warhead, scale, type, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverDamageReceivedRequest: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

void RenSharpRootEventClass::PlayerObserver_Damage_Dealt(RenSharpPlayerObserverClass *observer, DamageableGameObj *victim, float damage, unsigned int warhead, float scale, DADamageType::Type type)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverDamageDealt(observer, victim, damage, warhead, scale, type)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverDamageDealt: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerObserver_Damage_Received(RenSharpPlayerObserverClass *observer, ArmedGameObj *damager, float damage, unsigned int warhead, float scale, DADamageType::Type type)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverDamageReceived(observer, damager, damage, warhead, scale, type)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverDamageReceived: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerObserver_Kill_Dealt(RenSharpPlayerObserverClass *observer, DamageableGameObj *victim, float damage, unsigned int warhead, float scale, DADamageType::Type type)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverKillDealt(observer, victim, damage, warhead, scale, type)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverKillDealt: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerObserver_Kill_Received(RenSharpPlayerObserverClass *observer, ArmedGameObj *killer, float damage, unsigned int warhead, float scale, DADamageType::Type type)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverKillReceived(observer, killer, damage, warhead, scale, type)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverKillReceived: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerObserver_Custom(RenSharpPlayerObserverClass *observer, GameObject *sender, int type, int param)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverCustom(observer, sender, type, param)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverCustom: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerObserver_Poked(RenSharpPlayerObserverClass *observer, cPlayer *player)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverPoked(observer, player)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverPoked: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerObserver_Timer_Expired(RenSharpPlayerObserverClass *observer, int number, unsigned int data)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverTimerExpired(observer, number, data)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverTimerExpired: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerObserver_Think(RenSharpPlayerObserverClass *observer)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerObserverThink(observer)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerObserverThink: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::ConsoleFunction_Destructed(RenSharpConsoleFunctionClass *function)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ConsoleFunctionDestructed(function)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ConsoleFunctionDestructed: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::ConsoleFunction_Activate(RenSharpConsoleFunctionClass *function, const char *pArgs)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface *rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->ConsoleFunctionActivate(function, pArgs)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call ConsoleFunctionActivate: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::GameFeatureFactory_Destructed(RenSharpGameFeatureFactoryClass* factory)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->GameFeatureFactoryDestructed(factory)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call GameFeatureFactoryDestructed: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

DAGameFeatureClass* RenSharpRootEventClass::GameFeatureFactory_Create_Instance(RenSharpGameFeatureFactoryClass* factory)
{
	if (shutdown || hostControl == nullptr)
	{
		return nullptr;
	}

	DAGameFeatureClass *result = nullptr;

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->GameFeatureFactoryCreateInstance(factory, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call GameFeatureFactoryCreateInstance: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return result;
}

void RenSharpRootEventClass::GameFeature_Destructed(RenSharpGameFeatureClass* gameFeature)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->GameFeatureDestructed(gameFeature)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call GameFeatureDestructed: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::GameFeature_Init(RenSharpGameFeatureClass* gameFeature)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->GameFeatureInit(gameFeature)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call GameFeatureInit: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerDataFactory_Destructed(RenSharpPlayerDataFactoryClass* playerDataFactory)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerDataFactoryDestructed(playerDataFactory)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerDataFactoryDestructed: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

DAPlayerDataClass* RenSharpRootEventClass::PlayerDataFactory_Create_Data(RenSharpPlayerDataFactoryClass* playerDataFactory)
{
	if (shutdown || hostControl == nullptr)
	{
		return nullptr;
	}

	DAPlayerDataClass* result = nullptr;

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerDataFactoryCreateData(playerDataFactory, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerDataFactoryCreateData: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return result;
}

void RenSharpRootEventClass::PlayerData_Destructed(RenSharpPlayerDataClass* playerData)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerDataDestructed(playerData)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerDataDestructed: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerData_Init(RenSharpPlayerDataClass* playerData)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerDataInit(playerData)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerDataInit: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerData_Clear_Level(RenSharpPlayerDataClass* playerData)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerDataClearLevel(playerData)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerDataClearLevel: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::PlayerData_Clear_Session(RenSharpPlayerDataClass* playerData)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->PlayerDataClearSession(playerData)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call PlayerDataClearSession: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::GameModeFactory_Destructed(RenSharpGameModeFactoryClass* factory)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->GameModeFactoryDestructed(factory)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call GameModeFactoryDestructed: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

DAGameModeClass* RenSharpRootEventClass::GameModeFactory_Create_Instance(RenSharpGameModeFactoryClass* factory)
{
	if (shutdown || hostControl == nullptr)
	{
		return nullptr;
	}

	DAGameModeClass* result = nullptr;

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->GameModeFactoryCreateInstance(factory, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call GameModeFactoryCreateInstance: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return result;
}

void RenSharpRootEventClass::GameMode_Destructed(RenSharpGameModeClass* gameMode)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->GameModeDestructed(gameMode)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call GameModeDestructed: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::GameMode_Init(RenSharpGameModeClass* gameMode)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->GameModeInit(gameMode)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call GameModeInit: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::CrateModifierFactory_Destructed(RenSharpCrateModifierFactoryClass* factory)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->CrateModifierFactoryDestructed(factory)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call CrateModifierFactoryDestructed: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

DACrateModifierClass* RenSharpRootEventClass::CrateModifierFactory_Create(RenSharpCrateModifierFactoryClass* factory, const char* parameters)
{
	if (shutdown || hostControl == nullptr)
	{
		return nullptr;
	}

	DACrateModifierClass* result = nullptr;

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->CrateModifierFactoryCreate(factory, parameters, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call CrateModifierFactoryCreate: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return result;
}

void RenSharpRootEventClass::CrateModifier_Destructed(RenSharpCrateModifierClass* crateModifier)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->CrateModifierDestructed(crateModifier)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call CrateModifierDestructed: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::CrateModifier_Init(RenSharpCrateModifierClass* crateModifier, const char* parameters)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->CrateModifierInit(crateModifier, parameters)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call CrateModifierInit: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::CrateModifier_Calculate_Odds(RenSharpCrateModifierClass* crateModifier, float& odds, cPlayer* player)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->CrateModifierCalculateOdds(crateModifier, &odds, player)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call CrateModifierCalculateOdds: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Crate_Destructed(RenSharpCrateClass* crate)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->CrateDestructed(crate)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call CrateDestructed: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Crate_Init(RenSharpCrateClass* crate)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->CrateInit(crate)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call CrateInit: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Crate_Settings_Loaded(RenSharpCrateClass* crate)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->CrateSettingsLoaded(crate)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call CrateSettingsLoaded: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Crate_Calculate_Odds(RenSharpCrateClass* crate, cPlayer* player)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->CrateCalculateOdds(crate, player)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call CrateCalculateOdds: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

bool RenSharpRootEventClass::Crate_Can_Activate(RenSharpCrateClass* crate, cPlayer* player)
{
	if (shutdown || hostControl == nullptr)
	{
		return true;
	}

	BOOL result = TRUE;

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->CrateCanActivate(crate, player, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call CrateCanActivate: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return (result == TRUE);
}

void RenSharpRootEventClass::Crate_Activate(RenSharpCrateClass* crate, cPlayer* player)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->CrateActivate(crate, player)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call Crate_Activate: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::CrateFactory_Destructed(RenSharpCrateFactoryClass* factory)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->CrateFactoryDestructed(factory)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call CrateFactoryDestructed: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

DACrateClass* RenSharpRootEventClass::CrateFactory_Create_Instance(RenSharpCrateFactoryClass* factory)
{
	if (shutdown || hostControl == nullptr)
	{
		return nullptr;
	}

	DACrateClass* result = nullptr;

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->CrateFactoryCreateInstance(factory, &result)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call CrateFactoryCreateInstance: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}

	return result;
}

void RenSharpRootEventClass::Node_Destructed(RenSharpNodeClass* node)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->NodeDestructed(node)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call NodeDestructed: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Node_Init(RenSharpNodeClass* node, const INIClass* ini, const StringClass& header)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->NodeInit(node, ini, header.Peek_Buffer())))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call NodeInit: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Node_Contested_Event(RenSharpNodeClass* node)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->NodeContestedEvent(node)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call NodeContestedEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

void RenSharpRootEventClass::Node_Capture_Event(RenSharpNodeClass* node)
{
	if (shutdown || hostControl == nullptr)
	{
		return;
	}

	RenSharpInterface* rsInterface = hostControl->GetRenSharpInterface();
	if (rsInterface != nullptr)
	{
		HRESULT hr;
		if (FAILED(hr = rsInterface->NodeCaptureEvent(node)))
		{
			_com_error error(hr);
			Console_Output("ERROR: Failed to call NodeCaptureEvent: %s\n", error.ErrorMessage());
		}

		rsInterface->Release();
		rsInterface = nullptr;

		if (FAILED(hr))
		{
			Shutdown(true);
		}
	}
}

RenSharpRootEventClass &RenSharpRootEventClass::Get_Instance()
{
	static RenSharpRootEventClass instance;

	return instance;
}

void RenSharpRootEventClass::Dump_Exception(const char* exception)
{
	static const std::size_t MaxSliceSize = 256;

	// Exceptions can be very long, we need to split them up in smaller chunks so they wont get cut off
	std::size_t exceptionLen = std::strlen(exception);
	if (exceptionLen > MaxSliceSize)
	{
		char* exceptionCopy = new char[exceptionLen + 1];
		std::memcpy(exceptionCopy, exception, exceptionLen + 1);

		char* exceptionPtr = exceptionCopy;
		char tmpChar = exceptionCopy[0];

		for (std::size_t sliceEndIndex = MaxSliceSize; sliceEndIndex < exceptionLen; sliceEndIndex += MaxSliceSize, exceptionPtr += MaxSliceSize)
		{
			exceptionPtr[0] = tmpChar;
			tmpChar = exceptionCopy[sliceEndIndex];
			exceptionCopy[sliceEndIndex] = '\0';

			Console_Output(exceptionPtr);
		}

		exceptionPtr[0] = tmpChar;
		Console_Output(exceptionPtr);

		delete[] exceptionCopy;
		exceptionCopy = nullptr;
	}
	else
	{
		Console_Output(exception);
	}

	// Exceptions generally do not contain a newline at the end
	Console_Output("\n");
}

extern "C"
{
	_declspec(dllexport) void Plugin_Init()
	{
		if (!SetConsoleCtrlHandler(ConsoleCtrlHandlerRoutine, TRUE))
		{
			Console_Output("ERROR: Failed to initialize RenSharp: Error code: %u\n", GetLastError());
		}
		else
		{
			HRESULT hr;
			if (FAILED(hr = RenSharpRootEventClass::Get_Instance().Init()))
			{
				SetConsoleCtrlHandler(ConsoleCtrlHandlerRoutine, FALSE);

				RenSharpRootEventClass::Get_Instance().Clear_Events();
				RenSharpRootEventClass::Get_Instance().Clear_Object_Events();
				RenSharpRootEventClass::Get_Instance().Clear_Timers();
				RenSharpRootEventClass::Get_Instance().Clear_Chat_Commands();
				RenSharpRootEventClass::Get_Instance().Clear_Key_Hooks();
				RenSharpRootEventClass::Get_Instance().Clear_Events();

				_com_error error(hr);
				Console_Output("ERROR: Failed to initialize RenSharp: %s\n", error.ErrorMessage());
			}
		}
	}

	_declspec(dllexport) void Plugin_Shutdown()
	{
		// Cannot call shutdown, since CLR engine won't work here
	}
}