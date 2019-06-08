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
#include "MMatrix3D.h"

#include "MVector3.h"
#include "MMatrix3.h"
#include "MQuaternion.h"
#include "Mplane.h"

namespace RenSharp
{
	Matrix3D::Matrix3D(bool init)
	{
		::Matrix3D tmp(init);
		UnmanagedToManagedMatrix3D(tmp);
	}

	Matrix3D::Matrix3D(array<float> ^m)
	{
		if (m == nullptr)
		{
			throw gcnew ArgumentNullException("m");
		}
		else if (m->Length != 12)
		{
			throw gcnew ArgumentOutOfRangeException("m");
		}

		float mArray[12]
		{
			m[0],
			m[1],
			m[2],
			m[3],
			m[4],
			m[5],
			m[6],
			m[7],
			m[8],
			m[9],
			m[10],
			m[11]
		};

		::Matrix3D tmp(mArray);
		UnmanagedToManagedMatrix3D(tmp);
	}

	Matrix3D::Matrix3D(Vector3 x, Vector3 y, Vector3 z, Vector3 pos)
	{
		::Vector3 xVec;
		::Vector3 yVec;
		::Vector3 zVec;
		::Vector3 posVec;
		
		Vector3::ManagedToUnmanagedVector3(x, xVec);
		Vector3::ManagedToUnmanagedVector3(y, yVec);
		Vector3::ManagedToUnmanagedVector3(z, zVec);
		Vector3::ManagedToUnmanagedVector3(pos, posVec);

		::Matrix3D tmp(xVec, yVec, zVec, posVec);
		UnmanagedToManagedMatrix3D(tmp);
	}

	Matrix3D::Matrix3D(Vector3 axis, float angle)
	{
		::Vector3 axisVec;

		Vector3::ManagedToUnmanagedVector3(axis, axisVec);

		::Matrix3D tmp(axisVec);
		UnmanagedToManagedMatrix3D(tmp);
	}

	Matrix3D::Matrix3D(Vector3 axis, float sine, float cosine)
	{
		::Vector3 axisVec;

		Vector3::ManagedToUnmanagedVector3(axis, axisVec);

		::Matrix3D tmp(axisVec, sine, cosine);
		UnmanagedToManagedMatrix3D(tmp);
	}

	Matrix3D::Matrix3D(Matrix3 rotation, Vector3 position)
	{
		::Matrix3 rotationMat;
		::Vector3 posVec;

		Matrix3::ManagedToUnmanagedMatrix3(rotation, rotationMat);
		Vector3::ManagedToUnmanagedVector3(position, posVec);

		::Matrix3D tmp(rotationMat, posVec);
		UnmanagedToManagedMatrix3D(tmp);
	}

	Matrix3D::Matrix3D(Quaternion rotation, Vector3 position)
	{
		::Quaternion rotQuat;
		::Vector3 posVec;

		Quaternion::ManagedToUnmanagedQuaternion(rotation, rotQuat);
		Vector3::ManagedToUnmanagedVector3(position, posVec);

		::Matrix3D tmp(rotQuat, posVec);
		UnmanagedToManagedMatrix3D(tmp);
	}

	Matrix3D::Matrix3D(Vector3 position)
	{
		::Vector3 posVec;

		Vector3::ManagedToUnmanagedVector3(position, posVec);

		::Matrix3D tmp(posVec);
		UnmanagedToManagedMatrix3D(tmp);
	}

	Matrix3D::Matrix3D(
		float _11, float _12, float _13, float _14,
		float _21, float _22, float _23, float _24,
		float _31, float _32, float _33, float _34)
	{
		::Matrix3D tmp(
				_11, _12, _13, _14,
				_21, _22, _23, _24,
				_31, _32, _33, _34);
		UnmanagedToManagedMatrix3D(tmp);
	}

