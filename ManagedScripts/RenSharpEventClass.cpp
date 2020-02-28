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
#include "RenSharpEventClass.h"

#include "Imports.h"
#include "RenSharpChatCommandManager.h"
#include "RenSharpKeyHookManager.h"
#include "RenSharpTimerManager.h"

namespace RenSharp
{
	RenSharpEventClass::RenSharpEventClass()
		: disposedResources(false), destroyPointer(true), daEventClassPointer(IntPtr::Zero), daEventClass(nullptr)
	{

	}

	RenSharpEventClass::~RenSharpEventClass()
	{
		if (disposedResources)
		{
			return;
		}

		DAEventManager::UnregisterManagedEventClass(this);

		ClearTimers();
		ClearChatCommands();
		ClearKeyHooks();

		this->!RenSharpEventClass();

		disposedResources = true;
	}

	RenSharpEventClass::!RenSharpEventClass()
	{
		if (destroyPointer && IsAttached)
		{
			IntPtr tmp = daEventClassPointer;
			daEventClassPointer = IntPtr::Zero;
			Imports::DestroyDAEventClass(reinterpret_cast<::DAEventClass*>(tmp.ToPointer()));
		}

		ReleasePointer();
	}

	bool RenSharpEventClass::Equals(Object^ other)
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

		IRenSharpEventClass^ otherThis2 = dynamic_cast<IRenSharpEventClass^>(other);
		if (otherThis2 == nullptr)
		{
			return false;
		}

