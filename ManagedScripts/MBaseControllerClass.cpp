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
#include "MBaseControllerClass.h"

#include "MBuildingGameObj.h"
#include "MVehicleGameObj.h"
#include "Mobboxclass.h"
#include "MBuildingGameObjPtrDynamicVectorClass.h"

namespace RenSharp
{
	BaseControllerClass::BaseControllerClass(IntPtr pointer)
		: NetworkObjectClass(pointer)
	{

	}

	IBuildingGameObj ^BaseControllerClass::FindBuilding(unsigned int type)
	{
		auto result = InternalBaseControllerClassPointer->Find_Building(type);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BuildingGameObj(IntPtr(result));
		}
	}

	void BaseControllerClass::DestroyBase()
	{
		InternalBaseControllerClassPointer->Destroy_Base();
	}

	IntPtr BaseControllerClass::BaseControllerClassPointer::get()
	{
		return IntPtr(InternalBaseControllerClassPointer);
	}

	IVehicleGameObj ^BaseControllerClass::HarvesterVehicle::get()
	{
		auto result = InternalBaseControllerClassPointer->Get_Harvester_Vehicle();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew VehicleGameObj(IntPtr(result));
		}
	}

	bool BaseControllerClass::IsBasePowered::get()
	{
		return InternalBaseControllerClassPointer->Is_Base_Powered();
	}

	bool BaseControllerClass::CanGenerateSoldiers::get()
	{
		return InternalBaseControllerClassPointer->Can_Generate_Soldiers();
	}

	void BaseControllerClass::CanGenerateSoldiers::set(bool value)
	{
		InternalBaseControllerClassPointer->Set_Can_Generate_Soldiers(value);
	}

	bool BaseControllerClass::CanGenerateVehicles::get()
	{
		return InternalBaseControllerClassPointer->Can_Generate_Vehicles();
	}

	void BaseControllerClass::CanGenerateVehicles::set(bool value)
	{
		InternalBaseControllerClassPointer->Set_Can_Generate_Vehicles(value);
	}

	bool BaseControllerClass::BaseDestroyed::get()
	{
		return InternalBaseControllerClassPointer->Is_Base_Destroyed();
	}

	void BaseControllerClass::BaseDestroyed::set(bool value)
	{
		InternalBaseControllerClassPointer->Set_Base_Destroyed(value);
	}

	bool BaseControllerClass::BeaconDestroyedBase::get()
	{
		return InternalBaseControllerClassPointer->Did_Beacon_Destroy_Base();
	}

	void BaseControllerClass::BeaconDestroyedBase::set(bool value)
	{
		InternalBaseControllerClassPointer->Set_Beacon_Destroyed_Base(value);
	}

	bool BaseControllerClass::IsRadarEnabled::get()
	{
		return InternalBaseControllerClassPointer->Is_Radar_Enabled();
	}

	void BaseControllerClass::IsRadarEnabled::set(bool value)
	{
		InternalBaseControllerClassPointer->Enable_Radar(value);
	}

	float BaseControllerClass::OperationTimeFactor::get()
	{
		return InternalBaseControllerClassPointer->Get_Operation_Time_Factor();
	}

	int BaseControllerClass::PlayerType::get()
	{
		return InternalBaseControllerClassPointer->Get_Player_Type();
	}

	OBBoxClass BaseControllerClass::BeaconZone::get()
	{
		return OBBoxClass(IntPtr(const_cast<::OBBoxClass *>(&InternalBaseControllerClassPointer->Get_Beacon_Zone())));
	}

	IDynamicVectorClass<IBuildingGameObj ^> ^BaseControllerClass::BuildingList::get()
	{
		auto &result = InternalBaseControllerClassPointer->Get_Building_List();
		return gcnew BuildingGameObjPtrDynamicVectorClass(IntPtr(const_cast<::DynamicVectorClass<::BuildingGameObj *> *>(&result)));
	}

	::NetworkObjectClass *BaseControllerClass::InternalNetworkObjectClassPointer::get()
	{
		return InternalBaseControllerClassPointer;
	}

	::BaseControllerClass *BaseControllerClass::InternalBaseControllerClassPointer::get()
	{
		return reinterpret_cast<::BaseControllerClass *>(Pointer.ToPointer());
	}
}