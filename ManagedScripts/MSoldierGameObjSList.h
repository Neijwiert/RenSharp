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

class SoldierGameObj;

#pragma managed(pop)

namespace RenSharp
{
	interface class ISoldierGameObj;

	public ref class SoldierGameObjSLNode : public SLNode<ISoldierGameObj ^>
	{
		public:
			SoldierGameObjSLNode(IntPtr pointer);

			void SetNext(ISLNode<ISoldierGameObj ^> ^next) override sealed;

			property IntPtr SoldierGameObjSLNodePointer
			{
				IntPtr get();
			}

			property ISLNode<ISoldierGameObj ^> ^Next
			{
				ISLNode<ISoldierGameObj ^> ^get() override sealed;
			}

			property ISoldierGameObj ^Data
			{
				ISoldierGameObj ^get() override sealed;
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

			property ::SLNode<::SoldierGameObj> *InternalSoldierGameObjSLNodePointer
			{
				virtual ::SLNode<::SoldierGameObj> *get();
			}
	};

	public ref class SoldierGameObjSList : public SList<ISoldierGameObj ^>
	{
		private:
			SoldierGameObjSList();

		public:
			SoldierGameObjSList(IntPtr pointer);

			static IUnmanagedContainer<ISList<ISoldierGameObj ^> ^> ^CreateSoldierGameObjSList();

			bool AddHead(ISoldierGameObj ^data) override sealed;
			bool AddHead(ISList<ISoldierGameObj ^> ^list) override sealed;
			bool AddTail(ISoldierGameObj ^data) override sealed;
			bool AddTail(ISList<ISoldierGameObj ^> ^list) override sealed;
			ISoldierGameObj ^RemoveHead() override sealed;
			ISoldierGameObj ^RemoveTail() override sealed;
			bool Remove(ISoldierGameObj ^data) override;
			void RemoveAll() override sealed;
			bool InsertBefore(ISoldierGameObj ^newNode, ISoldierGameObj ^oldNode) override sealed;
			bool InsertAfter(ISoldierGameObj ^newNode, ISoldierGameObj ^oldNode) override sealed;
			ISLNode<ISoldierGameObj ^> ^FindNode(ISoldierGameObj ^data) override sealed;
			void InsertBefore(ISoldierGameObj ^data, ISLNode<ISoldierGameObj ^> ^node) override sealed;
			void InsertAfter(ISoldierGameObj ^data, ISLNode<ISoldierGameObj ^> ^node) override sealed;

			property IntPtr SoldierGameObjSListPointer
			{
				IntPtr get();
			}

			property bool IsEmpty
			{
				bool get() override sealed;
			}

			property ISLNode<ISoldierGameObj ^> ^Head
			{
				ISLNode<ISoldierGameObj ^> ^get() override sealed;
			}

			property ISLNode<ISoldierGameObj ^> ^Tail
			{
				ISLNode<ISoldierGameObj ^> ^get() override sealed;
			}

			property int Count
			{
				int get() override;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::SList<::SoldierGameObj> *InternalSoldierGameObjSListPointer
			{
				virtual ::SList<::SoldierGameObj> *get();
			}
	};
}