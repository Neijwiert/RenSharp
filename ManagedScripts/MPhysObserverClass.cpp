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
#include "MPhysObserverClass.h"

#include "Imports.h"
#include "UnmanagedContainer.h"
#include "MPhysClass.h"
#include "MDamageableGameObj.h"
#include "MPhysicalGameObj.h"
#include "MBuildingGameObj.h"

namespace RenSharp
{
	PhysObserverClass::PhysObserverClass()
		: AbstractUnmanagedObject(IntPtr(Imports::CreatePhysObserverClass()))
	{

	}

	PhysObserverClass::PhysObserverClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool PhysObserverClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IPhysObserverClass ^otherThis = dynamic_cast<IPhysObserverClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return PhysObserverClassPointer.Equals(otherThis->PhysObserverClassPointer);
	}

	IUnmanagedContainer<IPhysObserverClass ^> ^PhysObserverClass::CreatePhysObserverClass()
	{
		return gcnew UnmanagedContainer<IPhysObserverClass ^>(gcnew PhysObserverClass());
	}

	int PhysObserverClass::CollisionOccurred(IntPtr event)
	{
		if (event == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("event");
		}

		return InternalPhysObserverClassPointer->Collision_Occurred(*reinterpret_cast<::CollisionEventClass *>(event.ToPointer()));
	}

	int PhysObserverClass::ObjectExpired(IPhysClass ^observedObj)
	{
		if (observedObj == nullptr || observedObj->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("observedObj");
		}

		return InternalPhysObserverClassPointer->Object_Expired(reinterpret_cast<::PhysClass *>(observedObj->PhysClassPointer.ToPointer()));
	}

	void PhysObserverClass::ObjectRemovedFromScene(IPhysClass ^observedObj)
	{
		if (observedObj == nullptr || observedObj->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("observedObj");
		}

		InternalPhysObserverClassPointer->Object_Removed_From_Scene(reinterpret_cast<::PhysClass *>(observedObj->PhysClassPointer.ToPointer()));
	}

	void PhysObserverClass::ObjectShatteredSomething(IPhysClass ^observedObj, IPhysClass ^shatteredObj, int surfaceType)
	{
		if (observedObj == nullptr || observedObj->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("observedObj");
		}
		else if (shatteredObj == nullptr || shatteredObj->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("shatteredObj");
		}

		InternalPhysObserverClassPointer->Object_Shattered_Something(
			reinterpret_cast<::PhysClass *>(observedObj->PhysClassPointer.ToPointer()),
			reinterpret_cast<::PhysClass *>(shatteredObj->PhysClassPointer.ToPointer()),
			surfaceType);
	}

	IntPtr PhysObserverClass::PhysObserverClassPointer::get()
	{
		return IntPtr(InternalPhysObserverClassPointer);
	}

	bool PhysObserverClass::InternalDestroyPointer()
	{
		Imports::DestroyPhysObserverClass(InternalPhysObserverClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::PhysObserverClass *PhysObserverClass::InternalPhysObserverClassPointer::get()
	{
		return reinterpret_cast<::PhysObserverClass *>(Pointer.ToPointer());
	}

	CombatPhysObserverClass::CombatPhysObserverClass()
		: PhysObserverClass(IntPtr(Imports::CreateCombatPhysObserverClass()))
	{

	}

	CombatPhysObserverClass::CombatPhysObserverClass(IntPtr pointer)
		: PhysObserverClass(pointer)
	{

	}

	ICombatPhysObserverClass^ CombatPhysObserverClass::CreateCombatPhysObserverClassWrapper(IntPtr combatPhysObserverClassPtr)
	{
		return CreateCombatPhysObserverClassWrapper(reinterpret_cast<::CombatPhysObserverClass*>(combatPhysObserverClassPtr.ToPointer()));
	}

	IUnmanagedContainer<ICombatPhysObserverClass ^> ^CombatPhysObserverClass::CreateCombatPhysObserverClass()
	{
		return gcnew UnmanagedContainer<ICombatPhysObserverClass ^>(gcnew CombatPhysObserverClass());
	}

	IntPtr CombatPhysObserverClass::CombatPhysObserverClassPointer::get()
	{
		return IntPtr(InternalCombatPhysObserverClassPointer);
	}

	ICombatPhysObserverClass^ CombatPhysObserverClass::CreateCombatPhysObserverClassWrapper(::CombatPhysObserverClass* combatPhysObserverClassPtr)
	{
		if (combatPhysObserverClassPtr == nullptr)
		{
			throw gcnew ArgumentNullException("combatPhysObserverClassPtr");
		}

		auto buildingGameObjPtr = combatPhysObserverClassPtr->As_BuildingGameObj();
		if (buildingGameObjPtr != nullptr)
		{
			return safe_cast<ICombatPhysObserverClass^>(BaseGameObj::CreateBaseGameObjWrapper(buildingGameObjPtr));
		}

		auto physicalGameObjPtr = combatPhysObserverClassPtr->As_PhysicalGameObj();
		if (physicalGameObjPtr != nullptr)
		{
			return safe_cast<ICombatPhysObserverClass^>(BaseGameObj::CreateBaseGameObjWrapper(physicalGameObjPtr));
		}

		return gcnew CombatPhysObserverClass(IntPtr(combatPhysObserverClassPtr));
	}

	bool CombatPhysObserverClass::InternalDestroyPointer()
	{
		Imports::DestroyCombatPhysObserverClass(InternalCombatPhysObserverClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::PhysObserverClass *CombatPhysObserverClass::InternalPhysObserverClassPointer::get()
	{
		return InternalCombatPhysObserverClassPointer;
	}

	::CombatPhysObserverClass *CombatPhysObserverClass::InternalCombatPhysObserverClassPointer::get()
	{
		return reinterpret_cast<::CombatPhysObserverClass *>(Pointer.ToPointer());
	}
}