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

#include "AbstractUnmanagedObject.h"
#include "IUnmanagedContainer.h"
#include "Mda_event.h"

#pragma managed(push, off)

class DABanEntryClass;
class DABanListClass;
class DABanManager;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IDABanEntryClass : public IUnmanagedObject
	{
		bool MatchesName(String^ name);

		bool MatchesIP(String^ ip);

		bool MatchesSerial(String^ serial);

		property IntPtr DABanEntryClassPointer
		{
			IntPtr get();
		}

		property String^ Name
		{
			String^ get();
		}

		property String^ IP
		{
			String^ get();
		}

		property String^ Serial
		{
			String^ get();
		}

		property String^ Reason
		{
			String^ get();
		}
	};

	public ref class DABanEntryClass : public AbstractUnmanagedObject, public IDABanEntryClass
	{
		private:
			DABanEntryClass(String^ name, String^ ip, String^ serial, String^ reason);

		public:
			DABanEntryClass(IntPtr pointer);

			static IUnmanagedContainer<IDABanEntryClass^>^ CreateDABanEntryClass(String^ name, String^ ip, String^ serial, String^ reason);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual bool MatchesName(String^ name) sealed;
			virtual bool MatchesIP(String^ ip) sealed;
			virtual bool MatchesSerial(String^ serial) sealed;

			property IntPtr DABanEntryClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property String^ Name
			{
				virtual String^ get() sealed;
			}

			property String^ IP
			{
				virtual String^ get() sealed;
			}

			property String^ Serial
			{
				virtual String^ get() sealed;
			}

			property String^ Reason
			{
				virtual String^ get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DABanEntryClass* InternalDABanEntryClassPointer
			{
				virtual ::DABanEntryClass* get();
			}
	};

	public interface class IDABanListClass
		:
		public IUnmanagedObject,
		public Collections::IEnumerable,
		public Collections::Generic::IEnumerable<IDABanEntryClass^>
	{
		void Load();

		void Save();

		void Save(IDABanEntryClass^ entry);

		IDABanEntryClass^ AddEntry(String^ name, String^ ip, String^ serial, String^ reason);

		bool RemoveEntry(String^ name, String^ ip, String^ serial);

		bool RemoveEntryMatchAll(String^ name, String^ ip, String^ serial);

		IDABanEntryClass^ FindEntry(String^ name, String^ ip, String^ serial);

		DABanEntryClass^ FindEntryMatchAll(String^ name, String^ ip, String^ serial);

		void ListEntries();

		void ListEntries(String^ name, String^ ip, String^ serial);

		void ListEntriesMatchAll(String^ name, String^ ip, String^ serial);

		IDABanEntryClass^ PeekEntry(int position);

		property IntPtr DABanListClassPointer
		{
			IntPtr get();
		}

		property int Count
		{
			int get();
		}

		property String^ Name
		{
			String^ get();
		}
	};

	public ref class DABanListClass : public AbstractUnmanagedObject, public IDABanListClass
	{
		private:
			ref class Enumerator sealed : Collections::Generic::IEnumerator<IDABanEntryClass^>
			{
				private:
					DABanListClass ^banList;
					int index;

				public:
					Enumerator(DABanListClass ^banList)
						: banList(banList), index(-1)
					{

					}

					~Enumerator()
					{

					}

					virtual bool MoveNext() = Collections::Generic::IEnumerator<IDABanEntryClass^>::MoveNext
					{
						index++;

						if (index >= banList->Count)
						{
							return false;
						}

						return true;
					}

					virtual void Reset() = Collections::Generic::IEnumerator<IDABanEntryClass^>::Reset
					{
						index = -1;
					}

					property IDABanEntryClass^ Current
					{
						virtual IDABanEntryClass^ get() = Collections::Generic::IEnumerator<IDABanEntryClass^>::Current::get
						{
							if (index < 0 || index >= banList->Count)
							{
								throw gcnew IndexOutOfRangeException();
							}

							return banList->PeekEntry(index);
						}
					}

					property Object ^Current2
					{
						virtual Object ^get() = System::Collections::IEnumerator::Current::get
						{
							return Current;
						}
					}
			};

			DABanListClass(String^ name, String^ fileName);

		public:
			DABanListClass(IntPtr pointer);

			static IUnmanagedContainer<IDABanListClass^>^ CreateDABanListClass(String^ name, String^ fileName);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual void Load() sealed;
			virtual void Save() sealed;
			virtual void Save(IDABanEntryClass^ entry) sealed;
			virtual IDABanEntryClass^ AddEntry(String^ name, String^ ip, String^ serial, String^ reason) sealed;
			virtual bool RemoveEntry(String^ name, String^ ip, String^ serial) sealed;
			virtual bool RemoveEntryMatchAll(String^ name, String^ ip, String^ serial) sealed;
			virtual IDABanEntryClass^ FindEntry(String^ name, String^ ip, String^ serial) sealed;
			virtual DABanEntryClass^ FindEntryMatchAll(String^ name, String^ ip, String^ serial) sealed;
			virtual void ListEntries() sealed;
			virtual void ListEntries(String^ name, String^ ip, String^ serial) sealed;
			virtual void ListEntriesMatchAll(String^ name, String^ ip, String^ serial) sealed;
			virtual IDABanEntryClass^ PeekEntry(int position) sealed;

			virtual Collections::Generic::IEnumerator<IDABanEntryClass^>^ GetEnumerator() = Collections::Generic::IEnumerable<IDABanEntryClass^>::GetEnumerator
			{
				return gcnew Enumerator(this);
			}

				virtual Collections::IEnumerator^ GetEnumerator2() = Collections::IEnumerable::GetEnumerator
			{
				return GetEnumerator();
			}

			property IntPtr DABanListClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property int Count
			{
				virtual int get();
			}

			property String^ Name
			{
				virtual String^ get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DABanListClass* InternalDABanListClassPointer
			{
				virtual ::DABanListClass* get();
			}
	};

	public interface class IDABanManager : public IDAEventClass
	{
		property IntPtr DABanManagerPointer
		{
			IntPtr get();
		}
	};

	public ref class DABanManager : public DAEventClass, public IDABanManager
	{
		// Although you can instantiate a DABanManager class, it doesn't make any sense so I left it out
		public:
			DABanManager(IntPtr pointer);

			property IntPtr DABanManagerPointer
			{
				virtual IntPtr get() sealed;
			}

			static property IDABanListClass^ BanList
			{
				IDABanListClass^ get();
			}

			static property IDABanListClass^ BanExceptionList
			{
				IDABanListClass^ get();
			}

			static property IDABanListClass^ ForceTTList
			{
				IDABanListClass^ get();
			}

			static property IDABanListClass^ ForceTTExceptionList
			{
				IDABanListClass^ get();
			}

		protected:
			property ::DAEventClass* InternalDAEventClassPointer
			{
				::DAEventClass* get() override;
			}

			property ::DABanManager* InternalDABanManagerPointer
			{
				virtual ::DABanManager* get();
			}
	};
}