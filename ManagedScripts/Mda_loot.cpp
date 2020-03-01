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
#include "Mda_loot.h"

#include "MConstWeaponDefinitionClassPtrDynamicVectorClass.h"
#include "McPlayerPtrDynamicVectorClass.h"
#include "MWeaponClass.h"
#include "Mweaponmgr.h"
#include "MReferencerClass.h"
#include "MPowerUpGameObjDef.h"
#include "MSoldierGameObj.h"
#include "MSoldierGameObjDef.h"
#include "McPlayer.h"
#include "UnmanagedContainer.h"
#include "Imports.h"
#include "MVector3.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <engine_player.h>
#include <engine_da.h>
#include <da_player.h>
#include <da_loot.h>
#include <weaponmgr.h>
#include <PowerupGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{

#pragma managed(push, off)

	class DALootPowerUpClassHelper : public ::DALootPowerUpClass
	{
		private:
			DALootPowerUpClassHelper() = default;

		public:
			void CreateIcon()
			{
				Create_Icon();
			}

			void SetIcon(const ::WeaponDefinitionClass* weapon)
			{
				Set_Icon(weapon);
			}

			void DestroyIcon()
			{
				Destroy_Icon();
			}

			::DynamicVectorClass<::cPlayer*>& GetDamagers()
			{
				return Damagers;
			}

			::cPlayer*& GetDropper()
			{
				return Dropper;
			}

			::ReferencerClass& GetIcon()
			{
				return Icon;
			}
	};

