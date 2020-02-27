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
#include "MPresetMgr.h"

#include "MDefinition.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <PresetMgr.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	PresetMgrClass::PresetMgrClass(IntPtr pointer)
		: SaveLoadSubSystemClass(pointer)
	{

	}

	IPresetClass^ PresetMgrClass::PresetListHead::get()
	{
		auto result = InternalPresetMgrClassPointer->_PresetListHead;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PresetClass(IntPtr(result));
		}
	}

	void PresetMgrClass::PresetListHead::set(IPresetClass^ value)
	{
		::PresetClass* valuePtr;
		if (value == nullptr || value->PresetClassPointer.ToPointer() == nullptr)
		{
			valuePtr = nullptr;
		}
		else
		{
			valuePtr = reinterpret_cast<::PresetClass*>(value->PresetClassPointer.ToPointer());
		}

		InternalPresetMgrClassPointer->_PresetListHead = valuePtr;
	}

	bool PresetMgrClass::PresetsDirty::get()
	{
		return InternalPresetMgrClassPointer->PresetsDirty;
	}

	void PresetMgrClass::PresetsDirty::set(bool value)
	{
		InternalPresetMgrClassPointer->PresetsDirty = value;
	}

	bool PresetMgrClass::ImmedCheckin::get()
	{
		return InternalPresetMgrClassPointer->ImmedCheckin;
	}

	void PresetMgrClass::ImmedCheckin::set(bool value)
	{
		InternalPresetMgrClassPointer->ImmedCheckin = value;
	}

	IntPtr PresetMgrClass::PresetMgrClassPointer::get()
	{
		return IntPtr(InternalPresetMgrClassPointer);
	}

	::SaveLoadSubSystemClass* PresetMgrClass::InternalSaveLoadSubSystemClassPointer::get()
	{
		return InternalPresetMgrClassPointer;
	}

	::PresetMgrClass* PresetMgrClass::InternalPresetMgrClassPointer::get()
	{
		return reinterpret_cast<::PresetMgrClass*>(Pointer.ToPointer());
	}

	PresetClass::PresetClass(IntPtr pointer)
		: PersistClass(pointer)
	{

	}

	IPresetClass^ PresetClass::Next::get()
	{
		auto result = InternalPresetClassPointer->Next();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PresetClass(IntPtr(result));
		}
	}

	void PresetClass::Next::set(IPresetClass^ value)
	{
		::PresetClass* valuePtr;
		if (value == nullptr || value->PresetClassPointer.ToPointer() == nullptr)
		{
			valuePtr = nullptr;
		}
		else
		{
			valuePtr = reinterpret_cast<::PresetClass*>(value->PresetClassPointer.ToPointer());
		}

		InternalPresetClassPointer->Set_Next(valuePtr);
	}

	IPresetClass^ PresetClass::Prev::get()
	{
		auto result = InternalPresetClassPointer->Prev();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PresetClass(IntPtr(result));
		}
	}

	void PresetClass::Prev::set(IPresetClass^ value)
	{
		::PresetClass* valuePtr;
		if (value == nullptr || value->PresetClassPointer.ToPointer() == nullptr)
		{
			valuePtr = nullptr;
		}
		else
		{
			valuePtr = reinterpret_cast<::PresetClass*>(value->PresetClassPointer.ToPointer());
		}

		InternalPresetClassPointer->Set_Prev(valuePtr);
	}

	bool PresetClass::IsGood::get()
	{
		return InternalPresetClassPointer->Is_Good();
	}

	int PresetClass::ChildCount::get()
	{
		return InternalPresetClassPointer->Get_Child_Count();
	}

	IDefinitionClass^ PresetClass::Definition::get()
	{
		auto result = InternalPresetClassPointer->Get_Definition();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DefinitionClass(IntPtr(result));
		}
	}

	IPresetClass^ PresetClass::Parent::get()
	{
		auto result = InternalPresetClassPointer->Get_Parent();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PresetClass(IntPtr(result));
		}
	}

	unsigned int PresetClass::DefinitionId::get()
	{
		return InternalPresetClassPointer->Get_Definition_ID();
	}

	void PresetClass::DefinitionId::set(unsigned int value)
	{
		InternalPresetClassPointer->Set_Definition_ID(value);
	}

	bool PresetClass::IsTemp::get()
	{
		return InternalPresetClassPointer->Is_Temp();
	}

	IntPtr PresetClass::PresetClassPointer::get()
	{
		return IntPtr(InternalPresetClassPointer);
	}

	::PersistClass* PresetClass::InternalPersistClassPointer::get()
	{
		return InternalPresetClassPointer;
	}

	::PresetClass* PresetClass::InternalPresetClassPointer::get()
	{
		return reinterpret_cast<::PresetClass*>(Pointer.ToPointer());
	}
}