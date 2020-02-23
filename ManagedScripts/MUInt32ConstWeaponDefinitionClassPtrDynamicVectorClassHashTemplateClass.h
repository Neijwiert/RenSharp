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

#include "MHashTemplateClass.h"
#include "MHashTemplateIterator.h"
#include "Mengine_vector.h"

#pragma managed(push, off)

class WeaponDefinitionClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IWeaponDefinitionClass;

	public interface class IUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator : public IHashTemplateIterator<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^>
	{
		property IntPtr UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIteratorPointer
		{
			IntPtr get();
		}
	};

	public ref class UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator : public HashTemplateIterator<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^>, public IUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator
	{
		private:
			UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator(IHashTemplateClass<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^> ^table);

		public:
			UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator(IntPtr pointer);

			static IUnmanagedContainer<IHashTemplateIterator<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^>^>^ CreateUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator(IHashTemplateClass<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^>^ table);
	
			void Reset() override sealed;
			void Remove() override sealed;
			void Next() override sealed;

			property IntPtr UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIteratorPointer
			{
				virtual IntPtr get() sealed;
			}

			property unsigned int CurrentKey
			{
				unsigned int get() override sealed;
			}

			property IDynamicVectorClass<IWeaponDefinitionClass^>^ CurrentValue
			{
				IDynamicVectorClass<IWeaponDefinitionClass^>^ get() override sealed;
			}

			property bool IsDone
			{
				bool get() override sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::HashTemplateIterator<unsigned int, ::DynamicVectorClass<const ::WeaponDefinitionClass*>>* InternalUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIteratorPointer
			{
				virtual ::HashTemplateIterator<unsigned int, ::DynamicVectorClass<const ::WeaponDefinitionClass*>>* get();
			}
	};

	public interface class IUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass : public IHashTemplateClass<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^>
	{
		property IntPtr UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClassPointer
		{
			IntPtr get();
		}
	};

	public ref class UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass : public HashTemplateClass<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^>, public IUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass
	{
		private:
			UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass();

		public:
			UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass(IntPtr pointer);

			static IUnmanagedContainer<IHashTemplateClass<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^>^> ^CreateUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass();

			IDynamicVectorClass<IWeaponDefinitionClass^>^ Get(unsigned int key) override sealed;
			void Get(unsigned int key, IDynamicVectorClass<IWeaponDefinitionClass^>^ defaultValue, IDynamicVectorClass<IWeaponDefinitionClass^>^% result) override sealed;
			bool Exists(unsigned int key) override sealed;
			void Insert(unsigned int key, IDynamicVectorClass<IWeaponDefinitionClass^>^ value) override sealed;
			void RemoveAll() override sealed;
			void GetValueByIndex(int index, IDynamicVectorClass<IWeaponDefinitionClass^>^% result) override sealed;
			bool Remove(unsigned int key) override;
			bool Remove(Generic::KeyValuePair<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^> pair) override;
			bool Contains(Generic::KeyValuePair<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^> pair) override;
			bool Contains(Object ^key) override;
			void Add(Object ^key, Object ^value) override;
			void Remove(Object ^key) override;

			property IntPtr UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property uint Size
			{
				uint get() override sealed;
			}

			property Object ^default[Object ^]
			{
				Object ^get(Object ^key) override;
				void set(Object ^key, Object ^value) override;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::HashTemplateClass<unsigned int, ::DynamicVectorClass<const ::WeaponDefinitionClass*>>* InternalUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClassPointer
			{
				virtual ::HashTemplateClass<unsigned int, ::DynamicVectorClass<const ::WeaponDefinitionClass*>>* get();
			}

			property IUnmanagedContainer<IHashTemplateIterator<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^> ^> ^Iterator
			{
				IUnmanagedContainer<IHashTemplateIterator<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^> ^> ^get() override sealed;
			}
	};
}