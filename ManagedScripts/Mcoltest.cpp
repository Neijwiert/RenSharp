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
#include "Mcoltest.h"

#include "Imports.h"
#include "MRenderObjClass.h"
#include "MMatrix3D.h"

namespace RenSharp
{
	CollisionTestClassRef::CollisionTestClassRef(RenSharp::CollisionType collisionType)
		: AbstractUnmanagedObject(IntPtr(Imports::CreateCollisionTestClass(static_cast<int>(collisionType))))
	{

	}

	CollisionTestClassRef::CollisionTestClassRef()
	{

	}

	CollisionTestClassRef::CollisionTestClassRef(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<ICollisionTestClass ^> ^CollisionTestClassRef::CreateCollisionTestClassRef(RenSharp::CollisionType collisionType)
	{
		return gcnew UnmanagedContainer<ICollisionTestClass ^>(gcnew CollisionTestClassRef(collisionType));
	}

	bool CollisionTestClassRef::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		ICollisionTestClass ^otherThis = dynamic_cast<ICollisionTestClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return CollisionTestClassPointer.Equals(otherThis->CollisionTestClassPointer);
	}

	CollisionTestClass ^CollisionTestClassRef::ToCollisionTestClass()
	{
		return gcnew CollisionTestClass(this);
	}

	IntPtr CollisionTestClassRef::CollisionTestClassPointer::get()
	{
		return IntPtr(InternalCollisionTestClassPointer);
	}

	Nullable<CastResultStruct> CollisionTestClassRef::Result::get()
	{
		auto result = InternalCollisionTestClassPointer->Result;
		if (result == nullptr)
		{
			return Nullable<CastResultStruct>();
		}
		else
		{
			return Nullable<CastResultStruct>(CastResultStruct(IntPtr(result)));
		}
	}

	CollisionType CollisionTestClassRef::CollisionType::get()
	{
		return static_cast<RenSharp::CollisionType>(InternalCollisionTestClassPointer->CollisionType);
	}

	void CollisionTestClassRef::CollisionType::set(RenSharp::CollisionType value)
	{
		InternalCollisionTestClassPointer->CollisionType = static_cast<::Collision_Type>(value);
	}

