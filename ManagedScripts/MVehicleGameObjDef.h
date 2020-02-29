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

#include "MSmartGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <VehicleGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	value class Vector3;
	interface class ITransitionDataClass;

	public enum class EngineSoundState : int
	{
		EngineSoundStateStarting = ::ENGINE_SOUND_STATE_STARTING,
		EngineSoundStateRunning = ::ENGINE_SOUND_STATE_RUNNING,
		EngineSoundStateStopping = ::ENGINE_SOUND_STATE_STOPPING,
		EngineSoundStateOff = ::ENGINE_SOUND_STATE_OFF
	};

	public enum class VehicleType : int
	{
		VehicleTypeCar = ::VEHICLE_TYPE_CAR,
		VehicleTypeTank = ::VEHICLE_TYPE_TANK,
		VehicleTypeBike = ::VEHICLE_TYPE_BIKE,
		VehicleTypeFlying = ::VEHICLE_TYPE_FLYING,
		VehicleTypeTurret = ::VEHICLE_TYPE_TURRET,
		VehicleTypeBoat = ::VEHICLE_TYPE_BOAT,
		VehicleTypeSub = ::VEHICLE_TYPE_SUB
	};

	public interface class IVehicleGameObjDef : public ISmartGameObjDef
	{
		literal unsigned int VehicleGameObjDefClassID = 12304;

		int GetEngineSound(VehicleType type);

		property IntPtr VehicleGameObjDefPointer
		{
			IntPtr get();
		}

		property VehicleType Type
		{
			VehicleType get();
			void set(VehicleType value);
		}

		property String ^TypeName
		{
			String ^get();
			void set(String ^value);
		}

		property String ^Fire0Anim
		{
			String ^get();
			void set(String ^value);
		}

		property String ^Fire1Anim
		{
			String ^get();
			void set(String ^value);
		}

		property String ^Profile
		{
			String ^get();
			void set(String ^value);
		}

		property IDynamicVectorClass<ITransitionDataClass ^> ^Transitions
		{
			IDynamicVectorClass<ITransitionDataClass ^> ^get();
			void set(IDynamicVectorClass<ITransitionDataClass ^> ^value);
		}

		property float TurnRadius
		{
			float get();
			void set(float value);
		}

		property bool OccupantsVisible
		{
			bool get();
			void set(bool value);
		}

		property bool SightDownMuzzle
		{
			bool get();
			void set(bool value);
		}

		property bool Aim2D
		{
			bool get();
			void set(bool value);
		}

		property float EngineSoundMaxPitchFactor
		{
			float get();
			void set(float value);
		}

		property array<int> ^EngineSound
		{
			array<int> ^get();
			void set(array<int> ^value);
		}

		property float SquishVelocity
		{
			float get();
			void set(float value);
		}

		property int VehicleNameID
		{
			int get();
			void set(int value);
		}

		property int NumSeats
		{
			int get();
			void set(int value);
		}

		property int GDIDamageReportID
		{
			int get();
			void set(int value);
		}

		property int NodDamageReportID
		{
			int get();
			void set(int value);
		}

		property int GDIDestroyReportID
		{
			int get();
			void set(int value);
		}

		property int NodDestroyReportID
		{
			int get();
			void set(int value);
		}

		property bool CanBeStolen
		{
			bool get();
			void set(bool value);
		}

		property bool AllowStealthWhileEmpty
		{
			bool get();
			void set(bool value);
		}

		property bool BuildAtGround
		{
			bool get();
			void set(bool value);
		}

		property bool DualAim
		{
			bool get();
			void set(bool value);
		}

		property float FactoryRideHeight
		{
			float get();
			void set(float value);
		}

		property bool FakeTurret
		{
			bool get();
			void set(bool value);
		}

		property int GDIPurchaseReportID
		{
			int get();
			void set(int value);
		}

		property int NodPurchaseReportID
		{
			int get();
			void set(int value);
		}

		property bool CanRepair
		{
			bool get();
			void set(bool value);
		}

		property int EntryHelpMessage
		{
			int get();
			void set(int value);
		}

		property Vector3 EntryHelpMessageColor
		{
			Vector3 get();
			void set(Vector3 value);
		}

		property bool ApplySurfaceEffectDamage
		{
			bool get();
			void set(bool value);
		}

		property bool DisableSurfaceSounds
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class VehicleGameObjDef : public SmartGameObjDef, public IVehicleGameObjDef
	{
		public:
			VehicleGameObjDef(IntPtr pointer);

			virtual int GetEngineSound(VehicleType type) sealed;

			property IntPtr VehicleGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

			property VehicleType Type
			{

#pragma push_macro("new")
#undef new

				virtual VehicleType get() new sealed;

#pragma pop_macro("new")

				virtual void set(VehicleType value) sealed;
			}

			property String ^TypeName
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property String ^Fire0Anim
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property String ^Fire1Anim
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property String ^Profile
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property IDynamicVectorClass<ITransitionDataClass ^> ^Transitions
			{
				virtual IDynamicVectorClass<ITransitionDataClass ^> ^get() sealed;
				virtual void set(IDynamicVectorClass<ITransitionDataClass ^> ^value) sealed;
			}

			property float TurnRadius
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool OccupantsVisible
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool SightDownMuzzle
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool Aim2D
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property float EngineSoundMaxPitchFactor
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property array<int> ^EngineSound
			{
				virtual array<int> ^get() sealed;
				virtual void set(array<int> ^value) sealed;
			}

			property float SquishVelocity
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int VehicleNameID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int NumSeats
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int GDIDamageReportID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int NodDamageReportID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int GDIDestroyReportID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int NodDestroyReportID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property bool CanBeStolen
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool AllowStealthWhileEmpty
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool BuildAtGround
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool DualAim
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property float FactoryRideHeight
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool FakeTurret
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property int GDIPurchaseReportID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int NodPurchaseReportID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property bool CanRepair
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property int EntryHelpMessage
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property Vector3 EntryHelpMessageColor
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

			property bool ApplySurfaceEffectDamage
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool DisableSurfaceSounds
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			property ::SmartGameObjDef *InternalSmartGameObjDefPointer
			{
				::SmartGameObjDef *get() override;
			}

			property ::VehicleGameObjDef *InternalVehicleGameObjDefPointer
			{
				virtual ::VehicleGameObjDef *get();
			}
	};
}