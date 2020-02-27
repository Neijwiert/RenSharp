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

#include "MSaveLoadSubSystemClass.h"
#include "MPersist.h"

#pragma managed(push, off)

class PresetMgrClass;
class PresetClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IPresetClass;
	interface class IDefinitionClass;

	public interface class IPresetMgrClass : public ISaveLoadSubSystemClass
	{
		property IPresetClass^ PresetListHead
		{
			IPresetClass^ get();
			void set(IPresetClass^ value);
		}

		property bool PresetsDirty
		{
			bool get();
			void set(bool value);
		}

		property bool ImmedCheckin
		{
			bool get();
			void set(bool value);
		}

		property IntPtr PresetMgrClassPointer
		{
			IntPtr get();
		}
	};

	public ref class PresetMgrClass : public SaveLoadSubSystemClass, public IPresetMgrClass
	{
		public:
			PresetMgrClass(IntPtr pointer);

			property IPresetClass^ PresetListHead
			{
				virtual IPresetClass^ get() sealed;
				virtual void set(IPresetClass^ value) sealed;
			}

			property bool PresetsDirty
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool ImmedCheckin
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property IntPtr PresetMgrClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::SaveLoadSubSystemClass* InternalSaveLoadSubSystemClassPointer
			{
				::SaveLoadSubSystemClass* get() override;
			}

			property ::PresetMgrClass* InternalPresetMgrClassPointer
			{
				virtual ::PresetMgrClass* get();
			}
	};

	public interface class IPresetClass : public IPersistClass
	{
		property IPresetClass^ Next
		{
			IPresetClass^ get();
			void set(IPresetClass^ value);
		}

		property IPresetClass^ Prev
		{
			IPresetClass^ get();
			void set(IPresetClass^ value);
		}

		property bool IsGood
		{
			bool get();
		}

		property int ChildCount
		{
			int get();
		}

		property IDefinitionClass^ Definition
		{
			IDefinitionClass^ get();
		}

		property IPresetClass^ Parent
		{
			IPresetClass^ get();
		}

		property unsigned int DefinitionId
		{
			unsigned int get();
			void set(unsigned int value);
		}

		property bool IsTemp
		{
			bool get();
		}

		property IntPtr PresetClassPointer
		{
			IntPtr get();
		}
	};

	public ref class PresetClass : public PersistClass, public IPresetClass
	{
		public:
			PresetClass(IntPtr pointer);

			property IPresetClass^ Next
			{
				virtual IPresetClass^ get() sealed;
				virtual void set(IPresetClass^ value) sealed;
			}

			property IPresetClass^ Prev
			{
				virtual IPresetClass^ get() sealed;
				virtual void set(IPresetClass^ value) sealed;
			}

			property bool IsGood
			{
				virtual bool get() sealed;
			}

			property int ChildCount
			{
				virtual int get() sealed;
			}

			property IDefinitionClass^ Definition
			{
				virtual IDefinitionClass^ get() sealed;
			}

			property IPresetClass^ Parent
			{
				virtual IPresetClass^ get() sealed;
			}

			property unsigned int DefinitionId
			{
				virtual unsigned int get() sealed;
				virtual void set(unsigned int value) sealed;
			}

			property bool IsTemp
			{
				virtual bool get() sealed;
			}

			property IntPtr PresetClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::PersistClass* InternalPersistClassPointer
			{
				::PersistClass* get() override;
			}

			property ::PresetClass* InternalPresetClassPointer
			{
				virtual ::PresetClass* get();
			}
	};
}