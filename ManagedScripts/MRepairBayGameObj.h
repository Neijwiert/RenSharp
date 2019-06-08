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

class RepairBayGameObj;

#pragma managed(pop)

namespace RenSharp
{
	interface class IRepairBayGameObjDef;

	public interface class IRepairBayGameObj : public IBuildingGameObj
	{
		property IntPtr RepairBayGameObjPointer
		{
			IntPtr get();
		}

		property IRepairBayGameObjDef ^Definition
		{
			IRepairBayGameObjDef ^get();
		}
	};

	public ref class RepairBayGameObj : public BuildingGameObj, public IRepairBayGameObj
	{
		public:
			RepairBayGameObj(IntPtr pointer);

			IRepairBayGameObj ^AsRepairBayGameObj() override;

			property IntPtr RepairBayGameObjPointer
			{
				virtual IntPtr get() sealed;
			}

			property IRepairBayGameObjDef ^Definition
			{
#pragma push_macro("new")
#undef new

				virtual IRepairBayGameObjDef ^get() new sealed;

#pragma pop_macro("new")
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

			property ::RepairBayGameObj *InternalRepairBayGameObjPointer
			{
				virtual ::RepairBayGameObj *get();
			}
	};
}