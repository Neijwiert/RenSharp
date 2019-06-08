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
#include "MTransitionGameObjDef.h"

#include "Imports.h"
#include "UnmanagedContainer.h"
#include "MTransitionDataClassPtrDynamicVectorClass.h"

namespace RenSharp
{
	TransitionDataClass::TransitionDataClass()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateTransitionDataClass()))
	{

	}

	TransitionDataClass::TransitionDataClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<ITransitionDataClass ^> ^TransitionDataClass::CreateTransitionDataClass()
	{
		return gcnew UnmanagedContainer<ITransitionDataClass ^>(gcnew TransitionDataClass());
	}

	bool TransitionDataClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		ITransitionDataClass ^otherThis = dynamic_cast<ITransitionDataClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return TransitionDataClassPointer.Equals(otherThis->TransitionDataClassPointer);
	}

	IntPtr TransitionDataClass::TransitionDataClassPointer::get()
	{
		return IntPtr(InternalTransitionDataClassPointer);
	}

	ITransitionDataClass::StyleType TransitionDataClass::Type::get()
	{
		return static_cast<ITransitionDataClass::StyleType>(InternalTransitionDataClassPointer->Type);
	}

	void TransitionDataClass::Type::set(ITransitionDataClass::StyleType value)
	{
		InternalTransitionDataClassPointer->Type = static_cast<::TransitionDataClass::StyleType>(value);
	}

	OBBoxClass TransitionDataClass::TriggerZone::get()
	{
		OBBoxClass result;
		OBBoxClass::UnmanagedToManagedOBBoxClass(InternalTransitionDataClassPointer->TriggerZone, result);

		return result;
	}

	void TransitionDataClass::TriggerZone::set(OBBoxClass value)
	{
		OBBoxClass::ManagedToUnmanagedOBBoxClass(value, InternalTransitionDataClassPointer->TriggerZone);
	}

	String ^TransitionDataClass::AnimationName::get()
	{
		return gcnew String(InternalTransitionDataClassPointer->AnimationName.Peek_Buffer());
	}

	void TransitionDataClass::AnimationName::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalTransitionDataClassPointer->AnimationName = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	Matrix3D TransitionDataClass::CharacterTransform::get()
	{
		Matrix3D result;
		Matrix3D::UnmanagedToManagedMatrix3D(InternalTransitionDataClassPointer->CharacterTransform, result);

		return result;
	}

	void TransitionDataClass::CharacterTransform::set(Matrix3D value)
	{
		Matrix3D::ManagedToUnmanagedMatrix3D(value, InternalTransitionDataClassPointer->CharacterTransform);
	}

	bool TransitionDataClass::InternalDestroyPointer()
	{
		Imports::DestroyTransitionDataClass(InternalTransitionDataClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::TransitionDataClass *TransitionDataClass::InternalTransitionDataClassPointer::get()
	{
		return reinterpret_cast<::TransitionDataClass *>(Pointer.ToPointer());
	}

	TransitionGameObjDef::TransitionGameObjDef(IntPtr pointer)
		: BaseGameObjDef(pointer)
	{

	}

	IntPtr TransitionGameObjDef::TransitionGameObjDefPointer::get()
	{
		return IntPtr(InternalTransitionGameObjDefPointer);
	}

	IDynamicVectorClass<ITransitionDataClass ^> ^TransitionGameObjDef::Transitions::get()
	{
		return gcnew TransitionDataClassPtrDynamicVectorClass(IntPtr(&InternalTransitionGameObjDefPointer->Get_Transitions()));
	}

	void TransitionGameObjDef::Transitions::set(IDynamicVectorClass<ITransitionDataClass ^> ^value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto &transitions = InternalTransitionGameObjDefPointer->Get_Transitions();

		transitions = *reinterpret_cast<::DynamicVectorClass<::TransitionDataClass *> *>(value->Pointer.ToPointer());
	}

	::BaseGameObjDef *TransitionGameObjDef::InternalBaseGameObjDefPointer::get()
	{
		return InternalTransitionGameObjDefPointer;
	}

	::TransitionGameObjDef *TransitionGameObjDef::InternalTransitionGameObjDefPointer::get()
	{
		return reinterpret_cast<::TransitionGameObjDef *>(Pointer.ToPointer());
	}
}