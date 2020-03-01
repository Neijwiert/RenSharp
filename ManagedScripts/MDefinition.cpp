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
#include "MDefinition.h"

#include "MAirFactoryGameObjDef.h"
#include "MAirStripGameObjDef.h"
#include "MBeaconGameObjDef.h"
#include "MBuildingGameObjDef.h"
#include "MC4GameObjDef.h"
#include "MConstructionYardGameObjDef.h"
#include "MDamageZoneGameObjDef.h"
#include "MPhysDefClass.h"
#include "MDynamicPhysDefClass.h"
#include "MMoveablePhysDefClass.h"
#include "MNavalFactoryGameObjDef.h"
#include "MPurchaseSettingsDefClass.h"
#include "MRefineryGameObjDef.h"
#include "MRepairBayGameObjDef.h"
#include "MScriptZoneGameObjDef.h"
#include "MSimpleGameObjDef.h"
#include "MTeamPurchaseSettingsDefClass.h"
#include "MVehicleFactoryGameObjDef.h"
#include "MVehicleGameObjDef.h"
#include "MAudibleSoundDefinitionClass.h"
#include "MStaticPhysDefClass.h"
#include "MStaticAnimPhysDefClass.h"
#include "MBuildingAggregateDefClass.h"
#include "MCinematicGameObjDef.h"
#include "MComCenterGameObjDef.h"
#include "MDecorationPhysDefClass.h"
#include "MPowerPlantGameObjDef.h"
#include "MSamSiteGameObjDef.h"
#include "MSoldierFactoryGameObjDef.h"
#include "MSoldierGameObjDef.h"
#include "MSpawnerDefClass.h"
#include "MSpecialEffectsGameObjDef.h"
#include "MSuperweaponGameObjDef.h"
#include "MTransitionGameObjDef.h"
#include "MWarFactoryGameObjDef.h"
#include "Mweaponmgr.h"
#include "MPowerUpGameObjDef.h"
#include "MTwiddlerClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <Definition.h>
#include <PhysDefClass.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Text;

namespace RenSharp
{
	DefinitionClass::DefinitionClass(IntPtr pointer)
		: EditableClass(pointer)
	{

	}

	IDefinitionClass^ DefinitionClass::CreateDefinitionClassWrapper(IntPtr definitionClassPtr)
	{
		return CreateDefinitionClassWrapper(reinterpret_cast<::DefinitionClass*>(definitionClassPtr.ToPointer()));
	}

	String ^DefinitionClass::ToString()
	{
		StringBuilder ^builder = gcnew StringBuilder();
		builder->Append(Name);

		return builder->ToString();
	}

