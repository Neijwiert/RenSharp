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

#include "stdafx.h"
#include "MEngine.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4561 4091 4251 4244 26495 26454)
#include <engine_tt.h>
#include <engine_def.h>
#include <engine_dmg.h>
#include <engine_math.h>
#include <engine_obj2.h>
#include <engine_phys.h>
#include <engine_player.h>
#include <GameObjManager.h>
#include <cPlayer.h>
#include <engine_pt.h>
#include <engine_script.h>
#include <engine_tdb.h>
#include <engine_game.h>
#include <da_string.h>
#include <Crc32.h>
#include <ReferencerClass.h>
#include <MoveablePhysClass.h>
#include <w3d.h>
#include <da_ssgm.h>

RENEGADE_FUNCTION
::cTeam* Internal_Find_Team(int team)
AT2(0x0041DA10, 0x0041DA10);

RENEGADE_FUNCTION
void Internal_Create_Animation_Name(StringClass& target, const char* animation, const char* model)
AT2(0x006DB000, 0x006DA8A0);

::cTeam* Internal_Find_Team_Wrapper(int team)
{
	return Internal_Find_Team(team);
}

void Internal_Create_Animation_Name_Wrapper(StringClass& target, const char* animation, const char* model)
{
	Internal_Create_Animation_Name(target, animation, model);
}

#pragma warning(pop) 
#pragma managed(pop)

#include "Mengine_io.h"
#include "Mscripts.h"
#include "MScriptableGameObj.h"
#include "McPlayerSList.h"
#include "MStringClassGameDefinitionHashTemplateClass.h"
#include "McScTextObj.h"
#include "MSCAnnouncement.h"
#include "UnmanagedContainer.h"
#include "MInt32DynamicVectorClass.h"
#include "Mweaponmgr.h"
#include "FatalRenSharpException.h"
#include "MSmartGameObj.h"
#include "Mengine_tt.h"
#include "RenSharpConsoleFunctionClass.h"
#include "Mvector2.h"
#include "Mvector4.h"
#include "MConsoleFunctionClassPtrDynamicVectorClass.h"
#include "MDefinition.h"
#include "MMatrix3D.h"
#include "Mobboxclass.h"
#include "McPlayer.h"
#include "Mda_event.h"
#include "MDamageableGameObjDef.h"
#include "MWeaponBagClass.h"
#include "MWeaponClass.h"
#include "Mweaponmgr.h"
#include "MBeaconGameObj.h"
#include "McTeam.h"
#include "MBuildingGameObj.h"
#include "MVehicleGameObj.h"
#include "MSoldierGameObj.h"
#include "MSoldierGameObjDef.h"
#include "MPowerUpGameObjDef.h"
#include "MGameData.h"
#include "Mda_game.h"
#include "Mda_player.h"
#include "Mda_cratemanager.h"
#include "Mda_nodemanager.h"
#include "MBeaconGameObjDef.h"
#include "MPlayerDataClass.h"
#include "MPersist.h"
#include "MC4GameObj.h"
#include "MRenderObjClass.h"
#include "RenegadeDispatcher.h"
#include "McPlayerKill.h"
#include "McPurchaseResponseEvent.h"
#include "MC4GameObjDef.h"

using namespace System::Collections::Generic;
using namespace System::Runtime::InteropServices;

constexpr int ConsoleOutputBufferSize = 256;
constexpr std::int64_t InitialDispatcherQueueSize = 512;

namespace RenSharp
{
	static Engine::Engine()
	{
		shutdown = false;

		managedConsoleFunctions = gcnew Generic::Dictionary<IntPtr, IRenSharpConsoleFunctionClass^>();

		currentPathfindDistanceRequestId = 1;
		pathfindDistanceRequests = gcnew Generic::Dictionary<uint32, PathfindDistanceRequest ^>();
		internalPathfindCallbackDelegate = gcnew InternalPathfindDistanceDelegate(InternalPathfindDistanceCallback);

		surfaceTypeStrings = gcnew array<String^>(sizeof(::SURFACE_TYPE_STRINGS) / sizeof(::SURFACE_TYPE_STRINGS[0]));
		for (int x = 0; x < surfaceTypeStrings->Length; x++)
		{
			auto currentString = ::SURFACE_TYPE_STRINGS[x];
			if (currentString != nullptr)
			{
				surfaceTypeStrings[x] = gcnew String(currentString);
			}
		}

		dispatchers = gcnew Generic::Dictionary<Threading::Thread^, RenegadeDispatcher^>();
	}

	bool Engine::Init()
	{
		renegadeThread = Threading::Thread::CurrentThread;

		return true;
	}

	void Engine::Shutdown()
	{
		if (shutdown)
		{
			return;
		}

		shutdown = true;

		// Ensure everything gets disposed properly
		auto tmpPathfindDistanceRequests = gcnew Generic::Dictionary<uint32, PathfindDistanceRequest^>(pathfindDistanceRequests);
		pathfindDistanceRequests->Clear();
		for each (auto pair in tmpPathfindDistanceRequests)
		{
			::Cancel_Get_Pathfind_Distance(pair.Value->UnmanagedId);
		}

		tmpPathfindDistanceRequests->Clear();

		auto tmpManagedConsoleFunctions = gcnew Generic::Dictionary<IntPtr, IRenSharpConsoleFunctionClass^>(managedConsoleFunctions);
		managedConsoleFunctions->Clear();

		for each (auto consoleFunction in tmpManagedConsoleFunctions->Values)
		{
			if (consoleFunction->Name != nullptr)
			{
				DeleteConsoleFunction(consoleFunction->Name);
			}

			if (consoleFunction->Alias != nullptr)
			{
				DeleteConsoleFunction(consoleFunction->Alias);
			}

#pragma push_macro("delete")
#undef delete

			delete consoleFunction;
			consoleFunction = nullptr;

#pragma pop_macro("delete")
		}

		tmpManagedConsoleFunctions->Clear();

		::Sort_Function_List();
		::Verbose_Help_File();

		ScriptableGameObj::Shutdown();
		DAPlayerClass::Shutdown();
		DAPlayerManager::Shutdown();
		DAEventManager::Shutdown();
		DAGameManager::Shutdown();
		DACrateManager::Shutdown();
		DANodeManagerClass::Shutdown();
	}

	void Engine::Think()
	{
		ScriptableGameObj::RenSharpThink();
	}

