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

#include "General.h"
#include <engine.h>
#include <engine_da.h>
#include <da.h>
#include "RenSharpEventClass.h"
#include "RenSharp.h"

RenSharpEventClass::RenSharpEventClass()
{

}

RenSharpEventClass::~RenSharpEventClass()
{
	RenSharpRootEventClass::Get_Instance().EventClass_Destructed(this);
}

void RenSharpEventClass::Settings_Loaded_Event()
{
	RenSharpRootEventClass::Get_Instance().EventClass_Settings_Loaded_Event(this);
}

bool RenSharpEventClass::Chat_Event(cPlayer* Player, TextMessageEnum Type, const wchar_t* Message, int ReceiverID)
{
	return RenSharpRootEventClass::Get_Instance().EventClass_Chat_Event(this, Player, Type, Message, ReceiverID);
}

bool RenSharpEventClass::Chat_Command_Event(cPlayer * Player, TextMessageEnum Type, const StringClass & Command, const DATokenClass & Text, int ReceiverID)
{
	return RenSharpRootEventClass::Get_Instance().EventClass_Chat_Command_Event(this, Player, Type, Command, Text, ReceiverID);
}

bool RenSharpEventClass::Key_Hook_Event(cPlayer * Player, const StringClass & Key)
{
	return RenSharpRootEventClass::Get_Instance().EventClass_Key_Hook_Event(this, Player, Key);
}

bool RenSharpEventClass::Host_Chat_Event(int ID, TextMessageEnum Type, const char* Message)
{
	return RenSharpRootEventClass::Get_Instance().EventClass_Host_Chat_Event(this, ID, Type, Message);
}

bool RenSharpEventClass::Radio_Event(cPlayer * Player, int PlayerType, int AnnouncementID, int IconID, AnnouncementEnum AnnouncementType)
{
	return RenSharpRootEventClass::Get_Instance().EventClass_Radio_Event(this, Player, PlayerType, AnnouncementID, IconID, AnnouncementType);
}

ConnectionAcceptanceFilter::STATUS RenSharpEventClass::Connection_Request_Event(ConnectionRequest & Request, WideStringClass & RefusalMessage)
{
	return RenSharpRootEventClass::Get_Instance().EventClass_Connection_Request_Event(this, Request, RefusalMessage);
}

void RenSharpEventClass::Player_Pre_Join_Event(ConnectionRequest & Request)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Player_Pre_Join_Event(this, Request);
}

void RenSharpEventClass::Player_Join_Event(cPlayer * Player)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Player_Join_Event(this, Player);
}

void RenSharpEventClass::Player_Leave_Event(cPlayer * Player)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Player_Leave_Event(this, Player);
}

void RenSharpEventClass::Player_Loaded_Event(cPlayer * Player)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Player_Loaded_Event(this, Player);
}

void RenSharpEventClass::Name_Change_Event(cPlayer * Player)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Name_Change_Event(this, Player);
}

void RenSharpEventClass::Level_Loaded_Event()
{
	RenSharpRootEventClass::Get_Instance().EventClass_Level_Loaded_Event(this);
}

void RenSharpEventClass::Remix_Event()
{
	RenSharpRootEventClass::Get_Instance().EventClass_Remix_Event(this);
}

void RenSharpEventClass::Rebalance_Event()
{
	RenSharpRootEventClass::Get_Instance().EventClass_Rebalance_Event(this);
}

void RenSharpEventClass::Swap_Event()
{
	RenSharpRootEventClass::Get_Instance().EventClass_Swap_Event(this);
}

void RenSharpEventClass::Game_Over_Event()
{
	RenSharpRootEventClass::Get_Instance().EventClass_Game_Over_Event(this);
}

void RenSharpEventClass::Console_Output_Event(const char* Output)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Console_Output_Event(this, Output);
}

void RenSharpEventClass::Ren_Log_Event(const char* Output)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Ren_Log_Event(this, Output);
}

void RenSharpEventClass::DA_Log_Event(const char* Header, const char* Output)
{
	RenSharpRootEventClass::Get_Instance().EventClass_DA_Log_Event(this, Header, Output);
}

int RenSharpEventClass::Character_Purchase_Request_Event(BaseControllerClass * Base, cPlayer * Player, float& Cost, const SoldierGameObjDef * Item)
{
	return RenSharpRootEventClass::Get_Instance().EventClass_Character_Purchase_Request_Event(this, Base, Player, Cost, Item);
}

