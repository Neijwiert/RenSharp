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
#include "MConstDefinitionClassPtrDynamicVectorClass.h"

#include "MDefinition.h"
#include "Imports.h"

namespace RenSharp
{
	ConstDefinitionClassPtrDynamicVectorClass::ConstDefinitionClassPtrDynamicVectorClass()
		: DynamicVectorClass<IDefinitionClass^>(IntPtr(Imports::CreateConstDefinitionClassPtrDynamicVectorClass1()))
	{

	}

	ConstDefinitionClassPtrDynamicVectorClass::ConstDefinitionClassPtrDynamicVectorClass(int size)
		: DynamicVectorClass<IDefinitionClass^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateConstDefinitionClassPtrDynamicVectorClass2(size));
	}

	ConstDefinitionClassPtrDynamicVectorClass::ConstDefinitionClassPtrDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<IDefinitionClass^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<IDefinitionClass^>^>^ ConstDefinitionClassPtrDynamicVectorClass::CreateConstDefinitionClassPtrDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IDefinitionClass^>^>(gcnew ConstDefinitionClassPtrDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<IDefinitionClass^>^>^ ConstDefinitionClassPtrDynamicVectorClass::CreateConstDefinitionClassPtrDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IDefinitionClass^>^>(gcnew ConstDefinitionClassPtrDynamicVectorClass(size));
	}

	bool ConstDefinitionClassPtrDynamicVectorClass::Resize(int newSize)
	{
		return InternalConstDefinitionClassPtrDynamicVectorClassPointer->Resize(newSize);
	}

	void ConstDefinitionClassPtrDynamicVectorClass::Clear()
	{
		InternalConstDefinitionClassPtrDynamicVectorClassPointer->Clear();
	}

	int ConstDefinitionClassPtrDynamicVectorClass::ID(IDefinitionClass^ object)
	{
		if (object == nullptr || object->DefinitionClassPointer.ToPointer() == nullptr)
		{
			return InternalConstDefinitionClassPtrDynamicVectorClassPointer->ID(static_cast<::DefinitionClass*>(nullptr));
		}
		else
		{
			return InternalConstDefinitionClassPtrDynamicVectorClassPointer->ID(reinterpret_cast<::DefinitionClass*>(object->DefinitionClassPointer.ToPointer()));
		}
	}

	void ConstDefinitionClassPtrDynamicVectorClass::Insert(int index, IDefinitionClass^ object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (object == nullptr || object->DefinitionClassPointer.ToPointer() == nullptr)
		{
			InternalConstDefinitionClassPtrDynamicVectorClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalConstDefinitionClassPtrDynamicVectorClassPointer->Insert(index, reinterpret_cast<::DefinitionClass*>(object->DefinitionClassPointer.ToPointer()));
		}
	}

	bool ConstDefinitionClassPtrDynamicVectorClass::Add(IDefinitionClass^ object)
	{
		if (object == nullptr || object->DefinitionClassPointer.ToPointer() == nullptr)
		{
			return InternalConstDefinitionClassPtrDynamicVectorClassPointer->Add(nullptr);
		}
		else
		{
			return InternalConstDefinitionClassPtrDynamicVectorClassPointer->Add(reinterpret_cast<::DefinitionClass*>(object->DefinitionClassPointer.ToPointer()));
		}
	}

	void ConstDefinitionClassPtrDynamicVectorClass::ResetActive()
	{
		InternalConstDefinitionClassPtrDynamicVectorClassPointer->Reset_Active();
	}

	bool ConstDefinitionClassPtrDynamicVectorClass::AddHead(IDefinitionClass^ object)
	{
		if (object == nullptr || object->DefinitionClassPointer.ToPointer() == nullptr)
		{
			return InternalConstDefinitionClassPtrDynamicVectorClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalConstDefinitionClassPtrDynamicVectorClassPointer->Add_Head(reinterpret_cast<::DefinitionClass*>(object->DefinitionClassPointer.ToPointer()));
		}
	}

	bool ConstDefinitionClassPtrDynamicVectorClass::DeleteObj(IDefinitionClass^ object)
	{
		if (object == nullptr || object->DefinitionClassPointer.ToPointer() == nullptr)
		{
			return InternalConstDefinitionClassPtrDynamicVectorClassPointer->DeleteObj(nullptr);
		}
		else
		{
			return InternalConstDefinitionClassPtrDynamicVectorClassPointer->DeleteObj(reinterpret_cast<::DefinitionClass*>(object->DefinitionClassPointer.ToPointer()));
		}
	}

	bool ConstDefinitionClassPtrDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalConstDefinitionClassPtrDynamicVectorClassPointer->Delete(index);
	}

	void ConstDefinitionClassPtrDynamicVectorClass::DeleteAll()
	{
		InternalConstDefinitionClassPtrDynamicVectorClassPointer->Delete_All();
	}

	int ConstDefinitionClassPtrDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalConstDefinitionClassPtrDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void ConstDefinitionClassPtrDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalConstDefinitionClassPtrDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr ConstDefinitionClassPtrDynamicVectorClass::ConstDefinitionClassPtrDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalConstDefinitionClassPtrDynamicVectorClassPointer);
	}

	IDefinitionClass^ ConstDefinitionClassPtrDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalConstDefinitionClassPtrDynamicVectorClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DefinitionClass(IntPtr(const_cast<::DefinitionClass*>(result)));
		}
	}

	void ConstDefinitionClassPtrDynamicVectorClass::default::set(int index, IDefinitionClass^ value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->DefinitionClassPointer.ToPointer() == nullptr)
		{
			InternalConstDefinitionClassPtrDynamicVectorClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalConstDefinitionClassPtrDynamicVectorClassPointer->operator[](index) = reinterpret_cast<::DefinitionClass*>(value->DefinitionClassPointer.ToPointer());
		}
	}

	int ConstDefinitionClassPtrDynamicVectorClass::Length::get()
	{
		return InternalConstDefinitionClassPtrDynamicVectorClassPointer->Length();
	}

	int ConstDefinitionClassPtrDynamicVectorClass::Count::get()
	{
		return InternalConstDefinitionClassPtrDynamicVectorClassPointer->Count();
	}

	void ConstDefinitionClassPtrDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalConstDefinitionClassPtrDynamicVectorClassPointer->Set_Active(value);
	}

	int ConstDefinitionClassPtrDynamicVectorClass::GrowthStep::get()
	{
		return InternalConstDefinitionClassPtrDynamicVectorClassPointer->Growth_Step();
	}

	void ConstDefinitionClassPtrDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalConstDefinitionClassPtrDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool ConstDefinitionClassPtrDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyConstDefinitionClassPtrDynamicVectorClass(InternalConstDefinitionClassPtrDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<const ::DefinitionClass*>* ConstDefinitionClassPtrDynamicVectorClass::InternalConstDefinitionClassPtrDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<const ::DefinitionClass*>*>(Pointer.ToPointer());
	}

	IntPtr ConstDefinitionClassPtrDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DefinitionClass*>*>(InternalConstDefinitionClassPtrDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void ConstDefinitionClassPtrDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DefinitionClass*>*>(InternalConstDefinitionClassPtrDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::DefinitionClass * *>(value.ToPointer()));
	}

	int ConstDefinitionClassPtrDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DefinitionClass*>*>(InternalConstDefinitionClassPtrDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void ConstDefinitionClassPtrDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DefinitionClass*>*>(InternalConstDefinitionClassPtrDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool ConstDefinitionClassPtrDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DefinitionClass*>*>(InternalConstDefinitionClassPtrDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void ConstDefinitionClassPtrDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DefinitionClass*>*>(InternalConstDefinitionClassPtrDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool ConstDefinitionClassPtrDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DefinitionClass*>*>(InternalConstDefinitionClassPtrDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void ConstDefinitionClassPtrDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DefinitionClass*>*>(InternalConstDefinitionClassPtrDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int ConstDefinitionClassPtrDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DefinitionClass*>*>(InternalConstDefinitionClassPtrDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void ConstDefinitionClassPtrDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DefinitionClass*>*>(InternalConstDefinitionClassPtrDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}