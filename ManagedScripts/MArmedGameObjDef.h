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

#include "MPhysicalGameObjDef.h"

#pragma managed(push, off)

class ArmedGameObjDef;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IArmedGameObjDef : public IPhysicalGameObjDef
	{
		property IntPtr ArmedGameObjDefPointer
		{
			IntPtr get();
		}

		property float WeaponTiltRate
		{
			float get();
			void set(float value);
		}

		property float WeaponTiltMin
		{
			float get();
			void set(float value);
		}

		property float WeaponTiltMax
		{
			float get();
			void set(float value);
		}

		property float WeaponTurnRate
		{
			float get();
			void set(float value);
		}

		property float WeaponTurnMin
		{
			float get();
			void set(float value);
		}

		property float WeaponTurnMax
		{
			float get();
			void set(float value);
		}

		property float WeaponError
		{
			float get();
			void set(float value);
		}

		property int WeaponDefID
		{
			int get();
			void set(int value);
		}

		property int SecondaryWeaponDefID
		{
			int get();
			void set(int value);
		}

		property int WeaponRounds
		{
			int get();
			void set(int value);
		}
	};

	public ref class ArmedGameObjDef : public PhysicalGameObjDef, public IArmedGameObjDef
	{
		public:
			ArmedGameObjDef(IntPtr pointer);

			property IntPtr ArmedGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

			property float WeaponTiltRate
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float WeaponTiltMin
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float WeaponTiltMax
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float WeaponTurnRate
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float WeaponTurnMin
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float WeaponTurnMax
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float WeaponError
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int WeaponDefID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int SecondaryWeaponDefID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int WeaponRounds
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

		protected:
			property ::PhysicalGameObjDef *InternalPhysicalGameObjDefPointer
			{
				::PhysicalGameObjDef *get() override;
			}

			property ::ArmedGameObjDef *InternalArmedGameObjDefPointer
			{
				virtual ::ArmedGameObjDef *get();
			}
	};
}