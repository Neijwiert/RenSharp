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
#include "Mrect.h"

#include "Mvector2.h"

namespace RenSharp
{
	RectClass::RectClass(Vector2 topLeft, Vector2 bottomRight)
	{
		::Vector2 topLeftVec;
		::Vector2 bottomRightVec;

		Vector2::ManagedToUnmanagedVector2(topLeft, topLeftVec);
		Vector2::ManagedToUnmanagedVector2(bottomRight, bottomRightVec);

		::RectClass thisRect(topLeftVec, bottomRightVec);

		UnmanagedToManagedRectClass(thisRect);
	}

	RectClass::RectClass(float newLeft, float newTop, float newRight, float newBottom)
	{
		::RectClass thisRect(newLeft, newTop, newRight, newBottom);

		UnmanagedToManagedRectClass(thisRect);
	}

	RectClass::RectClass(IntPtr pointer)
	{
		if (pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		::RectClass *thisRect = reinterpret_cast<::RectClass *>(pointer.ToPointer());

		Left = thisRect->Left;
		Top = thisRect->Top;
		Right = thisRect->Right;
		Bottom = thisRect->Bottom;
	}

	void RectClass::Set(float left, float top, float right, float bottom)
	{
		::RectClass thisRect;
		ManagedToUnmanagedRectClass(thisRect);

		thisRect.Set(left, top, right, bottom);

		UnmanagedToManagedRectClass(thisRect);
	}

	void RectClass::Set(Vector2 topLeft, Vector2 bottomRight)
	{
		::Vector2 topLeftVec;
		::Vector2 bottomRightVec;

		Vector2::ManagedToUnmanagedVector2(topLeft, topLeftVec);
		Vector2::ManagedToUnmanagedVector2(bottomRight, bottomRightVec);

		::RectClass thisRect;
		ManagedToUnmanagedRectClass(thisRect);

		thisRect.Set(topLeftVec, bottomRightVec);

		UnmanagedToManagedRectClass(thisRect);
	}

	void RectClass::Set(RectClass r)
	{
		::RectClass rRect;

		ManagedToUnmanagedRectClass(r, rRect);

		::RectClass thisRect;
		ManagedToUnmanagedRectClass(thisRect);

		thisRect.Set(rRect);

		UnmanagedToManagedRectClass(thisRect);
	}

	RectClass RectClass::ScaleRelativeCenter(float k)
	{
		::RectClass thisRect;
		ManagedToUnmanagedRectClass(thisRect);

		thisRect.Scale_Relative_Center(k);

		UnmanagedToManagedRectClass(thisRect);

		return *this;
	}

	RectClass RectClass::Scale(float k)
	{
		::RectClass thisRect;
		ManagedToUnmanagedRectClass(thisRect);

		thisRect.Scale(k);

		UnmanagedToManagedRectClass(thisRect);

		return *this;
	}

	RectClass RectClass::InverseScale(Vector2 k)
	{
		::Vector2 kVec;

		Vector2::ManagedToUnmanagedVector2(k, kVec);

		::RectClass thisRect;
		ManagedToUnmanagedRectClass(thisRect);

		thisRect.Inverse_Scale(kVec);

		UnmanagedToManagedRectClass(thisRect);

		return *this;
	}

	void RectClass::Inflate(Vector2 o)
	{
		::Vector2 oVec;

		Vector2::ManagedToUnmanagedVector2(o, oVec);

		::RectClass thisRect;
		ManagedToUnmanagedRectClass(thisRect);

		thisRect.Inflate(oVec);

		UnmanagedToManagedRectClass(thisRect);
	}

	bool RectClass::Contains(Vector2 pos)
	{
		::Vector2 posVec;

		Vector2::ManagedToUnmanagedVector2(pos, posVec);

		::RectClass thisRect;
		ManagedToUnmanagedRectClass(thisRect);

		return thisRect.Contains(posVec);
	}

	void RectClass::SnapToUnits(Vector2 u)
	{
		::Vector2 uVec;

		Vector2::ManagedToUnmanagedVector2(u, uVec);

		::RectClass thisRect;
		ManagedToUnmanagedRectClass(thisRect);

		thisRect.Snap_To_Units(uVec);

		UnmanagedToManagedRectClass(thisRect);
	}

	RectClass RectClass::operator*(RectClass r, float k)
	{
		::RectClass rRect;

		ManagedToUnmanagedRectClass(r, rRect);

		rRect *= k;

		RectClass result;
		UnmanagedToManagedRectClass(rRect, result);

		return result;
	}

	RectClass RectClass::operator/(RectClass r, float k)
	{
		::RectClass rRect;

		ManagedToUnmanagedRectClass(r, rRect);

		rRect /= k;

		RectClass result;
		UnmanagedToManagedRectClass(rRect, result);

		return result;
	}

	RectClass RectClass::operator+(RectClass r, Vector2 o)
	{
		::RectClass rRect;
		::Vector2 oVec;

		ManagedToUnmanagedRectClass(r, rRect);
		Vector2::ManagedToUnmanagedVector2(o, oVec);

		rRect += oVec;

		RectClass result;
		UnmanagedToManagedRectClass(rRect, result);

		return result;
	}

	RectClass RectClass::operator-(RectClass r, Vector2 o)
	{
		::RectClass rRect;
		::Vector2 oVec;

		ManagedToUnmanagedRectClass(r, rRect);
		Vector2::ManagedToUnmanagedVector2(o, oVec);

		rRect -= oVec;

		RectClass result;
		UnmanagedToManagedRectClass(rRect, result);

		return result;
	}

	RectClass RectClass::operator+(RectClass a, RectClass b)
	{
		::RectClass aRect;
		::RectClass bRect;

		ManagedToUnmanagedRectClass(a, aRect);
		ManagedToUnmanagedRectClass(b, bRect);

		aRect += bRect;

		RectClass result;
		UnmanagedToManagedRectClass(aRect, result);

		return result;
	}

	Vector2 RectClass::UpperRight::get()
	{
		::RectClass thisRect;
		ManagedToUnmanagedRectClass(thisRect);

		Vector2 result;
		Vector2::UnmanagedToManagedVector2(thisRect.Upper_Right(), result);

		return result;
	}

	Vector2 RectClass::LowerLeft::get()
	{
		::RectClass thisRect;
		ManagedToUnmanagedRectClass(thisRect);

		Vector2 result;
		Vector2::UnmanagedToManagedVector2(thisRect.Lower_Left(), result);

		return result;
	}

	float RectClass::Width::get()
	{
		::RectClass thisRect;
		ManagedToUnmanagedRectClass(thisRect);

		return thisRect.Width();
	}

	float RectClass::Height::get()
	{
		::RectClass thisRect;
		ManagedToUnmanagedRectClass(thisRect);

		return thisRect.Height();
	}

	Vector2 RectClass::Center::get()
	{
		::RectClass thisRect;
		ManagedToUnmanagedRectClass(thisRect);

		Vector2 result;
		Vector2::UnmanagedToManagedVector2(thisRect.Center(), result);

		return result;
	}

	Vector2 RectClass::Extent::get()
	{
		::RectClass thisRect;
		ManagedToUnmanagedRectClass(thisRect);

		Vector2 result;
		Vector2::UnmanagedToManagedVector2(thisRect.Extent(), result);

		return result;
	}

	Vector2 RectClass::UpperLeft::get()
	{
		::RectClass thisRect;
		ManagedToUnmanagedRectClass(thisRect);

		Vector2 result;
		Vector2::UnmanagedToManagedVector2(thisRect.Upper_Left(), result);

		return result;
	}

	Vector2 RectClass::LowerRight::get()
	{
		::RectClass thisRect;
		ManagedToUnmanagedRectClass(thisRect);

		Vector2 result;
		Vector2::UnmanagedToManagedVector2(thisRect.Lower_Right(), result);

		return result;
	}

	Vector2 RectClass::Size::get()
	{
		::RectClass thisRect;
		ManagedToUnmanagedRectClass(thisRect);

		Vector2 result;
		Vector2::UnmanagedToManagedVector2(thisRect.getSize(), result);

		return result;
	}
}