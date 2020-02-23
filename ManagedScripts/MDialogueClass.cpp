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
#include "MDialogueClass.h"

#include "MDialogueOptionClassPtrDynamicVectorClass.h"

namespace RenSharp
{
	DialogueOptionClass::DialogueOptionClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool DialogueOptionClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDialogueOptionClass ^otherThis = dynamic_cast<IDialogueOptionClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DialogueOptionClassPointer.Equals(otherThis->DialogueOptionClassPointer);
	}

	IntPtr DialogueOptionClass::DialogueOptionClassPointer::get()
	{
		return IntPtr(InternalDialogueOptionClassPointer);
	}

	int DialogueOptionClass::ConversationID::get()
	{
		return InternalDialogueOptionClassPointer->Get_Conversation_ID();
	}

	void DialogueOptionClass::ConversationID::set(int value)
	{
		InternalDialogueOptionClassPointer->Set_Conversation_ID(value);
	}

	float DialogueOptionClass::Weight::get()
	{
		return InternalDialogueOptionClassPointer->Get_Weight();
	}

	void DialogueOptionClass::Weight::set(float value)
	{
		InternalDialogueOptionClassPointer->Set_Weight(value);
	}

	::DialogueOptionClass *DialogueOptionClass::InternalDialogueOptionClassPointer::get()
	{
		return reinterpret_cast<::DialogueOptionClass *>(Pointer.ToPointer());
	}

	DialogueClass::DialogueClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool DialogueClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDialogueClass ^otherThis = dynamic_cast<IDialogueClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DialogueClassPointer.Equals(otherThis->DialogueClassPointer);
	}

	IntPtr DialogueClass::DialogueClassPointer::get()
	{
		return IntPtr(InternalDialogueClassPointer);
	}

	IDynamicVectorClass<IDialogueOptionClass ^> ^DialogueClass::DialogueOptions::get()
	{
		return gcnew DialogueOptionClassPtrDynamicVectorClass(IntPtr(&InternalDialogueClassPointer->Get_Option_List()));
	}

	void DialogueClass::DialogueOptions::set(IDynamicVectorClass<IDialogueOptionClass ^> ^value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto &dialogueOptions = InternalDialogueClassPointer->Get_Option_List();
		dialogueOptions = *reinterpret_cast<::DynamicVectorClass<::DialogueOptionClass *> *>(value->Pointer.ToPointer());
	}

	float DialogueClass::SilenceWeight::get()
	{
		return InternalDialogueClassPointer->Get_Silence_Weight();
	}

	void DialogueClass::SilenceWeight::set(float value)
	{
		InternalDialogueClassPointer->Set_Silence_Weight(value);
	}

	::DialogueClass *DialogueClass::InternalDialogueClassPointer::get()
	{
		return reinterpret_cast<::DialogueClass *>(Pointer.ToPointer());
	}
}