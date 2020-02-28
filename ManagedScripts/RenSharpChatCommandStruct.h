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

namespace RenSharp
{
	ref class RenSharpChatCommandStruct;
	interface class IChatCommandInterface;

	public delegate bool RenSharpCCDelegate(IcPlayer ^player, String ^command, IDATokenClass ^text, TextMessageEnum chatType, Object ^data);

	public enum class ChatCommandGroup
	{
		PlayerObserver = 0,
		EventClass
	};

	public ref class RenSharpChatCommandStruct sealed
	{
		private:
			IChatCommandInterface^ owner;
			array<String ^> ^triggers;
			RenSharpCCDelegate ^func;
			DAAccessLevel accessLevel;
			int parameters;
			DAChatType chatType;
			Object^ data;

		public:
			RenSharpChatCommandStruct(IChatCommandInterface^ owner, RenSharpCCDelegate^ func, String ^triggers, int parameters, DAAccessLevel accessLevel, DAChatType chatType, Object^ data);

			static array<String^>^ ParseTriggers(String^ triggers);

			String ^ToString() override;

			bool HasTrigger(String ^trigger);

			property IChatCommandInterface^ Owner
			{
				IChatCommandInterface^ get();
			}

			property array<String^> ^Triggers
			{
				array<String ^> ^get();

				protected:
					void set(array<String^>^ value);
			}

			property RenSharpCCDelegate^ Func
			{
				RenSharpCCDelegate^ get();

				protected:
					void set(RenSharpCCDelegate^ value);
			}

			property DAAccessLevel AccessLevel
			{
				DAAccessLevel get();

				protected:
					void set(DAAccessLevel value);
			}

			property int Parameters
			{
				int get();

				protected:
					void set(int value);
			}

			property DAChatType ChatType
			{
				DAChatType get();

				protected:
					void set(DAChatType value);
			}

			property Object^ Data
			{
				Object^ get();
				void set(Object ^value);
			}
	};
}