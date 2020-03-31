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
#include "RenSharpTimerManager.h"

#include "RenSharpTimerStruct.h"
#include "MTimeManager.h"

namespace RenSharp
{
	static RenSharpTimerManager::RenSharpTimerManager()
	{
		timers = gcnew Collections::Generic::List<Collections::Generic::IList<RenSharpTimerStruct^>^>();
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
		for (int interfaceIndex = timers->Count - 1; interfaceIndex >= 0 && timers->Count > 0; interfaceIndex--)
		{
			auto timerList = timers[interfaceIndex];
			for (int timerIndex = timerList->Count - 1; timerIndex >= 0 && timerList->Count > 0; timerIndex--)
			{
				RenSharpTimerStruct^ currentTimer = timerList[timerIndex];

				currentTimer->RemainingTime -= TimeManager::FrameSeconds;
				if (currentTimer->RemainingTime <= 0)
				{
					if (currentTimer->Owner != nullptr)
					{
						if (currentTimer->Action != nullptr)
						{
							currentTimer->Action(currentTimer);
						}
						else
						{
							currentTimer->Owner->TimerExpired(currentTimer->Number, currentTimer->Data);
						}
					}

					if (currentTimer->Repeat)
					{
						currentTimer->Reset();
					}
					else
					{
						timerList->RemoveAt(timerIndex);
					}
				}
			}

			if (timerList->Count <= 0)
			{
				timers->RemoveAt(interfaceIndex);
			}
		}
	}

	void RenSharpTimerManager::StartTimer(ITimerInterface^ owner, int number, TimeSpan duration, bool repeat, Object^ data)
	{
		if (owner == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}

		Collections::Generic::IList<RenSharpTimerStruct^>^ eventTimers = FindTimerList(owner);
		if (eventTimers == nullptr)
		{
			eventTimers = gcnew Collections::Generic::List<RenSharpTimerStruct^>();

			timers->Add(eventTimers);
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

	void RenSharpTimerManager::StartTimer(ITimerInterface^ owner, TimeSpan duration, bool repeat, System::Action<RenSharpTimerStruct^>^ action)
	{
		if (owner == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}

		Collections::Generic::IList<RenSharpTimerStruct^>^ eventTimers = FindTimerList(owner);
		if (eventTimers == nullptr)
		{
			eventTimers = gcnew Collections::Generic::List<RenSharpTimerStruct^>();

			timers->Add(eventTimers);
		}

		eventTimers->Add(gcnew RenSharpTimerStruct(owner, duration, repeat, action));
	}

	void RenSharpTimerManager::StartTimer(ITimerInterface^ owner, TimeSpan duration, System::Action<RenSharpTimerStruct^>^ action)
	{
		StartTimer(owner, duration, false, action);
	}

	void RenSharpTimerManager::StopTimer(ITimerInterface^ owner, int number, Object^ data)
	{
		if (owner == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}

		Collections::Generic::IList<RenSharpTimerStruct^>^ eventTimers = FindTimerList(owner);
		if (eventTimers != nullptr)
		{
			for (int index = eventTimers->Count - 1; index >= 0; index--)
			{
				RenSharpTimerStruct^ currentTimer = eventTimers[index];
				if (currentTimer->Number == number && (data == nullptr || data->Equals(currentTimer->Data)))
				{
					eventTimers->RemoveAt(index);
				}
			}
		}
	}

	void RenSharpTimerManager::StopTimer(ITimerInterface^ owner, int number)
	{
		StopTimer(owner, number, nullptr);
	}

	void RenSharpTimerManager::StopTimer(ITimerInterface^ owner, System::Action<RenSharpTimerStruct^>^ action)
	{
		if (owner == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}
		else if (action == nullptr)
		{
			throw gcnew ArgumentNullException("action");
		}

		Collections::Generic::IList<RenSharpTimerStruct^>^ eventTimers = FindTimerList(owner);
		if (eventTimers != nullptr)
		{
			for (int index = eventTimers->Count - 1; index >= 0; index--)
			{
				RenSharpTimerStruct^ currentTimer = eventTimers[index];
				if (currentTimer->Action == action)
				{
					eventTimers->RemoveAt(index);
				}
			}
		}
	}

	bool RenSharpTimerManager::IsTimer(ITimerInterface^ owner, int number, Object^ data)
	{
		if (owner == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}

		Collections::Generic::IList<RenSharpTimerStruct^>^ eventTimers = FindTimerList(owner);
		if (eventTimers != nullptr)
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

	bool RenSharpTimerManager::IsTimer(ITimerInterface^ owner, System::Action<RenSharpTimerStruct^>^ action)
	{
		if (owner == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}
		else if (action == nullptr)
		{
			throw gcnew ArgumentNullException("action");
		}

		Collections::Generic::IList<RenSharpTimerStruct^>^ eventTimers = FindTimerList(owner);
		if (eventTimers != nullptr)
		{
			for each (RenSharpTimerStruct ^ timer in eventTimers)
			{
				if (timer->Action == action)
				{
					return true;
				}
			}
		}

		return false;
	}

	void RenSharpTimerManager::ClearTimers(ITimerInterface^ owner)
	{
		if (owner == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}

		for (int interfaceIndex = 0; interfaceIndex < timers->Count; interfaceIndex++)
		{
			if (Object::ReferenceEquals(timers[interfaceIndex], owner))
			{
				timers->RemoveAt(interfaceIndex);

				return;
			}
		}
	}

	Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ RenSharpTimerManager::GetTimers(ITimerInterface^ owner)
	{
		if (owner == nullptr)
		{
			throw gcnew ArgumentNullException("owner");
		}

		Collections::Generic::IList<RenSharpTimerStruct^>^ eventTimers = FindTimerList(owner);
		if (eventTimers != nullptr)
		{
			return eventTimers;
		}
		else
		{
			return System::Linq::Enumerable::Empty<RenSharpTimerStruct^>();
		}
	}

	Collections::Generic::IList<RenSharpTimerStruct^>^ RenSharpTimerManager::FindTimerList(ITimerInterface^ owner)
	{
		for each (auto timerList in timers)
		{
			if (timerList->Count > 0 && Object::ReferenceEquals(owner, timerList[0]->Owner))
			{
				return timerList;
			}
		}

		return nullptr;
	}
}