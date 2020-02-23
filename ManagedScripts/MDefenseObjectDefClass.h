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

#include "IUnmanagedObject.h"
#include "AbstractUnmanagedObject.h"

#pragma managed(push, off)

class DefenseObjectDefClass;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IDefenseObjectDefClass : public IUnmanagedObject
	{
		property IntPtr DefenseObjectDefClassPointer
		{
			IntPtr get();
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

		property unsigned int Skin
		{
			unsigned int get();
			void set(unsigned int value);
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

	public ref class DefenseObjectDefClass : public AbstractUnmanagedObject, public IDefenseObjectDefClass
	{
		public:
			DefenseObjectDefClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			property IntPtr DefenseObjectDefClassPointer
			{
				virtual IntPtr get() sealed;
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

			property unsigned int Skin
			{
				virtual unsigned int get() sealed;
				virtual void set(unsigned int value) sealed;
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
			property ::DefenseObjectDefClass *InternalDefenseObjectDefClassPointer
			{
				virtual ::DefenseObjectDefClass *get();
			}
	};
}