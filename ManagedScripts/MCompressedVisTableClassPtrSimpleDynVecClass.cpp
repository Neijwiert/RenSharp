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
#include "MCompressedVisTableClassPtrSimpleDynVecClass.h"

#include "MVisTableClass.h"
#include "Imports.h"

namespace RenSharp
{
	CompressedVisTableClassPtrSimpleDynVecClass::CompressedVisTableClassPtrSimpleDynVecClass()
		: SimpleDynVecClass<ICompressedVisTableClass^>(IntPtr(Imports::CreateCompressedVisTableClassPtrSimpleDynVecClass1()))
	{

	}

	CompressedVisTableClassPtrSimpleDynVecClass::CompressedVisTableClassPtrSimpleDynVecClass(int size)
		: SimpleDynVecClass<ICompressedVisTableClass^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateCompressedVisTableClassPtrSimpleDynVecClass2(size));
	}

	CompressedVisTableClassPtrSimpleDynVecClass::CompressedVisTableClassPtrSimpleDynVecClass(IntPtr pointer)
		: SimpleDynVecClass<ICompressedVisTableClass^>(pointer)
	{

	}

	IUnmanagedContainer<ISimpleDynVecClass<ICompressedVisTableClass^>^>^ CompressedVisTableClassPtrSimpleDynVecClass::CreateCompressedVisTableClassPtrSimpleDynVecClass()
	{
		return gcnew UnmanagedContainer<ISimpleDynVecClass<ICompressedVisTableClass^>^>(gcnew CompressedVisTableClassPtrSimpleDynVecClass());
	}

	IUnmanagedContainer<ISimpleDynVecClass<ICompressedVisTableClass^>^>^ CompressedVisTableClassPtrSimpleDynVecClass::CreateCompressedVisTableClassPtrSimpleDynVecClass(int size)
	{
		return gcnew UnmanagedContainer<ISimpleDynVecClass<ICompressedVisTableClass^>^>(gcnew CompressedVisTableClassPtrSimpleDynVecClass(size));
	}

	bool CompressedVisTableClassPtrSimpleDynVecClass::Resize(int newSize)
	{
		if (newSize < 0)
		{
			throw gcnew ArgumentOutOfRangeException("newSize");
		}

		return InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Resize(newSize);
	}

	bool CompressedVisTableClassPtrSimpleDynVecClass::UninitialisedGrow(int newSize)
	{
		if (newSize < 0)
		{
			throw gcnew ArgumentOutOfRangeException("newSize");
		}

		return InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Uninitialised_Grow(newSize);
	}

	void CompressedVisTableClassPtrSimpleDynVecClass::UninitializedResize(int newSize)
	{
		if (newSize < 0)
		{
			throw gcnew ArgumentOutOfRangeException("newSize");
		}

		InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Uninitialized_Resize(newSize);
	}

	IntPtr CompressedVisTableClassPtrSimpleDynVecClass::Peek()
	{
		return IntPtr(const_cast<::CompressedVisTableClass * *>(InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Peek()));
	}

#pragma push_macro("ZeroMemory")
#undef ZeroMemory

	void CompressedVisTableClassPtrSimpleDynVecClass::ZeroMemory()

