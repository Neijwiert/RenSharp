/*
Copyright 2019 Neijwiert

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

#include "stdafx.h"
#include "Mda_event.h"

#include "Imports.h"
#include "McPlayer.h"
#include "Mda_token.h"
#include "MBaseControllerClass.h"
#include "MSoldierGameObjDef.h"
#include "MVehicleGameObjDef.h"
#include "MPowerUpGameObjDef.h"
#include "MVehicleGameObj.h"
#include "MPowerUpGameObj.h"
#include "Mweaponmgr.h"
#include "MBeaconGameObj.h"
#include "MC4GameObj.h"
#include "MSmartGameObj.h"
#include "MVehicleFactoryGameObj.h"
#include "MScriptableGameObj.h"
#include "MDamageableGameObj.h"
#include "MArmedGameObj.h"
#include "MPhysicalGameObj.h"
#include "MScriptZoneGameObj.h"
#include "MConnectionRequest.h"
#include "MWeaponClass.h"
#include "MSoldierGameObj.h"
#include "UnmanagedContainer.h"
#include "MWeaponBagClass.h"
#include "RenSharpEventClass.h"

namespace RenSharp
{
	DAEventStruct::DAEventStruct()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateDAEventStruct()))
	{

	}

	DAEventStruct::DAEventStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{
		
	}

	IUnmanagedContainer<IDAEventStruct^>^ DAEventStruct::CreateDAEventStruct()
	{
		return gcnew UnmanagedContainer<IDAEventStruct^>(gcnew DAEventStruct());
	}

	bool DAEventStruct::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDAEventStruct^ otherThis = dynamic_cast<IDAEventStruct^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DAEventStructPointer.Equals(otherThis->DAEventStructPointer);
	}

	IntPtr DAEventStruct::DAEventStructPointer::get()
	{
		return IntPtr(InternalDAEventStructPointer);
	}

	IDAEventClass^ DAEventStruct::Base::get()
	{
		auto result = InternalDAEventStructPointer->Base;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAEventClass(IntPtr(result));
		}
	}

	void DAEventStruct::Base::set(IDAEventClass^ value)
	{
		if (value == nullptr || value->DAEventClassPointer.ToPointer() == nullptr)
		{
			InternalDAEventStructPointer->Base = nullptr;
		}
		else
		{
			InternalDAEventStructPointer->Base = reinterpret_cast<::DAEventClass*>(value->DAEventClassPointer.ToPointer());
		}
	}

	int DAEventStruct::Priority::get()
	{
		return InternalDAEventStructPointer->Priority;
	}

	void DAEventStruct::Priority::set(int value)
	{
		InternalDAEventStructPointer->Priority = value;
	}

	bool DAEventStruct::InternalDestroyPointer()
	{
		Imports::DestroyDAEventStruct(InternalDAEventStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DAEventStruct* DAEventStruct::InternalDAEventStructPointer::get()
	{
		return reinterpret_cast<::DAEventStruct*>(Pointer.ToPointer());
	}

	DAObjectEventStruct::DAObjectEventStruct()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateDAObjectEventStruct()))
	{

	}

	DAObjectEventStruct::DAObjectEventStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IDAObjectEventStruct^>^ DAObjectEventStruct::CreateDAObjectEventStruct()
	{
		return gcnew UnmanagedContainer<IDAObjectEventStruct^>(gcnew DAObjectEventStruct());
	}

	bool DAObjectEventStruct::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDAObjectEventStruct^ otherThis = dynamic_cast<IDAObjectEventStruct^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DAObjectEventStructPointer.Equals(otherThis->DAObjectEventStructPointer);
	}

	bool DAObjectEventStruct::HasFlag(DAObjectEventObjectType flag)
	{
		return InternalDAObjectEventStructPointer->Has_Flag(
			static_cast<DAObjectEvent::ObjectType>(flag));
	}

	bool DAObjectEventStruct::CheckObjectType(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			return InternalDAObjectEventStructPointer->Check_Object_Type(nullptr);
		}
		else
		{
			return InternalDAObjectEventStructPointer->Check_Object_Type(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
		}
	}

	IntPtr DAObjectEventStruct::DAObjectEventStructPointer::get()
	{
		return IntPtr(InternalDAObjectEventStructPointer);
	}

	IDAEventClass^ DAObjectEventStruct::Base::get()
	{
		auto result = InternalDAObjectEventStructPointer->Base;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAEventClass(IntPtr(result));
		}
	}

	void DAObjectEventStruct::Base::set(IDAEventClass^ value)
	{
		if (value == nullptr || value->DAEventClassPointer.ToPointer() == nullptr)
		{
			InternalDAObjectEventStructPointer->Base = nullptr;
		}
		else
		{
			InternalDAObjectEventStructPointer->Base = reinterpret_cast<::DAEventClass*>(value->DAEventClassPointer.ToPointer());
		}
	}

	DAObjectEventObjectType DAObjectEventStruct::ObjectType::get()
	{
		return static_cast<DAObjectEventObjectType>(InternalDAObjectEventStructPointer->ObjectType);
	}

	void DAObjectEventStruct::ObjectType::set(DAObjectEventObjectType value)
	{
		InternalDAObjectEventStructPointer->ObjectType = static_cast<DAObjectEvent::ObjectType>(value);
	}

	int DAObjectEventStruct::Priority::get()
	{
		return InternalDAObjectEventStructPointer->Priority;
	}

	void DAObjectEventStruct::Priority::set(int value)
	{
		InternalDAObjectEventStructPointer->Priority = value;
	}

	bool DAObjectEventStruct::InternalDestroyPointer()
	{
		Imports::DestroyDAObjectEventStruct(InternalDAObjectEventStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DAObjectEventStruct* DAObjectEventStruct::InternalDAObjectEventStructPointer::get()
	{
		return reinterpret_cast<::DAObjectEventStruct*>(Pointer.ToPointer());
	}

	DAEventTimerStruct::DAEventTimerStruct()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateDAEventTimerStruct()))
	{

	}

	DAEventTimerStruct::DAEventTimerStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IDAEventTimerStruct^>^ DAEventTimerStruct::CreateDAEventTimerStruct()
	{
		return gcnew UnmanagedContainer<IDAEventTimerStruct^>(gcnew DAEventTimerStruct());
	}

	bool DAEventTimerStruct::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDAEventTimerStruct^ otherThis = dynamic_cast<IDAEventTimerStruct^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DAEventTimerStructPointer.Equals(otherThis->DAEventTimerStructPointer);
	}

	IntPtr DAEventTimerStruct::DAEventTimerStructPointer::get()
	{
		return IntPtr(InternalDAEventTimerStructPointer);
	}

	IDAEventClass^ DAEventTimerStruct::Base::get()
	{
		auto result = InternalDAEventTimerStructPointer->Base;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAEventClass(IntPtr(result));
		}
	}

	void DAEventTimerStruct::Base::set(IDAEventClass^ value)
	{
		if (value == nullptr || value->DAEventClassPointer.ToPointer() == nullptr)
		{
			InternalDAEventTimerStructPointer->Base = nullptr;
		}
		else
		{
			InternalDAEventTimerStructPointer->Base = reinterpret_cast<::DAEventClass*>(value->DAEventClassPointer.ToPointer());
		}
	}

	unsigned long DAEventTimerStruct::StartTime::get()
	{
		return InternalDAEventTimerStructPointer->StartTime;
	}

	void DAEventTimerStruct::StartTime::set(unsigned long value)
	{
		InternalDAEventTimerStructPointer->StartTime = value;
	}

	unsigned long DAEventTimerStruct::Duration::get()
	{
		return InternalDAEventTimerStructPointer->Duration;
	}

	void DAEventTimerStruct::Duration::set(unsigned long value)
	{
		InternalDAEventTimerStructPointer->Duration = value;
	}

	bool DAEventTimerStruct::Repeat::get()
	{
		return InternalDAEventTimerStructPointer->Repeat;
	}

	void DAEventTimerStruct::Repeat::set(bool value)
	{
		InternalDAEventTimerStructPointer->Repeat = value;
	}

	int DAEventTimerStruct::Number::get()
	{
		return InternalDAEventTimerStructPointer->Number;
	}

	void DAEventTimerStruct::Number::set(int value)
	{
		InternalDAEventTimerStructPointer->Number = value;
	}

	unsigned int DAEventTimerStruct::Data::get()
	{
		return InternalDAEventTimerStructPointer->Data;
	}

	void DAEventTimerStruct::Data::set(unsigned int value)
	{
		InternalDAEventTimerStructPointer->Data = value;
	}

	bool DAEventTimerStruct::InternalDestroyPointer()
	{
		Imports::DestroyDAEventTimerStruct(InternalDAEventTimerStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DAEventTimerStruct* DAEventTimerStruct::InternalDAEventTimerStructPointer::get()
	{
		return reinterpret_cast<::DAEventTimerStruct*>(Pointer.ToPointer());
	}

	static DAEventManager::DAEventManager()
	{
		managedEventClasses = gcnew Generic::Dictionary<IntPtr, IRenSharpEventClass^>();
	}

	void DAEventManager::OnManagedEventClassDestructed(IntPtr eventClass)
	{
		IRenSharpEventClass^ managedEventClass = AsManagedEventClass(eventClass);
		if (managedEventClass != nullptr && managedEventClass->IsAttached)
		{
			managedEventClass->DestroyPointer = false;

#pragma push_macro("delete")
#undef delete

			delete managedEventClass;
			managedEventClass = nullptr;

#pragma pop_macro("delete")
		}
	}

	void DAEventManager::Shutdown()
	{
		auto tmpManagedEventClasses = gcnew Generic::Dictionary<IntPtr, IRenSharpEventClass^>(managedEventClasses);

		for each (auto eventClass in tmpManagedEventClasses->Values)
		{
#pragma push_macro("delete")
#undef delete

			delete eventClass;
			eventClass = nullptr;

#pragma pop_macro("delete")
		}

		tmpManagedEventClasses->Clear();
		managedEventClasses->Clear();
	}

	bool DAEventManager::IsManagedEventClass(IntPtr eventClass)
	{
		return managedEventClasses->ContainsKey(eventClass);
	}

	bool DAEventManager::IsManagedEventClass(IDAEventClass^ eventClass)
	{
		if (eventClass == nullptr)
		{
			throw gcnew ArgumentNullException("eventClass");
		}

		return IsManagedEventClass(eventClass->DAEventClassPointer);
	}

	IRenSharpEventClass^ DAEventManager::AsManagedEventClass(IntPtr eventClass)
	{
		IRenSharpEventClass^ result = nullptr;
		managedEventClasses->TryGetValue(eventClass, result);

		return result;
	}

	IRenSharpEventClass^ DAEventManager::AsManagedEventClass(IDAEventClass^ eventClass)
	{
		if (eventClass == nullptr)
		{
			throw gcnew ArgumentNullException("eventClass");
		}

		return AsManagedEventClass(eventClass->DAEventClassPointer);
	}

	void DAEventManager::Init()
	{
		::DAEventManager::Init();
	}

	void DAEventManager::SettingsLoadedEvent()
	{
		::DAEventManager::Settings_Loaded_Event();
	}

	bool DAEventManager::ChatEvent(IcPlayer^ player, TextMessageEnum type, String^ message, int receiverID)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (message == nullptr)
		{
			throw gcnew ArgumentNullException("message");
		}

		IntPtr messageHandle = Marshal::StringToHGlobalUni(message);
		try
		{
			return ::DAEventManager::Chat_Event(
				reinterpret_cast<::cPlayer *>(player->cPlayerPointer.ToPointer()),
				static_cast<::TextMessageEnum>(type),
				reinterpret_cast<wchar_t*>(messageHandle.ToPointer()),
				receiverID);
		}
		finally
		{
			Marshal::FreeHGlobal(messageHandle);
		}
	}

	bool DAEventManager::ChatCommandEvent(IcPlayer^ player, TextMessageEnum type, String^ command, IDATokenClass^ text, int receiverID)
	{
		if (command == nullptr)
		{
			throw gcnew ArgumentNullException("command");
		}
		else if (text == nullptr || text->DATokenClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("text");
		}

		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		IntPtr commandHandle = Marshal::StringToHGlobalAnsi(command);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(commandHandle.ToPointer()));

			return ::DAEventManager::Chat_Command_Event(
				playerPtr,
				static_cast<::TextMessageEnum>(type),
				tmp,
				*reinterpret_cast<::DATokenClass*>(text->DATokenClassPointer.ToPointer()),
				receiverID);
		}
		finally
		{
			Marshal::FreeHGlobal(commandHandle);
		}
	}

	bool DAEventManager::KeyHookEvent(IcPlayer^ player, String^ key)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}

		IntPtr keyHandle = Marshal::StringToHGlobalAnsi(key);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(keyHandle.ToPointer()));

			return ::DAEventManager::Key_Hook_Event(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
				tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(keyHandle);
		}
	}

	bool DAEventManager::HostChatEvent(int id, TextMessageEnum type, String^ message)
	{
		if (message == nullptr)
		{
			return ::DAEventManager::Host_Chat_Event(
				id,
				static_cast<::TextMessageEnum>(type),
				nullptr);
		}
		else
		{
			IntPtr messageHandle = Marshal::StringToHGlobalAnsi(message);
			try
			{
				return ::DAEventManager::Host_Chat_Event(
					id,
					static_cast<::TextMessageEnum>(type),
					reinterpret_cast<char*>(messageHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(messageHandle);
			}
		}
	}

	bool DAEventManager::RadioEvent(int playerId, int playerType, int announcementID, int iconID, AnnouncementEnum announcementType)
	{
		return ::DAEventManager::Radio_Event(
			playerId,
			playerType,
			announcementID,
			iconID,
			static_cast<::AnnouncementEnum>(announcementType));
	}

	void DAEventManager::PlayerJoinEvent(int playerId, String^ name)
	{
		if (name == nullptr)
		{
			::DAEventManager::Player_Join_Event(playerId, nullptr);
		}
		else
		{
			IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
			try
			{
				::DAEventManager::Player_Join_Event(
					playerId, 
					reinterpret_cast<char *>(nameHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(nameHandle);
			}
		}
	}

	void DAEventManager::PlayerLeaveEvent(int playerId)
	{
		::DAEventManager::Player_Leave_Event(playerId);
	}

	void DAEventManager::NameChangeEvent(IcPlayer^ player)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		::DAEventManager::Name_Change_Event(playerPtr);
	}

	void DAEventManager::LevelLoadedEvent()
	{
		::DAEventManager::Level_Loaded_Event();
	}

	void DAEventManager::RemixEvent()
	{
		::DAEventManager::Remix_Event();
	}

	void DAEventManager::RebalanceEvent()
	{
		::DAEventManager::Rebalance_Event();
	}

	void DAEventManager::SwapEvent()
	{
		::DAEventManager::Swap_Event();
	}

	void DAEventManager::GameOverEvent()
	{
		::DAEventManager::Game_Over_Event();
	}

	void DAEventManager::ConsoleOutputEvent(String^ output)
	{
		if (output == nullptr)
		{
			::DAEventManager::Console_Output_Event(nullptr);
		}
		else
		{
			IntPtr outputHandle = Marshal::StringToHGlobalAnsi(output);
			try
			{
				::DAEventManager::Console_Output_Event(
					reinterpret_cast<char*>(outputHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(outputHandle);
			}
		}
	}

	void DAEventManager::RenLogEvent(String^ output)
	{
		if (output == nullptr)
		{
			::DAEventManager::Console_Output_Event(nullptr);
		}
		else
		{
			IntPtr outputHandle = Marshal::StringToHGlobalAnsi(output);
			try
			{
				::DAEventManager::Ren_Log_Event(
					reinterpret_cast<char*>(outputHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(outputHandle);
			}
		}
	}

	void DAEventManager::DALogEvent(String^ header, String^ output)
	{
		if (header == nullptr)
		{
			if (output == nullptr)
			{
				::DAEventManager::DA_Log_Event(nullptr, nullptr);
			}
			else
			{
				IntPtr outputHandle = Marshal::StringToHGlobalAnsi(output);
				try
				{
					::DAEventManager::DA_Log_Event(
						nullptr,
						reinterpret_cast<char*>(outputHandle.ToPointer()));
				}
				finally
				{
					Marshal::FreeHGlobal(outputHandle);
				}
			}
		}
		else
		{
			IntPtr headerHandle = Marshal::StringToHGlobalAnsi(header);
			try
			{
				if (output == nullptr)
				{
					::DAEventManager::DA_Log_Event(
						reinterpret_cast<char*>(headerHandle.ToPointer()),
						nullptr);
				}
				else
				{
					IntPtr outputHandle = Marshal::StringToHGlobalAnsi(output);
					try
					{
						::DAEventManager::DA_Log_Event(
							reinterpret_cast<char*>(headerHandle.ToPointer()),
							reinterpret_cast<char*>(outputHandle.ToPointer()));
					}
					finally
					{
						Marshal::FreeHGlobal(outputHandle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(headerHandle);
			}
		}
	}

	int DAEventManager::CharacterPurchaseRequestEvent(IBaseControllerClass^ baseController, ISoldierGameObj^ soldier, unsigned int cost, unsigned int preset, String^ data)
	{
		if (soldier == nullptr || soldier->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}

		::BaseControllerClass* baseControllerPtr;
		if (baseController == nullptr || baseController->BaseControllerClassPointer.ToPointer() == nullptr)
		{
			baseControllerPtr = nullptr;
		}
		else
		{
			baseControllerPtr = reinterpret_cast<::BaseControllerClass*>(baseController->BaseControllerClassPointer.ToPointer());
		}

		if (data == nullptr)
		{
			return ::DAEventManager::Character_Purchase_Request_Event(
				baseControllerPtr,
				reinterpret_cast<::SoldierGameObj*>(soldier->SoldierGameObjPointer.ToPointer()),
				cost,
				preset,
				nullptr);
		}
		else
		{
			IntPtr dataHandle = Marshal::StringToHGlobalAnsi(data);
			try
			{
				return ::DAEventManager::Character_Purchase_Request_Event(
					baseControllerPtr,
					reinterpret_cast<::SoldierGameObj*>(soldier->SoldierGameObjPointer.ToPointer()),
					cost,
					preset,
					reinterpret_cast<char *>(dataHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(dataHandle);
			}
		}
	}

	int DAEventManager::VehiclePurchaseRequestEvent(IBaseControllerClass^ baseController, ISoldierGameObj^ soldier, unsigned int cost, unsigned int preset, String^ data)
	{
		if (soldier == nullptr || soldier->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}

		::BaseControllerClass* baseControllerPtr;
		if (baseController == nullptr || baseController->BaseControllerClassPointer.ToPointer() == nullptr)
		{
			baseControllerPtr = nullptr;
		}
		else
		{
			baseControllerPtr = reinterpret_cast<::BaseControllerClass*>(baseController->BaseControllerClassPointer.ToPointer());
		}

		if (data == nullptr)
		{
			return ::DAEventManager::Vehicle_Purchase_Request_Event(
				baseControllerPtr,
				reinterpret_cast<::SoldierGameObj*>(soldier->SoldierGameObjPointer.ToPointer()),
				cost,
				preset,
				nullptr);
		}
		else
		{
			IntPtr dataHandle = Marshal::StringToHGlobalAnsi(data);
			try
			{
				return ::DAEventManager::Vehicle_Purchase_Request_Event(
					baseControllerPtr,
					reinterpret_cast<::SoldierGameObj*>(soldier->SoldierGameObjPointer.ToPointer()),
					cost,
					preset,
					reinterpret_cast<char*>(dataHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(dataHandle);
			}
		}
	}

	int DAEventManager::PowerUpPurchaseRequestEvent(IBaseControllerClass^ baseController, ISoldierGameObj^ soldier, unsigned int cost, unsigned int preset, String^ data)
	{
		if (soldier == nullptr || soldier->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}

		::BaseControllerClass* baseControllerPtr;
		if (baseController == nullptr || baseController->BaseControllerClassPointer.ToPointer() == nullptr)
		{
			baseControllerPtr = nullptr;
		}
		else
		{
			baseControllerPtr = reinterpret_cast<::BaseControllerClass*>(baseController->BaseControllerClassPointer.ToPointer());
		}

		if (data == nullptr)
		{
			return ::DAEventManager::PowerUp_Purchase_Request_Event(
				baseControllerPtr,
				reinterpret_cast<::SoldierGameObj*>(soldier->SoldierGameObjPointer.ToPointer()),
				cost,
				preset,
				nullptr);
		}
		else
		{
			IntPtr dataHandle = Marshal::StringToHGlobalAnsi(data);
			try
			{
				return ::DAEventManager::PowerUp_Purchase_Request_Event(
					baseControllerPtr,
					reinterpret_cast<::SoldierGameObj*>(soldier->SoldierGameObjPointer.ToPointer()),
					cost,
					preset,
					reinterpret_cast<char*>(dataHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(dataHandle);
			}
		}
	}

	int DAEventManager::CustomPurchaseRequestEvent(IBaseControllerClass^ baseController, ISoldierGameObj^ soldier, unsigned int cost, unsigned int preset)
	{
		if (soldier == nullptr || soldier->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}

		::BaseControllerClass* baseControllerPtr;
		if (baseController == nullptr || baseController->BaseControllerClassPointer.ToPointer() == nullptr)
		{
			baseControllerPtr = nullptr;
		}
		else
		{
			baseControllerPtr = reinterpret_cast<::BaseControllerClass*>(baseController->BaseControllerClassPointer.ToPointer());
		}

		return ::DAEventManager::Custom_Purchase_Request_Event(
			baseControllerPtr,
			reinterpret_cast<::SoldierGameObj*>(soldier->SoldierGameObjPointer.ToPointer()),
			cost,
			preset);
	}

	void DAEventManager::CharacterPurchaseEvent(IcPlayer^ player, float cost, ISoldierGameObjDef^ item)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		::SoldierGameObjDef* itemPtr;
		if (item == nullptr || item->SoldierGameObjDefPointer.ToPointer() == nullptr)
		{
			itemPtr = nullptr;
		}
		else
		{
			itemPtr = reinterpret_cast<::SoldierGameObjDef*>(item->SoldierGameObjDefPointer.ToPointer());
		}

		::DAEventManager::Character_Purchase_Event(
			playerPtr,
			cost,
			itemPtr);
	}

	void DAEventManager::VehiclePurchaseEvent(IcPlayer^ player, float cost, IVehicleGameObjDef^ item)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		::VehicleGameObjDef* itemPtr;
		if (item == nullptr || item->VehicleGameObjDefPointer.ToPointer() == nullptr)
		{
			itemPtr = nullptr;
		}
		else
		{
			itemPtr = reinterpret_cast<::VehicleGameObjDef*>(item->VehicleGameObjDefPointer.ToPointer());
		}

		::DAEventManager::Vehicle_Purchase_Event(
			playerPtr,
			cost,
			itemPtr);
	}

	void DAEventManager::PowerUpPurchaseEvent(IcPlayer^ player, float cost, IPowerUpGameObjDef^ item)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		::PowerUpGameObjDef* itemPtr;
		if (item == nullptr || item->PowerUpGameObjDefPointer.ToPointer() == nullptr)
		{
			itemPtr = nullptr;
		}
		else
		{
			itemPtr = reinterpret_cast<::PowerUpGameObjDef*>(item->PowerUpGameObjDefPointer.ToPointer());
		}

		::DAEventManager::PowerUp_Purchase_Event(
			playerPtr,
			cost,
			itemPtr);
	}

	void DAEventManager::CustomPurchaseEvent(IcPlayer^ player, float cost, unsigned int id)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		::DAEventManager::Custom_Purchase_Event(
			playerPtr,
			cost,
			id);
	}

	bool DAEventManager::RefillEvent(ISoldierGameObj^ soldier)
	{
		if (soldier == nullptr || soldier->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}

		return ::DAEventManager::Refill_Event(
			reinterpret_cast<::SoldierGameObj*>(soldier->SoldierGameObjPointer.ToPointer()));
	}

	void DAEventManager::SuicideEvent(int id)
	{
		return ::DAEventManager::Suicide_Event(id);
	}

	void DAEventManager::TeamChangeRequestEvent(int id)
	{
		::DAEventManager::Team_Change_Request_Event(id);
	}

	bool DAEventManager::VehicleEntryRequestEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int% seat)
	{
		::VehicleGameObj* vehiclePtr;
		if (vehicle == nullptr || vehicle->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			vehiclePtr = nullptr;
		}
		else
		{
			vehiclePtr = reinterpret_cast<::VehicleGameObj*>(vehicle->VehicleGameObjPointer.ToPointer());
		}

		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		int tmpSeat = seat;

		auto result = ::DAEventManager::Vehicle_Entry_Request_Event(
			vehiclePtr,
			playerPtr,
			tmpSeat);

		seat = tmpSeat;

		return result;
	}

	bool DAEventManager::PowerUpGrantRequestEvent(ISmartGameObj^ grantee, IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj)
	{
		::SmartGameObj* granteePtr;
		if (grantee == nullptr || grantee->SmartGameObjPointer.ToPointer() == nullptr)
		{
			granteePtr = nullptr;
		}
		else
		{
			granteePtr = reinterpret_cast<::SmartGameObj*>(grantee->SmartGameObjPointer.ToPointer());
		}

		::PowerUpGameObjDef* powerUpPtr;
		if (powerUp == nullptr || powerUp->PowerUpGameObjDefPointer.ToPointer() == nullptr)
		{
			powerUpPtr = nullptr;
		}
		else
		{
			powerUpPtr = reinterpret_cast<::PowerUpGameObjDef*>(powerUp->PowerUpGameObjDefPointer.ToPointer());
		}

		::PowerUpGameObj* powerUpObjPtr;
		if (powerUpObj == nullptr || powerUpObj->PowerUpGameObjPointer.ToPointer() == nullptr)
		{
			powerUpObjPtr = nullptr;
		}
		else
		{
			powerUpObjPtr = reinterpret_cast<::PowerUpGameObj*>(powerUpObj->PowerUpGameObjPointer.ToPointer());
		}

		return ::DAEventManager::PowerUp_Grant_Request_Event(
			granteePtr,
			powerUpPtr,
			powerUpObjPtr);
	}

	void DAEventManager::PowerUpGrantEvent(ISmartGameObj^ grantee, IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj)
	{
		::SmartGameObj* granteePtr;
		if (grantee == nullptr || grantee->SmartGameObjPointer.ToPointer() == nullptr)
		{
			granteePtr = nullptr;
		}
		else
		{
			granteePtr = reinterpret_cast<::SmartGameObj*>(grantee->SmartGameObjPointer.ToPointer());
		}

		::PowerUpGameObjDef* powerUpPtr;
		if (powerUp == nullptr || powerUp->PowerUpGameObjDefPointer.ToPointer() == nullptr)
		{
			powerUpPtr = nullptr;
		}
		else
		{
			powerUpPtr = reinterpret_cast<::PowerUpGameObjDef*>(powerUp->PowerUpGameObjDefPointer.ToPointer());
		}

		::PowerUpGameObj* powerUpObjPtr;
		if (powerUpObj == nullptr || powerUpObj->PowerUpGameObjPointer.ToPointer() == nullptr)
		{
			powerUpObjPtr = nullptr;
		}
		else
		{
			powerUpObjPtr = reinterpret_cast<::PowerUpGameObj*>(powerUpObj->PowerUpGameObjPointer.ToPointer());
		}

		::DAEventManager::PowerUp_Grant_Event(
			granteePtr,
			powerUpPtr,
			powerUpObjPtr);
	}

	bool DAEventManager::AddWeaponRequestEvent(IWeaponBagClass^ bag, IWeaponDefinitionClass^ weapon)
	{
		if (bag == nullptr || bag->WeaponBagClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("bag");
		}

		::WeaponDefinitionClass* weaponPtr;
		if (weapon == nullptr || weapon->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			weaponPtr = nullptr;
		}
		else
		{
			weaponPtr = reinterpret_cast<::WeaponDefinitionClass*>(weapon->WeaponDefinitionClassPointer.ToPointer());
		}

		return ::DAEventManager::Add_Weapon_Request_Event(
			reinterpret_cast<::WeaponBagClass*>(bag->WeaponBagClassPointer.ToPointer()),
			weaponPtr);
	}

	void DAEventManager::AddWeaponEvent(IWeaponBagClass^ bag, IWeaponClass^ weapon)
	{
		if (bag == nullptr || bag->WeaponBagClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("bag");
		}

		::WeaponClass* weaponPtr;
		if (weapon == nullptr || weapon->WeaponClassPointer.ToPointer() == nullptr)
		{
			weaponPtr = nullptr;
		}
		else
		{
			weaponPtr = reinterpret_cast<::WeaponClass*>(weapon->WeaponClassPointer.ToPointer());
		}

		::DAEventManager::Add_Weapon_Event(
			reinterpret_cast<::WeaponBagClass*>(bag->WeaponBagClassPointer.ToPointer()),
			weaponPtr);
	}

	void DAEventManager::RemoveWeaponEvent(IWeaponBagClass^ bag, int index)
	{
		if (bag == nullptr || bag->WeaponBagClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("bag");
		}
		else if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		::DAEventManager::Remove_Weapon_Event(
			reinterpret_cast<::WeaponBagClass*>(bag->WeaponBagClassPointer.ToPointer()),
			index);
	}

	void DAEventManager::ClearWeaponsEvent(IWeaponBagClass^ bag)
	{
		if (bag == nullptr || bag->WeaponBagClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("bag");
		}

		::DAEventManager::Clear_Weapons_Event(
			reinterpret_cast<::WeaponBagClass*>(bag->WeaponBagClassPointer.ToPointer()));
	}

	void DAEventManager::BeaconSetStateEvent(IBeaconGameObj^ beacon)
	{
		if (beacon == nullptr || beacon->BeaconGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("beacon");
		}

		::DAEventManager::Beacon_Set_State_Event(
			reinterpret_cast<::BeaconGameObj*>(beacon->BeaconGameObjPointer.ToPointer()));
	}

	bool DAEventManager::C4DetonateRequestEvent(IC4GameObj^ c4)
	{
		if (c4 == nullptr || c4->C4GameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("c4");
		}

		return ::DAEventManager::C4_Detonate_Request_Event(
			reinterpret_cast<::C4GameObj*>(c4->C4GameObjPointer.ToPointer()));
	}

	void DAEventManager::C4DetonateEvent(IC4GameObj^ c4)
	{
		::C4GameObj* c4Ptr;
		if (c4 == nullptr || c4->C4GameObjPointer.ToPointer() == nullptr)
		{
			c4Ptr = nullptr;
		}
		else
		{
			c4Ptr = reinterpret_cast<::C4GameObj*>(c4->C4GameObjPointer.ToPointer());
		}

		::DAEventManager::C4_Detonate_Event(c4Ptr);
	}

	void DAEventManager::SoldierReInitEvent(ISoldierGameObj^ soldier, ISoldierGameObjDef^ soldierDef)
	{
		if (soldier == nullptr || soldier->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}

		::SoldierGameObjDef* soldierDefPtr;
		if (soldierDef == nullptr || soldierDef->SoldierGameObjDefPointer.ToPointer() == nullptr)
		{
			soldierDefPtr = nullptr;
		}
		else
		{
			soldierDefPtr = reinterpret_cast<::SoldierGameObjDef*>(soldierDef->SoldierGameObjDefPointer.ToPointer());
		}

		::DAEventManager::Soldier_Re_Init_Event(
			reinterpret_cast<::SoldierGameObj*>(soldier->SoldierGameObjPointer.ToPointer()),
			soldierDefPtr);
	}

	bool DAEventManager::VehicleFlipEvent(IVehicleGameObj^ vehicle)
	{
		::VehicleGameObj* vehiclePtr;
		if (vehicle == nullptr || vehicle->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			vehiclePtr = nullptr;
		}
		else
		{
			vehiclePtr = reinterpret_cast<::VehicleGameObj*>(vehicle->VehicleGameObjPointer.ToPointer());
		}

		return ::DAEventManager::Vehicle_Flip_Event(vehiclePtr);
	}

	bool DAEventManager::RequestVehicleEvent(IVehicleFactoryGameObj^ factory, unsigned int vehicle, ISoldierGameObj^ owner, float delay)
	{
		::VehicleFactoryGameObj* factoryPtr;
		if (factory == nullptr || factory->VehicleFactoryGameObjPointer.ToPointer() == nullptr)
		{
			factoryPtr = nullptr;
		}
		else
		{
			factoryPtr = reinterpret_cast<::VehicleFactoryGameObj*>(factory->VehicleFactoryGameObjPointer.ToPointer());
		}

		::SoldierGameObj* ownerPtr;
		if (owner == nullptr || owner->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			ownerPtr = nullptr;
		}
		else
		{
			ownerPtr = reinterpret_cast<::SoldierGameObj*>(owner->SoldierGameObjPointer.ToPointer());
		}

		return ::DAEventManager::Request_Vehicle_Event(factoryPtr, vehicle, ownerPtr, delay);
	}

	void DAEventManager::Think()
	{
		::DAEventManager::Think();
	}

	void DAEventManager::ObjectCreatedEvent(IntPtr data, IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::DAEventManager::Object_Created_Event(
			data.ToPointer(), 
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool DAEventManager::StockClientDamageRequestEvent(IPhysicalGameObj^ damager, IPhysicalGameObj^ target, float damage, uint warhead)
	{
		if (target == nullptr || target->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("target");
		}

		::PhysicalGameObj* damagerPtr;
		if (damager == nullptr || damager->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			damagerPtr = nullptr;
		}
		else
		{
			damagerPtr = reinterpret_cast<::PhysicalGameObj*>(damager->PhysicalGameObjPointer.ToPointer());
		}

		return ::DAEventManager::Stock_Client_Damage_Request_Event(
			damagerPtr,
			reinterpret_cast<::PhysicalGameObj*>(target->PhysicalGameObjPointer.ToPointer()),
			damage,
			warhead);
	}

	bool DAEventManager::TTClientDamageRequestEvent(IPhysicalGameObj^ damager, IPhysicalGameObj^ target, IAmmoDefinitionClass^ ammo, String^ bone)
	{
		if (target == nullptr || target->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("target");
		}

		::PhysicalGameObj* damagerPtr;
		if (damager == nullptr || damager->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			damagerPtr = nullptr;
		}
		else
		{
			damagerPtr = reinterpret_cast<::PhysicalGameObj*>(damager->PhysicalGameObjPointer.ToPointer());
		}

		::AmmoDefinitionClass* ammoPtr;
		if (ammo == nullptr || ammo->AmmoDefinitionClassPointer.ToPointer() == nullptr)
		{
			ammoPtr = nullptr;
		}
		else
		{
			ammoPtr = reinterpret_cast<::AmmoDefinitionClass*>(ammo->AmmoDefinitionClassPointer.ToPointer());
		}

		if (bone == nullptr)
		{
			return ::DAEventManager::TT_Client_Damage_Request_Event(
				damagerPtr,
				reinterpret_cast<::PhysicalGameObj*>(target->PhysicalGameObjPointer.ToPointer()),
				ammoPtr,
				nullptr);
		}
		else
		{
			IntPtr boneHandle = Marshal::StringToHGlobalAnsi(bone);
			try
			{
				return ::DAEventManager::TT_Client_Damage_Request_Event(
					damagerPtr,
					reinterpret_cast<::PhysicalGameObj*>(target->PhysicalGameObjPointer.ToPointer()),
					ammoPtr,
					reinterpret_cast<char*>(boneHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(boneHandle);
			}
		}
	}

	bool DAEventManager::DamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float% damage, unsigned int% warhead, float scale, DADamageType type)
	{
		::DamageableGameObj* victimPtr;
		if (victim == nullptr || victim->DamageableGameObjPointer.ToPointer() == nullptr)
		{
			victimPtr = nullptr;
		}
		else
		{
			victimPtr = reinterpret_cast<::DamageableGameObj*>(victim->DamageableGameObjPointer.ToPointer());
		}

		::ArmedGameObj* damagerPtr;
		if (damager == nullptr || damager->ArmedGameObjPointer.ToPointer() == nullptr)
		{
			damagerPtr = nullptr;
		}
		else
		{
			damagerPtr = reinterpret_cast<::ArmedGameObj*>(damager->ArmedGameObjPointer.ToPointer());
		}

		float tmpDamage = damage;
		unsigned int tmpWarhead = warhead;

		auto result = ::DAEventManager::Damage_Request_Event(
			victimPtr,
			damagerPtr,
			tmpDamage,
			tmpWarhead,
			scale,
			static_cast<::DADamageType::Type>(type));

		damage = tmpDamage;
		warhead = tmpWarhead;

		return result;
	}

	void DAEventManager::DamageEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float damage, unsigned int warhead, float scale, DADamageType type)
	{
		::DamageableGameObj* victimPtr;
		if (victim == nullptr || victim->DamageableGameObjPointer.ToPointer() == nullptr)
		{
			victimPtr = nullptr;
		}
		else
		{
			victimPtr = reinterpret_cast<::DamageableGameObj*>(victim->DamageableGameObjPointer.ToPointer());
		}

		::ArmedGameObj* damagerPtr;
		if (damager == nullptr || damager->ArmedGameObjPointer.ToPointer() == nullptr)
		{
			damagerPtr = nullptr;
		}
		else
		{
			damagerPtr = reinterpret_cast<::ArmedGameObj*>(damager->ArmedGameObjPointer.ToPointer());
		}

		::DAEventManager::Damage_Event(
			victimPtr,
			damagerPtr,
			damage,
			warhead,
			scale,
			static_cast<::DADamageType::Type>(type));
	}

	void DAEventManager::KillEvent(IDamageableGameObj^ victim, IArmedGameObj^ killer, float damage, unsigned int warhead, float scale, DADamageType type)
	{
		::DamageableGameObj* victimPtr;
		if (victim == nullptr || victim->DamageableGameObjPointer.ToPointer() == nullptr)
		{
			victimPtr = nullptr;
		}
		else
		{
			victimPtr = reinterpret_cast<::DamageableGameObj*>(victim->DamageableGameObjPointer.ToPointer());
		}

		::ArmedGameObj* killerPtr;
		if (killer == nullptr || killer->ArmedGameObjPointer.ToPointer() == nullptr)
		{
			killerPtr = nullptr;
		}
		else
		{
			killerPtr = reinterpret_cast<::ArmedGameObj*>(killer->ArmedGameObjPointer.ToPointer());
		}

		::DAEventManager::Kill_Event(
			victimPtr,
			killerPtr,
			damage,
			warhead,
			scale,
			static_cast<::DADamageType::Type>(type));
	}

	void DAEventManager::RegisterEvent(IDAEventClass^ base, DAEventType type, int priority)
	{
		if (base == nullptr || base->DAEventClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}

		::DAEventManager::Register_Event(
			reinterpret_cast<::DAEventClass *>(base->DAEventClassPointer.ToPointer()),
			static_cast<::DAEvent::Type>(type),
			priority);
	}

	void DAEventManager::RegisterEvent(IRenSharpEventClass^ base, DAEventType type, int priority)
	{
		if (base == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}

		if (!base->IsAttached)
		{
			base->AttachToUnmanagedObject();
			base->RegisterManagedObject();
		}

		::DAEventManager::Register_Event(
			reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer()),
			static_cast<::DAEvent::Type>(type),
			priority);
	}

	void DAEventManager::UnregisterEvent(IDAEventClass^ base, DAEventType type)
	{
		if (base == nullptr || base->DAEventClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}

		::DAEventManager::Unregister_Event(
			reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer()),
			static_cast<::DAEvent::Type>(type));
	}

	void DAEventManager::UnregisterEvent(IRenSharpEventClass^ base, DAEventType type)
	{
		if (base == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}

		if (!base->IsAttached)
		{
			base->AttachToUnmanagedObject();
			base->RegisterManagedObject();
		}

		::DAEventManager::Unregister_Event(
			reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer()),
			static_cast<::DAEvent::Type>(type));
	}

	void DAEventManager::ClearEvents(IDAEventClass^ base)
	{
		if (base == nullptr || base->DAEventClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}

		::DAEventManager::Clear_Events(
			reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer()));
	}

	void DAEventManager::ClearEvents(IRenSharpEventClass^ base)
	{
		if (base == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}
		
		if (!base->IsAttached)
		{
			base->AttachToUnmanagedObject();
			base->RegisterManagedObject();
		}

		::DAEventManager::Clear_Events(
			reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer()));
	}

	void DAEventManager::RegisterObjectEvent(IDAEventClass^ base, DAObjectEventType type, DAObjectEventObjectType objectType, int priority)
	{
		if (base == nullptr || base->DAEventClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}

		::DAEventManager::Register_Object_Event(
			reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer()),
			static_cast<::DAObjectEvent::Type>(type),
			static_cast<::DAObjectEvent::ObjectType>(objectType),
			priority);
	}

	void DAEventManager::RegisterObjectEvent(IRenSharpEventClass^ base, DAObjectEventType type, DAObjectEventObjectType objectType, int priority)
	{
		if (base == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}
		
		if (!base->IsAttached)
		{
			base->AttachToUnmanagedObject();
			base->RegisterManagedObject();
		}

		::DAEventManager::Register_Object_Event(
			reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer()),
			static_cast<::DAObjectEvent::Type>(type),
			static_cast<::DAObjectEvent::ObjectType>(objectType),
			priority);
	}

	void DAEventManager::UnregisterObjectEvent(IDAEventClass^ base, DAObjectEventType type)
	{
		if (base == nullptr || base->DAEventClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}

		::DAEventManager::Unregister_Object_Event(
			reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer()),
			static_cast<::DAObjectEvent::Type>(type));
	}

	void DAEventManager::UnregisterObjectEvent(IRenSharpEventClass^ base, DAObjectEventType type)
	{
		if (base == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}
		
		if (!base->IsAttached)
		{
			base->AttachToUnmanagedObject();
			base->RegisterManagedObject();
		}

		::DAEventManager::Unregister_Object_Event(
			reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer()),
			static_cast<::DAObjectEvent::Type>(type));
	}

	void DAEventManager::ClearObjectEvents(IDAEventClass^ base)
	{
		if (base == nullptr || base->DAEventClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}

		::DAEventManager::Clear_Object_Events(
			reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer()));
	}

	void DAEventManager::ClearObjectEvents(IRenSharpEventClass^ base)
	{
		if (base == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}
		
		if (!base->IsAttached)
		{
			base->AttachToUnmanagedObject();
			base->RegisterManagedObject();
		}

		::DAEventManager::Clear_Object_Events(
			reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer()));
	}

	void DAEventManager::StartTimer(IDAEventClass^ base, int number, float duration, bool repeat, unsigned int data)
	{
		if (base == nullptr || base->DAEventClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}

		if (base->IsManagedEventClass)
		{
			StartTimer(base->AsManagedEventClass(), number, TimeSpan::FromSeconds(duration), repeat, data);
		}
		else
		{
			::DAEventManager::Start_Timer(
				reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer()),
				number,
				duration,
				repeat,
				data);
		}
	}

	void DAEventManager::StartTimer(IRenSharpEventClass^ base, int number, TimeSpan duration, bool repeat, Object ^data)
	{
		if (base == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}
		
		if (!base->IsAttached)
		{
			base->AttachToUnmanagedObject();
			base->RegisterManagedObject();
		}

		base->StartTimer(number, duration, repeat, data);
	}

	void DAEventManager::StopTimer(IDAEventClass^ base, int number, unsigned int data)
	{
		if (base == nullptr || base->DAEventClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}

		if (base->IsManagedEventClass)
		{
			StopTimer(base->AsManagedEventClass(), number, data);
		}
		else
		{
			::DAEventManager::Stop_Timer(
				reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer()),
				number,
				data);
		}
	}

	void DAEventManager::StopTimer(IRenSharpEventClass^ base, int number, Object^ data)
	{
		if (base == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}
		
		if (!base->IsAttached)
		{
			base->AttachToUnmanagedObject();
			base->RegisterManagedObject();
		}

		if (data == nullptr)
		{
			::DAEventManager::Stop_Timer(
				reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer()),
				number,
				0);
		}
		else if (UInt32::typeid->Equals(data->GetType()))
		{
			::DAEventManager::Stop_Timer(
				reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer()),
				number,
				safe_cast<UInt32>(data));
		}

		base->StopTimer(number, data);
	}

	bool DAEventManager::IsTimer(IDAEventClass^ base, int number, unsigned int data)
	{
		if (base == nullptr || base->DAEventClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}

		if (base->IsManagedEventClass)
		{
			return IsTimer(base->AsManagedEventClass(), number, data);
		}
		else
		{
			return ::DAEventManager::Is_Timer(
				reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer()),
				number,
				data);
		}
	}

	bool DAEventManager::IsTimer(IRenSharpEventClass^ base, int number, Object^ data)
	{
		if (base == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}
		
		if (!base->IsAttached)
		{
			base->AttachToUnmanagedObject();
			base->RegisterManagedObject();
		}

		if (data == nullptr)
		{
			if (::DAEventManager::Is_Timer(
				reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer()),
				number,
				0))
			{
				return true;
			}
		}
		else if (UInt32::typeid->Equals(data->GetType()))
		{
			if (::DAEventManager::Is_Timer(
				reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer()),
				number,
				safe_cast<UInt32>(data)))
			{
				return true;
			}
		}

		return base->IsTimer(number, data);
	}

	void DAEventManager::ClearTimers(IDAEventClass^ base)
	{
		if (base == nullptr || base->DAEventClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}

		if (base->IsManagedEventClass)
		{
			ClearTimers(base->AsManagedEventClass());
		}
		else
		{
			::DAEventManager::Clear_Timers(
				reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer()));
		}
	}

	void DAEventManager::ClearTimers(IRenSharpEventClass^ base)
	{
		if (base == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}
		
		if (!base->IsAttached)
		{
			base->AttachToUnmanagedObject();
			base->RegisterManagedObject();
		}

		::DAEventManager::Clear_Timers(
			reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer()));

		base->ClearTimers();
	}

	void DAEventManager::RegisterManagedEventClass(IRenSharpEventClass^ eventClass)
	{
		if (eventClass == nullptr)
		{
			throw gcnew ArgumentNullException("eventClass");
		}
		else if (!eventClass->IsAttached)
		{
			throw gcnew ArgumentException("Event class is not attached");
		}
		else if (Imports::IsShuttingDown())
		{
			throw gcnew NotSupportedException("Engine is shutting down");
		}

		managedEventClasses->Add(eventClass->DAEventClassPointer, eventClass);
	}

	void DAEventManager::UnregisterManagedEventClass(IRenSharpEventClass^ eventClass)
	{
		if (eventClass == nullptr)
		{
			throw gcnew ArgumentNullException("eventClass");
		}

		managedEventClasses->Remove(eventClass->DAEventClassPointer);
	}

	DAEventClass::DAEventClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool DAEventClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IRenSharpEventClass^ otherThis1 = dynamic_cast<IRenSharpEventClass^>(other);
		if (otherThis1 != nullptr && DAEventClassPointer.Equals(otherThis1->DAEventClassPointer))
		{
			return true;
		}

		IDAEventClass^ otherThis2 = dynamic_cast<IDAEventClass^>(other);
		if (otherThis2 == nullptr)
		{
			return nullptr;
		}

		return DAEventClassPointer.Equals(otherThis2->DAEventClassPointer);
	}

	void DAEventClass::RegisterEvent(DAEventType type, int priority)
	{
		InternalDAEventClassPointer->Register_Event(
			static_cast<DAEvent::Type>(type),
			priority);
	}

	void DAEventClass::RegisterEvent(DAEventType type)
	{
		InternalDAEventClassPointer->Register_Event(
			static_cast<DAEvent::Type>(type));
	}

	void DAEventClass::UnregisterEvent(DAEventType type)
	{
		InternalDAEventClassPointer->Unregister_Event(
			static_cast<DAEvent::Type>(type));
	}

	void DAEventClass::ClearEvents()
	{
		InternalDAEventClassPointer->Clear_Events();
	}

	void DAEventClass::RegisterObjectEvent(DAObjectEventType type, DAObjectEventObjectType objectType, int priority)
	{
		InternalDAEventClassPointer->Register_Object_Event(
			static_cast<DAObjectEvent::Type>(type),
			static_cast<DAObjectEvent::ObjectType>(objectType),
			priority);
	}

	void DAEventClass::RegisterObjectEvent(DAObjectEventType type, DAObjectEventObjectType objectType)
	{
		InternalDAEventClassPointer->Register_Object_Event(
			static_cast<DAObjectEvent::Type>(type),
			static_cast<DAObjectEvent::ObjectType>(objectType));
	}

	void DAEventClass::UnregisterObjectEvent(DAObjectEventType type)
	{
		InternalDAEventClassPointer->Unregister_Object_Event(
			static_cast<DAObjectEvent::Type>(type));
	}

	void DAEventClass::ClearObjectEvents()
	{
		InternalDAEventClassPointer->Clear_Object_Events();
	}

	void DAEventClass::StartTimer(int number, float duration, bool repeat, unsigned int data)
	{
		if (IsManagedEventClass)
		{
			AsManagedEventClass()->StartTimer(number, TimeSpan::FromSeconds(duration), repeat, data);
		}
		else
		{
			InternalDAEventClassPointer->Start_Timer(number, duration, repeat, data);
		}
	}

	void DAEventClass::StartTimer(int number, float duration, bool repeat)
	{
		if (IsManagedEventClass)
		{
			AsManagedEventClass()->StartTimer(number, TimeSpan::FromSeconds(duration), repeat);
		}
		else
		{
			InternalDAEventClassPointer->Start_Timer(number, duration, repeat);
		}
	}

	void DAEventClass::StartTimer(int number, float duration)
	{
		if (IsManagedEventClass)
		{
			AsManagedEventClass()->StartTimer(number, TimeSpan::FromSeconds(duration));
		}
		else
		{
			InternalDAEventClassPointer->Start_Timer(number, duration);
		}
	}

	void DAEventClass::StopTimer(int number, unsigned int data)
	{
		if (IsManagedEventClass)
		{
			AsManagedEventClass()->StopTimer(number, data);
		}
		else
		{
			InternalDAEventClassPointer->Stop_Timer(number, data);
		}
	}

	void DAEventClass::StopTimer(int number)
	{
		if (IsManagedEventClass)
		{
			AsManagedEventClass()->StopTimer(number);
		}
		else
		{
			InternalDAEventClassPointer->Stop_Timer(number);
		}
	}

	bool DAEventClass::IsTimer(int number, unsigned int data)
	{
		if (IsManagedEventClass)
		{
			return AsManagedEventClass()->IsTimer(number, data);
		}
		else
		{
			return InternalDAEventClassPointer->Is_Timer(number, data);
		}
	}

	bool DAEventClass::IsTimer(int number)
	{
		if (IsManagedEventClass)
		{
			return AsManagedEventClass()->IsTimer(number);
		}
		else
		{
			return InternalDAEventClassPointer->Is_Timer(number);
		}
	}

	void DAEventClass::ClearTimers()
	{
		if (IsManagedEventClass)
		{
			AsManagedEventClass()->ClearTimers();
		}
		else
		{
			InternalDAEventClassPointer->Clear_Timers();
		}
	}

	void DAEventClass::UnregisterChatCommand(String^ trigger)
	{
		if (trigger == nullptr)
		{
			throw gcnew ArgumentNullException("trigger");
		}

		if (IsManagedEventClass)
		{
			AsManagedEventClass()->UnregisterChatCommand(trigger);
		}
		else
		{
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
	}

	void DAEventClass::ClearChatCommands()
	{
		if (IsManagedEventClass)
		{
			AsManagedEventClass()->ClearChatCommands();
		}
		else
		{
			InternalDAEventClassPointer->Clear_Chat_Commands();
		}
	}

	void DAEventClass::UnregisterKeyHook(String^ trigger)
	{
		if (trigger == nullptr)
		{
			throw gcnew ArgumentNullException("trigger");
		}

		if (IsManagedEventClass)
		{
			AsManagedEventClass()->UnregisterKeyHook(trigger);
		}
		else
		{
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
	}

	void DAEventClass::ClearKeyHooks()
	{
		if (IsManagedEventClass)
		{
			AsManagedEventClass()->ClearKeyHooks();
		}
		else
		{
			InternalDAEventClassPointer->Clear_Key_Hooks();
		}
	}

	void DAEventClass::SettingsLoadedEvent()
	{
		InternalDAEventClassPointer->Settings_Loaded_Event();
	}

	bool DAEventClass::ChatEvent(IcPlayer^ player, TextMessageEnum type, String^ message, int receiverID)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		if (message == nullptr)
		{
			return InternalDAEventClassPointer->Chat_Event(
				playerPtr,
				static_cast<::TextMessageEnum>(type),
				nullptr,
				receiverID);
		}
		else
		{
			IntPtr messageHandle = Marshal::StringToHGlobalUni(message);
			try
			{
				return InternalDAEventClassPointer->Chat_Event(
					playerPtr,
					static_cast<::TextMessageEnum>(type),
					reinterpret_cast<wchar_t *>(messageHandle.ToPointer()),
					receiverID);
			}
			finally
			{
				Marshal::FreeHGlobal(messageHandle);
			}
		}
	}

	bool DAEventClass::ChatCommandEvent(IcPlayer^ player, TextMessageEnum type, String^ command, IDATokenClass^ text, int receiverID)
	{
		if (command == nullptr)
		{
			throw gcnew ArgumentNullException("command");
		}
		else if (text == nullptr || text->DATokenClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("text");
		}

		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		IntPtr commandHandle = Marshal::StringToHGlobalAnsi(command);
		try
		{
			::StringClass tmp(reinterpret_cast<char *>(commandHandle.ToPointer()));

			return InternalDAEventClassPointer->Chat_Command_Event(
				playerPtr,
				static_cast<::TextMessageEnum>(type),
				tmp,
				*reinterpret_cast<::DATokenClass *>(text->DATokenClassPointer.ToPointer()),
				receiverID);
		}
		finally
		{
			Marshal::FreeHGlobal(commandHandle);
		}
	}

	bool DAEventClass::KeyHookEvent(IcPlayer^ player, String^ key)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}

		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		IntPtr keyHandle = Marshal::StringToHGlobalAnsi(key);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(keyHandle.ToPointer()));

			return InternalDAEventClassPointer->Key_Hook_Event(
				playerPtr,
				tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(keyHandle);
		}
	}

	bool DAEventClass::HostChatEvent(int id, TextMessageEnum type, String^ message)
	{
		if (message == nullptr)
		{
			return InternalDAEventClassPointer->Host_Chat_Event(
				id,
				static_cast<::TextMessageEnum>(type),
				nullptr);
		}
		else
		{
			IntPtr messageHandle = Marshal::StringToHGlobalAnsi(message);
			try
			{
				return InternalDAEventClassPointer->Host_Chat_Event(
					id,
					static_cast<::TextMessageEnum>(type),
					reinterpret_cast<char *>(messageHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(messageHandle);
			}
		}
	}

	bool DAEventClass::RadioEvent(IcPlayer^ player, int playerType, int announcementID, int iconID, AnnouncementEnum announcementType)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		return InternalDAEventClassPointer->Radio_Event(
			playerPtr,
			playerType,
			announcementID,
			iconID,
			static_cast<::AnnouncementEnum>(announcementType));
	}

	ConnectionAcceptanceFilterStatus DAEventClass::ConnectionRequestEvent(IConnectionRequest^ request, String^% refusalMessage)
	{
		if (request == nullptr || request->ConnectionRequestPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("request");
		}

		::WideStringClass tmp;

		if (refusalMessage != nullptr)
		{
			IntPtr refusalMessageHandle = Marshal::StringToHGlobalUni(refusalMessage);
			try
			{
				tmp = reinterpret_cast<wchar_t *>(refusalMessageHandle.ToPointer());
			}
			finally
			{
				Marshal::FreeHGlobal(refusalMessageHandle);
			}
		}

		auto result = InternalDAEventClassPointer->Connection_Request_Event(
			*reinterpret_cast<::ConnectionRequest*>(request->ConnectionRequestPointer.ToPointer()),
			tmp);

		refusalMessage = gcnew String(tmp.Peek_Buffer());

		return static_cast<ConnectionAcceptanceFilterStatus>(result);
	}

	void DAEventClass::PlayerPreJoinEvent(IConnectionRequest^ request)
	{
		if (request == nullptr || request->ConnectionRequestPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("request");
		}

		InternalDAEventClassPointer->Player_Pre_Join_Event(
			*reinterpret_cast<::ConnectionRequest*>(request->ConnectionRequestPointer.ToPointer()));
	}

	void DAEventClass::PlayerJoinEvent(IcPlayer^ player)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		InternalDAEventClassPointer->Player_Join_Event(playerPtr);
	}

	void DAEventClass::PlayerLeaveEvent(IcPlayer^ player)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		InternalDAEventClassPointer->Player_Leave_Event(playerPtr);
	}

	void DAEventClass::PlayerLoadedEvent(IcPlayer^ player)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		InternalDAEventClassPointer->Player_Loaded_Event(playerPtr);
	}

	void DAEventClass::NameChangeEvent(IcPlayer^ player)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		InternalDAEventClassPointer->Name_Change_Event(playerPtr);
	}

	void DAEventClass::LevelLoadedEvent()
	{
		InternalDAEventClassPointer->Level_Loaded_Event();
	}

	void DAEventClass::RemixEvent()
	{
		InternalDAEventClassPointer->Remix_Event();
	}

	void DAEventClass::RebalanceEvent()
	{
		InternalDAEventClassPointer->Rebalance_Event();
	}

	void DAEventClass::SwapEvent()
	{
		InternalDAEventClassPointer->Swap_Event();
	}

	void DAEventClass::GameOverEvent()
	{
		InternalDAEventClassPointer->Game_Over_Event();
	}

	void DAEventClass::ConsoleOutputEvent(String^ output)
	{
		if (output == nullptr)
		{
			InternalDAEventClassPointer->Console_Output_Event(nullptr);
		}
		else
		{
			IntPtr outputHandle = Marshal::StringToHGlobalAnsi(output);
			try
			{
				InternalDAEventClassPointer->Console_Output_Event(
					reinterpret_cast<char *>(outputHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(outputHandle);
			}
		}
	}

	void DAEventClass::RenLogEvent(String^ output)
	{
		if (output == nullptr)
		{
			InternalDAEventClassPointer->Console_Output_Event(nullptr);
		}
		else
		{
			IntPtr outputHandle = Marshal::StringToHGlobalAnsi(output);
			try
			{
				InternalDAEventClassPointer->Ren_Log_Event(
					reinterpret_cast<char*>(outputHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(outputHandle);
			}
		}
	}

	void DAEventClass::DALogEvent(String^ header, String^ output)
	{
		if (header == nullptr)
		{
			if (output == nullptr)
			{
				InternalDAEventClassPointer->DA_Log_Event(nullptr, nullptr);
			}
			else
			{
				IntPtr outputHandle = Marshal::StringToHGlobalAnsi(output);
				try
				{
					InternalDAEventClassPointer->DA_Log_Event(
						nullptr,
						reinterpret_cast<char*>(outputHandle.ToPointer()));
				}
				finally
				{
					Marshal::FreeHGlobal(outputHandle);
				}
			}
		}
		else
		{
			IntPtr headerHandle = Marshal::StringToHGlobalAnsi(header);
			try
			{
				if (output == nullptr)
				{
					InternalDAEventClassPointer->DA_Log_Event(
						reinterpret_cast<char *>(headerHandle.ToPointer()),
						nullptr);
				}
				else
				{
					IntPtr outputHandle = Marshal::StringToHGlobalAnsi(output);
					try
					{
						InternalDAEventClassPointer->DA_Log_Event(
							reinterpret_cast<char*>(headerHandle.ToPointer()),
							reinterpret_cast<char*>(outputHandle.ToPointer()));
					}
					finally
					{
						Marshal::FreeHGlobal(outputHandle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(headerHandle);
			}
		}
	}

	int DAEventClass::CharacterPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, ISoldierGameObjDef^ item)
	{
		::BaseControllerClass* baseControllerPtr;
		if (baseController == nullptr || baseController->BaseControllerClassPointer.ToPointer() == nullptr)
		{
			baseControllerPtr = nullptr;
		}
		else
		{
			baseControllerPtr = reinterpret_cast<::BaseControllerClass*>(baseController->BaseControllerClassPointer.ToPointer());
		}

		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		float tmpCost = cost;

		::SoldierGameObjDef* itemPtr;
		if (item == nullptr || item->SoldierGameObjDefPointer.ToPointer() == nullptr)
		{
			itemPtr = nullptr;
		}
		else
		{
			itemPtr = reinterpret_cast<::SoldierGameObjDef*>(item->SoldierGameObjDefPointer.ToPointer());
		}

		auto result = InternalDAEventClassPointer->Character_Purchase_Request_Event(
			baseControllerPtr,
			playerPtr,
			tmpCost,
			itemPtr);

		cost = tmpCost;

		return result;
	}

	int DAEventClass::VehiclePurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, IVehicleGameObjDef^ item)
	{
		::BaseControllerClass* baseControllerPtr;
		if (baseController == nullptr || baseController->BaseControllerClassPointer.ToPointer() == nullptr)
		{
			baseControllerPtr = nullptr;
		}
		else
		{
			baseControllerPtr = reinterpret_cast<::BaseControllerClass*>(baseController->BaseControllerClassPointer.ToPointer());
		}

		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		float tmpCost = cost;

		::VehicleGameObjDef* itemPtr;
		if (item == nullptr || item->VehicleGameObjDefPointer.ToPointer() == nullptr)
		{
			itemPtr = nullptr;
		}
		else
		{
			itemPtr = reinterpret_cast<::VehicleGameObjDef*>(item->VehicleGameObjDefPointer.ToPointer());
		}

		auto result = InternalDAEventClassPointer->Vehicle_Purchase_Request_Event(
			baseControllerPtr,
			playerPtr,
			tmpCost,
			itemPtr);

		cost = tmpCost;

		return result;
	}

	int DAEventClass::PowerUpPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, IPowerUpGameObjDef^ item)
	{
		::BaseControllerClass* baseControllerPtr;
		if (baseController == nullptr || baseController->BaseControllerClassPointer.ToPointer() == nullptr)
		{
			baseControllerPtr = nullptr;
		}
		else
		{
			baseControllerPtr = reinterpret_cast<::BaseControllerClass*>(baseController->BaseControllerClassPointer.ToPointer());
		}

		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		float tmpCost = cost;

		::PowerUpGameObjDef* itemPtr;
		if (item == nullptr || item->PowerUpGameObjDefPointer.ToPointer() == nullptr)
		{
			itemPtr = nullptr;
		}
		else
		{
			itemPtr = reinterpret_cast<::PowerUpGameObjDef*>(item->PowerUpGameObjDefPointer.ToPointer());
		}

		auto result = InternalDAEventClassPointer->PowerUp_Purchase_Request_Event(
			baseControllerPtr,
			playerPtr,
			tmpCost,
			itemPtr);

		cost = tmpCost;

		return result;
	}

	int DAEventClass::CustomPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, unsigned int id)
	{
		::BaseControllerClass* baseControllerPtr;
		if (baseController == nullptr || baseController->BaseControllerClassPointer.ToPointer() == nullptr)
		{
			baseControllerPtr = nullptr;
		}
		else
		{
			baseControllerPtr = reinterpret_cast<::BaseControllerClass*>(baseController->BaseControllerClassPointer.ToPointer());
		}

		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		float tmpCost = cost;

		auto result = InternalDAEventClassPointer->Custom_Purchase_Request_Event(
			baseControllerPtr,
			playerPtr,
			tmpCost,
			id);

		cost = tmpCost;

		return result;
	}

	void DAEventClass::CharacterPurchaseEvent(IcPlayer^ player, float cost, ISoldierGameObjDef^ item)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		::SoldierGameObjDef* itemPtr;
		if (item == nullptr || item->SoldierGameObjDefPointer.ToPointer() == nullptr)
		{
			itemPtr = nullptr;
		}
		else
		{
			itemPtr = reinterpret_cast<::SoldierGameObjDef*>(item->SoldierGameObjDefPointer.ToPointer());
		}

		InternalDAEventClassPointer->Character_Purchase_Event(
			playerPtr,
			cost,
			itemPtr);
	}

	void DAEventClass::VehiclePurchaseEvent(IcPlayer^ player, float cost, IVehicleGameObjDef^ item)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		::VehicleGameObjDef* itemPtr;
		if (item == nullptr || item->VehicleGameObjDefPointer.ToPointer() == nullptr)
		{
			itemPtr = nullptr;
		}
		else
		{
			itemPtr = reinterpret_cast<::VehicleGameObjDef*>(item->VehicleGameObjDefPointer.ToPointer());
		}

		InternalDAEventClassPointer->Vehicle_Purchase_Event(
			playerPtr,
			cost,
			itemPtr);
	}

	void DAEventClass::PowerUpPurchaseEvent(IcPlayer^ player, float cost, IPowerUpGameObjDef^ item)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		::PowerUpGameObjDef* itemPtr;
		if (item == nullptr || item->PowerUpGameObjDefPointer.ToPointer() == nullptr)
		{
			itemPtr = nullptr;
		}
		else
		{
			itemPtr = reinterpret_cast<::PowerUpGameObjDef*>(item->PowerUpGameObjDefPointer.ToPointer());
		}

		InternalDAEventClassPointer->PowerUp_Purchase_Event(
			playerPtr,
			cost,
			itemPtr);
	}

	void DAEventClass::CustomPurchaseEvent(IcPlayer^ player, float cost, unsigned int id)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		InternalDAEventClassPointer->Custom_Purchase_Event(
			playerPtr,
			cost,
			id);
	}

	bool DAEventClass::RefillEvent(IcPlayer^ player)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		return InternalDAEventClassPointer->Refill_Event(playerPtr);
	}

	bool DAEventClass::SuicideEvent(IcPlayer^ player)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		return InternalDAEventClassPointer->Suicide_Event(playerPtr);
	}

	bool DAEventClass::TeamChangeRequestEvent(IcPlayer^ player)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		return InternalDAEventClassPointer->Team_Change_Request_Event(playerPtr);
	}

	void DAEventClass::TeamChangeEvent(IcPlayer^ player)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		InternalDAEventClassPointer->Team_Change_Event(playerPtr);
	}

	bool DAEventClass::VehicleEntryRequestEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int% seat)
	{
		::VehicleGameObj* vehiclePtr;
		if (vehicle == nullptr || vehicle->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			vehiclePtr = nullptr;
		}
		else
		{
			vehiclePtr = reinterpret_cast<::VehicleGameObj*>(vehicle->VehicleGameObjPointer.ToPointer());
		}

		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		int tmpSeat = seat;

		auto result = InternalDAEventClassPointer->Vehicle_Entry_Request_Event(
			vehiclePtr,
			playerPtr,
			tmpSeat);

		seat = tmpSeat;

		return result;
	}

	void DAEventClass::VehicleEnterEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int seat)
	{
		::VehicleGameObj* vehiclePtr;
		if (vehicle == nullptr || vehicle->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			vehiclePtr = nullptr;
		}
		else
		{
			vehiclePtr = reinterpret_cast<::VehicleGameObj*>(vehicle->VehicleGameObjPointer.ToPointer());
		}

		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		InternalDAEventClassPointer->Vehicle_Enter_Event(
			vehiclePtr,
			playerPtr,
			seat);
	}

	void DAEventClass::VehicleExitEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int seat)
	{
		::VehicleGameObj* vehiclePtr;
		if (vehicle == nullptr || vehicle->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			vehiclePtr = nullptr;
		}
		else
		{
			vehiclePtr = reinterpret_cast<::VehicleGameObj*>(vehicle->VehicleGameObjPointer.ToPointer());
		}

		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		InternalDAEventClassPointer->Vehicle_Exit_Event(
			vehiclePtr,
			playerPtr,
			seat);
	}

	bool DAEventClass::PowerUpGrantRequestEvent(IcPlayer^ player, IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		::PowerUpGameObjDef* powerUpPtr;
		if (powerUp == nullptr || powerUp->PowerUpGameObjDefPointer.ToPointer() == nullptr)
		{
			powerUpPtr = nullptr;
		}
		else
		{
			powerUpPtr = reinterpret_cast<::PowerUpGameObjDef*>(powerUp->PowerUpGameObjDefPointer.ToPointer());
		}

		::PowerUpGameObj* powerUpObjPtr;
		if (powerUpObj == nullptr || powerUpObj->PowerUpGameObjPointer.ToPointer() == nullptr)
		{
			powerUpObjPtr = nullptr;
		}
		else
		{
			powerUpObjPtr = reinterpret_cast<::PowerUpGameObj*>(powerUpObj->PowerUpGameObjPointer.ToPointer());
		}

		return InternalDAEventClassPointer->PowerUp_Grant_Request_Event(
			playerPtr,
			powerUpPtr,
			powerUpObjPtr);
	}

	void DAEventClass::PowerUpGrantEvent(IcPlayer^ player, IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		::PowerUpGameObjDef* powerUpPtr;
		if (powerUp == nullptr || powerUp->PowerUpGameObjDefPointer.ToPointer() == nullptr)
		{
			powerUpPtr = nullptr;
		}
		else
		{
			powerUpPtr = reinterpret_cast<::PowerUpGameObjDef*>(powerUp->PowerUpGameObjDefPointer.ToPointer());
		}

		::PowerUpGameObj* powerUpObjPtr;
		if (powerUpObj == nullptr || powerUpObj->PowerUpGameObjPointer.ToPointer() == nullptr)
		{
			powerUpObjPtr = nullptr;
		}
		else
		{
			powerUpObjPtr = reinterpret_cast<::PowerUpGameObj*>(powerUpObj->PowerUpGameObjPointer.ToPointer());
		}

		InternalDAEventClassPointer->PowerUp_Grant_Event(
			playerPtr,
			powerUpPtr,
			powerUpObjPtr);
	}

	bool DAEventClass::AddWeaponRequestEvent(IcPlayer^ player, IWeaponDefinitionClass^ weapon)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		::WeaponDefinitionClass* weaponPtr;
		if (weapon == nullptr || weapon->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			weaponPtr = nullptr;
		}
		else
		{
			weaponPtr = reinterpret_cast<::WeaponDefinitionClass*>(weapon->WeaponDefinitionClassPointer.ToPointer());
		}

		return InternalDAEventClassPointer->Add_Weapon_Request_Event(playerPtr, weaponPtr);
	}

	void DAEventClass::AddWeaponEvent(IcPlayer^ player, IWeaponClass^ weapon)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		::WeaponClass* weaponPtr;
		if (weapon == nullptr || weapon->WeaponClassPointer.ToPointer() == nullptr)
		{
			weaponPtr = nullptr;
		}
		else
		{
			weaponPtr = reinterpret_cast<::WeaponClass*>(weapon->WeaponClassPointer.ToPointer());
		}

		InternalDAEventClassPointer->Add_Weapon_Event(playerPtr, weaponPtr);
	}

	void DAEventClass::RemoveWeaponEvent(IcPlayer^ player, IWeaponClass^ weapon)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		::WeaponClass* weaponPtr;
		if (weapon == nullptr || weapon->WeaponClassPointer.ToPointer() == nullptr)
		{
			weaponPtr = nullptr;
		}
		else
		{
			weaponPtr = reinterpret_cast<::WeaponClass*>(weapon->WeaponClassPointer.ToPointer());
		}

		InternalDAEventClassPointer->Remove_Weapon_Event(playerPtr, weaponPtr);
	}

	void DAEventClass::ClearWeaponsEvent(IcPlayer^ player)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		InternalDAEventClassPointer->Clear_Weapons_Event(playerPtr);
	}

	void DAEventClass::BeaconDeployEvent(IBeaconGameObj^ beacon)
	{
		::BeaconGameObj* beaconPtr;
		if (beacon == nullptr || beacon->BeaconGameObjPointer.ToPointer() == nullptr)
		{
			beaconPtr = nullptr;
		}
		else
		{
			beaconPtr = reinterpret_cast<::BeaconGameObj*>(beacon->BeaconGameObjPointer.ToPointer());
		}

		InternalDAEventClassPointer->Beacon_Deploy_Event(beaconPtr);
	}

	void DAEventClass::BeaconDetonateEvent(IBeaconGameObj^ beacon)
	{
		::BeaconGameObj* beaconPtr;
		if (beacon == nullptr || beacon->BeaconGameObjPointer.ToPointer() == nullptr)
		{
			beaconPtr = nullptr;
		}
		else
		{
			beaconPtr = reinterpret_cast<::BeaconGameObj*>(beacon->BeaconGameObjPointer.ToPointer());
		}

		InternalDAEventClassPointer->Beacon_Detonate_Event(beaconPtr);
	}

	bool DAEventClass::C4DetonateRequestEvent(IC4GameObj^ c4, ISmartGameObj^ triggerer)
	{
		::C4GameObj* c4Ptr;
		if (c4 == nullptr || c4->C4GameObjPointer.ToPointer() == nullptr)
		{
			c4Ptr = nullptr;
		}
		else
		{
			c4Ptr = reinterpret_cast<::C4GameObj*>(c4->C4GameObjPointer.ToPointer());
		}

		::SmartGameObj* triggererPtr;
		if (triggerer == nullptr || triggerer->SmartGameObjPointer.ToPointer() == nullptr)
		{
			triggererPtr = nullptr;
		}
		else
		{
			triggererPtr = reinterpret_cast<::SmartGameObj*>(triggerer->SmartGameObjPointer.ToPointer());
		}

		return InternalDAEventClassPointer->C4_Detonate_Request_Event(c4Ptr, triggererPtr);
	}

	void DAEventClass::C4DetonateEvent(IC4GameObj^ c4)
	{
		::C4GameObj* c4Ptr;
		if (c4 == nullptr || c4->C4GameObjPointer.ToPointer() == nullptr)
		{
			c4Ptr = nullptr;
		}
		else
		{
			c4Ptr = reinterpret_cast<::C4GameObj*>(c4->C4GameObjPointer.ToPointer());
		}

		InternalDAEventClassPointer->C4_Detonate_Event(c4Ptr);
	}

	void DAEventClass::ChangeCharacterEvent(IcPlayer^ player, ISoldierGameObjDef^ soldier)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		::SoldierGameObjDef* soldierPtr;
		if (soldier == nullptr || soldier->SoldierGameObjDefPointer.ToPointer() == nullptr)
		{
			soldierPtr = nullptr;
		}
		else
		{
			soldierPtr = reinterpret_cast<::SoldierGameObjDef*>(soldier->SoldierGameObjDefPointer.ToPointer());
		}

		InternalDAEventClassPointer->Change_Character_Event(playerPtr, soldierPtr);
	}

	bool DAEventClass::VehicleFlipEvent(IVehicleGameObj^ vehicle)
	{
		::VehicleGameObj* vehiclePtr;
		if (vehicle == nullptr || vehicle->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			vehiclePtr = nullptr;
		}
		else
		{
			vehiclePtr = reinterpret_cast<::VehicleGameObj*>(vehicle->VehicleGameObjPointer.ToPointer());
		}

		return InternalDAEventClassPointer->Vehicle_Flip_Event(vehiclePtr);
	}

	bool DAEventClass::RequestVehicleEvent(IVehicleFactoryGameObj^ factory, IVehicleGameObjDef^ vehicle, IcPlayer^ player, float delay)
	{
		::VehicleFactoryGameObj* factoryPtr;
		if (factory == nullptr || factory->VehicleFactoryGameObjPointer.ToPointer() == nullptr)
		{
			factoryPtr = nullptr;
		}
		else
		{
			factoryPtr = reinterpret_cast<::VehicleFactoryGameObj*>(factory->VehicleFactoryGameObjPointer.ToPointer());
		}

		::VehicleGameObjDef* vehiclePtr;
		if (vehicle == nullptr || vehicle->VehicleGameObjDefPointer.ToPointer() == nullptr)
		{
			vehiclePtr = nullptr;
		}
		else
		{
			vehiclePtr = reinterpret_cast<::VehicleGameObjDef*>(vehicle->VehicleGameObjDefPointer.ToPointer());
		}

		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		return InternalDAEventClassPointer->Request_Vehicle_Event(factoryPtr, vehiclePtr, playerPtr, delay);
	}

	void DAEventClass::Think()
	{
		InternalDAEventClassPointer->Think();
	}

	void DAEventClass::ObjectCreatedEvent(IScriptableGameObj^ obj)
	{
		::ScriptableGameObj* objPtr;
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			objPtr = nullptr;
		}
		else
		{
			objPtr = reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer());
		}

		InternalDAEventClassPointer->Object_Created_Event(objPtr);
	}

	bool DAEventClass::StockClientDamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float damage, uint warhead)
	{
		::DamageableGameObj* victimPtr;
		if (victim == nullptr || victim->DamageableGameObjPointer.ToPointer() == nullptr)
		{
			victimPtr = nullptr;
		}
		else
		{
			victimPtr = reinterpret_cast<::DamageableGameObj*>(victim->DamageableGameObjPointer.ToPointer());
		}

		::ArmedGameObj* damagerPtr;
		if (damager == nullptr || damager->ArmedGameObjPointer.ToPointer() == nullptr)
		{
			damagerPtr = nullptr;
		}
		else
		{
			damagerPtr = reinterpret_cast<::ArmedGameObj*>(damager->ArmedGameObjPointer.ToPointer());
		}

		return InternalDAEventClassPointer->Stock_Client_Damage_Request_Event(
			victimPtr,
			damagerPtr,
			damage,
			warhead);
	}

	bool DAEventClass::TTClientDamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, IAmmoDefinitionClass^ ammo, String^ bone)
	{
		::DamageableGameObj* victimPtr;
		if (victim == nullptr || victim->DamageableGameObjPointer.ToPointer() == nullptr)
		{
			victimPtr = nullptr;
		}
		else
		{
			victimPtr = reinterpret_cast<::DamageableGameObj*>(victim->DamageableGameObjPointer.ToPointer());
		}

		::ArmedGameObj* damagerPtr;
		if (damager == nullptr || damager->ArmedGameObjPointer.ToPointer() == nullptr)
		{
			damagerPtr = nullptr;
		}
		else
		{
			damagerPtr = reinterpret_cast<::ArmedGameObj*>(damager->ArmedGameObjPointer.ToPointer());
		}

		::AmmoDefinitionClass* ammoPtr;
		if (ammo == nullptr || ammo->AmmoDefinitionClassPointer.ToPointer() == nullptr)
		{
			ammoPtr = nullptr;
		}
		else
		{
			ammoPtr = reinterpret_cast<::AmmoDefinitionClass*>(ammo->AmmoDefinitionClassPointer.ToPointer());
		}

		if (bone == nullptr)
		{
			return InternalDAEventClassPointer->TT_Client_Damage_Request_Event(
				victimPtr,
				damagerPtr,
				ammoPtr,
				nullptr);
		}
		else
		{
			IntPtr boneHandle = Marshal::StringToHGlobalAnsi(bone);
			try
			{
				return InternalDAEventClassPointer->TT_Client_Damage_Request_Event(
					victimPtr,
					damagerPtr,
					ammoPtr,
					reinterpret_cast<char *>(boneHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(boneHandle);
			}
		}
	}

	bool DAEventClass::DamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float% damage, unsigned int% warhead, float scale, DADamageType type)
	{
		::DamageableGameObj* victimPtr;
		if (victim == nullptr || victim->DamageableGameObjPointer.ToPointer() == nullptr)
		{
			victimPtr = nullptr;
		}
		else
		{
			victimPtr = reinterpret_cast<::DamageableGameObj*>(victim->DamageableGameObjPointer.ToPointer());
		}

		::ArmedGameObj* damagerPtr;
		if (damager == nullptr || damager->ArmedGameObjPointer.ToPointer() == nullptr)
		{
			damagerPtr = nullptr;
		}
		else
		{
			damagerPtr = reinterpret_cast<::ArmedGameObj*>(damager->ArmedGameObjPointer.ToPointer());
		}

		float tmpDamage = damage;
		unsigned int tmpWarhead = warhead;

		auto result = InternalDAEventClassPointer->Damage_Request_Event(
			victimPtr,
			damagerPtr,
			tmpDamage,
			tmpWarhead,
			scale,
			static_cast<::DADamageType::Type>(type));

		damage = tmpDamage;
		warhead = tmpWarhead;

		return result;
	}

	void DAEventClass::DamageEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float damage, unsigned int warhead, float scale, DADamageType type)
	{
		::DamageableGameObj* victimPtr;
		if (victim == nullptr || victim->DamageableGameObjPointer.ToPointer() == nullptr)
		{
			victimPtr = nullptr;
		}
		else
		{
			victimPtr = reinterpret_cast<::DamageableGameObj*>(victim->DamageableGameObjPointer.ToPointer());
		}

		::ArmedGameObj* damagerPtr;
		if (damager == nullptr || damager->ArmedGameObjPointer.ToPointer() == nullptr)
		{
			damagerPtr = nullptr;
		}
		else
		{
			damagerPtr = reinterpret_cast<::ArmedGameObj*>(damager->ArmedGameObjPointer.ToPointer());
		}

		InternalDAEventClassPointer->Damage_Event(
			victimPtr,
			damagerPtr,
			damage,
			warhead,
			scale,
			static_cast<::DADamageType::Type>(type));
	}

	void DAEventClass::KillEvent(IDamageableGameObj^ victim, IArmedGameObj^ killer, float damage, unsigned int warhead, float scale, DADamageType type)
	{
		::DamageableGameObj* victimPtr;
		if (victim == nullptr || victim->DamageableGameObjPointer.ToPointer() == nullptr)
		{
			victimPtr = nullptr;
		}
		else
		{
			victimPtr = reinterpret_cast<::DamageableGameObj*>(victim->DamageableGameObjPointer.ToPointer());
		}

		::ArmedGameObj* killerPtr;
		if (killer == nullptr || killer->ArmedGameObjPointer.ToPointer() == nullptr)
		{
			killerPtr = nullptr;
		}
		else
		{
			killerPtr = reinterpret_cast<::ArmedGameObj*>(killer->ArmedGameObjPointer.ToPointer());
		}

		InternalDAEventClassPointer->Kill_Event(
			victimPtr,
			killerPtr,
			damage,
			warhead,
			scale,
			static_cast<::DADamageType::Type>(type));
	}

	void DAEventClass::CustomEvent(IScriptableGameObj^ obj, int type, int param, IScriptableGameObj^ sender)
	{
		::ScriptableGameObj* objPtr;
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			objPtr = nullptr;
		}
		else
		{
			objPtr = reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer());
		}

		::ScriptableGameObj* senderPtr;
		if (sender == nullptr || sender->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			senderPtr = nullptr;
		}
		else
		{
			senderPtr = reinterpret_cast<::ScriptableGameObj*>(sender->ScriptableGameObjPointer.ToPointer());
		}

		InternalDAEventClassPointer->Custom_Event(
			objPtr,
			type,
			param,
			senderPtr);
	}

	void DAEventClass::PokeEvent(IcPlayer^ player, IPhysicalGameObj^ obj)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		::PhysicalGameObj* objPtr;
		if (obj == nullptr || obj->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			objPtr = nullptr;
		}
		else
		{
			objPtr = reinterpret_cast<::PhysicalGameObj*>(obj->PhysicalGameObjPointer.ToPointer());
		}

		InternalDAEventClassPointer->Poke_Event(playerPtr, objPtr);
	}

	void DAEventClass::ZoneEnterEvent(IScriptZoneGameObj^ obj, IPhysicalGameObj^ enterer)
	{
		::ScriptZoneGameObj* objPtr;
		if (obj == nullptr || obj->ScriptZoneGameObjPointer.ToPointer() == nullptr)
		{
			objPtr = nullptr;
		}
		else
		{
			objPtr = reinterpret_cast<::ScriptZoneGameObj*>(obj->ScriptZoneGameObjPointer.ToPointer());
		}

		::PhysicalGameObj* entererPtr;
		if (enterer == nullptr || enterer->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			entererPtr = nullptr;
		}
		else
		{
			entererPtr = reinterpret_cast<::PhysicalGameObj*>(enterer->PhysicalGameObjPointer.ToPointer());
		}

		InternalDAEventClassPointer->Zone_Enter_Event(objPtr, entererPtr);
	}

	void DAEventClass::ZoneExitEvent(IScriptZoneGameObj^ obj, IPhysicalGameObj^ exiter)
	{
		::ScriptZoneGameObj* objPtr;
		if (obj == nullptr || obj->ScriptZoneGameObjPointer.ToPointer() == nullptr)
		{
			objPtr = nullptr;
		}
		else
		{
			objPtr = reinterpret_cast<::ScriptZoneGameObj*>(obj->ScriptZoneGameObjPointer.ToPointer());
		}

		::PhysicalGameObj* exiterPtr;
		if (exiter == nullptr || exiter->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			exiterPtr = nullptr;
		}
		else
		{
			exiterPtr = reinterpret_cast<::PhysicalGameObj*>(exiter->PhysicalGameObjPointer.ToPointer());
		}

		InternalDAEventClassPointer->Zone_Exit_Event(objPtr, exiterPtr);
	}

	void DAEventClass::ObjectDestroyedEvent(IScriptableGameObj^ obj)
	{
		::ScriptableGameObj* objPtr;
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			objPtr = nullptr;
		}
		else
		{
			objPtr = reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer());
		}

		InternalDAEventClassPointer->Object_Destroyed_Event(objPtr);
	}

	void DAEventClass::TimerExpired(int number, unsigned int data)
	{
		InternalDAEventClassPointer->Timer_Expired(number, data);
	}

	IRenSharpEventClass^ DAEventClass::AsManagedEventClass()
	{
		return DAEventManager::AsManagedEventClass(this);
	}

	IntPtr DAEventClass::DAEventClassPointer::get()
	{
		return IntPtr(InternalDAEventClassPointer);
	}

	bool DAEventClass::IsManagedEventClass::get()
	{
		return DAEventManager::IsManagedEventClass(this);
	}

	bool DAEventClass::InternalDestroyPointer()
	{
		Imports::DestroyDAEventClass(InternalDAEventClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DAEventClass* DAEventClass::InternalDAEventClassPointer::get()
	{
		return reinterpret_cast<::DAEventClass*>(Pointer.ToPointer());
	}
}