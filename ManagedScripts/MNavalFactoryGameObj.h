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

#include "MBuildingGameObj.h"

#pragma managed(push, off)

class NavalFactoryGameObj;

#pragma managed(pop)

namespace RenSharp
{
	interface class INavalFactoryGameObjDef;

	public interface class INavalFactoryGameObj : public IBuildingGameObj
	{
		property IntPtr NavalFactoryGameObjPointer
		{
			IntPtr get();
		}

		property INavalFactoryGameObjDef ^Definition
		{
			INavalFactoryGameObjDef ^get();
		}

		property bool IsAvailable
		{
			bool get();
		}

		property bool IsBusy
		{
			bool get();
			void set(bool value);
		}

		property bool IsDisabled
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class NavalFactoryGameObj : public BuildingGameObj, public INavalFactoryGameObj
	{
		public:
			NavalFactoryGameObj(IntPtr pointer);

			INavalFactoryGameObj ^AsNavalFactoryGameObj() override;

			property IntPtr NavalFactoryGameObjPointer
			{
				virtual IntPtr get() sealed;
			}

			property INavalFactoryGameObjDef ^Definition
			{
#pragma push_macro("new")
#undef new
				virtual INavalFactoryGameObjDef ^get() new sealed;

#pragma pop_macro("new")
			}

			property bool IsAvailable
			{
				virtual bool get() sealed;
			}

			property bool IsBusy
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsDisabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
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

			property ::NavalFactoryGameObj *InternalNavalFactoryGameObjPointer
			{
				virtual ::NavalFactoryGameObj *get();
			}
	};
}