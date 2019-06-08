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

#pragma once

#include "Mengine_ttdef.h"
#include "MConnectionAcceptanceFilter.h"
#include "Mda_event.h"
#include "ITimerInterface.h"
#include "IUnmanagedAttachable.h"
#include "IChatCommandInterface.h"
#include "IKeyHookInterface.h"

#pragma managed(push, off)

class DAEventClass;

#pragma managed(pop)

using namespace System;

namespace RenSharp
{
	interface class IcPlayer;
	interface class IDATokenClass;
	interface class IConnectionRequest;
	interface class IBaseControllerClass;
	interface class ISoldierGameObjDef;
	interface class IVehicleGameObjDef;
	interface class IPowerUpGameObjDef;
	interface class IVehicleGameObj;
	interface class IPowerUpGameObj;
	interface class IWeaponDefinitionClass;
	interface class IWeaponClass;
	interface class IBeaconGameObj;
	interface class IC4GameObj;
	interface class ISmartGameObj;
	interface class IVehicleFactoryGameObj;
	interface class IScriptableGameObj;
	interface class IDamageableGameObj;
	interface class IArmedGameObj;
	interface class IAmmoDefinitionClass;
	interface class IPhysicalGameObj;
	interface class IScriptZoneGameObj;

	public interface class IRenSharpEventClass : public ITimerInterface, public IUnmanagedAttachable<IDAEventClass^>, public IChatCommandInterface, public IKeyHookInterface
	{
		void SettingsLoadedEvent();

		bool ChatEvent(IcPlayer^ player, TextMessageEnum type, String^ message, int receiverID);

		bool ChatCommandEvent(IcPlayer^ player, TextMessageEnum type, String^ command, IDATokenClass^ text, int receiverID);

		bool KeyHookEvent(IcPlayer^ player, String^ key);

		bool HostChatEvent(int id, TextMessageEnum type, String^ message);

		bool RadioEvent(IcPlayer^ player, int playerType, int announcementID, int iconID, AnnouncementEnum announcementType);

		ConnectionAcceptanceFilterStatus ConnectionRequestEvent(IConnectionRequest^ request, String^% refusalMessage);

		void PlayerPreJoinEvent(IConnectionRequest^ request);

		void PlayerJoinEvent(IcPlayer^ player);

		void PlayerLeaveEvent(IcPlayer^ player);

		void PlayerLoadedEvent(IcPlayer^ player);

		void NameChangeEvent(IcPlayer^ player);

		void LevelLoadedEvent();

		void RemixEvent();

		void RebalanceEvent();

		void SwapEvent();

		void GameOverEvent();

		void ConsoleOutputEvent(String^ output);

		void RenLogEvent(String^ output);

		void DALogEvent(String^ header, String^ output);

		int CharacterPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, ISoldierGameObjDef^ item);

