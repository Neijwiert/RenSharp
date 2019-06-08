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
#include <vector2.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace RenSharp
{
	[StructLayout(LayoutKind::Sequential)]
	public value class Vector2i
	{
		public:
			int I;
			int J;

			Vector2i(int i, int j);
			Vector2i(IntPtr pointer);

			void Set(int i, int j);

		internal:
			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void ManagedToUnmanagedVector2i(Vector2i %managed, ::Vector2i &result)
			{
				result.I = managed.I;
				result.J = managed.J;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void UnmanagedToManagedVector2i(const ::Vector2i &unmanaged, Vector2i %result)
			{
				result.I = unmanaged.I;
				result.J = unmanaged.J;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void ManagedToUnmanagedVector2i(::Vector2i &result)
			{
				result.I = I;
				result.J = J;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void UnmanagedToManagedVector2i(const ::Vector2i &unmanaged)
			{
				I = unmanaged.I;
				J = unmanaged.J;
			}
	};

	[StructLayout(LayoutKind::Sequential)]
	public value class Vector2
	{
		public:
			float X;
			float Y;

			Vector2(float x, float y);
			Vector2(array<float> ^vector);
			Vector2(IntPtr pointer);

			void Set(float x, float y);
			void Normalize();
			void Rotate(float theta);
			void Rotate(float s, float c);
			bool RotateTowardsVector(Vector2 target, float maxTheta, [Out] bool %positiveTurn);
			bool RotateTowardsVector(Vector2 target, float maxS, float maxC, [Out] bool %positiveTurn);
			void UpdateMin(Vector2 a);
			void UpdateMax(Vector2 a);
			void Scale(float a, float b);
			void Scale(Vector2 a);
			void Unscale(Vector2 a);
			void Floor();

			static Vector2 operator-(Vector2 a, Vector2 b);
			static Vector2 operator-(Vector2 a);
			static Vector2 operator+(Vector2 a, Vector2 b);
			static Vector2 operator+(Vector2 a);
			static Vector2 operator*(Vector2 a, float k);
			static Vector2 operator*(float k, Vector2 a);
			static float operator*(Vector2 a, Vector2 b);
			static Vector2 operator/(Vector2 a, float k);
			static Vector2 operator/(Vector2 a, Vector2 b);
			static Vector2 operator/(Vector2 a, Vector2i b);

			static float DotProduct(Vector2 a, Vector2 b);
			static float PerpDotProduct(Vector2 a, Vector2 b);
			static float Distance(Vector2 p1, Vector2 p2);
			static Vector2 Lerp(Vector2 a, Vector2 b, float t);
			static void Swap(Vector2 %a, Vector2 %b);
			static float Distance(float x1, float y1, float x2, float y2);

			property float U
			{
				float get();
				void set(float value);
			}

			property float V
			{
				float get();
				void set(float value);
			}

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
			static inline void ManagedToUnmanagedVector2(Vector2 %managed, ::Vector2 &result)
			{
				result.X = managed.X;
				result.Y = managed.Y;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void UnmanagedToManagedVector2(const ::Vector2 &unmanaged, Vector2 %result)
			{
				result.X = unmanaged.X;
				result.Y = unmanaged.Y;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void ManagedToUnmanagedVector2(::Vector2 &result)
			{
				result.X = X;
				result.Y = Y;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void UnmanagedToManagedVector2(const ::Vector2 &unmanaged)
			{
				X = unmanaged.X;
				Y = unmanaged.Y;
			}
	};
}