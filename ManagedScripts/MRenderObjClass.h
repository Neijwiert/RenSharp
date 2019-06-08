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

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <RenderObjClass.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "Mengine_vector.h"
#include "MPersist.h"
#include "Mmultilist.h"

using namespace System::Runtime::InteropServices;

namespace RenSharp
{
	value class AABoxClass;
	interface class ISceneClass;
	value class Matrix3D;
	value class Vector3;
	interface class IRayCollisionTestClass;
	ref class RayCollisionTestClass;
	interface class IAABoxCollisionTestClass;
	ref class AABoxCollisionTestClass;
	interface class IOBBoxCollisionTestClass;
	ref class OBBoxCollisionTestClass;
	interface class IAABoxIntersectionTestClass;
	ref class AABoxIntersectionTestClass;
	interface class IOBBoxIntersectionTestClass;
	ref class OBBoxIntersectionTestClass;
	value class SphereClass;
	interface class IHTreeClass;

	public interface class IRenderObjClass : public IRefCountClass, public IPersistClass, public IMultiListObjectClass
	{
		enum class AnimMode : int
		{
			AnimModeManual = ::RenderObjClass::AnimMode::ANIM_MODE_MANUAL,
			AnimModeLoop = ::RenderObjClass::AnimMode::ANIM_MODE_LOOP,
			AnimModeOnce = ::RenderObjClass::AnimMode::ANIM_MODE_ONCE
		};

		enum class RenderObjFlags : int
		{
			CollisionTypeMask = ::RenderObjClass::COLLISION_TYPE_MASK,
			IsVisible = ::RenderObjClass::IS_VISIBLE,
			IsNotHidden = ::RenderObjClass::IS_NOT_HIDDEN,
			IsNotAnimationHidden = ::RenderObjClass::IS_NOT_ANIMATION_HIDDEN,
			IsForceVisible = ::RenderObjClass::IS_FORCE_VISIBLE,
			BoundingVolumesValid = ::RenderObjClass::BOUNDING_VOLUMES_VALID,
			IsTranslucent = ::RenderObjClass::IS_TRANSLUCENT,
			SubObjsMatchLOD = ::RenderObjClass::SUBOBJS_MATCH_LOD,
			SubObjTransformsDirty = ::RenderObjClass::SUBOBJ_TRANSFORMS_DIRTY,
			HasUserLighting = ::RenderObjClass::HAS_USER_LIGHTING,
			IsReallyVisible = ::RenderObjClass::IS_REALLY_VISIBLE,
			IsNotHiddenAtAll = ::RenderObjClass::IS_NOT_HIDDEN_AT_ALL,
			DefaultBits = ::RenderObjClass::DEFAULT_BITS,
		};

