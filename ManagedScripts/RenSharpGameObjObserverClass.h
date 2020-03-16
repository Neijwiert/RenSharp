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

#include "Mda_event.h"
#include "Mscripts.h"
#include "ITimerInterface.h"
#include "IUnmanagedAttachable.h"
#include "Mda_gameobj.h"

#pragma managed(push, off)

class DAGameObjObserverClass;

#pragma managed(pop)

using namespace System;

namespace RenSharp
{
	interface class IcPlayer;
	interface class IVehicleGameObj;
	interface class IDamageableGameObj;
	interface class IArmedGameObj;
	interface class IPowerUpGameObjDef;
	interface class IPowerUpGameObj;
	interface class IWeaponDefinitionClass;
	interface class IWeaponClass;
	interface class IScriptableGameObj;
	interface class ICombatSound;

	public interface class IRenSharpGameObjObserverClass : public ITimerInterface, public IUnmanagedAttachable<IDAGameObjObserverClass^>
	{
		void Init(IScriptableGameObj^ obj);

		void Destroyed(IScriptableGameObj^ obj);

		void Custom(IScriptableGameObj^ obj, int type, int param, IScriptableGameObj^ sender);

		void SoundHeard(IScriptableGameObj^ obj, ICombatSound^ sound);

		void EnemySeen(IScriptableGameObj^ obj, IScriptableGameObj^ enemy);

		void ActionComplete(IScriptableGameObj^ obj, int actionId, ActionCompleteReason completeReason);

		void AnimationComplete(IScriptableGameObj^ obj, String^ animationName);

		void Poked(IScriptableGameObj^ obj, IScriptableGameObj^ poker);

		void Entered(IScriptableGameObj^ obj, IScriptableGameObj^ enterer);

		void Exited(IScriptableGameObj^ obj, IScriptableGameObj^ exiter);

		bool VehicleEntryRequest(IScriptableGameObj^ obj, IcPlayer^ player, int% seat);

		bool VehicleEntryRequest(IScriptableGameObj^ obj, IVehicleGameObj^ vehicle, int% seat);

		void VehicleEnter(IScriptableGameObj^ obj, IcPlayer^ player, int seat);

		void VehicleEnter(IScriptableGameObj^ obj, IVehicleGameObj^ vehicle, int seat);

		void VehicleExit(IScriptableGameObj^ obj, IcPlayer^ player, int seat);

		void VehicleExit(IScriptableGameObj^ obj, IVehicleGameObj^ vehicle, int seat);

		bool VehicleFlip(IScriptableGameObj^ obj);

		bool DamageDealtRequest(IScriptableGameObj^ obj, IDamageableGameObj^ victim, float% damage, unsigned int% warhead, float scale, DADamageType type);

		bool DamageReceivedRequest(IScriptableGameObj^ obj, IArmedGameObj^ damager, float% damage, unsigned int% warhead, float scale, DADamageType type);

		void DamageDealt(IScriptableGameObj^ obj, IDamageableGameObj^ victim, float damage, unsigned int warhead, float scale, DADamageType type);

		void DamageReceived(IScriptableGameObj^ obj, IArmedGameObj^ damager, float damage, unsigned int warhead, float scale, DADamageType type);

		void KillDealt(IScriptableGameObj^ obj, IDamageableGameObj^ victim, float damage, unsigned int warhead, float scale, DADamageType type);

		void KillReceived(IScriptableGameObj^ obj, IArmedGameObj^ killer, float damage, unsigned int warhead, float scale, DADamageType type);

		bool PowerUpGrantRequest(IScriptableGameObj^ obj, IcPlayer^ player);

		bool PowerUpGrantRequest(IScriptableGameObj^ obj, IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj);

		void PowerUpGrant(IScriptableGameObj^ obj, IcPlayer^ player);

		void PowerUpGrant(IScriptableGameObj^ obj, IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj);

		bool AddWeaponRequest(IScriptableGameObj^ obj, IWeaponDefinitionClass^ weapon);

		void AddWeapon(IScriptableGameObj^ obj, IWeaponClass^ weapon);

		void RemoveWeapon(IScriptableGameObj^ obj, IWeaponClass^ weapon);

		void ClearWeapons(IScriptableGameObj^ obj);

		void SetDeletePending();

		property IntPtr DAGameObjObserverClassPointer
		{
			IntPtr get();
		}

		property String^ Name
		{
			String^ get();
		}

		property int ID
		{
			int get();
			void set(int value);
		}

		property IScriptableGameObj^ Owner
		{
			IScriptableGameObj^ get();
		}
	};