		return daEventClassPointer.Equals(otherThis2->DAEventClassPointer);
	}

	int RenSharpEventClass::GetHashCode()
	{
		return daEventClassPointer.GetHashCode();
	}

	void RenSharpEventClass::InitUnmanagedAttachable()
	{
		AttachToUnmanagedObject();
		RegisterManagedObject();
	}

	void RenSharpEventClass::AttachToUnmanagedObject()
	{
		if (IsAttached)
		{
			throw gcnew NotSupportedException("Already attached.");
		}

		::RenSharpEventClass* newEventClass = nullptr;
		try
		{
			newEventClass = Imports::CreateRenSharpEventClass();

			daEventClassPointer = IntPtr(newEventClass);
		}
		catch (Exception^)
		{
			if (newEventClass != nullptr)
			{
				Imports::DestroyDAEventClass(reinterpret_cast<::DAEventClass*>(newEventClass));
			}

			throw;
		}

		daEventClass = gcnew DAEventClass(daEventClassPointer);

		UnmanagedAttach();
	}

	void RenSharpEventClass::RegisterManagedObject()
	{
		DAEventManager::RegisterManagedEventClass(this);

		ManagedRegistered();
	}

	void RenSharpEventClass::ReleasePointer()
	{
		daEventClassPointer = IntPtr::Zero;
		daEventClass = nullptr;
	}

	void RenSharpEventClass::UnmanagedAttach()
	{

	}

	void RenSharpEventClass::ManagedRegistered()
	{

	}

	void RenSharpEventClass::SettingsLoadedEvent()
	{

	}

	bool RenSharpEventClass::ChatEvent(IcPlayer ^player, TextMessageEnum type, String ^message, int receiverID)
	{
		return true;
	}

	bool RenSharpEventClass::ChatCommandEvent(IcPlayer ^player, TextMessageEnum type, String ^command, IDATokenClass ^text, int receiverID)
	{
		return true;
	}

	bool RenSharpEventClass::KeyHookEvent(IcPlayer ^player, String ^key)
	{
		return true;
	}

	bool RenSharpEventClass::HostChatEvent(int id, TextMessageEnum type, String ^message)
	{
		return true;
	}

	bool RenSharpEventClass::RadioEvent(IcPlayer ^player, int playerType, int announcementID, int iconID, AnnouncementEnum announcementType)
	{
		return true;
	}

	ConnectionAcceptanceFilterStatus RenSharpEventClass::ConnectionRequestEvent(IConnectionRequest ^request, String ^%refusalMessage)
	{
		return ConnectionAcceptanceFilterStatus::StatusAccepting;
	}

	void RenSharpEventClass::PlayerPreJoinEvent(IConnectionRequest ^request)
	{

	}

	void RenSharpEventClass::PlayerJoinEvent(IcPlayer ^player)
	{

	}

	void RenSharpEventClass::PlayerLeaveEvent(IcPlayer ^player)
	{

	}

	void RenSharpEventClass::PlayerLoadedEvent(IcPlayer ^player)
	{

	}

	void RenSharpEventClass::NameChangeEvent(IcPlayer ^player)
	{

	}

	void RenSharpEventClass::LevelLoadedEvent()
	{

	}

	void RenSharpEventClass::RemixEvent()
	{

	}

	void RenSharpEventClass::RebalanceEvent()
	{

	}

	void RenSharpEventClass::SwapEvent()
	{

	}

	void RenSharpEventClass::GameOverEvent()
	{

	}

	void RenSharpEventClass::ConsoleOutputEvent(String ^output)
	{

	}

	void RenSharpEventClass::RenLogEvent(String ^output)
	{

	}

	void RenSharpEventClass::DALogEvent(String ^header, String ^output)
	{

	}

	int RenSharpEventClass::CharacterPurchaseRequestEvent(IBaseControllerClass ^baseController, IcPlayer ^player, float %cost, ISoldierGameObjDef ^item)
	{
		return -1;
	}

	int RenSharpEventClass::VehiclePurchaseRequestEvent(IBaseControllerClass ^baseController, IcPlayer ^player, float %cost, IVehicleGameObjDef ^item)
	{
		return -1;
	}

	int RenSharpEventClass::PowerUpPurchaseRequestEvent(IBaseControllerClass ^baseController, IcPlayer ^player, float %cost, IPowerUpGameObjDef ^item)
	{
		return -1;
	}

	int RenSharpEventClass::CustomPurchaseRequestEvent(IBaseControllerClass ^baseController, IcPlayer ^player, float %cost, unsigned int id)
	{
		return -1;
	}

	void RenSharpEventClass::CharacterPurchaseEvent(IcPlayer ^player, float cost, ISoldierGameObjDef ^item)
	{

	}

	void RenSharpEventClass::VehiclePurchaseEvent(IcPlayer ^player, float cost, IVehicleGameObjDef ^item)
	{

	}

	void RenSharpEventClass::PowerUpPurchaseEvent(IcPlayer ^player, float cost, IPowerUpGameObjDef ^item)
	{

	}

	void RenSharpEventClass::CustomPurchaseEvent(IcPlayer ^player, float cost, unsigned int id)
	{

	}

	bool RenSharpEventClass::RefillEvent(IcPlayer ^player)
	{
		return true;
	}

	bool RenSharpEventClass::SuicideEvent(IcPlayer ^player)
	{
		return true;
	}

	bool RenSharpEventClass::TeamChangeRequestEvent(IcPlayer ^player)
	{
		return true;
	}

	void RenSharpEventClass::TeamChangeEvent(IcPlayer ^player)
	{

	}

	bool RenSharpEventClass::VehicleEntryRequestEvent(IVehicleGameObj ^vehicle, IcPlayer ^player, int %seat)
	{
		return true;
	}

	void RenSharpEventClass::VehicleEnterEvent(IVehicleGameObj ^vehicle, IcPlayer ^player, int seat)
	{

	}

	void RenSharpEventClass::VehicleExitEvent(IVehicleGameObj ^vehicle, IcPlayer ^player, int seat)
	{

	}

	bool RenSharpEventClass::PowerUpGrantRequestEvent(IcPlayer ^player, IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj)
	{
		return true;
	}

	void RenSharpEventClass::PowerUpGrantEvent(IcPlayer ^player, IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj)
	{

	}

	bool RenSharpEventClass::AddWeaponRequestEvent(IcPlayer ^player, IWeaponDefinitionClass ^weapon)
	{
		return true;
	}

	void RenSharpEventClass::AddWeaponEvent(IcPlayer ^player, IWeaponClass ^weapon)
	{

	}

	void RenSharpEventClass::RemoveWeaponEvent(IcPlayer ^player, IWeaponClass ^weapon)
	{

	}

	void RenSharpEventClass::ClearWeaponsEvent(IcPlayer ^player)
	{

	}

	void RenSharpEventClass::BeaconDeployEvent(IBeaconGameObj ^beacon)
	{

	}

	void RenSharpEventClass::BeaconDetonateEvent(IBeaconGameObj ^beacon)
	{

	}

	bool RenSharpEventClass::C4DetonateRequestEvent(IC4GameObj ^c4, ISmartGameObj ^triggerer)
	{
		return true;
	}

	void RenSharpEventClass::C4DetonateEvent(IC4GameObj ^c4)
	{

	}

	void RenSharpEventClass::ChangeCharacterEvent(IcPlayer ^player, ISoldierGameObjDef ^soldier)
	{

	}

	bool RenSharpEventClass::VehicleFlipEvent(IVehicleGameObj ^vehicle)
	{
		return true;
	}

	bool RenSharpEventClass::RequestVehicleEvent(IVehicleFactoryGameObj ^factory, IVehicleGameObjDef ^vehicle, IcPlayer ^player, float delay)
	{
		return true;
	}

	void RenSharpEventClass::Think()
	{

	}

	void RenSharpEventClass::ObjectCreatedEvent(IScriptableGameObj ^obj)
	{

	}

	bool RenSharpEventClass::StockClientDamageRequestEvent(IDamageableGameObj ^victim, IArmedGameObj ^damager, float damage, uint warhead)
	{
		return true;
	}

	bool RenSharpEventClass::TTClientDamageRequestEvent(IDamageableGameObj ^victim, IArmedGameObj ^damager, IAmmoDefinitionClass ^ammo, String ^bone)
	{
		return true;
	}

	bool RenSharpEventClass::DamageRequestEvent(IDamageableGameObj ^victim, IArmedGameObj ^damager, float %damage, unsigned int %warhead, float scale, DADamageType type)
	{
		return true;
	}

	void RenSharpEventClass::DamageEvent(IDamageableGameObj ^victim, IArmedGameObj ^damager, float damage, unsigned int warhead, float scale, DADamageType type)
	{

	}

	void RenSharpEventClass::KillEvent(IDamageableGameObj ^victim, IArmedGameObj ^killer, float damage, unsigned int warhead, float scale, DADamageType type)
	{

	}

	void RenSharpEventClass::CustomEvent(IScriptableGameObj ^obj, int type, int param, IScriptableGameObj ^sender)
	{

	}

	void RenSharpEventClass::PokeEvent(IcPlayer ^player, IPhysicalGameObj ^obj)
	{

	}

	void RenSharpEventClass::ZoneEnterEvent(IScriptZoneGameObj ^obj, IPhysicalGameObj ^enterer)
	{

	}

	void RenSharpEventClass::ZoneExitEvent(IScriptZoneGameObj ^obj, IPhysicalGameObj ^exiter)
	{

	}

	void RenSharpEventClass::ObjectDestroyedEvent(IScriptableGameObj ^obj)
	{

	}

	void RenSharpEventClass::TimerExpired(int number, Object^ data)
	{

	}

	void RenSharpEventClass::StartTimer(int number, TimeSpan duration, bool repeat, Object^ data)
	{
		RenSharpTimerManager::StartTimer(this, number, duration, repeat, data);
	}

	void RenSharpEventClass::StartTimer(int number, TimeSpan duration, bool repeat)
	{
		RenSharpTimerManager::StartTimer(this, number, duration, repeat);
	}

	void RenSharpEventClass::StartTimer(int number, TimeSpan duration)
	{
		RenSharpTimerManager::StartTimer(this, number, duration);
	}

	void RenSharpEventClass::StopTimer(int number, Object^ data)
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

	void RenSharpEventClass::StopTimer(int number)
	{
		RenSharpTimerManager::StopTimer(this, number);

		InternalDAEventClassPointer->Stop_Timer(number);
	}

	bool RenSharpEventClass::IsTimer(int number, Object^ data)
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

	bool RenSharpEventClass::IsTimer(int number)
	{
		if (RenSharpTimerManager::IsTimer(this, number))
		{
			return true;
		}

		return InternalDAEventClassPointer->Is_Timer(number);
	}

	void RenSharpEventClass::ClearTimers()
	{
		RenSharpTimerManager::ClearTimers(this);
	}

	bool RenSharpEventClass::FilterChatCommand(IcPlayer^ player, String^ command, IDATokenClass^ text, TextMessageEnum chatType, Object^ data)
	{
		return true;
	}

	void RenSharpEventClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel, DAChatType chatType, Object^ data)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers, parameters, accessLevel, chatType, data);
	}

	void RenSharpEventClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel, DAChatType chatType)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers, parameters, accessLevel, chatType);
	}

	void RenSharpEventClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers, parameters, accessLevel);
	}

	void RenSharpEventClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, Object^ data)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers, parameters, data);
	}

	void RenSharpEventClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers, parameters);
	}

	void RenSharpEventClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers);
	}

	void RenSharpEventClass::UnregisterChatCommand(String^ trigger)
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

	void RenSharpEventClass::ClearChatCommands()
	{
		RenSharpChatCommandManager::ClearChatCommands(this, ChatCommandGroup::EventClass);
		InternalDAEventClassPointer->Clear_Chat_Commands();
	}

	bool RenSharpEventClass::FilterKeyHook(IcPlayer^ player, String^ key, Object^ data)
	{
		return true;
	}

	void RenSharpEventClass::RegisterKeyHook(RenSharpKHDelegate^ func, String^ triggers, Object^ data)
	{
		RenSharpKeyHookManager::RegisterKeyHook(this, KeyHookGroup::EventClass, func, triggers, data);
	}

	void RenSharpEventClass::RegisterKeyHook(RenSharpKHDelegate^ func, String^ triggers)
	{
		RenSharpKeyHookManager::RegisterKeyHook(this, KeyHookGroup::EventClass, func, triggers);
	}

	void RenSharpEventClass::UnregisterKeyHook(String^ trigger)
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

	void RenSharpEventClass::ClearKeyHooks()
	{
		RenSharpKeyHookManager::ClearKeyHooks(this, KeyHookGroup::EventClass);
		InternalDAEventClassPointer->Clear_Key_Hooks();
	}

	void RenSharpEventClass::RegisterEvent(DAEventType type, std::uint32_t priority)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daEventClass->RegisterEvent(type, priority);
	}

	void RenSharpEventClass::RegisterEvent(DAEventType type)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daEventClass->RegisterEvent(type);
	}

	void RenSharpEventClass::UnregisterEvent(DAEventType type)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daEventClass->UnregisterEvent(type);
	}

	void RenSharpEventClass::ClearEvents()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daEventClass->ClearEvents();
	}

	void RenSharpEventClass::RegisterObjectEvent(DAObjectEventType type, DAObjectEventObjectType objectType, std::uint32_t priority)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daEventClass->RegisterObjectEvent(type, objectType, priority);
	}

	void RenSharpEventClass::RegisterObjectEvent(DAObjectEventType type, DAObjectEventObjectType objectType)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daEventClass->RegisterObjectEvent(type, objectType);
	}

	void RenSharpEventClass::UnregisterObjectEvent(DAObjectEventType type)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daEventClass->UnregisterObjectEvent(type);
	}

	void RenSharpEventClass::ClearObjectEvents()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daEventClass->ClearObjectEvents();
	}

	IDAEventClass^ RenSharpEventClass::AsUnmanagedObject()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daEventClass;
	}

	Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ RenSharpEventClass::Timers::get()
	{
		return RenSharpTimerManager::GetTimers(this);
	}

	IntPtr RenSharpEventClass::DAEventClassPointer::get()
	{
		return daEventClassPointer;
	}

	IntPtr RenSharpEventClass::Pointer::get()
	{
		return daEventClassPointer;
	}

	bool RenSharpEventClass::IsAttached::get()
	{
		return (daEventClassPointer != IntPtr::Zero);
	}

	bool RenSharpEventClass::IsRegistered::get()
	{
		return (IsAttached && DAEventManager::IsManagedEventClass(daEventClassPointer));
	}

	Collections::Generic::IEnumerable<RenSharpChatCommandStruct^>^ RenSharpEventClass::ChatCommands::get()
	{
		return RenSharpChatCommandManager::GetChatCommands(this, ChatCommandGroup::EventClass);
	}

	Collections::Generic::IEnumerable<RenSharpKeyHookStruct^>^ RenSharpEventClass::KeyHooks::get()
	{
		return RenSharpKeyHookManager::GetKeyHooks(this, KeyHookGroup::EventClass);
	}

	bool RenSharpEventClass::DestroyPointer::get()
	{
		return destroyPointer;
	}

	void RenSharpEventClass::DestroyPointer::set(bool value)
	{
		destroyPointer = value;
	}

	::DAEventClass* RenSharpEventClass::InternalDAEventClassPointer::get()
	{
		return reinterpret_cast<::DAEventClass*>(daEventClassPointer.ToPointer());
	}
}