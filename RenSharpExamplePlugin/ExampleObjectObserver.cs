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

namespace RenSharpExamplePlugin
{
    public class ExampleObjectObserver : RenSharpGameObjObserverClass
    {
        public ExampleObjectObserver() 
            : base(nameof(ExampleObjectObserver))
        {
        }

        protected override void Dispose(bool disposing)
        {
            base.Dispose(disposing);
        }

        public override void UnmanagedAttach()
        {
            
        }

        public override void Init(IScriptableGameObj obj)
        {
            
        }

        public override void Destroyed(IScriptableGameObj obj)
        {

        }

        public override void Custom(IScriptableGameObj obj, int type, int param, IScriptableGameObj sender)
        {

        }

        public override void SoundHeard(IScriptableGameObj obj, ICombatSound sound)
        {

        }

        public override void EnemySeen(IScriptableGameObj obj, IScriptableGameObj enemy)
        {

        }

        public override void ActionComplete(IScriptableGameObj obj, int actionId, ActionCompleteReason completeReason)
        {

        }

        public override void TimerExpired(int number, object data)
        {
            
        }

        public override void AnimationComplete(IScriptableGameObj obj, string animationName)
        {

        }

        public override void Poked(IScriptableGameObj obj, IScriptableGameObj poker)
        {

        }

        public override void Entered(IScriptableGameObj obj, IScriptableGameObj enterer)
        {

        }

        public override void Exited(IScriptableGameObj obj, IScriptableGameObj exiter)
        {

        }

        public override bool VehicleEntryRequest(IScriptableGameObj obj, IcPlayer player, ref int seat)
        {
            if (player.PlayerType != DAVehicleManager.GetTeam(Owner))
            { 
                return false; //Prevent the enemy from stealing this vehicle.
            }

            return true;
        }

        public override bool VehicleEntryRequest(IScriptableGameObj obj, IVehicleGameObj vehicle, ref int seat)
        {
            return true;
        }

        public override void VehicleEnter(IScriptableGameObj obj, IcPlayer player, int seat)
        {

        }

        public override void VehicleEnter(IScriptableGameObj obj, IVehicleGameObj vehicle, int seat)
        {

        }

        public override void VehicleExit(IScriptableGameObj obj, IcPlayer player, int seat)
        {

        }

        public override void VehicleExit(IScriptableGameObj obj, IVehicleGameObj vehicle, int seat)
        {

        }

        public override bool VehicleFlip(IScriptableGameObj obj)
        {
            return true;
        }

        public override bool DamageDealtRequest(IScriptableGameObj obj, IDamageableGameObj victim, ref float damage, ref uint warhead, float scale, RenSharp.DADamageType type)
        {
            return true;
        }

        public override bool DamageReceivedRequest(IScriptableGameObj obj, IArmedGameObj damager, ref float damage, ref uint warhead, float scale, RenSharp.DADamageType type)
        {
            damage *= 0.9f; //%10 damage reduction.

            return true;
        }

        public override void DamageDealt(IScriptableGameObj obj, IDamageableGameObj victim, float damage, uint warhead, float scale, RenSharp.DADamageType type)
        {

        }

        public override void DamageReceived(IScriptableGameObj obj, IArmedGameObj damager, float damage, uint warhead, float scale, RenSharp.DADamageType type)
        {

        }

        public override void KillDealt(IScriptableGameObj obj, IDamageableGameObj victim, float damage, uint warhead, float scale, RenSharp.DADamageType type)
        {

        }

        public override void KillReceived(IScriptableGameObj obj, IArmedGameObj killer, float damage, uint warhead, float scale, RenSharp.DADamageType type)
        {

        }

        public override bool PowerUpGrantRequest(IScriptableGameObj obj, IcPlayer player)
        {
            return true;
        }

        public override bool PowerUpGrantRequest(IScriptableGameObj obj, IPowerUpGameObjDef powerUp, IPowerUpGameObj powerUpObj)
        {
            return true;
        }

        public override void PowerUpGrant(IScriptableGameObj obj, IcPlayer player)
        {

        }

        public override void PowerUpGrant(IScriptableGameObj obj, IPowerUpGameObjDef powerUp, IPowerUpGameObj powerUpObj)
        {

        }

        public override bool AddWeaponRequest(IScriptableGameObj obj, IWeaponDefinitionClass weapon)
        {
            return true;
        }

        public override void AddWeapon(IScriptableGameObj obj, IWeaponClass weapon)
        {

        }

        public override void RemoveWeapon(IScriptableGameObj obj, IWeaponClass weapon)
        {

        }

        public override void ClearWeapons(IScriptableGameObj obj)
        {

        }
    }
}
