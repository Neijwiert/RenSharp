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

#include "RenSharpEventClass.h"

namespace RenSharp
{
	ref class RenSharpTimerStruct;

	public ref class RenSharpTimerManager : public RenSharpEventClass
	{
		private:
			bool disposedResources;

			static Collections::Generic::IDictionary<ITimerInterface^, Collections::Generic::IList<RenSharpTimerStruct^>^>^ timers;

		public:
			static RenSharpTimerManager();

			RenSharpTimerManager();
			~RenSharpTimerManager();

			void UnmanagedAttach() override;
			void Think() override;

			static void StartTimer(ITimerInterface^ owner, int number, TimeSpan duration, bool repeat, Object^ data);
			static void StartTimer(ITimerInterface^ owner, int number, TimeSpan duration, bool repeat);
			static void StartTimer(ITimerInterface^ owner, int number, TimeSpan duration);
			static void StopTimer(ITimerInterface^ owner, int number, Object^ data);
			static void StopTimer(ITimerInterface^ owner, int number);
			static bool IsTimer(ITimerInterface^ owner, int number, Object^ data);
			static bool IsTimer(ITimerInterface^ owner, int number);
			static void ClearTimers(ITimerInterface^ owner);
			static Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ GetTimers(ITimerInterface^ owner);
	};
}