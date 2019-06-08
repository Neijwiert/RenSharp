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

#include "stdafx.h"
#include "Mwwmath.h"

#include "Imports.h"

namespace RenSharp
{
	static WWMath::WWMath()
	{
		fastAcosTable = gcnew array<float>(::ARC_TABLE_SIZE);
		pin_ptr<float> pinnedFastAcosTable = &fastAcosTable[0];
		float* fastAcosTablePtr = pinnedFastAcosTable;
		std::memcpy(fastAcosTablePtr, ::_FastAcosTable, ::ARC_TABLE_SIZE * sizeof(float));

		fastAsinTable = gcnew array<float>(::ARC_TABLE_SIZE);
		pin_ptr<float> pinnedFastAsinTable = &fastAsinTable[0];
		float* fastAsinTablePtr = pinnedFastAsinTable;
		std::memcpy(fastAsinTablePtr, ::_FastAsinTable, ::ARC_TABLE_SIZE * sizeof(float));

		fastSinTable = gcnew array<float>(::SIN_TABLE_SIZE);
		pin_ptr<float> pinnedFastSinTable = &fastSinTable[0];
		float* fastSinTablePtr = pinnedFastSinTable;
		std::memcpy(fastSinTablePtr, ::_FastSinTable, ::SIN_TABLE_SIZE * sizeof(float));

		fastInvSinTable = gcnew array<float>(::SIN_TABLE_SIZE);
		pin_ptr<float> pinnedFastInvSinTable = &fastInvSinTable[0];
		float* fastInvSinTablePtr = pinnedFastInvSinTable;
		std::memcpy(fastInvSinTablePtr, ::_FastInvSinTable, ::SIN_TABLE_SIZE * sizeof(float));
	}

	void WWMath::Init()
	{
		::WWMath::Init();
	}

	void WWMath::Shutdown()
	{
		::WWMath::Shutdown();
	}

	double WWMath::RadToDeg(double x)
	{
		return RAD_TO_DEG(x);
	}

	double WWMath::DegToRad(double x)
	{
		return DEG_TO_RAD(x);
	}

	float WWMath::RadToDeg(float x)
	{
		return RAD_TO_DEGF(x);
	}

	float WWMath::DegToRad(float x)
	{
		return DEG_TO_RADF(x);
	}

	float WWMath::Fabs(float val)
	{
		return ::WWMath::Fabs(val);
	}

	int WWMath::FloatToIntChop(float f)
	{
		return ::WWMath::Float_To_Int_Chop(f);
	}

	int WWMath::FloatToIntFloor(float f)
	{
		return ::WWMath::Float_To_Int_Floor(f);
	}

	float WWMath::Cos(float val)
	{
		return ::WWMath::Cos(val);
	}

	float WWMath::Sin(float val)
	{
		return ::WWMath::Sin(val);
	}

	float WWMath::Sqrt(float val)
	{
		return ::WWMath::Sqrt(val);
	}

	float WWMath::InvSqrt(float a)
	{
		return Imports::WWMathInvSqrt(a);
	}

	long WWMath::FloatToLong(float f)
	{
		return ::WWMath::Float_To_Long(f);
	}

	float WWMath::FastSin(float val)
	{
		return ::WWMath::Fast_Sin(val);
	}

	float WWMath::FastInvSin(float val)
	{
		return ::WWMath::Fast_Inv_Sin(val);
	}

	float WWMath::FastCos(float val)
	{
		return ::WWMath::Fast_Cos(val);
	}

	float WWMath::FastInvCos(float val)
	{
		return ::WWMath::Fast_Inv_Cos(val);
	}

	float WWMath::FastAcos(float val)
	{
		return ::WWMath::Fast_Acos(val);
	}

	float WWMath::FastAsin(float val)
	{
		return ::WWMath::Fast_Asin(val);
	}

	float WWMath::Acos(float val)
	{
		return ::WWMath::Acos(val);
	}

	float WWMath::Asin(float val)
	{
		return ::WWMath::Asin(val);
	}

	float WWMath::Atan(float x)
	{
		return ::WWMath::Atan(x);
	}

	float WWMath::Atan2(float y, float x)
	{
		return ::WWMath::Atan2(y, x);
	}

	float WWMath::Sign(float val)
	{
		return ::WWMath::Sign(val);
	}

	float WWMath::Ceil(float val)
	{
		return ::WWMath::Ceil(val);
	}

	float WWMath::Floor(float val)
	{
		return ::WWMath::Floor(val);
	}

	bool WWMath::FastIsFloatPositive(float val)
	{
		return ::WWMath::Fast_Is_Float_Positive(val);
	}

	float WWMath::RandomFloat()
	{
		return ::WWMath::Random_Float();
	}

	float WWMath::RandomFloat(float min, float max)
	{
		return ::WWMath::Random_Float(min, max);
	}

	float WWMath::Clamp(float val, float min, float max)
	{
		return ::WWMath::Clamp(val, min, max);
	}

	float WWMath::Clamp(float val, float min)
	{
		return ::WWMath::Clamp(val, min);
	}

	float WWMath::Clamp(float val)
	{
		return ::WWMath::Clamp(val);
	}

	double WWMath::Clamp(double val, double min, double max)
	{
		return ::WWMath::Clamp(val, min, max);
	}

	double WWMath::Clamp(double val, double min)
	{
		return ::WWMath::Clamp(val, min);
	}

	double WWMath::Clamp(double val)
	{
		return ::WWMath::Clamp(val);
	}

	int WWMath::ClampInt(int val, int min, int max)
	{
		return ::WWMath::Clamp_Int(val, min, max);
	}

	float WWMath::Wrap(float val, float min, float max)
	{
		return ::WWMath::Wrap(val, min, max);
	}

	float WWMath::Wrap(float val, float min)
	{
		return ::WWMath::Wrap(val, min);
	}

	float WWMath::Wrap(float val)
	{
		return ::WWMath::Wrap(val);
	}

	double WWMath::Wrap(double val, double min, double max)
	{
		return ::WWMath::Wrap(val, min, max);
	}

	double WWMath::Wrap(double val, double min)
	{
		return ::WWMath::Wrap(val, min);
	}

	double WWMath::Wrap(double val)
	{
		return ::WWMath::Wrap(val);
	}

	float WWMath::Min(float a, float b)
	{
		return ::WWMath::Min(a, b);
	}

	float WWMath::Max(float a, float b)
	{
		return ::WWMath::Max(a, b);
	}

	int WWMath::Lerp(int a, int b, float lerp)
	{
		return ::WWMath::Lerp(a, b, lerp);
	}

	long WWMath::FloatToLong(double f)
	{
		return ::WWMath::Float_To_Long(f);
	}

	unsigned char WWMath::UnitFloatToByte(float f)
	{
		return ::WWMath::Unit_Float_To_Byte(f);
	}

	float WWMath::ByteToUnitFloat(unsigned char byte)
	{
		return ::WWMath::Byte_To_Unit_Float(byte);
	}

	bool WWMath::IsValidFloat(float x)
	{
		return ::WWMath::Is_Valid_Float(x);
	}

	bool WWMath::IsValidDouble(double x)
	{
		return ::WWMath::Is_Valid_Double(x);
	}

	array<float>^ WWMath::FastAcosTable::get()
	{
		return fastAcosTable;
	}

	array<float>^ WWMath::FastAsinTable::get()
	{
		return fastAsinTable;
	}

	array<float>^ WWMath::FastSinTable::get()
	{
		return fastSinTable;
	}

	array<float>^ WWMath::FastInvSinTable::get()
	{
		return fastInvSinTable;
	}
}