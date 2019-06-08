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

#pragma once

#include "AbstractUnmanagedObject.h"
#include "IUnmanagedContainer.h"
#include "MBaseControllerClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <GameData.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Runtime::InteropServices;
using namespace System::Net;

namespace RenSharp
{
	interface class IcPlayer;
	interface class ISoldierGameObj;
	interface class IcGameDataSinglePlayer;
	interface class IcGameDataSkirmish;
	interface class IcGameDataCnC;
	interface class IBaseControllerClass;

	generic<typename A, typename B>
	public interface class ITypedEventPair : public IUnmanagedObject
	{
		property A ItemA
		{
			A get();
		}

		property B ItemB
		{
			B get();
		}
	};

	generic<typename A, typename B>
	public ref class TypedEventPair abstract : public AbstractUnmanagedObject, public ITypedEventPair<A, B>
	{
		public:
			TypedEventPair(IntPtr pointer)
				: AbstractUnmanagedObject(pointer)
			{

			}

			property A ItemA
			{
				virtual A get() = 0;

				protected:
					virtual void set(A value) = 0;
			}

			property B ItemB
			{
				virtual B get() = 0;

				protected:
					virtual void set(B value) = 0;
			}
	};

#pragma managed(push, off)

	template<typename A, typename B>
	class TypedEventPairHelper : public ::TypedEventPair<A, B>
	{
		private:
			TypedEventPairHelper(A a, B b)
				: ::TypedEventPair<A, B>(a, b)
			{

			}

		public:
			A& GetmItemA()
			{
				return mItemA;
			}

			B& GetmItemB()
			{
				return mItemB;
			}
	};

#pragma managed(pop)

	generic<typename T>
	public interface class ISignaler : public IUnmanagedObject
	{
		void SendSignal(T signal);

		void ReceiveSignal(T signal);

		void SignalDropped(ISignaler<T>^ signaler);

		void SignalMe(ISignaler<T>^ signaler);

		property ISignaler<T>^ Forward
		{
			ISignaler<T>^ get();
			void set(ISignaler<T>^ value);
		}
	};

	generic<typename T>
	public ref class Signaler abstract : public AbstractUnmanagedObject, public ISignaler<T>
	{
		public:
			Signaler(IntPtr pointer)
				: AbstractUnmanagedObject(pointer)
			{

			}

			virtual void SendSignal(T signal) = 0;
			virtual void ReceiveSignal(T signal) = 0;
			virtual void SignalDropped(ISignaler<T>^ signaler) = 0;
			virtual void SignalMe(ISignaler<T>^ signaler) = 0;

			property ISignaler<T>^ Forward
			{
				virtual ISignaler<T>^ get() = 0;
				virtual void set(ISignaler<T>^ value) = 0;
			}
	};

