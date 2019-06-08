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

#include "MSmartGameObj.h"
#include "Mengine_vector.h"

#pragma managed(push, off)

class VehicleGameObj;

#pragma managed(pop)

using namespace System::Drawing;

namespace RenSharp
{
	interface class IVehicleGameObjDef;
	interface class ISoldierGameObj;
	interface class ISound3DClass;
	interface class IAudibleSoundClass;
	interface class IReferencerClass;
	interface class IUndergroundEffectClass;
	interface class ITransitionInstanceClass;

	public interface class IVehicleGameObj : public ISmartGameObj
	{
		void AddOccupant(ISoldierGameObj ^occupant, int seatId);

		void AddOccupant(ISoldierGameObj ^occupant);

		bool IsEntryPermitted(ISoldierGameObj ^soldier);

		void LockVehicle(IScriptableGameObj ^lockOwner, float lockTime);

		void ToggleDriverIsGunner();

		void DamageMeshesUpdate();

		void SetOccupant(int seat, ISoldierGameObj ^occupant);

		ISoldierGameObj ^GetOccupant(int seat);

		void SetColor(Drawing::Color color);

		bool ScriptsIsEnemy(IDamageableGameObj ^obj);

		property IntPtr VehicleGameObjPointer
		{
			IntPtr get();
		}

		property IVehicleGameObjDef ^Definition
		{
			IVehicleGameObjDef ^get();
		}

		property bool Use2DAiming
		{
			bool get();
		}

		property bool HasTurret
		{
			bool get();
		}

		property bool IsAircraft
		{
			bool get();
		}

		property bool IsTurret
		{
			bool get();
		}

		property int OccupantCount
		{
			int get();
		}

		property ISoldierGameObj ^Driver
		{
			ISoldierGameObj ^get();
		}

		property ISoldierGameObj ^Gunner
		{
			ISoldierGameObj ^get();
		}

		property ISoldierGameObj ^ActualGunner
		{
			ISoldierGameObj ^get();
		}

		property String ^Profile
		{
			String ^get();
		}

		property float TurnRadius
		{
			float get();
		}

		property float SquishVelocity
		{
			float get();
		}

		property bool IsLocked
		{
			bool get();
		}

		property IScriptableGameObj ^LockOwner
		{
			IScriptableGameObj ^get();
		}

		property bool DriverIsGunner
		{
			bool get();
		}

		property bool IsScriptsVisible
		{
			bool get();
			void set(bool value);
		}

		property char ScriptsLastTeam
		{
			char get();
			void set(char value);
		}

		property bool ScriptsCanFire
		{
			bool get();
			void set(bool value);
		}

		property bool AllowStealthWhileEmpty
		{
			bool get();
			void set(bool value);
		}

		property bool IsUnderground
		{
			bool get();
		}

		property bool IsImmovable
		{
			bool get();
			void set(bool value);
		}

		property int LockTeam
		{
			int get();
			void set(int value);
		}

		property bool CanBeStolen
		{
			bool get();
			void set(bool value);
		}

		property ISoldierGameObj ^Owner
		{
			ISoldierGameObj ^get();
			void set(ISoldierGameObj ^value);
		}

		property bool CanDrive
		{
			bool get();
			void set(bool value);
		}

		property bool ScriptsIsTeamPlayer
		{
			bool get();
		}

		property bool ScriptsTransitionsEnabled
		{
			bool get();
		}

		property bool FixedTurretFacing
		{
			bool get();
			void set(bool value);
		}

		property bool LockedTurretFacing
		{
			bool get();
			void set(bool value);
		}

		property float DesiredTurretTurn
		{
			float get();
			void set(float value);
		}

		property float DesiredBarrelTilt
		{
			float get();
			void set(float value);
		}

		property float TurretTurn
		{
			float get();
			void set(float value);
		}

		property float BarrelTilt
		{
			float get();
			void set(float value);
		}
	};