	void Engine::OnManagedConsoleFunctionDestructed(IntPtr function)
	{
		IRenSharpConsoleFunctionClass^ managedConsoleFunction = AsManagedConsoleFunction(function);
		if (managedConsoleFunction != nullptr && managedConsoleFunction->IsAttached)
		{
			managedConsoleFunction->DestroyPointer = false;

#pragma push_macro("delete")
#undef delete

			delete managedConsoleFunction;
			managedConsoleFunction = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool Engine::IsManagedConsoleFunction(IntPtr function)
	{
		return managedConsoleFunctions->ContainsKey(function);
	}

	bool Engine::IsManagedConsoleFunction(IConsoleFunctionClass ^function)
	{
		if (function == nullptr || function->ConsoleFunctionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("function");
		}

		return IsManagedConsoleFunction(function->ConsoleFunctionClassPointer);
	}

	IRenSharpConsoleFunctionClass^ Engine::AsManagedConsoleFunction(IntPtr function)
	{
		IRenSharpConsoleFunctionClass^ result = nullptr;
		managedConsoleFunctions->TryGetValue(function, result);

		return result;
	}

	IRenSharpConsoleFunctionClass^ Engine::AsManagedConsoleFunction(IConsoleFunctionClass ^function)
	{
		if (function == nullptr || function->ConsoleFunctionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("function");
		}

		return AsManagedConsoleFunction(function->ConsoleFunctionClassPointer);
	}

#pragma managed(push, off)

	struct BeaconGameObjWeaponDef
	{
		typedef const ::WeaponDefinitionClass* (::BeaconGameObj::* type);
		friend type StealValue(BeaconGameObjWeaponDef);
	};

	template struct Rob<BeaconGameObjWeaponDef, &::BeaconGameObj::WeaponDef>;

	struct BeaconGameObjPlayer
	{
		typedef ::PlayerDataClass* (::BeaconGameObj::* type);
		friend type StealValue(BeaconGameObjPlayer);
	};

	template struct Rob<BeaconGameObjPlayer, &::BeaconGameObj::Player>;

	struct BeaconGameObjArmTime
	{
		typedef float (::BeaconGameObj::* type);
		friend type StealValue(BeaconGameObjArmTime);
	};

	template struct Rob<BeaconGameObjArmTime, &::BeaconGameObj::ArmTime>;

	struct BeaconGameObjState
	{
		typedef int(::BeaconGameObj::* type);
		friend type StealValue(BeaconGameObjState);
	};

	template struct Rob<BeaconGameObjState, & ::BeaconGameObj::State>;

	struct BeaconGameObjOwner
	{
		typedef ReferencerClass (::BeaconGameObj::* type);
		friend type StealValue(BeaconGameObjOwner);
	};

	template struct Rob<BeaconGameObjOwner, &::BeaconGameObj::Owner>;

	struct BeaconGameObjDetonateTime
	{
		typedef float(::BeaconGameObj::* type);
		friend type StealValue(BeaconGameObjDetonateTime);
	};

	template struct Rob<BeaconGameObjDetonateTime, & ::BeaconGameObj::DetonateTime>;

#pragma managed(pop)

	void Engine::SetBeaconOwner(IBeaconGameObj^ beacon, ISoldierGameObj^ owner)
	{
		if (beacon == nullptr || beacon->BeaconGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("beacon");
		}

		::SoldierGameObj* ownerPtr;
		if (owner == nullptr || owner->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			ownerPtr = nullptr;
		}
		else
		{
			ownerPtr = reinterpret_cast<::SoldierGameObj*>(owner->SoldierGameObjPointer.ToPointer());
		}

		::BeaconGameObj* beaconPtr = reinterpret_cast<::BeaconGameObj*>(beacon->BeaconGameObjPointer.ToPointer());

		auto& bPlayer = (*beaconPtr).*StealValue(BeaconGameObjPlayer());
		auto& bOwner = (*beaconPtr).*StealValue(BeaconGameObjOwner());

		if (ownerPtr == nullptr)
		{
			beaconPtr->Set_Player_Type(beaconPtr->Get_Definition().DefaultPlayerType);
			bPlayer = nullptr;
			bOwner = nullptr;
		}
		else
		{
			beaconPtr->Set_Player_Type(ownerPtr->Get_Player_Type());
			bPlayer = ownerPtr->Get_Player_Data();
			bOwner = ownerPtr;
		}

		beaconPtr->Set_Object_Dirty_Bit(::NetworkObjectClass::BIT_RARE, true);
	}

	void Engine::SetBeaconDetonateTime(IBeaconGameObj^ beacon, float detonateTime)
	{
		if (beacon == nullptr || beacon->BeaconGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("beacon");
		}

		::BeaconGameObj* beaconPtr = reinterpret_cast<::BeaconGameObj*>(beacon->BeaconGameObjPointer.ToPointer());

		auto& bArmTime = (*beaconPtr).*StealValue(BeaconGameObjDetonateTime());

		bArmTime = detonateTime;
	}

	IBeaconGameObj^ Engine::CreateBeacon(IWeaponDefinitionClass^ weaponDef, Matrix3D transform, IPlayerDataClass^ playerData, bool usePrimaryAmmo)
	{
		if (weaponDef == nullptr || weaponDef->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("weaponDef");
		}

		int ammoDefId;
		if (usePrimaryAmmo)
		{
			ammoDefId = weaponDef->PrimaryAmmoDefID;
		}
		else
		{
			ammoDefId = weaponDef->SecondaryAmmoDefID;
		}

		::AmmoDefinitionClass* ammoDefPtr = static_cast<::AmmoDefinitionClass*>(::DefinitionMgrClass::Find_Definition(ammoDefId, false));
		if (ammoDefPtr == nullptr || ammoDefPtr->Get_Class_ID() != IAmmoDefinitionClass::AmmoDefinitionClassClassID)
		{
			return nullptr;
		}

		::BeaconGameObjDef* beaconDefPtr = static_cast<::BeaconGameObjDef*>(::DefinitionMgrClass::Find_Definition(ammoDefPtr->BeaconDefID, false));
		if (beaconDefPtr == nullptr || beaconDefPtr->Get_Class_ID() != IBeaconGameObjDef::BeaconGameObjDefClassID)
		{
			return nullptr;
		}

		::BaseGameObj* baseObj = static_cast<::BaseGameObj*>(beaconDefPtr->Create());
		if (baseObj == nullptr)
		{
			return nullptr;
		}

		::PhysicalGameObj *physicalObj = baseObj->As_PhysicalGameObj();
		if (physicalObj == nullptr)
		{
			baseObj->Set_Delete_Pending();

			return nullptr;
		}

		::BeaconGameObj* beaconObj = physicalObj->As_BeaconGameObj();
		if (beaconObj == nullptr)
		{
			beaconObj->Set_Delete_Pending();

			return nullptr;
		}

		::Matrix3D mat;
		Matrix3D::ManagedToUnmanagedMatrix3D(transform, mat);
		beaconObj->Set_Transform(mat);

		auto& bWeaponDef = (*beaconObj).*StealValue(BeaconGameObjWeaponDef());
		auto& bPlayer = (*beaconObj).*StealValue(BeaconGameObjPlayer());
		auto& bArmTime = (*beaconObj).*StealValue(BeaconGameObjArmTime());
		auto& bState = (*beaconObj).*StealValue(BeaconGameObjState());
		auto& bOwner = (*beaconObj).*StealValue(BeaconGameObjOwner());

		bWeaponDef = reinterpret_cast<::WeaponDefinitionClass*>(weaponDef->WeaponDefinitionClassPointer.ToPointer());
		bPlayer = (playerData == nullptr || playerData->PlayerDataClassPointer.ToPointer() == nullptr ? nullptr : reinterpret_cast<::PlayerDataClass*>(playerData->PlayerDataClassPointer.ToPointer()));
		bArmTime = 0.0f;
		bState = static_cast<int>(BeaconGameObj::BeaconState::StateDeploying);

		if (bPlayer != nullptr)
		{
			for (auto it = ::GameObjManager::StarGameObjList.Head(); it != nullptr; it = it->Next())
			{
				::SoldierGameObj* star = it->Data();
				if (star != nullptr && star->Get_Player_Data() == bPlayer)
				{
					beaconObj->Set_Player_Type(star->Get_Player_Type());
					bOwner = star;

					break;
				}
			}
		}

		beaconObj->Set_Object_Dirty_Bit(::NetworkObjectClass::BIT_RARE, true);

		beaconObj->Think(); // Force state update

		// Start observers
		beaconObj->Post_Re_Init();

		return safe_cast<IBeaconGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(beaconObj));
	}

	IBeaconGameObj^ Engine::CreateBeacon(IWeaponDefinitionClass^ weaponDef, Vector3 position, IPlayerDataClass^ playerData, bool usePrimaryAmmo)
	{
		Matrix3D transform(true);
		transform.Translation = position;

		return CreateBeacon(weaponDef, transform, playerData, usePrimaryAmmo);
	}

	IBeaconGameObj^ Engine::CreateBeacon(String^ weaponPresetName, Matrix3D transform, IPlayerDataClass^ playerData, bool usePrimaryAmmo)
	{
		if (weaponPresetName == nullptr)
		{
			throw gcnew ArgumentNullException("weaponPresetName");
		}

		IntPtr weaponPresetNameHandle = Marshal::StringToHGlobalAnsi(weaponPresetName);
		try
		{
			::WeaponDefinitionClass* weaponDefPtr = static_cast<::WeaponDefinitionClass*>(::DefinitionMgrClass::Find_Named_Definition(
				reinterpret_cast<char*>(weaponPresetNameHandle.ToPointer()),
				false));
			if (weaponDefPtr == nullptr)
			{
				return nullptr;
			}
			else
			{
				return CreateBeacon(safe_cast<IWeaponDefinitionClass^>(DefinitionClass::CreateDefinitionClassWrapper(weaponDefPtr)), transform, playerData, usePrimaryAmmo);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(weaponPresetNameHandle);
		}
	}

	IBeaconGameObj^ Engine::CreateBeacon(String^ weaponPresetName, Vector3 position, IPlayerDataClass^ playerData, bool usePrimaryAmmo)
	{
		Matrix3D transform(true);
		transform.Translation = position;

		return CreateBeacon(weaponPresetName, transform, playerData, usePrimaryAmmo);
	}

#pragma managed(push, off)

	struct C4GameObjDetonationMode
	{
		typedef int(::C4GameObj::* type);
		friend type StealValue(C4GameObjDetonationMode);
	};

	template struct Rob<C4GameObjDetonationMode, &::C4GameObj::DetonationMode>;

	struct C4GameObjAttached
	{
		typedef bool(::C4GameObj::* type);
		friend type StealValue(C4GameObjAttached);
	};

	template struct Rob<C4GameObjAttached, &::C4GameObj::attached>;

	struct C4GameObjAmmoDef
	{
		typedef const ::AmmoDefinitionClass* (::C4GameObj::* type);
		friend type StealValue(C4GameObjAmmoDef);
	};

	template struct Rob<C4GameObjAmmoDef, &::C4GameObj::AmmoDef>;

	struct C4GameObjPlayer
	{
		typedef ::PlayerDataClass* (::C4GameObj::* type);
		friend type StealValue(C4GameObjPlayer);
	};

	template struct Rob<C4GameObjPlayer, &::C4GameObj::Player>;

	struct C4GameObjAttachObject
	{
		typedef ::ReferencerClass (::C4GameObj::* type);
		friend type StealValue(C4GameObjAttachObject);
	};

	template struct Rob<C4GameObjAttachObject, &::C4GameObj::attachObject>;

	struct C4GameObjAttachLocation
	{
		typedef ::Vector3 (::C4GameObj::* type);
		friend type StealValue(C4GameObjAttachLocation);
	};

	template struct Rob<C4GameObjAttachLocation, &::C4GameObj::AttachLocation>;

	struct C4GameObjAttachBoneIndex
	{
		typedef int(::C4GameObj::* type);
		friend type StealValue(C4GameObjAttachBoneIndex);
	};

	template struct Rob<C4GameObjAttachBoneIndex, &::C4GameObj::AttachBoneIndex>;

	struct C4GameObjIsAttachedToMCT
	{
		typedef bool(::C4GameObj::* type);
		friend type StealValue(C4GameObjIsAttachedToMCT);
	};

	template struct Rob<C4GameObjIsAttachedToMCT, &::C4GameObj::IsAttachedToMCT>;

	struct C4GameObjAttachedToDynamic
	{
		typedef bool(::C4GameObj::* type);
		friend type StealValue(C4GameObjAttachedToDynamic);
	};

	template struct Rob<C4GameObjAttachedToDynamic, &::C4GameObj::attachedToDynamic>;

	struct C4GameObjTriggerTime
	{
		typedef float(::C4GameObj::* type);
		friend type StealValue(C4GameObjTriggerTime);
	};

	template struct Rob<C4GameObjTriggerTime, &::C4GameObj::TriggerTime>;

	struct C4GameObjOwner
	{
		typedef ReferencerClass (::C4GameObj::* type);
		friend type get(C4GameObjOwner);
	};

	template struct Rob<C4GameObjOwner, &::C4GameObj::Owner>;

#pragma managed(pop)

	void Engine::SetC4Owner(IC4GameObj^ c4, ISoldierGameObj^ owner)
	{
		if (c4 == nullptr || c4->C4GameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("c4");
		}

		::SoldierGameObj* ownerPtr;
		if (owner == nullptr || owner->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			ownerPtr = nullptr;
		}
		else
		{
			ownerPtr = reinterpret_cast<::SoldierGameObj*>(owner->SoldierGameObjPointer.ToPointer());
		}

		::C4GameObj* c4Ptr = reinterpret_cast<::C4GameObj*>(c4->C4GameObjPointer.ToPointer());

		auto& c4Player = (*c4Ptr).*StealValue(C4GameObjPlayer());
		auto& c4Owner = (*c4Ptr).*StealValue(C4GameObjOwner());

		if (ownerPtr == nullptr)
		{
			c4Ptr->Set_Player_Type(c4Ptr->Get_Definition().DefaultPlayerType);
			c4Player = nullptr;
			c4Owner = nullptr;
		}
		else
		{
			c4Ptr->Set_Player_Type(ownerPtr->Get_Player_Type());
			c4Player = ownerPtr->Get_Player_Data();
			c4Owner = ownerPtr;
		}

		c4Ptr->Set_Object_Dirty_Bit(::NetworkObjectClass::BIT_RARE, true);
	}

	void Engine::SetC4TriggerTime(IC4GameObj^ c4, float triggerTime)
	{
		if (c4 == nullptr || c4->C4GameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("c4");
		}

		::C4GameObj* c4Ptr = reinterpret_cast<::C4GameObj*>(c4->C4GameObjPointer.ToPointer());
		if (c4Ptr->Get_Ammo_Def()->AmmoType == ::AmmoDefinitionClass::AMMO_TYPE_C4_REMOTE)
		{
			return;
		}

		auto& c4TriggerTime = (*c4Ptr).*StealValue(C4GameObjTriggerTime());

		c4TriggerTime = triggerTime;
	}

	void Engine::SetC4AttachedToMCT(IC4GameObj^ c4, bool isAttachedToMCT)
	{
		if (c4 == nullptr || c4->C4GameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("c4");
		}

		::C4GameObj* c4Ptr = reinterpret_cast<::C4GameObj*>(c4->C4GameObjPointer.ToPointer());
		if (c4Ptr->Get_Ammo_Def()->AmmoType != ::AmmoDefinitionClass::AMMO_TYPE_C4_TIMED)
		{
			return;
		}

		auto& c4IsAttachedToMCT = (*c4Ptr).*StealValue(C4GameObjIsAttachedToMCT());

		c4IsAttachedToMCT = isAttachedToMCT;

		c4Ptr->Set_Object_Dirty_Bit(::NetworkObjectClass::BIT_RARE, true);
	}

	IC4GameObj^ Engine::CreateC4(IAmmoDefinitionClass^ ammoDef, Matrix3D transform, Vector3 velocity, IPlayerDataClass^ playerData, int detonationMode)
	{
		if (ammoDef == nullptr || ammoDef->AmmoDefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("ammoDef");
		}
		else if (detonationMode < 1 || detonationMode > 3)
		{
			throw gcnew ArgumentOutOfRangeException("detonationMode");
		}

		int c4PresetId = ammoDef->C4Preset;
		if (c4PresetId <= 0)
		{
			c4PresetId = ::Get_Definition_ID("Tossed C4");
		}

		::C4GameObjDef* c4ObjDefPtr = static_cast<::C4GameObjDef*>(::DefinitionMgrClass::Find_Definition(c4PresetId, false));
		if (c4ObjDefPtr == nullptr || c4ObjDefPtr->Get_Class_ID() != IC4GameObjDef::C4GameObjDefClassID)
		{
			return nullptr;
		}

		::BaseGameObj* baseObj = static_cast<::BaseGameObj*>(c4ObjDefPtr->Create());
		if (baseObj == nullptr)
		{
			return nullptr;
		}

		::PhysicalGameObj* physicalObj = baseObj->As_PhysicalGameObj();
		if (physicalObj == nullptr)
		{
			baseObj->Set_Delete_Pending();

			return nullptr;
		}

		::C4GameObj* c4Obj = physicalObj->As_C4GameObj();
		if (c4Obj == nullptr)
		{
			baseObj->Set_Delete_Pending();

			return nullptr;
		}

		::Matrix3D mat;
		Matrix3D::ManagedToUnmanagedMatrix3D(transform, mat);
		c4Obj->Set_Transform(mat);

		::AmmoDefinitionClass* ammoDefPtr = reinterpret_cast<::AmmoDefinitionClass*>(ammoDef->AmmoDefinitionClassPointer.ToPointer());
		::PhysClass* physObj = c4Obj->Peek_Physical_Object();

		if (!ammoDefPtr->ModelName.Is_Empty())
		{
			::Commands->Set_Model(c4Obj, ammoDefPtr->ModelName.Peek_Buffer());

			if (ammoDefPtr->C4Animation)
			{
				::StringClass animName;
				Internal_Create_Animation_Name_Wrapper(animName, ammoDefPtr->ModelName.Peek_Buffer(), ammoDefPtr->ModelName.Peek_Buffer());
				if (!animName.Is_Empty())
				{
					::Commands->Set_Animation(c4Obj, animName.Peek_Buffer(), true, nullptr, 0.0f, -1.0f, false);
				}
			}
		}

		auto& c4AmmoDef = (*c4Obj).*StealValue(C4GameObjAmmoDef());
		auto& c4DetonationMode = (*c4Obj).*StealValue(C4GameObjDetonationMode());
		auto& c4Player = (*c4Obj).*StealValue(C4GameObjPlayer());
		auto& c4TriggerTime = (*c4Obj).*StealValue(C4GameObjTriggerTime());
		auto& c4Owner = (*c4Obj).*StealValue(C4GameObjOwner());

		auto& c4Attached = (*c4Obj).*StealValue(C4GameObjAttached());
		auto& c4AttachObject = (*c4Obj).*StealValue(C4GameObjAttachObject());
		auto& c4AttachLocation = (*c4Obj).*StealValue(C4GameObjAttachLocation());
		auto& c4AttachBoneIndex = (*c4Obj).*StealValue(C4GameObjAttachBoneIndex());
		auto& c4IsAttachedToMCT = (*c4Obj).*StealValue(C4GameObjIsAttachedToMCT());
		auto& c4AttachedToDynamic = (*c4Obj).*StealValue(C4GameObjAttachedToDynamic());

		c4AmmoDef = ammoDefPtr;
		c4DetonationMode = detonationMode;
		c4Player = (playerData == nullptr || playerData->PlayerDataClassPointer.ToPointer() == nullptr ? nullptr : reinterpret_cast<::PlayerDataClass*>(playerData->PlayerDataClassPointer.ToPointer()));

		if (ammoDef->AmmoType != ::AmmoDefinitionClass::AMMO_TYPE_C4_REMOTE)
		{
			switch (detonationMode)
			{
				case 2:
					c4TriggerTime = ammoDef->C4TriggerTime2;
					break;
				case 3:
					c4TriggerTime = ammoDef->C4TriggerTime3;
					break;
				default:
					c4TriggerTime = ammoDef->C4TriggerTime1;
					break;
			}
		}

		c4Attached = false;
		c4AttachObject = nullptr;
		c4AttachLocation = ::Vector3();
		c4AttachBoneIndex = 0;
		c4IsAttachedToMCT = false;
		c4AttachedToDynamic = false;

		::PhysClass* physC4Obj = c4Obj->Peek_Physical_Object();
		physC4Obj->Set_Collision_Group(::Collision_Group_Type::C4_COLLISION_GROUP);

		if (c4Player != nullptr)
		{
			for (auto it = ::GameObjManager::StarGameObjList.Head(); it != nullptr; it = it->Next())
			{
				::SoldierGameObj* star = it->Data();
				if (star != nullptr && star->Get_Player_Data() == c4Player)
				{
					c4Obj->Set_Player_Type(star->Get_Player_Type());
					c4Owner = star;

					break;
				}
			}
		}

		if (ammoDefPtr->C4TimingSound1ID != 0)
		{
			const char* c4TimingSound1Name = ::Get_Definition_Name(ammoDefPtr->C4TimingSound1ID);
			if (c4TimingSound1Name != nullptr)
			{
				::Commands->Create_Sound(c4TimingSound1Name, mat.Get_Translation(), c4Owner.Get_Ptr());
			}
		}

		if (physC4Obj->As_ProjectileClass() != nullptr)
		{
			::Vector3 tmp;
			Vector3::ManagedToUnmanagedVector3(velocity, tmp);
			physC4Obj->As_MoveablePhysClass()->Set_Velocity(tmp);
		}

		c4Obj->Set_Object_Dirty_Bit(::NetworkObjectClass::BIT_RARE, true);

		// Start observers
		c4Obj->Post_Re_Init();

		return safe_cast<IC4GameObj^>(BaseGameObj::CreateBaseGameObjWrapper(c4Obj));
	}

	IC4GameObj^ Engine::CreateC4(String^ ammoPresetName, Matrix3D transform, Vector3 velocity, IPlayerDataClass^ playerData, int detonationMode)
	{
		if (ammoPresetName == nullptr)
		{
			throw gcnew ArgumentNullException("ammoPresetName");
		}

		IntPtr ammoPresetNameHandle = Marshal::StringToHGlobalAnsi(ammoPresetName);
		try
		{
			::AmmoDefinitionClass* ammoDefPtr = static_cast<::AmmoDefinitionClass*>(::DefinitionMgrClass::Find_Named_Definition(
				reinterpret_cast<char*>(ammoPresetNameHandle.ToPointer()),
				false));
			if (ammoDefPtr == nullptr)
			{
				return nullptr;
			}
			else
			{
				return CreateC4(safe_cast<IAmmoDefinitionClass^>(DefinitionClass::CreateDefinitionClassWrapper(ammoDefPtr)), transform, velocity, playerData, detonationMode);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(ammoPresetNameHandle);
		}
	}

	IC4GameObj^ Engine::CreateC4(IAmmoDefinitionClass^ ammoDef, Vector3 position, Vector3 velocity, IPlayerDataClass^ playerData, int detonationMode)
	{
		Matrix3D transform(true);
		transform.Translation = position;

		return CreateC4(ammoDef, transform, velocity, playerData, detonationMode);
	}

	IC4GameObj^ Engine::CreateC4(String^ ammoPresetName, Vector3 position, Vector3 velocity, IPlayerDataClass^ playerData, int detonationMode)
	{
		Matrix3D transform(true);
		transform.Translation = position;

		return CreateC4(ammoPresetName, transform, velocity, playerData, detonationMode);
	}

	IC4GameObj^ Engine::CreateC4(IAmmoDefinitionClass^ ammoDef, Matrix3D transform, IPlayerDataClass^ playerData, int detonationMode)
	{
		IC4GameObj^ c4Obj = CreateC4(ammoDef, transform, Vector3(0.0f, 0.0f, 0.0f), playerData, detonationMode);
		if (c4Obj == nullptr)
		{
			return nullptr;
		}

		::C4GameObj* c4ObjPtr = reinterpret_cast<::C4GameObj*>(c4Obj->C4GameObjPointer.ToPointer());

		auto& c4Attached = (*c4ObjPtr).*StealValue(C4GameObjAttached());

		c4Attached = true;

		c4ObjPtr->Peek_Physical_Object()->Enable_User_Control(true);
		c4ObjPtr->Set_Object_Dirty_Bit(::NetworkObjectClass::BIT_RARE, true);

		return c4Obj;
	}

	IC4GameObj^ Engine::CreateC4(String^ ammoPresetName, Matrix3D transform, IPlayerDataClass^ playerData, int detonationMode)
	{
		if (ammoPresetName == nullptr)
		{
			throw gcnew ArgumentNullException("ammoPresetName");
		}

		IntPtr ammoPresetNameHandle = Marshal::StringToHGlobalAnsi(ammoPresetName);
		try
		{
			::AmmoDefinitionClass* ammoDefPtr = static_cast<::AmmoDefinitionClass*>(::DefinitionMgrClass::Find_Named_Definition(
				reinterpret_cast<char*>(ammoPresetNameHandle.ToPointer()),
				false));
			if (ammoDefPtr == nullptr)
			{
				return nullptr;
			}
			else
			{
				return CreateC4(safe_cast<IAmmoDefinitionClass^>(DefinitionClass::CreateDefinitionClassWrapper(ammoDefPtr)), transform, playerData, detonationMode);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(ammoPresetNameHandle);
		}
	}

	IC4GameObj^ Engine::CreateC4(IAmmoDefinitionClass^ ammoDef, Vector3 position, IPlayerDataClass^ playerData, int detonationMode)
	{
		Matrix3D transform(true);
		transform.Translation = position;

		return CreateC4(ammoDef, transform, playerData, detonationMode);
	}

	IC4GameObj^ Engine::CreateC4(String^ ammoPresetName, Vector3 position, IPlayerDataClass^ playerData, int detonationMode)
	{
		Matrix3D transform(true);
		transform.Translation = position;

		return CreateC4(ammoPresetName, transform, playerData, detonationMode);
	}

	IC4GameObj^ Engine::CreateC4(IAmmoDefinitionClass^ ammoDef, Matrix3D transform, IBuildingGameObj^ attachToObj, bool isAttachedToMCT, IPlayerDataClass^ playerData, int detonationMode)
	{
		if (attachToObj == nullptr || attachToObj->BuildingGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("attachToObj");
		}

		IC4GameObj^ c4Obj = CreateC4(ammoDef, transform, Vector3(0.0f, 0.0f, 0.0f), playerData, detonationMode);
		if (c4Obj == nullptr)
		{
			return nullptr;
		}

		::C4GameObj* c4ObjPtr = reinterpret_cast<::C4GameObj*>(c4Obj->C4GameObjPointer.ToPointer());

		auto& c4Attached = (*c4ObjPtr).*StealValue(C4GameObjAttached());
		auto& c4AttachObject = (*c4ObjPtr).*StealValue(C4GameObjAttachObject());
		auto& c4IsAttachedToMCT = (*c4ObjPtr).*StealValue(C4GameObjIsAttachedToMCT());
		auto& c4AttachLocation = (*c4ObjPtr).*StealValue(C4GameObjAttachLocation());

		c4Attached = true;
		c4AttachObject = reinterpret_cast<::BuildingGameObj*>(attachToObj->BuildingGameObjPointer.ToPointer());
		c4IsAttachedToMCT = isAttachedToMCT;
		Vector3::ManagedToUnmanagedVector3(transform.Translation, c4AttachLocation);

		c4ObjPtr->Peek_Physical_Object()->Enable_User_Control(true);

		c4ObjPtr->Set_Object_Dirty_Bit(::NetworkObjectClass::BIT_RARE, true);

		return c4Obj;
	}

	IC4GameObj^ Engine::CreateC4(IAmmoDefinitionClass^ ammoDef, Vector3 position, IBuildingGameObj^ attachToObj, bool isAttachedToMCT, IPlayerDataClass^ playerData, int detonationMode)
	{
		Matrix3D transform(true);
		transform.Translation = position;

		return CreateC4(ammoDef, transform, attachToObj, isAttachedToMCT, playerData, detonationMode);
	}

	IC4GameObj^ Engine::CreateC4(String^ ammoPresetName, Matrix3D transform, IBuildingGameObj^ attachToObj, bool isAttachedToMCT, IPlayerDataClass^ playerData, int detonationMode)
	{
		if (ammoPresetName == nullptr)
		{
			throw gcnew ArgumentNullException("ammoPresetName");
		}

		IntPtr ammoPresetNameHandle = Marshal::StringToHGlobalAnsi(ammoPresetName);
		try
		{
			::AmmoDefinitionClass* ammoDefPtr = static_cast<::AmmoDefinitionClass*>(::DefinitionMgrClass::Find_Named_Definition(
				reinterpret_cast<char*>(ammoPresetNameHandle.ToPointer()),
				false));
			if (ammoDefPtr == nullptr)
			{
				return nullptr;
			}
			else
			{
				return CreateC4(safe_cast<IAmmoDefinitionClass^>(DefinitionClass::CreateDefinitionClassWrapper(ammoDefPtr)), transform, attachToObj, isAttachedToMCT, playerData, detonationMode);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(ammoPresetNameHandle);
		}
	}

	IC4GameObj^ Engine::CreateC4(String^ ammoPresetName, Vector3 position, IBuildingGameObj^ attachToObj, bool isAttachedToMCT, IPlayerDataClass^ playerData, int detonationMode)
	{
		Matrix3D transform(true);
		transform.Translation = position;

		return CreateC4(ammoPresetName, transform, attachToObj, isAttachedToMCT, playerData, detonationMode);
	}

	void Engine::ConsoleInput(String ^input, ...array<Object ^> ^args)
	{
		if (input == nullptr)
		{
			throw gcnew ArgumentNullException(L"input");
		}

		String ^result = String::Format(input, args);

		IntPtr resultHandle = Marshal::StringToHGlobalAnsi(result);
		try
		{
			::Console_Input(reinterpret_cast<char *>(resultHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(resultHandle);
		}
	}

	void Engine::ConsoleOutput(String ^output, ...array<Object ^> ^args)
	{
		if (output == nullptr)
		{
			throw gcnew ArgumentNullException(L"output");
		}

		String ^result = String::Format(output, args);

		Generic::ICollection<String ^> ^resultChunks = gcnew LinkedList<String ^>();
		for (int index = 0; index < result->Length; index += ConsoleOutputBufferSize)
		{
			if (index + ConsoleOutputBufferSize > result->Length)
			{
				resultChunks->Add(result->Substring(index));
			}
			else
			{
				resultChunks->Add(result->Substring(index, ConsoleOutputBufferSize));
			}
		}

		for each(String ^chunk in resultChunks)
		{
			IntPtr chunkPtr = Marshal::StringToHGlobalAnsi(chunk);
			try
			{
				::Console_Output(reinterpret_cast<const char *>(chunkPtr.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(chunkPtr);
			}
		}
	}

	IFileClass ^Engine::GetDataFile(String ^filename)
	{
		if (filename == nullptr)
		{
			throw gcnew ArgumentNullException("filename");
		}

		IntPtr filenameHandle = Marshal::StringToHGlobalAnsi(filename);
		try
		{
			::FileClass *result = ::Get_Data_File(reinterpret_cast<char *>(filenameHandle.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew FileClass(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(filenameHandle);
		}
	}

	void Engine::CloseDataFile(IFileClass ^file)
	{
		if (file == nullptr || file->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("file");
		}

		::Close_Data_File(reinterpret_cast<::FileClass *>(file->FileClassPointer.ToPointer()));
	}

	IINIClass ^Engine::GetINI(String ^filename)
	{
		if (filename == nullptr)
		{
			throw gcnew ArgumentNullException("filename");
		}

		IntPtr filenameHandle = Marshal::StringToHGlobalAnsi(filename);
		try
		{
			::INIClass *result = ::Get_INI(reinterpret_cast<char *>(filenameHandle.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew INIClass(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(filenameHandle);
		}
	}

	void Engine::ReleaseINI(IINIClass ^ini)
	{
		if (ini == nullptr || ini->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("ini");
		}

		::Release_INI(reinterpret_cast<::INIClass *>(ini->INIClassPointer.ToPointer()));
	}

	unsigned int Engine::GetRegistryInt(String ^entry, int defaultValue)
	{
		if (entry == nullptr)
		{
			return ::Get_Registry_Int(nullptr, defaultValue);
		}
		else
		{
			IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
			try
			{
				return ::Get_Registry_Int(reinterpret_cast<char *>(entryHandle.ToPointer()), defaultValue);
			}
			finally
			{
				Marshal::FreeHGlobal(entryHandle);
			}
		}
	}

	String ^Engine::RenSharpVersion::get()
	{
		return "1.5";
	}

	Threading::Thread^ Engine::RenegadeThread::get()
	{
		return renegadeThread;
	}

	RenegadeDispatcher^ Engine::Dispatcher::get()
	{
		if (Threading::Thread::CurrentThread->Equals(renegadeThread))
		{
			throw gcnew InvalidOperationException("On the Renegade thread");
		}

		Monitor::Enter(dispatchers);
		try
		{
			RenegadeDispatcher^ dispatcher;
			if (!dispatchers->TryGetValue(Threading::Thread::CurrentThread, dispatcher))
			{
				dispatcher = gcnew RenegadeDispatcher(renegadeThread, Threading::Thread::CurrentThread, InitialDispatcherQueueSize);
				dispatchers->Add(Threading::Thread::CurrentThread, dispatcher);
			}

			return dispatcher;
		}
		finally
		{
			Monitor::Exit(dispatchers);
		}
	}

	String ^Engine::StripPathFromFilename(String ^filename)
	{
		if (filename == nullptr)
		{
			throw gcnew ArgumentNullException("filename");
		}

		StringClass result;

		IntPtr filenameHandle = Marshal::StringToHGlobalAnsi(filename);
		try
		{
			::Strip_Path_From_Filename(result, reinterpret_cast<char *>(filenameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(filenameHandle);
		}

		return gcnew String(result.Peek_Buffer());
	}

	void Engine::InternalPathfindDistanceCallback(::PathfindDistanceRequest *result)
	{
		try
		{
			if (shutdown)
			{
				return;
			}

			try
			{
				uint32 managedId = 0;
				if (result->Data)
				{
					managedId = *static_cast<uint32 *>(result->Data);
				}

				PathfindDistanceRequest ^request;
				if (!pathfindDistanceRequests->TryGetValue(managedId, request))
				{
					return;
				}

				pathfindDistanceRequests->Remove(managedId);

				Vector3 startVec;
				Vector3 destVec;

				Vector3::UnmanagedToManagedVector3(result->Start, startVec);
				Vector3::UnmanagedToManagedVector3(result->Dest, destVec);

				request->Delegate->Invoke(
					result->Id,
					startVec,
					destVec,
					static_cast<PathfindDistanceResult>(result->Result),
					result->Distance,
					request->Data);
			}
			catch (Exception ^ex)
			{
				FatalRenSharpException ^exception = gcnew FatalRenSharpException("Engine.InternalPathfindDistanceCallback failed fatally", ex);

				Imports::OnFatalExceptionCallback(exception->ToString());

				// throw exception; Cannot throw here
			}
		}
		finally
		{
			if (result->Data)
			{
				Imports::DestroyUInt32(static_cast<uint32 *>(result->Data));
			}
		}
	}

	ISList<IcPlayer ^> ^Engine::GetPlayerList()
	{
		if (::Get_Player_List == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		auto result = Get_Player_List();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayerSList(IntPtr(result));
		}
	}

	int Engine::GetCurrentMapIndex()
	{
		if (::Get_Current_Map_Index == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return ::Get_Current_Map_Index();
	}

	String ^Engine::GetMap(int index)
	{
		if (::Get_Map == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (index < 0 || index >= ::Get_Map_Count())
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = ::Get_Map(index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	int Engine::GetMapCount()
	{
		if (::Get_Map_Count == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return ::Get_Map_Count();
	}

	bool Engine::SetMap(String ^map, int index)
	{
		if (::Set_Map == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (map == nullptr)
		{
			throw gcnew ArgumentNullException("map");
		}
		else if (index < 0 || index >= ::Get_Map_Count())
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		IntPtr mapHandle = Marshal::StringToHGlobalAnsi(map);
		try
		{
			return ::Set_Map(
				reinterpret_cast<char *>(mapHandle.ToPointer()),
				index);
		}
		finally
		{
			Marshal::FreeHGlobal(mapHandle);
		}
	}

	IUnmanagedContainer<IHashTemplateClass<String ^, IGameDefinition ^> ^> ^Engine::GetGameDefinitions()
	{
		if (::Get_Game_Definitions == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		auto result = StringClassGameDefinitionHashTemplateClass::CreateStringClassGameDefinitionHashTemplateClass();
		try
		{
			::Get_Game_Definitions(*reinterpret_cast<::HashTemplateClass<::StringClass, ::GameDefinition> *>(result->UnmanagedObject->Pointer.ToPointer()));

			return result;
		}
		catch(Exception ^)
		{
#pragma push_macro("delete")
#undef delete

			delete result;
			result = nullptr;

#pragma pop_macro("delete")

			throw;
		}
	}

	void Engine::EvictClient(int clientId, String ^reason)
	{
		if (::Evict_Client == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (reason == nullptr)
		{
			throw gcnew ArgumentNullException(reason);
		}

		IntPtr reasonHandle = Marshal::StringToHGlobalUni(reason);
		try
		{
			::WideStringClass tmp(reinterpret_cast<wchar_t *>(reasonHandle.ToPointer()));

			::Evict_Client(clientId, tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(reasonHandle);
		}
	}

	String ^Engine::GetClientSerialHash(int clientId)
	{
		if (::Get_Client_Serial_Hash == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		auto result = ::Get_Client_Serial_Hash(clientId);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	IScriptableGameObj ^Engine::GetGameObjByPlayerName(String ^name)
	{
		if (::Get_GameObj_By_Player_Name == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			auto result = ::Get_GameObj_By_Player_Name(reinterpret_cast<char *>(nameHandle.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	void Engine::SendCustomAllPlayers(int type, IScriptableGameObj ^sender, int team)
	{
		if (::Send_Custom_All_Players == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (sender == nullptr || sender->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("sender");
		}

		::Send_Custom_All_Players(
			type,
			reinterpret_cast<::ScriptableGameObj *>(sender->ScriptableGameObjPointer.ToPointer()),
			team);
	}

	float Engine::StealTeamCredits(float percentage, int team)
	{
		if (::Steal_Team_Credits == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return ::Steal_Team_Credits(percentage, team);
	}

	float Engine::GetTeamCredits(int team)
	{
		if (::Get_Team_Credits == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return ::Get_Team_Credits(team);
	}

	void Engine::SetCurrentBullets(IScriptableGameObj ^obj, int bullets)
	{
		if (::Set_Current_Bullets == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Current_Bullets(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			bullets);
	}

	void Engine::SetCurrentClipBullets(IScriptableGameObj ^obj, int bullets)
	{
		if (::Set_Current_Clip_Bullets == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Current_Clip_Bullets(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			bullets);
	}

	void Engine::SetPositionBullets(IScriptableGameObj ^obj, int position, int bullets)
	{
		if (::Set_Position_Bullets == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		
		::Set_Position_Bullets(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			position,
			bullets);
	}

	void Engine::SetPositionClipBullets(IScriptableGameObj ^obj, int position, int bullets)
	{
		if (::Set_Position_Clip_Bullets == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Position_Clip_Bullets(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			position,
			bullets);
	}

	void Engine::SetBullets(IScriptableGameObj ^obj, String ^weapon, int bullets)
	{
		if (::Set_Bullets == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (weapon == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		IntPtr weaponHandle = Marshal::StringToHGlobalAnsi(weapon);
		try
		{
			::Set_Bullets(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(weaponHandle.ToPointer()),
				bullets);
		}
		finally
		{
			Marshal::FreeHGlobal(weaponHandle);
		}
	}

	void Engine::SetClipBullets(IScriptableGameObj ^obj, String ^weapon, int bullets)
	{
		if (::Set_Clip_Bullets == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (weapon == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		IntPtr weaponHandle = Marshal::StringToHGlobalAnsi(weapon);
		try
		{
			::Set_Clip_Bullets(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(weaponHandle.ToPointer()),
				bullets);
		}
		finally
		{
			Marshal::FreeHGlobal(weaponHandle);
		}
	}

	void Engine::DisplayGameHint(IScriptableGameObj ^obj, int eventId, String ^sound, int titleId, int textId, int textId2, int textId3)
	{
		if (::Display_Game_Hint == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (sound == nullptr)
		{
			throw gcnew ArgumentNullException("sound");
		}

		IntPtr soundHandle = Marshal::StringToHGlobalAnsi(sound);
		try
		{
			::Display_Game_Hint(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				eventId,
				reinterpret_cast<char *>(soundHandle.ToPointer()),
				titleId,
				textId,
				textId2,
				textId3);
		}
		finally
		{
			Marshal::FreeHGlobal(soundHandle);
		}
	}

	void Engine::DisplayGameHintImage(IScriptableGameObj ^obj, int eventId, String ^sound, int titleId, int textId, int textId2, int textId3, String ^textureName)
	{
		if (::Display_Game_Hint_Image == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (sound == nullptr)
		{
			throw gcnew ArgumentNullException("sound");
		}
		else if (textureName == nullptr)
		{
			throw gcnew ArgumentNullException("textureName");
		}

		IntPtr soundHandle = Marshal::StringToHGlobalAnsi(sound);
		try
		{
			IntPtr textureNameHandle = Marshal::StringToHGlobalAnsi(textureName);
			try
			{
				::Display_Game_Hint_Image(
					reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
					eventId,
					reinterpret_cast<char *>(soundHandle.ToPointer()),
					titleId,
					textId,
					textId2,
					textId3,
					reinterpret_cast<char *>(textureNameHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(textureNameHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(soundHandle);
		}
	}

	void Engine::SetScope(IScriptableGameObj ^obj, int scope)
	{
		throw gcnew NotSupportedException("No linkage");

		/*
		if (::Set_Scope == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Scope(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			scope);
		*/
	}

	String ^Engine::GetCurrentMusicTrack()
	{
		if (::GetCurrentMusicTrack == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		auto result = ::GetCurrentMusicTrack();
		try
		{
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew String(result);
			}
		}
		finally
		{
			// ::GetCurrentMusicTrack uses newstr
			Imports::DestroyAnsiString(result);
		}
	}

	void Engine::SetInfoTexture(IScriptableGameObj ^obj, String ^texture)
	{
		if (::Set_Info_Texture == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (texture == nullptr)
		{
			throw gcnew ArgumentNullException("texture");
		}

		IntPtr textureHandle = Marshal::StringToHGlobalAnsi(texture);
		try
		{
			::Set_Info_Texture(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(textureHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(textureHandle);
		}
	}

	void Engine::ClearInfoTexture(IScriptableGameObj ^obj)
	{
		if (::Clear_Info_Texture == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Clear_Info_Texture(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::EnableStealthPlayer(IScriptableGameObj ^obj, IScriptableGameObj ^obj2, bool enable)
	{
		if (::Enable_Stealth_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (obj2 == nullptr || obj2->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj2");
		}

		::Enable_Stealth_Player(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			reinterpret_cast<::ScriptableGameObj *>(obj2->ScriptableGameObjPointer.ToPointer()),
			enable);
	}

	void Engine::SetFogEnablePlayer(IScriptableGameObj ^obj, bool enable)
	{
		if (::Set_Fog_Enable_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Fog_Enable_Player(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			enable);
	}

	void Engine::SetFogRangePlayer(IScriptableGameObj ^obj, float startDistance, float endDistance, float transition)
	{
		if (::Set_Fog_Range_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Fog_Range_Player(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			startDistance,
			endDistance,
			transition);
	}

	void Engine::SetBackgroundMusicPlayer(IScriptableGameObj ^obj, String ^music)
	{
		if (::Set_Background_Music_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (music == nullptr)
		{
			throw gcnew ArgumentNullException("music");
		}

		IntPtr musicHandle = Marshal::StringToHGlobalAnsi(music);
		try
		{
			::Set_Background_Music_Player(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(musicHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(musicHandle);
		}
	}

	void Engine::FadeBackgroundMusicPlayer(IScriptableGameObj ^obj, String ^music, int fadeOut, int fadeIn)
	{
		if (::Fade_Background_Music_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		IntPtr musicHandle = Marshal::StringToHGlobalAnsi(music);
		try
		{
			::Fade_Background_Music_Player(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(musicHandle.ToPointer()),
				fadeOut,
				fadeIn);
		}
		finally
		{
			Marshal::FreeHGlobal(musicHandle);
		}
	}

	void Engine::StopBackgroundMusicPlayer(IScriptableGameObj ^obj)
	{
		if (::Stop_Background_Music_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Stop_Background_Music_Player(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::EnableRadarPlayer(IScriptableGameObj ^obj, bool enable)
	{
		if (::Enable_Radar_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Enable_Radar_Player(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			enable);
	}

	void Engine::DisplayGDIPlayerTerminalPlayer(IScriptableGameObj ^obj)
	{
		if (::Display_GDI_Player_Terminal_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Display_GDI_Player_Terminal_Player(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::DisplayNodPlayerTerminalPlayer(IScriptableGameObj ^obj)
	{
		if (::Display_NOD_Player_Terminal_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Display_NOD_Player_Terminal_Player(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::SetScreenFadeColorPlayer(IScriptableGameObj ^obj, Color color, float transition)
	{
		if (::Set_Screen_Fade_Color_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Screen_Fade_Color_Player(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			color.R / 255.0f,
			color.G / 255.0f,
			color.B / 255.0f,
			transition);
	}

	void Engine::SetScreenFadeOpacityPlayer(IScriptableGameObj ^obj, float opacity, float transition)
	{
		if (::Set_Screen_Fade_Opacity_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Screen_Fade_Opacity_Player(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			opacity,
			transition);
	}

	void Engine::ForceCameraLookPlayer(IScriptableGameObj ^obj, Vector3 look)
	{
		if (::Force_Camera_Look_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Vector3 lookVec;

		Vector3::ManagedToUnmanagedVector3(look, lookVec);

		::Force_Camera_Look_Player(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			lookVec);
	}

	void Engine::EnableHUDPlayer(IScriptableGameObj ^obj, bool enable)
	{
		if (::Enable_HUD_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Enable_HUD_Player(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			enable);
	}

	int Engine::CreateSoundPlayer(IScriptableGameObj ^obj, String ^soundname, Vector3 position, IScriptableGameObj ^obj2)
	{
		if (::Create_Sound_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (soundname == nullptr)
		{
			throw gcnew ArgumentNullException("soundname");
		}
		else if (obj2 == nullptr || obj2->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj2");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		IntPtr soundnameHandle = Marshal::StringToHGlobalAnsi(soundname);
		try
		{
			return ::Create_Sound_Player(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(soundnameHandle.ToPointer()),
				positionVec,
				reinterpret_cast<::ScriptableGameObj *>(obj2->ScriptableGameObjPointer.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(soundnameHandle);
		}
	}

	int Engine::Create2DSoundPlayer(IScriptableGameObj ^obj, String ^soundname)
	{
		if (::Create_2D_Sound_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (soundname == nullptr)
		{
			throw gcnew ArgumentNullException("soundname");
		}

		IntPtr soundnameHandle = Marshal::StringToHGlobalAnsi(soundname);
		try
		{
			return ::Create_2D_Sound_Player(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(soundnameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(soundnameHandle);
		}
	}

	int Engine::Create2DWAVSoundPlayer(IScriptableGameObj ^obj, String ^soundname)
	{
		if (::Create_2D_WAV_Sound_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (soundname == nullptr)
		{
			throw gcnew ArgumentNullException("soundname");
		}

		IntPtr soundnameHandle = Marshal::StringToHGlobalAnsi(soundname);
		try
		{
			return ::Create_2D_WAV_Sound_Player(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(soundnameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(soundnameHandle);
		}
	}

	int Engine::Create3DWAVSoundAtBonePlayer(IScriptableGameObj ^obj, String ^soundname, IScriptableGameObj ^obj2, String ^bonename)
	{
		if (::Create_3D_WAV_Sound_At_Bone_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (soundname == nullptr)
		{
			throw gcnew ArgumentNullException("soundname");
		}
		else if (obj2 == nullptr || obj2->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj2");
		}
		else if (bonename == nullptr)
		{
			throw gcnew ArgumentNullException("bonename");
		}

		IntPtr soundnameHandle = Marshal::StringToHGlobalAnsi(soundname);
		try
		{
			IntPtr bonenameHandle = Marshal::StringToHGlobalAnsi(bonename);
			try
			{
				return ::Create_3D_WAV_Sound_At_Bone_Player(
					reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
					reinterpret_cast<char *>(soundnameHandle.ToPointer()),
					reinterpret_cast<::ScriptableGameObj *>(obj2->ScriptableGameObjPointer.ToPointer()),
					reinterpret_cast<char *>(bonenameHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(bonenameHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(soundnameHandle);
		}
	}

	int Engine::Create3DSoundAtBonePlayer(IScriptableGameObj ^obj, String ^soundname, IScriptableGameObj ^obj2, String ^bonename)
	{
		if (::Create_3D_Sound_At_Bone_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (soundname == nullptr)
		{
			throw gcnew ArgumentNullException("soundname");
		}
		else if (obj2 == nullptr || obj2->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj2");
		}
		else if (bonename == nullptr)
		{
			throw gcnew ArgumentNullException("bonename");
		}

		IntPtr soundnameHandle = Marshal::StringToHGlobalAnsi(soundname);
		try
		{
			IntPtr bonenameHandle = Marshal::StringToHGlobalAnsi(bonename);
			try
			{
				return ::Create_3D_Sound_At_Bone_Player(
					reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
					reinterpret_cast<char *>(soundnameHandle.ToPointer()),
					reinterpret_cast<::ScriptableGameObj *>(obj2->ScriptableGameObjPointer.ToPointer()),
					reinterpret_cast<char *>(bonenameHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(bonenameHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(soundnameHandle);
		}
	}

	void Engine::SetVehicleLimit(unsigned int limit)
	{
		if (::Set_Vehicle_Limit == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Set_Vehicle_Limit(limit);
	}

	unsigned long Engine::GetVehicleLimit()
	{
		if (::Get_Vehicle_Limit == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return ::Get_Vehicle_Limit();
	}

	void Engine::SetAirVehicleLimit(unsigned int limit)
	{
		if (::Set_Air_Vehicle_Limit == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Set_Air_Vehicle_Limit(limit);
	}

	unsigned long Engine::GetAirVehicleLimit()
	{
		if (::Get_Air_Vehicle_Limit == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return ::Get_Air_Vehicle_Limit();
	}

	void Engine::SetNavalVehicleLimit(unsigned int limit)
	{
		if (::Set_Naval_Vehicle_Limit == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Set_Naval_Vehicle_Limit(limit);
	}

	unsigned long Engine::GetNavalVehicleLimit()
	{
		if (::Get_Naval_Vehicle_Limit == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return ::Get_Naval_Vehicle_Limit();
	}

	void Engine::SendMessage(Color color, String ^msg)
	{
		if (::Send_Message == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (msg == nullptr)
		{
			throw gcnew ArgumentNullException("msg");
		}

		IntPtr msgHandle = Marshal::StringToHGlobalAnsi(msg);
		try
		{
			::Send_Message(color.R, color.G, color.B, reinterpret_cast<char *>(msgHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(msgHandle);
		}
	}

	void Engine::SendMessagePlayer(IScriptableGameObj ^obj, Color color, String ^msg)
	{
		if (::Send_Message_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (msg == nullptr)
		{
			throw gcnew ArgumentNullException("msg");
		}

		IntPtr msgHandle = Marshal::StringToHGlobalAnsi(msg);
		try
		{
			::Send_Message_Player(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				color.R,
				color.G,
				color.B,
				reinterpret_cast<char *>(msgHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(msgHandle);
		}
	}

	void Engine::LoadNewHUDINI(IScriptableGameObj ^obj, String ^ini)
	{
		if (::Load_New_HUD_INI == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (ini == nullptr)
		{
			throw gcnew ArgumentNullException("ini");
		}

		IntPtr iniHandle = Marshal::StringToHGlobalAnsi(ini);
		try
		{
			::Load_New_HUD_INI(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(iniHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(iniHandle);
		}
	}

	void Engine::RemoveWeapon(IScriptableGameObj ^obj, String ^weapon)
	{
		if (::Remove_Weapon == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (weapon == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		IntPtr weaponHandle = Marshal::StringToHGlobalAnsi(weapon);
		try
		{
			::Remove_Weapon(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(weaponHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(weaponHandle);
		}
	}

	void Engine::ChangeRadarMap(float scale, float offsetX, float offsetY, String ^texture)
	{
		if (::Change_Radar_Map == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (texture == nullptr)
		{
			throw gcnew ArgumentNullException("texture");
		}

		IntPtr textureHandle = Marshal::StringToHGlobalAnsi(texture);
		try
		{
			::Change_Radar_Map(
				scale,
				offsetX,
				offsetY,
				reinterpret_cast<char *>(textureHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(textureHandle);
		}
	}

	float Engine::GetBuildTimeMultiplier(int team)
	{
		if (::Get_Build_Time_Multiplier == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return ::Get_Build_Time_Multiplier(team);
	}

	void Engine::SetCurrentlyBuilding(bool building, int team)
	{
		if (::Set_Currently_Building == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Set_Currently_Building(building, team);
	}

	bool Engine::IsCurrentlyBuilding(int team)
	{
		if (::Is_Currently_Building == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return ::Is_Currently_Building(team);
	}

	void Engine::SetFogColor(Color color)
	{
		if (::Set_Fog_Color == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Set_Fog_Color(color.R, color.G, color.B);
	}

	void Engine::SetFogColorPlayer(IScriptableGameObj ^obj, Color color)
	{
		if (::Set_Fog_Color_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Fog_Color_Player(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			color.R,
			color.G,
			color.B);
	}

	void Engine::SetFogMode(unsigned int mode)
	{
		if (::Set_Fog_Mode == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Set_Fog_Mode(mode);
	}

	void Engine::SetFogModePlayer(IScriptableGameObj ^obj, unsigned int mode)
	{
		if (::Set_Fog_Mode_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Fog_Mode_Player(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			mode);
	}

	void Engine::SetFogDensity(float density)
	{
		if (::Set_Fog_Density == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Set_Fog_Density(density);
	}

	void Engine::SetFogDensityPlayer(IScriptableGameObj ^obj, float density)
	{
		if (::Set_Fog_Density_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Fog_Density_Player(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			density);
	}

	void Engine::ChangeTimeRemaining(float time)
	{
		if (::Change_Time_Remaining == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Change_Time_Remaining(time);
	}

	void Engine::ChangeTimeLimit(int time)
	{
		if (::Change_Time_Limit == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Change_Time_Limit(time);
	}

	void Engine::DisplaySecurityDialog(IScriptableGameObj ^obj)
	{
		if (::Display_Security_Dialog == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Display_Security_Dialog(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::SendHUDNumber(IScriptableGameObj ^obj, unsigned int number)
	{
		if (::Send_HUD_Number == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Send_HUD_Number(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			number);
	}

	IScriptableGameObj ^Engine::GetExplosionObj()
	{
		if (::GetExplosionObj == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		auto result = ::GetExplosionObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	void Engine::SetExplosionObj(IScriptableGameObj ^obj)
	{
		if (::SetExplosionObj == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			::SetExplosionObj(nullptr);
		}
		else
		{
			::SetExplosionObj(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
		}
	}

	void Engine::UpdateNetworkObject(INetworkObjectClass ^obj)
	{
		if (::Update_Network_Object == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->NetworkObjectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Update_Network_Object(
			reinterpret_cast<::NetworkObjectClass *>(obj->NetworkObjectClassPointer.ToPointer()));
	}

	void Engine::UpdateNetworkObjectPlayer(INetworkObjectClass ^object, int id)
	{
		if (::Update_Network_Object_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->NetworkObjectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Update_Network_Object_Player(
			reinterpret_cast<::NetworkObjectClass *>(object->NetworkObjectClassPointer.ToPointer()),
			id);
	}

	IcScTextObj ^Engine::SendClientText(String ^message, TextMessageEnum type, bool popUp, int senderId, int receiverId, bool doDirtyBit, bool doAct)
	{
		if (::Send_Client_Text == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (message == nullptr)
		{
			throw gcnew ArgumentNullException("message");
		}

		IntPtr messageHandle = Marshal::StringToHGlobalUni(message);
		try
		{
			::WideStringClass tmp(reinterpret_cast<wchar_t *>(messageHandle.ToPointer()));

			auto result = ::Send_Client_Text(
				tmp,
				static_cast<::TextMessageEnum>(type),
				popUp,
				senderId,
				receiverId,
				doDirtyBit,
				doAct);

			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew cScTextObj(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(messageHandle);
		}
	}

	ISCAnnouncement ^Engine::SendClientAnnouncement(int receiptientId, int senderId, int translationId, AnnouncementEnum type, int emotIconId, bool doDirtyBit, bool doAct)
	{
		if (::Send_Client_Announcement == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		auto result = ::Send_Client_Announcement(
			receiptientId,
			senderId,
			translationId,
			static_cast<::AnnouncementEnum>(type),
			emotIconId,
			doDirtyBit,
			doAct);

		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SCAnnouncement(IntPtr(result));
		}
	}

	IcPlayerKill ^Engine::SendPlayerKillMessage(int killer, int victim)
	{
		if (::Send_Player_Kill_Message == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		auto result = ::Send_Player_Kill_Message(killer, victim);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayerKill(IntPtr(result));
		}
	}

	IcPurchaseResponseEvent ^Engine::SendPurchaseResponse(int id, int type)
	{
		if (::Send_Purchase_Response == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		auto result = ::Send_Purchase_Response(id, type);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPurchaseResponseEvent(IntPtr(result));
		}
	}

	void Engine::DoObjectivesDlg(IScriptableGameObj ^obj, String ^file)
	{
		if (::Do_Objectives_Dlg == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (file == nullptr)
		{
			throw gcnew ArgumentNullException("file");
		}

		IntPtr fileHandle = Marshal::StringToHGlobalAnsi(file);
		try
		{
			::Do_Objectives_Dlg(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(fileHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(fileHandle);
		}
	}

	void Engine::SetPlayerLimit(unsigned int limit)
	{
		if (::Set_Player_Limit == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Set_Player_Limit(limit);
	}

	unsigned int Engine::GetPlayerLimit()
	{
		if (::Get_Player_Limit == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return ::Get_Player_Limit();
	}

	void Engine::GetFogRange([Out] float %startDistance, [Out] float %endDistance)
	{
		if (::Get_Fog_Range == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		float tmpStartDistance;
		float tmpEndDistance;

		::Get_Fog_Range(tmpStartDistance, tmpEndDistance);

		startDistance = tmpStartDistance;
		endDistance = tmpEndDistance;
	}

	void Engine::SendShaderParamPlayerObsolete(IScriptableGameObj ^player, String ^parameter, String ^value)
	{
		if (::Send_Shader_Param_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}
		else if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
			try
			{
				::Send_Shader_Param_Player(
					reinterpret_cast<::ScriptableGameObj *>(player->ScriptableGameObjPointer.ToPointer()),
					reinterpret_cast<char *>(parameterHandle.ToPointer()),
					reinterpret_cast<char *>(valueHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(valueHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParamObsolete(String ^parameter, String ^value)
	{
		if (::Send_Shader_Param == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}
		else if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
			try
			{
				::Send_Shader_Param(
					reinterpret_cast<char *>(parameterHandle.ToPointer()),
					reinterpret_cast<char *>(valueHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(valueHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParamObjPlayerObsolete(IScriptableGameObj ^player, String ^parameter, String ^value, IScriptableGameObj ^obj)
	{
		if (::Send_Shader_Param_Obj_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}
		else if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
			try
			{
				::Send_Shader_Param_Obj_Player(
					reinterpret_cast<::ScriptableGameObj *>(player->ScriptableGameObjPointer.ToPointer()),
					reinterpret_cast<char *>(parameterHandle.ToPointer()),
					reinterpret_cast<char *>(valueHandle.ToPointer()),
					reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(valueHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParamObjObsolete(String ^parameter, String ^value, IScriptableGameObj ^obj)
	{
		if (::Send_Shader_Param_Obj == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}
		else if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
			try
			{
				::Send_Shader_Param_Obj(
					reinterpret_cast<char *>(parameterHandle.ToPointer()),
					reinterpret_cast<char *>(valueHandle.ToPointer()),
					reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(valueHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SetGDISoldierName(String ^name)
	{
		if (::Set_GDI_Soldier_Name == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			::Set_GDI_Soldier_Name(
				reinterpret_cast<char *>(nameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	void Engine::SetNodSoldierName(String ^name)
	{
		if (::Set_Nod_Soldier_Name == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			::Set_Nod_Soldier_Name(
				reinterpret_cast<char *>(nameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	String ^Engine::GetGDISoldierName()
	{
		if (::Get_GDI_Soldier_Name == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		auto result = ::Get_GDI_Soldier_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String ^Engine::GetNodSoldierName()
	{
		if (::Get_Nod_Soldier_Name == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		auto result = ::Get_Nod_Soldier_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String ^Engine::GetIPAddress(int playerId)
	{
		if (::Get_IP_Address == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		auto result = ::Get_IP_Address(playerId);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String ^Engine::GetIPPort(int playerId)
	{
		if (::Get_IP_Port == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		auto result = ::Get_IP_Port(playerId);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	IPEndPoint ^Engine::GetIP(int playerId)
	{
		if (::Get_IP == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		auto result = ::Get_IP(playerId);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew IPEndPoint(result->sin_addr.S_un.S_addr, result->sin_port);
		}
	}

	int Engine::GetBandwidth(int playerId)
	{
		if (::Get_Bandwidth == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return ::Get_Bandwidth(playerId);
	}

	int Engine::GetPing(int playerId)
	{
		if (::Get_Ping == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return ::Get_Ping(playerId);
	}

	unsigned long Engine::GetKbits(int playerId)
	{
		if (::Get_Kbits == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return ::Get_Kbits(playerId);
	}

	void Engine::SetFogOverridePlayer(IScriptableGameObj ^obj, float start, float end)
	{
		if (::Set_Fog_Override_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Fog_Override_Player(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			start,
			end);
	}

	void Engine::ClearFogOverridePlayer(IScriptableGameObj ^obj)
	{
		if (::Clear_Fog_Override_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Clear_Fog_Override_Player(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::SetMoonIsEarth(bool earth)
	{
		if (::Set_Moon_Is_Earth == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Set_Moon_Is_Earth(earth);
	}

	void Engine::SetGlobalStealthDisable(bool disabled)
	{
		if (::Set_Global_Stealth_Disable == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Set_Global_Stealth_Disable(disabled);
	}

	int Engine::GetMineLimit()
	{
		if (::Get_Mine_Limit == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return ::Get_Mine_Limit();
	}

	void Engine::SetSpecialBaseDestruction()
	{
		if (::Set_Special_Base_Destruction == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Set_Special_Base_Destruction();
	}

	float Engine::GetClientVersion(int playerId)
	{
		if (::Get_Client_Version == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return ::Get_Client_Version(playerId);
	}

	uint Engine::GetClientRevision(int playerId)
	{
		if (::Get_Client_Revision == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return ::Get_Client_Revision(playerId);
	}

	uint Engine::GetRevision(int playerId)
	{
		if (::Get_Revision == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return ::Get_Revision(playerId);
	}

	unsigned int Engine::GetDamageWarhead()
	{
		if (::Get_Damage_Warhead == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return ::Get_Damage_Warhead();
	}

	bool Engine::GetDamageIsExplosion()
	{
		if (::Get_Damage_Is_Explosion == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return ::Get_Damage_Is_Explosion();
	}

	bool Engine::IsWOLUser(String ^playerName)
	{
		if (::Is_WOL_User == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (playerName == nullptr)
		{
			throw gcnew ArgumentNullException("playerName");
		}

		IntPtr playerNameHandle = Marshal::StringToHGlobalUni(playerName);
		try
		{
			return ::Is_WOL_User(reinterpret_cast<wchar_t *>(playerNameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(playerNameHandle);
		}
	}

	int Engine::GetTechLevel()
	{
		if (::Get_Tech_Level == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return ::Get_Tech_Level();
	}

	void Engine::SetTechLevel(int mode)
	{
		if (::Set_Tech_Level == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Set_Tech_Level(mode);
	}

	void Engine::CreateExplosionExtended(String ^explosion, Vector3 pos, IScriptableGameObj ^creator)
	{
		if (::Create_Explosion_Extended == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (explosion == nullptr)
		{
			throw gcnew ArgumentNullException("explosion");
		}
		else if (creator == nullptr || creator->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("creator");
		}

		::Vector3 posVec;

		Vector3::ManagedToUnmanagedVector3(pos, posVec);

		IntPtr explosionHandle = Marshal::StringToHGlobalAnsi(explosion);
		try
		{
			::Create_Explosion_Extended(
				reinterpret_cast<char *>(explosionHandle.ToPointer()),
				posVec,
				reinterpret_cast<::ScriptableGameObj *>(creator->ScriptableGameObjPointer.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(explosionHandle);
		}
	}

	IUnmanagedContainer<IDynamicVectorClass<int> ^> ^Engine::RetrieveWaypaths()
	{
		if (::Retrieve_Waypaths == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		auto result = Int32DynamicVectorClass::CreateInt32DynamicVectorClass();
		try
		{
			::Retrieve_Waypaths(
				*reinterpret_cast<::DynamicVectorClass<int> *>(result->UnmanagedObject->Pointer.ToPointer()));

			return result;
		}
		catch (Exception ^)
		{
#pragma push_macro("delete")
#undef delete

			delete result;
			result = nullptr;

#pragma pop_macro("delete")

			throw;
		}
	}

	IUnmanagedContainer<IDynamicVectorClass<int> ^> ^Engine::RetrieveWaypoints(int waypathId)
	{
		if (::Retrieve_Waypoints == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		auto result = Int32DynamicVectorClass::CreateInt32DynamicVectorClass();
		try
		{
			::Retrieve_Waypoints(
				waypathId,
				*reinterpret_cast<::DynamicVectorClass<int> *>(result->UnmanagedObject->Pointer.ToPointer()));

			return result;
		}
		catch (Exception ^)
		{
#pragma push_macro("delete")
#undef delete

			delete result;
			result = nullptr;

#pragma pop_macro("delete")

			throw;
		}
	}

	Vector3 Engine::GetWaypointPosition(int waypathId, int waypointId)
	{
		if (::Get_Waypoint_Position == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Vector3 tmp;

		::Get_Waypoint_Position(waypathId, waypointId, tmp);

		Vector3 result;

		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	void Engine::CreateLightning(IAmmoDefinitionClass ^ammoDef, Vector3 start, Vector3 end)
	{
		if (::Create_Lightning == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (ammoDef == nullptr || ammoDef->AmmoDefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("ammoDef");
		}

		::Vector3 startVec;
		::Vector3 endVec;

		Vector3::ManagedToUnmanagedVector3(start, startVec);
		Vector3::ManagedToUnmanagedVector3(end, endVec);

		::Create_Lightning(
			reinterpret_cast<::AmmoDefinitionClass *>(ammoDef->AmmoDefinitionClassPointer.ToPointer()),
			startVec,
			endVec);
	}

	void Engine::GetClouds([Out] float %cloudCover, [Out] float %gloominess)
	{
		if (::Get_Clouds == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		float tmpCloudCover;
		float tmpGloominess;

		::Get_Clouds(tmpCloudCover, tmpGloominess);

		cloudCover = tmpCloudCover;
		gloominess = tmpGloominess;
	}

	void Engine::GetLightning([Out] float %intensity, [Out] float %startDistance, [Out] float %endDistance, [Out] float %heading, [Out] float %distribution)
	{
		if (::Get_Lightning == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		float tmpIntensity;
		float tmpStartDistance;
		float tmpEndDistance;
		float tmpHeading;
		float tmpDistribution;

		::Get_Lightning(tmpIntensity, tmpStartDistance, tmpEndDistance, tmpHeading, tmpDistribution);

		intensity = tmpIntensity;
		startDistance = tmpStartDistance;
		endDistance = tmpEndDistance;
		heading = tmpHeading;
		distribution = tmpDistribution;
	}

	void Engine::GetWind([Out] float %heading, [Out] float %speed, [Out] float %variability)
	{
		if (::Get_Wind == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		float tmpHeading;
		float tmpSpeed;
		float tmpVariability;

		::Get_Wind(tmpHeading, tmpSpeed, tmpVariability);

		heading = tmpHeading;
		speed = tmpSpeed;
		variability = tmpVariability;
	}

	void Engine::GetRain([Out] float %density)
	{
		if (::Get_Rain == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		float tmpDensity;

		::Get_Rain(tmpDensity);

		density = tmpDensity;
	}

	void Engine::GetSnow([Out] float %density)
	{
		if (::Get_Snow == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		float tmpDensity;

		::Get_Snow(tmpDensity);

		density = tmpDensity;
	}

	void Engine::GetAsh([Out] float %density)
	{
		if (::Get_Ash == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		float tmpDensity;

		::Get_Ash(tmpDensity);

		density = tmpDensity;
	}

	void Engine::UpdateGameOptions(int id)
	{
		if (::Update_Game_Options == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Update_Game_Options(id);
	}

	double Engine::GetTTVersion()
	{
		if (::GetTTVersion == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return ::GetTTVersion();
	}

	uint Engine::GetTTRevision()
	{
		if (::GetTTRevision == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return ::GetTTRevision();
	}

	void Engine::SetHUDHelpTextPlayer(IScriptableGameObj ^obj, int string, Color color)
	{
		if (::Set_HUD_Help_Text_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Vector3 colorVec(color.R / 255.0f, color.G / 255.0f, color.B / 255.0f);

		::Set_HUD_Help_Text_Player(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			string,
			colorVec);
	}

	void Engine::ChangeStringPlayer(IScriptableGameObj ^obj, int id, String ^string)
	{
		if (::Change_String_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (string == nullptr)
		{
			throw gcnew ArgumentNullException("string");
		}

		IntPtr stringHandle = Marshal::StringToHGlobalAnsi(string);
		try
		{
			::Change_String_Player(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				id,
				reinterpret_cast<char *>(stringHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(stringHandle);
		}
	}

	void Engine::ForcePositionUpdate(IScriptableGameObj ^obj)
	{
		if (::Force_Position_Update == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Force_Position_Update(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool Engine::GetRandomPathfindSpot(Vector3 center, float range, [Out] Vector3% returnPosition)
	{
		if (::Get_Random_Pathfind_Spot == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Vector3 centerVec;
		::Vector3 tmp;

		Vector3::ManagedToUnmanagedVector3(center, centerVec);

		if (::Get_Random_Pathfind_Spot(centerVec, range, &tmp))
		{
			Vector3::UnmanagedToManagedVector3(tmp, returnPosition);

			return true;
		}
		else
		{
			returnPosition = Vector3();

			return false;
		}
	}

	void Engine::SetHUDHelpTextPlayerText(IScriptableGameObj ^obj, int replaceStringId, String ^replaceText, Color color)
	{
		if (::Set_HUD_Help_Text_Player_Text == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (replaceText == nullptr)
		{
			throw gcnew ArgumentNullException("replaceText");
		}

		::Vector3 colorVec(color.R / 255.0f, color.G / 255.0f, color.B / 255.0f);

		IntPtr replaceTextHandle = Marshal::StringToHGlobalAnsi(replaceText);
		try
		{
			::Set_HUD_Help_Text_Player_Text(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				replaceStringId,
				reinterpret_cast<char *>(replaceTextHandle.ToPointer()),
				colorVec);
		}
		finally
		{
			Marshal::FreeHGlobal(replaceTextHandle);
		}
	}

	void Engine::GrantWeapon(IScriptableGameObj ^object, String ^grantWeaponName, bool grantWeapon, int grantWeaponRounds, bool grantWeaponClips)
	{
		if (::Grant_Weapon == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		if (grantWeaponName == nullptr)
		{
			::Grant_Weapon(
				reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
				nullptr,
				grantWeapon,
				grantWeaponRounds,
				grantWeaponClips);
		}
		else
		{
			IntPtr grantWeaponNameHandle = Marshal::StringToHGlobalAnsi(grantWeaponName);
			try
			{
				::Grant_Weapon(
					reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()),
					reinterpret_cast<char *>(grantWeaponNameHandle.ToPointer()),
					grantWeapon,
					grantWeaponRounds,
					grantWeaponClips);
			}
			finally
			{
				Marshal::FreeHGlobal(grantWeaponNameHandle);
			}
		}
	}

	void Engine::SetObjectVisibilityForPlayer(IScriptableGameObj ^player, int objectId, bool visible)
	{
		if (::Set_Object_Visibility_For_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		::Set_Object_Visibility_For_Player(
			reinterpret_cast<::ScriptableGameObj *>(player->ScriptableGameObjPointer.ToPointer()),
			objectId,
			visible);
	}

	void Engine::SetObjectVisibility(int objectId, bool visible)
	{
		if (::Set_Object_Visibility == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		::Set_Object_Visibility(objectId, visible);
	}

	void Engine::LockSoldierCollisionGroup(IScriptableGameObj ^obj, CollisionGroupType collisionGroupType)
	{
		if (::Lock_Soldier_Collision_Group == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Lock_Soldier_Collision_Group(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			static_cast<::Collision_Group_Type>(collisionGroupType));
	}

	void Engine::UnlockSoldierCollisionGroup(IScriptableGameObj ^obj)
	{
		if (::Unlock_Soldier_Collision_Group == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Unlock_Soldier_Collision_Group(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool Engine::IsEngineEnabled(IScriptableGameObj ^obj)
	{
		if (::Is_Engine_Enabled == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Is_Engine_Enabled(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::StopTimer(IScriptableGameObj ^obj, int number)
	{
		if (::Stop_Timer == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Stop_Timer(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			number);
	}

	int Engine::Create2DWaveSoundDialogPlayer(IScriptableGameObj ^obj, String ^soundName)
	{
		if (::Create_2D_Wave_Sound_Dialog_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (soundName == nullptr)
		{
			throw gcnew ArgumentNullException("soundName");
		}

		IntPtr soundNameHandle = Marshal::StringToHGlobalAnsi(soundName);
		try
		{
			return ::Create_2D_Wave_Sound_Dialog_Player(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(soundNameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(soundNameHandle);
		}
	}

	void Engine::ForcePositionUpdatePlayer(IScriptableGameObj ^player, IScriptableGameObj ^obj)
	{
		if (::Force_Position_Update_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Force_Position_Update_Player(
			reinterpret_cast<::ScriptableGameObj *>(player->ScriptableGameObjPointer.ToPointer()),
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::StopTimer2(IScriptableGameObj ^obj, IScriptClass ^script, int number)
	{
		if (::Stop_Timer2 == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (script == nullptr || script->ScriptClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		::Stop_Timer2(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			reinterpret_cast<::ScriptClass *>(script->ScriptClassPointer.ToPointer()),
			number);
	}

	bool Engine::HasTimer(IScriptableGameObj ^obj, IScriptClass ^script, int number)
	{
		if (::Has_Timer == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (script == nullptr || script->ScriptClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		return ::Has_Timer(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			reinterpret_cast<::ScriptClass *>(script->ScriptClassPointer.ToPointer()),
			number);
	}

	void Engine::SetBackgroundMusicPlayerOffset(IScriptableGameObj ^obj, String ^music, float startOffset)
	{
		if (::Set_Background_Music_Player_Offset == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (music == nullptr)
		{
			throw gcnew ArgumentNullException("music");
		}

		IntPtr musicHandle = Marshal::StringToHGlobalAnsi(music);
		try
		{
			::Set_Background_Music_Player_Offset(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(musicHandle.ToPointer()),
				startOffset);
		}
		finally
		{
			Marshal::FreeHGlobal(musicHandle);
		}
	}

	void Engine::SetCameraPlayer(IScriptableGameObj ^obj, String ^camera)
	{
		if (::Set_Camera_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (camera == nullptr)
		{
			throw gcnew ArgumentNullException("camera");
		}

		IntPtr cameraHandle = Marshal::StringToHGlobalAnsi(camera);
		try
		{
			::Set_Camera_Player(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(cameraHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(cameraHandle);
		}
	}

	void Engine::SetDefinitionTranslationIDPlayer(IScriptableGameObj ^obj, int defId, int stringId)
	{
		if (::Set_Definition_TranslationID_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Definition_TranslationID_Player(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			defId,
			stringId);
	}

	void Engine::SetNetUpdateRatePlayer(IScriptableGameObj ^obj, int rate)
	{
		if (::Set_Net_Update_Rate_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Net_Update_Rate_Player(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			rate);
	}

	void Engine::ForceOrientationUpdate(IScriptableGameObj ^obj)
	{
		if (::Force_Orientation_Update == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Force_Orientation_Update(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::ForceOrientationUpdatePlayer(IScriptableGameObj ^player, IScriptableGameObj ^obj)
	{
		if (::Force_Orientation_Update_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Force_Orientation_Update_Player(
			reinterpret_cast<::ScriptableGameObj *>(player->ScriptableGameObjPointer.ToPointer()),
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	int Engine::Create2DWaveSoundCinematicPlayer(IScriptableGameObj ^obj, String ^soundName)
	{
		if (::Create_2D_Wave_Sound_Cinematic_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (soundName == nullptr)
		{
			throw gcnew ArgumentNullException("soundName");
		}

		IntPtr soundNameHandle = Marshal::StringToHGlobalAnsi(soundName);
		try
		{
			return ::Create_2D_Wave_Sound_Cinematic_Player(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(soundNameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(soundNameHandle);
		}
	}

	void Engine::ForceTurretUpdate(IScriptableGameObj ^obj)
	{
		if (::Force_Turret_Update == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Force_Turret_Update(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::ForceTurretUpdatePlayer(IScriptableGameObj ^player, IScriptableGameObj ^obj)
	{
		if (::Force_Turret_Update_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Force_Turret_Update_Player(
			reinterpret_cast<::ScriptableGameObj *>(player->ScriptableGameObjPointer.ToPointer()),
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::ForceVelocityUpdate(IScriptableGameObj ^obj)
	{
		if (::Force_Velocity_Update == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Force_Velocity_Update(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::ForceVelocityUpdatePlayer(IScriptableGameObj ^player, IScriptableGameObj ^obj)
	{
		if (::Force_Velocity_Update_Player == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Force_Velocity_Update_Player(
			reinterpret_cast<::ScriptableGameObj *>(player->ScriptableGameObjPointer.ToPointer()),
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::SetCameraHostNetwork(IScriptableGameObj ^obj)
	{
		if (::Set_Camera_Host_Network == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			::Set_Camera_Host_Network(nullptr);
		}
		else
		{
			::Set_Camera_Host_Network(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
		}
	}

	uint32 Engine::GetPathfindDistance(Vector3 start, Vector3 dest, PathfindDistanceDelegate ^callback, ISmartGameObj ^pathObj, Object ^data)
	{
		return GetPathfindDistanceAsync(pathObj, dest, callback, data);
	}

	uint32 Engine::GetPathfindDistance(Vector3 start, Vector3 dest, PathfindDistanceDelegate^ callback, ISmartGameObj^ pathObj)
	{
#pragma warning(push)
#pragma warning(disable : 4947)
		return GetPathfindDistance(start, dest, callback, pathObj, nullptr);
#pragma warning(pop) 
	}

	uint32 Engine::GetPathfindDistanceAsync(ISmartGameObj^ pathObj, Vector3 dest, PathfindDistanceDelegate^ callback, Object^ data)
	{
		if (::Get_Pathfind_Distance_Async == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (callback == nullptr)
		{
			throw gcnew ArgumentNullException("callback");
		}
		else if (pathObj == nullptr || pathObj->SmartGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("pathObj");
		}

		::Vector3 destVec;

		Vector3::ManagedToUnmanagedVector3(dest, destVec);

		uint32* managedId = Imports::CreateUInt32();
		uint32 storedManagedId = currentPathfindDistanceRequestId++;
		try
		{
			(*managedId) = storedManagedId;
			PathfindDistanceRequest^ newRequest = gcnew PathfindDistanceRequest(callback, data);

			pathfindDistanceRequests->Add(storedManagedId, newRequest);

			uint32 unmanagedId = ::Get_Pathfind_Distance_Async(
				reinterpret_cast<::SmartGameObj*>(pathObj->SmartGameObjPointer.ToPointer()),
				destVec,
				reinterpret_cast<::PathfindDistanceCallback>(Marshal::GetFunctionPointerForDelegate(internalPathfindCallbackDelegate).ToPointer()),			
				managedId);

			newRequest->UnmanagedId = unmanagedId;

			if (unmanagedId == 0)
			{
				// Just to make sure there isnt any double deletion
				if (pathfindDistanceRequests->Remove(storedManagedId))
				{
					Imports::DestroyUInt32(managedId);
					managedId = nullptr;
				}
			}

			return storedManagedId;
		}
		catch (Exception^)
		{
			// It might've called the delegate already, prevent double deletion
			if (pathfindDistanceRequests->Remove(storedManagedId))
			{
				Imports::DestroyUInt32(managedId);
				managedId = nullptr;
			}

			throw;
		}
	}

	uint32 Engine::GetPathfindDistanceAsync(ISmartGameObj^ pathObj, Vector3 dest, PathfindDistanceDelegate^ callback)
	{
		return GetPathfindDistanceAsync(pathObj, dest, callback, nullptr);
	}

	bool Engine::GetPathfindDistanceBlocking(ISmartGameObj^ pathObj, Vector3 dest, [Out] float% distanceResult, [Out] PathfindDistanceResult% pathfindResult)
	{
		if (::Get_Pathfind_Distance_Blocking == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}
		else if (pathObj == nullptr || pathObj->SmartGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("pathObj");
		}

		::Vector3 destVec;

		Vector3::ManagedToUnmanagedVector3(dest, destVec);

		float tmpDistanceResult;
		::PathfindDistanceResult tmpPathfindResult;

		bool result = ::Get_Pathfind_Distance_Blocking(
			reinterpret_cast<::SmartGameObj*>(pathObj->SmartGameObjPointer.ToPointer()),
			destVec,
			tmpDistanceResult,
			tmpPathfindResult);

		distanceResult = tmpDistanceResult;
		pathfindResult = static_cast<PathfindDistanceResult>(tmpPathfindResult);

		return result;
	}

	bool Engine::CancelGetPathfindDistance(uint32 id)
	{
		if (::Cancel_Get_Pathfind_Distance == nullptr)
		{
			throw gcnew NotSupportedException("Pointer to function is null.");
		}

		return ::Cancel_Get_Pathfind_Distance(id);
	}

	void Engine::KillAllBuildingsByTeam(int team)
	{
		::Kill_All_Buildings_By_Team(team);
	}

	void Engine::SetOccupantsFade(IScriptableGameObj ^obj, Color color)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Occupants_Fade(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			color.R / 255.0f,
			color.G / 255.0f,
			color.B / 255.0f,
			color.A / 255.0f);
	}

	void Engine::EnableTeamRadar(int team, bool enable)
	{
		::Enable_Team_Radar(team, enable);
	}

	void Engine::CreateSoundTeam(String ^soundName, Vector3 position, IScriptableGameObj ^obj, int team)
	{
		if (soundName == nullptr)
		{
			throw gcnew ArgumentNullException("soundName");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		IntPtr soundNameHandle = Marshal::StringToHGlobalAnsi(soundName);
		try
		{
			::Create_Sound_Team(
				reinterpret_cast<char *>(soundNameHandle.ToPointer()),
				positionVec,
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				team);
		}
		finally
		{
			Marshal::FreeHGlobal(soundNameHandle);
		}
	}

	void Engine::Create2DSoundTeam(String ^soundName, int team)
	{
		if (soundName == nullptr)
		{
			throw gcnew ArgumentNullException("soundName");
		}

		IntPtr soundNameHandle = Marshal::StringToHGlobalAnsi(soundName);
		try
		{
			::Create_2D_Sound_Team(
				reinterpret_cast<char *>(soundNameHandle.ToPointer()),
				team);
		}
		finally
		{
			Marshal::FreeHGlobal(soundNameHandle);
		}
	}

	void Engine::Create2DWAVSoundTeam(String ^soundName, int team)
	{
		if (soundName == nullptr)
		{
			throw gcnew ArgumentNullException("soundName");
		}

		IntPtr soundNameHandle = Marshal::StringToHGlobalAnsi(soundName);
		try
		{
			::Create_2D_WAV_Sound_Team(
				reinterpret_cast<char *>(soundNameHandle.ToPointer()),
				team);
		}
		finally
		{
			Marshal::FreeHGlobal(soundNameHandle);
		}
	}

	void Engine::Create2DWAVSoundTeamDialog(String ^soundName, int team)
	{
		if (soundName == nullptr)
		{
			throw gcnew ArgumentNullException("soundName");
		}

		IntPtr soundNameHandle = Marshal::StringToHGlobalAnsi(soundName);
		try
		{
			::Create_2D_WAV_Sound_Team_Dialog(
				reinterpret_cast<char *>(soundNameHandle.ToPointer()),
				team);
		}
		finally
		{
			Marshal::FreeHGlobal(soundNameHandle);
		}
	}

	void Engine::Create2DWAVSoundTeamCinematic(String^ soundName, int team)
	{
		if (soundName == nullptr)
		{
			throw gcnew ArgumentNullException("soundName");
		}

		IntPtr soundNameHandle = Marshal::StringToHGlobalAnsi(soundName);
		try
		{
			::Create_2D_WAV_Sound_Team_Cinematic(
				reinterpret_cast<char*>(soundNameHandle.ToPointer()),
				team);
		}
		finally
		{
			Marshal::FreeHGlobal(soundNameHandle);
		}
	}

	void Engine::Create3DWAVSoundAtBoneTeam(String ^soundName, IScriptableGameObj ^obj, String ^boneName, int team)
	{
		if (soundName == nullptr)
		{
			throw gcnew ArgumentNullException("soundName");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (boneName == nullptr)
		{
			throw gcnew ArgumentNullException("boneName");
		}

		IntPtr soundNameHandle = Marshal::StringToHGlobalAnsi(soundName);
		try
		{
			IntPtr boneNameHandle = Marshal::StringToHGlobalAnsi(boneName);
			try
			{
				::Create_3D_WAV_Sound_At_Bone_Team(
					reinterpret_cast<char *>(soundNameHandle.ToPointer()),
					reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
					reinterpret_cast<char *>(boneNameHandle.ToPointer()),
					team);
			}
			finally
			{
				Marshal::FreeHGlobal(boneNameHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(soundNameHandle);
		}
	}

	void Engine::Create3DSoundAtBoneTeam(String ^soundName, IScriptableGameObj ^obj, String ^boneName, int team)
	{
		if (soundName == nullptr)
		{
			throw gcnew ArgumentNullException("soundName");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (boneName == nullptr)
		{
			throw gcnew ArgumentNullException("boneName");
		}

		IntPtr soundNameHandle = Marshal::StringToHGlobalAnsi(soundName);
		try
		{
			IntPtr boneNameHandle = Marshal::StringToHGlobalAnsi(boneName);
			try
			{
				::Create_3D_Sound_At_Bone_Team(
					reinterpret_cast<char *>(soundNameHandle.ToPointer()),
					reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
					reinterpret_cast<char *>(boneNameHandle.ToPointer()),
					team);
			}
			finally
			{
				Marshal::FreeHGlobal(boneNameHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(soundNameHandle);
		}
	}

	void Engine::SendMessageTeam(int team, Color color, String ^msg)
	{
		if (msg == nullptr)
		{
			throw gcnew ArgumentNullException("msg");
		}

		IntPtr msgHandle = Marshal::StringToHGlobalAnsi(msg);
		try
		{
			::Send_Message_Team(
				team,
				color.R,
				color.G,
				color.B,
				reinterpret_cast<char *>(msgHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(msgHandle);
		}
	}

	void Engine::SendMessageWithObjColor(IScriptableGameObj ^obj, String ^msg)
	{
		if (msg == nullptr)
		{
			throw gcnew ArgumentNullException("msg");
		}

		IntPtr msgHandle = Marshal::StringToHGlobalAnsi(msg);
		try
		{
			if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
			{
				::Send_Message_With_Obj_Color(
					nullptr,
					reinterpret_cast<char *>(msgHandle.ToPointer()));
			}
			else
			{
				::Send_Message_With_Obj_Color(
					reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
					reinterpret_cast<char *>(msgHandle.ToPointer()));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(msgHandle);
		}
	}

	void Engine::SendMessageWithTeamColor(int team, String ^msg)
	{
		if (msg == nullptr)
		{
			throw gcnew ArgumentNullException("msg");
		}

		IntPtr msgHandle = Marshal::StringToHGlobalAnsi(msg);
		try
		{
			::Send_Message_With_Team_Color(
				team,
				reinterpret_cast<char *>(msgHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(msgHandle);
		}
	}

	void Engine::RangedGapEffect(IGapListNode ^firstNode)
	{
		if (firstNode == nullptr || firstNode->GapListNodePointer.ToPointer() == nullptr)
		{
			::Ranged_Gap_Effect(nullptr);
		}
		else
		{
			::Ranged_Gap_Effect(
				reinterpret_cast<::Gap_ListNode *>(firstNode->GapListNodePointer.ToPointer()));
		}
	}

	void Engine::RangedGapEffect(GapListNode ^firstNode)
	{
		if (firstNode == nullptr)
		{
			::Ranged_Gap_Effect(nullptr);
		}
		else
		{
			auto tmp = GapListNodeRef::CreateGapListNodeRef(firstNode);
			try
			{
				::Ranged_Gap_Effect(
					reinterpret_cast<::Gap_ListNode *>(tmp->UnmanagedObject->GapListNodePointer.ToPointer()));
			}
			finally
			{
#pragma push_macro("delete")
#undef delete

				delete tmp;
				tmp = nullptr;

#pragma pop_macro("delete")
			}
		}
	}

	void Engine::RangedStealthOnTeam(IGapListNode ^firstNode)
	{
		if (firstNode == nullptr || firstNode->GapListNodePointer.ToPointer() == nullptr)
		{
			::Ranged_Stealth_On_Team(nullptr);
		}
		else
		{
			::Ranged_Stealth_On_Team(
				reinterpret_cast<::Gap_ListNode *>(firstNode->GapListNodePointer.ToPointer()));
		}
	}

	void Engine::RangedStealthOnTeam(GapListNode ^firstNode)
	{
		if (firstNode == nullptr)
		{
			::Ranged_Stealth_On_Team(nullptr);
		}
		else
		{
			auto tmp = GapListNodeRef::CreateGapListNodeRef(firstNode);
			try
			{
				::Ranged_Stealth_On_Team(
					reinterpret_cast<::Gap_ListNode *>(tmp->UnmanagedObject->GapListNodePointer.ToPointer()));
			}
			finally
			{
#pragma push_macro("delete")
#undef delete

				delete tmp;
				tmp = nullptr;

#pragma pop_macro("delete")
			}
		}
	}

	bool Engine::CanTeamBuildVehicle(int team)
	{
		return ::Can_Team_Build_Vehicle(team);
	}

	void Engine::SendShaderParam(String ^parameter, String ^value)
	{
		if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}
		else if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
			try
			{
				::SendShaderParam(
					reinterpret_cast<char *>(parameterHandle.ToPointer()),
					reinterpret_cast<char *>(valueHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(valueHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParam(String ^parameter, int value)
	{
		if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			::SendShaderParam(
				reinterpret_cast<char *>(parameterHandle.ToPointer()),
				value);
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParam(String ^parameter, unsigned int value)
	{
		if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			::SendShaderParam(
				reinterpret_cast<char *>(parameterHandle.ToPointer()),
				value);
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParam(String ^parameter, float value)
	{
		if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			::SendShaderParam(
				reinterpret_cast<char *>(parameterHandle.ToPointer()),
				value);
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParam(String ^parameter, Vector2 value)
	{
		if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			::Vector2 valueVec;

			Vector2::ManagedToUnmanagedVector2(value, valueVec);

			::SendShaderParam(
				reinterpret_cast<char *>(parameterHandle.ToPointer()),
				valueVec);
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParam(String ^parameter, Vector3 value)
	{
		if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			::Vector3 valueVec;

			Vector3::ManagedToUnmanagedVector3(value, valueVec);

			::SendShaderParam(
				reinterpret_cast<char *>(parameterHandle.ToPointer()),
				valueVec);
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParam(String ^parameter, Vector4 value)
	{
		if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			::Vector4 valueVec;

			Vector4::ManagedToUnmanagedVector4(value, valueVec);

			::SendShaderParam(
				reinterpret_cast<char *>(parameterHandle.ToPointer()),
				valueVec);
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParamPlayer(IScriptableGameObj ^player, String ^parameter, String ^value)
	{
		if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}
		else if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
			try
			{
				::SendShaderParamPlayer(
					reinterpret_cast<::ScriptableGameObj *>(player->ScriptableGameObjPointer.ToPointer()),
					reinterpret_cast<char *>(parameterHandle.ToPointer()),
					reinterpret_cast<char *>(valueHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(valueHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParamPlayer(IScriptableGameObj ^player, String ^parameter, int value)
	{
		if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			::SendShaderParamPlayer(
				reinterpret_cast<::ScriptableGameObj *>(player->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(parameterHandle.ToPointer()),
				value);
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParamPlayer(IScriptableGameObj ^player, String ^parameter, unsigned int value)
	{
		if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			::SendShaderParamPlayer(
				reinterpret_cast<::ScriptableGameObj *>(player->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(parameterHandle.ToPointer()),
				value);
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParamPlayer(IScriptableGameObj ^player, String ^parameter, float value)
	{
		if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			::SendShaderParamPlayer(
				reinterpret_cast<::ScriptableGameObj *>(player->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(parameterHandle.ToPointer()),
				value);
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParamPlayer(IScriptableGameObj ^player, String ^parameter, Vector2 value)
	{
		if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			::Vector2 valueVec;

			Vector2::ManagedToUnmanagedVector2(value, valueVec);

			::SendShaderParamPlayer(
				reinterpret_cast<::ScriptableGameObj *>(player->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(parameterHandle.ToPointer()),
				valueVec);
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParamPlayer(IScriptableGameObj ^player, String ^parameter, Vector3 value)
	{
		if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			::Vector3 valueVec;

			Vector3::ManagedToUnmanagedVector3(value, valueVec);

			::SendShaderParamPlayer(
				reinterpret_cast<::ScriptableGameObj *>(player->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(parameterHandle.ToPointer()),
				valueVec);
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParamPlayer(IScriptableGameObj ^player, String ^parameter, Vector4 value)
	{
		if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			::Vector4 valueVec;

			Vector4::ManagedToUnmanagedVector4(value, valueVec);

			::SendShaderParamPlayer(
				reinterpret_cast<::ScriptableGameObj *>(player->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(parameterHandle.ToPointer()),
				valueVec);
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParamObj(String ^parameter, String ^value, IScriptableGameObj ^object)
	{
		if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}
		else if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
			try
			{
				::SendShaderParamObj(
					reinterpret_cast<char *>(parameterHandle.ToPointer()),
					reinterpret_cast<char *>(valueHandle.ToPointer()),
					reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(valueHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParamObj(String ^parameter, int value, IScriptableGameObj ^object)
	{
		if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			::SendShaderParamObj(
				reinterpret_cast<char *>(parameterHandle.ToPointer()),
				value,
				reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParamObj(String ^parameter, unsigned int value, IScriptableGameObj ^object)
	{
		if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			::SendShaderParamObj(
				reinterpret_cast<char *>(parameterHandle.ToPointer()),
				value,
				reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParamObj(String ^parameter, float value, IScriptableGameObj ^object)
	{
		if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			::SendShaderParamObj(
				reinterpret_cast<char *>(parameterHandle.ToPointer()),
				value,
				reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParamObj(String ^parameter, Vector2 value, IScriptableGameObj ^object)
	{
		if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			::Vector2 valueVec;

			Vector2::ManagedToUnmanagedVector2(value, valueVec);

			::SendShaderParamObj(
				reinterpret_cast<char *>(parameterHandle.ToPointer()),
				valueVec,
				reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParamObj(String ^parameter, Vector3 value, IScriptableGameObj ^object)
	{
		if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			::Vector3 valueVec;

			Vector3::ManagedToUnmanagedVector3(value, valueVec);

			::SendShaderParamObj(
				reinterpret_cast<char *>(parameterHandle.ToPointer()),
				valueVec,
				reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParamObj(String ^parameter, Vector4 value, IScriptableGameObj ^object)
	{
		if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			::Vector4 valueVec;

			Vector4::ManagedToUnmanagedVector4(value, valueVec);

			::SendShaderParamObj(
				reinterpret_cast<char *>(parameterHandle.ToPointer()),
				valueVec,
				reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParamObjPlayer(IScriptableGameObj ^player, String ^parameter, String ^value, IScriptableGameObj ^object)
	{
		if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}
		else if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
			try
			{
				::SendShaderParamObjPlayer(
					reinterpret_cast<::ScriptableGameObj *>(player->ScriptableGameObjPointer.ToPointer()),
					reinterpret_cast<char *>(parameterHandle.ToPointer()),
					reinterpret_cast<char *>(valueHandle.ToPointer()),
					reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(valueHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParamObjPlayer(IScriptableGameObj ^player, String ^parameter, int value, IScriptableGameObj ^object)
	{
		if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			::SendShaderParamObjPlayer(
				reinterpret_cast<::ScriptableGameObj *>(player->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(parameterHandle.ToPointer()),
				value,
				reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParamObjPlayer(IScriptableGameObj ^player, String ^parameter, unsigned int value, IScriptableGameObj ^object)
	{
		if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			::SendShaderParamObjPlayer(
				reinterpret_cast<::ScriptableGameObj *>(player->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(parameterHandle.ToPointer()),
				value,
				reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParamObjPlayer(IScriptableGameObj ^player, String ^parameter, float value, IScriptableGameObj ^object)
	{
		if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			::SendShaderParamObjPlayer(
				reinterpret_cast<::ScriptableGameObj *>(player->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(parameterHandle.ToPointer()),
				value,
				reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParamObjPlayer(IScriptableGameObj ^player, String ^parameter, Vector2 value, IScriptableGameObj ^object)
	{
		if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			::Vector2 valueVec;

			Vector2::ManagedToUnmanagedVector2(value, valueVec);

			::SendShaderParamObjPlayer(
				reinterpret_cast<::ScriptableGameObj *>(player->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(parameterHandle.ToPointer()),
				valueVec,
				reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParamObjPlayer(IScriptableGameObj ^player, String ^parameter, Vector3 value, IScriptableGameObj ^object)
	{
		if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			::Vector3 valueVec;

			Vector3::ManagedToUnmanagedVector3(value, valueVec);

			::SendShaderParamObjPlayer(
				reinterpret_cast<::ScriptableGameObj *>(player->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(parameterHandle.ToPointer()),
				valueVec,
				reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::SendShaderParamObjPlayer(IScriptableGameObj ^player, String ^parameter, Vector4 value, IScriptableGameObj ^object)
	{
		if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (parameter == nullptr)
		{
			throw gcnew ArgumentNullException("parameter");
		}
		else if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr parameterHandle = Marshal::StringToHGlobalAnsi(parameter);
		try
		{
			::Vector4 valueVec;

			Vector4::ManagedToUnmanagedVector4(value, valueVec);

			::SendShaderParamObjPlayer(
				reinterpret_cast<::ScriptableGameObj *>(player->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(parameterHandle.ToPointer()),
				valueVec,
				reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(parameterHandle);
		}
	}

	void Engine::DeleteConsoleFunction(String ^name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			::Delete_Console_Function(
				reinterpret_cast<char *>(nameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	void Engine::SortFunctionList()
	{
		::Sort_Function_List();
	}

	void Engine::VerboseHelpFile()
	{
		::Verbose_Help_File();
	}

	void Engine::SendTranslatedMessageTeam(unsigned long id, int team, Color color, bool bPlaySound)
	{
		::Send_Translated_Message_Team(
			id,
			team,
			color.R,
			color.G,
			color.B,
			bPlaySound);
	}

	void Engine::SendTranslatedMessageTeam(unsigned long id, int team, Color color)
	{
		::Send_Translated_Message_Team(
			id,
			team,
			color.R,
			color.G,
			color.B);
	}

	void Engine::ForceVehicleEntry(IScriptableGameObj ^soldier, IScriptableGameObj ^vehicle)
	{
		if (soldier == nullptr || soldier->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}
		else if (vehicle == nullptr || vehicle->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("vehicle");
		}

		::Force_Vehicle_Entry(
			reinterpret_cast<::ScriptableGameObj *>(soldier->ScriptableGameObjPointer.ToPointer()),
			reinterpret_cast<::ScriptableGameObj *>(vehicle->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::DestroyAllObjectsWithScript(String^ script)
	{
		if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			::Destroy_All_Objects_With_Script(
				reinterpret_cast<char*>(scriptHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	bool Engine::HasBeacon(IArmedGameObj^ obj)
	{
		if (obj == nullptr || obj->ArmedGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Has_Beacon(
			reinterpret_cast<::ArmedGameObj*>(obj->ArmedGameObjPointer.ToPointer()));
	}

	float Engine::GetDistanceToClosestBeacon(Vector3 position, int team)
	{
		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		return ::Get_Distance_To_Closest_Beacon(positionVec, team);
	}

	float Engine::GetDistanceToClosestBuilding(Vector3 position, int team)
	{
		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		return ::Get_Distance_To_Closest_Building(positionVec, team);
	}

	float Engine::GetDistanceToClosestPCT(Vector3 position, int team)
	{
		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		return ::Get_Distance_To_Closest_PCT(positionVec, team);
	}

	float Engine::GetDistanceToClosestPlayer(Vector3 position, int team)
	{
		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		return ::Get_Distance_To_Closest_Player(positionVec, team);
	}

	float Engine::GetDistanceToClosestPlayer(Vector3 position)
	{
		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		return ::Get_Distance_To_Closest_Player(positionVec);
	}

	IBuildingGameObj^ Engine::GetClosestBuilding(Vector3 position, int team)
	{
		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		auto result = ::Get_Closest_Building(positionVec, team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IBuildingGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IPhysicalGameObj^ Engine::GetClosestFakeBuilding(Vector3 position, int team)
	{
		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		auto result = ::Get_Closest_Fake_Building(positionVec, team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IPhysicalGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IBuildingGameObj^ Engine::GetRandomBuilding(int team)
	{
		auto result = ::Get_Random_Building(team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IBuildingGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	void Engine::SendCustomEventVehicleOccupants(IScriptableGameObj^ obj, IScriptableGameObj^ sender, int message, int param, float delay, bool driver)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::ScriptableGameObj* senderPtr;
		if (sender == nullptr || sender->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			senderPtr = nullptr;
		}
		else
		{
			senderPtr = reinterpret_cast<::ScriptableGameObj*>(sender->ScriptableGameObjPointer.ToPointer());
		}

		::Send_Custom_Event_Vehicle_Occupants(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
			senderPtr,
			message,
			param,
			delay,
			driver);
	}

	void Engine::DisarmClosestBeacon(Vector3 pos, int team)
	{
		::Vector3 posVec;

		Vector3::ManagedToUnmanagedVector3(pos, posVec);

		::Disarm_Closest_Beacon(posVec, team);
	}

	void Engine::DisarmAllBeaconsTeam(int team)
	{
		::Disarm_All_Beacons_Team(team);
	}

	void Engine::DisarmAllBeaconsPlayer(IScriptableGameObj^ player)
	{
		if (player == nullptr || player->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		::Disarm_All_Beacons_Player(
			reinterpret_cast<::ScriptableGameObj*>(player->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::PlayAnimationAllPlayers(String^ anim)
	{
		if (anim == nullptr)
		{
			::Play_Animation_All_Players(nullptr);
		}
		else
		{
			IntPtr animHandle = Marshal::StringToHGlobalAnsi(anim);
			try
			{
				::Play_Animation_All_Players(
					reinterpret_cast<char*>(animHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(animHandle);
			}
		}
	}

	int Engine::FindEmptyVehicleSeat(IVehicleGameObj^ obj, bool allowDriver)
	{
		if (obj == nullptr || obj->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Find_Empty_Vehicle_Seat(
			reinterpret_cast<::VehicleGameObj*>(obj->VehicleGameObjPointer.ToPointer()), allowDriver);
	}

	int Engine::FindEmptyVehicleSeat(IVehicleGameObj^ obj)
	{
		if (obj == nullptr || obj->VehicleGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Find_Empty_Vehicle_Seat(
			reinterpret_cast<::VehicleGameObj*>(obj->VehicleGameObjPointer.ToPointer()));
	}

	void Engine::ChangeTeam3(IcPlayer^ player, int team)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		::Change_Team_3(
			reinterpret_cast<::cPlayer *>(player->cPlayerPointer.ToPointer()),
			team);
	}

	void Engine::ChangeTeam4(IcPlayer^ player, int team)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		::Change_Team_4(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
			team);
	}

	void Engine::ChangeTeam5(IcPlayer^ player, int team)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		::Change_Team_5(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
			team);
	}

	IcPlayer^ Engine::MatchPlayer(IcPlayer^ player, String^ nick, bool teamOnly, bool allowSelf)
	{
		if (nick == nullptr)
		{
			throw gcnew ArgumentNullException("nick");
		}

		IntPtr nickHandle = Marshal::StringToHGlobalAnsi(nick);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(nickHandle.ToPointer()));

			::cPlayer* playerPtr;
			if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
			{
				playerPtr = nullptr;
			}
			else
			{
				playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
			}

			auto result = ::Match_Player(
				playerPtr,
				tmp,
				teamOnly,
				allowSelf);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew cPlayer(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nickHandle);
		}
	}

	IcPlayer^ Engine::MatchPlayer(IcPlayer^ player, String^ nick, bool teamOnly)
	{
		if (nick == nullptr)
		{
			throw gcnew ArgumentNullException("nick");
		}

		IntPtr nickHandle = Marshal::StringToHGlobalAnsi(nick);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(nickHandle.ToPointer()));

			::cPlayer* playerPtr;
			if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
			{
				playerPtr = nullptr;
			}
			else
			{
				playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
			}

			auto result = ::Match_Player(
				playerPtr,
				tmp,
				teamOnly);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew cPlayer(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nickHandle);
		}
	}

	IcPlayer^ Engine::MatchPlayer(IcPlayer^ player, String^ nick)
	{
		if (nick == nullptr)
		{
			throw gcnew ArgumentNullException("nick");
		}

		IntPtr nickHandle = Marshal::StringToHGlobalAnsi(nick);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(nickHandle.ToPointer()));

			::cPlayer* playerPtr;
			if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
			{
				playerPtr = nullptr;
			}
			else
			{
				playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
			}

			auto result = ::Match_Player(
				playerPtr,
				tmp);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew cPlayer(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nickHandle);
		}
	}

	void Engine::DamageObjectsHalfNoKill()
	{
		::Damage_Objects_Half_No_Kill();
	}

	void Engine::AttachScriptToDefinition(String^ preset, String^ script, String^ params)
	{
		if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}
		else if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}
		else if (params == nullptr)
		{
			throw gcnew ArgumentNullException("params");
		}

		IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
			try
			{
				IntPtr paramsHandle = Marshal::StringToHGlobalAnsi(params);
				try
				{
					::Attach_Script_To_Definition(
						reinterpret_cast<char*>(presetHandle.ToPointer()),
						reinterpret_cast<char*>(scriptHandle.ToPointer()),
						reinterpret_cast<char*>(paramsHandle.ToPointer()));
				}
				finally
				{
					Marshal::FreeHGlobal(paramsHandle);
				}
			}
			finally
			{
				Marshal::FreeHGlobal(scriptHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(presetHandle);
		}
	}

	void Engine::AttachScriptToDefinitions(unsigned long cID, String^ script, String^ params)
	{
		if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}
		else if (params == nullptr)
		{
			throw gcnew ArgumentNullException("params");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			IntPtr paramsHandle = Marshal::StringToHGlobalAnsi(params);
			try
			{
				::Attach_Script_To_Definitions(
					cID,
					reinterpret_cast<char*>(scriptHandle.ToPointer()),
					reinterpret_cast<char*>(paramsHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(paramsHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	void Engine::RemoveScriptFromDefinition(String^ preset, String^ script)
	{
		if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}
		else if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
			try
			{
				::Remove_Script_From_Definition(
					reinterpret_cast<char*>(presetHandle.ToPointer()),
					reinterpret_cast<char*>(scriptHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(scriptHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(presetHandle);
		}
	}

	void Engine::RemoveScriptFromDefinitions(unsigned long cID, String^ script)
	{
		if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			::Remove_Script_From_Definitions(
				cID,
				reinterpret_cast<char*>(scriptHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	void Engine::SetObjectTypePreset(String^ preset, int team)
	{
		if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			::Set_Object_Type_Preset(
				reinterpret_cast<char*>(presetHandle.ToPointer()),
				team);
		}
		finally
		{
			Marshal::FreeHGlobal(presetHandle);
		}
	}

	IcTeam^ Engine::FindTeam(int team)
	{
		auto result = ::Internal_Find_Team_Wrapper(team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cTeam(IntPtr(result));
		}
	}

	void Engine::GiveCreditsTeam(int team, float credits)
	{
		::Give_Credits_Team(team, credits);
	}

	void Engine::GivePointsPlayersInRange(Vector3 position, float range, float points, bool giveMoney)
	{
		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		::Give_Points_Players_In_Range(
			positionVec,
			range,
			points,
			giveMoney);
	}

	void Engine::GivePointsPlayersInRange(Vector3 position, float range, float points)
	{
		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		::Give_Points_Players_In_Range(
			positionVec,
			range,
			points);
	}

	void Engine::GivePointsPlayersInRangeTeam(int team, Vector3 position, float range, float points, bool giveMoney)
	{
		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		::Give_Points_Players_In_Range_Team(
			team,
			positionVec,
			range,
			points,
			giveMoney);
	}

	void Engine::GivePointsPlayersInRangeTeam(int team, Vector3 position, float range, float points)
	{
		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		::Give_Points_Players_In_Range_Team(
			team,
			positionVec,
			range,
			points);
	}

	String^ Engine::EncryptApgar(String^ password)
	{
		if (password == nullptr)
		{
			throw gcnew ArgumentNullException("password");
		}

		IntPtr passwordHandle = Marshal::StringToHGlobalAnsi(password);
		try
		{
			return gcnew String(::Encrypt_Apgar(
				reinterpret_cast<char*>(passwordHandle.ToPointer())).Peek_Buffer());
		}
		finally
		{
			Marshal::FreeHGlobal(passwordHandle);
		}
	}

	void Engine::SetFacingPlayer(IScriptableGameObj^ obj, float facing)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Facing_Player(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
			facing);
	}

	bool Engine::OverlapTest(IScriptableGameObj^ obj, Vector3 position, bool checkDynOnly)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		return ::Overlap_Test(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
			positionVec,
			checkDynOnly);
	}

	bool Engine::OverlapTest(IScriptableGameObj^ obj, Vector3 position)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		return ::Overlap_Test(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
			positionVec);
	}

	bool Engine::IsSimple(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Is_Simple(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool Engine::IsPowerup(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Is_Powerup(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool Engine::IsC4(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Is_C4(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool Engine::IsBeacon(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Is_Beacon(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool Engine::IsArmed(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Is_Armed(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool Engine::IsPowerPlant(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Is_PowerPlant(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool Engine::IsVehicleFactory(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Is_VehicleFactory(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool Engine::IsRefinery(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Is_Refinery(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool Engine::IsSoldierFactory(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Is_SoldierFactory(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool Engine::IsDecorationPhys(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Is_DecorationPhys(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool Engine::IsPlayer(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Is_Player(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool Engine::IsStealthUnit(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Is_Stealth_Unit(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	unsigned int Engine::GetGroundVehicleCount(int team)
	{
		return ::Get_Ground_Vehicle_Count(team);
	}

	unsigned int Engine::GetAirVehicleCount(int team)
	{
		return ::Get_Air_Vehicle_Count(team);
	}

	unsigned int Engine::GetNavalVehicleCount(int team)
	{
		return ::Get_Naval_Vehicle_Count(team);
	}

	void Engine::SetObjectDirtyBitForVersionGreaterThan(INetworkObjectClass^ obj, float version, DirtyBit bit, bool onOff)
	{
		if (obj == nullptr || obj->NetworkObjectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Object_Dirty_Bit_For_Version_Greater_Than(
			reinterpret_cast<::NetworkObjectClass*>(obj->NetworkObjectClassPointer.ToPointer()),
			version,
			static_cast<::NetworkObjectClass::DIRTY_BIT>(bit),
			onOff);
	}

	void Engine::SetObjectDirtyBitForVersionLessThan(INetworkObjectClass^ obj, float version, DirtyBit bit, bool onOff)
	{
		if (obj == nullptr || obj->NetworkObjectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Object_Dirty_Bit_For_Version_Less_Than(
			reinterpret_cast<::NetworkObjectClass*>(obj->NetworkObjectClassPointer.ToPointer()),
			version,
			static_cast<::NetworkObjectClass::DIRTY_BIT>(bit),
			onOff);
	}

	void Engine::SetObjectDirtyBitForTeamVersionGreaterThan(INetworkObjectClass^ obj, int team, float version, DirtyBit bit, bool onOff)
	{
		if (obj == nullptr || obj->NetworkObjectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Object_Dirty_Bit_For_Team_Version_Greater_Than(
			reinterpret_cast<::NetworkObjectClass*>(obj->NetworkObjectClassPointer.ToPointer()),
			team,
			version,
			static_cast<::NetworkObjectClass::DIRTY_BIT>(bit),
			onOff);
	}

	void Engine::SetObjectDirtyBitForTeamVersionLessThan(INetworkObjectClass^ obj, int team, float version, DirtyBit bit, bool onOff)
	{
		if (obj == nullptr || obj->NetworkObjectClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Object_Dirty_Bit_For_Team_Version_Less_Than(
			reinterpret_cast<::NetworkObjectClass*>(obj->NetworkObjectClassPointer.ToPointer()),
			team,
			version,
			static_cast<::NetworkObjectClass::DIRTY_BIT>(bit),
			onOff);
	}

#pragma managed(push, off)

static ::WideStringClass NickSave;
static ::cPlayer* NickSavePlayer = nullptr;

#pragma managed(pop)

	int Engine::SetupSendMessageFake(String^ newNick, int id)
	{
		// Original does not support wide string
		if (newNick == nullptr)
		{
			throw gcnew ArgumentNullException("newNick");
		}

		IntPtr newNickHandle = Marshal::StringToHGlobalUni(newNick);
		try
		{
			for (::SLNode<::cPlayer>* z = ::Get_Player_List()->Head(); z; z = z->Next()) 
			{
				::cPlayer* player = z->Data();
				if (player->Is_Active()) 
				{
					NickSave = player->Get_Name();
					NickSavePlayer = player;
					player->PlayerName = reinterpret_cast<wchar_t*>(newNickHandle.ToPointer());
					if (id) 
					{
						player->Set_Object_Dirty_Bit(id, ::NetworkObjectClass::BIT_CREATION, true);
						::Update_Network_Object(player);
					}
					else 
					{
						::Set_Object_Dirty_Bit_For_Version_Less_Than(player, 2.6f, ::NetworkObjectClass::BIT_CREATION, true);
						::Update_Network_Object(player);
					}

					return player->Get_Id();
				}
			}

			return 0;
		}
		finally
		{
			Marshal::FreeHGlobal(newNickHandle);
		}
	}

	int Engine::SetupSendMessageFake(String^ newNick)
	{
		// Original does not support wide string
		return SetupSendMessageFake(newNick, 0);
	}

	int Engine::SetupSendMessageTeamFake(String^ newNick, int team, int id)
	{
		// Original does not support wide string
		if (newNick == nullptr)
		{
			throw gcnew ArgumentNullException("newNick");
		}

		IntPtr newNickHandle = Marshal::StringToHGlobalUni(newNick);
		try
		{
			for (::SLNode<::cPlayer>* z = ::Get_Player_List()->Head(); z; z = z->Next())
			{
				::cPlayer* player = z->Data();
				if (player->Is_Active() && player->Get_Player_Type() == team) 
				{
					NickSave = player->Get_Name();
					NickSavePlayer = player;
					player->PlayerName = reinterpret_cast<wchar_t*>(newNickHandle.ToPointer());
					if (id)
					{
						player->Set_Object_Dirty_Bit(id, ::NetworkObjectClass::BIT_CREATION, true);
						::Update_Network_Object(player);
					}
					else
					{
						::Set_Object_Dirty_Bit_For_Version_Less_Than(player, 2.6f, ::NetworkObjectClass::BIT_CREATION, true);
						::Update_Network_Object(player);
					}

					return player->Get_Id();
				}
			}

			return 0;
		}
		finally
		{
			Marshal::FreeHGlobal(newNickHandle);
		}
	}

	int Engine::SetupSendMessageTeamFake(String^ newNick, int team)
	{
		// Original does not support wide string
		return SetupSendMessageTeamFake(newNick, team, 0);
	}

	void Engine::RestoreSendMessageFake()
	{
		// Original does not support wide string
		if (NickSavePlayer) 
		{
			NickSavePlayer->PlayerName = NickSave;
			::Set_Object_Dirty_Bit_For_Version_Less_Than(NickSavePlayer, 2.6f, ::NetworkObjectClass::BIT_CREATION, true);
			::Update_Network_Object(NickSavePlayer);
			::DAEventManager::Name_Change_Event(NickSavePlayer);
			NickSavePlayer = nullptr;
		}
	}

	void Engine::SendAnnouncement(String^ stringID)
	{
		if (stringID == nullptr)
		{
			throw gcnew ArgumentNullException("stringID");
		}

		IntPtr stringIDHandle = Marshal::StringToHGlobalAnsi(stringID);
		try
		{
			::Send_Announcement(
				reinterpret_cast<char*>(stringIDHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(stringIDHandle);
		}
	}

	void Engine::SendAnnouncementVersionLessThan(String^ stringID, float version)
	{
		if (stringID == nullptr)
		{
			throw gcnew ArgumentNullException("stringID");
		}

		IntPtr stringIDHandle = Marshal::StringToHGlobalAnsi(stringID);
		try
		{
			::Send_Announcement_Version_Less_Than(
				reinterpret_cast<char*>(stringIDHandle.ToPointer()),
				version);
		}
		finally
		{
			Marshal::FreeHGlobal(stringIDHandle);
		}
	}

	void Engine::SendAnnouncementPlayer(int id, String^ stringID)
	{
		if (stringID == nullptr)
		{
			throw gcnew ArgumentNullException("stringID");
		}

		IntPtr stringIDHandle = Marshal::StringToHGlobalAnsi(stringID);
		try
		{
			::Send_Announcement_Player(
				id,
				reinterpret_cast<char*>(stringIDHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(stringIDHandle);
		}
	}

	void Engine::SendAnnouncementPlayerVersionLessThan(int id, String^ stringID, float version)
	{
		if (stringID == nullptr)
		{
			throw gcnew ArgumentNullException("stringID");
		}

		IntPtr stringIDHandle = Marshal::StringToHGlobalAnsi(stringID);
		try
		{
			::Send_Announcement_Player_Version_Less_Than(
				id,
				reinterpret_cast<char*>(stringIDHandle.ToPointer()),
				version);
		}
		finally
		{
			Marshal::FreeHGlobal(stringIDHandle);
		}
	}

	void Engine::SendAnnouncementTeam(int team, String^ stringID)
	{
		if (stringID == nullptr)
		{
			throw gcnew ArgumentNullException("stringID");
		}

		IntPtr stringIDHandle = Marshal::StringToHGlobalAnsi(stringID);
		try
		{
			::Send_Announcement_Team(
				team,
				reinterpret_cast<char*>(stringIDHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(stringIDHandle);
		}
	}

	void Engine::SendAnnouncementTeamVersionLessThan(int team, String^ stringID, float version)
	{
		if (stringID == nullptr)
		{
			throw gcnew ArgumentNullException("stringID");
		}

		IntPtr stringIDHandle = Marshal::StringToHGlobalAnsi(stringID);
		try
		{
			::Send_Announcement_Team_Version_Less_Than(
				team,
				reinterpret_cast<char*>(stringIDHandle.ToPointer()),
				version);
		}
		finally
		{
			Marshal::FreeHGlobal(stringIDHandle);
		}
	}

	void Engine::SendMessageTeamWithTeamColor(int team, String^ msg)
	{
		if (msg == nullptr)
		{
			throw gcnew ArgumentNullException("msg");
		}

		IntPtr msgHandle = Marshal::StringToHGlobalAnsi(msg);
		try
		{
			::Send_Message_Team_With_Team_Color(
				team,
				reinterpret_cast<char*>(msgHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(msgHandle);
		}
	}

	void Engine::SendMessagePlayerByID(int id, Color color, String^ message)
	{
		if (message == nullptr)
		{
			throw gcnew ArgumentNullException("msg");
		}

		IntPtr msgHandle = Marshal::StringToHGlobalAnsi(message);
		try
		{
			::Send_Message_Player_By_ID(
				id,
				color.R,
				color.G,
				color.B,
				reinterpret_cast<char*>(msgHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(msgHandle);
		}
	}

	void Engine::Create2DWAVSoundPlayerByID(int id, String^ sound)
	{
		if (sound == nullptr)
		{
			throw gcnew ArgumentNullException("sound");
		}

		IntPtr soundHandle = Marshal::StringToHGlobalAnsi(sound);
		try
		{
			::Create_2D_WAV_Sound_Player_By_ID(
				id,
				reinterpret_cast<char*>(soundHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(soundHandle);
		}
	}

	IPhysicalGameObj^ Engine::CreateObject(String^ preset, Vector3 position)
	{
		if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			auto result = ::Create_Object(
				reinterpret_cast<char*>(presetHandle.ToPointer()),
				positionVec);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return safe_cast<IPhysicalGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(presetHandle);
		}
	}

	IPhysicalGameObj^ Engine::CreateObject(String^ preset, Matrix3D transform)
	{
		if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		::Matrix3D transformMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(transform, transformMat);

		IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			auto result = ::Create_Object(
				reinterpret_cast<char*>(presetHandle.ToPointer()),
				transformMat);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return safe_cast<IPhysicalGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(presetHandle);
		}
	}

	IPhysicalGameObj^ Engine::CreateObject(int preset, Vector3 position)
	{
		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		auto result = ::Create_Object(
			preset,
			positionVec);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IPhysicalGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IPhysicalGameObj^ Engine::CreateObject(int preset, Matrix3D transform)
	{
		::Matrix3D transformMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(transform, transformMat);

		auto result = ::Create_Object(
			preset,
			transformMat);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IPhysicalGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IPhysicalGameObj^ Engine::CreateObject(IDefinitionClass^ def, Vector3 position)
	{
		if (def == nullptr || def->DefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("def");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		auto result = ::Create_Object(
			reinterpret_cast<::DefinitionClass*>(def->DefinitionClassPointer.ToPointer()),
			positionVec);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IPhysicalGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IPhysicalGameObj^ Engine::CreateObject(IDefinitionClass^ def, Matrix3D transform)
	{
		if (def == nullptr || def->DefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("def");
		}

		::Matrix3D transformMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(transform, transformMat);

		auto result = ::Create_Object(
			reinterpret_cast<::DefinitionClass*>(def->DefinitionClassPointer.ToPointer()),
			transformMat);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IPhysicalGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	ISoldierGameObj^ Engine::CreateCommando(IcPlayer^ player, String^ preset, Vector3 position)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			auto result = ::Create_Commando(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
				reinterpret_cast<char*>(presetHandle.ToPointer()),
				positionVec);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return safe_cast<ISoldierGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(presetHandle);
		}
	}

	ISoldierGameObj^ Engine::CreateCommando(IcPlayer^ player, String^ preset, Matrix3D transform)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		::Matrix3D transformMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(transform, transformMat);

		IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			auto result = ::Create_Commando(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
				reinterpret_cast<char*>(presetHandle.ToPointer()),
				transformMat);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return safe_cast<ISoldierGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(presetHandle);
		}
	}

	ISoldierGameObj^ Engine::CreateCommando(IcPlayer^ player, int preset, Vector3 position)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		auto result = ::Create_Commando(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
			preset,
			positionVec);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<ISoldierGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	ISoldierGameObj^ Engine::CreateCommando(IcPlayer^ player, int preset, Matrix3D transform)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		::Matrix3D transformMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(transform, transformMat);

		auto result = ::Create_Commando(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
			preset,
			transformMat);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<ISoldierGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	ISoldierGameObj^ Engine::CreateCommando(IcPlayer^ player, IDefinitionClass^ def, Vector3 position)
	{
		if (def == nullptr || def->DefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("def");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		auto result = ::Create_Commando(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
			reinterpret_cast<::DefinitionClass*>(def->DefinitionClassPointer.ToPointer()),
			positionVec);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<ISoldierGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	ISoldierGameObj^ Engine::CreateCommando(IcPlayer^ player, IDefinitionClass^ def, Matrix3D transform)
	{
		if (def == nullptr || def->DefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("def");
		}

		::Matrix3D transformMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(transform, transformMat);

		auto result = ::Create_Commando(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
			reinterpret_cast<::DefinitionClass*>(def->DefinitionClassPointer.ToPointer()),
			transformMat);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<ISoldierGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	void Engine::DisableBuildingType(int team, RenSharp::BuildingType type)
	{
		::Disable_Building_Type(team, static_cast<BuildingConstants::BuildingType>(type));
	}

	unsigned int Engine::GetHash(String^ string)
	{
		if (string == nullptr)
		{
			throw gcnew ArgumentNullException("string");
		}

		IntPtr stringHandle = Marshal::StringToHGlobalAnsi(string);
		try
		{
			return ::Get_Hash(
				reinterpret_cast<char*>(stringHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(stringHandle);
		}
	}

	bool Engine::IsStartingWeapon(ISoldierGameObjDef^ soldier, IPowerUpGameObjDef^ powerUp)
	{
		if (soldier == nullptr || soldier->SoldierGameObjDefPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}
		else if (powerUp == nullptr || powerUp->PowerUpGameObjDefPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("powerUp");
		}

		return ::Is_Starting_Weapon(
			reinterpret_cast<::SoldierGameObjDef*>(soldier->SoldierGameObjDefPointer.ToPointer()),
			reinterpret_cast<::PowerUpGameObjDef*>(powerUp->PowerUpGameObjDefPointer.ToPointer()));
	}

	bool Engine::IsStartingWeapon(ISoldierGameObj^ soldier, IPowerUpGameObjDef^ powerUp)
	{
		if (soldier == nullptr || soldier->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}
		else if (powerUp == nullptr || powerUp->PowerUpGameObjDefPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("powerUp");
		}

		return ::Is_Starting_Weapon(
			reinterpret_cast<::SoldierGameObj*>(soldier->SoldierGameObjPointer.ToPointer()),
			reinterpret_cast<::PowerUpGameObjDef*>(powerUp->PowerUpGameObjDefPointer.ToPointer()));
	}

	void Engine::FixStuckObjects(Vector3 position, float checkRange, float range, bool destroyUnfixable)
	{
		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		::Fix_Stuck_Objects(
			positionVec,
			checkRange,
			range,
			destroyUnfixable);
	}

	void Engine::FixStuckObjects(Vector3 position, float checkRange, float range)
	{
		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		::Fix_Stuck_Objects(
			positionVec,
			checkRange,
			range);
	}

	bool Engine::FixStuckObject(IPhysicalGameObj^ obj, float range)
	{
		if (obj == nullptr || obj->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Fix_Stuck_Object(
			reinterpret_cast<::PhysicalGameObj*>(obj->PhysicalGameObjPointer.ToPointer()),
			range);
	}

	String^ Engine::CleanModelName(String^ model)
	{
		if (model == nullptr)
		{
			throw gcnew ArgumentNullException("model");
		}

		IntPtr modelHandle = Marshal::StringToHGlobalAnsi(model);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(modelHandle.ToPointer()));

			return gcnew String(::Clean_Model_Name(tmp).Peek_Buffer());
		}
		finally
		{
			Marshal::FreeHGlobal(modelHandle);
		}
	}

	String^ Engine::GetWeaponPowerUpModel(IWeaponDefinitionClass^ weapon)
	{
		if (weapon == nullptr || weapon->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		return gcnew String(::Get_Weapon_PowerUp_Model(
			reinterpret_cast<::WeaponDefinitionClass*>(weapon->WeaponDefinitionClassPointer.ToPointer())).Peek_Buffer());
	}

	void Engine::AddConsoleFunction(IConsoleFunctionClass ^function)
	{
		if (function == nullptr || function->ConsoleFunctionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("function");
		}

		if (function->IsManagedConsoleFunction)
		{
			AddConsoleFunction(function->AsManagedConsoleFunction());
		}
		else
		{
			::Add_Console_Function(reinterpret_cast<::ConsoleFunctionClass*>(function->ConsoleFunctionClassPointer.ToPointer()));
		}
	}

	void Engine::AddConsoleFunction(IRenSharpConsoleFunctionClass^ function)
	{
		if (function == nullptr)
		{
			throw gcnew ArgumentNullException("function");
		}

		if (!function->IsAttached)
		{
			function->AttachToUnmanagedObject();
		}

		if (!function->IsRegistered)
		{
			function->RegisterManagedObject();
		}

		::Add_Console_Function(
			reinterpret_cast<::ConsoleFunctionClass *>(function->ConsoleFunctionClassPointer.ToPointer()));
	}

	int Engine::GetBuildingCount(int team, bool destroyed)
	{
		return ::Get_Building_Count(team, destroyed);
	}

	void Engine::EnableHUD(bool enable)
	{
		::Enable_HUD(enable);
	}

	void Engine::EnableHUDPlayerByID(int id, bool enable)
	{
		::Enable_HUD_Player_By_ID(id, enable);
	}

	void Engine::SetFogEnablePlayerByID(int id, bool enable)
	{
		::Set_Fog_Enable_Player_By_ID(id, enable);
	}

	void Engine::SetFogRangePlayerByID(int id, float startDistance, float endDistance, float transition)
	{
		::Set_Fog_Range_Player_By_ID(id, startDistance, endDistance, transition);
	}

	bool Engine::ExitVehicle(ISoldierGameObj^ soldier)
	{
		if (soldier == nullptr || soldier->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}

		return ::Exit_Vehicle(
			reinterpret_cast<::SoldierGameObj*>(soldier->SoldierGameObjPointer.ToPointer()));
	}

	void Engine::ReverseDamage(IScriptableGameObj^ obj, float amount)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Reverse_Damage(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
			amount);
	}

	void Engine::SetEmotIcon(int id, String^ model, int team)
	{
		if (model == nullptr)
		{
			throw gcnew ArgumentNullException("model");
		}

		IntPtr modelHandle = Marshal::StringToHGlobalAnsi(model);
		try
		{
			::Set_Emot_Icon(
				id,
				reinterpret_cast<char*>(modelHandle.ToPointer()),
				team);
		}
		finally
		{
			Marshal::FreeHGlobal(modelHandle);
		}
	}

	String ^Engine::GetDefinitionName(unsigned long id)
	{
		auto result = ::Get_Definition_Name(id);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	int Engine::GetDefinitionID(String ^name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			return ::Get_Definition_ID(
				reinterpret_cast<char *>(nameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	IDefinitionClass ^Engine::FindNamedDefinition(String ^name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			auto defPtr = ::Find_Named_Definition(
				reinterpret_cast<char *>(nameHandle.ToPointer()));

			if (defPtr == nullptr)
			{
				return nullptr;
			}
			else
			{
				return DefinitionClass::CreateDefinitionClassWrapper(defPtr);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	IDefinitionClass ^Engine::FindDefinition(unsigned long id)
	{
		auto defPtr = ::Find_Definition(id);

		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return DefinitionClass::CreateDefinitionClassWrapper(defPtr);
		}
	}

	unsigned long Engine::GetDefinitionClassID(String ^name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			return ::Get_Definition_Class_ID(
				reinterpret_cast<char *>(nameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	IDefinitionClass ^Engine::GetPhysDefinition(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto defPtr = ::Get_Phys_Definition(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));

		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return DefinitionClass::CreateDefinitionClassWrapper(defPtr);
		}
	}

	bool Engine::IsValidPresetID(unsigned long id)
	{
		return ::Is_Valid_Preset_ID(id);
	}

	bool Engine::IsValidPreset(String ^preset)
	{
		if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			return ::Is_Valid_Preset(
				reinterpret_cast<char *>(presetHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(presetHandle);
		}
	}

	void Engine::DamageAllBuildingsByTeam(int team, float damage, String ^warhead, IScriptableGameObj ^damager)
	{
		if (warhead == nullptr)
		{
			throw gcnew ArgumentNullException("warhead");
		}

		IntPtr warheadHandle = Marshal::StringToHGlobalAnsi(warhead);
		try
		{
			if (damager == nullptr || damager->ScriptableGameObjPointer.ToPointer() == nullptr)
			{
				::Damage_All_Buildings_By_Team(
					team,
					damage,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					nullptr);
			}
			else
			{
				::Damage_All_Buildings_By_Team(
					team,
					damage,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					reinterpret_cast<::ScriptableGameObj *>(damager->ScriptableGameObjPointer.ToPointer()));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(warheadHandle);
		}
	}

	void Engine::RepairAllBuildingsByTeam(int team, int constructionYardID, float health)
	{
		::Repair_All_Buildings_By_Team(team, constructionYardID, health);
	}

	void Engine::RepairAllStaticVehiclesByTeam(int team, int type)
	{
		::Repair_All_Static_Vehicles_By_Team(team, type);
	}

	void Engine::SetMaxHealth(IScriptableGameObj ^obj, float health)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Max_Health(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			health);
	}

	void Engine::SetMaxShieldStrength(IScriptableGameObj ^obj, float shieldStrength)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Max_Shield_Strength(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			shieldStrength);
	}

	String ^Engine::GetShieldType(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::Get_Shield_Type(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String ^Engine::GetSkin(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::Get_Skin(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	void Engine::SetSkin(IScriptableGameObj ^obj, String ^skinType)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (skinType == nullptr)
		{
			throw gcnew ArgumentNullException("skinType");
		}

		IntPtr skinTypeHandle = Marshal::StringToHGlobalAnsi(skinType);
		try
		{
			::Set_Skin(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(skinTypeHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(skinTypeHandle);
		}
	}

	void Engine::DamageAllVehiclesArea(float damage, String ^warhead, Vector3 position, float distance, IScriptableGameObj ^host, IScriptableGameObj ^damager)
	{
		if (warhead == nullptr)
		{
			throw gcnew ArgumentNullException("warhead");
		}
		else if (host == nullptr || host->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("host");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		IntPtr warheadHandle = Marshal::StringToHGlobalAnsi(warhead);
		try
		{
			if (damager == nullptr)
			{
				::Damage_All_Vehicles_Area(
					damage,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					positionVec,
					distance,
					reinterpret_cast<::ScriptableGameObj *>(host->ScriptableGameObjPointer.ToPointer()),
					nullptr);
			}
			else
			{
				::Damage_All_Vehicles_Area(
					damage,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					positionVec,
					distance,
					reinterpret_cast<::ScriptableGameObj *>(host->ScriptableGameObjPointer.ToPointer()),
					reinterpret_cast<::ScriptableGameObj *>(damager->ScriptableGameObjPointer.ToPointer()));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(warheadHandle);
		}
	}

	void Engine::DamageAllObjectsArea(float damage, String ^warhead, Vector3 position, float distance, IScriptableGameObj ^host, IScriptableGameObj ^damager)
	{
		if (warhead == nullptr)
		{
			throw gcnew ArgumentNullException("warhead");
		}
		else if (host == nullptr || host->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("host");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		IntPtr warheadHandle = Marshal::StringToHGlobalAnsi(warhead);
		try
		{
			if (damager == nullptr)
			{
				::Damage_All_Objects_Area(
					damage,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					positionVec,
					distance,
					reinterpret_cast<::ScriptableGameObj *>(host->ScriptableGameObjPointer.ToPointer()),
					nullptr);
			}
			else
			{
				::Damage_All_Objects_Area(
					damage,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					positionVec,
					distance,
					reinterpret_cast<::ScriptableGameObj *>(host->ScriptableGameObjPointer.ToPointer()),
					reinterpret_cast<::ScriptableGameObj *>(damager->ScriptableGameObjPointer.ToPointer()));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(warheadHandle);
		}
	}

	void Engine::DamageAllObjectsAreaByTeam(float damage, String ^warhead, Vector3 position, float distance, IScriptableGameObj ^damager, bool soldiers, bool vehicles, int team)
	{
		if (warhead == nullptr)
		{
			throw gcnew ArgumentNullException("warhead");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		IntPtr warheadHandle = Marshal::StringToHGlobalAnsi(warhead);
		try
		{
			if (damager == nullptr)
			{
				::Damage_All_Objects_Area_By_Team(
					damage,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					positionVec,
					distance,
					nullptr,
					soldiers,
					vehicles,
					team);
			}
			else
			{
				::Damage_All_Objects_Area_By_Team(
					damage,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					positionVec,
					distance,
					reinterpret_cast<::ScriptableGameObj *>(damager->ScriptableGameObjPointer.ToPointer()),
					soldiers,
					vehicles,
					team);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(warheadHandle);
		}
	}

	void Engine::RangedDamageToBuildings(float damage, String ^warhead, Vector3 location, float damageRadius, IScriptableGameObj ^damager)
	{
		if (warhead == nullptr)
		{
			throw gcnew ArgumentNullException("warhead");
		}

		::Vector3 locationVec;

		Vector3::ManagedToUnmanagedVector3(location, locationVec);

		IntPtr warheadHandle = Marshal::StringToHGlobalAnsi(warhead);
		try
		{
			if (damager == nullptr)
			{
				::Ranged_Damage_To_Buildings(
					damage,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					locationVec,
					damageRadius,
					nullptr);
			}
			else
			{
				::Ranged_Damage_To_Buildings(
					damage,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					locationVec,
					damageRadius,
					reinterpret_cast<::ScriptableGameObj *>(damager->ScriptableGameObjPointer.ToPointer()));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(warheadHandle);
		}
	}

	void Engine::RangedScaleDamageToBuildings(float damage, String ^warhead, Vector3 location, float damageRadius, IScriptableGameObj ^damager)
	{
		if (warhead == nullptr)
		{
			throw gcnew ArgumentNullException("warhead");
		}

		::Vector3 locationVec;

		Vector3::ManagedToUnmanagedVector3(location, locationVec);

		IntPtr warheadHandle = Marshal::StringToHGlobalAnsi(warhead);
		try
		{
			if (damager == nullptr)
			{
				::Ranged_Scale_Damage_To_Buildings(
					damage,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					locationVec,
					damageRadius,
					nullptr);
			}
			else
			{
				::Ranged_Scale_Damage_To_Buildings(
					damage,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					locationVec,
					damageRadius,
					reinterpret_cast<::ScriptableGameObj *>(damager->ScriptableGameObjPointer.ToPointer()));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(warheadHandle);
		}
	}

	void Engine::RangedPercentageDamageToBuildings(float percentage, String ^warhead, Vector3 location, float damageRadius, IScriptableGameObj ^damager)
	{
		if (warhead == nullptr)
		{
			throw gcnew ArgumentNullException("warhead");
		}

		::Vector3 locationVec;

		Vector3::ManagedToUnmanagedVector3(location, locationVec);

		IntPtr warheadHandle = Marshal::StringToHGlobalAnsi(warhead);
		try
		{
			if (damager == nullptr)
			{
				::Ranged_Percentage_Damage_To_Buildings(
					percentage,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					locationVec,
					damageRadius,
					nullptr);
			}
			else
			{
				::Ranged_Percentage_Damage_To_Buildings(
					percentage,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					locationVec,
					damageRadius,
					reinterpret_cast<::ScriptableGameObj *>(damager->ScriptableGameObjPointer.ToPointer()));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(warheadHandle);
		}
	}

	void Engine::RangedDamageToBuildingsTeam(int team, float damage, String ^warhead, Vector3 location, float damageRadius, IScriptableGameObj ^damager)
	{
		if (warhead == nullptr)
		{
			throw gcnew ArgumentNullException("warhead");
		}

		::Vector3 locationVec;

		Vector3::ManagedToUnmanagedVector3(location, locationVec);

		IntPtr warheadHandle = Marshal::StringToHGlobalAnsi(warhead);
		try
		{
			if (damager == nullptr)
			{
				::Ranged_Damage_To_Buildings_Team(
					team,
					damage,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					locationVec,
					damageRadius,
					nullptr);
			}
			else
			{
				::Ranged_Damage_To_Buildings_Team(
					team,
					damage,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					locationVec,
					damageRadius,
					reinterpret_cast<::ScriptableGameObj *>(damager->ScriptableGameObjPointer.ToPointer()));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(warheadHandle);
		}
	}

	void Engine::RangedScaleDamageToBuildingsTeam(int team, float damage, String ^warhead, Vector3 location, float damageRadius, IScriptableGameObj ^damager)
	{
		if (warhead == nullptr)
		{
			throw gcnew ArgumentNullException("warhead");
		}

		::Vector3 locationVec;

		Vector3::ManagedToUnmanagedVector3(location, locationVec);

		IntPtr warheadHandle = Marshal::StringToHGlobalAnsi(warhead);
		try
		{
			if (damager == nullptr)
			{
				::Ranged_Scale_Damage_To_Buildings_Team(
					team,
					damage,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					locationVec,
					damageRadius,
					nullptr);
			}
			else
			{
				::Ranged_Scale_Damage_To_Buildings_Team(
					team,
					damage,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					locationVec,
					damageRadius,
					reinterpret_cast<::ScriptableGameObj *>(damager->ScriptableGameObjPointer.ToPointer()));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(warheadHandle);
		}
	}

	void Engine::RangedPercentageDamageToBuildingsTeam(int team, float percentage, String ^warhead, Vector3 location, float damageRadius, IScriptableGameObj ^damager)
	{
		if (warhead == nullptr)
		{
			throw gcnew ArgumentNullException("warhead");
		}

		::Vector3 locationVec;

		Vector3::ManagedToUnmanagedVector3(location, locationVec);

		IntPtr warheadHandle = Marshal::StringToHGlobalAnsi(warhead);
		try
		{
			if (damager == nullptr)
			{
				::Ranged_Percentage_Damage_To_Buildings_Team(
					team,
					percentage,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					locationVec,
					damageRadius,
					nullptr);
			}
			else
			{
				::Ranged_Percentage_Damage_To_Buildings_Team(
					team,
					percentage,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					locationVec,
					damageRadius,
					reinterpret_cast<::ScriptableGameObj *>(damager->ScriptableGameObjPointer.ToPointer()));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(warheadHandle);
		}
	}

	void Engine::DamageObjectsHalf()
	{
		::Damage_Objects_Half();
	}

	void Engine::RangedPercentageDamageToVehicles(float percentage, String ^warhead, Vector3 location, float damageRadius, IScriptableGameObj ^damager)
	{
		if (warhead == nullptr)
		{
			throw gcnew ArgumentNullException("warhead");
		}

		::Vector3 locationVec;

		Vector3::ManagedToUnmanagedVector3(location, locationVec);

		IntPtr warheadHandle = Marshal::StringToHGlobalAnsi(warhead);
		try
		{
			if (damager == nullptr)
			{
				::Ranged_Percentage_Damage_To_Vehicles(
					percentage,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					locationVec,
					damageRadius,
					nullptr);
			}
			else
			{
				::Ranged_Percentage_Damage_To_Vehicles(
					percentage,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					locationVec,
					damageRadius,
					reinterpret_cast<::ScriptableGameObj *>(damager->ScriptableGameObjPointer.ToPointer()));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(warheadHandle);
		}
	}

	void Engine::SetDamagePoints(IScriptableGameObj ^obj, float points)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Damage_Points(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			points);
	}

	void Engine::SetDeathPoints(IScriptableGameObj ^obj, float points)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Death_Points(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			points);
	}

	void Engine::RepairAllBuildingsByTeamRadius(int team, int constructionYardID, float health, float radius)
	{
		::Repair_All_Buildings_By_Team_Radius(
			team,
			constructionYardID,
			health,
			radius);
	}

	void Engine::RepairAllTurretsByTeam(int team, float health)
	{
		::Repair_All_Turrets_By_Team(team, health);
	}

	void Engine::DamageAllObjectsInZone(IScriptableGameObj ^zone, float damage, String ^warhead, IScriptableGameObj ^damager)
	{
		if (zone == nullptr || zone->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("zone");
		}
		else if (warhead == nullptr)
		{
			throw gcnew ArgumentNullException("warhead");
		}

		IntPtr warheadHandle = Marshal::StringToHGlobalAnsi(warhead);
		try
		{
			if (damager == nullptr)
			{
				::Damage_All_Objects_In_Zone(
					reinterpret_cast<::ScriptableGameObj *>(zone->ScriptableGameObjPointer.ToPointer()),
					damage,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					nullptr);
			}
			else
			{
				::Damage_All_Objects_In_Zone(
					reinterpret_cast<::ScriptableGameObj *>(zone->ScriptableGameObjPointer.ToPointer()),
					damage,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					reinterpret_cast<::ScriptableGameObj *>(damager->ScriptableGameObjPointer.ToPointer()));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(warheadHandle);
		}
	}

	float Engine::GetDamagePoints(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Damage_Points(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	float Engine::GetDeathPoints(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Death_Points(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::KillOccupants(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Kill_Occupants(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::DamageOccupants(IScriptableGameObj ^obj, float damage, String ^warhead)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (warhead == nullptr)
		{
			throw gcnew ArgumentNullException("warhead");
		}

		IntPtr warheadHandle = Marshal::StringToHGlobalAnsi(warhead);
		try
		{
			::Damage_Occupants(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				damage,
				reinterpret_cast<char *>(warheadHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(warheadHandle);
		}
	}

	void Engine::RangedVariablePercentVehicleDamage(float enemyPercentage, float friendPecentage, bool forceFriendly, String ^warhead, Vector3 location, float damageRadius, IScriptableGameObj ^damager)
	{
		if (warhead == nullptr)
		{
			throw gcnew ArgumentNullException("warhead");
		}

		::Vector3 locationVec;

		Vector3::ManagedToUnmanagedVector3(location, locationVec);

		IntPtr warheadHandle = Marshal::StringToHGlobalAnsi(warhead);
		try
		{
			if (damager == nullptr)
			{
				::Ranged_Variable_Percent_Vehicle_Damage(
					enemyPercentage,
					friendPecentage,
					forceFriendly,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					locationVec,
					damageRadius,
					nullptr);
			}
			else
			{
				::Ranged_Variable_Percent_Vehicle_Damage(
					enemyPercentage,
					friendPecentage,
					forceFriendly,
					reinterpret_cast<char *>(warheadHandle.ToPointer()),
					locationVec,
					damageRadius,
					reinterpret_cast<::ScriptableGameObj *>(damager->ScriptableGameObjPointer.ToPointer()));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(warheadHandle);
		}
	}

	float Engine::GetMaxHitpoints(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Max_Hitpoints(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	float Engine::GetHitpoints(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Hitpoints(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool Engine::IsValidArmorType(String ^name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			return ::Is_Valid_Armor_Type(
				reinterpret_cast<char *>(nameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	bool Engine::IsValidWarheadType(String ^name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			return ::Is_Valid_Warhead_Type(
				reinterpret_cast<char *>(nameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	float Engine::Rad2Deg(float radians)
	{
		return RAD2DEG(radians);
	}

	float Engine::Deg2Rad(float degrees)
	{
		return DEG2RAD(degrees);
	}

	double Engine::Rad2Deg(double radians)
	{
		return RAD2DEG(radians);
	}

	double Engine::Deg2Rad(double degrees)
	{
		return DEG2RAD(degrees);
	}

	float Engine::DivideRoundUp(float x, float y)
	{
		return divideRoundUp(x, y);
	}

	double Engine::DivideRoundUp(double x, double y)
	{
		return divideRoundUp(x, y);
	}

	unsigned long Engine::F2DW(float f)
	{
		return ::F2DW(f);
	}

	std::uint8_t Engine::Sqr(std::uint8_t value)
	{
		return ::sqr(value);
	}

	std::int8_t Engine::Sqr(std::int8_t value)
	{
		return ::sqr(value);
	}

	std::uint16_t Engine::Sqr(std::uint16_t value)
	{
		return ::sqr(value);
	}

	std::int16_t Engine::Sqr(std::int16_t value)
	{
		return ::sqr(value);
	}

	std::uint32_t Engine::Sqr(std::uint32_t value)
	{
		return ::sqr(value);
	}

	std::int32_t Engine::Sqr(std::int32_t value)
	{
		return ::sqr(value);
	}

	std::uint64_t Engine::Sqr(std::uint64_t value)
	{
		return ::sqr(value);
	}

	std::int64_t Engine::Sqr(std::int64_t value)
	{
		return ::sqr(value);
	}

	float Engine::Sqr(float value)
	{
		return ::sqr(value);
	}

	double Engine::Sqr(double value)
	{
		return ::sqr(value);
	}

	double Engine::Sqr(wchar_t value)
	{
		return ::sqr(value);
	}

	std::uint8_t Engine::Clamp(std::uint8_t value, std::uint8_t min, std::uint8_t max)
	{
		return ::clamp(value, min, max);
	}

	std::int8_t Engine::Clamp(std::int8_t value, std::int8_t min, std::int8_t max)
	{
		return ::clamp(value, min, max);
	}

	std::uint16_t Engine::Clamp(std::uint16_t value, std::uint16_t min, std::uint16_t max)
	{
		return ::clamp(value, min, max);
	}

	std::int16_t Engine::Clamp(std::int16_t value, std::int16_t min, std::int16_t max)
	{
		return ::clamp(value, min, max);
	}

	std::uint32_t Engine::Clamp(std::uint32_t value, std::uint32_t min, std::uint32_t max)
	{
		return ::clamp(value, min, max);
	}

	std::int32_t Engine::Clamp(std::int32_t value, std::int32_t min, std::int32_t max)
	{
		return ::clamp(value, min, max);
	}

	std::uint64_t Engine::Clamp(std::uint64_t value, std::uint64_t min, std::uint64_t max)
	{
		return ::clamp(value, min, max);
	}

	std::int64_t Engine::Clamp(std::int64_t value, std::int64_t min, std::int64_t max)
	{
		return ::clamp(value, min, max);
	}

	float Engine::Clamp(float value, float min, float max)
	{
		return ::clamp(value, min, max);
	}

	double Engine::Clamp(double value, double min, double max)
	{
		return ::clamp(value, min, max);
	}

	wchar_t Engine::Clamp(wchar_t value, wchar_t min, wchar_t max)
	{
		return ::clamp(value, min, max);
	}

	std::uint8_t Engine::Wrap(std::uint8_t value, std::uint8_t min, std::uint8_t max)
	{
		return ::wrap(value, min, max);
	}

	std::int8_t Engine::Wrap(std::int8_t value, std::int8_t min, std::int8_t max)
	{
		return ::wrap(value, min, max);
	}

	std::uint16_t Engine::Wrap(std::uint16_t value, std::uint16_t min, std::uint16_t max)
	{
		return ::wrap(value, min, max);
	}

	std::int16_t Engine::Wrap(std::int16_t value, std::int16_t min, std::int16_t max)
	{
		return ::wrap(value, min, max);
	}

	std::uint32_t Engine::Wrap(std::uint32_t value, std::uint32_t min, std::uint32_t max)
	{
		return ::wrap(value, min, max);
	}

	std::int32_t Engine::Wrap(std::int32_t value, std::int32_t min, std::int32_t max)
	{
		return ::wrap(value, min, max);
	}

	std::uint64_t Engine::Wrap(std::uint64_t value, std::uint64_t min, std::uint64_t max)
	{
		return ::wrap(value, min, max);
	}

	std::int64_t Engine::Wrap(std::int64_t value, std::int64_t min, std::int64_t max)
	{
		return ::wrap(value, min, max);
	}

	float Engine::Wrap(float value, float min, float max)
	{
		return ::wrap(value, min, max);
	}

	wchar_t Engine::Wrap(wchar_t value, wchar_t min, wchar_t max)
	{
		return ::wrap(value, min, max);
	}

	std::uint8_t Engine::Lerp(std::uint8_t a, std::uint8_t b, float fraction)
	{
		return ::lerp(a, b, fraction);
	}

	std::int8_t Engine::Lerp(std::int8_t a, std::int8_t b, float fraction)
	{
		return ::lerp(a, b, fraction);
	}

	std::uint16_t Engine::Lerp(std::uint16_t a, std::uint16_t b, float fraction)
	{
		return ::lerp(a, b, fraction);
	}

	std::int16_t Engine::Lerp(std::int16_t a, std::int16_t b, float fraction)
	{
		return ::lerp(a, b, fraction);
	}

	std::uint32_t Engine::Lerp(std::uint32_t a, std::uint32_t b, float fraction)
	{
		return ::lerp(a, b, fraction);
	}

	std::int32_t Engine::Lerp(std::int32_t a, std::int32_t b, float fraction)
	{
		return ::lerp(a, b, fraction);
	}

	std::uint64_t Engine::Lerp(std::uint64_t a, std::uint64_t b, float fraction)
	{
		return ::lerp(a, b, fraction);
	}

	std::int64_t Engine::Lerp(std::int64_t a, std::int64_t b, float fraction)
	{
		return ::lerp(a, b, fraction);
	}

	float Engine::Lerp(float a, float b, float fraction)
	{
		return ::lerp(a, b, fraction);
	}

	double Engine::Lerp(double a, double b, float fraction)
	{
		return ::lerp(a, b, fraction);
	}

	wchar_t Engine::Lerp(wchar_t a, wchar_t b, float fraction)
	{
		return ::lerp(a, b, fraction);
	}

	bool Engine::IsPowerOfTwo(int number)
	{
		return ::isPowerOfTwo(number);
	}

	uint Engine::GetColorUInt32(int a, int r, int g, int b)
	{
		return GetColorUInt(a, r, g, b);
	}

	float Engine::Sgn(float x)
	{
		return ::sgn(x);
	}

	int Engine::FindPOTLT(int i)
	{
		return ::Find_POT_LT(i);
	}

	int Engine::GetObjectType(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Object_Type(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::SetObjectType(IScriptableGameObj ^obj, int type)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Object_Type(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			type);
	}

	Color Engine::GetObjectColor(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		unsigned int red = 0;
		unsigned int green = 0;
		unsigned int blue = 0;

		::Get_Object_Color(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			&red,
			&green,
			&blue);

		return Color::FromArgb(255, static_cast<int>(red), static_cast<int>(green), static_cast<int>(blue));
	}

	IScriptableGameObj ^Engine::FindSmartObjectByTeam(int team)
	{
		auto result = ::Find_Smart_Object_By_Team(team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<ISmartGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IScriptableGameObj ^Engine::FindObjectByTeam(int team)
	{
		auto result = ::Find_Object_By_Team(team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<ISmartGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IScriptableGameObj ^Engine::FindNonPlayerObjectByTeam(int team)
	{
		auto result = ::Find_Non_Player_Object_By_Team(team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<ISmartGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IScriptableGameObj ^Engine::FindObjectByPreset(int team, String ^presetName)
	{
		if (presetName == nullptr)
		{
			throw gcnew ArgumentNullException("presetName");
		}

		IntPtr presetNameHandle = Marshal::StringToHGlobalAnsi(presetName);
		try
		{
			auto result = ::Find_Object_By_Preset(
				team,
				reinterpret_cast<char *>(presetNameHandle.ToPointer()));

			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return safe_cast<ISmartGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(presetNameHandle);
		}
	}

	IScriptableGameObj ^Engine::FindClosestNonBuildingObjectByTeam(int team, Vector3 position)
	{
		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		auto result = ::Find_Closest_Non_Building_Object_By_Team(team, positionVec);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<ISmartGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IScriptableGameObj ^Engine::FindClosestPresetByTeam(int team, Vector3 pos, String ^preset)
	{
		if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		::Vector3 posVec;

		Vector3::ManagedToUnmanagedVector3(pos, posVec);

		IntPtr presetNameHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			auto result = ::Find_Closest_Preset_By_Team(
				team,
				posVec,
				reinterpret_cast<char *>(presetNameHandle.ToPointer()));

			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return safe_cast<ISmartGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(presetNameHandle);
		}
	}

	IScriptableGameObj ^Engine::FindRandomPresetByTeam(int team, String ^preset)
	{
		if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		IntPtr presetNameHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			auto result = ::Find_Random_Preset_By_Team(
				team,
				reinterpret_cast<char *>(presetNameHandle.ToPointer()));

			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return safe_cast<ISmartGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(presetNameHandle);
		}
	}

	int Engine::GetObjectCount(int team, String ^preset)
	{
		if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		IntPtr presetNameHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			return ::Get_Object_Count(
				team,
				reinterpret_cast<char *>(presetNameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(presetNameHandle);
		}
	}

	Generic::ICollection<IScriptableGameObj ^> ^Engine::GetAllObjectsByPreset(int team, String ^preset)
	{
		if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		IntPtr presetNameHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			auto tmp = ::Get_All_Objects_By_Preset(
				team,
				reinterpret_cast<char *>(presetNameHandle.ToPointer()));

			try
			{
				int count = tmp->Count();
				auto result = gcnew Generic::List<IScriptableGameObj ^>();
				
				for (int x = 0; x < count; x++)
				{
					auto currentObj = tmp->operator[](x);
					if (currentObj == nullptr)
					{
						result->Add(nullptr);
					}
					else
					{
						result->Add(safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(currentObj)));
					}
				}

				return result;
			}
			finally
			{
				Imports::DestroyScriptableGameObjPtrSimpleDynVecClass(tmp);
				tmp = nullptr;
			}
		}
		finally
		{
			Marshal::FreeHGlobal(presetNameHandle);
		}
	}

	IScriptableGameObj ^Engine::FindNearestPreset(Vector3 position, String ^preset)
	{
		if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		IntPtr presetNameHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			auto result = ::Find_Nearest_Preset(
				positionVec,
				reinterpret_cast<char *>(presetNameHandle.ToPointer()));

			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return safe_cast<ISmartGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(presetNameHandle);
		}
	}

	IScriptableGameObj ^Engine::FindRandomPreset(String ^preset, int min, int max)
	{
		if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		IntPtr presetNameHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			auto result = ::Find_Random_Preset(
				reinterpret_cast<char *>(presetNameHandle.ToPointer()),
				min,
				max);

			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return safe_cast<ISmartGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(presetNameHandle);
		}
	}

	void Engine::SendCustomToTeamBuildings(int team, IScriptableGameObj ^sender, int type, int param, float delay)
	{
		if (sender == nullptr || sender->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("sender");
		}

		::Send_Custom_To_Team_Buildings(
			team,
			reinterpret_cast<::ScriptableGameObj *>(sender->ScriptableGameObjPointer.ToPointer()),
			type,
			param,
			delay);
	}

	void Engine::SendCustomToTeamPreset(int team, String ^presetName, IScriptableGameObj ^sender, int type, int param, float delay)
	{
		if (presetName == nullptr)
		{
			throw gcnew ArgumentNullException("presetName");
		}
		else if (sender == nullptr || sender->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("sender");
		}

		IntPtr presetNameHandle = Marshal::StringToHGlobalAnsi(presetName);
		try
		{
			::Send_Custom_To_Team_Preset(
				team,
				reinterpret_cast<char *>(presetNameHandle.ToPointer()),
				reinterpret_cast<::ScriptableGameObj *>(sender->ScriptableGameObjPointer.ToPointer()),
				type,
				param,
				delay);
		}
		finally
		{
			Marshal::FreeHGlobal(presetNameHandle);
		}
	}

	void Engine::SendCustomAllObjectsArea(int type, Vector3 position, float distance, IScriptableGameObj ^sender, int team)
	{
		if (sender == nullptr || sender->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("sender");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		::Send_Custom_All_Objects_Area(
			team,
			positionVec,
			distance,
			reinterpret_cast<::ScriptableGameObj *>(sender->ScriptableGameObjPointer.ToPointer()),
			team);
	}

	void Engine::SendCustomAllObjects(int type, IScriptableGameObj ^sender, int team)
	{
		if (sender == nullptr || sender->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("sender");
		}

		::Send_Custom_All_Objects(
			type,
			reinterpret_cast<::ScriptableGameObj *>(sender->ScriptableGameObjPointer.ToPointer()),
			team);
	}

	void Engine::SendCustomEventToObject(IScriptableGameObj ^sender, String ^preset, int type, int param, float delay)
	{
		if (sender == nullptr || sender->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("sender");
		}
		else if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		IntPtr presetNameHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			::Send_Custom_Event_To_Object(
				reinterpret_cast<::ScriptableGameObj *>(sender->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(presetNameHandle.ToPointer()),
				type,
				param,
				delay);
		}
		finally
		{
			Marshal::FreeHGlobal(presetNameHandle);
		}
	}

	bool Engine::IsUnitInRange(String ^preset, float range, Vector3 location, int team, bool empty)
	{
		if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		::Vector3 locationVec;

		Vector3::ManagedToUnmanagedVector3(location, locationVec);

		IntPtr presetNameHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			return ::Is_Unit_In_Range(
				reinterpret_cast<char *>(presetNameHandle.ToPointer()),
				range,
				locationVec,
				team,
				empty);
		}
		finally
		{
			Marshal::FreeHGlobal(presetNameHandle);
		}
	}

	bool Engine::GetIsPowerupPersistant(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Is_Powerup_Persistant(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool Engine::GetPowerupAlwaysAllowGrant(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Powerup_Always_Allow_Grant(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::SetPowerupAlwaysAllowGrant(IScriptableGameObj ^obj, bool grant)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Powerup_Always_Allow_Grant(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			grant);
	}

	int Engine::GetPowerupGrantSound(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Powerup_Grant_Sound(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::GrantPowerup(IScriptableGameObj ^obj, String ^presetName)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (presetName == nullptr)
		{
			throw gcnew ArgumentNullException("presetName");
		}

		IntPtr presetNameHandle = Marshal::StringToHGlobalAnsi(presetName);
		try
		{
			::Grant_Powerup(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(presetNameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(presetNameHandle);
		}
	}

	IScriptableGameObj ^Engine::FindClosestBuilding(Vector3 position)
	{
		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		auto result = ::Find_Closest_Building(positionVec);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	Vector3 Engine::GetVelocity(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Vector3 tmp = ::Get_Velocity(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));

		Vector3 result;

		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	void Engine::SetVelocity(IScriptableGameObj ^obj, Vector3 velocity)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Vector3 velocityVec;

		Vector3::ManagedToUnmanagedVector3(velocity, velocityVec);

		::Set_Velocity(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			velocityVec);
	}

	Matrix3D Engine::GetTransform(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Matrix3D tmp = ::Get_Transform(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));

		Matrix3D result;

		Matrix3D::UnmanagedToManagedMatrix3D(tmp, result);

		return result;
	}

	void Engine::SetTransform(IScriptableGameObj ^obj, Matrix3D transform)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Matrix3D transformMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(transform, transformMat);

		::Set_Transform(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			transformMat);
	}

	IScriptableGameObj ^Engine::GetClosestArmedObjectToObject(IScriptableGameObj ^obj, int team)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::Get_Closest_Armed_Object_To_Object(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			team);

		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IScriptableGameObj ^Engine::GetClosestArmedObjectToObject(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::Get_Closest_Armed_Object_To_Object(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));

		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	bool Engine::VerifyPresetLimit(int team, int instanceCount, array<uint32> ^presetIds, IScriptableGameObj ^ignore)
	{
		if (presetIds == nullptr)
		{
			throw gcnew ArgumentNullException("presetIds");
		}

		pin_ptr<uint32> pinnedPresetIds = &presetIds[0];
		uint32 *presetIdsPtr = pinnedPresetIds;

		if (ignore == nullptr || ignore->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			return ::Verify_Preset_Limit(
				team,
				instanceCount,
				presetIdsPtr,
				presetIds->Length,
				nullptr);
		}
		else
		{
			return ::Verify_Preset_Limit(
				team,
				instanceCount,
				presetIdsPtr,
				presetIds->Length,
				reinterpret_cast<::ScriptableGameObj *>(ignore->ScriptableGameObjPointer.ToPointer()));
		}
	}

	bool Engine::VerifyPresetLimit(int team, int instanceCount, array<uint32> ^presetIds)
	{
		if (presetIds == nullptr)
		{
			throw gcnew ArgumentNullException("presetIds");
		}

		pin_ptr<uint32> pinnedPresetIds = &presetIds[0];
		uint32 *presetIdsPtr = pinnedPresetIds;

		return ::Verify_Preset_Limit(
			team,
			instanceCount,
			presetIdsPtr,
			presetIds->Length);
	}

	IScriptableGameObj ^Engine::GetVehicle(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::Get_Vehicle(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	void Engine::GrantRefill(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Grant_Refill(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool Engine::ChangeCharacter(IScriptableGameObj ^obj, String ^presetName)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (presetName == nullptr)
		{
			throw gcnew ArgumentNullException("presetName");
		}

		IntPtr presetNameHandle = Marshal::StringToHGlobalAnsi(presetName);
		try
		{
			return ::Change_Character(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(presetNameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(presetNameHandle);
		}
	}

	bool Engine::CreateVehicle(String ^presetName, float delay, IScriptableGameObj ^owner, int team)
	{
		if (presetName == nullptr)
		{
			throw gcnew ArgumentNullException("presetName");
		}
		else if (owner == nullptr || owner->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}

		IntPtr presetNameHandle = Marshal::StringToHGlobalAnsi(presetName);
		try
		{
			return ::Create_Vehicle(
				reinterpret_cast<char *>(presetNameHandle.ToPointer()),
				delay,
				reinterpret_cast<::ScriptableGameObj *>(owner->ScriptableGameObjPointer.ToPointer()),
				team);
		}
		finally
		{
			Marshal::FreeHGlobal(presetNameHandle);
		}
	}

	void Engine::ToggleFlyMode(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Toggle_Fly_Mode(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	int Engine::GetVehicleOccupantCount(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Vehicle_Occupant_Count(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	IScriptableGameObj ^Engine::GetVehicleOccupant(IScriptableGameObj ^obj, int seat)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (seat < 0)
		{
			throw gcnew ArgumentOutOfRangeException("seat");
		}

		auto result = ::Get_Vehicle_Occupant(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			seat);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IScriptableGameObj ^Engine::GetVehicleDriver(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::Get_Vehicle_Driver(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IScriptableGameObj ^Engine::GetVehicleGunner(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::Get_Vehicle_Gunner(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	void Engine::ForceOccupantExit(IScriptableGameObj ^obj, int seat)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (seat < 0)
		{
			throw gcnew ArgumentOutOfRangeException("seat");
		}

		::Force_Occupant_Exit(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			seat);
	}

	void Engine::ForceOccupantsExit(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Force_Occupants_Exit(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	IScriptableGameObj ^Engine::GetVehicleReturn(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::Get_Vehicle_Return(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	bool Engine::IsStealth(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Is_Stealth(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool Engine::GetFlyMode(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Fly_Mode(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	int Engine::GetVehicleSeatCount(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Vehicle_Seat_Count(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::SoldierTransitionVehicle(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Soldier_Transition_Vehicle(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	unsigned int Engine::GetVehicleMode(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Vehicle_Mode(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool Engine::IsVTOL(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Is_VTOL(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	IScriptableGameObj ^Engine::GetVehicleOwner(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::Get_Vehicle_Owner(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	void Engine::ForceOccupantsExitTeam(IScriptableGameObj ^obj, int team)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Force_Occupants_Exit_Team(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			team);
	}

	unsigned int Engine::GetVehicleDefinitionMode(String ^preset)
	{
		if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			return ::Get_Vehicle_Definition_Mode(
				reinterpret_cast<char *>(presetHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(presetHandle);
		}
	}

	IScriptableGameObj ^Engine::FindClosestZone(Vector3 location, unsigned int type)
	{
		::Vector3 locationVec;

		Vector3::ManagedToUnmanagedVector3(location, locationVec);

		auto result = ::Find_Closest_Zone(locationVec, type);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	bool Engine::IsInsideZone(IScriptableGameObj ^zone, IScriptableGameObj ^obj)
	{
		if (zone == nullptr || zone->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("zone");
		}
		else if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::IsInsideZone(
			reinterpret_cast<::ScriptableGameObj *>(zone->ScriptableGameObjPointer.ToPointer()),
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	unsigned int Engine::GetVehicleDefinitionModeByID(unsigned long id)
	{
		return ::Get_Vehicle_Definition_Mode_By_ID(id);
	}

	unsigned int Engine::GetZoneType(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Zone_Type(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool Engine::GetZoneBox(IScriptableGameObj ^obj, [Out] OBBoxClass %box)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto tmp = ::Get_Zone_Box(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
		if (tmp == nullptr)
		{
			return false;
		}

		OBBoxClass::UnmanagedToManagedOBBoxClass(*tmp, box);

		return true;
	}

	void Engine::SetZoneBox(IScriptableGameObj ^obj, OBBoxClass box)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::OBBoxClass tmp;

		OBBoxClass::ManagedToUnmanagedOBBoxClass(box, tmp);

		::Set_Zone_Box(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			tmp);
	}

	IScriptableGameObj ^Engine::CreateZone(String ^preset, OBBoxClass box)
	{
		if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		::OBBoxClass tmp;

		OBBoxClass::ManagedToUnmanagedOBBoxClass(box, tmp);

		IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			auto result = ::Create_Zone(
				reinterpret_cast<char *>(presetHandle.ToPointer()),
				tmp);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(presetHandle);
		}
	}

	bool Engine::IsAvailableForPurchase(IScriptableGameObj ^factory)
	{
		if (factory == nullptr || factory->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}

		return ::Is_Available_For_Purchase(
			reinterpret_cast<::ScriptableGameObj *>(factory->ScriptableGameObjPointer.ToPointer()));
	}

	IScriptableGameObj ^Engine::GetVehicleGunnerPos(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::Get_Vehicle_Gunner_Pos(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	void Engine::SetVehicleGunner(IScriptableGameObj ^obj, int seat)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Set_Vehicle_Gunner(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			seat);
	}

	bool Engine::IsSpy(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Is_Spy(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	int Engine::GetPlayerCountInZone(IScriptableGameObj ^obj, int team)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Player_Count_In_Zone(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			team);
	}

	int Engine::GetObjectCountInZone(IScriptableGameObj ^obj, int team)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Object_Count_In_Zone(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			team);
	}

	bool Engine::IsStealthEnabled(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Is_Stealth_Enabled(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	int Engine::GetOccupantSeat(IScriptableGameObj ^vehicle, IScriptableGameObj ^occupant)
	{
		if (vehicle == nullptr || vehicle->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("vehicle");
		}
		else if (occupant == nullptr || occupant->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("occupant");
		}

		return ::Get_Occupant_Seat(
			reinterpret_cast<::ScriptableGameObj *>(vehicle->ScriptableGameObjPointer.ToPointer()),
			reinterpret_cast<::ScriptableGameObj *>(occupant->ScriptableGameObjPointer.ToPointer()));
	}

	bool Engine::IsUnsquishable(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Is_Unsquishable(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	IScriptableGameObj ^Engine::CreateObjectAttachToObject(IScriptableGameObj ^host, String ^preset, String ^bone)
	{
		if (host == nullptr || host->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("host");
		}
		else if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			::ScriptableGameObj *result;

			if (bone == nullptr)
			{
				result = ::Create_Object_Attach_To_Object(
					reinterpret_cast<::ScriptableGameObj *>(host->ScriptableGameObjPointer.ToPointer()),
					reinterpret_cast<char *>(presetHandle.ToPointer()),
					nullptr);
			}
			else
			{
				IntPtr boneHandle = Marshal::StringToHGlobalAnsi(bone);
				try
				{
					result = ::Create_Object_Attach_To_Object(
						reinterpret_cast<::ScriptableGameObj *>(host->ScriptableGameObjPointer.ToPointer()),
						reinterpret_cast<char *>(presetHandle.ToPointer()),
						reinterpret_cast<char *>(boneHandle.ToPointer()));
				}
				finally
				{
					Marshal::FreeHGlobal(boneHandle);
				}
			}

			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(presetHandle);
		}
	}

	IScriptableGameObj ^Engine::CreateObjectAttachToObject(IScriptableGameObj ^host, String ^preset)
	{
		if (host == nullptr || host->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("host");
		}
		else if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			auto result = ::Create_Object_Attach_To_Object(
					reinterpret_cast<::ScriptableGameObj *>(host->ScriptableGameObjPointer.ToPointer()),
					reinterpret_cast<char *>(presetHandle.ToPointer()));

			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(presetHandle);
		}
	}

	String ^Engine::GetModel(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			auto result = ::Get_Model(nullptr);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew String(result);
			}
		}
		else
		{
			auto result = ::Get_Model(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew String(result);
			}
		}
	}

	float Engine::GetAnimationFrame(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Animation_Frame(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	float Engine::GetAnimationTargetFrame(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Animation_Target_Frame(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::CopyTransform(IScriptableGameObj ^in, IScriptableGameObj ^out)
	{
		if (in == nullptr || in->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("in");
		}
		else if (out == nullptr || out->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("out");
		}

		::Copy_Transform(
			reinterpret_cast<::ScriptableGameObj *>(in->ScriptableGameObjPointer.ToPointer()),
			reinterpret_cast<::ScriptableGameObj *>(out->ScriptableGameObjPointer.ToPointer()));
	}

	float Engine::GetMass(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Mass(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	String ^Engine::GetHtreeName(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			auto result = ::Get_Htree_Name(nullptr);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew String(result);
			}
		}
		else
		{
			auto result = ::Get_Htree_Name(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew String(result);
			}
		}
	}

	wchar_t Engine::GetSex(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Sex(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::CreateEffectAllStealthedObjectsArea(Vector3 position, float distance, String ^object, Vector3 offset, int team)
	{
		if (object == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		::Vector3 positionVec;
		::Vector3 offsetVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);
		Vector3::ManagedToUnmanagedVector3(offset, offsetVec);

		IntPtr objectHandle = Marshal::StringToHGlobalAnsi(object);
		try
		{
			::Create_Effect_All_Stealthed_Objects_Area(
				positionVec,
				distance,
				reinterpret_cast<char *>(objectHandle.ToPointer()),
				offsetVec,
				team);
		}
		finally
		{
			Marshal::FreeHGlobal(objectHandle);
		}
	}

	void Engine::CreateEffectAllOfPreset(String ^object, String ^preset, float zAdjust, bool zSet)
	{
		if (object == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}
		else if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		IntPtr objectHandle = Marshal::StringToHGlobalAnsi(object);
		try
		{
			IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
			try
			{
				::Create_Effect_All_Of_Preset(
					reinterpret_cast<char *>(objectHandle.ToPointer()),
					reinterpret_cast<char *>(presetHandle.ToPointer()),
					zAdjust,
					zSet);
			}
			finally
			{
				Marshal::FreeHGlobal(presetHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(objectHandle);
		}
	}

	void Engine::WakeUpObjectsInBox(IScriptableGameObj ^obj, String ^box)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (box == nullptr)
		{
			throw gcnew ArgumentNullException("box");
		}

		IntPtr boxHandle = Marshal::StringToHGlobalAnsi(box);
		try
		{
			::Wake_Up_Objects_In_Box(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(boxHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(boxHandle);
		}
	}

	void Engine::WakeUpObjectsInOBBox(OBBoxClass boundingBox)
	{
		::OBBoxClass tmp;

		OBBoxClass::ManagedToUnmanagedOBBoxClass(boundingBox, tmp);

		::Wake_Up_Objects_In_OBBox(tmp);
	}

	String ^Engine::GetAnimationName(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::Get_Animation_Name(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	IScriptableGameObj ^Engine::GetGameObj(int playerID)
	{
		auto result = ::Get_GameObj(playerID);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	long Engine::GetPlayerID(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Player_ID(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	String ^Engine::GetPlayerName(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::Get_Wide_Player_Name(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String ^Engine::GetPlayerNameByID(int playerID)
	{
		auto result = ::Get_Wide_Player_Name_By_ID(playerID);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	void Engine::ChangeTeam(IScriptableGameObj ^obj, int team)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Change_Team(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			team);
	}

	void Engine::ChangeTeamByID(int playerID, int team)
	{
		::Change_Team_By_ID(playerID, team);
	}

	int Engine::GetTeamPlayerCount(int team)
	{
		return ::Get_Team_Player_Count(team);
	}

	int Engine::GetTeam(int playerID)
	{
		return ::Get_Team(playerID);
	}

	int Engine::GetRank(int playerID)
	{
		return ::Get_Rank(playerID);
	}

	int Engine::GetKills(int playerID)
	{
		return ::Get_Kills(playerID);
	}

	int Engine::GetDeaths(int playerID)
	{
		return ::Get_Deaths(playerID);
	}

	float Engine::GetScore(int playerID)
	{
		return ::Get_Score(playerID);
	}

	float Engine::GetMoney(int playerID)
	{
		return ::Get_Money(playerID);
	}

	float Engine::GetKillToDeathRatio(int playerID)
	{
		return ::Get_Kill_To_Death_Ratio(playerID);
	}

	IScriptableGameObj ^Engine::GetPartName(String ^name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalUni(name);
		try
		{
			wchar_t *namePtr = reinterpret_cast<wchar_t *>(nameHandle.ToPointer());
			for (auto currentStarNode = ::GameObjManager::StarGameObjList.Head(); currentStarNode != nullptr; currentStarNode = currentStarNode->Next())
			{
				auto currentStarObj = currentStarNode->Data();
				if (currentStarObj == nullptr)
				{
					continue;
				}

				auto soldierStarObj = currentStarObj->As_SoldierGameObj();
				if (soldierStarObj == nullptr)
				{
					continue;
				}

				auto pData = static_cast<::cPlayer *>(soldierStarObj->Get_Player_Data());
				if (pData == nullptr)
				{
					continue;
				}

				if (::wcsistr(pData->PlayerName.Peek_Buffer(), namePtr))
				{
					return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(static_cast<::ScriptableGameObj *>(soldierStarObj)));
				}
			}

			return nullptr;
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	int Engine::GetPartNames(String ^name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalUni(name);
		try
		{
			int count = 0;

			wchar_t *namePtr = reinterpret_cast<wchar_t *>(nameHandle.ToPointer());
			for (auto currentStarNode = ::GameObjManager::StarGameObjList.Head(); currentStarNode != nullptr; currentStarNode = currentStarNode->Next())
			{
				auto currentStarObj = currentStarNode->Data();
				if (currentStarObj == nullptr)
				{
					continue;
				}

				auto soldierStarObj = currentStarObj->As_SoldierGameObj();
				if (soldierStarObj == nullptr)
				{
					continue;
				}

				auto pData = static_cast<::cPlayer *>(soldierStarObj->Get_Player_Data());
				if (pData == nullptr)
				{
					continue;
				}

				if (::wcsistr(pData->PlayerName.Peek_Buffer(), namePtr))
				{
					count++;
				}
			}

			return count;
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	Color Engine::GetTeamColor(unsigned int team)
	{
		unsigned int red;
		unsigned int green;
		unsigned int blue;

		::Get_Team_Color(team, &red, &green, &blue);

		return Color::FromArgb(255, static_cast<int>(red), static_cast<int>(green), static_cast<int>(blue));
	}

	Color Engine::GetPlayerColor(int playerID)
	{
		unsigned int red;
		unsigned int green;
		unsigned int blue;

		::Get_Player_Color(playerID, &red, &green, &blue);

		return Color::FromArgb(255, static_cast<int>(red), static_cast<int>(green), static_cast<int>(blue));
	}

	bool Engine::PurchaseItem(IScriptableGameObj ^obj, int cost)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Purchase_Item(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			cost);
	}

	void Engine::SetLadderPoints(int playerID, int amount)
	{
		::Set_Ladder_Points(playerID, amount);
	}

	void Engine::SetRung(int playerID, int amount)
	{
		::Set_Rung(playerID, amount);
	}

	void Engine::SetMoney(int playerID, float amount)
	{
		::Set_Money(playerID, amount);
	}

	void Engine::SetScore(int playerID, float amount)
	{
		::Set_Score(playerID, amount);
	}

	IScriptableGameObj ^Engine::FindFirstPlayer(int team)
	{
		auto result = ::Find_First_Player(team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	bool Engine::ChangePlayerTeam(IScriptableGameObj ^obj, bool retainScore, bool retainMoney, bool showHostMessage)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Change_Player_Team(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			retainScore,
			retainMoney,
			showHostMessage);
	}

	int Engine::TallyTeamSize(int team)
	{
		return ::Tally_Team_Size(team);
	}

	float Engine::GetTeamScore(int team)
	{
		return ::Get_Team_Score(team);
	}

	void Engine::ChangeTeam2(IScriptableGameObj ^obj, int team)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Change_Team_2(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
			team);
	}

	int Engine::GetPlayerType(IScriptableGameObj ^obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Player_Type(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	Color Engine::GetColorForTeam(int teamId)
	{
		::Vector3 tmp = ::Get_Color_For_Team(teamId);

		return Color::FromArgb(255, static_cast<int>(tmp.X * 255.0f), static_cast<int>(tmp.Y * 255.0f), static_cast<int>(tmp.Z * 255.0f));
	}

	int Engine::GetPlayerTeam(int playerID)
	{
		return ::Get_Player_Team(playerID);
	}

	IcPlayer ^Engine::FindPlayer(int playerID)
	{
		auto result = ::Find_Player(playerID);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	IcPlayer ^Engine::FindPlayer(String ^playerName)
	{
		if (playerName == nullptr)
		{
			throw gcnew ArgumentNullException("playerName");
		}

		IntPtr playerNameHandle = Marshal::StringToHGlobalUni(playerName);
		try
		{
			::WideStringClass tmp(reinterpret_cast<wchar_t *>(playerNameHandle.ToPointer()));

			auto result = ::Find_Player(tmp);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew cPlayer(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(playerNameHandle);
		}
	}

	int Engine::GetPlayerIDByName(String ^name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalUni(name);
		try
		{
			wchar_t *namePtr = reinterpret_cast<wchar_t *>(nameHandle.ToPointer());
			std::size_t nameLength = ::wcslen(namePtr);

			for (auto currentStarNode = ::GameObjManager::StarGameObjList.Head(); currentStarNode != nullptr; currentStarNode = currentStarNode->Next())
			{
				auto currentStarObj = currentStarNode->Data();
				if (currentStarObj == nullptr)
				{
					continue;
				}

				auto soldierStarObj = currentStarObj->As_SoldierGameObj();
				if (soldierStarObj == nullptr)
				{
					continue;
				}

				auto pData = static_cast<::cPlayer *>(soldierStarObj->Get_Player_Data());
				if (pData == nullptr)
				{
					continue;
				}

				if (pData->IsActive && ::_wcsnicmp(pData->PlayerName.Peek_Buffer(), namePtr, nameLength + 1))
				{
					return pData->Get_Id();
				}
			}

			return 0;
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	bool Engine::IsActive(int id)
	{
		return ::Is_Active(id);
	}

	void Engine::SetKills(int id, int kills)
	{
		::Set_Kills(id, kills);
	}

	void Engine::SetDeaths(int id, int deaths)
	{
		::Set_Deaths(id, deaths);
	}

	void Engine::SetTeamScore(int id, float score)
	{
		::Set_Team_Score(id, score);
	}

	void Engine::ChangeTeamDeaths(int teamId, int amount)
	{
		::ChangeTeamDeaths(teamId, amount);
	}

	unsigned int Engine::GetTeamCost(String ^preset, unsigned int team)
	{
		if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			return ::Get_Team_Cost(
				reinterpret_cast<char *>(presetHandle.ToPointer()),
				team);
		}
		finally
		{
			Marshal::FreeHGlobal(presetHandle);
		}
	}

	unsigned int Engine::GetCost(String ^preset)
	{
		if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			return ::Get_Cost(
				reinterpret_cast<char *>(presetHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(presetHandle);
		}
	}

	void Engine::DisablePresetByName(unsigned int team, String ^name, bool enable)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			::Disable_Preset_By_Name(
				team,
				reinterpret_cast<char *>(nameHandle.ToPointer()),
				enable);
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	void Engine::HidePresetByName(unsigned int team, String ^name, bool enable)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			::Hide_Preset_By_Name(
				team,
				reinterpret_cast<char *>(nameHandle.ToPointer()),
				enable);
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	void Engine::BusyPresetByName(unsigned int team, String ^name, bool enable)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			::Busy_Preset_By_Name(
				team,
				reinterpret_cast<char *>(nameHandle.ToPointer()),
				enable);
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	String ^Engine::GetTeamIcon(String ^preset, unsigned int team)
	{
		if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			auto result = ::Get_Team_Icon(
				reinterpret_cast<char *>(presetHandle.ToPointer()),
				team);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew String(result);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(presetHandle);
		}
	}

	String ^Engine::GetIcon(String ^preset)
	{
		if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			auto result = ::Get_Icon(
				reinterpret_cast<char *>(presetHandle.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew String(result);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(presetHandle);
		}
	}

	void Engine::DisableAllPresetsByFactoryTech(RenSharp::BuildingType type, unsigned int team, bool disable)
	{
		::Disable_All_Presets_By_Factory_Tech(
			static_cast<::BuildingType>(type),
			team,
			disable);
	}

	void Engine::RemoveScript(IScriptableGameObj^ obj, String^ script)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			::Remove_Script(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(scriptHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	void Engine::RemoveAllScripts(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Remove_All_Scripts(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::AttachScriptPreset(String^ script, String^ params, String^ preset, int team)
	{
		if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}
		else if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
			try
			{
				if (params == nullptr)
				{
					::Attach_Script_Preset(
						reinterpret_cast<char*>(scriptHandle.ToPointer()),
						nullptr,
						reinterpret_cast<char *>(presetHandle.ToPointer()),
						team);
				}
				else
				{
					IntPtr paramsHandle = Marshal::StringToHGlobalAnsi(params);
					try
					{
						::Attach_Script_Preset(
							reinterpret_cast<char*>(scriptHandle.ToPointer()),
							reinterpret_cast<char*>(paramsHandle.ToPointer()),
							reinterpret_cast<char*>(presetHandle.ToPointer()),
							team);
					}
					finally
					{
						Marshal::FreeHGlobal(paramsHandle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(presetHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	void Engine::AttachScriptType(String^ script, String^ params, unsigned long type, int team)
	{
		if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			if (params == nullptr)
			{
				::Attach_Script_Type(
					reinterpret_cast<char*>(scriptHandle.ToPointer()),
					nullptr,
					type,
					team);
			}
			else
			{
				IntPtr paramsHandle = Marshal::StringToHGlobalAnsi(params);
				try
				{
					::Attach_Script_Type(
						reinterpret_cast<char*>(scriptHandle.ToPointer()),
						reinterpret_cast<char*>(paramsHandle.ToPointer()),
						type,
						team);
				}
				finally
				{
					Marshal::FreeHGlobal(paramsHandle);
				}
			}
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	void Engine::RemoveScriptPreset(String^ script, String^ preset, int team)
	{
		if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}
		else if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
			try
			{
				::Remove_Script_Preset(
					reinterpret_cast<char*>(scriptHandle.ToPointer()),
					reinterpret_cast<char*>(presetHandle.ToPointer()),
					team);
			}
			finally
			{
				Marshal::FreeHGlobal(presetHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	void Engine::RemoveScriptType(String^ script, unsigned long type, int team)
	{
		if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			::Remove_Script_Type(
				reinterpret_cast<char*>(scriptHandle.ToPointer()),
				type,
				team);
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	bool Engine::IsScriptAttached(IScriptableGameObj^ obj, String^ script)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			return ::Is_Script_Attached(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char*>(scriptHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	void Engine::AttachScriptOnce(IScriptableGameObj^ obj, String^ script, String^ params, ...array<Object^>^ args)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			if (params == nullptr)
			{
				::Attach_Script_Once(
					reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
					reinterpret_cast<char*>(scriptHandle.ToPointer()),
					nullptr);
			}
			else
			{
				IntPtr paramsHandle = Marshal::StringToHGlobalAnsi(String::Format(params, args));
				try
				{
					::Attach_Script_Once(
						reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
						reinterpret_cast<char*>(scriptHandle.ToPointer()),
						reinterpret_cast<char*>(paramsHandle.ToPointer()));
				}
				finally
				{
					Marshal::FreeHGlobal(paramsHandle);
				}
			}
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	void Engine::AttachScriptPresetOnce(String^ script, String^ params, String^ preset, int team)
	{
		if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}
		else if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
			try
			{
				if (params == nullptr)
				{
					::Attach_Script_Preset_Once(
						reinterpret_cast<char*>(scriptHandle.ToPointer()),
						nullptr,
						reinterpret_cast<char*>(presetHandle.ToPointer()),
						team);
				}
				else
				{
					IntPtr paramsHandle = Marshal::StringToHGlobalAnsi(params);
					try
					{
						::Attach_Script_Preset_Once(
							reinterpret_cast<char*>(scriptHandle.ToPointer()),
							reinterpret_cast<char*>(paramsHandle.ToPointer()),
							reinterpret_cast<char*>(presetHandle.ToPointer()),
							team);
					}
					finally
					{
						Marshal::FreeHGlobal(paramsHandle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(presetHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	void Engine::AttachScriptTypeOnce(String^ script, String^ params, unsigned long type, int team)
	{
		if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			if (params == nullptr)
			{
				::Attach_Script_Type_Once(
					reinterpret_cast<char*>(scriptHandle.ToPointer()),
					nullptr,
					type,
					team);
			}
			else
			{
				IntPtr paramsHandle = Marshal::StringToHGlobalAnsi(params);
				try
				{
					::Attach_Script_Type_Once(
						reinterpret_cast<char*>(scriptHandle.ToPointer()),
						reinterpret_cast<char*>(paramsHandle.ToPointer()),
						type,
						team);
				}
				finally
				{
					Marshal::FreeHGlobal(paramsHandle);
				}
			}
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	void Engine::AttachScriptBuilding(String^ script, String^ params, int team)
	{
		if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			if (params == nullptr)
			{
				::Attach_Script_Building(
					reinterpret_cast<char*>(scriptHandle.ToPointer()),
					nullptr,
					team);
			}
			else
			{
				IntPtr paramsHandle = Marshal::StringToHGlobalAnsi(params);
				try
				{
					::Attach_Script_Building(
						reinterpret_cast<char*>(scriptHandle.ToPointer()),
						reinterpret_cast<char*>(paramsHandle.ToPointer()),
						team);
				}
				finally
				{
					Marshal::FreeHGlobal(paramsHandle);
				}
			}
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	void Engine::AttachScriptIsPreset(IScriptableGameObj^ obj, String^ preset, String^ script, String^ params, int team)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}
		else if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
			try
			{
				if (params == nullptr)
				{
					::Attach_Script_Is_Preset(
						reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
						reinterpret_cast<char*>(presetHandle.ToPointer()),
						reinterpret_cast<char*>(scriptHandle.ToPointer()),
						nullptr,
						team);
				}
				else
				{
					IntPtr paramsHandle = Marshal::StringToHGlobalAnsi(params);
					try
					{
						::Attach_Script_Is_Preset(
							reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
							reinterpret_cast<char*>(presetHandle.ToPointer()),
							reinterpret_cast<char*>(scriptHandle.ToPointer()),
							reinterpret_cast<char*>(paramsHandle.ToPointer()),
							team);
					}
					finally
					{
						Marshal::FreeHGlobal(paramsHandle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(presetHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	void Engine::AttachScriptIsType(IScriptableGameObj^ obj, unsigned long type, String^ script, String^ params, int team)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			if (params == nullptr)
			{
				::Attach_Script_Is_Type(
					reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
					type,
					reinterpret_cast<char*>(scriptHandle.ToPointer()),
					nullptr,
					team);
			}
			else
			{
				IntPtr paramsHandle = Marshal::StringToHGlobalAnsi(params);
				try
				{
					::Attach_Script_Is_Type(
						reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
						type,
						reinterpret_cast<char*>(scriptHandle.ToPointer()),
						reinterpret_cast<char*>(paramsHandle.ToPointer()),
						team);
				}
				finally
				{
					Marshal::FreeHGlobal(paramsHandle);
				}
			}
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	void Engine::AttachScriptPlayerOnce(String^ script, String^ params, int team)
	{
		if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			if (params == nullptr)
			{
				::Attach_Script_Player_Once(
					reinterpret_cast<char*>(scriptHandle.ToPointer()),
					nullptr,
					team);
			}
			else
			{
				IntPtr paramsHandle = Marshal::StringToHGlobalAnsi(params);
				try
				{
					::Attach_Script_Player_Once(
						reinterpret_cast<char*>(scriptHandle.ToPointer()),
						reinterpret_cast<char*>(paramsHandle.ToPointer()),
						team);
				}
				finally
				{
					Marshal::FreeHGlobal(paramsHandle);
				}
			}
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	void Engine::RemoveDuplicateScript(IScriptableGameObj^ obj, String^ script)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			::Remove_Duplicate_Script(
				reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char*>(scriptHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	void Engine::AttachScriptAllBuildingsTeam(int team, String^ script, String^ params, bool once)
	{
		if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			if (params == nullptr)
			{
				::Attach_Script_All_Buildings_Team(
					team,
					reinterpret_cast<char*>(scriptHandle.ToPointer()),
					nullptr,
					once);
			}
			else
			{
				IntPtr paramsHandle = Marshal::StringToHGlobalAnsi(params);
				try
				{
					::Attach_Script_All_Buildings_Team(
						team,
						reinterpret_cast<char*>(scriptHandle.ToPointer()),
						reinterpret_cast<char*>(paramsHandle.ToPointer()),
						once);
				}
				finally
				{
					Marshal::FreeHGlobal(paramsHandle);
				}
			}
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	void Engine::AttachScriptAllTurretsTeam(int team, String^ script, String^ params, bool once)
	{
		if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			if (params == nullptr)
			{
				::Attach_Script_All_Turrets_Team(
					team,
					reinterpret_cast<char*>(scriptHandle.ToPointer()),
					nullptr,
					once);
			}
			else
			{
				IntPtr paramsHandle = Marshal::StringToHGlobalAnsi(params);
				try
				{
					::Attach_Script_All_Turrets_Team(
						team,
						reinterpret_cast<char*>(scriptHandle.ToPointer()),
						reinterpret_cast<char*>(paramsHandle.ToPointer()),
						once);
				}
				finally
				{
					Marshal::FreeHGlobal(paramsHandle);
				}
			}
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	IScriptableGameObj^ Engine::FindBuildingWithScript(int team, int type, String^ script, IScriptableGameObj^ caller)
	{
		if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			::ScriptableGameObj* result;
			if (caller == nullptr || caller->ScriptableGameObjPointer.ToPointer() == nullptr)
			{
				result = ::Find_Building_With_Script(
					team,
					type,
					reinterpret_cast<char*>(scriptHandle.ToPointer()),
					nullptr);
			}
			else
			{
				result = ::Find_Building_With_Script(
					team,
					type,
					reinterpret_cast<char*>(scriptHandle.ToPointer()),
					reinterpret_cast<::ScriptableGameObj *>(caller->ScriptableGameObjPointer.ToPointer()));
			}

			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	IScriptableGameObj^ Engine::FindObjectWithScript(String^ script)
	{
		if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			auto result = ::Find_Object_With_Script(
				reinterpret_cast<char*>(scriptHandle.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	IScriptableGameObj^ Engine::FindClosestObjectWithScript(String^ script, Vector3 pos)
	{
		if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		::Vector3 posVec;

		Vector3::ManagedToUnmanagedVector3(pos, posVec);

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			auto result = ::Find_Closest_Object_With_Script(
				reinterpret_cast<char*>(scriptHandle.ToPointer()),
				posVec);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	Generic::ICollection<IScriptableGameObj^>^ Engine::FindAllObjectsWithScript(String^ script)
	{
		if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			::SList<::ScriptableGameObj> tmp;

			::Find_All_Objects_With_Script(
				reinterpret_cast<char*>(scriptHandle.ToPointer()),
				tmp);

			Generic::ICollection<IScriptableGameObj^>^ result = gcnew Generic::List<IScriptableGameObj^>();

			for (auto currentNode = tmp.Head(); currentNode != nullptr; currentNode = currentNode->Next())
			{
				auto currentObj = currentNode->Data();
				if (currentObj == nullptr)
				{
					result->Add(nullptr);
				}
				else
				{
					result->Add(safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(currentObj)));
				}
			}

			return result;
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	Generic::ICollection<IScriptableGameObj^>^ Engine::FindAllObjectsWithScriptByDistance(String^ script, Vector3 position)
	{
		if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		::Vector3 positionVec;
		
		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			::SList<::ScriptableGameObj> tmp;

			::Find_All_Objects_With_Script_By_Distance(
				reinterpret_cast<char*>(scriptHandle.ToPointer()),
				tmp,
				positionVec);

			Generic::ICollection<IScriptableGameObj^>^ result = gcnew Generic::List<IScriptableGameObj^>();

			for (auto currentNode = tmp.Head(); currentNode != nullptr; currentNode = currentNode->Next())
			{
				auto currentObj = currentNode->Data();
				if (currentObj == nullptr)
				{
					result->Add(nullptr);
				}
				else
				{
					result->Add(safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(currentObj)));
				}
			}

			return result;
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	void Engine::SendCustomEventToObjectsWithScript(IScriptableGameObj^ sender, String^ script, int message, int param, float delay)
	{
		if (sender == nullptr || sender->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("sender");
		}
		if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			::Send_Custom_Event_To_Objects_With_Script(
				reinterpret_cast<::ScriptableGameObj *>(sender->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char*>(scriptHandle.ToPointer()),
				message,
				param,
				delay);
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	void Engine::SendCustomEventToObjectsWithScriptRanged(IScriptableGameObj^ sender, String^ script, int message, int param, float delay, float range)
	{
		if (sender == nullptr || sender->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("sender");
		}
		if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			::Send_Custom_Event_To_Objects_With_Script_Ranged(
				reinterpret_cast<::ScriptableGameObj*>(sender->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char*>(scriptHandle.ToPointer()),
				message,
				param,
				delay,
				range);
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	IScriptImpClass^ Engine::FindScriptOnObject(IScriptableGameObj^ obj, String^ script)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			auto result = ::Find_Script_On_Object(
				reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char*>(scriptHandle.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew ScriptImpClass(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	void Engine::AttachScriptOccupants(IScriptableGameObj^ obj, String^ script, String^ params, ...array<Object^>^ args)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (script == nullptr)
		{
			throw gcnew ArgumentNullException("script");
		}

		IntPtr scriptHandle = Marshal::StringToHGlobalAnsi(script);
		try
		{
			if (params == nullptr)
			{
				::Attach_Script_Occupants(
					reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
					reinterpret_cast<char*>(scriptHandle.ToPointer()),
					nullptr);
			}
			else
			{
				IntPtr paramsHandle = Marshal::StringToHGlobalAnsi(String::Format(params, args));
				try
				{
					::Attach_Script_Occupants(
						reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
						reinterpret_cast<char*>(scriptHandle.ToPointer()),
						reinterpret_cast<char*>(paramsHandle.ToPointer()));
				}
				finally
				{
					Marshal::FreeHGlobal(paramsHandle);
				}
			}
		}
		finally
		{
			Marshal::FreeHGlobal(scriptHandle);
		}
	}

	String^ Engine::GetTranslatedString(unsigned long id)
	{
		auto result = ::Get_Wide_Translated_String(id);

		return gcnew String(result); // Should never return nullptr
	}

	String^ Engine::GetTranslatedPresetName(IScriptableGameObj^ obj)
	{
		// There is no wide variant, and it feels stupid to do a 1000 string conversions, while we just want the unicode version
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			return String::Empty;
		}

		auto damageableGameObjPtr = reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer())->As_DamageableGameObj();
		if (damageableGameObjPtr == nullptr)
		{
			return String::Empty;
		}

		return GetTranslatedString(damageableGameObjPtr->Get_Definition().Get_Translated_Name_ID());
	}

	String^ Engine::GetTranslatedWeapon(IScriptableGameObj^ obj, int position)
	{
		// There is no wide variant, and it feels stupid to do a 1000 string conversions, while we just want the unicode version
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			return String::Empty;
		}

		auto physicalGameObjPtr = reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer())->As_PhysicalGameObj();
		if (physicalGameObjPtr == nullptr)
		{
			return String::Empty;
		}

		auto armedGameObjPtr = physicalGameObjPtr->As_ArmedGameObj();
		if (armedGameObjPtr == nullptr)
		{
			return String::Empty;
		}

		auto weaponBagClassPtr = armedGameObjPtr->Get_Weapon_Bag();
		if (weaponBagClassPtr == nullptr)
		{
			return String::Empty;
		}

		if (position < 0 || position >= weaponBagClassPtr->Get_Count())
		{
			throw gcnew ArgumentOutOfRangeException("position");
		}

		auto weaponClassPtr = weaponBagClassPtr->Peek_Weapon(position);
		if (weaponClassPtr == nullptr)
		{
			return String::Empty;
		}
		
		return GetTranslatedString(weaponClassPtr->Get_Definition()->IconNameID);
	}

	String^ Engine::GetCurrentTranslatedWeapon(IScriptableGameObj^ obj)
	{
		const wchar_t* result;
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			result = ::Get_Current_Wide_Translated_Weapon(nullptr);
		}
		else
		{
			result = ::Get_Current_Wide_Translated_Weapon(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
		}

		if (result == nullptr)
		{
			return String::Empty; // To keep consistent with other methods as the unmanaged function isn't
		}
		else
		{
			return gcnew String(result);
		}
	}

	String^ Engine::GetTeamName(int team)
	{
		auto result = ::Get_Wide_Team_Name(team);

		return gcnew String(result); // Should never return nullptr
	}

	String^ Engine::GetVehicleName(IScriptableGameObj^ obj)
	{
		const wchar_t* result;
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			result = ::Get_Wide_Vehicle_Name(nullptr);
		}
		else
		{
			result = ::Get_Wide_Vehicle_Name(
				reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
		}

		return gcnew String(result); // Should never return nullptr
	}

	String^ Engine::GetTranslatedDefinitionName(String^ preset)
	{
		// There is no wide variant, and it feels stupid to do a 1000 string conversions, while we just want the unicode version
		IDefinitionClass^ def = FindNamedDefinition(preset);
		if (def == nullptr || def->DefinitionClassPointer.ToPointer() == nullptr)
		{
			return String::Empty;
		}

		::DamageableGameObjDef* damageableDef = static_cast<::DamageableGameObjDef*>(
			reinterpret_cast<::DefinitionClass*>(def->DefinitionClassPointer.ToPointer()));

		return GetTranslatedString(damageableDef->Get_Translated_Name_ID());
	}

	bool Engine::IsValidStringID(unsigned long id)
	{
		return ::Is_Valid_String_ID(id);
	}

	unsigned long Engine::GetStringIDByDesc(String^ desc)
	{
		if (desc == nullptr)
		{
			throw gcnew ArgumentNullException("desc");
		}

		IntPtr descHandle = Marshal::StringToHGlobalAnsi(desc);
		try
		{
			return ::Get_String_ID_By_Desc(
				reinterpret_cast<char *>(descHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(descHandle);
		}
	}

	unsigned long Engine::GetStringSoundID(unsigned long id)
	{
		return ::Get_String_Sound_ID(id);
	}

	int Engine::GetBullets(IScriptableGameObj^ obj, String^ weapon)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (weapon == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		IntPtr weaponHandle = Marshal::StringToHGlobalAnsi(weapon);
		try
		{
			return ::Get_Bullets(
				reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char *>(weaponHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(weaponHandle);
		}
	}

	int Engine::GetMaxBullets(IScriptableGameObj^ obj, String^ weapon)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (weapon == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		IntPtr weaponHandle = Marshal::StringToHGlobalAnsi(weapon);
		try
		{
			return ::Get_Max_Bullets(
				reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char*>(weaponHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(weaponHandle);
		}
	}

	int Engine::GetClipBullets(IScriptableGameObj^ obj, String^ weapon)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (weapon == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		IntPtr weaponHandle = Marshal::StringToHGlobalAnsi(weapon);
		try
		{
			return ::Get_Clip_Bullets(
				reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char*>(weaponHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(weaponHandle);
		}
	}

	int Engine::GetMaxClipBullets(IScriptableGameObj^ obj, String^ weapon)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (weapon == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		IntPtr weaponHandle = Marshal::StringToHGlobalAnsi(weapon);
		try
		{
			return ::Get_Max_Clip_Bullets(
				reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char*>(weaponHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(weaponHandle);
		}
	}

	int Engine::GetTotalBullets(IScriptableGameObj^ obj, String^ weapon)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (weapon == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		IntPtr weaponHandle = Marshal::StringToHGlobalAnsi(weapon);
		try
		{
			return ::Get_Total_Bullets(
				reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char*>(weaponHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(weaponHandle);
		}
	}

	int Engine::GetMaxTotalBullets(IScriptableGameObj^ obj, String^ weapon)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (weapon == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		IntPtr weaponHandle = Marshal::StringToHGlobalAnsi(weapon);
		try
		{
			return ::Get_Max_Total_Bullets(
				reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char*>(weaponHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(weaponHandle);
		}
	}

	int Engine::GetCurrentBullets(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Current_Bullets(
			reinterpret_cast<::ScriptableGameObj *>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	int Engine::GetCurrentMaxBullets(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Current_Max_Bullets(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	int Engine::GetCurrentClipBullets(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Current_Clip_Bullets(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	int Engine::GetCurrentClipMaxBullets(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Current_Clip_Max_Bullets(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	int Engine::GetCurrentTotalBullets(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Current_Total_Bullets(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	int Engine::GetCurrentTotalMaxBullets(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Current_Total_Max_Bullets(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	int Engine::GetPositionBullets(IScriptableGameObj^ obj, int position)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Position_Bullets(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
			position);
	}

	int Engine::GetPositionMaxBullets(IScriptableGameObj^ obj, int position)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Position_Max_Bullets(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
			position);
	}

	int Engine::GetPositionClipBullets(IScriptableGameObj^ obj, int position)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Position_Clip_Bullets(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
			position);
	}

	int Engine::GetPositionClipMaxBullets(IScriptableGameObj^ obj, int position)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Position_Clip_Max_Bullets(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
			position);
	}

	int Engine::GetPositionTotalBullets(IScriptableGameObj^ obj, int position)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Position_Total_Bullets(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
			position);
	}

	int Engine::GetPositionTotalMaxBullets(IScriptableGameObj^ obj, int position)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Position_Total_Max_Bullets(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
			position);
	}

	String^ Engine::GetPowerupWeapon(String^ powerup)
	{
		if (powerup == nullptr)
		{
			throw gcnew ArgumentNullException("powerup");
		}

		IntPtr powerupHandle = Marshal::StringToHGlobalAnsi(powerup);
		try
		{
			auto result = ::Get_Powerup_Weapon(
				reinterpret_cast<char *>(powerupHandle.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew String(result);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(powerupHandle);
		}
	}

	IAmmoDefinitionClass^ Engine::GetWeaponAmmoDefinition(String^ weapon, bool primaryFire)
	{
		if (weapon == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		IntPtr weaponHandle = Marshal::StringToHGlobalAnsi(weapon);
		try
		{
			auto defPtr = ::Get_Weapon_Ammo_Definition(
				reinterpret_cast<char *>(weaponHandle.ToPointer()),
				primaryFire);
			if (defPtr == nullptr)
			{
				return nullptr;
			}
			else
			{
				return safe_cast<IAmmoDefinitionClass^>(DefinitionClass::CreateDefinitionClassWrapper(defPtr));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(weaponHandle);
		}
	}

	IWeaponDefinitionClass^ Engine::GetWeaponDefinition(String^ weapon)
	{
		if (weapon == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		IntPtr weaponHandle = Marshal::StringToHGlobalAnsi(weapon);
		try
		{
			auto defPtr = ::Get_Weapon_Definition(
				reinterpret_cast<char*>(weaponHandle.ToPointer()));
			if (defPtr == nullptr)
			{
				return nullptr;
			}
			else
			{
				return safe_cast<IWeaponDefinitionClass^>(DefinitionClass::CreateDefinitionClassWrapper(defPtr));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(weaponHandle);
		}
	}

	IWeaponDefinitionClass^ Engine::GetCurrentWeaponDefinition(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto defPtr = ::Get_Current_Weapon_Definition(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IWeaponDefinitionClass^>(DefinitionClass::CreateDefinitionClassWrapper(defPtr));
		}
	}

	IWeaponDefinitionClass^ Engine::GetPositionWeaponDefinition(IScriptableGameObj^ obj, int position)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto defPtr = ::Get_Position_Weapon_Definition(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
			position);
		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IWeaponDefinitionClass^>(DefinitionClass::CreateDefinitionClassWrapper(defPtr));
		}
	}

	IExplosionDefinitionClass^ Engine::GetExplosion(String^ explosion)
	{
		if (explosion == nullptr)
		{
			throw gcnew ArgumentNullException("explosion");
		}

		IntPtr explosionHandle = Marshal::StringToHGlobalAnsi(explosion);
		try
		{
			auto defPtr = ::Get_Explosion(
				reinterpret_cast<char *>(explosionHandle.ToPointer()));
			if (defPtr == nullptr)
			{
				return nullptr;
			}
			else
			{
				return safe_cast<IExplosionDefinitionClass^>(DefinitionClass::CreateDefinitionClassWrapper(defPtr));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(explosionHandle);
		}
	}

	String^ Engine::GetPowerupWeaponByObj(IScriptableGameObj^ powerup)
	{
		if (powerup == nullptr || powerup->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("powerup");
		}

		auto result = ::Get_Powerup_Weapon_By_Obj(
			reinterpret_cast<::ScriptableGameObj*>(powerup->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	int Engine::GetCurrentWeaponStyle(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Current_Weapon_Style(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	int Engine::GetPositionWeaponStyle(IScriptableGameObj^ obj, int position)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Position_Weapon_Style(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
			position);
	}

	int Engine::GetWeaponStyle(IScriptableGameObj^ obj, String^ weapon)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (weapon == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		IntPtr weaponHandle = Marshal::StringToHGlobalAnsi(weapon);
		try
		{
			return ::Get_Weapon_Style(
				reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char*>(weaponHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(weaponHandle);
		}
	}

	void Engine::DisarmBeacon(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Disarm_Beacon(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::DisarmBeacons(int playerID)
	{
		::Disarm_Beacons(playerID);
	}

	void Engine::DisarmC4(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Disarm_C4(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	void Engine::DisarmAllC4Beacons(int playerID)
	{
		::Disarm_All_C4_Beacons(playerID);
	}

	String^ Engine::GetCurrentWeapon(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::Get_Current_Weapon(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	int Engine::GetWeaponCount(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_Weapon_Count(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	String^ Engine::GetWeapon(IScriptableGameObj^ obj, int position)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::Get_Weapon(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
			position);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	bool Engine::HasWeapon(IScriptableGameObj^ obj, String^ weapon)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}
		else if (weapon == nullptr)
		{
			throw gcnew ArgumentNullException("weapon");
		}

		IntPtr weaponHandle = Marshal::StringToHGlobalAnsi(weapon);
		try
		{
			return ::Has_Weapon(
				reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()),
				reinterpret_cast<char*>(weaponHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(weaponHandle);
		}
	}

	IScriptableGameObj^ Engine::FindBeacon(int number, int team)
	{
		auto result = ::Find_Beacon(number, team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	int Engine::GetC4Count(int team, int type)
	{
		return ::Get_C4_Count(team, type);
	}

	int Engine::GetC4Count(int team)
	{
		return ::Get_C4_Count(team);
	}

	void Engine::DefuseOwnedC4(int playerID, int type)
	{
		::Defuse_Owned_C4(playerID, type);
	}

	void Engine::DefuseOwnedC4(int playerID)
	{
		::Defuse_Owned_C4(playerID);
	}

	void Engine::DefuseAttachedC4(IScriptableGameObj^ attachedObject)
	{
		if (attachedObject == nullptr || attachedObject->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("attachedObject");
		}

		::Defuse_Attached_C4(
			reinterpret_cast<::ScriptableGameObj*>(attachedObject->ScriptableGameObjPointer.ToPointer()));
	}

	int Engine::GetBeaconCount(int team)
	{
		return ::Get_Beacon_Count(team);
	}

	int Engine::GetC4Mode(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Get_C4_Mode(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	IScriptableGameObj^ Engine::GetC4Planter(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::Get_C4_Planter(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IScriptableGameObj^ Engine::GetC4Attached(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::Get_C4_Attached(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IScriptableGameObj^ Engine::GetBeaconPlanter(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		auto result = ::Get_Beacon_Planter(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IBeaconGameObj^ Engine::FindNearestBeacon(Vector3 position, int team)
	{
		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		auto result = ::Find_Nearest_Beacon(positionVec, team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IBeaconGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	void Engine::DebugMsg(String^ format, ...array<Object^>^ args)
	{
		if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::DebugMsg(
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	int Engine::GetRandomInt(int min, int max)
	{
		return ::Get_Random_Int(min, max);
	}

	float Engine::GetRandomFloat(float min, float max)
	{
		return ::Get_Random_Float(min, max);
	}

	bool Engine::GetRandomBool()
	{
		return ::Get_Random_Bool();
	}

	float Engine::Diff(float first, float second)
	{
		return ::Diff(first, second);
	}

	int Engine::Diff(int first, int second)
	{
		return ::Diff(first, second);
	}

	String^ Engine::FormatTime(unsigned long time)
	{
		return gcnew String(::Format_Time(time).Peek_Buffer());
	}

	String^ Engine::LongToIP(unsigned long ip)
	{
		return gcnew String(::Long_To_IP(ip).Peek_Buffer());
	}

	float Engine::Round(float number)
	{
		return ::Round(number);
	}

	void Engine::PowerBase(int team, bool powered)
	{
		::Power_Base(team, powered);
	}

	void Engine::SetCanGenerateSoldiers(int team, bool canGenerate)
	{
		::Set_Can_Generate_Soldiers(team, canGenerate);
	}

	void Engine::SetCanGenerateVehicles(int team, bool canGenerate)
	{
		::Set_Can_Generate_Vehicles(team, canGenerate);
	}

	void Engine::DestroyBase(int team)
	{
		::Destroy_Base(team);
	}

	void Engine::BeaconDestroyedBase(int team, bool destroyed)
	{
		::Beacon_Destroyed_Base(team, destroyed);
	}

	void Engine::EnableBaseRadar(int team, bool enable)
	{
		::Enable_Base_Radar(team, enable);
	}

	bool Engine::IsHarvester(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Is_Harvester(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool Engine::IsRadarEnabled(int team)
	{
		return ::Is_Radar_Enabled(team);
	}

	int Engine::BuildingType(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Building_Type(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool Engine::IsBuildingDead(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Is_Building_Dead(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	IScriptableGameObj^ Engine::FindBuildingByType(int team, int type)
	{
		auto result = ::Find_Building_By_Type(team, type);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IScriptableGameObj^ Engine::FindBaseDefense(int team)
	{
		auto result = ::Find_Base_Defense(team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IScriptableGameObj^ Engine::CreateBuilding(String^ preset, Vector3 position)
	{
		if (preset == nullptr)
		{
			throw gcnew ArgumentNullException("preset");
		}

		::Vector3 positionVec;

		Vector3::ManagedToUnmanagedVector3(position, positionVec);

		IntPtr presetHandle = Marshal::StringToHGlobalAnsi(preset);
		try
		{
			auto result = ::Create_Building(
				reinterpret_cast<char*>(presetHandle.ToPointer()),
				positionVec);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(presetHandle);
		}
	}

	IScriptableGameObj^ Engine::FindHarvester(int team)
	{
		auto result = ::Find_Harvester(team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	bool Engine::IsBasePowered(int team)
	{
		return ::Is_Base_Powered(team);
	}

	bool Engine::CanGenerateVehicles(int team)
	{
		return ::Can_Generate_Vehicles(team);
	}

	bool Engine::CanGenerateSoldiers(int team)
	{
		return ::Can_Generate_Soldiers(team);
	}

	int Engine::GetBuildingCountTeam(int team)
	{
		return ::Get_Building_Count_Team(team);
	}

	IScriptableGameObj^ Engine::FindBuildingByTeam(int team)
	{
		auto result = ::Find_Building_By_Team(team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IScriptableGameObj^ Engine::FindBuildingByPreset(int team, String^ presetName)
	{
		if (presetName == nullptr)
		{
			throw gcnew ArgumentNullException("presetName");
		}

		IntPtr presetNameHandle = Marshal::StringToHGlobalAnsi(presetName);
		try
		{
			auto result = ::Find_Building_By_Preset(
				team,
				reinterpret_cast<char*>(presetNameHandle.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(presetNameHandle);
		}
	}

	IScriptableGameObj^ Engine::FindPowerPlant(int team)
	{
		auto result = ::Find_Power_Plant(team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IScriptableGameObj^ Engine::FindConstructionYard(int team)
	{
		auto result = ::Find_Construction_Yard(team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IScriptableGameObj^ Engine::FindRefinery(int team)
	{
		auto result = ::Find_Refinery(team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IScriptableGameObj^ Engine::FindRepairBay(int team)
	{
		auto result = ::Find_Repair_Bay(team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IScriptableGameObj^ Engine::FindSoldierFactory(int team)
	{
		auto result = ::Find_Soldier_Factory(team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IScriptableGameObj^ Engine::FindVehicleFactory(int team)
	{
		auto result = ::Find_Vehicle_Factory(team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IScriptableGameObj^ Engine::FindComCenter(int team)
	{
		auto result = ::Find_Com_Center(team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IScriptableGameObj^ Engine::FindSpecial(int team)
	{
		auto result = ::Find_Special(team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IScriptableGameObj^ Engine::FindNavalFactory(int team)
	{
		auto result = ::Find_Naval_Factory(team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IScriptableGameObj^ Engine::FindTechCenter(int team)
	{
		auto result = ::Find_Tech_Center(team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IScriptableGameObj^ Engine::FindHelipad(int team)
	{
		auto result = ::Find_Helipad(team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	IScriptableGameObj^ Engine::FindShrine(int team)
	{
		auto result = ::Find_Shrine(team);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IScriptableGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	void Engine::RestoreBuilding(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		::Restore_Building(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	int Engine::GetHarvesterPresetID(int team)
	{
		return ::Get_Harvester_Preset_ID(team);
	}

	bool Engine::IsHarvesterPreset(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		return ::Is_Harvester_Preset(
			reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
	}

	bool Engine::VehiclePresetIsAir(int preset)
	{
		return ::Vehicle_Preset_Is_Air(preset);
	}

	bool Engine::VehiclePresetIsNaval(int preset)
	{
		return ::Vehicle_Preset_Is_Naval(preset);
	}

	Vector3 Engine::GetBaseCenter(int team)
	{
		Vector3 result;

		Vector3::UnmanagedToManagedVector3(::Get_Base_Center(team), result);

		return result;
	}

	TimeSpan Engine::SecondsToHms(float secs)
	{
		int hours;
		int minutes;
		int seconds;

		::Seconds_To_Hms(secs, hours, minutes, seconds);

		TimeSpan result;
		result.Add(TimeSpan::FromHours(hours));
		result.Add(TimeSpan::FromMinutes(minutes));
		result.Add(TimeSpan::FromSeconds(minutes));

		return result;
	}

	void Engine::InitEngine()
	{
		::InitEngine();
	}

	String^ Engine::UppercaseAOrAn(String^ str)
	{
		if (str == nullptr)
		{
			throw gcnew ArgumentNullException("str");
		}

		IntPtr strHandle = Marshal::StringToHGlobalUni(str);
		try
		{
			auto result = ::A_Or_An(
				reinterpret_cast<wchar_t*>(strHandle.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew String(result);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(strHandle);
		}
	}

	String^ Engine::LowercaseAOrAn(String^ str)
	{
		if (str == nullptr)
		{
			throw gcnew ArgumentNullException("str");
		}

		IntPtr strHandle = Marshal::StringToHGlobalUni(str);
		try
		{
			auto result = ::a_or_an(
				reinterpret_cast<wchar_t*>(strHandle.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew String(result);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(strHandle);
		}
	}

	String^ Engine::UppercaseAOrAnPrepend(String^ str)
	{
		if (str == nullptr)
		{
			throw gcnew ArgumentNullException("str");
		}

		IntPtr strHandle = Marshal::StringToHGlobalUni(str);
		try
		{
			return gcnew String(::A_Or_An_Prepend(
				reinterpret_cast<wchar_t*>(strHandle.ToPointer())).Peek_Buffer());
		}
		finally
		{
			Marshal::FreeHGlobal(strHandle);
		}
	}

	String^ Engine::LowercaseAOrAnPrepend(String^ str)
	{
		if (str == nullptr)
		{
			throw gcnew ArgumentNullException("str");
		}

		IntPtr strHandle = Marshal::StringToHGlobalUni(str);
		try
		{
			return gcnew String(::a_or_an_Prepend(
				reinterpret_cast<wchar_t*>(strHandle.ToPointer())).Peek_Buffer());
		}
		finally
		{
			Marshal::FreeHGlobal(strHandle);
		}
	}

	String^ Engine::MakePossessive(String^ str)
	{
		if (str == nullptr)
		{
			throw gcnew ArgumentNullException("str");
		}

		IntPtr strHandle = Marshal::StringToHGlobalUni(str);
		try
		{
			::WideStringClass tmp(reinterpret_cast<wchar_t*>(strHandle.ToPointer()));

			return gcnew String(::Make_Possessive(tmp).Peek_Buffer());
		}
		finally
		{
			Marshal::FreeHGlobal(strHandle);
		}
	}

	bool Engine::IsNumeric(String^ str)
	{
		if (str == nullptr)
		{
			throw gcnew ArgumentNullException("str");
		}

		IntPtr strHandle = Marshal::StringToHGlobalAnsi(str);
		try
		{
			return ::Is_Numeric(
				reinterpret_cast<char*>(strHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(strHandle);
		}
	}

	bool Engine::IsNumber(String^ str)
	{
		if (str == nullptr)
		{
			throw gcnew ArgumentNullException("str");
		}

		IntPtr strHandle = Marshal::StringToHGlobalAnsi(str);
		try
		{
			return ::Is_Number(
				reinterpret_cast<char*>(strHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(strHandle);
		}
	}

	bool Engine::IsAlpha(String^ str)
	{
		if (str == nullptr)
		{
			throw gcnew ArgumentNullException("str");
		}

		IntPtr strHandle = Marshal::StringToHGlobalAnsi(str);
		try
		{
			return ::Is_Alpha(
				reinterpret_cast<char*>(strHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(strHandle);
		}
	}

	unsigned long Engine::CRCMemory(array<unsigned char>^ data, unsigned long crc)
	{
		if (data == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		pin_ptr<unsigned char> pinnedData = &data[0];
		unsigned char* dataPtr = pinnedData;

		return CRC_Memory(dataPtr, crc);
	}

	unsigned long Engine::CRCMemory(array<unsigned char>^ data)
	{
		if (data == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		pin_ptr<unsigned char> pinnedData = &data[0];
		unsigned char* dataPtr = pinnedData;

		return CRC_Memory(dataPtr, static_cast<unsigned long>(data->LongLength));
	}

	unsigned long Engine::CRCString(String^ data, unsigned long crc)
	{
		if (data == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		IntPtr dataHandle = Marshal::StringToHGlobalAnsi(data);
		try
		{
			return CRC_String(
				reinterpret_cast<char*>(dataHandle.ToPointer()),
				crc);
		}
		finally
		{
			Marshal::FreeHGlobal(dataHandle);
		}
	}

	unsigned long Engine::CRCStringi(String^ data, unsigned long crc)
	{
		if (data == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		IntPtr dataHandle = Marshal::StringToHGlobalAnsi(data);
		try
		{
			return CRC_Stringi(
				reinterpret_cast<char*>(dataHandle.ToPointer()),
				crc);
		}
		finally
		{
			Marshal::FreeHGlobal(dataHandle);
		}
	}

	unsigned long Engine::CRCStringi(String^ data)
	{
		if (data == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		IntPtr dataHandle = Marshal::StringToHGlobalAnsi(data);
		try
		{
			return CRC_Stringi(
				reinterpret_cast<char*>(dataHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(dataHandle);
		}
	}

	unsigned long Engine::CRCFile(IFileClass^ file, uint32 seed)
	{
		if (file == nullptr || file->FileClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("file");
		}

		return CRC_File(
			reinterpret_cast<::FileClass*>(file->FileClassPointer.ToPointer()),
			seed);
	}

	unsigned long Engine::CRCFile(IFileClass^ file)
	{
		if (file == nullptr || file->FileClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("file");
		}

		return CRC_File(
			reinterpret_cast<::FileClass*>(file->FileClassPointer.ToPointer()));
	}

	void Engine::LogKilledMessage(IScriptableGameObj^ obj, IScriptableGameObj^ killer, String^ objectType)
	{
		if (objectType == nullptr)
		{
			throw gcnew ArgumentNullException("objectType");
		}

		::ScriptableGameObj* objPtr;
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			objPtr = nullptr;
		}
		else
		{
			objPtr = reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer());
		}

		::ScriptableGameObj* killerPtr;
		if (killer == nullptr || killer->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			killerPtr = nullptr;
		}
		else
		{
			killerPtr = reinterpret_cast<::ScriptableGameObj*>(killer->ScriptableGameObjPointer.ToPointer());
		}

		IntPtr objectTypePtr = Marshal::StringToHGlobalAnsi(objectType);
		try
		{
			::Log_Killed_Message(objPtr, killerPtr, reinterpret_cast<const char*>(objectTypePtr.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(objectTypePtr);
		}
	}

	IntPtr Engine::GetPlayerListPointer::get()
	{
		return IntPtr(::Get_Player_List);
	}

	void Engine::GetPlayerListPointer::set(IntPtr value)
	{
		::Get_Player_List = reinterpret_cast<::gpl>(value.ToPointer());
	}

	IntPtr Engine::GetCurrentMapIndexPointer::get()
	{
		return IntPtr(::Get_Current_Map_Index);
	}

	void Engine::GetCurrentMapIndexPointer::set(IntPtr value)
	{
		::Get_Current_Map_Index = reinterpret_cast<::gcmi>(value.ToPointer());
	}

	IntPtr Engine::GetMapPointer::get()
	{
		return IntPtr(::Get_Map);
	}

	void Engine::GetMapPointer::set(IntPtr value)
	{
		::Get_Map = reinterpret_cast<::gm>(value.ToPointer());
	}

	IntPtr Engine::GetMapCountPointer::get()
	{
		return IntPtr(::Get_Map_Count);
	}

	void Engine::GetMapCountPointer::set(IntPtr value)
	{
		::Get_Map_Count = reinterpret_cast<::gmc>(value.ToPointer());
	}

	IntPtr Engine::SetMapPointer::get()
	{
		return IntPtr(::Set_Map);
	}

	void Engine::SetMapPointer::set(IntPtr value)
	{
		::Set_Map = reinterpret_cast<::smx>(value.ToPointer());
	}

	IntPtr Engine::GetGameDefinitionsPointer::get()
	{
		return IntPtr(::Get_Game_Definitions);
	}

	void Engine::GetGameDefinitionsPointer::set(IntPtr value)
	{
		::Get_Game_Definitions = reinterpret_cast<::ggd>(value.ToPointer());
	}

	IntPtr Engine::EvictClientPointer::get()
	{
		return IntPtr(::Evict_Client);
	}

	void Engine::EvictClientPointer::set(IntPtr value)
	{
		::Evict_Client = reinterpret_cast<::ec>(value.ToPointer());
	}

	IntPtr Engine::GetClientSerialHashPointer::get()
	{
		return IntPtr(::Get_Client_Serial_Hash);
	}

	void Engine::GetClientSerialHashPointer::set(IntPtr value)
	{
		::Get_Client_Serial_Hash = reinterpret_cast<::gcsh>(value.ToPointer());
	}

	IntPtr Engine::GetGameObjByPlayerNamePointer::get()
	{
		return IntPtr(::Get_GameObj_By_Player_Name);
	}

	void Engine::GetGameObjByPlayerNamePointer::set(IntPtr value)
	{
		::Get_GameObj_By_Player_Name = reinterpret_cast<::ggobpn>(value.ToPointer());
	}

	IntPtr Engine::SendCustomAllPlayersPointer::get()
	{
		return IntPtr(::Send_Custom_All_Players);
	}

	void Engine::SendCustomAllPlayersPointer::set(IntPtr value)
	{
		::Send_Custom_All_Players = reinterpret_cast<::scap>(value.ToPointer());
	}

	IntPtr Engine::StealTeamCreditsPointer::get()
	{
		return IntPtr(::Steal_Team_Credits);
	}

	void Engine::StealTeamCreditsPointer::set(IntPtr value)
	{
		::Steal_Team_Credits = reinterpret_cast<::stc>(value.ToPointer());
	}

	IntPtr Engine::GetTeamCreditsPointer::get()
	{
		return IntPtr(::Get_Team_Credits);
	}

	void Engine::GetTeamCreditsPointer::set(IntPtr value)
	{
		::Get_Team_Credits = reinterpret_cast<::gtc>(value.ToPointer());
	}

	IntPtr Engine::SetCurrentBulletsPointer::get()
	{
		return IntPtr(::Set_Current_Bullets);
	}

	void Engine::SetCurrentBulletsPointer::set(IntPtr value)
	{
		::Set_Current_Bullets = reinterpret_cast<::sclb>(value.ToPointer());
	}

	IntPtr Engine::SetCurrentClipBulletsPointer::get()
	{
		return IntPtr(::Set_Current_Clip_Bullets);
	}

	void Engine::SetCurrentClipBulletsPointer::set(IntPtr value)
	{
		::Set_Current_Clip_Bullets = reinterpret_cast<::sclb>(value.ToPointer());
	}

	IntPtr Engine::SetPositionBulletsPointer::get()
	{
		return IntPtr(::Set_Position_Bullets);
	}

	void Engine::SetPositionBulletsPointer::set(IntPtr value)
	{
		::Set_Position_Bullets = reinterpret_cast<::spb>(value.ToPointer());
	}

	IntPtr Engine::SetPositionClipBulletsPointer::get()
	{
		return IntPtr(::Set_Position_Clip_Bullets);
	}

	void Engine::SetPositionClipBulletsPointer::set(IntPtr value)
	{
		::Set_Position_Clip_Bullets = reinterpret_cast<::spb>(value.ToPointer());
	}

	IntPtr Engine::SetBulletsPointer::get()
	{
		return IntPtr(::Set_Bullets);
	}

	void Engine::SetBulletsPointer::set(IntPtr value)
	{
		::Set_Bullets = reinterpret_cast<::sb>(value.ToPointer());
	}

	IntPtr Engine::SetClipBulletsPointer::get()
	{
		return IntPtr(::Set_Clip_Bullets);
	}

	void Engine::SetClipBulletsPointer::set(IntPtr value)
	{
		::Set_Clip_Bullets = reinterpret_cast<::sb>(value.ToPointer());
	}

	IntPtr Engine::DisplayGameHintPointer::get()
	{
		return IntPtr(::Display_Game_Hint);
	}

	void Engine::DisplayGameHintPointer::set(IntPtr value)
	{
		::Display_Game_Hint = reinterpret_cast<::dgh>(value.ToPointer());
	}

	IntPtr Engine::DisplayGameHintImagePointer::get()
	{
		return IntPtr(::Display_Game_Hint_Image);
	}

	void Engine::DisplayGameHintImagePointer::set(IntPtr value)
	{
		::Display_Game_Hint_Image = reinterpret_cast<::dghi>(value.ToPointer());
	}

	IntPtr Engine::SetScopePointer::get()
	{
		throw gcnew NotSupportedException("No linkage");

		//return IntPtr(::Set_Scope);
	}

	void Engine::SetScopePointer::set(IntPtr value)
	{
		throw gcnew NotSupportedException("No linkage");

		//::Set_Scope = reinterpret_cast<::ss>(value.ToPointer());
	}

	IntPtr Engine::GetCurrentMusicTrackPointer::get()
	{
		return IntPtr(::GetCurrentMusicTrack);
	}

	void Engine::GetCurrentMusicTrackPointer::set(IntPtr value)
	{
		::GetCurrentMusicTrack = reinterpret_cast<::gcmt>(value.ToPointer());
	}

	IntPtr Engine::SetInfoTexturePointer::get()
	{
		return IntPtr(::Set_Info_Texture);
	}

	void Engine::SetInfoTexturePointer::set(IntPtr value)
	{
		::Set_Info_Texture = reinterpret_cast<::sit>(value.ToPointer());
	}

	IntPtr Engine::ClearInfoTexturePointer::get()
	{
		return IntPtr(::Clear_Info_Texture);
	}

	void Engine::ClearInfoTexturePointer::set(IntPtr value)
	{
		::Clear_Info_Texture = reinterpret_cast<::cit>(value.ToPointer());
	}

	IntPtr Engine::EnableStealthPlayerPointer::get()
	{
		return IntPtr(::Enable_Stealth_Player);
	}

	void Engine::EnableStealthPlayerPointer::set(IntPtr value)
	{
		::Enable_Stealth_Player = reinterpret_cast<::_Enable_Stealth_Player>(value.ToPointer());
	}

	IntPtr Engine::SetFogEnablePlayerPointer::get()
	{
		return IntPtr(::Set_Fog_Enable_Player);
	}

	void Engine::SetFogEnablePlayerPointer::set(IntPtr value)
	{
		::Set_Fog_Enable_Player = reinterpret_cast<::_Set_Fog_Enable_Player>(value.ToPointer());
	}

	IntPtr Engine::SetFogRangePlayerPointer::get()
	{
		return IntPtr(::Set_Fog_Range_Player);
	}

	void Engine::SetFogRangePlayerPointer::set(IntPtr value)
	{
		::Set_Fog_Range_Player = reinterpret_cast<::_Set_Fog_Range_Player>(value.ToPointer());
	}

	IntPtr Engine::SetBackgroundMusicPlayerPointer::get()
	{
		return IntPtr(::Set_Background_Music_Player);
	}

	void Engine::SetBackgroundMusicPlayerPointer::set(IntPtr value)
	{
		::Set_Background_Music_Player = reinterpret_cast<::_Set_Background_Music_Player>(value.ToPointer());
	}

	IntPtr Engine::FadeBackgroundMusicPlayerPointer::get()
	{
		return IntPtr(::Fade_Background_Music_Player);
	}

	void Engine::FadeBackgroundMusicPlayerPointer::set(IntPtr value)
	{
		::Fade_Background_Music_Player = reinterpret_cast<::_Fade_Background_Music_Player>(value.ToPointer());
	}

	IntPtr Engine::StopBackgroundMusicPlayerPointer::get()
	{
		return IntPtr(::Stop_Background_Music_Player);
	}

	void Engine::StopBackgroundMusicPlayerPointer::set(IntPtr value)
	{
		::Stop_Background_Music_Player = reinterpret_cast<::_Stop_Background_Music_Player>(value.ToPointer());
	}

	IntPtr Engine::EnableRadarPlayerPointer::get()
	{
		return IntPtr(::Enable_Radar_Player);
	}

	void Engine::EnableRadarPlayerPointer::set(IntPtr value)
	{
		::Enable_Radar_Player = reinterpret_cast<::_Enable_Radar_Player>(value.ToPointer());
	}

	IntPtr Engine::DisplayGDIPlayerTerminalPlayerPointer::get()
	{
		return IntPtr(::Display_GDI_Player_Terminal_Player);
	}

	void Engine::DisplayGDIPlayerTerminalPlayerPointer::set(IntPtr value)
	{
		::Display_GDI_Player_Terminal_Player = reinterpret_cast<::_Display_GDI_Player_Terminal_Player>(value.ToPointer());
	}

	IntPtr Engine::DisplayNodPlayerTerminalPlayerPointer::get()
	{
		return IntPtr(::Display_NOD_Player_Terminal_Player);
	}

	void Engine::DisplayNodPlayerTerminalPlayerPointer::set(IntPtr value)
	{
		::Display_NOD_Player_Terminal_Player = reinterpret_cast<::_Display_NOD_Player_Terminal_Player>(value.ToPointer());
	}

	IntPtr Engine::SetScreenFadeColorPlayerPointer::get()
	{
		return IntPtr(::Set_Screen_Fade_Color_Player);
	}

	void Engine::SetScreenFadeColorPlayerPointer::set(IntPtr value)
	{
		::Set_Screen_Fade_Color_Player = reinterpret_cast<::_Set_Screen_Fade_Color_Player>(value.ToPointer());
	}

	IntPtr Engine::SetScreenFadeOpacityPlayerPointer::get()
	{
		return IntPtr(::Set_Screen_Fade_Opacity_Player);
	}

	void Engine::SetScreenFadeOpacityPlayerPointer::set(IntPtr value)
	{
		::Set_Screen_Fade_Opacity_Player = reinterpret_cast<::_Set_Screen_Fade_Opacity_Player>(value.ToPointer());
	}

	IntPtr Engine::ForceCameraLookPlayerPointer::get()
	{
		return IntPtr(::Force_Camera_Look_Player);
	}

	void Engine::ForceCameraLookPlayerPointer::set(IntPtr value)
	{
		::Force_Camera_Look_Player = reinterpret_cast<::_Force_Camera_Look_Player>(value.ToPointer());
	}

	IntPtr Engine::EnableHUDPlayerPointer::get()
	{
		return IntPtr(::Enable_HUD_Player);
	}

	void Engine::EnableHUDPlayerPointer::set(IntPtr value)
	{
		::Enable_HUD_Player = reinterpret_cast<::_Enable_HUD_Player>(value.ToPointer());
	}

	IntPtr Engine::CreateSoundPlayerPointer::get()
	{
		return IntPtr(::Create_Sound_Player);
	}

	void Engine::CreateSoundPlayerPointer::set(IntPtr value)
	{
		::Create_Sound_Player = reinterpret_cast<::_Create_Sound_Player>(value.ToPointer());
	}

	IntPtr Engine::Create2DSoundPlayerPointer::get()
	{
		return IntPtr(::Create_2D_Sound_Player);
	}

	void Engine::Create2DSoundPlayerPointer::set(IntPtr value)
	{
		::Create_2D_Sound_Player = reinterpret_cast<::_Create_2D_Sound_Player>(value.ToPointer());
	}

	IntPtr Engine::Create2DWAVSoundPlayerPointer::get()
	{
		return IntPtr(::Create_2D_WAV_Sound_Player);
	}

	void Engine::Create2DWAVSoundPlayerPointer::set(IntPtr value)
	{
		::Create_2D_WAV_Sound_Player = reinterpret_cast<::_Create_2D_WAV_Sound_Player>(value.ToPointer());
	}

	IntPtr Engine::Create3DWAVSoundAtBonePlayerPointer::get()
	{
		return IntPtr(::Create_3D_WAV_Sound_At_Bone_Player);
	}

	void Engine::Create3DWAVSoundAtBonePlayerPointer::set(IntPtr value)
	{
		::Create_3D_WAV_Sound_At_Bone_Player = reinterpret_cast<::_Create_3D_WAV_Sound_At_Bone_Player>(value.ToPointer());
	}

	IntPtr Engine::Create3DSoundAtBonePlayerPointer::get()
	{
		return IntPtr(::Create_3D_Sound_At_Bone_Player);
	}

	void Engine::Create3DSoundAtBonePlayerPointer::set(IntPtr value)
	{
		::Create_3D_Sound_At_Bone_Player = reinterpret_cast<::_Create_3D_Sound_At_Bone_Player>(value.ToPointer());
	}

	IntPtr Engine::SetVehicleLimitPointer::get()
	{
		return IntPtr(::Set_Vehicle_Limit);
	}

	void Engine::SetVehicleLimitPointer::set(IntPtr value)
	{
		::Set_Vehicle_Limit = reinterpret_cast<::svl>(value.ToPointer());
	}

	IntPtr Engine::GetVehicleLimitPointer::get()
	{
		return IntPtr(::Get_Vehicle_Limit);
	}

	void Engine::GetVehicleLimitPointer::set(IntPtr value)
	{
		::Get_Vehicle_Limit = reinterpret_cast<::gvl>(value.ToPointer());
	}

	IntPtr Engine::SetAirVehicleLimitPointer::get()
	{
		return IntPtr(::Set_Air_Vehicle_Limit);
	}

	void Engine::SetAirVehicleLimitPointer::set(IntPtr value)
	{
		::Set_Air_Vehicle_Limit = reinterpret_cast<::svl>(value.ToPointer());
	}

	IntPtr Engine::GetAirVehicleLimitPointer::get()
	{
		return IntPtr(::Get_Air_Vehicle_Limit);
	}

	void Engine::GetAirVehicleLimitPointer::set(IntPtr value)
	{
		::Get_Air_Vehicle_Limit = reinterpret_cast<::gvl>(value.ToPointer());
	}

	IntPtr Engine::SetNavalVehicleLimitPointer::get()
	{
		return IntPtr(::Set_Naval_Vehicle_Limit);
	}

	void Engine::SetNavalVehicleLimitPointer::set(IntPtr value)
	{
		::Set_Naval_Vehicle_Limit = reinterpret_cast<::svl>(value.ToPointer());
	}

	IntPtr Engine::GetNavalVehicleLimitPointer::get()
	{
		return IntPtr(::Get_Naval_Vehicle_Limit);
	}

	void Engine::GetNavalVehicleLimitPointer::set(IntPtr value)
	{
		::Get_Naval_Vehicle_Limit = reinterpret_cast<::gvl>(value.ToPointer());
	}

	IntPtr Engine::SendMessagePointer::get()
	{
		return IntPtr(::Send_Message);
	}

	void Engine::SendMessagePointer::set(IntPtr value)
	{
		::Send_Message = reinterpret_cast<::sm>(value.ToPointer());
	}

	IntPtr Engine::SendMessagePlayerPointer::get()
	{
		return IntPtr(::Send_Message_Player);
	}

	void Engine::SendMessagePlayerPointer::set(IntPtr value)
	{
		::Send_Message_Player = reinterpret_cast<::smp>(value.ToPointer());
	}

	IntPtr Engine::LoadNewHUDINIPointer::get()
	{
		return IntPtr(::Load_New_HUD_INI);
	}

	void Engine::LoadNewHUDINIPointer::set(IntPtr value)
	{
		::Load_New_HUD_INI = reinterpret_cast<::lnhi>(value.ToPointer());
	}

	IntPtr Engine::RemoveWeaponPointer::get()
	{
		return IntPtr(::Remove_Weapon);
	}

	void Engine::RemoveWeaponPointer::set(IntPtr value)
	{
		::Remove_Weapon = reinterpret_cast<::rw>(value.ToPointer());
	}

	IntPtr Engine::ChangeRadarMapPointer::get()
	{
		return IntPtr(::Change_Radar_Map);
	}

	void Engine::ChangeRadarMapPointer::set(IntPtr value)
	{
		::Change_Radar_Map = reinterpret_cast<::crm>(value.ToPointer());
	}

	IntPtr Engine::GetBuildTimeMultiplierPointer::get()
	{
		return IntPtr(::Get_Build_Time_Multiplier);
	}

	void Engine::GetBuildTimeMultiplierPointer::set(IntPtr value)
	{
		::Get_Build_Time_Multiplier = reinterpret_cast<::gbm>(value.ToPointer());
	}

	IntPtr Engine::SetCurrentlyBuildingPointer::get()
	{
		return IntPtr(::Set_Currently_Building);
	}

	void Engine::SetCurrentlyBuildingPointer::set(IntPtr value)
	{
		::Set_Currently_Building = reinterpret_cast<::scb>(value.ToPointer());
	}

	IntPtr Engine::IsCurrentlyBuildingPointer::get()
	{
		return IntPtr(::Is_Currently_Building);
	}

	void Engine::IsCurrentlyBuildingPointer::set(IntPtr value)
	{
		::Is_Currently_Building = reinterpret_cast<::icb>(value.ToPointer());
	}

	IntPtr Engine::SetFogColorPointer::get()
	{
		return IntPtr(::Set_Fog_Color);
	}

	void Engine::SetFogColorPointer::set(IntPtr value)
	{
		::Set_Fog_Color = reinterpret_cast<::sfc>(value.ToPointer());
	}

	IntPtr Engine::SetFogColorPlayerPointer::get()
	{
		return IntPtr(::Set_Fog_Color_Player);
	}

	void Engine::SetFogColorPlayerPointer::set(IntPtr value)
	{
		::Set_Fog_Color_Player = reinterpret_cast<::sfcp>(value.ToPointer());
	}

	IntPtr Engine::SetFogModePointer::get()
	{
		return IntPtr(::Set_Fog_Mode);
	}

	void Engine::SetFogModePointer::set(IntPtr value)
	{
		::Set_Fog_Mode = reinterpret_cast<::sfm>(value.ToPointer());
	}

	IntPtr Engine::SetFogModePlayerPointer::get()
	{
		return IntPtr(::Set_Fog_Mode_Player);
	}

	void Engine::SetFogModePlayerPointer::set(IntPtr value)
	{
		::Set_Fog_Mode_Player = reinterpret_cast<::sfmp>(value.ToPointer());
	}

	IntPtr Engine::SetFogDensityPointer::get()
	{
		return IntPtr(::Set_Fog_Density);
	}

	void Engine::SetFogDensityPointer::set(IntPtr value)
	{
		::Set_Fog_Density = reinterpret_cast<::sfd>(value.ToPointer());
	}

	IntPtr Engine::SetFogDensityPlayerPointer::get()
	{
		return IntPtr(::Set_Fog_Density_Player);
	}

	void Engine::SetFogDensityPlayerPointer::set(IntPtr value)
	{
		::Set_Fog_Density_Player = reinterpret_cast<::sfdp>(value.ToPointer());
	}

	IntPtr Engine::ChangeTimeRemainingPointer::get()
	{
		return IntPtr(::Change_Time_Remaining);
	}

	void Engine::ChangeTimeRemainingPointer::set(IntPtr value)
	{
		::Change_Time_Remaining = reinterpret_cast<::ctr>(value.ToPointer());
	}

	IntPtr Engine::ChangeTimeLimitPointer::get()
	{
		return IntPtr(::Change_Time_Limit);
	}

	void Engine::ChangeTimeLimitPointer::set(IntPtr value)
	{
		::Change_Time_Limit = reinterpret_cast<::ctl>(value.ToPointer());
	}

	IntPtr Engine::DisplaySecurityDialogPointer::get()
	{
		return IntPtr(::Display_Security_Dialog);
	}

	void Engine::DisplaySecurityDialogPointer::set(IntPtr value)
	{
		::Display_Security_Dialog = reinterpret_cast<::dps>(value.ToPointer());
	}

	IntPtr Engine::SendHUDNumberPointer::get()
	{
		return IntPtr(::Send_HUD_Number);
	}

	void Engine::SendHUDNumberPointer::set(IntPtr value)
	{
		::Send_HUD_Number = reinterpret_cast<::shn>(value.ToPointer());
	}

	IntPtr Engine::GetExplosionObjPointer::get()
	{
		return IntPtr(::GetExplosionObj);
	}

	void Engine::GetExplosionObjPointer::set(IntPtr value)
	{
		::GetExplosionObj = reinterpret_cast<::geo>(value.ToPointer());
	}

	IntPtr Engine::SetExplosionObjPointer::get()
	{
		return IntPtr(::SetExplosionObj);
	}

	void Engine::SetExplosionObjPointer::set(IntPtr value)
	{
		::SetExplosionObj = reinterpret_cast<::seo>(value.ToPointer());
	}

	IntPtr Engine::UpdateNetworkObjectPointer::get()
	{
		return IntPtr(::Update_Network_Object);
	}

	void Engine::UpdateNetworkObjectPointer::set(IntPtr value)
	{
		::Update_Network_Object = reinterpret_cast<::uno>(value.ToPointer());
	}

	IntPtr Engine::UpdateNetworkObjectPlayerPointer::get()
	{
		return IntPtr(::Update_Network_Object_Player);
	}

	void Engine::UpdateNetworkObjectPlayerPointer::set(IntPtr value)
	{
		::Update_Network_Object_Player = reinterpret_cast<::unop>(value.ToPointer());
	}

	IntPtr Engine::SendClientTextPointer::get()
	{
		return IntPtr(::Send_Client_Text);
	}

	void Engine::SendClientTextPointer::set(IntPtr value)
	{
		::Send_Client_Text = reinterpret_cast<::sct>(value.ToPointer());
	}

	IntPtr Engine::SendClientAnnouncementPointer::get()
	{
		return IntPtr(::Send_Client_Announcement);
	}

	void Engine::SendClientAnnouncementPointer::set(IntPtr value)
	{
		::Send_Client_Announcement = reinterpret_cast<::sca>(value.ToPointer());
	}

	IntPtr Engine::SendPlayerKillMessagePointer::get()
	{
		return IntPtr(::Send_Player_Kill_Message);
	}

	void Engine::SendPlayerKillMessagePointer::set(IntPtr value)
	{
		::Send_Player_Kill_Message = reinterpret_cast<::spkm>(value.ToPointer());
	}

	IntPtr Engine::SendPurchaseResponsePointer::get()
	{
		return IntPtr(::Send_Purchase_Response);
	}

	void Engine::SendPurchaseResponsePointer::set(IntPtr value)
	{
		::Send_Purchase_Response = reinterpret_cast<::spr>(value.ToPointer());
	}

	IntPtr Engine::DoObjectivesDlgPointer::get()
	{
		return IntPtr(::Do_Objectives_Dlg);
	}

	void Engine::DoObjectivesDlgPointer::set(IntPtr value)
	{
		::Do_Objectives_Dlg = reinterpret_cast<::dod>(value.ToPointer());
	}

	IntPtr Engine::SetPlayerLimitPointer::get()
	{
		return IntPtr(::Set_Player_Limit);
	}

	void Engine::SetPlayerLimitPointer::set(IntPtr value)
	{
		::Set_Player_Limit = reinterpret_cast<::sl>(value.ToPointer());
	}

	IntPtr Engine::GetPlayerLimitPointer::get()
	{
		return IntPtr(::Get_Player_Limit);
	}

	void Engine::GetPlayerLimitPointer::set(IntPtr value)
	{
		::Get_Player_Limit = reinterpret_cast<::gl>(value.ToPointer());
	}

	IntPtr Engine::GetFogRangePointer::get()
	{
		return IntPtr(::Get_Fog_Range);
	}

	void Engine::GetFogRangePointer::set(IntPtr value)
	{
		::Get_Fog_Range = reinterpret_cast<::_Get_Fog_Range>(value.ToPointer());
	}

	IntPtr Engine::SendShaderParamPlayerObsoletePointer::get()
	{
		return IntPtr(::Send_Shader_Param_Player);
	}

	void Engine::SendShaderParamPlayerObsoletePointer::set(IntPtr value)
	{
		::Send_Shader_Param_Player = reinterpret_cast<::sspp>(value.ToPointer());
	}

	IntPtr Engine::SendShaderParamObsoletePointer::get()
	{
		return IntPtr(::Send_Shader_Param);
	}

	void Engine::SendShaderParamObsoletePointer::set(IntPtr value)
	{
		::Send_Shader_Param = reinterpret_cast<::ssp>(value.ToPointer());
	}

	IntPtr Engine::SendShaderParamObjPlayerObsoletePointer::get()
	{
		return IntPtr(::Send_Shader_Param_Obj_Player);
	}

	void Engine::SendShaderParamObjPlayerObsoletePointer::set(IntPtr value)
	{
		::Send_Shader_Param_Obj_Player = reinterpret_cast<::sspop>(value.ToPointer());
	}

	IntPtr Engine::SendShaderParamObjObsoletePointer::get()
	{
		return IntPtr(::Send_Shader_Param_Obj);
	}

	void Engine::SendShaderParamObjObsoletePointer::set(IntPtr value)
	{
		::Send_Shader_Param_Obj = reinterpret_cast<::sspo>(value.ToPointer());
	}

	IntPtr Engine::SetGDISoldierNamePointer::get()
	{
		return IntPtr(::Set_GDI_Soldier_Name);
	}

	void Engine::SetGDISoldierNamePointer::set(IntPtr value)
	{
		::Set_GDI_Soldier_Name = reinterpret_cast<::ssn>(value.ToPointer());
	}

	IntPtr Engine::SetNodSoldierNamePointer::get()
	{
		return IntPtr(::Set_Nod_Soldier_Name);
	}

	void Engine::SetNodSoldierNamePointer::set(IntPtr value)
	{
		::Set_Nod_Soldier_Name = reinterpret_cast<::ssn>(value.ToPointer());
	}

	IntPtr Engine::GetGDISoldierNamePointer::get()
	{
		return IntPtr(::Get_GDI_Soldier_Name);
	}

	void Engine::GetGDISoldierNamePointer::set(IntPtr value)
	{
		::Get_GDI_Soldier_Name = reinterpret_cast<::gsnx>(value.ToPointer());
	}

	IntPtr Engine::GetNodSoldierNamePointer::get()
	{
		return IntPtr(::Get_Nod_Soldier_Name);
	}

	void Engine::GetNodSoldierNamePointer::set(IntPtr value)
	{
		::Get_Nod_Soldier_Name = reinterpret_cast<::gsnx>(value.ToPointer());
	}

	IntPtr Engine::GetIPAddressPointer::get()
	{
		return IntPtr(::Get_IP_Address);
	}

	void Engine::GetIPAddressPointer::set(IntPtr value)
	{
		::Get_IP_Address = reinterpret_cast<::Get_IP_Addressx>(value.ToPointer());
	}

	IntPtr Engine::GetIPPortPointer::get()
	{
		return IntPtr(::Get_IP_Port);
	}

	void Engine::GetIPPortPointer::set(IntPtr value)
	{
		::Get_IP_Port = reinterpret_cast<::Get_IP_Portx>(value.ToPointer());
	}

	IntPtr Engine::GetIPPointer::get()
	{
		return IntPtr(::Get_IP);
	}

	void Engine::GetIPPointer::set(IntPtr value)
	{
		::Get_IP = reinterpret_cast<::Get_IPx>(value.ToPointer());
	}

	IntPtr Engine::GetBandwidthPointer::get()
	{
		return IntPtr(::Get_Bandwidth);
	}

	void Engine::GetBandwidthPointer::set(IntPtr value)
	{
		::Get_Bandwidth = reinterpret_cast<::Get_Bandwidthx>(value.ToPointer());
	}

	IntPtr Engine::GetPingPointer::get()
	{
		return IntPtr(::Get_Ping);
	}

	void Engine::GetPingPointer::set(IntPtr value)
	{
		::Get_Ping = reinterpret_cast<::Get_Pingx>(value.ToPointer());
	}

	IntPtr Engine::GetKbitsPointer::get()
	{
		return IntPtr(::Get_Kbits);
	}

	void Engine::GetKbitsPointer::set(IntPtr value)
	{
		::Get_Kbits = reinterpret_cast<::Get_Kbitsx>(value.ToPointer());
	}

	IntPtr Engine::SetFogOverridePlayerPointer::get()
	{
		return IntPtr(::Set_Fog_Override_Player);
	}

	void Engine::SetFogOverridePlayerPointer::set(IntPtr value)
	{
		::Set_Fog_Override_Player = reinterpret_cast<::sfop>(value.ToPointer());
	}

	IntPtr Engine::ClearFogOverridePlayerPointer::get()
	{
		return IntPtr(::Clear_Fog_Override_Player);
	}

	void Engine::ClearFogOverridePlayerPointer::set(IntPtr value)
	{
		::Clear_Fog_Override_Player = reinterpret_cast<::cfop>(value.ToPointer());
	}

	IntPtr Engine::SetMoonIsEarthPointer::get()
	{
		return IntPtr(::Set_Moon_Is_Earth);
	}

	void Engine::SetMoonIsEarthPointer::set(IntPtr value)
	{
		::Set_Moon_Is_Earth = reinterpret_cast<::smie>(value.ToPointer());
	}

	IntPtr Engine::SetGlobalStealthDisablePointer::get()
	{
		return IntPtr(::Set_Global_Stealth_Disable);
	}

	void Engine::SetGlobalStealthDisablePointer::set(IntPtr value)
	{
		::Set_Global_Stealth_Disable = reinterpret_cast<::smie>(value.ToPointer());
	}

	IntPtr Engine::GetMineLimitPointer::get()
	{
		return IntPtr(::Get_Mine_Limit);
	}

	void Engine::GetMineLimitPointer::set(IntPtr value)
	{
		::Get_Mine_Limit = reinterpret_cast<::gml>(value.ToPointer());
	}

	IntPtr Engine::SetSpecialBaseDestructionPointer::get()
	{
		return IntPtr(::Set_Special_Base_Destruction);
	}

	void Engine::SetSpecialBaseDestructionPointer::set(IntPtr value)
	{
		::Set_Special_Base_Destruction = reinterpret_cast<::sbd>(value.ToPointer());
	}

	IntPtr Engine::GetClientVersionPointer::get()
	{
		return IntPtr(::Get_Client_Version);
	}

	void Engine::GetClientVersionPointer::set(IntPtr value)
	{
		::Get_Client_Version = reinterpret_cast<::gpv>(value.ToPointer());
	}

	IntPtr Engine::GetClientRevisionPointer::get()
	{
		return IntPtr(::Get_Client_Revision);
	}

	void Engine::GetClientRevisionPointer::set(IntPtr value)
	{
		::Get_Client_Revision = reinterpret_cast<::gpr>(value.ToPointer());
	}

	IntPtr Engine::GetRevisionPointer::get()
	{
		return IntPtr(::Get_Revision);
	}

	void Engine::GetRevisionPointer::set(IntPtr value)
	{
		::Get_Revision = reinterpret_cast<::gpr>(value.ToPointer());
	}

	IntPtr Engine::GetDamageWarheadPointer::get()
	{
		return IntPtr(::Get_Damage_Warhead);
	}

	void Engine::GetDamageWarheadPointer::set(IntPtr value)
	{
		::Get_Damage_Warhead = reinterpret_cast<::gdw>(value.ToPointer());
	}

	IntPtr Engine::GetDamageIsExplosionPointer::get()
	{
		return IntPtr(::Get_Damage_Is_Explosion);
	}

	void Engine::GetDamageIsExplosionPointer::set(IntPtr value)
	{
		::Get_Damage_Is_Explosion = reinterpret_cast<::gdie>(value.ToPointer());
	}

	IntPtr Engine::IsWOLUserPointer::get()
	{
		return IntPtr(::Is_WOL_User);
	}

	void Engine::IsWOLUserPointer::set(IntPtr value)
	{
		::Is_WOL_User = reinterpret_cast<::iwu>(value.ToPointer());
	}

	IntPtr Engine::GetTechLevelPointer::get()
	{
		return IntPtr(::Get_Tech_Level);
	}

	void Engine::GetTechLevelPointer::set(IntPtr value)
	{
		::Get_Tech_Level = reinterpret_cast<::gml>(value.ToPointer());
	}

	IntPtr Engine::SetTechLevelPointer::get()
	{
		return IntPtr(::Set_Tech_Level);
	}

	void Engine::SetTechLevelPointer::set(IntPtr value)
	{
		::Set_Tech_Level = reinterpret_cast<::sw>(value.ToPointer());
	}

	IntPtr Engine::CreateExplosionExtendedPointer::get()
	{
		return IntPtr(::Create_Explosion_Extended);
	}

	void Engine::CreateExplosionExtendedPointer::set(IntPtr value)
	{
		::Create_Explosion_Extended = reinterpret_cast<::cee>(value.ToPointer());
	}

	IntPtr Engine::RetrieveWaypathsPointer::get()
	{
		return IntPtr(::Retrieve_Waypaths);
	}

	void Engine::RetrieveWaypathsPointer::set(IntPtr value)
	{
		::Retrieve_Waypaths = reinterpret_cast<::rwpa>(value.ToPointer());
	}

	IntPtr Engine::RetrieveWaypointsPointer::get()
	{
		return IntPtr(::Retrieve_Waypoints);
	}

	void Engine::RetrieveWaypointsPointer::set(IntPtr value)
	{
		::Retrieve_Waypoints = reinterpret_cast<::rwpo>(value.ToPointer());
	}

	IntPtr Engine::GetWaypointPositionPointer::get()
	{
		return IntPtr(::Get_Waypoint_Position);
	}

	void Engine::GetWaypointPositionPointer::set(IntPtr value)
	{
		::Get_Waypoint_Position = reinterpret_cast<::gwp>(value.ToPointer());
	}

	IntPtr Engine::CreateLightningPointer::get()
	{
		return IntPtr(::Create_Lightning);
	}

	void Engine::CreateLightningPointer::set(IntPtr value)
	{
		::Create_Lightning = reinterpret_cast<::cl>(value.ToPointer());
	}

	IntPtr Engine::GetCloudsPointer::get()
	{
		return IntPtr(::Get_Clouds);
	}

	void Engine::GetCloudsPointer::set(IntPtr value)
	{
		::Get_Clouds = reinterpret_cast<::gc>(value.ToPointer());
	}

	IntPtr Engine::GetLightningPointer::get()
	{
		return IntPtr(::Get_Lightning);
	}

	void Engine::GetLightningPointer::set(IntPtr value)
	{
		::Get_Lightning = reinterpret_cast<::gli>(value.ToPointer());
	}

	IntPtr Engine::GetWindPointer::get()
	{
		return IntPtr(::Get_Wind);
	}

	void Engine::GetWindPointer::set(IntPtr value)
	{
		::Get_Wind = reinterpret_cast<::gw>(value.ToPointer());
	}

	IntPtr Engine::GetRainPointer::get()
	{
		return IntPtr(::Get_Rain);
	}

	void Engine::GetRainPointer::set(IntPtr value)
	{
		::Get_Rain = reinterpret_cast<::gp>(value.ToPointer());
	}

	IntPtr Engine::GetSnowPointer::get()
	{
		return IntPtr(::Get_Snow);
	}

	void Engine::GetSnowPointer::set(IntPtr value)
	{
		::Get_Snow = reinterpret_cast<::gp>(value.ToPointer());
	}

	IntPtr Engine::GetAshPointer::get()
	{
		return IntPtr(::Get_Ash);
	}

	void Engine::GetAshPointer::set(IntPtr value)
	{
		::Get_Ash = reinterpret_cast<::gp>(value.ToPointer());
	}

	IntPtr Engine::UpdateGameOptionsPointer::get()
	{
		return IntPtr(::Update_Game_Options);
	}

	void Engine::UpdateGameOptionsPointer::set(IntPtr value)
	{
		::Update_Game_Options = reinterpret_cast<::ugo>(value.ToPointer());
	}

	IntPtr Engine::GetTTVersionPointer::get()
	{
		return IntPtr(::GetTTVersion);
	}

	void Engine::GetTTVersionPointer::set(IntPtr value)
	{
		::GetTTVersion = reinterpret_cast<::gttv>(value.ToPointer());
	}

	IntPtr Engine::GetTTRevisionPointer::get()
	{
		return IntPtr(::GetTTRevision);
	}

	void Engine::GetTTRevisionPointer::set(IntPtr value)
	{
		::GetTTRevision = reinterpret_cast<::gttr>(value.ToPointer());
	}

	IntPtr Engine::SetHUDHelpTextPlayerPointer::get()
	{
		return IntPtr(::Set_HUD_Help_Text_Player);
	}

	void Engine::SetHUDHelpTextPlayerPointer::set(IntPtr value)
	{
		::Set_HUD_Help_Text_Player = reinterpret_cast<::htp>(value.ToPointer());
	}

	IntPtr Engine::ChangeStringPlayerPointer::get()
	{
		return IntPtr(::Change_String_Player);
	}

	void Engine::ChangeStringPlayerPointer::set(IntPtr value)
	{
		::Change_String_Player = reinterpret_cast<::csp>(value.ToPointer());
	}

	IntPtr Engine::ForcePositionUpdatePointer::get()
	{
		return IntPtr(::Force_Position_Update);
	}

	void Engine::ForcePositionUpdatePointer::set(IntPtr value)
	{
		::Force_Position_Update = reinterpret_cast<::fpu>(value.ToPointer());
	}

	IntPtr Engine::GetRandomPathfindSpotPointer::get()
	{
		return IntPtr(::Get_Random_Pathfind_Spot);
	}

	void Engine::GetRandomPathfindSpotPointer::set(IntPtr value)
	{
		::Get_Random_Pathfind_Spot = reinterpret_cast<::grps>(value.ToPointer());
	}

	IntPtr Engine::SetHUDHelpTextPlayerTextPointer::get()
	{
		return IntPtr(::Set_HUD_Help_Text_Player_Text);
	}

	void Engine::SetHUDHelpTextPlayerTextPointer::set(IntPtr value)
	{
		::Set_HUD_Help_Text_Player_Text = reinterpret_cast<::htpt>(value.ToPointer());
	}

	IntPtr Engine::GrantWeaponPointer::get()
	{
		return IntPtr(::Grant_Weapon);
	}

	void Engine::GrantWeaponPointer::set(IntPtr value)
	{
		::Grant_Weapon = reinterpret_cast<::grw>(value.ToPointer());
	}

	IntPtr Engine::SetObjectVisibilityForPlayerPointer::get()
	{
		return IntPtr(::Set_Object_Visibility_For_Player);
	}

	void Engine::SetObjectVisibilityForPlayerPointer::set(IntPtr value)
	{
		::Set_Object_Visibility_For_Player = reinterpret_cast<::sovfp>(value.ToPointer());
	}

	IntPtr Engine::SetObjectVisibilityPointer::get()
	{
		return IntPtr(::Set_Object_Visibility);
	}

	void Engine::SetObjectVisibilityPointer::set(IntPtr value)
	{
		::Set_Object_Visibility = reinterpret_cast<::sov>(value.ToPointer());
	}

	IntPtr Engine::LockSoldierCollisionGroupPointer::get()
	{
		return IntPtr(::Lock_Soldier_Collision_Group);
	}

	void Engine::LockSoldierCollisionGroupPointer::set(IntPtr value)
	{
		::Lock_Soldier_Collision_Group = reinterpret_cast<::lscg>(value.ToPointer());
	}

	IntPtr Engine::UnlockSoldierCollisionGroupPointer::get()
	{
		return IntPtr(::Unlock_Soldier_Collision_Group);
	}

	void Engine::UnlockSoldierCollisionGroupPointer::set(IntPtr value)
	{
		::Unlock_Soldier_Collision_Group = reinterpret_cast<::ulscg>(value.ToPointer());
	}

	IntPtr Engine::IsEngineEnabledPointer::get()
	{
		return IntPtr(::Is_Engine_Enabled);
	}

	void Engine::IsEngineEnabledPointer::set(IntPtr value)
	{
		::Is_Engine_Enabled = reinterpret_cast<::iea>(value.ToPointer());
	}

	IntPtr Engine::StopTimerPointer::get()
	{
		return IntPtr(::Stop_Timer);
	}

	void Engine::StopTimerPointer::set(IntPtr value)
	{
		::Stop_Timer = reinterpret_cast<::ss>(value.ToPointer());
	}

	IntPtr Engine::Create2DWaveSoundDialogPlayerPointer::get()
	{
		return IntPtr(::Create_2D_Wave_Sound_Dialog_Player);
	}

	void Engine::Create2DWaveSoundDialogPlayerPointer::set(IntPtr value)
	{
		::Create_2D_Wave_Sound_Dialog_Player = reinterpret_cast<::cwsdp>(value.ToPointer());
	}

	IntPtr Engine::ForcePositionUpdatePlayerPointer::get()
	{
		return IntPtr(::Force_Position_Update_Player);
	}

	void Engine::ForcePositionUpdatePlayerPointer::set(IntPtr value)
	{
		::Force_Position_Update_Player = reinterpret_cast<::fpup>(value.ToPointer());
	}

	IntPtr Engine::StopTimer2Pointer::get()
	{
		return IntPtr(::Stop_Timer2);
	}

	void Engine::StopTimer2Pointer::set(IntPtr value)
	{
		::Stop_Timer2 = reinterpret_cast<::ss2>(value.ToPointer());
	}

	IntPtr Engine::HasTimerPointer::get()
	{
		return IntPtr(::Has_Timer);
	}

	void Engine::HasTimerPointer::set(IntPtr value)
	{
		::Has_Timer = reinterpret_cast<::htm>(value.ToPointer());
	}

	IntPtr Engine::SetBackgroundMusicPlayerOffsetPointer::get()
	{
		return IntPtr(::Set_Background_Music_Player_Offset);
	}

	void Engine::SetBackgroundMusicPlayerOffsetPointer::set(IntPtr value)
	{
		::Set_Background_Music_Player_Offset = reinterpret_cast<::sbgmo>(value.ToPointer());
	}

	IntPtr Engine::SetCameraPlayerPointer::get()
	{
		return IntPtr(::Set_Camera_Player);
	}

	void Engine::SetCameraPlayerPointer::set(IntPtr value)
	{
		::Set_Camera_Player = reinterpret_cast<::setcam>(value.ToPointer());
	}

	IntPtr Engine::SetDefinitionTranslationIDPlayerPointer::get()
	{
		return IntPtr(::Set_Definition_TranslationID_Player);
	}

	void Engine::SetDefinitionTranslationIDPlayerPointer::set(IntPtr value)
	{
		::Set_Definition_TranslationID_Player = reinterpret_cast<::settran>(value.ToPointer());
	}

	IntPtr Engine::SetNetUpdateRatePlayerPointer::get()
	{
		return IntPtr(::Set_Net_Update_Rate_Player);
	}

	void Engine::SetNetUpdateRatePlayerPointer::set(IntPtr value)
	{
		::Set_Net_Update_Rate_Player = reinterpret_cast<::setnur>(value.ToPointer());
	}

	IntPtr Engine::ForceOrientationUpdatePointer::get()
	{
		return IntPtr(::Force_Orientation_Update);
	}

	void Engine::ForceOrientationUpdatePointer::set(IntPtr value)
	{
		::Force_Orientation_Update = reinterpret_cast<::fou>(value.ToPointer());
	}

	IntPtr Engine::ForceOrientationUpdatePlayerPointer::get()
	{
		return IntPtr(::Force_Orientation_Update_Player);
	}

	void Engine::ForceOrientationUpdatePlayerPointer::set(IntPtr value)
	{
		::Force_Orientation_Update_Player = reinterpret_cast<::foup>(value.ToPointer());
	}

	IntPtr Engine::Create2DWaveSoundCinematicPlayerPointer::get()
	{
		return IntPtr(::Create_2D_Wave_Sound_Cinematic_Player);
	}

	void Engine::Create2DWaveSoundCinematicPlayerPointer::set(IntPtr value)
	{
		::Create_2D_Wave_Sound_Cinematic_Player = reinterpret_cast<::cwscp>(value.ToPointer());
	}

	IntPtr Engine::ForceTurretUpdatePointer::get()
	{
		return IntPtr(::Force_Turret_Update);
	}

	void Engine::ForceTurretUpdatePointer::set(IntPtr value)
	{
		::Force_Turret_Update = reinterpret_cast<::ftu>(value.ToPointer());
	}

	IntPtr Engine::ForceTurretUpdatePlayerPointer::get()
	{
		return IntPtr(::Force_Turret_Update_Player);
	}

	void Engine::ForceTurretUpdatePlayerPointer::set(IntPtr value)
	{
		::Force_Turret_Update_Player = reinterpret_cast<::ftup>(value.ToPointer());
	}

	IntPtr Engine::ForceVelocityUpdatePointer::get()
	{
		return IntPtr(::Force_Velocity_Update);
	}

	void Engine::ForceVelocityUpdatePointer::set(IntPtr value)
	{
		::Force_Velocity_Update = reinterpret_cast<::fvu>(value.ToPointer());
	}

	IntPtr Engine::ForceVelocityUpdatePlayerPointer::get()
	{
		return IntPtr(::Force_Velocity_Update_Player);
	}

	void Engine::ForceVelocityUpdatePlayerPointer::set(IntPtr value)
	{
		::Force_Velocity_Update_Player = reinterpret_cast<::fvup>(value.ToPointer());
	}

	IntPtr Engine::SetCameraHostNetworkPointer::get()
	{
		return IntPtr(::Set_Camera_Host_Network);
	}

	void Engine::SetCameraHostNetworkPointer::set(IntPtr value)
	{
		::Set_Camera_Host_Network = reinterpret_cast<::schn>(value.ToPointer());
	}

	IntPtr Engine::GetPathfindDistancePointer::get()
	{
		return IntPtr(::Get_Pathfind_Distance);
	}

	void Engine::GetPathfindDistancePointer::set(IntPtr value)
	{
		::Get_Pathfind_Distance = reinterpret_cast<::gpd>(value.ToPointer());
	}

	IntPtr Engine::GetPathfindDistanceAsyncPointer::get()
	{
		return IntPtr(::Get_Pathfind_Distance_Async);
	}

	void Engine::GetPathfindDistanceAsyncPointer::set(IntPtr value)
	{
		::Get_Pathfind_Distance_Async = reinterpret_cast<::gpda>(value.ToPointer());
	}

	IntPtr Engine::GetPathfindDistanceBlockingPointer::get()
	{
		return IntPtr(::Get_Pathfind_Distance_Blocking);
	}

	void Engine::GetPathfindDistanceBlockingPointer::set(IntPtr value)
	{
		::Get_Pathfind_Distance_Blocking = reinterpret_cast<::gpdb>(value.ToPointer());
	}

	IntPtr Engine::CancelGetPathfindDistancePointer::get()
	{
		return IntPtr(::Cancel_Get_Pathfind_Distance);
	}

	void Engine::CancelGetPathfindDistancePointer::set(IntPtr value)
	{
		::Cancel_Get_Pathfind_Distance = reinterpret_cast<::cgpd>(value.ToPointer());
	}

	IDynamicVectorClass<IConsoleFunctionClass ^> ^Engine::ConsoleFunctionList::get()
	{
		return gcnew ConsoleFunctionClassPtrDynamicVectorClass(IntPtr(&::ConsoleFunctionList));
	}

	void Engine::ConsoleFunctionList::set(IDynamicVectorClass<IConsoleFunctionClass ^> ^value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		::ConsoleFunctionList = *reinterpret_cast<::DynamicVectorClass<::ConsoleFunctionClass *> *>(value->Pointer.ToPointer());
	}

	IFileFactoryClass ^Engine::TheFileFactory::get()
	{
		auto theFileFactory = ::_TheFileFactory;
		if (theFileFactory == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew FileFactoryClass(IntPtr(theFileFactory));
		}
	}

	String ^Engine::FilePath::get()
	{
		auto filePath = ::Get_File_Path();
		if (filePath == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(filePath);
		}
	}

	String ^Engine::AppDataPath::get()
	{
		auto appDataPath = ::Get_App_Data_Path();
		if (appDataPath == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(appDataPath);
		}
	}

	String ^Engine::RegistryPath::get()
	{
		auto registryPath = ::Get_Registry_Path();
		if (registryPath == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(registryPath);
		}
	}

	float Engine::DontMoveArrivedDist::get()
	{
		return ::DONT_MOVE_ARRIVED_DIST;
	}

	IScriptCommands ^Engine::Commands::get()
	{
		auto result = ::Commands;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptCommands(IntPtr(result));
		}
	}

	void Engine::Commands::set(IScriptCommands ^value)
	{
		if (value == nullptr || value->ScriptCommandsPointer.ToPointer() == nullptr)
		{
			::Commands = nullptr;
		}
		else
		{
			::Commands = reinterpret_cast<::ScriptCommands *>(value->ScriptCommandsPointer.ToPointer());
		}
	}

	int Engine::PlayerCount::get()
	{
		return ::Get_Player_Count();
	}

	Color Engine::ColorWhite::get()
	{
		return Color::FromArgb(255, COLORWHITE);
	}

	Color Engine::ColorGray::get()
	{
		return Color::FromArgb(255, COLORGRAY);
	}

	Color Engine::ColorLightBlue::get()
	{
		return Color::FromArgb(255, COLORLIGHTBLUE);
	}

	Color Engine::ColorGreen::get()
	{
		return Color::FromArgb(255, COLORGREEN);
	}

	Color Engine::ColorBrown::get()
	{
		return Color::FromArgb(255, COLORBROWN);
	}

	Color Engine::ColorPurple::get()
	{
		return Color::FromArgb(255, COLORPURPLE);
	}

	bool Engine::IsMapFlying::get()
	{
		return ::Is_Map_Flying();
	}

	IcGameData^ Engine::TheGame::get()
	{
		auto result = ::The_Game();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cGameData(IntPtr(result));
		}
	}

	IcGameDataSkirmish^ Engine::TheSkirmishGame::get()
	{
		auto result = ::The_Skirmish_Game();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cGameDataSkirmish(IntPtr(result));
		}
	}

	IcGameDataCnC^ Engine::TheCncGame::get()
	{
		auto result = ::The_Cnc_Game();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cGameDataCnC(IntPtr(result));
		}
	}

	IcGameDataSinglePlayer^ Engine::TheSinglePlayerGame::get()
	{
		auto result = ::The_Single_Player_Game();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cGameDataSinglePlayer(IntPtr(result));
		}
	}

	bool Engine::IsGameplayPermitted::get()
	{
		return ::Is_Gameplay_Permitted();
	}

	bool Engine::IsDedicated::get()
	{
		return ::Is_Dedicated();
	}

	unsigned int Engine::CurrentGameMode::get()
	{
		return ::Get_Current_Game_Mode();
	}

	Color Engine::PrivateMessageColor::get()
	{
		unsigned int red;
		unsigned int green;
		unsigned int blue;
		::Get_Private_Message_Color(&red, &green, &blue);

		return Color::FromArgb(255, static_cast<int>(red), static_cast<int>(green), static_cast<int>(blue));
	}

	Color Engine::PublicMessageColor::get()
	{
		unsigned int red;
		unsigned int green;
		unsigned int blue;
		::Get_Public_Message_Color(&red, &green, &blue);

		return Color::FromArgb(255, static_cast<int>(red), static_cast<int>(green), static_cast<int>(blue));
	}

	int Engine::Exe::get()
	{
		return ::Exe;
	}

	void Engine::Exe::set(int value)
	{
		::Exe = value;
	}

	array<String^>^ Engine::SurfaceTypeStrings::get()
	{
		return surfaceTypeStrings;
	}

	void Engine::RegisterManagedConsoleFunction(IRenSharpConsoleFunctionClass^ function)
	{
		if (function == nullptr)
		{
			throw gcnew ArgumentNullException("function");
		}
		else if (!function->IsAttached)
		{
			throw gcnew ArgumentException("Console function is not attached");
		}

		managedConsoleFunctions->Add(function->ConsoleFunctionClassPointer, function);
	}

	void Engine::UnregisterManagedConsoleFunction(IRenSharpConsoleFunctionClass^ function)
	{
		if (function == nullptr)
		{
			throw gcnew ArgumentNullException("function");
		}

		managedConsoleFunctions->Remove(function->ConsoleFunctionClassPointer);
	}

	void Engine::ProcessDispatcherOperations()
	{
		Monitor::Enter(dispatchers);
		try
		{
			Collections::Generic::ICollection<Threading::Thread^>^ dispatchersToRemove = gcnew Collections::Generic::LinkedList<Threading::Thread^>();
			for each (auto threadDispatcherPair in dispatchers)
			{
				auto currentThread = threadDispatcherPair.Key;
				auto currentDispatcher = threadDispatcherPair.Value;

				if ((currentThread->ThreadState.HasFlag(Threading::ThreadState::Aborted) || currentThread->ThreadState.HasFlag(Threading::ThreadState::Stopped)) &&
					(currentDispatcher->CurrentQueueCount <= 1))
				{
					dispatchersToRemove->Add(currentThread);
				}
				
				currentDispatcher->ProcessOperation();
			}

			for each (auto threadToRemove in dispatchersToRemove)
			{
				dispatchers->Remove(threadToRemove);
			}
		}
		finally
		{
			Monitor::Exit(dispatchers);
		}
	}
}