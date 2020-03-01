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

#include "MDamageableGameObj.h"
#include "MPhysObserverClass.h"
#include "MStaticPhysClassRefMultiListClass.h"
#include "MBuildingAggregateClassRefMultiListClass.h"
#include "MLightPhysClassRefMultiListClass.h"

#pragma managed(push, off)

class BuildingGameObj;

#pragma managed(pop)

namespace RenSharp
{
	interface class IVehicleFactoryGameObj;
	interface class IBuildingGameObjDef;
	interface class IPowerPlantGameObj;
	interface class ISoldierFactoryGameObj;
	interface class IAirStripGameObj;
	interface class IWarFactoryGameObj;
	interface class IRefineryGameObj;
	interface class IComCenterGameObj;
	interface class IRepairBayGameObj;
	value class SphereClass;
	interface class IBaseControllerClass;
	interface class IBuildingAggregateClass;
	value class AABoxClass;
	interface class IConstructionYardGameObj;
	interface class IAirFactoryGameObj;
	interface class INavalFactoryGameObj;
	interface class ISuperweaponGameObj;
	interface class IAudibleSoundClass;

	public interface class IBuildingGameObj : public IDamageableGameObj, public ICombatPhysObserverClass
	{	
		void CnCInitialize(IBaseControllerClass ^base);

		void OnDestroyed();

		void OnDamaged();

		void OnRevived();

		IBuildingAggregateClass ^FindMCT();

		float FindClosestPoly(Vector3 pos);

		property IntPtr BuildingGameObjPointer
		{
			IntPtr get();
		}

		property IBuildingGameObjDef ^Definition
		{
			IBuildingGameObjDef ^get();
		}

		property Vector3 Position
		{
			Vector3 get();
			void set(Vector3 value);
		}

		property bool IsPowerOn
		{
			bool get();
		}

		property String ^NamePrefix
		{
			String ^get();
		}

		property SphereClass CollectionSphere
		{
			SphereClass get();
			void set(SphereClass value);
		}

		property bool IsDestroyed
		{
			bool get();
			void set(bool value);
		}

		property bool IsSpyDisabled
		{
			bool get();
			void set(bool value);
		}

		property bool IsGDI
		{
			bool get();
		}

		property bool IsNod
		{
			bool get();
		}

		property AABoxClass BoundingBox
		{
			AABoxClass get();
		}

		property int CurrentState
		{
			int get();
		}

		property IBaseControllerClass ^BaseController
		{
			IBaseControllerClass ^get();
		}
	};

	public ref class BuildingGameObj : public DamageableGameObj, public IBuildingGameObj
	{
		private:
			ICombatPhysObserverClass ^combatPhysObserverClass;

		public:
			BuildingGameObj(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual int CollisionOccurred(IntPtr event) sealed;
			virtual int ObjectExpired(IPhysClass ^observedObj) sealed;
			virtual void ObjectRemovedFromScene(IPhysClass ^observedObj) sealed;
			virtual void ObjectShatteredSomething(IPhysClass ^observedObj, IPhysClass ^shatteredObj, int surfaceType) sealed;
			virtual void CnCInitialize(IBaseControllerClass ^base) sealed;
			virtual void OnDestroyed() sealed;
			virtual void OnDamaged() sealed;
			virtual void OnRevived() sealed;
			virtual IBuildingAggregateClass ^FindMCT() sealed;
			virtual float FindClosestPoly(Vector3 pos) sealed;

			property IntPtr Pointer
			{
				IntPtr get() override;

				protected:
					void set(IntPtr value) override;
			}

			property IntPtr CombatPhysObserverClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr PhysObserverClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr BuildingGameObjPointer
			{
				virtual IntPtr get() sealed;
			}

			property IBuildingGameObjDef ^Definition
			{
#pragma push_macro("new")
#undef new

				virtual IBuildingGameObjDef ^get() new sealed;

#pragma pop_macro("new")

			}

			property Vector3 Position
			{
				Vector3 get() override;
				virtual void set(Vector3 value) sealed;
			}

			property bool IsPowerOn
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

			property String ^NamePrefix
			{
				virtual String ^get() sealed;
			}

			property SphereClass CollectionSphere
			{
				virtual SphereClass get() sealed;
				virtual void set(SphereClass value) sealed;
			}

			property bool IsDestroyed
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsSpyDisabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsGDI
			{
				virtual bool get() sealed;
			}

			property bool IsNod
			{
				virtual bool get() sealed;
			}

			property AABoxClass BoundingBox
			{
				virtual AABoxClass get() sealed;

				protected:
					void set(AABoxClass value);
			}

			property int CurrentState
			{
				virtual int get() sealed;

				protected:
					void set(int value);
			}

			property IBaseControllerClass ^BaseController
			{
				virtual IBaseControllerClass ^get() sealed;

				protected:
					void set(IBaseControllerClass ^value);
			}

		protected:
			property ::PhysObserverClass *InternalPhysObserverClassPointer
			{
				virtual ::PhysObserverClass *get();
			}

			property ::CombatPhysObserverClass *InternalCombatPhysObserverClassPointer
			{
				virtual ::CombatPhysObserverClass *get();
			}

			property ::DamageableGameObj *InternalDamageableGameObjPointer
			{
				::DamageableGameObj *get() override;
			}

			property ::BuildingGameObj *InternalBuildingGameObjPointer
			{
				virtual ::BuildingGameObj *get();
			}

			property IntPtr BuildingMonitor
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property IAudibleSoundClass ^CurrentAnnouncement
			{
				IAudibleSoundClass ^get();
				void set(IAudibleSoundClass ^value);
			}

			property SphereClass AnnouncementSphere
			{
				SphereClass get();
				void set(SphereClass value);
			}

			property IRefMultiListClass<IStaticPhysClass ^> ^InteriorMeshes
			{
				IRefMultiListClass<IStaticPhysClass ^> ^get();
			}

			property IRefMultiListClass<IStaticPhysClass ^> ^ExteriorMeshes
			{
				IRefMultiListClass<IStaticPhysClass ^> ^get();
			}

			property IRefMultiListClass<IBuildingAggregateClass ^> ^Aggregates
			{
				IRefMultiListClass<IBuildingAggregateClass ^> ^get();
			}

			property IRefMultiListClass<ILightPhysClass ^> ^PowerOnLights
			{
				IRefMultiListClass<ILightPhysClass ^> ^get();
			}

			property IRefMultiListClass<ILightPhysClass ^> ^PowerOffLights
			{
				IRefMultiListClass<ILightPhysClass ^> ^get();
			}
	};
}