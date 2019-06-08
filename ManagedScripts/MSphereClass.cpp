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
#include "MSphereClass.h"

#include "MMatrix3D.h"
#include "Imports.h"

namespace RenSharp
{
	SphereClass::SphereClass(Vector3 center, float radius)
	{
		::Vector3 centerVec;

		Vector3::ManagedToUnmanagedVector3(center, centerVec);

		::SphereClass thisSphere(centerVec, radius);
		UnmanagedToManagedSphereClass(thisSphere);
	}

	SphereClass::SphereClass(Vector3 center, SphereClass s0)
	{
		::Vector3 centerVec;
		::SphereClass s0Sphere;

		Vector3::ManagedToUnmanagedVector3(center, centerVec);
		ManagedToUnmanagedSphereClass(s0, s0Sphere);

		::SphereClass thisSphere(centerVec, s0Sphere);
		UnmanagedToManagedSphereClass(thisSphere);
	}

	SphereClass::SphereClass(array<Vector3> ^positions)
	{
		if (positions == nullptr)
		{
			throw gcnew ArgumentNullException("positions");
		}

		::Vector3 *vecArray = Imports::CreateVector3Array(static_cast<std::size_t>(positions->Length));
		try
		{
			::Vector3 positionVec;
			for (int x = 0; x < positions->Length; x++)
			{
				Vector3::ManagedToUnmanagedVector3(positions[x], positionVec);

				std::memcpy(&vecArray[x], &positionVec, sizeof(::Vector3));
			}

			::SphereClass thisSphere(vecArray, positions->Length);
			UnmanagedToManagedSphereClass(thisSphere);
		}
		finally
		{
			Imports::DestroyVector3Array(vecArray);
		}
	}

	SphereClass::SphereClass(IntPtr pointer)
	{
		if (pointer == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		::SphereClass *tmpSphere = reinterpret_cast<::SphereClass *>(pointer.ToPointer());

		Center.X = tmpSphere->Center.X;
		Center.Y = tmpSphere->Center.Y;
		Center.Z = tmpSphere->Center.Z;
		Radius = tmpSphere->Radius;
	}

	void SphereClass::Init(Vector3 pos, float radius)
	{
		::Vector3 posVec;

		Vector3::ManagedToUnmanagedVector3(pos, posVec);

		::SphereClass thisSphere;
		ManagedToUnmanagedSphereClass(thisSphere);

		thisSphere.Init(posVec, radius);

		UnmanagedToManagedSphereClass(thisSphere);
	}

	void SphereClass::ReCenter(Vector3 center)
	{
		::Vector3 centerVec;

		Vector3::ManagedToUnmanagedVector3(center, centerVec);

		::SphereClass thisSphere;
		ManagedToUnmanagedSphereClass(thisSphere);

		thisSphere.Re_Center(centerVec);

		UnmanagedToManagedSphereClass(thisSphere);
	}

	void SphereClass::AddSphere(SphereClass s)
	{
		::SphereClass sSphere;

		SphereClass::ManagedToUnmanagedSphereClass(s, sSphere);

		::SphereClass thisSphere;
		ManagedToUnmanagedSphereClass(thisSphere);

		thisSphere.Add_Sphere(sSphere);

		UnmanagedToManagedSphereClass(thisSphere);
	}

	void SphereClass::Transform(Matrix3D m)
	{
		::Matrix3D mMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(m, mMat);

		::SphereClass thisSphere;
		ManagedToUnmanagedSphereClass(thisSphere);

		thisSphere.Transform(mMat);

		UnmanagedToManagedSphereClass(thisSphere);
	}

	SphereClass SphereClass::operator+(SphereClass s0, SphereClass s1)
	{
		::SphereClass s0Sphere;
		::SphereClass s1Sphere;

		ManagedToUnmanagedSphereClass(s0, s0Sphere);
		ManagedToUnmanagedSphereClass(s1, s1Sphere);

		::SphereClass tmp = s0Sphere + s1Sphere;

		SphereClass result;
		UnmanagedToManagedSphereClass(tmp, result);

		return result;
	}

	SphereClass SphereClass::operator*(Matrix3D mat, SphereClass s0)
	{
		::Matrix3D mMat;
		::SphereClass s0Sphere;

		Matrix3D::ManagedToUnmanagedMatrix3D(mat, mMat);
		ManagedToUnmanagedSphereClass(s0, s0Sphere);

		::SphereClass tmp = mMat * s0Sphere;

		SphereClass result;
		UnmanagedToManagedSphereClass(tmp, result);

		return result;
	}

	bool SphereClass::SpheresIntersect(SphereClass s0, SphereClass s1)
	{
		::SphereClass s0Sphere;
		::SphereClass s1Sphere;

		ManagedToUnmanagedSphereClass(s0, s0Sphere);
		ManagedToUnmanagedSphereClass(s1, s1Sphere);

		return ::Spheres_Intersect(s0Sphere, s1Sphere);
	}

	SphereClass SphereClass::AddSpheres(SphereClass s0, SphereClass s1)
	{
		::SphereClass s0Sphere;
		::SphereClass s1Sphere;

		ManagedToUnmanagedSphereClass(s0, s0Sphere);
		ManagedToUnmanagedSphereClass(s1, s1Sphere);

		::SphereClass tmp = ::Add_Spheres(s0Sphere, s1Sphere);

		SphereClass result;
		UnmanagedToManagedSphereClass(tmp, result);

		return result;
	}

	SphereClass SphereClass::TransformSphere(Matrix3D mat, SphereClass s0)
	{
		::Matrix3D mMat;
		::SphereClass s0Sphere;

		Matrix3D::ManagedToUnmanagedMatrix3D(mat, mMat);
		ManagedToUnmanagedSphereClass(s0, s0Sphere);

		::SphereClass tmp = ::Transform_Sphere(mMat, s0Sphere);

		SphereClass result;
		UnmanagedToManagedSphereClass(tmp, result);

		return result;
	}

	float SphereClass::Volume::get()
	{
		::SphereClass thisSphere;
		ManagedToUnmanagedSphereClass(thisSphere);

		return thisSphere.Volume();
	}
}