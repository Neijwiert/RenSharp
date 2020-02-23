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

#pragma once

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <cPlayer.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MPlayerDataClass.h"
#include "MNetworkObjectClass.h"

using namespace System;
using namespace System::Net;

namespace RenSharp
{
	interface class IDAPlayerClass;
	interface class ISoldierGameObj;

	public enum class GameSpyAuthState : int
	{
		GameSpyAuthStateInitial = ::GAMESPY_AUTH_STATE_INITIAL,
		GameSpyAuthStateChallenged = ::GAMESPY_AUTH_STATE_CHALLENGED,
		GameSpyAuthStateValidating = ::GAMESPY_AUTH_STATE_VALIDATING,
		GameSpyAuthStateAccepted = ::GAMESPY_AUTH_STATE_ACCEPTED,
		GameSpyAuthStateRejecting = ::GAMESPY_AUTH_STATE_REJECTING,
		GameSpyAuthStateRejected = ::GAMESPY_AUTH_STATE_REJECTED
	};

	public interface class IcPlayer : public IPlayerDataClass, public INetworkObjectClass
	{
		void IncrementScore(float score);

		void SetPlayerType(int type);

		void IncrementKills();

		void IncrementDeaths();

		void DecrementKills();

		void DecrementDeaths();

		void SetKills(int kills);

		void SetDeaths(int deaths);

		void MarkAsModified();

		bool DestroyGameObj();

		void IncrementFloodCounter();

		void DecrementFloodCounter();

		property IntPtr cPlayerPointer
		{
			IntPtr get();
		}

		property bool Invulnerable
		{
			bool get();
			void set(bool value);
		}

		property String ^PlayerName
		{
			String ^get();
			void set(String ^value);
		}

		property int PlayerId
		{
			int get();
			void set(int value);
		}

		property int LadderPoints
		{
			int get();
			void set(int value);
		}

		property int Kills
		{
			int get();
			void set(int value);
		}

		property int Deaths
		{
			int get();
			void set(int value);
		}

		property int PlayerType
		{
			int get();
			void set(int value);
		}

		property int Rung
		{
			int get();
			void set(int value);
		}

		property int WolRank
		{
			int get();
			void set(int value);
		}

		property short WolPoints
		{
			short get();
			void set(short value);
		}

		property int DamageScaleFactor
		{
			int get();
			void set(int value);
		}

		property int Ping
		{
			int get();
			void set(int value);
		}

		property int JoinTime
		{
			int get();
			void set(int value);
		}

		property int TotalTime
		{
			int get();
			void set(int value);
		}

		property IPAddress ^IpAddress
		{
			IPAddress ^get();
			void set(IPAddress ^value);
		}

		property int Fps
		{
			int get();
			void set(int value);
		}

		property unsigned long LastUpdateTimeMs
		{
			unsigned long get();
			void set(unsigned long value);
		}

		property int FastSortKey
		{
			int get();
			void set(int value);
		}

		property int NumWolGames
		{
			int get();
			void set(int value);
		}

		property bool IsWaitingForIntermission
		{
			bool get();
			void set(bool value);
		}

		property GameSpyAuthState GameSpyAuthState
		{
			RenSharp::GameSpyAuthState get();
			void set(RenSharp::GameSpyAuthState value);
		}

		property unsigned long GameSpyAuthStateEntryTimeMs
		{
			unsigned long get();
			void set(unsigned long value);
		}

		property String ^GameSpyChallengeString
		{
			String ^get();
			void set(String ^value);
		}

		property String ^GameSpyHashId
		{
			String ^get();
			void set(String ^value);
		}

		property int GameSpyKickState
		{
			int get();
			void set(int value);
		}

		property unsigned long GameSpyKickStateEntryTimeMs
		{
			unsigned long get();
			void set(unsigned long value);
		}

		property bool IsInGame
		{
			bool get();
			void set(bool value);
		}

		property bool IsActive
		{
			bool get();
			void set(bool value);
		}

		property bool IsHuman
		{
			bool get();
		}

		property bool IsAliveAndKicking
		{
			bool get();
		}

		property float KillToDeathRatio
		{
			float get();
		}

		property IDAPlayerClass ^DAPlayer
		{
			IDAPlayerClass ^get();
			void set(IDAPlayerClass ^value);
		}

		property ISoldierGameObj ^GameObj
		{
			ISoldierGameObj ^get();
		}

		property String ^CustomTag
		{
			String ^get();
			void set(String ^value);
		}

		property bool IsFlooding
		{
			bool get();
		}
	};

