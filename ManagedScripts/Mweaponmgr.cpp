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
#include "Mweaponmgr.h"

#include "Mvector2.h"
#include "MVector3.h"
#include "Mrect.h"

namespace RenSharp
{
	AmmoDefinitionClass::AmmoDefinitionClass(IntPtr pointer)
		: DefinitionClass(pointer)
	{

	}

	IntPtr AmmoDefinitionClass::AmmoDefinitionClassPointer::get()
	{
		return IntPtr(InternalAmmoDefinitionClassPointer);
	}

	String ^AmmoDefinitionClass::ModelFilename::get()
	{
		return gcnew String(InternalAmmoDefinitionClassPointer->ModelFilename.Peek_Buffer());
	}

	void AmmoDefinitionClass::ModelFilename::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalAmmoDefinitionClassPointer->ModelFilename = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	String ^AmmoDefinitionClass::ModelName::get()
	{
		return gcnew String(InternalAmmoDefinitionClassPointer->ModelName.Peek_Buffer());
	}

	void AmmoDefinitionClass::ModelName::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalAmmoDefinitionClassPointer->ModelName = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	int AmmoDefinitionClass::Warhead::get()
	{
		return InternalAmmoDefinitionClassPointer->Warhead;
	}

	void AmmoDefinitionClass::Warhead::set(int value)
	{
		InternalAmmoDefinitionClassPointer->Warhead = value;
	}

	float AmmoDefinitionClass::Damage::get()
	{
		return InternalAmmoDefinitionClassPointer->Damage;
	}

	void AmmoDefinitionClass::Damage::set(float value)
	{
		InternalAmmoDefinitionClassPointer->Damage = value;
	}

	float AmmoDefinitionClass::Range::get()
	{
		return InternalAmmoDefinitionClassPointer->Range;
	}

	void AmmoDefinitionClass::Range::set(float value)
	{
		InternalAmmoDefinitionClassPointer->Range = value;
	}

	float AmmoDefinitionClass::Velocity::get()
	{
		return InternalAmmoDefinitionClassPointer->Velocity;
	}

	void AmmoDefinitionClass::Velocity::set(float value)
	{
		InternalAmmoDefinitionClassPointer->Velocity = value;
	}

	float AmmoDefinitionClass::Gravity::get()
	{
		return InternalAmmoDefinitionClassPointer->Gravity;
	}

	void AmmoDefinitionClass::Gravity::set(float value)
	{
		InternalAmmoDefinitionClassPointer->Gravity = value;
	}

	float AmmoDefinitionClass::Elasticity::get()
	{
		return InternalAmmoDefinitionClassPointer->Elasticity;
	}

	void AmmoDefinitionClass::Elasticity::set(float value)
	{
		InternalAmmoDefinitionClassPointer->Elasticity = value;
	}

	float AmmoDefinitionClass::RateOfFire::get()
	{
		return InternalAmmoDefinitionClassPointer->RateOfFire;
	}

	void AmmoDefinitionClass::RateOfFire::set(float value)
	{
		InternalAmmoDefinitionClassPointer->RateOfFire = value;
	}

	float AmmoDefinitionClass::SprayAngle::get()
	{
		return InternalAmmoDefinitionClassPointer->SprayAngle;
	}

	void AmmoDefinitionClass::SprayAngle::set(float value)
	{
		InternalAmmoDefinitionClassPointer->SprayAngle = value;
	}

	int AmmoDefinitionClass::SprayCount::get()
	{
		return InternalAmmoDefinitionClassPointer->SprayCount;
	}

	void AmmoDefinitionClass::SprayCount::set(int value)
	{
		InternalAmmoDefinitionClassPointer->SprayCount = value;
	}

	String ^AmmoDefinitionClass::TrailEmitter::get()
	{
		return gcnew String(InternalAmmoDefinitionClassPointer->TrailEmitter.Peek_Buffer());
	}

	void AmmoDefinitionClass::TrailEmitter::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalAmmoDefinitionClassPointer->TrailEmitter = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	float AmmoDefinitionClass::AquireTime::get()
	{
		return InternalAmmoDefinitionClassPointer->AquireTime;
	}

	void AmmoDefinitionClass::AquireTime::set(float value)
	{
		InternalAmmoDefinitionClassPointer->AquireTime = value;
	}

	float AmmoDefinitionClass::BurstDelayTime::get()
	{
		return InternalAmmoDefinitionClassPointer->BurstDelayTime;
	}

	void AmmoDefinitionClass::BurstDelayTime::set(float value)
	{
		InternalAmmoDefinitionClassPointer->BurstDelayTime = value;
	}

	int AmmoDefinitionClass::BurstMax::get()
	{
		return InternalAmmoDefinitionClassPointer->BurstMax;
	}

	void AmmoDefinitionClass::BurstMax::set(int value)
	{
		InternalAmmoDefinitionClassPointer->BurstMax = value;
	}

	int AmmoDefinitionClass::SoftPierceLimit::get()
	{
		return InternalAmmoDefinitionClassPointer->SoftPierceLimit;
	}

	void AmmoDefinitionClass::SoftPierceLimit::set(int value)
	{
		InternalAmmoDefinitionClassPointer->SoftPierceLimit = value;
	}

