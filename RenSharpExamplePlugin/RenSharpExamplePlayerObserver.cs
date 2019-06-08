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

using RenSharp;
using System;

namespace RenSharpExamplePlugin
{
    public class RenSharpExamplePlayerObserver : RenSharpPlayerObserverClass
    {
        public RenSharpExamplePlayerObserver()
            : base(nameof(RenSharpExamplePlayerObserver))
        {

        }

        public override void UnmanagedAttach()
        {
            
        }

        protected override void Dispose(bool disposing)
        {
            base.Dispose(disposing);
        }

        public override void Init()
        {
            AddFlag(RenSharp.DAPlayerFlags.PersistMap);
            AddFlag(RenSharp.DAPlayerFlags.Think);

            StartTimer(1, TimeSpan.FromSeconds(10), false, "Player observer timer data");
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
            return -1;
        }

        public override int VehiclePurchaseRequest(ref float cost, IVehicleGameObjDef item)
        {
            return -1;
        }

        public override int PowerUpPurchaseRequest(ref float cost, IPowerUpGameObjDef item)
        {
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
            return true;
        }

        public override void VehicleEnter(IVehicleGameObj vehicle, int seat)
        {

        }

        public override void VehicleExit(IVehicleGameObj vehicle, int seat)
        {

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
            return true;
        }

        public override void C4Detonate(IC4GameObj c4)
        {

        }

        public override void ChangeCharacter(ISoldierGameObjDef soldier)
        {

        }

        public override void Created()
        {

        }

        public override void Destroyed()
        {

        }

        public override bool DamageDealtRequest(IDamageableGameObj victim, ref float damage, ref uint warhead, float scale, RenSharp.DADamageType type)
        {
            return true;
        }

        public override bool DamageReceivedRequest(IArmedGameObj damager, ref float damage, ref uint warhead, float scale, RenSharp.DADamageType type)
        {
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

        }

        public override void KillReceived(IArmedGameObj killer, float damage, uint warhead, float scale, RenSharp.DADamageType type)
        {

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
                Engine.ConsoleOutput($"{nameof(RenSharpExamplePlayerObserver)}.{nameof(TimerExpired)}: {nameof(number)}={number}, {nameof(data)}='{data}'.\n");
            }
        }

        public override void Think()
        {

        }
    }
}
