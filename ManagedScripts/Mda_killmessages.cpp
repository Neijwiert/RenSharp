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
#include "Mda_killmessages.h"

#include "Imports.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_killmessages.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DAAdvancedKillMessagesGameFeatureClass::DAAdvancedKillMessagesGameFeatureClass(IntPtr pointer)
		: DAEventClass(pointer)
	{
		daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
	}

	String^ DAAdvancedKillMessagesGameFeatureClass::ToString()
	{
		return daGameFeatureClass->ToString();
	}

	bool DAAdvancedKillMessagesGameFeatureClass::Equals(Object^ other)
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

		auto otherDAAdvancedKillMessagesGameFeatureClass = dynamic_cast<IDAAdvancedKillMessagesGameFeatureClass^>(other);
		if (otherDAAdvancedKillMessagesGameFeatureClass != nullptr)
		{
			if (DAAdvancedKillMessagesGameFeatureClassPointer.Equals(otherDAAdvancedKillMessagesGameFeatureClass->DAAdvancedKillMessagesGameFeatureClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void DAAdvancedKillMessagesGameFeatureClass::Init()
	{
		daGameFeatureClass->Init();
	}

	IRenSharpGameFeatureClass^ DAAdvancedKillMessagesGameFeatureClass::AsManagedGameFeature()
	{
		return daGameFeatureClass->AsManagedGameFeature();
	}

	IntPtr DAAdvancedKillMessagesGameFeatureClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void DAAdvancedKillMessagesGameFeatureClass::Pointer::set(IntPtr value)
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

	IntPtr DAAdvancedKillMessagesGameFeatureClass::DAAdvancedKillMessagesGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAAdvancedKillMessagesGameFeatureClassPointer);
	}

	IntPtr DAAdvancedKillMessagesGameFeatureClass::DAGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAGameFeatureClassPointer);
	}

	String^ DAAdvancedKillMessagesGameFeatureClass::Name::get()
	{
		return daGameFeatureClass->Name;
	}

	IDAGameFeatureFactoryClass^ DAAdvancedKillMessagesGameFeatureClass::Factory::get()
	{
		return daGameFeatureClass->Factory;
	}

	void DAAdvancedKillMessagesGameFeatureClass::Factory::set(IDAGameFeatureFactoryClass^ value)
	{
		daGameFeatureClass->Factory = value;
	}

	bool DAAdvancedKillMessagesGameFeatureClass::IsManagedGameFeature::get()
	{
		return daGameFeatureClass->IsManagedGameFeature;
	}

	::DAEventClass* DAAdvancedKillMessagesGameFeatureClass::InternalDAEventClassPointer::get()
	{
		return InternalDAAdvancedKillMessagesGameFeatureClassPointer;
	}

	::DAGameFeatureClass* DAAdvancedKillMessagesGameFeatureClass::InternalDAGameFeatureClassPointer::get()
	{
		return InternalDAAdvancedKillMessagesGameFeatureClassPointer;
	}

	::DAAdvancedKillMessagesGameFeatureClass* DAAdvancedKillMessagesGameFeatureClass::InternalDAAdvancedKillMessagesGameFeatureClassPointer::get()
	{
		return reinterpret_cast<::DAAdvancedKillMessagesGameFeatureClass*>(Pointer.ToPointer());
	}
}