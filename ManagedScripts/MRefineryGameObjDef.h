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

#include "MBuildingGameObjDef.h"

#pragma managed(push, off)

class RefineryGameObjDef;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IRefineryGameObjDef : public IBuildingGameObjDef
	{
		property IntPtr RefineryGameObjDefPointer
		{
			IntPtr get();
		}

		property float UnloadTime
		{
			float get();
			void set(float value);
		}

		property float FundsGathered
		{
			float get();
			void set(float value);
		}

		property float FundsDistributedPerSec
		{
			float get();
			void set(float value);
		}

		property int HarvesterDefID
		{
			int get();
			void set(int value);
		}
	};

	public ref class RefineryGameObjDef : public BuildingGameObjDef, public IRefineryGameObjDef
	{
		public:
			RefineryGameObjDef(IntPtr pointer);

			property IntPtr RefineryGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

			property float UnloadTime
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float FundsGathered
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float FundsDistributedPerSec
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int HarvesterDefID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

		protected:
			property ::BuildingGameObjDef *InternalBuildingGameObjDefPointer
			{
				::BuildingGameObjDef *get() override;
			}

			property ::RefineryGameObjDef *InternalRefineryGameObjDefPointer
			{
				virtual ::RefineryGameObjDef *get();
			}
	};
}