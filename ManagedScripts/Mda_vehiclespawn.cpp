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
#include "Mda_vehiclespawn.h"

#include "MVector3.h"
#include "Mengine_io.h"
#include "MSoldierGameObj.h"
#include "MVehicleGameObjDef.h"
#include "Imports.h"
#include "MVehicleFactoryGameObj.h"
#include "MDAVehicleSpawnPointClassPtrDynamicVectorClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_vehiclespawn.h>
#include <type_traits>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Text;

namespace RenSharp
{

#pragma managed(push, off)

	class DAVehicleSpawnPointClassHelper : public ::DAVehicleSpawnPointClass
	{
		private:
			DAVehicleSpawnPointClassHelper() = default;

		public:
			void _Init(const ::INIClass* ini, const ::StringClass& header)
			{
				Init(ini, header);
			}

			::StringClass& GetGroup()
			{
				return Group;
			}

			::StringClass& GetName()
			{
				return Name;
			}

			::Vector3& GetPosition()
			{
				return Position;
			}

			bool& GetEnable()
			{
				return Enable;
			}

			int& GetTeam()
			{
				return Team;
			}

			float& GetFacing()
			{
				return Facing;
			}
	};

	class DAVehicleSpawnManagerClassHelper : public ::DAVehicleSpawnManagerClass
	{
		public:
			static constexpr std::size_t VFSizeCount = (sizeof(VF) / sizeof(std::remove_all_extents<decltype(VF)>::type));

		private:
			DAVehicleSpawnManagerClassHelper() = default;

		public:
			::DynamicVectorClass<::DAVehicleSpawnPointClass*>& GetSpawnPoints()
			{
				return SpawnPoints;
			}

			void GetVF(::VehicleFactoryGameObj** result)
			{
				std::memcpy(result, VF, sizeof(VF));
			}

			void SetVF(std::size_t index, ::VehicleFactoryGameObj* factory)
			{
				VF[index] = factory;
			}
	};

#pragma managed(pop)

	DAVehicleSpawnPointClass::DAVehicleSpawnPointClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	String^ DAVehicleSpawnPointClass::ToString()
	{
		StringBuilder^ builder = gcnew StringBuilder();
		builder->Append(Name);

		return builder->ToString();
	}

	bool DAVehicleSpawnPointClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDAVehicleSpawnPointClass^ otherThis = dynamic_cast<IDAVehicleSpawnPointClass^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DAVehicleSpawnPointClassPointer.Equals(otherThis->DAVehicleSpawnPointClassPointer);
	}

	void DAVehicleSpawnPointClass::SpawnVehicle(String^ preset, ISoldierGameObj^ owner)
	{
		if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}
		else if (owner == nullptr || owner->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}

		IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			InternalDAVehicleSpawnPointClassPointer->Spawn_Vehicle(
				reinterpret_cast<char*>(presetHandle.ToPointer()),
				reinterpret_cast<::SoldierGameObj*>(owner->SoldierGameObjPointer.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(presetHandle);
		}
	}

	void DAVehicleSpawnPointClass::SpawnVehicle(unsigned int defID, ISoldierGameObj^ owner)
	{
		if (owner == nullptr || owner->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}

		InternalDAVehicleSpawnPointClassPointer->Spawn_Vehicle(
			defID,
			reinterpret_cast<::SoldierGameObj*>(owner->SoldierGameObjPointer.ToPointer()));
	}

	void DAVehicleSpawnPointClass::SpawnVehicle(IVehicleGameObjDef^ def, ISoldierGameObj^ owner)
	{
		if (def == nullptr || def->VehicleGameObjDefPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("def");
		}
		else if (owner == nullptr || owner->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}

		InternalDAVehicleSpawnPointClassPointer->Spawn_Vehicle(
			reinterpret_cast<::VehicleGameObjDef*>(def->VehicleGameObjDefPointer.ToPointer()),
			reinterpret_cast<::SoldierGameObj*>(owner->SoldierGameObjPointer.ToPointer()));
	}

	void DAVehicleSpawnPointClass::SetEnabled(bool enable)
	{
		InternalDAVehicleSpawnPointClassPointer->Set_Enabled(enable);
	}

	void DAVehicleSpawnPointClass::SetTeam(int team)
	{
		InternalDAVehicleSpawnPointClassPointer->Set_Team(team);
	}

	float DAVehicleSpawnPointClass::GetDistance(Vector3 pos)
	{
		::Vector3 posVec;

		Vector3::ManagedToUnmanagedVector3(pos, posVec);

		return InternalDAVehicleSpawnPointClassPointer->Get_Distance(posVec);
	}

	IntPtr DAVehicleSpawnPointClass::DAVehicleSpawnPointClassPointer::get()
	{
		return IntPtr(InternalDAVehicleSpawnPointClassPointer);
	}

	String^ DAVehicleSpawnPointClass::Group::get()
	{
		return gcnew String(InternalDAVehicleSpawnPointClassPointer->Get_Group().Peek_Buffer());
	}

	void DAVehicleSpawnPointClass::Group::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<DAVehicleSpawnPointClassHelper*>(InternalDAVehicleSpawnPointClassPointer);

		auto& group = helper->GetGroup();

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			group = reinterpret_cast<char*>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	String^ DAVehicleSpawnPointClass::Name::get()
	{
		return gcnew String(InternalDAVehicleSpawnPointClassPointer->Get_Name().Peek_Buffer());
	}

	void DAVehicleSpawnPointClass::Name::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<DAVehicleSpawnPointClassHelper*>(InternalDAVehicleSpawnPointClassPointer);

		auto& name = helper->GetName();

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			name = reinterpret_cast<char*>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	Vector3 DAVehicleSpawnPointClass::Position::get()
	{
		Vector3 result;

		Vector3::UnmanagedToManagedVector3(InternalDAVehicleSpawnPointClassPointer->Get_Position(), result);

		return result;
	}

	void DAVehicleSpawnPointClass::Position::set(Vector3 value)
	{
		auto helper = reinterpret_cast<DAVehicleSpawnPointClassHelper*>(InternalDAVehicleSpawnPointClassPointer);

		auto& position = helper->GetPosition();

		Vector3::ManagedToUnmanagedVector3(value, position);
	}

	bool DAVehicleSpawnPointClass::IsEnabled::get()
	{
		return InternalDAVehicleSpawnPointClassPointer->Is_Enabled();
	}

	void DAVehicleSpawnPointClass::IsEnabled::set(bool value)
	{
		auto helper = reinterpret_cast<DAVehicleSpawnPointClassHelper*>(InternalDAVehicleSpawnPointClassPointer);

		auto& isEnabled = helper->GetEnable();

		isEnabled = value;
	}

	int DAVehicleSpawnPointClass::Team::get()
	{
		return InternalDAVehicleSpawnPointClassPointer->Get_Team();
	}

	void DAVehicleSpawnPointClass::Team::set(int value)
	{
		auto helper = reinterpret_cast<DAVehicleSpawnPointClassHelper*>(InternalDAVehicleSpawnPointClassPointer);

		auto& team = helper->GetTeam();

		team = value;
	}

	int DAVehicleSpawnPointClass::Priority::get()
	{
		return InternalDAVehicleSpawnPointClassPointer->Get_Priority();
	}

	void DAVehicleSpawnPointClass::Priority::set(int value)
	{
		InternalDAVehicleSpawnPointClassPointer->Set_Priority(value);
	}

	void DAVehicleSpawnPointClass::Init(IINIClass^ ini, String^ header)
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

			auto helper = reinterpret_cast<DAVehicleSpawnPointClassHelper*>(InternalDAVehicleSpawnPointClassPointer);

			helper->_Init(
				reinterpret_cast<::INIClass*>(ini->INIClassPointer.ToPointer()),
				tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(headerHandle);
		}
	}

	::DAVehicleSpawnPointClass* DAVehicleSpawnPointClass::InternalDAVehicleSpawnPointClassPointer::get()
	{
		return reinterpret_cast<::DAVehicleSpawnPointClass*>(Pointer.ToPointer());
	}

	float DAVehicleSpawnPointClass::Facing::get()
	{
		auto helper = reinterpret_cast<DAVehicleSpawnPointClassHelper*>(InternalDAVehicleSpawnPointClassPointer);

		auto& facing = helper->GetFacing();

		return facing;
	}

	void DAVehicleSpawnPointClass::Facing::set(float value)
	{
		auto helper = reinterpret_cast<DAVehicleSpawnPointClassHelper*>(InternalDAVehicleSpawnPointClassPointer);

		auto& facing = helper->GetFacing();

		facing = value;
	}

	DAVehicleAirDropPointClass::DAVehicleAirDropPointClass(IntPtr pointer)\
		: DAVehicleSpawnPointClass(pointer)
	{

	}

	IntPtr DAVehicleAirDropPointClass::DAVehicleAirDropPointClassPointer::get()
	{
		return IntPtr(InternalDAVehicleAirDropPointClassPointer);
	}

	::DAVehicleSpawnPointClass* DAVehicleAirDropPointClass::InternalDAVehicleSpawnPointClassPointer::get()
	{
		return InternalDAVehicleAirDropPointClassPointer;
	}

	::DAVehicleAirDropPointClass* DAVehicleAirDropPointClass::InternalDAVehicleAirDropPointClassPointer::get()
	{
		return reinterpret_cast<::DAVehicleAirDropPointClass*>(Pointer.ToPointer());
	}

	DAVehicleSpawnManagerClass::DAVehicleSpawnManagerClass(IntPtr pointer)
		: DAEventClass(pointer)
	{

	}

	IDAVehicleSpawnManagerClass^ DAVehicleSpawnManagerClass::CreateInstance()
	{
		auto result = Imports::CreateInstanceDAVehicleSpawnManagerClass();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAVehicleSpawnManagerClass(IntPtr(result));
		}
	}

	void DAVehicleSpawnManagerClass::DestroyInstance()
	{
		Imports::DestroyInstanceDAVehicleSpawnManagerClass();
	}

	void DAVehicleSpawnManagerClass::Init(IINIClass^ ini)
	{
		if (ini == nullptr || ini->INIClassPointer.ToPointer() == nullptr)
		{
			InternalDAVehicleSpawnManagerClass->Init(nullptr);
		}
		else
		{
			InternalDAVehicleSpawnManagerClass->Init(
				reinterpret_cast<::INIClass*>(ini->INIClassPointer.ToPointer()));
		}
	}

	void DAVehicleSpawnManagerClass::SpawnVehicle(int team, String^ preset, ISoldierGameObj^ owner)
	{
		if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}
		else if (owner == nullptr || owner->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}

		IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			InternalDAVehicleSpawnManagerClass->Spawn_Vehicle(
				team,
				reinterpret_cast<char*>(presetHandle.ToPointer()),
				reinterpret_cast<::SoldierGameObj*>(owner->SoldierGameObjPointer.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(presetHandle);
		}
	}

	void DAVehicleSpawnManagerClass::SpawnVehicle(int team, unsigned int defID, ISoldierGameObj^ owner)
	{
		if (owner == nullptr || owner->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}

		InternalDAVehicleSpawnManagerClass->Spawn_Vehicle(
			team,
			defID,
			reinterpret_cast<::SoldierGameObj*>(owner->SoldierGameObjPointer.ToPointer()));
	}

	void DAVehicleSpawnManagerClass::SpawnVehicle(int team, IVehicleGameObjDef^ def, ISoldierGameObj^ owner)
	{
		if (def == nullptr || def->VehicleGameObjDefPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("def");
		}
		else if (owner == nullptr || owner->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}

		InternalDAVehicleSpawnManagerClass->Spawn_Vehicle(
			team,
			reinterpret_cast<::VehicleGameObjDef*>(def->VehicleGameObjDefPointer.ToPointer()),
			reinterpret_cast<::SoldierGameObj*>(owner->SoldierGameObjPointer.ToPointer()));
	}

	IDAVehicleSpawnPointClass^ DAVehicleSpawnManagerClass::CreateSpawnPoint(IINIClass^ ini, String^ header)
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

			auto result = Imports::CreateSpawnPointDAVehicleSpawnManagerClass(
				InternalDAVehicleSpawnManagerClass,
				reinterpret_cast<::INIClass*>(ini->INIClassPointer.ToPointer()),
				&tmp);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew DAVehicleSpawnPointClass(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(headerHandle);
		}
	}

	IDAVehicleAirDropPointClass^ DAVehicleSpawnManagerClass::CreateAirDropPoint(IINIClass^ ini, String^ header)
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

			auto result = Imports::CreateAirDropPointDAVehicleSpawnManagerClass(
				InternalDAVehicleSpawnManagerClass,
				reinterpret_cast<::INIClass*>(ini->INIClassPointer.ToPointer()),
				&tmp);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew DAVehicleAirDropPointClass(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(headerHandle);
		}
	}

	IDAVehicleSpawnPointClass^ DAVehicleSpawnManagerClass::FindSpawnPoint(String^ group)
	{
		if (group == nullptr)
		{
			throw gcnew ArgumentNullException("group");
		}

		IntPtr groupHandle = Marshal::StringToHGlobalAnsi(group);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(groupHandle.ToPointer()));

			auto result = InternalDAVehicleSpawnManagerClass->Find_Spawn_Point(tmp);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew DAVehicleSpawnPointClass(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(groupHandle);
		}
	}

	void DAVehicleSpawnManagerClass::EnableAllSpawnPointsExcept(String^ group)
	{
		if (group == nullptr)
		{
			throw gcnew ArgumentNullException("group");
		}

		IntPtr groupHandle = Marshal::StringToHGlobalAnsi(group);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(groupHandle.ToPointer()));

			InternalDAVehicleSpawnManagerClass->Enable_All_Spawn_Points_Except(tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(groupHandle);
		}
	}

	void DAVehicleSpawnManagerClass::DisableAllSpawnPointsExcept(String^ group)
	{
		if (group == nullptr)
		{
			throw gcnew ArgumentNullException("group");
		}

		IntPtr groupHandle = Marshal::StringToHGlobalAnsi(group);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(groupHandle.ToPointer()));

			InternalDAVehicleSpawnManagerClass->Disable_All_Spawn_Points_Except(tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(groupHandle);
		}
	}

	void DAVehicleSpawnManagerClass::DisableAllSpawnPointsTeam(int team)
	{
		InternalDAVehicleSpawnManagerClass->Disable_All_Spawn_Points_Team(team);
	}

	void DAVehicleSpawnManagerClass::EnableAllSpawnPointsTeam(int team)
	{
		InternalDAVehicleSpawnManagerClass->Enable_All_Spawn_Points_Team(team);
	}

	void DAVehicleSpawnManagerClass::SetAllSpawnPointsTeam(int team)
	{
		InternalDAVehicleSpawnManagerClass->Set_All_Spawn_Points_Team(team);
	}

	bool DAVehicleSpawnManagerClass::AllSpawnPointsDisabledTeam(int team)
	{
		return InternalDAVehicleSpawnManagerClass->All_Spawn_Points_Disabled_Team(team);
	}

	void DAVehicleSpawnManagerClass::EnableVehicleFactory(int team, bool enable)
	{
		InternalDAVehicleSpawnManagerClass->Enable_Vehicle_Factory(team, enable);
	}

	void DAVehicleSpawnManagerClass::SetVehicleFactoryBusy(int team, bool busy)
	{
		if (team < 0 || team >= static_cast<int>(DAVehicleSpawnManagerClassHelper::VFSizeCount))
		{
			throw gcnew ArgumentOutOfRangeException("team");
		}

		InternalDAVehicleSpawnManagerClass->Set_Vehicle_Factory_Busy(team, busy);
	}

	IDAVehicleSpawnManagerClass^ DAVehicleSpawnManagerClass::Instance::get()
	{
		auto result = Imports::GetInstanceDAVehicleSpawnManagerClass();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAVehicleSpawnManagerClass(IntPtr(result));
		}
	}

	IntPtr DAVehicleSpawnManagerClass::DAVehicleSpawnManagerClassPointer::get()
	{
		return IntPtr(InternalDAVehicleSpawnManagerClass);
	}

	::DAEventClass* DAVehicleSpawnManagerClass::InternalDAEventClassPointer::get()
	{
		return InternalDAVehicleSpawnManagerClass;
	}

	::DAVehicleSpawnManagerClass* DAVehicleSpawnManagerClass::InternalDAVehicleSpawnManagerClass::get()
	{
		return reinterpret_cast<::DAVehicleSpawnManagerClass*>(Pointer.ToPointer());
	}

	IDynamicVectorClass<IDAVehicleSpawnPointClass^>^ DAVehicleSpawnManagerClass::SpawnPoints::get()
	{
		auto helper = reinterpret_cast<DAVehicleSpawnManagerClassHelper*>(InternalDAVehicleSpawnManagerClass);

		auto& spawnPoints = helper->GetSpawnPoints();

		return gcnew DAVehicleSpawnPointClassPtrDynamicVectorClass(IntPtr(&spawnPoints));
	}

	void DAVehicleSpawnManagerClass::SpawnPoints::set(IDynamicVectorClass<IDAVehicleSpawnPointClass^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<DAVehicleSpawnManagerClassHelper*>(InternalDAVehicleSpawnManagerClass);

		auto& spawnPoints = helper->GetSpawnPoints();

		spawnPoints = *reinterpret_cast<::DynamicVectorClass<::DAVehicleSpawnPointClass*>*>(value->Pointer.ToPointer());
	}

	array<IVehicleFactoryGameObj^>^ DAVehicleSpawnManagerClass::VF::get()
	{
		auto helper = reinterpret_cast<DAVehicleSpawnManagerClassHelper*>(InternalDAVehicleSpawnManagerClass);

		::VehicleFactoryGameObj* vf[DAVehicleSpawnManagerClassHelper::VFSizeCount];
		helper->GetVF(vf);

		array<IVehicleFactoryGameObj^>^ result = gcnew array<IVehicleFactoryGameObj^>(DAVehicleSpawnManagerClassHelper::VFSizeCount);
		for (int x = 0; x < result->Length; x++)
		{
			auto currentFactory = vf[x];
			if (currentFactory == nullptr)
			{
				result[x] = nullptr;
			}
			else
			{
				result[x] = gcnew VehicleFactoryGameObj(IntPtr(currentFactory));
			}
		}

		return result;
	}

	void DAVehicleSpawnManagerClass::VF::set(array<IVehicleFactoryGameObj^>^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}
		else if (value->Length != static_cast<int>(DAVehicleSpawnManagerClassHelper::VFSizeCount))
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DAVehicleSpawnManagerClassHelper*>(InternalDAVehicleSpawnManagerClass);

		for (int x = 0; x < value->Length; x++)
		{
			auto currentFactory = value[x];
			if (currentFactory == nullptr || currentFactory->VehicleFactoryGameObjPointer.ToPointer() == nullptr)
			{
				helper->SetVF(
					static_cast<std::size_t>(x),
					nullptr);
			}
			else
			{
				helper->SetVF(
					static_cast<std::size_t>(x),
					reinterpret_cast<::VehicleFactoryGameObj*>(currentFactory->VehicleFactoryGameObjPointer.ToPointer()));
			}
		}
	}
}