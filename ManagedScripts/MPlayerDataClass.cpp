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
#include "MPlayerDataClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <PlayerDataClass.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MReferencerClass.h"
#include "MSmartGameObj.h"
#include "MIntSimpleDynVecClass.h"

namespace RenSharp
{
	PlayerDataClass::PlayerDataClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool PlayerDataClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IPlayerDataClass ^otherThis = dynamic_cast<IPlayerDataClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return PlayerDataClassPointer.Equals(otherThis->PlayerDataClassPointer);
	}

	void PlayerDataClass::StatsAddGameTime(float time)
	{
		InternalPlayerDataClassPointer->Stats_Add_Game_Time(time);
	}

	IntPtr PlayerDataClass::PlayerDataClassPointer::get()
	{
		return IntPtr(InternalPlayerDataClassPointer);
	}

	float PlayerDataClass::Score::get()
	{
		return InternalPlayerDataClassPointer->Score;
	}

	void PlayerDataClass::Score::set(float value)
	{
		InternalPlayerDataClassPointer->Score = value;
	}

	float PlayerDataClass::Money::get()
	{
		return InternalPlayerDataClassPointer->Money;
	}

	void PlayerDataClass::Money::set(float value)
	{
		InternalPlayerDataClassPointer->Money = value;
	}

	IReferencerClass ^PlayerDataClass::Owner::get()
	{
		return gcnew ReferencerClass(IntPtr(&InternalPlayerDataClassPointer->Owner));
	}

	void PlayerDataClass::Owner::set(IReferencerClass ^value)
	{
		if (value == nullptr || value->ReferencerClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalPlayerDataClassPointer->Owner = *reinterpret_cast<::ReferencerClass *>(value->ReferencerClassPointer.ToPointer());
	}

	float PlayerDataClass::PunishTimer::get()
	{
		return InternalPlayerDataClassPointer->PunishTimer;
	}

	void PlayerDataClass::PunishTimer::set(float value)
	{
		InternalPlayerDataClassPointer->PunishTimer = value;
	}

	float PlayerDataClass::GameTime::get()
	{
		return InternalPlayerDataClassPointer->GameTime;
	}

	void PlayerDataClass::GameTime::set(float value)
	{
		InternalPlayerDataClassPointer->GameTime = value;
	}

	float PlayerDataClass::SessionTime::get()
	{
		return InternalPlayerDataClassPointer->SessionTime;
	}

	void PlayerDataClass::SessionTime::set(float value)
	{
		InternalPlayerDataClassPointer->SessionTime = value;
	}

	int PlayerDataClass::EnemiesKilled::get()
	{
		return InternalPlayerDataClassPointer->EnemiesKilled;
	}

	void PlayerDataClass::EnemiesKilled::set(int value)
	{
		InternalPlayerDataClassPointer->EnemiesKilled = value;
	}

	int PlayerDataClass::AlliesKilled::get()
	{
		return InternalPlayerDataClassPointer->AlliesKilled;
	}

	void PlayerDataClass::AlliesKilled::set(int value)
	{
		InternalPlayerDataClassPointer->AlliesKilled = value;
	}

	int PlayerDataClass::ShotsFired::get()
	{
		return InternalPlayerDataClassPointer->ShotsFired;
	}

	void PlayerDataClass::ShotsFired::set(int value)
	{
		InternalPlayerDataClassPointer->ShotsFired = value;
	}

	int PlayerDataClass::HeadShots::get()
	{
		return InternalPlayerDataClassPointer->HeadShots;
	}

	void PlayerDataClass::HeadShots::set(int value)
	{
		InternalPlayerDataClassPointer->HeadShots = value;
	}

	int PlayerDataClass::TorsoShots::get()
	{
		return InternalPlayerDataClassPointer->TorsoShots;
	}

	void PlayerDataClass::TorsoShots::set(int value)
	{
		InternalPlayerDataClassPointer->TorsoShots = value;
	}

	int PlayerDataClass::ArmShots::get()
	{
		return InternalPlayerDataClassPointer->ArmShots;
	}

	void PlayerDataClass::ArmShots::set(int value)
	{
		InternalPlayerDataClassPointer->ArmShots = value;
	}

	int PlayerDataClass::LegShots::get()
	{
		return InternalPlayerDataClassPointer->LegShots;
	}

	void PlayerDataClass::LegShots::set(int value)
	{
		InternalPlayerDataClassPointer->LegShots = value;
	}

	int PlayerDataClass::CrotchShots::get()
	{
		return InternalPlayerDataClassPointer->CrotchShots;
	}

	void PlayerDataClass::CrotchShots::set(int value)
	{
		InternalPlayerDataClassPointer->CrotchShots = value;
	}

	float PlayerDataClass::FinalHealth::get()
	{
		return InternalPlayerDataClassPointer->FinalHealth;
	}

	void PlayerDataClass::FinalHealth::set(float value)
	{
		InternalPlayerDataClassPointer->FinalHealth = value;
	}

	int PlayerDataClass::PowerupsCollected::get()
	{
		return InternalPlayerDataClassPointer->PowerupsCollected;
	}

	void PlayerDataClass::PowerupsCollected::set(int value)
	{
		InternalPlayerDataClassPointer->PowerupsCollected = value;
	}

	int PlayerDataClass::VehiclesDestroyed::get()
	{
		return InternalPlayerDataClassPointer->VehiclesDestroyed;
	}

	void PlayerDataClass::VehiclesDestroyed::set(int value)
	{
		InternalPlayerDataClassPointer->VehiclesDestroyed = value;
	}

	float PlayerDataClass::VehicleTime::get()
	{
		return InternalPlayerDataClassPointer->VehicleTime;
	}

	void PlayerDataClass::VehicleTime::set(float value)
	{
		InternalPlayerDataClassPointer->VehicleTime = value;
	}

	int PlayerDataClass::KillsFromVehicle::get()
	{
		return InternalPlayerDataClassPointer->KillsFromVehicle;
	}

	void PlayerDataClass::KillsFromVehicle::set(int value)
	{
		InternalPlayerDataClassPointer->KillsFromVehicle = value;
	}

	int PlayerDataClass::Squishes::get()
	{
		return InternalPlayerDataClassPointer->Squishes;
	}

	void PlayerDataClass::Squishes::set(int value)
	{
		InternalPlayerDataClassPointer->Squishes = value;
	}

	float PlayerDataClass::CreditGrant::get()
	{
		return InternalPlayerDataClassPointer->CreditGrant;
	}

	void PlayerDataClass::CreditGrant::set(float value)
	{
		InternalPlayerDataClassPointer->CreditGrant = value;
	}

	int PlayerDataClass::BuildingDestroyed::get()
	{
		return InternalPlayerDataClassPointer->BuildingDestroyed;
	}

	void PlayerDataClass::BuildingDestroyed::set(int value)
	{
		InternalPlayerDataClassPointer->BuildingDestroyed = value;
	}

	int PlayerDataClass::HeadHit::get()
	{
		return InternalPlayerDataClassPointer->HeadHit;
	}

	void PlayerDataClass::HeadHit::set(int value)
	{
		InternalPlayerDataClassPointer->HeadHit = value;
	}

	int PlayerDataClass::TorsoHit::get()
	{
		return InternalPlayerDataClassPointer->TorsoHit;
	}

	void PlayerDataClass::TorsoHit::set(int value)
	{
		InternalPlayerDataClassPointer->TorsoHit = value;
	}

	int PlayerDataClass::ArmHit::get()
	{
		return InternalPlayerDataClassPointer->ArmHit;
	}

	void PlayerDataClass::ArmHit::set(int value)
	{
		InternalPlayerDataClassPointer->ArmHit = value;
	}

	int PlayerDataClass::LegHit::get()
	{
		return InternalPlayerDataClassPointer->LegHit;
	}

	void PlayerDataClass::LegHit::set(int value)
	{
		InternalPlayerDataClassPointer->LegHit = value;
	}

	int PlayerDataClass::CrotchHit::get()
	{
		return InternalPlayerDataClassPointer->CrotchHit;
	}

	void PlayerDataClass::CrotchHit::set(int value)
	{
		InternalPlayerDataClassPointer->CrotchHit = value;
	}

	int PlayerDataClass::WeaponFired::get()
	{
		return InternalPlayerDataClassPointer->WeaponFired;
	}

	void PlayerDataClass::WeaponFired::set(int value)
	{
		InternalPlayerDataClassPointer->WeaponFired = value;
	}

	ISimpleDynVecClass<int> ^PlayerDataClass::WeaponsFiredID::get()
	{
		return gcnew IntSimpleDynVecClass(IntPtr(&InternalPlayerDataClassPointer->WeaponsFiredID));
	}

	void PlayerDataClass::WeaponsFiredID::set(ISimpleDynVecClass<int> ^value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalPlayerDataClassPointer->WeaponsFiredID = *reinterpret_cast<::SimpleDynVecClass<int> *>(value->Pointer.ToPointer());
	}

	ISimpleDynVecClass<int> ^PlayerDataClass::WeaponsFiredCount::get()
	{
		return gcnew IntSimpleDynVecClass(IntPtr(&InternalPlayerDataClassPointer->WeaponsFiredCount));
	}

	void PlayerDataClass::WeaponsFiredCount::set(ISimpleDynVecClass<int> ^value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalPlayerDataClassPointer->WeaponsFiredCount = *reinterpret_cast<::SimpleDynVecClass<int> *>(value->Pointer.ToPointer());
	}

	ISmartGameObj ^PlayerDataClass::GameObj::get()
	{
		auto result = InternalPlayerDataClassPointer->Get_GameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SmartGameObj(IntPtr(result));
		}
	}

	void PlayerDataClass::GameObj::set(ISmartGameObj ^value)
	{
		if (value == nullptr || value->SmartGameObjPointer.ToPointer() == nullptr)
		{
			InternalPlayerDataClassPointer->Set_GameObj(nullptr);
		}
		else
		{
			InternalPlayerDataClassPointer->Set_GameObj(reinterpret_cast<::SmartGameObj *>(value->SmartGameObjPointer.ToPointer()));
		}
	}

	::PlayerDataClass *PlayerDataClass::InternalPlayerDataClassPointer::get()
	{
		return reinterpret_cast<::PlayerDataClass *>(Pointer.ToPointer());
	}
}