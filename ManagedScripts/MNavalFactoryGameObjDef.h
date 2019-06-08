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

#include "MBuildingGameObjDef.h"

#pragma managed(push, off)

class NavalFactoryGameObjDef;

#pragma managed(pop)

namespace RenSharp
{
	public interface class INavalFactoryGameObjDef : public IBuildingGameObjDef
	{
		property IntPtr NavalFactoryGameObjDefPointer
		{
			IntPtr get();
		}

		property float Timer
		{
			float get();
			void set(float value);
		}

		property int ConstructionZone1DefId
		{
			int get();
			void set(int value);
		}

		property int ConstructionZone2DefId
		{
			int get();
			void set(int value);
		}

		property int ConstructionZone3DefId
		{
			int get();
			void set(int value);
		}

		property int ConstructionZone4DefId
		{
			int get();
			void set(int value);
		}

		property int ConstructionZone5DefId
		{
			int get();
			void set(int value);
		}

		property int ConstructionZone6DefId
		{
			int get();
			void set(int value);
		}
	};

	public ref class NavalFactoryGameObjDef : public BuildingGameObjDef, public INavalFactoryGameObjDef
	{
		public:
			NavalFactoryGameObjDef(IntPtr pointer);

			property IntPtr NavalFactoryGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

			property float Timer
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int ConstructionZone1DefId
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int ConstructionZone2DefId
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int ConstructionZone3DefId
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int ConstructionZone4DefId
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int ConstructionZone5DefId
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int ConstructionZone6DefId
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

		protected:
			property ::BuildingGameObjDef *InternalBuildingGameObjDefPointer
			{
				::BuildingGameObjDef *get() override;
			}

			property ::NavalFactoryGameObjDef *InternalNavalFactoryGameObjDefPointer
			{
				virtual ::NavalFactoryGameObjDef *get();
			}
	};
}