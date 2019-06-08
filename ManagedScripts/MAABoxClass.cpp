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
#include "MAABoxClass.h"

#include "MLineSegClass.h"
#include "MMatrix3D.h"
#include "Imports.h"

namespace RenSharp
{
	AABoxClass::AABoxClass(Vector3 center, Vector3 extent)
	{
		::Vector3 centerVec;
		::Vector3 extentVec;

		Vector3::ManagedToUnmanagedVector3(center, centerVec);
		Vector3::ManagedToUnmanagedVector3(extent, extentVec);

		::AABoxClass thisBox(centerVec, extentVec);

		UnmanagedToManagedAABoxClass(thisBox);
	}

	AABoxClass::AABoxClass(MinMaxAABoxClass minMaxBox)
	{
		::MinMaxAABoxClass tmpBox;

		MinMaxAABoxClass::ManagedToUnmanagedMinMaxAABoxClass(minMaxBox, tmpBox);

		::AABoxClass thisBox(tmpBox);

		UnmanagedToManagedAABoxClass(thisBox);
	}

	AABoxClass::AABoxClass(array<Vector3> ^points)
	{
		if (points == nullptr)
		{
			throw gcnew ArgumentNullException("points");
		}

		::Vector3 *vecArray = Imports::CreateVector3Array(static_cast<std::size_t>(points->Length));
		try
		{
			::Vector3 pointsVec;
			for (int x = 0; x < points->Length; x++)
			{
				Vector3::ManagedToUnmanagedVector3(points[x], pointsVec);

				std::memcpy(&vecArray[x], &pointsVec, sizeof(::Vector3));
			}

			::AABoxClass thisBox(vecArray, points->Length);

			UnmanagedToManagedAABoxClass(thisBox);
		}
		finally
		{
			Imports::DestroyVector3Array(vecArray);
		}
	}

