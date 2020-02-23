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

#include "RenSharpEventClass.h"

#pragma managed(push, off)

class DABaseNodeClass;
class RenSharpNodeClass;

#pragma managed(pop)

using namespace System;

namespace RenSharp
{
	interface class IINIClass;
	interface class IPhysicalGameObj;
	value class Vector3;
	interface class IRenSharpNodeClass;

	// Must be declared here due to circular inclusion
	public interface class IDABaseNodeClass : public IDAEventClass
	{
		void SetContested(bool value);
		
		IRenSharpNodeClass^ AsManagedNode();

		property IntPtr DABaseNodeClassPointer
		{
			IntPtr get();
		}

		property Vector3 Position
		{
			Vector3 get();
		}

		property String^ ObjectPreset
		{
			String^ get();
		}

		property String^ ObjectModel
		{
			String^ get();
		}

		property int Team
		{
			int get();
		}

		property String^ Group
		{
			String^ get();
		}

		property String^ Name
		{
			String^ get();
		}

		property bool IsContested
		{
			bool get();
		}

		property bool IsCapturable
		{
			bool get();
			void set(bool value);
		}

		property bool IsCaptureOnce
		{
			bool get();
			void set(bool value);
		}

		property String^ Type
		{
			String^ get();
		}

		property bool IsManagedNode
		{
			bool get();
		}
	};

	public interface class IRenSharpNodeClass : public IRenSharpEventClass, public IUnmanagedAttachable<IDABaseNodeClass^>
	{
		void Init(IINIClass^ ini, String^ header);

		void ContestedEvent();

		void CaptureEvent();

		void SetContested(bool value);

		property IntPtr DABaseNodeClassPointer
		{
			IntPtr get();
		}

		property Vector3 Position
		{
			Vector3 get();
		}

		property String^ ObjectPreset
		{
			String^ get();
		}

		property String^ ObjectModel
		{
			String^ get();
		}

		property int Team
		{
			int get();
		}

		property String^ Group
		{
			String^ get();
		}

		property String^ Name
		{
			String^ get();
		}

		property bool IsContested
		{
			bool get();
		}

		property bool IsCapturable
		{
			bool get();
			void set(bool value);
		}

		property bool IsCaptureOnce
		{
			bool get();
			void set(bool value);
		}

		property String^ Type
		{
			String^ get();
		}
	};

