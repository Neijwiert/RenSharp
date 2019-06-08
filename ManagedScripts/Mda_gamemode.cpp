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
#include "Mda_gamemode.h"

#include "Imports.h"
#include "UnmanagedContainer.h"
#include "Mda_game.h"
#include "RenSharpGameModeClass.h"
#include "RenSharpGameModeFactoryClass.h"

using namespace System::Text;

namespace RenSharp
{
	DAGameModeFactoryClass::DAGameModeFactoryClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	String^ DAGameModeFactoryClass::ToString()
	{
		StringBuilder^ builder = gcnew StringBuilder();
		builder->Append(LongName);

		return builder->ToString();
	}

	bool DAGameModeFactoryClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IRenSharpGameModeFactoryClass^ otherThis1 = dynamic_cast<IRenSharpGameModeFactoryClass^>(other);
		if (otherThis1 != nullptr && DAGameModeFactoryClassPointer.Equals(otherThis1->DAGameModeFactoryClassPointer))
		{
			return true;
		}

		IDAGameModeFactoryClass^ otherThis2 = dynamic_cast<IDAGameModeFactoryClass^>(other);
		if (otherThis2 == nullptr)
		{
			return nullptr;
		}

		return DAGameModeFactoryClassPointer.Equals(otherThis2->DAGameModeFactoryClassPointer);
	}

	IDAGameModeClass^ DAGameModeFactoryClass::CreateInstance()
	{
		auto result = InternalDAGameModeFactoryClassPointer->Create_Instance();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAGameModeClass(IntPtr(result));
		}
	}

	IRenSharpGameModeFactoryClass^ DAGameModeFactoryClass::AsManagedGameModeFactory()
	{
		return DAGameManager::AsManagedGameModeFactory(this);
	}

	IntPtr DAGameModeFactoryClass::DAGameModeFactoryClassPointer::get()
	{
		return IntPtr(InternalDAGameModeFactoryClassPointer);
	}

	String^ DAGameModeFactoryClass::LongName::get()
	{
		auto result = InternalDAGameModeFactoryClassPointer->Get_Long_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String^ DAGameModeFactoryClass::ShortName::get()
	{
		auto result = InternalDAGameModeFactoryClassPointer->Get_Short_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	IDAGameModeClass^ DAGameModeFactoryClass::Instance::get()
	{
		auto result = InternalDAGameModeFactoryClassPointer->Get_Instance();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAGameModeClass(IntPtr(result));
		}
	}

	void DAGameModeFactoryClass::Instance::set(IDAGameModeClass^ value)
	{
		auto helper = reinterpret_cast<DAGameModeFactoryClassHelper*>(InternalDAGameModeFactoryClassPointer);

		auto& instance = helper->GetInstance();

		if (value == nullptr || value->DAGameModeClassPointer.ToPointer() == nullptr)
		{
			instance = nullptr;
		}
		else
		{
			instance = reinterpret_cast<::DAGameModeClass*>(value->DAGameModeClassPointer.ToPointer());
		}
	}

	bool DAGameModeFactoryClass::IsManagedGameModeFactory::get()
	{
		return DAGameManager::IsManagedGameModeFactory(this);
	}

	bool DAGameModeFactoryClass::InternalDestroyPointer()
	{
		Imports::DestroyDAGameModeFactoryClass(InternalDAGameModeFactoryClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	void DAGameModeFactoryClass::AddGameMode()
	{
		auto helper = reinterpret_cast<DAGameModeFactoryClassHelper*>(InternalDAGameModeFactoryClassPointer);

		helper->AddGameMode();
	}

	::DAGameModeFactoryClass* DAGameModeFactoryClass::InternalDAGameModeFactoryClassPointer::get()
	{
		return reinterpret_cast<::DAGameModeFactoryClass*>(Pointer.ToPointer());
	}

	DAGameModeClass::DAGameModeClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	String^ DAGameModeClass::ToString()
	{
		StringBuilder^ builder = gcnew StringBuilder();
		builder->Append(LongName);

		return builder->ToString();
	}

	bool DAGameModeClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IRenSharpGameModeClass^ otherThis1 = dynamic_cast<IRenSharpGameModeClass^>(other);
		if (otherThis1 != nullptr && DAGameModeClassPointer.Equals(otherThis1->DAGameModeClassPointer))
		{
			return true;
		}

		IDAGameModeClass^ otherThis2 = dynamic_cast<IDAGameModeClass^>(other);
		if (otherThis2 == nullptr)
		{
			return nullptr;
		}

		return DAGameModeClassPointer.Equals(otherThis2->DAGameModeClassPointer);
	}

	void DAGameModeClass::Init()
	{
		InternalDAGameModeClassPointer->Init();
	}

	IRenSharpGameModeClass^ DAGameModeClass::AsManagedGameMode()
	{
		return DAGameManager::AsManagedGameMode(this);
	}

	IntPtr DAGameModeClass::DAGameModeClassPointer::get()
	{
		return IntPtr(InternalDAGameModeClassPointer);
	}

	String^ DAGameModeClass::LongName::get()
	{
		auto result = InternalDAGameModeClassPointer->Get_Long_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String^ DAGameModeClass::ShortName::get()
	{
		auto result = InternalDAGameModeClassPointer->Get_Short_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	IDAGameModeFactoryClass^ DAGameModeClass::Factory::get()
	{
		auto result = InternalDAGameModeClassPointer->Get_Factory();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAGameModeFactoryClass(IntPtr(const_cast<::DAGameModeFactoryClass*>(result)));
		}
	}

	void DAGameModeClass::Factory::set(IDAGameModeFactoryClass^ value)
	{
		if (value == nullptr || value->DAGameModeFactoryClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalDAGameModeClassPointer->Set_Factory(
			reinterpret_cast<::DAGameModeFactoryClass*>(value->DAGameModeFactoryClassPointer.ToPointer()));
	}

	bool DAGameModeClass::IsManagedGameMode::get()
	{
		return DAGameManager::IsManagedGameMode(this);
	}

	bool DAGameModeClass::InternalDestroyPointer()
	{
		Imports::DestroyDAGameModeClass(InternalDAGameModeClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DAGameModeClass* DAGameModeClass::InternalDAGameModeClassPointer::get()
	{
		return reinterpret_cast<::DAGameModeClass*>(Pointer.ToPointer());
	}
}