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
#include "RenSharpChatCommandStruct.h"

using namespace System::Text;

namespace RenSharp
{
	RenSharpChatCommandStruct::RenSharpChatCommandStruct(
		IChatCommandInterface^ owner,
		RenSharpCCDelegate^ func,
		String^ triggers,
		int parameters,
		DAAccessLevel accessLevel,
		DAChatType chatType,
		Object^ data)
		:
		owner(owner),
		func(func),
		accessLevel(accessLevel),
		parameters(parameters),
		chatType(chatType),
		data(data)
	{
		if (owner == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}
		else if (func == nullptr)
		{
			throw gcnew ArgumentNullException("func");
		}

		this->triggers = ParseTriggers(triggers);
	}

	array<String^>^ RenSharpChatCommandStruct::ParseTriggers(String^ triggers)
	{
		if (triggers == nullptr)
		{
			throw gcnew ArgumentNullException("triggers");
		}

		return triggers->Split(gcnew array<wchar_t>{ L'|' });
	}

	String^ RenSharpChatCommandStruct::ToString()
	{
		StringBuilder^ builder = gcnew StringBuilder();

		if (Triggers == nullptr)
		{
			builder->Append(static_cast<Object^>(nullptr));
		}
		else
		{
			bool isFirstTrigger = true;

			for each (String ^ trigger in Triggers)
			{
				if (isFirstTrigger)
				{
					isFirstTrigger = false;
				}
				else
				{
					builder->Append(L'|');
				}

				builder->Append(trigger);
			}
		}

		return builder->ToString();
	}

	bool RenSharpChatCommandStruct::HasTrigger(String^ trigger)
	{
		if (trigger == nullptr)
		{
			throw gcnew ArgumentNullException("trigger");
		}

		if (triggers != nullptr)
		{
			for each (String ^ currentTrigger in triggers)
			{
				if (currentTrigger->Equals(trigger, StringComparison::InvariantCultureIgnoreCase))
				{
					return true;
				}
			}
		}

		return false;
	}

	IChatCommandInterface^ RenSharpChatCommandStruct::Owner::get()
	{
		return owner;
	}

	array<String^>^ RenSharpChatCommandStruct::Triggers::get()
	{
		return triggers;
	}

	RenSharpCCDelegate^ RenSharpChatCommandStruct::Func::get()
	{
		return func;
	}

	DAAccessLevel RenSharpChatCommandStruct::AccessLevel::get()
	{
		return accessLevel;
	}

	int RenSharpChatCommandStruct::Parameters::get()
	{
		return parameters;
	}

	DAChatType RenSharpChatCommandStruct::ChatType::get()
	{
		return chatType;
	}

	Object^ RenSharpChatCommandStruct::Data::get()
	{
		return data;
	}

	void RenSharpChatCommandStruct::Data::set(Object^ value)
	{
		data = value;
	}
}