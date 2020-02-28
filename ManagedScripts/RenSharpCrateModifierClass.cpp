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
#include "RenSharpCrateModifierClass.h"

#include "Imports.h"
#include "Mda_cratemanager.h"
#include "McPlayer.h"
#include "Mda_token.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)

class cPlayer;

#include <engine_string.h>
#include <engine_vector.h>
#include <da_crate.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Text;

namespace RenSharp
{
	RenSharpCrateModifierClass::RenSharpCrateModifierClass()
		:
		disposedResources(false),
		destroyPointer(true),
		daCrateModifierClassPointer(IntPtr::Zero),
		daCrateModifierClass(nullptr)
	{

	}

	RenSharpCrateModifierClass::~RenSharpCrateModifierClass()
	{
		if (disposedResources)
		{
			return;
		}

		DACrateManager::UnregisterManagedCrateModifier(this);

		this->!RenSharpCrateModifierClass();

		disposedResources = true;
	}

	RenSharpCrateModifierClass::!RenSharpCrateModifierClass()
	{
		if (IsAttached)
		{
			auto& crates = DACrateManagerHelper::GetCrates();
			int crateCount = crates.Count();

			for (int x = 0; x < crateCount; x++)
			{
				auto crateFactory = crates[x];
				if (crateFactory == nullptr)
				{
					continue;
				}

				auto crateInstance = crateFactory->Get_Instance();
				if (crateInstance == nullptr)
				{
					continue;
				}

				auto helper = reinterpret_cast<DACrateClassHelper*>(crateInstance);

				auto& modifiers = helper->GetModifiers();

				modifiers.DeleteObj(InternalDACrateModifierClassPointer);
			}

			if (destroyPointer)
			{
				IntPtr tmp = daCrateModifierClassPointer;
				daCrateModifierClassPointer = IntPtr::Zero;
				Imports::DestroyDACrateModifierClass(reinterpret_cast<::DACrateModifierClass*>(tmp.ToPointer()));
			}
		}

		ReleasePointer();
	}

	String^ RenSharpCrateModifierClass::ToString()
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

	bool RenSharpCrateModifierClass::Equals(Object^ other)
	{
		if (ReferenceEquals(other, nullptr))
		{
			return false;
		}

		IDACrateModifierClass^ otherThis1 = dynamic_cast<IDACrateModifierClass^>(other);
		if (otherThis1 != nullptr && daCrateModifierClassPointer.Equals(otherThis1->DACrateModifierClassPointer))
		{
			return true;
		}

		IRenSharpCrateModifierClass^ otherThis2 = dynamic_cast<IRenSharpCrateModifierClass^>(other);
		if (otherThis2 == nullptr)
		{
			return false;
		}

		return daCrateModifierClassPointer.Equals(otherThis2->DACrateModifierClassPointer);
	}

	int RenSharpCrateModifierClass::GetHashCode()
	{
		return daCrateModifierClassPointer.GetHashCode();
	}

	void RenSharpCrateModifierClass::InitUnmanagedAttachable()
	{
		AttachToUnmanagedObject();
		RegisterManagedObject();
	}
	
	void RenSharpCrateModifierClass::AttachToUnmanagedObject()
	{
		if (IsAttached)
		{
			throw gcnew NotSupportedException("Already attached.");
		}

		daCrateModifierClassPointer = IntPtr(Imports::CreateRenSharpCrateModifierClass());

		daCrateModifierClass = gcnew DACrateModifierClass(daCrateModifierClassPointer);

		UnmanagedAttach();
	}

	void RenSharpCrateModifierClass::RegisterManagedObject()
	{
		DACrateManager::RegisterManagedCrateModifier(this);

		ManagedRegistered();
	}

	void RenSharpCrateModifierClass::ReleasePointer()
	{
		daCrateModifierClassPointer = IntPtr::Zero;
		daCrateModifierClass = nullptr;
	}

	void RenSharpCrateModifierClass::UnmanagedAttach()
	{

	}

	void RenSharpCrateModifierClass::ManagedRegistered()
	{

	}

	IDACrateModifierClass^ RenSharpCrateModifierClass::AsUnmanagedObject()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daCrateModifierClass;
	}

	void RenSharpCrateModifierClass::Init(String^ parameters)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}
		else if (parameters == nullptr)
		{
			throw gcnew ArgumentNullException("parameters");
		}

		IntPtr parametersHandle = Marshal::StringToHGlobalAnsi(parameters);
		try
		{
			InternalDACrateModifierClassPointer->::DACrateModifierClass::Init(
				reinterpret_cast<char*>(parametersHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(parametersHandle);
		}
	}

	void RenSharpCrateModifierClass::Init(IDATokenClass^ parameters)
	{

	}

	void RenSharpCrateModifierClass::ApplyModifier(float% odds)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		float tmpOdds = odds;

		InternalDACrateModifierClassPointer->::DACrateModifierClass::Apply_Modifier(tmpOdds);

		odds = tmpOdds;
	}

	IntPtr RenSharpCrateModifierClass::DACrateModifierClassPointer::get()
	{
		return daCrateModifierClassPointer;
	}

	IntPtr RenSharpCrateModifierClass::Pointer::get()
	{
		return daCrateModifierClassPointer;
	}

	bool RenSharpCrateModifierClass::IsAttached::get()
	{
		return (daCrateModifierClassPointer != IntPtr::Zero);
	}

	bool RenSharpCrateModifierClass::IsRegistered::get()
	{
		return (IsAttached && DACrateManager::IsManagedCrateModifier(daCrateModifierClassPointer));
	}

	bool RenSharpCrateModifierClass::DestroyPointer::get()
	{
		return destroyPointer;
	}

	void RenSharpCrateModifierClass::DestroyPointer::set(bool value)
	{
		destroyPointer = value;
	}

	bool RenSharpCrateModifierClass::IsMultiplicative::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daCrateModifierClass->IsMultiplicative;
	}

	bool RenSharpCrateModifierClass::IsPositive::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daCrateModifierClass->IsPositive;
	}

	IDACrateModifierFactoryClass^ RenSharpCrateModifierClass::Factory::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daCrateModifierClass->Factory;
	}

	void RenSharpCrateModifierClass::Factory::set(IDACrateModifierFactoryClass^ value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daCrateModifierClass->Factory = value;
	}

	String^ RenSharpCrateModifierClass::Name::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daCrateModifierClass->Name;
	}

	::DACrateModifierClass* RenSharpCrateModifierClass::InternalDACrateModifierClassPointer::get()
	{
		return reinterpret_cast<::DACrateModifierClass*>(daCrateModifierClassPointer.ToPointer());
	}

	DACrateModifierOperator RenSharpCrateModifierClass::Operator::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DACrateModifierClassHelper*>(InternalDACrateModifierClassPointer);

		auto& op = helper->GetOperator();

		return static_cast<DACrateModifierOperator>(op);
	}

	void RenSharpCrateModifierClass::Operator::set(DACrateModifierOperator value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DACrateModifierClassHelper*>(InternalDACrateModifierClassPointer);

		auto& op = helper->GetOperator();

		op = static_cast<::DACrateModifierOperator::Operator>(value);
	}

	float RenSharpCrateModifierClass::Value::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DACrateModifierClassHelper*>(InternalDACrateModifierClassPointer);

		auto& value = helper->GetValue();

		return value;
	}

	void RenSharpCrateModifierClass::Value::set(float value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DACrateModifierClassHelper*>(InternalDACrateModifierClassPointer);

		auto& _value = helper->GetValue();

		_value = value;
	}
}