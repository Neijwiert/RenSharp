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
#include "MChunkClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <ChunkClass.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "Mengine_io.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	ChunkHeader::ChunkHeader(IntPtr pointer)
	{
		if (pointer == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		::ChunkHeader *tmp = reinterpret_cast<::ChunkHeader *>(pointer.ToPointer());
		ChunkType = tmp->ChunkType;
		ChunkSize = tmp->ChunkSize;
	}

	MicroChunkHeader::MicroChunkHeader(IntPtr pointer)
	{
		if (pointer == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		::MicroChunkHeader *tmp = reinterpret_cast<::MicroChunkHeader *>(pointer.ToPointer());
		ChunkType = tmp->ChunkType;
		ChunkSize = tmp->ChunkSize;
	}

	MicroChunkHeader2::MicroChunkHeader2(IntPtr pointer)
	{
		if (pointer == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		::MicroChunkHeader2 *tmp = reinterpret_cast<::MicroChunkHeader2 *>(pointer.ToPointer());
		ChunkType = tmp->ChunkType;
		ChunkSize = tmp->ChunkSize;
	}

	IOVector2Struct::IOVector2Struct(IntPtr pointer)
	{
		if (pointer == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		::IOVector2Struct *tmp = reinterpret_cast<::IOVector2Struct *>(pointer.ToPointer());
		X = tmp->X;
		Y = tmp->Y;
	}

	IOVector3Struct::IOVector3Struct(IntPtr pointer)
	{
		if (pointer == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		::IOVector3Struct *tmp = reinterpret_cast<::IOVector3Struct *>(pointer.ToPointer());
		X = tmp->X;
		Y = tmp->Y;
		Z = tmp->Z;
	}

	IOVector4Struct::IOVector4Struct(IntPtr pointer)
	{
		if (pointer == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		::IOVector4Struct *tmp = reinterpret_cast<::IOVector4Struct *>(pointer.ToPointer());
		X = tmp->X;
		Y = tmp->Y;
		Z = tmp->Z;
		W = tmp->W;
	}

	IOQuaternionStruct::IOQuaternionStruct(IntPtr pointer)
		: Q(gcnew array<float>(4))
	{
		if (pointer == IntPtr::Zero)
		{
			throw gcnew ArgumentNullException("pointer");
		}

		::IOQuaternionStruct *tmp = reinterpret_cast<::IOQuaternionStruct *>(pointer.ToPointer());
		Q[0] = tmp->Q[0];
		Q[1] = tmp->Q[1];
		Q[2] = tmp->Q[2];
		Q[3] = tmp->Q[3];
	}

	ChunkLoadClass::ChunkLoadClass(IFileClass ^file)
		: AbstractUnmanagedObject()
	{
		if (file == nullptr || file->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("file");
		}

		Pointer = IntPtr(Imports::CreateChunkLoadClass(reinterpret_cast<::FileClass *>(file->FileClassPointer.ToPointer())));
	}

	ChunkLoadClass::ChunkLoadClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool ChunkLoadClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IChunkLoadClass ^otherThis = dynamic_cast<IChunkLoadClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return ChunkLoadClassPointer.Equals(otherThis->ChunkLoadClassPointer);
	}

	IUnmanagedContainer<IChunkLoadClass ^> ^ChunkLoadClass::CreateChunkLoadClass(IFileClass ^file)
	{
		return gcnew UnmanagedContainer<IChunkLoadClass ^>(gcnew ChunkLoadClass(file));
	}

	bool ChunkLoadClass::OpenChunk()
	{
		return InternalChunkLoadClassPointer->Open_Chunk();
	}

	bool ChunkLoadClass::PeekNextChunk(unsigned int %id, unsigned int %length)
	{
		uint tmpId = 0;
		uint tmpLength = 0;
		bool result = InternalChunkLoadClassPointer->Peek_Next_Chunk(&tmpId, &tmpLength);

		id = tmpId;
		length = tmpLength;

		return result;
	}

	bool ChunkLoadClass::CloseChunk()
	{
		return InternalChunkLoadClassPointer->Close_Chunk();
	}

	bool ChunkLoadClass::OpenMicroChunk()
	{
		return InternalChunkLoadClassPointer->Open_Micro_Chunk();
	}

	bool ChunkLoadClass::CloseMicroChunk()
	{
		return InternalChunkLoadClassPointer->Close_Micro_Chunk();
	}

	int ChunkLoadClass::Seek(unsigned long nBytes)
	{
		return InternalChunkLoadClassPointer->Seek(nBytes);
	}

	int ChunkLoadClass::Read(array<std::uint8_t> ^buffer)
	{
		if (buffer == nullptr)
		{
			throw gcnew ArgumentNullException("buffer");
		}

		pin_ptr<std::uint8_t> pinnedBuffer = &buffer[0];
		std::uint8_t *bufferPtr = pinnedBuffer;

		return InternalChunkLoadClassPointer->Read(bufferPtr, buffer->Length);
	}

	int ChunkLoadClass::Read(IOVector2Struct %result)
	{
		::IOVector2Struct tmp;
		int readResult = InternalChunkLoadClassPointer->Read(&tmp);

		result = IOVector2Struct(IntPtr(&tmp));

		return readResult;
	}

	int ChunkLoadClass::Read(IOVector3Struct %result)
	{
		::IOVector3Struct tmp;
		int readResult = InternalChunkLoadClassPointer->Read(&tmp);

		result = IOVector3Struct(IntPtr(&tmp));

		return readResult;
	}

	int ChunkLoadClass::Read(IOVector4Struct %result)
	{
		::IOVector4Struct tmp;
		int readResult = InternalChunkLoadClassPointer->Read(&tmp);

		result = IOVector4Struct(IntPtr(&tmp));

		return readResult;
	}

	int ChunkLoadClass::Read(IOQuaternionStruct %result)
	{
		::IOQuaternionStruct tmp;
		int readResult = InternalChunkLoadClassPointer->Read(&tmp);

		result = IOQuaternionStruct(IntPtr(&tmp));

		return readResult;
	}

	int ChunkLoadClass::Read(String ^%result)
	{
		StringClass tmp;
		int readResult = InternalChunkLoadClassPointer->Read(tmp);

		result = gcnew String(tmp.Peek_Buffer());

		return readResult;
	}

	int ChunkLoadClass::SimpleRead(bool %result)
	{
		bool tmp;
		int readResult = InternalChunkLoadClassPointer->SimpleRead(tmp);

		result = tmp;

		return readResult;
	}

	int ChunkLoadClass::SimpleRead(signed char %result)
	{
		signed char tmp;
		int readResult = InternalChunkLoadClassPointer->SimpleRead(tmp);

		result = tmp;

		return readResult;
	}

	int ChunkLoadClass::SimpleRead(unsigned char %result)
	{
		unsigned char tmp;
		int readResult = InternalChunkLoadClassPointer->SimpleRead(tmp);

		result = tmp;

		return readResult;
	}

	int ChunkLoadClass::SimpleRead(wchar_t %result)
	{
		wchar_t tmp;
		int readResult = InternalChunkLoadClassPointer->SimpleRead(tmp);

		result = tmp;

		return readResult;
	}

	int ChunkLoadClass::SimpleRead(double %result)
	{
		double tmp;
		int readResult = InternalChunkLoadClassPointer->SimpleRead(tmp);

		result = tmp;

		return readResult;
	}

	int ChunkLoadClass::SimpleRead(float %result)
	{
		float tmp;
		int readResult = InternalChunkLoadClassPointer->SimpleRead(tmp);

		result = tmp;

		return readResult;
	}

	int ChunkLoadClass::SimpleRead(signed int %result)
	{
		signed int tmp;
		int readResult = InternalChunkLoadClassPointer->SimpleRead(tmp);

		result = tmp;

		return readResult;
	}

	int ChunkLoadClass::SimpleRead(unsigned int %result)
	{
		unsigned int tmp;
		int readResult = InternalChunkLoadClassPointer->SimpleRead(tmp);

		result = tmp;

		return readResult;
	}

	int ChunkLoadClass::SimpleRead(signed __int64 %result)
	{
		signed __int64 tmp;
		int readResult = InternalChunkLoadClassPointer->SimpleRead(tmp);

		result = tmp;

		return readResult;
	}

	int ChunkLoadClass::SimpleRead(unsigned __int64 %result)
	{
		unsigned __int64 tmp;
		int readResult = InternalChunkLoadClassPointer->SimpleRead(tmp);

		result = tmp;

		return readResult;
	}

	int ChunkLoadClass::SimpleRead(signed short %result)
	{
		signed short tmp;
		int readResult = InternalChunkLoadClassPointer->SimpleRead(tmp);

		result = tmp;

		return readResult;
	}

	int ChunkLoadClass::SimpleRead(unsigned short %result)
	{
		unsigned short tmp;
		int readResult = InternalChunkLoadClassPointer->SimpleRead(tmp);

		result = tmp;

		return readResult;
	}

	IntPtr ChunkLoadClass::ChunkLoadClassPointer::get()
	{
		return IntPtr(InternalChunkLoadClassPointer);
	}

	unsigned long ChunkLoadClass::CurChunkId::get()
	{
		return InternalChunkLoadClassPointer->Cur_Chunk_ID();
	}

	unsigned long ChunkLoadClass::CurChunkLength::get()
	{
		return InternalChunkLoadClassPointer->Cur_Chunk_Length();
	}

	int ChunkLoadClass::CurChunkDepth::get()
	{
		return InternalChunkLoadClassPointer->Cur_Chunk_Depth();
	}

	int ChunkLoadClass::ContainsChunks::get()
	{
		return InternalChunkLoadClassPointer->Contains_Chunks();
	}

	unsigned long ChunkLoadClass::CurMicroChunkId::get()
	{
		return InternalChunkLoadClassPointer->Cur_Micro_Chunk_ID();
	}

	unsigned long ChunkLoadClass::CurMicroChunkLength::get()
	{
		return InternalChunkLoadClassPointer->Cur_Micro_Chunk_Length();
	}

	bool ChunkLoadClass::InternalDestroyPointer()
	{
		Imports::DestroyChunkLoadClass(InternalChunkLoadClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::ChunkLoadClass *ChunkLoadClass::InternalChunkLoadClassPointer::get()
	{
		return reinterpret_cast<::ChunkLoadClass *>(Pointer.ToPointer());
	}

	ChunkSaveClass::ChunkSaveClass(IFileClass ^file)
		: AbstractUnmanagedObject()
	{
		if (file == nullptr || file->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("file");
		}

		Pointer = IntPtr(Imports::CreateChunkSaveClass(reinterpret_cast<::FileClass *>(file->FileClassPointer.ToPointer())));
	}

	ChunkSaveClass::ChunkSaveClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool ChunkSaveClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IChunkSaveClass ^otherThis = dynamic_cast<IChunkSaveClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return ChunkSaveClassPointer.Equals(otherThis->ChunkSaveClassPointer);
	}

	IUnmanagedContainer<IChunkSaveClass ^> ^ChunkSaveClass::CreateChunkSaveClass(IFileClass ^file)
	{
		return gcnew UnmanagedContainer<IChunkSaveClass ^>(gcnew ChunkSaveClass(file));
	}

	void ChunkSaveClass::SetContainsChunks()
	{
		InternalChunkSaveClassPointer->Set_Contains_Chunks();
	}

	bool ChunkSaveClass::BeginChunk(unsigned long id)
	{
		return InternalChunkSaveClassPointer->Begin_Chunk(id);
	}

	bool ChunkSaveClass::EndChunk()
	{
		return InternalChunkSaveClassPointer->End_Chunk();
	}

	bool ChunkSaveClass::BeginMicroChunk(unsigned long id)
	{
		return InternalChunkSaveClassPointer->Begin_Micro_Chunk(id);
	}

	bool ChunkSaveClass::EndMicroChunk()
	{
		return InternalChunkSaveClassPointer->End_Micro_Chunk();
	}

	unsigned long ChunkSaveClass::Write(array<std::uint8_t> ^buffer)
	{
		if (buffer == nullptr)
		{
			throw gcnew ArgumentNullException("buffer");
		}

		pin_ptr<std::uint8_t> pinnedBuffer = &buffer[0];
		std::uint8_t *bufferPtr = pinnedBuffer;

		return InternalChunkSaveClassPointer->Write(bufferPtr, buffer->Length);
	}

	unsigned long ChunkSaveClass::Write(IOVector2Struct v)
	{
		::IOVector2Struct tmp;
		tmp.X = v.X;
		tmp.Y = v.Y;

		return InternalChunkSaveClassPointer->Write(tmp);
	}

	unsigned long ChunkSaveClass::Write(IOVector3Struct v)
	{
		::IOVector3Struct tmp;
		tmp.X = v.X;
		tmp.Y = v.Y;
		tmp.Z = v.Z;

		return InternalChunkSaveClassPointer->Write(tmp);
	}

	unsigned long ChunkSaveClass::Write(IOVector4Struct v)
	{
		::IOVector4Struct tmp;
		tmp.X = v.X;
		tmp.Y = v.Y;
		tmp.Z = v.Z;
		tmp.W = v.W;

		return InternalChunkSaveClassPointer->Write(tmp);
	}

	unsigned long ChunkSaveClass::Write(IOQuaternionStruct v)
	{
		::IOQuaternionStruct tmp;
		if (v.Q == nullptr)
		{
			tmp.Q[0] = 0;
			tmp.Q[1] = 0;
			tmp.Q[2] = 0;
			tmp.Q[3] = 0;
		}
		else
		{
			tmp.Q[0] = v.Q[0];
			tmp.Q[1] = v.Q[1];
			tmp.Q[2] = v.Q[2];
			tmp.Q[3] = v.Q[3];
		}

		return InternalChunkSaveClassPointer->Write(tmp);
	}

	unsigned long ChunkSaveClass::Write(String ^str)
	{
		if (str == nullptr)
		{
			throw gcnew ArgumentNullException("str");
		}

		IntPtr strPtr = Marshal::StringToHGlobalAnsi(str);
		try
		{
			::StringClass tmp(reinterpret_cast<const char *>(strPtr.ToPointer()));

			return InternalChunkSaveClassPointer->Write(tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(strPtr);
		}
	}

	int ChunkSaveClass::SimpleWrite(bool v)
	{
		return InternalChunkSaveClassPointer->SimpleWrite(v);
	}

	int ChunkSaveClass::SimpleWrite(signed char v)
	{
		return InternalChunkSaveClassPointer->SimpleWrite(v);
	}

	int ChunkSaveClass::SimpleWrite(unsigned char v)
	{
		return InternalChunkSaveClassPointer->SimpleWrite(v);
	}

	int ChunkSaveClass::SimpleWrite(wchar_t v)
	{
		return InternalChunkSaveClassPointer->SimpleWrite(v);
	}

	int ChunkSaveClass::SimpleWrite(double v)
	{
		return InternalChunkSaveClassPointer->SimpleWrite(v);
	}

	int ChunkSaveClass::SimpleWrite(float v)
	{
		return InternalChunkSaveClassPointer->SimpleWrite(v);
	}

	int ChunkSaveClass::SimpleWrite(signed int v)
	{
		return InternalChunkSaveClassPointer->SimpleWrite(v);
	}

	int ChunkSaveClass::SimpleWrite(unsigned int v)
	{
		return InternalChunkSaveClassPointer->SimpleWrite(v);
	}

	int ChunkSaveClass::SimpleWrite(signed __int64 v)
	{
		return InternalChunkSaveClassPointer->SimpleWrite(v);
	}

	int ChunkSaveClass::SimpleWrite(unsigned __int64 v)
	{
		return InternalChunkSaveClassPointer->SimpleWrite(v);
	}

	int ChunkSaveClass::SimpleWrite(signed short v)
	{
		return InternalChunkSaveClassPointer->SimpleWrite(v);
	}

	int ChunkSaveClass::SimpleWrite(unsigned short v)
	{
		return InternalChunkSaveClassPointer->SimpleWrite(v);
	}

	IntPtr ChunkSaveClass::ChunkSaveClassPointer::get()
	{
		return IntPtr(InternalChunkSaveClassPointer);
	}

	int ChunkSaveClass::CurChunkDepth::get()
	{
		return InternalChunkSaveClassPointer->Cur_Chunk_Depth();
	}

	uint ChunkSaveClass::CurChunkLength::get()
	{
		return InternalChunkSaveClassPointer->Cur_Chunk_Length();
	}

	bool ChunkSaveClass::InternalDestroyPointer()
	{
		Imports::DestroyChunkSaveClass(InternalChunkSaveClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::ChunkSaveClass *ChunkSaveClass::InternalChunkSaveClassPointer::get()
	{
		return reinterpret_cast<::ChunkSaveClass *>(Pointer.ToPointer());
	}
}