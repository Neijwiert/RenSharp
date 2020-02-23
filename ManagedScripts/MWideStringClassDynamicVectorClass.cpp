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
#include "MWideStringClassDynamicVectorClass.h"

#include "Imports.h"

namespace RenSharp
{
	WideStringClassDynamicVectorClass::WideStringClassDynamicVectorClass()
		: DynamicVectorClass<String^>(IntPtr(Imports::CreateWideStringClassDynamicVectorClass1()))
	{

	}

	WideStringClassDynamicVectorClass::WideStringClassDynamicVectorClass(int size)
		: DynamicVectorClass<String^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateWideStringClassDynamicVectorClass2(size));
	}

	WideStringClassDynamicVectorClass::WideStringClassDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<String^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<String^>^>^ WideStringClassDynamicVectorClass::CreateWideStringClassDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<String^>^>(gcnew WideStringClassDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<String^>^>^ WideStringClassDynamicVectorClass::CreateWideStringClassDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<String^>^>(gcnew WideStringClassDynamicVectorClass(size));
	}

	bool WideStringClassDynamicVectorClass::Resize(int newSize)
	{
		return InternalWideStringClassDynamicVectorClassPointer->Resize(newSize);
	}

	void WideStringClassDynamicVectorClass::Clear()
	{
		InternalWideStringClassDynamicVectorClassPointer->Clear();
	}

	int WideStringClassDynamicVectorClass::ID(String^ object)
	{
		if (object == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr objectHandle = Marshal::StringToHGlobalUni(object);
		try
		{
			::WideStringClass tmp = reinterpret_cast<wchar_t*>(objectHandle.ToPointer());

			return InternalWideStringClassDynamicVectorClassPointer->ID(tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(objectHandle);
		}
	}

	void WideStringClassDynamicVectorClass::Insert(int index, String^ object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}
		else if (object == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr objectHandle = Marshal::StringToHGlobalUni(object);
		try
		{
			::WideStringClass tmp = reinterpret_cast<wchar_t*>(objectHandle.ToPointer());

			InternalWideStringClassDynamicVectorClassPointer->Insert(index, tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(objectHandle);
		}
	}

	bool WideStringClassDynamicVectorClass::Add(String^ object)
	{
		if (object == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr objectHandle = Marshal::StringToHGlobalUni(object);
		try
		{
			::WideStringClass tmp = reinterpret_cast<wchar_t*>(objectHandle.ToPointer());

			return InternalWideStringClassDynamicVectorClassPointer->Add(tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(objectHandle);
		}
	}

	void WideStringClassDynamicVectorClass::ResetActive()
	{
		InternalWideStringClassDynamicVectorClassPointer->Reset_Active();
	}

	bool WideStringClassDynamicVectorClass::AddHead(String^ object)
	{
		if (object == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr objectHandle = Marshal::StringToHGlobalUni(object);
		try
		{
			::WideStringClass tmp = reinterpret_cast<wchar_t*>(objectHandle.ToPointer());

			return InternalWideStringClassDynamicVectorClassPointer->Add_Head(tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(objectHandle);
		}
	}

	bool WideStringClassDynamicVectorClass::DeleteObj(String^ object)
	{
		if (object == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr objectHandle = Marshal::StringToHGlobalUni(object);
		try
		{
			::WideStringClass tmp = reinterpret_cast<wchar_t*>(objectHandle.ToPointer());

			return InternalWideStringClassDynamicVectorClassPointer->DeleteObj(tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(objectHandle);
		}
	}

	bool WideStringClassDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalWideStringClassDynamicVectorClassPointer->Delete(index);
	}

	void WideStringClassDynamicVectorClass::DeleteAll()
	{
		InternalWideStringClassDynamicVectorClassPointer->Delete_All();
	}

	int WideStringClassDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalWideStringClassDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void WideStringClassDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalWideStringClassDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr WideStringClassDynamicVectorClass::WideStringClassDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalWideStringClassDynamicVectorClassPointer);
	}

	String^ WideStringClassDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto& result = InternalWideStringClassDynamicVectorClassPointer->operator[](index);

		return gcnew String(result.Peek_Buffer());
	}

	void WideStringClassDynamicVectorClass::default::set(int index, String^ value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}
		else if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalUni(value);
		try
		{
			::WideStringClass tmp = reinterpret_cast<wchar_t*>(valueHandle.ToPointer());

			InternalWideStringClassDynamicVectorClassPointer->operator[](index) = tmp;
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	int WideStringClassDynamicVectorClass::Length::get()
	{
		return InternalWideStringClassDynamicVectorClassPointer->Length();
	}

	int WideStringClassDynamicVectorClass::Count::get()
	{
		return InternalWideStringClassDynamicVectorClassPointer->Count();
	}

	void WideStringClassDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalWideStringClassDynamicVectorClassPointer->Set_Active(value);
	}

	int WideStringClassDynamicVectorClass::GrowthStep::get()
	{
		return InternalWideStringClassDynamicVectorClassPointer->Growth_Step();
	}

	void WideStringClassDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalWideStringClassDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool WideStringClassDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyWideStringClassDynamicVectorClass(InternalWideStringClassDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::WideStringClass>* WideStringClassDynamicVectorClass::InternalWideStringClassDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::WideStringClass>*>(Pointer.ToPointer());
	}

	IntPtr WideStringClassDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::WideStringClass>*>(InternalWideStringClassDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void WideStringClassDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::WideStringClass>*>(InternalWideStringClassDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::WideStringClass*>(value.ToPointer()));
	}

	int WideStringClassDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::WideStringClass>*>(InternalWideStringClassDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void WideStringClassDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::WideStringClass>*>(InternalWideStringClassDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool WideStringClassDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::WideStringClass>*>(InternalWideStringClassDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void WideStringClassDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::WideStringClass>*>(InternalWideStringClassDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool WideStringClassDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::WideStringClass>*>(InternalWideStringClassDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void WideStringClassDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::WideStringClass>*>(InternalWideStringClassDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int WideStringClassDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::WideStringClass>*>(InternalWideStringClassDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void WideStringClassDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::WideStringClass>*>(InternalWideStringClassDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}