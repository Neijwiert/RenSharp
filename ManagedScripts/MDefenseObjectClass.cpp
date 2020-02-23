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
#include "MDefenseObjectClass.h"

#include "MDamageableGameObj.h"

namespace RenSharp
{
	DefenseObjectClass::DefenseObjectClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool DefenseObjectClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDefenseObjectClass ^otherThis = dynamic_cast<IDefenseObjectClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DefenseObjectClassPointer.Equals(otherThis->DefenseObjectClassPointer);
	}

	void DefenseObjectClass::MarkOwnerDirty()
	{
		InternalDefenseObjectClassPointer->Mark_Owner_Dirty();
	}

	IntPtr DefenseObjectClass::DefenseObjectClassPointer::get()
	{
		return IntPtr(InternalDefenseObjectClassPointer);
	}

	IDamageableGameObj ^DefenseObjectClass::Owner::get()
	{
		auto result = InternalDefenseObjectClassPointer->Get_Owner();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DamageableGameObj(IntPtr(result));
		}
	}

	void DefenseObjectClass::Owner::set(IDamageableGameObj ^value)
	{
		if (value == nullptr || value->DamageableGameObjPointer.ToPointer() == nullptr)
		{
			InternalDefenseObjectClassPointer->Set_Owner(nullptr);
		}
		else
		{
			InternalDefenseObjectClassPointer->Set_Owner(reinterpret_cast<::DamageableGameObj *>(value->DamageableGameObjPointer.ToPointer()));
		}
	}

	unsigned int DefenseObjectClass::Skin::get()
	{
		return InternalDefenseObjectClassPointer->Get_Skin();
	}

	void DefenseObjectClass::Skin::set(unsigned int value)
	{
		InternalDefenseObjectClassPointer->Set_Skin(value);
	}

	float DefenseObjectClass::Health::get()
	{
		return InternalDefenseObjectClassPointer->Get_Health();
	}

	void DefenseObjectClass::Health::set(float value)
	{
		InternalDefenseObjectClassPointer->Set_Health(value);
	}

	float DefenseObjectClass::HealthMax::get()
	{
		return InternalDefenseObjectClassPointer->Get_Health_Max();
	}

	void DefenseObjectClass::HealthMax::set(float value)
	{
		InternalDefenseObjectClassPointer->Set_Health_Max(value);
	}

	float DefenseObjectClass::ShieldStrength::get()
	{
		return InternalDefenseObjectClassPointer->Get_Shield_Strength();
	}

	void DefenseObjectClass::ShieldStrength::set(float value)
	{
		InternalDefenseObjectClassPointer->Set_Shield_Strength(value);
	}

	float DefenseObjectClass::ShieldStrengthMax::get()
	{
		return InternalDefenseObjectClassPointer->Get_Shield_Strength_Max();
	}

	void DefenseObjectClass::ShieldStrengthMax::set(float value)
	{
		InternalDefenseObjectClassPointer->Set_Shield_Strength_Max(value);
	}

	unsigned int DefenseObjectClass::ShieldType::get()
	{
		return InternalDefenseObjectClassPointer->Get_Shield_Type();
	}

	void DefenseObjectClass::ShieldType::set(unsigned int value)
	{
		InternalDefenseObjectClassPointer->Set_Shield_Type(value);
	}

	bool DefenseObjectClass::CanObjectDie::get()
	{
		return InternalDefenseObjectClassPointer->Get_Can_Object_Die();
	}

	void DefenseObjectClass::CanObjectDie::set(bool value)
	{
		InternalDefenseObjectClassPointer->Set_Can_Object_Die(value);
	}

	float DefenseObjectClass::DamagePoints::get()
	{
		return InternalDefenseObjectClassPointer->Get_Damage_Points();
	}

	void DefenseObjectClass::DamagePoints::set(float value)
	{
		InternalDefenseObjectClassPointer->Set_Damage_Points(value);
	}

	float DefenseObjectClass::DeathPoints::get()
	{
		return InternalDefenseObjectClassPointer->Get_Death_Points();
	}

	void DefenseObjectClass::DeathPoints::set(float value)
	{
		InternalDefenseObjectClassPointer->Set_Death_Points(value);
	}

	::DefenseObjectClass *DefenseObjectClass::InternalDefenseObjectClassPointer::get()
	{
		return reinterpret_cast<::DefenseObjectClass *>(Pointer.ToPointer());
	}
}