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
#include "McPlayer.h"

#include "Mda_player.h"
#include "MSoldierGameObj.h"

namespace RenSharp
{
	cPlayer::cPlayer(IntPtr pointer)
		: NetworkObjectClass(pointer)
	{
		playerDataClass = gcnew PlayerDataClass(IntPtr(InternalPlayerDataClassPointer));
	}

	String ^cPlayer::ToString()
	{
		return PlayerName;
	}

	bool cPlayer::Equals(Object ^other)
	{
		if (NetworkObjectClass::Equals(other))
		{
			return true;
		}

		if (ReferenceEquals(other, nullptr))
		{
			return false;
		}

		auto otherUnmanagedObj = dynamic_cast<IUnmanagedObject ^>(other);
		if (otherUnmanagedObj == nullptr || otherUnmanagedObj->Pointer.Equals(IntPtr::Zero))
		{
			return false;
		}

		auto otherPlayerDataClass = dynamic_cast<IPlayerDataClass ^>(other);
		if (otherPlayerDataClass != nullptr)
		{
			if (playerDataClass->Equals(otherPlayerDataClass))
			{
				return true;
			}
		}

		auto othercPlayer = dynamic_cast<IcPlayer ^>(other);
		if (othercPlayer != nullptr)
		{
			if (cPlayerPointer.Equals(othercPlayer->cPlayerPointer))
			{
				return true;
			}
		}

		return false;
	}

	void cPlayer::StatsAddGameTime(float time)
	{
		playerDataClass->StatsAddGameTime(time);
	}

	void cPlayer::IncrementScore(float score)
	{
		InternalcPlayerPointer->Increment_Score(score);
	}

	void cPlayer::SetPlayerType(int type)
	{
		InternalcPlayerPointer->Set_Player_Type(type);
	}

	void cPlayer::IncrementKills()
	{
		InternalcPlayerPointer->Increment_Kills();
	}

	void cPlayer::IncrementDeaths()
	{
		InternalcPlayerPointer->Increment_Deaths();
	}

	void cPlayer::DecrementKills()
	{
		InternalcPlayerPointer->Decrement_Kills();
	}

	void cPlayer::DecrementDeaths()
	{
		InternalcPlayerPointer->Decrement_Deaths();
	}

	void cPlayer::SetKills(int kills)
	{
		InternalcPlayerPointer->Set_Kills(kills);
	}

	void cPlayer::SetDeaths(int deaths)
	{
		InternalcPlayerPointer->Set_Deaths(deaths);
	}

	void cPlayer::MarkAsModified()
	{
		InternalcPlayerPointer->Mark_As_Modified();
	}

	bool cPlayer::DestroyGameObj()
	{
		return InternalcPlayerPointer->Destroy_GameObj();
	}

	void cPlayer::IncrementFloodCounter()
	{
		InternalcPlayerPointer->Increment_Flood_Counter();
	}

	void cPlayer::DecrementFloodCounter()
	{
		InternalcPlayerPointer->Decrement_Flood_Counter();
	}

	IntPtr cPlayer::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void cPlayer::Pointer::set(IntPtr value)
	{
		AbstractUnmanagedObject::Pointer::set(value);

		if (Pointer == IntPtr::Zero)
		{
			playerDataClass = nullptr;
		}
		else
		{
			playerDataClass = gcnew PlayerDataClass(IntPtr(InternalPlayerDataClassPointer));
		}
	}

	IntPtr cPlayer::PlayerDataClassPointer::get()
	{
		return IntPtr(InternalPlayerDataClassPointer);
	}

	IntPtr cPlayer::cPlayerPointer::get()
	{
		return IntPtr(InternalcPlayerPointer);
	}

	float cPlayer::Score::get()
	{
		return playerDataClass->Score;
	}

	void cPlayer::Score::set(float value)
	{
		playerDataClass->Score = value;
	}

	float cPlayer::Money::get()
	{
		return playerDataClass->Money;
	}

	void cPlayer::Money::set(float value)
	{
		playerDataClass->Money = value;
	}

	IReferencerClass ^cPlayer::Owner::get()
	{
		return playerDataClass->Owner;
	}

