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
#include "Mda_vehicle.h"

#include "McPlayer.h"
#include "MVehicleGameObj.h"
#include "MVehicleGameObjDef.h"
#include "MVector3.h"
#include "Imports.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_vehicle.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DAVehicleObserverClass::DAVehicleObserverClass(IntPtr pointer)
		: DAGameObjObserverClass(pointer)
	{

	}

	void DAVehicleObserverClass::ResetLastExitTime()
	{
		InternalDAVehicleObserverClassPointer->Reset_Last_Exit_Time();
	}

	void DAVehicleObserverClass::ResetLastTheftTime()
	{
		InternalDAVehicleObserverClassPointer->Reset_Last_Theft_Time();
	}

	IntPtr DAVehicleObserverClass::DAVehicleObserverClassPointer::get()
	{
		return IntPtr(InternalDAVehicleObserverClassPointer);
	}

	IcPlayer^ DAVehicleObserverClass::VehicleOwner::get()
	{
		auto result = InternalDAVehicleObserverClassPointer->Get_Vehicle_Owner();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	void DAVehicleObserverClass::VehicleOwner::set(IcPlayer^ value)
	{
		if (value == nullptr || value->cPlayerPointer.ToPointer() == nullptr)
		{
			InternalDAVehicleObserverClassPointer->Set_Vehicle_Owner(nullptr);
		}
		else
		{
			InternalDAVehicleObserverClassPointer->Set_Vehicle_Owner(
				reinterpret_cast<::cPlayer*>(value->cPlayerPointer.ToPointer()));
		}
	}

	int DAVehicleObserverClass::Team::get()
	{
		return InternalDAVehicleObserverClassPointer->Get_Team();
	}

	void DAVehicleObserverClass::Team::set(int value)
	{
		InternalDAVehicleObserverClassPointer->Set_Team(value);
	}

	unsigned int DAVehicleObserverClass::TimeSinceLastExit::get()
	{
		return InternalDAVehicleObserverClassPointer->Get_Time_Since_Last_Exit();
	}

	unsigned int DAVehicleObserverClass::TimeSinceLastTheft::get()
	{
		return InternalDAVehicleObserverClassPointer->Get_Time_Since_Last_Theft();
	}

	IVehicleGameObj^ DAVehicleObserverClass::Vehicle::get()
	{
		auto result = InternalDAVehicleObserverClassPointer->Get_Vehicle();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IVehicleGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	::DAGameObjObserverClass* DAVehicleObserverClass::InternalDAGameObjObserverClassPointer::get()
	{
		return InternalDAVehicleObserverClassPointer;
	}

	::DAVehicleObserverClass* DAVehicleObserverClass::InternalDAVehicleObserverClassPointer::get()
	{
		return reinterpret_cast<::DAVehicleObserverClass*>(Pointer.ToPointer());
	}

	DAAirDroppedVehicleObserverClass::DAAirDroppedVehicleObserverClass(IntPtr pointer)
		: DAGameObjObserverClass(pointer)
	{

	}

	IntPtr DAAirDroppedVehicleObserverClass::DAAirDroppedVehicleObserverClassPointer::get()
	{
		return IntPtr(InternalDAAirDroppedVehicleObserverClassPointer);
	}

	::DAGameObjObserverClass* DAAirDroppedVehicleObserverClass::InternalDAGameObjObserverClassPointer::get()
	{
		return InternalDAAirDroppedVehicleObserverClassPointer;
	}

	::DAAirDroppedVehicleObserverClass* DAAirDroppedVehicleObserverClass::InternalDAAirDroppedVehicleObserverClassPointer::get()
	{
		return reinterpret_cast<::DAAirDroppedVehicleObserverClass*>(Pointer.ToPointer());
	}

	DAVehicleManager::DAVehicleManager(IntPtr pointer)
		: DAEventClass(pointer)
	{

	}

	bool DAVehicleManager::CheckLimitForPlayer(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		return ::DAVehicleManager::Check_Limit_For_Player(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	IDAVehicleObserverClass^ DAVehicleManager::GetVehicleData(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::DAVehicleManager::Get_Vehicle_Data(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAVehicleObserverClass(IntPtr(result));
		}
	}

	IcPlayer^ DAVehicleManager::GetVehicleOwner(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::DAVehicleManager::Get_Vehicle_Owner(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	int DAVehicleManager::GetTeam(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::DAVehicleManager::Get_Team(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void DAVehicleManager::AirDropVehicle(int team, IVehicleGameObj^ vehicle, Vector3 position, float facing)
	{
		if (vehicle == nullptr || vehicle->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("vehicle");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		::DAVehicleManager::Air_Drop_Vehicle(
			team,
			reinterpret_cast<::VehicleGameObj*>(vehicle->VehicleGameObjPointer.ToPointer()),
			positionVec,
			facing);
	}

	IVehicleGameObj^ DAVehicleManager::AirDropVehicle(int team, IVehicleGameObjDef^ vehicle, Vector3 position, float facing)
	{
		if (vehicle == nullptr || vehicle->VehicleGameObjDefPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("vehicle");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		auto result = ::DAVehicleManager::Air_Drop_Vehicle(
			team,
			reinterpret_cast<::VehicleGameObjDef*>(vehicle->VehicleGameObjDefPointer.ToPointer()),
			positionVec,
			facing);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IVehicleGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IVehicleGameObj^ DAVehicleManager::AirDropVehicle(int team, unsigned int vehicle, Vector3 position, float facing)
	{
		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		auto result = ::DAVehicleManager::Air_Drop_Vehicle(
			team,
			vehicle,
			positionVec,
			facing);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IVehicleGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IVehicleGameObj^ DAVehicleManager::AirDropVehicle(int team, String^ vehicle, Vector3 position, float facing)
	{
		if (vehicle == nullptr)
		{
			throw gcnew ArgumentNullException("vehicle");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		IntPtr vehicleHandle = Marshal::StringToHGlobalAnsi(vehicle);
		try
		{
			auto result = ::DAVehicleManager::Air_Drop_Vehicle(
				team,
				reinterpret_cast<char*>(vehicleHandle.ToPointer()),
				positionVec,
				facing);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return safe_cast<IVehicleGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(vehicleHandle);
		}
	}

	IntPtr DAVehicleManager::DAVehicleManagerPointer::get()
	{
		return IntPtr(InternalDAVehicleManagerPointer);
	}

	::DAEventClass* DAVehicleManager::InternalDAEventClassPointer::get()
	{
		return InternalDAVehicleManagerPointer;
	}

	::DAVehicleManager* DAVehicleManager::InternalDAVehicleManagerPointer::get()
	{
		return reinterpret_cast<::DAVehicleManager*>(Pointer.ToPointer());
	}
}