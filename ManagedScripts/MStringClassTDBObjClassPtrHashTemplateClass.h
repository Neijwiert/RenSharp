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

class TDBObjClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class ITDBObjClass;

	public interface class IStringClassTDBObjClassPtrHashTemplateIterator : public IHashTemplateIterator<String ^, ITDBObjClass^>
	{
		property IntPtr StringClassTDBObjClassPtrHashTemplateIteratorPointer
		{
			IntPtr get();
		}
	};

	public ref class StringClassTDBObjClassPtrHashTemplateIterator : public HashTemplateIterator<String ^, ITDBObjClass^>, public IStringClassTDBObjClassPtrHashTemplateIterator
	{
		private:
			StringClassTDBObjClassPtrHashTemplateIterator(IHashTemplateClass<String ^, ITDBObjClass^> ^table);

		public:
			StringClassTDBObjClassPtrHashTemplateIterator(IntPtr pointer);

			static IUnmanagedContainer<IHashTemplateIterator<String ^, ITDBObjClass^> ^> ^CreateStringClassTDBObjClassPtrHashTemplateIterator(IHashTemplateClass<String ^, ITDBObjClass^> ^table);
	
			void Reset() override sealed;
			void Remove() override sealed;
			void Next() override sealed;

			property IntPtr StringClassTDBObjClassPtrHashTemplateIteratorPointer
			{
				virtual IntPtr get() sealed;
			}

			property String ^CurrentKey
			{
				String ^get() override sealed;
			}

			property ITDBObjClass^CurrentValue
			{
				ITDBObjClass^get() override sealed;
			}

			property bool IsDone
			{
				bool get() override sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::HashTemplateIterator<::StringClass, ::TDBObjClass*> *InternalStringClassTDBObjClassPtrHashTemplateIteratorPointer
			{
				virtual ::HashTemplateIterator<::StringClass, ::TDBObjClass*> *get();
			}
	};

	public interface class IStringClassTDBObjClassPtrHashTemplateClass : public IHashTemplateClass<String ^, ITDBObjClass^>
	{
		property IntPtr StringClassTDBObjClassPtrHashTemplateClassPointer
		{
			IntPtr get();
		}
	};

	public ref class StringClassTDBObjClassPtrHashTemplateClass : public HashTemplateClass<String ^, ITDBObjClass^>, public IStringClassTDBObjClassPtrHashTemplateClass
	{
		private:
			StringClassTDBObjClassPtrHashTemplateClass();

		public:
			StringClassTDBObjClassPtrHashTemplateClass(IntPtr pointer);

			static IUnmanagedContainer<IHashTemplateClass<String ^, ITDBObjClass^> ^> ^CreateStringClassTDBObjClassPtrHashTemplateClass();

			ITDBObjClass^Get(String ^key) override sealed;
			void Get(String ^key, ITDBObjClass^defaultValue, ITDBObjClass^% result) override sealed;
			bool Exists(String ^key) override sealed;
			void Insert(String ^key, ITDBObjClass^ value) override sealed;
			void RemoveAll() override sealed;
			void GetValueByIndex(int index, ITDBObjClass^% result) override sealed;
			bool Remove(String ^key) override;
			bool Remove(Generic::KeyValuePair<String ^, ITDBObjClass^> pair) override;
			bool Contains(Generic::KeyValuePair<String ^, ITDBObjClass^> pair) override;
			bool Contains(Object ^key) override;
			void Add(Object ^key, Object ^value) override;
			void Remove(Object ^key) override;

			property IntPtr StringClassTDBObjClassPtrHashTemplateClassPointer
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

			property ::HashTemplateClass<::StringClass, ::TDBObjClass*> *InternalStringClassTDBObjClassPtrHashTemplateClassPointer
			{
				virtual ::HashTemplateClass<::StringClass, ::TDBObjClass*> *get();
			}

			property IUnmanagedContainer<IHashTemplateIterator<String ^, ITDBObjClass^> ^> ^Iterator
			{
				IUnmanagedContainer<IHashTemplateIterator<String ^, ITDBObjClass^> ^> ^get() override sealed;
			}
	};
}