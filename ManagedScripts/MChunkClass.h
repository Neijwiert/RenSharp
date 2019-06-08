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

#pragma once

#include "IUnmanagedObject.h"
#include "IUnmanagedContainer.h"
#include "AbstractUnmanagedObject.h"

using namespace System;
using namespace System::Runtime::InteropServices;

namespace RenSharp
{
	interface class IFileClass;

	[StructLayout(LayoutKind::Sequential)]
	public value class ChunkHeader
	{
		public:
			unsigned long ChunkType;
			unsigned long ChunkSize;

			ChunkHeader(IntPtr pointer);
	};

	[StructLayout(LayoutKind::Sequential)]
	public value class MicroChunkHeader
	{
		public:
			unsigned char ChunkType;
			unsigned char ChunkSize;

			MicroChunkHeader(IntPtr pointer);
	};

	[StructLayout(LayoutKind::Sequential)]
	public value class MicroChunkHeader2
	{
		public:
			unsigned short ChunkType;
			unsigned short ChunkSize;

			MicroChunkHeader2(IntPtr pointer);
	};

	[StructLayout(LayoutKind::Sequential)]
	public value class IOVector2Struct
	{
		public:
			float X;
			float Y;

			IOVector2Struct(IntPtr pointer);
	};

	[StructLayout(LayoutKind::Sequential)]
	public value class IOVector3Struct
	{
		public:
			float X;
			float Y;
			float Z;

			IOVector3Struct(IntPtr pointer);
	};

	[StructLayout(LayoutKind::Sequential)]
	public value class IOVector4Struct
	{
		public:
			float X;
			float Y;
			float Z;
			float W;

			IOVector4Struct(IntPtr pointer);
	};

	[StructLayout(LayoutKind::Sequential)]
	public value class IOQuaternionStruct
	{
		public:
			[MarshalAs(UnmanagedType::ByValArray, SizeConst = 4)]
			array<float> ^Q;

			IOQuaternionStruct(IntPtr pointer);
	};

	public interface class IChunkLoadClass : public IUnmanagedObject
	{
		bool OpenChunk();

		bool PeekNextChunk([Out] unsigned int %id, [Out] unsigned int %length);

		bool CloseChunk();

		bool OpenMicroChunk();

		bool CloseMicroChunk();

		int Seek(unsigned long nBytes);

		int Read(array<std::uint8_t> ^buffer);

		int Read([Out] IOVector2Struct %result);

		int Read([Out] IOVector3Struct %result);

		int Read([Out] IOVector4Struct %result);

		int Read([Out] IOQuaternionStruct %result);

		int Read([Out] String ^%result);

		int SimpleRead([Out] bool %result);

		int SimpleRead([Out] signed char %result);

		int SimpleRead([Out] unsigned char %result);

		int SimpleRead([Out] wchar_t %result);

		int SimpleRead([Out] double %result);

		int SimpleRead([Out] float %result);

		int SimpleRead([Out] signed int %result);

		int SimpleRead([Out] unsigned int %result);

		int SimpleRead([Out] signed __int64 %result);

		int SimpleRead([Out] unsigned __int64 %result);

		int SimpleRead([Out] signed short %result);

		int SimpleRead([Out] unsigned short %result);

		generic<typename T> 
		where T : value class
		int SimpleRead([Out] T %result);

		property IntPtr ChunkLoadClassPointer
		{
			IntPtr get();
		}

		property unsigned long CurChunkId
		{
			unsigned long get();
		}

		property unsigned long CurChunkLength
		{
			unsigned long get();
		}

		property int CurChunkDepth
		{
			int get();
		}

		property int ContainsChunks
		{
			int get();
		}

		property unsigned long CurMicroChunkId
		{
			unsigned long get();
		}

		property unsigned long CurMicroChunkLength
		{
			unsigned long get();
		}
	};

