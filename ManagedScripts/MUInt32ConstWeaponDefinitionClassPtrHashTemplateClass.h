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

#include "MHashTemplateClass.h"
#include "MHashTemplateIterator.h"

#pragma managed(push, off)

class WeaponDefinitionClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IWeaponDefinitionClass;

	public interface class IUInt32ConstWeaponDefinitionClassPtrHashTemplateIterator : public IHashTemplateIterator<unsigned int, IWeaponDefinitionClass^>
	{
		property IntPtr UInt32ConstWeaponDefinitionClassPtrHashTemplateIteratorPointer
		{
			IntPtr get();
		}
	};

	public ref class UInt32ConstWeaponDefinitionClassPtrHashTemplateIterator : public HashTemplateIterator<unsigned int, IWeaponDefinitionClass^>, public IUInt32ConstWeaponDefinitionClassPtrHashTemplateIterator
	{
		private:
			UInt32ConstWeaponDefinitionClassPtrHashTemplateIterator(IHashTemplateClass<unsigned int, IWeaponDefinitionClass^> ^table);

		public:
			UInt32ConstWeaponDefinitionClassPtrHashTemplateIterator(IntPtr pointer);

			static IUnmanagedContainer<IHashTemplateIterator<unsigned int, IWeaponDefinitionClass^>^>^ CreateUInt32ConstWeaponDefinitionClassPtrHashTemplateIterator(IHashTemplateClass<unsigned int, IWeaponDefinitionClass^>^ table);
	
			void Reset() override sealed;
			void Remove() override sealed;
			void Next() override sealed;

			property IntPtr UInt32ConstWeaponDefinitionClassPtrHashTemplateIteratorPointer
			{
				virtual IntPtr get() sealed;
			}

			property unsigned int CurrentKey
			{
				unsigned int get() override sealed;
			}

			property IWeaponDefinitionClass^ CurrentValue
			{
				IWeaponDefinitionClass^ get() override sealed;
			}

			property bool IsDone
			{
				bool get() override sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::HashTemplateIterator<unsigned int, const ::WeaponDefinitionClass*>* InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateIteratorPointer
			{
				virtual ::HashTemplateIterator<unsigned int, const ::WeaponDefinitionClass*>* get();
			}
	};

	public interface class IUInt32ConstWeaponDefinitionClassPtrHashTemplateClass : public IHashTemplateClass<unsigned int, IWeaponDefinitionClass^>
	{
		property IntPtr UInt32ConstWeaponDefinitionClassPtrHashTemplateClassPointer
		{
			IntPtr get();
		}
	};

	public ref class UInt32ConstWeaponDefinitionClassPtrHashTemplateClass : public HashTemplateClass<unsigned int, IWeaponDefinitionClass^>, public IUInt32ConstWeaponDefinitionClassPtrHashTemplateClass
	{
		private:
			UInt32ConstWeaponDefinitionClassPtrHashTemplateClass();

		public:
			UInt32ConstWeaponDefinitionClassPtrHashTemplateClass(IntPtr pointer);

			static IUnmanagedContainer<IHashTemplateClass<unsigned int, IWeaponDefinitionClass^>^> ^CreateUInt32ConstWeaponDefinitionClassPtrHashTemplateClass();

			IWeaponDefinitionClass^ Get(unsigned int key) override sealed;
			void Get(unsigned int key, IWeaponDefinitionClass^ defaultValue, IWeaponDefinitionClass^% result) override sealed;
			bool Exists(unsigned int key) override sealed;
			void Insert(unsigned int key, IWeaponDefinitionClass^ value) override sealed;
			void RemoveAll() override sealed;
			void GetValueByIndex(int index, IWeaponDefinitionClass^% result) override sealed;
			bool Remove(unsigned int key) override;
			bool Remove(Generic::KeyValuePair<unsigned int, IWeaponDefinitionClass^> pair) override;
			bool Contains(Generic::KeyValuePair<unsigned int, IWeaponDefinitionClass^> pair) override;
			bool Contains(Object ^key) override;
			void Add(Object ^key, Object ^value) override;
			void Remove(Object ^key) override;

			property IntPtr UInt32ConstWeaponDefinitionClassPtrHashTemplateClassPointer
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

			property ::HashTemplateClass<unsigned int, const ::WeaponDefinitionClass*>* InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateClassPointer
			{
				virtual ::HashTemplateClass<unsigned int, const ::WeaponDefinitionClass*>* get();
			}

			property IUnmanagedContainer<IHashTemplateIterator<unsigned int, IWeaponDefinitionClass^> ^> ^Iterator
			{
				IUnmanagedContainer<IHashTemplateIterator<unsigned int, IWeaponDefinitionClass^>^>  ^get() override sealed;
			}
	};
}