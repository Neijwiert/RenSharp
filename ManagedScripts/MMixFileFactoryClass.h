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

#include "Mengine_io.h"
#include "Mengine_vector.h"
#include "IUnmanagedContainer.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <MixFileFactoryClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	public interface class IMixHeader : public IUnmanagedObject
	{
		property IntPtr MixHeaderPointer
		{
			IntPtr get();
		}

		property int ID
		{
			int get();
			void set(int value);
		}

		property int IndexOffset
		{
			int get();
			void set(int value);
		}

		property int TailerOffset
		{
			int get();
			void set(int value);
		}

		property int Zero
		{
			int get();
			void set(int value);
		}
	};

	public ref class MixHeader : public AbstractUnmanagedObject, public IMixHeader
	{
		private:
			MixHeader();

		public:
			MixHeader(IntPtr pointer);

			static IUnmanagedContainer<IMixHeader^>^ CreateMixHeader();

			bool Equals(Object^ other) override;

			property IntPtr MixHeaderPointer
			{
				virtual IntPtr get() sealed;
			}

			property int ID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int IndexOffset
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int TailerOffset
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int Zero
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::mix_header* InternalMixHeaderPointer
			{
				virtual ::mix_header* get();
			}
	};

	public interface class IMixFileFactoryClass : public IFileFactoryClass
	{
		property IntPtr MixFileFactoryClassPointer
		{
			IntPtr get();
		}

		property bool IsValid
		{
			bool get();
		}
	};

	public ref class MixFileFactoryClass : public FileFactoryClass, public IMixFileFactoryClass
	{
		public:
			interface class IFileInfoStruct : public IUnmanagedObject
			{
				property IntPtr FileInfoStructPointer
				{
					IntPtr get();
				}

				property unsigned int ID
				{
					unsigned int get();
					void set(unsigned int value);
				}

				property unsigned int Offset
				{
					unsigned int get();
					void set(unsigned int value);
				}

				property unsigned int Size
				{
					unsigned int get();
					void set(unsigned int value);
				}
			};

			ref class FileInfoStruct : public AbstractUnmanagedObject, public IFileInfoStruct
			{
				private:
					FileInfoStruct();

				public:
					FileInfoStruct(IntPtr pointer);

					static IUnmanagedContainer<IFileInfoStruct^>^ CreateFileInfoStruct();

					bool Equals(Object^ other) override;

					property IntPtr FileInfoStructPointer
					{
						virtual IntPtr get() sealed;
					}

					property unsigned int ID
					{
						virtual unsigned int get() sealed;
						virtual void set(unsigned int value) sealed;
					}

					property unsigned int Offset
					{
						virtual unsigned int get() sealed;
						virtual void set(unsigned int value) sealed;
					}

					property unsigned int Size
					{
						virtual unsigned int get() sealed;
						virtual void set(unsigned int value) sealed;
					}

				protected:
					bool InternalDestroyPointer() override;

					property ::MixFileFactoryClass::FileInfoStruct* InternalFileInfoStructPointer
					{
						virtual ::MixFileFactoryClass::FileInfoStruct* get();
					}
			};

			interface class IAddInfoStruct : public IUnmanagedObject
			{
				property IntPtr AddInfoStructPointer
				{
					IntPtr get();
				}

				property String^ Filename1
				{
					String^ get();
					void set(String^ value);
				}

				property String^ Filename2
				{
					String^ get();
					void set(String^ value);
				}
			};

			ref class AddInfoStruct : public AbstractUnmanagedObject, public IAddInfoStruct
			{
				private:
					AddInfoStruct();

				public:
					AddInfoStruct(IntPtr pointer);

					static IUnmanagedContainer<IAddInfoStruct^>^ CreateAddInfoStruct();

					bool Equals(Object^ other) override;

					property IntPtr AddInfoStructPointer
					{
						virtual IntPtr get() sealed;
					}

					property String^ Filename1
					{
						virtual String^ get() sealed;
						virtual void set(String^ value) sealed;
					}

					property String^ Filename2
					{
						virtual String^ get() sealed;
						virtual void set(String^ value) sealed;
					}

				protected:
					bool InternalDestroyPointer() override;

					property ::MixFileFactoryClass::AddInfoStruct* InternalAddInfoStructPointer
					{
						virtual ::MixFileFactoryClass::AddInfoStruct* get();
					}
			};

			MixFileFactoryClass(IntPtr pointer);

			String^ ToString() override;

			property IntPtr MixFileFactoryClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool IsValid
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

		protected:
			property ::FileFactoryClass* InternalFileFactoryClassPointer
			{
				::FileFactoryClass* get() override;
			}

			property ::MixFileFactoryClass* InternalMixFileFactoryClassPointer
			{
				virtual ::MixFileFactoryClass* get();
			}

			property IFileFactoryClass^ Factory
			{
				IFileFactoryClass^ get();
				void set(IFileFactoryClass^ value);
			}

			property IDynamicVectorClass<IFileInfoStruct^>^ FileInformation
			{
				IDynamicVectorClass<IFileInfoStruct^>^ get();
				void set(IDynamicVectorClass<IFileInfoStruct^>^ value);
			}

			property String^ MixFilename
			{
				String^ get();
				void set(String^ value);
			}

			property unsigned int UnkOffset
			{
				unsigned int get();
				void set(unsigned int value);
			}

			property unsigned int FileCount
			{
				unsigned int get();
				void set(unsigned int value);
			}

			property unsigned int MaxFilenameOffset
			{
				unsigned int get();
				void set(unsigned int value);
			}

			property IDynamicVectorClass<String^>^ Filenames
			{
				IDynamicVectorClass<String^>^ get();
				void set(IDynamicVectorClass<String^>^ value);
			}

			property IDynamicVectorClass<IAddInfoStruct^>^ AddedFiles
			{
				IDynamicVectorClass<IAddInfoStruct^>^ get();
				void set(IDynamicVectorClass<IAddInfoStruct^>^ value);
			}

			property bool FileAdded
			{
				bool get();
				void set(bool value);
			}
	};

	public interface class IMixFileCreatorFileInfoStruct : public IUnmanagedObject
	{
		property IntPtr FileInfoStructPointer
		{
			IntPtr get();
		}

		property unsigned int CRC
		{
			unsigned int get();
			void set(unsigned int value);
		}

		property unsigned int Pos
		{
			unsigned int get();
			void set(unsigned int value);
		}

		property unsigned int Size
		{
			unsigned int get();
			void set(unsigned int value);
		}

		property String^ Name
		{
			String^ get();
			void set(String^ value);
		}
	};

	public ref class MixFileCreatorFileInfoStruct : public AbstractUnmanagedObject, public IMixFileCreatorFileInfoStruct
	{
		private:
			MixFileCreatorFileInfoStruct();

		public:
			MixFileCreatorFileInfoStruct(IntPtr pointer);

			static IUnmanagedContainer<IMixFileCreatorFileInfoStruct^>^ CreateMixFileCreatorFileInfoStruct();

			String^ ToString() override;
			bool Equals(Object^ other) override;

			property IntPtr FileInfoStructPointer
			{
				virtual IntPtr get() sealed;
			}

			property unsigned int CRC
			{
				virtual unsigned int get() sealed;
				virtual void set(unsigned int value) sealed;
			}

			property unsigned int Pos
			{
				virtual unsigned int get() sealed;
				virtual void set(unsigned int value) sealed;
			}

			property unsigned int Size
			{
				virtual unsigned int get() sealed;
				virtual void set(unsigned int value) sealed;
			}

			property String^ Name
			{
				virtual String^ get() sealed;
				virtual void set(String^ value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::MixFileCreator::FileInfoStruct* InternalFileInfoStructPointer
			{
				virtual ::MixFileCreator::FileInfoStruct* get();
			}
	};

	public interface class IMixFileCreator : public IUnmanagedObject
	{
		property IntPtr MixFileCreatorPointer
		{
			IntPtr get();
		}

		property IDynamicVectorClass<IMixFileCreatorFileInfoStruct^>^ Files
		{
			IDynamicVectorClass<IMixFileCreatorFileInfoStruct^>^ get();
			void set(IDynamicVectorClass<IMixFileCreatorFileInfoStruct^>^ value);
		}

		property IFileClass^ File
		{
			IFileClass^ get();
			void set(IFileClass^ value);
		}
	};

	public ref class MixFileCreator : public AbstractUnmanagedObject, public IMixFileCreator
	{
		public:
			MixFileCreator(IntPtr pointer);

			bool Equals(Object^ other) override;

			property IntPtr MixFileCreatorPointer
			{
				virtual IntPtr get() sealed;
			}

			property IDynamicVectorClass<IMixFileCreatorFileInfoStruct^>^ Files
			{
				virtual IDynamicVectorClass<IMixFileCreatorFileInfoStruct^>^ get() sealed;
				virtual void set(IDynamicVectorClass<IMixFileCreatorFileInfoStruct^>^ value) sealed;
			}

			property IFileClass^ File
			{
				virtual IFileClass^ get() sealed;
				virtual void set(IFileClass^ value) sealed;
			}

		protected:
			property ::MixFileCreator* InternalMixFileCreatorPointer
			{
				virtual ::MixFileCreator* get();
			}
	};

	public interface class IMixClass : public IUnmanagedObject
	{
		property IntPtr MixClassPointer
		{
			IntPtr get();
		}
	};

	public ref class MixClass : public AbstractUnmanagedObject, public IMixClass
	{
		private:
			MixClass();

		public:
			MixClass(IntPtr pointer);

			static IUnmanagedContainer<IMixClass^>^ CreateMixClass();

			property IntPtr MixClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::MixClass* InternalMixClassPointer
			{
				virtual ::MixClass* get();
			}
	};
}