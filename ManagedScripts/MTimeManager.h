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
	public ref class TimeManager abstract sealed
	{
		public:
			static property unsigned int SystemTicks
			{
				unsigned int get();
			}

			static property float Seconds
			{
				float get();
			}

			static property float FrameSeconds
			{
				float get();
			}

			static property float RealFrameSeconds
			{
				float get();
			}

			static property float TotalSeconds
			{
				float get();
			}

			static property int FrameTicks
			{
				int get();
			}
	};
}