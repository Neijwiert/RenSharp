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
#include "MGlobalSettingsDef.h"

#pragma managed(push, off)

class GlobalSettingsDef : public DefinitionClass
{
	private:
		GlobalSettingsDef() = default;

	public:
		static REF_DECL(GlobalSettingsDef*, GlobalSettings);

		int DeathSoundID;
		int EVAObjectivesSoundID;
		int HUDHelpTextSoundID;
		float MaxConversationDist;
		float MaxCombatConversationDist;
		float SoldierWalkSpeed;
		float SoldierCrouchSpeed;
		float FallingDamageMinDistance;
		float FallingDamageMaxDistance;
		StringClass PurchaseGDICharactersTexture;
		StringClass PurchaseGDIVehiclesTexture;
		StringClass PurchaseGDIEquipmentTexture;
		StringClass PurchaseNODCharactersTexture;
		StringClass PurchaseNODVehiclesTexture;
		StringClass PurchaseNODEquipmentTexture;
		StringClass PurchaseGDIMUTCharactersTexture;
		StringClass PurchaseGDIMUTVehiclesTexture;
		StringClass PurchaseGDIMUTEquipmentTexture;
		StringClass PurchaseNODMUTCharactersTexture;
		StringClass PurchaseNODMUTVehiclesTexture;
		StringClass PurchaseNODMUTEquipmentTexture;
		int EncyclopediaEventStringID;
		int FallingDamageWarhead;
		float StealthDistanceHuman;
		float StealthDistanceVehicle;
		float MPStealthDistanceHuman;
		float MPStealthDistanceVehicle;
		float UndergroundFadeDistance;
		int GDISoldierID;
		int NodSoldierID;
		float SoldierFlySpeed;
		StringClass VisceroidName;
};

REF_DEF3(GlobalSettingsDef*, GlobalSettingsDef::GlobalSettings, 0x0085E260, 0x0085D438, 0x0085EBB0);

#pragma managed(pop)

namespace RenSharp
{
	GlobalSettingsDef::GlobalSettingsDef(IntPtr pointer)
		: DefinitionClass(pointer)
	{

	}

