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
#include "Mengine_vector.h"

#include "Imports.h"

namespace RenSharp
{
	IGenericList ^GenericNode::MainList::get()
	{
		auto mainList = InternalGenericNodePointer->Main_List();
		if (mainList == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew GenericList(IntPtr(mainList));
		}
	}

	RefCountClass::RefCountClass()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateRefCountClass()))
	{

	}

	RefCountClass::RefCountClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IRefCountClass ^> ^RefCountClass::CreateRefCountClass()
	{
		return gcnew UnmanagedContainer<IRefCountClass ^>(gcnew RefCountClass());
	}

	bool RefCountClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IRefCountClass ^otherThis = dynamic_cast<IRefCountClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return RefCountClassPointer.Equals(otherThis->RefCountClassPointer);
	}

	void RefCountClass::DeleteThis()
	{
		InternalRefCountClassPointer->Delete_This();
	}

	void RefCountClass::ReleaseRef()
	{
		Imports::RefCountClassReleaseRef(InternalRefCountClassPointer);
	}

	void RefCountClass::AddRef()
	{
		InternalRefCountClassPointer->Add_Ref();
	}

	void RefCountClass::Release()
	{
		Imports::RefCountClassRelease(InternalRefCountClassPointer);
	}

	IntPtr RefCountClass::RefCountClassPointer::get()
	{
		return IntPtr(InternalRefCountClassPointer);
	}

	int RefCountClass::NumRefs::get()
	{
		return InternalRefCountClassPointer->Num_Refs();
	}

	bool RefCountClass::InternalDestroyPointer()
	{
		Release();
		Pointer = IntPtr::Zero;

		return true;
	}

	::RefCountClass *RefCountClass::InternalRefCountClassPointer::get()
	{
		return reinterpret_cast<::RefCountClass *>(Pointer.ToPointer());
	}
}