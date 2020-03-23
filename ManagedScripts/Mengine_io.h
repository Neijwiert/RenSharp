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
#include "AbstractUnmanagedObject.h"
#include "IUnmanagedContainer.h"

using namespace System;
using namespace System::Diagnostics;
using namespace System::IO;
using namespace System::Drawing;

struct INIEntry;

namespace RenSharp
{
	interface class IStraw;
	interface class IPipe;

	public interface class IFileClass : public IUnmanagedObject
	{
		bool Create();

		bool Delete();

		bool IsAvailable(int handle);

		bool IsAvailable();

		int Open(String ^name, int mode);

		int Open(String ^name);

		int Open(int mode);

		int Open();

		int Read(array<std::uint8_t> ^buffer);

		int Read(array<std::uint8_t>^ buffer, int offset, int count);

		int Seek(int offset, int origin);

		int Tell();

		int Write(array<std::uint8_t> ^buffer);

		int Write(array<std::uint8_t>^ buffer, int offset, int count);

		void Close();

		void Error(int a, int b, String ^c);

		void Bias(int start, int length);

		void Flush();

		void SetLength(int length);

		System::IO::Stream^ AsStream(int mode);

		property IntPtr FileClassPointer
		{
			IntPtr get();
		}

		property String ^Filename
		{
			String ^get();
			void set(String ^value);
		}

		property bool IsOpen
		{
			bool get();
		}

		property int Size
		{
			int get();
		}

		property DateTime DateTime
		{
			System::DateTime get();
			void set(System::DateTime value);
		}

		property IntPtr FileHandle
		{
			IntPtr get();
		}

		property bool IsHashChecked
		{
			bool get();
		}
	};

