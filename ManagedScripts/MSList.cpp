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
#include "MSList.h"

#include "Imports.h"

namespace RenSharp
{

#pragma managed(push, off)

	class GenericSLNodeHelper : public ::GenericSLNode
	{
		private:
			GenericSLNodeHelper(void *obj)
				: ::GenericSLNode(obj)
			{

			}

		public:
			void InternalSetNext(void *next)
			{
				Internal_Set_Next(next);
			}

			void InternalSetData(void *data)
			{
				Internal_Set_Data(data);
			}

			void *&GetNodeNext()
			{
				return NodeNext;
			}

			void *&GetNodeData()
			{
				return NodeData;
			}
	};

#pragma managed(pop)

	GenericSLNode::GenericSLNode(IntPtr pointer)
		: AutoPoolClass<IGenericSLNode ^>(pointer)
	{

	}

	bool GenericSLNode::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IGenericSLNode ^otherThis = dynamic_cast<IGenericSLNode ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return GenericSLNodePointer.Equals(otherThis->GenericSLNodePointer);
	}

	IntPtr GenericSLNode::AutoPoolClassPointer::get()
	{
		return IntPtr(InternalAutoPoolClassPointer);
	}

	IntPtr GenericSLNode::GenericSLNodePointer::get()
	{
		return IntPtr(InternalGenericSLNodePointer);
	}

	bool GenericSLNode::InternalDestroyPointer()
	{
		Imports::DestroyGenericSLNode(InternalGenericSLNodePointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	void GenericSLNode::InternalSetNext(IntPtr next)
	{
		auto helper = reinterpret_cast<GenericSLNodeHelper *>(InternalGenericSLNodePointer);

		helper->InternalSetNext(next.ToPointer());
	}

	void GenericSLNode::InternalSetData(IntPtr data)
	{
		auto helper = reinterpret_cast<GenericSLNodeHelper *>(InternalGenericSLNodePointer);

		helper->InternalSetData(data.ToPointer());
	}

	::AutoPoolClass<::GenericSLNode, 256> *GenericSLNode::InternalAutoPoolClassPointer::get()
	{
		return InternalGenericSLNodePointer;
	}

	::GenericSLNode *GenericSLNode::InternalGenericSLNodePointer::get()
	{
		return reinterpret_cast<::GenericSLNode *>(Pointer.ToPointer());
	}

	IntPtr GenericSLNode::NodeNext::get()
	{
		auto helper = reinterpret_cast<GenericSLNodeHelper *>(InternalGenericSLNodePointer);

		auto &nodeNext = helper->GetNodeNext();

		return IntPtr(nodeNext);
	}

	void GenericSLNode::NodeNext::set(IntPtr value)
	{
		auto helper = reinterpret_cast<GenericSLNodeHelper *>(InternalGenericSLNodePointer);

		auto &nodeNext = helper->GetNodeNext();

		nodeNext = value.ToPointer();
	}

	IntPtr GenericSLNode::NodeData::get()
	{
		auto helper = reinterpret_cast<GenericSLNodeHelper *>(InternalGenericSLNodePointer);

		auto &nodeData = helper->GetNodeData();

		return IntPtr(nodeData);
	}

	void GenericSLNode::NodeData::set(IntPtr value)
	{
		auto helper = reinterpret_cast<GenericSLNodeHelper *>(InternalGenericSLNodePointer);

		auto &nodeData = helper->GetNodeData();

		nodeData = value.ToPointer();
	}
}