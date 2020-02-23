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

using RenSharp;
using System;

namespace RenSharpExamplePlugin
{
    public class ExamplePlayerObserver : RenSharpPlayerObserverClass
    {
        public ExamplePlayerObserver()
            : base(nameof(ExamplePlayerObserver))
        {

        }

        protected override void Dispose(bool disposing)
        {
            base.Dispose(disposing);
        }

        public override void UnmanagedAttach()
        {
            
        }

        public override void Init()
        {
            AddFlag(RenSharp.DAPlayerFlags.PersistMap);
            AddFlag(RenSharp.DAPlayerFlags.Think);

            RegisterKeyHook(RefillKeyHook, "VehStatus");

            StartTimer(1, TimeSpan.FromSeconds(10), false, "Player observer timer data");
        }

        public void RefillKeyHook(IcPlayer player, string key, object data)
        {
            Engine.GrantRefill(GameObj);
        }

        public override void Join()
        {

        }

        public override void Leave()
        {

        }

        public override void LevelLoaded()
        {

        }

        public override void PlayerLoaded()
        {

        }

        public override void NameChange()
        {

        }

        public override void TeamChange()
        {

        }

        public override int CharacterPurchaseRequest(ref float cost, ISoldierGameObjDef item)
        {
            cost *= 0.9f; //10% discount on characters.

            return -1;
        }

        public override int VehiclePurchaseRequest(ref float cost, IVehicleGameObjDef item)
        {
            cost *= 0.8f; //20% discount on vehicles.

            return -1;
        }

        public override int PowerUpPurchaseRequest(ref float cost, IPowerUpGameObjDef item)
        {
            cost *= 0.7f; //30% discount on powerups.

            return -1;
        }

        public override int CustomPurchaseRequest(ref float cost, uint id)
        {
            return -1;
        }

        public override void CharacterPurchase(float cost, ISoldierGameObjDef item)
        {

        }

        public override void VehiclePurchase(float cost, IVehicleGameObjDef item)
        {

        }

        public override void PowerUpPurchase(float cost, IPowerUpGameObjDef item)
        {

        }

        public override void CustomPurchase(float cost, uint id)
        {

        }

        public override bool VehicleEntryRequest(IVehicleGameObj vehicle, ref int seat)
        {
            //This player can only enter the passenger seat of vehicles. If it's a one seater then the player is prohibited from entering.
            if (seat == 0)
            {
                seat = Engine.FindEmptyVehicleSeat(vehicle, false);
            }

            return true;
        }

        public override void VehicleEnter(IVehicleGameObj vehicle, int seat)
        {
            //This player increases the health of any vehicle they enter by 10%
            vehicle.DefenseObject.ShieldStrengthMax *= 1.1f;
            vehicle.DefenseObject.ShieldStrength = vehicle.DefenseObject.ShieldStrengthMax;
        }

        public override void VehicleExit(IVehicleGameObj vehicle, int seat)
        {
            //Remove the increase when they exit.
            vehicle.DefenseObject.ShieldStrengthMax = vehicle.Definition.DefenseObjectDef.ShieldStrengthMax;
        }

        public override bool PowerUpGrantRequest(IPowerUpGameObjDef powerUp, IPowerUpGameObj powerUpObj)
        {
            return true;
        }

        public override void PowerUpGrant(IPowerUpGameObjDef powerUp, IPowerUpGameObj powerUpObj)
        {

        }

        public override bool AddWeaponRequest(IWeaponDefinitionClass weapon)
        {
            return true;
        }

        public override void AddWeapon(IWeaponClass weapon)
        {

        }

        public override void RemoveWeapon(IWeaponClass weapon)
        {

        }

        public override void ClearWeapons()
        {

        }

        public override bool C4DetonateRequest(IC4GameObj c4)
        {
            return false; //Don't trigger proximity C4.
        }

        public override void C4Detonate(IC4GameObj c4)
        {

        }

        public override void ChangeCharacter(ISoldierGameObjDef soldier)
        {

        }

        public override void Created()
        {
            //Another 10% health increase.
            GameObj.DefenseObject.HealthMax *= 1.1f;
            GameObj.DefenseObject.Health = GameObj.DefenseObject.HealthMax;
        }

        public override void Destroyed()
        {

        }

        public override bool DamageDealtRequest(IDamageableGameObj victim, ref float damage, ref uint warhead, float scale, RenSharp.DADamageType type)
        {
            if (type == RenSharp.DADamageType.Splash)
            {
                return false; //This player deals no splash damage.
            }

            return true;
        }

        public override bool DamageReceivedRequest(IArmedGameObj damager, ref float damage, ref uint warhead, float scale, RenSharp.DADamageType type)
        {
            if (type == RenSharp.DADamageType.Squish || type == RenSharp.DADamageType.Fall)
            {
                return false; //This player cannot be squished and takes no fall damage.
            }

            return true;
        }

        public override void DamageDealt(IDamageableGameObj victim, float damage, uint warhead, float scale, RenSharp.DADamageType type)
        {
            
        }

        public override void DamageReceived(IArmedGameObj damager, float damage, uint warhead, float scale, RenSharp.DADamageType type)
        {

        }

        public override void KillDealt(IDamageableGameObj victim, float damage, uint warhead, float scale, RenSharp.DADamageType type)
        {
            //Anything this player kills explodes.
            Commands.CreateExplosion("Explosion_Shell_Artillery", Commands.GetPosition(victim), GameObj);
        }

        public override void KillReceived(IArmedGameObj killer, float damage, uint warhead, float scale, RenSharp.DADamageType type)
        {
            //Anyone who kills this player gets a refill.
            Engine.GrantRefill(killer);
        }

        public override void Custom(IScriptableGameObj sender, int type, int param)
        {

        }

        public override void Poked(IcPlayer player)
        {

        }

        public override void TimerExpired(int number, object data)
        {
            if (number == 1)
            {
                Engine.ConsoleOutput($"{nameof(ExamplePlayerObserver)}.{nameof(TimerExpired)}: {nameof(number)}={number}, {nameof(data)}='{data}'.\n");
            }
        }

        public override void Think()
        {

        }
    }
}
