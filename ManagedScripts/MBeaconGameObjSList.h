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

class BeaconGameObj;

#pragma managed(pop)

namespace RenSharp
{
	interface class IBeaconGameObj;

	public ref class BeaconGameObjSLNode : public SLNode<IBeaconGameObj ^>
	{
		public:
			BeaconGameObjSLNode(IntPtr pointer);

			void SetNext(ISLNode<IBeaconGameObj ^> ^next) override sealed;

			property IntPtr BeaconGameObjSLNodePointer
			{
				IntPtr get();
			}

			property ISLNode<IBeaconGameObj ^> ^Next
			{
				ISLNode<IBeaconGameObj ^> ^get() override sealed;
			}

			property IBeaconGameObj ^Data
			{
				IBeaconGameObj ^get() override sealed;
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

			property ::SLNode<::BeaconGameObj> *InternalBeaconGameObjSLNodePointer
			{
				virtual ::SLNode<::BeaconGameObj> *get();
			}
	};

	public ref class BeaconGameObjSList : public SList<IBeaconGameObj ^>
	{
		private:
			BeaconGameObjSList();

		public:
			BeaconGameObjSList(IntPtr pointer);

			static IUnmanagedContainer<ISList<IBeaconGameObj ^> ^> ^CreateBeaconGameObjSList();

			bool AddHead(IBeaconGameObj ^data) override sealed;
			bool AddHead(ISList<IBeaconGameObj ^> ^list) override sealed;
			bool AddTail(IBeaconGameObj ^data) override sealed;
			bool AddTail(ISList<IBeaconGameObj ^> ^list) override sealed;
			IBeaconGameObj ^RemoveHead() override sealed;
			IBeaconGameObj ^RemoveTail() override sealed;
			bool Remove(IBeaconGameObj ^data) override;
			void RemoveAll() override sealed;
			bool InsertBefore(IBeaconGameObj ^newNode, IBeaconGameObj ^oldNode) override sealed;
			bool InsertAfter(IBeaconGameObj ^newNode, IBeaconGameObj ^oldNode) override sealed;
			ISLNode<IBeaconGameObj ^> ^FindNode(IBeaconGameObj ^data) override sealed;
			void InsertBefore(IBeaconGameObj ^data, ISLNode<IBeaconGameObj ^> ^node) override sealed;
			void InsertAfter(IBeaconGameObj ^data, ISLNode<IBeaconGameObj ^> ^node) override sealed;

			property IntPtr BeaconGameObjSListPointer
			{
				IntPtr get();
			}

			property bool IsEmpty
			{
				bool get() override sealed;
			}

			property ISLNode<IBeaconGameObj ^> ^Head
			{
				ISLNode<IBeaconGameObj ^> ^get() override sealed;
			}

			property ISLNode<IBeaconGameObj ^> ^Tail
			{
				ISLNode<IBeaconGameObj ^> ^get() override sealed;
			}

			property int Count
			{
				int get() override;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::SList<::BeaconGameObj> *InternalBeaconGameObjSListPointer
			{
				virtual ::SList<::BeaconGameObj> *get();
			}
	};
}