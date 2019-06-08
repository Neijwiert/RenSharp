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
#include "MQuaternion.h"

#include "MVector3.h"

namespace RenSharp
{
	Quaternion::Quaternion(bool init)
	{
		::Quaternion tmp(init);
		UnmanagedToManagedQuaternion(tmp);
	}

	Quaternion::Quaternion(float a, float b, float c, float d)
	{
		::Quaternion tmp(a, b, c, d);
		UnmanagedToManagedQuaternion(tmp);
	}

	Quaternion::Quaternion(IntPtr pointer)
	{
		if (pointer == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		::Quaternion *tmp = reinterpret_cast<::Quaternion *>(pointer.ToPointer());

		X = tmp->X;
		Y = tmp->Y;
		Z = tmp->Z;
		W = tmp->W;
	}

	bool Quaternion::Equals(Object ^other)
	{
		Quaternion ^otherQuat = dynamic_cast<Quaternion ^>(other);
		if (otherQuat == nullptr)
		{
			return false;
		}

		bool result = true;

		result &= X.Equals(otherQuat->X);
		result &= Y.Equals(otherQuat->Y);
		result &= Z.Equals(otherQuat->Z);
		result &= W.Equals(otherQuat->W);

		return result;
	}

	int Quaternion::GetHashCode()
	{
		int hash = 17;
		hash = hash * 23 + X.GetHashCode();
		hash = hash * 23 + Y.GetHashCode();
		hash = hash * 23 + Z.GetHashCode();
		hash = hash * 23 + W.GetHashCode();

		return hash;
	}

	Quaternion Quaternion::Conjugate()
	{
		::Quaternion tmp;
		ManagedToUnmanagedQuaternion(tmp);

		Quaternion result;
		UnmanagedToManagedQuaternion(tmp.conjugate(), result);

		return result;
	}

	void Quaternion::Scale(float s)
	{
		::Quaternion tmp;
		tmp.Scale(s);

		UnmanagedToManagedQuaternion(tmp);
	}

	void Quaternion::MakeIdentity()
	{
		::Quaternion tmp;
		tmp.Make_Identity();

		UnmanagedToManagedQuaternion(tmp);
	}

	void Quaternion::Set(float a, float b, float c, float d)
	{
		::Quaternion tmp;
		ManagedToUnmanagedQuaternion(tmp);

		tmp.Set(a, b, c, d);

		UnmanagedToManagedQuaternion(tmp);
	}

	void Quaternion::Set(float a, float b, float c)
	{
		::Quaternion tmp;
		ManagedToUnmanagedQuaternion(tmp);

		tmp.Set(a, b, c);

		UnmanagedToManagedQuaternion(tmp);
	}

	void Quaternion::Set(float a, float b)
	{
		::Quaternion tmp;
		ManagedToUnmanagedQuaternion(tmp);

		tmp.Set(a, b);

		UnmanagedToManagedQuaternion(tmp);
	}

	void Quaternion::Set(float a)
	{
		::Quaternion tmp;
		ManagedToUnmanagedQuaternion(tmp);

		tmp.Set(a);

		UnmanagedToManagedQuaternion(tmp);
	}

	void Quaternion::Set()
	{
		::Quaternion tmp;
		ManagedToUnmanagedQuaternion(tmp);

		tmp.Set();

		UnmanagedToManagedQuaternion(tmp);
	}

	Vector3 Quaternion::RotateVector(Vector3 v)
	{
		::Vector3 input;
		Vector3::ManagedToUnmanagedVector3(v, input);

		::Quaternion tmp;

		ManagedToUnmanagedQuaternion(tmp);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp.Rotate_Vector(input), result);

		return Vector3(result.X, result.Y, result.Z);
	}

	Quaternion Quaternion::operator*(Vector3 a, Quaternion b)
	{
		::Vector3 aVec;
		Vector3::ManagedToUnmanagedVector3(a, aVec);

		::Quaternion bQuat;

		ManagedToUnmanagedQuaternion(b, bQuat);

		Quaternion result;
		UnmanagedToManagedQuaternion(aVec * bQuat, result);

		return result;
	}

	Quaternion Quaternion::operator*(float scl, Quaternion a)
	{
		::Quaternion aQuat;

		ManagedToUnmanagedQuaternion(a, aQuat);

		Quaternion result;
		UnmanagedToManagedQuaternion(scl * aQuat, result);

		return result;
	}

	Quaternion Quaternion::operator*(Quaternion a, float scl)
	{
		::Quaternion aQuat;

		ManagedToUnmanagedQuaternion(a, aQuat);

		Quaternion result;
		UnmanagedToManagedQuaternion(aQuat * scl, result);

		return result;
	}

	Quaternion Quaternion::operator*(Quaternion a, Quaternion b)
	{
		::Quaternion aQuat;
		::Quaternion bQuat;

		ManagedToUnmanagedQuaternion(a, aQuat);
		ManagedToUnmanagedQuaternion(b, bQuat);

		Quaternion result;
		UnmanagedToManagedQuaternion(aQuat * bQuat, result);
		
		return result;
	}

	Quaternion Quaternion::operator/(Quaternion a, Quaternion b)
	{
		::Quaternion aQuat;
		::Quaternion bQuat;

		ManagedToUnmanagedQuaternion(a, aQuat);
		ManagedToUnmanagedQuaternion(b, bQuat);

		Quaternion result;
		UnmanagedToManagedQuaternion(aQuat / bQuat, result);

		return result;
	}

	Quaternion Quaternion::Inverse(Quaternion a)
	{
		::Quaternion aQuat;

		ManagedToUnmanagedQuaternion(a, aQuat);

		Quaternion result;
		UnmanagedToManagedQuaternion(aQuat, result);

		return result;
	}

	float Quaternion::I::get()
	{
		return X;
	}

	void Quaternion::I::set(float value)
	{
		X = value;
	}

	float Quaternion::J::get()
	{
		return Y;
	}

	void Quaternion::J::set(float value)
	{
		Y = value;
	}

	float Quaternion::K::get()
	{
		return Z;
	}

	void Quaternion::K::set(float value)
	{
		Z = value;
	}

	float Quaternion::T::get()
	{
		return W;
	}

	void Quaternion::T::set(float value)
	{
		W = value;
	}

	float Quaternion::default::get(int index)
	{
		if (index < 0 || index >= 4)
		{
			throw gcnew IndexOutOfRangeException("index");
		}

		::Quaternion tmp;
		ManagedToUnmanagedQuaternion(tmp);

		return tmp[index];
	}

	void Quaternion::default::set(int index, float value)
	{
		if (index < 0 || index >= 4)
		{
			throw gcnew IndexOutOfRangeException("index");
		}

		::Quaternion tmp;
		ManagedToUnmanagedQuaternion(tmp);

		tmp[index] = value;

		UnmanagedToManagedQuaternion(tmp);
	}

	bool Quaternion::IsValid::get()
	{
		::Quaternion tmp;
		ManagedToUnmanagedQuaternion(tmp);

		return tmp.Is_Valid();
	}

	Quaternion Quaternion::Identity::get()
	{
		Quaternion result;
		result.MakeIdentity();

		return result;
	}
}