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
#include "MStaticPhysClassRefMultiListClass.h"

#include "Imports.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	StaticPhysClassRefMultiListClass::StaticPhysClassRefMultiListClass()
		: RefMultiListClass<IStaticPhysClass ^>(IntPtr(Imports::CreateStaticPhysClassRefMultiListClass()))
	{

	}

	StaticPhysClassRefMultiListClass::StaticPhysClassRefMultiListClass(IntPtr pointer)
		: RefMultiListClass<IStaticPhysClass ^>(pointer)
	{

	}

	IUnmanagedContainer<IRefMultiListClass<IStaticPhysClass ^> ^> ^StaticPhysClassRefMultiListClass::CreateStaticPhysClassRefMultiListClass()
	{
		return gcnew UnmanagedContainer<IRefMultiListClass<IStaticPhysClass ^> ^>(gcnew StaticPhysClassRefMultiListClass());
	}

	bool StaticPhysClassRefMultiListClass::Contains(IStaticPhysClass ^obj)
	{
		return GenericContains(obj);
	}

	bool StaticPhysClassRefMultiListClass::Add(IStaticPhysClass ^obj, bool onlyOnce)
	{
		if (obj == nullptr || obj->StaticPhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalStaticPhysClassRefMultiListClassPointer->Add(
			reinterpret_cast<::StaticPhysClass *>(obj->StaticPhysClassPointer.ToPointer()),
			onlyOnce);
	}

	bool StaticPhysClassRefMultiListClass::AddTail(IStaticPhysClass ^obj, bool onlyOnce)
	{
		if (obj == nullptr || obj->StaticPhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalStaticPhysClassRefMultiListClassPointer->Add_Tail(
			reinterpret_cast<::StaticPhysClass *>(obj->StaticPhysClassPointer.ToPointer()),
			onlyOnce);
	}

	bool StaticPhysClassRefMultiListClass::AddTail(IStaticPhysClass ^obj)
	{
		if (obj == nullptr || obj->StaticPhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalStaticPhysClassRefMultiListClassPointer->Add_Tail(
			reinterpret_cast<::StaticPhysClass *>(obj->StaticPhysClassPointer.ToPointer()));
	}

	bool StaticPhysClassRefMultiListClass::AddAfter(IStaticPhysClass ^obj, IStaticPhysClass ^existingListMember, bool onlyOnce)
	{
		if (obj == nullptr || obj->StaticPhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (existingListMember == nullptr || existingListMember->StaticPhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("existingListMember");
		}

		return InternalStaticPhysClassRefMultiListClassPointer->Add_After(
			reinterpret_cast<::StaticPhysClass *>(obj->StaticPhysClassPointer.ToPointer()),
			reinterpret_cast<::StaticPhysClass *>(existingListMember->StaticPhysClassPointer.ToPointer()),
			onlyOnce);
	}

	bool StaticPhysClassRefMultiListClass::AddAfter(IStaticPhysClass ^obj, IStaticPhysClass ^existingListMember)
	{
		if (obj == nullptr || obj->StaticPhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (existingListMember == nullptr || existingListMember->StaticPhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("existingListMember");
		}

		return InternalStaticPhysClassRefMultiListClassPointer->Add_After(
			reinterpret_cast<::StaticPhysClass *>(obj->StaticPhysClassPointer.ToPointer()),
			reinterpret_cast<::StaticPhysClass *>(existingListMember->StaticPhysClassPointer.ToPointer()));
	}

	bool StaticPhysClassRefMultiListClass::ReleaseHead()
	{
		return InternalStaticPhysClassRefMultiListClassPointer->Release_Head();
	}

	IStaticPhysClass ^StaticPhysClassRefMultiListClass::GetHead()
	{
		auto result = InternalStaticPhysClassRefMultiListClassPointer->Get_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IStaticPhysClass^>(PhysClass::CreatePhysClassWrapper(result));
		}
	}

	IStaticPhysClass ^StaticPhysClassRefMultiListClass::PeekHead()
	{
		auto result = InternalStaticPhysClassRefMultiListClassPointer->Peek_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IStaticPhysClass^>(PhysClass::CreatePhysClassWrapper(result));
		}
	}

	IStaticPhysClass ^StaticPhysClassRefMultiListClass::RemoveHead()
	{
		auto result = InternalStaticPhysClassRefMultiListClassPointer->Remove_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IStaticPhysClass^>(PhysClass::CreatePhysClassWrapper(result));
		}
	}

	void StaticPhysClassRefMultiListClass::ResetList()
	{
		InternalStaticPhysClassRefMultiListClassPointer->Reset_List();
	}

	bool StaticPhysClassRefMultiListClass::Remove(IStaticPhysClass ^item)
	{
		if (item == nullptr || item->StaticPhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("item");
		}

		return InternalStaticPhysClassRefMultiListClassPointer->Remove(
			reinterpret_cast<::StaticPhysClass *>(item->StaticPhysClassPointer.ToPointer()));
	}

	IntPtr StaticPhysClassRefMultiListClass::StaticPhysClassRefMultiListClassPointer::get()
	{
		return IntPtr(InternalStaticPhysClassRefMultiListClassPointer);
	}

	IUnmanagedContainer<IRefMultiListIterator<IStaticPhysClass ^> ^> ^StaticPhysClassRefMultiListClass::Iterator::get()
	{
		return StaticPhysClassRefMultiListIterator::CreateStaticPhysClassRefMultiListIterator(this);
	}

	bool StaticPhysClassRefMultiListClass::InternalDestroyPointer()
	{
		Imports::DestroyStaticPhysClassRefMultiListClass(InternalStaticPhysClassRefMultiListClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::GenericMultiListClass* StaticPhysClassRefMultiListClass::InternalGenericMultiListClassPointer::get()
	{
		return InternalStaticPhysClassRefMultiListClassPointer;
	}

	::RefMultiListClass<::StaticPhysClass> *StaticPhysClassRefMultiListClass::InternalStaticPhysClassRefMultiListClassPointer::get()
	{
		return reinterpret_cast<::RefMultiListClass<::StaticPhysClass> *>(Pointer.ToPointer());
	}

	StaticPhysClassRefMultiListIterator::StaticPhysClassRefMultiListIterator(IRefMultiListClass<IStaticPhysClass ^> ^list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		Pointer = IntPtr(Imports::CreateStaticPhysClassRefMultiListIterator(
			reinterpret_cast<::RefMultiListClass<::StaticPhysClass> *>(list->Pointer.ToPointer())));
	}

	StaticPhysClassRefMultiListIterator::StaticPhysClassRefMultiListIterator(IntPtr pointer)
		: RefMultiListIterator<IStaticPhysClass ^>(pointer)
	{

	}

	IUnmanagedContainer<IRefMultiListIterator<IStaticPhysClass ^> ^> ^StaticPhysClassRefMultiListIterator::CreateStaticPhysClassRefMultiListIterator(
		IRefMultiListClass<IStaticPhysClass ^> ^list)
	{
		return gcnew UnmanagedContainer<IRefMultiListIterator<IStaticPhysClass ^> ^>(gcnew StaticPhysClassRefMultiListIterator(list));
	}

	IStaticPhysClass ^StaticPhysClassRefMultiListIterator::GetObj()
	{
		auto result = InternalStaticPhysClassRefMultiListIteratorPointer->Get_Obj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IStaticPhysClass^>(PhysClass::CreatePhysClassWrapper(result));
		}
	}

	IStaticPhysClass ^StaticPhysClassRefMultiListIterator::PeekObj()
	{
		auto result = InternalStaticPhysClassRefMultiListIteratorPointer->Peek_Obj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IStaticPhysClass^>(PhysClass::CreatePhysClassWrapper(result));
		}
	}

	void StaticPhysClassRefMultiListIterator::RemoveCurrentObject()
	{
		InternalStaticPhysClassRefMultiListIteratorPointer->Remove_Current_Object();
	}

	IntPtr StaticPhysClassRefMultiListIterator::StaticPhysClassRefMultiListIteratorPointer::get()
	{
		return IntPtr(InternalStaticPhysClassRefMultiListIteratorPointer);
	}

	bool StaticPhysClassRefMultiListIterator::InternalDestroyPointer()
	{
		Imports::DestroyStaticPhysClassRefMultiListIterator(InternalStaticPhysClassRefMultiListIteratorPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::RefMultiListIterator<::StaticPhysClass> *StaticPhysClassRefMultiListIterator::InternalStaticPhysClassRefMultiListIteratorPointer::get()
	{
		return reinterpret_cast<::RefMultiListIterator<::StaticPhysClass> *>(Pointer.ToPointer());
	}
}