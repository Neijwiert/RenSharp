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
#include "Mda_damagelog.h"

#include "Imports.h"
#include "McPlayer.h"
#include "UnmanagedContainer.h"
#include "MDADamageTableStructDynamicVectorClass.h"
#include "MDADamageEventStructSList.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_damagelog.h>
#include <engine_game.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DADamageEventStruct::DADamageEventStruct()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateDADamageEventStruct()))
	{

	}

	DADamageEventStruct::DADamageEventStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IDADamageEventStruct^>^ DADamageEventStruct::CreateDADamageEventStruct()
	{
		return gcnew UnmanagedContainer<IDADamageEventStruct^>(gcnew DADamageEventStruct());
	}

	bool DADamageEventStruct::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDADamageEventStruct^ otherThis = dynamic_cast<IDADamageEventStruct^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DADamageEventStructPointer.Equals(otherThis->DADamageEventStructPointer);
	}

	IntPtr DADamageEventStruct::DADamageEventStructPointer::get()
	{
		return IntPtr(InternalDADamageEventStructPointer);
	}

	float DADamageEventStruct::Damage::get()
	{
		return InternalDADamageEventStructPointer->Damage;
	}

	void DADamageEventStruct::Damage::set(float value)
	{
		InternalDADamageEventStructPointer->Damage = value;
	}

	IcPlayer^ DADamageEventStruct::Player::get()
	{
		auto result = InternalDADamageEventStructPointer->Player;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	void DADamageEventStruct::Player::set(IcPlayer^ value)
	{
		if (value == nullptr || value->cPlayerPointer.ToPointer() == nullptr)
		{
			InternalDADamageEventStructPointer->Player = nullptr;
		}
		else
		{
			InternalDADamageEventStructPointer->Player = reinterpret_cast<::cPlayer*>(value->cPlayerPointer.ToPointer());
		}
	}

	unsigned int DADamageEventStruct::Time::get()
	{
		return InternalDADamageEventStructPointer->Time;
	}

	void DADamageEventStruct::Time::set(unsigned int value)
	{
		InternalDADamageEventStructPointer->Time = value;
	}

	bool DADamageEventStruct::InternalDestroyPointer()
	{
		Imports::DestroyDADamageEventStruct(InternalDADamageEventStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DADamageEventStruct* DADamageEventStruct::InternalDADamageEventStructPointer::get()
	{
		return reinterpret_cast<::DADamageEventStruct*>(Pointer.ToPointer());
	}

	DADamageTableStruct::DADamageTableStruct()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateDADamageTableStruct1()))
	{

	}

	DADamageTableStruct::DADamageTableStruct(IcPlayer^ player, float damage)
	{
		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		Pointer = IntPtr(Imports::CreateDADamageTableStruct2(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
			damage));
	}

	DADamageTableStruct::DADamageTableStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IDADamageTableStruct^>^ DADamageTableStruct::CreateDADamageTableStruct()
	{
		return gcnew UnmanagedContainer<IDADamageTableStruct^>(gcnew DADamageTableStruct());
	}

	IUnmanagedContainer<IDADamageTableStruct^>^ DADamageTableStruct::CreateDADamageTableStruct(IcPlayer^ player, float damage)
	{
		return gcnew UnmanagedContainer<IDADamageTableStruct^>(gcnew DADamageTableStruct(player, damage));
	}

	bool DADamageTableStruct::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDADamageTableStruct^ otherThis = dynamic_cast<IDADamageTableStruct^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DADamageTableStructPointer.Equals(otherThis->DADamageTableStructPointer);
	}

	IntPtr DADamageTableStruct::DADamageTableStructPointer::get()
	{
		return IntPtr(InternalDADamageTableStructPointer);
	}

	IcPlayer^ DADamageTableStruct::Player::get()
	{
		auto result = InternalDADamageTableStructPointer->Player;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	void DADamageTableStruct::Player::set(IcPlayer^ value)
	{
		if (value == nullptr || value->cPlayerPointer.ToPointer() == nullptr)
		{
			InternalDADamageTableStructPointer->Player = nullptr;
		}
		else
		{
			InternalDADamageTableStructPointer->Player = reinterpret_cast<::cPlayer*>(value->cPlayerPointer.ToPointer());
		}
	}

	float DADamageTableStruct::Damage::get()
	{
		return InternalDADamageTableStructPointer->Damage;
	}

	void DADamageTableStruct::Damage::set(float value)
	{
		InternalDADamageTableStructPointer->Damage = value;
	}

	bool DADamageTableStruct::InternalDestroyPointer()
	{
		Imports::DestroyDADamageTableStruct(InternalDADamageTableStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DADamageTableStruct* DADamageTableStruct::InternalDADamageTableStructPointer::get()
	{
		return reinterpret_cast<::DADamageTableStruct*>(Pointer.ToPointer());
	}

	DADamageLogObserverClass::DADamageLogObserverClass(IntPtr pointer)
		: DAGameObjObserverClass(pointer)
	{

	}

	void DADamageLogObserverClass::RemoveDamage(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		InternalDADamageLogObserverClassPointer->Remove_Damage(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	void DADamageLogObserverClass::ClearDamage()
	{
		InternalDADamageLogObserverClassPointer->Clear_Damage();
	}

	float DADamageLogObserverClass::CompileDamageTableTeam([Out] array<IUnmanagedContainer<IDADamageTableStruct^>^>^% damageTable, int team)
	{
		damageTable = nullptr;

		auto tmpTable = gcnew array<IUnmanagedContainer<IDADamageTableStruct^>^>(::NetworkObjectClass::MAX_CLIENT_COUNT);
		try
		{
			::DADamageTableStruct* tmpArray = Imports::CreateDADamageTableStructArray(tmpTable->Length);
			try
			{
				auto result = InternalDADamageLogObserverClassPointer->Compile_Damage_Table_Team(tmpArray, team);
				for (int x = 0; x < tmpTable->Length; x++)
				{
					tmpTable[x] = DADamageTableStruct::CreateDADamageTableStruct();
					auto currentTable = tmpTable[x];
					
					auto& unmanagedCurrentTable = tmpArray[x];

					(*reinterpret_cast<::DADamageTableStruct*>(currentTable->UnmanagedObject->DADamageTableStructPointer.ToPointer())) = unmanagedCurrentTable;
				}

				damageTable = tmpTable;
				tmpTable = nullptr;

				return result;
			}
			finally
			{
				Imports::DestroyDADamageTableStructArray(tmpArray);
				tmpArray = nullptr;
			}
		}
		catch (Exception^)
		{
			if (tmpTable != nullptr)
			{
				for (int x = 0; x < tmpTable->Length; x++)
				{
					auto currentTable = tmpTable[x];
					if (currentTable == nullptr)
					{
						continue;
					}

#pragma push_macro("delete")
#undef delete

					delete currentTable;
					currentTable = nullptr;

#pragma pop_macro("delete")
				}

				tmpTable = nullptr;
			}

			throw;
		}
	}

	float DADamageLogObserverClass::CompileDamageTableOtherTeam([Out] array<IUnmanagedContainer<IDADamageTableStruct^>^>^% damageTable, int team)
	{
		damageTable = nullptr;

		auto tmpTable = gcnew array<IUnmanagedContainer<IDADamageTableStruct^>^>(::NetworkObjectClass::MAX_CLIENT_COUNT);
		try
		{
			::DADamageTableStruct* tmpArray = Imports::CreateDADamageTableStructArray(tmpTable->Length);
			try
			{
				auto result = InternalDADamageLogObserverClassPointer->Compile_Damage_Table_Other_Team(tmpArray, team);
				for (int x = 0; x < tmpTable->Length; x++)
				{
					tmpTable[x] = DADamageTableStruct::CreateDADamageTableStruct();
					auto currentTable = tmpTable[x];

					auto& unmanagedCurrentTable = tmpArray[x];

					(*reinterpret_cast<::DADamageTableStruct*>(currentTable->UnmanagedObject->DADamageTableStructPointer.ToPointer())) = unmanagedCurrentTable;
				}

				damageTable = tmpTable;
				tmpTable = nullptr;

				return result;
			}
			finally
			{
				Imports::DestroyDADamageTableStructArray(tmpArray);
				tmpArray = nullptr;
			}
		}
		catch (Exception^)
		{
			if (tmpTable != nullptr)
			{
				for (int x = 0; x < tmpTable->Length; x++)
				{
					auto currentTable = tmpTable[x];
					if (currentTable == nullptr)
					{
						continue;
					}

#pragma push_macro("delete")
#undef delete

					delete currentTable;
					currentTable = nullptr;

#pragma pop_macro("delete")
				}

				tmpTable = nullptr;
			}

			throw;
		}
	}

	IUnmanagedContainer<IDynamicVectorClass<IDADamageTableStruct^>^>^ DADamageLogObserverClass::GetDamagersByPercentTeam(int team, float minimumPercentTotal, float minimumPercentHighest)
	{
		auto result = DADamageTableStructDynamicVectorClass::CreateDADamageTableStructDynamicVectorClass();
		try
		{
			InternalDADamageLogObserverClassPointer->Get_Damagers_By_Percent_Team(
				*reinterpret_cast<::DynamicVectorClass<::DADamageTableStruct>*>(result->UnmanagedObject->Pointer.ToPointer()),
				team,
				minimumPercentTotal,
				minimumPercentHighest);

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

	IUnmanagedContainer<IDynamicVectorClass<IDADamageTableStruct^>^>^ DADamageLogObserverClass::GetDamagersByPercentOtherTeam(int team, float minimumPercentTotal, float minimumPercentHighest)
	{
		auto result = DADamageTableStructDynamicVectorClass::CreateDADamageTableStructDynamicVectorClass();
		try
		{
			InternalDADamageLogObserverClassPointer->Get_Damagers_By_Percent_Other_Team(
				*reinterpret_cast<::DynamicVectorClass<::DADamageTableStruct>*>(result->UnmanagedObject->Pointer.ToPointer()),
				team,
				minimumPercentTotal,
				minimumPercentHighest);

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

	IcPlayer^ DADamageLogObserverClass::GetHighestDamagerTeam(int team)
	{
		auto result = InternalDADamageLogObserverClassPointer->Get_Highest_Damager_Team(team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	IcPlayer^ DADamageLogObserverClass::GetHighestDamagerOtherTeam(int team)
	{
		auto result = InternalDADamageLogObserverClassPointer->Get_Highest_Damager_Other_Team(team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	float DADamageLogObserverClass::GetPercentTeamDamage(int team)
	{
		return InternalDADamageLogObserverClassPointer->Get_Percent_Team_Damage(team);
	}

	float DADamageLogObserverClass::GetPercentOtherTeamDamage(int team)
	{
		return InternalDADamageLogObserverClassPointer->Get_Percent_Other_Team_Damage(team);
	}

	float DADamageLogObserverClass::GetPercentPlayerDamage(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		return InternalDADamageLogObserverClassPointer->Get_Percent_Player_Damage(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	float DADamageLogObserverClass::CompileRepairTableTeam([Out] array<IUnmanagedContainer<IDADamageTableStruct^>^>^% damageTable, int team)
	{
		damageTable = nullptr;

		auto tmpTable = gcnew array<IUnmanagedContainer<IDADamageTableStruct^>^>(::NetworkObjectClass::MAX_CLIENT_COUNT);
		try
		{
			::DADamageTableStruct* tmpArray = Imports::CreateDADamageTableStructArray(tmpTable->Length);
			try
			{
				auto result = InternalDADamageLogObserverClassPointer->Compile_Repair_Table_Team(tmpArray, team);
				for (int x = 0; x < tmpTable->Length; x++)
				{
					tmpTable[x] = DADamageTableStruct::CreateDADamageTableStruct();
					auto currentTable = tmpTable[x];

					auto& unmanagedCurrentTable = tmpArray[x];

					(*reinterpret_cast<::DADamageTableStruct*>(currentTable->UnmanagedObject->DADamageTableStructPointer.ToPointer())) = unmanagedCurrentTable;
				}

				damageTable = tmpTable;
				tmpTable = nullptr;

				return result;
			}
			finally
			{
				Imports::DestroyDADamageTableStructArray(tmpArray);
				tmpArray = nullptr;
			}
		}
		catch (Exception^)
		{
			if (tmpTable != nullptr)
			{
				for (int x = 0; x < tmpTable->Length; x++)
				{
					auto currentTable = tmpTable[x];
					if (currentTable == nullptr)
					{
						continue;
					}

#pragma push_macro("delete")
#undef delete

					delete currentTable;
					currentTable = nullptr;

#pragma pop_macro("delete")
				}

				tmpTable = nullptr;
			}

			throw;
		}
	}

	float DADamageLogObserverClass::CompileRepairTableOtherTeam([Out] array<IUnmanagedContainer<IDADamageTableStruct^>^>^% damageTable, int team)
	{
		damageTable = nullptr;

		auto tmpTable = gcnew array<IUnmanagedContainer<IDADamageTableStruct^>^>(::NetworkObjectClass::MAX_CLIENT_COUNT);
		try
		{
			::DADamageTableStruct* tmpArray = Imports::CreateDADamageTableStructArray(tmpTable->Length);
			try
			{
				auto result = InternalDADamageLogObserverClassPointer->Compile_Repair_Table_Other_Team(tmpArray, team);
				for (int x = 0; x < tmpTable->Length; x++)
				{
					tmpTable[x] = DADamageTableStruct::CreateDADamageTableStruct();
					auto currentTable = tmpTable[x];

					auto& unmanagedCurrentTable = tmpArray[x];

					(*reinterpret_cast<::DADamageTableStruct*>(currentTable->UnmanagedObject->DADamageTableStructPointer.ToPointer())) = unmanagedCurrentTable;
				}

				damageTable = tmpTable;
				tmpTable = nullptr;

				return result;
			}
			finally
			{
				Imports::DestroyDADamageTableStructArray(tmpArray);
				tmpArray = nullptr;
			}
		}
		catch (Exception^)
		{
			if (tmpTable != nullptr)
			{
				for (int x = 0; x < tmpTable->Length; x++)
				{
					auto currentTable = tmpTable[x];
					if (currentTable == nullptr)
					{
						continue;
					}

#pragma push_macro("delete")
#undef delete

					delete currentTable;
					currentTable = nullptr;

#pragma pop_macro("delete")
				}

				tmpTable = nullptr;
			}

			throw;
		}
	}

	IUnmanagedContainer<IDynamicVectorClass<IDADamageTableStruct^>^>^ DADamageLogObserverClass::GetRepairersByPercentTeam(int team, float minimumPercentTotal, float minimumPercentHighest)
	{
		auto result = DADamageTableStructDynamicVectorClass::CreateDADamageTableStructDynamicVectorClass();
		try
		{
			InternalDADamageLogObserverClassPointer->Get_Repairers_By_Percent_Team(
				*reinterpret_cast<::DynamicVectorClass<::DADamageTableStruct>*>(result->UnmanagedObject->Pointer.ToPointer()),
				team,
				minimumPercentTotal,
				minimumPercentHighest);

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

	IUnmanagedContainer<IDynamicVectorClass<IDADamageTableStruct^>^>^ DADamageLogObserverClass::GetRepairersByPercentOtherTeam(int team, float minimumPercentTotal, float minimumPercentHighest)
	{
		auto result = DADamageTableStructDynamicVectorClass::CreateDADamageTableStructDynamicVectorClass();
		try
		{
			InternalDADamageLogObserverClassPointer->Get_Repairers_By_Percent_Other_Team(
				*reinterpret_cast<::DynamicVectorClass<::DADamageTableStruct>*>(result->UnmanagedObject->Pointer.ToPointer()),
				team,
				minimumPercentTotal,
				minimumPercentHighest);

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

	IcPlayer^ DADamageLogObserverClass::GetHighestRepairerTeam(int team)
	{
		auto result = InternalDADamageLogObserverClassPointer->Get_Highest_Repairer_Team(team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	IcPlayer^ DADamageLogObserverClass::GetHighestRepairerOtherTeam(int team)
	{
		auto result = InternalDADamageLogObserverClassPointer->Get_Highest_Repairer_Other_Team(team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	float DADamageLogObserverClass::GetPercentTeamRepairs(int team)
	{
		return InternalDADamageLogObserverClassPointer->Get_Percent_Team_Repairs(team);
	}

	float DADamageLogObserverClass::GetPercentOtherTeamRepairs(int team)
	{
		return InternalDADamageLogObserverClassPointer->Get_Percent_Other_Team_Repairs(team);
	}

	float DADamageLogObserverClass::GetPercentPlayerRepairs(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		return InternalDADamageLogObserverClassPointer->Get_Percent_Player_Repairs(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	IntPtr DADamageLogObserverClass::DADamageLogObserverClassPointer::get()
	{
		return IntPtr(InternalDADamageLogObserverClassPointer);
	}

	ISList<IDADamageEventStruct^>^ DADamageLogObserverClass::DamageEvents::get()
	{
		auto result = InternalDADamageLogObserverClassPointer->Get_Damage_Events();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DADamageEventStructSList(IntPtr(const_cast<::SList<::DADamageEventStruct>*>(result)));
		}
	}

	IDADamageEventStruct^ DADamageLogObserverClass::LastDamageEvent::get()
	{
		auto result = InternalDADamageLogObserverClassPointer->Get_Last_Damage_Event();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DADamageEventStruct(IntPtr(const_cast<::DADamageEventStruct*>(result)));
		}
	}

	IDADamageEventStruct^ DADamageLogObserverClass::LastRepairEvent::get()
	{
		auto result = InternalDADamageLogObserverClassPointer->Get_Last_Repair_Event();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DADamageEventStruct(IntPtr(const_cast<::DADamageEventStruct*>(result)));
		}
	}

	::DAGameObjObserverClass* DADamageLogObserverClass::InternalDAGameObjObserverClassPointer::get()
	{
		return InternalDADamageLogObserverClassPointer;
	}

	::DADamageLogObserverClass* DADamageLogObserverClass::InternalDADamageLogObserverClassPointer::get()
	{
		return reinterpret_cast<::DADamageLogObserverClass*>(Pointer.ToPointer());
	}

	DADamageLog::DADamageLog(IntPtr pointer)
		: DAEventClass(pointer)
	{

	}

	IDADamageLogObserverClass^ DADamageLog::GetDamageLog(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::DADamageLog::Get_Damage_Log(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DADamageLogObserverClass(IntPtr(result));
		}
	}

	ISList<IDADamageEventStruct^>^ DADamageLog::GetDamageEvents(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::DADamageLog::Get_Damage_Events(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DADamageEventStructSList(IntPtr(const_cast<::SList<::DADamageEventStruct>*>(result)));
		}
	}

	float DADamageLog::CompileDamageTableTeam([Out] array<IUnmanagedContainer<IDADamageTableStruct^>^>^% damageTable, IScriptableGameObj^ obj, int team)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		damageTable = nullptr;

		auto tmpTable = gcnew array<IUnmanagedContainer<IDADamageTableStruct^>^>(::NetworkObjectClass::MAX_CLIENT_COUNT);
		try
		{
			::DADamageTableStruct* tmpArray = Imports::CreateDADamageTableStructArray(tmpTable->Length);
			try
			{
				auto result = ::DADamageLog::Compile_Damage_Table_Team(
					tmpArray,
					reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
					team);
				for (int x = 0; x < tmpTable->Length; x++)
				{
					tmpTable[x] = DADamageTableStruct::CreateDADamageTableStruct();
					auto currentTable = tmpTable[x];

					auto& unmanagedCurrentTable = tmpArray[x];

					(*reinterpret_cast<::DADamageTableStruct*>(currentTable->UnmanagedObject->DADamageTableStructPointer.ToPointer())) = unmanagedCurrentTable;
				}

				damageTable = tmpTable;
				tmpTable = nullptr;

				return result;
			}
			finally
			{
				Imports::DestroyDADamageTableStructArray(tmpArray);
				tmpArray = nullptr;
			}
		}
		catch (Exception^)
		{
			if (tmpTable != nullptr)
			{
				for (int x = 0; x < tmpTable->Length; x++)
				{
					auto currentTable = tmpTable[x];
					if (currentTable == nullptr)
					{
						continue;
					}

#pragma push_macro("delete")
#undef delete

					delete currentTable;
					currentTable = nullptr;

#pragma pop_macro("delete")
				}

				tmpTable = nullptr;
			}

			throw;
		}
	}

	float DADamageLog::CompileDamageTableOtherTeam([Out] array<IUnmanagedContainer<IDADamageTableStruct^>^>^% damageTable, IScriptableGameObj^ obj, int team)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		damageTable = nullptr;

		auto tmpTable = gcnew array<IUnmanagedContainer<IDADamageTableStruct^>^>(::NetworkObjectClass::MAX_CLIENT_COUNT);
		try
		{
			::DADamageTableStruct* tmpArray = Imports::CreateDADamageTableStructArray(tmpTable->Length);
			try
			{
				auto result = ::DADamageLog::Compile_Damage_Table_Other_Team(
					tmpArray,
					reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
					team);
				for (int x = 0; x < tmpTable->Length; x++)
				{
					tmpTable[x] = DADamageTableStruct::CreateDADamageTableStruct();
					auto currentTable = tmpTable[x];

					auto& unmanagedCurrentTable = tmpArray[x];

					(*reinterpret_cast<::DADamageTableStruct*>(currentTable->UnmanagedObject->DADamageTableStructPointer.ToPointer())) = unmanagedCurrentTable;
				}

				damageTable = tmpTable;
				tmpTable = nullptr;

				return result;
			}
			finally
			{
				Imports::DestroyDADamageTableStructArray(tmpArray);
				tmpArray = nullptr;
			}
		}
		catch (Exception^)
		{
			if (tmpTable != nullptr)
			{
				for (int x = 0; x < tmpTable->Length; x++)
				{
					auto currentTable = tmpTable[x];
					if (currentTable == nullptr)
					{
						continue;
					}

#pragma push_macro("delete")
#undef delete

					delete currentTable;
					currentTable = nullptr;

#pragma pop_macro("delete")
				}

				tmpTable = nullptr;
			}

			throw;
		}
	}

	IUnmanagedContainer<IDynamicVectorClass<IDADamageTableStruct^>^>^ DADamageLog::GetDamagersByPercentTeam(IScriptableGameObj^ obj, int team, float minimumPercentTotal, float minimumPercentHighest)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = DADamageTableStructDynamicVectorClass::CreateDADamageTableStructDynamicVectorClass();
		try
		{
			::DADamageLog::Get_Damagers_By_Percent_Team(
				*reinterpret_cast<::DynamicVectorClass<::DADamageTableStruct>*>(result->UnmanagedObject->Pointer.ToPointer()),
				reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
				team,
				minimumPercentTotal,
				minimumPercentHighest);

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

	IUnmanagedContainer<IDynamicVectorClass<IDADamageTableStruct^>^>^ DADamageLog::GetDamagersByPercentOtherTeam(IScriptableGameObj^ obj, int team, float minimumPercentTotal, float minimumPercentHighest)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = DADamageTableStructDynamicVectorClass::CreateDADamageTableStructDynamicVectorClass();
		try
		{
			::DADamageLog::Get_Damagers_By_Percent_Other_Team(
				*reinterpret_cast<::DynamicVectorClass<::DADamageTableStruct>*>(result->UnmanagedObject->Pointer.ToPointer()),
				reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
				team,
				minimumPercentTotal,
				minimumPercentHighest);

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

	IcPlayer^ DADamageLog::GetHighestDamagerTeam(IScriptableGameObj^ obj, int team)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::DADamageLog::Get_Highest_Damager_Team(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
			team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	IcPlayer^ DADamageLog::GetHighestDamagerOtherTeam(IScriptableGameObj^ obj, int team)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::DADamageLog::Get_Highest_Damager_Other_Team(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
			team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	float DADamageLog::GetPercentTeamDamage(IScriptableGameObj^ obj, int team)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::DADamageLog::Get_Percent_Team_Damage(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
			team);
	}

	float DADamageLog::GetPercentOtherTeamDamage(IScriptableGameObj^ obj, int team)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::DADamageLog::Get_Percent_Other_Team_Damage(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
			team);
	}

	float DADamageLog::GetPercentPlayerDamage(IScriptableGameObj^ obj, IcPlayer^ player)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		return ::DADamageLog::Get_Percent_Player_Damage(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	IDADamageEventStruct^ DADamageLog::GetLastDamageEvent(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::DADamageLog::Get_Last_Damage_Event(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DADamageEventStruct(IntPtr(const_cast<::DADamageEventStruct*>(result)));
		}
	}

	float DADamageLog::CompileRepairTableTeam([Out] array<IUnmanagedContainer<IDADamageTableStruct^>^>^% damageTable, IScriptableGameObj^ obj, int team)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		damageTable = nullptr;

		auto tmpTable = gcnew array<IUnmanagedContainer<IDADamageTableStruct^>^>(::NetworkObjectClass::MAX_CLIENT_COUNT);
		try
		{
			::DADamageTableStruct* tmpArray = Imports::CreateDADamageTableStructArray(tmpTable->Length);
			try
			{
				auto result = ::DADamageLog::Compile_Repair_Table_Team(
					tmpArray,
					reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
					team);
				for (int x = 0; x < tmpTable->Length; x++)
				{
					tmpTable[x] = DADamageTableStruct::CreateDADamageTableStruct();
					auto currentTable = tmpTable[x];

					auto& unmanagedCurrentTable = tmpArray[x];

					(*reinterpret_cast<::DADamageTableStruct*>(currentTable->UnmanagedObject->DADamageTableStructPointer.ToPointer())) = unmanagedCurrentTable;
				}

				damageTable = tmpTable;
				tmpTable = nullptr;

				return result;
			}
			finally
			{
				Imports::DestroyDADamageTableStructArray(tmpArray);
				tmpArray = nullptr;
			}
		}
		catch (Exception^)
		{
			if (tmpTable != nullptr)
			{
				for (int x = 0; x < tmpTable->Length; x++)
				{
					auto currentTable = tmpTable[x];
					if (currentTable == nullptr)
					{
						continue;
					}

#pragma push_macro("delete")
#undef delete

					delete currentTable;
					currentTable = nullptr;

#pragma pop_macro("delete")
				}

				tmpTable = nullptr;
			}

			throw;
		}
	}

	float DADamageLog::CompileRepairTableOtherTeam([Out] array<IUnmanagedContainer<IDADamageTableStruct^>^>^% damageTable, IScriptableGameObj^ obj, int team)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		damageTable = nullptr;

		auto tmpTable = gcnew array<IUnmanagedContainer<IDADamageTableStruct^>^>(::NetworkObjectClass::MAX_CLIENT_COUNT);
		try
		{
			::DADamageTableStruct* tmpArray = Imports::CreateDADamageTableStructArray(tmpTable->Length);
			try
			{
				auto result = ::DADamageLog::Compile_Repair_Table_Other_Team(
					tmpArray,
					reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
					team);
				for (int x = 0; x < tmpTable->Length; x++)
				{
					tmpTable[x] = DADamageTableStruct::CreateDADamageTableStruct();
					auto currentTable = tmpTable[x];

					auto& unmanagedCurrentTable = tmpArray[x];

					(*reinterpret_cast<::DADamageTableStruct*>(currentTable->UnmanagedObject->DADamageTableStructPointer.ToPointer())) = unmanagedCurrentTable;
				}

				damageTable = tmpTable;
				tmpTable = nullptr;

				return result;
			}
			finally
			{
				Imports::DestroyDADamageTableStructArray(tmpArray);
				tmpArray = nullptr;
			}
		}
		catch (Exception^)
		{
			if (tmpTable != nullptr)
			{
				for (int x = 0; x < tmpTable->Length; x++)
				{
					auto currentTable = tmpTable[x];
					if (currentTable == nullptr)
					{
						continue;
					}

#pragma push_macro("delete")
#undef delete

					delete currentTable;
					currentTable = nullptr;

#pragma pop_macro("delete")
				}

				tmpTable = nullptr;
			}

			throw;
		}
	}

	IUnmanagedContainer<IDynamicVectorClass<IDADamageTableStruct^>^>^ DADamageLog::GetRepairersByPercentTeam(IScriptableGameObj^ obj, int team, float minimumPercentTotal, float minimumPercentHighest)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = DADamageTableStructDynamicVectorClass::CreateDADamageTableStructDynamicVectorClass();
		try
		{
			::DADamageLog::Get_Repairers_By_Percent_Team(
				*reinterpret_cast<::DynamicVectorClass<::DADamageTableStruct>*>(result->UnmanagedObject->Pointer.ToPointer()),
				reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
				team,
				minimumPercentTotal,
				minimumPercentHighest);

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

	IUnmanagedContainer<IDynamicVectorClass<IDADamageTableStruct^>^>^ DADamageLog::GetRepairersByPercentOtherTeam(IScriptableGameObj^ obj, int team, float minimumPercentTotal, float minimumPercentHighest)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = DADamageTableStructDynamicVectorClass::CreateDADamageTableStructDynamicVectorClass();
		try
		{
			::DADamageLog::Get_Repairers_By_Percent_Other_Team(
				*reinterpret_cast<::DynamicVectorClass<::DADamageTableStruct>*>(result->UnmanagedObject->Pointer.ToPointer()),
				reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
				team,
				minimumPercentTotal,
				minimumPercentHighest);

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

	IcPlayer^ DADamageLog::GetHighestRepairerTeam(IScriptableGameObj^ obj, int team)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::DADamageLog::Get_Highest_Repairer_Team(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
			team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	IcPlayer^ DADamageLog::GetHighestRepairerOtherTeam(IScriptableGameObj^ obj, int team)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::DADamageLog::Get_Highest_Repairer_Other_Team(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
			team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	float DADamageLog::GetPercentTeamRepairs(IScriptableGameObj^ obj, int team)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::DADamageLog::Get_Percent_Team_Repairs(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
			team);
	}

	float DADamageLog::GetPercentOtherTeamRepairs(IScriptableGameObj^ obj, int team)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::DADamageLog::Get_Percent_Other_Team_Repairs(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
			team);
	}

	float DADamageLog::GetPercentPlayerRepairs(IScriptableGameObj^ obj, IcPlayer^ player)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		return ::DADamageLog::Get_Percent_Player_Repairs(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	IDADamageEventStruct^ DADamageLog::GetLastRepairEvent(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::DADamageLog::Get_Last_Repair_Event(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DADamageEventStruct(IntPtr(const_cast<::DADamageEventStruct*>(result)));
		}
	}

	IntPtr DADamageLog::DADamageLogPointer::get()
	{
		return IntPtr(InternalDADamageLogPointer);
	}

	::DAEventClass* DADamageLog::InternalDAEventClassPointer::get()
	{
		return InternalDADamageLogPointer;
	}

	::DADamageLog* DADamageLog::InternalDADamageLogPointer::get()
	{
		return reinterpret_cast<::DADamageLog*>(Pointer.ToPointer());
	}
}