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
#include "MPowerUpGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <PowerupGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	PowerUpGameObjDef::PowerUpGameObjDef(IntPtr pointer)
		: SimpleGameObjDef(pointer)
	{

	}

	IntPtr PowerUpGameObjDef::PowerUpGameObjDefPointer::get()
	{
		return IntPtr(InternalPowerUpGameObjDefPointer);
	}

	int PowerUpGameObjDef::GrantShieldType::get()
	{
		return InternalPowerUpGameObjDefPointer->GrantShieldType;
	}

	void PowerUpGameObjDef::GrantShieldType::set(int value)
	{
		InternalPowerUpGameObjDefPointer->GrantShieldType = value;
	}

	float PowerUpGameObjDef::GrantShieldStrength::get()
	{
		return InternalPowerUpGameObjDefPointer->GrantShieldStrength;
	}

	void PowerUpGameObjDef::GrantShieldStrength::set(float value)
	{
		InternalPowerUpGameObjDefPointer->GrantShieldStrength = value;
	}

	float PowerUpGameObjDef::GrantShieldStrengthMax::get()
	{
		return InternalPowerUpGameObjDefPointer->GrantShieldStrengthMax;
	}

	void PowerUpGameObjDef::GrantShieldStrengthMax::set(float value)
	{
		InternalPowerUpGameObjDefPointer->GrantShieldStrengthMax = value;
	}

	float PowerUpGameObjDef::GrantHealth::get()
	{
		return InternalPowerUpGameObjDefPointer->GrantHealth;
	}

	void PowerUpGameObjDef::GrantHealth::set(float value)
	{
		InternalPowerUpGameObjDefPointer->GrantHealth = value;
	}

	float PowerUpGameObjDef::GrantHealthMax::get()
	{
		return InternalPowerUpGameObjDefPointer->GrantHealthMax;
	}

	void PowerUpGameObjDef::GrantHealthMax::set(float value)
	{
		InternalPowerUpGameObjDefPointer->GrantHealthMax = value;
	}

	int PowerUpGameObjDef::GrantWeaponID::get()
	{
		return InternalPowerUpGameObjDefPointer->GrantWeaponID;
	}

	void PowerUpGameObjDef::GrantWeaponID::set(int value)
	{
		InternalPowerUpGameObjDefPointer->GrantWeaponID = value;
	}

	bool PowerUpGameObjDef::GrantWeapon::get()
	{
		return InternalPowerUpGameObjDefPointer->GrantWeapon;
	}

	void PowerUpGameObjDef::GrantWeapon::set(bool value)
	{
		InternalPowerUpGameObjDefPointer->GrantWeapon = value;
	}

	int PowerUpGameObjDef::GrantWeaponRounds::get()
	{
		return InternalPowerUpGameObjDefPointer->GrantWeaponRounds;
	}

	void PowerUpGameObjDef::GrantWeaponRounds::set(int value)
	{
		InternalPowerUpGameObjDefPointer->GrantWeaponRounds = value;
	}

	bool PowerUpGameObjDef::GrantWeaponClips::get()
	{
		return InternalPowerUpGameObjDefPointer->GrantWeaponClips;
	}

	void PowerUpGameObjDef::GrantWeaponClips::set(bool value)
	{
		InternalPowerUpGameObjDefPointer->GrantWeaponClips = value;
	}

	bool PowerUpGameObjDef::Persistent::get()
	{
		return InternalPowerUpGameObjDefPointer->Is_Persistant();
	}

	void PowerUpGameObjDef::Persistent::set(bool value)
	{
		InternalPowerUpGameObjDefPointer->Persistent = value;
	}

	int PowerUpGameObjDef::GrantKey::get()
	{
		return InternalPowerUpGameObjDefPointer->GrantKey;
	}

	void PowerUpGameObjDef::GrantKey::set(int value)
	{
		InternalPowerUpGameObjDefPointer->GrantKey = value;
	}

	bool PowerUpGameObjDef::AlwaysAllowGrant::get()
	{
		return InternalPowerUpGameObjDefPointer->Is_Always_Allow_Grant();
	}

	void PowerUpGameObjDef::AlwaysAllowGrant::set(bool value)
	{
		InternalPowerUpGameObjDefPointer->AlwaysAllowGrant = value;
	}

	int PowerUpGameObjDef::GrantSoundID::get()
	{
		return InternalPowerUpGameObjDefPointer->Get_Grant_Sound();
	}

	void PowerUpGameObjDef::GrantSoundID::set(int value)
	{
		InternalPowerUpGameObjDefPointer->GrantSoundID = value;
	}

	String ^PowerUpGameObjDef::GrantAnimationName::get()
	{
		return gcnew String(InternalPowerUpGameObjDefPointer->GrantAnimationName.Peek_Buffer());
	}

	void PowerUpGameObjDef::GrantAnimationName::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalPowerUpGameObjDefPointer->GrantAnimationName = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	int PowerUpGameObjDef::IdleSoundID::get()
	{
		return InternalPowerUpGameObjDefPointer->IdleSoundID;
	}

	void PowerUpGameObjDef::IdleSoundID::set(int value)
	{
		InternalPowerUpGameObjDefPointer->IdleSoundID = value;
	}

	String ^PowerUpGameObjDef::IdleAnimationName::get()
	{
		return gcnew String(InternalPowerUpGameObjDefPointer->IdleAnimationName.Peek_Buffer());
	}

	void PowerUpGameObjDef::IdleAnimationName::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalPowerUpGameObjDefPointer->IdleAnimationName = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	bool PowerUpGameObjDef::GrantShieldStrengthMaxIsScaled::get()
	{
		return InternalPowerUpGameObjDefPointer->GrantShieldStrengthMaxIsScaled;
	}

	void PowerUpGameObjDef::GrantShieldStrengthMaxIsScaled::set(bool value)
	{
		InternalPowerUpGameObjDefPointer->GrantShieldStrengthMaxIsScaled = value;
	}

	bool PowerUpGameObjDef::GrantHealthMaxIsScaled::get()
	{
		return InternalPowerUpGameObjDefPointer->GrantHealthMaxIsScaled;
	}

	void PowerUpGameObjDef::GrantHealthMaxIsScaled::set(bool value)
	{
		InternalPowerUpGameObjDefPointer->GrantHealthMaxIsScaled = value;
	}

	::SimpleGameObjDef *PowerUpGameObjDef::InternalSimpleGameObjDefPointer::get()
	{
		return InternalPowerUpGameObjDefPointer;
	}

	::PowerUpGameObjDef *PowerUpGameObjDef::InternalPowerUpGameObjDefPointer::get()
	{
		return reinterpret_cast<::PowerUpGameObjDef *>(Pointer.ToPointer());
	}
}