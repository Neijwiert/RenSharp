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
#include "MPhysicalGameObj.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <PhysicalGameObj.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MSimpleGameObj.h"
#include "MPowerUpGameObj.h"
#include "MC4GameObj.h"
#include "MBeaconGameObj.h"
#include "MCinematicGameObj.h"
#include "MMatrix3D.h"
#include "MPhysClass.h"
#include "MRenderObjClass.h"
#include "MOffenseObjectClass.h"
#include "MArmedGameObj.h"
#include "MAnimControlClass.h"

namespace RenSharp
{

#pragma managed(push, off)

	class PhysicalGameObjHelper : public ::PhysicalGameObj
	{
		private:
			PhysicalGameObjHelper() = default;

		public:
			::ActiveConversationClass *&GetActiveConversation()
			{
				return ActiveConversation;
			}
	};

#pragma managed(pop)

	PhysicalGameObj::PhysicalGameObj(IntPtr pointer)
		: DamageableGameObj(pointer)
	{
		combatPhysObserverClass = gcnew CombatPhysObserverClass(IntPtr(InternalCombatPhysObserverClassPointer));
	}

	bool PhysicalGameObj::Equals(Object ^other)
	{
		if (ScriptableGameObj::Equals(other))
		{
			return true;
		}

		if (ReferenceEquals(other, nullptr))
		{
			return false;
		}

		auto otherUnmanagedObj = dynamic_cast<IUnmanagedObject ^>(other);
		if (otherUnmanagedObj == nullptr || otherUnmanagedObj->Pointer.Equals(IntPtr::Zero))
		{
			return false;
		}

		auto otherPhysObserverClass = dynamic_cast<IPhysObserverClass^>(other);
		if (otherPhysObserverClass != nullptr)
		{
			if (combatPhysObserverClass->Equals(otherPhysObserverClass))
			{
				return true;
			}
		}

		auto otherPhysicalGameObj = dynamic_cast<IPhysicalGameObj ^>(other);
		if (otherPhysicalGameObj != nullptr)
		{
			if (PhysicalGameObjPointer.Equals(otherPhysicalGameObj->PhysicalGameObjPointer))
			{
				return true;
			}
		}

		return false;
	}

	int PhysicalGameObj::CollisionOccurred(IntPtr event)
	{
		return combatPhysObserverClass->CollisionOccurred(event);
	}

	int PhysicalGameObj::ObjectExpired(IPhysClass ^observedObj)
	{
		return combatPhysObserverClass->ObjectExpired(observedObj);
	}

	void PhysicalGameObj::ObjectRemovedFromScene(IPhysClass ^observedObj)
	{
		combatPhysObserverClass->ObjectRemovedFromScene(observedObj);
	}

	void PhysicalGameObj::ObjectShatteredSomething(IPhysClass ^observedObj, IPhysClass ^shatteredObj, int surfaceType)
	{
		combatPhysObserverClass->ObjectShatteredSomething(observedObj, shatteredObj, surfaceType);
	}

	IPhysicalGameObj ^PhysicalGameObj::AsPhysicalGameObj()
	{
		return this;
	}

	void PhysicalGameObj::Startup()
	{
		InternalPhysicalGameObjPointer->Startup();
	}

