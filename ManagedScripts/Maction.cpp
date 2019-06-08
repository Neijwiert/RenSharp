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
#include "Maction.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <action.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "Imports.h"
#include "UnmanagedContainer.h"
#include "MReferencerClass.h"
#include "MSmartGameObj.h"

namespace RenSharp
{

#pragma managed(push, off)

	class ActionClassHelper : public ::ActionClass
	{
		private:
			ActionClassHelper() = default;

		public:
			::SmartGameObj *&GetActionObj()
			{
				return ActionObj;
			}

			::ActionCodeClass *&GetActionCode()
			{
				return ActionCode;
			}

			unsigned int &GetActCount()
			{
				return ActCount;
			}
	};

#pragma managed(pop)

	SafeActionParamsStruct::SafeActionParamsStruct()
		: ActionParamsStructRef(IntPtr(Imports::CreateSafeActionParamsStruct()))
	{

	}

	SafeActionParamsStruct::SafeActionParamsStruct(ActionParamsStruct ^params)
		: SafeActionParamsStruct()
	{
		if (params == nullptr)
		{
			throw gcnew ArgumentNullException("params");
		}

		Pointer = IntPtr(Imports::CreateSafeActionParamsStruct());

		Priority = params->Priority;
		ActionID = params->ActionID;
		ObserverID = params->ObserverID;
		LookLocation = params->LookLocation;
		LookObject = params->LookObject;
		LookDuration = params->LookDuration;
		MoveLocation = params->MoveLocation;
		MoveObject = params->MoveObject;
		MoveObjectOffset = params->MoveObjectOffset;
		MoveSpeed = params->MoveSpeed;
		MoveArrivedDistance = params->MoveArrivedDistance;
		MoveBackup = params->MoveBackup;
		MoveFollow = params->MoveFollow;
		MoveCrouched = params->MoveCrouched;
		MovePathfind = params->MovePathfind;
		ShutdownEngineOnArrival = params->ShutdownEngineOnArrival;
		AttackRange = params->AttackRange;
		AttackError = params->AttackError;
		AttackErrorOverride = params->AttackErrorOverride;
		AttackObject = params->AttackObject;
		AttackPrimaryFire = params->AttackPrimaryFire;
		AttackCrouched = params->AttackCrouched;
		AttackLocation = params->AttackLocation;
		AttackCheckBlocked = params->AttackCheckBlocked;
		AttackActive = params->AttackActive;
		AttackWanderAllowed = params->AttackWanderAllowed;
		AttackFaceTarget = params->AttackFaceTarget;
		AttackForceFire = params->AttackForceFire;
		ForceFacing = params->ForceFacing;
		FaceLocation = params->FaceLocation;
		FaceDuration = params->FaceDuration;
		IgnoreFacing = params->IgnoreFacing;
		WaypathID = params->WaypathID;
		WaypointStartID = params->WaypointStartID;
		WaypointEndID = params->WaypointEndID;
		WaypathSplined = params->WaypathSplined;
		AnimationName = params->AnimationName;
		AnimationLooping = params->AnimationLooping;
		ActiveConversationID = params->ActiveConversationID;
		ConversationName = params->ConversationName;
		AIState = params->AIState;
		DockLocation = params->DockLocation;
		DockEntrance = params->DockEntrance;
	}

	SafeActionParamsStruct::SafeActionParamsStruct(IntPtr pointer)
		: ActionParamsStructRef(pointer)
	{

	}

	IUnmanagedContainer<ISafeActionParamsStruct ^> ^SafeActionParamsStruct::CreateSafeActionParamsStruct()
	{
		return gcnew UnmanagedContainer<ISafeActionParamsStruct ^>(gcnew SafeActionParamsStruct());
	}

	IUnmanagedContainer<ISafeActionParamsStruct ^> ^SafeActionParamsStruct::CreateSafeActionParamsStruct(ActionParamsStruct ^params)
	{
		return gcnew UnmanagedContainer<ISafeActionParamsStruct ^>(gcnew SafeActionParamsStruct(params));
	}