	float AmmoDefinitionClass::TurnRate::get()
	{
		return InternalAmmoDefinitionClassPointer->TurnRate;
	}

	void AmmoDefinitionClass::TurnRate::set(float value)
	{
		InternalAmmoDefinitionClassPointer->TurnRate = value;
	}


	bool AmmoDefinitionClass::TimeActivated::get()
	{
		return InternalAmmoDefinitionClassPointer->TimeActivated;
	}

	void AmmoDefinitionClass::TimeActivated::set(bool value)
	{
		InternalAmmoDefinitionClassPointer->TimeActivated = value;
	}

	bool AmmoDefinitionClass::TerrainActivated::get()
	{
		return InternalAmmoDefinitionClassPointer->TerrainActivated;
	}

	void AmmoDefinitionClass::TerrainActivated::set(bool value)
	{
		InternalAmmoDefinitionClassPointer->TerrainActivated = value;
	}

	bool AmmoDefinitionClass::IsTracking::get()
	{
		return InternalAmmoDefinitionClassPointer->IsTracking;
	}

	void AmmoDefinitionClass::IsTracking::set(bool value)
	{
		InternalAmmoDefinitionClassPointer->IsTracking = value;
	}

	float AmmoDefinitionClass::EffectiveRange::get()
	{
		return InternalAmmoDefinitionClassPointer->EffectiveRange;
	}

	void AmmoDefinitionClass::EffectiveRange::set(float value)
	{
		InternalAmmoDefinitionClassPointer->EffectiveRange = value;
	}

	int AmmoDefinitionClass::ExplosionDefID::get()
	{
		return InternalAmmoDefinitionClassPointer->ExplosionDefID;
	}

	void AmmoDefinitionClass::ExplosionDefID::set(int value)
	{
		InternalAmmoDefinitionClassPointer->ExplosionDefID = value;
	}

	float AmmoDefinitionClass::RandomTrackingScale::get()
	{
		return InternalAmmoDefinitionClassPointer->RandomTrackingScale;
	}

	void AmmoDefinitionClass::RandomTrackingScale::set(float value)
	{
		InternalAmmoDefinitionClassPointer->RandomTrackingScale = value;
	}

	bool AmmoDefinitionClass::DisplayLaser::get()
	{
		return InternalAmmoDefinitionClassPointer->DisplayLaser;
	}

	void AmmoDefinitionClass::DisplayLaser::set(bool value)
	{
		InternalAmmoDefinitionClassPointer->DisplayLaser = value;
	}

	float AmmoDefinitionClass::ChargeTime::get()
	{
		return InternalAmmoDefinitionClassPointer->ChargeTime;
	}

	void AmmoDefinitionClass::ChargeTime::set(float value)
	{
		InternalAmmoDefinitionClassPointer->ChargeTime = value;
	}

	int AmmoDefinitionClass::ContinuousSoundDefID::get()
	{
		return InternalAmmoDefinitionClassPointer->ContinuousSoundDefID;
	}

	void AmmoDefinitionClass::ContinuousSoundDefID::set(int value)
	{
		InternalAmmoDefinitionClassPointer->ContinuousSoundDefID = value;
	}

	int AmmoDefinitionClass::FireSoundDefID::get()
	{
		return InternalAmmoDefinitionClassPointer->FireSoundDefID;
	}

	void AmmoDefinitionClass::FireSoundDefID::set(int value)
	{
		InternalAmmoDefinitionClassPointer->FireSoundDefID = value;
	}

	String ^AmmoDefinitionClass::ContinuousEmitterName::get()
	{
		return gcnew String(InternalAmmoDefinitionClassPointer->ContinuousEmitterName.Peek_Buffer());
	}

	void AmmoDefinitionClass::ContinuousEmitterName::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalAmmoDefinitionClassPointer->ContinuousEmitterName = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	int AmmoDefinitionClass::MaxBounces::get()
	{
		return InternalAmmoDefinitionClassPointer->MaxBounces;
	}

	void AmmoDefinitionClass::MaxBounces::set(int value)
	{
		InternalAmmoDefinitionClassPointer->MaxBounces = value;
	}

	int AmmoDefinitionClass::SprayBulletCost::get()
	{
		return InternalAmmoDefinitionClassPointer->SprayBulletCost;
	}

	void AmmoDefinitionClass::SprayBulletCost::set(int value)
	{
		InternalAmmoDefinitionClassPointer->SprayBulletCost = value;
	}

	int AmmoDefinitionClass::AmmoType::get()
	{
		return InternalAmmoDefinitionClassPointer->AmmoType;
	}

	void AmmoDefinitionClass::AmmoType::set(int value)
	{
		InternalAmmoDefinitionClassPointer->AmmoType = value;
	}

	float AmmoDefinitionClass::C4TriggerTime1::get()
	{
		return InternalAmmoDefinitionClassPointer->C4TriggerTime1;
	}

	void AmmoDefinitionClass::C4TriggerTime1::set(float value)
	{
		InternalAmmoDefinitionClassPointer->C4TriggerTime1 = value;
	}

	float AmmoDefinitionClass::C4TriggerTime2::get()
	{
		return InternalAmmoDefinitionClassPointer->C4TriggerTime2;
	}

	void AmmoDefinitionClass::C4TriggerTime2::set(float value)
	{
		InternalAmmoDefinitionClassPointer->C4TriggerTime2 = value;
	}

