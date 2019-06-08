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
#include "MPowerUpGameObj.h"

#include "MSmartGameObj.h"
#include "MPowerUpGameObjDef.h"
#include "MAudibleSoundClass.h"
#include "MWeaponBagClass.h"

namespace RenSharp
{
	PowerUpGameObj::PowerUpGameObj(IntPtr pointer)
		: SimpleGameObj(pointer)
	{

	}

	IPowerUpGameObj ^PowerUpGameObj::AsPowerUpGameObj()
	{
		return this;
	}

	IntPtr PowerUpGameObj::PowerUpGameObjPointer::get()
	{
		return IntPtr(InternalPowerUpGameObjPointer);
	}

	IPowerUpGameObjDef ^PowerUpGameObj::Definition::get()
	{
		return gcnew PowerUpGameObjDef(IntPtr(const_cast<::PowerUpGameObjDef *>(&InternalPowerUpGameObjPointer->Get_Definition())));
	}

	::SimpleGameObj *PowerUpGameObj::InternalSimpleGameObjPointer::get()
	{
		return InternalPowerUpGameObjPointer;
	}

	::PowerUpGameObj *PowerUpGameObj::InternalPowerUpGameObjPointer::get()
	{
		return reinterpret_cast<::PowerUpGameObj *>(Pointer.ToPointer());
	}

	IAudibleSoundClass ^PowerUpGameObj::IdleSoundObj::get()
	{
		auto helper = reinterpret_cast<PowerUpGameObjHelper*>(InternalPowerUpGameObjPointer);

		auto& idleSoundObj = helper->GetIdleSoundObj();

		if (idleSoundObj == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew AudibleSoundClass(IntPtr(idleSoundObj));
		}
	}

	void PowerUpGameObj::IdleSoundObj::set(IAudibleSoundClass ^value)
	{
		auto helper = reinterpret_cast<PowerUpGameObjHelper*>(InternalPowerUpGameObjPointer);

		auto& idleSoundObj = helper->GetIdleSoundObj();

		if (value == nullptr || value->AudibleSoundClassPointer.ToPointer() == nullptr)
		{
			idleSoundObj = nullptr;
		}
		else
		{
			idleSoundObj = reinterpret_cast<::AudibleSoundClass*>(value->AudibleSoundClassPointer.ToPointer());
		}
	}

	int PowerUpGameObj::State::get()
	{
		auto helper = reinterpret_cast<PowerUpGameObjHelper *>(InternalPowerUpGameObjPointer);

		auto &state = helper->GetState();

		return state;
	}

	void PowerUpGameObj::State::set(int value)
	{
		auto helper = reinterpret_cast<PowerUpGameObjHelper *>(InternalPowerUpGameObjPointer);

		auto &state = helper->GetState();

		state = value;
	}

	float PowerUpGameObj::StateEndTimer::get()
	{
		auto helper = reinterpret_cast<PowerUpGameObjHelper *>(InternalPowerUpGameObjPointer);

		auto &stateEndTimer = helper->GetStateEndTimer();

		return stateEndTimer;
	}

	void PowerUpGameObj::StateEndTimer::set(float value)
	{
		auto helper = reinterpret_cast<PowerUpGameObjHelper *>(InternalPowerUpGameObjPointer);

		auto &stateEndTimer = helper->GetStateEndTimer();

		stateEndTimer = value;
	}

	IWeaponBagClass ^PowerUpGameObj::WeaponBag::get()
	{
		auto helper = reinterpret_cast<PowerUpGameObjHelper*>(InternalPowerUpGameObjPointer);

		auto& weaponBag = helper->GetWeaponBag();

		if (weaponBag == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew WeaponBagClass(IntPtr(weaponBag));
		}
	}

	void PowerUpGameObj::WeaponBag::set(IWeaponBagClass ^value)
	{
		auto helper = reinterpret_cast<PowerUpGameObjHelper*>(InternalPowerUpGameObjPointer);

		auto& weaponBag = helper->GetWeaponBag();

		if (value == nullptr || value->WeaponBagClassPointer.ToPointer() == nullptr)
		{
			weaponBag = nullptr;
		}
		else
		{
			weaponBag = reinterpret_cast<::WeaponBagClass*>(value->WeaponBagClassPointer.ToPointer());
		}
	}
}