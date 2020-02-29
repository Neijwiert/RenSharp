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

#include "stdafx.h"
#include "MAudibleSoundClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <AudibleSoundDefinitionClass.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MAudibleSoundDefinitionClass.h"
#include "MSoundBufferClass.h"
#include "MMatrix3D.h"

namespace RenSharp
{

#pragma managed(push, off)

	class AudibleSoundClassHelper : public ::AudibleSoundClass
	{
		private:
			AudibleSoundClassHelper() = default;

		public:
			uint32 &GetState()
			{
				return state;
			}

			uint32 &GetDuration()
			{
				return duration;
			}

			::SoundHandleClass *&GetHandle()
			{
				return handle;
			}

			uint32 &GetTime()
			{
				return time;
			}

			::AudibleSoundClass::Fade &GetFade()
			{
				return fade;
			}

			uint32 &GetFadeRemainingTime()
			{
				return fadeRemainingTime;
			}

			uint32 &GetFadeTime()
			{
				return fadeTime;
			}

			uint32 &GetChannel()
			{
				return channel;
			}

			::SoundBufferClass *&GetBuffer()
			{
				return buffer;
			}

			float &GetPriority()
			{
				return priority;
			}

			float &GetRealVolume()
			{
				return realVolume;
			}

			int32 &GetRemainingLoops()
			{
				return remainingLoops;
			}

			float &GetStartPosition()
			{
				return startPosition;
			}

			float &GetPitch()
			{
				return pitch;
			}

			::Matrix3D &GetListenerTransform()
			{
				return listenerTransform;
			}

			::Matrix3D &GetO260()
			{
				return o260;
			}

			bool &GetCulled()
			{
				return culled;
			}

			::FilteredSoundClass *&GetFilteredSound()
			{
				return filteredSound;
			}

			::LogicalSoundClass *&GetLogicalSound()
			{
				return logicalSound;
			}
	};

#pragma managed(pop)

	AudibleSoundClass::AudibleSoundClass(IntPtr pointer)
		: SoundSceneObjClass(pointer)
	{

	}

	IAudibleSoundClass ^AudibleSoundClass::AsAudibleSoundClass()
	{
		return this;
	}

	bool AudibleSoundClass::Play(bool addToPlaylist)
	{
		return InternalAudibleSoundClassPointer->Play(addToPlaylist);
	}

	bool AudibleSoundClass::Pause()
	{
		return InternalAudibleSoundClassPointer->Pause();
	}

	bool AudibleSoundClass::Resume()
	{
		return InternalAudibleSoundClassPointer->Resume();
	}

	bool AudibleSoundClass::Stop(bool removeFromPlaylist)
	{
		return InternalAudibleSoundClassPointer->Stop(removeFromPlaylist);
	}

	void AudibleSoundClass::Seek(uint32 playPosition)
	{
		InternalAudibleSoundClassPointer->Seek(playPosition);
	}

	void AudibleSoundClass::FadeOut(uint32 fadeTime)
	{
		InternalAudibleSoundClassPointer->Fade_Out(fadeTime);
	}

	void AudibleSoundClass::FadeIn(uint32 fadeTime)
	{
		InternalAudibleSoundClassPointer->Fade_In(fadeTime);
	}

	void AudibleSoundClass::UpdateVolume()
	{
		InternalAudibleSoundClassPointer->Update_Volume();
	}

	float AudibleSoundClass::GetPriority()
	{
		return InternalAudibleSoundClassPointer->Get_Priority();
	}

	float AudibleSoundClass::PeekPriority()
	{
		return InternalAudibleSoundClassPointer->Peek_Priority();
	}

	void AudibleSoundClass::SetPriority(float priority)
	{
		InternalAudibleSoundClassPointer->Set_Priority(priority);
	}

	void AudibleSoundClass::SetPlayPosition(float playPosition)
	{
		InternalAudibleSoundClassPointer->Set_Play_Position(playPosition);
	}

