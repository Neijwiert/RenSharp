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

#include "MBuildingGameObj.h"

#pragma managed(push, off)

class SuperweaponGameObj;

#pragma managed(pop)

namespace RenSharp
{
	interface class ISuperweaponGameObjDef;

	public interface class ISuperweaponGameObj : public IBuildingGameObj
	{
		property IntPtr SuperweaponGameObjPointer
		{
			IntPtr get();
		}

		property ISuperweaponGameObjDef ^Definition
		{
			ISuperweaponGameObjDef ^get();
		}

		property bool Launching
		{
			bool get();
		}
	};

	public ref class SuperweaponGameObj : public BuildingGameObj, public ISuperweaponGameObj
	{
		public:
			SuperweaponGameObj(IntPtr pointer);

			ISuperweaponGameObj ^AsSuperweaponGameObj() override;

			property IntPtr SuperweaponGameObjPointer
			{
				virtual IntPtr get() sealed;
			}

			property ISuperweaponGameObjDef ^Definition
			{
#pragma push_macro("new")
#undef new

				virtual ISuperweaponGameObjDef ^get() new sealed;

#pragma pop_macro("new")
			}

			property bool Launching
			{
				virtual bool get() sealed;
			}

		protected:
			property ::PhysObserverClass *InternalPhysObserverClassPointer
			{
				::PhysObserverClass *get() override;
			}

			property ::CombatPhysObserverClass *InternalCombatPhysObserverClassPointer
			{
				::CombatPhysObserverClass *get() override;
			}

			property ::BuildingGameObj *InternalBuildingGameObjPointer
			{
				::BuildingGameObj *get() override;
			}

			property ::SuperweaponGameObj *InternalSuperweaponGameObjPointer
			{
				virtual ::SuperweaponGameObj *get();
			}
	};
}