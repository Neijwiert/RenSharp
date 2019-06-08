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

#include "MArmedGameObj.h"
#include "MControlClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <SmartGameObj.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{

#pragma warning(push)
#pragma warning(disable : 4099 4251 4244 26495 26454)

	interface class ISmartGameObjDef;
	interface class IPlayerDataClass;
	interface class IActionClass;
	value class Matrix3D;
	value class Vector3;
	interface class IStealthEffectClass;
	interface class IPhysControllerClass;

#pragma warning(pop) 

	public interface class ISmartGameObj : public IArmedGameObj
	{
		literal int ServerControlOwner = ::SmartGameObj::SERVER_CONTROL_OWNER;

		void SetAnalogControl(IControlClass::AnalogControl control, float value);

		void GenerateControl();

		void ApplyControl();

		bool IsObjVisible(IPhysicalGameObj ^obj);

		bool IsSplashPossible(IPhysicalGameObj ^obj);

		property IntPtr SmartGameObjPointer
		{
			IntPtr get();
		}

		property ISmartGameObjDef ^Definition
		{
			ISmartGameObjDef ^get();
		}

		property IControlClass ^Control
		{
			IControlClass ^get();
			void set(IControlClass ^value);
		}

		property bool ControlEnabled
		{
			bool get();
			void set(bool value);
		}

		property int ControlOwner
		{
			int get();
			void set(int value);
		}

		property int WeaponControlOwner
		{
			int get();
		}

		property IPlayerDataClass ^PlayerData
		{
			IPlayerDataClass ^get();
		}

		property bool HasPlayer
		{
			bool get();
		}

		property bool IsHumanControlled
		{
			bool get();
		}

		property float MaxSpeed
		{
			float get();
		}

		property float TurnRate
		{
			float get();
		}

		property IActionClass ^Action
		{
			IActionClass ^get();
		}

		property bool IsEnemySeenEnabled
		{
			bool get();
			void set(bool value);
		}

		property Matrix3D LookTransform
		{
			Matrix3D get();
		}

		property Vector3 Velocity
		{
			Vector3 get();
		}

		property bool IsVisible
		{
			bool get();
		}

		property bool IsStealthEnabled
		{
			bool get();
		}

		property bool IsStealthed
		{
			bool get();
		}

		property float StealthFadeDistance
		{
			float get();
		}

		property IStealthEffectClass ^StealthEffect
		{
			IStealthEffectClass ^get();
		}

		property bool IsStealthActive
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class SmartGameObj : public ArmedGameObj, public ISmartGameObj
	{
		public:
			SmartGameObj(IntPtr pointer);

			ISmartGameObj ^AsSmartGameObj() override;

			virtual void SetAnalogControl(IControlClass::AnalogControl control, float value) sealed;
			virtual void GenerateControl() sealed;
			virtual void ApplyControl() sealed;
			virtual bool IsObjVisible(IPhysicalGameObj ^obj) sealed;
			virtual bool IsSplashPossible(IPhysicalGameObj ^obj) sealed;

			property IntPtr SmartGameObjPointer
			{
				virtual IntPtr get() sealed;
			}

#pragma push_macro("new")
#undef new

			property ISmartGameObjDef ^Definition
			{
				virtual ISmartGameObjDef ^get() new sealed;
			}

#pragma pop_macro("new")

			property IControlClass ^Control
			{
				virtual IControlClass ^get() sealed;
				virtual void set(IControlClass ^value) sealed;
			}

			property bool ControlEnabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property int ControlOwner
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int WeaponControlOwner
			{
				virtual int get() sealed;
			}

			property IPlayerDataClass ^PlayerData
			{
				virtual IPlayerDataClass ^get() sealed;
			}

			property bool HasPlayer
			{
				virtual bool get() sealed;
			}

			property bool IsHumanControlled
			{
				virtual bool get() sealed;
			}

			property float MaxSpeed
			{
				virtual float get();
			}

			property float TurnRate
			{
				virtual float get() sealed;
			}

			property IActionClass ^Action
			{
				virtual IActionClass ^get() sealed;
			}

			property bool IsEnemySeenEnabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property Matrix3D LookTransform
			{
				virtual Matrix3D get() sealed;
			}

			property Vector3 Velocity
			{
				virtual Vector3 get() sealed;
			}

			property bool IsVisible
			{
				virtual bool get();
			}

			property bool IsStealthEnabled
			{
				virtual bool get() sealed;
			}

			property bool IsStealthed
			{
				virtual bool get() sealed;
			}

			property float StealthFadeDistance
			{
				virtual float get() sealed;
			}

			property IStealthEffectClass ^StealthEffect
			{
				virtual IStealthEffectClass ^get() sealed;

				protected:
					void set(IStealthEffectClass ^value);
			}

			property bool IsStealthActive
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			property ::ArmedGameObj *InternalArmedGameObjPointer
			{
				::ArmedGameObj *get() override;
			}

			property ::SmartGameObj *InternalSmartGameObjPointer
			{
				virtual ::SmartGameObj *get();
			}

			property IPhysControllerClass ^Controller
			{
				IPhysControllerClass ^get();
				void set(IPhysControllerClass ^value);
			}

			property bool StealthEnabled
			{
				bool get();
				void set(bool value);
			}

			property bool StealthActive
			{
				bool get();
				void set(bool value);
			}

			property float StealthPowerupTimer
			{
				float get();
				void set(float value);
			}

			property float StealthFiringTimer
			{
				float get();
				void set(float value);
			}
	};
}