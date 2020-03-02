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

#include "MCullableClass.h"
#include "MPersist.h"
#include "Mmultilist.h"
#include "MPhysDefClass.h"
#include "Mmultilist.h"
#include "MMaterialEffectClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <PhysClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	value class Matrix3D;
	interface class IPhysRayCollisionTestClass;
	ref class PhysRayCollisionTestClass;
	interface class IPhysAABoxCollisionTestClass;
	ref class PhysAABoxCollisionTestClass;
	interface class IPhysOBBoxCollisionTestClass;
	ref class PhysOBBoxCollisionTestClass;
	interface class IPhysAABoxIntersectionTestClass;
	ref class PhysAABoxIntersectionTestClass;
	interface class IPhysOBBoxIntersectionTestClass;
	ref class PhysOBBoxIntersectionTestClass;
	interface class IPhysMeshIntersectionTestClass;
	ref class PhysMeshIntersectionTestClass;
	interface class IRenderObjClass;
	interface class IPhysObserverClass;
	interface class IDynamicPhysClass;
	interface class IMoveablePhysClass;
	interface class IStaticPhysClass;
	interface class IStaticAnimPhysClass;
	interface class IDecorationPhysClass;
	interface class ILightPhysClass;
	value class Vector3;

#pragma managed(push, off)

	class PhysClassHelper : public ::PhysClass
	{
		public:
			static constexpr int CollisionMask = ::PhysClass::COLLISION_MASK;
			static constexpr int Immovable = ::PhysClass::IMMOVABLE;
			static constexpr int Disabled = ::PhysClass::DISABLED;
			static constexpr int DebugDisplay = ::PhysClass::DEBUGDISPLAY;
			static constexpr int UserControl = ::PhysClass::USERCONTROL;
			static constexpr int CastShadow = ::PhysClass::CASTSHADOW;
			static constexpr int ForceProjectionShadow = ::PhysClass::FORCE_PROJECTION_SHADOW;
			static constexpr int DontSave = ::PhysClass::DONT_SAVE;
			static constexpr int Asleep = ::PhysClass::ASLEEP;
			static constexpr int IsWSMesh = ::PhysClass::IS_WS_MESH;
			static constexpr int IsPreLit = ::PhysClass::IS_PRE_LIT;
			static constexpr int IsInTheSun = ::PhysClass::IS_IN_THE_SUN;
			static constexpr int IsStateDirty = ::PhysClass::IS_STATE_DIRTY;
			static constexpr int StaticLightingDirty = ::PhysClass::STATIC_LIGHTING_DIRTY;
			static constexpr int FrictionDisabled = ::PhysClass::FRICTION_DISABLED;
			static constexpr int SimulationDisabled = ::PhysClass::SIMULATION_DISABLED;
			static constexpr int Hidden = ::PhysClass::HIDDEN;
			static constexpr int VisibilityModeShift = ::PhysClass::VISIBILITY_MODE_SHIFT;
			static constexpr int VisibilityModeMask = ::PhysClass::VISIBILITY_MODE_MASK;
			static constexpr int IgnoreShift = ::PhysClass::IGNORE_SHIFT;
			static constexpr int IgnoreMask = ::PhysClass::IGNORE_MASK;
			static constexpr int DefaultFlags = ::PhysClass::DEFAULT_FLAGS;

		private:
			PhysClassHelper() = default;

		public:
			bool GetFlag(unsigned int flag)
			{
				return Get_Flag(flag);
			}

			void SetFlag(unsigned int flag, bool onoff)
			{
				Set_Flag(flag, onoff);
			}

			unsigned int &GetFlags()
			{
				return Flags;
			}

			::RenderObjClass *&GetModel()
			{
				return Model;
			}

			::StringClass &GetName()
			{
				return Name;
			}

			::RefMultiListClass<::MaterialEffectClass> &GetMaterialEffectsOnMe()
			{
				return MaterialEffectsOnMe;
			}

			::LightEnvironmentClass *&GetStaticLightingCache()
			{
				return StaticLightingCache;
			}

			unsigned int &GetSunStatusLastUpdated()
			{
				return SunStatusLastUpdated;
			}
	};

