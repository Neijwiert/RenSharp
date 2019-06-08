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
#include "MVehicleFactoryGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <VehicleFactoryGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	VehicleFactoryGameObjDef::VehicleFactoryGameObjDef(IntPtr pointer)
		: BuildingGameObjDef(pointer)
	{

	}

	IntPtr VehicleFactoryGameObjDef::VehicleFactoryGameObjDefPointer::get()
	{
		return IntPtr(InternalVehicleFactoryGameObjDefPointer);
	}

	int VehicleFactoryGameObjDef::PadClearingWarhead::get()
	{
		return InternalVehicleFactoryGameObjDefPointer->Get_Pad_Clearing_Warhead();
	}

	void VehicleFactoryGameObjDef::PadClearingWarhead::set(int value)
	{
		InternalVehicleFactoryGameObjDefPointer->PadClearingWarhead = value;
	}

	float VehicleFactoryGameObjDef::TotalBuildingTime::get()
	{
		return InternalVehicleFactoryGameObjDefPointer->Get_Total_Building_Time();
	}

	void VehicleFactoryGameObjDef::TotalBuildingTime::set(float value)
	{
		InternalVehicleFactoryGameObjDefPointer->TotalBuildingTime = value;
	}

	bool VehicleFactoryGameObjDef::EnableFlyingWaypaths::get()
	{
		return InternalVehicleFactoryGameObjDefPointer->Get_Flying_Waypaths_Enabled();
	}

	void VehicleFactoryGameObjDef::EnableFlyingWaypaths::set(bool value)
	{
		InternalVehicleFactoryGameObjDefPointer->EnableFlyingWaypaths = value;
	}

	bool VehicleFactoryGameObjDef::BuildGroundOnly::get()
	{
		return InternalVehicleFactoryGameObjDefPointer->Get_Build_Ground_Only();
	}

	void VehicleFactoryGameObjDef::BuildGroundOnly::set(bool value)
	{
		InternalVehicleFactoryGameObjDefPointer->BuildGroundOnly = value;
	}

	::BuildingGameObjDef *VehicleFactoryGameObjDef::InternalBuildingGameObjDefPointer::get()
	{
		return InternalVehicleFactoryGameObjDefPointer;
	}

	::VehicleFactoryGameObjDef *VehicleFactoryGameObjDef::InternalVehicleFactoryGameObjDefPointer::get()
	{
		return reinterpret_cast<::VehicleFactoryGameObjDef *>(Pointer.ToPointer());
	}
}