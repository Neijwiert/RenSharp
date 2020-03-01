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
#include "MC4GameObjSList.h"

#include "Imports.h"
#include "MC4GameObj.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	C4GameObjSLNode::C4GameObjSLNode(IntPtr pointer)
		: SLNode<IC4GameObj ^>(pointer)
	{

	}

	void C4GameObjSLNode::SetNext(ISLNode<IC4GameObj ^> ^next)
	{
		if (next == nullptr || next->Pointer.ToPointer() == nullptr)
		{
			InternalC4GameObjSLNodePointer->Set_Next(nullptr);
		}
		else
		{
			InternalC4GameObjSLNodePointer->Set_Next(reinterpret_cast<::SLNode<::C4GameObj> *>(next->Pointer.ToPointer()));
		}
	}

	IntPtr C4GameObjSLNode::C4GameObjSLNodePointer::get()
	{
		return IntPtr(InternalC4GameObjSLNodePointer);
	}

	ISLNode<IC4GameObj ^> ^C4GameObjSLNode::Next::get()
	{
		auto result = InternalC4GameObjSLNodePointer->Next();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew C4GameObjSLNode(IntPtr(result));
		}
	}

	IC4GameObj ^C4GameObjSLNode::Data::get()
	{
		auto result = InternalC4GameObjSLNodePointer->Data();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IC4GameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	bool C4GameObjSLNode::InternalDestroyPointer()
	{
		Imports::DestroyC4GameObjSLNode(InternalC4GameObjSLNodePointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::AutoPoolClass<::GenericSLNode, 256> *C4GameObjSLNode::InternalAutoPoolClassPointer::get()
	{
		return InternalC4GameObjSLNodePointer;
	}

	::GenericSLNode *C4GameObjSLNode::InternalGenericSLNodePointer::get()
	{
		return InternalC4GameObjSLNodePointer;
	}

	::SLNode<::C4GameObj> *C4GameObjSLNode::InternalC4GameObjSLNodePointer::get()
	{
		return reinterpret_cast<::SLNode<::C4GameObj> *>(Pointer.ToPointer());
	}

	C4GameObjSList::C4GameObjSList()
		: SList<IC4GameObj ^>(IntPtr(Imports::CreateC4GameObjSList()))
	{

	}

	C4GameObjSList::C4GameObjSList(IntPtr pointer)
		: SList<IC4GameObj ^>(pointer)
	{

	}

	IUnmanagedContainer<ISList<IC4GameObj ^> ^> ^C4GameObjSList::CreateC4GameObjSList()
	{
		return gcnew UnmanagedContainer<ISList<IC4GameObj ^> ^>(gcnew C4GameObjSList());
	}

	bool C4GameObjSList::AddHead(IC4GameObj ^data)
	{
		if (data == nullptr || data->C4GameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalC4GameObjSListPointer->Add_Head(reinterpret_cast<::C4GameObj *>(data->C4GameObjPointer.ToPointer()));
	}

	bool C4GameObjSList::AddHead(ISList<IC4GameObj ^> ^list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		return InternalC4GameObjSListPointer->Add_Head(*reinterpret_cast<::SList<::C4GameObj> *>(list->Pointer.ToPointer()));
	}

	bool C4GameObjSList::AddTail(IC4GameObj ^data)
	{
		if (data == nullptr || data->C4GameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalC4GameObjSListPointer->Add_Tail(reinterpret_cast<::C4GameObj *>(data->C4GameObjPointer.ToPointer()));
	}

	bool C4GameObjSList::AddTail(ISList<IC4GameObj ^> ^list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		return InternalC4GameObjSListPointer->Add_Tail(*reinterpret_cast<::SList<::C4GameObj> *>(list->Pointer.ToPointer()));
	}

	IC4GameObj ^C4GameObjSList::RemoveHead()
	{
		auto result = InternalC4GameObjSListPointer->Remove_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IC4GameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IC4GameObj ^C4GameObjSList::RemoveTail()
	{
		auto result = InternalC4GameObjSListPointer->Remove_Tail();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IC4GameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	bool C4GameObjSList::Remove(IC4GameObj ^data)
	{
		if (data == nullptr || data->C4GameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalC4GameObjSListPointer->Remove(reinterpret_cast<::C4GameObj *>(data->C4GameObjPointer.ToPointer()));
	}

	void C4GameObjSList::RemoveAll()
	{
		InternalC4GameObjSListPointer->Remove_All();
	}

	bool C4GameObjSList::InsertBefore(IC4GameObj ^newNode, IC4GameObj ^oldNode)
	{
		if (newNode == nullptr || newNode->C4GameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("newNode");
		}
		else if (oldNode == nullptr || oldNode->C4GameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("oldNode");
		}

		return InternalC4GameObjSListPointer->Insert_Before(
			reinterpret_cast<::C4GameObj *>(newNode->C4GameObjPointer.ToPointer()),
			reinterpret_cast<::C4GameObj *>(oldNode->C4GameObjPointer.ToPointer()));
	}

	bool C4GameObjSList::InsertAfter(IC4GameObj ^newNode, IC4GameObj ^oldNode)
	{
		if (newNode == nullptr || newNode->C4GameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("newNode");
		}
		else if (oldNode == nullptr || oldNode->C4GameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("oldNode");
		}

		return InternalC4GameObjSListPointer->Insert_After(
			reinterpret_cast<::C4GameObj *>(newNode->C4GameObjPointer.ToPointer()),
			reinterpret_cast<::C4GameObj *>(oldNode->C4GameObjPointer.ToPointer()));
	}

	ISLNode<IC4GameObj ^> ^C4GameObjSList::FindNode(IC4GameObj ^data)
	{
		if (data == nullptr || data->C4GameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		auto result = InternalC4GameObjSListPointer->Find_Node(reinterpret_cast<::C4GameObj *>(data->C4GameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew C4GameObjSLNode(IntPtr(result));
		}
	}

	void C4GameObjSList::InsertBefore(IC4GameObj ^data, ISLNode<IC4GameObj ^> ^node)
	{
		if (data == nullptr || data->C4GameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}
		else if (node == nullptr || node->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}

		InternalC4GameObjSListPointer->insertBefore(
			reinterpret_cast<::C4GameObj *>(data->C4GameObjPointer.ToPointer()),
			*reinterpret_cast<::SLNode<::C4GameObj> *>(node->Pointer.ToPointer()));
	}

	void C4GameObjSList::InsertAfter(IC4GameObj ^data, ISLNode<IC4GameObj ^> ^node)
	{
		if (data == nullptr || data->C4GameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}
		else if (node == nullptr || node->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}

		InternalC4GameObjSListPointer->insertAfter(
			reinterpret_cast<::C4GameObj *>(data->C4GameObjPointer.ToPointer()),
			*reinterpret_cast<::SLNode<::C4GameObj> *>(node->Pointer.ToPointer()));
	}

	IntPtr C4GameObjSList::C4GameObjSListPointer::get()
	{
		return IntPtr(InternalC4GameObjSListPointer);
	}

	bool C4GameObjSList::IsEmpty::get()
	{
		return InternalC4GameObjSListPointer->Is_Empty();
	}

	ISLNode<IC4GameObj ^> ^C4GameObjSList::Head::get()
	{
		auto result = InternalC4GameObjSListPointer->Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew C4GameObjSLNode(IntPtr(result));
		}
	}

	ISLNode<IC4GameObj ^> ^C4GameObjSList::Tail::get()
	{
		auto result = InternalC4GameObjSListPointer->Tail();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew C4GameObjSLNode(IntPtr(result));
		}
	}

	int C4GameObjSList::Count::get()
	{
		return static_cast<int>(InternalC4GameObjSListPointer->Get_Count());
	}

	bool C4GameObjSList::InternalDestroyPointer()
	{
		Imports::DestroyC4GameObjSList(InternalC4GameObjSListPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::SList<::C4GameObj> *C4GameObjSList::InternalC4GameObjSListPointer::get()
	{
		return reinterpret_cast<::SList<::C4GameObj> *>(Pointer.ToPointer());
	}
}