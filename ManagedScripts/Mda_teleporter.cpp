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
#include "Mda_teleporter.h"

#include "MScriptableGameObj.h"
#include "MVector3.h"
#include "MVector3DynamicVectorClass.h"
#include "Mengine_io.h"
#include "Imports.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_teleporter.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DATeleporterClass::DATeleporterClass(IntPtr pointer)
		: DAGameObjObserverClass(pointer)
	{

	}

	void DATeleporterClass::TeleportPlayer(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalDATeleporterClassPointer->Teleport_Player(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void DATeleporterClass::AddIgnoreList(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalDATeleporterClassPointer->Add_Ignore_List(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void DATeleporterClass::RemoveIgnoreList(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalDATeleporterClassPointer->Remove_Ignore_List(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool DATeleporterClass::IsInIgnoreList(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return InternalDATeleporterClassPointer->Is_In_Ignore_List(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	IntPtr DATeleporterClass::DATeleporterClassPointer::get()
	{
		return IntPtr(InternalDATeleporterClassPointer);
	}

	IDynamicVectorClass<Vector3>^ DATeleporterClass::Spawners::get()
	{
		return gcnew Vector3DynamicVectorClass(IntPtr(const_cast<::DynamicVectorClass<::Vector3>*>(&InternalDATeleporterClassPointer->Get_Spawners())));
	}

	bool DATeleporterClass::IsEnabled::get()
	{
		return InternalDATeleporterClassPointer->Is_Enabled();
	}

	void DATeleporterClass::IsEnabled::set(bool value)
	{
		InternalDATeleporterClassPointer->Set_Enabled(value);
	}

	int DATeleporterClass::Team::get()
	{
		return InternalDATeleporterClassPointer->Get_Team();
	}

	void DATeleporterClass::Team::set(int value)
	{
		InternalDATeleporterClassPointer->Set_Team(value);
	}

	String^ DATeleporterClass::Group::get()
	{
		return gcnew String(InternalDATeleporterClassPointer->Get_Group().Peek_Buffer());
	}

	String^ DATeleporterClass::TeleporterName::get()
	{
		const ::StringClass& name = InternalDATeleporterClassPointer->Get_Name();

		return gcnew String(name.Peek_Buffer());
	}

	::DAGameObjObserverClass* DATeleporterClass::InternalDAGameObjObserverClassPointer::get()
	{
		return InternalDATeleporterClassPointer;
	}

	::DATeleporterClass* DATeleporterClass::InternalDATeleporterClassPointer::get()
	{
		return reinterpret_cast<::DATeleporterClass*>(Pointer.ToPointer());
	}

	DATeleporterManagerClass::DATeleporterManagerClass(IntPtr pointer)
		: DASingleton<IDATeleporterManagerClass^>(pointer)
	{

	}

	IDATeleporterManagerClass^ DATeleporterManagerClass::CreateInstance()
	{
		auto result = Imports::CreateInstanceDATeleporterManagerClass();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DATeleporterManagerClass(IntPtr(result));
		}
	}

	void DATeleporterManagerClass::DestroyInstance()
	{
		Imports::DestroyInstanceDATeleporterManagerClass();
	}

	bool DATeleporterManagerClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDATeleporterManagerClass^ otherThis = dynamic_cast<IDATeleporterManagerClass^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DATeleporterManagerClassPointer.Equals(otherThis->DATeleporterManagerClassPointer);
	}

	IDATeleporterClass^ DATeleporterManagerClass::CreateTeleporter(IINIClass^ ini, String^ header)
	{
		if (ini == nullptr || ini->INIClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("ini");
		}
		else if (header == nullptr)
		{
			throw gcnew ArgumentNullException("header");
		}

		IntPtr headerHandle = Marshal::StringToHGlobalAnsi(header);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(headerHandle.ToPointer()));

			auto result = Imports::CreateTeleporterDATeleporterManagerClass(
				InternalDATeleporterManagerClassPointer,
				reinterpret_cast<::INIClass*>(ini->INIClassPointer.ToPointer()),
				&tmp);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew DATeleporterClass(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(headerHandle);
		}
	}

	IDATeleporterClass^ DATeleporterManagerClass::FindTeleporter(String^ group)
	{
		if (group == nullptr)
		{
			throw gcnew ArgumentNullException("group");
		}

		IntPtr groupHandle = Marshal::StringToHGlobalAnsi(group);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(groupHandle.ToPointer()));

			auto result = InternalDATeleporterManagerClassPointer->Find_Teleporter(tmp);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew DATeleporterClass(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(groupHandle);
		}
	}

	IDATeleporterManagerClass^ DATeleporterManagerClass::Instance::get()
	{
		auto result = Imports::GetInstanceDATeleporterManagerClass();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DATeleporterManagerClass(IntPtr(result));
		}
	}

	IntPtr DATeleporterManagerClass::DATeleporterManagerClassPointer::get()
	{
		return IntPtr(InternalDATeleporterManagerClassPointer);
	}

	bool DATeleporterManagerClass::InternalDestroyPointer()
	{
		Imports::DestroyDATeleporterManagerClass(InternalDATeleporterManagerClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DATeleporterManagerClass* DATeleporterManagerClass::InternalDATeleporterManagerClassPointer::get()
	{
		return reinterpret_cast<::DATeleporterManagerClass*>(Pointer.ToPointer());
	}
}