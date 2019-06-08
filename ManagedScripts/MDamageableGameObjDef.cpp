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
#include "MDamageableGameObjDef.h"

#include "MDefenseObjectDefClass.h"

namespace RenSharp
{
	DamageableGameObjDef::DamageableGameObjDef(IntPtr pointer)
		: ScriptableGameObjDef(pointer)
	{

	}

	IntPtr DamageableGameObjDef::DamageableGameObjDefPointer::get()
	{
		return IntPtr(InternalDamageableGameObjDefPointer);
	}

	int DamageableGameObjDef::NameID::get()
	{
		return InternalDamageableGameObjDefPointer->Get_Name_ID();
	}

	void DamageableGameObjDef::NameID::set(int value)
	{
		InternalDamageableGameObjDefPointer->Set_Name_ID(value);
	}

	int DamageableGameObjDef::EncyclopediaType::get()
	{
		return InternalDamageableGameObjDefPointer->EncyclopediaType;
	}

	void DamageableGameObjDef::EncyclopediaType::set(int value)
	{
		InternalDamageableGameObjDefPointer->EncyclopediaType = value;
	}

	int DamageableGameObjDef::EncyclopediaID::get()
	{
		return InternalDamageableGameObjDefPointer->EncyclopediaID;
	}

	void DamageableGameObjDef::EncyclopediaID::set(int value)
	{
		InternalDamageableGameObjDefPointer->EncyclopediaID = value;
	}

	String ^DamageableGameObjDef::InfoIconTextureFilename::get()
	{
		return gcnew String(InternalDamageableGameObjDefPointer->InfoIconTextureFilename.Peek_Buffer());
	}

	void DamageableGameObjDef::InfoIconTextureFilename::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalDamageableGameObjDefPointer->InfoIconTextureFilename = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	int DamageableGameObjDef::TranslatedNameID::get()
	{
		return InternalDamageableGameObjDefPointer->Get_Translated_Name_ID();
	}

	void DamageableGameObjDef::TranslatedNameID::set(int value)
	{
		InternalDamageableGameObjDefPointer->Set_Translated_Name_ID(value);
	}

	IDefenseObjectDefClass ^DamageableGameObjDef::DefenseObjectDef::get()
	{
		return gcnew DefenseObjectDefClass(IntPtr(&InternalDamageableGameObjDefPointer->DefenseObjectDef));
	}

	void DamageableGameObjDef::DefenseObjectDef::set(IDefenseObjectDefClass ^value)
	{
		if (value == nullptr || value->DefenseObjectDefClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalDamageableGameObjDefPointer->DefenseObjectDef = *reinterpret_cast<::DefenseObjectDefClass *>(value->DefenseObjectDefClassPointer.ToPointer());
	}

	int DamageableGameObjDef::DefaultPlayerType::get()
	{
		return InternalDamageableGameObjDefPointer->DefaultPlayerType;
	}

	void DamageableGameObjDef::DefaultPlayerType::set(int value)
	{
		InternalDamageableGameObjDefPointer->DefaultPlayerType = value;
	}

	::ScriptableGameObjDef *DamageableGameObjDef::InternalScriptableGameObjDefPointer::get()
	{
		return InternalDamageableGameObjDefPointer;
	}

	::DamageableGameObjDef *DamageableGameObjDef::InternalDamageableGameObjDefPointer::get()
	{
		return reinterpret_cast<::DamageableGameObjDef *>(Pointer.ToPointer());
	}
}