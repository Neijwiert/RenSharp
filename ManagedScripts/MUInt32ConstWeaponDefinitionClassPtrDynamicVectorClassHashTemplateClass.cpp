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
#include "MUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass.h"

#include "Imports.h"
#include "MConstWeaponDefinitionClassPtrDynamicVectorClass.h"
#include "Mweaponmgr.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator::UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator(
		IHashTemplateClass<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^>^ table)
	{
		if (table == nullptr || table->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("table");
		}

		Pointer = IntPtr(Imports::CreateUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator(
			reinterpret_cast<::HashTemplateClass<unsigned int, ::DynamicVectorClass<const ::WeaponDefinitionClass*>>*>(table->Pointer.ToPointer())));
	}

	UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator::UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator(IntPtr pointer)
		: HashTemplateIterator<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^>(pointer)
	{

	}

	IUnmanagedContainer<IHashTemplateIterator<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^>^>^ UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator::CreateUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator(
		IHashTemplateClass<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^>^ table)
	{
		return gcnew UnmanagedContainer<IHashTemplateIterator<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^>^>(gcnew UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator(table));
	}

	void UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator::Reset()
	{
		InternalUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIteratorPointer->reset();
	}

	void UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator::Remove()
	{
		InternalUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIteratorPointer->remove();
	}

	void UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator::Next()
	{
		InternalUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIteratorPointer->operator++();
	}

	IntPtr UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator::UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIteratorPointer::get()
	{
		return IntPtr(InternalUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIteratorPointer);
	}

	unsigned int UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator::CurrentKey::get()
	{
		if (IsDone)
		{
			throw gcnew ArgumentOutOfRangeException();
		}

		return InternalUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIteratorPointer->getKey();
	}

	IDynamicVectorClass<IWeaponDefinitionClass^>^ UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator::CurrentValue::get()
	{
		return gcnew ConstWeaponDefinitionClassPtrDynamicVectorClass(
			IntPtr(&InternalUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIteratorPointer->getValue()));
	}

	bool UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator::IsDone::get()
	{
		return !InternalUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIteratorPointer->operator bool();
	}

	bool UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator::InternalDestroyPointer()
	{
		Imports::DestroyUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator(InternalUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIteratorPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::HashTemplateIterator<unsigned int, ::DynamicVectorClass<const ::WeaponDefinitionClass*>>* UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator::InternalUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIteratorPointer::get()
	{
		return reinterpret_cast<::HashTemplateIterator<unsigned int, ::DynamicVectorClass<const ::WeaponDefinitionClass*>>*>(Pointer.ToPointer());
	}

	UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass::UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass()
		: HashTemplateClass<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^>(IntPtr(Imports::CreateUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass()))
	{

	}

	UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass::UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass(IntPtr pointer)
		: HashTemplateClass<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^>(pointer)
	{

	}

	IUnmanagedContainer<IHashTemplateClass<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^>^>^ UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass::CreateUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass()
	{
		return gcnew UnmanagedContainer<IHashTemplateClass<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^>^>(gcnew UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass());
	}

	IDynamicVectorClass<IWeaponDefinitionClass^>^ UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass::Get(unsigned int key)
	{
		auto result = InternalUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClassPointer->Get(key);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ConstWeaponDefinitionClassPtrDynamicVectorClass(IntPtr(result));
		}
	}

	void UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass::Get(unsigned int key, IDynamicVectorClass<IWeaponDefinitionClass^>^ defaultValue, IDynamicVectorClass<IWeaponDefinitionClass^>^% result)
	{
		if (defaultValue == nullptr || defaultValue->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("defaultValue");
		}
		else if (result == nullptr || result->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("result");
		}

		(*reinterpret_cast<::DynamicVectorClass<const ::WeaponDefinitionClass*>*>(result->Pointer.ToPointer())) =
			InternalUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClassPointer->Get(
				key,
				*reinterpret_cast<::DynamicVectorClass<const ::WeaponDefinitionClass*>*>(defaultValue->Pointer.ToPointer()));
	}

	bool UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass::Exists(unsigned int key)
	{
		return InternalUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClassPointer->Exists(key);
	}

	void UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass::Insert(unsigned int key, IDynamicVectorClass<IWeaponDefinitionClass^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClassPointer->Insert(
			key,
			*reinterpret_cast<::DynamicVectorClass<const ::WeaponDefinitionClass*>*>(value->Pointer.ToPointer()));
	}

	void UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass::RemoveAll()
	{
		InternalUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClassPointer->Remove_All();
	}

	void UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass::GetValueByIndex(int index, IDynamicVectorClass<IWeaponDefinitionClass^>^% result)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}
		else if (result == nullptr || result->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		(*reinterpret_cast<::DynamicVectorClass<const ::WeaponDefinitionClass*>*>(result->Pointer.ToPointer())) = 
			InternalUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClassPointer->getValueByIndex(index);
	}

	bool UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass::Remove(unsigned int key)
	{
		if (InternalUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClassPointer->Exists(key))
		{
			InternalUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClassPointer->Remove(key);

			return true;
		}
		else
		{
			return false;
		}
	}

	bool UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass::Remove(Generic::KeyValuePair<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^> pair)
	{
		return false;
	}

	bool UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass::Contains(Generic::KeyValuePair<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^> pair)
	{
		return false;
	}

	bool UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass::Contains(Object^ key)
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

	void UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass::Add(Object^ key, Object^ value)
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

		auto vectorValue = dynamic_cast<IDynamicVectorClass<IWeaponDefinitionClass^>^>(value);
		if (vectorValue == nullptr)
		{
			return;
		}

		Insert(safe_cast<UInt32>(key), vectorValue);
	}

	void UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass::Remove(Object^ key)
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

	IntPtr UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass::UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClassPointer::get()
	{
		return IntPtr(InternalUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClassPointer);
	}

	uint UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass::Size::get()
	{
		return InternalUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClassPointer->Get_Size();
	}

	Object^ UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass::default::get(Object^ key)
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

	void UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass::default::set(Object^ key, Object^ value)
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

		auto vectorValue = dynamic_cast<IDynamicVectorClass<IWeaponDefinitionClass^>^>(value);
		if (vectorValue == nullptr)
		{
			return;
		}

		this[safe_cast<UInt32>(key)] = vectorValue;
	}

	bool UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass::InternalDestroyPointer()
	{
		Imports::DestroyUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass(InternalUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::HashTemplateClass<unsigned int, ::DynamicVectorClass<const ::WeaponDefinitionClass*>>* UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass::InternalUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClassPointer::get()
	{
		return reinterpret_cast<::HashTemplateClass<unsigned int, ::DynamicVectorClass<const ::WeaponDefinitionClass*>>*>(Pointer.ToPointer());
	}

	IUnmanagedContainer<IHashTemplateIterator<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^>^>^ UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass::Iterator::get()
	{
		return UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator::CreateUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateIterator(this);
	}
}