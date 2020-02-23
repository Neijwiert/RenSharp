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
#include "MVisTableClassMultiListClass.h"

#include "Imports.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	VisTableClassMultiListClass::VisTableClassMultiListClass()
		: MultiListClass<IVisTableClass^>(IntPtr(Imports::CreateVisTableClassMultiListClass()))
	{

	}

	VisTableClassMultiListClass::VisTableClassMultiListClass(IntPtr pointer)
		: MultiListClass<IVisTableClass^>(pointer)
	{

	}

	IUnmanagedContainer<IMultiListClass<IVisTableClass^>^>^ VisTableClassMultiListClass::CreateVisTableClassMultiListClass()
	{
		return gcnew UnmanagedContainer<IMultiListClass<IVisTableClass^>^>(gcnew VisTableClassMultiListClass());
	}

	bool VisTableClassMultiListClass::Contains(IVisTableClass^ obj)
	{
		return GenericContains(obj);
	}

	bool VisTableClassMultiListClass::Add(IVisTableClass^ obj, bool onlyOnce)
	{
		if (obj == nullptr || obj->VisTableClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalVisTableClassMultiListClassPointer->Add(
			reinterpret_cast<::VisTableClass*>(obj->VisTableClassPointer.ToPointer()),
			onlyOnce);
	}

	bool VisTableClassMultiListClass::AddTail(IVisTableClass^ obj, bool onlyOnce)
	{
		if (obj == nullptr || obj->VisTableClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalVisTableClassMultiListClassPointer->Add_Tail(
			reinterpret_cast<::VisTableClass*>(obj->VisTableClassPointer.ToPointer()),
			onlyOnce);
	}

	bool VisTableClassMultiListClass::AddTail(IVisTableClass^ obj)
	{
		if (obj == nullptr || obj->VisTableClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalVisTableClassMultiListClassPointer->Add_Tail(
			reinterpret_cast<::VisTableClass*>(obj->VisTableClassPointer.ToPointer()));
	}

	bool VisTableClassMultiListClass::AddAfter(IVisTableClass^ obj, IVisTableClass^ existingListMember, bool onlyOnce)
	{
		if (obj == nullptr || obj->VisTableClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (existingListMember == nullptr || existingListMember->VisTableClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("existingListMember");
		}

		return InternalVisTableClassMultiListClassPointer->Add_After(
			reinterpret_cast<::VisTableClass*>(obj->VisTableClassPointer.ToPointer()),
			reinterpret_cast<::VisTableClass*>(existingListMember->VisTableClassPointer.ToPointer()),
			onlyOnce);
	}

	bool VisTableClassMultiListClass::AddAfter(IVisTableClass^ obj, IVisTableClass^ existingListMember)
	{
		if (obj == nullptr || obj->VisTableClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (existingListMember == nullptr || existingListMember->VisTableClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("existingListMember");
		}

		return InternalVisTableClassMultiListClassPointer->Add_After(
			reinterpret_cast<::VisTableClass*>(obj->VisTableClassPointer.ToPointer()),
			reinterpret_cast<::VisTableClass*>(existingListMember->VisTableClassPointer.ToPointer()));
	}

	IVisTableClass^ VisTableClassMultiListClass::GetHead()
	{
		auto result = InternalVisTableClassMultiListClassPointer->Get_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew VisTableClass(IntPtr(result));
		}
	}

	IVisTableClass^ VisTableClassMultiListClass::PeekHead()
	{
		auto result = InternalVisTableClassMultiListClassPointer->Peek_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew VisTableClass(IntPtr(result));
		}
	}

	IVisTableClass^ VisTableClassMultiListClass::RemoveHead()
	{
		auto result = InternalVisTableClassMultiListClassPointer->Remove_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew VisTableClass(IntPtr(result));
		}
	}

	void VisTableClassMultiListClass::ResetList()
	{
		InternalVisTableClassMultiListClassPointer->Reset_List();
	}

	bool VisTableClassMultiListClass::Remove(IVisTableClass^ item)
	{
		if (item == nullptr || item->VisTableClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("item");
		}

		return InternalVisTableClassMultiListClassPointer->Remove(
			reinterpret_cast<::VisTableClass*>(item->VisTableClassPointer.ToPointer()));
	}

	IntPtr VisTableClassMultiListClass::VisTableClassMultiListClassPointer::get()
	{
		return IntPtr(InternalVisTableClassMultiListClassPointer);
	}

	IUnmanagedContainer<IMultiListIterator<IVisTableClass^>^>^ VisTableClassMultiListClass::Iterator::get()
	{
		return VisTableClassMultiListIterator::CreateVisTableClassMultiListIterator(this);
	}

	bool VisTableClassMultiListClass::InternalDestroyPointer()
	{
		Imports::DestroyVisTableClassMultiListClass(InternalVisTableClassMultiListClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::MultiListClass<::VisTableClass>* VisTableClassMultiListClass::InternalVisTableClassMultiListClassPointer::get()
	{
		return reinterpret_cast<::MultiListClass<::VisTableClass>*>(Pointer.ToPointer());
	}

	VisTableClassMultiListIterator::VisTableClassMultiListIterator(IMultiListClass<IVisTableClass^>^ list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		Pointer = IntPtr(Imports::CreateVisTableClassMultiListIterator(
			reinterpret_cast<::MultiListClass<::VisTableClass>*>(list->Pointer.ToPointer())));
	}

	VisTableClassMultiListIterator::VisTableClassMultiListIterator(IntPtr pointer)
		: MultiListIterator<IVisTableClass^>(pointer)
	{

	}

	IUnmanagedContainer<IMultiListIterator<IVisTableClass^>^>^ VisTableClassMultiListIterator::CreateVisTableClassMultiListIterator(
		IMultiListClass<IVisTableClass^>^ list)
	{
		return gcnew UnmanagedContainer<IMultiListIterator<IVisTableClass^>^>(gcnew VisTableClassMultiListIterator(list));
	}

	IVisTableClass^ VisTableClassMultiListIterator::GetObj()
	{
		auto result = InternalVisTableClassMultiListIteratorPointer->Get_Obj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew VisTableClass(IntPtr(result));
		}
	}

	IVisTableClass^ VisTableClassMultiListIterator::PeekObj()
	{
		auto result = InternalVisTableClassMultiListIteratorPointer->Peek_Obj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew VisTableClass(IntPtr(result));
		}
	}

	void VisTableClassMultiListIterator::RemoveCurrentObject()
	{
		InternalVisTableClassMultiListIteratorPointer->Remove_Current_Object();
	}

	IntPtr VisTableClassMultiListIterator::VisTableClassMultiListIteratorPointer::get()
	{
		return IntPtr(InternalVisTableClassMultiListIteratorPointer);
	}

	bool VisTableClassMultiListIterator::InternalDestroyPointer()
	{
		Imports::DestroyVisTableClassMultiListIterator(InternalVisTableClassMultiListIteratorPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::MultiListIterator<::VisTableClass>* VisTableClassMultiListIterator::InternalVisTableClassMultiListIteratorPointer::get()
	{
		return reinterpret_cast<::MultiListIterator<::VisTableClass>*>(Pointer.ToPointer());
	}
}