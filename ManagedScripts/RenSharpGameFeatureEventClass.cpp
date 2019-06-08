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
#include "RenSharpGameFeatureEventClass.h"

#include "Imports.h"
#include "Mda_game.h"
#include "RenSharpChatCommandManager.h"
#include "RenSharpKeyHookManager.h"
#include "RenSharpTimerManager.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_gamefeature.h>
#include <da_event.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Text;

namespace RenSharp
{
	RenSharpGameFeatureEventClass::RenSharpGameFeatureEventClass()
		:
		disposedResources(false),
		destroyPointer(true),
		renSharpGameFeatureEventClassPointer(IntPtr::Zero),
		daGameFeatureClassPointer(IntPtr::Zero),
		daEventClassPointer(IntPtr::Zero),
		daGameFeatureClass(nullptr),
		daEventClass(nullptr)
	{

	}

	RenSharpGameFeatureEventClass::~RenSharpGameFeatureEventClass()
	{
		if (disposedResources)
		{
			return;
		}

		DAEventManager::UnregisterManagedEventClass(this);
		DAGameManager::UnregisterManagedGameFeature(this);

		ClearTimers();
		ClearChatCommands();
		ClearKeyHooks();

		this->!RenSharpGameFeatureEventClass();

		disposedResources = true;
	}

