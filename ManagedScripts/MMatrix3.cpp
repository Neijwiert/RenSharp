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
#include "MMatrix3.h"

#include "MVector3.h"
#include "MQuaternion.h"
#include "MMatrix3D.h"
#include "Mmatrix4.h"

namespace RenSharp
{
	Matrix3::Matrix3(bool identity)
	{
		::Matrix3 result(identity);
		UnmanagedToManagedMatrix3(result);
	}

	Matrix3::Matrix3(Vector3 v0, Vector3 v1, Vector3 v2)
	{
		::Vector3 v0Vec;
		::Vector3 v1Vec;
		::Vector3 v2Vec;

		Vector3::ManagedToUnmanagedVector3(v0, v0Vec);
		Vector3::ManagedToUnmanagedVector3(v1, v1Vec);
		Vector3::ManagedToUnmanagedVector3(v2, v2Vec);

		::Matrix3 result(v0Vec, v1Vec, v2Vec);
		UnmanagedToManagedMatrix3(result);
	}

	Matrix3::Matrix3(Matrix3D m)
	{
		::Matrix3D tmp;
		Matrix3D::ManagedToUnmanagedMatrix3D(m, tmp);

		::Matrix3 result(tmp);
		UnmanagedToManagedMatrix3(result);
	}

	Matrix3::Matrix3(Matrix4 m)
	{
		::Matrix4 tmp;
		Matrix4::ManagedToUnmanagedMatrix4(m, tmp);

		::Matrix3 result(tmp);
		UnmanagedToManagedMatrix3(result);
	}

	Matrix3::Matrix3(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33)
	{
		::Matrix3 result(m11, m12, m13, m21, m22, m23, m31, m32, m33);
		UnmanagedToManagedMatrix3(result);
	}

	Matrix3::Matrix3(Vector3 axis, float angle)
	{
		::Vector3 axisVec;
		Vector3::ManagedToUnmanagedVector3(axis, axisVec);

		::Matrix3 result(axisVec, angle);
		UnmanagedToManagedMatrix3(result);
	}

	Matrix3::Matrix3(Vector3 axis, float sAngle, float cAngle)
	{
		::Vector3 axisVec;
		Vector3::ManagedToUnmanagedVector3(axis, axisVec);

		::Matrix3 result(axisVec, sAngle, cAngle);
		UnmanagedToManagedMatrix3(result);
	}

	Matrix3::Matrix3(Quaternion q)
	{
		::Quaternion qQuat;
		Quaternion::ManagedToUnmanagedQuaternion(q, qQuat);

		::Matrix3 result(qQuat);
		UnmanagedToManagedMatrix3(result);
	}