	void cPlayer::Owner::set(IReferencerClass ^value)
	{
		playerDataClass->Owner = value;
	}

	float cPlayer::PunishTimer::get()
	{
		return playerDataClass->PunishTimer;
	}

	void cPlayer::PunishTimer::set(float value)
	{
		playerDataClass->PunishTimer = value;
	}

	float cPlayer::GameTime::get()
	{
		return playerDataClass->GameTime;
	}

	void cPlayer::GameTime::set(float value)
	{
		playerDataClass->GameTime = value;
	}

	float cPlayer::SessionTime::get()
	{
		return playerDataClass->SessionTime;
	}

	void cPlayer::SessionTime::set(float value)
	{
		playerDataClass->SessionTime = value;
	}

	int cPlayer::EnemiesKilled::get()
	{
		return playerDataClass->EnemiesKilled;
	}

	void cPlayer::EnemiesKilled::set(int value)
	{
		playerDataClass->EnemiesKilled = value;
	}

	int cPlayer::AlliesKilled::get()
	{
		return playerDataClass->AlliesKilled;
	}

	void cPlayer::AlliesKilled::set(int value)
	{
		playerDataClass->AlliesKilled = value;
	}

	int cPlayer::ShotsFired::get()
	{
		return playerDataClass->ShotsFired;
	}

	void cPlayer::ShotsFired::set(int value)
	{
		playerDataClass->ShotsFired = value;
	}

	int cPlayer::HeadShots::get()
	{
		return playerDataClass->HeadShots;
	}

	void cPlayer::HeadShots::set(int value)
	{
		playerDataClass->HeadShots = value;
	}

	int cPlayer::TorsoShots::get()
	{
		return playerDataClass->TorsoShots;
	}

	void cPlayer::TorsoShots::set(int value)
	{
		playerDataClass->TorsoShots = value;
	}

	int cPlayer::ArmShots::get()
	{
		return playerDataClass->ArmShots;
	}

	void cPlayer::ArmShots::set(int value)
	{
		playerDataClass->ArmShots = value;
	}

	int cPlayer::LegShots::get()
	{
		return playerDataClass->LegShots;
	}

	void cPlayer::LegShots::set(int value)
	{
		playerDataClass->LegShots = value;
	}

	int cPlayer::CrotchShots::get()
	{
		return playerDataClass->CrotchShots;
	}

	void cPlayer::CrotchShots::set(int value)
	{
		playerDataClass->CrotchShots = value;
	}

	float cPlayer::FinalHealth::get()
	{
		return playerDataClass->FinalHealth;
	}

	void cPlayer::FinalHealth::set(float value)
	{
		playerDataClass->FinalHealth = value;
	}

	int cPlayer::PowerupsCollected::get()
	{
		return playerDataClass->PowerupsCollected;
	}

	void cPlayer::PowerupsCollected::set(int value)
	{
		playerDataClass->PowerupsCollected = value;
	}

	int cPlayer::VehiclesDestroyed::get()
	{
		return playerDataClass->VehiclesDestroyed;
	}

	void cPlayer::VehiclesDestroyed::set(int value)
	{
		playerDataClass->VehiclesDestroyed = value;
	}

	float cPlayer::VehicleTime::get()
	{
		return playerDataClass->VehicleTime;
	}

	void cPlayer::VehicleTime::set(float value)
	{
		playerDataClass->VehicleTime = value;
	}

	int cPlayer::KillsFromVehicle::get()
	{
		return playerDataClass->KillsFromVehicle;
	}

	void cPlayer::KillsFromVehicle::set(int value)
	{
		playerDataClass->KillsFromVehicle = value;
	}

	int cPlayer::Squishes::get()
	{
		return playerDataClass->Squishes;
	}

	void cPlayer::Squishes::set(int value)
	{
		playerDataClass->Squishes = value;
	}

	float cPlayer::CreditGrant::get()
	{
		return playerDataClass->CreditGrant;
	}

	void cPlayer::CreditGrant::set(float value)
	{
		playerDataClass->CreditGrant = value;
	}

	int cPlayer::BuildingDestroyed::get()
	{
		return playerDataClass->BuildingDestroyed;
	}

