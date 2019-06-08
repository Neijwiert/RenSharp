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
#include "MNavalFactoryGameObj.h"

#include "MNavalFactoryGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4091 4251 4244 26495 26454)
#include <NavalFactoryGameObj.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	NavalFactoryGameObj::NavalFactoryGameObj(IntPtr pointer)
		: BuildingGameObj(pointer)
	{

	}

	INavalFactoryGameObj ^NavalFactoryGameObj::AsNavalFactoryGameObj()
	{
		return this;
	}

	IntPtr NavalFactoryGameObj::NavalFactoryGameObjPointer::get()
	{
		return IntPtr(InternalNavalFactoryGameObjPointer);
	}

	INavalFactoryGameObjDef ^NavalFactoryGameObj::Definition::get()
	{
		return gcnew NavalFactoryGameObjDef(IntPtr(const_cast<::NavalFactoryGameObjDef *>(&InternalNavalFactoryGameObjPointer->Get_Definition())));
	}

	bool NavalFactoryGameObj::IsAvailable::get()
	{
		return InternalNavalFactoryGameObjPointer->Is_Available();
	}

	bool NavalFactoryGameObj::IsBusy::get()
	{
		return InternalNavalFactoryGameObjPointer->Is_Busy();
	}

	void NavalFactoryGameObj::IsBusy::set(bool value)
	{
		InternalNavalFactoryGameObjPointer->Set_Busy(value);
	}

	bool NavalFactoryGameObj::IsDisabled::get()
	{
		return InternalNavalFactoryGameObjPointer->Is_Disabled();
	}

	void NavalFactoryGameObj::IsDisabled::set(bool value)
	{
		InternalNavalFactoryGameObjPointer->Set_Disabled(value);
	}

	::PhysObserverClass *NavalFactoryGameObj::InternalPhysObserverClassPointer::get()
	{
		return InternalNavalFactoryGameObjPointer;
	}

	::CombatPhysObserverClass *NavalFactoryGameObj::InternalCombatPhysObserverClassPointer::get()
	{
		return InternalNavalFactoryGameObjPointer;
	}

	::BuildingGameObj *NavalFactoryGameObj::InternalBuildingGameObjPointer::get()
	{
		return InternalNavalFactoryGameObjPointer;
	}

	::NavalFactoryGameObj *NavalFactoryGameObj::InternalNavalFactoryGameObjPointer::get()
	{
		return reinterpret_cast<::NavalFactoryGameObj *>(Pointer.ToPointer());
	}
}