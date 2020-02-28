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
#include "RenSharpPlayerDataClass.h"

#include "Imports.h"
#include "RenSharpPlayerDataFactoryClass.h"
#include "McPlayer.h"
#include "MSoldierGameObj.h"
#include "Mda_player.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_player.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Text;

namespace RenSharp
{
#pragma managed(push, off)

	struct DAPlayerClassData
	{
		typedef ::DynamicVectorClass<::DAPlayerDataClass*> (::DAPlayerClass::*type);
		friend type get(DAPlayerClassData);
	};

	template struct Rob<DAPlayerClassData, &::DAPlayerClass::Data>;

#pragma managed(pop)

	RenSharpPlayerDataClass::RenSharpPlayerDataClass()
		:
		disposedResources(false),
		destroyPointer(true),
		daPlayerDataClassPointer(IntPtr::Zero),
		daPlayerDataClass(nullptr)
	{

	}

	RenSharpPlayerDataClass::~RenSharpPlayerDataClass()
	{
		if (disposedResources)
		{
			return;
		}

		DAPlayerManager::UnregisterManagedPlayerData(this);

		this->!RenSharpPlayerDataClass();

		disposedResources = true;
	}

	RenSharpPlayerDataClass::!RenSharpPlayerDataClass()
	{
		if (IsAttached)
		{
			auto cPlayerOwner = InternalDAPlayerDataClassPointer->Get_Owner();
			if (cPlayerOwner != nullptr)
			{
				auto daPlayerOwner = cPlayerOwner->Get_DA_Player();
				if (daPlayerOwner != nullptr)
				{
					auto& data = (*daPlayerOwner).*get(DAPlayerClassData());

					data.DeleteObj(InternalDAPlayerDataClassPointer);
				}
			}

			if (destroyPointer)
			{
				IntPtr tmp = daPlayerDataClassPointer;
				daPlayerDataClassPointer = IntPtr::Zero;
				Imports::DestroyDAPlayerDataClass(reinterpret_cast<::DAPlayerDataClass*>(tmp.ToPointer()));
			}
		}

		ReleasePointer();
	}

	String^ RenSharpPlayerDataClass::ToString()
	{
		StringBuilder^ builder = gcnew StringBuilder();
		if (IsAttached)
		{
			builder->Append(Name);
		}
		else
		{
			builder->Append(static_cast<Object^>(nullptr));
		}
		
		return builder->ToString();
	}

	bool RenSharpPlayerDataClass::Equals(Object^ other)
	{
		if (ReferenceEquals(other, nullptr))
		{
			return false;
		}

		IDAPlayerDataClass^ otherThis1 = dynamic_cast<IDAPlayerDataClass^>(other);
		if (otherThis1 != nullptr && daPlayerDataClassPointer.Equals(otherThis1->DAPlayerDataClassPointer))
		{
			return true;
		}

		IRenSharpPlayerDataClass^ otherThis2 = dynamic_cast<IRenSharpPlayerDataClass^>(other);
		if (otherThis2 == nullptr)
		{
			return false;
		}

		return daPlayerDataClassPointer.Equals(otherThis2->DAPlayerDataClassPointer);
	}

	int RenSharpPlayerDataClass::GetHashCode()
	{
		return daPlayerDataClassPointer.GetHashCode();
	}

	void RenSharpPlayerDataClass::InitUnmanagedAttachable()
	{
		AttachToUnmanagedObject();
		RegisterManagedObject();
	}

	void RenSharpPlayerDataClass::AttachToUnmanagedObject()
	{
		if (IsAttached)
		{
			throw gcnew NotSupportedException("Already attached.");
		}

		daPlayerDataClassPointer = IntPtr(Imports::CreateRenSharpPlayerDataClass());

		daPlayerDataClass = gcnew DAPlayerDataClass(daPlayerDataClassPointer);

		UnmanagedAttach();
	}

	void RenSharpPlayerDataClass::RegisterManagedObject()
	{
		DAPlayerManager::RegisterManagedPlayerData(this);

		ManagedRegistered();
	}

	void RenSharpPlayerDataClass::ReleasePointer()
	{
		daPlayerDataClassPointer = IntPtr::Zero;
		daPlayerDataClass = nullptr;
	}

	void RenSharpPlayerDataClass::UnmanagedAttach()
	{

	}

	void RenSharpPlayerDataClass::ManagedRegistered()
	{

	}

	IDAPlayerDataClass^ RenSharpPlayerDataClass::AsUnmanagedObject()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daPlayerDataClass;
	}

	void RenSharpPlayerDataClass::Init()
	{

	}

	void RenSharpPlayerDataClass::ClearLevel()
	{

	}

	void RenSharpPlayerDataClass::ClearSession()
	{

	}

	IntPtr RenSharpPlayerDataClass::DAPlayerDataClassPointer::get()
	{
		return daPlayerDataClassPointer;
	}

	IntPtr RenSharpPlayerDataClass::Pointer::get()
	{
		return daPlayerDataClassPointer;
	}

	bool RenSharpPlayerDataClass::IsAttached::get()
	{
		return (daPlayerDataClassPointer != IntPtr::Zero);
	}

	bool RenSharpPlayerDataClass::IsRegistered::get()
	{
		return (IsAttached && DAPlayerManager::IsManagedPlayerData(daPlayerDataClassPointer));
	}

	bool RenSharpPlayerDataClass::DestroyPointer::get()
	{
		return destroyPointer;
	}

	void RenSharpPlayerDataClass::DestroyPointer::set(bool value)
	{
		destroyPointer = value;
	}

	IcPlayer^ RenSharpPlayerDataClass::Owner::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daPlayerDataClass->Owner;
	}

	void RenSharpPlayerDataClass::Owner::set(IcPlayer^ value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daPlayerDataClass->Owner = value;
	}

	IDAPlayerDataFactoryClass^ RenSharpPlayerDataClass::Factory::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daPlayerDataClass->Factory;
	}

	void RenSharpPlayerDataClass::Factory::set(IDAPlayerDataFactoryClass^ value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daPlayerDataClass->Factory = value;
	}

	int RenSharpPlayerDataClass::ID::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daPlayerDataClass->ID;
	}

	String^ RenSharpPlayerDataClass::Name::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}
		
		return daPlayerDataClass->Name;
	}

	ISoldierGameObj^ RenSharpPlayerDataClass::GameObj::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daPlayerDataClass->GameObj;
	}

	int RenSharpPlayerDataClass::Team::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daPlayerDataClass->Team;
	}

	::DAPlayerDataClass* RenSharpPlayerDataClass::InternalDAPlayerDataClassPointer::get()
	{
		return reinterpret_cast<::DAPlayerDataClass*>(daPlayerDataClassPointer.ToPointer());
	}
}