#pragma managed(pop)

	public interface class IPhysClass : public ICullableClass, public IPersistClass, public IMultiListObjectClass
	{
		void DefinitionChanged();

		bool NeedsTimestep();

		void Timestep(float dt);

		void PostTimestepProcess();

		bool CastRay(IPhysRayCollisionTestClass ^rayTest);

		bool CastRay(PhysRayCollisionTestClass ^rayTest);

		bool CastAABox(IPhysAABoxCollisionTestClass ^boxTest);

		bool CastAABox(PhysAABoxCollisionTestClass ^boxTest);

		bool CastOBBox(IPhysOBBoxCollisionTestClass ^boxTest);

		bool CastOBBox(PhysOBBoxCollisionTestClass ^boxTest);

		bool IntersectionTest(IPhysAABoxIntersectionTestClass ^test);

		bool IntersectionTest(PhysAABoxIntersectionTestClass ^test);

		bool IntersectionTest(IPhysOBBoxIntersectionTestClass ^test);

		bool IntersectionTest(PhysOBBoxIntersectionTestClass ^test);

		bool IntersectionTest(IPhysMeshIntersectionTestClass ^test);

		bool IntersectionTest(PhysMeshIntersectionTestClass ^test);

		void LinkToCarrier(IPhysClass ^carrier, IRenderObjClass ^carrierSubObj);

		void LinkToCarrier(IPhysClass ^carrier);

		IRenderObjClass ^PeekCarrierSubObject();

		bool Push(Vector3 move);

		bool InternalLinkRider(IPhysClass ^rider);

		bool InternalUnlinkRider(IPhysClass ^rider);

		void SetModel(IRenderObjClass ^model);

		IRenderObjClass ^PeekModel();

		void Render(IntPtr rInfo);

		void VisRender(IntPtr rInfo);

		void RenderVisMeshes(IntPtr rInfo);

		void AddEffectToMe(IMaterialEffectClass ^effect);

		void RemoveEffectFromMe(IMaterialEffectClass ^effect);

		void IncIgnoreCounter();

		void DecIgnoreCounter();

		void EnableDebugDisplay(bool onoff);

		void ForceAwake();

		IntPtr AsPhys3Class();

		IntPtr AsHumanPhysClass();

		IntPtr AsRigidBodyClass();

		IntPtr AsVehiclePhysClass();

		IntPtr AsMotorVehicleClass();

		IntPtr AsWheeledVehicleClass();

		IntPtr AsMotorcycleClass();

		IntPtr AsTrackedVehicleClass();

		IntPtr AsVTOLVehicleClass();

		IntPtr AsElevatorPhysClass();

		IntPtr AsDamageableStaticPhysClass();

		IntPtr AsDoorPhysClass();

		IntPtr AsTimedDecorationPhysClass();

		IntPtr AsDynamicAnimPhysClass();

		IntPtr AsRenderObjPhysClass();

		IntPtr AsProjectileClass();

		IntPtr AsAccessiblePhysClass();

		property IntPtr PhysClassPointer
		{
			IntPtr get();
		}

		property Matrix3D Transform
		{
			Matrix3D get();
			void set(Matrix3D value);
		}

		property Vector3 Position
		{
			Vector3 get();
			void set(Vector3 value);
		}

		property float Facing
		{
			float get();
		}

		property uint32 InstanceID
		{
			uint32 get();
			void set(uint32 value);
		}

		property int VisObjectID
		{
			int get();
			void set(int value);
		}

		property AABoxClass ShadowBlobBox
		{
			AABoxClass get();
		}

		property bool IsCastingShadow
		{
			bool get();
		}

		property VisibilityModeType VisibilityMode
		{
			VisibilityModeType get();
			void set(VisibilityModeType value);
		}

		property CollisionGroupType CollisionGroup
		{
			CollisionGroupType get();
			void set(CollisionGroupType value);
		}

		property bool IsIgnoreMe
		{
			bool get();
		}

		property bool IsImmovable
		{
			bool get();
			void set(bool value);
		}

		property bool IsDisabled
		{
			bool get();
			void set(bool value);
		}

		property bool IsUserControlEnabled
		{
			bool get();
			void set(bool value);
		}

		property bool IsShadowGenerationEnabled
		{
			bool get();
			void set(bool value);
		}

		property bool IsForceProjectionShadowEnabled
		{
			bool get();
			void set(bool value);
		}

		property bool IsDontSaveEnabled
		{
			bool get();
			void set(bool value);
		}

		property bool IsAsleep
		{
			bool get();
		}

		property bool IsWorldSpaceMesh
		{
			bool get();
			void set(bool value);
		}

		property bool IsPreLit
		{
			bool get();
			void set(bool value);
		}

		property bool IsInTheSun
		{
			bool get();
			void set(bool value);
		}

		property bool IsStateDirty
		{
			bool get();
			void set(bool value);
		}

		property bool IsHidden
		{
			bool get();
			void set(bool value);
		}

		property bool IsObjectsSimulationEnabled
		{
			bool get();
			void set(bool value);
		}

		property IPhysObserverClass ^Observer
		{
			IPhysObserverClass ^get();
			void set(IPhysObserverClass ^value);
		}

		property IPhysDefClass ^Definition
		{
			IPhysDefClass ^get();
		}

		property bool IsSimulationDisabled
		{
			bool get();
		}

		property unsigned int LastVisibleFrame
		{
			unsigned int get();
			void set(unsigned int value);
		}
	};

	public ref class PhysClass : public CullableClass, public IPhysClass
	{
		protected:
			enum class PhysClassFlags : int
			{
				CollisionMask = PhysClassHelper::CollisionMask,
				Immovable = PhysClassHelper::Immovable,
				Disabled = PhysClassHelper::Disabled,
				DebugDisplay = PhysClassHelper::DebugDisplay,
				UserControl = PhysClassHelper::UserControl,
				CastShadow = PhysClassHelper::CastShadow,
				ForceProjectionShadow = PhysClassHelper::ForceProjectionShadow,
				DontSave = PhysClassHelper::DontSave,
				Asleep = PhysClassHelper::Asleep,
				IsWSMesh = PhysClassHelper::IsWSMesh,
				IsPreLit = PhysClassHelper::IsPreLit,
				IsInTheSun = PhysClassHelper::IsInTheSun,
				IsStateDirty = PhysClassHelper::IsStateDirty,
				StaticLightingDirty = PhysClassHelper::StaticLightingDirty,
				FrictionDisabled = PhysClassHelper::FrictionDisabled,
				SimulationDisabled = PhysClassHelper::SimulationDisabled,
				Hidden = PhysClassHelper::Hidden,
				VisibilityModeShift = PhysClassHelper::VisibilityModeShift,
				VisibilityModeMask = PhysClassHelper::VisibilityModeMask,
				IgnoreShift = PhysClassHelper::IgnoreShift,
				IgnoreMask = PhysClassHelper::IgnoreMask,
				DefaultFlags = PhysClassHelper::DefaultFlags
			};

		private:
			IPersistClass ^persistClass;
			IMultiListObjectClass ^multiListObjectClass;

		public:
			PhysClass(IntPtr pointer);

			static IPhysClass^ CreatePhysClassWrapper(IntPtr physClassPtr);

			bool Equals(Object ^other) override;

			virtual void OnPostLoad() sealed;
			virtual bool Save(IChunkSaveClass ^csave) sealed;
			virtual bool Load(IChunkLoadClass ^cload) sealed;
			virtual void DefinitionChanged() sealed;
			virtual bool NeedsTimestep() sealed;
			virtual void Timestep(float dt) sealed;
			virtual void PostTimestepProcess() sealed;
			virtual bool CastRay(IPhysRayCollisionTestClass ^rayTest) sealed;
			virtual bool CastRay(PhysRayCollisionTestClass ^rayTest) sealed;
			virtual bool CastAABox(IPhysAABoxCollisionTestClass ^boxTest) sealed;
			virtual bool CastAABox(PhysAABoxCollisionTestClass ^boxTest) sealed;
			virtual bool CastOBBox(IPhysOBBoxCollisionTestClass ^boxTest) sealed;
			virtual bool CastOBBox(PhysOBBoxCollisionTestClass ^boxTest) sealed;
			virtual bool IntersectionTest(IPhysAABoxIntersectionTestClass ^test) sealed;
			virtual bool IntersectionTest(PhysAABoxIntersectionTestClass ^test) sealed;
			virtual bool IntersectionTest(IPhysOBBoxIntersectionTestClass ^test) sealed;
			virtual bool IntersectionTest(PhysOBBoxIntersectionTestClass ^test) sealed;
			virtual bool IntersectionTest(IPhysMeshIntersectionTestClass ^test) sealed;
			virtual bool IntersectionTest(PhysMeshIntersectionTestClass ^test) sealed;
			virtual void LinkToCarrier(IPhysClass ^carrier, IRenderObjClass ^carrierSubObj) sealed;
			virtual void LinkToCarrier(IPhysClass ^carrier) sealed;
			virtual IRenderObjClass ^PeekCarrierSubObject() sealed;
			virtual bool Push(Vector3 move) sealed;
			virtual bool InternalLinkRider(IPhysClass ^rider) sealed;
			virtual bool InternalUnlinkRider(IPhysClass ^rider) sealed;
			virtual void SetModel(IRenderObjClass ^model) sealed;
			virtual IRenderObjClass ^PeekModel() sealed;
			virtual void Render(IntPtr rInfo) sealed;
			virtual void VisRender(IntPtr rInfo) sealed;
			virtual void RenderVisMeshes(IntPtr rInfo) sealed;
			virtual void AddEffectToMe(IMaterialEffectClass ^effect) sealed;
			virtual void RemoveEffectFromMe(IMaterialEffectClass ^effect) sealed;
			virtual void IncIgnoreCounter() sealed;
			virtual void DecIgnoreCounter() sealed;
			virtual void EnableDebugDisplay(bool onoff) sealed;
			virtual void ForceAwake() sealed;
			virtual IntPtr AsPhys3Class();
			virtual IntPtr AsHumanPhysClass();
			virtual IntPtr AsRigidBodyClass();
			virtual IntPtr AsVehiclePhysClass();
			virtual IntPtr AsMotorVehicleClass();
			virtual IntPtr AsWheeledVehicleClass();
			virtual IntPtr AsMotorcycleClass();
			virtual IntPtr AsTrackedVehicleClass();
			virtual IntPtr AsVTOLVehicleClass();
			virtual IntPtr AsElevatorPhysClass();
			virtual IntPtr AsDamageableStaticPhysClass();
			virtual IntPtr AsDoorPhysClass();
			virtual IntPtr AsTimedDecorationPhysClass();
			virtual IntPtr AsDynamicAnimPhysClass();
			virtual IntPtr AsRenderObjPhysClass();
			virtual IntPtr AsProjectileClass();
			virtual IntPtr AsAccessiblePhysClass();

			property IntPtr Pointer
			{
				IntPtr get() override;

				protected:
					void set(IntPtr value) override;
			}

			property IntPtr PostLoadableClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr PersistClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr MultiListObjectClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr PhysClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool IsPostLoadRegistered
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property IPersistFactoryClass ^Factory
			{
				virtual IPersistFactoryClass ^get() sealed;
			}

			property IMultiListNodeClass ^ListNode
			{
				virtual IMultiListNodeClass ^get() sealed;
				virtual void set(IMultiListNodeClass ^value) sealed;
			}

			property Matrix3D Transform
			{
				virtual Matrix3D get() sealed;
				virtual void set(Matrix3D value) sealed;
			}

			property Vector3 Position
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

			property float Facing
			{
				virtual float get() sealed;
			}

			property uint32 InstanceID
			{
				virtual uint32 get() sealed;
				virtual void set(uint32 value) sealed;
			}

			property int VisObjectID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property AABoxClass ShadowBlobBox
			{
				virtual AABoxClass get() sealed;
			}

			property bool IsCastingShadow
			{
				virtual bool get() sealed;
			}

			property VisibilityModeType VisibilityMode
			{
				virtual VisibilityModeType get() sealed;
				virtual void set(VisibilityModeType value) sealed;
			}

			property CollisionGroupType CollisionGroup
			{
				virtual CollisionGroupType get() sealed;
				virtual void set(CollisionGroupType value) sealed;
			}

			property bool IsIgnoreMe
			{
				virtual bool get() sealed;
			}

			property bool IsImmovable
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsDisabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsUserControlEnabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsShadowGenerationEnabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsForceProjectionShadowEnabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsDontSaveEnabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsAsleep
			{
				virtual bool get() sealed;
			}

			property bool IsWorldSpaceMesh
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsPreLit
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsInTheSun
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsStateDirty
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsHidden
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsObjectsSimulationEnabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property IPhysObserverClass ^Observer
			{
				virtual IPhysObserverClass ^get() sealed;
				virtual void set(IPhysObserverClass ^value) sealed;
			}

			property IPhysDefClass ^Definition
			{
				virtual IPhysDefClass ^get() sealed;
			}

			property bool IsSimulationDisabled
			{
				virtual bool get() sealed;
			}

			property unsigned int LastVisibleFrame
			{
				virtual unsigned int get() sealed;
				virtual void set(unsigned int value) sealed;
			}

		internal:
			static IPhysClass^ CreatePhysClassWrapper(::PhysClass* physClassPtr);

		protected:
			bool GetFlag(unsigned int flag);
			void SetFlag(unsigned int flag, bool onoff);

			property ::CullableClass *InternalCullableClassPointer
			{
				::CullableClass *get() override;
			}

			property ::PostLoadableClass *InternalPostLoadableClassPointer
			{
				virtual ::PostLoadableClass *get();
			}

			property ::PersistClass *InternalPersistClassPointer
			{
				virtual ::PersistClass *get();
			}

			property ::MultiListObjectClass *InternalMultiListObjectClassPointer
			{
				virtual ::MultiListObjectClass *get();
			}

			property ::PhysClass *InternalPhysClassPointer
			{
				virtual ::PhysClass *get();
			}

			property unsigned int Flags
			{
				unsigned int get();
				void set(unsigned int value);
			}

			property IRenderObjClass ^Model
			{
				IRenderObjClass ^get();
				void set(IRenderObjClass ^value);
			}

			property String ^Name
			{
				String ^get();
				void set(String ^value);
			}

			property IRefMultiListClass<IMaterialEffectClass ^> ^MaterialEffectsOnMe
			{
				IRefMultiListClass<IMaterialEffectClass ^> ^get();
			}

			property IntPtr StaticLightingCache
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property unsigned int SunStatusLastUpdated
			{
				unsigned int get();
				void set(unsigned int value);
			}
	};
}