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
#include "MVector3i.h"

namespace RenSharp
{
	Vector3i::Vector3i(int i, int j, int k)
	{
		::Vector3i thisVec(i, j, k);

		UnmanagedToManagedVector3i(thisVec);
	}

	Vector3i::Vector3i(IntPtr pointer)
	{
		if (pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		UnmanagedToManagedVector3i(
			*reinterpret_cast<::Vector3i*>(pointer.ToPointer()));
	}

	int Vector3i::default::get(int index)
	{
		if (index < 0 || index >= 3)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		::Vector3i thisVec;

		ManagedToUnmanagedVector3i(thisVec);

		return thisVec[index];
	}

	void Vector3i::default::set(int index, int value)
	{
		if (index < 0 || index >= 3)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		::Vector3i thisVec;

		ManagedToUnmanagedVector3i(thisVec);

		thisVec[index] = value;

		UnmanagedToManagedVector3i(thisVec);
	}

	Vector3i16::Vector3i16(unsigned short i, unsigned short j, unsigned short k)
	{
		::Vector3i16 thisVec(i, j, k);

		UnmanagedToManagedVector3i16(thisVec);
	}

	Vector3i16::Vector3i16(IntPtr pointer)
	{
		if (pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		UnmanagedToManagedVector3i16(
			*reinterpret_cast<::Vector3i16*>(pointer.ToPointer()));
	}

	unsigned short Vector3i16::default::get(int index)
	{
		if (index < 0 || index >= 3)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		::Vector3i16 thisVec;

		ManagedToUnmanagedVector3i16(thisVec);

		return thisVec[index];
	}

	void Vector3i16::default::set(int index, unsigned short value)
	{
		if (index < 0 || index >= 3)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		::Vector3i16 thisVec;

		ManagedToUnmanagedVector3i16(thisVec);

		thisVec[index] = value;

		UnmanagedToManagedVector3i16(thisVec);
	}
}