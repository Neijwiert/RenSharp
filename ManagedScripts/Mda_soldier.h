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
#include "MHashTemplateClass.h"
#include "Mengine_vector.h"

#pragma managed(push, off)

class DASoldierManager;

#pragma managed(pop)

namespace RenSharp
{
	interface class IWeaponDefinitionClass;

	public interface class IDASoldierManager : public IDAEventClass
	{
		property IntPtr DASoldierManagerPointer
		{
			IntPtr get();
		}
	};

	public ref class DASoldierManager : public DAEventClass, public IDASoldierManager
	{
		// Although you can instantiate a DASoldierManager class, it doesn't make any sense so I left it out
		public:
			DASoldierManager(IntPtr pointer);

			property IntPtr DASoldierManagerPointer
			{
				virtual IntPtr get() sealed;
			}

			static property IHashTemplateClass<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^>^ ExclusiveWeapons
			{
				IHashTemplateClass<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^>^ get();
			}

			static property IHashTemplateClass<unsigned int, IWeaponDefinitionClass^>^ ReplaceWeapons
			{
				IHashTemplateClass<unsigned int, IWeaponDefinitionClass^>^ get();
			}

			static property IHashTemplateClass<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^>^ RemoveWeapons
			{
				IHashTemplateClass<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^>^ get();
			}

		protected:
			property ::DAEventClass* InternalDAEventClassPointer
			{
				::DAEventClass* get() override;
			}

			property ::DASoldierManager* InternalDASoldierManagerPointer
			{
				virtual ::DASoldierManager* get();
			}
	};
}