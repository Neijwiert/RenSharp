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
#include "Mda_taunt.h"

#include "Imports.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_taunt.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DATauntsGameFeatureClass::DATauntsGameFeatureClass(IntPtr pointer)
		: DAEventClass(pointer)
	{
		daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
	}

	String^ DATauntsGameFeatureClass::ToString()
	{
		return daGameFeatureClass->ToString();
	}

	bool DATauntsGameFeatureClass::Equals(Object^ other)
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

		auto otherDATauntsGameFeatureClass = dynamic_cast<IDATauntsGameFeatureClass^>(other);
		if (otherDATauntsGameFeatureClass != nullptr)
		{
			if (DATauntsGameFeatureClassPointer.Equals(otherDATauntsGameFeatureClass->DATauntsGameFeatureClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void DATauntsGameFeatureClass::Init()
	{
		daGameFeatureClass->Init();
	}

	IRenSharpGameFeatureClass^ DATauntsGameFeatureClass::AsManagedGameFeature()
	{
		return daGameFeatureClass->AsManagedGameFeature();
	}

	IntPtr DATauntsGameFeatureClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void DATauntsGameFeatureClass::Pointer::set(IntPtr value)
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

	IntPtr DATauntsGameFeatureClass::DATauntsGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDATauntsGameFeatureClassPointer);
	}

	IntPtr DATauntsGameFeatureClass::DAGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAGameFeatureClassPointer);
	}

	String^ DATauntsGameFeatureClass::Name::get()
	{
		return daGameFeatureClass->Name;
	}

	IDAGameFeatureFactoryClass^ DATauntsGameFeatureClass::Factory::get()
	{
		return daGameFeatureClass->Factory;
	}

	void DATauntsGameFeatureClass::Factory::set(IDAGameFeatureFactoryClass^ value)
	{
		daGameFeatureClass->Factory = value;
	}

	bool DATauntsGameFeatureClass::IsManagedGameFeature::get()
	{
		return daGameFeatureClass->IsManagedGameFeature;
	}

	::DAEventClass* DATauntsGameFeatureClass::InternalDAEventClassPointer::get()
	{
		return InternalDATauntsGameFeatureClassPointer;
	}

	::DAGameFeatureClass* DATauntsGameFeatureClass::InternalDAGameFeatureClassPointer::get()
	{
		return InternalDATauntsGameFeatureClassPointer;
	}

	::DATauntsGameFeatureClass* DATauntsGameFeatureClass::InternalDATauntsGameFeatureClassPointer::get()
	{
		return reinterpret_cast<::DATauntsGameFeatureClass*>(Pointer.ToPointer());
	}
}