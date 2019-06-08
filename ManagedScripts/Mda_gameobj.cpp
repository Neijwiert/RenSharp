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
#include "Mda_gameobj.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_gameobj.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "McPlayer.h"
#include "MVehicleGameObj.h"
#include "MDamageableGameObj.h"
#include "MArmedGameObj.h"
#include "MPowerUpGameObjDef.h"
#include "MPowerUpGameObj.h"
#include "Mweaponmgr.h"
#include "MWeaponClass.h"
#include "RenSharpGameObjObserverClass.h"

namespace RenSharp
{
	DAGameObjObserverClass::DAGameObjObserverClass()
		: GameObjObserverClass()
	{

	}

	DAGameObjObserverClass::DAGameObjObserverClass(IntPtr pointer)
		: GameObjObserverClass(pointer)
	{

	}

	bool DAGameObjObserverClass::Equals(Object^ other)
	{
		if (GameObjObserverClass::Equals(other))
		{
			return true;
		}

		IRenSharpGameObjObserverClass^ otherThis = dynamic_cast<IRenSharpGameObjObserverClass^>(other);
		if (otherThis == nullptr)
		{
			return false;
		}

		return DAGameObjObserverClassPointer.Equals(otherThis->DAGameObjObserverClassPointer);
	}

	void DAGameObjObserverClass::Attach(IScriptableGameObj ^obj)
	{
		GameObjObserverClass::Attach(obj);
	}

	void DAGameObjObserverClass::Detach(IScriptableGameObj ^obj)
	{
		GameObjObserverClass::Detach(obj);
	}

	void DAGameObjObserverClass::Created(IScriptableGameObj ^obj)
	{
		GameObjObserverClass::Created(obj);
	}

	void DAGameObjObserverClass::Killed(IScriptableGameObj ^obj, IScriptableGameObj ^killer)
	{
		GameObjObserverClass::Killed(obj, killer);
	}

	void DAGameObjObserverClass::Damaged(IScriptableGameObj ^obj, IScriptableGameObj ^damager, float amount)
	{
		GameObjObserverClass::Damaged(obj, damager, amount);
	}

	void DAGameObjObserverClass::Init()
	{
		InternalDAGameObjObserverClassPointer->Init();
	}

	bool DAGameObjObserverClass::VehicleEntryRequest(IcPlayer ^player, int %seat)
	{
		int tmp = seat;
		bool result;

		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			result = InternalDAGameObjObserverClassPointer->Vehicle_Entry_Request(static_cast<::cPlayer *>(nullptr), tmp);
		}
		else
		{
			result = InternalDAGameObjObserverClassPointer->Vehicle_Entry_Request(reinterpret_cast<::cPlayer *>(player->cPlayerPointer.ToPointer()), tmp);
		}

		seat = tmp;

