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
#include "MSimpleFileFactoryClass.h"

#include "MCriticalSectionClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <SimpleFileFactoryClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	SimpleFileFactoryClass::SimpleFileFactoryClass(IntPtr pointer)
		: FileFactoryClass(pointer)
	{

	}

	IntPtr SimpleFileFactoryClass::SimpleFileFactoryClassPointer::get()
	{
		return IntPtr(InternalSimpleFileFactoryClassPointer);
	}

	String^ SimpleFileFactoryClass::SubDirectories::get()
	{
		return gcnew String(InternalSimpleFileFactoryClassPointer->subdirectories.c_str());
	}

	void SimpleFileFactoryClass::SubDirectories::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalSimpleFileFactoryClassPointer->subdirectories = reinterpret_cast<char*>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	bool SimpleFileFactoryClass::IsStripPath::get()
	{
		return InternalSimpleFileFactoryClassPointer->IsStripPath;
	}

	void SimpleFileFactoryClass::IsStripPath::set(bool value)
	{
		InternalSimpleFileFactoryClassPointer->IsStripPath = value;
	}

	ICriticalSectionClass^ SimpleFileFactoryClass::Mutex::get()
	{
		return gcnew CriticalSectionClass(IntPtr(&InternalSimpleFileFactoryClassPointer->Mutex));
	}

	::FileFactoryClass* SimpleFileFactoryClass::InternalFileFactoryClassPointer::get()
	{
		return InternalSimpleFileFactoryClassPointer;
	}

	::SimpleFileFactoryClass* SimpleFileFactoryClass::InternalSimpleFileFactoryClassPointer::get()
	{
		return reinterpret_cast<::SimpleFileFactoryClass*>(Pointer.ToPointer());
	}
}