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
#include "MScriptZoneGameObjDef.h"

#include "MVector3.h"

namespace RenSharp
{
	ScriptZoneGameObjDef::ScriptZoneGameObjDef(IntPtr pointer)
		: ScriptableGameObjDef(pointer)
	{

	}

	IntPtr ScriptZoneGameObjDef::ScriptZoneGameObjDefPointer::get()
	{
		return IntPtr(InternalScriptZoneGameObjDefPointer);
	}

	RenSharp::ZoneType ScriptZoneGameObjDef::ZoneType::get()
	{
		return static_cast<RenSharp::ZoneType>(InternalScriptZoneGameObjDefPointer->Get_Type());
	}

	void ScriptZoneGameObjDef::ZoneType::set(RenSharp::ZoneType value)
	{
		InternalScriptZoneGameObjDefPointer->ZoneType = static_cast<ZoneConstants::ZoneType>(value);
	}

	Drawing::Color ScriptZoneGameObjDef::Color::get()
	{
		auto &color = const_cast<::Vector3 &>(InternalScriptZoneGameObjDefPointer->Get_Color());

		return Drawing::Color::FromArgb(255, static_cast<int>(color.X * 255.0f), static_cast<int>(color.Y * 255.0f), static_cast<int>(color.Z * 255.0f));
	}

	void ScriptZoneGameObjDef::Color::set(Drawing::Color value)
	{
		::Vector3 tmp(value.R / 255.0f, value.G / 255.0f, value.B / 255.0f);

		InternalScriptZoneGameObjDefPointer->Color = tmp;
	}

	bool ScriptZoneGameObjDef::Unknown1::get()
	{
		return InternalScriptZoneGameObjDefPointer->unk;
	}

	void ScriptZoneGameObjDef::Unknown1::set(bool value)
	{
		InternalScriptZoneGameObjDefPointer->unk = value;
	}

	bool ScriptZoneGameObjDef::CheckStarsOnly::get()
	{
		return InternalScriptZoneGameObjDefPointer->CheckStarsOnly;
	}

	void ScriptZoneGameObjDef::CheckStarsOnly::set(bool value)
	{
		InternalScriptZoneGameObjDefPointer->CheckStarsOnly = value;
	}

	bool ScriptZoneGameObjDef::IsEnvironmentZone::get()
	{
		return InternalScriptZoneGameObjDefPointer->IsEnvironmentZone;
	}

	void ScriptZoneGameObjDef::IsEnvironmentZone::set(bool value)
	{
		InternalScriptZoneGameObjDefPointer->IsEnvironmentZone = value;
	}

	bool ScriptZoneGameObjDef::CheckC4::get()
	{
		return InternalScriptZoneGameObjDefPointer->CheckC4;
	}

	void ScriptZoneGameObjDef::CheckC4::set(bool value)
	{
		InternalScriptZoneGameObjDefPointer->CheckC4 = value;
	}

	int ScriptZoneGameObjDef::PresetID::get()
	{
		return InternalScriptZoneGameObjDefPointer->Get_Preset_ID();
	}

	void ScriptZoneGameObjDef::PresetID::set(int value)
	{
		InternalScriptZoneGameObjDefPointer->PresetID = value;
	}

	String ^ScriptZoneGameObjDef::ModelName::get()
	{
		return gcnew String(InternalScriptZoneGameObjDefPointer->ModelName.Peek_Buffer());
	}

	void ScriptZoneGameObjDef::ModelName::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalScriptZoneGameObjDefPointer->ModelName = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	::ScriptableGameObjDef *ScriptZoneGameObjDef::InternalScriptableGameObjDefPointer::get()
	{
		return InternalScriptZoneGameObjDefPointer;
	}

	::ScriptZoneGameObjDef *ScriptZoneGameObjDef::InternalScriptZoneGameObjDefPointer::get()
	{
		return reinterpret_cast<::ScriptZoneGameObjDef *>(Pointer.ToPointer());
	}
}