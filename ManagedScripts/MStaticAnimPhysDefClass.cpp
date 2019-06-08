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
#include "MStaticAnimPhysDefClass.h"

#include "MAnimCollisionManagerClass.h"
#include "MProjectorManagerClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <StaticAnimPhysDefClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{

#pragma managed(push, off)

	class StaticAnimPhysDefClassHelper : public ::StaticAnimPhysDefClass
	{
		private:
			StaticAnimPhysDefClassHelper() = default;

		public:
			bool &GetIsCosmetic()
			{
				return IsCosmetic;
			}

			::AnimCollisionManagerDefClass &GetAnimManagerDef()
			{
				return AnimManagerDef;
			}

			::ProjectorManagerDefClass &GetProjectorManagerDef()
			{
				return ProjectorManagerDef;
			}

			bool &GetShadowDynamicObjs()
			{
				return ShadowDynamicObjs;
			}

			bool &GetShadowIsAdditive()
			{
				return ShadowIsAdditive;
			}

			bool &GetShadowIgnoresZRotation()
			{
				return ShadowIgnoresZRotation;
			}

			float &GetShadowNearZ()
			{
				return ShadowNearZ;
			}

			float &GetShadowFarZ()
			{
				return ShadowFarZ;
			}

			float &GetShadowIntensity()
			{
				return ShadowIntensity;
			}

			bool &GetDoesCollideInPathfind()
			{
				return DoesCollideInPathfind;
			}
	};

