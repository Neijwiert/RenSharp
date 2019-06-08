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
#include "MAAPlaneClass.h"

#include "MVector3.h"

namespace RenSharp
{
	AAPlaneClass::AAPlaneClass(AxisEnum normal, float dist)
	{
		::AAPlaneClass thisPlane(
			static_cast<::AAPlaneClass::AxisEnum>(normal),
			dist);

		UnmanagedToManagedAAPlaneClass(thisPlane);
	}

	AAPlaneClass::AAPlaneClass(IntPtr pointer)
	{
		if (pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		::AAPlaneClass* planePtr = reinterpret_cast<::AAPlaneClass*>(pointer.ToPointer());

		UnmanagedToManagedAAPlaneClass(*planePtr);
	}

	void AAPlaneClass::Set(AxisEnum normal, float dist)
	{
		::AAPlaneClass thisPlane;

		ManagedToUnmanagedAAPlaneClass(thisPlane);

		thisPlane.Set(
			static_cast<::AAPlaneClass::AxisEnum>(normal),
			dist);

		UnmanagedToManagedAAPlaneClass(thisPlane);
	}

	bool AAPlaneClass::InFront(Vector3 point)
	{
		::Vector3 pointVec;
		::AAPlaneClass thisPlane;

		ManagedToUnmanagedAAPlaneClass(thisPlane);
		Vector3::ManagedToUnmanagedVector3(point, pointVec);

		return thisPlane.In_Front(pointVec);
	}

	Vector3 AAPlaneClass::VectorNormal::get()
	{
		::AAPlaneClass thisPlane;

		ManagedToUnmanagedAAPlaneClass(thisPlane);

		::Vector3 tmp;

		thisPlane.Get_Normal(&tmp);

		Vector3 result;

		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}
}