	public ref class cGameDataEvent : public TypedEventPair<bool, int>
	{
		private:
			cGameDataEvent(bool a, int b);

		public:
			cGameDataEvent(IntPtr pointer);

			static IUnmanagedContainer<ITypedEventPair<bool, int>^>^ CreatecGameDataEvent(bool a, int b);

			property IntPtr cGameDataEventPointer
			{
				IntPtr get();
			}

			property bool ItemA
			{
				bool get() override sealed;

				protected:
					void set(bool value) override sealed;
			}

			property int ItemB
			{
				int get() override sealed;

				protected:
					void set(int value) override sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::cGameDataEvent* InternalcGameDataEventPointer
			{
				virtual ::cGameDataEvent* get();
			}
	};

	public ref class cGameDataEventSignaler : public Signaler<ITypedEventPair<bool, int>^>
	{
		private:
			cGameDataEventSignaler();

		public:
			cGameDataEventSignaler(IntPtr pointer);

			static IUnmanagedContainer<ISignaler<ITypedEventPair<bool, int>^>^>^ CreatecGameDataEventSignaler();

			void SendSignal(ITypedEventPair<bool, int>^ signal) override sealed;
			void ReceiveSignal(ITypedEventPair<bool, int>^ signal) override sealed;
			void SignalDropped(ISignaler<ITypedEventPair<bool, int>^>^ signaler) override sealed;
			void SignalMe(ISignaler<ITypedEventPair<bool, int>^>^ signaler) override sealed;

			property ISignaler<ITypedEventPair<bool, int>^>^ Forward
			{
				ISignaler<ITypedEventPair<bool, int>^>^ get() override sealed;
				void set(ISignaler<ITypedEventPair<bool, int>^>^ value) override sealed;
			}

			property IntPtr cGameDataEventSignalerPointer
			{
				IntPtr get();
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::Signaler<::cGameDataEvent>* InternalcGameDataEventSignalerPointer
			{
				virtual ::Signaler<::cGameDataEvent>* get();
			}
	};

	public interface class IcGameData : public ISignaler<ITypedEventPair<bool, int>^>
	{
		enum class WinTypeEnum
		{
			WinTypeShutdown = ::cGameData::WIN_TYPE_SHUTDOWN,
			WinTypeAbandon = ::cGameData::WIN_TYPE_ABANDON,
			WinTypeTimeout = ::cGameData::WIN_TYPE_TIMEOUT,
			WinTypeBaseDestruction = ::cGameData::WIN_TYPE_BASEDESTRUCTION,
			WinTypeBeacon = ::cGameData::WIN_TYPE_BEACON
		};

		enum class GameTypeEnum
		{
			GameTypeSinglePlayer = ::cGameData::GAME_TYPE_SINGLE_PLAYER,
			GameTypeSkirmish = ::cGameData::GAME_TYPE_SKIRMISH,
			GameTypeCnC = ::cGameData::GAME_TYPE_CNC
		};

		void OnGameBegin();

		void OnGameEnd();

		void Think();

		void Render();

		void ResetGame(bool skipPlayerReset);

		int ChoosePlayerType(IcPlayer^ player, int type, bool skipAutoTeam);

		void LoadFromServerConfig();

		void SaveToServerConfig();

		void SoldierAdded(ISoldierGameObj^ obj);

		void ShowGameSettingsLimits();

		IcGameDataSinglePlayer^ AsSinglePlayer();

		IcGameDataSkirmish^ AsSkirmish();

		IcGameDataCnC^ AsCnC();

		bool IsValidSettings([Out] String^% errorString, bool b);

		void ExportTier1Data(IntPtr packet);

		void ImportTier1Data(IntPtr packet);

		void ImportTier1DataWOLGameInfo(IntPtr packet);

		void ExportTier2Data(IntPtr packet);

		void ImportTier2Data(IntPtr packet);

		void ResetTimeRemainingSeconds();

		void SetTimeLimitMinutes(int time);

		String^ GetMapCycle(int map);

		void SetMapCyle(int map, String^ name);

		bool IsValidPlayerType(int playerType);

		property IntPtr cGameDataPointer
		{
			IntPtr get();
		}

		property String^ GameName
		{
			String^ get();
		}

		property GameTypeEnum GameType
		{
			GameTypeEnum get();
		}

		property bool IsEditableTeaming
		{
			bool get();
		}

		property bool IsEditableClanGame
		{
			bool get();
		}

		property bool IsEditableFriendlyFire
		{
			bool get();
		}

		property bool IsSinglePlayer
		{
			bool get();
		}

		property bool IsSkirmish
		{
			bool get();
		}

		property bool IsCnC
		{
			bool get();
		}

		property unsigned int MinPlayers
		{
			unsigned int get();
		}

		property bool IsGameOver
		{
			bool get();
		}

		property bool IsLimited
		{
			bool get();
		}

		property bool IsGameplayPermitted
		{
			bool get();
		}

		property bool RememberInventory
		{
			bool get();
		}

		property String^ Description
		{
			String^ get();
		}

		property float TimeRemainingSeconds
		{
			float get();
			void set(float value);
		}

		property bool IsMapCycleOver
		{
			bool get();
			void set(bool value);
		}

		property int WinnerID
		{
			int get();
			void set(int value);
		}

		property String^ MOTD
		{
			String^ get();
			void set(String^ value);
		}

		property String^ MapName
		{
			String^ get();
			void set(String^ value);
		}

		property RadarMode RadarMode
		{
			RenSharp::RadarMode get();
			void set(RenSharp::RadarMode value);
		}

		property String^ MVPName
		{
			String^ get();
			void set(String^ value);
		}

		property unsigned int MVPCount
		{
			unsigned int get();
			void set(unsigned int value);
		}

		property unsigned int TimeLimitMinutes
		{
			unsigned int get();
			void set(unsigned int value);
		}

		property int CurrentPlayers
		{
			int get();
			void set(int value);
		}

		property bool IsFriendlyFirePermitted
		{
			bool get();
			void set(bool value);
		}

		property unsigned int GameDurationSeconds
		{
			unsigned int get();
			void set(unsigned int value);
		}

		property String^ ModName
		{
			String^ get();
			void set(String^ value);
		}

		property unsigned int MapNumber
		{
			unsigned int get();
			void set(unsigned int value);
		}

		property bool IsDedicated
		{
			bool get();
			void set(bool value);
		}

		property int MaxPlayers
		{
			int get();
			void set(int value);
		}

		property bool IsLaddered
		{
			bool get();
			void set(bool value);
		}

		property bool IsIntermission
		{
			bool get();
			void set(bool value);
		}

		property bool IsTeamChangingAllowed
		{
			bool get();
			void set(bool value);
		}

		property bool IsRemixTeams
		{
			bool get();
			void set(bool value);
		}

		property bool CanRepairBuildings
		{
			bool get();
			void set(bool value);
		}

		property bool DriverIsAlwaysGunner
		{
			bool get();
			void set(bool value);
		}

		property bool SpawnWeapons
		{
			bool get();
			void set(bool value);
		}

		property String^ INIFilename
		{
			String^ get();
			void set(String^ value);
		}

		property String^ SettingsDescription
		{
			String^ get();
			void set(String^ value);
		}

		property int MinQualifyingTimeMinutes
		{
			int get();
			void set(int value);
		}

		property bool DoesMapExist
		{
			bool get();
		}

		property String^ MapBaseName
		{
			String^ get();
		}

		property IPAddress^ IP
		{
			IPAddress^ get();
			void set(IPAddress^ value);
		}

		property int IntermissionTimeSeconds
		{
			int get();
			void set(int value);
		}

		property bool IsTimeLimt
		{
			bool get();
		}

		property int ExeKey
		{
			int get();
			void set(int value);
		}

		property float IntermissionTimeLeft
		{
			float get();
			void set(float value);
		}

		property int FrameCount
		{
			int get();
			void set(int value);
		}

		property bool IsAutoRestart
		{
			bool get();
			void set(bool value);
		}

		property bool IsPassworded
		{
			bool get();
			void set(bool value);
		}

		property bool GrantWeapons
		{
			bool get();
			void set(bool value);
		}

		property bool IsClanGame
		{
			bool get();
			void set(bool value);
		}

		property bool UseLagReduction
		{
			bool get();
			void set(bool value);
		}

		property bool DoMapsLoop
		{
			bool get();
			void set(bool value);
		}

		property String^ GameTitle
		{
			String^ get();
			void set(String^ value);
		}

		property String^ Password
		{
			String^ get();
			void set(String^ value);
		}

		property array<String^>^ MapList
		{
			array<String^>^ get();
		}

		property String^ Owner
		{
			String^ get();
			void set(String^ value);
		}

		property IDynamicVectorClass<String^>^ BottomText
		{
			IDynamicVectorClass<String^>^ get();
			void set(IDynamicVectorClass<String^>^ value);
		}

		property IDynamicVectorClass<String^>^ SettingsLimits
		{
			IDynamicVectorClass<String^>^ get();
			void set(IDynamicVectorClass<String^>^ value);
		}

		property bool ExeVersionsMatch
		{
			bool get();
			void set(bool value);
		}

		property bool StringVersionsMatch
		{
			bool get();
			void set(bool value);
		}

		property unsigned short Port
		{
			unsigned short get();
			void set(unsigned short value);
		}

		property unsigned int CFGModTime
		{
			unsigned int get();
			void set(unsigned int value);
		}

		property float MaxWorldDistance
		{
			float get();
			void set(float value);
		}

		property WinTypeEnum WinType
		{
			WinTypeEnum get();
			void set(WinTypeEnum value);
		}

		property DateTime GameStartTime2
		{
			DateTime get();
			void set(DateTime value);
		}

		property unsigned int GameStartTime
		{
			unsigned int get();
			void set(unsigned int value);
		}

		property bool IsQuickMatch
		{
			bool get();
			void set(bool value);
		}

		property array<unsigned long>^ Clans
		{
			array<unsigned long>^ get();
			void set(array<unsigned long>^ value);
		}
	};

	public ref class cGameData : public cGameDataEventSignaler, public IcGameData
	{
		public:
			cGameData(IntPtr pointer);

			static int GetMissionNumberFromMapName(String^ mapName);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual void OnGameBegin() sealed;
			virtual void OnGameEnd() sealed;
			virtual void Think() sealed;
			virtual void Render() sealed;
			virtual void ResetGame(bool skipPlayerReset) sealed;
			virtual int ChoosePlayerType(IcPlayer^ player, int type, bool skipAutoTeam) sealed;
			virtual void LoadFromServerConfig() sealed;
			virtual void SaveToServerConfig() sealed;
			virtual void SoldierAdded(ISoldierGameObj^ obj) sealed;
			virtual void ShowGameSettingsLimits() sealed;
			virtual IcGameDataSinglePlayer^ AsSinglePlayer();
			virtual IcGameDataSkirmish^ AsSkirmish();
			virtual IcGameDataCnC^ AsCnC();
			virtual bool IsValidSettings([Out] String^% errorString, bool b) sealed;
			virtual void ExportTier1Data(IntPtr packet) sealed;
			virtual void ImportTier1Data(IntPtr packet) sealed;
			virtual void ImportTier1DataWOLGameInfo(IntPtr packet) sealed;
			virtual void ExportTier2Data(IntPtr packet) sealed;
			virtual void ImportTier2Data(IntPtr packet) sealed;
			virtual void ResetTimeRemainingSeconds() sealed;
			virtual void SetTimeLimitMinutes(int time) sealed;
			virtual String^ GetMapCycle(int map) sealed;
			virtual void SetMapCyle(int map, String^ name) sealed;
			virtual bool IsValidPlayerType(int playerType) sealed;

			property IntPtr cGameDataPointer
			{
				virtual IntPtr get() sealed;
			}

			property String^ GameName
			{
				virtual String^ get() sealed;
			}

			property IcGameData::GameTypeEnum GameType
			{
				virtual IcGameData::GameTypeEnum get() sealed;
			}

			property bool IsEditableTeaming
			{
				virtual bool get() sealed;
			}

			property bool IsEditableClanGame
			{
				virtual bool get() sealed;
			}

			property bool IsEditableFriendlyFire
			{
				virtual bool get() sealed;
			}

			property bool IsSinglePlayer
			{
				virtual bool get() sealed;
			}

			property bool IsSkirmish
			{
				virtual bool get() sealed;
			}

			property bool IsCnC
			{
				virtual bool get() sealed;
			}

			property unsigned int MinPlayers
			{
				virtual unsigned int get() sealed;
			}

			property bool IsGameOver
			{
				virtual bool get() sealed;
			}

			property bool IsLimited
			{
				virtual bool get() sealed;
			}

			property bool IsGameplayPermitted
			{
				virtual bool get() sealed;
			}

			property bool RememberInventory
			{
				virtual bool get() sealed;
			}

			property String^ Description
			{
				virtual String^ get() sealed;
			}

			property float TimeRemainingSeconds
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool IsMapCycleOver
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property int WinnerID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property String^ MOTD
			{
				virtual String^ get() sealed;
				virtual void set(String^ value) sealed;
			}

			property String^ MapName
			{
				virtual String^ get() sealed;
				virtual void set(String^ value) sealed;
			}

			property RadarMode RadarMode
			{
				virtual RenSharp::RadarMode get() sealed;
				virtual void set(RenSharp::RadarMode value) sealed;
			}

			property String^ MVPName
			{
				virtual String^ get() sealed;
				virtual void set(String^ value) sealed;
			}

			property unsigned int MVPCount
			{
				virtual unsigned int get() sealed;
				virtual void set(unsigned int value) sealed;
			}

			property unsigned int TimeLimitMinutes
			{
				virtual unsigned int get() sealed;
				virtual void set(unsigned int value) sealed;
			}

			property int CurrentPlayers
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property bool IsFriendlyFirePermitted
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property unsigned int GameDurationSeconds
			{
				virtual unsigned int get() sealed;
				virtual void set(unsigned int value) sealed;
			}

			property String^ ModName
			{
				virtual String^ get() sealed;
				virtual void set(String^ value) sealed;
			}

			property unsigned int MapNumber
			{
				virtual unsigned int get() sealed;
				virtual void set(unsigned int value) sealed;
			}

			property bool IsDedicated
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property int MaxPlayers
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property bool IsLaddered
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsIntermission
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsTeamChangingAllowed
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsRemixTeams
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool CanRepairBuildings
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool DriverIsAlwaysGunner
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool SpawnWeapons
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property String^ INIFilename
			{
				virtual String^ get() sealed;
				virtual void set(String^ value) sealed;
			}

			property String^ SettingsDescription
			{
				virtual String^ get() sealed;
				virtual void set(String^ value) sealed;
			}

			property int MinQualifyingTimeMinutes
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property bool DoesMapExist
			{
				virtual bool get() sealed;
			}

			property String^ MapBaseName
			{
				virtual String^ get() sealed;
			}

			property IPAddress^ IP
			{
				virtual IPAddress^ get() sealed;
				virtual void set(IPAddress^ value) sealed;
			}

			property int IntermissionTimeSeconds
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property bool IsTimeLimt
			{
				virtual bool get() sealed;
			}

			property int ExeKey
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property float IntermissionTimeLeft
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int FrameCount
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property bool IsAutoRestart
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsPassworded
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool GrantWeapons
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsClanGame
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool UseLagReduction
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool DoMapsLoop
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property String^ GameTitle
			{
				virtual String^ get() sealed;
				virtual void set(String^ value) sealed;
			}

			property String^ Password
			{
				virtual String^ get() sealed;
				virtual void set(String^ value) sealed;
			}

			property array<String^>^ MapList
			{
				virtual array<String^>^ get() sealed;
			}

			property String^ Owner
			{
				virtual String^ get() sealed;
				virtual void set(String^ value) sealed;
			}

			property IDynamicVectorClass<String^>^ BottomText
			{
				virtual IDynamicVectorClass<String^>^ get() sealed;
				virtual void set(IDynamicVectorClass<String^>^ value) sealed;
			}

			property IDynamicVectorClass<String^>^ SettingsLimits
			{
				virtual IDynamicVectorClass<String^>^ get() sealed;
				virtual void set(IDynamicVectorClass<String^>^ value) sealed;
			}

			property bool ExeVersionsMatch
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool StringVersionsMatch
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property unsigned short Port
			{
				virtual unsigned short get() sealed;
				virtual void set(unsigned short value) sealed;
			}

			property unsigned int CFGModTime
			{
				virtual unsigned int get() sealed;
				virtual void set(unsigned int value) sealed;
			}

			property float MaxWorldDistance
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property IcGameData::WinTypeEnum WinType
			{
				virtual IcGameData::WinTypeEnum get() sealed;
				virtual void set(IcGameData::WinTypeEnum value) sealed;
			}

			property DateTime GameStartTime2
			{
				virtual DateTime get() sealed;
				virtual void set(DateTime value) sealed;
			}

			property unsigned int GameStartTime
			{
				virtual unsigned int get() sealed;
				virtual void set(unsigned int value) sealed;
			}

			property bool IsQuickMatch
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property array<unsigned long>^ Clans
			{
				virtual array<unsigned long>^ get() sealed;
				virtual void set(array<unsigned long>^ value) sealed;
			}

		protected:
			property ::Signaler<::cGameDataEvent>* InternalcGameDataEventSignalerPointer
			{
				::Signaler<::cGameDataEvent>* get() override;
			}

			property ::cGameData* InternalcGameDataPointer
			{
				virtual ::cGameData* get();
			}
	};

	public interface class IcGameDataCnC : public IcGameData
	{
		property IntPtr cGameDataCnCPointer
		{
			IntPtr get();
		}

		property bool BaseDestructionEndsGame
		{
			bool get();
			void set(bool value);
		}

		property bool BeaconPlacementEndsGame
		{
			bool get();
			void set(bool value);
		}

		property int StartingCredits
		{
			int get();
			void set(int value);
		}

		property IBaseControllerClass^ GDI
		{
			IBaseControllerClass^ get();
			void set(IBaseControllerClass^ value);
		}

		property IBaseControllerClass^ Nod
		{
			IBaseControllerClass^ get();
			void set(IBaseControllerClass^ value);
		}

		property bool BasesInitalized
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class cGameDataCnC : public cGameData, public IcGameDataCnC
	{
		public:
			cGameDataCnC(IntPtr pointer);

			IcGameDataCnC^ AsCnC() override;

			property IntPtr cGameDataCnCPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool BaseDestructionEndsGame
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool BeaconPlacementEndsGame
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property int StartingCredits
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property IBaseControllerClass^ GDI
			{
				virtual IBaseControllerClass^ get() sealed;
				virtual void set(IBaseControllerClass^ value) sealed;
			}

			property IBaseControllerClass^ Nod
			{
				virtual IBaseControllerClass^ get() sealed;
				virtual void set(IBaseControllerClass^ value) sealed;
			}

			property bool BasesInitalized
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			property ::cGameData* InternalcGameDataPointer
			{
				::cGameData* get() override;
			}

			property ::cGameDataCnc* InternalcGameDataCnCPointer
			{
				virtual ::cGameDataCnc* get();
			}
	};

	public interface class IcGameDataSkirmish : public IcGameData
	{
		property IntPtr cGameDataSkirmishPointer
		{
			IntPtr get();
		}

		property bool BaseDestructionEndsGame
		{
			bool get();
			void set(bool value);
		}

		property bool BeaconPlacementEndsGame
		{
			bool get();
			void set(bool value);
		}

		property int StartingCredits
		{
			int get();
			void set(int value);
		}

		property IBaseControllerClass^ GDI
		{
			IBaseControllerClass^ get();
			void set(IBaseControllerClass^ value);
		}

		property IBaseControllerClass^ Nod
		{
			IBaseControllerClass^ get();
			void set(IBaseControllerClass^ value);
		}

		property bool BasesInitalized
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class cGameDataSkirmish : public cGameData, public IcGameDataSkirmish
	{
		public:
			cGameDataSkirmish(IntPtr pointer);

			IcGameDataSkirmish^ AsSkirmish() override;

			property IntPtr cGameDataSkirmishPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool BaseDestructionEndsGame
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool BeaconPlacementEndsGame
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property int StartingCredits
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property IBaseControllerClass^ GDI
			{
				virtual IBaseControllerClass^ get() sealed;
				virtual void set(IBaseControllerClass^ value) sealed;
			}

			property IBaseControllerClass^ Nod
			{
				virtual IBaseControllerClass^ get() sealed;
				virtual void set(IBaseControllerClass^ value) sealed;
			}

			property bool BasesInitalized
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			property ::cGameData* InternalcGameDataPointer
			{
				::cGameData* get() override;
			}

			property ::cGameDataSkirmish* InternalcGameDataSkirmishPointer
			{
				virtual ::cGameDataSkirmish* get();
			}
	};

	public interface class IcGameDataSinglePlayer : public IcGameData
	{
		property IntPtr cGameDataSinglePlayerPointer
		{
			IntPtr get();
		}
	};

	public ref class cGameDataSinglePlayer : public cGameData, public IcGameDataSinglePlayer
	{
		public:
			cGameDataSinglePlayer(IntPtr pointer);

			IcGameDataSinglePlayer^ AsSinglePlayer() override;

			property IntPtr cGameDataSinglePlayerPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::cGameData* InternalcGameDataPointer
			{
				::cGameData* get() override;
			}

			property ::cGameDataSinglePlayer* InternalcGameDataSinglePlayerPointer
			{
				virtual ::cGameDataSinglePlayer* get();
			}
	};
}