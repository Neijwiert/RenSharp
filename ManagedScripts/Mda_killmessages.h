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
#include "Mda_gamefeature.h"

#pragma managed(push, off)

class DAAdvancedKillMessagesGameFeatureClass;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IDAAdvancedKillMessagesGameFeatureClass : public IDAEventClass, public IDAGameFeatureClass
	{
		property IntPtr DAAdvancedKillMessagesGameFeatureClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DAAdvancedKillMessagesGameFeatureClass : public DAEventClass, public IDAAdvancedKillMessagesGameFeatureClass
	{
		private:
			IDAGameFeatureClass^ daGameFeatureClass;

		public:
			DAAdvancedKillMessagesGameFeatureClass(IntPtr pointer);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual void Init() sealed;
			virtual IRenSharpGameFeatureClass^ AsManagedGameFeature() sealed;

			property IntPtr Pointer
			{
				IntPtr get() override;

				protected:
					void set(IntPtr value) override;
			}

			property IntPtr DAAdvancedKillMessagesGameFeatureClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr DAGameFeatureClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property String^ Name
			{
				virtual String^ get() sealed;
			}

			property IDAGameFeatureFactoryClass^ Factory
			{
				virtual IDAGameFeatureFactoryClass^ get() sealed;
				virtual void set(IDAGameFeatureFactoryClass^ value) sealed;
			}

			property bool IsManagedGameFeature
			{
				virtual bool get() sealed;
			}

		protected:
			property ::DAEventClass* InternalDAEventClassPointer
			{
				::DAEventClass* get() override;
			}

			property ::DAGameFeatureClass* InternalDAGameFeatureClassPointer
			{
				virtual ::DAGameFeatureClass* get();
			}

			property ::DAAdvancedKillMessagesGameFeatureClass* InternalDAAdvancedKillMessagesGameFeatureClassPointer
			{
				virtual ::DAAdvancedKillMessagesGameFeatureClass* get();
			}
	};
}