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

#include <GameDefinition.h>

#pragma managed(pop)

namespace RenSharp
{
	interface class IGameDefinition;

	public interface class IStringClassGameDefinitionHashTemplateIterator : public IHashTemplateIterator<String ^, IGameDefinition ^>
	{
		property IntPtr StringClassGameDefinitionHashTemplateIteratorPointer
		{
			IntPtr get();
		}
	};

	public ref class StringClassGameDefinitionHashTemplateIterator : public HashTemplateIterator<String ^, IGameDefinition ^>, public IStringClassGameDefinitionHashTemplateIterator
	{
		private:
			StringClassGameDefinitionHashTemplateIterator(IHashTemplateClass<String ^, IGameDefinition ^> ^table);

		public:
			StringClassGameDefinitionHashTemplateIterator(IntPtr pointer);

			static IUnmanagedContainer<IHashTemplateIterator<String ^, IGameDefinition ^> ^> ^CreateStringClassGameDefinitionHashTemplateIterator(IHashTemplateClass<String ^, IGameDefinition ^> ^table);
	
			void Reset() override sealed;
			void Remove() override sealed;
			void Next() override sealed;

			property IntPtr StringClassGameDefinitionHashTemplateIteratorPointer
			{
				virtual IntPtr get() sealed;
			}

			property String ^CurrentKey
			{
				String ^get() override sealed;
			}

			property IGameDefinition ^CurrentValue
			{
				IGameDefinition ^get() override sealed;
			}

			property bool IsDone
			{
				bool get() override sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::HashTemplateIterator<::StringClass, ::GameDefinition> *InternalStringClassGameDefinitionHashTemplateIteratorPointer
			{
				virtual ::HashTemplateIterator<::StringClass, ::GameDefinition> *get();
			}
	};

	public interface class IStringClassGameDefinitionHashTemplateClass : public IHashTemplateClass<String ^, IGameDefinition ^>
	{
		property IntPtr StringClassGameDefinitionHashTemplateClassPointer
		{
			IntPtr get();
		}
	};

	public ref class StringClassGameDefinitionHashTemplateClass : public HashTemplateClass<String ^, IGameDefinition ^>, public IStringClassGameDefinitionHashTemplateClass
	{
		private:
			StringClassGameDefinitionHashTemplateClass();

		public:
			StringClassGameDefinitionHashTemplateClass(IntPtr pointer);

			static IUnmanagedContainer<IHashTemplateClass<String ^, IGameDefinition ^> ^> ^CreateStringClassGameDefinitionHashTemplateClass();

			IGameDefinition ^Get(String ^key) override sealed;
			void Get(String ^key, IGameDefinition ^defaultValue, IGameDefinition ^%result) override sealed;
			bool Exists(String ^key) override sealed;
			void Insert(String ^key, IGameDefinition ^value) override sealed;
			void RemoveAll() override sealed;
			void GetValueByIndex(int index, IGameDefinition ^%result) override sealed;
			bool Remove(String ^key) override;
			bool Remove(Generic::KeyValuePair<String ^, IGameDefinition ^> pair) override;
			bool Contains(Generic::KeyValuePair<String ^, IGameDefinition ^> pair) override;
			bool Contains(Object ^key) override;
			void Add(Object ^key, Object ^value) override;
			void Remove(Object ^key) override;

			property IntPtr StringClassGameDefinitionHashTemplateClassPointer
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

			property ::HashTemplateClass<::StringClass, ::GameDefinition> *InternalStringClassGameDefinitionHashTemplateClassPointer
			{
				virtual ::HashTemplateClass<::StringClass, ::GameDefinition> *get();
			}

			property IUnmanagedContainer<IHashTemplateIterator<String ^, IGameDefinition ^> ^> ^Iterator
			{
				IUnmanagedContainer<IHashTemplateIterator<String ^, IGameDefinition ^> ^> ^get() override sealed;
			}
	};
}