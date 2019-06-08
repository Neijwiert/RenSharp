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
#include <Vector3.h>
#include <Types.h>
#include <CastResultStruct.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MVector3.h"

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace RenSharp
{
	[StructLayout(LayoutKind::Sequential)]
	public value class CastResultStruct
	{
		public:
			bool StartBad;
			float Fraction;
			Vector3 Normal;
			unsigned int SurfaceType;
			bool ComputeContactPoint;
			Vector3 ContactPoint;

			CastResultStruct(IntPtr pointer);

			void Reset();

		internal:
			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void ManagedToUnmanagedCastResultStruct(CastResultStruct %managed, ::CastResultStruct &result)
			{
				result.StartBad = managed.StartBad;
				result.Fraction = managed.Fraction;
				Vector3::ManagedToUnmanagedVector3(managed.Normal, result.Normal);
				result.SurfaceType = managed.SurfaceType;
				result.ComputeContactPoint = managed.ComputeContactPoint;
				Vector3::ManagedToUnmanagedVector3(managed.ContactPoint, result.ContactPoint);
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void UnmanagedToManagedCastResultStruct(const ::CastResultStruct &unmanaged, CastResultStruct %result)
			{
				result.StartBad = unmanaged.StartBad;
				result.Fraction = unmanaged.Fraction;
				Vector3::UnmanagedToManagedVector3(unmanaged.Normal, result.Normal);
				result.SurfaceType = unmanaged.SurfaceType;
				result.ComputeContactPoint = unmanaged.ComputeContactPoint;
				Vector3::UnmanagedToManagedVector3(unmanaged.ContactPoint, result.ContactPoint);
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void ManagedToUnmanagedCastResultStruct(::CastResultStruct &result)
			{
				result.StartBad = StartBad;
				result.Fraction = Fraction;
				Vector3::ManagedToUnmanagedVector3(Normal, result.Normal);
				result.SurfaceType = SurfaceType;
				result.ComputeContactPoint = ComputeContactPoint;
				Vector3::ManagedToUnmanagedVector3(ContactPoint, result.ContactPoint);
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void UnmanagedToManagedCastResultStruct(const ::CastResultStruct &unmanaged)
			{
				StartBad = unmanaged.StartBad;
				Fraction = unmanaged.Fraction;
				Vector3::UnmanagedToManagedVector3(unmanaged.Normal, Normal);
				SurfaceType = unmanaged.SurfaceType;
				ComputeContactPoint = unmanaged.ComputeContactPoint;
				Vector3::UnmanagedToManagedVector3(unmanaged.ContactPoint, ContactPoint);
			}
	};
}