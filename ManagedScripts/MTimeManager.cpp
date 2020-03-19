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
#include  "MTimeManager.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)

class TimeManager
{
	public:
		static uint32 SystemTicks();

		static float Get_Seconds()
		{
			return SystemTicks() / 1000.f;
		}

		static float Get_Frame_Seconds()
		{
			return FrameSeconds;
		}

		static float Get_Real_Frame_Seconds()
		{
			return RealFrameSeconds;
		}

		static float Get_Total_Seconds()
		{
			return TotalSeconds;
		}

		static int Get_Frame_Ticks()
		{
			return FrameTicks;
		}

	private:
		static REF_DECL(float, FrameSeconds);
		static REF_DECL(float, RealFrameSeconds);
		static REF_DECL(float, TotalSeconds);
		static REF_DECL(int, FrameTicks);
};

RENEGADE_FUNCTION
unsigned int ::TimeManager::SystemTicks()
AT2(0x0069DC90, 0x0069D530);

REF_DEF2(float, ::TimeManager::FrameSeconds, 0x00857290, 0x00856478);
REF_DEF2(float, ::TimeManager::RealFrameSeconds, 0x00857294, 0x0085647C);
REF_DEF2(float, ::TimeManager::TotalSeconds, 0x00857280, 0x00856468);
REF_DEF2(int, ::TimeManager::FrameTicks, 0x00857274, 0x0085645C);

unsigned int TimeManagerSystemTicksWrapper()
{
	return ::TimeManager::SystemTicks();
}

#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	unsigned int TimeManager::SystemTicks::get()
	{
		return TimeManagerSystemTicksWrapper();
	}

	float TimeManager::Seconds::get()
	{
		return ::TimeManager::Get_Seconds();
	}

	float TimeManager::FrameSeconds::get()
	{
		return ::TimeManager::Get_Frame_Seconds();
	}

	float TimeManager::RealFrameSeconds::get()
	{
		return ::TimeManager::Get_Real_Frame_Seconds();
	}

	float TimeManager::TotalSeconds::get()
	{
		return ::TimeManager::Get_Total_Seconds();
	}

	int TimeManager::FrameTicks::get()
	{
		return ::TimeManager::Get_Frame_Ticks();
	}
}