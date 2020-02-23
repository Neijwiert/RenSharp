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
#include "MStringClassSimpleDynVecClass.h"

#include "Imports.h"

namespace RenSharp
{
	StringClassSimpleDynVecClass::StringClassSimpleDynVecClass()
		: SimpleDynVecClass<String ^>(IntPtr(Imports::CreateStringClassSimpleDynVecClass1()))
	{

	}

	StringClassSimpleDynVecClass::StringClassSimpleDynVecClass(int size)
		: SimpleDynVecClass<String ^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateStringClassSimpleDynVecClass2(size));
	}

	StringClassSimpleDynVecClass::StringClassSimpleDynVecClass(IntPtr pointer)
		: SimpleDynVecClass<String ^>(pointer)
	{

	}

	IUnmanagedContainer<ISimpleDynVecClass<String ^> ^> ^StringClassSimpleDynVecClass::CreateStringClassSimpleDynVecClass()
	{
		return gcnew UnmanagedContainer<ISimpleDynVecClass<String ^> ^>(gcnew StringClassSimpleDynVecClass());
	}

	IUnmanagedContainer<ISimpleDynVecClass<String ^> ^> ^StringClassSimpleDynVecClass::CreateStringClassSimpleDynVecClass(int size)
	{
		return gcnew UnmanagedContainer<ISimpleDynVecClass<String ^> ^>(gcnew StringClassSimpleDynVecClass(size));
	}

	bool StringClassSimpleDynVecClass::Resize(int newSize)
	{
		if (newSize < 0)
		{
			throw gcnew ArgumentOutOfRangeException("newSize");
		}

		return InternalStringClassSimpleDynVecClassPointer->Resize(newSize);
	}

	bool StringClassSimpleDynVecClass::UninitialisedGrow(int newSize)
	{
		if (newSize < 0)
		{
			throw gcnew ArgumentOutOfRangeException("newSize");
		}

		return InternalStringClassSimpleDynVecClassPointer->Uninitialised_Grow(newSize);
	}

	void StringClassSimpleDynVecClass::UninitializedResize(int newSize)
	{
		if (newSize < 0)
		{
			throw gcnew ArgumentOutOfRangeException("newSize");
		}

		InternalStringClassSimpleDynVecClassPointer->Uninitialized_Resize(newSize);
	}

	IntPtr StringClassSimpleDynVecClass::Peek()
	{
		return IntPtr(const_cast<::StringClass *>(InternalStringClassSimpleDynVecClassPointer->Peek()));
	}

#pragma push_macro("ZeroMemory")
#undef ZeroMemory

	void StringClassSimpleDynVecClass::ZeroMemory()

