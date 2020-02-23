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
#include "MLightPhysClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <LightPhysClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	public ref class LightPhysClassRefMultiListClass : public RefMultiListClass<ILightPhysClass ^>
	{
		private:
			LightPhysClassRefMultiListClass();

		public:
			LightPhysClassRefMultiListClass(IntPtr pointer);

			static IUnmanagedContainer<IRefMultiListClass<ILightPhysClass ^> ^> ^CreateLightPhysClassRefMultiListClass();

			bool Contains(ILightPhysClass ^obj) override;
			bool Add(ILightPhysClass ^obj, bool onlyOnce) override;
			bool AddTail(ILightPhysClass ^obj, bool onlyOnce) override sealed;
			bool AddTail(ILightPhysClass ^obj) override sealed;
			bool AddAfter(ILightPhysClass ^obj, ILightPhysClass ^existingListMember, bool onlyOnce) override sealed;
			bool AddAfter(ILightPhysClass ^obj, ILightPhysClass ^existingListMember) override sealed;
			bool ReleaseHead() override sealed;
			ILightPhysClass ^GetHead() override sealed;
			ILightPhysClass ^PeekHead() override sealed;
			ILightPhysClass ^RemoveHead() override sealed;
			void ResetList() override sealed;
			bool Remove(ILightPhysClass ^item) override;

			property IntPtr LightPhysClassRefMultiListClassPointer
			{
				IntPtr get();
			}

			property IUnmanagedContainer<IRefMultiListIterator<ILightPhysClass ^> ^> ^Iterator
			{
				IUnmanagedContainer<IRefMultiListIterator<ILightPhysClass ^> ^> ^get() override sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::RefMultiListClass<::LightPhysClass> *InternalLightPhysClassRefMultiListClassPointer
			{
				virtual ::RefMultiListClass<::LightPhysClass> *get();
			}
	};

	public ref class LightPhysClassRefMultiListIterator : public RefMultiListIterator<ILightPhysClass ^>
	{
		private:
			LightPhysClassRefMultiListIterator(IRefMultiListClass<ILightPhysClass ^> ^list);

		public:
			LightPhysClassRefMultiListIterator(IntPtr pointer);

			static IUnmanagedContainer<IRefMultiListIterator<ILightPhysClass ^> ^> ^CreateLightPhysClassRefMultiListIterator(
				IRefMultiListClass<ILightPhysClass ^> ^list);

			ILightPhysClass ^GetObj() override sealed;
			ILightPhysClass ^PeekObj() override sealed;
			void RemoveCurrentObject() override sealed;

			property IntPtr LightPhysClassRefMultiListIteratorPointer
			{
				IntPtr get();
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::RefMultiListIterator<::LightPhysClass> *InternalLightPhysClassRefMultiListIteratorPointer
			{
				virtual ::RefMultiListIterator<::LightPhysClass> *get();
			}
	};
}