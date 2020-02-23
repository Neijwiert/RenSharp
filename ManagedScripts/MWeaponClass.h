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
#include <WeaponClass.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "IUnmanagedObject.h"
#include "AbstractUnmanagedObject.h"

namespace RenSharp
{

#pragma warning(push)
#pragma warning(disable : 4099 4251 4244 26495 26454)

	interface class IArmedGameObj;
	value class Matrix3D;
	value class Vector3;
	interface class IWeaponDefinitionClass;
	interface class IAmmoDefinitionClass;

#pragma warning(pop)

	public enum class WeaponHoldStyleType : int
	{
		WeaponHoldStyleC4 = ::WEAPON_HOLD_STYLE_C4,
		WeaponHoldStyleNotUsed = ::WEAPON_HOLD_STYLE_NOT_USED,
		WeaponHoldStyleAtShoulder = ::WEAPON_HOLD_STYLE_AT_SHOULDER,
		WeaponHoldStyleAtHip = ::WEAPON_HOLD_STYLE_AT_HIP,
		WeaponHoldStyleLauncher = ::WEAPON_HOLD_STYLE_LAUNCHER,
		WeaponHoldStyleHandgun = ::WEAPON_HOLD_STYLE_HANDGUN,
		WeaponHoldStyleBeacon = ::WEAPON_HOLD_STYLE_BEACON,
		WeaponHoldStyleEmptyHands = ::WEAPON_HOLD_STYLE_EMPTY_HANDS,
		WeaponHoldStyleAtChest = ::WEAPON_HOLD_STYLE_AT_CHEST,
		WeaponHoldStyleHandsDown = ::WEAPON_HOLD_STYLE_HANDS_DOWN
	};

	public enum class WeaponAnimState : int
	{
		WeaponAnimNotFiring = ::WEAPON_ANIM_NOT_FIRING,
		WeaponAnimFiring0 = ::WEAPON_ANIM_FIRING_0,
		WeaponAnimFiring1 = ::WEAPON_ANIM_FIRING_1
	};

	public enum class WeaponModelUpdateState : int
	{
		WeaponModelUpdateWillBeNeeded = ::WEAPON_MODEL_UPDATE_WILL_BE_NEEDED,
		WeaponModelUpdateIsNeeded = ::WEAPON_MODEL_UPDATE_IS_NEEDED,
		WeaponModelUpdateNotNeeded = ::WEAPON_MODEL_UPDATE_NOT_NEEDED
	};

	public interface class IWeaponClass : public IUnmanagedObject
	{
		enum class Muzzle : int
		{
			MuzzlePrimary0 = ::WeaponClass::MUZZLE_PRIMARY_0,
			MuzzlePrimary1 = ::WeaponClass::MUZZLE_PRIMARY_1,
			MuzzleSecondary0 = ::WeaponClass::MUZZLE_SECONDARY_0,
			MuzzleSecondary1 = ::WeaponClass::MUZZLE_SECONDARY_1
		};

		enum class WeaponStateType : int
		{
			StateIdle = ::WeaponClass::STATE_IDLE,
			StateReady = ::WeaponClass::STATE_READY,
			StateCharge = ::WeaponClass::STATE_CHARGE,
			StateFirePrimary = ::WeaponClass::STATE_FIRE_PRIMARY,
			StateFireSecondary = ::WeaponClass::STATE_FIRE_SECONDARY,
			StateReload = ::WeaponClass::STATE_RELOAD,
			StateStartSwitch = ::WeaponClass::STATE_START_SWITCH,
			StateEndSwitch = ::WeaponClass::STATE_END_SWITCH
		};

		void ResetModelUpdate();

		void ResetAnimUpdate();

		void ClearFiringSound();

		void SetDidFire(bool fire);

		property IntPtr WeaponClassPointer
		{
			IntPtr get();
		}

		property IArmedGameObj ^Owner
		{
			IArmedGameObj ^get();
		}

		property IWeaponDefinitionClass ^Definition
		{
			IWeaponDefinitionClass ^get();
		}

		property String ^Name
		{
			String ^get();
		}

		property int ID
		{
			int get();
		}

		property String ^HUDIconTextureName
		{
			String ^get();
		}

		property String ^ModelName
		{
			String ^get();
		}

		property String ^BackModelName
		{
			String ^get();
		}

		property String ^AnimName
		{
			String ^get();
		}

		property String ^FirstPersonAnimName
		{
			String ^get();
		}

		property int Style
		{
			int get();
		}

		property float KeyNumber
		{
			float get();
		}

		property bool CanSnipe
		{
			bool get();
		}

		property float Rating
		{
			float get();
		}

		property float EffectiveRange
		{
			float get();
		}

		property float PrimaryFireRate
		{
			float get();
		}

		property String ^FirstPersonModelName
		{
			String ^get();
		}

		property Vector3 FirstPersonModelOffset
		{
			Vector3 get();
		}

		property float RecoilTime
		{
			float get();
		}

		property float RecoilScale
		{
			float get();
		}

		property int TotalRounds
		{
			int get();
		}

		property int ClipRounds
		{
			int get();
		}

		property int InventoryRounds
		{
			int get();
		}

		property bool IsAmmoMaxed
		{
			bool get();
		}

