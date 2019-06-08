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
using System.Drawing;

namespace RenSharpExamplePlugin
{
    public class RenSharpExamplePlugin : RenSharpEventClass
    {
        public RenSharpExamplePlugin()
        {

        }

        public override void UnmanagedAttach()
        {
            RegisterEvent(DAEventType.SettingsLoaded);
            RegisterEvent(DAEventType.Chat);
            RegisterEvent(DAEventType.ChatCommand);
            RegisterEvent(DAEventType.KeyHook);
            RegisterEvent(DAEventType.HostChat);
            RegisterEvent(DAEventType.Radio);
            RegisterEvent(DAEventType.ConnectionRequest);
            RegisterEvent(DAEventType.PlayerPreJoin);
            RegisterEvent(DAEventType.PlayerJoin);
            RegisterEvent(DAEventType.PlayerLeave);
            RegisterEvent(DAEventType.PlayerLoaded);
            RegisterEvent(DAEventType.NameChange);
            RegisterEvent(DAEventType.LevelLoaded);
            RegisterEvent(DAEventType.Remix);
            RegisterEvent(DAEventType.Rebalance);
            RegisterEvent(DAEventType.Swap);
            RegisterEvent(DAEventType.Gameover);
            RegisterEvent(DAEventType.ConsoleOutput);
            RegisterEvent(DAEventType.RenLog);
            RegisterEvent(DAEventType.DALog);
            RegisterEvent(DAEventType.VehiclePurchaseRequest);
            RegisterEvent(DAEventType.CharacterPurchaseRequest);
            RegisterEvent(DAEventType.PowerUpPurchaseRequest);
            RegisterEvent(DAEventType.CustomPurchaseRequest);
            RegisterEvent(DAEventType.VehiclePurchase);
            RegisterEvent(DAEventType.CharacterPurchase);
            RegisterEvent(DAEventType.PowerUpPurchase);
            RegisterEvent(DAEventType.CustomPurchase);
            RegisterEvent(DAEventType.Refill);
            RegisterEvent(DAEventType.Suicide);
            RegisterEvent(DAEventType.TeamChangeRequest);
            RegisterEvent(DAEventType.TeamChange);
            RegisterEvent(DAEventType.VehicleEntryRequest);
            RegisterEvent(DAEventType.VehicleEnter);
            RegisterEvent(DAEventType.VehicleExit);
            RegisterEvent(DAEventType.PowerUpGrantRequest);
            RegisterEvent(DAEventType.PowerUpGrant);
            RegisterEvent(DAEventType.AddWeaponRequest);
            RegisterEvent(DAEventType.AddWeapon);
            RegisterEvent(DAEventType.RemoveWeapon);
            RegisterEvent(DAEventType.ClearWeapons);
            RegisterEvent(DAEventType.BeaconDeploy);
            RegisterEvent(DAEventType.BeaconDetonate);
            RegisterEvent(DAEventType.C4DetonateRequest);
            RegisterEvent(DAEventType.C4Detonate);
            RegisterEvent(DAEventType.ChangeCharacter);
            RegisterEvent(DAEventType.VehicleFlip);
            RegisterEvent(DAEventType.RequestVehicle);
            RegisterEvent(DAEventType.Think);

            RegisterObjectEvent(DAObjectEventType.Created, DAObjectEventObjectType.All);
            RegisterObjectEvent(DAObjectEventType.Destroyed, DAObjectEventObjectType.All);
            RegisterObjectEvent(DAObjectEventType.KillDealt, DAObjectEventObjectType.All);
            RegisterObjectEvent(DAObjectEventType.KillReceived, DAObjectEventObjectType.All);
            RegisterObjectEvent(DAObjectEventType.StockClientDamageRequest, DAObjectEventObjectType.All);
            RegisterObjectEvent(DAObjectEventType.TTClientDamageRequest, DAObjectEventObjectType.All);
            RegisterObjectEvent(DAObjectEventType.DamageDealtRequest, DAObjectEventObjectType.All);
            RegisterObjectEvent(DAObjectEventType.DamageReceivedRequest, DAObjectEventObjectType.All);
            RegisterObjectEvent(DAObjectEventType.DamageDealt, DAObjectEventObjectType.All);
            RegisterObjectEvent(DAObjectEventType.DamageReceived, DAObjectEventObjectType.All);
            RegisterObjectEvent(DAObjectEventType.Custom, DAObjectEventObjectType.All);
            RegisterObjectEvent(DAObjectEventType.Poke, DAObjectEventObjectType.All);
            RegisterObjectEvent(DAObjectEventType.ZoneEnter, DAObjectEventObjectType.All);
            RegisterObjectEvent(DAObjectEventType.ZoneExit, DAObjectEventObjectType.All);

            RegisterChatCommand(TestChatCommand, "!test", 0);

            StartTimer(1, TimeSpan.FromSeconds(5), true, "This is a test string");
        }

