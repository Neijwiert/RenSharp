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
#include "MLightPhysClassRefMultiListClass.h"

#include "Imports.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	LightPhysClassRefMultiListClass::LightPhysClassRefMultiListClass()
		: RefMultiListClass<ILightPhysClass ^>(IntPtr(Imports::CreateLightPhysClassRefMultiListClass()))
	{

	}

	LightPhysClassRefMultiListClass::LightPhysClassRefMultiListClass(IntPtr pointer)
		: RefMultiListClass<ILightPhysClass ^>(pointer)
	{

	}

	IUnmanagedContainer<IRefMultiListClass<ILightPhysClass ^> ^> ^LightPhysClassRefMultiListClass::CreateLightPhysClassRefMultiListClass()
	{
		return gcnew UnmanagedContainer<IRefMultiListClass<ILightPhysClass ^> ^>(gcnew LightPhysClassRefMultiListClass());
	}

	bool LightPhysClassRefMultiListClass::Contains(ILightPhysClass ^obj)
	{
		return GenericContains(obj);
	}

	bool LightPhysClassRefMultiListClass::Add(ILightPhysClass ^obj, bool onlyOnce)
	{
		if (obj == nullptr || obj->LightPhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalLightPhysClassRefMultiListClassPointer->Add(
			reinterpret_cast<::LightPhysClass *>(obj->LightPhysClassPointer.ToPointer()),
			onlyOnce);
	}

	bool LightPhysClassRefMultiListClass::AddTail(ILightPhysClass ^obj, bool onlyOnce)
	{
		if (obj == nullptr || obj->LightPhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalLightPhysClassRefMultiListClassPointer->Add_Tail(
			reinterpret_cast<::LightPhysClass *>(obj->LightPhysClassPointer.ToPointer()),
			onlyOnce);
	}

	bool LightPhysClassRefMultiListClass::AddTail(ILightPhysClass ^obj)
	{
		if (obj == nullptr || obj->LightPhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalLightPhysClassRefMultiListClassPointer->Add_Tail(
			reinterpret_cast<::LightPhysClass *>(obj->LightPhysClassPointer.ToPointer()));
	}

	bool LightPhysClassRefMultiListClass::AddAfter(ILightPhysClass ^obj, ILightPhysClass ^existingListMember, bool onlyOnce)
	{
		if (obj == nullptr || obj->LightPhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (existingListMember == nullptr || existingListMember->LightPhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("existingListMember");
		}

		return InternalLightPhysClassRefMultiListClassPointer->Add_After(
			reinterpret_cast<::LightPhysClass *>(obj->LightPhysClassPointer.ToPointer()),
			reinterpret_cast<::LightPhysClass *>(existingListMember->LightPhysClassPointer.ToPointer()),
			onlyOnce);
	}

	bool LightPhysClassRefMultiListClass::AddAfter(ILightPhysClass ^obj, ILightPhysClass ^existingListMember)
	{
		if (obj == nullptr || obj->LightPhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (existingListMember == nullptr || existingListMember->LightPhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("existingListMember");
		}

		return InternalLightPhysClassRefMultiListClassPointer->Add_After(
			reinterpret_cast<::LightPhysClass *>(obj->LightPhysClassPointer.ToPointer()),
			reinterpret_cast<::LightPhysClass *>(existingListMember->LightPhysClassPointer.ToPointer()));
	}

	bool LightPhysClassRefMultiListClass::ReleaseHead()
	{
		return InternalLightPhysClassRefMultiListClassPointer->Release_Head();
	}

	ILightPhysClass ^LightPhysClassRefMultiListClass::GetHead()
	{
		auto result = InternalLightPhysClassRefMultiListClassPointer->Get_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<ILightPhysClass^>(PhysClass::CreatePhysClassWrapper(result));
		}
	}

	ILightPhysClass ^LightPhysClassRefMultiListClass::PeekHead()
	{
		auto result = InternalLightPhysClassRefMultiListClassPointer->Peek_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<ILightPhysClass^>(PhysClass::CreatePhysClassWrapper(result));
		}
	}

	ILightPhysClass ^LightPhysClassRefMultiListClass::RemoveHead()
	{
		auto result = InternalLightPhysClassRefMultiListClassPointer->Remove_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<ILightPhysClass^>(PhysClass::CreatePhysClassWrapper(result));
		}
	}

	void LightPhysClassRefMultiListClass::ResetList()
	{
		InternalLightPhysClassRefMultiListClassPointer->Reset_List();
	}

	bool LightPhysClassRefMultiListClass::Remove(ILightPhysClass ^item)
	{
		if (item == nullptr || item->LightPhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("item");
		}

		return InternalLightPhysClassRefMultiListClassPointer->Remove(
			reinterpret_cast<::LightPhysClass *>(item->LightPhysClassPointer.ToPointer()));
	}

	IntPtr LightPhysClassRefMultiListClass::LightPhysClassRefMultiListClassPointer::get()
	{
		return IntPtr(InternalLightPhysClassRefMultiListClassPointer);
	}

	IUnmanagedContainer<IRefMultiListIterator<ILightPhysClass ^> ^> ^LightPhysClassRefMultiListClass::Iterator::get()
	{
		return LightPhysClassRefMultiListIterator::CreateLightPhysClassRefMultiListIterator(this);
	}

	bool LightPhysClassRefMultiListClass::InternalDestroyPointer()
	{
		Imports::DestroyLightPhysClassRefMultiListClass(InternalLightPhysClassRefMultiListClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::GenericMultiListClass* LightPhysClassRefMultiListClass::InternalGenericMultiListClassPointer::get()
	{
		return InternalLightPhysClassRefMultiListClassPointer;
	}

	::RefMultiListClass<::LightPhysClass> *LightPhysClassRefMultiListClass::InternalLightPhysClassRefMultiListClassPointer::get()
	{
		return reinterpret_cast<::RefMultiListClass<::LightPhysClass> *>(Pointer.ToPointer());
	}

	LightPhysClassRefMultiListIterator::LightPhysClassRefMultiListIterator(IRefMultiListClass<ILightPhysClass ^> ^list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		Pointer = IntPtr(Imports::CreateLightPhysClassRefMultiListIterator(
			reinterpret_cast<::RefMultiListClass<::LightPhysClass> *>(list->Pointer.ToPointer())));
	}

	LightPhysClassRefMultiListIterator::LightPhysClassRefMultiListIterator(IntPtr pointer)
		: RefMultiListIterator<ILightPhysClass ^>(pointer)
	{

	}

	IUnmanagedContainer<IRefMultiListIterator<ILightPhysClass ^> ^> ^LightPhysClassRefMultiListIterator::CreateLightPhysClassRefMultiListIterator(
		IRefMultiListClass<ILightPhysClass ^> ^list)
	{
		return gcnew UnmanagedContainer<IRefMultiListIterator<ILightPhysClass ^> ^>(gcnew LightPhysClassRefMultiListIterator(list));
	}

	ILightPhysClass ^LightPhysClassRefMultiListIterator::GetObj()
	{
		auto result = InternalLightPhysClassRefMultiListIteratorPointer->Get_Obj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<ILightPhysClass^>(PhysClass::CreatePhysClassWrapper(result));
		}
	}

	ILightPhysClass ^LightPhysClassRefMultiListIterator::PeekObj()
	{
		auto result = InternalLightPhysClassRefMultiListIteratorPointer->Peek_Obj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<ILightPhysClass^>(PhysClass::CreatePhysClassWrapper(result));
		}
	}

	void LightPhysClassRefMultiListIterator::RemoveCurrentObject()
	{
		InternalLightPhysClassRefMultiListIteratorPointer->Remove_Current_Object();
	}

	IntPtr LightPhysClassRefMultiListIterator::LightPhysClassRefMultiListIteratorPointer::get()
	{
		return IntPtr(InternalLightPhysClassRefMultiListIteratorPointer);
	}

	bool LightPhysClassRefMultiListIterator::InternalDestroyPointer()
	{
		Imports::DestroyLightPhysClassRefMultiListIterator(InternalLightPhysClassRefMultiListIteratorPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::RefMultiListIterator<::LightPhysClass> *LightPhysClassRefMultiListIterator::InternalLightPhysClassRefMultiListIteratorPointer::get()
	{
		return reinterpret_cast<::RefMultiListIterator<::LightPhysClass> *>(Pointer.ToPointer());
	}
}