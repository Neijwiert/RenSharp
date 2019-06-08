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

#include "MSList.h"
#include "MHashTemplateClass.h"
#include "IUnmanagedContainer.h"
#include "MVector3.h"
#include "Mengine_ttdef.h"
#include "IUnmanagedContainer.h"
#include "Mengine_vector.h"
#include "MPhysDefClass.h"
#include "MBuildingGameObjDef.h"
#include "MNetworkObjectClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <scripts.h>
#include <engine_common.h>
#include <engine_obj.h>
#include <engine_weap.h>
#include <engine_da.h>
#include <Defines.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;
using namespace System::Net;

namespace RenSharp
{
	interface class IFileClass;
	interface class IINIClass;
	interface class IFileFactoryClass;
	interface class IScriptCommands;
	interface class IScriptableGameObj;
	interface class IcPlayer;
	interface class IGameDefinition;
	interface class INetworkObjectClass;
	interface class IcScTextObj;
	interface class ISCAnnouncement;
	interface class IAmmoDefinitionClass;
	interface class IScriptClass;
	interface class ISmartGameObj;
	interface class IGapListNode;
	ref class GapListNode;
	interface class IRenSharpConsoleFunctionClass;
	interface class IConsoleFunctionClass;
	value class Vector2;
	value class Vector4;
	interface class IDefinitionClass;
	value class Matrix3D;
	value class OBBoxClass;
	interface class IScriptImpClass;
	interface class IAmmoDefinitionClass;
	interface class IWeaponDefinitionClass;
	interface class IExplosionDefinitionClass;
	interface class IBeaconGameObj;
	interface class IcTeam;
	interface class IArmedGameObj;
	interface class IBuildingGameObj;
	interface class IPhysicalGameObj;
	interface class IVehicleGameObj;
	interface class ISoldierGameObj;
	interface class ISoldierGameObjDef;
	interface class IPowerUpGameObjDef;
	interface class IcGameData;
	interface class IcGameDataSkirmish;
	interface class IcGameDataCnC;
	interface class IcGameDataSinglePlayer;

	// Custom stuff
	public delegate void PathfindDistanceDelegate(uint32 id, Vector3 start, Vector3 dest, PathfindDistanceResult result, float distance, Object ^data);

	[UnmanagedFunctionPointer(CallingConvention::Cdecl)]
	delegate void InternalPathfindDistanceDelegate(::PathfindDistanceRequest *result);

