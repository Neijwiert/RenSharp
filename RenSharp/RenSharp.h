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

#include <da_event.h>

struct ICLRMetaHost;
struct ICLRRuntimeInfo;
struct ICLRRuntimeHost;
struct ICLRControl;
class RenSharpHostControl;
class RenSharpGameObjObserverClass;
class RenSharpPlayerObserverClass;
class RenSharpConsoleFunctionClass;
class RenSharpEventClass;
class RenSharpGameFeatureFactoryClass;
class RenSharpGameFeatureClass;
class DAGameFeatureClass;
class RenSharpPlayerDataFactoryClass;
class DAPlayerDataClass;
class RenSharpPlayerDataClass;
class RenSharpGameModeFactoryClass;
class DAGameModeClass;
class RenSharpGameModeClass;
class RenSharpCrateModifierFactoryClass;
class DACrateModifierClass;
class RenSharpCrateModifierClass;
class RenSharpCrateClass;
class RenSharpCrateFactoryClass;
class DACrateClass;
class RenSharpNodeClass;

class RenSharpRootEventClass : public DAEventClass 
{
	private:
		bool shutdown;
		bool shutdownPending;
		ICLRMetaHost *metaHost;
		ICLRRuntimeInfo *runtimeInfo;
		ICLRRuntimeHost *clrRuntimeHost;
		ICLRControl *clrControl;
		RenSharpHostControl *hostControl;

	public:
		RenSharpRootEventClass();
		~RenSharpRootEventClass();
		void On_Fatal_Exception(const char *exception);
		void On_Fatal_Exception_Callback(const char* exception);
		HRESULT Init();
		void Shutdown(bool fatal = false);
		bool Is_Shutting_Down() const;

		virtual void Game_Over_Event();
		virtual void Think();

