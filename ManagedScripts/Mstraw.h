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

#pragma once

#include "AbstractUnmanagedObject.h"
#include "IUnmanagedContainer.h"

#pragma managed(push, off)

class Straw;
class Pipe;

#pragma managed(pop)

namespace RenSharp
{
	interface class IFileClass;

	public interface class IStraw : public IUnmanagedObject
	{
		void GetFrom(IStraw ^straw);

		int Get(array<std::uint8_t> ^source);

		property IntPtr StrawPointer
		{
			IntPtr get();
		}
	};

	public ref class Straw : public AbstractUnmanagedObject, public IStraw
	{
		protected:
			Straw(bool create);

		public:
			Straw(IntPtr pointer);

			bool Equals(Object ^other) override;

			static IUnmanagedContainer<IStraw ^> ^CreateStraw();

			virtual void GetFrom(IStraw ^straw) sealed;
			virtual int Get(array<std::uint8_t> ^source) sealed;

			property IntPtr StrawPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::Straw *InternalStrawPointer
			{
				virtual ::Straw *get();
			}
	};

	public interface class IBuffer : public IUnmanagedObject
	{
		property IntPtr BufferPointer
		{
			IntPtr get();
		}

		property array<std::uint8_t> ^BBuffer
		{
			array<std::uint8_t> ^get();
		}

		property long Size
		{
			long get();
		}
	};

	public ref class Buffer : public AbstractUnmanagedObject, public IBuffer
	{
		private:
			Buffer(long size);

		public:
			Buffer(IntPtr pointer);

			bool Equals(Object ^other) override;

			static IUnmanagedContainer<IBuffer ^> ^CreateBuffer(long size);

			property IntPtr BufferPointer
			{
				virtual IntPtr get() sealed;
			}

			property array<std::uint8_t> ^BBuffer
			{
				virtual array<std::uint8_t> ^get() sealed;
			}

			property long Size
			{
				virtual long get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::Buffer *InternalBufferPointer
			{
				virtual ::Buffer *get();
			}
	};

	public interface class IBufferStraw : public IStraw
	{
		property IntPtr BufferStrawPointer
		{
			IntPtr get();
		}
	};

	public ref class BufferStraw : public Straw, public IBufferStraw
	{
		private:
			BufferStraw(int size);

		public:
			BufferStraw(IntPtr pointer);

			static IUnmanagedContainer<IBufferStraw ^> ^CreateBufferStraw(int size);

			property IntPtr BufferStrawPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::Straw *InternalStrawPointer
			{
				::Straw *get() override;
			}

			property ::BufferStraw *InternalBufferStrawPointer
			{
				virtual ::BufferStraw *get();
			}
	};

	public interface class IFileStraw : public IStraw
	{
		property IntPtr FileStrawPointer
		{
			IntPtr get();
		}
	};

	public ref class FileStraw : public Straw, public IFileStraw
	{
		private:
			FileStraw(IFileClass ^file);

		public:
			FileStraw(IntPtr pointer);

			static IUnmanagedContainer<IFileStraw ^> ^CreateFileStraw(IFileClass ^file);

			property IntPtr FileStrawPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::Straw *InternalStrawPointer
			{
				::Straw *get() override;
			}

			property ::FileStraw *InternalFileStrawPointer
			{
				virtual ::FileStraw *get();
			}
	};

	public interface class ICacheStraw : public IStraw
	{
		property IntPtr CacheStrawPointer
		{
			IntPtr get();
		}

		property bool IsValid
		{
			bool get();
		}
	};

	public ref class CacheStraw : public Straw, public ICacheStraw
	{
		private:
			CacheStraw(int size);

		public:
			CacheStraw(IntPtr pointer);

			static IUnmanagedContainer<ICacheStraw ^> ^CreateCacheStraw(int size);

			property IntPtr CacheStrawPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool IsValid
			{
				virtual bool get() sealed;
			}

		protected:
			property ::Straw *InternalStrawPointer
			{
				::Straw *get() override;
			}

			property ::CacheStraw *InternalCacheStrawPointer
			{
				virtual ::CacheStraw *get();
			}
	};

	public interface class IPipe : public IUnmanagedObject
	{
		int Flush();

		int End();

		void PutTo(IPipe ^pipe);

		int Put(array<std::uint8_t> ^source);

		property IntPtr PipePointer
		{
			IntPtr get();
		}
	};

	public ref class Pipe : public AbstractUnmanagedObject, public IPipe
	{
		protected:
			Pipe(bool create);

		public:
			Pipe(IntPtr pointer);

			bool Equals(Object ^other) override;

			static IUnmanagedContainer<IPipe ^> ^CreatePipe();

			virtual int Flush() sealed;
			virtual int End() sealed;
			virtual void PutTo(IPipe ^pipe) sealed;
			virtual int Put(array<std::uint8_t> ^source) sealed;

			property IntPtr PipePointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::Pipe *InternalPipePointer
			{
				virtual ::Pipe *get();
			}
	};

	public interface class IBufferPipe : public IPipe
	{
		property IntPtr BufferPipePointer
		{
			IntPtr get();
		}
	};

	public ref class BufferPipe : public Pipe, public IBufferPipe
	{
		private:
			BufferPipe(int size);

		public:
			BufferPipe(IntPtr pointer);

			static IUnmanagedContainer<IBufferPipe ^> ^CreateBufferPipe(int size);

			property IntPtr BufferPipePointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::Pipe *InternalPipePointer
			{
				::Pipe *get() override;
			}

			property ::BufferPipe *InternalBufferPipePointer
			{
				virtual ::BufferPipe *get();
			}
	};

	public interface class IFilePipe : public IPipe
	{
		property IntPtr FilePipePointer
		{
			IntPtr get();
		}
	};

	public ref class FilePipe : public Pipe, public IFilePipe
	{
		private:
			FilePipe(IFileClass ^file);

		public:
			FilePipe(IntPtr pointer);

			static IUnmanagedContainer<IFilePipe ^> ^CreateFilePipe(IFileClass ^file);

			property IntPtr FilePipePointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::Pipe *InternalPipePointer
			{
				::Pipe *get() override;
			}

			property ::FilePipe *InternalFilePipePointer
			{
				virtual ::FilePipe *get();
			}
	};
}