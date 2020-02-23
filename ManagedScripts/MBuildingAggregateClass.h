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

#include "MStaticAnimPhysClass.h"

#pragma managed(push, off)

class BuildingAggregateClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IBuildingAggregateDefClass;

	public interface class IBuildingAggregateClass : public IStaticAnimPhysClass
	{
		property IntPtr BuildingAggregateClassPointer
		{
			IntPtr get();
		}

		property IBuildingAggregateDefClass^ BuildingAggregateDef
		{
			IBuildingAggregateDefClass^ get();
		}

		property bool IsMCT
		{
			bool get();
		}
	};

	public ref class BuildingAggregateClass : public StaticAnimPhysClass, public IBuildingAggregateClass
	{
		public:
			BuildingAggregateClass(IntPtr pointer);

			property IntPtr BuildingAggregateClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IBuildingAggregateDefClass^ BuildingAggregateDef
			{
				virtual IBuildingAggregateDefClass^ get() sealed;
			}

			property bool IsMCT
			{
				virtual bool get() sealed;
			}

		protected:
			property ::StaticAnimPhysClass *InternalStaticAnimPhysClassPointer
			{
				::StaticAnimPhysClass *get() override;
			}

			property ::BuildingAggregateClass *InternalBuildingAggregateClassPointer
			{
				virtual ::BuildingAggregateClass *get();
			}

			property int CurrentState
			{
				int get();
				void set(int value);
			}
	};
}