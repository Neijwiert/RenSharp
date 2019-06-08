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

#include "stdafx.h"
#include "RenSharpChatCommandManager.h"

#include "McPlayer.h"
#include "Mda_token.h"
#include "Mda_player.h"
#include "Mda.h"
#include "RenSharpChatCommandClass.h"
#include "Imports.h"

using namespace System::Text;

namespace RenSharp
{
	static RenSharpChatCommandManager::RenSharpChatCommandManager()
	{
		chatCommands = gcnew Collections::Generic::Dictionary<IChatCommandInterface^, array<Collections::Generic::IList<RenSharpChatCommandStruct^>^>^>();
		globalChatCommands = gcnew Collections::Generic::List<RenSharpChatCommandClass^>();
	}

	RenSharpChatCommandManager::RenSharpChatCommandManager()
		: disposedResources(false)
	{

	}

	RenSharpChatCommandManager::~RenSharpChatCommandManager()
	{
		if (disposedResources)
		{
			return;
		}

		chatCommands->Clear();

		auto tmpGlobalChatCommands = gcnew Collections::Generic::List<RenSharpChatCommandClass^>(globalChatCommands);

		for each (auto chatCommand in tmpGlobalChatCommands)
		{
#pragma push_macro("delete")
#undef delete
			delete chatCommand;
			chatCommand = nullptr;
#pragma pop_macro("delete")
		}

		tmpGlobalChatCommands->Clear();
		globalChatCommands->Clear();

		disposedResources = true;
	}

	void RenSharpChatCommandManager::UnmanagedAttach()
	{
		RegisterEvent(DAEventType::ChatCommand, Int32::MaxValue);
		RegisterEvent(DAEventType::KeyHook, Int32::MaxValue);
	}

	bool RenSharpChatCommandManager::ChatCommandEvent(IcPlayer^ player, TextMessageEnum type, String^ command, IDATokenClass^ text, int receiverID)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (command == nullptr)
		{
			throw gcnew ArgumentNullException("command");
		}
		else if (text == nullptr || text->DATokenClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("text");
		}

		for each (auto groupedChatCommands in chatCommands->Values)
		{
			for each (auto chatCommandCollection in groupedChatCommands)
			{
				switch (CheckChatCommands(chatCommandCollection, player, type, command, text))
				{
					case CheckChatCommandResult::FoundReturnTrue:
						return true;
					case CheckChatCommandResult::FoundReturnFalse:
						return false;
				}
			}
		}

		for each (auto chatCommand in globalChatCommands)
		{
			switch (CheckChatCommand(chatCommand, player, type, command, text))
			{
				case CheckChatCommandResult::FoundReturnTrue:
					return true;
				case CheckChatCommandResult::FoundReturnFalse:
					return false;
			}
		}

