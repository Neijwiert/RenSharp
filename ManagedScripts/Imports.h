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

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4091 4715 4251 4244 26495 26454)

class GenericNode;
class GenericList;
struct INIEntry;
template<class T>
class List;
template<typename T1, class T2> 
class IndexClass;
struct INISection;
class FileClass;
class Straw;
class Pipe;
class INIClass;
class FileFactoryClass;
class Buffer;
class BufferStraw;
class FileStraw;
class CacheStraw;
class BufferPipe;
class FilePipe;
class Vector3;
class DASettingsClass;
class NetworkObjectClass;
class PostLoadableClass;
class ChunkLoadClass;
class ChunkSaveClass;
class ReferencerClass;
class ScriptableGameObj;
class PersistFactoryClass;
class AudioCallbackClass;
template<class T>
class ReferenceableClas;
class PhysObserverClass;
class CombatPhysObserverClass;
class DialogueOptionClass;
struct DAPlayerObserverTimerStruct;
class DATokenParserClass;
class DATokenClass;
class DAPlayerDataFactoryClass;
class DAPlayerDataClass;
struct ConnectionRequest;
class Vector4;
class BuildingGameObj;
class PlaneClass;
class RefCountClass;
class MultiListObjectClass;
class SoundSceneObjClass;
struct CombatSound;
class GameObjObserverTimerClass;
class GameObjCustomTimerClass;
class RenSharpGameObjObserverClass;
class OffenseObjectClass;
class ArmedGameObj;
class LineSegClass;
class Vector2;
class FrustumClass;
class Matrix3D;
class CullSystemClass;
class CullLinkClass;
class AnimControlClass;
class MuzzleRecoilClass;
class ControlClass;
struct ScriptCommands;
class ScriptVariableClass;
class ScriptImpClass;
class SafeActionParamsStruct;
class ActionParamsStruct;
class ActionClass;
class PhysControllerClass;
class TransitionDataClass;
class TransitionGameObjDef;
struct DAPlayerObserverChatCommandStruct;
struct DAPlayerObserverKeyHookStruct;
class DAPlayerObserverClass;
class RenSharpPlayerObserverClass;
class TransitionCompletionDataStruct;
class RenderObjClass;
class PersistantSurfaceEmitterClass;
class SoldierGameObj;
class TransitionInstanceClass;
class RenSharpCollisionTestClass;
struct CastResultStruct;
class CollisionTestClass;
class RenSharpRayCollisionTestClass;
class LineSegClass;
class Matrix3D;
class RayCollisionTestClass;
class RenSharpAABoxCollisionTestClass;
class AABoxCollisionTestClass;
class AABoxClass;
class RenSharpOBBoxCollisionTestClass;
class OBBoxCollisionTestClass;
class OBBoxClass;
class MultiListNodeClass;
class GenericMultiListClass;
class GenericMultiListIterator;
class StaticPhysClass;
class BuildingAggregateClass;
class LightPhysClass;
class IntersectionTestClass;
class AABoxIntersectionTestClass;
class OBBoxIntersectionTestClass;
class PhysClass;
class RenSharpPhysAABoxIntersectionTestClass;
class RenSharpPhysOBBoxIntersectionTestClass;
class RenSharpPhysMeshIntersectionTestClass;
class MeshClass;
class PhysAABoxIntersectionTestClass;
class PhysOBBoxIntersectionTestClass;
class PhysMeshIntersectionTestClass;
class ScriptCommandsClass;
class PhysRayCollisionTestClass;
class RenSharpPhysRayCollisionTestClass;
class PhysAABoxCollisionTestClass;
class RenSharpPhysAABoxCollisionTestClass;
class PhysOBBoxCollisionTestClass;
class RenSharpPhysOBBoxCollisionTestClass;
class MaterialEffectClass;
class GenericSLNode;
class cPlayer;
class SceneIterator;
struct PivotClass;
struct Gap_ListNode;
class PrototypeClass;
class PrototypeLoaderClass;
class PrimitivePrototypeClass;
class MeshLoaderClass;
class RenderObjClass;
class ConsoleFunctionClass;
class RenSharpConsoleFunctionClass;
class DAEventClass;
struct DAEventStruct;
struct DAObjectEventStruct;
struct DAEventTimerStruct;
class RenSharpEventClass;
class DABanEntryClass;
class DABanListClass;
class DAChatCommandClass;
struct DAEventChatCommandStruct;
class DAKeyHookClass;
struct DAEventKeyHookStruct;
class DADamageLogObserverClass;
class DefinitionClass;
struct DACharacterDisableListStruct;
class DAGameModeFactoryClass;
class DAGameModeClass;
class DAGameFeatureFactoryClass;
class DAGameFeatureClass;
class DAGameFeatureFactoryClass;
class RenSharpGameFeatureFactoryClass;
class RenSharpGameFeatureClass;
class RenSharpPlayerDataFactoryClass;
class RenSharpPlayerDataClass;
class RenSharpGameModeFactoryClass;
class RenSharpGameModeClass;
class RenSharpGameFeatureEventClass;
class RenSharpGameFeatureEventClassPlayerDataFactory;
class RenSharpGameModeEventClass;
class RenSharpGameModeEventClassPlayerDataFactory;
class DATimedInvincibilityObserverClass;
class DAAttachToObjectWithZOffsetObserverClass;
class DANoPointsUntilEnteredObserverClass;
class WeaponDefinitionClass;
class Plugin;
class DACrateModifierFactoryClass;
class DACrateModifierClass;
class DACrateFactoryClass;
class DACrateClass;
class RenSharpCrateModifierFactoryClass;
class RenSharpCrateModifierClass;
class RenSharpCrateClass;
class RenSharpCrateFactoryClass;
class DACharacterRefundsPlayerDataClass;
class DAChatSoundsPlayerDataClass;
class DALootPlayerDataClass;
class DALootPowerUpClass;
class DALootBackpackClass;
class DALootDNAClass;
class DALootGameFeatureClass;
class DAExtraRadioCommandsPlayerDataClass;
struct DARTCStruct;
class DARTCPlayerDataClass;
struct DASquadInviteStruct;
struct DASquadRemixStruct;
class DASquadMemberClass;
class DASquadClass;
class DASquadManagerClass;
class DAVehicleOwnershipObserverClass;
struct DAVehicleShellStruct;
class DASpawnNodeClass;
class DANodeManagerClass;
class DASpawnManagerClass;
class RenSharpNodeClass;
class DATeleporterManagerClass;
class DAVehicleSpawnManagerClass;
class DAVehicleSpawnPointClass;
class DAVehicleAirDropPointClass;
class DATeleporterClass;
class ConnectionAcceptanceFilter;
class ParameterClass;
class ParameterListClass;
class RawFileClass;
class TextFileClass;
class BufferedFileClass;
class CombatNetworkHandlerClass;
class CombatMiscHandlerClass;
class CommandLineParser;
class ConversationRemarkClass;
class OratorClass;
class DefinitionFactoryClass;
class WidgetUserClass;
class CompressedVisTableClass;
class VisDecompressionCacheClass;
class SysTimeClass;
class TDBObjClass;
class ObserverImpClass;

#include <coltype.h>
#include <multilist.h>
#include <PhysDefClass.h>
#include <SList.h>
#include <HashTemplateClass.h>
#include <HashTemplateIterator.h>
#include <GameDefinition.h>
#include <WWAudioClass.h>
#include <BaseGameObj.h>
#include <BuildingGameObj.h>
#include <SoldierGameObj.h>
#include <SmartGameObj.h>
#include <C4GameObj.h>
#include <BeaconGameObj.h>
#include <VehicleGameObj.h>
#include <ScriptZoneGameObj.h>
#include <GameData.h>
#include <da_damagelog.h>
#include <da_crate.h>
#include <engine_player.h>
#include <engine_da.h>
#include <da_spawnsystem.h>
#include <AABTreeCull.h>
#include <GridCull.h>
#include <MixFileFactoryClass.h>
#include <PhysicsSceneClass.h>
#include <CriticalSectionClass.h>

#pragma warning(pop) 
#pragma managed(pop)

using namespace System;
using namespace System::Runtime::InteropServices;

#define RenSharpPluginName "da_RenSharp.dll"

namespace RenSharp
{
	namespace Imports
	{
		[DllImport(RenSharpPluginName)]
		extern "C" void OnFatalException([MarshalAs(UnmanagedType::LPStr)] String ^exception);

		[DllImport(RenSharpPluginName)]
		extern "C" void OnFatalExceptionCallback([MarshalAs(UnmanagedType::LPStr)] String^ exception);

		[DllImport(RenSharpPluginName)]
		extern "C" bool IsShuttingDown();

