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
#include "Mda_characterrefunds.h"

#include "Imports.h"
#include "UnmanagedContainer.h"
#include "MSoldierGameObjDef.h"
#include "MScriptableGameObj.h"
#include "McPlayer.h"
#include "Mda_player.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <engine_da.h>
#include <engine_player.h>
#include <da_characterrefunds.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DACharacterRefundsPlayerDataClass::DACharacterRefundsPlayerDataClass()\
		: DAPlayerDataClass(IntPtr(Imports::CreateDACharacterRefundsPlayerDataClass()))
	{

	}

	DACharacterRefundsPlayerDataClass::DACharacterRefundsPlayerDataClass(IntPtr pointer)
		: DAPlayerDataClass(pointer)
	{

	}

	IUnmanagedContainer<IDACharacterRefundsPlayerDataClass^>^ DACharacterRefundsPlayerDataClass::CreateDACharacterRefundsPlayerDataClass()
	{
		return gcnew UnmanagedContainer<IDACharacterRefundsPlayerDataClass^>(gcnew DACharacterRefundsPlayerDataClass());
	}

	IntPtr DACharacterRefundsPlayerDataClass::DACharacterRefundsPlayerDataClassPointer::get()
	{
		return IntPtr(InternalDACharacterRefundsPlayerDataClassPointer);
	}

	float DACharacterRefundsPlayerDataClass::Cost::get()
	{
		return InternalDACharacterRefundsPlayerDataClassPointer->Cost;
	}

	void DACharacterRefundsPlayerDataClass::Cost::set(float value)
	{
		InternalDACharacterRefundsPlayerDataClassPointer->Cost = value;
	}

	ISoldierGameObjDef^ DACharacterRefundsPlayerDataClass::Def::get()
	{
		auto result = InternalDACharacterRefundsPlayerDataClassPointer->Def;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SoldierGameObjDef(IntPtr(const_cast<::SoldierGameObjDef*>(result)));
		}
	}

	void DACharacterRefundsPlayerDataClass::Def::set(ISoldierGameObjDef^ value)
	{
		if (value == nullptr || value->SoldierGameObjDefPointer.ToPointer() == nullptr)
		{
			InternalDACharacterRefundsPlayerDataClassPointer->Def = nullptr;
		}
		else
		{
			InternalDACharacterRefundsPlayerDataClassPointer->Def = reinterpret_cast<::SoldierGameObjDef*>(value->SoldierGameObjDefPointer.ToPointer());
		}
	}

	::DAPlayerDataClass* DACharacterRefundsPlayerDataClass::InternalDAPlayerDataClassPointer::get()
	{
		return InternalDACharacterRefundsPlayerDataClassPointer;
	}

	::DACharacterRefundsPlayerDataClass* DACharacterRefundsPlayerDataClass::InternalDACharacterRefundsPlayerDataClassPointer::get()
	{
		return reinterpret_cast<::DACharacterRefundsPlayerDataClass*>(Pointer.ToPointer());
	}

	DACharacterRefundsGameFeatureClass::DACharacterRefundsGameFeatureClass(IntPtr pointer)
		: DAEventClass(pointer)
	{
		daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
		daPlayerDataFactoryClass = gcnew DAPlayerDataFactoryClass(IntPtr(InternalDAPlayerDataFactoryClassPointer));
	}

	String^ DACharacterRefundsGameFeatureClass::ToString()
	{
		return daGameFeatureClass->ToString();
	}

	bool DACharacterRefundsGameFeatureClass::Equals(Object^ other)
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

		auto otherDACharacterRefundsGameFeatureClass = dynamic_cast<IDACharacterRefundsGameFeatureClass^>(other);
		if (otherDACharacterRefundsGameFeatureClass != nullptr)
		{
			if (DACharacterRefundsGameFeatureClassPointer.Equals(otherDACharacterRefundsGameFeatureClass->DACharacterRefundsGameFeatureClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void DACharacterRefundsGameFeatureClass::Init()
	{
		daGameFeatureClass->Init();
	}

	IRenSharpGameFeatureClass^ DACharacterRefundsGameFeatureClass::AsManagedGameFeature()
	{
		return daGameFeatureClass->AsManagedGameFeature();
	}

	IUnmanagedContainer<IDAPlayerDataClass^>^ DACharacterRefundsGameFeatureClass::CreateData()
	{
		return daPlayerDataFactoryClass->CreateData();
	}

	IRenSharpPlayerDataFactoryClass^ DACharacterRefundsGameFeatureClass::AsManagedPlayerDataFactory()
	{
		return daPlayerDataFactoryClass->AsManagedPlayerDataFactory();
	}

	IDACharacterRefundsPlayerDataClass^ DACharacterRefundsGameFeatureClass::GetPlayerData(int id)
	{
		auto result = InternalDACharacterRefundsGameFeatureClassPointer->Get_Player_Data(id);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DACharacterRefundsPlayerDataClass(IntPtr(result));
		}
	}

	IDACharacterRefundsPlayerDataClass^ DACharacterRefundsGameFeatureClass::GetPlayerData(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = InternalDACharacterRefundsGameFeatureClassPointer->Get_Player_Data(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DACharacterRefundsPlayerDataClass(IntPtr(result));
		}
	}

	IDACharacterRefundsPlayerDataClass^ DACharacterRefundsGameFeatureClass::GetPlayerData(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		auto result = InternalDACharacterRefundsGameFeatureClassPointer->Get_Player_Data(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DACharacterRefundsPlayerDataClass(IntPtr(result));
		}
	}

	IDACharacterRefundsPlayerDataClass^ DACharacterRefundsGameFeatureClass::GetPlayerData(IDAPlayerClass^ player)
	{
		if (player == nullptr || player->DAPlayerClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		auto result = InternalDACharacterRefundsGameFeatureClassPointer->Get_Player_Data(
			reinterpret_cast<::DAPlayerClass*>(player->DAPlayerClassPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DACharacterRefundsPlayerDataClass(IntPtr(result));
		}
	}

	IntPtr DACharacterRefundsGameFeatureClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void DACharacterRefundsGameFeatureClass::Pointer::set(IntPtr value)
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

	IntPtr DACharacterRefundsGameFeatureClass::DACharacterRefundsGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDACharacterRefundsGameFeatureClassPointer);
	}

	IntPtr DACharacterRefundsGameFeatureClass::DAGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAGameFeatureClassPointer);
	}

	IntPtr DACharacterRefundsGameFeatureClass::DAPlayerDataFactoryClassPointer::get()
	{
		return IntPtr(InternalDAPlayerDataFactoryClassPointer);
	}

	bool DACharacterRefundsGameFeatureClass::IsManagedPlayerDataFactory::get()
	{
		return daPlayerDataFactoryClass->IsManagedPlayerDataFactory;
	}

	String^ DACharacterRefundsGameFeatureClass::Name::get()
	{
		return daGameFeatureClass->Name;
	}

	IDAGameFeatureFactoryClass^ DACharacterRefundsGameFeatureClass::Factory::get()
	{
		return daGameFeatureClass->Factory;
	}

	void DACharacterRefundsGameFeatureClass::Factory::set(IDAGameFeatureFactoryClass^ value)
	{
		daGameFeatureClass->Factory = value;
	}

	bool DACharacterRefundsGameFeatureClass::IsManagedGameFeature::get()
	{
		return daGameFeatureClass->IsManagedGameFeature;
	}

	::DAEventClass* DACharacterRefundsGameFeatureClass::InternalDAEventClassPointer::get()
	{
		return InternalDACharacterRefundsGameFeatureClassPointer;
	}

	::DAGameFeatureClass* DACharacterRefundsGameFeatureClass::InternalDAGameFeatureClassPointer::get()
	{
		return InternalDACharacterRefundsGameFeatureClassPointer;
	}

	::DAPlayerDataFactoryClass* DACharacterRefundsGameFeatureClass::InternalDAPlayerDataFactoryClassPointer::get()
	{
		return InternalDACharacterRefundsGameFeatureClassPointer;
	}

	::DAPlayerDataManagerClass<::DACharacterRefundsPlayerDataClass>* DACharacterRefundsGameFeatureClass::InternalDAPlayerDataManagerClassPointer::get()
	{
		return InternalDACharacterRefundsGameFeatureClassPointer;
	}

	::DACharacterRefundsGameFeatureClass* DACharacterRefundsGameFeatureClass::InternalDACharacterRefundsGameFeatureClassPointer::get()
	{
		return reinterpret_cast<::DACharacterRefundsGameFeatureClass*>(Pointer.ToPointer());
	}
}