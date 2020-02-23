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
#include "MBuildingAggregateClassRefMultiListClass.h"

#include "Imports.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	BuildingAggregateClassRefMultiListClass::BuildingAggregateClassRefMultiListClass()
		: RefMultiListClass<IBuildingAggregateClass ^>(IntPtr(Imports::CreateBuildingAggregateClassRefMultiListClass()))
	{

	}

	BuildingAggregateClassRefMultiListClass::BuildingAggregateClassRefMultiListClass(IntPtr pointer)
		: RefMultiListClass<IBuildingAggregateClass ^>(pointer)
	{

	}

	IUnmanagedContainer<IRefMultiListClass<IBuildingAggregateClass ^> ^> ^BuildingAggregateClassRefMultiListClass::CreateBuildingAggregateClassRefMultiListClass()
	{
		return gcnew UnmanagedContainer<IRefMultiListClass<IBuildingAggregateClass ^> ^>(gcnew BuildingAggregateClassRefMultiListClass());
	}

	bool BuildingAggregateClassRefMultiListClass::Contains(IBuildingAggregateClass ^obj)
	{
		return GenericContains(obj);
	}

	bool BuildingAggregateClassRefMultiListClass::Add(IBuildingAggregateClass ^obj, bool onlyOnce)
	{
		if (obj == nullptr || obj->BuildingAggregateClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalBuildingAggregateClassRefMultiListClassPointer->Add(
			reinterpret_cast<::BuildingAggregateClass *>(obj->BuildingAggregateClassPointer.ToPointer()),
			onlyOnce);
	}

	bool BuildingAggregateClassRefMultiListClass::AddTail(IBuildingAggregateClass ^obj, bool onlyOnce)
	{
		if (obj == nullptr || obj->BuildingAggregateClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalBuildingAggregateClassRefMultiListClassPointer->Add_Tail(
			reinterpret_cast<::BuildingAggregateClass *>(obj->BuildingAggregateClassPointer.ToPointer()),
			onlyOnce);
	}

	bool BuildingAggregateClassRefMultiListClass::AddTail(IBuildingAggregateClass ^obj)
	{
		if (obj == nullptr || obj->BuildingAggregateClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalBuildingAggregateClassRefMultiListClassPointer->Add_Tail(
			reinterpret_cast<::BuildingAggregateClass *>(obj->BuildingAggregateClassPointer.ToPointer()));
	}

	bool BuildingAggregateClassRefMultiListClass::AddAfter(IBuildingAggregateClass ^obj, IBuildingAggregateClass ^existingListMember, bool onlyOnce)
	{
		if (obj == nullptr || obj->BuildingAggregateClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (existingListMember == nullptr || existingListMember->BuildingAggregateClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("existingListMember");
		}

		return InternalBuildingAggregateClassRefMultiListClassPointer->Add_After(
			reinterpret_cast<::BuildingAggregateClass *>(obj->BuildingAggregateClassPointer.ToPointer()),
			reinterpret_cast<::BuildingAggregateClass *>(existingListMember->BuildingAggregateClassPointer.ToPointer()),
			onlyOnce);
	}

	bool BuildingAggregateClassRefMultiListClass::AddAfter(IBuildingAggregateClass ^obj, IBuildingAggregateClass ^existingListMember)
	{
		if (obj == nullptr || obj->BuildingAggregateClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (existingListMember == nullptr || existingListMember->BuildingAggregateClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("existingListMember");
		}

		return InternalBuildingAggregateClassRefMultiListClassPointer->Add_After(
			reinterpret_cast<::BuildingAggregateClass *>(obj->BuildingAggregateClassPointer.ToPointer()),
			reinterpret_cast<::BuildingAggregateClass *>(existingListMember->BuildingAggregateClassPointer.ToPointer()));
	}

	bool BuildingAggregateClassRefMultiListClass::ReleaseHead()
	{
		return InternalBuildingAggregateClassRefMultiListClassPointer->Release_Head();
	}

	IBuildingAggregateClass ^BuildingAggregateClassRefMultiListClass::GetHead()
	{
		auto result = InternalBuildingAggregateClassRefMultiListClassPointer->Get_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BuildingAggregateClass(IntPtr(result));
		}
	}

	IBuildingAggregateClass ^BuildingAggregateClassRefMultiListClass::PeekHead()
	{
		auto result = InternalBuildingAggregateClassRefMultiListClassPointer->Peek_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BuildingAggregateClass(IntPtr(result));
		}
	}

	IBuildingAggregateClass ^BuildingAggregateClassRefMultiListClass::RemoveHead()
	{
		auto result = InternalBuildingAggregateClassRefMultiListClassPointer->Remove_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BuildingAggregateClass(IntPtr(result));
		}
	}

	void BuildingAggregateClassRefMultiListClass::ResetList()
	{
		InternalBuildingAggregateClassRefMultiListClassPointer->Reset_List();
	}

	bool BuildingAggregateClassRefMultiListClass::Remove(IBuildingAggregateClass ^item)
	{
		if (item == nullptr || item->BuildingAggregateClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("item");
		}

		return InternalBuildingAggregateClassRefMultiListClassPointer->Remove(
			reinterpret_cast<::BuildingAggregateClass *>(item->BuildingAggregateClassPointer.ToPointer()));
	}

	IntPtr BuildingAggregateClassRefMultiListClass::BuildingAggregateClassRefMultiListClassPointer::get()
	{
		return IntPtr(InternalBuildingAggregateClassRefMultiListClassPointer);
	}

	IUnmanagedContainer<IRefMultiListIterator<IBuildingAggregateClass ^> ^> ^BuildingAggregateClassRefMultiListClass::Iterator::get()
	{
		return BuildingAggregateClassRefMultiListIterator::CreateBuildingAggregateClassRefMultiListIterator(this);
	}

	bool BuildingAggregateClassRefMultiListClass::InternalDestroyPointer()
	{
		Imports::DestroyBuildingAggregateClassRefMultiListClass(InternalBuildingAggregateClassRefMultiListClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::RefMultiListClass<::BuildingAggregateClass> *BuildingAggregateClassRefMultiListClass::InternalBuildingAggregateClassRefMultiListClassPointer::get()
	{
		return reinterpret_cast<::RefMultiListClass<::BuildingAggregateClass> *>(Pointer.ToPointer());
	}

	BuildingAggregateClassRefMultiListIterator::BuildingAggregateClassRefMultiListIterator(IRefMultiListClass<IBuildingAggregateClass ^> ^list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		Pointer = IntPtr(Imports::CreateBuildingAggregateClassRefMultiListIterator(
			reinterpret_cast<::RefMultiListClass<::BuildingAggregateClass> *>(list->Pointer.ToPointer())));
	}

	BuildingAggregateClassRefMultiListIterator::BuildingAggregateClassRefMultiListIterator(IntPtr pointer)
		: RefMultiListIterator<IBuildingAggregateClass ^>(pointer)
	{

	}

	IUnmanagedContainer<IRefMultiListIterator<IBuildingAggregateClass ^> ^> ^BuildingAggregateClassRefMultiListIterator::CreateBuildingAggregateClassRefMultiListIterator(
		IRefMultiListClass<IBuildingAggregateClass ^> ^list)
	{
		return gcnew UnmanagedContainer<IRefMultiListIterator<IBuildingAggregateClass ^> ^>(gcnew BuildingAggregateClassRefMultiListIterator(list));
	}

	IBuildingAggregateClass ^BuildingAggregateClassRefMultiListIterator::GetObj()
	{
		auto result = InternalBuildingAggregateClassRefMultiListIteratorPointer->Get_Obj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BuildingAggregateClass(IntPtr(result));
		}
	}

	IBuildingAggregateClass ^BuildingAggregateClassRefMultiListIterator::PeekObj()
	{
		auto result = InternalBuildingAggregateClassRefMultiListIteratorPointer->Peek_Obj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BuildingAggregateClass(IntPtr(result));
		}
	}

	void BuildingAggregateClassRefMultiListIterator::RemoveCurrentObject()
	{
		InternalBuildingAggregateClassRefMultiListIteratorPointer->Remove_Current_Object();
	}

	IntPtr BuildingAggregateClassRefMultiListIterator::BuildingAggregateClassRefMultiListIteratorPointer::get()
	{
		return IntPtr(InternalBuildingAggregateClassRefMultiListIteratorPointer);
	}

	bool BuildingAggregateClassRefMultiListIterator::InternalDestroyPointer()
	{
		Imports::DestroyBuildingAggregateClassRefMultiListIterator(InternalBuildingAggregateClassRefMultiListIteratorPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::RefMultiListIterator<::BuildingAggregateClass> *BuildingAggregateClassRefMultiListIterator::InternalBuildingAggregateClassRefMultiListIteratorPointer::get()
	{
		return reinterpret_cast<::RefMultiListIterator<::BuildingAggregateClass> *>(Pointer.ToPointer());
	}
}