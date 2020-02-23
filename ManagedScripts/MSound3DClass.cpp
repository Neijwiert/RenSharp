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
#include "MSound3DClass.h"

#include "MVector3.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <Sound3DClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	Sound3DClass::Sound3DClass(IntPtr pointer)
		: AudibleSoundClass(pointer)
	{

	}

	ISound3DClass ^Sound3DClass::AsSound3DClass()
	{
		return this;
	}

	IntPtr Sound3DClass::Sound3DClassPointer::get()
	{
		return IntPtr(InternalSound3DClassPointer);
	}

	bool Sound3DClass::IsTransformValid::get()
	{
		return InternalSound3DClassPointer->IsTransformValid;
	}

	void Sound3DClass::IsTransformValid::set(bool value)
	{
		InternalSound3DClassPointer->IsTransformValid = value;
	}

	bool Sound3DClass::IsAutoCalcVelocity::get()
	{
		return InternalSound3DClassPointer->IsAutoCalcVelocity;
	}

	void Sound3DClass::IsAutoCalcVelocity::set(bool value)
	{
		InternalSound3DClassPointer->IsAutoCalcVelocity = value;
	}

	Vector3 Sound3DClass::Velocity::get()
	{
		Vector3 result;

		Vector3::UnmanagedToManagedVector3(InternalSound3DClassPointer->Velocity, result);

		return result;
	}

	void Sound3DClass::Velocity::set(Vector3 value)
	{
		Vector3::ManagedToUnmanagedVector3(value, InternalSound3DClassPointer->Velocity);
	}

	float Sound3DClass::MaxVolRadius::get()
	{
		return InternalSound3DClassPointer->MaxVolRadius;
	}

	void Sound3DClass::MaxVolRadius::set(float value)
	{
		InternalSound3DClassPointer->MaxVolRadius = value;
	}

	bool Sound3DClass::IsStatic::get()
	{
		return InternalSound3DClassPointer->IsStatic;
	}

	void Sound3DClass::IsStatic::set(bool value)
	{
		InternalSound3DClassPointer->IsStatic = value;
	}

	uint32 Sound3DClass::Time::get()
	{
		return InternalSound3DClassPointer->Time;
	}

	void Sound3DClass::Time::set(uint32 value)
	{
		InternalSound3DClassPointer->Time = value;
	}

	::AudibleSoundClass *Sound3DClass::InternalAudibleSoundClassPointer::get()
	{
		return InternalSound3DClassPointer;
	}

	::Sound3DClass *Sound3DClass::InternalSound3DClassPointer::get()
	{
		return reinterpret_cast<::Sound3DClass *>(Pointer.ToPointer());
	}
}