	void cPlayer::BuildingDestroyed::set(int value)
	{
		playerDataClass->BuildingDestroyed = value;
	}

	int cPlayer::HeadHit::get()
	{
		return playerDataClass->HeadHit;
	}

	void cPlayer::HeadHit::set(int value)
	{
		playerDataClass->HeadHit = value;
	}

	int cPlayer::TorsoHit::get()
	{
		return playerDataClass->TorsoHit;
	}

	void cPlayer::TorsoHit::set(int value)
	{
		playerDataClass->TorsoHit = value;
	}

	int cPlayer::ArmHit::get()
	{
		return playerDataClass->ArmHit;
	}

	void cPlayer::ArmHit::set(int value)
	{
		playerDataClass->ArmHit = value;
	}

	int cPlayer::LegHit::get()
	{
		return playerDataClass->LegHit;
	}

	void cPlayer::LegHit::set(int value)
	{
		playerDataClass->LegHit = value;
	}

	int cPlayer::CrotchHit::get()
	{
		return playerDataClass->CrotchHit;
	}

	void cPlayer::CrotchHit::set(int value)
	{
		playerDataClass->CrotchHit = value;
	}

	int cPlayer::WeaponFired::get()
	{
		return playerDataClass->WeaponFired;
	}

	void cPlayer::WeaponFired::set(int value)
	{
		playerDataClass->WeaponFired = value;
	}

	ISimpleDynVecClass<int> ^cPlayer::WeaponsFiredID::get()
	{
		return playerDataClass->WeaponsFiredID;
	}

	void cPlayer::WeaponsFiredID::set(ISimpleDynVecClass<int> ^value)
	{
		playerDataClass->WeaponsFiredID = value;
	}

	ISimpleDynVecClass<int> ^cPlayer::WeaponsFiredCount::get()
	{
		return playerDataClass->WeaponsFiredCount;
	}

	void cPlayer::WeaponsFiredCount::set(ISimpleDynVecClass<int> ^value)
	{
		playerDataClass->WeaponsFiredCount = value;
	}

	ISmartGameObj ^cPlayer::SmartGameObj::get()
	{
		return playerDataClass->GameObj;
	}

	void cPlayer::SmartGameObj::set(ISmartGameObj ^value)
	{
		playerDataClass->GameObj = value;
	}

	bool cPlayer::Invulnerable::get()
	{
		return InternalcPlayerPointer->Invulnerable;
	}

	void cPlayer::Invulnerable::set(bool value)
	{
		InternalcPlayerPointer->Invulnerable = value;
	}

	String ^cPlayer::PlayerName::get()
	{
		return gcnew String(InternalcPlayerPointer->PlayerName.Peek_Buffer());
	}

