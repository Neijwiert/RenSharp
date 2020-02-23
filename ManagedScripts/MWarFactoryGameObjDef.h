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

#include "MVehicleFactoryGameObjDef.h"

#pragma managed(push, off)

class WarFactoryGameObjDef;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IWarFactoryGameObjDef : public IVehicleFactoryGameObjDef
	{
		property IntPtr WarFactoryGameObjDefPointer
		{
			IntPtr get();
		}
	};

	public ref class WarFactoryGameObjDef : public VehicleFactoryGameObjDef, public IWarFactoryGameObjDef
	{
		public:
			WarFactoryGameObjDef(IntPtr pointer);

			property IntPtr WarFactoryGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::VehicleFactoryGameObjDef *InternalVehicleFactoryGameObjDefPointer
			{
				::VehicleFactoryGameObjDef *get() override;
			}

			property ::WarFactoryGameObjDef *InternalWarFactoryGameObjDefPointer
			{
				virtual ::WarFactoryGameObjDef *get();
			}
	};
}