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
#include "MIntSimpleDynVecClass.h"

#include "Imports.h"

namespace RenSharp
{
	IntSimpleDynVecClass::IntSimpleDynVecClass()
		: SimpleDynVecClass<int>(IntPtr(Imports::CreateIntSimpleDynVecClass1()))
	{

	}

	IntSimpleDynVecClass::IntSimpleDynVecClass(int size)
		: SimpleDynVecClass<int>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateIntSimpleDynVecClass2(size));
	}

	IntSimpleDynVecClass::IntSimpleDynVecClass(IntPtr pointer)
		: SimpleDynVecClass<int>(pointer)
	{

	}

	IUnmanagedContainer<ISimpleDynVecClass<int> ^> ^IntSimpleDynVecClass::CreateIntSimpleDynVecClass()
	{
		return gcnew UnmanagedContainer<ISimpleDynVecClass<int> ^>(gcnew IntSimpleDynVecClass());
	}

	IUnmanagedContainer<ISimpleDynVecClass<int> ^> ^IntSimpleDynVecClass::CreateIntSimpleDynVecClass(int size)
	{
		return gcnew UnmanagedContainer<ISimpleDynVecClass<int> ^>(gcnew IntSimpleDynVecClass(size));
	}

	bool IntSimpleDynVecClass::Resize(int newSize)
	{
		if (newSize < 0)
		{
			throw gcnew ArgumentOutOfRangeException("newSize");
		}

		return InternalIntSimpleDynVecClassPointer->Resize(newSize);
	}

	bool IntSimpleDynVecClass::UninitialisedGrow(int newSize)
	{
		if (newSize < 0)
		{
			throw gcnew ArgumentOutOfRangeException("newSize");
		}

		return InternalIntSimpleDynVecClassPointer->Uninitialised_Grow(newSize);
	}

	void IntSimpleDynVecClass::UninitializedResize(int newSize)
	{
		if (newSize < 0)
		{
			throw gcnew ArgumentOutOfRangeException("newSize");
		}

		InternalIntSimpleDynVecClassPointer->Uninitialized_Resize(newSize);
	}

	IntPtr IntSimpleDynVecClass::Peek()
	{
		return IntPtr(const_cast<int *>(InternalIntSimpleDynVecClassPointer->Peek()));
	}

#pragma push_macro("ZeroMemory")
#undef ZeroMemory
	void IntSimpleDynVecClass::ZeroMemory()
