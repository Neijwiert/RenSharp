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
#include "MSuperweaponGameObj.h"

#include "MSuperweaponGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4091 4251 4244 26495 26454)
#include <SuperweaponGameObj.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	SuperweaponGameObj::SuperweaponGameObj(IntPtr pointer)
		: BuildingGameObj(pointer)
	{

	}

	ISuperweaponGameObj ^SuperweaponGameObj::AsSuperweaponGameObj()
	{
		return this;
	}

	IntPtr SuperweaponGameObj::SuperweaponGameObjPointer::get()
	{
		return IntPtr(InternalSuperweaponGameObjPointer);
	}

	ISuperweaponGameObjDef ^SuperweaponGameObj::Definition::get()
	{
		return gcnew SuperweaponGameObjDef(IntPtr(const_cast<::SuperweaponGameObjDef *>(&InternalSuperweaponGameObjPointer->Get_Definition())));
	}

	bool SuperweaponGameObj::Launching::get()
	{
		return InternalSuperweaponGameObjPointer->Is_Launching();
	}

	::PhysObserverClass *SuperweaponGameObj::InternalPhysObserverClassPointer::get()
	{
		return InternalSuperweaponGameObjPointer;
	}

	::CombatPhysObserverClass *SuperweaponGameObj::InternalCombatPhysObserverClassPointer::get()
	{
		return InternalSuperweaponGameObjPointer;
	}

	::BuildingGameObj *SuperweaponGameObj::InternalBuildingGameObjPointer::get()
	{
		return InternalSuperweaponGameObjPointer;
	}

	::SuperweaponGameObj *SuperweaponGameObj::InternalSuperweaponGameObjPointer::get()
	{
		return reinterpret_cast<::SuperweaponGameObj *>(Pointer.ToPointer());
	}
}