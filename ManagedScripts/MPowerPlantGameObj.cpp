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
#include "MPowerPlantGameObj.h"

#include "MPowerPlantGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4091 4251 4244 26495 26454)
#include <PowerPlantGameObj.h>
#include <PowerPlantGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	PowerPlantGameObj::PowerPlantGameObj(IntPtr pointer)
		: BuildingGameObj(pointer)
	{

	}

	IntPtr PowerPlantGameObj::PowerPlantGameObjPointer::get()
	{
		return IntPtr(InternalPowerPlantGameObjPointer);
	}

	::PhysObserverClass *PowerPlantGameObj::InternalPhysObserverClassPointer::get()
	{
		return InternalPowerPlantGameObjPointer;
	}

	IPowerPlantGameObjDef ^PowerPlantGameObj::Definition::get()
	{
		return safe_cast<IPowerPlantGameObjDef^>(DefinitionClass::CreateDefinitionClassWrapper(&InternalPowerPlantGameObjPointer->Get_Definition()));
	}

	::CombatPhysObserverClass *PowerPlantGameObj::InternalCombatPhysObserverClassPointer::get()
	{
		return InternalPowerPlantGameObjPointer;
	}

	::BuildingGameObj *PowerPlantGameObj::InternalBuildingGameObjPointer::get()
	{
		return InternalPowerPlantGameObjPointer;
	}

	::PowerPlantGameObj *PowerPlantGameObj::InternalPowerPlantGameObjPointer::get()
	{
		return reinterpret_cast<::PowerPlantGameObj *>(Pointer.ToPointer());
	}
}