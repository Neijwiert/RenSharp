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
#include "MVisTableClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <VisTableClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	public ref class VisTableClassMultiListClass : public MultiListClass<IVisTableClass ^>
	{
		private:
			VisTableClassMultiListClass();

		public:
			VisTableClassMultiListClass(IntPtr pointer);

			static IUnmanagedContainer<IMultiListClass<IVisTableClass ^> ^> ^CreateVisTableClassMultiListClass();

			bool Contains(IVisTableClass ^obj) override;
			bool Add(IVisTableClass ^obj, bool onlyOnce) override;
			bool AddTail(IVisTableClass ^obj, bool onlyOnce) override sealed;
			bool AddTail(IVisTableClass ^obj) override sealed;
			bool AddAfter(IVisTableClass ^obj, IVisTableClass ^existingListMember, bool onlyOnce) override sealed;
			bool AddAfter(IVisTableClass ^obj, IVisTableClass ^existingListMember) override sealed;
			IVisTableClass ^GetHead() override sealed;
			IVisTableClass ^PeekHead() override sealed;
			IVisTableClass ^RemoveHead() override sealed;
			void ResetList() override sealed;
			bool Remove(IVisTableClass ^item) override;

			property IntPtr VisTableClassMultiListClassPointer
			{
				IntPtr get();
			}

			property IUnmanagedContainer<IMultiListIterator<IVisTableClass ^> ^> ^Iterator
			{
				IUnmanagedContainer<IMultiListIterator<IVisTableClass ^> ^> ^get() override sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::MultiListClass<::VisTableClass> *InternalVisTableClassMultiListClassPointer
			{
				virtual ::MultiListClass<::VisTableClass> *get();
			}
	};

	public ref class VisTableClassMultiListIterator : public MultiListIterator<IVisTableClass ^>
	{
		private:
			VisTableClassMultiListIterator(IMultiListClass<IVisTableClass ^> ^list);

		public:
			VisTableClassMultiListIterator(IntPtr pointer);

			static IUnmanagedContainer<IMultiListIterator<IVisTableClass ^> ^> ^CreateVisTableClassMultiListIterator(
				IMultiListClass<IVisTableClass ^> ^list);

			IVisTableClass ^GetObj() override sealed;
			IVisTableClass ^PeekObj() override sealed;
			void RemoveCurrentObject() override sealed;

			property IntPtr VisTableClassMultiListIteratorPointer
			{
				IntPtr get();
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::MultiListIterator<::VisTableClass> *InternalVisTableClassMultiListIteratorPointer
			{
				virtual ::MultiListIterator<::VisTableClass> *get();
			}
	};
}