	public ref class Engine abstract sealed
	{
		private:
			static bool shutdown;

			static Engine();

			// Custom stuff
			static Generic::IDictionary<IntPtr, IRenSharpConsoleFunctionClass^> ^managedConsoleFunctions;

			// engine_tt.h
			ref class PathfindDistanceRequest
			{
				private:
					uint32 unmanagedId;
					PathfindDistanceDelegate ^delegate;
					Object ^data;

				public:
					PathfindDistanceRequest(PathfindDistanceDelegate ^delegate, Object ^data)
						: unmanagedId(0), delegate(delegate), data(data)
					{

					}

					property uint32 UnmanagedId
					{
						uint32 get()
						{
							return unmanagedId;
						}

						void set(uint32 value)
						{
							unmanagedId = value;
						}
					}

					property PathfindDistanceDelegate ^Delegate
					{
						PathfindDistanceDelegate ^get()
						{
							return delegate;
						}
					}

					property Object ^Data
					{
						Object ^get()
						{
							return data;
						}
					}
			};

			static uint32 currentPathfindDistanceRequestId;
			static Generic::IDictionary<uint32, PathfindDistanceRequest ^> ^pathfindDistanceRequests;
			static InternalPathfindDistanceDelegate ^internalPathfindCallbackDelegate;

			static void InternalPathfindDistanceCallback(::PathfindDistanceRequest *result);

		public:
			static void Shutdown();

			// Custom stuff
			static void OnManagedConsoleFunctionDestructed(IntPtr function);
			static bool IsManagedConsoleFunction(IntPtr function);
			static bool IsManagedConsoleFunction(IConsoleFunctionClass ^function);
			static IRenSharpConsoleFunctionClass^ AsManagedConsoleFunction(IntPtr function);
			static IRenSharpConsoleFunctionClass^ AsManagedConsoleFunction(IConsoleFunctionClass ^function);

			// scripts.h
			literal int ScriptCommandsVersion = SCRIPT_COMMANDS_VERSION;

			// engine_common.h
			literal int TTVersionMagic = TT_VERSION_MAGIC;
			literal float TTVersion = TT_VERSION;

			// engine_obj.h
			literal int CIDBeacon = CID_Beacon;
			literal int CIDBuilding = CID_Building;
			literal int CIDC4 = CID_C4;
			literal int CIDConstructionYard = CID_ConstructionYard;
			literal int CIDPowerPlant = CID_PowerPlant;
			literal int CIDPowerUp = CID_PowerUp;
			literal int CIDRefinery = CID_Refinery;
			literal int CIDRepairBay = CID_RepairBay;
			literal int CIDSamSite = CID_SamSite;
			literal int CIDScriptZone = CID_ScriptZone;
			literal int CIDSimple = CID_Simple;
			literal int CIDSoldier = CID_Soldier;
			literal int CIDSoldierFactory = CID_SoldierFactory;
			literal int CIDSpecialEffects = CID_SpecialEffects;
			literal int CIDVehicle = CID_Vehicle;
			literal int CIDVehicleFactory = CID_VehicleFactory;
			literal int CIDWarFactory = CID_WarFactory;
			literal int CIDAirstrip = CID_Airstrip;
			literal int CIDCinematic = CID_Cinematic;
			literal int CIDComCenter = CID_ComCenter;

			// engine_common.h
			generic<typename T>
			where T : IRefCountClass
			static void SafeRelease(T %unk)
			{
				if (unk != nullptr && unk->RefCountClassPointer.ToPointer() != nullptr)
				{
					unk->Release();
					unk = T();
				}
			}

			generic<typename T>
			where T : IRefCountClass
			static void RefPtrSet(T %dest, T %source)
			{
				if (source != nullptr && source->RefCountClassPointer.ToPointer() != nullptr)
				{
					source->AddRef();
				}

				if (dest != nullptr && dest->RefCountClassPointer.ToPointer() != nullptr)
				{
					dest->Release();
				}

				dest = source;
			}

			// engine_weap.h
			enum class C4Type : int
			{
				C4Remote = ::C4Type::C4_REMOTE,
				C4Timed = ::C4Type::C4_TIMED,
				C4Proxy = ::C4Type::C4_PROXY
			};

			// engine_da.h
			literal uint32 CIDWeapon = CID_Weapon;
			literal uint32 CIDAmmo = CID_Ammo;
			literal uint32 CIDExplosion = CID_Explosion;
			literal int StyleC4 = STYLE_C4;
			literal int StyleBeacon = STYLE_BEACON;
			literal uint32 CIDSpawner = CID_Spawner;

			// engine_ttdef.h
			literal int FogExp = FOG_EXP;
			literal int FogExp2 = FOG_EXP2;
			literal int FogLinear = FOG_LINEAR;

			// Defines.h
			literal int EXEClient = EXE_CLIENT;
			literal int EXEServer = EXE_SERVER;
			literal int EXELevelEdit = EXE_LEVELEDIT;
			literal int EXEUnitialised = EXE_UNINITIALISED;

			// engine_common.h
			static void ConsoleInput(String ^input, ...array<Object ^> ^args);
			static void ConsoleOutput(String ^output, ...array<Object ^> ^args);

			// engine_io.h
			static IFileClass ^GetDataFile(String ^filename);
			static void CloseDataFile(IFileClass ^file);
			static IINIClass ^GetINI(String ^filename);
			static void ReleaseINI(IINIClass ^ini);
			static unsigned int GetRegistryInt(String ^entry, int defaultValue);
			static String ^StripPathFromFilename(String ^filename);

			// engine_tt.h
			static ISList<IcPlayer ^> ^GetPlayerList();
			static int GetCurrentMapIndex();
			static String ^GetMap(int index);
			static int GetMapCount();
			static bool SetMap(String ^map, int index);
			static IUnmanagedContainer<IHashTemplateClass<String ^, IGameDefinition ^> ^> ^GetGameDefinitions();
			static void EvictClient(int clientId, String ^reason);
			static String ^GetClientSerialHash(int clientId);
			static IScriptableGameObj ^GetGameObjByPlayerName(String ^name);
			static void SendCustomAllPlayers(int type, IScriptableGameObj ^sender, int team);
			static float StealTeamCredits(float percentage, int team);
			static float GetTeamCredits(int team);
			static void SetCurrentBullets(IScriptableGameObj ^obj, int bullets);
			static void SetCurrentClipBullets(IScriptableGameObj ^obj, int bullets);
			static void SetPositionBullets(IScriptableGameObj ^obj, int position, int bullets);
			static void SetPositionClipBullets(IScriptableGameObj ^obj, int position, int bullets);
			static void SetBullets(IScriptableGameObj ^obj, String ^weapon, int bullets);
			static void SetClipBullets(IScriptableGameObj ^obj, String ^weapon, int bullets);
			static void DisplayGameHint(IScriptableGameObj ^obj, int eventId, String ^sound, int titleId, int textId, int textId2, int textId3);
			static void DisplayGameHintImage(IScriptableGameObj ^obj, int eventId, String ^sound, int titleId, int textId, int textId2, int textId3, String ^textureName);
			static void SetScope(IScriptableGameObj ^obj, int scope);
			static String ^GetCurrentMusicTrack();
			static void SetInfoTexture(IScriptableGameObj ^obj, String ^texture);
			static void ClearInfoTexture(IScriptableGameObj ^obj);
			static void EnableStealthPlayer(IScriptableGameObj ^obj, IScriptableGameObj ^obj2, bool enable);
			static void SetFogEnablePlayer(IScriptableGameObj ^obj, bool enable);
			static void SetFogRangePlayer(IScriptableGameObj ^obj, float startDistance, float endDistance, float transition);
			static void SetBackgroundMusicPlayer(IScriptableGameObj ^obj, String ^music);
			static void FadeBackgroundMusicPlayer(IScriptableGameObj ^obj, String ^music, int fadeOut, int fadeIn);
			static void StopBackgroundMusicPlayer(IScriptableGameObj ^obj);
			static void EnableRadarPlayer(IScriptableGameObj ^obj, bool enable);
			static void DisplayGDIPlayerTerminalPlayer(IScriptableGameObj ^obj);
			static void DisplayNodPlayerTerminalPlayer(IScriptableGameObj ^obj);
			static void SetScreenFadeColorPlayer(IScriptableGameObj ^obj, Color color, float transition);
			static void SetScreenFadeOpacityPlayer(IScriptableGameObj ^obj, float opacity, float transition);
			static void ForceCameraLookPlayer(IScriptableGameObj ^obj, Vector3 look);
			static void EnableHUDPlayer(IScriptableGameObj ^obj, bool enable);
			static int CreateSoundPlayer(IScriptableGameObj ^obj, String ^soundname, Vector3 position, IScriptableGameObj ^obj2);
			static int Create2DSoundPlayer(IScriptableGameObj ^obj, String ^soundname);
			static int Create2DWAVSoundPlayer(IScriptableGameObj ^obj, String ^soundname);
			static int Create3DWAVSoundAtBonePlayer(IScriptableGameObj ^obj, String ^soundname, IScriptableGameObj ^obj2, String ^bonename);
			static int Create3DSoundAtBonePlayer(IScriptableGameObj ^obj, String ^soundname, IScriptableGameObj ^obj2, String ^bonename);
			static void SetVehicleLimit(unsigned int limit);
			static unsigned long GetVehicleLimit();
			static void SetAirVehicleLimit(unsigned int limit);
			static unsigned long GetAirVehicleLimit();
			static void SetNavalVehicleLimit(unsigned int limit);
			static unsigned long GetNavalVehicleLimit();
			static void SendMessage(Color color, String ^msg);
			static void SendMessagePlayer(IScriptableGameObj ^obj, Color color, String ^msg);
			static void LoadNewHUDINI(IScriptableGameObj ^obj, String ^ini);
			static void RemoveWeapon(IScriptableGameObj ^obj, String ^weapon);
			static void ChangeRadarMap(float scale, float offsetX, float offsetY, String ^texture);
			static float GetBuildTimeMultiplier(int team);
			static void SetCurrentlyBuilding(bool building, int team);
			static bool IsCurrentlyBuilding(int team);
			static void SetFogColor(Color color);
			static void SetFogColorPlayer(IScriptableGameObj ^obj, Color color);
			static void SetFogMode(unsigned int mode);
			static void SetFogModePlayer(IScriptableGameObj ^obj, unsigned int mode);
			static void SetFogDensity(float density);
			static void SetFogDensityPlayer(IScriptableGameObj ^obj, float density);
			static void ChangeTimeRemaining(float time);
			static void ChangeTimeLimit(int time);
			static void DisplaySecurityDialog(IScriptableGameObj ^obj);
			static void SendHUDNumber(IScriptableGameObj ^obj, unsigned int number);
			static IScriptableGameObj ^GetExplosionObj();
			static void SetExplosionObj(IScriptableGameObj ^obj);
			static void UpdateNetworkObject(INetworkObjectClass ^obj);
			static void UpdateNetworkObjectPlayer(INetworkObjectClass ^object, int id);
			static IUnmanagedContainer<IcScTextObj ^> ^SendClientText(String ^message, TextMessageEnum type, bool popUp, int senderId, int receiverId, bool doDirtyBit, bool doAct);
			static IUnmanagedContainer<ISCAnnouncement ^> ^SendClientAnnouncement(int receiptientId, int senderId, int translationId, AnnouncementEnum type, int emotIconId, bool doDirtyBit, bool doAct);
			static IntPtr SendPlayerKillMessage(int killer, int victim);
			static IntPtr SendPurchaseResponse(int id, int type);
			static void DoObjectivesDlg(IScriptableGameObj ^obj, String ^file);
			static void SetPlayerLimit(unsigned int limit);
			static unsigned int GetPlayerLimit();
			static void GetFogRange([Out] float %startDistance, [Out] float %endDistance);

			[Obsolete("User other calls")]
			static void SendShaderParamPlayerObsolete(IScriptableGameObj ^player, String ^parameter, String ^value);

			[Obsolete("User other calls")]
			static void SendShaderParamObsolete(String ^parameter, String ^value);

			[Obsolete("User other calls")]
			static void SendShaderParamObjPlayerObsolete(IScriptableGameObj ^player, String ^parameter, String ^value, IScriptableGameObj ^obj);

			[Obsolete("User other calls")]
			static void SendShaderParamObjObsolete(String ^parameter, String ^value, IScriptableGameObj ^obj);

			static void SetGDISoldierName(String ^name);
			static void SetNodSoldierName(String ^name);
			static String ^GetGDISoldierName();
			static String ^GetNodSoldierName();
			static String ^GetIPAddress(int playerId);
			static String ^GetIPPort(int playerId);
			static IPEndPoint ^GetIP(int playerId);
			static int GetBandwidth(int playerId);
			static int GetPing(int playerId);
			static unsigned long GetKbits(int playerId);
			static void SetFogOverridePlayer(IScriptableGameObj ^obj, float start, float end);
			static void ClearFogOverridePlayer(IScriptableGameObj ^obj);
			static void SetMoonIsEarth(bool earth);
			static void SetGlobalStealthDisable(bool disabled);
			static int GetMineLimit();
			static void SetSpecialBaseDestruction();
			static float GetClientVersion(int playerId);
			static uint GetClientRevision(int playerId);
			static uint GetRevision(int playerId);
			static unsigned int GetDamageWarhead();
			static bool GetDamageIsExplosion();
			static bool IsWOLUser(String ^playerName);
			static int GetTechLevel();
			static void SetTechLevel(int mode);
			static void CreateExplosionExtended(String ^explosion, Vector3 pos, IScriptableGameObj ^creator);
			static IUnmanagedContainer<IDynamicVectorClass<int> ^> ^RetrieveWaypaths();
			static IUnmanagedContainer<IDynamicVectorClass<int> ^> ^RetrieveWaypoints(int waypathId);
			static Vector3 GetWaypointPosition(int waypathId, int waypointId);
			static void CreateLightning(IAmmoDefinitionClass ^ammoDef, Vector3 start, Vector3 end);
			static void GetClouds([Out] float %cloudCover, [Out] float %gloominess);
			static void GetLightning([Out] float %intensity, [Out] float %startDistance, [Out] float %endDistance, [Out] float %heading, [Out] float %distribution);
			static void GetWind([Out] float %heading, [Out] float %speed, [Out] float %variability);
			static void GetRain([Out] float %density);
			static void GetSnow([Out] float %density);
			static void GetAsh([Out] float %density);
			static void UpdateGameOptions(int id);
			static double GetTTVersion();
			static uint GetTTRevision();
			static void SetHUDHelpTextPlayer(IScriptableGameObj ^obj, int string, Color color);
			static void ChangeStringPlayer(IScriptableGameObj ^obj, int id, String ^string);
			static void ForcePositionUpdate(IScriptableGameObj ^obj);
			static bool GetRandomPathfindSpot(Vector3 center, float range, [Out] Vector3 returnPosition);
			static void SetHUDHelpTextPlayerText(IScriptableGameObj ^obj, int replaceStringId, String ^replaceText, Color color);
			static void GrantWeapon(IScriptableGameObj ^object, String ^grantWeaponName, bool grantWeapon, int grantWeaponRounds, bool grantWeaponClips);
			static void SetObjectVisibilityForPlayer(IScriptableGameObj ^player, int objectId, bool visible);
			static void SetObjectVisibility(int objectId, bool visible);
			static void LockSoldierCollisionGroup(IScriptableGameObj ^obj, CollisionGroupType collisionGroupType);
			static void UnlockSoldierCollisionGroup(IScriptableGameObj ^obj);
			static bool IsEngineEnabled(IScriptableGameObj ^obj);
			static void StopTimer(IScriptableGameObj ^obj, int number);
			static int Create2DWaveSoundDialogPlayer(IScriptableGameObj ^obj, String ^soundName);
			static void ForcePositionUpdatePlayer(IScriptableGameObj ^player, IScriptableGameObj ^obj);
			static void StopTimer2(IScriptableGameObj ^obj, IScriptClass ^script, int number);
			static bool HasTimer(IScriptableGameObj ^obj, IScriptClass ^script, int number);
			static void SetBackgroundMusicPlayerOffset(IScriptableGameObj ^obj, String ^music, float startOffset);
			static void SetCameraPlayer(IScriptableGameObj ^obj, String ^camera);
			static void SetDefinitionTranslationIDPlayer(IScriptableGameObj ^obj, int defId, int stringId);
			static void SetNetUpdateRatePlayer(IScriptableGameObj ^obj, int rate);
			static void ForceOrientationUpdate(IScriptableGameObj ^obj);
			static void ForceOrientationUpdatePlayer(IScriptableGameObj ^player, IScriptableGameObj ^obj);
			static int Create2DWaveSoundCinematicPlayer(IScriptableGameObj ^obj, String ^soundName);
			static void ForceTurretUpdate(IScriptableGameObj ^obj);
			static void ForceTurretUpdatePlayer(IScriptableGameObj ^player, IScriptableGameObj ^obj);
			static void ForceVelocityUpdate(IScriptableGameObj ^obj);
			static void ForceVelocityUpdatePlayer(IScriptableGameObj ^player, IScriptableGameObj ^obj);
			static void SetCameraHostNetwork(IScriptableGameObj ^obj);
			static uint32 GetPathfindDistance(Vector3 start, Vector3 dest, PathfindDistanceDelegate^ callback, ISmartGameObj^ pathObj, Object^ data);
			static uint32 GetPathfindDistance(Vector3 start, Vector3 dest, PathfindDistanceDelegate ^callback, ISmartGameObj ^pathObj);
			static bool CancelGetPathfindDistance(uint32 id);
			static void KillAllBuildingsByTeam(int team);
			static void SetOccupantsFade(IScriptableGameObj ^obj, Color color);
			static void EnableTeamRadar(int team, bool enable);
			static void CreateSoundTeam(String ^soundName, Vector3 position, IScriptableGameObj ^obj, int team);
			static void Create2DSoundTeam(String ^soundName, int team);
			static void Create2DWAVSoundTeam(String ^soundName, int team);
			static void Create2DWAVSoundTeamDialog(String ^soundName, int team);
			static void Create3DWAVSoundAtBoneTeam(String ^soundName, IScriptableGameObj ^obj, String ^boneName, int team);
			static void Create3DSoundAtBoneTeam(String ^soundName, IScriptableGameObj ^obj, String ^boneName, int team);
			static void SendMessageTeam(int team, Color color, String ^msg);
			static void SendMessageWithObjColor(IScriptableGameObj ^obj, String ^msg);
			static void SendMessageWithTeamColor(int team, String ^msg);
			static void RangedGapEffect(IGapListNode ^firstNode);
			static void RangedGapEffect(GapListNode ^firstNode);
			static void RangedStealthOnTeam(IGapListNode ^firstNode);
			static void RangedStealthOnTeam(GapListNode ^firstNode);
			static bool CanTeamBuildVehicle(int team);
			static void SendShaderParam(String ^parameter, String ^value);
			static void SendShaderParam(String ^parameter, int value);
			static void SendShaderParam(String ^parameter, unsigned int value);
			static void SendShaderParam(String ^parameter, float value);
			static void SendShaderParam(String ^parameter, Vector2 value);
			static void SendShaderParam(String ^parameter, Vector3 value);
			static void SendShaderParam(String ^parameter, Vector4 value);
			static void SendShaderParamPlayer(IScriptableGameObj ^player, String ^parameter, String ^value);
			static void SendShaderParamPlayer(IScriptableGameObj ^player, String ^parameter, int value);
			static void SendShaderParamPlayer(IScriptableGameObj ^player, String ^parameter, unsigned int value);
			static void SendShaderParamPlayer(IScriptableGameObj ^player, String ^parameter, float value);
			static void SendShaderParamPlayer(IScriptableGameObj ^player, String ^parameter, Vector2 value);
			static void SendShaderParamPlayer(IScriptableGameObj ^player, String ^parameter, Vector3 value);
			static void SendShaderParamPlayer(IScriptableGameObj ^player, String ^parameter, Vector4 value);
			static void SendShaderParamObj(String ^parameter, String ^value, IScriptableGameObj ^object);
			static void SendShaderParamObj(String ^parameter, int value, IScriptableGameObj ^object);
			static void SendShaderParamObj(String ^parameter, unsigned int value, IScriptableGameObj ^object);
			static void SendShaderParamObj(String ^parameter, float value, IScriptableGameObj ^object);
			static void SendShaderParamObj(String ^parameter, Vector2 value, IScriptableGameObj ^object);
			static void SendShaderParamObj(String ^parameter, Vector3 value, IScriptableGameObj ^object);
			static void SendShaderParamObj(String ^parameter, Vector4 value, IScriptableGameObj ^object);
			static void SendShaderParamObjPlayer(IScriptableGameObj ^player, String ^parameter, String ^value, IScriptableGameObj ^object);
			static void SendShaderParamObjPlayer(IScriptableGameObj ^player, String ^parameter, int value, IScriptableGameObj ^object);
			static void SendShaderParamObjPlayer(IScriptableGameObj ^player, String ^parameter, unsigned int value, IScriptableGameObj ^object);
			static void SendShaderParamObjPlayer(IScriptableGameObj ^player, String ^parameter, float value, IScriptableGameObj ^object);
			static void SendShaderParamObjPlayer(IScriptableGameObj ^player, String ^parameter, Vector2 value, IScriptableGameObj ^object);
			static void SendShaderParamObjPlayer(IScriptableGameObj ^player, String ^parameter, Vector3 value, IScriptableGameObj ^object);
			static void SendShaderParamObjPlayer(IScriptableGameObj ^player, String ^parameter, Vector4 value, IScriptableGameObj ^object);
			static void DeleteConsoleFunction(String ^name);
			static void SortFunctionList();
			static void VerboseHelpFile();
			static void SendTranslatedMessageTeam(unsigned long id, int team, Color color, bool bPlaySound);
			static void SendTranslatedMessageTeam(unsigned long id, int team, Color color);
			static void ForceVehicleEntry(IScriptableGameObj ^soldier, IScriptableGameObj ^vehicle);

			// engine_da.h
			static void DestroyAllObjectsWithScript(String^ script);
			static bool HasBeacon(IArmedGameObj^ obj);
			static float GetDistanceToClosestBeacon(Vector3 position, int team);
			static float GetDistanceToClosestBuilding(Vector3 position, int team);
			static float GetDistanceToClosestPCT(Vector3 position, int team);
			static float GetDistanceToClosestPlayer(Vector3 position, int team);
			static float GetDistanceToClosestPlayer(Vector3 position);
			static IBuildingGameObj^ GetClosestBuilding(Vector3 position, int team);
			static IPhysicalGameObj^ GetClosestFakeBuilding(Vector3 position, int team);
			static IBuildingGameObj^ GetRandomBuilding(int team);
			static void SendCustomEventVehicleOccupants(IScriptableGameObj^ obj, IScriptableGameObj^ sender, int message, int param, float delay, bool driver);
			static void DisarmClosestBeacon(Vector3 pos, int team);
			static void DisarmAllBeaconsTeam(int team);
			static void DisarmAllBeaconsPlayer(IScriptableGameObj^ player);
			static void PlayAnimationAllPlayers(String^ anim);
			static int FindEmptyVehicleSeat(IVehicleGameObj ^obj, bool allowDriver);
			static int FindEmptyVehicleSeat(IVehicleGameObj^ obj);
			static void ChangeTeam3(IcPlayer^ player, int team);
			static void ChangeTeam4(IcPlayer^ player, int team);
			static void ChangeTeam5(IcPlayer^ player, int team);
			static IcPlayer^ MatchPlayer(IcPlayer^ player, String^ nick, bool teamOnly, bool allowSelf);
			static IcPlayer^ MatchPlayer(IcPlayer^ player, String^ nick, bool teamOnly);
			static IcPlayer^ MatchPlayer(IcPlayer^ player, String^ nick);
			static void DamageObjectsHalfNoKill();
			static void AttachScriptToDefinition(String^ preset, String^ script, String^ params);
			static void AttachScriptToDefinitions(unsigned long cID, String^ script, String^ params);
			static void RemoveScriptFromDefinition(String^ preset, String^ script);
			static void RemoveScriptFromDefinitions(unsigned long cID, String^ script);
			static void SetObjectTypePreset(String^ preset, int team);
			static IcTeam^ FindTeam(int team);
			static void GiveCreditsTeam(int team, float credits);
			static void GivePointsPlayersInRange(Vector3 position, float range, float points, bool giveMoney);
			static void GivePointsPlayersInRange(Vector3 position, float range, float points);
			static void GivePointsPlayersInRangeTeam(int team, Vector3 position, float range, float points, bool giveMoney);
			static void GivePointsPlayersInRangeTeam(int team, Vector3 position, float range, float points);
			static String ^EncryptApgar(String^ password);
			static void SetFacingPlayer(IScriptableGameObj^ obj, float facing);
			static bool OverlapTest(IScriptableGameObj^ obj, Vector3 position, bool checkDynOnly);
			static bool OverlapTest(IScriptableGameObj^ obj, Vector3 position);
			static bool IsSimple(IScriptableGameObj^ obj);
			static bool IsPowerup(IScriptableGameObj^ obj);
			static bool IsC4(IScriptableGameObj^ obj);
			static bool IsBeacon(IScriptableGameObj^ obj);
			static bool IsArmed(IScriptableGameObj^ obj);
			static bool IsPowerPlant(IScriptableGameObj^ obj);
			static bool IsVehicleFactory(IScriptableGameObj^ obj);
			static bool IsRefinery(IScriptableGameObj^ obj);
			static bool IsSoldierFactory(IScriptableGameObj^ obj);
			static bool IsDecorationPhys(IScriptableGameObj^ obj);
			static bool IsPlayer(IScriptableGameObj^ obj);
			static bool IsStealthUnit(IScriptableGameObj^  obj);
			static unsigned int GetGroundVehicleCount(int team);
			static unsigned int GetAirVehicleCount(int team);
			static unsigned int GetNavalVehicleCount(int team);
			static void SetObjectDirtyBitForVersionGreaterThan(INetworkObjectClass^ obj, float version, DirtyBit bit, bool onOff);
			static void SetObjectDirtyBitForVersionLessThan(INetworkObjectClass^ obj, float version, DirtyBit bit, bool onOff);
			static void SetObjectDirtyBitForTeamVersionGreaterThan(INetworkObjectClass^ obj, int team, float version, DirtyBit bit, bool onOff);
			static void SetObjectDirtyBitForTeamVersionLessThan(INetworkObjectClass^ obj, int team, float version, DirtyBit bit, bool onOff);
			static int SetupSendMessageFake(String^ newNick, int id);
			static int SetupSendMessageFake(String^ newNick);
			static int SetupSendMessageTeamFake(String^ newNick, int team, int id);
			static int SetupSendMessageTeamFake(String^ newNick, int team);
			static void RestoreSendMessageFake();
			static void SendAnnouncement(String^ stringID);
			static void SendAnnouncementVersionLessThan(String^ stringID, float version);
			static void SendAnnouncementPlayer(int id, String^ stringID);
			static void SendAnnouncementPlayerVersionLessThan(int id, String^ stringID, float version);
			static void SendAnnouncementTeam(int team, String^ stringID);
			static void SendAnnouncementTeamVersionLessThan(int team, String^ stringID, float version);
			static void SendMessageTeamWithTeamColor(int team, String^ msg);
			static void SendMessagePlayerByID(int id, Color color, String^ message);
			static void Create2DWAVSoundPlayerByID(int id, String^ sound);
			static IPhysicalGameObj^ CreateObject(String^ preset, Vector3 position);
			static IPhysicalGameObj^ CreateObject(String^ preset, Matrix3D transform);
			static IPhysicalGameObj^ CreateObject(int preset, Vector3 position);
			static IPhysicalGameObj^ CreateObject(int preset, Matrix3D transform);
			static IPhysicalGameObj^ CreateObject(IDefinitionClass^ def, Vector3 position);
			static IPhysicalGameObj^ CreateObject(IDefinitionClass^ def, Matrix3D transform);
			static ISoldierGameObj^ CreateCommando(IcPlayer^ player, String^ preset, Vector3 position);
			static ISoldierGameObj^ CreateCommando(IcPlayer^ player, String^ preset, Matrix3D transform);
			static ISoldierGameObj^ CreateCommando(IcPlayer^ player, int preset, Vector3 position);
			static ISoldierGameObj^ CreateCommando(IcPlayer^ player, int preset, Matrix3D transform);
			static ISoldierGameObj^ CreateCommando(IcPlayer^ player, IDefinitionClass^ def, Vector3 position);
			static ISoldierGameObj^ CreateCommando(IcPlayer^ player, IDefinitionClass^ def, Matrix3D transform);
			static void DisableBuildingType(int team, RenSharp::BuildingType type);
			static unsigned int GetHash(String^ string);
			static bool IsStartingWeapon(ISoldierGameObjDef^ soldier, IPowerUpGameObjDef^ powerUp);
			static bool IsStartingWeapon(ISoldierGameObj^ soldier, IPowerUpGameObjDef^ powerUp);
			static void FixStuckObjects(Vector3 position, float checkRange, float range, bool destroyUnfixable);
			static void FixStuckObjects(Vector3 position, float checkRange, float range);
			static bool FixStuckObject(IPhysicalGameObj^ obj, float range);
			static String ^CleanModelName(String^ model);
			static String^ GetWeaponPowerUpModel(IWeaponDefinitionClass^ weapon);
			static void AddConsoleFunction(IConsoleFunctionClass^ function);
			static void AddConsoleFunction(IRenSharpConsoleFunctionClass^ function);
			static int GetBuildingCount(int team, bool destroyed);
			static void EnableHUD(bool enable);
			static void EnableHUDPlayerByID(int id, bool enable);
			static void SetFogEnablePlayerByID(int id, bool enable);
			static void SetFogRangePlayerByID(int id, float startDistance, float endDistance, float transition);
			static bool ExitVehicle(ISoldierGameObj^ soldier);
			static void ReverseDamage(IScriptableGameObj^ obj, float amount);
			static void SetEmotIcon(int id, String^ model, int team);

			// engine_def.h
			static String ^GetDefinitionName(unsigned long id); 
			static int GetDefinitionID(String ^name); 
			static IDefinitionClass ^FindNamedDefinition(String ^name);
			static IDefinitionClass ^FindDefinition(unsigned long id); 
			static unsigned long GetDefinitionClassID(String ^name);
			static IDefinitionClass ^GetPhysDefinition(IScriptableGameObj ^obj);
			static bool IsValidPresetID(unsigned long id); 
			static bool IsValidPreset(String ^preset);

			// engine_dmg.h
			static void DamageAllBuildingsByTeam(int team, float damage, String ^warhead, IScriptableGameObj ^damager);
			static void RepairAllBuildingsByTeam(int team, int constructionYardID, float health);
			static void RepairAllStaticVehiclesByTeam(int team, int type);
			static void SetMaxHealth(IScriptableGameObj ^obj, float health);
			static void SetMaxShieldStrength(IScriptableGameObj ^obj, float shieldStrength);
			static String ^GetShieldType(IScriptableGameObj ^obj);
			static String ^GetSkin(IScriptableGameObj ^obj);
			static void SetSkin(IScriptableGameObj ^obj, String ^skinType);
			static void DamageAllVehiclesArea(float damage, String ^warhead, Vector3 position, float distance, IScriptableGameObj ^host, IScriptableGameObj ^damager);
			static void DamageAllObjectsArea(float damage, String ^warhead, Vector3 position, float distance, IScriptableGameObj ^host, IScriptableGameObj ^damager);
			static void DamageAllObjectsAreaByTeam(float damage, String ^warhead, Vector3 position, float distance, IScriptableGameObj ^damager, bool soldiers, bool vehicles, int team);
			static void RangedDamageToBuildings(float damage, String ^warhead, Vector3 location, float damageRadius, IScriptableGameObj ^damager);
			static void RangedScaleDamageToBuildings(float damage, String ^warhead, Vector3 location, float damageRadius, IScriptableGameObj ^damager);
			static void RangedPercentageDamageToBuildings(float percentage, String ^warhead, Vector3 location, float damageRadius, IScriptableGameObj ^damager);
			static void RangedDamageToBuildingsTeam(int team, float damage, String ^warhead, Vector3 location, float damageRadius, IScriptableGameObj ^damager);
			static void RangedScaleDamageToBuildingsTeam(int team, float damage, String ^warhead, Vector3 location, float damageRadius, IScriptableGameObj ^damager);
			static void RangedPercentageDamageToBuildingsTeam(int team, float percentage, String ^warhead, Vector3 location, float damageRadius, IScriptableGameObj ^damager);
			static void DamageObjectsHalf();
			static void RangedPercentageDamageToVehicles(float percentage, String ^warhead, Vector3 location, float damageRadius, IScriptableGameObj ^damager);
			static void SetDamagePoints(IScriptableGameObj ^obj, float points);
			static void SetDeathPoints(IScriptableGameObj ^obj, float points);
			static void RepairAllBuildingsByTeamRadius(int team, int constructionYardID, float health, float radius);
			static void RepairAllTurretsByTeam(int team, float health);
			static void DamageAllObjectsInZone(IScriptableGameObj ^zone, float damage, String ^warhead, IScriptableGameObj ^damager);
			static float GetDamagePoints(IScriptableGameObj ^obj);
			static float GetDeathPoints(IScriptableGameObj ^obj);
			static void KillOccupants(IScriptableGameObj ^obj);
			static void DamageOccupants(IScriptableGameObj ^obj, float damage, String ^warhead);
			static void RangedVariablePercentVehicleDamage(float enemyPercentage, float friendPecentage, bool forceFriendly, String ^warhead, Vector3 location, float damageRadius, IScriptableGameObj ^damager);
			static float GetMaxHitpoints(IScriptableGameObj ^obj);
			static float GetHitpoints(IScriptableGameObj ^obj);
			static bool IsValidArmorType(String ^name);
			static bool IsValidWarheadType(String ^name);

			// engine_math.h
			static float Rad2Deg(float radians);
			static float Deg2Rad(float degrees);
			static double Rad2Deg(double radians);
			static double Deg2Rad(double degrees);
			static float DivideRoundUp(float x, float y);
			static double DivideRoundUp(double x, double y);
			static unsigned long F2DW(float f);
			static std::uint8_t Sqr(std::uint8_t value);
			static std::int8_t Sqr(std::int8_t value);
			static std::uint16_t Sqr(std::uint16_t value);
			static std::int16_t Sqr(std::int16_t value);
			static std::uint32_t Sqr(std::uint32_t value);
			static std::int32_t Sqr(std::int32_t value);
			static std::uint64_t Sqr(std::uint64_t value);
			static std::int64_t Sqr(std::int64_t value);
			static float Sqr(float value);
			static double Sqr(double value);
			static double Sqr(wchar_t value);
			static std::uint8_t Clamp(std::uint8_t value, std::uint8_t min, std::uint8_t max);
			static std::int8_t Clamp(std::int8_t value, std::int8_t min, std::int8_t max);
			static std::uint16_t Clamp(std::uint16_t value, std::uint16_t min, std::uint16_t max);
			static std::int16_t Clamp(std::int16_t value, std::int16_t min, std::int16_t max);
			static std::uint32_t Clamp(std::uint32_t value, std::uint32_t min, std::uint32_t max);
			static std::int32_t Clamp(std::int32_t value, std::int32_t min, std::int32_t max);
			static std::uint64_t Clamp(std::uint64_t value, std::uint64_t min, std::uint64_t max);
			static std::int64_t Clamp(std::int64_t value, std::int64_t min, std::int64_t max);
			static float Clamp(float value, float min, float max);
			static double Clamp(double value, double min, double max);
			static wchar_t Clamp(wchar_t value, wchar_t min, wchar_t max);
			static std::uint8_t Wrap(std::uint8_t value, std::uint8_t min, std::uint8_t max);
			static std::int8_t Wrap(std::int8_t value, std::int8_t min, std::int8_t max);
			static std::uint16_t Wrap(std::uint16_t value, std::uint16_t min, std::uint16_t max);
			static std::int16_t Wrap(std::int16_t value, std::int16_t min, std::int16_t max);
			static std::uint32_t Wrap(std::uint32_t value, std::uint32_t min, std::uint32_t max);
			static std::int32_t Wrap(std::int32_t value, std::int32_t min, std::int32_t max);
			static std::uint64_t Wrap(std::uint64_t value, std::uint64_t min, std::uint64_t max);
			static std::int64_t Wrap(std::int64_t value, std::int64_t min, std::int64_t max);
			static float Wrap(float value, float min, float max);
			static wchar_t Wrap(wchar_t value, wchar_t min, wchar_t max);
			static std::uint8_t Lerp(std::uint8_t a, std::uint8_t b, float fraction);
			static std::int8_t Lerp(std::int8_t a, std::int8_t b, float fraction);
			static std::uint16_t Lerp(std::uint16_t a, std::uint16_t b, float fraction);
			static std::int16_t Lerp(std::int16_t a, std::int16_t b, float fraction);
			static std::uint32_t Lerp(std::uint32_t a, std::uint32_t b, float fraction);
			static std::int32_t Lerp(std::int32_t a, std::int32_t b, float fraction);
			static std::uint64_t Lerp(std::uint64_t a, std::uint64_t b, float fraction);
			static std::int64_t Lerp(std::int64_t a, std::int64_t b, float fraction);
			static float Lerp(float a, float b, float fraction);
			static double Lerp(double a, double b, float fraction);
			static wchar_t Lerp(wchar_t a, wchar_t b, float fraction);
			static bool IsPowerOfTwo(int number);
			static uint GetColorUInt32(int a, int r, int g, int b);
			static float Sgn(float x);
			static int FindPOTLT(int i);

			// engine_obj.h
			static int GetObjectType(IScriptableGameObj ^obj);
			static void SetObjectType(IScriptableGameObj ^obj, int type);
			static Color GetObjectColor(IScriptableGameObj ^obj);
			static IScriptableGameObj ^FindSmartObjectByTeam(int team);
			static IScriptableGameObj ^FindObjectByTeam(int team);
			static IScriptableGameObj ^FindNonPlayerObjectByTeam(int team);
			static IScriptableGameObj ^FindObjectByPreset(int team, String ^presetName);
			static IScriptableGameObj ^FindClosestNonBuildingObjectByTeam(int team, Vector3 position);
			static IScriptableGameObj ^FindClosestPresetByTeam(int team, Vector3 pos, String ^preset);
			static IScriptableGameObj ^FindRandomPresetByTeam(int team, String ^preset);
			static int GetObjectCount(int team, String ^preset);
			static Generic::ICollection<IScriptableGameObj ^> ^GetAllObjectsByPreset(int team, String ^preset);
			static IScriptableGameObj ^FindNearestPreset(Vector3 position, String ^preset);
			static IScriptableGameObj ^FindRandomPreset(String ^preset, int min, int max);
			static void SendCustomToTeamBuildings(int team, IScriptableGameObj ^sender, int type, int param, float delay);
			static void SendCustomToTeamPreset(int team, String ^presetName, IScriptableGameObj ^sender, int type, int param, float delay);
			static void SendCustomAllObjectsArea(int type, Vector3 position, float distance, IScriptableGameObj ^sender, int team);
			static void SendCustomAllObjects(int type, IScriptableGameObj ^sender, int team);
			static void SendCustomEventToObject(IScriptableGameObj ^sender, String ^preset, int type, int param, float delay);
			static bool IsUnitInRange(String ^preset, float range, Vector3 location, int team, bool empty);
			static bool GetIsPowerupPersistant(IScriptableGameObj ^obj);
			static bool GetPowerupAlwaysAllowGrant(IScriptableGameObj ^obj);
			static void SetPowerupAlwaysAllowGrant(IScriptableGameObj ^obj, bool grant);
			static int GetPowerupGrantSound(IScriptableGameObj ^obj);
			static void GrantPowerup(IScriptableGameObj ^obj, String ^presetName);
			static IScriptableGameObj ^FindClosestBuilding(Vector3 position);
			static Vector3 GetVelocity(IScriptableGameObj ^obj);
			static void SetVelocity(IScriptableGameObj ^obj, Vector3 velocity);
			static Matrix3D GetTransform(IScriptableGameObj ^obj);
			static void SetTransform(IScriptableGameObj ^obj, Matrix3D transform);
			static IScriptableGameObj ^GetClosestArmedObjectToObject(IScriptableGameObj ^obj, int team);
			static IScriptableGameObj ^GetClosestArmedObjectToObject(IScriptableGameObj ^obj);
			static bool VerifyPresetLimit(int team, int instanceCount, array<uint32> ^presetIds, IScriptableGameObj ^ignore);
			static bool VerifyPresetLimit(int team, int instanceCount, array<uint32> ^presetIds);

			// engine_obj2.h
			static IScriptableGameObj ^GetVehicle(IScriptableGameObj ^obj);
			static void GrantRefill(IScriptableGameObj ^obj);
			static bool ChangeCharacter(IScriptableGameObj ^obj, String ^presetName);
			static bool CreateVehicle(String ^presetName, float delay, IScriptableGameObj ^owner, int team);
			static void ToggleFlyMode(IScriptableGameObj ^obj);
			static int GetVehicleOccupantCount(IScriptableGameObj ^obj);
			static IScriptableGameObj ^GetVehicleOccupant(IScriptableGameObj ^obj, int seat);
			static IScriptableGameObj ^GetVehicleDriver(IScriptableGameObj ^obj);
			static IScriptableGameObj ^GetVehicleGunner(IScriptableGameObj ^obj);
			static void ForceOccupantExit(IScriptableGameObj ^obj, int seat);
			static void ForceOccupantsExit(IScriptableGameObj ^obj);
			static IScriptableGameObj ^GetVehicleReturn(IScriptableGameObj ^obj);
			static bool IsStealth(IScriptableGameObj ^obj);
			static bool GetFlyMode(IScriptableGameObj ^obj);
			static int GetVehicleSeatCount(IScriptableGameObj ^obj);
			static void SoldierTransitionVehicle(IScriptableGameObj ^obj);
			static unsigned int GetVehicleMode(IScriptableGameObj ^obj);
			static bool IsVTOL(IScriptableGameObj ^obj);
			static IScriptableGameObj ^GetVehicleOwner(IScriptableGameObj ^obj);
			static void ForceOccupantsExitTeam(IScriptableGameObj ^obj, int team);
			static unsigned int GetVehicleDefinitionMode(String ^preset);
			static IScriptableGameObj ^FindClosestZone(Vector3 location, unsigned int type);
			static bool IsInsideZone(IScriptableGameObj ^zone, IScriptableGameObj ^obj);
			static unsigned int GetVehicleDefinitionModeByID(unsigned long id);
			static unsigned int GetZoneType(IScriptableGameObj ^obj);
			static bool GetZoneBox(IScriptableGameObj ^obj, [Out] OBBoxClass %box);
			static void SetZoneBox(IScriptableGameObj ^obj, OBBoxClass box);
			static IScriptableGameObj ^CreateZone(String ^preset, OBBoxClass box);
			static bool IsAvailableForPurchase(IScriptableGameObj ^factory);
			static IScriptableGameObj ^GetVehicleGunnerPos(IScriptableGameObj ^obj);
			static void SetVehicleGunner(IScriptableGameObj ^obj, int seat);
			static bool IsSpy(IScriptableGameObj ^obj);
			static int GetPlayerCountInZone(IScriptableGameObj ^obj, int team);
			static int GetObjectCountInZone(IScriptableGameObj ^obj, int team);
			static bool IsStealthEnabled(IScriptableGameObj ^obj);
			static int GetOccupantSeat(IScriptableGameObj ^vehicle, IScriptableGameObj ^occupant);
			static bool IsUnsquishable(IScriptableGameObj ^obj);
			static IScriptableGameObj ^CreateObjectAttachToObject(IScriptableGameObj ^host, String ^preset, String ^bone);
			static IScriptableGameObj ^CreateObjectAttachToObject(IScriptableGameObj ^host, String ^preset);

			// engine_phys.h
			static String ^GetModel(IScriptableGameObj ^obj);
			static float GetAnimationFrame(IScriptableGameObj ^obj);
			static float GetAnimationTargetFrame(IScriptableGameObj ^obj);
			static void CopyTransform(IScriptableGameObj ^in, IScriptableGameObj ^out);
			static float GetMass(IScriptableGameObj ^obj);
			static String ^GetHtreeName(IScriptableGameObj ^obj);
			static wchar_t GetSex(IScriptableGameObj ^obj);
			static void CreateEffectAllStealthedObjectsArea(Vector3 position, float distance, String ^object, Vector3 offset, int team);
			static void CreateEffectAllOfPreset(String ^object, String ^preset, float zAdjust, bool zSet);
			static void WakeUpObjectsInBox(IScriptableGameObj ^obj, String ^box);
			static void WakeUpObjectsInOBBox(OBBoxClass boundingBox);
			static String ^GetAnimationName(IScriptableGameObj ^obj);

			// engine_player.h
			static IScriptableGameObj ^GetGameObj(int playerID);
			static long GetPlayerID(IScriptableGameObj ^obj);
			static String ^GetPlayerName(IScriptableGameObj ^obj);
			static String ^GetPlayerNameByID(int playerID);
			static void ChangeTeam(IScriptableGameObj ^obj, int team);
			static void ChangeTeamByID(int playerID, int team);
			static int GetTeamPlayerCount(int team);
			static int GetTeam(int playerID);
			static int GetRank(int playerID);
			static int GetKills(int playerID);
			static int GetDeaths(int playerID);
			static float GetScore(int playerID);
			static float GetMoney(int playerID);
			static float GetKillToDeathRatio(int playerID);
			static IScriptableGameObj ^GetPartName(String ^name);
			static int GetPartNames(String ^name);
			static Color GetTeamColor(unsigned int team);
			static Color GetPlayerColor(int playerID);
			static bool PurchaseItem(IScriptableGameObj ^obj, int cost);
			static void SetLadderPoints(int playerID, int amount);
			static void SetRung(int playerID, int amount);
			static void SetMoney(int playerID, float amount);
			static void SetScore(int playerID, float amount);
			static IScriptableGameObj ^FindFirstPlayer(int team);
			static bool ChangePlayerTeam(IScriptableGameObj ^obj, bool retainScore, bool retainMoney, bool showHostMessage);
			static int TallyTeamSize(int team);
			static float GetTeamScore(int team);
			static void ChangeTeam2(IScriptableGameObj ^obj, int team);
			static int GetPlayerType(IScriptableGameObj ^obj);
			static Color GetColorForTeam(int teamId);
			static int GetPlayerTeam(int playerID);
			static IcPlayer ^FindPlayer(int playerID);
			static IcPlayer ^FindPlayer(String ^playerName);
			static int GetPlayerIDByName(String ^name);
			static bool IsActive(int id);
			static void SetKills(int id, int kills);
			static void SetDeaths(int id, int deaths);
			static void SetTeamScore(int id, float score);
			static void ChangeTeamDeaths(int teamId, int amount);

			// engine_pt.h
			static unsigned int GetTeamCost(String ^preset, unsigned int team);
			static unsigned int GetCost(String ^preset);
			static void DisablePresetByName(unsigned int team, String ^name, bool enable);
			static void HidePresetByName(unsigned int team, String ^name, bool enable);
			static void BusyPresetByName(unsigned int team, String ^name, bool enable);
			static String ^GetTeamIcon(String ^preset, unsigned int team);
			static String ^GetIcon(String ^preset);
			static void DisableAllPresetsByFactoryTech(RenSharp::BuildingType type, unsigned int team, bool disable);

			// engine_script.h
			static void RemoveScript(IScriptableGameObj^ obj, String^ script); 
			static void RemoveAllScripts(IScriptableGameObj^ obj); 
			static void AttachScriptPreset(String^ script, String^ params, String^ preset, int team);
			static void AttachScriptType(String^ script, String^ params, unsigned long type, int team); 
			static void RemoveScriptPreset(String^ script, String^ preset, int team); 
			static void RemoveScriptType(String^ script, unsigned long type, int team);
			static bool IsScriptAttached(IScriptableGameObj^ obj, String^ script); 
			static void AttachScriptOnce(IScriptableGameObj^ obj, String^ script, String^ params, ...array<Object^>^ args);
			static void AttachScriptPresetOnce(String^ script, String^ params, String^ preset, int team); 
			static void AttachScriptTypeOnce(String^ script, String^ params, unsigned long type, int team);
			static void AttachScriptBuilding(String^ script, String^ params, int team); 
			static void AttachScriptIsPreset(IScriptableGameObj^ obj, String^ preset, String^ script, String^ params, int team);
			static void AttachScriptIsType(IScriptableGameObj^ obj, unsigned long type, String^ script, String^ params, int team);
			static void AttachScriptPlayerOnce(String^ script, String^ params, int team);
			static void RemoveDuplicateScript(IScriptableGameObj^ obj, String^ script); 
			static void AttachScriptAllBuildingsTeam(int team, String^ script, String^ params, bool once); 
			static void AttachScriptAllTurretsTeam(int team, String^ script, String^ params, bool once);
			static IScriptableGameObj^ FindBuildingWithScript(int team, int type, String^ script, IScriptableGameObj^ caller); 
			static IScriptableGameObj^ FindObjectWithScript(String^ script); 
			static IScriptableGameObj^ FindClosestObjectWithScript(String^ script, Vector3 pos); 
			static Generic::ICollection<IScriptableGameObj ^>^ FindAllObjectsWithScript(String^ script);
			static Generic::ICollection<IScriptableGameObj^>^ FindAllObjectsWithScriptByDistance(String^ script, Vector3 position);
			static void SendCustomEventToObjectsWithScript(IScriptableGameObj^ sender, String^ script, int message, int param, float delay); 
			static void SendCustomEventToObjectsWithScriptRanged(IScriptableGameObj^ sender, String^ script, int message, int param, float delay, float range);
			static IScriptImpClass^ FindScriptOnObject(IScriptableGameObj^ obj, String^ script);
			static void AttachScriptOccupants(IScriptableGameObj^ obj, String^ script, String^ params, ...array<Object^>^ args);

			// engine_tdb.h
			static String^ GetTranslatedString(unsigned long id);
			static String^ GetTranslatedPresetName(IScriptableGameObj^ obj);
			static String^ GetTranslatedWeapon(IScriptableGameObj^ obj, int position);
			static String^ GetCurrentTranslatedWeapon(IScriptableGameObj^ obj);
			static String^ GetTeamName(int team);
			static String^ GetVehicleName(IScriptableGameObj^ obj);
			static String^ GetTranslatedDefinitionName(String^ preset);
			static bool IsValidStringID(unsigned long id);
			static unsigned long GetStringIDByDesc(String^ desc);
			static unsigned long GetStringSoundID(unsigned long id);

			// engine_weap.h
			static int GetBullets(IScriptableGameObj^ obj, String^ weapon);
			static int GetMaxBullets(IScriptableGameObj^ obj, String^ weapon);
			static int GetClipBullets(IScriptableGameObj^ obj, String^ weapon);
			static int GetMaxClipBullets(IScriptableGameObj^ obj, String^ weapon);
			static int GetTotalBullets(IScriptableGameObj^ obj, String^ weapon);
			static int GetMaxTotalBullets(IScriptableGameObj^ obj, String^ weapon);
			static int GetCurrentBullets(IScriptableGameObj^ obj);
			static int GetCurrentMaxBullets(IScriptableGameObj^ obj);
			static int GetCurrentClipBullets(IScriptableGameObj^ obj);
			static int GetCurrentClipMaxBullets(IScriptableGameObj^ obj);
			static int GetCurrentTotalBullets(IScriptableGameObj^ obj);
			static int GetCurrentTotalMaxBullets(IScriptableGameObj^ obj);
			static int GetPositionBullets(IScriptableGameObj^ obj, int position);
			static int GetPositionMaxBullets(IScriptableGameObj^ obj, int position);
			static int GetPositionClipBullets(IScriptableGameObj^ obj, int position);
			static int GetPositionClipMaxBullets(IScriptableGameObj^ obj, int position);
			static int GetPositionTotalBullets(IScriptableGameObj^ obj, int position);
			static int GetPositionTotalMaxBullets(IScriptableGameObj^ obj, int position);
			static String^ GetPowerupWeapon(String^ powerup);
			static IAmmoDefinitionClass^ GetWeaponAmmoDefinition(String^ weapon, bool primaryFire);
			static IWeaponDefinitionClass^ GetWeaponDefinition(String^ weapon);
			static IWeaponDefinitionClass^ GetCurrentWeaponDefinition(IScriptableGameObj^ obj);
			static IWeaponDefinitionClass^ GetPositionWeaponDefinition(IScriptableGameObj^ obj, int position);
			static IExplosionDefinitionClass^ GetExplosion(String^ explosion);
			static String^ GetPowerupWeaponByObj(IScriptableGameObj^ powerup);
			static int GetCurrentWeaponStyle(IScriptableGameObj^ obj); 
			static int GetPositionWeaponStyle(IScriptableGameObj^ obj, int position);
			static int GetWeaponStyle(IScriptableGameObj^ obj, String^ weapon);
			static void DisarmBeacon(IScriptableGameObj^ obj);
			static void DisarmBeacons(int playerID);
			static void DisarmC4(IScriptableGameObj^ obj); 
			static void DisarmAllC4Beacons(int playerID);
			static String^ GetCurrentWeapon(IScriptableGameObj^ obj);
			static int GetWeaponCount(IScriptableGameObj^ obj); 
			static String^ GetWeapon(IScriptableGameObj^ obj, int position); 
			static bool HasWeapon(IScriptableGameObj^ obj, String^ weapon); 
			static IScriptableGameObj^ FindBeacon(int number, int team);
			static int GetC4Count(int team, int type);
			static int GetC4Count(int team);
			static void DefuseOwnedC4(int playerID, int type);
			static void DefuseOwnedC4(int playerID);
			static void DefuseAttachedC4(IScriptableGameObj^ attachedObject);
			static int GetBeaconCount(int team); 
			static int GetC4Mode(IScriptableGameObj^ obj); 
			static IScriptableGameObj^ GetC4Planter(IScriptableGameObj^ obj);
			static IScriptableGameObj^ GetC4Attached(IScriptableGameObj^ obj);
			static IScriptableGameObj^ GetBeaconPlanter(IScriptableGameObj^ obj);
			static IBeaconGameObj ^FindNearestBeacon(Vector3 position, int team);

			// da.h
			static void DebugMsg(String^ format, ...array<Object^>^ args);
			static int GetRandomInt(int min, int max);
			static float GetRandomFloat(float min, float max);
			static bool GetRandomBool();
			static float Diff(float first, float second);
			static int Diff(int first, int second);
			static String^ FormatTime(unsigned long time);
			static String^ LongToIP(unsigned long ip);
			static float Round(float number);

			// engine_game.h
			static void PowerBase(int team, bool powered);
			static void SetCanGenerateSoldiers(int team, bool canGenerate);
			static void SetCanGenerateVehicles(int team, bool canGenerate);
			static void DestroyBase(int team);
			static void BeaconDestroyedBase(int team, bool destroyed);
			static void EnableBaseRadar(int team, bool enable);
			static bool IsHarvester(IScriptableGameObj^ obj);
			static bool IsRadarEnabled(int team);
			static int BuildingType(IScriptableGameObj^ obj);
			static bool IsBuildingDead(IScriptableGameObj^ obj);
			static IScriptableGameObj^ FindBuildingByType(int team, int type);
			static IScriptableGameObj^ FindBaseDefense(int team);
			static IScriptableGameObj^ CreateBuilding(String^ preset, Vector3 position);
			static IScriptableGameObj^ FindHarvester(int team);
			static bool IsBasePowered(int team);
			static bool CanGenerateVehicles(int team);
			static bool CanGenerateSoldiers(int team);
			static int GetBuildingCountTeam(int team);
			static IScriptableGameObj^ FindBuildingByTeam(int team);
			static IScriptableGameObj^ FindBuildingByPreset(int team, String^ presetName);
			static IScriptableGameObj^ FindPowerPlant(int team);
			static IScriptableGameObj^ FindConstructionYard(int team);
			static IScriptableGameObj^ FindRefinery(int team);
			static IScriptableGameObj^ FindRepairBay(int team);
			static IScriptableGameObj^ FindSoldierFactory(int team);
			static IScriptableGameObj^ FindVehicleFactory(int team);
			static IScriptableGameObj^ FindComCenter(int team);
			static IScriptableGameObj^ FindSpecial(int team);
			static IScriptableGameObj^ FindNavalFactory(int team);
			static IScriptableGameObj^ FindTechCenter(int team);
			static IScriptableGameObj^ FindHelipad(int team);
			static IScriptableGameObj^ FindShrine(int team);
			static void RestoreBuilding(IScriptableGameObj^ obj);
			static int GetHarvesterPresetID(int team);
			static bool IsHarvesterPreset(IScriptableGameObj^ obj);
			static bool VehiclePresetIsAir(int preset);
			static bool VehiclePresetIsNaval(int preset);
			static Vector3 GetBaseCenter(int team);
			static TimeSpan SecondsToHms(float secs);

			// Defines.h
			static void InitEngine();

			// da_string.h
			static String^ UppercaseAOrAn(String^ str);
			static String^ LowercaseAOrAn(String^ str);
			static String^ UppercaseAOrAnPrepend(String^ str);
			static String^ LowercaseAOrAnPrepend(String^ str);
			static String^ MakePossessive(String^ str);
			static bool IsNumeric(String^ str);
			static bool IsNumber(String^ str);
			static bool IsAlpha(String^ str);

			// Crc32.h
			static unsigned long CRCMemory(array<unsigned char>^ data, unsigned long crc);
			static unsigned long CRCMemory(array<unsigned char>^ data);
			static unsigned long CRCString(String^ data, unsigned long crc);
			static unsigned long CRCStringi(String^ data, unsigned long crc);
			static unsigned long CRCStringi(String^ data);
			static unsigned long CRCFile(IFileClass^ file, uint32 seed);
			static unsigned long CRCFile(IFileClass^ file);

			// Custom stuff
			static property String ^RenSharpVersion
			{
				String ^get();
			}

			// engine_tt.h
			static property IntPtr GetPlayerListPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetCurrentMapIndexPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetMapPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetMapCountPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetMapPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetGameDefinitionsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr EvictClientPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetClientSerialHashPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetGameObjByPlayerNamePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SendCustomAllPlayersPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr StealTeamCreditsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetTeamCreditsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetCurrentBulletsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetCurrentClipBulletsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetPositionBulletsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetPositionClipBulletsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetBulletsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetClipBulletsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr DisplayGameHintPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr DisplayGameHintImagePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetScopePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetCurrentMusicTrackPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetInfoTexturePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ClearInfoTexturePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr EnableStealthPlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetFogEnablePlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetFogRangePlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetBackgroundMusicPlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr FadeBackgroundMusicPlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr StopBackgroundMusicPlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr EnableRadarPlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr DisplayGDIPlayerTerminalPlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr DisplayNodPlayerTerminalPlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetScreenFadeColorPlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetScreenFadeOpacityPlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ForceCameraLookPlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr EnableHUDPlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr CreateSoundPlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr Create2DSoundPlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr Create2DWAVSoundPlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr Create3DWAVSoundAtBonePlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr Create3DSoundAtBonePlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetVehicleLimitPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetVehicleLimitPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetAirVehicleLimitPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetAirVehicleLimitPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetNavalVehicleLimitPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetNavalVehicleLimitPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SendMessagePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SendMessagePlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr LoadNewHUDINIPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr RemoveWeaponPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ChangeRadarMapPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetBuildTimeMultiplierPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetCurrentlyBuildingPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr IsCurrentlyBuildingPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetFogColorPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetFogColorPlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetFogModePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetFogModePlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetFogDensityPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetFogDensityPlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ChangeTimeRemainingPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ChangeTimeLimitPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr DisplaySecurityDialogPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SendHUDNumberPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetExplosionObjPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetExplosionObjPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr UpdateNetworkObjectPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr UpdateNetworkObjectPlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SendClientTextPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SendClientAnnouncementPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SendPlayerKillMessagePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SendPurchaseResponsePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr DoObjectivesDlgPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetPlayerLimitPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetPlayerLimitPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetFogRangePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SendShaderParamPlayerObsoletePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SendShaderParamObsoletePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SendShaderParamObjPlayerObsoletePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SendShaderParamObjObsoletePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetGDISoldierNamePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetNodSoldierNamePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetGDISoldierNamePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetNodSoldierNamePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetIPAddressPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetIPPortPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetIPPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetBandwidthPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetPingPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetKbitsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetFogOverridePlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ClearFogOverridePlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetMoonIsEarthPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetGlobalStealthDisablePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetMineLimitPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetSpecialBaseDestructionPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetClientVersionPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetClientRevisionPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetRevisionPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetDamageWarheadPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetDamageIsExplosionPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr IsWOLUserPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetTechLevelPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetTechLevelPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr CreateExplosionExtendedPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr RetrieveWaypathsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr RetrieveWaypointsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetWaypointPositionPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr CreateLightningPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetCloudsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetLightningPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetWindPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetRainPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetSnowPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetAshPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr UpdateGameOptionsPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetTTVersionPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetTTRevisionPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetHUDHelpTextPlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ChangeStringPlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ForcePositionUpdatePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetRandomPathfindSpotPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetHUDHelpTextPlayerTextPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GrantWeaponPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetObjectVisibilityForPlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetObjectVisibilityPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr LockSoldierCollisionGroupPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr UnlockSoldierCollisionGroupPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr IsEngineEnabledPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr StopTimerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr Create2DWaveSoundDialogPlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ForcePositionUpdatePlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr StopTimer2Pointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr HasTimerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetBackgroundMusicPlayerOffsetPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetCameraPlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetDefinitionTranslationIDPlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetNetUpdateRatePlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ForceOrientationUpdatePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ForceOrientationUpdatePlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr Create2DWaveSoundCinematicPlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ForceTurretUpdatePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ForceTurretUpdatePlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ForceVelocityUpdatePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr ForceVelocityUpdatePlayerPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr SetCameraHostNetworkPointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr GetPathfindDistancePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IntPtr CancelGetPathfindDistancePointer
			{
				IntPtr get();
				void set(IntPtr value);
			}

			static property IDynamicVectorClass<IConsoleFunctionClass ^> ^ConsoleFunctionList
			{
				IDynamicVectorClass<IConsoleFunctionClass ^> ^get();
				void set(IDynamicVectorClass<IConsoleFunctionClass ^> ^value);
			}

			// engine_io.h
			static property IFileFactoryClass ^TheFileFactory
			{
				IFileFactoryClass ^get();
			}

			static property String ^FilePath
			{
				String ^get();
			}

			static property String ^AppDataPath
			{
				String ^get();
			}

			static property String ^RegistryPath
			{
				String ^get();
			}

			// scripts.h
			static property float DontMoveArrivedDist
			{
				float get();
			}

			static property IScriptCommands ^Commands
			{
				IScriptCommands ^get();
				void set(IScriptCommands ^value);
			}

			// engine_player.h
			static property int PlayerCount
			{
				int get();
			}

			// da.h
			static property Color ColorWhite
			{
				Color get();
			}

			static property Color ColorGray
			{
				Color get();
			}

			static property Color ColorLightBlue
			{
				Color get();
			}

			static property Color ColorGreen
			{
				Color get();
			}

			static property Color ColorBrown
			{
				Color get();
			}

			static property Color ColorPurple
			{
				Color get();
			}

			// engine_game.h
			static property bool IsMapFlying
			{
				bool get();
			}

			static property IcGameData^ TheGame
			{
				IcGameData^ get();
			}

			static property IcGameDataSkirmish^ TheSkirmishGame
			{
				IcGameDataSkirmish^ get();
			}

			static property IcGameDataCnC^ TheCncGame
			{
				IcGameDataCnC^ get();
			}

			static property IcGameDataSinglePlayer^ TheSinglePlayerGame
			{
				IcGameDataSinglePlayer ^ get();
			}

			static property bool IsGameplayPermitted
			{
				bool get();
			}

			static property bool IsDedicated
			{
				bool get();
			}

			static property unsigned int CurrentGameMode
			{
				unsigned int get();
			}

			static property Color PrivateMessageColor
			{
				Color get();
			}

			static property Color PublicMessageColor
			{
				Color get();
			}

			static property int Exe
			{
				int get();
				void set(int value);
			}

		internal:
			// Custom stuff
			static void RegisterManagedConsoleFunction(IRenSharpConsoleFunctionClass^ function);
			static void UnregisterManagedConsoleFunction(IRenSharpConsoleFunctionClass^ function);
	};
}