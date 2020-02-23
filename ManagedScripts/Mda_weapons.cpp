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
#include "Mda_weapons.h"

#include "Imports.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_weapons.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DAWeaponsGameFeatureClass::DAWeaponsGameFeatureClass(IntPtr pointer)
		: DAEventClass(pointer)
	{
		daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
	}

	String^ DAWeaponsGameFeatureClass::ToString()
	{
		return daGameFeatureClass->ToString();
	}

	bool DAWeaponsGameFeatureClass::Equals(Object^ other)
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

		auto otherDAWeaponsGameFeatureClass = dynamic_cast<IDAWeaponsGameFeatureClass^>(other);
		if (otherDAWeaponsGameFeatureClass != nullptr)
		{
			if (DAWeaponsGameFeatureClassPointer.Equals(otherDAWeaponsGameFeatureClass->DAWeaponsGameFeatureClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void DAWeaponsGameFeatureClass::Init()
	{
		daGameFeatureClass->Init();
	}

	IRenSharpGameFeatureClass^ DAWeaponsGameFeatureClass::AsManagedGameFeature()
	{
		return daGameFeatureClass->AsManagedGameFeature();
	}

	IntPtr DAWeaponsGameFeatureClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void DAWeaponsGameFeatureClass::Pointer::set(IntPtr value)
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

	IntPtr DAWeaponsGameFeatureClass::DAWeaponsGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAWeaponsGameFeatureClassPointer);
	}

	IntPtr DAWeaponsGameFeatureClass::DAGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAGameFeatureClassPointer);
	}

	String^ DAWeaponsGameFeatureClass::Name::get()
	{
		return daGameFeatureClass->Name;
	}

	IDAGameFeatureFactoryClass^ DAWeaponsGameFeatureClass::Factory::get()
	{
		return daGameFeatureClass->Factory;
	}

	void DAWeaponsGameFeatureClass::Factory::set(IDAGameFeatureFactoryClass^ value)
	{
		daGameFeatureClass->Factory = value;
	}

	bool DAWeaponsGameFeatureClass::IsManagedGameFeature::get()
	{
		return daGameFeatureClass->IsManagedGameFeature;
	}

	::DAEventClass* DAWeaponsGameFeatureClass::InternalDAEventClassPointer::get()
	{
		return InternalDAWeaponsGameFeatureClassPointer;
	}

	::DAGameFeatureClass* DAWeaponsGameFeatureClass::InternalDAGameFeatureClassPointer::get()
	{
		return InternalDAWeaponsGameFeatureClassPointer;
	}

	::DAWeaponsGameFeatureClass* DAWeaponsGameFeatureClass::InternalDAWeaponsGameFeatureClassPointer::get()
	{
		return reinterpret_cast<::DAWeaponsGameFeatureClass*>(Pointer.ToPointer());
	}
}