	Matrix3::Matrix3(IntPtr pointer)
	{
		if (pointer == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		::Matrix3 *result = reinterpret_cast<::Matrix3 *>(pointer.ToPointer());
		
		auto &row0 = result->operator[](0);
		auto &row1 = result->operator[](1);
		auto &row2 = result->operator[](2);

		Vector3::UnmanagedToManagedVector3(row0, Row0);
		Vector3::UnmanagedToManagedVector3(row1, Row1);
		Vector3::UnmanagedToManagedVector3(row2, Row2);
	}

	void Matrix3::Set(Matrix3D m)
	{
		::Matrix3D tmp;
		Matrix3D::ManagedToUnmanagedMatrix3D(m, tmp);

		::Matrix3 result;
		ManagedToUnmanagedMatrix3(result);

		result.Set(tmp);

		UnmanagedToManagedMatrix3(result);
	}

	void Matrix3::Set(Matrix4 m)
	{
		::Matrix4 tmp;
		Matrix4::ManagedToUnmanagedMatrix4(m, tmp);

		::Matrix3 result;
		ManagedToUnmanagedMatrix3(result);

		result.Set(tmp);

		UnmanagedToManagedMatrix3(result);
	}

	void Matrix3::Set(Vector3 v0, Vector3 v1, Vector3 v2)
	{
		::Vector3 v0Vec;
		::Vector3 v1Vec;
		::Vector3 v2Vec;

		Vector3::ManagedToUnmanagedVector3(v0, v0Vec);
		Vector3::ManagedToUnmanagedVector3(v1, v1Vec);
		Vector3::ManagedToUnmanagedVector3(v2, v2Vec);

		::Matrix3 result;
		ManagedToUnmanagedMatrix3(result);

		result.Set(v0Vec, v1Vec, v2Vec);

		UnmanagedToManagedMatrix3(result);
	}

	void Matrix3::Set(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33)
	{
		::Matrix3 result;
		ManagedToUnmanagedMatrix3(result);

		result.Set(m11, m12, m13, m21, m22, m23, m31, m32, m33);

		UnmanagedToManagedMatrix3(result);
	}

	void Matrix3::Set(Vector3 axis, float angle)
	{
		::Vector3 axisVec;
		Vector3::ManagedToUnmanagedVector3(axis, axisVec);

		::Matrix3 result;
		ManagedToUnmanagedMatrix3(result);

		result.Set(axisVec, angle);

		UnmanagedToManagedMatrix3(result);
	}

	void Matrix3::Set(Vector3 axis, float s, float c)
	{
		::Vector3 axisVec;
		Vector3::ManagedToUnmanagedVector3(axis, axisVec);

		::Matrix3 result;
		ManagedToUnmanagedMatrix3(result);

		result.Set(axisVec, s, c);

		UnmanagedToManagedMatrix3(result);
	}

	void Matrix3::Set(Quaternion q)
	{
		::Quaternion qQuat;
		Quaternion::ManagedToUnmanagedQuaternion(q, qQuat);

		::Matrix3 result;
		ManagedToUnmanagedMatrix3(result);

		result.Set(qQuat);

		UnmanagedToManagedMatrix3(result);
	}

	Matrix3 Matrix3::Transpose()
	{
		::Matrix3 thisMat;
		ManagedToUnmanagedMatrix3(thisMat);

		::Matrix3 tmp = thisMat.Transpose();

		Matrix3 result;
		UnmanagedToManagedMatrix3(tmp, result);

		return result;
	}

	float Matrix3::Determinant()
	{
		::Matrix3 thisMat;
		ManagedToUnmanagedMatrix3(thisMat);

		return thisMat.Determinant();
	}

	void Matrix3::MakeIdentity()
	{
		::Matrix3 thisMat;
		ManagedToUnmanagedMatrix3(thisMat);

		thisMat.Make_Identity();

		UnmanagedToManagedMatrix3(thisMat);
	}

	void Matrix3::RotateX(float theta)
	{
		::Matrix3 thisMat;
		ManagedToUnmanagedMatrix3(thisMat);

		thisMat.Rotate_X(theta);

		UnmanagedToManagedMatrix3(thisMat);
	}

	void Matrix3::RotateX(float s, float c)
	{
		::Matrix3 thisMat;
		ManagedToUnmanagedMatrix3(thisMat);

		thisMat.Rotate_X(s, c);

		UnmanagedToManagedMatrix3(thisMat);
	}

	void Matrix3::RotateY(float theta)
	{
		::Matrix3 thisMat;
		ManagedToUnmanagedMatrix3(thisMat);

		thisMat.Rotate_Y(theta);

		UnmanagedToManagedMatrix3(thisMat);
	}

	void Matrix3::RotateY(float s, float c)
	{
		::Matrix3 thisMat;
		ManagedToUnmanagedMatrix3(thisMat);

		thisMat.Rotate_Y(s, c);

		UnmanagedToManagedMatrix3(thisMat);
	}

	void Matrix3::RotateZ(float theta)
	{
		::Matrix3 thisMat;
		ManagedToUnmanagedMatrix3(thisMat);

		thisMat.Rotate_Z(theta);

		UnmanagedToManagedMatrix3(thisMat);
	}

	void Matrix3::RotateZ(float s, float c)
	{
		::Matrix3 thisMat;
		ManagedToUnmanagedMatrix3(thisMat);

		thisMat.Rotate_Z(s, c);

		UnmanagedToManagedMatrix3(thisMat);
	}

	Vector3 Matrix3::RotateAABoxExtent(Vector3 extent)
	{
		::Vector3 extentVec;
		Vector3::ManagedToUnmanagedVector3(extent, extentVec);

		::Matrix3 thisMat;
		ManagedToUnmanagedMatrix3(thisMat);

		::Vector3 tmp;
		thisMat.Rotate_AABox_Extent(extentVec, &tmp);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	Matrix3 Matrix3::Inverse()
	{
		::Matrix3 thisMat;
		ManagedToUnmanagedMatrix3(thisMat);

		::Matrix3 tmp = thisMat.Inverse();

		Matrix3 result;
		UnmanagedToManagedMatrix3(tmp, result);

		return result;
	}

	Matrix3::operator Matrix3(Matrix3D m)
	{
		::Matrix3D mMatrix;
		Matrix3D::ManagedToUnmanagedMatrix3D(m, mMatrix);

		::Matrix3 tmp;
		tmp = mMatrix;

		Matrix3 result;
		UnmanagedToManagedMatrix3(tmp, result);

		return result;
	}

	Matrix3::operator Matrix3(Matrix4 m)
	{
		::Matrix4 mMatrix;
		Matrix4::ManagedToUnmanagedMatrix4(m, mMatrix);

		::Matrix3 tmp;
		tmp = mMatrix;

		Matrix3 result;
		UnmanagedToManagedMatrix3(tmp, result);

		return result;
	}

	Matrix3 Matrix3::operator+(Matrix3 a, Matrix3 b)
	{
		::Matrix3 aMat;
		::Matrix3 bMat;

		ManagedToUnmanagedMatrix3(a, aMat);
		ManagedToUnmanagedMatrix3(b, bMat);

		::Matrix3 tmp = aMat + bMat;

		Matrix3 result;
		UnmanagedToManagedMatrix3(tmp, result);
		
		return result;
	}

	Matrix3 Matrix3::operator-(Matrix3 a)
	{
		::Matrix3 aMat;
		ManagedToUnmanagedMatrix3(a, aMat);

		::Matrix3 tmp = -aMat;

		Matrix3 result;
		UnmanagedToManagedMatrix3(tmp, result);

		return result;
	}

	Matrix3 Matrix3::operator-(Matrix3 a, Matrix3 b)
	{
		::Matrix3 aMat;
		::Matrix3 bMat;

		ManagedToUnmanagedMatrix3(a, aMat);
		ManagedToUnmanagedMatrix3(b, bMat);

		::Matrix3 tmp = aMat - bMat;

		Matrix3 result;
		UnmanagedToManagedMatrix3(tmp, result);

		return result;
	}

	Matrix3 Matrix3::operator*(Matrix3 a, Matrix3 b)
	{
		::Matrix3 aMat;
		::Matrix3 bMat;

		ManagedToUnmanagedMatrix3(a, aMat);
		ManagedToUnmanagedMatrix3(b, bMat);

		::Matrix3 tmp = aMat * bMat;

		Matrix3 result;
		UnmanagedToManagedMatrix3(tmp, result);

		return result;
	}

	Matrix3 Matrix3::operator*(Matrix3 a, float d)
	{
		::Matrix3 aMat;
		ManagedToUnmanagedMatrix3(a, aMat);

		::Matrix3 tmp = aMat * d;

		Matrix3 result;
		UnmanagedToManagedMatrix3(tmp, result);

		return result;
	}

	Matrix3 Matrix3::operator*(float d, Matrix3 a)
	{
		::Matrix3 aMat;
		ManagedToUnmanagedMatrix3(a, aMat);

		::Matrix3 tmp = d * aMat;

		Matrix3 result;
		UnmanagedToManagedMatrix3(tmp, result);

		return result;
	}

	Vector3 Matrix3::operator*(Matrix3 a, Vector3 v)
	{
		::Matrix3 aMat;
		::Vector3 vVec;

		ManagedToUnmanagedMatrix3(a, aMat);
		Vector3::ManagedToUnmanagedVector3(v, vVec);

		::Vector3 tmp = aMat * vVec;

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	Matrix3 Matrix3::operator/(Matrix3 a, float d)
	{
		::Matrix3 aMat;
		ManagedToUnmanagedMatrix3(a, aMat);

		::Matrix3 tmp = aMat / d;

		Matrix3 result;
		UnmanagedToManagedMatrix3(tmp, result);

		return result;
	}

	Matrix3 Matrix3::Add(Matrix3 a, Matrix3 b)
	{
		::Matrix3 aMat;
		::Matrix3 bMat;

		ManagedToUnmanagedMatrix3(a, aMat);
		ManagedToUnmanagedMatrix3(b, bMat);

		::Matrix3 tmp;
		::Matrix3::Add(aMat, bMat, &tmp);

		Matrix3 result;
		UnmanagedToManagedMatrix3(tmp, result);

		return result;
	}

	Matrix3 Matrix3::Subtract(Matrix3 a, Matrix3 b)
	{
		::Matrix3 aMat;
		::Matrix3 bMat;

		ManagedToUnmanagedMatrix3(a, aMat);
		ManagedToUnmanagedMatrix3(b, bMat);

		::Matrix3 tmp;
		::Matrix3::Subtract(aMat, bMat, &tmp);

		Matrix3 result;
		UnmanagedToManagedMatrix3(tmp, result);

		return result;
	}

	Matrix3 Matrix3::Multiply(Matrix3 a, Matrix3 b)
	{
		::Matrix3 aMat;
		::Matrix3 bMat;

		ManagedToUnmanagedMatrix3(a, aMat);
		ManagedToUnmanagedMatrix3(b, bMat);

		::Matrix3 tmp;
		::Matrix3::Multiply(aMat, bMat, &tmp);

		Matrix3 result;
		UnmanagedToManagedMatrix3(tmp, result);

		return result;
	}

	Matrix3 Matrix3::Multiply(Matrix3D a, Matrix3 b)
	{
		::Matrix3D aMat;
		::Matrix3 bMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(a, aMat);
		ManagedToUnmanagedMatrix3(b, bMat);

		::Matrix3 tmp;
		::Matrix3::Multiply(aMat, bMat, &tmp);

		Matrix3 result;
		UnmanagedToManagedMatrix3(tmp, result);

		return result;
	}

	Matrix3 Matrix3::Multiply(Matrix3 a, Matrix3D b)
	{
		::Matrix3 aMat;
		::Matrix3D bMat;

		ManagedToUnmanagedMatrix3(a, aMat);
		Matrix3D::ManagedToUnmanagedMatrix3D(b, bMat);

		::Matrix3 tmp;
		::Matrix3::Multiply(aMat, bMat, &tmp);

		Matrix3 result;
		UnmanagedToManagedMatrix3(tmp, result);

		return result;
	}

	Vector3 Matrix3::RotateVector(Matrix3 a, Vector3 in)
	{
		::Matrix3 aMat;
		::Vector3 inVec;

		ManagedToUnmanagedMatrix3(a, aMat);
		Vector3::ManagedToUnmanagedVector3(in, inVec);

		::Vector3 tmp;
		::Matrix3::Rotate_Vector(aMat, inVec, &tmp);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	Vector3 Matrix3::TransposeRotateVector(Matrix3 a, Vector3 in)
	{
		::Matrix3 aMat;
		::Vector3 inVec;

		ManagedToUnmanagedMatrix3(a, aMat);
		Vector3::ManagedToUnmanagedVector3(in, inVec);

		::Vector3 tmp;
		::Matrix3::Transpose_Rotate_Vector(aMat, inVec, &tmp);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	Matrix3 Matrix3::CreateXRotationMatrix3(float s, float c)
	{
		::Matrix3 tmp = ::Create_X_Rotation_Matrix3(s, c);

		Matrix3 result;
		UnmanagedToManagedMatrix3(tmp, result);

		return result;
	}

	Matrix3 Matrix3::CreateXRotationMatrix3(float rad)
	{
		::Matrix3 tmp = ::Create_X_Rotation_Matrix3(rad);

		Matrix3 result;
		UnmanagedToManagedMatrix3(tmp, result);

		return result;
	}

	Matrix3 Matrix3::CreateYRotationMatrix3(float s, float c)
	{
		::Matrix3 tmp = ::Create_Y_Rotation_Matrix3(s, c);

		Matrix3 result;
		UnmanagedToManagedMatrix3(tmp, result);

		return result;
	}

	Matrix3 Matrix3::CreateYRotationMatrix3(float rad)
	{
		::Matrix3 tmp = ::Create_Y_Rotation_Matrix3(rad);

		Matrix3 result;
		UnmanagedToManagedMatrix3(tmp, result);

		return result;
	}

	Matrix3 Matrix3::CreateZRotationMatrix3(float s, float c)
	{
		::Matrix3 tmp = ::Create_Z_Rotation_Matrix3(s, c);

		Matrix3 result;
		UnmanagedToManagedMatrix3(tmp, result);

		return result;
	}

	Matrix3 Matrix3::CreateZRotationMatrix3(float rad)
	{
		::Matrix3 tmp = ::Create_Z_Rotation_Matrix3(rad);

		Matrix3 result;
		UnmanagedToManagedMatrix3(tmp, result);

		return result;
	}

	Vector3 Matrix3::default::get(int index)
	{
		if (index < 0 || index >= 3)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		::Matrix3 thisMat;
		ManagedToUnmanagedMatrix3(thisMat);

		::Vector3 tmp = thisMat[index];

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	void Matrix3::default::set(int index, Vector3 value)
	{
		if (index < 0 || index >= 3)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		::Vector3 valueVec;
		Vector3::ManagedToUnmanagedVector3(value, valueVec);

		::Matrix3 thisMat;
		ManagedToUnmanagedMatrix3(thisMat);

		thisMat[index] = valueVec;

		UnmanagedToManagedMatrix3(thisMat);
	}

	float Matrix3::XRotation::get()
	{
		::Matrix3 thisMat;
		ManagedToUnmanagedMatrix3(thisMat);

		return thisMat.Get_X_Rotation();
	}

	float Matrix3::YRotation::get()
	{
		::Matrix3 thisMat;
		ManagedToUnmanagedMatrix3(thisMat);

		return thisMat.Get_Y_Rotation();
	}

	float Matrix3::ZRotation::get()
	{
		::Matrix3 thisMat;
		ManagedToUnmanagedMatrix3(thisMat);

		return thisMat.Get_Z_Rotation();
	}

	Vector3 Matrix3::XVector::get()
	{
		::Matrix3 thisMat;
		ManagedToUnmanagedMatrix3(thisMat);

		::Vector3 tmp = thisMat.Get_X_Vector();

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	Vector3 Matrix3::YVector::get()
	{
		::Matrix3 thisMat;
		ManagedToUnmanagedMatrix3(thisMat);

		::Vector3 tmp = thisMat.Get_Y_Vector();

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	Vector3 Matrix3::ZVector::get()
	{
		::Matrix3 thisMat;
		ManagedToUnmanagedMatrix3(thisMat);

		::Vector3 tmp = thisMat.Get_Z_Vector();

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	Matrix3 Matrix3::Identity::get()
	{
		Matrix3 result;
		UnmanagedToManagedMatrix3(::Matrix3::Identity, result);

		return result;
	}
}