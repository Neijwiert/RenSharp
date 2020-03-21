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
#include  "MConversationMgrClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)

class ConversationClass;

class ConversationMgrClass : public SaveLoadSubSystemClass
{
	public:
		static ::ConversationClass* Find_Conversation(const char* name);
		static ::ConversationClass* Find_Conversation(int id);
};

RENEGADE_FUNCTION
::ConversationClass* ::ConversationMgrClass::Find_Conversation(const char* name)
AT2(0x006D6C30, 0x006D64D0);

RENEGADE_FUNCTION
::ConversationClass* ::ConversationMgrClass::Find_Conversation(int id)
AT2(0x006D6C90, 0x006D6530);

::ConversationClass* Find_Conversation(const char* name)
{
	return ::ConversationMgrClass::Find_Conversation(name);
}

::ConversationClass* Find_Conversation(int id)
{
	return ::ConversationMgrClass::Find_Conversation(id);
}

#pragma warning(pop) 
#pragma managed(pop)

#include "MConversationClass.h"
#include "RefCountClassUnmanagedContainer.h"

namespace RenSharp
{
	ConversationMgrClass::ConversationMgrClass(IntPtr pointer)
		: SaveLoadSubSystemClass(pointer)
	{

	}

	IUnmanagedContainer<IConversationClass^>^ ConversationMgrClass::FindConversation(String^ name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			auto result = Find_Conversation(reinterpret_cast<char*>(nameHandle.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew RefCountClassUnmanagedContainer<IConversationClass^>(gcnew ConversationClass(IntPtr(result)));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	IUnmanagedContainer<IConversationClass^>^ ConversationMgrClass::FindConversation(int id)
	{
		auto result = Find_Conversation(id);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RefCountClassUnmanagedContainer<IConversationClass^>(gcnew ConversationClass(IntPtr(result)));
		}
	}

	IntPtr ConversationMgrClass::ConversationMgrClassPointer::get()
	{
		return IntPtr(InternalConversationMgrClassPointer);
	}

	::SaveLoadSubSystemClass* ConversationMgrClass::InternalSaveLoadSubSystemClassPointer::get()
	{
		return InternalConversationMgrClassPointer;
	}

	::ConversationMgrClass* ConversationMgrClass::InternalConversationMgrClassPointer::get()
	{
		return reinterpret_cast<::ConversationMgrClass*>(Pointer.ToPointer());
	}
}