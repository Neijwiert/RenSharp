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

#include "AbstractUnmanagedObject.h"
#include "MTransitionGameObjDef.h"

#pragma managed(push, off)

class TransitionInstanceClass;

#pragma managed(pop)

namespace RenSharp
{

#pragma warning(push)
#pragma warning(disable : 4099 4251 4244 26495 26454)

	value class Matrix3D;
	value class OBBoxClass;
	interface class IVehicleGameObj;

#pragma warning(pop) 
	
	public interface class ITransitionInstanceClass : public IUnmanagedObject
	{
		void SetVehicle(IVehicleGameObj ^obj);

		void SetLadderIndex(int index);

		property IntPtr TransitionInstanceClassPointer
		{
			IntPtr get();
		}

		property ITransitionDataClass::StyleType Type
		{
			ITransitionDataClass::StyleType get();
		}

		property OBBoxClass TriggerZone
		{
			OBBoxClass get();
			void set(OBBoxClass value);
		}

		property Matrix3D CharacterTransform
		{
			Matrix3D get();
			void set(Matrix3D value);
		}
	};

	public ref class TransitionInstanceClass : public AbstractUnmanagedObject, public ITransitionInstanceClass
	{
		public:
			TransitionInstanceClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual void SetVehicle(IVehicleGameObj ^obj) sealed;
			virtual void SetLadderIndex(int index) sealed;

			property IntPtr TransitionInstanceClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property ITransitionDataClass::StyleType Type
			{
				virtual ITransitionDataClass::StyleType get() sealed;
			}

			property OBBoxClass TriggerZone
			{
				virtual OBBoxClass get() sealed;
				virtual void set(OBBoxClass value) sealed;
			}

			property Matrix3D CharacterTransform
			{
				virtual Matrix3D get() sealed;
				virtual void set(Matrix3D value) sealed;
			}

		protected:
			property ::TransitionInstanceClass *InternalTransitionInstanceClassPointer
			{
				virtual ::TransitionInstanceClass *get();
			}
	};
}