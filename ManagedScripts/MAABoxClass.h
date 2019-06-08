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

#pragma once

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <AABoxClass.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MVector3.h"

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace RenSharp
{
	value class MinMaxAABoxClass;
	value class LineSegClass;
	value class Matrix3D;

	[StructLayout(LayoutKind::Sequential)]
	public value class AABoxClass
	{
		public:
			Vector3 Center;
			Vector3 Extent;

			AABoxClass(Vector3 center, Vector3 extent);
			AABoxClass(MinMaxAABoxClass minMaxBox);
			AABoxClass(array<Vector3> ^points);
			AABoxClass(IntPtr pointer);

			void Init(Vector3 center, Vector3 extent);
			void Init(array<Vector3> ^points);
			void Init(MinMaxAABoxClass minMaxBox);
			void Init(LineSegClass line);
			void InitMinMax(Vector3 min, Vector3 max);
			void AddPoint(Vector3 point);
			void AddBox(AABoxClass b);
			void AddBox(MinMaxAABoxClass b);
			float ProjectToAxis(Vector3 axis);
			void Transform(Matrix3D tm);
			void Translate(Vector3 pos);
			bool Contains(MinMaxAABoxClass otherBox);
			float ComputeSquaredDistanceFromPoint(Vector3 point);
			float ComputeMaxSquaredDistanceFromPoint(Vector3 point);

			static AABoxClass Transform(Matrix3D tm, AABoxClass in);

			property float Volume
			{
				float get();
			}

		internal:
			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void ManagedToUnmanagedAABoxClass(AABoxClass %managed, ::AABoxClass &result)
			{
				Vector3::ManagedToUnmanagedVector3(managed.Center, result.Center);
				Vector3::ManagedToUnmanagedVector3(managed.Extent, result.Extent);
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void UnmanagedToManagedAABoxClass(const ::AABoxClass &unmanaged, AABoxClass %result)
			{
				Vector3::UnmanagedToManagedVector3(unmanaged.Center, result.Center);
				Vector3::UnmanagedToManagedVector3(unmanaged.Extent, result.Extent);
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void ManagedToUnmanagedAABoxClass(::AABoxClass &result)
			{
				Vector3::ManagedToUnmanagedVector3(Center, result.Center);
				Vector3::ManagedToUnmanagedVector3(Extent, result.Extent);
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void UnmanagedToManagedAABoxClass(const ::AABoxClass &unmanaged)
			{
				Vector3::UnmanagedToManagedVector3(unmanaged.Center, Center);
				Vector3::UnmanagedToManagedVector3(unmanaged.Extent, Extent);
			}
	};

	[StructLayout(LayoutKind::Sequential)]
	public value class MinMaxAABoxClass
	{
		public:
			Vector3 MinCorner;
			Vector3 MaxCorner;

			MinMaxAABoxClass(Vector3 minCorner, Vector3 maxCorner);
			MinMaxAABoxClass(array<Vector3> ^points);
			MinMaxAABoxClass(AABoxClass that);
			MinMaxAABoxClass(IntPtr pointer);

			void Init(array<Vector3> ^points);
			void Init(AABoxClass box);
			void InitEmpty();
			void AddPoint(Vector3 point);
			void AddBox(MinMaxAABoxClass box);
			void AddBox(AABoxClass box);
			void AddBox(Vector3 minCorner, Vector3 maxCorner);
			void Transform(Matrix3D tm);
			void Translate(Vector3 pos);

			property float Volume
			{
				float get();
			}

		internal:
			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void ManagedToUnmanagedMinMaxAABoxClass(MinMaxAABoxClass %managed, ::MinMaxAABoxClass &result)
			{
				Vector3::ManagedToUnmanagedVector3(managed.MinCorner, result.MinCorner);
				Vector3::ManagedToUnmanagedVector3(managed.MaxCorner, result.MaxCorner);
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void UnmanagedToManagedMinMaxAABoxClass(const ::MinMaxAABoxClass &unmanaged, MinMaxAABoxClass %result)
			{
				Vector3::UnmanagedToManagedVector3(unmanaged.MinCorner, result.MinCorner);
				Vector3::UnmanagedToManagedVector3(unmanaged.MaxCorner, result.MaxCorner);
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void ManagedToUnmanagedMinMaxAABoxClass(::MinMaxAABoxClass &result)
			{
				Vector3::ManagedToUnmanagedVector3(MinCorner, result.MinCorner);
				Vector3::ManagedToUnmanagedVector3(MaxCorner, result.MaxCorner);
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void UnmanagedToManagedMinMaxAABoxClass(const ::MinMaxAABoxClass &unmanaged)
			{
				Vector3::UnmanagedToManagedVector3(unmanaged.MinCorner, MinCorner);
				Vector3::UnmanagedToManagedVector3(unmanaged.MaxCorner, MaxCorner);
			}
	};
}