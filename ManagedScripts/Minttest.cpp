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
#include "Minttest.h"

#include "Imports.h"
#include "MMatrix3D.h"
#include "MVector3.h"
#include "UnmanagedContainer.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4715 4251 4244 26495 26454)
#include <inttest.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{

#pragma managed(push, off)

	class OBBoxIntersectionTestClassHelper : public ::OBBoxIntersectionTestClass
	{
		private:
			OBBoxIntersectionTestClassHelper(const OBBoxIntersectionTestClass &other)
				: OBBoxIntersectionTestClass(other)
			{

			}

		public:
			void UpdateBoundingBox()
			{
				update_bounding_box();
			}
	};

#pragma managed(pop)

	IntersectionTestClassRef::IntersectionTestClassRef(RenSharp::CollisionType collisionType)
		: AbstractUnmanagedObject(IntPtr(Imports::CreateIntersectionTestClass(static_cast<::Collision_Type>(collisionType))))
	{

	}

	IntersectionTestClassRef::IntersectionTestClassRef(IntersectionTestClass ^intersectionTestClass)
	{
		if (intersectionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		Pointer = IntPtr(Imports::CreateIntersectionTestClass(static_cast<::Collision_Type>(intersectionTestClass->CollisionType)));
	}

	IntersectionTestClassRef::IntersectionTestClassRef()
	{

	}

	IntersectionTestClassRef::IntersectionTestClassRef(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IIntersectionTestClass ^> ^IntersectionTestClassRef::CreateIntersectionTestClassRef(RenSharp::CollisionType collisionType)
	{
		return gcnew UnmanagedContainer<IIntersectionTestClass ^>(gcnew IntersectionTestClassRef(collisionType));
	}

	IUnmanagedContainer<IIntersectionTestClass ^> ^IntersectionTestClassRef::CreateIntersectionTestClassRef(IntersectionTestClass ^intersectionTestClass)
	{
		return gcnew UnmanagedContainer<IIntersectionTestClass ^>(gcnew IntersectionTestClassRef(intersectionTestClass));
	}

	bool IntersectionTestClassRef::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IIntersectionTestClass ^otherThis = dynamic_cast<IIntersectionTestClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return IntersectionTestClassPointer.Equals(otherThis->IntersectionTestClassPointer);
	}

	IntersectionTestClass ^IntersectionTestClassRef::ToIntersectionTestClass()
	{
		return gcnew IntersectionTestClass(this);
	}

	IntPtr IntersectionTestClassRef::IntersectionTestClassPointer::get()
	{
		return IntPtr(InternalIntersectionTestClassPointer);
	}

	RenSharp::CollisionType IntersectionTestClassRef::CollisionType::get()
	{
		return static_cast<RenSharp::CollisionType>(InternalIntersectionTestClassPointer->CollisionType);
	}

	void IntersectionTestClassRef::CollisionType::set(RenSharp::CollisionType value)
	{
		InternalIntersectionTestClassPointer->CollisionType = static_cast<::Collision_Type>(value);
	}

	bool IntersectionTestClassRef::InternalDestroyPointer()
	{
		Imports::DestroyIntersectionTestClass(InternalIntersectionTestClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::IntersectionTestClass *IntersectionTestClassRef::InternalIntersectionTestClassPointer::get()
	{
		return reinterpret_cast<::IntersectionTestClass *>(Pointer.ToPointer());
	}

	IntersectionTestClass::IntersectionTestClass(RenSharp::CollisionType collisionType)
		: collisionType(collisionType)
	{

	}

	IntersectionTestClass::IntersectionTestClass(IIntersectionTestClass ^intersectionTestClass)
	{
		if (intersectionTestClass == nullptr || intersectionTestClass->IntersectionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		collisionType = intersectionTestClass->CollisionType;
	}

	IntersectionTestClass::IntersectionTestClass(IntersectionTestClass ^intersectionTestClass)
	{
		if (intersectionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		collisionType = intersectionTestClass->CollisionType;
	}

	void IntersectionTestClass::CopyFrom(IIntersectionTestClass ^intersectionTestClass)
	{
		if (intersectionTestClass == nullptr || intersectionTestClass->IntersectionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		collisionType = intersectionTestClass->CollisionType;
	}

	void IntersectionTestClass::CopyFrom(IntersectionTestClass ^intersectionTestClass)
	{
		if (intersectionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		collisionType = intersectionTestClass->CollisionType;
	}

	RenSharp::CollisionType IntersectionTestClass::CollisionType::get()
	{
		return collisionType;
	}

	void IntersectionTestClass::CollisionType::set(RenSharp::CollisionType value)
	{
		collisionType = value;
	}

	AABoxIntersectionTestClassRef::AABoxIntersectionTestClassRef(AABoxClass box, RenSharp::CollisionType collisionType)
	{
		::AABoxClass boxBox;

		AABoxClass::ManagedToUnmanagedAABoxClass(box, boxBox);

		Pointer = IntPtr(Imports::CreateAABoxIntersectionTestClass(&boxBox, static_cast<::Collision_Type>(collisionType)));
	}

	AABoxIntersectionTestClassRef::AABoxIntersectionTestClassRef(AABoxIntersectionTestClass ^intersectionTestClass)
	{
		if (intersectionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		::AABoxClass boxBox;

		AABoxClass::ManagedToUnmanagedAABoxClass(intersectionTestClass->Box, boxBox);

		Pointer = IntPtr(Imports::CreateAABoxIntersectionTestClass(&boxBox, static_cast<::Collision_Type>(intersectionTestClass->CollisionType)));
	}

	AABoxIntersectionTestClassRef::AABoxIntersectionTestClassRef()
	{

	}

	AABoxIntersectionTestClassRef::AABoxIntersectionTestClassRef(IntPtr pointer)
		: IntersectionTestClassRef(pointer)
	{

	}

	IUnmanagedContainer<IAABoxIntersectionTestClass ^> ^AABoxIntersectionTestClassRef::CreateAABoxIntersectionTestClassRef(AABoxClass box, RenSharp::CollisionType collisionType)
	{
		return gcnew UnmanagedContainer<IAABoxIntersectionTestClass ^>(gcnew AABoxIntersectionTestClassRef(box, collisionType));
	}

	IUnmanagedContainer<IAABoxIntersectionTestClass ^> ^AABoxIntersectionTestClassRef::CreateAABoxIntersectionTestClassRef(AABoxIntersectionTestClass ^intersectionTestClass)
	{
		return gcnew UnmanagedContainer<IAABoxIntersectionTestClass ^>(gcnew AABoxIntersectionTestClassRef(intersectionTestClass));
	}

	IntersectionTestClass ^AABoxIntersectionTestClassRef::ToIntersectionTestClass()
	{
		return ToAABoxIntersectionTestClass();
	}

	AABoxIntersectionTestClass ^AABoxIntersectionTestClassRef::ToAABoxIntersectionTestClass()
	{
		return gcnew AABoxIntersectionTestClass(this);
	}

	bool AABoxIntersectionTestClassRef::Cull(Vector3 cullMin, Vector3 cullMax)
	{
		::Vector3 cullMinVec;
		::Vector3 cullMaxVec;

		Vector3::ManagedToUnmanagedVector3(cullMin, cullMinVec);
		Vector3::ManagedToUnmanagedVector3(cullMax, cullMaxVec);

		return InternalAABoxIntersectionTestClassPointer->Cull(cullMinVec, cullMaxVec);
	}

	bool AABoxIntersectionTestClassRef::Cull(AABoxClass cullBox)
	{
		::AABoxClass cullBoxBox;

		AABoxClass::ManagedToUnmanagedAABoxClass(cullBox, cullBoxBox);

		return InternalAABoxIntersectionTestClassPointer->Cull(cullBoxBox);
	}

	IntPtr AABoxIntersectionTestClassRef::AABoxIntersectionTestClassPointer::get()
	{
		return IntPtr(InternalAABoxIntersectionTestClassPointer);
	}

	AABoxClass AABoxIntersectionTestClassRef::Box::get()
	{
		AABoxClass result;

		AABoxClass::UnmanagedToManagedAABoxClass(InternalAABoxIntersectionTestClassPointer->Box, result);

		return result;
	}

	void AABoxIntersectionTestClassRef::Box::set(AABoxClass value)
	{
		AABoxClass::ManagedToUnmanagedAABoxClass(value, InternalAABoxIntersectionTestClassPointer->Box);
	}

	bool AABoxIntersectionTestClassRef::InternalDestroyPointer()
	{
		Imports::DestroyAABoxIntersectionTestClass(InternalAABoxIntersectionTestClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::IntersectionTestClass *AABoxIntersectionTestClassRef::InternalIntersectionTestClassPointer::get()
	{
		return InternalAABoxIntersectionTestClassPointer;
	}

	::AABoxIntersectionTestClass *AABoxIntersectionTestClassRef::InternalAABoxIntersectionTestClassPointer::get()
	{
		return reinterpret_cast<::AABoxIntersectionTestClass *>(Pointer.ToPointer());
	}

	AABoxIntersectionTestClass::AABoxIntersectionTestClass(AABoxClass box, RenSharp::CollisionType collisionType)
		: IntersectionTestClass(collisionType), box(box)
	{

	}

	AABoxIntersectionTestClass::AABoxIntersectionTestClass(IAABoxIntersectionTestClass ^intersectionTestClass)
		: IntersectionTestClass(intersectionTestClass)
	{
		if (intersectionTestClass == nullptr || intersectionTestClass->AABoxIntersectionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		box = intersectionTestClass->Box;
	}

	AABoxIntersectionTestClass::AABoxIntersectionTestClass(AABoxIntersectionTestClass ^intersectionTestClass)
		: IntersectionTestClass(intersectionTestClass)
	{
		if (intersectionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		box = intersectionTestClass->Box;
	}

	void AABoxIntersectionTestClass::CopyFrom(IAABoxIntersectionTestClass ^intersectionTestClass)
	{
		if (intersectionTestClass == nullptr || intersectionTestClass->AABoxIntersectionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		IntersectionTestClass::CopyFrom(intersectionTestClass);

		box = intersectionTestClass->Box;
	}

	void AABoxIntersectionTestClass::CopyFrom(AABoxIntersectionTestClass ^intersectionTestClass)
	{
		if (intersectionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		IntersectionTestClass::CopyFrom(intersectionTestClass);

		box = intersectionTestClass->Box;
	}

	bool AABoxIntersectionTestClass::Cull(Vector3 cullMin, Vector3 cullMax)
	{
		Vector3 boxMin = Vector3::Subtract(box.Center, box.Extent);
		Vector3 boxMax = Vector3::Add(box.Center, box.Extent);

		if ((boxMin.X > cullMax.X) || (boxMax.X < cullMin.X)) return true;
		if ((boxMin.Y > cullMax.Y) || (boxMax.Y < cullMin.Y)) return true;
		if ((boxMin.Z > cullMax.Z) || (boxMax.Z < cullMin.Z)) return true;

		return false;
	}

	bool AABoxIntersectionTestClass::Cull(AABoxClass cullBox)
	{
		Vector3 dc = Vector3::Subtract(cullBox.Center, box.Center);
		Vector3 r = Vector3::Add(cullBox.Extent, box.Extent);

		if (Math::Abs(dc.X) > r.X) return true;
		if (Math::Abs(dc.Y) > r.Y) return true;
		if (Math::Abs(dc.Z) > r.Z) return true;

		return false;
	}

	AABoxClass AABoxIntersectionTestClass::Box::get()
	{
		return box;
	}

	void AABoxIntersectionTestClass::Box::set(AABoxClass value)
	{
		box = value;
	}

	OBBoxIntersectionTestClassRef::OBBoxIntersectionTestClassRef(OBBoxClass box, RenSharp::CollisionType collisionType)
	{
		::OBBoxClass boxBox;

		OBBoxClass::ManagedToUnmanagedOBBoxClass(box, boxBox);

		Pointer = IntPtr(Imports::CreateOBBoxIntersectionTestClass1(&boxBox, static_cast<::Collision_Type>(collisionType)));
	}

	OBBoxIntersectionTestClassRef::OBBoxIntersectionTestClassRef(IOBBoxIntersectionTestClass ^that, Matrix3D tm)
	{
		if (that == nullptr || that->OBBoxIntersectionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("that");
		}

		::Matrix3D tmMat;
		
		Matrix3D::ManagedToUnmanagedMatrix3D(tm, tmMat);

		Pointer = IntPtr(Imports::CreateOBBoxIntersectionTestClass2(
			reinterpret_cast<::OBBoxIntersectionTestClass *>(that->OBBoxIntersectionTestClassPointer.ToPointer()),
			&tmMat));
	}

	OBBoxIntersectionTestClassRef::OBBoxIntersectionTestClassRef(IAABoxIntersectionTestClass ^that, Matrix3D tm)
	{
		if (that == nullptr || that->AABoxIntersectionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("that");
		}

		::Matrix3D tmMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(tm, tmMat);

		Pointer = IntPtr(Imports::CreateOBBoxIntersectionTestClass3(
			reinterpret_cast<::AABoxIntersectionTestClass *>(that->AABoxIntersectionTestClassPointer.ToPointer()),
			&tmMat));
	}

	OBBoxIntersectionTestClassRef::OBBoxIntersectionTestClassRef(OBBoxIntersectionTestClass ^intersectionTestClass)
	{
		if (intersectionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		::OBBoxClass boxBox;

		OBBoxClass::ManagedToUnmanagedOBBoxClass(intersectionTestClass->Box, boxBox);

		Pointer = IntPtr(Imports::CreateOBBoxIntersectionTestClass1(&boxBox, static_cast<::Collision_Type>(intersectionTestClass->CollisionType)));

		BoundingBox = intersectionTestClass->BoundingBox;
	}

	OBBoxIntersectionTestClassRef::OBBoxIntersectionTestClassRef()
	{

	}

	OBBoxIntersectionTestClassRef::OBBoxIntersectionTestClassRef(IntPtr pointer)
		: IntersectionTestClassRef(pointer)
	{

	}

	IUnmanagedContainer<IOBBoxIntersectionTestClass ^> ^OBBoxIntersectionTestClassRef::CreateOBBoxIntersectionTestClassRef(OBBoxClass box, RenSharp::CollisionType collisionType)
	{
		return gcnew UnmanagedContainer<IOBBoxIntersectionTestClass ^>(gcnew OBBoxIntersectionTestClassRef(box, collisionType));
	}

	IUnmanagedContainer<IOBBoxIntersectionTestClass ^> ^OBBoxIntersectionTestClassRef::CreateOBBoxIntersectionTestClassRef(IOBBoxIntersectionTestClass ^that, Matrix3D tm)
	{
		return gcnew UnmanagedContainer<IOBBoxIntersectionTestClass ^>(gcnew OBBoxIntersectionTestClassRef(that, tm));
	}

	IUnmanagedContainer<IOBBoxIntersectionTestClass ^> ^OBBoxIntersectionTestClassRef::CreateOBBoxIntersectionTestClassRef(IAABoxIntersectionTestClass ^that, Matrix3D tm)
	{
		return gcnew UnmanagedContainer<IOBBoxIntersectionTestClass ^>(gcnew OBBoxIntersectionTestClassRef(that, tm));
	}

	IUnmanagedContainer<IOBBoxIntersectionTestClass ^> ^OBBoxIntersectionTestClassRef::CreateOBBoxIntersectionTestClassRef(OBBoxIntersectionTestClass ^intersectionTestClass)
	{
		return gcnew UnmanagedContainer<IOBBoxIntersectionTestClass ^>(gcnew OBBoxIntersectionTestClassRef(intersectionTestClass));
	}

	IntersectionTestClass ^OBBoxIntersectionTestClassRef::ToIntersectionTestClass()
	{
		return ToOBBoxIntersectionTestClass();
	}

	OBBoxIntersectionTestClass ^OBBoxIntersectionTestClassRef::ToOBBoxIntersectionTestClass()
	{
		return gcnew OBBoxIntersectionTestClass(this);
	}

	bool OBBoxIntersectionTestClassRef::Cull(Vector3 cullMin, Vector3 cullMax)
	{
		::Vector3 cullMinVec;
		::Vector3 cullMaxVec;

		Vector3::ManagedToUnmanagedVector3(cullMin, cullMinVec);
		Vector3::ManagedToUnmanagedVector3(cullMax, cullMaxVec);

		return InternalOBBoxIntersectionTestClassPointer->Cull(cullMinVec, cullMaxVec);
	}

	bool OBBoxIntersectionTestClassRef::Cull(AABoxClass cullBox)
	{
		::AABoxClass cullBoxBox;

		AABoxClass::ManagedToUnmanagedAABoxClass(cullBox, cullBoxBox);

		return InternalOBBoxIntersectionTestClassPointer->Cull(cullBoxBox);
	}

	IntPtr OBBoxIntersectionTestClassRef::OBBoxIntersectionTestClassPointer::get()
	{
		return IntPtr(InternalOBBoxIntersectionTestClassPointer);
	}

	OBBoxClass OBBoxIntersectionTestClassRef::Box::get()
	{
		OBBoxClass result;

		OBBoxClass::UnmanagedToManagedOBBoxClass(InternalOBBoxIntersectionTestClassPointer->Box, result);

		return result;
	}

	void OBBoxIntersectionTestClassRef::Box::set(OBBoxClass value)
	{
		OBBoxClass::ManagedToUnmanagedOBBoxClass(value, InternalOBBoxIntersectionTestClassPointer->Box);
	}

	AABoxClass OBBoxIntersectionTestClassRef::BoundingBox::get()
	{
		AABoxClass result;

		AABoxClass::UnmanagedToManagedAABoxClass(InternalOBBoxIntersectionTestClassPointer->BoundingBox, result);

		return result;
	}

	void OBBoxIntersectionTestClassRef::BoundingBox::set(AABoxClass value)
	{
		AABoxClass::ManagedToUnmanagedAABoxClass(value, InternalOBBoxIntersectionTestClassPointer->BoundingBox);
	}

	bool OBBoxIntersectionTestClassRef::InternalDestroyPointer()
	{
		Imports::DestroyOBBoxIntersectionTestClass(InternalOBBoxIntersectionTestClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	void OBBoxIntersectionTestClassRef::UpdateBoundingBox()
	{
		auto helper = reinterpret_cast<OBBoxIntersectionTestClassHelper *>(InternalOBBoxIntersectionTestClassPointer);

		helper->UpdateBoundingBox();
	}

	::IntersectionTestClass *OBBoxIntersectionTestClassRef::InternalIntersectionTestClassPointer::get()
	{
		return InternalOBBoxIntersectionTestClassPointer;
	}

	::OBBoxIntersectionTestClass *OBBoxIntersectionTestClassRef::InternalOBBoxIntersectionTestClassPointer::get()
	{
		return reinterpret_cast<::OBBoxIntersectionTestClass *>(Pointer.ToPointer());
	}

	OBBoxIntersectionTestClass::OBBoxIntersectionTestClass(OBBoxClass box, RenSharp::CollisionType collisionType)
		: IntersectionTestClass(collisionType), box(box)
	{
		UpdateBoundingBox();
	}

	OBBoxIntersectionTestClass::OBBoxIntersectionTestClass(IOBBoxIntersectionTestClass ^that, Matrix3D tm)
		: IntersectionTestClass(that)
	{
		if (that == nullptr || that->OBBoxIntersectionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("that");
		}

		box = OBBoxClass::Transform(tm, that->Box);

		UpdateBoundingBox();
	}

	OBBoxIntersectionTestClass::OBBoxIntersectionTestClass(OBBoxIntersectionTestClass ^that, Matrix3D tm)
		: IntersectionTestClass(that)
	{
		if (that == nullptr)
		{
			throw gcnew ArgumentNullException("that");
		}

		box = OBBoxClass::Transform(tm, that->Box);

		UpdateBoundingBox();
	}

	OBBoxIntersectionTestClass::OBBoxIntersectionTestClass(IAABoxIntersectionTestClass ^that, Matrix3D tm)
		: IntersectionTestClass(that)
	{
		if (that == nullptr || that->AABoxIntersectionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("that");
		}


		Vector3 center = Matrix3D::TransformVector(tm, that->Box.Center);
		box = OBBoxClass(center, that->Box.Extent, tm);

		UpdateBoundingBox();
	}

	OBBoxIntersectionTestClass::OBBoxIntersectionTestClass(AABoxIntersectionTestClass ^that, Matrix3D tm)
		: IntersectionTestClass(that)
	{
		if (that == nullptr)
		{
			throw gcnew ArgumentNullException("that");
		}

		Vector3 center = Matrix3D::TransformVector(tm, that->Box.Center);
		box = OBBoxClass(center, that->Box.Extent, tm);

		UpdateBoundingBox();
	}

	OBBoxIntersectionTestClass::OBBoxIntersectionTestClass(IOBBoxIntersectionTestClass ^intersectionTestClass)
		: IntersectionTestClass(intersectionTestClass)
	{
		if (intersectionTestClass == nullptr || intersectionTestClass->OBBoxIntersectionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		box = intersectionTestClass->Box;
		boundingBox = intersectionTestClass->BoundingBox;
	}

	OBBoxIntersectionTestClass::OBBoxIntersectionTestClass(OBBoxIntersectionTestClass ^intersectionTestClass)
		: IntersectionTestClass(intersectionTestClass)
	{
		if (intersectionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		box = intersectionTestClass->Box;
		boundingBox = intersectionTestClass->BoundingBox;
	}

	void OBBoxIntersectionTestClass::CopyFrom(IOBBoxIntersectionTestClass ^intersectionTestClass)
	{
		if (intersectionTestClass == nullptr || intersectionTestClass->OBBoxIntersectionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		IntersectionTestClass::CopyFrom(intersectionTestClass);

		box = intersectionTestClass->Box;
		boundingBox = intersectionTestClass->BoundingBox;
	}

	void OBBoxIntersectionTestClass::CopyFrom(OBBoxIntersectionTestClass ^intersectionTestClass)
	{
		if (intersectionTestClass == nullptr)
		{
			throw gcnew ArgumentNullException("intersectionTestClass");
		}

		IntersectionTestClass::CopyFrom(intersectionTestClass);

		box = intersectionTestClass->Box;
		boundingBox = intersectionTestClass->BoundingBox;
	}

	bool OBBoxIntersectionTestClass::Cull(Vector3 cullMin, Vector3 cullMax)
	{
		Vector3 boxMin = Vector3::Subtract(boundingBox.Center, boundingBox.Extent);
		Vector3 boxMax = Vector3::Add(boundingBox.Center, boundingBox.Extent);

		if ((boxMin.X > cullMax.X) || (boxMax.X < cullMin.X)) return true;
		if ((boxMin.Y > cullMax.Y) || (boxMax.Y < cullMin.Y)) return true;
		if ((boxMin.Z > cullMax.Z) || (boxMax.Z < cullMin.Z)) return true;

		return false;
	}

	bool OBBoxIntersectionTestClass::Cull(AABoxClass cullBox)
	{
		Vector3 dc = Vector3::Subtract(cullBox.Center, boundingBox.Center);
		Vector3 r = Vector3::Add(cullBox.Extent, boundingBox.Extent);

		if (Math::Abs(dc.X) > r.X) return true;
		if (Math::Abs(dc.Y) > r.Y) return true;
		if (Math::Abs(dc.Z) > r.Z) return true;

		return false;
	}

	OBBoxClass OBBoxIntersectionTestClass::Box::get()
	{
		return box;
	}

	void OBBoxIntersectionTestClass::Box::set(OBBoxClass value)
	{
		box = value;
	}

	AABoxClass OBBoxIntersectionTestClass::BoundingBox::get()
	{
		return boundingBox;
	}

	void OBBoxIntersectionTestClass::BoundingBox::set(AABoxClass value)
	{
		boundingBox = value;
	}

	void OBBoxIntersectionTestClass::UpdateBoundingBox()
	{
		boundingBox.Center = box.Center;
		boundingBox.Extent = box.Basis.RotateAABoxExtent(box.Extent);
	}
}