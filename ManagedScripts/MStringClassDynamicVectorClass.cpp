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
#include "MStringClassDynamicVectorClass.h"

#include "Imports.h"

namespace RenSharp
{
	StringClassDynamicVectorClass::StringClassDynamicVectorClass()
		: DynamicVectorClass<String ^>(IntPtr(Imports::CreateStringClassDynamicVectorClass1()))
	{

	}

	StringClassDynamicVectorClass::StringClassDynamicVectorClass(int size)
		: DynamicVectorClass<String ^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateStringClassDynamicVectorClass2(size));
	}

	StringClassDynamicVectorClass::StringClassDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<String ^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<String ^> ^> ^StringClassDynamicVectorClass::CreateStringClassDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<String ^> ^>(gcnew StringClassDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<String ^> ^> ^StringClassDynamicVectorClass::CreateStringClassDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<String ^> ^>(gcnew StringClassDynamicVectorClass(size));
	}

	bool StringClassDynamicVectorClass::Resize(int newSize)
	{
		return InternalStringClassDynamicVectorClassPointer->Resize(newSize);
	}

	void StringClassDynamicVectorClass::Clear()
	{
		InternalStringClassDynamicVectorClassPointer->Clear();
	}

	int StringClassDynamicVectorClass::ID(String ^object)
	{
		if (object == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr objectHandle = Marshal::StringToHGlobalAnsi(object);
		try
		{
			::StringClass tmp = reinterpret_cast<char *>(objectHandle.ToPointer());

			return InternalStringClassDynamicVectorClassPointer->ID(tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(objectHandle);
		}
	}

	void StringClassDynamicVectorClass::Insert(int index, String ^object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}
		else if (object == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr objectHandle = Marshal::StringToHGlobalAnsi(object);
		try
		{
			::StringClass tmp = reinterpret_cast<char *>(objectHandle.ToPointer());

			InternalStringClassDynamicVectorClassPointer->Insert(index, tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(objectHandle);
		}
	}

	bool StringClassDynamicVectorClass::Add(String ^object)
	{
		if (object == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr objectHandle = Marshal::StringToHGlobalAnsi(object);
		try
		{
			::StringClass tmp = reinterpret_cast<char *>(objectHandle.ToPointer());

			return InternalStringClassDynamicVectorClassPointer->Add(tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(objectHandle);
		}
	}

	void StringClassDynamicVectorClass::ResetActive()
	{
		InternalStringClassDynamicVectorClassPointer->Reset_Active();
	}

	bool StringClassDynamicVectorClass::AddHead(String ^object)
	{
		if (object == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr objectHandle = Marshal::StringToHGlobalAnsi(object);
		try
		{
			::StringClass tmp = reinterpret_cast<char *>(objectHandle.ToPointer());

			return InternalStringClassDynamicVectorClassPointer->Add_Head(tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(objectHandle);
		}
	}

	bool StringClassDynamicVectorClass::DeleteObj(String ^object)
	{
		if (object == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr objectHandle = Marshal::StringToHGlobalAnsi(object);
		try
		{
			::StringClass tmp = reinterpret_cast<char *>(objectHandle.ToPointer());

			return InternalStringClassDynamicVectorClassPointer->DeleteObj(tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(objectHandle);
		}
	}

	bool StringClassDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalStringClassDynamicVectorClassPointer->Delete(index);
	}

	void StringClassDynamicVectorClass::DeleteAll()
	{
		InternalStringClassDynamicVectorClassPointer->Delete_All();
	}

	int StringClassDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalStringClassDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void StringClassDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalStringClassDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr StringClassDynamicVectorClass::StringClassDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalStringClassDynamicVectorClassPointer);
	}

	String ^StringClassDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto &result = InternalStringClassDynamicVectorClassPointer->operator[](index);

		return gcnew String(result.Peek_Buffer());
	}

	void StringClassDynamicVectorClass::default::set(int index, String ^value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}
		else if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			::StringClass tmp = reinterpret_cast<char *>(valueHandle.ToPointer());

			InternalStringClassDynamicVectorClassPointer->operator[](index) = tmp;
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	int StringClassDynamicVectorClass::Length::get()
	{
		return InternalStringClassDynamicVectorClassPointer->Length();
	}

	int StringClassDynamicVectorClass::Count::get()
	{
		return InternalStringClassDynamicVectorClassPointer->Count();
	}

	void StringClassDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalStringClassDynamicVectorClassPointer->Set_Active(value);
	}

	int StringClassDynamicVectorClass::GrowthStep::get()
	{
		return InternalStringClassDynamicVectorClassPointer->Growth_Step();
	}

	void StringClassDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalStringClassDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool StringClassDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyStringClassDynamicVectorClass(InternalStringClassDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::StringClass> *StringClassDynamicVectorClass::InternalStringClassDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::StringClass> *>(Pointer.ToPointer());
	}

	IntPtr StringClassDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::StringClass> *>(InternalStringClassDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void StringClassDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::StringClass> *>(InternalStringClassDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::StringClass *>(value.ToPointer()));
	}

	int StringClassDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::StringClass> *>(InternalStringClassDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void StringClassDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::StringClass> *>(InternalStringClassDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool StringClassDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::StringClass> *>(InternalStringClassDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void StringClassDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::StringClass> *>(InternalStringClassDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool StringClassDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::StringClass> *>(InternalStringClassDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void StringClassDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::StringClass> *>(InternalStringClassDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int StringClassDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::StringClass> *>(InternalStringClassDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void StringClassDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::StringClass> *>(InternalStringClassDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}