	public ref class cPlayer : public NetworkObjectClass, public IcPlayer
	{
		private:
			IPlayerDataClass ^playerDataClass;

		public:
			cPlayer(IntPtr pointer);

			String ^ToString() override;
			bool Equals(Object ^other) override;

			virtual void StatsAddGameTime(float time) sealed;
			virtual void IncrementScore(float score) sealed;
			virtual void SetPlayerType(int type) sealed;
			virtual void IncrementKills() sealed;
			virtual void IncrementDeaths() sealed;
			virtual void DecrementKills() sealed;
			virtual void DecrementDeaths() sealed;
			virtual void SetKills(int kills) sealed;
			virtual void SetDeaths(int deaths) sealed;
			virtual void MarkAsModified() sealed;
			virtual bool DestroyGameObj() sealed;
			virtual void IncrementFloodCounter() sealed;
			virtual void DecrementFloodCounter() sealed;

			property IntPtr Pointer
			{
				IntPtr get() override;

				protected:
					void set(IntPtr value) override;
			}

			property IntPtr PlayerDataClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr cPlayerPointer
			{
				virtual IntPtr get() sealed;
			}

			property float Score
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float Money
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property IReferencerClass ^Owner
			{
				virtual IReferencerClass ^get() sealed;
				virtual void set(IReferencerClass ^value) sealed;
			}

			property float PunishTimer
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float GameTime
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float SessionTime
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int EnemiesKilled
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int AlliesKilled
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int ShotsFired
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int HeadShots
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int TorsoShots
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int ArmShots
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int LegShots
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int CrotchShots
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property float FinalHealth
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int PowerupsCollected
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int VehiclesDestroyed
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property float VehicleTime
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int KillsFromVehicle
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int Squishes
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property float CreditGrant
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int BuildingDestroyed
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int HeadHit
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int TorsoHit
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int ArmHit
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int LegHit
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int CrotchHit
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int WeaponFired
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property ISimpleDynVecClass<int> ^WeaponsFiredID
			{
				virtual ISimpleDynVecClass<int> ^get() sealed;
				virtual void set(ISimpleDynVecClass<int> ^value) sealed;
			}

			property ISimpleDynVecClass<int> ^WeaponsFiredCount
			{
				virtual ISimpleDynVecClass<int> ^get() sealed;
				virtual void set(ISimpleDynVecClass<int> ^value) sealed;
			}

			property ISmartGameObj ^SmartGameObj
			{
				virtual ISmartGameObj ^get() sealed = IPlayerDataClass::GameObj::get;
				virtual void set(ISmartGameObj ^value) sealed = IPlayerDataClass::GameObj::set;
			}

			property bool Invulnerable
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property String ^PlayerName
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property int PlayerId
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int LadderPoints
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int Kills
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int Deaths
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int PlayerType
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int Rung
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int WolRank
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property short WolPoints
			{
				virtual short get() sealed;
				virtual void set(short value) sealed;
			}

			property int DamageScaleFactor
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int Ping
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int JoinTime
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int TotalTime
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property IPAddress ^IpAddress
			{
				virtual IPAddress ^get() sealed;
				virtual void set(IPAddress ^value) sealed;
			}

			property int Fps
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property unsigned long LastUpdateTimeMs
			{
				virtual unsigned long get() sealed;
				virtual void set(unsigned long value) sealed;
			}

			property int FastSortKey
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int NumWolGames
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property bool IsWaitingForIntermission
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property GameSpyAuthState GameSpyAuthState
			{
				virtual RenSharp::GameSpyAuthState get() sealed;
				virtual void set(RenSharp::GameSpyAuthState value) sealed;
			}

			property unsigned long GameSpyAuthStateEntryTimeMs
			{
				virtual unsigned long get() sealed;
				virtual void set(unsigned long value) sealed;
			}

			property String ^GameSpyChallengeString
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property String ^GameSpyHashId
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property int GameSpyKickState
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property unsigned long GameSpyKickStateEntryTimeMs
			{
				virtual unsigned long get() sealed;
				virtual void set(unsigned long value) sealed;
			}

			property bool IsInGame
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsActive
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsHuman
			{
				virtual bool get() sealed;
			}

			property bool IsAliveAndKicking
			{
				virtual bool get() sealed;
			}

			property float KillToDeathRatio
			{
				virtual float get() sealed;
			}

			property IDAPlayerClass ^DAPlayer
			{
				virtual IDAPlayerClass ^get() sealed;
				virtual void set(IDAPlayerClass ^value) sealed;
			}

			property ISoldierGameObj ^GameObj
			{
				virtual ISoldierGameObj ^get() sealed = IcPlayer::GameObj::get;
			}

			property String ^CustomTag
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property bool IsFlooding
			{
				virtual bool get() sealed;
			}
			
		protected:
			property ::PlayerDataClass *InternalPlayerDataClassPointer
			{
				virtual ::PlayerDataClass *get();
			}

			property ::NetworkObjectClass *InternalNetworkObjectClassPointer
			{
				::NetworkObjectClass *get() override;
			}

			property ::cPlayer *InternalcPlayerPointer
			{
				virtual ::cPlayer *get();
			}
	};
}