	float AmmoDefinitionClass::C4TriggerTime3::get()
	{
		return InternalAmmoDefinitionClassPointer->C4TriggerTime3;
	}

	void AmmoDefinitionClass::C4TriggerTime3::set(float value)
	{
		InternalAmmoDefinitionClassPointer->C4TriggerTime3 = value;
	}

	float AmmoDefinitionClass::C4TriggerRange1::get()
	{
		return InternalAmmoDefinitionClassPointer->C4TriggerRange1;
	}

	void AmmoDefinitionClass::C4TriggerRange1::set(float value)
	{
		InternalAmmoDefinitionClassPointer->C4TriggerRange1 = value;
	}

	float AmmoDefinitionClass::C4TriggerRange2::get()
	{
		return InternalAmmoDefinitionClassPointer->C4TriggerRange2;
	}

	void AmmoDefinitionClass::C4TriggerRange2::set(float value)
	{
		InternalAmmoDefinitionClassPointer->C4TriggerRange2 = value;
	}

	float AmmoDefinitionClass::C4TriggerRange3::get()
	{
		return InternalAmmoDefinitionClassPointer->C4TriggerRange3;
	}

	void AmmoDefinitionClass::C4TriggerRange3::set(float value)
	{
		InternalAmmoDefinitionClassPointer->C4TriggerRange3 = value;
	}

	int AmmoDefinitionClass::C4TimingSound1ID::get()
	{
		return InternalAmmoDefinitionClassPointer->C4TimingSound1ID;
	}

	void AmmoDefinitionClass::C4TimingSound1ID::set(int value)
	{
		InternalAmmoDefinitionClassPointer->C4TimingSound1ID = value;
	}

	int AmmoDefinitionClass::C4TimingSound2ID::get()
	{
		return InternalAmmoDefinitionClassPointer->C4TimingSound2ID;
	}

	void AmmoDefinitionClass::C4TimingSound2ID::set(int value)
	{
		InternalAmmoDefinitionClassPointer->C4TimingSound2ID = value;
	}

	int AmmoDefinitionClass::C4TimingSound3ID::get()
	{
		return InternalAmmoDefinitionClassPointer->C4TimingSound3ID;
	}

	void AmmoDefinitionClass::C4TimingSound3ID::set(int value)
	{
		InternalAmmoDefinitionClassPointer->C4TimingSound3ID = value;
	}

	float AmmoDefinitionClass::AliasedSpeed::get()
	{
		return InternalAmmoDefinitionClassPointer->AliasedSpeed;
	}

	void AmmoDefinitionClass::AliasedSpeed::set(float value)
	{
		InternalAmmoDefinitionClassPointer->AliasedSpeed = value;
	}

	int AmmoDefinitionClass::HitterType::get()
	{
		return InternalAmmoDefinitionClassPointer->HitterType;
	}

	void AmmoDefinitionClass::HitterType::set(int value)
	{
		InternalAmmoDefinitionClassPointer->HitterType = value;
	}

	int AmmoDefinitionClass::BeaconDefID::get()
	{
		return InternalAmmoDefinitionClassPointer->BeaconDefID;
	}

	void AmmoDefinitionClass::BeaconDefID::set(int value)
	{
		InternalAmmoDefinitionClassPointer->BeaconDefID = value;
	}

	bool AmmoDefinitionClass::BeamEnabled::get()
	{
		return InternalAmmoDefinitionClassPointer->BeamEnabled;
	}

	void AmmoDefinitionClass::BeamEnabled::set(bool value)
	{
		InternalAmmoDefinitionClassPointer->BeamEnabled = value;
	}

	Vector3 AmmoDefinitionClass::BeamColor::get()
	{
		Vector3 result;
		Vector3::UnmanagedToManagedVector3(InternalAmmoDefinitionClassPointer->BeamColor, result);

		return result;
	}

	void AmmoDefinitionClass::BeamColor::set(Vector3 value)
	{
		Vector3::ManagedToUnmanagedVector3(value, InternalAmmoDefinitionClassPointer->BeamColor);
	}

	float AmmoDefinitionClass::BeamTime::get()
	{
		return InternalAmmoDefinitionClassPointer->BeamTime;
	}

	void AmmoDefinitionClass::BeamTime::set(float value)
	{
		InternalAmmoDefinitionClassPointer->BeamTime = value;
	}

	float AmmoDefinitionClass::BeamWidth::get()
	{
		return InternalAmmoDefinitionClassPointer->BeamWidth;
	}

	void AmmoDefinitionClass::BeamWidth::set(float value)
	{
		InternalAmmoDefinitionClassPointer->BeamWidth = value;
	}

	bool AmmoDefinitionClass::BeamEndCaps::get()
	{
		return InternalAmmoDefinitionClassPointer->BeamEndCaps;
	}

	void AmmoDefinitionClass::BeamEndCaps::set(bool value)
	{
		InternalAmmoDefinitionClassPointer->BeamEndCaps = value;
	}

	String ^AmmoDefinitionClass::BeamTexture::get()
	{
		return gcnew String(InternalAmmoDefinitionClassPointer->BeamTexture.Peek_Buffer());
	}

