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

#include "AbstractUnmanagedObject.h"
#include "IUnmanagedContainer.h"
#include "MConnectionAcceptanceFilter.h"
#include "Mengine_ttdef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4561 4996 4091 4251 4244 26495 26454)
#include <da_event.h>

class RenSharpEventClass;
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Collections;

namespace RenSharp
{
	interface class IcPlayer;
	interface class IDATokenClass;
	interface class IConnectionRequest;
	interface class IBaseControllerClass;
	interface class ISoldierGameObjDef;
	interface class IVehicleGameObjDef;
	interface class IPowerUpGameObjDef;
	interface class IVehicleGameObj;
	interface class IPowerUpGameObj;
	interface class IWeaponDefinitionClass;
	interface class IWeaponClass;
	interface class IBeaconGameObj;
	interface class IC4GameObj;
	interface class ISmartGameObj;
	interface class IVehicleFactoryGameObj;
	interface class IScriptableGameObj;
	interface class IDamageableGameObj;
	interface class IArmedGameObj;
	interface class IAmmoDefinitionClass;
	interface class IPhysicalGameObj;
	interface class IScriptZoneGameObj;
	interface class ISoldierGameObj;
	interface class IWeaponBagClass;
	interface class IRenSharpEventClass;

	public enum class DAChatType : int
	{
		All = ::DAChatType::ALL,
		Public = ::DAChatType::PUBLIC,
		Team = ::DAChatType::TEAM,
		Private = ::DAChatType::PRIVATE,
		TMSG = ::DAChatType::TMSG
	};

	public enum class DAAccessLevel : int
	{
		None = ::DAAccessLevel::NONE,
		VIP = ::DAAccessLevel::VIP,
		TempModerator = ::DAAccessLevel::TEMPMODERATOR,
		HalfModerator = ::DAAccessLevel::HALFMODERATOR,
		FullModerator = ::DAAccessLevel::FULLMODERATOR,
		SuperModerator = ::DAAccessLevel::SUPERMODERATOR,
		Administrator = ::DAAccessLevel::ADMINISTRATOR
	};

	public enum class DADamageType : int
	{
		None = ::DADamageType::NONE,
		Normal = ::DADamageType::NORMAL,
		Neckshot = ::DADamageType::NECKSHOT,
		Headshot = ::DADamageType::HEADSHOT,
		Explosion = ::DADamageType::EXPLOSION,
		Splash = ::DADamageType::SPLASH,
		Burn = ::DADamageType::BURN,
		Squish = ::DADamageType::SQUISH,
		Fall = ::DADamageType::FALL,
		Tiberium = ::DADamageType::TIBERIUM,
		Flip = ::DADamageType::FLIP,
		Repair = ::DADamageType::REPAIR
	};

