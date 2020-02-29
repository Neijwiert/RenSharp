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

#include "MSmartGameObjDef.h"

#pragma managed(push, off)

class SAMSiteGameObjDef;

#pragma managed(pop)

namespace RenSharp
{
	public interface class ISAMSiteGameObjDef : public ISmartGameObjDef
	{
		literal unsigned int SAMSiteGameObjDefClassID = 12295;

		property IntPtr SAMSiteGameObjDefPointer
		{
			IntPtr get();
		}
	};

	public ref class SAMSiteGameObjDef : public SmartGameObjDef, public ISAMSiteGameObjDef
	{
		public:
			SAMSiteGameObjDef(IntPtr pointer);

			property IntPtr SAMSiteGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::SmartGameObjDef* InternalSmartGameObjDefPointer
			{
				::SmartGameObjDef* get() override;
			}

			property ::SAMSiteGameObjDef* InternalSAMSiteGameObjDefPointer
			{
				virtual ::SAMSiteGameObjDef* get();
			}
	};
}