	Matrix3D::Matrix3D(IntPtr pointer)
	{
		if (pointer == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		::Matrix3D *result = reinterpret_cast<::Matrix3D *>(pointer.ToPointer());

		auto &row0 = result->operator[](0);
		auto &row1 = result->operator[](1);
		auto &row2 = result->operator[](2);

		Vector4::UnmanagedToManagedVector4(row0, Row0);
		Vector4::UnmanagedToManagedVector4(row1, Row1);
		Vector4::UnmanagedToManagedVector4(row2, Row2);
	}

	bool Matrix3D::Equals(Object ^other)
	{
		Matrix3D ^otherMat = dynamic_cast<Matrix3D ^>(other);
		if (otherMat == nullptr)
		{
			return false;
		}

		::Matrix3D thisMat;
		::Matrix3D tmp;

		auto &row0 = tmp[0];
		auto &row1 = tmp[1];
		auto &row2 = tmp[2];

		ManagedToUnmanagedMatrix3D(thisMat);
		Vector4::ManagedToUnmanagedVector4(otherMat->Row0, row0);
		Vector4::ManagedToUnmanagedVector4(otherMat->Row1, row1);
		Vector4::ManagedToUnmanagedVector4(otherMat->Row2, row2);

		return (thisMat == tmp);
	}

	int Matrix3D::GetHashCode()
	{
		int hash = 17;
		hash = hash * 23 + Row0.GetHashCode();
		hash = hash * 23 + Row1.GetHashCode();
		hash = hash * 23 + Row2.GetHashCode();

		return hash;
	}

	Matrix3D Matrix3D::OrthogonalInverse()
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		::Matrix3D targetMat;
		thisMat.Get_Orthogonal_Inverse(targetMat);

		Matrix3D result;
		UnmanagedToManagedMatrix3D(targetMat, result);

		return result;
	}

