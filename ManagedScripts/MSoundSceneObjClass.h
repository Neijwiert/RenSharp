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

#include "Mmultilist.h"
#include "MPersist.h"
#include "Mengine_vector.h"
#include "Maudiocallback.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <SoundSceneObjClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	interface class ISound3DClass;
	interface class IAudibleSoundClass;
	value class Vector3;
	value class Matrix3D;
	interface class IRenderObjClass;

	public interface class ISoundSceneObjClass : public IMultiListObjectClass, public IPersistClass, public IRefCountClass
	{
		literal uint32 SoundObjDefaultID = ::SOUND_OBJ_DEFAULT_ID;

		literal uint32 SoundObjStartID = ::SOUND_OBJ_START_ID;

		ISound3DClass ^AsSound3DClass();

		IntPtr AsSoundPseudo3DClass();

		IntPtr AsFilteredSoundClass();

		IntPtr AsListener3DClass();

		IAudibleSoundClass ^AsAudibleSoundClass();

		bool OnFrameUpdate(unsigned int milliseconds);

		bool OnFrameUpdate();

		void OnEvent(IAudioCallbackClass::AudioCallbackEvent event, uint32 param1, uint32 param2);

		void OnEvent(IAudioCallbackClass::AudioCallbackEvent event, uint32 param1);

		void OnEvent(IAudioCallbackClass::AudioCallbackEvent event);

		void RegisterCallback(IAudioCallbackClass::AudioCallbackEvent events, IAudioCallbackClass ^callback);

		void RemoveCallback();

		void SetListenerTransform(Matrix3D tm);

		void CullSound(bool culled);

		void CullSound();

		void SetUserData(IRefCountClass ^userObj, uint32 user);

		void SetUserData(IRefCountClass ^userObj);

		void SetUserData();

		IRefCountClass ^PeekUserObj();

		void AttachToObject(IRenderObjClass ^renderObj, int boneIndex);

		void AttachToObject(IRenderObjClass ^renderObj);

		void AttachToObject(IRenderObjClass ^renderObj, String ^boneName);

		IRenderObjClass ^PeekParentObject();

		void ApplyAutoPosition();

		void AddToScene(bool startPlaying);

		void AddToScene();

		void RemoveFromScene();

		void SetDropOffRadius(float radius);

		void SetDropOffRadius();

		property IntPtr SoundSceneObjClassPointer
		{
			IntPtr get();
		}

		property uint32 ID
		{
			uint32 get();
			void set(uint32 value);
		}

		property Vector3 Position
		{
			Vector3 get();
			void set(Vector3 value);
		}

		property Matrix3D Transform
		{
			Matrix3D get();
			void set(Matrix3D value);
		}

		property bool IsSoundCulled
		{
			bool get();
		}

		property uint32 UserData
		{
			uint32 get();
		}

		property int AttachedBone
		{
			int get();
		}

		property bool IsInScene
		{
			bool get();
		}

		property float DropOffRadius
		{
			float get();
		}
	};

	public ref class SoundSceneObjClass : public PersistClass, public ISoundSceneObjClass
	{
		private:
			IMultiListObjectClass ^multiListObjectClass;
			IRefCountClass ^refCountClass;

		public:
			SoundSceneObjClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual void DeleteThis() sealed;
			virtual void ReleaseRef() sealed;
			virtual void AddRef() sealed;
			virtual void Release() sealed;
			virtual ISound3DClass ^AsSound3DClass();
			virtual IntPtr AsSoundPseudo3DClass();
			virtual IntPtr AsFilteredSoundClass();
			virtual IntPtr AsListener3DClass();
			virtual IAudibleSoundClass ^AsAudibleSoundClass();
			virtual bool OnFrameUpdate(unsigned int milliseconds) sealed;
			virtual bool OnFrameUpdate() sealed;
			virtual void OnEvent(IAudioCallbackClass::AudioCallbackEvent event, uint32 param1, uint32 param2) sealed;
			virtual void OnEvent(IAudioCallbackClass::AudioCallbackEvent event, uint32 param1) sealed;
			virtual void OnEvent(IAudioCallbackClass::AudioCallbackEvent event) sealed;
			virtual void RegisterCallback(IAudioCallbackClass::AudioCallbackEvent events, IAudioCallbackClass ^callback) sealed;
			virtual void RemoveCallback() sealed;
			virtual void SetListenerTransform(Matrix3D tm) sealed;
			virtual void CullSound(bool culled) sealed;
			virtual void CullSound() sealed;
			virtual void SetUserData(IRefCountClass ^userObj, uint32 user) sealed;
			virtual void SetUserData(IRefCountClass ^userObj) sealed;
			virtual void SetUserData() sealed;
			virtual IRefCountClass ^PeekUserObj() sealed;
			virtual void AttachToObject(IRenderObjClass ^renderObj, int boneIndex) sealed;
			virtual void AttachToObject(IRenderObjClass ^renderObj) sealed;
			virtual void AttachToObject(IRenderObjClass ^renderObj, String ^boneName) sealed;
			virtual IRenderObjClass ^PeekParentObject() sealed;
			virtual void ApplyAutoPosition() sealed;
			virtual void AddToScene(bool startPlaying) sealed;
			virtual void AddToScene() sealed;
			virtual void RemoveFromScene() sealed;
			virtual void SetDropOffRadius(float radius) sealed;
			virtual void SetDropOffRadius() sealed;

			property IntPtr Pointer
			{
				IntPtr get() override;

				protected:
					void set(IntPtr value) override;
			}

			property IntPtr MultiListObjectClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr RefCountClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr SoundSceneObjClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IMultiListNodeClass ^ListNode
			{
				virtual IMultiListNodeClass ^get() sealed;
				virtual void set(IMultiListNodeClass ^value) sealed;
			}

			property int NumRefs
			{
				virtual int get() sealed;
			}

			property uint32 ID
			{
				virtual uint32 get() sealed;
				virtual void set(uint32 value) sealed;
			}

			property Vector3 Position
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

			property Matrix3D Transform
			{
				virtual Matrix3D get() sealed;
				virtual void set(Matrix3D value) sealed;
			}

			property bool IsSoundCulled
			{
				virtual bool get() sealed;
			}

			property uint32 UserData
			{
				virtual uint32 get() sealed;

				protected:
					void set(uint32 value);
			}

			property int AttachedBone
			{
				virtual int get() sealed;

				protected:
					void set(int value);
			}

			property bool IsInScene
			{
				virtual bool get() sealed;
			}

			property float DropOffRadius
			{
				virtual float get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;
			IntPtr PeekCullableWrapper();
			void SetCullableWrapper(IntPtr obj);

			property ::PersistClass *InternalPersistClassPointer
			{
				::PersistClass *get() override;
			}

			property ::MultiListObjectClass *InternalMultiListObjectClassPointer
			{
				virtual ::MultiListObjectClass *get();
			}

			property ::RefCountClass *InternalRefCountClassPointer
			{
				virtual ::RefCountClass *get();
			}

			property ::SoundSceneObjClass *InternalSoundSceneObjClassPointer
			{
				virtual ::SoundSceneObjClass *get();
			}

			property IntPtr Scene
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property IntPtr PhysWrapper
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property IAudioCallbackClass ^PCallback
			{
				IAudioCallbackClass ^get();
				void set(IAudioCallbackClass ^value);
			}

			property IAudioCallbackClass::AudioCallbackEvent RegisteredEvents
			{
				IAudioCallbackClass::AudioCallbackEvent get();
				void set(IAudioCallbackClass::AudioCallbackEvent value);
			}

			property IRenderObjClass ^AttachedObject
			{
				IRenderObjClass ^get();
				void set(IRenderObjClass ^value);
			}

			property IRefCountClass ^UserObj
			{
				IRefCountClass ^get();
				void set(IRefCountClass ^value);
			}
	};
}