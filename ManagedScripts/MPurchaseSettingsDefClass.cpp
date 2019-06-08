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
#include "MPurchaseSettingsDefClass.h"

namespace RenSharp
{
	PurchaseSettingsDefClass::PurchaseSettingsDefClass(IntPtr pointer)
		: NetworkObjectClass(pointer)
	{
		definitionClass = gcnew DefinitionClass(DefinitionClassPointer);
	}

	IUnmanagedContainer<IPostLoadableClass^>^ PurchaseSettingsDefClass::CreatePostLoadableClass()
	{
		return PostLoadableClass::CreatePostLoadableClass();
	}

	IPurchaseSettingsDefClass^ PurchaseSettingsDefClass::FindDefinition(IPurchaseSettingsDefClass::TypeEnum type, IPurchaseSettingsDefClass::TeamEnum team)
	{
		auto result = ::PurchaseSettingsDefClass::Find_Definition(
			static_cast<::PurchaseSettingsDefClass::TYPE>(type),
			static_cast<::PurchaseSettingsDefClass::TEAM>(team));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PurchaseSettingsDefClass(IntPtr(result));
		}
	}

	int PurchaseSettingsDefClass::TeamToPurchaseTerminalTeam(int team)
	{
		return PTTEAM(team);
	}

	String^ PurchaseSettingsDefClass::ToString()
	{
		return definitionClass->ToString();
	}

	bool PurchaseSettingsDefClass::Equals(Object^ other)
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

		auto otherDefinitionClass = dynamic_cast<IDefinitionClass^>(other);
		if (otherDefinitionClass != nullptr)
		{
			if (definitionClass->DefinitionClassPointer.Equals(otherDefinitionClass->DefinitionClassPointer))
			{
				return true;
			}
		}

		auto otherPurchaseSettingsDefClass = dynamic_cast<IPurchaseSettingsDefClass^>(other);
		if (otherPurchaseSettingsDefClass != nullptr)
		{
			if (PurchaseSettingsDefClassPointer.Equals(otherPurchaseSettingsDefClass->PurchaseSettingsDefClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void PurchaseSettingsDefClass::OnPostLoad()
	{
		definitionClass->OnPostLoad();
	}

	bool PurchaseSettingsDefClass::Save(IChunkSaveClass^ csave)
	{
		return definitionClass->Save(csave);
	}

	bool PurchaseSettingsDefClass::Load(IChunkLoadClass^ cload)
	{
		return definitionClass->Load(cload);
	}

	IParameterClass^ PurchaseSettingsDefClass::LockParameter(int index)
	{
		return definitionClass->LockParameter(index);
	}

	void PurchaseSettingsDefClass::UnlockParameter(int index)
	{
		definitionClass->UnlockParameter(index);
	}

	IPersistClass^ PurchaseSettingsDefClass::Create()
	{
		return definitionClass->Create();
	}

	bool PurchaseSettingsDefClass::IsValidConfig([Out] String^% message)
	{
		return definitionClass->IsValidConfig(message);
	}

	int PurchaseSettingsDefClass::GetDefinition(int index)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalPurchaseSettingsDefClassPointer->Get_Definition(index);
	}

	int PurchaseSettingsDefClass::GetCost(int index)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalPurchaseSettingsDefClassPointer->Get_Cost(index);
	}

	String^ PurchaseSettingsDefClass::GetName(int index)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalPurchaseSettingsDefClassPointer->Get_Name(index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String^ PurchaseSettingsDefClass::GetTexture(int index)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalPurchaseSettingsDefClassPointer->Get_Texture(index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	int PurchaseSettingsDefClass::GetAltDefinition(int index, int index2)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}
		else if (index2 < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index2");
		}

		return InternalPurchaseSettingsDefClassPointer->Get_Alt_Definition(index, index2);
	}

	String^ PurchaseSettingsDefClass::GetAltTexture(int index, int index2)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}
		else if (index2 < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index2");
		}

		auto result = InternalPurchaseSettingsDefClassPointer->Get_Alt_Texture(index, index2);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	int PurchaseSettingsDefClass::GetString(int index)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalPurchaseSettingsDefClassPointer->Get_String(index);
	}

	int PurchaseSettingsDefClass::GetTechLevel(int index)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalPurchaseSettingsDefClassPointer->Get_Tech_Level(index);
	}

	bool PurchaseSettingsDefClass::GetFactoryNotRequired(int index)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalPurchaseSettingsDefClassPointer->Get_Factory_Not_Required(index);
	}

	BuildingType PurchaseSettingsDefClass::GetFactoryBuilding(int index)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return static_cast<BuildingType>(InternalPurchaseSettingsDefClassPointer->Get_Factory_Building(index));
	}

	BuildingType PurchaseSettingsDefClass::GetTechBuilding(int index)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return static_cast<BuildingType>(InternalPurchaseSettingsDefClassPointer->Get_Tech_Building(index));
	}

	void PurchaseSettingsDefClass::SetTechLevel(int index, int level)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		InternalPurchaseSettingsDefClassPointer->Set_Tech_Level(index, level);
	}

	void PurchaseSettingsDefClass::SetFactoryBuilding(int index, BuildingType type)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		InternalPurchaseSettingsDefClassPointer->Set_Factory_Building(
			index,
			static_cast<::BuildingType>(type));
	}

	void PurchaseSettingsDefClass::SetTechBuilding(int index, BuildingType type)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		InternalPurchaseSettingsDefClassPointer->Set_Tech_Building(
			index,
			static_cast<::BuildingType>(type));
	}

	bool PurchaseSettingsDefClass::GetHidden(int index)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalPurchaseSettingsDefClassPointer->Get_Hidden(index);
	}

	bool PurchaseSettingsDefClass::GetDisabled(int index)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalPurchaseSettingsDefClassPointer->Get_Disabled(index);
	}

	bool PurchaseSettingsDefClass::GetBusy(int index)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalPurchaseSettingsDefClassPointer->Get_Busy(index);
	}

	void PurchaseSettingsDefClass::SetHidden(int index, bool set)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		InternalPurchaseSettingsDefClassPointer->Set_Hidden(index, set);
	}

	void PurchaseSettingsDefClass::SetDisabled(int index, bool set)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		InternalPurchaseSettingsDefClassPointer->Set_Disabled(index, set);
	}

	void PurchaseSettingsDefClass::SetBusy(int index, bool set)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		InternalPurchaseSettingsDefClassPointer->Set_Busy(index, set);
	}

	void PurchaseSettingsDefClass::SetDefinition(int index, int preset)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		InternalPurchaseSettingsDefClassPointer->Set_Definition(index, preset);
	}

	void PurchaseSettingsDefClass::SetAltDefinition(int index, int index2, int preset)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}
		else if (index2 < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index2");
		}

		InternalPurchaseSettingsDefClassPointer->Set_Alt_Definition(index, index2, preset);
	}

	void PurchaseSettingsDefClass::SetCost(int index, int cost)
	{
		if (index < 0)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		InternalPurchaseSettingsDefClassPointer->Set_Cost(index, cost);
	}

	IntPtr PurchaseSettingsDefClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void PurchaseSettingsDefClass::Pointer::set(IntPtr value)
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

	IntPtr PurchaseSettingsDefClass::PurchaseSettingsDefClassPointer::get()
	{
		return IntPtr(InternalPurchaseSettingsDefClassPointer);
	}

	IntPtr PurchaseSettingsDefClass::PostLoadableClassPointer::get()
	{
		return IntPtr(InternalPostLoadableClassPointer);
	}

	IntPtr PurchaseSettingsDefClass::PersistClassPointer::get()
	{
		return IntPtr(InternalPersistClassPointer);
	}

	IntPtr PurchaseSettingsDefClass::EditableClassPointer::get()
	{
		return IntPtr(InternalEditableClassPointer);
	}

	IntPtr PurchaseSettingsDefClass::DefinitionClassPointer::get()
	{
		return IntPtr(InternalDefinitionClassPointer);
	}

	bool PurchaseSettingsDefClass::IsPostLoadRegistered::get()
	{
		return definitionClass->IsPostLoadRegistered;
	}

	void PurchaseSettingsDefClass::IsPostLoadRegistered::set(bool value)
	{
		definitionClass->IsPostLoadRegistered = value;
	}

	IPersistFactoryClass^ PurchaseSettingsDefClass::Factory::get()
	{
		return definitionClass->Factory;
	}

	int PurchaseSettingsDefClass::ParameterCount::get()
	{
		return definitionClass->ParameterCount;
	}

	uint32 PurchaseSettingsDefClass::ClassID::get()
	{
		return definitionClass->ClassID;
	}

	uint32 PurchaseSettingsDefClass::ID::get()
	{
		return definitionClass->ID;
	}

	void PurchaseSettingsDefClass::ID::set(uint32 value)
	{
		definitionClass->ID = value;
	}

	String^ PurchaseSettingsDefClass::Name::get()
	{
		return definitionClass->Name;
	}

	void PurchaseSettingsDefClass::Name::set(String^ value)
	{
		definitionClass->Name = value;
	}

	uint32 PurchaseSettingsDefClass::UserData::get()
	{
		return definitionClass->UserData;
	}

	void PurchaseSettingsDefClass::UserData::set(uint32 value)
	{
		definitionClass->UserData = value;
	}

	bool PurchaseSettingsDefClass::IsSaveEnabled::get()
	{
		return definitionClass->IsSaveEnabled;
	}

	void PurchaseSettingsDefClass::IsSaveEnabled::set(bool value)
	{
		definitionClass->IsSaveEnabled = value;
	}

	IPurchaseSettingsDefClass::TeamEnum PurchaseSettingsDefClass::Team::get()
	{
		return static_cast<IPurchaseSettingsDefClass::TeamEnum>(InternalPurchaseSettingsDefClassPointer->Get_Team());
	}

	IPurchaseSettingsDefClass::TypeEnum PurchaseSettingsDefClass::Type::get()
	{
		return static_cast<IPurchaseSettingsDefClass::TypeEnum>(InternalPurchaseSettingsDefClassPointer->Get_Type());
	}

	bool PurchaseSettingsDefClass::PageHidden::get()
	{
		return InternalPurchaseSettingsDefClassPointer->Get_Page_Hidden();
	}

	void PurchaseSettingsDefClass::PageHidden::set(bool value)
	{
		InternalPurchaseSettingsDefClassPointer->Set_Page_Hidden(value);
	}

	bool PurchaseSettingsDefClass::PageDisabled::get()
	{
		return InternalPurchaseSettingsDefClassPointer->Get_Page_Disabled();
	}

	void PurchaseSettingsDefClass::PageDisabled::set(bool value)
	{
		InternalPurchaseSettingsDefClassPointer->Set_Page_Disabled(value);
	}

	bool PurchaseSettingsDefClass::PageBusy::get()
	{
		return InternalPurchaseSettingsDefClassPointer->Get_Page_Busy();
	}

	void PurchaseSettingsDefClass::PageBusy::set(bool value)
	{
		InternalPurchaseSettingsDefClassPointer->Set_Page_Busy(value);
	}

	::NetworkObjectClass* PurchaseSettingsDefClass::InternalNetworkObjectClassPointer::get()
	{
		return InternalPurchaseSettingsDefClassPointer;
	}

	::PostLoadableClass* PurchaseSettingsDefClass::InternalPostLoadableClassPointer::get()
	{
		return InternalPurchaseSettingsDefClassPointer;
	}

	::PersistClass* PurchaseSettingsDefClass::InternalPersistClassPointer::get()
	{
		return InternalPurchaseSettingsDefClassPointer;
	}

	::EditableClass* PurchaseSettingsDefClass::InternalEditableClassPointer::get()
	{
		return InternalPurchaseSettingsDefClassPointer;
	}

	::DefinitionClass* PurchaseSettingsDefClass::InternalDefinitionClassPointer::get()
	{
		return InternalPurchaseSettingsDefClassPointer;
	}

	::PurchaseSettingsDefClass* PurchaseSettingsDefClass::InternalPurchaseSettingsDefClassPointer::get()
	{
		return reinterpret_cast<::PurchaseSettingsDefClass*>(Pointer.ToPointer());
	}

	int PurchaseSettingsDefClass::DefinitionMgrLink::get()
	{
		auto helper = reinterpret_cast<DefinitionClassHelper*>(InternalDefinitionClassPointer);

		auto& definitionMgrLink = helper->GetDefinitionMgrLink();

		return definitionMgrLink;
	}

	void PurchaseSettingsDefClass::DefinitionMgrLink::set(int value)
	{
		auto helper = reinterpret_cast<DefinitionClassHelper*>(InternalDefinitionClassPointer);

		auto& definitionMgrLink = helper->GetDefinitionMgrLink();

		definitionMgrLink = value;
	}
}