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

#include "Mmultilist.h"
#include "MPhysClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <PhysClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	public ref class PhysClassRefMultiListClass : public RefMultiListClass<IPhysClass ^>
	{
		private:
			PhysClassRefMultiListClass();

		public:
			PhysClassRefMultiListClass(IntPtr pointer);

			static IUnmanagedContainer<IRefMultiListClass<IPhysClass ^> ^> ^CreatePhysClassRefMultiListClass();

			bool Contains(IPhysClass ^obj) override;
			bool Add(IPhysClass ^obj, bool onlyOnce) override;
			bool AddTail(IPhysClass ^obj, bool onlyOnce) override sealed;
			bool AddTail(IPhysClass ^obj) override sealed;
			bool AddAfter(IPhysClass ^obj, IPhysClass ^existingListMember, bool onlyOnce) override sealed;
			bool AddAfter(IPhysClass ^obj, IPhysClass ^existingListMember) override sealed;
			bool ReleaseHead() override sealed;
			IPhysClass ^GetHead() override sealed;
			IPhysClass ^PeekHead() override sealed;
			IPhysClass ^RemoveHead() override sealed;
			void ResetList() override sealed;
			bool Remove(IPhysClass ^item) override;

			property IntPtr PhysClassRefMultiListClassPointer
			{
				IntPtr get();
			}

			property IUnmanagedContainer<IRefMultiListIterator<IPhysClass ^> ^> ^Iterator
			{
				IUnmanagedContainer<IRefMultiListIterator<IPhysClass ^> ^> ^get() override sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::RefMultiListClass<::PhysClass> *InternalPhysClassRefMultiListClassPointer
			{
				virtual ::RefMultiListClass<::PhysClass> *get();
			}
	};

	public ref class PhysClassRefMultiListIterator : public RefMultiListIterator<IPhysClass ^>
	{
		private:
			PhysClassRefMultiListIterator(IRefMultiListClass<IPhysClass ^> ^list);

		public:
			PhysClassRefMultiListIterator(IntPtr pointer);

			static IUnmanagedContainer<IRefMultiListIterator<IPhysClass ^> ^> ^CreatePhysClassRefMultiListIterator(
				IRefMultiListClass<IPhysClass ^> ^list);

			IPhysClass ^GetObj() override sealed;
			IPhysClass ^PeekObj() override sealed;
			void RemoveCurrentObject() override sealed;

			property IntPtr PhysClassRefMultiListIteratorPointer
			{
				IntPtr get();
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::RefMultiListIterator<::PhysClass> *InternalPhysClassRefMultiListIteratorPointer
			{
				virtual ::RefMultiListIterator<::PhysClass> *get();
			}
	};
}