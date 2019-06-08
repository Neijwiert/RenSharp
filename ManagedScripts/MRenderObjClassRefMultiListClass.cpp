/*
Copyright 2019 Neijwiert

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
#include "MRenderObjClassRefMultiListClass.h"

#include "Imports.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	RenderObjClassRefMultiListClass::RenderObjClassRefMultiListClass()
		: RefMultiListClass<IRenderObjClass^>(IntPtr(Imports::CreateRenderObjClassRefMultiListClass()))
	{

	}

	RenderObjClassRefMultiListClass::RenderObjClassRefMultiListClass(IntPtr pointer)
		: RefMultiListClass<IRenderObjClass^>(pointer)
	{

	}

	IUnmanagedContainer<IRefMultiListClass<IRenderObjClass^>^>^ RenderObjClassRefMultiListClass::CreateRenderObjClassRefMultiListClass()
	{
		return gcnew UnmanagedContainer<IRefMultiListClass<IRenderObjClass^>^>(gcnew RenderObjClassRefMultiListClass());
	}

	bool RenderObjClassRefMultiListClass::Contains(IRenderObjClass^ obj)
	{
		return GenericContains(obj);
	}

	bool RenderObjClassRefMultiListClass::Add(IRenderObjClass^ obj, bool onlyOnce)
	{
		if (obj == nullptr || obj->RenderObjClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalRenderObjClassRefMultiListClassPointer->Add(
			reinterpret_cast<::RenderObjClass*>(obj->RenderObjClassPointer.ToPointer()),
			onlyOnce);
	}

	bool RenderObjClassRefMultiListClass::AddTail(IRenderObjClass^ obj, bool onlyOnce)
	{
		if (obj == nullptr || obj->RenderObjClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalRenderObjClassRefMultiListClassPointer->Add_Tail(
			reinterpret_cast<::RenderObjClass*>(obj->RenderObjClassPointer.ToPointer()),
			onlyOnce);
	}

	bool RenderObjClassRefMultiListClass::AddTail(IRenderObjClass^ obj)
	{
		if (obj == nullptr || obj->RenderObjClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalRenderObjClassRefMultiListClassPointer->Add_Tail(
			reinterpret_cast<::RenderObjClass*>(obj->RenderObjClassPointer.ToPointer()));
	}

	bool RenderObjClassRefMultiListClass::AddAfter(IRenderObjClass^ obj, IRenderObjClass^ existingListMember, bool onlyOnce)
	{
		if (obj == nullptr || obj->RenderObjClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (existingListMember == nullptr || existingListMember->RenderObjClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("existingListMember");
		}

		return InternalRenderObjClassRefMultiListClassPointer->Add_After(
			reinterpret_cast<::RenderObjClass*>(obj->RenderObjClassPointer.ToPointer()),
			reinterpret_cast<::RenderObjClass*>(existingListMember->RenderObjClassPointer.ToPointer()),
			onlyOnce);
	}

	bool RenderObjClassRefMultiListClass::AddAfter(IRenderObjClass^ obj, IRenderObjClass^ existingListMember)
	{
		if (obj == nullptr || obj->RenderObjClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (existingListMember == nullptr || existingListMember->RenderObjClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("existingListMember");
		}

		return InternalRenderObjClassRefMultiListClassPointer->Add_After(
			reinterpret_cast<::RenderObjClass*>(obj->RenderObjClassPointer.ToPointer()),
			reinterpret_cast<::RenderObjClass*>(existingListMember->RenderObjClassPointer.ToPointer()));
	}

	bool RenderObjClassRefMultiListClass::ReleaseHead()
	{
		return InternalRenderObjClassRefMultiListClassPointer->Release_Head();
	}

	IRenderObjClass^ RenderObjClassRefMultiListClass::GetHead()
	{
		auto result = InternalRenderObjClassRefMultiListClassPointer->Get_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(result));
		}
	}

	IRenderObjClass^ RenderObjClassRefMultiListClass::PeekHead()
	{
		auto result = InternalRenderObjClassRefMultiListClassPointer->Peek_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(result));
		}
	}

	IRenderObjClass^ RenderObjClassRefMultiListClass::RemoveHead()
	{
		auto result = InternalRenderObjClassRefMultiListClassPointer->Remove_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(result));
		}
	}

	void RenderObjClassRefMultiListClass::ResetList()
	{
		InternalRenderObjClassRefMultiListClassPointer->Reset_List();
	}

	bool RenderObjClassRefMultiListClass::Remove(IRenderObjClass^ item)
	{
		if (item == nullptr || item->RenderObjClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("item");
		}

		return InternalRenderObjClassRefMultiListClassPointer->Remove(
			reinterpret_cast<::RenderObjClass*>(item->RenderObjClassPointer.ToPointer()));
	}

	IntPtr RenderObjClassRefMultiListClass::RenderObjClassRefMultiListClassPointer::get()
	{
		return IntPtr(InternalRenderObjClassRefMultiListClassPointer);
	}

	IUnmanagedContainer<IRefMultiListIterator<IRenderObjClass^>^>^ RenderObjClassRefMultiListClass::Iterator::get()
	{
		return RenderObjClassRefMultiListIterator::CreateRenderObjClassRefMultiListIterator(this);
	}

	bool RenderObjClassRefMultiListClass::InternalDestroyPointer()
	{
		Imports::DestroyRenderObjClassRefMultiListClass(InternalRenderObjClassRefMultiListClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::RefMultiListClass<::RenderObjClass>* RenderObjClassRefMultiListClass::InternalRenderObjClassRefMultiListClassPointer::get()
	{
		return reinterpret_cast<::RefMultiListClass<::RenderObjClass>*>(Pointer.ToPointer());
	}

	RenderObjClassRefMultiListIterator::RenderObjClassRefMultiListIterator(IRefMultiListClass<IRenderObjClass^>^ list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		Pointer = IntPtr(Imports::CreateRenderObjClassRefMultiListIterator(
			reinterpret_cast<::RefMultiListClass<::RenderObjClass>*>(list->Pointer.ToPointer())));
	}

	RenderObjClassRefMultiListIterator::RenderObjClassRefMultiListIterator(IntPtr pointer)
		: RefMultiListIterator<IRenderObjClass^>(pointer)
	{

	}

	IUnmanagedContainer<IRefMultiListIterator<IRenderObjClass^>^>^ RenderObjClassRefMultiListIterator::CreateRenderObjClassRefMultiListIterator(
		IRefMultiListClass<IRenderObjClass^>^ list)
	{
		return gcnew UnmanagedContainer<IRefMultiListIterator<IRenderObjClass^>^>(gcnew RenderObjClassRefMultiListIterator(list));
	}

	IRenderObjClass^ RenderObjClassRefMultiListIterator::GetObj()
	{
		auto result = InternalRenderObjClassRefMultiListIteratorPointer->Get_Obj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(result));
		}
	}

	IRenderObjClass^ RenderObjClassRefMultiListIterator::PeekObj()
	{
		auto result = InternalRenderObjClassRefMultiListIteratorPointer->Peek_Obj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(result));
		}
	}

	void RenderObjClassRefMultiListIterator::RemoveCurrentObject()
	{
		InternalRenderObjClassRefMultiListIteratorPointer->Remove_Current_Object();
	}

	IntPtr RenderObjClassRefMultiListIterator::RenderObjClassRefMultiListIteratorPointer::get()
	{
		return IntPtr(InternalRenderObjClassRefMultiListIteratorPointer);
	}

	bool RenderObjClassRefMultiListIterator::InternalDestroyPointer()
	{
		Imports::DestroyRenderObjClassRefMultiListIterator(InternalRenderObjClassRefMultiListIteratorPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::RefMultiListIterator<::RenderObjClass>* RenderObjClassRefMultiListIterator::InternalRenderObjClassRefMultiListIteratorPointer::get()
	{
		return reinterpret_cast<::RefMultiListIterator<::RenderObjClass>*>(Pointer.ToPointer());
	}
}