#pragma managed(pop)

	DALootPlayerDataClass::DALootPlayerDataClass()
		: DAPlayerDataClass(IntPtr(Imports::CreateDALootPlayerDataClass()))
	{

	}

	DALootPlayerDataClass::DALootPlayerDataClass(IntPtr pointer)
		: DAPlayerDataClass(pointer)
	{

	}

	IUnmanagedContainer<IDALootPlayerDataClass^>^ DALootPlayerDataClass::CreateDALootPlayerDataClass()
	{
		return gcnew UnmanagedContainer<IDALootPlayerDataClass^>(gcnew DALootPlayerDataClass());
	}

	void DALootPlayerDataClass::AddWeapon(IWeaponClass^ weapon)
	{
		if (weapon == nullptr || weapon->WeaponClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		InternalDALootPlayerDataClassPointer->Add_Weapon(
			reinterpret_cast<::WeaponClass*>(weapon->WeaponClassPointer.ToPointer()));
	}

	void DALootPlayerDataClass::AddWeapon(IWeaponDefinitionClass^ weapon)
	{
		if (weapon == nullptr || weapon->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		InternalDALootPlayerDataClassPointer->Add_Weapon(
			reinterpret_cast<::WeaponDefinitionClass*>(weapon->WeaponDefinitionClassPointer.ToPointer()));
	}

	void DALootPlayerDataClass::RemoveWeapon(IWeaponClass^ weapon)
	{
		if (weapon == nullptr || weapon->WeaponClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		InternalDALootPlayerDataClassPointer->Remove_Weapon(
			reinterpret_cast<::WeaponClass*>(weapon->WeaponClassPointer.ToPointer()));
	}

	void DALootPlayerDataClass::RemoveWeapon(IWeaponDefinitionClass^ weapon)
	{
		if (weapon == nullptr || weapon->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		InternalDALootPlayerDataClassPointer->Remove_Weapon(
			reinterpret_cast<::WeaponDefinitionClass*>(weapon->WeaponDefinitionClassPointer.ToPointer()));
	}

	bool DALootPlayerDataClass::HasWeapon(IWeaponClass^ weapon)
	{
		if (weapon == nullptr || weapon->WeaponClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		return InternalDALootPlayerDataClassPointer->Has_Weapon(
			reinterpret_cast<::WeaponClass*>(weapon->WeaponClassPointer.ToPointer()));
	}

	bool DALootPlayerDataClass::HasWeapon(IWeaponDefinitionClass^ weapon)
	{
		if (weapon == nullptr || weapon->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		return InternalDALootPlayerDataClassPointer->Has_Weapon(
			reinterpret_cast<::WeaponDefinitionClass*>(weapon->WeaponDefinitionClassPointer.ToPointer()));
	}

	void DALootPlayerDataClass::ClearWeapons()
	{
		InternalDALootPlayerDataClassPointer->Clear_Weapons();
	}

	IntPtr DALootPlayerDataClass::DALootPlayerDataClassPointer::get()
	{
		return IntPtr(InternalDALootPlayerDataClassPointer);
	}

	int DALootPlayerDataClass::WeaponCount::get()
	{
		return InternalDALootPlayerDataClassPointer->Get_Weapon_Count();
	}

	IDynamicVectorClass<IWeaponDefinitionClass^>^ DALootPlayerDataClass::Locker::get()
	{
		return gcnew ConstWeaponDefinitionClassPtrDynamicVectorClass(IntPtr(&InternalDALootPlayerDataClassPointer->Locker));
	}

	void DALootPlayerDataClass::Locker::set(IDynamicVectorClass<IWeaponDefinitionClass^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalDALootPlayerDataClassPointer->Locker = *reinterpret_cast<::DynamicVectorClass<const ::WeaponDefinitionClass*>*>(value->Pointer.ToPointer());
	}

	::DAPlayerDataClass* DALootPlayerDataClass::InternalDAPlayerDataClassPointer::get()
	{
		return InternalDALootPlayerDataClassPointer;
	}

	::DALootPlayerDataClass* DALootPlayerDataClass::InternalDALootPlayerDataClassPointer::get()
	{
		return reinterpret_cast<::DALootPlayerDataClass*>(Pointer.ToPointer());
	}

	DALootPowerUpClass::DALootPowerUpClass(bool create)
	{
		if (create)
		{
			Pointer = IntPtr(Imports::CreateDALootPowerUpClass1());
		}
	}

	DALootPowerUpClass::DALootPowerUpClass(ISoldierGameObj^ soldier)
	{
		if (soldier == nullptr || soldier->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}

		Pointer = IntPtr(Imports::CreateDALootPowerUpClass2(
			reinterpret_cast<::SoldierGameObj*>(soldier->SoldierGameObjPointer.ToPointer())));
	}

	DALootPowerUpClass::DALootPowerUpClass(IntPtr pointer)
		: DAGameObjObserverClass(pointer)
	{

	}

	IUnmanagedContainer<IDALootPowerUpClass^>^ DALootPowerUpClass::CreateDALootPowerUpClass()
	{
		return gcnew UnmanagedContainer<IDALootPowerUpClass^>(gcnew DALootPowerUpClass(true));
	}

	IUnmanagedContainer<IDALootPowerUpClass^>^ DALootPowerUpClass::CreateDALootPowerUpClass(ISoldierGameObj^ soldier)
	{
		return gcnew UnmanagedContainer<IDALootPowerUpClass^>(gcnew DALootPowerUpClass(soldier));
	}

	void DALootPowerUpClass::SetExpireTime(TimeSpan time)
	{
		InternalDALootPowerUpClassPointer->Set_Expire_Time(static_cast<float>(time.TotalSeconds));
	}

	void DALootPowerUpClass::InitDamagers(float range, TimeSpan expireTime)
	{
		InternalDALootPowerUpClassPointer->Init_Damagers(range, static_cast<float>(expireTime.TotalSeconds));
	}

	void DALootPowerUpClass::InitDamagers(float range, TimeSpan expireTime, ISoldierGameObj^ soldier)
	{
		if (soldier == nullptr || soldier->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}

		InternalDALootPowerUpClassPointer->Init_Damagers(
			range, 
			static_cast<float>(expireTime.TotalSeconds),
			reinterpret_cast<::SoldierGameObj*>(soldier->SoldierGameObjPointer.ToPointer()));
	}

	void DALootPowerUpClass::AddDamager(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		InternalDALootPowerUpClassPointer->Add_Damager(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	IntPtr DALootPowerUpClass::DALootPowerUpClassPointer::get()
	{
		return IntPtr(InternalDALootPowerUpClassPointer);
	}

	IcPlayer^ DALootPowerUpClass::Dropper::get()
	{
		auto result = InternalDALootPowerUpClassPointer->Get_Dropper();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	void DALootPowerUpClass::Dropper::set(IcPlayer^ value)
	{
		auto helper = reinterpret_cast<DALootPowerUpClassHelper*>(InternalDALootPowerUpClassPointer);

		auto& dropper = helper->GetDropper();

		if (value == nullptr || value->cPlayerPointer.ToPointer() == nullptr)
		{
			dropper = nullptr;
		}
		else
		{
			dropper = reinterpret_cast<::cPlayer*>(value->cPlayerPointer.ToPointer());
		}
	}

	void DALootPowerUpClass::CreateIcon()
	{
		auto helper = reinterpret_cast<DALootPowerUpClassHelper*>(InternalDALootPowerUpClassPointer);

		helper->CreateIcon();
	}

	void DALootPowerUpClass::SetIcon(IWeaponDefinitionClass^ weapon)
	{
		if (weapon == nullptr || weapon->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		auto helper = reinterpret_cast<DALootPowerUpClassHelper*>(InternalDALootPowerUpClassPointer);

		helper->SetIcon(
			reinterpret_cast<::WeaponDefinitionClass*>(weapon->WeaponDefinitionClassPointer.ToPointer()));
	}

	void DALootPowerUpClass::DestroyIcon()
	{
		auto helper = reinterpret_cast<DALootPowerUpClassHelper*>(InternalDALootPowerUpClassPointer);

		helper->DestroyIcon();
	}

	::DAGameObjObserverClass* DALootPowerUpClass::InternalDAGameObjObserverClassPointer::get()
	{
		return InternalDALootPowerUpClassPointer;
	}

	::DALootPowerUpClass* DALootPowerUpClass::InternalDALootPowerUpClassPointer::get()
	{
		return reinterpret_cast<::DALootPowerUpClass*>(Pointer.ToPointer());
	}

	IDynamicVectorClass<IcPlayer^>^ DALootPowerUpClass::Damagers::get()
	{
		auto helper = reinterpret_cast<DALootPowerUpClassHelper*>(InternalDALootPowerUpClassPointer);

		auto& damagers = helper->GetDamagers();

		return gcnew cPlayerPtrDynamicVectorClass(IntPtr(&damagers));
	}

	void DALootPowerUpClass::Damagers::set(IDynamicVectorClass<IcPlayer^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<DALootPowerUpClassHelper*>(InternalDALootPowerUpClassPointer);

		auto& damagers = helper->GetDamagers();

		damagers = *reinterpret_cast<::DynamicVectorClass<::cPlayer*>*>(value->Pointer.ToPointer());
	}

	IReferencerClass^ DALootPowerUpClass::Icon::get()
	{
		auto helper = reinterpret_cast<DALootPowerUpClassHelper*>(InternalDALootPowerUpClassPointer);

		auto& icon = helper->GetIcon();

		return gcnew ReferencerClass(IntPtr(&icon));
	}

	void DALootPowerUpClass::Icon::set(IReferencerClass^ value)
	{
		if (value == nullptr || value->ReferencerClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<DALootPowerUpClassHelper*>(InternalDALootPowerUpClassPointer);

		auto& icon = helper->GetIcon();

		icon = *reinterpret_cast<::ReferencerClass*>(value->ReferencerClassPointer.ToPointer());
	}

	DALootBackpackClass::DALootBackpackClass()
		: DALootPowerUpClass(IntPtr(Imports::CreateDALootBackpackClass1()))
	{

	}

	DALootBackpackClass::DALootBackpackClass(ISoldierGameObj^ soldier)
		: DALootPowerUpClass(false)
	{
		if (soldier == nullptr || soldier->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}

		Pointer = IntPtr(Imports::CreateDALootBackpackClass2(
			reinterpret_cast<::SoldierGameObj*>(soldier->SoldierGameObjPointer.ToPointer())));
	}

	DALootBackpackClass::DALootBackpackClass(IntPtr pointer)
		: DALootPowerUpClass(pointer)
	{

	}

	IUnmanagedContainer<IDALootBackpackClass^>^ DALootBackpackClass::CreateDALootBackpackClass()
	{
		return gcnew UnmanagedContainer<IDALootBackpackClass^>(gcnew DALootBackpackClass());
	}

	IUnmanagedContainer<IDALootBackpackClass^>^ DALootBackpackClass::CreateDALootBackpackClass(ISoldierGameObj^ soldier)
	{
		return gcnew UnmanagedContainer<IDALootBackpackClass^>(gcnew DALootBackpackClass(soldier));
	}

	void DALootBackpackClass::AddWeapon(IWeaponDefinitionClass^ weapon, int rounds)
	{
		if (weapon == nullptr || weapon->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		InternalDALootBackpackClassPointer->Add_Weapon(
			reinterpret_cast<::WeaponDefinitionClass*>(weapon->WeaponDefinitionClassPointer.ToPointer()),
			rounds);
	}

	IntPtr DALootBackpackClass::DALootBackpackClassPointer::get()
	{
		return IntPtr(InternalDALootBackpackClassPointer);
	}

	int DALootBackpackClass::WeaponCount::get()
	{
		return InternalDALootBackpackClassPointer->Get_Weapon_Count();
	}

	::DALootPowerUpClass* DALootBackpackClass::InternalDALootPowerUpClassPointer::get()
	{
		return InternalDALootBackpackClassPointer;
	}

	::DALootBackpackClass* DALootBackpackClass::InternalDALootBackpackClassPointer::get()
	{
		return reinterpret_cast<::DALootBackpackClass*>(Pointer.ToPointer());
	}

	DALootDNAClass::DALootDNAClass(ISoldierGameObjDef^ charDef)
		: DALootPowerUpClass(false)
	{
		if (charDef == nullptr || charDef->SoldierGameObjDefPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("charDef");
		}

		Pointer = IntPtr(Imports::CreateDALootDNAClass1(
			reinterpret_cast<::SoldierGameObjDef*>(charDef->SoldierGameObjDefPointer.ToPointer())));
	}

	DALootDNAClass::DALootDNAClass(ISoldierGameObj^ soldier) 
		: DALootPowerUpClass(false)
	{
		if (soldier == nullptr || soldier->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}

		Pointer = IntPtr(Imports::CreateDALootDNAClass2(
			reinterpret_cast<::SoldierGameObj*>(soldier->SoldierGameObjPointer.ToPointer())));
	}

	DALootDNAClass::DALootDNAClass(IntPtr pointer)
		: DALootPowerUpClass(pointer)
	{

	}

	IUnmanagedContainer<IDALootDNAClass^>^ DALootDNAClass::CreateDALootDNAClass(ISoldierGameObjDef^ charDef)
	{
		return gcnew UnmanagedContainer<IDALootDNAClass^>(gcnew DALootDNAClass(charDef));
	}

	IUnmanagedContainer<IDALootDNAClass^>^ DALootDNAClass::CreateDALootDNAClass(ISoldierGameObj^ soldier)
	{
		return gcnew UnmanagedContainer<IDALootDNAClass^>(gcnew DALootDNAClass(soldier));
	}

	IntPtr DALootDNAClass::DALootDNAClassPointer::get()
	{
		return IntPtr(InternalDALootDNAClassPointer);
	}

	::DALootPowerUpClass* DALootDNAClass::InternalDALootPowerUpClassPointer::get()
	{
		return InternalDALootDNAClassPointer;
	}

	::DALootDNAClass* DALootDNAClass::InternalDALootDNAClassPointer::get()
	{
		return reinterpret_cast<::DALootDNAClass*>(Pointer.ToPointer());
	}

	DALootGameFeatureClass::DALootGameFeatureClass()
		: DALootGameFeatureClass(IntPtr(Imports::CreateDALootGameFeatureClass()))
	{
		
	}

	DALootGameFeatureClass::DALootGameFeatureClass(IntPtr pointer)
		: DAEventClass(pointer)
	{
		daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
		daPlayerDataFactoryClass = gcnew DAPlayerDataFactoryClass(IntPtr(InternalDAPlayerDataFactoryClassPointer));
	}

	IUnmanagedContainer<IDALootGameFeatureClass^>^ DALootGameFeatureClass::CreateDALootGameFeatureClass()
	{
		return gcnew UnmanagedContainer<IDALootGameFeatureClass^>(gcnew DALootGameFeatureClass());
	}

	String^ DALootGameFeatureClass::ToString()
	{
		return daGameFeatureClass->ToString();
	}

	bool DALootGameFeatureClass::Equals(Object^ other)
	{
		if (DAEventClass::Equals(other))
		{
			return true;
		}

		if (ReferenceEquals(other, nullptr))
		{
			return false;
		}

		auto otherUnmanagedObj = dynamic_cast<IUnmanagedObject^>(other);
		if (otherUnmanagedObj == nullptr || otherUnmanagedObj->Pointer.Equals(IntPtr::Zero))
		{
			return false;
		}

		auto otherDAGameFeatureClass = dynamic_cast<IDAGameFeatureClass^>(other);
		if (otherDAGameFeatureClass != nullptr)
		{
			if (daGameFeatureClass->Equals(otherDAGameFeatureClass))
			{
				return true;
			}
		}

		auto otherDAPlayerDataFactoryClass = dynamic_cast<IDAPlayerDataFactoryClass^>(other);
		if (otherDAPlayerDataFactoryClass != nullptr)
		{
			if (daPlayerDataFactoryClass->Equals(otherDAPlayerDataFactoryClass))
			{
				return true;
			}
		}

		auto otherDALootGameFeatureClass = dynamic_cast<IDALootGameFeatureClass^>(other);
		if (otherDALootGameFeatureClass != nullptr)
		{
			if (DALootGameFeatureClassPointer.Equals(otherDALootGameFeatureClass->DALootGameFeatureClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void DALootGameFeatureClass::Init()
	{
		daGameFeatureClass->Init();
	}

	IRenSharpGameFeatureClass^ DALootGameFeatureClass::AsManagedGameFeature()
	{
		return daGameFeatureClass->AsManagedGameFeature();
	}

	IUnmanagedContainer<IDAPlayerDataClass^>^ DALootGameFeatureClass::CreateData()
	{
		return daPlayerDataFactoryClass->CreateData();
	}

	IRenSharpPlayerDataFactoryClass^ DALootGameFeatureClass::AsManagedPlayerDataFactory()
	{
		return daPlayerDataFactoryClass->AsManagedPlayerDataFactory();
	}

	IDALootPlayerDataClass^ DALootGameFeatureClass::GetPlayerData(int id)
	{
		auto result = InternalDALootGameFeatureClassPointer->Get_Player_Data(id);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DALootPlayerDataClass(IntPtr(result));
		}
	}

	IDALootPlayerDataClass^ DALootGameFeatureClass::GetPlayerData(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = InternalDALootGameFeatureClassPointer->Get_Player_Data(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DALootPlayerDataClass(IntPtr(result));
		}
	}

	IDALootPlayerDataClass^ DALootGameFeatureClass::GetPlayerData(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		auto result = InternalDALootGameFeatureClassPointer->Get_Player_Data(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DALootPlayerDataClass(IntPtr(result));
		}
	}

	IDALootPlayerDataClass^ DALootGameFeatureClass::GetPlayerData(IDAPlayerClass^ player)
	{
		if (player == nullptr || player->DAPlayerClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		auto result = InternalDALootGameFeatureClassPointer->Get_Player_Data(
			reinterpret_cast<::DAPlayerClass*>(player->DAPlayerClassPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DALootPlayerDataClass(IntPtr(result));
		}
	}

	IPowerUpGameObjDef^ DALootGameFeatureClass::GetCharacterPowerUpDrop(ISoldierGameObj^ soldier)
	{
		if (soldier == nullptr || soldier->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}

		auto defPtr = InternalDALootGameFeatureClassPointer->Get_Character_PowerUp_Drop(
			reinterpret_cast<::SoldierGameObj*>(soldier->SoldierGameObjPointer.ToPointer()));
		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IPowerUpGameObjDef^>(DefinitionClass::CreateDefinitionClassWrapper(defPtr));
		}
	}

	IPowerUpGameObjDef^ DALootGameFeatureClass::GetCharacterPowerUpDrop(ISoldierGameObjDef^ soldier)
	{
		if (soldier == nullptr || soldier->SoldierGameObjDefPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}

		auto defPtr = InternalDALootGameFeatureClassPointer->Get_Character_PowerUp_Drop(
			reinterpret_cast<::SoldierGameObjDef*>(soldier->SoldierGameObjDefPointer.ToPointer()));
		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IPowerUpGameObjDef^>(DefinitionClass::CreateDefinitionClassWrapper(defPtr));
		}
	}

	IDALootPowerUpClass^ DALootGameFeatureClass::CreatePowerUp(ISoldierGameObj^ soldier)
	{
		if (soldier == nullptr || soldier->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}

		auto result = InternalDALootGameFeatureClassPointer->Create_PowerUp(
			reinterpret_cast<::SoldierGameObj*>(soldier->SoldierGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DALootPowerUpClass(IntPtr(result));
		}
	}

	IDALootPowerUpClass^ DALootGameFeatureClass::CreatePowerUp(Vector3 position, ISoldierGameObjDef^ soldier)
	{
		if (soldier == nullptr || soldier->SoldierGameObjDefPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		auto result = InternalDALootGameFeatureClassPointer->Create_PowerUp(
			positionVec,
			reinterpret_cast<::SoldierGameObjDef*>(soldier->SoldierGameObjDefPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DALootPowerUpClass(IntPtr(result));
		}
	}

	IWeaponDefinitionClass^ DALootGameFeatureClass::GetCharacterWeaponDrop(ISoldierGameObj^ soldier)
	{
		if (soldier == nullptr || soldier->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}

		auto defPtr = InternalDALootGameFeatureClassPointer->Get_Character_Weapon_Drop(
			reinterpret_cast<::SoldierGameObj*>(soldier->SoldierGameObjPointer.ToPointer()));
		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IWeaponDefinitionClass^>(DefinitionClass::CreateDefinitionClassWrapper(defPtr));
		}
	}

	IWeaponDefinitionClass^ DALootGameFeatureClass::GetCharacterWeaponDrop(ISoldierGameObjDef^ soldier)
	{
		if (soldier == nullptr || soldier->SoldierGameObjDefPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}

		auto defPtr = InternalDALootGameFeatureClassPointer->Get_Character_Weapon_Drop(
			reinterpret_cast<::SoldierGameObjDef*>(soldier->SoldierGameObjDefPointer.ToPointer()));
		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IWeaponDefinitionClass^>(DefinitionClass::CreateDefinitionClassWrapper(defPtr));
		}
	}

	bool DALootGameFeatureClass::IsDroppable(IWeaponClass^ weapon)
	{
		if (weapon == nullptr || weapon->WeaponClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		return InternalDALootGameFeatureClassPointer->Is_Droppable(
			reinterpret_cast<::WeaponClass*>(weapon->WeaponClassPointer.ToPointer()));
	}

	bool DALootGameFeatureClass::IsDroppable(IWeaponDefinitionClass^ weapon)
	{
		if (weapon == nullptr || weapon->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		return InternalDALootGameFeatureClassPointer->Is_Droppable(
			reinterpret_cast<::WeaponDefinitionClass*>(weapon->WeaponDefinitionClassPointer.ToPointer()));
	}

	IDALootBackpackClass^ DALootGameFeatureClass::CreateBackpack(ISoldierGameObj^ soldier)
	{
		if (soldier == nullptr || soldier->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}

		auto result = InternalDALootGameFeatureClassPointer->Create_Backpack(
			reinterpret_cast<::SoldierGameObj*>(soldier->SoldierGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DALootBackpackClass(IntPtr(result));
		}
	}

	IDALootBackpackClass^ DALootGameFeatureClass::CreateBackpack(Vector3 position)
	{
		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		auto result = InternalDALootGameFeatureClassPointer->Create_Backpack(positionVec);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DALootBackpackClass(IntPtr(result));
		}
	}

	IDALootDNAClass^ DALootGameFeatureClass::CreateDNA(ISoldierGameObj^ soldier)
	{
		if (soldier == nullptr || soldier->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}

		auto result = InternalDALootGameFeatureClassPointer->Create_DNA(
			reinterpret_cast<::SoldierGameObj*>(soldier->SoldierGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DALootDNAClass(IntPtr(result));
		}
	}

	IDALootDNAClass^ DALootGameFeatureClass::CreateDNA(Vector3 position, ISoldierGameObjDef^ soldier)
	{
		if (soldier == nullptr || soldier->SoldierGameObjDefPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		auto result = InternalDALootGameFeatureClassPointer->Create_DNA(
			positionVec,
			reinterpret_cast<::SoldierGameObjDef*>(soldier->SoldierGameObjDefPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DALootDNAClass(IntPtr(result));
		}
	}

	IDALootGameFeatureClass^ DALootGameFeatureClass::Instance::get()
	{
		auto result = ::DALootGameFeatureClassRegistrant.Get_Instance();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DALootGameFeatureClass(IntPtr(static_cast<::DALootGameFeatureClass*>(result)));
		}
	}

	IDAGameFeatureRegistrant<IDALootGameFeatureClass^>^ DALootGameFeatureClass::Registrant::get()
	{
		return gcnew DALootGameFeatureClassDAGameFeatureRegistrant(IntPtr(&::DALootGameFeatureClassRegistrant));
	}

	IntPtr DALootGameFeatureClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void DALootGameFeatureClass::Pointer::set(IntPtr value)
	{
		AbstractUnmanagedObject::Pointer::set(value);

		if (Pointer == IntPtr::Zero)
		{
			daGameFeatureClass = nullptr;
			daPlayerDataFactoryClass = nullptr;
		}
		else
		{
			daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
			daPlayerDataFactoryClass = gcnew DAPlayerDataFactoryClass(IntPtr(InternalDAPlayerDataFactoryClassPointer));
		}
	}

	IntPtr DALootGameFeatureClass::DALootGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDALootGameFeatureClassPointer);
	}

	IntPtr DALootGameFeatureClass::DAGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAGameFeatureClassPointer);
	}

	IntPtr DALootGameFeatureClass::DAPlayerDataFactoryClassPointer::get()
	{
		return IntPtr(InternalDAPlayerDataFactoryClassPointer);
	}

	bool DALootGameFeatureClass::IsManagedPlayerDataFactory::get()
	{
		return daPlayerDataFactoryClass->IsManagedPlayerDataFactory;
	}

	String^ DALootGameFeatureClass::Name::get()
	{
		return daGameFeatureClass->Name;
	}

	IDAGameFeatureFactoryClass^ DALootGameFeatureClass::Factory::get()
	{
		return daGameFeatureClass->Factory;
	}

	void DALootGameFeatureClass::Factory::set(IDAGameFeatureFactoryClass^ value)
	{
		daGameFeatureClass->Factory = value;
	}

	bool DALootGameFeatureClass::IsManagedGameFeature::get()
	{
		return daGameFeatureClass->IsManagedGameFeature;
	}

	::DAEventClass* DALootGameFeatureClass::InternalDAEventClassPointer::get()
	{
		return InternalDALootGameFeatureClassPointer;
	}

	::DAGameFeatureClass* DALootGameFeatureClass::InternalDAGameFeatureClassPointer::get()
	{
		return InternalDALootGameFeatureClassPointer;
	}

	::DAPlayerDataFactoryClass* DALootGameFeatureClass::InternalDAPlayerDataFactoryClassPointer::get()
	{
		return InternalDALootGameFeatureClassPointer;
	}

	::DAPlayerDataManagerClass<::DALootPlayerDataClass>* DALootGameFeatureClass::InternalDAPlayerDataManagerClassPointer::get()
	{
		return InternalDALootGameFeatureClassPointer;
	}

	::DALootGameFeatureClass* DALootGameFeatureClass::InternalDALootGameFeatureClassPointer::get()
	{
		return reinterpret_cast<::DALootGameFeatureClass*>(Pointer.ToPointer());
	}

	DALootGameFeatureClassDAGameFeatureRegistrant::DALootGameFeatureClassDAGameFeatureRegistrant(IntPtr pointer)
		: DAGameFeatureRegistrant<IDALootGameFeatureClass^>(pointer)
	{

	}

	IntPtr DALootGameFeatureClassDAGameFeatureRegistrant::DALootGameFeatureClassDAGameFeatureRegistrantPointer::get()
	{
		return IntPtr(InternalDALootGameFeatureClassDAGameFeatureRegistrantPointer);
	}

	::DAGameFeatureFactoryClass* DALootGameFeatureClassDAGameFeatureRegistrant::InternalDAGameFeatureFactoryClassPointer::get()
	{
		return InternalDALootGameFeatureClassDAGameFeatureRegistrantPointer;
	}

	::DAGameFeatureRegistrant<::DALootGameFeatureClass>* DALootGameFeatureClassDAGameFeatureRegistrant::InternalDALootGameFeatureClassDAGameFeatureRegistrantPointer::get()
	{
		return reinterpret_cast<::DAGameFeatureRegistrant<::DALootGameFeatureClass>*>(Pointer.ToPointer());
	}
}