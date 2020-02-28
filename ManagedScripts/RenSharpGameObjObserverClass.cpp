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
#include "RenSharpGameObjObserverClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_gameobj.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MScriptableGameObj.h"
#include "Imports.h"
#include "RenSharpTimerManager.h"

namespace RenSharp
{
	RenSharpGameObjObserverClass::RenSharpGameObjObserverClass(String ^name)
		: disposedResources(false), destroyPointer(true), daGameObjObserverClassPointer(IntPtr::Zero), daGameObjObserverClass(nullptr), name(name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}
	}

	String ^RenSharpGameObjObserverClass::ToString()
	{
		return name;
	}

	bool RenSharpGameObjObserverClass::Equals(Object ^other)
	{
		if (ReferenceEquals(other, nullptr))
		{
			return false;
		}

		IGameObjObserverClass^ otherThis1 = dynamic_cast<IGameObjObserverClass^>(other);
		if (otherThis1 != nullptr && daGameObjObserverClassPointer.Equals(otherThis1->GameObjObserverClassPointer))
		{
			return true;
		}

		IRenSharpGameObjObserverClass ^otherThis2 = dynamic_cast<IRenSharpGameObjObserverClass ^>(other);
		if (otherThis2 == nullptr)
		{
			return false;
		}

		return daGameObjObserverClassPointer.Equals(otherThis2->DAGameObjObserverClassPointer);
	}

	int RenSharpGameObjObserverClass::GetHashCode()
	{
		return daGameObjObserverClassPointer.GetHashCode();
	}

	RenSharpGameObjObserverClass::~RenSharpGameObjObserverClass()
	{
		if (disposedResources)
		{
			return;
		}

		ScriptableGameObj::UnregisterManagedObserver(this);

		ClearTimers();

		this->!RenSharpGameObjObserverClass();

		disposedResources = true;
	}

	RenSharpGameObjObserverClass::!RenSharpGameObjObserverClass()
	{
		if (IsAttached)
		{
			auto owner = InternalDAGameObjObserverClassPointer->Get_Owner();
			if (owner != nullptr)
			{
				auto observers = const_cast<::SimpleDynVecClass<::GameObjObserverClass*>*>(&owner->Get_Observers());

				observers->Delete(InternalDAGameObjObserverClassPointer);
			}

			if (destroyPointer)
			{
				IntPtr tmp = daGameObjObserverClassPointer;
				daGameObjObserverClassPointer = IntPtr::Zero;
				Imports::DestroyGameObjObserverClass(reinterpret_cast<::GameObjObserverClass*>(tmp.ToPointer()));
			}
		}

		ReleasePointer();
	}

	void RenSharpGameObjObserverClass::InitUnmanagedAttachable()
	{
		AttachToUnmanagedObject();
		RegisterManagedObject();
	}

	void RenSharpGameObjObserverClass::AttachToUnmanagedObject()
	{
		if (IsAttached)
		{
			throw gcnew NotSupportedException("Already attached.");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			auto newObserver = Imports::CreateRenSharpGameObjObserverClass(reinterpret_cast<char*>(nameHandle.ToPointer()));
			try
			{
				IntPtr newObserverPtr = IntPtr(newObserver);

				daGameObjObserverClassPointer = newObserverPtr;
			}
			catch (Exception^)
			{
				Imports::DestroyGameObjObserverClass(reinterpret_cast<::GameObjObserverClass*>(newObserver));

				throw;
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}

		daGameObjObserverClass = gcnew DAGameObjObserverClass(daGameObjObserverClassPointer);

		UnmanagedAttach();
	}

	void RenSharpGameObjObserverClass::RegisterManagedObject()
	{
		ScriptableGameObj::RegisterManagedObserver(this);

		ManagedRegistered();
	}

	void RenSharpGameObjObserverClass::ReleasePointer()
	{
		daGameObjObserverClassPointer = IntPtr::Zero;
		daGameObjObserverClass = nullptr;
	}

	void RenSharpGameObjObserverClass::UnmanagedAttach()
	{

	}

	void RenSharpGameObjObserverClass::ManagedRegistered()
	{

	}

	void RenSharpGameObjObserverClass::Init(IScriptableGameObj ^obj)
	{

	}

	void RenSharpGameObjObserverClass::Destroyed(IScriptableGameObj ^obj)
	{

	}

	void RenSharpGameObjObserverClass::Custom(IScriptableGameObj ^obj, int type, int param, IScriptableGameObj ^sender)
	{

	}

	void RenSharpGameObjObserverClass::SoundHeard(IScriptableGameObj ^obj, ICombatSound ^sound)
	{

	}

	void RenSharpGameObjObserverClass::EnemySeen(IScriptableGameObj ^obj, IScriptableGameObj ^enemy)
	{

	}

	void RenSharpGameObjObserverClass::ActionComplete(IScriptableGameObj ^obj, int actionId, ActionCompleteReason completeReason)
	{

	}

	void RenSharpGameObjObserverClass::AnimationComplete(IScriptableGameObj ^obj, String ^animationName)
	{

	}

	void RenSharpGameObjObserverClass::Poked(IScriptableGameObj ^obj, IScriptableGameObj ^poker)
	{

	}

	void RenSharpGameObjObserverClass::Entered(IScriptableGameObj ^obj, IScriptableGameObj ^enterer)
	{

	}

	void RenSharpGameObjObserverClass::Exited(IScriptableGameObj ^obj, IScriptableGameObj ^exiter)
	{

	}

	bool RenSharpGameObjObserverClass::VehicleEntryRequest(IScriptableGameObj ^obj, IcPlayer ^player, int %seat)
	{
		return true;
	}

	bool RenSharpGameObjObserverClass::VehicleEntryRequest(IScriptableGameObj ^obj, IVehicleGameObj ^vehicle, int %seat)
	{
		return true;
	}

	void RenSharpGameObjObserverClass::VehicleEnter(IScriptableGameObj ^obj, IcPlayer ^player, int seat)
	{

	}

	void RenSharpGameObjObserverClass::VehicleEnter(IScriptableGameObj ^obj, IVehicleGameObj ^vehicle, int seat)
	{

	}

	void RenSharpGameObjObserverClass::VehicleExit(IScriptableGameObj ^obj, IcPlayer ^player, int seat)
	{

	}

	void RenSharpGameObjObserverClass::VehicleExit(IScriptableGameObj ^obj, IVehicleGameObj ^vehicle, int seat)
	{

	}

	bool RenSharpGameObjObserverClass::VehicleFlip(IScriptableGameObj ^obj)
	{
		return true;
	}

	bool RenSharpGameObjObserverClass::DamageDealtRequest(IScriptableGameObj ^obj, IDamageableGameObj ^victim, float %damage, unsigned int %warhead, float scale, DADamageType type)
	{
		return true;
	}

	bool RenSharpGameObjObserverClass::DamageReceivedRequest(IScriptableGameObj ^obj, IArmedGameObj ^damager, float %damage, unsigned int %warhead, float scale, DADamageType type)
	{
		return true;
	}

	void RenSharpGameObjObserverClass::DamageDealt(IScriptableGameObj ^obj, IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type)
	{

	}

	void RenSharpGameObjObserverClass::DamageReceived(IScriptableGameObj ^obj, IArmedGameObj ^damager, float damage, unsigned int warhead, float scale, DADamageType type)
	{

	}

	void RenSharpGameObjObserverClass::KillDealt(IScriptableGameObj ^obj, IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type)
	{

	}

	void RenSharpGameObjObserverClass::KillReceived(IScriptableGameObj ^obj, IArmedGameObj ^killer, float damage, unsigned int warhead, float scale, DADamageType type)
	{

	}

	bool RenSharpGameObjObserverClass::PowerUpGrantRequest(IScriptableGameObj ^obj, IcPlayer ^player)
	{
		return true;
	}

	bool RenSharpGameObjObserverClass::PowerUpGrantRequest(IScriptableGameObj ^obj, IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj)
	{
		return true;
	}

	void RenSharpGameObjObserverClass::PowerUpGrant(IScriptableGameObj ^obj, IcPlayer ^player)
	{

	}

	void RenSharpGameObjObserverClass::PowerUpGrant(IScriptableGameObj ^obj, IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj)
	{

	}

	bool RenSharpGameObjObserverClass::AddWeaponRequest(IScriptableGameObj ^obj, IWeaponDefinitionClass ^weapon)
	{
		return true;
	}

	void RenSharpGameObjObserverClass::AddWeapon(IScriptableGameObj ^obj, IWeaponClass ^weapon)
	{

	}

	void RenSharpGameObjObserverClass::RemoveWeapon(IScriptableGameObj ^obj, IWeaponClass ^weapon)
	{

	}

	void RenSharpGameObjObserverClass::ClearWeapons(IScriptableGameObj ^obj)
	{

	}

	void RenSharpGameObjObserverClass::SetDeletePending()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daGameObjObserverClass->SetDeletePending();
	}

	IDAGameObjObserverClass ^RenSharpGameObjObserverClass::AsUnmanagedObject()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daGameObjObserverClass;
	}

	void RenSharpGameObjObserverClass::TimerExpired(int number, Object^ data)
	{

	}

	void RenSharpGameObjObserverClass::StartTimer(int number, TimeSpan duration, bool repeat, Object^ data)
	{
		RenSharpTimerManager::StartTimer(this, number, duration, repeat, data);
	}

	void RenSharpGameObjObserverClass::StartTimer(int number, TimeSpan duration, bool repeat)
	{
		RenSharpTimerManager::StartTimer(this, number, duration, repeat);
	}

	void RenSharpGameObjObserverClass::StartTimer(int number, TimeSpan duration)
	{
		RenSharpTimerManager::StartTimer(this, number, duration);
	}

	void RenSharpGameObjObserverClass::StopTimer(int number, Object^ data)
	{
		RenSharpTimerManager::StopTimer(this, number, data);

		InternalDAGameObjObserverClassPointer->Stop_Timer(number);
	}

	void RenSharpGameObjObserverClass::StopTimer(int number)
	{
		RenSharpTimerManager::StopTimer(this, number);

		InternalDAGameObjObserverClassPointer->Stop_Timer(number);
	}

	bool RenSharpGameObjObserverClass::IsTimer(int number, Object^ data)
	{
		return (RenSharpTimerManager::IsTimer(this, number, data) ||
			InternalDAGameObjObserverClassPointer->Is_Timer(number));
	}

	bool RenSharpGameObjObserverClass::IsTimer(int number)
	{
		return (RenSharpTimerManager::IsTimer(this, number) ||
			InternalDAGameObjObserverClassPointer->Is_Timer(number));
	}

	void RenSharpGameObjObserverClass::ClearTimers()
	{
		RenSharpTimerManager::ClearTimers(this);
	}

	Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ RenSharpGameObjObserverClass::Timers::get()
	{
		return RenSharpTimerManager::GetTimers(this);
	}

	IntPtr RenSharpGameObjObserverClass::DAGameObjObserverClassPointer::get()
	{
		return daGameObjObserverClassPointer;
	}

	IntPtr RenSharpGameObjObserverClass::Pointer::get()
	{
		return daGameObjObserverClassPointer;
	}

	bool RenSharpGameObjObserverClass::IsAttached::get()
	{
		return (daGameObjObserverClassPointer != IntPtr::Zero);
	}

	bool RenSharpGameObjObserverClass::IsRegistered::get()
	{
		return (IsAttached && ScriptableGameObj::IsManagedObserver(daGameObjObserverClassPointer));
	}

	String ^RenSharpGameObjObserverClass::Name::get()
	{
		return name;
	}

	int RenSharpGameObjObserverClass::ID::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daGameObjObserverClass->ID;
	}

	void RenSharpGameObjObserverClass::ID::set(int value)
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		daGameObjObserverClass->ID = value;
	}

	IScriptableGameObj ^RenSharpGameObjObserverClass::Owner::get()
	{
		if (!IsAttached)
		{
			throw gcnew NotSupportedException("Not attached.");
		}

		return daGameObjObserverClass->Owner;
	}

	bool RenSharpGameObjObserverClass::DestroyPointer::get()
	{
		return destroyPointer;
	}

	void RenSharpGameObjObserverClass::DestroyPointer::set(bool value)
	{
		destroyPointer = value;
	}

	::DAGameObjObserverClass *RenSharpGameObjObserverClass::InternalDAGameObjObserverClassPointer::get()
	{
		return reinterpret_cast<::DAGameObjObserverClass *>(daGameObjObserverClassPointer.ToPointer());
	}
}