#pragma pop_macro("ZeroMemory")
	{
		InternalStringClassSimpleDynVecClassPointer->Zero_Memory();
	}

	int StringClassSimpleDynVecClass::FindIndex(String ^object)
	{
		if (object == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr objectHandle = Marshal::StringToHGlobalAnsi(object);
		try
		{
			::StringClass tmp = reinterpret_cast<char *>(objectHandle.ToPointer());

			return InternalStringClassSimpleDynVecClassPointer->Find_Index(tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(objectHandle);
		}
	}

	bool StringClassSimpleDynVecClass::Add(String ^data, int newSizeHint)
	{
		if (data == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}
		else if (newSizeHint < 0)
		{
			throw gcnew ArgumentOutOfRangeException("newSizeHint");
		}

		IntPtr dataHandle = Marshal::StringToHGlobalAnsi(data);
		try
		{
			::StringClass tmp = reinterpret_cast<char *>(dataHandle.ToPointer());

			return InternalStringClassSimpleDynVecClassPointer->Add(tmp, newSizeHint);
		}
		finally
		{
			Marshal::FreeHGlobal(dataHandle);
		}
	}

	bool StringClassSimpleDynVecClass::Add(String ^data)
	{
		if (data == nullptr)
		{
			throw gcnew ArgumentNullException("data");
		}

		IntPtr dataHandle = Marshal::StringToHGlobalAnsi(data);
		try
		{
			::StringClass tmp = reinterpret_cast<char *>(dataHandle.ToPointer());

			return InternalStringClassSimpleDynVecClassPointer->Add(tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(dataHandle);
		}
	}

	int StringClassSimpleDynVecClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		int index = Count;

		InternalStringClassSimpleDynVecClassPointer->Add_Multiple(numberToAdd);

		return index;
	}

	bool StringClassSimpleDynVecClass::AddHead(String ^object)
	{
		if (object == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr objectHandle = Marshal::StringToHGlobalAnsi(object);
		try
		{
			::StringClass tmp = reinterpret_cast<char *>(objectHandle.ToPointer());

			return InternalStringClassSimpleDynVecClassPointer->Add_Head(tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(objectHandle);
		}
	}

	void StringClassSimpleDynVecClass::Insert(int index, String ^item)
	{
		if (index < 0 || index > Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}
		else if (item == nullptr)
		{
			throw gcnew ArgumentNullException("item");
		}

		IntPtr itemHandle = Marshal::StringToHGlobalAnsi(item);
		try
		{
			::StringClass tmp = reinterpret_cast<char *>(itemHandle.ToPointer());

			InternalStringClassSimpleDynVecClassPointer->Insert(index, tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(itemHandle);
		}
	}

	bool StringClassSimpleDynVecClass::DeleteIndex(int index, bool allowShrink)
	{
		if (index < 0 || index > Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalStringClassSimpleDynVecClassPointer->Delete(index, allowShrink);
	}

	bool StringClassSimpleDynVecClass::DeleteIndex(int index)
	{
		if (index < 0 || index > Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalStringClassSimpleDynVecClassPointer->Delete(index);
	}

	bool StringClassSimpleDynVecClass::DeleteObject(String ^object, bool allowShrink)
	{
		if (object == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr objectHandle = Marshal::StringToHGlobalAnsi(object);
		try
		{
			::StringClass tmp = reinterpret_cast<char *>(objectHandle.ToPointer());

			return InternalStringClassSimpleDynVecClassPointer->Delete(tmp, allowShrink);
		}
		finally
		{
			Marshal::FreeHGlobal(objectHandle);
		}
	}

	bool StringClassSimpleDynVecClass::DeleteObject(String ^object)
	{
		if (object == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		IntPtr objectHandle = Marshal::StringToHGlobalAnsi(object);
		try
		{
			::StringClass tmp = reinterpret_cast<char *>(objectHandle.ToPointer());

			return InternalStringClassSimpleDynVecClassPointer->Delete(tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(objectHandle);
		}
	}

	bool StringClassSimpleDynVecClass::DeleteRange(int start, int count, bool allowShrink)
	{
		if (start < 0 || start > Count)
		{
			throw gcnew ArgumentOutOfRangeException("start");
		}
		else if (start + count > Count)
		{
			throw gcnew ArgumentOutOfRangeException("count");
		}

		return InternalStringClassSimpleDynVecClassPointer->Delete_Range(start, count, allowShrink);
	}

	bool StringClassSimpleDynVecClass::DeleteRange(int start, int count)
	{
		if (start < 0 || start > Count)
		{
			throw gcnew ArgumentOutOfRangeException("start");
		}
		else if (start + count > Count)
		{
			throw gcnew ArgumentOutOfRangeException("count");
		}

		return InternalStringClassSimpleDynVecClassPointer->Delete_Range(start, count);
	}

	void StringClassSimpleDynVecClass::DeleteAll(bool allowShrink)
	{
		InternalStringClassSimpleDynVecClassPointer->Delete_All(allowShrink);
	}

	void StringClassSimpleDynVecClass::DeleteAll()
	{
		InternalStringClassSimpleDynVecClassPointer->Delete_All();
	}

	IntPtr StringClassSimpleDynVecClass::StringClassSimpleDynVecClassPointer::get()
	{
		return IntPtr(InternalStringClassSimpleDynVecClassPointer);
	}

	int StringClassSimpleDynVecClass::Length::get()
	{
		return InternalStringClassSimpleDynVecClassPointer->Length();
	}

	String ^StringClassSimpleDynVecClass::default::get(int index)
	{
		if (index < 0 || index > Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto &result = InternalStringClassSimpleDynVecClassPointer->operator[](index);

		return gcnew String(result.Peek_Buffer());
	}

	void StringClassSimpleDynVecClass::default::set(int index, String ^value)
	{
		if (index < 0 || index > Count)
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

			InternalStringClassSimpleDynVecClassPointer->operator[](index) = tmp;
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	bool StringClassSimpleDynVecClass::IsEmpty::get()
	{
		return InternalStringClassSimpleDynVecClassPointer->isEmpty();
	}

	int StringClassSimpleDynVecClass::Count::get()
	{
		return InternalStringClassSimpleDynVecClassPointer->Count();
	}

	bool StringClassSimpleDynVecClass::InternalDestroyPointer()
	{
		Imports::DestroyStringClassSimpleDynVecClass(InternalStringClassSimpleDynVecClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	bool StringClassSimpleDynVecClass::Grow(int newSizeHint)
	{
		if (newSizeHint < 0)
		{
			throw gcnew ArgumentOutOfRangeException("newSizeHint");
		}

		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::StringClass> *>(InternalStringClassSimpleDynVecClassPointer);

		return helper->Grow(newSizeHint);
	}

	bool StringClassSimpleDynVecClass::Shrink()
	{
		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::StringClass> *>(InternalStringClassSimpleDynVecClassPointer);

		return helper->Shrink();
	}

	::SimpleDynVecClass<::StringClass> *StringClassSimpleDynVecClass::InternalStringClassSimpleDynVecClassPointer::get()
	{
		return reinterpret_cast<::SimpleDynVecClass<::StringClass> *>(Pointer.ToPointer());
	}

	IntPtr StringClassSimpleDynVecClass::Vector::get()
	{
		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::StringClass> *>(InternalStringClassSimpleDynVecClassPointer);

		return IntPtr(helper->GetVector());
	}

	void StringClassSimpleDynVecClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::StringClass> *>(InternalStringClassSimpleDynVecClassPointer);

		helper->SetVector(reinterpret_cast<::StringClass *>(value.ToPointer()));
	}

	int StringClassSimpleDynVecClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::StringClass> *>(InternalStringClassSimpleDynVecClassPointer);

		return helper->GetVectorMax();
	}

	void StringClassSimpleDynVecClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::StringClass> *>(InternalStringClassSimpleDynVecClassPointer);

		helper->SetVectorMax(value);
	}

	int StringClassSimpleDynVecClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::StringClass> *>(InternalStringClassSimpleDynVecClassPointer);

		return helper->GetActiveCount();
	}

	void StringClassSimpleDynVecClass::ActiveCount::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::StringClass> *>(InternalStringClassSimpleDynVecClassPointer);

		helper->SetActiveCount(value);
	}
}