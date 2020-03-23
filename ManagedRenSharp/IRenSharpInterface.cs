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

using System;
using System.Runtime.InteropServices;

namespace RenSharp
{
    [ComImport, Guid("E917FA9E-0909-4F70-AF1E-5E93467A30AB"), InterfaceType(ComInterfaceType.InterfaceIsIUnknown)]
    public interface IRenSharpInterface
    {
        // Other
        void FreePointer(IntPtr ptr);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool Init();

        void Shutdown();

        void Think();


        // RenSharpEventClass
        void EventClassDestructed(IntPtr eventClass);

        void EventClassSettingsLoadedEvent(IntPtr eventClass);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool EventClassChatEvent(IntPtr eventClass, IntPtr player, TextMessageEnum type, [MarshalAs(UnmanagedType.LPWStr)] string message, int receiverID);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool EventClassChatCommandEvent(IntPtr eventClass, IntPtr player, TextMessageEnum type, [MarshalAs(UnmanagedType.LPStr)] string command, IntPtr text, int receiverID);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool EventClassKeyHookEvent(IntPtr eventClass, IntPtr player, [MarshalAs(UnmanagedType.LPStr)] string key);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool EventClassHostChatEvent(IntPtr eventClass, int id, TextMessageEnum type, [MarshalAs(UnmanagedType.LPStr)] string message);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool EventClassRadioEvent(IntPtr eventClass, IntPtr player, int playerType, int announcementID, int iconID, AnnouncementEnum announcementType);

        ConnectionAcceptanceFilterStatus EventClassConnectionRequestEvent(IntPtr eventClass, IntPtr request, ref IntPtr message);

        void EventClassPlayerPreJoinEvent(IntPtr eventClass, IntPtr request);

	    void EventClassPlayerJoinEvent(IntPtr eventClass, IntPtr player);

	    void EventClassPlayerLeaveEvent(IntPtr eventClass, IntPtr player);

        void EventClassPlayerLoadedEvent(IntPtr eventClass, IntPtr player);

	    void EventClassNameChangeEvent(IntPtr eventClass, IntPtr player);

	    void EventClassLevelLoadedEvent(IntPtr eventClass);

	    void EventClassRemixEvent(IntPtr eventClass);

	    void EventClassRebalanceEvent(IntPtr eventClass);

	    void EventClassSwapEvent(IntPtr eventClass);

	    void EventClassGameOverEvent(IntPtr eventClass);

	    void EventClassConsoleOutputEvent(IntPtr eventClass, [MarshalAs(UnmanagedType.LPStr)] string output);

        void EventClassRenLogEvent(IntPtr eventClass, [MarshalAs(UnmanagedType.LPStr)] string output);

        void EventClassDALogEvent(IntPtr eventClass, [MarshalAs(UnmanagedType.LPStr)] string header, [MarshalAs(UnmanagedType.LPStr)] string output);

        int EventClassCharacterPurchaseRequestEvent(IntPtr eventClass, IntPtr baseController, IntPtr player, ref float cost, IntPtr item);

        int EventClassVehiclePurchaseRequestEvent(IntPtr eventClass, IntPtr baseController, IntPtr player, ref float cost, IntPtr item);

        int EventClassPowerUpPurchaseRequestEvent(IntPtr eventClass, IntPtr baseController, IntPtr player, ref float cost, IntPtr item);

        int EventClassCustomPurchaseRequestEvent(IntPtr eventClass, IntPtr baseController, IntPtr player, ref float cost, uint id);

        void EventClassCharacterPurchaseEvent(IntPtr eventClass, IntPtr player, float cost, IntPtr item);

        void EventClassVehiclePurchaseEvent(IntPtr eventClass, IntPtr player, float cost, IntPtr item);

        void EventClassPowerUpPurchaseEvent(IntPtr eventClass, IntPtr player, float cost, IntPtr item);

        void EventClassCustomPurchaseEvent(IntPtr eventClass, IntPtr player, float cost, uint id);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool EventClassRefillEvent(IntPtr eventClass, IntPtr player);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool EventClassSuicideEvent(IntPtr eventClass, IntPtr player);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool EventClassTeamChangeRequestEvent(IntPtr eventClass, IntPtr player);

	    void EventClassTeamChangeEvent(IntPtr eventClass, IntPtr player);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool EventClassVehicleEntryRequestEvent(IntPtr eventClass, IntPtr vehicle, IntPtr player, ref int seat);