	RenSharpGameFeatureEventClass::!RenSharpGameFeatureEventClass()
	{
		if (IsAttached)
		{
			auto factory = const_cast<::DAGameFeatureFactoryClass*>(InternalDAGameFeatureClassPointer->Get_Factory());
			if (factory != nullptr)
			{
				auto helper = reinterpret_cast<DAGameFeatureFactoryClassHelper*>(factory);

				auto& instance = helper->GetInstance();
				if (instance == InternalDAGameFeatureClassPointer)
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

	String^ RenSharpGameFeatureEventClass::ToString()
	{
		StringBuilder^ builder = gcnew StringBuilder();
		if (IsAttached)
		{
			builder->Append(Name);
		}
		else
		{
			builder->Append(static_cast<Object^>(nullptr));
		}

		return builder->ToString();
	}

	bool RenSharpGameFeatureEventClass::Equals(Object^ other)
	{
		if (ReferenceEquals(other, nullptr))
		{
			return false;
		}

		IDAGameFeatureClass^ otherThis1 = dynamic_cast<IDAGameFeatureClass^>(other);
		if (otherThis1 != nullptr && daGameFeatureClassPointer.Equals(otherThis1->DAGameFeatureClassPointer))
		{
			return true;
		}

		IDAEventClass^ otherThis2 = dynamic_cast<IDAEventClass^>(other);
		if (otherThis2 != nullptr && daEventClassPointer.Equals(otherThis2->DAEventClassPointer))
		{
			return true;
		}

		IRenSharpGameFeatureClass^ otherThis3 = dynamic_cast<IRenSharpGameFeatureClass^>(other);
		if (otherThis3 != nullptr && daGameFeatureClassPointer.Equals(otherThis3->DAGameFeatureClassPointer))
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

	int RenSharpGameFeatureEventClass::GetHashCode()
	{
		return renSharpGameFeatureEventClassPointer.GetHashCode();
	}

	void RenSharpGameFeatureEventClass::AttachToUnmanagedObject()
	{
		if (IsAttached)
		{
			throw gcnew NotSupportedException("Already attached.");
		}

		try
		{
			::RenSharpGameFeatureEventClass* renSharpGameFeatureEventPtr = nullptr;
			::RenSharpEventClass* eventClassPtr = nullptr;
			::RenSharpGameFeatureClass* gameFeaturePtr = nullptr;

			renSharpGameFeatureEventPtr = Imports::CreateRenSharpGameFeatureEventClass(&eventClassPtr, &gameFeaturePtr);

			renSharpGameFeatureEventClassPointer = IntPtr(renSharpGameFeatureEventPtr);
			daGameFeatureClassPointer = IntPtr(gameFeaturePtr);
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

		daGameFeatureClass = gcnew DAGameFeatureClass(daGameFeatureClassPointer);
		daEventClass = gcnew DAEventClass(daEventClassPointer);

		UnmanagedAttach();
	}

	void RenSharpGameFeatureEventClass::RegisterManagedObject()
	{
		DAGameManager::RegisterManagedGameFeature(this);
		DAEventManager::RegisterManagedEventClass(this);

		ManagedRegistered();
	}

	void RenSharpGameFeatureEventClass::ReleasePointer()
	{
		renSharpGameFeatureEventClassPointer = IntPtr::Zero;
		daGameFeatureClassPointer = IntPtr::Zero;
		daEventClassPointer = IntPtr::Zero;
		daGameFeatureClass = nullptr;
		daEventClass = nullptr;
	}

	void RenSharpGameFeatureEventClass::UnmanagedAttach()
	{

	}

	void RenSharpGameFeatureEventClass::ManagedRegistered()
	{

	}

	IDAGameFeatureClass^ RenSharpGameFeatureEventClass::AsUnmanagedGameFeature()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daGameFeatureClass;
	}

	IDAEventClass^ RenSharpGameFeatureEventClass::AsUnmanagedEventClass()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daEventClass;
	}

	void RenSharpGameFeatureEventClass::Init()
	{

	}

	void RenSharpGameFeatureEventClass::SettingsLoadedEvent()
	{

	}

	bool RenSharpGameFeatureEventClass::ChatEvent(IcPlayer^ player, TextMessageEnum type, String^ message, int receiverID)
	{
		return true;
	}

	bool RenSharpGameFeatureEventClass::ChatCommandEvent(IcPlayer^ player, TextMessageEnum type, String^ command, IDATokenClass^ text, int receiverID)
	{
		return true;
	}

	bool RenSharpGameFeatureEventClass::KeyHookEvent(IcPlayer^ player, String^ key)
	{
		return true;
	}

	bool RenSharpGameFeatureEventClass::HostChatEvent(int id, TextMessageEnum type, String^ message)
	{
		return true;
	}

	bool RenSharpGameFeatureEventClass::RadioEvent(IcPlayer^ player, int playerType, int announcementID, int iconID, AnnouncementEnum announcementType)
	{
		return true;
	}

	ConnectionAcceptanceFilterStatus RenSharpGameFeatureEventClass::ConnectionRequestEvent(IConnectionRequest^ request, String^% refusalMessage)
	{
		return ConnectionAcceptanceFilterStatus::StatusAccepting;
	}

	void RenSharpGameFeatureEventClass::PlayerPreJoinEvent(IConnectionRequest^ request)
	{

	}

	void RenSharpGameFeatureEventClass::PlayerJoinEvent(IcPlayer^ player)
	{

	}

	void RenSharpGameFeatureEventClass::PlayerLeaveEvent(IcPlayer^ player)
	{

	}

	void RenSharpGameFeatureEventClass::PlayerLoadedEvent(IcPlayer^ player)
	{

	}

	void RenSharpGameFeatureEventClass::NameChangeEvent(IcPlayer^ player)
	{

	}

	void RenSharpGameFeatureEventClass::LevelLoadedEvent()
	{

	}

	void RenSharpGameFeatureEventClass::RemixEvent()
	{

	}

	void RenSharpGameFeatureEventClass::RebalanceEvent()
	{

	}

	void RenSharpGameFeatureEventClass::SwapEvent()
	{

	}

	void RenSharpGameFeatureEventClass::GameOverEvent()
	{

	}

	void RenSharpGameFeatureEventClass::ConsoleOutputEvent(String^ output)
	{

	}

	void RenSharpGameFeatureEventClass::RenLogEvent(String^ output)
	{

	}

	void RenSharpGameFeatureEventClass::DALogEvent(String^ header, String^ output)
	{

	}

	int RenSharpGameFeatureEventClass::CharacterPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, ISoldierGameObjDef^ item)
	{
		return -1;
	}

	int RenSharpGameFeatureEventClass::VehiclePurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, IVehicleGameObjDef^ item)
	{
		return -1;
	}

	int RenSharpGameFeatureEventClass::PowerUpPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, IPowerUpGameObjDef^ item)
	{
		return -1;
	}

