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

#include "Mscripts.h"
#include "Mda_event.h"

#pragma managed(push, off)

class DAGameObjObserverClass;

#pragma managed(pop)

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
	interface class IRenSharpGameObjObserverClass;

	public interface class IDAGameObjObserverClass : public IGameObjObserverClass
	{
		void Init();

		bool VehicleEntryRequest(IcPlayer ^player, int %seat);

		bool VehicleEntryRequest(IVehicleGameObj ^vehicle, int %seat);

		void VehicleEnter(IcPlayer ^player, int seat);

		void VehicleEnter(IVehicleGameObj ^vehicle, int seat);

		void VehicleExit(IcPlayer ^player, int seat);

		void VehicleExit(IVehicleGameObj ^vehicle, int seat);

		bool VehicleFlip();

		bool DamageDealtRequest(IDamageableGameObj ^victim, float %damage, unsigned int %warhead, float scale, DADamageType type);

		bool DamageReceivedRequest(IArmedGameObj ^damager, float %damage, unsigned int %warhead, float scale, DADamageType type);

		void DamageDealt(IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type);

		void DamageReceived(IArmedGameObj ^damager, float damage, unsigned int warhead, float scale, DADamageType type);

		void KillDealt(IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type);

		void KillReceived(IArmedGameObj ^killer, float damage, unsigned int warhead, float scale, DADamageType type);

		bool PowerUpGrantRequest(IcPlayer ^player);

		bool PowerUpGrantRequest(IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj);

		void PowerUpGrant(IcPlayer ^player);

		void PowerUpGrant(IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj);

		bool AddWeaponRequest(IWeaponDefinitionClass ^weapon);

		void AddWeapon(IWeaponClass ^weapon);

		void RemoveWeapon(IWeaponClass ^weapon);

		void ClearWeapons();

		void StartTimer(int number, float duration);

		void StopTimer(int number);

		bool IsTimer(int number);

		void SetDeletePending();

		IRenSharpGameObjObserverClass^ AsManagedGameObjObserverClass();

		property IntPtr DAGameObjObserverClassPointer
		{
			IntPtr get();
		}

		property bool IsManagedGameObjObserverClass
		{
			bool get();
		}
	};

	public ref class DAGameObjObserverClass : public GameObjObserverClass, public IDAGameObjObserverClass
	{
		protected:
			DAGameObjObserverClass();

		public:
			DAGameObjObserverClass(IntPtr pointer);

			bool Equals(Object^ other) override;

			[Obsolete("Reserved for internal use. Use Init instead.", true)]
			void Attach(IScriptableGameObj ^obj) override sealed;

			[Obsolete("Reserved for internal use. Use DestroyPointer instead.", true)]
			void Detach(IScriptableGameObj ^obj) override sealed;

			[Obsolete("Replaced by Init.", true)]
			void Created(IScriptableGameObj ^obj) override sealed;

			[Obsolete("Replaced by KillReceived.", true)]
			void Killed(IScriptableGameObj ^obj, IScriptableGameObj ^killer) override sealed;

			[Obsolete("Replaced by DamageReceived.", true)]
			void Damaged(IScriptableGameObj ^obj, IScriptableGameObj ^damager, float amount) override sealed;

			virtual void Init() sealed;
			virtual bool VehicleEntryRequest(IcPlayer ^player, int %seat) sealed;
			virtual bool VehicleEntryRequest(IVehicleGameObj ^vehicle, int %seat) sealed;
			virtual void VehicleEnter(IcPlayer ^player, int seat) sealed;
			virtual void VehicleEnter(IVehicleGameObj ^vehicle, int seat) sealed;
			virtual void VehicleExit(IcPlayer ^player, int seat) sealed;
			virtual void VehicleExit(IVehicleGameObj ^vehicle, int seat) sealed;
			virtual bool VehicleFlip() sealed;
			virtual bool DamageDealtRequest(IDamageableGameObj ^victim, float %damage, unsigned int %warhead, float scale, DADamageType type) sealed;
			virtual bool DamageReceivedRequest(IArmedGameObj ^damager, float %damage, unsigned int %warhead, float scale, DADamageType type) sealed;
			virtual void DamageDealt(IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type) sealed;
			virtual void DamageReceived(IArmedGameObj ^damager, float damage, unsigned int warhead, float scale, DADamageType type) sealed;
			virtual void KillDealt(IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type) sealed;
			virtual void KillReceived(IArmedGameObj ^killer, float damage, unsigned int warhead, float scale, DADamageType type) sealed;
			virtual bool PowerUpGrantRequest(IcPlayer ^player) sealed;
			virtual bool PowerUpGrantRequest(IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj) sealed;
			virtual void PowerUpGrant(IcPlayer ^player) sealed;
			virtual void PowerUpGrant(IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj) sealed;
			virtual bool AddWeaponRequest(IWeaponDefinitionClass ^weapon) sealed;
			virtual void AddWeapon(IWeaponClass ^weapon) sealed;
			virtual void RemoveWeapon(IWeaponClass ^weapon) sealed;
			virtual void ClearWeapons() sealed;
			virtual void StartTimer(int number, float duration) sealed;
			virtual void StopTimer(int number) sealed;
			virtual bool IsTimer(int number) sealed;
			virtual void SetDeletePending() sealed;
			virtual IRenSharpGameObjObserverClass^ AsManagedGameObjObserverClass() sealed;

			property IntPtr DAGameObjObserverClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IScriptableGameObj ^Owner
			{
				IScriptableGameObj ^get() override sealed;
			}

			property bool IsManagedGameObjObserverClass
			{
				virtual bool get() sealed;
			}

		protected:
			property ::GameObjObserverClass *InternalGameObjObserverClassPointer
			{
				::GameObjObserverClass *get() override;
			}

			property ::DAGameObjObserverClass *InternalDAGameObjObserverClassPointer
			{
				virtual ::DAGameObjObserverClass *get();
			}
	};

	public interface class IDAGameObjManager : public IDAEventClass
	{
		property IntPtr DAGameObjManagerPointer
		{
			IntPtr get();
		}
	};

	public ref class DAGameObjManager : public DAEventClass, public IDAGameObjManager
	{
		// Although you can instantiate a DAGameObjManager class, it doesn't make any sense so I left it out
		public:
			DAGameObjManager(IntPtr pointer);

			static void SetObserverDeletePending(IDAGameObjObserverClass^ observer);
			static void SetObserverDeletePending(IRenSharpGameObjObserverClass^ observer);
			static void SetGameObjDeletePending(IScriptableGameObj^ obj);
			static void SetGameObjTTOnly(IScriptableGameObj^ obj);
			static void SetGameObjStockOnly(IScriptableGameObj^ obj);
			static void SetGameObjInvisible(IScriptableGameObj^ obj);
			static void SetGameObjInvisibleNoDelete(IScriptableGameObj^ obj);

			property IntPtr DAGameObjManagerPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::DAEventClass* InternalDAEventClassPointer
			{
				::DAEventClass* get() override;
			}

			property ::DAGameObjManager* InternalDAGameObjManagerPointer
			{
				virtual ::DAGameObjManager* get();
			}
	};
}