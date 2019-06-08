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

#include "MDynamicPhysClass.h"
#include "Mmultilist.h"

#pragma managed(push, off)

class MoveablePhysClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IMoveablePhysDefClass;
	value class Matrix3;
	value class Matrix3D;
	interface class IPhysControllerClass;
	interface class IRenderObjClass;
	interface class IDynamicShadowManagerClass;

	public interface class IMoveablePhysClass : public IDynamicPhysClass
	{
		void SetMass(float mass);

		bool CanTeleport(Matrix3D newTM, bool checkDynOnly, IMultiListClass<IPhysClass ^> ^resultList);

		bool CanTeleport(Matrix3D newTM, bool checkDynOnly);

		bool CanTeleport(Matrix3D newTM);

		bool CanTeleportAndStand(Matrix3D newTM, Matrix3D %out);

		bool FindTeleportLocation(Vector3 start, float radius, Vector3 %out);

		bool CanMoveTo(Matrix3D newTM);

		bool CinematicMoveTo(Matrix3D newTM);

		IPhysClass ^PeekCarrierObject();

		property IntPtr MoveablePhysClassPointer
		{
			IntPtr get();
		}

		property IMoveablePhysDefClass ^MoveablePhysDef
		{
			IMoveablePhysDefClass ^get();
		}

		property float Mass
		{
			float get();
		}

		property float MassInv
		{
			float get();
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

		property Matrix3 InertiaInv
		{
			Matrix3 get();
		}

		property IPhysControllerClass ^Controller
		{
			IPhysControllerClass ^get();
			void set(IPhysControllerClass ^value);
		}

		property Vector3 Velocity
		{
			Vector3 get();
			void set(Vector3 value);
		}
	};

	public ref class MoveablePhysClass : public DynamicPhysClass, public IMoveablePhysClass
	{
		public:
			MoveablePhysClass(IntPtr pointer);

			IMoveablePhysClass ^AsMoveablePhysClass() override;
			virtual void SetMass(float mass) sealed;
			virtual bool CanTeleport(Matrix3D newTM, bool checkDynOnly, IMultiListClass<IPhysClass ^> ^resultList) sealed;
			virtual bool CanTeleport(Matrix3D newTM, bool checkDynOnly) sealed;
			virtual bool CanTeleport(Matrix3D newTM) sealed;
			virtual bool CanTeleportAndStand(Matrix3D newTM, Matrix3D %out) sealed;
			virtual bool FindTeleportLocation(Vector3 start, float radius, Vector3 %out) sealed;
			virtual bool CanMoveTo(Matrix3D newTM) sealed;
			virtual bool CinematicMoveTo(Matrix3D newTM) sealed;
			virtual IPhysClass ^PeekCarrierObject() sealed;

			property IntPtr MoveablePhysClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IMoveablePhysDefClass ^MoveablePhysDef
			{
				virtual IMoveablePhysDefClass ^get() sealed;
			}

			property float Mass
			{
				virtual float get() sealed;

				protected:
					void set(float value);
			}

			property float MassInv
			{
				virtual float get() sealed;

				protected:
					void set(float value);
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

			property Matrix3 InertiaInv
			{
				virtual Matrix3 get() sealed;
			}

			property IPhysControllerClass ^Controller
			{
				virtual IPhysControllerClass ^get() sealed;
				virtual void set(IPhysControllerClass ^value) sealed;
			}

			property Vector3 Velocity
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

		protected:
			property ::DynamicPhysClass *InternalDynamicPhysClassPointer
			{
				::DynamicPhysClass *get() override;
			}

			property ::MoveablePhysClass *InternalMoveablePhysClassPointer
			{
				virtual ::MoveablePhysClass *get();
			}

			property IPhysClass ^Carrier
			{
				IPhysClass ^get();
				void set(IPhysClass ^value);
			}

			property IRenderObjClass ^CarrierSubObject
			{
				IRenderObjClass ^get();
				void set(IRenderObjClass ^value);
			}

			property IDynamicShadowManagerClass ^ShadowManager
			{
				IDynamicShadowManagerClass ^get();
			}
	};
}