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
#include "MVector3PtrDynamicVectorClass.h"

#include "MVector3.h"
#include "Imports.h"

namespace RenSharp
{
	Vector3PtrDynamicVectorClass::Vector3PtrDynamicVectorClass()
		: DynamicVectorClass<Vector3>(IntPtr(Imports::CreateVector3PtrDynamicVectorClass1()))
	{

	}

	Vector3PtrDynamicVectorClass::Vector3PtrDynamicVectorClass(int size)
		: DynamicVectorClass<Vector3>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateVector3PtrDynamicVectorClass2(size));
	}

	Vector3PtrDynamicVectorClass::Vector3PtrDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<Vector3>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<Vector3>^>^ Vector3PtrDynamicVectorClass::CreateVector3PtrDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<Vector3>^>(gcnew Vector3PtrDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<Vector3>^>^ Vector3PtrDynamicVectorClass::CreateVector3PtrDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<Vector3>^>(gcnew Vector3PtrDynamicVectorClass(size));
	}

	bool Vector3PtrDynamicVectorClass::Resize(int newSize)
	{
		return InternalVector3PtrDynamicVectorClassPointer->Resize(newSize);
	}

	void Vector3PtrDynamicVectorClass::Clear()
	{
		InternalVector3PtrDynamicVectorClassPointer->Clear();
	}

	int Vector3PtrDynamicVectorClass::ID(Vector3 object)
	{
		throw gcnew NotSupportedException();
	}

	void Vector3PtrDynamicVectorClass::Insert(int index, Vector3 object)
	{
		throw gcnew NotSupportedException();
	}

	bool Vector3PtrDynamicVectorClass::Add(Vector3 object)
	{
		throw gcnew NotSupportedException();
	}

	void Vector3PtrDynamicVectorClass::ResetActive()
	{
		InternalVector3PtrDynamicVectorClassPointer->Reset_Active();
	}

	bool Vector3PtrDynamicVectorClass::AddHead(Vector3 object)
	{
		throw gcnew NotSupportedException();
	}

	bool Vector3PtrDynamicVectorClass::DeleteObj(Vector3 object)
	{
		throw gcnew NotSupportedException();
	}

	bool Vector3PtrDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalVector3PtrDynamicVectorClassPointer->Delete(index);
	}

	void Vector3PtrDynamicVectorClass::DeleteAll()
	{
		InternalVector3PtrDynamicVectorClassPointer->Delete_All();
	}

	int Vector3PtrDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalVector3PtrDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void Vector3PtrDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalVector3PtrDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr Vector3PtrDynamicVectorClass::Vector3PtrDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalVector3PtrDynamicVectorClassPointer);
	}

	Vector3 Vector3PtrDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto& tmp = InternalVector3PtrDynamicVectorClassPointer->operator[](index);

		Vector3 result;

		if (tmp != nullptr)
		{
			Vector3::UnmanagedToManagedVector3(*tmp, result);
		}

		return result;
	}

	void Vector3PtrDynamicVectorClass::default::set(int index, Vector3 value)
	{
		throw gcnew NotSupportedException();
	}

	int Vector3PtrDynamicVectorClass::Length::get()
	{
		return InternalVector3PtrDynamicVectorClassPointer->Length();
	}

	int Vector3PtrDynamicVectorClass::Count::get()
	{
		return InternalVector3PtrDynamicVectorClassPointer->Count();
	}

	void Vector3PtrDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalVector3PtrDynamicVectorClassPointer->Set_Active(value);
	}

	int Vector3PtrDynamicVectorClass::GrowthStep::get()
	{
		return InternalVector3PtrDynamicVectorClassPointer->Growth_Step();
	}

	void Vector3PtrDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalVector3PtrDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool Vector3PtrDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyVector3PtrDynamicVectorClass(InternalVector3PtrDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::Vector3*>* Vector3PtrDynamicVectorClass::InternalVector3PtrDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::Vector3*>*>(Pointer.ToPointer());
	}

	IntPtr Vector3PtrDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Vector3*>*>(InternalVector3PtrDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void Vector3PtrDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Vector3*>*>(InternalVector3PtrDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::Vector3**>(value.ToPointer()));
	}

	int Vector3PtrDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Vector3*>*>(InternalVector3PtrDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void Vector3PtrDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Vector3*>*>(InternalVector3PtrDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool Vector3PtrDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Vector3*>*>(InternalVector3PtrDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void Vector3PtrDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Vector3*>*>(InternalVector3PtrDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool Vector3PtrDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Vector3*>*>(InternalVector3PtrDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void Vector3PtrDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Vector3*>*>(InternalVector3PtrDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int Vector3PtrDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Vector3*>*>(InternalVector3PtrDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void Vector3PtrDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Vector3*>*>(InternalVector3PtrDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}