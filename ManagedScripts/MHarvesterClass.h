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

#include "Mscripts.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4091 4251 4244 26495 26454)
#include <HarvesterClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{

#pragma warning(push)
#pragma warning(disable : 4099 4251 4244 26495 26454)

	interface class IVehicleGameObj;
	interface class IRefineryGameObj;
	value class Vector3;
	value class OBBoxClass;

#pragma warning(pop) 

	public interface class IHarvesterClass : public IGameObjObserverClass
	{
		enum class HarvesterState : int
		{
			NoState = ::HarvesterClass::NoState,
			StateGoingToHarvest = ::HarvesterClass::StateGoingToHarvest,
			StateHarvesting = ::HarvesterClass::StateHarvesting,
			StateGoingToUnload = ::HarvesterClass::StateGoingToUnload,
			StateUnloading = ::HarvesterClass::StateUnloading
		};

		void SetRefinery(IRefineryGameObj ^obj);

		void SetDockLocation(Vector3 location);

		void SetDockEntrance(Vector3 location);

		void SetTiberiumRegion(OBBoxClass region);

		void SetHarvestAnim(String ^anim);

		property IntPtr HarvesterClassPointer
		{
			IntPtr get();
		}

		property IVehicleGameObj ^Vehicle
		{
			IVehicleGameObj ^get();
		}

		property HarvesterState State
		{
			HarvesterState get();
		}
	};

	public ref class HarvesterClass : public GameObjObserverClass, public IHarvesterClass
	{
		public:
			HarvesterClass(IntPtr pointer);

			virtual void SetRefinery(IRefineryGameObj ^obj) sealed;
			virtual void SetDockLocation(Vector3 location) sealed;
			virtual void SetDockEntrance(Vector3 location) sealed;
			virtual void SetTiberiumRegion(OBBoxClass region) sealed;
			virtual void SetHarvestAnim(String ^anim) sealed;

			property IntPtr HarvesterClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IVehicleGameObj ^Vehicle
			{
				virtual IVehicleGameObj ^get() sealed;
			}

			property IHarvesterClass::HarvesterState State
			{
				virtual IHarvesterClass::HarvesterState get() sealed;
			}

		protected:
			property ::GameObjObserverClass *InternalGameObjObserverClassPointer
			{
				::GameObjObserverClass *get() override;
			}

			property ::HarvesterClass *InternalHarvesterClassPointer
			{
				virtual ::HarvesterClass *get();
			}
	};
}