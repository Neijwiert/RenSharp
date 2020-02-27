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

#include "stdafx.h"
#include "MVehicleGameObj.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <VehicleGameObj.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MVehicleGameObjDef.h"
#include "MSoldierGameObj.h"
#include "MSound3DClass.h"
#include "MAudibleSoundClass.h"
#include "MReferencerClass.h"
#include "MUndergroundEffectClass.h"
#include "MTransitionInstanceClass.h"
#include "MTransitionInstanceClassPtrDynamicVectorClass.h"
#include "MPersistantSurfaceEmitterClassPtrVectorClass.h"
#include "MSoldierGameObjPtrVectorClass.h"

namespace RenSharp
{

#pragma managed(push, off)

	class VehicleGameObjHelper : public ::VehicleGameObj
	{
		private:
			VehicleGameObjHelper() = default;

		public:
			bool &GetTransitionsEnabled()
			{
				return TransitionsEnabled;
			}

			bool &GetDriverIsGunner()
			{
				return DriverIsGunner;
			}

			::Sound3DClass *&GetSound()
			{
				return Sound;
			}

			int &GetEngineSoundState()
			{
				return EngineSoundState;
			}

			::AudibleSoundClass *&GetCachedEngineSound()
			{
				return CachedEngineSound;
			}

			int &GetTurretBone()
			{
				return TurretBone;
			}

			int &GetBarrelBone()
			{
				return BarrelBone;
			}

			float &GetBarrelOffset()
			{
				return BarrelOffset;
			}

			bool &GetHasEnterTransitions()
			{
				return HasEnterTransitions;
			}

			bool &GetHasExitTransitions()
			{
				return HasExitTransitions;
			}

			bool &GetVehicleDelivered()
			{
				return VehicleDelivered;
			}

			bool &GetDamageMeshesUpdateFlag()
			{
				return DamageMeshesUpdate;
			}

			::VectorClass<::PersistantSurfaceEmitterClass *> &GetWheelSurfaceEmitters()
			{
				return WheelSurfaceEmitters;
			}

			::PersistantSurfaceSoundClass *&GetWheelSurfaceSound()
			{
				return WheelSurfaceSound;
			}

			::VectorClass<::SoldierGameObj *> &GetSeatOccupants()
			{
				return SeatOccupants;
			}

			int &GetOccupiedSeats()
			{
				return OccupiedSeats;
			}

			::DynamicVectorClass<::TransitionInstanceClass *> &GetTransitionInstances()
			{
				return TransitionInstances;
			}

			::ReferencerClass &GetLockOwnerRef()
			{
				return LockOwner;
			}

			float &GetLockTimer()
			{
				return LockTimer;
			}

			::UndergroundEffectClass *&GetUndergroundEffect()
			{
				return UndergroundEffect;
			}

			::ReferencerClass &GetOwnerRef()
			{
				return Owner;
			}

			bool &GetHasUpdatedTargeting()
			{
				return HasUpdatedTargeting;
			}

			bool &GetDamageMeshesNetworkUpdate()
			{
				return DamageMeshesNetworkUpdate;
			}
	};

#pragma managed(pop)

	VehicleGameObj::VehicleGameObj(IntPtr pointer)
		: SmartGameObj(pointer)
	{

	}

	IVehicleGameObj ^VehicleGameObj::AsVehicleGameObj()
	{
		return this;
	}

	void VehicleGameObj::AddOccupant(ISoldierGameObj ^occupant, int seatId)
	{
		if (occupant == nullptr || occupant->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("occupant");
		}
		else if (seatId < 0 || seatId >= InternalVehicleGameObjPointer->Get_Definition().NumSeats)
		{
			throw gcnew ArgumentOutOfRangeException("seatId");
		}

		InternalVehicleGameObjPointer->Add_Occupant(
			reinterpret_cast<::SoldierGameObj *>(occupant->SoldierGameObjPointer.ToPointer()),
			seatId);
	}

	void VehicleGameObj::AddOccupant(ISoldierGameObj ^occupant)
	{
		if (occupant == nullptr || occupant->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("occupant");
		}

		InternalVehicleGameObjPointer->Add_Occupant(
			reinterpret_cast<::SoldierGameObj *>(occupant->SoldierGameObjPointer.ToPointer()));
	}

