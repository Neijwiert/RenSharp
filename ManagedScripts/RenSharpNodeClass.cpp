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
#include "RenSharpNodeClass.h"

#include "Mengine_io.h"
#include "Mda_nodemanager.h"
#include "MPhysicalGameObj.h"
#include "Imports.h"
#include "RenSharpTimerManager.h"
#include "RenSharpChatCommandManager.h"
#include "RenSharpKeyHookManager.h"
#include "MSoldierGameObj.h"

using namespace System;

namespace RenSharp
{
	RenSharpNodeClass::RenSharpNodeClass(String^ type)
		: disposedResources(false), destroyPointer(true), daBaseNodeClassPointer(IntPtr::Zero), daBaseNodeClass(nullptr), type(type)
	{
		if (type == nullptr)
		{
			throw gcnew ArgumentNullException("type");
		}
	}

	RenSharpNodeClass::~RenSharpNodeClass()
	{
		if (disposedResources)
		{
			return;
		}

		DAEventManager::UnregisterManagedEventClass(this);
		DANodeManagerClass::UnregisterManagedNode(this);

		ClearTimers();
		ClearChatCommands();
		ClearKeyHooks();

		this->!RenSharpNodeClass();

		disposedResources = true;
	}

	RenSharpNodeClass::!RenSharpNodeClass()
	{
		if (IsAttached)
		{
			auto nodeManager = ::DANodeManagerClass::Get_Instance();
			if (nodeManager != nullptr)
			{
				auto& nodes = (*nodeManager).*get(DANodeManagerClassNodes());

				nodes.DeleteObj(InternalDABaseNodeClassPointer);
			}

			if (destroyPointer)
			{
				IntPtr tmp = DAEventClassPointer;
				Imports::DestroyDAEventClass(reinterpret_cast<::DAEventClass*>(tmp.ToPointer()));
			}
		}

		ReleasePointer();
	}

	String^ RenSharpNodeClass::ToString()
	{
		return type;
	}

	bool RenSharpNodeClass::Equals(System::Object^ other)
	{
		if (ReferenceEquals(other, nullptr))
		{
			return false;
		}

		IDAEventClass^ otherThis1 = dynamic_cast<IDAEventClass^>(other);
		if (otherThis1 != nullptr && DAEventClassPointer.Equals(otherThis1->DAEventClassPointer))
		{
			return true;
		}

		IDABaseNodeClass^ otherThis2 = dynamic_cast<IDABaseNodeClass^>(other);
		if (otherThis2 != nullptr && DABaseNodeClassPointer.Equals(otherThis2->DABaseNodeClassPointer))
		{
			return true;
		}

		IRenSharpNodeClass^ otherThis3 = dynamic_cast<IRenSharpNodeClass^>(other);
		if (otherThis3 != nullptr && daBaseNodeClassPointer.Equals(otherThis3->DABaseNodeClassPointer))
		{
			return true;
		}

		IRenSharpEventClass^ otherThis4 = dynamic_cast<IRenSharpEventClass^>(other);
		if (otherThis4 == nullptr)
		{
			return false;
		}

		return DAEventClassPointer.Equals(otherThis4->DAEventClassPointer);
	}

	int RenSharpNodeClass::GetHashCode()
	{
		return daBaseNodeClassPointer.GetHashCode();
	}

	void RenSharpNodeClass::AttachToUnmanagedObject()
	{
		if (IsAttached)
		{
			throw gcnew NotSupportedException("Already attached.");
		}

		try
		{
			::RenSharpNodeClass* renSharpNodeClassPtr = nullptr;

			IntPtr typeHandle = Marshal::StringToHGlobalAnsi(type);
			try
			{
				renSharpNodeClassPtr = Imports::CreateRenSharpNodeClass(
					reinterpret_cast<char*>(typeHandle.ToPointer()));
			}
			finally
			{
				 Marshal::FreeHGlobal(typeHandle);
			}

			daBaseNodeClassPointer = IntPtr(renSharpNodeClassPtr);
		}
		catch (Exception^)
		{
			if (DAEventClassPointer.ToPointer() != nullptr)
			{
				Imports::DestroyDAEventClass(reinterpret_cast<::DAEventClass*>(DAEventClassPointer.ToPointer()));
			}

			throw;
		}

		daBaseNodeClass = gcnew DABaseNodeClass(daBaseNodeClassPointer);

		UnmanagedAttach();
	}

