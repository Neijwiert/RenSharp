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
#include "Mda_gamemode.h"

#pragma managed(push, off)

class DAShotgunGameModeClass;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IDAShotgunGameModeClass : public IDAEventClass, public IDAGameModeClass
	{
		property IntPtr DAShotgunGameModeClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DAShotgunGameModeClass : public DAEventClass, public IDAShotgunGameModeClass
	{
		private:
			IDAGameModeClass^ daGameModeClass;

		public:
			DAShotgunGameModeClass(IntPtr pointer);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual void Init() sealed;
			virtual IRenSharpGameModeClass^ AsManagedGameMode() sealed;

			property IntPtr Pointer
			{
				IntPtr get() override;

				protected:
					void set(IntPtr value) override;
			}

			property IntPtr DAShotgunGameModeClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr DAGameModeClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property String^ LongName
			{
				virtual String^ get() sealed;
			}

			property String^ ShortName
			{
				virtual String^ get() sealed;
			}

			property IDAGameModeFactoryClass^ Factory
			{
				virtual IDAGameModeFactoryClass^ get() sealed;
				virtual void set(IDAGameModeFactoryClass^ value) sealed;
			}

			property bool IsManagedGameMode
			{
				virtual bool get() sealed;
			}

		protected:
			property ::DAEventClass* InternalDAEventClassPointer
			{
				::DAEventClass* get() override;
			}

			property ::DAGameModeClass* InternalDAGameModeClassPointer
			{
				virtual ::DAGameModeClass* get();
			}

			property ::DAShotgunGameModeClass* InternalDAShotgunGameModeClassPointer
			{
				virtual ::DAShotgunGameModeClass* get();
			}
	};
}