	bool VehicleGameObj::IsEntryPermitted(ISoldierGameObj ^soldier)
	{
		if (soldier == nullptr || soldier->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}

		return InternalVehicleGameObjPointer->Is_Entry_Permitted(
			reinterpret_cast<::SoldierGameObj *>(soldier->SoldierGameObjPointer.ToPointer()));
	}

	void VehicleGameObj::LockVehicle(IScriptableGameObj ^lockOwner, float lockTime)
	{
		if (lockOwner == nullptr || lockOwner->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			InternalVehicleGameObjPointer->Lock_Vehicle(nullptr, lockTime);
		}
		else
		{
			InternalVehicleGameObjPointer->Lock_Vehicle(
				reinterpret_cast<::ScriptableGameObj *>(lockOwner->ScriptableGameObjPointer.ToPointer()),
				lockTime);
		}
	}

	void VehicleGameObj::ToggleDriverIsGunner()
	{
		InternalVehicleGameObjPointer->Toggle_Driver_Is_Gunner();
	}

	void VehicleGameObj::DamageMeshesUpdate()
	{
		InternalVehicleGameObjPointer->Damage_Meshes_Update();
	}

	void VehicleGameObj::SetOccupant(int seat, ISoldierGameObj ^occupant)
	{
		if (seat < 0 || seat >= InternalVehicleGameObjPointer->Get_Definition().NumSeats)
		{
			throw gcnew ArgumentOutOfRangeException("seat");
		}

		if (occupant == nullptr || occupant->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			InternalVehicleGameObjPointer->Set_Occupant(seat, nullptr);
		}
		else
		{
			InternalVehicleGameObjPointer->Set_Occupant(
				seat,
				reinterpret_cast<::SoldierGameObj *>(occupant->SoldierGameObjPointer.ToPointer()));
		}
	}

