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
#include "MVector3.h"

#include "Imports.h"

namespace RenSharp
{
	Vector3::Vector3(float x, float y, float z) 
	{
		::Vector3 tmp(x, y, z);
		UnmanagedToManagedVector3(tmp);
	}

	Vector3::Vector3(array<float> ^vector)
	{
		if (vector == nullptr)
		{
			throw gcnew ArgumentNullException("vector");
		}
		else if (vector->Length != 3)
		{
			throw gcnew ArgumentOutOfRangeException("vector");
		}

		const float vectorArray[3] = { vector[0], vector[1], vector[2] };
		::Vector3 tmpVec(vectorArray);

		X = tmpVec.X;
		Y = tmpVec.Y;
		Z = tmpVec.Z;
	}

	Vector3::Vector3(IntPtr pointer)
	{
		if (pointer == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		::Vector3 *tmpVec = reinterpret_cast<::Vector3 *>(pointer.ToPointer());

		X = tmpVec->X;
		Y = tmpVec->Y;
		Z = tmpVec->Z;
	}

	void Vector3::Set(float x, float y, float z)
	{
		::Vector3 thisVec;

		ManagedToUnmanagedVector3(thisVec);

		thisVec.Set(x, y, z);

		UnmanagedToManagedVector3(thisVec);
	}

	void Vector3::Set(Vector3 other)
	{
		::Vector3 thisVec;
		::Vector3 otherVec;

		ManagedToUnmanagedVector3(thisVec);
		ManagedToUnmanagedVector3(other, otherVec);

		thisVec.Set(otherVec);

		UnmanagedToManagedVector3(thisVec);
	}

	void Vector3::Normalize()
	{
		::Vector3 thisVec;

		ManagedToUnmanagedVector3(thisVec);

		Imports::Vector3Normalize(&thisVec); // Vector3::Normalize references WWMath::Inv_Sqrt which is a fastcall. We can't call fastcall functions

		UnmanagedToManagedVector3(thisVec);
	}

	Vector3 Vector3::Normalized()
	{
		::Vector3 thisVec;
		::Vector3 resultVec;

		ManagedToUnmanagedVector3(thisVec);

		Imports::Vector3Normalized(&thisVec, &resultVec); // Vector3::Normalized references WWMath::Inv_Sqrt which is a fastcall. We can't call fastcall functions
	
		Vector3 result;
		UnmanagedToManagedVector3(resultVec, result);

		return result;
	}

	void Vector3::Scale(Vector3 scale)
	{
		::Vector3 thisVec;
		::Vector3 scaleVec;

		ManagedToUnmanagedVector3(thisVec);
		ManagedToUnmanagedVector3(scale, scaleVec);

		thisVec.Scale(scaleVec);

		UnmanagedToManagedVector3(thisVec);
	}

	void Vector3::RotateX(float angle)
	{
		::Vector3 thisVec;

		ManagedToUnmanagedVector3(thisVec);

		thisVec.Rotate_X(angle);

		UnmanagedToManagedVector3(thisVec);
	}

	void Vector3::RotateX(float sAngle, float cAngle)
	{
		::Vector3 thisVec;

		ManagedToUnmanagedVector3(thisVec);

		thisVec.Rotate_X(sAngle, cAngle);

		UnmanagedToManagedVector3(thisVec);
	}

	void Vector3::RotateY(float angle)
	{
		::Vector3 thisVec;

		ManagedToUnmanagedVector3(thisVec);

		thisVec.Rotate_Y(angle);

		UnmanagedToManagedVector3(thisVec);
	}

	void Vector3::RotateY(float sAngle, float cAngle)
	{
		::Vector3 thisVec;

		ManagedToUnmanagedVector3(thisVec);

		thisVec.Rotate_Y(sAngle, cAngle);

		UnmanagedToManagedVector3(thisVec);
	}

	void Vector3::RotateZ(float angle)
	{
		::Vector3 thisVec;

		ManagedToUnmanagedVector3(thisVec);

		thisVec.Rotate_Z(angle);

		UnmanagedToManagedVector3(thisVec);
	}

	void Vector3::RotateZ(float sAngle, float cAngle)
	{
		::Vector3 thisVec;

		ManagedToUnmanagedVector3(thisVec);

		thisVec.Rotate_Z(sAngle, cAngle);

		UnmanagedToManagedVector3(thisVec);
	}

	Vector3 Vector3::Mul(Vector3 other)
	{
		::Vector3 thisVec;
		::Vector3 otherVec;

		ManagedToUnmanagedVector3(thisVec);
		ManagedToUnmanagedVector3(other, otherVec);

		::Vector3 tmp = thisVec.mul(otherVec);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	void Vector3::UpdateMin(Vector3 a)
	{
		::Vector3 thisVec;
		::Vector3 aVec;

		ManagedToUnmanagedVector3(thisVec);
		ManagedToUnmanagedVector3(a, aVec);

		thisVec.Update_Min(aVec);

		UnmanagedToManagedVector3(thisVec);
	}

	void Vector3::UpdateMax(Vector3 a)
	{
		::Vector3 thisVec;
		::Vector3 aVec;

		ManagedToUnmanagedVector3(thisVec);
		ManagedToUnmanagedVector3(a, aVec);

		thisVec.Update_Max(aVec);

		UnmanagedToManagedVector3(thisVec);
	}

	void Vector3::CapAbsoluteTo(Vector3 a)
	{
		::Vector3 thisVec;
		::Vector3 aVec;

		ManagedToUnmanagedVector3(thisVec);
		ManagedToUnmanagedVector3(a, aVec);

		thisVec.Cap_Absolute_To(aVec);

		UnmanagedToManagedVector3(thisVec);
	}

	Vector3 Vector3::operator-(Vector3 a, Vector3 b)
	{
		::Vector3 aVec;
		::Vector3 bVec;

		ManagedToUnmanagedVector3(a, aVec);
		ManagedToUnmanagedVector3(b, bVec);

		Vector3 result;
		UnmanagedToManagedVector3(aVec - bVec, result);

		return result;
	}

	Vector3 Vector3::operator-(Vector3 a)
	{
		::Vector3 aVec;

		ManagedToUnmanagedVector3(a, aVec);

		Vector3 result;
		UnmanagedToManagedVector3(-aVec, result);

		return result;
	}

	Vector3 Vector3::operator+(Vector3 a, Vector3 b)
	{
		::Vector3 aVec;
		::Vector3 bVec;

		ManagedToUnmanagedVector3(a, aVec);
		ManagedToUnmanagedVector3(b, bVec);

		Vector3 result;
		UnmanagedToManagedVector3(aVec + bVec, result);

		return result;
	}

	Vector3 Vector3::operator+(Vector3 a)
	{
		::Vector3 aVec;

		ManagedToUnmanagedVector3(a, aVec);

		Vector3 result;
		UnmanagedToManagedVector3(+aVec, result);

		return result;
	}

	Vector3 Vector3::operator*(Vector3 a, float k)
	{
		::Vector3 aVec;

		ManagedToUnmanagedVector3(a, aVec);

		Vector3 result;
		UnmanagedToManagedVector3(aVec * k, result);

		return result;
	}

	Vector3 Vector3::operator*(float k, Vector3 a)
	{
		::Vector3 aVec;

		ManagedToUnmanagedVector3(a, aVec);

		Vector3 result;
		UnmanagedToManagedVector3(k * aVec, result);

		return result;
	}

	float Vector3::operator*(Vector3 a, Vector3 b)
	{
		::Vector3 aVec;
		::Vector3 bVec;

		ManagedToUnmanagedVector3(a, aVec);
		ManagedToUnmanagedVector3(b, bVec);

		float result = aVec * bVec;

		return result;
	}

	Vector3 Vector3::operator/(Vector3 a, float k)
	{
		::Vector3 aVec;

		ManagedToUnmanagedVector3(a, aVec);

		Vector3 result;
		UnmanagedToManagedVector3(aVec / k, result);

		return result;
	}

	float Vector3::DotProduct(Vector3 a, Vector3 b)
	{
		::Vector3 aVec;
		::Vector3 bVec;

		ManagedToUnmanagedVector3(a, aVec);
		ManagedToUnmanagedVector3(b, bVec);

		float result = ::Vector3::Dot_Product(aVec, bVec);

		return result;
	}

	Vector3 Vector3::CrossProduct(Vector3 a, Vector3 b)
	{
		::Vector3 aVec;
		::Vector3 bVec;

		ManagedToUnmanagedVector3(a, aVec);
		ManagedToUnmanagedVector3(b, bVec);

		Vector3 result;
		UnmanagedToManagedVector3(::Vector3::Cross_Product(aVec, bVec), result);

		return result;
	}

	float Vector3::CrossProductX(Vector3 a, Vector3 b)
	{
		::Vector3 aVec;
		::Vector3 bVec;

		ManagedToUnmanagedVector3(a, aVec);
		ManagedToUnmanagedVector3(b, bVec);

		float result = ::Vector3::Cross_Product_X(aVec, bVec);

		return result;
	}

	float Vector3::CrossProductY(Vector3 a, Vector3 b)
	{
		::Vector3 aVec;
		::Vector3 bVec;

		ManagedToUnmanagedVector3(a, aVec);
		ManagedToUnmanagedVector3(b, bVec);

		float result = ::Vector3::Cross_Product_Y(aVec, bVec);

		return result;
	}

	float Vector3::CrossProductZ(Vector3 a, Vector3 b)
	{
		::Vector3 aVec;
		::Vector3 bVec;

		ManagedToUnmanagedVector3(a, aVec);
		ManagedToUnmanagedVector3(b, bVec);

		float result = ::Vector3::Cross_Product_Z(aVec, bVec);

		return result;
	}

	Vector3 Vector3::Add(Vector3 a, Vector3 b)
	{
		::Vector3 aVec;
		::Vector3 bVec;

		ManagedToUnmanagedVector3(a, aVec);
		ManagedToUnmanagedVector3(b, bVec);

		::Vector3 tmp;
		::Vector3::Add(aVec, bVec, &tmp);

		Vector3 result;
		UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	Vector3 Vector3::Subtract(Vector3 a, Vector3 b)
	{
		::Vector3 aVec;
		::Vector3 bVec;

		ManagedToUnmanagedVector3(a, aVec);
		ManagedToUnmanagedVector3(b, bVec);

		::Vector3 tmp;
		::Vector3::Subtract(aVec, bVec, &tmp);

		Vector3 result;
		UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	float Vector3::FindXAtY(float y, Vector3 p1, Vector3 p2)
	{
		::Vector3 p1Vec;
		::Vector3 p2Vec;

		ManagedToUnmanagedVector3(p1, p1Vec);
		ManagedToUnmanagedVector3(p2, p2Vec);

		float result = ::Vector3::Find_X_At_Y(y, p1Vec, p2Vec);

		return result;
	}

	float Vector3::FindXAtZ(float z, Vector3 p1, Vector3 p2)
	{
		::Vector3 p1Vec;
		::Vector3 p2Vec;

		ManagedToUnmanagedVector3(p1, p1Vec);
		ManagedToUnmanagedVector3(p2, p2Vec);

		float result = ::Vector3::Find_X_At_Z(z, p1Vec, p2Vec);

		return result;
	}

	float Vector3::FindYAtX(float x, Vector3 p1, Vector3 p2)
	{
		::Vector3 p1Vec;
		::Vector3 p2Vec;

		ManagedToUnmanagedVector3(p1, p1Vec);
		ManagedToUnmanagedVector3(p2, p2Vec);

		float result = ::Vector3::Find_Y_At_X(x, p1Vec, p2Vec);

		return result;
	}

	float Vector3::FindYAtZ(float z, Vector3 p1, Vector3 p2)
	{
		::Vector3 p1Vec;
		::Vector3 p2Vec;

		ManagedToUnmanagedVector3(p1, p1Vec);
		ManagedToUnmanagedVector3(p2, p2Vec);

		float result = ::Vector3::Find_Y_At_Z(z, p1Vec, p2Vec);

		return result;
	}

	float Vector3::FindZAtX(float x, Vector3 p1, Vector3 p2)
	{
		::Vector3 p1Vec;
		::Vector3 p2Vec;

		ManagedToUnmanagedVector3(p1, p1Vec);
		ManagedToUnmanagedVector3(p2, p2Vec);

		float result = ::Vector3::Find_Z_At_X(x, p1Vec, p2Vec);

		return result;
	}

	float Vector3::FindZAtY(float y, Vector3 p1, Vector3 p2)
	{
		::Vector3 p1Vec;
		::Vector3 p2Vec;

		ManagedToUnmanagedVector3(p1, p1Vec);
		ManagedToUnmanagedVector3(p2, p2Vec);

		float result = ::Vector3::Find_Z_At_Y(y, p1Vec, p2Vec);

		return result;
	}

	float Vector3::Distance(Vector3 p1, Vector3 p2)
	{
		::Vector3 p1Vec;
		::Vector3 p2Vec;

		ManagedToUnmanagedVector3(p1, p1Vec);
		ManagedToUnmanagedVector3(p2, p2Vec);

		float result = ::Vector3::Distance(p1Vec, p2Vec);

		return result;
	}

	Vector3 Vector3::Lerp(Vector3 a, Vector3 b, float alpha)
	{
		::Vector3 aVec;
		::Vector3 bVec;

		ManagedToUnmanagedVector3(a, aVec);
		ManagedToUnmanagedVector3(b, bVec);

		::Vector3 tmp;
		::Vector3::Lerp(aVec, bVec, alpha, &tmp);

		Vector3 result;
		UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	Vector3 Vector3::Replicate(float n)
	{
		Vector3 result;
		UnmanagedToManagedVector3(::Vector3::Replicate(n), result);

		return result;
	}

	void Vector3::Swap(Vector3 %a, Vector3 %b)
	{
		::Vector3 aVec;
		::Vector3 bVec;

		ManagedToUnmanagedVector3(a, aVec);
		ManagedToUnmanagedVector3(b, bVec);

		::Swap(aVec, bVec);

		a.X = aVec.X;
		a.Y = aVec.Y;
		a.Z = aVec.Z;

		b.X = bVec.X;
		b.Y = bVec.Y;
		b.Z = bVec.Z;
	}

	bool Vector3::IsValid::get()
	{
		::Vector3 thisVec;
		ManagedToUnmanagedVector3(thisVec);

		return thisVec.Is_Valid();
	}

	float Vector3::default::get(int index)
	{
		if (index < 0 || index >= 3)
		{
			throw gcnew IndexOutOfRangeException("index");
		}

		::Vector3 thisVec;
		ManagedToUnmanagedVector3(thisVec);

		return thisVec[index];
	}

	void Vector3::default::set(int index, float value)
	{
		if (index < 0 || index >= 3)
		{
			throw gcnew IndexOutOfRangeException("index");
		}

		::Vector3 thisVec;
		ManagedToUnmanagedVector3(thisVec);

		thisVec[index] = value;

		UnmanagedToManagedVector3(thisVec);
	}

	float Vector3::Length::get()
	{
		::Vector3 thisVec;
		ManagedToUnmanagedVector3(thisVec);

		return thisVec.Length();
	}

	float Vector3::Length2::get()
	{
		::Vector3 thisVec;
		ManagedToUnmanagedVector3(thisVec);

		return thisVec.Length2();
	}

	Vector3 Vector3::Abs::get()
	{
		::Vector3 thisVec;
		ManagedToUnmanagedVector3(thisVec);

		Vector3 result;
		UnmanagedToManagedVector3(thisVec.abs(), result);

		return result;
	}

	Color Vector3::ARGB::get()
	{
		::Vector3 thisVec;
		ManagedToUnmanagedVector3(thisVec);

		return Color::FromArgb(static_cast<int>(thisVec.Convert_To_ARGB()));
	}

	float Vector3::QuickLength::get()
	{
		::Vector3 thisVec;
		ManagedToUnmanagedVector3(thisVec);

		return thisVec.Quick_Length();
	}
}