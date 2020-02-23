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
#include "MSimpleGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <SimpleGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	SimpleGameObjDef::SimpleGameObjDef(IntPtr pointer)
		: PhysicalGameObjDef(pointer)
	{

	}

	IntPtr SimpleGameObjDef::SimpleGameObjDefPointer::get()
	{
		return IntPtr(InternalSimpleGameObjDefPointer);
	}

	bool SimpleGameObjDef::IsEditorObject::get()
	{
		return InternalSimpleGameObjDefPointer->IsEditorObject;
	}

	void SimpleGameObjDef::IsEditorObject::set(bool value)
	{
		InternalSimpleGameObjDefPointer->IsEditorObject = value;
	}

	bool SimpleGameObjDef::IsHiddenObject::get()
	{
		return InternalSimpleGameObjDefPointer->IsHiddenObject;
	}

	void SimpleGameObjDef::IsHiddenObject::set(bool value)
	{
		InternalSimpleGameObjDefPointer->IsHiddenObject = value;
	}

	int SimpleGameObjDef::PlayerTerminalType::get()
	{
		return InternalSimpleGameObjDefPointer->PlayerTerminalType;
	}

	void SimpleGameObjDef::PlayerTerminalType::set(int value)
	{
		InternalSimpleGameObjDefPointer->PlayerTerminalType = value;
	}

	::PhysicalGameObjDef *SimpleGameObjDef::InternalPhysicalGameObjDefPointer::get()
	{
		return InternalSimpleGameObjDefPointer;
	}

	::SimpleGameObjDef *SimpleGameObjDef::InternalSimpleGameObjDefPointer::get()
	{
		return reinterpret_cast<::SimpleGameObjDef *>(Pointer.ToPointer());
	}
}