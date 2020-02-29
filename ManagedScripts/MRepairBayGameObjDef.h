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

#include "MBuildingGameObjDef.h"

#pragma managed(push, off)

class RepairBayGameObjDef;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IRepairBayGameObjDef : public IBuildingGameObjDef
	{
		literal unsigned int RepairBayGameObjDefClassID = 53257;

		property IntPtr RepairBayGameObjDefPointer
		{
			IntPtr get();
		}

		property float RepairPerSec
		{
			float get();
			void set(float value);
		}

		property int RepairingStaticAnimDefID
		{
			int get();
			void set(int value);
		}
	};

	public ref class RepairBayGameObjDef : public BuildingGameObjDef, public IRepairBayGameObjDef
	{
		public:
			RepairBayGameObjDef(IntPtr pointer);

			property IntPtr RepairBayGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

			property float RepairPerSec
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int RepairingStaticAnimDefID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

		protected:
			property ::BuildingGameObjDef *InternalBuildingGameObjDefPointer
			{
				::BuildingGameObjDef *get() override;
			}

			property ::RepairBayGameObjDef *InternalRepairBayGameObjDefPointer
			{
				virtual ::RepairBayGameObjDef *get();
			}
	};
}