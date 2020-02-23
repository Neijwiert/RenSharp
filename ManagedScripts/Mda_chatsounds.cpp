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
#include "Mda_chatsounds.h"

#include "Imports.h"
#include "UnmanagedContainer.h"
#include "MScriptableGameObj.h"
#include "McPlayer.h"
#include "Mda_player.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <engine_da.h>
#include <engine_player.h>
#include <da_chatsounds.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DAChatSoundsPlayerDataClass::DAChatSoundsPlayerDataClass()\
		: DAPlayerDataClass(IntPtr(Imports::CreateDAChatSoundsPlayerDataClass()))
	{

	}

	DAChatSoundsPlayerDataClass::DAChatSoundsPlayerDataClass(IntPtr pointer)
		: DAPlayerDataClass(pointer)
	{

	}

	IUnmanagedContainer<IDAChatSoundsPlayerDataClass^>^ DAChatSoundsPlayerDataClass::CreateDAChatSoundsPlayerDataClass()
	{
		return gcnew UnmanagedContainer<IDAChatSoundsPlayerDataClass^>(gcnew DAChatSoundsPlayerDataClass());
	}

	IntPtr DAChatSoundsPlayerDataClass::DAChatSoundsPlayerDataClassPointer::get()
	{
		return IntPtr(InternalDAChatSoundsPlayerDataClassPointer);
	}

	bool DAChatSoundsPlayerDataClass::Enable::get()
	{
		return InternalDAChatSoundsPlayerDataClassPointer->Enable;
	}

	void DAChatSoundsPlayerDataClass::Enable::set(bool value)
	{
		InternalDAChatSoundsPlayerDataClassPointer->Enable = value;
	}

	bool DAChatSoundsPlayerDataClass::Mute::get()
	{
		return InternalDAChatSoundsPlayerDataClassPointer->Mute;
	}

	void DAChatSoundsPlayerDataClass::Mute::set(bool value)
	{
		InternalDAChatSoundsPlayerDataClassPointer->Mute = value;
	}

	::DAPlayerDataClass* DAChatSoundsPlayerDataClass::InternalDAPlayerDataClassPointer::get()
	{
		return InternalDAChatSoundsPlayerDataClassPointer;
	}

	::DAChatSoundsPlayerDataClass* DAChatSoundsPlayerDataClass::InternalDAChatSoundsPlayerDataClassPointer::get()
	{
		return reinterpret_cast<::DAChatSoundsPlayerDataClass*>(Pointer.ToPointer());
	}

	DAChatSoundsGameFeatureClass::DAChatSoundsGameFeatureClass(IntPtr pointer)
		: DAEventClass(pointer)
	{
		daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
		daPlayerDataFactoryClass = gcnew DAPlayerDataFactoryClass(IntPtr(InternalDAPlayerDataFactoryClassPointer));
	}

	String^ DAChatSoundsGameFeatureClass::ToString()
	{
		return daGameFeatureClass->ToString();
	}

	bool DAChatSoundsGameFeatureClass::Equals(Object^ other)
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

		auto otherDAGameFeatureClass = dynamic_cast<IDAGameFeatureClass^>(other);
		if (otherDAGameFeatureClass != nullptr)
		{
			if (daGameFeatureClass->Equals(otherDAGameFeatureClass))
			{
				return true;
			}
		}

		auto otherDAPlayerDataFactoryClass = dynamic_cast<IDAPlayerDataFactoryClass^>(other);
		if (otherDAPlayerDataFactoryClass != nullptr)
		{
			if (daPlayerDataFactoryClass->Equals(otherDAPlayerDataFactoryClass))
			{
				return true;
			}
		}

		auto otherDAChatSoundsGameFeatureClass = dynamic_cast<IDAChatSoundsGameFeatureClass^>(other);
		if (otherDAChatSoundsGameFeatureClass != nullptr)
		{
			if (DAChatSoundsGameFeatureClassPointer.Equals(otherDAChatSoundsGameFeatureClass->DAChatSoundsGameFeatureClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void DAChatSoundsGameFeatureClass::Init()
	{
		daGameFeatureClass->Init();
	}

	IRenSharpGameFeatureClass^ DAChatSoundsGameFeatureClass::AsManagedGameFeature()
	{
		return daGameFeatureClass->AsManagedGameFeature();
	}

	IUnmanagedContainer<IDAPlayerDataClass^>^ DAChatSoundsGameFeatureClass::CreateData()
	{
		return daPlayerDataFactoryClass->CreateData();
	}

	IRenSharpPlayerDataFactoryClass^ DAChatSoundsGameFeatureClass::AsManagedPlayerDataFactory()
	{
		return daPlayerDataFactoryClass->AsManagedPlayerDataFactory();
	}

	IDAChatSoundsPlayerDataClass^ DAChatSoundsGameFeatureClass::GetPlayerData(int id)
	{
		auto result = InternalDAChatSoundsGameFeatureClassPointer->Get_Player_Data(id);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAChatSoundsPlayerDataClass(IntPtr(result));
		}
	}

	IDAChatSoundsPlayerDataClass^ DAChatSoundsGameFeatureClass::GetPlayerData(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = InternalDAChatSoundsGameFeatureClassPointer->Get_Player_Data(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAChatSoundsPlayerDataClass(IntPtr(result));
		}
	}

	IDAChatSoundsPlayerDataClass^ DAChatSoundsGameFeatureClass::GetPlayerData(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		auto result = InternalDAChatSoundsGameFeatureClassPointer->Get_Player_Data(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAChatSoundsPlayerDataClass(IntPtr(result));
		}
	}

	IDAChatSoundsPlayerDataClass^ DAChatSoundsGameFeatureClass::GetPlayerData(IDAPlayerClass^ player)
	{
		if (player == nullptr || player->DAPlayerClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		auto result = InternalDAChatSoundsGameFeatureClassPointer->Get_Player_Data(
			reinterpret_cast<::DAPlayerClass*>(player->DAPlayerClassPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAChatSoundsPlayerDataClass(IntPtr(result));
		}
	}

	IntPtr DAChatSoundsGameFeatureClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void DAChatSoundsGameFeatureClass::Pointer::set(IntPtr value)
	{
		AbstractUnmanagedObject::Pointer::set(value);

		if (Pointer == IntPtr::Zero)
		{
			daGameFeatureClass = nullptr;
			daPlayerDataFactoryClass = nullptr;
		}
		else
		{
			daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
			daPlayerDataFactoryClass = gcnew DAPlayerDataFactoryClass(IntPtr(InternalDAPlayerDataFactoryClassPointer));
		}
	}

	IntPtr DAChatSoundsGameFeatureClass::DAChatSoundsGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAChatSoundsGameFeatureClassPointer);
	}

	IntPtr DAChatSoundsGameFeatureClass::DAGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAGameFeatureClassPointer);
	}

	IntPtr DAChatSoundsGameFeatureClass::DAPlayerDataFactoryClassPointer::get()
	{
		return IntPtr(InternalDAPlayerDataFactoryClassPointer);
	}

	bool DAChatSoundsGameFeatureClass::IsManagedPlayerDataFactory::get()
	{
		return daPlayerDataFactoryClass->IsManagedPlayerDataFactory;
	}

	String^ DAChatSoundsGameFeatureClass::Name::get()
	{
		return daGameFeatureClass->Name;
	}

	IDAGameFeatureFactoryClass^ DAChatSoundsGameFeatureClass::Factory::get()
	{
		return daGameFeatureClass->Factory;
	}

	void DAChatSoundsGameFeatureClass::Factory::set(IDAGameFeatureFactoryClass^ value)
	{
		daGameFeatureClass->Factory = value;
	}

	bool DAChatSoundsGameFeatureClass::IsManagedGameFeature::get()
	{
		return daGameFeatureClass->IsManagedGameFeature;
	}

	::DAEventClass* DAChatSoundsGameFeatureClass::InternalDAEventClassPointer::get()
	{
		return InternalDAChatSoundsGameFeatureClassPointer;
	}

	::DAGameFeatureClass* DAChatSoundsGameFeatureClass::InternalDAGameFeatureClassPointer::get()
	{
		return InternalDAChatSoundsGameFeatureClassPointer;
	}

	::DAPlayerDataFactoryClass* DAChatSoundsGameFeatureClass::InternalDAPlayerDataFactoryClassPointer::get()
	{
		return InternalDAChatSoundsGameFeatureClassPointer;
	}

	::DAPlayerDataManagerClass<::DAChatSoundsPlayerDataClass>* DAChatSoundsGameFeatureClass::InternalDAPlayerDataManagerClassPointer::get()
	{
		return InternalDAChatSoundsGameFeatureClassPointer;
	}

	::DAChatSoundsGameFeatureClass* DAChatSoundsGameFeatureClass::InternalDAChatSoundsGameFeatureClassPointer::get()
	{
		return reinterpret_cast<::DAChatSoundsGameFeatureClass*>(Pointer.ToPointer());
	}
}