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
#include "MVisTableClassPtrSimpleVecClass.h"

#include "Imports.h"
#include "UnmanagedContainer.h"
#include "MVisTableClass.h"

namespace RenSharp
{
	VisTableClassPtrSimpleVecClass::VisTableClassPtrSimpleVecClass()
		: SimpleVecClass<IVisTableClass^>(IntPtr(Imports::CreateVisTableClassPtrSimpleVecClass1()))
	{

	}

	VisTableClassPtrSimpleVecClass::VisTableClassPtrSimpleVecClass(int size)
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateVisTableClassPtrSimpleVecClass2(size));
	}

	VisTableClassPtrSimpleVecClass::VisTableClassPtrSimpleVecClass(IntPtr pointer)
		: SimpleVecClass<IVisTableClass^>(pointer)
	{

	}

	bool VisTableClassPtrSimpleVecClass::Resize(int newSize)
	{
		return InternalVisTableClassPtrSimpleVecClassPointer->Resize(newSize);
	}

	bool VisTableClassPtrSimpleVecClass::UninitialisedGrow(int newSize)
	{
		return InternalVisTableClassPtrSimpleVecClassPointer->Uninitialised_Grow(newSize);
	}

	void VisTableClassPtrSimpleVecClass::UninitializedResize(int newSize)
	{
		InternalVisTableClassPtrSimpleVecClassPointer->Uninitialized_Resize(newSize);
	}

	IntPtr VisTableClassPtrSimpleVecClass::Peek()
	{
		return IntPtr(InternalVisTableClassPtrSimpleVecClassPointer->Peek());
	}

#pragma push_macro("ZeroMemory")
#undef ZeroMemory
	void VisTableClassPtrSimpleVecClass::ZeroMemory()
#pragma pop_macro("ZeroMemory")
	{
		InternalVisTableClassPtrSimpleVecClassPointer->Zero_Memory();
	}

	IntPtr VisTableClassPtrSimpleVecClass::VisTableClassPtrSimpleVecClassPointer::get()
	{
		return IntPtr(InternalVisTableClassPtrSimpleVecClassPointer);
	}

	int VisTableClassPtrSimpleVecClass::Length::get()
	{
		return InternalVisTableClassPtrSimpleVecClassPointer->Length();
	}

	IVisTableClass^ VisTableClassPtrSimpleVecClass::default::get(int index)
	{
		auto result = InternalVisTableClassPtrSimpleVecClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew VisTableClass(IntPtr(result));
		}
	}

	void VisTableClassPtrSimpleVecClass::default::set(int index, IVisTableClass^ value)
	{
		if (index < 0 || index >= InternalVisTableClassPtrSimpleVecClassPointer->Length())
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->VisTableClassPointer.ToPointer() == nullptr)
		{
			InternalVisTableClassPtrSimpleVecClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalVisTableClassPtrSimpleVecClassPointer->operator[](index) = reinterpret_cast<::VisTableClass*>(value->VisTableClassPointer.ToPointer());
		}
	}

	bool VisTableClassPtrSimpleVecClass::InternalDestroyPointer()
	{
		Imports::DestroyVisTableClassPtrSimpleVecClass(InternalVisTableClassPtrSimpleVecClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::SimpleVecClass<::VisTableClass*>* VisTableClassPtrSimpleVecClass::InternalVisTableClassPtrSimpleVecClassPointer::get()
	{
		return reinterpret_cast<::SimpleVecClass<::VisTableClass*>*>(Pointer.ToPointer());
	}

	IntPtr VisTableClassPtrSimpleVecClass::Vector::get()
	{
		auto helper = reinterpret_cast<SimpleVecClassHelper<::VisTableClass*>*>(InternalVisTableClassPtrSimpleVecClassPointer);

		auto& vector = helper->GetVector();

		return IntPtr(vector);
	}

	void VisTableClassPtrSimpleVecClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<SimpleVecClassHelper<::VisTableClass*>*>(InternalVisTableClassPtrSimpleVecClassPointer);

		auto& vector = helper->GetVector();

		vector = reinterpret_cast<::VisTableClass**>(value.ToPointer());
	}

	int VisTableClassPtrSimpleVecClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<SimpleVecClassHelper<::VisTableClass*>*>(InternalVisTableClassPtrSimpleVecClassPointer);

		auto& vectorMax = helper->GetVectorMax();

		return vectorMax;
	}

	void VisTableClassPtrSimpleVecClass::VectorMax::set(int value)
	{
		auto helper = reinterpret_cast<SimpleVecClassHelper<::VisTableClass*>*>(InternalVisTableClassPtrSimpleVecClassPointer);

		auto& vectorMax = helper->GetVectorMax();

		vectorMax = value;
	}
}