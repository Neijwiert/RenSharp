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

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_ssgm.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	interface class IINIClass;

	public ref class SSGMGameLog abstract sealed
	{
		public:
			static void Init(unsigned short port);
			static void LogMessage(String^ message, String^ category);
			static void LogGamelog(String^ format, ...array<Object^>^ args);
			static void LogRenLog(String^ message);
			static void LogCustom(int id, String^ format, ...array<Object^>^ args);
			static void SendConsole(String^ message);
			static void Shutdown();
			static void Think();
			static void Send(String^ data);
	};

	public enum class EventType : int
	{
		EventGlobalINI = ::EVENT_GLOBAL_INI,
		EventMapINI = ::EVENT_MAP_INI,
		EventChatHook = ::EVENT_CHAT_HOOK,
		EventObjectCreateHook = ::EVENT_OBJECT_CREATE_HOOK,
		EventLoadLevelHook = ::EVENT_LOAD_LEVEL_HOOK,
		EventGameOverHook = ::EVENT_GAME_OVER_HOOK,
		EventPlayerJoinHook = ::EVENT_PLAYER_JOIN_HOOK,
		EventPlayerLeaveHook = ::EVENT_PLAYER_LEAVE_HOOK,
		EventRefillHook = ::EVENT_REFILL_HOOK,
		EventPowerUpPurchaseHook = ::EVENT_POWERUP_PURCHASE_HOOK,
		EventVehiclePurchaseHook = ::EVENT_VEHICLE_PURCHASE_HOOK,
		EventCharacterPurchaseHook = ::EVENT_CHARACTER_PURCHASE_HOOK,
		EventThinkHook = ::EVENT_THINK_HOOK,
		EventRadioHook = ::EVENT_RADIO_HOOK,
		EventStockDamageHook = ::EVENT_STOCK_DAMAGE_HOOK,
		EventTTDamageHook = ::EVENT_TT_DAMAGE_HOOK,
		EventPreLoadLevelHook = ::EVENT_PRE_LOAD_LEVEL_HOOK
	};

	public interface class IPlugin : public IUnmanagedObject
	{
		void OnLoadGlobalINISettings(IINIClass^ ssgmINI);

		void OnFreeData();

		void OnLoadMapINISettings(IINIClass^ ssgmINI);

		void OnFreeMapData();

		bool OnChat(int playerID, TextMessageEnum type, String^ message, int recieverID);

		void OnObjectCreate(IntPtr data, IScriptableGameObj^ obj);

		void OnLoadLevel();

		void OnGameOver();

		void OnPlayerJoin(int playerID, String^ playerName);

		void OnPlayerLeave(int playerID);

		bool OnRefill(IScriptableGameObj^ purchaser);

		int OnPowerupPurchase(IBaseControllerClass^ base, IScriptableGameObj^ purchaser, unsigned int cost, unsigned int preset, IntPtr data);

		int OnVehiclePurchase(IBaseControllerClass^ base, IScriptableGameObj^ purchaser, unsigned int cost, unsigned int preset, IntPtr data);

		int OnCharacterPurchase(IBaseControllerClass^  base, IScriptableGameObj^ purchaser, unsigned int cost, unsigned int preset, IntPtr data);

		void OnThink();

		bool OnRadioCommand(int playerType, int playerID, int announcementID, int iconID, AnnouncementEnum announcementType);

		bool OnStockDamage(IPhysicalGameObj^ damager, IPhysicalGameObj^ target, float damage, uint warheadId);

		bool OnTtDamage(IPhysicalGameObj^ damager, IPhysicalGameObj^ target, IAmmoDefinitionClass^ ammo, String^ bone);

		void OnPreLoadLevel();

		property IntPtr PluginPointer
		{
			IntPtr get();
		}

		property float Version
		{
			float get();
		}
	};

	public ref class Plugin : public AbstractUnmanagedObject, public IPlugin
	{
		// Disallow instantiating this class
		public:
			Plugin(IntPtr pointer);

			bool Equals(Object^ other) override;

			virtual void OnLoadGlobalINISettings(IINIClass^ ssgmINI) sealed;
			virtual void OnFreeData() sealed;
			virtual void OnLoadMapINISettings(IINIClass^ ssgmINI) sealed;
			virtual void OnFreeMapData() sealed;
			virtual bool OnChat(int playerID, TextMessageEnum type, String^ message, int recieverID) sealed;
			virtual void OnObjectCreate(IntPtr data, IScriptableGameObj^ obj) sealed;
			virtual void OnLoadLevel() sealed;
			virtual void OnGameOver() sealed;
			virtual void OnPlayerJoin(int playerID, String^ playerName) sealed;
			virtual void OnPlayerLeave(int playerID) sealed;
			virtual bool OnRefill(IScriptableGameObj^ purchaser) sealed;
			virtual int OnPowerupPurchase(IBaseControllerClass^ base, IScriptableGameObj^ purchaser, unsigned int cost, unsigned int preset, IntPtr data) sealed;
			virtual int OnVehiclePurchase(IBaseControllerClass^ base, IScriptableGameObj^ purchaser, unsigned int cost, unsigned int preset, IntPtr data) sealed;
			virtual int OnCharacterPurchase(IBaseControllerClass^ base, IScriptableGameObj^ purchaser, unsigned int cost, unsigned int preset, IntPtr data) sealed;
			virtual void OnThink() sealed;
			virtual bool OnRadioCommand(int playerType, int playerID, int announcementID, int iconID, AnnouncementEnum announcementType) sealed;
			virtual bool OnStockDamage(IPhysicalGameObj^ damager, IPhysicalGameObj^ target, float damage, uint warheadId) sealed;
			virtual bool OnTtDamage(IPhysicalGameObj^ damager, IPhysicalGameObj^ target, IAmmoDefinitionClass^ ammo, String^ bone) sealed;
			virtual void OnPreLoadLevel() sealed;

			property IntPtr PluginPointer
			{
				virtual IntPtr get() sealed;
			}

			property float Version
			{
				virtual float get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::Plugin* InternalPluginPointer
			{
				virtual ::Plugin* get();
			}
	};

	public interface class IDASSGMPluginManager : public IDAEventClass
	{
		property IntPtr DASSGMPluginManagerPointer
		{
			IntPtr get();
		}
	};

	public ref class DASSGMPluginManager : public DAEventClass, public IDASSGMPluginManager
	{
		// Although you can instantiate a DASSGMPluginManager class, it doesn't make any sense so I left it out
		public:
			DASSGMPluginManager(IntPtr pointer);

			property IntPtr DASSGMPluginManagerPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::DAEventClass* InternalDAEventClassPointer
			{
				::DAEventClass* get() override;
			}

			property ::DASSGMPluginManager* InternalDASSGMPluginManagerPointer
			{
				virtual ::DASSGMPluginManager* get();
			}
	};
}