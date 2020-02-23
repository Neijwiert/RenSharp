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
#include "MSpawnerDefClass.h"

#include "MInt32DynamicVectorClass.h"
#include "MStringClassDynamicVectorClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <SpawnerDefClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	SpawnerDefClass::SpawnerDefClass(IntPtr pointer)
		: DefinitionClass(pointer)
	{

	}

	IntPtr SpawnerDefClass::SpawnerDefClassPointer::get()
	{
		return IntPtr(InternalSpawnerDefClassPointer);
	}

	IDynamicVectorClass<int>^ SpawnerDefClass::SpawnDefinitionIDList::get()
	{
		return gcnew Int32DynamicVectorClass(IntPtr(&InternalSpawnerDefClassPointer->SpawnDefinitionIDList));
	}

	void SpawnerDefClass::SpawnDefinitionIDList::set(IDynamicVectorClass<int>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalSpawnerDefClassPointer->SpawnDefinitionIDList = *reinterpret_cast<::DynamicVectorClass<int>*>(value->Pointer.ToPointer());
	}

	sint32 SpawnerDefClass::PlayerType::get()
	{
		return InternalSpawnerDefClassPointer->PlayerType;
	}

	void SpawnerDefClass::PlayerType::set(sint32 value)
	{
		InternalSpawnerDefClassPointer->PlayerType = value;
	}

	sint32 SpawnerDefClass::SpawnMax::get()
	{
		return InternalSpawnerDefClassPointer->SpawnMax;
	}

	void SpawnerDefClass::SpawnMax::set(sint32 value)
	{
		InternalSpawnerDefClassPointer->SpawnMax = value;
	}

	float SpawnerDefClass::SpawnDelay::get()
	{
		return InternalSpawnerDefClassPointer->SpawnDelay;
	}

	void SpawnerDefClass::SpawnDelay::set(float value)
	{
		InternalSpawnerDefClassPointer->SpawnDelay = value;
	}

	float SpawnerDefClass::SpawnDelayVariation::get()
	{
		return InternalSpawnerDefClassPointer->SpawnDelayVariation;
	}

	void SpawnerDefClass::SpawnDelayVariation::set(float value)
	{
		InternalSpawnerDefClassPointer->SpawnDelayVariation = value;
	}

	bool SpawnerDefClass::IsPrimary::get()
	{
		return InternalSpawnerDefClassPointer->IsPrimary;
	}

	void SpawnerDefClass::IsPrimary::set(bool value)
	{
		InternalSpawnerDefClassPointer->IsPrimary = value;
	}

	bool SpawnerDefClass::IsSoldierStartup::get()
	{
		return InternalSpawnerDefClassPointer->IsSoldierStartup;
	}

	void SpawnerDefClass::IsSoldierStartup::set(bool value)
	{
		InternalSpawnerDefClassPointer->IsSoldierStartup = value;
	}

	bool SpawnerDefClass::GotoSpawnerPos::get()
	{
		return InternalSpawnerDefClassPointer->GotoSpawnerPos;
	}

	void SpawnerDefClass::GotoSpawnerPos::set(bool value)
	{
		InternalSpawnerDefClassPointer->GotoSpawnerPos = value;
	}

	float SpawnerDefClass::GotoSpawnerPosPriority::get()
	{
		return InternalSpawnerDefClassPointer->GotoSpawnerPosPriority;
	}

	void SpawnerDefClass::GotoSpawnerPosPriority::set(float value)
	{
		InternalSpawnerDefClassPointer->GotoSpawnerPosPriority = value;
	}

	bool SpawnerDefClass::TeleportFirstSpawn::get()
	{
		return InternalSpawnerDefClassPointer->TeleportFirstSpawn;
	}

	void SpawnerDefClass::TeleportFirstSpawn::set(bool value)
	{
		InternalSpawnerDefClassPointer->TeleportFirstSpawn = value;
	}

	sint32 SpawnerDefClass::SpecialEffectsObjID::get()
	{
		return InternalSpawnerDefClassPointer->SpecialEffectsObjID;
	}

	void SpawnerDefClass::SpecialEffectsObjID::set(sint32 value)
	{
		InternalSpawnerDefClassPointer->SpecialEffectsObjID = value;
	}

	float SpawnerDefClass::PostVisualSpawnDelay::get()
	{
		return InternalSpawnerDefClassPointer->PostVisualSpawnDelay;
	}

	void SpawnerDefClass::PostVisualSpawnDelay::set(float value)
	{
		InternalSpawnerDefClassPointer->PostVisualSpawnDelay = value;
	}

	bool SpawnerDefClass::StartsDisabled::get()
	{
		return InternalSpawnerDefClassPointer->StartsDisabled;
	}

	void SpawnerDefClass::StartsDisabled::set(bool value)
	{
		InternalSpawnerDefClassPointer->StartsDisabled = value;
	}

	bool SpawnerDefClass::KillHibernatingSpawn::get()
	{
		return InternalSpawnerDefClassPointer->KillHibernatingSpawn;
	}

	void SpawnerDefClass::KillHibernatingSpawn::set(bool value)
	{
		InternalSpawnerDefClassPointer->KillHibernatingSpawn = value;
	}

	bool SpawnerDefClass::ApplySpawnMaterialEffect::get()
	{
		return InternalSpawnerDefClassPointer->ApplySpawnMaterialEffect;
	}

	void SpawnerDefClass::ApplySpawnMaterialEffect::set(bool value)
	{
		InternalSpawnerDefClassPointer->ApplySpawnMaterialEffect = value;
	}

	bool SpawnerDefClass::IsMultiplayWeaponSpawner::get()
	{
		return InternalSpawnerDefClassPointer->IsMultiplayWeaponSpawner;
	}

	void SpawnerDefClass::IsMultiplayWeaponSpawner::set(bool value)
	{
		InternalSpawnerDefClassPointer->IsMultiplayWeaponSpawner = value;
	}

	IDynamicVectorClass<String^>^ SpawnerDefClass::ScriptNames::get()
	{
		return gcnew StringClassDynamicVectorClass(IntPtr(&InternalSpawnerDefClassPointer->ScriptNames));
	}

	void SpawnerDefClass::ScriptNames::set(IDynamicVectorClass<String^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalSpawnerDefClassPointer->ScriptNames = *reinterpret_cast<::DynamicVectorClass<::StringClass>*>(value->Pointer.ToPointer());
	}

	IDynamicVectorClass<String^>^ SpawnerDefClass::ScriptParameters::get()
	{
		return gcnew StringClassDynamicVectorClass(IntPtr(&InternalSpawnerDefClassPointer->ScriptParameters));
	}

	void SpawnerDefClass::ScriptParameters::set(IDynamicVectorClass<String^>^ value)
	{
		InternalSpawnerDefClassPointer->ScriptParameters = *reinterpret_cast<::DynamicVectorClass<::StringClass>*>(value->Pointer.ToPointer());
	}

	::DefinitionClass* SpawnerDefClass::InternalDefinitionClassPointer::get()
	{
		return InternalSpawnerDefClassPointer;
	}

	::SpawnerDefClass* SpawnerDefClass::InternalSpawnerDefClassPointer::get()
	{
		return reinterpret_cast<::SpawnerDefClass*>(Pointer.ToPointer());
	}
}