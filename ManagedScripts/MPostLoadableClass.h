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

#include "IUnmanagedObject.h"
#include "AbstractUnmanagedObject.h"
#include "IUnmanagedContainer.h"

#pragma managed(push, off)

class PostLoadableClass;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IPostLoadableClass : public IUnmanagedObject
	{
		void OnPostLoad();

		property IntPtr PostLoadableClassPointer
		{
			IntPtr get();
		}

		property bool IsPostLoadRegistered
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class PostLoadableClass : public AbstractUnmanagedObject, public IPostLoadableClass
	{
		protected:
			PostLoadableClass(bool create);

		public:
			PostLoadableClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			static IUnmanagedContainer<IPostLoadableClass ^> ^CreatePostLoadableClass();

			virtual void OnPostLoad() sealed;

			property IntPtr PostLoadableClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool IsPostLoadRegistered
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::PostLoadableClass *InternalPostLoadableClassPointer
			{
				virtual ::PostLoadableClass *get();
			}
	};
}