		// RenSharpEventClass
		void EventClass_Destructed(RenSharpEventClass* eventClass);
		void EventClass_Settings_Loaded_Event(RenSharpEventClass* eventClass);
		bool EventClass_Chat_Event(RenSharpEventClass* eventClass, cPlayer *Player, TextMessageEnum Type, const wchar_t *Message, int ReceiverID);
		bool EventClass_Chat_Command_Event(RenSharpEventClass* eventClass, cPlayer *Player, TextMessageEnum Type, const StringClass &Command, const DATokenClass &Text, int ReceiverID);
		bool EventClass_Key_Hook_Event(RenSharpEventClass* eventClass, cPlayer *Player, const StringClass &Key);
		bool EventClass_Host_Chat_Event(RenSharpEventClass* eventClass, int ID, TextMessageEnum Type, const char *Message);
		bool EventClass_Radio_Event(RenSharpEventClass* eventClass, cPlayer *Player, int PlayerType, int AnnouncementID, int IconID, AnnouncementEnum AnnouncementType);
		ConnectionAcceptanceFilter::STATUS EventClass_Connection_Request_Event(RenSharpEventClass* eventClass, ConnectionRequest &Request, WideStringClass &RefusalMessage);
		void EventClass_Player_Pre_Join_Event(RenSharpEventClass* eventClass, ConnectionRequest &Request);
		void EventClass_Player_Join_Event(RenSharpEventClass* eventClass, cPlayer *Player);
		void EventClass_Player_Leave_Event(RenSharpEventClass* eventClass, cPlayer *Player);
		void EventClass_Player_Loaded_Event(RenSharpEventClass* eventClass, cPlayer *Player);
		void EventClass_Name_Change_Event(RenSharpEventClass* eventClass, cPlayer *Player);
		void EventClass_Level_Loaded_Event(RenSharpEventClass* eventClass);
		void EventClass_Remix_Event(RenSharpEventClass* eventClass);
		void EventClass_Rebalance_Event(RenSharpEventClass* eventClass);
		void EventClass_Swap_Event(RenSharpEventClass* eventClass);
		void EventClass_Game_Over_Event(RenSharpEventClass* eventClass);
		void EventClass_Console_Output_Event(RenSharpEventClass* eventClass, const char *Output);
		void EventClass_Ren_Log_Event(RenSharpEventClass* eventClass, const char *Output);
		void EventClass_DA_Log_Event(RenSharpEventClass* eventClass, const char *Header, const char *Output);
		int EventClass_Character_Purchase_Request_Event(RenSharpEventClass* eventClass, BaseControllerClass *Base, cPlayer *Player, float &Cost, const SoldierGameObjDef *Item);
		int EventClass_Vehicle_Purchase_Request_Event(RenSharpEventClass* eventClass, BaseControllerClass *Base, cPlayer *Player, float &Cost, const VehicleGameObjDef *Item);
		int EventClass_PowerUp_Purchase_Request_Event(RenSharpEventClass* eventClass, BaseControllerClass *Base, cPlayer *Player, float &Cost, const PowerUpGameObjDef *Item);
		int EventClass_Custom_Purchase_Request_Event(RenSharpEventClass* eventClass, BaseControllerClass *Base, cPlayer *Player, float &Cost, unsigned int ID);
		void EventClass_Character_Purchase_Event(RenSharpEventClass* eventClass, cPlayer *Player, float Cost, const SoldierGameObjDef *Item);
		void EventClass_Vehicle_Purchase_Event(RenSharpEventClass* eventClass, cPlayer *Player, float Cost, const VehicleGameObjDef *Item);
		void EventClass_PowerUp_Purchase_Event(RenSharpEventClass* eventClass, cPlayer *Player, float Cost, const PowerUpGameObjDef *Item);
		void EventClass_Custom_Purchase_Event(RenSharpEventClass* eventClass, cPlayer *Player, float Cost, unsigned int ID);
		bool EventClass_Refill_Event(RenSharpEventClass* eventClass, cPlayer *Player);
		bool EventClass_Suicide_Event(RenSharpEventClass* eventClass, cPlayer *Player);
		bool EventClass_Team_Change_Request_Event(RenSharpEventClass* eventClass, cPlayer *Player);
		void EventClass_Team_Change_Event(RenSharpEventClass* eventClass, cPlayer *Player);
		bool EventClass_Vehicle_Entry_Request_Event(RenSharpEventClass* eventClass, VehicleGameObj *Vehicle, cPlayer *Player, int &Seat);
		void EventClass_Vehicle_Enter_Event(RenSharpEventClass* eventClass, VehicleGameObj *Vehicle, cPlayer *Player, int Seat);
		void EventClass_Vehicle_Exit_Event(RenSharpEventClass* eventClass, VehicleGameObj *Vehicle, cPlayer *Player, int Seat);
		bool EventClass_PowerUp_Grant_Request_Event(RenSharpEventClass* eventClass, cPlayer *Player, const PowerUpGameObjDef *PowerUp, PowerUpGameObj *PowerUpObj);
		void EventClass_PowerUp_Grant_Event(RenSharpEventClass* eventClass, cPlayer *Player, const PowerUpGameObjDef *PowerUp, PowerUpGameObj *PowerUpObj);
		bool EventClass_Add_Weapon_Request_Event(RenSharpEventClass* eventClass, cPlayer *Player, const WeaponDefinitionClass *Weapon);
		void EventClass_Add_Weapon_Event(RenSharpEventClass* eventClass, cPlayer *Player, WeaponClass *Weapon);
		void EventClass_Remove_Weapon_Event(RenSharpEventClass* eventClass, cPlayer *Player, WeaponClass *Weapon);
		void EventClass_Clear_Weapons_Event(RenSharpEventClass* eventClass, cPlayer *Player);
		void EventClass_Beacon_Deploy_Event(RenSharpEventClass* eventClass, BeaconGameObj *Beacon);
		void EventClass_Beacon_Detonate_Event(RenSharpEventClass* eventClass, BeaconGameObj *Beacon);
		bool EventClass_C4_Detonate_Request_Event(RenSharpEventClass* eventClass, C4GameObj *C4, SmartGameObj *Triggerer);
		void EventClass_C4_Detonate_Event(RenSharpEventClass* eventClass, C4GameObj *C4);
		void EventClass_Change_Character_Event(RenSharpEventClass* eventClass, cPlayer *Player, const SoldierGameObjDef *Soldier);
		bool EventClass_Vehicle_Flip_Event(RenSharpEventClass* eventClass, VehicleGameObj *Vehicle);
		bool EventClass_Request_Vehicle_Event(RenSharpEventClass* eventClass, VehicleFactoryGameObj *Factory, const VehicleGameObjDef *Vehicle, cPlayer *Player, float Delay);
		void EventClass_Think(RenSharpEventClass* eventClass);
		void EventClass_Object_Created_Event(RenSharpEventClass* eventClass, GameObject *obj);
		bool EventClass_Stock_Client_Damage_Request_Event(RenSharpEventClass* eventClass, DamageableGameObj *Victim, ArmedGameObj *Damager, float Damage, uint Warhead);
		bool EventClass_TT_Client_Damage_Request_Event(RenSharpEventClass* eventClass, DamageableGameObj *Victim, ArmedGameObj *Damager, const AmmoDefinitionClass *Ammo, const char *Bone);
		bool EventClass_Damage_Request_Event(RenSharpEventClass* eventClass, DamageableGameObj *Victim, ArmedGameObj *Damager, float &Damage, unsigned int &Warhead, float Scale, DADamageType::Type Type);
		void EventClass_Damage_Event(RenSharpEventClass* eventClass, DamageableGameObj *Victim, ArmedGameObj *Damager, float Damage, unsigned int Warhead, float Scale, DADamageType::Type Type);
		void EventClass_Kill_Event(RenSharpEventClass* eventClass, DamageableGameObj *Victim, ArmedGameObj *Killer, float Damage, unsigned int Warhead, float Scale, DADamageType::Type Type);
		void EventClass_Custom_Event(RenSharpEventClass* eventClass, GameObject *obj, int Type, int Param, GameObject *Sender);
		void EventClass_Poke_Event(RenSharpEventClass* eventClass, cPlayer *Player, PhysicalGameObj *obj);
		void EventClass_Zone_Enter_Event(RenSharpEventClass* eventClass, ScriptZoneGameObj *obj, PhysicalGameObj *Enterer);
		void EventClass_Zone_Exit_Event(RenSharpEventClass* eventClass, ScriptZoneGameObj *obj, PhysicalGameObj *Exiter);
		void EventClass_Object_Destroyed_Event(RenSharpEventClass* eventClass, GameObject *obj);
		void EventClass_Timer_Expired(RenSharpEventClass* eventClass, int Number, unsigned int Data);

