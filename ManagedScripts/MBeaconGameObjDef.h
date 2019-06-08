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

#include "MSimpleGameObjDef.h"

#pragma managed(push, off)

class BeaconGameObjDef;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IBeaconGameObjDef : public ISimpleGameObjDef
	{
		property IntPtr BeaconGameObjDefPointer
		{
			IntPtr get();
		}

		property float BroadcastToAllTime
		{
			float get();
			void set(float value);
		}

		property float ArmTime
		{
			float get();
			void set(float value);
		}

		property float DisarmTime
		{
			float get();
			void set(float value);
		}

		property float PreDetonateCinematicDelay
		{
			float get();
			void set(float value);
		}

		property float DetonateTime
		{
			float get();
			void set(float value);
		}

		property float PostDetonateTime
		{
			float get();
			void set(float value);
		}

		property int ArmedSoundDefID
		{
			int get();
			void set(int value);
		}

		property int DisarmingTextID
		{
			int get();
			void set(int value);
		}

		property int DisarmedTextID
		{
			int get();
			void set(int value);
		}

		property int ArmingTextID
		{
			int get();
			void set(int value);
		}

		property int ArmingInterruptedTextID
		{
			int get();
			void set(int value);
		}

		property int DisarmingInterruptedTextID
		{
			int get();
			void set(int value);
		}

		property int PreDetonateCinematicObjDef
		{
			int get();
			void set(int value);
		}

		property int PostDetonateCinematicObjDef
		{
			int get();
			void set(int value);
		}

		property int ExplosionObjDef
		{
			int get();
			void set(int value);
		}

		property int IsNuke
		{
			int get();
			void set(int value);
		}

		property String ^ArmingAnimationName
		{
			String ^get();
			void set(String ^value);
		}

		property bool RequiresSilo
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class BeaconGameObjDef : public SimpleGameObjDef, public IBeaconGameObjDef
	{
		public:
			BeaconGameObjDef(IntPtr pointer);

			property IntPtr BeaconGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

			property float BroadcastToAllTime
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float ArmTime
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float DisarmTime
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float PreDetonateCinematicDelay
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float DetonateTime
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float PostDetonateTime
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int ArmedSoundDefID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int DisarmingTextID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int DisarmedTextID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int ArmingTextID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int ArmingInterruptedTextID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int DisarmingInterruptedTextID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int PreDetonateCinematicObjDef
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int PostDetonateCinematicObjDef
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int ExplosionObjDef
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int IsNuke
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property String ^ArmingAnimationName
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property bool RequiresSilo
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			property ::SimpleGameObjDef *InternalSimpleGameObjDefPointer
			{
				::SimpleGameObjDef *get() override;
			}

			property ::BeaconGameObjDef *InternalBeaconGameObjDefPointer
			{
				virtual ::BeaconGameObjDef *get();
			}
	};
}