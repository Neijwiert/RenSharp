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

#include "AbstractUnmanagedObject.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <DefenseObjectClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	interface class IDamageableGameObj;

	public interface class IDefenseObjectClass : public IUnmanagedObject
	{
		literal float DefaultHealth = DEFAULT_HEALTH;
		literal int MaxMaxHealth = ::DefenseObjectClass::MAX_MAX_HEALTH;
		literal int MaxMaxShieldStrength = ::DefenseObjectClass::MAX_MAX_SHIELD_STRENGTH;
		literal int MaxMaxHealthNew = ::DefenseObjectClass::MAX_MAX_HEALTH_NEW;
		literal int MaxMaxShieldStrengthNew = ::DefenseObjectClass::MAX_MAX_SHIELD_STRENGTH_NEW;

		void MarkOwnerDirty();

		property IntPtr DefenseObjectClassPointer
		{
			IntPtr get();
		}

		property IDamageableGameObj ^Owner
		{
			IDamageableGameObj ^get();
			void set(IDamageableGameObj ^value);
		}

		property unsigned int Skin
		{
			unsigned int get();
			void set(unsigned int value);
		}

		property float Health
		{
			float get();
			void set(float value);
		}

		property float HealthMax
		{
			float get();
			void set(float value);
		}

		property float ShieldStrength
		{
			float get();
			void set(float value);
		}

		property float ShieldStrengthMax
		{
			float get();
			void set(float value);
		}

		property unsigned int ShieldType
		{
			unsigned int get();
			void set(unsigned int value);
		}

		property bool CanObjectDie
		{
			bool get();
			void set(bool value);
		}

		property float DamagePoints
		{
			float get();
			void set(float value);
		}

		property float DeathPoints
		{
			float get();
			void set(float value);
		}
	};

	public ref class DefenseObjectClass : public AbstractUnmanagedObject, public IDefenseObjectClass
	{
		public:
			DefenseObjectClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual void MarkOwnerDirty() sealed;

			property IntPtr DefenseObjectClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IDamageableGameObj ^Owner
			{
				virtual IDamageableGameObj ^get() sealed;
				virtual void set(IDamageableGameObj ^value) sealed;
			}

			property unsigned int Skin
			{
				virtual unsigned int get() sealed;
				virtual void set(unsigned int value) sealed;
			}

			property float Health
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float HealthMax
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float ShieldStrength
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float ShieldStrengthMax
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property unsigned int ShieldType
			{
				virtual unsigned int get() sealed;
				virtual void set(unsigned int value) sealed;
			}

			property bool CanObjectDie
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property float DamagePoints
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float DeathPoints
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

		protected:
			property ::DefenseObjectClass *InternalDefenseObjectClassPointer
			{
				virtual ::DefenseObjectClass *get();
			}
	};
}