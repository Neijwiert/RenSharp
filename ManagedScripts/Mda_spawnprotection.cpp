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
#include "Mda_spawnprotection.h"

#include "Imports.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_spawnprotection.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DASpawnProtectionGameFeatureClass::DASpawnProtectionGameFeatureClass(IntPtr pointer)
		: DAEventClass(pointer)
	{
		daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
	}

	String^ DASpawnProtectionGameFeatureClass::ToString()
	{
		return daGameFeatureClass->ToString();
	}

	bool DASpawnProtectionGameFeatureClass::Equals(Object^ other)
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

		auto otherDASpawnProtectionGameFeatureClass = dynamic_cast<IDASpawnProtectionGameFeatureClass^>(other);
		if (otherDASpawnProtectionGameFeatureClass != nullptr)
		{
			if (DASpawnProtectionGameFeatureClassPointer.Equals(otherDASpawnProtectionGameFeatureClass->DASpawnProtectionGameFeatureClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void DASpawnProtectionGameFeatureClass::Init()
	{
		daGameFeatureClass->Init();
	}

	IRenSharpGameFeatureClass^ DASpawnProtectionGameFeatureClass::AsManagedGameFeature()
	{
		return daGameFeatureClass->AsManagedGameFeature();
	}

	IntPtr DASpawnProtectionGameFeatureClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void DASpawnProtectionGameFeatureClass::Pointer::set(IntPtr value)
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

	IntPtr DASpawnProtectionGameFeatureClass::DASpawnProtectionGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDASpawnProtectionGameFeatureClassPointer);
	}

	IntPtr DASpawnProtectionGameFeatureClass::DAGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAGameFeatureClassPointer);
	}

	String^ DASpawnProtectionGameFeatureClass::Name::get()
	{
		return daGameFeatureClass->Name;
	}

	IDAGameFeatureFactoryClass^ DASpawnProtectionGameFeatureClass::Factory::get()
	{
		return daGameFeatureClass->Factory;
	}

	void DASpawnProtectionGameFeatureClass::Factory::set(IDAGameFeatureFactoryClass^ value)
	{
		daGameFeatureClass->Factory = value;
	}

	bool DASpawnProtectionGameFeatureClass::IsManagedGameFeature::get()
	{
		return daGameFeatureClass->IsManagedGameFeature;
	}

	::DAEventClass* DASpawnProtectionGameFeatureClass::InternalDAEventClassPointer::get()
	{
		return InternalDASpawnProtectionGameFeatureClassPointer;
	}

	::DAGameFeatureClass* DASpawnProtectionGameFeatureClass::InternalDAGameFeatureClassPointer::get()
	{
		return InternalDASpawnProtectionGameFeatureClassPointer;
	}

	::DASpawnProtectionGameFeatureClass* DASpawnProtectionGameFeatureClass::InternalDASpawnProtectionGameFeatureClassPointer::get()
	{
		return reinterpret_cast<::DASpawnProtectionGameFeatureClass*>(Pointer.ToPointer());
	}
}