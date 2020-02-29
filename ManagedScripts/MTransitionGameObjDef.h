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

#include "Mobboxclass.h"
#include "MMatrix3D.h"
#include "Mengine_vector.h"
#include "MBaseGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <TransitionGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	public interface class ITransitionDataClass : public IUnmanagedObject
	{
		enum class StyleType : int
		{
			LadderExitTop = ::TransitionDataClass::LADDER_EXIT_TOP,
			LadderExitBottom = ::TransitionDataClass::LADDER_EXIT_BOTTOM,
			LadderEnterTop = ::TransitionDataClass::LADDER_ENTER_TOP,
			LadderEnterBottom = ::TransitionDataClass::LADDER_ENTER_BOTTOM,
			LegacyVehicleEnter0 = ::TransitionDataClass::LEGACY_VEHICLE_ENTER_0,
			LegacyVehicleEnter1 = ::TransitionDataClass::LEGACY_VEHICLE_ENTER_1,
			LegacyVehicleExit0 = ::TransitionDataClass::LEGACY_VEHICLE_EXIT_0,
			LegacyVehicleExit1 = ::TransitionDataClass::LEGACY_VEHICLE_EXIT_1,
			VehicleEnter = ::TransitionDataClass::VEHICLE_ENTER,
			VehicleExit = ::TransitionDataClass::VEHICLE_EXIT
		};

		property IntPtr TransitionDataClassPointer
		{
			IntPtr get();
		}

		property StyleType Type
		{
			StyleType get();
			void set(StyleType value);
		}

		property OBBoxClass TriggerZone
		{
			OBBoxClass get();
			void set(OBBoxClass value);
		}

		property String ^AnimationName
		{
			String ^get();
			void set(String ^value);
		}

		property Matrix3D CharacterTransform
		{
			Matrix3D get();
			void set(Matrix3D value);
		}
	};

	public ref class TransitionDataClass : public AbstractUnmanagedObject, public ITransitionDataClass
	{
		private:
			TransitionDataClass();

		public:
			TransitionDataClass(IntPtr pointer);

			static IUnmanagedContainer<ITransitionDataClass ^> ^CreateTransitionDataClass();

			bool Equals(Object ^other) override;

			property IntPtr TransitionDataClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property ITransitionDataClass::StyleType Type
			{
				virtual ITransitionDataClass::StyleType get() sealed;
				virtual void set(ITransitionDataClass::StyleType value) sealed;
			}

			property OBBoxClass TriggerZone
			{
				virtual OBBoxClass get() sealed;
				virtual void set(OBBoxClass value) sealed;
			}

			property String ^AnimationName
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property Matrix3D CharacterTransform
			{
				virtual Matrix3D get() sealed;
				virtual void set(Matrix3D value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::TransitionDataClass *InternalTransitionDataClassPointer
			{
				virtual ::TransitionDataClass *get();
			}
	};

	public interface class ITransitionGameObjDef : public IBaseGameObjDef
	{
		literal unsigned int TransitionGameObjDefClassID = 12303;

		property IntPtr TransitionGameObjDefPointer
		{
			IntPtr get();
		}

		property IDynamicVectorClass<ITransitionDataClass ^> ^Transitions
		{
			IDynamicVectorClass<ITransitionDataClass ^> ^get();
			void set(IDynamicVectorClass<ITransitionDataClass ^> ^value);
		}
	};

	public ref class TransitionGameObjDef : public BaseGameObjDef, public ITransitionGameObjDef
	{
		public:
			TransitionGameObjDef(IntPtr pointer);

			property IntPtr TransitionGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

			property IDynamicVectorClass<ITransitionDataClass ^> ^Transitions
			{
				virtual IDynamicVectorClass<ITransitionDataClass ^> ^get() sealed;
				virtual void set(IDynamicVectorClass<ITransitionDataClass ^> ^value) sealed;
			}

		protected:
			property ::BaseGameObjDef *InternalBaseGameObjDefPointer
			{
				::BaseGameObjDef *get() override;
			}

			property ::TransitionGameObjDef *InternalTransitionGameObjDefPointer
			{
				virtual ::TransitionGameObjDef *get();
			}
	};
}