	int RenSharpGameFeatureEventClass::CustomPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, unsigned int id)
	{
		return -1;
	}

	void RenSharpGameFeatureEventClass::CharacterPurchaseEvent(IcPlayer^ player, float cost, ISoldierGameObjDef^ item)
	{

	}

	void RenSharpGameFeatureEventClass::VehiclePurchaseEvent(IcPlayer^ player, float cost, IVehicleGameObjDef^ item)
	{

	}

	void RenSharpGameFeatureEventClass::PowerUpPurchaseEvent(IcPlayer^ player, float cost, IPowerUpGameObjDef^ item)
	{

	}

	void RenSharpGameFeatureEventClass::CustomPurchaseEvent(IcPlayer^ player, float cost, unsigned int id)
	{

	}

	bool RenSharpGameFeatureEventClass::RefillEvent(IcPlayer^ player)
	{
		return true;
	}

	bool RenSharpGameFeatureEventClass::SuicideEvent(IcPlayer^ player)
	{
		return true;
	}

	bool RenSharpGameFeatureEventClass::TeamChangeRequestEvent(IcPlayer^ player)
	{
		return true;
	}

	void RenSharpGameFeatureEventClass::TeamChangeEvent(IcPlayer^ player)
	{

	}

	bool RenSharpGameFeatureEventClass::VehicleEntryRequestEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int% seat)
	{
		return true;
	}

	void RenSharpGameFeatureEventClass::VehicleEnterEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int seat)
	{

	}

	void RenSharpGameFeatureEventClass::VehicleExitEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int seat)
	{

	}

	bool RenSharpGameFeatureEventClass::PowerUpGrantRequestEvent(IcPlayer^ player, IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj)
	{
		return true;
	}

	void RenSharpGameFeatureEventClass::PowerUpGrantEvent(IcPlayer^ player, IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj)
	{

	}

	bool RenSharpGameFeatureEventClass::AddWeaponRequestEvent(IcPlayer^ player, IWeaponDefinitionClass^ weapon)
	{
		return true;
	}

	void RenSharpGameFeatureEventClass::AddWeaponEvent(IcPlayer^ player, IWeaponClass^ weapon)
	{

	}

	void RenSharpGameFeatureEventClass::RemoveWeaponEvent(IcPlayer^ player, IWeaponClass^ weapon)
	{

	}

	void RenSharpGameFeatureEventClass::ClearWeaponsEvent(IcPlayer^ player)
	{

	}

	void RenSharpGameFeatureEventClass::BeaconDeployEvent(IBeaconGameObj^ beacon)
	{

	}

	void RenSharpGameFeatureEventClass::BeaconDetonateEvent(IBeaconGameObj^ beacon)
	{

	}

	bool RenSharpGameFeatureEventClass::C4DetonateRequestEvent(IC4GameObj^ c4, ISmartGameObj^ triggerer)
	{
		return true;
	}

	void RenSharpGameFeatureEventClass::C4DetonateEvent(IC4GameObj^ c4)
	{

	}

	void RenSharpGameFeatureEventClass::ChangeCharacterEvent(IcPlayer^ player, ISoldierGameObjDef^ soldier)
	{

	}

	bool RenSharpGameFeatureEventClass::VehicleFlipEvent(IVehicleGameObj^ vehicle)
	{
		return true;
	}

	bool RenSharpGameFeatureEventClass::RequestVehicleEvent(IVehicleFactoryGameObj^ factory, IVehicleGameObjDef^ vehicle, IcPlayer^ player, float delay)
	{
		return true;
	}

	void RenSharpGameFeatureEventClass::Think()
	{

	}

	void RenSharpGameFeatureEventClass::ObjectCreatedEvent(IScriptableGameObj^ obj)
	{

	}

	bool RenSharpGameFeatureEventClass::StockClientDamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float damage, uint warhead)
	{
		return true;
	}

	bool RenSharpGameFeatureEventClass::TTClientDamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, IAmmoDefinitionClass^ ammo, String^ bone)
	{
		return true;
	}

	bool RenSharpGameFeatureEventClass::DamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float% damage, unsigned int% warhead, float scale, DADamageType type)
	{
		return true;
	}

	void RenSharpGameFeatureEventClass::DamageEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float damage, unsigned int warhead, float scale, DADamageType type)
	{

	}

	void RenSharpGameFeatureEventClass::KillEvent(IDamageableGameObj^ victim, IArmedGameObj^ killer, float damage, unsigned int warhead, float scale, DADamageType type)
	{

	}

	void RenSharpGameFeatureEventClass::CustomEvent(IScriptableGameObj^ obj, int type, int param, IScriptableGameObj^ sender)
	{

	}

	void RenSharpGameFeatureEventClass::PokeEvent(IcPlayer^ player, IPhysicalGameObj^ obj)
	{

	}

	void RenSharpGameFeatureEventClass::ZoneEnterEvent(IScriptZoneGameObj^ obj, IPhysicalGameObj^ enterer)
	{

	}

	void RenSharpGameFeatureEventClass::ZoneExitEvent(IScriptZoneGameObj^ obj, IPhysicalGameObj^ exiter)
	{

	}

	void RenSharpGameFeatureEventClass::ObjectDestroyedEvent(IScriptableGameObj^ obj)
	{

	}

	void RenSharpGameFeatureEventClass::TimerExpired(int number, Object^ data)
	{

	}

	void RenSharpGameFeatureEventClass::StartTimer(int number, TimeSpan duration, bool repeat, Object^ data)
	{
		RenSharpTimerManager::StartTimer(this, number, duration, repeat, data);
	}

	void RenSharpGameFeatureEventClass::StartTimer(int number, TimeSpan duration, bool repeat)
	{
		RenSharpTimerManager::StartTimer(this, number, duration, repeat);
	}

	void RenSharpGameFeatureEventClass::StartTimer(int number, TimeSpan duration)
	{
		RenSharpTimerManager::StartTimer(this, number, duration);
	}

	void RenSharpGameFeatureEventClass::StopTimer(int number, Object^ data)
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

	void RenSharpGameFeatureEventClass::StopTimer(int number)
	{
		RenSharpTimerManager::StopTimer(this, number);

		InternalDAEventClassPointer->Stop_Timer(number);
	}

	bool RenSharpGameFeatureEventClass::IsTimer(int number, Object^ data)
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

	bool RenSharpGameFeatureEventClass::IsTimer(int number)
	{
		if (RenSharpTimerManager::IsTimer(this, number))
		{
			return true;
		}

		return InternalDAEventClassPointer->Is_Timer(number);
	}

	void RenSharpGameFeatureEventClass::ClearTimers()
	{
		RenSharpTimerManager::ClearTimers(this);
		InternalDAEventClassPointer->Clear_Timers();
	}

	bool RenSharpGameFeatureEventClass::FilterChatCommand(IcPlayer^ player, String^ command, IDATokenClass^ text, TextMessageEnum chatType, Object^ data)
	{
		return true;
	}

	void RenSharpGameFeatureEventClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel, DAChatType chatType, Object^ data)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers, parameters, accessLevel, chatType, data);
	}

	void RenSharpGameFeatureEventClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel, DAChatType chatType)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers, parameters, accessLevel, chatType);
	}

	void RenSharpGameFeatureEventClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers, parameters, accessLevel);
	}

	void RenSharpGameFeatureEventClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, Object^ data)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers, parameters, data);
	}

	void RenSharpGameFeatureEventClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers, parameters);
	}

	void RenSharpGameFeatureEventClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers);
	}

	void RenSharpGameFeatureEventClass::UnregisterChatCommand(String^ trigger)
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

	void RenSharpGameFeatureEventClass::ClearChatCommands()
	{
		RenSharpChatCommandManager::ClearChatCommands(this, ChatCommandGroup::EventClass);
		InternalDAEventClassPointer->Clear_Chat_Commands();
	}

	bool RenSharpGameFeatureEventClass::FilterKeyHook(IcPlayer^ player, String^ key, Object^ data)
	{
		return true;
	}

	void RenSharpGameFeatureEventClass::RegisterKeyHook(RenSharpKHDelegate^ func, String^ triggers, Object^ data)
	{
		RenSharpKeyHookManager::RegisterKeyHook(this, KeyHookGroup::EventClass, func, triggers, data);
	}

	void RenSharpGameFeatureEventClass::RegisterKeyHook(RenSharpKHDelegate^ func, String^ triggers)
	{
		RenSharpKeyHookManager::RegisterKeyHook(this, KeyHookGroup::EventClass, func, triggers);
	}

	void RenSharpGameFeatureEventClass::UnregisterKeyHook(String^ trigger)
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

	void RenSharpGameFeatureEventClass::ClearKeyHooks()
	{
		RenSharpKeyHookManager::ClearKeyHooks(this, KeyHookGroup::EventClass);
		InternalDAEventClassPointer->Clear_Key_Hooks();
	}

	void RenSharpGameFeatureEventClass::RegisterEvent(DAEventType type, std::uint32_t priority)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daEventClass->RegisterEvent(type, priority);
	}

	void RenSharpGameFeatureEventClass::RegisterEvent(DAEventType type)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daEventClass->RegisterEvent(type);
	}

	void RenSharpGameFeatureEventClass::UnregisterEvent(DAEventType type)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daEventClass->UnregisterEvent(type);
	}

	void RenSharpGameFeatureEventClass::ClearEvents()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daEventClass->ClearEvents();
	}

	void RenSharpGameFeatureEventClass::RegisterObjectEvent(DAObjectEventType type, DAObjectEventObjectType objectType, std::uint32_t priority)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daEventClass->RegisterObjectEvent(type, objectType, priority);
	}

	void RenSharpGameFeatureEventClass::RegisterObjectEvent(DAObjectEventType type, DAObjectEventObjectType objectType)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daEventClass->RegisterObjectEvent(type, objectType);
	}

	void RenSharpGameFeatureEventClass::UnregisterObjectEvent(DAObjectEventType type)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daEventClass->UnregisterObjectEvent(type);
	}

	void RenSharpGameFeatureEventClass::ClearObjectEvents()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daEventClass->ClearObjectEvents();
	}

	IntPtr RenSharpGameFeatureEventClass::DAGameFeatureClassPointer::get()
	{
		return daGameFeatureClassPointer;
	}

	IntPtr RenSharpGameFeatureEventClass::DAEventClassPointer::get()
	{
		return daEventClassPointer;
	}

	IntPtr RenSharpGameFeatureEventClass::Pointer::get()
	{
		return renSharpGameFeatureEventClassPointer;
	}

	bool RenSharpGameFeatureEventClass::IsAttached::get()
	{
		return (renSharpGameFeatureEventClassPointer != IntPtr::Zero);
	}

	bool RenSharpGameFeatureEventClass::DestroyPointer::get()
	{
		return destroyPointer;
	}

	void RenSharpGameFeatureEventClass::DestroyPointer::set(bool value)
	{
		destroyPointer = value;
	}

	String^ RenSharpGameFeatureEventClass::Name::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daGameFeatureClass->Name;
	}

	IDAGameFeatureFactoryClass^ RenSharpGameFeatureEventClass::Factory::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daGameFeatureClass->Factory;
	}

	void RenSharpGameFeatureEventClass::Factory::set(IDAGameFeatureFactoryClass^ value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daGameFeatureClass->Factory = value;
	}

	Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ RenSharpGameFeatureEventClass::Timers::get()
	{
		return RenSharpTimerManager::GetTimers(this);
	}

	Collections::Generic::IEnumerable<RenSharpChatCommandStruct^>^ RenSharpGameFeatureEventClass::ChatCommands::get()
	{
		return RenSharpChatCommandManager::GetChatCommands(this, ChatCommandGroup::EventClass);
	}

	Collections::Generic::IEnumerable<RenSharpKeyHookStruct^>^ RenSharpGameFeatureEventClass::KeyHooks::get()
	{
		return RenSharpKeyHookManager::GetKeyHooks(this, KeyHookGroup::EventClass);
	}

	::DAGameFeatureClass* RenSharpGameFeatureEventClass::InternalDAGameFeatureClassPointer::get()
	{
		return reinterpret_cast<::DAGameFeatureClass*>(daGameFeatureClassPointer.ToPointer());
	}

	::DAEventClass* RenSharpGameFeatureEventClass::InternalDAEventClassPointer::get()
	{
		return reinterpret_cast<::DAEventClass*>(daEventClassPointer.ToPointer());
	}
}