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
#include "MDefinitionFactoryClass.h"

#include "MDefinition.h"
#include "UnmanagedContainer.h"
#include "Imports.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <DefinitionFactoryClass.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Text;

namespace RenSharp
{
	DefinitionFactoryClass::DefinitionFactoryClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	String^ DefinitionFactoryClass::ToString()
	{
		StringBuilder^ builder = gcnew StringBuilder();
		builder->Append(Name);

		return builder->ToString();
	}

	bool DefinitionFactoryClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDefinitionFactoryClass^ otherThis = dynamic_cast<IDefinitionFactoryClass^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DefinitionFactoryClassPointer.Equals(otherThis->DefinitionFactoryClassPointer);
	}

	IUnmanagedContainer<IDefinitionClass^>^ DefinitionFactoryClass::Create()
	{
		auto defPtr = InternalDefinitionFactoryClassPointer->Create();
		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew UnmanagedContainer<IDefinitionClass^>(DefinitionClass::CreateDefinitionClassWrapper(defPtr));
		}
	}

	IntPtr DefinitionFactoryClass::DefinitionFactoryClassPointer::get()
	{
		return IntPtr(InternalDefinitionFactoryClassPointer);
	}

	String^ DefinitionFactoryClass::Name::get()
	{
		auto result = InternalDefinitionFactoryClassPointer->Get_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	uint32 DefinitionFactoryClass::ClassID::get()
	{
		return InternalDefinitionFactoryClassPointer->Get_Class_ID();
	}

	bool DefinitionFactoryClass::IsDisplayed::get()
	{
		return InternalDefinitionFactoryClassPointer->Is_Displayed();
	}

	bool DefinitionFactoryClass::InternalDestroyPointer()
	{
		Imports::DestroyDefinitionFactoryClass(InternalDefinitionFactoryClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DefinitionFactoryClass* DefinitionFactoryClass::InternalDefinitionFactoryClassPointer::get()
	{
		return reinterpret_cast<::DefinitionFactoryClass*>(Pointer.ToPointer());
	}
}