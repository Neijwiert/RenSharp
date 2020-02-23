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
#include "Mda_translation.h"

#include "MDefinition.h"
#include "MWeaponClass.h"
#include "MScriptableGameObj.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_translation.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DATranslationManager::DATranslationManager(IntPtr pointer)
		: DAEventClass(pointer)
	{

	}

	String^ DATranslationManager::Translate(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::DATranslationManager::Translate(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String^ DATranslationManager::Translate(IWeaponClass^ weap)
	{
		if (weap == nullptr || weap->WeaponClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("weap");
		}

		auto result = ::DATranslationManager::Translate(
			reinterpret_cast<::WeaponClass*>(weap->WeaponClassPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String^ DATranslationManager::Translate(IDefinitionClass^ def)
	{
		if (def == nullptr || def->DefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("def");
		}

		auto result = ::DATranslationManager::Translate(
			reinterpret_cast<::DefinitionClass*>(def->DefinitionClassPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String^ DATranslationManager::Translate(String^ preset)
	{
		if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			auto result = ::DATranslationManager::Translate(
				reinterpret_cast<char*>(presetHandle.ToPointer()));
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
			Marshal::FreeHGlobal(presetHandle);
		}
	}

	String^ DATranslationManager::Translate(unsigned int defID)
	{
		auto result = ::DATranslationManager::Translate(defID);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String^ DATranslationManager::TranslateWithTeamName(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return gcnew String(::DATranslationManager::Translate_With_Team_Name(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer())).Peek_Buffer());
	}

	String^ DATranslationManager::TranslateWeapon(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::DATranslationManager::Translate_Weapon(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String^ DATranslationManager::TranslateSoldier(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return gcnew String(::DATranslationManager::Translate_Soldier(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer())).Peek_Buffer());
	}

	IntPtr DATranslationManager::DATranslationManagerPointer::get()
	{
		return IntPtr(InternalDATranslationManagerPointer);
	}

	::DAEventClass* DATranslationManager::InternalDAEventClassPointer::get()
	{
		return InternalDATranslationManagerPointer;
	}

	::DATranslationManager* DATranslationManager::InternalDATranslationManagerPointer::get()
	{
		return reinterpret_cast<::DATranslationManager*>(Pointer.ToPointer());
	}
}