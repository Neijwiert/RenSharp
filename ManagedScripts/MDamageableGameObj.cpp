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
#include "MDamageableGameObj.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <DamageableGameObj.h>
#include <DamageableGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MDamageableGameObjDef.h"
#include "MDefenseObjectClass.h"
#include "MOffenseObjectClass.h"

namespace RenSharp
{
	DamageableGameObj::DamageableGameObj(IntPtr pointer)
		: ScriptableGameObj(pointer)
	{

	}

	IDamageableGameObj ^DamageableGameObj::AsDamageableGameObj()
	{
		return this;
	}

	void DamageableGameObj::ApplyDamage(IOffenseObjectClass ^damager, float scale, int alternateSkin)
	{
		if (damager == nullptr || damager->OffenseObjectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("damager");
		}

		InternalDamageableGameObjPointer->Apply_Damage(*reinterpret_cast<::OffenseObjectClass *>(damager->OffenseObjectClassPointer.ToPointer()), scale, alternateSkin);
	}

	void DamageableGameObj::ApplyDamage(IOffenseObjectClass ^damager, float scale)
	{
		if (damager == nullptr || damager->OffenseObjectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("damager");
		}

		InternalDamageableGameObjPointer->Apply_Damage(*reinterpret_cast<::OffenseObjectClass *>(damager->OffenseObjectClassPointer.ToPointer()), scale);
	}

	void DamageableGameObj::ApplyDamage(IOffenseObjectClass ^damager)
	{
		if (damager == nullptr || damager->OffenseObjectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("damager");
		}

		InternalDamageableGameObjPointer->Apply_Damage(*reinterpret_cast<::OffenseObjectClass *>(damager->OffenseObjectClassPointer.ToPointer()));
	}

	void DamageableGameObj::CompletelyDamaged(IOffenseObjectClass ^damager)
	{
		if (damager == nullptr || damager->OffenseObjectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("damager");
		}

		InternalDamageableGameObjPointer->Completely_Damaged(*reinterpret_cast<::OffenseObjectClass *>(damager->OffenseObjectClassPointer.ToPointer()));
	}

	bool DamageableGameObj::IsTeamPlayer()
	{
		return InternalDamageableGameObjPointer->Is_Team_Player();
	}

	bool DamageableGameObj::IsTeammate(IDamageableGameObj ^obj)
	{
		if (obj == nullptr || obj->DamageableGameObjPointer.ToPointer() == nullptr)
		{
			return InternalDamageableGameObjPointer->Is_Teammate(nullptr);
		}
		else
		{
			return InternalDamageableGameObjPointer->Is_Teammate(reinterpret_cast<::DamageableGameObj *>(obj->DamageableGameObjPointer.ToPointer()));
		}
	}

	bool DamageableGameObj::IsEnemy(IDamageableGameObj ^obj)
	{
		if (obj == nullptr || obj->DamageableGameObjPointer.ToPointer() == nullptr)
		{
			return InternalDamageableGameObjPointer->Is_Enemy(nullptr);
		}
		else
		{
			return InternalDamageableGameObjPointer->Is_Enemy(reinterpret_cast<::DamageableGameObj *>(obj->DamageableGameObjPointer.ToPointer()));
		}
	}

	IntPtr DamageableGameObj::DamageableGameObjPointer::get()
	{
		return IntPtr(InternalDamageableGameObjPointer);
	}

	IDamageableGameObjDef ^DamageableGameObj::Definition::get()
	{
		return safe_cast<IDamageableGameObjDef^>(DefinitionClass::CreateDefinitionClassWrapper(&InternalDamageableGameObjPointer->Get_Definition()));
	}

	IDefenseObjectClass ^DamageableGameObj::DefenseObject::get()
	{
		return gcnew DefenseObjectClass(IntPtr(InternalDamageableGameObjPointer->Get_Defense_Object()));
	}

	void DamageableGameObj::DefenseObject::set(IDefenseObjectClass ^value)
	{
		if (value == nullptr || value->DefenseObjectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto defenseObject = InternalDamageableGameObjPointer->Get_Defense_Object();

		(*defenseObject) = *reinterpret_cast<::DefenseObjectClass *>(value->DefenseObjectClassPointer.ToPointer());
	}

	String ^DamageableGameObj::InfoIconTextureFilename::get()
	{
		return gcnew String(InternalDamageableGameObjPointer->Get_Info_Icon_Texture_Filename().Peek_Buffer());
	}

	int DamageableGameObj::TranslatedNameID::get()
	{
		return InternalDamageableGameObjPointer->Get_Translated_Name_ID();
	}

	bool DamageableGameObj::Targetable::get()
	{
		return InternalDamageableGameObjPointer->Is_Targetable();
	}

	bool DamageableGameObj::IsHealthBarDisplayed::get()
	{
		return InternalDamageableGameObjPointer->Is_Health_Bar_Displayed();
	}

	void DamageableGameObj::IsHealthBarDisplayed::set(bool value)
	{
		InternalDamageableGameObjPointer->Set_Is_Health_Bar_Displayed(value);
	}

	int DamageableGameObj::PlayerType::get()
	{
		return InternalDamageableGameObjPointer->Get_Player_Type();
	}

	void DamageableGameObj::PlayerType::set(int value)
	{
		InternalDamageableGameObjPointer->Set_Player_Type(value);
	}

	bool DamageableGameObj::IsDamaged::get()
	{
		return InternalDamageableGameObjPointer->Is_Damaged();
	}

	::ScriptableGameObj *DamageableGameObj::InternalScriptableGameObjPointer::get()
	{
		return InternalDamageableGameObjPointer;
	}

	::DamageableGameObj *DamageableGameObj::InternalDamageableGameObjPointer::get()
	{
		return reinterpret_cast<::DamageableGameObj *>(Pointer.ToPointer());
	}
}