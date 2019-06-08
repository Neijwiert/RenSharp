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
#include "Mda_rtc.h"

#include "Imports.h"
#include "McPlayer.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <engine_da.h>
#include <engine_player.h>
#include <engine_game.h>
#include <da_rtc.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DARTCStruct::DARTCStruct()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateDARTCStruct1()))
	{

	}

	DARTCStruct::DARTCStruct(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			Pointer = IntPtr(Imports::CreateDARTCStruct2(nullptr));
		}
		else
		{
			Pointer = IntPtr(Imports::CreateDARTCStruct2(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer())));
		}
	}

	DARTCStruct::DARTCStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IDARTCStruct^>^ DARTCStruct::CreateDARTCStruct()
	{
		return gcnew UnmanagedContainer<IDARTCStruct^>(gcnew DARTCStruct());
	}

	IUnmanagedContainer<IDARTCStruct^>^ DARTCStruct::CreateDARTCStruct(IcPlayer^ player)
	{
		return gcnew UnmanagedContainer<IDARTCStruct^>(gcnew DARTCStruct(player));
	}

	bool DARTCStruct::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDARTCStruct^ otherThis = dynamic_cast<IDARTCStruct^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DARTCStructPointer.Equals(otherThis->DARTCStructPointer);
	}

	IntPtr DARTCStruct::DARTCStructPointer::get()
	{
		return IntPtr(InternalDARTCStructPointer);
	}

	IcPlayer^ DARTCStruct::Player::get()
	{
		auto result = InternalDARTCStructPointer->Player;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	void DARTCStruct::Player::set(IcPlayer^ value)
	{
		if (value == nullptr || value->cPlayerPointer.ToPointer() == nullptr)
		{
			InternalDARTCStructPointer->Player = nullptr;
		}
		else
		{
			InternalDARTCStructPointer->Player = reinterpret_cast<::cPlayer*>(value->cPlayerPointer.ToPointer());
		}
	}

	unsigned int DARTCStruct::Timeout::get()
	{
		return InternalDARTCStructPointer->Timeout;
	}

	void DARTCStruct::Timeout::set(unsigned int value)
	{
		InternalDARTCStructPointer->Timeout = value;
	}

	bool DARTCStruct::InternalDestroyPointer()
	{
		Imports::DestroyDARTCStruct(InternalDARTCStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DARTCStruct* DARTCStruct::InternalDARTCStructPointer::get()
	{
		return reinterpret_cast<::DARTCStruct*>(Pointer.ToPointer());
	}

	DARTCPlayerDataClass::DARTCPlayerDataClass()
		: DAPlayerDataClass(IntPtr(Imports::CreateDARTCPlayerDataClass()))
	{

	}

	DARTCPlayerDataClass::DARTCPlayerDataClass(IntPtr pointer)
		: DAPlayerDataClass(pointer)
	{

	}

	IUnmanagedContainer<IDARTCPlayerDataClass^>^ DARTCPlayerDataClass::CreateDARTCPlayerDataClass()
	{
		return gcnew UnmanagedContainer<IDARTCPlayerDataClass^>(gcnew DARTCPlayerDataClass());
	}

	IntPtr DARTCPlayerDataClass::DARTCPlayerDataClassPointer::get()
	{
		return IntPtr(InternalDARTCPlayerDataClassPointer);
	}

	bool DARTCPlayerDataClass::CanRTC::get()
	{
		return InternalDARTCPlayerDataClassPointer->CanRTC;
	}

	void DARTCPlayerDataClass::CanRTC::set(bool value)
	{
		InternalDARTCPlayerDataClassPointer->CanRTC = value;
	}

	::DAPlayerDataClass* DARTCPlayerDataClass::InternalDAPlayerDataClassPointer::get()
	{
		return InternalDARTCPlayerDataClassPointer;
	}

	::DARTCPlayerDataClass* DARTCPlayerDataClass::InternalDARTCPlayerDataClassPointer::get()
	{
		return reinterpret_cast<::DARTCPlayerDataClass*>(Pointer.ToPointer());
	}

	DARTCGameFeatureClass::DARTCGameFeatureClass(IntPtr pointer)
		: DAEventClass(pointer)
	{
		daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
	}

	String^ DARTCGameFeatureClass::ToString()
	{
		return daGameFeatureClass->ToString();
	}

	bool DARTCGameFeatureClass::Equals(Object^ other)
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
			if (daGameFeatureClass->DAGameFeatureClassPointer.Equals(otherDAGameFeatureClass->DAGameFeatureClassPointer))
			{
				return true;
			}
		}

		auto otherDARTCGameFeatureClass = dynamic_cast<IDARTCGameFeatureClass^>(other);
		if (otherDARTCGameFeatureClass != nullptr)
		{
			if (DARTCGameFeatureClassPointer.Equals(otherDARTCGameFeatureClass->DARTCGameFeatureClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void DARTCGameFeatureClass::Init()
	{
		daGameFeatureClass->Init();
	}

	IRenSharpGameFeatureClass^ DARTCGameFeatureClass::AsManagedGameFeature()
	{
		return daGameFeatureClass->AsManagedGameFeature();
	}

	IntPtr DARTCGameFeatureClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void DARTCGameFeatureClass::Pointer::set(IntPtr value)
	{
		AbstractUnmanagedObject::Pointer::set(value);

		if (Pointer == IntPtr::Zero)
		{
			daGameFeatureClass = nullptr;
		}
		else
		{
			daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
		}
	}

	IntPtr DARTCGameFeatureClass::DARTCGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDARTCGameFeatureClassPointer);
	}

	IntPtr DARTCGameFeatureClass::DAGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAGameFeatureClassPointer);
	}

	String^ DARTCGameFeatureClass::Name::get()
	{
		return daGameFeatureClass->Name;
	}

	IDAGameFeatureFactoryClass^ DARTCGameFeatureClass::Factory::get()
	{
		return daGameFeatureClass->Factory;
	}

	void DARTCGameFeatureClass::Factory::set(IDAGameFeatureFactoryClass^ value)
	{
		daGameFeatureClass->Factory = value;
	}

	bool DARTCGameFeatureClass::IsManagedGameFeature::get()
	{
		return daGameFeatureClass->IsManagedGameFeature;
	}

	::DAEventClass* DARTCGameFeatureClass::InternalDAEventClassPointer::get()
	{
		return InternalDARTCGameFeatureClassPointer;
	}

	::DAGameFeatureClass* DARTCGameFeatureClass::InternalDAGameFeatureClassPointer::get()
	{
		return InternalDARTCGameFeatureClassPointer;
	}

	::DARTCGameFeatureClass* DARTCGameFeatureClass::InternalDARTCGameFeatureClassPointer::get()
	{
		return reinterpret_cast<::DARTCGameFeatureClass*>(Pointer.ToPointer());
	}
}