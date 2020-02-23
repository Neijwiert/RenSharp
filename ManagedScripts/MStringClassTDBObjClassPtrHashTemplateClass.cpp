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
#include "MStringClassTDBObjClassPtrHashTemplateClass.h"

#include "Imports.h"
#include "UnmanagedContainer.h"
#include "MTDBObjClass.h"

namespace RenSharp
{
	StringClassTDBObjClassPtrHashTemplateIterator::StringClassTDBObjClassPtrHashTemplateIterator(IHashTemplateClass<String^, ITDBObjClass^>^ table)
	{
		if (table == nullptr || table->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("table");
		}

		Pointer = IntPtr(Imports::CreateStringClassTDBObjClassPtrHashTemplateIterator(reinterpret_cast<::HashTemplateClass<::StringClass, ::TDBObjClass*>*>(table->Pointer.ToPointer())));
	}

	StringClassTDBObjClassPtrHashTemplateIterator::StringClassTDBObjClassPtrHashTemplateIterator(IntPtr pointer)
		: HashTemplateIterator<String^, ITDBObjClass^>(pointer)
	{

	}

	IUnmanagedContainer<IHashTemplateIterator<String^, ITDBObjClass^>^>^ StringClassTDBObjClassPtrHashTemplateIterator::CreateStringClassTDBObjClassPtrHashTemplateIterator(
		IHashTemplateClass<String^, ITDBObjClass^>^ table)
	{
		return gcnew UnmanagedContainer<IHashTemplateIterator<String^, ITDBObjClass^>^>(gcnew StringClassTDBObjClassPtrHashTemplateIterator(table));
	}

	void StringClassTDBObjClassPtrHashTemplateIterator::Reset()
	{
		InternalStringClassTDBObjClassPtrHashTemplateIteratorPointer->reset();
	}

	void StringClassTDBObjClassPtrHashTemplateIterator::Remove()
	{
		InternalStringClassTDBObjClassPtrHashTemplateIteratorPointer->remove();
	}

	void StringClassTDBObjClassPtrHashTemplateIterator::Next()
	{
		InternalStringClassTDBObjClassPtrHashTemplateIteratorPointer->operator++();
	}

	IntPtr StringClassTDBObjClassPtrHashTemplateIterator::StringClassTDBObjClassPtrHashTemplateIteratorPointer::get()
	{
		return IntPtr(InternalStringClassTDBObjClassPtrHashTemplateIteratorPointer);
	}

	String^ StringClassTDBObjClassPtrHashTemplateIterator::CurrentKey::get()
	{
		if (IsDone)
		{
			throw gcnew ArgumentOutOfRangeException();
		}

		return gcnew String(InternalStringClassTDBObjClassPtrHashTemplateIteratorPointer->getKey().Peek_Buffer());
	}

	ITDBObjClass^ StringClassTDBObjClassPtrHashTemplateIterator::CurrentValue::get()
	{
		return gcnew TDBObjClass(IntPtr(InternalStringClassTDBObjClassPtrHashTemplateIteratorPointer->getValue()));
	}

	bool StringClassTDBObjClassPtrHashTemplateIterator::IsDone::get()
	{
		return !InternalStringClassTDBObjClassPtrHashTemplateIteratorPointer->operator bool();
	}

	bool StringClassTDBObjClassPtrHashTemplateIterator::InternalDestroyPointer()
	{
		Imports::DestroyStringClassTDBObjClassPtrHashTemplateIterator(InternalStringClassTDBObjClassPtrHashTemplateIteratorPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::HashTemplateIterator<::StringClass, ::TDBObjClass*>* StringClassTDBObjClassPtrHashTemplateIterator::InternalStringClassTDBObjClassPtrHashTemplateIteratorPointer::get()
	{
		return reinterpret_cast<::HashTemplateIterator<::StringClass, ::TDBObjClass*>*>(Pointer.ToPointer());
	}

	StringClassTDBObjClassPtrHashTemplateClass::StringClassTDBObjClassPtrHashTemplateClass()
		: HashTemplateClass<String^, ITDBObjClass^>(IntPtr(Imports::CreateStringClassTDBObjClassPtrHashTemplateClass()))
	{

	}

	StringClassTDBObjClassPtrHashTemplateClass::StringClassTDBObjClassPtrHashTemplateClass(IntPtr pointer)
		: HashTemplateClass<String^, ITDBObjClass^>(pointer)
	{

	}

	IUnmanagedContainer<IHashTemplateClass<String^, ITDBObjClass^>^>^ StringClassTDBObjClassPtrHashTemplateClass::CreateStringClassTDBObjClassPtrHashTemplateClass()
	{
		return gcnew UnmanagedContainer<IHashTemplateClass<String^, ITDBObjClass^>^>(gcnew StringClassTDBObjClassPtrHashTemplateClass());
	}

	ITDBObjClass^ StringClassTDBObjClassPtrHashTemplateClass::Get(String^ key)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}

		IntPtr keyHandle = Marshal::StringToHGlobalAnsi(key);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(keyHandle.ToPointer()));