	public ref class RenSharpGameObjObserverClass abstract : public IRenSharpGameObjObserverClass
	{
		private:
			bool disposedResources;
			bool destroyPointer;
			IntPtr daGameObjObserverClassPointer;
			IDAGameObjObserverClass^ daGameObjObserverClass;
			String ^name;

		public:
			RenSharpGameObjObserverClass(String ^name);
			~RenSharpGameObjObserverClass();
			!RenSharpGameObjObserverClass();

			String ^ToString() override;
			bool Equals(Object ^other) override;
			int GetHashCode() override sealed;

			virtual void InitUnmanagedAttachable() sealed;
			virtual void AttachToUnmanagedObject() sealed;
			virtual void RegisterManagedObject() sealed;
			virtual void ReleasePointer() sealed;
			virtual void UnmanagedAttach();
			virtual void ManagedRegistered();

			virtual void Init(IScriptableGameObj ^obj);
			virtual void Destroyed(IScriptableGameObj ^obj);
			virtual void Custom(IScriptableGameObj ^obj, int type, int param, IScriptableGameObj ^sender);
			virtual void SoundHeard(IScriptableGameObj ^obj, ICombatSound ^sound);
			virtual void EnemySeen(IScriptableGameObj ^obj, IScriptableGameObj ^enemy);
			virtual void ActionComplete(IScriptableGameObj ^obj, int actionId, ActionCompleteReason completeReason);
			virtual void AnimationComplete(IScriptableGameObj ^obj, String ^animationName);
			virtual void Poked(IScriptableGameObj ^obj, IScriptableGameObj ^poker);
			virtual void Entered(IScriptableGameObj ^obj, IScriptableGameObj ^enterer);
			virtual void Exited(IScriptableGameObj ^obj, IScriptableGameObj ^exiter);
			virtual bool VehicleEntryRequest(IScriptableGameObj ^obj, IcPlayer ^player, int %seat);
			virtual bool VehicleEntryRequest(IScriptableGameObj ^obj, IVehicleGameObj ^vehicle, int %seat);
			virtual void VehicleEnter(IScriptableGameObj ^obj, IcPlayer ^player, int seat);
			virtual void VehicleEnter(IScriptableGameObj ^obj, IVehicleGameObj ^vehicle, int seat);
			virtual void VehicleExit(IScriptableGameObj ^obj, IcPlayer ^player, int seat);
			virtual void VehicleExit(IScriptableGameObj ^obj, IVehicleGameObj ^vehicle, int seat);
			virtual bool VehicleFlip(IScriptableGameObj ^obj);
			virtual bool DamageDealtRequest(IScriptableGameObj ^obj, IDamageableGameObj ^victim, float %damage, unsigned int %warhead, float scale, DADamageType type);
			virtual bool DamageReceivedRequest(IScriptableGameObj ^obj, IArmedGameObj ^damager, float %damage, unsigned int %warhead, float scale, DADamageType type);
			virtual void DamageDealt(IScriptableGameObj ^obj, IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type);
			virtual void DamageReceived(IScriptableGameObj ^obj, IArmedGameObj ^damager, float damage, unsigned int warhead, float scale, DADamageType type);
			virtual void KillDealt(IScriptableGameObj ^obj, IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type);
			virtual void KillReceived(IScriptableGameObj ^obj, IArmedGameObj ^killer, float damage, unsigned int warhead, float scale, DADamageType type);
			virtual bool PowerUpGrantRequest(IScriptableGameObj ^obj, IcPlayer ^player);
			virtual bool PowerUpGrantRequest(IScriptableGameObj ^obj, IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj);
			virtual void PowerUpGrant(IScriptableGameObj ^obj, IcPlayer ^player);
			virtual void PowerUpGrant(IScriptableGameObj ^obj, IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj);
			virtual bool AddWeaponRequest(IScriptableGameObj ^obj, IWeaponDefinitionClass ^weapon);
			virtual void AddWeapon(IScriptableGameObj ^obj, IWeaponClass ^weapon);
			virtual void RemoveWeapon(IScriptableGameObj ^obj, IWeaponClass ^weapon);
			virtual void ClearWeapons(IScriptableGameObj ^obj);
			virtual void SetDeletePending() sealed;
			virtual IDAGameObjObserverClass ^ AsUnmanagedObject() sealed;

			virtual void TimerExpired(int number, Object^ data);
			virtual void StartTimer(int number, TimeSpan duration, bool repeat, Object^ data) sealed;
			virtual void StartTimer(int number, TimeSpan duration, bool repeat) sealed;
			virtual void StartTimer(int number, TimeSpan duration) sealed;
			virtual void StartTimer(TimeSpan duration, bool repeat, System::Action<RenSharpTimerStruct^>^ action) sealed;
			virtual void StartTimer(TimeSpan duration, System::Action<RenSharpTimerStruct^>^ action) sealed;
			virtual void StopTimer(int number, Object^ data) sealed;
			virtual void StopTimer(int number) sealed;
			virtual void StopTimer(System::Action<RenSharpTimerStruct^>^ action) sealed;
			virtual bool IsTimer(int number, Object^ data) sealed;
			virtual bool IsTimer(int number) sealed;
			virtual bool IsTimer(System::Action<RenSharpTimerStruct^>^ action) sealed;
			virtual void ClearTimers() sealed;

			property Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ Timers
			{
				virtual Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ get() sealed;
			}

			property IntPtr DAGameObjObserverClassPointer
			{
				virtual IntPtr get() sealed;
			}
	
			property IntPtr Pointer
			{
				virtual IntPtr get() sealed;
			}
	
			property bool IsAttached
			{
				virtual bool get() sealed;
			}

			property bool IsRegistered
			{
				virtual bool get() sealed;
			}

			property bool DestroyPointer
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property String ^Name
			{
				virtual String ^get() sealed;
			}

			property int ID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property IScriptableGameObj ^Owner
			{
				virtual IScriptableGameObj ^get() sealed;
			}

		protected:
			property ::DAGameObjObserverClass *InternalDAGameObjObserverClassPointer
			{
				virtual ::DAGameObjObserverClass *get();
			}
	};
}