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

#include "RenSharpChatCommandStruct.h"

namespace RenSharp
{
	public interface class IChatCommandInterface : public IDisposable
	{
		bool FilterChatCommand(IcPlayer^ player, String^ command, IDATokenClass^ text, TextMessageEnum chatType, Object^ data);

		void RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel, DAChatType chatType, Object^ data);

		void RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel, DAChatType chatType);

		void RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, DAAccessLevel accessLevel);

		void RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters, Object^ data);

		void RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers, int parameters);

		void RegisterChatCommand(RenSharpCCDelegate^ func, String^ triggers);

		void UnregisterChatCommand(String^ trigger);

		void ClearChatCommands();

		property Collections::Generic::IEnumerable<RenSharpChatCommandStruct^>^ ChatCommands
		{
			Collections::Generic::IEnumerable<RenSharpChatCommandStruct^>^ get();
		}
	};
}