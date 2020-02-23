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
#include "MArmorWarheadManager.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace RenSharp
{
	bool ArmorWarheadManager::IsArmorSoft(unsigned int armor)
	{
		return ::ArmorWarheadManager::Is_Armor_Soft(armor);
	}

	unsigned int ArmorWarheadManager::GetArmorType(String^ name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr namePtr = Marshal::StringToHGlobalAnsi(name);
		try
		{
			return ::ArmorWarheadManager::Get_Armor_Type(reinterpret_cast<const char*>(namePtr.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(namePtr);
		}
	}

	String^ ArmorWarheadManager::GetArmorName(unsigned int type)
	{
		if (type > NumArmorTypes)
		{
			throw gcnew ArgumentOutOfRangeException("type");
		}

		auto result = ::ArmorWarheadManager::Get_Armor_Name(type);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	unsigned int ArmorWarheadManager::GetWarheadType(String^ name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr namePtr = Marshal::StringToHGlobalAnsi(name);
		try
		{
			return ::ArmorWarheadManager::Get_Warhead_Type(reinterpret_cast<const char*>(namePtr.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(namePtr);
		}
	}

	String^ ArmorWarheadManager::GetWarheadName(unsigned int type)
	{
		if (type > NumWarheadTypes)
		{
			throw gcnew ArgumentOutOfRangeException("type");
		}

		auto result = ::ArmorWarheadManager::Get_Warhead_Name(type);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	float ArmorWarheadManager::GetDamageMultiplier(unsigned int armor, unsigned int warhead)
	{
		if (armor > NumArmorTypes)
		{
			throw gcnew ArgumentOutOfRangeException("type");
		}
		else if (warhead > NumWarheadTypes)
		{
			throw gcnew ArgumentOutOfRangeException("type");
		}

		return ::ArmorWarheadManager::Get_Damage_Multiplier(armor, warhead);
	}

	float ArmorWarheadManager::GetShieldAbsorbsion(unsigned int armor, unsigned int warhead)
	{
		if (armor > NumArmorTypes)
		{
			throw gcnew ArgumentOutOfRangeException("type");
		}
		else if (warhead > NumWarheadTypes)
		{
			throw gcnew ArgumentOutOfRangeException("type");
		}

		return ::ArmorWarheadManager::Get_Shield_Absorbsion(armor, warhead);
	}

	ArmorWarheadManager::SpecialDamageType ArmorWarheadManager::GetSpecialDamageType(unsigned int warhead)
	{
		if (warhead > NumWarheadTypes)
		{
			throw gcnew ArgumentOutOfRangeException("type");
		}

		return static_cast<SpecialDamageType>(::ArmorWarheadManager::Get_Special_Damage_Type(warhead));
	}

	float ArmorWarheadManager::GetSpecialDamageProbability(unsigned int warhead)
	{
		if (warhead > NumWarheadTypes)
		{
			throw gcnew ArgumentOutOfRangeException("type");
		}

		return ::ArmorWarheadManager::Get_Special_Damage_Probability(warhead);
	}

	unsigned int ArmorWarheadManager::GetSpecialDamageWarhead(SpecialDamageType type)
	{
		return ::ArmorWarheadManager::Get_Special_Damage_Warhead(static_cast<::ArmorWarheadManager::SpecialDamageType>(type));
	}

	float ArmorWarheadManager::GetSpecialDamageDuration(SpecialDamageType type)
	{
		return ::ArmorWarheadManager::Get_Special_Damage_Duration(static_cast<::ArmorWarheadManager::SpecialDamageType>(type));
	}

	float ArmorWarheadManager::GetSpecialDamageScale(SpecialDamageType type)
	{
		return ::ArmorWarheadManager::Get_Special_Damage_Scale(static_cast<::ArmorWarheadManager::SpecialDamageType>(type));
	}

	String^ ArmorWarheadManager::GetSpecialDamageExplosion(SpecialDamageType type)
	{
		auto result = ::ArmorWarheadManager::Get_Special_Damage_Explosion(static_cast<::ArmorWarheadManager::SpecialDamageType>(type));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	float ArmorWarheadManager::GetVisceroidProbability(unsigned int warhead)
	{
		if (warhead > NumWarheadTypes)
		{
			throw gcnew ArgumentOutOfRangeException("type");
		}

		return ::ArmorWarheadManager::Get_Visceroid_Probability(warhead);
	}

	bool ArmorWarheadManager::IsSkinImpervious(SpecialDamageType type, unsigned int skin)
	{
		return ::ArmorWarheadManager::Is_Skin_Impervious(static_cast<::ArmorWarheadManager::SpecialDamageType>(type), skin);
	}

	unsigned int ArmorWarheadManager::NumArmorTypes::get()
	{
		return static_cast<unsigned int>(::ArmorWarheadManager::Get_Num_Armor_Types());
	}

	unsigned int ArmorWarheadManager::NumWarheadTypes::get()
	{
		return static_cast<unsigned int>(::ArmorWarheadManager::Get_Num_Warhead_Types());
	}
}