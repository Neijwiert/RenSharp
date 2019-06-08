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
#include "MRenderObjClass.h"

#include "MAABoxClass.h"
#include "MSceneClass.h"
#include "MMatrix3D.h"
#include "MVector3.h"
#include "Mcoltest.h"
#include "Minttest.h"
#include "MSphereClass.h"
#include "MStringClassDynamicVectorClass.h"
#include "UnmanagedContainer.h"
#include "Imports.h"
#include "MChunkClass.h"
#include "MHTreeClass.h"

using namespace System::Text;

namespace RenSharp
{

#pragma managed(push, off)

	class RenderObjClassHelper : public ::RenderObjClass
	{
		private:
			RenderObjClassHelper() = default;

		public:
			unsigned long &GetBits()
			{
				return Bits;
			}

			::SphereClass &GetCachedBoundingSphere()
			{
				return CachedBoundingSphere;
			}

			::AABoxClass &GetCachedBoundingBox()
			{
				return CachedBoundingBox;
			}

			bool &GetIsTransformIdentity()
			{
				return IsTransformIdentity;
			}

			::SceneClass *&GetScene()
			{
				return Scene;
			}

			void *&GetUserData()
			{
				return User_Data;
			}
	};

#pragma managed(pop)

	RenderObjClass::RenderObjClass(IntPtr pointer)
		: RefCountClass(pointer)
	{
		persistClass = gcnew PersistClass(IntPtr(InternalPersistClassPointer));
		multiListObjectClass = gcnew MultiListObjectClass(IntPtr(InternalMultiListObjectClassPointer));
	}

	String ^RenderObjClass::ToString()
	{
		StringBuilder ^builder = gcnew StringBuilder();
		builder->Append(Name);

		return builder->ToString();
	}

	bool RenderObjClass::Equals(Object ^other)
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

		auto otherPersistClass = dynamic_cast<IPersistClass ^>(other);
		if (otherPersistClass != nullptr)
		{
			if (persistClass->PersistClassPointer.Equals(otherPersistClass->PersistClassPointer))
			{
				return true;
			}
		}

		auto otherMultiListObjectClass = dynamic_cast<IMultiListObjectClass ^>(other);
		if (otherMultiListObjectClass != nullptr)
		{
			if (multiListObjectClass->MultiListObjectClassPointer.Equals(otherMultiListObjectClass->MultiListObjectClassPointer))
			{
				return true;
			}
		}

		auto otherRenderObjClass = dynamic_cast<IRenderObjClass ^>(other);
		if (otherRenderObjClass != nullptr)
		{
			if (RenderObjClassPointer.Equals(otherRenderObjClass->RenderObjClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void RenderObjClass::OnPostLoad()
	{
		persistClass->OnPostLoad();
	}

	bool RenderObjClass::Save(IChunkSaveClass ^csave)
	{
		return persistClass->Save(csave);
	}

	bool RenderObjClass::Load(IChunkLoadClass ^cload)
	{
		return persistClass->Load(cload);
	}

	IUnmanagedContainer<IRenderObjClass ^> ^RenderObjClass::Clone()
	{
		auto result = InternalRenderObjClassPointer->Clone();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew UnmanagedContainer<IRenderObjClass ^>(gcnew RenderObjClass(IntPtr(result)));
		}
	}

	void RenderObjClass::Render(IntPtr rInfo)
	{
		if (rInfo.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("rInfo");
		}

		InternalRenderObjClassPointer->Render(
			*reinterpret_cast<::RenderInfoClass *>(rInfo.ToPointer()));
	}

	void RenderObjClass::SpecialRender(IntPtr rInfo)
	{
		if (rInfo.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("rInfo");
		}

		InternalRenderObjClassPointer->Special_Render(
			*reinterpret_cast<::SpecialRenderInfoClass *>(rInfo.ToPointer()));
	}

	void RenderObjClass::OnFrameUpdate()
	{
		InternalRenderObjClassPointer->On_Frame_Update();
	}

	void RenderObjClass::Restart()
	{
		InternalRenderObjClassPointer->Restart();
	}

	void RenderObjClass::Add(ISceneClass ^scene)
	{
		if (scene == nullptr || scene->SceneClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("scene");
		}

		InternalRenderObjClassPointer->Add(
			reinterpret_cast<::SceneClass *>(scene->SceneClassPointer.ToPointer()));
	}

	void RenderObjClass::Remove()
	{
		InternalRenderObjClassPointer->Remove();
	}

	ISceneClass ^RenderObjClass::GetScene()
	{
		auto result = InternalRenderObjClassPointer->Get_Scene();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SceneClass(IntPtr(result));
		}
	}

	ISceneClass ^RenderObjClass::PeekScene()
	{
		auto result = InternalRenderObjClassPointer->Peek_Scene();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SceneClass(IntPtr(result));
		}
	}

	void RenderObjClass::ValidateTransform()
	{
		InternalRenderObjClassPointer->Validate_Transform();
	}

	void RenderObjClass::SetPosition(Vector3 position)
	{
		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		InternalRenderObjClassPointer->Set_Position(positionVec);
	}

	Matrix3D RenderObjClass::GetTransform([Out] bool %isTransformIdentity)
	{
		bool tmpIsTransformIdentity;
		Matrix3D result;

		Matrix3D::UnmanagedToManagedMatrix3D(InternalRenderObjClassPointer->Get_Transform(tmpIsTransformIdentity), result);

		isTransformIdentity = tmpIsTransformIdentity;

		return result;
	}

	Matrix3D RenderObjClass::GetTransformNoValidityCheck()
	{
		Matrix3D result;

		Matrix3D::UnmanagedToManagedMatrix3D(InternalRenderObjClassPointer->Get_Transform_No_Validity_Check(), result);

		return result;
	}