	public enum class DAEventType : int
	{
		SettingsLoaded = DAEvent::SETTINGSLOADED,
		Chat = DAEvent::CHAT,
		ChatCommand = DAEvent::CHATCOMMAND,
		KeyHook = DAEvent::KEYHOOK,
		HostChat = DAEvent::HOSTCHAT,
		Radio = DAEvent::RADIO,
		ConnectionRequest = DAEvent::CONNECTIONREQUEST,
		PlayerPreJoin = DAEvent::PLAYERPREJOIN,
		PlayerJoin = DAEvent::PLAYERJOIN,
		PlayerLeave = DAEvent::PLAYERLEAVE,
		PlayerLoaded = DAEvent::PLAYERLOADED,
		NameChange = DAEvent::NAMECHANGE,
		LevelLoaded = DAEvent::LEVELLOADED,
		Remix = DAEvent::REMIX,
		Rebalance = DAEvent::REBALANCE,
		Swap = DAEvent::SWAP,
		Gameover = DAEvent::GAMEOVER,
		ConsoleOutput = DAEvent::CONSOLEOUTPUT,
		RenLog = DAEvent::RENLOG,
		DALog = DAEvent::DALOG,
		VehiclePurchaseRequest = DAEvent::VEHICLEPURCHASEREQUEST,
		CharacterPurchaseRequest = DAEvent::CHARACTERPURCHASEREQUEST,
		PowerUpPurchaseRequest = DAEvent::POWERUPPURCHASEREQUEST,
		CustomPurchaseRequest = DAEvent::CUSTOMPURCHASEREQUEST,
		VehiclePurchase = DAEvent::VEHICLEPURCHASE,
		CharacterPurchase = DAEvent::CHARACTERPURCHASE,
		PowerUpPurchase = DAEvent::POWERUPPURCHASE,
		CustomPurchase = DAEvent::CUSTOMPURCHASE,
		Refill = DAEvent::REFILL,
		Suicide = DAEvent::SUICIDE,
		TeamChangeRequest = DAEvent::TEAMCHANGEREQUEST,
		TeamChange = DAEvent::TEAMCHANGE,
		VehicleEntryRequest = DAEvent::VEHICLEENTRYREQUEST,
		VehicleEnter = DAEvent::VEHICLEENTER,
		VehicleExit = DAEvent::VEHICLEEXIT,
		PowerUpGrantRequest = DAEvent::POWERUPGRANTREQUEST,
		PowerUpGrant = DAEvent::POWERUPGRANT,
		AddWeaponRequest = DAEvent::ADDWEAPONREQUEST,
		AddWeapon = DAEvent::ADDWEAPON,
		RemoveWeapon = DAEvent::REMOVEWEAPON,
		ClearWeapons = DAEvent::CLEARWEAPONS,
		BeaconDeploy = DAEvent::BEACONDEPLOY,
		BeaconDetonate = DAEvent::BEACONDETONATE,
		C4DetonateRequest = DAEvent::C4DETONATEREQUEST,
		C4Detonate = DAEvent::C4DETONATE,
		ChangeCharacter = DAEvent::CHANGECHARACTER,
		VehicleFlip = DAEvent::VEHICLEFLIP,
		RequestVehicle = DAEvent::REQUESTVEHICLE,
		Think = DAEvent::THINK
	};

	public enum class DAObjectEventType : int
	{
		Created = DAObjectEvent::CREATED,
		Destroyed = DAObjectEvent::DESTROYED,
		KillDealt = DAObjectEvent::KILLDEALT,
		KillReceived = DAObjectEvent::KILLRECEIVED,
		StockClientDamageRequest = DAObjectEvent::STOCKCLIENTDAMAGEREQUEST,
		TTClientDamageRequest = DAObjectEvent::TTCLIENTDAMAGEREQUEST,
		DamageDealtRequest = DAObjectEvent::DAMAGEDEALTREQUEST,
		DamageReceivedRequest = DAObjectEvent::DAMAGERECEIVEDREQUEST,
		DamageDealt = DAObjectEvent::DAMAGEDEALT,
		DamageReceived = DAObjectEvent::DAMAGERECEIVED,
		Custom = DAObjectEvent::CUSTOM,
		Poke = DAObjectEvent::POKE,
		ZoneEnter = DAObjectEvent::ZONEENTER,
		ZoneExit = DAObjectEvent::ZONEEXIT
	};

	[Flags]
	public enum class DAObjectEventObjectType : int
	{
		All = DAObjectEvent::ALL,
		Player = DAObjectEvent::PLAYER,
		Damageable = DAObjectEvent::DAMAGEABLE,
		Soldier = DAObjectEvent::SOLDIER,
		Vehicle = DAObjectEvent::VEHICLE,
		C4 = DAObjectEvent::C4,
		Beacon = DAObjectEvent::BEACON,
		Building = DAObjectEvent::BUILDING,
		Armed = DAObjectEvent::ARMED,
		PowerUp = DAObjectEvent::POWERUP,
		Simple = DAObjectEvent::SIMPLE
	};

	public interface class IDAEventClass : public IUnmanagedObject
	{
		void RegisterEvent(DAEventType type, int priority);

		void RegisterEvent(DAEventType type);

		void UnregisterEvent(DAEventType type);

		void ClearEvents();

		void RegisterObjectEvent(DAObjectEventType type, DAObjectEventObjectType objectType, int priority);

		void RegisterObjectEvent(DAObjectEventType type, DAObjectEventObjectType objectType);

		void UnregisterObjectEvent(DAObjectEventType type);