	IPhysClass ^PhysicalGameObj::PeekPhysicalObject()
	{
		auto result = InternalPhysicalGameObjPointer->Peek_Physical_Object();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PhysClass(IntPtr(result));
		}
	}

	IRenderObjClass ^PhysicalGameObj::PeekModel()
	{
		auto result = InternalPhysicalGameObjPointer->Peek_Model();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(result));
		}
	}

	void PhysicalGameObj::SetAnimation(String ^animationName, bool looping, float frameOffset)
	{
		if (animationName == nullptr)
		{
			InternalPhysicalGameObjPointer->Set_Animation(nullptr, looping, frameOffset);
		}
		else
		{
			IntPtr animationNameHandle = Marshal::StringToHGlobalAnsi(animationName);
			try
			{
				InternalPhysicalGameObjPointer->Set_Animation(reinterpret_cast<char *>(animationNameHandle.ToPointer()), looping, frameOffset);
			}
			finally
			{
				Marshal::FreeHGlobal(animationNameHandle);
			}
		}
	}

	void PhysicalGameObj::SetAnimation(String ^animationName, bool looping)
	{
		if (animationName == nullptr)
		{
			InternalPhysicalGameObjPointer->Set_Animation(nullptr, looping);
		}
		else
		{
			IntPtr animationNameHandle = Marshal::StringToHGlobalAnsi(animationName);
			try
			{
				InternalPhysicalGameObjPointer->Set_Animation(reinterpret_cast<char *>(animationNameHandle.ToPointer()), looping);
			}
			finally
			{
				Marshal::FreeHGlobal(animationNameHandle);
			}
		}
	}

	void PhysicalGameObj::SetAnimation(String ^animationName)
	{
		if (animationName == nullptr)
		{
			InternalPhysicalGameObjPointer->Set_Animation(nullptr);
		}
		else
		{
			IntPtr animationNameHandle = Marshal::StringToHGlobalAnsi(animationName);
			try
			{
				InternalPhysicalGameObjPointer->Set_Animation(reinterpret_cast<char *>(animationNameHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(animationNameHandle);
			}
		}
	}

	void PhysicalGameObj::SetAnimationFrame(String ^animationName, int frame)
	{
		if (animationName == nullptr)
		{
			InternalPhysicalGameObjPointer->Set_Animation_Frame(nullptr, frame);
		}
		else
		{
			IntPtr animationNameHandle = Marshal::StringToHGlobalAnsi(animationName);
			try
			{
				InternalPhysicalGameObjPointer->Set_Animation_Frame(reinterpret_cast<char *>(animationNameHandle.ToPointer()), frame);
			}
			finally
			{
				Marshal::FreeHGlobal(animationNameHandle);
			}
		}
	}

	void PhysicalGameObj::ApplyDamageExtended(IOffenseObjectClass ^offense, float scale, Vector3 direction, String ^collisionBoxName)
	{
		if (offense == nullptr)
		{
			throw gcnew ArgumentNullException("offense");
		}

		::Vector3 directionVec;

		Vector3::ManagedToUnmanagedVector3(direction, directionVec);

		if (collisionBoxName == nullptr)
		{
			InternalPhysicalGameObjPointer->Apply_Damage_Extended(
				*reinterpret_cast<::OffenseObjectClass *>(offense->OffenseObjectClassPointer.ToPointer()),
				scale,
				directionVec,
				nullptr);
		}
		else
		{
			IntPtr collisionBoxNameHandle = Marshal::StringToHGlobalAnsi(collisionBoxName);
			try
			{
				InternalPhysicalGameObjPointer->Apply_Damage_Extended(
					*reinterpret_cast<::OffenseObjectClass *>(offense->OffenseObjectClassPointer.ToPointer()),
					scale,
					directionVec,
					reinterpret_cast<char *>(collisionBoxNameHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(collisionBoxNameHandle);
			}
		}
	}

	void PhysicalGameObj::ApplyDamageExtended(IOffenseObjectClass ^offense, float scale, Vector3 direction)
	{
		if (offense == nullptr)
		{
			throw gcnew ArgumentNullException("offense");
		}

		::Vector3 directionVec;

		Vector3::ManagedToUnmanagedVector3(direction, directionVec);

		InternalPhysicalGameObjPointer->Apply_Damage_Extended(
			*reinterpret_cast<::OffenseObjectClass *>(offense->OffenseObjectClassPointer.ToPointer()),
			scale,
			directionVec);
	}

	void PhysicalGameObj::ApplyDamageExtended(IOffenseObjectClass ^offense, float scale)
	{
		if (offense == nullptr)
		{
			throw gcnew ArgumentNullException("offense");
		}

		InternalPhysicalGameObjPointer->Apply_Damage_Extended(
			*reinterpret_cast<::OffenseObjectClass *>(offense->OffenseObjectClassPointer.ToPointer()),
			scale);
	}

	void PhysicalGameObj::ApplyDamageExtended(IOffenseObjectClass ^offense)
	{
		if (offense == nullptr)
		{
			throw gcnew ArgumentNullException("offense");
		}

		InternalPhysicalGameObjPointer->Apply_Damage_Extended(
			*reinterpret_cast<::OffenseObjectClass *>(offense->OffenseObjectClassPointer.ToPointer()));
	}

	IPowerUpGameObj ^PhysicalGameObj::AsPowerUpGameObj()
	{
		auto result = InternalPhysicalGameObjPointer->As_PowerUpGameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PowerUpGameObj(IntPtr(result));
		}
	}

	IC4GameObj ^PhysicalGameObj::AsC4GameObj()
	{
		auto result = InternalPhysicalGameObjPointer->As_C4GameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew C4GameObj(IntPtr(result));
		}
	}

	IBeaconGameObj ^PhysicalGameObj::AsBeaconGameObj()
	{
		auto result = InternalPhysicalGameObjPointer->As_BeaconGameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BeaconGameObj(IntPtr(result));
		}
	}

	ISimpleGameObj ^PhysicalGameObj::AsSimpleGameObj()
	{
		auto result = InternalPhysicalGameObjPointer->As_SimpleGameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SimpleGameObj(IntPtr(result));
		}
	}

	ICinematicGameObj ^PhysicalGameObj::AsCinematicGameObj()
	{
		auto result = InternalPhysicalGameObjPointer->As_CinematicGameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew CinematicGameObj(IntPtr(result));
		}
	}

	IArmedGameObj ^PhysicalGameObj::AsArmedGameObj()
	{
		auto result = InternalPhysicalGameObjPointer->As_ArmedGameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ArmedGameObj(IntPtr(result));
		}
	}

	void PhysicalGameObj::EnableHibernation(bool enable)
	{
		InternalPhysicalGameObjPointer->Enable_Hibernation(enable);
	}

	void PhysicalGameObj::DoNotHibernate()
	{
		InternalPhysicalGameObjPointer->Do_Not_Hibernate();
	}

	void PhysicalGameObj::BeginHibernation()
	{
		InternalPhysicalGameObjPointer->Begin_Hibernation();
	}

	void PhysicalGameObj::EndHibernation()
	{
		InternalPhysicalGameObjPointer->End_Hibernation();
	}

	void PhysicalGameObj::ResetRadarBlipShapeType()
	{
		InternalPhysicalGameObjPointer->Reset_Radar_Blip_Shape_Type();
	}

	void PhysicalGameObj::ClearAnimation()
	{
		InternalPhysicalGameObjPointer->Clear_Animation();
	}

	void PhysicalGameObj::SetTeamVisibility(TeamVisibilitySetting setting)
	{
		InternalPhysicalGameObjPointer->Set_Team_Visibility(static_cast<::TeamVisibilitySetting>(setting));
	}

	void PhysicalGameObj::SetPlayerVisible(bool visible)
	{
		InternalPhysicalGameObjPointer->Set_Player_Visible(visible);
	}

	IntPtr PhysicalGameObj::Pointer::get()
	{
		return ScriptableGameObj::Pointer::get();
	}

	void PhysicalGameObj::Pointer::set(IntPtr value)
	{
		ScriptableGameObj::Pointer::set(value);

		if (Pointer == IntPtr::Zero)
		{
			combatPhysObserverClass = nullptr;
		}
		else
		{
			combatPhysObserverClass = gcnew CombatPhysObserverClass(IntPtr(InternalCombatPhysObserverClassPointer));
		}
	}

	Vector3 PhysicalGameObj::Position::get()
	{
		return ScriptableGameObj::Position::get();
	}

	void PhysicalGameObj::Position::set(Vector3 value)
	{
		::Vector3 valueVec;

		Vector3::ManagedToUnmanagedVector3(value, valueVec);

		InternalPhysicalGameObjPointer->Set_Position(valueVec);
	}

	IntPtr PhysicalGameObj::PhysObserverClassPointer::get()
	{
		return IntPtr(InternalPhysObserverClassPointer);
	}

	IntPtr PhysicalGameObj::CombatPhysObserverClassPointer::get()
	{
		return IntPtr(InternalCombatPhysObserverClassPointer);
	}

	IntPtr PhysicalGameObj::PhysicalGameObjPointer::get()
	{
		return IntPtr(InternalPhysicalGameObjPointer);
	}

	IPhysicalGameObjDef ^PhysicalGameObj::Definition::get()
	{
		return gcnew PhysicalGameObjDef(IntPtr(const_cast<::PhysicalGameObjDef *>(&InternalPhysicalGameObjPointer->Get_Definition())));
	}

	bool PhysicalGameObj::IsAttachedToAnObject::get()
	{
		return InternalPhysicalGameObjPointer->Is_Attached_To_An_Object();
	}

	Matrix3D PhysicalGameObj::Transform::get()
	{
		Matrix3D result;
		Matrix3D::UnmanagedToManagedMatrix3D(InternalPhysicalGameObjPointer->Get_Transform(), result);

		return result;
	}

	void PhysicalGameObj::Transform::set(Matrix3D value)
	{
		::Matrix3D valueMat;
		Matrix3D::ManagedToUnmanagedMatrix3D(value, valueMat);

		InternalPhysicalGameObjPointer->Set_Transform(valueMat);
	}

	float PhysicalGameObj::Facing::get()
	{
		return InternalPhysicalGameObjPointer->Get_Facing();
	}

	IAnimControlClass ^PhysicalGameObj::AnimControl::get()
	{
		auto result = InternalPhysicalGameObjPointer->Get_Anim_Control();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew AnimControlClass(IntPtr(result));
		}
	}

	float PhysicalGameObj::BullseyeOffsetZ::get()
	{
		return InternalPhysicalGameObjPointer->Get_Bullseye_Offset_Z();
	}

	Vector3 PhysicalGameObj::BullseyePosition::get()
	{
		Vector3 result;
		Vector3::UnmanagedToManagedVector3(InternalPhysicalGameObjPointer->Get_Bullseye_Position(), result);

		return result;
	}

	bool PhysicalGameObj::TakesExplosionDamage::get()
	{
		return InternalPhysicalGameObjPointer->Takes_Explosion_Damage();
	}

	int PhysicalGameObj::Type::get()
	{
		return InternalPhysicalGameObjPointer->Get_Type();
	}

	CollisionGroupType PhysicalGameObj::CollisionGroup::get()
	{
		return static_cast<CollisionGroupType>(InternalPhysicalGameObjPointer->Get_Collision_Group());
	}

	void PhysicalGameObj::CollisionGroup::set(CollisionGroupType value)
	{
		InternalPhysicalGameObjPointer->Set_Collision_Group(static_cast<::Collision_Group_Type>(value));
	}

	BYTE PhysicalGameObj::ServerSkips::get()
	{
		return InternalPhysicalGameObjPointer->Get_Server_Skips();
	}

	int PhysicalGameObj::RadarBlipShapeType::get()
	{
		return InternalPhysicalGameObjPointer->Get_Radar_Blip_Shape_Type();
	}

	void PhysicalGameObj::RadarBlipShapeType::set(int value)
	{
		InternalPhysicalGameObjPointer->Set_Radar_Blip_Shape_Type(value);
	}

	int PhysicalGameObj::RadarBlipColorType::get()
	{
		return InternalPhysicalGameObjPointer->Get_Radar_Blip_Color_Type();
	}

	void PhysicalGameObj::RadarBlipColorType::set(int value)
	{
		InternalPhysicalGameObjPointer->Set_Radar_Blip_Color_Type(value);
	}

	float PhysicalGameObj::RadarBlipIntensity::get()
	{
		return InternalPhysicalGameObjPointer->Get_Radar_Blip_Intensity();
	}

	void PhysicalGameObj::RadarBlipIntensity::set(float value)
	{
		InternalPhysicalGameObjPointer->Set_Radar_Blip_Intensity(value);
	}

	bool PhysicalGameObj::IsInnateConversationsEnabled::get()
	{
		return InternalPhysicalGameObjPointer->Are_Innate_Conversations_Enabled();
	}

	void PhysicalGameObj::IsInnateConversationsEnabled::set(bool value)
	{
		InternalPhysicalGameObjPointer->Enable_Innate_Conversations(value);
	}

	bool PhysicalGameObj::IsInConversation::get()
	{
		return InternalPhysicalGameObjPointer->Is_In_Conversation();
	}

	bool PhysicalGameObj::HUDPokableIndicatorEnabled::get()
	{
		return InternalPhysicalGameObjPointer->Is_HUD_Pokable_Indicator_Enabled();
	}

	IScriptableGameObj^ PhysicalGameObj::ParentObject::get()
	{
		auto result = InternalPhysicalGameObjPointer->Get_Parent_Object();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptableGameObj(IntPtr(result));
		}
	}

	::DamageableGameObj *PhysicalGameObj::InternalDamageableGameObjPointer::get()
	{
		return InternalPhysicalGameObjPointer;
	}

	::PhysObserverClass *PhysicalGameObj::InternalPhysObserverClassPointer::get()
	{
		return InternalPhysicalGameObjPointer;
	}

	::CombatPhysObserverClass *PhysicalGameObj::InternalCombatPhysObserverClassPointer::get()
	{
		return InternalPhysicalGameObjPointer;
	}

	::PhysicalGameObj *PhysicalGameObj::InternalPhysicalGameObjPointer::get()
	{
		return reinterpret_cast<::PhysicalGameObj *>(Pointer.ToPointer());
	}

	IntPtr PhysicalGameObj::ActiveConversation::get()
	{
		auto helper = reinterpret_cast<PhysicalGameObjHelper *>(InternalPhysicalGameObjPointer);

		auto &activeConversation = helper->GetActiveConversation();

		return IntPtr(activeConversation);
	}

	void PhysicalGameObj::ActiveConversation::set(IntPtr value)
	{
		auto helper = reinterpret_cast<PhysicalGameObjHelper *>(InternalPhysicalGameObjPointer);

		auto &activeConversation = helper->GetActiveConversation();

		activeConversation = reinterpret_cast<::ActiveConversationClass *>(value.ToPointer());
	}
}