	void RenSharpNodeClass::RegisterManagedObject()
	{
		DAEventManager::RegisterManagedEventClass(this);
		DANodeManagerClass::RegisterManagedNode(this);

		ManagedRegistered();
	}

	void RenSharpNodeClass::ReleasePointer()
	{
		daBaseNodeClassPointer = IntPtr::Zero;
		daBaseNodeClass = nullptr;
	}

	void RenSharpNodeClass::UnmanagedAttach()
	{

	}

	void RenSharpNodeClass::ManagedRegistered()
	{

	}

	IDABaseNodeClass^ RenSharpNodeClass::AsUnmanagedNode()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daBaseNodeClass;
	}

	IDAEventClass^ RenSharpNodeClass::AsUnmanagedEventClass()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daBaseNodeClass;
	}

	void RenSharpNodeClass::SettingsLoadedEvent()
	{

	}

	bool RenSharpNodeClass::ChatEvent(IcPlayer^ player, TextMessageEnum type, String^ message, int receiverID)
	{
		return true;
	}

	bool RenSharpNodeClass::ChatCommandEvent(IcPlayer^ player, TextMessageEnum type, String^ command, IDATokenClass^ text, int receiverID)
	{
		return true;
	}

	bool RenSharpNodeClass::KeyHookEvent(IcPlayer^ player, String^ key)
	{
		return true;
	}

	bool RenSharpNodeClass::HostChatEvent(int id, TextMessageEnum type, String^ message)
	{
		return true;
	}

	bool RenSharpNodeClass::RadioEvent(IcPlayer^ player, int playerType, int announcementID, int iconID, AnnouncementEnum announcementType)
	{
		return true;
	}

	ConnectionAcceptanceFilterStatus RenSharpNodeClass::ConnectionRequestEvent(IConnectionRequest^ request, String^% refusalMessage)
	{
		return ConnectionAcceptanceFilterStatus::StatusAccepting;
	}

	void RenSharpNodeClass::PlayerPreJoinEvent(IConnectionRequest^ request)
	{

	}

	void RenSharpNodeClass::PlayerJoinEvent(IcPlayer^ player)
	{

	}

	void RenSharpNodeClass::PlayerLeaveEvent(IcPlayer^ player)
	{

	}

	void RenSharpNodeClass::PlayerLoadedEvent(IcPlayer^ player)
	{

	}

	void RenSharpNodeClass::NameChangeEvent(IcPlayer^ player)
	{

	}

	void RenSharpNodeClass::LevelLoadedEvent()
	{

	}

	void RenSharpNodeClass::RemixEvent()
	{

	}

	void RenSharpNodeClass::RebalanceEvent()
	{

	}

	void RenSharpNodeClass::SwapEvent()
	{

	}

	void RenSharpNodeClass::GameOverEvent()
	{

	}

	void RenSharpNodeClass::ConsoleOutputEvent(String^ output)
	{

	}

	void RenSharpNodeClass::RenLogEvent(String^ output)
	{

	}

	void RenSharpNodeClass::DALogEvent(String^ header, String^ output)
	{

	}

	int RenSharpNodeClass::CharacterPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, ISoldierGameObjDef^ item)
	{
		return -1;
	}

	int RenSharpNodeClass::VehiclePurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, IVehicleGameObjDef^ item)
	{
		return -1;
	}

	int RenSharpNodeClass::PowerUpPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, IPowerUpGameObjDef^ item)
	{
		return -1;
	}

	int RenSharpNodeClass::CustomPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, unsigned int id)
	{
		return -1;
	}

	void RenSharpNodeClass::CharacterPurchaseEvent(IcPlayer^ player, float cost, ISoldierGameObjDef^ item)
	{

	}

	void RenSharpNodeClass::VehiclePurchaseEvent(IcPlayer^ player, float cost, IVehicleGameObjDef^ item)
	{

	}

	void RenSharpNodeClass::PowerUpPurchaseEvent(IcPlayer^ player, float cost, IPowerUpGameObjDef^ item)
	{

	}

	void RenSharpNodeClass::CustomPurchaseEvent(IcPlayer^ player, float cost, unsigned int id)
	{

	}

	bool RenSharpNodeClass::RefillEvent(IcPlayer^ player)
	{
		return true;
	}

	bool RenSharpNodeClass::SuicideEvent(IcPlayer^ player)
	{
		return true;
	}

	bool RenSharpNodeClass::TeamChangeRequestEvent(IcPlayer^ player)
	{
		return true;
	}

	void RenSharpNodeClass::TeamChangeEvent(IcPlayer^ player)
	{

	}

	bool RenSharpNodeClass::VehicleEntryRequestEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int% seat)
	{
		return true;
	}

	void RenSharpNodeClass::VehicleEnterEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int seat)
	{

	}

	void RenSharpNodeClass::VehicleExitEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int seat)
	{

	}

	bool RenSharpNodeClass::PowerUpGrantRequestEvent(IcPlayer^ player, IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj)
	{
		return true;
	}

	void RenSharpNodeClass::PowerUpGrantEvent(IcPlayer^ player, IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj)
	{

	}

	bool RenSharpNodeClass::AddWeaponRequestEvent(IcPlayer^ player, IWeaponDefinitionClass^ weapon)
	{
		return true;
	}

	void RenSharpNodeClass::AddWeaponEvent(IcPlayer^ player, IWeaponClass^ weapon)
	{

	}

	void RenSharpNodeClass::RemoveWeaponEvent(IcPlayer^ player, IWeaponClass^ weapon)
	{

	}

	void RenSharpNodeClass::ClearWeaponsEvent(IcPlayer^ player)
	{

	}

	void RenSharpNodeClass::BeaconDeployEvent(IBeaconGameObj^ beacon)
	{

	}

	void RenSharpNodeClass::BeaconDetonateEvent(IBeaconGameObj^ beacon)
	{

	}

	bool RenSharpNodeClass::C4DetonateRequestEvent(IC4GameObj^ c4, ISmartGameObj^ triggerer)
	{
		return true;
	}

	void RenSharpNodeClass::C4DetonateEvent(IC4GameObj^ c4)
	{

	}

	void RenSharpNodeClass::ChangeCharacterEvent(IcPlayer^ player, ISoldierGameObjDef^ soldier)
	{

	}

	bool RenSharpNodeClass::VehicleFlipEvent(IVehicleGameObj^ vehicle)
	{
		return true;
	}

	bool RenSharpNodeClass::RequestVehicleEvent(IVehicleFactoryGameObj^ factory, IVehicleGameObjDef^ vehicle, IcPlayer^ player, float delay)
	{
		return true;
	}

	void RenSharpNodeClass::Think()
	{

	}

	void RenSharpNodeClass::ObjectCreatedEvent(IScriptableGameObj^ obj)
	{

	}

	bool RenSharpNodeClass::StockClientDamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float damage, uint warhead)
	{
		return true;
	}

	bool RenSharpNodeClass::TTClientDamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, IAmmoDefinitionClass^ ammo, String^ bone)
	{
		return true;
	}

	bool RenSharpNodeClass::DamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float% damage, unsigned int% warhead, float scale, DADamageType type)
	{
		return true;
	}

	void RenSharpNodeClass::DamageEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float damage, unsigned int warhead, float scale, DADamageType type)
	{

	}

	void RenSharpNodeClass::KillEvent(IDamageableGameObj^ victim, IArmedGameObj^ killer, float damage, unsigned int warhead, float scale, DADamageType type)
	{

	}

	void RenSharpNodeClass::CustomEvent(IScriptableGameObj^ obj, int type, int param, IScriptableGameObj^ sender)
	{

	}

	void RenSharpNodeClass::PokeEvent(IcPlayer^ player, IPhysicalGameObj^ obj)
	{

	}

	void RenSharpNodeClass::ZoneEnterEvent(IScriptZoneGameObj^ obj, IPhysicalGameObj^ enterer)
	{

	}

	void RenSharpNodeClass::ZoneExitEvent(IScriptZoneGameObj^ obj, IPhysicalGameObj^ exiter)
	{

	}

	void RenSharpNodeClass::ObjectDestroyedEvent(IScriptableGameObj^ obj)
	{

	}

	void RenSharpNodeClass::TimerExpired(int number, System::Object^ data)
	{

	}

	void RenSharpNodeClass::StartTimer(int number, TimeSpan duration, bool repeat, System::Object^ data)
	{
		RenSharpTimerManager::StartTimer(this, number, duration, repeat, data);
	}

	void RenSharpNodeClass::StartTimer(int number, TimeSpan duration, bool repeat)
	{
		RenSharpTimerManager::StartTimer(this, number, duration, repeat);
	}

	void RenSharpNodeClass::StartTimer(int number, TimeSpan duration)
	{
		RenSharpTimerManager::StartTimer(this, number, duration);
	}

	void RenSharpNodeClass::StopTimer(int number, System::Object^ data)
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

	void RenSharpNodeClass::StopTimer(int number)
	{
		RenSharpTimerManager::StopTimer(this, number);

		InternalDAEventClassPointer->Stop_Timer(number);
	}

	bool RenSharpNodeClass::IsTimer(int number, System::Object^ data)
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

	bool RenSharpNodeClass::IsTimer(int number)
	{
		if (RenSharpTimerManager::IsTimer(this, number))
		{
			return true;
		}

		return InternalDAEventClassPointer->Is_Timer(number);
	}

	void RenSharpNodeClass::ClearTimers()
	{
		RenSharpTimerManager::ClearTimers(this);
		InternalDAEventClassPointer->Clear_Timers();
	}

	bool RenSharpNodeClass::FilterChatCommand(IcPlayer^ player, String^ command, IDATokenClass^ text, TextMessageEnum chatType, System::Object^ data)
	{
		return true;
	}

	void RenSharpNodeClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel, DAChatType chatType, System::Object^ data)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers, parameters, accessLevel, chatType, data);
	}

	void RenSharpNodeClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel, DAChatType chatType)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers, parameters, accessLevel, chatType);
	}

	void RenSharpNodeClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers, parameters, accessLevel);
	}

	void RenSharpNodeClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, System::Object^ data)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers, parameters, data);
	}

	void RenSharpNodeClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers, parameters);
	}

	void RenSharpNodeClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::EventClass, func, triggers);
	}

	void RenSharpNodeClass::UnregisterChatCommand(String^ trigger)
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

	void RenSharpNodeClass::ClearChatCommands()
	{
		RenSharpChatCommandManager::ClearChatCommands(this, ChatCommandGroup::EventClass);
		InternalDAEventClassPointer->Clear_Chat_Commands();
	}

	bool RenSharpNodeClass::FilterKeyHook(IcPlayer^ player, String^ key, System::Object^ data)
	{
		return true;
	}

	void RenSharpNodeClass::RegisterKeyHook(RenSharpKHDelegate^ func, String^ triggers, System::Object^ data)
	{
		RenSharpKeyHookManager::RegisterKeyHook(this, KeyHookGroup::EventClass, func, triggers, data);
	}

	void RenSharpNodeClass::RegisterKeyHook(RenSharpKHDelegate^ func, String^ triggers)
	{
		RenSharpKeyHookManager::RegisterKeyHook(this, KeyHookGroup::EventClass, func, triggers);
	}

	void RenSharpNodeClass::UnregisterKeyHook(String^ trigger)
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

	void RenSharpNodeClass::ClearKeyHooks()
	{
		RenSharpKeyHookManager::ClearKeyHooks(this, KeyHookGroup::EventClass);
		InternalDAEventClassPointer->Clear_Key_Hooks();
	}

	void RenSharpNodeClass::RegisterEvent(DAEventType type, std::uint32_t priority)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daBaseNodeClass->RegisterEvent(type, priority);
	}

	void RenSharpNodeClass::RegisterEvent(DAEventType type)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daBaseNodeClass->RegisterEvent(type);
	}

	void RenSharpNodeClass::UnregisterEvent(DAEventType type)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daBaseNodeClass->UnregisterEvent(type);
	}

	void RenSharpNodeClass::ClearEvents()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daBaseNodeClass->ClearEvents();
	}

	void RenSharpNodeClass::RegisterObjectEvent(DAObjectEventType type, DAObjectEventObjectType objectType, std::uint32_t priority)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daBaseNodeClass->RegisterObjectEvent(type, objectType, priority);
	}

	void RenSharpNodeClass::RegisterObjectEvent(DAObjectEventType type, DAObjectEventObjectType objectType)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daBaseNodeClass->RegisterObjectEvent(type, objectType);
	}

	void RenSharpNodeClass::UnregisterObjectEvent(DAObjectEventType type)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daBaseNodeClass->UnregisterObjectEvent(type);
	}

	void RenSharpNodeClass::ClearObjectEvents()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daBaseNodeClass->ClearObjectEvents();
	}

	void RenSharpNodeClass::Init(IINIClass^ ini, String^ header)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}
		else if (ini == nullptr || ini->INIClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("ini");
		}
		else if (header == nullptr)
		{
			throw gcnew ArgumentNullException("header");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		IntPtr headerHandle = Marshal::StringToHGlobalAnsi(header);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(headerHandle.ToPointer()));

			helper->_Init(
				reinterpret_cast<::INIClass*>(ini->INIClassPointer.ToPointer()),
				tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(headerHandle);
		}
	}

	void RenSharpNodeClass::ContestedEvent()
	{

	}

	void RenSharpNodeClass::CaptureEvent()
	{

	}

	void RenSharpNodeClass::SetContested(bool value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daBaseNodeClass->SetContested(value);
	}

	IntPtr RenSharpNodeClass::DABaseNodeClassPointer::get()
	{
		return daBaseNodeClassPointer;
	}

	IntPtr RenSharpNodeClass::DAEventClassPointer::get()
	{
		return IntPtr(InternalDAEventClassPointer);
	}

	IntPtr RenSharpNodeClass::Pointer::get()
	{
		return daBaseNodeClassPointer;
	}

	bool RenSharpNodeClass::IsAttached::get()
	{
		return (daBaseNodeClassPointer != IntPtr::Zero);
	}

	bool RenSharpNodeClass::DestroyPointer::get()
	{
		return destroyPointer;
	}

	void RenSharpNodeClass::DestroyPointer::set(bool value)
	{
		destroyPointer = value;
	}

	Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ RenSharpNodeClass::Timers::get()
	{
		return RenSharpTimerManager::GetTimers(this);
	}

	Collections::Generic::IEnumerable<RenSharpChatCommandStruct^>^ RenSharpNodeClass::ChatCommands::get()
	{
		return RenSharpChatCommandManager::GetChatCommands(this, ChatCommandGroup::EventClass);
	}

	Collections::Generic::IEnumerable<RenSharpKeyHookStruct^>^ RenSharpNodeClass::KeyHooks::get()
	{
		return RenSharpKeyHookManager::GetKeyHooks(this, KeyHookGroup::EventClass);
	}

	Vector3 RenSharpNodeClass::Position::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daBaseNodeClass->Position;
	}

	void RenSharpNodeClass::Position::set(Vector3 value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& position = helper->GetPosition();

		Vector3::ManagedToUnmanagedVector3(value, position);
	}

	String^ RenSharpNodeClass::ObjectPreset::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daBaseNodeClass->ObjectPreset;
	}

	String^ RenSharpNodeClass::ObjectModel::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daBaseNodeClass->ObjectModel;
	}

	int RenSharpNodeClass::Team::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daBaseNodeClass->Team;
	}

	void RenSharpNodeClass::Team::set(int value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& team = helper->GetTeam();

		team = value;
	}

	String^ RenSharpNodeClass::Group::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daBaseNodeClass->Group;
	}

	void RenSharpNodeClass::Group::set(String^ value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}
		else if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& group = helper->GetGroup();

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			group = reinterpret_cast<char*>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	String^ RenSharpNodeClass::Name::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daBaseNodeClass->Name;
	}

	void RenSharpNodeClass::Name::set(String^ value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}
		else if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& name = helper->GetName();

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			name = reinterpret_cast<char*>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	bool RenSharpNodeClass::IsContested::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daBaseNodeClass->IsContested;
	}

	void RenSharpNodeClass::IsContested::set(bool value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& isContested = helper->GetIsContested();

		isContested = value;
	}

	bool RenSharpNodeClass::IsCapturable::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daBaseNodeClass->IsCapturable;
	}

	void RenSharpNodeClass::IsCapturable::set(bool value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daBaseNodeClass->IsCapturable = value;
	}

	bool RenSharpNodeClass::IsCaptureOnce::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daBaseNodeClass->IsCaptureOnce;
	}

	void RenSharpNodeClass::IsCaptureOnce::set(bool value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daBaseNodeClass->IsCaptureOnce = value;
	}

	String^ RenSharpNodeClass::Type::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daBaseNodeClass->Type;
	}

	void RenSharpNodeClass::Captured(int captureTeam)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		helper->Captured(captureTeam);
	}

	void RenSharpNodeClass::AttackTick(int attackTeam)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		helper->AttackTick(attackTeam);
	}

	void RenSharpNodeClass::DefendTick()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		helper->DefendTick();
	}

	void RenSharpNodeClass::UpdateIconAndRadar()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		helper->UpdateIconAndRadar();
	}

	bool RenSharpNodeClass::IsPlayerInRange(ISoldierGameObj^ player)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}
		else if (player == nullptr || player->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		return helper->IsPlayerInRange(
			reinterpret_cast<::SoldierGameObj*>(player->SoldierGameObjPointer.ToPointer()));
	}

	void RenSharpNodeClass::GiveAttackDefendTickPoints(int team)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		helper->GiveAttackDefendTickPoints(team);
	}

	void RenSharpNodeClass::GiveCapturePoints()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		helper->GiveCapturePoints();
	}

	::DAEventClass* RenSharpNodeClass::InternalDAEventClassPointer::get()
	{
		return InternalDABaseNodeClassPointer;
	}

	::DABaseNodeClass* RenSharpNodeClass::InternalDABaseNodeClassPointer::get()
	{
		return reinterpret_cast<::DABaseNodeClass*>(daBaseNodeClassPointer.ToPointer());
	}

	IPhysicalGameObj^ RenSharpNodeClass::Object::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& object = helper->GetObject();

		if (object == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PhysicalGameObj(IntPtr(object));
		}
	}

	void RenSharpNodeClass::Object::set(IPhysicalGameObj^ value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& object = helper->GetObject();

		if (value == nullptr || value->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			object = nullptr;
		}
		else
		{
			object = reinterpret_cast<::PhysicalGameObj*>(value->PhysicalGameObjPointer.ToPointer());
		}
	}

	IPhysicalGameObj^ RenSharpNodeClass::Icon::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& icon = helper->GetIcon();

		if (icon == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PhysicalGameObj(IntPtr(icon));
		}
	}

	void RenSharpNodeClass::Icon::set(IPhysicalGameObj^ value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& icon = helper->GetIcon();

		if (value == nullptr || value->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			icon = nullptr;
		}
		else
		{
			icon = reinterpret_cast<::PhysicalGameObj*>(value->PhysicalGameObjPointer.ToPointer());
		}
	}

	array<IPhysicalGameObj^>^ RenSharpNodeClass::Radar::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		::PhysicalGameObj* tmp[DABaseNodeClassHelper::RadarSizeCount];
		helper->GetRadar(tmp);

		array<IPhysicalGameObj^>^ result = gcnew array<IPhysicalGameObj^>(DABaseNodeClassHelper::RadarSizeCount);
		for (int x = 0; x < result->Length; x++)
		{
			auto currentRadar = tmp[x];
			if (currentRadar == nullptr)
			{
				result[x] = nullptr;
			}
			else
			{
				result[x] = gcnew PhysicalGameObj(IntPtr(currentRadar));
			}
		}

		return result;
	}

	void RenSharpNodeClass::Radar::set(array<IPhysicalGameObj^>^ value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}
		else if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}
		else if (value->Length != static_cast<int>(DABaseNodeClassHelper::RadarSizeCount))
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		for (int x = 0; x < value->Length; x++)
		{
			auto currentRadar = value[x];
			if (currentRadar == nullptr || currentRadar->PhysicalGameObjPointer.ToPointer() == nullptr)
			{
				helper->SetRadar(
					static_cast<std::size_t>(x),
					nullptr);
			}
			else
			{
				helper->SetRadar(
					static_cast<std::size_t>(x),
					reinterpret_cast<::PhysicalGameObj*>(currentRadar->PhysicalGameObjPointer.ToPointer()));
			}
		}
	}

	bool RenSharpNodeClass::SentAttackMessage::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& sentAttackMessage = helper->GetSentAttackMessage();

		return sentAttackMessage;
	}

	void RenSharpNodeClass::SentAttackMessage::set(bool value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& sentAttackMessage = helper->GetSentAttackMessage();

		sentAttackMessage = value;
	}

	array<bool>^ RenSharpNodeClass::SentDefendMessage::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		array<bool>^ result = gcnew array<bool>(DABaseNodeClassHelper::SentDefendMessageSizeCount);

		pin_ptr<bool> pinnedResult = &result[0];
		bool* resultPtr = pinnedResult;

		helper->GetSentDefendMessage(resultPtr);

		return result;
	}

	void RenSharpNodeClass::SentDefendMessage::set(array<bool>^ value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}
		else if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}
		else if (value->Length != static_cast<int>(DABaseNodeClassHelper::SentDefendMessageSizeCount))
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		pin_ptr<bool> pinnedValue = &value[0];
		bool* valuePtr = pinnedValue;

		helper->SetSentDefendMessage(valuePtr);
	}

	unsigned long RenSharpNodeClass::LastAttackMessage::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& lastAttackMessage = helper->GetLastAttackMessage();

		return lastAttackMessage;
	}

	void RenSharpNodeClass::LastAttackMessage::set(unsigned long value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& lastAttackMessage = helper->GetLastAttackMessage();

		lastAttackMessage = value;
	}

	unsigned long RenSharpNodeClass::LastAttackTick::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& lastAttackTick = helper->GetLastAttackTick();

		return lastAttackTick;
	}

	void RenSharpNodeClass::LastAttackTick::set(unsigned long value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& lastAttackTick = helper->GetLastAttackTick();

		lastAttackTick = value;
	}

	unsigned long RenSharpNodeClass::LastDefendTick::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& lastDefendTick = helper->GetLastDefendTick();

		return lastDefendTick;
	}

	void RenSharpNodeClass::LastDefendTick::set(unsigned long value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& lastDefendTick = helper->GetLastDefendTick();

		lastDefendTick = value;
	}

	array<int>^ RenSharpNodeClass::PlayerCheck::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		array<int>^ result = gcnew array<int>(DABaseNodeClassHelper::PlayerCheckSizeCount);

		pin_ptr<int> pinnedResult = &result[0];
		int* resultPtr = pinnedResult;

		helper->GetPlayerCheck(resultPtr);

		return result;
	}

	void RenSharpNodeClass::PlayerCheck::set(array<int>^ value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}
		else if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}
		else if (value->Length != static_cast<int>(DABaseNodeClassHelper::PlayerCheckSizeCount))
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		pin_ptr<int> pinnedValue = &value[0];
		int* valuePtr = pinnedValue;

		helper->SetPlayerCheck(valuePtr);
	}

	int RenSharpNodeClass::LastAttackTeam::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& lastAttackTeam = helper->GetLastAttackTeam();

		return lastAttackTeam;
	}

	void RenSharpNodeClass::LastAttackTeam::set(int value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& lastAttackTeam = helper->GetLastAttackTeam();

		lastAttackTeam = value;
	}

	String^ RenSharpNodeClass::Preset::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& preset = helper->GetPreset();

		return gcnew String(preset.Peek_Buffer());
	}

	void RenSharpNodeClass::Preset::set(String^ value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}
		else if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& preset = helper->GetPreset();

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			preset = reinterpret_cast<char*>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	String^ RenSharpNodeClass::Model::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& model = helper->GetModel();

		return gcnew String(model.Peek_Buffer());
	}

	void RenSharpNodeClass::Model::set(String^ value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}
		else if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& model = helper->GetModel();

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			model = reinterpret_cast<char*>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	String^ RenSharpNodeClass::Animation::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& animation = helper->GetAnimation();

		return gcnew String(animation.Peek_Buffer());
	}

	void RenSharpNodeClass::Animation::set(String^ value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}
		else if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& animation = helper->GetAnimation();

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			animation = reinterpret_cast<char*>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	float RenSharpNodeClass::AttackDefendDistance::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& attackDefendDistance = helper->GetAttackDefendDistance();

		return attackDefendDistance;
	}

	void RenSharpNodeClass::AttackDefendDistance::set(float value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& attackDefendDistance = helper->GetAttackDefendDistance();

		attackDefendDistance = value;
	}

	bool RenSharpNodeClass::IgnoreLOS::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& ignoreLOS = helper->GetIgnoreLOS();

		return ignoreLOS;
	}

	void RenSharpNodeClass::IgnoreLOS::set(bool value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& ignoreLOS = helper->GetIgnoreLOS();

		ignoreLOS = value;
	}
}