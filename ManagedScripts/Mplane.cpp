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
#include "Mplane.h"

#include "MSphereClass.h"
#include "Imports.h"

namespace RenSharp
{
	PlaneClass::PlaneClass(float nX, float nY, float nZ, float dist)
	{
		::PlaneClass thisPlane(nX, nY, nZ, dist);
		UnmanagedToManagedPlaneClass(thisPlane);
	}

	PlaneClass::PlaneClass(Vector3 normal, float dist)
	{
		::Vector3 normalVec;

		Vector3::ManagedToUnmanagedVector3(normal, normalVec);

		::PlaneClass thisPlane(normalVec, dist);

		UnmanagedToManagedPlaneClass(thisPlane);
	}

	PlaneClass::PlaneClass(Vector3 normal, Vector3 point)
	{
		::Vector3 normalVec;
		::Vector3 pointVec;

		Vector3::ManagedToUnmanagedVector3(normal, normalVec);
		Vector3::ManagedToUnmanagedVector3(point, pointVec);

		::PlaneClass thisPlane(normalVec, pointVec);

		UnmanagedToManagedPlaneClass(thisPlane);
	}

	PlaneClass::PlaneClass(Vector3 point1, Vector3 point2, Vector3 point3)
	{
		::Vector3 p1;
		::Vector3 p2;
		::Vector3 p3;

		Vector3::ManagedToUnmanagedVector3(point1, p1);
		Vector3::ManagedToUnmanagedVector3(point2, p2);
		Vector3::ManagedToUnmanagedVector3(point3, p3);

		::PlaneClass thisPlane;

		// This constructor references a __fastcall function
		Imports::CreatePlaneClass(&thisPlane, &p1, &p2, &p3);

		UnmanagedToManagedPlaneClass(thisPlane);
	}

	PlaneClass::PlaneClass(IntPtr pointer)
	{
		if (pointer == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		::PlaneClass *tmpPlane = reinterpret_cast<::PlaneClass *>(pointer.ToPointer());

		N.X = tmpPlane->N.X;
		N.Y = tmpPlane->N.Y;
		N.Z = tmpPlane->N.Z;
		D = tmpPlane->D;
	}

	void PlaneClass::Set(float a, float b, float c, float d)
	{
		::PlaneClass thisPlane;
		ManagedToUnmanagedPlaneClass(thisPlane);

		thisPlane.Set(a, b, c, d);

		UnmanagedToManagedPlaneClass(thisPlane);
	}

	void PlaneClass::Set(Vector3 normal, float dist)
	{
		::Vector3 normalVec;

		Vector3::ManagedToUnmanagedVector3(normal, normalVec);

		::PlaneClass thisPlane;
		ManagedToUnmanagedPlaneClass(thisPlane);

		thisPlane.Set(normalVec, dist);

		UnmanagedToManagedPlaneClass(thisPlane);
	}

	void PlaneClass::Set(Vector3 normal, Vector3 point)
	{
		::Vector3 normalVec;
		::Vector3 pointVec;

		Vector3::ManagedToUnmanagedVector3(normal, normalVec);
		Vector3::ManagedToUnmanagedVector3(point, pointVec);

		::PlaneClass thisPlane;
		ManagedToUnmanagedPlaneClass(thisPlane);

		thisPlane.Set(normalVec, pointVec);

		UnmanagedToManagedPlaneClass(thisPlane);
	}

	void PlaneClass::Set(Vector3 point1, Vector3 point2, Vector3 point3)
	{
		::Vector3 p1;
		::Vector3 p2;
		::Vector3 p3;

		Vector3::ManagedToUnmanagedVector3(point1, p1);
		Vector3::ManagedToUnmanagedVector3(point2, p2);
		Vector3::ManagedToUnmanagedVector3(point3, p3);

		::PlaneClass thisPlane;
		ManagedToUnmanagedPlaneClass(thisPlane);

		// PlaneClass::Set references a __fastcall function
		Imports::PlaneClassSet(&thisPlane, &p1, &p2, &p3);

		UnmanagedToManagedPlaneClass(thisPlane);
	}

	void PlaneClass::Normalize()
	{
		::PlaneClass thisPlane;
		ManagedToUnmanagedPlaneClass(thisPlane);

		thisPlane.Normalize();

		UnmanagedToManagedPlaneClass(thisPlane);
	}

	bool PlaneClass::InFront(Vector3 point)
	{
		::Vector3 pointVec;

		Vector3::ManagedToUnmanagedVector3(point, pointVec);

		::PlaneClass thisPlane;
		ManagedToUnmanagedPlaneClass(thisPlane);

		return thisPlane.In_Front(pointVec);
	}

	bool PlaneClass::InFront(SphereClass sphere)
	{
		::SphereClass pSphere;

		SphereClass::ManagedToUnmanagedSphereClass(sphere, pSphere);

		::PlaneClass thisPlane;
		ManagedToUnmanagedPlaneClass(thisPlane);

		return thisPlane.In_Front(pSphere);
	}

	bool PlaneClass::ComputeIntersection(Vector3 p0, Vector3 p1, float %setT)
	{
		::Vector3 p0Vec;
		::Vector3 p1Vec;

		Vector3::ManagedToUnmanagedVector3(p0, p0Vec);
		Vector3::ManagedToUnmanagedVector3(p1, p1Vec);

		::PlaneClass thisPlane;
		ManagedToUnmanagedPlaneClass(thisPlane);

		float setResult = 0;
		bool result = thisPlane.Compute_Intersection(p0Vec, p1Vec, &setResult);

		setT = setResult;

		return result;
	}

	PlaneClass PlaneClass::operator-(PlaneClass p)
	{
		::PlaneClass pPlane;

		ManagedToUnmanagedPlaneClass(p, pPlane);

		::PlaneClass tmp = -pPlane;

		PlaneClass result;
		UnmanagedToManagedPlaneClass(tmp, result);

		return result;
	}
}