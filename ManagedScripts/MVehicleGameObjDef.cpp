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
#include "MVehicleGameObjDef.h"

#include "MTransitionDataClassPtrDynamicVectorClass.h"
#include "MVector3.h"

namespace RenSharp
{
	VehicleGameObjDef::VehicleGameObjDef(IntPtr pointer)
		: SmartGameObjDef(pointer)
	{

	}

	int VehicleGameObjDef::GetEngineSound(VehicleType type)
	{
		return InternalVehicleGameObjDefPointer->Get_Engine_Sound(static_cast<int>(type));
	}

	IntPtr VehicleGameObjDef::VehicleGameObjDefPointer::get()
	{
		return IntPtr(InternalVehicleGameObjDefPointer);
	}

	VehicleType VehicleGameObjDef::Type::get()
	{
		return static_cast<VehicleType>(InternalVehicleGameObjDefPointer->Type);
	}

	void VehicleGameObjDef::Type::set(VehicleType value)
	{
		InternalVehicleGameObjDefPointer->Type = static_cast<::VehicleType>(value);
	}

	String ^VehicleGameObjDef::TypeName::get()
	{
		return gcnew String(InternalVehicleGameObjDefPointer->TypeName.Peek_Buffer());
	}

	void VehicleGameObjDef::TypeName::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalVehicleGameObjDefPointer->TypeName = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	String ^VehicleGameObjDef::Fire0Anim::get()
	{
		return gcnew String(InternalVehicleGameObjDefPointer->Fire0Anim.Peek_Buffer());
	}

	void VehicleGameObjDef::Fire0Anim::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalVehicleGameObjDefPointer->Fire0Anim = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	String ^VehicleGameObjDef::Fire1Anim::get()
	{
		return gcnew String(InternalVehicleGameObjDefPointer->Fire1Anim.Peek_Buffer());
	}

	void VehicleGameObjDef::Fire1Anim::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalVehicleGameObjDefPointer->Fire1Anim = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	String ^VehicleGameObjDef::Profile::get()
	{
		return gcnew String(InternalVehicleGameObjDefPointer->Profile.Peek_Buffer());
	}

	void VehicleGameObjDef::Profile::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalVehicleGameObjDefPointer->Profile = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	IDynamicVectorClass<ITransitionDataClass ^> ^VehicleGameObjDef::Transitions::get()
	{
		return gcnew TransitionDataClassPtrDynamicVectorClass(IntPtr(&InternalVehicleGameObjDefPointer->Transitions));
	}

	void VehicleGameObjDef::Transitions::set(IDynamicVectorClass<ITransitionDataClass ^> ^value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalVehicleGameObjDefPointer->Transitions = *reinterpret_cast<::DynamicVectorClass<::TransitionDataClass *> *>(value->Pointer.ToPointer());
	}

	float VehicleGameObjDef::TurnRadius::get()
	{
		return InternalVehicleGameObjDefPointer->TurnRadius;
	}

	void VehicleGameObjDef::TurnRadius::set(float value)
	{
		InternalVehicleGameObjDefPointer->TurnRadius = value;
	}

	bool VehicleGameObjDef::OccupantsVisible::get()
	{
		return InternalVehicleGameObjDefPointer->OccupantsVisible;
	}

	void VehicleGameObjDef::OccupantsVisible::set(bool value)
	{
		InternalVehicleGameObjDefPointer->OccupantsVisible = value;
	}

	bool VehicleGameObjDef::SightDownMuzzle::get()
	{
		return InternalVehicleGameObjDefPointer->SightDownMuzzle;
	}

	void VehicleGameObjDef::SightDownMuzzle::set(bool value)
	{
		InternalVehicleGameObjDefPointer->SightDownMuzzle = value;
	}

	bool VehicleGameObjDef::Aim2D::get()
	{
		return InternalVehicleGameObjDefPointer->Aim2D;
	}

	void VehicleGameObjDef::Aim2D::set(bool value)
	{
		InternalVehicleGameObjDefPointer->Aim2D = value;
	}