	public ref class FileClass : public AbstractUnmanagedObject, public IFileClass
	{
		protected:
			FileClass();

		public:
			FileClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual bool Create() sealed;
			virtual bool Delete() sealed;
			virtual bool IsAvailable(int handle) sealed;
			virtual bool IsAvailable() sealed;
			virtual int Open(String ^name, int mode) sealed;
			virtual int Open(String ^name) sealed;
			virtual int Open(int mode) sealed;
			virtual int Open() sealed;
			virtual int Read(array<std::uint8_t> ^buffer) sealed;
			virtual int Read(array<std::uint8_t>^ buffer, int offset, int count) sealed;
			virtual int Seek(int offset, int origin) sealed;
			virtual int Tell() sealed;
			virtual int Write(array<std::uint8_t> ^buffer) sealed;
			virtual int Write(array<std::uint8_t>^ buffer, int offset, int count) sealed;
			virtual void Close() sealed;
			virtual void Error(int a, int b, String ^c) sealed;
			virtual void Bias(int start, int length) sealed;
			virtual void Flush() sealed;
			virtual void SetLength(int length) sealed;
			virtual System::IO::Stream^ AsStream(int mode) sealed;

			property IntPtr FileClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property String ^Filename
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property bool IsOpen
			{
				virtual bool get() sealed;
			}

			property int Size
			{
				virtual int get() sealed;
			}

			property DateTime DateTime
			{
				virtual System::DateTime get() sealed;
				virtual void set(System::DateTime value) sealed;
			}

			property IntPtr FileHandle
			{
				virtual IntPtr get() sealed;
			}

			property bool IsHashChecked
			{
				virtual bool get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::FileClass *InternalFileClassPointer
			{
				virtual ::FileClass *get();
			}
	};

	public interface class IINIEntry : public INode<IINIEntry ^>
	{
		property IntPtr INIEntryPointer
		{
			IntPtr get();
		}

		property String ^Entry
		{
			String ^get();
			void set(String ^value);
		}

		property String ^Value
		{
			String ^get();
			void set(String ^value);
		}

		property int IndexId
		{
			int get();
		}
	};

	public ref class INIEntry : public Node<IINIEntry ^>, public IINIEntry
	{
		private:
			INIEntry(String ^entry, String ^value);

		public:
			INIEntry(IntPtr pointer);
			
			String ^ToString() override;

			static IUnmanagedContainer<IINIEntry ^> ^CreateINIEntry(String ^entry, String ^value);
			
			property IntPtr INIEntryPointer
			{
				virtual IntPtr get() sealed;
			}

			[DebuggerBrowsable(DebuggerBrowsableState::Never)]
			[Obsolete("This property is unsafe", true)]
			property IList<IINIEntry ^> ^TMainList
			{
				IList<IINIEntry ^> ^get() override sealed;
			}

			property IINIEntry ^TNext
			{
				virtual IINIEntry ^get() override sealed;
			}

			property IINIEntry ^TNextValid
			{
				virtual IINIEntry ^get() override sealed;
			}

			property IINIEntry ^TPrev
			{
				virtual IINIEntry ^get() override sealed;
			}

			property IINIEntry ^TPrevValid
			{
				virtual IINIEntry ^get() override sealed;
			}

			property String ^Entry
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property String ^Value
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property int IndexId
			{
				virtual int get() sealed;
			}

		protected:
			property ::GenericNode *InternalGenericNodePointer
			{
				::GenericNode *get() override;
			}

			property ::INIEntry *InternalINIEntryPointer
			{
				virtual ::INIEntry *get();
			}
	};

	public ref class INIEntryList : public List<IINIEntry ^>
	{
		private:
			INIEntryList();

		public:
			INIEntryList(IntPtr pointer);

			static IUnmanagedContainer<IList<IINIEntry ^> ^> ^CreateINIEntryList();

			void Delete() override sealed;

			property IntPtr INIEntryListPointer
			{
				IntPtr get();
			}

			property IINIEntry ^TFirst
			{
				IINIEntry ^get() override sealed;
			}

			property IINIEntry ^TFirstValid
			{
				IINIEntry ^get() override sealed;
			}

			property IINIEntry ^TLast
			{
				IINIEntry ^get() override sealed;
			}

			property IINIEntry ^TLastValid
			{
				IINIEntry ^get() override sealed;
			}

		protected:
			property ::GenericList *InternalGenericListPointer
			{
				::GenericList *get() override;
			}

			property ::List<::INIEntry *> *InternalINIEntryListPointer
			{
				virtual ::List<::INIEntry *> *get();
			}
	};

	public ref class IntINIEntryIndexClass : public IndexClass<int, IINIEntry ^>
	{
		private:
			IntINIEntryIndexClass();

		public:
			IntINIEntryIndexClass(IntPtr pointer);

			static IUnmanagedContainer<IIndexClass<int, IINIEntry ^> ^> ^CreateIntINIEntryIndexClass();

			bool RemoveIndex(int id) override sealed;
			bool IsPresent(int id) override sealed;
			bool AddIndex(int id, IINIEntry ^data) override sealed;
			void InvalidateArchive() override sealed;
			void Clear() override sealed;
			bool IsArchiveSame(int id) override sealed;
			bool IncreaseTableSize(int amount) override sealed;
			int FetchIDByPosition(int position) override sealed;
			IINIEntry ^FetchByPosition(int position) override sealed;

			property IntPtr IntINIEntryIndexClassPointer
			{
				IntPtr get();
			}

			property int Count
			{
				int get() override sealed;
			}

			property IINIEntry ^default[int]
			{
				IINIEntry ^get(int key) override sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::IndexClass<int, ::INIEntry *> *InternalIntINIEntryIndexClassPointer
			{
				virtual ::IndexClass<int, ::INIEntry *> *get();
			}
	};

	public interface class IINISection : public INode<IINISection ^>
	{
		IINIEntry ^FindEntry(String ^entry);

		property IntPtr INISectionPointer
		{
			IntPtr get();
		}

		property String ^Section
		{
			String ^get();
			void set(String ^value);
		}

		property IList<IINIEntry ^> ^EntryList
		{
			IList<IINIEntry ^> ^get();
		}

		property IIndexClass<int, IINIEntry ^> ^EntryIndex
		{
			IIndexClass<int, IINIEntry ^> ^get();
			void set(IIndexClass<int, IINIEntry ^> ^value);
		}

		property int IndexId
		{
			int get();
		}
	};

	public ref class INISectionList : public List<IINISection ^>
	{
		private:
			INISectionList();

		public:
			INISectionList(IntPtr pointer);

			static IUnmanagedContainer<IList<IINISection ^> ^> ^CreateINISectionList();

			void Delete() override sealed;

			property IntPtr INISectionListPointer
			{
				IntPtr get();
			}

			property IINISection ^TFirst
			{
				IINISection ^get() override sealed;
			}

			property IINISection ^TFirstValid
			{
				IINISection ^get() override sealed;
			}

			property IINISection ^TLast
			{
				IINISection ^get() override sealed;
			}

			property IINISection ^TLastValid
			{
				IINISection ^get() override sealed;
			}

		protected:
			property ::GenericList *InternalGenericListPointer
			{
				::GenericList *get() override;
			}

			property ::List<::INISection *> *InternalINISectionListPointer
			{
				virtual ::List<::INISection *> *get();
			}
	};

	public ref class IntINISectionIndexClass : public IndexClass<int, IINISection ^>
	{
		private:
			IntINISectionIndexClass();

		public:
			IntINISectionIndexClass(IntPtr pointer);

			static IUnmanagedContainer<IIndexClass<int, IINISection ^> ^> ^CreateIntINISectionIndexClass();

			bool RemoveIndex(int id) override sealed;
			bool IsPresent(int id) override sealed;
			bool AddIndex(int id, IINISection ^data) override sealed;
			void InvalidateArchive() override sealed;
			void Clear() override sealed;
			bool IsArchiveSame(int id) override sealed;
			bool IncreaseTableSize(int amount) override sealed;
			int FetchIDByPosition(int position) override sealed;
			IINISection ^FetchByPosition(int position) override sealed;

			property IntPtr IntINISectionIndexClassPointer
			{
				IntPtr get();
			}

			property int Count
			{
				int get() override sealed;
			}

			property IINISection ^default[int]
			{
				IINISection ^get(int key) override sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::IndexClass<int, ::INISection *> *InternalIntINISectionIndexClassPointer
			{
				virtual ::IndexClass<int, ::INISection *> *get();
			}
	};

	public ref class INISection : public Node<IINISection ^>, public IINISection
	{
		private:
			INISection(String ^section);

		public:
			INISection(IntPtr pointer);

			String ^ToString() override;

			static IUnmanagedContainer<IINISection ^> ^CreateINISection(String ^section);

			virtual IINIEntry ^FindEntry(String ^entry) sealed;

			property IntPtr INISectionPointer
			{
				virtual IntPtr get() sealed;
			}

			[DebuggerBrowsable(DebuggerBrowsableState::Never)]
			[Obsolete("This property is unsafe", true)]
			property IList<IINISection ^> ^TMainList
			{
				IList<IINISection ^> ^get() override sealed;
			}

			property IINISection ^TNext
			{
				virtual IINISection ^get() override sealed;
			}

			property IINISection ^TNextValid
			{
				virtual IINISection ^get() override sealed;
			}

			property IINISection ^TPrev
			{
				virtual IINISection ^get() override sealed;
			}

			property IINISection ^TPrevValid
			{
				virtual IINISection ^get() override sealed;
			}

			property String ^Section
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property IList<IINIEntry ^> ^EntryList
			{
				virtual IList<IINIEntry ^> ^get() sealed;
			}

			property IIndexClass<int, IINIEntry ^> ^EntryIndex
			{
				virtual IIndexClass<int, IINIEntry ^> ^get() sealed;
				virtual void set(IIndexClass<int, IINIEntry ^> ^value) sealed;
			}

			property int IndexId
			{
				virtual int get() sealed;
			}

		protected:
			property ::GenericNode *InternalGenericNodePointer
			{
				::GenericNode *get() override;
			}

			property ::INISection *InternalINISectionPointer
			{
				virtual ::INISection *get();
			}
	};

	public interface class IINIClass : public IUnmanagedObject
	{
		void DuplicateCRCError(String ^function, String ^message, String ^entry);

		void Initialize();

		void Shutdown();

		bool Clear(String ^section, String ^entry);

		int GetInt(String ^section, String ^entry, int defaultValue);

		Color GetColor(String ^section, String ^entry, Color defaultValue);

		float GetFloat(String ^section, String ^entry, float defaultValue);

		bool GetBool(String ^section, String ^entry, bool defaultValue);

		String ^GetString(String ^section, String ^entry, String ^defaultValue);

		String ^GetString(String ^section, String ^entry);

		bool PutString(String ^section, String ^entry, String ^string);

		bool PutInt(String ^section, String ^entry, int value, int format);

		bool PutBool(String ^section, String ^entry, bool value);

		bool PutFloat(String ^section, String ^entry, float value);

		int EntryCount(String ^section);

		String ^GetEntry(String ^section, int index);

		IINIEntry ^FindEntry(String ^section, String ^entry);

		IINISection ^FindSection(String ^section);

		int Load(IStraw ^ffile);

		int Load(IFileClass ^file);

		int Load(String ^filename);

		int Save(IFileClass ^file);

		int Save(IPipe ^pipe);

		bool IsPresent(String ^section, String ^entry);

		bool SectionPresent(String ^section);

		property IntPtr INIClassPointer
		{
			IntPtr get();
		}

		property int SectionCount
		{
			int get();
		}

		property IList<IINISection ^> ^SectionList
		{
			IList<IINISection ^> ^get();
		}

		property IIndexClass<int, IINISection ^> ^SectionIndex
		{
			IIndexClass<int, IINISection ^> ^get();
			void set(IIndexClass<int, IINISection ^> ^value);
		}
	};

	public ref class INIClass : public AbstractUnmanagedObject, public IINIClass
	{
		private:
			INIClass();
			INIClass(IFileClass ^file);

		public:
			INIClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			static IUnmanagedContainer<IINIClass ^> ^CreateINIClass();
			static IUnmanagedContainer<IINIClass ^> ^CreateINIClass(IFileClass ^file);

			static String ^StripComments(String ^buffer);
			static int CRC(String ^string);

			virtual void DuplicateCRCError(String ^function, String ^message, String ^entry) sealed;
			virtual void Initialize() sealed;
			virtual void Shutdown() sealed;
			virtual bool Clear(String ^section, String ^entry) sealed;
			virtual int GetInt(String ^section, String ^entry, int defaultValue) sealed;
			virtual Color GetColor(String ^section, String ^entry, Color defaultValue) sealed;
			virtual float GetFloat(String ^section, String ^entry, float defaultValue) sealed;
			virtual bool GetBool(String ^section, String ^entry, bool defaultValue) sealed;
			virtual String ^GetString(String ^section, String ^entry, String ^defaultValue) sealed;
			virtual String ^GetString(String ^section, String ^entry) sealed;
			virtual bool PutString(String ^section, String ^entry, String ^string) sealed;
			virtual bool PutInt(String ^section, String ^entry, int value, int format) sealed;
			virtual bool PutBool(String ^section, String ^entry, bool value) sealed;
			virtual bool PutFloat(String ^section, String ^entry, float value) sealed;
			virtual int EntryCount(String ^section) sealed;
			virtual String ^GetEntry(String ^section, int index) sealed;
			virtual IINIEntry ^FindEntry(String ^section, String ^entry) sealed;
			virtual IINISection ^FindSection(String ^section) sealed;
			virtual int Load(IStraw ^ffile) sealed;
			virtual int Load(IFileClass ^file) sealed;
			virtual int Load(String ^filename) sealed;
			virtual int Save(IFileClass ^file) sealed;
			virtual int Save(IPipe ^pipe) sealed;
			virtual bool IsPresent(String ^section, String ^entry) sealed;
			virtual bool SectionPresent(String ^section) sealed;

			property IntPtr INIClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property int SectionCount
			{
				virtual int get() sealed;
			}

			property IList<IINISection ^> ^SectionList
			{
				virtual IList<IINISection ^> ^get() sealed;
			}

			property IIndexClass<int, IINISection ^> ^SectionIndex
			{
				virtual IIndexClass<int, IINISection ^> ^get() sealed;
				virtual void set(IIndexClass<int, IINISection ^> ^value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::INIClass *InternalINIClassPointer
			{
				virtual ::INIClass *get();
			}
	};

	public interface class IFileFactoryClass : public IUnmanagedObject
	{
		IFileClass ^GetFile(String ^filename);

		void ReturnFile(IFileClass ^file);

		property IntPtr FileFactoryClassPointer
		{
			IntPtr get();
		}
	};

	public ref class FileFactoryClass : public AbstractUnmanagedObject, public IFileFactoryClass
	{
		public:
			FileFactoryClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual IFileClass ^GetFile(String ^filename) sealed;
			virtual void ReturnFile(IFileClass ^file) sealed;

			property IntPtr FileFactoryClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::FileFactoryClass *InternalFileFactoryClassPointer
			{
				virtual ::FileFactoryClass *get();
			}
	};
}