		return true;
	}

	bool RenSharpChatCommandManager::KeyHookEvent(IcPlayer^ player, String^ key)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}

		IUnmanagedContainer<IDATokenClass^>^ nullToken = DATokenClass::CreateDATokenClass();
		try
		{
			for each (auto groupedChatCommands in chatCommands->Values)
			{
				for each (auto chatCommandCollection in groupedChatCommands)
				{
					switch (CheckChatCommands(chatCommandCollection, player, TextMessageEnum::TextMessageKeyHook, key, nullToken->UnmanagedObject))
					{
						case CheckChatCommandResult::FoundReturnTrue:
							return true;
						case CheckChatCommandResult::FoundReturnFalse:
							return false;
					}
				}
			}

			for each (auto chatCommand in globalChatCommands)
			{
				switch (CheckChatCommand(chatCommand, player, TextMessageEnum::TextMessageKeyHook, key, nullToken->UnmanagedObject))
				{
					case CheckChatCommandResult::FoundReturnTrue:
						return true;
					case CheckChatCommandResult::FoundReturnFalse:
						return false;
				}
			}
		}
		finally
		{

#pragma push_macro("delete")
#undef delete

			delete nullToken;
			nullToken = nullptr;

#pragma pop_macro("delete")

		}

		return true;
	}

	void RenSharpChatCommandManager::UnregisterChatCommand(String^ trigger)
	{
		if (trigger == nullptr)
		{
			throw gcnew ArgumentNullException("trigger");
		}

		for (int commandIndex = globalChatCommands->Count - 1; commandIndex >= 0; commandIndex--)
		{
			auto chatCommand = globalChatCommands[commandIndex];
			if (chatCommand->HasTrigger(trigger))
			{
				globalChatCommands->RemoveAt(commandIndex);

#pragma push_macro("delete")
#undef delete

				delete chatCommand;
				chatCommand = nullptr;

#pragma pop_macro("delete")
			}
		}
	}

	void RenSharpChatCommandManager::RegisterChatCommand(RenSharpChatCommandClass^ chatCommand)
	{
		if (chatCommand == nullptr)
		{
			throw gcnew ArgumentNullException("chatCommand");
		}
		else if (Imports::IsShuttingDown())
		{
			throw gcnew NotSupportedException("Engine is shutting down");
		}

		globalChatCommands->Add(chatCommand);
	}

	void RenSharpChatCommandManager::UnregisterChatCommand(RenSharpChatCommandClass^ chatCommand)
	{
		if (chatCommand == nullptr)
		{
			throw gcnew ArgumentNullException("chatCommand");
		}

		globalChatCommands->Remove(chatCommand);
	}

	void RenSharpChatCommandManager::RegisterChatCommand(IChatCommandInterface^ owner, ChatCommandGroup group, RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel, DAChatType chatType, Object ^data)
	{
		if (owner == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}

		RenSharpChatCommandStruct^ newChatCommand = gcnew RenSharpChatCommandStruct(owner, func, triggers, parameters, accessLevel, chatType, data);

		array<Collections::Generic::IList<RenSharpChatCommandStruct^>^>^ groupedChatCommands;
		if (!chatCommands->TryGetValue(owner, groupedChatCommands))
		{
			groupedChatCommands = gcnew array<Collections::Generic::IList<RenSharpChatCommandStruct^>^>(Enum::GetValues(ChatCommandGroup::typeid)->Length);
			for (int x = 0; x < groupedChatCommands->Length; x++)
			{
				groupedChatCommands[x] = gcnew Collections::Generic::List<RenSharpChatCommandStruct^>();
			}

			chatCommands->Add(owner, groupedChatCommands);
		}

		groupedChatCommands[static_cast<int>(group)]->Add(newChatCommand);
	}

	void RenSharpChatCommandManager::RegisterChatCommand(IChatCommandInterface^ owner, ChatCommandGroup group, RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel, DAChatType chatType)
	{
		RegisterChatCommand(owner, group, func, triggers, parameters, accessLevel, chatType, nullptr);
	}

	void RenSharpChatCommandManager::RegisterChatCommand(IChatCommandInterface^ owner, ChatCommandGroup group, RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel)
	{
		RegisterChatCommand(owner, group, func, triggers, parameters, accessLevel, DAChatType::All, nullptr);
	}

	void RenSharpChatCommandManager::RegisterChatCommand(IChatCommandInterface^ owner, ChatCommandGroup group, RenSharpCCDelegate^ func, String^ triggers, int parameters, Object^ data)
	{
		RegisterChatCommand(owner, group, func, triggers, parameters, DAAccessLevel::None, DAChatType::All, data);
	}

	void RenSharpChatCommandManager::RegisterChatCommand(IChatCommandInterface^ owner, ChatCommandGroup group, RenSharpCCDelegate^ func, String^ triggers, int parameters)
	{
		RegisterChatCommand(owner, group, func, triggers, parameters, nullptr);
	}

	void RenSharpChatCommandManager::RegisterChatCommand(IChatCommandInterface^ owner, ChatCommandGroup group, RenSharpCCDelegate^ func, String^ triggers)
	{
		RegisterChatCommand(owner, group, func, triggers, 0, nullptr);
	}

	void RenSharpChatCommandManager::UnregisterChatCommand(IChatCommandInterface^ owner, ChatCommandGroup group, String^ trigger)
	{
		if (owner == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}
		else if (trigger == nullptr)
		{
			throw gcnew ArgumentNullException("trigger");
		}

		array<Collections::Generic::IList<RenSharpChatCommandStruct^>^>^ groupedChatCommands;
		if (chatCommands->TryGetValue(owner, groupedChatCommands))
		{
			Collections::Generic::IList<RenSharpChatCommandStruct^>^ chatCommandCollection = groupedChatCommands[static_cast<int>(group)];

			for (int commandIndex = chatCommandCollection->Count - 1; commandIndex >= 0; commandIndex--)
			{
				auto chatCommand = chatCommandCollection[commandIndex];
				if (chatCommand->HasTrigger(trigger))
				{
					chatCommandCollection->RemoveAt(commandIndex);
				}
			}

			bool allCollectionsEmpty = true;
			for (int x = 0; x < groupedChatCommands->Length; x++)
			{
				if (groupedChatCommands[x]->Count > 0)
				{
					allCollectionsEmpty = false;

					break;
				}
			}
			
			if (allCollectionsEmpty)
			{
				chatCommands->Remove(owner);
			}
		}
	}

	void RenSharpChatCommandManager::ClearChatCommands(IChatCommandInterface^ owner, ChatCommandGroup group)
	{
		if (owner == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}

		array<Collections::Generic::IList<RenSharpChatCommandStruct^>^>^ groupedChatCommands;
		if (!chatCommands->TryGetValue(owner, groupedChatCommands))
		{
			return;
		}

		groupedChatCommands[static_cast<int>(group)]->Clear();

		bool allCollectionsEmpty = true;
		for (int x = 0; x < groupedChatCommands->Length; x++)
		{
			if (groupedChatCommands[x]->Count > 0)
			{
				allCollectionsEmpty = false;

				break;
			}
		}

		if (allCollectionsEmpty)
		{
			chatCommands->Remove(owner);
		}
	}

	Collections::Generic::IEnumerable<RenSharpChatCommandStruct^>^ RenSharpChatCommandManager::GetChatCommands(IChatCommandInterface^ owner, ChatCommandGroup group)
	{
		if (owner == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}

		array<Collections::Generic::IList<RenSharpChatCommandStruct^>^>^ groupedChatCommands;
		if (chatCommands->TryGetValue(owner, groupedChatCommands))
		{
			return groupedChatCommands[static_cast<int>(group)];
		}
			
		return gcnew Collections::Generic::List<RenSharpChatCommandStruct^>();
	}

	Collections::Generic::IEnumerable<RenSharpChatCommandClass^>^ RenSharpChatCommandManager::GlobalChatCommands::get()
	{
		return globalChatCommands;
	}

	RenSharpChatCommandManager::CheckChatCommandResult RenSharpChatCommandManager::CheckChatCommand(RenSharpChatCommandClass^ chatCommand, IcPlayer^ player, TextMessageEnum type, String^ command, IDATokenClass^ text)
	{
		if (chatCommand->HasTrigger(command))
		{
			auto daPlayer = player->DAPlayer;
			if (daPlayer->AccessLevel < chatCommand->AccessLevel)
			{
				DA::PagePlayer(player, "You do not have access to use this command.");

				return CheckChatCommandResult::FoundReturnFalse;
			}
			else if (text->Size < chatCommand->Parameters)
			{
				DA::PagePlayer(player, "Insufficient parameters. This command requires atleast {0} parameter(s), you only supplied {1}.", chatCommand->Parameters, text->Size);

				return CheckChatCommandResult::FoundReturnFalse;
			}
			else if (
				chatCommand->ChatType.HasFlag(DAChatType::All) ||
				(type == TextMessageEnum::TextMessagePublic && chatCommand->ChatType.HasFlag(DAChatType::Public)) ||
				(type == TextMessageEnum::TextMessageTeam && chatCommand->ChatType.HasFlag(DAChatType::Team)) ||
				(type == TextMessageEnum::TextMessagePrivate && chatCommand->ChatType.HasFlag(DAChatType::Private)) ||
				(type == TextMessageEnum::TextMessageTMSG && chatCommand->ChatType.HasFlag(DAChatType::TMSG)))
			{
				if (chatCommand->Activate(player, text, type))
				{
					return CheckChatCommandResult::FoundReturnTrue;
				}
			}

			return CheckChatCommandResult::FoundReturnFalse;
		}

		return CheckChatCommandResult::NoneFound;
	}

	RenSharpChatCommandManager::CheckChatCommandResult RenSharpChatCommandManager::CheckChatCommands(Collections::Generic::IList<RenSharpChatCommandStruct^>^ chatCommandCollection, IcPlayer^ player, TextMessageEnum type, String^ command, IDATokenClass^ text)
	{
		for each (auto chatCommand in chatCommandCollection)
		{
			if (chatCommand->Owner->FilterChatCommand(player, command, text, type, chatCommand->Data) && chatCommand->HasTrigger(command))
			{
				auto daPlayer = player->DAPlayer;
				if (daPlayer->AccessLevel < chatCommand->AccessLevel)
				{
					DA::PagePlayer(player, "You do not have access to use this command.");

					return CheckChatCommandResult::FoundReturnFalse;
				}
				else if (text->Size < chatCommand->Parameters)
				{
					DA::PagePlayer(player, "Insufficient parameters. This command requires atleast {0} parameter(s), you only supplied {1}.", chatCommand->Parameters, text->Size);

					return CheckChatCommandResult::FoundReturnFalse;
				}
				else if (
					chatCommand->ChatType.HasFlag(DAChatType::All) ||
					(type == TextMessageEnum::TextMessagePublic && chatCommand->ChatType.HasFlag(DAChatType::Public)) ||
					(type == TextMessageEnum::TextMessageTeam && chatCommand->ChatType.HasFlag(DAChatType::Team)) ||
					(type == TextMessageEnum::TextMessagePrivate && chatCommand->ChatType.HasFlag(DAChatType::Private)) ||
					(type == TextMessageEnum::TextMessageTMSG && chatCommand->ChatType.HasFlag(DAChatType::TMSG)))
				{
					if (chatCommand->Func->Invoke(player, command, text, type, chatCommand->Data))
					{
						return CheckChatCommandResult::FoundReturnTrue;
					}
				}

				return CheckChatCommandResult::FoundReturnFalse;
			}
		}

		return CheckChatCommandResult::NoneFound;
	}
}