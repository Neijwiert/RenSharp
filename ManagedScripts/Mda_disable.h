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

#include "Mda_event.h"
#include "Mengine_vector.h"

#pragma managed(push, off)

struct DACharacterDisableListStruct;
class DADisableListManager;

#pragma managed(pop)

namespace RenSharp
{
	interface class IDefinitionClass;

	public interface class IDACharacterDisableListStruct : public IUnmanagedObject
	{
		property IntPtr DACharacterDisableListStructPointer
		{
			IntPtr get();
		}

		property IDynamicVectorClass<IDefinitionClass^>^ DisableList
		{
			IDynamicVectorClass<IDefinitionClass^>^ get();
			void set(IDynamicVectorClass<IDefinitionClass^>^ value);
		}

		property bool EnterVehicles
		{
			bool get();
			void set(bool value);
		}

		property bool DriveVehicles
		{
			bool get();
			void set(bool value);
		}

		property bool StealVehicles
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class DACharacterDisableListStruct : public AbstractUnmanagedObject, public IDACharacterDisableListStruct
	{
		private:
			DACharacterDisableListStruct();

		public:
			DACharacterDisableListStruct(IntPtr pointer);

			static IUnmanagedContainer<IDACharacterDisableListStruct^>^ CreateDACharacterDisableListStruct();

			bool Equals(Object^ other) override;

			property IntPtr DACharacterDisableListStructPointer
			{
				virtual IntPtr get() sealed;
			}

			property IDynamicVectorClass<IDefinitionClass^>^ DisableList
			{
				virtual IDynamicVectorClass<IDefinitionClass^>^ get() sealed;
				virtual void set(IDynamicVectorClass<IDefinitionClass^>^ value) sealed;
			}

			property bool EnterVehicles
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool DriveVehicles
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool StealVehicles
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}
		
		protected:
			bool InternalDestroyPointer() override;

			property ::DACharacterDisableListStruct* InternalDACharacterDisableListStructPointer
			{
				virtual ::DACharacterDisableListStruct* get();
			}
	};

	public interface class IDADisableListManager : public IDAEventClass
	{
		property IntPtr DADisableListManagerPointer
		{
			IntPtr get();
		}
	};

	public ref class DADisableListManager : public DAEventClass, public IDADisableListManager
	{
		// Although you can instantiate a DADisableListManager class, it doesn't make any sense so I left it out
		public:
			DADisableListManager(IntPtr pointer);

			static bool IsPresetDisabled(IScriptableGameObj^ obj);
			static bool IsPresetDisabled(String^ preset);
			static bool IsPresetDisabled(IDefinitionClass^ def);
			static bool IsPresetDisabled(unsigned int defID);
			static bool IsPresetDisabledForCharacter(IDefinitionClass^ character, IDefinitionClass^ def);
			static bool IsPresetDisabledForCharacter(IDefinitionClass^ character, String^ preset);
			static bool IsPresetDisabledForCharacter(IDefinitionClass^ character, unsigned int defID);
			static bool CanCharacterEnterVehicles(IDefinitionClass^ character);
			static bool CanCharacterDriveVehicles(IDefinitionClass^ character);
			static bool CanCharacterStealVehicles(IDefinitionClass^ character);

			property IntPtr DADisableListManagerPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::DAEventClass* InternalDAEventClassPointer
			{
				::DAEventClass* get() override;
			}

			property ::DADisableListManager* InternalDADisableListManagerPointer
			{
				virtual ::DADisableListManager* get();
			}
	};
}