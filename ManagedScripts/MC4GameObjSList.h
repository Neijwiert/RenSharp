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

#pragma once

#include "MSList.h"

#pragma managed(push, off)

class C4GameObj;

#pragma managed(pop)

namespace RenSharp
{
	interface class IC4GameObj;

	public ref class C4GameObjSLNode : public SLNode<IC4GameObj ^>
	{
		public:
			C4GameObjSLNode(IntPtr pointer);

			void SetNext(ISLNode<IC4GameObj ^> ^next) override sealed;

			property IntPtr C4GameObjSLNodePointer
			{
				IntPtr get();
			}

			property ISLNode<IC4GameObj ^> ^Next
			{
				ISLNode<IC4GameObj ^> ^get() override sealed;
			}

			property IC4GameObj ^Data
			{
				IC4GameObj ^get() override sealed;
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

			property ::SLNode<::C4GameObj> *InternalC4GameObjSLNodePointer
			{
				virtual ::SLNode<::C4GameObj> *get();
			}
	};

	public ref class C4GameObjSList : public SList<IC4GameObj ^>
	{
		private:
			C4GameObjSList();

		public:
			C4GameObjSList(IntPtr pointer);

			static IUnmanagedContainer<ISList<IC4GameObj ^> ^> ^CreateC4GameObjSList();

			bool AddHead(IC4GameObj ^data) override sealed;
			bool AddHead(ISList<IC4GameObj ^> ^list) override sealed;
			bool AddTail(IC4GameObj ^data) override sealed;
			bool AddTail(ISList<IC4GameObj ^> ^list) override sealed;
			IC4GameObj ^RemoveHead() override sealed;
			IC4GameObj ^RemoveTail() override sealed;
			bool Remove(IC4GameObj ^data) override;
			void RemoveAll() override sealed;
			bool InsertBefore(IC4GameObj ^newNode, IC4GameObj ^oldNode) override sealed;
			bool InsertAfter(IC4GameObj ^newNode, IC4GameObj ^oldNode) override sealed;
			ISLNode<IC4GameObj ^> ^FindNode(IC4GameObj ^data) override sealed;
			void InsertBefore(IC4GameObj ^data, ISLNode<IC4GameObj ^> ^node) override sealed;
			void InsertAfter(IC4GameObj ^data, ISLNode<IC4GameObj ^> ^node) override sealed;

			property IntPtr C4GameObjSListPointer
			{
				IntPtr get();
			}

			property bool IsEmpty
			{
				bool get() override sealed;
			}

			property ISLNode<IC4GameObj ^> ^Head
			{
				ISLNode<IC4GameObj ^> ^get() override sealed;
			}

			property ISLNode<IC4GameObj ^> ^Tail
			{
				ISLNode<IC4GameObj ^> ^get() override sealed;
			}

			property int Count
			{
				int get() override;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::SList<::C4GameObj> *InternalC4GameObjSListPointer
			{
				virtual ::SList<::C4GameObj> *get();
			}
	};
}