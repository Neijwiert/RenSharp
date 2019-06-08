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
#include "Mmatrix4.h"

#include "MVector3.h"
#include "MMatrix3D.h"
#include "Mplane.h"

namespace RenSharp
{
	Matrix4::Matrix4(bool identity)
	{
		::Matrix4 thisMat(identity);
		UnmanagedToManagedMatrix4(thisMat);
	}

	Matrix4::Matrix4(Matrix3D m)
	{
		::Matrix3D tmp;
		Matrix3D::ManagedToUnmanagedMatrix3D(m, tmp);

		::Matrix4 thisMat(tmp);
		UnmanagedToManagedMatrix4(thisMat);
	}

	Matrix4::Matrix4(Vector4 v0, Vector4 v1, Vector4 v2, Vector4 v3)
	{
		::Vector4 v0Vec;
		::Vector4 v1Vec;
		::Vector4 v2Vec;
		::Vector4 v3Vec;

		Vector4::ManagedToUnmanagedVector4(v0, v0Vec);
		Vector4::ManagedToUnmanagedVector4(v1, v1Vec);
		Vector4::ManagedToUnmanagedVector4(v2, v2Vec);
		Vector4::ManagedToUnmanagedVector4(v3, v3Vec);

		::Matrix4 thisMat(v0Vec, v1Vec, v2Vec, v3Vec);
		UnmanagedToManagedMatrix4(thisMat);
	}

