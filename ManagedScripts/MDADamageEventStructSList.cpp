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
#include "MDADamageEventStructSList.h"

#include "Imports.h"
#include "Mda_damagelog.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	DADamageEventStructSLNode::DADamageEventStructSLNode(IntPtr pointer)
		: SLNode<IDADamageEventStruct^>(pointer)
	{

	}

	void DADamageEventStructSLNode::SetNext(ISLNode<IDADamageEventStruct^>^ next)
	{
		if (next == nullptr || next->Pointer.ToPointer() == nullptr)
		{
			InternalDADamageEventStructSLNodePointer->Set_Next(nullptr);
		}
		else
		{
			InternalDADamageEventStructSLNodePointer->Set_Next(reinterpret_cast<::SLNode<::DADamageEventStruct>*>(next->Pointer.ToPointer()));
		}
	}

	IntPtr DADamageEventStructSLNode::DADamageEventStructSLNodePointer::get()
	{
		return IntPtr(InternalDADamageEventStructSLNodePointer);
	}

	ISLNode<IDADamageEventStruct^>^ DADamageEventStructSLNode::Next::get()
	{
		auto result = InternalDADamageEventStructSLNodePointer->Next();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DADamageEventStructSLNode(IntPtr(result));
		}
	}

	IDADamageEventStruct^ DADamageEventStructSLNode::Data::get()
	{
		auto result = InternalDADamageEventStructSLNodePointer->Data();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DADamageEventStruct(IntPtr(result));
		}
	}

	bool DADamageEventStructSLNode::InternalDestroyPointer()
	{
		Imports::DestroyDADamageEventStructSLNode(InternalDADamageEventStructSLNodePointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::AutoPoolClass<::GenericSLNode, 256>* DADamageEventStructSLNode::InternalAutoPoolClassPointer::get()
	{
		return InternalDADamageEventStructSLNodePointer;
	}

	::GenericSLNode* DADamageEventStructSLNode::InternalGenericSLNodePointer::get()
	{
		return InternalDADamageEventStructSLNodePointer;
	}

	::SLNode<::DADamageEventStruct>* DADamageEventStructSLNode::InternalDADamageEventStructSLNodePointer::get()
	{
		return reinterpret_cast<::SLNode<::DADamageEventStruct>*>(Pointer.ToPointer());
	}

	DADamageEventStructSList::DADamageEventStructSList()
		: SList<IDADamageEventStruct^>(IntPtr(Imports::CreateDADamageEventStructSList()))
	{

	}

	DADamageEventStructSList::DADamageEventStructSList(IntPtr pointer)
		: SList<IDADamageEventStruct^>(pointer)
	{

	}

	IUnmanagedContainer<ISList<IDADamageEventStruct^>^>^ DADamageEventStructSList::CreateDADamageEventStructSList()
	{
		return gcnew UnmanagedContainer<ISList<IDADamageEventStruct^>^>(gcnew DADamageEventStructSList());
	}

	bool DADamageEventStructSList::AddHead(IDADamageEventStruct^ data)
	{
		if (data == nullptr || data->DADamageEventStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalDADamageEventStructSListPointer->Add_Head(reinterpret_cast<::DADamageEventStruct*>(data->DADamageEventStructPointer.ToPointer()));
	}

	bool DADamageEventStructSList::AddHead(ISList<IDADamageEventStruct^>^ list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		return InternalDADamageEventStructSListPointer->Add_Head(*reinterpret_cast<::SList<::DADamageEventStruct>*>(list->Pointer.ToPointer()));
	}

	bool DADamageEventStructSList::AddTail(IDADamageEventStruct^ data)
	{
		if (data == nullptr || data->DADamageEventStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalDADamageEventStructSListPointer->Add_Tail(reinterpret_cast<::DADamageEventStruct*>(data->DADamageEventStructPointer.ToPointer()));
	}

	bool DADamageEventStructSList::AddTail(ISList<IDADamageEventStruct^>^ list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		return InternalDADamageEventStructSListPointer->Add_Tail(*reinterpret_cast<::SList<::DADamageEventStruct>*>(list->Pointer.ToPointer()));
	}

	IDADamageEventStruct^ DADamageEventStructSList::RemoveHead()
	{
		auto result = InternalDADamageEventStructSListPointer->Remove_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DADamageEventStruct(IntPtr(result));
		}
	}

	IDADamageEventStruct^ DADamageEventStructSList::RemoveTail()
	{
		auto result = InternalDADamageEventStructSListPointer->Remove_Tail();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DADamageEventStruct(IntPtr(result));
		}
	}

	bool DADamageEventStructSList::Remove(IDADamageEventStruct^ data)
	{
		if (data == nullptr || data->DADamageEventStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalDADamageEventStructSListPointer->Remove(reinterpret_cast<::DADamageEventStruct*>(data->DADamageEventStructPointer.ToPointer()));
	}

	void DADamageEventStructSList::RemoveAll()
	{
		InternalDADamageEventStructSListPointer->Remove_All();
	}

	bool DADamageEventStructSList::InsertBefore(IDADamageEventStruct^ newNode, IDADamageEventStruct^ oldNode)
	{
		if (newNode == nullptr || newNode->DADamageEventStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("newNode");
		}
		else if (oldNode == nullptr || oldNode->DADamageEventStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("oldNode");
		}

		return InternalDADamageEventStructSListPointer->Insert_Before(
			reinterpret_cast<::DADamageEventStruct*>(newNode->DADamageEventStructPointer.ToPointer()),
			reinterpret_cast<::DADamageEventStruct*>(oldNode->DADamageEventStructPointer.ToPointer()));
	}

	bool DADamageEventStructSList::InsertAfter(IDADamageEventStruct^ newNode, IDADamageEventStruct^ oldNode)
	{
		if (newNode == nullptr || newNode->DADamageEventStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("newNode");
		}
		else if (oldNode == nullptr || oldNode->DADamageEventStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("oldNode");
		}

		return InternalDADamageEventStructSListPointer->Insert_After(
			reinterpret_cast<::DADamageEventStruct*>(newNode->DADamageEventStructPointer.ToPointer()),
			reinterpret_cast<::DADamageEventStruct*>(oldNode->DADamageEventStructPointer.ToPointer()));
	}

	ISLNode<IDADamageEventStruct^>^ DADamageEventStructSList::FindNode(IDADamageEventStruct^ data)
	{
		if (data == nullptr || data->DADamageEventStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		auto result = InternalDADamageEventStructSListPointer->Find_Node(reinterpret_cast<::DADamageEventStruct*>(data->DADamageEventStructPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DADamageEventStructSLNode(IntPtr(result));
		}
	}

	void DADamageEventStructSList::InsertBefore(IDADamageEventStruct^ data, ISLNode<IDADamageEventStruct^>^ node)
	{
		if (data == nullptr || data->DADamageEventStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}
		else if (node == nullptr || node->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}

		InternalDADamageEventStructSListPointer->insertBefore(
			reinterpret_cast<::DADamageEventStruct*>(data->DADamageEventStructPointer.ToPointer()),
			*reinterpret_cast<::SLNode<::DADamageEventStruct>*>(node->Pointer.ToPointer()));
	}

	void DADamageEventStructSList::InsertAfter(IDADamageEventStruct^ data, ISLNode<IDADamageEventStruct^>^ node)
	{
		if (data == nullptr || data->DADamageEventStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}
		else if (node == nullptr || node->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}

		InternalDADamageEventStructSListPointer->insertAfter(
			reinterpret_cast<::DADamageEventStruct*>(data->DADamageEventStructPointer.ToPointer()),
			*reinterpret_cast<::SLNode<::DADamageEventStruct>*>(node->Pointer.ToPointer()));
	}

	IntPtr DADamageEventStructSList::DADamageEventStructSListPointer::get()
	{
		return IntPtr(InternalDADamageEventStructSListPointer);
	}

	bool DADamageEventStructSList::IsEmpty::get()
	{
		return InternalDADamageEventStructSListPointer->Is_Empty();
	}

	ISLNode<IDADamageEventStruct^>^ DADamageEventStructSList::Head::get()
	{
		auto result = InternalDADamageEventStructSListPointer->Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DADamageEventStructSLNode(IntPtr(result));
		}
	}

	ISLNode<IDADamageEventStruct^>^ DADamageEventStructSList::Tail::get()
	{
		auto result = InternalDADamageEventStructSListPointer->Tail();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DADamageEventStructSLNode(IntPtr(result));
		}
	}

	int DADamageEventStructSList::Count::get()
	{
		return static_cast<int>(InternalDADamageEventStructSListPointer->Get_Count());
	}

	bool DADamageEventStructSList::InternalDestroyPointer()
	{
		Imports::DestroyDADamageEventStructSList(InternalDADamageEventStructSListPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::SList<::DADamageEventStruct>* DADamageEventStructSList::InternalDADamageEventStructSListPointer::get()
	{
		return reinterpret_cast<::SList<::DADamageEventStruct>*>(Pointer.ToPointer());
	}
}