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
#include "MUInt32ConstWeaponDefinitionClassPtrHashTemplateClass.h"

#include "Imports.h"
#include "Mweaponmgr.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	UInt32ConstWeaponDefinitionClassPtrHashTemplateIterator::UInt32ConstWeaponDefinitionClassPtrHashTemplateIterator(
		IHashTemplateClass<unsigned int, IWeaponDefinitionClass^>^ table)
	{
		if (table == nullptr || table->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("table");
		}

		Pointer = IntPtr(Imports::CreateUInt32ConstWeaponDefinitionClassPtrHashTemplateIterator(
			reinterpret_cast<::HashTemplateClass<unsigned int, const ::WeaponDefinitionClass*>*>(table->Pointer.ToPointer())));
	}

	UInt32ConstWeaponDefinitionClassPtrHashTemplateIterator::UInt32ConstWeaponDefinitionClassPtrHashTemplateIterator(IntPtr pointer)
		: HashTemplateIterator<unsigned int, IWeaponDefinitionClass^>(pointer)
	{

	}

	IUnmanagedContainer<IHashTemplateIterator<unsigned int, IWeaponDefinitionClass^>^>^ UInt32ConstWeaponDefinitionClassPtrHashTemplateIterator::CreateUInt32ConstWeaponDefinitionClassPtrHashTemplateIterator(
		IHashTemplateClass<unsigned int, IWeaponDefinitionClass^>^ table)
	{
		return gcnew UnmanagedContainer<IHashTemplateIterator<unsigned int, IWeaponDefinitionClass^>^>(gcnew UInt32ConstWeaponDefinitionClassPtrHashTemplateIterator(table));
	}

	void UInt32ConstWeaponDefinitionClassPtrHashTemplateIterator::Reset()
	{
		InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateIteratorPointer->reset();
	}

	void UInt32ConstWeaponDefinitionClassPtrHashTemplateIterator::Remove()
	{
		InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateIteratorPointer->remove();
	}

	void UInt32ConstWeaponDefinitionClassPtrHashTemplateIterator::Next()
	{
		InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateIteratorPointer->operator++();
	}

	IntPtr UInt32ConstWeaponDefinitionClassPtrHashTemplateIterator::UInt32ConstWeaponDefinitionClassPtrHashTemplateIteratorPointer::get()
	{
		return IntPtr(InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateIteratorPointer);
	}

	unsigned int UInt32ConstWeaponDefinitionClassPtrHashTemplateIterator::CurrentKey::get()
	{
		if (IsDone)
		{
			throw gcnew ArgumentOutOfRangeException();
		}

		return InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateIteratorPointer->getKey();
	}

	IWeaponDefinitionClass^ UInt32ConstWeaponDefinitionClassPtrHashTemplateIterator::CurrentValue::get()
	{
		auto result = DefinitionClass::CreateDefinitionClassWrapper(InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateIteratorPointer->getValue());
		if (result != nullptr)
		{
			return safe_cast<IWeaponDefinitionClass^>(result);
		}

		return gcnew WeaponDefinitionClass(
			IntPtr(const_cast<::WeaponDefinitionClass*>(InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateIteratorPointer->getValue())));
	}

	bool UInt32ConstWeaponDefinitionClassPtrHashTemplateIterator::IsDone::get()
	{
		return !InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateIteratorPointer->operator bool();
	}

	bool UInt32ConstWeaponDefinitionClassPtrHashTemplateIterator::InternalDestroyPointer()
	{
		Imports::DestroyUInt32ConstWeaponDefinitionClassPtrHashTemplateIterator(InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateIteratorPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::HashTemplateIterator<unsigned int, const ::WeaponDefinitionClass*>* UInt32ConstWeaponDefinitionClassPtrHashTemplateIterator::InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateIteratorPointer::get()
	{
		return reinterpret_cast<::HashTemplateIterator<unsigned int, const ::WeaponDefinitionClass*>*>(Pointer.ToPointer());
	}

	UInt32ConstWeaponDefinitionClassPtrHashTemplateClass::UInt32ConstWeaponDefinitionClassPtrHashTemplateClass()
		: HashTemplateClass<unsigned int, IWeaponDefinitionClass^>(IntPtr(Imports::CreateUInt32ConstWeaponDefinitionClassPtrHashTemplateClass()))
	{

	}

	UInt32ConstWeaponDefinitionClassPtrHashTemplateClass::UInt32ConstWeaponDefinitionClassPtrHashTemplateClass(IntPtr pointer)
		: HashTemplateClass<unsigned int, IWeaponDefinitionClass^>(pointer)
	{

	}

	IUnmanagedContainer<IHashTemplateClass<unsigned int, IWeaponDefinitionClass^>^>^ UInt32ConstWeaponDefinitionClassPtrHashTemplateClass::CreateUInt32ConstWeaponDefinitionClassPtrHashTemplateClass()
	{
		return gcnew UnmanagedContainer<IHashTemplateClass<unsigned int, IWeaponDefinitionClass^>^>(gcnew UInt32ConstWeaponDefinitionClassPtrHashTemplateClass());
	}

	IWeaponDefinitionClass^ UInt32ConstWeaponDefinitionClassPtrHashTemplateClass::Get(unsigned int key)
	{
		auto defPtrPtr = InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateClassPointer->Get(key);
		if (defPtrPtr == nullptr || (*defPtrPtr) == nullptr)
		{
			return nullptr;
		}
		else
		{
			auto result = DefinitionClass::CreateDefinitionClassWrapper(*defPtrPtr);
			if (result != nullptr)
			{
				return safe_cast<IWeaponDefinitionClass^>(result);
			}

			return gcnew WeaponDefinitionClass(IntPtr(const_cast<::WeaponDefinitionClass*>(*defPtrPtr)));
		}
	}

	void UInt32ConstWeaponDefinitionClassPtrHashTemplateClass::Get(unsigned int key, IWeaponDefinitionClass^ defaultValue, IWeaponDefinitionClass^% result)
	{
		const ::WeaponDefinitionClass* tmp;

		if (defaultValue == nullptr || defaultValue->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			tmp = InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateClassPointer->Get(
				key,
				nullptr);
		}
		else
		{
			tmp = InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateClassPointer->Get(
				key,
				*reinterpret_cast<const ::WeaponDefinitionClass * *>(defaultValue->WeaponDefinitionClassPointer.ToPointer()));
		}

		if (tmp == nullptr)
		{
			result = nullptr;
		}
		else
		{
			auto tmpResult = DefinitionClass::CreateDefinitionClassWrapper(tmp);
			if (tmpResult != nullptr)
			{
				result = safe_cast<IWeaponDefinitionClass^>(tmpResult);
			}
			else
			{
				result = gcnew WeaponDefinitionClass(IntPtr(const_cast<::WeaponDefinitionClass*>(tmp)));
			}
		}
	}

	bool UInt32ConstWeaponDefinitionClassPtrHashTemplateClass::Exists(unsigned int key)
	{
		return InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateClassPointer->Exists(key);
	}

	void UInt32ConstWeaponDefinitionClassPtrHashTemplateClass::Insert(unsigned int key, IWeaponDefinitionClass^ value)
	{
		if (value == nullptr || value->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateClassPointer->Insert(
				key,
				nullptr);
		}
		else
		{
			InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateClassPointer->Insert(
				key,
				*reinterpret_cast<const ::WeaponDefinitionClass * *>(value->WeaponDefinitionClassPointer.ToPointer()));
		}
	}

	void UInt32ConstWeaponDefinitionClassPtrHashTemplateClass::RemoveAll()
	{
		InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateClassPointer->Remove_All();
	}

	void UInt32ConstWeaponDefinitionClassPtrHashTemplateClass::GetValueByIndex(int index, IWeaponDefinitionClass^% result)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}
		else if (result == nullptr || result->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto tmp = InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateClassPointer->getValueByIndex(index);
		if (tmp == nullptr)
		{
			result = nullptr;
		}
		else
		{
			auto tmpResult = DefinitionClass::CreateDefinitionClassWrapper(tmp);
			if (tmpResult != nullptr)
			{
				result = safe_cast<IWeaponDefinitionClass^>(tmpResult);
			}
			else
			{
				result = gcnew WeaponDefinitionClass(IntPtr(const_cast<::WeaponDefinitionClass*>(tmp)));
			}
		}
	}

	bool UInt32ConstWeaponDefinitionClassPtrHashTemplateClass::Remove(unsigned int key)
	{
		if (InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateClassPointer->Exists(key))
		{
			InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateClassPointer->Remove(key);

			return true;
		}
		else
		{
			return false;
		}
	}

	bool UInt32ConstWeaponDefinitionClassPtrHashTemplateClass::Remove(Generic::KeyValuePair<unsigned int, IWeaponDefinitionClass^> pair)
	{
		if (Contains(pair))
		{
			InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateClassPointer->Remove(pair.Key);

			return true;
		}
		else
		{
			return false;
		}
	}

	bool UInt32ConstWeaponDefinitionClassPtrHashTemplateClass::Contains(Generic::KeyValuePair<unsigned int, IWeaponDefinitionClass^> pair)
	{
		if (InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateClassPointer->Exists(pair.Key))
		{
			auto value = InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateClassPointer->Get(pair.Key);
			if (pair.Value == nullptr || pair.Value->WeaponDefinitionClassPointer.ToPointer() == nullptr)
			{
				return (value == nullptr);
			}
			else
			{
				return (value == pair.Value->WeaponDefinitionClassPointer.ToPointer());
			}
		}

		return false;
	}

	bool UInt32ConstWeaponDefinitionClassPtrHashTemplateClass::Contains(Object^ key)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}

		if (!UInt32::typeid->Equals(key->GetType()))
		{
			return false;
		}

		return ContainsKey(safe_cast<UInt32>(key));
	}

	void UInt32ConstWeaponDefinitionClassPtrHashTemplateClass::Add(Object^ key, Object^ value)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}
		else if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		if (!UInt32::typeid->Equals(key->GetType()))
		{
			return;
		}

		auto defValue = dynamic_cast<IWeaponDefinitionClass^>(value);

		Insert(safe_cast<UInt32>(key), defValue);
	}

	void UInt32ConstWeaponDefinitionClassPtrHashTemplateClass::Remove(Object^ key)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}

		if (!UInt32::typeid->Equals(key->GetType()))
		{
			return;
		}

		Remove(safe_cast<UInt32>(key));
	}

	IntPtr UInt32ConstWeaponDefinitionClassPtrHashTemplateClass::UInt32ConstWeaponDefinitionClassPtrHashTemplateClassPointer::get()
	{
		return IntPtr(InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateClassPointer);
	}

	uint UInt32ConstWeaponDefinitionClassPtrHashTemplateClass::Size::get()
	{
		return InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateClassPointer->Get_Size();
	}

	Object^ UInt32ConstWeaponDefinitionClassPtrHashTemplateClass::default::get(Object^ key)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}

		if (!UInt32::typeid->Equals(key->GetType()))
		{
			return nullptr;
		}

		return this[safe_cast<UInt32>(key)];
	}

	void UInt32ConstWeaponDefinitionClassPtrHashTemplateClass::default::set(Object^ key, Object^ value)
	{
		if (key == nullptr)
		{
			throw gcnew ArgumentNullException("key");
		}
		else if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		if (!UInt32::typeid->Equals(key->GetType()))
		{
			return;
		}

		auto defValue = dynamic_cast<IWeaponDefinitionClass^>(value);

		this[safe_cast<UInt32>(key)] = defValue;
	}

	bool UInt32ConstWeaponDefinitionClassPtrHashTemplateClass::InternalDestroyPointer()
	{
		Imports::DestroyUInt32ConstWeaponDefinitionClassPtrHashTemplateClass(InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::HashTemplateClass<unsigned int, const ::WeaponDefinitionClass*>* UInt32ConstWeaponDefinitionClassPtrHashTemplateClass::InternalUInt32ConstWeaponDefinitionClassPtrHashTemplateClassPointer::get()
	{
		return reinterpret_cast<::HashTemplateClass<unsigned int, const ::WeaponDefinitionClass*>*>(Pointer.ToPointer());
	}

	IUnmanagedContainer<IHashTemplateIterator<unsigned int, IWeaponDefinitionClass^>^>^ UInt32ConstWeaponDefinitionClassPtrHashTemplateClass::Iterator::get()
	{
		return UInt32ConstWeaponDefinitionClassPtrHashTemplateIterator::CreateUInt32ConstWeaponDefinitionClassPtrHashTemplateIterator(this);
	}
}