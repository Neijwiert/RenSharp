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
#include "MTDBCategoryClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <TDBCategoryClass.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Text;
using namespace System::Runtime::InteropServices;

namespace RenSharp
{
	TDBCategoryClass::TDBCategoryClass(IntPtr pointer)
		: PersistClass(pointer)
	{

	}

	String^ TDBCategoryClass::ToString()
	{
		StringBuilder^ builder = gcnew StringBuilder();
		builder->Append(Name);

		return builder->ToString();
	}

	IntPtr TDBCategoryClass::TDBCategoryClassPointer::get()
	{
		return IntPtr(InternalTDBCategoryClassPointer);
	}

	String^ TDBCategoryClass::Name::get()
	{
		return gcnew String(InternalTDBCategoryClassPointer->Get_Name().Peek_Buffer());
	}

	void TDBCategoryClass::Name::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalTDBCategoryClassPointer->Set_Name(
				reinterpret_cast<char*>(valueHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	uint32 TDBCategoryClass::ID::get()
	{
		return InternalTDBCategoryClassPointer->Get_ID();
	}

	void TDBCategoryClass::ID::set(uint32 value)
	{
		InternalTDBCategoryClassPointer->Set_ID(value);
	}

	::PersistClass* TDBCategoryClass::InternalPersistClassPointer::get()
	{
		return InternalTDBCategoryClassPointer;
	}

	::TDBCategoryClass* TDBCategoryClass::InternalTDBCategoryClassPointer::get()
	{
		return reinterpret_cast<::TDBCategoryClass*>(Pointer.ToPointer());
	}
}