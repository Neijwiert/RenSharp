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

#include "AbstractUnmanagedObject.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <HumanStateClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{

#pragma warning(push)
#pragma warning(disable : 4099 4251 4244 26495 26454)

	value class Matrix3D;

#pragma warning(pop) 

	public interface class IHumanStateClass
	{
		enum class HumanStateType : int
		{
			Upright = ::HumanStateClass::UPRIGHT,
			Land = ::HumanStateClass::LAND,
			Animation = ::HumanStateClass::ANIMATION,
			Wounded = ::HumanStateClass::WOUNDED,
			Loiter = ::HumanStateClass::LOITER,
			Airborne = ::HumanStateClass::AIRBORNE,
			Dive = ::HumanStateClass::DIVE,
			Death = ::HumanStateClass::DEATH,
			Ladder = ::HumanStateClass::LADDER,
			InVehicle = ::HumanStateClass::IN_VEHICLE,
			Transition = ::HumanStateClass::TRANSITION,
			TransitionComplete = ::HumanStateClass::TRANSITION_COMPLETE,
			Destroy = ::HumanStateClass::DESTROY,
			DebugFly = ::HumanStateClass::DEBUG_FLY,
			OnFire = ::HumanStateClass::ON_FIRE,
			OnChem = ::HumanStateClass::ON_CHEM,
			OnElectric = ::HumanStateClass::ON_ELECTRIC,
			OnCnCFire = ::HumanStateClass::ON_CNC_FIRE,
			OnCnCChem = ::HumanStateClass::ON_CNC_CHEM,
			LockedAnimation = ::HumanStateClass::LOCKED_ANIMATION,
			HighestHumanState = ::HumanStateClass::HIGHEST_HUMAN_STATE
		};

		enum class HumanStateFlagsType : int
		{
			CrouchedFlag = ::HumanStateClass::CROUCHED_FLAG,
			SnipingFlag = ::HumanStateClass::SNIPING_FLAG,
			HighestHumanStateFlags = ::HumanStateClass::HIGHEST_HUMAN_STATE_FLAGS
		};

		enum class HumanSubStateType : int
		{
			SubStateForward = ::HumanStateClass::SUB_STATE_FORWARD,
			SubStateBackward = ::HumanStateClass::SUB_STATE_BACKWARD,
			SubStateUp = ::HumanStateClass::SUB_STATE_UP,
			SubStateDown = ::HumanStateClass::SUB_STATE_DOWN,
			SubStateLeft = ::HumanStateClass::SUB_STATE_LEFT,
			SubStateRight = ::HumanStateClass::SUB_STATE_RIGHT,
			SubStateTurnLeft = ::HumanStateClass::SUB_STATE_TURN_LEFT,
			SubStateTurnRight = ::HumanStateClass::SUB_STATE_TURN_RIGHT,
			SubStateSlow = ::HumanStateClass::SUB_STATE_SLOW,
			HighestHumanSubState = ::HumanStateClass::HIGHEST_HUMAN_SUB_STATE
		};

		enum class HumanOuchType : int
		{
			HeadFromBehind =::HumanStateClass::HEAD_FROM_BEHIND,
			HeadFromFront = ::HumanStateClass::HEAD_FROM_FRONT,
			TorsoFromBehind = ::HumanStateClass::TORSO_FROM_BEHIND,
			TorsoFromFront = ::HumanStateClass::TORSO_FROM_FRONT,
			LeftArmFromBehind = ::HumanStateClass::LEFT_ARM_FROM_BEHIND,
			LeftArmFromFront = ::HumanStateClass::LEFT_ARM_FROM_FRONT,
			RightArmFromBehind = ::HumanStateClass::RIGHT_ARM_FROM_BEHIND,
			RightArmFromFront = ::HumanStateClass::RIGHT_ARM_FROM_FRONT,
			LeftLegFromBehind = ::HumanStateClass::LEFT_LEG_FROM_BEHIND,
			LeftLegFromFront = ::HumanStateClass::LEFT_LEG_FROM_FRONT,
			RightLegFromBehind = ::HumanStateClass::RIGHT_LEG_FROM_BEHIND,
			RightLegFromFront = ::HumanStateClass::RIGHT_LEG_FROM_FRONT,
			Groin = ::HumanStateClass::GROIN,
			OuchFire = ::HumanStateClass::OUCH_FIRE,
			OuchChem = ::HumanStateClass::OUCH_CHEM,
			OuchElectric = ::HumanStateClass::OUCH_ELECTRIC,
			OuchSuperFire = ::HumanStateClass::OUCH_SUPER_FIRE
		};

		void ToggleStateFlag(int flag);

		bool GetStateFlag(int flag);

		void DropWeapon();

		void RaiseWeapon();

		void SetTurnVelocity(float vel);

		property IntPtr HumanStateClassPointer
		{
			IntPtr get();
		}

		property HumanStateType State
		{
			HumanStateType get();
		}

		property int SubState
		{
			int get();
		}

		property float StateTimer
		{
			float get();
			void set(float value);
		}

		property bool IsLocked
		{
			bool get();
		}

		property Matrix3D JumpTransform
		{
			Matrix3D get();
			void set(Matrix3D value);
		}
	};

	public ref class HumanStateClass : public AbstractUnmanagedObject, public IHumanStateClass
	{
		public:
			HumanStateClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual void ToggleStateFlag(int flag) sealed;
			virtual bool GetStateFlag(int flag) sealed;
			virtual void DropWeapon() sealed;
			virtual void RaiseWeapon() sealed;
			virtual void SetTurnVelocity(float vel) sealed;

			property IntPtr HumanStateClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IHumanStateClass::HumanStateType State
			{
				virtual IHumanStateClass::HumanStateType get() sealed;
			}

			property int SubState
			{
				virtual int get() sealed;
			}

			property float StateTimer
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool IsLocked
			{
				virtual bool get() sealed;
			}

			property Matrix3D JumpTransform
			{
				virtual Matrix3D get() sealed;
				virtual void set(Matrix3D value) sealed;
			}

		protected:
			property ::HumanStateClass *InternalHumanStateClassPointer
			{
				virtual ::HumanStateClass *get();
			}
	};
}