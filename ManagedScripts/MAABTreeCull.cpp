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
#include "MAABTreeCull.h"

#include "Imports.h"
#include "MSphereClass.h"
#include "MChunkClass.h"
#include "MAABoxClass.h"
#include "MAAPlaneClass.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{

#pragma managed(push, off)

	class AABTreeCullSystemClassHelper : public ::AABTreeCullSystemClass
	{
		private:
			AABTreeCullSystemClassHelper() = default;

		public:
			void NodeAccepted()
			{
				NODE_ACCEPTED();
			}

			void NodeTriviallyAccepted()
			{
				NODE_TRIVIALLY_ACCEPTED();
			}

			void NodeRejected()
			{
				NODE_REJECTED();
			}

			void LoadNodeContents(::AABTreeNodeClass* node, ::ChunkLoadClass& cLoad)
			{
				Load_Node_Contents(node, cLoad);
			}

			void SaveNodeContents(::AABTreeNodeClass* node, ::ChunkSaveClass& cSave)
			{
				Save_Node_Contents(node, cSave);
			}

			::AABTreeNodeClass*& GetRootNode()
			{
				return RootNode;
			}

			int& GetObjectCount()
			{
				return ObjectCount;
			}

			int& GetNodeCount()
			{
				return NodeCount;
			}

			::AABTreeNodeClass** GetIndexedNodes()
			{
				return IndexedNodes;
			}

			void SetIndexedNode(std::size_t index, ::AABTreeNodeClass* node)
			{
				IndexedNodes[index] = node;
			}

			::AABTreeCullSystemClass::StatsStruct& GetStats()
			{
				return Stats;
			}
	};