	void AmmoDefinitionClass::BeamTexture::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalAmmoDefinitionClassPointer->BeamTexture = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	bool AmmoDefinitionClass::BeamSubdivisionEnabled::get()
	{
		return InternalAmmoDefinitionClassPointer->BeamSubdivisionEnabled;
	}

	void AmmoDefinitionClass::BeamSubdivisionEnabled::set(bool value)
	{
		InternalAmmoDefinitionClassPointer->BeamSubdivisionEnabled = value;
	}

	float AmmoDefinitionClass::BeamSubdivisionScale::get()
	{
		return InternalAmmoDefinitionClassPointer->BeamSubdivisionScale;
	}

	void AmmoDefinitionClass::BeamSubdivisionScale::set(float value)
	{
		InternalAmmoDefinitionClassPointer->BeamSubdivisionScale = value;
	}

	bool AmmoDefinitionClass::BeamSubdivisionFrozen::get()
	{
		return InternalAmmoDefinitionClassPointer->BeamSubdivisionFrozen;
	}

	void AmmoDefinitionClass::BeamSubdivisionFrozen::set(bool value)
	{
		InternalAmmoDefinitionClassPointer->BeamSubdivisionFrozen = value;
	}

	int AmmoDefinitionClass::IconNameID::get()
	{
		return InternalAmmoDefinitionClassPointer->IconNameID;
	}

	void AmmoDefinitionClass::IconNameID::set(int value)
	{
		InternalAmmoDefinitionClassPointer->IconNameID = value;
	}

	String ^AmmoDefinitionClass::IconTextureName::get()
	{
		return gcnew String(InternalAmmoDefinitionClassPointer->IconTextureName.Peek_Buffer());
	}

	void AmmoDefinitionClass::IconTextureName::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalAmmoDefinitionClassPointer->IconTextureName = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	RectClass AmmoDefinitionClass::IconTextureUV::get()
	{
		RectClass result;
		RectClass::UnmanagedToManagedRectClass(InternalAmmoDefinitionClassPointer->IconTextureUV, result);

		return result;
	}

	void AmmoDefinitionClass::IconTextureUV::set(RectClass value)
	{
		RectClass::ManagedToUnmanagedRectClass(value, InternalAmmoDefinitionClassPointer->IconTextureUV);
	}

	Vector2 AmmoDefinitionClass::IconOffset::get()
	{
		Vector2 result;
		Vector2::UnmanagedToManagedVector2(InternalAmmoDefinitionClassPointer->IconOffset, result);

		return result;
	}

	void AmmoDefinitionClass::IconOffset::set(Vector2 value)
	{
		Vector2::ManagedToUnmanagedVector2(value, InternalAmmoDefinitionClassPointer->IconOffset);
	}

	float AmmoDefinitionClass::GrenadeSafetyTime::get()
	{
		return InternalAmmoDefinitionClassPointer->GrenadeSafetyTime;
	}

	void AmmoDefinitionClass::GrenadeSafetyTime::set(float value)
	{
		InternalAmmoDefinitionClassPointer->GrenadeSafetyTime = value;
	}

	bool AmmoDefinitionClass::C4Animation::get()
	{
		return InternalAmmoDefinitionClassPointer->C4Animation;
	}

	void AmmoDefinitionClass::C4Animation::set(bool value)
	{
		InternalAmmoDefinitionClassPointer->C4Animation = value;
	}

	float AmmoDefinitionClass::TargetingRange::get()
	{
		return InternalAmmoDefinitionClassPointer->TargetingRange;
	}

	void AmmoDefinitionClass::TargetingRange::set(float value)
	{
		InternalAmmoDefinitionClassPointer->TargetingRange = value;
	}

	int AmmoDefinitionClass::C4Preset::get()
	{
		return InternalAmmoDefinitionClassPointer->C4Preset;
	}

	void AmmoDefinitionClass::C4Preset::set(int value)
	{
		InternalAmmoDefinitionClassPointer->C4Preset = value;
	}

	bool AmmoDefinitionClass::DisableHitscan::get()
	{
		return InternalAmmoDefinitionClassPointer->DisableHitscan;
	}

	void AmmoDefinitionClass::DisableHitscan::set(bool value)
	{
		InternalAmmoDefinitionClassPointer->DisableHitscan = value;
	}

	bool AmmoDefinitionClass::TrackingIgnoreVehicle::get()
	{
		return InternalAmmoDefinitionClassPointer->TrackingIgnoreVehicle;
	}

	void AmmoDefinitionClass::TrackingIgnoreVehicle::set(bool value)
	{
		InternalAmmoDefinitionClassPointer->TrackingIgnoreVehicle = value;
	}

	bool AmmoDefinitionClass::TrackingIgnoreSoldier::get()
	{
		return InternalAmmoDefinitionClassPointer->TrackingIgnoreSoldier;
	}

	void AmmoDefinitionClass::TrackingIgnoreSoldier::set(bool value)
	{
		InternalAmmoDefinitionClassPointer->TrackingIgnoreSoldier = value;
	}

	bool AmmoDefinitionClass::TrackingIgnoreVTOL::get()
	{
		return InternalAmmoDefinitionClassPointer->TrackingIgnoreVTOL;
	}

