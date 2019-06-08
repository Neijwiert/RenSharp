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

#include "IUnmanagedObject.h"
#include "AbstractUnmanagedObject.h"
#include "IUnmanagedContainer.h"
#include "MSmartGameObj.h"
#include "MTransitionGameObjDef.h"
#include "Mscripts.h"
#include "MHumanStateClass.h"
#include "MArmorWarheadManager.h"

#pragma managed(push, off)

class SoldierGameObj;
class TransitionCompletionDataStruct;

#pragma managed(pop)

namespace RenSharp
{
	interface class IReferencerClass;
	interface class ISoldierGameObjDef;
	interface class IRenderObjClass;
	interface class IcPlayer;
	interface class IDAPlayerClass;
	interface class IAnimControlClass;
	interface class IDialogueClass;
	interface class IAudibleSoundClass;

	public interface class ITransitionCompletionDataStruct : public IUnmanagedObject
	{
		property IntPtr TransitionCompletionDataStructPointer
		{
			IntPtr get();
		}

		property ITransitionDataClass::StyleType Type
		{
			ITransitionDataClass::StyleType get();
			void set(ITransitionDataClass::StyleType value);
		}

		property IReferencerClass ^Vehicle
		{
			IReferencerClass ^get();
			void set(IReferencerClass ^value);
		}
	};

