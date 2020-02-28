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

#include "stdafx.h"
#include "Mda_player.h"

#include "Imports.h"
#include "UnmanagedContainer.h"
#include "McPlayer.h"
#include "MSoldierGameObj.h"
#include "MStringClassDynamicVectorClass.h"
#include "Mda_token.h"
#include "MDAPlayerObserverTimerStructPtrDynamicVectorClass.h"
#include "MDAPlayerObserverChatCommandStructPtrDynamicVectorClass.h"
#include "MDAPlayerObserverKeyHookStructPtrDynamicVectorClass.h"
#include "MSoldierGameObjDef.h"
#include "MVehicleGameObjDef.h"
#include "MPowerUpGameObjDef.h"
#include "MVehicleGameObj.h"
#include "MPowerUpGameObj.h"
#include "Mweaponmgr.h"
#include "MWeaponClass.h"
#include "MC4GameObj.h"
#include "MDamageableGameObj.h"
#include "MArmedGameObj.h"
#include "MScriptableGameObj.h"
#include "MDAPlayerObserverClassPtrDynamicVectorClass.h"
#include "RenSharpPlayerObserverClass.h"
#include "Mda.h"
#include "Mda_token.h"
#include "RenSharpPlayerDataFactoryClass.h"
#include "RenSharpPlayerDataClass.h"
#include "RenSharpPlayerDataFactoryClass.h"
#include "RenSharpPlayerDataClass.h"

using namespace System::Text;
using namespace System::ComponentModel;

