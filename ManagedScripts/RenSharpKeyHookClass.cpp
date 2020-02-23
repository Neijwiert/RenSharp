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
#include "RenSharpKeyHookClass.h"

#include "RenSharpTimerManager.h"
#include "RenSharpKeyHookStruct.h"
#include "RenSharpKeyHookManager.h"

namespace RenSharp
{
	RenSharpKeyHookClass::RenSharpKeyHookClass(String^ triggers)
		: disposedResources(false), triggers(RenSharpKeyHookStruct::ParseTriggers(triggers))
	{

	}

	RenSharpKeyHookClass::~RenSharpKeyHookClass()
	{
		if (disposedResources)
		{
			return;
		}

		RenSharpKeyHookManager::UnregisterKeyHook(this);

		ClearTimers();

		disposedResources = true;
	}

	void RenSharpKeyHookClass::RegisterManagedObject()
	{
		RenSharpKeyHookManager::RegisterKeyHook(this);
	}

	bool RenSharpKeyHookClass::HasTrigger(String^ trigger)
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

	void RenSharpKeyHookClass::TimerExpired(int number, Object^ data)
	{

	}

	void RenSharpKeyHookClass::StartTimer(int number, TimeSpan duration, bool repeat, Object^ data)
	{
		RenSharpTimerManager::StartTimer(this, number, duration, repeat, data);
	}

	void RenSharpKeyHookClass::StartTimer(int number, TimeSpan duration, bool repeat)
	{
		RenSharpTimerManager::StartTimer(this, number, duration, repeat);
	}

	void RenSharpKeyHookClass::StartTimer(int number, TimeSpan duration)
	{
		RenSharpTimerManager::StartTimer(this, number, duration);
	}

	void RenSharpKeyHookClass::StopTimer(int number, Object^ data)
	{
		RenSharpTimerManager::StopTimer(this, number, data);
	}

	void RenSharpKeyHookClass::StopTimer(int number)
	{
		RenSharpTimerManager::StopTimer(this, number);
	}

	bool RenSharpKeyHookClass::IsTimer(int number, Object^ data)
	{
		return RenSharpTimerManager::IsTimer(this, number, data);
	}

	bool RenSharpKeyHookClass::IsTimer(int number)
	{
		return RenSharpTimerManager::IsTimer(this, number);
	}

	void RenSharpKeyHookClass::ClearTimers()
	{
		RenSharpTimerManager::ClearTimers(this);
	}

	Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ RenSharpKeyHookClass::Timers::get()
	{
		return RenSharpTimerManager::GetTimers(this);
	}

	array<String^>^ RenSharpKeyHookClass::Triggers::get()
	{
		return triggers;
	}
}