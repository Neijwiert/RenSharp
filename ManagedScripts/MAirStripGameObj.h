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

#include "MVehicleFactoryGameObj.h"

#pragma managed(push, off)

class AirStripGameObj;

#pragma managed(pop)

namespace RenSharp
{
	interface class IAirStripGameObjDef;

	public interface class IAirStripGameObj : public IVehicleFactoryGameObj
	{
		property IntPtr AirStripGameObjPointer
		{
			IntPtr get();
		}

		property IAirStripGameObjDef ^Definition
		{
			IAirStripGameObjDef ^get();
		}
	};

	public ref class AirStripGameObj : public VehicleFactoryGameObj, public IAirStripGameObj
	{
		public:
			AirStripGameObj(IntPtr pointer);

			IAirStripGameObj ^AsAirStripGameObj() override;

			property IntPtr AirStripGameObjPointer
			{
				virtual IntPtr get() sealed;
			}

			property IAirStripGameObjDef ^Definition
			{
#pragma push_macro("new")
#undef new

				virtual IAirStripGameObjDef ^get() new sealed;

#pragma pop_macro("new")

			}

		protected:
			property ::VehicleFactoryGameObj *InternalVehicleFactoryGameObjPointer
			{
				::VehicleFactoryGameObj *get() override;
			}

			property ::AirStripGameObj *InternalAirStripGameObjPointer
			{
				virtual ::AirStripGameObj *get();
			}
	};
}