	ISoldierGameObj ^VehicleGameObj::GetOccupant(int seat)
	{
		if (seat < 0 || seat >= InternalVehicleGameObjPointer->Get_Definition().NumSeats)
		{
			throw gcnew ArgumentOutOfRangeException("seat");
		}

		auto result = InternalVehicleGameObjPointer->Get_Occupant(seat);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SoldierGameObj(IntPtr(result));
		}
	}

	void VehicleGameObj::SetColor(Drawing::Color color)
	{
		::Vector3 colorVec(color.R / 255.0f, color.G / 255.0f, color.B / 255.0f);

		InternalVehicleGameObjPointer->Set_Color(colorVec);
	}

	bool VehicleGameObj::ScriptsIsEnemy(IDamageableGameObj ^obj)
	{
		if (obj == nullptr || obj->DamageableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalVehicleGameObjPointer->Scripts_Is_Enemy(
			reinterpret_cast<::DamageableGameObj *>(obj->DamageableGameObjPointer.ToPointer()));
	}

	int	VehicleGameObj::CheckIfOnSurface(int surfaceType)
	{
		return InternalVehicleGameObjPointer->Check_If_On_Surface(surfaceType);
	}

	IntPtr VehicleGameObj::VehicleGameObjPointer::get()
	{
		return IntPtr(InternalVehicleGameObjPointer);
	}

	::SmartGameObj *VehicleGameObj::InternalSmartGameObjPointer::get()
	{
		return InternalVehicleGameObjPointer;
	}

	IVehicleGameObjDef ^VehicleGameObj::Definition::get()
	{
		return gcnew VehicleGameObjDef(IntPtr(const_cast<::VehicleGameObjDef *>(&InternalVehicleGameObjPointer->Get_Definition())));
	}

	bool VehicleGameObj::Use2DAiming::get()
	{
		return InternalVehicleGameObjPointer->Use_2D_Aiming();
	}

	bool VehicleGameObj::HasTurret::get()
	{
		return InternalVehicleGameObjPointer->Has_Turret();
	}

	bool VehicleGameObj::IsAircraft::get()
	{
		return InternalVehicleGameObjPointer->Is_Aircraft();
	}

	bool VehicleGameObj::IsTurret::get()
	{
		return InternalVehicleGameObjPointer->Is_Turret();
	}

	int VehicleGameObj::OccupantCount::get()
	{
		return InternalVehicleGameObjPointer->Get_Occupant_Count();
	}

	ISoldierGameObj ^VehicleGameObj::Driver::get()
	{
		auto result = InternalVehicleGameObjPointer->Get_Driver();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SoldierGameObj(IntPtr(result));
		}
	}

	ISoldierGameObj ^VehicleGameObj::Gunner::get()
	{
		auto result = InternalVehicleGameObjPointer->Get_Gunner();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SoldierGameObj(IntPtr(result));
		}
	}

	ISoldierGameObj ^VehicleGameObj::ActualGunner::get()
	{
		auto result = InternalVehicleGameObjPointer->Get_Actual_Gunner();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SoldierGameObj(IntPtr(result));
		}
	}

	String ^VehicleGameObj::Profile::get()
	{
		auto result = InternalVehicleGameObjPointer->Get_Profile();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	float VehicleGameObj::TurnRadius::get()
	{
		return InternalVehicleGameObjPointer->Get_Turn_Radius();
	}

	float VehicleGameObj::SquishVelocity::get()
	{
		return InternalVehicleGameObjPointer->Get_Squish_Velocity();
	}

	bool VehicleGameObj::IsLocked::get()
	{
		return InternalVehicleGameObjPointer->Is_Locked();
	}

	IScriptableGameObj ^VehicleGameObj::LockOwner::get()
	{
		auto result = InternalVehicleGameObjPointer->Get_Lock_Owner();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptableGameObj(IntPtr(result));
		}
	}

	bool VehicleGameObj::DriverIsGunner::get()
	{
		return InternalVehicleGameObjPointer->Get_Driver_Is_Gunner();
	}

	void VehicleGameObj::DriverIsGunner::set(bool value)
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &driverIsGunner = helper->GetDriverIsGunner();

		driverIsGunner = value;
	}

	bool VehicleGameObj::IsScriptsVisible::get()
	{
		return InternalVehicleGameObjPointer->Get_Is_Scripts_Visible();
	}

	void VehicleGameObj::IsScriptsVisible::set(bool value)
	{
		InternalVehicleGameObjPointer->Set_Is_Scripts_Visible(value);
	}

	char VehicleGameObj::ScriptsLastTeam::get()
	{
		return InternalVehicleGameObjPointer->Get_Last_Team();
	}

	void VehicleGameObj::ScriptsLastTeam::set(char value)
	{
		InternalVehicleGameObjPointer->Set_Scripts_Last_Team(value);
	}

	bool VehicleGameObj::ScriptsCanFire::get()
	{
		return InternalVehicleGameObjPointer->Get_Scripts_Can_Fire();
	}

	void VehicleGameObj::ScriptsCanFire::set(bool value)
	{
		InternalVehicleGameObjPointer->Set_Scripts_Can_Fire(value);
	}

	bool VehicleGameObj::AllowStealthWhileEmpty::get()
	{
		return InternalVehicleGameObjPointer->Get_Allow_Stealth_While_Empty();
	}

	void VehicleGameObj::AllowStealthWhileEmpty::set(bool value)
	{
		InternalVehicleGameObjPointer->Set_Allow_Stealth_While_Empty(value);
	}

	bool VehicleGameObj::IsUnderground::get()
	{
		return InternalVehicleGameObjPointer->Is_Underground();
	}

	bool VehicleGameObj::IsImmovable::get()
	{
		return InternalVehicleGameObjPointer->Is_Immovable();
	}

	void VehicleGameObj::IsImmovable::set(bool value)
	{
		InternalVehicleGameObjPointer->Set_Immovable(value);
	}

	int VehicleGameObj::LockTeam::get()
	{
		return InternalVehicleGameObjPointer->Get_Lock_Team();
	}

	void VehicleGameObj::LockTeam::set(int value)
	{
		InternalVehicleGameObjPointer->Set_Lock_Team(value);
	}

	bool VehicleGameObj::CanBeStolen::get()
	{
		return InternalVehicleGameObjPointer->Can_Be_Stolen();
	}

	void VehicleGameObj::CanBeStolen::set(bool value)
	{
		InternalVehicleGameObjPointer->Set_Can_Be_Stolen(value);
	}

	ISoldierGameObj ^VehicleGameObj::Owner::get()
	{
		auto result = InternalVehicleGameObjPointer->Get_Owner();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SoldierGameObj(IntPtr(result));
		}
	}

	void VehicleGameObj::Owner::set(ISoldierGameObj ^value)
	{
		if (value == nullptr || value->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			InternalVehicleGameObjPointer->Set_Owner(nullptr);
		}
		else
		{
			InternalVehicleGameObjPointer->Set_Owner(reinterpret_cast<::SoldierGameObj *>(value->SoldierGameObjPointer.ToPointer()));
		}
	}

	bool VehicleGameObj::CanDrive::get()
	{
		return InternalVehicleGameObjPointer->Can_Drive();
	}

	void VehicleGameObj::CanDrive::set(bool value)
	{
		InternalVehicleGameObjPointer->Set_Can_Drive(value);
	}

	bool VehicleGameObj::ScriptsIsTeamPlayer::get()
	{
		return InternalVehicleGameObjPointer->Scripts_Is_Team_Player();
	}

	bool VehicleGameObj::ScriptsTransitionsEnabled::get()
	{
		return InternalVehicleGameObjPointer->Are_Transitions_Enabled();
	}

	void VehicleGameObj::ScriptsTransitionsEnabled::set(bool value)
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &transitionsEnabled = helper->GetTransitionsEnabled();

		transitionsEnabled = value;
	}

	bool VehicleGameObj::FixedTurretFacing::get()
	{
		return InternalVehicleGameObjPointer->Get_Fixed_Turret_Facing();
	}

	void VehicleGameObj::FixedTurretFacing::set(bool value)
	{
		InternalVehicleGameObjPointer->Set_Fixed_Turret_Facing(value);
	}

	bool VehicleGameObj::LockedTurretFacing::get()
	{
		return InternalVehicleGameObjPointer->Get_Locked_Turret_Facing();
	}

	void VehicleGameObj::LockedTurretFacing::set(bool value)
	{
		InternalVehicleGameObjPointer->Set_Locked_Turret_Facing(value);
	}

	float VehicleGameObj::DesiredTurretTurn::get()
	{
		return InternalVehicleGameObjPointer->Get_Desired_Turret_Turn();
	}

	void VehicleGameObj::DesiredTurretTurn::set(float value)
	{
		InternalVehicleGameObjPointer->Set_Desired_Turret_Turn(value);
	}

	float VehicleGameObj::DesiredBarrelTilt::get()
	{
		return InternalVehicleGameObjPointer->Get_Desired_Barrel_Tilt();
	}

	void VehicleGameObj::DesiredBarrelTilt::set(float value)
	{
		InternalVehicleGameObjPointer->Set_Desired_Barrel_Tilt(value);
	}

	float VehicleGameObj::TurretTurn::get()
	{
		return InternalVehicleGameObjPointer->Get_Turret_Turn();
	}

	void VehicleGameObj::TurretTurn::set(float value)
	{
		InternalVehicleGameObjPointer->Set_Turret_Turn(value);
	}

	float VehicleGameObj::BarrelTilt::get()
	{
		return InternalVehicleGameObjPointer->Get_Barrel_Tilt();
	}

	void VehicleGameObj::BarrelTilt::set(float value)
	{
		InternalVehicleGameObjPointer->Set_Barrel_Tilt(value);
	}

	::VehicleGameObj *VehicleGameObj::InternalVehicleGameObjPointer::get()
	{
		return reinterpret_cast<::VehicleGameObj *>(Pointer.ToPointer());
	}

	ISound3DClass ^VehicleGameObj::Sound::get()
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &sound = helper->GetSound();

		if (sound == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew Sound3DClass(IntPtr(sound));
		}
	}

	void VehicleGameObj::Sound::set(ISound3DClass ^value)
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &sound = helper->GetSound();

		if (value == nullptr || value->Sound3DClassPointer.ToPointer() == nullptr)
		{
			sound = nullptr;
		}
		else
		{
			sound = reinterpret_cast<::Sound3DClass *>(value->Sound3DClassPointer.ToPointer());
		}
	}

	int VehicleGameObj::EngineSoundState::get()
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &engineSoundState = helper->GetEngineSoundState();

		return engineSoundState;
	}

	void VehicleGameObj::EngineSoundState::set(int value)
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &engineSoundState = helper->GetEngineSoundState();

		engineSoundState = value;
	}

	IAudibleSoundClass ^VehicleGameObj::CachedEngineSound::get()
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &cachedEngineSound = helper->GetCachedEngineSound();

		if (cachedEngineSound == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew AudibleSoundClass(IntPtr(cachedEngineSound));
		}
	}

	void VehicleGameObj::CachedEngineSound::set(IAudibleSoundClass ^value)
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &cachedEngineSound = helper->GetCachedEngineSound();

		if (value == nullptr || value->AudibleSoundClassPointer.ToPointer() == nullptr)
		{
			cachedEngineSound = nullptr;
		}
		else
		{
			cachedEngineSound = reinterpret_cast<::AudibleSoundClass *>(value->AudibleSoundClassPointer.ToPointer());
		}
	}

	int VehicleGameObj::TurretBone::get()
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &turretBone = helper->GetTurretBone();

		return turretBone;
	}

	void VehicleGameObj::TurretBone::set(int value)
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &turretBone = helper->GetTurretBone();

		turretBone = value;
	}

	int VehicleGameObj::BarrelBone::get()
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &barrelBone = helper->GetBarrelBone();

		return barrelBone;
	}

	void VehicleGameObj::BarrelBone::set(int value)
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &barrelBone = helper->GetBarrelBone();

		barrelBone = value;
	}

	float VehicleGameObj::BarrelOffset::get()
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &barrelOffset = helper->GetBarrelOffset();

		return barrelOffset;
	}

	void VehicleGameObj::BarrelOffset::set(float value)
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &barrelOffset = helper->GetBarrelOffset();

		barrelOffset = value;
	}

	bool VehicleGameObj::HasEnterTransitions::get()
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &hasEnterTransitions = helper->GetHasEnterTransitions();

		return hasEnterTransitions;
	}

	void VehicleGameObj::HasEnterTransitions::set(bool value)
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &hasEnterTransitions = helper->GetHasEnterTransitions();

		hasEnterTransitions = value;
	}

	bool VehicleGameObj::HasExitTransitions::get()
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &hasExitTransitions = helper->GetHasExitTransitions();

		return hasExitTransitions;
	}

	void VehicleGameObj::HasExitTransitions::set(bool value)
	{

		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &hasExitTransitions = helper->GetHasExitTransitions();

		hasExitTransitions = value;
	}

	bool VehicleGameObj::VehicleDelivered::get()
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &vehicleDelivered = helper->GetVehicleDelivered();

		return vehicleDelivered;
	}

	void VehicleGameObj::VehicleDelivered::set(bool value)
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &vehicleDelivered = helper->GetVehicleDelivered();

		vehicleDelivered = value;
	}

	bool VehicleGameObj::DamageMeshesUpdateFlag::get()
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &damageMeshesUpdateFlag = helper->GetDamageMeshesUpdateFlag();

		return damageMeshesUpdateFlag;
	}

	void VehicleGameObj::DamageMeshesUpdateFlag::set(bool value)
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &damageMeshesUpdateFlag = helper->GetDamageMeshesUpdateFlag();

		damageMeshesUpdateFlag = value;
	}

	IVectorClass<IntPtr> ^VehicleGameObj::WheelSurfaceEmitters::get()
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &wheelSurfaceEmitters = helper->GetWheelSurfaceEmitters();

		return gcnew PersistantSurfaceEmitterClassPtrVectorClass(IntPtr(&wheelSurfaceEmitters));
	}

	void VehicleGameObj::WheelSurfaceEmitters::set(IVectorClass<IntPtr> ^value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &wheelSurfaceEmitters = helper->GetWheelSurfaceEmitters();

		wheelSurfaceEmitters = *reinterpret_cast<::VectorClass<::PersistantSurfaceEmitterClass *> *>(value->Pointer.ToPointer());
	}

	IntPtr VehicleGameObj::WheelSurfaceSound::get()
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &wheelSurfaceSound = helper->GetWheelSurfaceSound();

		return IntPtr(wheelSurfaceSound);
	}

	void VehicleGameObj::WheelSurfaceSound::set(IntPtr value)
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &wheelSurfaceSound = helper->GetWheelSurfaceSound();

		if (value.ToPointer() == nullptr)
		{
			wheelSurfaceSound = nullptr;
		}
		else
		{
			wheelSurfaceSound = reinterpret_cast<::PersistantSurfaceSoundClass *>(value.ToPointer());
		}
	}

	IVectorClass<ISoldierGameObj ^> ^VehicleGameObj::SeatOccupants::get()
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &seatOccupants = helper->GetSeatOccupants();

		return gcnew SoldierGameObjPtrVectorClass(IntPtr(&seatOccupants));
	}

	void VehicleGameObj::SeatOccupants::set(IVectorClass<ISoldierGameObj ^> ^value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &seatOccupants = helper->GetSeatOccupants();

		seatOccupants = *reinterpret_cast<::VectorClass<::SoldierGameObj *> *>(value->Pointer.ToPointer());
	}

	int VehicleGameObj::OccupiedSeats::get()
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &occupiedSeats = helper->GetOccupiedSeats();

		return occupiedSeats;
	}

	void VehicleGameObj::OccupiedSeats::set(int value)
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &occupiedSeats = helper->GetOccupiedSeats();

		occupiedSeats = value;
	}

	IDynamicVectorClass<ITransitionInstanceClass ^> ^VehicleGameObj::TransitionInstances::get()
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &transitionInstances = helper->GetTransitionInstances();

		return gcnew TransitionInstanceClassPtrDynamicVectorClass(IntPtr(&transitionInstances));
	}

	void VehicleGameObj::TransitionInstances::set(IDynamicVectorClass<ITransitionInstanceClass ^> ^value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &transitionInstances = helper->GetTransitionInstances();

		transitionInstances = *reinterpret_cast<::DynamicVectorClass<::TransitionInstanceClass *> *>(value->Pointer.ToPointer());
	}

	IReferencerClass ^VehicleGameObj::LockOwnerRef::get()
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &lockOwner = helper->GetLockOwnerRef();

		return gcnew ReferencerClass(IntPtr(&lockOwner));
	}

	void VehicleGameObj::LockOwnerRef::set(IReferencerClass ^value)
	{
		if (value == nullptr || value->ReferencerClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &lockOwner = helper->GetLockOwnerRef();

		lockOwner = *reinterpret_cast<::ReferencerClass *>(value->ReferencerClassPointer.ToPointer());
	}

	float VehicleGameObj::LockTimer::get()
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &lockTimer = helper->GetLockTimer();

		return lockTimer;
	}

	void VehicleGameObj::LockTimer::set(float value)
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &lockTimer = helper->GetLockTimer();

		lockTimer = value;
	}

	IUndergroundEffectClass ^VehicleGameObj::UndergroundEffect::get()
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &undergroundEffect = helper->GetUndergroundEffect();

		if (undergroundEffect == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew UndergroundEffectClass(IntPtr(undergroundEffect));
		}
	}

	void VehicleGameObj::UndergroundEffect::set(IUndergroundEffectClass ^value)
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &undergroundEffect = helper->GetUndergroundEffect();

		if (value == nullptr || value->UndergroundEffectClassPointer.ToPointer() == nullptr)
		{
			undergroundEffect = nullptr;
		}
		else
		{
			undergroundEffect = reinterpret_cast<::UndergroundEffectClass *>(value->UndergroundEffectClassPointer.ToPointer());
		}
	}

	IReferencerClass ^VehicleGameObj::OwnerRef::get()
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &owner = helper->GetOwnerRef();

		return gcnew ReferencerClass(IntPtr(&owner));
	}

	void VehicleGameObj::OwnerRef::set(IReferencerClass ^value)
	{
		if (value == nullptr || value->ReferencerClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &owner = helper->GetOwnerRef();

		owner = *reinterpret_cast<::ReferencerClass *>(value->ReferencerClassPointer.ToPointer());
	}

	bool VehicleGameObj::HasUpdatedTargeting::get()
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &hasUpdatedTargeting = helper->GetHasUpdatedTargeting();

		return hasUpdatedTargeting;
	}

	void VehicleGameObj::HasUpdatedTargeting::set(bool value)
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &hasUpdatedTargeting = helper->GetHasUpdatedTargeting();

		hasUpdatedTargeting = value;
	}

	bool VehicleGameObj::DamageMeshesNetworkUpdate::get()
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &damageMeshesNetworkUpdate = helper->GetDamageMeshesNetworkUpdate();

		return damageMeshesNetworkUpdate;
	}

	void VehicleGameObj::DamageMeshesNetworkUpdate::set(bool value)
	{
		auto helper = reinterpret_cast<VehicleGameObjHelper *>(InternalVehicleGameObjPointer);

		auto &damageMeshesNetworkUpdate = helper->GetDamageMeshesNetworkUpdate();

		damageMeshesNetworkUpdate = value;
	}
}