	void AmmoDefinitionClass::TrackingIgnoreVTOL::set(bool value)
	{
		InternalAmmoDefinitionClassPointer->TrackingIgnoreVTOL = value;
	}

	::DefinitionClass *AmmoDefinitionClass::InternalDefinitionClassPointer::get()
	{
		return InternalAmmoDefinitionClassPointer;
	}

	::AmmoDefinitionClass *AmmoDefinitionClass::InternalAmmoDefinitionClassPointer::get()
	{
		return reinterpret_cast<::AmmoDefinitionClass *>(Pointer.ToPointer());
	}

	WeaponDefinitionClass::WeaponDefinitionClass(IntPtr pointer)
		: DefinitionClass(pointer)
	{

	}

	IntPtr WeaponDefinitionClass::WeaponDefinitionClassPointer::get()
	{
		return IntPtr(InternalWeaponDefinitionClassPointer);
	}

	int WeaponDefinitionClass::Style::get()
	{
		return InternalWeaponDefinitionClassPointer->Style;
	}

	void WeaponDefinitionClass::Style::set(int value)
	{
		InternalWeaponDefinitionClassPointer->Style = value;
	}

	String ^WeaponDefinitionClass::Model::get()
	{
		return gcnew String(InternalWeaponDefinitionClassPointer->Model.Peek_Buffer());
	}

	void WeaponDefinitionClass::Model::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalWeaponDefinitionClassPointer->Model = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	String ^WeaponDefinitionClass::IdleAnim::get()
	{
		return gcnew String(InternalWeaponDefinitionClassPointer->IdleAnim.Peek_Buffer());
	}

	void WeaponDefinitionClass::IdleAnim::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalWeaponDefinitionClassPointer->IdleAnim = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	String ^WeaponDefinitionClass::FireAnim::get()
	{
		return gcnew String(InternalWeaponDefinitionClassPointer->FireAnim.Peek_Buffer());
	}

	void WeaponDefinitionClass::FireAnim::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalWeaponDefinitionClassPointer->FireAnim = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	String ^WeaponDefinitionClass::BackModel::get()
	{
		return gcnew String(InternalWeaponDefinitionClassPointer->BackModel.Peek_Buffer());
	}

	void WeaponDefinitionClass::BackModel::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalWeaponDefinitionClassPointer->BackModel = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	float WeaponDefinitionClass::SwitchTime::get()
	{
		return InternalWeaponDefinitionClassPointer->SwitchTime;
	}

	void WeaponDefinitionClass::SwitchTime::set(float value)
	{
		InternalWeaponDefinitionClassPointer->SwitchTime = value;
	}

	float WeaponDefinitionClass::ReloadTime::get()
	{
		return InternalWeaponDefinitionClassPointer->ReloadTime;
	}

	void WeaponDefinitionClass::ReloadTime::set(float value)
	{
		InternalWeaponDefinitionClassPointer->ReloadTime = value;
	}

	float WeaponDefinitionClass::KeyNumber::get()
	{
		return InternalWeaponDefinitionClassPointer->KeyNumber;
	}

	void WeaponDefinitionClass::KeyNumber::set(float value)
	{
		InternalWeaponDefinitionClassPointer->KeyNumber = value;
	}

	bool WeaponDefinitionClass::CanSnipe::get()
	{
		return InternalWeaponDefinitionClassPointer->CanSnipe;
	}

	void WeaponDefinitionClass::CanSnipe::set(bool value)
	{
		InternalWeaponDefinitionClassPointer->CanSnipe = value;
	}

	bool WeaponDefinitionClass::CanReceiveGenericCnCAmmo::get()
	{
		return InternalWeaponDefinitionClassPointer->CanReceiveGenericCnCAmmo;
	}

	void WeaponDefinitionClass::CanReceiveGenericCnCAmmo::set(bool value)
	{
		InternalWeaponDefinitionClassPointer->CanReceiveGenericCnCAmmo = value;
	}

	float WeaponDefinitionClass::Rating::get()
	{
		return InternalWeaponDefinitionClassPointer->Rating;
	}

	void WeaponDefinitionClass::Rating::set(float value)
	{
		InternalWeaponDefinitionClassPointer->Rating = value;
	}

	int WeaponDefinitionClass::EjectPhysDefID::get()
	{
		return InternalWeaponDefinitionClassPointer->EjectPhysDefID;
	}

	void WeaponDefinitionClass::EjectPhysDefID::set(int value)
	{
		InternalWeaponDefinitionClassPointer->EjectPhysDefID = value;
	}

	int WeaponDefinitionClass::MuzzleFlashPhysDefID::get()
	{
		return InternalWeaponDefinitionClassPointer->MuzzleFlashPhysDefID;
	}

	void WeaponDefinitionClass::MuzzleFlashPhysDefID::set(int value)
	{
		InternalWeaponDefinitionClassPointer->MuzzleFlashPhysDefID = value;
	}

	String ^WeaponDefinitionClass::FirstPersonModel::get()
	{
		return gcnew String(InternalWeaponDefinitionClassPointer->FirstPersonModel.Peek_Buffer());
	}

	void WeaponDefinitionClass::FirstPersonModel::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalWeaponDefinitionClassPointer->FirstPersonModel = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	Vector3 WeaponDefinitionClass::FirstPersonOffset::get()
	{
		Vector3 result;
		Vector3::UnmanagedToManagedVector3(InternalWeaponDefinitionClassPointer->FirstPersonOffset, result);

		return result;
	}