	IPersistClass ^DefinitionClass::Create()
	{
		auto result = InternalDefinitionClassPointer->Create();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PersistClass(IntPtr(result));
		}
	}

	bool DefinitionClass::IsValidConfig(String ^%message)
	{
		StringClass messageResult;
		bool result = InternalDefinitionClassPointer->Is_Valid_Config(messageResult);

		message = gcnew String(messageResult.Peek_Buffer());

		return result;
	}

	IntPtr DefinitionClass::DefinitionClassPointer::get()
	{
		return IntPtr(InternalDefinitionClassPointer);
	}

	uint32 DefinitionClass::ClassID::get()
	{
		return InternalDefinitionClassPointer->Get_Class_ID();
	}

	uint32 DefinitionClass::ID::get()
	{
		return InternalDefinitionClassPointer->Get_ID();
	}

	void DefinitionClass::ID::set(uint32 value)
	{
		InternalDefinitionClassPointer->Set_ID(value);
	}

	String ^DefinitionClass::Name::get()
	{
		auto result = InternalDefinitionClassPointer->Get_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	void DefinitionClass::Name::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalDefinitionClassPointer->Set_Name(reinterpret_cast<char *>(valueHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	uint32 DefinitionClass::UserData::get()
	{
		return InternalDefinitionClassPointer->Get_User_Data();
	}

	void DefinitionClass::UserData::set(uint32 value)
	{
		InternalDefinitionClassPointer->Set_User_Data(value);
	}

	bool DefinitionClass::IsSaveEnabled::get()
	{
		return InternalDefinitionClassPointer->Is_Save_Enabled();
	}

	void DefinitionClass::IsSaveEnabled::set(bool value)
	{
		InternalDefinitionClassPointer->Enable_Save(value);
	}

	IDefinitionClass^ DefinitionClass::CreateDefinitionClassWrapper(const ::DefinitionClass* definitionClassPtr)
	{
		if (definitionClassPtr == nullptr)
		{
			throw gcnew ArgumentNullException("definitionClassPtr");
		}

		IntPtr wrappedDefinitionClassPtr = IntPtr(const_cast<::DefinitionClass*>(definitionClassPtr));

		auto classId = definitionClassPtr->Get_Class_ID();
		switch (classId)
		{
			case IAirFactoryGameObjDef::AirFactoryGameObjDefClassID:
				return gcnew AirFactoryGameObjDef(wrappedDefinitionClassPtr);
			case IAirStripGameObjDef::AirStripGameObjDefClassID:
				return gcnew AirStripGameObjDef(wrappedDefinitionClassPtr);
			case IBeaconGameObjDef::BeaconGameObjDefClassID:
				return gcnew BeaconGameObjDef(wrappedDefinitionClassPtr);
			case IC4GameObjDef::C4GameObjDefClassID:
				return gcnew C4GameObjDef(wrappedDefinitionClassPtr);
			case IConstructionYardGameObjDef::ConstructionYardGameObjDefClassID:
				return gcnew ConstructionYardGameObjDef(wrappedDefinitionClassPtr);
			case IDamageZoneGameObjDef::DamageZoneGameObjDefClassID:
				return gcnew DamageZoneGameObjDef(wrappedDefinitionClassPtr);
			case INavalFactoryGameObjDef::NavalFactoryGameObjDefClassID:
				return gcnew NavalFactoryGameObjDef(wrappedDefinitionClassPtr);
			case IPurchaseSettingsDefClass::PurchaseSettingsDefClassClassID:
				return gcnew PurchaseSettingsDefClass(wrappedDefinitionClassPtr);
			case IRefineryGameObjDef::RefineryGameObjDefClassID:
				return gcnew RefineryGameObjDef(wrappedDefinitionClassPtr);
			case IRepairBayGameObjDef::RepairBayGameObjDefClassID:
				return gcnew RepairBayGameObjDef(wrappedDefinitionClassPtr);
			case IScriptZoneGameObjDef::ScriptZoneGameObjDefClassID:
				return gcnew ScriptZoneGameObjDef(wrappedDefinitionClassPtr);
			case ITeamPurchaseSettingsDefClass::TeamPurchaseSettingsDefClassClassID:
				return gcnew TeamPurchaseSettingsDefClass(wrappedDefinitionClassPtr);
			case IVehicleGameObjDef::VehicleGameObjDefClassID:
			case 12308: // SakuraBossGameObjDef
				return gcnew VehicleGameObjDef(wrappedDefinitionClassPtr);
			case IAudibleSoundDefinitionClass::AudibleSoundDefinitionClassClassID:
				return gcnew AudibleSoundDefinitionClass(wrappedDefinitionClassPtr);
			case ICinematicGameObjDef::CinematicGameObjDefClassID:
				return gcnew CinematicGameObjDef(wrappedDefinitionClassPtr);
			case IComCenterGameObjDef::ComCenterGameObjDefClassID:
				return gcnew ComCenterGameObjDef(wrappedDefinitionClassPtr);
			case IPowerPlantGameObjDef::PowerPlantGameObjDefClassID:
				return gcnew PowerPlantGameObjDef(wrappedDefinitionClassPtr);
			case ISAMSiteGameObjDef::SAMSiteGameObjDefClassID:
				return gcnew SAMSiteGameObjDef(wrappedDefinitionClassPtr);
			case ISoldierGameObjDef::SoldierGameObjDefClassID:
			case 12311: // MendozaBossGameObjDefClass
			case 12312: // RaveshawBossGameObjDefClass
				return gcnew SoldierGameObjDef(wrappedDefinitionClassPtr);
			case ISpawnerDefClass::SpawnerDefClassClassID:
				return gcnew SpawnerDefClass(wrappedDefinitionClassPtr);
			case ISpecialEffectsGameObjDef::SpecialEffectsGameObjDefClassID:
				return gcnew SpecialEffectsGameObjDef(wrappedDefinitionClassPtr);
			case ISuperweaponGameObjDef::SuperweaponGameObjDefClassID:
				return gcnew SuperweaponGameObjDef(wrappedDefinitionClassPtr);
			case ITransitionGameObjDef::TransitionGameObjDefClassID:
				return gcnew TransitionGameObjDef(wrappedDefinitionClassPtr);
			case IWarFactoryGameObjDef::WarFactoryGameObjDefClassID:
				return gcnew WarFactoryGameObjDef(wrappedDefinitionClassPtr);
			case ISoldierFactoryGameObjDef::SoldierFactoryGameObjDefClassID:
				return gcnew SoldierFactoryGameObjDef(wrappedDefinitionClassPtr);
			case IVehicleFactoryGameObjDef::VehicleFactoryGameObjDefClassID:
				return gcnew VehicleFactoryGameObjDef(wrappedDefinitionClassPtr);
			case IBuildingAggregateDefClass::BuildingAggregateDefClassClassID:
				return gcnew BuildingAggregateDefClass(wrappedDefinitionClassPtr);
			case IDecorationPhysDefClass::DecorationPhysDefClassClassID:
			case 36878: // DynamicAnimPhysDefClass
			case 36874: // TimedDecorationPhysDefClass
				return gcnew DecorationPhysDefClass(wrappedDefinitionClassPtr);
			case IStaticAnimPhysDefClass::StaticAnimPhysDefClassClassID:
			case 36880: // AccessiblePhysDefClass
			case 36994: // DamageableStaticPhysDefClass
			case 36992: // DoorPhysDefClass
			case 36993: // ElevatorPhysDefClass
			case 36879: // ShakeableStaticPhysDefClass
				return gcnew StaticAnimPhysDefClass(wrappedDefinitionClassPtr);
			case IStaticPhysDefClass::StaticPhysDefClassClassID:
				return gcnew StaticPhysDefClass(wrappedDefinitionClassPtr);
			case ISimpleGameObjDef::SimpleGameObjDefClassID:
				return gcnew SimpleGameObjDef(wrappedDefinitionClassPtr);
			case IBuildingGameObjDef::BuildingGameObjDefClassID:
				return gcnew BuildingGameObjDef(wrappedDefinitionClassPtr);
			case IAmmoDefinitionClass::AmmoDefinitionClassClassID:
				return gcnew AmmoDefinitionClass(wrappedDefinitionClassPtr);
			case IWeaponDefinitionClass::WeaponDefinitionClassClassID:
				return gcnew WeaponDefinitionClass(wrappedDefinitionClassPtr);
			case IExplosionDefinitionClass::ExplosionDefinitionClassClassID:
				return gcnew ExplosionDefinitionClass(wrappedDefinitionClassPtr);
			case IPowerUpGameObjDef::PowerUpGameObjDefClassID:
				return gcnew PowerUpGameObjDef(wrappedDefinitionClassPtr);
			case ITwiddlerClass::TwiddlerClassClassID:
				return gcnew TwiddlerClass(wrappedDefinitionClassPtr);
			case 36869: // RigidBodyDefClass
			case 36875: // VehiclePhysDefClass
			case 36881: // AircraftPhysDefClass
			case 36868: // Phys3DefClass
			case 36865: // HumanPhysDefClass
			case 36867: // MotorVehicleDefClass
			case 36870: // WheeledVehicleDefClass
			case 36866: // MotorcycleDefClass
			case 36873: // ProjectileDefClass
			case 36876: // TrackedVehicleDefClass
			case 36877: // VTOLVehicleDefClass
				return gcnew MoveablePhysDefClass(wrappedDefinitionClassPtr);
			case 61446: // CharacterClassSettingsDefClass
			case 61450: // CNCModeSettingsDef
			case 61445: // EvaSettingsDefClass
			case 61443: // GlobalSettingsDef
			case 61444: // HUDGlobalSettingsDef
			case 61447: // HumanAnimOverrideDef
			case 61442: // HumanLoiterGlobalSettingsDef
				return gcnew DefinitionClass(wrappedDefinitionClassPtr);
			default:
				throw gcnew InvalidOperationException(String::Format("Unknown DefinitionClass class ID {0}.", classId)); // Let caller decide
		}
	}

	::EditableClass *DefinitionClass::InternalEditableClassPointer::get()
	{
		return InternalDefinitionClassPointer;
	}

	::DefinitionClass *DefinitionClass::InternalDefinitionClassPointer::get()
	{
		return reinterpret_cast<::DefinitionClass *>(Pointer.ToPointer());
	}

	int DefinitionClass::DefinitionMgrLink::get()
	{
		auto helper = reinterpret_cast<DefinitionClassHelper *>(InternalDefinitionClassPointer);

		auto &definitionMgrLink = helper->GetDefinitionMgrLink();

		return definitionMgrLink;
	}

	void DefinitionClass::DefinitionMgrLink::set(int value)
	{
		auto helper = reinterpret_cast<DefinitionClassHelper *>(InternalDefinitionClassPointer);

		auto &definitionMgrLink = helper->GetDefinitionMgrLink();

		definitionMgrLink = value;
	}
}