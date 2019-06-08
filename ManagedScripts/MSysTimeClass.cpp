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
#include "MSysTimeClass.h"

#include "Imports.h"
#include "UnmanagedContainer.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <SysTimeClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	SysTimeClass::SysTimeClass()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateSysTimeClass()))
	{

	}

	SysTimeClass::SysTimeClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<ISysTimeClass^>^ SysTimeClass::CreateSysTimeClass()
	{
		return gcnew UnmanagedContainer<ISysTimeClass^>(gcnew SysTimeClass());
	}

	bool SysTimeClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		ISysTimeClass^ otherThis = dynamic_cast<ISysTimeClass^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return SysTimeClassPointer.Equals(otherThis->SysTimeClassPointer);
	}

	uint32 SysTimeClass::Get()
	{
		return InternalSysTimeClassPointer->Get();
	}

	void SysTimeClass::Reset()
	{
		InternalSysTimeClassPointer->Reset();
	}

	bool SysTimeClass::IsInit::get()
	{
		return ::SysTimeClass::_is_init;
	}

	void SysTimeClass::IsInit::set(bool value)
	{
		::SysTimeClass::_is_init = value;
	}

	ISysTimeClass^ SysTimeClass::SystemTime::get()
	{
		return gcnew SysTimeClass(IntPtr(&::SysTimeClass::SystemTime));
	}

	void SysTimeClass::SystemTime::set(ISysTimeClass^ value)
	{
		if (value == nullptr || value->SysTimeClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		::SysTimeClass::SystemTime = *reinterpret_cast<::SysTimeClass*>(value->SysTimeClassPointer.ToPointer());
	}

	IntPtr SysTimeClass::SysTimeClassPointer::get()
	{
		return IntPtr(InternalSysTimeClassPointer);
	}

	bool SysTimeClass::InternalDestroyPointer()
	{
		Imports::DestroySysTimeClass(InternalSysTimeClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::SysTimeClass* SysTimeClass::InternalSysTimeClassPointer::get()
	{
		return reinterpret_cast<::SysTimeClass*>(Pointer.ToPointer());
	}
}