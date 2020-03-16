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
#include "MGameData.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)

REF_DEF2(bool, cGameData::IsManualExit, 0x0082F125, 0x0082E30D);
REF_DEF2(bool, cGameData::IsManualRestart, 0x0082F124, 0x0082E30C);

#pragma warning(pop) 
#pragma managed(pop)

#include "Imports.h"
#include "UnmanagedContainer.h"
#include "McPlayer.h"
#include "MSoldierGameObj.h"
#include "MWideStringClassDynamicVectorClass.h"
#include "MBaseControllerClass.h"

using namespace System::Text;

namespace RenSharp
{
	cGameDataEvent::cGameDataEvent(bool a, int b)
		: TypedEventPair<bool, int>(IntPtr(Imports::CreatecGameDataEvent(a, b)))
	{

	}

	cGameDataEvent::cGameDataEvent(IntPtr pointer)
		: TypedEventPair<bool, int>(pointer)
	{

	}

	IUnmanagedContainer<ITypedEventPair<bool, int>^>^ cGameDataEvent::CreatecGameDataEvent(bool a, int b)
	{
		return gcnew UnmanagedContainer<ITypedEventPair<bool, int>^>(gcnew cGameDataEvent(a, b));
	}

	IntPtr cGameDataEvent::cGameDataEventPointer::get()
	{
		return IntPtr(InternalcGameDataEventPointer);
	}

	bool cGameDataEvent::ItemA::get()
	{
		return InternalcGameDataEventPointer->GetItemA();
	}

	void cGameDataEvent::ItemA::set(bool value)
	{
		auto helper = reinterpret_cast<TypedEventPairHelper<bool, int>*>(InternalcGameDataEventPointer);

		auto& itemA = helper->GetmItemA();

		itemA = value;
	}

	int cGameDataEvent::ItemB::get()
	{
		return InternalcGameDataEventPointer->GetItemB();
	}

	void cGameDataEvent::ItemB::set(int value)
	{
		auto helper = reinterpret_cast<TypedEventPairHelper<bool, int>*>(InternalcGameDataEventPointer);

		auto& itemB = helper->GetmItemB();

		itemB = value;
	}

	bool cGameDataEvent::InternalDestroyPointer()
	{
		Imports::DestroycGameDataEvent(InternalcGameDataEventPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::cGameDataEvent* cGameDataEvent::InternalcGameDataEventPointer::get()
	{
		return reinterpret_cast<::cGameDataEvent*>(Pointer.ToPointer());
	}

	cGameDataEventSignaler::cGameDataEventSignaler()
		: Signaler<ITypedEventPair<bool, int>^>(IntPtr(Imports::CreatecGameDataEventSignaler()))
	{

	}

	cGameDataEventSignaler::cGameDataEventSignaler(IntPtr pointer)
		: Signaler<ITypedEventPair<bool, int>^>(pointer)
	{

	}

	IUnmanagedContainer<ISignaler<ITypedEventPair<bool, int>^>^>^ cGameDataEventSignaler::CreatecGameDataEventSignaler()
	{
		return gcnew UnmanagedContainer<ISignaler<ITypedEventPair<bool, int>^>^>(gcnew cGameDataEventSignaler());
	}

	void cGameDataEventSignaler::SendSignal(ITypedEventPair<bool, int>^ signal)
	{
		if (signal == nullptr || signal->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("signal");
		}

		InternalcGameDataEventSignalerPointer->SendSignal(
			*reinterpret_cast<::cGameDataEvent*>(signal->Pointer.ToPointer()));
	}

	void cGameDataEventSignaler::ReceiveSignal(ITypedEventPair<bool, int>^ signal)
	{
		if (signal == nullptr || signal->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("signal");
		}

		InternalcGameDataEventSignalerPointer->ReceiveSignal(
			*reinterpret_cast<::cGameDataEvent*>(signal->Pointer.ToPointer()));
	}

	void cGameDataEventSignaler::SignalDropped(ISignaler<ITypedEventPair<bool, int>^>^ signaler)
	{
		if (signaler == nullptr || signaler->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("signaler");
		}

		InternalcGameDataEventSignalerPointer->SignalDropped(
			*reinterpret_cast<::Signaler<::cGameDataEvent>*>(signaler->Pointer.ToPointer()));
	}

	void cGameDataEventSignaler::SignalMe(ISignaler<ITypedEventPair<bool, int>^>^ signaler)
	{
		if (signaler == nullptr || signaler->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("signaler");
		}

		InternalcGameDataEventSignalerPointer->SignalMe(
			*reinterpret_cast<::Signaler<::cGameDataEvent>*>(signaler->Pointer.ToPointer()));
	}

	ISignaler<ITypedEventPair<bool, int>^>^ cGameDataEventSignaler::Forward::get()
	{
		auto result = InternalcGameDataEventSignalerPointer->Forward;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cGameDataEventSignaler(IntPtr(result));
		}
	}

	void cGameDataEventSignaler::Forward::set(ISignaler<ITypedEventPair<bool, int>^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			InternalcGameDataEventSignalerPointer->Forward = nullptr;
		}
		else
		{
			InternalcGameDataEventSignalerPointer->Forward = reinterpret_cast<::Signaler<::cGameDataEvent>*>(value->Pointer.ToPointer());
		}
	}

