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
#include "MSoundBufferClass.h"

#include "Imports.h"
#include "Mengine_io.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <SoundBufferClass.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Text;

namespace RenSharp
{
	SoundBufferClass::SoundBufferClass(IntPtr pointer)
		: RefCountClass(pointer)
	{

	}

	String ^SoundBufferClass::ToString()
	{
		StringBuilder ^builder = gcnew StringBuilder();
		builder->Append(File);

		return builder->ToString();
	}

	bool SoundBufferClass::LoadFromFile(String ^file)
	{
		if (file == nullptr)
		{
			throw gcnew ArgumentNullException("file");
		}

		IntPtr fileHandle = Marshal::StringToHGlobalAnsi(file);
		try
		{
			return InternalSoundBufferClassPointer->Load_From_File(
				reinterpret_cast<char *>(fileHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(fileHandle);
		}
	}

	bool SoundBufferClass::LoadFromFile(IFileClass ^file)
	{
		if (file == nullptr || file->FileClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("file");
		}

		return InternalSoundBufferClassPointer->Load_From_File(
			*reinterpret_cast<::FileClass *>(file->FileClassPointer.ToPointer()));
	}

	bool SoundBufferClass::LoadFromMemory(array<std::uint8_t> ^buffer)
	{
		if (buffer == nullptr)
		{
			throw gcnew ArgumentNullException("buffer");
		}

		pin_ptr<std::uint8_t> pinnedBuffer = &buffer[0];
		std::uint8_t *bufferPtr = pinnedBuffer;

		char *unmanagedBuffer = Imports::CreateAnsiString(buffer->Length);
		try
		{
			// Is this copied over?
			std::memcpy(unmanagedBuffer, bufferPtr, buffer->Length);

			return InternalSoundBufferClassPointer->Load_From_Memory(unmanagedBuffer, buffer->Length);
		}
		catch (Exception ^)
		{
			Imports::DestroyAnsiString(unmanagedBuffer);
			unmanagedBuffer = nullptr;
			
			throw;
		}
	}

	void SoundBufferClass::FreeBuffer()
	{
		InternalSoundBufferClassPointer->Free_Buffer();
	}

	void SoundBufferClass::DetermineStats(IntPtr stats)
	{
		// What is correct implementation?
		InternalSoundBufferClassPointer->Determine_Stats(
			reinterpret_cast<char *>(stats.ToPointer()));
	}

	IntPtr SoundBufferClass::SoundBufferClassPointer::get()
	{
		return IntPtr(InternalSoundBufferClassPointer);
	}

	array<std::uint8_t> ^SoundBufferClass::Buffer::get()
	{
		char *buffer = InternalSoundBufferClassPointer->cBuffer;
		if (buffer == nullptr)
		{
			return nullptr;
		}

		array<std::uint8_t> ^result = gcnew array<std::uint8_t>(InternalSoundBufferClassPointer->uLength);
		pin_ptr<std::uint8_t> pinnedBuffer = &result[0];
		std::uint8_t *bufferPtr = pinnedBuffer;

		std::memcpy(bufferPtr, buffer, result->Length);

		return result;
	}

	void SoundBufferClass::Buffer::set(array<std::uint8_t> ^value)
	{
		Imports::DestroyAnsiString(InternalSoundBufferClassPointer->cBuffer);
		InternalSoundBufferClassPointer->cBuffer = nullptr;

		if (value != nullptr)
		{
			pin_ptr<std::uint8_t> pinnedBuffer = &value[0];
			std::uint8_t *bufferPtr = pinnedBuffer;

			InternalSoundBufferClassPointer->cBuffer = Imports::CreateAnsiString(value->Length);
			std::memcpy(InternalSoundBufferClassPointer->cBuffer, bufferPtr, value->Length);
		}
	}

	uint32 SoundBufferClass::Length::get()
	{
		return InternalSoundBufferClassPointer->uLength;
	}

	void SoundBufferClass::Length::set(uint32 value)
	{
		InternalSoundBufferClassPointer->uLength = value;
	}

	String ^SoundBufferClass::File::get()
	{
		auto result = InternalSoundBufferClassPointer->cFile;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	void SoundBufferClass::File::set(String ^value)
	{
		Imports::FreeAnsiString(InternalSoundBufferClassPointer->cFile);
		InternalSoundBufferClassPointer->cFile = nullptr;

		if (value != nullptr)
		{
			IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
			try
			{
				char *valuePtr = reinterpret_cast<char *>(valueHandle.ToPointer());
				std::size_t length = std::strlen(valuePtr);

				InternalSoundBufferClassPointer->cFile = Imports::MallocAnsiString(length);
				std::memcpy(InternalSoundBufferClassPointer->cFile, valuePtr, (length + 1) * sizeof(char));
			}
			finally
			{
				Marshal::FreeHGlobal(valueHandle);
			}
		}
	}

	uint32 SoundBufferClass::Duration::get()
	{
		return InternalSoundBufferClassPointer->uDuration;
	}

	void SoundBufferClass::Duration::set(uint32 value)
	{
		InternalSoundBufferClassPointer->uDuration = value;
	}

	uint32 SoundBufferClass::Rate::get()
	{
		return InternalSoundBufferClassPointer->uRate;
	}

	void SoundBufferClass::Rate::set(uint32 value)
	{
		InternalSoundBufferClassPointer->uRate = value;
	}

	uint32 SoundBufferClass::Bits::get()
	{
		return InternalSoundBufferClassPointer->uBits;
	}

	void SoundBufferClass::Bits::set(uint32 value)
	{
		InternalSoundBufferClassPointer->uBits = value;
	}

	uint32 SoundBufferClass::Channels::get()
	{
		return InternalSoundBufferClassPointer->uChannels;
	}

	void SoundBufferClass::Channels::set(uint32 value)
	{
		InternalSoundBufferClassPointer->uChannels = value;
	}

	uint32 SoundBufferClass::Type::get()
	{
		return InternalSoundBufferClassPointer->uType;
	}

	void SoundBufferClass::Type::set(uint32 value)
	{
		InternalSoundBufferClassPointer->uType = value;
	}

	unsigned int SoundBufferClass::Flag::get()
	{
		return InternalSoundBufferClassPointer->flag;
	}

	void SoundBufferClass::Flag::set(unsigned int value)
	{
		InternalSoundBufferClassPointer->flag = value;
	}

	int SoundBufferClass::CacheCount::get()
	{
		return InternalSoundBufferClassPointer->cachecount;
	}

	void SoundBufferClass::CacheCount::set(int value)
	{
		InternalSoundBufferClassPointer->cachecount = value;
	}

	bool SoundBufferClass::IsStreaming::get()
	{
		return InternalSoundBufferClassPointer->Is_Streaming();
	}

	::RefCountClass *SoundBufferClass::InternalRefCountClassPointer::get()
	{
		return InternalSoundBufferClassPointer;
	}

	::SoundBufferClass *SoundBufferClass::InternalSoundBufferClassPointer::get()
	{
		return reinterpret_cast<::SoundBufferClass *>(Pointer.ToPointer());
	}

	StreamSoundBufferClass::StreamSoundBufferClass(IntPtr pointer)
		: SoundBufferClass(pointer)
	{

	}

	IntPtr StreamSoundBufferClass::StreamSoundBufferClassPointer::get()
	{
		return IntPtr(InternalStreamSoundBufferClassPointer);
	}

	::SoundBufferClass *StreamSoundBufferClass::InternalSoundBufferClassPointer::get()
	{
		return InternalStreamSoundBufferClassPointer;
	}

	::StreamSoundBufferClass *StreamSoundBufferClass::InternalStreamSoundBufferClassPointer::get()
	{
		return reinterpret_cast<::StreamSoundBufferClass *>(Pointer.ToPointer());
	}
}