		[DllImport(RenSharpPluginName)]
		extern "C" char *CreateAnsiString(std::size_t size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyAnsiString(const char *str);

		[DllImport(RenSharpPluginName)]
		extern "C" char *MallocAnsiString(std::size_t size);

		[DllImport(RenSharpPluginName)]
		extern "C" void FreeAnsiString(const char *str);

		[DllImport(RenSharpPluginName)]
		extern "C" ::GenericNode *CreateGenericNode();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyGenericNode(::GenericNode *genericNode);

		[DllImport(RenSharpPluginName)]
		extern "C" ::GenericList *CreateGenericList();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyGenericList(::GenericList *genericList);

		[DllImport(RenSharpPluginName)]
		extern "C" ::INIEntry *CreateINIEntry(char *entry, char *value);

		[DllImport(RenSharpPluginName)]
		extern "C" ::List<::INIEntry *> *CreateINIEntryList();

		[DllImport(RenSharpPluginName)]
		extern "C" ::IndexClass<int, ::INIEntry *> *CreateIntINIEntryIndexClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyIntINIEntryIndexClass(::IndexClass<int, ::INIEntry *> *intINIEntryIndexClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::List<::INISection *> *CreateINISectionList();

		[DllImport(RenSharpPluginName)]
		extern "C" ::INISection *CreateINISection(char *section);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyFileClass(::FileClass *fileClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::Straw *CreateStraw();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyStraw(::Straw *straw);

		[DllImport(RenSharpPluginName)]
		extern "C" ::Pipe *CreatePipe1();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyPipe(::Pipe *pipe);

		[DllImport(RenSharpPluginName)]
		extern "C" ::IndexClass<int, ::INISection *> *CreateIntINISectionIndexClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyIntINISectionIndexClass(::IndexClass<int, ::INISection *> *intINISectionIndexClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::INIClass *CreateINIClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::INIClass *CreateINIClass2(::FileClass *file);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyINIClass(::INIClass *iniClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyFileFactoryClass(::FileFactoryClass *fileFactoryClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::Buffer *CreateBuffer(long size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyBuffer(::Buffer *buffer);

		[DllImport(RenSharpPluginName)]
		extern "C" ::BufferStraw *CreateBufferStraw(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" ::FileStraw *CreateFileStraw(::FileClass *file);

		[DllImport(RenSharpPluginName)]
		extern "C" ::CacheStraw *CreateCacheStraw(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" ::BufferPipe *CreateBufferPipe(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" ::FilePipe *CreateFilePipe(::FileClass *file);

		[DllImport(RenSharpPluginName)]
		extern "C" void Vector3Normalize(::Vector3 *vector);

		[DllImport(RenSharpPluginName)]
		extern "C" void Vector3Normalized(::Vector3* vector, ::Vector3* result);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DASettingsClass *CreateDASettingsClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DASettingsClass *CreateDASettingsClass2([MarshalAs(UnmanagedType::LPStr)] String ^filename);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DASettingsClass *CreateDASettingsClass3(::INIClass *ini);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDASettingsClass(::DASettingsClass *daSettingsClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyNetworkObjectClass(::NetworkObjectClass *networkObjectClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::PostLoadableClass *CreatePostLoadableClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyPostLoadableClass(::PostLoadableClass *postLoadableClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::ChunkLoadClass *CreateChunkLoadClass(::FileClass *file);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyChunkLoadClass(::ChunkLoadClass *chunkLoadClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::ChunkSaveClass *CreateChunkSaveClass(::FileClass *file);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyChunkSaveClass(::ChunkSaveClass *chunkSaveClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::ReferencerClass *CreateReferencerClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::ReferencerClass *CreateReferencerClass2(::ScriptableGameObj *object);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyReferencerClass(::ReferencerClass *referencerClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyPersistFactoryClass(::PersistFactoryClass *persistFactoryClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyAudioCallbackClass(::AudioCallbackClass *audioCallbackClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::ReferenceableClass<::ScriptableGameObj> *CreateReferenceableGameObj(::ScriptableGameObj *referenceData);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyReferenceableGameObj(::ReferenceableClass<::ScriptableGameObj> *referenceableGameObj);

		[DllImport(RenSharpPluginName)]
		extern "C" ::SimpleDynVecClass<int> *CreateIntSimpleDynVecClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::SimpleDynVecClass<int> *CreateIntSimpleDynVecClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyIntSimpleDynVecClass(::SimpleDynVecClass<int> *intSimpleDynVecClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::PhysObserverClass *CreatePhysObserverClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyPhysObserverClass(::PhysObserverClass *physObserverClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::CombatPhysObserverClass *CreateCombatPhysObserverClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyCombatPhysObserverClass(::CombatPhysObserverClass *combatPhysObserverClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::SimpleDynVecClass<::StringClass> *CreateStringClassSimpleDynVecClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::SimpleDynVecClass<::StringClass> *CreateStringClassSimpleDynVecClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyStringClassSimpleDynVecClass(::SimpleDynVecClass<::StringClass> *stringClassSimpleDynVecClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::StringClass> *CreateStringClassDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::StringClass> *CreateStringClassDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyStringClassDynamicVectorClass(::DynamicVectorClass<::StringClass> *stringClassDynamicVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::DialogueOptionClass *> *CreateDialogueOptionClassPtrDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::DialogueOptionClass *> *CreateDialogueOptionClassPtrDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDialogueOptionClassPtrDynamicVectorClass(::DynamicVectorClass<::DialogueOptionClass *> *dialogueOptionClassPtrDynamicVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DAPlayerObserverTimerStruct *CreateDAPlayerObserverTimerStruct();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDAPlayerObserverTimerStruct(::DAPlayerObserverTimerStruct *daPlayerObserverTimerStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DATokenParserClass *CreateDATokenParserClass(const char *str, char delim);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDATokenParserClass(::DATokenParserClass *daTokenParserClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DATokenClass *CreateDATokenClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DATokenClass *CreateDATokenClass2(const char *str, int startPos, char delim);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DATokenClass *CreateDATokenClass3(const char *str, int startPos);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DATokenClass *CreateDATokenClass4(const char *str);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DATokenClass* CreateDATokenClass5(::DATokenParserClass* parser);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDATokenClass(::DATokenClass *daTokenClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDAPlayerDataClass(::DAPlayerDataClass *daPlayerDataClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDAPlayerDataFactoryClass(::DAPlayerDataFactoryClass *daPlayerDataFactoryClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::ConnectionRequest *CreateConnectionRequest();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyConnectionRequest(::ConnectionRequest *connectionRequest);

		[DllImport(RenSharpPluginName)]
		extern "C" void Vector4Normalize(::Vector4 *vector);

		[DllImport(RenSharpPluginName)]
		extern "C" ::Vector3 *CreateVector3Array(std::size_t size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyVector3Array(::Vector3 *vArray);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::BuildingGameObj *> *CreateBuildingGameObjPtrDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::BuildingGameObj *> *CreateBuildingGameObjPtrDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyBuildingGameObjPtrDynamicVectorClass(::DynamicVectorClass<::BuildingGameObj *> *buildingGameObjPtrDynamicVector);
	
		[DllImport(RenSharpPluginName)]
		extern "C" void CreatePlaneClass(::PlaneClass *plane, ::Vector3 *point1, ::Vector3 *point2, ::Vector3 *point3);

		[DllImport(RenSharpPluginName)]
		extern "C" void PlaneClassSet(::PlaneClass *plane, ::Vector3 *point1, ::Vector3 *point2, ::Vector3 *point3);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RefCountClass *CreateRefCountClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void RefCountClassReleaseRef(::RefCountClass* thisPtr);

		[DllImport(RenSharpPluginName)]
		extern "C" void RefCountClassRelease(::RefCountClass* thisPtr);

		[DllImport(RenSharpPluginName)]
		extern "C" ::MultiListObjectClass *CreateMultiListObjectClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyMultiListObjectClass(::MultiListObjectClass *multiListObjectClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::SoundSceneObjClass *> *CreateSoundSceneObjClassPtrDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::SoundSceneObjClass *> *CreateSoundSceneObjClassPtrDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroySoundSceneObjClassPtrDynamicVectorClass(::DynamicVectorClass<::SoundSceneObjClass *> *soundSceneObjClassPtrDynamicVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::CombatSound *CreateCombatSound();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyCombatSound(::CombatSound *combatSound);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyGameObjObserverClass(::GameObjObserverClass *gameObjObserverClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::SimpleDynVecClass<::GameObjObserverClass *> *CreateGameObjObserverClassPtrSimpleDynVecClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::SimpleDynVecClass<::GameObjObserverClass *> *CreateGameObjObserverClassPtrSimpleDynVecClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyGameObjObserverClassPtrSimpleDynVecClass(::SimpleDynVecClass<::GameObjObserverClass *> *gameObjObserverClassPtrSimpleDynVecClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::GameObjObserverTimerClass *> *CreateGameObjObserverTimerClassPtrDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::GameObjObserverTimerClass *> *CreateGameObjObserverTimerClassPtrDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyGameObjObserverTimerClassPtrDynamicVectorClass(::DynamicVectorClass<::GameObjObserverTimerClass *> *gameObjObserverTimerClassPtrDynamicVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::GameObjCustomTimerClass *> *CreateGameObjCustomTimerClassPtrDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::GameObjCustomTimerClass *> *CreateGameObjCustomTimerClassPtrDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyGameObjCustomTimerClassPtrDynamicVectorClass(::DynamicVectorClass<::GameObjCustomTimerClass *> *GameObjCustomTimerClassPtrDynamicVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpGameObjObserverClass *CreateRenSharpGameObjObserverClass(const char *name);

		[DllImport(RenSharpPluginName)]
		extern "C" ::OffenseObjectClass *CreateOffenseObjectClass1(float damage, unsigned int warhead, ::ArmedGameObj *owner);

		[DllImport(RenSharpPluginName)]
		extern "C" ::OffenseObjectClass *CreateOffenseObjectClass2(float damage, unsigned int warhead);

		[DllImport(RenSharpPluginName)]
		extern "C" ::OffenseObjectClass *CreateOffenseObjectClass3(float damage);

		[DllImport(RenSharpPluginName)]
		extern "C" ::OffenseObjectClass *CreateOffenseObjectClass4();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyOffenseObjectClass(::OffenseObjectClass *offenseObjectClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void CreateLineSegClass(::LineSegClass *line, const ::Vector3 *p0, const ::Vector3 *p1);

		[DllImport(RenSharpPluginName)]
		extern "C" void LineSegClassSet(::LineSegClass *line, const ::Vector3 *p0, const ::Vector3 *p1);

		[DllImport(RenSharpPluginName)]
		extern "C" void LineSegClassRecalculate(::LineSegClass *line);

		[DllImport(RenSharpPluginName)]
		extern "C" void Vector2Normalize(::Vector2 *vec);

		[DllImport(RenSharpPluginName)]
		extern "C" void FrustumClassInit(
			::FrustumClass *frustum,
			const ::Matrix3D *camera,
			const ::Vector2 *vpMin,
			const ::Vector2 *vpMax,
			float zNear,
			float zFar);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyCullSystemClass(::CullSystemClass *cullSystemClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::CullLinkClass *CreateCullLinkClass(::CullSystemClass *system);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyCullLinkClass(::CullLinkClass *cullLinkClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyAnimControlClass(::AnimControlClass *animControlClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyMuzzleRecoilClass(::MuzzleRecoilClass *muzzleRecoilClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyControlClass(::ControlClass *controlClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::ScriptCommands *CreateScriptCommands();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyScriptCommands(::ScriptCommands *scriptCommands);

		[DllImport(RenSharpPluginName)]
		extern "C" ::ScriptVariableClass *CreateScriptVariableClass(void *dataPtr, int dataSize, int id, ::ScriptVariableClass *next);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyScriptVariableClass(::ScriptVariableClass *scriptVariableClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::ScriptImpClass *CreateScriptImpClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyScriptFactory(::ScriptFactory *scriptFactory);

		[DllImport(RenSharpPluginName)]
		extern "C" ::SafeActionParamsStruct *CreateSafeActionParamsStruct();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroySafeActionParamsStruct(::SafeActionParamsStruct *safeActionParamsStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" ::ActionParamsStruct *CreateActionParamsStruct();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyActionParamsStruct(::ActionParamsStruct *actionParamsStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyActionClass(::ActionClass *actionClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::PhysControllerClass *CreatePhysControllerClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyPhysControllerClass(::PhysControllerClass *physControllerClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::TransitionDataClass *CreateTransitionDataClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyTransitionDataClass(::TransitionDataClass *transitionDataClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::TransitionDataClass *> *CreateTransitionDataClassPtrDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::TransitionDataClass *> *CreateTransitionDataClassPtrDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyTransitionDataClassPtrDynamicVectorClass(::DynamicVectorClass<::TransitionDataClass *> *TransitionDataClassPtrDynamicVectorClass);
	
		[DllImport(RenSharpPluginName)]
		extern "C" ::DAPlayerObserverChatCommandStruct *CreateDAPlayerObserverChatCommandStruct();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDAPlayerObserverChatCommandStruct(::DAPlayerObserverChatCommandStruct *daPlayerObserverChatCommandStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DAPlayerObserverKeyHookStruct *CreateDAPlayerObserverKeyHookStruct();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDAPlayerObserverKeyHookStruct(::DAPlayerObserverKeyHookStruct *daPlayerObserverKeyHookStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::DAPlayerObserverTimerStruct *> *CreateDAPlayerObserverTimerStructPtrDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::DAPlayerObserverTimerStruct *> *CreateDAPlayerObserverTimerStructPtrDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDAPlayerObserverTimerStructPtrDynamicVectorClass(::DynamicVectorClass<::DAPlayerObserverTimerStruct *> *DAPlayerObserverTimerStructPtrDynamicVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::DAPlayerObserverChatCommandStruct *> *CreateDAPlayerObserverChatCommandStructPtrDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::DAPlayerObserverChatCommandStruct *> *CreateDAPlayerObserverChatCommandStructPtrDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDAPlayerObserverChatCommandStructPtrDynamicVectorClass(::DynamicVectorClass<::DAPlayerObserverChatCommandStruct *> *DAPlayerObserverChatCommandStructPtrDynamicVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::DAPlayerObserverKeyHookStruct *> *CreateDAPlayerObserverKeyHookStructPtrDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::DAPlayerObserverKeyHookStruct *> *CreateDAPlayerObserverKeyHookStructPtrDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDAPlayerObserverKeyHookStructPtrDynamicVectorClass(::DynamicVectorClass<::DAPlayerObserverKeyHookStruct *> *DAPlayerObserverKeyHookStructPtrDynamicVectorClass);
	
		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDAPlayerObserverClass(::DAPlayerObserverClass *daPlayerObserverClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::DAPlayerObserverClass *> *CreateDAPlayerObserverClassPtrDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::DAPlayerObserverClass *> *CreateDAPlayerObserverClassPtrDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDAPlayerObserverClassPtrDynamicVectorClass(::DynamicVectorClass<::DAPlayerObserverClass *> *DAPlayerObserverClassPtrDynamicVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpPlayerObserverClass *CreateRenSharpPlayerObserverClass(const char *name);

		[DllImport(RenSharpPluginName)]
		extern "C" ::TransitionCompletionDataStruct *CreateTransitionCompletionDataStruct();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyTransitionCompletionDataStruct(::TransitionCompletionDataStruct *transitionCompletionDataStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::RenderObjClass *> *CreateRenderObjClassPtrDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::RenderObjClass *> *CreateRenderObjClassPtrDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyRenderObjClassPtrDynamicVectorClass(::DynamicVectorClass<::RenderObjClass *> *RenderObjClassPtrDynamicVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::VectorClass<::PersistantSurfaceEmitterClass *> *CreatePersistantSurfaceEmitterClassPtrVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::VectorClass<::PersistantSurfaceEmitterClass *> *CreatePersistantSurfaceEmitterClassPtrVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyPersistantSurfaceEmitterClassPtrVectorClass(::VectorClass<::PersistantSurfaceEmitterClass *> *persistantSurfaceEmitterClassPtrVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::VectorClass<::SoldierGameObj *> *CreateSoldierGameObjPtrVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::VectorClass<::SoldierGameObj *> *CreateSoldierGameObjPtrVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroySoldierGameObjPtrVectorClass(::VectorClass<::SoldierGameObj *> *SoldierGameObjPtrVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::TransitionInstanceClass *> *CreateTransitionInstanceClassPtrDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::TransitionInstanceClass *> *CreateTransitionInstanceClassPtrDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyTransitionInstanceClassPtrDynamicVectorClass(::DynamicVectorClass<::TransitionInstanceClass *> *TransitionInstanceClassPtrDynamicVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpCollisionTestClass *CreateRenSharpCollisionTestClass(int collisionType);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyRenSharpCollisionTestClass(::RenSharpCollisionTestClass *renSharpCollisionTestClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::CollisionTestClass *CreateCollisionTestClass(int collisionType);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyCollisionTestClass(::CollisionTestClass *collisionTestClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void RenSharpCollisionTestClassSetResult(::RenSharpCollisionTestClass *thisPtr, const ::CastResultStruct *res);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpRayCollisionTestClass *CreateRenSharpRayCollisionTestClass1(const ::LineSegClass *ray, ::Collision_Type collisionType, bool ignoreTranslucentMeshes);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpRayCollisionTestClass *CreateRenSharpRayCollisionTestClass2(const ::LineSegClass *ray, ::Collision_Type collisionType);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpRayCollisionTestClass *CreateRenSharpRayCollisionTestClass3(const ::LineSegClass *ray);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpRayCollisionTestClass *CreateRenSharpRayCollisionTestClass4(const ::RayCollisionTestClass *rayTest, const ::Matrix3D *tm);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyRenSharpRayCollisionTestClass(::RenSharpRayCollisionTestClass *renSharpRayCollisionTestClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void RenSharpRayCollisionTestClassSetResult(::RenSharpRayCollisionTestClass *thisPtr, const ::CastResultStruct *res);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RayCollisionTestClass *CreateRayCollisionTestClass1(const ::LineSegClass *ray, ::Collision_Type collisionType, bool ignoreTranslucentMeshes);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RayCollisionTestClass *CreateRayCollisionTestClass2(const ::LineSegClass *ray, ::Collision_Type collisionType);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RayCollisionTestClass *CreateRayCollisionTestClass3(const ::LineSegClass *ray);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RayCollisionTestClass *CreateRayCollisionTestClass4(const ::RayCollisionTestClass *rayTest, const ::Matrix3D *tm);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyRayCollisionTestClass(::RayCollisionTestClass *rayCollisionTestClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpAABoxCollisionTestClass *CreateRenSharpAABoxCollisionTestClass1(const ::AABoxClass *aabox, const ::Vector3 *move, ::Collision_Type collisionType);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpAABoxCollisionTestClass *CreateRenSharpAABoxCollisionTestClass2(const ::AABoxClass *aabox, const ::Vector3 *move);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyRenSharpAABoxCollisionTestClass(::RenSharpAABoxCollisionTestClass *renSharpAABoxCollisionTestClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void RenSharpAABoxCollisionTestClassSetResult(::RenSharpAABoxCollisionTestClass *thisPtr, const ::CastResultStruct *res);

		[DllImport(RenSharpPluginName)]
		extern "C" ::AABoxCollisionTestClass *CreateAABoxCollisionTestClass1(const ::AABoxClass *aabox, const ::Vector3 *move, ::Collision_Type collisionType);

		[DllImport(RenSharpPluginName)]
		extern "C" ::AABoxCollisionTestClass *CreateAABoxCollisionTestClass2(const ::AABoxClass *aabox, const ::Vector3 *move);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyAABoxCollisionTestClass(::AABoxCollisionTestClass *aaBoxCollisionTestClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpOBBoxCollisionTestClass *CreateRenSharpOBBoxCollisionTestClass1(const ::OBBoxClass *obbox, const ::Vector3 *move, ::Collision_Type collisionType);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpOBBoxCollisionTestClass *CreateRenSharpOBBoxCollisionTestClass2(const ::OBBoxClass *obbox, const ::Vector3 *move);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpOBBoxCollisionTestClass *CreateRenSharpOBBoxCollisionTestClass3(const ::OBBoxCollisionTestClass *that, const ::Matrix3D *tm);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpOBBoxCollisionTestClass *CreateRenSharpOBBoxCollisionTestClass4(const ::AABoxCollisionTestClass *that, const ::Matrix3D *tm);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyRenSharpOBBoxCollisionTestClass(::RenSharpOBBoxCollisionTestClass *renSharpOBBoxCollisionTestClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void RenSharpOBBoxCollisionTestClassSetResult(::RenSharpOBBoxCollisionTestClass *thisPtr, const ::CastResultStruct *res);
	
		[DllImport(RenSharpPluginName)]
		extern "C" ::OBBoxCollisionTestClass *CreateOBBoxCollisionTestClass1(const ::OBBoxClass *obbox, const ::Vector3 *move, ::Collision_Type collisionType);

		[DllImport(RenSharpPluginName)]
		extern "C" ::OBBoxCollisionTestClass *CreateOBBoxCollisionTestClass2(const ::OBBoxClass *obbox, const ::Vector3 *move);

		[DllImport(RenSharpPluginName)]
		extern "C" ::OBBoxCollisionTestClass *CreateOBBoxCollisionTestClass3(const ::OBBoxCollisionTestClass *that, const ::Matrix3D *tm);

		[DllImport(RenSharpPluginName)]
		extern "C" ::OBBoxCollisionTestClass *CreateOBBoxCollisionTestClass4(const ::AABoxCollisionTestClass *that, const ::Matrix3D *tm);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyOBBoxCollisionTestClass(::OBBoxCollisionTestClass *oBBoxCollisionTestClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::MultiListNodeClass *CreateMultiListNodeClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyMultiListNodeClass(::MultiListNodeClass *multiListNodeClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::GenericMultiListClass *CreateGenericMultiListClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyGenericMultiListClass(::GenericMultiListClass *genericMultiListClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::GenericMultiListIterator *CreateGenericMultiListIterator(const ::GenericMultiListClass *list);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyGenericMultiListIterator(::GenericMultiListIterator *genericMultiListIterator);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RefMultiListClass<::StaticPhysClass> *CreateStaticPhysClassRefMultiListClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyStaticPhysClassRefMultiListClass(::RefMultiListClass<::StaticPhysClass> *staticPhysClassRefMultiListClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RefMultiListIterator<::StaticPhysClass> *CreateStaticPhysClassRefMultiListIterator(::RefMultiListClass<::StaticPhysClass> *list);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyStaticPhysClassRefMultiListIterator(::RefMultiListIterator<::StaticPhysClass> *staticPhysClassRefMultiListIterator);
	
		[DllImport(RenSharpPluginName)]
		extern "C" ::RefMultiListClass<::BuildingAggregateClass> *CreateBuildingAggregateClassRefMultiListClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyBuildingAggregateClassRefMultiListClass(::RefMultiListClass<::BuildingAggregateClass> *BuildingAggregateClassRefMultiListClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RefMultiListIterator<::BuildingAggregateClass> *CreateBuildingAggregateClassRefMultiListIterator(::RefMultiListClass<::BuildingAggregateClass> *list);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyBuildingAggregateClassRefMultiListIterator(::RefMultiListIterator<::BuildingAggregateClass> *BuildingAggregateClassRefMultiListIterator);
	
		[DllImport(RenSharpPluginName)]
		extern "C" ::RefMultiListClass<::LightPhysClass> *CreateLightPhysClassRefMultiListClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyLightPhysClassRefMultiListClass(::RefMultiListClass<::LightPhysClass> *LightPhysClassRefMultiListClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RefMultiListIterator<::LightPhysClass> *CreateLightPhysClassRefMultiListIterator(::RefMultiListClass<::LightPhysClass> *list);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyLightPhysClassRefMultiListIterator(::RefMultiListIterator<::LightPhysClass> *LightPhysClassRefMultiListIterator);

		[DllImport(RenSharpPluginName)]
		extern "C" ::IntersectionTestClass *CreateIntersectionTestClass(int collisionType);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyIntersectionTestClass(::IntersectionTestClass *intersectionTestClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::AABoxIntersectionTestClass *CreateAABoxIntersectionTestClass(const ::AABoxClass *box, int collisionType);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyAABoxIntersectionTestClass(::AABoxIntersectionTestClass *aaBoxIntersectionTestClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::OBBoxIntersectionTestClass *CreateOBBoxIntersectionTestClass1(const ::OBBoxClass *box, int collisionType);

		[DllImport(RenSharpPluginName)]
		extern "C" ::OBBoxIntersectionTestClass *CreateOBBoxIntersectionTestClass2(const ::OBBoxIntersectionTestClass *that, const ::Matrix3D *tm);

		[DllImport(RenSharpPluginName)]
		extern "C" ::OBBoxIntersectionTestClass *CreateOBBoxIntersectionTestClass3(const ::AABoxIntersectionTestClass *that, const ::Matrix3D *tm);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyOBBoxIntersectionTestClass(::OBBoxIntersectionTestClass *oBBoxIntersectionTestClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::MultiListClass<::PhysClass> *CreatePhysClassMultiListClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyPhysClassMultiListClass(::MultiListClass<::PhysClass> *PhysClassMultiListClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::MultiListIterator<::PhysClass> *CreatePhysClassMultiListIterator(::MultiListClass<::PhysClass> *list);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyPhysClassMultiListIterator(::MultiListIterator<::PhysClass> *PhysClassMultiListIterator);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpPhysAABoxIntersectionTestClass *CreateRenSharpPhysAABoxIntersectionTestClass(const ::AABoxClass *box, int colGroup, int colType, bool enableResultList);

		[DllImport(RenSharpPluginName)]
		extern "C" ::MultiListClass<::PhysClass> *GetRenSharpPhysAABoxIntersectionResultList(::RenSharpPhysAABoxIntersectionTestClass *thisPtr);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyRenSharpPhysAABoxIntersectionTestClass(::RenSharpPhysAABoxIntersectionTestClass *renSharpPhysAABoxIntersectionTestClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpPhysOBBoxIntersectionTestClass *CreateRenSharpPhysOBBoxIntersectionTestClass(const ::OBBoxClass *box, int colGroup, int colType, bool enableResultList);

		[DllImport(RenSharpPluginName)]
		extern "C" ::MultiListClass<::PhysClass> *GetRenSharpPhysOBBoxIntersectionTestClassResultList(::RenSharpPhysOBBoxIntersectionTestClass *thisPtr);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyRenSharpPhysOBBoxIntersectionTestClass(::RenSharpPhysOBBoxIntersectionTestClass *renSharpPhysOBBoxIntersectionTestClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpPhysMeshIntersectionTestClass *CreateRenSharpPhysMeshIntersectionTestClass(::MeshClass *mesh, int colGroup, int colType, bool enableResultList);

		[DllImport(RenSharpPluginName)]
		extern "C" ::MultiListClass<::PhysClass> *GetRenSharpPhysMeshIntersectionTestClassResultList(::RenSharpPhysMeshIntersectionTestClass *thisPtr);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyRenSharpPhysMeshIntersectionTestClass(::RenSharpPhysMeshIntersectionTestClass *renSharpPhysMeshIntersectionTestClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::PhysAABoxIntersectionTestClass *CreatePhysAABoxIntersectionTestClass(const ::AABoxClass *box, int colGroup, int colType);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyPhysAABoxIntersectionTestClass(::PhysAABoxIntersectionTestClass *physAABoxIntersectionTestClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::PhysOBBoxIntersectionTestClass *CreatePhysOBBoxIntersectionTestClass(const ::OBBoxClass *box, int colGroup, int colType);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyPhysOBBoxIntersectionTestClass(::PhysOBBoxIntersectionTestClass *physOBBoxIntersectionTestClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::PhysMeshIntersectionTestClass *CreatePhysMeshIntersectionTestClass(::MeshClass *mesh, int colGroup, int colType);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyPhysMeshIntersectionTestClass(::PhysMeshIntersectionTestClass *physMeshIntersectionTestClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::ScriptCommandsClass *CreateScriptCommandsClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyScriptCommandsClass(::ScriptCommandsClass *scriptCommandsClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::PhysRayCollisionTestClass *CreatePhysRayCollisionTestClass1(const ::LineSegClass *ray, ::Collision_Group_Type group, ::Collision_Type type);

		[DllImport(RenSharpPluginName)]
		extern "C" ::PhysRayCollisionTestClass *CreatePhysRayCollisionTestClass2(const ::LineSegClass *ray, ::Collision_Group_Type group);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyPhysRayCollisionTestClass(::PhysRayCollisionTestClass *physRayCollisionTestClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpPhysRayCollisionTestClass *CreateRenSharpPhysRayCollisionTestClass1(const ::LineSegClass *ray, ::Collision_Group_Type group, ::Collision_Type type);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpPhysRayCollisionTestClass *CreateRenSharpPhysRayCollisionTestClass2(const ::LineSegClass *ray, ::Collision_Group_Type group);

		[DllImport(RenSharpPluginName)]
		extern "C" void RenSharpPhysRayCollisionTestClassSetResult(::RenSharpPhysRayCollisionTestClass *thisPtr, const ::CastResultStruct *res);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyRenSharpPhysRayCollisionTestClass(::RenSharpPhysRayCollisionTestClass *renSharpPhysRayCollisionTestClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::PhysAABoxCollisionTestClass *CreatePhysAABoxCollisionTestClass1(const ::AABoxClass *box, const ::Vector3 *move, ::Collision_Group_Type group, ::Collision_Type type);

		[DllImport(RenSharpPluginName)]
		extern "C" ::PhysAABoxCollisionTestClass *CreatePhysAABoxCollisionTestClass2(const ::AABoxClass *box, const ::Vector3 *move, ::Collision_Group_Type group);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyPhysAABoxCollisionTestClass(::PhysAABoxCollisionTestClass *physAABoxCollisionTestClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpPhysAABoxCollisionTestClass *CreateRenSharpPhysAABoxCollisionTestClass1(const ::AABoxClass *box, const ::Vector3 *move, ::Collision_Group_Type group, ::Collision_Type type);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpPhysAABoxCollisionTestClass *CreateRenSharpPhysAABoxCollisionTestClass2(const ::AABoxClass *box, const ::Vector3 *move, ::Collision_Group_Type group);

		[DllImport(RenSharpPluginName)]
		extern "C" void RenSharpPhysAABoxCollisionTestClassSetResult(::RenSharpPhysAABoxCollisionTestClass *thisPtr, const ::CastResultStruct *res);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyRenSharpPhysAABoxCollisionTestClass(::RenSharpPhysAABoxCollisionTestClass *renSharpPhysAABoxCollisionTestClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::PhysOBBoxCollisionTestClass *CreatePhysOBBoxCollisionTestClass1(const ::OBBoxClass *box, const ::Vector3 *move, ::Collision_Group_Type group, ::Collision_Type type);

		[DllImport(RenSharpPluginName)]
		extern "C" ::PhysOBBoxCollisionTestClass *CreatePhysOBBoxCollisionTestClass2(const ::OBBoxClass *box, const ::Vector3 *move, ::Collision_Group_Type group);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyPhysOBBoxCollisionTestClass(::PhysOBBoxCollisionTestClass *physOBBoxCollisionTestClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpPhysOBBoxCollisionTestClass *CreateRenSharpPhysOBBoxCollisionTestClass1(const ::OBBoxClass *box, const ::Vector3 *move, ::Collision_Group_Type group, ::Collision_Type type);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpPhysOBBoxCollisionTestClass *CreateRenSharpPhysOBBoxCollisionTestClass2(const ::OBBoxClass *box, const ::Vector3 *move, ::Collision_Group_Type group);

		[DllImport(RenSharpPluginName)]
		extern "C" void RenSharpPhysOBBoxCollisionTestClassSetResult(::RenSharpPhysOBBoxCollisionTestClass *thisPtr, const ::CastResultStruct *res);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyRenSharpPhysOBBoxCollisionTestClass(::RenSharpPhysOBBoxCollisionTestClass *renSharpPhysOBBoxCollisionTestClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RefMultiListClass<::MaterialEffectClass> *CreateMaterialEffectClassRefMultiListClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyMaterialEffectClassRefMultiListClass(::RefMultiListClass<::MaterialEffectClass> *MaterialEffectClassRefMultiListClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RefMultiListIterator<::MaterialEffectClass> *CreateMaterialEffectClassRefMultiListIterator(::RefMultiListClass<::MaterialEffectClass> *list);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyMaterialEffectClassRefMultiListIterator(::RefMultiListIterator<::MaterialEffectClass> *MaterialEffectClassRefMultiListIterator);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyGenericSLNode(::GenericSLNode *genericSLNode);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroycPlayerSLNode(::SLNode<::cPlayer> *cPlayerSLNode);

		[DllImport(RenSharpPluginName)]
		extern "C" ::SList<::cPlayer> *CreatecPlayerSList();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroycPlayerSList(::SList<::cPlayer> *cPlayerSList);

		[DllImport(RenSharpPluginName)]
		extern "C" ::GameDefinition *CreateGameDefinition();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyGameDefinition(::GameDefinition *gameDefinition);

		[DllImport(RenSharpPluginName)]
		extern "C" ::SimpleVecClass<uint32> *Createuint32SimpleVecClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::SimpleVecClass<uint32> *Createuint32SimpleVecClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void Destroyuint32SimpleVecClass(::SimpleVecClass<uint32> *uint32SimpleVecClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::HashTemplateClass<::StringClass, ::GameDefinition> *CreateStringClassGameDefinitionHashTemplateClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyStringClassGameDefinitionHashTemplateClass(::HashTemplateClass<::StringClass, ::GameDefinition> *stringClassGameDefinitionHashTemplateClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::HashTemplateIterator<::StringClass, ::GameDefinition> *CreateStringClassGameDefinitionHashTemplateIterator(::HashTemplateClass<::StringClass, ::GameDefinition> *table);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyStringClassGameDefinitionHashTemplateIterator(::HashTemplateIterator<::StringClass, ::GameDefinition> *stringClassGameDefinitionHashTemplateIterator);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyCollideableObjClass(void *collideableObjClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyCollideableObjClassDynamicVectorClass(void *collideableObjClassDynamicVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroySceneIterator(::SceneIterator *sceneIterator);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<int> *CreateInt32DynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<int> *CreateInt32DynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyInt32DynamicVectorClass(::DynamicVectorClass<int> *int32DynamicVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" float *CreateFloatArray(std::size_t size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyFloatArray(float *fArray);

		[DllImport(RenSharpPluginName)]
		extern "C" uint32 *CreateUInt32();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyUInt32(uint32 *i);

		[DllImport(RenSharpPluginName)]
		extern "C" ::PivotClass *CreatePivotClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyPivotClass(::PivotClass *pivotClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::Gap_ListNode *CreateGap_ListNode();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyGap_ListNode(::Gap_ListNode *gap_ListNode);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyPrototypeClass(::PrototypeClass *prototypeClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyPrototypeLoaderClass(::PrototypeLoaderClass *prototypeLoaderClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::PrimitivePrototypeClass *CreatePrimitivePrototypeClass(::RenderObjClass *proto);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyConsoleFunctionClass(::ConsoleFunctionClass *consoleFunctionClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpConsoleFunctionClass *CreateRenSharpConsoleFunctionClass(const char *name, const char *alias, const char *help);
	
		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::ConsoleFunctionClass *> *CreateConsoleFunctionClassPtrDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::ConsoleFunctionClass *> *CreateConsoleFunctionClassPtrDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyConsoleFunctionClassPtrDynamicVectorClass(::DynamicVectorClass<::ConsoleFunctionClass *> *ConsoleFunctionClassPtrDynamicVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::WWAudioClass::DRIVER_INFO_STRUCT *CreateDriverInfoStruct();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDriverInfoStruct(::WWAudioClass::DRIVER_INFO_STRUCT *driverInfoStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyWWAudioClass(::WWAudioClass *wwAudioClasse);

		[DllImport(RenSharpPluginName)]
		extern "C" ::SimpleDynVecClass<::ScriptableGameObj *> *CreateScriptableGameObjPtrSimpleDynVecClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::SimpleDynVecClass<::ScriptableGameObj *> *CreateScriptableGameObjPtrSimpleDynVecClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyScriptableGameObjPtrSimpleDynVecClass(::SimpleDynVecClass<::ScriptableGameObj *> *ScriptableGameObjPtrSimpleDynVecClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyBaseGameObjSLNode(::SLNode<::BaseGameObj> *BaseGameObjSLNode);

		[DllImport(RenSharpPluginName)]
		extern "C" ::SList<::BaseGameObj> *CreateBaseGameObjSList();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyBaseGameObjSList(::SList<::BaseGameObj> *BaseGameObjSList);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyBuildingGameObjSLNode(::SLNode<::BuildingGameObj> *BuildingGameObjSLNode);

		[DllImport(RenSharpPluginName)]
		extern "C" ::SList<::BuildingGameObj> *CreateBuildingGameObjSList();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyBuildingGameObjSList(::SList<::BuildingGameObj> *BuildingGameObjSList);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroySoldierGameObjSLNode(::SLNode<::SoldierGameObj> *SoldierGameObjSLNode);

		[DllImport(RenSharpPluginName)]
		extern "C" ::SList<::SoldierGameObj> *CreateSoldierGameObjSList();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroySoldierGameObjSList(::SList<::SoldierGameObj> *SoldierGameObjSList);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroySmartGameObjSLNode(::SLNode<::SmartGameObj> *SmartGameObjSLNode);

		[DllImport(RenSharpPluginName)]
		extern "C" ::SList<::SmartGameObj> *CreateSmartGameObjSList();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroySmartGameObjSList(::SList<::SmartGameObj> *SmartGameObjSList);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyC4GameObjSLNode(::SLNode<::C4GameObj> *C4GameObjSLNode);

		[DllImport(RenSharpPluginName)]
		extern "C" ::SList<::C4GameObj> *CreateC4GameObjSList();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyC4GameObjSList(::SList<::C4GameObj> *C4GameObjSList);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyBeaconGameObjSLNode(::SLNode<::BeaconGameObj> *BeaconGameObjSLNode);

		[DllImport(RenSharpPluginName)]
		extern "C" ::SList<::BeaconGameObj> *CreateBeaconGameObjSList();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyBeaconGameObjSList(::SList<::BeaconGameObj> *BeaconGameObjSList);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyVehicleGameObjSLNode(::SLNode<::VehicleGameObj> *VehicleGameObjSLNode);

		[DllImport(RenSharpPluginName)]
		extern "C" ::SList<::VehicleGameObj> *CreateVehicleGameObjSList();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyVehicleGameObjSList(::SList<::VehicleGameObj> *VehicleGameObjSList);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyScriptZoneGameObjSLNode(::SLNode<::ScriptZoneGameObj> *ScriptZoneGameObjSLNode);

		[DllImport(RenSharpPluginName)]
		extern "C" ::SList<::ScriptZoneGameObj> *CreateScriptZoneGameObjSList();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyScriptZoneGameObjSList(::SList<::ScriptZoneGameObj> *ScriptZoneGameObjSList);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDAEventClass(::DAEventClass* daEventClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DAEventStruct* CreateDAEventStruct();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDAEventStruct(::DAEventStruct* daEventStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DAObjectEventStruct* CreateDAObjectEventStruct();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDAObjectEventStruct(::DAObjectEventStruct* daObjectEventStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DAEventTimerStruct* CreateDAEventTimerStruct();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDAEventTimerStruct(::DAEventTimerStruct* daEventTimerStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpEventClass* CreateRenSharpEventClass();

		[DllImport(RenSharpPluginName)]
		extern "C" ::cGameDataEvent* CreatecGameDataEvent(bool a, int b);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroycGameDataEvent(::cGameDataEvent* cGameDataEvent);

		[DllImport(RenSharpPluginName)]
		extern "C" ::Signaler<::cGameDataEvent>* CreatecGameDataEventSignaler();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroycGameDataEventSignaler(::Signaler<::cGameDataEvent>* cGameDataEventSignaler);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::WideStringClass>* CreateWideStringClassDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::WideStringClass>* CreateWideStringClassDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyWideStringClassDynamicVectorClass(::DynamicVectorClass<::WideStringClass>* WideStringClassDynamicVectorClass);
	
		[DllImport(RenSharpPluginName)]
		extern "C" ::DABanEntryClass* CreateDABanEntryClass(const char* name, const char* ip, const char* serial, const char* reason);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDABanEntryClass(::DABanEntryClass* daBanEntryClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DABanListClass* CreateDABanListClass(const char* name, const char* fileName);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDABanListClass(::DABanListClass* daBanListClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDAChatCommandClass(::DAChatCommandClass* daChatCommandClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DAEventChatCommandStruct* CreateDAEventChatCommandStruct();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDAEventChatCommandStruct(::DAEventChatCommandStruct* daEventChatCommandStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDAKeyHookClass(::DAKeyHookClass* daKeyHookClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DAEventKeyHookStruct* CreateDAEventKeyHookStruct();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDAEventKeyHookStruct(::DAEventKeyHookStruct* daEventKeyHookStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DADamageEventStruct* CreateDADamageEventStruct();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDADamageEventStruct(::DADamageEventStruct* daDamageEventStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DADamageTableStruct* CreateDADamageTableStruct1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DADamageTableStruct* CreateDADamageTableStruct2(::cPlayer* player, float damage);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDADamageTableStruct(::DADamageTableStruct* daDamageTableStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::DADamageTableStruct>* CreateDADamageTableStructDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::DADamageTableStruct>* CreateDADamageTableStructDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDADamageTableStructDynamicVectorClass(::DynamicVectorClass<::DADamageTableStruct>* DADamageTableStructDynamicVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDADamageEventStructSLNode(::SLNode<::DADamageEventStruct>* DADamageEventStructSLNode);

		[DllImport(RenSharpPluginName)]
		extern "C" ::SList<::DADamageEventStruct>* CreateDADamageEventStructSList();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDADamageEventStructSList(::SList<::DADamageEventStruct>* DADamageEventStructSList);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DADamageTableStruct* CreateDADamageTableStructArray(std::size_t size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDADamageTableStructArray(::DADamageTableStruct* daDamageTableStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<const ::DefinitionClass*>* CreateConstDefinitionClassPtrDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<const ::DefinitionClass*>* CreateConstDefinitionClassPtrDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyConstDefinitionClassPtrDynamicVectorClass(::DynamicVectorClass<const ::DefinitionClass*>* ConstDefinitionClassPtrDynamicVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DACharacterDisableListStruct* CreateDACharacterDisableListStruct();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDACharacterDisableListStruct(::DACharacterDisableListStruct* daCharacterDisableListStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDAGameModeFactoryClass(::DAGameModeFactoryClass* daGameModeFactoryClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDAGameModeClass(::DAGameModeClass* daGameModeClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDAGameFeatureFactoryClass(::DAGameFeatureFactoryClass* daGameFeatureFactoryClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDAGameFeatureClass(::DAGameFeatureClass* daGameFeatureClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::DAGameFeatureFactoryClass*>* CreateDAGameFeatureFactoryClassPtrDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::DAGameFeatureFactoryClass*>* CreateDAGameFeatureFactoryClassPtrDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDAGameFeatureFactoryClassPtrDynamicVectorClass(::DynamicVectorClass<::DAGameFeatureFactoryClass*>* DAGameFeatureFactoryClassPtrDynamicVector);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpGameFeatureFactoryClass* CreateRenSharpGameFeatureFactoryClass(const char* name, const char* enableSetting, const char* requiredData);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpGameFeatureClass* CreateRenSharpGameFeatureClass();

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpPlayerDataFactoryClass* CreateRenSharpPlayerDataFactoryClass();

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpPlayerDataClass* CreateRenSharpPlayerDataClass();

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpGameModeFactoryClass* CreateRenSharpGameModeFactoryClass(const char* shortName, const char* longName, const char* requiredData);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpGameModeClass* CreateRenSharpGameModeClass();

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpGameFeatureEventClass* CreateRenSharpGameFeatureEventClass(::RenSharpEventClass** eventClassPtr, ::RenSharpGameFeatureClass** gameFeaturePtr);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpGameFeatureEventClassPlayerDataFactory* CreateRenSharpGameFeatureEventClassPlayerDataFactory(::RenSharpEventClass** eventClassPtr, ::RenSharpGameFeatureClass** gameFeaturePtr, ::RenSharpPlayerDataFactoryClass** playerDataFactoryPtr);
	
		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpGameModeEventClass* CreateRenSharpGameModeEventClass(::RenSharpEventClass** eventClassPtr, ::RenSharpGameModeClass** gameModePtr);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpGameModeEventClassPlayerDataFactory* CreateRenSharpGameModeEventClassPlayerDataFactory(::RenSharpEventClass** eventClassPtr, ::RenSharpGameModeClass** gameModePtr, ::RenSharpPlayerDataFactoryClass** playerDataFactoryPtr);
	
		[DllImport(RenSharpPluginName)]
		extern "C" ::DATimedInvincibilityObserverClass* CreateDATimedInvincibilityObserverClass(float protectTime);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DAAttachToObjectWithZOffsetObserverClass* CreateDAAttachToObjectWithZOffsetObserverClass(::ScriptableGameObj* host, float offset, float syncTime);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DANoPointsUntilEnteredObserverClass* CreateDANoPointsUntilEnteredObserverClass();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<const ::WeaponDefinitionClass*>* CreateConstWeaponDefinitionClassPtrDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<const ::WeaponDefinitionClass*>* CreateConstWeaponDefinitionClassPtrDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyConstWeaponDefinitionClassPtrDynamicVectorClass(::DynamicVectorClass<const ::WeaponDefinitionClass*>* ConstWeaponDefinitionClassPtrDynamicVectorClass);
	
		[DllImport(RenSharpPluginName)]
		extern "C" ::HashTemplateClass<unsigned int, ::DynamicVectorClass<const ::WeaponDefinitionClass*>>* CreateUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass();
	
		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass(::HashTemplateClass<unsigned int, ::DynamicVectorClass<const ::WeaponDefinitionClass*>>* UInt32ConstWeaponDefinitionClassPtrDynamicVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::HashTemplateIterator<unsigned int, ::DynamicVectorClass<const ::WeaponDefinitionClass*>>* CreateUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator(::HashTemplateClass<unsigned int, ::DynamicVectorClass<const ::WeaponDefinitionClass*>>* table);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator(::HashTemplateIterator<unsigned int, ::DynamicVectorClass<const ::WeaponDefinitionClass*>>* UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassIterator);
	
		[DllImport(RenSharpPluginName)]
		extern "C" ::HashTemplateClass<unsigned int, const ::WeaponDefinitionClass*>* CreateUInt32ConstWeaponDefinitionClassPtrHashTemplateClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyUInt32ConstWeaponDefinitionClassPtrHashTemplateClass(::HashTemplateClass<unsigned int, const ::WeaponDefinitionClass*>* UInt32ConstWeaponDefinitionClassPtrHashTemplateClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::HashTemplateIterator<unsigned int, const ::WeaponDefinitionClass*>* CreateUInt32ConstWeaponDefinitionClassPtrHashTemplateIterator(::HashTemplateClass<unsigned int, const ::WeaponDefinitionClass*>* table);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyUInt32ConstWeaponDefinitionClassPtrHashTemplateIterator(::HashTemplateIterator<unsigned int, const ::WeaponDefinitionClass*>* UInt32ConstWeaponDefinitionClassPtrHashTemplateIterator);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyPlugin(::Plugin* plugin);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDACrateModifierFactoryClass(::DACrateModifierFactoryClass* daCrateModifierFactoryClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDACrateModifierClass(::DACrateModifierClass* daCrateModifierClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDACrateFactoryClass(::DACrateFactoryClass* daCrateFactoryClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDACrateClass(::DACrateClass* daCrateClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::DACrateModifierClass*>* CreateDACrateModifierClassPtrDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::DACrateModifierClass*>* CreateDACrateModifierClassPtrDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDACrateModifierClassPtrDynamicVectorClass(::DynamicVectorClass<::DACrateModifierClass*>* DACrateModifierClassPtrDynamicVector);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::DACrateFactoryClass*>* CreateDACrateFactoryClassPtrDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::DACrateFactoryClass*>* CreateDACrateFactoryClassPtrDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDACrateFactoryClassPtrDynamicVectorClass(::DynamicVectorClass<::DACrateFactoryClass*>* DACrateFactoryClassPtrDynamicVector);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::DACrateModifierFactoryClass*>* CreateDACrateModifierFactoryClassPtrDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::DACrateModifierFactoryClass*>* CreateDACrateModifierFactoryClassPtrDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDACrateModifierFactoryClassPtrDynamicVectorClass(::DynamicVectorClass<::DACrateModifierFactoryClass*>* DACrateModifierFactoryClassPtrDynamicVector);
	
		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::PhysicalGameObj*>* CreatePhysicalGameObjPtrDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::PhysicalGameObj*>* CreatePhysicalGameObjPtrDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyPhysicalGameObjPtrDynamicVectorClass(::DynamicVectorClass<::PhysicalGameObj*>* PhysicalGameObjPtrDynamicVector);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::Vector3>* CreateVector3DynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::Vector3>* CreateVector3DynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyVector3DynamicVectorClass(::DynamicVectorClass<::Vector3>* Vector3DynamicVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::Vector3*>* CreateVector3PtrDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::Vector3*>* CreateVector3PtrDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyVector3PtrDynamicVectorClass(::DynamicVectorClass<::Vector3*>* Vector3PtrDynamicVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpCrateModifierFactoryClass* CreateRenSharpCrateModifierFactoryClass(const char* name);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpCrateModifierClass* CreateRenSharpCrateModifierClass();

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpCrateClass* CreateRenSharpCrateClass();

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpCrateFactoryClass* CreateRenSharpCrateFactoryClass(const char* name, ::DACrateType::Type type);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DACharacterRefundsPlayerDataClass* CreateDACharacterRefundsPlayerDataClass();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DAChatSoundsPlayerDataClass* CreateDAChatSoundsPlayerDataClass();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DALootPlayerDataClass* CreateDALootPlayerDataClass();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DALootPowerUpClass* CreateDALootPowerUpClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DALootPowerUpClass* CreateDALootPowerUpClass2(::SoldierGameObj* soldier);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DALootBackpackClass* CreateDALootBackpackClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DALootBackpackClass* CreateDALootBackpackClass2(::SoldierGameObj* soldier);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DALootDNAClass* CreateDALootDNAClass1(const ::SoldierGameObjDef* charDef);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DALootDNAClass* CreateDALootDNAClass2(::SoldierGameObj* soldier);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DALootGameFeatureClass* CreateDALootGameFeatureClass();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::cPlayer*>* CreatecPlayerPtrDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::cPlayer*>* CreatecPlayerPtrDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroycPlayerPtrDynamicVectorClass(::DynamicVectorClass<::cPlayer*>* cPlayerPtrDynamicVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DAExtraRadioCommandsPlayerDataClass* CreateDAExtraRadioCommandsPlayerDataClass();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DARTCStruct* CreateDARTCStruct1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DARTCStruct* CreateDARTCStruct2(::cPlayer* player);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDARTCStruct(::DARTCStruct* daRTCStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DARTCPlayerDataClass* CreateDARTCPlayerDataClass();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DASquadInviteStruct* CreateDASquadInviteStruct1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DASquadInviteStruct* CreateDASquadInviteStruct2(::cPlayer* leader, ::cPlayer* player);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDASquadInviteStruct(::DASquadInviteStruct* daSquadInviteStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DASquadRemixStruct* CreateDASquadRemixStruct1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DASquadRemixStruct* CreateDASquadRemixStruct2(::DASquadClass* squad, int team);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDASquadRemixStruct(::DASquadRemixStruct* daSquadRemixStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DASquadMemberClass* CreateDASquadMemberClass(::DASquadClass* squad);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DASquadClass* CreateDASquadClass(::cPlayer* player);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDASquadClass(::DASquadClass* daSquadClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DASquadManagerClass* CreateDASquadManagerClass();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DAVehicleOwnershipObserverClass* CreateDAVehicleOwnershipObserverClass(::VehicleGameObj* vehicle, ::cPlayer* player);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DAVehicleShellStruct* CreateDAVehicleShellStruct();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDAVehicleShellStruct(::DAVehicleShellStruct* daVehicleShellStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DASpawnNodeClass* CreateDASpawnNodeClass();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DASpawnPlayerDataClass* CreateDASpawnPlayerDataClass();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DASpawnPointClass::DistanceCheckStruct* CreateDistanceCheckStruct();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDistanceCheckStruct(::DASpawnPointClass::DistanceCheckStruct* distanceCheckStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DASpawnNodeClass* CreateNodeDASpawnNodeClass(const ::INIClass* ini, const ::StringClass* header);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DANodeManagerClass* CreateInstanceDANodeManagerClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyInstanceDANodeManagerClass();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DANodeManagerClass* GetInstanceDANodeManagerClass();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DASpawnManagerClass* CreateInstanceDASpawnManagerClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyInstanceDASpawnManagerClass();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DASpawnManagerClass* GetInstanceDASpawnManagerClass();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DASpawnPointClass* CreateSpawnPointDASpawnManagerClass(::DASpawnManagerClass* thisPtr, const ::INIClass* ini, const ::StringClass* header);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RenSharpNodeClass* CreateRenSharpNodeClass(const char* type);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DATeleporterManagerClass* CreateInstanceDATeleporterManagerClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyInstanceDATeleporterManagerClass();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DATeleporterManagerClass* GetInstanceDATeleporterManagerClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDATeleporterManagerClass(::DATeleporterManagerClass* daTeleporterManagerClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DATeleporterClass* CreateTeleporterDATeleporterManagerClass(::DATeleporterManagerClass* thisPtr, const ::INIClass* ini, const ::StringClass* header);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DAVehicleSpawnManagerClass* CreateInstanceDAVehicleSpawnManagerClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyInstanceDAVehicleSpawnManagerClass();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DAVehicleSpawnManagerClass* GetInstanceDAVehicleSpawnManagerClass();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DAVehicleSpawnPointClass* CreateSpawnPointDAVehicleSpawnManagerClass(::DAVehicleSpawnManagerClass* thisPtr, const ::INIClass* ini, const ::StringClass* header);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DAVehicleAirDropPointClass* CreateAirDropPointDAVehicleSpawnManagerClass(::DAVehicleSpawnManagerClass* thisPtr, const ::INIClass* ini, const ::StringClass* header);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::DAVehicleSpawnPointClass*>* CreateDAVehicleSpawnPointClassPtrDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::DAVehicleSpawnPointClass*>* CreateDAVehicleSpawnPointClassPtrDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDAVehicleSpawnPointClassPtrDynamicVectorClass(::DynamicVectorClass<::DAVehicleSpawnPointClass*>* DAVehicleSpawnPointClassPtrDynamicVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyConnectionAcceptanceFilter(::ConnectionAcceptanceFilter* connectionAcceptanceFilter);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyParameterClass(::ParameterClass* parameterClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::ParameterListClass* CreateParameterListClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyParameterListClass(::ParameterListClass* parameterListClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void FreeParametersParameterListClass(::ParameterListClass* thisPtr);

		[DllImport(RenSharpPluginName)]
		extern "C" ::AABTreeCullSystemClass::StatsStruct* CreateAABTreeCullSystemClassStatsStruct();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyAABTreeCullSystemClassStatsStruct(::AABTreeCullSystemClass::StatsStruct* statsStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyAABTreeIterator(::AABTreeIterator* aabTreeIterator);

		[DllImport(RenSharpPluginName)]
		extern "C" ::AABTreeNodeClass::SplitChoiceStruct* CreateAABTreeNodeClassSplitChoiceStruct();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyAABTreeNodeClassSplitChoiceStruct(::AABTreeNodeClass::SplitChoiceStruct* splitChoiceStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" ::AABTreeLinkClass* CreateAABTreeLinkClass(::AABTreeCullSystemClass* system);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RawFileClass* CreateRawFileClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::RawFileClass* CreateRawFileClass2(const char* filename);

		[DllImport(RenSharpPluginName)]
		extern "C" ::TextFileClass* CreateTextFileClass();

		[DllImport(RenSharpPluginName)]
		extern "C" ::BufferedFileClass* CreateBufferedFileClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyCombatNetworkHandlerClass(::CombatNetworkHandlerClass* combatNetworkHandlerClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyCombatMiscHandlerClass(::CombatMiscHandlerClass* combatMiscHandlerClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::CommandLineParser* CreateCommandLineParser(const char* command);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyCommandLineParser(::CommandLineParser* commandLineParser);

		[DllImport(RenSharpPluginName)]
		extern "C" ::ConversationRemarkClass* CreateConversationRemarkClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyConversationRemarkClass(::ConversationRemarkClass* conversationRemarkClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::OratorClass* CreateOratorClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyOratorClass(::OratorClass* oratorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyDefinitionFactoryClass(::DefinitionFactoryClass* definitionFactoryClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::GridListIterator* CreateGridListIterator(::CullableClass* head);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyGridListIterator(::GridListIterator* gridListIterator);

		[DllImport(RenSharpPluginName)]
		extern "C" void* CreateGridCullSystemClassVolumeStruct1();

		[DllImport(RenSharpPluginName)]
		extern "C" void* CreateGridCullSystemClassVolumeStruct2(int i0, int j0, int k0, int i1, int j1, int k1);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyGridCullSystemClassVolumeStruct(void* volumeStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" ::GridCullSystemClass::StatsStruct* CreateGridCullSystemClassStatsStruct();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyGridCullSystemClassStatsStruct(::GridCullSystemClass::StatsStruct* statsStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" ::mix_header* Createmix_header();

		[DllImport(RenSharpPluginName)]
		extern "C" void Destroymix_header(::mix_header* header);

		[DllImport(RenSharpPluginName)]
		extern "C" ::MixFileFactoryClass::FileInfoStruct* CreateMixFileFactoryClassFileInfoStruct();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyMixFileFactoryClassFileInfoStruct(::MixFileFactoryClass::FileInfoStruct* fileInfoStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" ::MixFileFactoryClass::AddInfoStruct* CreateMixFileFactoryClassAddInfoStruct();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyMixFileFactoryClassAddInfoStruct(::MixFileFactoryClass::AddInfoStruct* addInfoStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" ::MixFileCreator::FileInfoStruct* CreateMixFileCreatorFileInfoStruct();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyMixFileCreatorFileInfoStruct(::MixFileCreator::FileInfoStruct* fileInfoStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" ::MixClass* CreateMixClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyMixClass(::MixClass* mixClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::MixFileFactoryClass::FileInfoStruct>* CreateMixFileFactoryClassFileInfoStructDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::MixFileFactoryClass::FileInfoStruct>* CreateMixFileFactoryClassFileInfoStructDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyMixFileFactoryClassFileInfoStructDynamicVectorClass(::DynamicVectorClass<::MixFileFactoryClass::FileInfoStruct>* MixFileFactoryClassFileInfoStructDynamicVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::MixFileFactoryClass::AddInfoStruct>* CreateMixFileFactoryClassAddInfoStructDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::MixFileFactoryClass::AddInfoStruct>* CreateMixFileFactoryClassAddInfoStructDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyMixFileFactoryClassAddInfoStructDynamicVectorClass(::DynamicVectorClass<::MixFileFactoryClass::AddInfoStruct>* MixFileFactoryClassAddInfoStructDynamicVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::MixFileCreator::FileInfoStruct>* CreateMixFileCreatorFileInfoStructDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::MixFileCreator::FileInfoStruct>* CreateMixFileCreatorFileInfoStructDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyMixFileCreatorFileInfoStructDynamicVectorClass(::DynamicVectorClass<::MixFileCreator::FileInfoStruct>* MixFileCreatorFileInfoStructDynamicVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::WidgetUserClass* CreateWidgetUserClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyWidgetUserClass(::WidgetUserClass* widgetUserClass);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyPhysicsSceneClassStatsStruct(::PhysicsSceneClass::StatsStruct* statsStruct);

		[DllImport(RenSharpPluginName)]
		extern "C" ::CompressedVisTableClass* CreateCompressedVisTableClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyCompressedVisTableClass(::CompressedVisTableClass* compressedVisTableClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::SimpleVecClass<::VisTableClass*>* CreateVisTableClassPtrSimpleVecClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::SimpleVecClass<::VisTableClass*>* CreateVisTableClassPtrSimpleVecClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyVisTableClassPtrSimpleVecClass(::SimpleVecClass<::VisTableClass*>* visTableClassPtrSimpleVecClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::MultiListClass<::VisTableClass>* CreateVisTableClassMultiListClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyVisTableClassMultiListClass(::MultiListClass<::VisTableClass>* VisTableClassMultiListClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::MultiListIterator<::VisTableClass>* CreateVisTableClassMultiListIterator(::MultiListClass<::VisTableClass>* list);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyVisTableClassMultiListIterator(::MultiListIterator<::VisTableClass>* VisTableClassMultiListIterator);

		[DllImport(RenSharpPluginName)]
		extern "C" ::SimpleDynVecClass<::CompressedVisTableClass*>* CreateCompressedVisTableClassPtrSimpleDynVecClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::SimpleDynVecClass<::CompressedVisTableClass*>* CreateCompressedVisTableClassPtrSimpleDynVecClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyCompressedVisTableClassPtrSimpleDynVecClass(::SimpleDynVecClass<::CompressedVisTableClass*>* CompressedVisTableClassPtrSimpleDynVecClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::VisDecompressionCacheClass* CreateVisDecompressionCacheClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyVisDecompressionCacheClass(::VisDecompressionCacheClass* visDecompressionCacheClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RefMultiListClass<::RenderObjClass>* CreateRenderObjClassRefMultiListClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyRenderObjClassRefMultiListClass(::RefMultiListClass<::RenderObjClass>* RenderObjClassRefMultiListClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RefMultiListIterator<::RenderObjClass>* CreateRenderObjClassRefMultiListIterator(::RefMultiListClass<::RenderObjClass>* list);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyRenderObjClassRefMultiListIterator(::RefMultiListIterator<::RenderObjClass>* RenderObjClassRefMultiListIterator);

		[DllImport(RenSharpPluginName)]
		extern "C" ::MultiListClass<::TexProjectClass>* CreateTexProjectClassMultiListClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyTexProjectClassMultiListClass(::MultiListClass<::TexProjectClass>* TexProjectClassMultiListClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::MultiListIterator<::TexProjectClass>* CreateTexProjectClassMultiListIterator(::MultiListClass<::TexProjectClass>* list);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyTexProjectClassMultiListIterator(::MultiListIterator<::TexProjectClass>* TexProjectClassMultiListIterator);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RefMultiListClass<::PhysClass>* CreatePhysClassRefMultiListClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyPhysClassRefMultiListClass(::RefMultiListClass<::PhysClass>* PhysClassRefMultiListClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::RefMultiListIterator<::PhysClass>* CreatePhysClassRefMultiListIterator(::RefMultiListClass<::PhysClass>* list);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyPhysClassRefMultiListIterator(::RefMultiListIterator<::PhysClass>* PhysClassRefMultiListIterator);

		[DllImport(RenSharpPluginName)]
		extern "C" ::CriticalSectionClass* CreateCriticalSectionClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyCriticalSectionClass(::CriticalSectionClass* criticalSectionClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::FastCriticalSectionClass* CreateFastCriticalSectionClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyFastCriticalSectionClass(::FastCriticalSectionClass* fastCriticalSectionClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::FastCriticalSectionClass::LockClass* CreateFastCriticalSectionClassLockClass(::FastCriticalSectionClass* section);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyFastCriticalSectionClassLockClass(::FastCriticalSectionClass::LockClass* lockClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::Matrix3D>* CreateMatrix3DDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::Matrix3D>* CreateMatrix3DDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyMatrix3DDynamicVectorClass(::DynamicVectorClass<::Matrix3D>* Matrix3DDynamicVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::SysTimeClass* CreateSysTimeClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroySysTimeClass(::SysTimeClass* sysTimeClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::TDBObjClass*>* CreateTDBObjClassPtrDynamicVectorClass1();

		[DllImport(RenSharpPluginName)]
		extern "C" ::DynamicVectorClass<::TDBObjClass*>* CreateTDBObjClassPtrDynamicVectorClass2(int size);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyTDBObjClassPtrDynamicVectorClass(::DynamicVectorClass<::TDBObjClass*>* TDBObjClassPtrDynamicVectorClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::HashTemplateClass<::StringClass, ::TDBObjClass*>* CreateStringClassTDBObjClassPtrHashTemplateClass();

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyStringClassTDBObjClassPtrHashTemplateClass(::HashTemplateClass<::StringClass, ::TDBObjClass*>* stringClassTDBObjClassPtrHashTemplateClass);

		[DllImport(RenSharpPluginName)]
		extern "C" ::HashTemplateIterator<::StringClass, ::TDBObjClass*>* CreateStringClassTDBObjClassPtrHashTemplateIterator(::HashTemplateClass<::StringClass, ::TDBObjClass*>* table);

		[DllImport(RenSharpPluginName)]
		extern "C" void DestroyStringClassTDBObjClassPtrHashTemplateIterator(::HashTemplateIterator<::StringClass, ::TDBObjClass*>* stringClassTDBObjClassPtrHashTemplateIterator);

		[DllImport(RenSharpPluginName)]
		extern "C" float WWMathInvSqrt(float a);

		[DllImport(RenSharpPluginName)]
		extern "C" ::ObserverImpClass* CreateObserverImpClass(const char* name);

		[DllImport(RenSharpPluginName)]
		extern "C" void RenSharpConsoleFunctionClassSetName(::RenSharpConsoleFunctionClass* renSharpConsoleFunctionClass, const char* name);

		[DllImport(RenSharpPluginName)]
		extern "C" void RenSharpConsoleFunctionClassSetAlias(::RenSharpConsoleFunctionClass* renSharpConsoleFunctionClass, const char* alias);

		[DllImport(RenSharpPluginName)]
		extern "C" void RenSharpConsoleFunctionClassSetHelp(::RenSharpConsoleFunctionClass* renSharpConsoleFunctionClass, const char* help);
	}
}