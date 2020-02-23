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
#include "McScTextObj.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <cScTextObj.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	cScTextObj::cScTextObj(IntPtr pointer)
		: cNetEvent(pointer)
	{

	}

	void cScTextObj::SetDirtyBitForTeam(DirtyBit dirtyBits, int teamId)
	{
		InternalcScTextObjPointer->Set_Dirty_Bit_For_Team(static_cast<::NetworkObjectClass::DIRTY_BIT>(dirtyBits), teamId);
	}

	IntPtr cScTextObj::cScTextObjPointer::get()
	{
		return IntPtr(InternalcScTextObjPointer);
	}

	int cScTextObj::SenderId::get()
	{
		return InternalcScTextObjPointer->senderId;
	}

	void cScTextObj::SenderId::set(int value)
	{
		InternalcScTextObjPointer->senderId = value;
	}

	int cScTextObj::ReceiverId::get()
	{
		return InternalcScTextObjPointer->receiverId;
	}

	void cScTextObj::ReceiverId::set(int value)
	{
		InternalcScTextObjPointer->receiverId = value;
	}

	TextMessageEnum cScTextObj::Type::get()
	{
		return static_cast<TextMessageEnum>(InternalcScTextObjPointer->type);
	}

	void cScTextObj::Type::set(TextMessageEnum value)
	{
		InternalcScTextObjPointer->type = static_cast<::TextMessageEnum>(value);
	}

	String ^cScTextObj::Message::get()
	{
		return gcnew String(InternalcScTextObjPointer->message.Peek_Buffer());
	}

	void cScTextObj::Message::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalUni(value);
		try
		{
			InternalcScTextObjPointer->message = reinterpret_cast<wchar_t *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	bool cScTextObj::PopUp::get()
	{
		return InternalcScTextObjPointer->popup;
	}

	void cScTextObj::PopUp::set(bool value)
	{
		InternalcScTextObjPointer->popup = value;
	}

	::cNetEvent *cScTextObj::InternalcNetEventPointer::get()
	{
		return InternalcScTextObjPointer;
	}

	::cScTextObj *cScTextObj::InternalcScTextObjPointer::get()
	{
		return reinterpret_cast<::cScTextObj *>(Pointer.ToPointer());
	}
}