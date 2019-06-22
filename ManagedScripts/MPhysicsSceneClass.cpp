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
#include "MPhysicsSceneClass.h"

#include "Mphyscoltest.h"
#include "obboxclass.h"
#include "MVisTableClass.h"
#include "MVisTableMgrClass.h"
#include "MRenderObjClassRefMultiListClass.h"
#include "MTexProjectClassMultiListClass.h"
#include "MTexProjectClassTypedAABTreeCullSystemClass.h"
#include "MTexProjectClassTypedGridCullSystemClass.h"
#include "MPhysClassRefMultiListClass.h"
#include "MPhysClassMultiListClass.h"
#include "Imports.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	PhysicsSceneClass::StatsStruct::StatsStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool PhysicsSceneClass::StatsStruct::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		PhysicsSceneClass::IStatsStruct^ otherThis = dynamic_cast<PhysicsSceneClass::IStatsStruct^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return StatsStructPointer.Equals(otherThis->StatsStructPointer);
	}

	IntPtr PhysicsSceneClass::StatsStruct::StatsStructPointer::get()
	{
		return IntPtr(InternalStatsStructPointer);
	}

	int PhysicsSceneClass::StatsStruct::FrameCount::get()
	{
		return InternalStatsStructPointer->FrameCount;
	}

	void PhysicsSceneClass::StatsStruct::FrameCount::set(int value)
	{
		InternalStatsStructPointer->FrameCount = value;
	}

	int PhysicsSceneClass::StatsStruct::CullNodeCount::get()
	{
		return InternalStatsStructPointer->CullNodeCount;
	}

	void PhysicsSceneClass::StatsStruct::CullNodeCount::set(int value)
	{
		InternalStatsStructPointer->CullNodeCount = value;
	}

	int PhysicsSceneClass::StatsStruct::CullNodesAccepted::get()
	{
		return InternalStatsStructPointer->CullNodesAccepted;
	}

	void PhysicsSceneClass::StatsStruct::CullNodesAccepted::set(int value)
	{
		InternalStatsStructPointer->CullNodesAccepted = value;
	}

	int PhysicsSceneClass::StatsStruct::CullNodesTriviallyAccepted::get()
	{
		return InternalStatsStructPointer->CullNodesTriviallyAccepted;
	}

	void PhysicsSceneClass::StatsStruct::CullNodesTriviallyAccepted::set(int value)
	{
		InternalStatsStructPointer->CullNodesTriviallyAccepted = value;
	}

	int PhysicsSceneClass::StatsStruct::CullNodesRejected::get()
	{
		return InternalStatsStructPointer->CullNodesRejected;
	}

	void PhysicsSceneClass::StatsStruct::CullNodesRejected::set(int value)
	{
		InternalStatsStructPointer->CullNodesRejected = value;
	}

	bool PhysicsSceneClass::StatsStruct::InternalDestroyPointer()
	{
		Imports::DestroyPhysicsSceneClassStatsStruct(InternalStatsStructPointer);
		Pointer = IntPtr::Zero;
		
		return true;
	}

	::PhysicsSceneClass::StatsStruct* PhysicsSceneClass::StatsStruct::InternalStatsStructPointer::get()
	{
		return reinterpret_cast<::PhysicsSceneClass::StatsStruct*>(Pointer.ToPointer());
	}

	PhysicsSceneClass::PhysicsSceneClass(IntPtr pointer)
		: SceneClass(pointer)
	{

	}

	bool PhysicsSceneClass::CastRay(IPhysRayCollisionTestClass^ raytest, bool useCollisionRegion)
	{
		if (raytest == nullptr || raytest->PhysRayCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("raytest");
		}

		return InternalPhysicsSceneClassPointer->Cast_Ray(
			*reinterpret_cast<::PhysRayCollisionTestClass*>(raytest->PhysRayCollisionTestClassPointer.ToPointer()),
			useCollisionRegion);
	}

	bool PhysicsSceneClass::CastRay(IPhysRayCollisionTestClass^ raytest)
	{
		if (raytest == nullptr || raytest->PhysRayCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("raytest");
		}

		return InternalPhysicsSceneClassPointer->Cast_Ray(
			*reinterpret_cast<::PhysRayCollisionTestClass*>(raytest->PhysRayCollisionTestClassPointer.ToPointer()));
	}

	bool PhysicsSceneClass::CastRay(PhysRayCollisionTestClass^ raytest, bool useCollisionRegion)
	{
		if (raytest == nullptr)
		{
			throw gcnew ArgumentNullException("raytest");
		}

		auto unmanagedRayTest = RenSharpPhysRayCollisionTestClass::CreateRenSharpPhysRayCollisionTestClass(raytest);
		try
		{
			bool result = InternalPhysicsSceneClassPointer->Cast_Ray(
				*reinterpret_cast<::PhysRayCollisionTestClass*>(unmanagedRayTest->UnmanagedObject->PhysRayCollisionTestClassPointer.ToPointer()),
				useCollisionRegion);

			raytest->CopyFrom(unmanagedRayTest->UnmanagedObject);

			return result;
		}
		finally
		{
#pragma push_macro("delete")
#undef delete

			delete unmanagedRayTest;
			unmanagedRayTest = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool PhysicsSceneClass::CastRay(PhysRayCollisionTestClass^ raytest)
	{
		if (raytest == nullptr)
		{
			throw gcnew ArgumentNullException("raytest");
		}

		auto unmanagedRayTest = RenSharpPhysRayCollisionTestClass::CreateRenSharpPhysRayCollisionTestClass(raytest);
		try
		{
			bool result = InternalPhysicsSceneClassPointer->Cast_Ray(
				*reinterpret_cast<::PhysRayCollisionTestClass*>(unmanagedRayTest->UnmanagedObject->PhysRayCollisionTestClassPointer.ToPointer()));

			raytest->CopyFrom(unmanagedRayTest->UnmanagedObject);

			return result;
		}
		finally
		{
#pragma push_macro("delete")
#undef delete

			delete unmanagedRayTest;
			unmanagedRayTest = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool PhysicsSceneClass::CastAABox(IPhysAABoxCollisionTestClass^ boxtest, bool useCollisionRegion)
	{
		if (boxtest == nullptr || boxtest->PhysAABoxCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("boxtest");
		}

		return InternalPhysicsSceneClassPointer->Cast_AABox(
			*reinterpret_cast<::PhysAABoxCollisionTestClass*>(boxtest->PhysAABoxCollisionTestClassPointer.ToPointer()),
			useCollisionRegion);
	}

	bool PhysicsSceneClass::CastAABox(IPhysAABoxCollisionTestClass^ boxtest)
	{
		if (boxtest == nullptr || boxtest->PhysAABoxCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("boxtest");
		}

		return InternalPhysicsSceneClassPointer->Cast_AABox(
			*reinterpret_cast<::PhysAABoxCollisionTestClass*>(boxtest->PhysAABoxCollisionTestClassPointer.ToPointer()));
	}

	bool PhysicsSceneClass::CastAABox(PhysAABoxCollisionTestClass^ boxtest, bool useCollisionRegion)
	{
		if (boxtest == nullptr)
		{
			throw gcnew ArgumentNullException("boxtest");
		}

		auto unmanagedBoxTest = RenSharpPhysAABoxCollisionTestClass::CreateRenSharpPhysAABoxCollisionTestClass(boxtest);
		try
		{
			bool result = InternalPhysicsSceneClassPointer->Cast_AABox(
				*reinterpret_cast<::PhysAABoxCollisionTestClass*>(unmanagedBoxTest->UnmanagedObject->PhysAABoxCollisionTestClassPointer.ToPointer()),
				useCollisionRegion);

			boxtest->CopyFrom(unmanagedBoxTest->UnmanagedObject);

			return result;
		}
		finally
		{
#pragma push_macro("delete")
#undef delete

			delete unmanagedBoxTest;
			unmanagedBoxTest = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool PhysicsSceneClass::CastAABox(PhysAABoxCollisionTestClass^ boxtest)
	{
		if (boxtest == nullptr)
		{
			throw gcnew ArgumentNullException("boxtest");
		}

		auto unmanagedBoxTest = RenSharpPhysAABoxCollisionTestClass::CreateRenSharpPhysAABoxCollisionTestClass(boxtest);
		try
		{
			bool result = InternalPhysicsSceneClassPointer->Cast_AABox(
				*reinterpret_cast<::PhysAABoxCollisionTestClass*>(unmanagedBoxTest->UnmanagedObject->PhysAABoxCollisionTestClassPointer.ToPointer()));

			boxtest->CopyFrom(unmanagedBoxTest->UnmanagedObject);

			return result;
		}
		finally
		{
#pragma push_macro("delete")
#undef delete

			delete unmanagedBoxTest;
			unmanagedBoxTest = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool PhysicsSceneClass::CastOBBox(IPhysOBBoxCollisionTestClass^ boxtest, bool useCollisionRegion)
	{
		if (boxtest == nullptr || boxtest->PhysOBBoxCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("boxtest");
		}

		return InternalPhysicsSceneClassPointer->Cast_OBBox(
			*reinterpret_cast<::PhysOBBoxCollisionTestClass*>(boxtest->PhysOBBoxCollisionTestClassPointer.ToPointer()),
			useCollisionRegion);
	}

	bool PhysicsSceneClass::CastOBBox(IPhysOBBoxCollisionTestClass^ boxtest)
	{
		if (boxtest == nullptr || boxtest->PhysOBBoxCollisionTestClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("boxtest");
		}

		return InternalPhysicsSceneClassPointer->Cast_OBBox(
			*reinterpret_cast<::PhysOBBoxCollisionTestClass*>(boxtest->PhysOBBoxCollisionTestClassPointer.ToPointer()));
	}

	bool PhysicsSceneClass::CastOBBox(PhysOBBoxCollisionTestClass^ boxtest, bool useCollisionRegion)
	{
		if (boxtest == nullptr)
		{
			throw gcnew ArgumentNullException("boxtest");
		}

		auto unmanagedBoxTest = RenSharpPhysOBBoxCollisionTestClass::CreateRenSharpPhysOBBoxCollisionTestClass(boxtest);
		try
		{
			bool result = InternalPhysicsSceneClassPointer->Cast_OBBox(
				*reinterpret_cast<::PhysOBBoxCollisionTestClass*>(unmanagedBoxTest->UnmanagedObject->PhysOBBoxCollisionTestClassPointer.ToPointer()),
				useCollisionRegion);

			boxtest->CopyFrom(unmanagedBoxTest->UnmanagedObject);

			return result;
		}
		finally
		{
#pragma push_macro("delete")
#undef delete

			delete unmanagedBoxTest;
			unmanagedBoxTest = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool PhysicsSceneClass::CastOBBox(PhysOBBoxCollisionTestClass^ boxtest)
	{
		if (boxtest == nullptr)
		{
			throw gcnew ArgumentNullException("boxtest");
		}

		auto unmanagedBoxTest = RenSharpPhysOBBoxCollisionTestClass::CreateRenSharpPhysOBBoxCollisionTestClass(boxtest);
		try
		{
			bool result = InternalPhysicsSceneClassPointer->Cast_OBBox(
				*reinterpret_cast<::PhysOBBoxCollisionTestClass*>(unmanagedBoxTest->UnmanagedObject->PhysOBBoxCollisionTestClassPointer.ToPointer()));

			boxtest->CopyFrom(unmanagedBoxTest->UnmanagedObject);

			return result;
		}
		finally
		{
#pragma push_macro("delete")
#undef delete

			delete unmanagedBoxTest;
			unmanagedBoxTest = nullptr;

#pragma pop_macro("delete")
		}
	}

	IUnmanagedContainer<IMultiListClass<IPhysClass^>^>^ PhysicsSceneClass::CollectObjects(OBBoxClass box, bool staticObjs, bool dynamicObjs)
	{
		::OBBoxClass tmp;

		OBBoxClass::ManagedToUnmanagedOBBoxClass(box, tmp);

		auto result = PhysClassMultiListClass::CreatePhysClassMultiListClass();
		try
		{
			InternalPhysicsSceneClassPointer->Collect_Objects(
				tmp,
				staticObjs,
				dynamicObjs,
				reinterpret_cast<::MultiListClass<::PhysClass>*>(result->UnmanagedObject->Pointer.ToPointer()));

			return result;
		}
		catch (Exception^)
		{
#pragma push_macro("delete")
#undef delete

			delete result;
			result = nullptr;

#pragma pop_macro("delete")

			throw;
		}
	}

	void PhysicsSceneClass::OnVisOccludersRendered(IntPtr context, IntPtr sample)
	{
		if (context.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("context");
		}
		else if (sample.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("sample");
		}

		InternalPhysicsSceneClassPointer->On_Vis_Occluders_Rendered(
			*reinterpret_cast<::VisRenderContextClass*>(context.ToPointer()),
			*reinterpret_cast<::VisSampleClass*>(sample.ToPointer()));
	}

	void PhysicsSceneClass::ResetVis(bool doItNow)
	{
		InternalPhysicsSceneClassPointer->Reset_Vis(doItNow);
	}

	void PhysicsSceneClass::ResetVis()
	{
		InternalPhysicsSceneClassPointer->Reset_Vis();
	}

	void PhysicsSceneClass::GetLevelExtents([Out] Vector3% min, [Out] Vector3% max)
	{
		::Vector3 minVec;
		::Vector3 maxVec;

		InternalPhysicsSceneClassPointer->Get_Level_Extents(minVec, maxVec);

		Vector3::UnmanagedToManagedVector3(minVec, min);
		Vector3::UnmanagedToManagedVector3(maxVec, max);
	}

	IPhysicsSceneClass^ PhysicsSceneClass::Instance::get()
	{
		auto result = ::PhysicsSceneClass::Get_Instance();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PhysicsSceneClass(IntPtr(result));
		}
	}

	IntPtr PhysicsSceneClass::PhysicsSceneClassPointer::get()
	{
		return IntPtr(InternalPhysicsSceneClassPointer);
	}

	IntPtr PhysicsSceneClass::WidgetUserClassPointer::get()
	{
		return IntPtr(InternalWidgetUserClassPointer);
	}

	int PhysicsSceneClass::LightingMode::get()
	{
		return InternalPhysicsSceneClassPointer->Get_Lighting_Mode();
	}

	void PhysicsSceneClass::LightingMode::set(int value)
	{
		InternalPhysicsSceneClassPointer->Set_Lighting_Mode(value);
	}

	bool PhysicsSceneClass::VisResetNeeded::get()
	{
		return InternalPhysicsSceneClassPointer->Is_Vis_Reset_Needed();
	}

	void PhysicsSceneClass::VisResetNeeded::set(bool value)
	{
		InternalPhysicsSceneClassPointer->Vis_Reset_Needed(value);
	}

	bool PhysicsSceneClass::UpdateOnlyVisibleObjects::get()
	{
		return InternalPhysicsSceneClassPointer->Get_Update_Only_Visible_Objects();
	}

	void PhysicsSceneClass::UpdateOnlyVisibleObjects::set(bool value)
	{
		InternalPhysicsSceneClassPointer->Set_Update_Only_Visible_Objects(value);
	}

	bool PhysicsSceneClass::DebugDisplayEnabled::get()
	{
		return InternalPhysicsSceneClassPointer->Is_Debug_Display_Enabled();
	}

	void PhysicsSceneClass::DebugDisplayEnabled::set(bool value)
	{
		InternalPhysicsSceneClassPointer->Enable_Debug_Display(value);
	}

	bool PhysicsSceneClass::ProjectorDebugDisplayEnabled::get()
	{
		return InternalPhysicsSceneClassPointer->Is_Projector_Debug_Display_Enabled();
	}

	void PhysicsSceneClass::ProjectorDebugDisplayEnabled::set(bool value)
	{
		InternalPhysicsSceneClassPointer->Enable_Projector_Debug_Display(value);
	}

	bool PhysicsSceneClass::DirtyCullDebugDisplayEnabled::get()
	{
		return InternalPhysicsSceneClassPointer->Is_Dirty_Cull_Debug_Display_Enabled();
	}

	void PhysicsSceneClass::DirtyCullDebugDisplayEnabled::set(bool value)
	{
		InternalPhysicsSceneClassPointer->Enable_Dirty_Cull_Debug_Display(value);
	}

	bool PhysicsSceneClass::LightingDebugDisplayEnabled::get()
	{
		return InternalPhysicsSceneClassPointer->Is_Lighting_Debug_Display_Enabled();
	}

	void PhysicsSceneClass::LightingDebugDisplayEnabled::set(bool value)
	{
		InternalPhysicsSceneClassPointer->Enable_Lighting_Debug_Display(value);
	}

	Vector3 PhysicsSceneClass::LastCameraPosition::get()
	{
		Vector3 result;

		Vector3::UnmanagedToManagedVector3(InternalPhysicsSceneClassPointer->Get_Last_Camera_Position(), result);

		return result;
	}

	void PhysicsSceneClass::LastCameraPosition::set(Vector3 value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& lastCameraPosition = helper->GetLastCameraPosition();

		Vector3::ManagedToUnmanagedVector3(value, lastCameraPosition);
	}

	unsigned int PhysicsSceneClass::CurrentFrameNumber::get()
	{
		return InternalPhysicsSceneClassPointer->CurrentFrameNumber;
	}

	void PhysicsSceneClass::CurrentFrameNumber::set(unsigned int value)
	{
		InternalPhysicsSceneClassPointer->CurrentFrameNumber = value;
	}

	void PhysicsSceneClass::InternalVisReset()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		helper->InternalVisReset();
	}

	::SceneClass* PhysicsSceneClass::InternalSceneClassPointer::get()
	{
		return InternalPhysicsSceneClassPointer;
	}

	::WidgetUserClass* PhysicsSceneClass::InternalWidgetUserClassPointer::get()
	{
		return InternalPhysicsSceneClassPointer;
	}

	::PhysicsSceneClass* PhysicsSceneClass::InternalPhysicsSceneClassPointer::get()
	{
		return InternalPhysicsSceneClassPointer;
	}

	IRefMultiListClass<IPhysClass^>^ PhysicsSceneClass::VisibleStaticObjectList::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& visibileStaticObjectList = helper->GetVisibleStaticObjectList();

		return gcnew PhysClassRefMultiListClass(IntPtr(&visibileStaticObjectList));
	}

	IRefMultiListClass<IPhysClass^>^ PhysicsSceneClass::VisibleWSMeshList::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& visibleWSMeshList = helper->GetVisibleWSMeshList();

		return gcnew PhysClassRefMultiListClass(IntPtr(&visibleWSMeshList));
	}

	IRefMultiListClass<IPhysClass^>^ PhysicsSceneClass::VisibleDynamicObjectList::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& visibleDynamicObjectList = helper->GetVisibleDynamicObjectList();

		return gcnew PhysClassRefMultiListClass(IntPtr(&visibleDynamicObjectList));
	}

	IMultiListClass<IntPtr>^ PhysicsSceneClass::ActiveTextureProjectors::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& activeTextureProjectors = helper->GetActiveTextureProjectors();

		return gcnew TexProjectClassMultiListClass(IntPtr(&activeTextureProjectors));
	}

	int PhysicsSceneClass::FrameNum::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& frameNum = helper->GetFrameNum();

		return frameNum;
	}

	void PhysicsSceneClass::FrameNum::set(int value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& frameNum = helper->GetFrameNum();

		frameNum = value;
	}

	int PhysicsSceneClass::LastValidVisId::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& lastValidVisId = helper->GetLastValidVisId();

		return lastValidVisId;
	}

	void PhysicsSceneClass::LastValidVisId::set(int value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& lastValidVisId = helper->GetLastValidVisId();

		lastValidVisId = value;
	}

	PhysicsSceneClass::IStatsStruct^ PhysicsSceneClass::LastValidStats::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& lastValidStats = helper->GetLastValidStats();

		return gcnew StatsStruct(IntPtr(&lastValidStats));
	}

	void PhysicsSceneClass::LastValidStats::set(PhysicsSceneClass::IStatsStruct^ value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& lastValidStats = helper->GetLastValidStats();

		lastValidStats = *reinterpret_cast<::PhysicsSceneClass::StatsStruct*>(value->StatsStructPointer.ToPointer());
	}

	PhysicsSceneClass::IStatsStruct^ PhysicsSceneClass::CurrentStats::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& currentStats = helper->GetCurrentStats();

		return gcnew StatsStruct(IntPtr(&currentStats));
	}

	void PhysicsSceneClass::CurrentStats::set(PhysicsSceneClass::IStatsStruct^ value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& currentStats = helper->GetCurrentStats();

		currentStats = *reinterpret_cast<::PhysicsSceneClass::StatsStruct*>(value->StatsStructPointer.ToPointer());
	}

	bool PhysicsSceneClass::StaticProjectorsDirty::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& staticProjectorsDirty = helper->GetStaticProjectorsDirty();

		return staticProjectorsDirty;
	}

	void PhysicsSceneClass::StaticProjectorsDirty::set(bool value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& staticProjectorsDirty = helper->GetStaticProjectorsDirty();

		staticProjectorsDirty = value;
	}

	bool PhysicsSceneClass::VisEnabled::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& visEnabled = helper->GetVisEnabled();

		return visEnabled;
	}

	void PhysicsSceneClass::VisEnabled::set(bool value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& visEnabled = helper->GetVisEnabled();

		visEnabled = value;
	}

	bool PhysicsSceneClass::VisInverted::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& visInverted = helper->GetVisInverted();

		return visInverted;
	}

	void PhysicsSceneClass::VisInverted::set(bool value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& visInverted = helper->GetVisInverted();

		visInverted = value;
	}

	bool PhysicsSceneClass::VisQuickAndDirty::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& visQuickAndDirty = helper->GetVisQuickAndDirty();

		return visQuickAndDirty;
	}

	void PhysicsSceneClass::VisQuickAndDirty::set(bool value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& visQuickAndDirty = helper->GetVisQuickAndDirty();

		visQuickAndDirty = value;
	}

	bool PhysicsSceneClass::VisSectorDisplayEnabled::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& visSectorDisplayEnabled = helper->GetVisSectorDisplayEnabled();

		return visSectorDisplayEnabled;
	}

	void PhysicsSceneClass::VisSectorDisplayEnabled::set(bool value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& visSectorDisplayEnabled = helper->GetVisSectorDisplayEnabled();

		visSectorDisplayEnabled = value;
	}

	bool PhysicsSceneClass::VisSectorHistoryEnabled::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& visSectorHistoryEnabled = helper->GetVisSectorHistoryEnabled();

		return visSectorHistoryEnabled;
	}

	void PhysicsSceneClass::VisSectorHistoryEnabled::set(bool value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& visSectorHistoryEnabled = helper->GetVisSectorHistoryEnabled();

		visSectorHistoryEnabled = value;
	}

	int PhysicsSceneClass::VisGridDisplayMode::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& visGridDisplayMode = helper->GetVisGridDisplayMode();

		return visGridDisplayMode;
	}

	void PhysicsSceneClass::VisGridDisplayMode::set(int value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& visGridDisplayMode = helper->GetVisGridDisplayMode();

		visGridDisplayMode = value;
	}

	bool PhysicsSceneClass::VisSectorMissing::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& visSectorMissing = helper->GetVisSectorMissing();

		return visSectorMissing;
	}

	void PhysicsSceneClass::VisSectorMissing::set(bool value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& visSectorMissing = helper->GetVisSectorMissing();

		visSectorMissing = value;
	}

	bool PhysicsSceneClass::VisSectorFallbackEnabled::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& visSectorFallbackEnabled = helper->GetVisSectorFallbackEnabled();

		return visSectorFallbackEnabled;
	}

	void PhysicsSceneClass::VisSectorFallbackEnabled::set(bool value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& visSectorFallbackEnabled = helper->GetVisSectorFallbackEnabled();

		visSectorFallbackEnabled = value;
	}

	bool PhysicsSceneClass::BackfaceDebugEnabled::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& backfaceDebugEnabled = helper->GetBackfaceDebugEnabled();

		return backfaceDebugEnabled;
	}

	void PhysicsSceneClass::BackfaceDebugEnabled::set(bool value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& backfaceDebugEnabled = helper->GetBackfaceDebugEnabled();

		backfaceDebugEnabled = value;
	}

	bool PhysicsSceneClass::VisSamplePointLocked::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& visSamplePointLocked = helper->GetVisSamplePointLocked();

		return visSamplePointLocked;
	}

	void PhysicsSceneClass::VisSamplePointLocked::set(bool value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& visSamplePointLocked = helper->GetVisSamplePointLocked();

		visSamplePointLocked = value;
	}

	Vector3 PhysicsSceneClass::LockedVisSamplePoint::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& lockedVisSamplePoint = helper->GetLockedVisSamplePoint();

		Vector3 result;

		Vector3::UnmanagedToManagedVector3(lockedVisSamplePoint, result);

		return result;
	}

	void PhysicsSceneClass::LockedVisSamplePoint::set(Vector3 value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& lockedVisSamplePoint = helper->GetLockedVisSamplePoint();

		Vector3::ManagedToUnmanagedVector3(value, lockedVisSamplePoint);
	}

	IntPtr PhysicsSceneClass::VisCamera::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& visCamera = helper->GetVisCamera();

		return IntPtr(visCamera);
	}

	void PhysicsSceneClass::VisCamera::set(IntPtr value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& visCamera = helper->GetVisCamera();

		visCamera = reinterpret_cast<::CameraClass*>(value.ToPointer());
	}

	IVisTableClass^ PhysicsSceneClass::CurrentVisTable::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& currentVisTable = helper->GetCurrentVisTable();

		if (currentVisTable == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew VisTableClass(IntPtr(currentVisTable));
		}
	}

	void PhysicsSceneClass::CurrentVisTable::set(IVisTableClass^ value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& currentVisTable = helper->GetCurrentVisTable();

		if (value == nullptr || value->VisTableClassPointer.ToPointer() == nullptr)
		{
			currentVisTable = nullptr;
		}
		else
		{
			currentVisTable = reinterpret_cast<::VisTableClass*>(value->VisTableClassPointer.ToPointer());
		}
	}
	
	bool PhysicsSceneClass::StaticProjectorsEnabled::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& staticProjectorsEnabled = helper->GetStaticProjectorsEnabled();

		return staticProjectorsEnabled;
	}

	void PhysicsSceneClass::StaticProjectorsEnabled::set(bool value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& staticProjectorsEnabled = helper->GetStaticProjectorsEnabled();

		staticProjectorsEnabled = value;
	}

	bool PhysicsSceneClass::DynamicProjectorsEnabled::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& dynamicProjectorsEnabled = helper->GetDynamicProjectorsEnabled();

		return dynamicProjectorsEnabled;
	}

	void PhysicsSceneClass::DynamicProjectorsEnabled::set(bool value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& dynamicProjectorsEnabled = helper->GetDynamicProjectorsEnabled();

		dynamicProjectorsEnabled = value;
	}

	IPhysicsSceneClass::ShadowEnum PhysicsSceneClass::ShadowMode::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& shadowMode = helper->GetShadowMode();

		return static_cast<IPhysicsSceneClass::ShadowEnum>(shadowMode);
	}

	void PhysicsSceneClass::ShadowMode::set(IPhysicsSceneClass::ShadowEnum value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& shadowMode = helper->GetShadowMode();

		shadowMode = static_cast<::PhysicsSceneClass::ShadowEnum>(value);
	}

	float PhysicsSceneClass::ShadowAttenStart::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& shadowAttenStart = helper->GetShadowAttenStart();

		return shadowAttenStart;
	}

	void PhysicsSceneClass::ShadowAttenStart::set(float value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& shadowAttenStart = helper->GetShadowAttenStart();

		shadowAttenStart = value;
	}

	float PhysicsSceneClass::ShadowAttenEnd::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& shadowAttenEnd = helper->GetShadowAttenEnd();

		return shadowAttenEnd;
	}

	void PhysicsSceneClass::ShadowAttenEnd::set(float value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& shadowAttenEnd = helper->GetShadowAttenEnd();

		shadowAttenEnd = value;
	}

	float PhysicsSceneClass::ShadowNormalIntensity::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& shadowNormalIntensity = helper->GetShadowNormalIntensity();

		return shadowNormalIntensity;
	}

	void PhysicsSceneClass::ShadowNormalIntensity::set(float value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& shadowNormalIntensity = helper->GetShadowNormalIntensity();

		shadowNormalIntensity = value;
	}

	IntPtr PhysicsSceneClass::ShadowBlobTexture::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& shadowBlobTexture = helper->GetShadowBlobTexture();

		return IntPtr(shadowBlobTexture);
	}

	void PhysicsSceneClass::ShadowBlobTexture::set(IntPtr value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& shadowBlobTexture = helper->GetShadowBlobTexture();

		shadowBlobTexture = reinterpret_cast<::TextureClass*>(value.ToPointer());
	}

	IntPtr PhysicsSceneClass::ShadowRenderContext::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& shadowRenderContext = helper->GetShadowRenderContext();

		return IntPtr(shadowRenderContext);
	}

	void PhysicsSceneClass::ShadowRenderContext::set(IntPtr value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& shadowRenderContext = helper->GetShadowRenderContext();

		shadowRenderContext = reinterpret_cast<::SpecialRenderInfoClass*>(value.ToPointer());
	}

	IntPtr PhysicsSceneClass::ShadowCamera::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& shadowCamera = helper->GetShadowCamera();

		return IntPtr(shadowCamera);
	}

	void PhysicsSceneClass::ShadowCamera::set(IntPtr value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& shadowCamera = helper->GetShadowCamera();

		shadowCamera = reinterpret_cast<::CameraClass*>(value.ToPointer());
	}

	IntPtr PhysicsSceneClass::ShadowMaterialPass::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& shadowMaterialPass = helper->GetShadowMaterialPass();

		return IntPtr(shadowMaterialPass);
	}

	void PhysicsSceneClass::ShadowMaterialPass::set(IntPtr value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& shadowMaterialPass = helper->GetShadowMaterialPass();

		shadowMaterialPass = reinterpret_cast<::MaterialPassClass*>(value.ToPointer());
	}

	int PhysicsSceneClass::ShadowResWidth::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& shadowResWidth = helper->GetShadowResWidth();

		return shadowResWidth;
	}

	void PhysicsSceneClass::ShadowResWidth::set(int value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& shadowResWidth = helper->GetShadowResWidth();

		shadowResWidth = value;
	}

	int PhysicsSceneClass::ShadowResHeight::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& shadowResHeight = helper->GetShadowResHeight();

		return shadowResHeight;
	}

	void PhysicsSceneClass::ShadowResHeight::set(int value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& shadowResHeight = helper->GetShadowResHeight();

		shadowResHeight = value;
	}

	IntPtr PhysicsSceneClass::DecalSystem::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& decalSystem = helper->GetDecalSystem();

		return IntPtr(decalSystem);
	}

	void PhysicsSceneClass::DecalSystem::set(IntPtr value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& decalSystem = helper->GetDecalSystem();

		decalSystem = reinterpret_cast<::PhysDecalSysClass*>(value.ToPointer());
	}

	IntPtr PhysicsSceneClass::Pathfinder::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& pathfinder = helper->GetPathfinder();

		return IntPtr(pathfinder);
	}

	void PhysicsSceneClass::Pathfinder::set(IntPtr value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& pathfinder = helper->GetPathfinder();

		pathfinder = reinterpret_cast<::PathfindClass*>(value.ToPointer());
	}

	IntPtr PhysicsSceneClass::CameraShakeSystem::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& cameraShakeSystem = helper->GetCameraShakeSystem();

		return IntPtr(cameraShakeSystem);
	}

	void PhysicsSceneClass::CameraShakeSystem::set(IntPtr value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& cameraShakeSystem = helper->GetCameraShakeSystem();

		cameraShakeSystem = reinterpret_cast<::CameraShakeSystemClass*>(value.ToPointer());
	}

	IRefMultiListClass<IRenderObjClass^>^ PhysicsSceneClass::UpdateList::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& updateList = helper->GetUpdateList();

		return gcnew RenderObjClassRefMultiListClass(IntPtr(&updateList));
	}

	IRefMultiListClass<IRenderObjClass^>^ PhysicsSceneClass::VertexProcList::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& vertexProcList = helper->GetVertexProcList();

		return gcnew RenderObjClassRefMultiListClass(IntPtr(&vertexProcList));
	}

	IRefMultiListClass<IPhysClass^>^ PhysicsSceneClass::ReleaseList::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& releaseList = helper->GetReleaseList();

		return gcnew PhysClassRefMultiListClass(IntPtr(&releaseList));
	}

	IntPtr PhysicsSceneClass::HighlightMaterialPass::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& highlightMaterialPass = helper->GetHighlightMaterialPass();

		return IntPtr(highlightMaterialPass);
	}

	void PhysicsSceneClass::HighlightMaterialPass::set(IntPtr value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& highlightMaterialPass = helper->GetHighlightMaterialPass();

		highlightMaterialPass = reinterpret_cast<::MaterialPassClass*>(value.ToPointer());
	}

	IntPtr PhysicsSceneClass::StaticCullingSystem::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& staticCullingSystem = helper->GetStaticCullingSystem();

		return IntPtr(staticCullingSystem);
	}

	void PhysicsSceneClass::StaticCullingSystem::set(IntPtr value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& staticCullingSystem = helper->GetStaticCullingSystem();

		staticCullingSystem = reinterpret_cast<::StaticAABTreeCullClass*>(value.ToPointer());
	}

	IntPtr PhysicsSceneClass::StaticLightingSystem::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& staticLightingSystem = helper->GetStaticLightingSystem();

		return IntPtr(staticLightingSystem);
	}

	void PhysicsSceneClass::StaticLightingSystem::set(IntPtr value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& staticLightingSystem = helper->GetStaticLightingSystem();

		staticLightingSystem = reinterpret_cast<::StaticLightCullClass*>(value.ToPointer());
	}

	IntPtr PhysicsSceneClass::DynamicCullingSystem::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& dynamicCullingSystem = helper->GetDynamicCullingSystem();

		return IntPtr(dynamicCullingSystem);
	}

	void PhysicsSceneClass::DynamicCullingSystem::set(IntPtr value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& dynamicCullingSystem = helper->GetDynamicCullingSystem();

		dynamicCullingSystem = reinterpret_cast<::PhysGridCullClass*>(value.ToPointer());
	}

	IntPtr PhysicsSceneClass::DynamicObjVisSystem::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& dynamicObjVisSystem = helper->GetDynamicObjVisSystem();

		return IntPtr(dynamicObjVisSystem);
	}

	void PhysicsSceneClass::DynamicObjVisSystem::set(IntPtr value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& dynamicObjVisSystem = helper->GetDynamicObjVisSystem();

		dynamicObjVisSystem = reinterpret_cast<::DynamicAABTreeCullClass*>(value.ToPointer());
	}

	ITypedAABTreeCullSystemClass<IntPtr>^ PhysicsSceneClass::StaticProjectorCullingSystem::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& staticProjectorCullingSystem = helper->GetStaticProjectorCullingSystem();

		if (staticProjectorCullingSystem == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew TexProjectClassTypedAABTreeCullSystemClass(IntPtr(staticProjectorCullingSystem));
		}
	}

	void PhysicsSceneClass::StaticProjectorCullingSystem::set(ITypedAABTreeCullSystemClass<IntPtr>^ value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& staticProjectorCullingSystem = helper->GetStaticProjectorCullingSystem();

		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			staticProjectorCullingSystem = nullptr;
		}
		else
		{
			staticProjectorCullingSystem = reinterpret_cast<::TypedAABTreeCullSystemClass<::TexProjectClass>*>(value->Pointer.ToPointer());
		}
	}

	ITypedGridCullSystemClass<IntPtr>^ PhysicsSceneClass::DynamicProjectorCullingSystem::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& dynamicProjectorCullingSystem = helper->GetDynamicProjectorCullingSystem();

		if (dynamicProjectorCullingSystem == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew TexProjectClassTypedGridCullSystemClass(IntPtr(dynamicProjectorCullingSystem));
		}
	}

	void PhysicsSceneClass::DynamicProjectorCullingSystem::set(ITypedGridCullSystemClass<IntPtr>^ value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& dynamicProjectorCullingSystem = helper->GetDynamicProjectorCullingSystem();

		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			dynamicProjectorCullingSystem = nullptr;
		}
		else
		{
			dynamicProjectorCullingSystem = reinterpret_cast<::TypedGridCullSystemClass<::TexProjectClass>*>(value->Pointer.ToPointer());
		}
	}

	IVisTableMgrClass^ PhysicsSceneClass::VisTableManager::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& visTableManager = helper->GetVisTableManager();

		return gcnew VisTableMgrClass(IntPtr(&visTableManager));
	}

	void PhysicsSceneClass::VisTableManager::set(IVisTableMgrClass^ value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& visTableManager = helper->GetVisTableManager();

		visTableManager = *reinterpret_cast<::VisTableMgrClass*>(value->VisTableMgrClassPointer.ToPointer());
	}

	Vector3 PhysicsSceneClass::SceneAmbientLight::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& sceneAmbientLight = helper->GetSceneAmbientLight();

		Vector3 result;

		Vector3::UnmanagedToManagedVector3(sceneAmbientLight, result);

		return result;
	}

	void PhysicsSceneClass::SceneAmbientLight::set(Vector3 value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& sceneAmbientLight = helper->GetSceneAmbientLight();

		Vector3::ManagedToUnmanagedVector3(value, sceneAmbientLight);
	}

	bool PhysicsSceneClass::UseSun::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& useSun = helper->GetUseSun();

		return useSun;
	}

	void PhysicsSceneClass::UseSun::set(bool value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& useSun = helper->GetUseSun();

		useSun = value;
	}

	float PhysicsSceneClass::SunPitch::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& sunPitch = helper->GetSunPitch();

		return sunPitch;
	}

	void PhysicsSceneClass::SunPitch::set(float value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& sunPitch = helper->GetSunPitch();

		sunPitch = value;
	}

	float PhysicsSceneClass::SunYaw::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& sunYaw = helper->GetSunYaw();

		return sunYaw;
	}

	void PhysicsSceneClass::SunYaw::set(float value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& sunYaw = helper->GetSunYaw();

		sunYaw = value;
	}

	IntPtr PhysicsSceneClass::SunLight::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& sunLight = helper->GetSunLight();

		return IntPtr(sunLight);
	}

	void PhysicsSceneClass::SunLight::set(IntPtr value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& sunLight = helper->GetSunLight();

		sunLight = reinterpret_cast<::LightClass*>(value.ToPointer());
	}

	int PhysicsSceneClass::DynamicPolyBudget::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& dynamicPolyBudget = helper->GetDynamicPolyBudget();

		return dynamicPolyBudget;
	}

	void PhysicsSceneClass::DynamicPolyBudget::set(int value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& dynamicPolyBudget = helper->GetDynamicPolyBudget();

		dynamicPolyBudget = value;
	}

	int PhysicsSceneClass::StaticPolyBudget::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& staticPolyBudget = helper->GetStaticPolyBudget();

		return staticPolyBudget;
	}

	void PhysicsSceneClass::StaticPolyBudget::set(int value)
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& staticPolyBudget = helper->GetStaticPolyBudget();

		staticPolyBudget = value;
	}

	IRefMultiListClass<IPhysClass^>^ PhysicsSceneClass::ObjList::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& objList = helper->GetObjList();

		return gcnew PhysClassRefMultiListClass(IntPtr(&objList));
	}

	IRefMultiListClass<IPhysClass^>^ PhysicsSceneClass::StaticObjList::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& staticObjList = helper->GetStaticObjList();

		return gcnew PhysClassRefMultiListClass(IntPtr(&staticObjList));
	}

	IRefMultiListClass<IPhysClass^>^ PhysicsSceneClass::StaticLightList::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& staticLightList = helper->GetStaticLightList();

		return gcnew PhysClassRefMultiListClass(IntPtr(&staticLightList));
	}

	IMultiListClass<IntPtr>^ PhysicsSceneClass::StaticProjectorList::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& staticProjectorList = helper->GetStaticProjectorList();

		return gcnew TexProjectClassMultiListClass(IntPtr(&staticProjectorList));
	}

	IMultiListClass<IntPtr>^ PhysicsSceneClass::DynamicProjectorList::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& dynamicProjectorList = helper->GetDynamicProjectorList();

		return gcnew TexProjectClassMultiListClass(IntPtr(&dynamicProjectorList));
	}

	IRefMultiListClass<IPhysClass^>^ PhysicsSceneClass::DirtyCullList::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& dirtyCullList = helper->GetDirtyCullList();

		return gcnew PhysClassRefMultiListClass(IntPtr(&dirtyCullList));
	}

	IRefMultiListClass<IPhysClass^>^ PhysicsSceneClass::TimestepList::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& timestepList = helper->GetTimestepList();

		return gcnew PhysClassRefMultiListClass(IntPtr(&timestepList));
	}

	IRefMultiListClass<IPhysClass^>^ PhysicsSceneClass::StaticAnimList::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& staticAnimList = helper->GetStaticAnimList();

		return gcnew PhysClassRefMultiListClass(IntPtr(&staticAnimList));
	}

	IMultiListClass<IPhysClass^>^ PhysicsSceneClass::CollisionRegionList::get()
	{
		auto helper = reinterpret_cast<PhysicsSceneClassHelper*>(InternalPhysicsSceneClassPointer);

		auto& collisionRegionList = helper->GetCollisionRegionList();

		return gcnew PhysClassMultiListClass(IntPtr(&collisionRegionList));
	}
}