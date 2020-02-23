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
#include "MTDBObjClassPtrDynamicVectorClass.h"

#include "Imports.h"
#include "MTDBObjClass.h"

namespace RenSharp
{
	TDBObjClassPtrDynamicVectorClass::TDBObjClassPtrDynamicVectorClass()
		: DynamicVectorClass<ITDBObjClass^>(IntPtr(Imports::CreateTDBObjClassPtrDynamicVectorClass1()))
	{

	}

	TDBObjClassPtrDynamicVectorClass::TDBObjClassPtrDynamicVectorClass(int size)
		: DynamicVectorClass<ITDBObjClass^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateTDBObjClassPtrDynamicVectorClass2(size));
	}

	TDBObjClassPtrDynamicVectorClass::TDBObjClassPtrDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<ITDBObjClass^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<ITDBObjClass^>^>^ TDBObjClassPtrDynamicVectorClass::CreateTDBObjClassPtrDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<ITDBObjClass^>^>(gcnew TDBObjClassPtrDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<ITDBObjClass^>^>^ TDBObjClassPtrDynamicVectorClass::CreateTDBObjClassPtrDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<ITDBObjClass^>^>(gcnew TDBObjClassPtrDynamicVectorClass(size));
	}

	bool TDBObjClassPtrDynamicVectorClass::Resize(int newSize)
	{
		return InternalTDBObjClassPtrDynamicVectorClassPointer->Resize(newSize);
	}

	void TDBObjClassPtrDynamicVectorClass::Clear()
	{
		InternalTDBObjClassPtrDynamicVectorClassPointer->Clear();
	}

	int TDBObjClassPtrDynamicVectorClass::ID(ITDBObjClass^ object)
	{
		if (object == nullptr || object->TDBObjClassPointer.ToPointer() == nullptr)
		{
			return InternalTDBObjClassPtrDynamicVectorClassPointer->ID(static_cast<::TDBObjClass*>(nullptr));
		}
		else
		{
			return InternalTDBObjClassPtrDynamicVectorClassPointer->ID(reinterpret_cast<::TDBObjClass*>(object->TDBObjClassPointer.ToPointer()));
		}
	}

	void TDBObjClassPtrDynamicVectorClass::Insert(int index, ITDBObjClass^ object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (object == nullptr || object->TDBObjClassPointer.ToPointer() == nullptr)
		{
			InternalTDBObjClassPtrDynamicVectorClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalTDBObjClassPtrDynamicVectorClassPointer->Insert(index, reinterpret_cast<::TDBObjClass*>(object->TDBObjClassPointer.ToPointer()));
		}
	}

	bool TDBObjClassPtrDynamicVectorClass::Add(ITDBObjClass^ object)
	{
		if (object == nullptr || object->TDBObjClassPointer.ToPointer() == nullptr)
		{
			return InternalTDBObjClassPtrDynamicVectorClassPointer->Add(nullptr);
		}
		else
		{
			return InternalTDBObjClassPtrDynamicVectorClassPointer->Add(reinterpret_cast<::TDBObjClass*>(object->TDBObjClassPointer.ToPointer()));
		}
	}

	void TDBObjClassPtrDynamicVectorClass::ResetActive()
	{
		InternalTDBObjClassPtrDynamicVectorClassPointer->Reset_Active();
	}

	bool TDBObjClassPtrDynamicVectorClass::AddHead(ITDBObjClass^ object)
	{
		if (object == nullptr || object->TDBObjClassPointer.ToPointer() == nullptr)
		{
			return InternalTDBObjClassPtrDynamicVectorClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalTDBObjClassPtrDynamicVectorClassPointer->Add_Head(reinterpret_cast<::TDBObjClass*>(object->TDBObjClassPointer.ToPointer()));
		}
	}

	bool TDBObjClassPtrDynamicVectorClass::DeleteObj(ITDBObjClass^ object)
	{
		if (object == nullptr || object->TDBObjClassPointer.ToPointer() == nullptr)
		{
			return InternalTDBObjClassPtrDynamicVectorClassPointer->DeleteObj(nullptr);
		}
		else
		{
			return InternalTDBObjClassPtrDynamicVectorClassPointer->DeleteObj(reinterpret_cast<::TDBObjClass*>(object->TDBObjClassPointer.ToPointer()));
		}
	}

	bool TDBObjClassPtrDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalTDBObjClassPtrDynamicVectorClassPointer->Delete(index);
	}

	void TDBObjClassPtrDynamicVectorClass::DeleteAll()
	{
		InternalTDBObjClassPtrDynamicVectorClassPointer->Delete_All();
	}

	int TDBObjClassPtrDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalTDBObjClassPtrDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void TDBObjClassPtrDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalTDBObjClassPtrDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr TDBObjClassPtrDynamicVectorClass::TDBObjClassPtrDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalTDBObjClassPtrDynamicVectorClassPointer);
	}

	ITDBObjClass^ TDBObjClassPtrDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalTDBObjClassPtrDynamicVectorClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew TDBObjClass(IntPtr(result));
		}
	}

	void TDBObjClassPtrDynamicVectorClass::default::set(int index, ITDBObjClass^ value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->TDBObjClassPointer.ToPointer() == nullptr)
		{
			InternalTDBObjClassPtrDynamicVectorClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalTDBObjClassPtrDynamicVectorClassPointer->operator[](index) = reinterpret_cast<::TDBObjClass*>(value->TDBObjClassPointer.ToPointer());
		}
	}

	int TDBObjClassPtrDynamicVectorClass::Length::get()
	{
		return InternalTDBObjClassPtrDynamicVectorClassPointer->Length();
	}

	int TDBObjClassPtrDynamicVectorClass::Count::get()
	{
		return InternalTDBObjClassPtrDynamicVectorClassPointer->Count();
	}

	void TDBObjClassPtrDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalTDBObjClassPtrDynamicVectorClassPointer->Set_Active(value);
	}

	int TDBObjClassPtrDynamicVectorClass::GrowthStep::get()
	{
		return InternalTDBObjClassPtrDynamicVectorClassPointer->Growth_Step();
	}

	void TDBObjClassPtrDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalTDBObjClassPtrDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool TDBObjClassPtrDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyTDBObjClassPtrDynamicVectorClass(InternalTDBObjClassPtrDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::TDBObjClass*>* TDBObjClassPtrDynamicVectorClass::InternalTDBObjClassPtrDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::TDBObjClass*>*>(Pointer.ToPointer());
	}

	IntPtr TDBObjClassPtrDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TDBObjClass*>*>(InternalTDBObjClassPtrDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void TDBObjClassPtrDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TDBObjClass*>*>(InternalTDBObjClassPtrDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::TDBObjClass * *>(value.ToPointer()));
	}

	int TDBObjClassPtrDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TDBObjClass*>*>(InternalTDBObjClassPtrDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void TDBObjClassPtrDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TDBObjClass*>*>(InternalTDBObjClassPtrDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool TDBObjClassPtrDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TDBObjClass*>*>(InternalTDBObjClassPtrDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void TDBObjClassPtrDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TDBObjClass*>*>(InternalTDBObjClassPtrDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool TDBObjClassPtrDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TDBObjClass*>*>(InternalTDBObjClassPtrDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void TDBObjClassPtrDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TDBObjClass*>*>(InternalTDBObjClassPtrDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int TDBObjClassPtrDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TDBObjClass*>*>(InternalTDBObjClassPtrDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void TDBObjClassPtrDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TDBObjClass*>*>(InternalTDBObjClassPtrDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}