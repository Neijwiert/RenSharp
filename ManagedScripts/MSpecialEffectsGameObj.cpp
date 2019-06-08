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
#include "MSpecialEffectsGameObj.h"

#include "MSpecialEffectsGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <SpecialEffectsGameObj.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	SpecialEffectsGameObj::SpecialEffectsGameObj(IntPtr pointer)
		: PhysicalGameObj(pointer)
	{

	}

	IntPtr SpecialEffectsGameObj::SpecialEffectsGameObjPointer::get()
	{
		return IntPtr(InternalSpecialEffectsGameObjPointer);
	}

	ISpecialEffectsGameObjDef^ SpecialEffectsGameObj::Definition::get()
	{
		return gcnew SpecialEffectsGameObjDef(IntPtr(const_cast<::SpecialEffectsGameObjDef*>(&InternalSpecialEffectsGameObjPointer->Get_Definition())));
	}

	::PhysObserverClass* SpecialEffectsGameObj::InternalPhysObserverClassPointer::get()
	{
		return InternalSpecialEffectsGameObjPointer;
	}

	::CombatPhysObserverClass* SpecialEffectsGameObj::InternalCombatPhysObserverClassPointer::get()
	{
		return InternalSpecialEffectsGameObjPointer;
	}

	::PhysicalGameObj* SpecialEffectsGameObj::InternalPhysicalGameObjPointer::get()
	{
		return InternalSpecialEffectsGameObjPointer;
	}

	::SpecialEffectsGameObj* SpecialEffectsGameObj::InternalSpecialEffectsGameObjPointer::get()
	{
		return reinterpret_cast<::SpecialEffectsGameObj*>(Pointer.ToPointer());
	}
}