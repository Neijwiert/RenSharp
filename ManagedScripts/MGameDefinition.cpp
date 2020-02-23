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
#include "MGameDefinition.h"

#include "Muint32SimpleVecClass.h"
#include "Imports.h"
#include "UnmanagedContainer.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <GameDefinition.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Text;

namespace RenSharp
{
	GameDefinition::GameDefinition()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateGameDefinition()))
	{

	}

	GameDefinition::GameDefinition(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IGameDefinition ^> ^GameDefinition::CreateGameDefinition()
	{
		return gcnew UnmanagedContainer<IGameDefinition ^>(gcnew GameDefinition());
	}

	String ^GameDefinition::ToString()
	{
		StringBuilder ^builder = gcnew StringBuilder();
		builder->Append(DisplayName);

		return builder->ToString();
	}

	bool GameDefinition::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IGameDefinition ^otherThis = dynamic_cast<IGameDefinition ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return GameDefinitionPointer.Equals(otherThis->GameDefinitionPointer);
	}

	IntPtr GameDefinition::GameDefinitionPointer::get()
	{
		return IntPtr(InternalGameDefinitionPointer);
	}

	String ^GameDefinition::Name::get()
	{
		return gcnew String(InternalGameDefinitionPointer->name.Peek_Buffer());
	}

	void GameDefinition::Name::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalGameDefinitionPointer->name = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}
	
	String ^GameDefinition::MapName::get()
	{
		return gcnew String(InternalGameDefinitionPointer->mapName.Peek_Buffer());
	}

	void GameDefinition::MapName::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalGameDefinitionPointer->mapName = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	String ^GameDefinition::ServerPresetsFile::get()
	{
		return gcnew String(InternalGameDefinitionPointer->serverPresetsFile.Peek_Buffer());
	}

	void GameDefinition::ServerPresetsFile::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalGameDefinitionPointer->serverPresetsFile = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	ISimpleVecClass<uint32> ^GameDefinition::Packages::get()
	{
		return gcnew uint32SimpleVecClass(IntPtr(&InternalGameDefinitionPointer->packages));
	}

	void GameDefinition::Packages::set(ISimpleVecClass<uint32> ^value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalGameDefinitionPointer->packages = *reinterpret_cast<::SimpleVecClass<uint32> *>(value->Pointer.ToPointer());
	}

	String ^GameDefinition::DisplayName::get()
	{
		return gcnew String(InternalGameDefinitionPointer->GetDisplayName().Peek_Buffer());
	}

	bool GameDefinition::InternalDestroyPointer()
	{
		Imports::DestroyGameDefinition(InternalGameDefinitionPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::GameDefinition *GameDefinition::InternalGameDefinitionPointer::get()
	{
		return reinterpret_cast<::GameDefinition *>(Pointer.ToPointer());
	}
}