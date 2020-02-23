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

class AirFactoryGameObjDef;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IAirFactoryGameObjDef : public IBuildingGameObjDef
	{
		property IntPtr AirFactoryGameObjDefPointer
		{
			IntPtr get();
		}

		property int LandingPosDefId
		{
			int get();
			void set(int value);
		}

		property float LandingPosDistance
		{
			float get();
			void set(float value);
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

		property float CinematicTimer
		{
			float get();
			void set(float value);
		}

		property bool DefaultEngineEnable
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class AirFactoryGameObjDef : public BuildingGameObjDef, public IAirFactoryGameObjDef
	{
		public:
			AirFactoryGameObjDef(IntPtr pointer);

			property IntPtr AirFactoryGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

			property int LandingPosDefId
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property float LandingPosDistance
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
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

			property float CinematicTimer
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool DefaultEngineEnable
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			property ::BuildingGameObjDef *InternalBuildingGameObjDefPointer
			{
				::BuildingGameObjDef *get() override;
			}

			property ::AirFactoryGameObjDef *InternalAirFactoryGameObjDefPointer
			{
				virtual ::AirFactoryGameObjDef *get();
			}
	};
}