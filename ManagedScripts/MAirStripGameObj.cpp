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
#include "MAirStripGameObj.h"

#include "MAirStripGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4091 4251 4244 26495 26454)
#include <AirStripGameObj.h>
#include <AirStripGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	AirStripGameObj::AirStripGameObj(IntPtr pointer)
		: VehicleFactoryGameObj(pointer)
	{

	}

	IntPtr AirStripGameObj::AirStripGameObjPointer::get()
	{
		return IntPtr(InternalAirStripGameObjPointer);
	}

	IAirStripGameObjDef ^AirStripGameObj::Definition::get()
	{
		return safe_cast<IAirStripGameObjDef^>(DefinitionClass::CreateDefinitionClassWrapper(&InternalAirStripGameObjPointer->Get_Definition()));
	}

	::VehicleFactoryGameObj *AirStripGameObj::InternalVehicleFactoryGameObjPointer::get()
	{
		return InternalAirStripGameObjPointer;
	}

	::AirStripGameObj *AirStripGameObj::InternalAirStripGameObjPointer::get()
	{
		return reinterpret_cast<::AirStripGameObj *>(Pointer.ToPointer());
	}
}