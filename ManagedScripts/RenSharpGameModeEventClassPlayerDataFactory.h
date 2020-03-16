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

#pragma once

#include "RenSharpGameModeClass.h"
#include "RenSharpEventClass.h"
#include "RenSharpPlayerDataFactoryClass.h"
#include "Mda_game.h"
#include "Mda_player.h"
#include "RenSharpChatCommandManager.h"
#include "RenSharpKeyHookManager.h"
#include "RenSharpTimerManager.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_gamemode.h>
#include <da_event.h>
#include <da_game.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Text;

namespace RenSharp
{
	public interface class IRenSharpGameModeEventClassPlayerDataFactory : public IRenSharpGameModeClass, public IRenSharpEventClass, public IRenSharpPlayerDataFactoryClass
	{

	};

	generic<typename T>
	where T : IRenSharpPlayerDataClass
	public ref class RenSharpGameModeEventClassPlayerDataFactory abstract : public IRenSharpGameModeEventClassPlayerDataFactory
	{
		private:
			bool disposedResources;
			bool destroyPointer;
			IntPtr renSharpGameModeEventClassPlayerDataFactory;
			IntPtr daGameModeClassPointer;
			IntPtr daEventClassPointer;
			IntPtr daPlayerDataFactoryClassPointer;
			IDAGameModeClass^ daGameModeClass;
			IDAEventClass^ daEventClass;
			IDAPlayerDataFactoryClass^ daPlayerDataFactoryClass;

		public:
			RenSharpGameModeEventClassPlayerDataFactory()
				:
				disposedResources(false),
				destroyPointer(true),
				renSharpGameModeEventClassPlayerDataFactory(IntPtr::Zero),
				daGameModeClassPointer(IntPtr::Zero),
				daEventClassPointer(IntPtr::Zero),
				daPlayerDataFactoryClassPointer(IntPtr::Zero),
				daGameModeClass(nullptr),
				daEventClass(nullptr),
				daPlayerDataFactoryClass(nullptr)
			{

			}

			~RenSharpGameModeEventClassPlayerDataFactory()
			{
				if (disposedResources)
				{
					return;
				}

				DAEventManager::UnregisterManagedEventClass(this);
				DAGameManager::UnregisterManagedGameMode(this);
				DAPlayerManager::UnregisterManagedPlayerDataFactory(this);

				ClearTimers();
				ClearChatCommands();
				ClearKeyHooks();

				this->!RenSharpGameModeEventClassPlayerDataFactory();

				disposedResources = true;
			}

			!RenSharpGameModeEventClassPlayerDataFactory() 
			{
				if (IsAttached)
				{
					auto currentGameModeFactory = ::DAGameManager::Get_Game_Mode();
					if (currentGameModeFactory != nullptr)
					{
						auto helper = reinterpret_cast<DAGameModeFactoryClassHelper*>(currentGameModeFactory);

						auto& instance = helper->GetInstance();
						if (instance == InternalDAGameModeClassPointer)
						{
							instance = nullptr;
						}
					}

					::DAPlayerManager::Remove_Data_Factory(InternalDAPlayerDataFactoryClassPointer);

					if (destroyPointer)
					{
						IntPtr tmp = daEventClassPointer;
						Imports::DestroyDAEventClass(reinterpret_cast<::DAEventClass*>(tmp.ToPointer()));
					}
				}

				ReleasePointer();
			}

			String^ ToString() override
			{
				StringBuilder^ builder = gcnew StringBuilder();
				if (IsAttached)
				{
					builder->Append(LongName);
				}
				else
				{
					builder->Append(static_cast<Object^>(nullptr));
				}

				return builder->ToString();
			}

			bool Equals(Object^ other) override
			{
				if (ReferenceEquals(other, nullptr))
				{
					return false;
				}

				IDAEventClass^ otherThis1 = dynamic_cast<IDAEventClass^>(other);
				if (otherThis1 != nullptr && daEventClassPointer.Equals(otherThis1->DAEventClassPointer))
				{
					return true;
				}

				IDAGameModeClass^ otherThis2 = dynamic_cast<IDAGameModeClass^>(other);
				if (otherThis2 != nullptr && daGameModeClassPointer.Equals(otherThis2->DAGameModeClassPointer))
				{
					return true;
				}

				IDAPlayerDataFactoryClass^ otherThis3 = dynamic_cast<IDAPlayerDataFactoryClass^>(other);
				if (otherThis3 != nullptr && daPlayerDataFactoryClassPointer.Equals(otherThis3->DAPlayerDataFactoryClassPointer))
				{
					return true;
				}

				IRenSharpGameModeClass^ otherThis4 = dynamic_cast<IRenSharpGameModeClass^>(other);
				if (otherThis4 != nullptr && daGameModeClassPointer.Equals(otherThis4->DAGameModeClassPointer))
				{
					return true;
				}

				IRenSharpEventClass^ otherThis5 = dynamic_cast<IRenSharpEventClass^>(other);
				if (otherThis5 != nullptr && daEventClassPointer.Equals(otherThis5->DAEventClassPointer))
				{
					return true;
				}

				IRenSharpPlayerDataFactoryClass^ otherThis6 = dynamic_cast<IRenSharpPlayerDataFactoryClass^>(other);
				if (otherThis6 == nullptr)
				{
					return false;
				}

				return daPlayerDataFactoryClassPointer.Equals(otherThis6->DAPlayerDataFactoryClassPointer);
			}

			int GetHashCode() override sealed
			{
				return renSharpGameModeEventClassPlayerDataFactory.GetHashCode();
			}

			virtual void InitUnmanagedAttachable() sealed
			{
				AttachToUnmanagedObject();
				RegisterManagedObject();
			}

			virtual void AttachToUnmanagedObject() sealed
			{
				if (IsAttached)
				{
					throw gcnew NotSupportedException("Already attached.");
				}

				try
				{
					::RenSharpGameModeEventClassPlayerDataFactory* renSharpGameModeEventClassPlayerDataFactoryPtr = nullptr;
					::RenSharpEventClass* eventClassPtr = nullptr;
					::RenSharpGameModeClass* gameModePtr = nullptr;
					::RenSharpPlayerDataFactoryClass* playerDataFactoryPtr = nullptr;

					renSharpGameModeEventClassPlayerDataFactoryPtr = Imports::CreateRenSharpGameModeEventClassPlayerDataFactory(&eventClassPtr, &gameModePtr, &playerDataFactoryPtr);

					renSharpGameModeEventClassPlayerDataFactory = IntPtr(renSharpGameModeEventClassPlayerDataFactoryPtr);
					daGameModeClassPointer = IntPtr(gameModePtr);
					daEventClassPointer = IntPtr(eventClassPtr);
					daPlayerDataFactoryClassPointer = IntPtr(playerDataFactoryPtr);
				}
				catch (Exception^)
				{
					if (daEventClassPointer.ToPointer() != nullptr)
					{
						Imports::DestroyDAEventClass(reinterpret_cast<::DAEventClass*>(daEventClassPointer.ToPointer()));
					}

					throw;
				}

				daGameModeClass = gcnew DAGameModeClass(daGameModeClassPointer);
				daEventClass = gcnew DAEventClass(daEventClassPointer);
				daPlayerDataFactoryClass = gcnew DAPlayerDataFactoryClass(daPlayerDataFactoryClassPointer);

				UnmanagedAttach();
			}

			virtual void RegisterManagedObject() sealed
			{
				DAGameManager::RegisterManagedGameMode(this);
				DAEventManager::RegisterManagedEventClass(this);
				DAPlayerManager::RegisterManagedPlayerDataFactory(this);

				ManagedRegistered();
			}

			virtual void ReleasePointer() sealed
			{
				renSharpGameModeEventClassPlayerDataFactory = IntPtr::Zero;
				daGameModeClassPointer = IntPtr::Zero;
				daEventClassPointer = IntPtr::Zero;
				daPlayerDataFactoryClassPointer = IntPtr::Zero;
				daGameModeClass = nullptr;
				daEventClass = nullptr;
				daPlayerDataFactoryClass = nullptr;
			}

			virtual void UnmanagedAttach()
			{

			}

			virtual void ManagedRegistered()
			{

			}

			virtual IDAGameModeClass^ AsUnmanagedGameMode() sealed = IUnmanagedAttachable<IDAGameModeClass^>::AsUnmanagedObject
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}

