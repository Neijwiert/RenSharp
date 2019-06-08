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

#include <da_player.h>

class RenSharpPlayerObserverClass : public DAPlayerObserverClass
{
	private:
		StringClass name;
		
	public:
		RenSharpPlayerObserverClass(const char *name);
		virtual ~RenSharpPlayerObserverClass();

		virtual const char *Get_Observer_Name();
		virtual void Init();
		virtual void Join();
		virtual void Leave();
		virtual void Level_Loaded();
		virtual void Player_Loaded();
		virtual void Name_Change();
		virtual void Team_Change();
		virtual int Character_Purchase_Request(float &cost, const SoldierGameObjDef *item);
		virtual int Vehicle_Purchase_Request(float &cost, const VehicleGameObjDef *item);
		virtual int PowerUp_Purchase_Request(float &cost, const PowerUpGameObjDef *item);
		virtual int Custom_Purchase_Request(float &cost, unsigned int id);
		virtual void Character_Purchase(float cost, const SoldierGameObjDef *item);
		virtual void Vehicle_Purchase(float cost, const VehicleGameObjDef *item);
		virtual void PowerUp_Purchase(float cost, const PowerUpGameObjDef *item);
		virtual void Custom_Purchase(float cost, unsigned int id);
		virtual bool Vehicle_Entry_Request(VehicleGameObj *vehicle, int &seat);
		virtual void Vehicle_Enter(VehicleGameObj *vehicle, int seat);
		virtual void Vehicle_Exit(VehicleGameObj *vehicle, int seat);
		virtual bool PowerUp_Grant_Request(const PowerUpGameObjDef *powerUp, PowerUpGameObj *powerUpObj);
		virtual void PowerUp_Grant(const PowerUpGameObjDef *powerUp, PowerUpGameObj *powerUpObj);
		virtual bool Add_Weapon_Request(const WeaponDefinitionClass *weapon);
		virtual void Add_Weapon(WeaponClass *weapon);
		virtual void Remove_Weapon(WeaponClass *weapon);
		virtual void Clear_Weapons();
		virtual bool C4_Detonate_Request(C4GameObj *c4);
		virtual void C4_Detonate(C4GameObj *c4);
		virtual void Change_Character(const SoldierGameObjDef *soldier);
		virtual void Created();
		virtual void Destroyed();
		virtual bool Damage_Dealt_Request(DamageableGameObj *victim, float &damage, unsigned int &warhead, float scale, DADamageType::Type type);
		virtual bool Damage_Received_Request(ArmedGameObj *damager, float &damage, unsigned int &warhead, float scale, DADamageType::Type type);
		virtual void Damage_Dealt(DamageableGameObj *victim, float damage, unsigned int warhead, float scale, DADamageType::Type type);
		virtual void Damage_Received(ArmedGameObj *damager, float damage, unsigned int warhead, float scale, DADamageType::Type type);
		virtual void Kill_Dealt(DamageableGameObj *victim, float damage, unsigned int warhead, float scale, DADamageType::Type type);
		virtual void Kill_Received(ArmedGameObj *killer, float damage, unsigned int warhead, float scale, DADamageType::Type type);
		virtual void Custom(GameObject *sender, int type, int param);
		virtual void Poked(cPlayer *player);
		virtual void Timer_Expired(int number, unsigned int data);
		virtual void Think();
};