	IntPtr cGameDataEventSignaler::cGameDataEventSignalerPointer::get()
	{
		return IntPtr(InternalcGameDataEventSignalerPointer);
	}

	bool cGameDataEventSignaler::InternalDestroyPointer()
	{
		Imports::DestroycGameDataEventSignaler(InternalcGameDataEventSignalerPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::Signaler<::cGameDataEvent>* cGameDataEventSignaler::InternalcGameDataEventSignalerPointer::get()
	{
		return reinterpret_cast<::Signaler<::cGameDataEvent>*>(Pointer.ToPointer());
	}

	cGameData::cGameData(IntPtr pointer)
		: cGameDataEventSignaler(pointer)
	{

	}

	int cGameData::GetMissionNumberFromMapName(String^ mapName)
	{
		if (mapName == nullptr)
		{
			throw gcnew ArgumentNullException("mapName");
		}

		IntPtr mapNameHandle = Marshal::StringToHGlobalAnsi(mapName);
		try
		{
			return ::cGameData::Get_Mission_Number_From_Map_Name(
				reinterpret_cast<char*>(mapNameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(mapNameHandle);
		}
	}

	String^ cGameData::ToString()
	{
		StringBuilder^ builder = gcnew StringBuilder();
		builder->Append(GameName);

		return builder->ToString();
	}

	bool cGameData::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IcGameData^ otherThis = dynamic_cast<IcGameData^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return cGameDataPointer.Equals(otherThis->cGameDataPointer);
	}

	void cGameData::OnGameBegin()
	{
		InternalcGameDataPointer->On_Game_Begin();
	}

	void cGameData::OnGameEnd()
	{
		InternalcGameDataPointer->On_Game_End();
	}

	void cGameData::Think()
	{
		InternalcGameDataPointer->Think();
	}

	void cGameData::Render()
	{
		InternalcGameDataPointer->Render();
	}

	void cGameData::ResetGame(bool skipPlayerReset)
	{
		InternalcGameDataPointer->Reset_Game(skipPlayerReset);
	}

	int cGameData::ChoosePlayerType(IcPlayer^ player, int type, bool skipAutoTeam)
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

		return InternalcGameDataPointer->Choose_Player_Type(
			playerPtr,
			type,
			skipAutoTeam);
	}

	void cGameData::LoadFromServerConfig()
	{
		InternalcGameDataPointer->Load_From_Server_Config();
	}

	void cGameData::SaveToServerConfig()
	{
		InternalcGameDataPointer->Save_To_Server_Config();
	}

	void cGameData::SoldierAdded(ISoldierGameObj^ obj)
	{
		if (obj == nullptr || obj->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalcGameDataPointer->Soldier_Added(
			reinterpret_cast<::SoldierGameObj*>(obj->SoldierGameObjPointer.ToPointer()));
	}

	void cGameData::ShowGameSettingsLimits()
	{
		InternalcGameDataPointer->Show_Game_Settings_Limits();
	}

	IcGameDataSinglePlayer^ cGameData::AsSinglePlayer()
	{
		auto result = InternalcGameDataPointer->As_Single_Player();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cGameDataSinglePlayer(IntPtr(result));
		}
	}

	IcGameDataSkirmish^ cGameData::AsSkirmish()
	{
		auto result = InternalcGameDataPointer->As_Skirmish();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cGameDataSkirmish(IntPtr(result));
		}
	}

	IcGameDataCnC^ cGameData::AsCnC()
	{
		auto result = InternalcGameDataPointer->As_Cnc();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cGameDataCnC(IntPtr(result));
		}
	}

	bool cGameData::IsValidSettings([Out] String^% errorString, bool b)
	{
		errorString = nullptr;

		::WideStringClass tmp;

		bool result = InternalcGameDataPointer->Is_Valid_Settings(tmp, b);

		errorString = gcnew String(tmp.Peek_Buffer());

		return result;
	}

	void cGameData::ExportTier1Data(IntPtr packet)
	{
		if (packet.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("packet");
		}

		InternalcGameDataPointer->Export_Tier_1_Data(
			*reinterpret_cast<::cPacket*>(packet.ToPointer()));
	}

	void cGameData::ImportTier1Data(IntPtr packet)
	{
		if (packet.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("packet");
		}

		InternalcGameDataPointer->Import_Tier_1_Data(
			*reinterpret_cast<::cPacket*>(packet.ToPointer()));
	}

	void cGameData::ImportTier1DataWOLGameInfo(IntPtr packet)
	{
		if (packet.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("packet");
		}

		InternalcGameDataPointer->Import_Tier_1_Data(
			*reinterpret_cast<::WOLGameInfo*>(packet.ToPointer()));
	}

