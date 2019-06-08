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
#include "MBuildingAggregateDefClass.h"

namespace RenSharp
{
	BuildingAggregateDefClass::BuildingAggregateDefClass(IntPtr pointer)
		: StaticAnimPhysDefClass(pointer)
	{

	}

	IntPtr BuildingAggregateDefClass::BuildingAggregateDefClassPointer::get()
	{
		return IntPtr(InternalBuildingAggregateDefClassPointer);
	}

	::StaticAnimPhysDefClass* BuildingAggregateDefClass::InternalStaticAnimPhysDefClassPointer::get()
	{
		return InternalBuildingAggregateDefClassPointer;
	}

	::BuildingAggregateDefClass* BuildingAggregateDefClass::InternalBuildingAggregateDefClassPointer::get()
	{
		return reinterpret_cast<::BuildingAggregateDefClass*>(Pointer.ToPointer());
	}

	int BuildingAggregateDefClass::AnimLogicMode::get()
	{
		auto helper = reinterpret_cast<BuildingAggregateDefClassHelper*>(InternalBuildingAggregateDefClassPointer);

		auto& animLogicMode = helper->GetAnimLogicMode();

		return animLogicMode;
	}

	void BuildingAggregateDefClass::AnimLogicMode::set(int value)
	{
		auto helper = reinterpret_cast<BuildingAggregateDefClassHelper*>(InternalBuildingAggregateDefClassPointer);

		auto& animLogicMode = helper->GetAnimLogicMode();

		animLogicMode = value;
	}

	bool BuildingAggregateDefClass::IsMCT::get()
	{
		auto helper = reinterpret_cast<BuildingAggregateDefClassHelper*>(InternalBuildingAggregateDefClassPointer);

		auto& isMCT = helper->GetIsMCT();

		return isMCT;
	}

	void BuildingAggregateDefClass::IsMCT::set(bool value)
	{
		auto helper = reinterpret_cast<BuildingAggregateDefClassHelper*>(InternalBuildingAggregateDefClassPointer);

		auto& isMCT = helper->GetIsMCT();

		isMCT = value;
	}

	array<int>^ BuildingAggregateDefClass::Frame0::get()
	{
		auto helper = reinterpret_cast<BuildingAggregateDefClassHelper*>(InternalBuildingAggregateDefClassPointer);

		array<int>^ result = gcnew array<int>(BuildingAggregateDefClassHelper::Frame0SizeCount);

		pin_ptr<int> pinnedResult = &result[0];
		int* resultPtr = pinnedResult;

		helper->GetFrame0(resultPtr);

		return result;
	}

	void BuildingAggregateDefClass::Frame0::set(array<int>^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}
		else if (value->Length != static_cast<int>(BuildingAggregateDefClassHelper::Frame0SizeCount))
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<BuildingAggregateDefClassHelper*>(InternalBuildingAggregateDefClassPointer);

		pin_ptr<int> pinnedValue = &value[0];
		int* valuePtr = pinnedValue;

		helper->SetFrame0(valuePtr);
	}

	array<int>^ BuildingAggregateDefClass::Frame1::get()
	{
		auto helper = reinterpret_cast<BuildingAggregateDefClassHelper*>(InternalBuildingAggregateDefClassPointer);

		array<int>^ result = gcnew array<int>(BuildingAggregateDefClassHelper::Frame1SizeCount);

		pin_ptr<int> pinnedResult = &result[0];
		int* resultPtr = pinnedResult;

		helper->GetFrame1(resultPtr);

		return result;
	}

	void BuildingAggregateDefClass::Frame1::set(array<int>^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}
		else if (value->Length != static_cast<int>(BuildingAggregateDefClassHelper::Frame1SizeCount))
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<BuildingAggregateDefClassHelper*>(InternalBuildingAggregateDefClassPointer);

		pin_ptr<int> pinnedValue = &value[0];
		int* valuePtr = pinnedValue;

		helper->SetFrame1(valuePtr);
	}

	array<bool>^ BuildingAggregateDefClass::AnimationEnabled::get()
	{
		auto helper = reinterpret_cast<BuildingAggregateDefClassHelper*>(InternalBuildingAggregateDefClassPointer);

		array<bool>^ result = gcnew array<bool>(BuildingAggregateDefClassHelper::AnimationEnabledSizeCount);

		pin_ptr<bool> pinnedResult = &result[0];
		bool* resultPtr = pinnedResult;

		helper->GetAnimationEnabled(resultPtr);

		return result;
	}

	void BuildingAggregateDefClass::AnimationEnabled::set(array<bool>^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}
		else if (value->Length != static_cast<int>(BuildingAggregateDefClassHelper::AnimationEnabledSizeCount))
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<BuildingAggregateDefClassHelper*>(InternalBuildingAggregateDefClassPointer);

		pin_ptr<bool> pinnedValue = &value[0];
		bool* valuePtr = pinnedValue;

		helper->SetAnimationEnabled(valuePtr);
	}
}