	void WeaponDefinitionClass::FirstPersonOffset::set(Vector3 value)
	{
		Vector3::ManagedToUnmanagedVector3(value, InternalWeaponDefinitionClassPointer->FirstPersonOffset);
	}

	float WeaponDefinitionClass::RecoilImpulse::get()
	{
		return InternalWeaponDefinitionClassPointer->RecoilImpulse;
	}

	void WeaponDefinitionClass::RecoilImpulse::set(float value)
	{
		InternalWeaponDefinitionClassPointer->RecoilImpulse = value;
	}

	String ^WeaponDefinitionClass::HUDIconTextureName::get()
	{
		return gcnew String(InternalWeaponDefinitionClassPointer->HUDIconTextureName.Peek_Buffer());
	}

	void WeaponDefinitionClass::HUDIconTextureName::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalWeaponDefinitionClassPointer->HUDIconTextureName = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	int WeaponDefinitionClass::ReloadSoundDefID::get()
	{
		return InternalWeaponDefinitionClassPointer->ReloadSoundDefID;
	}

	void WeaponDefinitionClass::ReloadSoundDefID::set(int value)
	{
		InternalWeaponDefinitionClassPointer->ReloadSoundDefID = value;
	}

	int WeaponDefinitionClass::EmptySoundDefID::get()
	{
		return InternalWeaponDefinitionClassPointer->EmptySoundDefID;
	}

	void WeaponDefinitionClass::EmptySoundDefID::set(int value)
	{
		InternalWeaponDefinitionClassPointer->EmptySoundDefID = value;
	}

	int WeaponDefinitionClass::PrimaryAmmoDefID::get()
	{
		return InternalWeaponDefinitionClassPointer->PrimaryAmmoDefID;
	}

	void WeaponDefinitionClass::PrimaryAmmoDefID::set(int value)
	{
		InternalWeaponDefinitionClassPointer->PrimaryAmmoDefID = value;
	}

	int WeaponDefinitionClass::SecondaryAmmoDefID::get()
	{
		return InternalWeaponDefinitionClassPointer->SecondaryAmmoDefID;
	}

	void WeaponDefinitionClass::SecondaryAmmoDefID::set(int value)
	{
		InternalWeaponDefinitionClassPointer->SecondaryAmmoDefID = value;
	}

	int WeaponDefinitionClass::ClipSize::get()
	{
		return InternalWeaponDefinitionClassPointer->ClipSize;
	}

	void WeaponDefinitionClass::ClipSize::set(int value)
	{
		InternalWeaponDefinitionClassPointer->ClipSize = value;
	}

	float WeaponDefinitionClass::RecoilTime::get()
	{
		return InternalWeaponDefinitionClassPointer->RecoilTime;
	}

	void WeaponDefinitionClass::RecoilTime::set(float value)
	{
		InternalWeaponDefinitionClassPointer->RecoilTime = value;
	}

	float WeaponDefinitionClass::RecoilScale::get()
	{
		return InternalWeaponDefinitionClassPointer->RecoilScale;
	}

	void WeaponDefinitionClass::RecoilScale::set(float value)
	{
		InternalWeaponDefinitionClassPointer->RecoilScale = value;
	}

	bool WeaponDefinitionClass::AGiveWeaponsWeapon::get()
	{
		return InternalWeaponDefinitionClassPointer->AGiveWeaponsWeapon;
	}

	void WeaponDefinitionClass::AGiveWeaponsWeapon::set(bool value)
	{
		InternalWeaponDefinitionClassPointer->AGiveWeaponsWeapon = value;
	}

	int WeaponDefinitionClass::MaxInventoryRounds::get()
	{
		return InternalWeaponDefinitionClassPointer->MaxInventoryRounds;
	}

	void WeaponDefinitionClass::MaxInventoryRounds::set(int value)
	{
		InternalWeaponDefinitionClassPointer->MaxInventoryRounds = value;
	}

	int WeaponDefinitionClass::IconNameID::get()
	{
		return InternalWeaponDefinitionClassPointer->IconNameID;
	}

	void WeaponDefinitionClass::IconNameID::set(int value)
	{
		InternalWeaponDefinitionClassPointer->IconNameID = value;
	}

	String ^WeaponDefinitionClass::IconTextureName::get()
	{
		return gcnew String(InternalWeaponDefinitionClassPointer->IconTextureName.Peek_Buffer());
	}

	void WeaponDefinitionClass::IconTextureName::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalWeaponDefinitionClassPointer->IconTextureName = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	RectClass WeaponDefinitionClass::IconTextureUV::get()
	{
		RectClass result;
		RectClass::UnmanagedToManagedRectClass(InternalWeaponDefinitionClassPointer->IconTextureUV, result);

		return result;
	}

	void WeaponDefinitionClass::IconTextureUV::set(RectClass value)
	{
		RectClass::ManagedToUnmanagedRectClass(value, InternalWeaponDefinitionClassPointer->IconTextureUV);
	}

	Vector2 WeaponDefinitionClass::IconOffset::get()
	{
		Vector2 result;
		Vector2::UnmanagedToManagedVector2(InternalWeaponDefinitionClassPointer->IconOffset, result);

		return result;
	}

