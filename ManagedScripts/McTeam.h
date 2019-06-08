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

#include "MNetworkObjectClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <cTeam.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	public interface class IcTeam : public INetworkObjectClass
	{
		literal int MaxTeams = MAX_TEAMS;

		property IntPtr cTeamPointer
		{
			IntPtr get();
		}

		property String ^Name
		{
			String^ get();
		}

		property int ID
		{
			int get();
		}

		property int Kills
		{
			int get();
			void set(int value);
		}

		property int Deaths
		{
			int get();
			void set(int value);
		}

		property float Score
		{
			float get();
			void set(float value);
		}

		property float KillToDeathRatio
		{
			float get();
		}
	};

	public ref class cTeam : public NetworkObjectClass, public IcTeam
	{
		public:
			cTeam(IntPtr pointer);

			String ^ToString() override;

			property IntPtr cTeamPointer
			{
				virtual IntPtr get() sealed;
			}

			property String^ Name
			{
				virtual String^ get() sealed;
			}

			property int ID
			{
				virtual int get() sealed;
			}

			property int Kills
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int Deaths
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property float Score
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float KillToDeathRatio
			{
				virtual float get() sealed;
			}

		protected:
			property ::NetworkObjectClass* InternalNetworkObjectClassPointer
			{
				::NetworkObjectClass* get() override;
			}

			property ::cTeam* InternalcTeamPointer
			{
				virtual ::cTeam* get();
			}
	};
}