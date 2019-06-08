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

#include "MVehicleFactoryGameObjDef.h"

#pragma managed(push, off)

class AirStripGameObjDef;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IAirStripGameObjDef : public IVehicleFactoryGameObjDef
	{
		property IntPtr AirStripGameObjDefPointer
		{
			IntPtr get();
		}

		property int DropCinematicDefId
		{
			int get();
			void set(int value);
		}

		property int CinematicSlotIndex
		{
			int get();
			void set(int value);
		}

		property float CinematicLengthToDropOff
		{
			float get();
			void set(float value);
		}

		property float CinematicLengthToVehicleDisplay
		{
			float get();
			void set(float value);
		}

		property bool HideVehicles
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class AirStripGameObjDef : public VehicleFactoryGameObjDef, public IAirStripGameObjDef
	{
		public:
			AirStripGameObjDef(IntPtr pointer);

			property IntPtr AirStripGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

			property int DropCinematicDefId
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int CinematicSlotIndex
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property float CinematicLengthToDropOff
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float CinematicLengthToVehicleDisplay
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool HideVehicles
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			property ::VehicleFactoryGameObjDef *InternalVehicleFactoryGameObjDefPointer
			{
				::VehicleFactoryGameObjDef *get() override;
			}

			property ::AirStripGameObjDef *InternalAirStripGameObjDefPointer
			{
				virtual ::AirStripGameObjDef *get();
			}
	};
}