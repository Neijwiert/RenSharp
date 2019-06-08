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

#include "stdafx.h"
#include "McPurchaseResponseEvent.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <cPurchaseResponseEvent.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	cPurchaseResponseEvent::cPurchaseResponseEvent(IntPtr pointer)
		: cNetEvent(pointer)
	{

	}

	IntPtr cPurchaseResponseEvent::cPurchaseResponseEventPointer::get()
	{
		return IntPtr(InternalcPurchaseResponseEventPointer);
	}

	::cNetEvent* cPurchaseResponseEvent::InternalcNetEventPointer::get()
	{
		return InternalcPurchaseResponseEventPointer;
	}

	::cPurchaseResponseEvent* cPurchaseResponseEvent::InternalcPurchaseResponseEventPointer::get()
	{
		return reinterpret_cast<::cPurchaseResponseEvent*>(Pointer.ToPointer());
	}
}