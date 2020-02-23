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
#include "MVehicleGameObjSList.h"

#include "Imports.h"
#include "MVehicleGameObj.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	VehicleGameObjSLNode::VehicleGameObjSLNode(IntPtr pointer)
		: SLNode<IVehicleGameObj ^>(pointer)
	{

	}

	void VehicleGameObjSLNode::SetNext(ISLNode<IVehicleGameObj ^> ^next)
	{
		if (next == nullptr || next->Pointer.ToPointer() == nullptr)
		{
			InternalVehicleGameObjSLNodePointer->Set_Next(nullptr);
		}
		else
		{
			InternalVehicleGameObjSLNodePointer->Set_Next(reinterpret_cast<::SLNode<::VehicleGameObj> *>(next->Pointer.ToPointer()));
		}
	}

	IntPtr VehicleGameObjSLNode::VehicleGameObjSLNodePointer::get()
	{
		return IntPtr(InternalVehicleGameObjSLNodePointer);
	}

	ISLNode<IVehicleGameObj ^> ^VehicleGameObjSLNode::Next::get()
	{
		auto result = InternalVehicleGameObjSLNodePointer->Next();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew VehicleGameObjSLNode(IntPtr(result));
		}
	}

	IVehicleGameObj ^VehicleGameObjSLNode::Data::get()
	{
		auto result = InternalVehicleGameObjSLNodePointer->Data();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew VehicleGameObj(IntPtr(result));
		}
	}

	bool VehicleGameObjSLNode::InternalDestroyPointer()
	{
		Imports::DestroyVehicleGameObjSLNode(InternalVehicleGameObjSLNodePointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::AutoPoolClass<::GenericSLNode, 256> *VehicleGameObjSLNode::InternalAutoPoolClassPointer::get()
	{
		return InternalVehicleGameObjSLNodePointer;
	}

	::GenericSLNode *VehicleGameObjSLNode::InternalGenericSLNodePointer::get()
	{
		return InternalVehicleGameObjSLNodePointer;
	}

	::SLNode<::VehicleGameObj> *VehicleGameObjSLNode::InternalVehicleGameObjSLNodePointer::get()
	{
		return reinterpret_cast<::SLNode<::VehicleGameObj> *>(Pointer.ToPointer());
	}

	VehicleGameObjSList::VehicleGameObjSList()
		: SList<IVehicleGameObj ^>(IntPtr(Imports::CreateVehicleGameObjSList()))
	{

	}

	VehicleGameObjSList::VehicleGameObjSList(IntPtr pointer)
		: SList<IVehicleGameObj ^>(pointer)
	{

	}

	IUnmanagedContainer<ISList<IVehicleGameObj ^> ^> ^VehicleGameObjSList::CreateVehicleGameObjSList()
	{
		return gcnew UnmanagedContainer<ISList<IVehicleGameObj ^> ^>(gcnew VehicleGameObjSList());
	}

	bool VehicleGameObjSList::AddHead(IVehicleGameObj ^data)
	{
		if (data == nullptr || data->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalVehicleGameObjSListPointer->Add_Head(reinterpret_cast<::VehicleGameObj *>(data->VehicleGameObjPointer.ToPointer()));
	}

	bool VehicleGameObjSList::AddHead(ISList<IVehicleGameObj ^> ^list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		return InternalVehicleGameObjSListPointer->Add_Head(*reinterpret_cast<::SList<::VehicleGameObj> *>(list->Pointer.ToPointer()));
	}

	bool VehicleGameObjSList::AddTail(IVehicleGameObj ^data)
	{
		if (data == nullptr || data->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalVehicleGameObjSListPointer->Add_Tail(reinterpret_cast<::VehicleGameObj *>(data->VehicleGameObjPointer.ToPointer()));
	}

	bool VehicleGameObjSList::AddTail(ISList<IVehicleGameObj ^> ^list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		return InternalVehicleGameObjSListPointer->Add_Tail(*reinterpret_cast<::SList<::VehicleGameObj> *>(list->Pointer.ToPointer()));
	}

	IVehicleGameObj ^VehicleGameObjSList::RemoveHead()
	{
		auto result = InternalVehicleGameObjSListPointer->Remove_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew VehicleGameObj(IntPtr(result));
		}
	}

	IVehicleGameObj ^VehicleGameObjSList::RemoveTail()
	{
		auto result = InternalVehicleGameObjSListPointer->Remove_Tail();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew VehicleGameObj(IntPtr(result));
		}
	}

	bool VehicleGameObjSList::Remove(IVehicleGameObj ^data)
	{
		if (data == nullptr || data->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalVehicleGameObjSListPointer->Remove(reinterpret_cast<::VehicleGameObj *>(data->VehicleGameObjPointer.ToPointer()));
	}

	void VehicleGameObjSList::RemoveAll()
	{
		InternalVehicleGameObjSListPointer->Remove_All();
	}

	bool VehicleGameObjSList::InsertBefore(IVehicleGameObj ^newNode, IVehicleGameObj ^oldNode)
	{
		if (newNode == nullptr || newNode->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("newNode");
		}
		else if (oldNode == nullptr || oldNode->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("oldNode");
		}

		return InternalVehicleGameObjSListPointer->Insert_Before(
			reinterpret_cast<::VehicleGameObj *>(newNode->VehicleGameObjPointer.ToPointer()),
			reinterpret_cast<::VehicleGameObj *>(oldNode->VehicleGameObjPointer.ToPointer()));
	}

	bool VehicleGameObjSList::InsertAfter(IVehicleGameObj ^newNode, IVehicleGameObj ^oldNode)
	{
		if (newNode == nullptr || newNode->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("newNode");
		}
		else if (oldNode == nullptr || oldNode->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("oldNode");
		}

		return InternalVehicleGameObjSListPointer->Insert_After(
			reinterpret_cast<::VehicleGameObj *>(newNode->VehicleGameObjPointer.ToPointer()),
			reinterpret_cast<::VehicleGameObj *>(oldNode->VehicleGameObjPointer.ToPointer()));
	}

	ISLNode<IVehicleGameObj ^> ^VehicleGameObjSList::FindNode(IVehicleGameObj ^data)
	{
		if (data == nullptr || data->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		auto result = InternalVehicleGameObjSListPointer->Find_Node(reinterpret_cast<::VehicleGameObj *>(data->VehicleGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew VehicleGameObjSLNode(IntPtr(result));
		}
	}

	void VehicleGameObjSList::InsertBefore(IVehicleGameObj ^data, ISLNode<IVehicleGameObj ^> ^node)
	{
		if (data == nullptr || data->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}
		else if (node == nullptr || node->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}

		InternalVehicleGameObjSListPointer->insertBefore(
			reinterpret_cast<::VehicleGameObj *>(data->VehicleGameObjPointer.ToPointer()),
			*reinterpret_cast<::SLNode<::VehicleGameObj> *>(node->Pointer.ToPointer()));
	}

	void VehicleGameObjSList::InsertAfter(IVehicleGameObj ^data, ISLNode<IVehicleGameObj ^> ^node)
	{
		if (data == nullptr || data->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}
		else if (node == nullptr || node->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}

		InternalVehicleGameObjSListPointer->insertAfter(
			reinterpret_cast<::VehicleGameObj *>(data->VehicleGameObjPointer.ToPointer()),
			*reinterpret_cast<::SLNode<::VehicleGameObj> *>(node->Pointer.ToPointer()));
	}

	IntPtr VehicleGameObjSList::VehicleGameObjSListPointer::get()
	{
		return IntPtr(InternalVehicleGameObjSListPointer);
	}

	bool VehicleGameObjSList::IsEmpty::get()
	{
		return InternalVehicleGameObjSListPointer->Is_Empty();
	}

	ISLNode<IVehicleGameObj ^> ^VehicleGameObjSList::Head::get()
	{
		auto result = InternalVehicleGameObjSListPointer->Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew VehicleGameObjSLNode(IntPtr(result));
		}
	}

	ISLNode<IVehicleGameObj ^> ^VehicleGameObjSList::Tail::get()
	{
		auto result = InternalVehicleGameObjSListPointer->Tail();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew VehicleGameObjSLNode(IntPtr(result));
		}
	}

	int VehicleGameObjSList::Count::get()
	{
		return static_cast<int>(InternalVehicleGameObjSListPointer->Get_Count());
	}

	bool VehicleGameObjSList::InternalDestroyPointer()
	{
		Imports::DestroyVehicleGameObjSList(InternalVehicleGameObjSListPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::SList<::VehicleGameObj> *VehicleGameObjSList::InternalVehicleGameObjSListPointer::get()
	{
		return reinterpret_cast<::SList<::VehicleGameObj> *>(Pointer.ToPointer());
	}
}