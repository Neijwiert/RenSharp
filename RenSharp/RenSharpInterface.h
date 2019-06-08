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

#include <unknwn.h>
#include <engine_ttdef.h>
#include <ConnectionAcceptanceFilter.h>
#include <da_event.h>
#include <cstdint>

class cPlayer;
class DATokenClass;
struct ConnectionRequest;
class BaseControllerClass;
class SoldierGameObjDef;
class VehicleGameObjDef;
class PowerUpGameObjDef;
class WeaponDefinitionClass;
class WeaponClass;
class BeaconGameObj;
class C4GameObj;
class SmartGameObj;
class DamageableGameObj;
class ArmedGameObj;
class ScriptZoneGameObj;
class PhysicalGameObj;
class ScriptableGameObj;
class VehicleGameObj;
class PowerUpGameObj;
class VehicleFactoryGameObj;
class RenSharpGameObjObserverClass;
class RenSharpPlayerObserverClass;
class RenSharpConsoleFunctionClass;
class RenSharpEventClass;
class RenSharpGameFeatureFactoryClass;
class DAGameFeatureClass;
class RenSharpGameFeatureClass;
class RenSharpPlayerDataFactoryClass;
class RenSharpPlayerDataClass;
class DAPlayerDataClass;
class RenSharpGameModeFactoryClass;
class DAGameModeClass;
class RenSharpGameModeClass;
class RenSharpCrateModifierFactoryClass;
class RenSharpCrateModifierClass;
class DACrateModifierClass;
class RenSharpCrateClass;
class RenSharpCrateFactoryClass;
class DACrateClass;
class RenSharpNodeClass;
class INIClass;

#define RENSHARP_GUID "E917FA9E-0909-4F70-AF1E-5E93467A30AB"

struct __declspec(uuid(RENSHARP_GUID)) RenSharpInterface;

struct RenSharpInterface : IUnknown
{
	// Other
	virtual HRESULT __stdcall FreePointer(void *ptr) = 0;
	virtual HRESULT __stdcall Init(BOOL *result) = 0;
	virtual HRESULT __stdcall Shutdown() = 0;

