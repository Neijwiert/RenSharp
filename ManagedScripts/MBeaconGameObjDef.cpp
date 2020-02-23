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
#include "MBeaconGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <BeaconGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	BeaconGameObjDef::BeaconGameObjDef(IntPtr pointer)
		: SimpleGameObjDef(pointer)
	{

	}

	IntPtr BeaconGameObjDef::BeaconGameObjDefPointer::get()
	{
		return IntPtr(InternalBeaconGameObjDefPointer);
	}

	float BeaconGameObjDef::BroadcastToAllTime::get()
	{
		return InternalBeaconGameObjDefPointer->BroadcastToAllTime;
	}

	void BeaconGameObjDef::BroadcastToAllTime::set(float value)
	{
		InternalBeaconGameObjDefPointer->BroadcastToAllTime = value;
	}

	float BeaconGameObjDef::ArmTime::get()
	{
		return InternalBeaconGameObjDefPointer->ArmTime;
	}

	void BeaconGameObjDef::ArmTime::set(float value)
	{
		InternalBeaconGameObjDefPointer->ArmTime = value;
	}

	float BeaconGameObjDef::DisarmTime::get()
	{
		return InternalBeaconGameObjDefPointer->DisarmTime;
	}

	void BeaconGameObjDef::DisarmTime::set(float value)
	{
		InternalBeaconGameObjDefPointer->DisarmTime = value;
	}

	float BeaconGameObjDef::PreDetonateCinematicDelay::get()
	{
		return InternalBeaconGameObjDefPointer->PreDetonateCinematicDelay;
	}

	void BeaconGameObjDef::PreDetonateCinematicDelay::set(float value)
	{
		InternalBeaconGameObjDefPointer->PreDetonateCinematicDelay = value;
	}

	float BeaconGameObjDef::DetonateTime::get()
	{
		return InternalBeaconGameObjDefPointer->DetonateTime;
	}

	void BeaconGameObjDef::DetonateTime::set(float value)
	{
		InternalBeaconGameObjDefPointer->DetonateTime = value;
	}

	float BeaconGameObjDef::PostDetonateTime::get()
	{
		return InternalBeaconGameObjDefPointer->PostDetonateTime;
	}

	void BeaconGameObjDef::PostDetonateTime::set(float value)
	{
		InternalBeaconGameObjDefPointer->PostDetonateTime = value;
	}

	int BeaconGameObjDef::ArmedSoundDefID::get()
	{
		return InternalBeaconGameObjDefPointer->ArmedSoundDefID;
	}

	void BeaconGameObjDef::ArmedSoundDefID::set(int value)
	{
		InternalBeaconGameObjDefPointer->ArmedSoundDefID = value;
	}

	int BeaconGameObjDef::DisarmingTextID::get()
	{
		return InternalBeaconGameObjDefPointer->DisarmingTextID;
	}

	void BeaconGameObjDef::DisarmingTextID::set(int value)
	{
		InternalBeaconGameObjDefPointer->DisarmingTextID = value;
	}

	int BeaconGameObjDef::DisarmedTextID::get()
	{
		return InternalBeaconGameObjDefPointer->DisarmedTextID;
	}

	void BeaconGameObjDef::DisarmedTextID::set(int value)
	{
		InternalBeaconGameObjDefPointer->DisarmedTextID = value;
	}

	int BeaconGameObjDef::ArmingTextID::get()
	{
		return InternalBeaconGameObjDefPointer->ArmingTextID;
	}

	void BeaconGameObjDef::ArmingTextID::set(int value)
	{
		InternalBeaconGameObjDefPointer->ArmingTextID = value;
	}

	int BeaconGameObjDef::ArmingInterruptedTextID::get()
	{
		return InternalBeaconGameObjDefPointer->ArmingInterruptedTextID;
	}

	void BeaconGameObjDef::ArmingInterruptedTextID::set(int value)
	{
		InternalBeaconGameObjDefPointer->ArmingInterruptedTextID = value;
	}

	int BeaconGameObjDef::DisarmingInterruptedTextID::get()
	{
		return InternalBeaconGameObjDefPointer->DisarmingInterruptedTextID;
	}

	void BeaconGameObjDef::DisarmingInterruptedTextID::set(int value)
	{
		InternalBeaconGameObjDefPointer->DisarmingInterruptedTextID = value;
	}

	int BeaconGameObjDef::PreDetonateCinematicObjDef::get()
	{
		return InternalBeaconGameObjDefPointer->PreDetonateCinematicObjDef;
	}

	void BeaconGameObjDef::PreDetonateCinematicObjDef::set(int value)
	{
		InternalBeaconGameObjDefPointer->PreDetonateCinematicObjDef = value;
	}

	int BeaconGameObjDef::PostDetonateCinematicObjDef::get()
	{
		return InternalBeaconGameObjDefPointer->PostDetonateCinematicObjDef;
	}

	void BeaconGameObjDef::PostDetonateCinematicObjDef::set(int value)
	{
		InternalBeaconGameObjDefPointer->PostDetonateCinematicObjDef = value;
	}

	int BeaconGameObjDef::ExplosionObjDef::get()
	{
		return InternalBeaconGameObjDefPointer->ExplosionObjDef;
	}

	void BeaconGameObjDef::ExplosionObjDef::set(int value)
	{
		InternalBeaconGameObjDefPointer->ExplosionObjDef = value;
	}

	int BeaconGameObjDef::IsNuke::get()
	{
		return InternalBeaconGameObjDefPointer->Is_Nuke();
	}

	void BeaconGameObjDef::IsNuke::set(int value)
	{
		InternalBeaconGameObjDefPointer->IsNuke = value;
	}

	String ^BeaconGameObjDef::ArmingAnimationName::get()
	{
		return gcnew String(InternalBeaconGameObjDefPointer->ArmingAnimationName.Peek_Buffer());
	}

	void BeaconGameObjDef::ArmingAnimationName::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalBeaconGameObjDefPointer->ArmingAnimationName = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	bool BeaconGameObjDef::RequiresSilo::get()
	{
		return InternalBeaconGameObjDefPointer->Requires_Silo();
	}

	void BeaconGameObjDef::RequiresSilo::set(bool value)
	{
		InternalBeaconGameObjDefPointer->RequiresSilo = value;
	}

	::SimpleGameObjDef *BeaconGameObjDef::InternalSimpleGameObjDefPointer::get()
	{
		return InternalBeaconGameObjDefPointer;
	}

	::BeaconGameObjDef *BeaconGameObjDef::InternalBeaconGameObjDefPointer::get()
	{
		return reinterpret_cast<::BeaconGameObjDef *>(Pointer.ToPointer());
	}
}