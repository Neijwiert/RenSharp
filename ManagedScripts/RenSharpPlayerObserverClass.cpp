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
#include "RenSharpPlayerObserverClass.h"

#include "Imports.h"
#include "McPlayer.h"
#include "MSoldierGameObj.h"
#include "RenSharpChatCommandManager.h"
#include "RenSharpKeyHookManager.h"
#include "RenSharpTimerManager.h"

using namespace System::Text;

namespace RenSharp
{
	RenSharpPlayerObserverClass::RenSharpPlayerObserverClass(String ^name)
		:
		disposedResources(false),
		destroyPointer(true),
		daPlayerObserverClassPointer(IntPtr::Zero),
		daPlayerObserverClass(nullptr),
		name(name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}
	}

	RenSharpPlayerObserverClass::~RenSharpPlayerObserverClass()
	{
		if (disposedResources)
		{
			return;
		}

		DAPlayerClass::UnregisterManagedObserver(this);

		ClearTimers();
		ClearChatCommands();
		ClearKeyHooks();

		this->!RenSharpPlayerObserverClass();

		disposedResources = true;
	}

	RenSharpPlayerObserverClass::!RenSharpPlayerObserverClass()
	{
		if (IsAttached)
		{
			auto cPlayerOwner = InternalDAPlayerObserverClassPointer->Get_Owner();
			if (cPlayerOwner != nullptr)
			{
				auto daPlayerOwner = cPlayerOwner->Get_DA_Player();
				if (daPlayerOwner != nullptr)
				{
					auto observers = const_cast<::DynamicVectorClass<::DAPlayerObserverClass*>*>(&daPlayerOwner->Get_Observers());

					observers->DeleteObj(InternalDAPlayerObserverClassPointer);
				}
			}

			if (destroyPointer)
			{
				IntPtr tmp = daPlayerObserverClassPointer;
				daPlayerObserverClassPointer = IntPtr::Zero;
				Imports::DestroyDAPlayerObserverClass(reinterpret_cast<::DAPlayerObserverClass*>(tmp.ToPointer()));
			}
		}

		ReleasePointer();
	}

	String ^RenSharpPlayerObserverClass::ToString()
	{
		return name;
	}

	bool RenSharpPlayerObserverClass::Equals(Object ^other)
	{
		if (ReferenceEquals(other, nullptr))
		{
			return false;
		}

		IDAPlayerObserverClass^ otherThis1 = dynamic_cast<IDAPlayerObserverClass^>(other);
		if (otherThis1 != nullptr && daPlayerObserverClassPointer.Equals(otherThis1->DAPlayerObserverClassPointer))
		{
			return true;
		}

		IRenSharpPlayerObserverClass ^otherThis2 = dynamic_cast<IRenSharpPlayerObserverClass ^>(other);
		if (otherThis2 == nullptr)
		{
			return false;
		}

		return daPlayerObserverClassPointer.Equals(otherThis2->DAPlayerObserverClassPointer);
	}

	int RenSharpPlayerObserverClass::GetHashCode()
	{
		return daPlayerObserverClassPointer.GetHashCode();
	}

	void RenSharpPlayerObserverClass::AttachToUnmanagedObject()
	{
		if (IsAttached)
		{
			throw gcnew NotSupportedException("Already attached.");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			auto newObserver = Imports::CreateRenSharpPlayerObserverClass(reinterpret_cast<char*>(nameHandle.ToPointer()));
			try
			{
				IntPtr newObserverPtr = IntPtr(newObserver);

				daPlayerObserverClassPointer = newObserverPtr;
			}
			catch (Exception^)
			{
				Imports::DestroyDAPlayerObserverClass(reinterpret_cast<::DAPlayerObserverClass*>(newObserver));

				throw;
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}

		daPlayerObserverClass = gcnew DAPlayerObserverClass(daPlayerObserverClassPointer);

		UnmanagedAttach();
	}

	void RenSharpPlayerObserverClass::RegisterManagedObject()
	{
		DAPlayerClass::RegisterManagedObserver(this);

		ManagedRegistered();
	}

	void RenSharpPlayerObserverClass::ReleasePointer()
	{
		daPlayerObserverClassPointer = IntPtr::Zero;
		daPlayerObserverClass = nullptr;
	}

	void RenSharpPlayerObserverClass::UnmanagedAttach()
	{

	}

	void RenSharpPlayerObserverClass::ManagedRegistered()
	{

	}

	void RenSharpPlayerObserverClass::Init()
	{

	}

	void RenSharpPlayerObserverClass::Join()
	{

	}

	void RenSharpPlayerObserverClass::Leave()
	{

	}

	void RenSharpPlayerObserverClass::LevelLoaded()
	{

	}

	void RenSharpPlayerObserverClass::PlayerLoaded()
	{

	}

	void RenSharpPlayerObserverClass::NameChange()
	{

	}

	void RenSharpPlayerObserverClass::TeamChange()
	{

	}

	int RenSharpPlayerObserverClass::CharacterPurchaseRequest(float %cost, ISoldierGameObjDef ^item)
	{
		return -1;
	}

	int RenSharpPlayerObserverClass::VehiclePurchaseRequest(float %cost, IVehicleGameObjDef ^item)
	{
		return -1;
	}

	int RenSharpPlayerObserverClass::PowerUpPurchaseRequest(float %cost, IPowerUpGameObjDef ^item)
	{
		return -1;
	}

	int RenSharpPlayerObserverClass::CustomPurchaseRequest(float %cost, unsigned int id)
	{
		return -1;
	}

	void RenSharpPlayerObserverClass::CharacterPurchase(float cost, ISoldierGameObjDef ^item)
	{

	}

	void RenSharpPlayerObserverClass::VehiclePurchase(float cost, IVehicleGameObjDef ^item)
	{

	}

	void RenSharpPlayerObserverClass::PowerUpPurchase(float cost, IPowerUpGameObjDef ^item)
	{

	}

	void RenSharpPlayerObserverClass::CustomPurchase(float cost, unsigned int id)
	{

	}

	bool RenSharpPlayerObserverClass::VehicleEntryRequest(IVehicleGameObj ^vehicle, int %seat)
	{
		return true;
	}

	void RenSharpPlayerObserverClass::VehicleEnter(IVehicleGameObj ^vehicle, int seat)
	{

	}

	void RenSharpPlayerObserverClass::VehicleExit(IVehicleGameObj ^vehicle, int seat)
	{

	}

	bool RenSharpPlayerObserverClass::PowerUpGrantRequest(IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj)
	{
		return true;
	}

	void RenSharpPlayerObserverClass::PowerUpGrant(IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj)
	{

	}

	bool RenSharpPlayerObserverClass::AddWeaponRequest(IWeaponDefinitionClass ^weapon)
	{
		return true;
	}

	void RenSharpPlayerObserverClass::AddWeapon(IWeaponClass ^weapon)
	{

	}

	void RenSharpPlayerObserverClass::RemoveWeapon(IWeaponClass ^weapon)
	{

	}

	void RenSharpPlayerObserverClass::ClearWeapons()
	{

	}

	bool RenSharpPlayerObserverClass::C4DetonateRequest(IC4GameObj ^c4)
	{
		return true;
	}

	void RenSharpPlayerObserverClass::C4Detonate(IC4GameObj ^c4)
	{

	}

	void RenSharpPlayerObserverClass::ChangeCharacter(ISoldierGameObjDef ^soldier)
	{

	}

	void RenSharpPlayerObserverClass::Created()
	{

	}

	void RenSharpPlayerObserverClass::Destroyed()
	{

	}

	bool RenSharpPlayerObserverClass::DamageDealtRequest(IDamageableGameObj ^victim, float %damage, unsigned int %warhead, float scale, DADamageType type)
	{
		return true;
	}

	bool RenSharpPlayerObserverClass::DamageReceivedRequest(IArmedGameObj ^damager, float %damage, unsigned int %warhead, float scale, DADamageType type)
	{
		return true;
	}

	void RenSharpPlayerObserverClass::DamageDealt(IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type)
	{

	}

	void RenSharpPlayerObserverClass::DamageReceived(IArmedGameObj ^damager, float damage, unsigned int warhead, float scale, DADamageType type)
	{

	}

	void RenSharpPlayerObserverClass::KillDealt(IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type)
	{

	}

	void RenSharpPlayerObserverClass::KillReceived(IArmedGameObj ^killer, float damage, unsigned int warhead, float scale, DADamageType type)
	{

	}

	void RenSharpPlayerObserverClass::Custom(IScriptableGameObj ^sender, int type, int param)
	{

	}

	void RenSharpPlayerObserverClass::Poked(IcPlayer ^player)
	{

	}

	void RenSharpPlayerObserverClass::Think()
	{

	}

	void RenSharpPlayerObserverClass::TimerExpired(int number, Object^ data)
	{

	}

	void RenSharpPlayerObserverClass::StartTimer(int number, TimeSpan duration, bool repeat, Object^ data)
	{
		RenSharpTimerManager::StartTimer(this, number, duration, repeat, data);
	}

	void RenSharpPlayerObserverClass::StartTimer(int number, TimeSpan duration, bool repeat)
	{
		RenSharpTimerManager::StartTimer(this, number, duration, repeat);
	}

	void RenSharpPlayerObserverClass::StartTimer(int number, TimeSpan duration)
	{
		RenSharpTimerManager::StartTimer(this, number, duration);
	}

	void RenSharpPlayerObserverClass::StopTimer(int number, Object^ data)
	{
		RenSharpTimerManager::StopTimer(this, number, data);

		if (data == nullptr)
		{
			InternalDAPlayerObserverClassPointer->Stop_Timer(number, 0);
		}
		else if (UInt32::typeid->Equals(data->GetType()))
		{
			InternalDAPlayerObserverClassPointer->Stop_Timer(number, safe_cast<UInt32>(data));
		}
	}

	void RenSharpPlayerObserverClass::StopTimer(int number)
	{
		RenSharpTimerManager::StopTimer(this, number);

		InternalDAPlayerObserverClassPointer->Stop_Timer(number);
	}

	bool RenSharpPlayerObserverClass::IsTimer(int number, Object^ data)
	{
		if (RenSharpTimerManager::IsTimer(this, number, data))
		{
			return true;
		}
		else if (data == nullptr)
		{
			if (InternalDAPlayerObserverClassPointer->Is_Timer(number, 0))
			{
				return true;
			}
		}
		else if (UInt32::typeid->Equals(data->GetType()))
		{
			if (InternalDAPlayerObserverClassPointer->Is_Timer(number, safe_cast<UInt32>(data)))
			{
				return true;
			}
		}

		return false;
	}

	bool RenSharpPlayerObserverClass::IsTimer(int number)
	{
		return (RenSharpTimerManager::IsTimer(this, number) ||
			InternalDAPlayerObserverClassPointer->Is_Timer(number));
	}

	void RenSharpPlayerObserverClass::ClearTimers()
	{
		RenSharpTimerManager::ClearTimers(this);
		InternalDAPlayerObserverClassPointer->Clear_Timers();
	}

	bool RenSharpPlayerObserverClass::FilterChatCommand(IcPlayer^ player, String^ command, IDATokenClass^ text, TextMessageEnum chatType, Object^ data)
	{
		return Object::Equals(Owner, player);
	}

	void RenSharpPlayerObserverClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel, DAChatType chatType, Object^ data)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::PlayerObserver, func, triggers, parameters, accessLevel, chatType, data);
	}

	void RenSharpPlayerObserverClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel, DAChatType chatType)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::PlayerObserver, func, triggers, parameters, accessLevel, chatType);
	}

	void RenSharpPlayerObserverClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::PlayerObserver, func, triggers, parameters, accessLevel);
	}

	void RenSharpPlayerObserverClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, Object^ data)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::PlayerObserver, func, triggers, parameters, data);
	}

	void RenSharpPlayerObserverClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::PlayerObserver, func, triggers, parameters);
	}

	void RenSharpPlayerObserverClass::RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers)
	{
		RenSharpChatCommandManager::RegisterChatCommand(this, ChatCommandGroup::PlayerObserver, func, triggers);
	}

	void RenSharpPlayerObserverClass::UnregisterChatCommand(String^ trigger)
	{
		if (trigger == nullptr)
		{
			throw gcnew ArgumentNullException("trigger");
		}

		RenSharpChatCommandManager::UnregisterChatCommand(this, ChatCommandGroup::PlayerObserver, trigger);

		IntPtr triggerHandle = Marshal::StringToHGlobalAnsi(trigger);
		try
		{
			InternalDAPlayerObserverClassPointer->Unregister_Chat_Command(
				reinterpret_cast<char*>(triggerHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(triggerHandle);
		}
	}

	void RenSharpPlayerObserverClass::ClearChatCommands()
	{
		RenSharpChatCommandManager::ClearChatCommands(this, ChatCommandGroup::PlayerObserver);
		InternalDAPlayerObserverClassPointer->Clear_Chat_Commands();
	}

	bool RenSharpPlayerObserverClass::FilterKeyHook(IcPlayer^ player, String^ key, Object^ data)
	{
		return Object::Equals(Owner, player);
	}

	void RenSharpPlayerObserverClass::RegisterKeyHook(RenSharpKHDelegate^ func, String^ triggers, Object^ data)
	{
		RenSharpKeyHookManager::RegisterKeyHook(this, KeyHookGroup::PlayerObserver, func, triggers, data);
	}

	void RenSharpPlayerObserverClass::RegisterKeyHook(RenSharpKHDelegate^ func, String^ triggers)
	{
		RenSharpKeyHookManager::RegisterKeyHook(this, KeyHookGroup::PlayerObserver, func, triggers);
	}

	void RenSharpPlayerObserverClass::UnregisterKeyHook(String^ trigger)
	{
		if (trigger == nullptr)
		{
			throw gcnew ArgumentNullException("trigger");
		}

		RenSharpKeyHookManager::UnregisterKeyHook(this, KeyHookGroup::PlayerObserver, trigger);

		IntPtr triggerHandle = Marshal::StringToHGlobalAnsi(trigger);
		try
		{
			InternalDAPlayerObserverClassPointer->Unregister_Key_Hook(
				reinterpret_cast<char*>(triggerHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(triggerHandle);
		}
	}

	void RenSharpPlayerObserverClass::ClearKeyHooks()
	{
		RenSharpKeyHookManager::ClearKeyHooks(this, KeyHookGroup::PlayerObserver);
		InternalDAPlayerObserverClassPointer->Clear_Key_Hooks();
	}

	void RenSharpPlayerObserverClass::AddFlag(DAPlayerFlags flag)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daPlayerObserverClass->AddFlag(flag);
	}

	void RenSharpPlayerObserverClass::RemoveFlag(DAPlayerFlags flag)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daPlayerObserverClass->RemoveFlag(flag);
	}

	bool RenSharpPlayerObserverClass::HasFlag(DAPlayerFlags flag)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daPlayerObserverClass->HasFlag(flag);
	}

	void RenSharpPlayerObserverClass::SetDeletePending()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daPlayerObserverClass->SetDeletePending();
	}

	IDAPlayerObserverClass ^RenSharpPlayerObserverClass::AsUnmanagedObject()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daPlayerObserverClass;
	}

	Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ RenSharpPlayerObserverClass::Timers::get()
	{
		return RenSharpTimerManager::GetTimers(this);
	}

	Collections::Generic::IEnumerable<RenSharpChatCommandStruct^>^ RenSharpPlayerObserverClass::ChatCommands::get()
	{
		return RenSharpChatCommandManager::GetChatCommands(this, ChatCommandGroup::PlayerObserver);
	}

	Collections::Generic::IEnumerable<RenSharpKeyHookStruct^>^ RenSharpPlayerObserverClass::KeyHooks::get()
	{
		return RenSharpKeyHookManager::GetKeyHooks(this, KeyHookGroup::PlayerObserver);
	}

	bool RenSharpPlayerObserverClass::IsDeletePending::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daPlayerObserverClass->IsDeletePending;
	}

	String ^RenSharpPlayerObserverClass::ObserverName::get()
	{
		return name;
	}

	IntPtr RenSharpPlayerObserverClass::DAPlayerObserverClassPointer::get()
	{
		return daPlayerObserverClassPointer;
	}

	IntPtr RenSharpPlayerObserverClass::Pointer::get()
	{
		return daPlayerObserverClassPointer;
	}

	bool RenSharpPlayerObserverClass::IsAttached::get()
	{
		return (daPlayerObserverClassPointer != IntPtr::Zero);
	}

	IcPlayer ^RenSharpPlayerObserverClass::Owner::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daPlayerObserverClass->Owner;
	}

	void RenSharpPlayerObserverClass::Owner::set(IcPlayer ^value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}
		
		daPlayerObserverClass->Owner = value;
	}

	DAPlayerFlags RenSharpPlayerObserverClass::Flags::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daPlayerObserverClass->Flags;
	}

	void RenSharpPlayerObserverClass::Flags::set(DAPlayerFlags value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daPlayerObserverClass->Flags = value;
	}

	int RenSharpPlayerObserverClass::ID::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daPlayerObserverClass->ID;
	}

	String ^RenSharpPlayerObserverClass::Name::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daPlayerObserverClass->Name;
	}

	ISoldierGameObj ^RenSharpPlayerObserverClass::GameObj::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daPlayerObserverClass->GameObj;
	}

	int RenSharpPlayerObserverClass::Team::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daPlayerObserverClass->Team;
	}

	bool RenSharpPlayerObserverClass::DestroyPointer::get()
	{
		return destroyPointer;
	}

	void RenSharpPlayerObserverClass::DestroyPointer::set(bool value)
	{
		destroyPointer = value;
	}

	::DAPlayerObserverClass *RenSharpPlayerObserverClass::InternalDAPlayerObserverClassPointer::get()
	{
		return reinterpret_cast<::DAPlayerObserverClass *>(daPlayerObserverClassPointer.ToPointer());
	}
}