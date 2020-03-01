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
#include "MBaseGameObjSList.h"

#include "Imports.h"
#include "MBaseGameObj.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	BaseGameObjSLNode::BaseGameObjSLNode(IntPtr pointer)
		: SLNode<IBaseGameObj ^>(pointer)
	{

	}

	void BaseGameObjSLNode::SetNext(ISLNode<IBaseGameObj ^> ^next)
	{
		if (next == nullptr || next->Pointer.ToPointer() == nullptr)
		{
			InternalBaseGameObjSLNodePointer->Set_Next(nullptr);
		}
		else
		{
			InternalBaseGameObjSLNodePointer->Set_Next(reinterpret_cast<::SLNode<::BaseGameObj> *>(next->Pointer.ToPointer()));
		}
	}

	IntPtr BaseGameObjSLNode::BaseGameObjSLNodePointer::get()
	{
		return IntPtr(InternalBaseGameObjSLNodePointer);
	}

	ISLNode<IBaseGameObj ^> ^BaseGameObjSLNode::Next::get()
	{
		auto result = InternalBaseGameObjSLNodePointer->Next();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BaseGameObjSLNode(IntPtr(result));
		}
	}

	IBaseGameObj ^BaseGameObjSLNode::Data::get()
	{
		auto result = InternalBaseGameObjSLNodePointer->Data();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return BaseGameObj::CreateBaseGameObjWrapper(result);
		}
	}

	bool BaseGameObjSLNode::InternalDestroyPointer()
	{
		Imports::DestroyBaseGameObjSLNode(InternalBaseGameObjSLNodePointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::AutoPoolClass<::GenericSLNode, 256> *BaseGameObjSLNode::InternalAutoPoolClassPointer::get()
	{
		return InternalBaseGameObjSLNodePointer;
	}

	::GenericSLNode *BaseGameObjSLNode::InternalGenericSLNodePointer::get()
	{
		return InternalBaseGameObjSLNodePointer;
	}

	::SLNode<::BaseGameObj> *BaseGameObjSLNode::InternalBaseGameObjSLNodePointer::get()
	{
		return reinterpret_cast<::SLNode<::BaseGameObj> *>(Pointer.ToPointer());
	}

	BaseGameObjSList::BaseGameObjSList()
		: SList<IBaseGameObj ^>(IntPtr(Imports::CreateBaseGameObjSList()))
	{

	}

	BaseGameObjSList::BaseGameObjSList(IntPtr pointer)
		: SList<IBaseGameObj ^>(pointer)
	{

	}

	IUnmanagedContainer<ISList<IBaseGameObj ^> ^> ^BaseGameObjSList::CreateBaseGameObjSList()
	{
		return gcnew UnmanagedContainer<ISList<IBaseGameObj ^> ^>(gcnew BaseGameObjSList());
	}

	bool BaseGameObjSList::AddHead(IBaseGameObj ^data)
	{
		if (data == nullptr || data->BaseGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalBaseGameObjSListPointer->Add_Head(reinterpret_cast<::BaseGameObj *>(data->BaseGameObjPointer.ToPointer()));
	}

	bool BaseGameObjSList::AddHead(ISList<IBaseGameObj ^> ^list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		return InternalBaseGameObjSListPointer->Add_Head(*reinterpret_cast<::SList<::BaseGameObj> *>(list->Pointer.ToPointer()));
	}

	bool BaseGameObjSList::AddTail(IBaseGameObj ^data)
	{
		if (data == nullptr || data->BaseGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalBaseGameObjSListPointer->Add_Tail(reinterpret_cast<::BaseGameObj *>(data->BaseGameObjPointer.ToPointer()));
	}

	bool BaseGameObjSList::AddTail(ISList<IBaseGameObj ^> ^list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		return InternalBaseGameObjSListPointer->Add_Tail(*reinterpret_cast<::SList<::BaseGameObj> *>(list->Pointer.ToPointer()));
	}

	IBaseGameObj ^BaseGameObjSList::RemoveHead()
	{
		auto result = InternalBaseGameObjSListPointer->Remove_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return BaseGameObj::CreateBaseGameObjWrapper(result);
		}
	}

	IBaseGameObj ^BaseGameObjSList::RemoveTail()
	{
		auto result = InternalBaseGameObjSListPointer->Remove_Tail();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return BaseGameObj::CreateBaseGameObjWrapper(result);
		}
	}

	bool BaseGameObjSList::Remove(IBaseGameObj ^data)
	{
		if (data == nullptr || data->BaseGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalBaseGameObjSListPointer->Remove(reinterpret_cast<::BaseGameObj *>(data->BaseGameObjPointer.ToPointer()));
	}

	void BaseGameObjSList::RemoveAll()
	{
		InternalBaseGameObjSListPointer->Remove_All();
	}

	bool BaseGameObjSList::InsertBefore(IBaseGameObj ^newNode, IBaseGameObj ^oldNode)
	{
		if (newNode == nullptr || newNode->BaseGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("newNode");
		}
		else if (oldNode == nullptr || oldNode->BaseGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("oldNode");
		}

		return InternalBaseGameObjSListPointer->Insert_Before(
			reinterpret_cast<::BaseGameObj *>(newNode->BaseGameObjPointer.ToPointer()),
			reinterpret_cast<::BaseGameObj *>(oldNode->BaseGameObjPointer.ToPointer()));
	}

	bool BaseGameObjSList::InsertAfter(IBaseGameObj ^newNode, IBaseGameObj ^oldNode)
	{
		if (newNode == nullptr || newNode->BaseGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("newNode");
		}
		else if (oldNode == nullptr || oldNode->BaseGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("oldNode");
		}

		return InternalBaseGameObjSListPointer->Insert_After(
			reinterpret_cast<::BaseGameObj *>(newNode->BaseGameObjPointer.ToPointer()),
			reinterpret_cast<::BaseGameObj *>(oldNode->BaseGameObjPointer.ToPointer()));
	}

	ISLNode<IBaseGameObj ^> ^BaseGameObjSList::FindNode(IBaseGameObj ^data)
	{
		if (data == nullptr || data->BaseGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		auto result = InternalBaseGameObjSListPointer->Find_Node(reinterpret_cast<::BaseGameObj *>(data->BaseGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BaseGameObjSLNode(IntPtr(result));
		}
	}

	void BaseGameObjSList::InsertBefore(IBaseGameObj ^data, ISLNode<IBaseGameObj ^> ^node)
	{
		if (data == nullptr || data->BaseGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}
		else if (node == nullptr || node->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}

		InternalBaseGameObjSListPointer->insertBefore(
			reinterpret_cast<::BaseGameObj *>(data->BaseGameObjPointer.ToPointer()),
			*reinterpret_cast<::SLNode<::BaseGameObj> *>(node->Pointer.ToPointer()));
	}

	void BaseGameObjSList::InsertAfter(IBaseGameObj ^data, ISLNode<IBaseGameObj ^> ^node)
	{
		if (data == nullptr || data->BaseGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}
		else if (node == nullptr || node->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}

		InternalBaseGameObjSListPointer->insertAfter(
			reinterpret_cast<::BaseGameObj *>(data->BaseGameObjPointer.ToPointer()),
			*reinterpret_cast<::SLNode<::BaseGameObj> *>(node->Pointer.ToPointer()));
	}

	IntPtr BaseGameObjSList::BaseGameObjSListPointer::get()
	{
		return IntPtr(InternalBaseGameObjSListPointer);
	}

	bool BaseGameObjSList::IsEmpty::get()
	{
		return InternalBaseGameObjSListPointer->Is_Empty();
	}

	ISLNode<IBaseGameObj ^> ^BaseGameObjSList::Head::get()
	{
		auto result = InternalBaseGameObjSListPointer->Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BaseGameObjSLNode(IntPtr(result));
		}
	}

	ISLNode<IBaseGameObj ^> ^BaseGameObjSList::Tail::get()
	{
		auto result = InternalBaseGameObjSListPointer->Tail();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BaseGameObjSLNode(IntPtr(result));
		}
	}

	int BaseGameObjSList::Count::get()
	{
		return static_cast<int>(InternalBaseGameObjSListPointer->Get_Count());
	}

	bool BaseGameObjSList::InternalDestroyPointer()
	{
		Imports::DestroyBaseGameObjSList(InternalBaseGameObjSListPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::SList<::BaseGameObj> *BaseGameObjSList::InternalBaseGameObjSListPointer::get()
	{
		return reinterpret_cast<::SList<::BaseGameObj> *>(Pointer.ToPointer());
	}
}