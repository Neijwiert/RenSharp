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
#include "MComCenterGameObj.h"

#include "MComCenterGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4091 4251 4244 26495 26454)
#include <ComCenterGameObj.h>
#include <ComCenterGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	ComCenterGameObj::ComCenterGameObj(IntPtr pointer)
		: BuildingGameObj(pointer)
	{

	}

	IComCenterGameObj ^ComCenterGameObj::AsComCenterGameObj()
	{
		return this;
	}

	IntPtr ComCenterGameObj::ComCenterGameObjPointer::get()
	{
		return IntPtr(InternalComCenterGameObjPointer);
	}

	IComCenterGameObjDef ^ComCenterGameObj::Definition::get()
	{
		auto result = DefinitionClass::CreateDefinitionClassWrapper(&InternalComCenterGameObjPointer->Get_Definition());
		if (result != nullptr)
		{
			return safe_cast<IComCenterGameObjDef^>(result);
		}

		return gcnew ComCenterGameObjDef(IntPtr(const_cast<::ComCenterGameObjDef *>(&InternalComCenterGameObjPointer->Get_Definition())));
	}

	::PhysObserverClass *ComCenterGameObj::InternalPhysObserverClassPointer::get()
	{
		return InternalComCenterGameObjPointer;
	}

	::CombatPhysObserverClass *ComCenterGameObj::InternalCombatPhysObserverClassPointer::get()
	{
		return InternalComCenterGameObjPointer;
	}

	::BuildingGameObj *ComCenterGameObj::InternalBuildingGameObjPointer::get()
	{
		return InternalComCenterGameObjPointer;
	}

	::ComCenterGameObj *ComCenterGameObj::InternalComCenterGameObjPointer::get()
	{
		return reinterpret_cast<::ComCenterGameObj *>(Pointer.ToPointer());
	}
}