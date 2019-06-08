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
#include "MDefenseObjectDefClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <DefenseObjectDefClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DefenseObjectDefClass::DefenseObjectDefClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool DefenseObjectDefClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDefenseObjectDefClass ^otherThis = dynamic_cast<IDefenseObjectDefClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DefenseObjectDefClassPointer.Equals(otherThis->DefenseObjectDefClassPointer);
	}

	IntPtr DefenseObjectDefClass::DefenseObjectDefClassPointer::get()
	{
		return IntPtr(InternalDefenseObjectDefClassPointer);
	}

	float DefenseObjectDefClass::Health::get()
	{
		return InternalDefenseObjectDefClassPointer->Health;
	}

	void DefenseObjectDefClass::Health::set(float value)
	{
		InternalDefenseObjectDefClassPointer->Health = value;
	}

	float DefenseObjectDefClass::HealthMax::get()
	{
		return InternalDefenseObjectDefClassPointer->HealthMax;
	}

	void DefenseObjectDefClass::HealthMax::set(float value)
	{
		InternalDefenseObjectDefClassPointer->HealthMax = value;
	}

	unsigned int DefenseObjectDefClass::Skin::get()
	{
		return InternalDefenseObjectDefClassPointer->Skin;
	}

	void DefenseObjectDefClass::Skin::set(unsigned int value)
	{
		InternalDefenseObjectDefClassPointer->Skin = value;
	}

	float DefenseObjectDefClass::ShieldStrength::get()
	{
		return InternalDefenseObjectDefClassPointer->ShieldStrength;
	}

	void DefenseObjectDefClass::ShieldStrength::set(float value)
	{
		InternalDefenseObjectDefClassPointer->ShieldStrength = value;
	}

	float DefenseObjectDefClass::ShieldStrengthMax::get()
	{
		return InternalDefenseObjectDefClassPointer->ShieldStrengthMax;
	}

	void DefenseObjectDefClass::ShieldStrengthMax::set(float value)
	{
		InternalDefenseObjectDefClassPointer->ShieldStrengthMax = value;
	}

	unsigned int DefenseObjectDefClass::ShieldType::get()
	{
		return InternalDefenseObjectDefClassPointer->ShieldType;
	}

	void DefenseObjectDefClass::ShieldType::set(unsigned int value)
	{
		InternalDefenseObjectDefClassPointer->ShieldType = value;
	}

	float DefenseObjectDefClass::DamagePoints::get()
	{
		return InternalDefenseObjectDefClassPointer->DamagePoints;
	}

	void DefenseObjectDefClass::DamagePoints::set(float value)
	{
		InternalDefenseObjectDefClassPointer->DamagePoints = value;
	}

	float DefenseObjectDefClass::DeathPoints::get()
	{
		return InternalDefenseObjectDefClassPointer->DeathPoints;
	}

	void DefenseObjectDefClass::DeathPoints::set(float value)
	{
		InternalDefenseObjectDefClassPointer->DeathPoints = value;
	}

	::DefenseObjectDefClass *DefenseObjectDefClass::InternalDefenseObjectDefClassPointer::get()
	{
		return reinterpret_cast<::DefenseObjectDefClass *>(Pointer.ToPointer());
	}
}