#pragma pop_macro("ZeroMemory")
	{
		InternalIntSimpleDynVecClassPointer->Zero_Memory();
	}

	int IntSimpleDynVecClass::FindIndex(int object)
	{
		return InternalIntSimpleDynVecClassPointer->Find_Index(object);
	}

	bool IntSimpleDynVecClass::Add(int data, int newSizeHint)
	{
		if (newSizeHint < 0)
		{
			throw gcnew ArgumentOutOfRangeException("newSizeHint");
		}

		return InternalIntSimpleDynVecClassPointer->Add(data, newSizeHint);
	}

	bool IntSimpleDynVecClass::Add(int data)
	{
		return InternalIntSimpleDynVecClassPointer->Add(data);
	}

	int IntSimpleDynVecClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		int index = Count;

		InternalIntSimpleDynVecClassPointer->Add_Multiple(numberToAdd);

		return index;
	}

	bool IntSimpleDynVecClass::AddHead(int object)
	{
		return InternalIntSimpleDynVecClassPointer->Add_Head(object);
	}

	void IntSimpleDynVecClass::Insert(int index, int item)
	{
		if (index < 0 || index > Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		InternalIntSimpleDynVecClassPointer->Insert(index, item);
	}

	bool IntSimpleDynVecClass::DeleteIndex(int index, bool allowShrink)
	{
		if (index < 0 || index > Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		int *vector = InternalIntSimpleDynVecClassPointer->Peek();
		if (index < Count - 1)
		{
			std::memmove(&(vector[index]), &(vector[index + 1]), (Count - index - 1) * sizeof(int));
		}

		ActiveCount--;

		if (allowShrink)
		{
			Shrink();
		}

		return true;
	}

	bool IntSimpleDynVecClass::DeleteIndex(int index)
	{
		return DeleteIndex(index, true);
	}

	bool IntSimpleDynVecClass::DeleteObject(int object, bool allowShrink)
	{
		int index = InternalIntSimpleDynVecClassPointer->Find_Index(object);
		if (index != -1)
		{
			return DeleteIndex(index, allowShrink);
		}

		return false;
	}

	bool IntSimpleDynVecClass::DeleteObject(int object)
	{
		return DeleteObject(object, true);
	}

	bool IntSimpleDynVecClass::DeleteRange(int start, int count, bool allowShrink)
	{
		if (start < 0 || start > Count)
		{
			throw gcnew ArgumentOutOfRangeException("start");
		}
		else if (start + count > Count)
		{
			throw gcnew ArgumentOutOfRangeException("count");
		}

		return InternalIntSimpleDynVecClassPointer->Delete_Range(start, count, allowShrink);
	}

	bool IntSimpleDynVecClass::DeleteRange(int start, int count)
	{
		if (start < 0 || start > Count)
		{
			throw gcnew ArgumentOutOfRangeException("start");
		}
		else if (start + count > Count)
		{
			throw gcnew ArgumentOutOfRangeException("count");
		}

		return InternalIntSimpleDynVecClassPointer->Delete_Range(start, count);
	}

	void IntSimpleDynVecClass::DeleteAll(bool allowShrink)
	{
		InternalIntSimpleDynVecClassPointer->Delete_All(allowShrink);
	}

	void IntSimpleDynVecClass::DeleteAll()
	{
		InternalIntSimpleDynVecClassPointer->Delete_All();
	}

	IntPtr IntSimpleDynVecClass::IntSimpleDynVecClassPointer::get()
	{
		return IntPtr(InternalIntSimpleDynVecClassPointer);
	}

	int IntSimpleDynVecClass::Length::get()
	{
		return InternalIntSimpleDynVecClassPointer->Length();
	}

	int IntSimpleDynVecClass::default::get(int index)
	{
		if (index < 0 || index > Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalIntSimpleDynVecClassPointer->operator[](index);
	}

	void IntSimpleDynVecClass::default::set(int index, int value)
	{
		if (index < 0 || index > Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		InternalIntSimpleDynVecClassPointer->operator[](index) = value;
	}

	bool IntSimpleDynVecClass::IsEmpty::get()
	{
		return InternalIntSimpleDynVecClassPointer->isEmpty();
	}

	int IntSimpleDynVecClass::Count::get()
	{
		return InternalIntSimpleDynVecClassPointer->Count();
	}

	bool IntSimpleDynVecClass::InternalDestroyPointer()
	{
		Imports::DestroyIntSimpleDynVecClass(InternalIntSimpleDynVecClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	bool IntSimpleDynVecClass::Grow(int newSizeHint)
	{
		if (newSizeHint < 0)
		{
			throw gcnew ArgumentOutOfRangeException("newSizeHint");
		}

		auto helper = reinterpret_cast<SimpleDynVecClassHelper<int> *>(InternalIntSimpleDynVecClassPointer);

		return helper->Grow(newSizeHint);
	}

	bool IntSimpleDynVecClass::Shrink()
	{
		auto helper = reinterpret_cast<SimpleDynVecClassHelper<int> *>(InternalIntSimpleDynVecClassPointer);

		return helper->Shrink();
	}

	::SimpleDynVecClass<int> *IntSimpleDynVecClass::InternalIntSimpleDynVecClassPointer::get()
	{
		return reinterpret_cast<::SimpleDynVecClass<int> *>(Pointer.ToPointer());
	}

	IntPtr IntSimpleDynVecClass::Vector::get()
	{
		auto helper = reinterpret_cast<SimpleDynVecClassHelper<int> *>(InternalIntSimpleDynVecClassPointer);

		return IntPtr(helper->GetVector());
	}

	void IntSimpleDynVecClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<SimpleDynVecClassHelper<int> *>(InternalIntSimpleDynVecClassPointer);

		helper->SetVector(reinterpret_cast<int *>(value.ToPointer()));
	}

	int IntSimpleDynVecClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<SimpleDynVecClassHelper<int> *>(InternalIntSimpleDynVecClassPointer);

		return helper->GetVectorMax();
	}

	void IntSimpleDynVecClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<SimpleDynVecClassHelper<int> *>(InternalIntSimpleDynVecClassPointer);

		helper->SetVectorMax(value);
	}

	int IntSimpleDynVecClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<SimpleDynVecClassHelper<int> *>(InternalIntSimpleDynVecClassPointer);

		return helper->GetActiveCount();
	}

	void IntSimpleDynVecClass::ActiveCount::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<SimpleDynVecClassHelper<int> *>(InternalIntSimpleDynVecClassPointer);

		helper->SetActiveCount(value);
	}
}