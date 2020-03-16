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
#include "RenSharpTimerStruct.h"

namespace RenSharp
{
	RenSharpTimerStruct::RenSharpTimerStruct(ITimerInterface^ owner, TimeSpan duration, bool repeat, int number, Object^ data)
		: owner(owner), startTime(DateTime::Now), duration(duration), repeat(repeat), number(number), data(data), action(nullptr)
	{
	}

	RenSharpTimerStruct::RenSharpTimerStruct(ITimerInterface^ owner, TimeSpan duration, bool repeat, System::Action<RenSharpTimerStruct^>^ action)
		: owner(owner), startTime(DateTime::Now), duration(duration), repeat(repeat), number(int::MinValue), data(nullptr), action(action)
	{
	}

	void RenSharpTimerStruct::Reset()
	{
		startTime = DateTime::Now;
	}

	ITimerInterface^ RenSharpTimerStruct::Owner::get()
	{
		return owner;
	}

	DateTime RenSharpTimerStruct::StartTime::get()
	{
		return startTime;
	}

	TimeSpan RenSharpTimerStruct::Duration::get()
	{
		return duration;
	}

	void RenSharpTimerStruct::Duration::set(TimeSpan value)
	{
		duration = value;
	}

	bool RenSharpTimerStruct::Repeat::get()
	{
		return repeat;
	}

	void RenSharpTimerStruct::Repeat::set(bool value)
	{
		repeat = value;
	}

	int RenSharpTimerStruct::Number::get()
	{
		return number;
	}

	void RenSharpTimerStruct::Number::set(int value)
	{
		number = value;
	}

	Object^ RenSharpTimerStruct::Data::get()
	{
		return data;
	}

	void RenSharpTimerStruct::Data::set(Object^ value)
	{
		data = value;
	}

	Action<RenSharpTimerStruct^>^ RenSharpTimerStruct::Action::get()
	{
		return action;
	}

	void RenSharpTimerStruct::Action::set(System::Action<RenSharpTimerStruct^>^ value)
	{
		action = value;
	}
}