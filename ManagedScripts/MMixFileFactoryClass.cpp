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
#include "MMixFileFactoryClass.h"

#include "MMixFileFactoryClassFileInfoStructDynamicVectorClass.h"
#include "MMixFileFactoryClassAddInfoStructDynamicVectorClass.h"
#include "MMixFileCreatorFileInfoStructDynamicVectorClass.h"
#include "MStringClassDynamicVectorClass.h"
#include "Imports.h"
#include "UnmanagedContainer.h"

using namespace System::Text;

namespace RenSharp
{

#pragma managed(push, off)

	class MixFileFactoryClassHelper : public ::MixFileFactoryClass 
	{
		private:
			MixFileFactoryClassHelper(const char* filePath, ::FileFactoryClass* parentFileFactory)
				: ::MixFileFactoryClass(filePath, parentFileFactory)
			{

			}

		public:
			::FileFactoryClass*& GetFactory()
			{
				return Factory;
			}

			::DynamicVectorClass<::MixFileFactoryClass::FileInfoStruct>& GetFileInformation()
			{
				return FileInformation;
			}

			::StringClass& GetMixFilename()
			{
				return MixFilename;
			}

			unsigned int& GetUnkOffset()
			{
				return UnkOffset;
			}

			unsigned int& GetFileCount()
			{
				return FileCount;
			}

			unsigned int& GetMixFilenameOffset()
			{
				return MixFilenameOffset;
			}

			bool& GetIsValid()
			{
				return IsValid;
			}

			::DynamicVectorClass<::StringClass>& GetFilenames()
			{
				return Filenames;
			}

			::DynamicVectorClass<::MixFileFactoryClass::AddInfoStruct>& GetAddedFiles()
			{
				return AddedFiles;
			}

			bool& GetFileAdded()
			{
				return FileAdded;
			}
	};

#pragma managed(pop)

	MixHeader::MixHeader()
		: AbstractUnmanagedObject(IntPtr(Imports::Createmix_header()))
	{

	}

	MixHeader::MixHeader(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IMixHeader^>^ MixHeader::CreateMixHeader()
	{
		return gcnew UnmanagedContainer<IMixHeader^>(gcnew MixHeader());
	}

	bool MixHeader::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IMixHeader^ otherThis = dynamic_cast<IMixHeader^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return MixHeaderPointer.Equals(otherThis->MixHeaderPointer);
	}

	IntPtr MixHeader::MixHeaderPointer::get()
	{
		return IntPtr(InternalMixHeaderPointer);
	}

	int MixHeader::ID::get()
	{
		return InternalMixHeaderPointer->id;
	}

	void MixHeader::ID::set(int value)
	{
		InternalMixHeaderPointer->id = value;
	}

	int MixHeader::IndexOffset::get()
	{
		return InternalMixHeaderPointer->index_offset;
	}

	void MixHeader::IndexOffset::set(int value)
	{
		InternalMixHeaderPointer->index_offset = value;
	}

	int MixHeader::TailerOffset::get()
	{
		return InternalMixHeaderPointer->tailer_offset;
	}

	void MixHeader::TailerOffset::set(int value)
	{
		InternalMixHeaderPointer->tailer_offset = value;
	}

	int MixHeader::Zero::get()
	{
		return InternalMixHeaderPointer->zero;
	}

	void MixHeader::Zero::set(int value)
	{
		InternalMixHeaderPointer->zero = value;
	}

	bool MixHeader::InternalDestroyPointer()
	{
		Imports::Destroymix_header(InternalMixHeaderPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::mix_header* MixHeader::InternalMixHeaderPointer::get()
	{
		return reinterpret_cast<::mix_header*>(Pointer.ToPointer());
	}

	MixFileFactoryClass::FileInfoStruct::FileInfoStruct()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateMixFileFactoryClassFileInfoStruct()))
	{

	}

	MixFileFactoryClass::FileInfoStruct::FileInfoStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<MixFileFactoryClass::IFileInfoStruct^>^ MixFileFactoryClass::FileInfoStruct::CreateFileInfoStruct()
	{
		return gcnew UnmanagedContainer<MixFileFactoryClass::IFileInfoStruct^>(gcnew MixFileFactoryClass::FileInfoStruct());
	}

