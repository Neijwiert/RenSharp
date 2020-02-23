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
#include <Matrix3.h>
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
	value class Matrix4;
	value class Quaternion;

	[StructLayout(LayoutKind::Sequential)]
	public value class Matrix3
	{

#pragma warning(pop)

		public:
			Vector3 Row0;
			Vector3 Row1;
			Vector3 Row2;

			Matrix3(bool identity);
			Matrix3(Vector3 v0, Vector3 v1, Vector3 v2);
			Matrix3(Matrix3D m);
			Matrix3(Matrix4 m);
			Matrix3(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33);
			Matrix3(Vector3 axis, float angle);
			Matrix3(Vector3 axis, float sAngle, float cAngle);
			Matrix3(Quaternion q);
			Matrix3(IntPtr pointer);

			void Set(Matrix3D m);
			void Set(Matrix4 m);
			void Set(Vector3 v0, Vector3 v1, Vector3 v2);
			void Set(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33);
			void Set(Vector3 axis, float angle);
			void Set(Vector3 axis, float s, float c);
			void Set(Quaternion q);
			Matrix3 Transpose();
			float Determinant();
			void MakeIdentity();
			void RotateX(float theta);
			void RotateX(float s, float c);
			void RotateY(float theta);
			void RotateY(float s, float c);
			void RotateZ(float theta);
			void RotateZ(float s, float c);
			Vector3 RotateAABoxExtent(Vector3 extent);
			Matrix3 Inverse();

			static operator Matrix3(Matrix3D m);
			static operator Matrix3(Matrix4 m);
			static Matrix3 operator+(Matrix3 a, Matrix3 b);
			static Matrix3 operator-(Matrix3 a);
			static Matrix3 operator-(Matrix3 a, Matrix3 b);	
			static Matrix3 operator*(Matrix3 a, Matrix3 b);
			static Matrix3 operator*(Matrix3 a, float d);
			static Matrix3 operator*(float d, Matrix3 a);
			static Vector3 operator*(Matrix3 a, Vector3 v);
			static Matrix3 operator/(Matrix3 a, float d);

			static Matrix3 Add(Matrix3 a, Matrix3 b);
			static Matrix3 Subtract(Matrix3 a, Matrix3 b);
			static Matrix3 Multiply(Matrix3 a, Matrix3 b);
			static Matrix3 Multiply(Matrix3D a, Matrix3 b);
			static Matrix3 Multiply(Matrix3 a, Matrix3D b);
			static Vector3 RotateVector(Matrix3 a, Vector3 in);
			static Vector3 TransposeRotateVector(Matrix3 a, Vector3 in);
			static Matrix3 CreateXRotationMatrix3(float s, float c);
			static Matrix3 CreateXRotationMatrix3(float rad);
			static Matrix3 CreateYRotationMatrix3(float s, float c);
			static Matrix3 CreateYRotationMatrix3(float rad);
			static Matrix3 CreateZRotationMatrix3(float s, float c);
			static Matrix3 CreateZRotationMatrix3(float rad);

			property Vector3 default[int]
			{
				Vector3 get(int index);
				void set(int index, Vector3 value);
			}

			property float XRotation
			{
				float get();
			}

			property float YRotation
			{
				float get();
			}

			property float ZRotation
			{
				float get();
			}

			property Vector3 XVector
			{
				Vector3 get();
			}

			property Vector3 YVector
			{
				Vector3 get();
			}

			property Vector3 ZVector
			{
				Vector3 get();
			}

			static property Matrix3 Identity
			{
				Matrix3 get();
			}

		internal:
			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void ManagedToUnmanagedMatrix3(Matrix3 %managed, ::Matrix3 &result)
			{
				auto &row0 = result[0];
				auto &row1 = result[1];
				auto &row2 = result[2];

				Vector3::ManagedToUnmanagedVector3(managed.Row0, row0);
				Vector3::ManagedToUnmanagedVector3(managed.Row1, row1);
				Vector3::ManagedToUnmanagedVector3(managed.Row2, row2);
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void UnmanagedToManagedMatrix3(const ::Matrix3 &unmanaged, Matrix3 %result)
			{
				auto &row0 = unmanaged[0];
				auto &row1 = unmanaged[1];
				auto &row2 = unmanaged[2];

				Vector3::UnmanagedToManagedVector3(row0, result.Row0);
				Vector3::UnmanagedToManagedVector3(row1, result.Row1);
				Vector3::UnmanagedToManagedVector3(row2, result.Row2);
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void ManagedToUnmanagedMatrix3(::Matrix3 &result)
			{
				auto &row0 = result[0];
				auto &row1 = result[1];
				auto &row2 = result[2];

				Vector3::ManagedToUnmanagedVector3(Row0, row0);
				Vector3::ManagedToUnmanagedVector3(Row1, row1);
				Vector3::ManagedToUnmanagedVector3(Row2, row2);
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void UnmanagedToManagedMatrix3(const ::Matrix3 &unmanaged)
			{
				auto &row0 = unmanaged[0];
				auto &row1 = unmanaged[1];
				auto &row2 = unmanaged[2];

				Vector3::UnmanagedToManagedVector3(row0, Row0);
				Vector3::UnmanagedToManagedVector3(row1, Row1);
				Vector3::UnmanagedToManagedVector3(row2, Row2);
			}
	};
}