int RenSharpEventClass::Vehicle_Purchase_Request_Event(BaseControllerClass * Base, cPlayer * Player, float& Cost, const VehicleGameObjDef * Item)
{
	return RenSharpRootEventClass::Get_Instance().EventClass_Vehicle_Purchase_Request_Event(this, Base, Player, Cost, Item);
}

int RenSharpEventClass::PowerUp_Purchase_Request_Event(BaseControllerClass * Base, cPlayer * Player, float& Cost, const PowerUpGameObjDef * Item)
{
	return RenSharpRootEventClass::Get_Instance().EventClass_PowerUp_Purchase_Request_Event(this, Base, Player, Cost, Item);
}

int RenSharpEventClass::Custom_Purchase_Request_Event(BaseControllerClass * Base, cPlayer * Player, float& Cost, unsigned int ID)
{
	return RenSharpRootEventClass::Get_Instance().EventClass_Custom_Purchase_Request_Event(this, Base, Player, Cost, ID);
}

void RenSharpEventClass::Character_Purchase_Event(cPlayer * Player, float Cost, const SoldierGameObjDef * Item)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Character_Purchase_Event(this, Player, Cost, Item);
}

void RenSharpEventClass::Vehicle_Purchase_Event(cPlayer * Player, float Cost, const VehicleGameObjDef * Item)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Vehicle_Purchase_Event(this, Player, Cost, Item);
}

void RenSharpEventClass::PowerUp_Purchase_Event(cPlayer * Player, float Cost, const PowerUpGameObjDef * Item)
{
	RenSharpRootEventClass::Get_Instance().EventClass_PowerUp_Purchase_Event(this, Player, Cost, Item);
}

void RenSharpEventClass::Custom_Purchase_Event(cPlayer * Player, float Cost, unsigned int ID)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Custom_Purchase_Event(this, Player, Cost, ID);
}

bool RenSharpEventClass::Refill_Event(cPlayer * Player)
{
	return RenSharpRootEventClass::Get_Instance().EventClass_Refill_Event(this, Player);
}

bool RenSharpEventClass::Suicide_Event(cPlayer * Player)
{
	return RenSharpRootEventClass::Get_Instance().EventClass_Suicide_Event(this, Player);
}

bool RenSharpEventClass::Team_Change_Request_Event(cPlayer * Player)
{
	return RenSharpRootEventClass::Get_Instance().EventClass_Team_Change_Request_Event(this, Player);
}

void RenSharpEventClass::Team_Change_Event(cPlayer * Player)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Team_Change_Event(this, Player);
}

bool RenSharpEventClass::Vehicle_Entry_Request_Event(VehicleGameObj * Vehicle, cPlayer * Player, int& Seat)
{
	return RenSharpRootEventClass::Get_Instance().EventClass_Vehicle_Entry_Request_Event(this, Vehicle, Player, Seat);
}

void RenSharpEventClass::Vehicle_Enter_Event(VehicleGameObj * Vehicle, cPlayer * Player, int Seat)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Vehicle_Enter_Event(this, Vehicle, Player, Seat);
}

void RenSharpEventClass::Vehicle_Exit_Event(VehicleGameObj * Vehicle, cPlayer * Player, int Seat)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Vehicle_Exit_Event(this, Vehicle, Player, Seat);
}

bool RenSharpEventClass::PowerUp_Grant_Request_Event(cPlayer * Player, const PowerUpGameObjDef * PowerUp, PowerUpGameObj * PowerUpObj)
{
	return RenSharpRootEventClass::Get_Instance().EventClass_PowerUp_Grant_Request_Event(this, Player, PowerUp, PowerUpObj);
}

void RenSharpEventClass::PowerUp_Grant_Event(cPlayer * Player, const PowerUpGameObjDef * PowerUp, PowerUpGameObj * PowerUpObj)
{
	RenSharpRootEventClass::Get_Instance().EventClass_PowerUp_Grant_Event(this, Player, PowerUp, PowerUpObj);
}

bool RenSharpEventClass::Add_Weapon_Request_Event(cPlayer * Player, const WeaponDefinitionClass * Weapon)
{
	return RenSharpRootEventClass::Get_Instance().EventClass_Add_Weapon_Request_Event(this, Player, Weapon);
}

void RenSharpEventClass::Add_Weapon_Event(cPlayer * Player, WeaponClass * Weapon)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Add_Weapon_Event(this, Player, Weapon);
}

void RenSharpEventClass::Remove_Weapon_Event(cPlayer * Player, WeaponClass * Weapon)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Remove_Weapon_Event(this, Player, Weapon);
}