		// RenSharpGameObjObserverClass
		void Observer_Destructed(RenSharpGameObjObserverClass *observer);
		void Observer_Destroyed(RenSharpGameObjObserverClass *observer, GameObject *obj);
		void Observer_Custom(RenSharpGameObjObserverClass *observer, GameObject *obj, int message, int param, GameObject *sender);
		void Observer_Poked(RenSharpGameObjObserverClass *observer, GameObject *obj, GameObject *poker);
		void Observer_Entered(RenSharpGameObjObserverClass *observer, GameObject *obj, GameObject *enterer);
		void Observer_Exited(RenSharpGameObjObserverClass *observer, GameObject *obj, GameObject *exiter);
		void Observer_Sound_Heard(RenSharpGameObjObserverClass *observer, GameObject *obj, const CombatSound &sound);
		void Observer_Enemy_Seen(RenSharpGameObjObserverClass *observer, GameObject *obj, GameObject *enemy);
		void Observer_Action_Complete(RenSharpGameObjObserverClass *observer, GameObject *obj, int actionID, ActionCompleteReason completeReason);
		void Observer_Timer_Expired(RenSharpGameObjObserverClass *observer, GameObject *obj, int number);
		void Observer_Animation_Complete(RenSharpGameObjObserverClass *observer, GameObject *obj, const char *name);
		void Observer_Init(RenSharpGameObjObserverClass *observer);
		bool Observer_Vehicle_Entry_Request(RenSharpGameObjObserverClass *observer, cPlayer *player, int &seat);
		bool Observer_Vehicle_Entry_Request(RenSharpGameObjObserverClass *observer, VehicleGameObj *vehicle, int &seat);
		void Observer_Vehicle_Enter(RenSharpGameObjObserverClass *observer, cPlayer *player, int seat);
		void Observer_Vehicle_Enter(RenSharpGameObjObserverClass *observer, VehicleGameObj *vehicle, int seat);
		void Observer_Vehicle_Exit(RenSharpGameObjObserverClass *observer, cPlayer *player, int seat);
		void Observer_Vehicle_Exit(RenSharpGameObjObserverClass *observer, VehicleGameObj *vehicle, int seat);
		bool Observer_Vehicle_Flip(RenSharpGameObjObserverClass *observer);
		bool Observer_Damage_Dealt_Request(RenSharpGameObjObserverClass *observer, DamageableGameObj *victim, float &damage, unsigned int &warhead, float scale, DADamageType::Type type);
		bool Observer_Damage_Received_Request(RenSharpGameObjObserverClass *observer, ArmedGameObj *damager, float &damage, unsigned int &warhead, float scale, DADamageType::Type type);
		void Observer_Damage_Dealt(RenSharpGameObjObserverClass *observer, DamageableGameObj *victim, float damage, unsigned int warhead, float scale, DADamageType::Type type);
		void Observer_Damage_Received(RenSharpGameObjObserverClass *observer, ArmedGameObj *damager, float damage, unsigned int warhead, float scale, DADamageType::Type type);
		void Observer_Kill_Dealt(RenSharpGameObjObserverClass *observer, DamageableGameObj *victim, float damage, unsigned int warhead, float scale, DADamageType::Type type);
		void Observer_Kill_Received(RenSharpGameObjObserverClass *observer, ArmedGameObj *killer, float damage, unsigned int warhead, float scale, DADamageType::Type type);
		bool Observer_PowerUp_Grant_Request(RenSharpGameObjObserverClass *observer, cPlayer *player);
		bool Observer_PowerUp_Grant_Request(RenSharpGameObjObserverClass *observer, const PowerUpGameObjDef *powerUp, PowerUpGameObj *powerUpObj);
		void Observer_PowerUp_Grant(RenSharpGameObjObserverClass *observer, cPlayer *player);
		void Observer_PowerUp_Grant(RenSharpGameObjObserverClass *observer, const PowerUpGameObjDef *powerUp, PowerUpGameObj *powerUpObj);
		bool Observer_Add_Weapon_Request(RenSharpGameObjObserverClass *observer, const WeaponDefinitionClass *weapon);
		void Observer_Add_Weapon(RenSharpGameObjObserverClass *observer, WeaponClass *weapon);
		void Observer_Remove_Weapon(RenSharpGameObjObserverClass *observer, WeaponClass *weapon);
		void Observer_Clear_Weapons(RenSharpGameObjObserverClass *observer);

