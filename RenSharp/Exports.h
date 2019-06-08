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

#include <RenSharp.h>
#include <engine_vector.h>
#include <engine_io.h>
#include <straw.h>
#include <Vector3.h>
#include <da_settings.h>
#include <NetworkObjectClass.h>
#include <PostLoadableClass.h>
#include <ChunkClass.h>
#include <ReferencerClass.h>
#include <PersistFactoryClass.h>
#include <audiocallback.h>
#include <ReferenceableClass.h>
#include <PhysObserverClass.h>
#include <DialogueClass.h>
#include <da_player.h>
#include <da_token.h>
#include <ConnectionRequest.h>
#include <vector4.h>
#include <BuildingGameObj.h>
#include <plane.h>
#include <multilist.h>
#include <SoundSceneObjClass.h>
#include <scripts.h>
#include <ScriptableGameObj.h>
#include "RenSharpGameObjObserverClass.h"
#include <OffenseObjectClass.h>
#include <LineSegClass.h>
#include <vector2.h>
#include <FrustumClass.h>
#include <CullSystemClass.h>
#include <CullableClass.h>
#include <AnimControlClass.h>
#include <MuzzleRecoilClass.h>
#include <ControlClass.h>
#include <action.h>
#include <PhysControllerClass.h>
#include <TransitionGameObjDef.h>
#include "RenSharpPlayerObserverClass.h"
#include <SoldierGameObj.h>
#include <RenderObjClass.h>
#include <TransitionInstanceClass.h>
#include "RenSharpCollisionTestClass.h"
#include "RenSharpRayCollisionTestClass.h"
#include "RenSharpAABoxCollisionTestClass.h"
#include "RenSharpOBBoxCollisionTestClass.h"
#include <inttest.h>
#include <PhysClass.h>
#include "RenSharpPhysAABoxIntersectionTestClass.h"
#include "RenSharpPhysOBBoxIntersectionTestClass.h"
#include "RenSharpPhysMeshIntersectionTestClass.h"
#include <physcoltest.h>
#include "RenSharpPhysRayCollisionTestClass.h"
#include "RenSharpPhysAABoxCollisionTestClass.h"
#include "RenSharpPhysOBBoxCollisionTestClass.h"
#include <MaterialEffectClass.h>
#include <SList.h>
#include <cPlayer.h>
#include <GameDefinition.h>
#include <HashTemplateClass.h>
#include <HashTemplateIterator.h>
#include <AnimCollisionManagerClass.h>
#include <SceneClass.h>
#include <HTreeClass.h>
#include <engine_tt.h>
#include <prototypeclass.h>
#include <MeshClass.h>
#include "RenSharpConsoleFunctionClass.h"
#include <WWAudioClass.h>
#include <BaseGameObj.h>
#include <BuildingGameObj.h>
#include <SoldierGameObj.h>
#include <SmartGameObj.h>
#include <C4GameObj.h>
#include <BeaconGameObj.h>
#include <VehicleGameObj.h>
#include <ScriptZoneGameObj.h>
#include <da_event.h>
#include "RenSharpEventClass.h"
#include <GameData.h>
#include <da_ban.h>
#include <da_chatcommand.h>
#include <da_damagelog.h>
#include <Definition.h>
#include <da_disable.h>
#include <da_gamemode.h>
#include <da_gamefeature.h>
#include <da_game.h>
#include "RenSharpGameFeatureFactoryClass.h"
#include "RenSharpGameFeatureClass.h"
#include "RenSharpPlayerDataFactoryClass.h"
#include "RenSharpPlayerDataClass.h"
#include "RenSharpGameModeFactoryClass.h"
#include "RenSharpGameModeClass.h"
#include "RenSharpGameFeatureEventClass.h"
#include "RenSharpGameFeatureEventClassPlayerDataFactory.h"
#include "RenSharpGameModeEventClass.h"
#include "RenSharpGameModeEventClassPlayerDataFactory.h"
#include <da_gameobjobservers.h>
#include <weaponmgr.h>
#include <da_ssgm.h>
#include <da_vehicle.h>
#include <da_crate.h>
#include "RenSharpCrateModifierFactoryClass.h"
#include "RenSharpCrateModifierClass.h"
#include "RenSharpCrateClass.h"
#include "RenSharpCrateFactoryClass.h"
#include <da_characterrefunds.h>
#include <da_chatsounds.h>
#include <da_loot.h>
#include <da_radio.h>
#include <da_rtc.h>
#include <da_squad.h>
#include <da_vehicleownership.h>
#include <da_vehicleshells.h>
#include <engine_player.h>
#include <engine_da.h>
#include <da_nodemanager.h>
#include <da_spawnsystem.h>
#include "RenSharpNodeClass.h"
#include <da_teleporter.h>
#include <da_vehiclespawn.h>
#include <ConnectionAcceptanceFilter.h>
#include <Parameter.h>
#include <AABTreeCull.h>
#include <RawFileClass.h>
#include <BufferedFileClass.h>
#include <CombatManager.h>
#include <CommandLineParser.h>
#include <ConversationClass.h>
#include <DefinitionFactoryClass.h>
#include <GridCull.h>
#include <MixFileFactoryClass.h>
#include <WidgetUserClass.h>
#include <PhysicsSceneClass.h>
#include <VisTableClass.h>
#include <VisTableMgrClass.h>
#include <CriticalSectionClass.h>
#include <SysTimeClass.h>
#include <DefaultConnectionAcceptanceFilter.h>
#include <wwmath.h>

class PersistantSurfaceEmitterClass;
class SoldierGameObj;
class StaticPhysClass;
class BuildingAggregateClass;
class LightPhysClass;
class TDBObjClass;

