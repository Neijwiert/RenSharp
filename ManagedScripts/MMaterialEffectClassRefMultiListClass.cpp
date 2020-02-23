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
#include "MMaterialEffectClassRefMultiListClass.h"

#include "Imports.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	MaterialEffectClassRefMultiListClass::MaterialEffectClassRefMultiListClass()
		: RefMultiListClass<IMaterialEffectClass ^>(IntPtr(Imports::CreateMaterialEffectClassRefMultiListClass()))
	{

	}

	MaterialEffectClassRefMultiListClass::MaterialEffectClassRefMultiListClass(IntPtr pointer)
		: RefMultiListClass<IMaterialEffectClass ^>(pointer)
	{

	}

	IUnmanagedContainer<IRefMultiListClass<IMaterialEffectClass ^> ^> ^MaterialEffectClassRefMultiListClass::CreateMaterialEffectClassRefMultiListClass()
	{
		return gcnew UnmanagedContainer<IRefMultiListClass<IMaterialEffectClass ^> ^>(gcnew MaterialEffectClassRefMultiListClass());
	}

	bool MaterialEffectClassRefMultiListClass::Contains(IMaterialEffectClass ^obj)
	{
		return GenericContains(obj);
	}

	bool MaterialEffectClassRefMultiListClass::Add(IMaterialEffectClass ^obj, bool onlyOnce)
	{
		if (obj == nullptr || obj->MaterialEffectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalMaterialEffectClassRefMultiListClassPointer->Add(
			reinterpret_cast<::MaterialEffectClass *>(obj->MaterialEffectClassPointer.ToPointer()),
			onlyOnce);
	}

	bool MaterialEffectClassRefMultiListClass::AddTail(IMaterialEffectClass ^obj, bool onlyOnce)
	{
		if (obj == nullptr || obj->MaterialEffectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalMaterialEffectClassRefMultiListClassPointer->Add_Tail(
			reinterpret_cast<::MaterialEffectClass *>(obj->MaterialEffectClassPointer.ToPointer()),
			onlyOnce);
	}

	bool MaterialEffectClassRefMultiListClass::AddTail(IMaterialEffectClass ^obj)
	{
		if (obj == nullptr || obj->MaterialEffectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalMaterialEffectClassRefMultiListClassPointer->Add_Tail(
			reinterpret_cast<::MaterialEffectClass *>(obj->MaterialEffectClassPointer.ToPointer()));
	}

	bool MaterialEffectClassRefMultiListClass::AddAfter(IMaterialEffectClass ^obj, IMaterialEffectClass ^existingListMember, bool onlyOnce)
	{
		if (obj == nullptr || obj->MaterialEffectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (existingListMember == nullptr || existingListMember->MaterialEffectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("existingListMember");
		}

		return InternalMaterialEffectClassRefMultiListClassPointer->Add_After(
			reinterpret_cast<::MaterialEffectClass *>(obj->MaterialEffectClassPointer.ToPointer()),
			reinterpret_cast<::MaterialEffectClass *>(existingListMember->MaterialEffectClassPointer.ToPointer()),
			onlyOnce);
	}

	bool MaterialEffectClassRefMultiListClass::AddAfter(IMaterialEffectClass ^obj, IMaterialEffectClass ^existingListMember)
	{
		if (obj == nullptr || obj->MaterialEffectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (existingListMember == nullptr || existingListMember->MaterialEffectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("existingListMember");
		}

		return InternalMaterialEffectClassRefMultiListClassPointer->Add_After(
			reinterpret_cast<::MaterialEffectClass *>(obj->MaterialEffectClassPointer.ToPointer()),
			reinterpret_cast<::MaterialEffectClass *>(existingListMember->MaterialEffectClassPointer.ToPointer()));
	}

	bool MaterialEffectClassRefMultiListClass::ReleaseHead()
	{
		return InternalMaterialEffectClassRefMultiListClassPointer->Release_Head();
	}

	IMaterialEffectClass ^MaterialEffectClassRefMultiListClass::GetHead()
	{
		auto result = InternalMaterialEffectClassRefMultiListClassPointer->Get_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew MaterialEffectClass(IntPtr(result));
		}
	}

	IMaterialEffectClass ^MaterialEffectClassRefMultiListClass::PeekHead()
	{
		auto result = InternalMaterialEffectClassRefMultiListClassPointer->Peek_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew MaterialEffectClass(IntPtr(result));
		}
	}

	IMaterialEffectClass ^MaterialEffectClassRefMultiListClass::RemoveHead()
	{
		auto result = InternalMaterialEffectClassRefMultiListClassPointer->Remove_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew MaterialEffectClass(IntPtr(result));
		}
	}

	void MaterialEffectClassRefMultiListClass::ResetList()
	{
		InternalMaterialEffectClassRefMultiListClassPointer->Reset_List();
	}

	bool MaterialEffectClassRefMultiListClass::Remove(IMaterialEffectClass ^item)
	{
		if (item == nullptr || item->MaterialEffectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("item");
		}

		return InternalMaterialEffectClassRefMultiListClassPointer->Remove(
			reinterpret_cast<::MaterialEffectClass *>(item->MaterialEffectClassPointer.ToPointer()));
	}

	IntPtr MaterialEffectClassRefMultiListClass::MaterialEffectClassRefMultiListClassPointer::get()
	{
		return IntPtr(InternalMaterialEffectClassRefMultiListClassPointer);
	}

	IUnmanagedContainer<IRefMultiListIterator<IMaterialEffectClass ^> ^> ^MaterialEffectClassRefMultiListClass::Iterator::get()
	{
		return MaterialEffectClassRefMultiListIterator::CreateMaterialEffectClassRefMultiListIterator(this);
	}

	bool MaterialEffectClassRefMultiListClass::InternalDestroyPointer()
	{
		Imports::DestroyMaterialEffectClassRefMultiListClass(InternalMaterialEffectClassRefMultiListClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::RefMultiListClass<::MaterialEffectClass> *MaterialEffectClassRefMultiListClass::InternalMaterialEffectClassRefMultiListClassPointer::get()
	{
		return reinterpret_cast<::RefMultiListClass<::MaterialEffectClass> *>(Pointer.ToPointer());
	}

	MaterialEffectClassRefMultiListIterator::MaterialEffectClassRefMultiListIterator(IRefMultiListClass<IMaterialEffectClass ^> ^list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		Pointer = IntPtr(Imports::CreateMaterialEffectClassRefMultiListIterator(
			reinterpret_cast<::RefMultiListClass<::MaterialEffectClass> *>(list->Pointer.ToPointer())));
	}

	MaterialEffectClassRefMultiListIterator::MaterialEffectClassRefMultiListIterator(IntPtr pointer)
		: RefMultiListIterator<IMaterialEffectClass ^>(pointer)
	{

	}

	IUnmanagedContainer<IRefMultiListIterator<IMaterialEffectClass ^> ^> ^MaterialEffectClassRefMultiListIterator::CreateMaterialEffectClassRefMultiListIterator(
		IRefMultiListClass<IMaterialEffectClass ^> ^list)
	{
		return gcnew UnmanagedContainer<IRefMultiListIterator<IMaterialEffectClass ^> ^>(gcnew MaterialEffectClassRefMultiListIterator(list));
	}

	IMaterialEffectClass ^MaterialEffectClassRefMultiListIterator::GetObj()
	{
		auto result = InternalMaterialEffectClassRefMultiListIteratorPointer->Get_Obj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew MaterialEffectClass(IntPtr(result));
		}
	}

	IMaterialEffectClass ^MaterialEffectClassRefMultiListIterator::PeekObj()
	{
		auto result = InternalMaterialEffectClassRefMultiListIteratorPointer->Peek_Obj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew MaterialEffectClass(IntPtr(result));
		}
	}

	void MaterialEffectClassRefMultiListIterator::RemoveCurrentObject()
	{
		InternalMaterialEffectClassRefMultiListIteratorPointer->Remove_Current_Object();
	}

	IntPtr MaterialEffectClassRefMultiListIterator::MaterialEffectClassRefMultiListIteratorPointer::get()
	{
		return IntPtr(InternalMaterialEffectClassRefMultiListIteratorPointer);
	}

	bool MaterialEffectClassRefMultiListIterator::InternalDestroyPointer()
	{
		Imports::DestroyMaterialEffectClassRefMultiListIterator(InternalMaterialEffectClassRefMultiListIteratorPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::RefMultiListIterator<::MaterialEffectClass> *MaterialEffectClassRefMultiListIterator::InternalMaterialEffectClassRefMultiListIteratorPointer::get()
	{
		return reinterpret_cast<::RefMultiListIterator<::MaterialEffectClass> *>(Pointer.ToPointer());
	}
}