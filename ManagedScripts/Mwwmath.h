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
#include <wwmath.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	public ref class WWMath abstract sealed
	{
		private:
			static array<float>^ fastAcosTable;
			static array<float>^ fastAsinTable;
			static array<float>^ fastSinTable;
			static array<float>^ fastInvSinTable;

		public:
			literal float Epsilon = WWMATH_EPSILON;
			literal float Epsilon2 = WWMATH_EPSILON2;
			literal float PI = WWMATH_PI;
			literal float FloatMax = WWMATH_FLOAT_MAX;
			literal float FloatMin = WWMATH_FLOAT_MIN;
			literal float FloatTiny = WWMATH_FLOAT_TINY;
			literal float Sqrt2 = WWMATH_SQRT2;
			literal float Sqrt3 = WWMATH_SQRT3;
			literal float OOSqrt2 = WWMATH_OOSQRT2;
			literal float OOSqrt3 = WWMATH_OOSQRT3;
			literal int ArcTableSize = ::ARC_TABLE_SIZE;
			literal int SinTableSize = ::SIN_TABLE_SIZE;

			static WWMath();

			static void Init();
			static void Shutdown();
			static double RadToDeg(double x);
			static double DegToRad(double x);
			static float RadToDeg(float x);
			static float DegToRad(float x);
			static float Fabs(float val);
			static int FloatToIntChop(float f);
			static int FloatToIntFloor(float f);
			static float Cos(float val);
			static float Sin(float val);
			static float Sqrt(float val);
			static float InvSqrt(float a);
			static long FloatToLong(float f);
			static float FastSin(float val);
			static float FastInvSin(float val);
			static float FastCos(float val);
			static float FastInvCos(float val);
			static float FastAcos(float val);
			static float FastAsin(float val);
			static float Acos(float val);
			static float Asin(float val);
			static float Atan(float x);
			static float Atan2(float y, float x);
			static float Sign(float val);
			static float Ceil(float val);
			static float Floor(float val);
			static bool FastIsFloatPositive(float val);
			static float RandomFloat();
			static float RandomFloat(float min, float max);
			static float Clamp(float val, float min, float max);
			static float Clamp(float val, float min);
			static float Clamp(float val);
			static double Clamp(double val, double min, double max);
			static double Clamp(double val, double min);
			static double Clamp(double val);
			static int ClampInt(int val, int min, int max);
			static float Wrap(float val, float min, float max);
			static float Wrap(float val, float min);
			static float Wrap(float val);
			static double Wrap(double val, double min, double max);
			static double Wrap(double val, double min);
			static double Wrap(double val);
			static float Min(float a, float b);
			static float Max(float a, float b);
			static int Lerp(int a, int b, float lerp);
			static long FloatToLong(double f);
			static unsigned char UnitFloatToByte(float f);
			static float ByteToUnitFloat(unsigned char byte);
			static bool IsValidFloat(float x);
			static bool IsValidDouble(double x);

			static property array<float>^ FastAcosTable
			{
				array<float>^ get();
			}

			static property array<float>^ FastAsinTable
			{
				array<float>^ get();
			}

			static property array<float>^ FastSinTable
			{
				array<float>^ get();
			}

			static property array<float>^ FastInvSinTable
			{
				array<float>^ get();
			}
	};
}