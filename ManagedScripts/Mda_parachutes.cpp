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
#include "Mda_parachutes.h"

#include "Imports.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_parachutes.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DAParachutesObserverClass::DAParachutesObserverClass(IntPtr pointer)
		: DAGameObjObserverClass(pointer)
	{

	}

	IntPtr DAParachutesObserverClass::DAParachutesObserverClassPointer::get()
	{
		return IntPtr(InternalDAParachutesObserverClassPointer);
	}

	::DAGameObjObserverClass* DAParachutesObserverClass::InternalDAGameObjObserverClassPointer::get()
	{
		return InternalDAParachutesObserverClassPointer;
	}

	::DAParachutesObserverClass* DAParachutesObserverClass::InternalDAParachutesObserverClassPointer::get()
	{
		return reinterpret_cast<::DAParachutesObserverClass*>(Pointer.ToPointer());
	}

	DAParachutesGameFeatureClass::DAParachutesGameFeatureClass(IntPtr pointer)
		: DAEventClass(pointer)
	{
		daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
	}

	String^ DAParachutesGameFeatureClass::ToString()
	{
		return daGameFeatureClass->ToString();
	}

	bool DAParachutesGameFeatureClass::Equals(Object^ other)
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

		auto otherDAParachutesGameFeatureClass = dynamic_cast<IDAParachutesGameFeatureClass^>(other);
		if (otherDAParachutesGameFeatureClass != nullptr)
		{
			if (DAParachutesGameFeatureClassPointer.Equals(otherDAParachutesGameFeatureClass->DAParachutesGameFeatureClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void DAParachutesGameFeatureClass::Init()
	{
		daGameFeatureClass->Init();
	}

	IRenSharpGameFeatureClass^ DAParachutesGameFeatureClass::AsManagedGameFeature()
	{
		return daGameFeatureClass->AsManagedGameFeature();
	}

	IntPtr DAParachutesGameFeatureClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void DAParachutesGameFeatureClass::Pointer::set(IntPtr value)
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

	IntPtr DAParachutesGameFeatureClass::DAParachutesGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAParachutesGameFeatureClassPointer);
	}

	IntPtr DAParachutesGameFeatureClass::DAGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAGameFeatureClassPointer);
	}

	String^ DAParachutesGameFeatureClass::Name::get()
	{
		return daGameFeatureClass->Name;
	}

	IDAGameFeatureFactoryClass^ DAParachutesGameFeatureClass::Factory::get()
	{
		return daGameFeatureClass->Factory;
	}

	void DAParachutesGameFeatureClass::Factory::set(IDAGameFeatureFactoryClass^ value)
	{
		daGameFeatureClass->Factory = value;
	}

	bool DAParachutesGameFeatureClass::IsManagedGameFeature::get()
	{
		return daGameFeatureClass->IsManagedGameFeature;
	}

	::DAEventClass* DAParachutesGameFeatureClass::InternalDAEventClassPointer::get()
	{
		return InternalDAParachutesGameFeatureClassPointer;
	}

	::DAGameFeatureClass* DAParachutesGameFeatureClass::InternalDAGameFeatureClassPointer::get()
	{
		return InternalDAParachutesGameFeatureClassPointer;
	}

	::DAParachutesGameFeatureClass* DAParachutesGameFeatureClass::InternalDAParachutesGameFeatureClassPointer::get()
	{
		return reinterpret_cast<::DAParachutesGameFeatureClass*>(Pointer.ToPointer());
	}
}