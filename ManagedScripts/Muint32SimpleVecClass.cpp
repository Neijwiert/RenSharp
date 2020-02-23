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
#include "Muint32SimpleVecClass.h"

#include "Imports.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	uint32SimpleVecClass::uint32SimpleVecClass()
		: SimpleVecClass<uint32>(IntPtr(Imports::Createuint32SimpleVecClass1()))
	{

	}

	uint32SimpleVecClass::uint32SimpleVecClass(int size)
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::Createuint32SimpleVecClass2(size));
	}

	uint32SimpleVecClass::uint32SimpleVecClass(IntPtr pointer)
		: SimpleVecClass<uint32>(pointer)
	{

	}

	IUnmanagedContainer<ISimpleVecClass<uint32> ^> ^uint32SimpleVecClass::Createuint32SimpleVecClass()
	{
		return gcnew UnmanagedContainer<ISimpleVecClass<uint32> ^>(gcnew uint32SimpleVecClass());
	}

	IUnmanagedContainer<ISimpleVecClass<uint32> ^> ^uint32SimpleVecClass::Createuint32SimpleVecClass(int size)
	{
		return gcnew UnmanagedContainer<ISimpleVecClass<uint32> ^>(gcnew uint32SimpleVecClass(size));
	}

	bool uint32SimpleVecClass::Resize(int newSize)
	{
		if (newSize < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		return Internaluint32SimpleVecClassPointer->Resize(newSize);
	}

	bool uint32SimpleVecClass::UninitialisedGrow(int newSize)
	{
		if (newSize < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		return Internaluint32SimpleVecClassPointer->Uninitialised_Grow(newSize);
	}

	void uint32SimpleVecClass::UninitializedResize(int newSize)
	{
		if (newSize < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		return Internaluint32SimpleVecClassPointer->Uninitialized_Resize(newSize);
	}

	IntPtr uint32SimpleVecClass::Peek()
	{
		return IntPtr(Internaluint32SimpleVecClassPointer->Peek());
	}

#pragma push_macro("ZeroMemory")
#undef ZeroMemory
	void uint32SimpleVecClass::ZeroMemory()
	{
		Internaluint32SimpleVecClassPointer->Zero_Memory();
	}
#pragma pop_macro("ZeroMemory")

	int uint32SimpleVecClass::Length::get()
	{
		return Internaluint32SimpleVecClassPointer->Length();
	}

	uint32 uint32SimpleVecClass::default::get(int index)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		return Internaluint32SimpleVecClassPointer->operator[](index);
	}

	void uint32SimpleVecClass::default::set(int index, uint32 value)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Internaluint32SimpleVecClassPointer->operator[](index) = value;
	}

	IntPtr uint32SimpleVecClass::uint32SimpleVecClassPointer::get()
	{
		return IntPtr(Internaluint32SimpleVecClassPointer);
	}

	bool uint32SimpleVecClass::InternalDestroyPointer()
	{
		Imports::Destroyuint32SimpleVecClass(Internaluint32SimpleVecClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::SimpleVecClass<uint32> *uint32SimpleVecClass::Internaluint32SimpleVecClassPointer::get()
	{
		return reinterpret_cast<::SimpleVecClass<uint32> *>(Pointer.ToPointer());
	}

	IntPtr uint32SimpleVecClass::Vector::get()
	{
		auto helper = reinterpret_cast<SimpleVecClassHelper<uint32> *>(Internaluint32SimpleVecClassPointer);

		auto &vector = helper->GetVector();

		return IntPtr(vector);
	}

	void uint32SimpleVecClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<SimpleVecClassHelper<uint32> * > (Internaluint32SimpleVecClassPointer);

		auto &vector = helper->GetVector();

		vector = reinterpret_cast<uint32 *>(value.ToPointer());
	}
	
	int uint32SimpleVecClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<SimpleVecClassHelper<uint32> *> (Internaluint32SimpleVecClassPointer);

		auto &vectorMax = helper->GetVectorMax();

		return vectorMax;
	}

	void uint32SimpleVecClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<SimpleVecClassHelper<uint32> *> (Internaluint32SimpleVecClassPointer);

		auto &vectorMax = helper->GetVectorMax();

		vectorMax = value;
	}
}