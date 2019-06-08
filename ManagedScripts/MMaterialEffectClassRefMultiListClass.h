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
#include "MMaterialEffectClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <MaterialEffectClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	public ref class MaterialEffectClassRefMultiListClass : public RefMultiListClass<IMaterialEffectClass ^>
	{
		private:
			MaterialEffectClassRefMultiListClass();

		public:
			MaterialEffectClassRefMultiListClass(IntPtr pointer);

			static IUnmanagedContainer<IRefMultiListClass<IMaterialEffectClass ^> ^> ^CreateMaterialEffectClassRefMultiListClass();

			bool Contains(IMaterialEffectClass ^obj) override;
			bool Add(IMaterialEffectClass ^obj, bool onlyOnce) override;
			bool AddTail(IMaterialEffectClass ^obj, bool onlyOnce) override sealed;
			bool AddTail(IMaterialEffectClass ^obj) override sealed;
			bool AddAfter(IMaterialEffectClass ^obj, IMaterialEffectClass ^existingListMember, bool onlyOnce) override sealed;
			bool AddAfter(IMaterialEffectClass ^obj, IMaterialEffectClass ^existingListMember) override sealed;
			bool ReleaseHead() override sealed;
			IMaterialEffectClass ^GetHead() override sealed;
			IMaterialEffectClass ^PeekHead() override sealed;
			IMaterialEffectClass ^RemoveHead() override sealed;
			void ResetList() override sealed;
			bool Remove(IMaterialEffectClass ^item) override;

			property IntPtr MaterialEffectClassRefMultiListClassPointer
			{
				IntPtr get();
			}

			property IUnmanagedContainer<IRefMultiListIterator<IMaterialEffectClass ^> ^> ^Iterator
			{
				IUnmanagedContainer<IRefMultiListIterator<IMaterialEffectClass ^> ^> ^get() override sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::RefMultiListClass<::MaterialEffectClass> *InternalMaterialEffectClassRefMultiListClassPointer
			{
				virtual ::RefMultiListClass<::MaterialEffectClass> *get();
			}
	};

	public ref class MaterialEffectClassRefMultiListIterator : public RefMultiListIterator<IMaterialEffectClass ^>
	{
		private:
			MaterialEffectClassRefMultiListIterator(IRefMultiListClass<IMaterialEffectClass ^> ^list);

		public:
			MaterialEffectClassRefMultiListIterator(IntPtr pointer);

			static IUnmanagedContainer<IRefMultiListIterator<IMaterialEffectClass ^> ^> ^CreateMaterialEffectClassRefMultiListIterator(
				IRefMultiListClass<IMaterialEffectClass ^> ^list);

			IMaterialEffectClass ^GetObj() override sealed;
			IMaterialEffectClass ^PeekObj() override sealed;
			void RemoveCurrentObject() override sealed;

			property IntPtr MaterialEffectClassRefMultiListIteratorPointer
			{
				IntPtr get();
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::RefMultiListIterator<::MaterialEffectClass> *InternalMaterialEffectClassRefMultiListIteratorPointer
			{
				virtual ::RefMultiListIterator<::MaterialEffectClass> *get();
			}
	};
}