	IRenderObjClass ^CollisionTestClassRef::CollidedRenderObj::get()
	{
		auto result = InternalCollisionTestClassPointer->CollidedRenderObj;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(result));
		}
	}

	void CollisionTestClassRef::CollidedRenderObj::set(IRenderObjClass ^value)
	{
		if (value == nullptr || value->RenderObjClassPointer.ToPointer() == nullptr)
		{
			InternalCollisionTestClassPointer->CollidedRenderObj = nullptr;
		}
		else
		{
			InternalCollisionTestClassPointer->CollidedRenderObj = reinterpret_cast<::RenderObjClass *>(value->RenderObjClassPointer.ToPointer());
		}
	}

	bool CollisionTestClassRef::InternalDestroyPointer()
	{
		Imports::DestroyCollisionTestClass(InternalCollisionTestClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::CollisionTestClass *CollisionTestClassRef::InternalCollisionTestClassPointer::get()
	{
		return reinterpret_cast<::CollisionTestClass *>(Pointer.ToPointer());
	}

	RenSharpCollisionTestClass::RenSharpCollisionTestClass(Nullable<CastResultStruct> res, RenSharp::CollisionType collisionType)
	{
		if (res.HasValue)
		{
			::CastResultStruct resultStruct;

			CastResultStruct::ManagedToUnmanagedCastResultStruct(res.Value, resultStruct);

			Pointer = IntPtr(Imports::CreateRenSharpCollisionTestClass(static_cast<int>(collisionType)));

			Imports::RenSharpCollisionTestClassSetResult(InternalRenSharpCollisionTestClassPointer, &resultStruct);
		}
		else
		{
			Pointer = IntPtr(Imports::CreateRenSharpCollisionTestClass(static_cast<int>(collisionType)));
		}
	}

	RenSharpCollisionTestClass::RenSharpCollisionTestClass(CollisionTestClass ^colTest)
	{
		if (colTest == nullptr)
		{
			throw gcnew ArgumentNullException("colTest");
		}

		::CastResultStruct resultStruct;

		CastResultStruct::ManagedToUnmanagedCastResultStruct(colTest->Result, resultStruct);

		Pointer = IntPtr(Imports::CreateRenSharpCollisionTestClass(static_cast<int>(colTest->CollisionType)));
		Imports::RenSharpCollisionTestClassSetResult(InternalRenSharpCollisionTestClassPointer, &resultStruct);

		CollidedRenderObj = colTest->CollidedRenderObj;
	}

	RenSharpCollisionTestClass::RenSharpCollisionTestClass(IntPtr pointer)
		: CollisionTestClassRef(pointer)
	{

	}

	IUnmanagedContainer<ICollisionTestClass ^> ^RenSharpCollisionTestClass::CreateRenSharpCollisionTestClass(Nullable<CastResultStruct> res, RenSharp::CollisionType collisionType)
	{
		return gcnew UnmanagedContainer<ICollisionTestClass ^>(gcnew RenSharpCollisionTestClass(res, collisionType));
	}

	IUnmanagedContainer<ICollisionTestClass ^> ^RenSharpCollisionTestClass::CreateRenSharpCollisionTestClass(CollisionTestClass ^colTest)
	{
		return gcnew UnmanagedContainer<ICollisionTestClass ^>(gcnew RenSharpCollisionTestClass(colTest));
	}

	IntPtr RenSharpCollisionTestClass::RenSharpCollisionTestClassPointer::get()
	{
		return IntPtr(InternalRenSharpCollisionTestClassPointer);
	}

	Nullable<CastResultStruct> RenSharpCollisionTestClass::Result::get()
	{
		return CollisionTestClassRef::Result::get();
	}

	void RenSharpCollisionTestClass::Result::set(Nullable<CastResultStruct> value)
	{
		if (value.HasValue)
		{
			::CastResultStruct resultStruct;

			CastResultStruct::ManagedToUnmanagedCastResultStruct(value.Value, resultStruct);

			Imports::RenSharpCollisionTestClassSetResult(InternalRenSharpCollisionTestClassPointer, &resultStruct);
		}
		else
		{
			InternalCollisionTestClassPointer->Result = nullptr;
		}
	}

	bool RenSharpCollisionTestClass::InternalDestroyPointer()
	{
		Imports::DestroyRenSharpCollisionTestClass(InternalRenSharpCollisionTestClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::RenSharpCollisionTestClass *RenSharpCollisionTestClass::InternalRenSharpCollisionTestClassPointer::get()
	{
		return reinterpret_cast<::RenSharpCollisionTestClass *>(Pointer.ToPointer());
	}

	CollisionTestClass::CollisionTestClass(CastResultStruct result, RenSharp::CollisionType collisionType)
		: result(result), collisionType(collisionType), collidedRenderObj(nullptr)
	{

	}

	CollisionTestClass::CollisionTestClass(RenSharp::CollisionType collisionType)
		: collisionType(collisionType), collidedRenderObj(nullptr)
	{
		result.Reset();
	}

	CollisionTestClass::CollisionTestClass(ICollisionTestClass ^colTest)
	{
		if (colTest == nullptr || colTest->CollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("colTest");
		}

		auto otherResult = colTest->Result;
		if (otherResult.HasValue)
		{
			result = otherResult.Value;
		}
		else
		{
			result.Reset();
		}

		collisionType = colTest->CollisionType;
		collidedRenderObj = colTest->CollidedRenderObj;
	}

	CollisionTestClass::CollisionTestClass(CollisionTestClass ^colTest)
	{
		if (colTest == nullptr)
		{
			throw gcnew ArgumentNullException("colTest");
		}

		result = colTest->result;
		collisionType = colTest->CollisionType;
		collidedRenderObj = colTest->CollidedRenderObj;
	}

	void CollisionTestClass::CopyFrom(ICollisionTestClass ^colTest)
	{
		if (colTest == nullptr || colTest->CollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("colTest");
		}

		auto otherResult = colTest->Result;
		if (otherResult.HasValue)
		{
			result = otherResult.Value;
		}
		else
		{
			result.Reset();
		}

		collisionType = colTest->CollisionType;
		collidedRenderObj = colTest->CollidedRenderObj;
	}

	void CollisionTestClass::CopyFrom(CollisionTestClass ^colTest)
	{
		if (colTest == nullptr)
		{
			throw gcnew ArgumentNullException("colTest");
		}

		result = colTest->result;
		collisionType = colTest->CollisionType;
		collidedRenderObj = colTest->CollidedRenderObj;
	}

	CastResultStruct CollisionTestClass::Result::get()
	{
		return result;
	}

	void CollisionTestClass::Result::set(CastResultStruct value)
	{
		result = value;
	}

	CollisionType CollisionTestClass::CollisionType::get()
	{
		return collisionType;
	}

	void CollisionTestClass::CollisionType::set(RenSharp::CollisionType value)
	{
		collisionType = value;
	}

	IRenderObjClass ^CollisionTestClass::CollidedRenderObj::get()
	{
		return collidedRenderObj;
	}

	void CollisionTestClass::CollidedRenderObj::set(IRenderObjClass ^value)
	{
		collidedRenderObj = value;
	}

	RayCollisionTestClassRef::RayCollisionTestClassRef(
		LineSegClass ray,
		RenSharp::CollisionType collisionType,
		bool ignoreTranslucentMeshes)
	{
		::LineSegClass rayLine;

		LineSegClass::ManagedToUnmanagedLineSegClass(ray, rayLine);

		Pointer = IntPtr(Imports::CreateRayCollisionTestClass1(
			&rayLine,
			static_cast<::Collision_Type>(collisionType),
			ignoreTranslucentMeshes));
	}

	RayCollisionTestClassRef::RayCollisionTestClassRef(LineSegClass ray, RenSharp::CollisionType collisionType)
	{
		::LineSegClass rayLine;

		LineSegClass::ManagedToUnmanagedLineSegClass(ray, rayLine);

		Pointer = IntPtr(Imports::CreateRayCollisionTestClass2(
			&rayLine,
			static_cast<::Collision_Type>(collisionType)));
	}

	RayCollisionTestClassRef::RayCollisionTestClassRef(LineSegClass ray)
	{
		::LineSegClass rayLine;

		LineSegClass::ManagedToUnmanagedLineSegClass(ray, rayLine);

		Pointer = IntPtr(Imports::CreateRayCollisionTestClass3(
			&rayLine));
	}

	RayCollisionTestClassRef::RayCollisionTestClassRef(IRayCollisionTestClass ^rayTest, Matrix3D tm)
	{
		if (rayTest == nullptr || rayTest->RayCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("rayTest");
		}

		::Matrix3D tmMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(tm, tmMat);

		Pointer = IntPtr(Imports::CreateRayCollisionTestClass4(
			reinterpret_cast<::RayCollisionTestClass *>(rayTest->RayCollisionTestClassPointer.ToPointer()),
			&tmMat));
	}

	RayCollisionTestClassRef::RayCollisionTestClassRef()
	{

	}

	RayCollisionTestClassRef::RayCollisionTestClassRef(IntPtr pointer)
		: CollisionTestClassRef(pointer)
	{

	}

	IUnmanagedContainer<IRayCollisionTestClass ^> ^RayCollisionTestClassRef::CreateRayCollisionTestClassRef(
		LineSegClass ray,
		RenSharp::CollisionType collisionType,
		bool ignoreTranslucentMeshes)
	{
		return gcnew UnmanagedContainer<IRayCollisionTestClass ^>(gcnew RayCollisionTestClassRef(ray, collisionType, ignoreTranslucentMeshes));
	}

	IUnmanagedContainer<IRayCollisionTestClass ^> ^RayCollisionTestClassRef::CreateRayCollisionTestClassRef(
		LineSegClass ray,
		RenSharp::CollisionType
		collisionType)
	{
		return gcnew UnmanagedContainer<IRayCollisionTestClass ^>(gcnew RayCollisionTestClassRef(ray, collisionType));
	}

	IUnmanagedContainer<IRayCollisionTestClass ^> ^RayCollisionTestClassRef::CreateRayCollisionTestClassRef(LineSegClass ray)
	{
		return gcnew UnmanagedContainer<IRayCollisionTestClass ^>(gcnew RayCollisionTestClassRef(ray));
	}

	IUnmanagedContainer<IRayCollisionTestClass ^> ^RayCollisionTestClassRef::CreateRayCollisionTestClassRef(
		IRayCollisionTestClass ^rayTest,
		Matrix3D tm)
	{
		return gcnew UnmanagedContainer<IRayCollisionTestClass ^>(gcnew RayCollisionTestClassRef(rayTest, tm));
	}

	CollisionTestClass ^RayCollisionTestClassRef::ToCollisionTestClass()
	{
		return ToRayCollisionTestClass();
	}

	RayCollisionTestClass ^RayCollisionTestClassRef::ToRayCollisionTestClass()
	{
		return gcnew RayCollisionTestClass(this);
	}

	IntPtr RayCollisionTestClassRef::RayCollisionTestClassPointer::get()
	{
		return IntPtr(InternalRayCollisionTestClassPointer);
	}

	LineSegClass RayCollisionTestClassRef::Ray::get()
	{
		LineSegClass result;

		LineSegClass::UnmanagedToManagedLineSegClass(InternalRayCollisionTestClassPointer->Ray, result);

		return result;
	}

	void RayCollisionTestClassRef::Ray::set(LineSegClass value)
	{
		LineSegClass::ManagedToUnmanagedLineSegClass(value, InternalRayCollisionTestClassPointer->Ray);
	}

	bool RayCollisionTestClassRef::IgnoreTranslucentMeshes::get()
	{
		return InternalRayCollisionTestClassPointer->IgnoreTranslucentMeshes;
	}

	void RayCollisionTestClassRef::IgnoreTranslucentMeshes::set(bool value)
	{
		InternalRayCollisionTestClassPointer->IgnoreTranslucentMeshes = value;
	}

	bool RayCollisionTestClassRef::InternalDestroyPointer()
	{
		Imports::DestroyRayCollisionTestClass(InternalRayCollisionTestClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::CollisionTestClass *RayCollisionTestClassRef::InternalCollisionTestClassPointer::get()
	{
		return InternalRayCollisionTestClassPointer;
	}

	::RayCollisionTestClass *RayCollisionTestClassRef::InternalRayCollisionTestClassPointer::get()
	{
		return reinterpret_cast<::RayCollisionTestClass *>(Pointer.ToPointer());
	}

	RenSharpRayCollisionTestClass::RenSharpRayCollisionTestClass(
		LineSegClass ray,
		RenSharp::CollisionType collisionType,
		bool ignoreTranslucentMeshes)
	{
		::LineSegClass rayLine;

		LineSegClass::ManagedToUnmanagedLineSegClass(ray, rayLine);

		Pointer = IntPtr(Imports::CreateRenSharpRayCollisionTestClass1(
			&rayLine,
			static_cast<::Collision_Type>(collisionType),
			ignoreTranslucentMeshes));
	}

	RenSharpRayCollisionTestClass::RenSharpRayCollisionTestClass(LineSegClass ray, RenSharp::CollisionType collisionType)
	{
		::LineSegClass rayLine;

		LineSegClass::ManagedToUnmanagedLineSegClass(ray, rayLine);

		Pointer = IntPtr(Imports::CreateRenSharpRayCollisionTestClass2(
			&rayLine,
			static_cast<::Collision_Type>(collisionType)));
	}

	RenSharpRayCollisionTestClass::RenSharpRayCollisionTestClass(LineSegClass ray)
	{
		::LineSegClass rayLine;

		LineSegClass::ManagedToUnmanagedLineSegClass(ray, rayLine);

		Pointer = IntPtr(Imports::CreateRenSharpRayCollisionTestClass3(
			&rayLine));
	}

	RenSharpRayCollisionTestClass::RenSharpRayCollisionTestClass(
		LineSegClass ray,
		Nullable<CastResultStruct> res,
		RenSharp::CollisionType collisionType,
		bool ignoreTranslucentMeshes)
		: RenSharpRayCollisionTestClass(ray, collisionType, ignoreTranslucentMeshes)
	{
		if (res.HasValue)
		{
			::CastResultStruct castRes;

			CastResultStruct::ManagedToUnmanagedCastResultStruct(res.Value, castRes);

			Imports::RenSharpRayCollisionTestClassSetResult(InternalRenSharpRayCollisionTestClassPointer, &castRes);
		}
	}

	RenSharpRayCollisionTestClass::RenSharpRayCollisionTestClass(
		LineSegClass ray,
		Nullable<CastResultStruct> res,
		RenSharp::CollisionType collisionType)
		: RenSharpRayCollisionTestClass(ray, collisionType)
	{
		if (res.HasValue)
		{
			::CastResultStruct castRes;

			CastResultStruct::ManagedToUnmanagedCastResultStruct(res.Value, castRes);

			Imports::RenSharpRayCollisionTestClassSetResult(InternalRenSharpRayCollisionTestClassPointer, &castRes);
		}
	}

	RenSharpRayCollisionTestClass::RenSharpRayCollisionTestClass(LineSegClass ray, Nullable<CastResultStruct> res)
		: RenSharpRayCollisionTestClass(ray)
	{
		if (res.HasValue)
		{
			::CastResultStruct castRes;

			CastResultStruct::ManagedToUnmanagedCastResultStruct(res.Value, castRes);

			Imports::RenSharpRayCollisionTestClassSetResult(InternalRenSharpRayCollisionTestClassPointer, &castRes);
		}
	}

	RenSharpRayCollisionTestClass::RenSharpRayCollisionTestClass(IRayCollisionTestClass ^rayTest, Matrix3D tm)
	{
		if (rayTest == nullptr || rayTest->RayCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("rayTest");
		}

		::Matrix3D tmMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(tm, tmMat);

		Pointer = IntPtr(Imports::CreateRenSharpRayCollisionTestClass4(
			reinterpret_cast<::RayCollisionTestClass *>(rayTest->RayCollisionTestClassPointer.ToPointer()),
			&tmMat));
	}

	RenSharpRayCollisionTestClass::RenSharpRayCollisionTestClass(RayCollisionTestClass ^rayTest, Matrix3D tm)
	{
		if (rayTest == nullptr)
		{
			throw gcnew ArgumentNullException("rayTest");
		}

		::Matrix3D tmMat;
		::LineSegClass ray;
		::CastResultStruct res;

		Matrix3D::ManagedToUnmanagedMatrix3D(tm, tmMat);
		LineSegClass::ManagedToUnmanagedLineSegClass(rayTest->Ray, ray);
		CastResultStruct::ManagedToUnmanagedCastResultStruct(rayTest->Result, res);

		::RayCollisionTestClass tmp(ray, &res, static_cast<::Collision_Type>(rayTest->CollisionType), rayTest->IgnoreTranslucentMeshes);
	
		Pointer = IntPtr(Imports::CreateRenSharpRayCollisionTestClass4(&tmp, &tmMat));
	}

	RenSharpRayCollisionTestClass::RenSharpRayCollisionTestClass(RayCollisionTestClass ^rayTest)
	{
		if (rayTest == nullptr)
		{
			throw gcnew ArgumentNullException("rayTest");
		}

		::LineSegClass ray;
		::CastResultStruct res;

		LineSegClass::ManagedToUnmanagedLineSegClass(rayTest->Ray, ray);
		CastResultStruct::ManagedToUnmanagedCastResultStruct(rayTest->Result, res);

		Pointer = IntPtr(Imports::CreateRenSharpRayCollisionTestClass1(
			&ray,
			static_cast<::Collision_Type>(rayTest->CollisionType),
			rayTest->IgnoreTranslucentMeshes));

		Imports::RenSharpRayCollisionTestClassSetResult(InternalRenSharpRayCollisionTestClassPointer, &res);

		CollidedRenderObj = rayTest->CollidedRenderObj;
	}

	RenSharpRayCollisionTestClass::RenSharpRayCollisionTestClass(IntPtr pointer)
		: RayCollisionTestClassRef(pointer)
	{

	}

	IUnmanagedContainer<IRayCollisionTestClass ^> ^RenSharpRayCollisionTestClass::CreateRenSharpRayCollisionTestClass(
		LineSegClass ray,
		RenSharp::CollisionType collisionType,
		bool ignoreTranslucentMeshes)
	{
		return gcnew UnmanagedContainer<IRayCollisionTestClass ^>(gcnew RenSharpRayCollisionTestClass(
			ray,
			collisionType,
			ignoreTranslucentMeshes));
	}

	IUnmanagedContainer<IRayCollisionTestClass ^> ^RenSharpRayCollisionTestClass::CreateRenSharpRayCollisionTestClass(
		LineSegClass ray,
		RenSharp::CollisionType collisionType)
	{
		return gcnew UnmanagedContainer<IRayCollisionTestClass ^>(gcnew RenSharpRayCollisionTestClass(
			ray,
			collisionType));
	}

	IUnmanagedContainer<IRayCollisionTestClass ^> ^RenSharpRayCollisionTestClass::CreateRenSharpRayCollisionTestClass(LineSegClass ray)
	{
		return gcnew UnmanagedContainer<IRayCollisionTestClass ^>(gcnew RenSharpRayCollisionTestClass(
			ray));
	}

	IUnmanagedContainer<IRayCollisionTestClass ^> ^RenSharpRayCollisionTestClass::CreateRenSharpRayCollisionTestClass(
		LineSegClass ray,
		Nullable<CastResultStruct> res,
		RenSharp::CollisionType collisionType,
		bool ignoreTranslucentMeshes)
	{
		return gcnew UnmanagedContainer<IRayCollisionTestClass ^>(gcnew RenSharpRayCollisionTestClass(
			ray,
			res,
			collisionType,
			ignoreTranslucentMeshes));
	}

	IUnmanagedContainer<IRayCollisionTestClass ^> ^RenSharpRayCollisionTestClass::CreateRenSharpRayCollisionTestClass(
		LineSegClass ray,
		Nullable<CastResultStruct> res,
		RenSharp::CollisionType collisionType)
	{
		return gcnew UnmanagedContainer<IRayCollisionTestClass ^>(gcnew RenSharpRayCollisionTestClass(
			ray,
			res,
			collisionType));
	}

	IUnmanagedContainer<IRayCollisionTestClass ^> ^RenSharpRayCollisionTestClass::CreateRenSharpRayCollisionTestClass(
		LineSegClass ray,
		Nullable<CastResultStruct> res)
	{
		return gcnew UnmanagedContainer<IRayCollisionTestClass ^>(gcnew RenSharpRayCollisionTestClass(
			ray,
			res));
	}

	IUnmanagedContainer<IRayCollisionTestClass ^> ^RenSharpRayCollisionTestClass::CreateRenSharpRayCollisionTestClass(
		IRayCollisionTestClass ^rayTest,
		Matrix3D tm)
	{
		return gcnew UnmanagedContainer<IRayCollisionTestClass ^>(gcnew RenSharpRayCollisionTestClass(
			rayTest,
			tm));
	}

	IUnmanagedContainer<IRayCollisionTestClass ^> ^RenSharpRayCollisionTestClass::CreateRenSharpRayCollisionTestClass(
		RayCollisionTestClass ^rayTest,
		Matrix3D tm)
	{
		return gcnew UnmanagedContainer<IRayCollisionTestClass ^>(gcnew RenSharpRayCollisionTestClass(
			rayTest,
			tm));
	}

	IUnmanagedContainer<IRayCollisionTestClass ^> ^RenSharpRayCollisionTestClass::CreateRenSharpRayCollisionTestClass(
		RayCollisionTestClass ^rayTest)
	{
		return gcnew UnmanagedContainer<IRayCollisionTestClass ^>(gcnew RenSharpRayCollisionTestClass(
			rayTest));
	}

	IntPtr RenSharpRayCollisionTestClass::RenSharpRayCollisionTestClassPointer::get()
	{
		return IntPtr(InternalRenSharpRayCollisionTestClassPointer);
	}

	Nullable<CastResultStruct> RenSharpRayCollisionTestClass::Result::get()
	{
		return CollisionTestClassRef::Result::get();
	}

	void RenSharpRayCollisionTestClass::Result::set(Nullable<CastResultStruct> value)
	{
		if (value.HasValue)
		{
			::CastResultStruct res;

			CastResultStruct::ManagedToUnmanagedCastResultStruct(value.Value, res);

			Imports::RenSharpRayCollisionTestClassSetResult(InternalRenSharpRayCollisionTestClassPointer, &res);
		}
		else
		{
			InternalRayCollisionTestClassPointer->Result = nullptr;
		}
	}

	bool RenSharpRayCollisionTestClass::InternalDestroyPointer()
	{
		Imports::DestroyRenSharpRayCollisionTestClass(InternalRenSharpRayCollisionTestClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::RenSharpRayCollisionTestClass *RenSharpRayCollisionTestClass::InternalRenSharpRayCollisionTestClassPointer::get()
	{
		return reinterpret_cast<::RenSharpRayCollisionTestClass *>(Pointer.ToPointer());
	}

	RayCollisionTestClass::RayCollisionTestClass(
		LineSegClass ray,
		CastResultStruct result,
		RenSharp::CollisionType collisionType,
		bool ignoreTranslucentMeshes)
		: CollisionTestClass(result, collisionType), ray(ray), ignoreTranslucentMeshes(ignoreTranslucentMeshes)
	{

	}

	RayCollisionTestClass::RayCollisionTestClass(LineSegClass ray, CastResultStruct result, RenSharp::CollisionType collisionType)
		: CollisionTestClass(result, collisionType), ray(ray), ignoreTranslucentMeshes(false)
	{

	}

	RayCollisionTestClass::RayCollisionTestClass(LineSegClass ray, CastResultStruct result)
		: CollisionTestClass(result, RenSharp::CollisionType::CollisionType0), ray(ray), ignoreTranslucentMeshes(false)
	{

	}

	RayCollisionTestClass::RayCollisionTestClass(LineSegClass ray, RenSharp::CollisionType collisionType, bool ignoreTranslucentMeshes)
		: CollisionTestClass(collisionType), ray(ray), ignoreTranslucentMeshes(ignoreTranslucentMeshes)
	{

	}

	RayCollisionTestClass::RayCollisionTestClass(LineSegClass ray, RenSharp::CollisionType collisionType)
		: CollisionTestClass(collisionType), ray(ray), ignoreTranslucentMeshes(false)
	{

	}

	RayCollisionTestClass::RayCollisionTestClass(LineSegClass ray)
		: CollisionTestClass(RenSharp::CollisionType::CollisionType0), ray(ray), ignoreTranslucentMeshes(false)
	{

	}

	RayCollisionTestClass::RayCollisionTestClass(IRayCollisionTestClass ^rayTest, Matrix3D tm)
		: CollisionTestClass(rayTest)
	{
		if (rayTest == nullptr || rayTest->RayCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("rayTest");
		}

		ray = LineSegClass(rayTest->Ray, tm);
		ignoreTranslucentMeshes = rayTest->IgnoreTranslucentMeshes;
	}

	RayCollisionTestClass::RayCollisionTestClass(RayCollisionTestClass ^rayTest, Matrix3D tm)
		: CollisionTestClass(rayTest)
	{
		if (rayTest == nullptr)
		{
			throw gcnew ArgumentNullException("rayTest");
		}

		ray = LineSegClass(rayTest->Ray, tm);
		ignoreTranslucentMeshes = rayTest->IgnoreTranslucentMeshes;
	}

	RayCollisionTestClass::RayCollisionTestClass(IRayCollisionTestClass ^rayTest)
		: CollisionTestClass(rayTest)
	{
		if (rayTest == nullptr || rayTest->RayCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("rayTest");
		}

		ray = rayTest->Ray;
		ignoreTranslucentMeshes = rayTest->IgnoreTranslucentMeshes;
	}

	RayCollisionTestClass::RayCollisionTestClass(RayCollisionTestClass ^rayTest)
		: CollisionTestClass(rayTest)
	{
		if (rayTest == nullptr)
		{
			throw gcnew ArgumentNullException("rayTest");
		}

		ray = rayTest->Ray;
		ignoreTranslucentMeshes = rayTest->IgnoreTranslucentMeshes;
	}

	void RayCollisionTestClass::CopyFrom(IRayCollisionTestClass ^rayTest)
	{
		if (rayTest == nullptr || rayTest->RayCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("rayTest");
		}

		CollisionTestClass::CopyFrom(rayTest);

		ray = rayTest->Ray;
		ignoreTranslucentMeshes = rayTest->IgnoreTranslucentMeshes;
	}

	void RayCollisionTestClass::CopyFrom(RayCollisionTestClass ^rayTest)
	{
		if (rayTest == nullptr)
		{
			throw gcnew ArgumentNullException("rayTest");
		}

		CollisionTestClass::CopyFrom(rayTest);

		ray = rayTest->Ray;
		ignoreTranslucentMeshes = rayTest->IgnoreTranslucentMeshes;
	}

	LineSegClass RayCollisionTestClass::Ray::get()
	{
		return ray;
	}

	void RayCollisionTestClass::Ray::set(LineSegClass value)
	{
		ray = value;
	}

	bool RayCollisionTestClass::IgnoreTranslucentMeshes::get()
	{
		return ignoreTranslucentMeshes;
	}

	void RayCollisionTestClass::IgnoreTranslucentMeshes::set(bool value)
	{
		ignoreTranslucentMeshes = value;
	}

	AABoxCollisionTestClassRef::AABoxCollisionTestClassRef(AABoxClass aabox, Vector3 move, RenSharp::CollisionType collisionType)
	{
		::AABoxClass aaboxBox;
		::Vector3 moveVec;

		AABoxClass::ManagedToUnmanagedAABoxClass(aabox, aaboxBox);
		Vector3::ManagedToUnmanagedVector3(move, moveVec);

		Pointer = IntPtr(Imports::CreateAABoxCollisionTestClass1(&aaboxBox, &moveVec, static_cast<::Collision_Type>(collisionType)));
	}

	AABoxCollisionTestClassRef::AABoxCollisionTestClassRef(AABoxClass aabox, Vector3 move)
	{
		::AABoxClass aaboxBox;
		::Vector3 moveVec;

		AABoxClass::ManagedToUnmanagedAABoxClass(aabox, aaboxBox);
		Vector3::ManagedToUnmanagedVector3(move, moveVec);

		Pointer = IntPtr(Imports::CreateAABoxCollisionTestClass2(&aaboxBox, &moveVec));
	}

	AABoxCollisionTestClassRef::AABoxCollisionTestClassRef()
	{

	}

	AABoxCollisionTestClassRef::AABoxCollisionTestClassRef(IntPtr pointer)
		: CollisionTestClassRef(pointer)
	{

	}

	IUnmanagedContainer<IAABoxCollisionTestClass ^> ^AABoxCollisionTestClassRef::CreateAABoxCollisionTestClassRef(
		AABoxClass aabox,
		Vector3 move,
		RenSharp::CollisionType collisionType)
	{
		return gcnew UnmanagedContainer<IAABoxCollisionTestClass ^>(gcnew AABoxCollisionTestClassRef(aabox, move, collisionType));
	}

	IUnmanagedContainer<IAABoxCollisionTestClass ^> ^AABoxCollisionTestClassRef::CreateAABoxCollisionTestClassRef(
		AABoxClass aabox,
		Vector3 move)
	{
		return gcnew UnmanagedContainer<IAABoxCollisionTestClass ^>(gcnew AABoxCollisionTestClassRef(aabox, move));
	}

	CollisionTestClass ^AABoxCollisionTestClassRef::ToCollisionTestClass()
	{
		return ToAABoxCollisionTestClass();
	}

	AABoxCollisionTestClass ^AABoxCollisionTestClassRef::ToAABoxCollisionTestClass()
	{
		return gcnew AABoxCollisionTestClass(this);
	}

	bool AABoxCollisionTestClassRef::Cull(Vector3 min, Vector3 max)
	{
		::Vector3 minVec;
		::Vector3 maxVec;

		Vector3::ManagedToUnmanagedVector3(min, minVec);
		Vector3::ManagedToUnmanagedVector3(max, maxVec);

		return InternalAABoxCollisionTestClassPointer->Cull(minVec, maxVec);
	}

	bool AABoxCollisionTestClassRef::Cull(AABoxClass box)
	{
		::AABoxClass boxBox;

		AABoxClass::ManagedToUnmanagedAABoxClass(box, boxBox);

		return InternalAABoxCollisionTestClassPointer->Cull(boxBox);
	}

	void AABoxCollisionTestClassRef::Translate(Vector3 translation)
	{
		::Vector3 translationVec;

		Vector3::ManagedToUnmanagedVector3(translation, translationVec);

		InternalAABoxCollisionTestClassPointer->Translate(translationVec);
	}

	void AABoxCollisionTestClassRef::Rotate(IAABoxCollisionTestClass::RotationType rotation)
	{
		InternalAABoxCollisionTestClassPointer->Rotate(static_cast<::AABoxCollisionTestClass::ROTATION_TYPE>(rotation));
	}

	void AABoxCollisionTestClassRef::Transform(Matrix3D tm)
	{
		::Matrix3D tmMat;
		
		Matrix3D::ManagedToUnmanagedMatrix3D(tm, tmMat);

		InternalAABoxCollisionTestClassPointer->Transform(tmMat);
	}

	IntPtr AABoxCollisionTestClassRef::AABoxCollisionTestClassPointer::get()
	{
		return IntPtr(InternalAABoxCollisionTestClassPointer);
	}

	AABoxClass AABoxCollisionTestClassRef::Box::get()
	{
		AABoxClass result;

		AABoxClass::UnmanagedToManagedAABoxClass(InternalAABoxCollisionTestClassPointer->Box, result);

		return result;
	}

	void AABoxCollisionTestClassRef::Box::set(AABoxClass value)
	{
		AABoxClass::ManagedToUnmanagedAABoxClass(value, InternalAABoxCollisionTestClassPointer->Box);
	}

	Vector3 AABoxCollisionTestClassRef::Move::get()
	{
		Vector3 result;

		Vector3::UnmanagedToManagedVector3(InternalAABoxCollisionTestClassPointer->Move, result);

		return result;
	}

	void AABoxCollisionTestClassRef::Move::set(Vector3 value)
	{
		Vector3::ManagedToUnmanagedVector3(value, InternalAABoxCollisionTestClassPointer->Move);
	}

	Vector3 AABoxCollisionTestClassRef::SweepMin::get()
	{
		Vector3 result;

		Vector3::UnmanagedToManagedVector3(InternalAABoxCollisionTestClassPointer->SweepMin, result);

		return result;
	}

	void AABoxCollisionTestClassRef::SweepMin::set(Vector3 value)
	{
		Vector3::ManagedToUnmanagedVector3(value, InternalAABoxCollisionTestClassPointer->SweepMin);
	}

	Vector3 AABoxCollisionTestClassRef::SweepMax::get()
	{
		Vector3 result;

		Vector3::UnmanagedToManagedVector3(InternalAABoxCollisionTestClassPointer->SweepMax, result);

		return result;
	}

	void AABoxCollisionTestClassRef::SweepMax::set(Vector3 value)
	{
		Vector3::ManagedToUnmanagedVector3(value, InternalAABoxCollisionTestClassPointer->SweepMax);
	}

	bool AABoxCollisionTestClassRef::InternalDestroyPointer()
	{
		Imports::DestroyAABoxCollisionTestClass(InternalAABoxCollisionTestClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::CollisionTestClass *AABoxCollisionTestClassRef::InternalCollisionTestClassPointer::get()
	{
		return InternalAABoxCollisionTestClassPointer;
	}

	::AABoxCollisionTestClass *AABoxCollisionTestClassRef::InternalAABoxCollisionTestClassPointer::get()
	{
		return reinterpret_cast<::AABoxCollisionTestClass *>(Pointer.ToPointer());
	}

	RenSharpAABoxCollisionTestClass::RenSharpAABoxCollisionTestClass(
		AABoxClass aabox,
		Vector3 move,
		RenSharp::CollisionType collisionType)
	{
		::AABoxClass aaboxBox;
		::Vector3 moveVec;

		AABoxClass::ManagedToUnmanagedAABoxClass(aabox, aaboxBox);
		Vector3::ManagedToUnmanagedVector3(move, moveVec);

		Pointer = IntPtr(Imports::CreateRenSharpAABoxCollisionTestClass1(
			&aaboxBox,
			&moveVec, 
			static_cast<::Collision_Type>(collisionType)));
	}

	RenSharpAABoxCollisionTestClass::RenSharpAABoxCollisionTestClass(AABoxClass aabox, Vector3 move)
	{
		::AABoxClass aaboxBox;
		::Vector3 moveVec;

		AABoxClass::ManagedToUnmanagedAABoxClass(aabox, aaboxBox);
		Vector3::ManagedToUnmanagedVector3(move, moveVec);

		Pointer = IntPtr(Imports::CreateRenSharpAABoxCollisionTestClass2(
			&aaboxBox,
			&moveVec));
	}

	RenSharpAABoxCollisionTestClass::RenSharpAABoxCollisionTestClass(
		AABoxClass aabox,
		Vector3 move,
		Nullable<CastResultStruct> res,
		RenSharp::CollisionType collisionType)
		: RenSharpAABoxCollisionTestClass(aabox, move, collisionType)
	{
		if (res.HasValue)
		{
			::CastResultStruct resStruct;

			CastResultStruct::ManagedToUnmanagedCastResultStruct(res.Value, resStruct);

			Imports::RenSharpAABoxCollisionTestClassSetResult(InternalRenSharpAABoxCollisionTestClassPointer, &resStruct);
		}
	}

	RenSharpAABoxCollisionTestClass::RenSharpAABoxCollisionTestClass(AABoxClass aabox, Vector3 move, Nullable<CastResultStruct> res)
		: RenSharpAABoxCollisionTestClass(aabox, move)
	{
		if (res.HasValue)
		{
			::CastResultStruct resStruct;

			CastResultStruct::ManagedToUnmanagedCastResultStruct(res.Value, resStruct);

			Imports::RenSharpAABoxCollisionTestClassSetResult(InternalRenSharpAABoxCollisionTestClassPointer, &resStruct);
		}
	}

	RenSharpAABoxCollisionTestClass::RenSharpAABoxCollisionTestClass(AABoxCollisionTestClass ^boxTest)
	{
		if (boxTest == nullptr)
		{
			throw gcnew ArgumentNullException("boxTest");
		}

		::AABoxClass aaboxBox;
		::Vector3 moveVec;
		::CastResultStruct res;

		AABoxClass::ManagedToUnmanagedAABoxClass(boxTest->Box, aaboxBox);
		Vector3::ManagedToUnmanagedVector3(boxTest->Move, moveVec);
		CastResultStruct::ManagedToUnmanagedCastResultStruct(boxTest->Result, res);

		Pointer = IntPtr(Imports::CreateRenSharpAABoxCollisionTestClass1(
			&aaboxBox,
			&moveVec,
			static_cast<::Collision_Type>(boxTest->CollisionType)));

		Imports::RenSharpAABoxCollisionTestClassSetResult(InternalRenSharpAABoxCollisionTestClassPointer, &res);

		CollidedRenderObj = boxTest->CollidedRenderObj;
		SweepMin = boxTest->SweepMin;
		SweepMax = boxTest->SweepMax;
	}

	RenSharpAABoxCollisionTestClass::RenSharpAABoxCollisionTestClass(IntPtr pointer)
		: AABoxCollisionTestClassRef(pointer)
	{

	}

	IUnmanagedContainer<IAABoxCollisionTestClass ^> ^RenSharpAABoxCollisionTestClass::CreateRenSharpAABoxCollisionTestClass(
		AABoxClass aabox,
		Vector3 move,
		RenSharp::CollisionType collisionType)
	{
		return gcnew UnmanagedContainer<IAABoxCollisionTestClass ^>(gcnew RenSharpAABoxCollisionTestClass(aabox, move, collisionType));
	}

	IUnmanagedContainer<IAABoxCollisionTestClass ^> ^RenSharpAABoxCollisionTestClass::CreateRenSharpAABoxCollisionTestClass(
		AABoxClass aabox,
		Vector3 move)
	{
		return gcnew UnmanagedContainer<IAABoxCollisionTestClass ^>(gcnew RenSharpAABoxCollisionTestClass(aabox, move));
	}

	IUnmanagedContainer<IAABoxCollisionTestClass ^> ^RenSharpAABoxCollisionTestClass::CreateRenSharpAABoxCollisionTestClass(
		AABoxClass aabox,
		Vector3 move,
		Nullable<CastResultStruct> res,
		RenSharp::CollisionType collisionType)
	{
		return gcnew UnmanagedContainer<IAABoxCollisionTestClass ^>(gcnew RenSharpAABoxCollisionTestClass(aabox, move, res, collisionType));
	}

	IUnmanagedContainer<IAABoxCollisionTestClass ^> ^RenSharpAABoxCollisionTestClass::CreateRenSharpAABoxCollisionTestClass(
		AABoxClass aabox,
		Vector3 move,
		Nullable<CastResultStruct> res)
	{
		return gcnew UnmanagedContainer<IAABoxCollisionTestClass ^>(gcnew RenSharpAABoxCollisionTestClass(aabox, move, res));
	}

	IUnmanagedContainer<IAABoxCollisionTestClass ^> ^RenSharpAABoxCollisionTestClass::CreateRenSharpAABoxCollisionTestClass(
		AABoxCollisionTestClass ^boxTest)
	{
		return gcnew UnmanagedContainer<IAABoxCollisionTestClass ^>(gcnew RenSharpAABoxCollisionTestClass(boxTest));
	}

	IntPtr RenSharpAABoxCollisionTestClass::RenSharpAABoxCollisionTestClassPointer::get()
	{
		return IntPtr(InternalRenSharpAABoxCollisionTestClassPointer);
	}

	Nullable<CastResultStruct> RenSharpAABoxCollisionTestClass::Result::get()
	{
		return CollisionTestClassRef::Result::get();
	}

	void RenSharpAABoxCollisionTestClass::Result::set(Nullable<CastResultStruct> value)
	{
		if (value.HasValue)
		{
			::CastResultStruct res;

			CastResultStruct::ManagedToUnmanagedCastResultStruct(value.Value, res);

			Imports::RenSharpAABoxCollisionTestClassSetResult(InternalRenSharpAABoxCollisionTestClassPointer, &res);
		}
		else
		{
			InternalAABoxCollisionTestClassPointer->Result = nullptr;
		}
	}

	bool RenSharpAABoxCollisionTestClass::InternalDestroyPointer()
	{
		Imports::DestroyRenSharpAABoxCollisionTestClass(InternalRenSharpAABoxCollisionTestClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::RenSharpAABoxCollisionTestClass *RenSharpAABoxCollisionTestClass::InternalRenSharpAABoxCollisionTestClassPointer::get()
	{
		return reinterpret_cast<::RenSharpAABoxCollisionTestClass *>(Pointer.ToPointer());
	}

	AABoxCollisionTestClass::AABoxCollisionTestClass(AABoxClass aabox, Vector3 move, RenSharp::CollisionType collisionType)
		: CollisionTestClass(collisionType), box(aabox), move(move)
	{
		sweepMin = Vector3::operator-(aabox.Center, aabox.Extent);
		sweepMax = Vector3::operator+(aabox.Center, aabox.Extent);
		Vector3 endmin = Vector3::operator-(Vector3::operator+(aabox.Center, move), aabox.Extent);
		Vector3 endmax = Vector3::operator+(Vector3::operator+(aabox.Center, move), aabox.Extent);
		if (endmax.X > sweepMax.X) sweepMax.X = endmax.X;
		if (endmax.Y > sweepMax.Y) sweepMax.Y = endmax.Y;
		if (endmax.Z > sweepMax.Z) sweepMax.Z = endmax.Z;
		if (endmin.X < sweepMin.X) sweepMin.X = endmin.X;
		if (endmin.Y < sweepMin.Y) sweepMin.Y = endmin.Y;
		if (endmin.Z < sweepMin.Z) sweepMin.Z = endmin.Z;
	}

	AABoxCollisionTestClass::AABoxCollisionTestClass(AABoxClass aabox, Vector3 move)
		: AABoxCollisionTestClass(aabox, move, RenSharp::CollisionType::CollisionType0)
	{

	}

	AABoxCollisionTestClass::AABoxCollisionTestClass(
		AABoxClass aabox,
		Vector3 move,
		CastResultStruct res,
		RenSharp::CollisionType collisionType)
		: CollisionTestClass(res, collisionType), box(aabox), move(move)
	{
		sweepMin = Vector3::operator-(aabox.Center, aabox.Extent);
		sweepMax = Vector3::operator+(aabox.Center, aabox.Extent);
		Vector3 endmin = Vector3::operator-(Vector3::operator+(aabox.Center, move), aabox.Extent);
		Vector3 endmax = Vector3::operator+(Vector3::operator+(aabox.Center, move), aabox.Extent);
		if (endmax.X > sweepMax.X) sweepMax.X = endmax.X;
		if (endmax.Y > sweepMax.Y) sweepMax.Y = endmax.Y;
		if (endmax.Z > sweepMax.Z) sweepMax.Z = endmax.Z;
		if (endmin.X < sweepMin.X) sweepMin.X = endmin.X;
		if (endmin.Y < sweepMin.Y) sweepMin.Y = endmin.Y;
		if (endmin.Z < sweepMin.Z) sweepMin.Z = endmin.Z;
	}

	AABoxCollisionTestClass::AABoxCollisionTestClass(AABoxClass aabox, Vector3 move, CastResultStruct res)
		: AABoxCollisionTestClass(aabox, move, res, RenSharp::CollisionType::CollisionType0)
	{

	}

	AABoxCollisionTestClass::AABoxCollisionTestClass(IAABoxCollisionTestClass ^boxTest)
		: CollisionTestClass(boxTest)
	{
		if (boxTest == nullptr || boxTest->AABoxCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("boxTest");
		}

		box = boxTest->Box;
		move = boxTest->Move;
		sweepMin = boxTest->SweepMin;
		sweepMax = boxTest->SweepMax;
	}

	AABoxCollisionTestClass::AABoxCollisionTestClass(AABoxCollisionTestClass ^boxTest)
		: CollisionTestClass(boxTest)
	{
		if (boxTest == nullptr)
		{
			throw gcnew ArgumentNullException("boxTest");
		}

		box = boxTest->Box;
		move = boxTest->Move;
		sweepMin = boxTest->SweepMin;
		sweepMax = boxTest->SweepMax;
	}

	void AABoxCollisionTestClass::CopyFrom(IAABoxCollisionTestClass ^boxTest)
	{
		if (boxTest == nullptr || boxTest->AABoxCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("boxTest");
		}

		CollisionTestClass::CopyFrom(boxTest);

		box = boxTest->Box;
		move = boxTest->Move;
		sweepMin = boxTest->SweepMin;
		sweepMax = boxTest->SweepMax;
	}

	void AABoxCollisionTestClass::CopyFrom(AABoxCollisionTestClass ^boxTest)
	{
		if (boxTest == nullptr)
		{
			throw gcnew ArgumentNullException("boxTest");
		}

		CollisionTestClass::CopyFrom(boxTest);

		box = boxTest->Box;
		move = boxTest->Move;
		sweepMin = boxTest->SweepMin;
		sweepMax = boxTest->SweepMax;
	}

	bool AABoxCollisionTestClass::Cull(Vector3 min, Vector3 max)
	{
		if ((sweepMin.X > max.X) || (sweepMax.X < min.X))
		{
			return true;
		}
		if ((sweepMin.Y > max.Y) || (sweepMax.Y < min.Y))
		{
			return true;
		}
		if ((sweepMin.Z > max.Z) || (sweepMax.Z < min.Z))
		{
			return true;
		}

		return false;
	}

	bool AABoxCollisionTestClass::Cull(AABoxClass box)
	{
		Vector3 minCorner = Vector3::Subtract(box.Center, box.Extent);
		Vector3 maxCorner = Vector3::Add(box.Center, box.Extent);

		return Cull(minCorner, maxCorner);
	}

	void AABoxCollisionTestClass::Translate(Vector3 translation)
	{
		box.Center = Vector3::operator+(box.Center, translation);
		sweepMin = Vector3::operator+(sweepMin, translation);
		sweepMax = Vector3::operator+(sweepMax, translation);
	}

	void AABoxCollisionTestClass::Rotate(IAABoxCollisionTestClass::RotationType rotation)
	{
		float tmp, minx, miny, maxx, maxy;
		switch (rotation)
		{
			case IAABoxCollisionTestClass::RotationType::RotateNone:
				break;
			case IAABoxCollisionTestClass::RotationType::RotateZ90:
				tmp = box.Center.X; box.Center.X = -box.Center.Y; box.Center.Y = tmp;
				tmp = move.X; move.X = -move.Y;	move.Y = tmp;
				tmp = box.Extent.X; box.Extent.X = box.Extent.Y; box.Extent.Y = tmp;
				minx = sweepMin.X; miny = sweepMin.Y; maxx = sweepMax.X; maxy = sweepMax.Y;
				sweepMin.X = -maxy;
				sweepMin.Y = minx;
				sweepMax.X = -miny;
				sweepMax.Y = maxx;
				break;
			case IAABoxCollisionTestClass::RotationType::RotateZ180:
				box.Center.X = -box.Center.X;
				box.Center.Y = -box.Center.Y;
				move.X = -move.X;
				move.Y = -move.Y;
				minx = sweepMin.X; miny = sweepMin.Y; maxx = sweepMax.X; maxy = sweepMax.Y;
				sweepMin.X = -maxx;
				sweepMin.Y = -maxy;
				sweepMax.X = -minx;
				sweepMax.Y = -miny;
				break;
			case IAABoxCollisionTestClass::RotationType::RotateZ270:
				tmp = box.Center.X; box.Center.X = box.Center.Y; box.Center.Y = -tmp;
				tmp = move.X; move.X = move.Y; move.Y = -tmp;
				tmp = box.Extent.X; box.Extent.X = box.Extent.Y; box.Extent.Y = tmp;
				minx = sweepMin.X; miny = sweepMin.Y; maxx = sweepMax.X; maxy = sweepMax.Y;
				sweepMin.X = miny;
				sweepMin.Y = -maxx;
				sweepMax.X = maxy;
				sweepMax.Y = -minx;
				break;
		}
	}

	void AABoxCollisionTestClass::Transform(Matrix3D tm)
	{
		Vector3 tmpcenter = box.Center;
		Vector3 tmpextent = box.Extent;

		tm.TransformCenterExtentAABox(tmpcenter, tmpextent, box.Center, box.Extent);

		move = tm.RotateVector(move);

		array<Vector3> ^pts = gcnew array<Vector3>(8);

		pts[0].Set(sweepMin.X, sweepMin.Y, sweepMin.Z);
		pts[1].Set(sweepMin.X, sweepMax.Y, sweepMin.Z);
		pts[2].Set(sweepMax.X, sweepMax.Y, sweepMin.Z);
		pts[3].Set(sweepMax.X, sweepMin.Y, sweepMin.Z);
		pts[4].Set(sweepMin.X, sweepMin.Y, sweepMax.Z);
		pts[5].Set(sweepMin.X, sweepMax.Y, sweepMax.Z);
		pts[6].Set(sweepMax.X, sweepMax.Y, sweepMax.Z);
		pts[7].Set(sweepMax.X, sweepMin.Y, sweepMax.Z);

		for (int i = 0; i < pts->Length; i++)
		{
			pts[i] = tm * pts[i];
		}

		Vector3 realmin = pts[0];
		Vector3 realmax = pts[0];

		for (int i = 1; i < pts->Length; i++)
		{
			if (realmin.X >= pts[i].X) realmin.X = pts[i].X;
			if (realmin.Y >= pts[i].Y) realmin.Y = pts[i].Y;
			if (realmin.Z >= pts[i].Z) realmin.Z = pts[i].Z;
			if (realmax.X <= pts[i].X) realmax.X = pts[i].X;
			if (realmax.Y <= pts[i].Y) realmax.Y = pts[i].Y;
			if (realmax.Z <= pts[i].Z) realmax.Z = pts[i].Z;
		}

		sweepMin = realmin;
		sweepMax = realmax;
	}

	AABoxClass AABoxCollisionTestClass::Box::get()
	{
		return box;
	}

	void AABoxCollisionTestClass::Box::set(AABoxClass value)
	{
		box = value;
	}

	Vector3 AABoxCollisionTestClass::Move::get()
	{
		return move;
	}

	void AABoxCollisionTestClass::Move::set(Vector3 value)
	{
		move = value;
	}

	Vector3 AABoxCollisionTestClass::SweepMin::get()
	{
		return sweepMin;
	}

	void AABoxCollisionTestClass::SweepMin::set(Vector3 value)
	{
		sweepMin = value;
	}

	Vector3 AABoxCollisionTestClass::SweepMax::get()
	{
		return sweepMax;
	}

	void AABoxCollisionTestClass::SweepMax::set(Vector3 value)
	{
		sweepMax = value;
	}

	OBBoxCollisionTestClassRef::OBBoxCollisionTestClassRef(OBBoxClass obbox, Vector3 move, RenSharp::CollisionType collisionType)
	{
		::OBBoxClass obboxBox;
		::Vector3 moveVec;

		OBBoxClass::ManagedToUnmanagedOBBoxClass(obbox, obboxBox);
		Vector3::ManagedToUnmanagedVector3(move, moveVec);

		Pointer = IntPtr(Imports::CreateOBBoxCollisionTestClass1(&obboxBox, &moveVec, static_cast<::Collision_Type>(collisionType)));
	}

	OBBoxCollisionTestClassRef::OBBoxCollisionTestClassRef(OBBoxClass obbox, Vector3 move)
	{
		::OBBoxClass obboxBox;
		::Vector3 moveVec;

		OBBoxClass::ManagedToUnmanagedOBBoxClass(obbox, obboxBox);
		Vector3::ManagedToUnmanagedVector3(move, moveVec);

		Pointer = IntPtr(Imports::CreateOBBoxCollisionTestClass2(&obboxBox, &moveVec));
	}

	OBBoxCollisionTestClassRef::OBBoxCollisionTestClassRef(IOBBoxCollisionTestClass ^that, Matrix3D tm)
	{
		if (that == nullptr || that->OBBoxCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("that");
		}

		::Matrix3D tmMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(tm, tmMat);

		Pointer = IntPtr(Imports::CreateOBBoxCollisionTestClass3(
			reinterpret_cast<::OBBoxCollisionTestClass *>(that->OBBoxCollisionTestClassPointer.ToPointer()),
			&tmMat));
	}

	OBBoxCollisionTestClassRef::OBBoxCollisionTestClassRef(IAABoxCollisionTestClass ^that, Matrix3D tm)
	{
		if (that == nullptr || that->AABoxCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("that");
		}

		::Matrix3D tmMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(tm, tmMat);

		Pointer = IntPtr(Imports::CreateOBBoxCollisionTestClass4(
			reinterpret_cast<::AABoxCollisionTestClass *>(that->AABoxCollisionTestClassPointer.ToPointer()),
			&tmMat));
	}

	OBBoxCollisionTestClassRef::OBBoxCollisionTestClassRef()
	{

	}

	OBBoxCollisionTestClassRef::OBBoxCollisionTestClassRef(IntPtr pointer)
		: CollisionTestClassRef(pointer)
	{

	}

	IUnmanagedContainer<IOBBoxCollisionTestClass ^> ^OBBoxCollisionTestClassRef::CreateOBBoxCollisionTestClassRef(
		OBBoxClass obbox,
		Vector3 move,
		RenSharp::CollisionType collisionType)
	{
		return gcnew UnmanagedContainer<IOBBoxCollisionTestClass ^>(gcnew OBBoxCollisionTestClassRef(obbox, move, collisionType));
	}

	IUnmanagedContainer<IOBBoxCollisionTestClass ^> ^OBBoxCollisionTestClassRef::CreateOBBoxCollisionTestClassRef(
		OBBoxClass obbox,
		Vector3 move)
	{
		return gcnew UnmanagedContainer<IOBBoxCollisionTestClass ^>(gcnew OBBoxCollisionTestClassRef(obbox, move));
	}

	IUnmanagedContainer<IOBBoxCollisionTestClass ^> ^OBBoxCollisionTestClassRef::CreateOBBoxCollisionTestClassRef(
		IOBBoxCollisionTestClass ^that,
		Matrix3D tm)
	{
		return gcnew UnmanagedContainer<IOBBoxCollisionTestClass ^>(gcnew OBBoxCollisionTestClassRef(that, tm));
	}

	IUnmanagedContainer<IOBBoxCollisionTestClass ^> ^OBBoxCollisionTestClassRef::CreateOBBoxCollisionTestClassRef(
		IAABoxCollisionTestClass ^that,
		Matrix3D tm)
	{
		return gcnew UnmanagedContainer<IOBBoxCollisionTestClass ^>(gcnew OBBoxCollisionTestClassRef(that, tm));
	}

	CollisionTestClass ^OBBoxCollisionTestClassRef::ToCollisionTestClass()
	{
		return ToOBBoxCollisionTestClass();
	}

	OBBoxCollisionTestClass ^OBBoxCollisionTestClassRef::ToOBBoxCollisionTestClass()
	{
		return gcnew OBBoxCollisionTestClass(this);
	}

	bool OBBoxCollisionTestClassRef::Cull(Vector3 min, Vector3 max)
	{
		::Vector3 minVec;
		::Vector3 maxVec;

		Vector3::ManagedToUnmanagedVector3(min, minVec);
		Vector3::ManagedToUnmanagedVector3(max, maxVec);

		return InternalOBBoxCollisionTestClassPointer->Cull(minVec, maxVec);
	}

	bool OBBoxCollisionTestClassRef::Cull(AABoxClass box)
	{
		::AABoxClass boxBox;

		AABoxClass::ManagedToUnmanagedAABoxClass(box, boxBox);

		return InternalOBBoxCollisionTestClassPointer->Cull(boxBox);
	}

	IntPtr OBBoxCollisionTestClassRef::OBBoxCollisionTestClassPointer::get()
	{
		return IntPtr(InternalOBBoxCollisionTestClassPointer);
	}

	OBBoxClass OBBoxCollisionTestClassRef::Box::get()
	{
		OBBoxClass result;

		OBBoxClass::UnmanagedToManagedOBBoxClass(InternalOBBoxCollisionTestClassPointer->Box, result);

		return result;
	}

	void OBBoxCollisionTestClassRef::Box::set(OBBoxClass value)
	{
		OBBoxClass::ManagedToUnmanagedOBBoxClass(value, InternalOBBoxCollisionTestClassPointer->Box);
	}

	Vector3 OBBoxCollisionTestClassRef::Move::get()
	{
		Vector3 result;

		Vector3::UnmanagedToManagedVector3(InternalOBBoxCollisionTestClassPointer->Move, result);

		return result;
	}

	void OBBoxCollisionTestClassRef::Move::set(Vector3 value)
	{
		Vector3::ManagedToUnmanagedVector3(value, InternalOBBoxCollisionTestClassPointer->Move);
	}

	Vector3 OBBoxCollisionTestClassRef::SweepMin::get()
	{
		Vector3 result;

		Vector3::UnmanagedToManagedVector3(InternalOBBoxCollisionTestClassPointer->SweepMin, result);

		return result;
	}

	void OBBoxCollisionTestClassRef::SweepMin::set(Vector3 value)
	{
		Vector3::ManagedToUnmanagedVector3(value, InternalOBBoxCollisionTestClassPointer->SweepMin);
	}

	Vector3 OBBoxCollisionTestClassRef::SweepMax::get()
	{
		Vector3 result;

		Vector3::UnmanagedToManagedVector3(InternalOBBoxCollisionTestClassPointer->SweepMax, result);

		return result;
	}

	void OBBoxCollisionTestClassRef::SweepMax::set(Vector3 value)
	{
		Vector3::ManagedToUnmanagedVector3(value, InternalOBBoxCollisionTestClassPointer->SweepMax);
	}

	bool OBBoxCollisionTestClassRef::InternalDestroyPointer()
	{
		Imports::DestroyOBBoxCollisionTestClass(InternalOBBoxCollisionTestClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::CollisionTestClass *OBBoxCollisionTestClassRef::InternalCollisionTestClassPointer::get()
	{
		return InternalOBBoxCollisionTestClassPointer;
	}

	::OBBoxCollisionTestClass *OBBoxCollisionTestClassRef::InternalOBBoxCollisionTestClassPointer::get()
	{
		return reinterpret_cast<::OBBoxCollisionTestClass *>(Pointer.ToPointer());
	}

	RenSharpOBBoxCollisionTestClass::RenSharpOBBoxCollisionTestClass(
		OBBoxClass obbox,
		Vector3 move,
		RenSharp::CollisionType collisionType)
	{
		::OBBoxClass obboxBox;
		::Vector3 moveVec;

		OBBoxClass::ManagedToUnmanagedOBBoxClass(obbox, obboxBox);
		Vector3::ManagedToUnmanagedVector3(move, moveVec);

		Pointer = IntPtr(Imports::CreateRenSharpOBBoxCollisionTestClass1(
			&obboxBox,
			&moveVec,
			static_cast<::Collision_Type>(collisionType)));
	}

	RenSharpOBBoxCollisionTestClass::RenSharpOBBoxCollisionTestClass(OBBoxClass obbox, Vector3 move)
	{
		::OBBoxClass obboxBox;
		::Vector3 moveVec;

		OBBoxClass::ManagedToUnmanagedOBBoxClass(obbox, obboxBox);
		Vector3::ManagedToUnmanagedVector3(move, moveVec);

		Pointer = IntPtr(Imports::CreateRenSharpOBBoxCollisionTestClass2(
			&obboxBox,
			&moveVec));
	}

	RenSharpOBBoxCollisionTestClass::RenSharpOBBoxCollisionTestClass(
		OBBoxClass obbox,
		Vector3 move,
		Nullable<CastResultStruct> res,
		RenSharp::CollisionType collisionType)
		: RenSharpOBBoxCollisionTestClass(obbox, move, collisionType)
	{
		if (res.HasValue)
		{
			::CastResultStruct resStruct;

			CastResultStruct::ManagedToUnmanagedCastResultStruct(res.Value, resStruct);

			Imports::RenSharpOBBoxCollisionTestClassSetResult(InternalRenSharpOBBoxCollisionTestClassPointer, &resStruct);
		}
	}

	RenSharpOBBoxCollisionTestClass::RenSharpOBBoxCollisionTestClass(
		OBBoxClass obbox,
		Vector3 move,
		Nullable<CastResultStruct> res)
		: RenSharpOBBoxCollisionTestClass(obbox, move)
	{
		if (res.HasValue)
		{
			::CastResultStruct resStruct;

			CastResultStruct::ManagedToUnmanagedCastResultStruct(res.Value, resStruct);

			Imports::RenSharpOBBoxCollisionTestClassSetResult(InternalRenSharpOBBoxCollisionTestClassPointer, &resStruct);
		}
	}

	RenSharpOBBoxCollisionTestClass::RenSharpOBBoxCollisionTestClass(IOBBoxCollisionTestClass ^that, Matrix3D tm)
	{
		if (that == nullptr || that->OBBoxCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("that");
		}

		::Matrix3D tmMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(tm, tmMat);

		Pointer = IntPtr(Imports::CreateRenSharpOBBoxCollisionTestClass3(
			reinterpret_cast<::OBBoxCollisionTestClass *>(that->OBBoxCollisionTestClassPointer.ToPointer()),
			&tmMat));
	}

	RenSharpOBBoxCollisionTestClass::RenSharpOBBoxCollisionTestClass(IAABoxCollisionTestClass ^that, Matrix3D tm)
	{
		if (that == nullptr || that->AABoxCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("that");
		}

		::Matrix3D tmMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(tm, tmMat);

		Pointer = IntPtr(Imports::CreateRenSharpOBBoxCollisionTestClass4(
			reinterpret_cast<::AABoxCollisionTestClass *>(that->AABoxCollisionTestClassPointer.ToPointer()),
			&tmMat));
	}

	RenSharpOBBoxCollisionTestClass::RenSharpOBBoxCollisionTestClass(OBBoxCollisionTestClass ^boxTest)
	{
		if (boxTest == nullptr)
		{
			throw gcnew ArgumentNullException("boxTest");
		}

		::OBBoxClass obboxBox;
		::Vector3 moveVec;

		OBBoxClass::ManagedToUnmanagedOBBoxClass(boxTest->Box, obboxBox);
		Vector3::ManagedToUnmanagedVector3(boxTest->Move, moveVec);

		Pointer = IntPtr(Imports::CreateRenSharpOBBoxCollisionTestClass1(
			&obboxBox,
			&moveVec,
			static_cast<::Collision_Type>(boxTest->CollisionType)));

		::CastResultStruct res;

		CastResultStruct::ManagedToUnmanagedCastResultStruct(boxTest->Result, res);

		Imports::RenSharpOBBoxCollisionTestClassSetResult(InternalRenSharpOBBoxCollisionTestClassPointer, &res);

		SweepMin = boxTest->SweepMin;
		SweepMax = boxTest->SweepMax;
	}

	RenSharpOBBoxCollisionTestClass::RenSharpOBBoxCollisionTestClass(IntPtr pointer)
		: OBBoxCollisionTestClassRef(pointer)
	{

	}

	IUnmanagedContainer<IOBBoxCollisionTestClass ^> ^RenSharpOBBoxCollisionTestClass::CreateRenSharpOBBoxCollisionTestClass(
		OBBoxClass obbox,
		Vector3 move,
		RenSharp::CollisionType collisionType)
	{
		return gcnew UnmanagedContainer<IOBBoxCollisionTestClass ^>(gcnew RenSharpOBBoxCollisionTestClass(obbox, move, collisionType));
	}

	IUnmanagedContainer<IOBBoxCollisionTestClass ^> ^RenSharpOBBoxCollisionTestClass::CreateRenSharpOBBoxCollisionTestClass(
		OBBoxClass obbox,
		Vector3 move)
	{
		return gcnew UnmanagedContainer<IOBBoxCollisionTestClass ^>(gcnew RenSharpOBBoxCollisionTestClass(obbox, move));
	}

	IUnmanagedContainer<IOBBoxCollisionTestClass ^> ^RenSharpOBBoxCollisionTestClass::CreateRenSharpOBBoxCollisionTestClass(
		OBBoxClass obbox,
		Vector3 move,
		Nullable<CastResultStruct> res,
		RenSharp::CollisionType collisionType)
	{
		return gcnew UnmanagedContainer<IOBBoxCollisionTestClass ^>(gcnew RenSharpOBBoxCollisionTestClass(obbox, move, res, collisionType));
	}

	IUnmanagedContainer<IOBBoxCollisionTestClass ^> ^RenSharpOBBoxCollisionTestClass::CreateRenSharpOBBoxCollisionTestClass(
		OBBoxClass obbox,
		Vector3 move,
		Nullable<CastResultStruct> res)
	{
		return gcnew UnmanagedContainer<IOBBoxCollisionTestClass ^>(gcnew RenSharpOBBoxCollisionTestClass(obbox, move, res));
	}

	IUnmanagedContainer<IOBBoxCollisionTestClass ^> ^RenSharpOBBoxCollisionTestClass::CreateRenSharpOBBoxCollisionTestClass(
		IOBBoxCollisionTestClass ^that,
		Matrix3D tm)
	{
		return gcnew UnmanagedContainer<IOBBoxCollisionTestClass ^>(gcnew RenSharpOBBoxCollisionTestClass(that, tm));
	}

	IUnmanagedContainer<IOBBoxCollisionTestClass ^> ^RenSharpOBBoxCollisionTestClass::CreateRenSharpOBBoxCollisionTestClass(
		IAABoxCollisionTestClass ^that,
		Matrix3D tm)
	{
		return gcnew UnmanagedContainer<IOBBoxCollisionTestClass ^>(gcnew RenSharpOBBoxCollisionTestClass(that, tm));
	}

	IUnmanagedContainer<IOBBoxCollisionTestClass ^> ^RenSharpOBBoxCollisionTestClass::CreateRenSharpOBBoxCollisionTestClass(
		OBBoxCollisionTestClass ^boxTest)
	{
		return gcnew UnmanagedContainer<IOBBoxCollisionTestClass ^>(gcnew RenSharpOBBoxCollisionTestClass(boxTest));
	}

	IntPtr RenSharpOBBoxCollisionTestClass::RenSharpOBBoxCollisionTestClassPointer::get()
	{
		return IntPtr(InternalRenSharpOBBoxCollisionTestClassPointer);
	}

	Nullable<CastResultStruct> RenSharpOBBoxCollisionTestClass::Result::get()
	{
		return CollisionTestClassRef::Result::get();
	}

	void RenSharpOBBoxCollisionTestClass::Result::set(Nullable<CastResultStruct> value)
	{
		if (value.HasValue)
		{
			::CastResultStruct res;

			CastResultStruct::ManagedToUnmanagedCastResultStruct(value.Value, res);

			Imports::RenSharpOBBoxCollisionTestClassSetResult(InternalRenSharpOBBoxCollisionTestClassPointer, &res);
		}
		else
		{
			InternalOBBoxCollisionTestClassPointer->Result = nullptr;
		}
	}

	bool RenSharpOBBoxCollisionTestClass::InternalDestroyPointer()
	{
		Imports::DestroyRenSharpOBBoxCollisionTestClass(InternalRenSharpOBBoxCollisionTestClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::RenSharpOBBoxCollisionTestClass *RenSharpOBBoxCollisionTestClass::InternalRenSharpOBBoxCollisionTestClassPointer::get()
	{
		return reinterpret_cast<::RenSharpOBBoxCollisionTestClass *>(Pointer.ToPointer());
	}

	OBBoxCollisionTestClass::OBBoxCollisionTestClass(OBBoxClass obbox, Vector3 move, RenSharp::CollisionType collisionType)
		: CollisionTestClass(collisionType), box(obbox), move(move)
	{
		Vector3 maxExtent;

		maxExtent.X = Math::Abs(box.Basis.Row0[0] * box.Extent.X) + Math::Abs(box.Basis.Row0[1] * box.Extent.Y) + Math::Abs(box.Basis.Row0[2] * box.Extent.Z) + 0.01f;
		maxExtent.Y = Math::Abs(box.Basis.Row1[0] * box.Extent.X) + Math::Abs(box.Basis.Row1[1] * box.Extent.Y) + Math::Abs(box.Basis.Row1[2] * box.Extent.Z) + 0.01f;
		maxExtent.Z = Math::Abs(box.Basis.Row2[0] * box.Extent.X) + Math::Abs(box.Basis.Row2[1] * box.Extent.Y) + Math::Abs(box.Basis.Row2[2] * box.Extent.Z) + 0.01f;
		sweepMin = Vector3::operator-(box.Center, maxExtent);
		sweepMax = Vector3::operator+(box.Center, maxExtent);
		Vector3 endmin = Vector3::operator-(Vector3::operator+(box.Center, move), maxExtent);
		Vector3 endmax = Vector3::operator+(Vector3::operator+(box.Center, move), maxExtent);
		if (endmax.X > sweepMax.X) sweepMax.X = endmax.X;
		if (endmax.Y > sweepMax.Y) sweepMax.Y = endmax.Y;
		if (endmax.Z > sweepMax.Z) sweepMax.Z = endmax.Z;
		if (endmin.X < sweepMin.X) sweepMin.X = endmin.X;
		if (endmin.Y < sweepMin.Y) sweepMin.Y = endmin.Y;
		if (endmin.Z < sweepMin.Z) sweepMin.Z = endmin.Z;
	}

	OBBoxCollisionTestClass::OBBoxCollisionTestClass(OBBoxClass obbox, Vector3 move)
		: OBBoxCollisionTestClass(obbox, move, RenSharp::CollisionType::CollisionType0)
	{

	}

	OBBoxCollisionTestClass::OBBoxCollisionTestClass(
		OBBoxClass obbox,
		Vector3 move,
		CastResultStruct res,
		RenSharp::CollisionType collisionType)
		: CollisionTestClass(res, collisionType)
	{
		Vector3 maxExtent;

		maxExtent.X = Math::Abs(box.Basis.Row0[0] * box.Extent.X) + Math::Abs(box.Basis.Row0[1] * box.Extent.Y) + Math::Abs(box.Basis.Row0[2] * box.Extent.Z) + 0.01f;
		maxExtent.Y = Math::Abs(box.Basis.Row1[0] * box.Extent.X) + Math::Abs(box.Basis.Row1[1] * box.Extent.Y) + Math::Abs(box.Basis.Row1[2] * box.Extent.Z) + 0.01f;
		maxExtent.Z = Math::Abs(box.Basis.Row2[0] * box.Extent.X) + Math::Abs(box.Basis.Row2[1] * box.Extent.Y) + Math::Abs(box.Basis.Row2[2] * box.Extent.Z) + 0.01f;
		sweepMin = Vector3::operator-(box.Center, maxExtent);
		sweepMax = Vector3::operator+(box.Center, maxExtent);
		Vector3 endmin = Vector3::operator-(Vector3::operator+(box.Center, move), maxExtent);
		Vector3 endmax = Vector3::operator+(Vector3::operator+(box.Center, move), maxExtent);
		if (endmax.X > sweepMax.X) sweepMax.X = endmax.X;
		if (endmax.Y > sweepMax.Y) sweepMax.Y = endmax.Y;
		if (endmax.Z > sweepMax.Z) sweepMax.Z = endmax.Z;
		if (endmin.X < sweepMin.X) sweepMin.X = endmin.X;
		if (endmin.Y < sweepMin.Y) sweepMin.Y = endmin.Y;
		if (endmin.Z < sweepMin.Z) sweepMin.Z = endmin.Z;
	}

	OBBoxCollisionTestClass::OBBoxCollisionTestClass(OBBoxClass obbox, Vector3 move, CastResultStruct res)
		: OBBoxCollisionTestClass(obbox, move, res, RenSharp::CollisionType::CollisionType0)
	{

	}

	OBBoxCollisionTestClass::OBBoxCollisionTestClass(IOBBoxCollisionTestClass ^that, Matrix3D tm)
		: CollisionTestClass(that)
	{
		if (that == nullptr || that->OBBoxCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("that");
		}

		tm.TransformMinMaxAABox(that->SweepMin, that->SweepMax, sweepMin, sweepMax);
		move = Matrix3D::RotateVector(tm, that->Move);
		box = OBBoxClass::Transform(tm, that->Box);
	}

	OBBoxCollisionTestClass::OBBoxCollisionTestClass(OBBoxCollisionTestClass ^that, Matrix3D tm)
		: CollisionTestClass(that)
	{
		if (that == nullptr)
		{
			throw gcnew ArgumentNullException("that");
		}

		tm.TransformMinMaxAABox(that->SweepMin, that->SweepMax, sweepMin, sweepMax);
		move = Matrix3D::RotateVector(tm, that->Move);
		box = OBBoxClass::Transform(tm, that->Box);
	}

	OBBoxCollisionTestClass::OBBoxCollisionTestClass(IAABoxCollisionTestClass ^that, Matrix3D tm)
		: CollisionTestClass(that)
	{
		if (that == nullptr || that->AABoxCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("that");
		}

		tm.TransformMinMaxAABox(that->SweepMin, that->SweepMax, sweepMin, sweepMax);
		move = Matrix3D::RotateVector(tm, that->Move);
		box.Center = Matrix3D::TransformVector(tm, that->Box.Center);
		box.Extent = that->Box.Extent;
		box.Basis = tm;
	}

	OBBoxCollisionTestClass::OBBoxCollisionTestClass(AABoxCollisionTestClass ^that, Matrix3D tm)
		: CollisionTestClass(that)
	{
		if (that == nullptr)
		{
			throw gcnew ArgumentNullException("that");
		}

		tm.TransformMinMaxAABox(that->SweepMin, that->SweepMax, sweepMin, sweepMax);
		move = Matrix3D::RotateVector(tm, that->Move);
		box.Center = Matrix3D::TransformVector(tm, that->Box.Center);
		box.Extent = that->Box.Extent;
		box.Basis = tm;
	}

	OBBoxCollisionTestClass::OBBoxCollisionTestClass(IOBBoxCollisionTestClass ^boxTest)
		: CollisionTestClass(boxTest)
	{
		if (boxTest == nullptr || boxTest->OBBoxCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("boxTest");
		}

		box = boxTest->Box;
		move = boxTest->Move;
		sweepMin = boxTest->SweepMin;
		sweepMax = boxTest->SweepMax;
	}

	OBBoxCollisionTestClass::OBBoxCollisionTestClass(OBBoxCollisionTestClass ^boxTest)
		: CollisionTestClass(boxTest)
	{
		if (boxTest == nullptr)
		{
			throw gcnew ArgumentNullException("boxTest");
		}

		box = boxTest->Box;
		move = boxTest->Move;
		sweepMin = boxTest->SweepMin;
		sweepMax = boxTest->SweepMax;
	}

	void OBBoxCollisionTestClass::CopyFrom(IOBBoxCollisionTestClass ^boxTest)
	{
		if (boxTest == nullptr || boxTest->OBBoxCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("boxTest");
		}

		CollisionTestClass::CopyFrom(boxTest);

		box = boxTest->Box;
		move = boxTest->Move;
		sweepMin = boxTest->SweepMin;
		sweepMax = boxTest->SweepMax;
	}

	void OBBoxCollisionTestClass::CopyFrom(OBBoxCollisionTestClass ^boxTest)
	{
		if (boxTest == nullptr)
		{
			throw gcnew ArgumentNullException("boxTest");
		}

		CollisionTestClass::CopyFrom(boxTest);

		box = boxTest->Box;
		move = boxTest->Move;
		sweepMin = boxTest->SweepMin;
		sweepMax = boxTest->SweepMax;
	}

	bool OBBoxCollisionTestClass::Cull(Vector3 min, Vector3 max)
	{
		if ((sweepMin.X > max.X) || (sweepMax.X < min.X))
		{
			return true;
		}
		if ((sweepMin.Y > max.Y) || (sweepMax.Y < min.Y))
		{
			return true;
		}
		if ((sweepMin.Z > max.Z) || (sweepMax.Z < min.Z))
		{
			return true;
		}

		return false;
	}

	bool OBBoxCollisionTestClass::Cull(AABoxClass box)
	{
		Vector3 minCorner = Vector3::Subtract(box.Center, box.Extent);
		Vector3 maxCorner = Vector3::Add(box.Center, box.Extent);

		return Cull(minCorner, maxCorner);
	}

	OBBoxClass OBBoxCollisionTestClass::Box::get()
	{
		return box;
	}

	void OBBoxCollisionTestClass::Box::set(OBBoxClass value)
	{
		box = value;
	}

	Vector3 OBBoxCollisionTestClass::Move::get()
	{
		return move;
	}

	void OBBoxCollisionTestClass::Move::set(Vector3 value)
	{
		move = value;
	}

	Vector3 OBBoxCollisionTestClass::SweepMin::get()
	{
		return sweepMin;
	}

	void OBBoxCollisionTestClass::SweepMin::set(Vector3 value)
	{
		sweepMin = value;
	}

	Vector3 OBBoxCollisionTestClass::SweepMax::get()
	{
		return sweepMax;
	}

	void OBBoxCollisionTestClass::SweepMax::set(Vector3 value)
	{
		sweepMax = value;
	}
}