	void AudibleSoundClass::ReSync(IAudibleSoundClass ^sound)
	{
		if (sound == nullptr || sound->AudibleSoundClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("sound");
		}

		InternalAudibleSoundClassPointer->Re_Sync(
			*reinterpret_cast<::AudibleSoundClass *>(sound->AudibleSoundClassPointer.ToPointer()));
	}

	void AudibleSoundClass::FreeConversion()
	{
		InternalAudibleSoundClassPointer->Free_Conversion();
	}

	void AudibleSoundClass::ConvertToFiltered()
	{
		InternalAudibleSoundClassPointer->Convert_To_Filtered();
	}

	IntPtr AudibleSoundClass::AsConvertedFormat()
	{
		return IntPtr(InternalAudibleSoundClassPointer->As_Converted_Format());
	}

	float AudibleSoundClass::DetermineRealVolume()
	{
		return InternalAudibleSoundClassPointer->Determine_Real_Volume();
	}

	void AudibleSoundClass::InternalSetVolume(float volume)
	{
		InternalAudibleSoundClassPointer->Internal_Set_Volume(volume);
	}

	void AudibleSoundClass::UpdateFade()
	{
		InternalAudibleSoundClassPointer->Update_Fade();
	}

	void AudibleSoundClass::FreeMilesHandle()
	{
		InternalAudibleSoundClassPointer->Free_Miles_Handle();
	}

	void AudibleSoundClass::InitializeMilesHandle()
	{
		InternalAudibleSoundClassPointer->Initialize_Miles_Handle();
	}

	void AudibleSoundClass::AllocateMilesHandle()
	{
		InternalAudibleSoundClassPointer->Allocate_Miles_Handle();
	}

