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
#include "MTwiddlerClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <TwiddlerClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	TwiddlerClass::TwiddlerClass(IntPtr pointer)
		: DefinitionClass(pointer)
	{

	}

	IDefinitionClass^ TwiddlerClass::Twiddle()
	{
		auto defPtr = InternalTwiddlerClassPointer->Twiddle();
		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			auto result = DefinitionClass::CreateDefinitionClassWrapper(defPtr);
			if (result == nullptr)
			{
				result = gcnew DefinitionClass(IntPtr(const_cast<::DefinitionClass*>(defPtr)));
			}

			return result;
		}
	}

	IntPtr TwiddlerClass::TwiddlerClassPointer::get()
	{
		return IntPtr(InternalTwiddlerClassPointer);
	}

	uint32 TwiddlerClass::IndirectClassID::get()
	{
		return InternalTwiddlerClassPointer->Get_Indirect_Class_ID();
	}

	void TwiddlerClass::IndirectClassID::set(uint32 value)
	{
		InternalTwiddlerClassPointer->Set_Indirect_Class_ID(value);
	}

	::DefinitionClass* TwiddlerClass::InternalDefinitionClassPointer::get()
	{
		return InternalTwiddlerClassPointer;
	}

	::TwiddlerClass* TwiddlerClass::InternalTwiddlerClassPointer::get()
	{
		return reinterpret_cast<::TwiddlerClass*>(Pointer.ToPointer());
	}
}