#pragma pop_macro("ZeroMemory")
	{
		InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Zero_Memory();
	}

	int CompressedVisTableClassPtrSimpleDynVecClass::FindIndex(ICompressedVisTableClass^ object)
	{
		if (object == nullptr || object->CompressedVisTableClassPointer.ToPointer() == nullptr)
		{
			return InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Find_Index(nullptr);
		}
		else
		{
			return InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Find_Index(reinterpret_cast<::CompressedVisTableClass*>(object->CompressedVisTableClassPointer.ToPointer()));
		}
	}

	bool CompressedVisTableClassPtrSimpleDynVecClass::Add(ICompressedVisTableClass^ data, int newSizeHint)
	{
		if (newSizeHint < 0)
		{
			throw gcnew ArgumentOutOfRangeException("newSizeHint");
		}

		if (data == nullptr || data->CompressedVisTableClassPointer.ToPointer() == nullptr)
		{
			return InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Add(nullptr, newSizeHint);
		}
		else
		{
			return InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Add(reinterpret_cast<::CompressedVisTableClass*>(data->CompressedVisTableClassPointer.ToPointer()), newSizeHint);
		}
	}

	bool CompressedVisTableClassPtrSimpleDynVecClass::Add(ICompressedVisTableClass^ data)
	{
		if (data == nullptr || data->CompressedVisTableClassPointer.ToPointer() == nullptr)
		{
			return InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Add(nullptr);
		}
		else
		{
			return InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Add(reinterpret_cast<::CompressedVisTableClass*>(data->CompressedVisTableClassPointer.ToPointer()));
		}
	}

	int CompressedVisTableClassPtrSimpleDynVecClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		int index = Count;

		InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Add_Multiple(numberToAdd);

		return index;
	}

	bool CompressedVisTableClassPtrSimpleDynVecClass::AddHead(ICompressedVisTableClass^ object)
	{
		if (object == nullptr || object->CompressedVisTableClassPointer.ToPointer() == nullptr)
		{
			return InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Add_Head(reinterpret_cast<::CompressedVisTableClass*>(object->CompressedVisTableClassPointer.ToPointer()));
		}
	}

	void CompressedVisTableClassPtrSimpleDynVecClass::Insert(int index, ICompressedVisTableClass^ item)
	{
		if (index < 0 || index > Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (item == nullptr || item->CompressedVisTableClassPointer.ToPointer() == nullptr)
		{
			InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Insert(index, reinterpret_cast<::CompressedVisTableClass*>(item->CompressedVisTableClassPointer.ToPointer()));
		}
	}

	bool CompressedVisTableClassPtrSimpleDynVecClass::DeleteIndex(int index, bool allowShrink)
	{
		if (index < 0 || index > Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Delete(index, allowShrink);
	}

	bool CompressedVisTableClassPtrSimpleDynVecClass::DeleteIndex(int index)
	{
		if (index < 0 || index > Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Delete(index);
	}

	bool CompressedVisTableClassPtrSimpleDynVecClass::DeleteObject(ICompressedVisTableClass^ object, bool allowShrink)
	{
		if (object == nullptr || object->CompressedVisTableClassPointer.ToPointer() == nullptr)
		{
			return InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Delete(nullptr, allowShrink);
		}
		else
		{
			return InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Delete(reinterpret_cast<::CompressedVisTableClass*>(object->CompressedVisTableClassPointer.ToPointer()));
		}
	}

	bool CompressedVisTableClassPtrSimpleDynVecClass::DeleteObject(ICompressedVisTableClass^ object)
	{
		if (object == nullptr || object->CompressedVisTableClassPointer.ToPointer() == nullptr)
		{
			return InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Delete(nullptr);
		}
		else
		{
			return InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Delete(reinterpret_cast<::CompressedVisTableClass*>(object->CompressedVisTableClassPointer.ToPointer()));
		}
	}

	bool CompressedVisTableClassPtrSimpleDynVecClass::DeleteRange(int start, int count, bool allowShrink)
	{
		if (start < 0 || start > Count)
		{
			throw gcnew ArgumentOutOfRangeException("start");
		}
		else if (start + count > Count)
		{
			throw gcnew ArgumentOutOfRangeException("count");
		}

		return InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Delete_Range(start, count, allowShrink);
	}

	bool CompressedVisTableClassPtrSimpleDynVecClass::DeleteRange(int start, int count)
	{
		if (start < 0 || start > Count)
		{
			throw gcnew ArgumentOutOfRangeException("start");
		}
		else if (start + count > Count)
		{
			throw gcnew ArgumentOutOfRangeException("count");
		}

		return InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Delete_Range(start, count);
	}

	void CompressedVisTableClassPtrSimpleDynVecClass::DeleteAll(bool allowShrink)
	{
		InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Delete_All(allowShrink);
	}

	void CompressedVisTableClassPtrSimpleDynVecClass::DeleteAll()
	{
		InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Delete_All();
	}

	IntPtr CompressedVisTableClassPtrSimpleDynVecClass::CompressedVisTableClassPtrSimpleDynVecClassPointer::get()
	{
		return IntPtr(InternalCompressedVisTableClassPtrSimpleDynVecClassPointer);
	}

	int CompressedVisTableClassPtrSimpleDynVecClass::Length::get()
	{
		return InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Length();
	}

	ICompressedVisTableClass^ CompressedVisTableClassPtrSimpleDynVecClass::default::get(int index)
	{
		if (index < 0 || index > Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew CompressedVisTableClass(IntPtr(result));
		}
	}

	void CompressedVisTableClassPtrSimpleDynVecClass::default::set(int index, ICompressedVisTableClass^ value)
	{
		if (index < 0 || index > Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->CompressedVisTableClassPointer.ToPointer() == nullptr)
		{
			InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->operator[](index) = reinterpret_cast<::CompressedVisTableClass*>(value->CompressedVisTableClassPointer.ToPointer());
		}
	}

	bool CompressedVisTableClassPtrSimpleDynVecClass::IsEmpty::get()
	{
		return InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->isEmpty();
	}

	int CompressedVisTableClassPtrSimpleDynVecClass::Count::get()
	{
		return InternalCompressedVisTableClassPtrSimpleDynVecClassPointer->Count();
	}

	bool CompressedVisTableClassPtrSimpleDynVecClass::InternalDestroyPointer()
	{
		Imports::DestroyCompressedVisTableClassPtrSimpleDynVecClass(InternalCompressedVisTableClassPtrSimpleDynVecClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	bool CompressedVisTableClassPtrSimpleDynVecClass::Grow(int newSizeHint)
	{
		if (newSizeHint < 0)
		{
			throw gcnew ArgumentOutOfRangeException("newSizeHint");
		}

		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::CompressedVisTableClass*>*>(InternalCompressedVisTableClassPtrSimpleDynVecClassPointer);

		return helper->Grow(newSizeHint);
	}

	bool CompressedVisTableClassPtrSimpleDynVecClass::Shrink()
	{
		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::CompressedVisTableClass*>*>(InternalCompressedVisTableClassPtrSimpleDynVecClassPointer);

		return helper->Shrink();
	}

	::SimpleDynVecClass<::CompressedVisTableClass*>* CompressedVisTableClassPtrSimpleDynVecClass::InternalCompressedVisTableClassPtrSimpleDynVecClassPointer::get()
	{
		return reinterpret_cast<::SimpleDynVecClass<::CompressedVisTableClass*>*>(Pointer.ToPointer());
	}

	IntPtr CompressedVisTableClassPtrSimpleDynVecClass::Vector::get()
	{
		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::CompressedVisTableClass*>*>(InternalCompressedVisTableClassPtrSimpleDynVecClassPointer);

		return IntPtr(helper->GetVector());
	}

	void CompressedVisTableClassPtrSimpleDynVecClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::CompressedVisTableClass*>*>(InternalCompressedVisTableClassPtrSimpleDynVecClassPointer);

		helper->SetVector(reinterpret_cast<::CompressedVisTableClass * *>(value.ToPointer()));
	}

	int CompressedVisTableClassPtrSimpleDynVecClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::CompressedVisTableClass*>*>(InternalCompressedVisTableClassPtrSimpleDynVecClassPointer);

		return helper->GetVectorMax();
	}

	void CompressedVisTableClassPtrSimpleDynVecClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::CompressedVisTableClass*>*>(InternalCompressedVisTableClassPtrSimpleDynVecClassPointer);

		helper->SetVectorMax(value);
	}

	int CompressedVisTableClassPtrSimpleDynVecClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::CompressedVisTableClass*>*>(InternalCompressedVisTableClassPtrSimpleDynVecClassPointer);

		return helper->GetActiveCount();
	}

	void CompressedVisTableClassPtrSimpleDynVecClass::ActiveCount::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::CompressedVisTableClass*>*>(InternalCompressedVisTableClassPtrSimpleDynVecClassPointer);

		helper->SetActiveCount(value);
	}
}