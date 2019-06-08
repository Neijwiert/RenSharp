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

#include "MSmartGameObj.h"

#pragma managed(push, off)

class SAMSiteGameObj;

#pragma managed(pop)

namespace RenSharp
{
	interface class ISAMSiteGameObjDef;

	public interface class ISAMSiteGameObj : public ISmartGameObj
	{
		property IntPtr SAMSiteGameObjPointer
		{
			IntPtr get();
		}

		property ISAMSiteGameObjDef^ Definition
		{
			ISAMSiteGameObjDef^ get();
		}
	};

	public ref class SAMSiteGameObj : public SmartGameObj, public ISAMSiteGameObj
	{
		public:
			SAMSiteGameObj(IntPtr pointer);

			property IntPtr SAMSiteGameObjPointer
			{
				virtual IntPtr get() sealed;
			}

			property ISAMSiteGameObjDef^ Definition
			{
#pragma push_macro("new")
#undef new
				virtual ISAMSiteGameObjDef^ get() new sealed;
#pragma pop_macro("new")
			}

		protected:
			property ::SmartGameObj* InternalSmartGameObjPointer
			{
				::SmartGameObj* get() override;
			}

			property ::SAMSiteGameObj* InternalSAMSiteGameObjPointer
			{
				virtual ::SAMSiteGameObj* get();
			}
	};
}