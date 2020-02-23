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
#include "MCommandLineParser.h"

#include "Imports.h"
#include "UnmanagedContainer.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <CommandLineParser.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	CommandLineParser::CommandLineParser(String^ command)
	{
		if (command == nullptr)
		{
			throw gcnew ArgumentNullException("command");
		}

		IntPtr commandHandle = Marshal::StringToHGlobalAnsi(command);
		try
		{
			Pointer = IntPtr(Imports::CreateCommandLineParser(
				reinterpret_cast<char*>(commandHandle.ToPointer())));
		}
		finally
		{
			Marshal::FreeHGlobal(commandHandle);
		}
	}

	CommandLineParser::CommandLineParser(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<ICommandLineParser^>^ CommandLineParser::CreateCommandLineParser(String^ command)
	{
		return gcnew UnmanagedContainer<ICommandLineParser^>(gcnew CommandLineParser(command));
	}

	bool CommandLineParser::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		ICommandLineParser^ otherThis = dynamic_cast<ICommandLineParser^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return CommandLineParserPointer.Equals(otherThis->CommandLineParserPointer);
	}

	void CommandLineParser::Skip()
	{
		InternalCommandLineParserPointer->skip();
	}

	String^ CommandLineParser::GetString()
	{
		auto result = InternalCommandLineParserPointer->getString();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String^ CommandLineParser::GetRemainingString()
	{
		auto result = InternalCommandLineParserPointer->getRemainingString();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	int CommandLineParser::GetInt()
	{
		return InternalCommandLineParserPointer->getInt();
	}

	double CommandLineParser::GetDouble()
	{
		return InternalCommandLineParserPointer->getDouble();
	}

	IntPtr CommandLineParser::CommandLineParserPointer::get()
	{
		return IntPtr(InternalCommandLineParserPointer);
	}

	bool CommandLineParser::InternalDestroyPointer()
	{
		Imports::DestroyCommandLineParser(InternalCommandLineParserPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::CommandLineParser* CommandLineParser::InternalCommandLineParserPointer::get()
	{
		return reinterpret_cast<::CommandLineParser*>(Pointer.ToPointer());
	}
}