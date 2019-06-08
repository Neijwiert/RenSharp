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

#include "stdafx.h"
#include "MSoldierGameObj.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <SoldierGameObj.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "Imports.h"
#include "UnmanagedContainer.h"
#include "MReferencerClass.h"
#include "MSoldierGameObjDef.h"
#include "MRenderObjClass.h"
#include "McPlayer.h"
#include "Mda_player.h"
#include "MAnimControlClass.h"
#include "MDialogueClass.h"
#include "MAudibleSoundClass.h"
#include "MRenderObjClassPtrDynamicVectorClass.h"
#include "MOffenseObjectClass.h"
#include "MVehicleGameObj.h"

namespace RenSharp
{

#pragma managed(push, off)

	class SoldierGameObjHelper : public ::SoldierGameObj
	{
		private:
			SoldierGameObjHelper() = default;

		public:
			int GetSubState()
			{
				return Get_Sub_State();
			}

			::RenderObjClass *&GetWeaponRenderModel()
			{
				return WeaponRenderModel;
			}

			::RenderObjClass *&GetBackWeaponRenderModel()
			{
				return BackWeaponRenderModel;
			}

			::RenderObjClass *&GetBackFlagRenderModel()
			{
				return BackFlagRenderModel;
			}

			::AnimControlClass *&GetWeaponAnimControl()
			{
				return WeaponAnimControl;
			}

			bool &GetDetonateC4()
			{
				return DetonateC4;
			}

			::TransitionCompletionDataStruct *&GetTransitionCompletionData()
			{
				return TransitionCompletionData;
			}

			::StringClass &GetAnimationName()
			{
				return AnimationName;
			}

			::VehicleGameObj *&GetVehicle()
			{
				return Vehicle;
			}

			::HumanStateClass &GetHumanState()
			{
				return HumanState;
			}

			float &GetLegFacing()
			{
				return LegFacing;
			}

			bool &GetSyncLegs()
			{
				return SyncLegs;
			}

			bool &GetLastLegMode()
			{
				return LastLegMode;
			}

			int &GetKeyRing()
			{
				return KeyRing;
			}

			bool &GetIsUsingGhostCollision()
			{
				return IsUsingGhostCollision;
			}

			::DialogueClass *GetDialogList()
			{
				return DialogList;
			}

			::AudibleSoundClass *&GetCurrentSpeech()
			{
				return CurrentSpeech;
			}

			float &GetHeadLookDuration()
			{
				return HeadLookDuration;
			}

			::Vector3 &GetHeadRotation()
			{
				return HeadRotation;
			}

			::Vector3 &GetHeadLookTarget()
			{
				return HeadLookTarget;
			}

			::Vector3 &GetHeadLookAngle()
			{
				return HeadLookAngle;
			}

			float &GetHeadLookAngleTimer()
			{
				return HeadLookAngleTimer;
			}

			::ArmorWarheadManager::SpecialDamageType &GetSpecialDamageMode()
			{
				return SpecialDamageMode;
			}

			float &GetSpecialDamageTimer()
			{
				return SpecialDamageTimer;
			}

			::ReferencerClass &GetSpecialDamageDamager()
			{
				return SpecialDamageDamager;
			}

			::TransitionEffectClass *&GetSpecialDamageEffect()
			{
				return SpecialDamageEffect;
			}

			::TransitionEffectClass *&GetHealingEffect()
			{
				return HealingEffect;
			}

			::ReferencerClass &GetFacingObject()
			{
				return FacingObject;
			}

			bool &GetFacingAllowBodyTurn()
			{
				return FacingAllowBodyTurn;
			}

			int &GetInnateEnableBits()
			{
				return InnateEnableBits;
			}

			::SoldierObserverClass *&GetInnateObserver()
			{
				return InnateObserver;
			}

			::SoldierAIState &GetAIState()
			{
				return AIState;
			}

			::DynamicSpeechAnimClass *&GetSpeechAnim()
			{
				return SpeechAnim;
			}

			float &GetGenerateIdleFacialAnimTimer()
			{
				return GenerateIdleFacialAnimTimer;
			}

			::RenderObjClass *&GetHeadModel()
			{
				return HeadModel;
			}

			::RenderObjClass *&GetEmotIconModel()
			{
				return EmotIconModel;
			}

			float &GetEmotIconTimer()
			{
				return EmotIconTimer;
			}

			bool &GetInFlyMode()
			{
				return InFlyMode;
			}

			bool &GetIsVisible()
			{
				return IsVisible;
			}

			bool &GetLadderUpMask()
			{
				return LadderUpMask;
			}

			bool &GetLadderDownMask()
			{
				return LadderDownMask;
			}

			float &GetReloadingTilt()
			{
				return ReloadingTilt;
			}

			bool &GetWeaponChanged()
			{
				return WeaponChanged;
			}

			bool &GetCanStealVehicles()
			{
				return CanStealVehicles;
			}

			bool &GetCanDriveVehicles()
			{
				return CanDriveVehicles;
			}

			::PersistantSurfaceEmitterClass *&GetWaterWake()
			{
				return WaterWake;
			}

			::DynamicVectorClass<::RenderObjClass*> &GetRenderObjList()
			{
				return RenderObjList;
			}

			bool &GetBlockActionKey()
			{
				return BlockActionKey;
			}

			bool &GetFreeze()
			{
				return Freeze;
			}

			int &GetHeadBone()
			{
				return head_bone;
			}

			int &GetNeckBone()
			{
				return neck_bone;
			}

			bool &GetCanPlayDamageAnimations()
			{
				return CanPlayDamageAnimations;
			}

			float &GetNetworkRescale()
			{
				return NetworkRescale;
			}

			float &GetLastScale()
			{
				return LastScale;
			}

			bool &GetMovementLoitersAllowed()
			{
				return movementLoitersAllowed;
			}

