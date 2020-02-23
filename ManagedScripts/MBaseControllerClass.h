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

#include "Mengine_io.h"
#include "MNetworkObjectClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <BaseControllerClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	interface class IBuildingGameObj;
	interface class IVehicleGameObj;
	value class OBBoxClass;

	public enum class RadarMode
	{
		RadarNobody = ::RADAR_NOBODY,
		RadarTeammates = ::RADAR_TEAMMATES,
		RadarAll = ::RADAR_ALL
	};

	public interface class IBaseControllerClass : public INetworkObjectClass
	{
		IBuildingGameObj ^FindBuilding(unsigned int type);

		void DestroyBase();

		property IntPtr BaseControllerClassPointer
		{
			IntPtr get();
		}

		property IVehicleGameObj ^HarvesterVehicle
		{
			IVehicleGameObj ^get();
		}

		property bool IsBasePowered
		{
			bool get();
		}

		property bool CanGenerateSoldiers
		{
			bool get();
			void set(bool value);
		}

		property bool CanGenerateVehicles
		{
			bool get();
			void set(bool value);
		}

		property bool BaseDestroyed
		{
			bool get();
			void set(bool value);
		}

		property bool BeaconDestroyedBase
		{
			bool get();
			void set(bool value);
		}

		property bool IsRadarEnabled
		{
			bool get();
			void set(bool value);
		}

		property float OperationTimeFactor
		{
			float get();
		}

		property int PlayerType
		{
			int get();
		}

		property OBBoxClass BeaconZone
		{
			OBBoxClass get();
		}

		property IDynamicVectorClass<IBuildingGameObj ^> ^BuildingList
		{
			IDynamicVectorClass<IBuildingGameObj ^> ^get();
		}
	};

	public ref class BaseControllerClass : public NetworkObjectClass, public IBaseControllerClass
	{
		public:
			BaseControllerClass(IntPtr pointer);

			virtual IBuildingGameObj ^FindBuilding(unsigned int type) sealed;
			virtual void DestroyBase() sealed;

			property IntPtr BaseControllerClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IVehicleGameObj ^HarvesterVehicle
			{
				virtual IVehicleGameObj ^get() sealed;
			}

			property bool IsBasePowered
			{
				virtual bool get() sealed;
			}

			property bool CanGenerateSoldiers
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool CanGenerateVehicles
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool BaseDestroyed
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool BeaconDestroyedBase
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsRadarEnabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property float OperationTimeFactor
			{
				virtual float get() sealed;
			}

			property int PlayerType
			{
				virtual int get() sealed;
			}

			property OBBoxClass BeaconZone
			{
				virtual OBBoxClass get() sealed;
			}

			property IDynamicVectorClass<IBuildingGameObj ^> ^BuildingList
			{
				virtual IDynamicVectorClass<IBuildingGameObj ^> ^get() sealed;
			}

		protected:
			property ::NetworkObjectClass *InternalNetworkObjectClassPointer
			{
				::NetworkObjectClass *get() override;
			}

			property ::BaseControllerClass *InternalBaseControllerClassPointer
			{
				virtual ::BaseControllerClass *get();
			}
	};
}