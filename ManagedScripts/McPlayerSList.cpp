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
#include "McPlayerSList.h"

#include "Imports.h"
#include "McPlayer.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	cPlayerSLNode::cPlayerSLNode(IntPtr pointer)
		: SLNode<IcPlayer ^>(pointer)
	{

	}

	void cPlayerSLNode::SetNext(ISLNode<IcPlayer ^> ^next)
	{
		if (next == nullptr || next->Pointer.ToPointer() == nullptr)
		{
			InternalcPlayerSLNodePointer->Set_Next(nullptr);
		}
		else
		{
			InternalcPlayerSLNodePointer->Set_Next(reinterpret_cast<::SLNode<::cPlayer> *>(next->Pointer.ToPointer()));
		}
	}

	IntPtr cPlayerSLNode::cPlayerSLNodePointer::get()
	{
		return IntPtr(InternalcPlayerSLNodePointer);
	}

	ISLNode<IcPlayer ^> ^cPlayerSLNode::Next::get()
	{
		auto result = InternalcPlayerSLNodePointer->Next();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayerSLNode(IntPtr(result));
		}
	}

	IcPlayer ^cPlayerSLNode::Data::get()
	{
		auto result = InternalcPlayerSLNodePointer->Data();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	bool cPlayerSLNode::InternalDestroyPointer()
	{
		Imports::DestroycPlayerSLNode(InternalcPlayerSLNodePointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::AutoPoolClass<::GenericSLNode, 256> *cPlayerSLNode::InternalAutoPoolClassPointer::get()
	{
		return InternalcPlayerSLNodePointer;
	}

	::GenericSLNode *cPlayerSLNode::InternalGenericSLNodePointer::get()
	{
		return InternalcPlayerSLNodePointer;
	}

	::SLNode<::cPlayer> *cPlayerSLNode::InternalcPlayerSLNodePointer::get()
	{
		return reinterpret_cast<::SLNode<::cPlayer> *>(Pointer.ToPointer());
	}

	cPlayerSList::cPlayerSList()
		: SList<IcPlayer ^>(IntPtr(Imports::CreatecPlayerSList()))
	{

	}

	cPlayerSList::cPlayerSList(IntPtr pointer)
		: SList<IcPlayer ^>(pointer)
	{

	}

	IUnmanagedContainer<ISList<IcPlayer ^> ^> ^cPlayerSList::CreatecPlayerSList()
	{
		return gcnew UnmanagedContainer<ISList<IcPlayer ^> ^>(gcnew cPlayerSList());
	}

	bool cPlayerSList::AddHead(IcPlayer ^data)
	{
		if (data == nullptr || data->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalcPlayerSListPointer->Add_Head(reinterpret_cast<::cPlayer *>(data->cPlayerPointer.ToPointer()));
	}

	bool cPlayerSList::AddHead(ISList<IcPlayer ^> ^list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		return InternalcPlayerSListPointer->Add_Head(*reinterpret_cast<::SList<::cPlayer> *>(list->Pointer.ToPointer()));
	}

	bool cPlayerSList::AddTail(IcPlayer ^data)
	{
		if (data == nullptr || data->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalcPlayerSListPointer->Add_Tail(reinterpret_cast<::cPlayer *>(data->cPlayerPointer.ToPointer()));
	}

	bool cPlayerSList::AddTail(ISList<IcPlayer ^> ^list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		return InternalcPlayerSListPointer->Add_Tail(*reinterpret_cast<::SList<::cPlayer> *>(list->Pointer.ToPointer()));
	}

	IcPlayer ^cPlayerSList::RemoveHead()
	{
		auto result = InternalcPlayerSListPointer->Remove_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	IcPlayer ^cPlayerSList::RemoveTail()
	{
		auto result = InternalcPlayerSListPointer->Remove_Tail();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	bool cPlayerSList::Remove(IcPlayer ^data)
	{
		if (data == nullptr || data->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalcPlayerSListPointer->Remove(reinterpret_cast<::cPlayer *>(data->cPlayerPointer.ToPointer()));
	}

	void cPlayerSList::RemoveAll()
	{
		InternalcPlayerSListPointer->Remove_All();
	}

	bool cPlayerSList::InsertBefore(IcPlayer ^newNode, IcPlayer ^oldNode)
	{
		if (newNode == nullptr || newNode->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("newNode");
		}
		else if (oldNode == nullptr || oldNode->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("oldNode");
		}

		return InternalcPlayerSListPointer->Insert_Before(
			reinterpret_cast<::cPlayer *>(newNode->cPlayerPointer.ToPointer()),
			reinterpret_cast<::cPlayer *>(oldNode->cPlayerPointer.ToPointer()));
	}

	bool cPlayerSList::InsertAfter(IcPlayer ^newNode, IcPlayer ^oldNode)
	{
		if (newNode == nullptr || newNode->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("newNode");
		}
		else if (oldNode == nullptr || oldNode->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("oldNode");
		}

		return InternalcPlayerSListPointer->Insert_After(
			reinterpret_cast<::cPlayer *>(newNode->cPlayerPointer.ToPointer()),
			reinterpret_cast<::cPlayer *>(oldNode->cPlayerPointer.ToPointer()));
	}

	ISLNode<IcPlayer ^> ^cPlayerSList::FindNode(IcPlayer ^data)
	{
		if (data == nullptr || data->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		auto result = InternalcPlayerSListPointer->Find_Node(reinterpret_cast<::cPlayer *>(data->cPlayerPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayerSLNode(IntPtr(result));
		}
	}

	void cPlayerSList::InsertBefore(IcPlayer ^data, ISLNode<IcPlayer ^> ^node)
	{
		if (data == nullptr || data->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}
		else if (node == nullptr || node->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}

		InternalcPlayerSListPointer->insertBefore(
			reinterpret_cast<::cPlayer *>(data->cPlayerPointer.ToPointer()),
			*reinterpret_cast<::SLNode<::cPlayer> *>(node->Pointer.ToPointer()));
	}

	void cPlayerSList::InsertAfter(IcPlayer ^data, ISLNode<IcPlayer ^> ^node)
	{
		if (data == nullptr || data->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}
		else if (node == nullptr || node->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}

		InternalcPlayerSListPointer->insertAfter(
			reinterpret_cast<::cPlayer *>(data->cPlayerPointer.ToPointer()),
			*reinterpret_cast<::SLNode<::cPlayer> *>(node->Pointer.ToPointer()));
	}

	IntPtr cPlayerSList::cPlayerSListPointer::get()
	{
		return IntPtr(InternalcPlayerSListPointer);
	}

	bool cPlayerSList::IsEmpty::get()
	{
		return InternalcPlayerSListPointer->Is_Empty();
	}

	ISLNode<IcPlayer ^> ^cPlayerSList::Head::get()
	{
		auto result = InternalcPlayerSListPointer->Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayerSLNode(IntPtr(result));
		}
	}

	ISLNode<IcPlayer ^> ^cPlayerSList::Tail::get()
	{
		auto result = InternalcPlayerSListPointer->Tail();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayerSLNode(IntPtr(result));
		}
	}

	int cPlayerSList::Count::get()
	{
		return static_cast<int>(InternalcPlayerSListPointer->Get_Count());
	}

	bool cPlayerSList::InternalDestroyPointer()
	{
		Imports::DestroycPlayerSList(InternalcPlayerSListPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::SList<::cPlayer> *cPlayerSList::InternalcPlayerSListPointer::get()
	{
		return reinterpret_cast<::SList<::cPlayer> *>(Pointer.ToPointer());
	}
}