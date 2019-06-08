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

#include "MVector3.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <plane.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace RenSharp
{
	value class SphereClass;

	[StructLayout(LayoutKind::Sequential)]
	public value class PlaneClass
	{
		public:
			Vector3 N;
			float D;

			PlaneClass(float nX, float nY, float nZ, float dist);
			PlaneClass(Vector3 normal, float dist);
			PlaneClass(Vector3 normal, Vector3 point);
			PlaneClass(Vector3 point1, Vector3 point2, Vector3 point3);
			PlaneClass(IntPtr pointer);

			void Set(float a, float b, float c, float d);
			void Set(Vector3 normal, float dist);
			void Set(Vector3 normal, Vector3 point);
			void Set(Vector3 point1, Vector3 point2, Vector3 point3);
			void Normalize();
			bool InFront(Vector3 point);
			bool InFront(SphereClass sphere);
			bool ComputeIntersection(Vector3 p0, Vector3 p1, float %setT);

			static PlaneClass operator-(PlaneClass p);

		internal:
			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void ManagedToUnmanagedPlaneClass(PlaneClass %managed, ::PlaneClass &result)
			{
				result.N.X = managed.N.X;
				result.N.Y = managed.N.Y;
				result.N.Z = managed.N.Z;
				result.D = managed.D;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void UnmanagedToManagedPlaneClass(const ::PlaneClass &unmanaged, PlaneClass %result)
			{
				result.N.X = unmanaged.N.X;
				result.N.Y = unmanaged.N.Y;
				result.N.Z = unmanaged.N.Z;
				result.D = unmanaged.D;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void ManagedToUnmanagedPlaneClass(::PlaneClass &result)
			{
				result.N.X = N.X;
				result.N.Y = N.Y;
				result.N.Z = N.Z;
				result.D = D;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void UnmanagedToManagedPlaneClass(const ::PlaneClass &unmanaged)
			{
				N.X = unmanaged.N.X;
				N.Y = unmanaged.N.Y;
				N.Z = unmanaged.N.Z;
				D = unmanaged.D;
			}
	};
}