	void cPlayer::PlayerName::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalUni(value);
		try
		{
			InternalcPlayerPointer->PlayerName = reinterpret_cast<wchar_t *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	int cPlayer::PlayerId::get()
	{
		return InternalcPlayerPointer->PlayerId;
	}

	void cPlayer::PlayerId::set(int value)
	{
		InternalcPlayerPointer->PlayerId = value;
	}

	int cPlayer::LadderPoints::get()
	{
		return InternalcPlayerPointer->LadderPoints;
	}

	void cPlayer::LadderPoints::set(int value)
	{
		InternalcPlayerPointer->LadderPoints = value;
	}

	int cPlayer::Kills::get()
	{
		return InternalcPlayerPointer->Kills;
	}

	void cPlayer::Kills::set(int value)
	{
		InternalcPlayerPointer->Kills = value;
	}

	int cPlayer::Deaths::get()
	{
		return InternalcPlayerPointer->Deaths;
	}

	void cPlayer::Deaths::set(int value)
	{
		InternalcPlayerPointer->Deaths = value;
	}

	int cPlayer::PlayerType::get()
	{
		return InternalcPlayerPointer->PlayerType;
	}

	void cPlayer::PlayerType::set(int value)
	{
		InternalcPlayerPointer->PlayerType = value;
	}

	int cPlayer::Rung::get()
	{
		return InternalcPlayerPointer->Rung;
	}

	void cPlayer::Rung::set(int value)
	{
		InternalcPlayerPointer->Rung = value;
	}

	int cPlayer::WolRank::get()
	{
		return InternalcPlayerPointer->WolRank;
	}

	void cPlayer::WolRank::set(int value)
	{
		InternalcPlayerPointer->WolRank = value;
	}

	short cPlayer::WolPoints::get()
	{
		return InternalcPlayerPointer->WolPoints;
	}

	void cPlayer::WolPoints::set(short value)
	{
		InternalcPlayerPointer->WolPoints = value;
	}

	int cPlayer::DamageScaleFactor::get()
	{
		return InternalcPlayerPointer->DamageScaleFactor;
	}

	void cPlayer::DamageScaleFactor::set(int value)
	{
		InternalcPlayerPointer->DamageScaleFactor = value;
	}

	int cPlayer::Ping::get()
	{
		return InternalcPlayerPointer->Ping;
	}

	void cPlayer::Ping::set(int value)
	{
		InternalcPlayerPointer->Ping = value;
	}

	int cPlayer::JoinTime::get()
	{
		return InternalcPlayerPointer->JoinTime;
	}

	void cPlayer::JoinTime::set(int value)
	{
		InternalcPlayerPointer->JoinTime = value;
	}

	int cPlayer::TotalTime::get()
	{
		return InternalcPlayerPointer->TotalTime;
	}

	void cPlayer::TotalTime::set(int value)
	{
		InternalcPlayerPointer->TotalTime = value;
	}

	IPAddress ^cPlayer::IpAddress::get()
	{
		auto ipAddress = InternalcPlayerPointer->IpAddress;

		return gcnew IPAddress(gcnew array<std::uint8_t>
		{ 
			static_cast<std::uint8_t>((ipAddress & 0x000000FF) >> 0),
			static_cast<std::uint8_t>((ipAddress & 0x0000FF00) >> 8),
			static_cast<std::uint8_t>((ipAddress & 0x00FF0000) >> 16),
			static_cast<std::uint8_t>((ipAddress & 0xFF000000) >> 24)
		});
	}

	void cPlayer::IpAddress::set(IPAddress ^value)
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

		unsigned long ipAddress = 0;

		ipAddress |= (static_cast<int>(bytes[0]) << 0);
		ipAddress |= (static_cast<int>(bytes[1]) << 8);
		ipAddress |= (static_cast<int>(bytes[2]) << 16);
		ipAddress |= (static_cast<int>(bytes[3]) << 24);

		InternalcPlayerPointer->IpAddress = ipAddress;
	}

	int cPlayer::Fps::get()
	{
		return InternalcPlayerPointer->Fps;
	}

	void cPlayer::Fps::set(int value)
	{
		InternalcPlayerPointer->Fps = value;
	}

	unsigned long cPlayer::LastUpdateTimeMs::get()
	{
		return InternalcPlayerPointer->LastUpdateTimeMs;
	}

	void cPlayer::LastUpdateTimeMs::set(unsigned long value)
	{
		InternalcPlayerPointer->LastUpdateTimeMs = value;
	}

	int cPlayer::FastSortKey::get()
	{
		return InternalcPlayerPointer->FastSortKey;
	}

	void cPlayer::FastSortKey::set(int value)
	{
		InternalcPlayerPointer->FastSortKey = value;
	}

	int cPlayer::NumWolGames::get()
	{
		return InternalcPlayerPointer->NumWolGames;
	}

	void cPlayer::NumWolGames::set(int value)
	{
		InternalcPlayerPointer->NumWolGames = value;
	}

	bool cPlayer::IsWaitingForIntermission::get()
	{
		return InternalcPlayerPointer->IsWaitingForIntermission;
	}

	void cPlayer::IsWaitingForIntermission::set(bool value)
	{
		InternalcPlayerPointer->IsWaitingForIntermission = value;
	}

	RenSharp::GameSpyAuthState cPlayer::GameSpyAuthState::get()
	{
		return static_cast<RenSharp::GameSpyAuthState>(InternalcPlayerPointer->GameSpyAuthState);
	}

	void cPlayer::GameSpyAuthState::set(RenSharp::GameSpyAuthState value)
	{
		InternalcPlayerPointer->GameSpyAuthState = static_cast<::GAMESPY_AUTH_STATE_ENUM>(value);
	}

