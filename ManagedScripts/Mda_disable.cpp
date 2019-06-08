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
#include "Mda_disable.h"

#include "MConstDefinitionClassPtrDynamicVectorClass.h"
#include "MDefinition.h"
#include "Imports.h"
#include "UnmanagedContainer.h"
#include "MScriptableGameObj.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_disable.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DACharacterDisableListStruct::DACharacterDisableListStruct()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateDACharacterDisableListStruct()))
	{

	}

	DACharacterDisableListStruct::DACharacterDisableListStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IDACharacterDisableListStruct^>^ DACharacterDisableListStruct::CreateDACharacterDisableListStruct()
	{
		return gcnew UnmanagedContainer<IDACharacterDisableListStruct^>(gcnew DACharacterDisableListStruct());
	}

	bool DACharacterDisableListStruct::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDACharacterDisableListStruct^ otherThis = dynamic_cast<IDACharacterDisableListStruct^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DACharacterDisableListStructPointer.Equals(otherThis->DACharacterDisableListStructPointer);
	}

	IntPtr DACharacterDisableListStruct::DACharacterDisableListStructPointer::get()
	{
		return IntPtr(InternalDACharacterDisableListStructPointer);
	}

	IDynamicVectorClass<IDefinitionClass^>^ DACharacterDisableListStruct::DisableList::get()
	{
		return gcnew ConstDefinitionClassPtrDynamicVectorClass(IntPtr(&InternalDACharacterDisableListStructPointer->DisableList));
	}

	void DACharacterDisableListStruct::DisableList::set(IDynamicVectorClass<IDefinitionClass^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalDACharacterDisableListStructPointer->DisableList =
			*reinterpret_cast<::DynamicVectorClass<const ::DefinitionClass*>*>(value->Pointer.ToPointer());
	}

	bool DACharacterDisableListStruct::EnterVehicles::get()
	{
		return InternalDACharacterDisableListStructPointer->EnterVehicles;
	}

	void DACharacterDisableListStruct::EnterVehicles::set(bool value)
	{
		InternalDACharacterDisableListStructPointer->EnterVehicles = value;
	}

	bool DACharacterDisableListStruct::DriveVehicles::get()
	{
		return InternalDACharacterDisableListStructPointer->DriveVehicles;
	}

	void DACharacterDisableListStruct::DriveVehicles::set(bool value)
	{
		InternalDACharacterDisableListStructPointer->DriveVehicles = value;
	}

	bool DACharacterDisableListStruct::StealVehicles::get()
	{
		return InternalDACharacterDisableListStructPointer->StealVehicles;
	}

	void DACharacterDisableListStruct::StealVehicles::set(bool value)
	{
		InternalDACharacterDisableListStructPointer->StealVehicles = value;
	}

	bool DACharacterDisableListStruct::InternalDestroyPointer()
	{
		Imports::DestroyDACharacterDisableListStruct(InternalDACharacterDisableListStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DACharacterDisableListStruct* DACharacterDisableListStruct::InternalDACharacterDisableListStructPointer::get()
	{
		return reinterpret_cast<::DACharacterDisableListStruct*>(Pointer.ToPointer());
	}

	DADisableListManager::DADisableListManager(IntPtr pointer)
		: DAEventClass(pointer)
	{

	}

	bool DADisableListManager::IsPresetDisabled(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::DADisableListManager::Is_Preset_Disabled(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool DADisableListManager::IsPresetDisabled(String^ preset)
	{
		if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			return ::DADisableListManager::Is_Preset_Disabled(
				reinterpret_cast<char*>(presetHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(presetHandle);
		}
	}

	bool DADisableListManager::IsPresetDisabled(IDefinitionClass^ def)
	{
		if (def == nullptr || def->DefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("def");
		}

		return ::DADisableListManager::Is_Preset_Disabled(
			reinterpret_cast<::DefinitionClass*>(def->DefinitionClassPointer.ToPointer()));
	}

	bool DADisableListManager::IsPresetDisabled(unsigned int defID)
	{
		return ::DADisableListManager::Is_Preset_Disabled(defID);
	}

	bool DADisableListManager::IsPresetDisabledForCharacter(IDefinitionClass^ character, IDefinitionClass^ def)
	{
		if (character == nullptr || character->DefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("character");
		}
		else if (def == nullptr || def->DefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("def");
		}

		return ::DADisableListManager::Is_Preset_Disabled_For_Character(
			reinterpret_cast<::DefinitionClass*>(character->DefinitionClassPointer.ToPointer()),
			reinterpret_cast<::DefinitionClass*>(def->DefinitionClassPointer.ToPointer()));
	}

	bool DADisableListManager::IsPresetDisabledForCharacter(IDefinitionClass^ character, String^ preset)
	{
		if (character == nullptr || character->DefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("character");
		}
		else if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			return ::DADisableListManager::Is_Preset_Disabled_For_Character(
				reinterpret_cast<::DefinitionClass*>(character->DefinitionClassPointer.ToPointer()),
				reinterpret_cast<char*>(presetHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(presetHandle);
		}
	}

	bool DADisableListManager::IsPresetDisabledForCharacter(IDefinitionClass^ character, unsigned int defID)
	{
		if (character == nullptr || character->DefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("character");
		}

		return ::DADisableListManager::Is_Preset_Disabled_For_Character(
			reinterpret_cast<::DefinitionClass*>(character->DefinitionClassPointer.ToPointer()),
			defID);
	}

	bool DADisableListManager::CanCharacterEnterVehicles(IDefinitionClass^ character)
	{
		if (character == nullptr || character->DefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("character");
		}

		return ::DADisableListManager::Can_Character_Enter_Vehicles(
			reinterpret_cast<::DefinitionClass*>(character->DefinitionClassPointer.ToPointer()));
	}

	bool DADisableListManager::CanCharacterDriveVehicles(IDefinitionClass^ character)
	{
		if (character == nullptr || character->DefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("character");
		}

		return ::DADisableListManager::Can_Character_Drive_Vehicles(
			reinterpret_cast<::DefinitionClass*>(character->DefinitionClassPointer.ToPointer()));
	}

	bool DADisableListManager::CanCharacterStealVehicles(IDefinitionClass^ character)
	{
		if (character == nullptr || character->DefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("character");
		}

		return ::DADisableListManager::Can_Character_Steal_Vehicles(
			reinterpret_cast<::DefinitionClass*>(character->DefinitionClassPointer.ToPointer()));
	}

	IntPtr DADisableListManager::DADisableListManagerPointer::get()
	{
		return IntPtr(InternalDADisableListManagerPointer);
	}

	::DAEventClass* DADisableListManager::InternalDAEventClassPointer::get()
	{
		return InternalDADisableListManagerPointer;
	}

	::DADisableListManager* DADisableListManager::InternalDADisableListManagerPointer::get()
	{
		return reinterpret_cast<::DADisableListManager*>(Pointer.ToPointer());
	}
}