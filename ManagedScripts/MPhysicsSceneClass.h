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

#include "MSceneClass.h"
#include "MWidgetUserClass.h"
#include "Mmultilist.h"
#include "MAABTreeCull.h"
#include "MGridCull.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <PhysicsSceneClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{

#pragma managed(push, off)

	class PhysicsSceneClassHelper : public ::PhysicsSceneClass 
	{
		public:
			static constexpr int VisRenderWidth = ::PhysicsSceneClass::VIS_RENDER_WIDTH;
			static constexpr int VisRenderHeight = ::PhysicsSceneClass::VIS_RENDER_HEIGHT;

		private:
			PhysicsSceneClassHelper() = default;

		public:
			void InternalVisReset()
			{
				Internal_Vis_Reset();
			}

			::RefMultiListClass<::PhysClass>& GetVisibleStaticObjectList()
			{
				return VisibleStaticObjectList;
			}

			::RefMultiListClass<::PhysClass>& GetVisibleWSMeshList()
			{
				return VisibleWSMeshList;
			}

			::RefMultiListClass<::PhysClass>& GetVisibleDynamicObjectList()
			{
				return VisibleDynamicObjectList;
			}

			::MultiListClass<::TexProjectClass>& GetActiveTextureProjectors()
			{
				return ActiveTextureProjectors;
			}

			int& GetFrameNum()
			{
				return FrameNum;
			}

			::Vector3& GetLastCameraPosition()
			{
				return LastCameraPosition;
			}

			int& GetLastValidVisId()
			{
				return LastValidVisId;
			}

			::PhysicsSceneClass::StatsStruct& GetLastValidStats()
			{
				return LastValidStats;
			}

			::PhysicsSceneClass::StatsStruct& GetCurrentStats()
			{
				return CurrentStats;
			}

			bool& GetStaticProjectorsDirty()
			{
				return StaticProjectorsDirty;
			}

			bool& GetVisEnabled()
			{
				return VisEnabled;
			}

			bool& GetVisInverted()
			{
				return VisInverted;
			}

			bool& GetVisQuickAndDirty()
			{
				return VisQuickAndDirty;
			}

			bool& GetVisResetNeeded()
			{
				return VisResetNeeded;
			}

			bool& GetVisSectorDisplayEnabled()
			{
				return VisSectorDisplayEnabled;
			}

			bool& GetVisSectorHistoryEnabled()
			{
				return VisSectorHistoryEnabled;
			}

			int& GetVisGridDisplayMode()
			{
				return VisGridDisplayMode;
			}

			bool& GetVisSectorMissing()
			{
				return VisSectorMissing;
			}

			bool& GetVisSectorFallbackEnabled()
			{
				return VisSectorFallbackEnabled;
			}

			bool& GetBackfaceDebugEnabled()
			{
				return BackfaceDebugEnabled;
			}

			bool& GetVisSamplePointLocked()
			{
				return VisSamplePointLocked;
			}

			::Vector3& GetLockedVisSamplePoint()
			{
				return LockedVisSamplePoint;
			}

			::CameraClass*& GetVisCamera()
			{
				return VisCamera;
			}

			::VisTableClass*& GetCurrentVisTable()
			{
				return CurrentVisTable;
			}

			bool& GetStaticProjectorsEnabled()
			{
				return StaticProjectorsEnabled;
			}

			bool& GetDynamicProjectorsEnabled()
			{
				return DynamicProjectorsEnabled;
			}

			::PhysicsSceneClass::ShadowEnum& GetShadowMode()
			{
				return ShadowMode;
			}

			float& GetShadowAttenStart()
			{
				return ShadowAttenStart;
			}

			float& GetShadowAttenEnd()
			{
				return ShadowAttenEnd;
			}

			float& GetShadowNormalIntensity()
			{
				return ShadowNormalIntensity;
			}

			::TextureClass*& GetShadowBlobTexture()
			{
				return ShadowBlobTexture;
			}

			::SpecialRenderInfoClass*& GetShadowRenderContext()
			{
				return ShadowRenderContext;
			}

			::CameraClass*& GetShadowCamera()
			{
				return ShadowCamera;
			}

			::MaterialPassClass*& GetShadowMaterialPass()
			{
				return ShadowMaterialPass;
			}

			int& GetShadowResWidth()
			{
				return ShadowResWidth;
			}

			int& GetShadowResHeight()
			{
				return ShadowResHeight;
			}

			::PhysDecalSysClass*& GetDecalSystem()
			{
				return DecalSystem;
			}

			::PathfindClass*& GetPathfinder()
			{
				return Pathfinder;
			}

			::CameraShakeSystemClass*& GetCameraShakeSystem()
			{
				return CameraShakeSystem;
			}

			::RefMultiListClass<::RenderObjClass>& GetUpdateList()
			{
				return UpdateList;
			}

			::RefMultiListClass<::RenderObjClass>& GetVertexProcList()
			{
				return VertexProcList;
			}

			::RefMultiListClass<::PhysClass>& GetReleaseList()
			{
				return ReleaseList;
			}

			::MaterialPassClass*& GetHighlightMaterialPass()
			{
				return HighlightMaterialPass;
			}

			::StaticAABTreeCullClass*& GetStaticCullingSystem()
			{
				return StaticCullingSystem;
			}

			::StaticLightCullClass*& GetStaticLightingSystem()
			{
				return StaticLightingSystem;
			}

			::PhysGridCullClass*& GetDynamicCullingSystem()
			{
				return DynamicCullingSystem;
			}

			::DynamicAABTreeCullClass*& GetDynamicObjVisSystem()
			{
				return DynamicObjVisSystem;
			}

			::TypedAABTreeCullSystemClass<::TexProjectClass>*& GetStaticProjectorCullingSystem()
			{
				return StaticProjectorCullingSystem;
			}

			::TypedGridCullSystemClass<::TexProjectClass>*& GetDynamicProjectorCullingSystem()
			{
				return DynamicProjectorCullingSystem;
			}

			::VisTableMgrClass& GetVisTableManager()
			{
				return VisTableManager;
			}

			int& GetLightingMode()
			{
				return LightingMode;
			}

			::Vector3& GetSceneAmbientLight()
			{
				return SceneAmbientLight;
			}

			bool& GetUseSun()
			{
				return UseSun;
			}

			float& GetSunPitch()
			{
				return SunPitch;
			}

			float& GetSunYaw()
			{
				return SunYaw;
			}

			::LightClass*& GetSunLight()
			{
				return SunLight;
			}

			int& GetDynamicPolyBudget()
			{
				return DynamicPolyBudget;
			}

			int& GetStaticPolyBudget()
			{
				return StaticPolyBudget;
			}

			float& GetmapStaticPolyBudget()
			{
				return mapStaticPolyBudget;
			}

			float& GetmapDynamicPolyBudget()
			{
				return mapDynamicPolyBudget;
			}

			::RefMultiListClass<::PhysClass>& GetObjList()
			{
				return ObjList;
			}

			::RefMultiListClass<::PhysClass>& GetStaticObjList()
			{
				return StaticObjList;
			}

			::RefMultiListClass<::PhysClass>& GetStaticLightList()
			{
				return StaticLightList;
			}

			::MultiListClass<::TexProjectClass>& GetStaticProjectorList()
			{
				return StaticProjectorList;
			}

			::MultiListClass<::TexProjectClass>& GetDynamicProjectorList()
			{
				return DynamicProjectorList;
			}

			::RefMultiListClass<::PhysClass>& GetDirtyCullList()
			{
				return DirtyCullList;
			}

			::RefMultiListClass<::PhysClass>& GetTimestepList()
			{
				return TimestepList;
			}

			::RefMultiListClass<::PhysClass>& GetStaticAnimList()
			{
				return StaticAnimList;
			}

			::MultiListClass<::PhysClass>& GetCollisionRegionList()
			{
				return CollisionRegionList;
			}

			bool& GetUpdateOnlyVisibleObjects()
			{
				return UpdateOnlyVisibleObjects;
			}
	};

