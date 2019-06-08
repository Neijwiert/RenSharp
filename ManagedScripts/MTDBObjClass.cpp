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
#include "MTDBObjClass.h"

#include "MWideStringClassDynamicVectorClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <TDBObjClass.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Text;

namespace RenSharp
{
#pragma managed(push, off)

	class TDBObjClassHelper : public ::TDBObjClass
	{
		private:
			TDBObjClassHelper() = default;

		public:
			::StringClass& GetEnglishString()
			{
				return EnglishString;
			}

			::StringClass& GetIDDesc()
			{
				return IDDesc;
			}

			uint32& GetID()
			{
				return ID;
			}

			::DynamicVectorClass<::WideStringClass>& GetTranslatedStrings()
			{
				return TranslatedStrings;
			}
	};

#pragma managed(pop)

	TDBObjClass::TDBObjClass(IntPtr pointer)
		: PersistClass(pointer)
	{

	}

	String^ TDBObjClass::ToString()
	{
		StringBuilder^ builder = gcnew StringBuilder();
		builder->Append(GetString());

		return builder->ToString();
	}

	String^ TDBObjClass::GetString(uint32 langId)
	{
		return gcnew String(InternalTDBObjClassPointer->Get_String(langId).Peek_Buffer());
	}

	String^ TDBObjClass::GetString()
	{
		return gcnew String(InternalTDBObjClassPointer->Get_String().Peek_Buffer());
	}

	void TDBObjClass::SetString(uint32 langId, String^ str)
	{
		if (str == nullptr)
		{
			throw gcnew ArgumentNullException("str");
		}

		IntPtr strHandle = Marshal::StringToHGlobalUni(str);
		try
		{
			InternalTDBObjClassPointer->Set_String(
				langId,
				reinterpret_cast<wchar_t*>(strHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(strHandle);
		}
	}

	void TDBObjClass::SetEnglishString(String^ str)
	{
		if (str == nullptr)
		{
			throw gcnew ArgumentNullException("str");
		}

		IntPtr strHandle = Marshal::StringToHGlobalAnsi(str);
		try
		{
			InternalTDBObjClassPointer->Set_English_String(
				reinterpret_cast<char*>(strHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(strHandle);
		}
	}

	void TDBObjClass::SetID(uint32 id)
	{
		InternalTDBObjClassPointer->Set_ID(id);
	}

	void TDBObjClass::SetIDDesc(String^ desc)
	{
		if (desc == nullptr)
		{
			throw gcnew ArgumentNullException("desc");
		}

		IntPtr descHandle = Marshal::StringToHGlobalAnsi(desc);
		try
		{
			InternalTDBObjClassPointer->Set_ID_Desc(
				reinterpret_cast<char*>(descHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(descHandle);
		}
	}

	bool TDBObjClass::ContainsTranslation(uint32 langId)
	{
		return InternalTDBObjClassPointer->Contains_Translation(langId);
	}

	IntPtr TDBObjClass::TDBObjClassPointer::get()
	{
		return IntPtr(InternalTDBObjClassPointer);
	}

	String^ TDBObjClass::EnglishString::get()
	{
		return gcnew String(InternalTDBObjClassPointer->Get_English_String().Peek_Buffer());
	}

	void TDBObjClass::EnglishString::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<TDBObjClassHelper*>(InternalTDBObjClassPointer);

		auto& englishString = helper->GetEnglishString();

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			englishString = reinterpret_cast<char*>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	uint32 TDBObjClass::ID::get()
	{
		return InternalTDBObjClassPointer->Get_ID();
	}

	void TDBObjClass::ID::set(uint32 value)
	{
		auto helper = reinterpret_cast<TDBObjClassHelper*>(InternalTDBObjClassPointer);

		auto& id = helper->GetID();

		id = value;
	}

	String^ TDBObjClass::IDDesc::get()
	{
		return gcnew String(InternalTDBObjClassPointer->Get_ID_Desc().Peek_Buffer());
	}

	void TDBObjClass::IDDesc::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<TDBObjClassHelper*>(InternalTDBObjClassPointer);

		auto& idDesc = helper->GetIDDesc();

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			idDesc = reinterpret_cast<char*>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	uint32 TDBObjClass::SoundID::get()
	{
		return InternalTDBObjClassPointer->Get_Sound_ID();
	}

	void TDBObjClass::SoundID::set(uint32 value)
	{
		InternalTDBObjClassPointer->Set_Sound_ID(value);
	}

	String^ TDBObjClass::AnimationName::get()
	{
		return gcnew String(InternalTDBObjClassPointer->Get_Animation_Name().Peek_Buffer());
	}

	void TDBObjClass::AnimationName::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalTDBObjClassPointer->Set_Animation_Name(
				reinterpret_cast<char*>(valueHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	uint32 TDBObjClass::CategoryID::get()
	{
		return InternalTDBObjClassPointer->Get_Category_ID();
	}

	void TDBObjClass::CategoryID::set(uint32 value)
	{
		InternalTDBObjClassPointer->Set_Category_ID(value);
	}

	::PersistClass* TDBObjClass::InternalPersistClassPointer::get()
	{
		return InternalTDBObjClassPointer;
	}

	::TDBObjClass* TDBObjClass::InternalTDBObjClassPointer::get()
	{
		return reinterpret_cast<::TDBObjClass*>(Pointer.ToPointer());
	}

	IDynamicVectorClass<String^>^ TDBObjClass::TranslatedStrings::get()
	{
		auto helper = reinterpret_cast<TDBObjClassHelper*>(InternalTDBObjClassPointer);

		auto& translatedStrings = helper->GetTranslatedStrings();

		return gcnew WideStringClassDynamicVectorClass(IntPtr(&translatedStrings));
	}

	void TDBObjClass::TranslatedStrings::set(IDynamicVectorClass<String^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<TDBObjClassHelper*>(InternalTDBObjClassPointer);

		auto& translatedStrings = helper->GetTranslatedStrings();

		translatedStrings = *reinterpret_cast<::DynamicVectorClass<::WideStringClass>*>(value->Pointer.ToPointer());
	}
}