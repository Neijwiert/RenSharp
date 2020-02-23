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
#include "MSaveLoadSubSystemClass.h"

#include "MChunkClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <SaveLoadSubSystemClass.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Text;

namespace RenSharp
{
	SaveLoadSubSystemClass::SaveLoadSubSystemClass(IntPtr pointer)
		: PostLoadableClass(pointer)
	{

	}

	String ^SaveLoadSubSystemClass::ToString()
	{
		StringBuilder ^builder = gcnew StringBuilder();
		builder->Append(Name);

		return builder->ToString();
	}

	bool SaveLoadSubSystemClass::Save(IChunkSaveClass ^cSave)
	{
		if (cSave == nullptr || cSave->ChunkSaveClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("cSave");
		}

		return InternalSaveLoadSubSystemClassPointer->Save(
			*reinterpret_cast<::ChunkSaveClass *>(cSave->ChunkSaveClassPointer.ToPointer()));
	}

	bool SaveLoadSubSystemClass::Load(IChunkLoadClass ^cLoad)
	{
		if (cLoad == nullptr || cLoad->ChunkLoadClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("cLoad");
		}

		return InternalSaveLoadSubSystemClassPointer->Load(
			*reinterpret_cast<::ChunkLoadClass *>(cLoad->ChunkLoadClassPointer.ToPointer()));
	}

	IntPtr SaveLoadSubSystemClass::SaveLoadSubSystemClassPointer::get()
	{
		return IntPtr(InternalSaveLoadSubSystemClassPointer);
	}

	ISaveLoadSubSystemClass ^SaveLoadSubSystemClass::NextSubSystem::get()
	{
		auto result = InternalSaveLoadSubSystemClassPointer->NextSubSystem;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SaveLoadSubSystemClass(IntPtr(result));
		}
	}

	void SaveLoadSubSystemClass::NextSubSystem::set(ISaveLoadSubSystemClass ^value)
	{
		if (value == nullptr || value->SaveLoadSubSystemClassPointer.ToPointer() == nullptr)
		{
			InternalSaveLoadSubSystemClassPointer->NextSubSystem = nullptr;
		}
		else
		{
			InternalSaveLoadSubSystemClassPointer->NextSubSystem = reinterpret_cast<::SaveLoadSubSystemClass *>(value->SaveLoadSubSystemClassPointer.ToPointer());
		}
	}

	uint32 SaveLoadSubSystemClass::ChunkID::get()
	{
		return InternalSaveLoadSubSystemClassPointer->Chunk_ID();
	}

	bool SaveLoadSubSystemClass::ContainsData::get()
	{
		return InternalSaveLoadSubSystemClassPointer->Contains_Data();
	}

	String ^SaveLoadSubSystemClass::Name::get()
	{
		auto result = InternalSaveLoadSubSystemClassPointer->Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	::PostLoadableClass *SaveLoadSubSystemClass::InternalPostLoadableClassPointer::get()
	{
		return InternalSaveLoadSubSystemClassPointer;
	}

	::SaveLoadSubSystemClass *SaveLoadSubSystemClass::InternalSaveLoadSubSystemClassPointer::get()
	{
		return reinterpret_cast<::SaveLoadSubSystemClass *>(Pointer.ToPointer());
	}
}