	public ref class VehicleGameObj : public SmartGameObj, public IVehicleGameObj
	{
		protected:
			enum class SeatType
			{
				DriverSeat = 0,
				GunnerSeat
			};

		public:
			VehicleGameObj(IntPtr pointer);

			IVehicleGameObj ^AsVehicleGameObj() override;

			virtual void AddOccupant(ISoldierGameObj ^occupant, int seatId) sealed;
			virtual void AddOccupant(ISoldierGameObj ^occupant) sealed;
			virtual bool IsEntryPermitted(ISoldierGameObj ^soldier) sealed;
			virtual void LockVehicle(IScriptableGameObj ^lockOwner, float lockTime) sealed;
			virtual void ToggleDriverIsGunner() sealed;
			virtual void DamageMeshesUpdate() sealed;
			virtual void SetOccupant(int seat, ISoldierGameObj ^occupant) sealed;
			virtual ISoldierGameObj ^GetOccupant(int seat) sealed;
			virtual void SetColor(Drawing::Color color) sealed;
			virtual bool ScriptsIsEnemy(IDamageableGameObj ^obj) sealed;

			property IntPtr VehicleGameObjPointer
			{
				virtual IntPtr get() sealed;
			}

			property IVehicleGameObjDef ^Definition
			{

#pragma push_macro("new")
#undef new

				virtual IVehicleGameObjDef ^get() new sealed;

#pragma pop_macro("new")

			}

			property bool Use2DAiming
			{
				virtual bool get() sealed;
			}

			property bool HasTurret
			{
				virtual bool get() sealed;
			}

			property bool IsAircraft
			{
				virtual bool get() sealed;
			}

			property bool IsTurret
			{
				virtual bool get() sealed;
			}

			property int OccupantCount
			{
				virtual int get() sealed;
			}

			property ISoldierGameObj ^Driver
			{
				virtual ISoldierGameObj ^get() sealed;
			}

			property ISoldierGameObj ^Gunner
			{
				virtual ISoldierGameObj ^get() sealed;
			}

			property ISoldierGameObj ^ActualGunner
			{
				virtual ISoldierGameObj ^get() sealed;
			}

			property String ^Profile
			{
				virtual String ^get() sealed;
			}

			property float TurnRadius
			{
				virtual float get() sealed;
			}

			property float SquishVelocity
			{
				virtual float get() sealed;
			}

			property bool IsLocked
			{
				virtual bool get() sealed;
			}

			property IScriptableGameObj ^LockOwner
			{
				virtual IScriptableGameObj ^get() sealed;
			}

			property bool DriverIsGunner
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

			property bool IsScriptsVisible
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property char ScriptsLastTeam
			{
				virtual char get() sealed;
				virtual void set(char value) sealed;
			}

			property bool ScriptsCanFire
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool AllowStealthWhileEmpty
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsUnderground
			{
				virtual bool get() sealed;
			}

			property bool IsImmovable
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property int LockTeam
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property bool CanBeStolen
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property ISoldierGameObj ^Owner
			{
				virtual ISoldierGameObj ^get() sealed;
				virtual void set(ISoldierGameObj ^value) sealed;
			}

			property bool CanDrive
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool ScriptsIsTeamPlayer
			{
				virtual bool get() sealed;
			}

			property bool ScriptsTransitionsEnabled
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

			property bool FixedTurretFacing
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool LockedTurretFacing
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property float DesiredTurretTurn
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float DesiredBarrelTilt
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float TurretTurn
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float BarrelTilt
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

		protected:
			property ::SmartGameObj *InternalSmartGameObjPointer
			{
				::SmartGameObj *get() override;
			}

			property ::VehicleGameObj *InternalVehicleGameObjPointer
			{
				virtual ::VehicleGameObj *get();
			}

			property ISound3DClass ^Sound
			{
				ISound3DClass ^get();
				void set(ISound3DClass ^value);
			}

			property int EngineSoundState
			{
				int get();
				void set(int value);
			}

			property IAudibleSoundClass ^CachedEngineSound
			{
				IAudibleSoundClass ^get();
				void set(IAudibleSoundClass ^value);
			}

			property int TurretBone
			{
				int get();
				void set(int value);
			}

			property int BarrelBone
			{
				int get();
				void set(int value);
			}

			property float BarrelOffset
			{
				float get();
				void set(float value);
			}

			property bool HasEnterTransitions
			{
				bool get();
				void set(bool value);
			}

			property bool HasExitTransitions
			{
				bool get();
				void set(bool value);
			}

			property bool VehicleDelivered
			{
				bool get();
				void set(bool value);
			}

			property bool DamageMeshesUpdateFlag
			{
				bool get();
				void set(bool value);
			}

			property IVectorClass<IntPtr> ^WheelSurfaceEmitters
			{
				IVectorClass<IntPtr> ^get();
				void set(IVectorClass<IntPtr> ^value);
			}

			property IntPtr WheelSurfaceSound
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property IVectorClass<ISoldierGameObj ^> ^SeatOccupants
			{
				IVectorClass<ISoldierGameObj ^> ^get();
				void set(IVectorClass<ISoldierGameObj ^> ^value);
			}

			property int OccupiedSeats
			{
				int get();
				void set(int value);
			}

			property IDynamicVectorClass<ITransitionInstanceClass ^> ^TransitionInstances
			{
				IDynamicVectorClass<ITransitionInstanceClass ^> ^get();
				void set(IDynamicVectorClass<ITransitionInstanceClass ^> ^value);
			}

			property IReferencerClass ^LockOwnerRef
			{
				IReferencerClass ^get();
				void set(IReferencerClass ^value);
			}

			property float LockTimer
			{
				float get();
				void set(float value);
			}

			property IUndergroundEffectClass ^UndergroundEffect
			{
				IUndergroundEffectClass ^get();
				void set(IUndergroundEffectClass ^value);
			}

			property IReferencerClass ^OwnerRef
			{
				IReferencerClass ^get();
				void set(IReferencerClass ^value);
			}

			property bool HasUpdatedTargeting
			{
				bool get();
				void set(bool value);
			}

			property bool DamageMeshesNetworkUpdate
			{
				bool get();
				void set(bool value);
			}
	};
}