        protected override void Dispose(bool disposing)
        {
            base.Dispose(disposing);
        }

        bool TestChatCommand(IcPlayer player, string command, IDATokenClass text, TextMessageEnum chatType, object data)
        {
            Engine.SendMessage(Color.Green, "Hello there!");

            return true;
        }

        public override void SettingsLoadedEvent()
        {
            
        }

        public override bool ChatEvent(IcPlayer player, TextMessageEnum type, string message, int receiverID)
        {
            return true;
        }

        public override bool ChatCommandEvent(IcPlayer player, TextMessageEnum type, string command, IDATokenClass text, int receiverID)
        {
            return true;
        }

        public override bool KeyHookEvent(IcPlayer player, string key)
        {
            return true;
        }

        public override bool HostChatEvent(int id, TextMessageEnum type, string message)
        {
            return true;
        }

        public override bool RadioEvent(IcPlayer player, int playerType, int announcementID, int iconID, AnnouncementEnum announcementType)
        {
            return true;
        }

        public override ConnectionAcceptanceFilterStatus ConnectionRequestEvent(IConnectionRequest request, ref string refusalMessage)
        {
            return ConnectionAcceptanceFilterStatus.StatusAccepting;
        }

        public override void PlayerPreJoinEvent(IConnectionRequest request)
        {
           
        }

        public override void PlayerJoinEvent(IcPlayer player)
        {
            if (player.DAPlayer.FindObserver(nameof(RenSharpExamplePlayerObserver)) == null)
            {
                player.DAPlayer.AddObserver(new RenSharpExamplePlayerObserver());
            }
        }

        public override void PlayerLeaveEvent(IcPlayer player)
        {
            
        }

        public override void PlayerLoadedEvent(IcPlayer player)
        {
            
        }

        public override void NameChangeEvent(IcPlayer player)
        {
            
        }

        public override void LevelLoadedEvent()
        {
            
        }

        public override void RemixEvent()
        {
            
        }

        public override void RebalanceEvent()
        {
            
        }

        public override void SwapEvent()
        {
            
        }

        public override void GameOverEvent()
        {
            
        }

        public override void ConsoleOutputEvent(string output)
        {
            
        }

        public override void RenLogEvent(string output)
        {
            
        }

        public override void DALogEvent(string header, string output)
        {
            
        }

        public override int CharacterPurchaseRequestEvent(IBaseControllerClass baseController, IcPlayer player, ref float cost, ISoldierGameObjDef item)
        {
            return -1;
        }

        public override int VehiclePurchaseRequestEvent(IBaseControllerClass baseController, IcPlayer player, ref float cost, IVehicleGameObjDef item)
        {
            return -1;
        }

        public override int PowerUpPurchaseRequestEvent(IBaseControllerClass baseController, IcPlayer player, ref float cost, IPowerUpGameObjDef item)
        {
            return -1;
        }

        public override int CustomPurchaseRequestEvent(IBaseControllerClass baseController, IcPlayer player, ref float cost, uint id)
        {
            return -1;
        }

        public override void CharacterPurchaseEvent(IcPlayer player, float cost, ISoldierGameObjDef item)
        {

        }

        public override void VehiclePurchaseEvent(IcPlayer player, float cost, IVehicleGameObjDef item)
        {

        }

        public override void PowerUpPurchaseEvent(IcPlayer player, float cost, IPowerUpGameObjDef item)
        {

        }

        public override void CustomPurchaseEvent(IcPlayer player, float cost, uint id)
        {

        }

