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

#include "stdafx.h"
#include "Maudiocallback.h"

#include "Imports.h"
#include "MSoundSceneObjClass.h"
#include "MSoundSceneObjClassPtrDynamicVectorClass.h"

namespace RenSharp
{
	AudioCallbackClass::AudioCallbackClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool AudioCallbackClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IAudioCallbackClass ^otherThis = dynamic_cast<IAudioCallbackClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return AudioCallbackClassPointer.Equals(otherThis->AudioCallbackClassPointer);
	}

	void AudioCallbackClass::OnSoundStarted(ISoundSceneObjClass ^soundObj)
	{
		if (soundObj == nullptr || soundObj->SoundSceneObjClassPointer.ToPointer() == nullptr)
		{
			InternalAudioCallbackClassPointer->On_Sound_Started(nullptr);
		}
		else
		{
			InternalAudioCallbackClassPointer->On_Sound_Started(reinterpret_cast<::SoundSceneObjClass *>(soundObj->SoundSceneObjClassPointer.ToPointer()));
		}
	}

	void AudioCallbackClass::OnSoundEnded(ISoundSceneObjClass ^soundObj)
	{
		if (soundObj == nullptr || soundObj->SoundSceneObjClassPointer.ToPointer() == nullptr)
		{
			InternalAudioCallbackClassPointer->On_Sound_Ended(nullptr);
		}
		else
		{
			InternalAudioCallbackClassPointer->On_Sound_Ended(reinterpret_cast<::SoundSceneObjClass *>(soundObj->SoundSceneObjClassPointer.ToPointer()));
		}
	}

	void AudioCallbackClass::OnLogicalHeard(IntPtr listener, IntPtr soundObj)
	{
		if (soundObj == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("soundObj");
		}

		InternalAudioCallbackClassPointer->On_Logical_Heard(reinterpret_cast<::LogicalListenerClass *>(listener.ToPointer()), reinterpret_cast<::LogicalSoundClass *>(soundObj.ToPointer()));
	}

	IntPtr AudioCallbackClass::AudioCallbackClassPointer::get()
	{
		return IntPtr(InternalAudioCallbackClassPointer);
	}

	IDynamicVectorClass<ISoundSceneObjClass ^> ^AudioCallbackClass::SoundList::get()
	{
		return gcnew SoundSceneObjClassPtrDynamicVectorClass(IntPtr(&InternalAudioCallbackClassPointer->SoundList));
	}

	void AudioCallbackClass::SoundList::set(IDynamicVectorClass<ISoundSceneObjClass ^> ^value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalAudioCallbackClassPointer->SoundList = *reinterpret_cast<::DynamicVectorClass<::SoundSceneObjClass *> *>(value->Pointer.ToPointer());
	}

	bool AudioCallbackClass::InternalDestroyPointer()
	{
		Imports::DestroyAudioCallbackClass(InternalAudioCallbackClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::AudioCallbackClass *AudioCallbackClass::InternalAudioCallbackClassPointer::get()
	{
		return reinterpret_cast<::AudioCallbackClass *>(Pointer.ToPointer());
	}
}