		// RenSharpPlayerObserverClass
		void PlayerObserver_Destructed(RenSharpPlayerObserverClass *observer);
		void PlayerObserver_Init(RenSharpPlayerObserverClass *observer);
		void PlayerObserver_Join(RenSharpPlayerObserverClass *observer);
		void PlayerObserver_Leave(RenSharpPlayerObserverClass *observer);
		void PlayerObserver_Level_Loaded(RenSharpPlayerObserverClass *observer);
		void PlayerObserver_Player_Loaded(RenSharpPlayerObserverClass *observer);
		void PlayerObserver_Name_Change(RenSharpPlayerObserverClass *observer);
		void PlayerObserver_Team_Change(RenSharpPlayerObserverClass *observer);
		int PlayerObserver_Character_Purchase_Request(RenSharpPlayerObserverClass *observer, float &cost, const SoldierGameObjDef *item);
		int PlayerObserver_Vehicle_Purchase_Request(RenSharpPlayerObserverClass *observer, float &cost, const VehicleGameObjDef *item);
		int PlayerObserver_PowerUp_Purchase_Request(RenSharpPlayerObserverClass *observer, float &cost, const PowerUpGameObjDef *item);
		int PlayerObserver_Custom_Purchase_Request(RenSharpPlayerObserverClass *observer, float &cost, unsigned int id);
		void PlayerObserver_Character_Purchase(RenSharpPlayerObserverClass *observer, float cost, const SoldierGameObjDef *item);
		void PlayerObserver_Vehicle_Purchase(RenSharpPlayerObserverClass *observer, float cost, const VehicleGameObjDef *item);
		void PlayerObserver_PowerUp_Purchase(RenSharpPlayerObserverClass *observer, float cost, const PowerUpGameObjDef *item);
		void PlayerObserver_Custom_Purchase(RenSharpPlayerObserverClass *observer, float cost, unsigned int id);
		bool PlayerObserver_Vehicle_Entry_Request(RenSharpPlayerObserverClass *observer, VehicleGameObj *vehicle, int &seat);
		void PlayerObserver_Vehicle_Enter(RenSharpPlayerObserverClass *observer, VehicleGameObj *vehicle, int seat);
		void PlayerObserver_Vehicle_Exit(RenSharpPlayerObserverClass *observer, VehicleGameObj *vehicle, int seat);
		bool PlayerObserver_PowerUp_Grant_Request(RenSharpPlayerObserverClass *observer, const PowerUpGameObjDef *powerUp, PowerUpGameObj *powerUpObj);
		void PlayerObserver_PowerUp_Grant(RenSharpPlayerObserverClass *observer, const PowerUpGameObjDef *powerUp, PowerUpGameObj *powerUpObj);
		bool PlayerObserver_Add_Weapon_Request(RenSharpPlayerObserverClass *observer, const WeaponDefinitionClass *weapon);
		void PlayerObserver_Add_Weapon(RenSharpPlayerObserverClass *observer, WeaponClass *weapon);
		void PlayerObserver_Remove_Weapon(RenSharpPlayerObserverClass *observer, WeaponClass *weapon);
		void PlayerObserver_Clear_Weapons(RenSharpPlayerObserverClass *observer);
		bool PlayerObserver_C4_Detonate_Request(RenSharpPlayerObserverClass *observer, C4GameObj *c4);
		void PlayerObserver_C4_Detonate(RenSharpPlayerObserverClass *observer, C4GameObj *c4);
		void PlayerObserver_Change_Character(RenSharpPlayerObserverClass *observer, const SoldierGameObjDef *soldier);
		void PlayerObserver_Created(RenSharpPlayerObserverClass *observer);
		void PlayerObserver_Destroyed(RenSharpPlayerObserverClass *observer);
		bool PlayerObserver_Damage_Dealt_Request(RenSharpPlayerObserverClass *observer, DamageableGameObj *victim, float &damage, unsigned int &warhead, float scale, DADamageType::Type type);
		bool PlayerObserver_Damage_Received_Request(RenSharpPlayerObserverClass *observer, ArmedGameObj *damager, float &damage, unsigned int &warhead, float scale, DADamageType::Type type);
		void PlayerObserver_Damage_Dealt(RenSharpPlayerObserverClass *observer, DamageableGameObj *victim, float damage, unsigned int warhead, float scale, DADamageType::Type type);
		void PlayerObserver_Damage_Received(RenSharpPlayerObserverClass *observer, ArmedGameObj *damager, float damage, unsigned int warhead, float scale, DADamageType::Type type);
		void PlayerObserver_Kill_Dealt(RenSharpPlayerObserverClass *observer, DamageableGameObj *victim, float damage, unsigned int warhead, float scale, DADamageType::Type type);
		void PlayerObserver_Kill_Received(RenSharpPlayerObserverClass *observer, ArmedGameObj *killer, float damage, unsigned int warhead, float scale, DADamageType::Type type);
		void PlayerObserver_Custom(RenSharpPlayerObserverClass *observer, GameObject *sender, int type, int param);
		void PlayerObserver_Poked(RenSharpPlayerObserverClass *observer, cPlayer *player);
		void PlayerObserver_Timer_Expired(RenSharpPlayerObserverClass *observer, int number, unsigned int data);
		void PlayerObserver_Think(RenSharpPlayerObserverClass *observer);