		enum class RenderObjClassId : int
		{
			ClassIdUnknown = ::RenderObjClass::CLASSID_UNKNOWN,
			ClassIdMesh = ::RenderObjClass::CLASSID_MESH,
			ClassIdHModel = ::RenderObjClass::CLASSID_HMODEL,
			ClassIdDistLOD = ::RenderObjClass::CLASSID_DISTLOD,
			ClassIdPreDLODGroup = ::RenderObjClass::CLASSID_PREDLODGROUP,
			ClassIdTileMap = ::RenderObjClass::CLASSID_TILEMAP,
			ClassIdImage3D = ::RenderObjClass::CLASSID_IMAGE3D,
			ClassIdLine3D = ::RenderObjClass::CLASSID_LINE3D,
			ClassIdBitMap2D = ::RenderObjClass::CLASSID_BITMAP2D,
			ClassIdCamera = ::RenderObjClass::CLASSID_CAMERA,
			ClassIdDynaMesh = ::RenderObjClass::CLASSID_DYNAMESH,
			ClassIdDynaScreenMesh = ::RenderObjClass::CLASSID_DYNASCREENMESH,
			ClassIdTextDraw = ::RenderObjClass::CLASSID_TEXTDRAW,
			ClassIdFog = ::RenderObjClass::CLASSID_FOG,
			ClassIdLayerFog = ::RenderObjClass::CLASSID_LAYERFOG,
			ClassIdLight = ::RenderObjClass::CLASSID_LIGHT,
			ClassIdParticleEmitter = ::RenderObjClass::CLASSID_PARTICLEEMITTER,
			ClassIdParticleBuffer = ::RenderObjClass::CLASSID_PARTICLEBUFFER,
			ClassIdScreenPointGroup = ::RenderObjClass::CLASSID_SCREENPOINTGROUP,
			ClassIdViewPointGroup = ::RenderObjClass::CLASSID_VIEWPOINTGROUP,
			ClassIdWorldPointGroup = ::RenderObjClass::CLASSID_WORLDPOINTGROUP,
			ClassIdText2D = ::RenderObjClass::CLASSID_TEXT2D,
			ClassIdText3D = ::RenderObjClass::CLASSID_TEXT3D,
			ClassIdNull = ::RenderObjClass::CLASSID_NULL,
			ClassIdCollection = ::RenderObjClass::CLASSID_COLLECTION,
			ClassIdFlare = ::RenderObjClass::CLASSID_FLARE,
			ClassIdHLOD = ::RenderObjClass::CLASSID_HLOD,
			ClassIdAABox = ::RenderObjClass::CLASSID_AABOX,
			ClassIdOBBox = ::RenderObjClass::CLASSID_OBBOX,
			ClassIdSegLine = ::RenderObjClass::CLASSID_SEGLINE,
			ClassIdSphere = ::RenderObjClass::CLASSID_SPHERE,
			ClassIdRing = ::RenderObjClass::CLASSID_RING,
			ClassIdBoundFog = ::RenderObjClass::CLASSID_BOUNDFOG,
			ClassIdDazzle = ::RenderObjClass::CLASSID_DAZZLE,
			ClassIdSound = ::RenderObjClass::CLASSID_SOUND,
			ClassIdSegLineTrail = ::RenderObjClass::CLASSID_SEGLINETRAIL,
			ClassIdLand = ::RenderObjClass::CLASSID_LAND,
			ClassIdRenegadeTerrain = ::RenderObjClass::CLASSID_RENEGADE_TERRAIN,
			ClassIdUserClipPlaneCamera = ::RenderObjClass::CLASSID_USERCLIPPLANECAMERA,
			ClassIdPlaneReflectionCamera = ::RenderObjClass::CLASSID_PLANEREFLECTIONCAMERA,
			ClassIdSceneUI = ::RenderObjClass::CLASSID_SCENEUI,
			ClassIdDebugVector = ::RenderObjClass::CLASSID_DEBUGVECTOR,
			ClassIdLast = ::RenderObjClass::CLASSID_LAST
		};

		IUnmanagedContainer<IRenderObjClass ^> ^Clone();

		void Render(IntPtr rInfo);

		void SpecialRender(IntPtr rInfo);

		void OnFrameUpdate();

		void Restart();

		void Add(ISceneClass ^scene);

		void Remove();

		ISceneClass ^GetScene();

		ISceneClass ^PeekScene();

		void ValidateTransform();

		void SetPosition(Vector3 position);

		Matrix3D GetTransform([Out] bool %isTransformIdentity);

		Matrix3D GetTransformNoValidityCheck();

		Matrix3D GetTransformNoValidityCheck([Out] bool %isTransformIdentity);

		void NotifyAdded(ISceneClass ^scene);

		void NotifyRemoved(ISceneClass ^scene);

		IRenderObjClass ^GetSubObject(int index);

		int AddSubObject(IRenderObjClass ^subObj);

		int RemoveSubObject(IRenderObjClass ^subObj);

		IRenderObjClass ^GetSubObjectByName(String ^name);

		int GetNumSubObjectsOnBone(int boneIndex);

		IRenderObjClass ^GetSubObjectOnBone(int index, int boneIndex);

		int GetSubObjectBoneIndex(IRenderObjClass ^subObj);

		int AddSubObjectToBone(IRenderObjClass ^subObj, int boneIndex);

		int AddSubObjectToBone(IRenderObjClass ^subObj, String ^name);

		int RemoveSubObjectsFromBone(String ^boneName);

