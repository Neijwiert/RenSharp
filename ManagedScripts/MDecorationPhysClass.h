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

#include "MDynamicPhysClass.h"

#pragma managed(push, off)

class DecorationPhysClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IDecorationPhysDefClass;
	value class AABoxClass;

	public interface class IDecorationPhysClass : public IDynamicPhysClass
	{
		property IntPtr DecorationPhysClassPointer
		{
			IntPtr get();
		}

		property IDecorationPhysDefClass^ DecorationPhysDef
		{
			IDecorationPhysDefClass^ get();
		}

		property AABoxClass BoundingBox
		{
			AABoxClass get();
		}
	};

	public ref class DecorationPhysClass : public DynamicPhysClass, public IDecorationPhysClass
	{
		public:
			DecorationPhysClass(IntPtr pointer);

			property IntPtr DecorationPhysClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IDecorationPhysDefClass^ DecorationPhysDef
			{
				virtual IDecorationPhysDefClass^ get() sealed;
			}

			property AABoxClass BoundingBox
			{
				virtual AABoxClass get() sealed;
			}

		protected:
			property ::DynamicPhysClass *InternalDynamicPhysClassPointer
			{
				::DynamicPhysClass *get() override;
			}

			property ::DecorationPhysClass *InternalDecorationPhysClassPointer
			{
				virtual ::DecorationPhysClass *get();
			}
	};
}