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
#include "MMuzzleRecoilClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <MuzzleRecoilClass.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "Imports.h"

namespace RenSharp
{
	MuzzleRecoilClass::MuzzleRecoilClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool MuzzleRecoilClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IMuzzleRecoilClass ^otherThis = dynamic_cast<IMuzzleRecoilClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return MuzzleRecoilClassPointer.Equals(otherThis->MuzzleRecoilClassPointer);
	}

	IntPtr MuzzleRecoilClass::MuzzleRecoilClassPointer::get()
	{
		return IntPtr(InternalMuzzleRecoilClassPointer);
	}

	bool MuzzleRecoilClass::IsRecoiling::get()
	{
		return InternalMuzzleRecoilClassPointer->Is_Recoiling();
	}

	bool MuzzleRecoilClass::InternalDestroyPointer()
	{
		Imports::DestroyMuzzleRecoilClass(InternalMuzzleRecoilClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::MuzzleRecoilClass *MuzzleRecoilClass::InternalMuzzleRecoilClassPointer::get()
	{
		return reinterpret_cast<::MuzzleRecoilClass *>(Pointer.ToPointer());
	}
}