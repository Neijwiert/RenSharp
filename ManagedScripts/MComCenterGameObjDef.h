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

class ComCenterGameObjDef;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IComCenterGameObjDef : public IBuildingGameObjDef
	{
		literal unsigned int ComCenterGameObjDefClassID = 53256;

		property IntPtr ComCenterGameObjDefPointer
		{
			IntPtr get();
		}
	};

	public ref class ComCenterGameObjDef : public BuildingGameObjDef, public IComCenterGameObjDef
	{
		public:
			ComCenterGameObjDef(IntPtr pointer);

			property IntPtr ComCenterGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::BuildingGameObjDef *InternalBuildingGameObjDefPointer
			{
				::BuildingGameObjDef *get() override;
			}

			property ::ComCenterGameObjDef *InternalComCenterGameObjDefPointer
			{
				virtual ::ComCenterGameObjDef *get();
			}
	};
}