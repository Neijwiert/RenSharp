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
#include "RenSharpKeyHookManager.h"

#include "McPlayer.h"
#include "Mda_token.h"
#include "Mda_player.h"
#include "Mda.h"
#include "RenSharpKeyHookClass.h"
#include "Imports.h"

using namespace System::Text;

namespace RenSharp
{
	static RenSharpKeyHookManager::RenSharpKeyHookManager()
	{
		keyHooks = gcnew Collections::Generic::Dictionary<IKeyHookInterface^, array<Collections::Generic::IList<RenSharpKeyHookStruct^>^>^>();
		globalKeyHooks = gcnew Collections::Generic::List<RenSharpKeyHookClass^>();
	}

	RenSharpKeyHookManager::RenSharpKeyHookManager()
		: disposedResources(false)
	{

	}

	RenSharpKeyHookManager::~RenSharpKeyHookManager()
	{
		if (disposedResources)
		{
			return;
		}

		keyHooks->Clear();

		auto tmpGlobalKeyHooks = gcnew Collections::Generic::List<RenSharpKeyHookClass^>(globalKeyHooks);

		for each (auto keyHook in tmpGlobalKeyHooks)
		{
#pragma push_macro("delete")
#undef delete

			delete keyHook;

#pragma push_macro("delete")
		}

		tmpGlobalKeyHooks->Clear();
		globalKeyHooks->Clear();

		disposedResources = true;
	}

	void RenSharpKeyHookManager::UnmanagedAttach()
	{
		RegisterEvent(DAEventType::KeyHook, Int32::MaxValue);
	}