			auto result = InternalStringClassTDBObjClassPtrHashTemplateClassPointer->Get(tmp);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew TDBObjClass(IntPtr(*result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(keyHandle);
		}
	}

	void StringClassTDBObjClassPtrHashTemplateClass::Get(String^ key, ITDBObjClass^ defaultValue, ITDBObjClass^% result)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}

		::TDBObjClass* defaultValuePtr;
		if (defaultValue == nullptr || defaultValue->TDBObjClassPointer.ToPointer() == nullptr)
		{
			defaultValuePtr = nullptr;
		}
		else
		{
			defaultValuePtr = reinterpret_cast<::TDBObjClass*>(defaultValue->TDBObjClassPointer.ToPointer());
		}

		IntPtr keyHandle = Marshal::StringToHGlobalAnsi(key);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(keyHandle.ToPointer()));

			auto resultPtr = InternalStringClassTDBObjClassPtrHashTemplateClassPointer->Get(
				tmp,
				reinterpret_cast<::TDBObjClass*>(defaultValue->TDBObjClassPointer.ToPointer()));
			if (resultPtr == nullptr)
			{
				result = nullptr;
			}
			else
			{
				result = gcnew TDBObjClass(IntPtr(resultPtr));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(keyHandle);
		}
	}

	bool StringClassTDBObjClassPtrHashTemplateClass::Exists(String^ key)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}

		IntPtr keyHandle = Marshal::StringToHGlobalAnsi(key);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(keyHandle.ToPointer()));

			return InternalStringClassTDBObjClassPtrHashTemplateClassPointer->Exists(tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(keyHandle);
		}
	}

	void StringClassTDBObjClassPtrHashTemplateClass::Insert(String^ key, ITDBObjClass^ value)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}

		IntPtr keyHandle = Marshal::StringToHGlobalAnsi(key);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(keyHandle.ToPointer()));

			if (value == nullptr || value->TDBObjClassPointer.ToPointer() == nullptr)
			{
				InternalStringClassTDBObjClassPtrHashTemplateClassPointer->Insert(
					tmp,
					nullptr);
			}
			else
			{
				InternalStringClassTDBObjClassPtrHashTemplateClassPointer->Insert(
					tmp,
					reinterpret_cast<::TDBObjClass*>(value->TDBObjClassPointer.ToPointer()));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(keyHandle);
		}
	}

	void StringClassTDBObjClassPtrHashTemplateClass::RemoveAll()
	{
		InternalStringClassTDBObjClassPtrHashTemplateClassPointer->Remove_All();
	}

	void StringClassTDBObjClassPtrHashTemplateClass::GetValueByIndex(int index, ITDBObjClass^% result)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto resultPtr = InternalStringClassTDBObjClassPtrHashTemplateClassPointer->getValueByIndex(index);
		if (resultPtr == nullptr)
		{
			result = nullptr;
		}
		else
		{
			result = gcnew TDBObjClass(IntPtr(resultPtr));
		}
	}

	bool StringClassTDBObjClassPtrHashTemplateClass::Remove(String^ key)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}

		IntPtr keyHandle = Marshal::StringToHGlobalAnsi(key);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(keyHandle.ToPointer()));

			if (InternalStringClassTDBObjClassPtrHashTemplateClassPointer->Exists(tmp))
			{
				InternalStringClassTDBObjClassPtrHashTemplateClassPointer->Remove(tmp);

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

	bool StringClassTDBObjClassPtrHashTemplateClass::Remove(Generic::KeyValuePair<String^, ITDBObjClass^> pair)
	{
		auto foundObj = Get(pair.Key);
		if (foundObj == nullptr)
		{
			return false;
		}

		bool foundNull = (foundObj == nullptr || foundObj->TDBObjClassPointer.ToPointer() == nullptr);
		bool pairNull = (pair.Value == nullptr || pair.Value->TDBObjClassPointer.ToPointer() == nullptr);
		if (foundNull && pairNull)
		{
			return true;
		}
		else if (foundNull || pairNull)
		{
			return false;
		}

		if (foundObj->Equals(pair.Value))
		{
			IntPtr keyHandle = Marshal::StringToHGlobalAnsi(pair.Key);
			try
			{
				::StringClass tmp(reinterpret_cast<char*>(keyHandle.ToPointer()));

				InternalStringClassTDBObjClassPtrHashTemplateClassPointer->Remove(tmp);

				return true;
			}
			finally
			{
				Marshal::FreeHGlobal(keyHandle);
			}
		}

		return false;
	}

	bool StringClassTDBObjClassPtrHashTemplateClass::Contains(Generic::KeyValuePair<String^, ITDBObjClass^> pair)
	{
		auto foundObj = Get(pair.Key);
		if (foundObj == nullptr)
		{
			return false;
		}

		bool foundNull = (foundObj == nullptr || foundObj->TDBObjClassPointer.ToPointer() == nullptr);
		bool pairNull = (pair.Value == nullptr || pair.Value->TDBObjClassPointer.ToPointer() == nullptr);
		if (foundNull && pairNull)
		{
			return true;
		}
		else if (foundNull || pairNull)
		{
			return false;
		}

		return foundObj->Equals(pair.Value);
	}

	bool StringClassTDBObjClassPtrHashTemplateClass::Contains(Object^ key)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}

		auto stringKey = dynamic_cast<String^>(key);
		if (stringKey == nullptr)
		{
			return false;
		}

		return ContainsKey(stringKey);
	}

	void StringClassTDBObjClassPtrHashTemplateClass::Add(Object^ key, Object^ value)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}
		else if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto stringKey = dynamic_cast<String^>(key);
		if (stringKey == nullptr)
		{
			return;
		}

		auto TDBObjClassPtrValue = dynamic_cast<ITDBObjClass^>(value);

		Insert(stringKey, TDBObjClassPtrValue);
	}

	void StringClassTDBObjClassPtrHashTemplateClass::Remove(Object^ key)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}

		auto stringKey = dynamic_cast<String^>(key);
		if (stringKey == nullptr)
		{
			return;
		}

		Remove(stringKey);
	}

	IntPtr StringClassTDBObjClassPtrHashTemplateClass::StringClassTDBObjClassPtrHashTemplateClassPointer::get()
	{
		return IntPtr(InternalStringClassTDBObjClassPtrHashTemplateClassPointer);
	}

	uint StringClassTDBObjClassPtrHashTemplateClass::Size::get()
	{
		return InternalStringClassTDBObjClassPtrHashTemplateClassPointer->Get_Size();
	}

	Object^ StringClassTDBObjClassPtrHashTemplateClass::default::get(Object^ key)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}

		auto stringKey = dynamic_cast<String^>(key);
		if (stringKey == nullptr)
		{
			return nullptr;
		}

		return this[stringKey];
	}

	void StringClassTDBObjClassPtrHashTemplateClass::default::set(Object^ key, Object^ value)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}
		else if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto stringKey = dynamic_cast<String^>(key);
		if (stringKey == nullptr)
		{
			return;
		}

		auto TDBObjClassPtrValue = dynamic_cast<ITDBObjClass^>(value);

		this[stringKey] = TDBObjClassPtrValue;
	}

	bool StringClassTDBObjClassPtrHashTemplateClass::InternalDestroyPointer()
	{
		Imports::DestroyStringClassTDBObjClassPtrHashTemplateClass(InternalStringClassTDBObjClassPtrHashTemplateClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::HashTemplateClass<::StringClass, ::TDBObjClass*>* StringClassTDBObjClassPtrHashTemplateClass::InternalStringClassTDBObjClassPtrHashTemplateClassPointer::get()
	{
		return reinterpret_cast<::HashTemplateClass<::StringClass, ::TDBObjClass*>*>(Pointer.ToPointer());
	}

	IUnmanagedContainer<IHashTemplateIterator<String^, ITDBObjClass^>^>^ StringClassTDBObjClassPtrHashTemplateClass::Iterator::get()
	{
		return StringClassTDBObjClassPtrHashTemplateIterator::CreateStringClassTDBObjClassPtrHashTemplateIterator(this);
	}
}