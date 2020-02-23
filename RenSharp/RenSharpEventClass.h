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

#include <da_event.h>

class RenSharpEventClass : public DAEventClass
{
	public:
		RenSharpEventClass();
		virtual ~RenSharpEventClass();

		virtual void Settings_Loaded_Event();
		virtual bool Chat_Event(cPlayer* Player, TextMessageEnum Type, const wchar_t* Message, int ReceiverID);
		virtual bool Chat_Command_Event(cPlayer* Player, TextMessageEnum Type, const StringClass& Command, const DATokenClass& Text, int ReceiverID);
		virtual bool Key_Hook_Event(cPlayer* Player, const StringClass& Key);
		virtual bool Host_Chat_Event(int ID, TextMessageEnum Type, const char* Message);
		virtual bool Radio_Event(cPlayer* Player, int PlayerType, int AnnouncementID, int IconID, AnnouncementEnum AnnouncementType);
		virtual ConnectionAcceptanceFilter::STATUS Connection_Request_Event(ConnectionRequest& Request, WideStringClass& RefusalMessage);
		virtual void Player_Pre_Join_Event(ConnectionRequest& Request);
		virtual void Player_Join_Event(cPlayer* Player);
		virtual void Player_Leave_Event(cPlayer* Player);
		virtual void Player_Loaded_Event(cPlayer* Player);
		virtual void Name_Change_Event(cPlayer* Player);
		virtual void Level_Loaded_Event();
		virtual void Remix_Event();
		virtual void Rebalance_Event();
		virtual void Swap_Event();
		virtual void Game_Over_Event();
		virtual void Console_Output_Event(const char* Output);
		virtual void Ren_Log_Event(const char* Output);
		virtual void DA_Log_Event(const char* Header, const char* Output);
		virtual int Character_Purchase_Request_Event(BaseControllerClass* Base, cPlayer* Player, float& Cost, const SoldierGameObjDef* Item);
		virtual int Vehicle_Purchase_Request_Event(BaseControllerClass* Base, cPlayer* Player, float& Cost, const VehicleGameObjDef* Item);
		virtual int PowerUp_Purchase_Request_Event(BaseControllerClass* Base, cPlayer* Player, float& Cost, const PowerUpGameObjDef* Item);
		virtual int Custom_Purchase_Request_Event(BaseControllerClass* Base, cPlayer* Player, float& Cost, unsigned int ID);
		virtual void Character_Purchase_Event(cPlayer* Player, float Cost, const SoldierGameObjDef* Item);
		virtual void Vehicle_Purchase_Event(cPlayer* Player, float Cost, const VehicleGameObjDef* Item);
		virtual void PowerUp_Purchase_Event(cPlayer* Player, float Cost, const PowerUpGameObjDef* Item);
		virtual void Custom_Purchase_Event(cPlayer* Player, float Cost, unsigned int ID);
		virtual bool Refill_Event(cPlayer* Player);
		virtual bool Suicide_Event(cPlayer* Player);
		virtual bool Team_Change_Request_Event(cPlayer* Player);
		virtual void Team_Change_Event(cPlayer* Player);
		virtual bool Vehicle_Entry_Request_Event(VehicleGameObj* Vehicle, cPlayer* Player, int& Seat);
		virtual void Vehicle_Enter_Event(VehicleGameObj* Vehicle, cPlayer* Player, int Seat);
		virtual void Vehicle_Exit_Event(VehicleGameObj* Vehicle, cPlayer* Player, int Seat);
		virtual bool PowerUp_Grant_Request_Event(cPlayer* Player, const PowerUpGameObjDef* PowerUp, PowerUpGameObj* PowerUpObj);
		virtual void PowerUp_Grant_Event(cPlayer* Player, const PowerUpGameObjDef* PowerUp, PowerUpGameObj* PowerUpObj);
		virtual bool Add_Weapon_Request_Event(cPlayer* Player, const WeaponDefinitionClass* Weapon);
		virtual void Add_Weapon_Event(cPlayer* Player, WeaponClass* Weapon);
		virtual void Remove_Weapon_Event(cPlayer* Player, WeaponClass* Weapon);
		virtual void Clear_Weapons_Event(cPlayer* Player);
		virtual void Beacon_Deploy_Event(BeaconGameObj* Beacon);
		virtual void Beacon_Detonate_Event(BeaconGameObj* Beacon);
		virtual bool C4_Detonate_Request_Event(C4GameObj* C4, SmartGameObj* Triggerer);
		virtual void C4_Detonate_Event(C4GameObj* C4);
		virtual void Change_Character_Event(cPlayer* Player, const SoldierGameObjDef* Soldier);
		virtual bool Vehicle_Flip_Event(VehicleGameObj* Vehicle);
		virtual bool Request_Vehicle_Event(VehicleFactoryGameObj* Factory, const VehicleGameObjDef* Vehicle, cPlayer* Player, float Delay);
		virtual void Think();
		virtual void Object_Created_Event(GameObject* obj);
		virtual bool Stock_Client_Damage_Request_Event(DamageableGameObj* Victim, ArmedGameObj* Damager, float Damage, uint Warhead);
		virtual bool TT_Client_Damage_Request_Event(DamageableGameObj* Victim, ArmedGameObj* Damager, const AmmoDefinitionClass* Ammo, const char* Bone);
		virtual bool Damage_Request_Event(DamageableGameObj* Victim, ArmedGameObj* Damager, float& Damage, unsigned int& Warhead, float Scale, DADamageType::Type Type);
		virtual void Damage_Event(DamageableGameObj* Victim, ArmedGameObj* Damager, float Damage, unsigned int Warhead, float Scale, DADamageType::Type Type);
		virtual void Kill_Event(DamageableGameObj* Victim, ArmedGameObj* Killer, float Damage, unsigned int Warhead, float Scale, DADamageType::Type Type);
		virtual void Custom_Event(GameObject* obj, int Type, int Param, GameObject* Sender);
		virtual void Poke_Event(cPlayer* Player, PhysicalGameObj* obj);
		virtual void Zone_Enter_Event(ScriptZoneGameObj* obj, PhysicalGameObj* Enterer);
		virtual void Zone_Exit_Event(ScriptZoneGameObj* obj, PhysicalGameObj* Exiter);
		virtual void Object_Destroyed_Event(GameObject* obj);
		virtual void Timer_Expired(int Number, unsigned int Data);
};