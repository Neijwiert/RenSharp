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
#include "Mda_crate.h"

#include "Imports.h"
#include "UnmanagedContainer.h"
#include "MDACrateModifierClassPtrDynamicVectorClass.h"
#include "McPlayer.h"
#include "Mda_cratemanager.h"
#include "RenSharpCrateClass.h"
#include "RenSharpCrateFactoryClass.h"
#include "RenSharpCrateModifierClass.h"
#include "RenSharpCrateModifierFactoryClass.h"

using namespace System::Text;

namespace RenSharp
{
	DACrateModifierFactoryClass::DACrateModifierFactoryClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	String^ DACrateModifierFactoryClass::ToString()
	{
		StringBuilder^ builder = gcnew StringBuilder();
		builder->Append(Name);

		return builder->ToString();
	}

	bool DACrateModifierFactoryClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IRenSharpCrateModifierFactoryClass^ otherThis1 = dynamic_cast<IRenSharpCrateModifierFactoryClass^>(other);
		if (otherThis1 != nullptr && DACrateModifierFactoryClassPointer.Equals(otherThis1->DACrateModifierFactoryClassPointer))
		{
			return true;
		}

		IDACrateModifierFactoryClass^ otherThis2 = dynamic_cast<IDACrateModifierFactoryClass^>(other);
		if (otherThis2 == nullptr)
		{
			return nullptr;
		}

