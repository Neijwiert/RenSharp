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
#include "MLineSegClass.h"

#include "MMatrix3D.h"
#include "Imports.h"

namespace RenSharp
{
	LineSegClass::LineSegClass(Vector3 p0, Vector3 p1)
	{
		::Vector3 p0Vec;
		::Vector3 p1Vec;
		
		Vector3::ManagedToUnmanagedVector3(p0, p0Vec);
		Vector3::ManagedToUnmanagedVector3(p1, p1Vec);

		::LineSegClass thisLine;
		Imports::CreateLineSegClass(&thisLine, &p0Vec, &p1Vec);

		UnmanagedToManagedLineSegClass(thisLine);
	}

	LineSegClass::LineSegClass(Vector3 p0, Vector3 dir, float length)
	{
		::Vector3 p0Vec;
		::Vector3 dirVec;

		Vector3::ManagedToUnmanagedVector3(p0, p0Vec);
		Vector3::ManagedToUnmanagedVector3(dir, dirVec);

		::LineSegClass thisLine(p0Vec, dirVec, length);

		UnmanagedToManagedLineSegClass(thisLine);
	}

	LineSegClass::LineSegClass(LineSegClass that, Matrix3D tm)
	{
		::LineSegClass thatLine;
		::Matrix3D tmMat;

		ManagedToUnmanagedLineSegClass(that, thatLine);
		Matrix3D::ManagedToUnmanagedMatrix3D(tm, tmMat);

		::LineSegClass thisLine(thatLine, tmMat);

		UnmanagedToManagedLineSegClass(thisLine);
	}

	LineSegClass::LineSegClass(IntPtr pointer)
	{
		if (pointer == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		::LineSegClass *tmpLine = reinterpret_cast<::LineSegClass *>(pointer.ToPointer());

		Vector3::UnmanagedToManagedVector3(tmpLine->Get_P0(), _P0);
		Vector3::UnmanagedToManagedVector3(tmpLine->Get_P1(), _P1);
		Vector3::UnmanagedToManagedVector3(tmpLine->Get_DP(), _DP);
		Vector3::UnmanagedToManagedVector3(tmpLine->Get_Dir(), _Dir);
		_Length = tmpLine->Get_Length();
	}

	void LineSegClass::Set(Vector3 p0, Vector3 p1)
	{
		::Vector3 p0Vec;
		::Vector3 p1Vec;

		Vector3::ManagedToUnmanagedVector3(p0, p0Vec);
		Vector3::ManagedToUnmanagedVector3(p1, p1Vec);

		::LineSegClass thisLine;
		ManagedToUnmanagedLineSegClass(thisLine);

		Imports::LineSegClassSet(&thisLine, &p0Vec, &p1Vec);

		UnmanagedToManagedLineSegClass(thisLine);
	}

	void LineSegClass::Set(Vector3 p0, Vector3 dir, float length)
	{
		::Vector3 p0Vec;
		::Vector3 dirVec;

		Vector3::ManagedToUnmanagedVector3(p0, p0Vec);
		Vector3::ManagedToUnmanagedVector3(dir, dirVec);

		::LineSegClass thisLine;
		ManagedToUnmanagedLineSegClass(thisLine);

		thisLine.Set(p0Vec, dirVec, length);

		UnmanagedToManagedLineSegClass(thisLine);
	}

	void LineSegClass::Set(LineSegClass that, Matrix3D tm)
	{
		::LineSegClass thatLine;
		::Matrix3D tmMat;

		ManagedToUnmanagedLineSegClass(that, thatLine);
		Matrix3D::ManagedToUnmanagedMatrix3D(tm, tmMat);

		::LineSegClass thisLine;
		ManagedToUnmanagedLineSegClass(thisLine);

		thisLine.Set(thatLine, tmMat);

		UnmanagedToManagedLineSegClass(thisLine);
	}

	Vector3 LineSegClass::ComputePoint(float t)
	{
		::LineSegClass thisLine;
		ManagedToUnmanagedLineSegClass(thisLine);

		::Vector3 tmp;
		thisLine.Compute_Point(t, &tmp);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	Vector3 LineSegClass::FindPointClosestTo(Vector3 pos)
	{
		::Vector3 posVec;

		Vector3::ManagedToUnmanagedVector3(pos, posVec);

		::LineSegClass thisLine;
		ManagedToUnmanagedLineSegClass(thisLine);

		::Vector3 tmp = thisLine.Find_Point_Closest_To(posVec);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	bool LineSegClass::FindIntersection(LineSegClass otherLine, Vector3 %p1, float %fraction1, Vector3 %p2, float %fraction2)
	{
		::LineSegClass otherLineLine;
		::Vector3 p1Vec;
		float tmpFraction1;
		::Vector3 p2Vec;
		float tmpFraction2;

		ManagedToUnmanagedLineSegClass(otherLine, otherLineLine);

		::LineSegClass thisLine;
		ManagedToUnmanagedLineSegClass(thisLine);

		bool result = thisLine.Find_Intersection(otherLineLine, &p1Vec, &tmpFraction1, &p2Vec, &tmpFraction2);

		Vector3::UnmanagedToManagedVector3(p1Vec, p1);
		fraction1 = tmpFraction1;
		Vector3::UnmanagedToManagedVector3(p2Vec, p2);
		fraction2 = tmpFraction2;

		return result;
	}

	Vector3 LineSegClass::P0::get()
	{
		::LineSegClass thisLine;
		ManagedToUnmanagedLineSegClass(thisLine);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(thisLine.Get_P0(), result);

		return result;
	}

	Vector3 LineSegClass::P1::get()
	{
		::LineSegClass thisLine;
		ManagedToUnmanagedLineSegClass(thisLine);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(thisLine.Get_P1(), result);

		return result;
	}

	Vector3 LineSegClass::DP::get()
	{
		::LineSegClass thisLine;
		ManagedToUnmanagedLineSegClass(thisLine);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(thisLine.Get_DP(), result);

		return result;
	}

	Vector3 LineSegClass::Dir::get()
	{
		::LineSegClass thisLine;
		ManagedToUnmanagedLineSegClass(thisLine);

		Vector3 result;
		Vector3::UnmanagedToManagedVector3(thisLine.Get_Dir(), result);

		return result;
	}

	float LineSegClass::Length::get()
	{
		::LineSegClass thisLine;
		ManagedToUnmanagedLineSegClass(thisLine);

		return thisLine.Get_Length();
	}

	void LineSegClass::Recalculate()
	{
		::LineSegClass thisLine;
		ManagedToUnmanagedLineSegClass(thisLine);

		Imports::LineSegClassRecalculate(&thisLine);

		UnmanagedToManagedLineSegClass(thisLine);
	}
}