	public ref class ChunkLoadClass : public AbstractUnmanagedObject, public IChunkLoadClass
	{
		private:
			ChunkLoadClass(IFileClass ^file);

		public:
			ChunkLoadClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			static IUnmanagedContainer<IChunkLoadClass ^> ^CreateChunkLoadClass(IFileClass ^file);

			virtual bool OpenChunk() sealed;
			virtual bool PeekNextChunk([Out] unsigned int %id, [Out] unsigned int %length) sealed;
			virtual bool CloseChunk() sealed;
			virtual bool OpenMicroChunk() sealed;
			virtual bool CloseMicroChunk() sealed;
			virtual int Seek(unsigned long nBytes) sealed;
			virtual int Read(array<std::uint8_t> ^buffer) sealed;
			virtual int Read([Out] IOVector2Struct %result) sealed;
			virtual int Read([Out] IOVector3Struct %result) sealed;
			virtual int Read([Out] IOVector4Struct %result) sealed;
			virtual int Read([Out] IOQuaternionStruct %result) sealed;
			virtual int Read([Out] String ^%result) sealed;
			virtual int SimpleRead([Out] bool %result) sealed;
			virtual int SimpleRead([Out] signed char %result) sealed;
			virtual int SimpleRead([Out] unsigned char %result) sealed;
			virtual int SimpleRead([Out] wchar_t %result) sealed;
			virtual int SimpleRead([Out] double %result) sealed;
			virtual int SimpleRead([Out] float %result) sealed;
			virtual int SimpleRead([Out] signed int %result) sealed;
			virtual int SimpleRead([Out] unsigned int %result) sealed;
			virtual int SimpleRead([Out] signed __int64 %result) sealed;
			virtual int SimpleRead([Out] unsigned __int64 %result) sealed;
			virtual int SimpleRead([Out] signed short %result) sealed;
			virtual int SimpleRead([Out] unsigned short %result) sealed;

			generic<typename T> 
			where T : value class
			virtual int SimpleRead([Out] T %result) sealed
			{
				int tSize = Marshal::SizeOf(T::typeid);
				array<std::uint8_t> ^buffer = gcnew array<std::uint8_t>(tSize);

				int readResult = Read(buffer);
				if (readResult != tSize)
				{
					result = T();

					return readResult;
				}

				pin_ptr<std::uint8_t> pinnedBuffer = &buffer[0];
				std::uint8_t *bufferPtr = pinnedBuffer;

				result = Marshal::PtrToStructure<T>(IntPtr(bufferPtr));

				return readResult;
			}

			property IntPtr ChunkLoadClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property unsigned long CurChunkId
			{
				virtual unsigned long get() sealed;
			}

			property unsigned long CurChunkLength
			{
				virtual unsigned long get() sealed;
			}

			property int CurChunkDepth
			{
				virtual int get() sealed;
			}

			property int ContainsChunks
			{
				virtual int get() sealed;
			}

			property unsigned long CurMicroChunkId
			{
				virtual unsigned long get() sealed;
			}

			property unsigned long CurMicroChunkLength
			{
				virtual unsigned long get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::ChunkLoadClass *InternalChunkLoadClassPointer
			{
				virtual ::ChunkLoadClass *get();
			}
	};

	public interface class IChunkSaveClass : public IUnmanagedObject
	{
		void SetContainsChunks();

		bool BeginChunk(unsigned long id);

		bool EndChunk();

		bool BeginMicroChunk(unsigned long id);

		bool EndMicroChunk();

		unsigned long Write(array<std::uint8_t> ^buffer);

		unsigned long Write(IOVector2Struct v);

		unsigned long Write(IOVector3Struct v);

		unsigned long Write(IOVector4Struct v);

		unsigned long Write(IOQuaternionStruct v);

		unsigned long Write(String ^str);

		int SimpleWrite(bool v);

		int SimpleWrite(signed char v);

		int SimpleWrite(unsigned char v);

		int SimpleWrite(wchar_t v);

		int SimpleWrite(double v);

		int SimpleWrite(float v);

		int SimpleWrite(signed int v);

		int SimpleWrite(unsigned int v);

		int SimpleWrite(signed __int64 v);

		int SimpleWrite(unsigned __int64 v);

		int SimpleWrite(signed short v);

		int SimpleWrite(unsigned short v);

		generic<typename T> 
		where T : value class
		int SimpleWrite(T v);

		property IntPtr ChunkSaveClassPointer
		{
			IntPtr get();
		}

		property int CurChunkDepth
		{
			int get();
		}

		property unsigned int CurChunkLength
		{
			unsigned int get();
		}
	};

	public ref class ChunkSaveClass : public AbstractUnmanagedObject, public IChunkSaveClass
	{
		private:
			ChunkSaveClass(IFileClass ^file);

		public:
			ChunkSaveClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			IUnmanagedContainer<IChunkSaveClass ^> ^CreateChunkSaveClass(IFileClass ^file);

			virtual void SetContainsChunks() sealed;
			virtual bool BeginChunk(unsigned long id) sealed;
			virtual bool EndChunk() sealed;
			virtual bool BeginMicroChunk(unsigned long id) sealed;
			virtual bool EndMicroChunk() sealed;
			virtual unsigned long Write(array<std::uint8_t> ^buffer) sealed;
			virtual unsigned long Write(IOVector2Struct v) sealed;
			virtual unsigned long Write(IOVector3Struct v) sealed;
			virtual unsigned long Write(IOVector4Struct v) sealed;
			virtual unsigned long Write(IOQuaternionStruct v) sealed;
			virtual unsigned long Write(String ^str) sealed;
			virtual int SimpleWrite(bool v) sealed;
			virtual int SimpleWrite(signed char v) sealed;
			virtual int SimpleWrite(unsigned char v) sealed;
			virtual int SimpleWrite(wchar_t v) sealed;
			virtual int SimpleWrite(double v) sealed;
			virtual int SimpleWrite(float v) sealed;
			virtual int SimpleWrite(signed int v) sealed;
			virtual int SimpleWrite(unsigned int v) sealed;
			virtual int SimpleWrite(signed __int64 v) sealed;
			virtual int SimpleWrite(unsigned __int64 v) sealed;
			virtual int SimpleWrite(signed short v) sealed;
			virtual int SimpleWrite(unsigned short v) sealed;

			generic<typename T> 
			where T : value class
			virtual int SimpleWrite(T v) sealed
			{
				int tSize = Marshal::SizeOf(T::typeid);
				array<std::uint8_t> ^buffer = gcnew array<std::uint8_t>(tSize);

				IntPtr structPtr = Marshal::AllocHGlobal(tSize);
				try
				{
					Marshal::StructureToPtr(v, structPtr, true);
					Marshal::Copy(structPtr, buffer, 0, tSize);
				}
				finally
				{
					Marshal::FreeHGlobal(structPtr);
				}

				return Write(buffer);
			}

			property IntPtr ChunkSaveClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property int CurChunkDepth
			{
				virtual int get() sealed;
			}

			property unsigned int CurChunkLength
			{
				virtual unsigned int get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::ChunkSaveClass *InternalChunkSaveClassPointer
			{
				virtual ::ChunkSaveClass *get();
			}
	};
}
