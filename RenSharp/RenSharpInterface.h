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
	virtual HRESULT __stdcall EventClassCharacterPurchaseRequestEvent(RenSharpEventClass* eventClass, BaseControllerClass *base, cPlayer *player, float *cost, const DefinitionClass *item, int *result) = 0;
	virtual HRESULT __stdcall EventClassVehiclePurchaseRequestEvent(RenSharpEventClass* eventClass, BaseControllerClass *base, cPlayer *player, float *cost, const DefinitionClass* item, int *result) = 0;
	virtual HRESULT __stdcall EventClassPowerUpPurchaseRequestEvent(RenSharpEventClass* eventClass, BaseControllerClass *base, cPlayer *player, float *cost, const DefinitionClass* item, int *result) = 0;
	virtual HRESULT __stdcall EventClassCustomPurchaseRequestEvent(RenSharpEventClass* eventClass, BaseControllerClass *base, cPlayer *player, float *cost, unsigned int id, int *result) = 0;
	virtual HRESULT __stdcall EventClassCharacterPurchaseEvent(RenSharpEventClass* eventClass, cPlayer *player, float cost, const DefinitionClass* item) = 0;
	virtual HRESULT __stdcall EventClassVehiclePurchaseEvent(RenSharpEventClass* eventClass, cPlayer *player, float cost, const DefinitionClass* item) = 0;
	virtual HRESULT __stdcall EventClassPowerUpPurchaseEvent(RenSharpEventClass* eventClass, cPlayer *player, float cost, const DefinitionClass* item) = 0;
	virtual HRESULT __stdcall EventClassCustomPurchaseEvent(RenSharpEventClass* eventClass, cPlayer *player, float cost, unsigned int id) = 0;
	virtual HRESULT __stdcall EventClassRefillEvent(RenSharpEventClass* eventClass, cPlayer *player, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassSuicideEvent(RenSharpEventClass* eventClass, cPlayer *player, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassTeamChangeRequestEvent(RenSharpEventClass* eventClass, cPlayer *player, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassTeamChangeEvent(RenSharpEventClass* eventClass, cPlayer *player) = 0;
	virtual HRESULT __stdcall EventClassVehicleEntryRequestEvent(RenSharpEventClass* eventClass, BaseGameObj *vehicle, cPlayer *player, int *seat, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassVehicleEnterEvent(RenSharpEventClass* eventClass, BaseGameObj* vehicle, cPlayer *player, int seat) = 0;
	virtual HRESULT __stdcall EventClassVehicleExitEvent(RenSharpEventClass* eventClass, BaseGameObj* vehicle, cPlayer *player, int seat) = 0;
	virtual HRESULT __stdcall EventClassPowerUpGrantRequestEvent(RenSharpEventClass* eventClass, cPlayer *player, const DefinitionClass *powerUp, BaseGameObj* powerUpObj, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassPowerUpGrantEvent(RenSharpEventClass* eventClass, cPlayer *player, const DefinitionClass *powerUp, BaseGameObj *powerUpObj) = 0;
	virtual HRESULT __stdcall EventClassAddWeaponRequestEvent(RenSharpEventClass* eventClass, cPlayer *player, const DefinitionClass *weapon, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassAddWeaponEvent(RenSharpEventClass* eventClass, cPlayer *player, WeaponClass *weapon) = 0;
	virtual HRESULT __stdcall EventClassRemoveWeaponEvent(RenSharpEventClass* eventClass, cPlayer *player, WeaponClass *weapon) = 0;
	virtual HRESULT __stdcall EventClassClearWeaponsEvent(RenSharpEventClass* eventClass, cPlayer *player) = 0;
	virtual HRESULT __stdcall EventClassBeaconDeployEvent(RenSharpEventClass* eventClass, BaseGameObj *beacon) = 0;
	virtual HRESULT __stdcall EventClassBeaconDetonateEvent(RenSharpEventClass* eventClass, BaseGameObj *beacon) = 0;
	virtual HRESULT __stdcall EventClassC4DetonateRequestEvent(RenSharpEventClass* eventClass, BaseGameObj *c4, BaseGameObj *triggerer, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassC4DetonateEvent(RenSharpEventClass* eventClass, BaseGameObj *c4) = 0;
	virtual HRESULT __stdcall EventClassChangeCharacterEvent(RenSharpEventClass* eventClass, cPlayer *player, const DefinitionClass *soldier) = 0;
	virtual HRESULT __stdcall EventClassVehicleFlipEvent(RenSharpEventClass* eventClass, BaseGameObj *vehicle, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassRequestVehicleEvent(RenSharpEventClass* eventClass, BaseGameObj *factory, const DefinitionClass *vehicle, cPlayer *player, float delay, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassThink(RenSharpEventClass* eventClass) = 0;
	virtual HRESULT __stdcall EventClassObjectCreatedEvent(RenSharpEventClass* eventClass, BaseGameObj *obj) = 0;
	virtual HRESULT __stdcall EventClassStockClientDamageRequestEvent(RenSharpEventClass* eventClass, BaseGameObj *victim, BaseGameObj *damager, float damage, uint warhead, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassTTClientDamageRequestEvent(RenSharpEventClass* eventClass, BaseGameObj *victim, BaseGameObj *damager, const DefinitionClass *ammo, const char *bone, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassDamageRequestEvent(RenSharpEventClass* eventClass, BaseGameObj *victim, BaseGameObj *damager, float *damage, unsigned int *warhead, float scale, DADamageType::Type type, BOOL *result) = 0;
	virtual HRESULT __stdcall EventClassDamageEvent(RenSharpEventClass* eventClass, BaseGameObj *victim, BaseGameObj *damager, float damage, unsigned int warhead, float scale, DADamageType::Type type) = 0;
	virtual HRESULT __stdcall EventClassKillEvent(RenSharpEventClass* eventClass, BaseGameObj *victim, BaseGameObj *killer, float damage, unsigned int warhead, float scale, DADamageType::Type type) = 0;
	virtual HRESULT __stdcall EventClassCustomEvent(RenSharpEventClass* eventClass, BaseGameObj *obj, int type, int param, BaseGameObj *sender) = 0;
	virtual HRESULT __stdcall EventClassPokeEvent(RenSharpEventClass* eventClass, cPlayer *player, BaseGameObj *obj) = 0;
	virtual HRESULT __stdcall EventClassZoneEnterEvent(RenSharpEventClass* eventClass, BaseGameObj *obj, BaseGameObj *enterer) = 0;
	virtual HRESULT __stdcall EventClassZoneExitEvent(RenSharpEventClass* eventClass, BaseGameObj *obj, BaseGameObj *exiter) = 0;
	virtual HRESULT __stdcall EventClassObjectDestroyedEvent(RenSharpEventClass* eventClass, BaseGameObj *obj) = 0;
	virtual HRESULT __stdcall EventClassTimerExpired(RenSharpEventClass* eventClass, int number, unsigned int data) = 0;

	// RenSharpGameObjObserverClass
	virtual HRESULT __stdcall ObserverDestructed(RenSharpGameObjObserverClass *observer) = 0;
	virtual HRESULT __stdcall ObserverDestroyed(RenSharpGameObjObserverClass *observer, BaseGameObj *obj) = 0;
	virtual HRESULT __stdcall ObserverCustom(RenSharpGameObjObserverClass *observer, BaseGameObj *obj, int message, int param, BaseGameObj *sender) = 0;
	virtual HRESULT __stdcall ObserverPoked(RenSharpGameObjObserverClass *observer, BaseGameObj *obj, BaseGameObj *poker) = 0;
	virtual HRESULT __stdcall ObserverEntered(RenSharpGameObjObserverClass *observer, BaseGameObj *obj, BaseGameObj *enterer) = 0;
	virtual HRESULT __stdcall ObserverExited(RenSharpGameObjObserverClass *observer, BaseGameObj *obj, BaseGameObj *exiter) = 0;
	virtual HRESULT __stdcall ObserverSoundHeard(RenSharpGameObjObserverClass *observer, BaseGameObj *obj, const CombatSound *sound) = 0;
	virtual HRESULT __stdcall ObserverEnemySeen(RenSharpGameObjObserverClass *observer, BaseGameObj *obj, BaseGameObj *enemy) = 0;
	virtual HRESULT __stdcall ObserverActionComplete(RenSharpGameObjObserverClass *observer, BaseGameObj *obj, int actionID, ActionCompleteReason completeReason) = 0;
	virtual HRESULT __stdcall ObserverTimerExpired(RenSharpGameObjObserverClass *observer, BaseGameObj *obj, int number) = 0;
	virtual HRESULT __stdcall ObserverAnimationComplete(RenSharpGameObjObserverClass *observer, BaseGameObj *obj, const char *name) = 0;
	virtual HRESULT __stdcall ObserverInit(RenSharpGameObjObserverClass *observer) = 0;
	virtual HRESULT __stdcall ObserverVehicleEntryRequest1(RenSharpGameObjObserverClass *observer, cPlayer *player, int *seat, BOOL *result) = 0;
	virtual HRESULT __stdcall ObserverVehicleEntryRequest2(RenSharpGameObjObserverClass *observer, BaseGameObj *vehicle, int *seat, BOOL *result) = 0;
	virtual HRESULT __stdcall ObserverVehicleEnter1(RenSharpGameObjObserverClass *observer, cPlayer *player, int seat) = 0;
	virtual HRESULT __stdcall ObserverVehicleEnter2(RenSharpGameObjObserverClass *observer, BaseGameObj *vehicle, int seat) = 0;
	virtual HRESULT __stdcall ObserverVehicleExit1(RenSharpGameObjObserverClass *observer, cPlayer *player, int seat) = 0;
	virtual HRESULT __stdcall ObserverVehicleExit2(RenSharpGameObjObserverClass *observer, BaseGameObj *vehicle, int seat) = 0;
	virtual HRESULT __stdcall ObserverVehicleFlip(RenSharpGameObjObserverClass *observer, BOOL *result) = 0;
	virtual HRESULT __stdcall ObserverDamageDealtRequest(RenSharpGameObjObserverClass *observer, BaseGameObj *victim, float *damage, unsigned int *warhead, float scale, DADamageType::Type type, BOOL *result) = 0;
	virtual HRESULT __stdcall ObserverDamageReceivedRequest(RenSharpGameObjObserverClass *observer, BaseGameObj *damager, float *damage, unsigned int *warhead, float scale, DADamageType::Type type, BOOL *result) = 0;
	virtual HRESULT __stdcall ObserverDamageDealt(RenSharpGameObjObserverClass *observer, BaseGameObj *victim, float damage, unsigned int warhead, float scale, DADamageType::Type type) = 0;
	virtual HRESULT __stdcall ObserverDamageReceived(RenSharpGameObjObserverClass *observer, BaseGameObj *damager, float damage, unsigned int warhead, float scale, DADamageType::Type type) = 0;
	virtual HRESULT __stdcall ObserverKillDealt(RenSharpGameObjObserverClass *observer, BaseGameObj *victim, float damage, unsigned int warhead, float scale, DADamageType::Type type) = 0;
	virtual HRESULT __stdcall ObserverKillReceived(RenSharpGameObjObserverClass *observer, BaseGameObj *killer, float damage, unsigned int warhead, float scale, DADamageType::Type type) = 0;
	virtual HRESULT __stdcall ObserverPowerUpGrantRequest1(RenSharpGameObjObserverClass *observer, cPlayer *player, BOOL *result) = 0;
	virtual HRESULT __stdcall ObserverPowerUpGrantRequest2(RenSharpGameObjObserverClass *observer, const DefinitionClass *powerUp, BaseGameObj *powerUpObj, BOOL *result) = 0;
	virtual HRESULT __stdcall ObserverPowerUpGrant1(RenSharpGameObjObserverClass *observer, cPlayer *player) = 0;
	virtual HRESULT __stdcall ObserverPowerUpGrant2(RenSharpGameObjObserverClass *observer, const DefinitionClass *powerUp, BaseGameObj *powerUpObj) = 0;
	virtual HRESULT __stdcall ObserverAddWeaponRequest(RenSharpGameObjObserverClass *observer, const DefinitionClass *weapon, BOOL *result) = 0;
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
	virtual HRESULT __stdcall PlayerObserverCharacterPurchaseRequest(RenSharpPlayerObserverClass *observer, float *cost, const DefinitionClass *item, int *result) = 0;
	virtual HRESULT __stdcall PlayerObserverVehiclePurchaseRequest(RenSharpPlayerObserverClass *observer, float *cost, const DefinitionClass *item, int *result) = 0;
	virtual HRESULT __stdcall PlayerObserverPowerUpPurchaseRequest(RenSharpPlayerObserverClass *observer, float *cost, const DefinitionClass *item, int *result) = 0;
	virtual HRESULT __stdcall PlayerObserverCustomPurchaseRequest(RenSharpPlayerObserverClass *observer, float *cost, unsigned int id, int *result) = 0;
	virtual HRESULT __stdcall PlayerObserverCharacterPurchase(RenSharpPlayerObserverClass *observer, float cost, const DefinitionClass *item) = 0;
	virtual HRESULT __stdcall PlayerObserverVehiclePurchase(RenSharpPlayerObserverClass *observer, float cost, const DefinitionClass *item) = 0;
	virtual HRESULT __stdcall PlayerObserverPowerUpPurchase(RenSharpPlayerObserverClass *observer, float cost, const DefinitionClass *item) = 0;
	virtual HRESULT __stdcall PlayerObserverCustomPurchase(RenSharpPlayerObserverClass *observer, float cost, unsigned int id) = 0;
	virtual HRESULT __stdcall PlayerObserverVehicleEntryRequest(RenSharpPlayerObserverClass *observer, BaseGameObj *vehicle, int *seat, BOOL *result) = 0;
	virtual HRESULT __stdcall PlayerObserverVehicleEnter(RenSharpPlayerObserverClass *observer, BaseGameObj *vehicle, int seat) = 0;
	virtual HRESULT __stdcall PlayerObserverVehicleExit(RenSharpPlayerObserverClass *observer, BaseGameObj *vehicle, int seat) = 0;
	virtual HRESULT __stdcall PlayerObserverPowerUpGrantRequest(RenSharpPlayerObserverClass *observer, const DefinitionClass *powerUp, BaseGameObj *powerUpObj, BOOL *result) = 0;
	virtual HRESULT __stdcall PlayerObserverPowerUpGrant(RenSharpPlayerObserverClass *observer, const DefinitionClass *powerUp, BaseGameObj *powerUpObj) = 0;
	virtual HRESULT __stdcall PlayerObserverAddWeaponRequest(RenSharpPlayerObserverClass *observer, const DefinitionClass *weapon, BOOL *result) = 0;
	virtual HRESULT __stdcall PlayerObserverAddWeapon(RenSharpPlayerObserverClass *observer, WeaponClass *weapon) = 0;
	virtual HRESULT __stdcall PlayerObserverRemoveWeapon(RenSharpPlayerObserverClass *observer, WeaponClass *weapon) = 0;
	virtual HRESULT __stdcall PlayerObserverClearWeapons(RenSharpPlayerObserverClass *observer) = 0;
	virtual HRESULT __stdcall PlayerObserverC4DetonateRequest(RenSharpPlayerObserverClass *observer, BaseGameObj *c4, BOOL *result) = 0;
	virtual HRESULT __stdcall PlayerObserverC4Detonate(RenSharpPlayerObserverClass *observer, BaseGameObj *c4) = 0;
	virtual HRESULT __stdcall PlayerObserverChangeCharacter(RenSharpPlayerObserverClass *observer, const DefinitionClass *soldier) = 0;
	virtual HRESULT __stdcall PlayerObserverCreated(RenSharpPlayerObserverClass *observer) = 0;
	virtual HRESULT __stdcall PlayerObserverDestroyed(RenSharpPlayerObserverClass *observer) = 0;
	virtual HRESULT __stdcall PlayerObserverDamageDealtRequest(RenSharpPlayerObserverClass *observer, BaseGameObj *victim, float *damage, unsigned int *warhead, float scale, DADamageType::Type type, BOOL *result) = 0;
	virtual HRESULT __stdcall PlayerObserverDamageReceivedRequest(RenSharpPlayerObserverClass *observer, BaseGameObj *damager, float *damage, unsigned int *warhead, float scale, DADamageType::Type type, BOOL *result) = 0;
	virtual HRESULT __stdcall PlayerObserverDamageDealt(RenSharpPlayerObserverClass *observer, BaseGameObj *victim, float damage, unsigned int warhead, float scale, DADamageType::Type type) = 0;
	virtual HRESULT __stdcall PlayerObserverDamageReceived(RenSharpPlayerObserverClass *observer, BaseGameObj *damager, float damage, unsigned int warhead, float scale, DADamageType::Type type) = 0;
	virtual HRESULT __stdcall PlayerObserverKillDealt(RenSharpPlayerObserverClass *observer, BaseGameObj *victim, float damage, unsigned int warhead, float scale, DADamageType::Type type) = 0;
	virtual HRESULT __stdcall PlayerObserverKillReceived(RenSharpPlayerObserverClass *observer, BaseGameObj *killer, float damage, unsigned int warhead, float scale, DADamageType::Type type) = 0;
	virtual HRESULT __stdcall PlayerObserverCustom(RenSharpPlayerObserverClass *observer, BaseGameObj *sender, int type, int param) = 0;
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
	virtual HRESULT __stdcall CrateModifierFactoryDestructed(RenSharpCrateModifierFactoryClass* factory) = 0;
	virtual HRESULT __stdcall CrateModifierFactoryCreate(RenSharpCrateModifierFactoryClass* factory, const char* parameters, DACrateModifierClass** result) = 0;

	// RenSharpCrateModifierClass
	virtual HRESULT __stdcall CrateModifierDestructed(RenSharpCrateModifierClass* crateModifier) = 0;
	virtual HRESULT __stdcall CrateModifierInit(RenSharpCrateModifierClass* crateModifier, const char* parameters) = 0;
	virtual HRESULT __stdcall CrateModifierCalculateOdds(RenSharpCrateModifierClass* crateModifier, float* odds, cPlayer* player) = 0;

	// RenSharpCrateClass
	virtual HRESULT __stdcall CrateDestructed(RenSharpCrateClass* crate) = 0;
	virtual HRESULT __stdcall CrateInit(RenSharpCrateClass* crate) = 0;
	virtual HRESULT __stdcall CrateSettingsLoaded(RenSharpCrateClass* crate) = 0;
	virtual HRESULT __stdcall CrateCalculateOdds(RenSharpCrateClass* crate, cPlayer* player) = 0;
	virtual HRESULT __stdcall CrateCanActivate(RenSharpCrateClass* crate, cPlayer* player, BOOL* result) = 0;
	virtual HRESULT __stdcall CrateActivate(RenSharpCrateClass* crate, cPlayer* player) = 0;

	// RenSharpCrateFactoryClass
	virtual HRESULT __stdcall CrateFactoryDestructed(RenSharpCrateFactoryClass* factory) = 0;
	virtual HRESULT __stdcall CrateFactoryCreateInstance(RenSharpCrateFactoryClass* factory, DACrateClass** result) = 0;

	// RenSharpNodeClass
	virtual HRESULT __stdcall NodeDestructed(RenSharpNodeClass* node) = 0;
	virtual HRESULT __stdcall NodeInit(RenSharpNodeClass* node, const INIClass* ini, const char* header) = 0;
	virtual HRESULT __stdcall NodeContestedEvent(RenSharpNodeClass* node) = 0;
	virtual HRESULT __stdcall NodeCaptureEvent(RenSharpNodeClass* node) = 0;
};