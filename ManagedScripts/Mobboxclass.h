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
#include "MMatrix3.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <obboxclass.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace RenSharp
{

#pragma warning(push)
#pragma warning(disable : 4099 4251 4244 26495 26454)

	value class Matrix3D;

#pragma warning(pop)

	[StructLayout(LayoutKind::Sequential)]
	public value class OBBoxClass
	{
		public:
			Matrix3 Basis;
			Vector3 Center;
			Vector3 Extent;

			OBBoxClass(Vector3 center, Vector3 extent);
			OBBoxClass(Vector3 center, Vector3 extent, Matrix3 basis);
			OBBoxClass(Vector3 aabbCenter, Vector3 aabbExtent, Matrix3D transform);
			OBBoxClass(IntPtr pointer);

			float ProjectToAxis(Vector3 axis);
			Vector3 ComputePoint(array<float> ^params);
			Vector3 ComputeAxisAlignedExtent();
			float ComputeSquaredDistanceFromPoint(Vector3 point);

			static OBBoxClass Transform(Matrix3D m, OBBoxClass in);

			property float Volume
			{
				float get();
			}

		internal:
			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void ManagedToUnmanagedOBBoxClass(OBBoxClass %managed, ::OBBoxClass &result)
			{
				Matrix3::ManagedToUnmanagedMatrix3(managed.Basis, result.Basis);
				Vector3::ManagedToUnmanagedVector3(managed.Center, result.Center);
				Vector3::ManagedToUnmanagedVector3(managed.Extent, result.Extent);
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void UnmanagedToManagedOBBoxClass(const ::OBBoxClass &unmanaged, OBBoxClass %result)
			{
				Matrix3::UnmanagedToManagedMatrix3(unmanaged.Basis, result.Basis);
				Vector3::UnmanagedToManagedVector3(unmanaged.Center, result.Center);
				Vector3::UnmanagedToManagedVector3(unmanaged.Extent, result.Extent);
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void ManagedToUnmanagedOBBoxClass(::OBBoxClass &result)
			{
				Matrix3::ManagedToUnmanagedMatrix3(Basis, result.Basis);
				Vector3::ManagedToUnmanagedVector3(Center, result.Center);
				Vector3::ManagedToUnmanagedVector3(Extent, result.Extent);
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void UnmanagedToManagedOBBoxClass(const ::OBBoxClass &unmanaged)
			{
				Matrix3::UnmanagedToManagedMatrix3(unmanaged.Basis, Basis);
				Vector3::UnmanagedToManagedVector3(unmanaged.Center, Center);
				Vector3::UnmanagedToManagedVector3(unmanaged.Extent, Extent);
			}
	};
}