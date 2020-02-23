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
#include "MAirStripGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <AirStripGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	AirStripGameObjDef::AirStripGameObjDef(IntPtr pointer)
		: VehicleFactoryGameObjDef(pointer)
	{

	}

	IntPtr AirStripGameObjDef::AirStripGameObjDefPointer::get()
	{
		return IntPtr(InternalAirStripGameObjDefPointer);
	}

	int AirStripGameObjDef::DropCinematicDefId::get()
	{
		return InternalAirStripGameObjDefPointer->DropCinematicDefId;
	}

	void AirStripGameObjDef::DropCinematicDefId::set(int value)
	{
		InternalAirStripGameObjDefPointer->DropCinematicDefId = value;
	}

	int AirStripGameObjDef::CinematicSlotIndex::get()
	{
		return InternalAirStripGameObjDefPointer->CinematicSlotIndex;
	}

	void AirStripGameObjDef::CinematicSlotIndex::set(int value)
	{
		InternalAirStripGameObjDefPointer->CinematicSlotIndex = value;
	}

	float AirStripGameObjDef::CinematicLengthToDropOff::get()
	{
		return InternalAirStripGameObjDefPointer->CinematicLengthToDropOff;
	}

	void AirStripGameObjDef::CinematicLengthToDropOff::set(float value)
	{
		InternalAirStripGameObjDefPointer->CinematicLengthToDropOff = value;
	}

	float AirStripGameObjDef::CinematicLengthToVehicleDisplay::get()
	{
		return InternalAirStripGameObjDefPointer->CinematicLengthToVehicleDisplay;
	}

	void AirStripGameObjDef::CinematicLengthToVehicleDisplay::set(float value)
	{
		InternalAirStripGameObjDefPointer->CinematicLengthToVehicleDisplay = value;
	}

	bool AirStripGameObjDef::HideVehicles::get()
	{
		return InternalAirStripGameObjDefPointer->HideVehicles;
	}

	void AirStripGameObjDef::HideVehicles::set(bool value)
	{
		InternalAirStripGameObjDefPointer->HideVehicles = value;
	}

	::VehicleFactoryGameObjDef *AirStripGameObjDef::InternalVehicleFactoryGameObjDefPointer::get()
	{
		return InternalAirStripGameObjDefPointer;
	}

	::AirStripGameObjDef *AirStripGameObjDef::InternalAirStripGameObjDefPointer::get()
	{
		return reinterpret_cast<::AirStripGameObjDef *>(Pointer.ToPointer());
	}
}