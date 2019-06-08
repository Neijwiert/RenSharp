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

#pragma once

#include "MSList.h"

namespace RenSharp
{
	interface class IBaseGameObj;
	interface class IBuildingGameObj;
	interface class ISoldierGameObj;
	interface class ISmartGameObj;
	interface class IC4GameObj;
	interface class IBeaconGameObj;
	interface class IVehicleGameObj;
	interface class IScriptZoneGameObj;

	public ref class GameObjManager abstract sealed
	{
		public:
			static ISmartGameObj ^FindSmartGameObj(int networkId);
			static void Add(IBaseGameObj ^obj);
			static void Remove(IBaseGameObj ^obj);
			static void AddBuilding(IBuildingGameObj ^obj);
			static void RemoveBuilding(IBuildingGameObj ^obj);

			static property ISList<IBaseGameObj ^> ^GameObjList
			{
				ISList<IBaseGameObj ^> ^get();
			}

			static property ISList<IBuildingGameObj ^> ^BuildingGameObjList
			{
				ISList<IBuildingGameObj ^> ^get();
			}

			static property ISList<ISoldierGameObj ^> ^StarGameObjList
			{
				ISList<ISoldierGameObj ^> ^get();
			}

			static property ISList<ISmartGameObj ^> ^SmartGameObjList
			{
				ISList<ISmartGameObj ^> ^get();
			}

			static property ISList<IC4GameObj ^> ^C4GameObjList
			{
				ISList<IC4GameObj ^> ^get();
			}

			static property ISList<IBeaconGameObj ^> ^BeaconGameObjList
			{
				ISList<IBeaconGameObj ^> ^get();
			}

			static property ISList<ISoldierGameObj ^> ^SoldierGameObjList
			{
				ISList<ISoldierGameObj ^> ^get();
			}

			static property ISList<IVehicleGameObj ^> ^VehicleGameObjList
			{
				ISList<IVehicleGameObj ^> ^get();
			}

			static property ISList<IScriptZoneGameObj ^> ^ScriptZoneGameObjList
			{
				ISList<IScriptZoneGameObj ^> ^get();
			}
	};
}