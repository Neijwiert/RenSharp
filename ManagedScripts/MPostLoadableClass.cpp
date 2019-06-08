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
#include "MPostLoadableClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <PostLoadableClass.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "UnmanagedContainer.h"
#include "Imports.h"

namespace RenSharp
{
	PostLoadableClass::PostLoadableClass(bool create)
		: AbstractUnmanagedObject()
	{
		if (create)
		{
			Pointer = IntPtr(Imports::CreatePostLoadableClass());
		}
	}

	PostLoadableClass::PostLoadableClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool PostLoadableClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IPostLoadableClass ^otherThis = dynamic_cast<IPostLoadableClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return PostLoadableClassPointer.Equals(otherThis->PostLoadableClassPointer);
	}

	IUnmanagedContainer<IPostLoadableClass ^> ^PostLoadableClass::CreatePostLoadableClass()
	{
		return gcnew UnmanagedContainer<IPostLoadableClass ^>(gcnew PostLoadableClass(true));
	}

	void PostLoadableClass::OnPostLoad()
	{
		InternalPostLoadableClassPointer->On_Post_Load();
	}

	IntPtr PostLoadableClass::PostLoadableClassPointer::get()
	{
		return IntPtr(InternalPostLoadableClassPointer);
	}

	bool PostLoadableClass::IsPostLoadRegistered::get()
	{
		return InternalPostLoadableClassPointer->Is_Post_Load_Registered();
	}

	void PostLoadableClass::IsPostLoadRegistered::set(bool value)
	{
		InternalPostLoadableClassPointer->Set_Post_Load_Registered(value);
	}

	bool PostLoadableClass::InternalDestroyPointer()
	{
		Imports::DestroyPostLoadableClass(InternalPostLoadableClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::PostLoadableClass *PostLoadableClass::InternalPostLoadableClassPointer::get()
	{
		return reinterpret_cast<::PostLoadableClass *>(Pointer.ToPointer());
	}
}