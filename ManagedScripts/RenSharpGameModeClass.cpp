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
#include "RenSharpGameModeClass.h"

#include "RenSharpGameModeFactoryClass.h"
#include "Mda_game.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_gamemode.h>
#include <da_game.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Text;

namespace RenSharp
{
	RenSharpGameModeClass::RenSharpGameModeClass()
		:
		disposedResources(false),
		destroyPointer(true),
		daGameModeClassPointer(IntPtr::Zero),
		daGameModeClass(nullptr)
	{

	}

	RenSharpGameModeClass::~RenSharpGameModeClass()
	{
		if (disposedResources)
		{
			return;
		}

		DAGameManager::UnregisterManagedGameMode(this);

		this->!RenSharpGameModeClass();

		disposedResources = true;
	}

	RenSharpGameModeClass::!RenSharpGameModeClass()
	{
		if (IsAttached)
		{
			auto currentGameModeFactory = ::DAGameManager::Get_Game_Mode();
			if (currentGameModeFactory != nullptr)
			{
				auto helper = reinterpret_cast<DAGameModeFactoryClassHelper*>(currentGameModeFactory);

				auto& instance = helper->GetInstance();
				if (instance == InternalDAGameModeClassPointer)
				{
					instance = nullptr;
				}
			}

			if (destroyPointer)
			{
				IntPtr tmp = daGameModeClassPointer;
				daGameModeClassPointer = IntPtr::Zero;
				Imports::DestroyDAGameModeClass(reinterpret_cast<::DAGameModeClass*>(tmp.ToPointer()));
			}
		}

		ReleasePointer();
	}

	String^ RenSharpGameModeClass::ToString()
	{
		StringBuilder^ builder = gcnew StringBuilder();
		if (IsAttached)
		{
			builder->Append(LongName);
		}
		else
		{
			builder->Append(static_cast<Object^>(nullptr));
		}

		return builder->ToString();
	}

	bool RenSharpGameModeClass::Equals(Object^ other)
	{
		if (ReferenceEquals(other, nullptr))
		{
			return false;
		}

		IDAGameModeClass^ otherThis1 = dynamic_cast<IDAGameModeClass^>(other);
		if (otherThis1 != nullptr && daGameModeClassPointer.Equals(otherThis1->DAGameModeClassPointer))
		{
			return true;
		}

		IRenSharpGameModeClass^ otherThis2 = dynamic_cast<IRenSharpGameModeClass^>(other);
		if (otherThis2 == nullptr)
		{
			return false;
		}

		return daGameModeClassPointer.Equals(otherThis2->DAGameModeClassPointer);
	}

	int RenSharpGameModeClass::GetHashCode()
	{
		return daGameModeClassPointer.GetHashCode();
	}

	void RenSharpGameModeClass::InitUnmanagedAttachable()
	{
		AttachToUnmanagedObject();
		RegisterManagedObject();
	}

	void RenSharpGameModeClass::AttachToUnmanagedObject()
	{
		if (IsAttached)
		{
			throw gcnew NotSupportedException("Already attached.");
		}

		daGameModeClassPointer = IntPtr(Imports::CreateRenSharpGameModeClass());

		daGameModeClass = gcnew DAGameModeClass(daGameModeClassPointer);

		UnmanagedAttach();
	}

	void RenSharpGameModeClass::RegisterManagedObject()
	{
		DAGameManager::RegisterManagedGameMode(this);

		ManagedRegistered();
	}

	void RenSharpGameModeClass::ReleasePointer()
	{
		daGameModeClassPointer = IntPtr::Zero;
		daGameModeClass = nullptr;
	}

	void RenSharpGameModeClass::UnmanagedAttach()
	{

	}

	void RenSharpGameModeClass::ManagedRegistered()
	{

	}

	IDAGameModeClass^ RenSharpGameModeClass::AsUnmanagedObject()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daGameModeClass;
	}

	void RenSharpGameModeClass::Init()
	{

	}

	IntPtr RenSharpGameModeClass::DAGameModeClassPointer::get()
	{
		return daGameModeClassPointer;
	}

	IntPtr RenSharpGameModeClass::Pointer::get()
	{
		return daGameModeClassPointer;
	}

	bool RenSharpGameModeClass::IsAttached::get()
	{
		return (daGameModeClassPointer != IntPtr::Zero);
	}

	bool RenSharpGameModeClass::IsRegistered::get()
	{
		return (IsAttached && DAGameManager::IsManagedGameMode(daGameModeClassPointer));
	}

	bool RenSharpGameModeClass::DestroyPointer::get()
	{
		return destroyPointer;
	}

	void RenSharpGameModeClass::DestroyPointer::set(bool value)
	{
		destroyPointer = value;
	}

	String^ RenSharpGameModeClass::LongName::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daGameModeClass->LongName;
	}

	String^ RenSharpGameModeClass::ShortName::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daGameModeClass->ShortName;
	}

	IDAGameModeFactoryClass^ RenSharpGameModeClass::Factory::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daGameModeClass->Factory;
	}

	void RenSharpGameModeClass::Factory::set(IDAGameModeFactoryClass^ value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daGameModeClass->Factory = value;
	}

	::DAGameModeClass* RenSharpGameModeClass::InternalDAGameModeClassPointer::get()
	{
		return reinterpret_cast<::DAGameModeClass*>(daGameModeClassPointer.ToPointer());
	}
}