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

#pragma once

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <LineSegClass.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MVector3.h"

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace RenSharp
{
	value class Matrix3D;

#pragma managed(push, off)

	struct LineSegClassHelper
	{
		::Vector3 P0;
		::Vector3 P1;
		::Vector3 DP;
		::Vector3 Dir;
		float Length;
	};

#pragma managed(pop)

	[StructLayout(LayoutKind::Sequential)]
	public value class LineSegClass
	{
		protected:
			Vector3 _P0;
			Vector3 _P1;
			Vector3 _DP;
			Vector3 _Dir;
			float _Length;

		public:
			LineSegClass(Vector3 p0, Vector3 p1);
			LineSegClass(Vector3 p0, Vector3 dir, float length);
			LineSegClass(LineSegClass that, Matrix3D tm);
			LineSegClass(IntPtr pointer);

			void Set(Vector3 p0, Vector3 p1);
			void Set(Vector3 p0, Vector3 dir, float length);
			void Set(LineSegClass that, Matrix3D tm);
			Vector3 ComputePoint(float t);
			Vector3 FindPointClosestTo(Vector3 pos);
			bool FindIntersection(LineSegClass otherLine, Vector3 %p1, float %fraction1, Vector3 %p2, float %fraction2);

			property Vector3 P0
			{
				Vector3 get();
			}

			property Vector3 P1
			{
				Vector3 get();
			}

			property Vector3 DP
			{
				Vector3 get();
			}

			property Vector3 Dir
			{
				Vector3 get();
			}

			property float Length
			{
				float get();
			}

		internal:
			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void ManagedToUnmanagedLineSegClass(LineSegClass %managed, ::LineSegClass &result)
			{
				auto helper = reinterpret_cast<LineSegClassHelper *>(&result);

				Vector3::ManagedToUnmanagedVector3(managed._P0, helper->P0);
				Vector3::ManagedToUnmanagedVector3(managed._P1, helper->P1);
				Vector3::ManagedToUnmanagedVector3(managed._DP, helper->DP);
				Vector3::ManagedToUnmanagedVector3(managed._Dir, helper->Dir);
				helper->Length = managed._Length;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void UnmanagedToManagedLineSegClass(const ::LineSegClass &unmanaged, LineSegClass %result)
			{
				Vector3::UnmanagedToManagedVector3(unmanaged.Get_P0(), result._P0);
				Vector3::UnmanagedToManagedVector3(unmanaged.Get_P1(), result._P1);
				Vector3::UnmanagedToManagedVector3(unmanaged.Get_DP(), result._DP);
				Vector3::UnmanagedToManagedVector3(unmanaged.Get_Dir(), result._Dir);
				result._Length = unmanaged.Get_Length();
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void ManagedToUnmanagedLineSegClass(::LineSegClass &result)
			{
				auto helper = reinterpret_cast<LineSegClassHelper *>(&result);

				Vector3::ManagedToUnmanagedVector3(_P0, helper->P0);
				Vector3::ManagedToUnmanagedVector3(_P1, helper->P1);
				Vector3::ManagedToUnmanagedVector3(_DP, helper->DP);
				Vector3::ManagedToUnmanagedVector3(_Dir, helper->Dir);
				helper->Length = _Length;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void UnmanagedToManagedLineSegClass(const ::LineSegClass &unmanaged)
			{
				Vector3::UnmanagedToManagedVector3(unmanaged.Get_P0(), _P0);
				Vector3::UnmanagedToManagedVector3(unmanaged.Get_P1(), _P1);
				Vector3::UnmanagedToManagedVector3(unmanaged.Get_DP(), _DP);
				Vector3::UnmanagedToManagedVector3(unmanaged.Get_Dir(), _Dir);
				_Length = unmanaged.Get_Length();
			}

		protected:
			void Recalculate();
	};
}