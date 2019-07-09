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
#include "MPhysClass.h"

#include "MMatrix3D.h"
#include "Mphyscoltest.h"
#include "Mphysinttest.h"
#include "MRenderObjClass.h"
#include "MPhysObserverClass.h"
#include "MDynamicPhysClass.h"
#include "MMoveablePhysClass.h"
#include "MStaticPhysClass.h"
#include "MStaticAnimPhysClass.h"
#include "MDecorationPhysClass.h"
#include "MLightPhysClass.h"
#include "MMaterialEffectClassRefMultiListClass.h"
#include "MVector3.h"
#include "MAABoxClass.h"

namespace RenSharp
{
	PhysClass::PhysClass(IntPtr pointer)
		: CullableClass(pointer)
	{
		persistClass = gcnew PersistClass(IntPtr(InternalPersistClassPointer));
		multiListObjectClass = gcnew MultiListObjectClass(IntPtr(InternalMultiListObjectClassPointer));
	}

	bool PhysClass::Equals(Object ^other)
	{
		if (RefCountClass::Equals(other))
		{
			return true;
		}

		if (ReferenceEquals(other, nullptr))
		{
			return false;
		}

		auto otherUnmanagedObj = dynamic_cast<IUnmanagedObject ^>(other);
		if (otherUnmanagedObj == nullptr || otherUnmanagedObj->Pointer.Equals(IntPtr::Zero))
		{
			return false;
		}

		auto otherPostLoadableClass = dynamic_cast<IPostLoadableClass^>(other);
		if (otherPostLoadableClass != nullptr)
		{
			if (persistClass->Equals(otherPostLoadableClass))
			{
				return true;
			}
		}

		auto otherMultiListObjectClass = dynamic_cast<IMultiListObjectClass ^>(other);
		if (otherMultiListObjectClass != nullptr)
		{
			if (multiListObjectClass->Equals(otherMultiListObjectClass))
			{
				return true;
			}
		}

		auto otherPhysClass = dynamic_cast<IPhysClass ^>(other);
		if (otherPhysClass != nullptr)
		{
			if (PhysClassPointer.Equals(otherPhysClass->PhysClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void PhysClass::OnPostLoad()
	{
		persistClass->OnPostLoad();
	}

	bool PhysClass::Save(IChunkSaveClass ^csave)
	{
		return persistClass->Save(csave);
	}

	bool PhysClass::Load(IChunkLoadClass ^cload)
	{
		return persistClass->Load(cload);
	}

	void PhysClass::DefinitionChanged()
	{
		InternalPhysClassPointer->Definition_Changed();
	}

	bool PhysClass::NeedsTimestep()
	{
		return InternalPhysClassPointer->Needs_Timestep();
	}

	void PhysClass::Timestep(float dt)
	{
		InternalPhysClassPointer->Timestep(dt);
	}

	void PhysClass::PostTimestepProcess()
	{
		InternalPhysClassPointer->Post_Timestep_Process();
	}

	bool PhysClass::CastRay(IPhysRayCollisionTestClass ^rayTest)
	{
		if (rayTest == nullptr || rayTest->PhysRayCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("rayTest");
		}

		return InternalPhysClassPointer->Cast_Ray(
			*reinterpret_cast<::PhysRayCollisionTestClass *>(rayTest->PhysRayCollisionTestClassPointer.ToPointer()));
	}

	bool PhysClass::CastRay(PhysRayCollisionTestClass ^rayTest)
	{
		if (rayTest == nullptr)
		{
			throw gcnew ArgumentNullException("rayTest");
		}

		IUnmanagedContainer<IPhysRayCollisionTestClass ^> ^tmpRayTest = RenSharpPhysRayCollisionTestClass::CreateRenSharpPhysRayCollisionTestClass(rayTest);
		try
		{
			bool result = InternalPhysClassPointer->Cast_Ray(
				*reinterpret_cast<::PhysRayCollisionTestClass *>(tmpRayTest->UnmanagedObject->PhysRayCollisionTestClassPointer.ToPointer()));

			rayTest->CopyFrom(tmpRayTest->UnmanagedObject);

			return result;
		}
		finally
		{
#pragma push_macro("delete")
#undef delete

			delete tmpRayTest;
			tmpRayTest = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool PhysClass::CastAABox(IPhysAABoxCollisionTestClass ^boxTest)
	{
		if (boxTest == nullptr || boxTest->PhysAABoxCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("boxTest");
		}

		return InternalPhysClassPointer->Cast_AABox(
			*reinterpret_cast<::PhysAABoxCollisionTestClass *>(boxTest->PhysAABoxCollisionTestClassPointer.ToPointer()));
	}

	bool PhysClass::CastAABox(PhysAABoxCollisionTestClass ^boxTest)
	{
		if (boxTest == nullptr)
		{
			throw gcnew ArgumentNullException("boxTest");
		}

		IUnmanagedContainer<IPhysAABoxCollisionTestClass ^> ^tmpBoxTest = RenSharpPhysAABoxCollisionTestClass::CreateRenSharpPhysAABoxCollisionTestClass(boxTest);
		try
		{
			bool result = InternalPhysClassPointer->Cast_AABox(
				*reinterpret_cast<::PhysAABoxCollisionTestClass *>(tmpBoxTest->UnmanagedObject->PhysAABoxCollisionTestClassPointer.ToPointer()));

			boxTest->CopyFrom(tmpBoxTest->UnmanagedObject);

			return result;
		}
		finally
		{
#pragma push_macro("delete")
#undef delete

			delete tmpBoxTest;
			tmpBoxTest = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool PhysClass::CastOBBox(IPhysOBBoxCollisionTestClass ^boxTest)
	{
		if (boxTest == nullptr || boxTest->PhysOBBoxCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("boxTest");
		}

		return InternalPhysClassPointer->Cast_OBBox(
			*reinterpret_cast<::PhysOBBoxCollisionTestClass *>(boxTest->PhysOBBoxCollisionTestClassPointer.ToPointer()));
	}

	bool PhysClass::CastOBBox(PhysOBBoxCollisionTestClass ^boxTest)
	{
		if (boxTest == nullptr)
		{
			throw gcnew ArgumentNullException("boxTest");
		}

		IUnmanagedContainer<IPhysOBBoxCollisionTestClass ^> ^tmpBoxTest = RenSharpPhysOBBoxCollisionTestClass::CreateRenSharpPhysOBBoxCollisionTestClass(boxTest);
		try
		{
			bool result = InternalPhysClassPointer->Cast_OBBox(
				*reinterpret_cast<::PhysOBBoxCollisionTestClass *>(tmpBoxTest->UnmanagedObject->PhysOBBoxCollisionTestClassPointer.ToPointer()));

			boxTest->CopyFrom(tmpBoxTest->UnmanagedObject);

			return result;
		}
		finally
		{
#pragma push_macro("delete")
#undef delete

			delete tmpBoxTest;
			tmpBoxTest = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool PhysClass::IntersectionTest(IPhysAABoxIntersectionTestClass ^test)
	{
		if (test == nullptr || test->PhysAABoxIntersectionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("test");
		}

		return InternalPhysClassPointer->Intersection_Test(
			*reinterpret_cast<::PhysAABoxIntersectionTestClass *>(test->PhysAABoxIntersectionTestClassPointer.ToPointer()));
	}

	bool PhysClass::IntersectionTest(PhysAABoxIntersectionTestClass ^test)
	{
		if (test == nullptr)
		{
			throw gcnew ArgumentNullException("test");
		}

		IUnmanagedContainer<IPhysAABoxIntersectionTestClass ^> ^tmpTest = RenSharpPhysAABoxIntersectionTestClass::CreateRenSharpPhysAABoxIntersectionTestClass(test);
		try
		{
			bool result = InternalPhysClassPointer->Intersection_Test(
				*reinterpret_cast<::PhysAABoxIntersectionTestClass *>(tmpTest->UnmanagedObject->PhysAABoxIntersectionTestClassPointer.ToPointer()));

			test->CopyFrom(tmpTest->UnmanagedObject);

			return result;
		}
		finally
		{
#pragma push_macro("delete")
#undef delete

			delete tmpTest;
		tmpTest = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool PhysClass::IntersectionTest(IPhysOBBoxIntersectionTestClass ^test)
	{
		if (test == nullptr || test->PhysOBBoxIntersectionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("test");
		}

		return InternalPhysClassPointer->Intersection_Test(
			*reinterpret_cast<::PhysOBBoxIntersectionTestClass *>(test->PhysOBBoxIntersectionTestClassPointer.ToPointer()));
	}

	bool PhysClass::IntersectionTest(PhysOBBoxIntersectionTestClass ^test)
	{
		if (test == nullptr)
		{
			throw gcnew ArgumentNullException("test");
		}

		IUnmanagedContainer<IPhysOBBoxIntersectionTestClass ^> ^tmpTest = RenSharpPhysOBBoxIntersectionTestClass::CreateRenSharpPhysOBBoxIntersectionTestClass(test);
		try
		{
			bool result = InternalPhysClassPointer->Intersection_Test(
				*reinterpret_cast<::PhysOBBoxIntersectionTestClass *>(tmpTest->UnmanagedObject->PhysOBBoxIntersectionTestClassPointer.ToPointer()));

			test->CopyFrom(tmpTest->UnmanagedObject);

			return result;
		}
		finally
		{
#pragma push_macro("delete")
#undef delete

			delete tmpTest;
		tmpTest = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool PhysClass::IntersectionTest(IPhysMeshIntersectionTestClass ^test)
	{
		if (test == nullptr || test->PhysMeshIntersectionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("test");
		}

		return InternalPhysClassPointer->Intersection_Test(
			*reinterpret_cast<::PhysMeshIntersectionTestClass *>(test->PhysMeshIntersectionTestClassPointer.ToPointer()));
	}

	bool PhysClass::IntersectionTest(PhysMeshIntersectionTestClass ^test)
	{
		if (test == nullptr)
		{
			throw gcnew ArgumentNullException("test");
		}

		IUnmanagedContainer<IPhysMeshIntersectionTestClass ^> ^tmpTest = RenSharpPhysMeshIntersectionTestClass::CreateRenSharpPhysMeshIntersectionTestClass(test);
		try
		{
			bool result = InternalPhysClassPointer->Intersection_Test(
				*reinterpret_cast<::PhysMeshIntersectionTestClass *>(tmpTest->UnmanagedObject->PhysMeshIntersectionTestClassPointer.ToPointer()));

			test->CopyFrom(tmpTest->UnmanagedObject);

			return result;
		}
		finally
		{
#pragma push_macro("delete")
#undef delete

			delete tmpTest;
		tmpTest = nullptr;

#pragma pop_macro("delete")
		}
	}

	void PhysClass::LinkToCarrier(IPhysClass ^carrier, IRenderObjClass ^carrierSubObj)
	{
		::PhysClass *carrierPtr;
		::RenderObjClass *carrierSubObjPtr;

		if (carrier == nullptr || carrier->PhysClassPointer.ToPointer() == nullptr)
		{
			carrierPtr = nullptr;
		}
		else
		{
			carrierPtr = reinterpret_cast<::PhysClass *>(carrier->PhysClassPointer.ToPointer());
		}

		if (carrierSubObj == nullptr || carrierSubObj->RenderObjClassPointer.ToPointer() == nullptr)
		{
			carrierSubObjPtr = nullptr;
		}
		else
		{
			carrierSubObjPtr = reinterpret_cast<::RenderObjClass *>(carrierSubObj->RenderObjClassPointer.ToPointer());
		}

		InternalPhysClassPointer->Link_To_Carrier(carrierPtr, carrierSubObjPtr);
	}

	void PhysClass::LinkToCarrier(IPhysClass ^carrier)
	{
		if (carrier == nullptr || carrier->PhysClassPointer.ToPointer() == nullptr)
		{
			InternalPhysClassPointer->Link_To_Carrier(nullptr);
		}
		else
		{
			InternalPhysClassPointer->Link_To_Carrier(reinterpret_cast<::PhysClass *>(carrier->PhysClassPointer.ToPointer()));
		}
	}

	IRenderObjClass ^PhysClass::PeekCarrierSubObject()
	{
		auto result = InternalPhysClassPointer->Peek_Carrier_Sub_Object();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(result));
		}
	}

	bool PhysClass::Push(Vector3 move)
	{
		::Vector3 moveVec;

		Vector3::ManagedToUnmanagedVector3(move, moveVec);

		return InternalPhysClassPointer->Push(moveVec);
	}

	bool PhysClass::InternalLinkRider(IPhysClass ^rider)
	{
		if (rider == nullptr || rider->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("rider");
		}

		return InternalPhysClassPointer->Internal_Link_Rider(reinterpret_cast<::PhysClass *>(rider->PhysClassPointer.ToPointer()));
	}

	bool PhysClass::InternalUnlinkRider(IPhysClass ^rider)
	{
		if (rider == nullptr || rider->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("rider");
		}

		return InternalPhysClassPointer->Internal_Unlink_Rider(reinterpret_cast<::PhysClass *>(rider->PhysClassPointer.ToPointer()));
	}

	void PhysClass::SetModel(IRenderObjClass ^model)
	{
		if (model == nullptr || model->RenderObjClassPointer.ToPointer() == nullptr)
		{
			InternalPhysClassPointer->Set_Model(nullptr);
		}
		else
		{
			InternalPhysClassPointer->Set_Model(reinterpret_cast<::RenderObjClass *>(model->RenderObjClassPointer.ToPointer()));
		}
	}

	IRenderObjClass ^PhysClass::PeekModel()
	{
		auto result = InternalPhysClassPointer->Peek_Model();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(result));
		}
	}

	void PhysClass::Render(IntPtr rInfo)
	{
		if (rInfo.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("rInfo");
		}

		InternalPhysClassPointer->Render(*reinterpret_cast<::RenderInfoClass *>(rInfo.ToPointer()));
	}

	void PhysClass::VisRender(IntPtr rInfo)
	{
		if (rInfo.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("rInfo");
		}

		InternalPhysClassPointer->Vis_Render(*reinterpret_cast<::SpecialRenderInfoClass *>(rInfo.ToPointer()));
	}

	void PhysClass::RenderVisMeshes(IntPtr rInfo)
	{
		if (rInfo.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("rInfo");
		}

		InternalPhysClassPointer->Render_Vis_Meshes(*reinterpret_cast<::RenderInfoClass *>(rInfo.ToPointer()));
	}

	void PhysClass::AddEffectToMe(IMaterialEffectClass ^effect)
	{
		if (effect == nullptr || effect->MaterialEffectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("effect");
		}

		InternalPhysClassPointer->Add_Effect_To_Me(reinterpret_cast<::MaterialEffectClass *>(effect->MaterialEffectClassPointer.ToPointer()));
	}

	void PhysClass::RemoveEffectFromMe(IMaterialEffectClass ^effect)
	{
		if (effect == nullptr || effect->MaterialEffectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("effect");
		}

		InternalPhysClassPointer->Remove_Effect_From_Me(reinterpret_cast<::MaterialEffectClass *>(effect->MaterialEffectClassPointer.ToPointer()));
	}

	void PhysClass::IncIgnoreCounter()
	{
		InternalPhysClassPointer->Inc_Ignore_Counter();
	}

	void PhysClass::DecIgnoreCounter()
	{
		InternalPhysClassPointer->Dec_Ignore_Counter();
	}

	void PhysClass::EnableDebugDisplay(bool onoff)
	{
		InternalPhysClassPointer->Enable_Debug_Display(onoff);
	}

	void PhysClass::ForceAwake()
	{
		InternalPhysClassPointer->Force_Awake();
	}

	IDynamicPhysClass ^PhysClass::AsDynamicPhysClass()
	{
		auto result = InternalPhysClassPointer->As_DynamicPhysClass();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DynamicPhysClass(IntPtr(result));
		}
	}

	IMoveablePhysClass ^PhysClass::AsMoveablePhysClass()
	{
		auto result = InternalPhysClassPointer->As_MoveablePhysClass();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew MoveablePhysClass(IntPtr(result));
		}
	}

	IntPtr PhysClass::AsPhys3Class()
	{
		return IntPtr(InternalPhysClassPointer->As_Phys3Class());
	}

	IntPtr PhysClass::AsHumanPhysClass()
	{
		return IntPtr(InternalPhysClassPointer->As_HumanPhysClass());
	}

	IntPtr PhysClass::AsRigidBodyClass()
	{
		return IntPtr(InternalPhysClassPointer->As_RigidBodyClass());
	}

	IntPtr PhysClass::AsVehiclePhysClass()
	{
		return IntPtr(InternalPhysClassPointer->As_VehiclePhysClass());
	}

	IntPtr PhysClass::AsMotorVehicleClass()
	{
		return IntPtr(InternalPhysClassPointer->As_MotorVehicleClass());
	}

	IntPtr PhysClass::AsWheeledVehicleClass()
	{
		return IntPtr(InternalPhysClassPointer->As_WheeledVehicleClass());
	}

	IntPtr PhysClass::AsMotorcycleClass()
	{
		return IntPtr(InternalPhysClassPointer->As_MotorcycleClass());
	}

	IntPtr PhysClass::AsTrackedVehicleClass()
	{
		return IntPtr(InternalPhysClassPointer->As_TrackedVehicleClass());
	}

	IntPtr PhysClass::AsVTOLVehicleClass()
	{
		return IntPtr(InternalPhysClassPointer->As_VTOLVehicleClass());
	}

	IStaticPhysClass ^PhysClass::AsStaticPhysClass()
	{
		auto result = InternalPhysClassPointer->As_StaticPhysClass();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew StaticPhysClass(IntPtr(result));
		}
	}

	IStaticAnimPhysClass ^PhysClass::AsStaticAnimPhysClass()
	{
		auto result = InternalPhysClassPointer->As_StaticAnimPhysClass();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew StaticAnimPhysClass(IntPtr(result));
		}
	}

	IntPtr PhysClass::AsElevatorPhysClass()
	{
		return IntPtr(InternalPhysClassPointer->As_ElevatorPhysClass());
	}

	IntPtr PhysClass::AsDamageableStaticPhysClass()
	{
		return IntPtr(InternalPhysClassPointer->As_DamageableStaticPhysClass());
	}

	IntPtr PhysClass::AsDoorPhysClass()
	{
		return IntPtr(InternalPhysClassPointer->As_DoorPhysClass());
	}

	IDecorationPhysClass ^PhysClass::AsDecorationPhysClass()
	{
		auto result = InternalPhysClassPointer->As_DecorationPhysClass();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DecorationPhysClass(IntPtr(result));
		}
	}

	IntPtr PhysClass::AsTimedDecorationPhysClass()
	{
		return IntPtr(InternalPhysClassPointer->As_TimedDecorationPhysClass());
	}

	IntPtr PhysClass::AsDynamicAnimPhysClass()
	{
		return IntPtr(InternalPhysClassPointer->As_DynamicAnimPhysClass());
	}

	ILightPhysClass ^PhysClass::AsLightPhysClass()
	{
		auto result = InternalPhysClassPointer->As_LightPhysClass();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew LightPhysClass(IntPtr(result));
		}
	}

	IntPtr PhysClass::AsRenderObjPhysClass()
	{
		return IntPtr(InternalPhysClassPointer->As_RenderObjPhysClass());
	}

	IntPtr PhysClass::AsProjectileClass()
	{
		return IntPtr(InternalPhysClassPointer->As_ProjectileClass());
	}

	IntPtr PhysClass::AsAccessiblePhysClass()
	{
		return IntPtr(InternalPhysClassPointer->As_AccessiblePhysClass());
	}

	IntPtr PhysClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void PhysClass::Pointer::set(IntPtr value)
	{
		AbstractUnmanagedObject::Pointer::set(value);

		if (Pointer == IntPtr::Zero)
		{
			persistClass = nullptr;
			multiListObjectClass = nullptr;
		}
		else
		{
			persistClass = gcnew PersistClass(IntPtr(InternalPersistClassPointer));
			multiListObjectClass = gcnew MultiListObjectClass(IntPtr(InternalMultiListObjectClassPointer));
		}
	}

	IntPtr PhysClass::PostLoadableClassPointer::get()
	{
		return IntPtr(InternalPostLoadableClassPointer);
	}

	IntPtr PhysClass::PersistClassPointer::get()
	{
		return IntPtr(InternalPersistClassPointer);
	}

	IntPtr PhysClass::MultiListObjectClassPointer::get()
	{
		return IntPtr(InternalMultiListObjectClassPointer);
	}

	IntPtr PhysClass::PhysClassPointer::get()
	{
		return IntPtr(InternalPhysClassPointer);
	}

	bool PhysClass::IsPostLoadRegistered::get()
	{
		return persistClass->IsPostLoadRegistered;
	}

	void PhysClass::IsPostLoadRegistered::set(bool value)
	{
		persistClass->IsPostLoadRegistered = value;
	}

	IPersistFactoryClass ^PhysClass::Factory::get()
	{
		return persistClass->Factory;
	}

	IMultiListNodeClass ^PhysClass::ListNode::get()
	{
		return multiListObjectClass->ListNode;
	}

	void PhysClass::ListNode::set(IMultiListNodeClass ^value)
	{
		multiListObjectClass->ListNode = value;
	}

	Matrix3D PhysClass::Transform::get()
	{
		Matrix3D result;

		Matrix3D::UnmanagedToManagedMatrix3D(InternalPhysClassPointer->Get_Transform(), result);

		return result;
	}

	void PhysClass::Transform::set(Matrix3D value)
	{
		::Matrix3D tmp;

		Matrix3D::ManagedToUnmanagedMatrix3D(value, tmp);

		InternalPhysClassPointer->Set_Transform(tmp);
	}

	Vector3 PhysClass::Position::get()
	{
		::Vector3 tmp;

		InternalPhysClassPointer->Get_Position(&tmp);

		Vector3 result;

		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	void PhysClass::Position::set(Vector3 value)
	{
		::Vector3 tmp;

		Vector3::ManagedToUnmanagedVector3(value, tmp);

		InternalPhysClassPointer->Set_Position(tmp);
	}

	float PhysClass::Facing::get()
	{
		return InternalPhysClassPointer->Get_Facing();
	}

	uint32 PhysClass::InstanceID::get()
	{
		return InternalPhysClassPointer->Get_ID();
	}

	void PhysClass::InstanceID::set(uint32 value)
	{
		InternalPhysClassPointer->Set_ID(value);
	}

	int PhysClass::VisObjectID::get()
	{
		return InternalPhysClassPointer->Get_Vis_Object_ID();
	}

	void PhysClass::VisObjectID::set(int value)
	{
		InternalPhysClassPointer->Set_Vis_Object_ID(value);
	}

	AABoxClass PhysClass::ShadowBlobBox::get()
	{
		::AABoxClass tmp;

		InternalPhysClassPointer->Get_Shadow_Blob_Box(&tmp);

		AABoxClass result;

		AABoxClass::UnmanagedToManagedAABoxClass(tmp, result);

		return result;
	}

	bool PhysClass::IsCastingShadow::get()
	{
		return InternalPhysClassPointer->Is_Casting_Shadow();
	}

	VisibilityModeType PhysClass::VisibilityMode::get()
	{
		return static_cast<VisibilityModeType>(InternalPhysClassPointer->Get_Visibility_Mode());
	}

	void PhysClass::VisibilityMode::set(VisibilityModeType value)
	{
		InternalPhysClassPointer->Set_Visibility_Mode(static_cast<::Visibility_Mode_Type>(value));
	}

	CollisionGroupType PhysClass::CollisionGroup::get()
	{
		return static_cast<CollisionGroupType>(InternalPhysClassPointer->Get_Collision_Group());
	}

	void PhysClass::CollisionGroup::set(CollisionGroupType value)
	{
		InternalPhysClassPointer->Set_Collision_Group(static_cast<::Collision_Group_Type>(value));
	}

	bool PhysClass::IsIgnoreMe::get()
	{
		return InternalPhysClassPointer->Is_Ignore_Me();
	}

	bool PhysClass::IsImmovable::get()
	{
		return InternalPhysClassPointer->Is_Immovable();
	}

	void PhysClass::IsImmovable::set(bool value)
	{
		InternalPhysClassPointer->Set_Immovable(value);
	}

	bool PhysClass::IsDisabled::get()
	{
		return InternalPhysClassPointer->Is_Disabled();
	}

	void PhysClass::IsDisabled::set(bool value)
	{
		InternalPhysClassPointer->Set_Disabled(value);
	}

	bool PhysClass::IsUserControlEnabled::get()
	{
		return InternalPhysClassPointer->Is_User_Control_Enabled();
	}

	void PhysClass::IsUserControlEnabled::set(bool value)
	{
		InternalPhysClassPointer->Enable_User_Control(value);
	}

	bool PhysClass::IsShadowGenerationEnabled::get()
	{
		return InternalPhysClassPointer->Is_Shadow_Generation_Enabled();
	}

	void PhysClass::IsShadowGenerationEnabled::set(bool value)
	{
		InternalPhysClassPointer->Enable_Shadow_Generation(value);
	}

	bool PhysClass::IsForceProjectionShadowEnabled::get()
	{
		return InternalPhysClassPointer->Is_Force_Projection_Shadow_Enabled();
	}

	void PhysClass::IsForceProjectionShadowEnabled::set(bool value)
	{
		InternalPhysClassPointer->Enable_Force_Projection_Shadow(value);
	}

	bool PhysClass::IsDontSaveEnabled::get()
	{
		return InternalPhysClassPointer->Is_Dont_Save_Enabled();
	}

	void PhysClass::IsDontSaveEnabled::set(bool value)
	{
		InternalPhysClassPointer->Enable_Dont_Save(value);
	}

	bool PhysClass::IsAsleep::get()
	{
		return InternalPhysClassPointer->Is_Asleep();
	}

	bool PhysClass::IsWorldSpaceMesh::get()
	{
		return InternalPhysClassPointer->Is_World_Space_Mesh();
	}

	void PhysClass::IsWorldSpaceMesh::set(bool value)
	{
		InternalPhysClassPointer->Enable_Is_World_Space_Mesh(value);
	}

	bool PhysClass::IsPreLit::get()
	{
		return InternalPhysClassPointer->Is_Pre_Lit();
	}

	void PhysClass::IsPreLit::set(bool value)
	{
		InternalPhysClassPointer->Enable_Is_Pre_Lit(value);
	}

	bool PhysClass::IsInTheSun::get()
	{
		return InternalPhysClassPointer->Is_In_The_Sun();
	}

	void PhysClass::IsInTheSun::set(bool value)
	{
		InternalPhysClassPointer->Enable_Is_In_The_Sun(value);
	}

	bool PhysClass::IsStateDirty::get()
	{
		return InternalPhysClassPointer->Is_State_Dirty();
	}

	void PhysClass::IsStateDirty::set(bool value)
	{
		InternalPhysClassPointer->Enable_Is_State_Dirty(value);
	}

	bool PhysClass::IsHidden::get()
	{
		return InternalPhysClassPointer->Is_Hidden();
	}

	void PhysClass::IsHidden::set(bool value)
	{
		InternalPhysClassPointer->Hide(value);
	}

	bool PhysClass::IsObjectsSimulationEnabled::get()
	{
		return InternalPhysClassPointer->Is_Objects_Simulation_Enabled();
	}

	void PhysClass::IsObjectsSimulationEnabled::set(bool value)
	{
		InternalPhysClassPointer->Enable_Objects_Simulation(value);
	}

	IPhysObserverClass ^PhysClass::Observer::get()
	{
		auto result = InternalPhysClassPointer->Get_Observer();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PhysObserverClass(IntPtr(result));
		}
	}

	void PhysClass::Observer::set(IPhysObserverClass ^value)
	{
		if (value == nullptr || value->PhysObserverClassPointer.ToPointer() == nullptr)
		{
			InternalPhysClassPointer->Set_Observer(nullptr);
		}
		else
		{
			InternalPhysClassPointer->Set_Observer(reinterpret_cast<::PhysObserverClass *>(value->PhysObserverClassPointer.ToPointer()));
		}
	}

	IPhysDefClass ^PhysClass::Definition::get()
	{
		auto result = InternalPhysClassPointer->Get_Definition();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PhysDefClass(IntPtr(const_cast<::PhysDefClass *>(result)));
		}
	}

	bool PhysClass::IsSimulationDisabled::get()
	{
		return InternalPhysClassPointer->Is_Simulation_Disabled();
	}

	unsigned int PhysClass::LastVisibleFrame::get()
	{
		return InternalPhysClassPointer->Get_Last_Visible_Frame();
	}

	void PhysClass::LastVisibleFrame::set(unsigned int value)
	{
		InternalPhysClassPointer->Set_Last_Visible_Frame(value);
	}

	bool PhysClass::GetFlag(unsigned int flag)
	{
		auto helper = reinterpret_cast<PhysClassHelper *>(InternalPhysClassPointer);

		return helper->GetFlag(flag);
	}

	void PhysClass::SetFlag(unsigned int flag, bool onoff)
	{
		auto helper = reinterpret_cast<PhysClassHelper *>(InternalPhysClassPointer);

		helper->SetFlag(flag, onoff);
	}

	::CullableClass *PhysClass::InternalCullableClassPointer::get()
	{
		return InternalPhysClassPointer;
	}

	::PostLoadableClass *PhysClass::InternalPostLoadableClassPointer::get()
	{
		return InternalPhysClassPointer;
	}

	::PersistClass *PhysClass::InternalPersistClassPointer::get()
	{
		return InternalPhysClassPointer;
	}

	::MultiListObjectClass *PhysClass::InternalMultiListObjectClassPointer::get()
	{
		return InternalPhysClassPointer;
	}

	::PhysClass *PhysClass::InternalPhysClassPointer::get()
	{
		return reinterpret_cast<::PhysClass *>(Pointer.ToPointer());
	}

	unsigned int PhysClass::Flags::get()
	{
		auto helper = reinterpret_cast<PhysClassHelper *>(InternalPhysClassPointer);

		auto &flags = helper->GetFlags();

		return flags;
	}

	void PhysClass::Flags::set(unsigned int value)
	{
		auto helper = reinterpret_cast<PhysClassHelper *>(InternalPhysClassPointer);

		auto &flags = helper->GetFlags();

		flags = value;
	}

	IRenderObjClass ^PhysClass::Model::get()
	{
		auto helper = reinterpret_cast<PhysClassHelper *>(InternalPhysClassPointer);

		auto &model = helper->GetModel();

		if (model == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(model));
		}
	}

	void PhysClass::Model::set(IRenderObjClass ^value)
	{
		auto helper = reinterpret_cast<PhysClassHelper *>(InternalPhysClassPointer);

		auto &model = helper->GetModel();

		if (value == nullptr || value->RenderObjClassPointer.ToPointer() == nullptr)
		{
			model = nullptr;
		}
		else
		{
			model = reinterpret_cast<::RenderObjClass *>(value->RenderObjClassPointer.ToPointer());
		}
	}

	String ^PhysClass::Name::get()
	{
		auto helper = reinterpret_cast<PhysClassHelper *>(InternalPhysClassPointer);

		auto &name = helper->GetName();

		return gcnew String(name.Peek_Buffer());
	}

	void PhysClass::Name::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<PhysClassHelper *>(InternalPhysClassPointer);

		auto &name = helper->GetName();

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			name = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	IRefMultiListClass<IMaterialEffectClass ^> ^PhysClass::MaterialEffectsOnMe::get()
	{
		auto helper = reinterpret_cast<PhysClassHelper *>(InternalPhysClassPointer);

		auto &materialEffectsOnMe = helper->GetMaterialEffectsOnMe();

		return gcnew MaterialEffectClassRefMultiListClass(IntPtr(&materialEffectsOnMe));
	}

	IntPtr PhysClass::StaticLightingCache::get()
	{
		auto helper = reinterpret_cast<PhysClassHelper *>(InternalPhysClassPointer);

		auto &staticLightingCache = helper->GetStaticLightingCache();

		return IntPtr(staticLightingCache);
	}

	void PhysClass::StaticLightingCache::set(IntPtr value)
	{
		auto helper = reinterpret_cast<PhysClassHelper *>(InternalPhysClassPointer);

		auto &staticLightingCache = helper->GetStaticLightingCache();

		staticLightingCache = reinterpret_cast<::LightEnvironmentClass *>(value.ToPointer());
	}

	unsigned int PhysClass::SunStatusLastUpdated::get()
	{
		auto helper = reinterpret_cast<PhysClassHelper *>(InternalPhysClassPointer);

		auto &sunStatusLastUpdated = helper->GetSunStatusLastUpdated();

		return sunStatusLastUpdated;
	}

	void PhysClass::SunStatusLastUpdated::set(unsigned int value)
	{
		auto helper = reinterpret_cast<PhysClassHelper *>(InternalPhysClassPointer);

		auto &sunStatusLastUpdated = helper->GetSunStatusLastUpdated();

		sunStatusLastUpdated = value;
	}
}