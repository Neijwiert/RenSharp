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
#include "MVehicleFactoryGameObj.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4091 4251 4244 26495 26454)
#include <VehicleFactoryGameObj.h>
#include <VehicleFactoryGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MVehicleFactoryGameObjDef.h"
#include "MSoldierGameObj.h"
#include "MMatrix3D.h"
#include "MReferencerClass.h"
#include "Mobboxclass.h"

namespace RenSharp
{

#pragma managed(push, off)

	class VehicleFactoryGameObjHelper : public ::VehicleFactoryGameObj
	{
		private:
			VehicleFactoryGameObjHelper() = default;

		public:
			void DestroyBlockingObjects()
			{
				Destroy_Blocking_Objects();
			}

			void BeginGeneration()
			{
				Begin_Generation();
			}

			void OnGenerationComplete()
			{
				On_Generation_Complete();
			}

			int &GetGeneratingVehicleID()
			{
				return GeneratingVehicleID;
			}

			::ReferencerClass &GetPurchaser()
			{
				return Purchaser;
			}

			::ReferencerClass &GetVehicle()
			{
				return Vehicle;
			}

			::OBBoxClass &GetGeneratingRegion()
			{
				return GeneratingRegion;
			}

			float &GetGenerationTime()
			{
				return GenerationTime;
			}

			int &GetLastDeliveryPath()
			{
				return LastDeliveryPath;
			}

			int &GetLastFlyingDeliveryPath()
			{
				return LastFlyingDeliveryPath;
			}

			float &GetEndTimer()
			{
				return EndTimer;
			}
	};

#pragma managed(pop)

	VehicleFactoryGameObj::VehicleFactoryGameObj(IntPtr pointer)
		: BuildingGameObj(pointer)
	{

	}

	IVehicleFactoryGameObj ^VehicleFactoryGameObj::AsVehicleFactoryGameObj()
	{
		return this;
	}

	bool VehicleFactoryGameObj::RequestVehicle(int definitionId, float generationTime, ISoldierGameObj ^player)
	{
		if (player == nullptr || player->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			return InternalVehicleFactoryGameObjPointer->Request_Vehicle(definitionId, generationTime, nullptr);
		}
		else
		{
			return InternalVehicleFactoryGameObjPointer->Request_Vehicle(definitionId, generationTime, reinterpret_cast<::SoldierGameObj *>(player->SoldierGameObjPointer.ToPointer()));
		}
	}

	bool VehicleFactoryGameObj::RequestVehicle(int definitionId, float generationTime)
	{
		return InternalVehicleFactoryGameObjPointer->Request_Vehicle(definitionId, generationTime);
	}

	IntPtr VehicleFactoryGameObj::VehicleFactoryGameObjPointer::get()
	{
		return IntPtr(InternalVehicleFactoryGameObjPointer);
	}

	IVehicleFactoryGameObjDef ^VehicleFactoryGameObj::Definition::get()
	{
		auto result = DefinitionClass::CreateDefinitionClassWrapper(&InternalVehicleFactoryGameObjPointer->Get_Definition());
		if (result != nullptr)
		{
			return safe_cast<IVehicleFactoryGameObjDef^>(result);
		}

		return gcnew VehicleFactoryGameObjDef(IntPtr(const_cast<::VehicleFactoryGameObjDef *>(&InternalVehicleFactoryGameObjPointer->Get_Definition())));
	}

	bool VehicleFactoryGameObj::IsAvailable::get()
	{
		return InternalVehicleFactoryGameObjPointer->Is_Available();
	}

	bool VehicleFactoryGameObj::IsBusy::get()
	{
		return InternalVehicleFactoryGameObjPointer->Is_Busy();
	}

	void VehicleFactoryGameObj::IsBusy::set(bool value)
	{
		InternalVehicleFactoryGameObjPointer->Set_Busy(value);
	}

	bool VehicleFactoryGameObj::IsDisabled::get()
	{
		return InternalVehicleFactoryGameObjPointer->Is_Disabled();
	}

	void VehicleFactoryGameObj::IsDisabled::set(bool value)
	{
		InternalVehicleFactoryGameObjPointer->Set_Disabled(value);
	}

	Matrix3D VehicleFactoryGameObj::CreationTM::get()
	{
		return Matrix3D(IntPtr(const_cast<::Matrix3D *>(&InternalVehicleFactoryGameObjPointer->Get_Creation_TM())));
	}

	void VehicleFactoryGameObj::CreationTM::set(Matrix3D value)
	{
		::Matrix3D tmp;
		Matrix3D::ManagedToUnmanagedMatrix3D(value, tmp);

		InternalVehicleFactoryGameObjPointer->Set_Creation_TM(tmp);
	}

	int VehicleFactoryGameObj::GeneratingVehicleID::get()
	{
		return InternalVehicleFactoryGameObjPointer->Get_Generating_Vehicle_ID();
	}

	void VehicleFactoryGameObj::GeneratingVehicleID::set(int value)
	{
		auto helper = reinterpret_cast<VehicleFactoryGameObjHelper *>(InternalVehicleFactoryGameObjPointer);

		auto &generatingVehicleID = helper->GetGeneratingVehicleID();

		generatingVehicleID = value;
	}

	IReferencerClass ^VehicleFactoryGameObj::Purchaser::get()
	{
		auto helper = reinterpret_cast<VehicleFactoryGameObjHelper *>(InternalVehicleFactoryGameObjPointer);

		auto &purchaser = helper->GetPurchaser();

		return gcnew ReferencerClass(IntPtr(&purchaser));
	}

