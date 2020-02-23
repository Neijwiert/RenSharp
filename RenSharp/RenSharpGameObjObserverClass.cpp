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

#include "General.h"
#include "RenSharpGameObjObserverClass.h"

#include "RenSharp.h"

RenSharpGameObjObserverClass::RenSharpGameObjObserverClass(const char *name)
	: name(name)
{

}

RenSharpGameObjObserverClass::~RenSharpGameObjObserverClass()
{
	RenSharpRootEventClass::Get_Instance().Observer_Destructed(this);
}

void RenSharpGameObjObserverClass::Destroyed(GameObject *obj)
{
	RenSharpRootEventClass::Get_Instance().Observer_Destroyed(this, obj);
}

void RenSharpGameObjObserverClass::Custom(GameObject *obj, int message, int param, GameObject *sender)
{
	RenSharpRootEventClass::Get_Instance().Observer_Custom(this, obj, message, param, sender);
}

void RenSharpGameObjObserverClass::Poked(GameObject *obj, GameObject *poker)
{
	RenSharpRootEventClass::Get_Instance().Observer_Poked(this, obj, poker);
}

void RenSharpGameObjObserverClass::Entered(GameObject *obj, GameObject *enterer)
{
	RenSharpRootEventClass::Get_Instance().Observer_Entered(this, obj, enterer);
}

void RenSharpGameObjObserverClass::Exited(GameObject *obj, GameObject *exiter)
{
	RenSharpRootEventClass::Get_Instance().Observer_Exited(this, obj, exiter);
}

const char *RenSharpGameObjObserverClass::Get_Name()
{
	return name.Peek_Buffer();
}

void RenSharpGameObjObserverClass::Sound_Heard(GameObject *obj, const CombatSound &sound)
{
	RenSharpRootEventClass::Get_Instance().Observer_Sound_Heard(this, obj, sound);
}

void RenSharpGameObjObserverClass::Enemy_Seen(GameObject *obj, GameObject *enemy)
{
	RenSharpRootEventClass::Get_Instance().Observer_Enemy_Seen(this, obj, enemy);
}

void RenSharpGameObjObserverClass::Action_Complete(GameObject *obj, int actionID, ActionCompleteReason completeReason)
{
	RenSharpRootEventClass::Get_Instance().Observer_Action_Complete(this, obj, actionID, completeReason);
}

void RenSharpGameObjObserverClass::Timer_Expired(GameObject *obj, int number)
{
	RenSharpRootEventClass::Get_Instance().Observer_Timer_Expired(this, obj, number);
}

void RenSharpGameObjObserverClass::Animation_Complete(GameObject *obj, const char *name)
{
	RenSharpRootEventClass::Get_Instance().Observer_Animation_Complete(this, obj, name);
}

void RenSharpGameObjObserverClass::Init()
{
	RenSharpRootEventClass::Get_Instance().Observer_Init(this);
}

bool RenSharpGameObjObserverClass::Vehicle_Entry_Request(cPlayer *player, int &seat)
{
	return RenSharpRootEventClass::Get_Instance().Observer_Vehicle_Entry_Request(this, player, seat);
}

bool RenSharpGameObjObserverClass::Vehicle_Entry_Request(VehicleGameObj *vehicle, int &seat)
{
	return RenSharpRootEventClass::Get_Instance().Observer_Vehicle_Entry_Request(this, vehicle, seat);
}

void RenSharpGameObjObserverClass::Vehicle_Enter(cPlayer *player, int seat)
{
	RenSharpRootEventClass::Get_Instance().Observer_Vehicle_Enter(this, player, seat);
}

void RenSharpGameObjObserverClass::Vehicle_Enter(VehicleGameObj *vehicle, int seat)
{
	RenSharpRootEventClass::Get_Instance().Observer_Vehicle_Enter(this, vehicle, seat);
}

void RenSharpGameObjObserverClass::Vehicle_Exit(cPlayer *player, int seat)
{
	RenSharpRootEventClass::Get_Instance().Observer_Vehicle_Exit(this, player, seat);
}

