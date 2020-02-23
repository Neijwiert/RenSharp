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
#include "MAudibleSoundDefinitionClass.h"

#include "UnmanagedContainer.h"
#include "MVector3.h"
#include "MAudibleSoundClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <AudibleSoundDefinitionClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	AudibleSoundDefinitionClass::AudibleSoundDefinitionClass(IntPtr pointer)
		: DefinitionClass(pointer)
	{

	}

	IUnmanagedContainer<IAudibleSoundClass ^> ^AudibleSoundDefinitionClass::CreateSound(int type)
	{
		auto result = InternalAudibleSoundDefinitionClassPointer->Create_Sound(type);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew UnmanagedContainer<IAudibleSoundClass ^>(gcnew AudibleSoundClass(IntPtr(result)));
		}
	}

	void AudibleSoundDefinitionClass::InitializeFromSound(IAudibleSoundClass ^sound)
	{
		if (sound == nullptr || sound->AudibleSoundClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("sound");
		}

		InternalAudibleSoundDefinitionClassPointer->Initialize_From_Sound(
			reinterpret_cast<::AudibleSoundClass *>(sound->AudibleSoundClassPointer.ToPointer()));
	}

	IntPtr AudibleSoundDefinitionClass::CreateLogical()
	{
		return IntPtr(InternalAudibleSoundDefinitionClassPointer->Create_Logical());
	}

	IntPtr AudibleSoundDefinitionClass::AudibleSoundDefinitionClassPointer::get()
	{
		return IntPtr(InternalAudibleSoundDefinitionClassPointer);
	}

	String ^AudibleSoundDefinitionClass::Filename::get()
	{
		return gcnew String(InternalAudibleSoundDefinitionClassPointer->Get_Filename().Peek_Buffer());
	}

	String ^AudibleSoundDefinitionClass::DisplayText::get()
	{
		return gcnew String(InternalAudibleSoundDefinitionClassPointer->Get_Display_Text().Peek_Buffer());
	}

	float AudibleSoundDefinitionClass::MaxVolRadius::get()
	{
		return InternalAudibleSoundDefinitionClassPointer->Get_Max_Vol_Radius();
	}

	void AudibleSoundDefinitionClass::MaxVolRadius::set(float value)
	{
		InternalAudibleSoundDefinitionClassPointer->Set_Max_Vol_Radius(value);
	}

	float AudibleSoundDefinitionClass::DropOffRadius::get()
	{
		return InternalAudibleSoundDefinitionClassPointer->Get_DropOff_Radius();
	}

	void AudibleSoundDefinitionClass::DropOffRadius::set(float value)
	{
		InternalAudibleSoundDefinitionClassPointer->Set_DropOff_Radius(value);
	}

	Vector3 AudibleSoundDefinitionClass::SphereColor::get()
	{
		Vector3 result;

		Vector3::UnmanagedToManagedVector3(InternalAudibleSoundDefinitionClassPointer->Get_Sphere_Color(), result);

		return result;
	}

	float AudibleSoundDefinitionClass::Volume::get()
	{
		return InternalAudibleSoundDefinitionClassPointer->Get_Volume();
	}

	void AudibleSoundDefinitionClass::Volume::set(float value)
	{
		InternalAudibleSoundDefinitionClassPointer->Set_Volume(value);
	}

	float AudibleSoundDefinitionClass::VolumeRandomizer::get()
	{
		return InternalAudibleSoundDefinitionClassPointer->Get_Volume_Randomizer();
	}

	void AudibleSoundDefinitionClass::VolumeRandomizer::set(float value)
	{
		InternalAudibleSoundDefinitionClassPointer->Set_Volume_Randomizer(value);
	}

	float AudibleSoundDefinitionClass::StartOffset::get()
	{
		return InternalAudibleSoundDefinitionClassPointer->Get_Start_Offset();
	}

	void AudibleSoundDefinitionClass::StartOffset::set(float value)
	{
		InternalAudibleSoundDefinitionClassPointer->Set_Start_Offset(value);
	}

	float AudibleSoundDefinitionClass::PitchFactor::get()
	{
		return InternalAudibleSoundDefinitionClassPointer->Get_Pitch_Factor();
	}

	void AudibleSoundDefinitionClass::PitchFactor::set(float value)
	{
		InternalAudibleSoundDefinitionClassPointer->Set_Pitch_Factor(value);
	}

	float AudibleSoundDefinitionClass::PitchFactorRandomizer::get()
	{
		return InternalAudibleSoundDefinitionClassPointer->Get_Pitch_Factor_Randomizer();
	}

	void AudibleSoundDefinitionClass::PitchFactorRandomizer::set(float value)
	{
		InternalAudibleSoundDefinitionClassPointer->Set_Pitch_Factor_Randomizer(value);
	}

	int AudibleSoundDefinitionClass::VirtualChannel::get()
	{
		return InternalAudibleSoundDefinitionClassPointer->Get_Virtual_Channel();
	}

	void AudibleSoundDefinitionClass::VirtualChannel::set(int value)
	{
		InternalAudibleSoundDefinitionClassPointer->Set_Virtual_Channel(value);
	}

	float AudibleSoundDefinitionClass::LogicalDropoffRadius::get()
	{
		return InternalAudibleSoundDefinitionClassPointer->Get_Logical_DropOff_Radius();
	}

	int AudibleSoundDefinitionClass::LogicalType::get()
	{
		return InternalAudibleSoundDefinitionClassPointer->Get_Logical_Type();
	}

	::DefinitionClass *AudibleSoundDefinitionClass::InternalDefinitionClassPointer::get()
	{
		return InternalAudibleSoundDefinitionClassPointer;
	}

	::AudibleSoundDefinitionClass *AudibleSoundDefinitionClass::InternalAudibleSoundDefinitionClassPointer::get()
	{
		return reinterpret_cast<::AudibleSoundDefinitionClass *>(Pointer.ToPointer());
	}
}