		void UpdateSubObjectTransforms();

		void SetAnimation();

		void SetAnimation(IntPtr motion, float frame, int animMode);

		void SetAnimation(IntPtr motion, float frame);

		void SetAnimation(IntPtr motion0, float frame0, IntPtr motion1, float frame1, float percentage);

		void SetAnimation(IntPtr animCombo);

		IntPtr PeekAnimation();

		String ^GetBoneName(int boneIndex);

		int GetBoneIndex(String ^boneName);

		Matrix3D GetBoneTransform(String ^boneName);

		Matrix3D GetBoneTransform(int boneIndex);

		void CaptureBone(int boneIndex);

		void ReleaseBone(int boneIndex);

		bool IsBoneCaptured(int boneIndex);

		void ControlBone(int boneIndex, Matrix3D objTM, bool worldSpaceTranslation);

		void ControlBone(int boneIndex, Matrix3D objTM );

		bool CastRay(IRayCollisionTestClass ^ray);

		bool CastRay(RayCollisionTestClass ^ray);

		bool CastAABox(IAABoxCollisionTestClass ^box);

		bool CastAABox(AABoxCollisionTestClass ^box);

		bool CastOBBox(IOBBoxCollisionTestClass ^box);

		bool CastOBBox(OBBoxCollisionTestClass ^box);

		bool IntersectAABox(IAABoxIntersectionTestClass ^box);

		bool IntersectAABox(AABoxIntersectionTestClass ^box);

		bool IntersectOBBox(IOBBoxIntersectionTestClass ^box);

		bool IntersectOBBox(OBBoxIntersectionTestClass ^box);

		bool Intersect(IntPtr intersection, IntPtr finalResult);

		bool IntersectSphere(IntPtr intersection, IntPtr finalResult);

		bool IntersectSphereQuick(IntPtr intersection, IntPtr finalResult);

		void UpdateObjSpaceBoundingVolumes();

		void PrepareLOD(IntPtr camera);

		void RecalculateStaticLODFactors();

		void IncrementLOD();

		void DecrementLOD();

		void SetLODBias(float bias);

		int CalculateCostValueArrays(float screenArea, [Out] array<float> ^%values, [Out] array<float> ^%costs);

		bool BuildDependencyList([Out] Generic::ICollection<String ^> ^%fileList, bool recursive);

		bool BuildDependencyList([Out] Generic::ICollection<String ^> ^%fileList);

		bool BuildTextureList([Out] Generic::ICollection<String ^> ^%textureFileList, bool recursive);

		bool BuildTextureList([Out] Generic::ICollection<String ^> ^%textureFileList);

		void CreateDecal(IntPtr generator);

		void DeleteDecal(uint32 decalId);

		void SetUserData(IntPtr value, bool recursive);

		Vector3 GetSnapPoint(int point);

		float GetScreenSize(IntPtr camera);

		void Scale(float scale);

		void Scale(float scaleX, float scaleY, float scaleZ);

		void SaveUserLighting(IChunkSaveClass ^cSave);

		void LoadUserLighting(IChunkLoadClass ^cLoad);

		Generic::ICollection<String ^> ^AddDependenciesToList(bool texturesOnly);

		Generic::ICollection<String ^> ^AddDependenciesToList();

		void UpdateCachedBoundingVolumes();

		void UpdateSubObjectBits();

		void SetSubObjectTransformsDirty(bool onoff);

		void InvalidateCachedBoundingVolumes();

		void ValidateCachedBoundingVolumes();

		property IntPtr RenderObjClassPointer
		{
			IntPtr get();
		}

		property AABoxClass BoundingBox
		{
			AABoxClass get();
		}

		property int ClassId
		{
			int get();
		}

		property String ^Name
		{
			String ^get();
			void set(String ^value);
		}

		property String ^BaseModelName
		{
			String ^get();
			void set(String ^value);
		}

		property int NumPolys
		{
			int get();
		}

		property IRenderObjClass ^Container
		{
			IRenderObjClass ^get();
			void set(IRenderObjClass ^value);
		}

		property Matrix3D Transform
		{
			Matrix3D get();
			void set(Matrix3D value);
		}

