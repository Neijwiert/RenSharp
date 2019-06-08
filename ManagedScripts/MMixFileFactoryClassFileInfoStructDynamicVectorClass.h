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
#include "MMixFileFactoryClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <MixFileFactoryClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	public ref class MixFileFactoryClassFileInfoStructDynamicVectorClass : public DynamicVectorClass<MixFileFactoryClass::IFileInfoStruct^>
	{
		private:
			MixFileFactoryClassFileInfoStructDynamicVectorClass();
			MixFileFactoryClassFileInfoStructDynamicVectorClass(int size);

		public:
			MixFileFactoryClassFileInfoStructDynamicVectorClass(IntPtr pointer);

			static IUnmanagedContainer<IDynamicVectorClass<MixFileFactoryClass::IFileInfoStruct^>^>^ CreateMixFileFactoryClassFileInfoStructDynamicVectorClass();
			static IUnmanagedContainer<IDynamicVectorClass<MixFileFactoryClass::IFileInfoStruct^>^>^ CreateMixFileFactoryClassFileInfoStructDynamicVectorClass(int size);

			bool Resize(int newSize) override sealed;
			void Clear() override;
			int ID(MixFileFactoryClass::IFileInfoStruct^ object) override sealed;
			void Insert(int index, MixFileFactoryClass::IFileInfoStruct^ object) override;
			bool Add(MixFileFactoryClass::IFileInfoStruct^ object) override;
			void ResetActive() override sealed;
			bool AddHead(MixFileFactoryClass::IFileInfoStruct^ object) override sealed;
			bool DeleteObj(MixFileFactoryClass::IFileInfoStruct^ object) override sealed;
			bool Delete(int index) override sealed;
			void DeleteAll() override sealed;
			int UninitializedAdd() override sealed;
			void AddMultiple(int numberToAdd) override sealed;

			property IntPtr MixFileFactoryClassFileInfoStructDynamicVectorClassPointer
			{
				IntPtr get();
			}

			property MixFileFactoryClass::IFileInfoStruct^ default[int]
			{
				MixFileFactoryClass::IFileInfoStruct^ get(int index) override;
				void set(int index, MixFileFactoryClass::IFileInfoStruct^ value) override;
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

			property ::DynamicVectorClass<::MixFileFactoryClass::FileInfoStruct>* InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer
			{
				virtual ::DynamicVectorClass<::MixFileFactoryClass::FileInfoStruct>* get();
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