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
#include "MDynamicPhysClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <DynamicPhysClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
#pragma managed(push, off)

	class DynamicPhysClassHelper : public ::DynamicPhysClass
	{
		private:
			DynamicPhysClassHelper() = default;

		public:
			bool &GetDirtyVisObjectID()
			{
				return DirtyVisObjectID;
			}

			int &GetVisNodeID()
			{
				return VisNodeID;
			}

			unsigned int &GetVisStatusLastUpdated()
			{
				return VisStatusLastUpdated;
			}
	};

#pragma managed(pop)

	DynamicPhysClass::DynamicPhysClass(IntPtr pointer)
		: PhysClass(pointer)
	{

	}

	IDynamicPhysClass ^DynamicPhysClass::AsDynamicPhysClass()
	{
		return this;
	}

	IntPtr DynamicPhysClass::DynamicPhysClassPointer::get()
	{
		return IntPtr(InternalDynamicPhysClassPointer);
	}

	::PostLoadableClass *DynamicPhysClass::InternalPostLoadableClassPointer::get()
	{
		return InternalDynamicPhysClassPointer;
	}

	::PersistClass *DynamicPhysClass::InternalPersistClassPointer::get()
	{
		return InternalDynamicPhysClassPointer;
	}

	::MultiListObjectClass *DynamicPhysClass::InternalMultiListObjectClassPointer::get()
	{
		return InternalDynamicPhysClassPointer;
	}

	::PhysClass *DynamicPhysClass::InternalPhysClassPointer::get()
	{
		return InternalDynamicPhysClassPointer;
	}

	::DynamicPhysClass *DynamicPhysClass::InternalDynamicPhysClassPointer::get()
	{
		return reinterpret_cast<::DynamicPhysClass *>(Pointer.ToPointer());
	}

	bool DynamicPhysClass::DirtyVisObjectID::get()
	{
		auto helper = reinterpret_cast<DynamicPhysClassHelper *>(InternalDynamicPhysClassPointer);

		auto &dirtyVisObjectID = helper->GetDirtyVisObjectID();

		return dirtyVisObjectID;
	}

	void DynamicPhysClass::DirtyVisObjectID::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicPhysClassHelper *>(InternalDynamicPhysClassPointer);

		auto &dirtyVisObjectID = helper->GetDirtyVisObjectID();

		dirtyVisObjectID = value;
	}

	int DynamicPhysClass::VisNodeID::get()
	{
		auto helper = reinterpret_cast<DynamicPhysClassHelper *>(InternalDynamicPhysClassPointer);

		auto &visNodeID = helper->GetVisNodeID();

		return visNodeID;
	}

	void DynamicPhysClass::VisNodeID::set(int value)
	{
		auto helper = reinterpret_cast<DynamicPhysClassHelper *>(InternalDynamicPhysClassPointer);

		auto &visNodeID = helper->GetVisNodeID();

		visNodeID = value;
	}

	unsigned int DynamicPhysClass::VisStatusLastUpdated::get()
	{
		auto helper = reinterpret_cast<DynamicPhysClassHelper *>(InternalDynamicPhysClassPointer);

		auto &visStatusLastUpdated = helper->GetVisStatusLastUpdated();

		return visStatusLastUpdated;
	}

	void DynamicPhysClass::VisStatusLastUpdated::set(unsigned int value)
	{
		auto helper = reinterpret_cast<DynamicPhysClassHelper *>(InternalDynamicPhysClassPointer);

		auto &visStatusLastUpdated = helper->GetVisStatusLastUpdated();

		visStatusLastUpdated = value;
	}
}