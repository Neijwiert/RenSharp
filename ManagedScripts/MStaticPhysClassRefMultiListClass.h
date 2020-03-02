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
#include "MStaticPhysClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <StaticPhysClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	public ref class StaticPhysClassRefMultiListClass : public RefMultiListClass<IStaticPhysClass ^>
	{
		private:
			StaticPhysClassRefMultiListClass();

		public:
			StaticPhysClassRefMultiListClass(IntPtr pointer);

			static IUnmanagedContainer<IRefMultiListClass<IStaticPhysClass ^> ^> ^CreateStaticPhysClassRefMultiListClass();

			bool Contains(IStaticPhysClass ^obj) override;
			bool Add(IStaticPhysClass ^obj, bool onlyOnce) override;
			bool AddTail(IStaticPhysClass ^obj, bool onlyOnce) override sealed;
			bool AddTail(IStaticPhysClass ^obj) override sealed;
			bool AddAfter(IStaticPhysClass ^obj, IStaticPhysClass ^existingListMember, bool onlyOnce) override sealed;
			bool AddAfter(IStaticPhysClass ^obj, IStaticPhysClass ^existingListMember) override sealed;
			bool ReleaseHead() override sealed;
			IStaticPhysClass ^GetHead() override sealed;
			IStaticPhysClass ^PeekHead() override sealed;
			IStaticPhysClass ^RemoveHead() override sealed;
			void ResetList() override sealed;
			bool Remove(IStaticPhysClass ^item) override;

			property IntPtr StaticPhysClassRefMultiListClassPointer
			{
				IntPtr get();
			}

			property IUnmanagedContainer<IRefMultiListIterator<IStaticPhysClass ^> ^> ^Iterator
			{
				IUnmanagedContainer<IRefMultiListIterator<IStaticPhysClass ^> ^> ^get() override sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::GenericMultiListClass* InternalGenericMultiListClassPointer
			{
				::GenericMultiListClass* get() override;
			}

			property ::RefMultiListClass<::StaticPhysClass> *InternalStaticPhysClassRefMultiListClassPointer
			{
				virtual ::RefMultiListClass<::StaticPhysClass> *get();
			}
	};

	public ref class StaticPhysClassRefMultiListIterator : public RefMultiListIterator<IStaticPhysClass ^>
	{
		private:
			StaticPhysClassRefMultiListIterator(IRefMultiListClass<IStaticPhysClass ^> ^list);

		public:
			StaticPhysClassRefMultiListIterator(IntPtr pointer);

			static IUnmanagedContainer<IRefMultiListIterator<IStaticPhysClass ^> ^> ^CreateStaticPhysClassRefMultiListIterator(
				IRefMultiListClass<IStaticPhysClass ^> ^list);

			IStaticPhysClass ^GetObj() override sealed;
			IStaticPhysClass ^PeekObj() override sealed;
			void RemoveCurrentObject() override sealed;

			property IntPtr StaticPhysClassRefMultiListIteratorPointer
			{
				IntPtr get();
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::RefMultiListIterator<::StaticPhysClass> *InternalStaticPhysClassRefMultiListIteratorPointer
			{
				virtual ::RefMultiListIterator<::StaticPhysClass> *get();
			}
	};
}