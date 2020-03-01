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
#include "MBaseGameObj.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <BaseGameObj.h>
#include <BaseGameObjDef.h>
#include <PhysicalGameObj.h>
#include <ScriptableGameObj.h>
#include <SmartGameObj.h>
#include <VehicleGameObj.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MBaseGameObjDef.h"
#include "MPhysicalGameObj.h"
#include "MVehicleGameObj.h"
#include "MSmartGameObj.h"
#include "MScriptableGameObj.h"
#include "MSoldierGameObj.h"
#include "MSamSiteGameObj.h"
#include "MSamSiteGameObjDef.h"
#include "MPowerUpGameObj.h"
#include "MC4GameObj.h"
#include "MBeaconGameObj.h"
#include "MCinematicGameObj.h"
#include "MSpecialEffectsGameObj.h"
#include "MSpecialEffectsGameObjDef.h"
#include "MSimpleGameObj.h"
#include "MArmedGameObj.h"
#include "MPhysicalGameObj.h"
#include "MScriptZoneGameObj.h"
#include "MSoldierFactoryGameObj.h"
#include "MVehicleFactoryGameObj.h"
#include "MAirStripGameObj.h"
#include "MWarFactoryGameObj.h"
#include "MPowerPlantGameObj.h"
#include "MRefineryGameObj.h"
#include "MComCenterGameObj.h"
#include "MRepairBayGameObj.h"
#include "MAirFactoryGameObj.h"
#include "MNavalFactoryGameObj.h"
#include "MSuperweaponGameObj.h"
#include "MConstructionYardGameObj.h"
#include "MDamageableGameObj.h"
#include "MTransitionGameObj.h"
#include "MTransitionGameObjDef.h"
#include "MDamageZoneGameObj.h"
#include "MDamageZoneGameObjDef.h"

namespace RenSharp
{
	BaseGameObj::BaseGameObj(IntPtr pointer)
		: NetworkObjectClass(pointer)
	{
		persistClass = gcnew PersistClass(IntPtr(InternalPersistClassPointer));
	}

	IBaseGameObj^ BaseGameObj::CreateBaseGameObjWrapper(IntPtr baseGameObjPtr)
	{
		return CreateBaseGameObjWrapper(reinterpret_cast<::BaseGameObj*>(baseGameObjPtr.ToPointer()));
	}

	bool BaseGameObj::Equals(Object ^other)
	{
		if (NetworkObjectClass::Equals(other))
		{
			return true;
		}

		if (ReferenceEquals(other, nullptr))
		{
			return false;
		}

		auto otherUnmanagedObj = dynamic_cast<IUnmanagedObject ^>(other);
		if (otherUnmanagedObj == nullptr || otherUnmanagedObj->Pointer.Equals(IntPtr::Zero))
		{
			return false;
		}

		auto otherPostLoadableClass = dynamic_cast<IPostLoadableClass^>(other);
		if (otherPostLoadableClass != nullptr)
		{
			if (persistClass->Equals(otherPostLoadableClass))
			{
				return true;
			}
		}

		auto otherBaseGameObj = dynamic_cast<IBaseGameObj ^>(other);
		if (otherBaseGameObj != nullptr)
		{
			if (BaseGameObjPointer.Equals(otherBaseGameObj->BaseGameObjPointer))
			{
				return true;
			}
		}

		return false;
	}

	void BaseGameObj::OnPostLoad()
	{
		persistClass->OnPostLoad();
	}

	bool BaseGameObj::Save(IChunkSaveClass ^csave)
	{
		return persistClass->Save(csave);
	}

	bool BaseGameObj::Load(IChunkLoadClass ^cload)
	{
		return persistClass->Load(cload);
	}

	void BaseGameObj::Think()
	{
		InternalBaseGameObjPointer->Think();
	}

	void BaseGameObj::PostThink()
	{
		InternalBaseGameObjPointer->Post_Think();
	}

	IntPtr BaseGameObj::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void BaseGameObj::Pointer::set(IntPtr value)
	{
		AbstractUnmanagedObject::Pointer::set(value);

		if (Pointer == IntPtr::Zero)
		{
			persistClass = nullptr;
		}
		else
		{
			persistClass = gcnew PersistClass(IntPtr(InternalPersistClassPointer));
		}
	}

	IntPtr BaseGameObj::PostLoadableClassPointer::get()
	{
		return IntPtr(InternalPostLoadableClassPointer);
	}

	IntPtr BaseGameObj::PersistClassPointer::get()
	{
		return IntPtr(InternalPersistClassPointer);
	}

	IntPtr BaseGameObj::BaseGameObjPointer::get()
	{
		return IntPtr(InternalBaseGameObjPointer);
	}

	bool BaseGameObj::IsPostLoadRegistered::get()
	{
		return persistClass->IsPostLoadRegistered;
	}

	void BaseGameObj::IsPostLoadRegistered::set(bool value)
	{
		persistClass->IsPostLoadRegistered = value;
	}

