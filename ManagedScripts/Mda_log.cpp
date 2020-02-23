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
#include "Mda_log.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4561 4996 4091 4251 4244 26495 26454)
#include <da_log.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DALogManager::DALogManager(IntPtr pointer)
		: DAEventClass(pointer)
	{

	}

	void DALogManager::WriteLog(String^ header, String^ format, ...array<Object^>^ args)
	{
		if (header == nullptr)
		{
			throw gcnew ArgumentNullException("header");
		}
		else if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr headerHandle = Marshal::StringToHGlobalAnsi(header);
		try
		{
			IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
			try
			{
				::DALogManager::Write_Log(
					reinterpret_cast<char*>(headerHandle.ToPointer()),
					reinterpret_cast<char*>(formatHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(formatHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(headerHandle);
		}
	}

	void DALogManager::WriteGameLog(String^ format, ...array<Object^>^ args)
	{
		if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DALogManager::Write_GameLog(
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DALogManager::Send(String^ data)
	{
		if (data == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		IntPtr dataHandle = Marshal::StringToHGlobalAnsi(data);
		try
		{
			::DALogManager::Send(
				reinterpret_cast<char*>(dataHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(dataHandle);
		}
	}

	IntPtr DALogManager::DALogManagerPointer::get()
	{
		return IntPtr(InternalDALogManagerPointer);
	}

	::DAEventClass* DALogManager::InternalDAEventClassPointer::get()
	{
		return InternalDALogManagerPointer;
	}

	::DALogManager* DALogManager::InternalDALogManagerPointer::get()
	{
		return reinterpret_cast<::DALogManager*>(Pointer.ToPointer());
	}
}