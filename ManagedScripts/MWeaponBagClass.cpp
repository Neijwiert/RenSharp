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
#include "MWeaponBagClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <WeaponBagClass.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MWeaponClass.h"
#include "Mweaponmgr.h"
#include "MArmedGameObj.h"

namespace RenSharp
{
	WeaponBagClass::WeaponBagClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool WeaponBagClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IWeaponBagClass ^otherThis = dynamic_cast<IWeaponBagClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return WeaponBagClassPointer.Equals(otherThis->WeaponBagClassPointer);
	}

	IWeaponClass ^WeaponBagClass::AddWeapon(IWeaponDefinitionClass ^def, int rounds, bool giveWeapon)
	{
		if (def == nullptr || def->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("def");
		}

		auto result = InternalWeaponBagClassPointer->Add_Weapon(
			reinterpret_cast<::WeaponDefinitionClass *>(def->WeaponDefinitionClassPointer.ToPointer()),
			rounds,
			giveWeapon);

		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew WeaponClass(IntPtr(result));
		}
	}

	IWeaponClass ^WeaponBagClass::AddWeapon(IWeaponDefinitionClass ^def, int rounds)
	{
		if (def == nullptr || def->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("def");
		}

		auto result = InternalWeaponBagClassPointer->Add_Weapon(
			reinterpret_cast<::WeaponDefinitionClass *>(def->WeaponDefinitionClassPointer.ToPointer()),
			rounds);

		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew WeaponClass(IntPtr(result));
		}
	}

	IWeaponClass ^WeaponBagClass::AddWeapon(IWeaponDefinitionClass ^def)
	{
		if (def == nullptr || def->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("def");
		}

		auto result = InternalWeaponBagClassPointer->Add_Weapon(
			reinterpret_cast<::WeaponDefinitionClass *>(def->WeaponDefinitionClassPointer.ToPointer()));

		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew WeaponClass(IntPtr(result));
		}
	}

	IWeaponClass ^WeaponBagClass::AddWeapon(int id, int rounds, bool giveWeapon)
	{
		auto result = InternalWeaponBagClassPointer->Add_Weapon(id, rounds, giveWeapon);

		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew WeaponClass(IntPtr(result));
		}
	}

	IWeaponClass ^WeaponBagClass::AddWeapon(int id, int rounds)
	{
		auto result = InternalWeaponBagClassPointer->Add_Weapon(id, rounds);

		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew WeaponClass(IntPtr(result));
		}
	}

	IWeaponClass ^WeaponBagClass::AddWeapon(int id)
	{
		auto result = InternalWeaponBagClassPointer->Add_Weapon(id);

		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew WeaponClass(IntPtr(result));
		}
	}

	IWeaponClass ^WeaponBagClass::AddWeapon(String ^weaponName, int rounds, bool giveWeapon)
	{
		if (weaponName == nullptr)
		{
			throw gcnew ArgumentNullException("weaponName");
		}

		IntPtr weaponNameHandle = Marshal::StringToHGlobalAnsi(weaponName);
		try
		{
			auto result = InternalWeaponBagClassPointer->Add_Weapon(reinterpret_cast<char *>(weaponNameHandle.ToPointer()), rounds, giveWeapon);

			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew WeaponClass(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(weaponNameHandle);
		}
	}

	IWeaponClass ^WeaponBagClass::AddWeapon(String ^weaponName, int rounds)
	{
		if (weaponName == nullptr)
		{
			throw gcnew ArgumentNullException("weaponName");
		}

		IntPtr weaponNameHandle = Marshal::StringToHGlobalAnsi(weaponName);
		try
		{
			auto result = InternalWeaponBagClassPointer->Add_Weapon(reinterpret_cast<char *>(weaponNameHandle.ToPointer()), rounds);

			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew WeaponClass(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(weaponNameHandle);
		}
	}

	IWeaponClass ^WeaponBagClass::AddWeapon(String ^weaponName)
	{
		if (weaponName == nullptr)
		{
			throw gcnew ArgumentNullException("weaponName");
		}

		IntPtr weaponNameHandle = Marshal::StringToHGlobalAnsi(weaponName);
		try
		{
			auto result = InternalWeaponBagClassPointer->Add_Weapon(reinterpret_cast<char *>(weaponNameHandle.ToPointer()));

			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew WeaponClass(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(weaponNameHandle);
		}
	}

	void WeaponBagClass::RemoveWeapon(int index)
	{
		InternalWeaponBagClassPointer->Remove_Weapon(index);
	}

	void WeaponBagClass::RemoveWeapon(IWeaponDefinitionClass ^weaponDef)
	{
		if (weaponDef == nullptr)
		{
			throw gcnew ArgumentNullException("weaponDef");
		}

		InternalWeaponBagClassPointer->Remove_Weapon(reinterpret_cast<::WeaponDefinitionClass *>(weaponDef->WeaponDefinitionClassPointer.ToPointer()));
	}

	void WeaponBagClass::RemoveWeapon(String ^weapon)
	{
		if (weapon == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		IntPtr weaponHandle = Marshal::StringToHGlobalAnsi(weapon);
		try
		{
			InternalWeaponBagClassPointer->Remove_Weapon(reinterpret_cast<char *>(weaponHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(weaponHandle);
		}
	}

	void WeaponBagClass::RemoveWeapon(unsigned int weaponDefId)
	{
		InternalWeaponBagClassPointer->Remove_Weapon(weaponDefId);
	}

	void WeaponBagClass::ClearWeapons()
	{
		InternalWeaponBagClassPointer->Clear_Weapons();
	}

	IWeaponClass ^WeaponBagClass::PeekWeapon(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalWeaponBagClassPointer->Peek_Weapon(index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew WeaponClass(IntPtr(result));
		}
	}

	IWeaponClass ^WeaponBagClass::GetWeapon()
	{
		auto result = InternalWeaponBagClassPointer->Get_Weapon();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew WeaponClass(IntPtr(result));
		}
	}

	void WeaponBagClass::SelectIndex(int index)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		InternalWeaponBagClassPointer->Select_Index(index);
	}

	void WeaponBagClass::SelectNext()
	{
		InternalWeaponBagClassPointer->Select_Next();
	}

	void WeaponBagClass::SelectPrev()
	{
		InternalWeaponBagClassPointer->Select_Prev();
	}

	void WeaponBagClass::SelectWeapon(IWeaponClass ^weapon)
	{
		if (weapon == nullptr || weapon->WeaponClassPointer.ToPointer() == nullptr)
		{
			InternalWeaponBagClassPointer->Select_Weapon(nullptr);
		}
		else
		{
			InternalWeaponBagClassPointer->Select_Weapon(reinterpret_cast<::WeaponClass *>(weapon->WeaponClassPointer.ToPointer()));
		}
	}

	void WeaponBagClass::SelectWeaponID(int weaponId)
	{
		InternalWeaponBagClassPointer->Select_Weapon_ID(weaponId);
	}

	void WeaponBagClass::SelectWeaponName(String ^name)
	{
		if (name == nullptr)
		{
			InternalWeaponBagClassPointer->Select_Weapon_Name(nullptr);
		}
		else
		{
			IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
			try
			{
				InternalWeaponBagClassPointer->Select_Weapon_Name(reinterpret_cast<char *>(nameHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(nameHandle);
			}
		}
	}

	void WeaponBagClass::ForceChanged()
	{
		InternalWeaponBagClassPointer->Force_Changed();
	}

	void WeaponBagClass::ResetChanged()
	{
		InternalWeaponBagClassPointer->Reset_Changed();
	}

	void WeaponBagClass::HUDResetChanged()
	{
		InternalWeaponBagClassPointer->HUD_Reset_Changed();
	}

	IWeaponClass ^WeaponBagClass::FindWeapon(IWeaponDefinitionClass ^weaponDef)
	{
		if (weaponDef == nullptr || weaponDef->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("weaponDef");
		}

		auto result = InternalWeaponBagClassPointer->Find_Weapon(reinterpret_cast<::WeaponDefinitionClass *>(weaponDef->WeaponDefinitionClassPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew WeaponClass(IntPtr(result));
		}
	}

	IWeaponClass ^WeaponBagClass::FindWeapon(String ^weapon)
	{
		if (weapon == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		IntPtr weaponHandle = Marshal::StringToHGlobalAnsi(weapon);
		try
		{
			auto result = InternalWeaponBagClassPointer->Find_Weapon(reinterpret_cast<char *>(weaponHandle.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew WeaponClass(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(weaponHandle);
		}
	}

	IWeaponClass ^WeaponBagClass::FindWeapon(unsigned int weaponDefID)
	{
		auto result = InternalWeaponBagClassPointer->Find_Weapon(weaponDefID);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew WeaponClass(IntPtr(result));
		}
	}

	int WeaponBagClass::GetWeaponPosition(IWeaponDefinitionClass ^weaponDef)
	{
		if (weaponDef == nullptr || weaponDef->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("weaponDef");
		}

		return InternalWeaponBagClassPointer->Get_Weapon_Position(reinterpret_cast<::WeaponDefinitionClass *>(weaponDef->WeaponDefinitionClassPointer.ToPointer()));
	}

	int WeaponBagClass::GetWeaponPosition(String ^weapon)
	{
		if (weapon == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		IntPtr weaponHandle = Marshal::StringToHGlobalAnsi(weapon);
		try
		{
			return InternalWeaponBagClassPointer->Get_Weapon_Position(reinterpret_cast<char *>(weaponHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(weaponHandle);
		}
	}

	int WeaponBagClass::GetWeaponPosition(unsigned int weaponDefID)
	{
		return InternalWeaponBagClassPointer->Get_Weapon_Position(weaponDefID);
	}

	int WeaponBagClass::GetWeaponPosition(IWeaponClass ^weapon)
	{
		if (weapon == nullptr || weapon->WeaponClassPointer.ToPointer() == nullptr)
		{
			return InternalWeaponBagClassPointer->Get_Weapon_Position(static_cast<::WeaponClass *>(nullptr));
		}
		else
		{
			return InternalWeaponBagClassPointer->Get_Weapon_Position(reinterpret_cast<::WeaponClass *>(weapon->WeaponClassPointer.ToPointer()));
		}
	}

	IntPtr WeaponBagClass::WeaponBagClassPointer::get()
	{
		return IntPtr(InternalWeaponBagClassPointer);
	}

	int WeaponBagClass::Count::get()
	{
		return InternalWeaponBagClassPointer->Get_Count();
	}

	int WeaponBagClass::Index::get()
	{
		return InternalWeaponBagClassPointer->Get_Index();
	}

	bool WeaponBagClass::IsChanged::get()
	{
		return InternalWeaponBagClassPointer->Is_Changed();
	}

	bool WeaponBagClass::HUDIsChanged::get()
	{
		return InternalWeaponBagClassPointer->HUD_Is_Changed();
	}

	IArmedGameObj ^WeaponBagClass::Owner::get()
	{
		auto result = InternalWeaponBagClassPointer->Get_Owner();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ArmedGameObj(IntPtr(result));
		}
	}

	bool WeaponBagClass::OwnerInitialized::get()
	{
		return InternalWeaponBagClassPointer->Is_Owner_Initialized();
	}

	void WeaponBagClass::OwnerInitialized::set(bool value)
	{
		InternalWeaponBagClassPointer->Owner_Initialized(value);
	}

	::WeaponBagClass *WeaponBagClass::InternalWeaponBagClassPointer::get()
	{
		return reinterpret_cast<::WeaponBagClass *>(Pointer.ToPointer());
	}
}