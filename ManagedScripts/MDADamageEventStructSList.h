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

struct DADamageEventStruct;

#pragma managed(pop)

namespace RenSharp
{
	interface class IDADamageEventStruct;

	public ref class DADamageEventStructSLNode : public SLNode<IDADamageEventStruct ^>
	{
		public:
			DADamageEventStructSLNode(IntPtr pointer);

			void SetNext(ISLNode<IDADamageEventStruct ^> ^next) override sealed;

			property IntPtr DADamageEventStructSLNodePointer
			{
				IntPtr get();
			}

			property ISLNode<IDADamageEventStruct ^> ^Next
			{
				ISLNode<IDADamageEventStruct ^> ^get() override sealed;
			}

			property IDADamageEventStruct ^Data
			{
				IDADamageEventStruct ^get() override sealed;
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

			property ::SLNode<::DADamageEventStruct> *InternalDADamageEventStructSLNodePointer
			{
				virtual ::SLNode<::DADamageEventStruct> *get();
			}
	};

	public ref class DADamageEventStructSList : public SList<IDADamageEventStruct ^>
	{
		private:
			DADamageEventStructSList();

		public:
			DADamageEventStructSList(IntPtr pointer);

			static IUnmanagedContainer<ISList<IDADamageEventStruct ^> ^> ^CreateDADamageEventStructSList();

			bool AddHead(IDADamageEventStruct ^data) override sealed;
			bool AddHead(ISList<IDADamageEventStruct ^> ^list) override sealed;
			bool AddTail(IDADamageEventStruct ^data) override sealed;
			bool AddTail(ISList<IDADamageEventStruct ^> ^list) override sealed;
			IDADamageEventStruct ^RemoveHead() override sealed;
			IDADamageEventStruct ^RemoveTail() override sealed;
			bool Remove(IDADamageEventStruct ^data) override;
			void RemoveAll() override sealed;
			bool InsertBefore(IDADamageEventStruct ^newNode, IDADamageEventStruct ^oldNode) override sealed;
			bool InsertAfter(IDADamageEventStruct ^newNode, IDADamageEventStruct ^oldNode) override sealed;
			ISLNode<IDADamageEventStruct ^> ^FindNode(IDADamageEventStruct ^data) override sealed;
			void InsertBefore(IDADamageEventStruct ^data, ISLNode<IDADamageEventStruct ^> ^node) override sealed;
			void InsertAfter(IDADamageEventStruct ^data, ISLNode<IDADamageEventStruct ^> ^node) override sealed;

			property IntPtr DADamageEventStructSListPointer
			{
				IntPtr get();
			}

			property bool IsEmpty
			{
				bool get() override sealed;
			}

			property ISLNode<IDADamageEventStruct ^> ^Head
			{
				ISLNode<IDADamageEventStruct ^> ^get() override sealed;
			}

			property ISLNode<IDADamageEventStruct ^> ^Tail
			{
				ISLNode<IDADamageEventStruct ^> ^get() override sealed;
			}

			property int Count
			{
				int get() override;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::SList<::DADamageEventStruct> *InternalDADamageEventStructSListPointer
			{
				virtual ::SList<::DADamageEventStruct> *get();
			}
	};
}