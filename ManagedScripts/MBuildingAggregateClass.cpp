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
#include "MBuildingAggregateClass.h"

#include "MBuildingAggregateDefClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <BuildingAggregateClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{

#pragma managed(push, off)

	class BuildingAggregateClassHelper : public ::BuildingAggregateClass 
	{
		private:
			BuildingAggregateClassHelper() = default;

		public:
			int& GetCurrentState()
			{
				return CurrentState;
			}
	};

#pragma managed(pop)

	BuildingAggregateClass::BuildingAggregateClass(IntPtr pointer)
		: StaticAnimPhysClass(pointer)
	{

	}

	IntPtr BuildingAggregateClass::BuildingAggregateClassPointer::get()
	{
		return IntPtr(InternalBuildingAggregateClassPointer);
	}

	IBuildingAggregateDefClass^ BuildingAggregateClass::BuildingAggregateDef::get()
	{
		auto result = InternalBuildingAggregateClassPointer->Get_BuildingAggregateDef();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BuildingAggregateDefClass(IntPtr(const_cast<::BuildingAggregateDefClass*>(result)));
		}
	}

	bool BuildingAggregateClass::IsMCT::get()
	{
		return InternalBuildingAggregateClassPointer->Is_MCT();
	}

	::StaticAnimPhysClass *BuildingAggregateClass::InternalStaticAnimPhysClassPointer::get()
	{
		return InternalBuildingAggregateClassPointer;
	}

	::BuildingAggregateClass *BuildingAggregateClass::InternalBuildingAggregateClassPointer::get()
	{
		return reinterpret_cast<::BuildingAggregateClass *>(Pointer.ToPointer());
	}

	int BuildingAggregateClass::CurrentState::get()
	{
		auto helper = reinterpret_cast<BuildingAggregateClassHelper*>(InternalBuildingAggregateClassPointer);

		auto& currentState = helper->GetCurrentState();

		return currentState;
	}

	void BuildingAggregateClass::CurrentState::set(int value)
	{
		auto helper = reinterpret_cast<BuildingAggregateClassHelper*>(InternalBuildingAggregateClassPointer);

		auto& currentState = helper->GetCurrentState();

		currentState = value;
	}
}