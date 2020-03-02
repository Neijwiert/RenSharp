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
#include "MPhysClassMultiListClass.h"

#include "Imports.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	PhysClassMultiListClass::PhysClassMultiListClass()
		: MultiListClass<IPhysClass ^>(IntPtr(Imports::CreatePhysClassMultiListClass()))
	{

	}

	PhysClassMultiListClass::PhysClassMultiListClass(IntPtr pointer)
		: MultiListClass<IPhysClass ^>(pointer)
	{

	}

	IUnmanagedContainer<IMultiListClass<IPhysClass ^> ^> ^PhysClassMultiListClass::CreatePhysClassMultiListClass()
	{
		return gcnew UnmanagedContainer<IMultiListClass<IPhysClass ^> ^>(gcnew PhysClassMultiListClass());
	}

	bool PhysClassMultiListClass::Contains(IPhysClass ^obj)
	{
		return GenericContains(obj);
	}

	bool PhysClassMultiListClass::Add(IPhysClass ^obj, bool onlyOnce)
	{
		if (obj == nullptr || obj->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalPhysClassMultiListClassPointer->Add(
			reinterpret_cast<::PhysClass *>(obj->PhysClassPointer.ToPointer()),
			onlyOnce);
	}

	bool PhysClassMultiListClass::AddTail(IPhysClass ^obj, bool onlyOnce)
	{
		if (obj == nullptr || obj->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalPhysClassMultiListClassPointer->Add_Tail(
			reinterpret_cast<::PhysClass *>(obj->PhysClassPointer.ToPointer()),
			onlyOnce);
	}

	bool PhysClassMultiListClass::AddTail(IPhysClass ^obj)
	{
		if (obj == nullptr || obj->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalPhysClassMultiListClassPointer->Add_Tail(
			reinterpret_cast<::PhysClass *>(obj->PhysClassPointer.ToPointer()));
	}

	bool PhysClassMultiListClass::AddAfter(IPhysClass ^obj, IPhysClass ^existingListMember, bool onlyOnce)
	{
		if (obj == nullptr || obj->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (existingListMember == nullptr || existingListMember->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("existingListMember");
		}

		return InternalPhysClassMultiListClassPointer->Add_After(
			reinterpret_cast<::PhysClass *>(obj->PhysClassPointer.ToPointer()),
			reinterpret_cast<::PhysClass *>(existingListMember->PhysClassPointer.ToPointer()),
			onlyOnce);
	}

	bool PhysClassMultiListClass::AddAfter(IPhysClass ^obj, IPhysClass ^existingListMember)
	{
		if (obj == nullptr || obj->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (existingListMember == nullptr || existingListMember->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("existingListMember");
		}

		return InternalPhysClassMultiListClassPointer->Add_After(
			reinterpret_cast<::PhysClass *>(obj->PhysClassPointer.ToPointer()),
			reinterpret_cast<::PhysClass *>(existingListMember->PhysClassPointer.ToPointer()));
	}

	IPhysClass ^PhysClassMultiListClass::GetHead()
	{
		auto result = InternalPhysClassMultiListClassPointer->Get_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return PhysClass::CreatePhysClassWrapper(result);
		}
	}

	IPhysClass ^PhysClassMultiListClass::PeekHead()
	{
		auto result = InternalPhysClassMultiListClassPointer->Peek_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return PhysClass::CreatePhysClassWrapper(result);
		}
	}

	IPhysClass ^PhysClassMultiListClass::RemoveHead()
	{
		auto result = InternalPhysClassMultiListClassPointer->Remove_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return PhysClass::CreatePhysClassWrapper(result);
		}
	}

	void PhysClassMultiListClass::ResetList()
	{
		InternalPhysClassMultiListClassPointer->Reset_List();
	}

	bool PhysClassMultiListClass::Remove(IPhysClass ^item)
	{
		if (item == nullptr || item->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("item");
		}

		return InternalPhysClassMultiListClassPointer->Remove(
			reinterpret_cast<::PhysClass *>(item->PhysClassPointer.ToPointer()));
	}

	IntPtr PhysClassMultiListClass::PhysClassMultiListClassPointer::get()
	{
		return IntPtr(InternalPhysClassMultiListClassPointer);
	}

	IUnmanagedContainer<IMultiListIterator<IPhysClass ^> ^> ^PhysClassMultiListClass::Iterator::get()
	{
		return PhysClassMultiListIterator::CreatePhysClassMultiListIterator(this);
	}

	bool PhysClassMultiListClass::InternalDestroyPointer()
	{
		Imports::DestroyPhysClassMultiListClass(InternalPhysClassMultiListClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::MultiListClass<::PhysClass> *PhysClassMultiListClass::InternalPhysClassMultiListClassPointer::get()
	{
		return reinterpret_cast<::MultiListClass<::PhysClass> *>(Pointer.ToPointer());
	}

	PhysClassMultiListIterator::PhysClassMultiListIterator(IMultiListClass<IPhysClass ^> ^list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		Pointer = IntPtr(Imports::CreatePhysClassMultiListIterator(
			reinterpret_cast<::MultiListClass<::PhysClass> *>(list->Pointer.ToPointer())));
	}

	PhysClassMultiListIterator::PhysClassMultiListIterator(IntPtr pointer)
		: MultiListIterator<IPhysClass ^>(pointer)
	{

	}

	IUnmanagedContainer<IMultiListIterator<IPhysClass ^> ^> ^PhysClassMultiListIterator::CreatePhysClassMultiListIterator(
		IMultiListClass<IPhysClass ^> ^list)
	{
		return gcnew UnmanagedContainer<IMultiListIterator<IPhysClass ^> ^>(gcnew PhysClassMultiListIterator(list));
	}

	IPhysClass ^PhysClassMultiListIterator::GetObj()
	{
		auto result = InternalPhysClassMultiListIteratorPointer->Get_Obj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return PhysClass::CreatePhysClassWrapper(result);
		}
	}

	IPhysClass ^PhysClassMultiListIterator::PeekObj()
	{
		auto result = InternalPhysClassMultiListIteratorPointer->Peek_Obj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return PhysClass::CreatePhysClassWrapper(result);
		}
	}

	void PhysClassMultiListIterator::RemoveCurrentObject()
	{
		InternalPhysClassMultiListIteratorPointer->Remove_Current_Object();
	}

	IntPtr PhysClassMultiListIterator::PhysClassMultiListIteratorPointer::get()
	{
		return IntPtr(InternalPhysClassMultiListIteratorPointer);
	}

	bool PhysClassMultiListIterator::InternalDestroyPointer()
	{
		Imports::DestroyPhysClassMultiListIterator(InternalPhysClassMultiListIteratorPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::MultiListIterator<::PhysClass> *PhysClassMultiListIterator::InternalPhysClassMultiListIteratorPointer::get()
	{
		return reinterpret_cast<::MultiListIterator<::PhysClass> *>(Pointer.ToPointer());
	}
}