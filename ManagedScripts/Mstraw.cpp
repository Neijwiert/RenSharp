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
#include "Mstraw.h"

#include "UnmanagedContainer.h"
#include "Imports.h"
#include "Mengine_io.h"

using namespace System;

namespace RenSharp
{
	Straw::Straw(bool create)
		: AbstractUnmanagedObject()
	{
		if (create)
		{
			Pointer = IntPtr(Imports::CreateStraw());
		}
	}

	Straw::Straw(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool Straw::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IStraw ^otherThis = dynamic_cast<IStraw ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return StrawPointer.Equals(otherThis->StrawPointer);
	}

	IUnmanagedContainer<IStraw ^> ^Straw::CreateStraw()
	{
		return gcnew UnmanagedContainer<IStraw ^>(gcnew Straw(true));
	}

	void Straw::GetFrom(IStraw ^straw)
	{
		if (straw == nullptr || straw->Pointer.ToPointer() == nullptr)
		{
			InternalStrawPointer->Get_From(nullptr);
		}
		else
		{
			InternalStrawPointer->Get_From(reinterpret_cast<::Straw *>(straw->StrawPointer.ToPointer()));
		}
	}

	int Straw::Get(array<std::uint8_t> ^source)
	{
		if (source == nullptr)
		{
			throw gcnew ArgumentNullException("source");
		}

		pin_ptr<std::uint8_t> pinnedSource = &source[0];
		std::uint8_t *sourcePtr = pinnedSource;

		return InternalStrawPointer->Get(sourcePtr, source->Length);
	}

	IntPtr Straw::StrawPointer::get()
	{
		return IntPtr(InternalStrawPointer);
	}

	bool Straw::InternalDestroyPointer()
	{
		Imports::DestroyStraw(InternalStrawPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::Straw *Straw::InternalStrawPointer::get()
	{
		return reinterpret_cast<::Straw *>(Pointer.ToPointer());
	}

	Buffer::Buffer(long size)
		: AbstractUnmanagedObject()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateBuffer(size));
	}

	Buffer::Buffer(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool Buffer::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IBuffer ^otherThis = dynamic_cast<IBuffer ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return BufferPointer.Equals(otherThis->BufferPointer);
	}

	IUnmanagedContainer<IBuffer ^> ^Buffer::CreateBuffer(long size)
	{
		return gcnew UnmanagedContainer<IBuffer ^>(gcnew Buffer(size));
	}

	IntPtr Buffer::BufferPointer::get()
	{
		return IntPtr(InternalBufferPointer);
	}

	array<std::uint8_t> ^Buffer::BBuffer::get()
	{
		auto buffer = InternalBufferPointer->Get_Buffer();
		if (buffer == nullptr)
		{
			return nullptr;
		}
		else
		{
			long size = InternalBufferPointer->Get_Size();
			array<std::uint8_t> ^result = gcnew array<std::uint8_t>(size);
			Marshal::Copy(IntPtr(buffer), result, 0, result->Length);

			return result;
		}
	}

	long Buffer::Size::get()
	{
		return InternalBufferPointer->Get_Size();
	}

	bool Buffer::InternalDestroyPointer()
	{
		Imports::DestroyBuffer(InternalBufferPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::Buffer *Buffer::InternalBufferPointer::get()
	{
		return reinterpret_cast<::Buffer *>(Pointer.ToPointer());
	}

	BufferStraw::BufferStraw(int size)
		: Straw(false)
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateBufferStraw(size));
	}

	BufferStraw::BufferStraw(IntPtr pointer)
		: Straw(pointer)
	{

	}

	IUnmanagedContainer<IBufferStraw ^> ^BufferStraw::CreateBufferStraw(int size)
	{
		return gcnew UnmanagedContainer<IBufferStraw ^>(gcnew BufferStraw(size));
	}

	IntPtr BufferStraw::BufferStrawPointer::get()
	{
		return IntPtr(InternalBufferStrawPointer);
	}

	::Straw *BufferStraw::InternalStrawPointer::get()
	{
		return InternalBufferStrawPointer;
	}

	::BufferStraw *BufferStraw::InternalBufferStrawPointer::get()
	{
		return reinterpret_cast<::BufferStraw *>(Pointer.ToPointer());
	}

	FileStraw::FileStraw(IFileClass ^file)
		: Straw(false)
	{
		if (file == nullptr || file->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("file");
		}

		Pointer = IntPtr(Imports::CreateFileStraw(reinterpret_cast<::FileClass *>(file->FileClassPointer.ToPointer())));
	}

	FileStraw::FileStraw(IntPtr pointer)
		: Straw(pointer)
	{

	}

	IUnmanagedContainer<IFileStraw ^> ^FileStraw::CreateFileStraw(IFileClass ^file)
	{
		return gcnew UnmanagedContainer<IFileStraw ^>(gcnew FileStraw(file));
	}

	IntPtr FileStraw::FileStrawPointer::get()
	{
		return IntPtr(InternalFileStrawPointer);
	}

