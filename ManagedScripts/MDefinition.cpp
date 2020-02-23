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
#include "MDefinition.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <Definition.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Text;

namespace RenSharp
{
	DefinitionClass::DefinitionClass(IntPtr pointer)
		: EditableClass(pointer)
	{

	}

	String ^DefinitionClass::ToString()
	{
		StringBuilder ^builder = gcnew StringBuilder();
		builder->Append(Name);

		return builder->ToString();
	}

	IPersistClass ^DefinitionClass::Create()
	{
		auto result = InternalDefinitionClassPointer->Create();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PersistClass(IntPtr(result));
		}
	}

	bool DefinitionClass::IsValidConfig(String ^%message)
	{
		StringClass messageResult;
		bool result = InternalDefinitionClassPointer->Is_Valid_Config(messageResult);

		message = gcnew String(messageResult.Peek_Buffer());

		return result;
	}

	IntPtr DefinitionClass::DefinitionClassPointer::get()
	{
		return IntPtr(InternalDefinitionClassPointer);
	}

	uint32 DefinitionClass::ClassID::get()
	{
		return InternalDefinitionClassPointer->Get_Class_ID();
	}

	uint32 DefinitionClass::ID::get()
	{
		return InternalDefinitionClassPointer->Get_ID();
	}

	void DefinitionClass::ID::set(uint32 value)
	{
		InternalDefinitionClassPointer->Set_ID(value);
	}

	String ^DefinitionClass::Name::get()
	{
		auto result = InternalDefinitionClassPointer->Get_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	void DefinitionClass::Name::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalDefinitionClassPointer->Set_Name(reinterpret_cast<char *>(valueHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	uint32 DefinitionClass::UserData::get()
	{
		return InternalDefinitionClassPointer->Get_User_Data();
	}

	void DefinitionClass::UserData::set(uint32 value)
	{
		InternalDefinitionClassPointer->Set_User_Data(value);
	}

	bool DefinitionClass::IsSaveEnabled::get()
	{
		return InternalDefinitionClassPointer->Is_Save_Enabled();
	}

	void DefinitionClass::IsSaveEnabled::set(bool value)
	{
		InternalDefinitionClassPointer->Enable_Save(value);
	}

	::EditableClass *DefinitionClass::InternalEditableClassPointer::get()
	{
		return InternalDefinitionClassPointer;
	}

	::DefinitionClass *DefinitionClass::InternalDefinitionClassPointer::get()
	{
		return reinterpret_cast<::DefinitionClass *>(Pointer.ToPointer());
	}

	int DefinitionClass::DefinitionMgrLink::get()
	{
		auto helper = reinterpret_cast<DefinitionClassHelper *>(InternalDefinitionClassPointer);

		auto &definitionMgrLink = helper->GetDefinitionMgrLink();

		return definitionMgrLink;
	}

	void DefinitionClass::DefinitionMgrLink::set(int value)
	{
		auto helper = reinterpret_cast<DefinitionClassHelper *>(InternalDefinitionClassPointer);

		auto &definitionMgrLink = helper->GetDefinitionMgrLink();

		definitionMgrLink = value;
	}
}