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
#include "MBuildingGameObjSList.h"

#include "Imports.h"
#include "MBuildingGameObj.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	BuildingGameObjSLNode::BuildingGameObjSLNode(IntPtr pointer)
		: SLNode<IBuildingGameObj ^>(pointer)
	{

	}

	void BuildingGameObjSLNode::SetNext(ISLNode<IBuildingGameObj ^> ^next)
	{
		if (next == nullptr || next->Pointer.ToPointer() == nullptr)
		{
			InternalBuildingGameObjSLNodePointer->Set_Next(nullptr);
		}
		else
		{
			InternalBuildingGameObjSLNodePointer->Set_Next(reinterpret_cast<::SLNode<::BuildingGameObj> *>(next->Pointer.ToPointer()));
		}
	}

	IntPtr BuildingGameObjSLNode::BuildingGameObjSLNodePointer::get()
	{
		return IntPtr(InternalBuildingGameObjSLNodePointer);
	}

	ISLNode<IBuildingGameObj ^> ^BuildingGameObjSLNode::Next::get()
	{
		auto result = InternalBuildingGameObjSLNodePointer->Next();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BuildingGameObjSLNode(IntPtr(result));
		}
	}

	IBuildingGameObj ^BuildingGameObjSLNode::Data::get()
	{
		auto result = InternalBuildingGameObjSLNodePointer->Data();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BuildingGameObj(IntPtr(result));
		}
	}

	bool BuildingGameObjSLNode::InternalDestroyPointer()
	{
		Imports::DestroyBuildingGameObjSLNode(InternalBuildingGameObjSLNodePointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::AutoPoolClass<::GenericSLNode, 256> *BuildingGameObjSLNode::InternalAutoPoolClassPointer::get()
	{
		return InternalBuildingGameObjSLNodePointer;
	}

	::GenericSLNode *BuildingGameObjSLNode::InternalGenericSLNodePointer::get()
	{
		return InternalBuildingGameObjSLNodePointer;
	}

	::SLNode<::BuildingGameObj> *BuildingGameObjSLNode::InternalBuildingGameObjSLNodePointer::get()
	{
		return reinterpret_cast<::SLNode<::BuildingGameObj> *>(Pointer.ToPointer());
	}

	BuildingGameObjSList::BuildingGameObjSList()
		: SList<IBuildingGameObj ^>(IntPtr(Imports::CreateBuildingGameObjSList()))
	{

	}

	BuildingGameObjSList::BuildingGameObjSList(IntPtr pointer)
		: SList<IBuildingGameObj ^>(pointer)
	{

	}

	IUnmanagedContainer<ISList<IBuildingGameObj ^> ^> ^BuildingGameObjSList::CreateBuildingGameObjSList()
	{
		return gcnew UnmanagedContainer<ISList<IBuildingGameObj ^> ^>(gcnew BuildingGameObjSList());
	}

	bool BuildingGameObjSList::AddHead(IBuildingGameObj ^data)
	{
		if (data == nullptr || data->BuildingGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalBuildingGameObjSListPointer->Add_Head(reinterpret_cast<::BuildingGameObj *>(data->BuildingGameObjPointer.ToPointer()));
	}

	bool BuildingGameObjSList::AddHead(ISList<IBuildingGameObj ^> ^list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		return InternalBuildingGameObjSListPointer->Add_Head(*reinterpret_cast<::SList<::BuildingGameObj> *>(list->Pointer.ToPointer()));
	}

	bool BuildingGameObjSList::AddTail(IBuildingGameObj ^data)
	{
		if (data == nullptr || data->BuildingGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalBuildingGameObjSListPointer->Add_Tail(reinterpret_cast<::BuildingGameObj *>(data->BuildingGameObjPointer.ToPointer()));
	}

	bool BuildingGameObjSList::AddTail(ISList<IBuildingGameObj ^> ^list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		return InternalBuildingGameObjSListPointer->Add_Tail(*reinterpret_cast<::SList<::BuildingGameObj> *>(list->Pointer.ToPointer()));
	}

	IBuildingGameObj ^BuildingGameObjSList::RemoveHead()
	{
		auto result = InternalBuildingGameObjSListPointer->Remove_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BuildingGameObj(IntPtr(result));
		}
	}

	IBuildingGameObj ^BuildingGameObjSList::RemoveTail()
	{
		auto result = InternalBuildingGameObjSListPointer->Remove_Tail();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BuildingGameObj(IntPtr(result));
		}
	}

	bool BuildingGameObjSList::Remove(IBuildingGameObj ^data)
	{
		if (data == nullptr || data->BuildingGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalBuildingGameObjSListPointer->Remove(reinterpret_cast<::BuildingGameObj *>(data->BuildingGameObjPointer.ToPointer()));
	}

	void BuildingGameObjSList::RemoveAll()
	{
		InternalBuildingGameObjSListPointer->Remove_All();
	}

	bool BuildingGameObjSList::InsertBefore(IBuildingGameObj ^newNode, IBuildingGameObj ^oldNode)
	{
		if (newNode == nullptr || newNode->BuildingGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("newNode");
		}
		else if (oldNode == nullptr || oldNode->BuildingGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("oldNode");
		}

		return InternalBuildingGameObjSListPointer->Insert_Before(
			reinterpret_cast<::BuildingGameObj *>(newNode->BuildingGameObjPointer.ToPointer()),
			reinterpret_cast<::BuildingGameObj *>(oldNode->BuildingGameObjPointer.ToPointer()));
	}

	bool BuildingGameObjSList::InsertAfter(IBuildingGameObj ^newNode, IBuildingGameObj ^oldNode)
	{
		if (newNode == nullptr || newNode->BuildingGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("newNode");
		}
		else if (oldNode == nullptr || oldNode->BuildingGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("oldNode");
		}

		return InternalBuildingGameObjSListPointer->Insert_After(
			reinterpret_cast<::BuildingGameObj *>(newNode->BuildingGameObjPointer.ToPointer()),
			reinterpret_cast<::BuildingGameObj *>(oldNode->BuildingGameObjPointer.ToPointer()));
	}

	ISLNode<IBuildingGameObj ^> ^BuildingGameObjSList::FindNode(IBuildingGameObj ^data)
	{
		if (data == nullptr || data->BuildingGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		auto result = InternalBuildingGameObjSListPointer->Find_Node(reinterpret_cast<::BuildingGameObj *>(data->BuildingGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BuildingGameObjSLNode(IntPtr(result));
		}
	}

	void BuildingGameObjSList::InsertBefore(IBuildingGameObj ^data, ISLNode<IBuildingGameObj ^> ^node)
	{
		if (data == nullptr || data->BuildingGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}
		else if (node == nullptr || node->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}

		InternalBuildingGameObjSListPointer->insertBefore(
			reinterpret_cast<::BuildingGameObj *>(data->BuildingGameObjPointer.ToPointer()),
			*reinterpret_cast<::SLNode<::BuildingGameObj> *>(node->Pointer.ToPointer()));
	}

	void BuildingGameObjSList::InsertAfter(IBuildingGameObj ^data, ISLNode<IBuildingGameObj ^> ^node)
	{
		if (data == nullptr || data->BuildingGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}
		else if (node == nullptr || node->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}

		InternalBuildingGameObjSListPointer->insertAfter(
			reinterpret_cast<::BuildingGameObj *>(data->BuildingGameObjPointer.ToPointer()),
			*reinterpret_cast<::SLNode<::BuildingGameObj> *>(node->Pointer.ToPointer()));
	}

	IntPtr BuildingGameObjSList::BuildingGameObjSListPointer::get()
	{
		return IntPtr(InternalBuildingGameObjSListPointer);
	}

	bool BuildingGameObjSList::IsEmpty::get()
	{
		return InternalBuildingGameObjSListPointer->Is_Empty();
	}

	ISLNode<IBuildingGameObj ^> ^BuildingGameObjSList::Head::get()
	{
		auto result = InternalBuildingGameObjSListPointer->Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BuildingGameObjSLNode(IntPtr(result));
		}
	}

	ISLNode<IBuildingGameObj ^> ^BuildingGameObjSList::Tail::get()
	{
		auto result = InternalBuildingGameObjSListPointer->Tail();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BuildingGameObjSLNode(IntPtr(result));
		}
	}

	int BuildingGameObjSList::Count::get()
	{
		return static_cast<int>(InternalBuildingGameObjSListPointer->Get_Count());
	}

	bool BuildingGameObjSList::InternalDestroyPointer()
	{
		Imports::DestroyBuildingGameObjSList(InternalBuildingGameObjSListPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::SList<::BuildingGameObj> *BuildingGameObjSList::InternalBuildingGameObjSListPointer::get()
	{
		return reinterpret_cast<::SList<::BuildingGameObj> *>(Pointer.ToPointer());
	}
}