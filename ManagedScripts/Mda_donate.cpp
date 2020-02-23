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
#include "Mda_donate.h"

#include "Imports.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_donate.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DADonateGameFeatureClass::DADonateGameFeatureClass(IntPtr pointer)
		: DAEventClass(pointer)
	{
		daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
	}

	String^ DADonateGameFeatureClass::ToString()
	{
		return daGameFeatureClass->ToString();
	}

	bool DADonateGameFeatureClass::Equals(Object^ other)
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

		auto otherDADonateGameFeatureClass = dynamic_cast<IDADonateGameFeatureClass^>(other);
		if (otherDADonateGameFeatureClass != nullptr)
		{
			if (DADonateGameFeatureClassPointer.Equals(otherDADonateGameFeatureClass->DADonateGameFeatureClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void DADonateGameFeatureClass::Init()
	{
		daGameFeatureClass->Init();
	}

	IRenSharpGameFeatureClass^ DADonateGameFeatureClass::AsManagedGameFeature()
	{
		return daGameFeatureClass->AsManagedGameFeature();
	}

	IntPtr DADonateGameFeatureClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void DADonateGameFeatureClass::Pointer::set(IntPtr value)
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

	IntPtr DADonateGameFeatureClass::DADonateGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDADonateGameFeatureClassPointer);
	}

	IntPtr DADonateGameFeatureClass::DAGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAGameFeatureClassPointer);
	}

	String^ DADonateGameFeatureClass::Name::get()
	{
		return daGameFeatureClass->Name;
	}

	IDAGameFeatureFactoryClass^ DADonateGameFeatureClass::Factory::get()
	{
		return daGameFeatureClass->Factory;
	}

	void DADonateGameFeatureClass::Factory::set(IDAGameFeatureFactoryClass^ value)
	{
		daGameFeatureClass->Factory = value;
	}

	bool DADonateGameFeatureClass::IsManagedGameFeature::get()
	{
		return daGameFeatureClass->IsManagedGameFeature;
	}

	::DAEventClass* DADonateGameFeatureClass::InternalDAEventClassPointer::get()
	{
		return InternalDADonateGameFeatureClassPointer;
	}

	::DAGameFeatureClass* DADonateGameFeatureClass::InternalDAGameFeatureClassPointer::get()
	{
		return InternalDADonateGameFeatureClassPointer;
	}

	::DADonateGameFeatureClass* DADonateGameFeatureClass::InternalDADonateGameFeatureClassPointer::get()
	{
		return reinterpret_cast<::DADonateGameFeatureClass*>(Pointer.ToPointer());
	}
}