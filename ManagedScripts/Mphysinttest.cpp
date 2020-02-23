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
#include "Mphysinttest.h"

#include "MMeshClass.h"
#include "MPhysClassMultiListClass.h"
#include "Imports.h"
#include "UnmanagedContainer.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <multilist.h>
#include <PhysClass.h>
#include <physinttest.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	PhysAABoxIntersectionTestClassRef::PhysAABoxIntersectionTestClassRef(AABoxClass box, CollisionGroupType colGroup, RenSharp::CollisionType colType)
	{
		::AABoxClass boxBox;

		AABoxClass::ManagedToUnmanagedAABoxClass(box, boxBox);

		Pointer = IntPtr(Imports::CreatePhysAABoxIntersectionTestClass(&boxBox, static_cast<::Collision_Group_Type>(colGroup), static_cast<::Collision_Type>(colType)));
	}

	PhysAABoxIntersectionTestClassRef::PhysAABoxIntersectionTestClassRef()
	{

	}

	PhysAABoxIntersectionTestClassRef::PhysAABoxIntersectionTestClassRef(IntPtr pointer)
		: AABoxIntersectionTestClassRef(pointer)
	{

	}

	IUnmanagedContainer<IPhysAABoxIntersectionTestClass ^> ^PhysAABoxIntersectionTestClassRef::CreatePhysAABoxIntersectionTestClassRef(AABoxClass box, CollisionGroupType colGroup, RenSharp::CollisionType colType)
	{
		return gcnew UnmanagedContainer<IPhysAABoxIntersectionTestClass ^>(gcnew PhysAABoxIntersectionTestClassRef(box, colGroup, colType));
	}

	AABoxIntersectionTestClass ^PhysAABoxIntersectionTestClassRef::ToAABoxIntersectionTestClass()
	{
		return ToPhysAABoxIntersectionTestClass();
	}

	PhysAABoxIntersectionTestClass ^PhysAABoxIntersectionTestClassRef::ToPhysAABoxIntersectionTestClass()
	{
		return gcnew PhysAABoxIntersectionTestClass(this);
	}

	void PhysAABoxIntersectionTestClassRef::AddIntersectedObject(IPhysClass ^obj)
	{
		if (obj == nullptr || obj->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalPhysAABoxIntersectionTestClassPointer->Add_Intersected_Object(
			reinterpret_cast<::PhysClass *>(obj->PhysClassPointer.ToPointer()));
	}

	IntPtr PhysAABoxIntersectionTestClassRef::PhysAABoxIntersectionTestClassPointer::get()
	{
		return IntPtr(InternalPhysAABoxIntersectionTestClassPointer);
	}

	CollisionGroupType PhysAABoxIntersectionTestClassRef::CollisionGroup::get()
	{
		return static_cast<CollisionGroupType>(InternalPhysAABoxIntersectionTestClassPointer->CollisionGroup);
	}

	void PhysAABoxIntersectionTestClassRef::CollisionGroup::set(CollisionGroupType value)
	{
		InternalPhysAABoxIntersectionTestClassPointer->CollisionGroup = static_cast<::Collision_Group_Type>(value);
	}

	bool PhysAABoxIntersectionTestClassRef::CheckStaticObjs::get()
	{
		return InternalPhysAABoxIntersectionTestClassPointer->CheckStaticObjs;
	}

	void PhysAABoxIntersectionTestClassRef::CheckStaticObjs::set(bool value)
	{
		InternalPhysAABoxIntersectionTestClassPointer->CheckStaticObjs = value;
	}

	bool PhysAABoxIntersectionTestClassRef::CheckDynamicObjs::get()
	{
		return InternalPhysAABoxIntersectionTestClassPointer->CheckDynamicObjs;
	}

	void PhysAABoxIntersectionTestClassRef::CheckDynamicObjs::set(bool value)
	{
		InternalPhysAABoxIntersectionTestClassPointer->CheckDynamicObjs = value;
	}

	bool PhysAABoxIntersectionTestClassRef::InternalDestroyPointer()
	{
		Imports::DestroyPhysAABoxIntersectionTestClass(InternalPhysAABoxIntersectionTestClassPointer);
		Pointer = IntPtr::Zero;
		
		return true;
	}

	::AABoxIntersectionTestClass *PhysAABoxIntersectionTestClassRef::InternalAABoxIntersectionTestClassPointer::get()
	{
		return InternalPhysAABoxIntersectionTestClassPointer;
	}

	::PhysAABoxIntersectionTestClass *PhysAABoxIntersectionTestClassRef::InternalPhysAABoxIntersectionTestClassPointer::get()
	{
		return reinterpret_cast<::PhysAABoxIntersectionTestClass *>(Pointer.ToPointer());
	}

	RenSharpPhysAABoxIntersectionTestClass::RenSharpPhysAABoxIntersectionTestClass(AABoxClass box, CollisionGroupType colGroup, RenSharp::CollisionType colType, bool enableResultList)
	{
		::AABoxClass boxBox;

		AABoxClass::ManagedToUnmanagedAABoxClass(box, boxBox);

		Pointer = IntPtr(Imports::CreateRenSharpPhysAABoxIntersectionTestClass(&boxBox, static_cast<::Collision_Group_Type>(colGroup), static_cast<::Collision_Type>(colType), enableResultList));
	}

	RenSharpPhysAABoxIntersectionTestClass::RenSharpPhysAABoxIntersectionTestClass(PhysAABoxIntersectionTestClass ^intersectionTestClass)
	{
		if (intersectionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		::AABoxClass boxBox;

		AABoxClass::ManagedToUnmanagedAABoxClass(intersectionTestClass->Box, boxBox);

		Pointer = IntPtr(Imports::CreateRenSharpPhysAABoxIntersectionTestClass(&boxBox, static_cast<::Collision_Group_Type>(intersectionTestClass->CollisionGroup), static_cast<::Collision_Type>(intersectionTestClass->CollisionType), true));

		CheckStaticObjs = intersectionTestClass->CheckStaticObjs;
		CheckDynamicObjs = intersectionTestClass->CheckDynamicObjs;
	}

	RenSharpPhysAABoxIntersectionTestClass::RenSharpPhysAABoxIntersectionTestClass(IntPtr pointer)
		: PhysAABoxIntersectionTestClassRef(pointer)
	{

	}

	IUnmanagedContainer<IPhysAABoxIntersectionTestClass ^> ^RenSharpPhysAABoxIntersectionTestClass::CreateRenSharpPhysAABoxIntersectionTestClass(
		AABoxClass box,
		CollisionGroupType colGroup,
		RenSharp::CollisionType colType,
		bool enableResultList)
	{
		return gcnew UnmanagedContainer<IPhysAABoxIntersectionTestClass ^>(gcnew RenSharpPhysAABoxIntersectionTestClass(box, colGroup, colType, enableResultList));
	}

	IUnmanagedContainer<IPhysAABoxIntersectionTestClass ^> ^RenSharpPhysAABoxIntersectionTestClass::CreateRenSharpPhysAABoxIntersectionTestClass(
		PhysAABoxIntersectionTestClass ^intersectionTestClass)
	{
		return gcnew UnmanagedContainer<IPhysAABoxIntersectionTestClass ^>(gcnew RenSharpPhysAABoxIntersectionTestClass(intersectionTestClass));
	}

	IntPtr RenSharpPhysAABoxIntersectionTestClass::RenSharpPhysAABoxIntersectionTestClassPointer::get()
	{
		return IntPtr(InternalRenSharpPhysAABoxIntersectionTestClassPointer);
	}

	IMultiListClass<IPhysClass ^> ^RenSharpPhysAABoxIntersectionTestClass::IntersectedObjects::get()
	{
		auto result = Imports::GetRenSharpPhysAABoxIntersectionResultList(InternalRenSharpPhysAABoxIntersectionTestClassPointer);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PhysClassMultiListClass(IntPtr(result));
		}
	}

	bool RenSharpPhysAABoxIntersectionTestClass::InternalDestroyPointer()
	{
		Imports::DestroyRenSharpPhysAABoxIntersectionTestClass(InternalRenSharpPhysAABoxIntersectionTestClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::RenSharpPhysAABoxIntersectionTestClass *RenSharpPhysAABoxIntersectionTestClass::InternalRenSharpPhysAABoxIntersectionTestClassPointer::get()
	{
		return reinterpret_cast<::RenSharpPhysAABoxIntersectionTestClass *>(Pointer.ToPointer());
	}

	PhysAABoxIntersectionTestClass::PhysAABoxIntersectionTestClass(AABoxClass box, CollisionGroupType colGroup, RenSharp::CollisionType colType)
		: AABoxIntersectionTestClass(box, colType), collisionGroup(colGroup), checkStaticObjs(true), checkDynamicObjs(true), intersectedObjects(nullptr)
	{

	}

	PhysAABoxIntersectionTestClass::PhysAABoxIntersectionTestClass(IPhysAABoxIntersectionTestClass ^intersectionTestClass)
		: AABoxIntersectionTestClass(intersectionTestClass)
	{
		if (intersectionTestClass == nullptr || intersectionTestClass->PhysAABoxIntersectionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		collisionGroup = intersectionTestClass->CollisionGroup;
		checkStaticObjs = intersectionTestClass->CheckStaticObjs;
		checkDynamicObjs = intersectionTestClass->CheckDynamicObjs;
		intersectedObjects = gcnew Generic::LinkedList<IPhysClass ^>();

		auto renSharpIntersectionTestClass = dynamic_cast<RenSharpPhysAABoxIntersectionTestClass ^>(intersectionTestClass);
		if (renSharpIntersectionTestClass != nullptr)
		{
			IntersectedObjects = renSharpIntersectionTestClass->IntersectedObjects;
		}
	}

	PhysAABoxIntersectionTestClass::PhysAABoxIntersectionTestClass(PhysAABoxIntersectionTestClass ^intersectionTestClass) 
		: AABoxIntersectionTestClass(intersectionTestClass)
	{
		if (intersectionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		collisionGroup = intersectionTestClass->CollisionGroup;
		checkStaticObjs = intersectionTestClass->CheckStaticObjs;
		checkDynamicObjs = intersectionTestClass->CheckDynamicObjs;
		intersectedObjects = gcnew Generic::LinkedList<IPhysClass ^>();

		IntersectedObjects = intersectionTestClass->IntersectedObjects;
	}

	void PhysAABoxIntersectionTestClass::CopyFrom(IPhysAABoxIntersectionTestClass ^intersectionTestClass)
	{
		if (intersectionTestClass == nullptr || intersectionTestClass->PhysAABoxIntersectionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		AABoxIntersectionTestClass::CopyFrom(intersectionTestClass);

		collisionGroup = intersectionTestClass->CollisionGroup;
		checkStaticObjs = intersectionTestClass->CheckStaticObjs;
		checkDynamicObjs = intersectionTestClass->CheckDynamicObjs;

		auto renSharpIntersectionTestClass = dynamic_cast<RenSharpPhysAABoxIntersectionTestClass ^>(intersectionTestClass);
		if (renSharpIntersectionTestClass != nullptr)
		{
			IntersectedObjects = renSharpIntersectionTestClass->IntersectedObjects;
		}
	}

	void PhysAABoxIntersectionTestClass::CopyFrom(PhysAABoxIntersectionTestClass ^intersectionTestClass)
	{
		if (intersectionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		AABoxIntersectionTestClass::CopyFrom(intersectionTestClass);

		collisionGroup = intersectionTestClass->CollisionGroup;
		checkStaticObjs = intersectionTestClass->CheckStaticObjs;
		checkDynamicObjs = intersectionTestClass->CheckDynamicObjs;

		IntersectedObjects = intersectionTestClass->IntersectedObjects;
	}

	CollisionGroupType PhysAABoxIntersectionTestClass::CollisionGroup::get()
	{
		return collisionGroup;
	}

	void PhysAABoxIntersectionTestClass::CollisionGroup::set(CollisionGroupType value)
	{
		collisionGroup = value;
	}

	bool PhysAABoxIntersectionTestClass::CheckStaticObjs::get()
	{
		return checkStaticObjs;
	}

	void PhysAABoxIntersectionTestClass::CheckStaticObjs::set(bool value)
	{
		checkStaticObjs = value;
	}

	bool PhysAABoxIntersectionTestClass::CheckDynamicObjs::get()
	{
		return checkDynamicObjs;
	}

	void PhysAABoxIntersectionTestClass::CheckDynamicObjs::set(bool value)
	{
		checkDynamicObjs = value;
	}

	Generic::ICollection<IPhysClass ^> ^PhysAABoxIntersectionTestClass::IntersectedObjects::get()
	{
		return intersectedObjects;
	}

	void PhysAABoxIntersectionTestClass::IntersectedObjects::set(Generic::ICollection<IPhysClass ^> ^value)
	{
		intersectedObjects->Clear();

		if (value != nullptr)
		{
			auto multiListValue = dynamic_cast<IMultiListClass<IPhysClass ^> ^>(value);
			if (multiListValue != nullptr && multiListValue->Pointer.ToPointer() == nullptr)
			{
				return;
			}

			for each (auto phys in value)
			{
				intersectedObjects->Add(phys);
			}
		}
	}

	PhysOBBoxIntersectionTestClassRef::PhysOBBoxIntersectionTestClassRef(OBBoxClass box, CollisionGroupType colGroup, RenSharp::CollisionType colType)
	{
		::OBBoxClass boxBox;

		OBBoxClass::ManagedToUnmanagedOBBoxClass(box, boxBox);

		Pointer = IntPtr(Imports::CreatePhysOBBoxIntersectionTestClass(&boxBox, static_cast<::Collision_Group_Type>(colGroup), static_cast<::Collision_Type>(colType)));
	}

	PhysOBBoxIntersectionTestClassRef::PhysOBBoxIntersectionTestClassRef()
	{

	}

	PhysOBBoxIntersectionTestClassRef::PhysOBBoxIntersectionTestClassRef(IntPtr pointer)
		: OBBoxIntersectionTestClassRef(pointer)
	{

	}

	IUnmanagedContainer<IPhysOBBoxIntersectionTestClass ^> ^PhysOBBoxIntersectionTestClassRef::CreatePhysOBBoxIntersectionTestClassRef(OBBoxClass box, CollisionGroupType colGroup, RenSharp::CollisionType colType)
	{
		return gcnew UnmanagedContainer<IPhysOBBoxIntersectionTestClass ^>(gcnew PhysOBBoxIntersectionTestClassRef(box, colGroup, colType));
	}

	OBBoxIntersectionTestClass ^PhysOBBoxIntersectionTestClassRef::ToOBBoxIntersectionTestClass()
	{
		return ToPhysOBBoxIntersectionTestClass();
	}

	PhysOBBoxIntersectionTestClass ^PhysOBBoxIntersectionTestClassRef::ToPhysOBBoxIntersectionTestClass()
	{
		return gcnew PhysOBBoxIntersectionTestClass(this);
	}

	void PhysOBBoxIntersectionTestClassRef::AddIntersectedObject(IPhysClass ^obj)
	{
		if (obj == nullptr || obj->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalPhysOBBoxIntersectionTestClassPointer->Add_Intersected_Object(
			reinterpret_cast<::PhysClass *>(obj->PhysClassPointer.ToPointer()));
	}

	IntPtr PhysOBBoxIntersectionTestClassRef::PhysOBBoxIntersectionTestClassPointer::get()
	{
		return IntPtr(InternalPhysOBBoxIntersectionTestClassPointer);
	}

	CollisionGroupType PhysOBBoxIntersectionTestClassRef::CollisionGroup::get()
	{
		return static_cast<CollisionGroupType>(InternalPhysOBBoxIntersectionTestClassPointer->CollisionGroup);
	}

	void PhysOBBoxIntersectionTestClassRef::CollisionGroup::set(CollisionGroupType value)
	{
		InternalPhysOBBoxIntersectionTestClassPointer->CollisionGroup = static_cast<::Collision_Group_Type>(value);
	}

	bool PhysOBBoxIntersectionTestClassRef::CheckStaticObjs::get()
	{
		return InternalPhysOBBoxIntersectionTestClassPointer->CheckStaticObjs;
	}

	void PhysOBBoxIntersectionTestClassRef::CheckStaticObjs::set(bool value)
	{
		InternalPhysOBBoxIntersectionTestClassPointer->CheckStaticObjs = value;
	}

	bool PhysOBBoxIntersectionTestClassRef::CheckDynamicObjs::get()
	{
		return InternalPhysOBBoxIntersectionTestClassPointer->CheckDynamicObjs;
	}

	void PhysOBBoxIntersectionTestClassRef::CheckDynamicObjs::set(bool value)
	{
		InternalPhysOBBoxIntersectionTestClassPointer->CheckDynamicObjs = value;
	}

	bool PhysOBBoxIntersectionTestClassRef::InternalDestroyPointer()
	{
		Imports::DestroyPhysOBBoxIntersectionTestClass(InternalPhysOBBoxIntersectionTestClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::OBBoxIntersectionTestClass *PhysOBBoxIntersectionTestClassRef::InternalOBBoxIntersectionTestClassPointer::get()
	{
		return InternalPhysOBBoxIntersectionTestClassPointer;
	}

	::PhysOBBoxIntersectionTestClass *PhysOBBoxIntersectionTestClassRef::InternalPhysOBBoxIntersectionTestClassPointer::get()
	{
		return reinterpret_cast<::PhysOBBoxIntersectionTestClass *>(Pointer.ToPointer());
	}

	RenSharpPhysOBBoxIntersectionTestClass::RenSharpPhysOBBoxIntersectionTestClass(OBBoxClass box, CollisionGroupType colGroup, RenSharp::CollisionType colType, bool enableResultList)
	{
		::OBBoxClass boxBox;

		OBBoxClass::ManagedToUnmanagedOBBoxClass(box, boxBox);

		Pointer = IntPtr(Imports::CreateRenSharpPhysOBBoxIntersectionTestClass(&boxBox, static_cast<::Collision_Group_Type>(colGroup), static_cast<::Collision_Type>(colType), enableResultList));
	}

	RenSharpPhysOBBoxIntersectionTestClass::RenSharpPhysOBBoxIntersectionTestClass(PhysOBBoxIntersectionTestClass ^intersectionTestClass)
	{
		if (intersectionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		::OBBoxClass boxBox;

		OBBoxClass::ManagedToUnmanagedOBBoxClass(intersectionTestClass->Box, boxBox);

		Pointer = IntPtr(Imports::CreateRenSharpPhysOBBoxIntersectionTestClass(&boxBox, static_cast<::Collision_Group_Type>(intersectionTestClass->CollisionGroup), static_cast<::Collision_Type>(intersectionTestClass->CollisionType), true));

		CheckStaticObjs = intersectionTestClass->CheckStaticObjs;
		CheckDynamicObjs = intersectionTestClass->CheckDynamicObjs;
	}

	RenSharpPhysOBBoxIntersectionTestClass::RenSharpPhysOBBoxIntersectionTestClass(IntPtr pointer)
		: PhysOBBoxIntersectionTestClassRef(pointer)
	{

	}

	IUnmanagedContainer<IPhysOBBoxIntersectionTestClass ^> ^RenSharpPhysOBBoxIntersectionTestClass::CreateRenSharpPhysOBBoxIntersectionTestClass(
		OBBoxClass box,
		CollisionGroupType colGroup,
		RenSharp::CollisionType colType,
		bool enableResultList)
	{
		return gcnew UnmanagedContainer<IPhysOBBoxIntersectionTestClass ^>(gcnew RenSharpPhysOBBoxIntersectionTestClass(box, colGroup, colType, enableResultList));
	}

	IUnmanagedContainer<IPhysOBBoxIntersectionTestClass ^> ^RenSharpPhysOBBoxIntersectionTestClass::CreateRenSharpPhysOBBoxIntersectionTestClass(
		PhysOBBoxIntersectionTestClass ^intersectionTestClass)
	{
		return gcnew UnmanagedContainer<IPhysOBBoxIntersectionTestClass ^>(gcnew RenSharpPhysOBBoxIntersectionTestClass(intersectionTestClass));
	}

	IntPtr RenSharpPhysOBBoxIntersectionTestClass::RenSharpPhysOBBoxIntersectionTestClassPointer::get()
	{
		return IntPtr(InternalRenSharpPhysOBBoxIntersectionTestClassPointer);
	}

	IMultiListClass<IPhysClass ^> ^RenSharpPhysOBBoxIntersectionTestClass::IntersectedObjects::get()
	{
		auto result = Imports::GetRenSharpPhysOBBoxIntersectionTestClassResultList(InternalRenSharpPhysOBBoxIntersectionTestClassPointer);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PhysClassMultiListClass(IntPtr(result));
		}
	}

	bool RenSharpPhysOBBoxIntersectionTestClass::InternalDestroyPointer()
	{
		Imports::DestroyRenSharpPhysOBBoxIntersectionTestClass(InternalRenSharpPhysOBBoxIntersectionTestClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::RenSharpPhysOBBoxIntersectionTestClass *RenSharpPhysOBBoxIntersectionTestClass::InternalRenSharpPhysOBBoxIntersectionTestClassPointer::get()
	{
		return reinterpret_cast<::RenSharpPhysOBBoxIntersectionTestClass *>(Pointer.ToPointer());
	}

	PhysOBBoxIntersectionTestClass::PhysOBBoxIntersectionTestClass(OBBoxClass box, CollisionGroupType colGroup, RenSharp::CollisionType colType)
		: OBBoxIntersectionTestClass(box, colType), collisionGroup(colGroup), checkStaticObjs(true), checkDynamicObjs(true), intersectedObjects(nullptr)
	{

	}

	PhysOBBoxIntersectionTestClass::PhysOBBoxIntersectionTestClass(IPhysOBBoxIntersectionTestClass ^intersectionTestClass)
		: OBBoxIntersectionTestClass(intersectionTestClass)
	{
		if (intersectionTestClass == nullptr || intersectionTestClass->PhysOBBoxIntersectionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		collisionGroup = intersectionTestClass->CollisionGroup;
		checkStaticObjs = intersectionTestClass->CheckStaticObjs;
		checkDynamicObjs = intersectionTestClass->CheckDynamicObjs;
		intersectedObjects = gcnew Generic::LinkedList<IPhysClass ^>();

		auto renSharpIntersectionTestClass = dynamic_cast<RenSharpPhysOBBoxIntersectionTestClass ^>(intersectionTestClass);
		if (renSharpIntersectionTestClass != nullptr)
		{
			IntersectedObjects = renSharpIntersectionTestClass->IntersectedObjects;
		}
	}

	PhysOBBoxIntersectionTestClass::PhysOBBoxIntersectionTestClass(PhysOBBoxIntersectionTestClass ^intersectionTestClass)
		: OBBoxIntersectionTestClass(intersectionTestClass)
	{
		if (intersectionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		collisionGroup = intersectionTestClass->CollisionGroup;
		checkStaticObjs = intersectionTestClass->CheckStaticObjs;
		checkDynamicObjs = intersectionTestClass->CheckDynamicObjs;
		intersectedObjects = gcnew Generic::LinkedList<IPhysClass ^>();

		IntersectedObjects = intersectionTestClass->IntersectedObjects;
	}

	void PhysOBBoxIntersectionTestClass::CopyFrom(IPhysOBBoxIntersectionTestClass ^intersectionTestClass)
	{
		if (intersectionTestClass == nullptr || intersectionTestClass->PhysOBBoxIntersectionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		OBBoxIntersectionTestClass::CopyFrom(intersectionTestClass);

		collisionGroup = intersectionTestClass->CollisionGroup;
		checkStaticObjs = intersectionTestClass->CheckStaticObjs;
		checkDynamicObjs = intersectionTestClass->CheckDynamicObjs;

		auto renSharpIntersectionTestClass = dynamic_cast<RenSharpPhysOBBoxIntersectionTestClass ^>(intersectionTestClass);
		if (renSharpIntersectionTestClass != nullptr)
		{
			IntersectedObjects = renSharpIntersectionTestClass->IntersectedObjects;
		}
	}

	void PhysOBBoxIntersectionTestClass::CopyFrom(PhysOBBoxIntersectionTestClass ^intersectionTestClass)
	{
		if (intersectionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		OBBoxIntersectionTestClass::CopyFrom(intersectionTestClass);

		collisionGroup = intersectionTestClass->CollisionGroup;
		checkStaticObjs = intersectionTestClass->CheckStaticObjs;
		checkDynamicObjs = intersectionTestClass->CheckDynamicObjs;

		IntersectedObjects = intersectionTestClass->IntersectedObjects;
	}

	CollisionGroupType PhysOBBoxIntersectionTestClass::CollisionGroup::get()
	{
		return collisionGroup;
	}

	void PhysOBBoxIntersectionTestClass::CollisionGroup::set(CollisionGroupType value)
	{
		collisionGroup = value;
	}

	bool PhysOBBoxIntersectionTestClass::CheckStaticObjs::get()
	{
		return checkStaticObjs;
	}

	void PhysOBBoxIntersectionTestClass::CheckStaticObjs::set(bool value)
	{
		checkStaticObjs = value;
	}

	bool PhysOBBoxIntersectionTestClass::CheckDynamicObjs::get()
	{
		return checkDynamicObjs;
	}

	void PhysOBBoxIntersectionTestClass::CheckDynamicObjs::set(bool value)
	{
		checkDynamicObjs = value;
	}

	Generic::ICollection<IPhysClass ^> ^PhysOBBoxIntersectionTestClass::IntersectedObjects::get()
	{
		return intersectedObjects;
	}

	void PhysOBBoxIntersectionTestClass::IntersectedObjects::set(Generic::ICollection<IPhysClass ^> ^value)
	{
		intersectedObjects->Clear();

		if (value != nullptr)
		{
			auto multiListValue = dynamic_cast<IMultiListClass<IPhysClass ^> ^>(value);
			if (multiListValue != nullptr && multiListValue->Pointer.ToPointer() == nullptr)
			{
				return;
			}

			for each (auto phys in value)
			{
				intersectedObjects->Add(phys);
			}
		}
	}

	PhysMeshIntersectionTestClassRef::PhysMeshIntersectionTestClassRef(IMeshClass ^mesh, CollisionGroupType colGroup, RenSharp::CollisionType colType)
	{
		::MeshClass *meshPtr;
		if (mesh == nullptr || mesh->MeshClassPointer.ToPointer() == nullptr)
		{
			meshPtr = nullptr;
		}
		else
		{
			meshPtr = reinterpret_cast<::MeshClass *>(mesh->MeshClassPointer.ToPointer());
		}

		Pointer = IntPtr(Imports::CreatePhysMeshIntersectionTestClass(meshPtr, static_cast<::Collision_Group_Type>(colGroup), static_cast<::Collision_Type>(colType)));
	}

	PhysMeshIntersectionTestClassRef::PhysMeshIntersectionTestClassRef()
	{

	}

	PhysMeshIntersectionTestClassRef::PhysMeshIntersectionTestClassRef(IntPtr pointer)
		: IntersectionTestClassRef(pointer)
	{

	}

	IUnmanagedContainer<IPhysMeshIntersectionTestClass ^> ^PhysMeshIntersectionTestClassRef::CreatePhysMeshIntersectionTestClassRef()
	{
		return gcnew UnmanagedContainer<IPhysMeshIntersectionTestClass ^>(gcnew PhysMeshIntersectionTestClassRef());
	}

	IntersectionTestClass ^PhysMeshIntersectionTestClassRef::ToIntersectionTestClass()
	{
		return ToPhysMeshIntersectionTestClass();
	}

	PhysMeshIntersectionTestClass ^PhysMeshIntersectionTestClassRef::ToPhysMeshIntersectionTestClass()
	{
		return gcnew PhysMeshIntersectionTestClass(this);
	}

	bool PhysMeshIntersectionTestClassRef::Cull(Vector3 min, Vector3 max)
	{
		::Vector3 minVec;
		::Vector3 maxVec;

		Vector3::ManagedToUnmanagedVector3(min, minVec);
		Vector3::ManagedToUnmanagedVector3(max, maxVec);

		return InternalPhysMeshIntersectionTestClassPointer->Cull(minVec, maxVec);
	}

	bool PhysMeshIntersectionTestClassRef::Cull(AABoxClass box)
	{
		::AABoxClass boxBox;

		AABoxClass::ManagedToUnmanagedAABoxClass(box, boxBox);

		return InternalPhysMeshIntersectionTestClassPointer->Cull(boxBox);
	}

	void PhysMeshIntersectionTestClassRef::AddIntersectedObject(IPhysClass ^obj)
	{
		if (obj == nullptr || obj->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalPhysMeshIntersectionTestClassPointer->Add_Intersected_Object(
			reinterpret_cast<::PhysClass *>(obj->PhysClassPointer.ToPointer()));
	}

	IntPtr PhysMeshIntersectionTestClassRef::PhysMeshIntersectionTestClassPointer::get()
	{
		return IntPtr(InternalPhysMeshIntersectionTestClassPointer);
	}

	IMeshClass ^PhysMeshIntersectionTestClassRef::Mesh::get()
	{
		auto result = InternalPhysMeshIntersectionTestClassPointer->Mesh;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew MeshClass(IntPtr(result));
		}
	}

	void PhysMeshIntersectionTestClassRef::Mesh::set(IMeshClass ^value)
	{
		REF_PTR_RELEASE(InternalPhysMeshIntersectionTestClassPointer->Mesh);

		if (value == nullptr || value->MeshClassPointer.ToPointer() == nullptr)
		{
			InternalPhysMeshIntersectionTestClassPointer->Mesh = nullptr;
		}
		else
		{
			auto mesh = reinterpret_cast<::MeshClass *>(value->MeshClassPointer.ToPointer());

			mesh->Add_Ref();
			InternalPhysMeshIntersectionTestClassPointer->Mesh = mesh;
		}
	}

	AABoxClass PhysMeshIntersectionTestClassRef::BoundingBox::get()
	{
		AABoxClass result;

		AABoxClass::UnmanagedToManagedAABoxClass(InternalPhysMeshIntersectionTestClassPointer->BoundingBox, result);

		return result;
	}

	void PhysMeshIntersectionTestClassRef::BoundingBox::set(AABoxClass value)
	{
		AABoxClass::ManagedToUnmanagedAABoxClass(value, InternalPhysMeshIntersectionTestClassPointer->BoundingBox);
	}

	CollisionGroupType PhysMeshIntersectionTestClassRef::CollisionGroup::get()
	{
		return static_cast<CollisionGroupType>(InternalPhysMeshIntersectionTestClassPointer->CollisionGroup);
	}

	void PhysMeshIntersectionTestClassRef::CollisionGroup::set(CollisionGroupType value)
	{
		InternalPhysMeshIntersectionTestClassPointer->CollisionGroup = static_cast<::Collision_Group_Type>(value);
	}

	bool PhysMeshIntersectionTestClassRef::CheckStaticObjs::get()
	{
		return InternalPhysMeshIntersectionTestClassPointer->CheckStaticObjs;
	}

	void PhysMeshIntersectionTestClassRef::CheckStaticObjs::set(bool value)
	{
		InternalPhysMeshIntersectionTestClassPointer->CheckStaticObjs = value;
	}

	bool PhysMeshIntersectionTestClassRef::CheckDynamicObjs::get()
	{
		return InternalPhysMeshIntersectionTestClassPointer->CheckDynamicObjs;
	}

	void PhysMeshIntersectionTestClassRef::CheckDynamicObjs::set(bool value)
	{
		InternalPhysMeshIntersectionTestClassPointer->CheckDynamicObjs = value;
	}

	bool PhysMeshIntersectionTestClassRef::InternalDestroyPointer()
	{
		Imports::DestroyPhysMeshIntersectionTestClass(InternalPhysMeshIntersectionTestClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::IntersectionTestClass *PhysMeshIntersectionTestClassRef::InternalIntersectionTestClassPointer::get()
	{
		return InternalPhysMeshIntersectionTestClassPointer;
	}

	::PhysMeshIntersectionTestClass *PhysMeshIntersectionTestClassRef::InternalPhysMeshIntersectionTestClassPointer::get()
	{
		return reinterpret_cast<::PhysMeshIntersectionTestClass *>(Pointer.ToPointer());
	}

	RenSharpPhysMeshIntersectionTestClass::RenSharpPhysMeshIntersectionTestClass(IMeshClass ^mesh, CollisionGroupType colGroup, RenSharp::CollisionType colType, bool enableResultList)
	{
		if (mesh == nullptr || mesh->MeshClassPointer.ToPointer() == nullptr)
		{
			Pointer = IntPtr(Imports::CreateRenSharpPhysMeshIntersectionTestClass(nullptr, static_cast<::Collision_Group_Type>(colGroup), static_cast<::Collision_Type>(colType), enableResultList));
		}
		else
		{
			Pointer = IntPtr(Imports::CreateRenSharpPhysMeshIntersectionTestClass(
				reinterpret_cast<::MeshClass *>(mesh->MeshClassPointer.ToPointer()),
				static_cast<::Collision_Group_Type>(colGroup),
				static_cast<::Collision_Type>(colType),
				enableResultList));
		}
	}

	RenSharpPhysMeshIntersectionTestClass::RenSharpPhysMeshIntersectionTestClass(PhysMeshIntersectionTestClass ^intersectionTestClass)
	{
		if (intersectionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		auto mesh = intersectionTestClass->Mesh;
		if (mesh == nullptr || mesh->MeshClassPointer.ToPointer() == nullptr)
		{
			Pointer = IntPtr(Imports::CreateRenSharpPhysMeshIntersectionTestClass(
				nullptr,
				static_cast<::Collision_Group_Type>(intersectionTestClass->CollisionGroup),
				static_cast<::Collision_Type>(intersectionTestClass->CollisionType),
				true));
		}
		else
		{
			Pointer = IntPtr(Imports::CreateRenSharpPhysMeshIntersectionTestClass(
				reinterpret_cast<::MeshClass *>(mesh->MeshClassPointer.ToPointer()),
				static_cast<::Collision_Group_Type>(intersectionTestClass->CollisionGroup),
				static_cast<::Collision_Type>(intersectionTestClass->CollisionType),
				true));
		}

		BoundingBox = intersectionTestClass->BoundingBox;
		CheckStaticObjs = intersectionTestClass->CheckStaticObjs;
		CheckDynamicObjs = intersectionTestClass->CheckDynamicObjs;
	}

	RenSharpPhysMeshIntersectionTestClass::RenSharpPhysMeshIntersectionTestClass(IntPtr pointer)
		: PhysMeshIntersectionTestClassRef(pointer)
	{

	}

	IUnmanagedContainer<IPhysMeshIntersectionTestClass ^> ^RenSharpPhysMeshIntersectionTestClass::CreateRenSharpPhysMeshIntersectionTestClass(
		IMeshClass ^mesh,
		CollisionGroupType colGroup,
		RenSharp::CollisionType colType,
		bool enableResultList)
	{
		return gcnew UnmanagedContainer<IPhysMeshIntersectionTestClass ^>(gcnew RenSharpPhysMeshIntersectionTestClass(mesh, colGroup, colType, enableResultList));
	}

	IUnmanagedContainer<IPhysMeshIntersectionTestClass ^> ^RenSharpPhysMeshIntersectionTestClass::CreateRenSharpPhysMeshIntersectionTestClass(PhysMeshIntersectionTestClass ^intersectionTestClass)
	{
		return gcnew UnmanagedContainer<IPhysMeshIntersectionTestClass ^>(gcnew RenSharpPhysMeshIntersectionTestClass(intersectionTestClass));
	}

	IntPtr RenSharpPhysMeshIntersectionTestClass::RenSharpPhysMeshIntersectionTestClassPointer::get()
	{
		return IntPtr(InternalRenSharpPhysMeshIntersectionTestClassPointer);
	}

	IMultiListClass<IPhysClass ^> ^RenSharpPhysMeshIntersectionTestClass::IntersectedObjects::get()
	{
		auto result = Imports::GetRenSharpPhysMeshIntersectionTestClassResultList(InternalRenSharpPhysMeshIntersectionTestClassPointer);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PhysClassMultiListClass(IntPtr(result));
		}
	}

	bool RenSharpPhysMeshIntersectionTestClass::InternalDestroyPointer()
	{
		Imports::DestroyRenSharpPhysMeshIntersectionTestClass(InternalRenSharpPhysMeshIntersectionTestClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::RenSharpPhysMeshIntersectionTestClass *RenSharpPhysMeshIntersectionTestClass::InternalRenSharpPhysMeshIntersectionTestClassPointer::get()
	{
		return reinterpret_cast<::RenSharpPhysMeshIntersectionTestClass *>(Pointer.ToPointer());
	}

	PhysMeshIntersectionTestClass::PhysMeshIntersectionTestClass(IMeshClass ^mesh, CollisionGroupType colGroup, RenSharp::CollisionType colType)
		: IntersectionTestClass(colType), mesh(mesh), collisionGroup(colGroup), checkStaticObjs(true), checkDynamicObjs(true), intersectedObjects(nullptr)
	{
		if (mesh != nullptr && mesh->MeshClassPointer.ToPointer() != nullptr)
		{
			boundingBox = mesh->BoundingBox;
		}
	}

	PhysMeshIntersectionTestClass::PhysMeshIntersectionTestClass(IPhysMeshIntersectionTestClass ^intersectionTestClass)
		: IntersectionTestClass(intersectionTestClass)
	{
		if (intersectionTestClass == nullptr || intersectionTestClass->PhysMeshIntersectionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		mesh = intersectionTestClass->Mesh;
		boundingBox = intersectionTestClass->BoundingBox;
		collisionGroup = intersectionTestClass->CollisionGroup;
		checkStaticObjs = intersectionTestClass->CheckStaticObjs;
		checkDynamicObjs = intersectionTestClass->CheckDynamicObjs;
		intersectedObjects = gcnew Generic::LinkedList<IPhysClass ^>();

		auto renSharpIntersectionTestClass = dynamic_cast<RenSharpPhysMeshIntersectionTestClass ^>(intersectionTestClass);
		if (renSharpIntersectionTestClass != nullptr)
		{
			IntersectedObjects = renSharpIntersectionTestClass->IntersectedObjects;
		}
	}

	PhysMeshIntersectionTestClass::PhysMeshIntersectionTestClass(PhysMeshIntersectionTestClass ^intersectionTestClass)
		: IntersectionTestClass(intersectionTestClass)
	{
		if (intersectionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		mesh = intersectionTestClass->Mesh;
		boundingBox = intersectionTestClass->BoundingBox;
		collisionGroup = intersectionTestClass->CollisionGroup;
		checkStaticObjs = intersectionTestClass->CheckStaticObjs;
		checkDynamicObjs = intersectionTestClass->CheckDynamicObjs;
		intersectedObjects = gcnew Generic::LinkedList<IPhysClass ^>();

		IntersectedObjects = intersectionTestClass->IntersectedObjects;
	}

	void PhysMeshIntersectionTestClass::CopyFrom(IPhysMeshIntersectionTestClass ^intersectionTestClass)
	{
		if (intersectionTestClass == nullptr || intersectionTestClass->PhysMeshIntersectionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		IntersectionTestClass::CopyFrom(intersectionTestClass);

		mesh = intersectionTestClass->Mesh;
		boundingBox = intersectionTestClass->BoundingBox;
		collisionGroup = intersectionTestClass->CollisionGroup;
		checkStaticObjs = intersectionTestClass->CheckStaticObjs;
		checkDynamicObjs = intersectionTestClass->CheckDynamicObjs;

		auto renSharpIntersectionTestClass = dynamic_cast<RenSharpPhysMeshIntersectionTestClass ^>(intersectionTestClass);
		if (renSharpIntersectionTestClass != nullptr)
		{
			IntersectedObjects = renSharpIntersectionTestClass->IntersectedObjects;
		}
	}

	void PhysMeshIntersectionTestClass::CopyFrom(PhysMeshIntersectionTestClass ^intersectionTestClass)
	{
		if (intersectionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		IntersectionTestClass::CopyFrom(intersectionTestClass);

		mesh = intersectionTestClass->Mesh;
		boundingBox = intersectionTestClass->BoundingBox;
		collisionGroup = intersectionTestClass->CollisionGroup;
		checkStaticObjs = intersectionTestClass->CheckStaticObjs;
		checkDynamicObjs = intersectionTestClass->CheckDynamicObjs;

		IntersectedObjects = intersectionTestClass->IntersectedObjects;
	}

	bool PhysMeshIntersectionTestClass::Cull(Vector3 min, Vector3 max)
	{
		Vector3 boxMin = Vector3::Subtract(boundingBox.Center, boundingBox.Extent);
		Vector3 boxMax = Vector3::Add(boundingBox.Center, boundingBox.Extent);

		if ((boxMin.X > max.X) || (boxMax.X < min.X)) return true;
		if ((boxMin.Y > max.Y) || (boxMax.Y < min.Y)) return true;
		if ((boxMin.Z > max.Z) || (boxMax.Z < min.Z)) return true;

		return false;
	}

	bool PhysMeshIntersectionTestClass::Cull(AABoxClass box)
	{
		Vector3 dc = Vector3::Subtract(box.Center, boundingBox.Center);
		Vector3 r = Vector3::Add(box.Extent, boundingBox.Extent);

		if (Math::Abs(dc.X) > r.X) return true;
		if (Math::Abs(dc.Y) > r.Y) return true;
		if (Math::Abs(dc.Z) > r.Z) return true;

		return false;
	}

	IMeshClass ^PhysMeshIntersectionTestClass::Mesh::get()
	{
		return mesh;
	}

	void PhysMeshIntersectionTestClass::Mesh::set(IMeshClass ^value)
	{
		if (value == nullptr || value->MeshClassPointer.ToPointer() == nullptr)
		{
			mesh = nullptr;
		}
		else
		{
			mesh = value;
		}
	}

	AABoxClass PhysMeshIntersectionTestClass::BoundingBox::get()
	{
		return boundingBox;
	}

	void PhysMeshIntersectionTestClass::BoundingBox::set(AABoxClass value)
	{
		boundingBox = value;
	}

	CollisionGroupType PhysMeshIntersectionTestClass::CollisionGroup::get()
	{
		return collisionGroup;
	}

	void PhysMeshIntersectionTestClass::CollisionGroup::set(CollisionGroupType value)
	{
		collisionGroup = value;
	}

	bool PhysMeshIntersectionTestClass::CheckStaticObjs::get()
	{
		return checkStaticObjs;
	}

	void PhysMeshIntersectionTestClass::CheckStaticObjs::set(bool value)
	{
		checkStaticObjs = value;
	}

	bool PhysMeshIntersectionTestClass::CheckDynamicObjs::get()
	{
		return checkDynamicObjs;
	}

	void PhysMeshIntersectionTestClass::CheckDynamicObjs::set(bool value)
	{
		checkDynamicObjs = value;
	}

	Generic::ICollection<IPhysClass ^> ^PhysMeshIntersectionTestClass::IntersectedObjects::get()
	{
		return intersectedObjects;
	}

	void PhysMeshIntersectionTestClass::IntersectedObjects::set(Generic::ICollection<IPhysClass ^> ^value)
	{
		intersectedObjects->Clear();

		if (value != nullptr)
		{
			auto multiListValue = dynamic_cast<IMultiListClass<IPhysClass ^> ^>(value);
			if (multiListValue != nullptr && multiListValue->Pointer.ToPointer() == nullptr)
			{
				return;
			}

			for each (auto phys in value)
			{
				intersectedObjects->Add(phys);
			}
		}
	}
}