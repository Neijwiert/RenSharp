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
#include <Vector3i.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace RenSharp
{
	[StructLayout(LayoutKind::Sequential)]
	public value class Vector3i
	{
		public:
			int I;
			int	J;
			int	K;

			Vector3i(int i, int j, int k);
			Vector3i(IntPtr pointer);

			property int default[int]
			{
				int get(int index);
				void set(int index, int value);
			}

		internal:
			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void ManagedToUnmanagedVector3i(Vector3i% managed, ::Vector3i& result)
			{
				result.I = managed.I;
				result.J = managed.J;
				result.K = managed.K;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void UnmanagedToManagedVector3i(const ::Vector3i& unmanaged, Vector3i%  result)
			{
				result.I = unmanaged.I;
				result.J = unmanaged.J;
				result.K = unmanaged.K;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void ManagedToUnmanagedVector3i(::Vector3i& result)
			{
				result.I = I;
				result.J = J;
				result.K = K;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void UnmanagedToManagedVector3i(const ::Vector3i& unmanaged)
			{
				I = unmanaged.I;
				J = unmanaged.J;
				K = unmanaged.K;
			}
	};

	[StructLayout(LayoutKind::Sequential)]
	public value class Vector3i16
	{
		public:
			unsigned short I;
			unsigned short	J;
			unsigned short	K;

			Vector3i16(unsigned short i, unsigned short j, unsigned short k);
			Vector3i16(IntPtr pointer);

			property unsigned short default[int]
			{
				unsigned short get(int index);
				void set(int index, unsigned short value);
			}

		internal:
			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void ManagedToUnmanagedVector3i16(Vector3i16% managed, ::Vector3i16& result)
			{
				result.I = managed.I;
				result.J = managed.J;
				result.K = managed.K;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void UnmanagedToManagedVector3i16(const ::Vector3i16& unmanaged, Vector3i16%  result)
			{
				result.I = unmanaged.I;
				result.J = unmanaged.J;
				result.K = unmanaged.K;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void ManagedToUnmanagedVector3i16(::Vector3i16& result)
			{
				result.I = I;
				result.J = J;
				result.K = K;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void UnmanagedToManagedVector3i16(const ::Vector3i16& unmanaged)
			{
				I = unmanaged.I;
				J = unmanaged.J;
				K = unmanaged.K;
			}
	};
}