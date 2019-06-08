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

#include "MBuildingGameObjDef.h"

#pragma managed(push, off)

class ConstructionYardGameObjDef;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IConstructionYardGameObjDef : public IBuildingGameObjDef
	{
		property IntPtr ConstructionYardGameObjDefPointer
		{
			IntPtr get();
		}

		property float RepairRate
		{
			float get();
			void set(float value);
		}

		property float VehicleRepairRate
		{
			float get();
			void set(float value);
		}

		property float RepairAmount
		{
			float get();
			void set(float value);
		}

		property float LowPowerRepairAmount
		{
			float get();
			void set(float value);
		}

		property int RepairWarhead
		{
			int get();
			void set(int value);
		}
	};

	public ref class ConstructionYardGameObjDef : public BuildingGameObjDef, public IConstructionYardGameObjDef
	{
		public:
			ConstructionYardGameObjDef(IntPtr pointer);

			property IntPtr ConstructionYardGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

			property float RepairRate
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float VehicleRepairRate
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float RepairAmount
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float LowPowerRepairAmount
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int RepairWarhead
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

		protected:
			property ::BuildingGameObjDef *InternalBuildingGameObjDefPointer
			{
				::BuildingGameObjDef *get() override;
			}

			property ::ConstructionYardGameObjDef *InternalConstructionYardGameObjDefPointer
			{
				virtual ::ConstructionYardGameObjDef *get();
			}
	};
}