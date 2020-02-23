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
#include <Quaternion.h>
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

	[StructLayout(LayoutKind::Sequential)]
	public value class Quaternion
	{

#pragma warning(pop)

		public:
			float X;
			float Y;
			float Z;
			float W;

			Quaternion(bool init);
			Quaternion(float a, float b, float c, float d);
			Quaternion(IntPtr pointer);

			virtual bool Equals(Object ^other) override;
			virtual int GetHashCode() override;

			Quaternion Conjugate();
			void Scale(float s);
			void MakeIdentity();
			void Set(float a, float b, float c, float d);
			void Set(float a, float b, float c);
			void Set(float a, float b);
			void Set(float a);
			void Set();
			Vector3 RotateVector(Vector3 v);

			static Quaternion operator*(Vector3 a, Quaternion b);
			static Quaternion operator*(float scl, Quaternion a);
			static Quaternion operator*(Quaternion a, float scl);
			static Quaternion operator*(Quaternion a, Quaternion b);
			static Quaternion operator/(Quaternion a, Quaternion b);

			static Quaternion Inverse(Quaternion a);

			property float I
			{
				float get();
				void set(float value);
			}

			property float J
			{
				float get();
				void set(float value);
			}

			property float K
			{
				float get();
				void set(float value);
			}

			property float T
			{
				float get();
				void set(float value);
			}

			property float default[int]
			{
				float get(int index);
				void set(int index, float value);
			}

			property bool IsValid
			{
				bool get();
			}

			static property Quaternion Identity
			{
				Quaternion get();
			}

		internal:
			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void ManagedToUnmanagedQuaternion(Quaternion %managed, ::Quaternion &result)
			{
				result.X = managed.X;
				result.Y = managed.Y;
				result.Z = managed.Z;
				result.W = managed.W;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void UnmanagedToManagedQuaternion(const ::Quaternion &unmanaged, Quaternion %result)
			{
				result.X = unmanaged.X;
				result.Y = unmanaged.Y;
				result.Z = unmanaged.Z;
				result.W = unmanaged.W;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void ManagedToUnmanagedQuaternion(::Quaternion &result)
			{
				result.X = this->X;
				result.Y = this->Y;
				result.Z = this->Z;
				result.W = this->W;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void UnmanagedToManagedQuaternion(const ::Quaternion &unmanaged)
			{
				this->X = unmanaged.X;
				this->Y = unmanaged.Y;
				this->Z = unmanaged.Z;
				this->W = unmanaged.W;
			}
	};
}