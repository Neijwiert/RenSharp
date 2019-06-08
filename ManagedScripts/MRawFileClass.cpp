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
#include "MRawFileClass.h"

#include "Imports.h"
#include "CriticalUnmanagedContainer.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <RawFileClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	RawFileClass::RawFileClass(bool create)
	{
		if (create)
		{
			Pointer = IntPtr(Imports::CreateRawFileClass1());
		}
	}

	RawFileClass::RawFileClass(String^ filename)
	{
		if (filename == nullptr)
		{
			throw gcnew ArgumentNullException("filename");
		}

		IntPtr filenameHandle = Marshal::StringToHGlobalAnsi(filename);
		try
		{
			Pointer = IntPtr(Imports::CreateRawFileClass2(
				reinterpret_cast<char*>(filenameHandle.ToPointer())));
		}
		finally
		{
			Marshal::FreeHGlobal(filenameHandle);
		}
	}

	RawFileClass::RawFileClass(IntPtr pointer)
		: FileClass(pointer)
	{

	}

	IUnmanagedContainer<IRawFileClass^>^ RawFileClass::CreateRawFileClass()
	{
		return gcnew CriticalUnmanagedContainer<IRawFileClass^>(gcnew RawFileClass(true));
	}

	IUnmanagedContainer<IRawFileClass^>^ RawFileClass::CreateRawFileClass(String^ filename)
	{
		return gcnew CriticalUnmanagedContainer<IRawFileClass^>(gcnew RawFileClass(filename));
	}

	void RawFileClass::Reset()
	{
		InternalRawFileClassPointer->Reset();
	}

	int RawFileClass::RawSeek(int pos, int dir)
	{
		return InternalRawFileClassPointer->Raw_Seek(pos, dir);
	}

	void RawFileClass::Attach(IntPtr handle, int rights)
	{
		InternalRawFileClassPointer->Attach(handle.ToPointer(), rights);
	}

	void RawFileClass::Detach()
	{
		InternalRawFileClassPointer->Detach();
	}

	IntPtr RawFileClass::RawFileClassPointer::get()
	{
		return IntPtr(InternalRawFileClassPointer);
	}

	bool RawFileClass::IsBiased::get()
	{
		return InternalRawFileClassPointer->Is_Biased();
	}

	int RawFileClass::TransferBlockSize::get()
	{
		return InternalRawFileClassPointer->Transfer_Block_Size();
	}

	::FileClass* RawFileClass::InternalFileClassPointer::get()
	{
		return InternalRawFileClassPointer;
	}

	::RawFileClass* RawFileClass::InternalRawFileClassPointer::get()
	{
		return reinterpret_cast<::RawFileClass*>(Pointer.ToPointer());
	}

	TextFileClass::TextFileClass(bool create)
		: RawFileClass(false)
	{
		if (create)
		{
			Pointer = IntPtr(Imports::CreateTextFileClass());
		}
	}

	TextFileClass::TextFileClass(IntPtr pointer)
		: RawFileClass(pointer)
	{

	}

	IUnmanagedContainer<ITextFileClass^>^ TextFileClass::CreateTextFileClass()
	{
		return gcnew CriticalUnmanagedContainer<ITextFileClass^>(gcnew TextFileClass(true));
	}

	bool TextFileClass::ReadLine([Out] String^% line)
	{
		::StringClass strLine;

		auto result = InternalTextFileClassPointer->Read_Line(strLine);

		line = gcnew String(strLine.Peek_Buffer());

		return result;
	}

	bool TextFileClass::WriteLine(String^ str)
	{
		if (str == nullptr)
		{
			throw gcnew ArgumentNullException("str");
		}

		IntPtr strHandle = Marshal::StringToHGlobalAnsi(str);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(strHandle.ToPointer()));

			return InternalTextFileClassPointer->Write_Line(tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(strHandle);
		}
	}

	IntPtr TextFileClass::TextFileClassPointer::get()
	{
		return IntPtr(InternalTextFileClassPointer);
	}

	::RawFileClass* TextFileClass::InternalRawFileClassPointer::get()
	{
		return InternalTextFileClassPointer;
	}

	::TextFileClass* TextFileClass::InternalTextFileClassPointer::get()
	{
		return reinterpret_cast<::TextFileClass*>(Pointer.ToPointer());
	}
}