	IGlobalSettingsDef^ GlobalSettingsDef::GlobalSettings::get()
	{
		auto result = ::GlobalSettingsDef::GlobalSettings;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew GlobalSettingsDef(IntPtr(result));
		}
	}

	IntPtr GlobalSettingsDef::GlobalSettingsDefPointer::get()
	{
		return IntPtr(InternalGlobalSettingsDefPointer);
	}

	int GlobalSettingsDef::DeathSoundID::get()
	{
		return InternalGlobalSettingsDefPointer->DeathSoundID;
	}

	int GlobalSettingsDef::EVAObjectivesSoundID::get()
	{
		return InternalGlobalSettingsDefPointer->EVAObjectivesSoundID;
	}

	int GlobalSettingsDef::HUDHelpTextSoundID::get()
	{
		return InternalGlobalSettingsDefPointer->HUDHelpTextSoundID;
	}

	float GlobalSettingsDef::MaxConversationDist::get()
	{
		return InternalGlobalSettingsDefPointer->MaxConversationDist;
	}

	float GlobalSettingsDef::MaxCombatConversationDist::get()
	{
		return InternalGlobalSettingsDefPointer->MaxCombatConversationDist;
	}

	float GlobalSettingsDef::SoldierWalkSpeed::get()
	{
		return InternalGlobalSettingsDefPointer->SoldierWalkSpeed;
	}

	float GlobalSettingsDef::SoldierCrouchSpeed::get()
	{
		return InternalGlobalSettingsDefPointer->SoldierCrouchSpeed;
	}

	float GlobalSettingsDef::FallingDamageMinDistance::get()
	{
		return InternalGlobalSettingsDefPointer->FallingDamageMinDistance;
	}

	float GlobalSettingsDef::FallingDamageMaxDistance::get()
	{
		return InternalGlobalSettingsDefPointer->FallingDamageMaxDistance;
	}

	String^ GlobalSettingsDef::PurchaseGDICharactersTexture::get()
	{
		return gcnew String(InternalGlobalSettingsDefPointer->PurchaseGDICharactersTexture.Peek_Buffer());
	}

	String^ GlobalSettingsDef::PurchaseGDIVehiclesTexture::get()
	{
		return gcnew String(InternalGlobalSettingsDefPointer->PurchaseGDIVehiclesTexture.Peek_Buffer());
	}

	String^ GlobalSettingsDef::PurchaseGDIEquipmentTexture::get()
	{
		return gcnew String(InternalGlobalSettingsDefPointer->PurchaseGDIEquipmentTexture.Peek_Buffer());
	}

	String^ GlobalSettingsDef::PurchaseNODCharactersTexture::get()
	{
		return gcnew String(InternalGlobalSettingsDefPointer->PurchaseNODCharactersTexture.Peek_Buffer());
	}

	String^ GlobalSettingsDef::PurchaseNODVehiclesTexture::get()
	{
		return gcnew String(InternalGlobalSettingsDefPointer->PurchaseNODVehiclesTexture.Peek_Buffer());
	}

	String^ GlobalSettingsDef::PurchaseNODEquipmentTexture::get()
	{
		return gcnew String(InternalGlobalSettingsDefPointer->PurchaseNODEquipmentTexture.Peek_Buffer());
	}

	String^ GlobalSettingsDef::PurchaseGDIMUTCharactersTexture::get()
	{
		return gcnew String(InternalGlobalSettingsDefPointer->PurchaseGDIMUTCharactersTexture.Peek_Buffer());
	}

	String^ GlobalSettingsDef::PurchaseGDIMUTVehiclesTexture::get()
	{
		return gcnew String(InternalGlobalSettingsDefPointer->PurchaseGDIMUTVehiclesTexture.Peek_Buffer());
	}

	String^ GlobalSettingsDef::PurchaseGDIMUTEquipmentTexture::get()
	{
		return gcnew String(InternalGlobalSettingsDefPointer->PurchaseGDIMUTEquipmentTexture.Peek_Buffer());
	}

	String^ GlobalSettingsDef::PurchaseNODMUTCharactersTexture::get()
	{
		return gcnew String(InternalGlobalSettingsDefPointer->PurchaseNODMUTCharactersTexture.Peek_Buffer());
	}

	String^ GlobalSettingsDef::PurchaseNODMUTVehiclesTexture::get()
	{
		return gcnew String(InternalGlobalSettingsDefPointer->PurchaseNODMUTVehiclesTexture.Peek_Buffer());
	}

	String^ GlobalSettingsDef::PurchaseNODMUTEquipmentTexture::get()
	{
		return gcnew String(InternalGlobalSettingsDefPointer->PurchaseNODMUTEquipmentTexture.Peek_Buffer());
	}

	int GlobalSettingsDef::EncyclopediaEventStringID::get()
	{
		return InternalGlobalSettingsDefPointer->EncyclopediaEventStringID;
	}

	int GlobalSettingsDef::FallingDamageWarhead::get()
	{
		return InternalGlobalSettingsDefPointer->FallingDamageWarhead;
	}

	float GlobalSettingsDef::StealthDistanceHuman::get()
	{
		return InternalGlobalSettingsDefPointer->StealthDistanceHuman;
	}

	float GlobalSettingsDef::StealthDistanceVehicle::get()
	{
		return InternalGlobalSettingsDefPointer->StealthDistanceVehicle;
	}

	float GlobalSettingsDef::MPStealthDistanceHuman::get()
	{
		return InternalGlobalSettingsDefPointer->MPStealthDistanceHuman;
	}

	float GlobalSettingsDef::MPStealthDistanceVehicle::get()
	{
		return InternalGlobalSettingsDefPointer->MPStealthDistanceVehicle;
	}

	float GlobalSettingsDef::UndergroundFadeDistance::get()
	{
		return InternalGlobalSettingsDefPointer->UndergroundFadeDistance;
	}

	int GlobalSettingsDef::GDISoldierID::get()
	{
		return InternalGlobalSettingsDefPointer->GDISoldierID;
	}

	void GlobalSettingsDef::GDISoldierID::set(int value)
	{
		InternalGlobalSettingsDefPointer->GDISoldierID = value;
	}

	int GlobalSettingsDef::NodSoldierID::get()
	{
		return InternalGlobalSettingsDefPointer->NodSoldierID;
	}

	void GlobalSettingsDef::NodSoldierID::set(int value)
	{
		InternalGlobalSettingsDefPointer->NodSoldierID = value;
	}

	float GlobalSettingsDef::SoldierFlySpeed::get()
	{
		return InternalGlobalSettingsDefPointer->SoldierFlySpeed;
	}

	String^ GlobalSettingsDef::VisceroidName::get()
	{
		return gcnew String(InternalGlobalSettingsDefPointer->VisceroidName.Peek_Buffer());
	}

	::DefinitionClass* GlobalSettingsDef::InternalDefinitionClassPointer::get()
	{
		return InternalGlobalSettingsDefPointer;
	}

	::GlobalSettingsDef* GlobalSettingsDef::InternalGlobalSettingsDefPointer::get()
	{
		return reinterpret_cast<::GlobalSettingsDef*>(Pointer.ToPointer());
	}
}