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

#include "Mengine_vector.h"

#pragma managed(push, off)

class PersistantSurfaceEmitterClass;

#pragma managed(pop)

namespace RenSharp
{
	public ref class PersistantSurfaceEmitterClassPtrVectorClass : public VectorClass<IntPtr>
	{
		private:
			PersistantSurfaceEmitterClassPtrVectorClass();
			PersistantSurfaceEmitterClassPtrVectorClass(int size);

		public:
			PersistantSurfaceEmitterClassPtrVectorClass(IntPtr pointer);

			static IUnmanagedContainer<IVectorClass<IntPtr> ^> ^CreatePersistantSurfaceEmitterClassPtrVectorClass();
			static IUnmanagedContainer<IVectorClass<IntPtr> ^> ^CreatePersistantSurfaceEmitterClassPtrVectorClass(int size);

			bool Resize(int newSize) override sealed;
			void Clear() override sealed;
			int ID(IntPtr object) override sealed;

			property IntPtr PersistantSurfaceEmitterClassPtrVectorClassPointer
			{
				IntPtr get();
			}

			property IntPtr default[int]
			{
				IntPtr get(int index) override sealed;
				void set(int index, IntPtr value) override sealed;
			}

			property int Length
			{
				int get() override sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::VectorClass<::PersistantSurfaceEmitterClass *> *InternalPersistantSurfaceEmitterClassPtrVectorClassPointer
			{
				virtual ::VectorClass<::PersistantSurfaceEmitterClass *> *get();
			}

			property IntPtr Vector
			{
				IntPtr get() override sealed;
				void set(IntPtr value) override sealed;
			}

			property int VectorMax
			{
				int get() override sealed;
				void set(int value) override sealed;
			}

			property bool IsValid
			{
				bool get() override sealed;
				void set(bool value) override sealed;
			}

			property bool IsAllocated
			{
				bool get() override sealed;
				void set(bool value) override sealed;
			}
	};
}