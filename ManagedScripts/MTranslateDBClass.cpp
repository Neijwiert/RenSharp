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
#include "MTranslateDBClass.h"

#include "MTDBObjClassPtrDynamicVectorClass.h"
#include "MTDBObjClass.h"
#include "MStringClassTDBObjClassPtrHashTemplateClass.h"

namespace RenSharp
{
	TranslateDBClass::TranslateDBClass(IntPtr pointer)
		: SaveLoadSubSystemClass(pointer)
	{

	}

	void TranslateDBClass::Initialize()
	{
		::TranslateDBClass::Initialize();
	}

	void TranslateDBClass::Shutdown()
	{
		::TranslateDBClass::Shutdown();
	}

	void TranslateDBClass::RemoveAll()
	{
		::TranslateDBClass::Remove_All();
	}

	String^ TranslateDBClass::GetString(uint32 id)
	{
		auto result = ::TranslateDBClass::Get_String(id);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String^ TranslateDBClass::GetString(String^ id)
	{
		if (id == nullptr)
		{
			throw gcnew ArgumentNullException("id");
		}

		IntPtr idHandle = Marshal::StringToHGlobalAnsi(id);
		try
		{
			auto result = ::TranslateDBClass::Get_String(
				reinterpret_cast<char*>(idHandle.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew String(result);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(idHandle);
		}
	}

	String^ TranslateDBClass::GetEnglishString(uint32 id)
	{
		auto result = ::TranslateDBClass::Get_English_String(id);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	ITDBObjClass^ TranslateDBClass::FindObject(String^ id)
	{
		if (id == nullptr)
		{
			throw gcnew ArgumentNullException("id");
		}

		IntPtr idHandle = Marshal::StringToHGlobalAnsi(id);
		try
		{
			auto result = ::TranslateDBClass::Find_Object(
				reinterpret_cast<char*>(idHandle.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew TDBObjClass(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(idHandle);
		}
	}

	ITDBObjClass^ TranslateDBClass::FindObject(uint32 id)
	{
		auto result = ::TranslateDBClass::Find_Object(id);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew TDBObjClass(IntPtr(result));
		}
	}

	String^ TranslateDBClass::StringNotFound::get()
	{
		if (::STRING_NOT_FOUND == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(::STRING_NOT_FOUND);
		}
	}

	String^ TranslateDBClass::EnglishStringNotFound::get()
	{
		if (::ENGLISH_STRING_NOT_FOUND == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(::ENGLISH_STRING_NOT_FOUND);
		}
	}

	uint32 TranslateDBClass::VersionNumber::get()
	{
		return ::TranslateDBClass::Get_Version_Number();
	}

	bool TranslateDBClass::IsLoaded::get()
	{
		return ::TranslateDBClass::Is_Loaded();
	}

	int TranslateDBClass::ObjectCount::get()
	{
		return ::TranslateDBClass::Get_Object_Count();
	}

	uint32 TranslateDBClass::CurrentLanguage::get()
	{
		return ::TranslateDBClass::Get_Current_Language();
	}

	void TranslateDBClass::CurrentLanguage::set(uint32 value)
	{
		::TranslateDBClass::Set_Current_Language(value);
	}

	IntPtr TranslateDBClass::TranslateDBClassPointer::get()
	{
		return IntPtr(InternalTranslateDBClassPointer);
	}

	::SaveLoadSubSystemClass* TranslateDBClass::InternalSaveLoadSubSystemClassPointer::get()
	{
		return InternalTranslateDBClassPointer;
	}

	::TranslateDBClass* TranslateDBClass::InternalTranslateDBClassPointer::get()
	{
		return reinterpret_cast<::TranslateDBClass*>(Pointer.ToPointer());
	}
}