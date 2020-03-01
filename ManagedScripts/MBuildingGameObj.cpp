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
#include "MBuildingGameObj.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4091 4251 4244 26495 26454)
#include <BuildingGameObj.h>
#include <BuildingGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MVehicleFactoryGameObj.h"
#include "MBuildingGameObjDef.h"
#include "MPowerPlantGameObj.h"
#include "MSoldierFactoryGameObj.h"
#include "MAirFactoryGameObj.h"
#include "MWarFactoryGameObj.h"
#include "MRefineryGameObj.h"
#include "MComCenterGameObj.h"
#include "MRepairBayGameObj.h"
#include "MSphereClass.h"
#include "MBaseControllerClass.h"
#include "MBuildingAggregateClass.h"
#include "MAABoxClass.h"
#include "MConstructionYardGameObj.h"
#include "MAirFactoryGameObj.h"
#include "MNavalFactoryGameObj.h"
#include "MSuperweaponGameObj.h"
#include "MAudibleSoundClass.h"
#include "MAirStripGameObj.h"

namespace RenSharp
{

#pragma managed(push, off)

	class BuildingGameObjHelper : public ::BuildingGameObj
	{
		private:
			BuildingGameObjHelper() = default;

		public:
			::RefMultiListClass<::StaticPhysClass> &GetInteriorMeshes()
			{
				return InteriorMeshes;
			}

			::BuildingMonitorClass *&GetBuildingMonitor()
			{
				return BuildingMonitor;
			}

			::BaseControllerClass *&GetBaseController()
			{
				return BaseController;
			}

			bool &GetIsPowerOn()
			{
				return IsPowerOn;
			}

			int &GetCurrentState()
			{
				return CurrentState;
			}

			::AudibleSoundClass *&GetCurrentAnnouncement()
			{
				return CurrentAnnouncement;
			}

			::SphereClass &GetAnnouncementSphere()
			{
				return AnnouncementSphere;
			}

			::SphereClass &GetCollectionSphere()
			{
				return CollectionSphere;
			}

			::RefMultiListClass<::StaticPhysClass> &GetExteriorMeshes()
			{
				return ExteriorMeshes;
			}

			::RefMultiListClass<::BuildingAggregateClass> &GetAggregates()
			{
				return Aggregates;
			}

			::RefMultiListClass<::LightPhysClass> &GetPowerOnLights()
			{
				return PowerOnLights;
			}

			::RefMultiListClass<::LightPhysClass> &GetPowerOffLights()
			{
				return PowerOffLights;
			}

			::AABoxClass &GetBoundingBox()
			{
				return BoundingBox;
			}
	};

#pragma managed(pop)

	BuildingGameObj::BuildingGameObj(IntPtr pointer)
		: DamageableGameObj(pointer)
	{
		combatPhysObserverClass = gcnew CombatPhysObserverClass(IntPtr(InternalCombatPhysObserverClassPointer));
	}

	bool BuildingGameObj::Equals(Object ^other)
	{
		if (ScriptableGameObj::Equals(other))
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

		auto otherPhysObserverClass = dynamic_cast<IPhysObserverClass^>(other);
		if (otherPhysObserverClass != nullptr)
		{
			if (combatPhysObserverClass->Equals(otherPhysObserverClass))
			{
				return true;
			}
		}

		auto otherBuildingGameObj = dynamic_cast<IBuildingGameObj ^>(other);
		if (otherBuildingGameObj != nullptr)
		{
			if (BuildingGameObjPointer.Equals(otherBuildingGameObj->BuildingGameObjPointer))
			{
				return true;
			}
		}

		return false;
	}

	int BuildingGameObj::CollisionOccurred(IntPtr event)
	{
		return combatPhysObserverClass->CollisionOccurred(event);
	}

	int BuildingGameObj::ObjectExpired(IPhysClass ^observedObj)
	{
		return combatPhysObserverClass->ObjectExpired(observedObj);
	}

