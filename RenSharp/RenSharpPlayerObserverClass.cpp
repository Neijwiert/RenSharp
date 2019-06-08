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
#include "RenSharpPlayerObserverClass.h"

#include "RenSharp.h"

RenSharpPlayerObserverClass::RenSharpPlayerObserverClass(const char *name)
	: name(name)
{

}

RenSharpPlayerObserverClass::~RenSharpPlayerObserverClass()
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Destructed(this);
}

const char *RenSharpPlayerObserverClass::Get_Observer_Name()
{
	return name.Peek_Buffer();
}

void RenSharpPlayerObserverClass::Init()
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Init(this);
}

void RenSharpPlayerObserverClass::Join()
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Join(this);
}

void RenSharpPlayerObserverClass::Leave()
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Leave(this);
}

void RenSharpPlayerObserverClass::Level_Loaded()
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Level_Loaded(this);
}

void RenSharpPlayerObserverClass::Player_Loaded()
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Player_Loaded(this);
}

void RenSharpPlayerObserverClass::Name_Change()
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Name_Change(this);
}

void RenSharpPlayerObserverClass::Team_Change()
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Team_Change(this);
}

int RenSharpPlayerObserverClass::Character_Purchase_Request(float &cost, const SoldierGameObjDef *item)
{
	return RenSharpRootEventClass::Get_Instance().PlayerObserver_Character_Purchase_Request(this, cost, item);
}

int RenSharpPlayerObserverClass::Vehicle_Purchase_Request(float &cost, const VehicleGameObjDef *item)
{
	return RenSharpRootEventClass::Get_Instance().PlayerObserver_Vehicle_Purchase_Request(this, cost, item);
}

int RenSharpPlayerObserverClass::PowerUp_Purchase_Request(float &cost, const PowerUpGameObjDef *item)
{
	return RenSharpRootEventClass::Get_Instance().PlayerObserver_PowerUp_Purchase_Request(this, cost, item);
}

int RenSharpPlayerObserverClass::Custom_Purchase_Request(float &cost, unsigned int id)
{
	return RenSharpRootEventClass::Get_Instance().PlayerObserver_Custom_Purchase_Request(this, cost, id);
}

void RenSharpPlayerObserverClass::Character_Purchase(float cost, const SoldierGameObjDef *item)
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Character_Purchase(this, cost, item);
}

void RenSharpPlayerObserverClass::Vehicle_Purchase(float cost, const VehicleGameObjDef *item)
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Vehicle_Purchase(this, cost, item);
}

void RenSharpPlayerObserverClass::PowerUp_Purchase(float cost, const PowerUpGameObjDef *item)
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_PowerUp_Purchase(this, cost, item);
}

void RenSharpPlayerObserverClass::Custom_Purchase(float cost, unsigned int id)
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Custom_Purchase(this, cost, id);
}

bool RenSharpPlayerObserverClass::Vehicle_Entry_Request(VehicleGameObj *vehicle, int &seat)
{
	return RenSharpRootEventClass::Get_Instance().PlayerObserver_Vehicle_Entry_Request(this, vehicle, seat);
}

void RenSharpPlayerObserverClass::Vehicle_Enter(VehicleGameObj *vehicle, int seat)
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Vehicle_Enter(this, vehicle, seat);
}

void RenSharpPlayerObserverClass::Vehicle_Exit(VehicleGameObj *vehicle, int seat)
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Vehicle_Exit(this, vehicle, seat);
}

bool RenSharpPlayerObserverClass::PowerUp_Grant_Request(const PowerUpGameObjDef *powerUp, PowerUpGameObj *powerUpObj)
{
	return RenSharpRootEventClass::Get_Instance().PlayerObserver_PowerUp_Grant_Request(this, powerUp, powerUpObj);
}

void RenSharpPlayerObserverClass::PowerUp_Grant(const PowerUpGameObjDef *powerUp, PowerUpGameObj *powerUpObj)
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_PowerUp_Grant(this, powerUp, powerUpObj);
}

bool RenSharpPlayerObserverClass::Add_Weapon_Request(const WeaponDefinitionClass *weapon)
{
	return RenSharpRootEventClass::Get_Instance().PlayerObserver_Add_Weapon_Request(this, weapon);
}

void RenSharpPlayerObserverClass::Add_Weapon(WeaponClass *weapon)
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Add_Weapon(this, weapon);
}

void RenSharpPlayerObserverClass::Remove_Weapon(WeaponClass *weapon)
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Remove_Weapon(this, weapon);
}

void RenSharpPlayerObserverClass::Clear_Weapons()
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Clear_Weapons(this);
}

bool RenSharpPlayerObserverClass::C4_Detonate_Request(C4GameObj *c4)
{
	return RenSharpRootEventClass::Get_Instance().PlayerObserver_C4_Detonate_Request(this, c4);
}

void RenSharpPlayerObserverClass::C4_Detonate(C4GameObj *c4)
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_C4_Detonate(this, c4);
}

void RenSharpPlayerObserverClass::Change_Character(const SoldierGameObjDef *soldier)
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Change_Character(this, soldier);
}

void RenSharpPlayerObserverClass::Created()
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Created(this);
}

void RenSharpPlayerObserverClass::Destroyed()
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Destroyed(this);
}

bool RenSharpPlayerObserverClass::Damage_Dealt_Request(DamageableGameObj *victim, float &damage, unsigned int &warhead, float scale, DADamageType::Type type)
{
	return RenSharpRootEventClass::Get_Instance().PlayerObserver_Damage_Dealt_Request(this, victim, damage, warhead, scale, type);
}

bool RenSharpPlayerObserverClass::Damage_Received_Request(ArmedGameObj *damager, float &damage, unsigned int &warhead, float scale, DADamageType::Type type)
{
	return RenSharpRootEventClass::Get_Instance().PlayerObserver_Damage_Received_Request(this, damager, damage, warhead, scale, type);
}

void RenSharpPlayerObserverClass::Damage_Dealt(DamageableGameObj *victim, float damage, unsigned int warhead, float scale, DADamageType::Type type)
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Damage_Dealt(this, victim, damage, warhead, scale, type);
}

void RenSharpPlayerObserverClass::Damage_Received(ArmedGameObj *damager, float damage, unsigned int warhead, float scale, DADamageType::Type type)
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Damage_Received(this, damager, damage, warhead, scale, type);
}

void RenSharpPlayerObserverClass::Kill_Dealt(DamageableGameObj *victim, float damage, unsigned int warhead, float scale, DADamageType::Type type)
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Kill_Dealt(this, victim, damage, warhead, scale, type);
}

void RenSharpPlayerObserverClass::Kill_Received(ArmedGameObj *killer, float damage, unsigned int warhead, float scale, DADamageType::Type type)
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Kill_Received(this, killer, damage, warhead, scale, type);
}

void RenSharpPlayerObserverClass::Custom(GameObject *sender, int type, int param)
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Custom(this, sender, type, param);
}

void RenSharpPlayerObserverClass::Poked(cPlayer *player)
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Poked(this, player);
}

void RenSharpPlayerObserverClass::Timer_Expired(int number, unsigned int data)
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Timer_Expired(this, number, data);
}

void RenSharpPlayerObserverClass::Think()
{
	RenSharpRootEventClass::Get_Instance().PlayerObserver_Think(this);
}