#pragma managed(pop)

	StaticAnimPhysDefClass::StaticAnimPhysDefClass(IntPtr pointer)
		: StaticPhysDefClass(pointer)
	{

	}

	IntPtr StaticAnimPhysDefClass::StaticAnimPhysDefClassPointer::get()
	{
		return IntPtr(InternalStaticAnimPhysDefClassPointer);
	}

	bool StaticAnimPhysDefClass::ShadowDynamicObjs::get()
	{
		return InternalStaticAnimPhysDefClassPointer->Shadow_Dynamic_Objs();
	}

	void StaticAnimPhysDefClass::ShadowDynamicObjs::set(bool value)
	{
		auto helper = reinterpret_cast<StaticAnimPhysDefClassHelper *>(InternalStaticAnimPhysDefClassPointer);

		auto &shadowDynamicObjs = helper->GetShadowDynamicObjs();

		shadowDynamicObjs = value;
	}

	bool StaticAnimPhysDefClass::ShadowIsAdditive::get()
	{
		return InternalStaticAnimPhysDefClassPointer->Shadow_Is_Additive();
	}

	void StaticAnimPhysDefClass::ShadowIsAdditive::set(bool value)
	{
		auto helper = reinterpret_cast<StaticAnimPhysDefClassHelper *>(InternalStaticAnimPhysDefClassPointer);

		auto &shadowIsAdditive = helper->GetShadowIsAdditive();

		shadowIsAdditive = value;
	}

	bool StaticAnimPhysDefClass::ShadowIgnoresZRotation::get()
	{
		return InternalStaticAnimPhysDefClassPointer->Shadow_Ignores_Z_Rotation();
	}

	void StaticAnimPhysDefClass::ShadowIgnoresZRotation::set(bool value)
	{
		auto helper = reinterpret_cast<StaticAnimPhysDefClassHelper *>(InternalStaticAnimPhysDefClassPointer);

		auto &shadowIgnoresZRotation = helper->GetShadowIgnoresZRotation();

		shadowIgnoresZRotation = value;
	}

	float StaticAnimPhysDefClass::ShadowNearZ::get()
	{
		return InternalStaticAnimPhysDefClassPointer->Shadow_NearZ();
	}

	void StaticAnimPhysDefClass::ShadowNearZ::set(float value)
	{
		auto helper = reinterpret_cast<StaticAnimPhysDefClassHelper *>(InternalStaticAnimPhysDefClassPointer);

		auto &shadowNearZ = helper->GetShadowNearZ();

		shadowNearZ = value;
	}

	float StaticAnimPhysDefClass::ShadowFarZ::get()
	{
		return InternalStaticAnimPhysDefClassPointer->Shadow_FarZ();
	}

	void StaticAnimPhysDefClass::ShadowFarZ::set(float value)
	{
		auto helper = reinterpret_cast<StaticAnimPhysDefClassHelper *>(InternalStaticAnimPhysDefClassPointer);

		auto &shadowFarZ = helper->GetShadowFarZ();

		shadowFarZ = value;
	}

	float StaticAnimPhysDefClass::ShadowIntensity::get()
	{
		return InternalStaticAnimPhysDefClassPointer->Shadow_Intensity();
	}

	void StaticAnimPhysDefClass::ShadowIntensity::set(float value)
	{
		auto helper = reinterpret_cast<StaticAnimPhysDefClassHelper *>(InternalStaticAnimPhysDefClassPointer);

		auto &shadowIntensity = helper->GetShadowIntensity();

		shadowIntensity = value;
	}

	bool StaticAnimPhysDefClass::DoesCollideInPathfind::get()
	{
		return InternalStaticAnimPhysDefClassPointer->Does_Collide_In_Pathfind();
	}

	void StaticAnimPhysDefClass::DoesCollideInPathfind::set(bool value)
	{
		auto helper = reinterpret_cast<StaticAnimPhysDefClassHelper *>(InternalStaticAnimPhysDefClassPointer);

		auto &doesCollideInPathfind = helper->GetDoesCollideInPathfind();

		doesCollideInPathfind = value;
	}

	::StaticPhysDefClass *StaticAnimPhysDefClass::InternalStaticPhysDefClassPointer::get()
	{
		return InternalStaticAnimPhysDefClassPointer;
	}

	::StaticAnimPhysDefClass *StaticAnimPhysDefClass::InternalStaticAnimPhysDefClassPointer::get()
	{
		return reinterpret_cast<::StaticAnimPhysDefClass *>(Pointer.ToPointer());
	}

	bool StaticAnimPhysDefClass::IsCosmetic::get()
	{
		auto helper = reinterpret_cast<StaticAnimPhysDefClassHelper *>(InternalStaticAnimPhysDefClassPointer);

		auto &isCosmetic = helper->GetIsCosmetic();

		return isCosmetic;
	}

	void StaticAnimPhysDefClass::IsCosmetic::set(bool value)
	{
		auto helper = reinterpret_cast<StaticAnimPhysDefClassHelper *>(InternalStaticAnimPhysDefClassPointer);

		auto &isCosmetic = helper->GetIsCosmetic();

		isCosmetic = value;
	}

	IAnimCollisionManagerDefClass ^StaticAnimPhysDefClass::AnimManagerDef::get()
	{
		auto helper = reinterpret_cast<StaticAnimPhysDefClassHelper *>(InternalStaticAnimPhysDefClassPointer);

		auto &animManagerDef = helper->GetAnimManagerDef();

		return gcnew AnimCollisionManagerDefClass(IntPtr(&animManagerDef));
	}

	void StaticAnimPhysDefClass::AnimManagerDef::set(IAnimCollisionManagerDefClass ^value)
	{
		if (value == nullptr || value->AnimCollisionManagerDefClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<StaticAnimPhysDefClassHelper *>(InternalStaticAnimPhysDefClassPointer);

		auto &animManagerDef = helper->GetAnimManagerDef();

		animManagerDef = *reinterpret_cast<::AnimCollisionManagerDefClass *>(value->AnimCollisionManagerDefClassPointer.ToPointer());
	}

	IProjectorManagerDefClass ^StaticAnimPhysDefClass::ProjectorManagerDef::get()
	{
		auto helper = reinterpret_cast<StaticAnimPhysDefClassHelper *>(InternalStaticAnimPhysDefClassPointer);

		auto &projectorManagerDef = helper->GetProjectorManagerDef();

		return gcnew ProjectorManagerDefClass(IntPtr(&projectorManagerDef));
	}

	void StaticAnimPhysDefClass::ProjectorManagerDef::set(IProjectorManagerDefClass ^value)
	{
		if (value == nullptr || value->ProjectorManagerDefClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<StaticAnimPhysDefClassHelper *>(InternalStaticAnimPhysDefClassPointer);

		auto &projectorManagerDef = helper->GetProjectorManagerDef();

		projectorManagerDef = *reinterpret_cast<::ProjectorManagerDefClass *>(value->ProjectorManagerDefClassPointer.ToPointer());
	}
}