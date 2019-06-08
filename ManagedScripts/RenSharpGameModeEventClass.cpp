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

#include "stdafx.h"
#include "RenSharpGameModeEventClass.h"

#include "Imports.h"
#include "Mda_game.h"
#include "RenSharpChatCommandManager.h"
#include "RenSharpKeyHookManager.h"
#include "RenSharpTimerManager.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_gamemode.h>
#include <da_event.h>
#include <da_game.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Text;

namespace RenSharp
{
	RenSharpGameModeEventClass::RenSharpGameModeEventClass()
		:
		disposedResources(false),
		destroyPointer(true),
		renSharpGameModeEventClassPointer(IntPtr::Zero),
		daGameModeClassPointer(IntPtr::Zero),
		daEventClassPointer(IntPtr::Zero),
		daGameModeClass(nullptr),
		daEventClass(nullptr)
	{

	}

	RenSharpGameModeEventClass::~RenSharpGameModeEventClass()
	{
		if (disposedResources)
		{
			return;
		}

		DAEventManager::UnregisterManagedEventClass(this);
		DAGameManager::UnregisterManagedGameMode(this);

		ClearTimers();
		ClearChatCommands();
		ClearKeyHooks();

		this->!RenSharpGameModeEventClass();

		disposedResources = true;
	}

	RenSharpGameModeEventClass::!RenSharpGameModeEventClass()
	{
		if (IsAttached)
		{
			auto currentGameModeFactory = ::DAGameManager::Get_Game_Mode();
			if (currentGameModeFactory != nullptr)
			{
				auto helper = reinterpret_cast<DAGameModeFactoryClassHelper*>(currentGameModeFactory);

				auto& instance = helper->GetInstance();
				if (instance == InternalDAGameModeClassPointer)
				{
					instance = nullptr;
				}
			}

			if (destroyPointer)
			{
				IntPtr tmp = daEventClassPointer;
				Imports::DestroyDAEventClass(reinterpret_cast<::DAEventClass*>(tmp.ToPointer()));
			}
		}

		ReleasePointer();
	}

	String^ RenSharpGameModeEventClass::ToString()
	{
		StringBuilder^ builder = gcnew StringBuilder();
		if (IsAttached)
		{
			builder->Append(LongName);
		}
		else
		{
			builder->Append(static_cast<Object^>(nullptr));
		}

		return builder->ToString();
	}

	bool RenSharpGameModeEventClass::Equals(Object^ other)
	{
		if (ReferenceEquals(other, nullptr))
		{
			return false;
		}

		IDAEventClass^ otherThis1 = dynamic_cast<IDAEventClass^>(other);
		if (otherThis1 != nullptr && daEventClassPointer.Equals(otherThis1->DAEventClassPointer))
		{
			return true;
		}

		IDAGameModeClass^ otherThis2 = dynamic_cast<IDAGameModeClass^>(other);
		if (otherThis2 != nullptr && daGameModeClassPointer.Equals(otherThis2->DAGameModeClassPointer))
		{
			return true;
		}

		IRenSharpGameModeClass^ otherThis3 = dynamic_cast<IRenSharpGameModeClass^>(other);
		if (otherThis3 != nullptr && daGameModeClassPointer.Equals(otherThis3->DAGameModeClassPointer))
		{
			return true;
		}

		IRenSharpEventClass^ otherThis4 = dynamic_cast<IRenSharpEventClass^>(other);
		if (otherThis4 == nullptr)
		{
			return false;
		}

		return daEventClassPointer.Equals(otherThis4->DAEventClassPointer);
	}

	int RenSharpGameModeEventClass::GetHashCode()
	{
		return renSharpGameModeEventClassPointer.GetHashCode();
	}

	void RenSharpGameModeEventClass::AttachToUnmanagedObject()
	{
		if (IsAttached)
		{
			throw gcnew NotSupportedException("Already attached.");
		}

		try
		{
			::RenSharpGameModeEventClass* renSharpGameModeEventPtr = nullptr;
			::RenSharpEventClass* eventClassPtr = nullptr;
			::RenSharpGameModeClass* gameModePtr = nullptr;

			renSharpGameModeEventPtr = Imports::CreateRenSharpGameModeEventClass(&eventClassPtr, &gameModePtr);

			renSharpGameModeEventClassPointer = IntPtr(renSharpGameModeEventPtr);
			daGameModeClassPointer = IntPtr(gameModePtr);
			daEventClassPointer = IntPtr(eventClassPtr);
		}
		catch (Exception^)
		{
			if (daEventClassPointer.ToPointer() != nullptr)
			{
				Imports::DestroyDAEventClass(reinterpret_cast<::DAEventClass*>(daEventClassPointer.ToPointer()));
			}

			throw;
		}

		daGameModeClass = gcnew DAGameModeClass(daGameModeClassPointer);
		daEventClass = gcnew DAEventClass(daEventClassPointer);

		UnmanagedAttach();
	}