	Matrix4::Matrix4(IntPtr pointer)
	{
		if (pointer == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		::Matrix4 *result = reinterpret_cast<::Matrix4 *>(pointer.ToPointer());

		auto &row0 = result->operator[](0);
		auto &row1 = result->operator[](1);
		auto &row2 = result->operator[](2);
		auto &row3 = result->operator[](3);

		Vector4::UnmanagedToManagedVector4(row0, Row0);
		Vector4::UnmanagedToManagedVector4(row1, Row1);
		Vector4::UnmanagedToManagedVector4(row2, Row2);
		Vector4::UnmanagedToManagedVector4(row3, Row3);
	}

	bool Matrix4::Equals(Object ^other)
	{
		Matrix4 ^otherMat = dynamic_cast<Matrix4 ^>(other);
		if (otherMat == nullptr)
		{
			return false;
		}
		
		bool result = true;

		result &= Row0.Equals(otherMat->Row0);
		result &= Row1.Equals(otherMat->Row1);
		result &= Row2.Equals(otherMat->Row2);
		result &= Row3.Equals(otherMat->Row3);

		return result;
	}

	int Matrix4::GetHashCode()
	{
		int hash = 17;
		hash = hash * 23 + Row0.GetHashCode();
		hash = hash * 23 + Row1.GetHashCode();
		hash = hash * 23 + Row2.GetHashCode();
		hash = hash * 23 + Row3.GetHashCode();

		return hash;
	}

	void Matrix4::MakeIdentity()
	{
		::Matrix4 thisMat;
		ManagedToUnmanagedMatrix4(thisMat);

		thisMat.Make_Identity();

		UnmanagedToManagedMatrix4(thisMat);
	}

	void Matrix4::Init(Matrix3D m)
	{
		::Matrix3D mMat;
		Matrix3D::ManagedToUnmanagedMatrix3D(m, mMat);

		::Matrix4 thisMat;
		ManagedToUnmanagedMatrix4(thisMat);

		thisMat.Init(mMat);

		UnmanagedToManagedMatrix4(thisMat);
	}

	void Matrix4::Init(Vector4 v0, Vector4 v1, Vector4 v2, Vector4 v3)
	{
		::Vector4 v0Vec;
		::Vector4 v1Vec;
		::Vector4 v2Vec;
		::Vector4 v3Vec;

		Vector4::ManagedToUnmanagedVector4(v0, v0Vec);
		Vector4::ManagedToUnmanagedVector4(v1, v1Vec);
		Vector4::ManagedToUnmanagedVector4(v2, v2Vec);
		Vector4::ManagedToUnmanagedVector4(v3, v3Vec);

		::Matrix4 thisMat;
		ManagedToUnmanagedMatrix4(thisMat);

		thisMat.Init(v0Vec, v1Vec, v2Vec, v3Vec);

		UnmanagedToManagedMatrix4(thisMat);
	}

	void Matrix4::InitOrthoOGL(float left, float right, float bottom, float top, float zNear, float zFar)
	{
		::Matrix4 thisMat;
		ManagedToUnmanagedMatrix4(thisMat);

		thisMat.Init_Ortho_OGL(left, right, bottom, top, zNear, zFar);

		UnmanagedToManagedMatrix4(thisMat);
	}

	void Matrix4::InitPerspectiveOGL(float hFOV, float vFOV, float zNear, float zFar)
	{
		::Matrix4 thisMat;
		ManagedToUnmanagedMatrix4(thisMat);

		thisMat.Init_Perspective_OGL(hFOV, vFOV, zNear, zFar);

		UnmanagedToManagedMatrix4(thisMat);
	}

	void Matrix4::InitPerspectiveOGL(float left, float right, float bottom, float top, float zNear, float zFar)
	{
		::Matrix4 thisMat;
		ManagedToUnmanagedMatrix4(thisMat);

		thisMat.Init_Perspective_OGL(left, right, bottom, top, zNear, zFar);

		UnmanagedToManagedMatrix4(thisMat);
	}

	void Matrix4::InitOrtho(float left, float right, float bottom, float top, float zNear, float zFar)
	{
		::Matrix4 thisMat;
		ManagedToUnmanagedMatrix4(thisMat);

		thisMat.Init_Ortho(left, right, bottom, top, zNear, zFar);

		UnmanagedToManagedMatrix4(thisMat);
	}

	void Matrix4::InitPerspective(float left, float right, float bottom, float top, float zNear, float zFar)
	{
		::Matrix4 thisMat;
		ManagedToUnmanagedMatrix4(thisMat);

		thisMat.Init_Perspective(left, right, bottom, top, zNear, zFar);

		UnmanagedToManagedMatrix4(thisMat);
	}

	Matrix4 Matrix4::Transpose()
	{
		::Matrix4 thisMat;
		ManagedToUnmanagedMatrix4(thisMat);

		::Matrix4 tmp = thisMat.Transpose();

		Matrix4 result;
		UnmanagedToManagedMatrix4(tmp, result);

		return result;
	}

	Matrix4 Matrix4::Inverse()
	{
		::Matrix4 thisMat;
		ManagedToUnmanagedMatrix4(thisMat);

		::Matrix4 tmp = thisMat.Inverse();

		Matrix4 result;
		UnmanagedToManagedMatrix4(tmp, result);

		return result;
	}

	Matrix4 Matrix4::operator+(Matrix4 a, Matrix4 b)
	{
		::Matrix4 aMat;
		::Matrix4 bMat;

		ManagedToUnmanagedMatrix4(a, aMat);
		ManagedToUnmanagedMatrix4(b, bMat);

		::Matrix4 tmp = aMat + bMat;

		Matrix4 result;
		UnmanagedToManagedMatrix4(tmp, result);

		return result;
	}

	Matrix4 Matrix4::operator-(Matrix4 a, Matrix4 b)
	{
		::Matrix4 aMat;
		::Matrix4 bMat;

		ManagedToUnmanagedMatrix4(a, aMat);
		ManagedToUnmanagedMatrix4(b, bMat);

		::Matrix4 tmp = aMat - bMat;

		Matrix4 result;
		UnmanagedToManagedMatrix4(tmp, result);

		return result;
	}

	Matrix4 Matrix4::operator-(Matrix4 a)
	{
		::Matrix4 aMat;

		ManagedToUnmanagedMatrix4(a, aMat);

		::Matrix4 tmp = -aMat;

		Matrix4 result;
		UnmanagedToManagedMatrix4(tmp, result);

		return result;
	}

	Matrix4 Matrix4::operator*(Matrix4 a, float d)
	{
		::Matrix4 aMat;

		ManagedToUnmanagedMatrix4(a, aMat);

		::Matrix4 tmp = aMat * d;

		Matrix4 result;
		UnmanagedToManagedMatrix4(tmp, result);

		return result;
	}

	Matrix4 Matrix4::operator*(float d, Matrix4 a)
	{
		::Matrix4 aMat;

		ManagedToUnmanagedMatrix4(a, aMat);

		::Matrix4 tmp = d * aMat;

		Matrix4 result;
		UnmanagedToManagedMatrix4(tmp, result);

		return result;
	}

	Matrix4 Matrix4::operator*(Matrix4 a, Matrix4 b)
	{
		::Matrix4 aMat;
		::Matrix4 bMat;

		ManagedToUnmanagedMatrix4(a, aMat);
		ManagedToUnmanagedMatrix4(b, bMat);

		::Matrix4 tmp = aMat * bMat;

		Matrix4 result;
		UnmanagedToManagedMatrix4(tmp, result);

		return result;
	}

	Matrix4 Matrix4::operator*(Matrix3D a, Matrix4 b)
	{
		::Matrix3D aMat;
		::Matrix4 bMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(a, aMat);
		ManagedToUnmanagedMatrix4(b, bMat);

		::Matrix4 tmp = aMat * bMat;

		Matrix4 result;
		UnmanagedToManagedMatrix4(tmp, result);

		return result;
	}

	Matrix4 Matrix4::operator*(Matrix4 a, Matrix3D b)
	{
		::Matrix4 aMat;
		::Matrix3D bMat;

		ManagedToUnmanagedMatrix4(a, aMat);
		Matrix3D::ManagedToUnmanagedMatrix3D(b, bMat);

		::Matrix4 tmp = aMat * bMat;

		Matrix4 result;
		UnmanagedToManagedMatrix4(tmp, result);

		return result;
	}

	Vector4 Matrix4::operator*(Matrix4 a, Vector4 v)
	{
		::Matrix4 aMat;
		::Vector4 vVec;

		ManagedToUnmanagedMatrix4(a, aMat);
		Vector4::ManagedToUnmanagedVector4(v, vVec);

		::Vector4 tmp = aMat * vVec;

		Vector4 result;
		Vector4::UnmanagedToManagedVector4(tmp, result);

		return result;
	}

	Vector4 Matrix4::operator*(Matrix4 a, Vector3 v)
	{
		::Matrix4 aMat;
		::Vector3 vVec;

		ManagedToUnmanagedMatrix4(a, aMat);
		Vector3::ManagedToUnmanagedVector3(v, vVec);

		::Vector4 tmp = aMat * vVec;

		Vector4 result;
		Vector4::UnmanagedToManagedVector4(tmp, result);

		return result;
	}

	Matrix4 Matrix4::operator/(Matrix4 a, float d)
	{
		::Matrix4 aMat;

		ManagedToUnmanagedMatrix4(a, aMat);

		::Matrix4 tmp = aMat / d;

		Matrix4 result;
		UnmanagedToManagedMatrix4(tmp, result);

		return result;
	}


	Matrix4 Matrix4::Subtract(Matrix4 a, Matrix4 b)
	{
		::Matrix4 aMat;
		::Matrix4 bMat;

		ManagedToUnmanagedMatrix4(a, aMat);
		ManagedToUnmanagedMatrix4(b, bMat);

		::Matrix4 tmp = ::Subtract(aMat, bMat);

		Matrix4 result;
		UnmanagedToManagedMatrix4(tmp, result);

		return result;
	}

	Matrix4 Matrix4::Multiply(Matrix4 a, Matrix4 b)
	{
		::Matrix4 aMat;
		::Matrix4 bMat;

		ManagedToUnmanagedMatrix4(a, aMat);
		ManagedToUnmanagedMatrix4(b, bMat);

		::Matrix4 tmp = ::Multiply(aMat, bMat);

		Matrix4 result;
		UnmanagedToManagedMatrix4(tmp, result);

		return result;
	}

	Matrix4 Matrix4::Multiply(Matrix3D a, Matrix4 b)
	{
		::Matrix3D aMat;
		::Matrix4 bMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(a, aMat);
		ManagedToUnmanagedMatrix4(b, bMat);

		::Matrix4 tmp;
		::Matrix4::Multiply(aMat, bMat, &tmp);

		Matrix4 result;
		UnmanagedToManagedMatrix4(tmp, result);

		return result;
	}

	Matrix4 Matrix4::Multiply(Matrix4 a, Matrix3D b)
	{
		::Matrix4 aMat;
		::Matrix3D bMat;

		ManagedToUnmanagedMatrix4(a, aMat);
		Matrix3D::ManagedToUnmanagedMatrix3D(b, bMat);

		::Matrix4 tmp;
		::Matrix4::Multiply(aMat, bMat, &tmp);

		Matrix4 result;
		UnmanagedToManagedMatrix4(tmp, result);

		return result;
	}

	Vector3 Matrix4::TransformVector3(Matrix4 a, Vector3 in)
	{
		::Matrix4 aMat;
		::Vector3 inVec;

		ManagedToUnmanagedMatrix4(a, aMat);
		Vector3::ManagedToUnmanagedVector3(in, inVec);

		::Vector3 tmp;
		::Matrix4::Transform_Vector(aMat, inVec, &tmp);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	Vector4 Matrix4::TransformVector4(Matrix4 a, Vector3 in)
	{
		::Matrix4 aMat;
		::Vector3 inVec;

		ManagedToUnmanagedMatrix4(a, aMat);
		Vector3::ManagedToUnmanagedVector3(in, inVec);

		::Vector4 tmp;
		::Matrix4::Transform_Vector(aMat, inVec, &tmp);

		Vector4 result;
		Vector4::UnmanagedToManagedVector4(tmp, result);

		return result;
	}

	Vector4 Matrix4::TransformVector4(Matrix4 a, Vector4 in)
	{
		::Matrix4 aMat;
		::Vector4 inVec;

		ManagedToUnmanagedMatrix4(a, aMat);
		Vector4::ManagedToUnmanagedVector4(in, inVec);

		::Vector4 tmp;
		::Matrix4::Transform_Vector(aMat, inVec, &tmp);

		Vector4 result;
		Vector4::UnmanagedToManagedVector4(tmp, result);

		return result;
	}

	Matrix4 Matrix4::ReflectPlane(PlaneClass plane)
	{
		::PlaneClass pPlane;

		PlaneClass::ManagedToUnmanagedPlaneClass(plane, pPlane);

		::Matrix4 tmp = ::Matrix4::ReflectPlane(pPlane);

		Matrix4 result;
		UnmanagedToManagedMatrix4(tmp, result);

		return result;
	}

	Vector4 Matrix4::default::get(int index)
	{
		if (index < 0 || index >= 4)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		::Matrix4 thisMat;
		ManagedToUnmanagedMatrix4(thisMat);

		::Vector4 tmp = thisMat[index];

		Vector4 result;
		Vector4::UnmanagedToManagedVector4(tmp, result);

		return result;
	}

	void Matrix4::default::set(int index, Vector4 value)
	{
		if (index < 0 || index >= 4)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		::Vector4 valueVec;

		Vector4::ManagedToUnmanagedVector4(value, valueVec);

		::Matrix4 thisMat;
		ManagedToUnmanagedMatrix4(thisMat);

		thisMat[index] = valueVec;

		UnmanagedToManagedMatrix4(thisMat);
	}

	float Matrix4::Determinant::get()
	{
		::Matrix4 thisMat;
		ManagedToUnmanagedMatrix4(thisMat);

		return thisMat.Determinant();
	}

	Matrix4 Matrix4::Identity::get()
	{
		Matrix4 result;
		UnmanagedToManagedMatrix4(::Matrix4::IDENTITY, result);

		return result;
	}
}