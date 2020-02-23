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

#include "Mvector4.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <matrix4.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace RenSharp
{

#pragma warning(push)
#pragma warning(disable : 4099 4251 4244 26495 26454)

	value class Vector3;
	value class Vector4;
	value class Matrix3D;
	value class PlaneClass;

#pragma warning(pop)

	[StructLayout(LayoutKind::Sequential)]
	public value class Matrix4
	{
		protected:
			Vector4 Row0;
			Vector4 Row1;
			Vector4 Row2;
			Vector4 Row3;

		public:
			Matrix4(bool identity);
			Matrix4(Matrix3D m);
			Matrix4(Vector4 v0, Vector4 v1, Vector4 v2, Vector4 v3);
			Matrix4(IntPtr pointer);

			virtual bool Equals(Object ^other) override;
			virtual int GetHashCode() override;

			void MakeIdentity();
			void Init(Matrix3D m);
			void Init(Vector4 v0, Vector4 v1, Vector4 v2, Vector4 v3);
			void InitOrthoOGL(float left, float right, float bottom, float top, float zNear, float zFar);
			void InitPerspectiveOGL(float hFOV, float vFOV, float zNear, float zFar);
			void InitPerspectiveOGL(float left, float right, float bottom, float top, float zNear, float zFar);
			void InitOrtho(float left, float right, float bottom, float top, float zNear, float zFar);
			void InitPerspective(float left, float right, float bottom, float top, float zNear, float zFar);
			Matrix4 Transpose();
			Matrix4 Inverse();

			static Matrix4 operator+(Matrix4 a, Matrix4 b);
			static Matrix4 operator-(Matrix4 a, Matrix4 b);
			static Matrix4 operator-(Matrix4 a);
			static Matrix4 operator*(Matrix4 a, float d);
			static Matrix4 operator*(float d, Matrix4 a);
			static Matrix4 operator*(Matrix4 a, Matrix4 b);
			static Matrix4 operator*(Matrix3D a, Matrix4 b);
			static Matrix4 operator*(Matrix4 a, Matrix3D b);
			static Vector4 operator*(Matrix4 a, Vector4 v);
			static Vector4 operator*(Matrix4 a, Vector3 v);
			static Matrix4 operator/(Matrix4 a, float d);

			static Matrix4 Subtract(Matrix4 a, Matrix4 b);
			static Matrix4 Multiply(Matrix4 a, Matrix4 b);
			static Matrix4 Multiply(Matrix3D a, Matrix4 b);
			static Matrix4 Multiply(Matrix4 a, Matrix3D b);
			static Vector3 TransformVector3(Matrix4 a, Vector3 in);
			static Vector4 TransformVector4(Matrix4 a, Vector3 in);
			static Vector4 TransformVector4(Matrix4 a, Vector4 in);
			static Matrix4 ReflectPlane(PlaneClass plane);

			property Vector4 default[int]
			{
				Vector4 get(int index);
				void set(int index, Vector4 value);
			}

			property float Determinant
			{
				float get();
			}

			static property Matrix4 Identity
			{
				Matrix4 get();
			}

		internal:
			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void ManagedToUnmanagedMatrix4(Matrix4 %managed, ::Matrix4 &result)
			{
				auto &row0 = result[0];
				auto &row1 = result[1];
				auto &row2 = result[2];
				auto &row3 = result[3];

				Vector4::ManagedToUnmanagedVector4(managed.Row0, row0);
				Vector4::ManagedToUnmanagedVector4(managed.Row1, row1);
				Vector4::ManagedToUnmanagedVector4(managed.Row2, row2);
				Vector4::ManagedToUnmanagedVector4(managed.Row3, row3);
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void UnmanagedToManagedMatrix4(const ::Matrix4 &unmanaged, Matrix4 %result)
			{
				auto &row0 = unmanaged[0];
				auto &row1 = unmanaged[1];
				auto &row2 = unmanaged[2];
				auto &row3 = unmanaged[3];

				Vector4::UnmanagedToManagedVector4(row0, result.Row0);
				Vector4::UnmanagedToManagedVector4(row1, result.Row1);
				Vector4::UnmanagedToManagedVector4(row2, result.Row2);
				Vector4::UnmanagedToManagedVector4(row3, result.Row3);
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void ManagedToUnmanagedMatrix4(::Matrix4 &result)
			{
				auto &row0 = result[0];
				auto &row1 = result[1];
				auto &row2 = result[2];
				auto &row3 = result[3];

				Vector4::ManagedToUnmanagedVector4(Row0, row0);
				Vector4::ManagedToUnmanagedVector4(Row1, row1);
				Vector4::ManagedToUnmanagedVector4(Row2, row2);
				Vector4::ManagedToUnmanagedVector4(Row3, row3);
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void UnmanagedToManagedMatrix4(const ::Matrix4 &unmanaged)
			{
				auto &row0 = unmanaged[0];
				auto &row1 = unmanaged[1];
				auto &row2 = unmanaged[2];
				auto &row3 = unmanaged[3];

				Vector4::UnmanagedToManagedVector4(row0, Row0);
				Vector4::UnmanagedToManagedVector4(row1, Row1);
				Vector4::UnmanagedToManagedVector4(row2, Row2);
				Vector4::UnmanagedToManagedVector4(row3, Row3);
			}
	};
}