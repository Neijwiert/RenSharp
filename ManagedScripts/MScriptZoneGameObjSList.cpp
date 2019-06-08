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
#include "MScriptZoneGameObjSList.h"

#include "Imports.h"
#include "MScriptZoneGameObj.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	ScriptZoneGameObjSLNode::ScriptZoneGameObjSLNode(IntPtr pointer)
		: SLNode<IScriptZoneGameObj ^>(pointer)
	{

	}

	void ScriptZoneGameObjSLNode::SetNext(ISLNode<IScriptZoneGameObj ^> ^next)
	{
		if (next == nullptr || next->Pointer.ToPointer() == nullptr)
		{
			InternalScriptZoneGameObjSLNodePointer->Set_Next(nullptr);
		}
		else
		{
			InternalScriptZoneGameObjSLNodePointer->Set_Next(reinterpret_cast<::SLNode<::ScriptZoneGameObj> *>(next->Pointer.ToPointer()));
		}
	}

	IntPtr ScriptZoneGameObjSLNode::ScriptZoneGameObjSLNodePointer::get()
	{
		return IntPtr(InternalScriptZoneGameObjSLNodePointer);
	}

	ISLNode<IScriptZoneGameObj ^> ^ScriptZoneGameObjSLNode::Next::get()
	{
		auto result = InternalScriptZoneGameObjSLNodePointer->Next();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptZoneGameObjSLNode(IntPtr(result));
		}
	}

	IScriptZoneGameObj ^ScriptZoneGameObjSLNode::Data::get()
	{
		auto result = InternalScriptZoneGameObjSLNodePointer->Data();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptZoneGameObj(IntPtr(result));
		}
	}

	bool ScriptZoneGameObjSLNode::InternalDestroyPointer()
	{
		Imports::DestroyScriptZoneGameObjSLNode(InternalScriptZoneGameObjSLNodePointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::AutoPoolClass<::GenericSLNode, 256> *ScriptZoneGameObjSLNode::InternalAutoPoolClassPointer::get()
	{
		return InternalScriptZoneGameObjSLNodePointer;
	}

	::GenericSLNode *ScriptZoneGameObjSLNode::InternalGenericSLNodePointer::get()
	{
		return InternalScriptZoneGameObjSLNodePointer;
	}

	::SLNode<::ScriptZoneGameObj> *ScriptZoneGameObjSLNode::InternalScriptZoneGameObjSLNodePointer::get()
	{
		return reinterpret_cast<::SLNode<::ScriptZoneGameObj> *>(Pointer.ToPointer());
	}

	ScriptZoneGameObjSList::ScriptZoneGameObjSList()
		: SList<IScriptZoneGameObj ^>(IntPtr(Imports::CreateScriptZoneGameObjSList()))
	{

	}

	ScriptZoneGameObjSList::ScriptZoneGameObjSList(IntPtr pointer)
		: SList<IScriptZoneGameObj ^>(pointer)
	{

	}

	IUnmanagedContainer<ISList<IScriptZoneGameObj ^> ^> ^ScriptZoneGameObjSList::CreateScriptZoneGameObjSList()
	{
		return gcnew UnmanagedContainer<ISList<IScriptZoneGameObj ^> ^>(gcnew ScriptZoneGameObjSList());
	}

	bool ScriptZoneGameObjSList::AddHead(IScriptZoneGameObj ^data)
	{
		if (data == nullptr || data->ScriptZoneGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalScriptZoneGameObjSListPointer->Add_Head(reinterpret_cast<::ScriptZoneGameObj *>(data->ScriptZoneGameObjPointer.ToPointer()));
	}

	bool ScriptZoneGameObjSList::AddHead(ISList<IScriptZoneGameObj ^> ^list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		return InternalScriptZoneGameObjSListPointer->Add_Head(*reinterpret_cast<::SList<::ScriptZoneGameObj> *>(list->Pointer.ToPointer()));
	}

	bool ScriptZoneGameObjSList::AddTail(IScriptZoneGameObj ^data)
	{
		if (data == nullptr || data->ScriptZoneGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalScriptZoneGameObjSListPointer->Add_Tail(reinterpret_cast<::ScriptZoneGameObj *>(data->ScriptZoneGameObjPointer.ToPointer()));
	}

	bool ScriptZoneGameObjSList::AddTail(ISList<IScriptZoneGameObj ^> ^list)
	{
		if (list == nullptr || list->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("list");
		}

		return InternalScriptZoneGameObjSListPointer->Add_Tail(*reinterpret_cast<::SList<::ScriptZoneGameObj> *>(list->Pointer.ToPointer()));
	}

	IScriptZoneGameObj ^ScriptZoneGameObjSList::RemoveHead()
	{
		auto result = InternalScriptZoneGameObjSListPointer->Remove_Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptZoneGameObj(IntPtr(result));
		}
	}

	IScriptZoneGameObj ^ScriptZoneGameObjSList::RemoveTail()
	{
		auto result = InternalScriptZoneGameObjSListPointer->Remove_Tail();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptZoneGameObj(IntPtr(result));
		}
	}

	bool ScriptZoneGameObjSList::Remove(IScriptZoneGameObj ^data)
	{
		if (data == nullptr || data->ScriptZoneGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		return InternalScriptZoneGameObjSListPointer->Remove(reinterpret_cast<::ScriptZoneGameObj *>(data->ScriptZoneGameObjPointer.ToPointer()));
	}

	void ScriptZoneGameObjSList::RemoveAll()
	{
		InternalScriptZoneGameObjSListPointer->Remove_All();
	}

	bool ScriptZoneGameObjSList::InsertBefore(IScriptZoneGameObj ^newNode, IScriptZoneGameObj ^oldNode)
	{
		if (newNode == nullptr || newNode->ScriptZoneGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("newNode");
		}
		else if (oldNode == nullptr || oldNode->ScriptZoneGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("oldNode");
		}

		return InternalScriptZoneGameObjSListPointer->Insert_Before(
			reinterpret_cast<::ScriptZoneGameObj *>(newNode->ScriptZoneGameObjPointer.ToPointer()),
			reinterpret_cast<::ScriptZoneGameObj *>(oldNode->ScriptZoneGameObjPointer.ToPointer()));
	}

	bool ScriptZoneGameObjSList::InsertAfter(IScriptZoneGameObj ^newNode, IScriptZoneGameObj ^oldNode)
	{
		if (newNode == nullptr || newNode->ScriptZoneGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("newNode");
		}
		else if (oldNode == nullptr || oldNode->ScriptZoneGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("oldNode");
		}

		return InternalScriptZoneGameObjSListPointer->Insert_After(
			reinterpret_cast<::ScriptZoneGameObj *>(newNode->ScriptZoneGameObjPointer.ToPointer()),
			reinterpret_cast<::ScriptZoneGameObj *>(oldNode->ScriptZoneGameObjPointer.ToPointer()));
	}

	ISLNode<IScriptZoneGameObj ^> ^ScriptZoneGameObjSList::FindNode(IScriptZoneGameObj ^data)
	{
		if (data == nullptr || data->ScriptZoneGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		auto result = InternalScriptZoneGameObjSListPointer->Find_Node(reinterpret_cast<::ScriptZoneGameObj *>(data->ScriptZoneGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptZoneGameObjSLNode(IntPtr(result));
		}
	}

	void ScriptZoneGameObjSList::InsertBefore(IScriptZoneGameObj ^data, ISLNode<IScriptZoneGameObj ^> ^node)
	{
		if (data == nullptr || data->ScriptZoneGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}
		else if (node == nullptr || node->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}

		InternalScriptZoneGameObjSListPointer->insertBefore(
			reinterpret_cast<::ScriptZoneGameObj *>(data->ScriptZoneGameObjPointer.ToPointer()),
			*reinterpret_cast<::SLNode<::ScriptZoneGameObj> *>(node->Pointer.ToPointer()));
	}

	void ScriptZoneGameObjSList::InsertAfter(IScriptZoneGameObj ^data, ISLNode<IScriptZoneGameObj ^> ^node)
	{
		if (data == nullptr || data->ScriptZoneGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}
		else if (node == nullptr || node->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}

		InternalScriptZoneGameObjSListPointer->insertAfter(
			reinterpret_cast<::ScriptZoneGameObj *>(data->ScriptZoneGameObjPointer.ToPointer()),
			*reinterpret_cast<::SLNode<::ScriptZoneGameObj> *>(node->Pointer.ToPointer()));
	}

	IntPtr ScriptZoneGameObjSList::ScriptZoneGameObjSListPointer::get()
	{
		return IntPtr(InternalScriptZoneGameObjSListPointer);
	}

	bool ScriptZoneGameObjSList::IsEmpty::get()
	{
		return InternalScriptZoneGameObjSListPointer->Is_Empty();
	}

	ISLNode<IScriptZoneGameObj ^> ^ScriptZoneGameObjSList::Head::get()
	{
		auto result = InternalScriptZoneGameObjSListPointer->Head();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptZoneGameObjSLNode(IntPtr(result));
		}
	}

	ISLNode<IScriptZoneGameObj ^> ^ScriptZoneGameObjSList::Tail::get()
	{
		auto result = InternalScriptZoneGameObjSListPointer->Tail();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptZoneGameObjSLNode(IntPtr(result));
		}
	}

	int ScriptZoneGameObjSList::Count::get()
	{
		return static_cast<int>(InternalScriptZoneGameObjSListPointer->Get_Count());
	}

	bool ScriptZoneGameObjSList::InternalDestroyPointer()
	{
		Imports::DestroyScriptZoneGameObjSList(InternalScriptZoneGameObjSListPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::SList<::ScriptZoneGameObj> *ScriptZoneGameObjSList::InternalScriptZoneGameObjSListPointer::get()
	{
		return reinterpret_cast<::SList<::ScriptZoneGameObj> *>(Pointer.ToPointer());
	}
}