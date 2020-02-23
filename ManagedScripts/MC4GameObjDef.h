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

#include "MSimpleGameObjDef.h"

#pragma managed(push, off)

class C4GameObjDef;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IC4GameObjDef : public ISimpleGameObjDef
	{
		property IntPtr C4GameObjDefPointer
		{
			IntPtr get();
		}
	};

	public ref class C4GameObjDef : public SimpleGameObjDef, public IC4GameObjDef
	{
		public:
			C4GameObjDef(IntPtr pointer);

			property IntPtr C4GameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::SimpleGameObjDef *InternalSimpleGameObjDefPointer
			{
				::SimpleGameObjDef *get() override;
			}

			property ::C4GameObjDef *InternalC4GameObjDefPointer
			{
				virtual ::C4GameObjDef *get();
			}
	};
}