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
#include "MGameObjManager.h"

#include "MBaseGameObjSList.h"
#include "MBuildingGameObjSList.h"
#include "MSoldierGameObjSList.h"
#include "MSmartGameObjSList.h"
#include "MC4GameObjSList.h"
#include "MBeaconGameObjSList.h"
#include "MVehicleGameObjSList.h"
#include "MScriptZoneGameObjSList.h"
#include "MSmartGameObj.h"
#include "MBaseGameObj.h"
#include "MBuildingGameObj.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <GameObjManager.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	ISmartGameObj ^GameObjManager::FindSmartGameObj(int networkId)
	{
		auto result = ::GameObjManager::Find_SmartGameObj(networkId);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SmartGameObj(IntPtr(result));
		}
	}

	void GameObjManager::Add(IBaseGameObj ^obj)
	{
		if (obj == nullptr || obj->BaseGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::GameObjManager::Add(
			reinterpret_cast<::BaseGameObj *>(obj->BaseGameObjPointer.ToPointer()));
	}

	void GameObjManager::Remove(IBaseGameObj ^obj)
	{
		if (obj == nullptr || obj->BaseGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::GameObjManager::Remove(
			reinterpret_cast<::BaseGameObj *>(obj->BaseGameObjPointer.ToPointer()));
	}

	void GameObjManager::AddBuilding(IBuildingGameObj ^obj)
	{
		if (obj == nullptr || obj->BuildingGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::GameObjManager::Add_Building(
			reinterpret_cast<::BuildingGameObj *>(obj->BuildingGameObjPointer.ToPointer()));
	}

	void GameObjManager::RemoveBuilding(IBuildingGameObj ^obj)
	{
		if (obj == nullptr || obj->BuildingGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::GameObjManager::Remove_Building(
			reinterpret_cast<::BuildingGameObj *>(obj->BuildingGameObjPointer.ToPointer()));
	}

	ISList<IBaseGameObj ^> ^GameObjManager::GameObjList::get()
	{
		return gcnew BaseGameObjSList(IntPtr(&::GameObjManager::GameObjList));
	}

	ISList<IBuildingGameObj ^> ^GameObjManager::BuildingGameObjList::get()
	{
		return gcnew BuildingGameObjSList(IntPtr(&::GameObjManager::BuildingGameObjList));
	}

	ISList<ISoldierGameObj ^> ^GameObjManager::StarGameObjList::get()
	{
		return gcnew SoldierGameObjSList(IntPtr(&::GameObjManager::StarGameObjList));
	}

	ISList<ISmartGameObj ^> ^GameObjManager::SmartGameObjList::get()
	{
		return gcnew SmartGameObjSList(IntPtr(&::GameObjManager::SmartGameObjList));
	}

	ISList<IC4GameObj ^> ^GameObjManager::C4GameObjList::get()
	{
		return gcnew C4GameObjSList(IntPtr(&::GameObjManager::C4GameObjList));
	}

	ISList<IBeaconGameObj ^> ^GameObjManager::BeaconGameObjList::get()
	{
		return gcnew BeaconGameObjSList(IntPtr(&::GameObjManager::BeaconGameObjList));
	}

	ISList<ISoldierGameObj ^> ^GameObjManager::SoldierGameObjList::get()
	{
		return gcnew SoldierGameObjSList(IntPtr(&::GameObjManager::SoldierGameObjList));
	}

	ISList<IVehicleGameObj ^> ^GameObjManager::VehicleGameObjList::get()
	{
		return gcnew VehicleGameObjSList(IntPtr(&::GameObjManager::VehicleGameObjList));
	}

	ISList<IScriptZoneGameObj ^> ^GameObjManager::ScriptZoneGameObjList::get()
	{
		return gcnew ScriptZoneGameObjSList(IntPtr(&::GameObjManager::ScriptZoneGameObjList));
	}
}