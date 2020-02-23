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

class BaseGameObj;

#pragma managed(pop)

namespace RenSharp
{
	interface class IBaseGameObj;

	public ref class BaseGameObjSLNode : public SLNode<IBaseGameObj ^>
	{
		public:
			BaseGameObjSLNode(IntPtr pointer);

			void SetNext(ISLNode<IBaseGameObj ^> ^next) override sealed;

			property IntPtr BaseGameObjSLNodePointer
			{
				IntPtr get();
			}

			property ISLNode<IBaseGameObj ^> ^Next
			{
				ISLNode<IBaseGameObj ^> ^get() override sealed;
			}

			property IBaseGameObj ^Data
			{
				IBaseGameObj ^get() override sealed;
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

			property ::SLNode<::BaseGameObj> *InternalBaseGameObjSLNodePointer
			{
				virtual ::SLNode<::BaseGameObj> *get();
			}
	};

	public ref class BaseGameObjSList : public SList<IBaseGameObj ^>
	{
		private:
			BaseGameObjSList();

		public:
			BaseGameObjSList(IntPtr pointer);

			static IUnmanagedContainer<ISList<IBaseGameObj ^> ^> ^CreateBaseGameObjSList();

			bool AddHead(IBaseGameObj ^data) override sealed;
			bool AddHead(ISList<IBaseGameObj ^> ^list) override sealed;
			bool AddTail(IBaseGameObj ^data) override sealed;
			bool AddTail(ISList<IBaseGameObj ^> ^list) override sealed;
			IBaseGameObj ^RemoveHead() override sealed;
			IBaseGameObj ^RemoveTail() override sealed;
			bool Remove(IBaseGameObj ^data) override;
			void RemoveAll() override sealed;
			bool InsertBefore(IBaseGameObj ^newNode, IBaseGameObj ^oldNode) override sealed;
			bool InsertAfter(IBaseGameObj ^newNode, IBaseGameObj ^oldNode) override sealed;
			ISLNode<IBaseGameObj ^> ^FindNode(IBaseGameObj ^data) override sealed;
			void InsertBefore(IBaseGameObj ^data, ISLNode<IBaseGameObj ^> ^node) override sealed;
			void InsertAfter(IBaseGameObj ^data, ISLNode<IBaseGameObj ^> ^node) override sealed;

			property IntPtr BaseGameObjSListPointer
			{
				IntPtr get();
			}

			property bool IsEmpty
			{
				bool get() override sealed;
			}

			property ISLNode<IBaseGameObj ^> ^Head
			{
				ISLNode<IBaseGameObj ^> ^get() override sealed;
			}

			property ISLNode<IBaseGameObj ^> ^Tail
			{
				ISLNode<IBaseGameObj ^> ^get() override sealed;
			}

			property int Count
			{
				int get() override;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::SList<::BaseGameObj> *InternalBaseGameObjSListPointer
			{
				virtual ::SList<::BaseGameObj> *get();
			}
	};
}