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

using namespace System;

namespace RenSharp
{
	interface class ITimerInterface;

	public ref class RenSharpTimerStruct sealed
	{
		private:
			ITimerInterface ^owner;
			DateTime startTime;
			TimeSpan duration;
			bool repeat;
			int number;
			Object ^data;
			Action<RenSharpTimerStruct^>^ action;

		public:
			RenSharpTimerStruct(ITimerInterface ^owner, TimeSpan duration, bool repeat, int number, Object ^data);
			RenSharpTimerStruct(ITimerInterface^ owner, TimeSpan duration, bool repeat, System::Action<RenSharpTimerStruct^>^ action);

			void Reset();

			property ITimerInterface ^Owner
			{
				ITimerInterface ^get();
			}

			property DateTime StartTime
			{
				DateTime get();
			}

			property TimeSpan Duration
			{
				TimeSpan get();
				void set(TimeSpan value);
			}

			property bool Repeat
			{
				bool get();
				void set(bool value);
			}

			property int Number
			{
				int get();
				void set(int value);
			}

			property Object ^Data
			{
				Object ^get();
				void set(Object ^value);
			}

			property System::Action<RenSharpTimerStruct^>^ Action
			{
				System::Action<RenSharpTimerStruct^>^ get();
				void set(System::Action<RenSharpTimerStruct^>^ value);
			}
	};
}