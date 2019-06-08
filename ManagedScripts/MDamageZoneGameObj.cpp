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
#include "MDamageZoneGameObj.h"

#include "Mobboxclass.h"
#include "MDamageZoneGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <DamageZoneGameObj.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DamageZoneGameObj::DamageZoneGameObj(IntPtr pointer)
		: BaseGameObj(pointer)
	{

	}

	IntPtr DamageZoneGameObj::DamageZoneGameObjPointer::get()
	{
		return IntPtr(InternalDamageZoneGameObjPointer);
	}

	IDamageZoneGameObjDef^ DamageZoneGameObj::Definition::get()
	{
		return gcnew DamageZoneGameObjDef(IntPtr(const_cast<::DamageZoneGameObjDef*>(&InternalDamageZoneGameObjPointer->Get_Definition())));
	}

	OBBoxClass DamageZoneGameObj::BoundingBox::get()
	{
		OBBoxClass result;

		OBBoxClass::UnmanagedToManagedOBBoxClass(InternalDamageZoneGameObjPointer->Get_Bounding_Box(), result);

		return result;
	}

	void DamageZoneGameObj::BoundingBox::set(OBBoxClass value)
	{
		::OBBoxClass valueBox;

		OBBoxClass::ManagedToUnmanagedOBBoxClass(value, valueBox);

		InternalDamageZoneGameObjPointer->Set_Bounding_Box(valueBox);
	}

	::PostLoadableClass* DamageZoneGameObj::InternalPostLoadableClassPointer::get()
	{
		return InternalDamageZoneGameObjPointer;
	}

	::PersistClass* DamageZoneGameObj::InternalPersistClassPointer::get()
	{
		return InternalDamageZoneGameObjPointer;
	}

	::BaseGameObj* DamageZoneGameObj::InternalBaseGameObjPointer::get()
	{
		return InternalDamageZoneGameObjPointer;
	}

	::DamageZoneGameObj* DamageZoneGameObj::InternalDamageZoneGameObjPointer::get()
	{
		return reinterpret_cast<::DamageZoneGameObj*>(Pointer.ToPointer());
	}
}