	bool RenSharpKeyHookManager::KeyHookEvent(IcPlayer^ player, String^ key)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}

		for each (auto groupedKeyHooks in keyHooks->Values)
		{
			for each (auto keyHookCollection in groupedKeyHooks)
			{
				switch (CheckKeyHooks(keyHookCollection, player, key))
				{
					case CheckKeyHookResult::FoundReturnTrue:
						return true;
					case CheckKeyHookResult::FoundReturnFalse:
						return false;
				}
			}
		}

		for each (auto keyHook in globalKeyHooks)
		{
			switch (CheckKeyHook(keyHook, player, key))
			{
				case CheckKeyHookResult::FoundReturnTrue:
					return true;
				case CheckKeyHookResult::FoundReturnFalse:
					return false;
			}
		}

		return true;
	}

	void RenSharpKeyHookManager::UnregisterKeyHook(String^ trigger)
	{
		if (trigger == nullptr)
		{
			throw gcnew ArgumentNullException("trigger");
		}

		for (int keyHookIndex = globalKeyHooks->Count - 1; keyHookIndex >= 0; keyHookIndex--)
		{
			auto keyHook = globalKeyHooks[keyHookIndex];
			if (keyHook->HasTrigger(trigger))
			{
				globalKeyHooks->RemoveAt(keyHookIndex);

#pragma push_macro("delete")
#undef delete

				delete keyHook;
				keyHook = nullptr;

#pragma push_macro("delete")
			}
		}
	}

	void RenSharpKeyHookManager::RegisterKeyHook(RenSharpKeyHookClass^ keyHook)
	{
		if (keyHook == nullptr)
		{
			throw gcnew ArgumentNullException("keyHook");
		}
		else if (Imports::IsShuttingDown())
		{
			throw gcnew NotSupportedException("Engine is shutting down");
		}

		globalKeyHooks->Add(keyHook);
	}

	void RenSharpKeyHookManager::UnregisterKeyHook(RenSharpKeyHookClass^ keyHook)
	{
		if (keyHook == nullptr)
		{
			throw gcnew ArgumentNullException("keyHook");
		}

		globalKeyHooks->Remove(keyHook);
	}

	RenSharpKeyHookStruct^ RenSharpKeyHookManager::RegisterKeyHook(IKeyHookInterface^ owner, KeyHookGroup group, RenSharpKHDelegate^ func, String^ triggers, Object^ data)
	{
		if (owner == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}

		RenSharpKeyHookStruct^ newKeyHook = gcnew RenSharpKeyHookStruct(owner, func, triggers, data);

		array<Collections::Generic::IList<RenSharpKeyHookStruct^>^>^ groupedKeyHooks;
		if (!keyHooks->TryGetValue(owner, groupedKeyHooks))
		{
			groupedKeyHooks = gcnew array<Collections::Generic::IList<RenSharpKeyHookStruct^>^>(Enum::GetValues(KeyHookGroup::typeid)->Length);
			for (int x = 0; x < groupedKeyHooks->Length; x++)
			{
				groupedKeyHooks[x] = gcnew Collections::Generic::List<RenSharpKeyHookStruct^>();
			}

			keyHooks->Add(owner, groupedKeyHooks);
		}

		groupedKeyHooks[static_cast<int>(group)]->Add(newKeyHook);

		return newKeyHook;
	}

	RenSharpKeyHookStruct^ RenSharpKeyHookManager::RegisterKeyHook(IKeyHookInterface^ owner, KeyHookGroup group, RenSharpKHDelegate^ func, String^ triggers)
	{
		return RegisterKeyHook(owner, group, func, triggers, nullptr);
	}

	void RenSharpKeyHookManager::UnregisterKeyHook(IKeyHookInterface^ owner, KeyHookGroup group, String^ trigger)
	{
		if (owner == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}
		else if (trigger == nullptr)
		{
			throw gcnew ArgumentNullException("trigger");
		}

		array<Collections::Generic::IList<RenSharpKeyHookStruct^>^>^ groupedKeyHooks;
		if (keyHooks->TryGetValue(owner, groupedKeyHooks))
		{
			Collections::Generic::IList<RenSharpKeyHookStruct^>^ keyHookCollection = groupedKeyHooks[static_cast<int>(group)];

			for (int keyHookIndex = keyHookCollection->Count - 1; keyHookIndex >= 0; keyHookIndex--)
			{
				auto keyHook = keyHookCollection[keyHookIndex];
				if (keyHook->HasTrigger(trigger))
				{
					keyHookCollection->RemoveAt(keyHookIndex);
				}
			}

			bool allCollectionsEmpty = true;
			for (int x = 0; x < groupedKeyHooks->Length; x++)
			{
				if (groupedKeyHooks[x]->Count > 0)
				{
					allCollectionsEmpty = false;

					break;
				}
			}

			if (allCollectionsEmpty)
			{
				keyHooks->Remove(owner);
			}
		}
	}

	void RenSharpKeyHookManager::ClearKeyHooks(IKeyHookInterface^ owner, KeyHookGroup group)
	{
		if (owner == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}

		array<Collections::Generic::IList<RenSharpKeyHookStruct^>^>^ groupedKeyHooks;
		if (!keyHooks->TryGetValue(owner, groupedKeyHooks))
		{
			return;
		}

		groupedKeyHooks[static_cast<int>(group)]->Clear();

		bool allCollectionsEmpty = true;
		for (int x = 0; x < groupedKeyHooks->Length; x++)
		{
			if (groupedKeyHooks[x]->Count > 0)
			{
				allCollectionsEmpty = false;

				break;
			}
		}

		if (allCollectionsEmpty)
		{
			keyHooks->Remove(owner);
		}
	}

	Collections::Generic::IEnumerable<RenSharpKeyHookStruct^>^ RenSharpKeyHookManager::GetKeyHooks(IKeyHookInterface^ owner, KeyHookGroup group)
	{
		if (owner == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}

		array<Collections::Generic::IList<RenSharpKeyHookStruct^>^>^ groupedKeyHooks;
		if (keyHooks->TryGetValue(owner, groupedKeyHooks))
		{
			return groupedKeyHooks[static_cast<int>(group)];
		}

		return gcnew Collections::Generic::List<RenSharpKeyHookStruct^>();
	}

	Collections::Generic::IEnumerable<RenSharpKeyHookClass^>^ RenSharpKeyHookManager::GlobalKeyHooks::get()
	{
		return globalKeyHooks;
	}

	RenSharpKeyHookManager::CheckKeyHookResult RenSharpKeyHookManager::CheckKeyHook(RenSharpKeyHookClass^ keyHook, IcPlayer^ player, String^ key)
	{
		if (keyHook->HasTrigger(key))
		{
			keyHook->Activate(player);

			return CheckKeyHookResult::FoundReturnFalse;
		}

		return CheckKeyHookResult::NoneFound;
	}

	RenSharpKeyHookManager::CheckKeyHookResult RenSharpKeyHookManager::CheckKeyHooks(Collections::Generic::IList<RenSharpKeyHookStruct^>^ keyHookCollection, IcPlayer^ player, String^ key)
	{
		for each (auto keyHook in keyHookCollection)
		{
			if (keyHook->Owner->FilterKeyHook(player, key, keyHook->Data) && keyHook->HasTrigger(key))
			{
				keyHook->Func->Invoke(player, key, keyHook->Data);

				return CheckKeyHookResult::FoundReturnFalse;
			}
		}

		return CheckKeyHookResult::NoneFound;
	}
}