	float VehicleGameObjDef::EngineSoundMaxPitchFactor::get()
	{
		return InternalVehicleGameObjDefPointer->EngineSoundMaxPitchFactor;
	}

	void VehicleGameObjDef::EngineSoundMaxPitchFactor::set(float value)
	{
		InternalVehicleGameObjDefPointer->EngineSoundMaxPitchFactor = value;
	}

	array<int> ^VehicleGameObjDef::EngineSound::get()
	{
		array<int> ^result = gcnew array<int>(::MAX_ENGINE_SOUND_STATES);

		for (int x = 0; x < result->Length; x++)
		{
			result[x] = InternalVehicleGameObjDefPointer->EngineSound[x];
		}

		return result;
	}

	void VehicleGameObjDef::EngineSound::set(array<int> ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}
		else if (value->Length != ::MAX_ENGINE_SOUND_STATES)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		pin_ptr<int> pinnedValue = &value[0];
		int *valuePtr = pinnedValue;

		std::memcpy(InternalVehicleGameObjDefPointer->EngineSound, valuePtr, sizeof(int) * ::MAX_ENGINE_SOUND_STATES);
	}

	float VehicleGameObjDef::SquishVelocity::get()
	{
		return InternalVehicleGameObjDefPointer->SquishVelocity;
	}

	void VehicleGameObjDef::SquishVelocity::set(float value)
	{
		InternalVehicleGameObjDefPointer->SquishVelocity = value;
	}

	int VehicleGameObjDef::VehicleNameID::get()
	{
		return InternalVehicleGameObjDefPointer->VehicleNameID;
	}

	void VehicleGameObjDef::VehicleNameID::set(int value)
	{
		InternalVehicleGameObjDefPointer->VehicleNameID = value;
	}

	int VehicleGameObjDef::NumSeats::get()
	{
		return InternalVehicleGameObjDefPointer->NumSeats;
	}

	void VehicleGameObjDef::NumSeats::set(int value)
	{
		InternalVehicleGameObjDefPointer->NumSeats = value;
	}

	int VehicleGameObjDef::GDIDamageReportID::get()
	{
		return InternalVehicleGameObjDefPointer->GDIDamageReportID;
	}

	void VehicleGameObjDef::GDIDamageReportID::set(int value)
	{
		InternalVehicleGameObjDefPointer->GDIDamageReportID = value;
	}

	int VehicleGameObjDef::NodDamageReportID::get()
	{
		return InternalVehicleGameObjDefPointer->NodDamageReportID;
	}

	void VehicleGameObjDef::NodDamageReportID::set(int value)
	{
		InternalVehicleGameObjDefPointer->NodDamageReportID = value;
	}

	int VehicleGameObjDef::GDIDestroyReportID::get()
	{
		return InternalVehicleGameObjDefPointer->GDIDestroyReportID;
	}

	void VehicleGameObjDef::GDIDestroyReportID::set(int value)
	{
		InternalVehicleGameObjDefPointer->GDIDestroyReportID = value;
	}

	int VehicleGameObjDef::NodDestroyReportID::get()
	{
		return InternalVehicleGameObjDefPointer->NodDestroyReportID;
	}

	void VehicleGameObjDef::NodDestroyReportID::set(int value)
	{
		InternalVehicleGameObjDefPointer->NodDestroyReportID = value;
	}

	bool VehicleGameObjDef::CanBeStolen::get()
	{
		return InternalVehicleGameObjDefPointer->CanBeStolen;
	}

	void VehicleGameObjDef::CanBeStolen::set(bool value)
	{
		InternalVehicleGameObjDefPointer->CanBeStolen = value;
	}

	bool VehicleGameObjDef::AllowStealthWhileEmpty::get()
	{
		return InternalVehicleGameObjDefPointer->AllowStealthWhileEmpty;
	}

	void VehicleGameObjDef::AllowStealthWhileEmpty::set(bool value)
	{
		InternalVehicleGameObjDefPointer->AllowStealthWhileEmpty = value;
	}

	bool VehicleGameObjDef::BuildAtGround::get()
	{
		return InternalVehicleGameObjDefPointer->BuildAtGround;
	}

	void VehicleGameObjDef::BuildAtGround::set(bool value)
	{
		InternalVehicleGameObjDefPointer->BuildAtGround = value;
	}

	bool VehicleGameObjDef::DualAim::get()
	{
		return InternalVehicleGameObjDefPointer->DualAim;
	}

	void VehicleGameObjDef::DualAim::set(bool value)
	{
		InternalVehicleGameObjDefPointer->DualAim = value;
	}

	float VehicleGameObjDef::FactoryRideHeight::get()
	{
		return InternalVehicleGameObjDefPointer->FactoryRideHeight;
	}

	void VehicleGameObjDef::FactoryRideHeight::set(float value)
	{
		InternalVehicleGameObjDefPointer->FactoryRideHeight = value;
	}

	bool VehicleGameObjDef::FakeTurret::get()
	{
		return InternalVehicleGameObjDefPointer->FakeTurret;
	}

	void VehicleGameObjDef::FakeTurret::set(bool value)
	{
		InternalVehicleGameObjDefPointer->FakeTurret = value;
	}

	int VehicleGameObjDef::GDIPurchaseReportID::get()
	{
		return InternalVehicleGameObjDefPointer->GDIPurchaseReportID;
	}

	void VehicleGameObjDef::GDIPurchaseReportID::set(int value)
	{
		InternalVehicleGameObjDefPointer->GDIPurchaseReportID = value;
	}

	int VehicleGameObjDef::NodPurchaseReportID::get()
	{
		return InternalVehicleGameObjDefPointer->NodPurchaseReportID;
	}

	void VehicleGameObjDef::NodPurchaseReportID::set(int value)
	{
		InternalVehicleGameObjDefPointer->NodPurchaseReportID = value;
	}

	bool VehicleGameObjDef::CanRepair::get()
	{
		return InternalVehicleGameObjDefPointer->CanRepair;
	}

	void VehicleGameObjDef::CanRepair::set(bool value)
	{
		InternalVehicleGameObjDefPointer->CanRepair = value;
	}

	int VehicleGameObjDef::EntryHelpMessage::get()
	{
		return InternalVehicleGameObjDefPointer->EntryHelpMessage;
	}

	void VehicleGameObjDef::EntryHelpMessage::set(int value)
	{
		InternalVehicleGameObjDefPointer->EntryHelpMessage = value;
	}

	Vector3 VehicleGameObjDef::EntryHelpMessageColor::get()
	{
		Vector3 result;

		Vector3::UnmanagedToManagedVector3(InternalVehicleGameObjDefPointer->EntryHelpMessageColor, result);

		return result;
	}

	void VehicleGameObjDef::EntryHelpMessageColor::set(Vector3 value)
	{
		Vector3::ManagedToUnmanagedVector3(value, InternalVehicleGameObjDefPointer->EntryHelpMessageColor);
	}

	bool VehicleGameObjDef::ApplySurfaceEffectDamage::get()
	{
		return InternalVehicleGameObjDefPointer->ApplySurfaceEffectDamage;
	}

	void VehicleGameObjDef::ApplySurfaceEffectDamage::set(bool value)
	{
		InternalVehicleGameObjDefPointer->ApplySurfaceEffectDamage = value;
	}

	bool VehicleGameObjDef::DisableSurfaceSounds::get()
	{
		return InternalVehicleGameObjDefPointer->DisableSurfaceSounds;
	}

	void VehicleGameObjDef::DisableSurfaceSounds::set(bool value)
	{
		InternalVehicleGameObjDefPointer->DisableSurfaceSounds = value;
	}

	::SmartGameObjDef *VehicleGameObjDef::InternalSmartGameObjDefPointer::get()
	{
		return InternalVehicleGameObjDefPointer;
	}

	::VehicleGameObjDef *VehicleGameObjDef::InternalVehicleGameObjDefPointer::get()
	{
		return reinterpret_cast<::VehicleGameObjDef *>(Pointer.ToPointer());
	}
}