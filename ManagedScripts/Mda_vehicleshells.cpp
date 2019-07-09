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
#include "Mda_vehicleshells.h"

#include "Imports.h"
#include "UnmanagedContainer.h"
#include "MVehicleGameObj.h"
#include "MVehicleGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_vehicleshells.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DAVehicleShellStruct::DAVehicleShellStruct()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateDAVehicleShellStruct()))
	{

	}

	DAVehicleShellStruct::DAVehicleShellStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IDAVehicleShellStruct^>^ DAVehicleShellStruct::CreateDAVehicleShellStruct()
	{
		return gcnew UnmanagedContainer<IDAVehicleShellStruct^>(gcnew DAVehicleShellStruct());
	}

	bool DAVehicleShellStruct::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDAVehicleShellStruct^ otherThis = dynamic_cast<IDAVehicleShellStruct^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DAVehicleShellStructPointer.Equals(otherThis->DAVehicleShellStructPointer);
	}

	IntPtr DAVehicleShellStruct::DAVehicleShellStructPointer::get()
	{
		return IntPtr(InternalDAVehicleShellStructPointer);
	}

	IVehicleGameObjDef^ DAVehicleShellStruct::Def::get()
	{
		auto result = InternalDAVehicleShellStructPointer->Def;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew VehicleGameObjDef(IntPtr(result));
		}
	}

	void DAVehicleShellStruct::Def::set(IVehicleGameObjDef^ value)
	{
		if (value == nullptr || value->VehicleGameObjDefPointer.ToPointer() == nullptr)
		{
			InternalDAVehicleShellStructPointer->Def = nullptr;
		}
		else
		{
			InternalDAVehicleShellStructPointer->Def = reinterpret_cast<::VehicleGameObjDef*>(value->VehicleGameObjDefPointer.ToPointer());
		}
	}

	String^ DAVehicleShellStruct::Model::get()
	{
		return gcnew String(InternalDAVehicleShellStructPointer->Model.Peek_Buffer());
	}

	void DAVehicleShellStruct::Model::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalDAVehicleShellStructPointer->Model = reinterpret_cast<char*>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	String^ DAVehicleShellStruct::Explosion::get()
	{
		return gcnew String(InternalDAVehicleShellStructPointer->Explosion.Peek_Buffer());
	}

	void DAVehicleShellStruct::Explosion::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalDAVehicleShellStructPointer->Explosion = reinterpret_cast<char*>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	float DAVehicleShellStruct::ZOffset::get()
	{
		return InternalDAVehicleShellStructPointer->ZOffset;
	}

	void DAVehicleShellStruct::ZOffset::set(float value)
	{
		InternalDAVehicleShellStructPointer->ZOffset = value;
	}

	bool DAVehicleShellStruct::InternalDestroyPointer()
	{
		Imports::DestroyDAVehicleShellStruct(InternalDAVehicleShellStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DAVehicleShellStruct* DAVehicleShellStruct::InternalDAVehicleShellStructPointer::get()
	{
		return reinterpret_cast<::DAVehicleShellStruct*>(Pointer.ToPointer());
	}

	DAVehicleShellObserverClass::DAVehicleShellObserverClass(IntPtr pointer)
		: DAGameObjObserverClass(pointer)
	{

	}

	IntPtr DAVehicleShellObserverClass::DAVehicleShellObserverClassPointer::get()
	{
		return IntPtr(InternalDAVehicleShellObserverClassPointer);
	}

	::DAGameObjObserverClass* DAVehicleShellObserverClass::InternalDAGameObjObserverClassPointer::get()
	{
		return InternalDAVehicleShellObserverClassPointer;
	}

	::DAVehicleShellObserverClass* DAVehicleShellObserverClass::InternalDAVehicleShellObserverClassPointer::get()
	{
		return reinterpret_cast<::DAVehicleShellObserverClass*>(Pointer.ToPointer());
	}

	DAVehicleShellShadowObserverClass::DAVehicleShellShadowObserverClass(IntPtr pointer)
		: DAGameObjObserverClass(pointer)
	{

	}

	IntPtr DAVehicleShellShadowObserverClass::DAVehicleShellShadowObserverClassPointer::get()
	{
		return IntPtr(InternalDAVehicleShellShadowObserverClassPointer);
	}

	::DAGameObjObserverClass* DAVehicleShellShadowObserverClass::InternalDAGameObjObserverClassPointer::get()
	{
		return InternalDAVehicleShellShadowObserverClassPointer;
	}

	::DAVehicleShellShadowObserverClass* DAVehicleShellShadowObserverClass::InternalDAVehicleShellShadowObserverClassPointer::get()
	{
		return reinterpret_cast<::DAVehicleShellShadowObserverClass*>(Pointer.ToPointer());
	}

	DAVehicleShellsGameFeatureClass::DAVehicleShellsGameFeatureClass(IntPtr pointer)
		: DAEventClass(pointer)
	{
		daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
	}

	String^ DAVehicleShellsGameFeatureClass::ToString()
	{
		return daGameFeatureClass->ToString();
	}

	bool DAVehicleShellsGameFeatureClass::Equals(Object^ other)
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

		auto otherDAVehicleShellsGameFeatureClass = dynamic_cast<IDAVehicleShellsGameFeatureClass^>(other);
		if (otherDAVehicleShellsGameFeatureClass != nullptr)
		{
			if (DAVehicleShellsGameFeatureClassPointer.Equals(otherDAVehicleShellsGameFeatureClass->DAVehicleShellsGameFeatureClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void DAVehicleShellsGameFeatureClass::Init()
	{
		daGameFeatureClass->Init();
	}

	IRenSharpGameFeatureClass^ DAVehicleShellsGameFeatureClass::AsManagedGameFeature()
	{
		return daGameFeatureClass->AsManagedGameFeature();
	}

	IDAVehicleShellStruct^ DAVehicleShellsGameFeatureClass::GetShell(IVehicleGameObj^ vehicle)
	{
		if (vehicle == nullptr || vehicle->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("vehicle");
		}

		auto result = InternalDAVehicleShellsGameFeatureClassPointer->Get_Shell(
			reinterpret_cast<::VehicleGameObj*>(vehicle->VehicleGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAVehicleShellStruct(IntPtr(result));
		}
	}

	IntPtr DAVehicleShellsGameFeatureClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void DAVehicleShellsGameFeatureClass::Pointer::set(IntPtr value)
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

	IntPtr DAVehicleShellsGameFeatureClass::DAVehicleShellsGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAVehicleShellsGameFeatureClassPointer);
	}

	IntPtr DAVehicleShellsGameFeatureClass::DAGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAGameFeatureClassPointer);
	}

	String^ DAVehicleShellsGameFeatureClass::Name::get()
	{
		return daGameFeatureClass->Name;
	}

	IDAGameFeatureFactoryClass^ DAVehicleShellsGameFeatureClass::Factory::get()
	{
		return daGameFeatureClass->Factory;
	}

	void DAVehicleShellsGameFeatureClass::Factory::set(IDAGameFeatureFactoryClass^ value)
	{
		daGameFeatureClass->Factory = value;
	}

	bool DAVehicleShellsGameFeatureClass::IsManagedGameFeature::get()
	{
		return daGameFeatureClass->IsManagedGameFeature;
	}

	::DAEventClass* DAVehicleShellsGameFeatureClass::InternalDAEventClassPointer::get()
	{
		return InternalDAVehicleShellsGameFeatureClassPointer;
	}

	::DAGameFeatureClass* DAVehicleShellsGameFeatureClass::InternalDAGameFeatureClassPointer::get()
	{
		return InternalDAVehicleShellsGameFeatureClassPointer;
	}

	::DAVehicleShellsGameFeatureClass* DAVehicleShellsGameFeatureClass::InternalDAVehicleShellsGameFeatureClassPointer::get()
	{
		return reinterpret_cast<::DAVehicleShellsGameFeatureClass*>(Pointer.ToPointer());
	}
}