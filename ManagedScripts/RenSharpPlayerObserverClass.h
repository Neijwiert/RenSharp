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
#include "Mda_player.h"
#include "ITimerInterface.h"
#include "IUnmanagedAttachable.h"
#include "IChatCommandInterface.h"
#include "IKeyHookInterface.h"

#pragma managed(push, off)

class DAPlayerObserverClass;

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
	interface class IDAPlayerObserverClass;
	interface class IDATokenClass;

	public interface class IRenSharpPlayerObserverClass : public ITimerInterface, public IUnmanagedAttachable<IDAPlayerObserverClass^>, public IChatCommandInterface, public IKeyHookInterface
	{
		void Init();

		void Join();

		void Leave();

		void LevelLoaded();

		void PlayerLoaded();

		void NameChange();

		void TeamChange();

		int CharacterPurchaseRequest(float% cost, ISoldierGameObjDef^ item);

		int VehiclePurchaseRequest(float% cost, IVehicleGameObjDef^ item);

		int PowerUpPurchaseRequest(float% cost, IPowerUpGameObjDef^ item);

		int CustomPurchaseRequest(float% cost, unsigned int id);

		void CharacterPurchase(float cost, ISoldierGameObjDef^ item);

		void VehiclePurchase(float cost, IVehicleGameObjDef^ item);

		void PowerUpPurchase(float cost, IPowerUpGameObjDef^ item);

		void CustomPurchase(float cost, unsigned int id);

		bool VehicleEntryRequest(IVehicleGameObj^ vehicle, int% seat);

		void VehicleEnter(IVehicleGameObj^ vehicle, int seat);

		void VehicleExit(IVehicleGameObj^ vehicle, int seat);

		bool PowerUpGrantRequest(IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj);

		void PowerUpGrant(IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj);

		bool AddWeaponRequest(IWeaponDefinitionClass^ weapon);

		void AddWeapon(IWeaponClass^ weapon);

		void RemoveWeapon(IWeaponClass^ weapon);

		void ClearWeapons();

		bool C4DetonateRequest(IC4GameObj^ c4);

		void C4Detonate(IC4GameObj^ c4);

		void ChangeCharacter(ISoldierGameObjDef^ soldier);

		void Created();

		void Destroyed();

		bool DamageDealtRequest(IDamageableGameObj^ victim, float% damage, unsigned int% warhead, float scale, DADamageType type);

		bool DamageReceivedRequest(IArmedGameObj^ damager, float% damage, unsigned int% warhead, float scale, DADamageType type);

		void DamageDealt(IDamageableGameObj^ victim, float damage, unsigned int warhead, float scale, DADamageType type);

		void DamageReceived(IArmedGameObj^ damager, float damage, unsigned int warhead, float scale, DADamageType type);

		void KillDealt(IDamageableGameObj^ victim, float damage, unsigned int warhead, float scale, DADamageType type);

		void KillReceived(IArmedGameObj^ killer, float damage, unsigned int warhead, float scale, DADamageType type);

		void Custom(IScriptableGameObj^ sender, int type, int param);

		void Poked(IcPlayer^ player);

		void Think();

		void AddFlag(DAPlayerFlags flag);

		void RemoveFlag(DAPlayerFlags flag);

		bool HasFlag(DAPlayerFlags flag);

		void SetDeletePending();

		property IntPtr DAPlayerObserverClassPointer
		{
			IntPtr get();
		}

		property bool IsDeletePending
		{
			bool get();
		}

		property String^ ObserverName
		{
			String^ get();
		}

		property IcPlayer^ Owner
		{
			IcPlayer^ get();
			void set(IcPlayer^ value);
		}

		property DAPlayerFlags Flags
		{
			DAPlayerFlags get();
			void set(DAPlayerFlags value);
		}

		property int ID
		{
			int get();
		}

		property String^ Name
		{
			String^ get();
		}

		property ISoldierGameObj^ GameObj
		{
			ISoldierGameObj^ get();
		}

		property int Team
		{
			int get();
		}
	};

	public ref class RenSharpPlayerObserverClass abstract : public IRenSharpPlayerObserverClass
	{
		private:
			bool disposedResources;
			bool destroyPointer;
			IntPtr daPlayerObserverClassPointer;
			IDAPlayerObserverClass^ daPlayerObserverClass;
			String ^name;

		public:
			RenSharpPlayerObserverClass(String ^name);
			~RenSharpPlayerObserverClass();
			!RenSharpPlayerObserverClass();

			String ^ToString() override;
			bool Equals(Object ^other) override;
			int GetHashCode() override sealed;

			virtual void InitUnmanagedAttachable() sealed;
			virtual void AttachToUnmanagedObject() sealed;
			virtual void RegisterManagedObject() sealed;
			virtual void ReleasePointer() sealed;
			virtual void UnmanagedAttach();
			virtual void ManagedRegistered();

			virtual void Init();
			virtual void Join();
			virtual void Leave();
			virtual void LevelLoaded();
			virtual void PlayerLoaded();
			virtual void NameChange();
			virtual void TeamChange();
			virtual int CharacterPurchaseRequest(float %cost, ISoldierGameObjDef ^item);
			virtual int VehiclePurchaseRequest(float %cost, IVehicleGameObjDef ^item);
			virtual int PowerUpPurchaseRequest(float %cost, IPowerUpGameObjDef ^item);
			virtual int CustomPurchaseRequest(float %cost, unsigned int id);
			virtual void CharacterPurchase(float cost, ISoldierGameObjDef ^item);
			virtual void VehiclePurchase(float cost, IVehicleGameObjDef ^item);
			virtual void PowerUpPurchase(float cost, IPowerUpGameObjDef ^item);
			virtual void CustomPurchase(float cost, unsigned int id);
			virtual bool VehicleEntryRequest(IVehicleGameObj ^vehicle, int %seat);
			virtual void VehicleEnter(IVehicleGameObj ^vehicle, int seat);
			virtual void VehicleExit(IVehicleGameObj ^vehicle, int seat);
			virtual bool PowerUpGrantRequest(IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj);
			virtual void PowerUpGrant(IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj);
			virtual bool AddWeaponRequest(IWeaponDefinitionClass ^weapon);
			virtual void AddWeapon(IWeaponClass ^weapon);
			virtual void RemoveWeapon(IWeaponClass ^weapon);
			virtual void ClearWeapons();
			virtual bool C4DetonateRequest(IC4GameObj ^c4);
			virtual void C4Detonate(IC4GameObj ^c4);
			virtual void ChangeCharacter(ISoldierGameObjDef ^soldier);
			virtual void Created();
			virtual void Destroyed();
			virtual bool DamageDealtRequest(IDamageableGameObj ^victim, float %damage, unsigned int %warhead, float scale, DADamageType type);
			virtual bool DamageReceivedRequest(IArmedGameObj ^damager, float %damage, unsigned int %warhead, float scale, DADamageType type);
			virtual void DamageDealt(IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type);
			virtual void DamageReceived(IArmedGameObj ^damager, float damage, unsigned int warhead, float scale, DADamageType type);
			virtual void KillDealt(IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type);
			virtual void KillReceived(IArmedGameObj ^killer, float damage, unsigned int warhead, float scale, DADamageType type);
			virtual void Custom(IScriptableGameObj ^sender, int type, int param);
			virtual void Poked(IcPlayer ^player);
			virtual void Think();

			virtual void TimerExpired(int number, Object^ data);
			virtual void StartTimer(int number, TimeSpan duration, bool repeat, Object^ data) sealed;
			virtual void StartTimer(int number, TimeSpan duration, bool repeat) sealed;
			virtual void StartTimer(int number, TimeSpan duration) sealed;
			virtual void StopTimer(int number, Object^ data) sealed;
			virtual void StopTimer(int number) sealed;
			virtual bool IsTimer(int number, Object^ data) sealed;
			virtual bool IsTimer(int number) sealed;
			virtual void ClearTimers() sealed;

			virtual bool FilterChatCommand(IcPlayer^ player, String^ command, IDATokenClass^ text, TextMessageEnum chatType, Object^ data) sealed;
			virtual RenSharpChatCommandStruct^ RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel, DAChatType chatType, Object^ data) sealed;
			virtual RenSharpChatCommandStruct^ RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel, DAChatType chatType) sealed;
			virtual RenSharpChatCommandStruct^ RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel) sealed;
			virtual RenSharpChatCommandStruct^ RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, Object^ data) sealed;
			virtual RenSharpChatCommandStruct^ RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters) sealed;
			virtual RenSharpChatCommandStruct^ RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers) sealed;
			virtual void UnregisterChatCommand(String^ trigger) sealed;
			virtual void ClearChatCommands() sealed;

			virtual bool FilterKeyHook(IcPlayer^ player, String^ key, Object^ data) sealed;
			virtual RenSharpKeyHookStruct^ RegisterKeyHook(RenSharpKHDelegate^ func, String^ triggers, Object^ data) sealed;
			virtual RenSharpKeyHookStruct^ RegisterKeyHook(RenSharpKHDelegate^ func, String^ triggers) sealed;
			virtual void UnregisterKeyHook(String^ trigger) sealed;
			virtual void ClearKeyHooks() sealed;

			virtual void AddFlag(DAPlayerFlags flag) sealed;
			virtual void RemoveFlag(DAPlayerFlags flag) sealed;
			virtual bool HasFlag(DAPlayerFlags flag) sealed;
			virtual void SetDeletePending() sealed;
			virtual IDAPlayerObserverClass ^ AsUnmanagedObject() sealed;

			property Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ Timers
			{
				virtual Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ get() sealed;
			}

			property Collections::Generic::IEnumerable<RenSharpChatCommandStruct^>^ ChatCommands
			{
				virtual Collections::Generic::IEnumerable<RenSharpChatCommandStruct^>^ get() sealed;
			}

			property Collections::Generic::IEnumerable<RenSharpKeyHookStruct^>^ KeyHooks
			{
				virtual Collections::Generic::IEnumerable<RenSharpKeyHookStruct^>^ get() sealed;
			}

			property bool IsDeletePending
			{
				virtual bool get() sealed;
			}

			property String ^ObserverName
			{
				virtual String ^get() sealed;
			}

			property IntPtr DAPlayerObserverClassPointer
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

			property IcPlayer ^Owner
			{
				virtual IcPlayer ^get() sealed;
				virtual void set(IcPlayer ^value) sealed;
			}

			property DAPlayerFlags Flags
			{
				virtual DAPlayerFlags get() sealed;
				virtual void set(DAPlayerFlags value) sealed;
			}

			property int ID
			{
				virtual int get() sealed;
			}

			property String ^Name
			{
				virtual String ^get() sealed;
			}

			property ISoldierGameObj ^GameObj
			{
				virtual ISoldierGameObj ^get() sealed;
			}

			property int Team
			{
				virtual int get() sealed;
			}

		protected:
			property ::DAPlayerObserverClass *InternalDAPlayerObserverClassPointer
			{
				virtual ::DAPlayerObserverClass *get();
			}
	};
}