        void EventClassVehicleEnterEvent(IntPtr eventClass, IntPtr vehicle, IntPtr player, int seat);

        void EventClassVehicleExitEvent(IntPtr eventClass, IntPtr vehicle, IntPtr player, int seat);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool EventClassPowerUpGrantRequestEvent(IntPtr eventClass, IntPtr player, IntPtr powerUp, IntPtr powerUpObj);

        void EventClassPowerUpGrantEvent(IntPtr eventClass, IntPtr player, IntPtr powerUp, IntPtr powerUpObj);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool EventClassAddWeaponRequestEvent(IntPtr eventClass, IntPtr player, IntPtr weapon);

        void EventClassAddWeaponEvent(IntPtr eventClass, IntPtr player, IntPtr weapon);

        void EventClassRemoveWeaponEvent(IntPtr eventClass, IntPtr player, IntPtr weapon);

        void EventClassClearWeaponsEvent(IntPtr eventClass, IntPtr player);

        void EventClassBeaconDeployEvent(IntPtr eventClass, IntPtr beacon);

        void EventClassBeaconDetonateEvent(IntPtr eventClass, IntPtr beacon);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool EventClassC4DetonateRequestEvent(IntPtr eventClass, IntPtr c4, IntPtr triggerer);

        void EventClassC4DetonateEvent(IntPtr eventClass, IntPtr c4);

        void EventClassChangeCharacterEvent(IntPtr eventClass, IntPtr player, IntPtr soldier);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool EventClassVehicleFlipEvent(IntPtr eventClass, IntPtr vehicle);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool EventClassRequestVehicleEvent(IntPtr eventClass, IntPtr factory, IntPtr vehicle, IntPtr player, float delay);

        void EventClassThink(IntPtr eventClass);

        void EventClassObjectCreatedEvent(IntPtr eventClass, IntPtr obj);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool EventClassStockClientDamageRequestEvent(IntPtr eventClass, IntPtr victim, IntPtr damager, float damage, uint warhead);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool EventClassTTClientDamageRequestEvent(IntPtr eventClass, IntPtr victim, IntPtr damager, IntPtr ammo, [MarshalAs(UnmanagedType.LPStr)] string bone);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool EventClassDamageRequestEvent(IntPtr eventClass, IntPtr victim, IntPtr damager, ref float damage, ref uint warhead, float scale, DADamageType type);

        void EventClassDamageEvent(IntPtr eventClass, IntPtr victim, IntPtr damager, float damage, uint warhead, float scale, DADamageType type);

        void EventClassKillEvent(IntPtr eventClass, IntPtr victim, IntPtr killer, float damage, uint warhead, float scale, DADamageType type);

        void EventClassCustomEvent(IntPtr eventClass, IntPtr obj, int type, int param, IntPtr sender);

        void EventClassPokeEvent(IntPtr eventClass, IntPtr player, IntPtr obj);

        void EventClassZoneEnterEvent(IntPtr eventClass, IntPtr obj, IntPtr enterer);

        void EventClassZoneExitEvent(IntPtr eventClass, IntPtr obj, IntPtr exiter);

        void EventClassObjectDestroyedEvent(IntPtr eventClass, IntPtr obj);

        void EventClassTimerExpired(IntPtr eventClass, int number, uint data);


        // RenSharpGameObjObserverClass
        void ObserverDestructed(IntPtr observer);

	    void ObserverDestroyed(IntPtr observer, IntPtr obj);

	    void ObserverCustom(IntPtr observer, IntPtr obj, int message, int param, IntPtr sender);

	    void ObserverPoked(IntPtr observer, IntPtr obj, IntPtr poker);

	    void ObserverEntered(IntPtr observer, IntPtr obj, IntPtr enterer);

	    void ObserverExited(IntPtr observer, IntPtr obj, IntPtr exiter);

	    void ObserverSoundHeard(IntPtr observer, IntPtr obj, IntPtr sound);

	    void ObserverEnemySeen(IntPtr observer, IntPtr obj, IntPtr enemy);

	    void ObserverActionComplete(IntPtr observer, IntPtr obj, int actionID, ActionCompleteReason completeReason);

	    void ObserverTimerExpired(IntPtr observer, IntPtr obj, int number);

	    void ObserverAnimationComplete(IntPtr observer, IntPtr obj, [MarshalAs(UnmanagedType.LPStr)] string name);

