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

class WeaponDefinitionClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IWeaponDefinitionClass;

	public ref class ConstWeaponDefinitionClassPtrDynamicVectorClass : public DynamicVectorClass<IWeaponDefinitionClass ^>
	{
		private:
			ConstWeaponDefinitionClassPtrDynamicVectorClass();
			ConstWeaponDefinitionClassPtrDynamicVectorClass(int size);

		public:
			ConstWeaponDefinitionClassPtrDynamicVectorClass(IntPtr pointer);

			static IUnmanagedContainer<IDynamicVectorClass<IWeaponDefinitionClass ^> ^> ^CreateConstWeaponDefinitionClassPtrDynamicVectorClass();
			static IUnmanagedContainer<IDynamicVectorClass<IWeaponDefinitionClass ^> ^> ^CreateConstWeaponDefinitionClassPtrDynamicVectorClass(int size);

			bool Resize(int newSize) override sealed;
			void Clear() override;
			int ID(IWeaponDefinitionClass ^object) override sealed;
			void Insert(int index, IWeaponDefinitionClass ^object) override;
			bool Add(IWeaponDefinitionClass ^object) override;
			void ResetActive() override sealed;
			bool AddHead(IWeaponDefinitionClass ^object) override sealed;
			bool DeleteObj(IWeaponDefinitionClass ^object) override sealed;
			bool Delete(int index) override sealed;
			void DeleteAll() override sealed;
			int UninitializedAdd() override sealed;
			void AddMultiple(int numberToAdd) override sealed;

			property IntPtr ConstWeaponDefinitionClassPtrDynamicVectorClassPointer
			{
				IntPtr get();
			}

			property IWeaponDefinitionClass ^default[int]
			{
				IWeaponDefinitionClass ^get(int index) override;
				void set(int index, IWeaponDefinitionClass ^value) override;
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

			property ::DynamicVectorClass<const ::WeaponDefinitionClass *> *InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer
			{
				virtual ::DynamicVectorClass<const ::WeaponDefinitionClass *> *get();
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