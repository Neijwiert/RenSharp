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
#include "Mmultilist.h"

#include "Imports.h"

namespace RenSharp
{

#pragma managed(push, off)

	class GenericMultiListClassHelper : public ::GenericMultiListClass
	{
		private:
			GenericMultiListClassHelper() = default;

		public:
			bool InternalAdd(::MultiListObjectClass *obj, bool onlyOnce = true)
			{
				return Internal_Add(obj, onlyOnce);
			}

			bool InternalAddTail(::MultiListObjectClass *obj, bool onlyOnce = true)
			{
				return Internal_Add_Tail(obj, onlyOnce);
			}

			bool InternalAddAfter(::MultiListObjectClass *obj, const ::MultiListObjectClass* existingListMember, bool onlyOnce = true)
			{
				return Internal_Add_After(obj, existingListMember, onlyOnce);
			}

			bool InternalRemove(::MultiListObjectClass *obj)
			{
				return Internal_Remove(obj);
			}

			::MultiListObjectClass *InternalRemoveListHead()
			{
				return Internal_Remove_List_Head();
			}

			::MultiListObjectClass* InternalGetListHead() const
			{
				return Internal_Get_List_Head();
			}
	};

	class GenericMultiListIteratorHelper : public ::GenericMultiListIterator
	{
		private:
			GenericMultiListIteratorHelper(const ::GenericMultiListClass *list)
				: ::GenericMultiListIterator(list)
			{

			}

		public:
			::MultiListObjectClass *GetCurrentObject() const
			{
				return Current_Object();
			};

			const ::GenericMultiListClass *GetList() const
			{
				return List;
			}

			const ::MultiListNodeClass *GetCurNode() const
			{
				return CurNode;
			}
	};

#pragma managed(pop)

