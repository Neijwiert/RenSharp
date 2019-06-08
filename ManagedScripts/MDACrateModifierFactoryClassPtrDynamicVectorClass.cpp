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
#include "MDACrateModifierFactoryClassPtrDynamicVectorClass.h"

#include "Imports.h"
#include "Mda_crate.h"

namespace RenSharp
{
	DACrateModifierFactoryClassPtrDynamicVectorClass::DACrateModifierFactoryClassPtrDynamicVectorClass()
		: DynamicVectorClass<IDACrateModifierFactoryClass^>(IntPtr(Imports::CreateDACrateModifierFactoryClassPtrDynamicVectorClass1()))
	{

	}

	DACrateModifierFactoryClassPtrDynamicVectorClass::DACrateModifierFactoryClassPtrDynamicVectorClass(int size)
		: DynamicVectorClass<IDACrateModifierFactoryClass^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateDACrateModifierFactoryClassPtrDynamicVectorClass2(size));
	}

	DACrateModifierFactoryClassPtrDynamicVectorClass::DACrateModifierFactoryClassPtrDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<IDACrateModifierFactoryClass^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<IDACrateModifierFactoryClass^>^>^ DACrateModifierFactoryClassPtrDynamicVectorClass::CreateDACrateModifierFactoryClassPtrDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IDACrateModifierFactoryClass^>^>(gcnew DACrateModifierFactoryClassPtrDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<IDACrateModifierFactoryClass^>^>^ DACrateModifierFactoryClassPtrDynamicVectorClass::CreateDACrateModifierFactoryClassPtrDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IDACrateModifierFactoryClass^>^>(gcnew DACrateModifierFactoryClassPtrDynamicVectorClass(size));
	}

	bool DACrateModifierFactoryClassPtrDynamicVectorClass::Resize(int newSize)
	{
		return InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer->Resize(newSize);
	}

	void DACrateModifierFactoryClassPtrDynamicVectorClass::Clear()
	{
		InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer->Clear();
	}

	int DACrateModifierFactoryClassPtrDynamicVectorClass::ID(IDACrateModifierFactoryClass^ object)
	{
		if (object == nullptr || object->DACrateModifierFactoryClassPointer.ToPointer() == nullptr)
		{
			return InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer->ID(static_cast<::DACrateModifierFactoryClass*>(nullptr));
		}
		else
		{
			return InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer->ID(reinterpret_cast<::DACrateModifierFactoryClass*>(object->DACrateModifierFactoryClassPointer.ToPointer()));
		}
	}

	void DACrateModifierFactoryClassPtrDynamicVectorClass::Insert(int index, IDACrateModifierFactoryClass^ object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (object == nullptr || object->DACrateModifierFactoryClassPointer.ToPointer() == nullptr)
		{
			InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer->Insert(index, reinterpret_cast<::DACrateModifierFactoryClass*>(object->DACrateModifierFactoryClassPointer.ToPointer()));
		}
	}

	bool DACrateModifierFactoryClassPtrDynamicVectorClass::Add(IDACrateModifierFactoryClass^ object)
	{
		if (object == nullptr || object->DACrateModifierFactoryClassPointer.ToPointer() == nullptr)
		{
			return InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer->Add(nullptr);
		}
		else
		{
			return InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer->Add(reinterpret_cast<::DACrateModifierFactoryClass*>(object->DACrateModifierFactoryClassPointer.ToPointer()));
		}
	}

	void DACrateModifierFactoryClassPtrDynamicVectorClass::ResetActive()
	{
		InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer->Reset_Active();
	}

	bool DACrateModifierFactoryClassPtrDynamicVectorClass::AddHead(IDACrateModifierFactoryClass^ object)
	{
		if (object == nullptr || object->DACrateModifierFactoryClassPointer.ToPointer() == nullptr)
		{
			return InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer->Add_Head(reinterpret_cast<::DACrateModifierFactoryClass*>(object->DACrateModifierFactoryClassPointer.ToPointer()));
		}
	}

	bool DACrateModifierFactoryClassPtrDynamicVectorClass::DeleteObj(IDACrateModifierFactoryClass^ object)
	{
		if (object == nullptr || object->DACrateModifierFactoryClassPointer.ToPointer() == nullptr)
		{
			return InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer->DeleteObj(nullptr);
		}
		else
		{
			return InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer->DeleteObj(reinterpret_cast<::DACrateModifierFactoryClass*>(object->DACrateModifierFactoryClassPointer.ToPointer()));
		}
	}

	bool DACrateModifierFactoryClassPtrDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer->Delete(index);
	}

	void DACrateModifierFactoryClassPtrDynamicVectorClass::DeleteAll()
	{
		InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer->Delete_All();
	}

	int DACrateModifierFactoryClassPtrDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void DACrateModifierFactoryClassPtrDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr DACrateModifierFactoryClassPtrDynamicVectorClass::DACrateModifierFactoryClassPtrDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer);
	}

	IDACrateModifierFactoryClass^ DACrateModifierFactoryClassPtrDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DACrateModifierFactoryClass(IntPtr(result));
		}
	}

	void DACrateModifierFactoryClassPtrDynamicVectorClass::default::set(int index, IDACrateModifierFactoryClass^ value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->DACrateModifierFactoryClassPointer.ToPointer() == nullptr)
		{
			InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer->operator[](index) = reinterpret_cast<::DACrateModifierFactoryClass*>(value->DACrateModifierFactoryClassPointer.ToPointer());
		}
	}

	int DACrateModifierFactoryClassPtrDynamicVectorClass::Length::get()
	{
		return InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer->Length();
	}

	int DACrateModifierFactoryClassPtrDynamicVectorClass::Count::get()
	{
		return InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer->Count();
	}

	void DACrateModifierFactoryClassPtrDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer->Set_Active(value);
	}

	int DACrateModifierFactoryClassPtrDynamicVectorClass::GrowthStep::get()
	{
		return InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer->Growth_Step();
	}

	void DACrateModifierFactoryClassPtrDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool DACrateModifierFactoryClassPtrDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyDACrateModifierFactoryClassPtrDynamicVectorClass(InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::DACrateModifierFactoryClass*>* DACrateModifierFactoryClassPtrDynamicVectorClass::InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::DACrateModifierFactoryClass*>*>(Pointer.ToPointer());
	}

	IntPtr DACrateModifierFactoryClassPtrDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateModifierFactoryClass*>*>(InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void DACrateModifierFactoryClassPtrDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateModifierFactoryClass*>*>(InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::DACrateModifierFactoryClass * *>(value.ToPointer()));
	}

	int DACrateModifierFactoryClassPtrDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateModifierFactoryClass*>*>(InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void DACrateModifierFactoryClassPtrDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateModifierFactoryClass*>*>(InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool DACrateModifierFactoryClassPtrDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateModifierFactoryClass*>*>(InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void DACrateModifierFactoryClassPtrDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateModifierFactoryClass*>*>(InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool DACrateModifierFactoryClassPtrDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateModifierFactoryClass*>*>(InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void DACrateModifierFactoryClassPtrDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateModifierFactoryClass*>*>(InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int DACrateModifierFactoryClassPtrDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateModifierFactoryClass*>*>(InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void DACrateModifierFactoryClassPtrDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateModifierFactoryClass*>*>(InternalDACrateModifierFactoryClassPtrDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}