		// RenSharpConsoleFunctionClass
		void ConsoleFunction_Destructed(RenSharpConsoleFunctionClass *function);
		void ConsoleFunction_Activate(RenSharpConsoleFunctionClass *function, const char *pArgs);

		// RenSharpGameFeatureFactoryClass
		void GameFeatureFactory_Destructed(RenSharpGameFeatureFactoryClass* factory);
		DAGameFeatureClass *GameFeatureFactory_Create_Instance(RenSharpGameFeatureFactoryClass* factory);

		// RenSharpGameFeatureClass
		void GameFeature_Destructed(RenSharpGameFeatureClass* gameFeature);
		void GameFeature_Init(RenSharpGameFeatureClass* gameFeature);

		// RenSharpPlayerDataFactoryClass
		void PlayerDataFactory_Destructed(RenSharpPlayerDataFactoryClass* playerDataFactory);
		DAPlayerDataClass* PlayerDataFactory_Create_Data(RenSharpPlayerDataFactoryClass* playerDataFactory);

		// RenSharpPlayerDataClass
		void PlayerData_Destructed(RenSharpPlayerDataClass* playerData);
		void PlayerData_Init(RenSharpPlayerDataClass* playerData);
		void PlayerData_Clear_Level(RenSharpPlayerDataClass* playerData);
		void PlayerData_Clear_Session(RenSharpPlayerDataClass* playerData);

