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
#include "Mda_levelcleaner.h"

#include "Mengine_io.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_levelcleaner.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	void DALevelCleaner::CleanLevel()
	{
		::DALevelCleaner::Clean_Level();
	}

	void DALevelCleaner::DestroySPBuildings()
	{
		::DALevelCleaner::Destroy_SP_Buildings();
	}

	void DALevelCleaner::DestroySPObjects()
	{
		::DALevelCleaner::Destroy_SP_Objects();
	}

	void DALevelCleaner::DestroySPSpawners()
	{
		::DALevelCleaner::Destroy_SP_Spawners();
	}

	void DALevelCleaner::LoadBlockers(IINIClass^ ini)
	{
		if (ini == nullptr || ini->INIClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("ini");
		}

		::DALevelCleaner::Load_Blockers(
			reinterpret_cast<::INIClass*>(ini->INIClassPointer.ToPointer()));
	}
}