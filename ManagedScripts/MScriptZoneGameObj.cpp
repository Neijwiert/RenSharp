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
#include "MScriptZoneGameObj.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <ScriptZoneGameObj.h>
#include <ScriptZoneGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MScriptZoneGameObjDef.h"
#include "MVector3.h"
#include "Mobboxclass.h"

namespace RenSharp
{
	ScriptZoneGameObj::ScriptZoneGameObj(IntPtr pointer)
		: ScriptableGameObj(pointer)
	{

	}

	IScriptZoneGameObj ^ScriptZoneGameObj::AsScriptZoneGameObj()
	{
		return this;
	}

	IntPtr ScriptZoneGameObj::ScriptZoneGameObjPointer::get()
	{
		return IntPtr(InternalScriptZoneGameObjPointer);
	}

	IScriptZoneGameObjDef ^ScriptZoneGameObj::Definition::get()
	{
		return safe_cast<IScriptZoneGameObjDef^>(DefinitionClass::CreateDefinitionClassWrapper(&InternalScriptZoneGameObjPointer->Get_Definition()));
	}

	OBBoxClass ScriptZoneGameObj::BoundingBox::get()
	{
		OBBoxClass result;
		OBBoxClass::UnmanagedToManagedOBBoxClass(InternalScriptZoneGameObjPointer->Get_Bounding_Box(), result);

		return result;
	}

	void ScriptZoneGameObj::BoundingBox::set(OBBoxClass value)
	{
		::OBBoxClass tmp;
		OBBoxClass::ManagedToUnmanagedOBBoxClass(value, tmp);

		InternalScriptZoneGameObjPointer->Set_Bounding_Box(tmp);
	}

	int ScriptZoneGameObj::PlayerType::get()
	{
		return InternalScriptZoneGameObjPointer->Get_Player_Type();
	}

	void ScriptZoneGameObj::PlayerType::set(int value)
	{
		InternalScriptZoneGameObjPointer->Set_Player_Type(value);
	}

	bool ScriptZoneGameObj::IsEnvironmentZone::get()
	{
		return InternalScriptZoneGameObjPointer->Is_Environment_Zone();
	}

	::ScriptableGameObj *ScriptZoneGameObj::InternalScriptableGameObjPointer::get()
	{
		return InternalScriptZoneGameObjPointer;
	}

	::ScriptZoneGameObj *ScriptZoneGameObj::InternalScriptZoneGameObjPointer::get()
	{
		return reinterpret_cast<::ScriptZoneGameObj *>(Pointer.ToPointer());
	}
}