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

#pragma once

#include "MSList.h"

#pragma managed(push, off)

class BuildingGameObj;

#pragma managed(pop)

namespace RenSharp
{
	interface class IBuildingGameObj;

	public ref class BuildingGameObjSLNode : public SLNode<IBuildingGameObj ^>
	{
		public:
			BuildingGameObjSLNode(IntPtr pointer);

			void SetNext(ISLNode<IBuildingGameObj ^> ^next) override sealed;

			property IntPtr BuildingGameObjSLNodePointer
			{
				IntPtr get();
			}

			property ISLNode<IBuildingGameObj ^> ^Next
			{
				ISLNode<IBuildingGameObj ^> ^get() override sealed;
			}

			property IBuildingGameObj ^Data
			{
				IBuildingGameObj ^get() override sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::AutoPoolClass<::GenericSLNode, 256> *InternalAutoPoolClassPointer
			{
				::AutoPoolClass<::GenericSLNode, 256> *get() override;
			}

			property ::GenericSLNode *InternalGenericSLNodePointer
			{
				::GenericSLNode *get() override;
			}

			property ::SLNode<::BuildingGameObj> *InternalBuildingGameObjSLNodePointer
			{
				virtual ::SLNode<::BuildingGameObj> *get();
			}
	};

	public ref class BuildingGameObjSList : public SList<IBuildingGameObj ^>
	{
		private:
			BuildingGameObjSList();

		public:
			BuildingGameObjSList(IntPtr pointer);

			static IUnmanagedContainer<ISList<IBuildingGameObj ^> ^> ^CreateBuildingGameObjSList();

			bool AddHead(IBuildingGameObj ^data) override sealed;
			bool AddHead(ISList<IBuildingGameObj ^> ^list) override sealed;
			bool AddTail(IBuildingGameObj ^data) override sealed;
			bool AddTail(ISList<IBuildingGameObj ^> ^list) override sealed;
			IBuildingGameObj ^RemoveHead() override sealed;
			IBuildingGameObj ^RemoveTail() override sealed;
			bool Remove(IBuildingGameObj ^data) override;
			void RemoveAll() override sealed;
			bool InsertBefore(IBuildingGameObj ^newNode, IBuildingGameObj ^oldNode) override sealed;
			bool InsertAfter(IBuildingGameObj ^newNode, IBuildingGameObj ^oldNode) override sealed;
			ISLNode<IBuildingGameObj ^> ^FindNode(IBuildingGameObj ^data) override sealed;
			void InsertBefore(IBuildingGameObj ^data, ISLNode<IBuildingGameObj ^> ^node) override sealed;
			void InsertAfter(IBuildingGameObj ^data, ISLNode<IBuildingGameObj ^> ^node) override sealed;

			property IntPtr BuildingGameObjSListPointer
			{
				IntPtr get();
			}

			property bool IsEmpty
			{
				bool get() override sealed;
			}

			property ISLNode<IBuildingGameObj ^> ^Head
			{
				ISLNode<IBuildingGameObj ^> ^get() override sealed;
			}

			property ISLNode<IBuildingGameObj ^> ^Tail
			{
				ISLNode<IBuildingGameObj ^> ^get() override sealed;
			}

			property int Count
			{
				int get() override;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::SList<::BuildingGameObj> *InternalBuildingGameObjSListPointer
			{
				virtual ::SList<::BuildingGameObj> *get();
			}
	};
}