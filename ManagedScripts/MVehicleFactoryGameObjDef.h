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

class VehicleFactoryGameObjDef;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IVehicleFactoryGameObjDef : public IBuildingGameObjDef
	{
		property IntPtr VehicleFactoryGameObjDefPointer
		{
			IntPtr get();
		}

		property int PadClearingWarhead
		{
			int get();
			void set(int value);
		}

		property float TotalBuildingTime
		{
			float get();
			void set(float value);
		}

		property bool EnableFlyingWaypaths
		{
			bool get();
			void set(bool value);
		}

		property bool BuildGroundOnly
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class VehicleFactoryGameObjDef : public BuildingGameObjDef, public IVehicleFactoryGameObjDef
	{
		public:
			VehicleFactoryGameObjDef(IntPtr pointer);

			property IntPtr VehicleFactoryGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

			property int PadClearingWarhead
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property float TotalBuildingTime
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool EnableFlyingWaypaths
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool BuildGroundOnly
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			property ::BuildingGameObjDef *InternalBuildingGameObjDefPointer
			{
				::BuildingGameObjDef *get() override;
			}

			property ::VehicleFactoryGameObjDef *InternalVehicleFactoryGameObjDefPointer
			{
				virtual ::VehicleFactoryGameObjDef *get();
			}
	};
}