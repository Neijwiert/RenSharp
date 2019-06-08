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
#include "Mda_spawnsystem.h"

#include "Imports.h"
#include "UnmanagedContainer.h"
#include "MScriptableGameObj.h"
#include "McPlayer.h"
#include "MVector3.h"
#include "Mengine_io.h"
#include "MVector3DynamicVectorClass.h"

using namespace System::Text;

namespace RenSharp
{
	DASpawnPlayerDataClass::DASpawnPlayerDataClass()
		: DAPlayerDataClass(IntPtr(Imports::CreateDASpawnPlayerDataClass()))
	{

	}

	DASpawnPlayerDataClass::DASpawnPlayerDataClass(IntPtr pointer)
		: DAPlayerDataClass(pointer)
	{

	}

	IntPtr DASpawnPlayerDataClass::DASpawnPlayerDataClassPointer::get()
	{
		return IntPtr(InternalDASpawnPlayerDataClassPointer);
	}

	::DAPlayerDataClass* DASpawnPlayerDataClass::InternalDAPlayerDataClassPointer::get()
	{
		return InternalDASpawnPlayerDataClassPointer;
	}

	::DASpawnPlayerDataClass* DASpawnPlayerDataClass::InternalDASpawnPlayerDataClassPointer::get()
	{
		return reinterpret_cast<::DASpawnPlayerDataClass*>(Pointer.ToPointer());
	}

