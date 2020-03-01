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
#include "MSoldierGameObjSList.h"

#include "Imports.h"
#include "MSoldierGameObj.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	SoldierGameObjSLNode::SoldierGameObjSLNode(IntPtr pointer)
		: SLNode<ISoldierGameObj ^>(pointer)
	{

	}

	void SoldierGameObjSLNode::SetNext(ISLNode<ISoldierGameObj ^> ^next)
	{
		if (next == nullptr || next->Pointer.ToPointer() == nullptr)
		{
			InternalSoldierGameObjSLNodePointer->Set_Next(nullptr);
		}
		else
		{
			InternalSoldierGameObjSLNodePointer->Set_Next(reinterpret_cast<::SLNode<::SoldierGameObj> *>(next->Pointer.ToPointer()));
		}
	}

	IntPtr SoldierGameObjSLNode::SoldierGameObjSLNodePointer::get()
	{
		return IntPtr(InternalSoldierGameObjSLNodePointer);
	}

	ISLNode<ISoldierGameObj ^> ^SoldierGameObjSLNode::Next::get()
	{
		auto result = InternalSoldierGameObjSLNodePointer->Next();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SoldierGameObjSLNode(IntPtr(result));
		}
	}

	ISoldierGameObj ^SoldierGameObjSLNode::Data::get()
	{
		auto result = InternalSoldierGameObjSLNodePointer->Data();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<ISoldierGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	bool SoldierGameObjSLNode::InternalDestroyPointer()
	{
		Imports::DestroySoldierGameObjSLNode(InternalSoldierGameObjSLNodePointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::AutoPoolClass<::GenericSLNode, 256> *SoldierGameObjSLNode::InternalAutoPoolClassPointer::get()
	{
		return InternalSoldierGameObjSLNodePointer;
	}

	::GenericSLNode *SoldierGameObjSLNode::InternalGenericSLNodePointer::get()
	{
		return InternalSoldierGameObjSLNodePointer;
	}

	::SLNode<::SoldierGameObj> *SoldierGameObjSLNode::InternalSoldierGameObjSLNodePointer::get()
	{
		return reinterpret_cast<::SLNode<::SoldierGameObj> *>(Pointer.ToPointer());
	}

	SoldierGameObjSList::SoldierGameObjSList()
		: SList<ISoldierGameObj ^>(IntPtr(Imports::CreateSoldierGameObjSList()))
	{

	}

	SoldierGameObjSList::SoldierGameObjSList(IntPtr pointer)
		: SList<ISoldierGameObj ^>(pointer)
	{

	}

	IUnmanagedContainer<ISList<ISoldierGameObj ^> ^> ^SoldierGameObjSList::CreateSoldierGameObjSList()
	{
		return gcnew UnmanagedContainer<ISList<ISoldierGameObj ^> ^>(gcnew SoldierGameObjSList());
	}

	bool SoldierGameObjSList::AddHead(ISoldierGameObj ^data)
	{
		if (data == nullptr || data->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalSoldierGameObjSListPointer->Add_Head(reinterpret_cast<::SoldierGameObj *>(data->SoldierGameObjPointer.ToPointer()));
	}

	bool SoldierGameObjSList::AddHead(ISList<ISoldierGameObj ^> ^list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		return InternalSoldierGameObjSListPointer->Add_Head(*reinterpret_cast<::SList<::SoldierGameObj> *>(list->Pointer.ToPointer()));
	}

	bool SoldierGameObjSList::AddTail(ISoldierGameObj ^data)
	{
		if (data == nullptr || data->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalSoldierGameObjSListPointer->Add_Tail(reinterpret_cast<::SoldierGameObj *>(data->SoldierGameObjPointer.ToPointer()));
	}

	bool SoldierGameObjSList::AddTail(ISList<ISoldierGameObj ^> ^list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		return InternalSoldierGameObjSListPointer->Add_Tail(*reinterpret_cast<::SList<::SoldierGameObj> *>(list->Pointer.ToPointer()));
	}

	ISoldierGameObj ^SoldierGameObjSList::RemoveHead()
	{
		auto result = InternalSoldierGameObjSListPointer->Remove_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<ISoldierGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	ISoldierGameObj ^SoldierGameObjSList::RemoveTail()
	{
		auto result = InternalSoldierGameObjSListPointer->Remove_Tail();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<ISoldierGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	bool SoldierGameObjSList::Remove(ISoldierGameObj ^data)
	{
		if (data == nullptr || data->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalSoldierGameObjSListPointer->Remove(reinterpret_cast<::SoldierGameObj *>(data->SoldierGameObjPointer.ToPointer()));
	}

	void SoldierGameObjSList::RemoveAll()
	{
		InternalSoldierGameObjSListPointer->Remove_All();
	}

	bool SoldierGameObjSList::InsertBefore(ISoldierGameObj ^newNode, ISoldierGameObj ^oldNode)
	{
		if (newNode == nullptr || newNode->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("newNode");
		}
		else if (oldNode == nullptr || oldNode->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("oldNode");
		}

		return InternalSoldierGameObjSListPointer->Insert_Before(
			reinterpret_cast<::SoldierGameObj *>(newNode->SoldierGameObjPointer.ToPointer()),
			reinterpret_cast<::SoldierGameObj *>(oldNode->SoldierGameObjPointer.ToPointer()));
	}

	bool SoldierGameObjSList::InsertAfter(ISoldierGameObj ^newNode, ISoldierGameObj ^oldNode)
	{
		if (newNode == nullptr || newNode->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("newNode");
		}
		else if (oldNode == nullptr || oldNode->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("oldNode");
		}

		return InternalSoldierGameObjSListPointer->Insert_After(
			reinterpret_cast<::SoldierGameObj *>(newNode->SoldierGameObjPointer.ToPointer()),
			reinterpret_cast<::SoldierGameObj *>(oldNode->SoldierGameObjPointer.ToPointer()));
	}

	ISLNode<ISoldierGameObj ^> ^SoldierGameObjSList::FindNode(ISoldierGameObj ^data)
	{
		if (data == nullptr || data->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		auto result = InternalSoldierGameObjSListPointer->Find_Node(reinterpret_cast<::SoldierGameObj *>(data->SoldierGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SoldierGameObjSLNode(IntPtr(result));
		}
	}

	void SoldierGameObjSList::InsertBefore(ISoldierGameObj ^data, ISLNode<ISoldierGameObj ^> ^node)
	{
		if (data == nullptr || data->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}
		else if (node == nullptr || node->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}

		InternalSoldierGameObjSListPointer->insertBefore(
			reinterpret_cast<::SoldierGameObj *>(data->SoldierGameObjPointer.ToPointer()),
			*reinterpret_cast<::SLNode<::SoldierGameObj> *>(node->Pointer.ToPointer()));
	}

	void SoldierGameObjSList::InsertAfter(ISoldierGameObj ^data, ISLNode<ISoldierGameObj ^> ^node)
	{
		if (data == nullptr || data->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}
		else if (node == nullptr || node->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}

		InternalSoldierGameObjSListPointer->insertAfter(
			reinterpret_cast<::SoldierGameObj *>(data->SoldierGameObjPointer.ToPointer()),
			*reinterpret_cast<::SLNode<::SoldierGameObj> *>(node->Pointer.ToPointer()));
	}

	IntPtr SoldierGameObjSList::SoldierGameObjSListPointer::get()
	{
		return IntPtr(InternalSoldierGameObjSListPointer);
	}

	bool SoldierGameObjSList::IsEmpty::get()
	{
		return InternalSoldierGameObjSListPointer->Is_Empty();
	}

	ISLNode<ISoldierGameObj ^> ^SoldierGameObjSList::Head::get()
	{
		auto result = InternalSoldierGameObjSListPointer->Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SoldierGameObjSLNode(IntPtr(result));
		}
	}

	ISLNode<ISoldierGameObj ^> ^SoldierGameObjSList::Tail::get()
	{
		auto result = InternalSoldierGameObjSListPointer->Tail();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SoldierGameObjSLNode(IntPtr(result));
		}
	}

	int SoldierGameObjSList::Count::get()
	{
		return static_cast<int>(InternalSoldierGameObjSListPointer->Get_Count());
	}

	bool SoldierGameObjSList::InternalDestroyPointer()
	{
		Imports::DestroySoldierGameObjSList(InternalSoldierGameObjSListPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::SList<::SoldierGameObj> *SoldierGameObjSList::InternalSoldierGameObjSListPointer::get()
	{
		return reinterpret_cast<::SList<::SoldierGameObj> *>(Pointer.ToPointer());
	}
}