		void ClearObjectEvents();

		void StartTimer(int number, float duration, bool repeat, unsigned int data);

		void StartTimer(int number, float duration, bool repeat);

		void StartTimer(int number, float duration);

		void StopTimer(int number, unsigned int data);

		void StopTimer(int number);

		bool IsTimer(int number, unsigned int data);

		bool IsTimer(int number);

		void ClearTimers();

		void UnregisterChatCommand(String^ trigger);

		void ClearChatCommands();

		void UnregisterKeyHook(String^ trigger);

		void ClearKeyHooks();

		void SettingsLoadedEvent();

		bool ChatEvent(IcPlayer^ player, TextMessageEnum type, String^ message, int receiverID);

		bool ChatCommandEvent(IcPlayer^ player, TextMessageEnum type, String^ command, IDATokenClass^ text, int receiverID);

		bool KeyHookEvent(IcPlayer^ player, String^ key);

		bool HostChatEvent(int id, TextMessageEnum type, String^ message);

		bool RadioEvent(IcPlayer^ player, int playerType, int announcementID, int iconID, AnnouncementEnum announcementType);

		ConnectionAcceptanceFilterStatus ConnectionRequestEvent(IConnectionRequest^ request, String^% refusalMessage);

		void PlayerPreJoinEvent(IConnectionRequest^ request);

		void PlayerJoinEvent(IcPlayer^ player);

		void PlayerLeaveEvent(IcPlayer^ player);

		void PlayerLoadedEvent(IcPlayer^ player);

		void NameChangeEvent(IcPlayer^ player);

		void LevelLoadedEvent();

		void RemixEvent();

		void RebalanceEvent();

		void SwapEvent();

		void GameOverEvent();

		void ConsoleOutputEvent(String^ output);

		void RenLogEvent(String^ output);

		void DALogEvent(String^ header, String^ output);

		int CharacterPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, ISoldierGameObjDef^ item);

