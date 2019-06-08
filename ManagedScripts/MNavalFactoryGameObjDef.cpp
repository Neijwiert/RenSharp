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
#include "MNavalFactoryGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <NavalFactoryGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	NavalFactoryGameObjDef::NavalFactoryGameObjDef(IntPtr pointer)
		: BuildingGameObjDef(pointer)
	{

	}

	IntPtr NavalFactoryGameObjDef::NavalFactoryGameObjDefPointer::get()
	{
		return IntPtr(InternalNavalFactoryGameObjDefPointer);
	}

	float NavalFactoryGameObjDef::Timer::get()
	{
		return InternalNavalFactoryGameObjDefPointer->Timer;
	}

	void NavalFactoryGameObjDef::Timer::set(float value)
	{
		InternalNavalFactoryGameObjDefPointer->Timer = value;
	}

	int NavalFactoryGameObjDef::ConstructionZone1DefId::get()
	{
		return InternalNavalFactoryGameObjDefPointer->ConstructionZone1DefId;
	}

	void NavalFactoryGameObjDef::ConstructionZone1DefId::set(int value)
	{
		InternalNavalFactoryGameObjDefPointer->ConstructionZone1DefId = value;
	}

	int NavalFactoryGameObjDef::ConstructionZone2DefId::get()
	{
		return InternalNavalFactoryGameObjDefPointer->ConstructionZone2DefId;
	}

	void NavalFactoryGameObjDef::ConstructionZone2DefId::set(int value)
	{
		InternalNavalFactoryGameObjDefPointer->ConstructionZone2DefId = value;
	}

	int NavalFactoryGameObjDef::ConstructionZone3DefId::get()
	{
		return InternalNavalFactoryGameObjDefPointer->ConstructionZone3DefId;
	}

	void NavalFactoryGameObjDef::ConstructionZone3DefId::set(int value)
	{
		InternalNavalFactoryGameObjDefPointer->ConstructionZone3DefId = value;
	}

	int NavalFactoryGameObjDef::ConstructionZone4DefId::get()
	{
		return InternalNavalFactoryGameObjDefPointer->ConstructionZone4DefId;
	}

	void NavalFactoryGameObjDef::ConstructionZone4DefId::set(int value)
	{
		InternalNavalFactoryGameObjDefPointer->ConstructionZone4DefId = value;
	}

	int NavalFactoryGameObjDef::ConstructionZone5DefId::get()
	{
		return InternalNavalFactoryGameObjDefPointer->ConstructionZone5DefId;
	}

	void NavalFactoryGameObjDef::ConstructionZone5DefId::set(int value)
	{
		InternalNavalFactoryGameObjDefPointer->ConstructionZone5DefId = value;
	}

	int NavalFactoryGameObjDef::ConstructionZone6DefId::get()
	{
		return InternalNavalFactoryGameObjDefPointer->ConstructionZone6DefId;
	}

	void NavalFactoryGameObjDef::ConstructionZone6DefId::set(int value)
	{
		InternalNavalFactoryGameObjDefPointer->ConstructionZone6DefId = value;
	}

	::BuildingGameObjDef *NavalFactoryGameObjDef::InternalBuildingGameObjDefPointer::get()
	{
		return InternalNavalFactoryGameObjDefPointer;
	}

	::NavalFactoryGameObjDef *NavalFactoryGameObjDef::InternalNavalFactoryGameObjDefPointer::get()
	{
		return reinterpret_cast<::NavalFactoryGameObjDef *>(Pointer.ToPointer());
	}
}