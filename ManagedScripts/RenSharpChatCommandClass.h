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
#include "Mda_event.h"

namespace RenSharp
{
	// To keep consistency with the calling order, this is implemented in our own way and not hooked into dragonade
	public ref class RenSharpChatCommandClass abstract : public ITimerInterface
	{
		private:
			bool disposedResources;
			array<String^>^ triggers;
			DAAccessLevel accessLevel;
			DAChatType chatType;
			int parameters;

		public:
			RenSharpChatCommandClass(String^ triggers, DAAccessLevel accessLevel, DAChatType chatType, int parameters);
			RenSharpChatCommandClass(String^ triggers, DAAccessLevel accessLevel, DAChatType chatType);
			RenSharpChatCommandClass(String^ triggers, DAAccessLevel accessLevel);
			RenSharpChatCommandClass(String^ triggers);
			~RenSharpChatCommandClass();

			void RegisterManagedObject();

			bool HasTrigger(String^ trigger);

			virtual bool Activate(IcPlayer^ player, IDATokenClass ^text, TextMessageEnum chatType) = 0;

			virtual void TimerExpired(int number, Object^ data) sealed;
			virtual void StartTimer(int number, TimeSpan duration, bool repeat, Object^ data) sealed;
			virtual void StartTimer(int number, TimeSpan duration, bool repeat) sealed;
			virtual void StartTimer(int number, TimeSpan duration) sealed;
			virtual void StartTimer(TimeSpan duration, bool repeat, System::Action<RenSharpTimerStruct^>^ action) sealed;
			virtual void StartTimer(TimeSpan duration, System::Action<RenSharpTimerStruct^>^ action) sealed;
			virtual void StopTimer(int number, Object^ data) sealed;
			virtual void StopTimer(int number) sealed;
			virtual void StopTimer(System::Action<RenSharpTimerStruct^>^ action) sealed;
			virtual bool IsTimer(int number, Object^ data) sealed;
			virtual bool IsTimer(int number) sealed;
			virtual bool IsTimer(System::Action<RenSharpTimerStruct^>^ action) sealed;
			virtual void ClearTimers() sealed;

			property Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ Timers
			{
				virtual Collections::Generic::IEnumerable<RenSharpTimerStruct^>^ get() sealed;
			}

			property array<String^>^ Triggers
			{
				array<String^>^ get();

				protected:
					void set(array<String^>^ value);
			}

			property DAAccessLevel AccessLevel
			{
				DAAccessLevel get();

				protected:
					void set(DAAccessLevel value);
			}

			property DAChatType ChatType
			{
				DAChatType get();

				protected:
					void set(DAChatType value);
			}

			property int Parameters
			{
				int get();

				protected:
					void set(int value);
			}
	};
}