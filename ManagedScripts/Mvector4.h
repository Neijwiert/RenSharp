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
#include <vector4.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace RenSharp
{
	[StructLayout(LayoutKind::Sequential)]
	public value class Vector4
	{
		public:
			float X;
			float Y;
			float Z;
			float W;

			Vector4(float x, float y, float z, float w);
			Vector4(array<float> ^v);
			Vector4(IntPtr pointer);

			void Set(float x, float y, float z, float w);
			void Normalize();

			static Vector4 operator-(Vector4 a, Vector4 b);
			static Vector4 operator-(Vector4 a);
			static Vector4 operator+(Vector4 a, Vector4 b);
			static Vector4 operator+(Vector4 a);
			static Vector4 operator*(Vector4 a, float f);
			static Vector4 operator*(float f, Vector4 a);
			static float operator*(Vector4 a, Vector4 b);
			static Vector4 operator/(Vector4 a, float f);

			static float DotProduct(Vector4 a, Vector4 b);
			static Vector4 Lerp(Vector4 a, Vector4 b, float alpha);
			static void Swap(Vector4 %a, Vector4 %b);

			property float default[int]
			{
				float get(int index);
				void set(int index, float value);
			}

			property float Length
			{
				float get();
			}

			property float Length2
			{
				float get();
			}

		internal:
			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void ManagedToUnmanagedVector4(Vector4 %managed, ::Vector4 &result)
			{
				result.X = managed.X;
				result.Y = managed.Y;
				result.Z = managed.Z;
				result.W = managed.W;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void UnmanagedToManagedVector4(const ::Vector4 &unmanaged, Vector4 %result)
			{
				result.X = unmanaged.X;
				result.Y = unmanaged.Y;
				result.Z = unmanaged.Z;
				result.W = unmanaged.W;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void ManagedToUnmanagedVector4(::Vector4 &result)
			{
				result.X = this->X;
				result.Y = this->Y;
				result.Z = this->Z;
				result.W = this->W;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void UnmanagedToManagedVector4(const ::Vector4 &unmanaged)
			{
				this->X = unmanaged.X;
				this->Y = unmanaged.Y;
				this->Z = unmanaged.Z;
				this->W = unmanaged.W;
			}
	};
}