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
#include "MAirFactoryGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <AirFactoryGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	AirFactoryGameObjDef::AirFactoryGameObjDef(IntPtr pointer)
		: BuildingGameObjDef(pointer)
	{

	}

	IntPtr AirFactoryGameObjDef::AirFactoryGameObjDefPointer::get()
	{
		return IntPtr(InternalAirFactoryGameObjDefPointer);
	}

	int AirFactoryGameObjDef::LandingPosDefId::get()
	{
		return InternalAirFactoryGameObjDefPointer->LandingPosDefId;
	}

	void AirFactoryGameObjDef::LandingPosDefId::set(int value)
	{
		InternalAirFactoryGameObjDefPointer->LandingPosDefId = value;
	}

	float AirFactoryGameObjDef::LandingPosDistance::get()
	{
		return InternalAirFactoryGameObjDefPointer->LandingPosDistance;
	}

	void AirFactoryGameObjDef::LandingPosDistance::set(float value)
	{
		InternalAirFactoryGameObjDefPointer->LandingPosDistance = value;
	}

	int AirFactoryGameObjDef::DropCinematicDefId::get()
	{
		return InternalAirFactoryGameObjDefPointer->DropCinematicDefId;
	}

	void AirFactoryGameObjDef::DropCinematicDefId::set(int value)
	{
		InternalAirFactoryGameObjDefPointer->DropCinematicDefId = value;
	}

	int AirFactoryGameObjDef::CinematicSlotIndex::get()
	{
		return InternalAirFactoryGameObjDefPointer->CinematicSlotIndex;
	}

	void AirFactoryGameObjDef::CinematicSlotIndex::set(int value)
	{
		InternalAirFactoryGameObjDefPointer->CinematicSlotIndex = value;
	}

	float AirFactoryGameObjDef::CinematicTimer::get()
	{
		return InternalAirFactoryGameObjDefPointer->CinematicTimer;
	}

	void AirFactoryGameObjDef::CinematicTimer::set(float value)
	{
		InternalAirFactoryGameObjDefPointer->CinematicTimer = value;
	}

	bool AirFactoryGameObjDef::DefaultEngineEnable::get()
	{
		return InternalAirFactoryGameObjDefPointer->DefaultEngineEnable;
	}

	void AirFactoryGameObjDef::DefaultEngineEnable::set(bool value)
	{
		InternalAirFactoryGameObjDefPointer->DefaultEngineEnable = value;
	}

	::BuildingGameObjDef *AirFactoryGameObjDef::InternalBuildingGameObjDefPointer::get()
	{
		return InternalAirFactoryGameObjDefPointer;
	}

	::AirFactoryGameObjDef *AirFactoryGameObjDef::InternalAirFactoryGameObjDefPointer::get()
	{
		return reinterpret_cast<::AirFactoryGameObjDef *>(Pointer.ToPointer());
	}
}