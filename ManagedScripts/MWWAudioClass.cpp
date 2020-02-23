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
#include "MWWAudioClass.h"

#include "Imports.h"
#include "Mengine_io.h"
#include "MAudibleSoundClass.h"
#include "UnmanagedContainer.h"

using namespace System::Text;

namespace RenSharp
{
	DriverInfoStruct::DriverInfoStruct()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateDriverInfoStruct()))
	{

	}

	DriverInfoStruct::DriverInfoStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	String ^DriverInfoStruct::ToString()
	{
		StringBuilder ^builder = gcnew StringBuilder();
		builder->Append(Name);

		return builder->ToString();
	}

	bool DriverInfoStruct::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDriverInfoStruct ^otherThis = dynamic_cast<IDriverInfoStruct ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DriverInfoStructPointer.Equals(otherThis->DriverInfoStructPointer);
	}

	IUnmanagedContainer<IDriverInfoStruct ^> ^DriverInfoStruct::CreateDriverInfoStruct()
	{
		return gcnew UnmanagedContainer<IDriverInfoStruct ^>(gcnew DriverInfoStruct());
	}

	IntPtr DriverInfoStruct::DriverInfoStructPointer::get()
	{
		return IntPtr(InternalDriverInfoStructPointer);
	}

	unsigned int DriverInfoStruct::Driver::get()
	{
		return InternalDriverInfoStructPointer->driver;
	}

	void DriverInfoStruct::Driver::set(unsigned int value)
	{
		InternalDriverInfoStructPointer->driver = value;
	}

	String ^DriverInfoStruct::Name::get()
	{
		auto result = InternalDriverInfoStructPointer->name;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	bool DriverInfoStruct::InternalDestroyPointer()
	{
		Imports::DestroyDriverInfoStruct(InternalDriverInfoStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::WWAudioClass::DRIVER_INFO_STRUCT *DriverInfoStruct::InternalDriverInfoStructPointer::get()
	{
		return reinterpret_cast<::WWAudioClass::DRIVER_INFO_STRUCT *>(Pointer.ToPointer());
	}

	WWAudioClass::WWAudioClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool WWAudioClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IWWAudioClass ^otherThis = dynamic_cast<IWWAudioClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return WWAudioClassPointer.Equals(otherThis->WWAudioClassPointer);
	}

	bool WWAudioClass::Get3DDevice(int index, [Out] IDriverInfoStruct ^%info)
	{
		if (index < 0 || index >= InternalWWAudioClassPointer->Get_3D_Device_Count())
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		info = nullptr;

		::WWAudioClass::DRIVER_INFO_STRUCT *tmpInfo;

		if (InternalWWAudioClassPointer->Get_3D_Device(index, &tmpInfo))
		{
			if (tmpInfo != nullptr)
			{
				info = gcnew DriverInfoStruct(IntPtr(tmpInfo));
			}

			return true;
		}
		else
		{
			return false;
		}
	}

	void WWAudioClass::SetFileFactory(IFileFactoryClass ^factory)
	{
		if (factory == nullptr || factory->FileFactoryClassPointer.ToPointer() == nullptr)
		{
			InternalWWAudioClassPointer->Set_File_Factory(nullptr);
		}
		else
		{
			InternalWWAudioClassPointer->Set_File_Factory(
				reinterpret_cast<::FileFactoryClass *>(factory->FileFactoryClassPointer.ToPointer()));
		}
	}

	IAudibleSoundClass ^WWAudioClass::PeekBackgroundMusic()
	{
		auto result = InternalWWAudioClassPointer->Peek_Background_Music();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew AudibleSoundClass(IntPtr(result));
		}
	}

	void WWAudioClass::SetMax2DSoundBuffer(int bytes)
	{
		InternalWWAudioClassPointer->Set_Max_2D_Sound_Buffer(bytes);
	}

	void WWAudioClass::SetMax2DSoundBuffer()
	{
		InternalWWAudioClassPointer->Set_Max_2D_Sound_Buffer();
	}

	void WWAudioClass::SetMax3DSoundBuffer(int bytes)
	{
		InternalWWAudioClassPointer->Set_Max_3D_Sound_Buffer(bytes);
	}

	void WWAudioClass::SetMax3DSoundBuffer()
	{
		InternalWWAudioClassPointer->Set_Max_3D_Sound_Buffer();
	}

	IAudibleSoundClass ^WWAudioClass::PeekPlaylistEntry(int index)
	{
		if (index < 0 || index >= InternalWWAudioClassPointer->Get_Playlist_Count())
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalWWAudioClassPointer->Peek_Playlist_Entry(index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew AudibleSoundClass(IntPtr(result));
		}
	}

	void WWAudioClass::SetNonDialogFadeTime(float fadeTime)
	{
		InternalWWAudioClassPointer->Set_Non_Dialog_Fade_Time(fadeTime);
	}

	IntPtr WWAudioClass::WWAudioClassPointer::get()
	{
		return IntPtr(InternalWWAudioClassPointer);
	}

	IntPtr WWAudioClass::Driver2D::get()
	{
		return IntPtr(InternalWWAudioClassPointer->Get_2D_Driver());
	}

	unsigned int WWAudioClass::Driver3D::get()
	{
		return InternalWWAudioClassPointer->Get_3D_Driver();
	}

	String ^WWAudioClass::Driver3DName::get()
	{
		return gcnew String(InternalWWAudioClassPointer->Get_3D_Driver_Name().Peek_Buffer());
	}

	unsigned int WWAudioClass::ReverbFilter::get()
	{
		return InternalWWAudioClassPointer->Get_Reverb_Filter();
	}

	int WWAudioClass::PlaybackRate::get()
	{
		return InternalWWAudioClassPointer->Get_Playback_Rate();
	}

	int WWAudioClass::PlaybackBits::get()
	{
		return InternalWWAudioClassPointer->Get_Playback_Bits();
	}

	bool WWAudioClass::PlaybackStereo::get()
	{
		return InternalWWAudioClassPointer->Get_Playback_Stereo();
	}

	int WWAudioClass::Device3DCount::get()
	{
		return InternalWWAudioClassPointer->Get_3D_Device_Count();
	}

	float WWAudioClass::EffectsLevel::get()
	{
		return InternalWWAudioClassPointer->Get_Effects_Level();
	}

	int WWAudioClass::ReverbRoomType::get()
	{
		return InternalWWAudioClassPointer->Get_Reverb_Room_Type();
	}

	float WWAudioClass::SoundEffectsVolume::get()
	{
		return InternalWWAudioClassPointer->Get_Sound_Effects_Volume();
	}

	float WWAudioClass::MusicVolume::get()
	{
		return InternalWWAudioClassPointer->Get_Music_Volume();
	}

	float WWAudioClass::DialogVolume::get()
	{
		return InternalWWAudioClassPointer->Get_Dialog_Volume();
	}

	float WWAudioClass::CinematicVolume::get()
	{
		return InternalWWAudioClassPointer->Get_Cinematic_Volume();
	}

	bool WWAudioClass::AreSoundEffectsOn::get()
	{
		return InternalWWAudioClassPointer->Are_Sound_Effects_On();
	}

	bool WWAudioClass::IsMusicOn::get()
	{
		return InternalWWAudioClassPointer->Is_Music_On();
	}

	bool WWAudioClass::IsDialogOn::get()
	{
		return InternalWWAudioClassPointer->Is_Dialog_On();
	}

	bool WWAudioClass::IsCinematicSoundOn::get()
	{
		return InternalWWAudioClassPointer->Is_Cinematic_Sound_On();
	}

	bool WWAudioClass::AreNewSoundsEnabled::get()
	{
		return InternalWWAudioClassPointer->Are_New_Sounds_Enabled();
	}

	void WWAudioClass::AreNewSoundsEnabled::set(bool value)
	{
		InternalWWAudioClassPointer->Enable_New_Sounds(value);
	}

	String ^WWAudioClass::BackgroundMusicName::get()
	{
		auto result = InternalWWAudioClassPointer->Get_Background_Music_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	int WWAudioClass::LogicalTypeCount::get()
	{
		return InternalWWAudioClassPointer->Get_Logical_Type_Count();
	}

	IntPtr WWAudioClass::SoundScene::get()
	{
		return IntPtr(InternalWWAudioClassPointer->Get_Sound_Scene());
	}

	int WWAudioClass::CacheSize::get()
	{
		return InternalWWAudioClassPointer->Get_Cache_Size();
	}

	int WWAudioClass::CurrentCacheSize::get()
	{
		return InternalWWAudioClassPointer->Get_Current_Cache_Size();
	}

	int WWAudioClass::PlaylistCount::get()
	{
		return InternalWWAudioClassPointer->Get_Playlist_Count();
	}

	int WWAudioClass::Sample2DCount::get()
	{
		return InternalWWAudioClassPointer->Get_2D_Sample_Count();
	}

	int WWAudioClass::Sample3DCount::get()
	{
		return InternalWWAudioClassPointer->Get_3D_Sample_Count();
	}

	int WWAudioClass::Def2DSampleCount::get()
	{
		return ::DEF_2D_SAMPLE_COUNT;
	}

	int WWAudioClass::Def3DSampleCount::get()
	{
		return ::DEF_3D_SAMPLE_COUNT;
	}

	float WWAudioClass::DefMusicVol::get()
	{
		return ::DEF_MUSIC_VOL;
	}

	float WWAudioClass::DefSFXVol::get()
	{
		return ::DEF_SFX_VOL;
	}

	float WWAudioClass::DefDialogVol::get()
	{
		return ::DEF_DIALOG_VOL;
	}

	float WWAudioClass::DefCinematicVol::get()
	{
		return ::DEF_CINEMATIC_VOL;
	}

	float WWAudioClass::DefFadeTime::get()
	{
		return ::DEF_FADE_TIME;
	}

	int WWAudioClass::DefCacheSize::get()
	{
		return ::DEF_CACHE_SIZE;
	}

	int WWAudioClass::DefMax2DBufferSize::get()
	{
		return ::DEF_MAX_2D_BUFFER_SIZE;
	}

	int WWAudioClass::DefMax3DBufferSize::get()
	{
		return ::DEF_MAX_3D_BUFFER_SIZE;
	}

	bool WWAudioClass::InternalDestroyPointer()
	{
		Imports::DestroyWWAudioClass(InternalWWAudioClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::WWAudioClass *WWAudioClass::InternalWWAudioClassPointer::get()
	{
		return reinterpret_cast<::WWAudioClass *>(Pointer.ToPointer());
	}
}