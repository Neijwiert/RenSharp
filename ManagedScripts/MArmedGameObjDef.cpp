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
#include "MArmedGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <ArmedGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	ArmedGameObjDef::ArmedGameObjDef(IntPtr pointer)
		: PhysicalGameObjDef(pointer)
	{

	}

	IntPtr ArmedGameObjDef::ArmedGameObjDefPointer::get()
	{
		return IntPtr(InternalArmedGameObjDefPointer);
	}

	float ArmedGameObjDef::WeaponTiltRate::get()
	{
		return InternalArmedGameObjDefPointer->WeaponTiltRate;
	}

	void ArmedGameObjDef::WeaponTiltRate::set(float value)
	{
		InternalArmedGameObjDefPointer->WeaponTiltRate = value;
	}

	float ArmedGameObjDef::WeaponTiltMin::get()
	{
		return InternalArmedGameObjDefPointer->WeaponTiltMin;
	}

	void ArmedGameObjDef::WeaponTiltMin::set(float value)
	{
		InternalArmedGameObjDefPointer->WeaponTiltMin = value;
	}

	float ArmedGameObjDef::WeaponTiltMax::get()
	{
		return InternalArmedGameObjDefPointer->WeaponTiltMax;
	}

	void ArmedGameObjDef::WeaponTiltMax::set(float value)
	{
		InternalArmedGameObjDefPointer->WeaponTiltMax = value;
	}

	float ArmedGameObjDef::WeaponTurnRate::get()
	{
		return InternalArmedGameObjDefPointer->WeaponTurnRate;
	}

	void ArmedGameObjDef::WeaponTurnRate::set(float value)
	{
		InternalArmedGameObjDefPointer->WeaponTurnRate = value;
	}

	float ArmedGameObjDef::WeaponTurnMin::get()
	{
		return InternalArmedGameObjDefPointer->WeaponTurnMin;
	}

	void ArmedGameObjDef::WeaponTurnMin::set(float value)
	{
		InternalArmedGameObjDefPointer->WeaponTurnMin = value;
	}

	float ArmedGameObjDef::WeaponTurnMax::get()
	{
		return InternalArmedGameObjDefPointer->WeaponTurnMax;
	}

	void ArmedGameObjDef::WeaponTurnMax::set(float value)
	{
		InternalArmedGameObjDefPointer->WeaponTurnMax = value;
	}

	float ArmedGameObjDef::WeaponError::get()
	{
		return InternalArmedGameObjDefPointer->WeaponError;
	}

	void ArmedGameObjDef::WeaponError::set(float value)
	{
		InternalArmedGameObjDefPointer->WeaponError = value;
	}

	int ArmedGameObjDef::WeaponDefID::get()
	{
		return InternalArmedGameObjDefPointer->WeaponDefID;
	}

	void ArmedGameObjDef::WeaponDefID::set(int value)
	{
		InternalArmedGameObjDefPointer->WeaponDefID = value;
	}

	int ArmedGameObjDef::SecondaryWeaponDefID::get()
	{
		return InternalArmedGameObjDefPointer->SecondaryWeaponDefID;
	}

	void ArmedGameObjDef::SecondaryWeaponDefID::set(int value)
	{
		InternalArmedGameObjDefPointer->SecondaryWeaponDefID = value;
	}

	int ArmedGameObjDef::WeaponRounds::get()
	{
		return InternalArmedGameObjDefPointer->WeaponRounds;
	}

	void ArmedGameObjDef::WeaponRounds::set(int value)
	{
		InternalArmedGameObjDefPointer->WeaponRounds = value;
	}

	::PhysicalGameObjDef *ArmedGameObjDef::InternalPhysicalGameObjDefPointer::get()
	{
		return InternalArmedGameObjDefPointer;
	}

	::ArmedGameObjDef *ArmedGameObjDef::InternalArmedGameObjDefPointer::get()
	{
		return reinterpret_cast<::ArmedGameObjDef *>(Pointer.ToPointer());
	}
}