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
#include "MDACrateFactoryClassPtrDynamicVectorClass.h"

#include "Imports.h"
#include "Mda_crate.h"

namespace RenSharp
{
	DACrateFactoryClassPtrDynamicVectorClass::DACrateFactoryClassPtrDynamicVectorClass()
		: DynamicVectorClass<IDACrateFactoryClass^>(IntPtr(Imports::CreateDACrateFactoryClassPtrDynamicVectorClass1()))
	{

	}

	DACrateFactoryClassPtrDynamicVectorClass::DACrateFactoryClassPtrDynamicVectorClass(int size)
		: DynamicVectorClass<IDACrateFactoryClass^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateDACrateFactoryClassPtrDynamicVectorClass2(size));
	}

	DACrateFactoryClassPtrDynamicVectorClass::DACrateFactoryClassPtrDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<IDACrateFactoryClass^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<IDACrateFactoryClass^>^>^ DACrateFactoryClassPtrDynamicVectorClass::CreateDACrateFactoryClassPtrDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IDACrateFactoryClass^>^>(gcnew DACrateFactoryClassPtrDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<IDACrateFactoryClass^>^>^ DACrateFactoryClassPtrDynamicVectorClass::CreateDACrateFactoryClassPtrDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IDACrateFactoryClass^>^>(gcnew DACrateFactoryClassPtrDynamicVectorClass(size));
	}

	bool DACrateFactoryClassPtrDynamicVectorClass::Resize(int newSize)
	{
		return InternalDACrateFactoryClassPtrDynamicVectorClassPointer->Resize(newSize);
	}

	void DACrateFactoryClassPtrDynamicVectorClass::Clear()
	{
		InternalDACrateFactoryClassPtrDynamicVectorClassPointer->Clear();
	}

	int DACrateFactoryClassPtrDynamicVectorClass::ID(IDACrateFactoryClass^ object)
	{
		if (object == nullptr || object->DACrateFactoryClassPointer.ToPointer() == nullptr)
		{
			return InternalDACrateFactoryClassPtrDynamicVectorClassPointer->ID(static_cast<::DACrateFactoryClass*>(nullptr));
		}
		else
		{
			return InternalDACrateFactoryClassPtrDynamicVectorClassPointer->ID(reinterpret_cast<::DACrateFactoryClass*>(object->DACrateFactoryClassPointer.ToPointer()));
		}
	}

	void DACrateFactoryClassPtrDynamicVectorClass::Insert(int index, IDACrateFactoryClass^ object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (object == nullptr || object->DACrateFactoryClassPointer.ToPointer() == nullptr)
		{
			InternalDACrateFactoryClassPtrDynamicVectorClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalDACrateFactoryClassPtrDynamicVectorClassPointer->Insert(index, reinterpret_cast<::DACrateFactoryClass*>(object->DACrateFactoryClassPointer.ToPointer()));
		}
	}

	bool DACrateFactoryClassPtrDynamicVectorClass::Add(IDACrateFactoryClass^ object)
	{
		if (object == nullptr || object->DACrateFactoryClassPointer.ToPointer() == nullptr)
		{
			return InternalDACrateFactoryClassPtrDynamicVectorClassPointer->Add(nullptr);
		}
		else
		{
			return InternalDACrateFactoryClassPtrDynamicVectorClassPointer->Add(reinterpret_cast<::DACrateFactoryClass*>(object->DACrateFactoryClassPointer.ToPointer()));
		}
	}

	void DACrateFactoryClassPtrDynamicVectorClass::ResetActive()
	{
		InternalDACrateFactoryClassPtrDynamicVectorClassPointer->Reset_Active();
	}

	bool DACrateFactoryClassPtrDynamicVectorClass::AddHead(IDACrateFactoryClass^ object)
	{
		if (object == nullptr || object->DACrateFactoryClassPointer.ToPointer() == nullptr)
		{
			return InternalDACrateFactoryClassPtrDynamicVectorClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalDACrateFactoryClassPtrDynamicVectorClassPointer->Add_Head(reinterpret_cast<::DACrateFactoryClass*>(object->DACrateFactoryClassPointer.ToPointer()));
		}
	}

	bool DACrateFactoryClassPtrDynamicVectorClass::DeleteObj(IDACrateFactoryClass^ object)
	{
		if (object == nullptr || object->DACrateFactoryClassPointer.ToPointer() == nullptr)
		{
			return InternalDACrateFactoryClassPtrDynamicVectorClassPointer->DeleteObj(nullptr);
		}
		else
		{
			return InternalDACrateFactoryClassPtrDynamicVectorClassPointer->DeleteObj(reinterpret_cast<::DACrateFactoryClass*>(object->DACrateFactoryClassPointer.ToPointer()));
		}
	}

	bool DACrateFactoryClassPtrDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalDACrateFactoryClassPtrDynamicVectorClassPointer->Delete(index);
	}

	void DACrateFactoryClassPtrDynamicVectorClass::DeleteAll()
	{
		InternalDACrateFactoryClassPtrDynamicVectorClassPointer->Delete_All();
	}

	int DACrateFactoryClassPtrDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalDACrateFactoryClassPtrDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void DACrateFactoryClassPtrDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalDACrateFactoryClassPtrDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr DACrateFactoryClassPtrDynamicVectorClass::DACrateFactoryClassPtrDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalDACrateFactoryClassPtrDynamicVectorClassPointer);
	}

	IDACrateFactoryClass^ DACrateFactoryClassPtrDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalDACrateFactoryClassPtrDynamicVectorClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DACrateFactoryClass(IntPtr(result));
		}
	}

	void DACrateFactoryClassPtrDynamicVectorClass::default::set(int index, IDACrateFactoryClass^ value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->DACrateFactoryClassPointer.ToPointer() == nullptr)
		{
			InternalDACrateFactoryClassPtrDynamicVectorClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalDACrateFactoryClassPtrDynamicVectorClassPointer->operator[](index) = reinterpret_cast<::DACrateFactoryClass*>(value->DACrateFactoryClassPointer.ToPointer());
		}
	}

	int DACrateFactoryClassPtrDynamicVectorClass::Length::get()
	{
		return InternalDACrateFactoryClassPtrDynamicVectorClassPointer->Length();
	}

	int DACrateFactoryClassPtrDynamicVectorClass::Count::get()
	{
		return InternalDACrateFactoryClassPtrDynamicVectorClassPointer->Count();
	}

	void DACrateFactoryClassPtrDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalDACrateFactoryClassPtrDynamicVectorClassPointer->Set_Active(value);
	}

	int DACrateFactoryClassPtrDynamicVectorClass::GrowthStep::get()
	{
		return InternalDACrateFactoryClassPtrDynamicVectorClassPointer->Growth_Step();
	}

	void DACrateFactoryClassPtrDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalDACrateFactoryClassPtrDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool DACrateFactoryClassPtrDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyDACrateFactoryClassPtrDynamicVectorClass(InternalDACrateFactoryClassPtrDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::DACrateFactoryClass*>* DACrateFactoryClassPtrDynamicVectorClass::InternalDACrateFactoryClassPtrDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::DACrateFactoryClass*>*>(Pointer.ToPointer());
	}

	IntPtr DACrateFactoryClassPtrDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateFactoryClass*>*>(InternalDACrateFactoryClassPtrDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void DACrateFactoryClassPtrDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateFactoryClass*>*>(InternalDACrateFactoryClassPtrDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::DACrateFactoryClass * *>(value.ToPointer()));
	}

	int DACrateFactoryClassPtrDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateFactoryClass*>*>(InternalDACrateFactoryClassPtrDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void DACrateFactoryClassPtrDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateFactoryClass*>*>(InternalDACrateFactoryClassPtrDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool DACrateFactoryClassPtrDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateFactoryClass*>*>(InternalDACrateFactoryClassPtrDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void DACrateFactoryClassPtrDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateFactoryClass*>*>(InternalDACrateFactoryClassPtrDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool DACrateFactoryClassPtrDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateFactoryClass*>*>(InternalDACrateFactoryClassPtrDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void DACrateFactoryClassPtrDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateFactoryClass*>*>(InternalDACrateFactoryClassPtrDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int DACrateFactoryClassPtrDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateFactoryClass*>*>(InternalDACrateFactoryClassPtrDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void DACrateFactoryClassPtrDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateFactoryClass*>*>(InternalDACrateFactoryClassPtrDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}