	::Straw *FileStraw::InternalStrawPointer::get()
	{
		return InternalFileStrawPointer;
	}

	::FileStraw *FileStraw::InternalFileStrawPointer::get()
	{
		return reinterpret_cast<::FileStraw *>(Pointer.ToPointer());
	}

	CacheStraw::CacheStraw(int size)
		: Straw(false)
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateCacheStraw(size));
	}

	CacheStraw::CacheStraw(IntPtr pointer)
		: Straw(pointer)
	{

	}

	IUnmanagedContainer<ICacheStraw ^> ^CacheStraw::CreateCacheStraw(int size)
	{
		return gcnew UnmanagedContainer<ICacheStraw ^>(gcnew CacheStraw(size));
	}

	IntPtr CacheStraw::CacheStrawPointer::get()
	{
		return IntPtr(InternalCacheStrawPointer);
	}

	bool CacheStraw::IsValid::get()
	{
		return InternalCacheStrawPointer->Is_Valid();
	}

	::Straw *CacheStraw::InternalStrawPointer::get()
	{
		return InternalCacheStrawPointer;
	}

	::CacheStraw *CacheStraw::InternalCacheStrawPointer::get()
	{
		return reinterpret_cast<::CacheStraw *>(Pointer.ToPointer());
	}

	Pipe::Pipe(bool create)
		: AbstractUnmanagedObject()
	{
		if (create)
		{
			Pointer = IntPtr(Imports::CreatePipe1());
		}
	}

	Pipe::Pipe(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool Pipe::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IPipe ^otherThis = dynamic_cast<IPipe ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return PipePointer.Equals(otherThis->PipePointer);
	}

	IUnmanagedContainer<IPipe ^> ^Pipe::CreatePipe()
	{
		return gcnew UnmanagedContainer<IPipe ^>(gcnew Pipe(true));
	}

	int Pipe::Flush()
	{
		return InternalPipePointer->Flush();
	}

	int Pipe::End()
	{
		return InternalPipePointer->End();
	}

	void Pipe::PutTo(IPipe ^pipe)
	{
		if (pipe == nullptr || pipe->Pointer.ToPointer() == nullptr)
		{
			InternalPipePointer->Put_To(nullptr);
		}
		else
		{
			InternalPipePointer->Put_To(reinterpret_cast<::Pipe *>(pipe->PipePointer.ToPointer()));
		}
	}

	int Pipe::Put(array<std::uint8_t> ^source)
	{
		if (source == nullptr)
		{
			throw gcnew ArgumentNullException("source");
		}

		pin_ptr<std::uint8_t> pinnedSource = &source[0];
		std::uint8_t *sourcePtr = pinnedSource;

		return InternalPipePointer->Put(sourcePtr, source->Length);
	}

	IntPtr Pipe::PipePointer::get()
	{
		return IntPtr(InternalPipePointer);
	}

	bool Pipe::InternalDestroyPointer()
	{
		Imports::DestroyPipe(InternalPipePointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::Pipe *Pipe::InternalPipePointer::get()
	{
		return reinterpret_cast<::Pipe *>(Pointer.ToPointer());
	}

	BufferPipe::BufferPipe(int size)
		: Pipe(false)
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateBufferPipe(size));
	}

	BufferPipe::BufferPipe(IntPtr pointer)
		: Pipe(pointer)
	{

	}

	IUnmanagedContainer<IBufferPipe ^> ^BufferPipe::CreateBufferPipe(int size)
	{
		return gcnew UnmanagedContainer<IBufferPipe ^>(gcnew BufferPipe(size));
	}

	IntPtr BufferPipe::BufferPipePointer::get()
	{
		return IntPtr(InternalBufferPipePointer);
	}

	::Pipe *BufferPipe::InternalPipePointer::get()
	{
		return InternalBufferPipePointer;
	}

	::BufferPipe *BufferPipe::InternalBufferPipePointer::get()
	{
		return reinterpret_cast<::BufferPipe *>(Pointer.ToPointer());
	}

	FilePipe::FilePipe(IFileClass ^file)
		: Pipe(false)
	{
		if (file == nullptr || file->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("file");
		}

		Pointer = IntPtr(Imports::CreateFilePipe(reinterpret_cast<::FileClass *>(file->FileClassPointer.ToPointer())));
	}

	FilePipe::FilePipe(IntPtr pointer)
		: Pipe(pointer)
	{

	}

	IUnmanagedContainer<IFilePipe ^> ^FilePipe::CreateFilePipe(IFileClass ^file)
	{
		return gcnew UnmanagedContainer<IFilePipe ^>(gcnew FilePipe(file));
	}

	IntPtr FilePipe::FilePipePointer::get()
	{
		return IntPtr(InternalFilePipePointer);
	}

	::Pipe *FilePipe::InternalPipePointer::get()
	{
		return InternalFilePipePointer;
	}

	::FilePipe *FilePipe::InternalFilePipePointer::get()
	{
		return reinterpret_cast<::FilePipe *>(Pointer.ToPointer());
	}
}