	void SafeActionParamsStruct::SetAnimation(String ^name, bool looping)
	{
		if (name == nullptr)
		{
			InternalSafeActionParamsStructPointer->Set_Animation(nullptr, looping);
			InternalSafeActionParamsStructPointer->SafeAnimationName = "";
		}
		else
		{
			IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
			try
			{
				InternalSafeActionParamsStructPointer->SafeAnimationName = reinterpret_cast<char *>(nameHandle.ToPointer());
				InternalSafeActionParamsStructPointer->Set_Animation(InternalSafeActionParamsStructPointer->SafeAnimationName.Peek_Buffer(), looping);
			}
			finally
			{
				Marshal::FreeHGlobal(nameHandle);
			}
		}
	}

	void SafeActionParamsStruct::StartConversation(String ^name)
	{
		if (name == nullptr)
		{
			InternalSafeActionParamsStructPointer->Start_Conversation(nullptr);
			InternalSafeActionParamsStructPointer->ConversationName = "";
		}
		else
		{
			IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
			try
			{
				InternalSafeActionParamsStructPointer->SafeConversationName = reinterpret_cast<char *>(nameHandle.ToPointer());
				InternalSafeActionParamsStructPointer->Start_Conversation(InternalSafeActionParamsStructPointer->SafeConversationName.Peek_Buffer());
			}
			finally
			{
				Marshal::FreeHGlobal(nameHandle);
			}
		}
	}

	IntPtr SafeActionParamsStruct::SafeActionParamsStructPointer::get()
	{
		return IntPtr(InternalSafeActionParamsStructPointer);
	}

	IScriptableGameObj ^SafeActionParamsStruct::LookObject::get()
	{
		return ActionParamsStructRef::LookObject::get();
	}

	void SafeActionParamsStruct::LookObject::set(IScriptableGameObj ^value)
	{
		ActionParamsStructRef::LookObject::set(value);
		InternalSafeActionParamsStructPointer->LookObjectRef = InternalSafeActionParamsStructPointer->LookObject;
	}

	IScriptableGameObj ^SafeActionParamsStruct::MoveObject::get()
	{
		return ActionParamsStructRef::MoveObject::get();
	}

	void SafeActionParamsStruct::MoveObject::set(IScriptableGameObj ^value)
	{
		ActionParamsStructRef::MoveObject::set(value);
		InternalSafeActionParamsStructPointer->MoveObjectRef = InternalSafeActionParamsStructPointer->MoveObject;
	}

	IScriptableGameObj ^SafeActionParamsStruct::AttackObject::get()
	{
		return ActionParamsStructRef::AttackObject::get();
	}

	void SafeActionParamsStruct::AttackObject::set(IScriptableGameObj ^value)
	{
		ActionParamsStructRef::AttackObject::set(value);
		InternalSafeActionParamsStructPointer->AttackObjectRef = InternalSafeActionParamsStructPointer->AttackObject;
	}

	String ^SafeActionParamsStruct::AnimationName::get()
	{
		return ActionParamsStructRef::AnimationName::get();
	}

	void SafeActionParamsStruct::AnimationName::set(String ^value)
	{
		if (value == nullptr)
		{
			InternalSafeActionParamsStructPointer->AnimationName = nullptr;
			InternalSafeActionParamsStructPointer->SafeAnimationName = "";
		}
		else
		{
			IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
			try
			{
				InternalSafeActionParamsStructPointer->SafeAnimationName = reinterpret_cast<char *>(valueHandle.ToPointer());
				InternalSafeActionParamsStructPointer->AnimationName = InternalSafeActionParamsStructPointer->SafeAnimationName.Peek_Buffer();
			}
			finally
			{
				Marshal::FreeHGlobal(valueHandle);
			}
		}
	}

	String ^SafeActionParamsStruct::ConversationName::get()
	{
		return ActionParamsStructRef::ConversationName::get();
	}