	void VehicleFactoryGameObj::Purchaser::set(IReferencerClass ^value)
	{
		if (value == nullptr || value->ReferencerClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<VehicleFactoryGameObjHelper *>(InternalVehicleFactoryGameObjPointer);

		auto &purchaser = helper->GetPurchaser();

		purchaser = *reinterpret_cast<::ReferencerClass *>(value->ReferencerClassPointer.ToPointer());
	}

	void VehicleFactoryGameObj::DestroyBlockingObjects()
	{
		auto helper = reinterpret_cast<VehicleFactoryGameObjHelper *>(InternalVehicleFactoryGameObjPointer);

		helper->DestroyBlockingObjects();
	}

	void VehicleFactoryGameObj::BeginGeneration()
	{
		auto helper = reinterpret_cast<VehicleFactoryGameObjHelper *>(InternalVehicleFactoryGameObjPointer);

		helper->BeginGeneration();
	}

	void VehicleFactoryGameObj::OnGenerationComplete()
	{
		auto helper = reinterpret_cast<VehicleFactoryGameObjHelper *>(InternalVehicleFactoryGameObjPointer);

		helper->OnGenerationComplete();
	}

	::BuildingGameObj *VehicleFactoryGameObj::InternalBuildingGameObjPointer::get()
	{
		return InternalVehicleFactoryGameObjPointer;
	}

	::VehicleFactoryGameObj *VehicleFactoryGameObj::InternalVehicleFactoryGameObjPointer::get()
	{
		return reinterpret_cast<::VehicleFactoryGameObj *>(Pointer.ToPointer());
	}

	IReferencerClass ^VehicleFactoryGameObj::Vehicle::get()
	{
		auto helper = reinterpret_cast<VehicleFactoryGameObjHelper *>(InternalVehicleFactoryGameObjPointer);

		auto &vehicle = helper->GetVehicle();

		return gcnew ReferencerClass(IntPtr(&vehicle));
	}

	void VehicleFactoryGameObj::Vehicle::set(IReferencerClass ^value)
	{
		if (value == nullptr || value->ReferencerClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<VehicleFactoryGameObjHelper *>(InternalVehicleFactoryGameObjPointer);

		auto &vehicle = helper->GetVehicle();

		vehicle = *reinterpret_cast<::ReferencerClass *>(value->ReferencerClassPointer.ToPointer());
	}

	OBBoxClass VehicleFactoryGameObj::GeneratingRegion::get()
	{
		auto helper = reinterpret_cast<VehicleFactoryGameObjHelper *>(InternalVehicleFactoryGameObjPointer);

		auto &generatingRegion = helper->GetGeneratingRegion();

		return OBBoxClass(IntPtr(&generatingRegion));
	}

	void VehicleFactoryGameObj::GeneratingRegion::set(OBBoxClass value)
	{
		auto helper = reinterpret_cast<VehicleFactoryGameObjHelper *>(InternalVehicleFactoryGameObjPointer);

		auto &generatingRegion = helper->GetGeneratingRegion();

		OBBoxClass::ManagedToUnmanagedOBBoxClass(value, generatingRegion);
	}

	float VehicleFactoryGameObj::GenerationTime::get()
	{
		auto helper = reinterpret_cast<VehicleFactoryGameObjHelper *>(InternalVehicleFactoryGameObjPointer);

		auto &generationTime = helper->GetGenerationTime();

		return generationTime;
	}

	void VehicleFactoryGameObj::GenerationTime::set(float value)
	{
		auto helper = reinterpret_cast<VehicleFactoryGameObjHelper *>(InternalVehicleFactoryGameObjPointer);

		auto &generationTime = helper->GetGenerationTime();

		generationTime = value;
	}

	int VehicleFactoryGameObj::LastDeliveryPath::get()
	{
		auto helper = reinterpret_cast<VehicleFactoryGameObjHelper *>(InternalVehicleFactoryGameObjPointer);

		auto &lastDeliveryPath = helper->GetLastDeliveryPath();

		return lastDeliveryPath;
	}

	void VehicleFactoryGameObj::LastDeliveryPath::set(int value)
	{
		auto helper = reinterpret_cast<VehicleFactoryGameObjHelper *>(InternalVehicleFactoryGameObjPointer);

		auto &lastDeliveryPath = helper->GetLastDeliveryPath();

		lastDeliveryPath = value;
	}

	int VehicleFactoryGameObj::LastFlyingDeliveryPath::get()
	{
		auto helper = reinterpret_cast<VehicleFactoryGameObjHelper *>(InternalVehicleFactoryGameObjPointer);

		auto &lastFlyingDeliveryPath = helper->GetLastFlyingDeliveryPath();

		return lastFlyingDeliveryPath;
	}

	void VehicleFactoryGameObj::LastFlyingDeliveryPath::set(int value)
	{
		auto helper = reinterpret_cast<VehicleFactoryGameObjHelper *>(InternalVehicleFactoryGameObjPointer);

		auto &lastFlyingDeliveryPath = helper->GetLastFlyingDeliveryPath();

		lastFlyingDeliveryPath = value;
	}

	float VehicleFactoryGameObj::EndTimer::get()
	{
		auto helper = reinterpret_cast<VehicleFactoryGameObjHelper *>(InternalVehicleFactoryGameObjPointer);

		auto &endTimer = helper->GetEndTimer();

		return endTimer;
	}

	void VehicleFactoryGameObj::EndTimer::set(float value)
	{
		auto helper = reinterpret_cast<VehicleFactoryGameObjHelper *>(InternalVehicleFactoryGameObjPointer);

		auto &endTimer = helper->GetEndTimer();

		endTimer = value;
	}
}