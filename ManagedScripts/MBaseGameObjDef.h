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

#include "MDefinition.h"

#pragma managed(push, off)

class BaseGameObjDef;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IBaseGameObjDef : public IDefinitionClass
	{
		property IntPtr BaseGameObjDefPointer
		{
			IntPtr get();
		}
	};

	public ref class BaseGameObjDef : public DefinitionClass, public IBaseGameObjDef
	{
		public:
			BaseGameObjDef(IntPtr pointer);

			property IntPtr BaseGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::DefinitionClass *InternalDefinitionClassPointer
			{
				::DefinitionClass *get() override;
			}

			property ::BaseGameObjDef *InternalBaseGameObjDefPointer
			{
				virtual ::BaseGameObjDef *get();
			}
	};
}