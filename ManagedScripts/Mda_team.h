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

#include "Mda_event.h"

#pragma managed(push, off)

class DATeamManager;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IDATeamManager : public IDAEventClass
	{
		property IntPtr DATeamManagerPointer
		{
			IntPtr get();
		}
	};

	public ref class DATeamManager : public DAEventClass, public IDATeamManager
	{
		// Although you can instantiate a DATeamManager class, it doesn't make any sense so I left it out
		public:
			DATeamManager(IntPtr pointer);

			static void Remix();
			static void Rebalance();
			static void Swap();

			static property int ForceTeam
			{
				int get();
				void set(int value);
			}

			static property bool IsFreeTeamChangingEnabled
			{
				bool get();
			}

			property IntPtr DATeamManagerPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::DAEventClass* InternalDAEventClassPointer
			{
				::DAEventClass* get() override;
			}

			property ::DATeamManager* InternalDATeamManagerPointer
			{
				virtual ::DATeamManager* get();
			}
	};
}