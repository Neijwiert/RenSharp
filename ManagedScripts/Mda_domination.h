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

#include "Mda_nodemanager.h"
#include "Mda_event.h"
#include "Mda_gamemode.h"

#pragma managed(push, off)

class DAControlNodeClass;
class DATiberiumNodeClass;
class DADominationManagerClass;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IDAControlNodeClass : public IDASpawnNodeClass
	{
		property IntPtr DAControlNodeClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DAControlNodeClass : public DASpawnNodeClass, public IDAControlNodeClass
	{
		public:
			DAControlNodeClass(IntPtr pointer);

#pragma push_macro("ControlNodeType")
#undef ControlNodeType
			static property String^ ControlNodeType
			{
				String^ get();
			}
#pragma pop_macro("ControlNodeType")

			property IntPtr DAControlNodeClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::DASpawnNodeClass* InternalDASpawnNodeClassPointer
			{
				::DASpawnNodeClass* get() override;
			}

			property ::DAControlNodeClass* InternalDAControlNodeClassPointer
			{
				virtual ::DAControlNodeClass* get();
			}
	};

	public interface class IDATiberiumNodeClass : public IDABaseNodeClass
	{
		property IntPtr DATiberiumNodeClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DATiberiumNodeClass : public DABaseNodeClass, public IDATiberiumNodeClass
	{
		public:
			DATiberiumNodeClass(IntPtr pointer);

#pragma push_macro("TiberiumNodeType")
#undef TiberiumNodeType
			static property String^ TiberiumNodeType
			{
				String^ get();
			}
#pragma pop_macro("TiberiumNodeType")

			property IntPtr DATiberiumNodeClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::DABaseNodeClass* InternalDABaseNodeClassPointer
			{
				::DABaseNodeClass* get() override;
			}

			property ::DATiberiumNodeClass* InternalDATiberiumNodeClassPointer
			{
				virtual ::DATiberiumNodeClass* get();
			}
	};

	public interface class IDADominationManagerClass : public IDAEventClass, public IDAGameModeClass
	{
		void IncrementCredits(int team);

		property IntPtr DADominationManagerClassPointer
		{
			IntPtr get();
		}

		property String^ ControlNodePreset
		{
			String^ get();
		}

		property String^ ControlNodeModel
		{
			String^ get();
		}

		property String^ ControlNodeAnimation
		{
			String^ get();
		}

		property String^ TiberiumNodePreset
		{
			String^ get();
		}

		property String^ TiberiumNodeModel
		{
			String^ get();
		}

		property String^ TiberiumNodeAnimation
		{
			String^ get();
		}

		property float PointTickAmount
		{
			float get();
		}

		property TimeSpan PointTickTime
		{
			TimeSpan get();
		}

		property float CreditTickAmount
		{
			float get();
		}

		property TimeSpan CreditTickTime
		{
			TimeSpan get();
		}
	};

	public ref class DADominationManagerClass : public DAEventClass, public IDADominationManagerClass
	{
		private:
			IDAGameModeClass^ daGameModeClass;

		public:
			DADominationManagerClass(IntPtr pointer);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual void Init() sealed;
			virtual IRenSharpGameModeClass^ AsManagedGameMode() sealed;

			virtual void IncrementCredits(int team) sealed;

			property IntPtr Pointer
			{
				IntPtr get() override;

				protected:
					void set(IntPtr value) override;
			}

			property IntPtr DADominationManagerClassPointer
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

			property String^ ControlNodePreset
			{
				virtual String^ get() sealed;
			}

			property String^ ControlNodeModel
			{
				virtual String^ get() sealed;
			}

			property String^ ControlNodeAnimation
			{
				virtual String^ get() sealed;
			}

			property String^ TiberiumNodePreset
			{
				virtual String^ get() sealed;
			}

			property String^ TiberiumNodeModel
			{
				virtual String^ get() sealed;
			}

			property String^ TiberiumNodeAnimation
			{
				virtual String^ get() sealed;
			}

			property float PointTickAmount
			{
				virtual float get() sealed;
			}

			property TimeSpan PointTickTime
			{
				virtual TimeSpan get() sealed;
			}

			property float CreditTickAmount
			{
				virtual float get() sealed;
			}

			property TimeSpan CreditTickTime
			{
				virtual TimeSpan get() sealed;
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

			property ::DADominationManagerClass* InternalDADominationManagerClassPointer
			{
				virtual ::DADominationManagerClass* get();
			}
	};
}