	bool MixFileFactoryClass::FileInfoStruct::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		MixFileFactoryClass::IFileInfoStruct^ otherThis = dynamic_cast<MixFileFactoryClass::IFileInfoStruct^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return FileInfoStructPointer.Equals(otherThis->FileInfoStructPointer);
	}

	IntPtr MixFileFactoryClass::FileInfoStruct::FileInfoStructPointer::get()
	{
		return IntPtr(InternalFileInfoStructPointer);
	}

	unsigned int MixFileFactoryClass::FileInfoStruct::ID::get()
	{
		return InternalFileInfoStructPointer->id;
	}

	void MixFileFactoryClass::FileInfoStruct::ID::set(unsigned int value)
	{
		InternalFileInfoStructPointer->id = value;
	}

	unsigned int MixFileFactoryClass::FileInfoStruct::Offset::get()
	{
		return InternalFileInfoStructPointer->offset;
	}

	void MixFileFactoryClass::FileInfoStruct::Offset::set(unsigned int value)
	{
		InternalFileInfoStructPointer->offset = value;
	}

	unsigned int MixFileFactoryClass::FileInfoStruct::Size::get()
	{
		return InternalFileInfoStructPointer->size;
	}

	void MixFileFactoryClass::FileInfoStruct::Size::set(unsigned int value)
	{
		InternalFileInfoStructPointer->size = value;
	}

	bool MixFileFactoryClass::FileInfoStruct::InternalDestroyPointer()
	{
		Imports::DestroyMixFileFactoryClassFileInfoStruct(InternalFileInfoStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::MixFileFactoryClass::FileInfoStruct* MixFileFactoryClass::FileInfoStruct::InternalFileInfoStructPointer::get()
	{
		return reinterpret_cast<::MixFileFactoryClass::FileInfoStruct*>(Pointer.ToPointer());
	}

	MixFileFactoryClass::AddInfoStruct::AddInfoStruct()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateMixFileFactoryClassAddInfoStruct()))
	{

	}

	MixFileFactoryClass::AddInfoStruct::AddInfoStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<MixFileFactoryClass::IAddInfoStruct^>^ MixFileFactoryClass::AddInfoStruct::CreateAddInfoStruct()
	{
		return gcnew UnmanagedContainer<MixFileFactoryClass::IAddInfoStruct^>(gcnew MixFileFactoryClass::AddInfoStruct());
	}

	bool MixFileFactoryClass::AddInfoStruct::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		MixFileFactoryClass::IAddInfoStruct^ otherThis = dynamic_cast<MixFileFactoryClass::IAddInfoStruct^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return AddInfoStructPointer.Equals(otherThis->AddInfoStructPointer);
	}

	IntPtr MixFileFactoryClass::AddInfoStruct::AddInfoStructPointer::get()
	{
		return IntPtr(InternalAddInfoStructPointer);
	}

	String^ MixFileFactoryClass::AddInfoStruct::Filename1::get()
	{
		return gcnew String(InternalAddInfoStructPointer->Filename1.Peek_Buffer());
	}

	void MixFileFactoryClass::AddInfoStruct::Filename1::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalAddInfoStructPointer->Filename1 = reinterpret_cast<char*>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	String^ MixFileFactoryClass::AddInfoStruct::Filename2::get()
	{
		return gcnew String(InternalAddInfoStructPointer->Filename2.Peek_Buffer());
	}

	void MixFileFactoryClass::AddInfoStruct::Filename2::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalAddInfoStructPointer->Filename2 = reinterpret_cast<char*>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	bool MixFileFactoryClass::AddInfoStruct::InternalDestroyPointer()
	{
		Imports::DestroyMixFileFactoryClassAddInfoStruct(InternalAddInfoStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::MixFileFactoryClass::AddInfoStruct* MixFileFactoryClass::AddInfoStruct::InternalAddInfoStructPointer::get()
	{
		return reinterpret_cast<::MixFileFactoryClass::AddInfoStruct*>(Pointer.ToPointer());
	}

	MixFileFactoryClass::MixFileFactoryClass(IntPtr pointer)
		: FileFactoryClass(pointer)
	{

	}

	String^ MixFileFactoryClass::ToString()
	{
		StringBuilder^ builder = gcnew StringBuilder();
		builder->Append(MixFilename);

		return builder->ToString();
	}

	IntPtr MixFileFactoryClass::MixFileFactoryClassPointer::get()
	{
		return IntPtr(InternalMixFileFactoryClassPointer);
	}

	bool MixFileFactoryClass::IsValid::get()
	{
		return InternalMixFileFactoryClassPointer->Is_Valid();
	}

	void MixFileFactoryClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<MixFileFactoryClassHelper*>(InternalMixFileFactoryClassPointer);

		auto& isValid = helper->GetIsValid();

		isValid = value;
	}

	::FileFactoryClass* MixFileFactoryClass::InternalFileFactoryClassPointer::get()
	{
		return InternalMixFileFactoryClassPointer;
	}

	::MixFileFactoryClass* MixFileFactoryClass::InternalMixFileFactoryClassPointer::get()
	{
		return reinterpret_cast<::MixFileFactoryClass*>(Pointer.ToPointer());
	}

	IFileFactoryClass^ MixFileFactoryClass::Factory::get()
	{
		auto helper = reinterpret_cast<MixFileFactoryClassHelper*>(InternalMixFileFactoryClassPointer);

		auto& factory = helper->GetFactory();

		if (factory == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew FileFactoryClass(IntPtr(factory));
		}
	}

	void MixFileFactoryClass::Factory::set(IFileFactoryClass^ value)
	{
		auto helper = reinterpret_cast<MixFileFactoryClassHelper*>(InternalMixFileFactoryClassPointer);

		auto& factory = helper->GetFactory();

		if (value == nullptr || value->FileFactoryClassPointer.ToPointer() == nullptr)
		{
			factory = nullptr;
		}
		else
		{
			factory = reinterpret_cast<::FileFactoryClass*>(value->FileFactoryClassPointer.ToPointer());
		}
	}

	IDynamicVectorClass<MixFileFactoryClass::IFileInfoStruct^>^ MixFileFactoryClass::FileInformation::get()
	{
		auto helper = reinterpret_cast<MixFileFactoryClassHelper*>(InternalMixFileFactoryClassPointer);

		auto& fileInformation = helper->GetFileInformation();

		return gcnew MixFileFactoryClassFileInfoStructDynamicVectorClass(IntPtr(&fileInformation));
	}

	void MixFileFactoryClass::FileInformation::set(IDynamicVectorClass<IFileInfoStruct^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<MixFileFactoryClassHelper*>(InternalMixFileFactoryClassPointer);

		auto& fileInformation = helper->GetFileInformation();

		fileInformation = *reinterpret_cast<::DynamicVectorClass<::MixFileFactoryClass::FileInfoStruct>*>(value->Pointer.ToPointer());
	}

	String^ MixFileFactoryClass::MixFilename::get()
	{
		auto helper = reinterpret_cast<MixFileFactoryClassHelper*>(InternalMixFileFactoryClassPointer);

		auto& mixFilename = helper->GetMixFilename();

		return gcnew String(mixFilename.Peek_Buffer());
	}

	void MixFileFactoryClass::MixFilename::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<MixFileFactoryClassHelper*>(InternalMixFileFactoryClassPointer);

		auto& mixFilename = helper->GetMixFilename();

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			mixFilename = reinterpret_cast<char*>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	unsigned int MixFileFactoryClass::UnkOffset::get()
	{
		auto helper = reinterpret_cast<MixFileFactoryClassHelper*>(InternalMixFileFactoryClassPointer);

		auto& unkOffset = helper->GetUnkOffset();

		return unkOffset;
	}

	void MixFileFactoryClass::UnkOffset::set(unsigned int value)
	{
		auto helper = reinterpret_cast<MixFileFactoryClassHelper*>(InternalMixFileFactoryClassPointer);

		auto& unkOffset = helper->GetUnkOffset();

		unkOffset = value;
	}

	unsigned int MixFileFactoryClass::FileCount::get()
	{
		auto helper = reinterpret_cast<MixFileFactoryClassHelper*>(InternalMixFileFactoryClassPointer);

		auto& fileCount = helper->GetFileCount();

		return fileCount;
	}

	void MixFileFactoryClass::FileCount::set(unsigned int value)
	{
		auto helper = reinterpret_cast<MixFileFactoryClassHelper*>(InternalMixFileFactoryClassPointer);

		auto& fileCount = helper->GetFileCount();

		fileCount = value;
	}

	unsigned int MixFileFactoryClass::MaxFilenameOffset::get()
	{
		auto helper = reinterpret_cast<MixFileFactoryClassHelper*>(InternalMixFileFactoryClassPointer);

		auto& maxFilenameOffset = helper->GetMixFilenameOffset();

		return maxFilenameOffset;
	}

	void MixFileFactoryClass::MaxFilenameOffset::set(unsigned int value)
	{
		auto helper = reinterpret_cast<MixFileFactoryClassHelper*>(InternalMixFileFactoryClassPointer);

		auto& maxFilenameOffset = helper->GetMixFilenameOffset();

		maxFilenameOffset = value;
	}

	IDynamicVectorClass<String^>^ MixFileFactoryClass::Filenames::get()
	{
		auto helper = reinterpret_cast<MixFileFactoryClassHelper*>(InternalMixFileFactoryClassPointer);

		auto& filenames = helper->GetFilenames();

		return gcnew StringClassDynamicVectorClass(IntPtr(&filenames));
	}

	void MixFileFactoryClass::Filenames::set(IDynamicVectorClass<String^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<MixFileFactoryClassHelper*>(InternalMixFileFactoryClassPointer);

		auto& filenames = helper->GetFilenames();

		filenames = *reinterpret_cast<::DynamicVectorClass<::StringClass>*>(value->Pointer.ToPointer());
	}

	IDynamicVectorClass<MixFileFactoryClass::IAddInfoStruct^>^ MixFileFactoryClass::AddedFiles::get()
	{
		auto helper = reinterpret_cast<MixFileFactoryClassHelper*>(InternalMixFileFactoryClassPointer);

		auto& addedFiles = helper->GetAddedFiles();

		return gcnew MixFileFactoryClassAddInfoStructDynamicVectorClass(IntPtr(&addedFiles));
	}

	void MixFileFactoryClass::AddedFiles::set(IDynamicVectorClass<IAddInfoStruct^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<MixFileFactoryClassHelper*>(InternalMixFileFactoryClassPointer);

		auto& addedFiles = helper->GetAddedFiles();

		addedFiles = *reinterpret_cast<::DynamicVectorClass<::MixFileFactoryClass::AddInfoStruct>*>(value->Pointer.ToPointer());
	}

	bool MixFileFactoryClass::FileAdded::get()
	{
		auto helper = reinterpret_cast<MixFileFactoryClassHelper*>(InternalMixFileFactoryClassPointer);

		auto& fileAdded = helper->GetFileAdded();

		return fileAdded;
	}

	void MixFileFactoryClass::FileAdded::set(bool value)
	{
		auto helper = reinterpret_cast<MixFileFactoryClassHelper*>(InternalMixFileFactoryClassPointer);

		auto& fileAdded = helper->GetFileAdded();

		fileAdded = value;
	}

	MixFileCreatorFileInfoStruct::MixFileCreatorFileInfoStruct()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateMixFileCreatorFileInfoStruct()))
	{

	}

	MixFileCreatorFileInfoStruct::MixFileCreatorFileInfoStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IMixFileCreatorFileInfoStruct^>^ MixFileCreatorFileInfoStruct::CreateMixFileCreatorFileInfoStruct()
	{
		return gcnew UnmanagedContainer<IMixFileCreatorFileInfoStruct^>(gcnew MixFileCreatorFileInfoStruct());
	}

	String^ MixFileCreatorFileInfoStruct::ToString()
	{
		StringBuilder^ builder = gcnew StringBuilder();
		builder->Append(Name);

		return builder->ToString();
	}

	bool MixFileCreatorFileInfoStruct::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IMixFileCreatorFileInfoStruct^ otherThis = dynamic_cast<IMixFileCreatorFileInfoStruct^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return FileInfoStructPointer.Equals(otherThis->FileInfoStructPointer);
	}

	IntPtr MixFileCreatorFileInfoStruct::FileInfoStructPointer::get()
	{
		return IntPtr(InternalFileInfoStructPointer);
	}

	unsigned int MixFileCreatorFileInfoStruct::CRC::get()
	{
		return InternalFileInfoStructPointer->CRC;
	}

	void MixFileCreatorFileInfoStruct::CRC::set(unsigned int value)
	{
		InternalFileInfoStructPointer->CRC = value;
	}

	unsigned int MixFileCreatorFileInfoStruct::Pos::get()
	{
		return InternalFileInfoStructPointer->pos;
	}

	void MixFileCreatorFileInfoStruct::Pos::set(unsigned int value)
	{
		InternalFileInfoStructPointer->pos = value;
	}

	unsigned int MixFileCreatorFileInfoStruct::Size::get()
	{
		return InternalFileInfoStructPointer->size;
	}

	void MixFileCreatorFileInfoStruct::Size::set(unsigned int value)
	{
		InternalFileInfoStructPointer->size = value;
	}

	String^ MixFileCreatorFileInfoStruct::Name::get()
	{
		return gcnew String(InternalFileInfoStructPointer->name.Peek_Buffer());
	}

	void MixFileCreatorFileInfoStruct::Name::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalFileInfoStructPointer->name = reinterpret_cast<char*>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	bool MixFileCreatorFileInfoStruct::InternalDestroyPointer()
	{
		Imports::DestroyMixFileCreatorFileInfoStruct(InternalFileInfoStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::MixFileCreator::FileInfoStruct* MixFileCreatorFileInfoStruct::InternalFileInfoStructPointer::get()
	{
		return reinterpret_cast<::MixFileCreator::FileInfoStruct*>(Pointer.ToPointer());
	}

	MixFileCreator::MixFileCreator(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool MixFileCreator::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IMixFileCreator^ otherThis = dynamic_cast<IMixFileCreator^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return MixFileCreatorPointer.Equals(otherThis->MixFileCreatorPointer);
	}

	IntPtr MixFileCreator::MixFileCreatorPointer::get()
	{
		return IntPtr(InternalMixFileCreatorPointer);
	}

	IDynamicVectorClass<IMixFileCreatorFileInfoStruct^>^ MixFileCreator::Files::get()
	{
		return gcnew MixFileCreatorFileInfoStructDynamicVectorClass(IntPtr(&InternalMixFileCreatorPointer->Files));
	}

	void MixFileCreator::Files::set(IDynamicVectorClass<IMixFileCreatorFileInfoStruct^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalMixFileCreatorPointer->Files = *reinterpret_cast<::DynamicVectorClass<::MixFileCreator::FileInfoStruct>*>(value->Pointer.ToPointer());
	}

	IFileClass^ MixFileCreator::File::get()
	{
		auto result = InternalMixFileCreatorPointer->File;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew FileClass(IntPtr(result));
		}
	}

	void MixFileCreator::File::set(IFileClass^ value)
	{
		if (value == nullptr || value->FileClassPointer.ToPointer() == nullptr)
		{
			InternalMixFileCreatorPointer->File = nullptr;
		}
		else
		{
			InternalMixFileCreatorPointer->File = reinterpret_cast<::FileClass*>(value->FileClassPointer.ToPointer());
		}
	}

	::MixFileCreator* MixFileCreator::InternalMixFileCreatorPointer::get()
	{
		return reinterpret_cast<::MixFileCreator*>(Pointer.ToPointer());
	}

	MixClass::MixClass()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateMixClass()))
	{

	}

	MixClass::MixClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IMixClass^>^ MixClass::CreateMixClass()
	{
		return gcnew UnmanagedContainer<IMixClass^>(gcnew MixClass());
	}

	IntPtr MixClass::MixClassPointer::get()
	{
		return IntPtr(InternalMixClassPointer);
	}

	bool MixClass::InternalDestroyPointer()
	{
		Imports::DestroyMixClass(InternalMixClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::MixClass* MixClass::InternalMixClassPointer::get()
	{
		return reinterpret_cast<::MixClass*>(Pointer.ToPointer());
	}
}