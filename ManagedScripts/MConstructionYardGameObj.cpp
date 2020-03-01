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
#include "MConstructionYardGameObj.h"

#include "MConstructionYardGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4091 4251 4244 26495 26454)
#include <ConstructionYardGameObj.h>
#include <ConstructionYardGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	ConstructionYardGameObj::ConstructionYardGameObj(IntPtr pointer)
		: BuildingGameObj(pointer)
	{

	}

	IConstructionYardGameObj ^ConstructionYardGameObj::AsConstructionYardGameObj()
	{
		return this;
	}

	void ConstructionYardGameObj::SetSpy(bool set)
	{
		InternalConstructionYardGameObjPointer->Set_Spy(set);
	}

	IntPtr ConstructionYardGameObj::ConstructionYardGameObjPointer::get()
	{
		return IntPtr(InternalConstructionYardGameObjPointer);
	}

	IConstructionYardGameObjDef ^ConstructionYardGameObj::Definition::get()
	{
		return safe_cast<IConstructionYardGameObjDef^>(DefinitionClass::CreateDefinitionClassWrapper(&InternalConstructionYardGameObjPointer->Get_Definition()));
	}

	::PhysObserverClass *ConstructionYardGameObj::InternalPhysObserverClassPointer::get()
	{
		return InternalConstructionYardGameObjPointer;
	}

	::CombatPhysObserverClass *ConstructionYardGameObj::InternalCombatPhysObserverClassPointer::get()
	{
		return InternalConstructionYardGameObjPointer;
	}

	::BuildingGameObj *ConstructionYardGameObj::InternalBuildingGameObjPointer::get()
	{
		return InternalConstructionYardGameObjPointer;
	}

	::ConstructionYardGameObj *ConstructionYardGameObj::InternalConstructionYardGameObjPointer::get()
	{
		return reinterpret_cast<::ConstructionYardGameObj *>(Pointer.ToPointer());
	}
}