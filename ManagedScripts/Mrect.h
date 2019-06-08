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
#include <rect.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace RenSharp
{
	value class Vector2;

	[StructLayout(LayoutKind::Sequential)]
	public value class RectClass
	{
		public:
			float Left;
			float Top;
			float Right;
			float Bottom;

			RectClass(Vector2 topLeft, Vector2 bottomRight);
			RectClass(float newLeft, float newTop, float newRight, float newBottom);
			RectClass(IntPtr pointer);

			void Set(float left, float top, float right, float bottom);
			void Set(Vector2 topLeft, Vector2 bottomRight);
			void Set(RectClass r);
			RectClass ScaleRelativeCenter(float k);
			RectClass Scale(float k);
			RectClass InverseScale(Vector2 k);
			void Inflate(Vector2 o);
			bool Contains(Vector2 pos);
			void SnapToUnits(Vector2 u);

			static RectClass operator*(RectClass r, float k);
			static RectClass operator/(RectClass r, float k);
			static RectClass operator+(RectClass r, Vector2 o);
			static RectClass operator-(RectClass r, Vector2 o);
			static RectClass operator+(RectClass a, RectClass b);

			property Vector2 UpperRight
			{
				Vector2 get();
			}

			property Vector2 LowerLeft
			{
				Vector2 get();
			}

			property float Width
			{
				float get();
			}

			property float Height
			{
				float get();
			}

			property Vector2 Center
			{
				Vector2 get();
			}

			property Vector2 Extent
			{
				Vector2 get();
			}

			property Vector2 UpperLeft
			{
				Vector2 get();
			}

			property Vector2 LowerRight
			{
				Vector2 get();
			}

			property Vector2 Size
			{
				Vector2 get();
			}

		internal:
			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void ManagedToUnmanagedRectClass(RectClass %managed, ::RectClass &result)
			{
				result.Left = managed.Left;
				result.Top = managed.Top;
				result.Right = managed.Right;
				result.Bottom = managed.Bottom;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			static inline void UnmanagedToManagedRectClass(const ::RectClass &unmanaged, RectClass %result)
			{
				result.Left = unmanaged.Left;
				result.Top = unmanaged.Top;
				result.Right = unmanaged.Right;
				result.Bottom = unmanaged.Bottom;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void ManagedToUnmanagedRectClass(::RectClass &result)
			{
				result.Left = Left;
				result.Top = Top;
				result.Right = Right;
				result.Bottom = Bottom;
			}

			[MethodImpl(MethodImplOptions::AggressiveInlining)]
			inline void UnmanagedToManagedRectClass(const ::RectClass &unmanaged)
			{
				Left = unmanaged.Left;
				Top = unmanaged.Top;
				Right = unmanaged.Right;
				Bottom = unmanaged.Bottom;
			}
	};
}