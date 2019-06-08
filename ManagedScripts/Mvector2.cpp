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
#include "Mvector2.h"

#include "Imports.h"

namespace RenSharp
{
	Vector2i::Vector2i(int i, int j)
	{
		::Vector2i thisVec(i, j);

		UnmanagedToManagedVector2i(thisVec);
	}

	Vector2i::Vector2i(IntPtr pointer)
	{
		if (pointer == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		::Vector2i *thisVec = reinterpret_cast<::Vector2i *>(pointer.ToPointer());

		I = thisVec->I;
		J = thisVec->J;
	}

	void Vector2i::Set(int i, int j)
	{
		::Vector2i thisVec;
		ManagedToUnmanagedVector2i(thisVec);

		thisVec.Set(i, j);

		UnmanagedToManagedVector2i(thisVec);
	}

	Vector2::Vector2(float x, float y)
	{
		::Vector2 thisVec(x, y);

		UnmanagedToManagedVector2(thisVec);
	}

	Vector2::Vector2(array<float> ^vector)
	{
		if (vector == nullptr)
		{
			throw gcnew ArgumentNullException("vector");
		}
		else if (vector->Length != 2)
		{
			throw gcnew ArgumentOutOfRangeException("vector");
		}

		float tmpVector[2] =
		{
			vector[0],
			vector[1]
		};

		::Vector2 thisVec(tmpVector);

		UnmanagedToManagedVector2(thisVec);
	}

	Vector2::Vector2(IntPtr pointer)
	{
		if (pointer == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		::Vector2 *thisVec = reinterpret_cast<::Vector2 *>(pointer.ToPointer());

		X = thisVec->X;
		Y = thisVec->Y;
	}

	void Vector2::Set(float x, float y)
	{
		::Vector2 thisVec;
		ManagedToUnmanagedVector2(thisVec);

		thisVec.Set(x, y);

		UnmanagedToManagedVector2(thisVec);
	}

	void Vector2::Normalize()
	{
		::Vector2 thisVec;
		ManagedToUnmanagedVector2(thisVec);

		Imports::Vector2Normalize(&thisVec);

		UnmanagedToManagedVector2(thisVec);
	}

	void Vector2::Rotate(float theta)
	{
		::Vector2 thisVec;
		ManagedToUnmanagedVector2(thisVec);

		thisVec.Rotate(theta);

		UnmanagedToManagedVector2(thisVec);
	}

	void Vector2::Rotate(float s, float c)
	{
		::Vector2 thisVec;
		ManagedToUnmanagedVector2(thisVec);

		thisVec.Rotate(s, c);

		UnmanagedToManagedVector2(thisVec);
	}

	bool Vector2::RotateTowardsVector(Vector2 target, float maxTheta, [Out] bool %positiveTurn)
	{
		::Vector2 targetVec;
		bool tmpPositiveTurn;

		ManagedToUnmanagedVector2(target, targetVec);

		::Vector2 thisVec;
		ManagedToUnmanagedVector2(thisVec);

		bool result = thisVec.Rotate_Towards_Vector(targetVec, maxTheta, tmpPositiveTurn);

		UnmanagedToManagedVector2(thisVec);

		positiveTurn = tmpPositiveTurn;

		return result;
	}

	bool Vector2::RotateTowardsVector(Vector2 target, float maxS, float maxC, [Out] bool %positiveTurn)
	{
		::Vector2 targetVec;
		bool tmpPositiveTurn;

		ManagedToUnmanagedVector2(target, targetVec);

		::Vector2 thisVec;
		ManagedToUnmanagedVector2(thisVec);

		bool result = thisVec.Rotate_Towards_Vector(targetVec, maxS, maxC, tmpPositiveTurn);

		UnmanagedToManagedVector2(thisVec);

		positiveTurn = tmpPositiveTurn;

		return result;
	}

	void Vector2::UpdateMin(Vector2 a)
	{
		::Vector2 aVec;

		Vector2::ManagedToUnmanagedVector2(a, aVec);

		::Vector2 thisVec;
		ManagedToUnmanagedVector2(thisVec);

		thisVec.Update_Min(aVec);

		UnmanagedToManagedVector2(thisVec);
	}

	void Vector2::UpdateMax(Vector2 a)
	{
		::Vector2 aVec;

		Vector2::ManagedToUnmanagedVector2(a, aVec);

		::Vector2 thisVec;
		ManagedToUnmanagedVector2(thisVec);

		thisVec.Update_Max(aVec);

		UnmanagedToManagedVector2(thisVec);
	}

	void Vector2::Scale(float a, float b)
	{
		::Vector2 thisVec;
		ManagedToUnmanagedVector2(thisVec);

		thisVec.Scale(a, b);

		UnmanagedToManagedVector2(thisVec);
	}

	void Vector2::Scale(Vector2 a)
	{
		::Vector2 aVec;

		Vector2::ManagedToUnmanagedVector2(a, aVec);

		::Vector2 thisVec;
		ManagedToUnmanagedVector2(thisVec);

		thisVec.Scale(aVec);

		UnmanagedToManagedVector2(thisVec);
	}

	void Vector2::Unscale(Vector2 a)
	{
		::Vector2 aVec;

		Vector2::ManagedToUnmanagedVector2(a, aVec);

		::Vector2 thisVec;
		ManagedToUnmanagedVector2(thisVec);

		thisVec.Unscale(aVec);

		UnmanagedToManagedVector2(thisVec);
	}

	void Vector2::Floor()
	{
		::Vector2 thisVec;
		ManagedToUnmanagedVector2(thisVec);

		thisVec.Floor();

		UnmanagedToManagedVector2(thisVec);
	}

	Vector2 Vector2::operator-(Vector2 a, Vector2 b)
	{
		::Vector2 aVec;
		::Vector2 bVec;

		ManagedToUnmanagedVector2(a, aVec);
		ManagedToUnmanagedVector2(b, bVec);

		::Vector2 tmp = aVec - bVec;

		Vector2 result;
		UnmanagedToManagedVector2(tmp, result);

		return result;
	}

	Vector2 Vector2::operator-(Vector2 a)
	{
		::Vector2 aVec;

		ManagedToUnmanagedVector2(a, aVec);

		::Vector2 tmp = -aVec;

		Vector2 result;
		UnmanagedToManagedVector2(tmp, result);

		return result;
	}

	Vector2 Vector2::operator+(Vector2 a, Vector2 b)
	{
		::Vector2 aVec;
		::Vector2 bVec;

		ManagedToUnmanagedVector2(a, aVec);
		ManagedToUnmanagedVector2(b, bVec);

		::Vector2 tmp = aVec + bVec;

		Vector2 result;
		UnmanagedToManagedVector2(tmp, result);

		return result;
	}

	Vector2 Vector2::operator+(Vector2 a)
	{
		::Vector2 aVec;

		ManagedToUnmanagedVector2(a, aVec);

		::Vector2 tmp = +aVec;

		Vector2 result;
		UnmanagedToManagedVector2(tmp, result);

		return result;
	}

	Vector2 Vector2::operator*(Vector2 a, float k)
	{
		::Vector2 aVec;

		ManagedToUnmanagedVector2(a, aVec);

		::Vector2 tmp = aVec * k;

		Vector2 result;
		UnmanagedToManagedVector2(tmp, result);

		return result;
	}

	Vector2 Vector2::operator*(float k, Vector2 a)
	{
		::Vector2 aVec;

		ManagedToUnmanagedVector2(a, aVec);

		::Vector2 tmp = k * aVec;

		Vector2 result;
		UnmanagedToManagedVector2(tmp, result);

		return result;
	}

	float Vector2::operator*(Vector2 a, Vector2 b)
	{
		::Vector2 aVec;
		::Vector2 bVec;

		ManagedToUnmanagedVector2(a, aVec);
		ManagedToUnmanagedVector2(b, bVec);

		return (aVec * bVec);
	}

	Vector2 Vector2::operator/(Vector2 a, float k)
	{
		::Vector2 aVec;

		ManagedToUnmanagedVector2(a, aVec);

		::Vector2 tmp = aVec / k;

		Vector2 result;
		UnmanagedToManagedVector2(tmp, result);

		return result;
	}

	Vector2 Vector2::operator/(Vector2 a, Vector2 b)
	{
		::Vector2 aVec;
		::Vector2 bVec;

		ManagedToUnmanagedVector2(a, aVec);
		ManagedToUnmanagedVector2(b, bVec);

		::Vector2 tmp = aVec / bVec;

		Vector2 result;
		UnmanagedToManagedVector2(tmp, result);

		return result;
	}

	Vector2 Vector2::operator/(Vector2 a, Vector2i b)
	{
		::Vector2 aVec;
		::Vector2i bVec;

		ManagedToUnmanagedVector2(a, aVec);
		Vector2i::ManagedToUnmanagedVector2i(b, bVec);

		::Vector2 tmp = aVec / bVec;

		Vector2 result;
		UnmanagedToManagedVector2(tmp, result);

		return result;
	}

	float Vector2::DotProduct(Vector2 a, Vector2 b)
	{
		::Vector2 aVec;
		::Vector2 bVec;

		ManagedToUnmanagedVector2(a, aVec);
		ManagedToUnmanagedVector2(b, bVec);

		return ::Vector2::Dot_Product(aVec, bVec);
	}

	float Vector2::PerpDotProduct(Vector2 a, Vector2 b)
	{
		::Vector2 aVec;
		::Vector2 bVec;

		ManagedToUnmanagedVector2(a, aVec);
		ManagedToUnmanagedVector2(b, bVec);

		return ::Vector2::Perp_Dot_Product(aVec, bVec);
	}

	float Vector2::Distance(Vector2 p1, Vector2 p2)
	{
		::Vector2 p1Vec;
		::Vector2 p2Vec;

		ManagedToUnmanagedVector2(p1, p1Vec);
		ManagedToUnmanagedVector2(p2, p2Vec);

		return ::Vector2::Distance(p1Vec, p2Vec);
	}

	Vector2 Vector2::Lerp(Vector2 a, Vector2 b, float t)
	{
		::Vector2 aVec;
		::Vector2 bVec;

		ManagedToUnmanagedVector2(a, aVec);
		ManagedToUnmanagedVector2(b, bVec);

		::Vector2 tmp;
		::Vector2::Lerp(aVec, bVec, t, &tmp);

		Vector2 result;
		UnmanagedToManagedVector2(tmp, result);

		return result;
	}

	void Vector2::Swap(Vector2 %a, Vector2 %b)
	{
		::Vector2 aVec;
		::Vector2 bVec;

		ManagedToUnmanagedVector2(a, aVec);
		ManagedToUnmanagedVector2(b, bVec);

		::Swap(aVec, bVec);

		UnmanagedToManagedVector2(aVec, a);
		UnmanagedToManagedVector2(bVec, b);
	}

	float Vector2::Distance(float x1, float y1, float x2, float y2)
	{
		return ::Distance(x1, y1, x2, y2);
	}

	float Vector2::U::get()
	{
		return X;
	}

	void Vector2::U::set(float value)
	{
		X = value;
	}

	float Vector2::V::get()
	{
		return Y;
	}

	void Vector2::V::set(float value)
	{
		Y = value;
	}

	float Vector2::default::get(int index)
	{
		if (index < 0 || index >= 2)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		::Vector2 thisVec;
		ManagedToUnmanagedVector2(thisVec);

		return thisVec[index];
	}

	void Vector2::default::set(int index, float value)
	{
		if (index < 0 || index >= 2)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		::Vector2 thisVec;
		ManagedToUnmanagedVector2(thisVec);

		thisVec[index] = value;

		UnmanagedToManagedVector2(thisVec);
	}

	float Vector2::Length::get()
	{
		::Vector2 thisVec;
		ManagedToUnmanagedVector2(thisVec);

		return thisVec.Length();
	}

	float Vector2::Length2::get()
	{
		::Vector2 thisVec;
		ManagedToUnmanagedVector2(thisVec);

		return thisVec.Length2();
	}
}