	unsigned long cPlayer::GameSpyAuthStateEntryTimeMs::get()
	{
		return InternalcPlayerPointer->GameSpyAuthStateEntryTimeMs;
	}

	void cPlayer::GameSpyAuthStateEntryTimeMs::set(unsigned long value)
	{
		InternalcPlayerPointer->GameSpyAuthStateEntryTimeMs = value;
	}

	String ^cPlayer::GameSpyChallengeString::get()
	{
		return gcnew String(InternalcPlayerPointer->GameSpyChallengeString.Peek_Buffer());
	}

	void cPlayer::GameSpyChallengeString::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalcPlayerPointer->GameSpyChallengeString = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	String ^cPlayer::GameSpyHashId::get()
	{
		return gcnew String(InternalcPlayerPointer->GameSpyHashId.Peek_Buffer());
	}

	void cPlayer::GameSpyHashId::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalcPlayerPointer->GameSpyHashId = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	int cPlayer::GameSpyKickState::get()
	{
		return InternalcPlayerPointer->GameSpyKickState;
	}

	void cPlayer::GameSpyKickState::set(int value)
	{
		InternalcPlayerPointer->GameSpyKickState = value;
	}

	unsigned long cPlayer::GameSpyKickStateEntryTimeMs::get()
	{
		return InternalcPlayerPointer->GameSpyKickStateEntryTimeMs;
	}

	void cPlayer::GameSpyKickStateEntryTimeMs::set(unsigned long value)
	{
		InternalcPlayerPointer->GameSpyKickStateEntryTimeMs = value;
	}

	bool cPlayer::IsInGame::get()
	{
		return InternalcPlayerPointer->IsInGame;
	}

	void cPlayer::IsInGame::set(bool value)
	{
		InternalcPlayerPointer->IsInGame = value;
	}

	bool cPlayer::IsActive::get()
	{
		return InternalcPlayerPointer->IsActive;
	}

	void cPlayer::IsActive::set(bool value)
	{
		InternalcPlayerPointer->IsActive = value;
	}

	bool cPlayer::IsHuman::get()
	{
		return InternalcPlayerPointer->Is_Human();
	}

	bool cPlayer::IsAliveAndKicking::get()
	{
		return InternalcPlayerPointer->Is_Alive_And_Kicking();
	}

	float cPlayer::KillToDeathRatio::get()
	{
		return InternalcPlayerPointer->Get_Kill_To_Death_Ratio();
	}

	IDAPlayerClass ^cPlayer::DAPlayer::get()
	{
		auto result = InternalcPlayerPointer->DAPlayer;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAPlayerClass(IntPtr(result));
		}
	}

	void cPlayer::DAPlayer::set(IDAPlayerClass ^value)
	{
		if (value == nullptr || value->DAPlayerClassPointer.ToPointer() == nullptr)
		{
			InternalcPlayerPointer->DAPlayer = nullptr;
		}
		else
		{
			InternalcPlayerPointer->DAPlayer = reinterpret_cast<::DAPlayerClass *>(value->DAPlayerClassPointer.ToPointer());
		}
	}

	ISoldierGameObj ^cPlayer::GameObj::get()
	{
		auto result = InternalcPlayerPointer->Get_GameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SoldierGameObj(IntPtr(result));
		}
	}

	String ^cPlayer::CustomTag::get()
	{
		return gcnew String(InternalcPlayerPointer->customTag.Peek_Buffer());
	}

	void cPlayer::CustomTag::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalUni(value);
		try
		{
			InternalcPlayerPointer->customTag = reinterpret_cast<wchar_t *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	bool cPlayer::IsFlooding::get()
	{
		return InternalcPlayerPointer->Is_Flooding();
	}

	::PlayerDataClass *cPlayer::InternalPlayerDataClassPointer::get()
	{
		return InternalcPlayerPointer;
	}

	::NetworkObjectClass *cPlayer::InternalNetworkObjectClassPointer::get()
	{
		return InternalcPlayerPointer;
	}

	::cPlayer *cPlayer::InternalcPlayerPointer::get()
	{
		return reinterpret_cast<::cPlayer *>(Pointer.ToPointer());
	}
}