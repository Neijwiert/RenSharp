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
#include "MHarvesterClass.h"

#include "MVehicleGameObj.h"
#include "MRefineryGameObj.h"
#include "MVector3.h"
#include "Mobboxclass.h"

namespace RenSharp
{
	HarvesterClass::HarvesterClass(IntPtr pointer)
		: GameObjObserverClass(pointer)
	{

	}

	void HarvesterClass::SetRefinery(IRefineryGameObj ^obj)
	{
		if (obj == nullptr || obj->RefineryGameObjPointer.ToPointer() == nullptr)
		{
			InternalHarvesterClassPointer->Set_Refinery(nullptr);
		}
		else
		{
			InternalHarvesterClassPointer->Set_Refinery(
				reinterpret_cast<::RefineryGameObj *>(obj->RefineryGameObjPointer.ToPointer()));
		}
	}

	void HarvesterClass::SetDockLocation(Vector3 location)
	{
		::Vector3 locationVec;

		Vector3::ManagedToUnmanagedVector3(location, locationVec);

		InternalHarvesterClassPointer->Set_Dock_Location(locationVec);
	}

	void HarvesterClass::SetDockEntrance(Vector3 location)
	{
		::Vector3 locationVec;

		Vector3::ManagedToUnmanagedVector3(location, locationVec);

		InternalHarvesterClassPointer->Set_Dock_Entrance(locationVec);
	}

	void HarvesterClass::SetTiberiumRegion(OBBoxClass region)
	{
		::OBBoxClass regionBox;

		OBBoxClass::ManagedToUnmanagedOBBoxClass(region, regionBox);

		InternalHarvesterClassPointer->Set_Tiberium_Region(regionBox);
	}

	void HarvesterClass::SetHarvestAnim(String ^anim)
	{
		if (anim == nullptr)
		{
			throw gcnew ArgumentNullException("anim");
		}

		IntPtr animHandle = Marshal::StringToHGlobalAnsi(anim);
		try
		{
			InternalHarvesterClassPointer->Set_Harvest_Anim(reinterpret_cast<char *>(animHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(animHandle);
		}
	}

	IntPtr HarvesterClass::HarvesterClassPointer::get()
	{
		return IntPtr(InternalHarvesterClassPointer);
	}

	IVehicleGameObj ^HarvesterClass::Vehicle::get()
	{
		auto result = InternalHarvesterClassPointer->Get_Vehicle();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IVehicleGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IHarvesterClass::HarvesterState HarvesterClass::State::get()
	{
		return static_cast<IHarvesterClass::HarvesterState>(InternalHarvesterClassPointer->Get_State());
	}

	::GameObjObserverClass *HarvesterClass::InternalGameObjObserverClassPointer::get()
	{
		return InternalHarvesterClassPointer;
	}

	::HarvesterClass *HarvesterClass::InternalHarvesterClassPointer::get()
	{
		return reinterpret_cast<::HarvesterClass *>(Pointer.ToPointer());
	}
}