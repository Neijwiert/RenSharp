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
#include "McNetEvent.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <cNetEvent.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	cNetEvent::cNetEvent(IntPtr pointer)
		: NetworkObjectClass(pointer)
	{

	}

	void cNetEvent::Act()
	{
		InternalcNetEventPointer->Act();
	}

	void cNetEvent::SetObjectDirtyBitForRevision(uint revision, DirtyBit dirtyBit, bool onoff)
	{
		InternalcNetEventPointer->Set_Object_Dirty_Bit_For_Revision(revision, static_cast<::NetworkObjectClass::DIRTY_BIT>(dirtyBit), onoff);
	}

	IntPtr cNetEvent::cNetEventPointer::get()
	{
		return IntPtr(InternalcNetEventPointer);
	}

	::NetworkObjectClass *cNetEvent::InternalNetworkObjectClassPointer::get()
	{
		return InternalcNetEventPointer;
	}

	::cNetEvent *cNetEvent::InternalcNetEventPointer::get()
	{
		return reinterpret_cast<::cNetEvent *>(Pointer.ToPointer());
	}
}