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

#include "Mengine_vector.h"
#include "IUnmanagedContainer.h"

#pragma managed(push, off)

class CullLinkClass;
class CullableClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class ICullSystemClass;
	value class AABoxClass;

	public interface class ICullLinkClass : public IUnmanagedObject
	{
		property IntPtr CullLinkClassPointer
		{
			IntPtr get();
		}

		property ICullSystemClass ^CullingSystem
		{
			ICullSystemClass ^get();
			void set(ICullSystemClass ^value);
		}
	};

	public ref class CullLinkClass : public AbstractUnmanagedObject, public ICullLinkClass
	{
		private:
			CullLinkClass(ICullSystemClass ^system);

		protected:
			CullLinkClass();

		public:
			CullLinkClass(IntPtr pointer);

			static IUnmanagedContainer<ICullLinkClass ^> ^CreateCullLinkClass(ICullSystemClass ^system);

			bool Equals(Object ^other) override;

			property IntPtr CullLinkClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property ICullSystemClass ^CullingSystem
			{
				virtual ICullSystemClass ^get() sealed;
				virtual void set(ICullSystemClass ^value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::CullLinkClass *InternalCullLinkClassPointer
			{
				virtual ::CullLinkClass *get();
			}
	};

	public interface class ICullableClass : public IRefCountClass
	{
		property IntPtr CullableClassPointer
		{
			IntPtr get();
		}

		property AABoxClass CullBox
		{
			AABoxClass get();
		}

		property ICullLinkClass ^CullLink
		{
			ICullLinkClass ^get();
			void set(ICullLinkClass ^value);
		}
	};

	public ref class CullableClass : public RefCountClass, public ICullableClass
	{
		public:
			CullableClass(IntPtr pointer);

			property IntPtr CullableClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property AABoxClass CullBox
			{
				virtual AABoxClass get() sealed;
			}

			property ICullLinkClass ^CullLink
			{
				virtual ICullLinkClass ^get() sealed;
				virtual void set(ICullLinkClass ^value) sealed;
			}

		protected:
			property ::RefCountClass *InternalRefCountClassPointer
			{
				::RefCountClass *get() override;
			}

			property ::CullableClass *InternalCullableClassPointer
			{
				virtual ::CullableClass *get();
			}
	};
}