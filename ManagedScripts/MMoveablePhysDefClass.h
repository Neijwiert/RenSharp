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

#include "MDynamicPhysDefClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <MoveablePhysDefClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	public interface class IMoveablePhysDefClass : public IDynamicPhysDefClass
	{
		enum class CinematicCollision : int
		{
			CinematicCollisionNone = ::MoveablePhysDefClass::CINEMATIC_COLLISION_NONE,
			CinematicCollisionStop = ::MoveablePhysDefClass::CINEMATIC_COLLISION_STOP,
			CinematicCollisionPush = ::MoveablePhysDefClass::CINEMATIC_COLLISION_PUSH,
			CinematicCollisionKill = ::MoveablePhysDefClass::CINEMATIC_COLLISION_KILL
		};

		literal String^ MoveablePhysDefClassTypeName = "MoveablePhysDef";

		property IntPtr MoveablePhysDefClassPointer
		{
			IntPtr get();
		}

		property float Mass
		{
			float get();
			void set(float value);
		}

		property float GravScale
		{
			float get();
			void set(float value);
		}

		property float Elasticity
		{
			float get();
			void set(float value);
		}

		property int CinematicCollisionMode
		{
			int get();
			void set(int value);
		}
	};

	public ref class MoveablePhysDefClass : public DynamicPhysDefClass, public IMoveablePhysDefClass
	{
		public:
			MoveablePhysDefClass(IntPtr pointer);

			property IntPtr MoveablePhysDefClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property float Mass
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float GravScale
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float Elasticity
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int CinematicCollisionMode
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

		protected:
			property ::DynamicPhysDefClass *InternalDynamicPhysDefClassPointer
			{
				::DynamicPhysDefClass *get() override;
			}

			property ::MoveablePhysDefClass *InternalMoveablePhysDefClassPointer
			{
				virtual ::MoveablePhysDefClass *get();
			}
	};
}