	void cGameData::ExportTier2Data(IntPtr packet)
	{
		if (packet.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("packet");
		}

		InternalcGameDataPointer->Export_Tier_2_Data(
			*reinterpret_cast<::cPacket*>(packet.ToPointer()));
	}

	void cGameData::ImportTier2Data(IntPtr packet)
	{
		if (packet.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("packet");
		}

		InternalcGameDataPointer->Import_Tier_2_Data(
			*reinterpret_cast<::cPacket*>(packet.ToPointer()));
	}

	void cGameData::ResetTimeRemainingSeconds()
	{
		InternalcGameDataPointer->Reset_Time_Remaining_Seconds();
	}

	void cGameData::SetTimeLimitMinutes(int time)
	{
		InternalcGameDataPointer->Set_Time_Limit_Minutes(time);
	}

	String^ cGameData::GetMapCycle(int map)
	{
		if (map < 0 || map >= (sizeof(InternalcGameDataPointer->MapList) / sizeof(InternalcGameDataPointer->MapList[0])))
		{
			throw gcnew ArgumentOutOfRangeException("map");
		}

		return gcnew String(InternalcGameDataPointer->Get_Map_Cycle(map).Peek_Buffer());
	}

	void cGameData::SetMapCyle(int map, String^ name)
	{
		if (map < 0 || map >= (sizeof(InternalcGameDataPointer->MapList) / sizeof(InternalcGameDataPointer->MapList[0])))
		{
			throw gcnew ArgumentOutOfRangeException("map");
		}
		else if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			InternalcGameDataPointer->Set_Map_Cycle(
				map,
				reinterpret_cast<char*>(nameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	bool cGameData::IsValidPlayerType(int playerType)
	{
		return InternalcGameDataPointer->Is_Valid_Player_Type(playerType);
	}

	bool cGameData::IsManualExit::get()
	{
		return ::cGameData::Is_Manual_Exit();
	}

	void cGameData::IsManualExit::set(bool value)
	{
		::cGameData::Set_Manual_Exit(value);
	}

	bool cGameData::IsManualRestart::get()
	{
		return ::cGameData::Is_Manual_Restart();
	}

	void cGameData::IsManualRestart::set(bool value)
	{
		::cGameData::Set_Manual_Restart(value);
	}

	IntPtr cGameData::cGameDataPointer::get()
	{
		return IntPtr(InternalcGameDataPointer);
	}

	String^ cGameData::GameName::get()
	{
		auto result = InternalcGameDataPointer->Get_Game_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	IcGameData::GameTypeEnum cGameData::GameType::get()
	{
		return static_cast<IcGameData::GameTypeEnum>(InternalcGameDataPointer->Get_Game_Type());
	}

	bool cGameData::IsEditableTeaming::get()
	{
		return InternalcGameDataPointer->Is_Editable_Teaming();
	}

	bool cGameData::IsEditableClanGame::get()
	{
		return InternalcGameDataPointer->Is_Editable_Clan_Game();
	}

	bool cGameData::IsEditableFriendlyFire::get()
	{
		return InternalcGameDataPointer->Is_Editable_Friendly_Fire();
	}

	bool cGameData::IsSinglePlayer::get()
	{
		return InternalcGameDataPointer->Is_Single_Player();
	}

	bool cGameData::IsSkirmish::get()
	{
		return InternalcGameDataPointer->Is_Skirmish();
	}

	bool cGameData::IsCnC::get()
	{
		return InternalcGameDataPointer->Is_Cnc();
	}

	unsigned int cGameData::MinPlayers::get()
	{
		return InternalcGameDataPointer->Get_Min_Players();
	}

	bool cGameData::IsGameOver::get()
	{
		return InternalcGameDataPointer->Is_Game_Over();
	}

	bool cGameData::IsLimited::get()
	{
		return InternalcGameDataPointer->Is_Limited();
	}

	bool cGameData::IsGameplayPermitted::get()
	{
		return InternalcGameDataPointer->Is_Gameplay_Permitted();
	}

	bool cGameData::RememberInventory::get()
	{
		return InternalcGameDataPointer->Remember_Inventory();
	}

	String^ cGameData::Description::get()
	{
		::WideStringClass result;
		InternalcGameDataPointer->Get_Description(result);

		return gcnew String(result.Peek_Buffer());
	}

	float cGameData::TimeRemainingSeconds::get()
	{
		return InternalcGameDataPointer->Get_Time_Remaining_Seconds();
	}

	void cGameData::TimeRemainingSeconds::set(float value)
	{
		InternalcGameDataPointer->Set_Time_Remaining_Seconds(value);
	}

	bool cGameData::IsMapCycleOver::get()
	{
		return InternalcGameDataPointer->Is_Map_Cycle_Over();
	}

	void cGameData::IsMapCycleOver::set(bool value)
	{
		InternalcGameDataPointer->Set_Is_Map_Cycle_Over(value);
	}

	int cGameData::WinnerID::get()
	{
		return InternalcGameDataPointer->Get_Winner_ID();
	}

	void cGameData::WinnerID::set(int value)
	{
		InternalcGameDataPointer->Set_Winner_ID(value);
	}

	String^ cGameData::MOTD::get()
	{
		return gcnew String(InternalcGameDataPointer->Get_Motd().Peek_Buffer());
	}

	void cGameData::MOTD::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalUni(value);
		try
		{
			InternalcGameDataPointer->Set_Motd(
				reinterpret_cast<wchar_t*>(valueHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	String^ cGameData::MapName::get()
	{
		return gcnew String(InternalcGameDataPointer->Get_Map_Name().Peek_Buffer());
	}

	void cGameData::MapName::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(valueHandle.ToPointer()));

			InternalcGameDataPointer->Set_Map_Name(tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	RenSharp::RadarMode cGameData::RadarMode::get()
	{
		return static_cast<RenSharp::RadarMode>(InternalcGameDataPointer->Get_Radar_Mode());
	}

	void cGameData::RadarMode::set(RenSharp::RadarMode value)
	{
		InternalcGameDataPointer->Set_Radar_Mode(
			static_cast<::RadarModeEnum>(value));
	}

	String^ cGameData::MVPName::get()
	{
		return gcnew String(InternalcGameDataPointer->Get_Mvp_Name().Peek_Buffer());
	}

	void cGameData::MVPName::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalUni(value);
		try
		{
			InternalcGameDataPointer->MVPName = reinterpret_cast<wchar_t*>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	unsigned int cGameData::MVPCount::get()
	{
		return InternalcGameDataPointer->Get_Mvp_Count();
	}

	void cGameData::MVPCount::set(unsigned int value)
	{
		InternalcGameDataPointer->MVPCount = value;
	}

	unsigned int cGameData::TimeLimitMinutes::get()
	{
		return InternalcGameDataPointer->Get_Time_Limit_Minutes();
	}

	void cGameData::TimeLimitMinutes::set(unsigned int value)
	{
		InternalcGameDataPointer->TimeLimit_Minutes = value;
	}

	int cGameData::CurrentPlayers::get()
	{
		return InternalcGameDataPointer->Get_Current_Players();
	}

	void cGameData::CurrentPlayers::set(int value)
	{
		InternalcGameDataPointer->CurrentPlayers = value;
	}

	bool cGameData::IsFriendlyFirePermitted::get()
	{
		return InternalcGameDataPointer->Is_Friendly_Fire_Permitted();
	}

	void cGameData::IsFriendlyFirePermitted::set(bool value)
	{
		InternalcGameDataPointer->Set_Is_Friendly_Fire_Permitted(value);
	}

	unsigned int cGameData::GameDurationSeconds::get()
	{
		return InternalcGameDataPointer->Get_Game_Duration_S();
	}

	void cGameData::GameDurationSeconds::set(unsigned int value)
	{
		InternalcGameDataPointer->GameDuration_Seconds = value;
	}

	String^ cGameData::ModName::get()
	{
		return gcnew String(InternalcGameDataPointer->Get_Mod_Name().Peek_Buffer());
	}

	void cGameData::ModName::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalcGameDataPointer->ModName = reinterpret_cast<char*>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	unsigned int cGameData::MapNumber::get()
	{
		return InternalcGameDataPointer->Get_Map_Number();
	}

	void cGameData::MapNumber::set(unsigned int value)
	{
		InternalcGameDataPointer->MapNumber = value;
	}

	bool cGameData::IsDedicated::get()
	{
		return InternalcGameDataPointer->Is_Dedicated();
	}

	void cGameData::IsDedicated::set(bool value)
	{
		InternalcGameDataPointer->Set_Is_Dedicated(value);
	}

	int cGameData::MaxPlayers::get()
	{
		return InternalcGameDataPointer->Get_Max_Players();
	}

	void cGameData::MaxPlayers::set(int value)
	{
		InternalcGameDataPointer->MaxPlayers = value;
	}

	bool cGameData::IsLaddered::get()
	{
		return InternalcGameDataPointer->Is_Laddered();
	}

	void cGameData::IsLaddered::set(bool value)
	{
		InternalcGameDataPointer->Set_Is_Laddered(value);
	}

	bool cGameData::IsIntermission::get()
	{
		return InternalcGameDataPointer->Is_Intermission();
	}

	void cGameData::IsIntermission::set(bool value)
	{
		InternalcGameDataPointer->Set_Is_Intermission(value);
	}

	bool cGameData::IsTeamChangingAllowed::get()
	{
		return InternalcGameDataPointer->Is_Team_Changing_Allowed();
	}

	void cGameData::IsTeamChangingAllowed::set(bool value)
	{
		InternalcGameDataPointer->Set_Is_Team_Changing_Allowed(value);
	}

	bool cGameData::IsRemixTeams::get()
	{
		return InternalcGameDataPointer->Is_Remix_Teams();
	}

	void cGameData::IsRemixTeams::set(bool value)
	{
		InternalcGameDataPointer->Set_Remix_Teams(value);
	}

	bool cGameData::CanRepairBuildings::get()
	{
		return InternalcGameDataPointer->Can_Repair_Buildings();
	}

	void cGameData::CanRepairBuildings::set(bool value)
	{
		InternalcGameDataPointer->Set_Can_Repair_Buildings(value);
	}

	bool cGameData::DriverIsAlwaysGunner::get()
	{
		return InternalcGameDataPointer->Driver_Is_Always_Gunner();
	}

	void cGameData::DriverIsAlwaysGunner::set(bool value)
	{
		InternalcGameDataPointer->Set_Driver_Is_Always_Gunner(value);
	}

	bool cGameData::SpawnWeapons::get()
	{
		return InternalcGameDataPointer->Spawn_Weapons();
	}

	void cGameData::SpawnWeapons::set(bool value)
	{
		InternalcGameDataPointer->Set_Spawn_Weapons(value);
	}

	String^ cGameData::INIFilename::get()
	{
		return gcnew String(InternalcGameDataPointer->Get_Ini_Filename().Peek_Buffer());
	}

	void cGameData::INIFilename::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(valueHandle.ToPointer()));

			InternalcGameDataPointer->Set_Ini_Filename(tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	String^ cGameData::SettingsDescription::get()
	{
		return gcnew String(InternalcGameDataPointer->Get_Settings_Description().Peek_Buffer());
	}

	void cGameData::SettingsDescription::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(valueHandle.ToPointer()));

			InternalcGameDataPointer->Set_Settings_Description(tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	int cGameData::MinQualifyingTimeMinutes::get()
	{
		return InternalcGameDataPointer->Get_Min_Qualifying_Time_Minutes();
	}

	void cGameData::MinQualifyingTimeMinutes::set(int value)
	{
		InternalcGameDataPointer->MinQualifyingTime_Minutes = value;
	}

	bool cGameData::DoesMapExist::get()
	{
		return InternalcGameDataPointer->Does_Map_Exist();
	}

	String^ cGameData::MapBaseName::get()
	{
		return gcnew String(InternalcGameDataPointer->getMapBaseName().Peek_Buffer());
	}

	IPAddress^ cGameData::IP::get()
	{
		auto ipAddress = InternalcGameDataPointer->Get_Ip_Address();

		return gcnew IPAddress(gcnew array<std::uint8_t>
		{
			static_cast<std::uint8_t>((ipAddress & 0x000000FF) >> 0),
				static_cast<std::uint8_t>((ipAddress & 0x0000FF00) >> 8),
				static_cast<std::uint8_t>((ipAddress & 0x00FF0000) >> 16),
				static_cast<std::uint8_t>((ipAddress & 0xFF000000) >> 24)
		});
	}

	void cGameData::IP::set(IPAddress^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto bytes = value->GetAddressBytes();
		if (bytes->Length != 4)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		unsigned int ipAddress = 0;

		ipAddress |= (static_cast<int>(bytes[0]) << 0);
		ipAddress |= (static_cast<int>(bytes[1]) << 8);
		ipAddress |= (static_cast<int>(bytes[2]) << 16);
		ipAddress |= (static_cast<int>(bytes[3]) << 24);

		InternalcGameDataPointer->IP = ipAddress;
	}

	int cGameData::IntermissionTimeSeconds::get()
	{
		return InternalcGameDataPointer->Get_Intermission_Time_Seconds();
	}

	void cGameData::IntermissionTimeSeconds::set(int value)
	{
		InternalcGameDataPointer->IntermissionTime_Seconds = value;
	}

	bool cGameData::IsTimeLimt::get()
	{
		return InternalcGameDataPointer->Is_Time_Limit();
	}

	int cGameData::ExeKey::get()
	{
		return InternalcGameDataPointer->ExeKey;
	}

	void cGameData::ExeKey::set(int value)
	{
		InternalcGameDataPointer->ExeKey = value;
	}

	float cGameData::IntermissionTimeLeft::get()
	{
		return InternalcGameDataPointer->Get_Intermission_Time_Remaining();
	}

	void cGameData::IntermissionTimeLeft::set(float value)
	{
		InternalcGameDataPointer->IntermissionTimeLeft = value;
	}

	int cGameData::FrameCount::get()
	{
		return InternalcGameDataPointer->Get_Frame_Count();
	}

	void cGameData::FrameCount::set(int value)
	{
		InternalcGameDataPointer->FrameCount = value;
	}

	bool cGameData::IsAutoRestart::get()
	{
		return InternalcGameDataPointer->Is_Auto_Restart();
	}

	void cGameData::IsAutoRestart::set(bool value)
	{
		InternalcGameDataPointer->Set_Is_Auto_Restart(value);
	}

	bool cGameData::IsPassworded::get()
	{
		return InternalcGameDataPointer->Is_Passworded();
	}

	void cGameData::IsPassworded::set(bool value)
	{
		InternalcGameDataPointer->Set_Is_Passworded(value);
	}

	bool cGameData::GrantWeapons::get()
	{
		return InternalcGameDataPointer->GrantWeapons;
	}

	void cGameData::GrantWeapons::set(bool value)
	{
		InternalcGameDataPointer->GrantWeapons = value;
	}

	bool cGameData::IsClanGame::get()
	{
		return InternalcGameDataPointer->Is_Clan_Game();
	}

	void cGameData::IsClanGame::set(bool value)
	{
		InternalcGameDataPointer->Set_Is_Clan_Game(value);
	}

	bool cGameData::UseLagReduction::get()
	{
		return InternalcGameDataPointer->UseLagReduction;
	}

	void cGameData::UseLagReduction::set(bool value)
	{
		InternalcGameDataPointer->UseLagReduction = value;
	}

	bool cGameData::DoMapsLoop::get()
	{
		return InternalcGameDataPointer->Do_Maps_Loop();
	}

	void cGameData::DoMapsLoop::set(bool value)
	{
		InternalcGameDataPointer->Set_Do_Maps_Loop(value);
	}

	String^ cGameData::GameTitle::get()
	{
		return gcnew String(InternalcGameDataPointer->Get_Game_Title().Peek_Buffer());
	}

	void cGameData::GameTitle::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalUni(value);
		try
		{
			InternalcGameDataPointer->Set_Game_Title(
				reinterpret_cast<wchar_t*>(valueHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	String^ cGameData::Password::get()
	{
		auto result = InternalcGameDataPointer->Get_Password();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	void cGameData::Password::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalUni(value);
		try
		{
			InternalcGameDataPointer->Set_Password(
				reinterpret_cast<wchar_t*>(valueHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	array<String^>^ cGameData::MapList::get()
	{
		array<String^>^ result = gcnew array<String^>(sizeof(InternalcGameDataPointer->MapList) / sizeof(InternalcGameDataPointer->MapList[0]));

		for (int x = 0; x < result->Length; x++)
		{
			result[x] = gcnew String(InternalcGameDataPointer->MapList[x]);
		}

		return result;
	}

	String^ cGameData::Owner::get()
	{
		return gcnew String(InternalcGameDataPointer->Get_Owner().Peek_Buffer());
	}

	void cGameData::Owner::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalUni(value);
		try
		{
			InternalcGameDataPointer->Owner = reinterpret_cast<wchar_t*>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	IDynamicVectorClass<String^>^ cGameData::BottomText::get()
	{
		return gcnew WideStringClassDynamicVectorClass(IntPtr(&InternalcGameDataPointer->BottomText));
	}

	void cGameData::BottomText::set(IDynamicVectorClass<String^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalcGameDataPointer->BottomText =
			*reinterpret_cast<::DynamicVectorClass<::WideStringClass>*>(value->Pointer.ToPointer());
	}

	IDynamicVectorClass<String^>^ cGameData::SettingsLimits::get()
	{
		return gcnew WideStringClassDynamicVectorClass(IntPtr(&InternalcGameDataPointer->SettingsLimits));
	}

	void cGameData::SettingsLimits::set(IDynamicVectorClass<String^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalcGameDataPointer->SettingsLimits =
			*reinterpret_cast<::DynamicVectorClass<::WideStringClass>*>(value->Pointer.ToPointer());
	}

	bool cGameData::ExeVersionsMatch::get()
	{
		return InternalcGameDataPointer->ExeVersionsMatch;
	}

	void cGameData::ExeVersionsMatch::set(bool value)
	{
		InternalcGameDataPointer->ExeVersionsMatch = value;
	}

	bool cGameData::StringVersionsMatch::get()
	{
		return InternalcGameDataPointer->StringVersionsMatch;
	}

	void cGameData::StringVersionsMatch::set(bool value)
	{
		InternalcGameDataPointer->StringVersionsMatch = value;
	}

	unsigned short cGameData::Port::get()
	{
		return InternalcGameDataPointer->Port;
	}

	void cGameData::Port::set(unsigned short value)
	{
		InternalcGameDataPointer->Port = value;
	}

	unsigned int cGameData::CFGModTime::get()
	{
		return InternalcGameDataPointer->CFGModTime;
	}

	void cGameData::CFGModTime::set(unsigned int value)
	{
		InternalcGameDataPointer->CFGModTime = value;
	}

	float cGameData::MaxWorldDistance::get()
	{
		return InternalcGameDataPointer->MaxWorldDistance;
	}

	void cGameData::MaxWorldDistance::set(float value)
	{
		InternalcGameDataPointer->MaxWorldDistance = value;
	}

	IcGameData::WinTypeEnum cGameData::WinType::get()
	{
		return static_cast<IcGameData::WinTypeEnum>(InternalcGameDataPointer->Get_Win_Type());
	}

	void cGameData::WinType::set(IcGameData::WinTypeEnum value)
	{
		InternalcGameDataPointer->Set_Win_Type(
			static_cast<::cGameData::WinTypeEnum>(value));
	}

	DateTime cGameData::GameStartTime2::get()
	{
		auto& tmp = InternalcGameDataPointer->GameStartTime2;

		return DateTime(tmp.wYear, tmp.wMonth, tmp.wDay, tmp.wHour, tmp.wMinute, tmp.wSecond, tmp.wMilliseconds);
	}

	void cGameData::GameStartTime2::set(DateTime value)
	{
		if (value.Year < 1601 || value.Year > 30827)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto& tmp = InternalcGameDataPointer->GameStartTime2;
		tmp.wYear = value.Year;
		tmp.wMonth = value.Month;
		tmp.wDay = value.Day;
		tmp.wDayOfWeek = static_cast<WORD>(value.DayOfWeek);
		tmp.wHour = value.Hour;
		tmp.wMinute = value.Minute;
		tmp.wSecond = value.Second;
		tmp.wMilliseconds = value.Millisecond;
	}

	unsigned int cGameData::GameStartTime::get()
	{
		return InternalcGameDataPointer->GameStartTime;
	}

	void cGameData::GameStartTime::set(unsigned int value)
	{
		InternalcGameDataPointer->GameStartTime = value;
	}

	bool cGameData::IsQuickMatch::get()
	{
		return InternalcGameDataPointer->Is_QuickMatch_Server();
	}

	void cGameData::IsQuickMatch::set(bool value)
	{
		InternalcGameDataPointer->Set_QuickMatch_Server(value);
	}

	array<unsigned long>^ cGameData::Clans::get()
	{
		array<unsigned long>^ result = gcnew array<unsigned long>(sizeof(InternalcGameDataPointer->Clans) / sizeof(InternalcGameDataPointer->Clans[0]));
		
		for (int x = 0; x < result->Length; x++)
		{
			result[x] = InternalcGameDataPointer->Clans[x];
		}

		return result;
	}

	void cGameData::Clans::set(array<unsigned long>^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}
		else if (value->Length != (sizeof(InternalcGameDataPointer->Clans) / sizeof(InternalcGameDataPointer->Clans[0])))
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		pin_ptr<unsigned long> pinnedClans = &value[0];
		unsigned long* clansPtr = pinnedClans;

		std::memcpy(InternalcGameDataPointer->Clans, clansPtr, sizeof(InternalcGameDataPointer->Clans));
	}

	::Signaler<::cGameDataEvent>* cGameData::InternalcGameDataEventSignalerPointer::get()
	{
		return InternalcGameDataPointer;
	}

	::cGameData* cGameData::InternalcGameDataPointer::get()
	{
		return reinterpret_cast<::cGameData*>(Pointer.ToPointer());
	}

	cGameDataCnC::cGameDataCnC(IntPtr pointer)
		: cGameData(pointer)
	{

	}

	IcGameDataCnC^ cGameDataCnC::AsCnC()
	{
		return this;
	}

	IntPtr cGameDataCnC::cGameDataCnCPointer::get()
	{
		return IntPtr(InternalcGameDataCnCPointer);
	}

	bool cGameDataCnC::BaseDestructionEndsGame::get()
	{
		return InternalcGameDataCnCPointer->Base_Destruction_Ends_Game();
	}

	void cGameDataCnC::BaseDestructionEndsGame::set(bool value)
	{
		InternalcGameDataCnCPointer->Set_Base_Destruction_Ends_Game(value);
	}

	bool cGameDataCnC::BeaconPlacementEndsGame::get()
	{
		return InternalcGameDataCnCPointer->Beacon_Placement_Ends_Game();
	}

	void cGameDataCnC::BeaconPlacementEndsGame::set(bool value)
	{
		InternalcGameDataCnCPointer->Set_Beacon_Placement_Ends_Game(value);
	}

	int cGameDataCnC::StartingCredits::get()
	{
		return InternalcGameDataCnCPointer->Get_Starting_Credits();
	}

	void cGameDataCnC::StartingCredits::set(int value)
	{
		InternalcGameDataCnCPointer->Set_Starting_Credits(value);
	}

	IBaseControllerClass^ cGameDataCnC::GDI::get()
	{
		return gcnew BaseControllerClass(IntPtr(&InternalcGameDataCnCPointer->GDI));
	}

	void cGameDataCnC::GDI::set(IBaseControllerClass^ value)
	{
		if (value == nullptr || value->BaseControllerClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalcGameDataCnCPointer->GDI = *reinterpret_cast<::BaseControllerClass*>(value->BaseControllerClassPointer.ToPointer());
	}

	IBaseControllerClass^ cGameDataCnC::Nod::get()
	{
		return gcnew BaseControllerClass(IntPtr(&InternalcGameDataCnCPointer->Nod));
	}

	void cGameDataCnC::Nod::set(IBaseControllerClass^ value)
	{
		if (value == nullptr || value->BaseControllerClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalcGameDataCnCPointer->Nod = *reinterpret_cast<::BaseControllerClass*>(value->BaseControllerClassPointer.ToPointer());
	}

	bool cGameDataCnC::BasesInitalized::get()
	{
		return InternalcGameDataCnCPointer->BasesInitalized;
	}

	void cGameDataCnC::BasesInitalized::set(bool value)
	{
		InternalcGameDataCnCPointer->BasesInitalized = value;
	}

	::cGameData* cGameDataCnC::InternalcGameDataPointer::get()
	{
		return InternalcGameDataCnCPointer;
	}

	::cGameDataCnc* cGameDataCnC::InternalcGameDataCnCPointer::get()
	{
		return reinterpret_cast<::cGameDataCnc*>(Pointer.ToPointer());
	}

	cGameDataSkirmish::cGameDataSkirmish(IntPtr pointer)
		: cGameData(pointer)
	{

	}

	IcGameDataSkirmish^ cGameDataSkirmish::AsSkirmish()
	{
		return this;
	}

	IntPtr cGameDataSkirmish::cGameDataSkirmishPointer::get()
	{
		return IntPtr(InternalcGameDataSkirmishPointer);
	}

	bool cGameDataSkirmish::BaseDestructionEndsGame::get()
	{
		return InternalcGameDataSkirmishPointer->Base_Destruction_Ends_Game();
	}

	void cGameDataSkirmish::BaseDestructionEndsGame::set(bool value)
	{
		InternalcGameDataSkirmishPointer->Set_Base_Destruction_Ends_Game(value);
	}

	bool cGameDataSkirmish::BeaconPlacementEndsGame::get()
	{
		return InternalcGameDataSkirmishPointer->Beacon_Placement_Ends_Game();
	}

	void cGameDataSkirmish::BeaconPlacementEndsGame::set(bool value)
	{
		InternalcGameDataSkirmishPointer->Set_Beacon_Placement_Ends_Game(value);
	}

	int cGameDataSkirmish::StartingCredits::get()
	{
		return InternalcGameDataSkirmishPointer->Get_Starting_Credits();
	}

	void cGameDataSkirmish::StartingCredits::set(int value)
	{
		InternalcGameDataSkirmishPointer->Set_Starting_Credits(value);
	}

	IBaseControllerClass^ cGameDataSkirmish::GDI::get()
	{
		return gcnew BaseControllerClass(IntPtr(&InternalcGameDataSkirmishPointer->GDI));
	}

	void cGameDataSkirmish::GDI::set(IBaseControllerClass^ value)
	{
		if (value == nullptr || value->BaseControllerClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalcGameDataSkirmishPointer->GDI = *reinterpret_cast<::BaseControllerClass*>(value->BaseControllerClassPointer.ToPointer());
	}

	IBaseControllerClass^ cGameDataSkirmish::Nod::get()
	{
		return gcnew BaseControllerClass(IntPtr(&InternalcGameDataSkirmishPointer->Nod));
	}

	void cGameDataSkirmish::Nod::set(IBaseControllerClass^ value)
	{
		if (value == nullptr || value->BaseControllerClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalcGameDataSkirmishPointer->Nod = *reinterpret_cast<::BaseControllerClass*>(value->BaseControllerClassPointer.ToPointer());
	}

	bool cGameDataSkirmish::BasesInitalized::get()
	{
		return InternalcGameDataSkirmishPointer->BasesInitalized;
	}

	void cGameDataSkirmish::BasesInitalized::set(bool value)
	{
		InternalcGameDataSkirmishPointer->BasesInitalized = value;
	}

	::cGameData* cGameDataSkirmish::InternalcGameDataPointer::get()
	{
		return InternalcGameDataSkirmishPointer;
	}

	::cGameDataSkirmish* cGameDataSkirmish::InternalcGameDataSkirmishPointer::get()
	{
		return reinterpret_cast<::cGameDataSkirmish*>(Pointer.ToPointer());
	}

	cGameDataSinglePlayer::cGameDataSinglePlayer(IntPtr pointer)
		: cGameData(pointer)
	{

	}

	IcGameDataSinglePlayer^ cGameDataSinglePlayer::AsSinglePlayer()
	{
		return this;
	}

	IntPtr cGameDataSinglePlayer::cGameDataSinglePlayerPointer::get()
	{
		return IntPtr(InternalcGameDataSinglePlayerPointer);
	}

	::cGameData* cGameDataSinglePlayer::InternalcGameDataPointer::get()
	{
		return InternalcGameDataSinglePlayerPointer;
	}

	::cGameDataSinglePlayer* cGameDataSinglePlayer::InternalcGameDataSinglePlayerPointer::get()
	{
		return reinterpret_cast<::cGameDataSinglePlayer*>(Pointer.ToPointer());
	}
}