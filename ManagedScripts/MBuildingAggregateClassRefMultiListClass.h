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
#include "MBuildingAggregateClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <BuildingAggregateClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	public ref class BuildingAggregateClassRefMultiListClass : public RefMultiListClass<IBuildingAggregateClass ^>
	{
		private:
			BuildingAggregateClassRefMultiListClass();

		public:
			BuildingAggregateClassRefMultiListClass(IntPtr pointer);

			static IUnmanagedContainer<IRefMultiListClass<IBuildingAggregateClass ^> ^> ^CreateBuildingAggregateClassRefMultiListClass();

			bool Contains(IBuildingAggregateClass ^obj) override;
			bool Add(IBuildingAggregateClass ^obj, bool onlyOnce) override;
			bool AddTail(IBuildingAggregateClass ^obj, bool onlyOnce) override sealed;
			bool AddTail(IBuildingAggregateClass ^obj) override sealed;
			bool AddAfter(IBuildingAggregateClass ^obj, IBuildingAggregateClass ^existingListMember, bool onlyOnce) override sealed;
			bool AddAfter(IBuildingAggregateClass ^obj, IBuildingAggregateClass ^existingListMember) override sealed;
			bool ReleaseHead() override sealed;
			IBuildingAggregateClass ^GetHead() override sealed;
			IBuildingAggregateClass ^PeekHead() override sealed;
			IBuildingAggregateClass ^RemoveHead() override sealed;
			void ResetList() override sealed;
			bool Remove(IBuildingAggregateClass ^item) override;

			property IntPtr BuildingAggregateClassRefMultiListClassPointer
			{
				IntPtr get();
			}

			property IUnmanagedContainer<IRefMultiListIterator<IBuildingAggregateClass ^> ^> ^Iterator
			{
				IUnmanagedContainer<IRefMultiListIterator<IBuildingAggregateClass ^> ^> ^get() override sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::GenericMultiListClass* InternalGenericMultiListClassPointer
			{
				::GenericMultiListClass* get() override;
			}

			property ::RefMultiListClass<::BuildingAggregateClass> *InternalBuildingAggregateClassRefMultiListClassPointer
			{
				virtual ::RefMultiListClass<::BuildingAggregateClass> *get();
			}
	};

	public ref class BuildingAggregateClassRefMultiListIterator : public RefMultiListIterator<IBuildingAggregateClass ^>
	{
		private:
			BuildingAggregateClassRefMultiListIterator(IRefMultiListClass<IBuildingAggregateClass ^> ^list);

		public:
			BuildingAggregateClassRefMultiListIterator(IntPtr pointer);

			static IUnmanagedContainer<IRefMultiListIterator<IBuildingAggregateClass ^> ^> ^CreateBuildingAggregateClassRefMultiListIterator(
				IRefMultiListClass<IBuildingAggregateClass ^> ^list);

			IBuildingAggregateClass ^GetObj() override sealed;
			IBuildingAggregateClass ^PeekObj() override sealed;
			void RemoveCurrentObject() override sealed;

			property IntPtr BuildingAggregateClassRefMultiListIteratorPointer
			{
				IntPtr get();
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::RefMultiListIterator<::BuildingAggregateClass> *InternalBuildingAggregateClassRefMultiListIteratorPointer
			{
				virtual ::RefMultiListIterator<::BuildingAggregateClass> *get();
			}
	};
}