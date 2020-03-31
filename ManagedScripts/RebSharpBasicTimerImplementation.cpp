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
#include "RenSharpBasicTimerImplementation.h"

#include "RenSharpTimerManager.h"

namespace RenSharp
{
	RenSharpBasicTimerImplementation::~RenSharpBasicTimerImplementation()
	{
		this->!RenSharpBasicTimerImplementation();
	}

	void RenSharpBasicTimerImplementation::ClearTimers()
	{
		RenSharpTimerManager::ClearTimers(this);
	}

	bool RenSharpBasicTimerImplementation::IsTimer(System::Action<RenSharpTimerStruct^>^ action)
	{
		return RenSharpTimerManager::IsTimer(this, action);
	}

	bool RenSharpBasicTimerImplementation::IsTimer(int number)
	{
		return RenSharpTimerManager::IsTimer(this, number);
	}

	bool RenSharpBasicTimerImplementation::IsTimer(int number, System::Object^ data)
	{
		return RenSharpTimerManager::IsTimer(this, number, data);
	}

	void RenSharpBasicTimerImplementation::StartTimer(TimeSpan duration, System::Action<RenSharpTimerStruct^>^ action)
	{
		RenSharpTimerManager::StartTimer(this, duration, action);
	}

	void RenSharpBasicTimerImplementation::StartTimer(TimeSpan duration, bool repeat, System::Action<RenSharpTimerStruct^>^ action)
	{
		RenSharpTimerManager::StartTimer(this, duration, repeat, action);
	}

	void RenSharpBasicTimerImplementation::StartTimer(int number, TimeSpan duration)
	{
		RenSharpTimerManager::StartTimer(this, number, duration);
	}

	void RenSharpBasicTimerImplementation::StartTimer(int number, TimeSpan duration, bool repeat)
	{
		RenSharpTimerManager::StartTimer(this, number, duration, repeat);
	}

	void RenSharpBasicTimerImplementation::StartTimer(int number, TimeSpan duration, bool repeat, System::Object^ data)
	{
		RenSharpTimerManager::StartTimer(this, number, duration, repeat, data);
	}

	void RenSharpBasicTimerImplementation::StopTimer(System::Action<RenSharpTimerStruct^>^ action)
	{
		RenSharpTimerManager::StopTimer(this, action);
	}

	void RenSharpBasicTimerImplementation::StopTimer(int number)
	{
		RenSharpTimerManager::StopTimer(this, number);
	}

	void RenSharpBasicTimerImplementation::StopTimer(int number, System::Object^ data)
	{
		RenSharpTimerManager::StopTimer(this, number, data);
	}

	void RenSharpBasicTimerImplementation::TimerExpired(int number, System::Object^ data)
	{
		
	}

	System::Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ RenSharpBasicTimerImplementation::Timers::get()
	{
		return RenSharpTimerManager::GetTimers(this);
	}

	RenSharpBasicTimerImplementation::!RenSharpBasicTimerImplementation()
	{
		ClearTimers();
	}
}