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
#include "MPhysDefClass.h"

namespace RenSharp
{

#pragma managed(push, off)

	class PhysDefClassHelper : public ::PhysDefClass
	{
		private:
			PhysDefClassHelper() = default;

		public:
			::StringClass &GetModelName()
			{
				return ModelName;
			}

			bool &GetIsPreLit()
			{
				return IsPreLit;
			}
	};

#pragma managed(pop)

	PhysDefClass::PhysDefClass(IntPtr pointer)
		: DefinitionClass(pointer)
	{

	}

	String ^PhysDefClass::GetCollisionGroupName(CollisionGroupType group)
	{
		auto result = ::GetCollisionGroupName(static_cast<::Collision_Group_Type>(group));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	bool PhysDefClass::IsType(String ^typeName)
	{
		if (typeName == nullptr)
		{
			throw gcnew ArgumentNullException("typeName");
		}

		IntPtr typeNameHandle = Marshal::StringToHGlobalAnsi(typeName);
		try
		{
			return InternalPhysDefClassPointer->Is_Type(reinterpret_cast<char *>(typeNameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(typeNameHandle);
		}
	}

	IntPtr PhysDefClass::PhysDefClassPointer::get()
	{
		return IntPtr(InternalPhysDefClassPointer);
	}

	String ^PhysDefClass::TypeName::get()
	{
		auto result = InternalPhysDefClassPointer->Get_Type_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String ^PhysDefClass::ModelName::get()
	{
		return gcnew String(InternalPhysDefClassPointer->Get_Model_Name().Peek_Buffer());
	}

	void PhysDefClass::ModelName::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			auto helper = reinterpret_cast<PhysDefClassHelper *>(InternalPhysDefClassPointer);

			auto &modelName = helper->GetModelName();

			modelName = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	bool PhysDefClass::IsPreLit::get()
	{
		return InternalPhysDefClassPointer->Get_Is_Pre_Lit();
	}

	void PhysDefClass::IsPreLit::set(bool value)
	{
		auto helper = reinterpret_cast<PhysDefClassHelper *>(InternalPhysDefClassPointer);

		bool &isPreLit = helper->GetIsPreLit();

		isPreLit = value;
	}

	::DefinitionClass *PhysDefClass::InternalDefinitionClassPointer::get()
	{
		return InternalPhysDefClassPointer;
	}

	::PhysDefClass *PhysDefClass::InternalPhysDefClassPointer::get()
	{
		return reinterpret_cast<::PhysDefClass *>(Pointer.ToPointer());
	}
}