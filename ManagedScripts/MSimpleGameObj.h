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

#include "MPhysicalGameObj.h"

#pragma managed(push, off)

class SimpleGameObj;

#pragma managed(pop)

namespace RenSharp
{
	interface class ISimpleGameObjDef;

	public interface class ISimpleGameObj : public IPhysicalGameObj
	{
		property IntPtr SimpleGameObjPointer
		{
			IntPtr get();
		}

		property ISimpleGameObjDef ^Definition
		{
			ISimpleGameObjDef ^get();
		}

		property bool IsHiddenObject
		{
			bool get();
		}
	};

	public ref class SimpleGameObj : public PhysicalGameObj, public ISimpleGameObj
	{
		public:
			SimpleGameObj(IntPtr pointer);

			property IntPtr SimpleGameObjPointer
			{
				virtual IntPtr get() sealed;
			}

#pragma push_macro("new")
#undef new

			property ISimpleGameObjDef ^Definition
			{
				virtual ISimpleGameObjDef ^get() new;
			}

#pragma pop_macro("new")

			property bool IsHiddenObject
			{
				virtual bool get() sealed;
			}

		protected:
			property ::PhysicalGameObj *InternalPhysicalGameObjPointer
			{
				::PhysicalGameObj *get() override;
			}

			property ::SimpleGameObj *InternalSimpleGameObjPointer
			{
				virtual ::SimpleGameObj *get();
			}
	};
}