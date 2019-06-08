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
#include "Mda_ban.h"

#include "UnmanagedContainer.h"
#include "Imports.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_ban.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DABanEntryClass::DABanEntryClass(String^ name, String^ ip, String^ serial, String^ reason)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}
		else if (ip == nullptr)
		{
			throw gcnew ArgumentNullException("ip");
		}
		else if (serial == nullptr)
		{
			throw gcnew ArgumentNullException("serial");
		}
		else if (reason == nullptr)
		{
			throw gcnew ArgumentNullException("reason");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			IntPtr ipHandle = Marshal::StringToHGlobalAnsi(ip);
			try
			{
				IntPtr serialHandle = Marshal::StringToHGlobalAnsi(serial);
				try
				{
					IntPtr reasonHandle = Marshal::StringToHGlobalAnsi(reason);
					try
					{
						Pointer = IntPtr(Imports::CreateDABanEntryClass(
							reinterpret_cast<char*>(nameHandle.ToPointer()),
							reinterpret_cast<char*>(ipHandle.ToPointer()),
							reinterpret_cast<char*>(serialHandle.ToPointer()),
							reinterpret_cast<char*>(reasonHandle.ToPointer())));
					}
					finally
					{
						Marshal::FreeHGlobal(reasonHandle);
					}
				}
				finally
				{
					Marshal::FreeHGlobal(serialHandle);
				}
			}
			finally
			{
				Marshal::FreeHGlobal(ipHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	DABanEntryClass::DABanEntryClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IDABanEntryClass^>^ DABanEntryClass::CreateDABanEntryClass(String^ name, String^ ip, String^ serial, String^ reason)
	{
		return gcnew UnmanagedContainer<IDABanEntryClass^>(gcnew DABanEntryClass(name, ip, serial, reason));
	}

	String^ DABanEntryClass::ToString()
	{
		return Name;
	}

	bool DABanEntryClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDABanEntryClass^ otherThis = dynamic_cast<IDABanEntryClass^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DABanEntryClassPointer.Equals(otherThis->DABanEntryClassPointer);
	}

	bool DABanEntryClass::MatchesName(String^ name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			return InternalDABanEntryClassPointer->Matches_Name(
				reinterpret_cast<char*>(nameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	bool DABanEntryClass::MatchesIP(String^ ip)
	{
		if (ip == nullptr)
		{
			return InternalDABanEntryClassPointer->Matches_IP(nullptr);
		}

		IntPtr ipHandle = Marshal::StringToHGlobalAnsi(ip);
		try
		{
			return InternalDABanEntryClassPointer->Matches_IP(
				reinterpret_cast<char*>(ipHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(ipHandle);
		}
	}

	bool DABanEntryClass::MatchesSerial(String^ serial)
	{
		if (serial == nullptr)
		{
			throw gcnew ArgumentNullException("serial");
		}

		IntPtr serialHandle = Marshal::StringToHGlobalAnsi(serial);
		try
		{
			return InternalDABanEntryClassPointer->Matches_Serial(
				reinterpret_cast<char*>(serialHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(serialHandle);
		}
	}

	IntPtr DABanEntryClass::DABanEntryClassPointer::get()
	{
		return IntPtr(InternalDABanEntryClassPointer);
	}

	String^ DABanEntryClass::Name::get()
	{
		return gcnew String(InternalDABanEntryClassPointer->Get_Name().Peek_Buffer());
	}

	String^ DABanEntryClass::IP::get()
	{
		return gcnew String(InternalDABanEntryClassPointer->Get_IP().Peek_Buffer());
	}

	String^ DABanEntryClass::Serial::get()
	{
		return gcnew String(InternalDABanEntryClassPointer->Get_Serial().Peek_Buffer());
	}

	String^ DABanEntryClass::Reason::get()
	{
		return gcnew String(InternalDABanEntryClassPointer->Get_Reason().Peek_Buffer());
	}

	bool DABanEntryClass::InternalDestroyPointer()
	{
		Imports::DestroyDABanEntryClass(InternalDABanEntryClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DABanEntryClass* DABanEntryClass::InternalDABanEntryClassPointer::get()
	{
		return reinterpret_cast<::DABanEntryClass*>(Pointer.ToPointer());
	}

	DABanListClass::DABanListClass(String^ name, String^ fileName)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}
		else if (fileName == nullptr)
		{
			throw gcnew ArgumentNullException("fileName");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			IntPtr fileNameHandle = Marshal::StringToHGlobalAnsi(fileName);
			try
			{
				Pointer = IntPtr(Imports::CreateDABanListClass(
					reinterpret_cast<char*>(nameHandle.ToPointer()),
					reinterpret_cast<char*>(fileNameHandle.ToPointer())));
			}
			finally
			{
				Marshal::FreeHGlobal(fileNameHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	DABanListClass::DABanListClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IDABanListClass^>^ DABanListClass::CreateDABanListClass(String^ name, String^ fileName)
	{
		return gcnew UnmanagedContainer<IDABanListClass^>(gcnew DABanListClass(name, fileName));
	}

	String^ DABanListClass::ToString()
	{
		return Name;
	}

	bool DABanListClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDABanListClass^ otherThis = dynamic_cast<IDABanListClass^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DABanListClassPointer.Equals(otherThis->DABanListClassPointer);
	}

	void DABanListClass::Load()
	{
		InternalDABanListClassPointer->Load();
	}

	void DABanListClass::Save()
	{
		InternalDABanListClassPointer->Save();
	}

	void DABanListClass::Save(IDABanEntryClass^ entry)
	{
		if (entry == nullptr || entry->DABanEntryClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("entry");
		}

		InternalDABanListClassPointer->Save(
			reinterpret_cast<::DABanEntryClass*>(entry->DABanEntryClassPointer.ToPointer()));
	}

	IDABanEntryClass^ DABanListClass::AddEntry(String^ name, String^ ip, String^ serial, String^ reason)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}
		else if (ip == nullptr)
		{
			throw gcnew ArgumentNullException("ip");
		}
		else if (serial == nullptr)
		{
			throw gcnew ArgumentNullException("serial");
		}
		else if (reason == nullptr)
		{
			throw gcnew ArgumentNullException("reason");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			IntPtr ipHandle = Marshal::StringToHGlobalAnsi(ip);
			try
			{
				IntPtr serialHandle = Marshal::StringToHGlobalAnsi(serial);
				try
				{
					IntPtr reasonHandle = Marshal::StringToHGlobalAnsi(reason);
					try
					{
						auto result = InternalDABanListClassPointer->Add_Entry(
							reinterpret_cast<char*>(nameHandle.ToPointer()),
							reinterpret_cast<char*>(ipHandle.ToPointer()),
							reinterpret_cast<char*>(serialHandle.ToPointer()),
							reinterpret_cast<char*>(reasonHandle.ToPointer()));
						if (result == nullptr)
						{
							return nullptr;
						}
						else
						{
							return gcnew DABanEntryClass(IntPtr(result));
						}
					}
					finally
					{
						Marshal::FreeHGlobal(reasonHandle);
					}
				}
				finally
				{
					Marshal::FreeHGlobal(serialHandle);
				}
			}
			finally
			{
				Marshal::FreeHGlobal(ipHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	bool DABanListClass::RemoveEntry(String^ name, String^ ip, String^ serial)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}
		else if (serial == nullptr)
		{
			throw gcnew ArgumentNullException("serial");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			IntPtr serialHandle = Marshal::StringToHGlobalAnsi(serial);
			try
			{
				if (ip == nullptr)
				{
					return InternalDABanListClassPointer->Remove_Entry(
						reinterpret_cast<char*>(nameHandle.ToPointer()),
						nullptr,
						reinterpret_cast<char*>(serialHandle.ToPointer()));
				}
				else
				{
					IntPtr ipHandle = Marshal::StringToHGlobalAnsi(ip);
					try
					{
						return InternalDABanListClassPointer->Remove_Entry(
							reinterpret_cast<char*>(nameHandle.ToPointer()),
							reinterpret_cast<char*>(ipHandle.ToPointer()),
							reinterpret_cast<char*>(serialHandle.ToPointer()));
					}
					finally
					{
						Marshal::FreeHGlobal(ipHandle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(serialHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	bool DABanListClass::RemoveEntryMatchAll(String^ name, String^ ip, String^ serial)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}
		else if (serial == nullptr)
		{
			throw gcnew ArgumentNullException("serial");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			IntPtr serialHandle = Marshal::StringToHGlobalAnsi(serial);
			try
			{
				if (ip == nullptr)
				{
					return InternalDABanListClassPointer->Remove_Entry_Match_All(
						reinterpret_cast<char*>(nameHandle.ToPointer()),
						nullptr,
						reinterpret_cast<char*>(serialHandle.ToPointer()));
				}
				else
				{
					IntPtr ipHandle = Marshal::StringToHGlobalAnsi(ip);
					try
					{
						return InternalDABanListClassPointer->Remove_Entry_Match_All(
							reinterpret_cast<char*>(nameHandle.ToPointer()),
							reinterpret_cast<char*>(ipHandle.ToPointer()),
							reinterpret_cast<char*>(serialHandle.ToPointer()));
					}
					finally
					{
						Marshal::FreeHGlobal(ipHandle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(serialHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	IDABanEntryClass^ DABanListClass::FindEntry(String^ name, String^ ip, String^ serial)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}
		else if (serial == nullptr)
		{
			throw gcnew ArgumentNullException("serial");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			IntPtr serialHandle = Marshal::StringToHGlobalAnsi(serial);
			try
			{
				::DABanEntryClass* result;
				if (ip == nullptr)
				{
					result = InternalDABanListClassPointer->Find_Entry(
						reinterpret_cast<char*>(nameHandle.ToPointer()),
						nullptr,
						reinterpret_cast<char*>(serialHandle.ToPointer()));
				}
				else
				{
					IntPtr ipHandle = Marshal::StringToHGlobalAnsi(ip);
					try
					{
						result = InternalDABanListClassPointer->Find_Entry(
							reinterpret_cast<char*>(nameHandle.ToPointer()),
							reinterpret_cast<char*>(ipHandle.ToPointer()),
							reinterpret_cast<char*>(serialHandle.ToPointer()));
					}
					finally
					{
						Marshal::FreeHGlobal(ipHandle);
					}
				}

				if (result == nullptr)
				{
					return nullptr;
				}
				else
				{
					return gcnew DABanEntryClass(IntPtr(result));
				}
			}
			finally
			{
				Marshal::FreeHGlobal(serialHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	DABanEntryClass^ DABanListClass::FindEntryMatchAll(String^ name, String^ ip, String^ serial)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}
		else if (serial == nullptr)
		{
			throw gcnew ArgumentNullException("serial");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			IntPtr serialHandle = Marshal::StringToHGlobalAnsi(serial);
			try
			{
				::DABanEntryClass* result;
				if (ip == nullptr)
				{
					result = InternalDABanListClassPointer->Find_Entry_Match_All(
						reinterpret_cast<char*>(nameHandle.ToPointer()),
						nullptr,
						reinterpret_cast<char*>(serialHandle.ToPointer()));
				}
				else
				{
					IntPtr ipHandle = Marshal::StringToHGlobalAnsi(ip);
					try
					{
						result = InternalDABanListClassPointer->Find_Entry_Match_All(
							reinterpret_cast<char*>(nameHandle.ToPointer()),
							reinterpret_cast<char*>(ipHandle.ToPointer()),
							reinterpret_cast<char*>(serialHandle.ToPointer()));
					}
					finally
					{
						Marshal::FreeHGlobal(ipHandle);
					}
				}

				if (result == nullptr)
				{
					return nullptr;
				}
				else
				{
					return gcnew DABanEntryClass(IntPtr(result));
				}
			}
			finally
			{
				Marshal::FreeHGlobal(serialHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	void DABanListClass::ListEntries()
	{
		InternalDABanListClassPointer->List_Entries();
	}

	void DABanListClass::ListEntries(String^ name, String^ ip, String^ serial)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}
		else if (serial == nullptr)
		{
			throw gcnew ArgumentNullException("serial");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			IntPtr serialHandle = Marshal::StringToHGlobalAnsi(serial);
			try
			{
				if (ip == nullptr)
				{
					InternalDABanListClassPointer->List_Entries(
						reinterpret_cast<char*>(nameHandle.ToPointer()),
						nullptr,
						reinterpret_cast<char*>(serialHandle.ToPointer()));
				}
				else
				{
					IntPtr ipHandle = Marshal::StringToHGlobalAnsi(ip);
					try
					{
						InternalDABanListClassPointer->List_Entries(
							reinterpret_cast<char*>(nameHandle.ToPointer()),
							reinterpret_cast<char*>(ipHandle.ToPointer()),
							reinterpret_cast<char*>(serialHandle.ToPointer()));
					}
					finally
					{
						Marshal::FreeHGlobal(ipHandle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(serialHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	void DABanListClass::ListEntriesMatchAll(String^ name, String^ ip, String^ serial)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}
		else if (serial == nullptr)
		{
			throw gcnew ArgumentNullException("serial");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			IntPtr serialHandle = Marshal::StringToHGlobalAnsi(serial);
			try
			{
				if (ip == nullptr)
				{
					InternalDABanListClassPointer->List_Entries_Match_All(
						reinterpret_cast<char*>(nameHandle.ToPointer()),
						nullptr,
						reinterpret_cast<char*>(serialHandle.ToPointer()));
				}
				else
				{
					IntPtr ipHandle = Marshal::StringToHGlobalAnsi(ip);
					try
					{
						InternalDABanListClassPointer->List_Entries_Match_All(
							reinterpret_cast<char*>(nameHandle.ToPointer()),
							reinterpret_cast<char*>(ipHandle.ToPointer()),
							reinterpret_cast<char*>(serialHandle.ToPointer()));
					}
					finally
					{
						Marshal::FreeHGlobal(ipHandle);
					}
				}
			}
			finally
			{
				Marshal::FreeHGlobal(serialHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	IDABanEntryClass^ DABanListClass::PeekEntry(int position)
	{
		if (position < 0 || position >= InternalDABanListClassPointer->Get_Count())
		{
			throw gcnew ArgumentOutOfRangeException("position");
		}

		auto result = InternalDABanListClassPointer->Peek_Entry(position);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DABanEntryClass(IntPtr(result));
		}
	}

	IntPtr DABanListClass::DABanListClassPointer::get()
	{
		return IntPtr(InternalDABanListClassPointer);
	}

	int DABanListClass::Count::get()
	{
		return InternalDABanListClassPointer->Get_Count();
	}

	String^ DABanListClass::Name::get()
	{
		return gcnew String(InternalDABanListClassPointer->Get_Name().Peek_Buffer());
	}

	bool DABanListClass::InternalDestroyPointer()
	{
		Imports::DestroyDABanListClass(InternalDABanListClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DABanListClass* DABanListClass::InternalDABanListClassPointer::get()
	{
		return reinterpret_cast<::DABanListClass*>(Pointer.ToPointer());
	}

	DABanManager::DABanManager(IntPtr pointer)
		: DAEventClass(pointer)
	{

	}

	IntPtr DABanManager::DABanManagerPointer::get()
	{
		return IntPtr(InternalDABanManagerPointer);
	}

	IDABanListClass^ DABanManager::BanList::get()
	{
		auto result = ::DABanManager::Get_Ban_List();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DABanListClass(IntPtr(result));
		}
	}

	IDABanListClass^ DABanManager::BanExceptionList::get()
	{
		auto result = ::DABanManager::Get_Ban_Exception_List();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DABanListClass(IntPtr(result));
		}
	}

	IDABanListClass^ DABanManager::ForceTTList::get()
	{
		auto result = ::DABanManager::Get_ForceTT_List();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DABanListClass(IntPtr(result));
		}
	}

	IDABanListClass^ DABanManager::ForceTTExceptionList::get()
	{
		auto result = ::DABanManager::Get_ForceTT_Exception_List();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DABanListClass(IntPtr(result));
		}
	}

	::DAEventClass* DABanManager::InternalDAEventClassPointer::get()
	{
		return InternalDABanManagerPointer;
	}

	::DABanManager* DABanManager::InternalDABanManagerPointer::get()
	{
		return reinterpret_cast<::DABanManager*>(Pointer.ToPointer());
	}
}