#pragma managed(pop)

	AABTreeCullSystemClass::StatsStruct::StatsStruct()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateAABTreeCullSystemClassStatsStruct()))
	{

	}

	AABTreeCullSystemClass::StatsStruct::StatsStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool AABTreeCullSystemClass::StatsStruct::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IStatsStruct^ otherThis = dynamic_cast<IStatsStruct^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return StatsStructPointer.Equals(otherThis->StatsStructPointer);
	}

	IUnmanagedContainer<AABTreeCullSystemClass::IStatsStruct^>^ AABTreeCullSystemClass::StatsStruct::CreateStatsStruct()
	{
		return gcnew UnmanagedContainer<AABTreeCullSystemClass::IStatsStruct^>(gcnew AABTreeCullSystemClass::StatsStruct());
	}

	IntPtr AABTreeCullSystemClass::StatsStruct::StatsStructPointer::get()
	{
		return IntPtr(InternalStatsStructPointer);
	}

	int AABTreeCullSystemClass::StatsStruct::NodeCount::get()
	{
		return InternalStatsStructPointer->NodeCount;
	}

	void AABTreeCullSystemClass::StatsStruct::NodeCount::set(int value)
	{
		InternalStatsStructPointer->NodeCount = value;
	}

	int AABTreeCullSystemClass::StatsStruct::NodesAccepted::get()
	{
		return InternalStatsStructPointer->NodesAccepted;
	}

	void AABTreeCullSystemClass::StatsStruct::NodesAccepted::set(int value)
	{
		InternalStatsStructPointer->NodesAccepted = value;
	}

	int AABTreeCullSystemClass::StatsStruct::NodesTriviallyAccepted::get()
	{
		return InternalStatsStructPointer->NodesTriviallyAccepted;
	}

	void AABTreeCullSystemClass::StatsStruct::NodesTriviallyAccepted::set(int value)
	{
		InternalStatsStructPointer->NodesTriviallyAccepted = value;
	}

	int AABTreeCullSystemClass::StatsStruct::NodesRejected::get()
	{
		return InternalStatsStructPointer->NodesRejected;
	}

	void AABTreeCullSystemClass::StatsStruct::NodesRejected::set(int value)
	{
		InternalStatsStructPointer->NodesRejected = value;
	}

	bool AABTreeCullSystemClass::StatsStruct::InternalDestroyPointer()
	{
		Imports::DestroyAABTreeCullSystemClassStatsStruct(InternalStatsStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::AABTreeCullSystemClass::StatsStruct* AABTreeCullSystemClass::StatsStruct::InternalStatsStructPointer::get()
	{
		return reinterpret_cast<::AABTreeCullSystemClass::StatsStruct*>(Pointer.ToPointer());
	}

	AABTreeCullSystemClass::AABTreeCullSystemClass(IntPtr pointer)
		: CullSystemClass(pointer)
	{

	}

	void AABTreeCullSystemClass::CollectObjects(SphereClass sphere)
	{
		::SphereClass tmp;

		SphereClass::ManagedToUnmanagedSphereClass(sphere, tmp);

		InternalAABTreeCullSystemClassPointer->Collect_Objects(tmp);
	}

	IntPtr AABTreeCullSystemClass::AABTreeCullSystemClassPointer::get()
	{
		return IntPtr(InternalAABTreeCullSystemClassPointer);
	}

	void AABTreeCullSystemClass::NodeAccepted()
	{
		auto helper = reinterpret_cast<AABTreeCullSystemClassHelper*>(InternalAABTreeCullSystemClassPointer);

		helper->NodeAccepted();
	}

	void AABTreeCullSystemClass::NodeTriviallyAccepted()
	{
		auto helper = reinterpret_cast<AABTreeCullSystemClassHelper*>(InternalAABTreeCullSystemClassPointer);

		helper->NodeTriviallyAccepted();
	}

	void AABTreeCullSystemClass::NodeRejected()
	{
		auto helper = reinterpret_cast<AABTreeCullSystemClassHelper*>(InternalAABTreeCullSystemClassPointer);

		helper->NodeRejected();
	}

	void AABTreeCullSystemClass::LoadNodeContents(IAABTreeNodeClass^ node, IChunkLoadClass^ cLoad)
	{
		if (node == nullptr || node->AABTreeNodeClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}
		else if (cLoad == nullptr || cLoad->ChunkLoadClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("cLoad");
		}

		auto helper = reinterpret_cast<AABTreeCullSystemClassHelper*>(InternalAABTreeCullSystemClassPointer);

		helper->LoadNodeContents(
			reinterpret_cast<::AABTreeNodeClass*>(node->AABTreeNodeClassPointer.ToPointer()),
			*reinterpret_cast<::ChunkLoadClass*>(cLoad->ChunkLoadClassPointer.ToPointer()));
	}

	void AABTreeCullSystemClass::SaveNodeContents(IAABTreeNodeClass^ node, IChunkSaveClass^ cSave)
	{
		if (node == nullptr || node->AABTreeNodeClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}
		else if (cSave == nullptr || cSave->ChunkSaveClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("cSave");
		}

		auto helper = reinterpret_cast<AABTreeCullSystemClassHelper*>(InternalAABTreeCullSystemClassPointer);

		helper->SaveNodeContents(
			reinterpret_cast<::AABTreeNodeClass*>(node->AABTreeNodeClassPointer.ToPointer()),
			*reinterpret_cast<::ChunkSaveClass*>(cSave->ChunkSaveClassPointer.ToPointer()));
	}

	::CullSystemClass* AABTreeCullSystemClass::InternalCullSystemClassPointer::get()
	{
		return InternalAABTreeCullSystemClassPointer;
	}

	::AABTreeCullSystemClass* AABTreeCullSystemClass::InternalAABTreeCullSystemClassPointer::get()
	{
		return reinterpret_cast<::AABTreeCullSystemClass*>(Pointer.ToPointer());
	}

	IAABTreeNodeClass^ AABTreeCullSystemClass::RootNode::get()
	{
		auto helper = reinterpret_cast<AABTreeCullSystemClassHelper*>(InternalAABTreeCullSystemClassPointer);

		auto& rootNode = helper->GetRootNode();

		if (rootNode == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew AABTreeNodeClass(IntPtr(rootNode));
		}
	}

	void AABTreeCullSystemClass::RootNode::set(IAABTreeNodeClass^ value)
	{
		auto helper = reinterpret_cast<AABTreeCullSystemClassHelper*>(InternalAABTreeCullSystemClassPointer);

		auto& rootNode = helper->GetRootNode();

		if (value == nullptr || value->AABTreeNodeClassPointer.ToPointer() == nullptr)
		{
			rootNode = nullptr;
		}
		else
		{
			rootNode = reinterpret_cast<::AABTreeNodeClass*>(value->AABTreeNodeClassPointer.ToPointer());
		}
	}

	int AABTreeCullSystemClass::ObjectCount::get()
	{
		auto helper = reinterpret_cast<AABTreeCullSystemClassHelper*>(InternalAABTreeCullSystemClassPointer);

		auto& objectCount = helper->GetObjectCount();

		return objectCount;
	}

	void AABTreeCullSystemClass::ObjectCount::set(int value)
	{
		auto helper = reinterpret_cast<AABTreeCullSystemClassHelper*>(InternalAABTreeCullSystemClassPointer);

		auto& objectCount = helper->GetObjectCount();

		objectCount = value;
	}

	int AABTreeCullSystemClass::NodeCount::get()
	{
		auto helper = reinterpret_cast<AABTreeCullSystemClassHelper*>(InternalAABTreeCullSystemClassPointer);

		auto& nodeCount = helper->GetNodeCount();

		return nodeCount;
	}

	void AABTreeCullSystemClass::NodeCount::set(int value)
	{
		auto helper = reinterpret_cast<AABTreeCullSystemClassHelper*>(InternalAABTreeCullSystemClassPointer);

		auto& nodeCount = helper->GetNodeCount();

		nodeCount = value;
	}

	array<IAABTreeNodeClass^>^ AABTreeCullSystemClass::IndexedNodes::get()
	{
		auto helper = reinterpret_cast<AABTreeCullSystemClassHelper*>(InternalAABTreeCullSystemClassPointer);

		auto indexNodes = helper->GetIndexedNodes();

		array<IAABTreeNodeClass^>^ result = gcnew array<IAABTreeNodeClass^>(NodeCount);
		for (int x = 0; x < result->Length; x++)
		{
			auto currentNode = indexNodes[x];
			if (currentNode == nullptr)
			{
				result[x] = nullptr;
			}
			else
			{
				result[x] = gcnew AABTreeNodeClass(IntPtr(currentNode));
			}
		}

		return result;
	}

	void AABTreeCullSystemClass::IndexedNodes::set(array<IAABTreeNodeClass^>^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}
		else if (value->Length != NodeCount)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<AABTreeCullSystemClassHelper*>(InternalAABTreeCullSystemClassPointer);

		for (int x = 0; x < value->Length; x++)
		{
			auto currentNode = value[x];
			if (currentNode == nullptr || currentNode->AABTreeNodeClassPointer.ToPointer() == nullptr)
			{
				helper->SetIndexedNode(
					static_cast<std::size_t>(x),
					nullptr);
			}
			else
			{
				helper->SetIndexedNode(
					static_cast<std::size_t>(x),
					reinterpret_cast<::AABTreeNodeClass*>(currentNode->AABTreeNodeClassPointer.ToPointer()));
			}
		}
	}

	AABTreeCullSystemClass::IStatsStruct^ AABTreeCullSystemClass::Stats::get()
	{
		auto helper = reinterpret_cast<AABTreeCullSystemClassHelper*>(InternalAABTreeCullSystemClassPointer);

		auto& stats = helper->GetStats();

		return gcnew AABTreeCullSystemClass::StatsStruct(IntPtr(&stats));
	}

	void AABTreeCullSystemClass::Stats::set(AABTreeCullSystemClass::IStatsStruct^ value)
	{
		if (value == nullptr || value->StatsStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<AABTreeCullSystemClassHelper*>(InternalAABTreeCullSystemClassPointer);

		auto& stats = helper->GetStats();

		stats = *reinterpret_cast<::AABTreeCullSystemClass::StatsStruct*>(value->StatsStructPointer.ToPointer());
	}

	AABTreeIterator::AABTreeIterator(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IntPtr AABTreeIterator::AABTreeIteratorPointer::get()
	{
		return IntPtr(InternalAABTreeIteratorPointer);
	}

	bool AABTreeIterator::InternalDestroyPointer()
	{
		Imports::DestroyAABTreeIterator(InternalAABTreeIteratorPointer);
		Pointer = IntPtr::Zero;
		
		return true;
	}

	::AABTreeIterator* AABTreeIterator::InternalAABTreeIteratorPointer::get()
	{
		return reinterpret_cast<::AABTreeIterator*>(Pointer.ToPointer());
	}

	AABTreeNodeClass::SplitChoiceStruct::SplitChoiceStruct()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateAABTreeNodeClassSplitChoiceStruct()))
	{

	}

	AABTreeNodeClass::SplitChoiceStruct::SplitChoiceStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<AABTreeNodeClass::ISplitChoiceStruct^>^ AABTreeNodeClass::SplitChoiceStruct::CreateSplitChoiceStruct()
	{
		return gcnew UnmanagedContainer<AABTreeNodeClass::ISplitChoiceStruct^>(gcnew AABTreeNodeClass::SplitChoiceStruct());
	}

	bool AABTreeNodeClass::SplitChoiceStruct::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		AABTreeNodeClass::ISplitChoiceStruct^ otherThis = dynamic_cast<AABTreeNodeClass::ISplitChoiceStruct^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return SplitChoiceStructPointer.Equals(otherThis->SplitChoiceStructPointer);
	}

	IntPtr AABTreeNodeClass::SplitChoiceStruct::SplitChoiceStructPointer::get()
	{
		return IntPtr(InternalSplitChoiceStructPointer);
	}

	float AABTreeNodeClass::SplitChoiceStruct::Cost::get()
	{
		return InternalSplitChoiceStructPointer->Cost;
	}

	void AABTreeNodeClass::SplitChoiceStruct::Cost::set(float value)
	{
		InternalSplitChoiceStructPointer->Cost = value;
	}

	int AABTreeNodeClass::SplitChoiceStruct::FrontCount::get()
	{
		return InternalSplitChoiceStructPointer->FrontCount;
	}

	void AABTreeNodeClass::SplitChoiceStruct::FrontCount::set(int value)
	{
		InternalSplitChoiceStructPointer->FrontCount = value;
	}

	int AABTreeNodeClass::SplitChoiceStruct::BackCount::get()
	{
		return InternalSplitChoiceStructPointer->BackCount;
	}

	void AABTreeNodeClass::SplitChoiceStruct::BackCount::set(int value)
	{
		InternalSplitChoiceStructPointer->BackCount = value;
	}

	MinMaxAABoxClass AABTreeNodeClass::SplitChoiceStruct::FrontBox::get()
	{
		MinMaxAABoxClass result;

		MinMaxAABoxClass::UnmanagedToManagedMinMaxAABoxClass(InternalSplitChoiceStructPointer->FrontBox, result);

		return result;
	}

	void AABTreeNodeClass::SplitChoiceStruct::FrontBox::set(MinMaxAABoxClass value)
	{
		MinMaxAABoxClass::ManagedToUnmanagedMinMaxAABoxClass(value, InternalSplitChoiceStructPointer->FrontBox);
	}

	MinMaxAABoxClass AABTreeNodeClass::SplitChoiceStruct::BackBox::get()
	{
		MinMaxAABoxClass result;

		MinMaxAABoxClass::UnmanagedToManagedMinMaxAABoxClass(InternalSplitChoiceStructPointer->BackBox, result);

		return result;
	}

	void AABTreeNodeClass::SplitChoiceStruct::BackBox::set(MinMaxAABoxClass value)
	{
		MinMaxAABoxClass::ManagedToUnmanagedMinMaxAABoxClass(value, InternalSplitChoiceStructPointer->BackBox);
	}

	AAPlaneClass AABTreeNodeClass::SplitChoiceStruct::Plane::get()
	{
		AAPlaneClass result;

		AAPlaneClass::UnmanagedToManagedAAPlaneClass(InternalSplitChoiceStructPointer->Plane, result);

		return result;
	}

	void AABTreeNodeClass::SplitChoiceStruct::Plane::set(AAPlaneClass value)
	{
		AAPlaneClass::ManagedToUnmanagedAAPlaneClass(value, InternalSplitChoiceStructPointer->Plane);
	}

	bool AABTreeNodeClass::SplitChoiceStruct::InternalDestroyPointer()
	{
		Imports::DestroyAABTreeNodeClassSplitChoiceStruct(InternalSplitChoiceStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::AABTreeNodeClass::SplitChoiceStruct* AABTreeNodeClass::SplitChoiceStruct::InternalSplitChoiceStructPointer::get()
	{
		return reinterpret_cast<::AABTreeNodeClass::SplitChoiceStruct*>(Pointer.ToPointer());
	}

	AABTreeNodeClass::AABTreeNodeClass(IntPtr pointer)
		: AutoPoolClass<IAABTreeNodeClass^>(pointer)
	{

	}

	bool AABTreeNodeClass::Equals(System::Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IAABTreeNodeClass^ otherThis = dynamic_cast<IAABTreeNodeClass^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return AABTreeNodeClassPointer.Equals(otherThis->AABTreeNodeClassPointer);
	}

	IntPtr AABTreeNodeClass::AABTreeNodeClassPointer::get()
	{
		return IntPtr(InternalAABTreeNodeClassPointer);
	}

	IntPtr AABTreeNodeClass::AABTreeNodeClassAutoPoolClassPointer::get()
	{
		return IntPtr(InternalAABTreeNodeClassAutoPoolClassPointer);
	}

	uint32 AABTreeNodeClass::Index::get()
	{
		return InternalAABTreeNodeClassPointer->Index;
	}

	void AABTreeNodeClass::Index::set(uint32 value)
	{
		InternalAABTreeNodeClassPointer->Index = value;
	}

	AABoxClass AABTreeNodeClass::Box::get()
	{
		AABoxClass result;

		AABoxClass::UnmanagedToManagedAABoxClass(InternalAABTreeNodeClassPointer->Box, result);

		return result;
	}

	void AABTreeNodeClass::Box::set(AABoxClass value)
	{
		AABoxClass::ManagedToUnmanagedAABoxClass(value, InternalAABTreeNodeClassPointer->Box);
	}

	IAABTreeNodeClass^ AABTreeNodeClass::Parent::get()
	{
		auto result = InternalAABTreeNodeClassPointer->Parent;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew AABTreeNodeClass(IntPtr(result));
		}
	}

	void AABTreeNodeClass::Parent::set(IAABTreeNodeClass^ value)
	{
		if (value == nullptr || value->AABTreeNodeClassPointer.ToPointer() == nullptr)
		{
			InternalAABTreeNodeClassPointer->Parent = nullptr;
		}
		else
		{
			InternalAABTreeNodeClassPointer->Parent = reinterpret_cast<::AABTreeNodeClass*>(value->AABTreeNodeClassPointer.ToPointer());
		}
	}

	IAABTreeNodeClass^ AABTreeNodeClass::Front::get()
	{
		auto result = InternalAABTreeNodeClassPointer->Front;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew AABTreeNodeClass(IntPtr(result));
		}
	}

	void AABTreeNodeClass::Front::set(IAABTreeNodeClass^ value)
	{
		if (value == nullptr || value->AABTreeNodeClassPointer.ToPointer() == nullptr)
		{
			InternalAABTreeNodeClassPointer->Front = nullptr;
		}
		else
		{
			InternalAABTreeNodeClassPointer->Front = reinterpret_cast<::AABTreeNodeClass*>(value->AABTreeNodeClassPointer.ToPointer());
		}
	}

	IAABTreeNodeClass^ AABTreeNodeClass::Back::get()
	{
		auto result = InternalAABTreeNodeClassPointer->Back;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew AABTreeNodeClass(IntPtr(result));
		}
	}

	void AABTreeNodeClass::Back::set(IAABTreeNodeClass^ value)
	{
		if (value == nullptr || value->AABTreeNodeClassPointer.ToPointer() == nullptr)
		{
			InternalAABTreeNodeClassPointer->Back = nullptr;
		}
		else
		{
			InternalAABTreeNodeClassPointer->Back = reinterpret_cast<::AABTreeNodeClass*>(value->AABTreeNodeClassPointer.ToPointer());
		}
	}

	ICullableClass^ AABTreeNodeClass::Object::get()
	{
		auto result = InternalAABTreeNodeClassPointer->Object;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew CullableClass(IntPtr(result));
		}
	}

	void AABTreeNodeClass::Object::set(ICullableClass^ value)
	{
		if (value == nullptr || value->CullableClassPointer.ToPointer() == nullptr)
		{
			InternalAABTreeNodeClassPointer->Object = nullptr;
		}
		else
		{
			InternalAABTreeNodeClassPointer->Object = reinterpret_cast<::CullableClass*>(value->CullableClassPointer.ToPointer());
		}
	}

	uint32 AABTreeNodeClass::UserData::get()
	{
		return InternalAABTreeNodeClassPointer->UserData;
	}

	void AABTreeNodeClass::UserData::set(uint32 value)
	{
		InternalAABTreeNodeClassPointer->UserData = value;
	}

	::AutoPoolClass<::AABTreeNodeClass, 256>* AABTreeNodeClass::InternalAABTreeNodeClassAutoPoolClassPointer::get()
	{
		return InternalAABTreeNodeClassPointer;
	}

	::AABTreeNodeClass* AABTreeNodeClass::InternalAABTreeNodeClassPointer::get()
	{
		return reinterpret_cast<::AABTreeNodeClass*>(Pointer.ToPointer());
	}

	AABTreeLinkClass::AABTreeLinkClass(IAABTreeCullSystemClass^ system)
	{
		::AABTreeCullSystemClass* systemPtr;
		if (system == nullptr || system->AABTreeCullSystemClassPointer.ToPointer())
		{
			systemPtr = nullptr;
		}
		else
		{
			systemPtr = reinterpret_cast<::AABTreeCullSystemClass*>(system->AABTreeCullSystemClassPointer.ToPointer());
		}

		Pointer = IntPtr(Imports::CreateAABTreeLinkClass(systemPtr));
	}

	AABTreeLinkClass::AABTreeLinkClass(IntPtr pointer)
		: CullLinkClass(pointer)
	{

	}

	IUnmanagedContainer<IAABTreeLinkClass^>^ AABTreeLinkClass::CreateAABTreeLinkClass(IAABTreeCullSystemClass^ system)
	{
		return gcnew UnmanagedContainer<IAABTreeLinkClass^>(gcnew AABTreeLinkClass(system));
	}

	IntPtr AABTreeLinkClass::AABTreeLinkClassPointer::get()
	{
		return IntPtr(InternalAABTreeLinkClassPointer);
	}

	IntPtr AABTreeLinkClass::AABTreeLinkClassAutoPoolClassPointer::get()
	{
		return IntPtr(InternalAABTreeLinkClassAutoPoolClassPointer);
	}

	IAABTreeNodeClass^ AABTreeLinkClass::Node::get()
	{
		auto result = InternalAABTreeLinkClassPointer->Node;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew AABTreeNodeClass(IntPtr(result));
		}
	}

	void AABTreeLinkClass::Node::set(IAABTreeNodeClass^ value)
	{
		if (value == nullptr || value->AABTreeNodeClassPointer.ToPointer() == nullptr)
		{
			InternalAABTreeLinkClassPointer->Node = nullptr;
		}
		else
		{
			InternalAABTreeLinkClassPointer->Node = reinterpret_cast<::AABTreeNodeClass*>(value->AABTreeNodeClassPointer.ToPointer());
		}
	}

	ICullableClass^ AABTreeLinkClass::NextObject::get()
	{
		auto result = InternalAABTreeLinkClassPointer->NextObject;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew CullableClass(IntPtr(result));
		}
	}

	void AABTreeLinkClass::NextObject::set(ICullableClass^ value)
	{
		if (value == nullptr || value->CullableClassPointer.ToPointer() == nullptr)
		{
			InternalAABTreeLinkClassPointer->NextObject = nullptr;
		}
		else
		{
			InternalAABTreeLinkClassPointer->NextObject = reinterpret_cast<::CullableClass*>(value->CullableClassPointer.ToPointer());
		}
	}

	::CullLinkClass* AABTreeLinkClass::InternalCullLinkClassPointer::get()
	{
		return InternalAABTreeLinkClassPointer;
	}

	::AutoPoolClass<::AABTreeLinkClass, 256>* AABTreeLinkClass::InternalAABTreeLinkClassAutoPoolClassPointer::get()
	{
		return InternalAABTreeLinkClassPointer;
	}

	::AABTreeLinkClass* AABTreeLinkClass::InternalAABTreeLinkClassPointer::get()
	{
		return reinterpret_cast<::AABTreeLinkClass*>(Pointer.ToPointer());
	}
}