			bool &GetUseStockGhostBehavior()
			{
				return useStockGhostBehavior;
			}

			bool &GetOverrideMuzzleDirection()
			{
				return OverrideMuzzleDirection;
			}

			float &GetSkeletonHeight()
			{
				return skeletonHeight;
			}

			float &GetSkeletonWidth()
			{
				return skeletonWidth;
			}

			float &GetLastSkeletonHeight()
			{
				return lastSkeletonHeight;
			}

			float &GetLastSkeletonWidth()
			{
				return lastSkeletonWidth;
			}

			int &GetOverrideWeaponHoldStyleId()
			{
				return overrideWeaponHoldStyleId;
			}

			bool &GetEnableHumanAnimOverride()
			{
				return enableHumanAnimOverride;
			}
	};

#pragma managed(pop)

	TransitionCompletionDataStruct::TransitionCompletionDataStruct()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateTransitionCompletionDataStruct()))
	{

	}

	TransitionCompletionDataStruct::TransitionCompletionDataStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<ITransitionCompletionDataStruct ^> ^TransitionCompletionDataStruct::CreateTransitionCompletionDataStruct()
	{
		return gcnew UnmanagedContainer<ITransitionCompletionDataStruct ^>(gcnew TransitionCompletionDataStruct());
	}

	bool TransitionCompletionDataStruct::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		ITransitionCompletionDataStruct ^otherThis = dynamic_cast<ITransitionCompletionDataStruct ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return TransitionCompletionDataStructPointer.Equals(otherThis->TransitionCompletionDataStructPointer);
	}

	IntPtr TransitionCompletionDataStruct::TransitionCompletionDataStructPointer::get()
	{
		return IntPtr(InternalTransitionCompletionDataStructPointer);
	}

	ITransitionDataClass::StyleType TransitionCompletionDataStruct::Type::get()
	{
		return static_cast<ITransitionDataClass::StyleType>(InternalTransitionCompletionDataStructPointer->Type);
	}

	void TransitionCompletionDataStruct::Type::set(ITransitionDataClass::StyleType value)
	{
		InternalTransitionCompletionDataStructPointer->Type = static_cast<::TransitionDataClass::StyleType>(value);
	}

	IReferencerClass ^TransitionCompletionDataStruct::Vehicle::get()
	{
		return gcnew ReferencerClass(IntPtr(&InternalTransitionCompletionDataStructPointer->Vehicle));
	}

	void TransitionCompletionDataStruct::Vehicle::set(IReferencerClass ^value)
	{
		if (value == nullptr || value->ReferencerClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalTransitionCompletionDataStructPointer->Vehicle = *reinterpret_cast<::ReferencerClass *>(value->ReferencerClassPointer.ToPointer());
	}

	bool TransitionCompletionDataStruct::InternalDestroyPointer()
	{
		Imports::DestroyTransitionCompletionDataStruct(InternalTransitionCompletionDataStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::TransitionCompletionDataStruct *TransitionCompletionDataStruct::InternalTransitionCompletionDataStructPointer::get()
	{
		return reinterpret_cast<::TransitionCompletionDataStruct *>(Pointer.ToPointer());
	}

	SoldierGameObj::SoldierGameObj(IntPtr pointer)
		: SmartGameObj(pointer)
	{

	}

	ISoldierGameObj ^SoldierGameObj::AsSoldierGameObj()
	{
		return this;
	}

	void SoldierGameObj::ReInit(ISoldierGameObjDef ^definition)
	{
		if (definition == nullptr || definition->SoldierGameObjDefPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("definition");
		}

		InternalSoldierGameObjPointer->Re_Init(*reinterpret_cast<::SoldierGameObjDef *>(definition->SoldierGameObjDefPointer.ToPointer()));
	}

	void SoldierGameObj::ApplyDamageIgnoreVehicleCheck(IOffenseObjectClass ^damager, float scale, int alternateSkin)
	{
		if (damager == nullptr || damager->OffenseObjectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("damager");
		}

		InternalSoldierGameObjPointer->Apply_Damage_IgnoreVehicleCheck(
			*reinterpret_cast<::OffenseObjectClass *>(damager->OffenseObjectClassPointer.ToPointer()),
			scale,
			alternateSkin);
	}

	void SoldierGameObj::ApplyDamageIgnoreVehicleCheck(IOffenseObjectClass ^damager, float scale)
	{
		if (damager == nullptr || damager->OffenseObjectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("damager");
		}

		InternalSoldierGameObjPointer->Apply_Damage_IgnoreVehicleCheck(
			*reinterpret_cast<::OffenseObjectClass *>(damager->OffenseObjectClassPointer.ToPointer()),
			scale);
	}

	void SoldierGameObj::ApplyDamageIgnoreVehicleCheck(IOffenseObjectClass ^damager)
	{
		if (damager == nullptr || damager->OffenseObjectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("damager");
		}

		InternalSoldierGameObjPointer->Apply_Damage_IgnoreVehicleCheck(
			*reinterpret_cast<::OffenseObjectClass *>(damager->OffenseObjectClassPointer.ToPointer()));
	}

	void SoldierGameObj::SetWeaponModel(String ^modelName)
	{
		if (modelName == nullptr)
		{
			InternalSoldierGameObjPointer->Set_Weapon_Model(nullptr);
		}
		else
		{
			IntPtr modelNameHandle = Marshal::StringToHGlobalAnsi(modelName);
			try
			{
				InternalSoldierGameObjPointer->Set_Weapon_Model(reinterpret_cast<char *>(modelNameHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(modelNameHandle);
			}
		}
	}

	void SoldierGameObj::SetWeaponAnimation(String ^animName)
	{
		if (animName == nullptr)
		{
			InternalSoldierGameObjPointer->Set_Weapon_Animation(nullptr);
		}
		else
		{
			IntPtr animNameHandle = Marshal::StringToHGlobalAnsi(animName);
			try
			{
				InternalSoldierGameObjPointer->Set_Weapon_Animation(reinterpret_cast<char *>(animNameHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(animNameHandle);
			}
		}
	}

	void SoldierGameObj::StartTransitionAnimation(String ^animName, ITransitionCompletionDataStruct ^completionData)
	{
		if (animName == nullptr)
		{
			throw gcnew ArgumentNullException("animName");
		}

		IntPtr animNameHandle = Marshal::StringToHGlobalAnsi(animName);
		try
		{
			if (completionData == nullptr || completionData->TransitionCompletionDataStructPointer.ToPointer() == nullptr)
			{
				InternalSoldierGameObjPointer->Start_Transition_Animation(
					reinterpret_cast<char *>(animNameHandle.ToPointer()),
					reinterpret_cast<::TransitionCompletionDataStruct *>(completionData->TransitionCompletionDataStructPointer.ToPointer()));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(animNameHandle);
		}
	}

	void SoldierGameObj::SetBlendedAnimation(String ^animationName, bool looping, float frameOffset, bool playBackwards)
	{
		if (animationName == nullptr)
		{
			InternalSoldierGameObjPointer->Set_Blended_Animation(nullptr, looping, frameOffset, playBackwards);
		}
		else
		{
			IntPtr animationNameHandle = Marshal::StringToHGlobalAnsi(animationName);
			try
			{
				InternalSoldierGameObjPointer->Set_Blended_Animation(
					reinterpret_cast<char *>(animationNameHandle.ToPointer()),
					looping,
					frameOffset,
					playBackwards);
			}
			finally
			{
				Marshal::FreeHGlobal(animationNameHandle);
			}
		}
	}

	void SoldierGameObj::SetBlendedAnimation(String ^animationName, bool looping, float frameOffset)
	{
		if (animationName == nullptr)
		{
			InternalSoldierGameObjPointer->Set_Blended_Animation(nullptr, looping, frameOffset);
		}
		else
		{
			IntPtr animationNameHandle = Marshal::StringToHGlobalAnsi(animationName);
			try
			{
				InternalSoldierGameObjPointer->Set_Blended_Animation(
					reinterpret_cast<char *>(animationNameHandle.ToPointer()),
					looping,
					frameOffset);
			}
			finally
			{
				Marshal::FreeHGlobal(animationNameHandle);
			}
		}
	}

	void SoldierGameObj::SetBlendedAnimation(String ^animationName, bool looping)
	{
		if (animationName == nullptr)
		{
			InternalSoldierGameObjPointer->Set_Blended_Animation(nullptr, looping);
		}
		else
		{
			IntPtr animationNameHandle = Marshal::StringToHGlobalAnsi(animationName);
			try
			{
				InternalSoldierGameObjPointer->Set_Blended_Animation(
					reinterpret_cast<char *>(animationNameHandle.ToPointer()),
					looping);
			}
			finally
			{
				Marshal::FreeHGlobal(animationNameHandle);
			}
		}
	}

	void SoldierGameObj::SetBlendedAnimation(String ^animationName)
	{
		if (animationName == nullptr)
		{
			InternalSoldierGameObjPointer->Set_Blended_Animation(nullptr);
		}
		else
		{
			IntPtr animationNameHandle = Marshal::StringToHGlobalAnsi(animationName);
			try
			{
				InternalSoldierGameObjPointer->Set_Blended_Animation(
					reinterpret_cast<char *>(animationNameHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(animationNameHandle);
			}
		}
	}

	void SoldierGameObj::ToggleFlyMode()
	{
		InternalSoldierGameObjPointer->Toggle_Fly_Mode();
	}

	void SoldierGameObj::LookAt(Vector3 pos, float time)
	{
		::Vector3 posVec;

		Vector3::ManagedToUnmanagedVector3(pos, posVec);

		InternalSoldierGameObjPointer->Look_At(posVec, time);
	}

	void SoldierGameObj::UpdateLookAt(Vector3 pos)
	{
		::Vector3 posVec;

		Vector3::ManagedToUnmanagedVector3(pos, posVec);

		InternalSoldierGameObjPointer->Update_Look_At(posVec);
	}

	void SoldierGameObj::CancelLookAt()
	{
		InternalSoldierGameObjPointer->Cancel_Look_At();
	}

	void SoldierGameObj::InnateEnable(int bits)
	{
		InternalSoldierGameObjPointer->Innate_Enable(bits);
	}

	void SoldierGameObj::InnateEnable()
	{
		InternalSoldierGameObjPointer->Innate_Enable();
	}

	void SoldierGameObj::InnateDisable(int bits)
	{
		InternalSoldierGameObjPointer->Innate_Disable(bits);
	}

	void SoldierGameObj::InnateDisable()
	{
		InternalSoldierGameObjPointer->Innate_Disable();
	}

	bool SoldierGameObj::IsInnateEnabled(int bits)
	{
		return InternalSoldierGameObjPointer->Is_Innate_Enabled(bits);
	}

	bool SoldierGameObj::IsInnateEnabled()
	{
		return InternalSoldierGameObjPointer->Is_Innate_Enabled();
	}

	void SoldierGameObj::ClearInnateObserver()
	{
		InternalSoldierGameObjPointer->Clear_Innate_Observer();
	}

	void SoldierGameObj::GiveKey(int keyNumber)
	{
		InternalSoldierGameObjPointer->Give_Key(keyNumber);
	}

	void SoldierGameObj::RemoveKey(int keyNumber)
	{
		InternalSoldierGameObjPointer->Remove_Key(keyNumber);
	}

	bool SoldierGameObj::HasKey(int keyNumber)
	{
		return InternalSoldierGameObjPointer->Has_Key(keyNumber);
	}

	void SoldierGameObj::SetHumanAnimOverride(bool enableHumanAnimOverride)
	{
		InternalSoldierGameObjPointer->Set_Human_Anim_Override(enableHumanAnimOverride);
	}

	int	SoldierGameObj::GetHumanAnimOverride()
	{
		return InternalSoldierGameObjPointer->Get_Human_Anim_Override();
	}

	void SoldierGameObj::SetIsSniping()
	{
		InternalSoldierGameObjPointer->Set_Is_Sniping();
	}

	IntPtr SoldierGameObj::SoldierGameObjPointer::get()
	{
		return IntPtr(InternalSoldierGameObjPointer);
	}

	ISoldierGameObjDef ^SoldierGameObj::Definition::get()
	{
		return gcnew SoldierGameObjDef(IntPtr(const_cast<::SoldierGameObjDef *>(&InternalSoldierGameObjPointer->Get_Definition())));
	}

	bool SoldierGameObj::IsTurreted::get()
	{
		return InternalSoldierGameObjPointer->Is_Turreted();
	}

	bool SoldierGameObj::DetonateC4::get()
	{
		return InternalSoldierGameObjPointer->Detonate_C4();
	}

	void SoldierGameObj::DetonateC4::set(bool value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &detonateC4 = helper->GetDetonateC4();

		detonateC4 = value;
	}

	bool SoldierGameObj::IsInElevator::get()
	{
		return InternalSoldierGameObjPointer->Is_In_Elevator();
	}

	bool SoldierGameObj::IsDead::get()
	{
		return InternalSoldierGameObjPointer->Is_Dead();
	}

	bool SoldierGameObj::IsDestroyed::get()
	{
		return InternalSoldierGameObjPointer->Is_Destroyed();
	}

	bool SoldierGameObj::IsUpright::get()
	{
		return InternalSoldierGameObjPointer->Is_Upright();
	}

	bool SoldierGameObj::IsWounded::get()
	{
		return InternalSoldierGameObjPointer->Is_Wounded();
	}

	bool SoldierGameObj::InTransition::get()
	{
		return InternalSoldierGameObjPointer->In_Transition();
	}

	bool SoldierGameObj::IsAirborne::get()
	{
		return InternalSoldierGameObjPointer->Is_Airborne();
	}

	bool SoldierGameObj::IsCrouched::get()
	{
		return InternalSoldierGameObjPointer->Is_Crouched();
	}

	bool SoldierGameObj::IsSniping::get()
	{
		return InternalSoldierGameObjPointer->Is_Sniping();
	}

	bool SoldierGameObj::IsSlow::get()
	{
		return InternalSoldierGameObjPointer->Is_Slow();
	}

	bool SoldierGameObj::IsOnLadder::get()
	{
		return InternalSoldierGameObjPointer->Is_On_Ladder();
	}

	bool SoldierGameObj::IsInVehicle::get()
	{
		return InternalSoldierGameObjPointer->Is_In_Vehicle();
	}

	float SoldierGameObj::MaxSpeed::get()
	{
		return InternalSoldierGameObjPointer->Get_Max_Speed();
	}

	void SoldierGameObj::MaxSpeed::set(float value)
	{
		InternalSoldierGameObjPointer->Set_Max_Speed(value);
	}

	IVehicleGameObj ^SoldierGameObj::Vehicle::get()
	{
		auto result = InternalSoldierGameObjPointer->Get_Vehicle();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew VehicleGameObj(IntPtr(result));
		}
	}

	void SoldierGameObj::Vehicle::set(IVehicleGameObj ^value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &vehicle = helper->GetVehicle();

		if (value == nullptr || value->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			vehicle = nullptr;
		}
		else
		{
			vehicle = reinterpret_cast<::VehicleGameObj *>(value->VehicleGameObjPointer.ToPointer());
		}
	}

	String ^SoldierGameObj::AnimationName::get()
	{
		return gcnew String(InternalSoldierGameObjPointer->Get_Animation_Name().Peek_Buffer());
	}

	void SoldierGameObj::AnimationName::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &animationName = helper->GetAnimationName();

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			animationName = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	IHumanStateClass ^SoldierGameObj::HumanState::get()
	{
		auto result = InternalSoldierGameObjPointer->Get_Human_State();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew HumanStateClass(IntPtr(result));
		}
	}

	void SoldierGameObj::HumanState::set(IHumanStateClass ^value)
	{
		if (value == nullptr || value->HumanStateClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &humanState = helper->GetHumanState();

		humanState = *reinterpret_cast<::HumanStateClass *>(value->HumanStateClassPointer.ToPointer());
	}

	bool SoldierGameObj::IsLooking::get()
	{
		return InternalSoldierGameObjPointer->Is_Looking();
	}

	IntPtr SoldierGameObj::FacialAnim::get()
	{
		return IntPtr(InternalSoldierGameObjPointer->Get_Facial_Anim());
	}

	SoldierAIState SoldierGameObj::AIState::get()
	{
		return static_cast<SoldierAIState>(InternalSoldierGameObjPointer->Get_AI_State());
	}

	void SoldierGameObj::AIState::set(SoldierAIState value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &aiState = helper->GetAIState();

		aiState = static_cast<::SoldierAIState>(value);
	}

	IntPtr SoldierGameObj::InnateObserver::get()
	{
		return IntPtr(InternalSoldierGameObjPointer->Get_Innate_Observer());
	}

	void SoldierGameObj::InnateObserver::set(IntPtr value)
	{
		if (value.ToPointer() == nullptr)
		{
			InternalSoldierGameObjPointer->Set_Innate_Observer(nullptr);
		}
		else
		{
			InternalSoldierGameObjPointer->Set_Innate_Observer(reinterpret_cast<::SoldierObserverClass *>(value.ToPointer()));
		}
	}

	int SoldierGameObj::KeyRing::get()
	{
		return InternalSoldierGameObjPointer->Get_Key_Ring();
	}

	void SoldierGameObj::KeyRing::set(int value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &keyRing = helper->GetKeyRing();

		keyRing = value;
	}

	bool SoldierGameObj::WantsPowerups::get()
	{
		return InternalSoldierGameObjPointer->Wants_Powerups();
	}

	bool SoldierGameObj::AllowSpecialDamageStateLock::get()
	{
		return InternalSoldierGameObjPointer->Allow_Special_Damage_State_Lock();
	}

	bool SoldierGameObj::IsVisible::get()
	{
		return InternalSoldierGameObjPointer->Is_Visible();
	}

	void SoldierGameObj::IsVisible::set(bool value)
	{
		InternalSoldierGameObjPointer->Set_Is_Visible(value);
	}

	bool SoldierGameObj::IsTargetable::get()
	{
		return InternalSoldierGameObjPointer->Is_Targetable();
	}

	bool SoldierGameObj::FlyMode::get()
	{
		return InternalSoldierGameObjPointer->Get_Fly_Mode();
	}

	void SoldierGameObj::FlyMode::set(bool value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &flyMode = helper->GetInFlyMode();

		flyMode = value;
	}

	IHumanStateClass::HumanStateType SoldierGameObj::State::get()
	{
		return static_cast<IHumanStateClass::HumanStateType>(InternalSoldierGameObjPointer->Get_State());
	}

	IRenderObjClass ^SoldierGameObj::WeaponRenderModel::get()
	{
		auto result = InternalSoldierGameObjPointer->Get_Weapon_Render_Model();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(result));
		}
	}

	void SoldierGameObj::WeaponRenderModel::set(IRenderObjClass ^value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &weaponRenderModel = helper->GetWeaponRenderModel();

		if (value == nullptr || value->RenderObjClassPointer.ToPointer() == nullptr)
		{
			weaponRenderModel = nullptr;
		}
		else
		{
			weaponRenderModel = reinterpret_cast<::RenderObjClass *>(value->RenderObjClassPointer.ToPointer());
		}
	}

	bool SoldierGameObj::CanStealVehicles::get()
	{
		return InternalSoldierGameObjPointer->Can_Steal_Vehicles();
	}

	void SoldierGameObj::CanStealVehicles::set(bool value)
	{
		InternalSoldierGameObjPointer->Set_Can_Steal_Vehicles(value);
	}

	bool SoldierGameObj::CanDriveVehicles::get()
	{
		return InternalSoldierGameObjPointer->Can_Drive_Vehicles();
	}

	void SoldierGameObj::CanDriveVehicles::set(bool value)
	{
		InternalSoldierGameObjPointer->Set_Can_Drive_Vehicles(value);
	}

	bool SoldierGameObj::BlockActionKey::get()
	{
		return InternalSoldierGameObjPointer->Block_Action_Key();
	}

	void SoldierGameObj::BlockActionKey::set(bool value)
	{
		InternalSoldierGameObjPointer->Set_Block_Action_Key(value);
	}

	bool SoldierGameObj::Freeze::get()
	{
		return InternalSoldierGameObjPointer->Is_Frozen();
	}

	void SoldierGameObj::Freeze::set(bool value)
	{
		InternalSoldierGameObjPointer->Set_Freeze(value);
	}

	bool SoldierGameObj::CanPlayDamageAnimations::get()
	{
		return InternalSoldierGameObjPointer->Can_Play_Damage_Animations();
	}

	void SoldierGameObj::CanPlayDamageAnimations::set(bool value)
	{
		InternalSoldierGameObjPointer->Set_Can_Play_Damage_Animations(value);
	}

	float SoldierGameObj::NetworkRescale::get()
	{
		return InternalSoldierGameObjPointer->Get_Scale_Across_Network();
	}

	void SoldierGameObj::NetworkRescale::set(float value)
	{
		InternalSoldierGameObjPointer->Set_Scale_Across_Network(value);
	}

	bool SoldierGameObj::MovementLoitersAllowed::get()
	{
		return InternalSoldierGameObjPointer->Get_Movement_Loiter_Allowed();
	}

	void SoldierGameObj::MovementLoitersAllowed::set(bool value)
	{
		InternalSoldierGameObjPointer->Set_Movement_Loiters_Allowed(value);
	}

	bool SoldierGameObj::UseStockGhostBehavior::get()
	{
		return InternalSoldierGameObjPointer->Get_Use_Stock_Ghost_Behavior();
	}

	void SoldierGameObj::UseStockGhostBehavior::set(bool value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &useStockGhostBehavior = helper->GetUseStockGhostBehavior();

		useStockGhostBehavior = value;
	}

	bool SoldierGameObj::OverrideMuzzleDirection::get()
	{
		return InternalSoldierGameObjPointer->Get_Override_Muzzle_Direction();
	}

	void SoldierGameObj::OverrideMuzzleDirection::set(bool value)
	{
		InternalSoldierGameObjPointer->Set_Override_Muzzle_Direction(value);
	}

	int SoldierGameObj::ContactSurfaceType::get()
	{
		return InternalSoldierGameObjPointer->Get_Contact_Surface_Type();
	}

	float SoldierGameObj::SkeletonHeight::get()
	{
		return InternalSoldierGameObjPointer->Get_Skeleton_Heigth();
	}

	void SoldierGameObj::SkeletonHeight::set(float value)
	{
		return InternalSoldierGameObjPointer->Set_Skeleton_Height(value);
	}

	float SoldierGameObj::SkeletonWidth::get()
	{
		return InternalSoldierGameObjPointer->Get_Skeleton_Width();
	}

	void SoldierGameObj::SkeletonWidth::set(float value)
	{
		InternalSoldierGameObjPointer->Set_Skeleton_Width(value);
	}

	int SoldierGameObj::OverrideWeaponHoldStyle::get()
	{
		return InternalSoldierGameObjPointer->Get_Override_Weapon_Hold_Style();
	}

	void SoldierGameObj::OverrideWeaponHoldStyle::set(int value)
	{
		InternalSoldierGameObjPointer->Set_Override_Weapon_Hold_Style(value);
	}

	IcPlayer ^SoldierGameObj::Player::get()
	{
		auto result = InternalSoldierGameObjPointer->Get_Player();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	IDAPlayerClass ^SoldierGameObj::DAPlayer::get()
	{
		auto result = InternalSoldierGameObjPointer->Get_DA_Player();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAPlayerClass(IntPtr(result));
		}
	}

	::SmartGameObj *SoldierGameObj::InternalSmartGameObjPointer::get()
	{
		return InternalSoldierGameObjPointer;
	}

	::SoldierGameObj *SoldierGameObj::InternalSoldierGameObjPointer::get()
	{
		return reinterpret_cast<::SoldierGameObj *>(Pointer.ToPointer());
	}

	IRenderObjClass ^SoldierGameObj::BackWeaponRenderModel::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &backWeaponRenderModel = helper->GetBackWeaponRenderModel();

		if (backWeaponRenderModel == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(backWeaponRenderModel));
		}
	}

	void SoldierGameObj::BackWeaponRenderModel::set(IRenderObjClass ^value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &backWeaponRenderModel = helper->GetBackWeaponRenderModel();

		if (value == nullptr || value->RenderObjClassPointer.ToPointer() == nullptr)
		{
			backWeaponRenderModel = nullptr;
		}
		else
		{
			backWeaponRenderModel = reinterpret_cast<::RenderObjClass *>(value->RenderObjClassPointer.ToPointer());
		}
	}

	IRenderObjClass ^SoldierGameObj::BackFlagRenderModel::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &backFlagRenderModel = helper->GetBackFlagRenderModel();

		if (backFlagRenderModel == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(backFlagRenderModel));
		}
	}

	void SoldierGameObj::BackFlagRenderModel::set(IRenderObjClass ^value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &backFlagRenderModel = helper->GetBackFlagRenderModel();

		if (value == nullptr || value->RenderObjClassPointer.ToPointer() == nullptr)
		{
			backFlagRenderModel = nullptr;
		}
		else
		{
			backFlagRenderModel = reinterpret_cast<::RenderObjClass *>(value->RenderObjClassPointer.ToPointer());
		}
	}

	IAnimControlClass ^SoldierGameObj::WeaponAnimControl::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &weaponAnimControl = helper->GetWeaponAnimControl();

		if (weaponAnimControl == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew AnimControlClass(IntPtr(weaponAnimControl));
		}
	}

	void SoldierGameObj::WeaponAnimControl::set(IAnimControlClass ^value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &weaponAnimControl = helper->GetWeaponAnimControl();

		if (value == nullptr || value->AnimControlClassPointer.ToPointer() == nullptr)
		{
			weaponAnimControl = nullptr;
		}
		else
		{
			weaponAnimControl = reinterpret_cast<::AnimControlClass *>(value->AnimControlClassPointer.ToPointer());
		}
	}

	ITransitionCompletionDataStruct ^SoldierGameObj::TransitionCompletionData::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &transitionCompletionData = helper->GetTransitionCompletionData();

		if (transitionCompletionData == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew TransitionCompletionDataStruct(IntPtr(transitionCompletionData));
		}
	}

	void SoldierGameObj::TransitionCompletionData::set(ITransitionCompletionDataStruct ^value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &transitionCompletionData = helper->GetTransitionCompletionData();

		if (value == nullptr || value->TransitionCompletionDataStructPointer.ToPointer() == nullptr)
		{
			transitionCompletionData = nullptr;
		}
		else
		{
			transitionCompletionData = reinterpret_cast<::TransitionCompletionDataStruct *>(value->TransitionCompletionDataStructPointer.ToPointer());
		}
	}

	float SoldierGameObj::LegFacing::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &legFacing = helper->GetLegFacing();

		return legFacing;
	}

	void SoldierGameObj::LegFacing::set(float value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &legFacing = helper->GetLegFacing();

		legFacing = value;
	}

	bool SoldierGameObj::SyncLegs::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &syncLegs = helper->GetSyncLegs();

		return syncLegs;
	}

	void SoldierGameObj::SyncLegs::set(bool value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &syncLegs = helper->GetSyncLegs();

		syncLegs = value;
	}

	bool SoldierGameObj::LastLegMode::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &lastLegMode = helper->GetLastLegMode();

		return lastLegMode;
	}

	void SoldierGameObj::LastLegMode::set(bool value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &lastLegMode = helper->GetLastLegMode();

		lastLegMode = value;
	}

	bool SoldierGameObj::IsUsingGhostCollision::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &isUsingGhostCollision = helper->GetIsUsingGhostCollision();

		return isUsingGhostCollision;
	}

	void SoldierGameObj::IsUsingGhostCollision::set(bool value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &isUsingGhostCollision = helper->GetIsUsingGhostCollision();

		isUsingGhostCollision = value;
	}

	array<IDialogueClass ^> ^SoldierGameObj::DialogList::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto *dialogList = helper->GetDialogList();

		array<IDialogueClass ^> ^result = gcnew array<IDialogueClass ^>(::DialogueTypes::DIALOG_MAX);
		for (int x = 0; x < result->Length; x++)
		{
			result[x] = gcnew DialogueClass(IntPtr(&(dialogList[x])));
		}

		return result;
	}

	IAudibleSoundClass ^SoldierGameObj::CurrentSpeech::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &currentSpeech = helper->GetCurrentSpeech();

		if (currentSpeech == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew AudibleSoundClass(IntPtr(helper));
		}
	}

	void SoldierGameObj::CurrentSpeech::set(IAudibleSoundClass ^value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &currentSpeech = helper->GetCurrentSpeech();

		if (value == nullptr || value->AudibleSoundClassPointer.ToPointer() == nullptr)
		{
			currentSpeech = nullptr;
		}
		else
		{
			currentSpeech = reinterpret_cast<::AudibleSoundClass *>(value->AudibleSoundClassPointer.ToPointer());
		}
	}

	float SoldierGameObj::HeadLookDuration::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &headLookDuration = helper->GetHeadLookDuration();

		return headLookDuration;
	}

	void SoldierGameObj::HeadLookDuration::set(float value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &headLookDuration = helper->GetHeadLookDuration();

		headLookDuration = value;
	}

	Vector3 SoldierGameObj::HeadRotation::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &headRotation = helper->GetHeadRotation();

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(headRotation, result);

		return result;
	}

	void SoldierGameObj::HeadRotation::set(Vector3 value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &headRotation = helper->GetHeadRotation();

		Vector3::ManagedToUnmanagedVector3(value, headRotation);
	}

	Vector3 SoldierGameObj::HeadLookTarget::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &headLookTarget = helper->GetHeadLookTarget();

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(headLookTarget, result);

		return result;
	}

	void SoldierGameObj::HeadLookTarget::set(Vector3 value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &headLookTarget = helper->GetHeadLookTarget();

		Vector3::ManagedToUnmanagedVector3(value, headLookTarget);
	}

	Vector3 SoldierGameObj::HeadLookAngle::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &headLookAngle = helper->GetHeadLookAngle();

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(headLookAngle, result);

		return result;
	}

	void SoldierGameObj::HeadLookAngle::set(Vector3 value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &headLookAngle = helper->GetHeadLookAngle();

		Vector3::ManagedToUnmanagedVector3(value, headLookAngle);
	}

	float SoldierGameObj::HeadLookAngleTimer::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &headLookAngleTimer = helper->GetHeadLookAngleTimer();

		return headLookAngleTimer;
	}

	void SoldierGameObj::HeadLookAngleTimer::set(float value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &headLookAngleTimer = helper->GetHeadLookAngleTimer();

		headLookAngleTimer = value;
	}

	int SoldierGameObj::SubState::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		return helper->GetSubState();
	}

	ArmorWarheadManager::SpecialDamageType SoldierGameObj::SpecialDamageMode::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &specialDamageMode = helper->GetSpecialDamageMode();

		return static_cast<ArmorWarheadManager::SpecialDamageType>(specialDamageMode);
	}

	void SoldierGameObj::SpecialDamageMode::set(ArmorWarheadManager::SpecialDamageType value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &specialDamageMode = helper->GetSpecialDamageMode();

		specialDamageMode = static_cast<::ArmorWarheadManager::SpecialDamageType>(value);
	}

	float SoldierGameObj::SpecialDamageTimer::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &specialDamageTimer = helper->GetSpecialDamageTimer();

		return specialDamageTimer;
	}

	void SoldierGameObj::SpecialDamageTimer::set(float value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &specialDamageTimer = helper->GetSpecialDamageTimer();

		specialDamageTimer = value;
	}

	IReferencerClass ^SoldierGameObj::SpecialDamageDamager::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &specialDamageDamager = helper->GetSpecialDamageDamager();

		return gcnew ReferencerClass(IntPtr(&specialDamageDamager));
	}

	void SoldierGameObj::SpecialDamageDamager::set(IReferencerClass ^value)
	{
		if (value == nullptr || value->ReferencerClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &specialDamageDamager = helper->GetSpecialDamageDamager();

		specialDamageDamager = *reinterpret_cast<::ReferencerClass *>(value->ReferencerClassPointer.ToPointer());
	}

	IntPtr SoldierGameObj::SpecialDamageEffect::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &specialDamageEffect = helper->GetSpecialDamageEffect();

		return IntPtr(specialDamageEffect);
	}

	void SoldierGameObj::SpecialDamageEffect::set(IntPtr value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &specialDamageEffect = helper->GetSpecialDamageEffect();

		specialDamageEffect = reinterpret_cast<::TransitionEffectClass *>(value.ToPointer());
	}

	IntPtr SoldierGameObj::HealingEffect::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &healingEffect = helper->GetHealingEffect();

		return IntPtr(healingEffect);
	}

	void SoldierGameObj::HealingEffect::set(IntPtr value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &healingEffect = helper->GetHealingEffect();

		healingEffect = reinterpret_cast<::TransitionEffectClass *>(value.ToPointer());
	}

	IReferencerClass ^SoldierGameObj::FacingObject::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &facingObject = helper->GetFacingObject();

		return gcnew ReferencerClass(IntPtr(&facingObject));
	}

	void SoldierGameObj::FacingObject::set(IReferencerClass ^value)
	{
		if (value == nullptr || value->ReferencerClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &facingObject = helper->GetFacingObject();

		facingObject = *reinterpret_cast<::ReferencerClass *>(value->ReferencerClassPointer.ToPointer());
	}

	bool SoldierGameObj::FacingAllowBodyTurn::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		bool &facingAllowBodyTurn = helper->GetFacingAllowBodyTurn();

		return facingAllowBodyTurn;
	}

	void SoldierGameObj::FacingAllowBodyTurn::set(bool value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		bool &facingAllowBodyTurn = helper->GetFacingAllowBodyTurn();

		facingAllowBodyTurn = value;
	}

	int SoldierGameObj::InnateEnableBits::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &innateEnableBits = helper->GetInnateEnableBits();

		return innateEnableBits;
	}

	void SoldierGameObj::InnateEnableBits::set(int value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &innateEnableBits = helper->GetInnateEnableBits();

		innateEnableBits = value;
	}

	IntPtr SoldierGameObj::SpeechAnim::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &speechAnim = helper->GetSpeechAnim();

		return IntPtr(speechAnim);
	}

	void SoldierGameObj::SpeechAnim::set(IntPtr value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &speechAnim = helper->GetSpeechAnim();

		speechAnim = reinterpret_cast<::DynamicSpeechAnimClass *>(value.ToPointer());
	}

	float SoldierGameObj::GenerateIdleFacialAnimTimer::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &generateIdleFacialAnimTimer = helper->GetGenerateIdleFacialAnimTimer();

		return generateIdleFacialAnimTimer;
	}

	void SoldierGameObj::GenerateIdleFacialAnimTimer::set(float value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &generateIdleFacialAnimTimer = helper->GetGenerateIdleFacialAnimTimer();

		generateIdleFacialAnimTimer = value;
	}

	IRenderObjClass ^SoldierGameObj::HeadModel::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &headModel = helper->GetHeadModel();

		if (headModel == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(headModel));
		}
	}

	void SoldierGameObj::HeadModel::set(IRenderObjClass ^value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &headModel = helper->GetHeadModel();

		if (value == nullptr || value->RenderObjClassPointer.ToPointer() == nullptr)
		{
			headModel = nullptr;
		}
		else
		{
			headModel = reinterpret_cast<::RenderObjClass *>(value->RenderObjClassPointer.ToPointer());
		}
	}

	IRenderObjClass ^SoldierGameObj::EmotIconModel::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &emotIconModel = helper->GetEmotIconModel();

		if (emotIconModel == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(emotIconModel));
		}
	}

	void SoldierGameObj::EmotIconModel::set(IRenderObjClass ^value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &emotIconModel = helper->GetEmotIconModel();

		if (value == nullptr || value->RenderObjClassPointer.ToPointer() == nullptr)
		{
			emotIconModel = nullptr;
		}
		else
		{
			emotIconModel = reinterpret_cast<::RenderObjClass *>(value->RenderObjClassPointer.ToPointer());
		}
	}

	float SoldierGameObj::EmotIconTimer::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &emotIconTimer = helper->GetEmotIconTimer();

		return emotIconTimer;
	}

	void SoldierGameObj::EmotIconTimer::set(float value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &emotIconTimer = helper->GetEmotIconTimer();

		emotIconTimer = value;
	}

	bool SoldierGameObj::LadderUpMask::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &ladderUpMask = helper->GetLadderUpMask();

		return ladderUpMask;
	}

	void SoldierGameObj::LadderUpMask::set(bool value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &ladderUpMask = helper->GetLadderUpMask();

		ladderUpMask = value;
	}

	bool SoldierGameObj::LadderDownMask::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &ladderDownMask = helper->GetLadderDownMask();

		return ladderDownMask;
	}

	void SoldierGameObj::LadderDownMask::set(bool value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &ladderDownMask = helper->GetLadderDownMask();

		ladderDownMask = value;
	}

	float SoldierGameObj::ReloadingTilt::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &reloadingTilt = helper->GetReloadingTilt();

		return reloadingTilt;
	}

	void SoldierGameObj::ReloadingTilt::set(float value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &reloadingTilt = helper->GetReloadingTilt();

		reloadingTilt = value;
	}

	bool SoldierGameObj::WeaponChanged::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &weaponChanged = helper->GetWeaponChanged();

		return weaponChanged;
	}

	void SoldierGameObj::WeaponChanged::set(bool value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &weaponChanged = helper->GetWeaponChanged();

		weaponChanged = value;
	}

	IntPtr SoldierGameObj::WaterWake::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &waterWake = helper->GetWaterWake();

		return IntPtr(waterWake);
	}

	void SoldierGameObj::WaterWake::set(IntPtr value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &waterWake = helper->GetWaterWake();

		waterWake = reinterpret_cast<::PersistantSurfaceEmitterClass *>(value.ToPointer());
	}

	IDynamicVectorClass<IRenderObjClass ^> ^SoldierGameObj::RenderObjList::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &renderObjList = helper->GetRenderObjList();

		return gcnew RenderObjClassPtrDynamicVectorClass(IntPtr(&renderObjList));
	}

	void SoldierGameObj::RenderObjList::set(IDynamicVectorClass<IRenderObjClass ^> ^value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &renderObjList = helper->GetRenderObjList();

		renderObjList = *reinterpret_cast<::DynamicVectorClass<::RenderObjClass *> *>(value->Pointer.ToPointer());
	}

	int SoldierGameObj::HeadBone::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &headBone = helper->GetHeadBone();

		return headBone;
	}

	void SoldierGameObj::HeadBone::set(int value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &headBone = helper->GetHeadBone();

		headBone = value;
	}

	int SoldierGameObj::NeckBone::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &neckBone = helper->GetNeckBone();

		return neckBone;
	}

	void SoldierGameObj::NeckBone::set(int value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &neckBone = helper->GetNeckBone();

		neckBone = value;
	}

	float SoldierGameObj::LastScale::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &lastScale = helper->GetLastScale();

		return lastScale;
	}

	void SoldierGameObj::LastScale::set(float value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &lastScale = helper->GetLastScale();

		lastScale = value;
	}

	float SoldierGameObj::LastSkeletonHeight::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &lastSkeletonHeight = helper->GetLastSkeletonHeight();

		return lastSkeletonHeight;
	}

	void SoldierGameObj::LastSkeletonHeight::set(float value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &lastSkeletonHeight = helper->GetLastSkeletonHeight();

		lastSkeletonHeight = value;
	}

	float SoldierGameObj::LastSkeletonWidth::get()
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &lastSkeletonWidth = helper->GetLastSkeletonWidth();

		return lastSkeletonWidth;
	}

	void SoldierGameObj::LastSkeletonWidth::set(float value)
	{
		auto helper = reinterpret_cast<SoldierGameObjHelper *>(InternalSoldierGameObjPointer);

		auto &lastSkeletonWidth = helper->GetLastSkeletonWidth();

		lastSkeletonWidth = value;
	}
}