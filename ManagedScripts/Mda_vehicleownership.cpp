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
#include "Mda_vehicleownership.h"

#include "MVehicleGameObj.h"
#include "McPlayer.h"
#include "UnmanagedContainer.h"
#include "Imports.h"
#include "MSoldierGameObj.h"

namespace RenSharp
{
	DAVehicleOwnershipObserverClass::DAVehicleOwnershipObserverClass(IVehicleGameObj^ vehicle, IcPlayer^ player)
	{
		if (vehicle == nullptr || vehicle->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("vehicle");
		}

		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			Pointer = IntPtr(Imports::CreateDAVehicleOwnershipObserverClass(
				reinterpret_cast<::VehicleGameObj*>(vehicle->VehicleGameObjPointer.ToPointer()),
				nullptr));
		}
		else
		{
			Pointer = IntPtr(Imports::CreateDAVehicleOwnershipObserverClass(
				reinterpret_cast<::VehicleGameObj*>(vehicle->VehicleGameObjPointer.ToPointer()),
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer())));
		}
	}

	DAVehicleOwnershipObserverClass::DAVehicleOwnershipObserverClass(IntPtr pointer)
		: DAGameObjObserverClass(pointer)
	{

	}

	IUnmanagedContainer<IDAVehicleOwnershipObserverClass^>^ DAVehicleOwnershipObserverClass::CreateDAVehicleOwnershipObserverClass(IVehicleGameObj^ vehicle, IcPlayer^ player)
	{
		return gcnew UnmanagedContainer<IDAVehicleOwnershipObserverClass^>(gcnew DAVehicleOwnershipObserverClass(vehicle, player));
	}

	void DAVehicleOwnershipObserverClass::CreateIcons()
	{
		InternalDAVehicleOwnershipObserverClassPointer->Create_Icons();
	}

	void DAVehicleOwnershipObserverClass::DestroyIcons()
	{
		InternalDAVehicleOwnershipObserverClassPointer->Destroy_Icons();
	}

	void DAVehicleOwnershipObserverClass::Lock()
	{
		InternalDAVehicleOwnershipObserverClassPointer->Lock();
	}

	void DAVehicleOwnershipObserverClass::Unlock()
	{
		InternalDAVehicleOwnershipObserverClassPointer->Unlock();
	}

	void DAVehicleOwnershipObserverClass::Sell()
	{
		InternalDAVehicleOwnershipObserverClassPointer->Sell();
	}

	void DAVehicleOwnershipObserverClass::Free()
	{
		InternalDAVehicleOwnershipObserverClassPointer->Free();
	}

	void DAVehicleOwnershipObserverClass::Unbind()
	{
		InternalDAVehicleOwnershipObserverClassPointer->Unbind();
	}

	IntPtr DAVehicleOwnershipObserverClass::DAVehicleOwnershipObserverClassPointer::get()
	{
		return IntPtr(InternalDAVehicleOwnershipObserverClassPointer);
	}

	bool DAVehicleOwnershipObserverClass::IsLocked::get()
	{
		return InternalDAVehicleOwnershipObserverClassPointer->Is_Locked();
	}

	bool DAVehicleOwnershipObserverClass::IsSelling::get()
	{
		return InternalDAVehicleOwnershipObserverClassPointer->Is_Selling();
	}

	bool DAVehicleOwnershipObserverClass::IsFree::get()
	{
		return InternalDAVehicleOwnershipObserverClassPointer->Is_Free();
	}

	IVehicleGameObj^ DAVehicleOwnershipObserverClass::Vehicle::get()
	{
		auto result = InternalDAVehicleOwnershipObserverClassPointer->Get_Vehicle();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IVehicleGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IcPlayer^ DAVehicleOwnershipObserverClass::VehicleOwner::get()
	{
		auto result = InternalDAVehicleOwnershipObserverClassPointer->Get_Vehicle_Owner();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	int DAVehicleOwnershipObserverClass::Team::get()
	{
		return InternalDAVehicleOwnershipObserverClassPointer->Get_Team();
	}

	::DAGameObjObserverClass* DAVehicleOwnershipObserverClass::InternalDAGameObjObserverClassPointer::get()
	{
		return InternalDAVehicleOwnershipObserverClassPointer;
	}

	::DAVehicleOwnershipObserverClass* DAVehicleOwnershipObserverClass::InternalDAVehicleOwnershipObserverClassPointer::get()
	{
		return reinterpret_cast<::DAVehicleOwnershipObserverClass*>(Pointer.ToPointer());
	}

	DAVehicleOwnershipGameFeatureClass::DAVehicleOwnershipGameFeatureClass(IntPtr pointer)
		: DAEventClass(pointer)
	{
		daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
	}

	String^ DAVehicleOwnershipGameFeatureClass::ToString()
	{
		return daGameFeatureClass->ToString();
	}

	bool DAVehicleOwnershipGameFeatureClass::Equals(Object^ other)
	{
		if (DAEventClass::Equals(other))
		{
			return true;
		}

		if (ReferenceEquals(other, nullptr))
		{
			return false;
		}

		auto otherUnmanagedObj = dynamic_cast<IUnmanagedObject^>(other);
		if (otherUnmanagedObj == nullptr || otherUnmanagedObj->Pointer.Equals(IntPtr::Zero))
		{
			return false;
		}

		auto otherDAGameFeatureClass = dynamic_cast<IDAGameFeatureClass^>(other);
		if (otherDAGameFeatureClass != nullptr)
		{
			if (daGameFeatureClass->Equals(otherDAGameFeatureClass))
			{
				return true;
			}
		}

		auto otherDAVehicleOwnershipGameFeatureClass = dynamic_cast<IDAVehicleOwnershipGameFeatureClass^>(other);
		if (otherDAVehicleOwnershipGameFeatureClass != nullptr)
		{
			if (DAVehicleOwnershipGameFeatureClassPointer.Equals(otherDAVehicleOwnershipGameFeatureClass->DAVehicleOwnershipGameFeatureClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void DAVehicleOwnershipGameFeatureClass::Init()
	{
		daGameFeatureClass->Init();
	}

	IRenSharpGameFeatureClass^ DAVehicleOwnershipGameFeatureClass::AsManagedGameFeature()
	{
		return daGameFeatureClass->AsManagedGameFeature();
	}

	IDAVehicleOwnershipObserverClass^ DAVehicleOwnershipGameFeatureClass::BindVehicle(IVehicleGameObj^ vehicle, IcPlayer^ player)
	{
		if (vehicle == nullptr || vehicle->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("vehicle");
		}
		else if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		auto result = InternalDAVehicleOwnershipGameFeatureClassPointer->Bind_Vehicle(
			reinterpret_cast<::VehicleGameObj*>(vehicle->VehicleGameObjPointer.ToPointer()),
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAVehicleOwnershipObserverClass(IntPtr(result));
		}
	}

	bool DAVehicleOwnershipGameFeatureClass::UnbindVehicle(IVehicleGameObj^ vehicle)
	{
		if (vehicle == nullptr || vehicle->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("vehicle");
		}

		return InternalDAVehicleOwnershipGameFeatureClassPointer->Unbind_Vehicle(
			reinterpret_cast<::VehicleGameObj*>(vehicle->VehicleGameObjPointer.ToPointer()));
	}

	bool DAVehicleOwnershipGameFeatureClass::UnbindVehicle(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		return InternalDAVehicleOwnershipGameFeatureClassPointer->Unbind_Vehicle(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	bool DAVehicleOwnershipGameFeatureClass::LockVehicle(IVehicleGameObj^ vehicle)
	{
		if (vehicle == nullptr || vehicle->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("vehicle");
		}

		return InternalDAVehicleOwnershipGameFeatureClassPointer->Lock_Vehicle(
			reinterpret_cast<::VehicleGameObj*>(vehicle->VehicleGameObjPointer.ToPointer()));
	}

	bool DAVehicleOwnershipGameFeatureClass::LockVehicle(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		return InternalDAVehicleOwnershipGameFeatureClassPointer->Lock_Vehicle(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	bool DAVehicleOwnershipGameFeatureClass::UnlockVehicle(IVehicleGameObj^ vehicle)
	{
		if (vehicle == nullptr || vehicle->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("vehicle");
		}

		return InternalDAVehicleOwnershipGameFeatureClassPointer->Unlock_Vehicle(
			reinterpret_cast<::VehicleGameObj*>(vehicle->VehicleGameObjPointer.ToPointer()));
	}

	bool DAVehicleOwnershipGameFeatureClass::UnlockVehicle(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		return InternalDAVehicleOwnershipGameFeatureClassPointer->Unlock_Vehicle(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	IcPlayer^ DAVehicleOwnershipGameFeatureClass::GetVehicleOwner(IScriptableGameObj^ vehicle)
	{
		if (vehicle == nullptr || vehicle->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("vehicle");
		}

		auto result = InternalDAVehicleOwnershipGameFeatureClassPointer->Get_Vehicle_Owner(
			reinterpret_cast<::ScriptableGameObj*>(vehicle->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	IVehicleGameObj^ DAVehicleOwnershipGameFeatureClass::GetVehicle(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		auto result = InternalDAVehicleOwnershipGameFeatureClassPointer->Get_Vehicle(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IVehicleGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IDAVehicleOwnershipObserverClass^ DAVehicleOwnershipGameFeatureClass::GetVehicleData(IScriptableGameObj^ vehicle)
	{
		if (vehicle == nullptr || vehicle->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("vehicle");
		}

		auto result = InternalDAVehicleOwnershipGameFeatureClassPointer->Get_Vehicle_Data(
			reinterpret_cast<::ScriptableGameObj*>(vehicle->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAVehicleOwnershipObserverClass(IntPtr(result));
		}
	}

	IDAVehicleOwnershipObserverClass^ DAVehicleOwnershipGameFeatureClass::GetVehicleData(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		auto result = InternalDAVehicleOwnershipGameFeatureClassPointer->Get_Vehicle_Data(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAVehicleOwnershipObserverClass(IntPtr(result));
		}
	}

	IDAVehicleOwnershipObserverClass^ DAVehicleOwnershipGameFeatureClass::GetVehicleData(ISoldierGameObj^ soldier)
	{
		if (soldier == nullptr || soldier->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}

		auto result = InternalDAVehicleOwnershipGameFeatureClassPointer->Get_Vehicle_Data(
			reinterpret_cast<::SoldierGameObj*>(soldier->SoldierGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAVehicleOwnershipObserverClass(IntPtr(result));
		}
	}

	IDAGameFeatureRegistrant<IDAVehicleOwnershipGameFeatureClass^>^ DAVehicleOwnershipGameFeatureClass::Registrant::get()
	{
		return gcnew DAVehicleOwnershipGameFeatureClassDAGameFeatureRegistrant(IntPtr(&::DAVehicleOwnershipGameFeatureClassRegistrant));
	}

	IDAVehicleOwnershipGameFeatureClass^ DAVehicleOwnershipGameFeatureClass::Instance::get()
	{
		auto result = ::DAVehicleOwnershipGameFeatureClassRegistrant.Get_Instance();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAVehicleOwnershipGameFeatureClass(IntPtr(result));
		}
	}

	IntPtr DAVehicleOwnershipGameFeatureClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void DAVehicleOwnershipGameFeatureClass::Pointer::set(IntPtr value)
	{
		AbstractUnmanagedObject::Pointer::set(value);

		if (Pointer == IntPtr::Zero)
		{
			daGameFeatureClass = nullptr;
		}
		else
		{
			daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
		}
	}

	IntPtr DAVehicleOwnershipGameFeatureClass::DAVehicleOwnershipGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAVehicleOwnershipGameFeatureClassPointer);
	}

	IntPtr DAVehicleOwnershipGameFeatureClass::DAGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAGameFeatureClassPointer);
	}

	String^ DAVehicleOwnershipGameFeatureClass::Name::get()
	{
		return daGameFeatureClass->Name;
	}

	IDAGameFeatureFactoryClass^ DAVehicleOwnershipGameFeatureClass::Factory::get()
	{
		return daGameFeatureClass->Factory;
	}

	void DAVehicleOwnershipGameFeatureClass::Factory::set(IDAGameFeatureFactoryClass^ value)
	{
		daGameFeatureClass->Factory = value;
	}

	bool DAVehicleOwnershipGameFeatureClass::IsManagedGameFeature::get()
	{
		return daGameFeatureClass->IsManagedGameFeature;
	}

	float DAVehicleOwnershipGameFeatureClass::SellPercent::get()
	{
		return InternalDAVehicleOwnershipGameFeatureClassPointer->Get_Sell_Percent();
	}

	::DAEventClass* DAVehicleOwnershipGameFeatureClass::InternalDAEventClassPointer::get()
	{
		return InternalDAVehicleOwnershipGameFeatureClassPointer;
	}

	::DAGameFeatureClass* DAVehicleOwnershipGameFeatureClass::InternalDAGameFeatureClassPointer::get()
	{
		return InternalDAVehicleOwnershipGameFeatureClassPointer;
	}

	::DAVehicleOwnershipGameFeatureClass* DAVehicleOwnershipGameFeatureClass::InternalDAVehicleOwnershipGameFeatureClassPointer::get()
	{
		return reinterpret_cast<::DAVehicleOwnershipGameFeatureClass*>(Pointer.ToPointer());
	}

	DAVehicleOwnershipGameFeatureClassDAGameFeatureRegistrant::DAVehicleOwnershipGameFeatureClassDAGameFeatureRegistrant(IntPtr pointer)
		: DAGameFeatureRegistrant<IDAVehicleOwnershipGameFeatureClass^>(pointer)
	{

	}

	IntPtr DAVehicleOwnershipGameFeatureClassDAGameFeatureRegistrant::DAVehicleOwnershipGameFeatureClassDAGameFeatureRegistrantPointer::get()
	{
		return IntPtr(InternalDAVehicleOwnershipGameFeatureClassDAGameFeatureRegistrantPointer);
	}

	::DAGameFeatureFactoryClass* DAVehicleOwnershipGameFeatureClassDAGameFeatureRegistrant::InternalDAGameFeatureFactoryClassPointer::get()
	{
		return InternalDAVehicleOwnershipGameFeatureClassDAGameFeatureRegistrantPointer;
	}

	::DAGameFeatureRegistrant<::DAVehicleOwnershipGameFeatureClass>* DAVehicleOwnershipGameFeatureClassDAGameFeatureRegistrant::InternalDAVehicleOwnershipGameFeatureClassDAGameFeatureRegistrantPointer::get()
	{
		return reinterpret_cast<::DAGameFeatureRegistrant<::DAVehicleOwnershipGameFeatureClass>*>(Pointer.ToPointer());
	}
}