		property bool IsTransformIdentity
		{
			bool get();
		}

		property bool IsTransformIdentityNoValidityCheck
		{
			bool get();
		}

		property int NumSubObjects
		{
			int get();
		}

		property int NumBones
		{
			int get();
		}

		property IHTreeClass ^HTree
		{
			IHTreeClass ^get();
		}

		property SphereClass BoundingSphere
		{
			SphereClass get();
		}

		property SphereClass ObjSpaceBoundingSphere
		{
			SphereClass get();
		}

		property AABoxClass ObjSpaceBoundingBox
		{
			AABoxClass get();
		}

		property float Cost
		{
			float get();
		}

		property float Value
		{
			float get();
		}

		property float PostIncrementValue
		{
			float get();
		}

		property int LODLevel
		{
			int get();
			void set(int value);
		}

		property int LODCount
		{
			int get();
		}

		property IRenderObjClass ^CurrentLOD
		{
			IRenderObjClass ^get();
		}

		property IntPtr MaterialInfo
		{
			IntPtr get();
		}

		property IntPtr UserData
		{
			IntPtr get();
		}

		property int NumSnapPoints
		{
			int get();
		}

		property int SortLevel
		{
			int get();
			void set(int value);
		}

		property int IsReallyVisible
		{
			int get();
		}

		property int IsNotHiddenAtAll
		{
			int get();
		}

		property int IsVisible
		{
			int get();
			void set(int value);
		}

		property int IsHidden
		{
			int get();
			void set(int value);
		}

		property int IsAnimationHidden
		{
			int get();
			void set(int value);
		}

		property int IsForceVisible
		{
			int get();
			void set(int value);
		}

		property int HasUserLighting
		{
			int get();
			void set(int value);
		}

		property int IsTranslucent
		{
			int get();
			void set(int value);
		}

		property int CollisionType
		{
			int get();
			void set(int value);
		}

		property int IsComplete
		{
			int get();
		}

		property int IsInScene
		{
			int get();
		}

		property float NativeScreenSize
		{
			float get();
			void set(float value);
		}

		property int IsSubObjectsMatchLODEnabled
		{
			int get();
			void set(int value);
		}
	};

