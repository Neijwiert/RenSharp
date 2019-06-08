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
#include "MWidgetUserClass.h"

#include "Imports.h"
#include "UnmanagedContainer.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <WidgetUserClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	WidgetUserClass::WidgetUserClass()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateWidgetUserClass()))
	{

	}

	WidgetUserClass::WidgetUserClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IWidgetUserClass^>^ WidgetUserClass::CreateWidgetUserClass()
	{
		return gcnew UnmanagedContainer<IWidgetUserClass^>(gcnew WidgetUserClass());
	}

	bool WidgetUserClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IWidgetUserClass^ otherThis = dynamic_cast<IWidgetUserClass^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return WidgetUserClassPointer.Equals(otherThis->WidgetUserClassPointer);
	}

	IntPtr WidgetUserClass::WidgetUserClassPointer::get()
	{
		return IntPtr(InternalWidgetUserClassPointer);
	}

	bool WidgetUserClass::InternalDestroyPointer()
	{
		Imports::DestroyWidgetUserClass(InternalWidgetUserClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::WidgetUserClass* WidgetUserClass::InternalWidgetUserClassPointer::get()
	{
		return reinterpret_cast<::WidgetUserClass*>(Pointer.ToPointer());
	}
}