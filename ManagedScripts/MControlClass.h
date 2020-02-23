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

#include "AbstractUnmanagedObject.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <ControlClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	public interface class IControlClass : public IUnmanagedObject 
	{
		enum class BooleanControl : int
		{
			BooleanOneTimeFirst = ::ControlClass::BOOLEAN_ONE_TIME_FIRST,
			BooleanJump = ::ControlClass::BOOLEAN_JUMP,
			BooleanWeaponNext = ::ControlClass::BOOLEAN_WEAPON_NEXT,
			BooleanWeaponPrev = ::ControlClass::BOOLEAN_WEAPON_PREV,
			BooleanWeaponReload = ::ControlClass::BOOLEAN_WEAPON_RELOAD,
			BooleanWeaponUse = ::ControlClass::BOOLEAN_WEAPON_USE,
			BooleanDiveForward = ::ControlClass::BOOLEAN_DIVE_FORWARD,
			BooleanDiveBackward = ::ControlClass::BOOLEAN_DIVE_BACKWARD,
			BooleanDiveLeft = ::ControlClass::BOOLEAN_DIVE_LEFT,
			BooleanDiveRight = ::ControlClass::BOOLEAN_DIVE_RIGHT,
			BooleanAction = ::ControlClass::BOOLEAN_ACTION,
			BooleanSelectNoWeapon = ::ControlClass::BOOLEAN_SELECT_NO_WEAPON,
			BooleanSelectWeapon0 = ::ControlClass::BOOLEAN_SELECT_WEAPON_0,
			BooleanSelectWeapon1 = ::ControlClass::BOOLEAN_SELECT_WEAPON_1,
			BooleanSelectWeapon2 = ::ControlClass::BOOLEAN_SELECT_WEAPON_2,
			BooleanSelectWeapon3 = ::ControlClass::BOOLEAN_SELECT_WEAPON_3,
			BooleanSelectWeapon4 = ::ControlClass::BOOLEAN_SELECT_WEAPON_4,
			BooleanSelectWeapon5 = ::ControlClass::BOOLEAN_SELECT_WEAPON_5,
			BooleanSelectWeapon6 = ::ControlClass::BOOLEAN_SELECT_WEAPON_6,
			BooleanSelectWeapon7 = ::ControlClass::BOOLEAN_SELECT_WEAPON_7,
			BooleanSelectWeapon8 = ::ControlClass::BOOLEAN_SELECT_WEAPON_8,
			BooleanSelectWeapon9 = ::ControlClass::BOOLEAN_SELECT_WEAPON_9,
			BooleanDropFlag = ::ControlClass::BOOLEAN_DROP_FLAG,
			BooleanVehicleToggleGunner = ::ControlClass::BOOLEAN_VEHICLE_TOGGLE_GUNNER,
			BooleanContinuousFirst = ::ControlClass::BOOLEAN_CONTINUOUS_FIRST,
			BooleanWeaponFirePrimary = ::ControlClass::BOOLEAN_WEAPON_FIRE_PRIMARY,
			BooleanWeaponFireSecondary = ::ControlClass::BOOLEAN_WEAPON_FIRE_SECONDARY,
			BooleanWalk = ::ControlClass::BOOLEAN_WALK,
			BooleanCrouch = ::ControlClass::BOOLEAN_CROUCH,
			BooleanTotal = ::ControlClass::BOOLEAN_TOTAL,
			NumBooleanOneTime = ::ControlClass::NUM_BOOLEAN_ONE_TIME,
			NumBooleanContinuous = ::ControlClass::NUM_BOOLEAN_CONTINUOUS
		};

		enum class AnalogControl : int
		{
			AnalogMoveForward = ::ControlClass::ANALOG_MOVE_FORWARD,
			AnalogMoveLeft = ::ControlClass::ANALOG_MOVE_LEFT,
			AnalogMoveUp = ::ControlClass::ANALOG_MOVE_UP,
			AnalogTurnLeft = ::ControlClass::ANALOG_TURN_LEFT
		};

		void ClearOneTimeBoolean();

		void ClearAnalog();

		void SetAnalog(AnalogControl control, float value);

		float GetAnalog(AnalogControl control);

		property IntPtr ControlClassPointer
		{
			IntPtr get();
		}

		property bool ActionTrigger
		{
			bool get();
			void set(bool value);
		}

		property unsigned long OneTimeBooleanBits
		{
			unsigned long get();
		}

		property unsigned char ContinuousBooleanBits
		{
			unsigned char get();
		}
	};

	public ref class ControlClass : public AbstractUnmanagedObject, public IControlClass
	{
		public:
			ControlClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual void ClearOneTimeBoolean() sealed;
			virtual void ClearAnalog() sealed;
			virtual void SetAnalog(IControlClass::AnalogControl control, float value) sealed;
			virtual float GetAnalog(IControlClass::AnalogControl control) sealed;

			property IntPtr ControlClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool ActionTrigger
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property unsigned long OneTimeBooleanBits
			{
				virtual unsigned long get() sealed;
			}

			property unsigned char ContinuousBooleanBits
			{
				virtual unsigned char get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::ControlClass *InternalControlClassPointer
			{
				virtual ::ControlClass *get();
			}
	};
}