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
#include "MBeaconGameObjSList.h"

#include "Imports.h"
#include "MBeaconGameObj.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	BeaconGameObjSLNode::BeaconGameObjSLNode(IntPtr pointer)
		: SLNode<IBeaconGameObj ^>(pointer)
	{

	}

	void BeaconGameObjSLNode::SetNext(ISLNode<IBeaconGameObj ^> ^next)
	{
		if (next == nullptr || next->Pointer.ToPointer() == nullptr)
		{
			InternalBeaconGameObjSLNodePointer->Set_Next(nullptr);
		}
		else
		{
			InternalBeaconGameObjSLNodePointer->Set_Next(reinterpret_cast<::SLNode<::BeaconGameObj> *>(next->Pointer.ToPointer()));
		}
	}

	IntPtr BeaconGameObjSLNode::BeaconGameObjSLNodePointer::get()
	{
		return IntPtr(InternalBeaconGameObjSLNodePointer);
	}

	ISLNode<IBeaconGameObj ^> ^BeaconGameObjSLNode::Next::get()
	{
		auto result = InternalBeaconGameObjSLNodePointer->Next();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BeaconGameObjSLNode(IntPtr(result));
		}
	}

	IBeaconGameObj ^BeaconGameObjSLNode::Data::get()
	{
		auto result = InternalBeaconGameObjSLNodePointer->Data();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IBeaconGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	bool BeaconGameObjSLNode::InternalDestroyPointer()
	{
		Imports::DestroyBeaconGameObjSLNode(InternalBeaconGameObjSLNodePointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::AutoPoolClass<::GenericSLNode, 256> *BeaconGameObjSLNode::InternalAutoPoolClassPointer::get()
	{
		return InternalBeaconGameObjSLNodePointer;
	}

	::GenericSLNode *BeaconGameObjSLNode::InternalGenericSLNodePointer::get()
	{
		return InternalBeaconGameObjSLNodePointer;
	}

	::SLNode<::BeaconGameObj> *BeaconGameObjSLNode::InternalBeaconGameObjSLNodePointer::get()
	{
		return reinterpret_cast<::SLNode<::BeaconGameObj> *>(Pointer.ToPointer());
	}

	BeaconGameObjSList::BeaconGameObjSList()
		: SList<IBeaconGameObj ^>(IntPtr(Imports::CreateBeaconGameObjSList()))
	{

	}

	BeaconGameObjSList::BeaconGameObjSList(IntPtr pointer)
		: SList<IBeaconGameObj ^>(pointer)
	{

	}

	IUnmanagedContainer<ISList<IBeaconGameObj ^> ^> ^BeaconGameObjSList::CreateBeaconGameObjSList()
	{
		return gcnew UnmanagedContainer<ISList<IBeaconGameObj ^> ^>(gcnew BeaconGameObjSList());
	}

	bool BeaconGameObjSList::AddHead(IBeaconGameObj ^data)
	{
		if (data == nullptr || data->BeaconGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalBeaconGameObjSListPointer->Add_Head(reinterpret_cast<::BeaconGameObj *>(data->BeaconGameObjPointer.ToPointer()));
	}

	bool BeaconGameObjSList::AddHead(ISList<IBeaconGameObj ^> ^list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		return InternalBeaconGameObjSListPointer->Add_Head(*reinterpret_cast<::SList<::BeaconGameObj> *>(list->Pointer.ToPointer()));
	}

	bool BeaconGameObjSList::AddTail(IBeaconGameObj ^data)
	{
		if (data == nullptr || data->BeaconGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalBeaconGameObjSListPointer->Add_Tail(reinterpret_cast<::BeaconGameObj *>(data->BeaconGameObjPointer.ToPointer()));
	}

	bool BeaconGameObjSList::AddTail(ISList<IBeaconGameObj ^> ^list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		return InternalBeaconGameObjSListPointer->Add_Tail(*reinterpret_cast<::SList<::BeaconGameObj> *>(list->Pointer.ToPointer()));
	}

	IBeaconGameObj ^BeaconGameObjSList::RemoveHead()
	{
		auto result = InternalBeaconGameObjSListPointer->Remove_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IBeaconGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IBeaconGameObj ^BeaconGameObjSList::RemoveTail()
	{
		auto result = InternalBeaconGameObjSListPointer->Remove_Tail();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IBeaconGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	bool BeaconGameObjSList::Remove(IBeaconGameObj ^data)
	{
		if (data == nullptr || data->BeaconGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalBeaconGameObjSListPointer->Remove(reinterpret_cast<::BeaconGameObj *>(data->BeaconGameObjPointer.ToPointer()));
	}

	void BeaconGameObjSList::RemoveAll()
	{
		InternalBeaconGameObjSListPointer->Remove_All();
	}

	bool BeaconGameObjSList::InsertBefore(IBeaconGameObj ^newNode, IBeaconGameObj ^oldNode)
	{
		if (newNode == nullptr || newNode->BeaconGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("newNode");
		}
		else if (oldNode == nullptr || oldNode->BeaconGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("oldNode");
		}

		return InternalBeaconGameObjSListPointer->Insert_Before(
			reinterpret_cast<::BeaconGameObj *>(newNode->BeaconGameObjPointer.ToPointer()),
			reinterpret_cast<::BeaconGameObj *>(oldNode->BeaconGameObjPointer.ToPointer()));
	}

	bool BeaconGameObjSList::InsertAfter(IBeaconGameObj ^newNode, IBeaconGameObj ^oldNode)
	{
		if (newNode == nullptr || newNode->BeaconGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("newNode");
		}
		else if (oldNode == nullptr || oldNode->BeaconGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("oldNode");
		}

		return InternalBeaconGameObjSListPointer->Insert_After(
			reinterpret_cast<::BeaconGameObj *>(newNode->BeaconGameObjPointer.ToPointer()),
			reinterpret_cast<::BeaconGameObj *>(oldNode->BeaconGameObjPointer.ToPointer()));
	}

	ISLNode<IBeaconGameObj ^> ^BeaconGameObjSList::FindNode(IBeaconGameObj ^data)
	{
		if (data == nullptr || data->BeaconGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		auto result = InternalBeaconGameObjSListPointer->Find_Node(reinterpret_cast<::BeaconGameObj *>(data->BeaconGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BeaconGameObjSLNode(IntPtr(result));
		}
	}

	void BeaconGameObjSList::InsertBefore(IBeaconGameObj ^data, ISLNode<IBeaconGameObj ^> ^node)
	{
		if (data == nullptr || data->BeaconGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}
		else if (node == nullptr || node->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}

		InternalBeaconGameObjSListPointer->insertBefore(
			reinterpret_cast<::BeaconGameObj *>(data->BeaconGameObjPointer.ToPointer()),
			*reinterpret_cast<::SLNode<::BeaconGameObj> *>(node->Pointer.ToPointer()));
	}

	void BeaconGameObjSList::InsertAfter(IBeaconGameObj ^data, ISLNode<IBeaconGameObj ^> ^node)
	{
		if (data == nullptr || data->BeaconGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}
		else if (node == nullptr || node->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}

		InternalBeaconGameObjSListPointer->insertAfter(
			reinterpret_cast<::BeaconGameObj *>(data->BeaconGameObjPointer.ToPointer()),
			*reinterpret_cast<::SLNode<::BeaconGameObj> *>(node->Pointer.ToPointer()));
	}

	IntPtr BeaconGameObjSList::BeaconGameObjSListPointer::get()
	{
		return IntPtr(InternalBeaconGameObjSListPointer);
	}

	bool BeaconGameObjSList::IsEmpty::get()
	{
		return InternalBeaconGameObjSListPointer->Is_Empty();
	}

	ISLNode<IBeaconGameObj ^> ^BeaconGameObjSList::Head::get()
	{
		auto result = InternalBeaconGameObjSListPointer->Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BeaconGameObjSLNode(IntPtr(result));
		}
	}

	ISLNode<IBeaconGameObj ^> ^BeaconGameObjSList::Tail::get()
	{
		auto result = InternalBeaconGameObjSListPointer->Tail();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BeaconGameObjSLNode(IntPtr(result));
		}
	}

	int BeaconGameObjSList::Count::get()
	{
		return static_cast<int>(InternalBeaconGameObjSListPointer->Get_Count());
	}

	bool BeaconGameObjSList::InternalDestroyPointer()
	{
		Imports::DestroyBeaconGameObjSList(InternalBeaconGameObjSListPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::SList<::BeaconGameObj> *BeaconGameObjSList::InternalBeaconGameObjSListPointer::get()
	{
		return reinterpret_cast<::SList<::BeaconGameObj> *>(Pointer.ToPointer());
	}
}