extern "C"
{
	__declspec(dllexport) void __stdcall OnFatalException(const char *exception)
	{
		RenSharpRootEventClass::Get_Instance().On_Fatal_Exception(exception);
	}

	__declspec(dllexport) void __stdcall OnFatalExceptionCallback(const char* exception)
	{
		RenSharpRootEventClass::Get_Instance().On_Fatal_Exception_Callback(exception);
	}

	__declspec(dllexport) bool __stdcall IsShuttingDown()
	{
		return RenSharpRootEventClass::Get_Instance().Is_Shutting_Down();
	}

	__declspec(dllexport) char * __stdcall CreateAnsiString(std::size_t size)
	{
		return new char[size];
	}

	__declspec(dllexport) void __stdcall DestroyAnsiString(const char *str)
	{
		delete[] str;
	}

	__declspec(dllexport) char * __stdcall MallocAnsiString(std::size_t size)
	{
		return reinterpret_cast<char *>(std::malloc(size));
	}

	__declspec(dllexport) void __stdcall FreeAnsiString(char *str)
	{
		std::free(str);
	}

	__declspec(dllexport) GenericNode * __stdcall CreateGenericNode()
	{
		return new GenericNode();
	}

	__declspec(dllexport) void __stdcall DestroyGenericNode(GenericNode *genericNode)
	{
		delete genericNode;
	}

	__declspec(dllexport) GenericList * __stdcall CreateGenericList()
	{
		return new GenericList();
	}

	__declspec(dllexport) void __stdcall DestroyGenericList(GenericList *genericList)
	{
		delete genericList;
	}

	__declspec(dllexport) INIEntry * __stdcall CreateINIEntry(char *entry, char *value)
	{
		return new INIEntry(entry, value);
	}

	__declspec(dllexport) List<INIEntry *> * __stdcall CreateINIEntryList()
	{
		return new List<INIEntry *>();
	}

	__declspec(dllexport) IndexClass<int, INIEntry *> * __stdcall CreateIntINIEntryIndexClass()
	{
		return new IndexClass<int, INIEntry *>();
	}

	__declspec(dllexport) void __stdcall DestroyIntINIEntryIndexClass(IndexClass<int, INIEntry *> *intINIEntryIndexClass)
	{
		delete intINIEntryIndexClass;
	}

	__declspec(dllexport) INISection * __stdcall CreateINISection(char *section)
	{
		return new INISection(section);
	}

	__declspec(dllexport) List<INISection *> * __stdcall CreateINISectionList()
	{
		return new List<INISection *>();
	}

	__declspec(dllexport) void __stdcall DestroyFileClass(FileClass *fileClass)
	{
		delete fileClass;
	}

	__declspec(dllexport) Straw * __stdcall CreateStraw()
	{
		return new Straw();
	}

	__declspec(dllexport) void __stdcall DestroyStraw(Straw *straw)
	{
		delete straw;
	}

	__declspec(dllexport) Pipe * __stdcall CreatePipe1()
	{
		return new Pipe();
	}

	__declspec(dllexport) void __stdcall DestroyPipe(Pipe *pipe)
	{
		delete pipe;
	}

	__declspec(dllexport) IndexClass<int, INISection *> * __stdcall CreateIntINISectionIndexClass()
	{
		return new IndexClass<int, INISection *>();
	}

	__declspec(dllexport) void __stdcall DestroyIntINISectionIndexClass(IndexClass<int, INISection *> *intINISectionIndexClass)
	{
		delete intINISectionIndexClass;
	}

	__declspec(dllexport) INIClass * __stdcall CreateINIClass1()
	{
		return new INIClass();
	}

	__declspec(dllexport) INIClass * __stdcall CreateINIClass2(FileClass *file)
	{
		return new INIClass(*file);
	}

	__declspec(dllexport) void __stdcall DestroyINIClass(INIClass *iniClass)
	{
		delete iniClass;
	}

	__declspec(dllexport) void __stdcall DestroyFileFactoryClass(FileFactoryClass *fileFactoryClass)
	{
		delete fileFactoryClass;
	}

	__declspec(dllexport) Buffer * __stdcall CreateBuffer(long size)
	{
		return new Buffer(size);
	}

	__declspec(dllexport) void __stdcall DestroyBuffer(Buffer *buffer)
	{
		delete buffer;
	}

	__declspec(dllexport) BufferStraw * __stdcall CreateBufferStraw(int size)
	{
		return new BufferStraw(nullptr, size);
	}

	__declspec(dllexport) FileStraw * __stdcall CreateFileStraw(FileClass *file)
	{
		return new FileStraw(*file);
	}

	__declspec(dllexport) CacheStraw * __stdcall CreateCacheStraw(int size)
	{
		return new CacheStraw(size);
	}

	__declspec(dllexport) BufferPipe * __stdcall CreateBufferPipe(int size)
	{
		return new BufferPipe(nullptr, size);
	}

	__declspec(dllexport) FilePipe * __stdcall CreateFilePipe(FileClass *file)
	{
		return new FilePipe(file);
	}

	__declspec(dllexport) void __stdcall Vector3Normalize(Vector3 *vector)
	{
		vector->Normalize();
	}

	__declspec(dllexport) DASettingsClass * __stdcall CreateDASettingsClass1()
	{
		return new DASettingsClass();
	}

	__declspec(dllexport) DASettingsClass * __stdcall CreateDASettingsClass2(const char *filename)
	{
		return new DASettingsClass(filename);
	}

	__declspec(dllexport) DASettingsClass * __stdcall CreateDASettingsClass3(INIClass *ini)
	{
		return new DASettingsClass(ini);
	}

	__declspec(dllexport) void __stdcall DestroyDASettingsClass(DASettingsClass *daSettingsClass)
	{
		delete daSettingsClass;
	}

	__declspec(dllexport) void __stdcall DestroyNetworkObjectClass(NetworkObjectClass *networkObjectClass)
	{
		delete networkObjectClass;
	}

	__declspec(dllexport) PostLoadableClass * __stdcall CreatePostLoadableClass()
	{
		return new PostLoadableClass();
	}

	__declspec(dllexport) void __stdcall DestroyPostLoadableClass(PostLoadableClass *postLoadableClass)
	{
		delete postLoadableClass;
	}

	__declspec(dllexport) ChunkLoadClass * __stdcall CreateChunkLoadClass(::FileClass *file)
	{
		return new ChunkLoadClass(file);
	}

	__declspec(dllexport) void __stdcall DestroyChunkLoadClass(ChunkLoadClass *chunkLoadClass)
	{
		delete chunkLoadClass;
	}

	__declspec(dllexport) ChunkSaveClass * __stdcall CreateChunkSaveClass(::FileClass *file)
	{
		return new ChunkSaveClass(file);
	}

	__declspec(dllexport) void __stdcall DestroyChunkSaveClass(ChunkSaveClass *chunkSaveClass)
	{
		delete chunkSaveClass;
	}

	__declspec(dllexport) ReferencerClass * __stdcall CreateReferencerClass1()
	{
		return new ReferencerClass();
	}

	__declspec(dllexport) ReferencerClass * __stdcall CreateReferencerClass2(ScriptableGameObj *object)
	{
		return new ReferencerClass(object);
	}

	__declspec(dllexport) void __stdcall DestroyReferencerClass(ReferencerClass *referencerClass)
	{
		delete referencerClass;
	}

	__declspec(dllexport) void __stdcall DestroyPersistFactoryClass(PersistFactoryClass *persistFactoryClass)
	{
		delete persistFactoryClass;
	}

	__declspec(dllexport) void __stdcall DestroyAudioCallbackClass(AudioCallbackClass *audioCallbackClass)
	{
		delete audioCallbackClass;
	}

	__declspec(dllexport) ReferenceableGameObj * __stdcall CreateReferenceableGameObj(::ScriptableGameObj *referenceData)
	{
		return new ReferenceableGameObj(referenceData);
	}

	__declspec(dllexport) void __stdcall DestroyReferenceableGameObj(ReferenceableGameObj *referenceableGameObj)
	{
		delete referenceableGameObj;
	}

	__declspec(dllexport) SimpleDynVecClass<int> * __stdcall CreateIntSimpleDynVecClass1()
	{
		return new SimpleDynVecClass<int>();
	}

	__declspec(dllexport) SimpleDynVecClass<int> * __stdcall CreateIntSimpleDynVecClass2(int size)
	{
		return new SimpleDynVecClass<int>(size);
	}

	__declspec(dllexport) void __stdcall DestroyIntSimpleDynVecClass(SimpleDynVecClass<int> *intSimpleDynVecClass)
	{
		delete intSimpleDynVecClass;
	}

	__declspec(dllexport) PhysObserverClass * __stdcall CreatePhysObserverClass()
	{
		return new PhysObserverClass();
	}

	__declspec(dllexport) void __stdcall DestroyPhysObserverClass(PhysObserverClass *physObserverClass)
	{
		delete physObserverClass;
	}

	__declspec(dllexport) CombatPhysObserverClass * __stdcall CreateCombatPhysObserverClass()
	{
		return new CombatPhysObserverClass();
	}

	__declspec(dllexport) void __stdcall DestroyCombatPhysObserverClass(CombatPhysObserverClass *combatPhysObserverClass)
	{
		delete combatPhysObserverClass;
	}

	__declspec(dllexport) SimpleDynVecClass<StringClass> * __stdcall CreateStringClassSimpleDynVecClass1()
	{
		return new SimpleDynVecClass<StringClass>();
	}

	__declspec(dllexport) SimpleDynVecClass<StringClass> * __stdcall CreateStringClassSimpleDynVecClass2(int size)
	{
		return new SimpleDynVecClass<StringClass>(size);
	}

	__declspec(dllexport) void __stdcall DestroyStringClassSimpleDynVecClass(SimpleDynVecClass<StringClass> *stringClassSimpleDynVecClass)
	{
		delete stringClassSimpleDynVecClass;
	}

	__declspec(dllexport) DynamicVectorClass<StringClass> * __stdcall CreateStringClassDynamicVectorClass1()
	{
		return new DynamicVectorClass<StringClass>();
	}

	__declspec(dllexport) DynamicVectorClass<StringClass> * __stdcall CreateStringClassDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<StringClass>(size);
	}

	__declspec(dllexport) void __stdcall DestroyStringClassDynamicVectorClass(DynamicVectorClass<StringClass> *stringClassDynamicVectorClass)
	{
		delete stringClassDynamicVectorClass;
	}

	__declspec(dllexport) DynamicVectorClass<DialogueOptionClass *> * __stdcall CreateDialogueOptionClassPtrDynamicVectorClass1()
	{
		return new DynamicVectorClass<DialogueOptionClass *>();
	}

	__declspec(dllexport) DynamicVectorClass<DialogueOptionClass *> * __stdcall CreateDialogueOptionClassPtrDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<DialogueOptionClass *>(size);
	}

	__declspec(dllexport) void __stdcall DestroyDialogueOptionClassPtrDynamicVectorClass(DynamicVectorClass<DialogueOptionClass *> *dialogueOptionClassPtrDynamicVectorClass)
	{
		delete dialogueOptionClassPtrDynamicVectorClass;
	}

	__declspec(dllexport) DAPlayerObserverTimerStruct * __stdcall CreateDAPlayerObserverTimerStruct()
	{
		return new DAPlayerObserverTimerStruct();
	}

	__declspec(dllexport) void __stdcall DestroyDAPlayerObserverTimerStruct(DAPlayerObserverTimerStruct *daPlayerObserverTimerStruct)
	{
		delete daPlayerObserverTimerStruct;
	}

	__declspec(dllexport) DATokenParserClass * __stdcall CreateDATokenParserClass(const char *str, char delim)
	{
		return new DATokenParserClass(str, delim);
	}

	__declspec(dllexport) void __stdcall DestroyDATokenParserClass(DATokenParserClass *daTokenParserClass)
	{
		delete daTokenParserClass;
	}

	__declspec(dllexport) DATokenClass * __stdcall CreateDATokenClass1()
	{
		return new DATokenClass();
	}

	__declspec(dllexport) DATokenClass * __stdcall CreateDATokenClass2(const char *str, int startPos, char delim)
	{
		return new DATokenClass(str, startPos, delim);
	}

	__declspec(dllexport) DATokenClass * __stdcall CreateDATokenClass3(const char *str, int startPos)
	{
		return new DATokenClass(str, startPos);
	}

	__declspec(dllexport) DATokenClass * __stdcall CreateDATokenClass4(const char *str)
	{
		return new DATokenClass(str);
	}

	__declspec(dllexport) DATokenClass* __stdcall CreateDATokenClass5(DATokenParserClass* parser)
	{
		return new DATokenClass(*parser);
	}

	__declspec(dllexport) void __stdcall DestroyDATokenClass(DATokenClass *daTokenClass)
	{
		delete daTokenClass;
	}

	__declspec(dllexport) void __stdcall DestroyDAPlayerDataClass(DAPlayerDataClass *daPlayerDataClass)
	{
		delete daPlayerDataClass;
	}

	__declspec(dllexport) void __stdcall DestroyDAPlayerDataFactoryClass(DAPlayerDataFactoryClass *daPlayerDataFactoryClass)
	{
		delete daPlayerDataFactoryClass;
	}

	__declspec(dllexport) ConnectionRequest * __stdcall CreateConnectionRequest()
	{
		return new ConnectionRequest();
	}

	__declspec(dllexport) void __stdcall DestroyConnectionRequest(ConnectionRequest *connectionRequest)
	{
		delete connectionRequest;
	}

	__declspec(dllexport) void __stdcall Vector4Normalize(Vector4 *vector)
	{
		vector->Normalize();
	}

	__declspec(dllexport) Vector3 *__stdcall CreateVector3Array(std::size_t size)
	{
		return new Vector3[size];
	}

	__declspec(dllexport) void __stdcall DestroyVector3Array(Vector3 *vArray)
	{
		delete[] vArray;
	}

	__declspec(dllexport) DynamicVectorClass<BuildingGameObj *> * __stdcall CreateBuildingGameObjPtrDynamicVectorClass1()
	{
		return new DynamicVectorClass<BuildingGameObj *>();
	}

	__declspec(dllexport) DynamicVectorClass<BuildingGameObj *> * __stdcall CreateBuildingGameObjPtrDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<BuildingGameObj *>(size);
	}

	__declspec(dllexport) void __stdcall DestroyBuildingGameObjPtrDynamicVectorClass(DynamicVectorClass<BuildingGameObj *> *buildingGameObjPtrDynamicVector)
	{
		delete buildingGameObjPtrDynamicVector;
	}

	__declspec(dllexport) void __stdcall CreatePlaneClass(PlaneClass *plane, Vector3 *point1, Vector3 *point2, Vector3 *point3)
	{
		PlaneClass tmpPlane(*point1, *point2, *point3);
		std::memcpy(plane, &tmpPlane, sizeof(PlaneClass));
	}

	__declspec(dllexport) void __stdcall PlaneClassSet(PlaneClass *plane, Vector3 *point1, Vector3 *point2, Vector3 *point3)
	{
		plane->Set(*point1, *point2, *point3);
	}

	__declspec(dllexport) RefCountClass * __stdcall CreateRefCountClass()
	{
		return new RefCountClass();
	}

	__declspec(dllexport) void __stdcall RefCountClassReleaseRef(RefCountClass* thisPtr)
	{
		thisPtr->Release_Ref();
	}

	__declspec(dllexport) void __stdcall RefCountClassRelease(RefCountClass* thisPtr)
	{
		thisPtr->Release();
	}

	__declspec(dllexport) MultiListObjectClass * __stdcall CreateMultiListObjectClass()
	{
		return new MultiListObjectClass();
	}

	__declspec(dllexport) void __stdcall DestroyMultiListObjectClass(MultiListObjectClass *multiListObjectClass)
	{
		delete multiListObjectClass;
	}

	__declspec(dllexport) DynamicVectorClass<SoundSceneObjClass *> * __stdcall CreateSoundSceneObjClassPtrDynamicVectorClass1()
	{
		return new DynamicVectorClass<SoundSceneObjClass *>();
	}

	__declspec(dllexport) DynamicVectorClass<SoundSceneObjClass *> * __stdcall CreateSoundSceneObjClassPtrDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<SoundSceneObjClass *>(size);
	}

	__declspec(dllexport) void __stdcall DestroySoundSceneObjClassPtrDynamicVectorClass(DynamicVectorClass<SoundSceneObjClass *> *soundSceneObjClassPtrDynamicVectorClass)
	{
		delete soundSceneObjClassPtrDynamicVectorClass;
	}

	__declspec(dllexport) CombatSound * __stdcall CreateCombatSound()
	{
		return new CombatSound();
	}

	__declspec(dllexport) void __stdcall DestroyCombatSound(CombatSound *combatSound)
	{
		delete combatSound;
	}

	__declspec(dllexport) void __stdcall DestroyGameObjObserverClass(GameObjObserverClass *gameObjObserverClass)
	{
		delete gameObjObserverClass;
	}

	__declspec(dllexport) SimpleDynVecClass<GameObjObserverClass *> * __stdcall CreateGameObjObserverClassPtrSimpleDynVecClass1()
	{
		return new SimpleDynVecClass<GameObjObserverClass *>();
	}

	__declspec(dllexport) SimpleDynVecClass<GameObjObserverClass *> * __stdcall CreateGameObjObserverClassPtrSimpleDynVecClass2(int size)
	{
		return new SimpleDynVecClass<GameObjObserverClass *>(size);
	}

	__declspec(dllexport) void __stdcall DestroyGameObjObserverClassPtrSimpleDynVecClass(SimpleDynVecClass<GameObjObserverClass *> *gameObjObserverClassPtrSimpleDynVecClass)
	{
		delete gameObjObserverClassPtrSimpleDynVecClass;
	}

	__declspec(dllexport) DynamicVectorClass<GameObjObserverTimerClass *> * __stdcall CreateGameObjObserverTimerClassPtrDynamicVectorClass1()
	{
		return new DynamicVectorClass<GameObjObserverTimerClass *>();
	}

	__declspec(dllexport) DynamicVectorClass<GameObjObserverTimerClass *> * __stdcall CreateGameObjObserverTimerClassPtrDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<GameObjObserverTimerClass *>(size);
	}

	__declspec(dllexport) void __stdcall DestroyGameObjObserverTimerClassPtrDynamicVectorClass(DynamicVectorClass<GameObjObserverTimerClass *> *gameObjObserverTimerClassPtrDynamicVectorClass)
	{
		delete gameObjObserverTimerClassPtrDynamicVectorClass;
	}

	__declspec(dllexport) DynamicVectorClass<GameObjCustomTimerClass *> * __stdcall CreateGameObjCustomTimerClassPtrDynamicVectorClass1()
	{
		return new DynamicVectorClass<GameObjCustomTimerClass *>();
	}

	__declspec(dllexport) DynamicVectorClass<GameObjCustomTimerClass *> * __stdcall CreateGameObjCustomTimerClassPtrDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<GameObjCustomTimerClass *>(size);
	}

	__declspec(dllexport) void __stdcall DestroyGameObjCustomTimerClassPtrDynamicVectorClass(DynamicVectorClass<GameObjCustomTimerClass *> *GameObjCustomTimerClassPtrDynamicVectorClass)
	{
		delete GameObjCustomTimerClassPtrDynamicVectorClass;
	}

	__declspec(dllexport) RenSharpGameObjObserverClass * __stdcall CreateRenSharpGameObjObserverClass(const char *name)
	{
		return new RenSharpGameObjObserverClass(name);
	}

	__declspec(dllexport) OffenseObjectClass * __stdcall CreateOffenseObjectClass1(float damage, unsigned int warhead, ArmedGameObj *owner)
	{
		return new OffenseObjectClass(damage, warhead, owner);
	}

	__declspec(dllexport) OffenseObjectClass * __stdcall CreateOffenseObjectClass2(float damage, unsigned int warhead)
	{
		return new OffenseObjectClass(damage, warhead);
	}

	__declspec(dllexport) OffenseObjectClass * __stdcall CreateOffenseObjectClass3(float damage)
	{
		return new OffenseObjectClass(damage);
	}

	__declspec(dllexport) OffenseObjectClass * __stdcall CreateOffenseObjectClass4()
	{
		return new OffenseObjectClass();
	}

	__declspec(dllexport) void __stdcall DestroyOffenseObjectClass(OffenseObjectClass *offenseObjectClass)
	{
		delete offenseObjectClass;
	}

	__declspec(dllexport) void __stdcall CreateLineSegClass(LineSegClass *line, const Vector3 *p0, const Vector3 *p1)
	{
		LineSegClass tmp(*p0, *p1);
		std::memcpy(line, &tmp, sizeof(LineSegClass));
	}

	__declspec(dllexport) void __stdcall LineSegClassSet(LineSegClass *line, const Vector3 *p0, const Vector3 *p1)
	{
		line->Set(*p0, *p1);
	}

	class LineSegClassHelper : public LineSegClass
	{
		private:
			LineSegClassHelper()
			{

			}

		public:
			void Recalculate()
			{
				recalculate();
			}
	};

	__declspec(dllexport) void __stdcall LineSegClassRecalculate(LineSegClass *line)
	{
		LineSegClassHelper *helper = reinterpret_cast<LineSegClassHelper *>(line);
		helper->Recalculate();
	}

	__declspec(dllexport) void __stdcall Vector2Normalize(Vector2 *vec)
	{
		vec->Normalize();
	}

	__declspec(dllexport) void __stdcall FrustumClassInit(
		FrustumClass *frustum, 
		const Matrix3D *camera,
		const Vector2 *vpMin,
		const Vector2 *vpMax,
		float zNear,
		float zFar)
	{
		frustum->Init(*camera, *vpMin, *vpMax, zNear, zFar);
	}

	__declspec(dllexport) void __stdcall DestroyCullSystemClass(CullSystemClass *cullSystemClass)
	{
		delete cullSystemClass;
	}

	__declspec(dllexport) CullLinkClass * __stdcall CreateCullLinkClass(CullSystemClass *system)
	{
		return new CullLinkClass(system);
	}

	__declspec(dllexport) void __stdcall DestroyCullLinkClass(CullLinkClass *cullLinkClass)
	{
		delete cullLinkClass;
	}

	__declspec(dllexport) void __stdcall DestroyAnimControlClass(AnimControlClass *animControlClass)
	{
		delete animControlClass;
	}

	__declspec(dllexport) void __stdcall DestroyMuzzleRecoilClass(MuzzleRecoilClass *muzzleRecoilClass)
	{
		delete muzzleRecoilClass;
	}

	__declspec(dllexport) void __stdcall DestroyControlClass(ControlClass *controlClass)
	{
		delete controlClass;
	}

	__declspec(dllexport) ScriptCommands * __stdcall CreateScriptCommands()
	{
		return new ScriptCommands();
	}

	__declspec(dllexport) void __stdcall DestroyScriptCommands(ScriptCommands *scriptCommands)
	{
		delete scriptCommands;
	}

	__declspec(dllexport) ScriptVariableClass * __stdcall CreateScriptVariableClass(void *dataPtr, int dataSize, int id, ScriptVariableClass *next)
	{
		return new ScriptVariableClass(dataPtr, dataSize, id, next);
	}

	__declspec(dllexport) void __stdcall DestroyScriptVariableClass(ScriptVariableClass *scriptVariableClass)
	{
		delete scriptVariableClass;
	}

	__declspec(dllexport) ScriptImpClass * __stdcall CreateScriptImpClass()
	{
		return new ScriptImpClass();
	}

	__declspec(dllexport) void __stdcall DestroyScriptFactory(ScriptFactory *scriptFactory)
	{
		delete scriptFactory;
	}

	__declspec(dllexport) SafeActionParamsStruct * __stdcall CreateSafeActionParamsStruct()
	{
		return new SafeActionParamsStruct();
	}

	__declspec(dllexport) void __stdcall DestroySafeActionParamsStruct(SafeActionParamsStruct *safeActionParamsStruct)
	{
		delete safeActionParamsStruct;
	}

	__declspec(dllexport) ActionParamsStruct * __stdcall CreateActionParamsStruct()
	{
		return new ActionParamsStruct();
	}

	__declspec(dllexport) void __stdcall DestroyActionParamsStruct(ActionParamsStruct *actionParamsStruct)
	{
		delete actionParamsStruct;
	}

	__declspec(dllexport) void __stdcall DestroyActionClass(ActionClass *actionClass)
	{
		delete actionClass;
	}

	__declspec(dllexport) PhysControllerClass * __stdcall CreatePhysControllerClass()
	{
		return new PhysControllerClass();
	}

	__declspec(dllexport) void __stdcall DestroyPhysControllerClass(PhysControllerClass *physControllerClass)
	{
		delete physControllerClass;
	}

	__declspec(dllexport) TransitionDataClass * __stdcall CreateTransitionDataClass()
	{
		return new TransitionDataClass();
	}

	__declspec(dllexport) void __stdcall DestroyTransitionDataClass(TransitionDataClass *transitionDataClass)
	{
		delete transitionDataClass;
	}

	__declspec(dllexport) DynamicVectorClass<TransitionDataClass *> * __stdcall CreateTransitionDataClassPtrDynamicVectorClass1()
	{
		return new DynamicVectorClass<TransitionDataClass *>();
	}

	__declspec(dllexport) DynamicVectorClass<TransitionDataClass *> * __stdcall CreateTransitionDataClassPtrDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<TransitionDataClass *>(size);
	}

	__declspec(dllexport) void __stdcall DestroyTransitionDataClassPtrDynamicVectorClass(DynamicVectorClass<TransitionDataClass *> *TransitionDataClassPtrDynamicVectorClass)
	{
		delete TransitionDataClassPtrDynamicVectorClass;
	}

	__declspec(dllexport) DAPlayerObserverChatCommandStruct * __stdcall CreateDAPlayerObserverChatCommandStruct()
	{
		return new DAPlayerObserverChatCommandStruct();
	}

	__declspec(dllexport) void __stdcall DestroyDAPlayerObserverChatCommandStruct(DAPlayerObserverChatCommandStruct *daPlayerObserverChatCommandStruct)
	{
		delete daPlayerObserverChatCommandStruct;
	}

	__declspec(dllexport) DAPlayerObserverKeyHookStruct * __stdcall CreateDAPlayerObserverKeyHookStruct()
	{
		return new DAPlayerObserverKeyHookStruct();
	}

	__declspec(dllexport) void __stdcall DestroyDAPlayerObserverKeyHookStruct(DAPlayerObserverKeyHookStruct *daPlayerObserverKeyHookStruct)
	{
		delete daPlayerObserverKeyHookStruct;
	}

	__declspec(dllexport) DynamicVectorClass<DAPlayerObserverTimerStruct *> * __stdcall CreateDAPlayerObserverTimerStructPtrDynamicVectorClass1()
	{
		return new DynamicVectorClass<DAPlayerObserverTimerStruct *>();
	}

	__declspec(dllexport) DynamicVectorClass<DAPlayerObserverTimerStruct *> * __stdcall CreateDAPlayerObserverTimerStructPtrDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<DAPlayerObserverTimerStruct *>(size);
	}

	__declspec(dllexport) void __stdcall DestroyDAPlayerObserverTimerStructPtrDynamicVectorClass(DynamicVectorClass<DAPlayerObserverTimerStruct *> *DAPlayerObserverTimerStructPtrDynamicVectorClass)
	{
		delete DAPlayerObserverTimerStructPtrDynamicVectorClass;
	}

	__declspec(dllexport) DynamicVectorClass<DAPlayerObserverChatCommandStruct *> * __stdcall CreateDAPlayerObserverChatCommandStructPtrDynamicVectorClass1()
	{
		return new DynamicVectorClass<DAPlayerObserverChatCommandStruct *>();
	}

	__declspec(dllexport) DynamicVectorClass<DAPlayerObserverChatCommandStruct *> * __stdcall CreateDAPlayerObserverChatCommandStructPtrDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<DAPlayerObserverChatCommandStruct *>(size);
	}

	__declspec(dllexport) void __stdcall DestroyDAPlayerObserverChatCommandStructPtrDynamicVectorClass(DynamicVectorClass<DAPlayerObserverChatCommandStruct *> *DAPlayerObserverChatCommandStructPtrDynamicVectorClass)
	{
		delete DAPlayerObserverChatCommandStructPtrDynamicVectorClass;
	}

	__declspec(dllexport) DynamicVectorClass<DAPlayerObserverKeyHookStruct *> * __stdcall CreateDAPlayerObserverKeyHookStructPtrDynamicVectorClass1()
	{
		return new DynamicVectorClass<DAPlayerObserverKeyHookStruct *>();
	}

	__declspec(dllexport) DynamicVectorClass<DAPlayerObserverKeyHookStruct *> * __stdcall CreateDAPlayerObserverKeyHookStructPtrDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<DAPlayerObserverKeyHookStruct *>(size);
	}

	__declspec(dllexport) void __stdcall DestroyDAPlayerObserverKeyHookStructPtrDynamicVectorClass(DynamicVectorClass<DAPlayerObserverKeyHookStruct *> *DAPlayerObserverKeyHookStructPtrDynamicVectorClass)
	{
		delete DAPlayerObserverKeyHookStructPtrDynamicVectorClass;
	}

	__declspec(dllexport) void __stdcall DestroyDAPlayerObserverClass(DAPlayerObserverClass *daPlayerObserverClass)
	{
		delete daPlayerObserverClass;
	}

	__declspec(dllexport) DynamicVectorClass<DAPlayerObserverClass *> * __stdcall CreateDAPlayerObserverClassPtrDynamicVectorClass1()
	{
		return new DynamicVectorClass<DAPlayerObserverClass *>();
	}

	__declspec(dllexport) DynamicVectorClass<DAPlayerObserverClass *> * __stdcall CreateDAPlayerObserverClassPtrDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<DAPlayerObserverClass *>(size);
	}

	__declspec(dllexport) void __stdcall DestroyDAPlayerObserverClassPtrDynamicVectorClass(DynamicVectorClass<DAPlayerObserverClass *> *DAPlayerObserverClassPtrDynamicVectorClass)
	{
		delete DAPlayerObserverClassPtrDynamicVectorClass;
	}

	__declspec(dllexport) RenSharpPlayerObserverClass * __stdcall CreateRenSharpPlayerObserverClass(const char *name)
	{
		return new RenSharpPlayerObserverClass(name);
	}

	__declspec(dllexport) TransitionCompletionDataStruct * __stdcall CreateTransitionCompletionDataStruct()
	{
		return new TransitionCompletionDataStruct();
	}

	__declspec(dllexport) void __stdcall DestroyTransitionCompletionDataStruct(TransitionCompletionDataStruct *transitionCompletionDataStruct)
	{
		delete transitionCompletionDataStruct;
	}

	__declspec(dllexport) DynamicVectorClass<RenderObjClass *> * __stdcall CreateRenderObjClassPtrDynamicVectorClass1()
	{
		return new DynamicVectorClass<RenderObjClass *>();
	}

	__declspec(dllexport) DynamicVectorClass<RenderObjClass *> * __stdcall CreateRenderObjClassPtrDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<RenderObjClass *>(size);
	}

	__declspec(dllexport) void __stdcall DestroyRenderObjClassPtrDynamicVectorClass(DynamicVectorClass<RenderObjClass *> *RenderObjClassPtrDynamicVectorClass)
	{
		delete RenderObjClassPtrDynamicVectorClass;
	}

	__declspec(dllexport) VectorClass<PersistantSurfaceEmitterClass *> * __stdcall CreatePersistantSurfaceEmitterClassPtrVectorClass1()
	{
		return new VectorClass<PersistantSurfaceEmitterClass *>();
	}

	__declspec(dllexport) VectorClass<PersistantSurfaceEmitterClass *> * __stdcall CreatePersistantSurfaceEmitterClassPtrVectorClass2(int size)
	{
		return new VectorClass<PersistantSurfaceEmitterClass *>(size);
	}

	__declspec(dllexport) void __stdcall DestroyPersistantSurfaceEmitterClassPtrVectorClass(VectorClass<PersistantSurfaceEmitterClass *> *persistantSurfaceEmitterClassPtrVectorClass)
	{
		delete persistantSurfaceEmitterClassPtrVectorClass;
	}

	__declspec(dllexport) VectorClass<SoldierGameObj *> * __stdcall CreateSoldierGameObjPtrVectorClass1()
	{
		return new VectorClass<SoldierGameObj *>();
	}

	__declspec(dllexport) VectorClass<SoldierGameObj *> * __stdcall CreateSoldierGameObjPtrVectorClass2(int size)
	{
		return new VectorClass<SoldierGameObj *>(size);
	}

	__declspec(dllexport) void __stdcall DestroySoldierGameObjPtrVectorClass(VectorClass<SoldierGameObj *> *SoldierGameObjPtrVectorClass)
	{
		delete SoldierGameObjPtrVectorClass;
	}

	__declspec(dllexport) DynamicVectorClass<TransitionInstanceClass *> * __stdcall CreateTransitionInstanceClassPtrDynamicVectorClass1()
	{
		return new DynamicVectorClass<TransitionInstanceClass *>();
	}

	__declspec(dllexport) DynamicVectorClass<TransitionInstanceClass *> * __stdcall CreateTransitionInstanceClassPtrDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<TransitionInstanceClass *>(size);
	}

	__declspec(dllexport) void __stdcall DestroyTransitionInstanceClassPtrDynamicVectorClass(DynamicVectorClass<TransitionInstanceClass *> *TransitionInstanceClassPtrDynamicVectorClass)
	{
		delete TransitionInstanceClassPtrDynamicVectorClass;
	}

	__declspec(dllexport) RenSharpCollisionTestClass * __stdcall CreateRenSharpCollisionTestClass(Collision_Type collisionType)
	{
		return new RenSharpCollisionTestClass(collisionType);
	}

	__declspec(dllexport) void __stdcall DestroyRenSharpCollisionTestClass(RenSharpCollisionTestClass *renSharpCollisionTestClass)
	{
		delete renSharpCollisionTestClass;
	}

	__declspec(dllexport) CollisionTestClass * __stdcall CreateCollisionTestClass(Collision_Type collisionType)
	{
		return new CollisionTestClass(nullptr, collisionType);
	}

	__declspec(dllexport) void __stdcall DestroyCollisionTestClass(CollisionTestClass *collisionTestClass)
	{
		delete collisionTestClass;
	}

	__declspec(dllexport) void __stdcall RenSharpCollisionTestClassSetResult(RenSharpCollisionTestClass *thisPtr, const CastResultStruct *res)
	{
		thisPtr->setResult(*res);
	}

	__declspec(dllexport) RenSharpRayCollisionTestClass * __stdcall CreateRenSharpRayCollisionTestClass1(const LineSegClass *ray, Collision_Type collisionType, bool ignoreTranslucentMeshes)
	{
		return new RenSharpRayCollisionTestClass(*ray, collisionType, ignoreTranslucentMeshes);
	}

	__declspec(dllexport) RenSharpRayCollisionTestClass * __stdcall CreateRenSharpRayCollisionTestClass2(const LineSegClass *ray, Collision_Type collisionType)
	{
		return new RenSharpRayCollisionTestClass(*ray, collisionType);
	}

	__declspec(dllexport) RenSharpRayCollisionTestClass * __stdcall CreateRenSharpRayCollisionTestClass3(const LineSegClass *ray)
	{
		return new RenSharpRayCollisionTestClass(*ray);
	}

	__declspec(dllexport) RenSharpRayCollisionTestClass * __stdcall CreateRenSharpRayCollisionTestClass4(const RayCollisionTestClass *rayTest, const Matrix3D *tm)
	{
		return new RenSharpRayCollisionTestClass(*rayTest, *tm);
	}

	__declspec(dllexport) void __stdcall DestroyRenSharpRayCollisionTestClass(RenSharpRayCollisionTestClass *renSharpRayCollisionTestClass)
	{
		delete renSharpRayCollisionTestClass;
	}

	__declspec(dllexport) void __stdcall RenSharpRayCollisionTestClassSetResult(RenSharpRayCollisionTestClass *thisPtr, const CastResultStruct *res)
	{
		thisPtr->setResult(*res);
	}

	__declspec(dllexport) RayCollisionTestClass * __stdcall CreateRayCollisionTestClass1(const LineSegClass *ray, Collision_Type collisionType, bool ignoreTranslucentMeshes)
	{
		return new RayCollisionTestClass(*ray, nullptr, collisionType, ignoreTranslucentMeshes);
	}

	__declspec(dllexport) RayCollisionTestClass * __stdcall CreateRayCollisionTestClass2(const LineSegClass *ray, Collision_Type collisionType)
	{
		return new RayCollisionTestClass(*ray, nullptr, collisionType);
	}

	__declspec(dllexport) RayCollisionTestClass * __stdcall CreateRayCollisionTestClass3(const LineSegClass *ray)
	{
		return new RayCollisionTestClass(*ray, nullptr);
	}

	__declspec(dllexport) RayCollisionTestClass * __stdcall CreateRayCollisionTestClass4(const RayCollisionTestClass *rayTest, const Matrix3D *tm)
	{
		return new RayCollisionTestClass(*rayTest, *tm);
	}

	__declspec(dllexport) void __stdcall DestroyRayCollisionTestClass(RayCollisionTestClass *rayCollisionTestClass)
	{
		delete rayCollisionTestClass;
	}

	__declspec(dllexport) RenSharpAABoxCollisionTestClass * __stdcall CreateRenSharpAABoxCollisionTestClass1(const AABoxClass *aabox, const Vector3 *move, Collision_Type collisionType)
	{
		return new RenSharpAABoxCollisionTestClass(*aabox, *move, collisionType);
	}

	__declspec(dllexport) RenSharpAABoxCollisionTestClass * __stdcall CreateRenSharpAABoxCollisionTestClass2(const AABoxClass *aabox, const Vector3 *move)
	{
		return new RenSharpAABoxCollisionTestClass(*aabox, *move);
	}

	__declspec(dllexport) void __stdcall DestroyRenSharpAABoxCollisionTestClass(RenSharpAABoxCollisionTestClass *renSharpAABoxCollisionTestClass)
	{
		delete renSharpAABoxCollisionTestClass;
	}

	__declspec(dllexport) void __stdcall RenSharpAABoxCollisionTestClassSetResult(RenSharpAABoxCollisionTestClass *thisPtr, const CastResultStruct *res)
	{
		thisPtr->setResult(*res);
	}

	__declspec(dllexport) AABoxCollisionTestClass * __stdcall CreateAABoxCollisionTestClass1(const AABoxClass *aabox, const Vector3 *move, Collision_Type collisionType)
	{
		return new AABoxCollisionTestClass(*aabox, *move, nullptr, collisionType);
	}

	__declspec(dllexport) AABoxCollisionTestClass * __stdcall CreateAABoxCollisionTestClass2(const AABoxClass *aabox, const Vector3 *move)
	{
		return new AABoxCollisionTestClass(*aabox, *move, nullptr);
	}

	__declspec(dllexport) void __stdcall DestroyAABoxCollisionTestClass(AABoxCollisionTestClass *aaBoxCollisionTestClass)
	{
		delete aaBoxCollisionTestClass;
	}

	__declspec(dllexport) RenSharpOBBoxCollisionTestClass * __stdcall CreateRenSharpOBBoxCollisionTestClass1(const OBBoxClass *obbox, const Vector3 *move, Collision_Type collisionType)
	{
		return new RenSharpOBBoxCollisionTestClass(*obbox, *move, collisionType);
	}

	__declspec(dllexport) RenSharpOBBoxCollisionTestClass * __stdcall CreateRenSharpOBBoxCollisionTestClass2(const OBBoxClass *obbox, const Vector3 *move)
	{
		return new RenSharpOBBoxCollisionTestClass(*obbox, *move);
	}

	__declspec(dllexport) RenSharpOBBoxCollisionTestClass * __stdcall CreateRenSharpOBBoxCollisionTestClass3(const OBBoxCollisionTestClass *that, const Matrix3D *tm)
	{
		return new RenSharpOBBoxCollisionTestClass(*that, *tm);
	}

	__declspec(dllexport) RenSharpOBBoxCollisionTestClass * __stdcall CreateRenSharpOBBoxCollisionTestClass4(const AABoxCollisionTestClass *that, const Matrix3D *tm)
	{
		return new RenSharpOBBoxCollisionTestClass(*that, *tm);
	}

	__declspec(dllexport) void __stdcall DestroyRenSharpOBBoxCollisionTestClass(RenSharpOBBoxCollisionTestClass *renSharpOBBoxCollisionTestClass)
	{
		delete renSharpOBBoxCollisionTestClass;
	}

	__declspec(dllexport) void __stdcall RenSharpOBBoxCollisionTestClassSetResult(RenSharpOBBoxCollisionTestClass *thisPtr, const CastResultStruct *res)
	{
		thisPtr->setResult(*res);
	}

	__declspec(dllexport) OBBoxCollisionTestClass * __stdcall CreateOBBoxCollisionTestClass1(const OBBoxClass *obbox, const Vector3 *move, Collision_Type collisionType)
	{
		return new OBBoxCollisionTestClass(*obbox, *move, nullptr, collisionType);
	}

	__declspec(dllexport) OBBoxCollisionTestClass * __stdcall CreateOBBoxCollisionTestClass2(const OBBoxClass *obbox, const Vector3 *move)
	{
		return new OBBoxCollisionTestClass(*obbox, *move, nullptr);
	}

	__declspec(dllexport) OBBoxCollisionTestClass * __stdcall CreateOBBoxCollisionTestClass3(const OBBoxCollisionTestClass *that, const Matrix3D *tm)
	{
		return new OBBoxCollisionTestClass(*that, *tm);
	}

	__declspec(dllexport) OBBoxCollisionTestClass * __stdcall CreateOBBoxCollisionTestClass4(const AABoxCollisionTestClass *that, const Matrix3D *tm)
	{
		return new OBBoxCollisionTestClass(*that, *tm);
	}

	__declspec(dllexport) void __stdcall DestroyOBBoxCollisionTestClass(OBBoxCollisionTestClass *oBBoxCollisionTestClass)
	{
		delete oBBoxCollisionTestClass;
	}

	__declspec(dllexport) MultiListNodeClass * __stdcall CreateMultiListNodeClass()
	{
		return new MultiListNodeClass();
	}

	__declspec(dllexport) void __stdcall DestroyMultiListNodeClass(MultiListNodeClass *multiListNodeClass)
	{
		delete multiListNodeClass;
	}

	__declspec(dllexport) GenericMultiListClass * __stdcall CreateGenericMultiListClass()
	{
		return new GenericMultiListClass();
	}

	__declspec(dllexport) void __stdcall DestroyGenericMultiListClass(GenericMultiListClass *genericMultiListClass)
	{
		delete genericMultiListClass;
	}

	__declspec(dllexport) GenericMultiListIterator * __stdcall CreateGenericMultiListIterator(const GenericMultiListClass *list)
	{
		return new GenericMultiListIterator(list);
	}

	__declspec(dllexport) void __stdcall DestroyGenericMultiListIterator(GenericMultiListIterator *genericMultiListIterator)
	{
		delete genericMultiListIterator;
	}

	__declspec(dllexport) RefMultiListClass<StaticPhysClass> * __stdcall CreateStaticPhysClassRefMultiListClass()
	{
		return new RefMultiListClass<StaticPhysClass>();
	}

	__declspec(dllexport) void __stdcall DestroyStaticPhysClassRefMultiListClass(RefMultiListClass<StaticPhysClass> *staticPhysClassRefMultiListClass)
	{
		delete staticPhysClassRefMultiListClass;
	}

	__declspec(dllexport) RefMultiListIterator<StaticPhysClass> * __stdcall CreateStaticPhysClassRefMultiListIterator(RefMultiListClass<StaticPhysClass> *list)
	{
		return new RefMultiListIterator<StaticPhysClass>(list);
	}

	__declspec(dllexport) void __stdcall DestroyStaticPhysClassRefMultiListIterator(RefMultiListIterator<StaticPhysClass> *staticPhysClassRefMultiListIterator)
	{
		delete staticPhysClassRefMultiListIterator;
	}

	__declspec(dllexport) RefMultiListClass<BuildingAggregateClass> * __stdcall CreateBuildingAggregateClassRefMultiListClass()
	{
		return new RefMultiListClass<BuildingAggregateClass>();
	}

	__declspec(dllexport) void __stdcall DestroyBuildingAggregateClassRefMultiListClass(RefMultiListClass<BuildingAggregateClass> *BuildingAggregateClassRefMultiListClass)
	{
		delete BuildingAggregateClassRefMultiListClass;
	}

	__declspec(dllexport) RefMultiListIterator<BuildingAggregateClass> * __stdcall CreateBuildingAggregateClassRefMultiListIterator(RefMultiListClass<BuildingAggregateClass> *list)
	{
		return new RefMultiListIterator<BuildingAggregateClass>(list);
	}

	__declspec(dllexport) void __stdcall DestroyBuildingAggregateClassRefMultiListIterator(RefMultiListIterator<BuildingAggregateClass> *BuildingAggregateClassRefMultiListIterator)
	{
		delete BuildingAggregateClassRefMultiListIterator;
	}

	__declspec(dllexport) RefMultiListClass<LightPhysClass> * __stdcall CreateLightPhysClassRefMultiListClass()
	{
		return new RefMultiListClass<LightPhysClass>();
	}

	__declspec(dllexport) void __stdcall DestroyLightPhysClassRefMultiListClass(RefMultiListClass<LightPhysClass> *LightPhysClassRefMultiListClass)
	{
		delete LightPhysClassRefMultiListClass;
	}

	__declspec(dllexport) RefMultiListIterator<LightPhysClass> * __stdcall CreateLightPhysClassRefMultiListIterator(RefMultiListClass<LightPhysClass> *list)
	{
		return new RefMultiListIterator<LightPhysClass>(list);
	}

	__declspec(dllexport) void __stdcall DestroyLightPhysClassRefMultiListIterator(RefMultiListIterator<LightPhysClass> *LightPhysClassRefMultiListIterator)
	{
		delete LightPhysClassRefMultiListIterator;
	}

	__declspec(dllexport) IntersectionTestClass * __stdcall CreateIntersectionTestClass(int collisionType)
	{
		return new IntersectionTestClass(collisionType);
	}

	__declspec(dllexport) void __stdcall DestroyIntersectionTestClass(IntersectionTestClass *intersectionTestClass)
	{
		delete intersectionTestClass;
	}

	__declspec(dllexport) AABoxIntersectionTestClass * __stdcall CreateAABoxIntersectionTestClass(const AABoxClass *box, int collisionType)
	{
		return new AABoxIntersectionTestClass(*box, collisionType);
	}

	__declspec(dllexport) void __stdcall DestroyAABoxIntersectionTestClass(AABoxIntersectionTestClass *aaBoxIntersectionTestClass)
	{
		delete aaBoxIntersectionTestClass;
	}

	__declspec(dllexport) OBBoxIntersectionTestClass * __stdcall CreateOBBoxIntersectionTestClass1(const OBBoxClass *box, int collisionType)
	{
		return new OBBoxIntersectionTestClass(*box, collisionType);
	}

	__declspec(dllexport) OBBoxIntersectionTestClass * __stdcall CreateOBBoxIntersectionTestClass2(const OBBoxIntersectionTestClass *that, const Matrix3D *tm)
	{
		return new OBBoxIntersectionTestClass(*that, *tm);
	}

	__declspec(dllexport) OBBoxIntersectionTestClass * __stdcall CreateOBBoxIntersectionTestClass3(const AABoxIntersectionTestClass *that, const Matrix3D *tm)
	{
		return new OBBoxIntersectionTestClass(*that, *tm);
	}

	__declspec(dllexport) void __stdcall DestroyOBBoxIntersectionTestClass(OBBoxIntersectionTestClass *oBBoxIntersectionTestClass)
	{
		delete oBBoxIntersectionTestClass;
	}

	__declspec(dllexport) MultiListClass<PhysClass> * __stdcall CreatePhysClassMultiListClass()
	{
		return new MultiListClass<PhysClass>();
	}

	__declspec(dllexport) void __stdcall DestroyPhysClassMultiListClass(MultiListClass<StaticPhysClass> *physClassMultiListClass)
	{
		delete physClassMultiListClass;
	}

	__declspec(dllexport) MultiListIterator<PhysClass> * __stdcall CreatePhysClassMultiListIterator(MultiListClass<PhysClass> *list)
	{
		return new MultiListIterator<PhysClass>(list);
	}

	__declspec(dllexport) void __stdcall DestroyPhysClassMultiListIterator(MultiListIterator<PhysClass> *physClassMultiListIterator)
	{
		delete physClassMultiListIterator;
	}

	__declspec(dllexport) RenSharpPhysAABoxIntersectionTestClass * __stdcall CreateRenSharpPhysAABoxIntersectionTestClass(const AABoxClass *box, int colGroup, int colType, bool enableResultList)
	{
		return new RenSharpPhysAABoxIntersectionTestClass(*box, colGroup, colType, enableResultList);
	}

	__declspec(dllexport) MultiListClass<PhysClass> * __stdcall GetRenSharpPhysAABoxIntersectionResultList(RenSharpPhysAABoxIntersectionTestClass *thisPtr)
	{
		return thisPtr->getResultList();
	}

	__declspec(dllexport) void __stdcall DestroyRenSharpPhysAABoxIntersectionTestClass(RenSharpPhysAABoxIntersectionTestClass *renSharpPhysAABoxIntersectionTestClass)
	{
		delete renSharpPhysAABoxIntersectionTestClass;
	}

	__declspec(dllexport) RenSharpPhysOBBoxIntersectionTestClass * __stdcall CreateRenSharpPhysOBBoxIntersectionTestClass(const OBBoxClass *box, int colGroup, int colType, bool enableResultList)
	{
		return new RenSharpPhysOBBoxIntersectionTestClass(*box, colGroup, colType, enableResultList);
	}

	__declspec(dllexport) MultiListClass<PhysClass> * __stdcall GetRenSharpPhysOBBoxIntersectionTestClassResultList(RenSharpPhysOBBoxIntersectionTestClass *thisPtr)
	{
		return thisPtr->getResultList();
	}

	__declspec(dllexport) void __stdcall DestroyRenSharpPhysOBBoxIntersectionTestClass(RenSharpPhysOBBoxIntersectionTestClass *renSharpPhysOBBoxIntersectionTestClass)
	{
		delete renSharpPhysOBBoxIntersectionTestClass;
	}

	__declspec(dllexport) RenSharpPhysMeshIntersectionTestClass * __stdcall CreateRenSharpPhysMeshIntersectionTestClass(MeshClass *mesh, int colGroup, int colType, bool enableResultList)
	{
		return new RenSharpPhysMeshIntersectionTestClass(mesh, colGroup, colType, enableResultList);
	}

	__declspec(dllexport) MultiListClass<PhysClass> * __stdcall GetRenSharpPhysMeshIntersectionTestClassResultList(RenSharpPhysMeshIntersectionTestClass *thisPtr)
	{
		return thisPtr->getResultList();
	}

	__declspec(dllexport) void __stdcall DestroyRenSharpPhysMeshIntersectionTestClass(RenSharpPhysMeshIntersectionTestClass *renSharpPhysMeshIntersectionTestClass)
	{
		delete renSharpPhysMeshIntersectionTestClass;
	}

	__declspec(dllexport) PhysAABoxIntersectionTestClass * __stdcall CreatePhysAABoxIntersectionTestClass(const AABoxClass *box, int colGroup, int colType)
	{
		return new PhysAABoxIntersectionTestClass(*box, colGroup, colType);
	}

	__declspec(dllexport) void __stdcall DestroyPhysAABoxIntersectionTestClass(PhysAABoxIntersectionTestClass *physAABoxIntersectionTestClass)
	{
		delete physAABoxIntersectionTestClass;
	}

	__declspec(dllexport) PhysOBBoxIntersectionTestClass * __stdcall CreatePhysOBBoxIntersectionTestClass(const OBBoxClass *box, int colGroup, int colType)
	{
		return new PhysOBBoxIntersectionTestClass(*box, colGroup, colType);
	}

	__declspec(dllexport) void __stdcall DestroyPhysOBBoxIntersectionTestClass(PhysOBBoxIntersectionTestClass *physOBBoxIntersectionTestClass)
	{
		delete physOBBoxIntersectionTestClass;
	}

	__declspec(dllexport) PhysMeshIntersectionTestClass * __stdcall CreatePhysMeshIntersectionTestClass(MeshClass *mesh, int colGroup, int colType)
	{
		return new PhysMeshIntersectionTestClass(mesh, colGroup, colType, nullptr);
	}

	__declspec(dllexport) void __stdcall DestroyPhysMeshIntersectionTestClass(PhysMeshIntersectionTestClass *physMeshIntersectionTestClass)
	{
		delete physMeshIntersectionTestClass;
	}

	__declspec(dllexport) ScriptCommandsClass * __stdcall CreateScriptCommandsClass()
	{
		return new ScriptCommandsClass();
	}

	__declspec(dllexport) void __stdcall DestroyScriptCommandsClass(ScriptCommandsClass *scriptCommandsClass)
	{
		delete scriptCommandsClass;
	}

	__declspec(dllexport) PhysRayCollisionTestClass * __stdcall CreatePhysRayCollisionTestClass1(const LineSegClass *ray, Collision_Group_Type group, Collision_Type type)
	{
		return new PhysRayCollisionTestClass(*ray, nullptr, group, type);
	}

	__declspec(dllexport) PhysRayCollisionTestClass * __stdcall CreatePhysRayCollisionTestClass2(const LineSegClass *ray, Collision_Group_Type group)
	{
		return new PhysRayCollisionTestClass(*ray, nullptr, group);
	}

	__declspec(dllexport) void __stdcall DestroyPhysRayCollisionTestClass(PhysRayCollisionTestClass *physRayCollisionTestClass)
	{
		delete physRayCollisionTestClass;
	}

	__declspec(dllexport) RenSharpPhysRayCollisionTestClass * __stdcall CreateRenSharpPhysRayCollisionTestClass1(const LineSegClass *ray, Collision_Group_Type group, Collision_Type type)
	{
		return new RenSharpPhysRayCollisionTestClass(*ray, group, type);
	}

	__declspec(dllexport) RenSharpPhysRayCollisionTestClass * __stdcall CreateRenSharpPhysRayCollisionTestClass2(const LineSegClass *ray, Collision_Group_Type group)
	{
		return new RenSharpPhysRayCollisionTestClass(*ray, group);
	}

	__declspec(dllexport) void __stdcall RenSharpPhysRayCollisionTestClassSetResult(RenSharpPhysRayCollisionTestClass *thisPtr, const CastResultStruct *res)
	{
		thisPtr->setResult(*res);
	}

	__declspec(dllexport) void __stdcall DestroyRenSharpPhysRayCollisionTestClass(RenSharpPhysRayCollisionTestClass *renSharpPhysRayCollisionTestClass)
	{
		delete renSharpPhysRayCollisionTestClass;
	}

	__declspec(dllexport) PhysAABoxCollisionTestClass * __stdcall CreatePhysAABoxCollisionTestClass1(const AABoxClass *box, const Vector3 *move, Collision_Group_Type group, Collision_Type type)
	{
		return new PhysAABoxCollisionTestClass(*box, *move, nullptr, group, type);
	}

	__declspec(dllexport) PhysAABoxCollisionTestClass * __stdcall CreatePhysAABoxCollisionTestClass2(const AABoxClass *box, const Vector3 *move, Collision_Group_Type group)
	{
		return new PhysAABoxCollisionTestClass(*box, *move, nullptr, group);
	}

	__declspec(dllexport) void __stdcall DestroyPhysAABoxCollisionTestClass(PhysAABoxCollisionTestClass *physAABoxCollisionTestClass)
	{
		delete physAABoxCollisionTestClass;
	}

	__declspec(dllexport) RenSharpPhysAABoxCollisionTestClass * __stdcall CreateRenSharpPhysAABoxCollisionTestClass1(const AABoxClass *box, const Vector3 *move, Collision_Group_Type group, Collision_Type type)
	{
		return new RenSharpPhysAABoxCollisionTestClass(*box, *move, group, type);
	}

	__declspec(dllexport) RenSharpPhysAABoxCollisionTestClass * __stdcall CreateRenSharpPhysAABoxCollisionTestClass2(const AABoxClass *box, const Vector3 *move, Collision_Group_Type group)
	{
		return new RenSharpPhysAABoxCollisionTestClass(*box, *move, group);
	}

	__declspec(dllexport) void __stdcall RenSharpPhysAABoxCollisionTestClassSetResult(RenSharpPhysAABoxCollisionTestClass *thisPtr, const CastResultStruct *res)
	{
		thisPtr->setResult(*res);
	}

	__declspec(dllexport) void __stdcall DestroyRenSharpPhysAABoxCollisionTestClass(RenSharpPhysAABoxCollisionTestClass *renSharpPhysAABoxCollisionTestClass)
	{
		delete renSharpPhysAABoxCollisionTestClass;
	}

	__declspec(dllexport) PhysOBBoxCollisionTestClass * __stdcall CreatePhysOBBoxCollisionTestClass1(const OBBoxClass *box, const Vector3 *move, Collision_Group_Type group, Collision_Type type)
	{
		return new PhysOBBoxCollisionTestClass(*box, *move, nullptr, group, type);
	}

	__declspec(dllexport) PhysOBBoxCollisionTestClass * __stdcall CreatePhysOBBoxCollisionTestClass2(const OBBoxClass *box, const Vector3 *move, Collision_Group_Type group)
	{
		return new PhysOBBoxCollisionTestClass(*box, *move, nullptr, group);
	}

	__declspec(dllexport) void __stdcall DestroyPhysOBBoxCollisionTestClass(PhysOBBoxCollisionTestClass *physOBBoxCollisionTestClass)
	{
		delete physOBBoxCollisionTestClass;
	}

	__declspec(dllexport) RenSharpPhysOBBoxCollisionTestClass * __stdcall CreateRenSharpPhysOBBoxCollisionTestClass1(const OBBoxClass *box, const Vector3 *move, Collision_Group_Type group, Collision_Type type)
	{
		return new RenSharpPhysOBBoxCollisionTestClass(*box, *move, group, type);
	}

	__declspec(dllexport) RenSharpPhysOBBoxCollisionTestClass * __stdcall CreateRenSharpPhysOBBoxCollisionTestClass2(const OBBoxClass *box, const Vector3 *move, Collision_Group_Type group)
	{
		return new RenSharpPhysOBBoxCollisionTestClass(*box, *move, group);
	}

	__declspec(dllexport) void __stdcall RenSharpPhysOBBoxCollisionTestClassSetResult(RenSharpPhysOBBoxCollisionTestClass *thisPtr, const CastResultStruct *res)
	{
		thisPtr->setResult(*res);
	}

	__declspec(dllexport) void __stdcall DestroyRenSharpPhysOBBoxCollisionTestClass(RenSharpPhysOBBoxCollisionTestClass *renSharpPhysOBBoxCollisionTestClass)
	{
		delete renSharpPhysOBBoxCollisionTestClass;
	}

	__declspec(dllexport) RefMultiListClass<MaterialEffectClass> * __stdcall CreateMaterialEffectClassRefMultiListClass()
	{
		return new RefMultiListClass<MaterialEffectClass>();
	}

	__declspec(dllexport) void __stdcall DestroyMaterialEffectClassRefMultiListClass(RefMultiListClass<MaterialEffectClass> *MaterialEffectClassRefMultiListClass)
	{
		delete MaterialEffectClassRefMultiListClass;
	}

	__declspec(dllexport) RefMultiListIterator<MaterialEffectClass> * __stdcall CreateMaterialEffectClassRefMultiListIterator(RefMultiListClass<MaterialEffectClass> *list)
	{
		return new RefMultiListIterator<MaterialEffectClass>(list);
	}

	__declspec(dllexport) void __stdcall DestroyMaterialEffectClassRefMultiListIterator(RefMultiListIterator<MaterialEffectClass> *MaterialEffectClassRefMultiListIterator)
	{
		delete MaterialEffectClassRefMultiListIterator;
	}

	__declspec(dllexport) void __stdcall DestroyGenericSLNode(GenericSLNode *genericSLNode)
	{
		delete genericSLNode;
	}

	__declspec(dllexport) void __stdcall DestroycPlayerSLNode(SLNode<cPlayer> *cPlayerSLNode)
	{
		delete cPlayerSLNode;
	}

	__declspec(dllexport) SList<cPlayer> * __stdcall CreatecPlayerSList()
	{
		return new SList<cPlayer>();
	}

	__declspec(dllexport) void __stdcall DestroycPlayerSList(SList<cPlayer> *cPlayerSList)
	{
		delete cPlayerSList;
	}

	__declspec(dllexport) GameDefinition * __stdcall CreateGameDefinition()
	{
		return new GameDefinition();
	}

	__declspec(dllexport) void __stdcall DestroyGameDefinition(GameDefinition *gameDefinition)
	{
		delete gameDefinition;
	}

	__declspec(dllexport) SimpleVecClass<uint32> * __stdcall Createuint32SimpleVecClass1()
	{
		return new SimpleVecClass<uint32>();
	}

	__declspec(dllexport) SimpleVecClass<uint32> * __stdcall Createuint32SimpleVecClass2(int size)
	{
		return new SimpleVecClass<uint32>(size);
	}

	__declspec(dllexport) void __stdcall Destroyuint32SimpleVecClass(SimpleVecClass<uint32> *uint32SimpleVecClass)
	{
		delete uint32SimpleVecClass;
	}

	__declspec(dllexport) HashTemplateClass<StringClass, GameDefinition> * __stdcall CreateStringClassGameDefinitionHashTemplateClass()
	{
		return new HashTemplateClass<StringClass, GameDefinition>();
	}

	__declspec(dllexport) void __stdcall DestroyStringClassGameDefinitionHashTemplateClass(HashTemplateClass<StringClass, GameDefinition> *stringClassGameDefinitionHashTemplateClass)
	{
		delete stringClassGameDefinitionHashTemplateClass;
	}

	__declspec(dllexport) HashTemplateIterator<StringClass, GameDefinition> * __stdcall CreateStringClassGameDefinitionHashTemplateIterator(HashTemplateClass<StringClass, GameDefinition> *table)
	{
		return new HashTemplateIterator<StringClass, GameDefinition>(*table);
	}

	__declspec(dllexport) void __stdcall DestroyStringClassGameDefinitionHashTemplateIterator(HashTemplateIterator<StringClass, GameDefinition> *stringClassGameDefinitionHashTemplateIterator)
	{
		delete stringClassGameDefinitionHashTemplateIterator;
	}

	class AnimCollisionManagerClassHelper : public AnimCollisionManagerClass
	{
		private:
			AnimCollisionManagerClassHelper(PhysClass &parent)
				: AnimCollisionManagerClass(parent)
			{

			}

		public:
			static void DestroyCollideableObjClass(void *collideableObjClass)
			{
				CollideableObjClass *castObj = reinterpret_cast<CollideableObjClass *>(collideableObjClass);

				delete castObj;
			}

			static void DestroyCollideableObjClassDynamicVectorClass(void *collideableObjClassDynamicVectorClass)
			{
				DynamicVectorClass<CollideableObjClass> *castObj = reinterpret_cast<DynamicVectorClass<CollideableObjClass> *>(collideableObjClassDynamicVectorClass);

				delete castObj;
			}
	};

	__declspec(dllexport) void __stdcall DestroyCollideableObjClass(void *collideableObjClass)
	{
		AnimCollisionManagerClassHelper::DestroyCollideableObjClass(collideableObjClass);
	}

	__declspec(dllexport) void __stdcall DestroyCollideableObjClassDynamicVectorClass(void *collideableObjClassDynamicVectorClass)
	{
		AnimCollisionManagerClassHelper::DestroyCollideableObjClassDynamicVectorClass(collideableObjClassDynamicVectorClass);
	}

	__declspec(dllexport) void __stdcall DestroySceneIterator(SceneIterator *sceneIterator)
	{
		delete sceneIterator;
	}

	__declspec(dllexport) DynamicVectorClass<int> * __stdcall CreateInt32DynamicVectorClass1()
	{
		return new DynamicVectorClass<int>();
	}

	__declspec(dllexport) DynamicVectorClass<int> * __stdcall CreateInt32DynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<int>(size);
	}

	__declspec(dllexport) void __stdcall DestroyInt32DynamicVectorClass(DynamicVectorClass<int> *int32DynamicVectorClass)
	{
		delete int32DynamicVectorClass;
	}

	__declspec(dllexport) float *__stdcall CreateFloatArray(std::size_t size)
	{
		return new float[size];
	}

	__declspec(dllexport) void __stdcall DestroyFloatArray(float *fArray)
	{
		delete[] fArray;
	}

	__declspec(dllexport) uint32 *__stdcall CreateUInt32()
	{
		return new uint32;
	}

	__declspec(dllexport) void __stdcall DestroyUInt32(uint32 *i)
	{
		delete i;
	}

	__declspec(dllexport) PivotClass *__stdcall CreatePivotClass()
	{
		return new PivotClass();
	}

	__declspec(dllexport) void __stdcall DestroyPivotClass(PivotClass *pivotClass)
	{
		delete pivotClass;
	}

	__declspec(dllexport) Gap_ListNode *__stdcall CreateGap_ListNode()
	{
		auto result = new Gap_ListNode();
		result->Next = nullptr;

		return result;
	}

	__declspec(dllexport) void __stdcall DestroyGap_ListNode(Gap_ListNode *gap_ListNode)
	{
		delete gap_ListNode;
	}

	__declspec(dllexport) void __stdcall DestroyPrototypeClass(PrototypeClass *prototypeClass)
	{
		delete prototypeClass;
	}

	__declspec(dllexport) void __stdcall DestroyPrototypeLoaderClass(PrototypeLoaderClass *prototypeLoaderClass)
	{
		delete prototypeLoaderClass;
	}

	__declspec(dllexport) PrimitivePrototypeClass *__stdcall CreatePrimitivePrototypeClass(RenderObjClass *proto)
	{
		return new PrimitivePrototypeClass(proto);
	}

	__declspec(dllexport) void __stdcall DestroyConsoleFunctionClass(ConsoleFunctionClass *consoleFunctionClass)
	{
		delete consoleFunctionClass;
	}

	__declspec(dllexport) RenSharpConsoleFunctionClass *__stdcall CreateRenSharpConsoleFunctionClass(const char *name, const char *alias, const char *help)
	{
		return new RenSharpConsoleFunctionClass(name, alias, help);
	}

	__declspec(dllexport) DynamicVectorClass<ConsoleFunctionClass *> * __stdcall CreateConsoleFunctionClassPtrDynamicVectorClass1()
	{
		return new DynamicVectorClass<ConsoleFunctionClass *>();
	}

	__declspec(dllexport) DynamicVectorClass<ConsoleFunctionClass *> * __stdcall CreateConsoleFunctionClassPtrDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<ConsoleFunctionClass *>(size);
	}

	__declspec(dllexport) void __stdcall DestroyConsoleFunctionClassPtrDynamicVectorClass(DynamicVectorClass<ConsoleFunctionClass *> *ConsoleFunctionClassPtrDynamicVectorClass)
	{
		delete ConsoleFunctionClassPtrDynamicVectorClass;
	}

	__declspec(dllexport) WWAudioClass::DRIVER_INFO_STRUCT *__stdcall CreateDriverInfoStruct()
	{
		auto result = new WWAudioClass::DRIVER_INFO_STRUCT();
		result->driver = 0;
		result->name = nullptr;

		return result;
	}

	__declspec(dllexport) void __stdcall DestroyDriverInfoStruct(WWAudioClass::DRIVER_INFO_STRUCT *driverInfoStruct)
	{
		delete driverInfoStruct;
	}

	__declspec(dllexport) void __stdcall DestroyWWAudioClass(WWAudioClass *wwAudioClass)
	{
		delete wwAudioClass;
	}

	__declspec(dllexport) SimpleDynVecClass<ScriptableGameObj *> * __stdcall CreateScriptableGameObjPtrSimpleDynVecClass1()
	{
		return new SimpleDynVecClass<ScriptableGameObj *>();
	}

	__declspec(dllexport) SimpleDynVecClass<ScriptableGameObj *> * __stdcall CreateScriptableGameObjPtrSimpleDynVecClass2(int size)
	{
		return new SimpleDynVecClass<ScriptableGameObj *>(size);
	}

	__declspec(dllexport) void __stdcall DestroyScriptableGameObjPtrSimpleDynVecClass(SimpleDynVecClass<ScriptableGameObj *> *scriptableGameObjPtrSimpleDynVecClass)
	{
		delete scriptableGameObjPtrSimpleDynVecClass;
	}

	__declspec(dllexport) void __stdcall DestroyBaseGameObjSLNode(SLNode<BaseGameObj> *BaseGameObjSLNode)
	{
		delete BaseGameObjSLNode;
	}

	__declspec(dllexport) SList<BaseGameObj> * __stdcall CreateBaseGameObjSList()
	{
		return new SList<BaseGameObj>();
	}

	__declspec(dllexport) void __stdcall DestroyBaseGameObjSList(SList<BaseGameObj> *BaseGameObjSList)
	{
		delete BaseGameObjSList;
	}

	__declspec(dllexport) void __stdcall DestroyBuildingGameObjSLNode(SLNode<BuildingGameObj> *BuildingGameObjSLNode)
	{
		delete BuildingGameObjSLNode;
	}

	__declspec(dllexport) SList<BuildingGameObj> * __stdcall CreateBuildingGameObjSList()
	{
		return new SList<BuildingGameObj>();
	}

	__declspec(dllexport) void __stdcall DestroyBuildingGameObjSList(SList<BuildingGameObj> *BuildingGameObjSList)
	{
		delete BuildingGameObjSList;
	}

	__declspec(dllexport) void __stdcall DestroySoldierGameObjSLNode(SLNode<SoldierGameObj> *SoldierGameObjSLNode)
	{
		delete SoldierGameObjSLNode;
	}

	__declspec(dllexport) SList<SoldierGameObj> * __stdcall CreateSoldierGameObjSList()
	{
		return new SList<SoldierGameObj>();
	}

	__declspec(dllexport) void __stdcall DestroySoldierGameObjSList(SList<SoldierGameObj> *SoldierGameObjSList)
	{
		delete SoldierGameObjSList;
	}

	__declspec(dllexport) void __stdcall DestroySmartGameObjSLNode(SLNode<SmartGameObj> *SmartGameObjSLNode)
	{
		delete SmartGameObjSLNode;
	}

	__declspec(dllexport) SList<SmartGameObj> * __stdcall CreateSmartGameObjSList()
	{
		return new SList<SmartGameObj>();
	}

	__declspec(dllexport) void __stdcall DestroySmartGameObjSList(SList<SmartGameObj> *SmartGameObjSList)
	{
		delete SmartGameObjSList;
	}

	__declspec(dllexport) void __stdcall DestroyC4GameObjSLNode(SLNode<C4GameObj> *C4GameObjSLNode)
	{
		delete C4GameObjSLNode;
	}

	__declspec(dllexport) SList<C4GameObj> * __stdcall CreateC4GameObjSList()
	{
		return new SList<C4GameObj>();
	}

	__declspec(dllexport) void __stdcall DestroyC4GameObjSList(SList<C4GameObj> *C4GameObjSList)
	{
		delete C4GameObjSList;
	}

	__declspec(dllexport) void __stdcall DestroyBeaconGameObjSLNode(SLNode<BeaconGameObj> *BeaconGameObjSLNode)
	{
		delete BeaconGameObjSLNode;
	}

	__declspec(dllexport) SList<BeaconGameObj> * __stdcall CreateBeaconGameObjSList()
	{
		return new SList<BeaconGameObj>();
	}

	__declspec(dllexport) void __stdcall DestroyBeaconGameObjSList(SList<BeaconGameObj> *BeaconGameObjSList)
	{
		delete BeaconGameObjSList;
	}

	__declspec(dllexport) void __stdcall DestroyVehicleGameObjSLNode(SLNode<VehicleGameObj> *VehicleGameObjSLNode)
	{
		delete VehicleGameObjSLNode;
	}

	__declspec(dllexport) SList<VehicleGameObj> * __stdcall CreateVehicleGameObjSList()
	{
		return new SList<VehicleGameObj>();
	}

	__declspec(dllexport) void __stdcall DestroyVehicleGameObjSList(SList<VehicleGameObj> *VehicleGameObjSList)
	{
		delete VehicleGameObjSList;
	}

	__declspec(dllexport) void __stdcall DestroyScriptZoneGameObjSLNode(SLNode<ScriptZoneGameObj> *ScriptZoneGameObjSLNode)
	{
		delete ScriptZoneGameObjSLNode;
	}

	__declspec(dllexport) SList<ScriptZoneGameObj> * __stdcall CreateScriptZoneGameObjSList()
	{
		return new SList<ScriptZoneGameObj>();
	}

	__declspec(dllexport) void __stdcall DestroyScriptZoneGameObjSList(SList<ScriptZoneGameObj> *ScriptZoneGameObjSList)
	{
		delete ScriptZoneGameObjSList;
	}

	__declspec(dllexport) void __stdcall DestroyDAEventClass(DAEventClass* daEventClass)
	{
		delete daEventClass;
	}

	__declspec(dllexport) DAEventStruct* __stdcall CreateDAEventStruct()
	{
		auto result = new DAEventStruct();
		result->Base = nullptr;

		return result;
	}

	__declspec(dllexport) void __stdcall DestroyDAEventStruct(DAEventStruct* daEventStruct)
	{
		delete daEventStruct;
	}

	__declspec(dllexport) DAObjectEventStruct* __stdcall CreateDAObjectEventStruct()
	{
		auto result = new DAObjectEventStruct();
		result->Base = nullptr;

		return result;
	}

	__declspec(dllexport) void __stdcall DestroyDAObjectEventStruct(DAObjectEventStruct* daObjectEventStruct)
	{
		delete daObjectEventStruct;
	}

	__declspec(dllexport) DAEventTimerStruct* __stdcall CreateDAEventTimerStruct()
	{
		auto result = new DAEventTimerStruct();
		result->Base = nullptr;
		result->Data = 0;

		return result;
	}

	__declspec(dllexport) void __stdcall DestroyDAEventTimerStruct(DAEventTimerStruct* daEventTimerStruct)
	{
		delete daEventTimerStruct;
	}

	__declspec(dllexport) RenSharpEventClass* __stdcall CreateRenSharpEventClass()
	{
		return new RenSharpEventClass();
	}

	__declspec(dllexport) cGameDataEvent* __stdcall CreatecGameDataEvent(bool a, int b)
	{
		return new cGameDataEvent(a, b);
	}

	__declspec(dllexport) void __stdcall DestroycGameDataEvent(cGameDataEvent* cGameDataEvent)
	{
		delete cGameDataEvent;
	}

	__declspec(dllexport) Signaler<cGameDataEvent>* __stdcall CreatecGameDataEventSignaler()
	{
		return new Signaler<cGameDataEvent>();
	}

	__declspec(dllexport) void __stdcall DestroycGameDataEventSignaler(Signaler<cGameDataEvent>* cGameDataEventSignaler)
	{
		delete cGameDataEventSignaler;
	}

	__declspec(dllexport) DynamicVectorClass<WideStringClass>* __stdcall CreateWideStringClassDynamicVectorClass1()
	{
		return new DynamicVectorClass<WideStringClass>();
	}

	__declspec(dllexport) DynamicVectorClass<WideStringClass>* __stdcall CreateWideStringClassDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<WideStringClass>(size);
	}

	__declspec(dllexport) void __stdcall DestroyWideStringClassDynamicVectorClass(DynamicVectorClass<WideStringClass>* WideStringClassDynamicVectorClass)
	{
		delete WideStringClassDynamicVectorClass;
	}

	__declspec(dllexport) DABanEntryClass* __stdcall CreateDABanEntryClass(const char* name, const char* ip, const char* serial, const char* reason)
	{
		return new DABanEntryClass(name, ip, serial, reason);
	}

	__declspec(dllexport) void __stdcall DestroyDABanEntryClass(DABanEntryClass* daBanEntryClass)
	{
		delete daBanEntryClass;
	}

	__declspec(dllexport) DABanListClass* __stdcall CreateDABanListClass(const char* name, const char* fileName)
	{
		return new DABanListClass(name, fileName);
	}

	__declspec(dllexport) void __stdcall DestroyDABanListClass(DABanListClass* daBanListClass)
	{
		delete daBanListClass;
	}

	__declspec(dllexport) void __stdcall DestroyDAChatCommandClass(DAChatCommandClass* daChatCommandClass)
	{
		delete daChatCommandClass;
	}

	__declspec(dllexport) DAEventChatCommandStruct* __stdcall CreateDAEventChatCommandStruct()
	{
		return new DAEventChatCommandStruct();
	}

	__declspec(dllexport) void __stdcall DestroyDAEventChatCommandStruct(DAEventChatCommandStruct* daEventChatCommandStruct)
	{
		delete daEventChatCommandStruct;
	}

	__declspec(dllexport) void __stdcall DestroyDAKeyHookClass(DAKeyHookClass* daKeyHookClass)
	{
		delete daKeyHookClass;
	}

	__declspec(dllexport) DAEventKeyHookStruct* __stdcall CreateDAEventKeyHookStruct()
	{
		return new DAEventKeyHookStruct();
	}

	__declspec(dllexport) void __stdcall DestroyDAEventKeyHookStruct(DAEventKeyHookStruct* daEventKeyHookStruct)
	{
		delete daEventKeyHookStruct;
	}

	__declspec(dllexport) DADamageEventStruct* __stdcall CreateDADamageEventStruct()
	{
		return new DADamageEventStruct();
	}

	__declspec(dllexport) void __stdcall DestroyDADamageEventStruct(DADamageEventStruct* daDamageEventStruct)
	{
		delete daDamageEventStruct;
	}

	__declspec(dllexport) DADamageTableStruct* __stdcall CreateDADamageTableStruct1()
	{
		return new DADamageTableStruct();
	}

	__declspec(dllexport) DADamageTableStruct* __stdcall CreateDADamageTableStruct2(cPlayer* player, float damage)
	{
		return new DADamageTableStruct();
	}

	__declspec(dllexport) void __stdcall DestroyDADamageTableStruct(DADamageTableStruct* daDamageTableStruct)
	{
		delete daDamageTableStruct;
	}

	__declspec(dllexport) DynamicVectorClass<DADamageTableStruct>* __stdcall CreateDADamageTableStructDynamicVectorClass1()
	{
		return new DynamicVectorClass<DADamageTableStruct>();
	}

	__declspec(dllexport) DynamicVectorClass<DADamageTableStruct>* __stdcall CreateDADamageTableStructDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<DADamageTableStruct>(size);
	}

	__declspec(dllexport) void __stdcall DestroyDADamageTableStructDynamicVectorClass(DynamicVectorClass<DADamageTableStruct>* DADamageTableStructDynamicVectorClass)
	{
		delete DADamageTableStructDynamicVectorClass;
	}

	__declspec(dllexport) void __stdcall DestroyDADamageEventStructSLNode(SLNode<DADamageEventStruct>* DADamageEventStructSLNode)
	{
		delete DADamageEventStructSLNode;
	}

	__declspec(dllexport) SList<DADamageEventStruct>* __stdcall CreateDADamageEventStructSList()
	{
		return new SList<DADamageEventStruct>();
	}

	__declspec(dllexport) void __stdcall DestroyDADamageEventStructSList(SList<DADamageEventStruct>* DADamageEventStructSList)
	{
		delete DADamageEventStructSList;
	}

	__declspec(dllexport) DADamageTableStruct* __stdcall CreateDADamageTableStructArray(std::size_t size)
	{
		return new DADamageTableStruct[size];
	}

	__declspec(dllexport) void __stdcall DestroyDADamageTableStructArray(DADamageTableStruct* daDamageTableStruct)
	{
		delete[] daDamageTableStruct;
	}

	__declspec(dllexport) DynamicVectorClass<const DefinitionClass*>* __stdcall CreateConstDefinitionClassPtrDynamicVectorClass1()
	{
		return new DynamicVectorClass<const DefinitionClass*>();
	}

	__declspec(dllexport) DynamicVectorClass<const DefinitionClass*>* __stdcall CreateConstDefinitionClassPtrDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<const DefinitionClass*>(size);
	}

	__declspec(dllexport) void __stdcall DestroyConstDefinitionClassPtrDynamicVectorClass(DynamicVectorClass<const DefinitionClass*>* ConstDefinitionClassPtrDynamicVectorClass)
	{
		delete ConstDefinitionClassPtrDynamicVectorClass;
	}

	__declspec(dllexport) DACharacterDisableListStruct* __stdcall CreateDACharacterDisableListStruct()
	{
		return new DACharacterDisableListStruct();
	}

	__declspec(dllexport) void __stdcall DestroyDACharacterDisableListStruct(DACharacterDisableListStruct* daCharacterDisableListStruct)
	{
		delete daCharacterDisableListStruct;
	}

	__declspec(dllexport) void __stdcall DestroyDAGameModeFactoryClass(DAGameModeFactoryClass* daGameModeFactoryClass)
	{
		delete daGameModeFactoryClass;
	}

	__declspec(dllexport) void __stdcall DestroyDAGameModeClass(DAGameModeClass* daGameModeClass)
	{
		delete daGameModeClass;
	}

	__declspec(dllexport) void __stdcall DestroyDAGameFeatureFactoryClass(DAGameFeatureFactoryClass* daGameFeatureFactoryClass)
	{
		delete daGameFeatureFactoryClass;
	}

	__declspec(dllexport) void __stdcall DestroyDAGameFeatureClass(DAGameFeatureClass* daGameFeatureClass)
	{
		delete daGameFeatureClass;
	}

	__declspec(dllexport) DynamicVectorClass<DAGameFeatureFactoryClass*>* __stdcall CreateDAGameFeatureFactoryClassPtrDynamicVectorClass1()
	{
		return new DynamicVectorClass<DAGameFeatureFactoryClass*>();
	}

	__declspec(dllexport) DynamicVectorClass<DAGameFeatureFactoryClass*>* __stdcall CreateDAGameFeatureFactoryClassPtrDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<DAGameFeatureFactoryClass*>(size);
	}

	__declspec(dllexport) void __stdcall DestroyDAGameFeatureFactoryClassPtrDynamicVectorClass(DynamicVectorClass<DAGameFeatureFactoryClass*>* DAGameFeatureFactoryClassPtrDynamicVector)
	{
		delete DAGameFeatureFactoryClassPtrDynamicVector;
	}

	__declspec(dllexport) RenSharpGameFeatureFactoryClass* __stdcall CreateRenSharpGameFeatureFactoryClass(const char* name, const char* enableSetting, const char* requiredData)
	{
		return new RenSharpGameFeatureFactoryClass(name, enableSetting, requiredData);
	}

	__declspec(dllexport) RenSharpGameFeatureClass* __stdcall CreateRenSharpGameFeatureClass()
	{
		return new RenSharpGameFeatureClass();
	}

	__declspec(dllexport) RenSharpPlayerDataFactoryClass* __stdcall CreateRenSharpPlayerDataFactoryClass()
	{
		return new RenSharpPlayerDataFactoryClass();
	}

	__declspec(dllexport) RenSharpPlayerDataClass* __stdcall CreateRenSharpPlayerDataClass()
	{
		return new RenSharpPlayerDataClass();
	}

	__declspec(dllexport) RenSharpGameModeFactoryClass* __stdcall CreateRenSharpGameModeFactoryClass(const char* shortName, const char* longName, const char* requiredData)
	{
		return new RenSharpGameModeFactoryClass(shortName, longName, requiredData);
	}

	__declspec(dllexport) RenSharpGameModeClass* __stdcall CreateRenSharpGameModeClass()
	{
		return new RenSharpGameModeClass();
	}

	__declspec(dllexport) RenSharpGameFeatureEventClass* __stdcall CreateRenSharpGameFeatureEventClass(RenSharpEventClass** eventClassPtr, RenSharpGameFeatureClass** gameFeaturePtr)
	{
		auto result = new RenSharpGameFeatureEventClass();

		(*eventClassPtr) = result;
		(*gameFeaturePtr) = result;

		return result;
	}

	__declspec(dllexport) RenSharpGameFeatureEventClassPlayerDataFactory* __stdcall CreateRenSharpGameFeatureEventClassPlayerDataFactory(RenSharpEventClass** eventClassPtr, RenSharpGameFeatureClass** gameFeaturePtr, RenSharpPlayerDataFactoryClass **playerDataFactoryPtr)
	{
		auto result = new RenSharpGameFeatureEventClassPlayerDataFactory();

		(*eventClassPtr) = result;
		(*gameFeaturePtr) = result;
		(*playerDataFactoryPtr) = result;

		return result;
	}

	__declspec(dllexport) RenSharpGameModeEventClass* __stdcall CreateRenSharpGameModeEventClass(RenSharpEventClass** eventClassPtr, RenSharpGameModeClass** gameModePtr)
	{
		auto result = new RenSharpGameModeEventClass();

		(*eventClassPtr) = result;
		(*gameModePtr) = result;

		return result;
	}

	__declspec(dllexport) RenSharpGameModeEventClassPlayerDataFactory* __stdcall CreateRenSharpGameModeEventClassPlayerDataFactory(RenSharpEventClass** eventClassPtr, RenSharpGameModeClass** gameModePtr, RenSharpPlayerDataFactoryClass** playerDataFactoryPtr)
	{
		auto result = new RenSharpGameModeEventClassPlayerDataFactory();

		(*eventClassPtr) = result;
		(*gameModePtr) = result;
		(*playerDataFactoryPtr) = result;

		return result;
	}

	__declspec(dllexport) DATimedInvincibilityObserverClass* __stdcall CreateDATimedInvincibilityObserverClass(float protectTime)
	{
		return new DATimedInvincibilityObserverClass(protectTime);
	}

	__declspec(dllexport) DAAttachToObjectWithZOffsetObserverClass* __stdcall CreateDAAttachToObjectWithZOffsetObserverClass(ScriptableGameObj* host, float offset, float syncTime)
	{
		return new DAAttachToObjectWithZOffsetObserverClass(host, offset, syncTime);
	}

	__declspec(dllexport) DANoPointsUntilEnteredObserverClass* __stdcall CreateDANoPointsUntilEnteredObserverClass()
	{
		return new DANoPointsUntilEnteredObserverClass();
	}

	__declspec(dllexport) DynamicVectorClass<const WeaponDefinitionClass*>* __stdcall CreateConstWeaponDefinitionClassPtrDynamicVectorClass1()
	{
		return new DynamicVectorClass<const WeaponDefinitionClass*>();
	}

	__declspec(dllexport) DynamicVectorClass<const WeaponDefinitionClass*>* __stdcall CreateConstWeaponDefinitionClassPtrDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<const WeaponDefinitionClass*>(size);
	}

	__declspec(dllexport) void __stdcall DestroyConstWeaponDefinitionClassPtrDynamicVectorClass(DynamicVectorClass<const WeaponDefinitionClass*>* ConstWeaponDefinitionClassPtrDynamicVectorClass)
	{
		delete ConstWeaponDefinitionClassPtrDynamicVectorClass;
	}

	__declspec(dllexport) HashTemplateClass<unsigned int, DynamicVectorClass<const WeaponDefinitionClass*>>* __stdcall CreateUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass()
	{
		return new HashTemplateClass<unsigned int, DynamicVectorClass<const WeaponDefinitionClass*>>();
	}

	__declspec(dllexport) void __stdcall DestroyUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass(HashTemplateClass<unsigned int, DynamicVectorClass<const WeaponDefinitionClass*>>* UInt32ConstWeaponDefinitionClassPtrDynamicVectorClass)
	{
		delete UInt32ConstWeaponDefinitionClassPtrDynamicVectorClass;
	}

	__declspec(dllexport) HashTemplateIterator<unsigned int, DynamicVectorClass<const WeaponDefinitionClass*>>* __stdcall CreateUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator(HashTemplateClass<unsigned int, DynamicVectorClass<const WeaponDefinitionClass*>>* table)
	{
		return new HashTemplateIterator<unsigned int, DynamicVectorClass<const WeaponDefinitionClass*>>(*table);
	}

	__declspec(dllexport) void __stdcall DestroyUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator(HashTemplateIterator<unsigned int, DynamicVectorClass<const WeaponDefinitionClass*>>* UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassIterator)
	{
		delete UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassIterator;
	}

	__declspec(dllexport) HashTemplateClass<unsigned int, const WeaponDefinitionClass*>* __stdcall CreateUInt32ConstWeaponDefinitionClassPtrHashTemplateClass()
	{
		return new HashTemplateClass<unsigned int, const WeaponDefinitionClass*>();
	}

	__declspec(dllexport) void __stdcall DestroyUInt32ConstWeaponDefinitionClassPtrHashTemplateClass(HashTemplateClass<unsigned int, const WeaponDefinitionClass*>* UInt32ConstWeaponDefinitionClassPtrHashTemplateClass)
	{
		delete UInt32ConstWeaponDefinitionClassPtrHashTemplateClass;
	}

	__declspec(dllexport) HashTemplateIterator<unsigned int, const WeaponDefinitionClass*>* __stdcall CreateUInt32ConstWeaponDefinitionClassPtrHashTemplateIterator(HashTemplateClass<unsigned int, const WeaponDefinitionClass*>* table)
	{
		return new HashTemplateIterator<unsigned int, const WeaponDefinitionClass*>(*table);
	}

	__declspec(dllexport) void __stdcall DestroyUInt32ConstWeaponDefinitionClassPtrHashTemplateIterator(HashTemplateIterator<unsigned int, const WeaponDefinitionClass*>* UInt32ConstWeaponDefinitionClassPtrHashTemplateIterator)
	{
		delete UInt32ConstWeaponDefinitionClassPtrHashTemplateIterator;
	}

	__declspec(dllexport) void __stdcall DestroyPlugin(Plugin* plugin)
	{
		delete plugin;
	}

	__declspec(dllexport) void __stdcall DestroyDACrateModifierFactoryClass(DACrateModifierFactoryClass* daCrateModifierFactoryClass)
	{
		delete daCrateModifierFactoryClass;
	}

	__declspec(dllexport) void __stdcall DestroyDACrateModifierClass(DACrateModifierClass* daCrateModifierClass)
	{
		delete daCrateModifierClass;
	}

	__declspec(dllexport) void __stdcall DestroyDACrateFactoryClass(DACrateFactoryClass* daCrateFactoryClass)
	{
		delete daCrateFactoryClass;
	}

	__declspec(dllexport) void __stdcall DestroyDACrateClass(DACrateClass* daCrateClass)
	{
		delete daCrateClass;
	}

	__declspec(dllexport) DynamicVectorClass<DACrateModifierClass*>* __stdcall CreateDACrateModifierClassPtrDynamicVectorClass1()
	{
		return new DynamicVectorClass<DACrateModifierClass*>();
	}

	__declspec(dllexport) DynamicVectorClass<DACrateModifierClass*>* __stdcall CreateDACrateModifierClassPtrDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<DACrateModifierClass*>(size);
	}

	__declspec(dllexport) void __stdcall DestroyDACrateModifierClassPtrDynamicVectorClass(DynamicVectorClass<DACrateModifierClass*>* DACrateModifierClassPtrDynamicVector)
	{
		delete DACrateModifierClassPtrDynamicVector;
	}

	__declspec(dllexport) DynamicVectorClass<DACrateFactoryClass*>* __stdcall CreateDACrateFactoryClassPtrDynamicVectorClass1()
	{
		return new DynamicVectorClass<DACrateFactoryClass*>();
	}

	__declspec(dllexport) DynamicVectorClass<DACrateFactoryClass*>* __stdcall CreateDACrateFactoryClassPtrDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<DACrateFactoryClass*>(size);
	}

	__declspec(dllexport) void __stdcall DestroyDACrateFactoryClassPtrDynamicVectorClass(DynamicVectorClass<DACrateFactoryClass*>* DACrateFactoryClassPtrDynamicVector)
	{
		delete DACrateFactoryClassPtrDynamicVector;
	}

	__declspec(dllexport) DynamicVectorClass<DACrateModifierFactoryClass*>* __stdcall CreateDACrateModifierFactoryClassPtrDynamicVectorClass1()
	{
		return new DynamicVectorClass<DACrateModifierFactoryClass*>();
	}

	__declspec(dllexport) DynamicVectorClass<DACrateModifierFactoryClass*>* __stdcall CreateDACrateModifierFactoryClassPtrDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<DACrateModifierFactoryClass*>(size);
	}

	__declspec(dllexport) void __stdcall DestroyDACrateModifierFactoryClassPtrDynamicVectorClass(DynamicVectorClass<DACrateModifierFactoryClass*>* DACrateModifierFactoryClassPtrDynamicVector)
	{
		delete DACrateModifierFactoryClassPtrDynamicVector;
	}

	__declspec(dllexport) DynamicVectorClass<PhysicalGameObj*>* __stdcall CreatePhysicalGameObjPtrDynamicVectorClass1()
	{
		return new DynamicVectorClass<PhysicalGameObj*>();
	}

	__declspec(dllexport) DynamicVectorClass<PhysicalGameObj*>* __stdcall CreatePhysicalGameObjPtrDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<PhysicalGameObj*>(size);
	}

	__declspec(dllexport) void __stdcall DestroyPhysicalGameObjPtrDynamicVectorClass(DynamicVectorClass<PhysicalGameObj*>* PhysicalGameObjPtrDynamicVector)
	{
		delete PhysicalGameObjPtrDynamicVector;
	}

	__declspec(dllexport) DynamicVectorClass<Vector3>* __stdcall CreateVector3DynamicVectorClass1()
	{
		return new DynamicVectorClass<Vector3>();
	}

	__declspec(dllexport) DynamicVectorClass<Vector3>* __stdcall CreateVector3DynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<Vector3>(size);
	}

	__declspec(dllexport) void __stdcall DestroyVector3DynamicVectorClass(DynamicVectorClass<Vector3>* Vector3DynamicVectorClass)
	{
		delete Vector3DynamicVectorClass;
	}

	__declspec(dllexport) DynamicVectorClass<Vector3*>* __stdcall CreateVector3PtrDynamicVectorClass1()
	{
		return new DynamicVectorClass<Vector3*>();
	}

	__declspec(dllexport) DynamicVectorClass<Vector3*>* __stdcall CreateVector3PtrDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<Vector3*>(size);
	}

	__declspec(dllexport) void __stdcall DestroyVector3PtrDynamicVectorClass(DynamicVectorClass<Vector3*>* Vector3PtrDynamicVectorClass)
	{
		delete Vector3PtrDynamicVectorClass;
	}

	__declspec(dllexport) RenSharpCrateModifierFactoryClass* __stdcall CreateRenSharpCrateModifierFactoryClass(const char* name)
	{
		return new RenSharpCrateModifierFactoryClass(name);
	}

	__declspec(dllexport) RenSharpCrateModifierClass* __stdcall CreateRenSharpCrateModifierClass()
	{
		return new RenSharpCrateModifierClass();
	}

	__declspec(dllexport) RenSharpCrateClass* __stdcall CreateRenSharpCrateClass()
	{
		return new RenSharpCrateClass();
	}

	__declspec(dllexport) RenSharpCrateFactoryClass* __stdcall CreateRenSharpCrateFactoryClass(const char* name, DACrateType::Type type)
	{
		return new RenSharpCrateFactoryClass(name, type);
	}

	__declspec(dllexport) DACharacterRefundsPlayerDataClass* __stdcall CreateDACharacterRefundsPlayerDataClass()
	{
		return new DACharacterRefundsPlayerDataClass();
	}

	__declspec(dllexport) DAChatSoundsPlayerDataClass* __stdcall CreateDAChatSoundsPlayerDataClass()
	{
		return new DAChatSoundsPlayerDataClass();
	}

	__declspec(dllexport) DALootPlayerDataClass* __stdcall CreateDALootPlayerDataClass()
	{
		return new DALootPlayerDataClass();
	}

	__declspec(dllexport) DALootPowerUpClass* __stdcall CreateDALootPowerUpClass1()
	{
		return new DALootPowerUpClass();
	}

	__declspec(dllexport) DALootPowerUpClass* __stdcall CreateDALootPowerUpClass2(SoldierGameObj* soldier)
	{
		return new DALootPowerUpClass(soldier);
	}

	__declspec(dllexport) DALootBackpackClass* __stdcall CreateDALootBackpackClass1()
	{
		return new DALootBackpackClass();
	}

	__declspec(dllexport) DALootBackpackClass* __stdcall CreateDALootBackpackClass2(SoldierGameObj* soldier)
	{
		return new DALootBackpackClass(soldier);
	}

	__declspec(dllexport) DALootDNAClass* __stdcall CreateDALootDNAClass1(const SoldierGameObjDef* charDef)
	{
		return new DALootDNAClass(charDef);
	}

	__declspec(dllexport) DALootDNAClass* __stdcall CreateDALootDNAClass2(SoldierGameObj* soldier)
	{
		return new DALootDNAClass(soldier);
	}

	__declspec(dllexport) DALootGameFeatureClass* __stdcall CreateDALootGameFeatureClass()
	{
		return new DALootGameFeatureClass();
	}

	__declspec(dllexport) DynamicVectorClass<cPlayer*>* __stdcall CreatecPlayerPtrDynamicVectorClass1()
	{
		return new DynamicVectorClass<cPlayer*>();
	}

	__declspec(dllexport) DynamicVectorClass<cPlayer*>* __stdcall CreatecPlayerPtrDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<cPlayer*>(size);
	}

	__declspec(dllexport) void __stdcall DestroycPlayerPtrDynamicVectorClass(DynamicVectorClass<cPlayer*>* cPlayerPtrDynamicVectorClass)
	{
		delete cPlayerPtrDynamicVectorClass;
	}

	__declspec(dllexport) DAExtraRadioCommandsPlayerDataClass* __stdcall CreateDAExtraRadioCommandsPlayerDataClass()
	{
		return new DAExtraRadioCommandsPlayerDataClass();
	}

	__declspec(dllexport) DARTCStruct* __stdcall CreateDARTCStruct1()
	{
		return new DARTCStruct();
	}

	__declspec(dllexport) DARTCStruct* __stdcall CreateDARTCStruct2(cPlayer* player)
	{
		return new DARTCStruct(player);
	}

	__declspec(dllexport) void __stdcall DestroyDARTCStruct(DARTCStruct* daRTCStruct)
	{
		delete daRTCStruct;
	}

	__declspec(dllexport) DARTCPlayerDataClass* __stdcall CreateDARTCPlayerDataClass()
	{
		return new DARTCPlayerDataClass();
	}

	__declspec(dllexport) DASquadInviteStruct* __stdcall CreateDASquadInviteStruct1()
	{
		return new DASquadInviteStruct();
	}

	__declspec(dllexport) DASquadInviteStruct* __stdcall CreateDASquadInviteStruct2(cPlayer* leader, cPlayer* player)
	{
		return new DASquadInviteStruct(leader, player);
	}

	__declspec(dllexport) void __stdcall DestroyDASquadInviteStruct(DASquadInviteStruct* daSquadInviteStruct)
	{
		delete daSquadInviteStruct;
	}

	__declspec(dllexport) DASquadRemixStruct* __stdcall CreateDASquadRemixStruct1()
	{
		return new DASquadRemixStruct();
	}

	__declspec(dllexport) DASquadRemixStruct* __stdcall CreateDASquadRemixStruct2(DASquadClass* squad, int team)
	{
		return new DASquadRemixStruct(squad, team);
	}

	__declspec(dllexport) void __stdcall DestroyDASquadRemixStruct(DASquadRemixStruct* daSquadRemixStruct)
	{
		delete daSquadRemixStruct;
	}

	__declspec(dllexport) DASquadMemberClass* __stdcall CreateDASquadMemberClass(DASquadClass* squad)
	{
		return new DASquadMemberClass(squad);
	}

	__declspec(dllexport) DASquadClass* __stdcall CreateDASquadClass(cPlayer* player)
	{
		return new DASquadClass(player);
	}

	__declspec(dllexport) void __stdcall DestroyDASquadClass(DASquadClass* daSquadClass)
	{
		delete daSquadClass;
	}

	__declspec(dllexport) DASquadManagerClass* __stdcall CreateDASquadManagerClass()
	{
		return new DASquadManagerClass();
	}

	__declspec(dllexport) DAVehicleOwnershipObserverClass* __stdcall CreateDAVehicleOwnershipObserverClass(VehicleGameObj* vehicle, cPlayer* player)
	{
		return new DAVehicleOwnershipObserverClass(vehicle, player);
	}

	__declspec(dllexport) DAVehicleShellStruct* __stdcall CreateDAVehicleShellStruct()
	{
		return new DAVehicleShellStruct();
	}

	__declspec(dllexport) void __stdcall DestroyDAVehicleShellStruct(DAVehicleShellStruct* daVehicleShellStruct)
	{
		delete daVehicleShellStruct;
	}

	__declspec(dllexport) DASpawnNodeClass* __stdcall CreateDASpawnNodeClass()
	{
		return new DASpawnNodeClass();
	}

	__declspec(dllexport) DASpawnPlayerDataClass* __stdcall CreateDASpawnPlayerDataClass()
	{
		return new DASpawnPlayerDataClass();
	}

	__declspec(dllexport) DASpawnPointClass::DistanceCheckStruct* __stdcall CreateDistanceCheckStruct()
	{
		return new DASpawnPointClass::DistanceCheckStruct();
	}

	__declspec(dllexport) void __stdcall DestroyDistanceCheckStruct(DASpawnPointClass::DistanceCheckStruct* distanceCheckStruct)
	{
		delete distanceCheckStruct;
	}

	__declspec(dllexport) DASpawnNodeClass* __stdcall CreateNodeDASpawnNodeClass(const INIClass* ini, const StringClass* header)
	{
		return static_cast<DASpawnNodeClass*>(DANodeManagerClass::Get_Instance()->Create_Node<DASpawnNodeClass>(ini, *header));
	}

	__declspec(dllexport) DANodeManagerClass* __stdcall CreateInstanceDANodeManagerClass()
	{
		return DANodeManagerClass::Create_Instance();
	}

	__declspec(dllexport) void __stdcall DestroyInstanceDANodeManagerClass()
	{
		DANodeManagerClass::Destroy_Instance();
	}

	__declspec(dllexport) DANodeManagerClass* __stdcall GetInstanceDANodeManagerClass()
	{
		return DANodeManagerClass::Get_Instance();
	}

	__declspec(dllexport) DASpawnManagerClass* __stdcall CreateInstanceDASpawnManagerClass()
	{
		return DASpawnManagerClass::Create_Instance();
	}

	__declspec(dllexport) void __stdcall DestroyInstanceDASpawnManagerClass()
	{
		DASpawnManagerClass::Destroy_Instance();
	}

	__declspec(dllexport) DASpawnManagerClass* __stdcall GetInstanceDASpawnManagerClass()
	{
		return DASpawnManagerClass::Get_Instance();
	}

	__declspec(dllexport) DASpawnPointClass* __stdcall CreateSpawnPointDASpawnManagerClass(DASpawnManagerClass* thisPtr, const INIClass* ini, const StringClass* header)
	{
		return thisPtr->Create_Spawn_Point(ini, *header);
	}

	__declspec(dllexport) RenSharpNodeClass* __stdcall CreateRenSharpNodeClass(const char* type)
	{
		return new RenSharpNodeClass(type);
	}

	__declspec(dllexport) DATeleporterManagerClass* __stdcall CreateInstanceDATeleporterManagerClass()
	{
		return DATeleporterManagerClass::Create_Instance();
	}

	__declspec(dllexport) void __stdcall DestroyInstanceDATeleporterManagerClass()
	{
		DATeleporterManagerClass::Destroy_Instance();
	}

	__declspec(dllexport) DATeleporterManagerClass* __stdcall GetInstanceDATeleporterManagerClass()
	{
		return DATeleporterManagerClass::Get_Instance();
	}

	__declspec(dllexport) void __stdcall DestroyDATeleporterManagerClass(DATeleporterManagerClass* daTeleporterManagerClass)
	{
		delete daTeleporterManagerClass;
	}

	__declspec(dllexport) DATeleporterClass* __stdcall CreateTeleporterDATeleporterManagerClass(DATeleporterManagerClass* thisPtr, const INIClass* ini, const StringClass* header)
	{
		return thisPtr->Create_Teleporter(ini, *header);
	}

	__declspec(dllexport) DAVehicleSpawnManagerClass* __stdcall CreateInstanceDAVehicleSpawnManagerClass()
	{
		return DAVehicleSpawnManagerClass::Create_Instance();
	}

	__declspec(dllexport) void __stdcall DestroyInstanceDAVehicleSpawnManagerClass()
	{
		DAVehicleSpawnManagerClass::Destroy_Instance();
	}

	__declspec(dllexport) DAVehicleSpawnManagerClass* __stdcall GetInstanceDAVehicleSpawnManagerClass()
	{
		return DAVehicleSpawnManagerClass::Get_Instance();
	}

	__declspec(dllexport) DAVehicleSpawnPointClass* __stdcall CreateSpawnPointDAVehicleSpawnManagerClass(DAVehicleSpawnManagerClass* thisPtr, const INIClass* ini, const StringClass* header)
	{
		return thisPtr->Create_Spawn_Point(ini, *header);
	}

	__declspec(dllexport) DAVehicleAirDropPointClass* __stdcall CreateAirDropPointDAVehicleSpawnManagerClass(DAVehicleSpawnManagerClass* thisPtr, const INIClass* ini, const StringClass* header)
	{
		return thisPtr->Create_Air_Drop_Point(ini, *header);
	}

	__declspec(dllexport) DynamicVectorClass<DAVehicleSpawnPointClass*>* __stdcall CreateDAVehicleSpawnPointClassPtrDynamicVectorClass1()
	{
		return new DynamicVectorClass<DAVehicleSpawnPointClass*>();
	}

	__declspec(dllexport) DynamicVectorClass<DAVehicleSpawnPointClass*>* __stdcall CreateDAVehicleSpawnPointClassPtrDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<DAVehicleSpawnPointClass*>(size);
	}

	__declspec(dllexport) void __stdcall DestroyDAVehicleSpawnPointClassPtrDynamicVectorClass(DynamicVectorClass<DAVehicleSpawnPointClass*>* DAVehicleSpawnPointClassPtrDynamicVectorClass)
	{
		delete DAVehicleSpawnPointClassPtrDynamicVectorClass;
	}

	__declspec(dllexport) void __stdcall DestroyConnectionAcceptanceFilter(ConnectionAcceptanceFilter* connectionAcceptanceFilter)
	{
		delete connectionAcceptanceFilter;
	}

	__declspec(dllexport) void __stdcall DestroyParameterClass(ParameterClass* parameterClass)
	{
		delete parameterClass;
	}

	__declspec(dllexport) ParameterListClass* __stdcall CreateParameterListClass()
	{
		return new ParameterListClass();
	}

	__declspec(dllexport) void __stdcall DestroyParameterListClass(ParameterListClass* parameterListClass)
	{
		delete parameterListClass;
	}

	class ParameterListClassHelper : public ParameterListClass
	{
		private:
			ParameterListClassHelper()
				: ParameterListClass()
			{

			}

		public:
			void FreeParameters()
			{
				Free_Parameters();
			}
	};

	__declspec(dllexport) void __stdcall FreeParametersParameterListClass(ParameterListClass* thisPtr)
	{
		ParameterListClassHelper* helper = reinterpret_cast<ParameterListClassHelper*>(thisPtr);

		helper->FreeParameters();
	}

	__declspec(dllexport) AABTreeCullSystemClass::StatsStruct* __stdcall CreateAABTreeCullSystemClassStatsStruct()
	{
		return new AABTreeCullSystemClass::StatsStruct();
	}

	__declspec(dllexport) void __stdcall DestroyAABTreeCullSystemClassStatsStruct(AABTreeCullSystemClass::StatsStruct* statsStruct)
	{
		delete statsStruct;
	}

	__declspec(dllexport) void __stdcall DestroyAABTreeIterator(AABTreeIterator* aabTreeIterator)
	{
		delete aabTreeIterator;
	}

	__declspec(dllexport) AABTreeNodeClass::SplitChoiceStruct* __stdcall CreateAABTreeNodeClassSplitChoiceStruct()
	{
		return new AABTreeNodeClass::SplitChoiceStruct();
	}

	__declspec(dllexport) void __stdcall DestroyAABTreeNodeClassSplitChoiceStruct(AABTreeNodeClass::SplitChoiceStruct* splitChoiceStruct)
	{
		delete splitChoiceStruct;
	}

	__declspec(dllexport) AABTreeLinkClass* __stdcall CreateAABTreeLinkClass(AABTreeCullSystemClass* system)
	{
		return new AABTreeLinkClass(system);
	}

	__declspec(dllexport) RawFileClass* __stdcall CreateRawFileClass1()
	{
		return new RawFileClass();
	}

	__declspec(dllexport) RawFileClass* __stdcall CreateRawFileClass2(const char* filename)
	{
		return new RawFileClass(filename);
	}

	__declspec(dllexport) TextFileClass* __stdcall CreateTextFileClass()
	{
		return new TextFileClass();
	}

	__declspec(dllexport) BufferedFileClass* __stdcall CreateBufferedFileClass()
	{
		return new BufferedFileClass();
	}

	__declspec(dllexport) void __stdcall DestroyCombatNetworkHandlerClass(CombatNetworkHandlerClass* combatNetworkHandlerClass)
	{
		delete combatNetworkHandlerClass;
	}

	__declspec(dllexport) void __stdcall DestroyCombatMiscHandlerClass(CombatMiscHandlerClass* combatMiscHandlerClass)
	{
		delete combatMiscHandlerClass;
	}

	__declspec(dllexport) CommandLineParser* __stdcall CreateCommandLineParser(const char* command)
	{
		return new CommandLineParser(command);
	}

	__declspec(dllexport) void __stdcall DestroyCommandLineParser(CommandLineParser* commandLineParser)
	{
		delete commandLineParser;
	}

	__declspec(dllexport) ConversationRemarkClass* __stdcall CreateConversationRemarkClass()
	{
		return new ConversationRemarkClass();
	}

	__declspec(dllexport) void __stdcall DestroyConversationRemarkClass(ConversationRemarkClass* conversationRemarkClass)
	{
		delete conversationRemarkClass;
	}

	__declspec(dllexport) OratorClass* __stdcall CreateOratorClass()
	{
		return new OratorClass();
	}

	__declspec(dllexport) void __stdcall DestroyOratorClass(OratorClass* oratorClass)
	{
		delete oratorClass;
	}

	__declspec(dllexport) void __stdcall DestroyDefinitionFactoryClass(DefinitionFactoryClass* definitionFactoryClass)
	{
		delete definitionFactoryClass;
	}

	__declspec(dllexport) GridListIterator* __stdcall CreateGridListIterator(CullableClass* head)
	{
		return new GridListIterator(head);
	}

	__declspec(dllexport) void __stdcall DestroyGridListIterator(GridListIterator* gridListIterator)
	{
		delete gridListIterator;
	}

	class GridCullSystemClassHelper : public GridCullSystemClass
	{
		private:
			GridCullSystemClassHelper()
			{

			}

		public:
			static GridCullSystemClass::VolumeStruct* CreateVolumeStruct()
			{
				return new VolumeStruct();
			}

			static GridCullSystemClass::VolumeStruct* CreateVolumeStruct(int i0, int j0, int k0, int i1, int j1, int k1)
			{
				return new VolumeStruct(i0, j0, k0, i1, j1, k1);
			}

			static void DestroyVolumeStruct(void* volumeStruct)
			{
				delete reinterpret_cast<GridCullSystemClass::VolumeStruct*>(volumeStruct);
			}
	};

	__declspec(dllexport) void* __stdcall CreateGridCullSystemClassVolumeStruct1()
	{
		return GridCullSystemClassHelper::CreateVolumeStruct();
	}

	__declspec(dllexport) void* __stdcall CreateGridCullSystemClassVolumeStruct2(int i0, int j0, int k0, int i1, int j1, int k1)
	{
		return GridCullSystemClassHelper::CreateVolumeStruct(i0, j0, k0, i1, j1, k1);
	}

	__declspec(dllexport) void __stdcall DestroyGridCullSystemClassVolumeStruct(void* volumeStruct)
	{
		GridCullSystemClassHelper::DestroyVolumeStruct(volumeStruct);
	}

	__declspec(dllexport) GridCullSystemClass::StatsStruct* __stdcall CreateGridCullSystemClassStatsStruct()
	{
		return new GridCullSystemClass::StatsStruct();
	}

	__declspec(dllexport) void __stdcall DestroyGridCullSystemClassStatsStruct(GridCullSystemClass::StatsStruct* statsStruct)
	{
		delete statsStruct;
	}

	__declspec(dllexport) mix_header* __stdcall Createmix_header()
	{
		return new mix_header();
	}

	__declspec(dllexport) void __stdcall Destroymix_header(mix_header* header)
	{
		delete header;
	}

	__declspec(dllexport) MixFileFactoryClass::FileInfoStruct* __stdcall CreateMixFileFactoryClassFileInfoStruct()
	{
		return new MixFileFactoryClass::FileInfoStruct();
	}

	__declspec(dllexport) void __stdcall DestroyMixFileFactoryClassFileInfoStruct(MixFileFactoryClass::FileInfoStruct* fileInfoStruct)
	{
		delete fileInfoStruct;
	}

	__declspec(dllexport) MixFileFactoryClass::AddInfoStruct* __stdcall CreateMixFileFactoryClassAddInfoStruct()
	{
		return new MixFileFactoryClass::AddInfoStruct();
	}

	__declspec(dllexport) void __stdcall DestroyMixFileFactoryClassAddInfoStruct(MixFileFactoryClass::AddInfoStruct* addInfoStruct)
	{
		delete addInfoStruct;
	}

	__declspec(dllexport) MixFileCreator::FileInfoStruct* __stdcall CreateMixFileCreatorFileInfoStruct()
	{
		return new MixFileCreator::FileInfoStruct();
	}

	__declspec(dllexport) void __stdcall DestroyMixFileCreatorFileInfoStruct(MixFileCreator::FileInfoStruct* fileInfoStruct)
	{
		delete fileInfoStruct;
	}

	__declspec(dllexport) MixClass* __stdcall CreateMixClass()
	{
		return new MixClass();
	}

	__declspec(dllexport) void __stdcall DestroyMixClass(MixClass* mixClass)
	{
		delete mixClass;
	}

	__declspec(dllexport) DynamicVectorClass<MixFileFactoryClass::FileInfoStruct>* __stdcall CreateMixFileFactoryClassFileInfoStructDynamicVectorClass1()
	{
		return new DynamicVectorClass<MixFileFactoryClass::FileInfoStruct>();
	}

	__declspec(dllexport) DynamicVectorClass<MixFileFactoryClass::FileInfoStruct>* __stdcall CreateMixFileFactoryClassFileInfoStructDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<MixFileFactoryClass::FileInfoStruct>(size);
	}

	__declspec(dllexport) void __stdcall DestroyMixFileFactoryClassFileInfoStructDynamicVectorClass(DynamicVectorClass<MixFileFactoryClass::FileInfoStruct>* MixFileFactoryClassFileInfoStructDynamicVectorClass)
	{
		delete MixFileFactoryClassFileInfoStructDynamicVectorClass;
	}

	__declspec(dllexport) DynamicVectorClass<MixFileFactoryClass::AddInfoStruct>* __stdcall CreateMixFileFactoryClassAddInfoStructDynamicVectorClass1()
	{
		return new DynamicVectorClass<MixFileFactoryClass::AddInfoStruct>();
	}

	__declspec(dllexport) DynamicVectorClass<MixFileFactoryClass::AddInfoStruct>* __stdcall CreateMixFileFactoryClassAddInfoStructDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<MixFileFactoryClass::AddInfoStruct>(size);
	}

	__declspec(dllexport) void __stdcall DestroyMixFileFactoryClassAddInfoStructDynamicVectorClass(DynamicVectorClass<MixFileFactoryClass::AddInfoStruct>* MixFileFactoryClassAddInfoStructDynamicVectorClass)
	{
		delete MixFileFactoryClassAddInfoStructDynamicVectorClass;
	}

	__declspec(dllexport) DynamicVectorClass<MixFileCreator::FileInfoStruct>* __stdcall CreateMixFileCreatorFileInfoStructDynamicVectorClass1()
	{
		return new DynamicVectorClass<MixFileCreator::FileInfoStruct>();
	}

	__declspec(dllexport) DynamicVectorClass<MixFileCreator::FileInfoStruct>* __stdcall CreateMixFileCreatorFileInfoStructDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<MixFileCreator::FileInfoStruct>(size);
	}

	__declspec(dllexport) void __stdcall DestroyMixFileCreatorFileInfoStructDynamicVectorClass(DynamicVectorClass<MixFileCreator::FileInfoStruct>* MixFileCreatorFileInfoStructDynamicVectorClass)
	{
		delete MixFileCreatorFileInfoStructDynamicVectorClass;
	}

	__declspec(dllexport) WidgetUserClass* __stdcall CreateWidgetUserClass()
	{
		return new WidgetUserClass();
	}

	__declspec(dllexport) void __stdcall DestroyWidgetUserClass(WidgetUserClass* widgetUserClass)
	{
		delete widgetUserClass;
	}

	__declspec(dllexport) void __stdcall DestroyPhysicsSceneClassStatsStruct(::PhysicsSceneClass::StatsStruct* statsStruct)
	{
		delete statsStruct;
	}

	__declspec(dllexport) CompressedVisTableClass* __stdcall CreateCompressedVisTableClass()
	{
		return new CompressedVisTableClass();
	}

	__declspec(dllexport) void __stdcall DestroyCompressedVisTableClass(CompressedVisTableClass* compressedVisTableClass)
	{
		delete compressedVisTableClass;
	}

	__declspec(dllexport) SimpleVecClass<VisTableClass*>* __stdcall CreateVisTableClassPtrSimpleVecClass1()
	{
		return new SimpleVecClass<VisTableClass*>();
	}

	__declspec(dllexport) SimpleVecClass<VisTableClass*>* __stdcall CreateVisTableClassPtrSimpleVecClass2(int size)
	{
		return new SimpleVecClass<VisTableClass*>(size);
	}

	__declspec(dllexport) void __stdcall DestroyVisTableClassPtrSimpleVecClass(SimpleVecClass<VisTableClass*>* visTableClassPtrSimpleVecClass)
	{
		delete visTableClassPtrSimpleVecClass;
	}

	__declspec(dllexport) MultiListClass<VisTableClass>* __stdcall CreateVisTableClassMultiListClass()
	{
		return new MultiListClass<VisTableClass>();
	}

	__declspec(dllexport) void __stdcall DestroyVisTableClassMultiListClass(MultiListClass<VisTableClass>* VisTableClassMultiListClass)
	{
		delete VisTableClassMultiListClass;
	}

	__declspec(dllexport) MultiListIterator<VisTableClass>* __stdcall CreateVisTableClassMultiListIterator(MultiListClass<VisTableClass>* list)
	{
		return new MultiListIterator<VisTableClass>(list);
	}

	__declspec(dllexport) void __stdcall DestroyVisTableClassMultiListIterator(MultiListIterator<VisTableClass>* VisTableClassMultiListIterator)
	{
		delete VisTableClassMultiListIterator;
	}

	__declspec(dllexport) SimpleDynVecClass<CompressedVisTableClass*>* __stdcall CreateCompressedVisTableClassPtrSimpleDynVecClass1()
	{
		return new SimpleDynVecClass<CompressedVisTableClass*>();
	}

	__declspec(dllexport) SimpleDynVecClass<CompressedVisTableClass*>* __stdcall CreateCompressedVisTableClassPtrSimpleDynVecClass2(int size)
	{
		return new SimpleDynVecClass<CompressedVisTableClass*>(size);
	}

	__declspec(dllexport) void __stdcall DestroyCompressedVisTableClassPtrSimpleDynVecClass(SimpleDynVecClass<CompressedVisTableClass*>* CompressedVisTableClassPtrSimpleDynVecClass)
	{
		delete CompressedVisTableClassPtrSimpleDynVecClass;
	}

	__declspec(dllexport) VisDecompressionCacheClass* __stdcall CreateVisDecompressionCacheClass()
	{
		return new VisDecompressionCacheClass();
	}

	__declspec(dllexport) void __stdcall DestroyVisDecompressionCacheClass(VisDecompressionCacheClass* visDecompressionCacheClass)
	{
		delete visDecompressionCacheClass;
	}

	__declspec(dllexport) RefMultiListClass<RenderObjClass>* __stdcall CreateRenderObjClassRefMultiListClass()
	{
		return new RefMultiListClass<RenderObjClass>();
	}

	__declspec(dllexport) void __stdcall DestroyRenderObjClassRefMultiListClass(RefMultiListClass<RenderObjClass>* RenderObjClassRefMultiListClass)
	{
		delete RenderObjClassRefMultiListClass;
	}

	__declspec(dllexport) RefMultiListIterator<RenderObjClass>* __stdcall CreateRenderObjClassRefMultiListIterator(RefMultiListClass<RenderObjClass>* list)
	{
		return new RefMultiListIterator<RenderObjClass>(list);
	}

	__declspec(dllexport) void __stdcall DestroyRenderObjClassRefMultiListIterator(RefMultiListIterator<RenderObjClass>* RenderObjClassRefMultiListIterator)
	{
		delete RenderObjClassRefMultiListIterator;
	}

	__declspec(dllexport) MultiListClass<TexProjectClass>* __stdcall CreateTexProjectClassMultiListClass()
	{
		return new MultiListClass<TexProjectClass>();
	}

	__declspec(dllexport) void __stdcall DestroyTexProjectClassMultiListClass(MultiListClass<TexProjectClass>* TexProjectClassMultiListClass)
	{
		delete TexProjectClassMultiListClass;
	}

	__declspec(dllexport) MultiListIterator<TexProjectClass>* __stdcall CreateTexProjectClassMultiListIterator(MultiListClass<TexProjectClass>* list)
	{
		return new MultiListIterator<TexProjectClass>(list);
	}

	__declspec(dllexport) void __stdcall DestroyTexProjectClassMultiListIterator(MultiListIterator<TexProjectClass>* TexProjectClassMultiListIterator)
	{
		delete TexProjectClassMultiListIterator;
	}

	__declspec(dllexport) RefMultiListClass<PhysClass>* __stdcall CreatePhysClassRefMultiListClass()
	{
		return new RefMultiListClass<PhysClass>();
	}

	__declspec(dllexport) void __stdcall DestroyPhysClassRefMultiListClass(RefMultiListClass<PhysClass>* PhysClassRefMultiListClass)
	{
		delete PhysClassRefMultiListClass;
	}

	__declspec(dllexport) RefMultiListIterator<PhysClass>* __stdcall CreatePhysClassRefMultiListIterator(RefMultiListClass<PhysClass>* list)
	{
		return new RefMultiListIterator<PhysClass>(list);
	}

	__declspec(dllexport) void __stdcall DestroyPhysClassRefMultiListIterator(RefMultiListIterator<PhysClass>* PhysClassRefMultiListIterator)
	{
		delete PhysClassRefMultiListIterator;
	}

	__declspec(dllexport) CriticalSectionClass* __stdcall CreateCriticalSectionClass()
	{
		return new CriticalSectionClass();
	}

	__declspec(dllexport) void __stdcall DestroyCriticalSectionClass(CriticalSectionClass* criticalSectionClass)
	{
		delete criticalSectionClass;
	}

	__declspec(dllexport) FastCriticalSectionClass* __stdcall CreateFastCriticalSectionClass()
	{
		return new FastCriticalSectionClass();
	}

	__declspec(dllexport) void __stdcall DestroyFastCriticalSectionClass(FastCriticalSectionClass* fastCriticalSectionClass)
	{
		delete fastCriticalSectionClass;
	}

	__declspec(dllexport) FastCriticalSectionClass::LockClass* __stdcall CreateFastCriticalSectionClassLockClass(FastCriticalSectionClass* section)
	{
		return new FastCriticalSectionClass::LockClass(*section);
	}

	__declspec(dllexport) void __stdcall DestroyFastCriticalSectionClassLockClass(FastCriticalSectionClass::LockClass* lockClass)
	{
		delete lockClass;
	}

	__declspec(dllexport) DynamicVectorClass<Matrix3D>* __stdcall CreateMatrix3DDynamicVectorClass1()
	{
		return new DynamicVectorClass<Matrix3D>();
	}

	__declspec(dllexport) DynamicVectorClass<Matrix3D>* __stdcall CreateMatrix3DDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<Matrix3D>(size);
	}

	__declspec(dllexport) void __stdcall DestroyMatrix3DDynamicVectorClass(DynamicVectorClass<Matrix3D>* Matrix3DDynamicVectorClass)
	{
		delete Matrix3DDynamicVectorClass;
	}

	__declspec(dllexport) SysTimeClass* __stdcall CreateSysTimeClass()
	{
		return new SysTimeClass();
	}

	__declspec(dllexport) void __stdcall DestroySysTimeClass(SysTimeClass* sysTimeClass)
	{
		delete sysTimeClass;
	}

	__declspec(dllexport) DynamicVectorClass<TDBObjClass*>* __stdcall CreateTDBObjClassPtrDynamicVectorClass1()
	{
		return new DynamicVectorClass<TDBObjClass*>();
	}

	__declspec(dllexport) DynamicVectorClass<TDBObjClass*>* __stdcall CreateTDBObjClassPtrDynamicVectorClass2(int size)
	{
		return new DynamicVectorClass<TDBObjClass*>(size);
	}

	__declspec(dllexport) void __stdcall DestroyTDBObjClassPtrDynamicVectorClass(DynamicVectorClass<TDBObjClass*>* TDBObjClassPtrDynamicVectorClass)
	{
		delete TDBObjClassPtrDynamicVectorClass;
	}

	__declspec(dllexport) HashTemplateClass<StringClass, TDBObjClass*>* __stdcall CreateStringClassTDBObjClassPtrHashTemplateClass()
	{
		return new HashTemplateClass<StringClass, TDBObjClass*>();
	}

	__declspec(dllexport) void __stdcall DestroyStringClassTDBObjClassPtrHashTemplateClass(HashTemplateClass<StringClass, TDBObjClass*>* stringClassTDBObjClassPtrHashTemplateClass)
	{
		delete stringClassTDBObjClassPtrHashTemplateClass;
	}

	__declspec(dllexport) HashTemplateIterator<StringClass, TDBObjClass*>* __stdcall CreateStringClassTDBObjClassPtrHashTemplateIterator(HashTemplateClass<StringClass, TDBObjClass*>* table)
	{
		return new HashTemplateIterator<StringClass, TDBObjClass*>(*table);
	}

	__declspec(dllexport) void __stdcall DestroyStringClassTDBObjClassPtrHashTemplateIterator(HashTemplateIterator<StringClass, TDBObjClass*>* stringClassTDBObjClassPtrHashTemplateIterator)
	{
		delete stringClassTDBObjClassPtrHashTemplateIterator;
	}

	__declspec(dllexport) void __stdcall DestroyDefaultConnectionAcceptanceFilter(DefaultConnectionAcceptanceFilter* defaultConnectionAcceptanceFilter)
	{
		delete defaultConnectionAcceptanceFilter;
	}

	__declspec(dllexport) float __stdcall WWMathInvSqrt(float a)
	{
		return WWMath::Inv_Sqrt(a);
	}
}