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
#include "MPersistFactoryClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <PersistFactoryClass.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MChunkClass.h"
#include "MPersist.h"
#include "Imports.h"

namespace RenSharp
{
	PersistFactoryClass::PersistFactoryClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool PersistFactoryClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IPersistFactoryClass ^otherThis = dynamic_cast<IPersistFactoryClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return PersistFactoryClassPointer.Equals(otherThis->PersistFactoryClassPointer);
	}

	IPersistClass ^PersistFactoryClass::Load(IChunkLoadClass ^xLoad)
	{
		if (xLoad == nullptr || xLoad->ChunkLoadClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("xLoad");
		}

		auto result = InternalPersistFactoryClassPointer->Load(*reinterpret_cast<::ChunkLoadClass *>(xLoad->ChunkLoadClassPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PersistClass(IntPtr(result));
		}
	}

	void PersistFactoryClass::Save(IChunkSaveClass ^xSave, IPersistClass ^object)
	{
		if (xSave == nullptr || xSave->ChunkSaveClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("xSave");
		}
		else if (object == nullptr || object->PersistClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalPersistFactoryClassPointer->Save(
			*reinterpret_cast<::ChunkSaveClass *>(xSave->ChunkSaveClassPointer.ToPointer()),
			reinterpret_cast<::PersistClass *>(object->PersistClassPointer.ToPointer()));
	}

	IntPtr PersistFactoryClass::PersistFactoryClassPointer::get()
	{
		return IntPtr(InternalPersistFactoryClassPointer);
	}

	IPersistFactoryClass ^PersistFactoryClass::NextFactory::get()
	{
		auto result = InternalPersistFactoryClassPointer->NextFactory;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PersistFactoryClass(IntPtr(result));
		}
	}

	void PersistFactoryClass::NextFactory::set(IPersistFactoryClass ^value)
	{
		if (value == nullptr || value->PersistFactoryClassPointer.ToPointer() == nullptr)
		{
			InternalPersistFactoryClassPointer->NextFactory = nullptr;
		}
		else
		{
			InternalPersistFactoryClassPointer->NextFactory = reinterpret_cast<::PersistFactoryClass *>(value->PersistFactoryClassPointer.ToPointer());
		}
	}

	uint32 PersistFactoryClass::ChunkID::get()
	{
		return InternalPersistFactoryClassPointer->Chunk_ID();
	}

	bool PersistFactoryClass::InternalDestroyPointer()
	{
		Imports::DestroyPersistFactoryClass(InternalPersistFactoryClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::PersistFactoryClass *PersistFactoryClass::InternalPersistFactoryClassPointer::get()
	{
		return reinterpret_cast<::PersistFactoryClass *>(Pointer.ToPointer());
	}
}