	DistanceCheckStruct::DistanceCheckStruct()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateDistanceCheckStruct()))
	{

	}

	DistanceCheckStruct::DistanceCheckStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IDistanceCheckStruct^>^ DistanceCheckStruct::CreateDistanceCheckStruct()
	{
		return gcnew UnmanagedContainer<IDistanceCheckStruct^>(gcnew DistanceCheckStruct());
	}

	bool DistanceCheckStruct::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDistanceCheckStruct^ otherThis = dynamic_cast<IDistanceCheckStruct^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DistanceCheckStructPointer.Equals(otherThis->DistanceCheckStructPointer);
	}

	IntPtr DistanceCheckStruct::DistanceCheckStructPointer::get()
	{
		return IntPtr(InternalDistanceCheckStructPointer);
	}

	float DistanceCheckStruct::Both::get()
	{
		return InternalDistanceCheckStructPointer->Both;
	}

	void DistanceCheckStruct::Both::set(float value)
	{
		InternalDistanceCheckStructPointer->Both = value;
	}

	float DistanceCheckStruct::Ally::get()
	{
		return InternalDistanceCheckStructPointer->Ally;
	}

	void DistanceCheckStruct::Ally::set(float value)
	{
		InternalDistanceCheckStructPointer->Ally = value;
	}

	float DistanceCheckStruct::Enemy::get()
	{
		return InternalDistanceCheckStructPointer->Enemy;
	}

	void DistanceCheckStruct::Enemy::set(float value)
	{
		InternalDistanceCheckStructPointer->Enemy = value;
	}

	bool DistanceCheckStruct::InternalDestroyPointer()
	{
		Imports::DestroyDistanceCheckStruct(InternalDistanceCheckStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DASpawnPointClass::DistanceCheckStruct* DistanceCheckStruct::InternalDistanceCheckStructPointer::get()
	{
		return reinterpret_cast<::DASpawnPointClass::DistanceCheckStruct*>(Pointer.ToPointer());
	}

	DASpawnPointClass::DASpawnPointClass(IntPtr pointer)
		: DAEventClass(pointer)
	{

	}

	String^ DASpawnPointClass::ToString()
	{
		StringBuilder^ builder = gcnew StringBuilder();
		builder->Append(Name);

		return builder->ToString();
	}

	void DASpawnPointClass::ClearSpawnListFindNewSpawn()
	{
		InternalDASpawnPointClassPointer->Clear_Spawn_List_Find_New_Spawn();
	}

	void DASpawnPointClass::ClearSpawnList()
	{
		InternalDASpawnPointClassPointer->Clear_Spawn_List();
	}

	float DASpawnPointClass::GetDistance(Vector3 position)
	{
		::Vector3 positionVec;
		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		return InternalDASpawnPointClassPointer->Get_Distance(positionVec);
	}

	IUnmanagedContainer<IDistanceCheckStruct^>^ DASpawnPointClass::DistanceCheck(Vector3 pos, int team)
	{
		::Vector3 posVec;
		Vector3::ManagedToUnmanagedVector3(pos, posVec);

		auto result = DistanceCheckStruct::CreateDistanceCheckStruct();
		try
		{
			InternalDASpawnPointClassPointer->Distance_Check(
				*reinterpret_cast<::DASpawnPointClass::DistanceCheckStruct*>(result->UnmanagedObject->DistanceCheckStructPointer.ToPointer()),
				posVec,
				team);

			return result;
		}
		catch (Exception^)
		{
#pragma push_macro("delete")
#undef delete
			delete result;
			result = nullptr;
#pragma pop_macro("delete")

			throw;
		}
	}

	IntPtr DASpawnPointClass::DASpawnPointClassPointer::get()
	{
		return IntPtr(InternalDASpawnPointClassPointer);
	}

	Vector3 DASpawnPointClass::CenterPoint::get()
	{
		Vector3 result;

		Vector3::UnmanagedToManagedVector3(InternalDASpawnPointClassPointer->Get_Center_Point(), result);

		return result;
	}

	void DASpawnPointClass::CenterPoint::set(Vector3 value)
	{
		::Vector3 valueVec;

		Vector3::ManagedToUnmanagedVector3(value, valueVec);

		InternalDASpawnPointClassPointer->Set_Center_Point(valueVec);
	}

	IDynamicVectorClass<Vector3>^ DASpawnPointClass::Spawners::get()
	{
		return gcnew Vector3DynamicVectorClass(IntPtr(const_cast<::DynamicVectorClass<::Vector3>*>(&InternalDASpawnPointClassPointer->Get_Spawners())));
	}

	bool DASpawnPointClass::Enabled::get()
	{
		return InternalDASpawnPointClassPointer->Is_Enabled();
	}

	void DASpawnPointClass::Enabled::set(bool value)
	{
		InternalDASpawnPointClassPointer->Set_Enabled(value);
	}

	int DASpawnPointClass::Team::get()
	{
		return InternalDASpawnPointClassPointer->Get_Team();
	}

	void DASpawnPointClass::Team::set(int value)
	{
		InternalDASpawnPointClassPointer->Set_Team(value);
	}

	String^ DASpawnPointClass::Group::get()
	{
		return gcnew String(InternalDASpawnPointClassPointer->Get_Group().Peek_Buffer());
	}

	String^ DASpawnPointClass::Name::get()
	{
		return gcnew String(InternalDASpawnPointClassPointer->Get_Name().Peek_Buffer());
	}

	unsigned int DASpawnPointClass::SpawnTime::get()
	{
		return InternalDASpawnPointClassPointer->Get_Spawn_Time();
	}

	void DASpawnPointClass::SpawnTime::set(unsigned int value)
	{
		InternalDASpawnPointClassPointer->Set_Spawn_Time(value);
	}

	unsigned int DASpawnPointClass::BaseSpawnTime::get()
	{
		return InternalDASpawnPointClassPointer->Get_Base_Spawn_Time();
	}

	float DASpawnPointClass::ProtectTime::get()
	{
		return InternalDASpawnPointClassPointer->Get_Protect_Time();
	}

	void DASpawnPointClass::ProtectTime::set(float value)
	{
		InternalDASpawnPointClassPointer->Set_Protect_Time(value);
	}

	int DASpawnPointClass::Priority::get()
	{
		return InternalDASpawnPointClassPointer->Get_Priority();
	}

	void DASpawnPointClass::Priority::set(int value)
	{
		InternalDASpawnPointClassPointer->Set_Priority(value);
	}

	::DAEventClass* DASpawnPointClass::InternalDAEventClassPointer::get()
	{
		return InternalDASpawnPointClassPointer;
	}

	::DASpawnPointClass* DASpawnPointClass::InternalDASpawnPointClassPointer::get()
	{
		return reinterpret_cast<::DASpawnPointClass*>(Pointer.ToPointer());
	}

	DASpawnManagerClass::DASpawnManagerClass(IntPtr pointer) 
		: DAEventClass(pointer)
	{
		daPlayerDataFactoryClass = gcnew DAPlayerDataFactoryClass(IntPtr(InternalDAPlayerDataFactoryClassPointer));
	}

	bool DASpawnManagerClass::Equals(Object^ other)
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

		auto otherDAPlayerDataFactoryClass = dynamic_cast<IDAPlayerDataFactoryClass^>(other);
		if (otherDAPlayerDataFactoryClass != nullptr)
		{
			if (daPlayerDataFactoryClass->DAPlayerDataFactoryClassPointer.Equals(otherDAPlayerDataFactoryClass->DAPlayerDataFactoryClassPointer))
			{
				return true;
			}
		}

		auto otherDASpawnManagerClass = dynamic_cast<IDASpawnManagerClass^>(other);
		if (otherDASpawnManagerClass != nullptr)
		{
			if (DASpawnManagerClassPointer.Equals(otherDASpawnManagerClass->DASpawnManagerClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	IDASpawnManagerClass^ DASpawnManagerClass::CreateInstance()
	{
		auto result = Imports::CreateInstanceDASpawnManagerClass();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DASpawnManagerClass(IntPtr(result));
		}
	}

	void DASpawnManagerClass::DestroyInstance()
	{
		Imports::DestroyInstanceDASpawnManagerClass();
	}

	IUnmanagedContainer<IDAPlayerDataClass^>^ DASpawnManagerClass::CreateData()
	{
		return daPlayerDataFactoryClass->CreateData();
	}

	IRenSharpPlayerDataFactoryClass^ DASpawnManagerClass::AsManagedPlayerDataFactory()
	{
		return daPlayerDataFactoryClass->AsManagedPlayerDataFactory();
	}

	IDASpawnPlayerDataClass^ DASpawnManagerClass::GetPlayerData(int id)
	{
		auto result = InternalDASpawnManagerClassPointer->Get_Player_Data(id);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DASpawnPlayerDataClass(IntPtr(result));
		}
	}

	IDASpawnPlayerDataClass^ DASpawnManagerClass::GetPlayerData(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = InternalDASpawnManagerClassPointer->Get_Player_Data(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DASpawnPlayerDataClass(IntPtr(result));
		}
	}

	IDASpawnPlayerDataClass^ DASpawnManagerClass::GetPlayerData(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		auto result = InternalDASpawnManagerClassPointer->Get_Player_Data(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DASpawnPlayerDataClass(IntPtr(result));
		}
	}

	IDASpawnPlayerDataClass^ DASpawnManagerClass::GetPlayerData(IDAPlayerClass^ player)
	{
		if (player == nullptr || player->DAPlayerClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		auto result = InternalDASpawnManagerClassPointer->Get_Player_Data(
			reinterpret_cast<::DAPlayerClass*>(player->DAPlayerClassPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DASpawnPlayerDataClass(IntPtr(result));
		}
	}

	void DASpawnManagerClass::Init(IINIClass^ ini)
	{
		if (ini == nullptr || ini->INIClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("ini");
		}

		InternalDASpawnManagerClassPointer->Init(
			reinterpret_cast<::INIClass*>(ini->INIClassPointer.ToPointer()));
	}

	void DASpawnManagerClass::ReAddSpawnList(int id)
	{
		InternalDASpawnManagerClassPointer->Re_Add_Spawn_List(id);
	}

	void DASpawnManagerClass::ReAddSpawnList(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalDASpawnManagerClassPointer->Re_Add_Spawn_List(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void DASpawnManagerClass::SetNextSpawnLocation(IScriptableGameObj^ obj, String^ name)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(nameHandle.ToPointer()));

			InternalDASpawnManagerClassPointer->Set_Next_Spawn_Location(
				reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
				tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	void DASpawnManagerClass::SetNextSpawnLocation(int id, String^ name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(nameHandle.ToPointer()));

			InternalDASpawnManagerClassPointer->Set_Next_Spawn_Location(id, tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	void DASpawnManagerClass::DisplayPT(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalDASpawnManagerClassPointer->Display_PT(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	IDASpawnPointClass^ DASpawnManagerClass::CreateSpawnPoint(IINIClass^ ini, String^ header)
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

			auto result = Imports::CreateSpawnPointDASpawnManagerClass(
				InternalDASpawnManagerClassPointer,
				reinterpret_cast<::INIClass*>(ini->INIClassPointer.ToPointer()),
				&tmp);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew DASpawnPointClass(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(headerHandle);
		}
	}

	IDASpawnPointClass^ DASpawnManagerClass::FindSpawnPoint(String^ group)
	{
		if (group == nullptr)
		{
			throw gcnew ArgumentNullException("group");
		}

		IntPtr groupHandle = Marshal::StringToHGlobalAnsi(group);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(groupHandle.ToPointer()));

			auto result = InternalDASpawnManagerClassPointer->Find_Spawn_Point(tmp);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew DASpawnPointClass(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(groupHandle);
		}
	}

	void DASpawnManagerClass::EnableAllExcept(String^ group)
	{
		if (group == nullptr)
		{
			throw gcnew ArgumentNullException("group");
		}

		IntPtr groupHandle = Marshal::StringToHGlobalAnsi(group);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(groupHandle.ToPointer()));

			InternalDASpawnManagerClassPointer->Enable_All_Except(tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(groupHandle);
		}
	}

	void DASpawnManagerClass::DisableAllExcept(String^ group)
	{
		if (group == nullptr)
		{
			throw gcnew ArgumentNullException("group");
		}

		IntPtr groupHandle = Marshal::StringToHGlobalAnsi(group);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(groupHandle.ToPointer()));

			InternalDASpawnManagerClassPointer->Disable_All_Except(tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(groupHandle);
		}
	}

	Vector3 DASpawnManagerClass::GetDeathPosition(int id)
	{
		Vector3 result;

		Vector3::UnmanagedToManagedVector3(InternalDASpawnManagerClassPointer->Get_Death_Position(id), result);

		return result;
	}

	Vector3 DASpawnManagerClass::GetDeathPosition(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		Vector3 result;

		Vector3::UnmanagedToManagedVector3(InternalDASpawnManagerClassPointer->Get_Death_Position(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer())), result);

		return result;
	}

	IDASpawnManagerClass^ DASpawnManagerClass::Instance::get()
	{
		auto result = Imports::GetInstanceDASpawnManagerClass();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DASpawnManagerClass(IntPtr(result));
		}
	}

	IntPtr DASpawnManagerClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void DASpawnManagerClass::Pointer::set(IntPtr value)
	{
		AbstractUnmanagedObject::Pointer::set(value);

		if (Pointer == IntPtr::Zero)
		{
			daPlayerDataFactoryClass = nullptr;
		}
		else
		{
			daPlayerDataFactoryClass = gcnew DAPlayerDataFactoryClass(IntPtr(InternalDAPlayerDataFactoryClassPointer));
		}
	}

	IntPtr DASpawnManagerClass::DASpawnManagerClassPointer::get()
	{
		return IntPtr(InternalDASpawnManagerClassPointer);
	}

	IntPtr DASpawnManagerClass::DAPlayerDataFactoryClassPointer::get()
	{
		return IntPtr(InternalDAPlayerDataFactoryClassPointer);
	}

	bool DASpawnManagerClass::IsManagedPlayerDataFactory::get()
	{
		return daPlayerDataFactoryClass->IsManagedPlayerDataFactory;
	}

	unsigned int DASpawnManagerClass::SpawnTime::get()
	{
		return InternalDASpawnManagerClassPointer->Get_Spawn_Time();
	}

	unsigned int DASpawnManagerClass::IntermissionTime::get()
	{
		return InternalDASpawnManagerClassPointer->Get_Intermission_Time();
	}

	float DASpawnManagerClass::MinAllyDistance::get()
	{
		return InternalDASpawnManagerClassPointer->Get_Min_Ally_Distance();
	}

	float DASpawnManagerClass::MaxAllyDistance::get()
	{
		return InternalDASpawnManagerClassPointer->Get_Max_Ally_Distance();
	}

	float DASpawnManagerClass::MinEnemyDistance::get()
	{
		return InternalDASpawnManagerClassPointer->Get_Min_Enemy_Distance();
	}

	float DASpawnManagerClass::MaxEnemyDistance::get()
	{
		return InternalDASpawnManagerClassPointer->Get_Max_Enemy_Distance();
	}

	bool DASpawnManagerClass::UseWaitingRoom::get()
	{
		return InternalDASpawnManagerClassPointer->Using_Waiting_Room();
	}

	float DASpawnManagerClass::ProtectTime::get()
	{
		return InternalDASpawnManagerClassPointer->Get_Protect_Time();
	}

	::DAEventClass* DASpawnManagerClass::InternalDAEventClassPointer::get()
	{
		return InternalDASpawnManagerClassPointer;
	}

	::DAPlayerDataFactoryClass* DASpawnManagerClass::InternalDAPlayerDataFactoryClassPointer::get()
	{
		return InternalDASpawnManagerClassPointer;
	}

	::DASpawnManagerClass* DASpawnManagerClass::InternalDASpawnManagerClassPointer::get()
	{
		return reinterpret_cast<::DASpawnManagerClass*>(Pointer.ToPointer());
	}
}