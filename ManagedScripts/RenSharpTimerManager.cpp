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
#include "RenSharpTimerManager.h"

#include "RenSharpTimerStruct.h"

namespace RenSharp
{
	static RenSharpTimerManager::RenSharpTimerManager()
	{
		timers = gcnew Collections::Generic::Dictionary<ITimerInterface^, Collections::Generic::IList<RenSharpTimerStruct^>^>();
	}

	RenSharpTimerManager::RenSharpTimerManager()
		: disposedResources(false)
	{

	}

	RenSharpTimerManager::~RenSharpTimerManager()
	{
		if (disposedResources)
		{
			return;
		}

		timers->Clear();

		disposedResources = true;
	}

	void RenSharpTimerManager::UnmanagedAttach()
	{
		RegisterEvent(DAEventType::Think, Int32::MaxValue);
	}

	void RenSharpTimerManager::Think()
	{
		for each (auto pair in timers)
		{
			for (int index = pair.Value->Count - 1; index >= 0; index--)
			{
				RenSharpTimerStruct^ currentTimer = pair.Value[index];

				TimeSpan elapsedTime = DateTime::Now - currentTimer->StartTime;
				if (elapsedTime >= currentTimer->Duration)
				{
					if (currentTimer->Owner != nullptr)
					{
						currentTimer->Owner->TimerExpired(currentTimer->Number, currentTimer->Data);
					}

					if (currentTimer->Repeat)
					{
						currentTimer->Reset();
					}
					else
					{
						pair.Value->RemoveAt(index);
					}
				}
			}
		}
	}

	void RenSharpTimerManager::StartTimer(ITimerInterface^ owner, int number, TimeSpan duration, bool repeat, Object^ data)
	{
		if (owner == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}

		Collections::Generic::IList<RenSharpTimerStruct^>^ eventTimers;
		if (!timers->TryGetValue(owner, eventTimers))
		{
			eventTimers = gcnew Collections::Generic::List<RenSharpTimerStruct^>();

			timers->Add(owner, eventTimers);
		}

		eventTimers->Add(gcnew RenSharpTimerStruct(owner, duration, repeat, number, data));
	}

	void RenSharpTimerManager::StartTimer(ITimerInterface^ owner, int number, TimeSpan duration, bool repeat)
	{
		StartTimer(owner, number, duration, repeat, nullptr);
	}

	void RenSharpTimerManager::StartTimer(ITimerInterface^ owner, int number, TimeSpan duration)
	{
		StartTimer(owner, number, duration, false, nullptr);
	}

	void RenSharpTimerManager::StopTimer(ITimerInterface^ owner, int number, Object^ data)
	{
		if (owner == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}

		Collections::Generic::IList<RenSharpTimerStruct^>^ eventTimers;
		if (timers->TryGetValue(owner, eventTimers))
		{
			for (int index = eventTimers->Count - 1; index >= 0; index--)
			{
				RenSharpTimerStruct^ currentTimer = eventTimers[index];
				if (currentTimer->Number == number && (data == nullptr || data->Equals(currentTimer->Data)))
				{
					eventTimers->RemoveAt(index);
				}
			}

			if (eventTimers->Count <= 0)
			{
				timers->Remove(owner);
			}
		}
	}

	void RenSharpTimerManager::StopTimer(ITimerInterface^ owner, int number)
	{
		StopTimer(owner, number, nullptr);
	}

	bool RenSharpTimerManager::IsTimer(ITimerInterface^ owner, int number, Object^ data)
	{
		if (owner == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}

		Collections::Generic::IList<RenSharpTimerStruct^>^ eventTimers;
		if (timers->TryGetValue(owner, eventTimers))
		{
			for each (RenSharpTimerStruct ^ timer in eventTimers)
			{
				if (timer->Number == number && (data == nullptr || data->Equals(timer->Data)))
				{
					return true;
				}
			}
		}

		return false;
	}

	bool RenSharpTimerManager::IsTimer(ITimerInterface^ owner, int number)
	{
		return IsTimer(owner, number, nullptr);
	}

	void RenSharpTimerManager::ClearTimers(ITimerInterface^ owner)
	{
		if (owner == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}

		timers->Remove(owner);
	}

	Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ RenSharpTimerManager::GetTimers(ITimerInterface^ owner)
	{
		if (owner == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}

		Collections::Generic::IList<RenSharpTimerStruct^>^ eventTimers;
		if (timers->TryGetValue(owner, eventTimers))
		{
			return eventTimers;
		}
		else
		{
			return gcnew Collections::Generic::List<RenSharpTimerStruct^>();
		}
	}
}