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
#include "MScriptableGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <ScriptableGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MStringClassDynamicVectorClass.h"

namespace RenSharp
{
	ScriptableGameObjDef::ScriptableGameObjDef(IntPtr pointer)
		: BaseGameObjDef(pointer)
	{

	}

	IntPtr ScriptableGameObjDef::ScriptableGameObjDefPointer::get()
	{
		return IntPtr(InternalScriptableGameObjDefPointer);
	}

	IDynamicVectorClass<String ^> ^ScriptableGameObjDef::ScriptNameList::get()
	{
		return gcnew StringClassDynamicVectorClass(IntPtr(&InternalScriptableGameObjDefPointer->ScriptNameList));
	}

	void ScriptableGameObjDef::ScriptNameList::set(IDynamicVectorClass<String ^> ^value)
	{
		if (value == nullptr || value->Pointer.ToPointer())
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalScriptableGameObjDefPointer->ScriptNameList = *reinterpret_cast<::DynamicVectorClass<StringClass> *>(value->Pointer.ToPointer());
	}

	IDynamicVectorClass<String ^> ^ScriptableGameObjDef::ScriptParameterList::get()
	{
		return gcnew StringClassDynamicVectorClass(IntPtr(&InternalScriptableGameObjDefPointer->ScriptParameterList));
	}

	void ScriptableGameObjDef::ScriptParameterList::set(IDynamicVectorClass<String ^> ^value)
	{
		if (value == nullptr || value->Pointer.ToPointer())
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalScriptableGameObjDefPointer->ScriptParameterList = *reinterpret_cast<::DynamicVectorClass<StringClass> *>(value->Pointer.ToPointer());
	}

	::BaseGameObjDef *ScriptableGameObjDef::InternalBaseGameObjDefPointer::get()
	{
		return InternalScriptableGameObjDefPointer;
	}

	::ScriptableGameObjDef *ScriptableGameObjDef::InternalScriptableGameObjDefPointer::get()
	{
		return reinterpret_cast<::ScriptableGameObjDef *>(Pointer.ToPointer());
	}
}