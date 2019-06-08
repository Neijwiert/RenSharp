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

#pragma once

using namespace System;

namespace RenSharp
{
	ref class RenSharpTimerStruct;

	public interface class ITimerInterface : public IDisposable
	{
		void TimerExpired(int number, Object ^data);

		void StartTimer(int number, TimeSpan duration, bool repeat, Object ^data);

		void StartTimer(int number, TimeSpan duration, bool repeat);

		void StartTimer(int number, TimeSpan duration);

		void StopTimer(int number, Object ^data);

		void StopTimer(int number);

		bool IsTimer(int number, Object ^data);

		bool IsTimer(int number);

		void ClearTimers();

		property Collections::Generic::IEnumerable<RenSharpTimerStruct ^> ^Timers
		{
			Collections::Generic::IEnumerable<RenSharpTimerStruct ^> ^get();
		}
	};
}