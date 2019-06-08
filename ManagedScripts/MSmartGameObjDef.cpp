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
#include "MSmartGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <SmartGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	SmartGameObjDef::SmartGameObjDef(IntPtr pointer)
		: ArmedGameObjDef(pointer)
	{

	}

	IntPtr SmartGameObjDef::SmartGameObjDefPointer::get()
	{
		return IntPtr(InternalSmartGameObjDefPointer);
	}

	float SmartGameObjDef::SightRange::get()
	{
		return InternalSmartGameObjDefPointer->SightRange;
	}

	void SmartGameObjDef::SightRange::set(float value)
	{
		InternalSmartGameObjDefPointer->SightRange = value;
	}

	float SmartGameObjDef::SightArc::get()
	{
		return InternalSmartGameObjDefPointer->SightArc;
	}

	void SmartGameObjDef::SightArc::set(float value)
	{
		InternalSmartGameObjDefPointer->SightArc = value;
	}

	float SmartGameObjDef::ListenerScale::get()
	{
		return InternalSmartGameObjDefPointer->ListenerScale;
	}

	void SmartGameObjDef::ListenerScale::set(float value)
	{
		InternalSmartGameObjDefPointer->ListenerScale = value;
	}

	bool SmartGameObjDef::IsStealthUnit::get()
	{
		return InternalSmartGameObjDefPointer->IsStealthUnit;
	}

	void SmartGameObjDef::IsStealthUnit::set(bool value)
	{
		InternalSmartGameObjDefPointer->IsStealthUnit = value;
	}

	::ArmedGameObjDef *SmartGameObjDef::InternalArmedGameObjDefPointer::get()
	{
		return InternalSmartGameObjDefPointer;
	}

	::SmartGameObjDef *SmartGameObjDef::InternalSmartGameObjDefPointer::get()
	{
		return reinterpret_cast<::SmartGameObjDef *>(Pointer.ToPointer());
	}
}