	void WeaponDefinitionClass::IconOffset::set(Vector2 value)
	{
		Vector2::ManagedToUnmanagedVector2(value, InternalWeaponDefinitionClassPointer->IconOffset);
	}

	String ^WeaponDefinitionClass::HumanFiringAnimation::get()
	{
		return gcnew String(InternalWeaponDefinitionClassPointer->HumanFiringAnimation.Peek_Buffer());
	}

	void WeaponDefinitionClass::HumanFiringAnimation::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalWeaponDefinitionClassPointer->HumanFiringAnimation = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	String ^WeaponDefinitionClass::ScopeTexture::get()
	{
		return gcnew String(InternalWeaponDefinitionClassPointer->ScopeTexture.Peek_Buffer());
	}

	void WeaponDefinitionClass::ScopeTexture::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalWeaponDefinitionClassPointer->ScopeTexture = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	float WeaponDefinitionClass::MaxZoom::get()
	{
		return InternalWeaponDefinitionClassPointer->MaxZoom;
	}

	void WeaponDefinitionClass::MaxZoom::set(float value)
	{
		InternalWeaponDefinitionClassPointer->MaxZoom = value;
	}

	float WeaponDefinitionClass::MinZoom::get()
	{
		return InternalWeaponDefinitionClassPointer->MinZoom;
	}

	void WeaponDefinitionClass::MinZoom::set(float value)
	{
		InternalWeaponDefinitionClassPointer->MinZoom = value;
	}

	int WeaponDefinitionClass::GlobalFireSoundDefID::get()
	{
		return InternalWeaponDefinitionClassPointer->GlobalFireSoundDefID;
	}

	void WeaponDefinitionClass::GlobalFireSoundDefID::set(int value)
	{
		InternalWeaponDefinitionClassPointer->GlobalFireSoundDefID = value;
	}

	bool WeaponDefinitionClass::AreaEffectWeapon::get()
	{
		return InternalWeaponDefinitionClassPointer->AreaEffectWeapon;
	}

	void WeaponDefinitionClass::AreaEffectWeapon::set(bool value)
	{
		InternalWeaponDefinitionClassPointer->AreaEffectWeapon = value;
	}

	bool WeaponDefinitionClass::AreaEffectWeaponAffectOwner::get()
	{
		return InternalWeaponDefinitionClassPointer->AreaEffectWeaponAffectOwner;
	}

	void WeaponDefinitionClass::AreaEffectWeaponAffectOwner::set(bool value)
	{
		InternalWeaponDefinitionClassPointer->AreaEffectWeaponAffectOwner = value;
	}

	bool WeaponDefinitionClass::AreaEffectWeaponAffectFriendly::get()
	{
		return InternalWeaponDefinitionClassPointer->AreaEffectWeaponAffectFriendly;
	}

	void WeaponDefinitionClass::AreaEffectWeaponAffectFriendly::set(bool value)
	{
		InternalWeaponDefinitionClassPointer->AreaEffectWeaponAffectFriendly = value;
	}

	bool WeaponDefinitionClass::AreaEffectWeaponAffectEnemy::get()
	{
		return InternalWeaponDefinitionClassPointer->AreaEffectWeaponAffectEnemy;
	}

	void WeaponDefinitionClass::AreaEffectWeaponAffectEnemy::set(bool value)
	{
		InternalWeaponDefinitionClassPointer->AreaEffectWeaponAffectEnemy = value;
	}

	bool WeaponDefinitionClass::AreaEffectWeaponAffectNeutral::get()
	{
		return InternalWeaponDefinitionClassPointer->AreaEffectWeaponAffectNeutral;
	}

	void WeaponDefinitionClass::AreaEffectWeaponAffectNeutral::set(bool value)
	{
		InternalWeaponDefinitionClassPointer->AreaEffectWeaponAffectNeutral = value;
	}

	String ^WeaponDefinitionClass::FirstPersonAnim::get()
	{
		return gcnew String(InternalWeaponDefinitionClassPointer->FirstPersonAnim.Peek_Buffer());
	}

	void WeaponDefinitionClass::FirstPersonAnim::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalWeaponDefinitionClassPointer->FirstPersonAnim = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	bool WeaponDefinitionClass::DoTiltWhileReloading::get()
	{
		return InternalWeaponDefinitionClassPointer->DoTiltWhileReloading;
	}

	void WeaponDefinitionClass::DoTiltWhileReloading::set(bool value)
	{
		InternalWeaponDefinitionClassPointer->DoTiltWhileReloading = value;
	}

	bool WeaponDefinitionClass::AllowEmptyShots::get()
	{
		return InternalWeaponDefinitionClassPointer->AllowEmptyShots;
	}

	void WeaponDefinitionClass::AllowEmptyShots::set(bool value)
	{
		InternalWeaponDefinitionClassPointer->AllowEmptyShots = value;
	}

	::DefinitionClass *WeaponDefinitionClass::InternalDefinitionClassPointer::get()
	{
		return InternalWeaponDefinitionClassPointer;
	}

	::WeaponDefinitionClass *WeaponDefinitionClass::InternalWeaponDefinitionClassPointer::get()
	{
		return reinterpret_cast<::WeaponDefinitionClass *>(Pointer.ToPointer());
	}

