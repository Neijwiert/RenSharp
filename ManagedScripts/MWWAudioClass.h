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

#include "AbstractUnmanagedObject.h"
#include "IUnmanagedContainer.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <WWAudioClass.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Runtime::InteropServices;

namespace RenSharp
{
	interface class IFileFactoryClass;
	interface class IAudibleSoundClass;

	public enum class SoundClassID : int
	{
		ClassIDUnknown = ::CLASSID_UNKNOWN,
		ClassID2D = ::CLASSID_2D,
		ClassID3D = ::CLASSID_3D,
		ClassIDListener = ::CLASSID_LISTENER,
		ClassIDPseudo3D = ::CLASSID_PSEUDO3D,
		ClassID2DTrigger = ::CLASSID_2DTRIGGER,
		ClassIDLogical = ::CLASSID_LOGICAL,
		ClassIDFiltered = ::CLASSID_FILTERED
	};

	public enum class CacheHash : int
	{
		MaxCacheHash = ::MAX_CACHE_HASH,
		CacheHashMask = ::CACHE_HASH_MASK
	};

	public interface class IDriverInfoStruct : IUnmanagedObject 
	{
		property IntPtr DriverInfoStructPointer
		{
			IntPtr get();
		}

		property unsigned int Driver
		{
			unsigned int get();
			void set(unsigned int value);
		}

		property String ^Name
		{
			String ^get();
		}
	};

