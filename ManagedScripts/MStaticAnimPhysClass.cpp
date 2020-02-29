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
#include "MStaticAnimPhysClass.h"

#include "MStaticAnimPhysDefClass.h"
#include "MAnimCollisionManagerClass.h"
#include "MProjectorManagerClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <StaticAnimPhysClass.h>
#include <StaticAnimPhysDefClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{

#pragma managed(push, off)

	class StaticAnimPhysClassHelper : public ::StaticAnimPhysClass
	{
		private:
			StaticAnimPhysClassHelper() = default;

		public:
			::ProjectorManagerClass &GetProjectorManager()
			{
				return ProjectorManager;
			}

			::TexProjectClass *&GetShadowProjector()
			{
				return ShadowProjector;
			}
	};

#pragma managed(pop)

	StaticAnimPhysClass::StaticAnimPhysClass(IntPtr pointer)
		: StaticPhysClass(pointer)
	{

	}

	IStaticAnimPhysClass ^StaticAnimPhysClass::AsStaticAnimPhysClass()
	{
		return this;
	}

	IntPtr StaticAnimPhysClass::StaticAnimPhysClassPointer::get()
	{
		return IntPtr(InternalStaticAnimPhysClassPointer);
	}

	IStaticAnimPhysDefClass ^StaticAnimPhysClass::StaticAnimPhysDef::get()
	{
		auto defPtr = InternalStaticAnimPhysClassPointer->Get_StaticAnimPhysDef();
		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			auto result = DefinitionClass::CreateDefinitionClassWrapper(defPtr);
			if (result != nullptr)
			{
				return safe_cast<IStaticAnimPhysDefClass^>(result);
			}

			return gcnew StaticAnimPhysDefClass(IntPtr(defPtr));
		}
	}

	IAnimCollisionManagerClass ^StaticAnimPhysClass::AnimationManager::get()
	{
		return gcnew AnimCollisionManagerClass(IntPtr(&InternalStaticAnimPhysClassPointer->Get_Animation_Manager()));
	}

	::StaticPhysClass *StaticAnimPhysClass::InternalStaticPhysClassPointer::get()
	{
		return InternalStaticAnimPhysClassPointer;
	}

	::StaticAnimPhysClass *StaticAnimPhysClass::InternalStaticAnimPhysClassPointer::get()
	{
		return reinterpret_cast<::StaticAnimPhysClass *>(Pointer.ToPointer());
	}

	IProjectorManagerClass ^StaticAnimPhysClass::ProjectorManager::get()
	{
		auto helper = reinterpret_cast<StaticAnimPhysClassHelper *>(InternalStaticAnimPhysClassPointer);

		auto &projectorManager = helper->GetProjectorManager();

		return gcnew ProjectorManagerClass(IntPtr(&projectorManager));
	}

	void StaticAnimPhysClass::ProjectorManager::set(IProjectorManagerClass ^value)
	{
		if (value == nullptr || value->ProjectorManagerClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<StaticAnimPhysClassHelper *>(InternalStaticAnimPhysClassPointer);

		auto &projectorManager = helper->GetProjectorManager();

		projectorManager = *reinterpret_cast<::ProjectorManagerClass *>(value->ProjectorManagerClassPointer.ToPointer());
	}

	IntPtr StaticAnimPhysClass::ShadowProjector::get()
	{
		auto helper = reinterpret_cast<StaticAnimPhysClassHelper *>(InternalStaticAnimPhysClassPointer);

		auto &shadowProjector = helper->GetShadowProjector();

		return IntPtr(shadowProjector);
	}

	void StaticAnimPhysClass::ShadowProjector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<StaticAnimPhysClassHelper *>(InternalStaticAnimPhysClassPointer);

		auto &shadowProjector = helper->GetShadowProjector();

		shadowProjector = reinterpret_cast<::TexProjectClass *>(value.ToPointer());
	}
}