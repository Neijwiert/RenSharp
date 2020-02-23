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
#include "Mda_gamefeature.h"

#include "Imports.h"
#include "UnmanagedContainer.h"
#include "Mda_game.h"
#include "RenSharpGameFeatureClass.h"
#include "RenSharpGameFeatureFactoryClass.h"

using namespace System::Text;

namespace RenSharp
{
	DAGameFeatureFactoryClass::DAGameFeatureFactoryClass()
	{

	}

	DAGameFeatureFactoryClass::DAGameFeatureFactoryClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	String^ DAGameFeatureFactoryClass::ToString()
	{
		StringBuilder^ builder = gcnew StringBuilder();
		builder->Append(Name);

		return builder->ToString();
	}

	bool DAGameFeatureFactoryClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IRenSharpGameFeatureFactoryClass^ otherThis1 = dynamic_cast<IRenSharpGameFeatureFactoryClass^>(other);
		if (otherThis1 != nullptr && DAGameFeatureFactoryClassPointer.Equals(otherThis1->DAGameFeatureFactoryClassPointer))
		{
			return true;
		}

		IDAGameFeatureFactoryClass^ otherThis2 = dynamic_cast<IDAGameFeatureFactoryClass^>(other);
		if (otherThis2 == nullptr)
		{
			return nullptr;
		}

		return DAGameFeatureFactoryClassPointer.Equals(otherThis2->DAGameFeatureFactoryClassPointer);
	}

	IDAGameFeatureClass^ DAGameFeatureFactoryClass::CreateInstance()
	{
		auto result = InternalDAGameFeatureFactoryClassPointer->Create_Instance();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAGameFeatureClass(IntPtr(result));
		}
	}

	IRenSharpGameFeatureFactoryClass^ DAGameFeatureFactoryClass::AsManagedGameFeatureFactory()
	{
		return DAGameManager::AsManagedGameFeatureFactory(this);
	}

	IntPtr DAGameFeatureFactoryClass::DAGameFeatureFactoryClassPointer::get()
	{
		return IntPtr(InternalDAGameFeatureFactoryClassPointer);
	}

	String^ DAGameFeatureFactoryClass::Name::get()
	{
		auto result = InternalDAGameFeatureFactoryClassPointer->Get_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String^ DAGameFeatureFactoryClass::EnableSetting::get()
	{
		auto result = InternalDAGameFeatureFactoryClassPointer->Get_Enable_Setting();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String^ DAGameFeatureFactoryClass::RequiredData::get()
	{
		auto result = InternalDAGameFeatureFactoryClassPointer->Get_Required_Data();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	IDAGameFeatureClass^ DAGameFeatureFactoryClass::Instance::get()
	{
		auto result = InternalDAGameFeatureFactoryClassPointer->Get_Instance();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAGameFeatureClass(IntPtr(result));
		}
	}

	void DAGameFeatureFactoryClass::Instance::set(IDAGameFeatureClass^ value)
	{
		auto helper = reinterpret_cast<DAGameFeatureFactoryClassHelper*>(InternalDAGameFeatureFactoryClassPointer);

		auto& instance = helper->GetInstance();

		if (value == nullptr || value->DAGameFeatureClassPointer.ToPointer() == nullptr)
		{
			instance = nullptr;
		}
		else
		{
			instance = reinterpret_cast<::DAGameFeatureClass*>(value->DAGameFeatureClassPointer.ToPointer());
		}
	}

	bool DAGameFeatureFactoryClass::IsManagedGameFeatureFactory::get()
	{
		return DAGameManager::IsManagedGameFeatureFactory(this);
	}

	bool DAGameFeatureFactoryClass::InternalDestroyPointer()
	{
		Imports::DestroyDAGameFeatureFactoryClass(InternalDAGameFeatureFactoryClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	void DAGameFeatureFactoryClass::AddGameFeature()
	{
		auto helper = reinterpret_cast<DAGameFeatureFactoryClassHelper*>(InternalDAGameFeatureFactoryClassPointer);

		helper->AddGameFeature();
	}

	::DAGameFeatureFactoryClass* DAGameFeatureFactoryClass::InternalDAGameFeatureFactoryClassPointer::get()
	{
		return reinterpret_cast<::DAGameFeatureFactoryClass*>(Pointer.ToPointer());
	}

	DAGameFeatureClass::DAGameFeatureClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	String^ DAGameFeatureClass::ToString()
	{
		StringBuilder^ builder = gcnew StringBuilder();
		builder->Append(Name);

		return builder->ToString();
	}

	bool DAGameFeatureClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IRenSharpGameFeatureClass^ otherThis1 = dynamic_cast<IRenSharpGameFeatureClass^>(other);
		if (otherThis1 != nullptr && DAGameFeatureClassPointer.Equals(otherThis1->DAGameFeatureClassPointer))
		{
			return true;
		}

		IDAGameFeatureClass^ otherThis2 = dynamic_cast<IDAGameFeatureClass^>(other);
		if (otherThis2 == nullptr)
		{
			return nullptr;
		}

		return DAGameFeatureClassPointer.Equals(otherThis2->DAGameFeatureClassPointer);
	}

	void DAGameFeatureClass::Init()
	{
		InternalDAGameFeatureClassPointer->Init();
	}

	IRenSharpGameFeatureClass^ DAGameFeatureClass::AsManagedGameFeature()
	{
		return DAGameManager::AsManagedGameFeature(this);
	}

	IntPtr DAGameFeatureClass::DAGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAGameFeatureClassPointer);
	}

	String^ DAGameFeatureClass::Name::get()
	{
		auto result = InternalDAGameFeatureClassPointer->Get_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	IDAGameFeatureFactoryClass^ DAGameFeatureClass::Factory::get()
	{
		auto result = InternalDAGameFeatureClassPointer->Get_Factory();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAGameFeatureFactoryClass(IntPtr(const_cast<::DAGameFeatureFactoryClass*>(result)));
		}
	}

	void DAGameFeatureClass::Factory::set(IDAGameFeatureFactoryClass^ value)
	{
		if (value == nullptr || value->DAGameFeatureFactoryClassPointer.ToPointer() == nullptr)
		{
			InternalDAGameFeatureClassPointer->Set_Factory(nullptr);
		}
		else
		{
			InternalDAGameFeatureClassPointer->Set_Factory(
				reinterpret_cast<::DAGameFeatureFactoryClass*>(Pointer.ToPointer()));
		}
	}

	bool DAGameFeatureClass::IsManagedGameFeature::get()
	{
		return DAGameManager::IsManagedGameFeature(this);
	}

	bool DAGameFeatureClass::InternalDestroyPointer()
	{
		Imports::DestroyDAGameFeatureClass(InternalDAGameFeatureClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DAGameFeatureClass* DAGameFeatureClass::InternalDAGameFeatureClassPointer::get()
	{
		return reinterpret_cast<::DAGameFeatureClass*>(Pointer.ToPointer());
	}
}