	// RenSharpEventClass
	virtual HRESULT __stdcall EventClassDestructed(RenSharpEventClass* eventClass) = 0;
	virtual HRESULT __stdcall EventClassSettingsLoadedEvent(RenSharpEventClass* eventClass) = 0;
	virtual HRESULT __stdcall EventClassChatEvent(RenSharpEventClass* eventClass, cPlayer *player, TextMessageEnum type, const wchar_t *message, int receiverID, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassChatCommandEvent(RenSharpEventClass* eventClass, cPlayer *player, TextMessageEnum type, const char *command, const DATokenClass *text, int receiverID, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassKeyHookEvent(RenSharpEventClass* eventClass, cPlayer *player, const char *key, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassHostChatEvent(RenSharpEventClass* eventClass, int id, TextMessageEnum type, const char *message, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassRadioEvent(RenSharpEventClass* eventClass, cPlayer *player, int playerType, int announcementID, int iconID, AnnouncementEnum announcementType, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassConnectionRequestEvent(RenSharpEventClass* eventClass, ConnectionRequest *request, wchar_t **refusalMessage, ConnectionAcceptanceFilter::STATUS *result) = 0;
	virtual HRESULT __stdcall EventClassPlayerPreJoinEvent(RenSharpEventClass* eventClass, ConnectionRequest *request) = 0;
	virtual HRESULT __stdcall EventClassPlayerJoinEvent(RenSharpEventClass* eventClass, cPlayer *player) = 0;
	virtual HRESULT __stdcall EventClassPlayerLeaveEvent(RenSharpEventClass* eventClass, cPlayer *player) = 0;
	virtual HRESULT __stdcall EventClassPlayerLoadedEvent(RenSharpEventClass* eventClass, cPlayer *player) = 0;
	virtual HRESULT __stdcall EventClassNameChangeEvent(RenSharpEventClass* eventClass, cPlayer *player) = 0;
	virtual HRESULT __stdcall EventClassLevelLoadedEvent(RenSharpEventClass* eventClass) = 0;
	virtual HRESULT __stdcall EventClassRemixEvent(RenSharpEventClass* eventClass) = 0;
	virtual HRESULT __stdcall EventClassRebalanceEvent(RenSharpEventClass* eventClass) = 0;
	virtual HRESULT __stdcall EventClassSwapEvent(RenSharpEventClass* eventClass) = 0;
	virtual HRESULT __stdcall EventClassGameOverEvent(RenSharpEventClass* eventClass) = 0;
	virtual HRESULT __stdcall EventClassConsoleOutputEvent(RenSharpEventClass* eventClass, const char *output) = 0;
	virtual HRESULT __stdcall EventClassRenLogEvent(RenSharpEventClass* eventClass, const char *output) = 0;
	virtual HRESULT __stdcall EventClassDALogEvent(RenSharpEventClass* eventClass, const char *header, const char *output) = 0;
	virtual HRESULT __stdcall EventClassCharacterPurchaseRequestEvent(RenSharpEventClass* eventClass, BaseControllerClass *base, cPlayer *player, float *cost, const SoldierGameObjDef *item, int *result) = 0;
	virtual HRESULT __stdcall EventClassVehiclePurchaseRequestEvent(RenSharpEventClass* eventClass, BaseControllerClass *base, cPlayer *player, float *cost, const VehicleGameObjDef *item, int *result) = 0;
	virtual HRESULT __stdcall EventClassPowerUpPurchaseRequestEvent(RenSharpEventClass* eventClass, BaseControllerClass *base, cPlayer *player, float *cost, const PowerUpGameObjDef *item, int *result) = 0;
	virtual HRESULT __stdcall EventClassCustomPurchaseRequestEvent(RenSharpEventClass* eventClass, BaseControllerClass *base, cPlayer *player, float *cost, unsigned int id, int *result) = 0;
	virtual HRESULT __stdcall EventClassCharacterPurchaseEvent(RenSharpEventClass* eventClass, cPlayer *player, float cost, const SoldierGameObjDef *item) = 0;
	virtual HRESULT __stdcall EventClassVehiclePurchaseEvent(RenSharpEventClass* eventClass, cPlayer *player, float cost, const VehicleGameObjDef *item) = 0;
	virtual HRESULT __stdcall EventClassPowerUpPurchaseEvent(RenSharpEventClass* eventClass, cPlayer *player, float cost, const PowerUpGameObjDef *item) = 0;
	virtual HRESULT __stdcall EventClassCustomPurchaseEvent(RenSharpEventClass* eventClass, cPlayer *player, float cost, unsigned int id) = 0;
	virtual HRESULT __stdcall EventClassRefillEvent(RenSharpEventClass* eventClass, cPlayer *player, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassSuicideEvent(RenSharpEventClass* eventClass, cPlayer *player, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassTeamChangeRequestEvent(RenSharpEventClass* eventClass, cPlayer *player, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassTeamChangeEvent(RenSharpEventClass* eventClass, cPlayer *player) = 0;
	virtual HRESULT __stdcall EventClassVehicleEntryRequestEvent(RenSharpEventClass* eventClass, VehicleGameObj *vehicle, cPlayer *player, int *seat, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassVehicleEnterEvent(RenSharpEventClass* eventClass, VehicleGameObj *vehicle, cPlayer *player, int seat) = 0;
	virtual HRESULT __stdcall EventClassVehicleExitEvent(RenSharpEventClass* eventClass, VehicleGameObj *vehicle, cPlayer *player, int seat) = 0;
	virtual HRESULT __stdcall EventClassPowerUpGrantRequestEvent(RenSharpEventClass* eventClass, cPlayer *player, const PowerUpGameObjDef *powerUp, PowerUpGameObj *powerUpObj, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassPowerUpGrantEvent(RenSharpEventClass* eventClass, cPlayer *player, const PowerUpGameObjDef *powerUp, PowerUpGameObj *powerUpObj) = 0;
	virtual HRESULT __stdcall EventClassAddWeaponRequestEvent(RenSharpEventClass* eventClass, cPlayer *player, const WeaponDefinitionClass *weapon, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassAddWeaponEvent(RenSharpEventClass* eventClass, cPlayer *player, WeaponClass *weapon) = 0;
	virtual HRESULT __stdcall EventClassRemoveWeaponEvent(RenSharpEventClass* eventClass, cPlayer *player, WeaponClass *weapon) = 0;
	virtual HRESULT __stdcall EventClassClearWeaponsEvent(RenSharpEventClass* eventClass, cPlayer *player) = 0;
	virtual HRESULT __stdcall EventClassBeaconDeployEvent(RenSharpEventClass* eventClass, BeaconGameObj *beacon) = 0;
	virtual HRESULT __stdcall EventClassBeaconDetonateEvent(RenSharpEventClass* eventClass, BeaconGameObj *beacon) = 0;
	virtual HRESULT __stdcall EventClassC4DetonateRequestEvent(RenSharpEventClass* eventClass, C4GameObj *c4, SmartGameObj *triggerer, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassC4DetonateEvent(RenSharpEventClass* eventClass, C4GameObj *c4) = 0;
	virtual HRESULT __stdcall EventClassChangeCharacterEvent(RenSharpEventClass* eventClass, cPlayer *player, const SoldierGameObjDef *soldier) = 0;
	virtual HRESULT __stdcall EventClassVehicleFlipEvent(RenSharpEventClass* eventClass, VehicleGameObj *vehicle, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassRequestVehicleEvent(RenSharpEventClass* eventClass, VehicleFactoryGameObj *factory, const VehicleGameObjDef *vehicle, cPlayer *player, float delay, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassThink(RenSharpEventClass* eventClass) = 0;
	virtual HRESULT __stdcall EventClassObjectCreatedEvent(RenSharpEventClass* eventClass, ScriptableGameObj *obj) = 0;
	virtual HRESULT __stdcall EventClassStockClientDamageRequestEvent(RenSharpEventClass* eventClass, DamageableGameObj *victim, ArmedGameObj *damager, float damage, uint warhead, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassTTClientDamageRequestEvent(RenSharpEventClass* eventClass, DamageableGameObj *victim, ArmedGameObj *damager, const AmmoDefinitionClass *ammo, const char *bone, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassDamageRequestEvent(RenSharpEventClass* eventClass, DamageableGameObj *victim, ArmedGameObj *damager, float *damage, unsigned int *warhead, float scale, DADamageType::Type type, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassDamageEvent(RenSharpEventClass* eventClass, DamageableGameObj *victim, ArmedGameObj *damager, float damage, unsigned int warhead, float scale, DADamageType::Type type) = 0;
	virtual HRESULT __stdcall EventClassKillEvent(RenSharpEventClass* eventClass, DamageableGameObj *victim, ArmedGameObj *killer, float damage, unsigned int warhead, float scale, DADamageType::Type type) = 0;
	virtual HRESULT __stdcall EventClassCustomEvent(RenSharpEventClass* eventClass, ScriptableGameObj *obj, int type, int param, ScriptableGameObj *sender) = 0;
	virtual HRESULT __stdcall EventClassPokeEvent(RenSharpEventClass* eventClass, cPlayer *player, PhysicalGameObj *obj) = 0;
	virtual HRESULT __stdcall EventClassZoneEnterEvent(RenSharpEventClass* eventClass, ScriptZoneGameObj *obj, PhysicalGameObj *enterer) = 0;
	virtual HRESULT __stdcall EventClassZoneExitEvent(RenSharpEventClass* eventClass, ScriptZoneGameObj *obj, PhysicalGameObj *exiter) = 0;
	virtual HRESULT __stdcall EventClassObjectDestroyedEvent(RenSharpEventClass* eventClass, ScriptableGameObj *obj) = 0;
	virtual HRESULT __stdcall EventClassTimerExpired(RenSharpEventClass* eventClass, int number, unsigned int data) = 0;

	// RenSharpGameObjObserverClass
	virtual HRESULT __stdcall ObserverDestructed(RenSharpGameObjObserverClass *observer) = 0;
	virtual HRESULT __stdcall ObserverDestroyed(RenSharpGameObjObserverClass *observer, GameObject *obj) = 0;
	virtual HRESULT __stdcall ObserverCustom(RenSharpGameObjObserverClass *observer, GameObject *obj, int message, int param, GameObject *sender) = 0;
	virtual HRESULT __stdcall ObserverPoked(RenSharpGameObjObserverClass *observer, GameObject *obj, GameObject *poker) = 0;
	virtual HRESULT __stdcall ObserverEntered(RenSharpGameObjObserverClass *observer, GameObject *obj, GameObject *enterer) = 0;
	virtual HRESULT __stdcall ObserverExited(RenSharpGameObjObserverClass *observer, GameObject *obj, GameObject *exiter) = 0;
	virtual HRESULT __stdcall ObserverSoundHeard(RenSharpGameObjObserverClass *observer, GameObject *obj, const CombatSound *sound) = 0;
	virtual HRESULT __stdcall ObserverEnemySeen(RenSharpGameObjObserverClass *observer, GameObject *obj, GameObject *enemy) = 0;
	virtual HRESULT __stdcall ObserverActionComplete(RenSharpGameObjObserverClass *observer, GameObject *obj, int actionID, ActionCompleteReason completeReason) = 0;
	virtual HRESULT __stdcall ObserverTimerExpired(RenSharpGameObjObserverClass *observer, GameObject *obj, int number) = 0;
	virtual HRESULT __stdcall ObserverAnimationComplete(RenSharpGameObjObserverClass *observer, GameObject *obj, const char *name) = 0;
	virtual HRESULT __stdcall ObserverInit(RenSharpGameObjObserverClass *observer) = 0;
	virtual HRESULT __stdcall ObserverVehicleEntryRequest1(RenSharpGameObjObserverClass *observer, cPlayer *player, int *seat, BOOL *result) = 0;
	virtual HRESULT __stdcall ObserverVehicleEntryRequest2(RenSharpGameObjObserverClass *observer, VehicleGameObj *vehicle, int *seat, BOOL *result) = 0;
	virtual HRESULT __stdcall ObserverVehicleEnter1(RenSharpGameObjObserverClass *observer, cPlayer *player, int seat) = 0;
	virtual HRESULT __stdcall ObserverVehicleEnter2(RenSharpGameObjObserverClass *observer, VehicleGameObj *vehicle, int seat) = 0;
	virtual HRESULT __stdcall ObserverVehicleExit1(RenSharpGameObjObserverClass *observer, cPlayer *player, int seat) = 0;
	virtual HRESULT __stdcall ObserverVehicleExit2(RenSharpGameObjObserverClass *observer, VehicleGameObj *vehicle, int seat) = 0;
	virtual HRESULT __stdcall ObserverVehicleFlip(RenSharpGameObjObserverClass *observer, BOOL *result) = 0;
	virtual HRESULT __stdcall ObserverDamageDealtRequest(RenSharpGameObjObserverClass *observer, DamageableGameObj *victim, float *damage, unsigned int *warhead, float scale, DADamageType::Type type, BOOL *result) = 0;
	virtual HRESULT __stdcall ObserverDamageReceivedRequest(RenSharpGameObjObserverClass *observer, ArmedGameObj *damager, float *damage, unsigned int *warhead, float scale, DADamageType::Type type, BOOL *result) = 0;
	virtual HRESULT __stdcall ObserverDamageDealt(RenSharpGameObjObserverClass *observer, DamageableGameObj *victim, float damage, unsigned int warhead, float scale, DADamageType::Type type) = 0;
	virtual HRESULT __stdcall ObserverDamageReceived(RenSharpGameObjObserverClass *observer, ArmedGameObj *damager, float damage, unsigned int warhead, float scale, DADamageType::Type type) = 0;
	virtual HRESULT __stdcall ObserverKillDealt(RenSharpGameObjObserverClass *observer, DamageableGameObj *victim, float damage, unsigned int warhead, float scale, DADamageType::Type type) = 0;
	virtual HRESULT __stdcall ObserverKillReceived(RenSharpGameObjObserverClass *observer, ArmedGameObj *killer, float damage, unsigned int warhead, float scale, DADamageType::Type type) = 0;
	virtual HRESULT __stdcall ObserverPowerUpGrantRequest1(RenSharpGameObjObserverClass *observer, cPlayer *player, BOOL *result) = 0;
	virtual HRESULT __stdcall ObserverPowerUpGrantRequest2(RenSharpGameObjObserverClass *observer, const PowerUpGameObjDef *powerUp, PowerUpGameObj *powerUpObj, BOOL *result) = 0;
	virtual HRESULT __stdcall ObserverPowerUpGrant1(RenSharpGameObjObserverClass *observer, cPlayer *player) = 0;
	virtual HRESULT __stdcall ObserverPowerUpGrant2(RenSharpGameObjObserverClass *observer, const PowerUpGameObjDef *powerUp, PowerUpGameObj *powerUpObj) = 0;
	virtual HRESULT __stdcall ObserverAddWeaponRequest(RenSharpGameObjObserverClass *observer, const WeaponDefinitionClass *weapon, BOOL *result) = 0;
	virtual HRESULT __stdcall ObserverAddWeapon(RenSharpGameObjObserverClass *observer, WeaponClass *weapon) = 0;
	virtual HRESULT __stdcall ObserverRemoveWeapon(RenSharpGameObjObserverClass *observer, WeaponClass *weapon) = 0;
	virtual HRESULT __stdcall ObserverClearWeapons(RenSharpGameObjObserverClass *observer) = 0;

	// RenSharpPlayerObserverClass
	virtual HRESULT __stdcall PlayerObserverDestructed(RenSharpPlayerObserverClass *observer) = 0;
	virtual HRESULT __stdcall PlayerObserverInit(RenSharpPlayerObserverClass *observer) = 0;
	virtual HRESULT __stdcall PlayerObserverJoin(RenSharpPlayerObserverClass *observer) = 0;
	virtual HRESULT __stdcall PlayerObserverLeave(RenSharpPlayerObserverClass *observer) = 0;
	virtual HRESULT __stdcall PlayerObserverLevelLoaded(RenSharpPlayerObserverClass *observer) = 0;
	virtual HRESULT __stdcall PlayerObserverPlayerLoaded(RenSharpPlayerObserverClass *observer) = 0;
	virtual HRESULT __stdcall PlayerObserverNameChange(RenSharpPlayerObserverClass *observer) = 0;
	virtual HRESULT __stdcall PlayerObserverTeamChange(RenSharpPlayerObserverClass *observer) = 0;
	virtual HRESULT __stdcall PlayerObserverCharacterPurchaseRequest(RenSharpPlayerObserverClass *observer, float *cost, const SoldierGameObjDef *item, int *result) = 0;
	virtual HRESULT __stdcall PlayerObserverVehiclePurchaseRequest(RenSharpPlayerObserverClass *observer, float *cost, const VehicleGameObjDef *item, int *result) = 0;
	virtual HRESULT __stdcall PlayerObserverPowerUpPurchaseRequest(RenSharpPlayerObserverClass *observer, float *cost, const PowerUpGameObjDef *item, int *result) = 0;
	virtual HRESULT __stdcall PlayerObserverCustomPurchaseRequest(RenSharpPlayerObserverClass *observer, float *cost, unsigned int id, int *result) = 0;
	virtual HRESULT __stdcall PlayerObserverCharacterPurchase(RenSharpPlayerObserverClass *observer, float cost, const SoldierGameObjDef *item) = 0;
	virtual HRESULT __stdcall PlayerObserverVehiclePurchase(RenSharpPlayerObserverClass *observer, float cost, const VehicleGameObjDef *item) = 0;
	virtual HRESULT __stdcall PlayerObserverPowerUpPurchase(RenSharpPlayerObserverClass *observer, float cost, const PowerUpGameObjDef *item) = 0;
	virtual HRESULT __stdcall PlayerObserverCustomPurchase(RenSharpPlayerObserverClass *observer, float cost, unsigned int id) = 0;
	virtual HRESULT __stdcall PlayerObserverVehicleEntryRequest(RenSharpPlayerObserverClass *observer, VehicleGameObj *vehicle, int *seat, BOOL *result) = 0;
	virtual HRESULT __stdcall PlayerObserverVehicleEnter(RenSharpPlayerObserverClass *observer, VehicleGameObj *vehicle, int seat) = 0;
	virtual HRESULT __stdcall PlayerObserverVehicleExit(RenSharpPlayerObserverClass *observer, VehicleGameObj *vehicle, int seat) = 0;
	virtual HRESULT __stdcall PlayerObserverPowerUpGrantRequest(RenSharpPlayerObserverClass *observer, const PowerUpGameObjDef *powerUp, PowerUpGameObj *powerUpObj, BOOL *result) = 0;
	virtual HRESULT __stdcall PlayerObserverPowerUpGrant(RenSharpPlayerObserverClass *observer, const PowerUpGameObjDef *powerUp, PowerUpGameObj *powerUpObj) = 0;
	virtual HRESULT __stdcall PlayerObserverAddWeaponRequest(RenSharpPlayerObserverClass *observer, const WeaponDefinitionClass *weapon, BOOL *result) = 0;
	virtual HRESULT __stdcall PlayerObserverAddWeapon(RenSharpPlayerObserverClass *observer, WeaponClass *weapon) = 0;
	virtual HRESULT __stdcall PlayerObserverRemoveWeapon(RenSharpPlayerObserverClass *observer, WeaponClass *weapon) = 0;
	virtual HRESULT __stdcall PlayerObserverClearWeapons(RenSharpPlayerObserverClass *observer) = 0;
	virtual HRESULT __stdcall PlayerObserverC4DetonateRequest(RenSharpPlayerObserverClass *observer, C4GameObj *c4, BOOL *result) = 0;
	virtual HRESULT __stdcall PlayerObserverC4Detonate(RenSharpPlayerObserverClass *observer, C4GameObj *c4) = 0;
	virtual HRESULT __stdcall PlayerObserverChangeCharacter(RenSharpPlayerObserverClass *observer, const SoldierGameObjDef *soldier) = 0;
	virtual HRESULT __stdcall PlayerObserverCreated(RenSharpPlayerObserverClass *observer) = 0;
	virtual HRESULT __stdcall PlayerObserverDestroyed(RenSharpPlayerObserverClass *observer) = 0;
	virtual HRESULT __stdcall PlayerObserverDamageDealtRequest(RenSharpPlayerObserverClass *observer, DamageableGameObj *victim, float *damage, unsigned int *warhead, float scale, DADamageType::Type type, BOOL *result) = 0;
	virtual HRESULT __stdcall PlayerObserverDamageReceivedRequest(RenSharpPlayerObserverClass *observer, ArmedGameObj *damager, float *damage, unsigned int *warhead, float scale, DADamageType::Type type, BOOL *result) = 0;
	virtual HRESULT __stdcall PlayerObserverDamageDealt(RenSharpPlayerObserverClass *observer, DamageableGameObj *victim, float damage, unsigned int warhead, float scale, DADamageType::Type type) = 0;
	virtual HRESULT __stdcall PlayerObserverDamageReceived(RenSharpPlayerObserverClass *observer, ArmedGameObj *damager, float damage, unsigned int warhead, float scale, DADamageType::Type type) = 0;
	virtual HRESULT __stdcall PlayerObserverKillDealt(RenSharpPlayerObserverClass *observer, DamageableGameObj *victim, float damage, unsigned int warhead, float scale, DADamageType::Type type) = 0;
	virtual HRESULT __stdcall PlayerObserverKillReceived(RenSharpPlayerObserverClass *observer, ArmedGameObj *killer, float damage, unsigned int warhead, float scale, DADamageType::Type type) = 0;
	virtual HRESULT __stdcall PlayerObserverCustom(RenSharpPlayerObserverClass *observer, GameObject *sender, int type, int param) = 0;
	virtual HRESULT __stdcall PlayerObserverPoked(RenSharpPlayerObserverClass *observer, cPlayer *player) = 0;
	virtual HRESULT __stdcall PlayerObserverTimerExpired(RenSharpPlayerObserverClass *observer, int number, unsigned int data) = 0;
	virtual HRESULT __stdcall PlayerObserverThink(RenSharpPlayerObserverClass *observer) = 0;

	// RenSharpConsoleFunctionClass
	virtual HRESULT __stdcall ConsoleFunctionDestructed(RenSharpConsoleFunctionClass *function) = 0;
	virtual HRESULT __stdcall ConsoleFunctionActivate(RenSharpConsoleFunctionClass *function, const char *pArgs) = 0;

	// RenSharpGameFeatureFactoryClass
	virtual HRESULT __stdcall GameFeatureFactoryDestructed(RenSharpGameFeatureFactoryClass* factory) = 0;
	virtual HRESULT __stdcall GameFeatureFactoryCreateInstance(RenSharpGameFeatureFactoryClass* factory, DAGameFeatureClass** result) = 0;

	// RenSharpGameFeatureClass
	virtual HRESULT __stdcall GameFeatureDestructed(RenSharpGameFeatureClass* gameFeature) = 0;
	virtual HRESULT __stdcall GameFeatureInit(RenSharpGameFeatureClass* gameFeature) = 0;

	// RenSharpPlayerDataFactoryClass
	virtual HRESULT __stdcall PlayerDataFactoryDestructed(RenSharpPlayerDataFactoryClass* playerDataFactory) = 0;
	virtual HRESULT __stdcall PlayerDataFactoryCreateData(RenSharpPlayerDataFactoryClass* playerDataFactory, DAPlayerDataClass** result) = 0;

	// RenSharpPlayerDataClass
	virtual HRESULT __stdcall PlayerDataDestructed(RenSharpPlayerDataClass* playerData) = 0;
	virtual HRESULT __stdcall PlayerDataInit(RenSharpPlayerDataClass* playerData) = 0;
	virtual HRESULT __stdcall PlayerDataClearLevel(RenSharpPlayerDataClass* playerData) = 0;
	virtual HRESULT __stdcall PlayerDataClearSession(RenSharpPlayerDataClass* playerData) = 0;

	// RenSharpGameModeFactoryClass
	virtual HRESULT __stdcall GameModeFactoryDestructed(RenSharpGameModeFactoryClass* factory) = 0;
	virtual HRESULT __stdcall GameModeFactoryCreateInstance(RenSharpGameModeFactoryClass* factory, DAGameModeClass** result) = 0;

	// RenSharpGameModeClass
	virtual HRESULT __stdcall GameModeDestructed(RenSharpGameModeClass* gameMode) = 0;
	virtual HRESULT __stdcall GameModeInit(RenSharpGameModeClass* gameMode) = 0;

	// RenSharpCrateModifierFactoryClass
	virtual HRESULT __stdcall CrateModifierFactoryDestructed(RenSharpCrateModifierFactoryClass* factory);
	virtual HRESULT __stdcall CrateModifierFactoryCreate(RenSharpCrateModifierFactoryClass* factory, const char* parameters, DACrateModifierClass** result);

	// RenSharpCrateModifierClass
	virtual HRESULT __stdcall CrateModifierDestructed(RenSharpCrateModifierClass* crateModifier);
	virtual HRESULT __stdcall CrateModifierInit(RenSharpCrateModifierClass* crateModifier, const char* parameters);
	virtual HRESULT __stdcall CrateModifierCalculateOdds(RenSharpCrateModifierClass* crateModifier, float* odds, cPlayer* player);

	// RenSharpCrateClass
	virtual HRESULT __stdcall CrateDestructed(RenSharpCrateClass* crate);
	virtual HRESULT __stdcall CrateInit(RenSharpCrateClass* crate);
	virtual HRESULT __stdcall CrateSettingsLoaded(RenSharpCrateClass* crate);
	virtual HRESULT __stdcall CrateCalculateOdds(RenSharpCrateClass* crate, cPlayer* player);
	virtual HRESULT __stdcall CrateCanActivate(RenSharpCrateClass* crate, cPlayer* player, BOOL* result);
	virtual HRESULT __stdcall CrateActivate(RenSharpCrateClass* crate, cPlayer* player);

	// RenSharpCrateFactoryClass
	virtual HRESULT __stdcall CrateFactoryDestructed(RenSharpCrateFactoryClass* factory);
	virtual HRESULT __stdcall CrateFactoryCreateInstance(RenSharpCrateFactoryClass* factory, DACrateClass** result);

	// RenSharpNodeClass
	virtual HRESULT __stdcall NodeDestructed(RenSharpNodeClass* node);
	virtual HRESULT __stdcall NodeInit(RenSharpNodeClass* node, const INIClass* ini, const char* header);
	virtual HRESULT __stdcall NodeContestedEvent(RenSharpNodeClass* node);
	virtual HRESULT __stdcall NodeCaptureEvent(RenSharpNodeClass* node);
};