namespace RenSharp
{
	DAPlayerObserverTimerStruct::DAPlayerObserverTimerStruct()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateDAPlayerObserverTimerStruct()))
	{

	}

	DAPlayerObserverTimerStruct::DAPlayerObserverTimerStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool DAPlayerObserverTimerStruct::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDAPlayerObserverTimerStruct ^otherThis = dynamic_cast<IDAPlayerObserverTimerStruct ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DAPlayerObserverTimerStructPointer.Equals(otherThis->DAPlayerObserverTimerStructPointer);
	}

	IUnmanagedContainer<IDAPlayerObserverTimerStruct ^> ^DAPlayerObserverTimerStruct::CreateDAPlayerObserverTimerStruct()
	{
		return gcnew UnmanagedContainer<IDAPlayerObserverTimerStruct ^>(gcnew DAPlayerObserverTimerStruct());
	}

	IntPtr DAPlayerObserverTimerStruct::DAPlayerObserverTimerStructPointer::get()
	{
		return IntPtr(InternalDAPlayerObserverTimerStructPointer);
	}

	unsigned long DAPlayerObserverTimerStruct::StartTime::get()
	{
		return InternalDAPlayerObserverTimerStructPointer->StartTime;
	}

	void DAPlayerObserverTimerStruct::StartTime::set(unsigned long value)
	{
		InternalDAPlayerObserverTimerStructPointer->StartTime = value;
	}

	unsigned long DAPlayerObserverTimerStruct::Duration::get()
	{
		return InternalDAPlayerObserverTimerStructPointer->Duration;
	}

	void DAPlayerObserverTimerStruct::Duration::set(unsigned long value)
	{
		InternalDAPlayerObserverTimerStructPointer->Duration = value;
	}

	bool DAPlayerObserverTimerStruct::Repeat::get()
	{
		return InternalDAPlayerObserverTimerStructPointer->Repeat;
	}

	void DAPlayerObserverTimerStruct::Repeat::set(bool value)
	{
		InternalDAPlayerObserverTimerStructPointer->Repeat = value;
	}

	int DAPlayerObserverTimerStruct::Number::get()
	{
		return InternalDAPlayerObserverTimerStructPointer->Number;
	}

	void DAPlayerObserverTimerStruct::Number::set(int value)
	{
		InternalDAPlayerObserverTimerStructPointer->Number = value;
	}

	unsigned int DAPlayerObserverTimerStruct::Data::get()
	{
		return InternalDAPlayerObserverTimerStructPointer->Data;
	}

	void DAPlayerObserverTimerStruct::Data::set(unsigned int value)
	{
		InternalDAPlayerObserverTimerStructPointer->Data = value;
	}

	bool DAPlayerObserverTimerStruct::InternalDestroyPointer()
	{
		Imports::DestroyDAPlayerObserverTimerStruct(InternalDAPlayerObserverTimerStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DAPlayerObserverTimerStruct *DAPlayerObserverTimerStruct::InternalDAPlayerObserverTimerStructPointer::get()
	{
		return reinterpret_cast<::DAPlayerObserverTimerStruct *>(Pointer.ToPointer());
	}

	DAPlayerDataClass::DAPlayerDataClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool DAPlayerDataClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IRenSharpPlayerDataClass^ otherThis1 = dynamic_cast<IRenSharpPlayerDataClass^>(other);
		if (otherThis1 != nullptr && DAPlayerDataClassPointer.Equals(otherThis1->DAPlayerDataClassPointer))
		{
			return true;
		}

		IDAPlayerDataClass ^otherThis2 = dynamic_cast<IDAPlayerDataClass ^>(other);
		if (otherThis2 == nullptr)
		{
			return nullptr;
		}

		return DAPlayerDataClassPointer.Equals(otherThis2->DAPlayerDataClassPointer);
	}

	void DAPlayerDataClass::Init()
	{
		InternalDAPlayerDataClassPointer->Init();
	}

	void DAPlayerDataClass::ClearLevel()
	{
		InternalDAPlayerDataClassPointer->Clear_Level();
	}

	void DAPlayerDataClass::ClearSession()
	{
		InternalDAPlayerDataClassPointer->Clear_Session();
	}

	IRenSharpPlayerDataClass^ DAPlayerDataClass::AsManagedPlayerData()
	{
		return DAPlayerManager::AsManagedPlayerData(this);
	}

	IntPtr DAPlayerDataClass::DAPlayerDataClassPointer::get()
	{
		return IntPtr(InternalDAPlayerDataClassPointer);
	}

	IcPlayer ^DAPlayerDataClass::Owner::get()
	{
		auto result = InternalDAPlayerDataClassPointer->Get_Owner();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	void DAPlayerDataClass::Owner::set(IcPlayer ^value)
	{
		if (value == nullptr || value->cPlayerPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerDataClassPointer->Set_Owner(nullptr);
		}
		else
		{
			InternalDAPlayerDataClassPointer->Set_Owner(reinterpret_cast<::cPlayer *>(value->cPlayerPointer.ToPointer()));
		}
	}

	IDAPlayerDataFactoryClass ^DAPlayerDataClass::Factory::get()
	{
		auto result = const_cast<::DAPlayerDataFactoryClass *>(InternalDAPlayerDataClassPointer->Get_Factory());
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAPlayerDataFactoryClass(IntPtr(result));
		}
	}

	void DAPlayerDataClass::Factory::set(IDAPlayerDataFactoryClass ^value)
	{
		if (value == nullptr || value->DAPlayerDataFactoryClassPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerDataClassPointer->Set_Factory(nullptr);
		}
		else
		{
			InternalDAPlayerDataClassPointer->Set_Factory(reinterpret_cast<::DAPlayerDataFactoryClass *>(value->DAPlayerDataFactoryClassPointer.ToPointer()));
		}
	}

	int DAPlayerDataClass::ID::get()
	{
		return InternalDAPlayerDataClassPointer->Get_ID();
	}

	String ^DAPlayerDataClass::Name::get()
	{
		return gcnew String(InternalDAPlayerDataClassPointer->Get_Name().Peek_Buffer());
	}

	ISoldierGameObj ^DAPlayerDataClass::GameObj::get()
	{
		auto result = InternalDAPlayerDataClassPointer->Get_GameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SoldierGameObj(IntPtr(result));
		}
	}

	int DAPlayerDataClass::Team::get()
	{
		return InternalDAPlayerDataClassPointer->Get_Team();
	}

	bool DAPlayerDataClass::IsManagedPlayerData::get()
	{
		return DAPlayerManager::IsManagedPlayerData(this);
	}

	bool DAPlayerDataClass::InternalDestroyPointer()
	{
		Imports::DestroyDAPlayerDataClass(InternalDAPlayerDataClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DAPlayerDataClass *DAPlayerDataClass::InternalDAPlayerDataClassPointer::get()
	{
		return reinterpret_cast<::DAPlayerDataClass *>(Pointer.ToPointer());
	}

	DAPlayerDataFactoryClass::DAPlayerDataFactoryClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool DAPlayerDataFactoryClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IRenSharpPlayerDataFactoryClass^ otherThis1 = dynamic_cast<IRenSharpPlayerDataFactoryClass^>(other);
		if (otherThis1 != nullptr && DAPlayerDataFactoryClassPointer.Equals(otherThis1->DAPlayerDataFactoryClassPointer))
		{
			return true;
		}

		IDAPlayerDataFactoryClass ^otherThis2 = dynamic_cast<IDAPlayerDataFactoryClass ^>(other);
		if (otherThis2 == nullptr)
		{
			return nullptr;
		}

		return DAPlayerDataFactoryClassPointer.Equals(otherThis2->DAPlayerDataFactoryClassPointer);
	}

	IUnmanagedContainer<IDAPlayerDataClass ^> ^DAPlayerDataFactoryClass::CreateData()
	{
		auto result = InternalDAPlayerDataFactoryClassPointer->Create_Data();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew UnmanagedContainer<IDAPlayerDataClass ^>(gcnew DAPlayerDataClass(IntPtr(result)));
		}
	}

	IRenSharpPlayerDataFactoryClass^ DAPlayerDataFactoryClass::AsManagedPlayerDataFactory()
	{
		return DAPlayerManager::AsManagedPlayerDataFactory(this);
	}

	IntPtr DAPlayerDataFactoryClass::DAPlayerDataFactoryClassPointer::get()
	{
		return IntPtr(InternalDAPlayerDataFactoryClassPointer);
	}

	bool DAPlayerDataFactoryClass::IsManagedPlayerDataFactory::get()
	{
		return DAPlayerManager::IsManagedPlayerDataFactory(this);
	}

	bool DAPlayerDataFactoryClass::InternalDestroyPointer()
	{
		Imports::DestroyDAPlayerDataFactoryClass(InternalDAPlayerDataFactoryClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DAPlayerDataFactoryClass *DAPlayerDataFactoryClass::InternalDAPlayerDataFactoryClassPointer::get()
	{
		return reinterpret_cast<::DAPlayerDataFactoryClass *>(Pointer.ToPointer());
	}

	DAPlayerObserverChatCommandStruct::DAPlayerObserverChatCommandStruct()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateDAPlayerObserverChatCommandStruct()))
	{

	}

	DAPlayerObserverChatCommandStruct::DAPlayerObserverChatCommandStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IDAPlayerObserverChatCommandStruct ^> ^DAPlayerObserverChatCommandStruct::CreateDAPlayerObserverChatCommandStruct()
	{
		return gcnew UnmanagedContainer<IDAPlayerObserverChatCommandStruct ^>(gcnew DAPlayerObserverChatCommandStruct());
	}

	bool DAPlayerObserverChatCommandStruct::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDAPlayerObserverChatCommandStruct ^otherThis = dynamic_cast<IDAPlayerObserverChatCommandStruct ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DAPlayerObserverChatCommandStructPointer.Equals(otherThis->DAPlayerObserverChatCommandStructPointer);
	}

	bool DAPlayerObserverChatCommandStruct::Func(IDAPlayerObserverClass ^observer, IDATokenClass ^text, TextMessageEnum chatType)
	{
		if (observer == nullptr || observer->DAPlayerObserverClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("observer");
		}
		else if (text == nullptr || text->DATokenClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("text");
		}

		return (reinterpret_cast<::DAPlayerObserverClass *>(observer->DAPlayerObserverClassPointer.ToPointer())
			->*InternalDAPlayerObserverChatCommandStructPointer->Func)(
				*reinterpret_cast<::DATokenClass *>(text->DATokenClassPointer.ToPointer()),
				static_cast<::TextMessageEnum>(chatType));
	}

	IntPtr DAPlayerObserverChatCommandStruct::DAPlayerObserverChatCommandStructPointer::get()
	{
		return IntPtr(InternalDAPlayerObserverChatCommandStructPointer);
	}

	IDynamicVectorClass<String ^> ^DAPlayerObserverChatCommandStruct::Triggers::get()
	{
		return gcnew StringClassDynamicVectorClass(IntPtr(&InternalDAPlayerObserverChatCommandStructPointer->Triggers));
	}

	void DAPlayerObserverChatCommandStruct::Triggers::set(IDynamicVectorClass<String ^> ^value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalDAPlayerObserverChatCommandStructPointer->Triggers = *reinterpret_cast<::DynamicVectorClass<::StringClass> *>(value->Pointer.ToPointer());
	}

	int DAPlayerObserverChatCommandStruct::Parameters::get()
	{
		return InternalDAPlayerObserverChatCommandStructPointer->Parameters;
	}

	void DAPlayerObserverChatCommandStruct::Parameters::set(int value)
	{
		InternalDAPlayerObserverChatCommandStructPointer->Parameters = value;
	}

	DAChatType DAPlayerObserverChatCommandStruct::ChatType::get()
	{
		return static_cast<DAChatType>(InternalDAPlayerObserverChatCommandStructPointer->ChatType);
	}

	void DAPlayerObserverChatCommandStruct::ChatType::set(DAChatType value)
	{
		InternalDAPlayerObserverChatCommandStructPointer->ChatType = static_cast<::DAChatType::Type>(value);
	}

	bool DAPlayerObserverChatCommandStruct::InternalDestroyPointer()
	{
		Imports::DestroyDAPlayerObserverChatCommandStruct(InternalDAPlayerObserverChatCommandStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DAPlayerObserverChatCommandStruct *DAPlayerObserverChatCommandStruct::InternalDAPlayerObserverChatCommandStructPointer::get()
	{
		return reinterpret_cast<::DAPlayerObserverChatCommandStruct *>(Pointer.ToPointer());
	}

	DAPlayerObserverKeyHookStruct::DAPlayerObserverKeyHookStruct()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateDAPlayerObserverKeyHookStruct()))
	{

	}

	DAPlayerObserverKeyHookStruct::DAPlayerObserverKeyHookStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IDAPlayerObserverKeyHookStruct ^> ^DAPlayerObserverKeyHookStruct::CreateDAPlayerObserverKeyHookStruct()
	{
		return gcnew UnmanagedContainer<IDAPlayerObserverKeyHookStruct ^>(gcnew DAPlayerObserverKeyHookStruct());
	}

	bool DAPlayerObserverKeyHookStruct::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDAPlayerObserverKeyHookStruct ^otherThis = dynamic_cast<IDAPlayerObserverKeyHookStruct ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DAPlayerObserverKeyHookStructPointer.Equals(otherThis->DAPlayerObserverKeyHookStructPointer);
	}

	void DAPlayerObserverKeyHookStruct::Func(IDAPlayerObserverClass ^observer)
	{
		if (observer == nullptr || observer->DAPlayerObserverClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("observer");
		}

		(reinterpret_cast<::DAPlayerObserverClass *>(observer->DAPlayerObserverClassPointer.ToPointer())
			->*InternalDAPlayerObserverKeyHookStructPointer->Func)();
	}

	IntPtr DAPlayerObserverKeyHookStruct::DAPlayerObserverKeyHookStructPointer::get()
	{
		return IntPtr(InternalDAPlayerObserverKeyHookStructPointer);
	}

	IDynamicVectorClass<String ^> ^DAPlayerObserverKeyHookStruct::Triggers::get()
	{
		return gcnew StringClassDynamicVectorClass(IntPtr(&InternalDAPlayerObserverKeyHookStructPointer->Triggers));
	}

	void DAPlayerObserverKeyHookStruct::Triggers::set(IDynamicVectorClass<String ^> ^value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalDAPlayerObserverKeyHookStructPointer->Triggers = *reinterpret_cast<::DynamicVectorClass<::StringClass> *>(value->Pointer.ToPointer());
	}

	bool DAPlayerObserverKeyHookStruct::InternalDestroyPointer()
	{
		Imports::DestroyDAPlayerObserverKeyHookStruct(InternalDAPlayerObserverKeyHookStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DAPlayerObserverKeyHookStruct *DAPlayerObserverKeyHookStruct::InternalDAPlayerObserverKeyHookStructPointer::get()
	{
		return reinterpret_cast<::DAPlayerObserverKeyHookStruct *>(Pointer.ToPointer());
	}

	DAPlayerObserverClass::DAPlayerObserverClass()
	{

	}

	DAPlayerObserverClass::DAPlayerObserverClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	String ^DAPlayerObserverClass::ToString()
	{
		StringBuilder ^builder = gcnew StringBuilder();
		builder->Append(ObserverName);

		return builder->ToString();
	}

	bool DAPlayerObserverClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDAPlayerObserverClass ^otherThis = dynamic_cast<IDAPlayerObserverClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DAPlayerObserverClassPointer.Equals(otherThis->DAPlayerObserverClassPointer);
	}

	void DAPlayerObserverClass::AddFlag(DAPlayerFlags flag)
	{
		InternalDAPlayerObserverClassPointer->Add_Flag(static_cast<::DAPlayerFlags::Flag>(flag));
	}

	void DAPlayerObserverClass::RemoveFlag(DAPlayerFlags flag)
	{
		InternalDAPlayerObserverClassPointer->Remove_Flag(static_cast<::DAPlayerFlags::Flag>(flag));
	}

	bool DAPlayerObserverClass::HasFlag(DAPlayerFlags flag)
	{
		return InternalDAPlayerObserverClassPointer->Has_Flag(static_cast<::DAPlayerFlags::Flag>(flag));
	}

	void DAPlayerObserverClass::StartTimer(int number, float duration, bool repeat, unsigned int data)
	{
		if (IsManagedObserver)
		{
			AsManagedPlayerObserver()->StartTimer(number, TimeSpan::FromSeconds(duration), repeat, data);
		}
		else
		{
			InternalDAPlayerObserverClassPointer->Start_Timer(number, duration, repeat, data);
		}
	}

	void DAPlayerObserverClass::StartTimer(int number, float duration, bool repeat)
	{
		if (IsManagedObserver)
		{
			AsManagedPlayerObserver()->StartTimer(number, TimeSpan::FromSeconds(duration), repeat);
		}
		else
		{
			InternalDAPlayerObserverClassPointer->Start_Timer(number, duration, repeat);
		}
	}

	void DAPlayerObserverClass::StartTimer(int number, float duration)
	{
		if (IsManagedObserver)
		{
			AsManagedPlayerObserver()->StartTimer(number, TimeSpan::FromSeconds(duration));
		}
		else
		{
			InternalDAPlayerObserverClassPointer->Start_Timer(number, duration);
		}
	}

	void DAPlayerObserverClass::StopTimer(int number, unsigned int data)
	{
		if (IsManagedObserver)
		{
			AsManagedPlayerObserver()->StopTimer(number, data);
		}
		else
		{
			InternalDAPlayerObserverClassPointer->Stop_Timer(number, data);
		}
	}

	void DAPlayerObserverClass::StopTimer(int number)
	{
		if (IsManagedObserver)
		{
			AsManagedPlayerObserver()->StopTimer(number);
		}
		else
		{
			InternalDAPlayerObserverClassPointer->Stop_Timer(number);
		}
	}

	bool DAPlayerObserverClass::IsTimer(int number, unsigned int data)
	{
		if (IsManagedObserver)
		{
			return AsManagedPlayerObserver()->IsTimer(number, data);
		}
		else
		{
			return InternalDAPlayerObserverClassPointer->Is_Timer(number, data);
		}
	}

	bool DAPlayerObserverClass::IsTimer(int number)
	{
		if (IsManagedObserver)
		{
			return AsManagedPlayerObserver()->IsTimer(number);
		}
		else
		{
			return InternalDAPlayerObserverClassPointer->Is_Timer(number);
		}
	}

	void DAPlayerObserverClass::ClearTimers()
	{
		if (IsManagedObserver)
		{
			AsManagedPlayerObserver()->ClearTimers();
		}
		else
		{
			InternalDAPlayerObserverClassPointer->Clear_Timers();
		}
	}

	void DAPlayerObserverClass::UnregisterChatCommand(String ^trigger)
	{
		if (trigger == nullptr)
		{
			throw gcnew ArgumentNullException("trigger");
		}

		if (IsManagedObserver)
		{
			AsManagedPlayerObserver()->UnregisterChatCommand(trigger);
		}
		else
		{
			IntPtr triggerHandle = Marshal::StringToHGlobalAnsi(trigger);
			try
			{
				InternalDAPlayerObserverClassPointer->Unregister_Chat_Command(reinterpret_cast<char*>(triggerHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(triggerHandle);
			}
		}
	}

	void DAPlayerObserverClass::ClearChatCommands()
	{
		if (IsManagedObserver)
		{
			AsManagedPlayerObserver()->ClearChatCommands();
		}
		else
		{
			InternalDAPlayerObserverClassPointer->Clear_Chat_Commands();
		}
	}

	void DAPlayerObserverClass::UnregisterKeyHook(String ^trigger)
	{
		if (trigger == nullptr)
		{
			throw gcnew ArgumentNullException("trigger");
		}

		if (IsManagedObserver)
		{
			AsManagedPlayerObserver()->UnregisterKeyHook(trigger);
		}
		else
		{
			IntPtr triggerHandle = Marshal::StringToHGlobalAnsi(trigger);
			try
			{
				InternalDAPlayerObserverClassPointer->Unregister_Key_Hook(reinterpret_cast<char*>(triggerHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(triggerHandle);
			}
		}
	}

	void DAPlayerObserverClass::ClearKeyHooks()
	{
		if (IsManagedObserver)
		{
			AsManagedPlayerObserver()->ClearKeyHooks();
		}
		else
		{
			InternalDAPlayerObserverClassPointer->Clear_Key_Hooks();
		}
	}

	void DAPlayerObserverClass::Init()
	{
		InternalDAPlayerObserverClassPointer->Init();
	}

	void DAPlayerObserverClass::Join()
	{
		InternalDAPlayerObserverClassPointer->Join();
	}

	void DAPlayerObserverClass::Leave()
	{
		InternalDAPlayerObserverClassPointer->Leave();
	}

	void DAPlayerObserverClass::LevelLoaded()
	{
		InternalDAPlayerObserverClassPointer->Level_Loaded();
	}

	void DAPlayerObserverClass::PlayerLoaded()
	{
		InternalDAPlayerObserverClassPointer->Player_Loaded();
	}

	void DAPlayerObserverClass::NameChange()
	{
		InternalDAPlayerObserverClassPointer->Name_Change();
	}

	void DAPlayerObserverClass::TeamChange()
	{
		InternalDAPlayerObserverClassPointer->Team_Change();
	}

	int DAPlayerObserverClass::CharacterPurchaseRequest(float %cost, ISoldierGameObjDef ^item)
	{
		float tmpCost = cost;
		::SoldierGameObjDef *itemPtr;

		if (item == nullptr || item->SoldierGameObjDefPointer.ToPointer() == nullptr)
		{
			itemPtr = nullptr;
		}
		else
		{
			itemPtr = reinterpret_cast<::SoldierGameObjDef *>(item->SoldierGameObjDefPointer.ToPointer());
		}

		int result = InternalDAPlayerObserverClassPointer->Character_Purchase_Request(tmpCost, itemPtr);

		cost = tmpCost;

		return result;
	}

	int DAPlayerObserverClass::VehiclePurchaseRequest(float %cost, IVehicleGameObjDef ^item)
	{
		float tmpCost = cost;
		::VehicleGameObjDef *itemPtr;

		if (item == nullptr || item->VehicleGameObjDefPointer.ToPointer() == nullptr)
		{
			itemPtr = nullptr;
		}
		else
		{
			itemPtr = reinterpret_cast<::VehicleGameObjDef *>(item->VehicleGameObjDefPointer.ToPointer());
		}

		int result = InternalDAPlayerObserverClassPointer->Vehicle_Purchase_Request(tmpCost, itemPtr);

		cost = tmpCost;

		return result;
	}

	int DAPlayerObserverClass::PowerUpPurchaseRequest(float %cost, IPowerUpGameObjDef ^item)
	{
		float tmpCost = cost;
		::PowerUpGameObjDef *itemPtr;

		if (item == nullptr || item->PowerUpGameObjDefPointer.ToPointer() == nullptr)
		{
			itemPtr = nullptr;
		}
		else
		{
			itemPtr = reinterpret_cast<::PowerUpGameObjDef *>(item->PowerUpGameObjDefPointer.ToPointer());
		}

		int result = InternalDAPlayerObserverClassPointer->PowerUp_Purchase_Request(tmpCost, itemPtr);

		cost = tmpCost;

		return result;
	}

	int DAPlayerObserverClass::CustomPurchaseRequest(float %cost, unsigned int id)
	{
		float tmpCost = cost;

		int result = InternalDAPlayerObserverClassPointer->Custom_Purchase_Request(tmpCost, id);

		cost = tmpCost;

		return result;
	}

	void DAPlayerObserverClass::CharacterPurchase(float cost, ISoldierGameObjDef ^item)
	{
		if (item == nullptr || item->SoldierGameObjDefPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerObserverClassPointer->Character_Purchase(cost, nullptr);
		}
		else
		{
			InternalDAPlayerObserverClassPointer->Character_Purchase(
				cost, 
				reinterpret_cast<::SoldierGameObjDef *>(item->SoldierGameObjDefPointer.ToPointer()));
		}
	}

	void DAPlayerObserverClass::VehiclePurchase(float cost, IVehicleGameObjDef ^item)
	{
		if (item == nullptr || item->VehicleGameObjDefPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerObserverClassPointer->Vehicle_Purchase(cost, nullptr);
		}
		else
		{
			InternalDAPlayerObserverClassPointer->Vehicle_Purchase(
				cost,
				reinterpret_cast<::VehicleGameObjDef *>(item->VehicleGameObjDefPointer.ToPointer()));
		}
	}

	void DAPlayerObserverClass::PowerUpPurchase(float cost, IPowerUpGameObjDef ^item)
	{
		if (item == nullptr || item->PowerUpGameObjDefPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerObserverClassPointer->PowerUp_Purchase(cost, nullptr);
		}
		else
		{
			InternalDAPlayerObserverClassPointer->PowerUp_Purchase(
				cost,
				reinterpret_cast<::PowerUpGameObjDef *>(item->PowerUpGameObjDefPointer.ToPointer()));
		}
	}

	void DAPlayerObserverClass::CustomPurchase(float cost, unsigned int id)
	{
		InternalDAPlayerObserverClassPointer->Custom_Purchase(cost, id);
	}

	bool DAPlayerObserverClass::VehicleEntryRequest(IVehicleGameObj ^vehicle, int %seat)
	{
		::VehicleGameObj *vehiclePtr;
		int tmpSeat = seat;

		if (vehicle == nullptr || vehicle->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			vehiclePtr = nullptr;
		}
		else
		{
			vehiclePtr = reinterpret_cast<::VehicleGameObj *>(vehicle->VehicleGameObjPointer.ToPointer());
		}

		bool result = InternalDAPlayerObserverClassPointer->Vehicle_Entry_Request(vehiclePtr, tmpSeat);

		seat = tmpSeat;

		return result;
	}

	void DAPlayerObserverClass::VehicleEnter(IVehicleGameObj ^vehicle, int seat)
	{
		if (vehicle == nullptr || vehicle->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerObserverClassPointer->Vehicle_Enter(nullptr, seat);
		}
		else
		{
			InternalDAPlayerObserverClassPointer->Vehicle_Enter(
				reinterpret_cast<::VehicleGameObj *>(vehicle->VehicleGameObjPointer.ToPointer()),
				seat);
		}
	}

	void DAPlayerObserverClass::VehicleExit(IVehicleGameObj ^vehicle, int seat)
	{
		if (vehicle == nullptr || vehicle->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerObserverClassPointer->Vehicle_Exit(nullptr, seat);
		}
		else
		{
			InternalDAPlayerObserverClassPointer->Vehicle_Exit(
				reinterpret_cast<::VehicleGameObj *>(vehicle->VehicleGameObjPointer.ToPointer()),
				seat);
		}
	}

	bool DAPlayerObserverClass::PowerUpGrantRequest(IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj)
	{
		::PowerUpGameObjDef *powerUpPtr;
		::PowerUpGameObj *powerUpObjPtr;

		if (powerUp == nullptr || powerUp->PowerUpGameObjDefPointer.ToPointer() == nullptr)
		{
			powerUpPtr = nullptr;
		}
		else
		{
			powerUpPtr = reinterpret_cast<::PowerUpGameObjDef *>(powerUp->PowerUpGameObjDefPointer.ToPointer());
		}

		if (powerUpObj == nullptr || powerUpObj->PowerUpGameObjPointer.ToPointer() == nullptr)
		{
			powerUpObjPtr = nullptr;
		}
		else
		{
			powerUpObjPtr = reinterpret_cast<::PowerUpGameObj *>(powerUpObj->PowerUpGameObjPointer.ToPointer());
		}

		return InternalDAPlayerObserverClassPointer->PowerUp_Grant_Request(powerUpPtr, powerUpObjPtr);
	}

	void DAPlayerObserverClass::PowerUpGrant(IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj)
	{
		::PowerUpGameObjDef *powerUpPtr;
		::PowerUpGameObj *powerUpObjPtr;

		if (powerUp == nullptr || powerUp->PowerUpGameObjDefPointer.ToPointer() == nullptr)
		{
			powerUpPtr = nullptr;
		}
		else
		{
			powerUpPtr = reinterpret_cast<::PowerUpGameObjDef *>(powerUp->PowerUpGameObjDefPointer.ToPointer());
		}

		if (powerUpObj == nullptr || powerUpObj->PowerUpGameObjPointer.ToPointer() == nullptr)
		{
			powerUpObjPtr = nullptr;
		}
		else
		{
			powerUpObjPtr = reinterpret_cast<::PowerUpGameObj *>(powerUpObj->PowerUpGameObjPointer.ToPointer());
		}

		InternalDAPlayerObserverClassPointer->PowerUp_Grant(powerUpPtr, powerUpObjPtr);
	}

	bool DAPlayerObserverClass::AddWeaponRequest(IWeaponDefinitionClass ^weapon)
	{
		if (weapon == nullptr || weapon->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			return InternalDAPlayerObserverClassPointer->Add_Weapon_Request(nullptr);
		}
		else
		{
			return InternalDAPlayerObserverClassPointer->Add_Weapon_Request(
				reinterpret_cast<::WeaponDefinitionClass *>(weapon->WeaponDefinitionClassPointer.ToPointer()));
		}
	}

	void DAPlayerObserverClass::AddWeapon(IWeaponClass ^weapon)
	{
		if (weapon == nullptr || weapon->WeaponClassPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerObserverClassPointer->Add_Weapon(nullptr);
		}
		else
		{
			InternalDAPlayerObserverClassPointer->Add_Weapon(
				reinterpret_cast<::WeaponClass *>(weapon->WeaponClassPointer.ToPointer()));
		}
	}

	void DAPlayerObserverClass::RemoveWeapon(IWeaponClass ^weapon)
	{
		if (weapon == nullptr || weapon->WeaponClassPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerObserverClassPointer->Remove_Weapon(nullptr);
		}
		else
		{
			InternalDAPlayerObserverClassPointer->Remove_Weapon(
				reinterpret_cast<::WeaponClass *>(weapon->WeaponClassPointer.ToPointer()));
		}
	}

	void DAPlayerObserverClass::ClearWeapons()
	{
		InternalDAPlayerObserverClassPointer->Clear_Weapons();
	}

	bool DAPlayerObserverClass::C4DetonateRequest(IC4GameObj ^c4)
	{
		if (c4 == nullptr || c4->C4GameObjPointer.ToPointer() == nullptr)
		{
			return InternalDAPlayerObserverClassPointer->C4_Detonate_Request(nullptr);
		}
		else
		{
			return InternalDAPlayerObserverClassPointer->C4_Detonate_Request(
				reinterpret_cast<::C4GameObj *>(c4->C4GameObjPointer.ToPointer()));
		}
	}

	void DAPlayerObserverClass::C4Detonate(IC4GameObj ^c4)
	{
		if (c4 == nullptr || c4->C4GameObjPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerObserverClassPointer->C4_Detonate(nullptr);
		}
		else
		{
			InternalDAPlayerObserverClassPointer->C4_Detonate(
				reinterpret_cast<::C4GameObj *>(c4->C4GameObjPointer.ToPointer()));
		}
	}

	void DAPlayerObserverClass::ChangeCharacter(ISoldierGameObjDef ^soldier)
	{
		if (soldier == nullptr || soldier->SoldierGameObjDefPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerObserverClassPointer->Change_Character(nullptr);
		}
		else
		{
			InternalDAPlayerObserverClassPointer->Change_Character(
				reinterpret_cast<::SoldierGameObjDef *>(soldier->SoldierGameObjDefPointer.ToPointer()));
		}
	}

	void DAPlayerObserverClass::Created()
	{
		InternalDAPlayerObserverClassPointer->Created();
	}

	void DAPlayerObserverClass::Destroyed()
	{
		InternalDAPlayerObserverClassPointer->Destroyed();
	}

	bool DAPlayerObserverClass::DamageDealtRequest(IDamageableGameObj ^victim, float %damage, unsigned int %warhead, float scale, DADamageType type)
	{
		::DamageableGameObj *victimPtr;
		float tmpDamage = damage;
		unsigned int tmpWarhead = warhead;

		if (victim == nullptr || victim->DamageableGameObjPointer.ToPointer() == nullptr)
		{
			victimPtr = nullptr;
		}
		else
		{
			victimPtr = reinterpret_cast<::DamageableGameObj *>(victim->DamageableGameObjPointer.ToPointer());
		}

		bool result = InternalDAPlayerObserverClassPointer->Damage_Dealt_Request(
			victimPtr, 
			tmpDamage,
			tmpWarhead, 
			scale, 
			static_cast<::DADamageType::Type>(type));

		damage = tmpDamage;
		warhead = tmpWarhead;

		return result;
	}

	bool DAPlayerObserverClass::DamageReceivedRequest(IArmedGameObj ^damager, float %damage, unsigned int %warhead, float scale, DADamageType type)
	{
		::ArmedGameObj *damagerPtr;
		float tmpDamage = damage;
		unsigned int tmpWarhead = warhead;

		if (damager == nullptr || damager->ArmedGameObjPointer.ToPointer() == nullptr)
		{
			damagerPtr = nullptr;
		}
		else
		{
			damagerPtr = reinterpret_cast<::ArmedGameObj *>(damager->ArmedGameObjPointer.ToPointer());
		}

		bool result = InternalDAPlayerObserverClassPointer->Damage_Received_Request(
			damagerPtr,
			tmpDamage,
			tmpWarhead,
			scale,
			static_cast<::DADamageType::Type>(type));

		damage = tmpDamage;
		warhead = tmpWarhead;

		return result;
	}

	void DAPlayerObserverClass::DamageDealt(IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type)
	{
		if (victim == nullptr || victim->DamageableGameObjPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerObserverClassPointer->Damage_Dealt(
				nullptr,
				damage,
				warhead,
				scale,
				static_cast<::DADamageType::Type>(type));
		}
		else
		{
			InternalDAPlayerObserverClassPointer->Damage_Dealt(
				reinterpret_cast<::DamageableGameObj *>(victim->DamageableGameObjPointer.ToPointer()),
				damage,
				warhead,
				scale,
				static_cast<::DADamageType::Type>(type));
		}
	}

	void DAPlayerObserverClass::DamageReceived(IArmedGameObj ^damager, float damage, unsigned int warhead, float scale, DADamageType type)
	{
		if (damager == nullptr || damager->ArmedGameObjPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerObserverClassPointer->Damage_Received(
				nullptr,
				damage,
				warhead,
				scale,
				static_cast<::DADamageType::Type>(type));
		}
		else
		{
			InternalDAPlayerObserverClassPointer->Damage_Received(
				reinterpret_cast<::ArmedGameObj *>(damager->ArmedGameObjPointer.ToPointer()),
				damage,
				warhead,
				scale,
				static_cast<::DADamageType::Type>(type));
		}
	}

	void DAPlayerObserverClass::KillDealt(IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type)
	{
		if (victim == nullptr || victim->DamageableGameObjPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerObserverClassPointer->Kill_Dealt(
				nullptr,
				damage,
				warhead,
				scale,
				static_cast<::DADamageType::Type>(type));
		}
		else
		{
			InternalDAPlayerObserverClassPointer->Kill_Dealt(
				reinterpret_cast<::DamageableGameObj *>(victim->DamageableGameObjPointer.ToPointer()),
				damage,
				warhead,
				scale,
				static_cast<::DADamageType::Type>(type));
		}
	}

	void DAPlayerObserverClass::KillReceived(IArmedGameObj ^killer, float damage, unsigned int warhead, float scale, DADamageType type)
	{
		if (killer == nullptr || killer->ArmedGameObjPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerObserverClassPointer->Kill_Received(
				nullptr,
				damage,
				warhead,
				scale,
				static_cast<::DADamageType::Type>(type));
		}
		else
		{
			InternalDAPlayerObserverClassPointer->Kill_Received(
				reinterpret_cast<::ArmedGameObj *>(killer->ArmedGameObjPointer.ToPointer()),
				damage,
				warhead,
				scale,
				static_cast<::DADamageType::Type>(type));
		}
	}

	void DAPlayerObserverClass::Custom(IScriptableGameObj ^sender, int type, int param)
	{
		if (sender == nullptr || sender->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerObserverClassPointer->Custom(nullptr, type, param);
		}
		else
		{
			InternalDAPlayerObserverClassPointer->Custom(
				reinterpret_cast<::ScriptableGameObj *>(sender->ScriptableGameObjPointer.ToPointer()),
				type,
				param);
		}
	}

	void DAPlayerObserverClass::Poked(IcPlayer ^player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerObserverClassPointer->Poked(nullptr);
		}
		else
		{
			InternalDAPlayerObserverClassPointer->Poked(reinterpret_cast<::cPlayer *>(player->cPlayerPointer.ToPointer()));
		}
	}

	void DAPlayerObserverClass::TimerExpired(int number, unsigned int data)
	{
		InternalDAPlayerObserverClassPointer->Timer_Expired(number, data);
	}

	void DAPlayerObserverClass::Think()
	{
		InternalDAPlayerObserverClassPointer->Think();
	}

	void DAPlayerObserverClass::SetDeletePending()
	{
		InternalDAPlayerObserverClassPointer->Set_Delete_Pending();
	}

	IRenSharpPlayerObserverClass^ DAPlayerObserverClass::AsManagedPlayerObserver()
	{
		return DAPlayerClass::AsManagedPlayerObserver(this);
	}

	IntPtr DAPlayerObserverClass::DAPlayerObserverClassPointer::get()
	{
		return IntPtr(InternalDAPlayerObserverClassPointer);
	}

	IcPlayer ^DAPlayerObserverClass::Owner::get()
	{
		auto result = InternalDAPlayerObserverClassPointer->Get_Owner();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	void DAPlayerObserverClass::Owner::set(IcPlayer ^value)
	{
		if (value == nullptr || value->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalDAPlayerObserverClassPointer->Set_Owner(reinterpret_cast<::cPlayer *>(value->cPlayerPointer.ToPointer()));
	}

	DAPlayerFlags DAPlayerObserverClass::Flags::get()
	{
		return static_cast<DAPlayerFlags>(InternalDAPlayerObserverClassPointer->Get_Flags());
	}

	void DAPlayerObserverClass::Flags::set(DAPlayerFlags value)
	{
		InternalDAPlayerObserverClassPointer->Set_Flags(static_cast<::DAPlayerFlags::Flag>(value));
	}

	int DAPlayerObserverClass::ID::get()
	{
		return InternalDAPlayerObserverClassPointer->Get_ID();
	}

	String ^DAPlayerObserverClass::Name::get()
	{
		return gcnew String(InternalDAPlayerObserverClassPointer->Get_Name().Peek_Buffer());
	}

	ISoldierGameObj ^DAPlayerObserverClass::GameObj::get()
	{
		auto result = InternalDAPlayerObserverClassPointer->Get_GameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SoldierGameObj(IntPtr(result));
		}
	}

	int DAPlayerObserverClass::Team::get()
	{
		return InternalDAPlayerObserverClassPointer->Get_Team();
	}

	IDynamicVectorClass<IDAPlayerObserverTimerStruct ^> ^DAPlayerObserverClass::Timers::get()
	{
		return gcnew DAPlayerObserverTimerStructPtrDynamicVectorClass(
			IntPtr(const_cast<::DynamicVectorClass<::DAPlayerObserverTimerStruct *> *>(&InternalDAPlayerObserverClassPointer->Get_Timers())));
	}

	IDynamicVectorClass<IDAPlayerObserverChatCommandStruct ^> ^DAPlayerObserverClass::ChatCommands::get()
	{
		return gcnew DAPlayerObserverChatCommandStructPtrDynamicVectorClass(
			IntPtr(const_cast<::DynamicVectorClass<::DAPlayerObserverChatCommandStruct *> *>(&InternalDAPlayerObserverClassPointer->Get_Chat_Commands())));
	}

	IDynamicVectorClass<IDAPlayerObserverKeyHookStruct ^> ^DAPlayerObserverClass::KeyHooks::get()
	{
		return gcnew DAPlayerObserverKeyHookStructPtrDynamicVectorClass(
			IntPtr(const_cast<::DynamicVectorClass<::DAPlayerObserverKeyHookStruct *> *>(&InternalDAPlayerObserverClassPointer->Get_Key_Hooks())));
	}

	bool DAPlayerObserverClass::IsDeletePending::get()
	{
		return InternalDAPlayerObserverClassPointer->Is_Delete_Pending();
	}

	String ^DAPlayerObserverClass::ObserverName::get()
	{
		auto result = InternalDAPlayerObserverClassPointer->Get_Observer_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	bool DAPlayerObserverClass::IsManagedObserver::get()
	{
		return DAPlayerClass::IsManagedPlayerObserver(this);
	}

	bool DAPlayerObserverClass::InternalDestroyPointer()
	{
		Imports::DestroyDAPlayerObserverClass(InternalDAPlayerObserverClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DAPlayerObserverClass *DAPlayerObserverClass::InternalDAPlayerObserverClassPointer::get()
	{
		return reinterpret_cast<::DAPlayerObserverClass *>(Pointer.ToPointer());
	}

	static DAPlayerClass::DAPlayerClass()
	{
		managedPlayerObservers = gcnew Generic::Dictionary<IntPtr, IRenSharpPlayerObserverClass^>();
	}

	DAPlayerClass::DAPlayerClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	String ^DAPlayerClass::ToString()
	{
		StringBuilder ^builder = gcnew StringBuilder();
		builder->Append(Name);

		return builder->ToString();
	}

	bool DAPlayerClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDAPlayerClass ^otherThis = dynamic_cast<IDAPlayerClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DAPlayerClassPointer.Equals(otherThis->DAPlayerClassPointer);
	}

	void DAPlayerClass::OnManagedPlayerObserverDestructed(IntPtr observer)
	{
		IRenSharpPlayerObserverClass^ managedPlayerObserver = AsManagedPlayerObserver(observer);
		if (managedPlayerObserver != nullptr && managedPlayerObserver->IsAttached)
		{
			managedPlayerObserver->DestroyPointer = false;

#pragma push_macro("delete")
#undef delete

			delete managedPlayerObserver;
			managedPlayerObserver = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool DAPlayerClass::IsManagedPlayerObserver(IntPtr observer)
	{
		return managedPlayerObservers->ContainsKey(observer);
	}

	bool DAPlayerClass::IsManagedPlayerObserver(IDAPlayerObserverClass ^observer)
	{
		if (observer == nullptr)
		{
			throw gcnew ArgumentNullException("observer");
		}

		return IsManagedPlayerObserver(observer->DAPlayerObserverClassPointer);
	}

	IRenSharpPlayerObserverClass^ DAPlayerClass::AsManagedPlayerObserver(IntPtr observerPtr)
	{
		IRenSharpPlayerObserverClass^ result = nullptr;
		managedPlayerObservers->TryGetValue(observerPtr, result);

		return result;
	}

	IRenSharpPlayerObserverClass^ DAPlayerClass::AsManagedPlayerObserver(IDAPlayerObserverClass ^observer)
	{
		if (observer == nullptr)
		{
			throw gcnew ArgumentNullException("observer");
		}

		return AsManagedPlayerObserver(observer->DAPlayerObserverClassPointer);
	}

	void DAPlayerClass::AddObserver(IDAPlayerObserverClass ^observer)
	{
		if (observer == nullptr || observer->DAPlayerObserverClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("observer");
		}
		
		if (observer->IsManagedObserver)
		{
			AddObserver(observer->AsManagedPlayerObserver());
		}
		else
		{
			InternalDAPlayerClassPointer->Add_Observer(
				reinterpret_cast<::DAPlayerObserverClass*>(observer->DAPlayerObserverClassPointer.ToPointer()));
		}
	}

	void DAPlayerClass::AddObserver(IRenSharpPlayerObserverClass^ observer)
	{
		if (observer == nullptr)
		{
			throw gcnew ArgumentNullException("observer");
		}
		
		if (!observer->IsAttached)
		{
			observer->AttachToUnmanagedObject();
		}

		if (!observer->IsRegistered)
		{
			observer->RegisterManagedObject();
		}

		InternalDAPlayerClassPointer->Add_Observer(
			reinterpret_cast<::DAPlayerObserverClass *>(observer->DAPlayerObserverClassPointer.ToPointer()));
	}

	void DAPlayerClass::AddObserver(IUnmanagedContainer<IDAPlayerObserverClass^>^ observer)
	{
		if (observer == nullptr)
		{
			throw gcnew ArgumentNullException("observer");
		}
		else if (observer->UnmanagedObject == nullptr || observer->UnmanagedObject->DAPlayerObserverClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentException("Unmanaged container is empty.");
		}

		AddObserver(observer->UnmanagedObject);
		observer->ReleaseObject();
	}

	void DAPlayerClass::RemoveObserver(String ^name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			InternalDAPlayerClassPointer->Remove_Observer(reinterpret_cast<char *>(nameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	IDAPlayerObserverClass ^DAPlayerClass::FindObserver(String ^name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			auto result = InternalDAPlayerClassPointer->Find_Observer(reinterpret_cast<char *>(nameHandle.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew DAPlayerObserverClass(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	IDAPlayerDataClass ^DAPlayerClass::FindData(IDAPlayerDataFactoryClass ^factory)
	{
		if (factory == nullptr || factory->DAPlayerDataFactoryClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}

		auto result = InternalDAPlayerClassPointer->Find_Data(
			reinterpret_cast<::DAPlayerDataFactoryClass *>(factory->DAPlayerDataFactoryClassPointer.ToPointer()));

		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAPlayerDataClass(IntPtr(result));
		}
	}

	IRenSharpPlayerDataClass^ DAPlayerClass::FindData(IRenSharpPlayerDataFactoryClass^ factory)
	{
		if (factory == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}

		if (!factory->IsAttached)
		{
			factory->AttachToUnmanagedObject();
		}

		if (!factory->IsRegistered)
		{
			factory->RegisterManagedObject();
		}

		auto result = InternalDAPlayerClassPointer->Find_Data(
			reinterpret_cast<::DAPlayerDataFactoryClass*>(factory->DAPlayerDataFactoryClassPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}

		return DAPlayerManager::AsManagedPlayerData(IntPtr(result));
	}

	void DAPlayerClass::UpdateTag()
	{
		InternalDAPlayerClassPointer->Update_Tag();
	}

	void DAPlayerClass::AddTag(String ^tag, int position, DAPlayerFlags flags)
	{
		if (tag == nullptr)
		{
			throw gcnew ArgumentNullException("tag");
		}

		IntPtr tagHandle = Marshal::StringToHGlobalAnsi(tag);
		try
		{
			InternalDAPlayerClassPointer->Add_Tag(
				reinterpret_cast<char *>(tagHandle.ToPointer()),
				position,
				static_cast<::DAPlayerFlags::Flag>(flags));
		}
		finally
		{
			Marshal::FreeHGlobal(tagHandle);
		}
	}

	void DAPlayerClass::AddTag(String ^tag, int position)
	{
		if (tag == nullptr)
		{
			throw gcnew ArgumentNullException("tag");
		}

		IntPtr tagHandle = Marshal::StringToHGlobalAnsi(tag);
		try
		{
			InternalDAPlayerClassPointer->Add_Tag(
				reinterpret_cast<char *>(tagHandle.ToPointer()),
				position);
		}
		finally
		{
			Marshal::FreeHGlobal(tagHandle);
		}
	}

	void DAPlayerClass::AddTag(String ^tag)
	{
		if (tag == nullptr)
		{
			throw gcnew ArgumentNullException("tag");
		}

		IntPtr tagHandle = Marshal::StringToHGlobalAnsi(tag);
		try
		{
			InternalDAPlayerClassPointer->Add_Tag(
				reinterpret_cast<char *>(tagHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(tagHandle);
		}
	}

	void DAPlayerClass::RemoveTag(String ^tag)
	{
		if (tag == nullptr)
		{
			throw gcnew ArgumentNullException("tag");
		}

		IntPtr tagHandle = Marshal::StringToHGlobalAnsi(tag);
		try
		{
			InternalDAPlayerClassPointer->Remove_Tag(
				reinterpret_cast<char *>(tagHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(tagHandle);
		}
	}

	void DAPlayerClass::RemoveTagsWithFlag(DAPlayerFlags flag)
	{
		InternalDAPlayerClassPointer->Remove_Tags_With_Flag(static_cast<::DAPlayerFlags::Flag>(flag));
	}

	void DAPlayerClass::ResetLastTibDamageTime()
	{
		InternalDAPlayerClassPointer->Reset_Last_Tib_Damage_Time();
	}

	void DAPlayerClass::ResetCreationTime()
	{
		InternalDAPlayerClassPointer->Reset_Creation_Time();
	}

	void DAPlayerClass::Join()
	{
		InternalDAPlayerClassPointer->Join();
	}

	void DAPlayerClass::Leave()
	{
		InternalDAPlayerClassPointer->Leave();
	}

	void DAPlayerClass::LevelLoaded()
	{
		InternalDAPlayerClassPointer->Level_Loaded();
	}

	void DAPlayerClass::PlayerLoaded()
	{
		InternalDAPlayerClassPointer->Player_Loaded();
	}

	void DAPlayerClass::NameChange()
	{
		InternalDAPlayerClassPointer->Name_Change();
	}

	bool DAPlayerClass::Chat(TextMessageEnum type, String ^message, int receiverID)
	{
		if (message == nullptr)
		{
			return InternalDAPlayerClassPointer->Chat(
				static_cast<::TextMessageEnum>(type),
				nullptr,
				receiverID);
		}
		else
		{
			IntPtr messageHandle = Marshal::StringToHGlobalUni(message);
			try
			{
				return InternalDAPlayerClassPointer->Chat(
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

	bool DAPlayerClass::Radio(int playerType, int announcementID, int iconID, AnnouncementEnum announcementType)
	{
		return InternalDAPlayerClassPointer->Radio(
			playerType,
			announcementID,
			iconID,
			static_cast<::AnnouncementEnum>(announcementType));
	}

	void DAPlayerClass::TeamChange()
	{
		InternalDAPlayerClassPointer->Team_Change();
	}

	int DAPlayerClass::CharacterPurchaseRequest(float %cost, ISoldierGameObjDef ^item)
	{
		float tmpCost = cost;
		::SoldierGameObjDef *itemPtr;

		if (item == nullptr || item->SoldierGameObjDefPointer.ToPointer() == nullptr)
		{
			itemPtr = nullptr;
		}
		else
		{
			itemPtr = reinterpret_cast<::SoldierGameObjDef *>(item->SoldierGameObjDefPointer.ToPointer());
		}

		int result = InternalDAPlayerClassPointer->Character_Purchase_Request(tmpCost, itemPtr);

		cost = tmpCost;

		return result;
	}

	int DAPlayerClass::VehiclePurchaseRequest(float %cost, IVehicleGameObjDef ^item)
	{
		float tmpCost = cost;
		::VehicleGameObjDef *itemPtr;

		if (item == nullptr || item->VehicleGameObjDefPointer.ToPointer() == nullptr)
		{
			itemPtr = nullptr;
		}
		else
		{
			itemPtr = reinterpret_cast<::VehicleGameObjDef *>(item->VehicleGameObjDefPointer.ToPointer());
		}

		int result = InternalDAPlayerClassPointer->Vehicle_Purchase_Request(tmpCost, itemPtr);

		cost = tmpCost;

		return result;
	}

	int DAPlayerClass::PowerUpPurchaseRequest(float %cost, IPowerUpGameObjDef ^item)
	{
		float tmpCost = cost;
		::PowerUpGameObjDef *itemPtr;

		if (item == nullptr || item->PowerUpGameObjDefPointer.ToPointer() == nullptr)
		{
			itemPtr = nullptr;
		}
		else
		{
			itemPtr = reinterpret_cast<::PowerUpGameObjDef *>(item->PowerUpGameObjDefPointer.ToPointer());
		}

		int result = InternalDAPlayerClassPointer->PowerUp_Purchase_Request(tmpCost, itemPtr);

		cost = tmpCost;

		return result;
	}

	int DAPlayerClass::CustomPurchaseRequest(float %cost, unsigned int id)
	{
		float tmpCost = cost;

		int result = InternalDAPlayerClassPointer->Custom_Purchase_Request(tmpCost, id);

		cost = tmpCost;

		return result;
	}

	void DAPlayerClass::CharacterPurchase(float cost, ISoldierGameObjDef ^item)
	{
		if (item == nullptr || item->SoldierGameObjDefPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerClassPointer->Character_Purchase(
				cost,
				nullptr);
		}
		else
		{
			InternalDAPlayerClassPointer->Character_Purchase(
				cost,
				reinterpret_cast<::SoldierGameObjDef *>(item->SoldierGameObjDefPointer.ToPointer()));
		}
	}

	void DAPlayerClass::VehiclePurchase(float cost, IVehicleGameObjDef ^item)
	{
		if (item == nullptr || item->VehicleGameObjDefPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerClassPointer->Vehicle_Purchase(
				cost,
				nullptr);
		}
		else
		{
			InternalDAPlayerClassPointer->Vehicle_Purchase(
				cost,
				reinterpret_cast<::VehicleGameObjDef *>(item->VehicleGameObjDefPointer.ToPointer()));
		}
	}

	void DAPlayerClass::PowerUpPurchase(float cost, IPowerUpGameObjDef ^item)
	{
		if (item == nullptr || item->PowerUpGameObjDefPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerClassPointer->PowerUp_Purchase(
				cost,
				nullptr);
		}
		else
		{
			InternalDAPlayerClassPointer->PowerUp_Purchase(
				cost,
				reinterpret_cast<::PowerUpGameObjDef *>(item->PowerUpGameObjDefPointer.ToPointer()));
		}
	}

	void DAPlayerClass::CustomPurchase(float cost, unsigned int id)
	{
		InternalDAPlayerClassPointer->Custom_Purchase(cost, id);
	}

	bool DAPlayerClass::VehicleEntryRequest(IVehicleGameObj ^vehicle, int %seat)
	{
		::VehicleGameObj *vehiclePtr;
		int tmpSeat = seat;

		if (vehicle == nullptr || vehicle->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			vehiclePtr = nullptr;
		}
		else
		{
			vehiclePtr = reinterpret_cast<::VehicleGameObj *>(vehicle->VehicleGameObjPointer.ToPointer());
		}

		bool result = InternalDAPlayerClassPointer->Vehicle_Entry_Request(vehiclePtr, tmpSeat);

		seat = tmpSeat;

		return result;
	}

	void DAPlayerClass::VehicleEnter(IVehicleGameObj ^vehicle, int seat)
	{
		if (vehicle == nullptr || vehicle->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerClassPointer->Vehicle_Enter(nullptr, seat);
		}
		else
		{
			InternalDAPlayerClassPointer->Vehicle_Enter(
				reinterpret_cast<::VehicleGameObj *>(vehicle->VehicleGameObjPointer.ToPointer()),
				seat);
		}
	}

	void DAPlayerClass::VehicleExit(IVehicleGameObj ^vehicle, int seat)
	{
		if (vehicle == nullptr || vehicle->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerClassPointer->Vehicle_Exit(nullptr, seat);
		}
		else
		{
			InternalDAPlayerClassPointer->Vehicle_Exit(
				reinterpret_cast<::VehicleGameObj *>(vehicle->VehicleGameObjPointer.ToPointer()),
				seat);
		}
	}

	bool DAPlayerClass::PowerUpGrantRequest(IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj)
	{
		::PowerUpGameObjDef *powerUpPtr;
		::PowerUpGameObj *powerUpObjPtr;

		if (powerUp == nullptr || powerUp->PowerUpGameObjDefPointer.ToPointer() == nullptr)
		{
			powerUpPtr = nullptr;
		}
		else
		{
			powerUpPtr = reinterpret_cast<::PowerUpGameObjDef *>(powerUp->PowerUpGameObjDefPointer.ToPointer());
		}

		if (powerUpObj == nullptr || powerUpObj->PowerUpGameObjPointer.ToPointer() == nullptr)
		{
			powerUpObjPtr = nullptr;
		}
		else
		{
			powerUpObjPtr = reinterpret_cast<::PowerUpGameObj *>(powerUpObj->PowerUpGameObjPointer.ToPointer());
		}

		return InternalDAPlayerClassPointer->PowerUp_Grant_Request(powerUpPtr, powerUpObjPtr);
	}

	void DAPlayerClass::PowerUpGrant(IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj)
	{
		::PowerUpGameObjDef *powerUpPtr;
		::PowerUpGameObj *powerUpObjPtr;

		if (powerUp == nullptr || powerUp->PowerUpGameObjDefPointer.ToPointer() == nullptr)
		{
			powerUpPtr = nullptr;
		}
		else
		{
			powerUpPtr = reinterpret_cast<::PowerUpGameObjDef *>(powerUp->PowerUpGameObjDefPointer.ToPointer());
		}

		if (powerUpObj == nullptr || powerUpObj->PowerUpGameObjPointer.ToPointer() == nullptr)
		{
			powerUpObjPtr = nullptr;
		}
		else
		{
			powerUpObjPtr = reinterpret_cast<::PowerUpGameObj *>(powerUpObj->PowerUpGameObjPointer.ToPointer());
		}

		InternalDAPlayerClassPointer->PowerUp_Grant(powerUpPtr, powerUpObjPtr);
	}

	bool DAPlayerClass::AddWeaponRequest(IWeaponDefinitionClass ^weapon)
	{
		if (weapon == nullptr || weapon->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			return InternalDAPlayerClassPointer->Add_Weapon_Request(nullptr);
		}
		else
		{
			return InternalDAPlayerClassPointer->Add_Weapon_Request(
				reinterpret_cast<::WeaponDefinitionClass *>(weapon->WeaponDefinitionClassPointer.ToPointer()));
		}
	}

	void DAPlayerClass::AddWeapon(IWeaponClass ^weapon)
	{
		if (weapon == nullptr || weapon->WeaponClassPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerClassPointer->Add_Weapon(nullptr);
		}
		else
		{
			InternalDAPlayerClassPointer->Add_Weapon(
				reinterpret_cast<::WeaponClass *>(weapon->WeaponClassPointer.ToPointer()));
		}
	}

	void DAPlayerClass::RemoveWeapon(IWeaponClass ^weapon)
	{
		if (weapon == nullptr || weapon->WeaponClassPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerClassPointer->Remove_Weapon(nullptr);
		}
		else
		{
			InternalDAPlayerClassPointer->Remove_Weapon(
				reinterpret_cast<::WeaponClass *>(weapon->WeaponClassPointer.ToPointer()));
		}
	}

	void DAPlayerClass::ClearWeapons()
	{
		InternalDAPlayerClassPointer->Clear_Weapons();
	}

	bool DAPlayerClass::C4DetonateRequest(IC4GameObj ^c4)
	{
		if (c4 == nullptr || c4->C4GameObjPointer.ToPointer() == nullptr)
		{
			return InternalDAPlayerClassPointer->C4_Detonate_Request(nullptr);
		}
		else
		{
			return InternalDAPlayerClassPointer->C4_Detonate_Request(
				reinterpret_cast<::C4GameObj *>(c4->C4GameObjPointer.ToPointer()));
		}
	}

	void DAPlayerClass::C4Detonate(IC4GameObj ^c4)
	{
		if (c4 == nullptr || c4->C4GameObjPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerClassPointer->C4_Detonate(nullptr);
		}
		else
		{
			InternalDAPlayerClassPointer->C4_Detonate(
				reinterpret_cast<::C4GameObj *>(c4->C4GameObjPointer.ToPointer()));
		}
	}

	void DAPlayerClass::ChangeCharacter(ISoldierGameObjDef ^soldier)
	{
		if (soldier == nullptr || soldier->SoldierGameObjDefPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerClassPointer->Change_Character(nullptr);
		}
		else
		{
			InternalDAPlayerClassPointer->Change_Character(
				reinterpret_cast<::SoldierGameObjDef *>(soldier->SoldierGameObjDefPointer.ToPointer()));
		}
	}

	void DAPlayerClass::Created()
	{
		InternalDAPlayerClassPointer->Created();
	}

	void DAPlayerClass::Destroyed()
	{
		InternalDAPlayerClassPointer->Destroyed();
	}

	bool DAPlayerClass::DamageDealtRequest(IDamageableGameObj ^victim, float %damage, unsigned int %warhead, float scale, DADamageType type)
	{
		::DamageableGameObj *victimPtr;
		float tmpDamage = damage;
		unsigned int tmpWarhead = warhead;

		if (victim == nullptr || victim->DamageableGameObjPointer.ToPointer())
		{
			victimPtr = nullptr;
		}
		else
		{
			victimPtr = reinterpret_cast<::DamageableGameObj *>(victim->DamageableGameObjPointer.ToPointer());
		}

		bool result = InternalDAPlayerClassPointer->Damage_Dealt_Request(
			victimPtr,
			tmpDamage,
			tmpWarhead,
			scale,
			static_cast<::DADamageType::Type>(type));

		damage = tmpDamage;
		warhead = tmpWarhead;

		return result;
	}

	bool DAPlayerClass::DamageReceivedRequest(IArmedGameObj ^damager, float %damage, unsigned int %warhead, float scale, DADamageType type)
	{
		::ArmedGameObj *damagerPtr;
		float tmpDamage = damage;
		unsigned int tmpWarhead = warhead;

		if (damager == nullptr || damager->ArmedGameObjPointer.ToPointer() == nullptr)
		{
			damagerPtr = nullptr;
		}
		else
		{
			damagerPtr = reinterpret_cast<::ArmedGameObj *>(damager->ArmedGameObjPointer.ToPointer());
		}

		bool result = InternalDAPlayerClassPointer->Damage_Received_Request(
			damagerPtr,
			tmpDamage,
			tmpWarhead,
			scale,
			static_cast<::DADamageType::Type>(type));

		damage = tmpDamage;
		warhead = tmpWarhead;

		return result;
	}

	void DAPlayerClass::DamageDealt(IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type)
	{
		::DamageableGameObj *victimPtr;

		if (victim == nullptr || victim->DamageableGameObjPointer.ToPointer())
		{
			victimPtr = nullptr;
		}
		else
		{
			victimPtr = reinterpret_cast<::DamageableGameObj *>(victim->DamageableGameObjPointer.ToPointer());
		}

		InternalDAPlayerClassPointer->Damage_Dealt(
			victimPtr,
			damage,
			warhead,
			scale,
			static_cast<::DADamageType::Type>(type));
	}

	void DAPlayerClass::DamageReceived(IArmedGameObj ^damager, float damage, unsigned int warhead, float scale, DADamageType type)
	{
		::ArmedGameObj *damagerPtr;

		if (damager == nullptr || damager->ArmedGameObjPointer.ToPointer() == nullptr)
		{
			damagerPtr = nullptr;
		}
		else
		{
			damagerPtr = reinterpret_cast<::ArmedGameObj *>(damager->ArmedGameObjPointer.ToPointer());
		}

		InternalDAPlayerClassPointer->Damage_Received(
			damagerPtr,
			damage,
			warhead,
			scale,
			static_cast<::DADamageType::Type>(type));
	}

	void DAPlayerClass::KillDealt(IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type)
	{
		::DamageableGameObj *victimPtr;

		if (victim == nullptr || victim->DamageableGameObjPointer.ToPointer())
		{
			victimPtr = nullptr;
		}
		else
		{
			victimPtr = reinterpret_cast<::DamageableGameObj *>(victim->DamageableGameObjPointer.ToPointer());
		}

		InternalDAPlayerClassPointer->Kill_Dealt(
			victimPtr,
			damage,
			warhead,
			scale,
			static_cast<::DADamageType::Type>(type));
	}

	void DAPlayerClass::KillReceived(IArmedGameObj ^killer, float damage, unsigned int warhead, float scale, DADamageType type)
	{
		::ArmedGameObj *killerPtr;

		if (killer == nullptr || killer->ArmedGameObjPointer.ToPointer() == nullptr)
		{
			killerPtr = nullptr;
		}
		else
		{
			killerPtr = reinterpret_cast<::ArmedGameObj *>(killer->ArmedGameObjPointer.ToPointer());
		}

		InternalDAPlayerClassPointer->Kill_Received(
			killerPtr,
			damage,
			warhead,
			scale,
			static_cast<::DADamageType::Type>(type));
	}

	void DAPlayerClass::Custom(IScriptableGameObj ^sender, int type, int param)
	{
		if (sender == nullptr || sender->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerClassPointer->Custom(nullptr, type, param);
		}
		else
		{
			InternalDAPlayerClassPointer->Custom(
				reinterpret_cast<::ScriptableGameObj *>(sender->ScriptableGameObjPointer.ToPointer()),
				type,
				param);
		}
	}

	void DAPlayerClass::Poked(IcPlayer ^player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerClassPointer->Poked(nullptr);
		}
		else
		{
			InternalDAPlayerClassPointer->Poked(reinterpret_cast<::cPlayer *>(player->cPlayerPointer.ToPointer()));
		}
	}

	void DAPlayerClass::Think()
	{
		InternalDAPlayerClassPointer->Think();
	}

	IntPtr DAPlayerClass::DAPlayerClassPointer::get()
	{
		return IntPtr(InternalDAPlayerClassPointer);
	}

	IcPlayer ^DAPlayerClass::Owner::get()
	{
		auto result = InternalDAPlayerClassPointer->Get_Owner();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	int DAPlayerClass::ID::get()
	{
		return InternalDAPlayerClassPointer->Get_ID();
	}

	String ^DAPlayerClass::Name::get()
	{
		return gcnew String(InternalDAPlayerClassPointer->Get_Name().Peek_Buffer());
	}

	int DAPlayerClass::Team::get()
	{
		return InternalDAPlayerClassPointer->Get_Team();
	}

	IDynamicVectorClass<IDAPlayerObserverClass ^> ^DAPlayerClass::Observers::get()
	{
		return gcnew DAPlayerObserverClassPtrDynamicVectorClass(
			IntPtr(const_cast<::DynamicVectorClass<::DAPlayerObserverClass *> *>(&InternalDAPlayerClassPointer->Get_Observers())));
	}

	DAAccessLevel DAPlayerClass::AccessLevel::get()
	{
		return static_cast<DAAccessLevel>(InternalDAPlayerClassPointer->Get_Access_Level());
	}

	void DAPlayerClass::AccessLevel::set(DAAccessLevel value)
	{
		InternalDAPlayerClassPointer->Set_Access_Level(static_cast<::DAAccessLevel::Level>(value));
	}

	bool DAPlayerClass::IsMuted::get()
	{
		return InternalDAPlayerClassPointer->Is_Muted();
	}

	void DAPlayerClass::IsMuted::set(bool value)
	{
		InternalDAPlayerClassPointer->Mute(value);
	}

	bool DAPlayerClass::IsBeaconLocked::get()
	{
		return InternalDAPlayerClassPointer->Is_Beacon_Locked();
	}

	void DAPlayerClass::IsBeaconLocked::set(bool value)
	{
		InternalDAPlayerClassPointer->Beacon_Lock(value);
	}

	bool DAPlayerClass::IsC4Locked::get()
	{
		return InternalDAPlayerClassPointer->Is_C4_Locked();
	}

	void DAPlayerClass::IsC4Locked::set(bool value)
	{
		InternalDAPlayerClassPointer->C4_Lock(value);
	}

	float DAPlayerClass::CharacterDiscount::get()
	{
		return InternalDAPlayerClassPointer->Get_Character_Discount();
	}

	void DAPlayerClass::CharacterDiscount::set(float value)
	{
		InternalDAPlayerClassPointer->Set_Character_Discount(value);
	}

	float DAPlayerClass::VehicleDiscount::get()
	{
		return InternalDAPlayerClassPointer->Get_Vehicle_Discount();
	}

	void DAPlayerClass::VehicleDiscount::set(float value)
	{
		InternalDAPlayerClassPointer->Set_Vehicle_Discount(value);
	}

	float DAPlayerClass::PowerUpDiscount::get()
	{
		return InternalDAPlayerClassPointer->Get_PowerUp_Discount();
	}

	void DAPlayerClass::PowerUpDiscount::set(float value)
	{
		InternalDAPlayerClassPointer->Set_PowerUp_Discount(value);
	}

	unsigned long DAPlayerClass::TimeSinceLastTibDamage::get()
	{
		return InternalDAPlayerClassPointer->Get_Time_Since_Last_Tib_Damage();
	}

	bool DAPlayerClass::IsLoaded::get()
	{
		return InternalDAPlayerClassPointer->Is_Loaded();
	}

	void DAPlayerClass::IsLoaded::set(bool value)
	{
		InternalDAPlayerClassPointer->Set_Loaded(value);
	}

	String ^DAPlayerClass::Serial::get()
	{
		return gcnew String(InternalDAPlayerClassPointer->Get_Serial().Peek_Buffer());
	}

	float DAPlayerClass::Version::get()
	{
		return InternalDAPlayerClassPointer->Get_Version();
	}

	void DAPlayerClass::Version::set(float value)
	{
		InternalDAPlayerClassPointer->Set_Version(value);
	}

	unsigned int DAPlayerClass::Revision::get()
	{
		return InternalDAPlayerClassPointer->Get_Revision();
	}

	bool DAPlayerClass::IsTTClient::get()
	{
		return InternalDAPlayerClassPointer->Is_TT_Client();
	}

	bool DAPlayerClass::IsScriptsClient::get()
	{
		return InternalDAPlayerClassPointer->Is_Scripts_Client();
	}

	bool DAPlayerClass::IsStockClient::get()
	{
		return InternalDAPlayerClassPointer->Is_Stock_Client();
	}

	bool DAPlayerClass::UseServerDamage::get()
	{
		return InternalDAPlayerClassPointer->Use_Server_Damage();
	}

	void DAPlayerClass::UseServerDamage::set(bool value)
	{
		InternalDAPlayerClassPointer->Set_Server_Damage(value);
	}

	bool DAPlayerClass::IsSpawning::get()
	{
		return InternalDAPlayerClassPointer->Is_Spawning();
	}

	unsigned long DAPlayerClass::CreationTime::get()
	{
		return InternalDAPlayerClassPointer->Get_Creation_Time();
	}

	bool DAPlayerClass::NeedsTeam::get()
	{
		return InternalDAPlayerClassPointer->Get_Needs_Team();
	}

	void DAPlayerClass::NeedsTeam::set(bool value)
	{
		InternalDAPlayerClassPointer->Set_Needs_Team(value);
	}

	void DAPlayerClass::Shutdown()
	{
		auto tmpManagedPlayerObservers = gcnew Generic::Dictionary<IntPtr, IRenSharpPlayerObserverClass^>(managedPlayerObservers);

		for each (auto observer in tmpManagedPlayerObservers->Values)
		{
#pragma push_macro("delete")
#undef delete

			delete observer;
			observer = nullptr;

#pragma pop_macro("delete")
		}

		tmpManagedPlayerObservers->Clear();
		managedPlayerObservers->Clear();
	}

	void DAPlayerClass::RegisterManagedObserver(IRenSharpPlayerObserverClass^ observer)
	{
		if (observer == nullptr)
		{
			throw gcnew ArgumentNullException("observer");
		}
		else if (!observer->IsAttached)
		{
			throw gcnew ArgumentException("Observer is not attached.");
		}
		else if (Imports::IsShuttingDown())
		{
			throw gcnew NotSupportedException("Engine is shutting down");
		}

		managedPlayerObservers->Add(observer->DAPlayerObserverClassPointer, observer);
	}

	void DAPlayerClass::UnregisterManagedObserver(IRenSharpPlayerObserverClass^ observer)
	{
		if (observer == nullptr)
		{
			throw gcnew ArgumentNullException("observer");
		}

		managedPlayerObservers->Remove(observer->DAPlayerObserverClassPointer);
	}

	::DAPlayerClass *DAPlayerClass::InternalDAPlayerClassPointer::get()
	{
		return reinterpret_cast<::DAPlayerClass *>(Pointer.ToPointer());
	}

	static DAPlayerManager::DAPlayerManager()
	{
		managedPlayerDataFactories = gcnew Generic::Dictionary<IntPtr, IRenSharpPlayerDataFactoryClass^>();
		managedPlayerDatas = gcnew Generic::Dictionary<IntPtr, IRenSharpPlayerDataClass^>();
	}

	DAPlayerManager::DAPlayerManager(IntPtr pointer)
		: DAEventClass(pointer)
	{

	}

	void DAPlayerManager::OnManagedPlayerDataFactoryDestructed(IntPtr factory)
	{
		IRenSharpPlayerDataFactoryClass^ managedPlayerDataFactory = AsManagedPlayerDataFactory(factory);
		if (managedPlayerDataFactory != nullptr && managedPlayerDataFactory->IsAttached)
		{
			managedPlayerDataFactory->DestroyPointer = false;

#pragma push_macro("delete")
#undef delete

			delete managedPlayerDataFactory;
			managedPlayerDataFactory = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool DAPlayerManager::IsManagedPlayerDataFactory(IntPtr factory)
	{
		return managedPlayerDataFactories->ContainsKey(factory);
	}

	bool DAPlayerManager::IsManagedPlayerDataFactory(IDAPlayerDataFactoryClass^ factory)
	{
		if (factory == nullptr || factory->DAPlayerDataFactoryClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}

		return IsManagedPlayerDataFactory(factory->DAPlayerDataFactoryClassPointer);
	}

	IRenSharpPlayerDataFactoryClass^ DAPlayerManager::AsManagedPlayerDataFactory(IntPtr factory)
	{
		IRenSharpPlayerDataFactoryClass^ result = nullptr;
		managedPlayerDataFactories->TryGetValue(factory, result);

		return result;
	}

	IRenSharpPlayerDataFactoryClass^ DAPlayerManager::AsManagedPlayerDataFactory(IDAPlayerDataFactoryClass^ factory)
	{
		if (factory == nullptr || factory->DAPlayerDataFactoryClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}

		return AsManagedPlayerDataFactory(factory->DAPlayerDataFactoryClassPointer);
	}

	void DAPlayerManager::OnManagedPlayerDataDestructed(IntPtr playerData)
	{
		IRenSharpPlayerDataClass^ managedPlayerData = AsManagedPlayerData(playerData);
		if (managedPlayerData != nullptr && managedPlayerData->IsAttached)
		{
			managedPlayerData->DestroyPointer = false;

#pragma push_macro("delete")
#undef delete

			delete managedPlayerData;
			managedPlayerData = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool DAPlayerManager::IsManagedPlayerData(IntPtr playerData)
	{
		return managedPlayerDatas->ContainsKey(playerData);
	}

	bool DAPlayerManager::IsManagedPlayerData(IDAPlayerDataClass^ playerData)
	{
		if (playerData == nullptr || playerData->DAPlayerDataClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("playerData");
		}

		return IsManagedPlayerData(playerData->DAPlayerDataClassPointer);
	}

	IRenSharpPlayerDataClass^ DAPlayerManager::AsManagedPlayerData(IntPtr playerData)
	{
		IRenSharpPlayerDataClass^ result = nullptr;
		managedPlayerDatas->TryGetValue(playerData, result);

		return result;
	}

	IRenSharpPlayerDataClass^ DAPlayerManager::AsManagedPlayerData(IDAPlayerDataClass^ playerData)
	{
		if (playerData == nullptr || playerData->DAPlayerDataClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("playerData");
		}

		return AsManagedPlayerData(playerData->DAPlayerDataClassPointer);
	}

	void DAPlayerManager::AddDataFactory(IDAPlayerDataFactoryClass^ factory)
	{
		if (factory == nullptr || factory->DAPlayerDataFactoryClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}
		else if (factory->IsManagedPlayerDataFactory)
		{
			throw gcnew ArgumentException("Player data factory is already attached.");
		}

		::DAPlayerManager::Add_Data_Factory(
			reinterpret_cast<::DAPlayerDataFactoryClass*>(factory->DAPlayerDataFactoryClassPointer.ToPointer()));
	}

	void DAPlayerManager::RemoveDataFactory(IDAPlayerDataFactoryClass^ factory)
	{
		if (factory == nullptr || factory->DAPlayerDataFactoryClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}

		::DAPlayerManager::Remove_Data_Factory(
			reinterpret_cast<::DAPlayerDataFactoryClass*>(factory->DAPlayerDataFactoryClassPointer.ToPointer()));
	}

	void DAPlayerManager::AddDataFactory(IRenSharpPlayerDataFactoryClass^ factory)
	{
		if (factory == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}
		
		if (!factory->IsAttached)
		{
			factory->AttachToUnmanagedObject();
		}

		if (!factory->IsRegistered)
		{
			factory->RegisterManagedObject();
		}

		::DAPlayerManager::Add_Data_Factory(
			reinterpret_cast<::DAPlayerDataFactoryClass*>(factory->DAPlayerDataFactoryClassPointer.ToPointer()));
	}

	void DAPlayerManager::RemoveDataFactory(IRenSharpPlayerDataFactoryClass^ factory)
	{
		if (factory == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}
		
		if (!factory->IsAttached)
		{
			factory->AttachToUnmanagedObject();
		}

		if (!factory->IsRegistered)
		{
			factory->RegisterManagedObject();
		}

		::DAPlayerManager::Remove_Data_Factory(
			reinterpret_cast<::DAPlayerDataFactoryClass*>(factory->DAPlayerDataFactoryClassPointer.ToPointer()));
	}

	IntPtr DAPlayerManager::DAPlayerManagerPointer::get()
	{
		return IntPtr(InternalDAPlayerManagerPointer);
	}

	bool DAPlayerManager::DisableKillMessages::get()
	{
		return ::DAPlayerManager::Get_Disable_Kill_Messages();
	}

	void DAPlayerManager::DisableKillMessages::set(bool value)
	{
		::DAPlayerManager::Set_Disable_Kill_Messages(value);
	}

	bool DAPlayerManager::DisableKillCounter::get()
	{
		return ::DAPlayerManager::Get_Disable_Kill_Counter();
	}

	void DAPlayerManager::DisableKillCounter::set(bool value)
	{
		::DAPlayerManager::Set_Disable_Kill_Counter(value);
	}

	bool DAPlayerManager::DisableTeamKillCounter::get()
	{
		return ::DAPlayerManager::Get_Disable_Team_Kill_Counter();
	}

	void DAPlayerManager::DisableTeamKillCounter::set(bool value)
	{
		::DAPlayerManager::Set_Disable_Team_Kill_Counter(value);
	}

	bool DAPlayerManager::DisableDeathCounter::get()
	{
		return ::DAPlayerManager::Get_Disable_Death_Counter();
	}

	void DAPlayerManager::DisableDeathCounter::set(bool value)
	{
		::DAPlayerManager::Set_Disable_Death_Counter(value);
	}

	bool DAPlayerManager::DisableTeamDeathCounter::get()
	{
		return ::DAPlayerManager::Get_Disable_Team_Death_Counter();
	}

	void DAPlayerManager::DisableTeamDeathCounter::set(bool value)
	{
		::DAPlayerManager::Set_Disable_Team_Death_Counter(value);
	}

	bool DAPlayerManager::DisableDamagePoints::get()
	{
		return ::DAPlayerManager::Get_Disable_Damage_Points();
	}

	void DAPlayerManager::DisableDamagePoints::set(bool value)
	{
		::DAPlayerManager::Set_Disable_Damage_Points(value);
	}

	bool DAPlayerManager::DisableDeathPoints::get()
	{
		return ::DAPlayerManager::Get_Disable_Death_Points();
	}

	void DAPlayerManager::DisableDeathPoints::set(bool value)
	{
		::DAPlayerManager::Set_Disable_Death_Points(value);
	}

	bool DAPlayerManager::DisableTeamScoreCounter::get()
	{
		return ::DAPlayerManager::Get_Disable_Team_Score_Counter();
	}

	void DAPlayerManager::DisableTeamScoreCounter::set(bool value)
	{
		::DAPlayerManager::Set_Disable_Team_Score_Counter(value);
	}

	float DAPlayerManager::CreditsMultiplier::get()
	{
		return ::DAPlayerManager::Get_Credits_Multiplier();
	}

	void DAPlayerManager::CreditsMultiplier::set(float value)
	{
		::DAPlayerManager::Set_Credits_Multiplier(value);
	}

	void DAPlayerManager::Shutdown()
	{
		auto tmpManagedPlayerDatas = gcnew Generic::Dictionary<IntPtr, IRenSharpPlayerDataClass^>(managedPlayerDatas);

		for each (auto playerData in tmpManagedPlayerDatas->Values)
		{
#pragma push_macro("delete")
#undef delete

			delete playerData;
			playerData = nullptr;

#pragma push_macro("delete")
		}

		tmpManagedPlayerDatas->Clear();
		managedPlayerDatas->Clear();

		auto tmpManagedPlayerDataFactories = gcnew Generic::Dictionary<IntPtr, IRenSharpPlayerDataFactoryClass^>(managedPlayerDataFactories);

		for each (auto playerDataFactory in tmpManagedPlayerDataFactories->Values)
		{
#pragma push_macro("delete")
#undef delete

			delete playerDataFactory;
			playerDataFactory = nullptr;

#pragma push_macro("delete")
		}

		tmpManagedPlayerDataFactories->Clear();
		managedPlayerDataFactories->Clear();
	}

	void DAPlayerManager::RegisterManagedPlayerDataFactory(IRenSharpPlayerDataFactoryClass^ factory)
	{
		if (factory == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}
		else if (!factory->IsAttached)
		{
			throw gcnew ArgumentException("Player data factory is not attached.");
		}
		else if (Imports::IsShuttingDown())
		{
			throw gcnew NotSupportedException("Engine is shutting down");
		}

		managedPlayerDataFactories->Add(factory->DAPlayerDataFactoryClassPointer, factory);
	}

	void DAPlayerManager::RegisterManagedPlayerData(IRenSharpPlayerDataClass^ playerData)
	{
		if (playerData == nullptr)
		{
			throw gcnew ArgumentNullException("playerData");
		}
		else if (!playerData->IsAttached)
		{
			throw gcnew ArgumentException("Player data is not attached");
		}
		else if (Imports::IsShuttingDown())
		{
			throw gcnew NotSupportedException("Engine is shutting down");
		}

		managedPlayerDatas->Add(playerData->DAPlayerDataClassPointer, playerData);
	}

	void DAPlayerManager::UnregisterManagedPlayerDataFactory(IRenSharpPlayerDataFactoryClass^ factory)
	{
		if (factory == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}

		managedPlayerDataFactories->Remove(factory->DAPlayerDataFactoryClassPointer);
	}

	void DAPlayerManager::UnregisterManagedPlayerData(IRenSharpPlayerDataClass^ playerData)
	{
		if (playerData == nullptr)
		{
			throw gcnew ArgumentNullException("playerData");
		}

		managedPlayerDatas->Remove(playerData->DAPlayerDataClassPointer);
	}

	::DAEventClass* DAPlayerManager::InternalDAEventClassPointer::get()
	{
		return InternalDAPlayerManagerPointer;
	}

	::DAPlayerManager* DAPlayerManager::InternalDAPlayerManagerPointer::get()
	{
		return reinterpret_cast<::DAPlayerManager*>(Pointer.ToPointer());
	}
}