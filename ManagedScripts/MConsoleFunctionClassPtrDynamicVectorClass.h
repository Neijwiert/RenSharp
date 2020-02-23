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

#pragma managed(push, off)

class ConsoleFunctionClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IConsoleFunctionClass;

	public ref class ConsoleFunctionClassPtrDynamicVectorClass : public DynamicVectorClass<IConsoleFunctionClass ^>
	{
		private:
			ConsoleFunctionClassPtrDynamicVectorClass();
			ConsoleFunctionClassPtrDynamicVectorClass(int size);

		public:
			ConsoleFunctionClassPtrDynamicVectorClass(IntPtr pointer);

			static IUnmanagedContainer<IDynamicVectorClass<IConsoleFunctionClass ^> ^> ^CreateConsoleFunctionClassPtrDynamicVectorClass();
			static IUnmanagedContainer<IDynamicVectorClass<IConsoleFunctionClass ^> ^> ^CreateConsoleFunctionClassPtrDynamicVectorClass(int size);

			bool Resize(int newSize) override sealed;
			void Clear() override;
			int ID(IConsoleFunctionClass ^object) override sealed;
			void Insert(int index, IConsoleFunctionClass ^object) override;
			bool Add(IConsoleFunctionClass ^object) override;
			void ResetActive() override sealed;
			bool AddHead(IConsoleFunctionClass ^object) override sealed;
			bool DeleteObj(IConsoleFunctionClass ^object) override sealed;
			bool Delete(int index) override sealed;
			void DeleteAll() override sealed;
			int UninitializedAdd() override sealed;
			void AddMultiple(int numberToAdd) override sealed;

			property IntPtr ConsoleFunctionClassPtrDynamicVectorClassPointer
			{
				IntPtr get();
			}

			property IConsoleFunctionClass ^default[int]
			{
				IConsoleFunctionClass ^get(int index) override;
				void set(int index, IConsoleFunctionClass ^value) override;
			}

			property int Length
			{
				int get() override sealed;
			}

			property int Count
			{
				int get() override;
				void set(int value) override sealed;
			}

			property int GrowthStep
			{
				int get() override sealed;
				void set(int value) override sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DynamicVectorClass<::ConsoleFunctionClass *> *InternalConsoleFunctionClassPtrDynamicVectorClassPointer
			{
				virtual ::DynamicVectorClass<::ConsoleFunctionClass *> *get();
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

			property int ActiveCount
			{
				int get() override sealed;
				void set(int value) override sealed;
			}
	};
}