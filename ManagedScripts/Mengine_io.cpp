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
#include "Mengine_io.h"

#include "Imports.h"
#include "UnmanagedContainer.h"
#include "Misc.h"
#include "Mstraw.h"

using namespace System::Runtime::InteropServices;
using namespace System::Text;

namespace RenSharp
{
	ref class FileClassStream sealed : Stream
	{
		private:
			bool _disposedResources = false;
			initonly IFileClass^ _file;
			initonly bool _canRead;
			initonly bool _canWrite;

		public:
			FileClassStream(IFileClass^ file, int mode)
			{
				if (file == nullptr || file->FileClassPointer.ToPointer() == nullptr)
				{
					throw gcnew ArgumentNullException("file");
				}

				_file = file;

				if (!file->IsAvailable())
				{
					throw gcnew IOException(String::Format("File not available ({0}).", GetLastError()));
				}

				if (_file->Open(mode) != 1)
				{
					throw gcnew IOException(String::Format("Failed to open {0}.", GetLastError()));
				}

				_canRead = (mode == 1 || mode == 0);
				_canWrite = (mode == 2 || mode == 3);
			}

			~FileClassStream()
			{
				this->!FileClassStream();
			}

			void Flush() override
			{
				_file->Flush();
			}

			int Read(array<std::uint8_t>^ buffer, int offset, int count) override
			{
				if (!CanRead)
				{
					throw gcnew NotSupportedException("Reading is not supported.");
				}

				return _file->Read(buffer, offset, count);
			}

			long long Seek(long long offset, SeekOrigin origin) override
			{
				int result = _file->Seek(static_cast<int>(offset), static_cast<int>(origin));
				if (result == -1)
				{
					throw gcnew IOException(String::Format("Failed to seek {0}.", GetLastError()));
				}

				return result;
			}

			void SetLength(long long value) override
			{
				_file->SetLength(static_cast<int>(value));
			}

			void Write(array<std::uint8_t>^ buffer, int offset, int count) override
			{
				if (!CanWrite)
				{
					throw gcnew NotSupportedException("Writing is not supported.");
				}

				if (_file->Write(buffer, offset, count) != count)
				{
					throw gcnew IOException(String::Format("Failed to write {0}.", GetLastError()));
				}
			}

			property bool CanRead
			{
				bool get() override
				{
					return _canRead;
				}
			}

			property bool CanSeek
			{
				bool get() override
				{
					return true;
				}
			}

			property bool CanWrite
			{
				bool get() override
				{
					return _canWrite;
				}
			}

			property long long Length
			{
				long long get() override
				{
					return _file->Size;
				}
			}

			property long long Position
			{
				long long get() override
				{
					return _file->Tell();
				}
				void set(long long value) override
				{
					if (_file->Seek((int)value, 0) == -1)
					{
						throw gcnew IOException(String::Format("Failed to seek {0}.", GetLastError()));
					}
				}
			}

			property IFileClass^ File
			{
				IFileClass^ get()
				{
					return _file;
				}
			}
		protected:
			!FileClassStream()
			{
				if (!_disposedResources)
				{
					_file->Close();

					_disposedResources = true;
				}
			}
	};

	FileClass::FileClass()
	{

	}

