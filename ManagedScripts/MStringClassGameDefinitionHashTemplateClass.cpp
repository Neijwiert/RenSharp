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
#include "MStringClassGameDefinitionHashTemplateClass.h"

#include "Imports.h"
#include "UnmanagedContainer.h"
#include "MGameDefinition.h"

namespace RenSharp
{
	StringClassGameDefinitionHashTemplateIterator::StringClassGameDefinitionHashTemplateIterator(IHashTemplateClass<String ^, IGameDefinition ^> ^table)
	{
		if (table == nullptr || table->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("table");
		}

		Pointer = IntPtr(Imports::CreateStringClassGameDefinitionHashTemplateIterator(reinterpret_cast<::HashTemplateClass<::StringClass, ::GameDefinition> *>(table->Pointer.ToPointer())));
	}

	StringClassGameDefinitionHashTemplateIterator::StringClassGameDefinitionHashTemplateIterator(IntPtr pointer)
		: HashTemplateIterator<String ^, IGameDefinition ^>(pointer)
	{

	}

	IUnmanagedContainer<IHashTemplateIterator<String ^, IGameDefinition ^> ^> ^StringClassGameDefinitionHashTemplateIterator::CreateStringClassGameDefinitionHashTemplateIterator(
		IHashTemplateClass<String ^, IGameDefinition ^> ^table)
	{
		return gcnew UnmanagedContainer<IHashTemplateIterator<String ^, IGameDefinition ^> ^>(gcnew StringClassGameDefinitionHashTemplateIterator(table));
	}

	void StringClassGameDefinitionHashTemplateIterator::Reset()
	{
		InternalStringClassGameDefinitionHashTemplateIteratorPointer->reset();
	}

	void StringClassGameDefinitionHashTemplateIterator::Remove()
	{
		InternalStringClassGameDefinitionHashTemplateIteratorPointer->remove();
	}

	void StringClassGameDefinitionHashTemplateIterator::Next()
	{
		InternalStringClassGameDefinitionHashTemplateIteratorPointer->operator++();
	}

	IntPtr StringClassGameDefinitionHashTemplateIterator::StringClassGameDefinitionHashTemplateIteratorPointer::get()
	{
		return IntPtr(InternalStringClassGameDefinitionHashTemplateIteratorPointer);
	}

	String ^StringClassGameDefinitionHashTemplateIterator::CurrentKey::get()
	{
		if (IsDone)
		{
			throw gcnew ArgumentOutOfRangeException();
		}

		return gcnew String(InternalStringClassGameDefinitionHashTemplateIteratorPointer->getKey().Peek_Buffer());
	}

	IGameDefinition ^StringClassGameDefinitionHashTemplateIterator::CurrentValue::get()
	{
		return gcnew GameDefinition(IntPtr(&InternalStringClassGameDefinitionHashTemplateIteratorPointer->getValue()));
	}

	bool StringClassGameDefinitionHashTemplateIterator::IsDone::get()
	{
		return !InternalStringClassGameDefinitionHashTemplateIteratorPointer->operator bool();
	}

	bool StringClassGameDefinitionHashTemplateIterator::InternalDestroyPointer()
	{
		Imports::DestroyStringClassGameDefinitionHashTemplateIterator(InternalStringClassGameDefinitionHashTemplateIteratorPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::HashTemplateIterator<::StringClass, ::GameDefinition> *StringClassGameDefinitionHashTemplateIterator::InternalStringClassGameDefinitionHashTemplateIteratorPointer::get()
	{
		return reinterpret_cast<::HashTemplateIterator<::StringClass, ::GameDefinition> *>(Pointer.ToPointer());
	}

	StringClassGameDefinitionHashTemplateClass::StringClassGameDefinitionHashTemplateClass()
		: HashTemplateClass<String ^, IGameDefinition ^>(IntPtr(Imports::CreateStringClassGameDefinitionHashTemplateClass()))
	{

	}

	StringClassGameDefinitionHashTemplateClass::StringClassGameDefinitionHashTemplateClass(IntPtr pointer)
		: HashTemplateClass<String ^, IGameDefinition ^>(pointer)
	{

	}

	IUnmanagedContainer<IHashTemplateClass<String ^, IGameDefinition ^> ^> ^StringClassGameDefinitionHashTemplateClass::CreateStringClassGameDefinitionHashTemplateClass()
	{
		return gcnew UnmanagedContainer<IHashTemplateClass<String ^, IGameDefinition ^> ^>(gcnew StringClassGameDefinitionHashTemplateClass());
	}

	IGameDefinition ^StringClassGameDefinitionHashTemplateClass::Get(String ^key)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}

		IntPtr keyHandle = Marshal::StringToHGlobalAnsi(key);
		try
		{
			::StringClass tmp(reinterpret_cast<char *>(keyHandle.ToPointer()));

			auto result = InternalStringClassGameDefinitionHashTemplateClassPointer->Get(tmp);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew GameDefinition(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(keyHandle);
		}
	}

	void StringClassGameDefinitionHashTemplateClass::Get(String ^key, IGameDefinition ^defaultValue, IGameDefinition ^%result)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}
		else if (defaultValue == nullptr || defaultValue->GameDefinitionPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("defaultValue");
		}
		else if (result == nullptr || result->GameDefinitionPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("result");
		}

		IntPtr keyHandle = Marshal::StringToHGlobalAnsi(key);
		try
		{
			::StringClass tmp(reinterpret_cast<char *>(keyHandle.ToPointer()));

			(*reinterpret_cast<::GameDefinition *>(result->GameDefinitionPointer.ToPointer())) = 
				InternalStringClassGameDefinitionHashTemplateClassPointer->Get(tmp, *reinterpret_cast<::GameDefinition *>(defaultValue->GameDefinitionPointer.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(keyHandle);
		}
	}

	bool StringClassGameDefinitionHashTemplateClass::Exists(String ^key)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}

