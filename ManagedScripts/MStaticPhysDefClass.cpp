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
#include "MStaticPhysDefClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <StaticPhysDefClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{

#pragma managed(push, off)

	class StaticPhysDefClassHelper : public ::StaticPhysDefClass
	{
		private:
			StaticPhysDefClassHelper() = default;

		public:
			bool &GetIsNonOccluder()
			{
				return IsNonOccluder;
			}

			char &GetCollisionGroup()
			{
				return CollisionGroup;
			}

			char &GetVisibilityMode()
			{
				return VisibilityMode;
			}
	};

#pragma managed(pop)

	StaticPhysDefClass::StaticPhysDefClass(IntPtr pointer)
		: PhysDefClass(pointer)
	{

	}

	IntPtr StaticPhysDefClass::StaticPhysDefClassPointer::get()
	{
		return IntPtr(InternalStaticPhysDefClassPointer);
	}

	::PhysDefClass *StaticPhysDefClass::InternalPhysDefClassPointer::get()
	{
		return InternalStaticPhysDefClassPointer;
	}

	::StaticPhysDefClass *StaticPhysDefClass::InternalStaticPhysDefClassPointer::get()
	{
		return reinterpret_cast<::StaticPhysDefClass *>(Pointer.ToPointer());
	}

	bool StaticPhysDefClass::IsNonOccluder::get()
	{
		auto helper = reinterpret_cast<StaticPhysDefClassHelper *>(InternalStaticPhysDefClassPointer);

		auto &isNonOccluder = helper->GetIsNonOccluder();

		return isNonOccluder;
	}

	void StaticPhysDefClass::IsNonOccluder::set(bool value)
	{
		auto helper = reinterpret_cast<StaticPhysDefClassHelper *>(InternalStaticPhysDefClassPointer);

		auto &isNonOccluder = helper->GetIsNonOccluder();

		isNonOccluder = value;
	}

	char StaticPhysDefClass::CollisionGroup::get()
	{
		auto helper = reinterpret_cast<StaticPhysDefClassHelper *>(InternalStaticPhysDefClassPointer);

		auto &collisionGroup = helper->GetCollisionGroup();

		return collisionGroup;
	}

	void StaticPhysDefClass::CollisionGroup::set(char value)
	{
		auto helper = reinterpret_cast<StaticPhysDefClassHelper *>(InternalStaticPhysDefClassPointer);

		auto &collisionGroup = helper->GetCollisionGroup();

		collisionGroup = value;
	}

	char StaticPhysDefClass::VisibilityMode::get()
	{
		auto helper = reinterpret_cast<StaticPhysDefClassHelper *>(InternalStaticPhysDefClassPointer);

		auto &visibilityMode = helper->GetVisibilityMode();

		return visibilityMode;
	}

	void StaticPhysDefClass::VisibilityMode::set(char value)
	{
		auto helper = reinterpret_cast<StaticPhysDefClassHelper *>(InternalStaticPhysDefClassPointer);

		auto &visibilityMode = helper->GetVisibilityMode();

		visibilityMode = value;
	}
}