	public ref class RenderObjClass : public RefCountClass, public IRenderObjClass
	{
		private:
			IPersistClass ^persistClass;
			IMultiListObjectClass ^multiListObjectClass;

		public:
			RenderObjClass(IntPtr pointer);

			String ^ToString() override;
			bool Equals(Object ^other) override;

			virtual void OnPostLoad() sealed;
			virtual bool Save(IChunkSaveClass ^csave) sealed;
			virtual bool Load(IChunkLoadClass ^cload) sealed;
			virtual IUnmanagedContainer<IRenderObjClass ^> ^Clone() sealed;
			virtual void Render(IntPtr rInfo) sealed;
			virtual void SpecialRender(IntPtr rInfo) sealed;
			virtual void OnFrameUpdate() sealed;
			virtual void Restart() sealed;
			virtual void Add(ISceneClass ^scene) sealed;
			virtual void Remove() sealed;
			virtual ISceneClass ^GetScene() sealed;
			virtual ISceneClass ^PeekScene() sealed;
			virtual void ValidateTransform() sealed;
			virtual void SetPosition(Vector3 position) sealed;
			virtual Matrix3D GetTransform([Out] bool %isTransformIdentity) sealed;
			virtual Matrix3D GetTransformNoValidityCheck() sealed;
			virtual Matrix3D GetTransformNoValidityCheck([Out] bool %isTransformIdentity) sealed;
			virtual void NotifyAdded(ISceneClass ^scene) sealed;
			virtual void NotifyRemoved(ISceneClass ^scene) sealed;
			virtual IRenderObjClass ^GetSubObject(int index) sealed;
			virtual int AddSubObject(IRenderObjClass ^subObj) sealed;
			virtual int RemoveSubObject(IRenderObjClass ^subObj) sealed;
			virtual IRenderObjClass ^GetSubObjectByName(String ^name) sealed;
			virtual int GetNumSubObjectsOnBone(int boneIndex) sealed;
			virtual IRenderObjClass ^GetSubObjectOnBone(int index, int boneIndex) sealed;
			virtual int GetSubObjectBoneIndex(IRenderObjClass ^subObj) sealed;
			virtual int AddSubObjectToBone(IRenderObjClass ^subObj, int boneIndex) sealed;
			virtual int AddSubObjectToBone(IRenderObjClass ^subObj, String ^name) sealed;
			virtual int RemoveSubObjectsFromBone(String ^boneName) sealed;
			virtual void UpdateSubObjectTransforms() sealed;
			virtual void SetAnimation() sealed;
			virtual void SetAnimation(IntPtr motion, float frame, int animMode) sealed;
			virtual void SetAnimation(IntPtr motion, float frame) sealed;
			virtual void SetAnimation(IntPtr motion0, float frame0, IntPtr motion1, float frame1, float percentage) sealed;
			virtual void SetAnimation(IntPtr animCombo) sealed;
			virtual IntPtr PeekAnimation() sealed;
			virtual String ^GetBoneName(int boneIndex) sealed;
			virtual int GetBoneIndex(String ^boneName) sealed;
			virtual Matrix3D GetBoneTransform(String ^boneName) sealed;
			virtual Matrix3D GetBoneTransform(int boneIndex) sealed;
			virtual void CaptureBone(int boneIndex) sealed;
			virtual void ReleaseBone(int boneIndex) sealed;
			virtual bool IsBoneCaptured(int boneIndex) sealed;
			virtual void ControlBone(int boneIndex, Matrix3D objTM, bool worldSpaceTranslation) sealed;
			virtual void ControlBone(int boneIndex, Matrix3D objTM) sealed;
			virtual bool CastRay(IRayCollisionTestClass ^ray) sealed;
			virtual bool CastRay(RayCollisionTestClass ^ray) sealed;
			virtual bool CastAABox(IAABoxCollisionTestClass ^box) sealed;
			virtual bool CastAABox(AABoxCollisionTestClass ^box) sealed;
			virtual bool CastOBBox(IOBBoxCollisionTestClass ^box) sealed;
			virtual bool CastOBBox(OBBoxCollisionTestClass ^box) sealed;
			virtual bool IntersectAABox(IAABoxIntersectionTestClass ^box) sealed;
			virtual bool IntersectAABox(AABoxIntersectionTestClass ^box) sealed;
			virtual bool IntersectOBBox(IOBBoxIntersectionTestClass ^box) sealed;
			virtual bool IntersectOBBox(OBBoxIntersectionTestClass ^box) sealed;
			virtual bool Intersect(IntPtr intersection, IntPtr finalResult) sealed;
			virtual bool IntersectSphere(IntPtr intersection, IntPtr finalResult) sealed;
			virtual bool IntersectSphereQuick(IntPtr intersection, IntPtr finalResult) sealed;
			virtual void UpdateObjSpaceBoundingVolumes() sealed;
			virtual void PrepareLOD(IntPtr camera) sealed;
			virtual void RecalculateStaticLODFactors() sealed;
			virtual void IncrementLOD() sealed;
			virtual void DecrementLOD() sealed;
			virtual void SetLODBias(float bias) sealed;
			virtual int CalculateCostValueArrays(float screenArea, [Out] array<float> ^%values, [Out] array<float> ^%costs) sealed;
			virtual bool BuildDependencyList([Out] Generic::ICollection<String ^> ^%fileList, bool recursive) sealed;
			virtual bool BuildDependencyList([Out] Generic::ICollection<String ^> ^%fileList) sealed;
			virtual bool BuildTextureList([Out] Generic::ICollection<String ^> ^%textureFileList, bool recursive) sealed;
			virtual bool BuildTextureList([Out] Generic::ICollection<String ^> ^%textureFileList) sealed;
			virtual void CreateDecal(IntPtr generator) sealed;
			virtual void DeleteDecal(uint32 decalId) sealed;
			virtual void SetUserData(IntPtr value, bool recursive) sealed;
			virtual Vector3 GetSnapPoint(int point) sealed;
			virtual float GetScreenSize(IntPtr camera) sealed;
			virtual void Scale(float scale) sealed;
			virtual void Scale(float scaleX, float scaleY, float scaleZ) sealed;
			virtual void SaveUserLighting(IChunkSaveClass ^cSave) sealed;
			virtual void LoadUserLighting(IChunkLoadClass ^cLoad) sealed;
			virtual Generic::ICollection<String ^> ^AddDependenciesToList(bool texturesOnly) sealed;
			virtual Generic::ICollection<String ^> ^AddDependenciesToList() sealed;
			virtual void UpdateCachedBoundingVolumes() sealed;
			virtual void UpdateSubObjectBits() sealed;
			virtual void SetSubObjectTransformsDirty(bool onoff) sealed;
			virtual void InvalidateCachedBoundingVolumes() sealed;
			virtual void ValidateCachedBoundingVolumes() sealed;

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

			property IntPtr RenderObjClassPointer
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

			property AABoxClass BoundingBox
			{
				virtual AABoxClass get() sealed;
			}

			property int ClassId
			{
				virtual int get() sealed;
			}

			property String ^Name
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property String ^BaseModelName
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property int NumPolys
			{
				virtual int get() sealed;
			}

			property IRenderObjClass ^Container
			{
				virtual IRenderObjClass ^get() sealed;
				virtual void set(IRenderObjClass ^value) sealed;
			}

			property Matrix3D Transform
			{
				virtual Matrix3D get() sealed;
				virtual void set(Matrix3D value) sealed;
			}

			property bool IsTransformIdentity
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

			property bool IsTransformIdentityNoValidityCheck
			{
				virtual bool get() sealed;
			}

			property int NumSubObjects
			{
				virtual int get() sealed;
			}

			property int NumBones
			{
				virtual int get() sealed;
			}

			property IHTreeClass ^HTree
			{
				virtual IHTreeClass ^get() sealed;
			}

			property SphereClass BoundingSphere
			{
				virtual SphereClass get() sealed;
			}

			property SphereClass ObjSpaceBoundingSphere
			{
				virtual SphereClass get() sealed;
			}

			property AABoxClass ObjSpaceBoundingBox
			{
				virtual AABoxClass get() sealed;
			}

			property float Cost
			{
				virtual float get() sealed;
			}

			property float Value
			{
				virtual float get() sealed;
			}

			property float PostIncrementValue
			{
				virtual float get() sealed;
			}

			property int LODLevel
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int LODCount
			{
				virtual int get() sealed;
			}

			property IRenderObjClass ^CurrentLOD
			{
				virtual IRenderObjClass ^get() sealed;
			}

			property IntPtr MaterialInfo
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr UserData
			{
				virtual IntPtr get() sealed;

				protected:
					void set(IntPtr value);
			}

			property int NumSnapPoints
			{
				virtual int get() sealed;
			}

			property int SortLevel
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int IsReallyVisible
			{
				virtual int get() sealed;
			}

			property int IsNotHiddenAtAll
			{
				virtual int get() sealed;
			}

			property int IsVisible
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int IsHidden
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int IsAnimationHidden
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int IsForceVisible
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int HasUserLighting
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int IsTranslucent
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int CollisionType
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int IsComplete
			{
				virtual int get() sealed;
			}

			property int IsInScene
			{
				virtual int get() sealed;
			}

			property float NativeScreenSize
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int IsSubObjectsMatchLODEnabled
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

		protected:
			property ::RefCountClass *InternalRefCountClassPointer
			{
				::RefCountClass *get() override;
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

			property ::RenderObjClass *InternalRenderObjClassPointer
			{
				virtual ::RenderObjClass *get();
			}

			property unsigned long Bits
			{
				unsigned long get();
				void set(unsigned long value);
			}

			property SphereClass CachedBoundingSphere
			{
				SphereClass get();
				void set(SphereClass value);
			}

			property AABoxClass CachedBoundingBox
			{
				AABoxClass get();
				void set(AABoxClass value);
			}

			property ISceneClass ^Scene
			{
				ISceneClass ^get();
				void set(ISceneClass ^value);
			}
	};
}