void RenSharpGameObjObserverClass::Vehicle_Exit(VehicleGameObj *vehicle, int seat)
{
	RenSharpRootEventClass::Get_Instance().Observer_Vehicle_Exit(this, vehicle, seat);
}

bool RenSharpGameObjObserverClass::Vehicle_Flip()
{
	return RenSharpRootEventClass::Get_Instance().Observer_Vehicle_Flip(this);
}

bool RenSharpGameObjObserverClass::Damage_Dealt_Request(DamageableGameObj *victim, float &damage, unsigned int &warhead, float scale, DADamageType::Type type)
{
	return RenSharpRootEventClass::Get_Instance().Observer_Damage_Dealt_Request(this, victim, damage, warhead, scale, type);
}

bool RenSharpGameObjObserverClass::Damage_Received_Request(ArmedGameObj *damager, float &damage, unsigned int &warhead, float scale, DADamageType::Type type)
{
	return RenSharpRootEventClass::Get_Instance().Observer_Damage_Received_Request(this, damager, damage, warhead, scale, type);
}

void RenSharpGameObjObserverClass::Damage_Dealt(DamageableGameObj *victim, float damage, unsigned int warhead, float scale, DADamageType::Type type)
{
	RenSharpRootEventClass::Get_Instance().Observer_Damage_Dealt(this, victim, damage, warhead, scale, type);
}

void RenSharpGameObjObserverClass::Damage_Received(ArmedGameObj *damager, float damage, unsigned int warhead, float scale, DADamageType::Type type)
{
	RenSharpRootEventClass::Get_Instance().Observer_Damage_Received(this, damager, damage, warhead, scale, type);
}

void RenSharpGameObjObserverClass::Kill_Dealt(DamageableGameObj *victim, float damage, unsigned int warhead, float scale, DADamageType::Type type)
{
	RenSharpRootEventClass::Get_Instance().Observer_Kill_Dealt(this, victim, damage, warhead, scale, type);
}

void RenSharpGameObjObserverClass::Kill_Received(ArmedGameObj *killer, float damage, unsigned int warhead, float scale, DADamageType::Type type)
{
	RenSharpRootEventClass::Get_Instance().Observer_Kill_Received(this, killer, damage, warhead, scale, type);
}

bool RenSharpGameObjObserverClass::PowerUp_Grant_Request(cPlayer *player)
{
	return RenSharpRootEventClass::Get_Instance().Observer_PowerUp_Grant_Request(this, player);
}

bool RenSharpGameObjObserverClass::PowerUp_Grant_Request(const PowerUpGameObjDef *powerUp, PowerUpGameObj *powerUpObj)
{
	return RenSharpRootEventClass::Get_Instance().Observer_PowerUp_Grant_Request(this, powerUp, powerUpObj);
}

void RenSharpGameObjObserverClass::PowerUp_Grant(cPlayer *player)
{
	RenSharpRootEventClass::Get_Instance().Observer_PowerUp_Grant(this, player);
}

void RenSharpGameObjObserverClass::PowerUp_Grant(const PowerUpGameObjDef *powerUp, PowerUpGameObj *powerUpObj)
{
	RenSharpRootEventClass::Get_Instance().Observer_PowerUp_Grant(this, powerUp, powerUpObj);
}

bool RenSharpGameObjObserverClass::Add_Weapon_Request(const WeaponDefinitionClass *weapon)
{
	return RenSharpRootEventClass::Get_Instance().Observer_Add_Weapon_Request(this, weapon);
}

void RenSharpGameObjObserverClass::Add_Weapon(WeaponClass *weapon)
{
	RenSharpRootEventClass::Get_Instance().Observer_Add_Weapon(this, weapon);
}

void RenSharpGameObjObserverClass::Remove_Weapon(WeaponClass *weapon)
{
	RenSharpRootEventClass::Get_Instance().Observer_Remove_Weapon(this, weapon);
}

void RenSharpGameObjObserverClass::Clear_Weapons()
{
	RenSharpRootEventClass::Get_Instance().Observer_Clear_Weapons(this);
}