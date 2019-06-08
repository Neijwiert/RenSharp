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
#include "RenSharpCrateClass.h"

#include "Imports.h"
#include "Mda_cratemanager.h"
#include "McPlayer.h"
#include "RenSharpTimerManager.h"
#include "MDACrateModifierClassPtrDynamicVectorClass.h"

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
	RenSharpCrateClass::RenSharpCrateClass()
		:
		disposedResources(false),
		destroyPointer(true),
		daCrateClassPointer(IntPtr::Zero),
		daCrateClass(nullptr)
	{

	}

	RenSharpCrateClass::~RenSharpCrateClass()
	{
		if (disposedResources)
		{
			return;
		}

		DACrateManager::UnregisterManagedCrate(this);

		this->!RenSharpCrateClass();

		disposedResources = true;
	}

	RenSharpCrateClass::!RenSharpCrateClass()
	{
		if (IsAttached)
		{
			auto factory = const_cast<::DACrateFactoryClass*>(InternalDACrateClassPointer->Get_Factory());
			if (factory != nullptr)
			{
				auto helper = reinterpret_cast<DACrateFactoryClassHelper*>(factory);

				auto& instance = helper->GetInstance();
				if (instance == InternalDACrateClassPointer)
				{
					instance = nullptr;
				}
			}

			if (destroyPointer)
			{
				IntPtr tmp = daCrateClassPointer;
				daCrateClassPointer = IntPtr::Zero;
				Imports::DestroyDACrateClass(reinterpret_cast<::DACrateClass*>(tmp.ToPointer()));
			}
		}

		ReleasePointer();
	}

	String^ RenSharpCrateClass::ToString()
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

	bool RenSharpCrateClass::Equals(Object^ other)
	{
		if (ReferenceEquals(other, nullptr))
		{
			return false;
		}

		IDACrateClass^ otherThis1 = dynamic_cast<IDACrateClass^>(other);
		if (otherThis1 != nullptr && daCrateClassPointer.Equals(otherThis1->DACrateClassPointer))
		{
			return true;
		}

		IRenSharpCrateClass^ otherThis2 = dynamic_cast<IRenSharpCrateClass^>(other);
		if (otherThis2 == nullptr)
		{
			return false;
		}

		return daCrateClassPointer.Equals(otherThis2->DACrateClassPointer);
	}

	int RenSharpCrateClass::GetHashCode()
	{
		return daCrateClassPointer.GetHashCode();
	}

	void RenSharpCrateClass::AttachToUnmanagedObject()
	{
		if (IsAttached)
		{
			throw gcnew NotSupportedException("Already attached.");
		}

		daCrateClassPointer = IntPtr(Imports::CreateRenSharpCrateClass());

		daCrateClass = gcnew DACrateClass(daCrateClassPointer);

		UnmanagedAttach();
	}

	void RenSharpCrateClass::RegisterManagedObject()
	{
		DACrateManager::RegisterManagedCrate(this);

		ManagedRegistered();
	}

	void RenSharpCrateClass::ReleasePointer()
	{
		daCrateClassPointer = IntPtr::Zero;
		daCrateClass = nullptr;
	}

	void RenSharpCrateClass::UnmanagedAttach()
	{

	}

	void RenSharpCrateClass::ManagedRegistered()
	{

	}

	IDACrateClass^ RenSharpCrateClass::AsUnmanagedObject()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daCrateClass;
	}

	void RenSharpCrateClass::TimerExpired(int number, Object^ data)
	{

	}

	void RenSharpCrateClass::StartTimer(int number, TimeSpan duration, bool repeat, Object^ data)
	{
		RenSharpTimerManager::StartTimer(this, number, duration, repeat, data);
	}

	void RenSharpCrateClass::StartTimer(int number, TimeSpan duration, bool repeat)
	{
		RenSharpTimerManager::StartTimer(this, number, duration, repeat);
	}

	void RenSharpCrateClass::StartTimer(int number, TimeSpan duration)
	{
		RenSharpTimerManager::StartTimer(this, number, duration);
	}

	void RenSharpCrateClass::StopTimer(int number, Object^ data)
	{
		RenSharpTimerManager::StopTimer(this, number, data);
	}

	void RenSharpCrateClass::StopTimer(int number)
	{
		RenSharpTimerManager::StopTimer(this, number);
	}

	bool RenSharpCrateClass::IsTimer(int number, Object^ data)
	{
		return RenSharpTimerManager::IsTimer(this, number, data);
	}

	bool RenSharpCrateClass::IsTimer(int number)
	{
		return RenSharpTimerManager::IsTimer(this, number);
	}

	void RenSharpCrateClass::ClearTimers()
	{
		RenSharpTimerManager::ClearTimers(this);
	}

	void RenSharpCrateClass::Init()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}
		
		InternalDACrateClassPointer->::DACrateClass::Init();
	}

	void RenSharpCrateClass::SettingsLoaded()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		InternalDACrateClassPointer->::DACrateClass::Settings_Loaded();
	}

	void RenSharpCrateClass::CalculateOdds(IcPlayer^ player)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}
		else if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		InternalDACrateClassPointer->::DACrateClass::Calculate_Odds(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	bool RenSharpCrateClass::CanActivate(IcPlayer^ player)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}
		else if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		return InternalDACrateClassPointer->::DACrateClass::Can_Activate(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	bool RenSharpCrateClass::CheckType(IcPlayer^ player)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daCrateClass->CheckType(player);
	}

	bool RenSharpCrateClass::CheckType(DACrateType type)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daCrateClass->CheckType(type);
	}

	void RenSharpCrateClass::AdjustOdds(float odds)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daCrateClass->AdjustOdds(odds);
	}

	IntPtr RenSharpCrateClass::DACrateClassPointer::get()
	{
		return daCrateClassPointer;
	}

	IntPtr RenSharpCrateClass::Pointer::get()
	{
		return daCrateClassPointer;
	}

	bool RenSharpCrateClass::IsAttached::get()
	{
		return (daCrateClassPointer != IntPtr::Zero);
	}

	bool RenSharpCrateClass::DestroyPointer::get()
	{
		return destroyPointer;
	}

	void RenSharpCrateClass::DestroyPointer::set(bool value)
	{
		destroyPointer = value;
	}

	Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ RenSharpCrateClass::Timers::get()
	{
		return RenSharpTimerManager::GetTimers(this);
	}

	bool RenSharpCrateClass::CapOdds::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daCrateClass->CapOdds;
	}

	void RenSharpCrateClass::CapOdds::set(bool value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DACrateClassHelper*>(InternalDACrateClassPointer);

		auto& capOdds = helper->GetCapOdds();

		capOdds = value;
	}

	float RenSharpCrateClass::BaseOdds::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daCrateClass->BaseOdds;
	}

	void RenSharpCrateClass::BaseOdds::set(float value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DACrateClassHelper*>(InternalDACrateClassPointer);

		auto& baseOdds = helper->GetBaseOdds();

		baseOdds = value;
	}

	float RenSharpCrateClass::ModifiedOdds::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daCrateClass->ModifiedOdds;
	}

	void RenSharpCrateClass::ModifiedOdds::set(float value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DACrateClassHelper*>(InternalDACrateClassPointer);

		auto& modifiedOdds = helper->GetModifiedOdds();

		modifiedOdds = value;
	}

	float RenSharpCrateClass::FinalOdds::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daCrateClass->FinalOdds;
	}

	void RenSharpCrateClass::FinalOdds::set(float value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DACrateClassHelper*>(InternalDACrateClassPointer);

		auto& finalOdds = helper->GetFinalOdds();

		finalOdds = value;
	}

	IDACrateFactoryClass^ RenSharpCrateClass::Factory::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daCrateClass->Factory;
	}

	void RenSharpCrateClass::Factory::set(IDACrateFactoryClass^ value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daCrateClass->Factory = value;
	}

	String^ RenSharpCrateClass::Name::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daCrateClass->Name;
	}

	String^ RenSharpCrateClass::Section::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daCrateClass->Section;
	}

	DACrateType RenSharpCrateClass::Type::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daCrateClass->Type;
	}

	void RenSharpCrateClass::Type::set(DACrateType value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DACrateClassHelper*>(InternalDACrateClassPointer);

		auto& type = helper->GetType();

		type = static_cast<::DACrateType::Type>(value);
	}

	::DACrateClass* RenSharpCrateClass::InternalDACrateClassPointer::get()
	{
		return reinterpret_cast<::DACrateClass*>(daCrateClassPointer.ToPointer());
	}

	IDynamicVectorClass<IDACrateModifierClass^>^ RenSharpCrateClass::Modifiers::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DACrateClassHelper*>(InternalDACrateClassPointer);

		auto& modifiers = helper->GetModifiers();

		return gcnew DACrateModifierClassPtrDynamicVectorClass(IntPtr(&modifiers));
	}

	void RenSharpCrateClass::Modifiers::set(IDynamicVectorClass<IDACrateModifierClass^>^ value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}
		else if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<DACrateClassHelper*>(InternalDACrateClassPointer);

		auto& modifiers = helper->GetModifiers();

		modifiers = *reinterpret_cast<::DynamicVectorClass<::DACrateModifierClass*>*>(value->Pointer.ToPointer());
	}
}