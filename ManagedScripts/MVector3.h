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

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Drawing;
using namespace System::Runtime::CompilerServices;

namespace RenSharp
{

#pragma warning(push)
#pragma warning(disable : 4099 4251 4244 26495 26454)

	[StructLayout(LayoutKind::Sequential)]
	public value class Vector3
	{

#pragma warning(pop)

		public:
			float X;
			float Y;
			float Z;

			Vector3(float x, float y, float z);
			Vector3(array<float> ^vector);
			Vector3(IntPtr pointer);

			void Set(float x, float y, float z);
			void Set(Vector3 other);
			void Normalize();
			Vector3 Normalized();
			void Scale(Vector3 scale);
			void RotateX(float angle);
			void RotateX(float sAngle, float cAngle);
			void RotateY(float angle);
			void RotateY(float sAngle, float cAngle);
			void RotateZ(float angle);
			void RotateZ(float sAngle, float cAngle);
			Vector3 Mul(Vector3 other);
			void UpdateMin(Vector3 a);
			void UpdateMax(Vector3 a);
			void CapAbsoluteTo(Vector3 a);

			static Vector3 operator-(Vector3 a, Vector3 b);
			static Vector3 operator-(Vector3 a);
			static Vector3 operator+(Vector3 a, Vector3 b);
			static Vector3 operator+(Vector3 a);
			static Vector3 operator*(Vector3 a, float k);
			static Vector3 operator*(float k, Vector3 a);
			static float operator*(Vector3 a, Vector3 b);
			static Vector3 operator/(Vector3 a, float k);
			static float DotProduct(Vector3 a, Vector3 b);
			static Vector3 CrossProduct(Vector3 a, Vector3 b);
			static float CrossProductX(Vector3 a, Vector3 b);
			static float CrossProductY(Vector3 a, Vector3 b);
			static float CrossProductZ(Vector3 a, Vector3 b);
			static Vector3 Add(Vector3 a, Vector3 b);
			static Vector3 Subtract(Vector3 a, Vector3 b);
			static float FindXAtY(float y, Vector3 p1, Vector3 p2);
			static float FindXAtZ(float z, Vector3 p1, Vector3 p2);
			static float FindYAtX(float x, Vector3 p1, Vector3 p2);
			static float FindYAtZ(float z, Vector3 p1, Vector3 p2);
			static float FindZAtX(float x, Vector3 p1, Vector3 p2);
			static float FindZAtY(float y, Vector3 p1, Vector3 p2);
			static float Distance(Vector3 p1, Vector3 p2);
			static Vector3 Lerp(Vector3 a, Vector3 b, float alpha);
			static Vector3 Replicate(float n);
			static void Swap(Vector3 %a, Vector3 %b);

			property bool IsValid
			{
				bool get();
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

			property Vector3 Abs
			{
				Vector3 get();
			}

			property Color ARGB
			{
				Color get();
			}

			property float QuickLength
			{
				float get();
			}

		internal:
			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void ManagedToUnmanagedVector3(Vector3 %managed, ::Vector3 &result)
			{
				result.X = managed.X;
				result.Y = managed.Y;
				result.Z = managed.Z;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void UnmanagedToManagedVector3(const ::Vector3 &unmanaged, Vector3 %result)
			{
				result.X = unmanaged.X;
				result.Y = unmanaged.Y;
				result.Z = unmanaged.Z;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void ManagedToUnmanagedVector3(::Vector3 &result)
			{
				result.X = this->X;
				result.Y = this->Y;
				result.Z = this->Z;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void UnmanagedToManagedVector3(const ::Vector3 &unmanaged)
			{
				this->X = unmanaged.X;
				this->Y = unmanaged.Y;
				this->Z = unmanaged.Z;
			}
	};
}