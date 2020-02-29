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
#include "MTransitionGameObj.h"

#include "MTransitionGameObjDef.h"
#include "MMatrix3D.h"
#include "MTransitionInstanceClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <TransitionGameObj.h>
#include <TransitionGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	TransitionGameObj::TransitionGameObj(IntPtr pointer)
		: BaseGameObj(pointer)
	{

	}

	ITransitionInstanceClass^ TransitionGameObj::GetTransition(int trans)
	{
		if (trans < 0 || trans >= InternalTransitionGameObjPointer->Get_Transition_Count())
		{
			throw gcnew ArgumentOutOfRangeException("trans");
		}

		auto result = InternalTransitionGameObjPointer->Get_Transition(trans);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew TransitionInstanceClass(IntPtr(result));
		}
	}

	IntPtr TransitionGameObj::TransitionGameObjPointer::get()
	{
		return IntPtr(InternalTransitionGameObjPointer);
	}

	ITransitionGameObjDef^ TransitionGameObj::Definition::get()
	{
		auto result = DefinitionClass::CreateDefinitionClassWrapper(&InternalTransitionGameObjPointer->Get_Definition());
		if (result != nullptr)
		{
			return safe_cast<ITransitionGameObjDef^>(result);
		}

		return gcnew TransitionGameObjDef(IntPtr(const_cast<::TransitionGameObjDef*>(&InternalTransitionGameObjPointer->Get_Definition())));
	}

	Matrix3D TransitionGameObj::Transform::get()
	{
		Matrix3D result;

		Matrix3D::UnmanagedToManagedMatrix3D(InternalTransitionGameObjPointer->Get_Transform(), result);

		return result;
	}

	void TransitionGameObj::Transform::set(Matrix3D value)
	{
		::Matrix3D tmp;

		Matrix3D::ManagedToUnmanagedMatrix3D(value, tmp);

		InternalTransitionGameObjPointer->Set_Transform(tmp);
	}

	int TransitionGameObj::TransitionCount::get()
	{
		return InternalTransitionGameObjPointer->Get_Transition_Count();
	}

	int TransitionGameObj::LadderIndex::get()
	{
		return InternalTransitionGameObjPointer->Get_Ladder_Index();
	}

	::PostLoadableClass* TransitionGameObj::InternalPostLoadableClassPointer::get()
	{
		return InternalTransitionGameObjPointer;
	}

	::PersistClass* TransitionGameObj::InternalPersistClassPointer::get()
	{
		return InternalTransitionGameObjPointer;
	}

	::BaseGameObj* TransitionGameObj::InternalBaseGameObjPointer::get()
	{
		return InternalTransitionGameObjPointer;
	}

	::TransitionGameObj* TransitionGameObj::InternalTransitionGameObjPointer::get()
	{
		return reinterpret_cast<::TransitionGameObj*>(Pointer.ToPointer());
	}
}