		property bool IsLoaded
		{
			bool get();
		}

		property float Range
		{
			float get();
		}

		property bool IsModelUpdateNeeded
		{
			bool get();
		}

		property bool IsAnimUpdateNeeded
		{
			bool get();
		}

		property WeaponAnimState AnimState
		{
			WeaponAnimState get();
		}

		property int TotalRoundsFired
		{
			int get();
		}

		property Vector3 Target
		{
			Vector3 get();
			void set(Vector3 value);
		}

		property WeaponStateType State
		{
			WeaponStateType get();
		}

		property bool IsFiring
		{
			bool get();
		}

		property bool IsReloading
		{
			bool get();
		}

		property bool IsSwitching
		{
			bool get();
		}

		property bool SafetySet
		{
			bool get();
			void set(bool value);
		}

		property bool IsTriggered
		{
			bool get();
		}

		property bool WeaponExists
		{
			bool get();
			void set(bool value);
		}

		property float TargetingRange
		{
			float get();
		}

		property bool TiltGunWhileReloading
		{
			bool get();
		}

		property IAmmoDefinitionClass ^PrimaryAmmoDefinition
		{
			IAmmoDefinitionClass ^get();
		}

		property IAmmoDefinitionClass ^SecondaryAmmoDefinition
		{
			IAmmoDefinitionClass ^get();
		}
	};

	public ref class WeaponClass : public AbstractUnmanagedObject, public IWeaponClass
	{
		public:
			WeaponClass(IntPtr pointer);

			String ^ToString() override;
			bool Equals(Object ^other) override;

			virtual void ResetModelUpdate() sealed;
			virtual void ResetAnimUpdate() sealed;
			virtual void ClearFiringSound() sealed;
			virtual void SetDidFire(bool fire) sealed;

			property IntPtr WeaponClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IArmedGameObj ^Owner
			{
				virtual IArmedGameObj ^get();
			}

			property IWeaponDefinitionClass ^Definition
			{
				virtual IWeaponDefinitionClass ^get() sealed;
			}

			property String ^Name
			{
				virtual String ^get() sealed;
			}

			property int ID
			{
				virtual int get() sealed;
			}

			property String ^HUDIconTextureName
			{
				virtual String ^get() sealed;
			}

			property String ^ModelName
			{
				virtual String ^get() sealed;
			}

			property String ^BackModelName
			{
				virtual String ^get() sealed;
			}

			property String ^AnimName
			{
				virtual String ^get() sealed;
			}

			property String ^FirstPersonAnimName
			{
				virtual String ^get() sealed;
			}

			property int Style
			{
				virtual int get() sealed;
			}

			property float KeyNumber
			{
				virtual float get() sealed;
			}

			property bool CanSnipe
			{
				virtual bool get() sealed;
			}

			property float Rating
			{
				virtual float get() sealed;
			}

			property float EffectiveRange
			{
				virtual float get() sealed;
			}

			property float PrimaryFireRate
			{
				virtual float get() sealed;
			}

			property String ^FirstPersonModelName
			{
				virtual String ^get() sealed;
			}

			property Vector3 FirstPersonModelOffset
			{
				virtual Vector3 get() sealed;
			}

			property float RecoilTime
			{
				virtual float get() sealed;
			}

			property float RecoilScale
			{
				virtual float get() sealed;
			}

			property int TotalRounds
			{
				virtual int get() sealed;
			}

			property int ClipRounds
			{
				virtual int get() sealed;
			}

			property int InventoryRounds
			{
				virtual int get() sealed;
			}

			property bool IsAmmoMaxed
			{
				virtual bool get() sealed;
			}

			property bool IsLoaded
			{
				virtual bool get() sealed;
			}

			property float Range
			{
				virtual float get() sealed;
			}

			property bool IsModelUpdateNeeded
			{
				virtual bool get() sealed;
			}

			property bool IsAnimUpdateNeeded
			{
				virtual bool get() sealed;
			}

			property WeaponAnimState AnimState
			{
				virtual WeaponAnimState get() sealed;
			}

			property int TotalRoundsFired
			{
				virtual int get() sealed;
			}

			property Vector3 Target
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

			property IWeaponClass::WeaponStateType State
			{
				virtual IWeaponClass::WeaponStateType get() sealed;
			}

			property bool IsFiring
			{
				virtual bool get() sealed;
			}

			property bool IsReloading
			{
				virtual bool get() sealed;
			}

			property bool IsSwitching
			{
				virtual bool get() sealed;
			}

			property bool SafetySet
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsTriggered
			{
				virtual bool get() sealed;
			}

			property bool WeaponExists
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property float TargetingRange
			{
				virtual float get() sealed;
			}

			property bool TiltGunWhileReloading
			{
				virtual bool get() sealed;
			}

			property IAmmoDefinitionClass ^PrimaryAmmoDefinition
			{
				virtual IAmmoDefinitionClass ^get() sealed;
			}

			property IAmmoDefinitionClass ^SecondaryAmmoDefinition
			{
				virtual IAmmoDefinitionClass ^get() sealed;
			}

		protected:
			property ::WeaponClass *InternalWeaponClassPointer
			{
				virtual ::WeaponClass *get();
			}
	};
}