	Matrix3D RenderObjClass::GetTransformNoValidityCheck([Out] bool %isTransformIdentity)
	{
		bool tmpIsTransformIdentity;
		Matrix3D result;

		Matrix3D::UnmanagedToManagedMatrix3D(InternalRenderObjClassPointer->Get_Transform_No_Validity_Check(tmpIsTransformIdentity), result);

		isTransformIdentity = tmpIsTransformIdentity;

		return result;
	}

	void RenderObjClass::NotifyAdded(ISceneClass ^scene)
	{
		if (scene == nullptr || scene->SceneClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("scene");
		}

		InternalRenderObjClassPointer->Notify_Added(
			reinterpret_cast<::SceneClass *>(scene->SceneClassPointer.ToPointer()));
	}

	void RenderObjClass::NotifyRemoved(ISceneClass ^scene)
	{
		if (scene == nullptr || scene->SceneClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("scene");
		}

		InternalRenderObjClassPointer->Notify_Removed(
			reinterpret_cast<::SceneClass *>(scene->SceneClassPointer.ToPointer()));
	}

	IRenderObjClass ^RenderObjClass::GetSubObject(int index)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}
		
		auto result = InternalRenderObjClassPointer->Get_Sub_Object(index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(result));
		}
	}

	int RenderObjClass::AddSubObject(IRenderObjClass ^subObj)
	{
		if (subObj == nullptr || subObj->RenderObjClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("subObj");
		}

		return InternalRenderObjClassPointer->Add_Sub_Object(
			reinterpret_cast<::RenderObjClass *>(subObj->RenderObjClassPointer.ToPointer()));
	}

	int RenderObjClass::RemoveSubObject(IRenderObjClass ^subObj)
	{
		if (subObj == nullptr || subObj->RenderObjClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("subObj");
		}

		return InternalRenderObjClassPointer->Remove_Sub_Object(
			reinterpret_cast<::RenderObjClass *>(subObj->RenderObjClassPointer.ToPointer()));
	}

	IRenderObjClass ^RenderObjClass::GetSubObjectByName(String ^name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			auto result = InternalRenderObjClassPointer->Get_Sub_Object_By_Name(
				reinterpret_cast<char *>(nameHandle.ToPointer()));

			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew RenderObjClass(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	int RenderObjClass::GetNumSubObjectsOnBone(int boneIndex)
	{
		return InternalRenderObjClassPointer->Get_Num_Sub_Objects_On_Bone(boneIndex);
	}

	IRenderObjClass ^RenderObjClass::GetSubObjectOnBone(int index, int boneIndex)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalRenderObjClassPointer->Get_Sub_Object_On_Bone(index, boneIndex);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(result));
		}
	}

	int RenderObjClass::GetSubObjectBoneIndex(IRenderObjClass ^subObj)
	{
		if (subObj == nullptr || subObj->RenderObjClassPointer.ToPointer() == nullptr)
		{
			return InternalRenderObjClassPointer->Get_Sub_Object_Bone_Index(nullptr);
		}
		else
		{
			return InternalRenderObjClassPointer->Get_Sub_Object_Bone_Index(
				reinterpret_cast<::RenderObjClass *>(subObj->RenderObjClassPointer.ToPointer()));
		}
	}

	int RenderObjClass::AddSubObjectToBone(IRenderObjClass ^subObj, int boneIndex)
	{
		if (subObj == nullptr || subObj->RenderObjClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("subObj");
		}
		else if (boneIndex < 0)
		{
			throw gcnew ArgumentOutOfRangeException("boneIndex");
		}

		return InternalRenderObjClassPointer->Add_Sub_Object_To_Bone(
			reinterpret_cast<::RenderObjClass *>(subObj->RenderObjClassPointer.ToPointer()),
			boneIndex);
	}

	int RenderObjClass::AddSubObjectToBone(IRenderObjClass ^subObj, String ^name)
	{
		if (subObj == nullptr || subObj->RenderObjClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("subObj");
		}
		else if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			return InternalRenderObjClassPointer->Add_Sub_Object_To_Bone(
				reinterpret_cast<::RenderObjClass *>(subObj->RenderObjClassPointer.ToPointer()),
				reinterpret_cast<char *>(nameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	int RenderObjClass::RemoveSubObjectsFromBone(String ^boneName)
	{
		if (boneName == nullptr)
		{
			throw gcnew ArgumentNullException("boneName");
		}

		IntPtr boneNameHandle = Marshal::StringToHGlobalAnsi(boneName);
		try
		{
			return InternalRenderObjClassPointer->Remove_Sub_Objects_From_Bone(
				reinterpret_cast<char *>(boneNameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(boneNameHandle);
		}
	}

	void RenderObjClass::UpdateSubObjectTransforms()
	{
		InternalRenderObjClassPointer->Update_Sub_Object_Transforms();
	}

	void RenderObjClass::SetAnimation()
	{
		InternalRenderObjClassPointer->Set_Animation();
	}

	void RenderObjClass::SetAnimation(IntPtr motion, float frame, int animMode)
	{
		InternalRenderObjClassPointer->Set_Animation(
			reinterpret_cast<::HAnimClass *>(motion.ToPointer()),
			frame,
			animMode);
	}

	void RenderObjClass::SetAnimation(IntPtr motion, float frame)
	{
		InternalRenderObjClassPointer->Set_Animation(
			reinterpret_cast<::HAnimClass *>(motion.ToPointer()),
			frame);
	}

	void RenderObjClass::SetAnimation(IntPtr motion0, float frame0, IntPtr motion1, float frame1, float percentage)
	{
		InternalRenderObjClassPointer->Set_Animation(
			reinterpret_cast<::HAnimClass *>(motion0.ToPointer()),
			frame0,
			reinterpret_cast<::HAnimClass *>(motion1.ToPointer()),
			frame1,
			percentage);
	}

	void RenderObjClass::SetAnimation(IntPtr animCombo)
	{
		InternalRenderObjClassPointer->Set_Animation(
			reinterpret_cast<::HAnimComboClass *>(animCombo.ToPointer()));
	}

	IntPtr RenderObjClass::PeekAnimation()
	{
		return IntPtr(InternalRenderObjClassPointer->Peek_Animation());
	}

	String ^RenderObjClass::GetBoneName(int boneIndex)
	{
		if (boneIndex < 0)
		{
			throw gcnew ArgumentOutOfRangeException("boneIndex");
		}

		auto result = InternalRenderObjClassPointer->Get_Bone_Name(boneIndex);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	int RenderObjClass::GetBoneIndex(String ^boneName)
	{
		if (boneName == nullptr)
		{
			throw gcnew ArgumentNullException("boneName");
		}

		IntPtr boneNameHandle = Marshal::StringToHGlobalAnsi(boneName);
		try
		{
			return InternalRenderObjClassPointer->Get_Bone_Index(
				reinterpret_cast<char *>(boneNameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(boneNameHandle);
		}
	}

	Matrix3D RenderObjClass::GetBoneTransform(String ^boneName)
	{
		if (boneName == nullptr)
		{
			throw gcnew ArgumentNullException("boneName");
		}

		IntPtr boneNameHandle = Marshal::StringToHGlobalAnsi(boneName);
		try
		{
			Matrix3D result;

			Matrix3D::UnmanagedToManagedMatrix3D(InternalRenderObjClassPointer->Get_Bone_Transform(
				reinterpret_cast<char *>(boneNameHandle.ToPointer())), result);

			return result;
		}
		finally
		{
			Marshal::FreeHGlobal(boneNameHandle);
		}
	}

	Matrix3D RenderObjClass::GetBoneTransform(int boneIndex)
	{
		if (boneIndex < 0)
		{
			throw gcnew ArgumentOutOfRangeException("boneIndex");
		}

		Matrix3D result;

		Matrix3D::UnmanagedToManagedMatrix3D(InternalRenderObjClassPointer->Get_Bone_Transform(boneIndex), result);
		
		return result;
	}

	void RenderObjClass::CaptureBone(int boneIndex)
	{
		if (boneIndex < 0)
		{
			throw gcnew ArgumentOutOfRangeException("boneIndex");
		}

		InternalRenderObjClassPointer->Capture_Bone(boneIndex);
	}

	void RenderObjClass::ReleaseBone(int boneIndex)
	{
		if (boneIndex < 0)
		{
			throw gcnew ArgumentOutOfRangeException("boneIndex");
		}

		InternalRenderObjClassPointer->Release_Bone(boneIndex);
	}

	bool RenderObjClass::IsBoneCaptured(int boneIndex)
	{
		if (boneIndex < 0)
		{
			throw gcnew ArgumentOutOfRangeException("boneIndex");
		}

		return InternalRenderObjClassPointer->Is_Bone_Captured(boneIndex);
	}

	void RenderObjClass::ControlBone(int boneIndex, Matrix3D objTM, bool worldSpaceTranslation)
	{
		if (boneIndex < 0)
		{
			throw gcnew ArgumentOutOfRangeException("boneIndex");
		}

		::Matrix3D objTMMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(objTM, objTMMat);

		InternalRenderObjClassPointer->Control_Bone(boneIndex, objTMMat, worldSpaceTranslation);
	}

	void RenderObjClass::ControlBone(int boneIndex, Matrix3D objTM)
	{
		if (boneIndex < 0)
		{
			throw gcnew ArgumentOutOfRangeException("boneIndex");
		}

		::Matrix3D objTMMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(objTM, objTMMat);

		InternalRenderObjClassPointer->Control_Bone(boneIndex, objTMMat);
	}

	bool RenderObjClass::CastRay(IRayCollisionTestClass ^ray)
	{
		if (ray == nullptr || ray->RayCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("ray");
		}

		return InternalRenderObjClassPointer->Cast_Ray(
			*reinterpret_cast<::RayCollisionTestClass *>(ray->RayCollisionTestClassPointer.ToPointer()));
	}

	bool RenderObjClass::CastRay(RayCollisionTestClass ^ray)
	{
		if (ray == nullptr)
		{
			throw gcnew ArgumentNullException("ray");
		}

		auto tmp = RenSharpRayCollisionTestClass::CreateRenSharpRayCollisionTestClass(ray);
		try
		{
			bool result = InternalRenderObjClassPointer->Cast_Ray(
				*reinterpret_cast<::RayCollisionTestClass *>(tmp->UnmanagedObject->RayCollisionTestClassPointer.ToPointer()));

			ray->CopyFrom(tmp->UnmanagedObject);

			return result;
		}
		finally
		{
#pragma push_macro("delete")
#undef delete

			delete tmp;
			tmp = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool RenderObjClass::CastAABox(IAABoxCollisionTestClass ^box)
	{
		if (box == nullptr || box->AABoxCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("box");
		}

		return InternalRenderObjClassPointer->Cast_AABox(
			*reinterpret_cast<::AABoxCollisionTestClass *>(box->AABoxCollisionTestClassPointer.ToPointer()));
	}

	bool RenderObjClass::CastAABox(AABoxCollisionTestClass ^box)
	{
		if (box == nullptr)
		{
			throw gcnew ArgumentNullException("box");
		}

		auto tmp = RenSharpAABoxCollisionTestClass::CreateRenSharpAABoxCollisionTestClass(box);
		try
		{
			bool result = InternalRenderObjClassPointer->Cast_AABox(
				*reinterpret_cast<::AABoxCollisionTestClass *>(tmp->UnmanagedObject->AABoxCollisionTestClassPointer.ToPointer()));

			box->CopyFrom(tmp->UnmanagedObject);

			return result;
		}
		finally
		{
#pragma push_macro("delete")
#undef delete

			delete tmp;
			tmp = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool RenderObjClass::CastOBBox(IOBBoxCollisionTestClass ^box)
	{
		if (box == nullptr || box->OBBoxCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("box");
		}

		return InternalRenderObjClassPointer->Cast_OBBox(
			*reinterpret_cast<::OBBoxCollisionTestClass *>(box->OBBoxCollisionTestClassPointer.ToPointer()));
	}

	bool RenderObjClass::CastOBBox(OBBoxCollisionTestClass ^box)
	{
		if (box == nullptr)
		{
			throw gcnew ArgumentNullException("box");
		}

		auto tmp = RenSharpOBBoxCollisionTestClass::CreateRenSharpOBBoxCollisionTestClass(box);
		try
		{
			bool result = InternalRenderObjClassPointer->Cast_OBBox(
				*reinterpret_cast<::OBBoxCollisionTestClass *>(tmp->UnmanagedObject->OBBoxCollisionTestClassPointer.ToPointer()));

			box->CopyFrom(tmp->UnmanagedObject);

			return result;
		}
		finally
		{
#pragma push_macro("delete")
#undef delete

			delete tmp;
			tmp = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool RenderObjClass::IntersectAABox(IAABoxIntersectionTestClass ^box)
	{
		if (box == nullptr || box->AABoxIntersectionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("box");
		}

		return InternalRenderObjClassPointer->Intersect_AABox(
			*reinterpret_cast<::AABoxIntersectionTestClass *>(box->AABoxIntersectionTestClassPointer.ToPointer()));
	}

	bool RenderObjClass::IntersectAABox(AABoxIntersectionTestClass ^box)
	{
		if (box == nullptr)
		{
			throw gcnew ArgumentNullException("box");
		}

		auto tmp = AABoxIntersectionTestClassRef::CreateAABoxIntersectionTestClassRef(box);
		try
		{
			bool result = InternalRenderObjClassPointer->Intersect_AABox(
				*reinterpret_cast<::AABoxIntersectionTestClass *>(tmp->UnmanagedObject->AABoxIntersectionTestClassPointer.ToPointer()));

			box->CopyFrom(tmp->UnmanagedObject);

			return result;
		}
		finally
		{
#pragma push_macro("delete")
#undef delete

			delete tmp;
			tmp = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool RenderObjClass::IntersectOBBox(IOBBoxIntersectionTestClass ^box)
	{
		if (box == nullptr || box->OBBoxIntersectionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("box");
		}

		return InternalRenderObjClassPointer->Intersect_OBBox(
			*reinterpret_cast<::OBBoxIntersectionTestClass *>(box->OBBoxIntersectionTestClassPointer.ToPointer()));
	}

	bool RenderObjClass::IntersectOBBox(OBBoxIntersectionTestClass ^box)
	{
		if (box == nullptr)
		{
			throw gcnew ArgumentNullException("box");
		}

		auto tmp = OBBoxIntersectionTestClassRef::CreateOBBoxIntersectionTestClassRef(box);
		try
		{
			bool result = InternalRenderObjClassPointer->Intersect_OBBox(
				*reinterpret_cast<::OBBoxIntersectionTestClass *>(tmp->UnmanagedObject->OBBoxIntersectionTestClassPointer.ToPointer()));

			box->CopyFrom(tmp->UnmanagedObject);

			return result;
		}
		finally
		{
#pragma push_macro("delete")
#undef delete

			delete tmp;
			tmp = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool RenderObjClass::Intersect(IntPtr intersection, IntPtr finalResult)
	{
		if (intersection.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("intersection");
		}
		else if (finalResult.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("finalResult");
		}

		return InternalRenderObjClassPointer->Intersect(
			reinterpret_cast<::IntersectionClass *>(intersection.ToPointer()),
			reinterpret_cast<::IntersectionResultClass *>(finalResult.ToPointer()));
	}

	bool RenderObjClass::IntersectSphere(IntPtr intersection, IntPtr finalResult)
	{
		if (intersection.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("intersection");
		}
		else if (finalResult.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("finalResult");
		}

		return InternalRenderObjClassPointer->Intersect_Sphere(
			reinterpret_cast<::IntersectionClass *>(intersection.ToPointer()),
			reinterpret_cast<::IntersectionResultClass *>(finalResult.ToPointer()));
	}

	bool RenderObjClass::IntersectSphereQuick(IntPtr intersection, IntPtr finalResult)
	{
		if (intersection.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("intersection");
		}
		else if (finalResult.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("finalResult");
		}

		return InternalRenderObjClassPointer->Intersect_Sphere_Quick(
			reinterpret_cast<::IntersectionClass *>(intersection.ToPointer()),
			reinterpret_cast<::IntersectionResultClass *>(finalResult.ToPointer()));
	}

	void RenderObjClass::UpdateObjSpaceBoundingVolumes()
	{
		InternalRenderObjClassPointer->Update_Obj_Space_Bounding_Volumes();
	}

	void RenderObjClass::PrepareLOD(IntPtr camera)
	{
		if (camera.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("camera");
		}

		InternalRenderObjClassPointer->Prepare_LOD(
			*reinterpret_cast<::CameraClass *>(camera.ToPointer()));
	}

	void RenderObjClass::RecalculateStaticLODFactors()
	{
		InternalRenderObjClassPointer->Recalculate_Static_LOD_Factors();
	}

	void RenderObjClass::IncrementLOD()
	{
		InternalRenderObjClassPointer->Increment_LOD();
	}

	void RenderObjClass::DecrementLOD()
	{
		InternalRenderObjClassPointer->Decrement_LOD();
	}

	void RenderObjClass::SetLODBias(float bias)
	{
		InternalRenderObjClassPointer->Set_LOD_Bias(bias);
	}

	int RenderObjClass::CalculateCostValueArrays(float screenArea, [Out] array<float> ^%values, [Out] array<float> ^%costs)
	{
		int arraySize = InternalRenderObjClassPointer->Get_LOD_Count() + 1;

		values = gcnew array<float>(arraySize);
		costs = gcnew array<float>(arraySize);

		float *tmpValues = Imports::CreateFloatArray(arraySize);
		try
		{
			float *tmpCosts = Imports::CreateFloatArray(arraySize);
			try
			{
				int result = InternalRenderObjClassPointer->Calculate_Cost_Value_Arrays(screenArea, tmpValues, tmpCosts);

				for (int x = 0; x < arraySize; x++)
				{
					values[x] = tmpValues[x];
					costs[x] = tmpCosts[x];
				}

				return result;
			}
			finally
			{
				Imports::DestroyFloatArray(tmpCosts);
				tmpCosts = nullptr;
			}
		}
		finally
		{
			Imports::DestroyFloatArray(tmpValues);
			tmpValues = nullptr;
		}
	}

	bool RenderObjClass::BuildDependencyList([Out] Generic::ICollection<String ^> ^%fileList, bool recursive)
	{
		auto tmpFileList = StringClassDynamicVectorClass::CreateStringClassDynamicVectorClass();
		try
		{
			bool result = InternalRenderObjClassPointer->Build_Dependency_List(
				*reinterpret_cast<::DynamicVectorClass<::StringClass> *>(tmpFileList->UnmanagedObject->Pointer.ToPointer()),
				recursive);

			fileList = gcnew Generic::List<String ^>(tmpFileList->UnmanagedObject->Count);

			for each(String ^file in tmpFileList->UnmanagedObject)
			{
				fileList->Add(file);
			}

			return result;
		}
		finally
		{
#pragma push_macro("delete")
#undef delete

			delete tmpFileList;
			tmpFileList = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool RenderObjClass::BuildDependencyList([Out] Generic::ICollection<String ^> ^%fileList)
	{
		auto tmpFileList = StringClassDynamicVectorClass::CreateStringClassDynamicVectorClass();
		try
		{
			bool result = InternalRenderObjClassPointer->Build_Dependency_List(
				*reinterpret_cast<::DynamicVectorClass<::StringClass> *>(tmpFileList->UnmanagedObject->Pointer.ToPointer()));

			fileList = gcnew Generic::List<String ^>(tmpFileList->UnmanagedObject->Count);

			for each(String ^file in tmpFileList->UnmanagedObject)
			{
				fileList->Add(file);
			}

			return result;
		}
		finally
		{
#pragma push_macro("delete")
#undef delete

			delete tmpFileList;
			tmpFileList = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool RenderObjClass::BuildTextureList([Out] Generic::ICollection<String ^> ^%textureFileList, bool recursive)
	{
		auto tmpFileList = StringClassDynamicVectorClass::CreateStringClassDynamicVectorClass();
		try
		{
			bool result = InternalRenderObjClassPointer->Build_Texture_List(
				*reinterpret_cast<::DynamicVectorClass<::StringClass> *>(tmpFileList->UnmanagedObject->Pointer.ToPointer()),
				recursive);

			textureFileList = gcnew Generic::List<String ^>(tmpFileList->UnmanagedObject->Count);

			for each(String ^file in tmpFileList->UnmanagedObject)
			{
				textureFileList->Add(file);
			}

			return result;
		}
		finally
		{
#pragma push_macro("delete")
#undef delete

			delete tmpFileList;
			tmpFileList = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool RenderObjClass::BuildTextureList([Out] Generic::ICollection<String ^> ^%textureFileList)
	{
		auto tmpFileList = StringClassDynamicVectorClass::CreateStringClassDynamicVectorClass();
		try
		{
			bool result = InternalRenderObjClassPointer->Build_Texture_List(
				*reinterpret_cast<::DynamicVectorClass<::StringClass> *>(tmpFileList->UnmanagedObject->Pointer.ToPointer()));

			textureFileList = gcnew Generic::List<String ^>(tmpFileList->UnmanagedObject->Count);

			for each(String ^file in tmpFileList->UnmanagedObject)
			{
				textureFileList->Add(file);
			}

			return result;
		}
		finally
		{
#pragma push_macro("delete")
#undef delete

			delete tmpFileList;
			tmpFileList = nullptr;

#pragma pop_macro("delete")
		}
	}

	void RenderObjClass::CreateDecal(IntPtr generator)
	{
		if (generator.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("generator");
		}

		InternalRenderObjClassPointer->Create_Decal(
			reinterpret_cast<::DecalGeneratorClass *>(generator.ToPointer()));
	}

	void RenderObjClass::DeleteDecal(uint32 decalId)
	{
		InternalRenderObjClassPointer->Delete_Decal(decalId);
	}

	void RenderObjClass::SetUserData(IntPtr value, bool recursive)
	{
		InternalRenderObjClassPointer->Set_User_Data(value.ToPointer(), recursive);
	}

	Vector3 RenderObjClass::GetSnapPoint(int point)
	{
		::Vector3 tmp;

		InternalRenderObjClassPointer->Get_Snap_Point(point, &tmp);

		Vector3 result;

		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	float RenderObjClass::GetScreenSize(IntPtr camera)
	{
		if (camera.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("camera");
		}

		return InternalRenderObjClassPointer->Get_Screen_Size(
			*reinterpret_cast<::CameraClass *>(camera.ToPointer()));
	}

	void RenderObjClass::Scale(float scale)
	{
		InternalRenderObjClassPointer->Scale(scale);
	}

	void RenderObjClass::Scale(float scaleX, float scaleY, float scaleZ)
	{
		InternalRenderObjClassPointer->Scale(scaleX, scaleY, scaleZ);
	}

	void RenderObjClass::SaveUserLighting(IChunkSaveClass ^cSave)
	{
		if (cSave == nullptr || cSave->ChunkSaveClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("cSave");
		}

		InternalRenderObjClassPointer->Save_User_Lighting(
			*reinterpret_cast<::ChunkSaveClass *>(cSave->ChunkSaveClassPointer.ToPointer()));
	}

	void RenderObjClass::LoadUserLighting(IChunkLoadClass ^cLoad)
	{
		if (cLoad == nullptr || cLoad->ChunkLoadClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("cLoad");
		}

		InternalRenderObjClassPointer->Load_User_Lighting(
			*reinterpret_cast<::ChunkLoadClass *>(cLoad->ChunkLoadClassPointer.ToPointer()));
	}

	Generic::ICollection<String ^> ^RenderObjClass::AddDependenciesToList(bool texturesOnly)
	{
		auto tmpFileList = StringClassDynamicVectorClass::CreateStringClassDynamicVectorClass();
		try
		{
			InternalRenderObjClassPointer->Add_Dependencies_To_List(
				*reinterpret_cast<::DynamicVectorClass<::StringClass> *>(tmpFileList->UnmanagedObject->Pointer.ToPointer()),
				texturesOnly);

			Generic::ICollection<String ^> ^result = gcnew Generic::List<String ^>(tmpFileList->UnmanagedObject->Count);

			for each(String ^file in tmpFileList->UnmanagedObject)
			{
				result->Add(file);
			}

			return result;
		}
		finally
		{
#pragma push_macro("delete")
#undef delete

			delete tmpFileList;
			tmpFileList = nullptr;

#pragma pop_macro("delete")
		}
	}

	Generic::ICollection<String ^> ^RenderObjClass::AddDependenciesToList()
	{
		auto tmpFileList = StringClassDynamicVectorClass::CreateStringClassDynamicVectorClass();
		try
		{
			InternalRenderObjClassPointer->Add_Dependencies_To_List(
				*reinterpret_cast<::DynamicVectorClass<::StringClass> *>(tmpFileList->UnmanagedObject->Pointer.ToPointer()));

			Generic::ICollection<String ^> ^result = gcnew Generic::List<String ^>(tmpFileList->UnmanagedObject->Count);

			for each(String ^file in tmpFileList->UnmanagedObject)
			{
				result->Add(file);
			}

			return result;
		}
		finally
		{
#pragma push_macro("delete")
#undef delete

			delete tmpFileList;
			tmpFileList = nullptr;

#pragma pop_macro("delete")
		}
	}

	void RenderObjClass::UpdateCachedBoundingVolumes()
	{
		InternalRenderObjClassPointer->Update_Cached_Bounding_Volumes();
	}

	void RenderObjClass::UpdateSubObjectBits()
	{
		InternalRenderObjClassPointer->Update_Sub_Object_Bits();
	}

	void RenderObjClass::SetSubObjectTransformsDirty(bool onoff)
	{
		InternalRenderObjClassPointer->Set_Sub_Object_Transforms_Dirty(onoff);
	}

	void RenderObjClass::InvalidateCachedBoundingVolumes()
	{
		InternalRenderObjClassPointer->Invalidate_Cached_Bounding_Volumes();
	}

	void RenderObjClass::ValidateCachedBoundingVolumes()
	{
		InternalRenderObjClassPointer->Validate_Cached_Bounding_Volumes();
	}

	IntPtr RenderObjClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void RenderObjClass::Pointer::set(IntPtr value)
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

	IntPtr RenderObjClass::PostLoadableClassPointer::get()
	{
		return IntPtr(InternalPostLoadableClassPointer);
	}

	IntPtr RenderObjClass::PersistClassPointer::get()
	{
		return IntPtr(InternalPersistClassPointer);
	}

	IntPtr RenderObjClass::MultiListObjectClassPointer::get()
	{
		return IntPtr(InternalMultiListObjectClassPointer);
	}

	IntPtr RenderObjClass::RenderObjClassPointer::get()
	{
		return IntPtr(InternalRenderObjClassPointer);
	}

	bool RenderObjClass::IsPostLoadRegistered::get()
	{
		return persistClass->IsPostLoadRegistered;
	}

	void RenderObjClass::IsPostLoadRegistered::set(bool value)
	{
		persistClass->IsPostLoadRegistered = value;
	}

	IPersistFactoryClass ^RenderObjClass::Factory::get()
	{
		return persistClass->Factory;
	}

	IMultiListNodeClass ^RenderObjClass::ListNode::get()
	{
		return multiListObjectClass->ListNode;
	}

	void RenderObjClass::ListNode::set(IMultiListNodeClass ^value)
	{
		multiListObjectClass->ListNode = value;
	}

	AABoxClass RenderObjClass::BoundingBox::get()
	{
		AABoxClass result;

		AABoxClass::UnmanagedToManagedAABoxClass(InternalRenderObjClassPointer->Get_Bounding_Box(), result);

		return result;
	}

	int RenderObjClass::ClassId::get()
	{
		return InternalRenderObjClassPointer->Class_ID();
	}

	String ^RenderObjClass::Name::get()
	{
		auto result = InternalRenderObjClassPointer->Get_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	void RenderObjClass::Name::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalRenderObjClassPointer->Set_Name(
				reinterpret_cast<char *>(valueHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	String ^RenderObjClass::BaseModelName::get()
	{
		auto result = InternalRenderObjClassPointer->Get_Base_Model_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	void RenderObjClass::BaseModelName::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalRenderObjClassPointer->Set_Base_Model_Name(
				reinterpret_cast<char *>(valueHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	int RenderObjClass::NumPolys::get()
	{
		return InternalRenderObjClassPointer->Get_Num_Polys();
	}

	IRenderObjClass ^RenderObjClass::Container::get()
	{
		auto result = InternalRenderObjClassPointer->Get_Container();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(result));
		}
	}

	void RenderObjClass::Container::set(IRenderObjClass ^value)
	{
		if (value == nullptr || value->RenderObjClassPointer.ToPointer() == nullptr)
		{
			InternalRenderObjClassPointer->Set_Container(nullptr);
		}
		else
		{
			InternalRenderObjClassPointer->Set_Container(
				reinterpret_cast<::RenderObjClass *>(value->RenderObjClassPointer.ToPointer()));
		}
	}

	Matrix3D RenderObjClass::Transform::get()
	{
		Matrix3D result;

		Matrix3D::UnmanagedToManagedMatrix3D(InternalRenderObjClassPointer->Get_Transform(), result);

		return result;
	}

	void RenderObjClass::Transform::set(Matrix3D value)
	{
		::Matrix3D tmp;

		Matrix3D::ManagedToUnmanagedMatrix3D(value, tmp);

		InternalRenderObjClassPointer->Set_Transform(tmp);
	}

	bool RenderObjClass::IsTransformIdentity::get()
	{
		return InternalRenderObjClassPointer->Is_Transform_Identity();
	}

	void RenderObjClass::IsTransformIdentity::set(bool value)
	{
		auto helper = reinterpret_cast<RenderObjClassHelper *>(InternalRenderObjClassPointer);

		auto &isTransformIdentity = helper->GetIsTransformIdentity();

		isTransformIdentity = value;
	}

	bool RenderObjClass::IsTransformIdentityNoValidityCheck::get()
	{
		return InternalRenderObjClassPointer->Is_Transform_Identity_No_Validity_Check();
	}

	int RenderObjClass::NumSubObjects::get()
	{
		return InternalRenderObjClassPointer->Get_Num_Sub_Objects();
	}

	int RenderObjClass::NumBones::get()
	{
		return InternalRenderObjClassPointer->Get_Num_Bones();
	}

	IHTreeClass ^RenderObjClass::HTree::get()
	{
		auto result = InternalRenderObjClassPointer->Get_HTree();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew HTreeClass(IntPtr(const_cast<::HTreeClass *>(result)));
		}
	}

	SphereClass RenderObjClass::BoundingSphere::get()
	{
		SphereClass result;

		SphereClass::UnmanagedToManagedSphereClass(InternalRenderObjClassPointer->Get_Bounding_Sphere(), result);

		return result;
	}

	SphereClass RenderObjClass::ObjSpaceBoundingSphere::get()
	{
		::SphereClass tmp;

		InternalRenderObjClassPointer->Get_Obj_Space_Bounding_Sphere(tmp);

		SphereClass result;

		SphereClass::UnmanagedToManagedSphereClass(tmp, result);

		return result;
	}

	AABoxClass RenderObjClass::ObjSpaceBoundingBox::get()
	{
		::AABoxClass tmp;

		InternalRenderObjClassPointer->Get_Obj_Space_Bounding_Box(tmp);

		AABoxClass result;

		AABoxClass::UnmanagedToManagedAABoxClass(tmp, result);

		return result;
	}

	float RenderObjClass::Cost::get()
	{
		return InternalRenderObjClassPointer->Get_Cost();
	}

	float RenderObjClass::Value::get()
	{
		return InternalRenderObjClassPointer->Get_Value();
	}

	float RenderObjClass::PostIncrementValue::get()
	{
		return InternalRenderObjClassPointer->Get_Post_Increment_Value();
	}

	int RenderObjClass::LODLevel::get()
	{
		return InternalRenderObjClassPointer->Get_LOD_Level();
	}

	void RenderObjClass::LODLevel::set(int value)
	{
		InternalRenderObjClassPointer->Set_LOD_Level(value);
	}

	int RenderObjClass::LODCount::get()
	{
		return InternalRenderObjClassPointer->Get_LOD_Count();
	}

	IRenderObjClass ^RenderObjClass::CurrentLOD::get()
	{
		auto result = InternalRenderObjClassPointer->Get_Current_LOD();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(result));
		}
	}

	IntPtr RenderObjClass::MaterialInfo::get()
	{
		return IntPtr(InternalRenderObjClassPointer->Get_Material_Info());
	}

	IntPtr RenderObjClass::UserData::get()
	{
		return IntPtr(InternalRenderObjClassPointer->Get_User_Data());
	}

	void RenderObjClass::UserData::set(IntPtr value)
	{
		auto helper = reinterpret_cast<RenderObjClassHelper *>(InternalRenderObjClassPointer);

		auto &userData = helper->GetUserData();

		userData = value.ToPointer();
	}

	int RenderObjClass::NumSnapPoints::get()
	{
		return InternalRenderObjClassPointer->Get_Num_Snap_Points();
	}

	int RenderObjClass::SortLevel::get()
	{
		return InternalRenderObjClassPointer->Get_Sort_Level();
	}

	void RenderObjClass::SortLevel::set(int value)
	{
		InternalRenderObjClassPointer->Set_Sort_Level(value);
	}

	int RenderObjClass::IsReallyVisible::get()
	{
		return InternalRenderObjClassPointer->Is_Really_Visible();
	}

	int RenderObjClass::IsNotHiddenAtAll::get()
	{
		return InternalRenderObjClassPointer->Is_Not_Hidden_At_All();
	}

	int RenderObjClass::IsVisible::get()
	{
		return InternalRenderObjClassPointer->Is_Visible();
	}

	void RenderObjClass::IsVisible::set(int value)
	{
		InternalRenderObjClassPointer->Set_Visible(value);
	}

	int RenderObjClass::IsHidden::get()
	{
		return InternalRenderObjClassPointer->Is_Hidden();
	}

	void RenderObjClass::IsHidden::set(int value)
	{
		InternalRenderObjClassPointer->Set_Hidden(value);
	}

	int RenderObjClass::IsAnimationHidden::get()
	{
		return InternalRenderObjClassPointer->Is_Animation_Hidden();
	}

	void RenderObjClass::IsAnimationHidden::set(int value)
	{
		InternalRenderObjClassPointer->Set_Animation_Hidden(value);
	}

	int RenderObjClass::IsForceVisible::get()
	{
		return InternalRenderObjClassPointer->Is_Force_Visible();
	}

	void RenderObjClass::IsForceVisible::set(int value)
	{
		InternalRenderObjClassPointer->Set_Force_Visible(value);
	}

	int RenderObjClass::HasUserLighting::get()
	{
		return InternalRenderObjClassPointer->Has_User_Lighting();
	}

	void RenderObjClass::HasUserLighting::set(int value)
	{
		InternalRenderObjClassPointer->Set_Has_User_Lighting(value);
	}

	int RenderObjClass::IsTranslucent::get()
	{
		return InternalRenderObjClassPointer->Is_Translucent();
	}

	void RenderObjClass::IsTranslucent::set(int value)
	{
		InternalRenderObjClassPointer->Set_Translucent(value);
	}

	int RenderObjClass::CollisionType::get()
	{
		return InternalRenderObjClassPointer->Get_Collision_Type();
	}

	void RenderObjClass::CollisionType::set(int value)
	{
		InternalRenderObjClassPointer->Set_Collision_Type(value);
	}

	int RenderObjClass::IsComplete::get()
	{
		return InternalRenderObjClassPointer->Is_Complete();
	}

	int RenderObjClass::IsInScene::get()
	{
		return InternalRenderObjClassPointer->Is_In_Scene();
	}

	float RenderObjClass::NativeScreenSize::get()
	{
		return InternalRenderObjClassPointer->Get_Native_Screen_Size();
	}

	void RenderObjClass::NativeScreenSize::set(float value)
	{
		InternalRenderObjClassPointer->Set_Native_Screen_Size(value);
	}

	int RenderObjClass::IsSubObjectsMatchLODEnabled::get()
	{
		return InternalRenderObjClassPointer->Is_Sub_Objects_Match_LOD_Enabled();
	}

	void RenderObjClass::IsSubObjectsMatchLODEnabled::set(int value)
	{
		InternalRenderObjClassPointer->Set_Sub_Objects_Match_LOD(value);
	}

	::RefCountClass *RenderObjClass::InternalRefCountClassPointer::get()
	{
		return InternalRenderObjClassPointer;
	}

	::PostLoadableClass *RenderObjClass::InternalPostLoadableClassPointer::get()
	{
		return InternalRenderObjClassPointer;
	}

	::PersistClass *RenderObjClass::InternalPersistClassPointer::get()
	{
		return InternalRenderObjClassPointer;
	}

	::MultiListObjectClass *RenderObjClass::InternalMultiListObjectClassPointer::get()
	{
		return InternalRenderObjClassPointer;
	}

	::RenderObjClass *RenderObjClass::InternalRenderObjClassPointer::get()
	{
		return reinterpret_cast<::RenderObjClass *>(Pointer.ToPointer());
	}

	unsigned long RenderObjClass::Bits::get()
	{
		auto helper = reinterpret_cast<RenderObjClassHelper *>(InternalRenderObjClassPointer);

		auto &bits = helper->GetBits();

		return bits;
	}

	void RenderObjClass::Bits::set(unsigned long value)
	{
		auto helper = reinterpret_cast<RenderObjClassHelper *>(InternalRenderObjClassPointer);

		auto &bits = helper->GetBits();

		bits = value;
	}

	SphereClass RenderObjClass::CachedBoundingSphere::get()
	{
		auto helper = reinterpret_cast<RenderObjClassHelper *>(InternalRenderObjClassPointer);

		auto &cachedBoundingSphere = helper->GetCachedBoundingSphere();

		SphereClass result;

		SphereClass::UnmanagedToManagedSphereClass(cachedBoundingSphere, result);

		return result;
	}

	void RenderObjClass::CachedBoundingSphere::set(SphereClass value)
	{
		auto helper = reinterpret_cast<RenderObjClassHelper *>(InternalRenderObjClassPointer);

		auto &cachedBoundingSphere = helper->GetCachedBoundingSphere();

		SphereClass::ManagedToUnmanagedSphereClass(value, cachedBoundingSphere);
	}

	AABoxClass RenderObjClass::CachedBoundingBox::get()
	{
		auto helper = reinterpret_cast<RenderObjClassHelper *>(InternalRenderObjClassPointer);

		auto &cachedBoundingBox = helper->GetCachedBoundingBox();

		AABoxClass result;

		AABoxClass::UnmanagedToManagedAABoxClass(cachedBoundingBox, result);

		return result;
	}

	void RenderObjClass::CachedBoundingBox::set(AABoxClass value)
	{
		auto helper = reinterpret_cast<RenderObjClassHelper *>(InternalRenderObjClassPointer);

		auto &cachedBoundingBox = helper->GetCachedBoundingBox();

		AABoxClass::ManagedToUnmanagedAABoxClass(value, cachedBoundingBox);
	}

	ISceneClass ^RenderObjClass::Scene::get()
	{
		auto helper = reinterpret_cast<RenderObjClassHelper *>(InternalRenderObjClassPointer);

		auto &scene = helper->GetScene();

		if (scene == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SceneClass(IntPtr(helper));
		}
	}

	void RenderObjClass::Scene::set(ISceneClass ^value)
	{
		auto helper = reinterpret_cast<RenderObjClassHelper *>(InternalRenderObjClassPointer);

		auto &scene = helper->GetScene();

		if (value == nullptr || value->SceneClassPointer.ToPointer() == nullptr)
		{
			scene = nullptr;
		}
		else
		{
			scene = reinterpret_cast<::SceneClass *>(value->SceneClassPointer.ToPointer());
		}
	}
}