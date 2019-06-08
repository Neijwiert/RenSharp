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
#include "MBuildingGameObjDef.h"

namespace RenSharp
{
	BuildingGameObjDef::BuildingGameObjDef(IntPtr pointer)
		: DamageableGameObjDef(pointer)
	{

	}

	IntPtr BuildingGameObjDef::BuildingGameObjDefPointer::get()
	{
		return IntPtr(InternalBuildingGameObjDefPointer);
	}

	BuildingType BuildingGameObjDef::Type::get()
	{
		return static_cast<BuildingType>(InternalBuildingGameObjDefPointer->Get_Type());
	}

	void BuildingGameObjDef::Type::set(BuildingType value)
	{
		InternalBuildingGameObjDefPointer->Set_Type(static_cast<BuildingConstants::BuildingType>(value));
	}

	String ^BuildingGameObjDef::MeshPrefix::get()
	{
		return gcnew String(InternalBuildingGameObjDefPointer->Get_Mesh_Prefix().Peek_Buffer());
	}

	void BuildingGameObjDef::MeshPrefix::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalBuildingGameObjDefPointer->MeshPrefix = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	unsigned int BuildingGameObjDef::MCTSkin::get()
	{
		return InternalBuildingGameObjDefPointer->MCTSkin;
	}

	void BuildingGameObjDef::MCTSkin::set(unsigned int value)
	{
		InternalBuildingGameObjDefPointer->MCTSkin = value;
	}

	int BuildingGameObjDef::GDIDamageReportID::get()
	{
		return InternalBuildingGameObjDefPointer->GDIDamageReportID;
	}

	void BuildingGameObjDef::GDIDamageReportID::set(int value)
	{
		InternalBuildingGameObjDefPointer->GDIDamageReportID = value;
	}

	int BuildingGameObjDef::NodDamageReportID::get()
	{
		return InternalBuildingGameObjDefPointer->NodDamageReportID;
	}

	void BuildingGameObjDef::NodDamageReportID::set(int value)
	{
		InternalBuildingGameObjDefPointer->NodDamageReportID = value;
	}

	int BuildingGameObjDef::GDIDestroyReportID::get()
	{
		return InternalBuildingGameObjDefPointer->GDIDestroyReportID;
	}

	void BuildingGameObjDef::GDIDestroyReportID::set(int value)
	{
		InternalBuildingGameObjDefPointer->GDIDestroyReportID = value;
	}

	int BuildingGameObjDef::NodDestroyReportID::get()
	{
		return InternalBuildingGameObjDefPointer->NodDestroyReportID;
	}

	void BuildingGameObjDef::NodDestroyReportID::set(int value)
	{
		InternalBuildingGameObjDefPointer->NodDestroyReportID = value;
	}

	::DamageableGameObjDef *BuildingGameObjDef::InternalDamageableGameObjDefPointer::get()
	{
		return InternalBuildingGameObjDefPointer;
	}

	::BuildingGameObjDef *BuildingGameObjDef::InternalBuildingGameObjDefPointer::get()
	{
		return reinterpret_cast<::BuildingGameObjDef *>(Pointer.ToPointer());
	}
}