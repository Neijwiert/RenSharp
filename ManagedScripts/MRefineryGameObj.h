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

class RefineryGameObj;

#pragma managed(pop)

namespace RenSharp
{
	interface class IRefineryGameObjDef;
	interface class IVehicleGameObj;
	interface class IHarvesterClass;
	value class Matrix3D;

	public interface class IRefineryGameObj : public IBuildingGameObj
	{
		void DestroyHarvester();

		void BlockHarvesterSpawn();

		void SetAllowHarvesterSpawn();

		property IntPtr RefineryGameObjPointer
		{
			IntPtr get();
		}

		property IRefineryGameObjDef ^Definition
		{
			IRefineryGameObjDef ^get();
		}

		property bool NeedsHarvester
		{
			bool get();
		}

		property int HarvesterDefId
		{
			int get();
		}

		property bool IsHarvesterDocked
		{
			bool get();
		}

		property IVehicleGameObj ^HarvesterVehicle
		{
			IVehicleGameObj ^get();
		}

		property IHarvesterClass ^Harvester
		{
			IHarvesterClass ^get();
			void set(IHarvesterClass ^value);
		}

		property Matrix3D DockTM
		{
			Matrix3D get();
			void set(Matrix3D value);
		}

		property bool AllowHarvesterSpawn
		{
			bool get();
		}
	};

	public ref class RefineryGameObj : public BuildingGameObj, public IRefineryGameObj
	{
		public:
			RefineryGameObj(IntPtr pointer);

			IRefineryGameObj ^AsRefineryGameObj() override;
			virtual void DestroyHarvester() sealed;
			virtual void BlockHarvesterSpawn() sealed;
			virtual void SetAllowHarvesterSpawn() sealed;

			property IntPtr RefineryGameObjPointer
			{
				virtual IntPtr get() sealed;
			}

			property IRefineryGameObjDef ^Definition
			{
#pragma push_macro("new")
#undef new

				virtual IRefineryGameObjDef ^get() new sealed;

#pragma pop_macro("new")
			}

			property bool NeedsHarvester
			{
				virtual bool get() sealed;
			}

			property int HarvesterDefId
			{
				virtual int get() sealed;
			}

			property bool IsHarvesterDocked
			{
				virtual bool get() sealed;
			}

			property IVehicleGameObj ^HarvesterVehicle
			{
				virtual IVehicleGameObj ^get() sealed;
			}

			property IHarvesterClass ^Harvester
			{
				virtual IHarvesterClass ^get() sealed;
				virtual void set(IHarvesterClass ^value) sealed;
			}

			property Matrix3D DockTM
			{
				virtual Matrix3D get() sealed;
				virtual void set(Matrix3D value) sealed;
			}

			property bool AllowHarvesterSpawn
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

			property ::RefineryGameObj *InternalRefineryGameObjPointer
			{
				virtual ::RefineryGameObj *get();
			}
	};
}