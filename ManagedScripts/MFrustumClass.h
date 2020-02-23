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
#include <FrustumClass.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MMatrix3D.h"
#include "Mplane.h"
#include "MVector3.h"

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace RenSharp
{
	value class Vector2;

	[StructLayout(LayoutKind::Sequential)]
	public value class FrustumClass
	{
		public:
			Matrix3D CameraTransform;
			PlaneClass Plane0;
			PlaneClass Plane1;
			PlaneClass Plane2;
			PlaneClass Plane3;
			PlaneClass Plane4;
			PlaneClass Plane5;
			Vector3 Corner0;
			Vector3 Corner1;
			Vector3 Corner2;
			Vector3 Corner3;
			Vector3 Corner4;
			Vector3 Corner5;
			Vector3 Corner6;
			Vector3 Corner7;
			Vector3 BoundMin;
			Vector3 BoundMax;

			void Init(Matrix3D camera, Vector2 vpMin, Vector2 vpMax, float zNear, float zFar);

		internal:
			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void ManagedToUnmanagedFrustumClass(FrustumClass %managed, ::FrustumClass &result)
			{
				Matrix3D::ManagedToUnmanagedMatrix3D(managed.CameraTransform, result.CameraTransform);
				PlaneClass::ManagedToUnmanagedPlaneClass(managed.Plane0, result.Planes[0]);
				PlaneClass::ManagedToUnmanagedPlaneClass(managed.Plane1, result.Planes[1]);
				PlaneClass::ManagedToUnmanagedPlaneClass(managed.Plane2, result.Planes[2]);
				PlaneClass::ManagedToUnmanagedPlaneClass(managed.Plane3, result.Planes[3]);
				PlaneClass::ManagedToUnmanagedPlaneClass(managed.Plane4, result.Planes[4]);
				PlaneClass::ManagedToUnmanagedPlaneClass(managed.Plane5, result.Planes[5]);
				Vector3::ManagedToUnmanagedVector3(managed.Corner0, result.Corners[0]);
				Vector3::ManagedToUnmanagedVector3(managed.Corner1, result.Corners[1]);
				Vector3::ManagedToUnmanagedVector3(managed.Corner2, result.Corners[2]);
				Vector3::ManagedToUnmanagedVector3(managed.Corner3, result.Corners[3]);
				Vector3::ManagedToUnmanagedVector3(managed.Corner4, result.Corners[4]);
				Vector3::ManagedToUnmanagedVector3(managed.Corner5, result.Corners[5]);
				Vector3::ManagedToUnmanagedVector3(managed.Corner6, result.Corners[6]);
				Vector3::ManagedToUnmanagedVector3(managed.Corner7, result.Corners[7]);
				Vector3::ManagedToUnmanagedVector3(managed.BoundMin, result.BoundMin);
				Vector3::ManagedToUnmanagedVector3(managed.BoundMax, result.BoundMax);
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void UnmanagedToManagedFrustumClass(const ::FrustumClass &unmanaged, FrustumClass %result)
			{
				Matrix3D::UnmanagedToManagedMatrix3D(unmanaged.CameraTransform, result.CameraTransform);
				PlaneClass::UnmanagedToManagedPlaneClass(unmanaged.Planes[0], result.Plane0);
				PlaneClass::UnmanagedToManagedPlaneClass(unmanaged.Planes[1], result.Plane1);
				PlaneClass::UnmanagedToManagedPlaneClass(unmanaged.Planes[2], result.Plane2);
				PlaneClass::UnmanagedToManagedPlaneClass(unmanaged.Planes[3], result.Plane3);
				PlaneClass::UnmanagedToManagedPlaneClass(unmanaged.Planes[4], result.Plane4);
				PlaneClass::UnmanagedToManagedPlaneClass(unmanaged.Planes[5], result.Plane5);
				Vector3::UnmanagedToManagedVector3(unmanaged.Corners[0], result.Corner0);
				Vector3::UnmanagedToManagedVector3(unmanaged.Corners[1], result.Corner1);
				Vector3::UnmanagedToManagedVector3(unmanaged.Corners[2], result.Corner2);
				Vector3::UnmanagedToManagedVector3(unmanaged.Corners[3], result.Corner3);
				Vector3::UnmanagedToManagedVector3(unmanaged.Corners[4], result.Corner4);
				Vector3::UnmanagedToManagedVector3(unmanaged.Corners[5], result.Corner5);
				Vector3::UnmanagedToManagedVector3(unmanaged.Corners[6], result.Corner6);
				Vector3::UnmanagedToManagedVector3(unmanaged.Corners[7], result.Corner7);
				Vector3::UnmanagedToManagedVector3(unmanaged.BoundMin, result.BoundMin);
				Vector3::UnmanagedToManagedVector3(unmanaged.BoundMax, result.BoundMax);
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void ManagedToUnmanagedFrustumClass(::FrustumClass &result)
			{
				Matrix3D::ManagedToUnmanagedMatrix3D(CameraTransform, result.CameraTransform);
				PlaneClass::ManagedToUnmanagedPlaneClass(Plane0, result.Planes[0]);
				PlaneClass::ManagedToUnmanagedPlaneClass(Plane1, result.Planes[1]);
				PlaneClass::ManagedToUnmanagedPlaneClass(Plane2, result.Planes[2]);
				PlaneClass::ManagedToUnmanagedPlaneClass(Plane3, result.Planes[3]);
				PlaneClass::ManagedToUnmanagedPlaneClass(Plane4, result.Planes[4]);
				PlaneClass::ManagedToUnmanagedPlaneClass(Plane5, result.Planes[5]);
				Vector3::ManagedToUnmanagedVector3(Corner0, result.Corners[0]);
				Vector3::ManagedToUnmanagedVector3(Corner1, result.Corners[1]);
				Vector3::ManagedToUnmanagedVector3(Corner2, result.Corners[2]);
				Vector3::ManagedToUnmanagedVector3(Corner3, result.Corners[3]);
				Vector3::ManagedToUnmanagedVector3(Corner4, result.Corners[4]);
				Vector3::ManagedToUnmanagedVector3(Corner5, result.Corners[5]);
				Vector3::ManagedToUnmanagedVector3(Corner6, result.Corners[6]);
				Vector3::ManagedToUnmanagedVector3(Corner7, result.Corners[7]);
				Vector3::ManagedToUnmanagedVector3(BoundMin, result.BoundMin);
				Vector3::ManagedToUnmanagedVector3(BoundMax, result.BoundMax);
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void UnmanagedToManagedFrustumClass(const ::FrustumClass &unmanaged)
			{
				Matrix3D::UnmanagedToManagedMatrix3D(unmanaged.CameraTransform, CameraTransform);
				PlaneClass::UnmanagedToManagedPlaneClass(unmanaged.Planes[0], Plane0);
				PlaneClass::UnmanagedToManagedPlaneClass(unmanaged.Planes[1], Plane1);
				PlaneClass::UnmanagedToManagedPlaneClass(unmanaged.Planes[2], Plane2);
				PlaneClass::UnmanagedToManagedPlaneClass(unmanaged.Planes[3], Plane3);
				PlaneClass::UnmanagedToManagedPlaneClass(unmanaged.Planes[4], Plane4);
				PlaneClass::UnmanagedToManagedPlaneClass(unmanaged.Planes[5], Plane5);
				Vector3::UnmanagedToManagedVector3(unmanaged.Corners[0], Corner0);
				Vector3::UnmanagedToManagedVector3(unmanaged.Corners[1], Corner1);
				Vector3::UnmanagedToManagedVector3(unmanaged.Corners[2], Corner2);
				Vector3::UnmanagedToManagedVector3(unmanaged.Corners[3], Corner3);
				Vector3::UnmanagedToManagedVector3(unmanaged.Corners[4], Corner4);
				Vector3::UnmanagedToManagedVector3(unmanaged.Corners[5], Corner5);
				Vector3::UnmanagedToManagedVector3(unmanaged.Corners[6], Corner6);
				Vector3::UnmanagedToManagedVector3(unmanaged.Corners[7], Corner7);
				Vector3::UnmanagedToManagedVector3(unmanaged.BoundMin, BoundMin);
				Vector3::UnmanagedToManagedVector3(unmanaged.BoundMax, BoundMax);
			}
	};
}