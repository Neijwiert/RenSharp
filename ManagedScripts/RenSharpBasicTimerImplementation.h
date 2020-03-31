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

#include "ITimerInterface.h"

namespace RenSharp
{
	public ref class RenSharpBasicTimerImplementation abstract : ITimerInterface
	{
		public:
			~RenSharpBasicTimerImplementation();

			virtual void ClearTimers() sealed;
			virtual bool IsTimer(System::Action<RenSharpTimerStruct^>^ action) sealed;
			virtual bool IsTimer(int number) sealed;
			virtual bool IsTimer(int number, System::Object^ data) sealed;
			virtual void StartTimer(TimeSpan duration, System::Action<RenSharpTimerStruct^>^ action) sealed;
			virtual void StartTimer(TimeSpan duration, bool repeat, System::Action<RenSharpTimerStruct^>^ action) sealed;
			virtual void StartTimer(int number, TimeSpan duration) sealed;
			virtual void StartTimer(int number, TimeSpan duration, bool repeat) sealed;
			virtual void StartTimer(int number, TimeSpan duration, bool repeat, System::Object^ data) sealed;
			virtual void StopTimer(System::Action<RenSharpTimerStruct^>^ action) sealed;
			virtual void StopTimer(int number) sealed;
			virtual void StopTimer(int number, System::Object^ data) sealed;
			virtual void TimerExpired(int number, System::Object^ data);

			property System::Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ Timers
			{
				virtual System::Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ get() sealed;
			}

		protected:
			!RenSharpBasicTimerImplementation();
	};
}