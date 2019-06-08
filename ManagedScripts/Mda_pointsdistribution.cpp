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
#include "Mda_pointsdistribution.h"

#include "Imports.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_pointsdistribution.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DAPointsDistributionGameFeatureClass::DAPointsDistributionGameFeatureClass(IntPtr pointer)
		: DAEventClass(pointer)
	{
		daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
	}

	String^ DAPointsDistributionGameFeatureClass::ToString()
	{
		return daGameFeatureClass->ToString();
	}

	bool DAPointsDistributionGameFeatureClass::Equals(Object^ other)
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

		auto otherDAPointsDistributionGameFeatureClass = dynamic_cast<IDAPointsDistributionGameFeatureClass^>(other);
		if (otherDAPointsDistributionGameFeatureClass != nullptr)
		{
			if (DAPointsDistributionGameFeatureClassPointer.Equals(otherDAPointsDistributionGameFeatureClass->DAPointsDistributionGameFeatureClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void DAPointsDistributionGameFeatureClass::Init()
	{
		daGameFeatureClass->Init();
	}

	IRenSharpGameFeatureClass^ DAPointsDistributionGameFeatureClass::AsManagedGameFeature()
	{
		return daGameFeatureClass->AsManagedGameFeature();
	}

	IntPtr DAPointsDistributionGameFeatureClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void DAPointsDistributionGameFeatureClass::Pointer::set(IntPtr value)
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

	IntPtr DAPointsDistributionGameFeatureClass::DAPointsDistributionGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAPointsDistributionGameFeatureClassPointer);
	}

	IntPtr DAPointsDistributionGameFeatureClass::DAGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAGameFeatureClassPointer);
	}

	String^ DAPointsDistributionGameFeatureClass::Name::get()
	{
		return daGameFeatureClass->Name;
	}

	IDAGameFeatureFactoryClass^ DAPointsDistributionGameFeatureClass::Factory::get()
	{
		return daGameFeatureClass->Factory;
	}

	void DAPointsDistributionGameFeatureClass::Factory::set(IDAGameFeatureFactoryClass^ value)
	{
		daGameFeatureClass->Factory = value;
	}

	bool DAPointsDistributionGameFeatureClass::IsManagedGameFeature::get()
	{
		return daGameFeatureClass->IsManagedGameFeature;
	}

	::DAEventClass* DAPointsDistributionGameFeatureClass::InternalDAEventClassPointer::get()
	{
		return InternalDAPointsDistributionGameFeatureClassPointer;
	}

	::DAGameFeatureClass* DAPointsDistributionGameFeatureClass::InternalDAGameFeatureClassPointer::get()
	{
		return InternalDAPointsDistributionGameFeatureClassPointer;
	}

	::DAPointsDistributionGameFeatureClass* DAPointsDistributionGameFeatureClass::InternalDAPointsDistributionGameFeatureClassPointer::get()
	{
		return reinterpret_cast<::DAPointsDistributionGameFeatureClass*>(Pointer.ToPointer());
	}
}