	FileClass::FileClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool FileClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IFileClass ^otherThis = dynamic_cast<IFileClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return FileClassPointer.Equals(otherThis->FileClassPointer);
	}

	bool FileClass::Create()
	{
		return InternalFileClassPointer->Create();
	}

	bool FileClass::Delete()
	{
		return InternalFileClassPointer->Delete();
	}

	bool FileClass::IsAvailable(int handle)
	{
		return InternalFileClassPointer->Is_Available(handle);
	}

	bool FileClass::IsAvailable()
	{
		return InternalFileClassPointer->Is_Available();
	}

	int FileClass::Open(String ^name, int mode)
	{
		if (name == nullptr)
		{
			return InternalFileClassPointer->Open(nullptr, mode);
		}
		else
		{
			IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
			try
			{
				return InternalFileClassPointer->Open(reinterpret_cast<char *>(nameHandle.ToPointer()), mode);
			}
			finally
			{
				Marshal::FreeHGlobal(nameHandle);
			}
		}
	}

	int FileClass::Open(String ^name)
	{
		if (name == nullptr)
		{
			return InternalFileClassPointer->Open(nullptr);
		}
		else
		{
			IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
			try
			{
				return InternalFileClassPointer->Open(reinterpret_cast<char *>(nameHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(nameHandle);
			}
		}
	}

	int FileClass::Open(int mode)
	{
		return InternalFileClassPointer->Open(mode);
	}

	int FileClass::Open()
	{
		return InternalFileClassPointer->Open();
	}

	int FileClass::Read(array<std::uint8_t> ^buffer)
	{
		if (buffer == nullptr)
		{
			throw gcnew ArgumentNullException("buffer");
		}

		pin_ptr<std::uint8_t> pinnedBuffer = &buffer[0];
		std::uint8_t *bufferPtr = pinnedBuffer;

		return InternalFileClassPointer->Read(bufferPtr, buffer->Length);
	}

	int FileClass::Read(array<std::uint8_t>^ buffer, int offset, int count)
	{
		if (buffer == nullptr)
		{
			throw gcnew ArgumentNullException("buffer");
		}
		else if (offset + count > buffer->Length)
		{
			throw gcnew ArgumentException(String::Format("The sum of offset ({0}) and count ({1}) is larger than the buffer length.", offset, count));
		}
		else if (offset < 0)
		{
			throw gcnew ArgumentOutOfRangeException(String::Format("offset ({0}) is negative.", offset));
		}
		else if (count < 0)
		{
			throw gcnew ArgumentOutOfRangeException(String::Format("count ({0}) is negative.", count));
		}

		pin_ptr<std::uint8_t> pinnedBuffer = &buffer[0];
		std::uint8_t* bufferPtr = pinnedBuffer;
		bufferPtr += offset;

		return InternalFileClassPointer->Read(bufferPtr, count);
	}

	int FileClass::Seek(int offset, int origin)
	{
		return InternalFileClassPointer->Seek(offset, origin);
	}

	int FileClass::Tell()
	{
		return InternalFileClassPointer->Tell();
	}

	int FileClass::Write(array<std::uint8_t> ^buffer)
	{
		if (buffer == nullptr)
		{
			throw gcnew ArgumentNullException("buffer");
		}

		pin_ptr<std::uint8_t> pinnedBuffer = &buffer[0];
		std::uint8_t *bufferPtr = pinnedBuffer;

		return InternalFileClassPointer->Write(bufferPtr, buffer->Length);
	}

	int FileClass::Write(array<std::uint8_t>^ buffer, int offset, int count)
	{
		if (buffer == nullptr)
		{
			throw gcnew ArgumentNullException("buffer");
		}
		else if (offset + count > buffer->Length)
		{
			throw gcnew ArgumentException(String::Format("The sum of offset ({0}) and count ({1}) is larger than the buffer length.", offset, count));
		}
		else if (offset < 0)
		{
			throw gcnew ArgumentOutOfRangeException(String::Format("offset ({0}) is negative.", offset));
		}
		else if (count < 0)
		{
			throw gcnew ArgumentOutOfRangeException(String::Format("count ({0}) is negative.", count));
		}

		pin_ptr<std::uint8_t> pinnedBuffer = &buffer[0];
		std::uint8_t* bufferPtr = pinnedBuffer;
		bufferPtr += offset;

		return InternalFileClassPointer->Write(bufferPtr, count);
	}

	void FileClass::Close()
	{
		InternalFileClassPointer->Close();
	}

	void FileClass::Error(int a, int b, String ^c)
	{
		if (c == nullptr)
		{
			return InternalFileClassPointer->Error(a, b, nullptr);
		}
		else
		{
			IntPtr cHandle = Marshal::StringToHGlobalAnsi(c);
			try
			{
				return InternalFileClassPointer->Error(a, b, reinterpret_cast<char *>(cHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(cHandle);
			}
		}
	}

	void FileClass::Bias(int start, int length)
	{
		InternalFileClassPointer->Bias(start, length);
	}

	void FileClass::Flush()
	{
		if (!FlushFileBuffers(InternalFileClassPointer->Get_File_Handle()))
		{
			throw gcnew IOException(String::Format("Failed to flush ({0}).", GetLastError()));
		}
	}

	void FileClass::SetLength(int length)
	{
		auto fileHandle = InternalFileClassPointer->Get_File_Handle();
		DWORD originalPosition = SetFilePointer(fileHandle, 0, NULL, FILE_CURRENT);
		if (originalPosition == INVALID_SET_FILE_POINTER)
		{
			throw gcnew IOException(String::Format("Failed to set the file pointer ({0}).", GetLastError()));
		}

		if (SetFilePointer(fileHandle, length, nullptr, FILE_BEGIN) == INVALID_SET_FILE_POINTER)
		{
			throw gcnew IOException(String::Format("Failed to set the file pointer ({0}).", GetLastError()));
		}

		if (SetEndOfFile(fileHandle) == FALSE)
		{
			throw gcnew IOException(String::Format("Failed to set the end of the file ({0}).", GetLastError()));
		}

		if (originalPosition < static_cast<DWORD>(length))
		{
			if (SetFilePointer(fileHandle, originalPosition, nullptr, FILE_BEGIN) == INVALID_SET_FILE_POINTER)
			{
				throw gcnew IOException(String::Format("Failed to set the file pointer ({0}).", GetLastError()));
			}
		}
	}

	Stream^ FileClass::AsStream(int mode)
	{
		return gcnew FileClassStream(this, mode);
	}

	IntPtr FileClass::FileClassPointer::get()
	{
		return IntPtr(InternalFileClassPointer);
	}

	String ^FileClass::Filename::get()
	{
		auto filename = InternalFileClassPointer->File_Name();
		if (filename == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(filename);
		}
	}

	void FileClass::Filename::set(String ^value)
	{
		if (value == nullptr)
		{
			InternalFileClassPointer->Set_Name(nullptr);
		}
		else
		{
			IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
			try
			{
				InternalFileClassPointer->Set_Name(reinterpret_cast<char *>(valueHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(valueHandle);
			}
		}
	}

	bool FileClass::IsOpen::get()
	{
		return InternalFileClassPointer->Is_Open();
	}

	int FileClass::Size::get()
	{
		return InternalFileClassPointer->Size();
	}

	DateTime FileClass::DateTime::get()
	{
		unsigned long dosDateTime = InternalFileClassPointer->Get_Date_Time();
		unsigned short dosDate = (dosDateTime >> 0x10) & 0x10;
		unsigned short dosTime = dosDateTime & 0x10;

		int day = dosDate & 0x1F;
		int month = (dosDate >> 5) & 0xF;
		int yearOffset = (dosDate >> 9) & 0x7F;
		int year = yearOffset + 1980;

		int second = (dosTime & 0x1F) * 2;
		int minute = (dosTime >> 5) & 0x3F;
		int hour = (dosTime >> 11) & 0x1F;

		return System::DateTime(year, month, day, hour, minute, second);
	}

	void FileClass::DateTime::set(System::DateTime value)
	{
		if (value.Year < 1980 || value.Year > 1980 + 127)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		unsigned short dosDate = 0;
		dosDate |= value.Day;
		dosDate |= (value.Month << 5);
		dosDate |= ((value.Year - 1980) << 9);

		unsigned short dosTime = 0;
		dosTime |= (value.Second / 2);
		dosTime |= (value.Minute << 5);
		dosTime |= (value.Hour << 11);

		InternalFileClassPointer->Set_Date_Time((dosDate << 0x10) | dosTime);
	}

	IntPtr FileClass::FileHandle::get()
	{
		return IntPtr(InternalFileClassPointer->Get_File_Handle());
	}

	bool FileClass::IsHashChecked::get()
	{
		return InternalFileClassPointer->Is_Hash_Checked();
	}

	bool FileClass::InternalDestroyPointer()
	{
		Imports::DestroyFileClass(InternalFileClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::FileClass *FileClass::InternalFileClassPointer::get()
	{
		return reinterpret_cast<::FileClass *>(Pointer.ToPointer());
	}

	INIEntry::INIEntry(String ^entry, String ^value)
		: Node<IINIEntry ^>(IntPtr(Imports::CreateINIEntry(Misc::ToAnsiPointer(entry), Misc::ToAnsiPointer(value))))
	{

	}

	INIEntry::INIEntry(IntPtr pointer)
		: Node<IINIEntry ^>(pointer)
	{

	}

	String ^INIEntry::ToString()
	{
		StringBuilder ^builder = gcnew StringBuilder();
		builder->Append(Entry)->Append(" = ")->Append(Value);

		return builder->ToString();
	}

	IUnmanagedContainer<IINIEntry ^> ^INIEntry::CreateINIEntry(String ^entry, String ^value)
	{
		return gcnew UnmanagedContainer<IINIEntry ^>(gcnew INIEntry(entry, value));
	}

	IntPtr INIEntry::INIEntryPointer::get()
	{
		return IntPtr(InternalINIEntryPointer);
	}

	IList<IINIEntry ^> ^INIEntry::TMainList::get()
	{
		auto mainList = InternalINIEntryPointer->Main_List();
		if (mainList == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INIEntryList(IntPtr(mainList));
		}
	}

	IINIEntry ^INIEntry::TNext::get()
	{
		auto next = InternalINIEntryPointer->Next();
		if (next == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INIEntry(IntPtr(next));
		}
	}

	IINIEntry ^INIEntry::TNextValid::get()
	{
		auto nextValid = InternalINIEntryPointer->Next_Valid();
		if (nextValid == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INIEntry(IntPtr(nextValid));
		}
	}

	IINIEntry ^INIEntry::TPrev::get()
	{
		auto prev = InternalINIEntryPointer->Prev();
		if (prev == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INIEntry(IntPtr(prev));
		}
	}

	IINIEntry ^INIEntry::TPrevValid::get()
	{
		auto prevValid = InternalINIEntryPointer->Prev_Valid();
		if (prevValid == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INIEntry(IntPtr(prevValid));
		}
	}

	String ^INIEntry::Entry::get()
	{
		char *entry = InternalINIEntryPointer->Entry;
		if (entry == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(entry);
		}
	}

	void INIEntry::Entry::set(String ^value)
	{
		Misc::CopyTo(value, &InternalINIEntryPointer->Entry);
	}

	String ^INIEntry::Value::get()
	{
		char *value = InternalINIEntryPointer->Value;
		if (value == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(value);
		}
	}

	void INIEntry::Value::set(String ^value)
	{
		Misc::CopyTo(value, &InternalINIEntryPointer->Value);
	}

	int INIEntry::IndexId::get()
	{
		return InternalINIEntryPointer->Index_ID();
	}

	::GenericNode *INIEntry::InternalGenericNodePointer::get()
	{
		return InternalINIEntryPointer;
	}

	::INIEntry *INIEntry::InternalINIEntryPointer::get()
	{
		return reinterpret_cast<::INIEntry *>(Pointer.ToPointer());
	}

	INIEntryList::INIEntryList()
		: List<IINIEntry ^>(IntPtr(Imports::CreateINIEntryList()))
	{

	}

	INIEntryList::INIEntryList(IntPtr pointer)
		: List<IINIEntry ^>(pointer)
	{

	}

	IUnmanagedContainer<IList<IINIEntry ^> ^> ^INIEntryList::CreateINIEntryList()
	{
		return gcnew UnmanagedContainer<IList<IINIEntry ^> ^>(gcnew INIEntryList());
	}

	void INIEntryList::Delete()
	{
		InternalINIEntryListPointer->Delete();
	}

	IntPtr INIEntryList::INIEntryListPointer::get()
	{
		return IntPtr(InternalINIEntryListPointer);
	}

	IINIEntry ^INIEntryList::TFirst::get()
	{
		auto first = InternalINIEntryListPointer->First();
		if (first == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INIEntry(IntPtr(first));
		}
	}

	IINIEntry ^INIEntryList::TFirstValid::get()
	{
		auto firstValid = InternalINIEntryListPointer->First_Valid();
		if (firstValid == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INIEntry(IntPtr(firstValid));
		}
	}

	IINIEntry ^INIEntryList::TLast::get()
	{
		auto last = InternalINIEntryListPointer->Last();
		if (last == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INIEntry(IntPtr(last));
		}
	}

	IINIEntry ^INIEntryList::TLastValid::get()
	{
		auto lastValid = InternalINIEntryListPointer->Last_Valid();
		if (lastValid == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INIEntry(IntPtr(lastValid));
		}
	}

	::GenericList *INIEntryList::InternalGenericListPointer::get()
	{
		return InternalINIEntryListPointer;
	}

	::List<::INIEntry *> *INIEntryList::InternalINIEntryListPointer::get()
	{
		return reinterpret_cast<::List<::INIEntry *> *>(Pointer.ToPointer());
	}

	IntINIEntryIndexClass::IntINIEntryIndexClass()
		: IndexClass<int, IINIEntry ^>(IntPtr(Imports::CreateIntINIEntryIndexClass()))
	{

	}

	IntINIEntryIndexClass::IntINIEntryIndexClass(IntPtr pointer)
		: IndexClass<int, IINIEntry ^>(pointer)
	{

	}

	IUnmanagedContainer<IIndexClass<int, IINIEntry ^> ^> ^IntINIEntryIndexClass::CreateIntINIEntryIndexClass()
	{
		return gcnew UnmanagedContainer<IIndexClass<int, IINIEntry ^> ^>(gcnew IntINIEntryIndexClass());
	}

	bool IntINIEntryIndexClass::RemoveIndex(int id)
	{
		return InternalIntINIEntryIndexClassPointer->Remove_Index(id);
	}

	bool IntINIEntryIndexClass::IsPresent(int id)
	{
		return InternalIntINIEntryIndexClassPointer->Is_Present(id);
	}

	bool IntINIEntryIndexClass::AddIndex(int id, IINIEntry ^data)
	{
		if (data == nullptr || data->Pointer.ToPointer() == nullptr)
		{
			return InternalIntINIEntryIndexClassPointer->Add_Index(id, nullptr);
		}
		else
		{
			return InternalIntINIEntryIndexClassPointer->Add_Index(id, reinterpret_cast<::INIEntry *>(data->INIEntryPointer.ToPointer()));
		}
	}

	void IntINIEntryIndexClass::InvalidateArchive()
	{
		InternalIntINIEntryIndexClassPointer->Invalidate_Archive();
	}

	void IntINIEntryIndexClass::Clear()
	{
		InternalIntINIEntryIndexClassPointer->Clear();
	}

	bool IntINIEntryIndexClass::IsArchiveSame(int id)
	{
		return InternalIntINIEntryIndexClassPointer->Is_Archive_Same(id);
	}

	bool IntINIEntryIndexClass::IncreaseTableSize(int amount)
	{
		return InternalIntINIEntryIndexClassPointer->Increase_Table_Size(amount);
	}

	int IntINIEntryIndexClass::FetchIDByPosition(int position)
	{
		return InternalIntINIEntryIndexClassPointer->Fetch_ID_By_Position(position);
	}

	IINIEntry ^IntINIEntryIndexClass::FetchByPosition(int position)
	{
		auto value = InternalIntINIEntryIndexClassPointer->Fetch_By_Position(position);
		if (value == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INIEntry(IntPtr(value));
		}
	}

	IntPtr IntINIEntryIndexClass::IntINIEntryIndexClassPointer::get()
	{
		return IntPtr(InternalIntINIEntryIndexClassPointer);
	}

	int IntINIEntryIndexClass::Count::get()
	{
		return InternalIntINIEntryIndexClassPointer->Count();
	}

	IINIEntry ^IntINIEntryIndexClass::default::get(int key)
	{
		auto value = InternalIntINIEntryIndexClassPointer->operator[](key);
		if (value == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INIEntry(IntPtr(value));
		}
	}

	bool IntINIEntryIndexClass::InternalDestroyPointer()
	{
		Imports::DestroyIntINIEntryIndexClass(InternalIntINIEntryIndexClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::IndexClass<int, ::INIEntry *> *IntINIEntryIndexClass::InternalIntINIEntryIndexClassPointer::get()
	{
		return reinterpret_cast<::IndexClass<int, ::INIEntry *> *>(Pointer.ToPointer());
	}

	INISectionList::INISectionList()
		: List<IINISection ^>(IntPtr(Imports::CreateINISectionList()))
	{

	}

	INISectionList::INISectionList(IntPtr pointer)
		: List<IINISection ^>(pointer)
	{

	}

	IUnmanagedContainer<IList<IINISection ^> ^> ^INISectionList::CreateINISectionList()
	{
		return gcnew UnmanagedContainer<IList<IINISection ^> ^>(gcnew INISectionList());
	}

	void INISectionList::Delete()
	{
		InternalINISectionListPointer->Delete();
	}

	IntPtr INISectionList::INISectionListPointer::get()
	{
		return IntPtr(InternalINISectionListPointer);
	}

	IINISection ^INISectionList::TFirst::get()
	{
		auto first = InternalINISectionListPointer->First();
		if (first == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INISection(IntPtr(first));
		}
	}

	IINISection ^INISectionList::TFirstValid::get()
	{
		auto firstValid = InternalINISectionListPointer->First_Valid();
		if (firstValid == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INISection(IntPtr(firstValid));
		}
	}

	IINISection ^INISectionList::TLast::get()
	{
		auto last = InternalINISectionListPointer->Last();
		if (last == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INISection(IntPtr(last));
		}
	}

	IINISection ^INISectionList::TLastValid::get()
	{
		auto lastValid = InternalINISectionListPointer->Last_Valid();
		if (lastValid == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INISection(IntPtr(lastValid));
		}
	}

	::GenericList *INISectionList::InternalGenericListPointer::get()
	{
		return InternalINISectionListPointer;
	}

	::List<::INISection *> *INISectionList::InternalINISectionListPointer::get()
	{
		return reinterpret_cast<::List<::INISection *> *>(Pointer.ToPointer());
	}

	IntINISectionIndexClass::IntINISectionIndexClass()
		: IndexClass<int, IINISection ^>(IntPtr(Imports::CreateIntINISectionIndexClass()))
	{

	}

	IntINISectionIndexClass::IntINISectionIndexClass(IntPtr pointer)
		: IndexClass<int, IINISection ^>(pointer)
	{

	}

	IUnmanagedContainer<IIndexClass<int, IINISection ^> ^> ^IntINISectionIndexClass::CreateIntINISectionIndexClass()
	{
		return gcnew UnmanagedContainer<IIndexClass<int, IINISection ^> ^>(gcnew IntINISectionIndexClass());
	}

	bool IntINISectionIndexClass::RemoveIndex(int id)
	{
		return InternalIntINISectionIndexClassPointer->Remove_Index(id);
	}

	bool IntINISectionIndexClass::IsPresent(int id)
	{
		return InternalIntINISectionIndexClassPointer->Is_Present(id);
	}

	bool IntINISectionIndexClass::AddIndex(int id, IINISection ^data)
	{
		if (data == nullptr || data->Pointer.ToPointer() == nullptr)
		{
			return InternalIntINISectionIndexClassPointer->Add_Index(id, nullptr);
		}
		else
		{
			return InternalIntINISectionIndexClassPointer->Add_Index(id, reinterpret_cast<::INISection *>(data->INISectionPointer.ToPointer()));
		}
	}

	void IntINISectionIndexClass::InvalidateArchive()
	{
		InternalIntINISectionIndexClassPointer->Invalidate_Archive();
	}

	void IntINISectionIndexClass::Clear()
	{
		InternalIntINISectionIndexClassPointer->Clear();
	}

	bool IntINISectionIndexClass::IsArchiveSame(int id)
	{
		return InternalIntINISectionIndexClassPointer->Is_Archive_Same(id);
	}

	bool IntINISectionIndexClass::IncreaseTableSize(int amount)
	{
		return InternalIntINISectionIndexClassPointer->Increase_Table_Size(amount);
	}

	int IntINISectionIndexClass::FetchIDByPosition(int position)
	{
		return InternalIntINISectionIndexClassPointer->Fetch_ID_By_Position(position);
	}

	IINISection ^IntINISectionIndexClass::FetchByPosition(int position)
	{
		auto value = InternalIntINISectionIndexClassPointer->Fetch_By_Position(position);
		if (value == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INISection(IntPtr(value));
		}
	}

	IntPtr IntINISectionIndexClass::IntINISectionIndexClassPointer::get()
	{
		return IntPtr(InternalIntINISectionIndexClassPointer);
	}

	int IntINISectionIndexClass::Count::get()
	{
		return InternalIntINISectionIndexClassPointer->Count();
	}

	IINISection ^IntINISectionIndexClass::default::get(int key)
	{
		auto value = InternalIntINISectionIndexClassPointer->operator[](key);
		if (value == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INISection(IntPtr(value));
		}
	}

	bool IntINISectionIndexClass::InternalDestroyPointer()
	{
		Imports::DestroyIntINISectionIndexClass(InternalIntINISectionIndexClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::IndexClass<int, ::INISection *> *IntINISectionIndexClass::InternalIntINISectionIndexClassPointer::get()
	{
		return reinterpret_cast<::IndexClass<int, ::INISection *> *>(Pointer.ToPointer());
	}

	INISection::INISection(String ^section)
		: Node<IINISection ^>(IntPtr(Imports::CreateINISection(Misc::ToAnsiPointer(section))))
	{

	}

	INISection::INISection(IntPtr pointer)
		: Node<IINISection ^>(pointer)
	{

	}

	String ^INISection::ToString()
	{
		StringBuilder ^builder = gcnew StringBuilder();
		builder->Append(Section);

		return builder->ToString();
	}

	IUnmanagedContainer<IINISection ^> ^INISection::CreateINISection(String ^section)
	{
		return gcnew UnmanagedContainer<IINISection ^>(gcnew INISection(section));
	}

	IINIEntry ^INISection::FindEntry(String ^entry)
	{
		::INIEntry *foundEntry;
		if (entry == nullptr)
		{
			foundEntry = InternalINISectionPointer->Find_Entry(nullptr);
		}
		else
		{
			IntPtr entryPointer = Marshal::StringToHGlobalAnsi(entry);
			try
			{
				foundEntry = InternalINISectionPointer->Find_Entry(reinterpret_cast<char *>(entryPointer.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(entryPointer);
			}
		}
		
		if (foundEntry == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INIEntry(IntPtr(foundEntry));
		}
	}

	IntPtr INISection::INISectionPointer::get()
	{
		return IntPtr(InternalINISectionPointer);
	}

	IList<IINISection ^> ^INISection::TMainList::get()
	{
		auto mainList = InternalINISectionPointer->Main_List();
		if (mainList == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INISectionList(IntPtr(mainList));
		}
	}

	IINISection ^INISection::TNext::get()
	{
		auto next = InternalINISectionPointer->Next();
		if (next == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INISection(IntPtr(next));
		}
	}

	IINISection ^INISection::TNextValid::get()
	{
		auto nextValid = InternalINISectionPointer->Next_Valid();
		if (nextValid == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INISection(IntPtr(nextValid));
		}
	}

	IINISection ^INISection::TPrev::get()
	{
		auto prev = InternalINISectionPointer->Prev();
		if (prev == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INISection(IntPtr(prev));
		}
	}

	IINISection ^INISection::TPrevValid::get()
	{
		auto prevValid = InternalINISectionPointer->Prev_Valid();
		if (prevValid == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew INISection(IntPtr(prevValid));
		}
	}

	String ^INISection::Section::get()
	{
		auto section = InternalINISectionPointer->Section;
		if (section == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(section);
		}
	}

	void INISection::Section::set(String ^value)
	{
		Misc::CopyTo(value, &InternalINISectionPointer->Section);
	}

	IList<IINIEntry ^> ^INISection::EntryList::get()
	{
		return gcnew INIEntryList(IntPtr(&InternalINISectionPointer->EntryList));
	}

	IIndexClass<int, IINIEntry ^> ^INISection::EntryIndex::get()
	{
		return gcnew IntINIEntryIndexClass(IntPtr(&InternalINISectionPointer->EntryIndex));
	}

	void INISection::EntryIndex::set(IIndexClass<int, IINIEntry ^> ^value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalINISectionPointer->EntryIndex = (*reinterpret_cast<::IndexClass<int, ::INIEntry *> *>(value->Pointer.ToPointer()));
	}

	int INISection::IndexId::get()
	{
		return InternalINISectionPointer->Index_ID();
	}

	::GenericNode *INISection::InternalGenericNodePointer::get()
	{
		return InternalINISectionPointer;
	}

	::INISection *INISection::InternalINISectionPointer::get()
	{
		return reinterpret_cast<::INISection *>(Pointer.ToPointer());
	}

	INIClass::INIClass()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateINIClass1()))
	{

	}

	INIClass::INIClass(IFileClass ^file)
		: AbstractUnmanagedObject()
	{
		if (file == nullptr || file->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("file");
		}

		Pointer = IntPtr(Imports::CreateINIClass2(reinterpret_cast<::FileClass *>(file->FileClassPointer.ToPointer())));
	}

	INIClass::INIClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool INIClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IINIClass ^otherThis = dynamic_cast<IINIClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return INIClassPointer.Equals(otherThis->INIClassPointer);
	}

	IUnmanagedContainer<IINIClass ^> ^INIClass::CreateINIClass()
	{
		return gcnew UnmanagedContainer<IINIClass ^>(gcnew INIClass());
	}

	IUnmanagedContainer<IINIClass ^> ^INIClass::CreateINIClass(IFileClass ^file)
	{
		return gcnew UnmanagedContainer<IINIClass ^>(gcnew INIClass(file));
	}

	String ^INIClass::StripComments(String ^buffer)
	{
		if (buffer == nullptr)
		{
			::INIClass::Strip_Comments(nullptr);

			return nullptr;
		}
		else
		{
			IntPtr bufferHandle = Marshal::StringToHGlobalAnsi(buffer);
			try
			{
				char *bufferPtr = reinterpret_cast<char *>(bufferHandle.ToPointer());
				::INIClass::Strip_Comments(bufferPtr);

				return gcnew String(bufferPtr);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferHandle);
			}
		}
	}

	int INIClass::CRC(String ^string)
	{
		if (string == nullptr)
		{
			throw gcnew ArgumentNullException("string");
		}

		IntPtr stringHandle = Marshal::StringToHGlobalAnsi(string);
		try
		{
			return ::INIClass::CRC(reinterpret_cast<char *>(stringHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(stringHandle);
		}
	}

	void INIClass::DuplicateCRCError(String ^function, String ^message, String ^entry)
	{
		if (function == nullptr)
		{
			throw gcnew ArgumentNullException("function");
		}
		else if (message == nullptr)
		{
			throw gcnew ArgumentNullException("message");
		}
		else if (entry == nullptr)
		{
			throw gcnew ArgumentNullException("entry");
		}

		IntPtr functionHandle = Marshal::StringToHGlobalAnsi(function);
		try
		{
			IntPtr messageHandle = Marshal::StringToHGlobalAnsi(message);
			try
			{
				IntPtr entryHandle = Marshal::StringToHGlobalAnsi(entry);
				try
				{
					InternalINIClassPointer->DuplicateCRCError(
						reinterpret_cast<char *>(functionHandle.ToPointer()), 
						reinterpret_cast<char *>(messageHandle.ToPointer()), 
						reinterpret_cast<char *>(entryHandle.ToPointer()));
				}
				finally
				{
					Marshal::FreeHGlobal(entryHandle);
				}
			}
			finally
			{
				Marshal::FreeHGlobal(messageHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(functionHandle);
		}
	}

	void INIClass::Initialize()
	{
		InternalINIClassPointer->Initialize();
	}

	void INIClass::Shutdown()
	{
		InternalINIClassPointer->Shutdown();
	}

	bool INIClass::Clear(String ^section, String ^entry)
	{
		if (section == nullptr)
		{
			if (entry == nullptr)
			{
				return InternalINIClassPointer->Clear(nullptr, nullptr);
			}

			IntPtr entryPtr = Marshal::StringToHGlobalAnsi(entry);
			try
			{
				return InternalINIClassPointer->Clear(nullptr, reinterpret_cast<char *>(entryPtr.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(entryPtr);
			}
		}
		else
		{
			IntPtr sectionPtr = Marshal::StringToHGlobalAnsi(section);
			try
			{
				if (entry == nullptr)
				{
					return InternalINIClassPointer->Clear(reinterpret_cast<char *>(sectionPtr.ToPointer()), nullptr);
				}

				IntPtr entryPtr = Marshal::StringToHGlobalAnsi(entry);
				try
				{
					return InternalINIClassPointer->Clear(reinterpret_cast<char *>(sectionPtr.ToPointer()), reinterpret_cast<char *>(entryPtr.ToPointer()));
				}
				finally
				{
					Marshal::FreeHGlobal(entryPtr);
				}
			}
			finally
			{
				Marshal::FreeHGlobal(sectionPtr);
			}
		}
	}

	int INIClass::GetInt(String ^section, String ^entry, int defaultValue)
	{
		if (section == nullptr)
		{
			if (entry == nullptr)
			{
				return InternalINIClassPointer->Get_Int(nullptr, nullptr, defaultValue);
			}

			IntPtr entryPtr = Marshal::StringToHGlobalAnsi(entry);
			try
			{
				return InternalINIClassPointer->Get_Int(nullptr, reinterpret_cast<const char *>(entryPtr.ToPointer()), defaultValue);
			}
			finally
			{
				Marshal::FreeHGlobal(entryPtr);
			}
		}
		else
		{
			IntPtr sectionPtr = Marshal::StringToHGlobalAnsi(section);
			try
			{
				if (entry == nullptr)
				{
					return InternalINIClassPointer->Get_Int(reinterpret_cast<const char *>(sectionPtr.ToPointer()), nullptr, defaultValue);
				}

				IntPtr entryPtr = Marshal::StringToHGlobalAnsi(entry);
				try
				{
					return InternalINIClassPointer->Get_Int(reinterpret_cast<const char *>(sectionPtr.ToPointer()), reinterpret_cast<const char *>(entryPtr.ToPointer()), defaultValue);
				}
				finally
				{
					Marshal::FreeHGlobal(entryPtr);
				}
			}
			finally
			{
				Marshal::FreeHGlobal(sectionPtr);
			}
		}
	}

	Color INIClass::GetColor(String ^section, String ^entry, Color defaultValue)
	{
		if (section == nullptr)
		{
			if (entry == nullptr)
			{
				return Color::FromArgb(InternalINIClassPointer->Get_Color_UInt(nullptr, nullptr, static_cast<uint>(defaultValue.ToArgb())));
			}

			IntPtr entryPtr = Marshal::StringToHGlobalAnsi(entry);
			try
			{
				return Color::FromArgb(InternalINIClassPointer->Get_Color_UInt(nullptr, reinterpret_cast<const char *>(entryPtr.ToPointer()), static_cast<uint>(defaultValue.ToArgb())));
			}
			finally
			{
				Marshal::FreeHGlobal(entryPtr);
			}
		}
		else
		{
			IntPtr sectionPtr = Marshal::StringToHGlobalAnsi(section);
			try
			{
				if (entry == nullptr)
				{
					return Color::FromArgb(InternalINIClassPointer->Get_Color_UInt(reinterpret_cast<const char *>(sectionPtr.ToPointer()), nullptr, static_cast<uint>(defaultValue.ToArgb())));
				}

				IntPtr entryPtr = Marshal::StringToHGlobalAnsi(entry);
				try
				{
					return Color::FromArgb(InternalINIClassPointer->Get_Color_UInt(reinterpret_cast<const char *>(sectionPtr.ToPointer()), reinterpret_cast<const char *>(entryPtr.ToPointer()), static_cast<uint>(defaultValue.ToArgb())));
				}
				finally
				{
					Marshal::FreeHGlobal(entryPtr);
				}
			}
			finally
			{
				Marshal::FreeHGlobal(sectionPtr);
			}
		}
	}

	float INIClass::GetFloat(String ^section, String ^entry, float defaultValue)
	{
		if (section == nullptr)
		{
			if (entry == nullptr)
			{
				return InternalINIClassPointer->Get_Float(nullptr, nullptr, defaultValue);
			}

			IntPtr entryPtr = Marshal::StringToHGlobalAnsi(entry);
			try
			{
				return InternalINIClassPointer->Get_Float(nullptr, reinterpret_cast<const char *>(entryPtr.ToPointer()), defaultValue);
			}
			finally
			{
				Marshal::FreeHGlobal(entryPtr);
			}
		}
		else
		{
			IntPtr sectionPtr = Marshal::StringToHGlobalAnsi(section);
			try
			{
				if (entry == nullptr)
				{
					return InternalINIClassPointer->Get_Float(reinterpret_cast<const char *>(sectionPtr.ToPointer()), nullptr, defaultValue);
				}

				IntPtr entryPtr = Marshal::StringToHGlobalAnsi(entry);
				try
				{
					return InternalINIClassPointer->Get_Float(reinterpret_cast<const char *>(sectionPtr.ToPointer()), reinterpret_cast<const char *>(entryPtr.ToPointer()), defaultValue);
				}
				finally
				{
					Marshal::FreeHGlobal(entryPtr);
				}
			}
			finally
			{
				Marshal::FreeHGlobal(sectionPtr);
			}
		}
	}

	bool INIClass::GetBool(String ^section, String ^entry, bool defaultValue)
	{
		if (section == nullptr)
		{
			if (entry == nullptr)
			{
				return InternalINIClassPointer->Get_Bool(nullptr, nullptr, defaultValue);
			}

			IntPtr entryPtr = Marshal::StringToHGlobalAnsi(entry);
			try
			{
				return InternalINIClassPointer->Get_Bool(nullptr, reinterpret_cast<const char *>(entryPtr.ToPointer()), defaultValue);
			}
			finally
			{
				Marshal::FreeHGlobal(entryPtr);
			}
		}
		else
		{
			IntPtr sectionPtr = Marshal::StringToHGlobalAnsi(section);
			try
			{
				if (entry == nullptr)
				{
					return InternalINIClassPointer->Get_Bool(reinterpret_cast<const char *>(sectionPtr.ToPointer()), nullptr, defaultValue);
				}

				IntPtr entryPtr = Marshal::StringToHGlobalAnsi(entry);
				try
				{
					return InternalINIClassPointer->Get_Bool(reinterpret_cast<const char *>(sectionPtr.ToPointer()), reinterpret_cast<const char *>(entryPtr.ToPointer()), defaultValue);
				}
				finally
				{
					Marshal::FreeHGlobal(entryPtr);
				}
			}
			finally
			{
				Marshal::FreeHGlobal(sectionPtr);
			}
		}
	}

	String ^INIClass::GetString(String ^section, String ^entry, String ^defaultValue)
	{
		::WideStringClass result;

		if (section == nullptr)
		{
			if (entry == nullptr)
			{
				if (defaultValue == nullptr)
				{
					InternalINIClassPointer->Get_Wide_String(result, nullptr, nullptr, nullptr);
				}
				else
				{
					IntPtr defaultValueHandle = Marshal::StringToHGlobalUni(defaultValue);
					try
					{
						InternalINIClassPointer->Get_Wide_String(result, nullptr, nullptr, reinterpret_cast<wchar_t *>(defaultValueHandle.ToPointer()));
					}
					finally
					{
						Marshal::FreeHGlobal(defaultValueHandle);
					}
				}
			}
			else
			{
				IntPtr entryPtr = Marshal::StringToHGlobalAnsi(entry);
				try
				{
					if (defaultValue == nullptr)
					{
						InternalINIClassPointer->Get_Wide_String(result, nullptr, reinterpret_cast<const char *>(entryPtr.ToPointer()), nullptr);
					}
					else
					{
						IntPtr defaultValueHandle = Marshal::StringToHGlobalUni(defaultValue);
						try
						{
							InternalINIClassPointer->Get_Wide_String(result, nullptr, reinterpret_cast<const char *>(entryPtr.ToPointer()), reinterpret_cast<wchar_t *>(defaultValueHandle.ToPointer()));
						}
						finally
						{
							Marshal::FreeHGlobal(defaultValueHandle);
						}
					}
				}
				finally
				{
					Marshal::FreeHGlobal(entryPtr);
				}
			}
		}
		else
		{
			IntPtr sectionPtr = Marshal::StringToHGlobalAnsi(section);
			try
			{
				if (entry == nullptr)
				{
					if (defaultValue == nullptr)
					{
						InternalINIClassPointer->Get_Wide_String(
							result, 
							reinterpret_cast<const char *>(sectionPtr.ToPointer()), 
							nullptr, 
							nullptr);
					}
					else
					{
						IntPtr defaultValueHandle = Marshal::StringToHGlobalUni(defaultValue);
						try
						{
							InternalINIClassPointer->Get_Wide_String(
								result, 
								reinterpret_cast<const char *>(sectionPtr.ToPointer()), 
								nullptr, 
								reinterpret_cast<wchar_t *>(defaultValueHandle.ToPointer()));
						}
						finally
						{
							Marshal::FreeHGlobal(defaultValueHandle);
						}
					}
				}
				else
				{
					IntPtr entryPtr = Marshal::StringToHGlobalAnsi(entry);
					try
					{
						if (defaultValue == nullptr)
						{
							InternalINIClassPointer->Get_Wide_String(
								result, 
								reinterpret_cast<const char *>(sectionPtr.ToPointer()), 
								reinterpret_cast<const char *>(entryPtr.ToPointer()), 
								nullptr);
						}
						else
						{
							IntPtr defaultValueHandle = Marshal::StringToHGlobalUni(defaultValue);
							try
							{
								InternalINIClassPointer->Get_Wide_String(
									result, 
									reinterpret_cast<const char *>(sectionPtr.ToPointer()), 
									reinterpret_cast<const char *>(entryPtr.ToPointer()), 
									reinterpret_cast<wchar_t *>(defaultValueHandle.ToPointer()));
							}
							finally
							{
								Marshal::FreeHGlobal(defaultValueHandle);
							}
						}
					}
					finally
					{
						Marshal::FreeHGlobal(entryPtr);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(sectionPtr);
			}
		}

		return gcnew String(result.Peek_Buffer());
	}

	String ^INIClass::GetString(String ^section, String ^entry)
	{
		return GetString(section, entry, nullptr);
	}

	bool INIClass::PutString(String ^section, String ^entry, String ^string)
	{
		if (section == nullptr)
		{
			if (entry == nullptr)
			{
				if (string == nullptr)
				{
					return InternalINIClassPointer->Put_Wide_String(nullptr, nullptr, nullptr);
				}
				else
				{
					IntPtr stringHandle = Marshal::StringToHGlobalUni(string);
					try
					{
						return InternalINIClassPointer->Put_Wide_String(nullptr, nullptr, reinterpret_cast<wchar_t *>(stringHandle.ToPointer()));
					}
					finally
					{
						Marshal::FreeHGlobal(stringHandle);
					}
				}
			}

			IntPtr entryPtr = Marshal::StringToHGlobalAnsi(entry);
			try
			{
				if (string == nullptr)
				{
					return InternalINIClassPointer->Put_Wide_String(nullptr, reinterpret_cast<const char *>(entryPtr.ToPointer()), nullptr);
				}
				else
				{
					IntPtr stringHandle = Marshal::StringToHGlobalUni(string);
					try
					{
						return InternalINIClassPointer->Put_Wide_String(nullptr, reinterpret_cast<const char *>(entryPtr.ToPointer()), reinterpret_cast<wchar_t *>(stringHandle.ToPointer()));
					}
					finally
					{
						Marshal::FreeHGlobal(stringHandle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(entryPtr);
			}
		}
		else
		{
			IntPtr sectionPtr = Marshal::StringToHGlobalAnsi(section);
			try
			{
				if (entry == nullptr)
				{
					if (string == nullptr)
					{
						return InternalINIClassPointer->Put_Wide_String(reinterpret_cast<const char *>(sectionPtr.ToPointer()), nullptr, nullptr);
					}
					else
					{
						IntPtr stringHandle = Marshal::StringToHGlobalUni(string);
						try
						{
							return InternalINIClassPointer->Put_Wide_String(
								reinterpret_cast<const char *>(sectionPtr.ToPointer()), 
								nullptr, 
								reinterpret_cast<wchar_t *>(stringHandle.ToPointer()));
						}
						finally
						{
							Marshal::FreeHGlobal(stringHandle);
						}
					}
				}

				IntPtr entryPtr = Marshal::StringToHGlobalAnsi(entry);
				try
				{
					if (string == nullptr)
					{
						return InternalINIClassPointer->Put_Wide_String(
							reinterpret_cast<const char *>(sectionPtr.ToPointer()), 
							reinterpret_cast<const char *>(entryPtr.ToPointer()), 
							nullptr);
					}
					else
					{
						IntPtr stringHandle = Marshal::StringToHGlobalUni(string);
						try
						{
							return InternalINIClassPointer->Put_Wide_String(
								reinterpret_cast<const char *>(sectionPtr.ToPointer()), 
								reinterpret_cast<const char *>(entryPtr.ToPointer()), 
								reinterpret_cast<wchar_t *>(stringHandle.ToPointer()));
						}
						finally
						{
							Marshal::FreeHGlobal(stringHandle);
						}
					}
				}
				finally
				{
					Marshal::FreeHGlobal(entryPtr);
				}
			}
			finally
			{
				Marshal::FreeHGlobal(sectionPtr);
			}
		}
	}

	bool INIClass::PutInt(String ^section, String ^entry, int value, int format)
	{
		if (section == nullptr)
		{
			if (entry == nullptr)
			{
				return InternalINIClassPointer->Put_Int(nullptr, nullptr, value, static_cast<int>(format));
			}

			IntPtr entryPtr = Marshal::StringToHGlobalAnsi(entry);
			try
			{
				return InternalINIClassPointer->Put_Int(nullptr, reinterpret_cast<const char *>(entryPtr.ToPointer()), value, static_cast<int>(format));
			}
			finally
			{
				Marshal::FreeHGlobal(entryPtr);
			}
		}
		else
		{
			IntPtr sectionPtr = Marshal::StringToHGlobalAnsi(section);
			try
			{
				if (entry == nullptr)
				{
					return InternalINIClassPointer->Put_Int(reinterpret_cast<const char *>(sectionPtr.ToPointer()), nullptr, value, static_cast<int>(format));
				}

				IntPtr entryPtr = Marshal::StringToHGlobalAnsi(entry);
				try
				{
					return InternalINIClassPointer->Put_Int(reinterpret_cast<const char *>(sectionPtr.ToPointer()), reinterpret_cast<const char *>(entryPtr.ToPointer()), value, static_cast<int>(format));
				}
				finally
				{
					Marshal::FreeHGlobal(entryPtr);
				}
			}
			finally
			{
				Marshal::FreeHGlobal(sectionPtr);
			}
		}
	}

	bool INIClass::PutBool(String ^section, String ^entry, bool value)
	{
		if (section == nullptr)
		{
			if (entry == nullptr)
			{
				return InternalINIClassPointer->Put_Bool(nullptr, nullptr, value);
			}

			IntPtr entryPtr = Marshal::StringToHGlobalAnsi(entry);
			try
			{
				return InternalINIClassPointer->Put_Bool(nullptr, reinterpret_cast<const char *>(entryPtr.ToPointer()), value);
			}
			finally
			{
				Marshal::FreeHGlobal(entryPtr);
			}
		}
		else
		{
			IntPtr sectionPtr = Marshal::StringToHGlobalAnsi(section);
			try
			{
				if (entry == nullptr)
				{
					return InternalINIClassPointer->Put_Bool(reinterpret_cast<const char *>(sectionPtr.ToPointer()), nullptr, value);
				}

				IntPtr entryPtr = Marshal::StringToHGlobalAnsi(entry);
				try
				{
					return InternalINIClassPointer->Put_Bool(reinterpret_cast<const char *>(sectionPtr.ToPointer()), reinterpret_cast<const char *>(entryPtr.ToPointer()), value);
				}
				finally
				{
					Marshal::FreeHGlobal(entryPtr);
				}
			}
			finally
			{
				Marshal::FreeHGlobal(sectionPtr);
			}
		}
	}

	bool INIClass::PutFloat(String ^section, String ^entry, float value)
	{
		if (section == nullptr)
		{
			if (entry == nullptr)
			{
				return InternalINIClassPointer->Put_Float(nullptr, nullptr, value);
			}

			IntPtr entryPtr = Marshal::StringToHGlobalAnsi(entry);
			try
			{
				return InternalINIClassPointer->Put_Float(nullptr, reinterpret_cast<const char *>(entryPtr.ToPointer()), value);
			}
			finally
			{
				Marshal::FreeHGlobal(entryPtr);
			}
		}
		else
		{
			IntPtr sectionPtr = Marshal::StringToHGlobalAnsi(section);
			try
			{
				if (entry == nullptr)
				{
					return InternalINIClassPointer->Put_Float(reinterpret_cast<const char *>(sectionPtr.ToPointer()), nullptr, value);
				}

				IntPtr entryPtr = Marshal::StringToHGlobalAnsi(entry);
				try
				{
					return InternalINIClassPointer->Put_Float(reinterpret_cast<const char *>(sectionPtr.ToPointer()), reinterpret_cast<const char *>(entryPtr.ToPointer()), value);
				}
				finally
				{
					Marshal::FreeHGlobal(entryPtr);
				}
			}
			finally
			{
				Marshal::FreeHGlobal(sectionPtr);
			}
		}
	}

	int INIClass::EntryCount(String ^section)
	{
		if (section == nullptr)
		{
			return InternalINIClassPointer->Entry_Count(nullptr);
		}

		IntPtr sectionPtr = Marshal::StringToHGlobalAnsi(section);
		try
		{
			return InternalINIClassPointer->Entry_Count(reinterpret_cast<const char *>(sectionPtr.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(sectionPtr);
		}
	}

	String ^INIClass::GetEntry(String ^section, int index)
	{
		const char *result;

		if (section == nullptr)
		{
			result = InternalINIClassPointer->Get_Entry(nullptr, index);
		}
		else
		{
			IntPtr sectionPtr = Marshal::StringToHGlobalAnsi(section);
			try
			{
				result = InternalINIClassPointer->Get_Entry(reinterpret_cast<const char *>(sectionPtr.ToPointer()), index);
			}
			finally
			{
				Marshal::FreeHGlobal(sectionPtr);
			}
		}

		if (result == nullptr)
		{
			return nullptr;
		}

		return gcnew String(result);
	}

	IINIEntry ^INIClass::FindEntry(String ^section, String ^entry)
	{
		::INIEntry *result;

		if (section == nullptr)
		{
			if (entry == nullptr)
			{
				result = InternalINIClassPointer->Find_Entry(nullptr, nullptr);
			}
			else
			{
				IntPtr entryPtr = Marshal::StringToHGlobalAnsi(entry);
				try
				{
					result = InternalINIClassPointer->Find_Entry(nullptr, reinterpret_cast<const char *>(entryPtr.ToPointer()));
				}
				finally
				{
					Marshal::FreeHGlobal(entryPtr);
				}
			}
		}
		else
		{
			IntPtr sectionPtr = Marshal::StringToHGlobalAnsi(section);
			try
			{
				if (entry == nullptr)
				{
					result = InternalINIClassPointer->Find_Entry(reinterpret_cast<const char *>(sectionPtr.ToPointer()), nullptr);
				}
				else
				{
					IntPtr entryPtr = Marshal::StringToHGlobalAnsi(entry);
					try
					{
						result = InternalINIClassPointer->Find_Entry(reinterpret_cast<const char *>(sectionPtr.ToPointer()), reinterpret_cast<const char *>(entryPtr.ToPointer()));
					}
					finally
					{
						Marshal::FreeHGlobal(entryPtr);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(sectionPtr);
			}
		}

		if (result == nullptr)
		{
			return nullptr;
		}

		return gcnew INIEntry(IntPtr(result));
	}

	IINISection ^INIClass::FindSection(String ^section)
	{
		::INISection *result;
		if (section == nullptr)
		{
			result = InternalINIClassPointer->Find_Section(nullptr);
		}
		else
		{
			IntPtr sectionPtr = Marshal::StringToHGlobalAnsi(section);
			try
			{
				result = InternalINIClassPointer->Find_Section(reinterpret_cast<const char *>(sectionPtr.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(sectionPtr);
			}
		}

		if (result == nullptr)
		{
			return nullptr;
		}

		return gcnew INISection(IntPtr(result));
	}

	int INIClass::Load(IStraw ^ffile)
	{
		if (ffile == nullptr || ffile->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("ffile");
		}

		return InternalINIClassPointer->Load(*reinterpret_cast<::Straw *>(ffile->StrawPointer.ToPointer()));
	}

	int INIClass::Load(IFileClass ^file)
	{
		if (file == nullptr || file->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("file");
		}

		return InternalINIClassPointer->Load(*reinterpret_cast<::FileClass *>(file->FileClassPointer.ToPointer()));
	}

	int INIClass::Load(String ^filename)
	{
		if (filename == nullptr)
		{
			throw gcnew ArgumentNullException("filename");
		}

		IntPtr filenameHandle = Marshal::StringToHGlobalAnsi(filename);
		try
		{
			return InternalINIClassPointer->Load(reinterpret_cast<char *>(filenameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(filenameHandle);
		}
	}

	int INIClass::Save(IFileClass ^file)
	{
		if (file == nullptr || file->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("file");
		}

		return InternalINIClassPointer->Save(*reinterpret_cast<::FileClass *>(file->FileClassPointer.ToPointer()));
	}

	int INIClass::Save(IPipe ^pipe)
	{
		if (pipe == nullptr || pipe->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("pipe");
		}

		return InternalINIClassPointer->Save(*reinterpret_cast<::Pipe *>(pipe->PipePointer.ToPointer()));
	}

	bool INIClass::IsPresent(String ^section, String ^entry)
	{
		if (section == nullptr)
		{
			if (entry == nullptr)
			{
				return InternalINIClassPointer->Is_Present(nullptr, nullptr);
			}

			IntPtr entryPtr = Marshal::StringToHGlobalAnsi(entry);
			try
			{
				return InternalINIClassPointer->Is_Present(nullptr, reinterpret_cast<const char *>(entryPtr.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(entryPtr);
			}
		}
		else
		{
			IntPtr sectionPtr = Marshal::StringToHGlobalAnsi(section);
			try
			{
				if (entry == nullptr)
				{
					return InternalINIClassPointer->Is_Present(reinterpret_cast<const char *>(sectionPtr.ToPointer()), nullptr);
				}

				IntPtr entryPtr = Marshal::StringToHGlobalAnsi(entry);
				try
				{
					return InternalINIClassPointer->Is_Present(reinterpret_cast<const char *>(sectionPtr.ToPointer()), reinterpret_cast<const char *>(entryPtr.ToPointer()));
				}
				finally
				{
					Marshal::FreeHGlobal(entryPtr);
				}
			}
			finally
			{
				Marshal::FreeHGlobal(sectionPtr);
			}
		}
	}

	bool INIClass::SectionPresent(String ^section)
	{
		if (section == nullptr)
		{
			return InternalINIClassPointer->Section_Present(nullptr);
		}

		IntPtr sectionPtr = Marshal::StringToHGlobalAnsi(section);
		try
		{
			return InternalINIClassPointer->Section_Present(reinterpret_cast<const char *>(sectionPtr.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(sectionPtr);
		}
	}

	IntPtr INIClass::INIClassPointer::get()
	{
		return IntPtr(InternalINIClassPointer);
	}

	int INIClass::SectionCount::get()
	{
		return InternalINIClassPointer->Section_Count();
	}

	IList<IINISection ^> ^INIClass::SectionList::get()
	{
		return gcnew INISectionList(IntPtr(&InternalINIClassPointer->Get_Section_List()));
	}

	IIndexClass<int, IINISection ^> ^INIClass::SectionIndex::get()
	{
		return gcnew IntINISectionIndexClass(IntPtr(&InternalINIClassPointer->Get_Section_Index()));
	}

	void INIClass::SectionIndex::set(IIndexClass<int, IINISection ^> ^value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto &sectionIndex = InternalINIClassPointer->Get_Section_Index();
		sectionIndex = (*reinterpret_cast<::IndexClass<int, ::INISection *> *>(value->Pointer.ToPointer()));
	}

	bool INIClass::InternalDestroyPointer()
	{
		Imports::DestroyINIClass(InternalINIClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::INIClass *INIClass::InternalINIClassPointer::get()
	{
		return reinterpret_cast<::INIClass *>(Pointer.ToPointer());
	}

	FileFactoryClass::FileFactoryClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool FileFactoryClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IFileFactoryClass ^otherThis = dynamic_cast<IFileFactoryClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return FileFactoryClassPointer.Equals(otherThis->FileFactoryClassPointer);
	}

	IFileClass ^FileFactoryClass::GetFile(String ^filename)
	{
		if (filename == nullptr)
		{
			throw gcnew ArgumentNullException("filename");
		}

		IntPtr filenameHandle = Marshal::StringToHGlobalAnsi(filename);
		try
		{
			::FileClass *result = InternalFileFactoryClassPointer->Get_File(reinterpret_cast<char *>(filenameHandle.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew FileClass(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(filenameHandle);
		}
	}

	void FileFactoryClass::ReturnFile(IFileClass ^file)
	{
		if (file == nullptr || file->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("file");
		}

		InternalFileFactoryClassPointer->Return_File(reinterpret_cast<::FileClass *>(file->FileClassPointer.ToPointer()));
	}

	IntPtr FileFactoryClass::FileFactoryClassPointer::get()
	{
		return IntPtr(InternalFileFactoryClassPointer);
	}

	bool FileFactoryClass::InternalDestroyPointer()
	{
		Imports::DestroyFileFactoryClass(InternalFileFactoryClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::FileFactoryClass *FileFactoryClass::InternalFileFactoryClassPointer::get()
	{
		return reinterpret_cast<::FileFactoryClass *>(Pointer.ToPointer());
	}
}