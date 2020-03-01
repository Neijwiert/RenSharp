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
#include "MWeaponClass.h"

#include "MArmedGameObj.h"
#include "MMatrix3D.h"
#include "MVector3.h"
#include "Mweaponmgr.h"

using namespace System::Text;

namespace RenSharp
{
	WeaponClass::WeaponClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	String ^WeaponClass::ToString()
	{
		StringBuilder ^builder = gcnew StringBuilder();
		builder->Append(Name);

		return builder->ToString();
	}

	bool WeaponClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IWeaponClass ^otherThis = dynamic_cast<IWeaponClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return WeaponClassPointer.Equals(otherThis->WeaponClassPointer);
	}

	void WeaponClass::ResetModelUpdate()
	{
		InternalWeaponClassPointer->Reset_Model_Update();
	}

	void WeaponClass::ResetAnimUpdate()
	{
		InternalWeaponClassPointer->Reset_Anim_Update();
	}

	void WeaponClass::ClearFiringSound()
	{
		InternalWeaponClassPointer->Clear_Firing_Sound();
	}

	void WeaponClass::SetDidFire(bool fire)
	{
		InternalWeaponClassPointer->Set_Did_Fire(fire);
	}

	IntPtr WeaponClass::WeaponClassPointer::get()
	{
		return IntPtr(InternalWeaponClassPointer);
	}

	IArmedGameObj ^WeaponClass::Owner::get()
	{
		auto result = InternalWeaponClassPointer->Get_Owner();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IArmedGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IWeaponDefinitionClass ^WeaponClass::Definition::get()
	{
		auto defPtr = InternalWeaponClassPointer->Get_Definition();
		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IWeaponDefinitionClass^>(DefinitionClass::CreateDefinitionClassWrapper(defPtr));
		}
	}

	String ^WeaponClass::Name::get()
	{
		auto result = InternalWeaponClassPointer->Get_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	int WeaponClass::ID::get()
	{
		return InternalWeaponClassPointer->Get_ID();
	}

	String ^WeaponClass::HUDIconTextureName::get()
	{
		auto result = InternalWeaponClassPointer->Get_HUD_Icon_Texture_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String ^WeaponClass::ModelName::get()
	{
		auto result = InternalWeaponClassPointer->Get_Model_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String ^WeaponClass::BackModelName::get()
	{
		auto result = InternalWeaponClassPointer->Get_Back_Model_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String ^WeaponClass::AnimName::get()
	{
		auto result = InternalWeaponClassPointer->Get_Anim_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String ^WeaponClass::FirstPersonAnimName::get()
	{
		auto result = InternalWeaponClassPointer->Get_First_Person_Anim_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	int WeaponClass::Style::get()
	{
		return InternalWeaponClassPointer->Get_Style();
	}

	float WeaponClass::KeyNumber::get()
	{
		return InternalWeaponClassPointer->Get_Key_Number();
	}

	bool WeaponClass::CanSnipe::get()
	{
		return InternalWeaponClassPointer->Get_Can_Snipe();
	}

	float WeaponClass::Rating::get()
	{
		return InternalWeaponClassPointer->Get_Rating();
	}

	float WeaponClass::EffectiveRange::get()
	{
		return InternalWeaponClassPointer->Get_Effective_Range();
	}

	float WeaponClass::PrimaryFireRate::get()
	{
		return InternalWeaponClassPointer->Get_Primary_Fire_Rate();
	}

	String ^WeaponClass::FirstPersonModelName::get()
	{
		auto result = InternalWeaponClassPointer->Get_First_Person_Model_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	Vector3 WeaponClass::FirstPersonModelOffset::get()
	{
		Vector3 result;
		Vector3::UnmanagedToManagedVector3(InternalWeaponClassPointer->Get_First_Person_Model_Offset(), result);

		return result;
	}

	float WeaponClass::RecoilTime::get()
	{
		return InternalWeaponClassPointer->Get_Recoil_Time();
	}

	float WeaponClass::RecoilScale::get()
	{
		return InternalWeaponClassPointer->Get_Recoil_Scale();
	}

	int WeaponClass::TotalRounds::get()
	{
		return InternalWeaponClassPointer->Get_Total_Rounds();
	}

	int WeaponClass::ClipRounds::get()
	{
		return InternalWeaponClassPointer->Get_Clip_Rounds();
	}

	int WeaponClass::InventoryRounds::get()
	{
		return InternalWeaponClassPointer->Get_Inventory_Rounds();
	}

	bool WeaponClass::IsAmmoMaxed::get()
	{
		return InternalWeaponClassPointer->Is_Ammo_Maxed();
	}

	bool WeaponClass::IsLoaded::get()
	{
		return InternalWeaponClassPointer->Is_Loaded();
	}

	float WeaponClass::Range::get()
	{
		return InternalWeaponClassPointer->Get_Range();
	}

	bool WeaponClass::IsModelUpdateNeeded::get()
	{
		return InternalWeaponClassPointer->Is_Model_Update_Needed();
	}

	bool WeaponClass::IsAnimUpdateNeeded::get()
	{
		return InternalWeaponClassPointer->Is_Anim_Update_Needed();
	}

	WeaponAnimState WeaponClass::AnimState::get()
	{
		return static_cast<WeaponAnimState>(InternalWeaponClassPointer->Get_Anim_State());
	}

	int WeaponClass::TotalRoundsFired::get()
	{
		return InternalWeaponClassPointer->Get_Total_Rounds_Fired();
	}

	Vector3 WeaponClass::Target::get()
	{
		Vector3 result;
		Vector3::UnmanagedToManagedVector3(InternalWeaponClassPointer->Get_Target(), result);

		return result;
	}

	void WeaponClass::Target::set(Vector3 value)
	{
		::Vector3 tmp;

		Vector3::ManagedToUnmanagedVector3(value, tmp);

		InternalWeaponClassPointer->Set_Target(tmp);
	}

	IWeaponClass::WeaponStateType WeaponClass::State::get()
	{
		return static_cast<IWeaponClass::WeaponStateType>(InternalWeaponClassPointer->Get_State());
	}

	bool WeaponClass::IsFiring::get()
	{
		return InternalWeaponClassPointer->Is_Firing();
	}

	bool WeaponClass::IsReloading::get()
	{
		return InternalWeaponClassPointer->Is_Reloading();
	}

	bool WeaponClass::IsSwitching::get()
	{
		return InternalWeaponClassPointer->Is_Switching();
	}

	bool WeaponClass::SafetySet::get()
	{
		return InternalWeaponClassPointer->Is_Safety_Set();
	}

	void WeaponClass::SafetySet::set(bool value)
	{
		InternalWeaponClassPointer->Set_Safety(value);
	}

	bool WeaponClass::IsTriggered::get()
	{
		return InternalWeaponClassPointer->Is_Triggered();
	}

	bool WeaponClass::WeaponExists::get()
	{
		return InternalWeaponClassPointer->Does_Weapon_Exist();
	}

	void WeaponClass::WeaponExists::set(bool value)
	{
		InternalWeaponClassPointer->Set_Weapon_Exists(value);
	}

	float WeaponClass::TargetingRange::get()
	{
		return InternalWeaponClassPointer->Get_Targeting_Range();
	}

	bool WeaponClass::TiltGunWhileReloading::get()
	{
		return InternalWeaponClassPointer->Tilt_Gun_While_Reloading();
	}

	IAmmoDefinitionClass ^WeaponClass::PrimaryAmmoDefinition::get()
	{
		auto defPtr = InternalWeaponClassPointer->PrimaryAmmoDefinition;
		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IAmmoDefinitionClass^>(DefinitionClass::CreateDefinitionClassWrapper(defPtr));
		}
	}

	IAmmoDefinitionClass ^WeaponClass::SecondaryAmmoDefinition::get()
	{
		auto defPtr = InternalWeaponClassPointer->SecondaryAmmoDefinition;
		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IAmmoDefinitionClass^>(DefinitionClass::CreateDefinitionClassWrapper(defPtr));
		}
	}

	::WeaponClass *WeaponClass::InternalWeaponClassPointer::get()
	{
		return reinterpret_cast<::WeaponClass *>(Pointer.ToPointer());
	}
}