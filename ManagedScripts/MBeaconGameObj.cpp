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
#include "MBeaconGameObj.h"

#include "MBeaconGameObjDef.h"
#include "MPlayerDataClass.h"
#include "Mweaponmgr.h"

namespace RenSharp
{
	BeaconGameObj::BeaconGameObj(IntPtr pointer)
		: SimpleGameObj(pointer)
	{

	}

	IBeaconGameObj ^BeaconGameObj::AsBeaconGameObj()
	{
		return this;
	}

	IntPtr BeaconGameObj::BeaconGameObjPointer::get()
	{
		return IntPtr(InternalBeaconGameObjPointer);
	}

	IBeaconGameObjDef ^BeaconGameObj::Definition::get()
	{
		auto result = const_cast<::BeaconGameObjDef *>(&InternalBeaconGameObjPointer->Get_Definition());
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BeaconGameObjDef(IntPtr(result));
		}
	}

	IPlayerDataClass ^BeaconGameObj::PlayerData::get()
	{
		auto result = InternalBeaconGameObjPointer->Get_Player_Data();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PlayerDataClass(IntPtr(result));
		}
	}

	int BeaconGameObj::State::get()
	{
		return InternalBeaconGameObjPointer->Get_State();
	}

	float BeaconGameObj::ArmTime::get()
	{
		return InternalBeaconGameObjPointer->Get_Arm_Time();
	}

	float BeaconGameObj::DetonateTime::get()
	{
		return InternalBeaconGameObjPointer->Get_Detonate_Time();
	}

	IWeaponDefinitionClass ^BeaconGameObj::WeaponDef::get()
	{
		auto result = const_cast<::WeaponDefinitionClass *>(InternalBeaconGameObjPointer->Get_WeaponDef());
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew WeaponDefinitionClass(IntPtr(result));
		}
	}

	::SimpleGameObj *BeaconGameObj::InternalSimpleGameObjPointer::get()
	{
		return InternalBeaconGameObjPointer;
	}

	::BeaconGameObj *BeaconGameObj::InternalBeaconGameObjPointer::get()
	{
		return reinterpret_cast<::BeaconGameObj *>(Pointer.ToPointer());
	}
}