	public ref class DriverInfoStruct : public AbstractUnmanagedObject, public IDriverInfoStruct
	{
		private:
			DriverInfoStruct();

		public:
			DriverInfoStruct(IntPtr pointer);

			String ^ToString() override;
			bool Equals(Object ^other) override;

			static IUnmanagedContainer<IDriverInfoStruct ^> ^CreateDriverInfoStruct();

			property IntPtr DriverInfoStructPointer
			{
				virtual IntPtr get() sealed;
			}

			property unsigned int Driver
			{
				virtual unsigned int get() sealed;
				virtual void set(unsigned int value) sealed;
			}

			property String ^Name
			{
				virtual String ^get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::WWAudioClass::DRIVER_INFO_STRUCT *InternalDriverInfoStructPointer
			{
				virtual ::WWAudioClass::DRIVER_INFO_STRUCT *get();
			}
	};

	public interface class IWWAudioClass : public IUnmanagedObject
	{
		enum class DriverType2D : int
		{
			Driver2DError = ::WWAudioClass::DRIVER2D_ERROR,
			Driver2DDSound = ::WWAudioClass::DRIVER2D_DSOUND,
			Driver2DWaveOut = ::WWAudioClass::DRIVER2D_WAVEOUT
		};

		enum class DriverType3D : int
		{
			Driver3DError = ::WWAudioClass::DRIVER3D_ERROR,
			Driver3DD3DSound = ::WWAudioClass::DRIVER3D_D3DSOUND,
			Driver3DEAX = ::WWAudioClass::DRIVER3D_EAX,
			Driver3DA3D = ::WWAudioClass::DRIVER3D_A3D,
			Driver3DRSX = ::WWAudioClass::DRIVER3D_RSX,
			Driver3DPSEUDO = ::WWAudioClass::DRIVER3D_PSEUDO,
			Driver3DDolby = ::WWAudioClass::DRIVER3D_DOLBY
		};

		enum class SoundPage : int
		{
			PagePrimary = ::WWAudioClass::PAGE_PRIMARY,
			PageSecondary = ::WWAudioClass::PAGE_SECONDARY,
			PageTertiary = ::WWAudioClass::PAGE_TERTIARY
		};

		bool Get3DDevice(int index, [Out] IDriverInfoStruct ^%info);

		void SetFileFactory(IFileFactoryClass ^factory);

		IAudibleSoundClass ^PeekBackgroundMusic();

		void SetMax2DSoundBuffer(int bytes);

		void SetMax2DSoundBuffer();

		void SetMax3DSoundBuffer(int bytes);

		void SetMax3DSoundBuffer();

		IAudibleSoundClass ^PeekPlaylistEntry(int index);

		void SetNonDialogFadeTime(float fadeTime);

		property IntPtr WWAudioClassPointer
		{
			IntPtr get();
		}

		property IntPtr Driver2D
		{
			IntPtr get();
		}

		property unsigned int Driver3D
		{
			unsigned int get();
		}

		property String ^Driver3DName
		{
			String ^get();
		}

		property unsigned int ReverbFilter
		{
			unsigned int get();
		}

		property int PlaybackRate
		{
			int get();
		}

		property int PlaybackBits
		{
			int get();
		}

		property bool PlaybackStereo
		{
			bool get();
		}

		property int Device3DCount
		{
			int get();
		}

		property float EffectsLevel
		{
			float get();
		}

		property int ReverbRoomType
		{
			int get();
		}

		property float SoundEffectsVolume
		{
			float get();
		}

		property float MusicVolume
		{
			float get();
		}

		property float DialogVolume
		{
			float get();
		}

		property float CinematicVolume
		{
			float get();
		}

		property bool AreSoundEffectsOn
		{
			bool get();
		}

		property bool IsMusicOn
		{
			bool get();
		}

		property bool IsDialogOn
		{
			bool get();
		}

		property bool IsCinematicSoundOn
		{
			bool get();
		}

		property bool AreNewSoundsEnabled
		{
			bool get();
			void set(bool value);
		}

		property String ^BackgroundMusicName
		{
			String ^get();
		}

		property int LogicalTypeCount
		{
			int get();
		}

		property IntPtr SoundScene
		{
			IntPtr get();
		}

		property int CacheSize
		{
			int get();
		}

		property int CurrentCacheSize
		{
			int get();
		}

		property int PlaylistCount
		{
			int get();
		}

		property int Sample2DCount
		{
			int get();
		}

		property int Sample3DCount
		{
			int get();
		}
	};

	public ref class WWAudioClass : public AbstractUnmanagedObject, public IWWAudioClass
	{
		public:
			WWAudioClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual bool Get3DDevice(int index, [Out] IDriverInfoStruct ^%info) sealed;
			virtual void SetFileFactory(IFileFactoryClass ^factory) sealed;
			virtual IAudibleSoundClass ^PeekBackgroundMusic() sealed;
			virtual void SetMax2DSoundBuffer(int bytes) sealed;
			virtual void SetMax2DSoundBuffer() sealed;
			virtual void SetMax3DSoundBuffer(int bytes) sealed;
			virtual void SetMax3DSoundBuffer() sealed;
			virtual IAudibleSoundClass ^PeekPlaylistEntry(int index) sealed;
			virtual void SetNonDialogFadeTime(float fadeTime) sealed;

			property IntPtr WWAudioClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr Driver2D
			{
				virtual IntPtr get() sealed;
			}

			property unsigned int Driver3D
			{
				virtual unsigned int get() sealed;
			}

			property String ^Driver3DName
			{
				virtual String ^get() sealed;
			}

			property unsigned int ReverbFilter
			{
				virtual unsigned int get() sealed;
			}

			property int PlaybackRate
			{
				virtual int get() sealed;
			}

			property int PlaybackBits
			{
				virtual int get() sealed;
			}

			property bool PlaybackStereo
			{
				virtual bool get() sealed;
			}

			property int Device3DCount
			{
				virtual int get() sealed;
			}

			property float EffectsLevel
			{
				virtual float get() sealed;
			}

			property int ReverbRoomType
			{
				virtual int get() sealed;
			}

			property float SoundEffectsVolume
			{
				virtual float get() sealed;
			}

			property float MusicVolume
			{
				virtual float get() sealed;
			}

			property float DialogVolume
			{
				virtual float get() sealed;
			}

			property float CinematicVolume
			{
				virtual float get() sealed;
			}

			property bool AreSoundEffectsOn
			{
				virtual bool get() sealed;
			}

			property bool IsMusicOn
			{
				virtual bool get() sealed;
			}

			property bool IsDialogOn
			{
				virtual bool get() sealed;
			}

			property bool IsCinematicSoundOn
			{
				virtual bool get() sealed;
			}

			property bool AreNewSoundsEnabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property String ^BackgroundMusicName
			{
				virtual String ^get() sealed;
			}

			property int LogicalTypeCount
			{
				virtual int get() sealed;
			}

			property IntPtr SoundScene
			{
				virtual IntPtr get() sealed;
			}

			property int CacheSize
			{
				virtual int get() sealed;
			}

			property int CurrentCacheSize
			{
				virtual int get() sealed;
			}

			property int PlaylistCount
			{
				virtual int get() sealed;
			}

			property int Sample2DCount
			{
				virtual int get() sealed;
			}

			property int Sample3DCount
			{
				virtual int get() sealed;
			}

			static property int Def2DSampleCount
			{
				int get();
			}

			static property int Def3DSampleCount
			{
				int get();
			}

			static property float DefMusicVol
			{
				float get();
			}

			static property float DefSFXVol
			{
				float get();
			}

			static property float DefDialogVol
			{
				float get();
			}

			static property float DefCinematicVol
			{
				float get();
			}

			static property float DefFadeTime
			{
				float get();
			}

			static property int DefCacheSize
			{
				int get();
			}

			static property int DefMax2DBufferSize
			{
				int get();
			}

			static property int DefMax3DBufferSize
			{
				int get();
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::WWAudioClass *InternalWWAudioClassPointer
			{
				virtual ::WWAudioClass *get();
			}
	};
}