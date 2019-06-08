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
#include "MSmartGameObjSList.h"

#include "Imports.h"
#include "MSmartGameObj.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	SmartGameObjSLNode::SmartGameObjSLNode(IntPtr pointer)
		: SLNode<ISmartGameObj ^>(pointer)
	{

	}

	void SmartGameObjSLNode::SetNext(ISLNode<ISmartGameObj ^> ^next)
	{
		if (next == nullptr || next->Pointer.ToPointer() == nullptr)
		{
			InternalSmartGameObjSLNodePointer->Set_Next(nullptr);
		}
		else
		{
			InternalSmartGameObjSLNodePointer->Set_Next(reinterpret_cast<::SLNode<::SmartGameObj> *>(next->Pointer.ToPointer()));
		}
	}

	IntPtr SmartGameObjSLNode::SmartGameObjSLNodePointer::get()
	{
		return IntPtr(InternalSmartGameObjSLNodePointer);
	}

	ISLNode<ISmartGameObj ^> ^SmartGameObjSLNode::Next::get()
	{
		auto result = InternalSmartGameObjSLNodePointer->Next();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SmartGameObjSLNode(IntPtr(result));
		}
	}

	ISmartGameObj ^SmartGameObjSLNode::Data::get()
	{
		auto result = InternalSmartGameObjSLNodePointer->Data();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SmartGameObj(IntPtr(result));
		}
	}

	bool SmartGameObjSLNode::InternalDestroyPointer()
	{
		Imports::DestroySmartGameObjSLNode(InternalSmartGameObjSLNodePointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::AutoPoolClass<::GenericSLNode, 256> *SmartGameObjSLNode::InternalAutoPoolClassPointer::get()
	{
		return InternalSmartGameObjSLNodePointer;
	}

	::GenericSLNode *SmartGameObjSLNode::InternalGenericSLNodePointer::get()
	{
		return InternalSmartGameObjSLNodePointer;
	}

	::SLNode<::SmartGameObj> *SmartGameObjSLNode::InternalSmartGameObjSLNodePointer::get()
	{
		return reinterpret_cast<::SLNode<::SmartGameObj> *>(Pointer.ToPointer());
	}

	SmartGameObjSList::SmartGameObjSList()
		: SList<ISmartGameObj ^>(IntPtr(Imports::CreateSmartGameObjSList()))
	{

	}

	SmartGameObjSList::SmartGameObjSList(IntPtr pointer)
		: SList<ISmartGameObj ^>(pointer)
	{

	}

	IUnmanagedContainer<ISList<ISmartGameObj ^> ^> ^SmartGameObjSList::CreateSmartGameObjSList()
	{
		return gcnew UnmanagedContainer<ISList<ISmartGameObj ^> ^>(gcnew SmartGameObjSList());
	}

	bool SmartGameObjSList::AddHead(ISmartGameObj ^data)
	{
		if (data == nullptr || data->SmartGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalSmartGameObjSListPointer->Add_Head(reinterpret_cast<::SmartGameObj *>(data->SmartGameObjPointer.ToPointer()));
	}

	bool SmartGameObjSList::AddHead(ISList<ISmartGameObj ^> ^list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		return InternalSmartGameObjSListPointer->Add_Head(*reinterpret_cast<::SList<::SmartGameObj> *>(list->Pointer.ToPointer()));
	}

	bool SmartGameObjSList::AddTail(ISmartGameObj ^data)
	{
		if (data == nullptr || data->SmartGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalSmartGameObjSListPointer->Add_Tail(reinterpret_cast<::SmartGameObj *>(data->SmartGameObjPointer.ToPointer()));
	}

	bool SmartGameObjSList::AddTail(ISList<ISmartGameObj ^> ^list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		return InternalSmartGameObjSListPointer->Add_Tail(*reinterpret_cast<::SList<::SmartGameObj> *>(list->Pointer.ToPointer()));
	}

	ISmartGameObj ^SmartGameObjSList::RemoveHead()
	{
		auto result = InternalSmartGameObjSListPointer->Remove_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SmartGameObj(IntPtr(result));
		}
	}

	ISmartGameObj ^SmartGameObjSList::RemoveTail()
	{
		auto result = InternalSmartGameObjSListPointer->Remove_Tail();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SmartGameObj(IntPtr(result));
		}
	}

	bool SmartGameObjSList::Remove(ISmartGameObj ^data)
	{
		if (data == nullptr || data->SmartGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalSmartGameObjSListPointer->Remove(reinterpret_cast<::SmartGameObj *>(data->SmartGameObjPointer.ToPointer()));
	}

	void SmartGameObjSList::RemoveAll()
	{
		InternalSmartGameObjSListPointer->Remove_All();
	}

	bool SmartGameObjSList::InsertBefore(ISmartGameObj ^newNode, ISmartGameObj ^oldNode)
	{
		if (newNode == nullptr || newNode->SmartGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("newNode");
		}
		else if (oldNode == nullptr || oldNode->SmartGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("oldNode");
		}

		return InternalSmartGameObjSListPointer->Insert_Before(
			reinterpret_cast<::SmartGameObj *>(newNode->SmartGameObjPointer.ToPointer()),
			reinterpret_cast<::SmartGameObj *>(oldNode->SmartGameObjPointer.ToPointer()));
	}

	bool SmartGameObjSList::InsertAfter(ISmartGameObj ^newNode, ISmartGameObj ^oldNode)
	{
		if (newNode == nullptr || newNode->SmartGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("newNode");
		}
		else if (oldNode == nullptr || oldNode->SmartGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("oldNode");
		}

		return InternalSmartGameObjSListPointer->Insert_After(
			reinterpret_cast<::SmartGameObj *>(newNode->SmartGameObjPointer.ToPointer()),
			reinterpret_cast<::SmartGameObj *>(oldNode->SmartGameObjPointer.ToPointer()));
	}

	ISLNode<ISmartGameObj ^> ^SmartGameObjSList::FindNode(ISmartGameObj ^data)
	{
		if (data == nullptr || data->SmartGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		auto result = InternalSmartGameObjSListPointer->Find_Node(reinterpret_cast<::SmartGameObj *>(data->SmartGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SmartGameObjSLNode(IntPtr(result));
		}
	}

	void SmartGameObjSList::InsertBefore(ISmartGameObj ^data, ISLNode<ISmartGameObj ^> ^node)
	{
		if (data == nullptr || data->SmartGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}
		else if (node == nullptr || node->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}

		InternalSmartGameObjSListPointer->insertBefore(
			reinterpret_cast<::SmartGameObj *>(data->SmartGameObjPointer.ToPointer()),
			*reinterpret_cast<::SLNode<::SmartGameObj> *>(node->Pointer.ToPointer()));
	}

	void SmartGameObjSList::InsertAfter(ISmartGameObj ^data, ISLNode<ISmartGameObj ^> ^node)
	{
		if (data == nullptr || data->SmartGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}
		else if (node == nullptr || node->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}

		InternalSmartGameObjSListPointer->insertAfter(
			reinterpret_cast<::SmartGameObj *>(data->SmartGameObjPointer.ToPointer()),
			*reinterpret_cast<::SLNode<::SmartGameObj> *>(node->Pointer.ToPointer()));
	}

	IntPtr SmartGameObjSList::SmartGameObjSListPointer::get()
	{
		return IntPtr(InternalSmartGameObjSListPointer);
	}

	bool SmartGameObjSList::IsEmpty::get()
	{
		return InternalSmartGameObjSListPointer->Is_Empty();
	}

	ISLNode<ISmartGameObj ^> ^SmartGameObjSList::Head::get()
	{
		auto result = InternalSmartGameObjSListPointer->Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SmartGameObjSLNode(IntPtr(result));
		}
	}

	ISLNode<ISmartGameObj ^> ^SmartGameObjSList::Tail::get()
	{
		auto result = InternalSmartGameObjSListPointer->Tail();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SmartGameObjSLNode(IntPtr(result));
		}
	}

	int SmartGameObjSList::Count::get()
	{
		return static_cast<int>(InternalSmartGameObjSListPointer->Get_Count());
	}

	bool SmartGameObjSList::InternalDestroyPointer()
	{
		Imports::DestroySmartGameObjSList(InternalSmartGameObjSListPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::SList<::SmartGameObj> *SmartGameObjSList::InternalSmartGameObjSListPointer::get()
	{
		return reinterpret_cast<::SList<::SmartGameObj> *>(Pointer.ToPointer());
	}
}