	ISoundBufferClass ^AudibleSoundClass::GetBuffer()
	{
		auto result = InternalAudibleSoundClassPointer->Get_Buffer();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SoundBufferClass(IntPtr(result));
		}
	}

	ISoundBufferClass ^AudibleSoundClass::PeekBuffer()
	{
		auto result = InternalAudibleSoundClassPointer->Peek_Buffer();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SoundBufferClass(IntPtr(result));
		}
	}

	void AudibleSoundClass::SetBuffer(ISoundBufferClass ^buffer)
	{
		if (buffer == nullptr || buffer->SoundBufferClassPointer.ToPointer() == nullptr)
		{
			InternalAudibleSoundClassPointer->Set_Buffer(nullptr);
		}
		else
		{
			InternalAudibleSoundClassPointer->Set_Buffer(
				reinterpret_cast<::SoundBufferClass *>(buffer->SoundBufferClassPointer.ToPointer()));
		}
	}

	void AudibleSoundClass::RestartLoop()
	{
		InternalAudibleSoundClassPointer->Restart_Loop();
	}

	void AudibleSoundClass::UpdatePlayPosition()
	{
		InternalAudibleSoundClassPointer->Update_Play_Position();
	}

	void AudibleSoundClass::OnLoopEnd()
	{
		InternalAudibleSoundClassPointer->On_Loop_End();
	}

	IntPtr AudibleSoundClass::AudibleSoundClassPointer::get()
	{
		return IntPtr(InternalAudibleSoundClassPointer);
	}

	unsigned long AudibleSoundClass::ClassID::get()
	{
		return InternalAudibleSoundClassPointer->Get_Class_ID();
	}

	IAudibleSoundClass::SoundType AudibleSoundClass::Type::get()
	{
		return static_cast<IAudibleSoundClass::SoundType>(InternalAudibleSoundClassPointer->Get_Type());
	}

	void AudibleSoundClass::Type::set(IAudibleSoundClass::SoundType value)
	{
		InternalAudibleSoundClassPointer->Set_Type(static_cast<::AudibleSoundClass::SoundType>(value));
	}

	uint32 AudibleSoundClass::State::get()
	{
		return InternalAudibleSoundClassPointer->Get_State();
	}

	void AudibleSoundClass::State::set(uint32 value)
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &state = helper->GetState();

		state = value;
	}

	uint32 AudibleSoundClass::Timestamp::get()
	{
		return InternalAudibleSoundClassPointer->Get_Timestamp();
	}

	uint32 AudibleSoundClass::VirtualChannel::get()
	{
		return InternalAudibleSoundClassPointer->Get_Virtual_Channel();
	}

	void AudibleSoundClass::VirtualChannel::set(uint32 value)
	{
		InternalAudibleSoundClassPointer->Set_Virtual_Channel(value);
	}

	String ^AudibleSoundClass::Filename::get()
	{
		auto result = InternalAudibleSoundClassPointer->Get_Filename();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	bool AudibleSoundClass::IsPlaying::get()
	{
		return InternalAudibleSoundClassPointer->Is_Playing();
	}

	float AudibleSoundClass::Pan::get()
	{
		return InternalAudibleSoundClassPointer->Get_Pan();
	}

	void AudibleSoundClass::Pan::set(float value)
	{
		InternalAudibleSoundClassPointer->Set_Pan(value);
	}

	float AudibleSoundClass::Volume::get()
	{
		return InternalAudibleSoundClassPointer->Get_Volume();
	}

	void AudibleSoundClass::Volume::set(float value)
	{
		InternalAudibleSoundClassPointer->Set_Volume(value);
	}

	uint32 AudibleSoundClass::LoopCount::get()
	{
		return InternalAudibleSoundClassPointer->Get_Loop_Count();
	}

	void AudibleSoundClass::LoopCount::set(uint32 value)
	{
		InternalAudibleSoundClassPointer->Set_Loop_Count(value);
	}

	uint32 AudibleSoundClass::LoopsLeft::get()
	{
		return InternalAudibleSoundClassPointer->Get_Loops_Left();
	}

	float AudibleSoundClass::RuntimePriority::get()
	{
		return InternalAudibleSoundClassPointer->Get_Runtime_Priority();
	}

	void AudibleSoundClass::RuntimePriority::set(float value)
	{
		InternalAudibleSoundClassPointer->Set_Runtime_Priority(value);
	}

	uint32 AudibleSoundClass::PlaybackRate::get()
	{
		return InternalAudibleSoundClassPointer->Get_Playback_Rate();
	}

	void AudibleSoundClass::PlaybackRate::set(uint32 value)
	{
		InternalAudibleSoundClassPointer->Set_Playback_Rate(value);
	}

	float AudibleSoundClass::PitchFactor::get()
	{
		return InternalAudibleSoundClassPointer->Get_Pitch_Factor();
	}

	void AudibleSoundClass::PitchFactor::set(float value)
	{
		InternalAudibleSoundClassPointer->Set_Pitch_Factor(value);
	}

	uint32 AudibleSoundClass::Duration::get()
	{
		return InternalAudibleSoundClassPointer->Get_Duration();
	}

	void AudibleSoundClass::Duration::set(uint32 value)
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &duration = helper->GetDuration();

		duration = value;
	}

	uint32 AudibleSoundClass::PlayPosition::get()
	{
		return InternalAudibleSoundClassPointer->Get_Play_Position();
	}

	void AudibleSoundClass::PlayPosition::set(uint32 value)
	{
		InternalAudibleSoundClassPointer->Set_Play_Position(value);
	}

	float AudibleSoundClass::StartOffset::get()
	{
		return InternalAudibleSoundClassPointer->Get_Start_Offset();
	}

	void AudibleSoundClass::StartOffset::set(float value)
	{
		InternalAudibleSoundClassPointer->Set_Start_Offset(value);
	}

	bool AudibleSoundClass::IsDirty::get()
	{
		return InternalAudibleSoundClassPointer->Is_Dirty();
	}

	void AudibleSoundClass::IsDirty::set(bool value)
	{
		InternalAudibleSoundClassPointer->Set_Dirty(value);
	}

	IAudibleSoundDefinitionClass ^AudibleSoundClass::Definition::get()
	{
		auto defPtr = InternalAudibleSoundClassPointer->Get_Definition();
		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			auto result = DefinitionClass::CreateDefinitionClassWrapper(defPtr);
			if (result != nullptr)
			{
				return safe_cast<IAudibleSoundDefinitionClass^>(result);
			}

			return gcnew AudibleSoundDefinitionClass(IntPtr(defPtr));
		}
	}

	void AudibleSoundClass::Definition::set(IAudibleSoundDefinitionClass ^value)
	{
		if (value == nullptr || value->AudibleSoundDefinitionClassPointer.ToPointer() == nullptr)
		{
			InternalAudibleSoundClassPointer->Set_Definition(nullptr);
		}
		else
		{
			InternalAudibleSoundClassPointer->Set_Definition(
				reinterpret_cast<::AudibleSoundDefinitionClass *>(value->AudibleSoundDefinitionClassPointer.ToPointer()));
		}
	}

	IntPtr AudibleSoundClass::MilesHandle::get()
	{
		return IntPtr(InternalAudibleSoundClassPointer->Get_Miles_Handle());
	}

	void AudibleSoundClass::MilesHandle::set(IntPtr value)
	{
		InternalAudibleSoundClassPointer->Set_Miles_Handle(
			reinterpret_cast<::HSAMPLE>(value.ToPointer()));
	}

	::MultiListObjectClass *AudibleSoundClass::InternalMultiListObjectClassPointer::get()
	{
		return InternalAudibleSoundClassPointer;
	}

	::RefCountClass *AudibleSoundClass::InternalRefCountClassPointer::get()
	{
		return InternalAudibleSoundClassPointer;
	}

	::SoundSceneObjClass *AudibleSoundClass::InternalSoundSceneObjClassPointer::get()
	{
		return InternalAudibleSoundClassPointer;
	}

	::AudibleSoundClass *AudibleSoundClass::InternalAudibleSoundClassPointer::get()
	{
		return reinterpret_cast<::AudibleSoundClass *>(Pointer.ToPointer());
	}

	IntPtr AudibleSoundClass::Handle::get()
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &handle = helper->GetHandle();

		return IntPtr(handle);
	}

	void AudibleSoundClass::Handle::set(IntPtr value)
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &handle = helper->GetHandle();

		handle = reinterpret_cast<::SoundHandleClass *>(value.ToPointer());
	}

	uint32 AudibleSoundClass::Time::get()
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &time = helper->GetTime();

		return time;
	}

	void AudibleSoundClass::Time::set(uint32 value)
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &time = helper->GetTime();

		time = value;
	}
	
	IAudibleSoundClass::Fade AudibleSoundClass::_Fade::get()
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &fade = helper->GetFade();

		return static_cast<IAudibleSoundClass::Fade>(fade);
	}

	void AudibleSoundClass::_Fade::set(IAudibleSoundClass::Fade value)
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &fade = helper->GetFade();

		fade = static_cast<::AudibleSoundClass::Fade>(value);
	}
	
	uint32 AudibleSoundClass::FadeRemainingTime::get()
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &fadeRemainingTime = helper->GetFadeRemainingTime();

		return fadeRemainingTime;
	}

	void AudibleSoundClass::FadeRemainingTime::set(uint32 value)
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &fadeRemainingTime = helper->GetFadeRemainingTime();

		fadeRemainingTime = value;
	}

	uint32 AudibleSoundClass::FadeTime::get()
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &fadeTime = helper->GetFadeTime();

		return fadeTime;
	}

	void AudibleSoundClass::FadeTime::set(uint32 value)
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &fadeTime = helper->GetFadeTime();

		fadeTime = value;
	}

	uint32 AudibleSoundClass::Channel::get()
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &channel = helper->GetChannel();

		return channel;
	}

	void AudibleSoundClass::Channel::set(uint32 value)
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &channel = helper->GetChannel();

		channel = value;
	}

	ISoundBufferClass ^AudibleSoundClass::Buffer::get()
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &buffer = helper->GetBuffer();

		if (buffer == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SoundBufferClass(IntPtr(buffer));
		}
	}

	void AudibleSoundClass::Buffer::set(ISoundBufferClass ^value)
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &buffer = helper->GetBuffer();

		if (value == nullptr || value->SoundBufferClassPointer.ToPointer() == nullptr)
		{
			buffer = nullptr;
		}
		else
		{
			buffer = reinterpret_cast<::SoundBufferClass *>(value->SoundBufferClassPointer.ToPointer());
		}
	}

	float AudibleSoundClass::Priority::get()
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &priority = helper->GetPriority();

		return priority;
	}

	void AudibleSoundClass::Priority::set(float value)
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &priority = helper->GetPriority();

		priority = value;
	}

	float AudibleSoundClass::RealVolume::get()
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &realVolume = helper->GetRealVolume();

		return realVolume;
	}

	void AudibleSoundClass::RealVolume::set(float value)
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &realVolume = helper->GetRealVolume();

		realVolume = value;
	}

	int32 AudibleSoundClass::RemainingLoops::get()
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &remainingLoops = helper->GetRemainingLoops();

		return remainingLoops;
	}

	void AudibleSoundClass::RemainingLoops::set(int32 value)
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &remainingLoops = helper->GetRemainingLoops();

		remainingLoops = value;
	}

	float AudibleSoundClass::StartPosition::get()
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &startPosition = helper->GetStartPosition();

		return startPosition;
	}

	void AudibleSoundClass::StartPosition::set(float value)
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &startPosition = helper->GetStartPosition();

		startPosition = value;
	}

	float AudibleSoundClass::Pitch::get()
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &pitch = helper->GetPitch();

		return pitch;
	}

	void AudibleSoundClass::Pitch::set(float value)
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &pitch = helper->GetPitch();

		pitch = value;
	}

	Matrix3D AudibleSoundClass::ListenerTransform::get()
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &listenerTransform = helper->GetListenerTransform();

		Matrix3D result;

		Matrix3D::UnmanagedToManagedMatrix3D(listenerTransform, result);

		return result;
	}

	void AudibleSoundClass::ListenerTransform::set(Matrix3D value)
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &listenerTransform = helper->GetListenerTransform();

		Matrix3D::ManagedToUnmanagedMatrix3D(value, listenerTransform);
	}

	Matrix3D AudibleSoundClass::O260::get()
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &o260 = helper->GetO260();

		Matrix3D result;

		Matrix3D::UnmanagedToManagedMatrix3D(o260, result);

		return result;
	}

	void AudibleSoundClass::O260::set(Matrix3D value)
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &o260 = helper->GetO260();

		Matrix3D::ManagedToUnmanagedMatrix3D(value, o260);
	}

	bool AudibleSoundClass::Culled::get()
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &culled = helper->GetCulled();

		return culled;
	}

	void AudibleSoundClass::Culled::set(bool value)
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &culled = helper->GetCulled();

		culled = value;
	}

	IntPtr AudibleSoundClass::FilteredSound::get()
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &filteredSound = helper->GetFilteredSound();

		return IntPtr(filteredSound);
	}

	void AudibleSoundClass::FilteredSound::set(IntPtr value)
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &filteredSound = helper->GetFilteredSound();

		filteredSound = reinterpret_cast<::FilteredSoundClass *>(value.ToPointer());
	}

	IntPtr AudibleSoundClass::LogicalSound::get()
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &logicalSound = helper->GetLogicalSound();

		return IntPtr(logicalSound);
	}

	void AudibleSoundClass::LogicalSound::set(IntPtr value)
	{
		auto helper = reinterpret_cast<AudibleSoundClassHelper *>(InternalAudibleSoundClassPointer);

		auto &logicalSound = helper->GetLogicalSound();

		logicalSound = reinterpret_cast<::LogicalSoundClass *>(value.ToPointer());
	}
}