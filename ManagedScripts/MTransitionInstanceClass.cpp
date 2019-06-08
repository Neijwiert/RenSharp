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
#include "MTransitionInstanceClass.h"

#include "MMatrix3D.h"
#include "Mobboxclass.h"
#include "MVehicleGameObj.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <TransitionInstanceClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	TransitionInstanceClass::TransitionInstanceClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool TransitionInstanceClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		ITransitionInstanceClass ^otherThis = dynamic_cast<ITransitionInstanceClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return TransitionInstanceClassPointer.Equals(otherThis->TransitionInstanceClassPointer);
	}

	void TransitionInstanceClass::SetVehicle(IVehicleGameObj ^obj)
	{
		if (obj == nullptr || obj->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			InternalTransitionInstanceClassPointer->Set_Vehicle(nullptr);
		}
		else
		{
			InternalTransitionInstanceClassPointer->Set_Vehicle(reinterpret_cast<::VehicleGameObj *>(obj->VehicleGameObjPointer.ToPointer()));
		}
	}

	void TransitionInstanceClass::SetLadderIndex(int index)
	{
		InternalTransitionInstanceClassPointer->Set_Ladder_Index(index);
	}

	IntPtr TransitionInstanceClass::TransitionInstanceClassPointer::get()
	{
		return IntPtr(InternalTransitionInstanceClassPointer);
	}

	ITransitionDataClass::StyleType TransitionInstanceClass::Type::get()
	{
		return static_cast<ITransitionDataClass::StyleType>(InternalTransitionInstanceClassPointer->Get_Type());
	}

	OBBoxClass TransitionInstanceClass::TriggerZone::get()
	{
		OBBoxClass result;

		OBBoxClass::UnmanagedToManagedOBBoxClass(InternalTransitionInstanceClassPointer->Get_Trigger_Zone(), result);

		return result;
	}

	void TransitionInstanceClass::TriggerZone::set(OBBoxClass value)
	{
		OBBoxClass::ManagedToUnmanagedOBBoxClass(value, InternalTransitionInstanceClassPointer->Get_Trigger_Zone());
	}

	Matrix3D TransitionInstanceClass::CharacterTransform::get()
	{
		Matrix3D result;

		Matrix3D::UnmanagedToManagedMatrix3D(InternalTransitionInstanceClassPointer->Get_Character_Transform(), result);

		return result;
	}

	void TransitionInstanceClass::CharacterTransform::set(Matrix3D value)
	{
		Matrix3D::ManagedToUnmanagedMatrix3D(value, InternalTransitionInstanceClassPointer->Get_Character_Transform());
	}

	::TransitionInstanceClass *TransitionInstanceClass::InternalTransitionInstanceClassPointer::get()
	{
		return reinterpret_cast<::TransitionInstanceClass *>(Pointer.ToPointer());
	}
}