	void BuildingGameObj::ObjectRemovedFromScene(IPhysClass ^observedObj)
	{
		combatPhysObserverClass->ObjectRemovedFromScene(observedObj);
	}

	void BuildingGameObj::ObjectShatteredSomething(IPhysClass ^observedObj, IPhysClass ^shatteredObj, int surfaceType)
	{
		combatPhysObserverClass->ObjectShatteredSomething(observedObj, shatteredObj, surfaceType);
	}

	IBuildingGameObj ^BuildingGameObj::AsBuildingGameObj()
	{
		return this;
	}

	IPowerPlantGameObj ^BuildingGameObj::AsPowerPlantGameObj()
	{
		auto result = InternalBuildingGameObjPointer->As_PowerPlantGameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PowerPlantGameObj(IntPtr(result));
		}
	}

	ISoldierFactoryGameObj ^BuildingGameObj::AsSoldierFactoryGameObj()
	{
		auto result = InternalBuildingGameObjPointer->As_SoldierFactoryGameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SoldierFactoryGameObj(IntPtr(result));
		}
	}

	IVehicleFactoryGameObj ^BuildingGameObj::AsVehicleFactoryGameObj()
	{
		auto result = InternalBuildingGameObjPointer->As_VehicleFactoryGameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew VehicleFactoryGameObj(IntPtr(result));
		}
	}

	IAirStripGameObj ^BuildingGameObj::AsAirStripGameObj()
	{
		auto result = InternalBuildingGameObjPointer->As_AirStripGameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew AirStripGameObj(IntPtr(result));
		}
	}

	IWarFactoryGameObj ^BuildingGameObj::AsWarFactoryGameObj()
	{
		auto result = InternalBuildingGameObjPointer->As_WarFactoryGameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew WarFactoryGameObj(IntPtr(result));
		}
	}

	IRefineryGameObj ^BuildingGameObj::AsRefineryGameObj()
	{
		auto result = InternalBuildingGameObjPointer->As_RefineryGameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RefineryGameObj(IntPtr(result));
		}
	}

	IComCenterGameObj ^BuildingGameObj::AsComCenterGameObj()
	{
		auto result = InternalBuildingGameObjPointer->As_ComCenterGameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ComCenterGameObj(IntPtr(result));
		}
	}

	IRepairBayGameObj ^BuildingGameObj::AsRepairBayGameObj()
	{
		auto result = InternalBuildingGameObjPointer->As_RepairBayGameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RepairBayGameObj(IntPtr(result));
		}
	}

	void BuildingGameObj::CnCInitialize(IBaseControllerClass ^base)
	{
		if (base == nullptr || base->BaseControllerClassPointer.ToPointer() == nullptr)
		{
			InternalBuildingGameObjPointer->CnC_Initialize(nullptr);
		}
		else
		{
			InternalBuildingGameObjPointer->CnC_Initialize(
				reinterpret_cast<::BaseControllerClass *>(base->BaseControllerClassPointer.ToPointer()));
		}
	}

	void BuildingGameObj::OnDestroyed()
	{
		InternalBuildingGameObjPointer->On_Destroyed();
	}

	void BuildingGameObj::OnDamaged()
	{
		InternalBuildingGameObjPointer->On_Damaged();
	}

	void BuildingGameObj::OnRevived()
	{
		InternalBuildingGameObjPointer->On_Revived();
	}

	IBuildingAggregateClass ^BuildingGameObj::FindMCT()
	{
		auto result = InternalBuildingGameObjPointer->Find_MCT();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BuildingAggregateClass(IntPtr(result));
		}
	}

	float BuildingGameObj::FindClosestPoly(Vector3 pos)
	{
		::Vector3 posVec;

		Vector3::ManagedToUnmanagedVector3(pos, posVec);

		return InternalBuildingGameObjPointer->Find_Closest_Poly(posVec);
	}

	IConstructionYardGameObj ^BuildingGameObj::AsConstructionYardGameObj()
	{
		auto result = InternalBuildingGameObjPointer->As_ConstructionYardGameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ConstructionYardGameObj(IntPtr(result));
		}
	}

	IAirFactoryGameObj ^BuildingGameObj::AsAirFactoryGameObj()
	{
		auto result = InternalBuildingGameObjPointer->As_AirFactoryGameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew AirFactoryGameObj(IntPtr(result));
		}
	}

	INavalFactoryGameObj ^BuildingGameObj::AsNavalFactoryGameObj()
	{
		auto result = InternalBuildingGameObjPointer->As_NavalFactoryGameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew NavalFactoryGameObj(IntPtr(result));
		}
	}

	ISuperweaponGameObj ^BuildingGameObj::AsSuperweaponGameObj()
	{
		auto result = InternalBuildingGameObjPointer->As_SuperweaponGameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SuperweaponGameObj(IntPtr(result));
		}
	}

	IntPtr BuildingGameObj::Pointer::get()
	{
		return ScriptableGameObj::Pointer::get();
	}

	void BuildingGameObj::Pointer::set(IntPtr value)
	{
		ScriptableGameObj::Pointer::set(value);

		if (Pointer == IntPtr::Zero)
		{
			combatPhysObserverClass = nullptr;
		}
		else
		{
			combatPhysObserverClass = gcnew CombatPhysObserverClass(IntPtr(InternalCombatPhysObserverClassPointer));
		}
	}

	IntPtr BuildingGameObj::CombatPhysObserverClassPointer::get()
	{
		return IntPtr(InternalCombatPhysObserverClassPointer);
	}

	IntPtr BuildingGameObj::PhysObserverClassPointer::get()
	{
		return IntPtr(InternalPhysObserverClassPointer);
	}

	IntPtr BuildingGameObj::BuildingGameObjPointer::get()
	{
		return IntPtr(InternalBuildingGameObjPointer);
	}

	IBuildingGameObjDef ^BuildingGameObj::Definition::get()
	{
		return safe_cast<IBuildingGameObjDef^>(DefinitionClass::CreateDefinitionClassWrapper(&InternalBuildingGameObjPointer->Get_Definition()));
	}

	Vector3 BuildingGameObj::Position::get()
	{
		return ScriptableGameObj::Position::get();
	}

	void BuildingGameObj::Position::set(Vector3 value)
	{
		::Vector3 valueVec;

		Vector3::ManagedToUnmanagedVector3(value, valueVec);

		InternalBuildingGameObjPointer->Set_Position(valueVec);
	}

	bool BuildingGameObj::IsPowerOn::get()
	{
		return InternalBuildingGameObjPointer->Is_Power_Enabled();
	}

	void BuildingGameObj::IsPowerOn::set(bool value)
	{
		auto helper = reinterpret_cast<BuildingGameObjHelper *>(InternalBuildingGameObjPointer);

		auto &isPowerOn = helper->GetIsPowerOn();

		isPowerOn = value;
	}

	String ^BuildingGameObj::NamePrefix::get()
	{
		auto result = InternalBuildingGameObjPointer->Get_Name_Prefix();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	SphereClass BuildingGameObj::CollectionSphere::get()
	{
		::SphereClass tmp;

		InternalBuildingGameObjPointer->Get_Collection_Sphere(&tmp);

		SphereClass result;

		SphereClass::UnmanagedToManagedSphereClass(tmp, result);

		return result;
	}

	void BuildingGameObj::CollectionSphere::set(SphereClass value)
	{
		::SphereClass tmp;

		SphereClass::ManagedToUnmanagedSphereClass(value, tmp);

		InternalBuildingGameObjPointer->Set_Collection_Sphere(tmp);
	}

	bool BuildingGameObj::IsDestroyed::get()
	{
		return InternalBuildingGameObjPointer->Is_Destroyed();
	}

	void BuildingGameObj::IsDestroyed::set(bool value)
	{
		InternalBuildingGameObjPointer->Set_Is_Destroyed(value);
	}

	bool BuildingGameObj::IsSpyDisabled::get()
	{
		return InternalBuildingGameObjPointer->Is_Spy_Disabled();
	}

	void BuildingGameObj::IsSpyDisabled::set(bool value)
	{
		InternalBuildingGameObjPointer->Set_Is_Spy_Disabled(value);
	}

	bool BuildingGameObj::IsGDI::get()
	{
		return InternalBuildingGameObjPointer->Is_GDI();
	}

	bool BuildingGameObj::IsNod::get()
	{
		return InternalBuildingGameObjPointer->Is_Nod();
	}

	AABoxClass BuildingGameObj::BoundingBox::get()
	{
		AABoxClass result;

		AABoxClass::UnmanagedToManagedAABoxClass(InternalBuildingGameObjPointer->Get_Bounds(), result);

		return result;
	}

	void BuildingGameObj::BoundingBox::set(AABoxClass value)
	{
		auto helper = reinterpret_cast<BuildingGameObjHelper *>(InternalBuildingGameObjPointer);

		auto &boundingBox = helper->GetBoundingBox();

		AABoxClass::ManagedToUnmanagedAABoxClass(value, boundingBox);
	}

	int BuildingGameObj::CurrentState::get()
	{
		return InternalBuildingGameObjPointer->Get_State();
	}

	void BuildingGameObj::CurrentState::set(int value)
	{
		auto helper = reinterpret_cast<BuildingGameObjHelper *>(InternalBuildingGameObjPointer);

		auto &currentState = helper->GetCurrentState();

		currentState = value;
	}

	IBaseControllerClass ^BuildingGameObj::BaseController::get()
	{
		auto result = InternalBuildingGameObjPointer->Get_Base();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BaseControllerClass(IntPtr(result));
		}
	}

	void BuildingGameObj::BaseController::set(IBaseControllerClass ^value)
	{
		auto helper = reinterpret_cast<BuildingGameObjHelper *>(InternalBuildingGameObjPointer);

		auto &baseController = helper->GetBaseController();

		if (value == nullptr || value->BaseControllerClassPointer.ToPointer() == nullptr)
		{
			baseController = nullptr;
		}
		else
		{
			baseController = reinterpret_cast<::BaseControllerClass *>(value->BaseControllerClassPointer.ToPointer());
		}
	}

	::PhysObserverClass *BuildingGameObj::InternalPhysObserverClassPointer::get()
	{
		return InternalBuildingGameObjPointer;
	}

	::CombatPhysObserverClass *BuildingGameObj::InternalCombatPhysObserverClassPointer::get()
	{
		return InternalBuildingGameObjPointer;
	}

	::DamageableGameObj *BuildingGameObj::InternalDamageableGameObjPointer::get()
	{
		return InternalBuildingGameObjPointer;
	}

	::BuildingGameObj *BuildingGameObj::InternalBuildingGameObjPointer::get()
	{
		return reinterpret_cast<::BuildingGameObj *>(Pointer.ToPointer());
	}

	IntPtr BuildingGameObj::BuildingMonitor::get()
	{
		auto helper = reinterpret_cast<BuildingGameObjHelper *>(InternalBuildingGameObjPointer);

		auto &buildingMonitor = helper->GetBuildingMonitor();

		return IntPtr(buildingMonitor);
	}

	void BuildingGameObj::BuildingMonitor::set(IntPtr value)
	{
		auto helper = reinterpret_cast<BuildingGameObjHelper *>(InternalBuildingGameObjPointer);

		auto &buildingMonitor = helper->GetBuildingMonitor();

		if (value.ToPointer() == nullptr)
		{
			buildingMonitor = nullptr;
		}
		else
		{
			buildingMonitor = reinterpret_cast<::BuildingMonitorClass *>(value.ToPointer());
		}
	}

	IAudibleSoundClass ^BuildingGameObj::CurrentAnnouncement::get()
	{
		auto helper = reinterpret_cast<BuildingGameObjHelper *>(InternalBuildingGameObjPointer);

		auto &currentAnnouncement = helper->GetCurrentAnnouncement();

		if (currentAnnouncement == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew AudibleSoundClass(IntPtr(currentAnnouncement));
		}
	}

	void BuildingGameObj::CurrentAnnouncement::set(IAudibleSoundClass ^value)
	{
		auto helper = reinterpret_cast<BuildingGameObjHelper *>(InternalBuildingGameObjPointer);

		auto &currentAnnouncement = helper->GetCurrentAnnouncement();

		if (value == nullptr || value->AudibleSoundClassPointer.ToPointer() == nullptr)
		{
			currentAnnouncement = nullptr;
		}
		else
		{
			currentAnnouncement = reinterpret_cast<::AudibleSoundClass *>(value->AudibleSoundClassPointer.ToPointer());
		}
	}

	SphereClass BuildingGameObj::AnnouncementSphere::get()
	{
		auto helper = reinterpret_cast<BuildingGameObjHelper *>(InternalBuildingGameObjPointer);

		auto &announcementSphere = helper->GetAnnouncementSphere();

		SphereClass result;

		SphereClass::UnmanagedToManagedSphereClass(announcementSphere, result);

		return result;
	}

	void BuildingGameObj::AnnouncementSphere::set(SphereClass value)
	{
		auto helper = reinterpret_cast<BuildingGameObjHelper *>(InternalBuildingGameObjPointer);

		auto &announcementSphere = helper->GetAnnouncementSphere();

		SphereClass::ManagedToUnmanagedSphereClass(value, announcementSphere);
	}

	IRefMultiListClass<IStaticPhysClass ^> ^BuildingGameObj::InteriorMeshes::get()
	{
		auto helper = reinterpret_cast<BuildingGameObjHelper *>(InternalBuildingGameObjPointer);

		return gcnew StaticPhysClassRefMultiListClass(IntPtr(&helper->GetInteriorMeshes()));
	}

	IRefMultiListClass<IStaticPhysClass ^> ^BuildingGameObj::ExteriorMeshes::get()
	{
		auto helper = reinterpret_cast<BuildingGameObjHelper *>(InternalBuildingGameObjPointer);

		auto &exteriorMeshes = helper->GetExteriorMeshes();

		return gcnew StaticPhysClassRefMultiListClass(IntPtr(&exteriorMeshes));
	}

	IRefMultiListClass<IBuildingAggregateClass ^> ^BuildingGameObj::Aggregates::get()
	{
		auto helper = reinterpret_cast<BuildingGameObjHelper *>(InternalBuildingGameObjPointer);

		auto &aggregates = helper->GetAggregates();

		return gcnew BuildingAggregateClassRefMultiListClass(IntPtr(&aggregates));
	}

	IRefMultiListClass<ILightPhysClass ^> ^BuildingGameObj::PowerOnLights::get()
	{
		auto helper = reinterpret_cast<BuildingGameObjHelper *>(InternalBuildingGameObjPointer);

		auto &powerOnLights = helper->GetPowerOnLights();

		return gcnew LightPhysClassRefMultiListClass(IntPtr(&powerOnLights));
	}

	IRefMultiListClass<ILightPhysClass ^> ^BuildingGameObj::PowerOffLights::get()
	{
		auto helper = reinterpret_cast<BuildingGameObjHelper *>(InternalBuildingGameObjPointer);

		auto &powerOffLights = helper->GetPowerOffLights();

		return gcnew LightPhysClassRefMultiListClass(IntPtr(&powerOffLights));
	}
}