		return result;
	}

	bool DAGameObjObserverClass::VehicleEntryRequest(IVehicleGameObj ^vehicle, int %seat)
	{
		int tmp = seat;
		bool result;

		if (vehicle == nullptr || vehicle->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			result = InternalDAGameObjObserverClassPointer->Vehicle_Entry_Request(static_cast<::VehicleGameObj *>(nullptr), tmp);
		}
		else
		{
			result = InternalDAGameObjObserverClassPointer->Vehicle_Entry_Request(reinterpret_cast<::VehicleGameObj *>(vehicle->VehicleGameObjPointer.ToPointer()), tmp);
		}

		seat = tmp;

		return result;
	}

	void DAGameObjObserverClass::VehicleEnter(IcPlayer ^player, int seat)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			InternalDAGameObjObserverClassPointer->Vehicle_Enter(static_cast<::cPlayer *>(player->cPlayerPointer.ToPointer()), seat);
		}
		else
		{
			InternalDAGameObjObserverClassPointer->Vehicle_Enter(reinterpret_cast<::cPlayer *>(player->cPlayerPointer.ToPointer()), seat);
		}
	}

	void DAGameObjObserverClass::VehicleEnter(IVehicleGameObj ^vehicle, int seat)
	{
		if (vehicle == nullptr || vehicle->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			InternalDAGameObjObserverClassPointer->Vehicle_Enter(static_cast<::VehicleGameObj *>(nullptr), seat);
		}
		else
		{
			InternalDAGameObjObserverClassPointer->Vehicle_Enter(reinterpret_cast<::VehicleGameObj *>(vehicle->VehicleGameObjPointer.ToPointer()), seat);
		}
	}

	void DAGameObjObserverClass::VehicleExit(IcPlayer ^player, int seat)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			InternalDAGameObjObserverClassPointer->Vehicle_Exit(static_cast<::cPlayer *>(nullptr), seat);
		}
		else
		{
			InternalDAGameObjObserverClassPointer->Vehicle_Exit(reinterpret_cast<::cPlayer *>(player->cPlayerPointer.ToPointer()), seat);
		}
	}

	void DAGameObjObserverClass::VehicleExit(IVehicleGameObj ^vehicle, int seat)
	{
		if (vehicle == nullptr || vehicle->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			InternalDAGameObjObserverClassPointer->Vehicle_Exit(static_cast<::VehicleGameObj *>(nullptr), seat);
		}
		else
		{
			InternalDAGameObjObserverClassPointer->Vehicle_Exit(reinterpret_cast<::VehicleGameObj *>(vehicle->VehicleGameObjPointer.ToPointer()), seat);
		}
	}

	bool DAGameObjObserverClass::VehicleFlip()
	{
		return InternalDAGameObjObserverClassPointer->Vehicle_Flip();
	}

	bool DAGameObjObserverClass::DamageDealtRequest(IDamageableGameObj ^victim, float %damage, unsigned int %warhead, float scale, DADamageType type)
	{
		float tmpDamage = damage;
		unsigned int tmpWarhead = warhead;
		bool result;

		if (victim == nullptr || victim->DamageableGameObjPointer.ToPointer() == nullptr)
		{
			result = InternalDAGameObjObserverClassPointer->Damage_Dealt_Request(nullptr, tmpDamage, tmpWarhead, scale, static_cast<::DADamageType::Type>(type));
		}
		else
		{
			result = InternalDAGameObjObserverClassPointer->Damage_Dealt_Request(
				reinterpret_cast<::DamageableGameObj *>(victim->DamageableGameObjPointer.ToPointer()),
				tmpDamage,
				tmpWarhead,
				scale,
				static_cast<::DADamageType::Type>(type));
		}

		damage = tmpDamage;
		warhead = tmpWarhead;

		return result;
	}

	bool DAGameObjObserverClass::DamageReceivedRequest(IArmedGameObj ^damager, float %damage, unsigned int %warhead, float scale, DADamageType type)
	{
		float tmpDamage = damage;
		unsigned int tmpWarhead = warhead;
		bool result;

		if (damager == nullptr || damager->ArmedGameObjPointer.ToPointer() == nullptr)
		{
			result = InternalDAGameObjObserverClassPointer->Damage_Received_Request(nullptr, tmpDamage, tmpWarhead, scale, static_cast<::DADamageType::Type>(type));
		}
		else
		{
			result = InternalDAGameObjObserverClassPointer->Damage_Received_Request(
				reinterpret_cast<::ArmedGameObj *>(damager->ArmedGameObjPointer.ToPointer()),
				tmpDamage,
				tmpWarhead,
				scale, 
				static_cast<::DADamageType::Type>(type));
		}

		damage = tmpDamage;
		warhead = tmpWarhead;

		return result;
	}

	void DAGameObjObserverClass::DamageDealt(IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type)
	{
		if (victim == nullptr || victim->DamageableGameObjPointer.ToPointer() == nullptr)
		{
			InternalDAGameObjObserverClassPointer->Damage_Dealt(nullptr, damage, warhead, scale, static_cast<::DADamageType::Type>(type));
		}
		else
		{
			InternalDAGameObjObserverClassPointer->Damage_Dealt(
				reinterpret_cast<::DamageableGameObj *>(victim->DamageableGameObjPointer.ToPointer()),
				damage,
				warhead,
				scale,
				static_cast<::DADamageType::Type>(type));
		}
	}

	void DAGameObjObserverClass::DamageReceived(IArmedGameObj ^damager, float damage, unsigned int warhead, float scale, DADamageType type)
	{
		if (damager == nullptr || damager->ArmedGameObjPointer.ToPointer() == nullptr)
		{
			InternalDAGameObjObserverClassPointer->Damage_Received(nullptr, damage, warhead, scale, static_cast<::DADamageType::Type>(type));
		}
		else
		{
			InternalDAGameObjObserverClassPointer->Damage_Received(
				reinterpret_cast<::ArmedGameObj *>(damager->ArmedGameObjPointer.ToPointer()),
				damage,
				warhead,
				scale, 
				static_cast<::DADamageType::Type>(type));
		}
	}

	void DAGameObjObserverClass::KillDealt(IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type)
	{
		if (victim == nullptr || victim->DamageableGameObjPointer.ToPointer() == nullptr)
		{
			InternalDAGameObjObserverClassPointer->Kill_Dealt(nullptr, damage, warhead, scale, static_cast<::DADamageType::Type>(type));
		}
		else
		{
			InternalDAGameObjObserverClassPointer->Kill_Dealt(
				reinterpret_cast<::DamageableGameObj *>(victim->DamageableGameObjPointer.ToPointer()), 
				damage, 
				warhead,
				scale, 
				static_cast<::DADamageType::Type>(type));
		}
	}

	void DAGameObjObserverClass::KillReceived(IArmedGameObj ^killer, float damage, unsigned int warhead, float scale, DADamageType type)
	{
		if (killer == nullptr || killer->ArmedGameObjPointer.ToPointer() == nullptr)
		{
			InternalDAGameObjObserverClassPointer->Kill_Received(nullptr, damage, warhead, scale, static_cast<::DADamageType::Type>(type));
		}
		else
		{
			InternalDAGameObjObserverClassPointer->Kill_Received(
				reinterpret_cast<::ArmedGameObj *>(killer->ArmedGameObjPointer.ToPointer()),
				damage, 
				warhead,
				scale, 
				static_cast<::DADamageType::Type>(type));
		}
	}

	bool DAGameObjObserverClass::PowerUpGrantRequest(IcPlayer ^player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			return InternalDAGameObjObserverClassPointer->PowerUp_Grant_Request(nullptr);
		}
		else
		{
			return InternalDAGameObjObserverClassPointer->PowerUp_Grant_Request(reinterpret_cast<::cPlayer *>(player->cPlayerPointer.ToPointer()));
		}
	}

	bool DAGameObjObserverClass::PowerUpGrantRequest(IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj)
	{
		::PowerUpGameObjDef *defPtr;
		::PowerUpGameObj *objPtr;

		if (powerUp == nullptr || powerUp->PowerUpGameObjDefPointer.ToPointer() == nullptr)
		{
			defPtr = nullptr;
		}
		else
		{
			defPtr = reinterpret_cast<::PowerUpGameObjDef *>(powerUp->PowerUpGameObjDefPointer.ToPointer());
		}

		if (powerUpObj == nullptr || powerUpObj->PowerUpGameObjPointer.ToPointer() == nullptr)
		{
			objPtr = nullptr;
		}
		else
		{
			objPtr = reinterpret_cast<::PowerUpGameObj *>(powerUpObj->PowerUpGameObjPointer.ToPointer());
		}

		return InternalDAGameObjObserverClassPointer->PowerUp_Grant_Request(defPtr, objPtr);
	}

	void DAGameObjObserverClass::PowerUpGrant(IcPlayer ^player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			InternalDAGameObjObserverClassPointer->PowerUp_Grant(nullptr);
		}
		else
		{
			InternalDAGameObjObserverClassPointer->PowerUp_Grant(reinterpret_cast<::cPlayer *>(player->cPlayerPointer.ToPointer()));
		}
	}

	void DAGameObjObserverClass::PowerUpGrant(IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj)
	{
		::PowerUpGameObjDef *defPtr;
		::PowerUpGameObj *objPtr;

		if (powerUp == nullptr || powerUp->PowerUpGameObjDefPointer.ToPointer() == nullptr)
		{
			defPtr = nullptr;
		}
		else
		{
			defPtr = reinterpret_cast<::PowerUpGameObjDef *>(powerUp->PowerUpGameObjDefPointer.ToPointer());
		}

		if (powerUpObj == nullptr || powerUpObj->PowerUpGameObjPointer.ToPointer() == nullptr)
		{
			objPtr = nullptr;
		}
		else
		{
			objPtr = reinterpret_cast<::PowerUpGameObj *>(powerUpObj->PowerUpGameObjPointer.ToPointer());
		}

		InternalDAGameObjObserverClassPointer->PowerUp_Grant(defPtr, objPtr);
	}

	bool DAGameObjObserverClass::AddWeaponRequest(IWeaponDefinitionClass ^weapon)
	{
		if (weapon == nullptr || weapon->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			return InternalDAGameObjObserverClassPointer->Add_Weapon_Request(nullptr);
		}
		else
		{
			return InternalDAGameObjObserverClassPointer->Add_Weapon_Request(reinterpret_cast<::WeaponDefinitionClass *>(weapon->WeaponDefinitionClassPointer.ToPointer()));
		}
	}

	void DAGameObjObserverClass::AddWeapon(IWeaponClass ^weapon)
	{
		if (weapon == nullptr || weapon->WeaponClassPointer.ToPointer() == nullptr)
		{
			InternalDAGameObjObserverClassPointer->Add_Weapon(nullptr);
		}
		else
		{
			InternalDAGameObjObserverClassPointer->Add_Weapon(reinterpret_cast<::WeaponClass *>(weapon->WeaponClassPointer.ToPointer()));
		}
	}

	void DAGameObjObserverClass::RemoveWeapon(IWeaponClass ^weapon)
	{
		if (weapon == nullptr || weapon->WeaponClassPointer.ToPointer() == nullptr)
		{
			InternalDAGameObjObserverClassPointer->Remove_Weapon(nullptr);
		}
		else
		{
			InternalDAGameObjObserverClassPointer->Remove_Weapon(reinterpret_cast<::WeaponClass *>(weapon->WeaponClassPointer.ToPointer()));
		}
	}

	void DAGameObjObserverClass::ClearWeapons()
	{
		InternalDAGameObjObserverClassPointer->Clear_Weapons();
	}

	void DAGameObjObserverClass::StartTimer(int number, float duration)
	{
		if (IsManagedObserver)
		{
			AsManagedGameObjObserverClass()->StartTimer(number, TimeSpan::FromSeconds(duration));
		}
		else
		{
			InternalDAGameObjObserverClassPointer->Start_Timer(number, duration);
		}
	}

	void DAGameObjObserverClass::StopTimer(int number)
	{
		if (IsManagedObserver)
		{
			AsManagedGameObjObserverClass()->StopTimer(number);
		}
		else
		{
			InternalDAGameObjObserverClassPointer->Stop_Timer(number);
		}
	}

	bool DAGameObjObserverClass::IsTimer(int number)
	{
		if (IsManagedObserver)
		{
			return AsManagedGameObjObserverClass()->IsTimer(number);
		}
		else
		{
			return InternalDAGameObjObserverClassPointer->Is_Timer(number);
		}
	}

	void DAGameObjObserverClass::SetDeletePending()
	{
		InternalDAGameObjObserverClassPointer->Set_Delete_Pending();
	}

	IRenSharpGameObjObserverClass^ DAGameObjObserverClass::AsManagedGameObjObserverClass()
	{
		return ScriptableGameObj::AsManagedObserver(this);
	}

	IntPtr DAGameObjObserverClass::DAGameObjObserverClassPointer::get()
	{
		return IntPtr(InternalDAGameObjObserverClassPointer);
	}

	IScriptableGameObj ^DAGameObjObserverClass::Owner::get()
	{
		auto result = InternalDAGameObjObserverClassPointer->Get_Owner();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptableGameObj(IntPtr(result));
		}
	}

	bool DAGameObjObserverClass::IsManagedGameObjObserverClass::get()
	{
		return ScriptableGameObj::IsManagedObserver(this);
	}

	::GameObjObserverClass *DAGameObjObserverClass::InternalGameObjObserverClassPointer::get()
	{
		return InternalDAGameObjObserverClassPointer;
	}

	::DAGameObjObserverClass *DAGameObjObserverClass::InternalDAGameObjObserverClassPointer::get()
	{
		return reinterpret_cast<::DAGameObjObserverClass *>(Pointer.ToPointer());
	}

	DAGameObjManager::DAGameObjManager(IntPtr pointer)
		: DAEventClass(pointer)
	{

	}

	void DAGameObjManager::SetObserverDeletePending(IDAGameObjObserverClass^ observer)
	{
		if (observer == nullptr || observer->DAGameObjObserverClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("observer");
		}

		::DAGameObjManager::Set_Observer_Delete_Pending(
			reinterpret_cast<::DAGameObjObserverClass*>(observer->DAGameObjObserverClassPointer.ToPointer()));
	}

	void DAGameObjManager::SetObserverDeletePending(IRenSharpGameObjObserverClass^ observer)
	{
		if (observer == nullptr)
		{
			throw gcnew ArgumentNullException("observer");
		}

		if (!observer->IsAttached)
		{
			observer->AttachToUnmanagedObject();
			observer->RegisterManagedObject();
		}

		::DAGameObjManager::Set_Observer_Delete_Pending(
			reinterpret_cast<::DAGameObjObserverClass*>(observer->DAGameObjObserverClassPointer.ToPointer()));
	}

	void DAGameObjManager::SetGameObjDeletePending(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::DAGameObjManager::Set_GameObj_Delete_Pending(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void DAGameObjManager::SetGameObjTTOnly(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::DAGameObjManager::Set_GameObj_TT_Only(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void DAGameObjManager::SetGameObjStockOnly(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::DAGameObjManager::Set_GameObj_Stock_Only(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void DAGameObjManager::SetGameObjInvisible(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::DAGameObjManager::Set_GameObj_Invisible(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void DAGameObjManager::SetGameObjInvisibleNoDelete(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::DAGameObjManager::Set_GameObj_Invisible_No_Delete(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	IntPtr DAGameObjManager::DAGameObjManagerPointer::get()
	{
		return IntPtr(InternalDAGameObjManagerPointer);
	}

	::DAEventClass* DAGameObjManager::InternalDAEventClassPointer::get()
	{
		return InternalDAGameObjManagerPointer;
	}

	::DAGameObjManager* DAGameObjManager::InternalDAGameObjManagerPointer::get()
	{
		return reinterpret_cast<::DAGameObjManager*>(Pointer.ToPointer());
	}
}