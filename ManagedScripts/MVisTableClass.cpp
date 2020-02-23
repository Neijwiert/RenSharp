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
#include "MVisTableClass.h"

#include "Imports.h"
#include "UnmanagedContainer.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <VisTableClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	VisTableClass::VisTableClass(IntPtr pointer)
		: RefCountClass(pointer)
	{
		multiListObjectClass = gcnew MultiListObjectClass(MultiListObjectClassPointer);
	}

	bool VisTableClass::Equals(Object^ other)
	{
		if (RefCountClass::Equals(other))
		{
			return true;
		}

		if (ReferenceEquals(other, nullptr))
		{
			return false;
		}

		auto otherUnmanagedObj = dynamic_cast<IUnmanagedObject^>(other);
		if (otherUnmanagedObj == nullptr || otherUnmanagedObj->Pointer.Equals(IntPtr::Zero))
		{
			return false;
		}

		auto otherMultiListObjectClass = dynamic_cast<IMultiListObjectClass^>(other);
		if (otherMultiListObjectClass != nullptr)
		{
			if (multiListObjectClass->Equals(otherMultiListObjectClass))
			{
				return true;
			}
		}

		auto otherVisTableClass = dynamic_cast<IVisTableClass^>(other);
		if (otherVisTableClass != nullptr)
		{
			if (VisTableClassPointer.Equals(otherVisTableClass->VisTableClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	IntPtr VisTableClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void VisTableClass::Pointer::set(IntPtr value)
	{
		AbstractUnmanagedObject::Pointer::set(value);

		if (Pointer == IntPtr::Zero)
		{
			multiListObjectClass = nullptr;
		}
		else
		{
			multiListObjectClass = gcnew MultiListObjectClass(MultiListObjectClassPointer);
		}
	}

	IntPtr VisTableClass::VisTableClassPointer::get()
	{
		return IntPtr(InternalVisTableClassPointer);
	}

	IntPtr VisTableClass::MultiListObjectClassPointer::get()
	{
		return IntPtr(InternalMultiListObjectClassPointer);
	}

	IMultiListNodeClass^ VisTableClass::ListNode::get()
	{
		return multiListObjectClass->ListNode;
	}

	void VisTableClass::ListNode::set(IMultiListNodeClass^ value)
	{
		multiListObjectClass->ListNode = value;
	}

	IntPtr VisTableClass::Bytes::get()
	{
		return IntPtr(InternalVisTableClassPointer->Get_Bytes());
	}

	IntPtr VisTableClass::Longs::get()
	{
		return IntPtr(InternalVisTableClassPointer->Get_Longs());
	}

	int VisTableClass::BitCount::get()
	{
		return InternalVisTableClassPointer->Get_Bit_Count();
	}

	int VisTableClass::VisSectorID::get()
	{
		return InternalVisTableClassPointer->Get_Vis_Sector_ID();
	}

	void VisTableClass::VisSectorID::set(int value)
	{
		InternalVisTableClassPointer->Set_Vis_Sector_ID(value);
	}

	int VisTableClass::TimeStamp::get()
	{
		return InternalVisTableClassPointer->Get_Time_Stamp();
	}

	void VisTableClass::TimeStamp::set(int value)
	{
		InternalVisTableClassPointer->Set_Time_Stamp(value);
	}

	::RefCountClass* VisTableClass::InternalRefCountClassPointer::get()
	{
		return InternalVisTableClassPointer;
	}

	::MultiListObjectClass* VisTableClass::InternalMultiListObjectClassPointer::get()
	{
		return InternalVisTableClassPointer;
	}

	::VisTableClass* VisTableClass::InternalVisTableClassPointer::get()
	{
		return reinterpret_cast<::VisTableClass*>(Pointer.ToPointer());
	}

	CompressedVisTableClass::CompressedVisTableClass()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateCompressedVisTableClass()))
	{

	}

	CompressedVisTableClass::CompressedVisTableClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<ICompressedVisTableClass^>^ CompressedVisTableClass::CreateCompressedVisTableClass()
	{
		return gcnew UnmanagedContainer<ICompressedVisTableClass^>(gcnew CompressedVisTableClass());
	}

	bool CompressedVisTableClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		ICompressedVisTableClass^ otherThis = dynamic_cast<ICompressedVisTableClass^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return CompressedVisTableClassPointer.Equals(otherThis->CompressedVisTableClassPointer);
	}

	IntPtr CompressedVisTableClass::CompressedVisTableClassPointer::get()
	{
		return IntPtr(InternalCompressedVisTableClassPointer);
	}

	IntPtr CompressedVisTableClass::Bytes::get()
	{
		return IntPtr(InternalCompressedVisTableClassPointer->Get_Bytes());
	}

	int CompressedVisTableClass::ByteCount::get()
	{
		return InternalCompressedVisTableClassPointer->Get_Byte_Count();
	}

	bool CompressedVisTableClass::InternalDestroyPointer()
	{
		Imports::DestroyCompressedVisTableClass(InternalCompressedVisTableClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::CompressedVisTableClass* CompressedVisTableClass::InternalCompressedVisTableClassPointer::get()
	{
		return reinterpret_cast<::CompressedVisTableClass*>(Pointer.ToPointer());
	}
}