	IPersistFactoryClass ^BaseGameObj::Factory::get()
	{
		return persistClass->Factory;
	}

	IBaseGameObjDef ^BaseGameObj::Definition::get()
	{
		return safe_cast<IBaseGameObjDef^>(DefinitionClass::CreateDefinitionClassWrapper(&InternalBaseGameObjPointer->Get_Definition()));
	}

	bool BaseGameObj::IsHibernating::get()
	{
		return InternalBaseGameObjPointer->Is_Hibernating();
	}

	int BaseGameObj::ID::get()
	{
		return InternalBaseGameObjPointer->Get_ID();
	}

	bool BaseGameObj::IsPostThinkAllowed::get()
	{
		return InternalBaseGameObjPointer->Is_Post_Think_Allowed();
	}

	void BaseGameObj::IsPostThinkAllowed::set(bool value)
	{
		InternalBaseGameObjPointer->IsPostThinkAllowed = value;
	}

	bool BaseGameObj::EnableCinematicFreeze::get()
	{
		return InternalBaseGameObjPointer->Is_Cinematic_Freeze_Enabled();
	}

	void BaseGameObj::EnableCinematicFreeze::set(bool value)
	{
		InternalBaseGameObjPointer->Enable_Cinematic_Freeze(value);
	}

	IBaseGameObj^ BaseGameObj::CreateBaseGameObjWrapper(::BaseGameObj* baseGameObjPtr)
	{
		if (baseGameObjPtr == nullptr)
		{
			throw gcnew ArgumentNullException("baseGameObjPtr");
		}

		auto vehicleGameObjPtr = baseGameObjPtr->As_VehicleGameObj();
		if (vehicleGameObjPtr != nullptr)
		{
			return gcnew VehicleGameObj(IntPtr(vehicleGameObjPtr));
		}
		else
		{
			auto smartGameObjPtr = baseGameObjPtr->As_SmartGameObj();
			if (smartGameObjPtr != nullptr)
			{
				auto soldierGameObjPtr = smartGameObjPtr->As_SoldierGameObj();
				if (soldierGameObjPtr != nullptr)
				{
					return gcnew SoldierGameObj(IntPtr(soldierGameObjPtr));
				}
				else if (smartGameObjPtr->Get_Definition().Get_Class_ID() == ISAMSiteGameObjDef::SAMSiteGameObjDefClassID)
				{
					return gcnew SAMSiteGameObj(IntPtr(smartGameObjPtr));
				}

				return gcnew SmartGameObj(IntPtr(smartGameObjPtr));
			}
			else
			{
				auto physicalGameObjPtr = baseGameObjPtr->As_PhysicalGameObj();
				if (physicalGameObjPtr != nullptr)
				{
					auto powerUpGameObjPtr = physicalGameObjPtr->As_PowerUpGameObj();
					if (powerUpGameObjPtr != nullptr)
					{
						return gcnew PowerUpGameObj(IntPtr(powerUpGameObjPtr));
					}

					auto c4GameObjPtr = physicalGameObjPtr->As_C4GameObj();
					if (c4GameObjPtr != nullptr)
					{
						return gcnew C4GameObj(IntPtr(c4GameObjPtr));
					}

					auto beaconGameObjPtr = physicalGameObjPtr->As_BeaconGameObj();
					if (beaconGameObjPtr != nullptr)
					{
						return gcnew BeaconGameObj(IntPtr(beaconGameObjPtr));
					}

					auto cinematicGameObjPtr = physicalGameObjPtr->As_CinematicGameObj();
					if (cinematicGameObjPtr != nullptr)
					{
						return gcnew CinematicGameObj(IntPtr(cinematicGameObjPtr));
					}
					else if (physicalGameObjPtr->Get_Definition().Get_Class_ID() == ISpecialEffectsGameObjDef::SpecialEffectsGameObjDefClassID)
					{
						return gcnew SpecialEffectsGameObj(IntPtr(physicalGameObjPtr));
					}
					else
					{
						auto simpleGameObjPtr = physicalGameObjPtr->As_SimpleGameObj();
						if (simpleGameObjPtr != nullptr)
						{
							return gcnew SimpleGameObj(IntPtr(simpleGameObjPtr));
						}

						auto armedGameObjPtr = physicalGameObjPtr->As_ArmedGameObj();
						if (armedGameObjPtr != nullptr)
						{
							return gcnew ArmedGameObj(IntPtr(armedGameObjPtr));
						}

						return gcnew PhysicalGameObj(IntPtr(physicalGameObjPtr));
					}
				}
				else
				{
					auto scriptableGameObjPtr = baseGameObjPtr->As_ScriptableGameObj();
					if (scriptableGameObjPtr != nullptr)
					{
						auto scriptZoneGameObjPtr = scriptableGameObjPtr->As_ScriptZoneGameObj();
						if (scriptZoneGameObjPtr != nullptr)
						{
							return gcnew ScriptZoneGameObj(IntPtr(scriptZoneGameObjPtr));
						}

						auto buildingGameObjPtr = scriptableGameObjPtr->As_BuildingGameObj();
						if (buildingGameObjPtr != nullptr)
						{
							auto soldierFactoryGameObjPtr = buildingGameObjPtr->As_SoldierFactoryGameObj();
							if (soldierFactoryGameObjPtr != nullptr)
							{
								return gcnew SoldierFactoryGameObj(IntPtr(soldierFactoryGameObjPtr));
							}

							auto vehicleFactoryGameObjPtr = buildingGameObjPtr->As_VehicleFactoryGameObj();
							if (vehicleFactoryGameObjPtr != nullptr)
							{
								auto airStripGameObjPtr = vehicleFactoryGameObjPtr->As_AirStripGameObj();
								if (airStripGameObjPtr != nullptr)
								{
									return gcnew AirStripGameObj(IntPtr(airStripGameObjPtr));
								}

								auto warFactoryGameObjPtr = vehicleFactoryGameObjPtr->As_WarFactoryGameObj();
								if (warFactoryGameObjPtr != nullptr)
								{
									return gcnew WarFactoryGameObj(IntPtr(warFactoryGameObjPtr));
								}

								return gcnew VehicleFactoryGameObj(IntPtr(vehicleFactoryGameObjPtr));
							}

							auto powerPlantGameObjPtr = buildingGameObjPtr->As_PowerPlantGameObj();
							if (powerPlantGameObjPtr != nullptr)
							{
								return gcnew PowerPlantGameObj(IntPtr(powerPlantGameObjPtr));
							}

							auto refineryGameObjPtr = buildingGameObjPtr->As_RefineryGameObj();
							if (refineryGameObjPtr != nullptr)
							{
								return gcnew RefineryGameObj(IntPtr(refineryGameObjPtr));
							}

							auto comCenterGameObjPtr = buildingGameObjPtr->As_ComCenterGameObj();
							if (comCenterGameObjPtr != nullptr)
							{
								return gcnew ComCenterGameObj(IntPtr(comCenterGameObjPtr));
							}

							auto repairBayGameObjPtr = buildingGameObjPtr->As_RepairBayGameObj();
							if (repairBayGameObjPtr != nullptr)
							{
								return gcnew RepairBayGameObj(IntPtr(repairBayGameObjPtr));
							}

							auto airFactoryGameObjPtr = buildingGameObjPtr->As_AirFactoryGameObj();
							if (airFactoryGameObjPtr != nullptr)
							{
								return gcnew AirFactoryGameObj(IntPtr(airFactoryGameObjPtr));
							}

							auto constructionYardGameObjPtr = buildingGameObjPtr->As_ConstructionYardGameObj();
							if (constructionYardGameObjPtr != nullptr)
							{
								return gcnew ConstructionYardGameObj(IntPtr(constructionYardGameObjPtr));
							}

							auto navalFactoryGameObjPtr = buildingGameObjPtr->As_NavalFactoryGameObj();
							if (navalFactoryGameObjPtr != nullptr)
							{
								return gcnew NavalFactoryGameObj(IntPtr(navalFactoryGameObjPtr));
							}

							auto superweaponGameObjPtr = buildingGameObjPtr->As_SuperweaponGameObj();
							if (superweaponGameObjPtr != nullptr)
							{
								return gcnew SuperweaponGameObj(IntPtr(superweaponGameObjPtr));
							}

							return gcnew BuildingGameObj(IntPtr(buildingGameObjPtr));
						}

						auto damageableGameObjPtr = scriptableGameObjPtr->As_DamageableGameObj();
						if (damageableGameObjPtr != nullptr)
						{
							return gcnew DamageableGameObj(IntPtr(damageableGameObjPtr));
						}

						return gcnew ScriptableGameObj(IntPtr(scriptableGameObjPtr));
					}
					else if (baseGameObjPtr->Get_Definition().Get_Class_ID() == ITransitionGameObjDef::TransitionGameObjDefClassID)
					{
						return gcnew TransitionGameObj(IntPtr(baseGameObjPtr));
					}
					else if (baseGameObjPtr->Get_Definition().Get_Class_ID() == IDamageZoneGameObjDef::DamageZoneGameObjDefClassID)
					{
						return gcnew DamageZoneGameObj(IntPtr(baseGameObjPtr));
					}

					return gcnew BaseGameObj(IntPtr(baseGameObjPtr));
				}
			}
		}
	}

	::NetworkObjectClass *BaseGameObj::InternalNetworkObjectClassPointer::get()
	{
		return InternalBaseGameObjPointer;
	}

	::PostLoadableClass *BaseGameObj::InternalPostLoadableClassPointer::get()
	{
		return InternalBaseGameObjPointer;
	}

	::PersistClass *BaseGameObj::InternalPersistClassPointer::get()
	{
		return InternalBaseGameObjPointer;
	}

	::BaseGameObj *BaseGameObj::InternalBaseGameObjPointer::get()
	{
		return reinterpret_cast<::BaseGameObj *>(Pointer.ToPointer());
	}
}