#pragma managed(pop)

	interface class IPhysRayCollisionTestClass;
	ref class PhysRayCollisionTestClass;
	interface class IPhysAABoxCollisionTestClass;
	ref class PhysAABoxCollisionTestClass;
	interface class IPhysOBBoxCollisionTestClass;
	ref class PhysOBBoxCollisionTestClass;
	interface class IPhysClass;
	value class OBBoxClass;
	interface class IVisTableClass;
	interface class IVisTableMgrClass;

	public interface class IPhysicsSceneClass : public ISceneClass, public IWidgetUserClass
	{
		enum class LightingModeEnum : int
		{
			LightingModeNone = ::PhysicsSceneClass::LIGHTING_MODE_NONE,
			LightingModeSurrender = ::PhysicsSceneClass::LIGHTING_MODE_SURRENDER,
			LightingModeCheap = ::PhysicsSceneClass::LIGHTING_MODE_CHEAP
		};

		enum class VisGridDisplayEnum : int
		{
			VISGridDisplayNone = ::PhysicsSceneClass::VIS_GRID_DISPLAY_NONE,
			VISGridDisplayActualBoxes = ::PhysicsSceneClass::VIS_GRID_DISPLAY_ACTUAL_BOXES,
			VISGridDisplayCenters = ::PhysicsSceneClass::VIS_GRID_DISPLAY_CENTERS,
			VISGridDisplayOccupied = ::PhysicsSceneClass::VIS_GRID_DISPLAY_OCCUPIED
		};

		enum class ShadowEnum : int
		{
			ShadowModeNone = ::PhysicsSceneClass::SHADOW_MODE_NONE,
			ShadowModeBlobs = ::PhysicsSceneClass::SHADOW_MODE_BLOBS,
			ShadowModeBlobsPlus = ::PhysicsSceneClass::SHADOW_MODE_BLOBS_PLUS,
			ShadowModeHardware = ::PhysicsSceneClass::SHADOW_MODE_HARDWARE
		};

		literal int CollisionGroupWorld = ::PhysicsSceneClass::COLLISION_GROUP_WORLD;
		literal int MaxCollisionGroup = ::PhysicsSceneClass::MAX_COLLISION_GROUP;
		literal int NumCollisionFlags = ::PhysicsSceneClass::NUM_COLLISION_FLAGS;
		literal int CollisionFlagShift = ::PhysicsSceneClass::COLLISION_FLAG_SHIFT;

		bool CastRay(IPhysRayCollisionTestClass^ raytest, bool useCollisionRegion);

		bool CastRay(IPhysRayCollisionTestClass^ raytest);

		bool CastRay(PhysRayCollisionTestClass^ raytest, bool useCollisionRegion);

		bool CastRay(PhysRayCollisionTestClass^ raytest);

		bool CastAABox(IPhysAABoxCollisionTestClass^ boxtest, bool useCollisionRegion);

		bool CastAABox(IPhysAABoxCollisionTestClass^ boxtest);

		bool CastAABox(PhysAABoxCollisionTestClass^ boxtest, bool useCollisionRegion);

		bool CastAABox(PhysAABoxCollisionTestClass^ boxtest);

		bool CastOBBox(IPhysOBBoxCollisionTestClass^ boxtest, bool useCollisionRegion);

		bool CastOBBox(IPhysOBBoxCollisionTestClass^ boxtest);

		bool CastOBBox(PhysOBBoxCollisionTestClass^ boxtest, bool useCollisionRegion);

		bool CastOBBox(PhysOBBoxCollisionTestClass^ boxtest);

		IUnmanagedContainer<IMultiListClass<IPhysClass^>^>^ CollectObjects(OBBoxClass box, bool staticObjs, bool dynamicObjs);

		void OnVisOccludersRendered(IntPtr context, IntPtr sample);

		void ResetVis(bool doItNow);

		void ResetVis();

		void GetLevelExtents([Out] Vector3% min, [Out] Vector3% max);

		property IntPtr PhysicsSceneClassPointer
		{
			IntPtr get();
		}

		property int LightingMode
		{
			int get();
			void set(int value);
		}

		property bool VisResetNeeded
		{
			bool get();
			void set(bool value);
		}

		property bool UpdateOnlyVisibleObjects
		{
			bool get();
			void set(bool value);
		}

		property bool DebugDisplayEnabled
		{
			bool get();
			void set(bool value);
		}

		property bool ProjectorDebugDisplayEnabled
		{
			bool get();
			void set(bool value);
		}

		property bool DirtyCullDebugDisplayEnabled
		{
			bool get();
			void set(bool value);
		}

		property bool LightingDebugDisplayEnabled
		{
			bool get();
			void set(bool value);
		}

		property Vector3 LastCameraPosition
		{
			Vector3 get();
		}

		property unsigned int CurrentFrameNumber
		{
			unsigned int get();
			void set(unsigned int value);
		}
	};

	public ref class PhysicsSceneClass : public SceneClass, public IPhysicsSceneClass
	{
		public:
			interface class IStatsStruct : public IUnmanagedObject
			{
				property IntPtr StatsStructPointer
				{
					IntPtr get();
				}

				property int FrameCount
				{
					int get();
					void set(int value);
				}

				property int CullNodeCount
				{
					int get();
					void set(int value);
				}

				property int CullNodesAccepted
				{
					int get();
					void set(int value);
				}

				property int CullNodesTriviallyAccepted
				{
					int get();
					void set(int value);
				}

				property int CullNodesRejected
				{
					int get();
					void set(int value);
				}
			};

			ref class StatsStruct : public AbstractUnmanagedObject, public IStatsStruct
			{
				public:
					StatsStruct(IntPtr pointer);

					bool Equals(Object^ other) override;

					property IntPtr StatsStructPointer
					{
						virtual IntPtr get() sealed;
					}

					property int FrameCount
					{
						virtual int get() sealed;
						virtual void set(int value) sealed;
					}

					property int CullNodeCount
					{
						virtual int get() sealed;
						virtual void set(int value) sealed;
					}

					property int CullNodesAccepted
					{
						virtual int get() sealed;
						virtual void set(int value) sealed;
					}

					property int CullNodesTriviallyAccepted
					{
						virtual int get() sealed;
						virtual void set(int value) sealed;
					}

					property int CullNodesRejected
					{
						virtual int get() sealed;
						virtual void set(int value) sealed;
					}

				protected:
					bool InternalDestroyPointer() override;

					property ::PhysicsSceneClass::StatsStruct* InternalStatsStructPointer
					{
						virtual ::PhysicsSceneClass::StatsStruct* get();
					}
			};

			PhysicsSceneClass(IntPtr pointer);

			virtual bool CastRay(IPhysRayCollisionTestClass^ raytest, bool useCollisionRegion) sealed;
			virtual bool CastRay(IPhysRayCollisionTestClass^ raytest) sealed;
			virtual bool CastRay(PhysRayCollisionTestClass^ raytest, bool useCollisionRegion) sealed;
			virtual bool CastRay(PhysRayCollisionTestClass^ raytest) sealed;
			virtual bool CastAABox(IPhysAABoxCollisionTestClass^ boxtest, bool useCollisionRegion) sealed;
			virtual bool CastAABox(IPhysAABoxCollisionTestClass^ boxtest) sealed;
			virtual bool CastAABox(PhysAABoxCollisionTestClass^ boxtest, bool useCollisionRegion) sealed;
			virtual bool CastAABox(PhysAABoxCollisionTestClass^ boxtest) sealed;
			virtual bool CastOBBox(IPhysOBBoxCollisionTestClass^ boxtest, bool useCollisionRegion) sealed;
			virtual bool CastOBBox(IPhysOBBoxCollisionTestClass^ boxtest) sealed;
			virtual bool CastOBBox(PhysOBBoxCollisionTestClass^ boxtest, bool useCollisionRegion) sealed;
			virtual bool CastOBBox(PhysOBBoxCollisionTestClass^ boxtest) sealed;
			virtual IUnmanagedContainer<IMultiListClass<IPhysClass^>^>^ CollectObjects(OBBoxClass box, bool staticObjs, bool dynamicObjs) sealed;
			virtual void OnVisOccludersRendered(IntPtr context, IntPtr sample) sealed;
			virtual void ResetVis(bool doItNow) sealed;
			virtual void ResetVis() sealed;
			virtual void GetLevelExtents([Out] Vector3% min, [Out] Vector3% max) sealed;

			static property IPhysicsSceneClass^ Instance
			{
				IPhysicsSceneClass ^get();
			}

			property IntPtr PhysicsSceneClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr WidgetUserClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property int LightingMode
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property bool VisResetNeeded
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool UpdateOnlyVisibleObjects
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool DebugDisplayEnabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool ProjectorDebugDisplayEnabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool DirtyCullDebugDisplayEnabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool LightingDebugDisplayEnabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property Vector3 LastCameraPosition
			{
				virtual Vector3 get() sealed;

				protected:
					void set(Vector3 value);
			}

			property unsigned int CurrentFrameNumber
			{
				virtual unsigned int get() sealed;
				virtual void set(unsigned int value) sealed;
			}

		protected:
			literal int VisRenderWidth = PhysicsSceneClassHelper::VisRenderWidth;
			literal int VisRenderHeight = PhysicsSceneClassHelper::VisRenderHeight;

			void InternalVisReset();

			property ::SceneClass* InternalSceneClassPointer
			{
				::SceneClass* get() override;
			}

			property ::WidgetUserClass* InternalWidgetUserClassPointer
			{
				virtual ::WidgetUserClass* get();
			}

			property ::PhysicsSceneClass* InternalPhysicsSceneClassPointer
			{
				virtual ::PhysicsSceneClass* get();
			}

			property IRefMultiListClass<IPhysClass^>^ VisibleStaticObjectList
			{
				IRefMultiListClass<IPhysClass^>^ get();
			}

			property IRefMultiListClass<IPhysClass^>^ VisibleWSMeshList
			{
				IRefMultiListClass<IPhysClass^>^ get();
			}

			property IRefMultiListClass<IPhysClass^>^ VisibleDynamicObjectList
			{
				IRefMultiListClass<IPhysClass^>^ get();
			}

			property IMultiListClass<IntPtr>^ ActiveTextureProjectors
			{
				IMultiListClass<IntPtr>^ get();
			}

			property int FrameNum
			{
				int get();
				void set(int value);
			}

			property int LastValidVisId
			{
				int get();
				void set(int value);
			}

			property IStatsStruct^ LastValidStats
			{
				IStatsStruct^ get();
				void set(IStatsStruct^ value);
			}

			property IStatsStruct^ CurrentStats
			{
				IStatsStruct^ get();
				void set(IStatsStruct^ value);
			}

			property bool StaticProjectorsDirty
			{
				bool get();
				void set(bool value);
			}

			property bool VisEnabled
			{
				bool get();
				void set(bool value);
			}

			property bool VisInverted
			{
				bool get();
				void set(bool value);
			}

			property bool VisQuickAndDirty
			{
				bool get();
				void set(bool value);
			}

			property bool VisSectorDisplayEnabled
			{
				bool get();
				void set(bool value);
			}

			property bool VisSectorHistoryEnabled
			{
				bool get();
				void set(bool value);
			}

			property int VisGridDisplayMode
			{
				int get();
				void set(int value);
			}

			property bool VisSectorMissing
			{
				bool get();
				void set(bool value);
			}

			property bool VisSectorFallbackEnabled
			{
				bool get();
				void set(bool value);
			}

			property bool BackfaceDebugEnabled
			{
				bool get();
				void set(bool value);
			}

			property bool VisSamplePointLocked
			{
				bool get();
				void set(bool value);
			}

			property Vector3 LockedVisSamplePoint
			{
				Vector3 get();
				void set(Vector3 value);
			}

			property IntPtr VisCamera
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property IVisTableClass^ CurrentVisTable
			{
				IVisTableClass^ get();
				void set(IVisTableClass^ value);
			}

			property bool StaticProjectorsEnabled
			{
				bool get();
				void set(bool value);
			}

			property bool DynamicProjectorsEnabled
			{
				bool get();
				void set(bool value);
			}

			property IPhysicsSceneClass::ShadowEnum ShadowMode
			{
				IPhysicsSceneClass::ShadowEnum get();
				void set(IPhysicsSceneClass::ShadowEnum value);
			}

			property float ShadowAttenStart
			{
				float get();
				void set(float value);
			}

			property float ShadowAttenEnd
			{
				float get();
				void set(float value);
			}

			property float ShadowNormalIntensity
			{
				float get();
				void set(float value);
			}

			property IntPtr ShadowBlobTexture
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property IntPtr ShadowRenderContext
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property IntPtr ShadowCamera
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property IntPtr ShadowMaterialPass
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property int ShadowResWidth
			{
				int get();
				void set(int value);
			}

			property int ShadowResHeight
			{
				int get();
				void set(int value);
			}

			property IntPtr DecalSystem
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property IntPtr Pathfinder
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property IntPtr CameraShakeSystem
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property IRefMultiListClass<IRenderObjClass^>^ UpdateList
			{
				IRefMultiListClass<IRenderObjClass^>^ get();
			}

			property IRefMultiListClass<IRenderObjClass^>^ VertexProcList
			{
				IRefMultiListClass<IRenderObjClass^>^ get();
			}

			property IRefMultiListClass<IPhysClass^>^ ReleaseList
			{
				IRefMultiListClass<IPhysClass^>^ get();
			}

			property IntPtr HighlightMaterialPass
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property IntPtr StaticCullingSystem
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property IntPtr StaticLightingSystem
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property IntPtr DynamicCullingSystem
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property IntPtr DynamicObjVisSystem
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property ITypedAABTreeCullSystemClass<IntPtr>^ StaticProjectorCullingSystem
			{
				ITypedAABTreeCullSystemClass<IntPtr>^ get();
				void set(ITypedAABTreeCullSystemClass<IntPtr>^ value);
			}

			property ITypedGridCullSystemClass<IntPtr>^ DynamicProjectorCullingSystem
			{
				ITypedGridCullSystemClass<IntPtr>^ get();
				void set(ITypedGridCullSystemClass<IntPtr>^ value);
			}

			property IVisTableMgrClass^ VisTableManager
			{
				IVisTableMgrClass^ get();
				void set(IVisTableMgrClass^ value);
			}

			property Vector3 SceneAmbientLight
			{
				Vector3 get();
				void set(Vector3 value);
			}

			property bool UseSun
			{
				bool get();
				void set(bool value);
			}

			property float SunPitch
			{
				float get();
				void set(float value);
			}

			property float SunYaw
			{
				float get();
				void set(float value);
			}

			property IntPtr SunLight
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property int DynamicPolyBudget
			{
				int get();
				void set(int value);
			}

			property int StaticPolyBudget
			{
				int get();
				void set(int value);
			}

			property float MapStaticPolyBudget
			{
				float get();
				void set(float value);
			}

			property float MapDynamicPolyBudget
			{
				float get();
				void set(float value);
			}

			property IRefMultiListClass<IPhysClass^>^ ObjList
			{
				IRefMultiListClass<IPhysClass^>^ get();
			}

			property IRefMultiListClass<IPhysClass^>^ StaticObjList
			{
				IRefMultiListClass<IPhysClass^>^ get();
			}

			property IRefMultiListClass<IPhysClass^>^ StaticLightList
			{
				IRefMultiListClass<IPhysClass^>^ get();
			}

			property IMultiListClass<IntPtr>^ StaticProjectorList
			{
				IMultiListClass<IntPtr>^ get();
			}

			property IMultiListClass<IntPtr>^ DynamicProjectorList
			{
				IMultiListClass<IntPtr>^ get();
			}

			property IRefMultiListClass<IPhysClass^>^ DirtyCullList
			{
				IRefMultiListClass<IPhysClass^>^ get();
			}

			property IRefMultiListClass<IPhysClass^>^ TimestepList
			{
				IRefMultiListClass<IPhysClass^>^ get();
			}

			property IRefMultiListClass<IPhysClass^>^ StaticAnimList
			{
				IRefMultiListClass<IPhysClass^>^ get();
			}

			property IMultiListClass<IPhysClass^>^ CollisionRegionList
			{
				IMultiListClass<IPhysClass^>^ get();
			}
	};
}