	    void ObserverInit(IntPtr observer);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool ObserverVehicleEntryRequest1(IntPtr observer, IntPtr player, ref int seat);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool ObserverVehicleEntryRequest2(IntPtr observer, IntPtr vehicle, ref int seat);

	    void ObserverVehicleEnter1(IntPtr observer, IntPtr player, int seat);

	    void ObserverVehicleEnter2(IntPtr observer, IntPtr vehicle, int seat);

	    void ObserverVehicleExit1(IntPtr observer, IntPtr player, int seat);

	    void ObserverVehicleExit2(IntPtr observer, IntPtr vehicle, int seat);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool ObserverVehicleFlip(IntPtr observer);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool ObserverDamageDealtRequest(IntPtr observer, IntPtr victim, ref float damage, ref uint warhead, float scale, DADamageType type);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool ObserverDamageReceivedRequest(IntPtr observer, IntPtr damager, ref float damage, ref uint warhead, float scale, DADamageType type);

	    void ObserverDamageDealt(IntPtr observer, IntPtr victim, float damage, uint warhead, float scale, DADamageType type);

	    void ObserverDamageReceived(IntPtr observer, IntPtr damager, float damage, uint warhead, float scale, DADamageType type);

	    void ObserverKillDealt(IntPtr observer, IntPtr victim, float damage, uint warhead, float scale, DADamageType type);

	    void ObserverKillReceived(IntPtr observer, IntPtr killer, float damage, uint warhead, float scale, DADamageType type);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool ObserverPowerUpGrantRequest1(IntPtr observer, IntPtr player);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool ObserverPowerUpGrantRequest2(IntPtr observer, IntPtr powerUp, IntPtr powerUpObj);

	    void ObserverPowerUpGrant1(IntPtr observer, IntPtr player);

	    void ObserverPowerUpGrant2(IntPtr observer, IntPtr powerUp, IntPtr powerUpObj);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool ObserverAddWeaponRequest(IntPtr observer, IntPtr weapon);

	    void ObserverAddWeapon(IntPtr observer, IntPtr weapon);

	    void ObserverRemoveWeapon(IntPtr observer, IntPtr weapon);

	    void ObserverClearWeapons(IntPtr observer);


        // RenSharpPlayerObserverClass
        void PlayerObserverDestructed(IntPtr observer);

        void PlayerObserverInit(IntPtr observer);

        void PlayerObserverJoin(IntPtr observer);

        void PlayerObserverLeave(IntPtr observer);

        void PlayerObserverLevelLoaded(IntPtr observer);

        void PlayerObserverPlayerLoaded(IntPtr observer);

        void PlayerObserverNameChange(IntPtr observer);

        void PlayerObserverTeamChange(IntPtr observer);

        int PlayerObserverCharacterPurchaseRequest(IntPtr observer, ref float cost, IntPtr item);

        int PlayerObserverVehiclePurchaseRequest(IntPtr observer, ref float cost, IntPtr item);

        int PlayerObserverPowerUpPurchaseRequest(IntPtr observer, ref float cost, IntPtr item);

        int PlayerObserverCustomPurchaseRequest(IntPtr observer, ref float cost, uint id);

        void PlayerObserverCharacterPurchase(IntPtr observer, float cost, IntPtr item);

        void PlayerObserverVehiclePurchase(IntPtr observer, float cost, IntPtr item);

        void PlayerObserverPowerUpPurchase(IntPtr observer, float cost, IntPtr item);

        void PlayerObserverCustomPurchase(IntPtr observer, float cost, uint id);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool PlayerObserverVehicleEntryRequest(IntPtr observer, IntPtr vehicle, ref int seat);

        void PlayerObserverVehicleEnter(IntPtr observer, IntPtr vehicle, int seat);

        void PlayerObserverVehicleExit(IntPtr observer, IntPtr vehicle, int seat);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool PlayerObserverPowerUpGrantRequest(IntPtr observer, IntPtr powerUp, IntPtr powerUpObj);

		void PlayerObserverPowerUpGrant(IntPtr observer, IntPtr powerUp, IntPtr powerUpObj);

		[return: MarshalAs(UnmanagedType.Bool)]
        bool PlayerObserverAddWeaponRequest(IntPtr observer, IntPtr weapon);

        void PlayerObserverAddWeapon(IntPtr observer, IntPtr weapon);

        void PlayerObserverRemoveWeapon(IntPtr observer, IntPtr weapon);

        void PlayerObserverClearWeapons(IntPtr observer);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool PlayerObserverC4DetonateRequest(IntPtr observer, IntPtr c4);

