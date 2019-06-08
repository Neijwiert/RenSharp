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

#include "MSimpleGameObj.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <BeaconGameObj.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	interface class IBeaconGameObjDef;
	interface class IPlayerDataClass;
	interface class IWeaponDefinitionClass;

	public interface class IBeaconGameObj
	{
		property IntPtr BeaconGameObjPointer
		{
			IntPtr get();
		}

		property IBeaconGameObjDef ^Definition
		{
			IBeaconGameObjDef ^get();
		}

		property IPlayerDataClass ^PlayerData
		{
			IPlayerDataClass ^get();
		}

		property int State
		{
			int get();
		}

		property float ArmTime
		{
			float get();
		}

		property float DetonateTime
		{
			float get();
		}

		property IWeaponDefinitionClass ^WeaponDef
		{
			IWeaponDefinitionClass ^get();
		}
	};

	public ref class BeaconGameObj : public SimpleGameObj, public IBeaconGameObj
	{
		public:
			enum class BeaconState : int
			{
				State0 = 0,
				StateDeploying = 1,
				StateDeployed = 2,
				StateDisarmed = 3,
				StateDetonated = 4
			};

			BeaconGameObj(IntPtr pointer);

			IBeaconGameObj ^AsBeaconGameObj() override;

			property IntPtr BeaconGameObjPointer
			{
				virtual IntPtr get() sealed;
			}

#pragma push_macro("new")
#undef new

			property IBeaconGameObjDef ^Definition
			{
				virtual IBeaconGameObjDef ^get() new;
			}

#pragma pop_macro("new")

			property IPlayerDataClass ^PlayerData
			{
				virtual IPlayerDataClass ^get() sealed;
			}

			property int State
			{
				virtual int get() sealed;
			}

			property float ArmTime
			{
				virtual float get() sealed;
			}

			property float DetonateTime
			{
				virtual float get() sealed;
			}

			property IWeaponDefinitionClass ^WeaponDef
			{
				virtual IWeaponDefinitionClass ^get() sealed;
			}

		protected:
			property ::SimpleGameObj *InternalSimpleGameObjPointer
			{
				::SimpleGameObj *get() override;
			}

			property ::BeaconGameObj *InternalBeaconGameObjPointer
			{
				virtual ::BeaconGameObj *get();
			}
	};
}