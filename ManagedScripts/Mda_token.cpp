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
#include "Mda_token.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_token.h>
#include <limits>
#pragma warning(pop) 
#pragma managed(pop)

#include "UnmanagedContainer.h"
#include "Imports.h"

namespace RenSharp
{
	DATokenParserClass::DATokenParserClass(String ^str, wchar_t delim)
		: AbstractUnmanagedObject()
	{
		if (str == nullptr)
		{
			throw gcnew ArgumentNullException("str");
		}
		else if (delim < (std::numeric_limits<char>::min)() || delim > (std::numeric_limits<char>::max)())
		{
			throw gcnew ArgumentOutOfRangeException("delim");
		}

		IntPtr strHandle = Marshal::StringToHGlobalAnsi(str);
		try
		{
			Pointer = IntPtr(Imports::CreateDATokenParserClass(reinterpret_cast<char *>(strHandle.ToPointer()), static_cast<char>(delim)));
		}
		finally
		{
			Marshal::FreeHGlobal(strHandle);
		}
	}

	DATokenParserClass::DATokenParserClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool DATokenParserClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDATokenParserClass ^otherThis = dynamic_cast<IDATokenParserClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DATokenParserClassPointer.Equals(otherThis->DATokenParserClassPointer);
	}

	IUnmanagedContainer<IDATokenParserClass ^> ^DATokenParserClass::CreateDATokenParserClass(String ^str, wchar_t delim)
	{
		return gcnew UnmanagedContainer<IDATokenParserClass ^>(gcnew DATokenParserClass(str, delim));
	}

	void DATokenParserClass::Set(String ^str, wchar_t delim)
	{
		if (str == nullptr)
		{
			throw gcnew ArgumentNullException("str");
		}
		else if (delim < (std::numeric_limits<char>::min)() || delim > (std::numeric_limits<char>::max)())
		{
			throw gcnew ArgumentOutOfRangeException("delim");
		}

		IntPtr strHandle = Marshal::StringToHGlobalAnsi(str);
		try
		{
			InternalDATokenParserClassPointer->Set(reinterpret_cast<char *>(strHandle.ToPointer()), static_cast<char>(delim));
		}
		finally
		{
			Marshal::FreeHGlobal(strHandle);
		}
	}

	String ^DATokenParserClass::GetString()
	{
		auto result = InternalDATokenParserClassPointer->Get_String();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String ^DATokenParserClass::GetRemainingString()
	{
		auto result = InternalDATokenParserClassPointer->Get_Remaining_String();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	bool DATokenParserClass::GetInt(int %buffer)
	{
		int tmp = 0;

		bool result = InternalDATokenParserClassPointer->Get_Int(tmp);
		buffer = tmp;

		return result;
	}

	bool DATokenParserClass::GetUInt(unsigned int %buffer)
	{
		unsigned int tmp = 0;

		bool result = InternalDATokenParserClassPointer->Get_UInt(tmp);
		buffer = tmp;

		return result;
	}

	bool DATokenParserClass::GetFloat(float %buffer)
	{
		float tmp = 0;

		bool result = InternalDATokenParserClassPointer->Get_Float(tmp);
		buffer = tmp;

		return result;
	}

	IntPtr DATokenParserClass::DATokenParserClassPointer::get()
	{
		return IntPtr(InternalDATokenParserClassPointer);
	}

	bool DATokenParserClass::InternalDestroyPointer()
	{
		Imports::DestroyDATokenParserClass(InternalDATokenParserClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DATokenParserClass *DATokenParserClass::InternalDATokenParserClassPointer::get()
	{
		return reinterpret_cast<::DATokenParserClass *>(Pointer.ToPointer());
	}

	DATokenClass::DATokenClass()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateDATokenClass1()))
	{

	}

	DATokenClass::DATokenClass(String ^str, int startPos, wchar_t delim)
		: AbstractUnmanagedObject()
	{
		if (str == nullptr)
		{
			throw gcnew ArgumentNullException("str");
		}
		else if (startPos < 0)
		{
			throw gcnew ArgumentOutOfRangeException("startPos");
		}
		else if (delim < (std::numeric_limits<char>::min)() || delim > (std::numeric_limits<char>::max)())
		{
			throw gcnew ArgumentOutOfRangeException("delim");
		}

		IntPtr strHandle = Marshal::StringToHGlobalAnsi(str);
		try
		{
			Pointer = IntPtr(Imports::CreateDATokenClass2(reinterpret_cast<char *>(strHandle.ToPointer()), startPos, static_cast<char>(delim)));
		}
		finally
		{
			Marshal::FreeHGlobal(strHandle);
		}
	}

	DATokenClass::DATokenClass(String ^str, int startPos)
		: AbstractUnmanagedObject()
	{
		if (str == nullptr)
		{
			throw gcnew ArgumentNullException("str");
		}
		else if (startPos < 0)
		{
			throw gcnew ArgumentOutOfRangeException("startPos");
		}

		IntPtr strHandle = Marshal::StringToHGlobalAnsi(str);
		try
		{
			Pointer = IntPtr(Imports::CreateDATokenClass3(reinterpret_cast<char *>(strHandle.ToPointer()), startPos));
		}
		finally
		{
			Marshal::FreeHGlobal(strHandle);
		}
	}

	DATokenClass::DATokenClass(String ^str)
		: AbstractUnmanagedObject()
	{
		if (str == nullptr)
		{
			throw gcnew ArgumentNullException("str");
		}

		IntPtr strHandle = Marshal::StringToHGlobalAnsi(str);
		try
		{
			Pointer = IntPtr(Imports::CreateDATokenClass4(reinterpret_cast<char *>(strHandle.ToPointer())));
		}
		finally
		{
			Marshal::FreeHGlobal(strHandle);
		}
	}

	DATokenClass::DATokenClass(IDATokenParserClass^ parser)
	{
		if (parser == nullptr || parser->DATokenParserClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("parser");
		}

		Pointer = IntPtr(Imports::CreateDATokenClass5(
			reinterpret_cast<::DATokenParserClass*>(parser->DATokenParserClassPointer.ToPointer())));
	}

	DATokenClass::DATokenClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool DATokenClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDATokenClass ^otherThis = dynamic_cast<IDATokenClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DATokenClassPointer.Equals(otherThis->DATokenClassPointer);
	}

	IUnmanagedContainer<IDATokenClass ^> ^DATokenClass::CreateDATokenClass()
	{
		return gcnew UnmanagedContainer<IDATokenClass ^>(gcnew DATokenClass());
	}

	IUnmanagedContainer<IDATokenClass ^> ^DATokenClass::CreateDATokenClass(String ^str, int startPos, wchar_t delim)
	{
		return gcnew UnmanagedContainer<IDATokenClass ^>(gcnew DATokenClass(str, startPos, delim));
	}

	IUnmanagedContainer<IDATokenClass ^> ^DATokenClass::CreateDATokenClass(String ^str, int startPos)
	{
		return gcnew UnmanagedContainer<IDATokenClass ^>(gcnew DATokenClass(str, startPos));
	}

	IUnmanagedContainer<IDATokenClass ^> ^DATokenClass::CreateDATokenClass(String ^str)
	{
		return gcnew UnmanagedContainer<IDATokenClass ^>(gcnew DATokenClass(str));
	}

	IUnmanagedContainer<IDATokenClass^>^ DATokenClass::CreateDATokenClass(IDATokenParserClass^ parser)
	{
		return gcnew UnmanagedContainer<IDATokenClass^>(gcnew DATokenClass(parser));
	}

	void DATokenClass::Build(IDATokenParserClass ^parser)
	{
		if (parser == nullptr || parser->DATokenParserClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("parser");
		}

		InternalDATokenClassPointer->Build(*reinterpret_cast<::DATokenParserClass *>(parser->DATokenParserClassPointer.ToPointer()));
	}

	void DATokenClass::Build(String ^str, int startPos, wchar_t delim)
	{
		if (str == nullptr)
		{
			throw gcnew ArgumentNullException("str");
		}
		else if (startPos < 1)
		{
			throw gcnew ArgumentOutOfRangeException("startPos");
		}
		else if (delim < (std::numeric_limits<char>::min)() || delim > (std::numeric_limits<char>::max)())
		{
			throw gcnew ArgumentOutOfRangeException("delim");
		}

		IntPtr strHandle = Marshal::StringToHGlobalAnsi(str);
		try
		{
			InternalDATokenClassPointer->Build(reinterpret_cast<char *>(strHandle.ToPointer()), startPos, static_cast<char>(delim));
		}
		finally
		{
			Marshal::FreeHGlobal(strHandle);
		}
	}

	void DATokenClass::ToLower()
	{
		InternalDATokenClassPointer->To_Lower();
	}

	String ^DATokenClass::GetPartialToken(int start, int end)
	{
		::StringClass result = InternalDATokenClassPointer->operator()(start, end);

		return gcnew String(result.Peek_Buffer());
	}

	String ^DATokenClass::GetPartialToken(int start)
	{
		::StringClass result = InternalDATokenClassPointer->operator()(start);

		return gcnew String(result.Peek_Buffer());
	}

	void DATokenClass::Erase(int pos)
	{
		InternalDATokenClassPointer->Erase(pos);
	}

	void DATokenClass::Replace(int pos, String ^newText)
	{
		if (newText == nullptr)
		{
			throw gcnew ArgumentNullException("newText");
		}

		IntPtr newTextHandle = Marshal::StringToHGlobalAnsi(newText);
		try
		{
			::StringClass tmp = reinterpret_cast<char *>(newTextHandle.ToPointer());
			InternalDATokenClassPointer->Replace(pos, tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(newTextHandle);
		}
	}

	void DATokenClass::Add(String ^text, int pos)
	{
		if (text == nullptr)
		{
			throw gcnew ArgumentNullException("text");
		}

		IntPtr textHandle = Marshal::StringToHGlobalAnsi(text);
		try
		{
			::StringClass tmp = reinterpret_cast<char *>(textHandle.ToPointer());
			InternalDATokenClassPointer->Add(tmp, pos);
		}
		finally
		{
			Marshal::FreeHGlobal(textHandle);
		}
	}

	void DATokenClass::Add(String ^text)
	{
		if (text == nullptr)
		{
			throw gcnew ArgumentNullException("text");
		}

		IntPtr textHandle = Marshal::StringToHGlobalAnsi(text);
		try
		{
			::StringClass tmp = reinterpret_cast<char *>(textHandle.ToPointer());
			InternalDATokenClassPointer->Add(tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(textHandle);
		}
	}

	bool DATokenClass::IsInt(int pos)
	{
		return InternalDATokenClassPointer->Is_Int(pos);
	}

	bool DATokenClass::IsUInt(int pos)
	{
		return InternalDATokenClassPointer->Is_UInt(pos);
	}

	bool DATokenClass::IsFloat(int pos)
	{
		return InternalDATokenClassPointer->Is_Float(pos);
	}

	int DATokenClass::Find(String ^text)
	{
		if (text == nullptr)
		{
			throw gcnew ArgumentNullException("text");
		}

		IntPtr textHandle = Marshal::StringToHGlobalAnsi(text);
		try
		{
			::StringClass tmp = reinterpret_cast<char *>(textHandle.ToPointer());
			
			return InternalDATokenClassPointer->Find(tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(textHandle);
		}
	}

	int DATokenClass::Find(uint hash)
	{
		return InternalDATokenClassPointer->Find(hash);
	}

	bool DATokenClass::AsInt(int pos, [Out] int %buffer)
	{
		int tmp = 0;

		bool result = InternalDATokenClassPointer->As_Int(pos, tmp);
		buffer = tmp;

		return result;
	}

	bool DATokenClass::AsUInt(int pos, [Out] unsigned int %buffer)
	{
		unsigned int tmp = 0;

		bool result = InternalDATokenClassPointer->As_UInt(pos, tmp);
		buffer = tmp;

		return result;
	}

	bool DATokenClass::AsFloat(int pos, [Out] float %buffer)
	{
		float tmp = 0;

		bool result = InternalDATokenClassPointer->As_Float(pos, tmp);
		buffer = tmp;

		return result;
	}

	String ^DATokenClass::AsString(int pos)
	{
		return this[pos];
	}

	IntPtr DATokenClass::DATokenClassPointer::get()
	{
		return IntPtr(InternalDATokenClassPointer);
	}

	String ^DATokenClass::Delimiter::get()
	{
		return gcnew String(InternalDATokenClassPointer->Get_Delimiter().Peek_Buffer());
	}

	String ^DATokenClass::default::get(int index)
	{
		return gcnew String(InternalDATokenClassPointer->operator[](index).Peek_Buffer());
	}

	int DATokenClass::Size::get()
	{
		return InternalDATokenClassPointer->Size();
	}

	bool DATokenClass::InternalDestroyPointer()
	{
		Imports::DestroyDATokenClass(InternalDATokenClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DATokenClass *DATokenClass::InternalDATokenClassPointer::get()
	{
		return reinterpret_cast<::DATokenClass *>(Pointer.ToPointer());
	}
}