		IntPtr keyHandle = Marshal::StringToHGlobalAnsi(key);
		try
		{
			::StringClass tmp(reinterpret_cast<char *>(keyHandle.ToPointer()));

			return InternalStringClassGameDefinitionHashTemplateClassPointer->Exists(tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(keyHandle);
		}
	}

	void StringClassGameDefinitionHashTemplateClass::Insert(String ^key, IGameDefinition ^value)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}
		else if (value == nullptr || value->GameDefinitionPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr keyHandle = Marshal::StringToHGlobalAnsi(key);
		try
		{
			::StringClass tmp(reinterpret_cast<char *>(keyHandle.ToPointer()));

			InternalStringClassGameDefinitionHashTemplateClassPointer->Insert(tmp, *reinterpret_cast<::GameDefinition *>(value->GameDefinitionPointer.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(keyHandle);
		}
	}

	void StringClassGameDefinitionHashTemplateClass::RemoveAll()
	{
		InternalStringClassGameDefinitionHashTemplateClassPointer->Remove_All();
	}

	void StringClassGameDefinitionHashTemplateClass::GetValueByIndex(int index, IGameDefinition ^%result)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}
		else if (result == nullptr || result->GameDefinitionPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		(*reinterpret_cast<::GameDefinition *>(result->GameDefinitionPointer.ToPointer())) = InternalStringClassGameDefinitionHashTemplateClassPointer->getValueByIndex(index);
	}

	bool StringClassGameDefinitionHashTemplateClass::Remove(String ^key)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}

		IntPtr keyHandle = Marshal::StringToHGlobalAnsi(key);
		try
		{
			::StringClass tmp(reinterpret_cast<char *>(keyHandle.ToPointer()));

			if (InternalStringClassGameDefinitionHashTemplateClassPointer->Exists(tmp))
			{
				InternalStringClassGameDefinitionHashTemplateClassPointer->Remove(tmp);

				return true;
			}
			else
			{
				return false;
			}
		}
		finally
		{
			Marshal::FreeHGlobal(keyHandle);
		}
	}

	bool StringClassGameDefinitionHashTemplateClass::Remove(Generic::KeyValuePair<String ^, IGameDefinition ^> pair)
	{
		throw gcnew NotSupportedException();
	}

	bool StringClassGameDefinitionHashTemplateClass::Contains(Generic::KeyValuePair<String ^, IGameDefinition ^> pair)
	{
		throw gcnew NotSupportedException();
	}

	bool StringClassGameDefinitionHashTemplateClass::Contains(Object ^key)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}

		auto stringKey = dynamic_cast<String ^>(key);
		if (stringKey == nullptr)
		{
			return false;
		}

		return ContainsKey(stringKey);
	}

	void StringClassGameDefinitionHashTemplateClass::Add(Object ^key, Object ^value)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}
		else if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto stringKey = dynamic_cast<String ^>(key);
		if (stringKey == nullptr)
		{
			return;
		}

		auto gameDefinitionValue = dynamic_cast<IGameDefinition ^>(value);
		if (gameDefinitionValue == nullptr)
		{
			return;
		}

		Insert(stringKey, gameDefinitionValue);
	}

	void StringClassGameDefinitionHashTemplateClass::Remove(Object ^key)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}

		auto stringKey = dynamic_cast<String ^>(key);
		if (stringKey == nullptr)
		{
			return;
		}

		Remove(stringKey);
	}

	IntPtr StringClassGameDefinitionHashTemplateClass::StringClassGameDefinitionHashTemplateClassPointer::get()
	{
		return IntPtr(InternalStringClassGameDefinitionHashTemplateClassPointer);
	}

	uint StringClassGameDefinitionHashTemplateClass::Size::get()
	{
		return InternalStringClassGameDefinitionHashTemplateClassPointer->Get_Size();
	}

	Object ^StringClassGameDefinitionHashTemplateClass::default::get(Object ^key)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}

		auto stringKey = dynamic_cast<String ^>(key);
		if (stringKey == nullptr)
		{
			return nullptr;
		}

		return this[stringKey];
	}

	void StringClassGameDefinitionHashTemplateClass::default::set(Object ^key, Object ^value)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}
		else if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto stringKey = dynamic_cast<String ^>(key);
		if (stringKey == nullptr)
		{
			return;
		}

		auto gameDefinitionValue = dynamic_cast<IGameDefinition ^>(value);
		if (gameDefinitionValue == nullptr)
		{
			return;
		}

		this[stringKey] = gameDefinitionValue;
	}

	bool StringClassGameDefinitionHashTemplateClass::InternalDestroyPointer()
	{
		Imports::DestroyStringClassGameDefinitionHashTemplateClass(InternalStringClassGameDefinitionHashTemplateClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::HashTemplateClass<::StringClass, ::GameDefinition> *StringClassGameDefinitionHashTemplateClass::InternalStringClassGameDefinitionHashTemplateClassPointer::get()
	{
		return reinterpret_cast<::HashTemplateClass<::StringClass, ::GameDefinition> *>(Pointer.ToPointer());
	}

	IUnmanagedContainer<IHashTemplateIterator<String ^, IGameDefinition ^> ^> ^StringClassGameDefinitionHashTemplateClass::Iterator::get()
	{
		return StringClassGameDefinitionHashTemplateIterator::CreateStringClassGameDefinitionHashTemplateIterator(this);
	}
}