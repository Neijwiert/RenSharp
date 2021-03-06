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
#include "MDecorationPhysClass.h"

#include "MAABoxClass.h"
#include "MDecorationPhysDefClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <DecorationPhysClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DecorationPhysClass::DecorationPhysClass(IntPtr pointer)
		: DynamicPhysClass(pointer)
	{

	}

	IntPtr DecorationPhysClass::DecorationPhysClassPointer::get()
	{
		return IntPtr(InternalDecorationPhysClassPointer);
	}

	IDecorationPhysDefClass^ DecorationPhysClass::DecorationPhysDef::get()
	{
		auto defPtr = InternalDecorationPhysClassPointer->Get_Definition();
		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IDecorationPhysDefClass^>(DefinitionClass::CreateDefinitionClassWrapper(defPtr));
		}
	}

	AABoxClass DecorationPhysClass::BoundingBox::get()
	{
		AABoxClass result;

		AABoxClass::UnmanagedToManagedAABoxClass(InternalDecorationPhysClassPointer->Get_Bounding_Box(), result);

		return result;
	}

	::DynamicPhysClass *DecorationPhysClass::InternalDynamicPhysClassPointer::get()
	{
		return InternalDecorationPhysClassPointer;
	}

	::DecorationPhysClass *DecorationPhysClass::InternalDecorationPhysClassPointer::get()
	{
		return reinterpret_cast<::DecorationPhysClass *>(Pointer.ToPointer());
	}
}