	public ref class TransitionCompletionDataStruct : public AbstractUnmanagedObject, public ITransitionCompletionDataStruct
	{
		private:
			TransitionCompletionDataStruct();

		public:
			TransitionCompletionDataStruct(IntPtr pointer);

			static IUnmanagedContainer<ITransitionCompletionDataStruct ^> ^CreateTransitionCompletionDataStruct();

			bool Equals(Object ^other) override;

			property IntPtr TransitionCompletionDataStructPointer
			{
				virtual IntPtr get() sealed;
			}

			property ITransitionDataClass::StyleType Type
			{
				virtual ITransitionDataClass::StyleType get() sealed;
				virtual void set(ITransitionDataClass::StyleType value) sealed;
			}

			property IReferencerClass ^Vehicle
			{
				virtual IReferencerClass ^get() sealed;
				virtual void set(IReferencerClass ^value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::TransitionCompletionDataStruct *InternalTransitionCompletionDataStructPointer
			{
				virtual ::TransitionCompletionDataStruct *get();
			}
	};

	public interface class ISoldierGameObj : public ISmartGameObj
	{
		void ReInit(ISoldierGameObjDef ^definition);

		void ApplyDamageIgnoreVehicleCheck(IOffenseObjectClass ^damager, float scale, int alternateSkin);

		void ApplyDamageIgnoreVehicleCheck(IOffenseObjectClass ^damager, float scale);

		void ApplyDamageIgnoreVehicleCheck(IOffenseObjectClass ^damager);

		void SetWeaponModel(String ^modelName);

		void SetWeaponAnimation(String ^animName);

		void StartTransitionAnimation(String ^animName, ITransitionCompletionDataStruct ^completionData);

		void SetBlendedAnimation(String ^animationName, bool looping, float frameOffset, bool playBackwards);

		void SetBlendedAnimation(String ^animationName, bool looping, float frameOffset);

		void SetBlendedAnimation(String ^animationName, bool looping);

		void SetBlendedAnimation(String ^animationName);

		void ToggleFlyMode();

		void LookAt(Vector3 pos, float time);

		void UpdateLookAt(Vector3 pos);

		void CancelLookAt();

		void InnateEnable(int bits);

		void InnateEnable();

		void InnateDisable(int bits);

		void InnateDisable();

		bool IsInnateEnabled(int bits);

		bool IsInnateEnabled();

		void ClearInnateObserver();

		void GiveKey(int keyNumber);

		void RemoveKey(int keyNumber);

		bool HasKey(int keyNumber);

		void SetHumanAnimOverride(bool enableHumanAnimOverride);

		int	GetHumanAnimOverride();

		void SetIsSniping();

		property IntPtr SoldierGameObjPointer
		{
			IntPtr get();
		}

		property ISoldierGameObjDef ^Definition
		{
			ISoldierGameObjDef ^get();
		}

		property bool IsTurreted
		{
			bool get();
		}

		property bool DetonateC4
		{
			bool get();
		}

		property bool IsInElevator
		{
			bool get();
		}

		property bool IsDead
		{
			bool get();
		}

		property bool IsDestroyed
		{
			bool get();
		}

		property bool IsUpright
		{
			bool get();
		}

		property bool IsWounded
		{
			bool get();
		}

		property bool InTransition
		{
			bool get();
		}

		property bool IsAirborne
		{
			bool get();
		}

		property bool IsCrouched
		{
			bool get();
		}

		property bool IsSniping
		{
			bool get();
		}

		property bool IsSlow
		{
			bool get();
		}

		property bool IsOnLadder
		{
			bool get();
		}

		property bool IsInVehicle
		{
			bool get();
		}

		property float MaxSpeed
		{
			float get();
			void set(float value);
		}

		property IVehicleGameObj ^Vehicle
		{
			IVehicleGameObj ^get();
		}

		property String ^AnimationName
		{
			String ^get();
		}

		property IHumanStateClass ^HumanState
		{
			IHumanStateClass ^get();
		}

		property bool IsLooking
		{
			bool get();
		}

		property IntPtr FacialAnim
		{
			IntPtr get();
		}

		property SoldierAIState AIState
		{
			SoldierAIState get();
		}

		property IntPtr InnateObserver
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property int KeyRing
		{
			int get();
		}

		property bool WantsPowerups
		{
			bool get();
		}

		property bool AllowSpecialDamageStateLock
		{
			bool get();
		}

		property bool IsVisible
		{
			bool get();
			void set(bool value);
		}

		property bool IsTargetable
		{
			bool get();
		}

		property bool FlyMode
		{
			bool get();
		}

		property IHumanStateClass::HumanStateType State
		{
			IHumanStateClass::HumanStateType get();
		}

		property IRenderObjClass ^WeaponRenderModel
		{
			IRenderObjClass ^get();
		}

		property bool CanStealVehicles
		{
			bool get();
			void set(bool value);
		}

		property bool CanDriveVehicles
		{
			bool get();
			void set(bool value);
		}

		property bool BlockActionKey
		{
			bool get();
			void set(bool value);
		}

		property bool Freeze
		{
			bool get();
			void set(bool value);
		}

		property bool CanPlayDamageAnimations
		{
			bool get();
			void set(bool value);
		}

		property float NetworkRescale
		{
			float get();
			void set(float value);
		}

		property bool MovementLoitersAllowed
		{
			bool get();
			void set(bool value);
		}

		property bool UseStockGhostBehavior
		{
			bool get();
		}

		property bool OverrideMuzzleDirection
		{
			bool get();
			void set(bool value);
		}

		property int ContactSurfaceType
		{
			int get();
		}

		property float SkeletonHeight
		{
			float get();
			void set(float value);
		}

		property float SkeletonWidth
		{
			float get();
			void set(float value);
		}

		property int OverrideWeaponHoldStyle
		{
			int get();
			void set(int value);
		}

		property IcPlayer ^Player
		{
			IcPlayer ^get();
		}

		property IDAPlayerClass ^DAPlayer
		{
			IDAPlayerClass ^get();
		}
	};

	public ref class SoldierGameObj : public SmartGameObj, public ISoldierGameObj
	{
		public:
			SoldierGameObj(IntPtr pointer);

			ISoldierGameObj ^AsSoldierGameObj() override;

			virtual void ReInit(ISoldierGameObjDef ^definition) sealed;
			virtual void ApplyDamageIgnoreVehicleCheck(IOffenseObjectClass ^damager, float scale, int alternateSkin) sealed;
			virtual void ApplyDamageIgnoreVehicleCheck(IOffenseObjectClass ^damager, float scale) sealed;
			virtual void ApplyDamageIgnoreVehicleCheck(IOffenseObjectClass ^damager) sealed;
			virtual void SetWeaponModel(String ^modelName) sealed;
			virtual void SetWeaponAnimation(String ^animName) sealed;
			virtual void StartTransitionAnimation(String ^animName, ITransitionCompletionDataStruct ^completionData) sealed;
			virtual void SetBlendedAnimation(String ^animationName, bool looping, float frameOffset, bool playBackwards) sealed;
			virtual void SetBlendedAnimation(String ^animationName, bool looping, float frameOffset) sealed;
			virtual void SetBlendedAnimation(String ^animationName, bool looping) sealed;
			virtual void SetBlendedAnimation(String ^animationName) sealed;
			virtual void ToggleFlyMode() sealed;
			virtual void LookAt(Vector3 pos, float time) sealed;
			virtual void UpdateLookAt(Vector3 pos) sealed;
			virtual void CancelLookAt() sealed;
			virtual void InnateEnable(int bits) sealed;
			virtual void InnateEnable() sealed;
			virtual void InnateDisable(int bits) sealed;
			virtual void InnateDisable() sealed;
			virtual bool IsInnateEnabled(int bits) sealed;
			virtual bool IsInnateEnabled() sealed;
			virtual void ClearInnateObserver() sealed;
			virtual void GiveKey(int keyNumber) sealed;
			virtual void RemoveKey(int keyNumber) sealed;
			virtual bool HasKey(int keyNumber) sealed;
			virtual void SetHumanAnimOverride(bool enableHumanAnimOverride) sealed;
			virtual int	GetHumanAnimOverride() sealed;
			virtual void SetIsSniping() sealed;

			property IntPtr SoldierGameObjPointer
			{
				virtual IntPtr get() sealed;
			}

			property ISoldierGameObjDef ^Definition
			{

#pragma push_macro("new")
#undef new

				virtual ISoldierGameObjDef ^get() new sealed;

#pragma pop_macro("new")

			}

			property bool IsTurreted
			{
				virtual bool get() sealed;
			}

			property bool DetonateC4
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

			property bool IsInElevator
			{
				virtual bool get() sealed;
			}

			property bool IsDead
			{
				virtual bool get() sealed;
			}

			property bool IsDestroyed
			{
				virtual bool get() sealed;
			}

			property bool IsUpright
			{
				virtual bool get() sealed;
			}

			property bool IsWounded
			{
				virtual bool get() sealed;
			}

			property bool InTransition
			{
				virtual bool get() sealed;
			}

			property bool IsAirborne
			{
				virtual bool get() sealed;
			}

			property bool IsCrouched
			{
				virtual bool get() sealed;
			}

			property bool IsSniping
			{
				virtual bool get() sealed;
			}

			property bool IsSlow
			{
				virtual bool get() sealed;
			}

			property bool IsOnLadder
			{
				virtual bool get() sealed;
			}

			property bool IsInVehicle
			{
				virtual bool get() sealed;
			}

			property float MaxSpeed
			{
				float get() override sealed;
				virtual void set(float value) sealed;
			}

			property IVehicleGameObj ^Vehicle
			{
				virtual IVehicleGameObj ^get() sealed;

				protected:
					void set(IVehicleGameObj ^value);
			}

			property String ^AnimationName
			{
				virtual String ^get() sealed;

				protected:
					void set(String ^value);
			}

			property IHumanStateClass ^HumanState
			{
				virtual IHumanStateClass ^get() sealed;

				protected:
					void set(IHumanStateClass ^value);
			}

			property bool IsLooking
			{
				virtual bool get() sealed;
			}

			property IntPtr FacialAnim
			{
				virtual IntPtr get() sealed;
			}

			property SoldierAIState AIState
			{
				virtual SoldierAIState get() sealed;

				protected:
					void set(SoldierAIState value);
			}

			property IntPtr InnateObserver
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property int KeyRing
			{
				virtual int get() sealed;

				protected:
					void set(int value);
			}

			property bool WantsPowerups
			{
				virtual bool get() sealed;
			}

			property bool AllowSpecialDamageStateLock
			{
				virtual bool get() sealed;
			}

			property bool IsVisible
			{
				bool get() override sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsTargetable
			{
				virtual bool get() sealed;
			}

			property bool FlyMode
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

			property IHumanStateClass::HumanStateType State
			{
				virtual IHumanStateClass::HumanStateType get() sealed;
			}

			property IRenderObjClass ^WeaponRenderModel
			{
				virtual IRenderObjClass ^get() sealed;

				protected:
					void set(IRenderObjClass ^value);
			}

			property bool CanStealVehicles
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool CanDriveVehicles
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool BlockActionKey
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool Freeze
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool CanPlayDamageAnimations
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property float NetworkRescale
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool MovementLoitersAllowed
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool UseStockGhostBehavior
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

			property bool OverrideMuzzleDirection
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property int ContactSurfaceType
			{
				virtual int get() sealed;
			}

			property float SkeletonHeight
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float SkeletonWidth
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int OverrideWeaponHoldStyle
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property IcPlayer ^Player
			{
				virtual IcPlayer ^get() sealed;
			}

			property IDAPlayerClass ^DAPlayer
			{
				virtual IDAPlayerClass ^get() sealed;
			}

		protected:
			property ::SmartGameObj *InternalSmartGameObjPointer
			{
				::SmartGameObj *get() override;
			}

			property ::SoldierGameObj *InternalSoldierGameObjPointer
			{
				virtual ::SoldierGameObj *get();
			}

			property IRenderObjClass ^BackWeaponRenderModel
			{
				IRenderObjClass ^get();
				void set(IRenderObjClass ^value);
			}

			property IRenderObjClass ^BackFlagRenderModel
			{
				IRenderObjClass ^get();
				void set(IRenderObjClass ^value);
			}

			property IAnimControlClass ^WeaponAnimControl
			{
				IAnimControlClass ^get();
				void set(IAnimControlClass ^value);
			}

			property ITransitionCompletionDataStruct ^TransitionCompletionData
			{
				ITransitionCompletionDataStruct ^get();
				void set(ITransitionCompletionDataStruct ^value);
			}

			property float LegFacing
			{
				float get();
				void set(float value);
			}

			property bool SyncLegs
			{
				bool get();
				void set(bool value);
			}

			property bool LastLegMode
			{
				bool get();
				void set(bool value);
			}

			property bool IsUsingGhostCollision
			{
				bool get();
				void set(bool value);
			}

			property array<IDialogueClass ^> ^DialogList
			{
				array<IDialogueClass ^> ^get();
			}

			property IAudibleSoundClass ^CurrentSpeech
			{
				IAudibleSoundClass ^get();
				void set(IAudibleSoundClass ^value);
			}

			property float HeadLookDuration
			{
				float get();
				void set(float value);
			}

			property Vector3 HeadRotation
			{
				Vector3 get();
				void set(Vector3 value);
			}

			property Vector3 HeadLookTarget
			{
				Vector3 get();
				void set(Vector3 value);
			}

			property Vector3 HeadLookAngle
			{
				Vector3 get();
				void set(Vector3 value);
			}

			property float HeadLookAngleTimer
			{
				float get();
				void set(float value);
			}

			property int SubState
			{
				int get();
			}

			property ArmorWarheadManager::SpecialDamageType SpecialDamageMode
			{
				ArmorWarheadManager::SpecialDamageType get();
				void set(ArmorWarheadManager::SpecialDamageType value);
			}

			property float SpecialDamageTimer
			{
				float get();
				void set(float value);
			}

			property IReferencerClass ^SpecialDamageDamager
			{
				IReferencerClass ^get();
				void set(IReferencerClass ^value);
			}

			property IntPtr SpecialDamageEffect
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property IntPtr HealingEffect
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property IReferencerClass ^FacingObject
			{
				IReferencerClass ^get();
				void set(IReferencerClass ^value);
			}

			property bool FacingAllowBodyTurn
			{
				bool get();
				void set(bool value);
			}

			property int InnateEnableBits
			{
				int get();
				void set(int value);
			}

			property IntPtr SpeechAnim
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property float GenerateIdleFacialAnimTimer
			{
				float get();
				void set(float value);
			}

			property IRenderObjClass ^HeadModel
			{
				IRenderObjClass ^get();
				void set(IRenderObjClass ^value);
			}

			property IRenderObjClass ^EmotIconModel
			{
				IRenderObjClass ^get();
				void set(IRenderObjClass ^value);
			}

			property float EmotIconTimer
			{
				float get();
				void set(float value);
			}

			property bool LadderUpMask
			{
				bool get();
				void set(bool value);
			}

			property bool LadderDownMask
			{
				bool get();
				void set(bool value);
			}

			property float ReloadingTilt
			{
				float get();
				void set(float value);
			}

			property bool WeaponChanged
			{
				bool get();
				void set(bool value);
			}

			property IntPtr WaterWake
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property IDynamicVectorClass<IRenderObjClass ^> ^RenderObjList
			{
				IDynamicVectorClass<IRenderObjClass ^> ^get();
				void set(IDynamicVectorClass<IRenderObjClass ^> ^value);
			}

			property int HeadBone
			{
				int get();
				void set(int value);
			}

			property int NeckBone
			{
				int get();
				void set(int value);
			}

			property float LastScale
			{
				float get();
				void set(float value);
			}

			property float LastSkeletonHeight
			{
				float get();
				void set(float value);
			}

			property float LastSkeletonWidth
			{
				float get();
				void set(float value);
			}
	};
}