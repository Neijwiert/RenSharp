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
#include "MStaticPhysClass.h"

#include "MStaticPhysDefClass.h"
#include "MRenderObjClass.h"
#include "Mobboxclass.h"
#include "MAABoxClass.h"
#include "MChunkClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <StaticPhysClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{

#pragma managed(push, off)

	class StaticPhysClassHelper : public ::StaticPhysClass
	{
		private:
			StaticPhysClassHelper() = default;

		public:
			int &GetVisSectorID()
			{
				return VisSectorID;
			}
	};

#pragma managed(pop)

	StaticPhysClass::StaticPhysClass(IntPtr pointer)
		: PhysClass(pointer)
	{

	}

	IStaticPhysClass ^StaticPhysClass::AsStaticPhysClass()
	{
		return this;
	}

	bool StaticPhysClass::Intersects(OBBoxClass box)
	{
		::OBBoxClass boxBox;

		OBBoxClass::ManagedToUnmanagedOBBoxClass(box, boxBox);

		return InternalStaticPhysClassPointer->Intersects(boxBox);
	}

	void StaticPhysClass::SaveState(IChunkSaveClass ^cSave)
	{
		if (cSave == nullptr || cSave->ChunkSaveClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("cSave");
		}

		InternalStaticPhysClassPointer->Save_State(*reinterpret_cast<::ChunkSaveClass *>(cSave->ChunkSaveClassPointer.ToPointer()));
	}

	void StaticPhysClass::LoadState(IChunkLoadClass ^cLoad)
	{
		if (cLoad == nullptr || cLoad->ChunkLoadClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("cLoad");
		}

		InternalStaticPhysClassPointer->Load_State(*reinterpret_cast<::ChunkLoadClass *>(cLoad->ChunkLoadClassPointer.ToPointer()));
	}

	IntPtr StaticPhysClass::StaticPhysClassPointer::get()
	{
		return IntPtr(InternalStaticPhysClassPointer);
	}

	IStaticPhysDefClass ^StaticPhysClass::StaticPhysDef::get()
	{
		return gcnew StaticPhysDefClass(IntPtr(InternalStaticPhysClassPointer->Get_StaticPhysDef()));
	}

	AABoxClass StaticPhysClass::BoundingBox::get()
	{
		AABoxClass result;

		AABoxClass::UnmanagedToManagedAABoxClass(InternalStaticPhysClassPointer->Get_Bounding_Box(), result);

		return result;
	}

	int StaticPhysClass::VisSectorID::get()
	{
		return InternalStaticPhysClassPointer->Get_Vis_Sector_ID();
	}

	void StaticPhysClass::VisSectorID::set(int value)
	{
		auto helper = reinterpret_cast<StaticPhysClassHelper *>(InternalStaticPhysClassPointer);

		auto &visSectorID = helper->GetVisSectorID();

		visSectorID = value;
	}

	bool StaticPhysClass::HasDynamicState::get()
	{
		return InternalStaticPhysClassPointer->Has_Dynamic_State();
	}

	::PostLoadableClass *StaticPhysClass::InternalPostLoadableClassPointer::get()
	{
		return InternalStaticPhysClassPointer;
	}

	::PersistClass *StaticPhysClass::InternalPersistClassPointer::get()
	{
		return InternalStaticPhysClassPointer;
	}

	::MultiListObjectClass *StaticPhysClass::InternalMultiListObjectClassPointer::get()
	{
		return InternalStaticPhysClassPointer;
	}

	::PhysClass *StaticPhysClass::InternalPhysClassPointer::get()
	{
		return InternalStaticPhysClassPointer;
	}

	::StaticPhysClass *StaticPhysClass::InternalStaticPhysClassPointer::get()
	{
		return reinterpret_cast<::StaticPhysClass *>(Pointer.ToPointer());
	}
}