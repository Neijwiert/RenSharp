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
#include "MDefinitionMgrClass.h"

#include "MDefinition.h"

namespace RenSharp
{
	DefinitionMgrClass::DefinitionMgrClass(IntPtr pointer)
		: SaveLoadSubSystemClass(pointer)
	{

	}

	IDefinitionClass ^DefinitionMgrClass::FindDefinition(uint32 id, bool twiddle)
	{
		auto result = ::DefinitionMgrClass::Find_Definition(id, twiddle);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DefinitionClass(IntPtr(result));
		}
	}

	IDefinitionClass ^DefinitionMgrClass::FindNamedDefinition(String ^name, bool twiddle)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			auto result = ::DefinitionMgrClass::Find_Named_Definition(
				reinterpret_cast<char *>(nameHandle.ToPointer()),
				twiddle);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew DefinitionClass(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	IDefinitionClass ^DefinitionMgrClass::FindTypedDefinition(String ^name, uint32 classID, bool twiddle)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			auto result = ::DefinitionMgrClass::Find_Typed_Definition(
				reinterpret_cast<char *>(nameHandle.ToPointer()),
				classID,
				twiddle);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew DefinitionClass(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	void DefinitionMgrClass::RegisterDefinition(IDefinitionClass ^definition)
	{
		if (definition == nullptr || definition->DefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("definition");
		}

		::DefinitionMgrClass::Register_Definition(
			reinterpret_cast<::DefinitionClass *>(definition->DefinitionClassPointer.ToPointer()));
	}

	void DefinitionMgrClass::UnregisterDefinition(IDefinitionClass ^definition)
	{
		if (definition == nullptr || definition->DefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("definition");
		}

		::DefinitionMgrClass::Unregister_Definition(
			reinterpret_cast<::DefinitionClass *>(definition->DefinitionClassPointer.ToPointer()));
	}

	IDefinitionClass ^DefinitionMgrClass::GetFirst(uint32 id, IDefinitionMgrClass::IDType type)
	{
		auto result = ::DefinitionMgrClass::Get_First(
			id,
			static_cast<::DefinitionMgrClass::ID_TYPE>(type));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DefinitionClass(IntPtr(result));
		}
	}

	IDefinitionClass ^DefinitionMgrClass::GetFirst(uint32 id)
	{
		auto result = ::DefinitionMgrClass::Get_First(id);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DefinitionClass(IntPtr(result));
		}
	}

	IDefinitionClass ^DefinitionMgrClass::GetFirst()
	{
		auto result = ::DefinitionMgrClass::Get_First();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DefinitionClass(IntPtr(result));
		}
	}

	IDefinitionClass ^DefinitionMgrClass::GetNext(IDefinitionClass ^currDef, uint32 id, IDefinitionMgrClass::IDType type)
	{
		if (currDef == nullptr || currDef->DefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("currDef");
		}

		auto result = ::DefinitionMgrClass::Get_Next(
			reinterpret_cast<::DefinitionClass *>(currDef->DefinitionClassPointer.ToPointer()),
			id,
			static_cast<::DefinitionMgrClass::ID_TYPE>(type));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DefinitionClass(IntPtr(result));
		}
	}

	IDefinitionClass ^DefinitionMgrClass::GetNext(IDefinitionClass ^currDef, uint32 id)
	{
		if (currDef == nullptr || currDef->DefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("currDef");
		}

		auto result = ::DefinitionMgrClass::Get_Next(
			reinterpret_cast<::DefinitionClass *>(currDef->DefinitionClassPointer.ToPointer()),
			id);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DefinitionClass(IntPtr(result));
		}
	}

	IDefinitionClass ^DefinitionMgrClass::GetNext(IDefinitionClass ^currDef)
	{
		if (currDef == nullptr || currDef->DefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("currDef");
		}

		auto result = ::DefinitionMgrClass::Get_Next(
			reinterpret_cast<::DefinitionClass *>(currDef->DefinitionClassPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DefinitionClass(IntPtr(result));
		}
	}

	void DefinitionMgrClass::FreeDefinitions()
	{
		::DefinitionMgrClass::Free_Definitions();
	}

	IntPtr DefinitionMgrClass::DefinitionMgrClassPointer::get()
	{
		return IntPtr(InternalDefinitionMgrClassPointer);
	}

	::SaveLoadSubSystemClass *DefinitionMgrClass::InternalSaveLoadSubSystemClassPointer::get()
	{
		return InternalDefinitionMgrClassPointer;
	}

	::DefinitionMgrClass *DefinitionMgrClass::InternalDefinitionMgrClassPointer::get()
	{
		return reinterpret_cast<::DefinitionMgrClass *>(Pointer.ToPointer());
	}
}