	void RenSharpGameModeEventClass::RegisterManagedObject()
	{
		DAGameManager::RegisterManagedGameMode(this);
		DAEventManager::RegisterManagedEventClass(this);

		ManagedRegistered();
	}

	void RenSharpGameModeEventClass::ReleasePointer()
	{
		renSharpGameModeEventClassPointer = IntPtr::Zero;
		daGameModeClassPointer = IntPtr::Zero;
		daEventClassPointer = IntPtr::Zero;
		daGameModeClass = nullptr;
		daEventClass = nullptr;
	}

	void RenSharpGameModeEventClass::UnmanagedAttach()
	{

	}

	void RenSharpGameModeEventClass::ManagedRegistered()
	{

	}

	IDAGameModeClass^ RenSharpGameModeEventClass::AsUnmanagedGameMode()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daGameModeClass;
	}

	IDAEventClass^ RenSharpGameModeEventClass::AsUnmanagedEventClass()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daEventClass;
	}

	void RenSharpGameModeEventClass::Init()
	{

	}

	void RenSharpGameModeEventClass::SettingsLoadedEvent()
	{

	}

	bool RenSharpGameModeEventClass::ChatEvent(IcPlayer^ player, TextMessageEnum type, String^ message, int receiverID)
	{
		return true;
	}

	bool RenSharpGameModeEventClass::ChatCommandEvent(IcPlayer^ player, TextMessageEnum type, String^ command, IDATokenClass^ text, int receiverID)
	{
		return true;
	}

	bool RenSharpGameModeEventClass::KeyHookEvent(IcPlayer^ player, String^ key)
	{
		return true;
	}

	bool RenSharpGameModeEventClass::HostChatEvent(int id, TextMessageEnum type, String^ message)
	{
		return true;
	}

	bool RenSharpGameModeEventClass::RadioEvent(IcPlayer^ player, int playerType, int announcementID, int iconID, AnnouncementEnum announcementType)
	{
		return true;
	}

	ConnectionAcceptanceFilterStatus RenSharpGameModeEventClass::ConnectionRequestEvent(IConnectionRequest^ request, String^% refusalMessage)
	{
		return ConnectionAcceptanceFilterStatus::StatusAccepting;
	}

	void RenSharpGameModeEventClass::PlayerPreJoinEvent(IConnectionRequest^ request)
	{

	}

	void RenSharpGameModeEventClass::PlayerJoinEvent(IcPlayer^ player)
	{

	}

	void RenSharpGameModeEventClass::PlayerLeaveEvent(IcPlayer^ player)
	{

	}

	void RenSharpGameModeEventClass::PlayerLoadedEvent(IcPlayer^ player)
	{

	}

	void RenSharpGameModeEventClass::NameChangeEvent(IcPlayer^ player)
	{

	}

	void RenSharpGameModeEventClass::LevelLoadedEvent()
	{

	}

	void RenSharpGameModeEventClass::RemixEvent()
	{

	}

	void RenSharpGameModeEventClass::RebalanceEvent()
	{

	}

	void RenSharpGameModeEventClass::SwapEvent()
	{

	}

	void RenSharpGameModeEventClass::GameOverEvent()
	{

	}

	void RenSharpGameModeEventClass::ConsoleOutputEvent(String^ output)
	{

	}

	void RenSharpGameModeEventClass::RenLogEvent(String^ output)
	{

	}

	void RenSharpGameModeEventClass::DALogEvent(String^ header, String^ output)
	{

	}

	int RenSharpGameModeEventClass::CharacterPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, ISoldierGameObjDef^ item)
	{
		return -1;
	}

	int RenSharpGameModeEventClass::VehiclePurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, IVehicleGameObjDef^ item)
	{
		return -1;
	}

	int RenSharpGameModeEventClass::PowerUpPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, IPowerUpGameObjDef^ item)
	{
		return -1;
	}

	int RenSharpGameModeEventClass::CustomPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, unsigned int id)
	{
		return -1;
	}

	void RenSharpGameModeEventClass::CharacterPurchaseEvent(IcPlayer^ player, float cost, ISoldierGameObjDef^ item)
	{

	}

	void RenSharpGameModeEventClass::VehiclePurchaseEvent(IcPlayer^ player, float cost, IVehicleGameObjDef^ item)
	{

	}

	void RenSharpGameModeEventClass::PowerUpPurchaseEvent(IcPlayer^ player, float cost, IPowerUpGameObjDef^ item)
	{

	}

	void RenSharpGameModeEventClass::CustomPurchaseEvent(IcPlayer^ player, float cost, unsigned int id)
	{

	}

	bool RenSharpGameModeEventClass::RefillEvent(IcPlayer^ player)
	{
		return true;
	}

	bool RenSharpGameModeEventClass::SuicideEvent(IcPlayer^ player)
	{
		return true;
	}

	bool RenSharpGameModeEventClass::TeamChangeRequestEvent(IcPlayer^ player)
	{
		return true;
	}

	void RenSharpGameModeEventClass::TeamChangeEvent(IcPlayer^ player)
	{

	}

	bool RenSharpGameModeEventClass::VehicleEntryRequestEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int% seat)
	{
		return true;
	}

	void RenSharpGameModeEventClass::VehicleEnterEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int seat)
	{

	}

	void RenSharpGameModeEventClass::VehicleExitEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int seat)
	{

	}

	bool RenSharpGameModeEventClass::PowerUpGrantRequestEvent(IcPlayer^ player, IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj)
	{
		return true;
	}

	void RenSharpGameModeEventClass::PowerUpGrantEvent(IcPlayer^ player, IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj)
	{

	}

	bool RenSharpGameModeEventClass::AddWeaponRequestEvent(IcPlayer^ player, IWeaponDefinitionClass^ weapon)
	{
		return true;
	}

	void RenSharpGameModeEventClass::AddWeaponEvent(IcPlayer^ player, IWeaponClass^ weapon)
	{

	}

	void RenSharpGameModeEventClass::RemoveWeaponEvent(IcPlayer^ player, IWeaponClass^ weapon)
	{

	}

	void RenSharpGameModeEventClass::ClearWeaponsEvent(IcPlayer^ player)
	{

	}

	void RenSharpGameModeEventClass::BeaconDeployEvent(IBeaconGameObj^ beacon)
	{

	}

	void RenSharpGameModeEventClass::BeaconDetonateEvent(IBeaconGameObj^ beacon)
	{

	}

	bool RenSharpGameModeEventClass::C4DetonateRequestEvent(IC4GameObj^ c4, ISmartGameObj^ triggerer)
	{
		return true;
	}

	void RenSharpGameModeEventClass::C4DetonateEvent(IC4GameObj^ c4)
	{

	}

	void RenSharpGameModeEventClass::ChangeCharacterEvent(IcPlayer^ player, ISoldierGameObjDef^ soldier)
	{

	}

	bool RenSharpGameModeEventClass::VehicleFlipEvent(IVehicleGameObj^ vehicle)
	{
		return true;
	}

	bool RenSharpGameModeEventClass::RequestVehicleEvent(IVehicleFactoryGameObj^ factory, IVehicleGameObjDef^ vehicle, IcPlayer^ player, float delay)
	{
		return true;
	}

	void RenSharpGameModeEventClass::Think()
	{

	}

	void RenSharpGameModeEventClass::ObjectCreatedEvent(IScriptableGameObj^ obj)
	{

	}

	bool RenSharpGameModeEventClass::StockClientDamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float damage, uint warhead)
	{
		return true;
	}

	bool RenSharpGameModeEventClass::TTClientDamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, IAmmoDefinitionClass^ ammo, String^ bone)
	{
		return true;
	}

	bool RenSharpGameModeEventClass::DamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float% damage, unsigned int% warhead, float scale, DADamageType type)
	{
		return true;
	}

	void RenSharpGameModeEventClass::DamageEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float damage, unsigned int warhead, float scale, DADamageType type)
	{

	}

	void RenSharpGameModeEventClass::KillEvent(IDamageableGameObj^ victim, IArmedGameObj^ killer, float damage, unsigned int warhead, float scale, DADamageType type)
	{

	}

	void RenSharpGameModeEventClass::CustomEvent(IScriptableGameObj^ obj, int type, int param, IScriptableGameObj^ sender)
	{

	}

	void RenSharpGameModeEventClass::PokeEvent(IcPlayer^ player, IPhysicalGameObj^ obj)
	{

	}

	void RenSharpGameModeEventClass::ZoneEnterEvent(IScriptZoneGameObj^ obj, IPhysicalGameObj^ enterer)
	{

	}

	void RenSharpGameModeEventClass::ZoneExitEvent(IScriptZoneGameObj^ obj, IPhysicalGameObj^ exiter)
	{

	}

	void RenSharpGameModeEventClass::ObjectDestroyedEvent(IScriptableGameObj^ obj)
	{

	}

	void RenSharpGameModeEventClass::TimerExpired(int number, Object^ data)
	{

	}

	void RenSharpGameModeEventClass::StartTimer(int number, TimeSpan duration, bool repeat, Object^ data)
	{
		RenSharpTimerManager::StartTimer(this, number, duration, repeat, data);
	}

	void RenSharpGameModeEventClass::StartTimer(int number, TimeSpan duration, bool repeat)
	{
		RenSharpTimerManager::StartTimer(this, number, duration, repeat);
	}

	void RenSharpGameModeEventClass::StartTimer(int number, TimeSpan duration)
	{
		RenSharpTimerManager::StartTimer(this, number, duration);
	}

	void RenSharpGameModeEventClass::StopTimer(int number, Object^ data)
	{
		RenSharpTimerManager::StopTimer(this, number, data);

		if (data == nullptr)
		{
			InternalDAEventClassPointer->Stop_Timer(number, 0);
		}
		else if (UInt32::typeid->Equals(data->GetType()))
		{
			InternalDAEventClassPointer->Stop_Timer(number, safe_cast<UInt32>(data));
		}
	}

	void RenSharpGameModeEventClass::StopTimer(int number)
	{
		RenSharpTimerManager::StopTimer(this, number);

		InternalDAEventClassPointer->Stop_Timer(number);
	}

	bool RenSharpGameModeEventClass::IsTimer(int number, Object^ data)
	{
		if (RenSharpTimerManager::IsTimer(this, number, data))
		{
			return true;
		}
		else if (data == nullptr)
		{
			if (InternalDAEventClassPointer->Is_Timer(number, 0))
			{
				return true;
			}
		}
		else if (UInt32::typeid->Equals(data->GetType()))
		{
			if (InternalDAEventClassPointer->Is_Timer(number, safe_cast<UInt32>(data)))
			{
				return true;
			}
		}

		return false;
	}

	bool RenSharpGameModeEventClass::IsTimer(int number)
	{
		if (RenSharpTimerManager::IsTimer(this, number))
		{
			return true;
		}

		return InternalDAEventClassPointer->Is_Timer(number);
	}

	void RenSharpGameModeEventClass::ClearTimers()
	{
		RenSharpTimerManager::ClearTimers(this);
		InternalDAEventClassPointer->Clear_Timers();
	}

	bool RenSharpGameModeEventClass::FilterChatCommand(IcPlayer^ player, String^ command, IDATokenClass^ text, TextMessageEnum chatType, Object^ data)
	{
		return true;
	}

	void RenSharpGameModeEventClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel, DAChatType chatType, Object^ data)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers, parameters, accessLevel, chatType, data);
	}

	void RenSharpGameModeEventClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel, DAChatType chatType)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers, parameters, accessLevel, chatType);
	}

	void RenSharpGameModeEventClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers, parameters, accessLevel);
	}

	void RenSharpGameModeEventClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, Object^ data)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers, parameters, data);
	}

	void RenSharpGameModeEventClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers, parameters);
	}

	void RenSharpGameModeEventClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers);
	}

	void RenSharpGameModeEventClass::UnregisterChatCommand(String^ trigger)
	{
		if (trigger == nullptr)
		{
			throw gcnew ArgumentNullException("trigger");
		}

		RenSharpChatCommandManager::UnregisterChatCommand(this, ChatCommandGroup::EventClass, trigger);

		IntPtr triggerHandle = Marshal::StringToHGlobalAnsi(trigger);
		try
		{
			InternalDAEventClassPointer->Unregister_Chat_Command(
				reinterpret_cast<char*>(triggerHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(triggerHandle);
		}
	}

	void RenSharpGameModeEventClass::ClearChatCommands()
	{
		RenSharpChatCommandManager::ClearChatCommands(this, ChatCommandGroup::EventClass);
		InternalDAEventClassPointer->Clear_Chat_Commands();
	}

	bool RenSharpGameModeEventClass::FilterKeyHook(IcPlayer^ player, String^ key, Object^ data)
	{
		return true;
	}

	void RenSharpGameModeEventClass::RegisterKeyHook(RenSharpKHDelegate^ func, String^ triggers, Object^ data)
	{
		RenSharpKeyHookManager::RegisterKeyHook(this, KeyHookGroup::EventClass, func, triggers, data);
	}

	void RenSharpGameModeEventClass::RegisterKeyHook(RenSharpKHDelegate^ func, String^ triggers)
	{
		RenSharpKeyHookManager::RegisterKeyHook(this, KeyHookGroup::EventClass, func, triggers);
	}

	void RenSharpGameModeEventClass::UnregisterKeyHook(String^ trigger)
	{
		if (trigger == nullptr)
		{
			throw gcnew ArgumentNullException("trigger");
		}

		RenSharpKeyHookManager::UnregisterKeyHook(this, KeyHookGroup::EventClass, trigger);

		IntPtr triggerHandle = Marshal::StringToHGlobalAnsi(trigger);
		try
		{
			InternalDAEventClassPointer->Unregister_Key_Hook(
				reinterpret_cast<char*>(triggerHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(triggerHandle);
		}
	}

	void RenSharpGameModeEventClass::ClearKeyHooks()
	{
		RenSharpKeyHookManager::ClearKeyHooks(this, KeyHookGroup::EventClass);
		InternalDAEventClassPointer->Clear_Key_Hooks();
	}

	void RenSharpGameModeEventClass::RegisterEvent(DAEventType type, std::uint32_t priority)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daEventClass->RegisterEvent(type, priority);
	}

	void RenSharpGameModeEventClass::RegisterEvent(DAEventType type)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daEventClass->RegisterEvent(type);
	}

	void RenSharpGameModeEventClass::UnregisterEvent(DAEventType type)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daEventClass->UnregisterEvent(type);
	}

	void RenSharpGameModeEventClass::ClearEvents()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daEventClass->ClearEvents();
	}

	void RenSharpGameModeEventClass::RegisterObjectEvent(DAObjectEventType type, DAObjectEventObjectType objectType, std::uint32_t priority)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daEventClass->RegisterObjectEvent(type, objectType, priority);
	}

	void RenSharpGameModeEventClass::RegisterObjectEvent(DAObjectEventType type, DAObjectEventObjectType objectType)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daEventClass->RegisterObjectEvent(type, objectType);
	}

	void RenSharpGameModeEventClass::UnregisterObjectEvent(DAObjectEventType type)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daEventClass->UnregisterObjectEvent(type);
	}

	void RenSharpGameModeEventClass::ClearObjectEvents()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daEventClass->ClearObjectEvents();
	}

	IntPtr RenSharpGameModeEventClass::DAGameModeClassPointer::get()
	{
		return daGameModeClassPointer;
	}

	IntPtr RenSharpGameModeEventClass::DAEventClassPointer::get()
	{
		return daEventClassPointer;
	}

	IntPtr RenSharpGameModeEventClass::Pointer::get()
	{
		return renSharpGameModeEventClassPointer;
	}

	bool RenSharpGameModeEventClass::IsAttached::get()
	{
		return (renSharpGameModeEventClassPointer != IntPtr::Zero);
	}

	bool RenSharpGameModeEventClass::DestroyPointer::get()
	{
		return destroyPointer;
	}

	void RenSharpGameModeEventClass::DestroyPointer::set(bool value)
	{
		destroyPointer = value;
	}

	String^ RenSharpGameModeEventClass::LongName::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daGameModeClass->LongName;
	}

	String^ RenSharpGameModeEventClass::ShortName::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daGameModeClass->ShortName;
	}

	IDAGameModeFactoryClass^ RenSharpGameModeEventClass::Factory::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daGameModeClass->Factory;
	}

	void RenSharpGameModeEventClass::Factory::set(IDAGameModeFactoryClass^ value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daGameModeClass->Factory = value;
	}

	Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ RenSharpGameModeEventClass::Timers::get()
	{
		return RenSharpTimerManager::GetTimers(this);
	}

	Collections::Generic::IEnumerable<RenSharpChatCommandStruct^>^ RenSharpGameModeEventClass::ChatCommands::get()
	{
		return RenSharpChatCommandManager::GetChatCommands(this, ChatCommandGroup::EventClass);
	}

	Collections::Generic::IEnumerable<RenSharpKeyHookStruct^>^ RenSharpGameModeEventClass::KeyHooks::get()
	{
		return RenSharpKeyHookManager::GetKeyHooks(this, KeyHookGroup::EventClass);
	}

	::DAGameModeClass* RenSharpGameModeEventClass::InternalDAGameModeClassPointer::get()
	{
		return reinterpret_cast<::DAGameModeClass*>(daGameModeClassPointer.ToPointer());
	}

	::DAEventClass* RenSharpGameModeEventClass::InternalDAEventClassPointer::get()
	{
		return reinterpret_cast<::DAEventClass*>(daEventClassPointer.ToPointer());
	}
}