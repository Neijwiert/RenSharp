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

class PhysControllerClass;

#pragma managed(pop)

namespace RenSharp
{

#pragma warning(push)
#pragma warning(disable : 4099 4251 4244 26495 26454)

	value class Vector3;

#pragma warning(pop) 

	public interface class IPhysControllerClass : public IUnmanagedObject
	{
		void Reset();

		void ResetMove();

		void ResetTurn();

		property IntPtr PhysControllerClassPointer
		{
			IntPtr get();
		}

		property float MoveForward
		{
			float get();
			void set(float value);
		}

		property float MoveLeft
		{
			float get();
			void set(float value);
		}

		property float MoveUp
		{
			float get();
			void set(float value);
		}

		property float TurnLeft
		{
			float get();
			void set(float value);
		}

		property Vector3 MoveVector
		{
			Vector3 get();
		}

		property bool IsInactive
		{
			bool get();
		}
	};

	public ref class PhysControllerClass : public AbstractUnmanagedObject, public IPhysControllerClass
	{
		private:
			PhysControllerClass();

		public:
			PhysControllerClass(IntPtr pointer);

			static IUnmanagedContainer<IPhysControllerClass ^> ^CreatePhysControllerClass();

			bool Equals(Object ^other) override;

			virtual void Reset() sealed;
			virtual void ResetMove() sealed;
			virtual void ResetTurn() sealed;

			property IntPtr PhysControllerClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property float MoveForward
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float MoveLeft
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float MoveUp
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float TurnLeft
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property Vector3 MoveVector
			{
				virtual Vector3 get() sealed;
			}

			property bool IsInactive
			{
				virtual bool get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::PhysControllerClass *InternalPhysControllerClassPointer
			{
				virtual ::PhysControllerClass *get();
			}
	};
}