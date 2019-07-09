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
#include "Mda_shotgun.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_shotgun.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DAShotgunGameModeClass::DAShotgunGameModeClass(IntPtr pointer)
		: DAEventClass(pointer)
	{
		daGameModeClass = gcnew DAGameModeClass(IntPtr(InternalDAGameModeClassPointer));
	}

	String^ DAShotgunGameModeClass::ToString()
	{
		return daGameModeClass->ToString();
	}

	bool DAShotgunGameModeClass::Equals(Object^ other)
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

		auto otherDAGameModeClass = dynamic_cast<IDAGameModeClass^>(other);
		if (otherDAGameModeClass != nullptr)
		{
			if (daGameModeClass->Equals(otherDAGameModeClass))
			{
				return true;
			}
		}

		auto otherDAShotgunGameModeClass = dynamic_cast<IDAShotgunGameModeClass^>(other);
		if (otherDAShotgunGameModeClass != nullptr)
		{
			if (DAShotgunGameModeClassPointer.Equals(otherDAShotgunGameModeClass->DAShotgunGameModeClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void DAShotgunGameModeClass::Init()
	{
		daGameModeClass->Init();
	}

	IRenSharpGameModeClass^ DAShotgunGameModeClass::AsManagedGameMode()
	{
		return daGameModeClass->AsManagedGameMode();
	}

	IntPtr DAShotgunGameModeClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void DAShotgunGameModeClass::Pointer::set(IntPtr value)
	{
		AbstractUnmanagedObject::Pointer::set(value);

		if (Pointer == IntPtr::Zero)
		{
			daGameModeClass = nullptr;
		}
		else
		{
			daGameModeClass = gcnew DAGameModeClass(IntPtr(InternalDAGameModeClassPointer));
		}
	}

	IntPtr DAShotgunGameModeClass::DAShotgunGameModeClassPointer::get()
	{
		return IntPtr(InternalDAShotgunGameModeClassPointer);
	}

	IntPtr DAShotgunGameModeClass::DAGameModeClassPointer::get()
	{
		return IntPtr(InternalDAGameModeClassPointer);
	}

	String^ DAShotgunGameModeClass::LongName::get()
	{
		return daGameModeClass->LongName;
	}

	String^ DAShotgunGameModeClass::ShortName::get()
	{
		return daGameModeClass->ShortName;
	}

	IDAGameModeFactoryClass^ DAShotgunGameModeClass::Factory::get()
	{
		return daGameModeClass->Factory;
	}

	void DAShotgunGameModeClass::Factory::set(IDAGameModeFactoryClass^ value)
	{
		daGameModeClass->Factory = value;
	}

	bool DAShotgunGameModeClass::IsManagedGameMode::get()
	{
		return daGameModeClass->IsManagedGameMode;
	}

	::DAEventClass* DAShotgunGameModeClass::InternalDAEventClassPointer::get()
	{
		return InternalDAShotgunGameModeClassPointer;
	}

	::DAGameModeClass* DAShotgunGameModeClass::InternalDAGameModeClassPointer::get()
	{
		return InternalDAShotgunGameModeClassPointer;
	}

	::DAShotgunGameModeClass* DAShotgunGameModeClass::InternalDAShotgunGameModeClassPointer::get()
	{
		return reinterpret_cast<::DAShotgunGameModeClass*>(Pointer.ToPointer());
	}
}