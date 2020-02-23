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

#include "stdafx.h"
#include "McPlayerKill.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <cPlayerKill.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	cPlayerKill::cPlayerKill(IntPtr pointer)
		: cNetEvent(pointer)
	{

	}

	IntPtr cPlayerKill::cPlayerKillPointer::get()
	{
		return IntPtr(InternalcPlayerKillPointer);
	}

	int cPlayerKill::Id1::get()
	{
		return InternalcPlayerKillPointer->id1;
	}

	void cPlayerKill::Id1::set(int value)
	{
		InternalcPlayerKillPointer->id1 = value;
	}

	int cPlayerKill::Id2::get()
	{
		return InternalcPlayerKillPointer->id2;
	}

	void cPlayerKill::Id2::set(int value)
	{
		InternalcPlayerKillPointer->id2 = value;
	}

	::cNetEvent* cPlayerKill::InternalcNetEventPointer::get()
	{
		return InternalcPlayerKillPointer;
	}

	::cPlayerKill* cPlayerKill::InternalcPlayerKillPointer::get()
	{
		return reinterpret_cast<::cPlayerKill*>(Pointer.ToPointer());
	}
}