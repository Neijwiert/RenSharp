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
#include "MPhysClassRefMultiListClass.h"

#include "Imports.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	PhysClassRefMultiListClass::PhysClassRefMultiListClass()
		: RefMultiListClass<IPhysClass^>(IntPtr(Imports::CreatePhysClassRefMultiListClass()))
	{

	}

	PhysClassRefMultiListClass::PhysClassRefMultiListClass(IntPtr pointer)
		: RefMultiListClass<IPhysClass^>(pointer)
	{

	}

	IUnmanagedContainer<IRefMultiListClass<IPhysClass^>^>^ PhysClassRefMultiListClass::CreatePhysClassRefMultiListClass()
	{
		return gcnew UnmanagedContainer<IRefMultiListClass<IPhysClass^>^>(gcnew PhysClassRefMultiListClass());
	}

	bool PhysClassRefMultiListClass::Contains(IPhysClass^ obj)
	{
		return GenericContains(obj);
	}

	bool PhysClassRefMultiListClass::Add(IPhysClass^ obj, bool onlyOnce)
	{
		if (obj == nullptr || obj->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalPhysClassRefMultiListClassPointer->Add(
			reinterpret_cast<::PhysClass*>(obj->PhysClassPointer.ToPointer()),
			onlyOnce);
	}

	bool PhysClassRefMultiListClass::AddTail(IPhysClass^ obj, bool onlyOnce)
	{
		if (obj == nullptr || obj->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalPhysClassRefMultiListClassPointer->Add_Tail(
			reinterpret_cast<::PhysClass*>(obj->PhysClassPointer.ToPointer()),
			onlyOnce);
	}

	bool PhysClassRefMultiListClass::AddTail(IPhysClass^ obj)
	{
		if (obj == nullptr || obj->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalPhysClassRefMultiListClassPointer->Add_Tail(
			reinterpret_cast<::PhysClass*>(obj->PhysClassPointer.ToPointer()));
	}

	bool PhysClassRefMultiListClass::AddAfter(IPhysClass^ obj, IPhysClass^ existingListMember, bool onlyOnce)
	{
		if (obj == nullptr || obj->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (existingListMember == nullptr || existingListMember->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("existingListMember");
		}

		return InternalPhysClassRefMultiListClassPointer->Add_After(
			reinterpret_cast<::PhysClass*>(obj->PhysClassPointer.ToPointer()),
			reinterpret_cast<::PhysClass*>(existingListMember->PhysClassPointer.ToPointer()),
			onlyOnce);
	}

	bool PhysClassRefMultiListClass::AddAfter(IPhysClass^ obj, IPhysClass^ existingListMember)
	{
		if (obj == nullptr || obj->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (existingListMember == nullptr || existingListMember->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("existingListMember");
		}

		return InternalPhysClassRefMultiListClassPointer->Add_After(
			reinterpret_cast<::PhysClass*>(obj->PhysClassPointer.ToPointer()),
			reinterpret_cast<::PhysClass*>(existingListMember->PhysClassPointer.ToPointer()));
	}

	bool PhysClassRefMultiListClass::ReleaseHead()
	{
		return InternalPhysClassRefMultiListClassPointer->Release_Head();
	}

	IPhysClass^ PhysClassRefMultiListClass::GetHead()
	{
		auto result = InternalPhysClassRefMultiListClassPointer->Get_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return PhysClass::CreatePhysClassWrapper(result);
		}
	}

	IPhysClass^ PhysClassRefMultiListClass::PeekHead()
	{
		auto result = InternalPhysClassRefMultiListClassPointer->Peek_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return PhysClass::CreatePhysClassWrapper(result);
		}
	}

	IPhysClass^ PhysClassRefMultiListClass::RemoveHead()
	{
		auto result = InternalPhysClassRefMultiListClassPointer->Remove_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return PhysClass::CreatePhysClassWrapper(result);
		}
	}

	void PhysClassRefMultiListClass::ResetList()
	{
		InternalPhysClassRefMultiListClassPointer->Reset_List();
	}

	bool PhysClassRefMultiListClass::Remove(IPhysClass^ item)
	{
		if (item == nullptr || item->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("item");
		}

		return InternalPhysClassRefMultiListClassPointer->Remove(
			reinterpret_cast<::PhysClass*>(item->PhysClassPointer.ToPointer()));
	}

	IntPtr PhysClassRefMultiListClass::PhysClassRefMultiListClassPointer::get()
	{
		return IntPtr(InternalPhysClassRefMultiListClassPointer);
	}

	IUnmanagedContainer<IRefMultiListIterator<IPhysClass^>^>^ PhysClassRefMultiListClass::Iterator::get()
	{
		return PhysClassRefMultiListIterator::CreatePhysClassRefMultiListIterator(this);
	}

	bool PhysClassRefMultiListClass::InternalDestroyPointer()
	{
		Imports::DestroyPhysClassRefMultiListClass(InternalPhysClassRefMultiListClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::GenericMultiListClass* PhysClassRefMultiListClass::InternalGenericMultiListClassPointer::get()
	{
		return InternalPhysClassRefMultiListClassPointer;
	}

	::RefMultiListClass<::PhysClass>* PhysClassRefMultiListClass::InternalPhysClassRefMultiListClassPointer::get()
	{
		return reinterpret_cast<::RefMultiListClass<::PhysClass>*>(Pointer.ToPointer());
	}

	PhysClassRefMultiListIterator::PhysClassRefMultiListIterator(IRefMultiListClass<IPhysClass^>^ list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		Pointer = IntPtr(Imports::CreatePhysClassRefMultiListIterator(
			reinterpret_cast<::RefMultiListClass<::PhysClass>*>(list->Pointer.ToPointer())));
	}

	PhysClassRefMultiListIterator::PhysClassRefMultiListIterator(IntPtr pointer)
		: RefMultiListIterator<IPhysClass^>(pointer)
	{

	}

	IUnmanagedContainer<IRefMultiListIterator<IPhysClass^>^>^ PhysClassRefMultiListIterator::CreatePhysClassRefMultiListIterator(
		IRefMultiListClass<IPhysClass^>^ list)
	{
		return gcnew UnmanagedContainer<IRefMultiListIterator<IPhysClass^>^>(gcnew PhysClassRefMultiListIterator(list));
	}

	IPhysClass^ PhysClassRefMultiListIterator::GetObj()
	{
		auto result = InternalPhysClassRefMultiListIteratorPointer->Get_Obj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return PhysClass::CreatePhysClassWrapper(result);
		}
	}

	IPhysClass^ PhysClassRefMultiListIterator::PeekObj()
	{
		auto result = InternalPhysClassRefMultiListIteratorPointer->Peek_Obj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return PhysClass::CreatePhysClassWrapper(result);
		}
	}

	void PhysClassRefMultiListIterator::RemoveCurrentObject()
	{
		InternalPhysClassRefMultiListIteratorPointer->Remove_Current_Object();
	}

	IntPtr PhysClassRefMultiListIterator::PhysClassRefMultiListIteratorPointer::get()
	{
		return IntPtr(InternalPhysClassRefMultiListIteratorPointer);
	}

	bool PhysClassRefMultiListIterator::InternalDestroyPointer()
	{
		Imports::DestroyPhysClassRefMultiListIterator(InternalPhysClassRefMultiListIteratorPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::RefMultiListIterator<::PhysClass>* PhysClassRefMultiListIterator::InternalPhysClassRefMultiListIteratorPointer::get()
	{
		return reinterpret_cast<::RefMultiListIterator<::PhysClass>*>(Pointer.ToPointer());
	}
}