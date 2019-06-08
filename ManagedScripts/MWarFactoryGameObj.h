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

#include "MVehicleFactoryGameObj.h"

#pragma managed(push, off)

class WarFactoryGameObj;

#pragma managed(pop)

namespace RenSharp
{
	interface class IWarFactoryGameObjDef;

	public interface class IWarFactoryGameObj : public IVehicleFactoryGameObj
	{
		property IntPtr WarFactoryGameObjPointer
		{
			IntPtr get();
		}

		property IWarFactoryGameObjDef ^Definition
		{
			IWarFactoryGameObjDef ^get();
		}
	};

	public ref class WarFactoryGameObj : public VehicleFactoryGameObj, public IWarFactoryGameObj
	{
		public:
			WarFactoryGameObj(IntPtr pointer);

			IWarFactoryGameObj ^AsWarFactoryGameObj() override;

			property IntPtr WarFactoryGameObjPointer
			{
				virtual IntPtr get() sealed;
			}

			property IWarFactoryGameObjDef ^Definition
			{
#pragma push_macro("new")
#undef new

				virtual IWarFactoryGameObjDef ^get() new sealed;

#pragma pop_macro("new")
			}

		protected:
			property ::VehicleFactoryGameObj *InternalVehicleFactoryGameObjPointer
			{
				::VehicleFactoryGameObj *get() override;
			}

			property ::WarFactoryGameObj *InternalWarFactoryGameObjPointer
			{
				virtual ::WarFactoryGameObj *get();
			}

			property int CreationAnimationID
			{
				int get();
				void set(int value);
			}

			property float CreationFinishedTimer
			{
				float get();
				void set(float value);
			}
	};
}