				return daGameModeClass;
			}

			virtual IDAEventClass^ AsUnmanagedEventClass() sealed = IUnmanagedAttachable<IDAEventClass^>::AsUnmanagedObject
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}

				return daEventClass;
			}

			virtual IDAPlayerDataFactoryClass^ AsUnmanagedPlayerDataFactory() sealed = IUnmanagedAttachable<IDAPlayerDataFactoryClass^>::AsUnmanagedObject
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}

				return daPlayerDataFactoryClass;
			}

			virtual void Init()
			{
			}

			virtual void SettingsLoadedEvent()
			{
			}

			virtual bool ChatEvent(IcPlayer^ player, TextMessageEnum type, String^ message, int receiverID)
			{
				return true;
			}

			virtual bool ChatCommandEvent(IcPlayer^ player, TextMessageEnum type, String^ command, IDATokenClass^ text, int receiverID)
			{
				return true;
			}

			virtual bool KeyHookEvent(IcPlayer^ player, String^ key)
			{
				return true;
			}

			virtual bool HostChatEvent(int id, TextMessageEnum type, String^ message)
			{
				return true;
			}

			virtual bool RadioEvent(IcPlayer^ player, int playerType, int announcementID, int iconID, AnnouncementEnum announcementType)
			{
				return true;
			}

			virtual ConnectionAcceptanceFilterStatus ConnectionRequestEvent(IConnectionRequest^ request, String^% refusalMessage)
			{
				return ConnectionAcceptanceFilterStatus::StatusAccepting;
			}

			virtual void PlayerPreJoinEvent(IConnectionRequest^ request)
			{
			}

			virtual void PlayerJoinEvent(IcPlayer^ player)
			{
			}

			virtual void PlayerLeaveEvent(IcPlayer^ player)
			{
			}

			virtual void PlayerLoadedEvent(IcPlayer^ player)
			{
			}

			virtual void NameChangeEvent(IcPlayer^ player)
			{
			}

			virtual void LevelLoadedEvent()
			{
			}

			virtual void RemixEvent()
			{
			}

			virtual void RebalanceEvent()
			{
			}

			virtual void SwapEvent()
			{
			}

			virtual void GameOverEvent()
			{
			}

			virtual void ConsoleOutputEvent(String^ output)
			{
			}

			virtual void RenLogEvent(String^ output)
			{
			}

			virtual void DALogEvent(String^ header, String^ output)
			{
			}

			virtual int CharacterPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, ISoldierGameObjDef^ item)
			{
				return -1;
			}

			virtual int VehiclePurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, IVehicleGameObjDef^ item)
			{
				return -1;
			}

			virtual int PowerUpPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, IPowerUpGameObjDef^ item)
			{
				return -1;
			}

			virtual int CustomPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, unsigned int id)
			{
				return -1;
			}

			virtual void CharacterPurchaseEvent(IcPlayer^ player, float cost, ISoldierGameObjDef^ item)
			{
			}

			virtual void VehiclePurchaseEvent(IcPlayer^ player, float cost, IVehicleGameObjDef^ item)
			{
			}

			virtual void PowerUpPurchaseEvent(IcPlayer^ player, float cost, IPowerUpGameObjDef^ item)
			{
			}

			virtual void CustomPurchaseEvent(IcPlayer^ player, float cost, unsigned int id)
			{
			}

			virtual bool RefillEvent(IcPlayer^ player)
			{
				return true;
			}

			virtual bool SuicideEvent(IcPlayer^ player)
			{
				return true;
			}

			virtual bool TeamChangeRequestEvent(IcPlayer^ player)
			{
				return true;
			}

			virtual void TeamChangeEvent(IcPlayer^ player)
			{
			}

			virtual bool VehicleEntryRequestEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int% seat)
			{
				return true;
			}

			virtual void VehicleEnterEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int seat)
			{
			}

			virtual void VehicleExitEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int seat)
			{
			}

			virtual bool PowerUpGrantRequestEvent(IcPlayer^ player, IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj)
			{
				return true;
			}

			virtual void PowerUpGrantEvent(IcPlayer^ player, IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj)
			{
			}

			virtual bool AddWeaponRequestEvent(IcPlayer^ player, IWeaponDefinitionClass^ weapon)
			{
				return true;
			}

			virtual void AddWeaponEvent(IcPlayer^ player, IWeaponClass^ weapon)
			{
			}

			virtual void RemoveWeaponEvent(IcPlayer^ player, IWeaponClass^ weapon)
			{
			}

			virtual void ClearWeaponsEvent(IcPlayer^ player)
			{
			}

			virtual void BeaconDeployEvent(IBeaconGameObj^ beacon)
			{
			}

			virtual void BeaconDetonateEvent(IBeaconGameObj^ beacon)
			{
			}

			virtual bool C4DetonateRequestEvent(IC4GameObj^ c4, ISmartGameObj^ triggerer)
			{
				return true;
			}

			virtual void C4DetonateEvent(IC4GameObj^ c4)
			{
			}

			virtual void ChangeCharacterEvent(IcPlayer^ player, ISoldierGameObjDef^ soldier)
			{
			}

			virtual bool VehicleFlipEvent(IVehicleGameObj^ vehicle)
			{
				return true;
			}

			virtual bool RequestVehicleEvent(IVehicleFactoryGameObj^ factory, IVehicleGameObjDef^ vehicle, IcPlayer^ player, float delay)
			{
				return true;
			}

			virtual void Think()
			{
			}

			virtual void ObjectCreatedEvent(IScriptableGameObj^ obj)
			{
			}

			virtual bool StockClientDamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float damage, uint warhead)
			{
				return true;
			}

			virtual bool TTClientDamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, IAmmoDefinitionClass^ ammo, String^ bone)
			{
				return true;
			}

			virtual bool DamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float% damage, unsigned int% warhead, float scale, DADamageType type)
			{
				return true;
			}

			virtual void DamageEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float damage, unsigned int warhead, float scale, DADamageType type)
			{
			}

			virtual void KillEvent(IDamageableGameObj^ victim, IArmedGameObj^ killer, float damage, unsigned int warhead, float scale, DADamageType type)
			{
			}

			virtual void CustomEvent(IScriptableGameObj^ obj, int type, int param, IScriptableGameObj^ sender)
			{
			}

			virtual void PokeEvent(IcPlayer^ player, IPhysicalGameObj^ obj)
			{
			}

			virtual void ZoneEnterEvent(IScriptZoneGameObj^ obj, IPhysicalGameObj^ enterer)
			{
			}

			virtual void ZoneExitEvent(IScriptZoneGameObj^ obj, IPhysicalGameObj^ exiter)
			{
			}

			virtual void ObjectDestroyedEvent(IScriptableGameObj^ obj)
			{
			}

			virtual void TimerExpired(int number, Object^ data)
			{

			}

			virtual void StartTimer(int number, TimeSpan duration, bool repeat, Object^ data) sealed
			{
				RenSharpTimerManager::StartTimer(this, number, duration, repeat, data);
			}

			virtual void StartTimer(int number, TimeSpan duration, bool repeat) sealed
			{
				RenSharpTimerManager::StartTimer(this, number, duration, repeat);
			}

			virtual void StartTimer(int number, TimeSpan duration) sealed
			{
				RenSharpTimerManager::StartTimer(this, number, duration);
			}

			virtual void StartTimer(TimeSpan duration, bool repeat, System::Action<RenSharpTimerStruct^>^ action) sealed
			{
				RenSharpTimerManager::StartTimer(this, duration, repeat, action);
			}

			virtual void StartTimer(TimeSpan duration, System::Action<RenSharpTimerStruct^>^ action) sealed
			{
				RenSharpTimerManager::StartTimer(this, duration, action);
			}

			virtual void StopTimer(int number, Object^ data) sealed
			{
				RenSharpTimerManager::StopTimer(this, number, data);

				if (data == nullptr)
				{
					InternalDAEventClassPointer->Stop_Timer(number, 0);
				}
				else if (UInt32::typeid->Equals(data->GetType()))
				{
					InternalDAEventClassPointer->Stop_Timer(number, safe_cast<UInt32>(data));
				}
			}

			virtual void StopTimer(int number) sealed
			{
				RenSharpTimerManager::StopTimer(this, number);

				InternalDAEventClassPointer->Stop_Timer(number);
			}

			virtual void StopTimer(System::Action<RenSharpTimerStruct^>^ action) sealed
			{
				RenSharpTimerManager::StopTimer(this, action);
			}

			virtual bool IsTimer(int number, Object^ data) sealed
			{
				if (RenSharpTimerManager::IsTimer(this, number, data))
				{
					return true;
				}
				else if (data == nullptr)
				{
					if (InternalDAEventClassPointer->Is_Timer(number, 0))
					{
						return true;
					}
				}
				else if (UInt32::typeid->Equals(data->GetType()))
				{
					if (InternalDAEventClassPointer->Is_Timer(number, safe_cast<UInt32>(data)))
					{
						return true;
					}
				}

				return false;
			}

			virtual bool IsTimer(int number) sealed
			{
				if (RenSharpTimerManager::IsTimer(this, number))
				{
					return true;
				}

				return InternalDAEventClassPointer->Is_Timer(number);
			}

			virtual bool IsTimer(System::Action<RenSharpTimerStruct^>^ action) sealed
			{
				return RenSharpTimerManager::IsTimer(this, action);
			}

			virtual void ClearTimers() sealed
			{
				RenSharpTimerManager::ClearTimers(this);
				InternalDAEventClassPointer->Clear_Timers();
			}

			virtual bool FilterChatCommand(IcPlayer^ player, String^ command, IDATokenClass^ text, TextMessageEnum chatType, Object^ data) sealed
			{
				return true;
			}

			virtual RenSharpChatCommandStruct^ RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel, DAChatType chatType, Object^ data) sealed
			{
				return RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers, parameters, accessLevel, chatType, data);
			}

			virtual RenSharpChatCommandStruct^ RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel, DAChatType chatType) sealed
			{
				return RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers, parameters, accessLevel, chatType);
			}

			virtual RenSharpChatCommandStruct^ RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel) sealed
			{
				return RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers, parameters, accessLevel);
			}

			virtual RenSharpChatCommandStruct^ RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, Object^ data) sealed
			{
				return RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers, parameters, data);
			}

			virtual RenSharpChatCommandStruct^ RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters) sealed
			{
				return RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers, parameters);
			}

			virtual RenSharpChatCommandStruct^ RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers) sealed
			{
				return RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers);
			}

			virtual void UnregisterChatCommand(String^ trigger) sealed
			{
				if (trigger == nullptr)
				{
					throw gcnew ArgumentNullException("trigger");
				}

				RenSharpChatCommandManager::UnregisterChatCommand(this, ChatCommandGroup::EventClass, trigger);

				IntPtr triggerHandle = Marshal::StringToHGlobalAnsi(trigger);
				try
				{
					InternalDAEventClassPointer->Unregister_Chat_Command(
						reinterpret_cast<char*>(triggerHandle.ToPointer()));
				}
				finally
				{
					Marshal::FreeHGlobal(triggerHandle);
				}
			}

			virtual void ClearChatCommands() sealed
			{
				RenSharpChatCommandManager::ClearChatCommands(this, ChatCommandGroup::EventClass);
				InternalDAEventClassPointer->Clear_Chat_Commands();
			}

			virtual bool FilterKeyHook(IcPlayer^ player, String^ key, Object^ data) sealed
			{
				return true;
			}

			virtual RenSharpKeyHookStruct^ RegisterKeyHook(RenSharpKHDelegate^ func, String^ triggers, Object^ data) sealed
			{
				return RenSharpKeyHookManager::RegisterKeyHook(this, KeyHookGroup::EventClass, func, triggers, data);
			}

			virtual RenSharpKeyHookStruct^ RegisterKeyHook(RenSharpKHDelegate^ func, String^ triggers) sealed
			{
				return RenSharpKeyHookManager::RegisterKeyHook(this, KeyHookGroup::EventClass, func, triggers);
			}

			virtual void UnregisterKeyHook(String^ trigger) sealed
			{
				if (trigger == nullptr)
				{
					throw gcnew ArgumentNullException("trigger");
				}

				RenSharpKeyHookManager::UnregisterKeyHook(this, KeyHookGroup::EventClass, trigger);

				IntPtr triggerHandle = Marshal::StringToHGlobalAnsi(trigger);
				try
				{
					InternalDAEventClassPointer->Unregister_Key_Hook(
						reinterpret_cast<char*>(triggerHandle.ToPointer()));
				}
				finally
				{
					Marshal::FreeHGlobal(triggerHandle);
				}
			}

			virtual void ClearKeyHooks() sealed
			{
				RenSharpKeyHookManager::ClearKeyHooks(this, KeyHookGroup::EventClass);
				InternalDAEventClassPointer->Clear_Key_Hooks();
			}

			virtual void RegisterEvent(DAEventType type, std::uint32_t priority) sealed
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}

				daEventClass->RegisterEvent(type, priority);
			}

			virtual void RegisterEvent(DAEventType type) sealed
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}

				daEventClass->RegisterEvent(type);
			}

			virtual void UnregisterEvent(DAEventType type) sealed
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}

				daEventClass->UnregisterEvent(type);
			}

			virtual void ClearEvents() sealed
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}

				daEventClass->ClearEvents();
			}

			virtual void RegisterObjectEvent(DAObjectEventType type, DAObjectEventObjectType objectType, std::uint32_t priority) sealed
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}

				daEventClass->RegisterObjectEvent(type, objectType, priority);
			}

			virtual void RegisterObjectEvent(DAObjectEventType type, DAObjectEventObjectType objectType) sealed
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}

				daEventClass->RegisterObjectEvent(type, objectType);
			}

			virtual void UnregisterObjectEvent(DAObjectEventType type) sealed
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}

				daEventClass->UnregisterObjectEvent(type);
			}

			virtual void ClearObjectEvents() sealed
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}

				daEventClass->ClearObjectEvents();
			}

			virtual IUnmanagedContainer<IDAPlayerDataClass^>^ CreateData() sealed
			{
				T managedData = CreateManagedData();
				if (managedData == nullptr)
				{
					return nullptr;
				}
				else
				{
					return gcnew UnmanagedContainer<IDAPlayerDataClass^>(gcnew DAPlayerDataClass(managedData->DAPlayerDataClassPointer));
				}
			}

			T CreateManagedData()
			{
				if (!IsAttached)
				{
					throw gcnew NotSupportedException("Not attached.");
				}

				T managedData = InternalCreateData();
				try
				{
					managedData->InitUnmanagedAttachable();

					managedData->Factory = gcnew DAPlayerDataFactoryClass(daPlayerDataFactoryClassPointer);

					return managedData;
				}
				catch (Exception^)
				{
#pragma push_macro("delete")
#undef delete

					delete managedData;
					managedData = T();

#pragma pop_macro("delete")

					throw;
				}
			}

			property IntPtr DAGameModeClassPointer
			{
				virtual IntPtr get() sealed
				{
					return daGameModeClassPointer;
				}
			}

			property IntPtr DAEventClassPointer
			{
				virtual IntPtr get() sealed
				{
					return daEventClassPointer;
				}
			}

			property IntPtr DAPlayerDataFactoryClassPointer
			{
				virtual IntPtr get() sealed
				{
					return daPlayerDataFactoryClassPointer;
				}
			}

			property IntPtr Pointer
			{
				virtual IntPtr get() sealed
				{
					return renSharpGameModeEventClassPlayerDataFactory;
				}
			}

			property bool IsAttached
			{
				virtual bool get() sealed
				{
					return (renSharpGameModeEventClassPlayerDataFactory != IntPtr::Zero);
				}
			}

			property bool IsRegistered
			{
				virtual bool get() sealed
				{
					return (
						IsAttached && 
						DAGameManager::IsManagedGameMode(daGameModeClassPointer) &&
						DAEventManager::IsManagedEventClass(daEventClassPointer) &&
						DAPlayerManager::IsManagedPlayerDataFactory(daPlayerDataFactoryClassPointer));
				}
			}

			property bool DestroyPointer
			{
				virtual bool get() sealed
				{
					return destroyPointer;
				}

				virtual void set(bool value) sealed
				{
					destroyPointer = value;
				}
			}

			property String^ LongName
			{
				virtual String^ get() sealed
				{
					if (!IsAttached)
					{
						throw gcnew NotSupportedException("Not attached.");
					}

					return daGameModeClass->LongName;
				}
			}

			property String^ ShortName
			{
				virtual String^ get() sealed
				{
					if (!IsAttached)
					{
						throw gcnew NotSupportedException("Not attached.");
					}

					return daGameModeClass->ShortName;
				}
			}

			property IDAGameModeFactoryClass^ Factory
			{
				virtual IDAGameModeFactoryClass^ get() sealed
				{
					if (!IsAttached)
					{
						throw gcnew NotSupportedException("Not attached.");
					}

					return daGameModeClass->Factory;
				}

				virtual void set(IDAGameModeFactoryClass^ value) sealed
				{
					if (!IsAttached)
					{
						throw gcnew NotSupportedException("Not attached.");
					}

					daGameModeClass->Factory = value;
				}
			}

			property Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ Timers
			{
				virtual Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ get() sealed
				{
					return RenSharpTimerManager::GetTimers(this);
				}
			}

			property Collections::Generic::IEnumerable<RenSharpChatCommandStruct^>^ ChatCommands
			{
				virtual Collections::Generic::IEnumerable<RenSharpChatCommandStruct^>^ get() sealed
				{
					return RenSharpChatCommandManager::GetChatCommands(this, ChatCommandGroup::EventClass);
				}
			}

			property Collections::Generic::IEnumerable<RenSharpKeyHookStruct^>^ KeyHooks
			{
				virtual Collections::Generic::IEnumerable<RenSharpKeyHookStruct^>^ get() sealed
				{
					return RenSharpKeyHookManager::GetKeyHooks(this, KeyHookGroup::EventClass);
				}
			}

		protected:
			property ::DAGameModeClass* InternalDAGameModeClassPointer
			{
				virtual ::DAGameModeClass* get()
				{
					return reinterpret_cast<::DAGameModeClass*>(daGameModeClassPointer.ToPointer());
				}
			}

			property ::DAEventClass* InternalDAEventClassPointer
			{
				virtual ::DAEventClass* get()
				{
					return reinterpret_cast<::DAEventClass*>(daEventClassPointer.ToPointer());
				}
			}

			property ::DAPlayerDataFactoryClass* InternalDAPlayerDataFactoryClassPointer
			{
				virtual ::DAPlayerDataFactoryClass* get()
				{
					return reinterpret_cast<::DAPlayerDataFactoryClass*>(daPlayerDataFactoryClassPointer.ToPointer());
				}
			}

			virtual T InternalCreateData()
			{
				return safe_cast<T>(Activator::CreateInstance(T::typeid));
			}
	};
}