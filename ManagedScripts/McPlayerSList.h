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

class cPlayer;

#pragma managed(pop)

namespace RenSharp
{
	interface class IcPlayer;

	public ref class cPlayerSLNode : public SLNode<IcPlayer ^>
	{
		public:
			cPlayerSLNode(IntPtr pointer);

			void SetNext(ISLNode<IcPlayer ^> ^next) override sealed;

			property IntPtr cPlayerSLNodePointer
			{
				IntPtr get();
			}

			property ISLNode<IcPlayer ^> ^Next
			{
				ISLNode<IcPlayer ^> ^get() override sealed;
			}

			property IcPlayer ^Data
			{
				IcPlayer ^get() override sealed;
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

			property ::SLNode<::cPlayer> *InternalcPlayerSLNodePointer
			{
				virtual ::SLNode<::cPlayer> *get();
			}
	};

	public ref class cPlayerSList : public SList<IcPlayer ^>
	{
		private:
			cPlayerSList();

		public:
			cPlayerSList(IntPtr pointer);

			static IUnmanagedContainer<ISList<IcPlayer ^> ^> ^CreatecPlayerSList();

			bool AddHead(IcPlayer ^data) override sealed;
			bool AddHead(ISList<IcPlayer ^> ^list) override sealed;
			bool AddTail(IcPlayer ^data) override sealed;
			bool AddTail(ISList<IcPlayer ^> ^list) override sealed;
			IcPlayer ^RemoveHead() override sealed;
			IcPlayer ^RemoveTail() override sealed;
			bool Remove(IcPlayer ^data) override;
			void RemoveAll() override sealed;
			bool InsertBefore(IcPlayer ^newNode, IcPlayer ^oldNode) override sealed;
			bool InsertAfter(IcPlayer ^newNode, IcPlayer ^oldNode) override sealed;
			ISLNode<IcPlayer ^> ^FindNode(IcPlayer ^data) override sealed;
			void InsertBefore(IcPlayer ^data, ISLNode<IcPlayer ^> ^node) override sealed;
			void InsertAfter(IcPlayer ^data, ISLNode<IcPlayer ^> ^node) override sealed;

			property IntPtr cPlayerSListPointer
			{
				IntPtr get();
			}

			property bool IsEmpty
			{
				bool get() override sealed;
			}

			property ISLNode<IcPlayer ^> ^Head
			{
				ISLNode<IcPlayer ^> ^get() override sealed;
			}

			property ISLNode<IcPlayer ^> ^Tail
			{
				ISLNode<IcPlayer ^> ^get() override sealed;
			}

			property int Count
			{
				int get() override;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::SList<::cPlayer> *InternalcPlayerSListPointer
			{
				virtual ::SList<::cPlayer> *get();
			}
	};
}