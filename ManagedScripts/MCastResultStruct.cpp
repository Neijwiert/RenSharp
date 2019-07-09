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
#include "MCastResultStruct.h"

namespace RenSharp
{
	CastResultStruct::CastResultStruct(bool reset)
	{
		if (reset)
		{
			Reset();
		}
	}
	
	CastResultStruct::CastResultStruct(IntPtr pointer)
	{
		if (pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		auto otherThis = reinterpret_cast<::CastResultStruct *>(pointer.ToPointer());

		StartBad = otherThis->StartBad;
		Fraction = otherThis->Fraction;
		Vector3::UnmanagedToManagedVector3(otherThis->Normal, Normal);
		SurfaceType = otherThis->SurfaceType;
		ComputeContactPoint = otherThis->ComputeContactPoint;
		Vector3::UnmanagedToManagedVector3(otherThis->ContactPoint, ContactPoint);
	}

	void CastResultStruct::Reset()
	{
		::CastResultStruct thisStruct;

		ManagedToUnmanagedCastResultStruct(thisStruct);

		thisStruct.Reset();

		UnmanagedToManagedCastResultStruct(thisStruct);
	}
}