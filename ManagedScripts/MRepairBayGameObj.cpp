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
#include "MRepairBayGameObj.h"

#include "MRepairBayGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4091 4251 4244 26495 26454)
#include <RepairBayGameObj.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	RepairBayGameObj::RepairBayGameObj(IntPtr pointer)
		: BuildingGameObj(pointer)
	{

	}

	IRepairBayGameObj ^RepairBayGameObj::AsRepairBayGameObj()
	{
		return this;
	}

	IntPtr RepairBayGameObj::RepairBayGameObjPointer::get()
	{
		return IntPtr(InternalRepairBayGameObjPointer);
	}

	IRepairBayGameObjDef ^RepairBayGameObj::Definition::get()
	{
		return gcnew RepairBayGameObjDef(IntPtr(const_cast<::RepairBayGameObjDef *>(&InternalRepairBayGameObjPointer->Get_Definition())));
	}

	::PhysObserverClass *RepairBayGameObj::InternalPhysObserverClassPointer::get()
	{
		return InternalRepairBayGameObjPointer;
	}

	::CombatPhysObserverClass *RepairBayGameObj::InternalCombatPhysObserverClassPointer::get()
	{
		return InternalRepairBayGameObjPointer;
	}

	::BuildingGameObj *RepairBayGameObj::InternalBuildingGameObjPointer::get()
	{
		return InternalRepairBayGameObjPointer;
	}

	::RepairBayGameObj *RepairBayGameObj::InternalRepairBayGameObjPointer::get()
	{
		return reinterpret_cast<::RepairBayGameObj *>(Pointer.ToPointer());
	}
}