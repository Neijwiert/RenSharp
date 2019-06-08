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
#include "RenSharpGameFeatureClass.h"

#include "RenSharpGameFeatureFactoryClass.h"
#include "Mda_game.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_gamefeature.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Text;

namespace RenSharp
{
	RenSharpGameFeatureClass::RenSharpGameFeatureClass()
		:
		disposedResources(false),
		destroyPointer(true),
		daGameFeatureClassPointer(IntPtr::Zero),
		daGameFeatureClass(nullptr)
	{

	}

	RenSharpGameFeatureClass::~RenSharpGameFeatureClass()
	{
		if (disposedResources)
		{
			return;
		}

		DAGameManager::UnregisterManagedGameFeature(this);

		this->!RenSharpGameFeatureClass();

		disposedResources = true;
	}

	RenSharpGameFeatureClass::!RenSharpGameFeatureClass()
	{
		if (IsAttached)
		{
			auto factory = const_cast<::DAGameFeatureFactoryClass*>(InternalDAGameFeatureClassPointer->Get_Factory());
			if (factory != nullptr)
			{
				auto helper = reinterpret_cast<DAGameFeatureFactoryClassHelper*>(factory);

				auto& instance = helper->GetInstance();
				if (instance == InternalDAGameFeatureClassPointer)
				{
					instance = nullptr;
				}
			}

			if (destroyPointer)
			{
				IntPtr tmp = daGameFeatureClassPointer;
				daGameFeatureClassPointer = IntPtr::Zero;
				Imports::DestroyDAGameFeatureClass(reinterpret_cast<::DAGameFeatureClass*>(tmp.ToPointer()));
			}
		}

		ReleasePointer();
	}

	String^ RenSharpGameFeatureClass::ToString()
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

	bool RenSharpGameFeatureClass::Equals(Object^ other)
	{
		if (ReferenceEquals(other, nullptr))
		{
			return false;
		}

		IDAGameFeatureClass^ otherThis1 = dynamic_cast<IDAGameFeatureClass^>(other);
		if (otherThis1 != nullptr && daGameFeatureClassPointer.Equals(otherThis1->DAGameFeatureClassPointer))
		{
			return true;
		}

		IRenSharpGameFeatureClass^ otherThis2 = dynamic_cast<IRenSharpGameFeatureClass^>(other);
		if (otherThis2 == nullptr)
		{
			return false;
		}

		return daGameFeatureClassPointer.Equals(otherThis2->DAGameFeatureClassPointer);
	}

	int RenSharpGameFeatureClass::GetHashCode()
	{
		return daGameFeatureClassPointer.GetHashCode();
	}

	void RenSharpGameFeatureClass::AttachToUnmanagedObject()
	{
		if (IsAttached)
		{
			throw gcnew NotSupportedException("Already attached.");
		}

		daGameFeatureClassPointer = IntPtr(Imports::CreateRenSharpGameFeatureClass());

		daGameFeatureClass = gcnew DAGameFeatureClass(daGameFeatureClassPointer);

		UnmanagedAttach();
	}

	void RenSharpGameFeatureClass::RegisterManagedObject()
	{
		DAGameManager::RegisterManagedGameFeature(this);

		ManagedRegistered();
	}

	void RenSharpGameFeatureClass::ReleasePointer()
	{
		daGameFeatureClassPointer = IntPtr::Zero;
		daGameFeatureClass = nullptr;
	}

	void RenSharpGameFeatureClass::UnmanagedAttach()
	{

	}

	void RenSharpGameFeatureClass::ManagedRegistered()
	{

	}

	IDAGameFeatureClass^ RenSharpGameFeatureClass::AsUnmanagedObject()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daGameFeatureClass;
	}

	void RenSharpGameFeatureClass::Init()
	{

	}

	IntPtr RenSharpGameFeatureClass::DAGameFeatureClassPointer::get()
	{
		return daGameFeatureClassPointer;
	}

	IntPtr RenSharpGameFeatureClass::Pointer::get()
	{
		return daGameFeatureClassPointer;
	}

	bool RenSharpGameFeatureClass::IsAttached::get()
	{
		return (daGameFeatureClassPointer != IntPtr::Zero);
	}

	bool RenSharpGameFeatureClass::DestroyPointer::get()
	{
		return destroyPointer;
	}

	void RenSharpGameFeatureClass::DestroyPointer::set(bool value)
	{
		destroyPointer = value;
	}

	String^ RenSharpGameFeatureClass::Name::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daGameFeatureClass->Name;
	}

	IDAGameFeatureFactoryClass^ RenSharpGameFeatureClass::Factory::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daGameFeatureClass->Factory;
	}

	void RenSharpGameFeatureClass::Factory::set(IDAGameFeatureFactoryClass^ value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daGameFeatureClass->Factory = value;
	}

	::DAGameFeatureClass* RenSharpGameFeatureClass::InternalDAGameFeatureClassPointer::get()
	{
		return reinterpret_cast<::DAGameFeatureClass*>(daGameFeatureClassPointer.ToPointer());
	}
}