void RenSharpEventClass::Clear_Weapons_Event(cPlayer * Player)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Clear_Weapons_Event(this, Player);
}

void RenSharpEventClass::Beacon_Deploy_Event(BeaconGameObj * Beacon)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Beacon_Deploy_Event(this, Beacon);
}

void RenSharpEventClass::Beacon_Detonate_Event(BeaconGameObj * Beacon)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Beacon_Detonate_Event(this, Beacon);
}

bool RenSharpEventClass::C4_Detonate_Request_Event(C4GameObj * C4, SmartGameObj * Triggerer)
{
	return RenSharpRootEventClass::Get_Instance().EventClass_C4_Detonate_Request_Event(this, C4, Triggerer);
}

void RenSharpEventClass::C4_Detonate_Event(C4GameObj * C4)
{
	RenSharpRootEventClass::Get_Instance().EventClass_C4_Detonate_Event(this, C4);
}

void RenSharpEventClass::Change_Character_Event(cPlayer * Player, const SoldierGameObjDef * Soldier)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Change_Character_Event(this, Player, Soldier);
}

bool RenSharpEventClass::Vehicle_Flip_Event(VehicleGameObj * Vehicle)
{
	return RenSharpRootEventClass::Get_Instance().EventClass_Vehicle_Flip_Event(this, Vehicle);
}

bool RenSharpEventClass::Request_Vehicle_Event(VehicleFactoryGameObj * Factory, const VehicleGameObjDef * Vehicle, cPlayer * Player, float Delay)
{
	return RenSharpRootEventClass::Get_Instance().EventClass_Request_Vehicle_Event(this, Factory, Vehicle, Player, Delay);
}

void RenSharpEventClass::Think()
{
	RenSharpRootEventClass::Get_Instance().EventClass_Think(this);
}

void RenSharpEventClass::Object_Created_Event(GameObject * obj)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Object_Created_Event(this, obj);
}

bool RenSharpEventClass::Stock_Client_Damage_Request_Event(DamageableGameObj * Victim, ArmedGameObj * Damager, float Damage, uint Warhead)
{
	return RenSharpRootEventClass::Get_Instance().EventClass_Stock_Client_Damage_Request_Event(this, Victim, Damager, Damage, Warhead);
}

bool RenSharpEventClass::TT_Client_Damage_Request_Event(DamageableGameObj * Victim, ArmedGameObj * Damager, const AmmoDefinitionClass * Ammo, const char* Bone)
{
	return RenSharpRootEventClass::Get_Instance().EventClass_TT_Client_Damage_Request_Event(this, Victim, Damager, Ammo, Bone);
}

bool RenSharpEventClass::Damage_Request_Event(DamageableGameObj * Victim, ArmedGameObj * Damager, float& Damage, unsigned int& Warhead, float Scale, DADamageType::Type Type)
{
	return RenSharpRootEventClass::Get_Instance().EventClass_Damage_Request_Event(this, Victim, Damager, Damage, Warhead, Scale, Type);
}

void RenSharpEventClass::Damage_Event(DamageableGameObj * Victim, ArmedGameObj * Damager, float Damage, unsigned int Warhead, float Scale, DADamageType::Type Type)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Damage_Event(this, Victim, Damager, Damage, Warhead, Scale, Type);
}

void RenSharpEventClass::Kill_Event(DamageableGameObj * Victim, ArmedGameObj * Killer, float Damage, unsigned int Warhead, float Scale, DADamageType::Type Type)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Kill_Event(this, Victim, Killer, Damage, Warhead, Scale, Type);
}

void RenSharpEventClass::Custom_Event(GameObject * obj, int Type, int Param, GameObject * Sender)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Custom_Event(this, obj, Type, Param, Sender);
}

void RenSharpEventClass::Poke_Event(cPlayer * Player, PhysicalGameObj * obj)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Poke_Event(this, Player, obj);
}

void RenSharpEventClass::Zone_Enter_Event(ScriptZoneGameObj * obj, PhysicalGameObj * Enterer)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Zone_Enter_Event(this, obj, Enterer);
}

void RenSharpEventClass::Zone_Exit_Event(ScriptZoneGameObj * obj, PhysicalGameObj * Exiter)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Zone_Exit_Event(this, obj, Exiter);
}

void RenSharpEventClass::Object_Destroyed_Event(GameObject * obj)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Object_Destroyed_Event(this, obj);
}

void RenSharpEventClass::Timer_Expired(int Number, unsigned int Data)
{
	RenSharpRootEventClass::Get_Instance().EventClass_Timer_Expired(this, Number, Data);
}