	ExplosionDefinitionClass::ExplosionDefinitionClass(IntPtr pointer)
		: DefinitionClass(pointer)
	{

	}

	IntPtr ExplosionDefinitionClass::ExplosionDefinitionClassPointer::get()
	{
		return IntPtr(InternalExplosionDefinitionClassPointer);
	}

	int ExplosionDefinitionClass::PhysDefID::get()
	{
		return InternalExplosionDefinitionClassPointer->PhysDefID;
	}

	void ExplosionDefinitionClass::PhysDefID::set(int value)
	{
		InternalExplosionDefinitionClassPointer->PhysDefID = value;
	}

	uint32 ExplosionDefinitionClass::SoundDefID::get()
	{
		return InternalExplosionDefinitionClassPointer->SoundDefID;
	}

	void ExplosionDefinitionClass::SoundDefID::set(uint32 value)
	{
		InternalExplosionDefinitionClassPointer->SoundDefID = value;
	}

	float ExplosionDefinitionClass::DamageRadius::get()
	{
		return InternalExplosionDefinitionClassPointer->DamageRadius;
	}

	void ExplosionDefinitionClass::DamageRadius::set(float value)
	{
		InternalExplosionDefinitionClassPointer->DamageRadius = value;
	}

	float ExplosionDefinitionClass::DamageStrength::get()
	{
		return InternalExplosionDefinitionClassPointer->DamageStrength;
	}

	void ExplosionDefinitionClass::DamageStrength::set(float value)
	{
		InternalExplosionDefinitionClassPointer->DamageStrength = value;
	}

	int ExplosionDefinitionClass::Warhead::get()
	{
		return InternalExplosionDefinitionClassPointer->Warhead;
	}

	void ExplosionDefinitionClass::Warhead::set(int value)
	{
		InternalExplosionDefinitionClassPointer->Warhead = value;
	}

	bool ExplosionDefinitionClass::DamageIsScaled::get()
	{
		return InternalExplosionDefinitionClassPointer->DamageIsScaled;
	}

	void ExplosionDefinitionClass::DamageIsScaled::set(bool value)
	{
		InternalExplosionDefinitionClassPointer->DamageIsScaled = value;
	}

	String ^ExplosionDefinitionClass::DecalFilename::get()
	{
		return gcnew String(InternalExplosionDefinitionClassPointer->DecalFilename.Peek_Buffer());
	}

	void ExplosionDefinitionClass::DecalFilename::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalExplosionDefinitionClassPointer->DecalFilename = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	float ExplosionDefinitionClass::DecalSize::get()
	{
		return InternalExplosionDefinitionClassPointer->DecalSize;
	}

	void ExplosionDefinitionClass::DecalSize::set(float value)
	{
		InternalExplosionDefinitionClassPointer->DecalSize = value;
	}

	bool ExplosionDefinitionClass::AnimatedExplosion::get()
	{
		return InternalExplosionDefinitionClassPointer->AnimatedExplosion;
	}

	void ExplosionDefinitionClass::AnimatedExplosion::set(bool value)
	{
		InternalExplosionDefinitionClassPointer->AnimatedExplosion = value;
	}

	float ExplosionDefinitionClass::CameraShakeIntensity::get()
	{
		return InternalExplosionDefinitionClassPointer->CameraShakeIntensity;
	}

	void ExplosionDefinitionClass::CameraShakeIntensity::set(float value)
	{
		InternalExplosionDefinitionClassPointer->CameraShakeIntensity = value;
	}

	float ExplosionDefinitionClass::CameraShakeRadius::get()
	{
		return InternalExplosionDefinitionClassPointer->CameraShakeRadius;
	}

	void ExplosionDefinitionClass::CameraShakeRadius::set(float value)
	{
		InternalExplosionDefinitionClassPointer->CameraShakeRadius = value;
	}

	float ExplosionDefinitionClass::CameraShakeDuration::get()
	{
		return InternalExplosionDefinitionClassPointer->CameraShakeDuration;
	}

	void ExplosionDefinitionClass::CameraShakeDuration::set(float value)
	{
		InternalExplosionDefinitionClassPointer->CameraShakeDuration = value;
	}

	float ExplosionDefinitionClass::CollisionDamageMultiplier::get()
	{
		return InternalExplosionDefinitionClassPointer->CollisionDamageMultiplier;
	}

	void ExplosionDefinitionClass::CollisionDamageMultiplier::set(float value)
	{
		InternalExplosionDefinitionClassPointer->CollisionDamageMultiplier = value;
	}

	bool ExplosionDefinitionClass::ResetMappers::get()
	{
		return InternalExplosionDefinitionClassPointer->AnimatedExplosion;
	}

	void ExplosionDefinitionClass::ResetMappers::set(bool value)
	{
		InternalExplosionDefinitionClassPointer->AnimatedExplosion = value;
	}

	::DefinitionClass *ExplosionDefinitionClass::InternalDefinitionClassPointer::get()
	{
		return InternalExplosionDefinitionClassPointer;
	}

	::ExplosionDefinitionClass *ExplosionDefinitionClass::InternalExplosionDefinitionClassPointer::get()
	{
		return reinterpret_cast<::ExplosionDefinitionClass *>(Pointer.ToPointer());
	}
}