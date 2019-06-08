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

#include "IUnmanagedObject.h"
#include "AbstractUnmanagedObject.h"
#include "Mengine_vector.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <audiocallback.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System;

namespace RenSharp
{
	interface class ISoundSceneObjClass;

	public interface class IAudioCallbackClass : public IUnmanagedObject
	{
		enum class AudioCallbackEvent : int
		{
			EventNone = ::AudioCallbackClass::EVENTS::EVENT_NONE,
			EventSoundStarted = ::AudioCallbackClass::EVENTS::EVENT_SOUND_STARTED,
			EventSoundEnded = ::AudioCallbackClass::EVENTS::EVENT_SOUND_ENDED,
			EventLogicalHeard = ::AudioCallbackClass::EVENTS::EVENT_LOGICAL_HEARD
		};

		void OnSoundStarted(ISoundSceneObjClass ^soundObj);

		void OnSoundEnded(ISoundSceneObjClass ^soundObj);

		void OnLogicalHeard(IntPtr listener, IntPtr soundObj);

		property IntPtr AudioCallbackClassPointer
		{
			IntPtr get();
		}

		property IDynamicVectorClass<ISoundSceneObjClass ^> ^SoundList
		{
			IDynamicVectorClass<ISoundSceneObjClass ^> ^get();
			void set(IDynamicVectorClass<ISoundSceneObjClass ^> ^value);
		}
	};

	public ref class AudioCallbackClass : public AbstractUnmanagedObject, public IAudioCallbackClass
	{
		public:
			AudioCallbackClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual void OnSoundStarted(ISoundSceneObjClass ^soundObj) sealed;
			virtual void OnSoundEnded(ISoundSceneObjClass ^soundObj) sealed;
			virtual void OnLogicalHeard(IntPtr listener, IntPtr soundObj) sealed;

			property IntPtr AudioCallbackClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IDynamicVectorClass<ISoundSceneObjClass ^> ^SoundList
			{
				virtual IDynamicVectorClass<ISoundSceneObjClass ^> ^get() sealed;
				virtual void set(IDynamicVectorClass<ISoundSceneObjClass ^> ^value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::AudioCallbackClass *InternalAudioCallbackClassPointer
			{
				virtual ::AudioCallbackClass *get();
			}
	};
}