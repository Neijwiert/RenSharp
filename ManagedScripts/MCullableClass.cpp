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
#include "MCullableClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <CullableClass.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MCullSystemClass.h"
#include "MAABoxClass.h"
#include "Imports.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	CullLinkClass::CullLinkClass(ICullSystemClass ^system)
		: AbstractUnmanagedObject(IntPtr(Imports::CreateCullLinkClass(
			system == nullptr || system->CullSystemClassPointer.ToPointer() == nullptr ? nullptr : reinterpret_cast<::CullSystemClass *>(system->CullSystemClassPointer.ToPointer()))))
	{

	}

	CullLinkClass::CullLinkClass()
	{

	}

	CullLinkClass::CullLinkClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<ICullLinkClass ^> ^CullLinkClass::CreateCullLinkClass(ICullSystemClass ^system)
	{
		return gcnew UnmanagedContainer<ICullLinkClass ^>(gcnew CullLinkClass(system));
	}

	bool CullLinkClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		ICullLinkClass ^otherThis = dynamic_cast<ICullLinkClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return CullLinkClassPointer.Equals(otherThis->CullLinkClassPointer);
	}

	IntPtr CullLinkClass::CullLinkClassPointer::get()
	{
		return IntPtr(InternalCullLinkClassPointer);
	}

	ICullSystemClass ^CullLinkClass::CullingSystem::get()
	{
		auto result = InternalCullLinkClassPointer->Get_Culling_System();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew CullSystemClass(IntPtr(result));
		}
	}

	void CullLinkClass::CullingSystem::set(ICullSystemClass ^value)
	{
		if (value == nullptr || value->CullSystemClassPointer.ToPointer() == nullptr)
		{
			InternalCullLinkClassPointer->Set_Culling_System(nullptr);
		}
		else
		{
			InternalCullLinkClassPointer->Set_Culling_System(reinterpret_cast<::CullSystemClass *>(value->CullSystemClassPointer.ToPointer()));
		}
	}

	bool CullLinkClass::InternalDestroyPointer()
	{
		Imports::DestroyCullLinkClass(InternalCullLinkClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::CullLinkClass *CullLinkClass::InternalCullLinkClassPointer::get()
	{
		return reinterpret_cast<::CullLinkClass *>(Pointer.ToPointer());
	}

	CullableClass::CullableClass(IntPtr pointer)
		: RefCountClass(pointer)
	{

	}

	IntPtr CullableClass::CullableClassPointer::get()
	{
		return IntPtr(InternalCullableClassPointer);
	}

	AABoxClass CullableClass::CullBox::get()
	{
		AABoxClass result;
		AABoxClass::UnmanagedToManagedAABoxClass(InternalCullableClassPointer->Get_Cull_Box(), result);

		return result;
	}

	ICullLinkClass ^CullableClass::CullLink::get()
	{
		auto result = InternalCullableClassPointer->Get_Cull_Link();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew CullLinkClass(IntPtr(result));
		}
	}

	void CullableClass::CullLink::set(ICullLinkClass ^value)
	{
		if (value == nullptr || value->CullLinkClassPointer.ToPointer() == nullptr)
		{
			InternalCullableClassPointer->Set_Cull_Link(nullptr);
		}
		else
		{
			InternalCullableClassPointer->Set_Cull_Link(reinterpret_cast<::CullLinkClass *>(value->CullLinkClassPointer.ToPointer()));
		}
	}

	::RefCountClass *CullableClass::InternalRefCountClassPointer::get()
	{
		return InternalCullableClassPointer;
	}

	::CullableClass *CullableClass::InternalCullableClassPointer::get()
	{
		return reinterpret_cast<::CullableClass *>(Pointer.ToPointer());
	}
}