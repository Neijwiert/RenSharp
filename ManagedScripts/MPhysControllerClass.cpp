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
#include "MPhysControllerClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <PhysControllerClass.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "Imports.h"
#include "MVector3.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	PhysControllerClass::PhysControllerClass()
		: AbstractUnmanagedObject(IntPtr(Imports::CreatePhysControllerClass()))
	{

	}

	PhysControllerClass::PhysControllerClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IPhysControllerClass ^> ^PhysControllerClass::CreatePhysControllerClass()
	{
		return gcnew UnmanagedContainer<IPhysControllerClass ^>(gcnew PhysControllerClass());
	}

	bool PhysControllerClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IPhysControllerClass ^otherThis = dynamic_cast<IPhysControllerClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return PhysControllerClassPointer.Equals(otherThis->PhysControllerClassPointer);
	}

	void PhysControllerClass::Reset()
	{
		InternalPhysControllerClassPointer->Reset();
	}

	void PhysControllerClass::ResetMove()
	{
		InternalPhysControllerClassPointer->Reset_Move();
	}

	void PhysControllerClass::ResetTurn()
	{
		InternalPhysControllerClassPointer->Reset_Turn();
	}

	IntPtr PhysControllerClass::PhysControllerClassPointer::get()
	{
		return IntPtr(InternalPhysControllerClassPointer);
	}

	float PhysControllerClass::MoveForward::get()
	{
		return InternalPhysControllerClassPointer->Get_Move_Forward();
	}

	void PhysControllerClass::MoveForward::set(float value)
	{
		InternalPhysControllerClassPointer->Set_Move_Forward(value);
	}

	float PhysControllerClass::MoveLeft::get()
	{
		return InternalPhysControllerClassPointer->Get_Move_Left();
	}

	void PhysControllerClass::MoveLeft::set(float value)
	{
		InternalPhysControllerClassPointer->Set_Move_Left(value);
	}

	float PhysControllerClass::MoveUp::get()
	{
		return InternalPhysControllerClassPointer->Get_Move_Up();
	}

	void PhysControllerClass::MoveUp::set(float value)
	{
		InternalPhysControllerClassPointer->Set_Move_Up(value);
	}
	
	float PhysControllerClass::TurnLeft::get()
	{
		return InternalPhysControllerClassPointer->Get_Turn_Left();
	}

	void PhysControllerClass::TurnLeft::set(float value)
	{
		InternalPhysControllerClassPointer->Set_Turn_Left(value);
	}

	Vector3 PhysControllerClass::MoveVector::get()
	{
		Vector3 result;
		Vector3::UnmanagedToManagedVector3(InternalPhysControllerClassPointer->Get_Move_Vector(), result);

		return result;
	}

	bool PhysControllerClass::IsInactive::get()
	{
		return InternalPhysControllerClassPointer->Is_Inactive();
	}

	bool PhysControllerClass::InternalDestroyPointer()
	{
		Imports::DestroyPhysControllerClass(InternalPhysControllerClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::PhysControllerClass *PhysControllerClass::InternalPhysControllerClassPointer::get()
	{
		return reinterpret_cast<::PhysControllerClass *>(Pointer.ToPointer());
	}
}