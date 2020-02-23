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
#include "MInt32DynamicVectorClass.h"

#include "Imports.h"

namespace RenSharp
{
	Int32DynamicVectorClass::Int32DynamicVectorClass()
		: DynamicVectorClass<int>(IntPtr(Imports::CreateInt32DynamicVectorClass1()))
	{

	}

	Int32DynamicVectorClass::Int32DynamicVectorClass(int size)
		: DynamicVectorClass<int>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateInt32DynamicVectorClass2(size));
	}

	Int32DynamicVectorClass::Int32DynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<int>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<int> ^> ^Int32DynamicVectorClass::CreateInt32DynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<int> ^>(gcnew Int32DynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<int> ^> ^Int32DynamicVectorClass::CreateInt32DynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<int> ^>(gcnew Int32DynamicVectorClass(size));
	}

	bool Int32DynamicVectorClass::Resize(int newSize)
	{
		return InternalInt32DynamicVectorClassPointer->Resize(newSize);
	}

	void Int32DynamicVectorClass::Clear()
	{
		InternalInt32DynamicVectorClassPointer->Clear();
	}

	int Int32DynamicVectorClass::ID(int object)
	{
		return InternalInt32DynamicVectorClassPointer->ID(object);
	}

	void Int32DynamicVectorClass::Insert(int index, int object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		InternalInt32DynamicVectorClassPointer->Insert(index, object);
	}

	bool Int32DynamicVectorClass::Add(int object)
	{
		return InternalInt32DynamicVectorClassPointer->Add(object);
	}

	void Int32DynamicVectorClass::ResetActive()
	{
		InternalInt32DynamicVectorClassPointer->Reset_Active();
	}

	bool Int32DynamicVectorClass::AddHead(int object)
	{
		return InternalInt32DynamicVectorClassPointer->Add_Head(object);
	}

	bool Int32DynamicVectorClass::DeleteObj(int object)
	{
		return InternalInt32DynamicVectorClassPointer->DeleteObj(object);
	}

	bool Int32DynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalInt32DynamicVectorClassPointer->Delete(index);
	}

	void Int32DynamicVectorClass::DeleteAll()
	{
		InternalInt32DynamicVectorClassPointer->Delete_All();
	}

	int Int32DynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalInt32DynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void Int32DynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalInt32DynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr Int32DynamicVectorClass::Int32DynamicVectorClassPointer::get()
	{
		return IntPtr(InternalInt32DynamicVectorClassPointer);
	}

	int Int32DynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalInt32DynamicVectorClassPointer->operator[](index);
	}

	void Int32DynamicVectorClass::default::set(int index, int value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		InternalInt32DynamicVectorClassPointer->operator[](index) = value;
	}

	int Int32DynamicVectorClass::Length::get()
	{
		return InternalInt32DynamicVectorClassPointer->Length();
	}

	int Int32DynamicVectorClass::Count::get()
	{
		return InternalInt32DynamicVectorClassPointer->Count();
	}

	void Int32DynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalInt32DynamicVectorClassPointer->Set_Active(value);
	}

	int Int32DynamicVectorClass::GrowthStep::get()
	{
		return InternalInt32DynamicVectorClassPointer->Growth_Step();
	}

	void Int32DynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalInt32DynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool Int32DynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyInt32DynamicVectorClass(InternalInt32DynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<int> *Int32DynamicVectorClass::InternalInt32DynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<int> *>(Pointer.ToPointer());
	}

	IntPtr Int32DynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<int> *>(InternalInt32DynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void Int32DynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<int> *>(InternalInt32DynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<int *>(value.ToPointer()));
	}

	int Int32DynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<int> *>(InternalInt32DynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void Int32DynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<int> *>(InternalInt32DynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool Int32DynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<int> *>(InternalInt32DynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void Int32DynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<int> *>(InternalInt32DynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool Int32DynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<int> *>(InternalInt32DynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void Int32DynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<int> *>(InternalInt32DynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int Int32DynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<int> *>(InternalInt32DynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void Int32DynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<int> *>(InternalInt32DynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}