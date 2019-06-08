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

#include "MSoundSceneObjClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <AudibleSoundClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	interface class IAudibleSoundDefinitionClass;
	interface class ISoundBufferClass;
	value class Matrix3D;

	public interface class IAudibleSoundClass : public ISoundSceneObjClass
	{
		enum class Fade : int
		{
			NoFade = ::AudibleSoundClass::NoFade,
			FadeIn = ::AudibleSoundClass::FadeIn,
			FadeOut = ::AudibleSoundClass::FadeOut
		};

		enum class SoundType : int
		{
			TypeMusic = ::AudibleSoundClass::TypeMusic,
			TypeEffect = ::AudibleSoundClass::TypeEffect,
			TypeDialog = ::AudibleSoundClass::TypeDialog,
			TypeCinematic = ::AudibleSoundClass::TypeCinematic
		};

		bool Play(bool addToPlaylist);

		bool Pause();

		bool Resume();

		bool Stop(bool removeFromPlaylist);

		void Seek(uint32 playPosition);

		void FadeOut(uint32 fadeTime);

		void FadeIn(uint32 fadeTime);

		void UpdateVolume();

		float GetPriority();

		float PeekPriority();

		void SetPriority(float priority);

		void SetPlayPosition(float playPosition);

		void ReSync(IAudibleSoundClass ^sound);

		void FreeConversion();

		void ConvertToFiltered();

		IntPtr AsConvertedFormat();

		float DetermineRealVolume();

		void InternalSetVolume(float volume);

		void UpdateFade();

		void FreeMilesHandle();

		void InitializeMilesHandle();

		void AllocateMilesHandle();

		ISoundBufferClass ^GetBuffer();

		ISoundBufferClass ^PeekBuffer();

		void SetBuffer(ISoundBufferClass ^buffer);

		void RestartLoop();

		void UpdatePlayPosition();

		void OnLoopEnd();

		property IntPtr AudibleSoundClassPointer
		{
			IntPtr get();
		}

		property unsigned long ClassID
		{
			unsigned long get();
		}

		property SoundType Type
		{
			SoundType get();
			void set(SoundType value);
		}

		property uint32 State
		{
			uint32 get();
		}

		property uint32 Timestamp
		{
			uint32 get();
		}

		property uint32 VirtualChannel
		{
			uint32 get();
			void set(uint32 value);
		}

		property String ^Filename
		{
			String ^get();
		}

		property bool IsPlaying
		{
			bool get();
		}

		property float Pan
		{
			float get();
			void set(float value);
		}

		property float Volume
		{
			float get();
			void set(float value);
		}

		property uint32 LoopCount
		{
			uint32 get();
			void set(uint32 value);
		}

		property uint32 LoopsLeft
		{
			uint32 get();
		}

		property float RuntimePriority
		{
			float get();
			void set(float value);
		}

		property uint32 PlaybackRate
		{
			uint32 get();
			void set(uint32 value);
		}

		property float PitchFactor
		{
			float get();
			void set(float value);
		}

		property uint32 Duration
		{
			uint32 get();
		}

		property uint32 PlayPosition
		{
			uint32 get();
			void set(uint32 value);
		}

		property float StartOffset
		{
			float get();
			void set(float value);
		}

		property bool IsDirty
		{
			bool get();
			void set(bool value);
		}

		property IAudibleSoundDefinitionClass ^Definition
		{
			IAudibleSoundDefinitionClass ^get();
			void set(IAudibleSoundDefinitionClass ^value);
		}

		property IntPtr MilesHandle
		{
			IntPtr get();
			void set(IntPtr value);
		}
	};

	public ref class AudibleSoundClass : public SoundSceneObjClass, public IAudibleSoundClass
	{
		public:
			AudibleSoundClass(IntPtr pointer);

			IAudibleSoundClass ^AsAudibleSoundClass() override;
			virtual bool Play(bool addToPlaylist) sealed;
			virtual bool Pause() sealed;
			virtual bool Resume() sealed;
			virtual bool Stop(bool removeFromPlaylist) sealed;
			virtual void Seek(uint32 playPosition) sealed;
			virtual void FadeOut(uint32 fadeTime) sealed;
			virtual void FadeIn(uint32 fadeTime) sealed;
			virtual void UpdateVolume() sealed;
			virtual float GetPriority() sealed;
			virtual float PeekPriority() sealed;
			virtual void SetPriority(float priority) sealed;
			virtual void SetPlayPosition(float playPosition) sealed;
			virtual void ReSync(IAudibleSoundClass ^sound) sealed;
			virtual void FreeConversion() sealed;
			virtual void ConvertToFiltered() sealed;
			virtual IntPtr AsConvertedFormat() sealed;
			virtual float DetermineRealVolume() sealed;
			virtual void InternalSetVolume(float volume) sealed;
			virtual void UpdateFade() sealed;
			virtual void FreeMilesHandle() sealed;
			virtual void InitializeMilesHandle() sealed;
			virtual void AllocateMilesHandle() sealed;
			virtual ISoundBufferClass ^GetBuffer() sealed;
			virtual ISoundBufferClass ^PeekBuffer() sealed;
			virtual void SetBuffer(ISoundBufferClass ^buffer) sealed;
			virtual void RestartLoop() sealed;
			virtual void UpdatePlayPosition() sealed;
			virtual void OnLoopEnd() sealed;

			property IntPtr AudibleSoundClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property unsigned long ClassID
			{
				virtual unsigned long get() sealed;
			}

			property IAudibleSoundClass::SoundType Type
			{
				virtual IAudibleSoundClass::SoundType get() sealed;
				virtual void set(IAudibleSoundClass::SoundType value) sealed;
			}

			property uint32 State
			{
				virtual uint32 get() sealed;

				protected:
					void set(uint32 value);
			}

			property uint32 Timestamp
			{
				virtual uint32 get() sealed;
			}

			property uint32 VirtualChannel
			{
				virtual uint32 get() sealed;
				virtual void set(uint32 value) sealed;
			}

			property String ^Filename
			{
				virtual String ^get() sealed;
			}

			property bool IsPlaying
			{
				virtual bool get() sealed;
			}

			property float Pan
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float Volume
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property uint32 LoopCount
			{
				virtual uint32 get() sealed;
				virtual void set(uint32 value) sealed;
			}

			property uint32 LoopsLeft
			{
				virtual uint32 get() sealed;
			}

			property float RuntimePriority
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property uint32 PlaybackRate
			{
				virtual uint32 get() sealed;
				virtual void set(uint32 value) sealed;
			}

			property float PitchFactor
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property uint32 Duration
			{
				virtual uint32 get() sealed;

				protected:
					void set(uint32 value);
			}

			property uint32 PlayPosition
			{
				virtual uint32 get() sealed;
				virtual void set(uint32 value) sealed;
			}

			property float StartOffset
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool IsDirty
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property IAudibleSoundDefinitionClass ^Definition
			{
				virtual IAudibleSoundDefinitionClass ^get() sealed;
				virtual void set(IAudibleSoundDefinitionClass ^value) sealed;
			}

			property IntPtr MilesHandle
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

		protected:
			property ::MultiListObjectClass *InternalMultiListObjectClassPointer
			{
				::MultiListObjectClass *get() override;
			}

			property ::RefCountClass *InternalRefCountClassPointer
			{
				::RefCountClass *get() override;
			}

			property ::SoundSceneObjClass *InternalSoundSceneObjClassPointer
			{
				::SoundSceneObjClass *get() override;
			}

			property ::AudibleSoundClass *InternalAudibleSoundClassPointer
			{
				virtual ::AudibleSoundClass *get();
			}

			property IntPtr Handle
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property uint32 Time
			{
				uint32 get();
				void set(uint32 value);
			}
			
			property IAudibleSoundClass::Fade _Fade // Naming it Fade causes an internal error in the compiler somehow... It can't handle the same names
			{
				IAudibleSoundClass::Fade get();
				void set(IAudibleSoundClass::Fade value);
			}
			
			property uint32 FadeRemainingTime
			{
				uint32 get();
				void set(uint32 value);
			}

			property uint32 FadeTime
			{
				uint32 get();
				void set(uint32 value);
			}

			property uint32 Channel
			{
				uint32 get();
				void set(uint32 value);
			}

			property ISoundBufferClass ^Buffer
			{
				ISoundBufferClass ^get();
				void set(ISoundBufferClass ^value);
			}

			property float Priority
			{
				float get();
				void set(float value);
			}

			property float RealVolume
			{
				float get();
				void set(float value);
			}

			property int32 RemainingLoops
			{
				int32 get();
				void set(int32 value);
			}

			property float StartPosition
			{
				float get();
				void set(float value);
			}

			property float Pitch
			{
				float get();
				void set(float value);
			}

			property Matrix3D ListenerTransform
			{
				Matrix3D get();
				void set(Matrix3D value);
			}

			property Matrix3D O260
			{
				Matrix3D get();
				void set(Matrix3D value);
			}

			property bool Culled
			{
				bool get();
				void set(bool value);
			}

			property IntPtr FilteredSound
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IntPtr LogicalSound
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}
	};
}