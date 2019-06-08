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
#include "MPersist.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <Persist.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MChunkClass.h"
#include "MPersistFactoryClass.h"

namespace RenSharp
{
	PersistClass::PersistClass(IntPtr pointer)
		: PostLoadableClass(pointer)
	{

	}

	bool PersistClass::Save(IChunkSaveClass ^csave)
	{
		if (csave == nullptr || csave->ChunkSaveClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("csave");
		}

		return InternalPersistClassPointer->Save(*reinterpret_cast<::ChunkSaveClass *>(csave->ChunkSaveClassPointer.ToPointer()));
	}

	bool PersistClass::Load(IChunkLoadClass ^cload)
	{
		if (cload == nullptr || cload->ChunkLoadClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("cload");
		}

		return InternalPersistClassPointer->Load(*reinterpret_cast<::ChunkLoadClass *>(cload->ChunkLoadClassPointer.ToPointer()));
	}

	IntPtr PersistClass::PersistClassPointer::get()
	{
		return IntPtr(InternalPersistClassPointer);
	}

	IPersistFactoryClass ^PersistClass::Factory::get()
	{
		auto result = const_cast<::PersistFactoryClass *>(&InternalPersistClassPointer->Get_Factory());
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PersistFactoryClass(IntPtr(result));
		}
	}

	::PostLoadableClass *PersistClass::InternalPostLoadableClassPointer::get()
	{
		return InternalPersistClassPointer;
	}

	::PersistClass *PersistClass::InternalPersistClassPointer::get()
	{
		return reinterpret_cast<::PersistClass *>(Pointer.ToPointer());
	}
}