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
#include "MHumanStateClass.h"

#include "MMatrix3D.h"

namespace RenSharp
{
	HumanStateClass::HumanStateClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool HumanStateClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IHumanStateClass ^otherThis = dynamic_cast<IHumanStateClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return HumanStateClassPointer.Equals(otherThis->HumanStateClassPointer);
	}

	void HumanStateClass::ToggleStateFlag(int flag)
	{
		InternalHumanStateClassPointer->Toggle_State_Flag(flag);
	}

	bool HumanStateClass::GetStateFlag(int flag)
	{
		return InternalHumanStateClassPointer->Get_State_Flag(flag);
	}

	void HumanStateClass::DropWeapon()
	{
		InternalHumanStateClassPointer->Drop_Weapon();
	}

	void HumanStateClass::RaiseWeapon()
	{
		InternalHumanStateClassPointer->Raise_Weapon();
	}

	void HumanStateClass::SetTurnVelocity(float vel)
	{
		InternalHumanStateClassPointer->Set_Turn_Velocity(vel);
	}

	void HumanStateClass::SetLoitersAllowed(bool allowed)
	{
		InternalHumanStateClassPointer->Set_Loiters_Allowed(allowed);
	}

	IntPtr HumanStateClass::HumanStateClassPointer::get()
	{
		return IntPtr(InternalHumanStateClassPointer);
	}

	IHumanStateClass::HumanStateType HumanStateClass::State::get()
	{
		return static_cast<IHumanStateClass::HumanStateType>(InternalHumanStateClassPointer->Get_State());
	}

	int HumanStateClass::SubState::get()
	{
		return InternalHumanStateClassPointer->Get_Sub_State();
	}

	float HumanStateClass::StateTimer::get()
	{
		return InternalHumanStateClassPointer->Get_State_Timer();
	}

	void HumanStateClass::StateTimer::set(float value)
	{
		InternalHumanStateClassPointer->Set_State_Timer(value);
	}

	bool HumanStateClass::IsLocked::get()
	{
		return InternalHumanStateClassPointer->Is_Locked();
	}

	Matrix3D HumanStateClass::JumpTransform::get()
	{
		Matrix3D result;
		Matrix3D::UnmanagedToManagedMatrix3D(InternalHumanStateClassPointer->Get_Jump_Transform(), result);

		return result;
	}

	void HumanStateClass::JumpTransform::set(Matrix3D value)
	{
		::Matrix3D tmp;
		Matrix3D::ManagedToUnmanagedMatrix3D(value, tmp);

		InternalHumanStateClassPointer->Set_Jump_Transform(tmp);
	}

	::HumanStateClass *HumanStateClass::InternalHumanStateClassPointer::get()
	{
		return reinterpret_cast<::HumanStateClass *>(Pointer.ToPointer());
	}
}