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
#include "MDACrateModifierClassPtrDynamicVectorClass.h"

#include "Imports.h"
#include "Mda_crate.h"

namespace RenSharp
{
	DACrateModifierClassPtrDynamicVectorClass::DACrateModifierClassPtrDynamicVectorClass()
		: DynamicVectorClass<IDACrateModifierClass^>(IntPtr(Imports::CreateDACrateModifierClassPtrDynamicVectorClass1()))
	{

	}

	DACrateModifierClassPtrDynamicVectorClass::DACrateModifierClassPtrDynamicVectorClass(int size)
		: DynamicVectorClass<IDACrateModifierClass^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateDACrateModifierClassPtrDynamicVectorClass2(size));
	}

	DACrateModifierClassPtrDynamicVectorClass::DACrateModifierClassPtrDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<IDACrateModifierClass^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<IDACrateModifierClass^>^>^ DACrateModifierClassPtrDynamicVectorClass::CreateDACrateModifierClassPtrDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IDACrateModifierClass^>^>(gcnew DACrateModifierClassPtrDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<IDACrateModifierClass^>^>^ DACrateModifierClassPtrDynamicVectorClass::CreateDACrateModifierClassPtrDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IDACrateModifierClass^>^>(gcnew DACrateModifierClassPtrDynamicVectorClass(size));
	}

	bool DACrateModifierClassPtrDynamicVectorClass::Resize(int newSize)
	{
		return InternalDACrateModifierClassPtrDynamicVectorClassPointer->Resize(newSize);
	}

	void DACrateModifierClassPtrDynamicVectorClass::Clear()
	{
		InternalDACrateModifierClassPtrDynamicVectorClassPointer->Clear();
	}

	int DACrateModifierClassPtrDynamicVectorClass::ID(IDACrateModifierClass^ object)
	{
		if (object == nullptr || object->DACrateModifierClassPointer.ToPointer() == nullptr)
		{
			return InternalDACrateModifierClassPtrDynamicVectorClassPointer->ID(static_cast<::DACrateModifierClass*>(nullptr));
		}
		else
		{
			return InternalDACrateModifierClassPtrDynamicVectorClassPointer->ID(reinterpret_cast<::DACrateModifierClass*>(object->DACrateModifierClassPointer.ToPointer()));
		}
	}

	void DACrateModifierClassPtrDynamicVectorClass::Insert(int index, IDACrateModifierClass^ object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (object == nullptr || object->DACrateModifierClassPointer.ToPointer() == nullptr)
		{
			InternalDACrateModifierClassPtrDynamicVectorClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalDACrateModifierClassPtrDynamicVectorClassPointer->Insert(index, reinterpret_cast<::DACrateModifierClass*>(object->DACrateModifierClassPointer.ToPointer()));
		}
	}

	bool DACrateModifierClassPtrDynamicVectorClass::Add(IDACrateModifierClass^ object)
	{
		if (object == nullptr || object->DACrateModifierClassPointer.ToPointer() == nullptr)
		{
			return InternalDACrateModifierClassPtrDynamicVectorClassPointer->Add(nullptr);
		}
		else
		{
			return InternalDACrateModifierClassPtrDynamicVectorClassPointer->Add(reinterpret_cast<::DACrateModifierClass*>(object->DACrateModifierClassPointer.ToPointer()));
		}
	}

	void DACrateModifierClassPtrDynamicVectorClass::ResetActive()
	{
		InternalDACrateModifierClassPtrDynamicVectorClassPointer->Reset_Active();
	}

	bool DACrateModifierClassPtrDynamicVectorClass::AddHead(IDACrateModifierClass^ object)
	{
		if (object == nullptr || object->DACrateModifierClassPointer.ToPointer() == nullptr)
		{
			return InternalDACrateModifierClassPtrDynamicVectorClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalDACrateModifierClassPtrDynamicVectorClassPointer->Add_Head(reinterpret_cast<::DACrateModifierClass*>(object->DACrateModifierClassPointer.ToPointer()));
		}
	}

	bool DACrateModifierClassPtrDynamicVectorClass::DeleteObj(IDACrateModifierClass^ object)
	{
		if (object == nullptr || object->DACrateModifierClassPointer.ToPointer() == nullptr)
		{
			return InternalDACrateModifierClassPtrDynamicVectorClassPointer->DeleteObj(nullptr);
		}
		else
		{
			return InternalDACrateModifierClassPtrDynamicVectorClassPointer->DeleteObj(reinterpret_cast<::DACrateModifierClass*>(object->DACrateModifierClassPointer.ToPointer()));
		}
	}

	bool DACrateModifierClassPtrDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalDACrateModifierClassPtrDynamicVectorClassPointer->Delete(index);
	}

	void DACrateModifierClassPtrDynamicVectorClass::DeleteAll()
	{
		InternalDACrateModifierClassPtrDynamicVectorClassPointer->Delete_All();
	}

	int DACrateModifierClassPtrDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalDACrateModifierClassPtrDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void DACrateModifierClassPtrDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalDACrateModifierClassPtrDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr DACrateModifierClassPtrDynamicVectorClass::DACrateModifierClassPtrDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalDACrateModifierClassPtrDynamicVectorClassPointer);
	}

	IDACrateModifierClass^ DACrateModifierClassPtrDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalDACrateModifierClassPtrDynamicVectorClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DACrateModifierClass(IntPtr(result));
		}
	}

	void DACrateModifierClassPtrDynamicVectorClass::default::set(int index, IDACrateModifierClass^ value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->DACrateModifierClassPointer.ToPointer() == nullptr)
		{
			InternalDACrateModifierClassPtrDynamicVectorClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalDACrateModifierClassPtrDynamicVectorClassPointer->operator[](index) = reinterpret_cast<::DACrateModifierClass*>(value->DACrateModifierClassPointer.ToPointer());
		}
	}

	int DACrateModifierClassPtrDynamicVectorClass::Length::get()
	{
		return InternalDACrateModifierClassPtrDynamicVectorClassPointer->Length();
	}

	int DACrateModifierClassPtrDynamicVectorClass::Count::get()
	{
		return InternalDACrateModifierClassPtrDynamicVectorClassPointer->Count();
	}

	void DACrateModifierClassPtrDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalDACrateModifierClassPtrDynamicVectorClassPointer->Set_Active(value);
	}

	int DACrateModifierClassPtrDynamicVectorClass::GrowthStep::get()
	{
		return InternalDACrateModifierClassPtrDynamicVectorClassPointer->Growth_Step();
	}

	void DACrateModifierClassPtrDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalDACrateModifierClassPtrDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool DACrateModifierClassPtrDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyDACrateModifierClassPtrDynamicVectorClass(InternalDACrateModifierClassPtrDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::DACrateModifierClass*>* DACrateModifierClassPtrDynamicVectorClass::InternalDACrateModifierClassPtrDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::DACrateModifierClass*>*>(Pointer.ToPointer());
	}

	IntPtr DACrateModifierClassPtrDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateModifierClass*>*>(InternalDACrateModifierClassPtrDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void DACrateModifierClassPtrDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateModifierClass*>*>(InternalDACrateModifierClassPtrDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::DACrateModifierClass * *>(value.ToPointer()));
	}

	int DACrateModifierClassPtrDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateModifierClass*>*>(InternalDACrateModifierClassPtrDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void DACrateModifierClassPtrDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateModifierClass*>*>(InternalDACrateModifierClassPtrDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool DACrateModifierClassPtrDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateModifierClass*>*>(InternalDACrateModifierClassPtrDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void DACrateModifierClassPtrDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateModifierClass*>*>(InternalDACrateModifierClassPtrDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool DACrateModifierClassPtrDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateModifierClass*>*>(InternalDACrateModifierClassPtrDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void DACrateModifierClassPtrDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateModifierClass*>*>(InternalDACrateModifierClassPtrDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int DACrateModifierClassPtrDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateModifierClass*>*>(InternalDACrateModifierClassPtrDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void DACrateModifierClassPtrDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DACrateModifierClass*>*>(InternalDACrateModifierClassPtrDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}