	public ref class RenSharpNodeClass abstract : public IRenSharpNodeClass
	{
		private:
			bool disposedResources;
			bool destroyPointer;
			IntPtr daBaseNodeClassPointer;
			IDABaseNodeClass^ daBaseNodeClass;
			String^ type;

		public:
			RenSharpNodeClass(String^ type);
			~RenSharpNodeClass();
			!RenSharpNodeClass();

			String^ ToString() override;
			bool Equals(Object^ other) override;
			int GetHashCode() override sealed;

			virtual void AttachToUnmanagedObject() sealed;
			virtual void RegisterManagedObject() sealed;
			virtual void ReleasePointer() sealed;
			virtual void UnmanagedAttach();
			virtual void ManagedRegistered();
			virtual IDABaseNodeClass^ AsUnmanagedNode() sealed = IUnmanagedAttachable<IDABaseNodeClass^>::AsUnmanagedObject;
			virtual IDAEventClass^ AsUnmanagedEventClass() sealed = IUnmanagedAttachable<IDAEventClass^>::AsUnmanagedObject;

			virtual void SettingsLoadedEvent();
			virtual bool ChatEvent(IcPlayer^ player, TextMessageEnum type, String^ message, int receiverID);
			virtual bool ChatCommandEvent(IcPlayer^ player, TextMessageEnum type, String^ command, IDATokenClass^ text, int receiverID);
			virtual bool KeyHookEvent(IcPlayer^ player, String^ key);
			virtual bool HostChatEvent(int id, TextMessageEnum type, String^ message);
			virtual bool RadioEvent(IcPlayer^ player, int playerType, int announcementID, int iconID, AnnouncementEnum announcementType);
			virtual ConnectionAcceptanceFilterStatus ConnectionRequestEvent(IConnectionRequest^ request, String^% refusalMessage);
			virtual void PlayerPreJoinEvent(IConnectionRequest^ request);
			virtual void PlayerJoinEvent(IcPlayer^ player);
			virtual void PlayerLeaveEvent(IcPlayer^ player);
			virtual void PlayerLoadedEvent(IcPlayer^ player);
			virtual void NameChangeEvent(IcPlayer^ player);
			virtual void LevelLoadedEvent();
			virtual void RemixEvent();
			virtual void RebalanceEvent();
			virtual void SwapEvent();
			virtual void GameOverEvent();
			virtual void ConsoleOutputEvent(String^ output);
			virtual void RenLogEvent(String^ output);
			virtual void DALogEvent(String^ header, String^ output);
			virtual int CharacterPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, ISoldierGameObjDef^ item);
			virtual int VehiclePurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, IVehicleGameObjDef^ item);
			virtual int PowerUpPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, IPowerUpGameObjDef^ item);
			virtual int CustomPurchaseRequestEvent(IBaseControllerClass^ baseController, IcPlayer^ player, float% cost, unsigned int id);
			virtual void CharacterPurchaseEvent(IcPlayer^ player, float cost, ISoldierGameObjDef^ item);
			virtual void VehiclePurchaseEvent(IcPlayer^ player, float cost, IVehicleGameObjDef^ item);
			virtual void PowerUpPurchaseEvent(IcPlayer^ player, float cost, IPowerUpGameObjDef^ item);
			virtual void CustomPurchaseEvent(IcPlayer^ player, float cost, unsigned int id);
			virtual bool RefillEvent(IcPlayer^ player);
			virtual bool SuicideEvent(IcPlayer^ player);
			virtual bool TeamChangeRequestEvent(IcPlayer^ player);
			virtual void TeamChangeEvent(IcPlayer^ player);
			virtual bool VehicleEntryRequestEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int% seat);
			virtual void VehicleEnterEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int seat);
			virtual void VehicleExitEvent(IVehicleGameObj^ vehicle, IcPlayer^ player, int seat);
			virtual bool PowerUpGrantRequestEvent(IcPlayer^ player, IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj);
			virtual void PowerUpGrantEvent(IcPlayer^ player, IPowerUpGameObjDef^ powerUp, IPowerUpGameObj^ powerUpObj);
			virtual bool AddWeaponRequestEvent(IcPlayer^ player, IWeaponDefinitionClass^ weapon);
			virtual void AddWeaponEvent(IcPlayer^ player, IWeaponClass^ weapon);
			virtual void RemoveWeaponEvent(IcPlayer^ player, IWeaponClass^ weapon);
			virtual void ClearWeaponsEvent(IcPlayer^ player);
			virtual void BeaconDeployEvent(IBeaconGameObj^ beacon);
			virtual void BeaconDetonateEvent(IBeaconGameObj^ beacon);
			virtual bool C4DetonateRequestEvent(IC4GameObj^ c4, ISmartGameObj^ triggerer);
			virtual void C4DetonateEvent(IC4GameObj^ c4);
			virtual void ChangeCharacterEvent(IcPlayer^ player, ISoldierGameObjDef^ soldier);
			virtual bool VehicleFlipEvent(IVehicleGameObj^ vehicle);
			virtual bool RequestVehicleEvent(IVehicleFactoryGameObj^ factory, IVehicleGameObjDef^ vehicle, IcPlayer^ player, float delay);
			virtual void Think();
			virtual void ObjectCreatedEvent(IScriptableGameObj^ obj);
			virtual bool StockClientDamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float damage, uint warhead);
			virtual bool TTClientDamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, IAmmoDefinitionClass^ ammo, String^ bone);
			virtual bool DamageRequestEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float% damage, unsigned int% warhead, float scale, DADamageType type);
			virtual void DamageEvent(IDamageableGameObj^ victim, IArmedGameObj^ damager, float damage, unsigned int warhead, float scale, DADamageType type);
			virtual void KillEvent(IDamageableGameObj^ victim, IArmedGameObj^ killer, float damage, unsigned int warhead, float scale, DADamageType type);
			virtual void CustomEvent(IScriptableGameObj^ obj, int type, int param, IScriptableGameObj^ sender);
			virtual void PokeEvent(IcPlayer^ player, IPhysicalGameObj^ obj);
			virtual void ZoneEnterEvent(IScriptZoneGameObj^ obj, IPhysicalGameObj^ enterer);
			virtual void ZoneExitEvent(IScriptZoneGameObj^ obj, IPhysicalGameObj^ exiter);
			virtual void ObjectDestroyedEvent(IScriptableGameObj^ obj);

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

			virtual void Init(IINIClass^ ini, String^ header);
			virtual void ContestedEvent();
			virtual void CaptureEvent();
			virtual void SetContested(bool value) sealed;

			property IntPtr DABaseNodeClassPointer
			{
				virtual IntPtr get() sealed;
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

			property Vector3 Position
			{
				virtual Vector3 get() sealed;

				protected:
					void set(Vector3 value);
			}

			property String^ ObjectPreset
			{
				virtual String^ get() sealed;
			}

			property String^ ObjectModel
			{
				virtual String^ get() sealed;
			}

			property int Team
			{
				virtual int get() sealed;

				protected:
					void set(int value);
			}

			property String^ Group
			{
				virtual String^ get() sealed;

				protected:
					void set(String^ value);
			}

			property String^ Name
			{
				virtual String^ get() sealed;

				protected:
					void set(String^ value);
			}

			property bool IsContested
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

			property bool IsCapturable
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsCaptureOnce
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property String^ Type
			{
				virtual String^ get() sealed;
			}

		protected:
			void Captured(int captureTeam);
			void AttackTick(int attackTeam);
			void DefendTick();
			void UpdateIconAndRadar();
			bool IsPlayerInRange(ISoldierGameObj^ player);
			void GiveAttackDefendTickPoints(int team);
			void GiveCapturePoints();

			property ::DAEventClass* InternalDAEventClassPointer
			{
				virtual ::DAEventClass* get();
			}

			property ::DABaseNodeClass* InternalDABaseNodeClassPointer
			{
				virtual ::DABaseNodeClass* get();
			}

			property IPhysicalGameObj^ Object
			{
				IPhysicalGameObj^ get();
				void set(IPhysicalGameObj^ value);
			}

			property IPhysicalGameObj^ Icon
			{
				IPhysicalGameObj^ get();
				void set(IPhysicalGameObj^ value);
			}

			property array<IPhysicalGameObj^>^ Radar
			{
				array<IPhysicalGameObj^>^ get();
				void set(array<IPhysicalGameObj^>^ value);
			}

			property bool SentAttackMessage
			{
				bool get();
				void set(bool value);
			}

			property array<bool>^ SentDefendMessage
			{
				array<bool>^ get();
				void set(array<bool>^ value);
			}

			property unsigned long LastAttackMessage
			{
				unsigned long get();
				void set(unsigned long value);
			}

			property unsigned long LastAttackTick
			{
				unsigned long get();
				void set(unsigned long value);
			}

			property unsigned long LastDefendTick
			{
				unsigned long get();
				void set(unsigned long value);
			}

			property array<int>^ PlayerCheck
			{
				array<int>^ get();
				void set(array<int>^ value);
			}

			property int LastAttackTeam
			{
				int get();
				void set(int value);
			}

			property String^ Preset
			{
				String^ get();
				void set(String^ value);
			}

			property String^ Model
			{
				String^ get();
				void set(String^ value);
			}

			property String^ Animation
			{
				String^ get();
				void set(String^ value);
			}

			property float AttackDefendDistance
			{
				float get();
				void set(float value);
			}

			property bool IgnoreLOS
			{
				bool get();
				void set(bool value);
			}
	};
}