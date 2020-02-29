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
#include "MSimpleGameObj.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <SimpleGameObj.h>
#include <SimpleGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MSimpleGameObjDef.h"

namespace RenSharp
{
	SimpleGameObj::SimpleGameObj(IntPtr pointer)
		: PhysicalGameObj(pointer)
	{

	}

	ISimpleGameObj ^SimpleGameObj::AsSimpleGameObj()
	{
		return this;
	}

	IntPtr SimpleGameObj::SimpleGameObjPointer::get()
	{
		return IntPtr(InternalSimpleGameObjPointer);
	}

	ISimpleGameObjDef ^SimpleGameObj::Definition::get()
	{
		auto result = DefinitionClass::CreateDefinitionClassWrapper(&InternalSimpleGameObjPointer->Get_Definition());
		if (result != nullptr)
		{
			return safe_cast<ISimpleGameObjDef^>(result);
		}

		return gcnew SimpleGameObjDef(IntPtr(const_cast<::SimpleGameObjDef *>(&InternalSimpleGameObjPointer->Get_Definition())));
	}

	bool SimpleGameObj::IsHiddenObject::get()
	{
		return InternalSimpleGameObjPointer->Is_Hidden_Object();
	}

	::PhysicalGameObj *SimpleGameObj::InternalPhysicalGameObjPointer::get()
	{
		return InternalSimpleGameObjPointer;
	}

	::SimpleGameObj *SimpleGameObj::InternalSimpleGameObjPointer::get()
	{
		return reinterpret_cast<::SimpleGameObj *>(Pointer.ToPointer());
	}
}