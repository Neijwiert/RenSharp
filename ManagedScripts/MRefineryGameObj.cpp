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
#include "MRefineryGameObj.h"

#include "MRefineryGameObjDef.h"
#include "MVehicleGameObj.h"
#include "MHarvesterClass.h"
#include "MMatrix3D.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4091 4251 4244 26495 26454)
#include <RefineryGameObj.h>
#include <RefineryGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	RefineryGameObj::RefineryGameObj(IntPtr pointer)
		: BuildingGameObj(pointer)
	{

	}

	IRefineryGameObj ^RefineryGameObj::AsRefineryGameObj()
	{
		return this;
	}

	void RefineryGameObj::DestroyHarvester()
	{
		InternalRefineryGameObjPointer->Destroy_Harvester();
	}

	void RefineryGameObj::BlockHarvesterSpawn()
	{
		InternalRefineryGameObjPointer->Block_Harvester_Spawn();
	}

	void RefineryGameObj::SetAllowHarvesterSpawn()
	{
		InternalRefineryGameObjPointer->Allow_Harvester_Spawn();
	}

	IntPtr RefineryGameObj::RefineryGameObjPointer::get()
	{
		return IntPtr(InternalRefineryGameObjPointer);
	}

	IRefineryGameObjDef ^RefineryGameObj::Definition::get()
	{
		auto result = DefinitionClass::CreateDefinitionClassWrapper(&InternalRefineryGameObjPointer->Get_Definition());
		if (result != nullptr)
		{
			return safe_cast<IRefineryGameObjDef^>(result);
		}

		return gcnew RefineryGameObjDef(IntPtr(const_cast<::RefineryGameObjDef *>(&InternalRefineryGameObjPointer->Get_Definition())));
	}

	bool RefineryGameObj::NeedsHarvester::get()
	{
		return InternalRefineryGameObjPointer->Needs_Harvester();
	}

	int RefineryGameObj::HarvesterDefId::get()
	{
		return InternalRefineryGameObjPointer->Get_Harvester_Def_ID();
	}

	bool RefineryGameObj::IsHarvesterDocked::get()
	{
		return InternalRefineryGameObjPointer->Get_Is_Harvester_Docked();
	}

	IVehicleGameObj ^RefineryGameObj::HarvesterVehicle::get()
	{
		auto result = InternalRefineryGameObjPointer->Get_Harvester_Vehicle();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew VehicleGameObj(IntPtr(result));
		}
	}

	IHarvesterClass ^RefineryGameObj::Harvester::get()
	{
		auto result = InternalRefineryGameObjPointer->Get_Harvester();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew HarvesterClass(IntPtr(result));
		}
	}

	void RefineryGameObj::Harvester::set(IHarvesterClass ^value)
	{
		if (value == nullptr || value->HarvesterClassPointer.ToPointer() == nullptr)
		{
			InternalRefineryGameObjPointer->Set_Harvester(nullptr);
		}
		else
		{
			InternalRefineryGameObjPointer->Set_Harvester(
				reinterpret_cast<::HarvesterClass *>(value->HarvesterClassPointer.ToPointer()));
		}
	}

	Matrix3D RefineryGameObj::DockTM::get()
	{
		Matrix3D result;

		Matrix3D::UnmanagedToManagedMatrix3D(InternalRefineryGameObjPointer->Get_Dock_TM(), result);

		return result;
	}

	void RefineryGameObj::DockTM::set(Matrix3D value)
	{
		::Matrix3D tmp;

		Matrix3D::ManagedToUnmanagedMatrix3D(value, tmp);

		InternalRefineryGameObjPointer->Set_Dock_TM(tmp);
	}

	bool RefineryGameObj::AllowHarvesterSpawn::get()
	{
		return InternalRefineryGameObjPointer->Get_Allow_Harvester_Spawn();
	}

	::PhysObserverClass *RefineryGameObj::InternalPhysObserverClassPointer::get()
	{
		return InternalRefineryGameObjPointer;
	}

	::CombatPhysObserverClass *RefineryGameObj::InternalCombatPhysObserverClassPointer::get()
	{
		return InternalRefineryGameObjPointer;
	}

	::BuildingGameObj *RefineryGameObj::InternalBuildingGameObjPointer::get()
	{
		return InternalRefineryGameObjPointer;
	}

	::RefineryGameObj *RefineryGameObj::InternalRefineryGameObjPointer::get()
	{
		return reinterpret_cast<::RefineryGameObj *>(Pointer.ToPointer());
	}
}