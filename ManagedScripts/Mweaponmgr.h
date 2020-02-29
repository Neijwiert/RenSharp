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

#include "MDefinition.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <weaponmgr.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{

#pragma warning(push)
#pragma warning(disable : 4099 4251 4244 26495 26454)

	value class Vector3;
	value class Vector2;
	value class RectClass;

#pragma warning(pop)

	public interface class IAmmoDefinitionClass : public IDefinitionClass
	{
		enum class AmmoTypeEnum : int
		{
			AmmoTypeNormal = ::AmmoDefinitionClass::AMMO_TYPE_NORMAL,
			AmmoTypeC4Remote = ::AmmoDefinitionClass::AMMO_TYPE_C4_REMOTE,
			AmmoTypeC4Timed = ::AmmoDefinitionClass::AMMO_TYPE_C4_TIMED,
			AmmoTypeC4Proximity = ::AmmoDefinitionClass::AMMO_TYPE_C4_PROXIMITY
		};

		literal unsigned int AmmoDefinitionClassClassID = 45058;

		property IntPtr AmmoDefinitionClassPointer
		{
			IntPtr get();
		}

		property String ^ModelFilename
		{
			String ^get();
			void set(String ^value);
		}

		property String ^ModelName
		{
			String ^get();
			void set(String ^value);
		}

		property int Warhead
		{
			int get();
			void set(int value);
		}

		property float Damage
		{
			float get();
			void set(float value);
		}

		property float Range
		{
			float get();
			void set(float value);
		}

		property float Velocity
		{
			float get();
			void set(float value);
		}

		property float Gravity
		{
			float get();
			void set(float value);
		}

		property float Elasticity
		{
			float get();
			void set(float value);
		}

		property float RateOfFire
		{
			float get();
			void set(float value);
		}

		property float SprayAngle
		{
			float get();
			void set(float value);
		}

		property int SprayCount
		{
			int get();
			void set(int value);
		}

		property String ^TrailEmitter
		{
			String ^get();
			void set(String ^value);
		}

		property float AquireTime
		{
			float get();
			void set(float value);
		}

		property float BurstDelayTime
		{
			float get();
			void set(float value);
		}

		property int BurstMax
		{
			int get();
			void set(int value);
		}

		property int SoftPierceLimit
		{
			int get();
			void set(int value);
		}

		property float TurnRate
		{
			float get();
			void set(float value);
		}

		property bool TimeActivated
		{
			bool get();
			void set(bool value);
		}

		property bool TerrainActivated
		{
			bool get();
			void set(bool value);
		}

		property bool IsTracking
		{
			bool get();
			void set(bool value);
		}

		property float EffectiveRange
		{
			float get();
			void set(float value);
		}

		property int ExplosionDefID
		{
			int get();
			void set(int value);
		}

		property float RandomTrackingScale
		{
			float get();
			void set(float value);
		}

		property bool DisplayLaser
		{
			bool get();
			void set(bool value);
		}

		property float ChargeTime
		{
			float get();
			void set(float value);
		}

		property int ContinuousSoundDefID
		{
			int get();
			void set(int value);
		}

		property int FireSoundDefID
		{
			int get();
			void set(int value);
		}

		property String ^ContinuousEmitterName
		{
			String ^get();
			void set(String ^value);
		}

		property int MaxBounces
		{
			int get();
			void set(int value);
		}

		property int SprayBulletCost
		{
			int get();
			void set(int value);
		}

		property int AmmoType
		{
			int get();
			void set(int value);
		}

		property float C4TriggerTime1
		{
			float get();
			void set(float value);
		}

		property float C4TriggerTime2
		{
			float get();
			void set(float value);
		}

		property float C4TriggerTime3
		{
			float get();
			void set(float value);
		}

		property float C4TriggerRange1
		{
			float get();
			void set(float value);
		}

		property float C4TriggerRange2
		{
			float get();
			void set(float value);
		}

		property float C4TriggerRange3
		{
			float get();
			void set(float value);
		}

		property int C4TimingSound1ID
		{
			int get();
			void set(int value);
		}

		property int C4TimingSound2ID
		{
			int get();
			void set(int value);
		}

		property int C4TimingSound3ID
		{
			int get();
			void set(int value);
		}

		property float AliasedSpeed
		{
			float get();
			void set(float value);
		}

		property int HitterType
		{
			int get();
			void set(int value);
		}

		property int BeaconDefID
		{
			int get();
			void set(int value);
		}

		property bool BeamEnabled
		{
			bool get();
			void set(bool value);
		}

		property Vector3 BeamColor
		{
			Vector3 get();
			void set(Vector3 value);
		}

		property float BeamTime
		{
			float get();
			void set(float value);
		}

		property float BeamWidth
		{
			float get();
			void set(float value);
		}

		property bool BeamEndCaps
		{
			bool get();
			void set(bool value);
		}

		property String ^BeamTexture
		{
			String ^get();
			void set(String ^value);
		}

		property bool BeamSubdivisionEnabled
		{
			bool get();
			void set(bool value);
		}

		property float BeamSubdivisionScale
		{
			float get();
			void set(float value);
		}

		property bool BeamSubdivisionFrozen
		{
			bool get();
			void set(bool value);
		}

		property int IconNameID
		{
			int get();
			void set(int value);
		}

		property String ^IconTextureName
		{
			String ^get();
			void set(String ^value);
		}

		property RectClass IconTextureUV
		{
			RectClass get();
			void set(RectClass value);
		}

		property Vector2 IconOffset
		{
			Vector2 get();
			void set(Vector2 value);
		}

		property float GrenadeSafetyTime
		{
			float get();
			void set(float value);
		}

		property bool C4Animation
		{
			bool get();
			void set(bool value);
		}

		property float TargetingRange
		{
			float get();
			void set(float value);
		}

		property int C4Preset
		{
			int get();
			void set(int value);
		}

		property bool DisableHitscan
		{
			bool get();
			void set(bool value);
		}

		property bool TrackingIgnoreVehicle
		{
			bool get();
			void set(bool value);
		}

		property bool TrackingIgnoreSoldier
		{
			bool get();
			void set(bool value);
		}

		property bool TrackingIgnoreVTOL
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class AmmoDefinitionClass : public DefinitionClass, public IAmmoDefinitionClass
	{
		public:
			AmmoDefinitionClass(IntPtr pointer);

			property IntPtr AmmoDefinitionClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property String ^ModelFilename
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property String ^ModelName
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property int Warhead
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property float Damage
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float Range
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float Velocity
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float Gravity
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float Elasticity
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float RateOfFire
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float SprayAngle
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int SprayCount
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property String ^TrailEmitter
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property float AquireTime
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float BurstDelayTime
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int BurstMax
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int SoftPierceLimit
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property float TurnRate
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool TimeActivated
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool TerrainActivated
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsTracking
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property float EffectiveRange
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int ExplosionDefID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property float RandomTrackingScale
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool DisplayLaser
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property float ChargeTime
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int ContinuousSoundDefID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int FireSoundDefID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property String ^ContinuousEmitterName
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property int MaxBounces
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int SprayBulletCost
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int AmmoType
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property float C4TriggerTime1
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float C4TriggerTime2
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float C4TriggerTime3
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float C4TriggerRange1
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float C4TriggerRange2
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float C4TriggerRange3
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int C4TimingSound1ID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int C4TimingSound2ID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int C4TimingSound3ID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property float AliasedSpeed
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int HitterType
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int BeaconDefID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property bool BeamEnabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property Vector3 BeamColor
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

			property float BeamTime
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float BeamWidth
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool BeamEndCaps
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property String ^BeamTexture
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property bool BeamSubdivisionEnabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property float BeamSubdivisionScale
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool BeamSubdivisionFrozen
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property int IconNameID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property String ^IconTextureName
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property RectClass IconTextureUV
			{
				virtual RectClass get() sealed;
				virtual void set(RectClass value) sealed;
			}

			property Vector2 IconOffset
			{
				virtual Vector2 get() sealed;
				virtual void set(Vector2 value) sealed;
			}

			property float GrenadeSafetyTime
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool C4Animation
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property float TargetingRange
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int C4Preset
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property bool DisableHitscan
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool TrackingIgnoreVehicle
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool TrackingIgnoreSoldier
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool TrackingIgnoreVTOL
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			property ::DefinitionClass *InternalDefinitionClassPointer
			{
				::DefinitionClass *get() override;
			}

			property ::AmmoDefinitionClass *InternalAmmoDefinitionClassPointer
			{
				virtual ::AmmoDefinitionClass *get();
			}
	};

	public interface class IWeaponDefinitionClass : public IDefinitionClass
	{
		literal unsigned int WeaponDefinitionClassClassID = 45057;

		property IntPtr WeaponDefinitionClassPointer
		{
			IntPtr get();
		}

		property int Style
		{
			int get();
			void set(int value);
		}

		property String ^Model
		{
			String ^get();
			void set(String ^value);
		}

		property String ^IdleAnim
		{
			String ^get();
			void set(String ^value);
		}

		property String ^FireAnim
		{
			String ^get();
			void set(String ^value);
		}

		property String ^BackModel
		{
			String ^get();
			void set(String ^value);
		}

		property float SwitchTime
		{
			float get();
			void set(float value);
		}

		property float ReloadTime
		{
			float get();
			void set(float value);
		}

		property float KeyNumber
		{
			float get();
			void set(float value);
		}

		property bool CanSnipe
		{
			bool get();
			void set(bool value);
		}

		property bool CanReceiveGenericCnCAmmo
		{
			bool get();
			void set(bool value);
		}

		property float Rating
		{
			float get();
			void set(float value);
		}

		property int EjectPhysDefID
		{
			int get();
			void set(int value);
		}

		property int MuzzleFlashPhysDefID
		{
			int get();
			void set(int value);
		}

		property String ^FirstPersonModel
		{
			String ^get();
			void set(String ^value);
		}

		property Vector3 FirstPersonOffset
		{
			Vector3 get();
			void set(Vector3 value);
		}

		property float RecoilImpulse
		{
			float get();
			void set(float value);
		}

		property String ^HUDIconTextureName
		{
			String ^get();
			void set(String ^value);
		}

		property int ReloadSoundDefID
		{
			int get();
			void set(int value);
		}

		property int EmptySoundDefID
		{
			int get();
			void set(int value);
		}

		property int PrimaryAmmoDefID
		{
			int get();
			void set(int value);
		}

		property int SecondaryAmmoDefID
		{
			int get();
			void set(int value);
		}

		property int ClipSize
		{
			int get();
			void set(int value);
		}

		property float RecoilTime
		{
			float get();
			void set(float value);
		}

		property float RecoilScale
		{
			float get();
			void set(float value);
		}

		property bool AGiveWeaponsWeapon
		{
			bool get();
			void set(bool value);
		}

		property int MaxInventoryRounds
		{
			int get();
			void set(int value);
		}

		property int IconNameID
		{
			int get();
			void set(int value);
		}

		property String ^IconTextureName
		{
			String ^get();
			void set(String ^value);
		}

		property RectClass IconTextureUV
		{
			RectClass get();
			void set(RectClass value);
		}

		property Vector2 IconOffset
		{
			Vector2 get();
			void set(Vector2 value);
		}

		property String ^HumanFiringAnimation
		{
			String ^get();
			void set(String ^value);
		}

		property String ^ScopeTexture
		{
			String ^get();
			void set(String ^value);
		}

		property float MaxZoom
		{
			float get();
			void set(float value);
		}

		property float MinZoom
		{
			float get();
			void set(float value);
		}

		property int GlobalFireSoundDefID
		{
			int get();
			void set(int value);
		}

		property bool AreaEffectWeapon
		{
			bool get();
			void set(bool value);
		}

		property bool AreaEffectWeaponAffectOwner
		{
			bool get();
			void set(bool value);
		}

		property bool AreaEffectWeaponAffectFriendly
		{
			bool get();
			void set(bool value);
		}

		property bool AreaEffectWeaponAffectEnemy
		{
			bool get();
			void set(bool value);
		}

		property bool AreaEffectWeaponAffectNeutral
		{
			bool get();
			void set(bool value);
		}

		property String ^FirstPersonAnim
		{
			String ^get();
			void set(String ^value);
		}

		property bool DoTiltWhileReloading
		{
			bool get();
			void set(bool value);
		}

		property bool AllowEmptyShots
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class WeaponDefinitionClass : public DefinitionClass, public IWeaponDefinitionClass
	{
		public:
			WeaponDefinitionClass(IntPtr pointer);

			property IntPtr WeaponDefinitionClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property int Style
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property String ^Model
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property String ^IdleAnim
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property String ^FireAnim
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property String ^BackModel
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property float SwitchTime
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float ReloadTime
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float KeyNumber
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool CanSnipe
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool CanReceiveGenericCnCAmmo
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property float Rating
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int EjectPhysDefID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int MuzzleFlashPhysDefID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property String ^FirstPersonModel
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property Vector3 FirstPersonOffset
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

			property float RecoilImpulse
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property String ^HUDIconTextureName
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property int ReloadSoundDefID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int EmptySoundDefID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int PrimaryAmmoDefID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int SecondaryAmmoDefID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int ClipSize
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property float RecoilTime
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float RecoilScale
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool AGiveWeaponsWeapon
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property int MaxInventoryRounds
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int IconNameID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property String ^IconTextureName
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property RectClass IconTextureUV
			{
				virtual RectClass get() sealed;
				virtual void set(RectClass value) sealed;
			}

			property Vector2 IconOffset
			{
				virtual Vector2 get() sealed;
				virtual void set(Vector2 value) sealed;
			}

			property String ^HumanFiringAnimation
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property String ^ScopeTexture
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property float MaxZoom
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float MinZoom
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int GlobalFireSoundDefID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property bool AreaEffectWeapon
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool AreaEffectWeaponAffectOwner
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool AreaEffectWeaponAffectFriendly
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool AreaEffectWeaponAffectEnemy
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool AreaEffectWeaponAffectNeutral
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property String ^FirstPersonAnim
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property bool DoTiltWhileReloading
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool AllowEmptyShots
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			property ::DefinitionClass *InternalDefinitionClassPointer
			{
				::DefinitionClass *get() override;
			}

			property ::WeaponDefinitionClass *InternalWeaponDefinitionClassPointer
			{
				virtual ::WeaponDefinitionClass *get();
			}
	};

	public interface class IExplosionDefinitionClass : public IDefinitionClass
	{
		literal unsigned int ExplosionDefinitionClassClassID = 45059;

		property IntPtr ExplosionDefinitionClassPointer
		{
			IntPtr get();
		}

		property int PhysDefID
		{
			int get();
			void set(int value);
		}

		property uint32 SoundDefID
		{
			uint32 get();
			void set(uint32 value);
		}

		property float DamageRadius
		{
			float get();
			void set(float value);
		}

		property float DamageStrength
		{
			float get();
			void set(float value);
		}

		property int Warhead
		{
			int get();
			void set(int value);
		}

		property bool DamageIsScaled
		{
			bool get();
			void set(bool value);
		}

		property String ^DecalFilename
		{
			String ^get();
			void set(String ^value);
		}

		property float DecalSize
		{
			float get();
			void set(float value);
		}

		property bool AnimatedExplosion
		{
			bool get();
			void set(bool value);
		}

		property float CameraShakeIntensity
		{
			float get();
			void set(float value);
		}

		property float CameraShakeRadius
		{
			float get();
			void set(float value);
		}

		property float CameraShakeDuration
		{
			float get();
			void set(float value);
		}

		property float CollisionDamageMultiplier
		{
			float get();
			void set(float value);
		}

		property bool ResetMappers
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class ExplosionDefinitionClass : public DefinitionClass, public IExplosionDefinitionClass
	{
		public:
			ExplosionDefinitionClass(IntPtr pointer);

			property IntPtr ExplosionDefinitionClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property int PhysDefID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property uint32 SoundDefID
			{
				virtual uint32 get() sealed;
				virtual void set(uint32 value) sealed;
			}

			property float DamageRadius
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float DamageStrength
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int Warhead
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property bool DamageIsScaled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property String ^DecalFilename
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property float DecalSize
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool AnimatedExplosion
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property float CameraShakeIntensity
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float CameraShakeRadius
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float CameraShakeDuration
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float CollisionDamageMultiplier
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool ResetMappers
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			property ::DefinitionClass *InternalDefinitionClassPointer
			{
				::DefinitionClass *get() override;
			}

			property ::ExplosionDefinitionClass *InternalExplosionDefinitionClassPointer
			{
				virtual ::ExplosionDefinitionClass *get();
			}
	};
}