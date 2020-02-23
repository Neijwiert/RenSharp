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
#include "Mobboxclass.h"

#include "MMatrix3D.h"

namespace RenSharp
{
	OBBoxClass::OBBoxClass(Vector3 center, Vector3 extent)
	{
		::Vector3 centerVec;
		::Vector3 extentVec;

		Vector3::ManagedToUnmanagedVector3(center, centerVec);
		Vector3::ManagedToUnmanagedVector3(extent, extentVec);

		::OBBoxClass thisBox(centerVec, extentVec);
		UnmanagedToManagedOBBoxClass(thisBox);
	}

	OBBoxClass::OBBoxClass(Vector3 center, Vector3 extent, Matrix3 basis)
	{
		::Vector3 centerVec;
		::Vector3 extentVec;
		::Matrix3 basisMat;

		Vector3::ManagedToUnmanagedVector3(center, centerVec);
		Vector3::ManagedToUnmanagedVector3(extent, extentVec);
		Matrix3::ManagedToUnmanagedMatrix3(basis, basisMat);

		::OBBoxClass thisBox(centerVec, extentVec, basisMat);
		UnmanagedToManagedOBBoxClass(thisBox);
	}

	OBBoxClass::OBBoxClass(Vector3 aabbCenter, Vector3 aabbExtent, Matrix3D transform)
	{
		::Vector3 centerVec;
		::Vector3 extentVec;
		::Matrix3D transformMat;

		Vector3::ManagedToUnmanagedVector3(aabbCenter, centerVec);
		Vector3::ManagedToUnmanagedVector3(aabbExtent, extentVec);
		Matrix3D::ManagedToUnmanagedMatrix3D(transform, transformMat);

		::OBBoxClass thisBox(centerVec, extentVec, transformMat);
		UnmanagedToManagedOBBoxClass(thisBox);
	}

	OBBoxClass::OBBoxClass(IntPtr pointer)
	{
		if (pointer == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		::OBBoxClass *tmpBox = reinterpret_cast<::OBBoxClass *>(pointer.ToPointer());

		Matrix3::UnmanagedToManagedMatrix3(tmpBox->Basis, Basis);
		Vector3::UnmanagedToManagedVector3(tmpBox->Center, Center);
		Vector3::UnmanagedToManagedVector3(tmpBox->Extent, Extent);
	}

	float OBBoxClass::ProjectToAxis(Vector3 axis)
	{
		::Vector3 axisVec;

		Vector3::ManagedToUnmanagedVector3(axis, axisVec);

		::OBBoxClass thisBox;
		ManagedToUnmanagedOBBoxClass(thisBox);

		return thisBox.Project_To_Axis(axisVec);
	}

	Vector3 OBBoxClass::ComputePoint(array<float> ^params)
	{
		if (params == nullptr)
		{
			throw gcnew ArgumentNullException("params");
		}
		else if (params->Length != 3)
		{
			throw gcnew ArgumentOutOfRangeException("params");
		}

		float tmpParams[3] =
		{
			params[0],
			params[1],
			params[2]
		};

		::OBBoxClass thisBox;
		ManagedToUnmanagedOBBoxClass(thisBox);

		::Vector3 tmp;
		thisBox.Compute_Point(tmpParams, &tmp);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	Vector3 OBBoxClass::ComputeAxisAlignedExtent()
	{
		::OBBoxClass thisBox;
		ManagedToUnmanagedOBBoxClass(thisBox);

		::Vector3 tmp;
		thisBox.Compute_Axis_Aligned_Extent(&tmp);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	float OBBoxClass::ComputeSquaredDistanceFromPoint(Vector3 point)
	{
		::Vector3 pointVec;

		Vector3::ManagedToUnmanagedVector3(point, pointVec);

		::OBBoxClass thisBox;
		ManagedToUnmanagedOBBoxClass(thisBox);

		return thisBox.ComputeSquaredDistanceFromPoint(pointVec);
	}

	OBBoxClass OBBoxClass::Transform(Matrix3D m, OBBoxClass in)
	{
		::Matrix3D mMat;
		::OBBoxClass inBox;

		Matrix3D::ManagedToUnmanagedMatrix3D(m, mMat);
		ManagedToUnmanagedOBBoxClass(in, inBox);

		::OBBoxClass tmp;
		::OBBoxClass::Transform(mMat, inBox, &tmp);

		OBBoxClass result;
		UnmanagedToManagedOBBoxClass(tmp, result);

		return result;
	}

	float OBBoxClass::Volume::get()
	{
		::OBBoxClass thisBox;
		ManagedToUnmanagedOBBoxClass(thisBox);

		return thisBox.Volume();
	}
}