	AABoxClass::AABoxClass(IntPtr pointer)
	{
		if (pointer == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		::AABoxClass *tmpBox = reinterpret_cast<::AABoxClass *>(pointer.ToPointer());

		Vector3::UnmanagedToManagedVector3(tmpBox->Center, Center);
		Vector3::UnmanagedToManagedVector3(tmpBox->Extent, Extent);
	}

	void AABoxClass::Init(Vector3 center, Vector3 extent)
	{
		::Vector3 centerVec;
		::Vector3 extentVec;

		Vector3::ManagedToUnmanagedVector3(center, centerVec);
		Vector3::ManagedToUnmanagedVector3(extent, extentVec);

		::AABoxClass thisBox;
		ManagedToUnmanagedAABoxClass(thisBox);

		thisBox.Init(centerVec, extentVec);

		UnmanagedToManagedAABoxClass(thisBox);
	}

	void AABoxClass::Init(array<Vector3> ^points)
	{
		if (points == nullptr)
		{
			throw gcnew ArgumentNullException("points");
		}

		::Vector3 *vecArray = Imports::CreateVector3Array(static_cast<std::size_t>(points->Length));
		try
		{
			::Vector3 pointsVec;
			for (int x = 0; x < points->Length; x++)
			{
				Vector3::ManagedToUnmanagedVector3(points[x], pointsVec);

				std::memcpy(&vecArray[x], &pointsVec, sizeof(::Vector3));
			}

			::AABoxClass thisBox;
			ManagedToUnmanagedAABoxClass(thisBox);

			thisBox.Init(vecArray, points->Length);

			UnmanagedToManagedAABoxClass(thisBox);
		}
		finally
		{
			Imports::DestroyVector3Array(vecArray);
		}
	}

	void AABoxClass::Init(MinMaxAABoxClass minMaxBox)
	{
		::MinMaxAABoxClass tmpBox;

		MinMaxAABoxClass::ManagedToUnmanagedMinMaxAABoxClass(minMaxBox, tmpBox);

		::AABoxClass thisBox;
		ManagedToUnmanagedAABoxClass(thisBox);

		thisBox.Init(tmpBox);

		UnmanagedToManagedAABoxClass(thisBox);
	}

	void AABoxClass::Init(LineSegClass line)
	{
		::LineSegClass tmpLine;

		LineSegClass::ManagedToUnmanagedLineSegClass(line, tmpLine);

		::AABoxClass thisBox;
		ManagedToUnmanagedAABoxClass(thisBox);

		thisBox.Init(tmpLine);

		UnmanagedToManagedAABoxClass(thisBox);
	}

	void AABoxClass::InitMinMax(Vector3 min, Vector3 max)
	{
		::Vector3 minVec;
		::Vector3 maxVec;

		Vector3::ManagedToUnmanagedVector3(min, minVec);
		Vector3::ManagedToUnmanagedVector3(max, maxVec);

		::AABoxClass thisBox;
		ManagedToUnmanagedAABoxClass(thisBox);

		thisBox.Init_Min_Max(minVec, maxVec);

		UnmanagedToManagedAABoxClass(thisBox);
	}

	void AABoxClass::AddPoint(Vector3 point)
	{
		::Vector3 pointVec;

		Vector3::ManagedToUnmanagedVector3(point, pointVec);

		::AABoxClass thisBox;
		ManagedToUnmanagedAABoxClass(thisBox);

		thisBox.Add_Point(pointVec);

		UnmanagedToManagedAABoxClass(thisBox);
	}

	void AABoxClass::AddBox(AABoxClass b)
	{
		::AABoxClass bBox;

		ManagedToUnmanagedAABoxClass(b, bBox);

		::AABoxClass thisBox;
		ManagedToUnmanagedAABoxClass(thisBox);

		thisBox.Add_Box(bBox);

		UnmanagedToManagedAABoxClass(thisBox);
	}

	void AABoxClass::AddBox(MinMaxAABoxClass b)
	{
		::MinMaxAABoxClass bBox;

		MinMaxAABoxClass::ManagedToUnmanagedMinMaxAABoxClass(b, bBox);

		::AABoxClass thisBox;
		ManagedToUnmanagedAABoxClass(thisBox);

		thisBox.Add_Box(bBox);

		UnmanagedToManagedAABoxClass(thisBox);
	}

	float AABoxClass::ProjectToAxis(Vector3 axis)
	{
		::Vector3 axisVec;

		Vector3::ManagedToUnmanagedVector3(axis, axisVec);

		::AABoxClass thisBox;
		ManagedToUnmanagedAABoxClass(thisBox);

		return thisBox.Project_To_Axis(axisVec);
	}

	void AABoxClass::Transform(Matrix3D tm)
	{
		::Matrix3D tmMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(tm, tmMat);

		::AABoxClass thisBox;
		ManagedToUnmanagedAABoxClass(thisBox);

		thisBox.Transform(tmMat);

		UnmanagedToManagedAABoxClass(thisBox);
	}

	void AABoxClass::Translate(Vector3 pos)
	{
		::Vector3 posVec;

		Vector3::ManagedToUnmanagedVector3(pos, posVec);

		::AABoxClass thisBox;
		ManagedToUnmanagedAABoxClass(thisBox);

		thisBox.Translate(posVec);

		UnmanagedToManagedAABoxClass(thisBox);
	}

	bool AABoxClass::Contains(MinMaxAABoxClass otherBox)
	{
		::MinMaxAABoxClass tmpOther;

		MinMaxAABoxClass::ManagedToUnmanagedMinMaxAABoxClass(otherBox, tmpOther);

		::AABoxClass thisBox;
		ManagedToUnmanagedAABoxClass(thisBox);

		return thisBox.Contains(tmpOther);
	}

	float AABoxClass::ComputeSquaredDistanceFromPoint(Vector3 point)
	{
		::Vector3 pointVec;

		Vector3::ManagedToUnmanagedVector3(point, pointVec);

		::AABoxClass thisBox;
		ManagedToUnmanagedAABoxClass(thisBox);

		return thisBox.ComputeSquaredDistanceFromPoint(pointVec);
	}

	float AABoxClass::ComputeMaxSquaredDistanceFromPoint(Vector3 point)
	{
		::Vector3 pointVec;

		Vector3::ManagedToUnmanagedVector3(point, pointVec);

		::AABoxClass thisBox;
		ManagedToUnmanagedAABoxClass(thisBox);

		return thisBox.ComputeMaxSquaredDistanceFromPoint(pointVec);
	}

	AABoxClass AABoxClass::Transform(Matrix3D tm, AABoxClass in)
	{
		::Matrix3D tmMat;
		::AABoxClass inBox;

		Matrix3D::ManagedToUnmanagedMatrix3D(tm, tmMat);
		ManagedToUnmanagedAABoxClass(in, inBox);

		::AABoxClass tmp;
		::AABoxClass::Transform(tmMat, inBox, &tmp);

		AABoxClass result;
		UnmanagedToManagedAABoxClass(tmp, result);

		return result;
	}

	float AABoxClass::Volume::get()
	{
		::AABoxClass thisBox;
		ManagedToUnmanagedAABoxClass(thisBox);

		return thisBox.Volume();
	}

	MinMaxAABoxClass::MinMaxAABoxClass(Vector3 minCorner, Vector3 maxCorner)
	{
		::Vector3 minCornerVec;
		::Vector3 maxCornerVec;

		Vector3::ManagedToUnmanagedVector3(minCorner, minCornerVec);
		Vector3::ManagedToUnmanagedVector3(maxCorner, maxCornerVec);

		::MinMaxAABoxClass thisBox(minCornerVec, maxCornerVec);

		UnmanagedToManagedMinMaxAABoxClass(thisBox);
	}

	MinMaxAABoxClass::MinMaxAABoxClass(array<Vector3> ^points)
	{
		if (points == nullptr)
		{
			throw gcnew ArgumentNullException("points");
		}

		::Vector3 *vecArray = Imports::CreateVector3Array(static_cast<std::size_t>(points->Length));
		try
		{
			::Vector3 pointsVec;
			for (int x = 0; x < points->Length; x++)
			{
				Vector3::ManagedToUnmanagedVector3(points[x], pointsVec);

				std::memcpy(&vecArray[x], &pointsVec, sizeof(::Vector3));
			}

			::MinMaxAABoxClass thisBox(vecArray, points->Length);

			UnmanagedToManagedMinMaxAABoxClass(thisBox);
		}
		finally
		{
			Imports::DestroyVector3Array(vecArray);
		}
	}

	MinMaxAABoxClass::MinMaxAABoxClass(AABoxClass that)
	{
		::AABoxClass thatBox;

		AABoxClass::ManagedToUnmanagedAABoxClass(that, thatBox);

		::MinMaxAABoxClass thisBox(thatBox);

		UnmanagedToManagedMinMaxAABoxClass(thisBox);
	}

	MinMaxAABoxClass::MinMaxAABoxClass(IntPtr pointer)
	{
		if (pointer == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		::MinMaxAABoxClass *tmpBox = reinterpret_cast<::MinMaxAABoxClass *>(pointer.ToPointer());

		Vector3::UnmanagedToManagedVector3(tmpBox->MinCorner, MinCorner);
		Vector3::UnmanagedToManagedVector3(tmpBox->MaxCorner, MaxCorner);
	}

	void MinMaxAABoxClass::Init(array<Vector3> ^points)
	{
		if (points == nullptr)
		{
			throw gcnew ArgumentNullException("points");
		}

		::Vector3 *vecArray = Imports::CreateVector3Array(static_cast<std::size_t>(points->Length));
		try
		{
			::Vector3 pointsVec;
			for (int x = 0; x < points->Length; x++)
			{
				Vector3::ManagedToUnmanagedVector3(points[x], pointsVec);

				std::memcpy(&vecArray[x], &pointsVec, sizeof(::Vector3));
			}

			::MinMaxAABoxClass thisBox;
			ManagedToUnmanagedMinMaxAABoxClass(thisBox);

			thisBox.Init(vecArray, points->Length);

			UnmanagedToManagedMinMaxAABoxClass(thisBox);
		}
		finally
		{
			Imports::DestroyVector3Array(vecArray);
		}
	}

	void MinMaxAABoxClass::Init(AABoxClass box)
	{
		::AABoxClass bBox;

		AABoxClass::ManagedToUnmanagedAABoxClass(box, bBox);

		::MinMaxAABoxClass thisBox;
		ManagedToUnmanagedMinMaxAABoxClass(thisBox);

		thisBox.Init(bBox);

		UnmanagedToManagedMinMaxAABoxClass(thisBox);
	}

	void MinMaxAABoxClass::InitEmpty()
	{
		::MinMaxAABoxClass thisBox;
		ManagedToUnmanagedMinMaxAABoxClass(thisBox);

		thisBox.Init_Empty();

		UnmanagedToManagedMinMaxAABoxClass(thisBox);
	}

	void MinMaxAABoxClass::AddPoint(Vector3 point)
	{
		::Vector3 pointVec;

		Vector3::ManagedToUnmanagedVector3(point, pointVec);

		::MinMaxAABoxClass thisBox;
		ManagedToUnmanagedMinMaxAABoxClass(thisBox);

		thisBox.Add_Point(pointVec);

		UnmanagedToManagedMinMaxAABoxClass(thisBox);
	}

	void MinMaxAABoxClass::AddBox(MinMaxAABoxClass box)
	{
		::MinMaxAABoxClass bBox;

		ManagedToUnmanagedMinMaxAABoxClass(box, bBox);

		::MinMaxAABoxClass thisBox;
		ManagedToUnmanagedMinMaxAABoxClass(thisBox);

		thisBox.Add_Box(bBox);

		UnmanagedToManagedMinMaxAABoxClass(thisBox);
	}

	void MinMaxAABoxClass::AddBox(AABoxClass box)
	{
		::AABoxClass bBox;

		AABoxClass::ManagedToUnmanagedAABoxClass(box, bBox);

		::MinMaxAABoxClass thisBox;
		ManagedToUnmanagedMinMaxAABoxClass(thisBox);

		thisBox.Add_Box(bBox);

		UnmanagedToManagedMinMaxAABoxClass(thisBox);
	}

	void MinMaxAABoxClass::AddBox(Vector3 minCorner, Vector3 maxCorner)
	{
		::Vector3 minCornerVec;
		::Vector3 maxCornerVec;

		Vector3::ManagedToUnmanagedVector3(minCorner, minCornerVec);
		Vector3::ManagedToUnmanagedVector3(maxCorner, maxCornerVec);

		::MinMaxAABoxClass thisBox;
		ManagedToUnmanagedMinMaxAABoxClass(thisBox);

		thisBox.Add_Box(minCornerVec, maxCornerVec);

		UnmanagedToManagedMinMaxAABoxClass(thisBox);
	}

	void MinMaxAABoxClass::Transform(Matrix3D tm)
	{
		::Matrix3D tmMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(tm, tmMat);

		::MinMaxAABoxClass thisBox;
		ManagedToUnmanagedMinMaxAABoxClass(thisBox);

		thisBox.Transform(tmMat);

		UnmanagedToManagedMinMaxAABoxClass(thisBox);
	}

	void MinMaxAABoxClass::Translate(Vector3 pos)
	{
		::Vector3 posVec;

		Vector3::ManagedToUnmanagedVector3(pos, posVec);

		::MinMaxAABoxClass thisBox;
		ManagedToUnmanagedMinMaxAABoxClass(thisBox);

		thisBox.Translate(posVec);

		UnmanagedToManagedMinMaxAABoxClass(thisBox);
	}

	float MinMaxAABoxClass::Volume::get()
	{
		::MinMaxAABoxClass thisBox;
		ManagedToUnmanagedMinMaxAABoxClass(thisBox);

		return thisBox.Volume();
	}
}