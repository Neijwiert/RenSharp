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
#include "MTexProjectClassMultiListClass.h"

#include "Imports.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	TexProjectClassMultiListClass::TexProjectClassMultiListClass()
		: MultiListClass<IntPtr>(IntPtr(Imports::CreateTexProjectClassMultiListClass()))
	{

	}

	TexProjectClassMultiListClass::TexProjectClassMultiListClass(IntPtr pointer)
		: MultiListClass<IntPtr>(pointer)
	{

	}

	IUnmanagedContainer<IMultiListClass<IntPtr>^>^ TexProjectClassMultiListClass::CreateTexProjectClassMultiListClass()
	{
		return gcnew UnmanagedContainer<IMultiListClass<IntPtr>^>(gcnew TexProjectClassMultiListClass());
	}

	bool TexProjectClassMultiListClass::Contains(IntPtr obj)
	{
		if (obj.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalTexProjectClassMultiListClassPointer->Contains(
			reinterpret_cast<::MultiListObjectClass*>(obj.ToPointer()));
	}

	bool TexProjectClassMultiListClass::Add(IntPtr obj, bool onlyOnce)
	{
		throw gcnew NotSupportedException();
	}

	bool TexProjectClassMultiListClass::AddTail(IntPtr obj, bool onlyOnce)
	{
		throw gcnew NotSupportedException();
	}

	bool TexProjectClassMultiListClass::AddTail(IntPtr obj)
	{
		throw gcnew NotSupportedException();
	}

	bool TexProjectClassMultiListClass::AddAfter(IntPtr obj, IntPtr existingListMember, bool onlyOnce)
	{
		throw gcnew NotSupportedException();
	}

	bool TexProjectClassMultiListClass::AddAfter(IntPtr obj, IntPtr existingListMember)
	{
		throw gcnew NotSupportedException();
	}

	IntPtr TexProjectClassMultiListClass::GetHead()
	{
		auto result = InternalTexProjectClassMultiListClassPointer->Get_Head();
		if (result == nullptr)
		{
			return IntPtr::Zero;
		}
		else
		{
			return IntPtr(result);
		}
	}

	IntPtr TexProjectClassMultiListClass::PeekHead()
	{
		auto result = InternalTexProjectClassMultiListClassPointer->Peek_Head();
		if (result == nullptr)
		{
			return IntPtr::Zero;
		}
		else
		{
			return IntPtr(result);
		}
	}

	IntPtr TexProjectClassMultiListClass::RemoveHead()
	{
		auto result = InternalTexProjectClassMultiListClassPointer->Remove_Head();
		if (result == nullptr)
		{
			return IntPtr::Zero;
		}
		else
		{
			return IntPtr(result);
		}
	}

	void TexProjectClassMultiListClass::ResetList()
	{
		InternalTexProjectClassMultiListClassPointer->Reset_List();
	}

	bool TexProjectClassMultiListClass::Remove(IntPtr item)
	{
		throw gcnew NotSupportedException();
	}

	IntPtr TexProjectClassMultiListClass::TexProjectClassMultiListClassPointer::get()
	{
		return IntPtr(InternalTexProjectClassMultiListClassPointer);
	}

	IUnmanagedContainer<IMultiListIterator<IntPtr>^>^ TexProjectClassMultiListClass::Iterator::get()
	{
		return TexProjectClassMultiListIterator::CreateTexProjectClassMultiListIterator(this);
	}

	bool TexProjectClassMultiListClass::InternalDestroyPointer()
	{
		Imports::DestroyTexProjectClassMultiListClass(InternalTexProjectClassMultiListClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::MultiListClass<::TexProjectClass>* TexProjectClassMultiListClass::InternalTexProjectClassMultiListClassPointer::get()
	{
		return reinterpret_cast<::MultiListClass<::TexProjectClass>*>(Pointer.ToPointer());
	}

	TexProjectClassMultiListIterator::TexProjectClassMultiListIterator(IMultiListClass<IntPtr>^ list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		Pointer = IntPtr(Imports::CreateTexProjectClassMultiListIterator(
			reinterpret_cast<::MultiListClass<::TexProjectClass>*>(list->Pointer.ToPointer())));
	}

	TexProjectClassMultiListIterator::TexProjectClassMultiListIterator(IntPtr pointer)
		: MultiListIterator<IntPtr>(pointer)
	{

	}

	IUnmanagedContainer<IMultiListIterator<IntPtr>^>^ TexProjectClassMultiListIterator::CreateTexProjectClassMultiListIterator(
		IMultiListClass<IntPtr>^ list)
	{
		return gcnew UnmanagedContainer<IMultiListIterator<IntPtr>^>(gcnew TexProjectClassMultiListIterator(list));
	}

	IntPtr TexProjectClassMultiListIterator::GetObj()
	{
		auto result = InternalTexProjectClassMultiListIteratorPointer->Get_Obj();
		if (result == nullptr)
		{
			return IntPtr::Zero;
		}
		else
		{
			return IntPtr(result);
		}
	}

	IntPtr TexProjectClassMultiListIterator::PeekObj()
	{
		auto result = InternalTexProjectClassMultiListIteratorPointer->Peek_Obj();
		if (result == nullptr)
		{
			return IntPtr::Zero;
		}
		else
		{
			return IntPtr(result);
		}
	}

	void TexProjectClassMultiListIterator::RemoveCurrentObject()
	{
		throw gcnew NotSupportedException();
	}

	IntPtr TexProjectClassMultiListIterator::TexProjectClassMultiListIteratorPointer::get()
	{
		return IntPtr(InternalTexProjectClassMultiListIteratorPointer);
	}

	bool TexProjectClassMultiListIterator::InternalDestroyPointer()
	{
		Imports::DestroyTexProjectClassMultiListIterator(InternalTexProjectClassMultiListIteratorPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::MultiListIterator<::TexProjectClass>* TexProjectClassMultiListIterator::InternalTexProjectClassMultiListIteratorPointer::get()
	{
		return reinterpret_cast<::MultiListIterator<::TexProjectClass>*>(Pointer.ToPointer());
	}
}