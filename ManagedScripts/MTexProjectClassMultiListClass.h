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

#pragma managed(push, off)

class TexProjectClass;

#pragma managed(pop)

namespace RenSharp
{
	public ref class TexProjectClassMultiListClass : public MultiListClass<IntPtr>
	{
		private:
			TexProjectClassMultiListClass();

		public:
			TexProjectClassMultiListClass(IntPtr pointer);

			static IUnmanagedContainer<IMultiListClass<IntPtr> ^> ^CreateTexProjectClassMultiListClass();

			bool Contains(IntPtr obj) override;
			bool Add(IntPtr obj, bool onlyOnce) override;
			bool AddTail(IntPtr obj, bool onlyOnce) override sealed;
			bool AddTail(IntPtr obj) override sealed;
			bool AddAfter(IntPtr obj, IntPtr existingListMember, bool onlyOnce) override sealed;
			bool AddAfter(IntPtr obj, IntPtr existingListMember) override sealed;
			IntPtr GetHead() override sealed;
			IntPtr PeekHead() override sealed;
			IntPtr RemoveHead() override sealed;
			void ResetList() override sealed;
			bool Remove(IntPtr item) override;

			property IntPtr TexProjectClassMultiListClassPointer
			{
				IntPtr get();
			}

			property IUnmanagedContainer<IMultiListIterator<IntPtr > ^> ^Iterator
			{
				IUnmanagedContainer<IMultiListIterator<IntPtr > ^> ^get() override sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::MultiListClass<::TexProjectClass> *InternalTexProjectClassMultiListClassPointer
			{
				virtual ::MultiListClass<::TexProjectClass> *get();
			}
	};

	public ref class TexProjectClassMultiListIterator : public MultiListIterator<IntPtr >
	{
		private:
			TexProjectClassMultiListIterator(IMultiListClass<IntPtr > ^list);

		public:
			TexProjectClassMultiListIterator(IntPtr pointer);

			static IUnmanagedContainer<IMultiListIterator<IntPtr > ^> ^CreateTexProjectClassMultiListIterator(
				IMultiListClass<IntPtr > ^list);

			IntPtr GetObj() override sealed;
			IntPtr PeekObj() override sealed;
			void RemoveCurrentObject() override sealed;

			property IntPtr TexProjectClassMultiListIteratorPointer
			{
				IntPtr get();
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::MultiListIterator<::TexProjectClass> *InternalTexProjectClassMultiListIteratorPointer
			{
				virtual ::MultiListIterator<::TexProjectClass> *get();
			}
	};
}