	void SafeActionParamsStruct::ConversationName::set(String ^value)
	{
		if (value == nullptr)
		{
			InternalSafeActionParamsStructPointer->ConversationName = nullptr;
			InternalSafeActionParamsStructPointer->SafeConversationName = "";
		}
		else
		{
			IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
			try
			{
				InternalSafeActionParamsStructPointer->SafeConversationName = reinterpret_cast<char *>(valueHandle.ToPointer());
				InternalSafeActionParamsStructPointer->ConversationName = InternalSafeActionParamsStructPointer->SafeConversationName.Peek_Buffer();
			}
			finally
			{
				Marshal::FreeHGlobal(valueHandle);
			}
		}
	}

	IReferencerClass ^SafeActionParamsStruct::MoveObjectRef::get()
	{
		return gcnew ReferencerClass(IntPtr(&InternalSafeActionParamsStructPointer->MoveObjectRef));
	}

	void SafeActionParamsStruct::MoveObjectRef::set(IReferencerClass ^value)
	{
		if (value == nullptr || value->ReferencerClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalSafeActionParamsStructPointer->MoveObjectRef = *reinterpret_cast<::ReferencerClass *>(value->ReferencerClassPointer.ToPointer());
	}

	IReferencerClass ^SafeActionParamsStruct::AttackObjectRef::get()
	{
		return gcnew ReferencerClass(IntPtr(&InternalSafeActionParamsStructPointer->AttackObjectRef));
	}

	void SafeActionParamsStruct::AttackObjectRef::set(IReferencerClass ^value)
	{
		if (value == nullptr || value->ReferencerClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalSafeActionParamsStructPointer->AttackObjectRef = *reinterpret_cast<::ReferencerClass *>(value->ReferencerClassPointer.ToPointer());
	}

	IReferencerClass ^SafeActionParamsStruct::LookObjectRef::get()
	{
		return gcnew ReferencerClass(IntPtr(&InternalSafeActionParamsStructPointer->LookObjectRef));
	}

	void SafeActionParamsStruct::LookObjectRef::set(IReferencerClass ^value)
	{
		if (value == nullptr || value->ReferencerClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalSafeActionParamsStructPointer->LookObjectRef = *reinterpret_cast<::ReferencerClass *>(value->ReferencerClassPointer.ToPointer());
	}

	String ^SafeActionParamsStruct::SafeAnimationName::get()
	{
		return gcnew String(InternalSafeActionParamsStructPointer->SafeAnimationName.Peek_Buffer());
	}

	void SafeActionParamsStruct::SafeAnimationName::set(String ^value)
	{
		if (value == nullptr)
		{
			InternalSafeActionParamsStructPointer->SafeAnimationName = "";
			InternalSafeActionParamsStructPointer->AnimationName = nullptr;
		}
		else
		{
			IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
			try
			{
				InternalSafeActionParamsStructPointer->SafeAnimationName = reinterpret_cast<char *>(valueHandle.ToPointer());
				InternalSafeActionParamsStructPointer->AnimationName = InternalSafeActionParamsStructPointer->SafeAnimationName.Peek_Buffer();
			}
			finally
			{
				Marshal::FreeHGlobal(valueHandle);
			}
		}
	}

	String ^SafeActionParamsStruct::SafeConversationName::get()
	{
		return gcnew String(InternalSafeActionParamsStructPointer->SafeConversationName.Peek_Buffer());
	}

	void SafeActionParamsStruct::SafeConversationName::set(String ^value)
	{
		if (value == nullptr)
		{
			InternalSafeActionParamsStructPointer->SafeConversationName = "";
			InternalSafeActionParamsStructPointer->ConversationName = nullptr;
		}
		else
		{
			IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
			try
			{
				InternalSafeActionParamsStructPointer->SafeConversationName = reinterpret_cast<char *>(valueHandle.ToPointer());
				InternalSafeActionParamsStructPointer->ConversationName = InternalSafeActionParamsStructPointer->SafeConversationName.Peek_Buffer();
			}
			finally
			{
				Marshal::FreeHGlobal(valueHandle);
			}
		}
	}

	bool SafeActionParamsStruct::InternalDestroyPointer()
	{
		Imports::DestroySafeActionParamsStruct(InternalSafeActionParamsStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::ActionParamsStruct *SafeActionParamsStruct::InternalActionParamsStructPointer::get()
	{
		return InternalSafeActionParamsStructPointer;
	}

	::SafeActionParamsStruct *SafeActionParamsStruct::InternalSafeActionParamsStructPointer::get()
	{
		return reinterpret_cast<::SafeActionParamsStruct *>(Pointer.ToPointer());
	}

	ActionClass::ActionClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool ActionClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IActionClass ^otherThis = dynamic_cast<IActionClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return ActionClassPointer.Equals(otherThis->ActionClassPointer);
	}

	IntPtr ActionClass::ActionClassPointer::get()
	{
		return IntPtr(InternalActionClassPointer);
	}

	ISmartGameObj ^ActionClass::ActionObj::get()
	{
		auto result = InternalActionClassPointer->Get_Action_Obj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SmartGameObj(IntPtr(result));
		}
	}

	void ActionClass::ActionObj::set(ISmartGameObj ^value)
	{
		auto helper = reinterpret_cast<ActionClassHelper *>(InternalActionClassPointer);

		auto &actionObj = helper->GetActionObj();

		if (value == nullptr || value->SmartGameObjPointer.ToPointer() == nullptr)
		{
			actionObj = nullptr;
		}
		else
		{
			actionObj = reinterpret_cast<::SmartGameObj *>(value->SmartGameObjPointer.ToPointer());
		}
	}

	ISafeActionParamsStruct ^ActionClass::Parameters::get()
	{
		return gcnew SafeActionParamsStruct(IntPtr(&InternalActionClassPointer->Get_Parameters()));
	}

	void ActionClass::Parameters::set(ISafeActionParamsStruct ^value)
	{
		if (value == nullptr || value->SafeActionParamsStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto &parameters = InternalActionClassPointer->Get_Parameters();

		parameters = *reinterpret_cast<::SafeActionParamsStruct *>(value->SafeActionParamsStructPointer.ToPointer());
	}

	bool ActionClass::IsActing::get()
	{
		return InternalActionClassPointer->Is_Acting();
	}

	unsigned int ActionClass::ActCount::get()
	{
		return InternalActionClassPointer->Get_Act_Count();
	}

	void ActionClass::ActCount::set(unsigned int value)
	{
		auto helper = reinterpret_cast<ActionClassHelper *>(InternalActionClassPointer);

		auto &actCount = helper->GetActCount();

		actCount = value;
	}

	bool ActionClass::IsPaused::get()
	{
		return InternalActionClassPointer->Is_Paused();
	}

	void ActionClass::IsPaused::set(bool value)
	{
		InternalActionClassPointer->Pause(value);
	}

	bool ActionClass::InternalDestroyPointer()
	{
		Imports::DestroyActionClass(InternalActionClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::ActionClass *ActionClass::InternalActionClassPointer::get()
	{
		return reinterpret_cast<::ActionClass *>(Pointer.ToPointer());
	}

	IntPtr ActionClass::ActionCode::get()
	{
		auto helper = reinterpret_cast<ActionClassHelper *>(InternalActionClassPointer);

		auto &actionCode = helper->GetActionCode();

		return IntPtr(actionCode);
	}

	void ActionClass::ActionCode::set(IntPtr value)
	{
		auto helper = reinterpret_cast<ActionClassHelper *>(InternalActionClassPointer);

		auto &actionCode = helper->GetActionCode();

		actionCode = reinterpret_cast<::ActionCodeClass *>(value.ToPointer());
	}
}