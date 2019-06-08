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
#include <AAPlaneClass.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace RenSharp
{
	value class Vector3;

	[StructLayout(LayoutKind::Sequential)]
	public value class AAPlaneClass
	{
		public:
			enum class AxisEnum : int
			{
				XNormal = ::AAPlaneClass::AxisEnum::XNORMAL,
				YNormal = ::AAPlaneClass::AxisEnum::YNORMAL,
				ZNormal = ::AAPlaneClass::AxisEnum::ZNORMAL
			};

			AxisEnum Normal;
			float Dist;

			AAPlaneClass(AxisEnum normal, float dist);
			AAPlaneClass(IntPtr pointer);

			void Set(AxisEnum normal, float dist);
			bool InFront(Vector3 point);

			property Vector3 VectorNormal
			{
				Vector3 get();
			}

		internal:
			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void ManagedToUnmanagedAAPlaneClass(AAPlaneClass% managed, ::AAPlaneClass&result)
			{
				result.Normal = static_cast<::AAPlaneClass::AxisEnum>(managed.Normal);
				result.Dist = managed.Dist;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void UnmanagedToManagedAAPlaneClass(const ::AAPlaneClass& unmanaged, AAPlaneClass% result)
			{
				result.Normal = static_cast<AxisEnum>(unmanaged.Normal);
				result.Dist = unmanaged.Dist;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void ManagedToUnmanagedAAPlaneClass(::AAPlaneClass& result)
			{
				result.Normal = static_cast<::AAPlaneClass::AxisEnum>(Normal);
				result.Dist = Dist;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void UnmanagedToManagedAAPlaneClass(const ::AAPlaneClass& unmanaged)
			{
				Normal = static_cast<AxisEnum>(unmanaged.Normal);
				Dist = unmanaged.Dist;
			}
	};
}