	MultiListObjectClass::MultiListObjectClass()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateMultiListObjectClass()))
	{

	}

	MultiListObjectClass::MultiListObjectClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IMultiListObjectClass ^> ^MultiListObjectClass::CreateMultiListObjectClass()
	{
		return gcnew UnmanagedContainer<IMultiListObjectClass ^>(gcnew MultiListObjectClass());
	}

	bool MultiListObjectClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IMultiListObjectClass ^otherThis = dynamic_cast<IMultiListObjectClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return MultiListObjectClassPointer.Equals(otherThis->MultiListObjectClassPointer);
	}

	IntPtr MultiListObjectClass::MultiListObjectClassPointer::get()
	{
		return IntPtr(InternalMultiListObjectClassPointer);
	}

	IMultiListNodeClass ^MultiListObjectClass::ListNode::get()
	{
		auto result = InternalMultiListObjectClassPointer->Get_List_Node();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			throw gcnew MultiListNodeClass(IntPtr(result));
		}
	}

	void MultiListObjectClass::ListNode::set(IMultiListNodeClass ^value)
	{
		if (value == nullptr || value->MultiListNodeClassPointer == IntPtr::Zero)
		{
			InternalMultiListObjectClassPointer->Set_List_Node(nullptr);
		}
		else
		{
			InternalMultiListObjectClassPointer->Set_List_Node(reinterpret_cast<::MultiListNodeClass *>(value->MultiListNodeClassPointer.ToPointer()));
		}
	}

	bool MultiListObjectClass::InternalDestroyPointer()
	{
		Imports::DestroyMultiListObjectClass(InternalMultiListObjectClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::MultiListObjectClass *MultiListObjectClass::InternalMultiListObjectClassPointer::get()
	{
		return reinterpret_cast<::MultiListObjectClass *>(Pointer.ToPointer());
	}

	MultiListNodeClass::MultiListNodeClass()
		: AutoPoolClass<IMultiListNodeClass ^>(IntPtr(Imports::CreateMultiListNodeClass()))
	{

	}

	MultiListNodeClass::MultiListNodeClass(IntPtr pointer)
		: AutoPoolClass<IMultiListNodeClass ^>(pointer)
	{

	}

	IUnmanagedContainer<IMultiListNodeClass ^> ^MultiListNodeClass::CreateMultiListNodeClass()
	{
		return gcnew UnmanagedContainer<IMultiListNodeClass ^>(gcnew MultiListNodeClass());
	}

	bool MultiListNodeClass::Equals(System::Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IMultiListNodeClass ^otherThis = dynamic_cast<IMultiListNodeClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return MultiListNodeClassPointer.Equals(otherThis->MultiListNodeClassPointer);
	}

	IntPtr MultiListNodeClass::AutoPoolClassPointer::get()
	{
		return IntPtr(InternalAutoPoolClassPointer);
	}

	IntPtr MultiListNodeClass::MultiListNodeClassPointer::get()
	{
		return IntPtr(InternalMultiListNodeClassPointer);
	}

	IMultiListNodeClass ^MultiListNodeClass::Prev::get()
	{
		auto result = InternalMultiListNodeClassPointer->Prev;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew MultiListNodeClass(IntPtr(result));
		}
	}

	void MultiListNodeClass::Prev::set(IMultiListNodeClass ^value)
	{
		if (value == nullptr || value->MultiListNodeClassPointer.ToPointer() == nullptr)
		{
			InternalMultiListNodeClassPointer->Prev = nullptr;
		}
		else
		{
			InternalMultiListNodeClassPointer->Prev = reinterpret_cast<::MultiListNodeClass *>(value->MultiListNodeClassPointer.ToPointer());
		}
	}

	IMultiListNodeClass ^MultiListNodeClass::Next::get()
	{
		auto result = InternalMultiListNodeClassPointer->Next;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew MultiListNodeClass(IntPtr(result));
		}
	}

	void MultiListNodeClass::Next::set(IMultiListNodeClass ^value)
	{
		if (value == nullptr || value->MultiListNodeClassPointer.ToPointer() == nullptr)
		{
			InternalMultiListNodeClassPointer->Next = nullptr;
		}
		else
		{
			InternalMultiListNodeClassPointer->Next = reinterpret_cast<::MultiListNodeClass *>(value->MultiListNodeClassPointer.ToPointer());
		}
	}

	IMultiListNodeClass ^MultiListNodeClass::NextList::get()
	{
		auto result = InternalMultiListNodeClassPointer->NextList;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew MultiListNodeClass(IntPtr(result));
		}
	}

	void MultiListNodeClass::NextList::set(IMultiListNodeClass ^value)
	{
		if (value == nullptr || value->MultiListNodeClassPointer.ToPointer() == nullptr)
		{
			InternalMultiListNodeClassPointer->NextList = nullptr;
		}
		else
		{
			InternalMultiListNodeClassPointer->NextList = reinterpret_cast<::MultiListNodeClass *>(value->MultiListNodeClassPointer.ToPointer());
		}
	}

	IMultiListObjectClass ^MultiListNodeClass::Object::get()
	{
		auto result = InternalMultiListNodeClassPointer->Object;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew MultiListObjectClass(IntPtr(result));
		}
	}

	void MultiListNodeClass::Object::set(IMultiListObjectClass ^value)
	{
		if (value == nullptr || value->MultiListObjectClassPointer.ToPointer())
		{
			InternalMultiListNodeClassPointer->Object = nullptr;
		}
		else
		{
			InternalMultiListNodeClassPointer->Object = reinterpret_cast<::MultiListObjectClass *>(value->MultiListObjectClassPointer.ToPointer());
		}
	}

	IGenericMultiListClass ^MultiListNodeClass::List::get()
	{
		auto result = InternalMultiListNodeClassPointer->List;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew GenericMultiListClass(IntPtr(result));
		}
	}

	void MultiListNodeClass::List::set(IGenericMultiListClass ^value)
	{
		if (value == nullptr || value->GenericMultiListClassPointer.ToPointer() == nullptr)
		{
			InternalMultiListNodeClassPointer->List = nullptr;
		}
		else
		{
			InternalMultiListNodeClassPointer->List = reinterpret_cast<::GenericMultiListClass *>(value->GenericMultiListClassPointer.ToPointer());
		}
	}

	bool MultiListNodeClass::InternalDestroyPointer()
	{
		Imports::DestroyMultiListNodeClass(InternalMultiListNodeClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::AutoPoolClass<::MultiListNodeClass, 256> *MultiListNodeClass::InternalAutoPoolClassPointer::get()
	{
		return InternalMultiListNodeClassPointer;
	}

	::MultiListNodeClass *MultiListNodeClass::InternalMultiListNodeClassPointer::get()
	{
		return reinterpret_cast<::MultiListNodeClass *>(Pointer.ToPointer());
	}

	GenericMultiListClass::GenericMultiListClass()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateGenericMultiListClass()))
	{

	}

	GenericMultiListClass::GenericMultiListClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IGenericMultiListClass ^> ^GenericMultiListClass::CreateGenericMultiListClass()
	{
		return gcnew UnmanagedContainer<IGenericMultiListClass ^>(gcnew GenericMultiListClass());
	}

	bool GenericMultiListClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IGenericMultiListClass ^otherThis = dynamic_cast<IGenericMultiListClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return GenericMultiListClassPointer.Equals(otherThis->GenericMultiListClassPointer);
	}

	bool GenericMultiListClass::IsInList(IMultiListObjectClass ^obj)
	{
		if (obj == nullptr || obj->MultiListObjectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalGenericMultiListClassPointer->Is_In_List(
			reinterpret_cast<::MultiListObjectClass *>(obj->MultiListObjectClassPointer.ToPointer()));
	}

	bool GenericMultiListClass::GenericContains(IMultiListObjectClass ^obj)
	{
		if (obj == nullptr || obj->MultiListObjectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalGenericMultiListClassPointer->Contains(
			reinterpret_cast<::MultiListObjectClass *>(obj->MultiListObjectClassPointer.ToPointer()));
	}

	IntPtr GenericMultiListClass::GenericMultiListClassPointer::get()
	{
		return IntPtr(InternalGenericMultiListClassPointer);
	}

	bool GenericMultiListClass::IsEmpty::get()
	{
		return InternalGenericMultiListClassPointer->Is_Empty();
	}

	int GenericMultiListClass::Count::get()
	{
		return InternalGenericMultiListClassPointer->Count();
	}

	bool GenericMultiListClass::InternalDestroyPointer()
	{
		Imports::DestroyGenericMultiListClass(InternalGenericMultiListClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	bool GenericMultiListClass::InternalAdd(IMultiListObjectClass ^obj, bool onlyOnce)
	{
		if (obj == nullptr || obj->MultiListObjectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto helper = reinterpret_cast<GenericMultiListClassHelper *>(InternalGenericMultiListClassPointer);

		return helper->InternalAdd(
			reinterpret_cast<::MultiListObjectClass *>(obj->MultiListObjectClassPointer.ToPointer()),
			onlyOnce);
	}

	bool GenericMultiListClass::InternalAdd(IMultiListObjectClass ^obj)
	{
		if (obj == nullptr || obj->MultiListObjectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto helper = reinterpret_cast<GenericMultiListClassHelper *>(InternalGenericMultiListClassPointer);

		return helper->InternalAdd(
			reinterpret_cast<::MultiListObjectClass *>(obj->MultiListObjectClassPointer.ToPointer()));
	}

	bool GenericMultiListClass::InternalAddTail(IMultiListObjectClass ^obj, bool onlyOnce)
	{
		if (obj == nullptr || obj->MultiListObjectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto helper = reinterpret_cast<GenericMultiListClassHelper *>(InternalGenericMultiListClassPointer);

		return helper->InternalAddTail(
			reinterpret_cast<::MultiListObjectClass *>(obj->MultiListObjectClassPointer.ToPointer()),
			onlyOnce);
	}

	bool GenericMultiListClass::InternalAddTail(IMultiListObjectClass ^obj)
	{
		if (obj == nullptr || obj->MultiListObjectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto helper = reinterpret_cast<GenericMultiListClassHelper *>(InternalGenericMultiListClassPointer);

		return helper->InternalAddTail(
			reinterpret_cast<::MultiListObjectClass *>(obj->MultiListObjectClassPointer.ToPointer()));
	}

	bool GenericMultiListClass::InternalAddAfter(IMultiListObjectClass ^obj, IMultiListObjectClass ^existingListMember, bool onlyOnce)
	{
		if (obj == nullptr || obj->MultiListObjectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (existingListMember == nullptr || existingListMember->MultiListObjectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("existingListMember");
		}

		auto helper = reinterpret_cast<GenericMultiListClassHelper *>(InternalGenericMultiListClassPointer);

		return helper->InternalAddAfter(
			reinterpret_cast<::MultiListObjectClass *>(obj->MultiListObjectClassPointer.ToPointer()),
			reinterpret_cast<::MultiListObjectClass *>(existingListMember->MultiListObjectClassPointer.ToPointer()),
			onlyOnce);
	}

	bool GenericMultiListClass::InternalAddAfter(IMultiListObjectClass ^obj, IMultiListObjectClass ^existingListMember)
	{
		if (obj == nullptr || obj->MultiListObjectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (existingListMember == nullptr || existingListMember->MultiListObjectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("existingListMember");
		}

		auto helper = reinterpret_cast<GenericMultiListClassHelper *>(InternalGenericMultiListClassPointer);

		return helper->InternalAddAfter(
			reinterpret_cast<::MultiListObjectClass *>(obj->MultiListObjectClassPointer.ToPointer()),
			reinterpret_cast<::MultiListObjectClass *>(existingListMember->MultiListObjectClassPointer.ToPointer()));
	}

	bool GenericMultiListClass::InternalRemove(IMultiListObjectClass ^obj)
	{
		if (obj == nullptr || obj->MultiListObjectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto helper = reinterpret_cast<GenericMultiListClassHelper *>(InternalGenericMultiListClassPointer);

		return helper->InternalRemove(
			reinterpret_cast<::MultiListObjectClass *>(obj->MultiListObjectClassPointer.ToPointer()));
	}

	IMultiListObjectClass ^GenericMultiListClass::InternalRemoveListHead()
	{
		auto helper = reinterpret_cast<GenericMultiListClassHelper *>(InternalGenericMultiListClassPointer);

		auto result = helper->InternalRemoveListHead();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew MultiListObjectClass(IntPtr(result));
		}
	}

	::GenericMultiListClass *GenericMultiListClass::InternalGenericMultiListClassPointer::get()
	{
		return reinterpret_cast<::GenericMultiListClass *>(Pointer.ToPointer());
	}

	IMultiListObjectClass ^GenericMultiListClass::ListHead::get()
	{
		auto helper = reinterpret_cast<GenericMultiListClassHelper *>(InternalGenericMultiListClassPointer);

		auto result = helper->InternalGetListHead();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew MultiListObjectClass(IntPtr(result));
		}
	}

	GenericMultiListIterator::GenericMultiListIterator(IGenericMultiListClass ^list)
	{
		if (list == nullptr || list->GenericMultiListClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		Pointer = IntPtr(Imports::CreateGenericMultiListIterator(
			reinterpret_cast<::GenericMultiListClass *>(list->GenericMultiListClassPointer.ToPointer())));
	}

	GenericMultiListIterator::GenericMultiListIterator(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IGenericMultiListIterator ^> ^GenericMultiListIterator::CreateGenericMultiListIterator(IGenericMultiListClass ^list)
	{
		return gcnew UnmanagedContainer<IGenericMultiListIterator ^>(gcnew GenericMultiListIterator(list));
	}

	bool GenericMultiListIterator::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IGenericMultiListIterator ^otherThis = dynamic_cast<IGenericMultiListIterator ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return GenericMultiListIteratorPointer.Equals(otherThis->GenericMultiListIteratorPointer);
	}

	void GenericMultiListIterator::First(IGenericMultiListClass ^list)
	{
		if (list == nullptr || list->GenericMultiListClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		InternalGenericMultiListIteratorPointer->First(
			reinterpret_cast<::GenericMultiListClass *>(list->GenericMultiListClassPointer.ToPointer()));
	}

	void GenericMultiListIterator::First()
	{
		InternalGenericMultiListIteratorPointer->First();
	}

	void GenericMultiListIterator::Next()
	{
		InternalGenericMultiListIteratorPointer->Next();
	}

	void GenericMultiListIterator::Prev()
	{
		InternalGenericMultiListIteratorPointer->Prev();
	}

	IntPtr GenericMultiListIterator::GenericMultiListIteratorPointer::get()
	{
		return IntPtr(InternalGenericMultiListIteratorPointer);
	}

	bool GenericMultiListIterator::IsDone::get()
	{
		return InternalGenericMultiListIteratorPointer->Is_Done();
	}

	bool GenericMultiListIterator::InternalDestroyPointer()
	{
		Imports::DestroyGenericMultiListIterator(InternalGenericMultiListIteratorPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::GenericMultiListIterator *GenericMultiListIterator::InternalGenericMultiListIteratorPointer::get()
	{
		return reinterpret_cast<::GenericMultiListIterator *>(Pointer.ToPointer());
	}

	IMultiListObjectClass ^GenericMultiListIterator::CurrentObject::get()
	{
		auto helper = reinterpret_cast<GenericMultiListIteratorHelper *>(InternalGenericMultiListIteratorPointer);

		auto result = helper->GetCurrentObject();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew MultiListObjectClass(IntPtr(result));
		}
	}

	IGenericMultiListClass ^GenericMultiListIterator::List::get()
	{
		auto helper = reinterpret_cast<GenericMultiListIteratorHelper *>(InternalGenericMultiListIteratorPointer);

		auto result = helper->GetList();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew GenericMultiListClass(IntPtr(const_cast<::GenericMultiListClass *>(result)));
		}
	}

	IMultiListNodeClass ^GenericMultiListIterator::CurNode::get()
	{
		auto helper = reinterpret_cast<GenericMultiListIteratorHelper *>(InternalGenericMultiListIteratorPointer);
		
		auto result = helper->GetCurNode();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew MultiListNodeClass(IntPtr(const_cast<::MultiListNodeClass *>(result)));
		}
	}
}