        public override bool RefillEvent(IcPlayer player)
        {
            return true;
        }

        public override bool SuicideEvent(IcPlayer player)
        {
            return true;
        }

        public override bool TeamChangeRequestEvent(IcPlayer player)
        {
            return true;
        }

        public override void TeamChangeEvent(IcPlayer player)
        {

        }

        public override bool VehicleEntryRequestEvent(IVehicleGameObj vehicle, IcPlayer player, ref int seat)
        {
            return true;
        }

        public override void VehicleEnterEvent(IVehicleGameObj vehicle, IcPlayer player, int seat)
        {

        }

        public override void VehicleExitEvent(IVehicleGameObj vehicle, IcPlayer player, int seat)
        {

        }

        public override bool PowerUpGrantRequestEvent(IcPlayer player, IPowerUpGameObjDef powerUp, IPowerUpGameObj powerUpObj)
        {
            return true;
        }

        public override void PowerUpGrantEvent(IcPlayer player, IPowerUpGameObjDef powerUp, IPowerUpGameObj powerUpObj)
        {

        }

        public override bool AddWeaponRequestEvent(IcPlayer player, IWeaponDefinitionClass weapon)
        {
            return true;
        }

        public override void AddWeaponEvent(IcPlayer player, IWeaponClass weapon)
        {

        }

        public override void RemoveWeaponEvent(IcPlayer player, IWeaponClass weapon)
        {

        }

        public override void ClearWeaponsEvent(IcPlayer player)
        {

        }

        public override void BeaconDeployEvent(IBeaconGameObj beacon)
        {

        }

        public override void BeaconDetonateEvent(IBeaconGameObj beacon)
        {

        }

        public override bool C4DetonateRequestEvent(IC4GameObj c4, ISmartGameObj triggerer)
        {
            return true;
        }

        public override void C4DetonateEvent(IC4GameObj c4)
        {

        }

        public override void ChangeCharacterEvent(IcPlayer player, ISoldierGameObjDef soldier)
        {

        }

        public override bool VehicleFlipEvent(IVehicleGameObj vehicle)
        {
            return true;
        }

        public override bool RequestVehicleEvent(IVehicleFactoryGameObj factory, IVehicleGameObjDef vehicle, IcPlayer player, float delay)
        {
            return true;
        }

        public override void Think()
        {

        }

        public override void ObjectCreatedEvent(IScriptableGameObj obj)
        {
            obj.AddObserver(new RenSharpExampleObserver());
        }

        public override bool StockClientDamageRequestEvent(IDamageableGameObj victim, IArmedGameObj damager, float damage, uint warhead)
        {
            return true;
        }

        public override bool TTClientDamageRequestEvent(IDamageableGameObj victim, IArmedGameObj damager, IAmmoDefinitionClass ammo, string bone)
        {
            return true;
        }

        public override bool DamageRequestEvent(IDamageableGameObj victim, IArmedGameObj damager, ref float damage, ref uint warhead, float scale, RenSharp.DADamageType type)
        {
            return true;
        }

        public override void DamageEvent(IDamageableGameObj victim, IArmedGameObj damager, float damage, uint warhead, float scale, RenSharp.DADamageType type)
        {

        }

        public override void KillEvent(IDamageableGameObj victim, IArmedGameObj killer, float damage, uint warhead, float scale, RenSharp.DADamageType type)
        {

        }

        public override void CustomEvent(IScriptableGameObj obj, int type, int param, IScriptableGameObj sender)
        {

        }

        public override void PokeEvent(IcPlayer player, IPhysicalGameObj obj)
        {

        }

        public override void ZoneEnterEvent(IScriptZoneGameObj obj, IPhysicalGameObj enterer)
        {

        }

        public override void ZoneExitEvent(IScriptZoneGameObj obj, IPhysicalGameObj exiter)
        {

        }

        public override void ObjectDestroyedEvent(IScriptableGameObj obj)
        {

        }

        public override void TimerExpired(int number, object data)
        {
            if (number == 1)
            {
                Engine.ConsoleOutput($"{nameof(RenSharpExamplePlugin)}.{nameof(TimerExpired)}: {nameof(number)}={number}, {nameof(data)}='{data}'.\n");
            }
        }
    }
}
