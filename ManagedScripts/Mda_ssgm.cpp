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
#include "Mda_ssgm.h"

#include "Mengine_io.h"
#include "MScriptableGameObj.h"
#include "MBaseControllerClass.h"
#include "MPhysicalGameObj.h"
#include "Mweaponmgr.h"

namespace RenSharp
{
	void SSGMGameLog::Init(unsigned short port)
	{
		::SSGMGameLog::Init(port);
	}

	void SSGMGameLog::LogMessage(String^ message, String^ category)
	{
		if (message == nullptr)
		{
			throw gcnew ArgumentNullException("message");
		}
		else if (category == nullptr)
		{
			throw gcnew ArgumentNullException("category");
		}

		IntPtr messageHandle = Marshal::StringToHGlobalAnsi(message);
		try
		{
			IntPtr categoryHandle = Marshal::StringToHGlobalAnsi(category);
			try
			{
				::SSGMGameLog::Log_Message(
					reinterpret_cast<char*>(messageHandle.ToPointer()),
					reinterpret_cast<char*>(categoryHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(categoryHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(messageHandle);
		}
	}

	void SSGMGameLog::LogGamelog(String^ format, ...array<Object^>^ args)
	{
		if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::SSGMGameLog::Log_Gamelog(
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void SSGMGameLog::LogRenLog(String^ message)
	{
		if (message == nullptr)
		{
			throw gcnew ArgumentNullException("message");
		}

		IntPtr messageHandle = Marshal::StringToHGlobalAnsi(message);
		try
		{
			::SSGMGameLog::Log_RenLog(
				reinterpret_cast<char*>(messageHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(messageHandle);
		}
	}

	void SSGMGameLog::LogCustom(int id, String^ format, ...array<Object^>^ args)
	{
		if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			::SSGMGameLog::Log_Custom(
				id,
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void SSGMGameLog::SendConsole(String^ message)
	{
		if (message == nullptr)
		{
			throw gcnew ArgumentNullException("message");
		}

		IntPtr messageHandle = Marshal::StringToHGlobalAnsi(message);
		try
		{
			::SSGMGameLog::Send_Console(
				reinterpret_cast<char*>(messageHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(messageHandle);
		}
	}

	void SSGMGameLog::Shutdown()
	{
		::SSGMGameLog::Shutdown();
	}

	void SSGMGameLog::Think()
	{
		::SSGMGameLog::Think();
	}

	void SSGMGameLog::Send(String^ data)
	{
		if (data == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		IntPtr dataHandle = Marshal::StringToHGlobalAnsi(data);
		try
		{
			::SSGMGameLog::Send(
				reinterpret_cast<char*>(dataHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(dataHandle);
		}
	}

	Plugin::Plugin(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool Plugin::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IPlugin^ otherThis = dynamic_cast<IPlugin^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return PluginPointer.Equals(otherThis->PluginPointer);
	}

	void Plugin::OnLoadGlobalINISettings(IINIClass^ ssgmINI)
	{
		if (ssgmINI == nullptr || ssgmINI->INIClassPointer.ToPointer() == nullptr)
		{
			InternalPluginPointer->OnLoadGlobalINISettings(nullptr);
		}
		else
		{
			InternalPluginPointer->OnLoadGlobalINISettings(
				reinterpret_cast<::INIClass*>(ssgmINI->INIClassPointer.ToPointer()));
		}
	}

	void Plugin::OnFreeData()
	{
		InternalPluginPointer->OnFreeData();
	}

	void Plugin::OnLoadMapINISettings(IINIClass^ ssgmINI)
	{
		if (ssgmINI == nullptr || ssgmINI->INIClassPointer.ToPointer() == nullptr)
		{
			InternalPluginPointer->OnLoadGlobalINISettings(nullptr);
		}
		else
		{
			InternalPluginPointer->OnLoadMapINISettings(
				reinterpret_cast<::INIClass*>(ssgmINI->INIClassPointer.ToPointer()));
		}
	}

	void Plugin::OnFreeMapData()
	{
		InternalPluginPointer->OnFreeMapData();
	}

	bool Plugin::OnChat(int playerID, TextMessageEnum type, String^ message, int recieverID)
	{
		if (message == nullptr)
		{
			return InternalPluginPointer->OnChat(
				playerID,
				static_cast<::TextMessageEnum>(type),
				nullptr,
				recieverID);
		}
		else
		{
			IntPtr messageHandle = Marshal::StringToHGlobalUni(message);
			try
			{
				return InternalPluginPointer->OnChat(
					playerID,
					static_cast<::TextMessageEnum>(type),
					reinterpret_cast<wchar_t*>(messageHandle.ToPointer()),
					recieverID);
			}
			finally
			{
				Marshal::FreeHGlobal(messageHandle);
			}
		}
	}

	void Plugin::OnObjectCreate(IntPtr data, IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			InternalPluginPointer->OnObjectCreate(data.ToPointer(), nullptr);
		}
		else
		{
			InternalPluginPointer->OnObjectCreate(
				data.ToPointer(),
				reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
		}
	}

	void Plugin::OnLoadLevel()
	{
		InternalPluginPointer->OnLoadLevel();
	}

	void Plugin::OnGameOver()
	{
		InternalPluginPointer->OnGameOver();
	}

	void Plugin::OnPlayerJoin(int playerID, String^ playerName)
	{
		if (playerName == nullptr)
		{
			InternalPluginPointer->OnPlayerJoin(playerID, nullptr);
		}
		else
		{
			IntPtr playerNameHandle = Marshal::StringToHGlobalAnsi(playerName);
			try
			{
				InternalPluginPointer->OnPlayerJoin(
					playerID,
					reinterpret_cast<char*>(playerNameHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(playerNameHandle);
			}
		}
	}

	void Plugin::OnPlayerLeave(int playerID)
	{
		InternalPluginPointer->OnPlayerLeave(playerID);
	}

	bool Plugin::OnRefill(IScriptableGameObj^ purchaser)
	{
		if (purchaser == nullptr || purchaser->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			return InternalPluginPointer->OnRefill(nullptr);
		}
		else
		{
			return InternalPluginPointer->OnRefill(
				reinterpret_cast<::ScriptableGameObj*>(purchaser->ScriptableGameObjPointer.ToPointer()));
		}
	}

	int Plugin::OnPowerupPurchase(IBaseControllerClass^ base, IScriptableGameObj^ purchaser, unsigned int cost, unsigned int preset, IntPtr data)
	{
		::BaseControllerClass* basePtr;
		if (base == nullptr || base->BaseControllerClassPointer.ToPointer() == nullptr)
		{
			basePtr = nullptr;
		}
		else
		{
			basePtr = reinterpret_cast<::BaseControllerClass*>(base->BaseControllerClassPointer.ToPointer());
		}

		::ScriptableGameObj* purchaserPtr;
		if (purchaser == nullptr || purchaser->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			purchaserPtr = nullptr;
		}
		else
		{
			purchaserPtr = reinterpret_cast<::ScriptableGameObj*>(purchaser->ScriptableGameObjPointer.ToPointer());
		}

		return InternalPluginPointer->OnPowerupPurchase(
			basePtr,
			purchaserPtr,
			cost,
			preset,
			reinterpret_cast<char *>(data.ToPointer()));
	}

	int Plugin::OnVehiclePurchase(IBaseControllerClass^ base, IScriptableGameObj^ purchaser, unsigned int cost, unsigned int preset, IntPtr data)
	{
		::BaseControllerClass* basePtr;
		if (base == nullptr || base->BaseControllerClassPointer.ToPointer() == nullptr)
		{
			basePtr = nullptr;
		}
		else
		{
			basePtr = reinterpret_cast<::BaseControllerClass*>(base->BaseControllerClassPointer.ToPointer());
		}

		::ScriptableGameObj* purchaserPtr;
		if (purchaser == nullptr || purchaser->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			purchaserPtr = nullptr;
		}
		else
		{
			purchaserPtr = reinterpret_cast<::ScriptableGameObj*>(purchaser->ScriptableGameObjPointer.ToPointer());
		}

		return InternalPluginPointer->OnVehiclePurchase(
			basePtr,
			purchaserPtr,
			cost,
			preset,
			reinterpret_cast<char*>(data.ToPointer()));
	}

	int Plugin::OnCharacterPurchase(IBaseControllerClass^ base, IScriptableGameObj^ purchaser, unsigned int cost, unsigned int preset, IntPtr data)
	{
		::BaseControllerClass* basePtr;
		if (base == nullptr || base->BaseControllerClassPointer.ToPointer() == nullptr)
		{
			basePtr = nullptr;
		}
		else
		{
			basePtr = reinterpret_cast<::BaseControllerClass*>(base->BaseControllerClassPointer.ToPointer());
		}

		::ScriptableGameObj* purchaserPtr;
		if (purchaser == nullptr || purchaser->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			purchaserPtr = nullptr;
		}
		else
		{
			purchaserPtr = reinterpret_cast<::ScriptableGameObj*>(purchaser->ScriptableGameObjPointer.ToPointer());
		}

		return InternalPluginPointer->OnCharacterPurchase(
			basePtr,
			purchaserPtr,
			cost,
			preset,
			reinterpret_cast<char*>(data.ToPointer()));
	}

	void Plugin::OnThink()
	{
		InternalPluginPointer->OnThink();
	}

	bool Plugin::OnRadioCommand(int playerType, int playerID, int announcementID, int iconID, AnnouncementEnum announcementType)
	{
		return InternalPluginPointer->OnRadioCommand(
			playerType,
			playerID,
			announcementID,
			iconID,
			static_cast<::AnnouncementEnum>(announcementType));
	}

	bool Plugin::OnStockDamage(IPhysicalGameObj^ damager, IPhysicalGameObj^ target, float damage, uint warheadId)
	{
		::PhysicalGameObj* damagerPtr;
		if (damager == nullptr || damager->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			damagerPtr = nullptr;
		}
		else
		{
			damagerPtr = reinterpret_cast<::PhysicalGameObj*>(damager->PhysicalGameObjPointer.ToPointer());
		}

		::PhysicalGameObj* targetPtr;
		if (target == nullptr || target->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			targetPtr = nullptr;
		}
		else
		{
			targetPtr = reinterpret_cast<::PhysicalGameObj*>(target->PhysicalGameObjPointer.ToPointer());
		}

		return InternalPluginPointer->OnStockDamage(
			damagerPtr,
			targetPtr,
			damage,
			warheadId);
	}

	bool Plugin::OnTtDamage(IPhysicalGameObj^ damager, IPhysicalGameObj^ target, IAmmoDefinitionClass^ ammo, String^ bone)
	{
		::PhysicalGameObj* damagerPtr;
		if (damager == nullptr || damager->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			damagerPtr = nullptr;
		}
		else
		{
			damagerPtr = reinterpret_cast<::PhysicalGameObj*>(damager->PhysicalGameObjPointer.ToPointer());
		}

		::PhysicalGameObj* targetPtr;
		if (target == nullptr || target->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			targetPtr = nullptr;
		}
		else
		{
			targetPtr = reinterpret_cast<::PhysicalGameObj*>(target->PhysicalGameObjPointer.ToPointer());
		}

		::AmmoDefinitionClass* ammoPtr;
		if (ammo == nullptr || ammo->AmmoDefinitionClassPointer.ToPointer() == nullptr)
		{
			ammoPtr = nullptr;
		}
		else
		{
			ammoPtr = reinterpret_cast<::AmmoDefinitionClass*>(ammo->AmmoDefinitionClassPointer.ToPointer());
		}

		if (bone == nullptr)
		{
			return InternalPluginPointer->OnTtDamage(
				damagerPtr,
				targetPtr,
				ammoPtr,
				nullptr);
		}
		else
		{
			IntPtr boneHandle = Marshal::StringToHGlobalAnsi(bone);
			try
			{
				return InternalPluginPointer->OnTtDamage(
					damagerPtr,
					targetPtr,
					ammoPtr,
					reinterpret_cast<char*>(boneHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(boneHandle);
			}
		}
	}

	void Plugin::OnPreLoadLevel()
	{
		InternalPluginPointer->OnPreLoadLevel();
	}

	IntPtr Plugin::PluginPointer::get()
	{
		return IntPtr(InternalPluginPointer);
	}

	float Plugin::Version::get()
	{
		return InternalPluginPointer->Get_Version();
	}

	bool Plugin::InternalDestroyPointer()
	{
		Imports::DestroyPlugin(InternalPluginPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::Plugin* Plugin::InternalPluginPointer::get()
	{
		return reinterpret_cast<::Plugin*>(Pointer.ToPointer());
	}

	DASSGMPluginManager::DASSGMPluginManager(IntPtr pointer)
		: DAEventClass(pointer)
	{

	}

	IntPtr DASSGMPluginManager::DASSGMPluginManagerPointer::get()
	{
		return IntPtr(InternalDASSGMPluginManagerPointer);
	}

	::DAEventClass* DASSGMPluginManager::InternalDAEventClassPointer::get()
	{
		return InternalDASSGMPluginManagerPointer;
	}

	::DASSGMPluginManager* DASSGMPluginManager::InternalDASSGMPluginManagerPointer::get()
	{
		return reinterpret_cast<::DASSGMPluginManager*>(Pointer.ToPointer());
	}
}