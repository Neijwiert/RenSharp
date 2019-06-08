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

#include "ITimerInterface.h"

namespace RenSharp
{
	interface class IcPlayer;

	// To keep consistency with the calling order, this is implemented in our own way and not hooked into dragonade
	public ref class RenSharpKeyHookClass abstract : public ITimerInterface
	{
		private:
			bool disposedResources;
			array<String^>^ triggers;

		public:
			RenSharpKeyHookClass(String^ triggers);
			~RenSharpKeyHookClass();

			void RegisterManagedObject();

			bool HasTrigger(String^ trigger);

			virtual bool Activate(IcPlayer^ player) = 0;

			virtual void TimerExpired(int number, Object^ data) sealed;
			virtual void StartTimer(int number, TimeSpan duration, bool repeat, Object^ data) sealed;
			virtual void StartTimer(int number, TimeSpan duration, bool repeat) sealed;
			virtual void StartTimer(int number, TimeSpan duration) sealed;
			virtual void StopTimer(int number, Object^ data) sealed;
			virtual void StopTimer(int number) sealed;
			virtual bool IsTimer(int number, Object^ data) sealed;
			virtual bool IsTimer(int number) sealed;
			virtual void ClearTimers() sealed;

			property Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ Timers
			{
				virtual Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ get() sealed;
			}

			property array<String^>^ Triggers
			{
				array<String^>^ get();
			}
	};
}