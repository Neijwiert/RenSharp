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
#include "Mda_chatcommand.h"

#include "Imports.h"
#include "MStringClassDynamicVectorClass.h"
#include "McPlayer.h"
#include "Mda_token.h"
#include "RenSharpChatCommandManager.h"
#include "RenSharpKeyHookManager.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_chatcommand.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DAChatCommandClass::DAChatCommandClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool DAChatCommandClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDAChatCommandClass^ otherThis = dynamic_cast<IDAChatCommandClass^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DAChatCommandClassPointer.Equals(otherThis->DAChatCommandClassPointer);
	}

	bool DAChatCommandClass::Activate(IcPlayer^ player, IDATokenClass^ text, TextMessageEnum chatType)
	{
		if (text == nullptr || text->DATokenClassPointer.ToPointer() == nullptr)
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

		return InternalDAChatCommandClassPointer->Activate(
			playerPtr,
			*reinterpret_cast<::DATokenClass*>(text->DATokenClassPointer.ToPointer()),
			static_cast<::TextMessageEnum>(chatType));
	}

	IntPtr DAChatCommandClass::DAChatCommandClassPointer::get()
	{
		return IntPtr(InternalDAChatCommandClassPointer);
	}

	IDynamicVectorClass<String^>^ DAChatCommandClass::Triggers::get()
	{
		return gcnew StringClassDynamicVectorClass(IntPtr(&InternalDAChatCommandClassPointer->Triggers));
	}

	void DAChatCommandClass::Triggers::set(IDynamicVectorClass<String^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalDAChatCommandClassPointer->Triggers = *reinterpret_cast<::DynamicVectorClass<::StringClass>*>(value->Pointer.ToPointer());
	}

	DAAccessLevel DAChatCommandClass::AccessLevel::get()
	{
		return static_cast<DAAccessLevel>(InternalDAChatCommandClassPointer->AccessLevel);
	}

	void DAChatCommandClass::AccessLevel::set(DAAccessLevel value)
	{
		InternalDAChatCommandClassPointer->AccessLevel = static_cast<::DAAccessLevel::Level>(value);
	}

	DAChatType DAChatCommandClass::ChatType::get()
	{
		return static_cast<DAChatType>(InternalDAChatCommandClassPointer->ChatType);
	}

	void DAChatCommandClass::ChatType::set(DAChatType value)
	{
		InternalDAChatCommandClassPointer->ChatType = static_cast<::DAChatType::Type>(value);
	}

	int DAChatCommandClass::Parameters::get()
	{
		return InternalDAChatCommandClassPointer->Parameters;
	}

	void DAChatCommandClass::Parameters::set(int value)
	{
		InternalDAChatCommandClassPointer->Parameters = value;
	}

	bool DAChatCommandClass::InternalDestroyPointer()
	{
		Imports::DestroyDAChatCommandClass(InternalDAChatCommandClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DAChatCommandClass* DAChatCommandClass::InternalDAChatCommandClassPointer::get()
	{
		return reinterpret_cast<::DAChatCommandClass*>(Pointer.ToPointer());
	}

	DAEventChatCommandStruct::DAEventChatCommandStruct()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateDAEventChatCommandStruct()))
	{

	}

	DAEventChatCommandStruct::DAEventChatCommandStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IDAEventChatCommandStruct^>^ DAEventChatCommandStruct::CreateDAEventChatCommandStruct()
	{
		return gcnew UnmanagedContainer<IDAEventChatCommandStruct^>(gcnew DAEventChatCommandStruct());
	}

	bool DAEventChatCommandStruct::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDAEventChatCommandStruct^ otherThis = dynamic_cast<IDAEventChatCommandStruct^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DAEventChatCommandStructPointer.Equals(otherThis->DAEventChatCommandStructPointer);
	}

	bool DAEventChatCommandStruct::Invoke(IDAEventClass^ base, IcPlayer^ player, IDATokenClass^ text, TextMessageEnum chatType)
	{
		if (base == nullptr || base->DAEventClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}
		else if (text == nullptr || text->DATokenClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("text");
		}

		::DAEventClass* basePtr = reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer());
		::cPlayer* playerPtr;

		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		return ((*basePtr).*(InternalDAEventChatCommandStructPointer->Func))(
			playerPtr,
			*reinterpret_cast<::DATokenClass*>(text->DATokenClassPointer.ToPointer()),
			static_cast<::TextMessageEnum>(chatType));
	}

	IntPtr DAEventChatCommandStruct::DAEventChatCommandStructPointer::get()
	{
		return IntPtr(InternalDAEventChatCommandStructPointer);
	}

	IDynamicVectorClass<String^>^ DAEventChatCommandStruct::Triggers::get()
	{
		return gcnew StringClassDynamicVectorClass(IntPtr(&InternalDAEventChatCommandStructPointer->Triggers));
	}

	void DAEventChatCommandStruct::Triggers::set(IDynamicVectorClass<String^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalDAEventChatCommandStructPointer->Triggers = *reinterpret_cast<::DynamicVectorClass<::StringClass>*>(value->Pointer.ToPointer());
	}

	DAAccessLevel DAEventChatCommandStruct::AccessLevel::get()
	{
		return static_cast<DAAccessLevel>(InternalDAEventChatCommandStructPointer->AccessLevel);
	}

	void DAEventChatCommandStruct::AccessLevel::set(DAAccessLevel value)
	{
		InternalDAEventChatCommandStructPointer->AccessLevel = static_cast<::DAAccessLevel::Level>(value);
	}

	DAChatType DAEventChatCommandStruct::ChatType::get()
	{
		return static_cast<DAChatType>(InternalDAEventChatCommandStructPointer->ChatType);
	}

	void DAEventChatCommandStruct::ChatType::set(DAChatType value)
	{
		InternalDAEventChatCommandStructPointer->ChatType = static_cast<::DAChatType::Type>(value);
	}

	int DAEventChatCommandStruct::Parameters::get()
	{
		return InternalDAEventChatCommandStructPointer->Parameters;
	}

	void DAEventChatCommandStruct::Parameters::set(int value)
	{
		InternalDAEventChatCommandStructPointer->Parameters = value;
	}

	IDAEventClass^ DAEventChatCommandStruct::Base::get()
	{
		auto result = InternalDAEventChatCommandStructPointer->Base;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAEventClass(IntPtr(result));
		}
	}

	void DAEventChatCommandStruct::Base::set(IDAEventClass^ value)
	{
		if (value == nullptr || value->DAEventClassPointer.ToPointer() == nullptr)
		{
			InternalDAEventChatCommandStructPointer->Base = nullptr;
		}
		else
		{
			InternalDAEventChatCommandStructPointer->Base =
				reinterpret_cast<::DAEventClass*>(value->DAEventClassPointer.ToPointer());
		}
	}

	bool DAEventChatCommandStruct::InternalDestroyPointer()
	{
		Imports::DestroyDAEventChatCommandStruct(InternalDAEventChatCommandStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DAEventChatCommandStruct* DAEventChatCommandStruct::InternalDAEventChatCommandStructPointer::get()
	{
		return reinterpret_cast<::DAEventChatCommandStruct*>(Pointer.ToPointer());
	}

	DAKeyHookClass::DAKeyHookClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool DAKeyHookClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDAKeyHookClass^ otherThis = dynamic_cast<IDAKeyHookClass^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DAKeyHookClassPointer.Equals(otherThis->DAKeyHookClassPointer);
	}

	void DAKeyHookClass::Activate(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			InternalDAKeyHookClassPointer->Activate(nullptr);
		}
		else
		{
			InternalDAKeyHookClassPointer->Activate(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
		}
	}

	IntPtr DAKeyHookClass::DAKeyHookClassPointer::get()
	{
		return IntPtr(InternalDAKeyHookClassPointer);
	}

	IDynamicVectorClass<String^>^ DAKeyHookClass::Triggers::get()
	{
		return gcnew StringClassDynamicVectorClass(IntPtr(&InternalDAKeyHookClassPointer->Triggers));
	}

	void DAKeyHookClass::Triggers::set(IDynamicVectorClass<String^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalDAKeyHookClassPointer->Triggers = *reinterpret_cast<::DynamicVectorClass<::StringClass>*>(value->Pointer.ToPointer());
	}

	bool DAKeyHookClass::InternalDestroyPointer()
	{
		Imports::DestroyDAKeyHookClass(InternalDAKeyHookClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DAKeyHookClass* DAKeyHookClass::InternalDAKeyHookClassPointer::get()
	{
		return reinterpret_cast<::DAKeyHookClass*>(Pointer.ToPointer());
	}

	DAEventKeyHookStruct::DAEventKeyHookStruct()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateDAEventKeyHookStruct()))
	{

	}

	DAEventKeyHookStruct::DAEventKeyHookStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IDAEventKeyHookStruct^>^ DAEventKeyHookStruct::CreateDAEventKeyHookStruct()
	{
		return gcnew UnmanagedContainer<IDAEventKeyHookStruct^>(gcnew DAEventKeyHookStruct());
	}

	bool DAEventKeyHookStruct::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDAEventKeyHookStruct^ otherThis = dynamic_cast<IDAEventKeyHookStruct^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DAEventKeyHookStructPointer.Equals(otherThis->DAEventKeyHookStructPointer);
	}

	void DAEventKeyHookStruct::Invoke(IDAEventClass^ base, IcPlayer^ player)
	{
		if (base == nullptr || base->DAEventClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}

		::DAEventClass* basePtr = reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer());
		::cPlayer* playerPtr;

		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		return ((*basePtr).*(InternalDAEventKeyHookStructPointer->Func))(playerPtr);
	}

	IntPtr DAEventKeyHookStruct::DAEventKeyHookStructPointer::get()
	{
		return IntPtr(InternalDAEventKeyHookStructPointer);
	}

	IDynamicVectorClass<String^>^ DAEventKeyHookStruct::Triggers::get()
	{
		return gcnew StringClassDynamicVectorClass(IntPtr(&InternalDAEventKeyHookStructPointer->Triggers));
	}

	void DAEventKeyHookStruct::Triggers::set(IDynamicVectorClass<String^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalDAEventKeyHookStructPointer->Triggers = *reinterpret_cast<::DynamicVectorClass<::StringClass>*>(value->Pointer.ToPointer());
	}

	IDAEventClass^ DAEventKeyHookStruct::Base::get()
	{
		auto result = InternalDAEventKeyHookStructPointer->Base;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAEventClass(IntPtr(result));
		}
	}

	void DAEventKeyHookStruct::Base::set(IDAEventClass^ value)
	{
		if (value == nullptr || value->DAEventClassPointer.ToPointer() == nullptr)
		{
			InternalDAEventKeyHookStructPointer->Base = nullptr;
		}
		else
		{
			InternalDAEventKeyHookStructPointer->Base =
				reinterpret_cast<::DAEventClass*>(value->DAEventClassPointer.ToPointer());
		}
	}

	bool DAEventKeyHookStruct::InternalDestroyPointer()
	{
		Imports::DestroyDAEventKeyHookStruct(InternalDAEventKeyHookStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DAEventKeyHookStruct* DAEventKeyHookStruct::InternalDAEventKeyHookStructPointer::get()
	{
		return reinterpret_cast<::DAEventKeyHookStruct*>(Pointer.ToPointer());
	}

	DAChatCommandManager::DAChatCommandManager(IntPtr pointer)
		: DAEventClass(pointer)
	{

	}

	void DAChatCommandManager::RegisterChatCommand(IDAChatCommandClass^ base, String^ triggers, int parameters, DAAccessLevel accessLevel, DAChatType chatType)
	{
		if (base == nullptr || base->DAChatCommandClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}
		else if (triggers == nullptr)
		{
			throw gcnew ArgumentNullException("triggers");
		}

		IntPtr triggersHandle = Marshal::StringToHGlobalAnsi(triggers);
		try
		{
			::DAChatCommandManager::Register_Chat_Command(
				reinterpret_cast<::DAChatCommandClass*>(base->DAChatCommandClassPointer.ToPointer()),
				reinterpret_cast<char*>(triggersHandle.ToPointer()),
				parameters,
				static_cast<::DAAccessLevel::Level>(accessLevel),
				static_cast<::DAChatType::Type>(chatType));
		}
		finally
		{
			Marshal::FreeHGlobal(triggersHandle);
		}
	}

	void DAChatCommandManager::RegisterChatCommand(IDAChatCommandClass^ base, String^ triggers, int parameters, DAAccessLevel accessLevel)
	{
		if (base == nullptr || base->DAChatCommandClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}
		else if (triggers == nullptr)
		{
			throw gcnew ArgumentNullException("triggers");
		}

		IntPtr triggersHandle = Marshal::StringToHGlobalAnsi(triggers);
		try
		{
			::DAChatCommandManager::Register_Chat_Command(
				reinterpret_cast<::DAChatCommandClass*>(base->DAChatCommandClassPointer.ToPointer()),
				reinterpret_cast<char*>(triggersHandle.ToPointer()),
				parameters,
				static_cast<::DAAccessLevel::Level>(accessLevel));
		}
		finally
		{
			Marshal::FreeHGlobal(triggersHandle);
		}
	}

	void DAChatCommandManager::RegisterChatCommand(IDAChatCommandClass^ base, String^ triggers, int parameters)
	{
		if (base == nullptr || base->DAChatCommandClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}
		else if (triggers == nullptr)
		{
			throw gcnew ArgumentNullException("triggers");
		}

		IntPtr triggersHandle = Marshal::StringToHGlobalAnsi(triggers);
		try
		{
			::DAChatCommandManager::Register_Chat_Command(
				reinterpret_cast<::DAChatCommandClass*>(base->DAChatCommandClassPointer.ToPointer()),
				reinterpret_cast<char*>(triggersHandle.ToPointer()),
				parameters);
		}
		finally
		{
			Marshal::FreeHGlobal(triggersHandle);
		}
	}

	void DAChatCommandManager::RegisterChatCommand(IDAChatCommandClass^ base, String^ triggers)
	{
		if (base == nullptr || base->DAChatCommandClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}
		else if (triggers == nullptr)
		{
			throw gcnew ArgumentNullException("triggers");
		}

		IntPtr triggersHandle = Marshal::StringToHGlobalAnsi(triggers);
		try
		{
			::DAChatCommandManager::Register_Chat_Command(
				reinterpret_cast<::DAChatCommandClass*>(base->DAChatCommandClassPointer.ToPointer()),
				reinterpret_cast<char*>(triggersHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(triggersHandle);
		}
	}

	void DAChatCommandManager::RegisterKeyHook(IDAKeyHookClass^ base, String^ triggers)
	{
		if (base == nullptr || base->DAKeyHookClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}
		else if (triggers == nullptr)
		{
			throw gcnew ArgumentNullException("triggers");
		}

		IntPtr triggersHandle = Marshal::StringToHGlobalAnsi(triggers);
		try
		{
			::DAChatCommandManager::Register_Key_Hook(
				reinterpret_cast<::DAKeyHookClass*>(base->DAKeyHookClassPointer.ToPointer()),
				reinterpret_cast<char*>(triggersHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(triggersHandle);
		}
	}

	void DAChatCommandManager::UnregisterChatCommand(String^ trigger)
	{
		if (trigger == nullptr)
		{
			throw gcnew ArgumentNullException("trigger");
		}

		RenSharpChatCommandManager::UnregisterChatCommand(trigger);

		IntPtr triggerHandle = Marshal::StringToHGlobalAnsi(trigger);
		try
		{
			::DAChatCommandManager::Unregister_Chat_Command(
				reinterpret_cast<char*>(triggerHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(triggerHandle);
		}
	}

	void DAChatCommandManager::UnregisterEventChatCommand(IDAEventClass^ base, String^ trigger)
	{
		if (base == nullptr || base->DAEventClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}
		else if (trigger == nullptr)
		{
			throw gcnew ArgumentNullException("trigger");
		}

		IntPtr triggerHandle = Marshal::StringToHGlobalAnsi(trigger);
		try
		{
			::DAChatCommandManager::Unregister_Event_Chat_Command(
				reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer()),
				reinterpret_cast<char*>(triggerHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(triggerHandle);
		}
	}

	void DAChatCommandManager::UnregisterKeyHook(String^ trigger)
	{
		if (trigger == nullptr)
		{
			throw gcnew ArgumentNullException("trigger");
		}

		RenSharpKeyHookManager::UnregisterKeyHook(trigger);

		IntPtr triggerHandle = Marshal::StringToHGlobalAnsi(trigger);
		try
		{
			::DAChatCommandManager::Unregister_Key_Hook(
				reinterpret_cast<char*>(triggerHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(triggerHandle);
		}
	}

	void DAChatCommandManager::UnregisterEventKeyHook(IDAEventClass^ base, String^ trigger)
	{
		if (base == nullptr || base->DAEventClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}
		else if (trigger == nullptr)
		{
			throw gcnew ArgumentNullException("trigger");
		}

		IntPtr triggerHandle = Marshal::StringToHGlobalAnsi(trigger);
		try
		{
			::DAChatCommandManager::Unregister_Event_Key_Hook(
				reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer()),
				reinterpret_cast<char*>(triggerHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(triggerHandle);
		}
	}

	void DAChatCommandManager::ClearEventChatCommands(IDAEventClass^ base)
	{
		if (base == nullptr || base->DAEventClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}

		::DAChatCommandManager::Clear_Event_Chat_Commands(
			reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer()));
	}

	void DAChatCommandManager::ClearEventKeyHooks(IDAEventClass^ base)
	{
		if (base == nullptr || base->DAEventClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("base");
		}

		::DAChatCommandManager::Clear_Event_Key_Hooks(
			reinterpret_cast<::DAEventClass*>(base->DAEventClassPointer.ToPointer()));
	}

	IntPtr DAChatCommandManager::DAChatCommandManagerPointer::get()
	{
		return IntPtr(InternalDAChatCommandManagerPointer);
	}

	::DAEventClass* DAChatCommandManager::InternalDAEventClassPointer::get()
	{
		return InternalDAChatCommandManagerPointer;
	}

	::DAChatCommandManager* DAChatCommandManager::InternalDAChatCommandManagerPointer::get()
	{
		return reinterpret_cast<::DAChatCommandManager*>(Pointer.ToPointer());
	}
}