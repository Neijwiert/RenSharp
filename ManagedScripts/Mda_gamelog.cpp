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
#include "Mda_gamelog.h"

#include "Imports.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_gamelog.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DAGameLogGameFeatureClass::DAGameLogGameFeatureClass(IntPtr pointer)
		: DAEventClass(pointer)
	{
		daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
	}

	String^ DAGameLogGameFeatureClass::ToString()
	{
		return daGameFeatureClass->ToString();
	}

	bool DAGameLogGameFeatureClass::Equals(Object^ other)
	{
		if (DAEventClass::Equals(other))
		{
			return true;
		}

		if (ReferenceEquals(other, nullptr))
		{
			return false;
		}

		auto otherUnmanagedObj = dynamic_cast<IUnmanagedObject^>(other);
		if (otherUnmanagedObj == nullptr || otherUnmanagedObj->Pointer.Equals(IntPtr::Zero))
		{
			return false;
		}

		auto otherDAGameFeatureClass = dynamic_cast<IDAGameFeatureClass^>(other);
		if (otherDAGameFeatureClass != nullptr)
		{
			if (daGameFeatureClass->Equals(otherDAGameFeatureClass))
			{
				return true;
			}
		}

		auto otherDAGameLogGameFeatureClass = dynamic_cast<IDAGameLogGameFeatureClass^>(other);
		if (otherDAGameLogGameFeatureClass != nullptr)
		{
			if (DAGameLogGameFeatureClassPointer.Equals(otherDAGameLogGameFeatureClass->DAGameLogGameFeatureClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void DAGameLogGameFeatureClass::Init()
	{
		daGameFeatureClass->Init();
	}

	IRenSharpGameFeatureClass^ DAGameLogGameFeatureClass::AsManagedGameFeature()
	{
		return daGameFeatureClass->AsManagedGameFeature();
	}

	IntPtr DAGameLogGameFeatureClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void DAGameLogGameFeatureClass::Pointer::set(IntPtr value)
	{
		AbstractUnmanagedObject::Pointer::set(value);

		if (Pointer == IntPtr::Zero)
		{
			daGameFeatureClass = nullptr;
		}
		else
		{
			daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
		}
	}

	IntPtr DAGameLogGameFeatureClass::DAGameLogGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAGameLogGameFeatureClassPointer);
	}

	IntPtr DAGameLogGameFeatureClass::DAGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAGameFeatureClassPointer);
	}

	String^ DAGameLogGameFeatureClass::Name::get()
	{
		return daGameFeatureClass->Name;
	}

	IDAGameFeatureFactoryClass^ DAGameLogGameFeatureClass::Factory::get()
	{
		return daGameFeatureClass->Factory;
	}

	void DAGameLogGameFeatureClass::Factory::set(IDAGameFeatureFactoryClass^ value)
	{
		daGameFeatureClass->Factory = value;
	}

	bool DAGameLogGameFeatureClass::IsManagedGameFeature::get()
	{
		return daGameFeatureClass->IsManagedGameFeature;
	}

	::DAEventClass* DAGameLogGameFeatureClass::InternalDAEventClassPointer::get()
	{
		return InternalDAGameLogGameFeatureClassPointer;
	}

	::DAGameFeatureClass* DAGameLogGameFeatureClass::InternalDAGameFeatureClassPointer::get()
	{
		return InternalDAGameLogGameFeatureClassPointer;
	}

	::DAGameLogGameFeatureClass* DAGameLogGameFeatureClass::InternalDAGameLogGameFeatureClassPointer::get()
	{
		return reinterpret_cast<::DAGameLogGameFeatureClass*>(Pointer.ToPointer());
	}
}