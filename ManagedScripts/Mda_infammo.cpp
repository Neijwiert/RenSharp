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
#include "Mda_infammo.h"

#include "Imports.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_infammo.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DAInfiniteAmmoGameFeatureClass::DAInfiniteAmmoGameFeatureClass(IntPtr pointer)
		: DAEventClass(pointer)
	{
		daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
	}

	String^ DAInfiniteAmmoGameFeatureClass::ToString()
	{
		return daGameFeatureClass->ToString();
	}

	bool DAInfiniteAmmoGameFeatureClass::Equals(Object^ other)
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
			if (daGameFeatureClass->DAGameFeatureClassPointer.Equals(otherDAGameFeatureClass->DAGameFeatureClassPointer))
			{
				return true;
			}
		}

		auto otherDAInfiniteAmmoGameFeatureClass = dynamic_cast<IDAInfiniteAmmoGameFeatureClass^>(other);
		if (otherDAInfiniteAmmoGameFeatureClass != nullptr)
		{
			if (DAInfiniteAmmoGameFeatureClassPointer.Equals(otherDAInfiniteAmmoGameFeatureClass->DAInfiniteAmmoGameFeatureClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void DAInfiniteAmmoGameFeatureClass::Init()
	{
		daGameFeatureClass->Init();
	}

	IRenSharpGameFeatureClass^ DAInfiniteAmmoGameFeatureClass::AsManagedGameFeature()
	{
		return daGameFeatureClass->AsManagedGameFeature();
	}

	IntPtr DAInfiniteAmmoGameFeatureClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void DAInfiniteAmmoGameFeatureClass::Pointer::set(IntPtr value)
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

	IntPtr DAInfiniteAmmoGameFeatureClass::DAInfiniteAmmoGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAInfiniteAmmoGameFeatureClassPointer);
	}

	IntPtr DAInfiniteAmmoGameFeatureClass::DAGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAGameFeatureClassPointer);
	}

	String^ DAInfiniteAmmoGameFeatureClass::Name::get()
	{
		return daGameFeatureClass->Name;
	}

	IDAGameFeatureFactoryClass^ DAInfiniteAmmoGameFeatureClass::Factory::get()
	{
		return daGameFeatureClass->Factory;
	}

	void DAInfiniteAmmoGameFeatureClass::Factory::set(IDAGameFeatureFactoryClass^ value)
	{
		daGameFeatureClass->Factory = value;
	}

	bool DAInfiniteAmmoGameFeatureClass::IsManagedGameFeature::get()
	{
		return daGameFeatureClass->IsManagedGameFeature;
	}

	::DAEventClass* DAInfiniteAmmoGameFeatureClass::InternalDAEventClassPointer::get()
	{
		return InternalDAInfiniteAmmoGameFeatureClassPointer;
	}

	::DAGameFeatureClass* DAInfiniteAmmoGameFeatureClass::InternalDAGameFeatureClassPointer::get()
	{
		return InternalDAInfiniteAmmoGameFeatureClassPointer;
	}

	::DAInfiniteAmmoGameFeatureClass* DAInfiniteAmmoGameFeatureClass::InternalDAInfiniteAmmoGameFeatureClassPointer::get()
	{
		return reinterpret_cast<::DAInfiniteAmmoGameFeatureClass*>(Pointer.ToPointer());
	}

	DANoReloadPlayerObserverClass::DANoReloadPlayerObserverClass(IntPtr pointer)
		: DAPlayerObserverClass(pointer)
	{

	}

	IntPtr DANoReloadPlayerObserverClass::DANoReloadPlayerObserverClassPointer::get()
	{
		return IntPtr(InternalDANoReloadPlayerObserverClassPointer);
	}

	::DAPlayerObserverClass* DANoReloadPlayerObserverClass::InternalDAPlayerObserverClassPointer::get()
	{
		return InternalDANoReloadPlayerObserverClassPointer;
	}

	::DANoReloadPlayerObserverClass* DANoReloadPlayerObserverClass::InternalDANoReloadPlayerObserverClassPointer::get()
	{
		return reinterpret_cast<::DANoReloadPlayerObserverClass*>(Pointer.ToPointer());
	}

	DANoReloadGameFeatureClass::DANoReloadGameFeatureClass(IntPtr pointer)
		: DAEventClass(pointer)
	{
		daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
	}

	String^ DANoReloadGameFeatureClass::ToString()
	{
		return daGameFeatureClass->ToString();
	}

	bool DANoReloadGameFeatureClass::Equals(Object^ other)
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
			if (daGameFeatureClass->DAGameFeatureClassPointer.Equals(otherDAGameFeatureClass->DAGameFeatureClassPointer))
			{
				return true;
			}
		}

		auto otherDANoReloadGameFeatureClass = dynamic_cast<IDANoReloadGameFeatureClass^>(other);
		if (otherDANoReloadGameFeatureClass != nullptr)
		{
			if (DANoReloadGameFeatureClassPointer.Equals(otherDANoReloadGameFeatureClass->DANoReloadGameFeatureClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void DANoReloadGameFeatureClass::Init()
	{
		daGameFeatureClass->Init();
	}

	IRenSharpGameFeatureClass^ DANoReloadGameFeatureClass::AsManagedGameFeature()
	{
		return daGameFeatureClass->AsManagedGameFeature();
	}

	IntPtr DANoReloadGameFeatureClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void DANoReloadGameFeatureClass::Pointer::set(IntPtr value)
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

	IntPtr DANoReloadGameFeatureClass::DANoReloadGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDANoReloadGameFeatureClassPointer);
	}

	IntPtr DANoReloadGameFeatureClass::DAGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAGameFeatureClassPointer);
	}

	String^ DANoReloadGameFeatureClass::Name::get()
	{
		return daGameFeatureClass->Name;
	}

	IDAGameFeatureFactoryClass^ DANoReloadGameFeatureClass::Factory::get()
	{
		return daGameFeatureClass->Factory;
	}

	void DANoReloadGameFeatureClass::Factory::set(IDAGameFeatureFactoryClass^ value)
	{
		daGameFeatureClass->Factory = value;
	}

	bool DANoReloadGameFeatureClass::IsManagedGameFeature::get()
	{
		return daGameFeatureClass->IsManagedGameFeature;
	}

	::DAEventClass* DANoReloadGameFeatureClass::InternalDAEventClassPointer::get()
	{
		return InternalDANoReloadGameFeatureClassPointer;
	}

	::DAGameFeatureClass* DANoReloadGameFeatureClass::InternalDAGameFeatureClassPointer::get()
	{
		return InternalDANoReloadGameFeatureClassPointer;
	}

	::DANoReloadGameFeatureClass* DANoReloadGameFeatureClass::InternalDANoReloadGameFeatureClassPointer::get()
	{
		return reinterpret_cast<::DANoReloadGameFeatureClass*>(Pointer.ToPointer());
	}
}