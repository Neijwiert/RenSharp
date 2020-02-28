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
#include "RenSharpChatCommandStruct.h"
#include "IChatCommandInterface.h"

namespace RenSharp
{
	ref class RenSharpChatCommandClass;

	public ref class RenSharpChatCommandManager sealed : public RenSharpEventClass
	{
		private:
			enum class CheckChatCommandResult
			{
				NoneFound,
				FoundReturnFalse,
				FoundReturnTrue
			};

			bool disposedResources;
			
			static Collections::Generic::IDictionary<IChatCommandInterface^, array<Collections::Generic::IList<RenSharpChatCommandStruct^>^>^>^ chatCommands;
			static Collections::Generic::IList<RenSharpChatCommandClass^>^ globalChatCommands;

		public:
			static RenSharpChatCommandManager();

			RenSharpChatCommandManager();
			~RenSharpChatCommandManager();

			void UnmanagedAttach() override;
			bool ChatCommandEvent(IcPlayer^ player, TextMessageEnum type, String^ command, IDATokenClass^ text, int receiverID) override;
			bool KeyHookEvent(IcPlayer^ player, String^ key) override;

		internal:
			static void UnregisterChatCommand(String^ trigger);

			static void RegisterChatCommand(RenSharpChatCommandClass^ chatCommand);
			static void UnregisterChatCommand(RenSharpChatCommandClass^ chatCommand);

			static RenSharpChatCommandStruct^ RegisterChatCommand(IChatCommandInterface^ owner, ChatCommandGroup group, RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel, DAChatType chatType, Object^ data);
			static RenSharpChatCommandStruct^ RegisterChatCommand(IChatCommandInterface^ owner, ChatCommandGroup group, RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel, DAChatType chatType);
			static RenSharpChatCommandStruct^ RegisterChatCommand(IChatCommandInterface^ owner, ChatCommandGroup group, RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel);
			static RenSharpChatCommandStruct^ RegisterChatCommand(IChatCommandInterface^ owner, ChatCommandGroup group, RenSharpCCDelegate^ func, String^ triggers, int parameters, Object^ data);
			static RenSharpChatCommandStruct^ RegisterChatCommand(IChatCommandInterface^ owner, ChatCommandGroup group, RenSharpCCDelegate^ func, String^ triggers, int parameters);
			static RenSharpChatCommandStruct^ RegisterChatCommand(IChatCommandInterface^ owner, ChatCommandGroup group, RenSharpCCDelegate^ func, String^ triggers);
			static void UnregisterChatCommand(IChatCommandInterface^ owner, ChatCommandGroup group, String^ trigger);
			static void ClearChatCommands(IChatCommandInterface^ owner, ChatCommandGroup group);
			static Collections::Generic::IEnumerable<RenSharpChatCommandStruct^>^ GetChatCommands(IChatCommandInterface^ owner, ChatCommandGroup group);

			static property Collections::Generic::IEnumerable<RenSharpChatCommandClass^>^ GlobalChatCommands
			{
				Collections::Generic::IEnumerable<RenSharpChatCommandClass^>^ get();
			}

		private:
			CheckChatCommandResult CheckChatCommand(RenSharpChatCommandClass^ chatCommand, IcPlayer^ player, TextMessageEnum type, String^ command, IDATokenClass^ text);
			CheckChatCommandResult CheckChatCommands(Collections::Generic::IList<RenSharpChatCommandStruct^>^ chatCommandCollection, IcPlayer^ player, TextMessageEnum type, String^ command, IDATokenClass^ text);
	};
}