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
#include "MConstWeaponDefinitionClassPtrDynamicVectorClass.h"

#include "Mweaponmgr.h"
#include "Imports.h"

namespace RenSharp
{
	ConstWeaponDefinitionClassPtrDynamicVectorClass::ConstWeaponDefinitionClassPtrDynamicVectorClass()
		: DynamicVectorClass<IWeaponDefinitionClass^>(IntPtr(Imports::CreateConstWeaponDefinitionClassPtrDynamicVectorClass1()))
	{

	}

	ConstWeaponDefinitionClassPtrDynamicVectorClass::ConstWeaponDefinitionClassPtrDynamicVectorClass(int size)
		: DynamicVectorClass<IWeaponDefinitionClass^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateConstWeaponDefinitionClassPtrDynamicVectorClass2(size));
	}

	ConstWeaponDefinitionClassPtrDynamicVectorClass::ConstWeaponDefinitionClassPtrDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<IWeaponDefinitionClass^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<IWeaponDefinitionClass^>^>^ ConstWeaponDefinitionClassPtrDynamicVectorClass::CreateConstWeaponDefinitionClassPtrDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IWeaponDefinitionClass^>^>(gcnew ConstWeaponDefinitionClassPtrDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<IWeaponDefinitionClass^>^>^ ConstWeaponDefinitionClassPtrDynamicVectorClass::CreateConstWeaponDefinitionClassPtrDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IWeaponDefinitionClass^>^>(gcnew ConstWeaponDefinitionClassPtrDynamicVectorClass(size));
	}

	bool ConstWeaponDefinitionClassPtrDynamicVectorClass::Resize(int newSize)
	{
		return InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer->Resize(newSize);
	}

	void ConstWeaponDefinitionClassPtrDynamicVectorClass::Clear()
	{
		InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer->Clear();
	}

	int ConstWeaponDefinitionClassPtrDynamicVectorClass::ID(IWeaponDefinitionClass^ object)
	{
		if (object == nullptr || object->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			return InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer->ID(static_cast<::WeaponDefinitionClass*>(nullptr));
		}
		else
		{
			return InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer->ID(reinterpret_cast<::WeaponDefinitionClass*>(object->WeaponDefinitionClassPointer.ToPointer()));
		}
	}

	void ConstWeaponDefinitionClassPtrDynamicVectorClass::Insert(int index, IWeaponDefinitionClass^ object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (object == nullptr || object->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer->Insert(index, reinterpret_cast<::WeaponDefinitionClass*>(object->WeaponDefinitionClassPointer.ToPointer()));
		}
	}

	bool ConstWeaponDefinitionClassPtrDynamicVectorClass::Add(IWeaponDefinitionClass^ object)
	{
		if (object == nullptr || object->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			return InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer->Add(nullptr);
		}
		else
		{
			return InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer->Add(reinterpret_cast<::WeaponDefinitionClass*>(object->WeaponDefinitionClassPointer.ToPointer()));
		}
	}

	void ConstWeaponDefinitionClassPtrDynamicVectorClass::ResetActive()
	{
		InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer->Reset_Active();
	}

	bool ConstWeaponDefinitionClassPtrDynamicVectorClass::AddHead(IWeaponDefinitionClass^ object)
	{
		if (object == nullptr || object->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			return InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer->Add_Head(reinterpret_cast<::WeaponDefinitionClass*>(object->WeaponDefinitionClassPointer.ToPointer()));
		}
	}

	bool ConstWeaponDefinitionClassPtrDynamicVectorClass::DeleteObj(IWeaponDefinitionClass^ object)
	{
		if (object == nullptr || object->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			return InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer->DeleteObj(nullptr);
		}
		else
		{
			return InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer->DeleteObj(reinterpret_cast<::WeaponDefinitionClass*>(object->WeaponDefinitionClassPointer.ToPointer()));
		}
	}

	bool ConstWeaponDefinitionClassPtrDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer->Delete(index);
	}

	void ConstWeaponDefinitionClassPtrDynamicVectorClass::DeleteAll()
	{
		InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer->Delete_All();
	}

	int ConstWeaponDefinitionClassPtrDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void ConstWeaponDefinitionClassPtrDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr ConstWeaponDefinitionClassPtrDynamicVectorClass::ConstWeaponDefinitionClassPtrDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer);
	}

	IWeaponDefinitionClass^ ConstWeaponDefinitionClassPtrDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto defPtr = InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer->operator[](index);
		if (defPtr == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IWeaponDefinitionClass^>(DefinitionClass::CreateDefinitionClassWrapper(defPtr));
		}
	}

	void ConstWeaponDefinitionClassPtrDynamicVectorClass::default::set(int index, IWeaponDefinitionClass^ value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->WeaponDefinitionClassPointer.ToPointer() == nullptr)
		{
			InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer->operator[](index) = reinterpret_cast<::WeaponDefinitionClass*>(value->WeaponDefinitionClassPointer.ToPointer());
		}
	}

	int ConstWeaponDefinitionClassPtrDynamicVectorClass::Length::get()
	{
		return InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer->Length();
	}

	int ConstWeaponDefinitionClassPtrDynamicVectorClass::Count::get()
	{
		return InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer->Count();
	}

	void ConstWeaponDefinitionClassPtrDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer->Set_Active(value);
	}

	int ConstWeaponDefinitionClassPtrDynamicVectorClass::GrowthStep::get()
	{
		return InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer->Growth_Step();
	}

	void ConstWeaponDefinitionClassPtrDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool ConstWeaponDefinitionClassPtrDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyConstWeaponDefinitionClassPtrDynamicVectorClass(InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<const ::WeaponDefinitionClass*>* ConstWeaponDefinitionClassPtrDynamicVectorClass::InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<const ::WeaponDefinitionClass*>*>(Pointer.ToPointer());
	}

	IntPtr ConstWeaponDefinitionClassPtrDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::WeaponDefinitionClass*>*>(InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void ConstWeaponDefinitionClassPtrDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::WeaponDefinitionClass*>*>(InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::WeaponDefinitionClass * *>(value.ToPointer()));
	}

	int ConstWeaponDefinitionClassPtrDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::WeaponDefinitionClass*>*>(InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void ConstWeaponDefinitionClassPtrDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::WeaponDefinitionClass*>*>(InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool ConstWeaponDefinitionClassPtrDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::WeaponDefinitionClass*>*>(InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void ConstWeaponDefinitionClassPtrDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::WeaponDefinitionClass*>*>(InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool ConstWeaponDefinitionClassPtrDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::WeaponDefinitionClass*>*>(InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void ConstWeaponDefinitionClassPtrDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::WeaponDefinitionClass*>*>(InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int ConstWeaponDefinitionClassPtrDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::WeaponDefinitionClass*>*>(InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void ConstWeaponDefinitionClassPtrDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::WeaponDefinitionClass*>*>(InternalConstWeaponDefinitionClassPtrDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}