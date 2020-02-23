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
#include "Mvector4.h"

#include "Imports.h"

namespace RenSharp
{
	Vector4::Vector4(float x, float y, float z, float w)
	{
		::Vector4 tmp(x, y, z, w);
		UnmanagedToManagedVector4(tmp);
	}

	Vector4::Vector4(array<float> ^v)
	{
		if (v == nullptr)
		{
			throw gcnew ArgumentNullException("v");
		}
		else if (v->Length != 4)
		{
			throw gcnew ArgumentOutOfRangeException("v");
		}

		const float vectorArray[4] = { v[0], v[1], v[2], v[3] };
		::Vector4 tmpVec(vectorArray);

		X = tmpVec.X;
		Y = tmpVec.Y;
		Z = tmpVec.Z;
		W = tmpVec.W;
	}

	Vector4::Vector4(IntPtr pointer)
	{
		if (pointer == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		::Vector4 *tmpVec = reinterpret_cast<::Vector4 *>(pointer.ToPointer());

		X = tmpVec->X;
		Y = tmpVec->Y;
		Z = tmpVec->Z;
		W = tmpVec->W;
	}

	void Vector4::Set(float x, float y, float z, float w)
	{
		::Vector4 thisVec;

		ManagedToUnmanagedVector4(thisVec);

		thisVec.Set(x, y, z, w);

		UnmanagedToManagedVector4(thisVec);
	}

	void Vector4::Normalize()
	{
		::Vector4 thisVec;

		ManagedToUnmanagedVector4(thisVec);

		Imports::Vector4Normalize(&thisVec); // Vector3::Normalize references WWMath::Inv_Sqrt which is a fastcall. We can't call fastcall functions

		UnmanagedToManagedVector4(thisVec);
	}

	Vector4 Vector4::operator-(Vector4 a, Vector4 b)
	{
		::Vector4 aVec;
		::Vector4 bVec;

		ManagedToUnmanagedVector4(a, aVec);
		ManagedToUnmanagedVector4(b, bVec);

		Vector4 result;
		UnmanagedToManagedVector4(aVec - bVec, result);

		return result;
	}

	Vector4 Vector4::operator-(Vector4 a)
	{
		::Vector4 aVec;

		ManagedToUnmanagedVector4(a, aVec);

		Vector4 result;
		UnmanagedToManagedVector4(-aVec, result);

		return result;
	}

	Vector4 Vector4::operator+(Vector4 a, Vector4 b)
	{
		::Vector4 aVec;
		::Vector4 bVec;

		ManagedToUnmanagedVector4(a, aVec);
		ManagedToUnmanagedVector4(b, bVec);

		Vector4 result;
		UnmanagedToManagedVector4(aVec + bVec, result);

		return result;
	}

	Vector4 Vector4::operator+(Vector4 a)
	{
		::Vector4 aVec;

		ManagedToUnmanagedVector4(a, aVec);

		Vector4 result;
		UnmanagedToManagedVector4(+aVec, result);

		return result;
	}

	Vector4 Vector4::operator*(Vector4 a, float f)
	{
		::Vector4 aVec;

		ManagedToUnmanagedVector4(a, aVec);

		Vector4 result;
		UnmanagedToManagedVector4(aVec * f, result);

		return result;
	}

	Vector4 Vector4::operator*(float f, Vector4 a)
	{
		::Vector4 aVec;

		ManagedToUnmanagedVector4(a, aVec);

		Vector4 result;
		UnmanagedToManagedVector4(f * aVec, result);

		return result;
	}

	float Vector4::operator*(Vector4 a, Vector4 b)
	{
		::Vector4 aVec;
		::Vector4 bVec;

		ManagedToUnmanagedVector4(a, aVec);
		ManagedToUnmanagedVector4(b, bVec);

		float result = aVec * bVec;

		return result;
	}

	Vector4 Vector4::operator/(Vector4 a, float f)
	{
		::Vector4 aVec;

		ManagedToUnmanagedVector4(a, aVec);

		Vector4 result;
		UnmanagedToManagedVector4(aVec / f, result);

		return result;
	}

	float Vector4::DotProduct(Vector4 a, Vector4 b)
	{
		::Vector4 aVec;
		::Vector4 bVec;

		ManagedToUnmanagedVector4(a, aVec);
		ManagedToUnmanagedVector4(b, bVec);

		float result = ::Vector4::Dot_Product(aVec, bVec);

		return result;
	}

	Vector4 Vector4::Lerp(Vector4 a, Vector4 b, float alpha)
	{
		::Vector4 aVec;
		::Vector4 bVec;

		ManagedToUnmanagedVector4(a, aVec);
		ManagedToUnmanagedVector4(b, bVec);

		::Vector4 tmp;
		::Vector4::Lerp(aVec, bVec, alpha, &tmp);

		Vector4 result;
		UnmanagedToManagedVector4(tmp, result);

		return result;
	}

	void Vector4::Swap(Vector4 %a, Vector4 %b)
	{
		::Vector4 aVec;
		::Vector4 bVec;

		ManagedToUnmanagedVector4(a, aVec);
		ManagedToUnmanagedVector4(b, bVec);

		::Swap(aVec, bVec);

		a.X = aVec.X;
		a.Y = aVec.Y;
		a.Z = aVec.Z;
		a.W = aVec.W;

		b.X = bVec.X;
		b.Y = bVec.Y;
		b.Z = bVec.Z;
		b.W = bVec.W;
	}

	float Vector4::default::get(int index)
	{
		if (index < 0 || index >= 4)
		{
			throw gcnew IndexOutOfRangeException("index");
		}

		::Vector4 thisVec;
		ManagedToUnmanagedVector4(thisVec);

		return thisVec[index];
	}

	void Vector4::default::set(int index, float value)
	{
		if (index < 0 || index >= 4)
		{
			throw gcnew IndexOutOfRangeException("index");
		}

		::Vector4 thisVec;
		ManagedToUnmanagedVector4(thisVec);

		thisVec[index] = value;

		UnmanagedToManagedVector4(thisVec);
	}

	float Vector4::Length::get()
	{
		::Vector4 thisVec;
		ManagedToUnmanagedVector4(thisVec);

		return thisVec.Length();
	}

	float Vector4::Length2::get()
	{
		::Vector4 thisVec;
		ManagedToUnmanagedVector4(thisVec);

		return thisVec.Length2();
	}
}