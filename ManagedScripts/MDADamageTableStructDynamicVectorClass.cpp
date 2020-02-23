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
#include "MDADamageTableStructDynamicVectorClass.h"

#include "Mda_damagelog.h"
#include "Imports.h"

namespace RenSharp
{
	DADamageTableStructDynamicVectorClass::DADamageTableStructDynamicVectorClass()
		: DynamicVectorClass<IDADamageTableStruct^>(IntPtr(Imports::CreateDADamageTableStructDynamicVectorClass1()))
	{

	}

	DADamageTableStructDynamicVectorClass::DADamageTableStructDynamicVectorClass(int size)
		: DynamicVectorClass<IDADamageTableStruct^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateDADamageTableStructDynamicVectorClass2(size));
	}

	DADamageTableStructDynamicVectorClass::DADamageTableStructDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<IDADamageTableStruct^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<IDADamageTableStruct^>^>^ DADamageTableStructDynamicVectorClass::CreateDADamageTableStructDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IDADamageTableStruct^>^>(gcnew DADamageTableStructDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<IDADamageTableStruct^>^>^ DADamageTableStructDynamicVectorClass::CreateDADamageTableStructDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IDADamageTableStruct^>^>(gcnew DADamageTableStructDynamicVectorClass(size));
	}

	bool DADamageTableStructDynamicVectorClass::Resize(int newSize)
	{
		return InternalDADamageTableStructDynamicVectorClassPointer->Resize(newSize);
	}

	void DADamageTableStructDynamicVectorClass::Clear()
	{
		InternalDADamageTableStructDynamicVectorClassPointer->Clear();
	}

	int DADamageTableStructDynamicVectorClass::ID(IDADamageTableStruct^ object)
	{
		if (object == nullptr || object->DADamageTableStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		return InternalDADamageTableStructDynamicVectorClassPointer->ID(
			*reinterpret_cast<::DADamageTableStruct*>(object->DADamageTableStructPointer.ToPointer()));
	}

	void DADamageTableStructDynamicVectorClass::Insert(int index, IDADamageTableStruct^ object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}
		else if (object == nullptr || object->DADamageTableStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalDADamageTableStructDynamicVectorClassPointer->Insert(
			index, 
			*reinterpret_cast<::DADamageTableStruct*>(object->DADamageTableStructPointer.ToPointer()));
	}

	bool DADamageTableStructDynamicVectorClass::Add(IDADamageTableStruct^ object)
	{
		if (object == nullptr || object->DADamageTableStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		return InternalDADamageTableStructDynamicVectorClassPointer->Add(
			*reinterpret_cast<::DADamageTableStruct*>(object->DADamageTableStructPointer.ToPointer()));
	}

	void DADamageTableStructDynamicVectorClass::ResetActive()
	{
		InternalDADamageTableStructDynamicVectorClassPointer->Reset_Active();
	}

	bool DADamageTableStructDynamicVectorClass::AddHead(IDADamageTableStruct^ object)
	{
		if (object == nullptr || object->DADamageTableStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		return InternalDADamageTableStructDynamicVectorClassPointer->Add_Head(
			*reinterpret_cast<::DADamageTableStruct*>(object->DADamageTableStructPointer.ToPointer()));
	}

	bool DADamageTableStructDynamicVectorClass::DeleteObj(IDADamageTableStruct^ object)
	{
		if (object == nullptr || object->DADamageTableStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		return InternalDADamageTableStructDynamicVectorClassPointer->DeleteObj(
			*reinterpret_cast<::DADamageTableStruct*>(object->DADamageTableStructPointer.ToPointer()));
	}

	bool DADamageTableStructDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalDADamageTableStructDynamicVectorClassPointer->Delete(index);
	}

	void DADamageTableStructDynamicVectorClass::DeleteAll()
	{
		InternalDADamageTableStructDynamicVectorClassPointer->Delete_All();
	}

	int DADamageTableStructDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalDADamageTableStructDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void DADamageTableStructDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalDADamageTableStructDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr DADamageTableStructDynamicVectorClass::DADamageTableStructDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalDADamageTableStructDynamicVectorClassPointer);
	}

	IDADamageTableStruct^ DADamageTableStructDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto& result = InternalDADamageTableStructDynamicVectorClassPointer->operator[](index);

		return gcnew DADamageTableStruct(IntPtr(&result));
	}

	void DADamageTableStructDynamicVectorClass::default::set(int index, IDADamageTableStruct^ value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}
		else if (value == nullptr || value->DADamageTableStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalDADamageTableStructDynamicVectorClassPointer->operator[](index) = 
			*reinterpret_cast<::DADamageTableStruct*>(value->DADamageTableStructPointer.ToPointer());
	}

	int DADamageTableStructDynamicVectorClass::Length::get()
	{
		return InternalDADamageTableStructDynamicVectorClassPointer->Length();
	}

	int DADamageTableStructDynamicVectorClass::Count::get()
	{
		return InternalDADamageTableStructDynamicVectorClassPointer->Count();
	}

	void DADamageTableStructDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalDADamageTableStructDynamicVectorClassPointer->Set_Active(value);
	}

	int DADamageTableStructDynamicVectorClass::GrowthStep::get()
	{
		return InternalDADamageTableStructDynamicVectorClassPointer->Growth_Step();
	}

	void DADamageTableStructDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalDADamageTableStructDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool DADamageTableStructDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyDADamageTableStructDynamicVectorClass(InternalDADamageTableStructDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::DADamageTableStruct>* DADamageTableStructDynamicVectorClass::InternalDADamageTableStructDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::DADamageTableStruct>*>(Pointer.ToPointer());
	}

	IntPtr DADamageTableStructDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DADamageTableStruct>*>(InternalDADamageTableStructDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void DADamageTableStructDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DADamageTableStruct>*>(InternalDADamageTableStructDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::DADamageTableStruct*>(value.ToPointer()));
	}

	int DADamageTableStructDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DADamageTableStruct>*>(InternalDADamageTableStructDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void DADamageTableStructDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DADamageTableStruct>*>(InternalDADamageTableStructDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool DADamageTableStructDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DADamageTableStruct>*>(InternalDADamageTableStructDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void DADamageTableStructDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DADamageTableStruct>*>(InternalDADamageTableStructDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool DADamageTableStructDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DADamageTableStruct>*>(InternalDADamageTableStructDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void DADamageTableStructDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DADamageTableStruct>*>(InternalDADamageTableStructDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int DADamageTableStructDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DADamageTableStruct>*>(InternalDADamageTableStructDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void DADamageTableStructDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DADamageTableStruct>*>(InternalDADamageTableStructDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}