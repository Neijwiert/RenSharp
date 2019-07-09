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
#include "MTeamPurchaseSettingsDefClass.h"

namespace RenSharp
{
	TeamPurchaseSettingsDefClass::TeamPurchaseSettingsDefClass(IntPtr pointer)
		: NetworkObjectClass(pointer)
	{
		definitionClass = gcnew DefinitionClass(DefinitionClassPointer);
	}

	IUnmanagedContainer<IPostLoadableClass^>^ TeamPurchaseSettingsDefClass::CreatePostLoadableClass()
	{
		return PostLoadableClass::CreatePostLoadableClass();
	}

	ITeamPurchaseSettingsDefClass^ TeamPurchaseSettingsDefClass::GetDefinition(ITeamPurchaseSettingsDefClass::TeamEnum team)
	{
		auto result = ::TeamPurchaseSettingsDefClass::Get_Definition(
			static_cast<::TeamPurchaseSettingsDefClass::TEAM>(team));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew TeamPurchaseSettingsDefClass(IntPtr(result));
		}
	}

	int TeamPurchaseSettingsDefClass::TeamToPurchaseTerminalTeam(int team)
	{
		return PTTEAM(team);
	}

	String^ TeamPurchaseSettingsDefClass::ToString()
	{
		return definitionClass->ToString();
	}

	bool TeamPurchaseSettingsDefClass::Equals(Object^ other)
	{
		if (NetworkObjectClass::Equals(other))
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

		auto otherPostLoadableClass = dynamic_cast<IPostLoadableClass^>(other);
		if (otherPostLoadableClass != nullptr)
		{
			if (definitionClass->Equals(otherPostLoadableClass))
			{
				return true;
			}
		}

		auto otherTeamPurchaseSettingsDefClass = dynamic_cast<ITeamPurchaseSettingsDefClass^>(other);
		if (otherTeamPurchaseSettingsDefClass != nullptr)
		{
			if (TeamPurchaseSettingsDefClassPointer.Equals(otherTeamPurchaseSettingsDefClass->TeamPurchaseSettingsDefClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void TeamPurchaseSettingsDefClass::OnPostLoad()
	{
		definitionClass->OnPostLoad();
	}

	bool TeamPurchaseSettingsDefClass::Save(IChunkSaveClass^ csave)
	{
		return definitionClass->Save(csave);
	}

	bool TeamPurchaseSettingsDefClass::Load(IChunkLoadClass^ cload)
	{
		return definitionClass->Load(cload);
	}

	IParameterClass^ TeamPurchaseSettingsDefClass::LockParameter(int index)
	{
		return definitionClass->LockParameter(index);
	}

	void TeamPurchaseSettingsDefClass::UnlockParameter(int index)
	{
		definitionClass->UnlockParameter(index);
	}

	IPersistClass^ TeamPurchaseSettingsDefClass::Create()
	{
		return definitionClass->Create();
	}

	bool TeamPurchaseSettingsDefClass::IsValidConfig([Out] String^% message)
	{
		return definitionClass->IsValidConfig(message);
	}

	String^ TeamPurchaseSettingsDefClass::GetEnlistedName(int index)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalTeamPurchaseSettingsDefClassPointer->Get_Enlisted_Name(index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	unsigned int TeamPurchaseSettingsDefClass::GetEnlistedString(int index)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalTeamPurchaseSettingsDefClassPointer->Get_Enlisted_String(index);
	}

	int TeamPurchaseSettingsDefClass::GetEnlistedCost(int index)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalTeamPurchaseSettingsDefClassPointer->Get_Enlisted_Cost(index);
	}

	int TeamPurchaseSettingsDefClass::GetEnlistedDefinition(int index)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalTeamPurchaseSettingsDefClassPointer->Get_Enlisted_Definition(index);
	}

	String^ TeamPurchaseSettingsDefClass::GetEnlistedTexture(int index)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalTeamPurchaseSettingsDefClassPointer->Get_Enlisted_Texture(index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	bool TeamPurchaseSettingsDefClass::GetHidden(int index)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalTeamPurchaseSettingsDefClassPointer->Get_Hidden(index);
	}

	bool TeamPurchaseSettingsDefClass::GetDisabled(int index)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalTeamPurchaseSettingsDefClassPointer->Get_Disabled(index);
	}

	bool TeamPurchaseSettingsDefClass::GetBusy(int index)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalTeamPurchaseSettingsDefClassPointer->Get_Busy(index);
	}

	void TeamPurchaseSettingsDefClass::SetHidden(int index, bool set)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		InternalTeamPurchaseSettingsDefClassPointer->Set_Hidden(index, set);
	}

	void TeamPurchaseSettingsDefClass::SetDisabled(int index, bool set)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		InternalTeamPurchaseSettingsDefClassPointer->Set_Disabled(index, set);
	}

	void TeamPurchaseSettingsDefClass::SetBusy(int index, bool set)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		InternalTeamPurchaseSettingsDefClassPointer->Set_Busy(index, set);
	}

	void TeamPurchaseSettingsDefClass::SetEnlistedDefinition(int index, int preset)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		InternalTeamPurchaseSettingsDefClassPointer->Set_Enlisted_Definition(index, preset);
	}

	IntPtr TeamPurchaseSettingsDefClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void TeamPurchaseSettingsDefClass::Pointer::set(IntPtr value)
	{
		AbstractUnmanagedObject::Pointer::set(value);

		if (value.ToPointer() == nullptr)
		{
			definitionClass = nullptr;
		}
		else
		{
			definitionClass = gcnew DefinitionClass(DefinitionClassPointer);
		}
	}

	IntPtr TeamPurchaseSettingsDefClass::TeamPurchaseSettingsDefClassPointer::get()
	{
		return IntPtr(InternalTeamPurchaseSettingsDefClassPointer);
	}

	IntPtr TeamPurchaseSettingsDefClass::PostLoadableClassPointer::get()
	{
		return IntPtr(InternalPostLoadableClassPointer);
	}

	IntPtr TeamPurchaseSettingsDefClass::PersistClassPointer::get()
	{
		return IntPtr(InternalPersistClassPointer);
	}

	IntPtr TeamPurchaseSettingsDefClass::EditableClassPointer::get()
	{
		return IntPtr(InternalEditableClassPointer);
	}

	IntPtr TeamPurchaseSettingsDefClass::DefinitionClassPointer::get()
	{
		return IntPtr(InternalDefinitionClassPointer);
	}

	bool TeamPurchaseSettingsDefClass::IsPostLoadRegistered::get()
	{
		return definitionClass->IsPostLoadRegistered;
	}

	void TeamPurchaseSettingsDefClass::IsPostLoadRegistered::set(bool value)
	{
		definitionClass->IsPostLoadRegistered = value;
	}

	IPersistFactoryClass^ TeamPurchaseSettingsDefClass::Factory::get()
	{
		return definitionClass->Factory;
	}

	int TeamPurchaseSettingsDefClass::ParameterCount::get()
	{
		return definitionClass->ParameterCount;
	}

	uint32 TeamPurchaseSettingsDefClass::ClassID::get()
	{
		return definitionClass->ClassID;
	}

	uint32 TeamPurchaseSettingsDefClass::ID::get()
	{
		return definitionClass->ID;
	}

	void TeamPurchaseSettingsDefClass::ID::set(uint32 value)
	{
		definitionClass->ID = value;
	}

	String^ TeamPurchaseSettingsDefClass::Name::get()
	{
		return definitionClass->Name;
	}

	void TeamPurchaseSettingsDefClass::Name::set(String^ value)
	{
		definitionClass->Name = value;
	}

	uint32 TeamPurchaseSettingsDefClass::UserData::get()
	{
		return definitionClass->UserData;
	}

	void TeamPurchaseSettingsDefClass::UserData::set(uint32 value)
	{
		definitionClass->UserData = value;
	}

	bool TeamPurchaseSettingsDefClass::IsSaveEnabled::get()
	{
		return definitionClass->IsSaveEnabled;
	}

	void TeamPurchaseSettingsDefClass::IsSaveEnabled::set(bool value)
	{
		definitionClass->IsSaveEnabled = value;
	}

	ITeamPurchaseSettingsDefClass::TeamEnum TeamPurchaseSettingsDefClass::Team::get()
	{
		return static_cast<ITeamPurchaseSettingsDefClass::TeamEnum>(InternalTeamPurchaseSettingsDefClassPointer->Get_Team());
	}

	unsigned int TeamPurchaseSettingsDefClass::BeaconString::get()
	{
		return InternalTeamPurchaseSettingsDefClassPointer->Get_Beacon_String();
	}

	String^ TeamPurchaseSettingsDefClass::BeaconName::get()
	{
		auto result = InternalTeamPurchaseSettingsDefClassPointer->Get_Beacon_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	int TeamPurchaseSettingsDefClass::BeaconCost::get()
	{
		return InternalTeamPurchaseSettingsDefClassPointer->Get_Beacon_Cost();
	}

	void TeamPurchaseSettingsDefClass::BeaconCost::set(int value)
	{
		InternalTeamPurchaseSettingsDefClassPointer->Set_Beacon_Cost(value);
	}

	int TeamPurchaseSettingsDefClass::BeaconDefinition::get()
	{
		return InternalTeamPurchaseSettingsDefClassPointer->Get_Beacon_Definition();
	}

	void TeamPurchaseSettingsDefClass::BeaconDefinition::set(int value)
	{
		InternalTeamPurchaseSettingsDefClassPointer->Set_Beacon_Definition(value);
	}

	String^ TeamPurchaseSettingsDefClass::BeaconTexture::get()
	{
		auto result = InternalTeamPurchaseSettingsDefClassPointer->Get_Beacon_Texture();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	unsigned int TeamPurchaseSettingsDefClass::SupplyString::get()
	{
		return InternalTeamPurchaseSettingsDefClassPointer->Get_Supply_String();
	}

	String^ TeamPurchaseSettingsDefClass::SupplyName::get()
	{
		auto result = InternalTeamPurchaseSettingsDefClassPointer->Get_Supply_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String^ TeamPurchaseSettingsDefClass::SupplyTexture::get()
	{
		auto result = InternalTeamPurchaseSettingsDefClassPointer->Get_Supply_Texture();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	::NetworkObjectClass* TeamPurchaseSettingsDefClass::InternalNetworkObjectClassPointer::get()
	{
		return InternalTeamPurchaseSettingsDefClassPointer;
	}

	::PostLoadableClass* TeamPurchaseSettingsDefClass::InternalPostLoadableClassPointer::get()
	{
		return InternalTeamPurchaseSettingsDefClassPointer;
	}

	::PersistClass* TeamPurchaseSettingsDefClass::InternalPersistClassPointer::get()
	{
		return InternalTeamPurchaseSettingsDefClassPointer;
	}

	::EditableClass* TeamPurchaseSettingsDefClass::InternalEditableClassPointer::get()
	{
		return InternalTeamPurchaseSettingsDefClassPointer;
	}

	::DefinitionClass* TeamPurchaseSettingsDefClass::InternalDefinitionClassPointer::get()
	{
		return InternalTeamPurchaseSettingsDefClassPointer;
	}

	::TeamPurchaseSettingsDefClass* TeamPurchaseSettingsDefClass::InternalTeamPurchaseSettingsDefClassPointer::get()
	{
		return reinterpret_cast<::TeamPurchaseSettingsDefClass*>(Pointer.ToPointer());
	}

	int TeamPurchaseSettingsDefClass::DefinitionMgrLink::get()
	{
		auto helper = reinterpret_cast<DefinitionClassHelper*>(InternalDefinitionClassPointer);

		auto& definitionMgrLink = helper->GetDefinitionMgrLink();

		return definitionMgrLink;
	}

	void TeamPurchaseSettingsDefClass::DefinitionMgrLink::set(int value)
	{
		auto helper = reinterpret_cast<DefinitionClassHelper*>(InternalDefinitionClassPointer);

		auto& definitionMgrLink = helper->GetDefinitionMgrLink();

		definitionMgrLink = value;
	}
}