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

class DALogManager;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IDALogManager : public IDAEventClass
	{
		property IntPtr DALogManagerPointer
		{
			IntPtr get();
		}
	};

	public ref class DALogManager : public DAEventClass, public IDALogManager
	{
		// Although you can instantiate a DALogManager class, it doesn't make any sense so I left it out
		public:
			DALogManager(IntPtr pointer);

			static void WriteLog(String^ header, String^ format, ...array<Object^>^ args);
			static void WriteGameLog(String^ format, ...array<Object^>^ args);
			static void Send(String^ data);

			property IntPtr DALogManagerPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::DAEventClass* InternalDAEventClassPointer
			{
				::DAEventClass* get() override;
			}

			property ::DALogManager* InternalDALogManagerPointer
			{
				virtual ::DALogManager* get();
			}
	};
}