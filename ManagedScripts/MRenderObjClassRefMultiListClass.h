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

#include "Mmultilist.h"
#include "MRenderObjClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <RenderObjClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	public ref class RenderObjClassRefMultiListClass : public RefMultiListClass<IRenderObjClass ^>
	{
		private:
			RenderObjClassRefMultiListClass();

		public:
			RenderObjClassRefMultiListClass(IntPtr pointer);

			static IUnmanagedContainer<IRefMultiListClass<IRenderObjClass ^> ^> ^CreateRenderObjClassRefMultiListClass();

			bool Contains(IRenderObjClass ^obj) override;
			bool Add(IRenderObjClass ^obj, bool onlyOnce) override;
			bool AddTail(IRenderObjClass ^obj, bool onlyOnce) override sealed;
			bool AddTail(IRenderObjClass ^obj) override sealed;
			bool AddAfter(IRenderObjClass ^obj, IRenderObjClass ^existingListMember, bool onlyOnce) override sealed;
			bool AddAfter(IRenderObjClass ^obj, IRenderObjClass ^existingListMember) override sealed;
			bool ReleaseHead() override sealed;
			IRenderObjClass ^GetHead() override sealed;
			IRenderObjClass ^PeekHead() override sealed;
			IRenderObjClass ^RemoveHead() override sealed;
			void ResetList() override sealed;
			bool Remove(IRenderObjClass ^item) override;

			property IntPtr RenderObjClassRefMultiListClassPointer
			{
				IntPtr get();
			}

			property IUnmanagedContainer<IRefMultiListIterator<IRenderObjClass ^> ^> ^Iterator
			{
				IUnmanagedContainer<IRefMultiListIterator<IRenderObjClass ^> ^> ^get() override sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::RefMultiListClass<::RenderObjClass> *InternalRenderObjClassRefMultiListClassPointer
			{
				virtual ::RefMultiListClass<::RenderObjClass> *get();
			}
	};

	public ref class RenderObjClassRefMultiListIterator : public RefMultiListIterator<IRenderObjClass ^>
	{
		private:
			RenderObjClassRefMultiListIterator(IRefMultiListClass<IRenderObjClass ^> ^list);

		public:
			RenderObjClassRefMultiListIterator(IntPtr pointer);

			static IUnmanagedContainer<IRefMultiListIterator<IRenderObjClass ^> ^> ^CreateRenderObjClassRefMultiListIterator(
				IRefMultiListClass<IRenderObjClass ^> ^list);

			IRenderObjClass ^GetObj() override sealed;
			IRenderObjClass ^PeekObj() override sealed;
			void RemoveCurrentObject() override sealed;

			property IntPtr RenderObjClassRefMultiListIteratorPointer
			{
				IntPtr get();
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::RefMultiListIterator<::RenderObjClass> *InternalRenderObjClassRefMultiListIteratorPointer
			{
				virtual ::RefMultiListIterator<::RenderObjClass> *get();
			}
	};
}