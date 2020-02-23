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
#include "MPhysicalGameObjDef.h"

namespace RenSharp
{
	PhysicalGameObjDef::PhysicalGameObjDef(IntPtr pointer)
		: DamageableGameObjDef(pointer)
	{

	}

	IntPtr PhysicalGameObjDef::PhysicalGameObjDefPointer::get()
	{
		return IntPtr(InternalPhysicalGameObjDefPointer);
	}

	int PhysicalGameObjDef::Type::get()
	{
		return InternalPhysicalGameObjDefPointer->Type;
	}

	void PhysicalGameObjDef::Type::set(int value)
	{
		InternalPhysicalGameObjDefPointer->Type = value;
	}

	int PhysicalGameObjDef::RadarBlipType::get()
	{
		return InternalPhysicalGameObjDefPointer->RadarBlipType;
	}

	void PhysicalGameObjDef::RadarBlipType::set(int value)
	{
		InternalPhysicalGameObjDefPointer->RadarBlipType = value;
	}

	float PhysicalGameObjDef::BullseyeOffsetZ::get()
	{
		return InternalPhysicalGameObjDefPointer->BullseyeOffsetZ;
	}

	void PhysicalGameObjDef::BullseyeOffsetZ::set(float value)
	{
		InternalPhysicalGameObjDefPointer->BullseyeOffsetZ = value;
	}

	String ^PhysicalGameObjDef::Animation::get()
	{
		return gcnew String(InternalPhysicalGameObjDefPointer->Animation.Peek_Buffer());
	}

	void PhysicalGameObjDef::Animation::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalPhysicalGameObjDefPointer->Animation = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	int PhysicalGameObjDef::PhysDefID::get()
	{
		return InternalPhysicalGameObjDefPointer->PhysDefID;
	}

	void PhysicalGameObjDef::PhysDefID::set(int value)
	{
		InternalPhysicalGameObjDefPointer->PhysDefID = value;
	}

	int PhysicalGameObjDef::KilledExplosion::get()
	{
		return InternalPhysicalGameObjDefPointer->KilledExplosion;
	}

	void PhysicalGameObjDef::KilledExplosion::set(int value)
	{
		InternalPhysicalGameObjDefPointer->KilledExplosion = value;
	}

	bool PhysicalGameObjDef::DefaultHibernationEnable::get()
	{
		return InternalPhysicalGameObjDefPointer->DefaultHibernationEnable;
	}

	void PhysicalGameObjDef::DefaultHibernationEnable::set(bool value)
	{
		InternalPhysicalGameObjDefPointer->DefaultHibernationEnable = value;
	}

	bool PhysicalGameObjDef::AllowInnateConversations::get()
	{
		return InternalPhysicalGameObjDefPointer->AllowInnateConversations;
	}

	void PhysicalGameObjDef::AllowInnateConversations::set(bool value)
	{
		InternalPhysicalGameObjDefPointer->AllowInnateConversations = value;
	}

	int PhysicalGameObjDef::OratorType::get()
	{
		return InternalPhysicalGameObjDefPointer->OratorType;
	}

	void PhysicalGameObjDef::OratorType::set(int value)
	{
		InternalPhysicalGameObjDefPointer->OratorType = value;
	}

	bool PhysicalGameObjDef::UseCreationEffect::get()
	{
		return InternalPhysicalGameObjDefPointer->UseCreationEffect;
	}

	void PhysicalGameObjDef::UseCreationEffect::set(bool value)
	{
		InternalPhysicalGameObjDefPointer->UseCreationEffect = value;
	}

	char PhysicalGameObjDef::TeamVisibility::get()
	{
		return InternalPhysicalGameObjDefPointer->TeamVisibility;
	}

	void PhysicalGameObjDef::TeamVisibility::set(char value)
	{
		InternalPhysicalGameObjDefPointer->TeamVisibility = value;
	}

	bool PhysicalGameObjDef::IgnoreForTracking::get()
	{
		return InternalPhysicalGameObjDefPointer->IgnoreForTracking;
	}

	void PhysicalGameObjDef::IgnoreForTracking::set(bool value)
	{
		InternalPhysicalGameObjDefPointer->IgnoreForTracking = value;
	}

	::DamageableGameObjDef *PhysicalGameObjDef::InternalDamageableGameObjDefPointer::get()
	{
		return InternalPhysicalGameObjDefPointer;
	}

	::PhysicalGameObjDef *PhysicalGameObjDef::InternalPhysicalGameObjDefPointer::get()
	{
		return reinterpret_cast<::PhysicalGameObjDef *>(Pointer.ToPointer());
	}
}