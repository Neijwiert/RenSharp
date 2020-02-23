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

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <PowerupGameObj.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MSimpleGameObj.h"

namespace RenSharp
{

#pragma managed(push, off)

	class PowerUpGameObjHelper : public ::PowerUpGameObj
	{
		private:
			PowerUpGameObjHelper() = default;

		public:
			static const int STATE_BECOMING_IDLE = ::PowerUpGameObj::STATE_BECOMING_IDLE;
			static const int STATE_IDLING = ::PowerUpGameObj::STATE_IDLING;
			static const int STATE_GRANTING = ::PowerUpGameObj::STATE_GRANTING;
			static const int STATE_EXPIRING = ::PowerUpGameObj::STATE_EXPIRING;

			int &GetState()
			{
				return State;
			}

			float &GetStateEndTimer()
			{
				return StateEndTimer;
			}

			::AudibleSoundClass*& GetIdleSoundObj()
			{
				return IdleSoundObj;
			}

			::WeaponBagClass*& GetWeaponBag()
			{
				return WeaponBag;
			}
	};

#pragma managed(pop)

	interface class ISmartGameObj;
	interface class IPowerUpGameObjDef;
	interface class IAudibleSoundClass;
	interface class IWeaponBagClass;

	public interface class IPowerUpGameObj : public ISimpleGameObj
	{
		property IntPtr PowerUpGameObjPointer
		{
			IntPtr get();
		}

		property IPowerUpGameObjDef ^Definition
		{
			IPowerUpGameObjDef ^get();
		}
	};

	public ref class PowerUpGameObj : public SimpleGameObj, public IPowerUpGameObj
	{
		public:
			PowerUpGameObj(IntPtr pointer);

			IPowerUpGameObj ^AsPowerUpGameObj() override;

			property IntPtr PowerUpGameObjPointer
			{
				virtual IntPtr get() sealed;
			}

#pragma push_macro("new")
#undef new

			property IPowerUpGameObjDef ^Definition
			{
				virtual IPowerUpGameObjDef ^get() new;
			}

#pragma pop_macro("new")

		protected:
			enum class PowerUpGameObjState : int
			{
				StateBecomingIdle = PowerUpGameObjHelper::STATE_BECOMING_IDLE,
				StateIdling = PowerUpGameObjHelper::STATE_IDLING,
				StateGranting = PowerUpGameObjHelper::STATE_GRANTING,
				StateExpiring = PowerUpGameObjHelper::STATE_EXPIRING
			};

			property ::SimpleGameObj *InternalSimpleGameObjPointer
			{
				::SimpleGameObj *get() override;
			}

			property ::PowerUpGameObj *InternalPowerUpGameObjPointer
			{
				virtual ::PowerUpGameObj *get();
			}

			property IAudibleSoundClass ^IdleSoundObj
			{
				IAudibleSoundClass ^get();
				void set(IAudibleSoundClass ^value);
			}

			property int State
			{
				int get();
				void set(int value);
			}

			property float StateEndTimer
			{
				float get();
				void set(float value);
			}

			property IWeaponBagClass ^WeaponBag
			{
				IWeaponBagClass ^get();
				void set(IWeaponBagClass ^value);
			}
	};
}