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

class ScriptZoneGameObj;

#pragma managed(pop)

namespace RenSharp
{
	interface class IScriptZoneGameObj;

	public ref class ScriptZoneGameObjSLNode : public SLNode<IScriptZoneGameObj ^>
	{
		public:
			ScriptZoneGameObjSLNode(IntPtr pointer);

			void SetNext(ISLNode<IScriptZoneGameObj ^> ^next) override sealed;

			property IntPtr ScriptZoneGameObjSLNodePointer
			{
				IntPtr get();
			}

			property ISLNode<IScriptZoneGameObj ^> ^Next
			{
				ISLNode<IScriptZoneGameObj ^> ^get() override sealed;
			}

			property IScriptZoneGameObj ^Data
			{
				IScriptZoneGameObj ^get() override sealed;
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

			property ::SLNode<::ScriptZoneGameObj> *InternalScriptZoneGameObjSLNodePointer
			{
				virtual ::SLNode<::ScriptZoneGameObj> *get();
			}
	};

	public ref class ScriptZoneGameObjSList : public SList<IScriptZoneGameObj ^>
	{
		private:
			ScriptZoneGameObjSList();

		public:
			ScriptZoneGameObjSList(IntPtr pointer);

			static IUnmanagedContainer<ISList<IScriptZoneGameObj ^> ^> ^CreateScriptZoneGameObjSList();

			bool AddHead(IScriptZoneGameObj ^data) override sealed;
			bool AddHead(ISList<IScriptZoneGameObj ^> ^list) override sealed;
			bool AddTail(IScriptZoneGameObj ^data) override sealed;
			bool AddTail(ISList<IScriptZoneGameObj ^> ^list) override sealed;
			IScriptZoneGameObj ^RemoveHead() override sealed;
			IScriptZoneGameObj ^RemoveTail() override sealed;
			bool Remove(IScriptZoneGameObj ^data) override;
			void RemoveAll() override sealed;
			bool InsertBefore(IScriptZoneGameObj ^newNode, IScriptZoneGameObj ^oldNode) override sealed;
			bool InsertAfter(IScriptZoneGameObj ^newNode, IScriptZoneGameObj ^oldNode) override sealed;
			ISLNode<IScriptZoneGameObj ^> ^FindNode(IScriptZoneGameObj ^data) override sealed;
			void InsertBefore(IScriptZoneGameObj ^data, ISLNode<IScriptZoneGameObj ^> ^node) override sealed;
			void InsertAfter(IScriptZoneGameObj ^data, ISLNode<IScriptZoneGameObj ^> ^node) override sealed;

			property IntPtr ScriptZoneGameObjSListPointer
			{
				IntPtr get();
			}

			property bool IsEmpty
			{
				bool get() override sealed;
			}

			property ISLNode<IScriptZoneGameObj ^> ^Head
			{
				ISLNode<IScriptZoneGameObj ^> ^get() override sealed;
			}

			property ISLNode<IScriptZoneGameObj ^> ^Tail
			{
				ISLNode<IScriptZoneGameObj ^> ^get() override sealed;
			}

			property int Count
			{
				int get() override;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::SList<::ScriptZoneGameObj> *InternalScriptZoneGameObjSListPointer
			{
				virtual ::SList<::ScriptZoneGameObj> *get();
			}
	};
}