		return DACrateModifierFactoryClassPointer.Equals(otherThis2->DACrateModifierFactoryClassPointer);
	}

	IUnmanagedContainer<IDACrateModifierClass^>^ DACrateModifierFactoryClass::Create(String^ parameters)
	{
		if (parameters == nullptr)
		{
			throw gcnew ArgumentNullException("parameters");
		}

		IntPtr parametersHandle = Marshal::StringToHGlobalAnsi(parameters);
		try
		{
			auto result = InternalDACrateModifierFactoryClassPointer->Create(
				reinterpret_cast<char*>(parametersHandle.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew UnmanagedContainer<IDACrateModifierClass^>(gcnew DACrateModifierClass(IntPtr(result)));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(parametersHandle);
		}
	}

	IRenSharpCrateModifierFactoryClass^ DACrateModifierFactoryClass::AsManagedCrateModifierFactory()
	{
		return DACrateManager::AsManagedCrateModifierFactory(this);
	}

	IntPtr DACrateModifierFactoryClass::DACrateModifierFactoryClassPointer::get()
	{
		return IntPtr(InternalDACrateModifierFactoryClassPointer);
	}

	String^ DACrateModifierFactoryClass::Name::get()
	{
		auto result = InternalDACrateModifierFactoryClassPointer->Get_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	bool DACrateModifierFactoryClass::IsManagedCrateModifierFactory::get()
	{
		return DACrateManager::IsManagedCrateModifierFactory(this);
	}

	bool DACrateModifierFactoryClass::InternalDestroyPointer()
	{
		Imports::DestroyDACrateModifierFactoryClass(InternalDACrateModifierFactoryClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DACrateModifierFactoryClass* DACrateModifierFactoryClass::InternalDACrateModifierFactoryClassPointer::get()
	{
		return reinterpret_cast<::DACrateModifierFactoryClass*>(Pointer.ToPointer());
	}

	DACrateModifierClass::DACrateModifierClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	String^ DACrateModifierClass::ToString()
	{
		StringBuilder^ builder = gcnew StringBuilder();
		builder->Append(Name);

		return builder->ToString();
	}

	bool DACrateModifierClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IRenSharpCrateModifierClass^ otherThis1 = dynamic_cast<IRenSharpCrateModifierClass^>(other);
		if (otherThis1 != nullptr && DACrateModifierClassPointer.Equals(otherThis1->DACrateModifierClassPointer))
		{
			return true;
		}

		IDACrateModifierClass^ otherThis2 = dynamic_cast<IDACrateModifierClass^>(other);
		if (otherThis2 == nullptr)
		{
			return nullptr;
		}

		return DACrateModifierClassPointer.Equals(otherThis2->DACrateModifierClassPointer);
	}

	void DACrateModifierClass::Init(String^ parameters)
	{
		if (parameters == nullptr)
		{
			throw gcnew ArgumentNullException("parameters");
		}

		IntPtr parametersHandle = Marshal::StringToHGlobalAnsi(parameters);
		try
		{
			InternalDACrateModifierClassPointer->Init(
				reinterpret_cast<char*>(parametersHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(parametersHandle);
		}
	}

	void DACrateModifierClass::CalculateOdds(float% odds, IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		float tmpOdds = odds;

		InternalDACrateModifierClassPointer->Calculate_Odds(
			tmpOdds,
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));

		odds = tmpOdds;
	}

	void DACrateModifierClass::ApplyModifier(float% odds)
	{
		float tmpOdds = odds;

		InternalDACrateModifierClassPointer->Apply_Modifier(tmpOdds);

		odds = tmpOdds;
	}

	IRenSharpCrateModifierClass^ DACrateModifierClass::AsManagedCrateModifier()
	{
		return DACrateManager::AsManagedCrateModifier(this);
	}

	IntPtr DACrateModifierClass::DACrateModifierClassPointer::get()
	{
		return IntPtr(InternalDACrateModifierClassPointer);
	}

	bool DACrateModifierClass::IsMultiplicative::get()
	{
		return InternalDACrateModifierClassPointer->Is_Multiplicative();
	}

	bool DACrateModifierClass::IsPositive::get()
	{
		return InternalDACrateModifierClassPointer->Is_Positive();
	}

	IDACrateModifierFactoryClass^ DACrateModifierClass::Factory::get()
	{
		auto result = InternalDACrateModifierClassPointer->Get_Factory();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DACrateModifierFactoryClass(IntPtr(const_cast<::DACrateModifierFactoryClass*>(result)));
		}
	}

	void DACrateModifierClass::Factory::set(IDACrateModifierFactoryClass^ value)
	{
		if (value == nullptr || value->DACrateModifierFactoryClassPointer.ToPointer() == nullptr)
		{
			InternalDACrateModifierClassPointer->Set_Factory(nullptr);
		}
		else
		{
			InternalDACrateModifierClassPointer->Set_Factory(
				reinterpret_cast<::DACrateModifierFactoryClass*>(value->DACrateModifierFactoryClassPointer.ToPointer()));
		}
	}

	String^ DACrateModifierClass::Name::get()
	{
		auto result = InternalDACrateModifierClassPointer->Get_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	bool DACrateModifierClass::IsManagedCrateModifier::get()
	{
		return DACrateManager::IsManagedCrateModifier(this);
	}

	bool DACrateModifierClass::InternalDestroyPointer()
	{
		Imports::DestroyDACrateModifierClass(InternalDACrateModifierClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DACrateModifierClass* DACrateModifierClass::InternalDACrateModifierClassPointer::get()
	{
		return reinterpret_cast<::DACrateModifierClass*>(Pointer.ToPointer());
	}

	float DACrateModifierClass::Value::get()
	{
		auto helper = reinterpret_cast<DACrateModifierClassHelper*>(InternalDACrateModifierClassPointer);

		auto& value = helper->GetValue();

		return value;
	}

	void DACrateModifierClass::Value::set(float value)
	{
		auto helper = reinterpret_cast<DACrateModifierClassHelper*>(InternalDACrateModifierClassPointer);

		auto& _value = helper->GetValue();

		_value = value;
	}

	RenSharp::DACrateModifierOperator DACrateModifierClass::Operator::get()
	{
		auto helper = reinterpret_cast<DACrateModifierClassHelper*>(InternalDACrateModifierClassPointer);

		auto& op = helper->GetOperator();

		return static_cast<RenSharp::DACrateModifierOperator>(op);
	}

	void DACrateModifierClass::Operator::set(RenSharp::DACrateModifierOperator value)
	{
		auto helper = reinterpret_cast<DACrateModifierClassHelper*>(InternalDACrateModifierClassPointer);

		auto& op = helper->GetOperator();

		op = static_cast<::DACrateModifierOperator::Operator>(value);
	}

	DACrateFactoryClass::DACrateFactoryClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	String^ DACrateFactoryClass::ToString()
	{
		StringBuilder^ builder = gcnew StringBuilder();
		builder->Append(Name);

		return builder->ToString();
	}

	bool DACrateFactoryClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IRenSharpCrateFactoryClass^ otherThis1 = dynamic_cast<IRenSharpCrateFactoryClass^>(other);
		if (otherThis1 != nullptr && DACrateFactoryClassPointer.Equals(otherThis1->DACrateFactoryClassPointer))
		{
			return true;
		}

		IDACrateFactoryClass^ otherThis2 = dynamic_cast<IDACrateFactoryClass^>(other);
		if (otherThis2 == nullptr)
		{
			return nullptr;
		}

		return DACrateFactoryClassPointer.Equals(otherThis2->DACrateFactoryClassPointer);
	}

	IDACrateClass^ DACrateFactoryClass::CreateInstance()
	{
		auto result = InternalDACrateFactoryClassPointer->Create_Instance();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DACrateClass(IntPtr(result));
		}
	}

	void DACrateFactoryClass::DestroyInstance()
	{
		InternalDACrateFactoryClassPointer->Destroy_Instance();
	}

	bool DACrateFactoryClass::CheckEnabled()
	{
		return InternalDACrateFactoryClassPointer->Check_Enabled();
	}

	bool DACrateFactoryClass::CheckType(RenSharp::DACrateType type)
	{
		return InternalDACrateFactoryClassPointer->Check_Type(
			static_cast<::DACrateType::Type>(type));
	}

	bool DACrateFactoryClass::CheckEnabledType(RenSharp::DACrateType type)
	{
		return InternalDACrateFactoryClassPointer->Check_Enabled_Type(
			static_cast<::DACrateType::Type>(type));
	}

	IRenSharpCrateFactoryClass^ DACrateFactoryClass::AsManagedCrateFactory()
	{
		return DACrateManager::AsManagedCrateFactory(this);
	}

	IntPtr DACrateFactoryClass::DACrateFactoryClassPointer::get()
	{
		return IntPtr(InternalDACrateFactoryClassPointer);
	}

	String^ DACrateFactoryClass::Name::get()
	{
		auto result = InternalDACrateFactoryClassPointer->Get_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String^ DACrateFactoryClass::Section::get()
	{
		auto result = InternalDACrateFactoryClassPointer->Get_Section();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	void DACrateFactoryClass::Section::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<DACrateFactoryClassHelper*>(InternalDACrateFactoryClassPointer);

		auto& section = helper->GetSection();

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			section = reinterpret_cast<char*>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	RenSharp::DACrateType DACrateFactoryClass::Type::get()
	{
		return static_cast<RenSharp::DACrateType>(InternalDACrateFactoryClassPointer->Get_Type());
	}

	void DACrateFactoryClass::Type::set(RenSharp::DACrateType value)
	{
		auto helper = reinterpret_cast<DACrateFactoryClassHelper*>(InternalDACrateFactoryClassPointer);

		auto& type = helper->GetType();

		type = static_cast<::DACrateType::Type>(value);
	}

	IDACrateClass^ DACrateFactoryClass::Instance::get()
	{
		auto result = InternalDACrateFactoryClassPointer->Get_Instance();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DACrateClass(IntPtr(result));
		}
	}

	void DACrateFactoryClass::Instance::set(IDACrateClass^ value)
	{
		auto helper = reinterpret_cast<DACrateFactoryClassHelper*>(InternalDACrateFactoryClassPointer);

		auto& instance = helper->GetInstance();

		if (value == nullptr || value->DACrateClassPointer.ToPointer() == nullptr)
		{
			instance = nullptr;
		}
		else
		{
			instance = reinterpret_cast<::DACrateClass*>(value->DACrateClassPointer.ToPointer());
		}
	}

	bool DACrateFactoryClass::IsManagedCrateFactory::get()
	{
		return DACrateManager::IsManagedCrateFactory(this);
	}

	bool DACrateFactoryClass::InternalDestroyPointer()
	{
		Imports::DestroyDACrateFactoryClass(InternalDACrateFactoryClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DACrateFactoryClass* DACrateFactoryClass::InternalDACrateFactoryClassPointer::get()
	{
		return reinterpret_cast<::DACrateFactoryClass*>(Pointer.ToPointer());
	}

	DACrateClass::DACrateClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	String^ DACrateClass::ToString()
	{
		StringBuilder^ builder = gcnew StringBuilder();
		builder->Append(Name);

		return builder->ToString();
	}

	bool DACrateClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IRenSharpCrateClass^ otherThis1 = dynamic_cast<IRenSharpCrateClass^>(other);
		if (otherThis1 != nullptr && DACrateClassPointer.Equals(otherThis1->DACrateClassPointer))
		{
			return true;
		}

		IDACrateClass^ otherThis2 = dynamic_cast<IDACrateClass^>(other);
		if (otherThis2 == nullptr)
		{
			return nullptr;
		}

		return DACrateClassPointer.Equals(otherThis2->DACrateClassPointer);
	}

	void DACrateClass::Init()
	{
		InternalDACrateClassPointer->Init();
	}

	void DACrateClass::SettingsLoaded()
	{
		InternalDACrateClassPointer->Settings_Loaded();
	}

	void DACrateClass::CalculateOdds(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		InternalDACrateClassPointer->Calculate_Odds(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	bool DACrateClass::CanActivate(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		return InternalDACrateClassPointer->Can_Activate(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	void DACrateClass::Activate(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		InternalDACrateClassPointer->Activate(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	bool DACrateClass::CheckType(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		return InternalDACrateClassPointer->Check_Type(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	bool DACrateClass::CheckType(RenSharp::DACrateType type)
	{
		return InternalDACrateClassPointer->Check_Type(
			static_cast<::DACrateType::Type>(type));
	}

	void DACrateClass::AdjustOdds(float odds)
	{
		InternalDACrateClassPointer->Adjust_Odds(odds);
	}

	IRenSharpCrateClass^ DACrateClass::AsManagedCrate()
	{
		return DACrateManager::AsManagedCrate(this);
	}

	IntPtr DACrateClass::DACrateClassPointer::get()
	{
		return IntPtr(InternalDACrateClassPointer);
	}

	bool DACrateClass::CapOdds::get()
	{
		return InternalDACrateClassPointer->Get_Cap_Odds();
	}

	void DACrateClass::CapOdds::set(bool value)
	{
		auto helper = reinterpret_cast<DACrateClassHelper*>(InternalDACrateClassPointer);

		auto& capOdds = helper->GetCapOdds();

		capOdds = value;
	}

	float DACrateClass::BaseOdds::get()
	{
		return InternalDACrateClassPointer->Get_Base_Odds();
	}

	void DACrateClass::BaseOdds::set(float value)
	{
		auto helper = reinterpret_cast<DACrateClassHelper*>(InternalDACrateClassPointer);

		auto& baseOdds = helper->GetBaseOdds();

		baseOdds = value;
	}

	float DACrateClass::ModifiedOdds::get()
	{
		return InternalDACrateClassPointer->Get_Modified_Odds();
	}

	void DACrateClass::ModifiedOdds::set(float value)
	{
		auto helper = reinterpret_cast<DACrateClassHelper*>(InternalDACrateClassPointer);

		auto& modifiedOdds = helper->GetModifiedOdds();

		modifiedOdds = value;
	}

	float DACrateClass::FinalOdds::get()
	{
		return InternalDACrateClassPointer->Get_Final_Odds();
	}

	void DACrateClass::FinalOdds::set(float value)
	{
		auto helper = reinterpret_cast<DACrateClassHelper*>(InternalDACrateClassPointer);

		auto& finalOdds = helper->GetFinalOdds();

		finalOdds = value;
	}

	IDACrateFactoryClass^ DACrateClass::Factory::get()
	{
		auto result = InternalDACrateClassPointer->Get_Factory();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DACrateFactoryClass(IntPtr(const_cast<::DACrateFactoryClass*>(result)));
		}
	}

	void DACrateClass::Factory::set(IDACrateFactoryClass^ value)
	{
		if (value == nullptr || value->DACrateFactoryClassPointer.ToPointer() == nullptr)
		{
			InternalDACrateClassPointer->Set_Factory(nullptr);
		}
		else
		{
			InternalDACrateClassPointer->Set_Factory(
				reinterpret_cast<::DACrateFactoryClass*>(value->DACrateFactoryClassPointer.ToPointer()));
		}
	}

	String^ DACrateClass::Name::get()
	{
		auto result = InternalDACrateClassPointer->Get_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String^ DACrateClass::Section::get()
	{
		auto result = InternalDACrateClassPointer->Get_Section();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	RenSharp::DACrateType DACrateClass::Type::get()
	{
		return static_cast<RenSharp::DACrateType>(InternalDACrateClassPointer->Get_Type());
	}

	void DACrateClass::Type::set(RenSharp::DACrateType value)
	{
		auto helper = reinterpret_cast<DACrateClassHelper*>(InternalDACrateClassPointer);

		auto& type = helper->GetType();

		type = static_cast<::DACrateType::Type>(value);
	}

	bool DACrateClass::IsManagedCrate::get()
	{
		return DACrateManager::IsManagedCrate(this);
	}

	bool DACrateClass::InternalDestroyPointer()
	{
		Imports::DestroyDACrateClass(InternalDACrateClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DACrateClass* DACrateClass::InternalDACrateClassPointer::get()
	{
		return reinterpret_cast<::DACrateClass*>(Pointer.ToPointer());
	}

	IDynamicVectorClass<IDACrateModifierClass^>^ DACrateClass::Modifiers::get()
	{
		auto helper = reinterpret_cast<DACrateClassHelper*>(InternalDACrateClassPointer);

		auto& modifiers = helper->GetModifiers();

		return gcnew DACrateModifierClassPtrDynamicVectorClass(IntPtr(&modifiers));
	}

	void DACrateClass::Modifiers::set(IDynamicVectorClass<IDACrateModifierClass^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<DACrateClassHelper*>(InternalDACrateClassPointer);

		auto& modifiers = helper->GetModifiers();

		modifiers = (*reinterpret_cast<::DynamicVectorClass<::DACrateModifierClass*>*>(value->Pointer.ToPointer()));
	}
}