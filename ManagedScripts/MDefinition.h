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

#include "MEditable.h"

#pragma managed(push, off)

class DefinitionClass;
class PhysDefClass;

#pragma managed(pop)

using namespace System::Runtime::InteropServices;

namespace RenSharp
{

#pragma managed(push, off)

	class DefinitionClassHelper : public ::DefinitionClass
	{
		private:
			DefinitionClassHelper() = default;

		public:
			int &GetDefinitionMgrLink()
			{
				return m_DefinitionMgrLink;
			}
	};

#pragma managed(pop)

	interface class IChunkSaveClass;
	interface class IChunkLoadClass;

	public interface class IDefinitionClass : public IEditableClass
	{
		IPersistClass ^Create();

		bool IsValidConfig([Out] String ^%message);

		property IntPtr DefinitionClassPointer
		{
			IntPtr get();
		}

		property uint32 ClassID
		{
			uint32 get();
		}

		property uint32 ID
		{
			uint32 get();
			void set(uint32 value);
		}

		property String ^Name
		{
			String ^get();
			void set(String ^value);
		}

		property uint32 UserData
		{
			uint32 get();
			void set(uint32 value);
		}

		property bool IsSaveEnabled
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class DefinitionClass : public EditableClass, public IDefinitionClass
	{
		public:
			DefinitionClass(IntPtr pointer);

			String ^ToString() override;

			virtual IPersistClass ^Create() sealed;
			virtual bool IsValidConfig([Out] String ^%message) sealed;

			property IntPtr DefinitionClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property uint32 ClassID
			{
				virtual uint32 get() sealed;
			}

			property uint32 ID
			{
				virtual uint32 get() sealed;
				virtual void set(uint32 value) sealed;
			}

			property String ^Name
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property uint32 UserData
			{
				virtual uint32 get() sealed;
				virtual void set(uint32 value) sealed;
			}

			property bool IsSaveEnabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		internal:
			static IDefinitionClass^ CreateDefinitionClassWrapper(const ::DefinitionClass* definitionClassPtr);

		protected:
			property ::EditableClass *InternalEditableClassPointer
			{
				::EditableClass *get() override;
			}

			property ::DefinitionClass *InternalDefinitionClassPointer
			{
				virtual ::DefinitionClass *get();
			}

			property int DefinitionMgrLink
			{
				int get();
				void set(int value);
			}
	};
}
