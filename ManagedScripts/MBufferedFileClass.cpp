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
#include "MBufferedFileClass.h"

#include "CriticalUnmanagedContainer.h"
#include "Imports.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <BufferedFileClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	BufferedFileClass::BufferedFileClass(bool create)
		: RawFileClass(false)
	{
		if (create)
		{
			Pointer = IntPtr(Imports::CreateBufferedFileClass());
		}
	}

	BufferedFileClass::BufferedFileClass(IntPtr pointer)
		: RawFileClass(pointer)
	{

	}

	IUnmanagedContainer<IBufferedFileClass^>^ BufferedFileClass::CreateBufferedFileClass()
	{
		return gcnew CriticalUnmanagedContainer<IBufferedFileClass^>(gcnew BufferedFileClass(true));
	}

	void BufferedFileClass::ResetBuffer()
	{
		InternalBufferedFileClassPointer->Reset_Buffer();
	}

	IntPtr BufferedFileClass::BufferedFileClassPointer::get()
	{
		return IntPtr(InternalBufferedFileClassPointer);
	}

	::RawFileClass* BufferedFileClass::InternalRawFileClassPointer::get()
	{
		return InternalBufferedFileClassPointer;
	}

	::BufferedFileClass* BufferedFileClass::InternalBufferedFileClassPointer::get()
	{
		return reinterpret_cast<::BufferedFileClass*>(Pointer.ToPointer());
	}
}