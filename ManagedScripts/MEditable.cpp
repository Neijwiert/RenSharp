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
#include "MEditable.h"

#include "MParameter.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <Editable.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	EditableClass::EditableClass(IntPtr pointer)
		: PersistClass(pointer)
	{

	}

	IParameterClass^ EditableClass::LockParameter(int index)
	{
		if (index < 0 || index >= InternalEditableClassPointer->Get_Parameter_Count())
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalEditableClassPointer->Lock_Parameter(index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ParameterClass(IntPtr(result));
		}
	}

	void EditableClass::UnlockParameter(int index)
	{
		if (index < 0 || index >= InternalEditableClassPointer->Get_Parameter_Count())
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		InternalEditableClassPointer->Unlock_Parameter(index);
	}

	IntPtr EditableClass::EditableClassPointer::get()
	{
		return IntPtr(InternalEditableClassPointer);
	}

	int EditableClass::ParameterCount::get()
	{
		return InternalEditableClassPointer->Get_Parameter_Count();
	}

	::PersistClass *EditableClass::InternalPersistClassPointer::get()
	{
		return InternalEditableClassPointer;
	}

	::EditableClass *EditableClass::InternalEditableClassPointer::get()
	{
		return reinterpret_cast<::EditableClass *>(Pointer.ToPointer());
	}
}