	void Matrix3D::LookAt(Vector3 p, Vector3 t, float roll)
	{
		::Vector3 pVec;
		::Vector3 tVec;

		Vector3::ManagedToUnmanagedVector3(p, pVec);
		Vector3::ManagedToUnmanagedVector3(t, tVec);

		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Look_At(pVec, tVec, roll);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::ObjLookAt(Vector3 p, Vector3 t, float roll)
	{
		::Vector3 pVec;
		::Vector3 tVec;

		Vector3::ManagedToUnmanagedVector3(p, pVec);
		Vector3::ManagedToUnmanagedVector3(t, tVec);

		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Obj_Look_At(pVec, tVec, roll);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	Vector3 Matrix3D::RotateVector(Vector3 vector)
	{
		::Vector3 vectorVec;

		Vector3::ManagedToUnmanagedVector3(vector, vectorVec);

		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		::Vector3 tmp = thisMat.Rotate_Vector(vectorVec);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	Vector3 Matrix3D::InverseRotateVector(Vector3 vector)
	{
		::Vector3 vectorVec;

		Vector3::ManagedToUnmanagedVector3(vector, vectorVec);

		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		::Vector3 tmp = thisMat.Inverse_Rotate_Vector(vectorVec);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	void Matrix3D::Set(array<float> ^m)
	{
		if (m == nullptr)
		{
			throw gcnew ArgumentNullException("m");
		}
		else if (m->Length != 12)
		{
			throw gcnew ArgumentOutOfRangeException("m");
		}

		float mArray[12]
		{
			m[0],
			m[1],
			m[2],
			m[3],
			m[4],
			m[5],
			m[6],
			m[7],
			m[8],
			m[9],
			m[10],
			m[11]
		};

		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Set(mArray);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::Set(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Set(m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34);
		UnmanagedToManagedMatrix3D(thisMat);

	}

	void Matrix3D::Set(Vector3 x, Vector3 y, Vector3 z, Vector3 pos)
	{
		::Vector3 xVec;
		::Vector3 yVec;
		::Vector3 zVec;
		::Vector3 posVec;

		Vector3::ManagedToUnmanagedVector3(x, xVec);
		Vector3::ManagedToUnmanagedVector3(y, yVec);
		Vector3::ManagedToUnmanagedVector3(z, zVec);
		Vector3::ManagedToUnmanagedVector3(pos, posVec);

		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Set(xVec, yVec, zVec, posVec);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::Set(Vector3 axis, float angle)
	{
		::Vector3 axisVec;

		Vector3::ManagedToUnmanagedVector3(axis, axisVec);

		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Set(axisVec, angle);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::Set(Vector3 axis, float s, float c)
	{
		::Vector3 axisVec;

		Vector3::ManagedToUnmanagedVector3(axis, axisVec);

		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Set(axisVec, s, c);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::Set(Vector3 position)
	{
		::Vector3 posVec;

		Vector3::ManagedToUnmanagedVector3(position, posVec);

		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Set(posVec);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::Set(Matrix3 rotation, Vector3 position)
	{
		::Matrix3 rotMat;
		::Vector3 posVec;

		Matrix3::ManagedToUnmanagedMatrix3(rotation, rotMat);
		Vector3::ManagedToUnmanagedVector3(position, posVec);

		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Set(rotMat, posVec);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::Set(Quaternion rotation, Vector3 position)
	{
		::Quaternion rotQuat;
		::Vector3 posVec;

		Quaternion::ManagedToUnmanagedQuaternion(rotation, rotQuat);
		Vector3::ManagedToUnmanagedVector3(position, posVec);

		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Set(rotQuat, posVec);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::SetRotation(Quaternion rotation)
	{
		::Quaternion rotQuat;

		Quaternion::ManagedToUnmanagedQuaternion(rotation, rotQuat);

		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Set_Rotation(rotQuat);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::SetRotation(Matrix3 m)
	{
		::Matrix3 rotMat;

		Matrix3::ManagedToUnmanagedMatrix3(m, rotMat);

		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Set_Rotation(rotMat);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::AdjustTranslation(Vector3 t)
	{
		::Vector3 tVec;

		Vector3::ManagedToUnmanagedVector3(t, tVec);

		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Adjust_Translation(tVec);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::MakeIdentity()
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Make_Identity();

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::Translate(float x, float y, float z)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Translate(x, y, z);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::Translate(Vector3 t)
	{
		::Vector3 tVec;

		Vector3::ManagedToUnmanagedVector3(t, tVec);

		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Translate(tVec);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::TranslateX(float x)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Translate_X(x);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::TranslateY(float y)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Translate_Y(y);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::TranslateZ(float z)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Translate_Z(z);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::RotateX(float theta)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Rotate_X(theta);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::RotateY(float theta)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Rotate_Y(theta);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::RotateZ(float theta)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Rotate_Z(theta);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::RotateX(float s, float c)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Rotate_X(s, c);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::RotateY(float s, float c)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Rotate_Y(s, c);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::RotateZ(float s, float c)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Rotate_Z(s, c);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::Scale(float scale)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Scale(scale);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::Scale(float x, float y, float z)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Scale(x, y, z);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::Scale(Vector3 scale)
	{
		::Vector3 scaleVec;

		Vector3::ManagedToUnmanagedVector3(scale, scaleVec);

		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Scale(scaleVec);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::PreRotateX(float theta)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Pre_Rotate_X(theta);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::PreRotateY(float theta)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Pre_Rotate_Y(theta);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::PreRotateZ(float theta)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Pre_Rotate_Z(theta);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::PreRotateX(float s, float c)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Pre_Rotate_X(s, c);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::PreRotateY(float s, float c)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Pre_Rotate_Y(s, c);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::PreRotateZ(float s, float c)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Pre_Rotate_Z(s, c);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::InPlacePreRotateX(float theta)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.In_Place_Pre_Rotate_X(theta);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::InPlacePreRotateY(float theta)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.In_Place_Pre_Rotate_Y(theta);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::InPlacePreRotateZ(float theta)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.In_Place_Pre_Rotate_Z(theta);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::InPlacePreRotateX(float s, float c)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.In_Place_Pre_Rotate_X(s, c);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::InPlacePreRotateY(float s, float c)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.In_Place_Pre_Rotate_Y(s, c);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	void Matrix3D::InPlacePreRotateZ(float s, float c)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.In_Place_Pre_Rotate_Z(s, c);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	Matrix3D Matrix3D::Inverse()
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		::Matrix3D tmp;
		thisMat.Get_Inverse(tmp);

		Matrix3D result;
		UnmanagedToManagedMatrix3D(tmp, result);

		return result;
	}

	void Matrix3D::TransformMinMaxAABox(Vector3 min, Vector3 max, Vector3 %setMin, Vector3 %setMax)
	{
		::Vector3 minVec;
		::Vector3 maxVec;

		Vector3::ManagedToUnmanagedVector3(min, minVec);
		Vector3::ManagedToUnmanagedVector3(max, maxVec);

		::Vector3 setMinVec;
		::Vector3 setMaxVec;

		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Transform_Min_Max_AABox(minVec, maxVec, &setMinVec, &setMaxVec);

		Vector3::UnmanagedToManagedVector3(setMinVec, setMin);
		Vector3::UnmanagedToManagedVector3(setMaxVec, setMax);
	}

	void Matrix3D::TransformCenterExtentAABox(Vector3 center, Vector3 extent, Vector3 %setCenter, Vector3 %setExtent)
	{
		::Vector3 centerVec;
		::Vector3 extentVec;

		Vector3::ManagedToUnmanagedVector3(center, centerVec);
		Vector3::ManagedToUnmanagedVector3(extent, extentVec);

		::Vector3 setCenterVec;
		::Vector3 setExtentVec;

		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Transform_Center_Extent_AABox(centerVec, extentVec, &setCenterVec, &setExtentVec);

		Vector3::UnmanagedToManagedVector3(setCenterVec, setCenter);
		Vector3::UnmanagedToManagedVector3(setExtentVec, setExtent);
	}

	PlaneClass Matrix3D::TransformPlane(PlaneClass plane)
	{
		::PlaneClass pPlane;

		PlaneClass::ManagedToUnmanagedPlaneClass(plane, pPlane);

		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		::PlaneClass tmp = thisMat.Transform_Plane(pPlane);

		PlaneClass result;
		PlaneClass::UnmanagedToManagedPlaneClass(tmp, result);

		return result;
	}

	void Matrix3D::ReOrthogonalize()
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Re_Orthogonalize();

		UnmanagedToManagedMatrix3D(thisMat);
	}

	Matrix3D Matrix3D::operator*(Matrix3D a, Matrix3D b)
	{
		::Matrix3D aMat;
		::Matrix3D bMat;

		ManagedToUnmanagedMatrix3D(a, aMat);
		ManagedToUnmanagedMatrix3D(b, bMat);

		::Matrix3D tmp = aMat * bMat;

		Matrix3D result;
		UnmanagedToManagedMatrix3D(tmp, result);

		return result;
	}

	Vector3 Matrix3D::operator*(Matrix3D matrix, Vector3 vector)
	{
		::Matrix3D matrixMat;
		::Vector3 vectorVec;

		ManagedToUnmanagedMatrix3D(matrix, matrixMat);
		Vector3::ManagedToUnmanagedVector3(vector, vectorVec);

		::Vector3 tmp = matrixMat * vectorVec;

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	Vector3 Matrix3D::TransformVector(Matrix3D a, Vector3 in)
	{
		::Matrix3D aMat;
		::Vector3 inVec;

		ManagedToUnmanagedMatrix3D(a, aMat);
		Vector3::ManagedToUnmanagedVector3(in, inVec);

		::Vector3 tmp;
		::Matrix3D::Transform_Vector(aMat, inVec, &tmp);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	Matrix3D Matrix3D::Multiply(Matrix3D a, Matrix3D b)
	{
		::Matrix3D aMat;
		::Matrix3D bMat;

		ManagedToUnmanagedMatrix3D(a, aMat);
		ManagedToUnmanagedMatrix3D(b, bMat);

		::Matrix3D tmp;
		::Matrix3D::Multiply(aMat, bMat, &tmp);

		Matrix3D result;
		UnmanagedToManagedMatrix3D(tmp, result);

		return result;
	}

	Vector3 Matrix3D::RotateVector(Matrix3D a, Vector3 in)
	{
		::Matrix3D aMat;
		::Vector3 inVec;

		ManagedToUnmanagedMatrix3D(a, aMat);
		Vector3::ManagedToUnmanagedVector3(in, inVec);

		::Vector3 tmp;
		::Matrix3D::Rotate_Vector(aMat, inVec, &tmp);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	Vector3 Matrix3D::InverseTransformVector(Matrix3D a, Vector3 in)
	{
		::Matrix3D aMat;
		::Vector3 inVec;

		ManagedToUnmanagedMatrix3D(a, aMat);
		Vector3::ManagedToUnmanagedVector3(in, inVec);

		::Vector3 tmp;
		::Matrix3D::Inverse_Transform_Vector(aMat, inVec, &tmp);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	Vector3 Matrix3D::InverseRotateVector(Matrix3D a, Vector3 in)
	{
		::Matrix3D aMat;
		::Vector3 inVec;

		ManagedToUnmanagedMatrix3D(a, aMat);
		Vector3::ManagedToUnmanagedVector3(in, inVec);

		::Vector3 tmp;
		::Matrix3D::Inverse_Rotate_Vector(aMat, inVec, &tmp);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	Matrix3D Matrix3D::ReflectPlane(PlaneClass plane)
	{
		::PlaneClass pPlane;

		PlaneClass::ManagedToUnmanagedPlaneClass(plane, pPlane);

		::Matrix3D tmp = ::Matrix3D::Reflect_Plane(pPlane);

		Matrix3D result;
		UnmanagedToManagedMatrix3D(tmp, result);

		return result;
	}

	bool Matrix3D::SolveLinearSystem(Matrix3D %system)
	{
		::Matrix3D systemMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(system, systemMat);

		bool result = systemMat.Solve_Linear_System(systemMat);

		UnmanagedToManagedMatrix3D(systemMat, system);

		return result;
	}

	Vector4 Matrix3D::default::get(int index)
	{
		if (index < 0 || index >= 3)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		Vector4 result;
		Vector4::UnmanagedToManagedVector4(thisMat[index], result);

		return result;
	}

	void Matrix3D::default::set(int index, Vector4 value)
	{
		if (index < 0 || index >= 3)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		::Vector4 tmp;
		Vector4::ManagedToUnmanagedVector4(value, tmp);

		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat[index] = tmp;

		UnmanagedToManagedMatrix3D(thisMat);
	}

	float Matrix3D::XRotation::get()
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		return thisMat.Get_X_Rotation();
	}

	float Matrix3D::YRotation::get()
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		return thisMat.Get_Y_Rotation();
	}

	float Matrix3D::ZRotation::get()
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		return thisMat.Get_Z_Rotation();
	}

	Vector3 Matrix3D::Translation::get()
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(thisMat.Get_Translation(), result);

		return result;
	}

	void Matrix3D::Translation::set(Vector3 value)
	{
		::Vector3 valueVec;

		Vector3::ManagedToUnmanagedVector3(value, valueVec);

		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Set_Translation(valueVec);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	float Matrix3D::XTranslation::get()
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		return thisMat.Get_X_Translation();
	}

	void Matrix3D::XTranslation::set(float value)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Set_X_Translation(value);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	float Matrix3D::YTranslation::get()
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		return thisMat.Get_Y_Translation();
	}

	void Matrix3D::YTranslation::set(float value)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Set_Y_Translation(value);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	float Matrix3D::ZTranslation::get()
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		return thisMat.Get_Z_Translation();
	}

	void Matrix3D::ZTranslation::set(float value)
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		thisMat.Set_Z_Translation(value);

		UnmanagedToManagedMatrix3D(thisMat);
	}

	int Matrix3D::IsOrthogonal::get()
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		return thisMat.Is_Orthogonal();
	}

	Vector3 Matrix3D::XVector::get()
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(thisMat.Get_X_Vector(), result);

		return result;
	}

	Vector3 Matrix3D::YVector::get()
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(thisMat.Get_Y_Vector(), result);

		return result;
	}

	Vector3 Matrix3D::ZVector::get()
	{
		::Matrix3D thisMat;
		ManagedToUnmanagedMatrix3D(thisMat);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(thisMat.Get_Z_Vector(), result);

		return result;
	}

	Matrix3D Matrix3D::Identity::get()
	{
		Matrix3D result;
		UnmanagedToManagedMatrix3D(::Matrix3D::Identity, result);

		return result;
	}
}