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
#include "IUnmanagedContainer.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <ReferencerClass.h> // Stupid OffenseObjectClass.h does not include this
#include <OffenseObjectClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	interface class IArmedGameObj;

	public interface class IOffenseObjectClass : public IUnmanagedObject
	{
		literal float DefaultDamage = DEFAULT_DAMAGE;

		void ScaleDamage(float scale);

		property IntPtr OffenseObjectClassPointer
		{
			IntPtr get();
		}

		property float Damage
		{
			float get();
			void set(float value);
		}

		property unsigned int Warhead
		{
			unsigned int get();
			void set(unsigned int value);
		}

		property IArmedGameObj ^Owner
		{
			IArmedGameObj ^get();
			void set(IArmedGameObj ^value);
		}

		property bool ForceServerDamage
		{
			bool get();
			void set(bool value);
		}

		property bool EnableClientDamage
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class OffenseObjectClass : public AbstractUnmanagedObject, public IOffenseObjectClass
	{
		private:
			OffenseObjectClass(float damage, unsigned int warhead, IArmedGameObj ^owner);
			OffenseObjectClass(float damage, unsigned int warhead);
			OffenseObjectClass(float damage);
			OffenseObjectClass();

		public:
			OffenseObjectClass(IntPtr pointer);

			static IUnmanagedContainer<IOffenseObjectClass ^> ^CreateOffenseObjectClass(float damage, unsigned int warhead, IArmedGameObj ^owner);
			static IUnmanagedContainer<IOffenseObjectClass ^> ^CreateOffenseObjectClass(float damage, unsigned int warhead);
			static IUnmanagedContainer<IOffenseObjectClass ^> ^CreateOffenseObjectClass(float damage);
			static IUnmanagedContainer<IOffenseObjectClass ^> ^CreateOffenseObjectClass();

			bool Equals(Object ^other) override;

			virtual void ScaleDamage(float scale) sealed;

			property IntPtr OffenseObjectClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property float Damage
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property unsigned int Warhead
			{
				virtual unsigned int get() sealed;
				virtual void set(unsigned int value) sealed;
			}

			property IArmedGameObj ^Owner
			{
				virtual IArmedGameObj ^get() sealed;
				virtual void set(IArmedGameObj ^value) sealed;
			}

			property bool ForceServerDamage
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool EnableClientDamage
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::OffenseObjectClass *InternalOffenseObjectClassPointer
			{
				virtual ::OffenseObjectClass *get();
			}
	};
}