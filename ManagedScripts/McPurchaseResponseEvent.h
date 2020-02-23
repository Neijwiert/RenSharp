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

#include "McNetEvent.h"

#pragma managed(push, off)

class cPurchaseResponseEvent;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IcPurchaseResponseEvent : public IcNetEvent
	{
		property IntPtr cPurchaseResponseEventPointer
		{
			IntPtr get();
		}
	};

	public ref class cPurchaseResponseEvent : public cNetEvent, public IcPurchaseResponseEvent
	{
		public:
			cPurchaseResponseEvent(IntPtr pointer);

			property IntPtr cPurchaseResponseEventPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::cNetEvent* InternalcNetEventPointer
			{
				::cNetEvent* get() override;
			}

			property ::cPurchaseResponseEvent* InternalcPurchaseResponseEventPointer
			{
				virtual ::cPurchaseResponseEvent* get();
			}
	};
}