		int VehiclePurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, IVehicleGameObjDef^ item);

		int PowerUpPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, IPowerUpGameObjDef^ item);

		int CustomPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, unsigned int id);

		void CharacterPurchaseEvent(IcPlayer^ player, float cost, ISoldierGameObjDef^ item);

		void VehiclePurchaseEvent(IcPlayer^ player, float cost, IVehicleGameObjDef^ item);

		void PowerUpPurchaseEvent(IcPlayer^ player, float cost, IPowerUpGameObjDef^ item);

		void CustomPurchaseEvent(IcPlayer^ player, float cost, unsigned int id);

		bool RefillEvent(IcPlayer^ player);

		bool SuicideEvent(IcPlayer^ player);

		bool TeamChangeRequestEvent(IcPlayer^ player);

		void TeamChangeEvent(IcPlayer^ player);

		bool VehicleEntryRequestEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int% seat);

		void VehicleEnterEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int seat);

		void VehicleExitEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int seat);

		bool PowerUpGrantRequestEvent(IcPlayer^ player, IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj);

		void PowerUpGrantEvent(IcPlayer^ player, IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj);

		bool AddWeaponRequestEvent(IcPlayer^ player, IWeaponDefinitionClass^ weapon);

		void AddWeaponEvent(IcPlayer^ player, IWeaponClass^ weapon);

		void RemoveWeaponEvent(IcPlayer^ player, IWeaponClass^ weapon);

		void ClearWeaponsEvent(IcPlayer^ player);

		void BeaconDeployEvent(IBeaconGameObj^ beacon);

		void BeaconDetonateEvent(IBeaconGameObj^ beacon);

		bool C4DetonateRequestEvent(IC4GameObj^ c4, ISmartGameObj^ triggerer);

		void C4DetonateEvent(IC4GameObj^ c4);

		void ChangeCharacterEvent(IcPlayer^ player, ISoldierGameObjDef^ soldier);

		bool VehicleFlipEvent(IVehicleGameObj^ vehicle);

		bool RequestVehicleEvent(IVehicleFactoryGameObj^ factory, IVehicleGameObjDef^ vehicle, IcPlayer^ player, float delay);

		void Think();

		void ObjectCreatedEvent(IScriptableGameObj^ obj);

		bool StockClientDamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float damage, uint warhead);

		bool TTClientDamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, IAmmoDefinitionClass^ ammo, String^ bone);

		bool DamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float% damage, unsigned int% warhead, float scale, DADamageType type);

		void DamageEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float damage, unsigned int warhead, float scale, DADamageType type);

		void KillEvent(IDamageableGameObj^ victim, IArmedGameObj^ killer, float damage, unsigned int warhead, float scale, DADamageType type);

		void CustomEvent(IScriptableGameObj^ obj, int type, int param, IScriptableGameObj^ sender);

		void PokeEvent(IcPlayer^ player, IPhysicalGameObj^ obj);

		void ZoneEnterEvent(IScriptZoneGameObj^ obj, IPhysicalGameObj^ enterer);

		void ZoneExitEvent(IScriptZoneGameObj^ obj, IPhysicalGameObj^ exiter);

		void ObjectDestroyedEvent(IScriptableGameObj^ obj);

		void RegisterEvent(DAEventType type, std::uint32_t priority);

		void RegisterEvent(DAEventType type);

		void UnregisterEvent(DAEventType type);

		void ClearEvents();

		void RegisterObjectEvent(DAObjectEventType type, DAObjectEventObjectType objectType, std::uint32_t priority);

		void RegisterObjectEvent(DAObjectEventType type, DAObjectEventObjectType objectType);

		void UnregisterObjectEvent(DAObjectEventType type);

		void ClearObjectEvents();

		property IntPtr DAEventClassPointer
		{
			IntPtr get();
		}
	};

	public ref class RenSharpEventClass abstract : public IRenSharpEventClass
	{
		private:
			bool disposedResources;
			bool destroyPointer;
			IntPtr daEventClassPointer;
			IDAEventClass^ daEventClass;

		public:
			RenSharpEventClass();
			~RenSharpEventClass();
			!RenSharpEventClass();

			bool Equals(Object^ other) override;
			int GetHashCode() override sealed;

			virtual void AttachToUnmanagedObject() sealed;
			virtual void RegisterManagedObject() sealed;
			virtual void ReleasePointer() sealed;
			virtual void UnmanagedAttach();
			virtual void ManagedRegistered();

			virtual void SettingsLoadedEvent();
			virtual bool ChatEvent(IcPlayer ^player, TextMessageEnum type, String ^message, int receiverID);
			virtual bool ChatCommandEvent(IcPlayer ^player, TextMessageEnum type, String ^command, IDATokenClass ^text, int receiverID);
			virtual bool KeyHookEvent(IcPlayer ^player, String ^key);
			virtual bool HostChatEvent(int id, TextMessageEnum type, String ^message);
			virtual bool RadioEvent(IcPlayer ^player, int playerType, int announcementID, int iconID, AnnouncementEnum announcementType);
			virtual ConnectionAcceptanceFilterStatus ConnectionRequestEvent(IConnectionRequest ^request, String ^%refusalMessage);
			virtual void PlayerPreJoinEvent(IConnectionRequest ^request);
			virtual void PlayerJoinEvent(IcPlayer ^player);
			virtual void PlayerLeaveEvent(IcPlayer ^player);
			virtual void PlayerLoadedEvent(IcPlayer ^player);
			virtual void NameChangeEvent(IcPlayer ^player);
			virtual void LevelLoadedEvent();
			virtual void RemixEvent();
			virtual void RebalanceEvent();
			virtual void SwapEvent();
			virtual void GameOverEvent();
			virtual void ConsoleOutputEvent(String ^output);
			virtual void RenLogEvent(String ^output);
			virtual void DALogEvent(String ^header, String ^output);
			virtual int CharacterPurchaseRequestEvent(IBaseControllerClass ^baseController, IcPlayer ^player, float %cost, ISoldierGameObjDef ^item);
			virtual int VehiclePurchaseRequestEvent(IBaseControllerClass ^baseController, IcPlayer ^player, float %cost, IVehicleGameObjDef ^item);
			virtual int PowerUpPurchaseRequestEvent(IBaseControllerClass ^baseController, IcPlayer ^player, float %cost, IPowerUpGameObjDef ^item);
			virtual int CustomPurchaseRequestEvent(IBaseControllerClass ^baseController, IcPlayer ^player, float %cost, unsigned int id);
			virtual void CharacterPurchaseEvent(IcPlayer ^player, float cost, ISoldierGameObjDef ^item);
			virtual void VehiclePurchaseEvent(IcPlayer ^player, float cost, IVehicleGameObjDef ^item);
			virtual void PowerUpPurchaseEvent(IcPlayer ^player, float cost, IPowerUpGameObjDef ^item);
			virtual void CustomPurchaseEvent(IcPlayer ^player, float cost, unsigned int id);
			virtual bool RefillEvent(IcPlayer ^player);
			virtual bool SuicideEvent(IcPlayer ^player);
			virtual bool TeamChangeRequestEvent(IcPlayer ^player);
			virtual void TeamChangeEvent(IcPlayer ^player);
			virtual bool VehicleEntryRequestEvent(IVehicleGameObj ^vehicle, IcPlayer ^player, int %seat);
			virtual void VehicleEnterEvent(IVehicleGameObj ^vehicle, IcPlayer ^player, int seat);
			virtual void VehicleExitEvent(IVehicleGameObj ^vehicle, IcPlayer ^player, int seat);
			virtual bool PowerUpGrantRequestEvent(IcPlayer ^player, IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj);
			virtual void PowerUpGrantEvent(IcPlayer ^player, IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj);
			virtual bool AddWeaponRequestEvent(IcPlayer ^player, IWeaponDefinitionClass ^weapon);
			virtual void AddWeaponEvent(IcPlayer ^player, IWeaponClass ^weapon);
			virtual void RemoveWeaponEvent(IcPlayer ^player, IWeaponClass ^weapon);
			virtual void ClearWeaponsEvent(IcPlayer ^player);
			virtual void BeaconDeployEvent(IBeaconGameObj ^beacon);
			virtual void BeaconDetonateEvent(IBeaconGameObj ^beacon);
			virtual bool C4DetonateRequestEvent(IC4GameObj ^c4, ISmartGameObj ^triggerer);
			virtual void C4DetonateEvent(IC4GameObj ^c4);
			virtual void ChangeCharacterEvent(IcPlayer ^player, ISoldierGameObjDef ^soldier);
			virtual bool VehicleFlipEvent(IVehicleGameObj ^vehicle);
			virtual bool RequestVehicleEvent(IVehicleFactoryGameObj ^factory, IVehicleGameObjDef ^vehicle, IcPlayer ^player, float delay);
			virtual void Think();
			virtual void ObjectCreatedEvent(IScriptableGameObj ^obj);
			virtual bool StockClientDamageRequestEvent(IDamageableGameObj ^victim, IArmedGameObj ^damager, float damage, uint warhead);
			virtual bool TTClientDamageRequestEvent(IDamageableGameObj ^victim, IArmedGameObj ^damager, IAmmoDefinitionClass ^ammo, String ^bone);
			virtual bool DamageRequestEvent(IDamageableGameObj ^victim, IArmedGameObj ^damager, float %damage, unsigned int %warhead, float scale, DADamageType type);
			virtual void DamageEvent(IDamageableGameObj ^victim, IArmedGameObj ^damager, float damage, unsigned int warhead, float scale, DADamageType type);
			virtual void KillEvent(IDamageableGameObj ^victim, IArmedGameObj ^killer, float damage, unsigned int warhead, float scale, DADamageType type);
			virtual void CustomEvent(IScriptableGameObj ^obj, int type, int param, IScriptableGameObj ^sender);
			virtual void PokeEvent(IcPlayer ^player, IPhysicalGameObj ^obj);
			virtual void ZoneEnterEvent(IScriptZoneGameObj ^obj, IPhysicalGameObj ^enterer);
			virtual void ZoneExitEvent(IScriptZoneGameObj ^obj, IPhysicalGameObj ^exiter);
			virtual void ObjectDestroyedEvent(IScriptableGameObj ^obj);

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
			virtual void RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel, DAChatType chatType, Object^ data) sealed;
			virtual void RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel, DAChatType chatType) sealed;
			virtual void RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel) sealed;
			virtual void RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, Object^ data) sealed;
			virtual void RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters) sealed;
			virtual void RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers) sealed;
			virtual void UnregisterChatCommand(String^ trigger) sealed;
			virtual void ClearChatCommands() sealed;

			virtual bool FilterKeyHook(IcPlayer^ player, String^ key, Object^ data) sealed;
			virtual void RegisterKeyHook(RenSharpKHDelegate^ func, String^ triggers, Object^ data) sealed;
			virtual void RegisterKeyHook(RenSharpKHDelegate^ func, String^ triggers) sealed;
			virtual void UnregisterKeyHook(String^ trigger) sealed;
			virtual void ClearKeyHooks() sealed;

			virtual void RegisterEvent(DAEventType type, std::uint32_t priority) sealed;
			virtual void RegisterEvent(DAEventType type) sealed;
			virtual void UnregisterEvent(DAEventType type) sealed;
			virtual void ClearEvents() sealed;

			virtual void RegisterObjectEvent(DAObjectEventType type, DAObjectEventObjectType objectType, std::uint32_t priority) sealed;
			virtual void RegisterObjectEvent(DAObjectEventType type, DAObjectEventObjectType objectType) sealed;
			virtual void UnregisterObjectEvent(DAObjectEventType type) sealed;
			virtual void ClearObjectEvents() sealed;

			virtual IDAEventClass^ AsUnmanagedObject() sealed;

			property Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ Timers
			{
				virtual Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ get() sealed;
			}

			property IntPtr DAEventClassPointer
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

			property bool DestroyPointer
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property Collections::Generic::IEnumerable<RenSharpChatCommandStruct^>^ ChatCommands
			{
				virtual Collections::Generic::IEnumerable<RenSharpChatCommandStruct^>^ get() sealed;
			}

			property Collections::Generic::IEnumerable<RenSharpKeyHookStruct^>^ KeyHooks
			{
				virtual Collections::Generic::IEnumerable<RenSharpKeyHookStruct^>^ get() sealed;
			}

		protected:
			property ::DAEventClass* InternalDAEventClassPointer
			{
				virtual ::DAEventClass*get();
			}
	};
}