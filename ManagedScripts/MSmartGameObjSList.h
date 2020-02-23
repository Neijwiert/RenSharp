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

class SmartGameObj;

#pragma managed(pop)

namespace RenSharp
{
	interface class ISmartGameObj;

	public ref class SmartGameObjSLNode : public SLNode<ISmartGameObj ^>
	{
		public:
			SmartGameObjSLNode(IntPtr pointer);

			void SetNext(ISLNode<ISmartGameObj ^> ^next) override sealed;

			property IntPtr SmartGameObjSLNodePointer
			{
				IntPtr get();
			}

			property ISLNode<ISmartGameObj ^> ^Next
			{
				ISLNode<ISmartGameObj ^> ^get() override sealed;
			}

			property ISmartGameObj ^Data
			{
				ISmartGameObj ^get() override sealed;
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

			property ::SLNode<::SmartGameObj> *InternalSmartGameObjSLNodePointer
			{
				virtual ::SLNode<::SmartGameObj> *get();
			}
	};

	public ref class SmartGameObjSList : public SList<ISmartGameObj ^>
	{
		private:
			SmartGameObjSList();

		public:
			SmartGameObjSList(IntPtr pointer);

			static IUnmanagedContainer<ISList<ISmartGameObj ^> ^> ^CreateSmartGameObjSList();

			bool AddHead(ISmartGameObj ^data) override sealed;
			bool AddHead(ISList<ISmartGameObj ^> ^list) override sealed;
			bool AddTail(ISmartGameObj ^data) override sealed;
			bool AddTail(ISList<ISmartGameObj ^> ^list) override sealed;
			ISmartGameObj ^RemoveHead() override sealed;
			ISmartGameObj ^RemoveTail() override sealed;
			bool Remove(ISmartGameObj ^data) override;
			void RemoveAll() override sealed;
			bool InsertBefore(ISmartGameObj ^newNode, ISmartGameObj ^oldNode) override sealed;
			bool InsertAfter(ISmartGameObj ^newNode, ISmartGameObj ^oldNode) override sealed;
			ISLNode<ISmartGameObj ^> ^FindNode(ISmartGameObj ^data) override sealed;
			void InsertBefore(ISmartGameObj ^data, ISLNode<ISmartGameObj ^> ^node) override sealed;
			void InsertAfter(ISmartGameObj ^data, ISLNode<ISmartGameObj ^> ^node) override sealed;

			property IntPtr SmartGameObjSListPointer
			{
				IntPtr get();
			}

			property bool IsEmpty
			{
				bool get() override sealed;
			}

			property ISLNode<ISmartGameObj ^> ^Head
			{
				ISLNode<ISmartGameObj ^> ^get() override sealed;
			}

			property ISLNode<ISmartGameObj ^> ^Tail
			{
				ISLNode<ISmartGameObj ^> ^get() override sealed;
			}

			property int Count
			{
				int get() override;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::SList<::SmartGameObj> *InternalSmartGameObjSListPointer
			{
				virtual ::SList<::SmartGameObj> *get();
			}
	};
}