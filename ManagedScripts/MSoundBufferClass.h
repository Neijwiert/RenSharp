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

#include "Mengine_vector.h"

#pragma managed(push, off)

class SoundBufferClass;
class StreamSoundBufferClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IFileClass;

	public interface class ISoundBufferClass : public IRefCountClass
	{
		bool LoadFromFile(String ^file);

		bool LoadFromFile(IFileClass ^file);
		
		bool LoadFromMemory(array<std::uint8_t> ^buffer);

		void FreeBuffer();

		void DetermineStats(IntPtr stats);

		property IntPtr SoundBufferClassPointer
		{
			IntPtr get();
		}

		property array<std::uint8_t> ^Buffer
		{
			array<std::uint8_t> ^get();
			void set(array<std::uint8_t> ^value);
		}

		property uint32 Length
		{
			uint32 get();
			void set(uint32 value);
		}

		property String ^File
		{
			String ^get();
			void set(String ^value);
		}

		property uint32 Duration
		{
			uint32 get();
			void set(uint32 value);
		}

		property uint32 Rate
		{
			uint32 get();
			void set(uint32 value);
		}

		property uint32 Bits
		{
			uint32 get();
			void set(uint32 value);
		}

		property uint32 Channels
		{
			uint32 get();
			void set(uint32 value);
		}

		property uint32 Type
		{
			uint32 get();
			void set(uint32 value);
		}

		property unsigned int Flag
		{
			unsigned int get();
			void set(unsigned int value);
		}

		property int CacheCount
		{
			int get();
			void set(int value);
		}

		property bool IsStreaming
		{
			bool get();
		}
	};

	public ref class SoundBufferClass : public RefCountClass, public ISoundBufferClass
	{
		public:
			SoundBufferClass(IntPtr pointer);

			String ^ToString() override;

			virtual bool LoadFromFile(String ^file) sealed;
			virtual bool LoadFromFile(IFileClass ^file) sealed;
			virtual bool LoadFromMemory(array<std::uint8_t> ^buffer) sealed;
			virtual void FreeBuffer() sealed;
			virtual void DetermineStats(IntPtr stats) sealed;

			property IntPtr SoundBufferClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property array<std::uint8_t> ^Buffer
			{
				virtual array<std::uint8_t> ^get() sealed;
				virtual void set(array<std::uint8_t> ^value) sealed;
			}

			property uint32 Length
			{
				virtual uint32 get() sealed;
				virtual void set(uint32 value) sealed;
			}

			property String ^File
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property uint32 Duration
			{
				virtual uint32 get() sealed;
				virtual void set(uint32 value) sealed;
			}

			property uint32 Rate
			{
				virtual uint32 get() sealed;
				virtual void set(uint32 value) sealed;
			}

			property uint32 Bits
			{
				virtual uint32 get() sealed;
				virtual void set(uint32 value) sealed;
			}

			property uint32 Channels
			{
				virtual uint32 get() sealed;
				virtual void set(uint32 value) sealed;
			}

			property uint32 Type
			{
				virtual uint32 get() sealed;
				virtual void set(uint32 value) sealed;
			}

			property unsigned int Flag
			{
				virtual unsigned int get() sealed;
				virtual void set(unsigned int value) sealed;
			}

			property int CacheCount
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property bool IsStreaming
			{
				virtual bool get() sealed;
			}

		protected:
			property ::RefCountClass *InternalRefCountClassPointer
			{
				::RefCountClass *get() override;
			}

			property ::SoundBufferClass *InternalSoundBufferClassPointer
			{
				virtual ::SoundBufferClass *get();
			}
	};

	public interface class IStreamSoundBufferClass : public ISoundBufferClass
	{
		property IntPtr StreamSoundBufferClassPointer
		{
			IntPtr get();
		}
	};

	public ref class StreamSoundBufferClass : public SoundBufferClass, public IStreamSoundBufferClass
	{
		public:
			StreamSoundBufferClass(IntPtr pointer);

			property IntPtr StreamSoundBufferClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::SoundBufferClass *InternalSoundBufferClassPointer
			{
				::SoundBufferClass *get() override;
			}

			property ::StreamSoundBufferClass *InternalStreamSoundBufferClassPointer
			{
				virtual ::StreamSoundBufferClass *get();
			}
	};
}