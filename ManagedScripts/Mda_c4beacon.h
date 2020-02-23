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

#include "Mda_event.h"

#pragma managed(push, off)

class DAC4BeaconManager;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IDAC4BeaconManager : public IDAEventClass
	{
		property IntPtr DAC4BeaconManagerPointer
		{
			IntPtr get();
		}
	};

	public ref class DAC4BeaconManager : public DAEventClass, public IDAC4BeaconManager
	{
		// Although you can instantiate a DAC4BeaconManager class, it doesn't make any sense so I left it out
		public:
			DAC4BeaconManager(IntPtr pointer);

			property IntPtr DAC4BeaconManagerPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::DAEventClass* InternalDAEventClassPointer
			{
				::DAEventClass* get() override;
			}

			property ::DAC4BeaconManager* InternalDAC4BeaconManagerPointer
			{
				virtual ::DAC4BeaconManager* get();
			}
	};
}