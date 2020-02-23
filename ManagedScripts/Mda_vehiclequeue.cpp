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
#include "Mda_vehiclequeue.h"

#include "Imports.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_vehiclequeue.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DAVehicleQueueGameFeatureClass::DAVehicleQueueGameFeatureClass(IntPtr pointer)
		: DAEventClass(pointer)
	{
		daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
	}

	String^ DAVehicleQueueGameFeatureClass::ToString()
	{
		return daGameFeatureClass->ToString();
	}

	bool DAVehicleQueueGameFeatureClass::Equals(Object^ other)
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

		auto otherDAVehicleQueueGameFeatureClass = dynamic_cast<IDAVehicleQueueGameFeatureClass^>(other);
		if (otherDAVehicleQueueGameFeatureClass != nullptr)
		{
			if (DAVehicleQueueGameFeatureClassPointer.Equals(otherDAVehicleQueueGameFeatureClass->DAVehicleQueueGameFeatureClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void DAVehicleQueueGameFeatureClass::Init()
	{
		daGameFeatureClass->Init();
	}

	IRenSharpGameFeatureClass^ DAVehicleQueueGameFeatureClass::AsManagedGameFeature()
	{
		return daGameFeatureClass->AsManagedGameFeature();
	}

	IntPtr DAVehicleQueueGameFeatureClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void DAVehicleQueueGameFeatureClass::Pointer::set(IntPtr value)
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

	IntPtr DAVehicleQueueGameFeatureClass::DAVehicleQueueGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAVehicleQueueGameFeatureClassPointer);
	}

	IntPtr DAVehicleQueueGameFeatureClass::DAGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAGameFeatureClassPointer);
	}

	String^ DAVehicleQueueGameFeatureClass::Name::get()
	{
		return daGameFeatureClass->Name;
	}

	IDAGameFeatureFactoryClass^ DAVehicleQueueGameFeatureClass::Factory::get()
	{
		return daGameFeatureClass->Factory;
	}

	void DAVehicleQueueGameFeatureClass::Factory::set(IDAGameFeatureFactoryClass^ value)
	{
		daGameFeatureClass->Factory = value;
	}

	bool DAVehicleQueueGameFeatureClass::IsManagedGameFeature::get()
	{
		return daGameFeatureClass->IsManagedGameFeature;
	}

	::DAEventClass* DAVehicleQueueGameFeatureClass::InternalDAEventClassPointer::get()
	{
		return InternalDAVehicleQueueGameFeatureClassPointer;
	}

	::DAGameFeatureClass* DAVehicleQueueGameFeatureClass::InternalDAGameFeatureClassPointer::get()
	{
		return InternalDAVehicleQueueGameFeatureClassPointer;
	}

	::DAVehicleQueueGameFeatureClass* DAVehicleQueueGameFeatureClass::InternalDAVehicleQueueGameFeatureClassPointer::get()
	{
		return reinterpret_cast<::DAVehicleQueueGameFeatureClass*>(Pointer.ToPointer());
	}
}