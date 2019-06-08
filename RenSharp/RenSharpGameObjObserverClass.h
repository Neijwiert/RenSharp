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

#include <da_gameobj.h>

class RenSharpGameObjObserverClass : public DAGameObjObserverClass
{
	private:
		StringClass name;

	public:
		RenSharpGameObjObserverClass(const char *name);
		virtual ~RenSharpGameObjObserverClass();

		virtual void Destroyed(GameObject *obj);
		virtual void Custom(GameObject *obj, int message, int param, GameObject *sender);
		virtual void Poked(GameObject *obj, GameObject *poker);
		virtual void Entered(GameObject *obj, GameObject *enterer);
		virtual void Exited(GameObject *obj, GameObject *exiter);
		virtual const char *Get_Name();
		virtual void Sound_Heard(GameObject *obj, const CombatSound &sound);
		virtual void Enemy_Seen(GameObject *obj, GameObject *enemy);
		virtual void Action_Complete(GameObject *obj, int actionID, ActionCompleteReason completeReason);
		virtual void Timer_Expired(GameObject *obj, int number);
		virtual void Animation_Complete(GameObject *obj, const char *name);
		virtual void Init();
		virtual bool Vehicle_Entry_Request(cPlayer *player, int &seat);
		virtual bool Vehicle_Entry_Request(VehicleGameObj *vehicle, int &seat);
		virtual void Vehicle_Enter(cPlayer *player, int seat);
		virtual void Vehicle_Enter(VehicleGameObj *vehicle, int seat);
		virtual void Vehicle_Exit(cPlayer *player, int seat);
		virtual void Vehicle_Exit(VehicleGameObj *vehicle, int seat);
		virtual bool Vehicle_Flip();
		virtual bool Damage_Dealt_Request(DamageableGameObj *victim, float &damage, unsigned int &warhead, float scale, DADamageType::Type type);
		virtual bool Damage_Received_Request(ArmedGameObj *damager, float &damage, unsigned int &warhead, float scale, DADamageType::Type type);
		virtual void Damage_Dealt(DamageableGameObj *victim, float damage, unsigned int warhead, float scale, DADamageType::Type type);
		virtual void Damage_Received(ArmedGameObj *damager, float damage, unsigned int warhead, float scale, DADamageType::Type type);
		virtual void Kill_Dealt(DamageableGameObj *victim, float damage, unsigned int warhead, float scale, DADamageType::Type type);
		virtual void Kill_Received(ArmedGameObj *killer, float damage, unsigned int warhead, float scale, DADamageType::Type type);
		virtual bool PowerUp_Grant_Request(cPlayer *player);
		virtual bool PowerUp_Grant_Request(const PowerUpGameObjDef *powerUp, PowerUpGameObj *powerUpObj);
		virtual void PowerUp_Grant(cPlayer *player);
		virtual void PowerUp_Grant(const PowerUpGameObjDef *powerUp, PowerUpGameObj *powerUpObj);
		virtual bool Add_Weapon_Request(const WeaponDefinitionClass *weapon);
		virtual void Add_Weapon(WeaponClass *weapon);
		virtual void Remove_Weapon(WeaponClass *weapon);
		virtual void Clear_Weapons();
};