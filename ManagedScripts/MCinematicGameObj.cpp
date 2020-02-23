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
#include "MCinematicGameObj.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <CinematicGameObj.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MCinematicGameObjDef.h"

namespace RenSharp
{
	CinematicGameObj::CinematicGameObj(IntPtr pointer)
		: ArmedGameObj(pointer)
	{

	}

	ICinematicGameObj ^CinematicGameObj::AsCinematicGameObj()
	{
		return this;
	}

	IntPtr CinematicGameObj::CinematicGameObjPointer::get()
	{
		return IntPtr(InternalCinematicGameObjPointer);
	}

	ICinematicGameObjDef ^CinematicGameObj::Definition::get()
	{
		return gcnew CinematicGameObjDef(IntPtr(const_cast<::CinematicGameObjDef *>(&InternalCinematicGameObjPointer->Get_Definition())));
	}

	::ArmedGameObj *CinematicGameObj::InternalArmedGameObjPointer::get()
	{
		return InternalCinematicGameObjPointer;
	}

	::CinematicGameObj *CinematicGameObj::InternalCinematicGameObjPointer::get()
	{
		return reinterpret_cast<::CinematicGameObj *>(Pointer.ToPointer());
	}
}