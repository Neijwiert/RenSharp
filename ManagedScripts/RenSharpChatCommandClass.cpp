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
#include "RenSharpChatCommandClass.h"

#include "RenSharpTimerManager.h"
#include "RenSharpChatCommandStruct.h"
#include "RenSharpChatCommandManager.h"

namespace RenSharp
{
	RenSharpChatCommandClass::RenSharpChatCommandClass(String^ triggers, DAAccessLevel accessLevel, DAChatType chatType, int parameters)
		: disposedResources(false), triggers(RenSharpChatCommandStruct::ParseTriggers(triggers)), accessLevel(accessLevel), chatType(chatType), parameters(parameters)
	{

	}

	RenSharpChatCommandClass::RenSharpChatCommandClass(String^ triggers, DAAccessLevel accessLevel, DAChatType chatType)
		: RenSharpChatCommandClass(triggers, accessLevel, chatType, 0)
	{

	}

	RenSharpChatCommandClass::RenSharpChatCommandClass(String^ triggers, DAAccessLevel accessLevel)
		: RenSharpChatCommandClass(triggers, accessLevel, DAChatType::All)
	{

	}

	RenSharpChatCommandClass::RenSharpChatCommandClass(String^ triggers)
		: RenSharpChatCommandClass(triggers, DAAccessLevel::None)
	{

	}

	RenSharpChatCommandClass::~RenSharpChatCommandClass()
	{
		if (disposedResources)
		{
			return;
		}

		RenSharpChatCommandManager::UnregisterChatCommand(this);

		ClearTimers();

		disposedResources = true;
	}

	void RenSharpChatCommandClass::RegisterManagedObject()
	{
		RenSharpChatCommandManager::RegisterChatCommand(this);
	}

	bool RenSharpChatCommandClass::HasTrigger(String^ trigger)
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

	void RenSharpChatCommandClass::TimerExpired(int number, Object^ data)
	{

	}

	void RenSharpChatCommandClass::StartTimer(int number, TimeSpan duration, bool repeat, Object^ data)
	{
		RenSharpTimerManager::StartTimer(this, number, duration, repeat, data);
	}

	void RenSharpChatCommandClass::StartTimer(int number, TimeSpan duration, bool repeat)
	{
		RenSharpTimerManager::StartTimer(this, number, duration, repeat);
	}

	void RenSharpChatCommandClass::StartTimer(int number, TimeSpan duration)
	{
		RenSharpTimerManager::StartTimer(this, number, duration);
	}

	void RenSharpChatCommandClass::StartTimer(TimeSpan duration, bool repeat, System::Action<RenSharpTimerStruct^>^ action)
	{
		RenSharpTimerManager::StartTimer(this, duration, repeat, action);
	}

	void RenSharpChatCommandClass::StartTimer(TimeSpan duration, System::Action<RenSharpTimerStruct^>^ action)
	{
		RenSharpTimerManager::StartTimer(this, duration, action);
	}

	void RenSharpChatCommandClass::StopTimer(int number, Object^ data)
	{
		RenSharpTimerManager::StopTimer(this, number, data);
	}

	void RenSharpChatCommandClass::StopTimer(int number)
	{
		RenSharpTimerManager::StopTimer(this, number);
	}

	void RenSharpChatCommandClass::StopTimer(System::Action<RenSharpTimerStruct^>^ action)
	{
		RenSharpTimerManager::StopTimer(this, action);
	}

	bool RenSharpChatCommandClass::IsTimer(int number, Object^ data)
	{
		return RenSharpTimerManager::IsTimer(this, number, data);
	}

	bool RenSharpChatCommandClass::IsTimer(int number)
	{
		return RenSharpTimerManager::IsTimer(this, number);
	}

	bool RenSharpChatCommandClass::IsTimer(System::Action<RenSharpTimerStruct^>^ action)
	{
		return RenSharpTimerManager::IsTimer(this, action);
	}

	void RenSharpChatCommandClass::ClearTimers()
	{
		RenSharpTimerManager::ClearTimers(this);
	}

	Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ RenSharpChatCommandClass::Timers::get()
	{
		return RenSharpTimerManager::GetTimers(this);
	}

	array<String^>^ RenSharpChatCommandClass::Triggers::get()
	{
		return triggers;
	}

	void RenSharpChatCommandClass::Triggers::set(array<String^>^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		triggers = value;
	}

	DAAccessLevel RenSharpChatCommandClass::AccessLevel::get()
	{
		return accessLevel;
	}

	void RenSharpChatCommandClass::AccessLevel::set(DAAccessLevel value)
	{
		accessLevel = value;
	}

	DAChatType RenSharpChatCommandClass::ChatType::get()
	{
		return chatType;
	}

	void RenSharpChatCommandClass::ChatType::set(DAChatType value)
	{
		chatType = value;
	}

	int RenSharpChatCommandClass::Parameters::get()
	{
		return parameters;
	}

	void RenSharpChatCommandClass::Parameters::set(int value)
	{
		parameters = value;
	}
}