		int VehiclePurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, IVehicleGameObjDef^ item);

		int PowerUpPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, IPowerUpGameObjDef^ item);

		int CustomPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, unsigned int id);

		void CharacterPurchaseEvent(IcPlayer^ player, float cost, ISoldierGameObjDef^ item);

		void VehiclePurchaseEvent(IcPlayer^ player, float cost, IVehicleGameObjDef^ item);

		void PowerUpPurchaseEvent(IcPlayer^ player, float cost, IPowerUpGameObjDef^ item);

		void CustomPurchaseEvent(IcPlayer^ player, float cost, unsigned int id);

		bool RefillEvent(IcPlayer^ player);

		bool SuicideEvent(IcPlayer^ player);

		bool TeamChangeRequestEvent(IcPlayer^ player);

		void TeamChangeEvent(IcPlayer^ player);

		bool VehicleEntryRequestEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int% seat);

		void VehicleEnterEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int seat);

		void VehicleExitEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int seat);

		bool PowerUpGrantRequestEvent(IcPlayer^ player, IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj);

		void PowerUpGrantEvent(IcPlayer^ player, IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj);

		bool AddWeaponRequestEvent(IcPlayer^ player, IWeaponDefinitionClass^ weapon);

		void AddWeaponEvent(IcPlayer^ player, IWeaponClass^ weapon);

		void RemoveWeaponEvent(IcPlayer^ player, IWeaponClass^ weapon);

		void ClearWeaponsEvent(IcPlayer^ player);

		void BeaconDeployEvent(IBeaconGameObj^ beacon);

		void BeaconDetonateEvent(IBeaconGameObj^ beacon);

		bool C4DetonateRequestEvent(IC4GameObj^ c4, ISmartGameObj^ triggerer);

		void C4DetonateEvent(IC4GameObj^ c4);

		void ChangeCharacterEvent(IcPlayer^ player, ISoldierGameObjDef^ soldier);

		bool VehicleFlipEvent(IVehicleGameObj^ vehicle);

		bool RequestVehicleEvent(IVehicleFactoryGameObj^ factory, IVehicleGameObjDef^ vehicle, IcPlayer^ player, float delay);

		void Think();

		void ObjectCreatedEvent(IScriptableGameObj^ obj);

		bool StockClientDamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float damage, uint warhead);

		bool TTClientDamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, IAmmoDefinitionClass^ ammo, String^ bone);

		bool DamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float% damage, unsigned int% warhead, float scale, DADamageType type);

		void DamageEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float damage, unsigned int warhead, float scale, DADamageType type);

		void KillEvent(IDamageableGameObj^ victim, IArmedGameObj^ killer, float damage, unsigned int warhead, float scale, DADamageType type);

		void CustomEvent(IScriptableGameObj^ obj, int type, int param, IScriptableGameObj^ sender);

		void PokeEvent(IcPlayer^ player, IPhysicalGameObj^ obj);

		void ZoneEnterEvent(IScriptZoneGameObj^ obj, IPhysicalGameObj^ enterer);

		void ZoneExitEvent(IScriptZoneGameObj^ obj, IPhysicalGameObj^ exiter);

		void ObjectDestroyedEvent(IScriptableGameObj^ obj);

		void TimerExpired(int number, unsigned int data);

		IRenSharpEventClass^ AsManagedEventClass();

		property IntPtr DAEventClassPointer
		{
			IntPtr get();
		}

		property bool IsManagedEventClass
		{
			bool get();
		}
	};

	public interface class IDAEventStruct : public IUnmanagedObject
	{
		property IntPtr DAEventStructPointer
		{
			IntPtr get();
		}

		property IDAEventClass^ Base
		{
			IDAEventClass^ get();
			void set(IDAEventClass ^value);
		}

		property int Priority
		{
			int get();
			void set(int value);
		}
	};

	public ref class DAEventStruct : public AbstractUnmanagedObject, public IDAEventStruct
	{
		private:
			DAEventStruct();

		public:
			DAEventStruct(IntPtr pointer);

			static IUnmanagedContainer<IDAEventStruct^>^ CreateDAEventStruct();

			bool Equals(Object^ other) override;

			property IntPtr DAEventStructPointer
			{
				virtual IntPtr get() sealed;
			}

			property IDAEventClass^ Base
			{
				virtual IDAEventClass^ get() sealed;
				virtual void set(IDAEventClass^ value) sealed;
			}

			property int Priority
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DAEventStruct* InternalDAEventStructPointer
			{
				virtual ::DAEventStruct* get();
			}
	};

	public interface class IDAObjectEventStruct : public IUnmanagedObject
	{
		bool HasFlag(DAObjectEventObjectType flag);

		bool CheckObjectType(IScriptableGameObj^ obj);

		property IntPtr DAObjectEventStructPointer
		{
			IntPtr get();
		}

		property IDAEventClass^ Base
		{
			IDAEventClass^ get();
			void set(IDAEventClass^ value);
		}

		property DAObjectEventObjectType ObjectType
		{
			DAObjectEventObjectType get();
			void set(DAObjectEventObjectType value);
		}

		property int Priority
		{
			int get();
			void set(int value);
		}
	};

	public ref class DAObjectEventStruct : public AbstractUnmanagedObject, public IDAObjectEventStruct
	{
		private:
			DAObjectEventStruct();

		public:
			DAObjectEventStruct(IntPtr pointer);

			static IUnmanagedContainer<IDAObjectEventStruct^>^ CreateDAObjectEventStruct();

			bool Equals(Object^ other) override;

			virtual bool HasFlag(DAObjectEventObjectType flag) sealed;
			virtual bool CheckObjectType(IScriptableGameObj^ obj) sealed;

			property IntPtr DAObjectEventStructPointer
			{
				virtual IntPtr get() sealed;
			}

			property IDAEventClass^ Base
			{
				virtual IDAEventClass^ get() sealed;
				virtual void set(IDAEventClass^ value) sealed;
			}

			property DAObjectEventObjectType ObjectType
			{
				virtual DAObjectEventObjectType get() sealed;
				virtual void set(DAObjectEventObjectType value) sealed;
			}

			property int Priority
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DAObjectEventStruct* InternalDAObjectEventStructPointer
			{
				virtual ::DAObjectEventStruct* get();
			}
	};

	public interface class IDAEventTimerStruct : public IUnmanagedObject
	{
		property IntPtr DAEventTimerStructPointer
		{
			IntPtr get();
		}

		property IDAEventClass^ Base
		{
			IDAEventClass^ get();
			void set(IDAEventClass^ value);
		}

		property unsigned long StartTime
		{
			unsigned long get();
			void set(unsigned long value);
		}

		property unsigned long Duration
		{
			unsigned long get();
			void set(unsigned long value);
		}

		property bool Repeat
		{
			bool get();
			void set(bool value);
		}

		property int Number
		{
			int get();
			void set(int value);
		}

		property unsigned int Data
		{
			unsigned int get();
			void set(unsigned int value);
		}
	};

	public ref class DAEventTimerStruct : public AbstractUnmanagedObject, public IDAEventTimerStruct
	{
		private:
			DAEventTimerStruct();

		public:
			DAEventTimerStruct(IntPtr pointer);

			static IUnmanagedContainer<IDAEventTimerStruct^>^ CreateDAEventTimerStruct();

			bool Equals(Object^ other) override;

			property IntPtr DAEventTimerStructPointer
			{
				virtual IntPtr get() sealed;
			}

			property IDAEventClass^ Base
			{
				virtual IDAEventClass^ get() sealed;
				virtual void set(IDAEventClass^ value) sealed;
			}

			property unsigned long StartTime
			{
				virtual unsigned long get() sealed;
				virtual void set(unsigned long value) sealed;
			}

			property unsigned long Duration
			{
				virtual unsigned long get() sealed;
				virtual void set(unsigned long value) sealed;
			}

			property bool Repeat
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property int Number
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property unsigned int Data
			{
				virtual unsigned int get() sealed;
				virtual void set(unsigned int value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DAEventTimerStruct* InternalDAEventTimerStructPointer
			{
				virtual ::DAEventTimerStruct* get();
			}
	};

	public ref class DAEventManager abstract sealed
	{
		private:
			static Generic::IDictionary<IntPtr, IRenSharpEventClass^>^ managedEventClasses;

			static DAEventManager();

		public:
			static void OnManagedEventClassDestructed(IntPtr eventClass);
			static bool IsManagedEventClass(IntPtr eventClass);
			static bool IsManagedEventClass(IDAEventClass^ eventClass);
			static IRenSharpEventClass^ AsManagedEventClass(IntPtr eventClass);
			static IRenSharpEventClass^ AsManagedEventClass(IDAEventClass^ eventClass);

			static void Init();
			static void SettingsLoadedEvent();
			static bool ChatEvent(IcPlayer^ player, TextMessageEnum type, String^ message, int receiverID);
			static bool ChatCommandEvent(IcPlayer^ player, TextMessageEnum type, String^ command, IDATokenClass^ text, int receiverID);
			static bool KeyHookEvent(IcPlayer^ player, String^ key);
			static bool HostChatEvent(int id, TextMessageEnum type, String^ message);
			static bool RadioEvent(int playerId, int playerType, int announcementID, int iconID, AnnouncementEnum announcementType);
			static void PlayerJoinEvent(int playerId, String ^name);
			static void PlayerLeaveEvent(int playerId);
			static void NameChangeEvent(IcPlayer^ player);
			static void LevelLoadedEvent();
			static void RemixEvent();
			static void RebalanceEvent();
			static void SwapEvent();
			static void GameOverEvent();
			static void ConsoleOutputEvent(String^ output);
			static void RenLogEvent(String^ output);
			static void DALogEvent(String^ header, String^ output);
			static int CharacterPurchaseRequestEvent(IBaseControllerClass^ baseController, ISoldierGameObj^ soldier, unsigned int cost, unsigned int preset, String^ data);
			static int VehiclePurchaseRequestEvent(IBaseControllerClass^ baseController, ISoldierGameObj^ soldier, unsigned int cost, unsigned int preset, String^ data);
			static int PowerUpPurchaseRequestEvent(IBaseControllerClass^ baseController, ISoldierGameObj^ soldier, unsigned int cost, unsigned int preset, String^ data);
			static int CustomPurchaseRequestEvent(IBaseControllerClass^ baseController, ISoldierGameObj^ soldier, unsigned int cost, unsigned int preset);
			static void CharacterPurchaseEvent(IcPlayer^ player, float cost, ISoldierGameObjDef^ item);
			static void VehiclePurchaseEvent(IcPlayer^ player, float cost, IVehicleGameObjDef^ item);
			static void PowerUpPurchaseEvent(IcPlayer^ player, float cost, IPowerUpGameObjDef^ item);
			static void CustomPurchaseEvent(IcPlayer^ player, float cost, unsigned int id);
			static bool RefillEvent(ISoldierGameObj^ soldier);
			static void SuicideEvent(int id);
			static void TeamChangeRequestEvent(int id);
			static bool VehicleEntryRequestEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int% seat);
			static bool PowerUpGrantRequestEvent(ISmartGameObj^ grantee, IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj);
			static void PowerUpGrantEvent(ISmartGameObj^ grantee, IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj);
			static bool AddWeaponRequestEvent(IWeaponBagClass^ bag, IWeaponDefinitionClass^ weapon);
			static void AddWeaponEvent(IWeaponBagClass^ bag, IWeaponClass^ weapon);
			static void RemoveWeaponEvent(IWeaponBagClass^ bag, int index);
			static void ClearWeaponsEvent(IWeaponBagClass^ bag);
			static void BeaconSetStateEvent(IBeaconGameObj^ beacon);
			static bool C4DetonateRequestEvent(IC4GameObj^ c4);
			static void C4DetonateEvent(IC4GameObj^ c4);
			static void SoldierReInitEvent(ISoldierGameObj^ soldier, ISoldierGameObjDef^ soldierDef);
			static bool RequestVehicleEvent(IVehicleFactoryGameObj^ factory, unsigned int vehicle, ISoldierGameObj^ owner, float delay);
			static void Think();
			static void ObjectCreatedEvent(IntPtr data, IScriptableGameObj^ obj);
			static bool StockClientDamageRequestEvent(IPhysicalGameObj^ damager, IPhysicalGameObj^ target, float damage, uint warhead);
			static bool TTClientDamageRequestEvent(IPhysicalGameObj^ damager, IPhysicalGameObj^ target, IAmmoDefinitionClass^ ammo, String^ bone);
			static bool DamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float% damage, unsigned int% warhead, float scale, DADamageType type);
			static void DamageEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float damage, unsigned int warhead, float scale, DADamageType type);
			static void KillEvent(IDamageableGameObj^ victim, IArmedGameObj^ killer, float damage, unsigned int warhead, float scale, DADamageType type);
			static bool VehicleFlipEvent(IVehicleGameObj^ vehicle);
			static void RegisterEvent(IDAEventClass^ base, DAEventType type, int priority);
			static void RegisterEvent(IRenSharpEventClass^ base, DAEventType type, int priority);
			static void UnregisterEvent(IDAEventClass^ base, DAEventType type);
			static void UnregisterEvent(IRenSharpEventClass^ base, DAEventType type);
			static void ClearEvents(IDAEventClass^ base);
			static void ClearEvents(IRenSharpEventClass^ base);
			static void RegisterObjectEvent(IDAEventClass^ base, DAObjectEventType type, DAObjectEventObjectType objectType, int priority);
			static void RegisterObjectEvent(IRenSharpEventClass^ base, DAObjectEventType type, DAObjectEventObjectType objectType, int priority);
			static void UnregisterObjectEvent(IDAEventClass^ base, DAObjectEventType type);
			static void UnregisterObjectEvent(IRenSharpEventClass^ base, DAObjectEventType type);
			static void ClearObjectEvents(IDAEventClass^ base);
			static void ClearObjectEvents(IRenSharpEventClass^ base);
			static void StartTimer(IDAEventClass^ base, int number, float duration, bool repeat, unsigned int data);
			static void StartTimer(IRenSharpEventClass^ base, int number, TimeSpan duration, bool repeat, Object ^data);
			static void StopTimer(IDAEventClass^ base, int number, unsigned int data);
			static void StopTimer(IRenSharpEventClass^ base, int number, Object ^data);
			static bool IsTimer(IDAEventClass^ base, int number, unsigned int data);
			static bool IsTimer(IRenSharpEventClass^ base, int number, Object ^data);
			static void ClearTimers(IDAEventClass^ base);
			static void ClearTimers(IRenSharpEventClass^ base);

		internal:
			static void Shutdown();

			static void RegisterManagedEventClass(IRenSharpEventClass^ eventClass);
			static void UnregisterManagedEventClass(IRenSharpEventClass^ eventClass);
	};

	public ref class DAEventClass : public AbstractUnmanagedObject, public IDAEventClass
	{
		public:
			DAEventClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual void RegisterEvent(DAEventType type, int priority) sealed;
			virtual void RegisterEvent(DAEventType type) sealed;
			virtual void UnregisterEvent(DAEventType type) sealed;
			virtual void ClearEvents() sealed;
			virtual void RegisterObjectEvent(DAObjectEventType type, DAObjectEventObjectType objectType, int priority) sealed;
			virtual void RegisterObjectEvent(DAObjectEventType type, DAObjectEventObjectType objectType) sealed;
			virtual void UnregisterObjectEvent(DAObjectEventType type) sealed;
			virtual void ClearObjectEvents() sealed;
			virtual void StartTimer(int number, float duration, bool repeat, unsigned int data) sealed;
			virtual void StartTimer(int number, float duration, bool repeat) sealed;
			virtual void StartTimer(int number, float duration) sealed;
			virtual void StopTimer(int number, unsigned int data) sealed;
			virtual void StopTimer(int number) sealed;
			virtual bool IsTimer(int number, unsigned int data) sealed;
			virtual bool IsTimer(int number) sealed;
			virtual void ClearTimers() sealed;
			virtual void UnregisterChatCommand(String^ trigger) sealed;
			virtual void ClearChatCommands() sealed;
			virtual void UnregisterKeyHook(String^ trigger) sealed;
			virtual void ClearKeyHooks() sealed;
			virtual void SettingsLoadedEvent() sealed;
			virtual bool ChatEvent(IcPlayer^ player, TextMessageEnum type, String^ message, int receiverID) sealed;
			virtual bool ChatCommandEvent(IcPlayer^ player, TextMessageEnum type, String^ command, IDATokenClass^ text, int receiverID) sealed;
			virtual bool KeyHookEvent(IcPlayer^ player, String^ key) sealed;
			virtual bool HostChatEvent(int id, TextMessageEnum type, String^ message) sealed;
			virtual bool RadioEvent(IcPlayer^ player, int playerType, int announcementID, int iconID, AnnouncementEnum announcementType) sealed;
			virtual ConnectionAcceptanceFilterStatus ConnectionRequestEvent(IConnectionRequest^ request, String^% refusalMessage) sealed;
			virtual void PlayerPreJoinEvent(IConnectionRequest^ request) sealed;
			virtual void PlayerJoinEvent(IcPlayer^ player) sealed;
			virtual void PlayerLeaveEvent(IcPlayer^ player) sealed;
			virtual void PlayerLoadedEvent(IcPlayer^ player) sealed;
			virtual void NameChangeEvent(IcPlayer^ player) sealed;
			virtual void LevelLoadedEvent() sealed;
			virtual void RemixEvent() sealed;
			virtual void RebalanceEvent() sealed;
			virtual void SwapEvent() sealed;
			virtual void GameOverEvent() sealed;
			virtual void ConsoleOutputEvent(String^ output) sealed;
			virtual void RenLogEvent(String^ output) sealed;
			virtual void DALogEvent(String^ header, String^ output) sealed;
			virtual int CharacterPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, ISoldierGameObjDef^ item) sealed;
			virtual int VehiclePurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, IVehicleGameObjDef^ item) sealed;
			virtual int PowerUpPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, IPowerUpGameObjDef^ item) sealed;
			virtual int CustomPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, unsigned int id) sealed;
			virtual void CharacterPurchaseEvent(IcPlayer^ player, float cost, ISoldierGameObjDef^ item) sealed;
			virtual void VehiclePurchaseEvent(IcPlayer^ player, float cost, IVehicleGameObjDef^ item) sealed;
			virtual void PowerUpPurchaseEvent(IcPlayer^ player, float cost, IPowerUpGameObjDef^ item) sealed;
			virtual void CustomPurchaseEvent(IcPlayer^ player, float cost, unsigned int id) sealed;
			virtual bool RefillEvent(IcPlayer^ player) sealed;
			virtual bool SuicideEvent(IcPlayer^ player) sealed;
			virtual bool TeamChangeRequestEvent(IcPlayer^ player) sealed;
			virtual void TeamChangeEvent(IcPlayer^ player) sealed;
			virtual bool VehicleEntryRequestEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int% seat) sealed;
			virtual void VehicleEnterEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int seat) sealed;
			virtual void VehicleExitEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int seat) sealed;
			virtual bool PowerUpGrantRequestEvent(IcPlayer^ player, IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj) sealed;
			virtual void PowerUpGrantEvent(IcPlayer^ player, IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj) sealed;
			virtual bool AddWeaponRequestEvent(IcPlayer^ player, IWeaponDefinitionClass^ weapon) sealed;
			virtual void AddWeaponEvent(IcPlayer^ player, IWeaponClass^ weapon) sealed;
			virtual void RemoveWeaponEvent(IcPlayer^ player, IWeaponClass^ weapon) sealed;
			virtual void ClearWeaponsEvent(IcPlayer^ player) sealed;
			virtual void BeaconDeployEvent(IBeaconGameObj^ beacon) sealed;
			virtual void BeaconDetonateEvent(IBeaconGameObj^ beacon) sealed;
			virtual bool C4DetonateRequestEvent(IC4GameObj^ c4, ISmartGameObj^ triggerer) sealed;
			virtual void C4DetonateEvent(IC4GameObj^ c4) sealed;
			virtual void ChangeCharacterEvent(IcPlayer^ player, ISoldierGameObjDef^ soldier) sealed;
			virtual bool VehicleFlipEvent(IVehicleGameObj^ vehicle) sealed;
			virtual bool RequestVehicleEvent(IVehicleFactoryGameObj^ factory, IVehicleGameObjDef^ vehicle, IcPlayer^ player, float delay) sealed;
			virtual void Think() sealed;
			virtual void ObjectCreatedEvent(IScriptableGameObj^ obj) sealed;
			virtual bool StockClientDamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float damage, uint warhead) sealed;
			virtual bool TTClientDamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, IAmmoDefinitionClass^ ammo, String^ bone) sealed;
			virtual bool DamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float% damage, unsigned int% warhead, float scale, DADamageType type) sealed;
			virtual void DamageEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float damage, unsigned int warhead, float scale, DADamageType type) sealed;
			virtual void KillEvent(IDamageableGameObj^ victim, IArmedGameObj^ killer, float damage, unsigned int warhead, float scale, DADamageType type) sealed;
			virtual void CustomEvent(IScriptableGameObj^ obj, int type, int param, IScriptableGameObj^ sender) sealed;
			virtual void PokeEvent(IcPlayer^ player, IPhysicalGameObj^ obj) sealed;
			virtual void ZoneEnterEvent(IScriptZoneGameObj^ obj, IPhysicalGameObj^ enterer) sealed;
			virtual void ZoneExitEvent(IScriptZoneGameObj^ obj, IPhysicalGameObj^ exiter) sealed;
			virtual void ObjectDestroyedEvent(IScriptableGameObj^ obj) sealed;
			virtual void TimerExpired(int number, unsigned int data) sealed;
			virtual IRenSharpEventClass^ AsManagedEventClass() sealed;

			property IntPtr DAEventClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool IsManagedEventClass
			{
				virtual bool get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DAEventClass* InternalDAEventClassPointer
			{
				virtual ::DAEventClass* get();
			}
	};

	generic<typename T>
	public interface class IDASingleton : public IUnmanagedObject
	{

	};

	generic<typename T>
	public ref class DASingleton abstract : public AbstractUnmanagedObject, public IDASingleton<T>
	{
		public:
			DASingleton(IntPtr pointer)
				: AbstractUnmanagedObject(pointer)
			{

			}
	};
}