		// RenSharpGameModeFactoryClass
		void GameModeFactory_Destructed(RenSharpGameModeFactoryClass* factory);
		DAGameModeClass* GameModeFactory_Create_Instance(RenSharpGameModeFactoryClass* factory);

		// RenSharpGameModeClass
		void GameMode_Destructed(RenSharpGameModeClass* gameMode);
		void GameMode_Init(RenSharpGameModeClass* gameMode);

		// RenSharpCrateModifierFactoryClass
		void CrateModifierFactory_Destructed(RenSharpCrateModifierFactoryClass* factory);
		DACrateModifierClass* CrateModifierFactory_Create(RenSharpCrateModifierFactoryClass* factory, const char* parameters);

		// RenSharpCrateModifierClass
		void CrateModifier_Destructed(RenSharpCrateModifierClass* crateModifier);
		void CrateModifier_Init(RenSharpCrateModifierClass* crateModifier, const char* parameters);
		void CrateModifier_Calculate_Odds(RenSharpCrateModifierClass* crateModifier, float& odds, cPlayer* player);

		// RenSharpCrateClass
		void Crate_Destructed(RenSharpCrateClass* crate);
		void Crate_Init(RenSharpCrateClass* crate);
		void Crate_Settings_Loaded(RenSharpCrateClass* crate);
		void Crate_Calculate_Odds(RenSharpCrateClass* crate, cPlayer* player);
		bool Crate_Can_Activate(RenSharpCrateClass* crate, cPlayer* player);
		void Crate_Activate(RenSharpCrateClass* crate, cPlayer* player);

		// RenSharpCrateFactoryClass
		void CrateFactory_Destructed(RenSharpCrateFactoryClass* factory);
		DACrateClass* CrateFactory_Create_Instance(RenSharpCrateFactoryClass* factory);

		// RenSharpNodeClass
		void Node_Destructed(RenSharpNodeClass* node);
		void Node_Init(RenSharpNodeClass* node, const INIClass* ini, const StringClass& header);
		void Node_Contested_Event(RenSharpNodeClass* node);
		void Node_Capture_Event(RenSharpNodeClass* node);

		static RenSharpRootEventClass& Get_Instance();

	private:
		void Dump_Exception(const char *exception);
};