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

#include "MVector3.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <SphereClass.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace RenSharp
{
	value class Matrix3D;

	[StructLayout(LayoutKind::Sequential)]
	public value class SphereClass
	{
		public:
			Vector3 Center;
			float Radius;

			SphereClass(Vector3 center, float radius);
			SphereClass(Vector3 center, SphereClass s0);
			SphereClass(array<Vector3> ^positions);
			SphereClass(IntPtr pointer);

			void Init(Vector3 pos, float radius);
			void ReCenter(Vector3 center);
			void AddSphere(SphereClass s);
			void Transform(Matrix3D m);

			static SphereClass operator+(SphereClass s0, SphereClass s1);
			static SphereClass operator*(Matrix3D mat, SphereClass s0);

			static bool SpheresIntersect(SphereClass s0, SphereClass s1);
			static SphereClass AddSpheres(SphereClass s0, SphereClass s1);
			static SphereClass TransformSphere(Matrix3D mat, SphereClass s0);

			property float Volume
			{
				float get();
			}

		internal:
			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void ManagedToUnmanagedSphereClass(SphereClass %managed, ::SphereClass &result)
			{
				result.Center.X = managed.Center.X;
				result.Center.Y = managed.Center.Y;
				result.Center.Z = managed.Center.Z;
				result.Radius = managed.Radius;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void UnmanagedToManagedSphereClass(const ::SphereClass &unmanaged, SphereClass %result)
			{
				result.Center.X = unmanaged.Center.X;
				result.Center.Y = unmanaged.Center.Y;
				result.Center.Z = unmanaged.Center.Z;
				result.Radius = unmanaged.Radius;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void ManagedToUnmanagedSphereClass(::SphereClass &result)
			{
				result.Center.X = Center.X;
				result.Center.Y = Center.Y;
				result.Center.Z = Center.Z;
				result.Radius = Radius;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void UnmanagedToManagedSphereClass(const ::SphereClass &unmanaged)
			{
				Center.X = unmanaged.Center.X;
				Center.Y = unmanaged.Center.Y;
				Center.Z = unmanaged.Center.Z;
				Radius = unmanaged.Radius;
			}
	};
}