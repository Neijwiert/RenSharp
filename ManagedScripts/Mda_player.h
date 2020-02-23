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

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4091 4251 4244 26495 26454)
#include <da_player.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "IUnmanagedObject.h"
#include "AbstractUnmanagedObject.h"
#include "IUnmanagedContainer.h"
#include "Mengine_vector.h"
#include "Mengine_ttdef.h"
#include "Mda_event.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace RenSharp
{
	interface class IDATokenClass;
	interface class IDAPlayerObserverClass;
	interface class IcPlayer;
	interface class ISoldierGameObj;
	interface class ISoldierGameObjDef;
	interface class IVehicleGameObjDef;
	interface class IPowerUpGameObjDef;
	interface class IVehicleGameObj;
	interface class IPowerUpGameObj;
	interface class IWeaponDefinitionClass;
	interface class IWeaponClass;
	interface class IC4GameObj;
	interface class IDamageableGameObj;
	interface class IArmedGameObj;
	interface class IScriptableGameObj;
	interface class IRenSharpPlayerObserverClass;
	interface class IRenSharpPlayerDataClass;
	interface class IRenSharpPlayerDataFactoryClass;
	interface class IDAPlayerClass;

	[Flags]
	public enum class DAPlayerFlags : int
	{
		PersistLeave = ::DAPlayerFlags::PERSISTLEAVE,
		PersistMap = ::DAPlayerFlags::PERSISTMAP,
		Think = ::DAPlayerFlags::THINK,
		LegacyTag = ::DAPlayerFlags::LEGACYTAG
	};

	public interface class IDAPlayerObserverTimerStruct : public IUnmanagedObject
	{
		property IntPtr DAPlayerObserverTimerStructPointer
		{
			IntPtr get();
		}

		property unsigned long StartTime
		{
			unsigned long get();
			void set(unsigned long value);
		}

		property unsigned long Duration
		{
			unsigned long get();
			void set(unsigned long value);
		}

		property bool Repeat
		{
			bool get();
			void set(bool value);
		}

		property int Number
		{
			int get();
			void set(int value);
		}

		property unsigned int Data
		{
			unsigned int get();
			void set(unsigned int value);
		}
	};

	public ref class DAPlayerObserverTimerStruct : public AbstractUnmanagedObject, public IDAPlayerObserverTimerStruct
	{
		private:
			DAPlayerObserverTimerStruct();

		public:
			DAPlayerObserverTimerStruct(IntPtr pointer);

			bool Equals(Object ^other) override;

			static IUnmanagedContainer<IDAPlayerObserverTimerStruct ^> ^CreateDAPlayerObserverTimerStruct();

			property IntPtr DAPlayerObserverTimerStructPointer
			{
				virtual IntPtr get() sealed;
			}

			property unsigned long StartTime
			{
				virtual unsigned long get() sealed;
				virtual void set(unsigned long value) sealed;
			}

			property unsigned long Duration
			{
				virtual unsigned long get() sealed;
				virtual void set(unsigned long value) sealed;
			}

			property bool Repeat
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property int Number
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property unsigned int Data
			{
				virtual unsigned int get() sealed;
				virtual void set(unsigned int value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DAPlayerObserverTimerStruct *InternalDAPlayerObserverTimerStructPointer
			{
				virtual ::DAPlayerObserverTimerStruct *get();
			}
	};

	interface class IcPlayer;
	interface class IDAPlayerDataFactoryClass;
	interface class ISoldierGameObj;

	public interface class IDAPlayerDataClass : public IUnmanagedObject
	{
		void Init();

		void ClearLevel();

		void ClearSession();

		IRenSharpPlayerDataClass^ AsManagedPlayerData();

		property IntPtr DAPlayerDataClassPointer
		{
			IntPtr get();
		}

		property IcPlayer ^Owner
		{
			IcPlayer ^get();
			void set(IcPlayer ^value);
		}

		property IDAPlayerDataFactoryClass ^Factory
		{
			IDAPlayerDataFactoryClass ^get();
			void set(IDAPlayerDataFactoryClass ^value);
		}

		property int ID
		{
			int get();
		}

		property String ^Name
		{
			String ^get();
		}

		property ISoldierGameObj ^GameObj
		{
			ISoldierGameObj ^get();
		}

		property int Team
		{
			int get();
		}

		property bool IsManagedPlayerData
		{
			bool get();
		}
	};

	public ref class DAPlayerDataClass : public AbstractUnmanagedObject, public IDAPlayerDataClass
	{
		public:
			DAPlayerDataClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual void Init() sealed;
			virtual void ClearLevel() sealed;
			virtual void ClearSession() sealed;
			virtual IRenSharpPlayerDataClass^ AsManagedPlayerData() sealed;

			property IntPtr DAPlayerDataClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IcPlayer ^Owner
			{
				virtual IcPlayer ^get() sealed;
				virtual void set(IcPlayer ^value) sealed;
			}

			property IDAPlayerDataFactoryClass ^Factory
			{
				virtual IDAPlayerDataFactoryClass ^get() sealed;
				virtual void set(IDAPlayerDataFactoryClass ^value) sealed;
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

			property bool IsManagedPlayerData
			{
				virtual bool get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DAPlayerDataClass *InternalDAPlayerDataClassPointer
			{
				virtual ::DAPlayerDataClass *get();
			}
	};

	public interface class IDAPlayerDataFactoryClass : public IUnmanagedObject
	{
		IUnmanagedContainer<IDAPlayerDataClass ^> ^CreateData();

		IRenSharpPlayerDataFactoryClass^ AsManagedPlayerDataFactory();

		property IntPtr DAPlayerDataFactoryClassPointer
		{
			IntPtr get();
		}

		property bool IsManagedPlayerDataFactory
		{
			bool get();
		}
	};

	public ref class DAPlayerDataFactoryClass : public AbstractUnmanagedObject, public IDAPlayerDataFactoryClass
	{
		public:
			DAPlayerDataFactoryClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual IUnmanagedContainer<IDAPlayerDataClass ^> ^CreateData() sealed;
			virtual IRenSharpPlayerDataFactoryClass^ AsManagedPlayerDataFactory() sealed;

			property IntPtr DAPlayerDataFactoryClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool IsManagedPlayerDataFactory
			{
				virtual bool get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DAPlayerDataFactoryClass *InternalDAPlayerDataFactoryClassPointer
			{
				virtual ::DAPlayerDataFactoryClass *get();
			}
	};

	generic<typename T>
	public interface class IDAPlayerDataManagerClass : public IDAPlayerDataFactoryClass
	{
		T GetPlayerData(int id);

		T GetPlayerData(IScriptableGameObj^ obj);

		T GetPlayerData(IcPlayer^ player);

		T GetPlayerData(IDAPlayerClass^ player);
	};

	generic<typename T>
	public ref class DAPlayerDataManagerClass abstract : public DAPlayerDataFactoryClass, public IDAPlayerDataManagerClass<T>
	{
		public:
			DAPlayerDataManagerClass(IntPtr pointer)
				: DAPlayerDataFactoryClass(pointer)
			{

			}

			virtual T GetPlayerData(int id) = 0;
			virtual T GetPlayerData(IScriptableGameObj^ obj) = 0;
			virtual T GetPlayerData(IcPlayer^ player) = 0;
			virtual T GetPlayerData(IDAPlayerClass^ player) = 0;
	};

	public interface class IDAPlayerObserverChatCommandStruct : public IUnmanagedObject
	{
		bool Func(IDAPlayerObserverClass ^observer, IDATokenClass ^text, TextMessageEnum chatType);

		property IntPtr DAPlayerObserverChatCommandStructPointer
		{
			IntPtr get();
		}

		property IDynamicVectorClass<String ^> ^Triggers
		{
			IDynamicVectorClass<String ^> ^get();
			void set(IDynamicVectorClass<String ^> ^value);
		}

		property int Parameters
		{
			int get();
			void set(int value);
		}

		property DAChatType ChatType
		{
			DAChatType get();
			void set(DAChatType value);
		}
	};

	public ref class DAPlayerObserverChatCommandStruct : public AbstractUnmanagedObject, public IDAPlayerObserverChatCommandStruct
	{
		private:
			DAPlayerObserverChatCommandStruct();

		public:
			DAPlayerObserverChatCommandStruct(IntPtr pointer);

			static IUnmanagedContainer<IDAPlayerObserverChatCommandStruct ^> ^CreateDAPlayerObserverChatCommandStruct();

			bool Equals(Object ^other) override;

			virtual bool Func(IDAPlayerObserverClass ^observer, IDATokenClass ^text, TextMessageEnum chatType) sealed;

			property IntPtr DAPlayerObserverChatCommandStructPointer
			{
				virtual IntPtr get() sealed;
			}

			property IDynamicVectorClass<String ^> ^Triggers
			{
				virtual IDynamicVectorClass<String ^> ^get() sealed;
				virtual void set(IDynamicVectorClass<String ^> ^value) sealed;
			}

			property int Parameters
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property DAChatType ChatType
			{
				virtual DAChatType get() sealed;
				virtual void set(DAChatType value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DAPlayerObserverChatCommandStruct *InternalDAPlayerObserverChatCommandStructPointer
			{
				virtual ::DAPlayerObserverChatCommandStruct *get();
			}
	};

	public interface class IDAPlayerObserverKeyHookStruct : public IUnmanagedObject
	{
		void Func(IDAPlayerObserverClass ^observer);

		property IntPtr DAPlayerObserverKeyHookStructPointer
		{
			IntPtr get();
		}

		property IDynamicVectorClass<String ^> ^Triggers
		{
			IDynamicVectorClass<String ^> ^get();
			void set(IDynamicVectorClass<String ^> ^value);
		}
	};

	public ref class DAPlayerObserverKeyHookStruct : public AbstractUnmanagedObject, public IDAPlayerObserverKeyHookStruct
	{
		private:
			DAPlayerObserverKeyHookStruct();

		public:
			DAPlayerObserverKeyHookStruct(IntPtr pointer);

			static IUnmanagedContainer<IDAPlayerObserverKeyHookStruct ^> ^CreateDAPlayerObserverKeyHookStruct();

			bool Equals(Object ^other) override;

			virtual void Func(IDAPlayerObserverClass ^observer) sealed;

			property IntPtr DAPlayerObserverKeyHookStructPointer
			{
				virtual IntPtr get() sealed;
			}

			property IDynamicVectorClass<String ^> ^Triggers
			{
				virtual IDynamicVectorClass<String ^> ^get() sealed;
				virtual void set(IDynamicVectorClass<String ^> ^value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DAPlayerObserverKeyHookStruct *InternalDAPlayerObserverKeyHookStructPointer
			{
				virtual ::DAPlayerObserverKeyHookStruct *get();
			}
	};

	public interface class IDAPlayerObserverClass : public IUnmanagedObject
	{
		void AddFlag(DAPlayerFlags flag);

		void RemoveFlag(DAPlayerFlags flag);

		bool HasFlag(DAPlayerFlags flag);

		void StartTimer(int number, float duration, bool repeat, unsigned int data);

		void StartTimer(int number, float duration, bool repeat);

		void StartTimer(int number, float duration);

		void StopTimer(int number, unsigned int data);

		void StopTimer(int number);

		bool IsTimer(int number, unsigned int data);

		bool IsTimer(int number);

		void ClearTimers();

		void UnregisterChatCommand(String ^trigger);

		void ClearChatCommands();

		void UnregisterKeyHook(String ^trigger);

		void ClearKeyHooks();

		void Init();

		void Join();

		void Leave();

		void LevelLoaded();

		void PlayerLoaded();

		void NameChange();

		void TeamChange();

		int CharacterPurchaseRequest(float %cost, ISoldierGameObjDef ^item);

		int VehiclePurchaseRequest(float %cost, IVehicleGameObjDef ^item);

		int PowerUpPurchaseRequest(float %cost, IPowerUpGameObjDef ^item);

		int CustomPurchaseRequest(float %cost, unsigned int id);

		void CharacterPurchase(float cost, ISoldierGameObjDef ^item);

		void VehiclePurchase(float cost, IVehicleGameObjDef ^item);

		void PowerUpPurchase(float cost, IPowerUpGameObjDef ^item);

		void CustomPurchase(float cost, unsigned int id);

		bool VehicleEntryRequest(IVehicleGameObj ^vehicle, int %seat);

		void VehicleEnter(IVehicleGameObj ^vehicle, int seat);

		void VehicleExit(IVehicleGameObj ^vehicle, int seat);

		bool PowerUpGrantRequest(IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj);

		void PowerUpGrant(IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj);

		bool AddWeaponRequest(IWeaponDefinitionClass ^weapon);

		void AddWeapon(IWeaponClass ^weapon);

		void RemoveWeapon(IWeaponClass ^weapon);

		void ClearWeapons();

		bool C4DetonateRequest(IC4GameObj ^c4);

		void C4Detonate(IC4GameObj ^c4);

		void ChangeCharacter(ISoldierGameObjDef ^soldier);

		void Created();

		void Destroyed();

		bool DamageDealtRequest(IDamageableGameObj ^victim, float %damage, unsigned int %warhead, float scale, DADamageType type);

		bool DamageReceivedRequest(IArmedGameObj ^damager, float %damage, unsigned int %warhead, float scale, DADamageType type);

		void DamageDealt(IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type);

		void DamageReceived(IArmedGameObj ^damager, float damage, unsigned int warhead, float scale, DADamageType type);

		void KillDealt(IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type);

		void KillReceived(IArmedGameObj ^killer, float damage, unsigned int warhead, float scale, DADamageType type);

		void Custom(IScriptableGameObj ^sender, int type, int param);

		void Poked(IcPlayer ^player);

		void TimerExpired(int number, unsigned int data);

		void Think();

		void SetDeletePending();

		IRenSharpPlayerObserverClass^ AsManagedPlayerObserver();

		property IntPtr DAPlayerObserverClassPointer
		{
			IntPtr get();
		}

		property IcPlayer ^Owner
		{
			IcPlayer ^get();
			void set(IcPlayer ^value);
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

		property String ^Name
		{
			String ^get();
		}

		property ISoldierGameObj ^GameObj
		{
			ISoldierGameObj ^get();
		}

		property int Team
		{
			int get();
		}

		property IDynamicVectorClass<IDAPlayerObserverTimerStruct ^> ^Timers
		{
			IDynamicVectorClass<IDAPlayerObserverTimerStruct ^> ^get();
		}

		property IDynamicVectorClass<IDAPlayerObserverChatCommandStruct ^> ^ChatCommands
		{
			IDynamicVectorClass<IDAPlayerObserverChatCommandStruct ^> ^get();
		}

		property IDynamicVectorClass<IDAPlayerObserverKeyHookStruct ^> ^KeyHooks
		{
			IDynamicVectorClass<IDAPlayerObserverKeyHookStruct ^> ^get();
		}

		property bool IsDeletePending
		{
			bool get();
		}

		property String ^ObserverName
		{
			String ^get();
		}

		property bool IsManagedObserver
		{
			bool get();
		}
	};

	public ref class DAPlayerObserverClass : public AbstractUnmanagedObject, public IDAPlayerObserverClass
	{
		protected:
			DAPlayerObserverClass();

		public:
			DAPlayerObserverClass(IntPtr pointer);

			String ^ToString() override;
			bool Equals(Object ^other) override;

			virtual void AddFlag(DAPlayerFlags flag) sealed;
			virtual void RemoveFlag(DAPlayerFlags flag) sealed;
			virtual bool HasFlag(DAPlayerFlags flag) sealed;
			virtual void StartTimer(int number, float duration, bool repeat, unsigned int data) sealed;
			virtual void StartTimer(int number, float duration, bool repeat) sealed;
			virtual void StartTimer(int number, float duration) sealed;
			virtual void StopTimer(int number, unsigned int data) sealed;
			virtual void StopTimer(int number) sealed;
			virtual bool IsTimer(int number, unsigned int data) sealed;
			virtual bool IsTimer(int number) sealed;
			virtual void ClearTimers() sealed;
			virtual void UnregisterChatCommand(String ^trigger) sealed;
			virtual void ClearChatCommands() sealed;
			virtual void UnregisterKeyHook(String ^trigger) sealed;
			virtual void ClearKeyHooks() sealed;
			virtual void Init() sealed;
			virtual void Join() sealed;
			virtual void Leave() sealed;
			virtual void LevelLoaded() sealed;
			virtual void PlayerLoaded() sealed;
			virtual void NameChange() sealed;
			virtual void TeamChange() sealed;
			virtual int CharacterPurchaseRequest(float %cost, ISoldierGameObjDef ^item) sealed;
			virtual int VehiclePurchaseRequest(float %cost, IVehicleGameObjDef ^item) sealed;
			virtual int PowerUpPurchaseRequest(float %cost, IPowerUpGameObjDef ^item) sealed;
			virtual int CustomPurchaseRequest(float %cost, unsigned int id) sealed;
			virtual void CharacterPurchase(float cost, ISoldierGameObjDef ^item) sealed;
			virtual void VehiclePurchase(float cost, IVehicleGameObjDef ^item) sealed;
			virtual void PowerUpPurchase(float cost, IPowerUpGameObjDef ^item) sealed;
			virtual void CustomPurchase(float cost, unsigned int id) sealed;
			virtual bool VehicleEntryRequest(IVehicleGameObj ^vehicle, int %seat) sealed;
			virtual void VehicleEnter(IVehicleGameObj ^vehicle, int seat) sealed;
			virtual void VehicleExit(IVehicleGameObj ^vehicle, int seat) sealed;
			virtual bool PowerUpGrantRequest(IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj) sealed;
			virtual void PowerUpGrant(IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj) sealed;
			virtual bool AddWeaponRequest(IWeaponDefinitionClass ^weapon) sealed;
			virtual void AddWeapon(IWeaponClass ^weapon) sealed;
			virtual void RemoveWeapon(IWeaponClass ^weapon) sealed;
			virtual void ClearWeapons() sealed;
			virtual bool C4DetonateRequest(IC4GameObj ^c4) sealed;
			virtual void C4Detonate(IC4GameObj ^c4) sealed;
			virtual void ChangeCharacter(ISoldierGameObjDef ^soldier) sealed;
			virtual void Created() sealed;
			virtual void Destroyed() sealed;
			virtual bool DamageDealtRequest(IDamageableGameObj ^victim, float %damage, unsigned int %warhead, float scale, DADamageType type) sealed;
			virtual bool DamageReceivedRequest(IArmedGameObj ^damager, float %damage, unsigned int %warhead, float scale, DADamageType type) sealed;
			virtual void DamageDealt(IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type) sealed;
			virtual void DamageReceived(IArmedGameObj ^damager, float damage, unsigned int warhead, float scale, DADamageType type) sealed;
			virtual void KillDealt(IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type) sealed;
			virtual void KillReceived(IArmedGameObj ^killer, float damage, unsigned int warhead, float scale, DADamageType type) sealed;
			virtual void Custom(IScriptableGameObj ^sender, int type, int param) sealed;
			virtual void Poked(IcPlayer ^player) sealed;
			virtual void TimerExpired(int number, unsigned int data) sealed;
			virtual void Think() sealed;
			virtual void SetDeletePending() sealed;
			virtual IRenSharpPlayerObserverClass^ AsManagedPlayerObserver() sealed;

			property IntPtr DAPlayerObserverClassPointer
			{
				virtual IntPtr get() sealed;
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

			property IDynamicVectorClass<IDAPlayerObserverTimerStruct ^> ^Timers
			{
				virtual IDynamicVectorClass<IDAPlayerObserverTimerStruct ^> ^get() sealed;
			}

			property IDynamicVectorClass<IDAPlayerObserverChatCommandStruct ^> ^ChatCommands
			{
				virtual IDynamicVectorClass<IDAPlayerObserverChatCommandStruct ^> ^get() sealed;
			}

			property IDynamicVectorClass<IDAPlayerObserverKeyHookStruct ^> ^KeyHooks
			{
				virtual IDynamicVectorClass<IDAPlayerObserverKeyHookStruct ^> ^get() sealed;
			}

			property bool IsDeletePending
			{
				virtual bool get() sealed;
			}

			property String ^ObserverName
			{
				virtual String ^get() sealed;
			}

			property bool IsManagedObserver
			{
				virtual bool get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DAPlayerObserverClass *InternalDAPlayerObserverClassPointer
			{
				virtual ::DAPlayerObserverClass *get();
			}
	};

	public interface class IDAPlayerClass : public IUnmanagedObject
	{
		void AddObserver(IDAPlayerObserverClass ^observer);

		void AddObserver(IRenSharpPlayerObserverClass^ observer);

		void AddObserver(IUnmanagedContainer<IDAPlayerObserverClass^>^ observer);

		void RemoveObserver(String ^name);

		IDAPlayerObserverClass ^FindObserver(String ^name);

		IDAPlayerDataClass ^FindData(IDAPlayerDataFactoryClass ^factory);

		IRenSharpPlayerDataClass^ FindData(IRenSharpPlayerDataFactoryClass ^factory);

		void UpdateTag();

		void AddTag(String ^tag, int position, DAPlayerFlags flags);

		void AddTag(String ^tag, int position);

		void AddTag(String ^tag);

		void RemoveTag(String ^tag);

		void RemoveTagsWithFlag(DAPlayerFlags flag);

		void ResetLastTibDamageTime();

		void ResetCreationTime();

		void Join();

		void Leave();

		void LevelLoaded();

		void PlayerLoaded();

		void NameChange();

		bool Chat(TextMessageEnum type, String ^message, int receiverID);

		bool Radio(int playerType, int announcementID, int iconID, AnnouncementEnum announcementType);

		void TeamChange();

		int CharacterPurchaseRequest(float %cost, ISoldierGameObjDef ^item);

		int VehiclePurchaseRequest(float %cost, IVehicleGameObjDef ^item);

		int PowerUpPurchaseRequest(float %cost, IPowerUpGameObjDef ^item);

		int CustomPurchaseRequest(float %cost, unsigned int id);

		void CharacterPurchase(float cost, ISoldierGameObjDef ^item);

		void VehiclePurchase(float cost, IVehicleGameObjDef ^item);

		void PowerUpPurchase(float cost, IPowerUpGameObjDef ^item);

		void CustomPurchase(float cost, unsigned int id);

		bool VehicleEntryRequest(IVehicleGameObj ^vehicle, int %seat);

		void VehicleEnter(IVehicleGameObj ^vehicle, int seat);

		void VehicleExit(IVehicleGameObj ^vehicle, int seat);

		bool PowerUpGrantRequest(IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj);

		void PowerUpGrant(IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj);

		bool AddWeaponRequest(IWeaponDefinitionClass ^weapon);

		void AddWeapon(IWeaponClass ^weapon);

		void RemoveWeapon(IWeaponClass ^weapon);

		void ClearWeapons();

		bool C4DetonateRequest(IC4GameObj ^c4);

		void C4Detonate(IC4GameObj ^c4);

		void ChangeCharacter(ISoldierGameObjDef ^soldier);

		void Created();

		void Destroyed();

		bool DamageDealtRequest(IDamageableGameObj ^victim, float %damage, unsigned int %warhead, float scale, DADamageType type);

		bool DamageReceivedRequest(IArmedGameObj ^damager, float %damage, unsigned int %warhead, float scale, DADamageType type);

		void DamageDealt(IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type);

		void DamageReceived(IArmedGameObj ^damager, float damage, unsigned int warhead, float scale, DADamageType type);

		void KillDealt(IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type);

		void KillReceived(IArmedGameObj ^killer, float damage, unsigned int warhead, float scale, DADamageType type);

		void Custom(IScriptableGameObj ^sender, int type, int param);

		void Poked(IcPlayer ^player);

		void Think();

		property IntPtr DAPlayerClassPointer
		{
			IntPtr get();
		}

		property IcPlayer ^Owner
		{
			IcPlayer ^get();
		}

		property int ID
		{
			int get();
		}

		property String ^Name
		{
			String ^get();
		}

		property int Team
		{
			int get();
		}

		property IDynamicVectorClass<IDAPlayerObserverClass ^> ^Observers
		{
			IDynamicVectorClass<IDAPlayerObserverClass ^> ^get();
		}

		property DAAccessLevel AccessLevel
		{
			DAAccessLevel get();
			void set(DAAccessLevel value);
		}

		property bool IsMuted
		{
			bool get();
			void set(bool value);
		}

		property bool IsBeaconLocked
		{
			bool get();
			void set(bool value);
		}

		property bool IsC4Locked
		{
			bool get();
			void set(bool value);
		}

		property float CharacterDiscount
		{
			float get();
			void set(float value);
		}

		property float VehicleDiscount
		{
			float get();
			void set(float value);
		}

		property float PowerUpDiscount
		{
			float get();
			void set(float value);
		}

		property unsigned long TimeSinceLastTibDamage
		{
			unsigned long get();
		}

		property bool IsLoaded
		{
			bool get();
			void set(bool value);
		}

		property String ^Serial
		{
			String ^get();
		}

		property float Version
		{
			float get();
			void set(float value);
		}

		property unsigned int Revision
		{
			unsigned int get();
		}

		property bool IsTTClient
		{
			bool get();
		}

		property bool IsScriptsClient
		{
			bool get();
		}

		property bool IsStockClient
		{
			bool get();
		}

		property bool UseServerDamage
		{
			bool get();
			void set(bool value);
		}

		property bool IsSpawning
		{
			bool get();
		}

		property unsigned long CreationTime
		{
			unsigned long get();
		}

		property bool NeedsTeam
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class DAPlayerClass : public AbstractUnmanagedObject, public IDAPlayerClass
	{
		private:
			static Generic::IDictionary<IntPtr, IRenSharpPlayerObserverClass^ > ^managedPlayerObservers;

		public:
			static DAPlayerClass();
			DAPlayerClass(IntPtr pointer);

			String ^ToString() override;
			bool Equals(Object ^other) override;

			static void OnManagedPlayerObserverDestructed(IntPtr observer);
			static bool IsManagedPlayerObserver(IntPtr observer);
			static bool IsManagedPlayerObserver(IDAPlayerObserverClass ^observer);
			static IRenSharpPlayerObserverClass^ AsManagedPlayerObserver(IntPtr observerPtr);
			static IRenSharpPlayerObserverClass^ AsManagedPlayerObserver(IDAPlayerObserverClass ^observer);

			virtual void AddObserver(IDAPlayerObserverClass ^observer) sealed;
			virtual void AddObserver(IRenSharpPlayerObserverClass^ observer) sealed;
			virtual void AddObserver(IUnmanagedContainer<IDAPlayerObserverClass^>^ observer) sealed;
			virtual void RemoveObserver(String ^name) sealed;
			virtual IDAPlayerObserverClass ^FindObserver(String ^name) sealed;
			virtual IDAPlayerDataClass ^FindData(IDAPlayerDataFactoryClass ^factory) sealed;
			virtual IRenSharpPlayerDataClass^ FindData(IRenSharpPlayerDataFactoryClass^ factory) sealed;
			virtual void UpdateTag() sealed;
			virtual void AddTag(String ^tag, int position, DAPlayerFlags flags) sealed;
			virtual void AddTag(String ^tag, int position) sealed;
			virtual void AddTag(String ^tag) sealed;
			virtual void RemoveTag(String ^tag) sealed;
			virtual void RemoveTagsWithFlag(DAPlayerFlags flag) sealed;
			virtual void ResetLastTibDamageTime() sealed;
			virtual void ResetCreationTime() sealed;
			virtual void Join() sealed;
			virtual void Leave() sealed;
			virtual void LevelLoaded() sealed;
			virtual void PlayerLoaded() sealed;
			virtual void NameChange() sealed;
			virtual bool Chat(TextMessageEnum type, String ^message, int receiverID) sealed;
			virtual bool Radio(int playerType, int announcementID, int iconID, AnnouncementEnum announcementType) sealed;
			virtual void TeamChange() sealed;
			virtual int CharacterPurchaseRequest(float %cost, ISoldierGameObjDef ^item) sealed;
			virtual int VehiclePurchaseRequest(float %cost, IVehicleGameObjDef ^item) sealed;
			virtual int PowerUpPurchaseRequest(float %cost, IPowerUpGameObjDef ^item) sealed;
			virtual int CustomPurchaseRequest(float %cost, unsigned int id) sealed;
			virtual void CharacterPurchase(float cost, ISoldierGameObjDef ^item) sealed;
			virtual void VehiclePurchase(float cost, IVehicleGameObjDef ^item) sealed;
			virtual void PowerUpPurchase(float cost, IPowerUpGameObjDef ^item) sealed;
			virtual void CustomPurchase(float cost, unsigned int id) sealed;
			virtual bool VehicleEntryRequest(IVehicleGameObj ^vehicle, int %seat) sealed;
			virtual void VehicleEnter(IVehicleGameObj ^vehicle, int seat) sealed;
			virtual void VehicleExit(IVehicleGameObj ^vehicle, int seat) sealed;
			virtual bool PowerUpGrantRequest(IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj) sealed;
			virtual void PowerUpGrant(IPowerUpGameObjDef ^powerUp, IPowerUpGameObj ^powerUpObj) sealed;
			virtual bool AddWeaponRequest(IWeaponDefinitionClass ^weapon) sealed;
			virtual void AddWeapon(IWeaponClass ^weapon) sealed;
			virtual void RemoveWeapon(IWeaponClass ^weapon) sealed;
			virtual void ClearWeapons() sealed;
			virtual bool C4DetonateRequest(IC4GameObj ^c4) sealed;
			virtual void C4Detonate(IC4GameObj ^c4) sealed;
			virtual void ChangeCharacter(ISoldierGameObjDef ^soldier) sealed;
			virtual void Created() sealed;
			virtual void Destroyed() sealed;
			virtual bool DamageDealtRequest(IDamageableGameObj ^victim, float %damage, unsigned int %warhead, float scale, DADamageType type) sealed;
			virtual bool DamageReceivedRequest(IArmedGameObj ^damager, float %damage, unsigned int %warhead, float scale, DADamageType type) sealed;
			virtual void DamageDealt(IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type) sealed;
			virtual void DamageReceived(IArmedGameObj ^damager, float damage, unsigned int warhead, float scale, DADamageType type) sealed;
			virtual void KillDealt(IDamageableGameObj ^victim, float damage, unsigned int warhead, float scale, DADamageType type) sealed;
			virtual void KillReceived(IArmedGameObj ^killer, float damage, unsigned int warhead, float scale, DADamageType type) sealed;
			virtual void Custom(IScriptableGameObj ^sender, int type, int param) sealed;
			virtual void Poked(IcPlayer ^player) sealed;
			virtual void Think() sealed;

			property IntPtr DAPlayerClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IcPlayer ^Owner
			{
				virtual IcPlayer ^get() sealed;
			}

			property int ID
			{
				virtual int get() sealed;
			}

			property String ^Name
			{
				virtual String ^get() sealed;
			}

			property int Team
			{
				virtual int get() sealed;
			}

			property IDynamicVectorClass<IDAPlayerObserverClass ^> ^Observers
			{
				virtual IDynamicVectorClass<IDAPlayerObserverClass ^> ^get() sealed;
			}

			property DAAccessLevel AccessLevel
			{
				virtual DAAccessLevel get() sealed;
				virtual void set(DAAccessLevel value) sealed;
			}

			property bool IsMuted
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsBeaconLocked
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsC4Locked
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property float CharacterDiscount
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float VehicleDiscount
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float PowerUpDiscount
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property unsigned long TimeSinceLastTibDamage
			{
				virtual unsigned long get() sealed;
			}

			property bool IsLoaded
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property String ^Serial
			{
				virtual String ^get() sealed;
			}

			property float Version
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property unsigned int Revision
			{
				virtual unsigned int get() sealed;
			}

			property bool IsTTClient
			{
				virtual bool get() sealed;
			}

			property bool IsScriptsClient
			{
				virtual bool get() sealed;
			}

			property bool IsStockClient
			{
				virtual bool get() sealed;
			}

			property bool UseServerDamage
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsSpawning
			{
				virtual bool get() sealed;
			}

			property unsigned long CreationTime
			{
				virtual unsigned long get() sealed;
			}

			property bool NeedsTeam
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		internal:
			static void Shutdown();

			static void RegisterManagedObserver(IRenSharpPlayerObserverClass^ observer);
			static void UnregisterManagedObserver(IRenSharpPlayerObserverClass^ observer);

		protected:
			property ::DAPlayerClass *InternalDAPlayerClassPointer
			{
				virtual ::DAPlayerClass *get();
			}
	};

	public interface class IDAPlayerManager : public IDAEventClass
	{
		property IntPtr DAPlayerManagerPointer
		{
			IntPtr get();
		}
	};

	public ref class DAPlayerManager : public DAEventClass, public IDAPlayerManager
	{
		private:
			static Generic::IDictionary<IntPtr, IRenSharpPlayerDataFactoryClass^>^ managedPlayerDataFactories;
			static Generic::IDictionary<IntPtr, IRenSharpPlayerDataClass^>^ managedPlayerDatas;

			static DAPlayerManager();

		// Although you can instantiate a DAPlayerManager class, it doesn't make any sense so I left it out
		public:
			DAPlayerManager(IntPtr pointer);

			static void OnManagedPlayerDataFactoryDestructed(IntPtr factory);
			static bool IsManagedPlayerDataFactory(IntPtr factory);
			static bool IsManagedPlayerDataFactory(IDAPlayerDataFactoryClass^ factory);
			static IRenSharpPlayerDataFactoryClass^ AsManagedPlayerDataFactory(IntPtr factory);
			static IRenSharpPlayerDataFactoryClass^ AsManagedPlayerDataFactory(IDAPlayerDataFactoryClass^ factory);
			static void OnManagedPlayerDataDestructed(IntPtr playerData);
			static bool IsManagedPlayerData(IntPtr playerData);
			static bool IsManagedPlayerData(IDAPlayerDataClass^ playerData);
			static IRenSharpPlayerDataClass^ AsManagedPlayerData(IntPtr playerData);
			static IRenSharpPlayerDataClass^ AsManagedPlayerData(IDAPlayerDataClass^ playerData);

			static void AddDataFactory(IDAPlayerDataFactoryClass^ factory);
			static void RemoveDataFactory(IDAPlayerDataFactoryClass^ factory);
			static void AddDataFactory(IRenSharpPlayerDataFactoryClass^ factory);
			static void RemoveDataFactory(IRenSharpPlayerDataFactoryClass^ factory);

			property IntPtr DAPlayerManagerPointer
			{
				virtual IntPtr get() sealed;
			}

			static property bool DisableKillMessages
			{
				bool get();
				void set(bool value);
			}

			static property bool DisableKillCounter
			{
				bool get();
				void set(bool value);
			}

			static property bool DisableTeamKillCounter
			{
				bool get();
				void set(bool value);
			}

			static property bool DisableDeathCounter
			{
				bool get();
				void set(bool value);
			}

			static property bool DisableTeamDeathCounter
			{
				bool get();
				void set(bool value);
			}

			static property bool DisableDamagePoints
			{
				bool get();
				void set(bool value);
			}

			static property bool DisableDeathPoints
			{
				bool get();
				void set(bool value);
			}

			static property bool DisableTeamScoreCounter
			{
				bool get();
				void set(bool value);
			}

			static property float CreditsMultiplier
			{
				float get();
				void set(float value);
			}

		internal:
			static void Shutdown();

			static void RegisterManagedPlayerDataFactory(IRenSharpPlayerDataFactoryClass^ factory);
			static void RegisterManagedPlayerData(IRenSharpPlayerDataClass^ playerData);
			static void UnregisterManagedPlayerDataFactory(IRenSharpPlayerDataFactoryClass^ factory);
			static void UnregisterManagedPlayerData(IRenSharpPlayerDataClass^ playerData);

		protected:
			property ::DAEventClass* InternalDAEventClassPointer
			{
				::DAEventClass* get() override;
			}

			property ::DAPlayerManager* InternalDAPlayerManagerPointer
			{
				virtual ::DAPlayerManager* get();
			}
	};
}