        void PlayerObserverC4Detonate(IntPtr observer, IntPtr c4);

        void PlayerObserverChangeCharacter(IntPtr observer, IntPtr soldier);

        void PlayerObserverCreated(IntPtr observer);

        void PlayerObserverDestroyed(IntPtr observer);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool PlayerObserverDamageDealtRequest(IntPtr observer, IntPtr victim, ref float damage, ref uint warhead, float scale, DADamageType type);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool PlayerObserverDamageReceivedRequest(IntPtr observer, IntPtr damager, ref float damage, ref uint warhead, float scale, DADamageType type);

        void PlayerObserverDamageDealt(IntPtr observer, IntPtr victim, float damage, uint warhead, float scale, DADamageType type);

        void PlayerObserverDamageReceived(IntPtr observer, IntPtr damager, float damage, uint warhead, float scale, DADamageType type);

        void PlayerObserverKillDealt(IntPtr observer, IntPtr victim, float damage, uint warhead, float scale, DADamageType type);

        void PlayerObserverKillReceived(IntPtr observer, IntPtr killer, float damage, uint warhead, float scale, DADamageType type);

        void PlayerObserverCustom(IntPtr observer, IntPtr sender, int type, int param);

        void PlayerObserverPoked(IntPtr observer, IntPtr player);

        void PlayerObserverTimerExpired(IntPtr observer, int number, uint data);

        void PlayerObserverThink(IntPtr observer);


        // RenSharpConsoleFunctionClass
        void ConsoleFunctionDestructed(IntPtr function);

        void ConsoleFunctionActivate(IntPtr function, [MarshalAs(UnmanagedType.LPStr)] string pArgs);


        // RenSharpGameFeatureFactoryClass
        void GameFeatureFactoryDestructed(IntPtr factory);

        IntPtr GameFeatureFactoryCreateInstance(IntPtr factory);


	    // RenSharpGameFeatureClass
	    void GameFeatureDestructed(IntPtr gameFeature);

	    void GameFeatureInit(IntPtr gameFeature);


        // RenSharpPlayerDataFactoryClass
        void PlayerDataFactoryDestructed(IntPtr playerDataFactory);

	    IntPtr PlayerDataFactoryCreateData(IntPtr playerDataFactory);


	    // RenSharpPlayerDataClass
	    void PlayerDataDestructed(IntPtr playerData);

	    void PlayerDataInit(IntPtr playerData);

	    void PlayerDataClearLevel(IntPtr playerData);

	    void PlayerDataClearSession(IntPtr playerData);


        // RenSharpGameModeFactoryClass
        void GameModeFactoryDestructed(IntPtr factory);

	    IntPtr GameModeFactoryCreateInstance(IntPtr factory);


	    // RenSharpGameModeClass
	    void GameModeDestructed(IntPtr gameMode);

	    void GameModeInit(IntPtr gameMode);


        // RenSharpCrateModifierFactoryClass
        void CrateModifierFactoryDestructed(IntPtr factory);

        IntPtr CrateModifierFactoryCreate(IntPtr factory, [MarshalAs(UnmanagedType.LPStr)] string parameters);


	    // RenSharpCrateModifierClass
	    void CrateModifierDestructed(IntPtr crateModifier);

        void CrateModifierInit(IntPtr crateModifier, [MarshalAs(UnmanagedType.LPStr)] string parameters);

        void CrateModifierCalculateOdds(IntPtr crateModifier, ref float odds, IntPtr player);


        // RenSharpCrateClass
        void CrateDestructed(IntPtr crate);

        void CrateInit(IntPtr crate);

        void CrateSettingsLoaded(IntPtr crate);

        void CrateCalculateOdds(IntPtr crate, IntPtr player);

        [return: MarshalAs(UnmanagedType.Bool)]
        bool CrateCanActivate(IntPtr crate, IntPtr player);

        void CrateActivate(IntPtr crate, IntPtr player);


        // RenSharpCrateFactoryClass
        void CrateFactoryDestructed(IntPtr factory);

        IntPtr CrateFactoryCreateInstance(IntPtr factory);


        // RenSharpNodeClass
        void NodeDestructed(IntPtr node);

        void NodeInit(IntPtr node, IntPtr ini, [MarshalAs(UnmanagedType.LPStr)] string header);

        void NodeContestedEvent(IntPtr node);

        void NodeCaptureEvent(IntPtr node);
    }
}
