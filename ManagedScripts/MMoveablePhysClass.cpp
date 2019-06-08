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
#include "MMoveablePhysClass.h"

#include "MMoveablePhysDefClass.h"
#include "MMatrix3.h"
#include "MMatrix3D.h"
#include "MPhysControllerClass.h"
#include "MRenderObjClass.h"
#include "MDynamicShadowManagerClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <MoveablePhysClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{

#pragma managed(push, off)

	class MoveablePhysClassHelper : public ::MoveablePhysClass
	{
		private:
			MoveablePhysClassHelper() = default;

		public:
			float &GetMass()
			{
				return Mass;
			}

			float &GetMassInv()
			{
				return MassInv;
			}

			::PhysClass *&GetCarrier()
			{
				return Carrier;
			}

			::RenderObjClass *&GetCarrierSubObject()
			{
				return CarrierSubObject;
			}

			::DynamicShadowManagerClass &GetShadowManager()
			{
				return ShadowManager;
			}
	};

#pragma managed(pop)

	MoveablePhysClass::MoveablePhysClass(IntPtr pointer)
		: DynamicPhysClass(pointer)
	{

	}

	IMoveablePhysClass ^MoveablePhysClass::AsMoveablePhysClass()
	{
		return this;
	}

	void MoveablePhysClass::SetMass(float mass)
	{
		InternalMoveablePhysClassPointer->Set_Mass(mass);
	}

	bool MoveablePhysClass::CanTeleport(Matrix3D newTM, bool checkDynOnly, IMultiListClass<IPhysClass ^> ^resultList)
	{
		::Matrix3D newTMMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(newTM, newTMMat);

		if (resultList == nullptr || resultList->Pointer.ToPointer() == nullptr)
		{
			return InternalMoveablePhysClassPointer->Can_Teleport(newTMMat, checkDynOnly, nullptr);
		}
		else
		{
			return InternalMoveablePhysClassPointer->Can_Teleport(newTMMat, checkDynOnly, reinterpret_cast<::MultiListClass<::PhysClass> *>(resultList->Pointer.ToPointer()));
		}
	}

	bool MoveablePhysClass::CanTeleport(Matrix3D newTM, bool checkDynOnly)
	{
		::Matrix3D newTMMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(newTM, newTMMat);

		return InternalMoveablePhysClassPointer->Can_Teleport(newTMMat, checkDynOnly);
	}

	bool MoveablePhysClass::CanTeleport(Matrix3D newTM)
	{
		::Matrix3D newTMMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(newTM, newTMMat);

		return InternalMoveablePhysClassPointer->Can_Teleport(newTMMat);
	}

	bool MoveablePhysClass::CanTeleportAndStand(Matrix3D newTM, Matrix3D %out)
	{
		::Matrix3D newTMMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(newTM, newTMMat);

		::Matrix3D tmp;

		if (InternalMoveablePhysClassPointer->Can_Teleport_And_Stand(newTMMat, &tmp))
		{
			Matrix3D::UnmanagedToManagedMatrix3D(tmp, out);

			return true;
		}
		else
		{
			return false;
		}
	}

	bool MoveablePhysClass::FindTeleportLocation(Vector3 start, float radius, Vector3 %out)
	{
		::Vector3 startVec;

		Vector3::ManagedToUnmanagedVector3(start, startVec);

		::Vector3 tmp;

		if (InternalMoveablePhysClassPointer->Find_Teleport_Location(startVec, radius, &tmp))
		{
			Vector3::UnmanagedToManagedVector3(tmp, out);

			return true;
		}
		else
		{
			return false;
		}
	}

	bool MoveablePhysClass::CanMoveTo(Matrix3D newTM)
	{
		::Matrix3D newTMMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(newTM, newTMMat);

		return InternalMoveablePhysClassPointer->Can_Move_To(newTMMat);
	}

	bool MoveablePhysClass::CinematicMoveTo(Matrix3D newTM)
	{
		::Matrix3D newTMMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(newTM, newTMMat);

		return InternalMoveablePhysClassPointer->Cinematic_Move_To(newTMMat);
	}

	IPhysClass ^MoveablePhysClass::PeekCarrierObject()
	{
		auto result = InternalMoveablePhysClassPointer->Peek_Carrier_Object();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PhysClass(IntPtr(result));
		}
	}

	IntPtr MoveablePhysClass::MoveablePhysClassPointer::get()
	{
		return IntPtr(InternalMoveablePhysClassPointer);
	}

	IMoveablePhysDefClass ^MoveablePhysClass::MoveablePhysDef::get()
	{
		return gcnew MoveablePhysDefClass(IntPtr(const_cast<::MoveablePhysDefClass *>(InternalMoveablePhysClassPointer->Get_MoveablePhysDef())));
	}

	float MoveablePhysClass::Mass::get()
	{
		return InternalMoveablePhysClassPointer->Get_Mass();
	}

	void MoveablePhysClass::Mass::set(float value)
	{
		auto helper = reinterpret_cast<MoveablePhysClassHelper *>(InternalMoveablePhysClassPointer);

		auto &mass = helper->GetMass();

		mass = value;
	}

	float MoveablePhysClass::MassInv::get()
	{
		return InternalMoveablePhysClassPointer->Get_Mass_Inv();
	}

	void MoveablePhysClass::MassInv::set(float value)
	{
		auto helper = reinterpret_cast<MoveablePhysClassHelper *>(InternalMoveablePhysClassPointer);

		auto &massInv = helper->GetMassInv();

		massInv = value;
	}

	float MoveablePhysClass::GravScale::get()
	{
		return InternalMoveablePhysClassPointer->Get_Gravity_Multiplier();
	}

	void MoveablePhysClass::GravScale::set(float value)
	{
		InternalMoveablePhysClassPointer->Set_Gravity_Multiplier(value);
	}

	float MoveablePhysClass::Elasticity::get()
	{
		return InternalMoveablePhysClassPointer->Get_Elasticity();
	}

	void MoveablePhysClass::Elasticity::set(float value)
	{
		InternalMoveablePhysClassPointer->Set_Elasticity(value);
	}

	Matrix3 MoveablePhysClass::InertiaInv::get()
	{
		::Matrix3 tmp;

		InternalMoveablePhysClassPointer->Get_Inertia_Inv(&tmp);

		Matrix3 result;

		Matrix3::UnmanagedToManagedMatrix3(tmp, result);

		return result;
	}

	IPhysControllerClass ^MoveablePhysClass::Controller::get()
	{
		auto result = InternalMoveablePhysClassPointer->Get_Controller();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PhysControllerClass(IntPtr(result));
		}
	}

	void MoveablePhysClass::Controller::set(IPhysControllerClass ^value)
	{
		if (value == nullptr || value->PhysControllerClassPointer.ToPointer() == nullptr)
		{
			InternalMoveablePhysClassPointer->Set_Controller(nullptr);
		}
		else
		{
			InternalMoveablePhysClassPointer->Set_Controller(reinterpret_cast<::PhysControllerClass *>(value->PhysControllerClassPointer.ToPointer()));
		}
	}

	Vector3 MoveablePhysClass::Velocity::get()
	{
		::Vector3 tmp;

		InternalMoveablePhysClassPointer->Get_Velocity(&tmp);

		Vector3 result;

		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	void MoveablePhysClass::Velocity::set(Vector3 value)
	{
		::Vector3 tmp;

		Vector3::ManagedToUnmanagedVector3(value, tmp);

		InternalMoveablePhysClassPointer->Set_Velocity(tmp);
	}

	::DynamicPhysClass *MoveablePhysClass::InternalDynamicPhysClassPointer::get()
	{
		return InternalMoveablePhysClassPointer;
	}

	::MoveablePhysClass *MoveablePhysClass::InternalMoveablePhysClassPointer::get()
	{
		return reinterpret_cast<::MoveablePhysClass *>(Pointer.ToPointer());
	}

	IPhysClass ^MoveablePhysClass::Carrier::get()
	{
		auto helper = reinterpret_cast<MoveablePhysClassHelper *>(InternalMoveablePhysClassPointer);

		auto &carrier = helper->GetCarrier();

		if (carrier == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PhysClass(IntPtr(carrier));
		}
	}

	void MoveablePhysClass::Carrier::set(IPhysClass ^value)
	{
		auto helper = reinterpret_cast<MoveablePhysClassHelper *>(InternalMoveablePhysClassPointer);

		auto &carrier = helper->GetCarrier();

		if (value == nullptr || value->PhysClassPointer.ToPointer() == nullptr)
		{
			carrier = nullptr;
		}
		else
		{
			carrier = reinterpret_cast<::PhysClass *>(value->PhysClassPointer.ToPointer());
		}
	}

	IRenderObjClass ^MoveablePhysClass::CarrierSubObject::get()
	{
		auto helper = reinterpret_cast<MoveablePhysClassHelper *>(InternalMoveablePhysClassPointer);

		auto &carrierSubObject = helper->GetCarrierSubObject();

		if (carrierSubObject == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(carrierSubObject));
		}
	}

	void MoveablePhysClass::CarrierSubObject::set(IRenderObjClass ^value)
	{
		auto helper = reinterpret_cast<MoveablePhysClassHelper *>(InternalMoveablePhysClassPointer);

		auto &carrierSubObject = helper->GetCarrierSubObject();

		if (value == nullptr || value->RenderObjClassPointer.ToPointer() == nullptr)
		{
			carrierSubObject = nullptr;
		}
		else
		{
			carrierSubObject = reinterpret_cast<::RenderObjClass *>(value->RenderObjClassPointer.ToPointer());
		}
	}

	IDynamicShadowManagerClass ^MoveablePhysClass::ShadowManager::get()
	{
		auto helper = reinterpret_cast<MoveablePhysClassHelper *>(InternalMoveablePhysClassPointer);

		auto &shadowManager = helper->GetShadowManager();

		return gcnew DynamicShadowManagerClass(IntPtr(&shadowManager));
	}
}