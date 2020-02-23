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
#include "Mda_domination.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_domination.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DAControlNodeClass::DAControlNodeClass(IntPtr pointer)
		: DASpawnNodeClass(pointer)
	{

	}

#pragma push_macro("ControlNodeType")
#undef ControlNodeType
	String^ DAControlNodeClass::ControlNodeType::get()
#pragma pop_macro("ControlNodeType")
	{
		return gcnew String(ControlNodeType);
	}

	IntPtr DAControlNodeClass::DAControlNodeClassPointer::get()
	{
		return IntPtr(InternalDAControlNodeClassPointer);
	}

	::DASpawnNodeClass* DAControlNodeClass::InternalDASpawnNodeClassPointer::get()
	{
		return InternalDAControlNodeClassPointer;
	}

	::DAControlNodeClass* DAControlNodeClass::InternalDAControlNodeClassPointer::get()
	{
		return reinterpret_cast<::DAControlNodeClass*>(Pointer.ToPointer());
	}

	DATiberiumNodeClass::DATiberiumNodeClass(IntPtr pointer)
		: DABaseNodeClass(pointer)
	{

	}

#pragma push_macro("TiberiumNodeType")
#undef TiberiumNodeType
	String^ DATiberiumNodeClass::TiberiumNodeType::get()
#pragma pop_macro("TiberiumNodeType")
	{
		return gcnew String(TiberiumNodeType);
	}

	IntPtr DATiberiumNodeClass::DATiberiumNodeClassPointer::get()
	{
		return IntPtr(InternalDATiberiumNodeClassPointer);
	}

	::DABaseNodeClass* DATiberiumNodeClass::InternalDABaseNodeClassPointer::get()
	{
		return InternalDATiberiumNodeClassPointer;
	}

	::DATiberiumNodeClass* DATiberiumNodeClass::InternalDATiberiumNodeClassPointer::get()
	{
		return reinterpret_cast<::DATiberiumNodeClass*>(Pointer.ToPointer());
	}

	DADominationManagerClass::DADominationManagerClass(IntPtr pointer)
		: DAEventClass(pointer)
	{
		daGameModeClass = gcnew DAGameModeClass(IntPtr(InternalDAGameModeClassPointer));
	}

	String^ DADominationManagerClass::ToString()
	{
		return daGameModeClass->ToString();
	}

	bool DADominationManagerClass::Equals(Object^ other)
	{
		if (DAEventClass::Equals(other))
		{
			return true;
		}

		if (ReferenceEquals(other, nullptr))
		{
			return false;
		}

		auto otherUnmanagedObj = dynamic_cast<IUnmanagedObject^>(other);
		if (otherUnmanagedObj == nullptr || otherUnmanagedObj->Pointer.Equals(IntPtr::Zero))
		{
			return false;
		}

		auto otherDAGameModeClass = dynamic_cast<IDAGameModeClass^>(other);
		if (otherDAGameModeClass != nullptr)
		{
			if (daGameModeClass->Equals(otherDAGameModeClass))
			{
				return true;
			}
		}

		auto otherDADominationManagerClass = dynamic_cast<IDADominationManagerClass^>(other);
		if (otherDADominationManagerClass != nullptr)
		{
			if (DADominationManagerClassPointer.Equals(otherDADominationManagerClass->DADominationManagerClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void DADominationManagerClass::Init()
	{
		daGameModeClass->Init();
	}

	IRenSharpGameModeClass^ DADominationManagerClass::AsManagedGameMode()
	{
		return daGameModeClass->AsManagedGameMode();
	}

	void DADominationManagerClass::IncrementCredits(int team)
	{
		InternalDADominationManagerClassPointer->Increment_Credits(team);
	}

	IntPtr DADominationManagerClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void DADominationManagerClass::Pointer::set(IntPtr value)
	{
		AbstractUnmanagedObject::Pointer::set(value);

		if (Pointer == IntPtr::Zero)
		{
			daGameModeClass = nullptr;
		}
		else
		{
			daGameModeClass = gcnew DAGameModeClass(IntPtr(InternalDAGameModeClassPointer));
		}
	}

	IntPtr DADominationManagerClass::DADominationManagerClassPointer::get()
	{
		return IntPtr(InternalDADominationManagerClassPointer);
	}

	IntPtr DADominationManagerClass::DAGameModeClassPointer::get()
	{
		return IntPtr(InternalDAGameModeClassPointer);
	}

	String^ DADominationManagerClass::LongName::get()
	{
		return daGameModeClass->LongName;
	}

	String^ DADominationManagerClass::ShortName::get()
	{
		return daGameModeClass->ShortName;
	}

	IDAGameModeFactoryClass^ DADominationManagerClass::Factory::get()
	{
		return daGameModeClass->Factory;
	}

	void DADominationManagerClass::Factory::set(IDAGameModeFactoryClass^ value)
	{
		daGameModeClass->Factory = value;
	}

	bool DADominationManagerClass::IsManagedGameMode::get()
	{
		return daGameModeClass->IsManagedGameMode;
	}

	String^ DADominationManagerClass::ControlNodePreset::get()
	{
		return gcnew String(InternalDADominationManagerClassPointer->Get_Control_Node_Preset().Peek_Buffer());
	}

	String^ DADominationManagerClass::ControlNodeModel::get()
	{
		return gcnew String(InternalDADominationManagerClassPointer->Get_Control_Node_Model().Peek_Buffer());
	}

	String^ DADominationManagerClass::ControlNodeAnimation::get()
	{
		return gcnew String(InternalDADominationManagerClassPointer->Get_Control_Node_Animation().Peek_Buffer());
	}

	String^ DADominationManagerClass::TiberiumNodePreset::get()
	{
		return gcnew String(InternalDADominationManagerClassPointer->Get_Tiberium_Node_Preset().Peek_Buffer());
	}

	String^ DADominationManagerClass::TiberiumNodeModel::get()
	{
		return gcnew String(InternalDADominationManagerClassPointer->Get_Tiberium_Node_Model().Peek_Buffer());
	}

	String^ DADominationManagerClass::TiberiumNodeAnimation::get()
	{
		return gcnew String(InternalDADominationManagerClassPointer->Get_Tiberium_Node_Animation().Peek_Buffer());
	}

	float DADominationManagerClass::PointTickAmount::get()
	{
		return InternalDADominationManagerClassPointer->Get_Point_Tick_Amount();
	}

	TimeSpan DADominationManagerClass::PointTickTime::get()
	{
		return TimeSpan::FromSeconds(InternalDADominationManagerClassPointer->Get_Point_Tick_Time());
	}

	float DADominationManagerClass::CreditTickAmount::get()
	{
		return InternalDADominationManagerClassPointer->Get_Credit_Tick_Amount();
	}

	TimeSpan DADominationManagerClass::CreditTickTime::get()
	{
		return TimeSpan::FromSeconds(InternalDADominationManagerClassPointer->Get_Credit_Tick_Time());
	}

	::DAEventClass* DADominationManagerClass::InternalDAEventClassPointer::get()
	{
		return InternalDADominationManagerClassPointer;
	}

	::DAGameModeClass* DADominationManagerClass::InternalDAGameModeClassPointer::get()
	{
		return InternalDADominationManagerClassPointer;
	}

	::DADominationManagerClass* DADominationManagerClass::InternalDADominationManagerClassPointer::get()
	{
		return reinterpret_cast<::DADominationManagerClass*>(Pointer.ToPointer());
	}
}