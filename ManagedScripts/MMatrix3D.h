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
#include <Matrix3D.h>
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
	value class Matrix3;
	value class Quaternion;
	value class PlaneClass;

	[StructLayout(LayoutKind::Sequential)]
	public value class Matrix3D
	{

#pragma warning(pop)
		protected:
			Vector4 Row0;
			Vector4 Row1;
			Vector4 Row2;

		public:
			Matrix3D(bool init);
			Matrix3D(array<float> ^m);
			Matrix3D(Vector3 x, Vector3 y, Vector3 z, Vector3 pos);
			Matrix3D(Vector3 axis, float angle);
			Matrix3D(Vector3 axis, float sine, float cosine);
			Matrix3D(Matrix3 rotation, Vector3 position);
			Matrix3D(Quaternion rotation, Vector3 position);
			Matrix3D(Vector3 position);
			Matrix3D(
				float _11, float _12, float _13, float _14,
				float _21, float _22, float _23, float _24,
				float _31, float _32, float _33, float _34);
			Matrix3D(IntPtr pointer);

			virtual bool Equals(Object ^other) override;
			virtual int GetHashCode() override;

			Matrix3D OrthogonalInverse();
			void LookAt(Vector3 p, Vector3 t, float roll);
			void ObjLookAt(Vector3 p, Vector3 t, float roll);
			Vector3 RotateVector(Vector3 vector);
			Vector3 InverseRotateVector(Vector3 vector);
			void Set(array<float> ^m);
			void Set(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34);
			void Set(Vector3 x, Vector3 y, Vector3 z, Vector3 pos);
			void Set(Vector3 axis, float angle);
			void Set(Vector3 axis, float s, float c);
			void Set(Vector3 position);
			void Set(Matrix3 rotation, Vector3 position);
			void Set(Quaternion rotation, Vector3 position);
			void SetRotation(Quaternion rotation);
			void SetRotation(Matrix3 m);
			void AdjustTranslation(Vector3 t);
			void AdjustXTranslation(float x);
			void AdjustYTranslation(float y);
			void AdjustZTranslation(float z);
			void MakeIdentity();
			void Translate(float x, float y, float z);
			void Translate(Vector3 t);
			void TranslateX(float x);
			void TranslateY(float y);
			void TranslateZ(float z);
			void RotateX(float theta);
			void RotateY(float theta);
			void RotateZ(float theta);
			void RotateX(float s, float c);
			void RotateY(float s, float c);
			void RotateZ(float s, float c);
			void Scale(float scale);
			void Scale(float x, float y, float z);
			void Scale(Vector3 scale);
			void PreRotateX(float theta);
			void PreRotateY(float theta);
			void PreRotateZ(float theta);
			void PreRotateX(float s, float c);
			void PreRotateY(float s, float c);
			void PreRotateZ(float s, float c);
			void InPlacePreRotateX(float theta);
			void InPlacePreRotateY(float theta);
			void InPlacePreRotateZ(float theta);
			void InPlacePreRotateX(float s, float c);
			void InPlacePreRotateY(float s, float c);
			void InPlacePreRotateZ(float s, float c);
			Matrix3D Inverse();
			void TransformMinMaxAABox(Vector3 min, Vector3 max, [Out] Vector3 %setMin, [Out] Vector3 %setMax);
			void TransformCenterExtentAABox(Vector3 center, Vector3 extent, [Out] Vector3 %setCenter, [Out] Vector3 %setExtent);
			PlaneClass TransformPlane(PlaneClass plane);
			void ReOrthogonalize();

			static Matrix3D operator*(Matrix3D a, Matrix3D b);
			static Vector3 operator*(Matrix3D matrix, Vector3 vector);	

			static Vector3 TransformVector(Matrix3D a, Vector3 in);
			static Matrix3D Multiply(Matrix3D a, Matrix3D b);
			static Vector3 RotateVector(Matrix3D a, Vector3 in);
			static Vector3 InverseTransformVector(Matrix3D a, Vector3 in);
			static Vector3 InverseRotateVector(Matrix3D a, Vector3 in);
			static Matrix3D ReflectPlane(PlaneClass plane);
			static bool SolveLinearSystem(Matrix3D %system);

			property Vector4 default[int]
			{
				Vector4 get(int index);
				void set(int index, Vector4 value);
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

			property Vector3 Translation
			{
				Vector3 get();
				void set(Vector3 value);
			}

			property float XTranslation
			{
				float get();
				void set(float value);
			}

			property float YTranslation
			{
				float get();
				void set(float value);
			}

			property float ZTranslation
			{
				float get();
				void set(float value);
			}

			property int IsOrthogonal
			{
				int get();
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

			static property Matrix3D Identity
			{
				Matrix3D get();
			}

		internal:
			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void ManagedToUnmanagedMatrix3D(Matrix3D %managed, ::Matrix3D &result)
			{
				auto &row0 = result[0];
				auto &row1 = result[1];
				auto &row2 = result[2];

				Vector4::ManagedToUnmanagedVector4(managed.Row0, row0);
				Vector4::ManagedToUnmanagedVector4(managed.Row1, row1);
				Vector4::ManagedToUnmanagedVector4(managed.Row2, row2);
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void UnmanagedToManagedMatrix3D(const ::Matrix3D &unmanaged, Matrix3D %result)
			{
				auto &row0 = unmanaged[0];
				auto &row1 = unmanaged[1];
				auto &row2 = unmanaged[2];

				Vector4::UnmanagedToManagedVector4(row0, result.Row0);
				Vector4::UnmanagedToManagedVector4(row1, result.Row1);
				Vector4::UnmanagedToManagedVector4(row2, result.Row2);
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void ManagedToUnmanagedMatrix3D(::Matrix3D &result)
			{
				auto &row0 = result[0];
				auto &row1 = result[1];
				auto &row2 = result[2];

				Vector4::ManagedToUnmanagedVector4(Row0, row0);
				Vector4::ManagedToUnmanagedVector4(Row1, row1);
				Vector4::ManagedToUnmanagedVector4(Row2, row2);
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void UnmanagedToManagedMatrix3D(const ::Matrix3D &unmanaged)
			{
				auto &row0 = unmanaged[0];
				auto &row1 = unmanaged[1];
				auto &row2 = unmanaged[2];

				Vector4::UnmanagedToManagedVector4(row0, Row0);
				Vector4::UnmanagedToManagedVector4(row1, Row1);
				Vector4::UnmanagedToManagedVector4(row2, Row2);
			}
	};
}