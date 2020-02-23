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
#include "Mda_radio.h"

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
#include <da_radio.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DAExtraRadioCommandsPlayerDataClass::DAExtraRadioCommandsPlayerDataClass()\
		: DAPlayerDataClass(IntPtr(Imports::CreateDAExtraRadioCommandsPlayerDataClass()))
	{

	}

	DAExtraRadioCommandsPlayerDataClass::DAExtraRadioCommandsPlayerDataClass(IntPtr pointer)
		: DAPlayerDataClass(pointer)
	{

	}

	IUnmanagedContainer<IDAExtraRadioCommandsPlayerDataClass^>^ DAExtraRadioCommandsPlayerDataClass::CreateDAExtraRadioCommandsPlayerDataClass()
	{
		return gcnew UnmanagedContainer<IDAExtraRadioCommandsPlayerDataClass^>(gcnew DAExtraRadioCommandsPlayerDataClass());
	}

	IntPtr DAExtraRadioCommandsPlayerDataClass::DAExtraRadioCommandsPlayerDataClassPointer::get()
	{
		return IntPtr(InternalDAExtraRadioCommandsPlayerDataClassPointer);
	}

	IScriptableGameObj^ DAExtraRadioCommandsPlayerDataClass::LastDamage::get()
	{
		auto result = InternalDAExtraRadioCommandsPlayerDataClassPointer->Get_Last_Damage();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptableGameObj(IntPtr(result));
		}
	}

	void DAExtraRadioCommandsPlayerDataClass::LastDamage::set(IScriptableGameObj^ value)
	{
		if (value == nullptr || value->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			InternalDAExtraRadioCommandsPlayerDataClassPointer->Set_Last_Damage(nullptr);
		}
		else
		{
			InternalDAExtraRadioCommandsPlayerDataClassPointer->Set_Last_Damage(
				reinterpret_cast<::ScriptableGameObj*>(value->ScriptableGameObjPointer.ToPointer()));
		}
	}

	::DAPlayerDataClass* DAExtraRadioCommandsPlayerDataClass::InternalDAPlayerDataClassPointer::get()
	{
		return InternalDAExtraRadioCommandsPlayerDataClassPointer;
	}

	::DAExtraRadioCommandsPlayerDataClass* DAExtraRadioCommandsPlayerDataClass::InternalDAExtraRadioCommandsPlayerDataClassPointer::get()
	{
		return reinterpret_cast<::DAExtraRadioCommandsPlayerDataClass*>(Pointer.ToPointer());
	}

	DAExtraRadioCommandsGameFeatureClass::DAExtraRadioCommandsGameFeatureClass(IntPtr pointer)
		: DAEventClass(pointer)
	{
		daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
		daPlayerDataFactoryClass = gcnew DAPlayerDataFactoryClass(IntPtr(InternalDAPlayerDataFactoryClassPointer));
	}

	String^ DAExtraRadioCommandsGameFeatureClass::ToString()
	{
		return daGameFeatureClass->ToString();
	}

	bool DAExtraRadioCommandsGameFeatureClass::Equals(Object^ other)
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

		auto otherDAExtraRadioCommandsGameFeatureClass = dynamic_cast<IDAExtraRadioCommandsGameFeatureClass^>(other);
		if (otherDAExtraRadioCommandsGameFeatureClass != nullptr)
		{
			if (DAExtraRadioCommandsGameFeatureClassPointer.Equals(otherDAExtraRadioCommandsGameFeatureClass->DAExtraRadioCommandsGameFeatureClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void DAExtraRadioCommandsGameFeatureClass::Init()
	{
		daGameFeatureClass->Init();
	}

	IRenSharpGameFeatureClass^ DAExtraRadioCommandsGameFeatureClass::AsManagedGameFeature()
	{
		return daGameFeatureClass->AsManagedGameFeature();
	}

	IUnmanagedContainer<IDAPlayerDataClass^>^ DAExtraRadioCommandsGameFeatureClass::CreateData()
	{
		return daPlayerDataFactoryClass->CreateData();
	}

	IRenSharpPlayerDataFactoryClass^ DAExtraRadioCommandsGameFeatureClass::AsManagedPlayerDataFactory()
	{
		return daPlayerDataFactoryClass->AsManagedPlayerDataFactory();
	}

	IDAExtraRadioCommandsPlayerDataClass^ DAExtraRadioCommandsGameFeatureClass::GetPlayerData(int id)
	{
		auto result = InternalDAExtraRadioCommandsGameFeatureClassPointer->Get_Player_Data(id);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAExtraRadioCommandsPlayerDataClass(IntPtr(result));
		}
	}

	IDAExtraRadioCommandsPlayerDataClass^ DAExtraRadioCommandsGameFeatureClass::GetPlayerData(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = InternalDAExtraRadioCommandsGameFeatureClassPointer->Get_Player_Data(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAExtraRadioCommandsPlayerDataClass(IntPtr(result));
		}
	}

	IDAExtraRadioCommandsPlayerDataClass^ DAExtraRadioCommandsGameFeatureClass::GetPlayerData(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		auto result = InternalDAExtraRadioCommandsGameFeatureClassPointer->Get_Player_Data(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAExtraRadioCommandsPlayerDataClass(IntPtr(result));
		}
	}

	IDAExtraRadioCommandsPlayerDataClass^ DAExtraRadioCommandsGameFeatureClass::GetPlayerData(IDAPlayerClass^ player)
	{
		if (player == nullptr || player->DAPlayerClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		auto result = InternalDAExtraRadioCommandsGameFeatureClassPointer->Get_Player_Data(
			reinterpret_cast<::DAPlayerClass*>(player->DAPlayerClassPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAExtraRadioCommandsPlayerDataClass(IntPtr(result));
		}
	}

	IntPtr DAExtraRadioCommandsGameFeatureClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void DAExtraRadioCommandsGameFeatureClass::Pointer::set(IntPtr value)
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

	IntPtr DAExtraRadioCommandsGameFeatureClass::DAExtraRadioCommandsGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAExtraRadioCommandsGameFeatureClassPointer);
	}

	IntPtr DAExtraRadioCommandsGameFeatureClass::DAGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAGameFeatureClassPointer);
	}

	IntPtr DAExtraRadioCommandsGameFeatureClass::DAPlayerDataFactoryClassPointer::get()
	{
		return IntPtr(InternalDAPlayerDataFactoryClassPointer);
	}

	bool DAExtraRadioCommandsGameFeatureClass::IsManagedPlayerDataFactory::get()
	{
		return daPlayerDataFactoryClass->IsManagedPlayerDataFactory;
	}

	String^ DAExtraRadioCommandsGameFeatureClass::Name::get()
	{
		return daGameFeatureClass->Name;
	}

	IDAGameFeatureFactoryClass^ DAExtraRadioCommandsGameFeatureClass::Factory::get()
	{
		return daGameFeatureClass->Factory;
	}

	void DAExtraRadioCommandsGameFeatureClass::Factory::set(IDAGameFeatureFactoryClass^ value)
	{
		daGameFeatureClass->Factory = value;
	}

	bool DAExtraRadioCommandsGameFeatureClass::IsManagedGameFeature::get()
	{
		return daGameFeatureClass->IsManagedGameFeature;
	}

	::DAEventClass* DAExtraRadioCommandsGameFeatureClass::InternalDAEventClassPointer::get()
	{
		return InternalDAExtraRadioCommandsGameFeatureClassPointer;
	}

	::DAGameFeatureClass* DAExtraRadioCommandsGameFeatureClass::InternalDAGameFeatureClassPointer::get()
	{
		return InternalDAExtraRadioCommandsGameFeatureClassPointer;
	}

	::DAPlayerDataFactoryClass* DAExtraRadioCommandsGameFeatureClass::InternalDAPlayerDataFactoryClassPointer::get()
	{
		return InternalDAExtraRadioCommandsGameFeatureClassPointer;
	}

	::DAPlayerDataManagerClass<::DAExtraRadioCommandsPlayerDataClass>* DAExtraRadioCommandsGameFeatureClass::InternalDAPlayerDataManagerClassPointer::get()
	{
		return InternalDAExtraRadioCommandsGameFeatureClassPointer;
	}

	::DAExtraRadioCommandsGameFeatureClass* DAExtraRadioCommandsGameFeatureClass::InternalDAExtraRadioCommandsGameFeatureClassPointer::get()
	{
		return reinterpret_cast<::DAExtraRadioCommandsGameFeatureClass*>(Pointer.ToPointer());
	}
}