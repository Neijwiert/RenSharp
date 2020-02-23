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
#include "MVector3DynamicVectorClass.h"

#include "MVector3.h"
#include "Imports.h"

namespace RenSharp
{
	Vector3DynamicVectorClass::Vector3DynamicVectorClass()
		: DynamicVectorClass<Vector3>(IntPtr(Imports::CreateVector3DynamicVectorClass1()))
	{

	}

	Vector3DynamicVectorClass::Vector3DynamicVectorClass(int size)
		: DynamicVectorClass<Vector3>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateVector3DynamicVectorClass2(size));
	}

	Vector3DynamicVectorClass::Vector3DynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<Vector3>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<Vector3>^>^ Vector3DynamicVectorClass::CreateVector3DynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<Vector3>^>(gcnew Vector3DynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<Vector3>^>^ Vector3DynamicVectorClass::CreateVector3DynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<Vector3>^>(gcnew Vector3DynamicVectorClass(size));
	}

	bool Vector3DynamicVectorClass::Resize(int newSize)
	{
		return InternalVector3DynamicVectorClassPointer->Resize(newSize);
	}

	void Vector3DynamicVectorClass::Clear()
	{
		InternalVector3DynamicVectorClassPointer->Clear();
	}

	int Vector3DynamicVectorClass::ID(Vector3 object)
	{
		::Vector3 objectVec;

		Vector3::ManagedToUnmanagedVector3(object, objectVec);

		return InternalVector3DynamicVectorClassPointer->ID(objectVec);
	}

	void Vector3DynamicVectorClass::Insert(int index, Vector3 object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		::Vector3 objectVec;

		Vector3::ManagedToUnmanagedVector3(object, objectVec);

		InternalVector3DynamicVectorClassPointer->Insert(
			index,
			objectVec);
	}

	bool Vector3DynamicVectorClass::Add(Vector3 object)
	{
		::Vector3 objectVec;

		Vector3::ManagedToUnmanagedVector3(object, objectVec);

		return InternalVector3DynamicVectorClassPointer->Add(objectVec);
	}

	void Vector3DynamicVectorClass::ResetActive()
	{
		InternalVector3DynamicVectorClassPointer->Reset_Active();
	}

	bool Vector3DynamicVectorClass::AddHead(Vector3 object)
	{
		::Vector3 objectVec;

		Vector3::ManagedToUnmanagedVector3(object, objectVec);

		return InternalVector3DynamicVectorClassPointer->Add_Head(objectVec);
	}

	bool Vector3DynamicVectorClass::DeleteObj(Vector3 object)
	{
		::Vector3 objectVec;

		Vector3::ManagedToUnmanagedVector3(object, objectVec);

		return InternalVector3DynamicVectorClassPointer->DeleteObj(objectVec);
	}

	bool Vector3DynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalVector3DynamicVectorClassPointer->Delete(index);
	}

	void Vector3DynamicVectorClass::DeleteAll()
	{
		InternalVector3DynamicVectorClassPointer->Delete_All();
	}

	int Vector3DynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalVector3DynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void Vector3DynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalVector3DynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr Vector3DynamicVectorClass::Vector3DynamicVectorClassPointer::get()
	{
		return IntPtr(InternalVector3DynamicVectorClassPointer);
	}

	Vector3 Vector3DynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto& tmp = InternalVector3DynamicVectorClassPointer->operator[](index);

		Vector3 result;

		Vector3::UnmanagedToManagedVector3(tmp, result);

		return result;
	}

	void Vector3DynamicVectorClass::default::set(int index, Vector3 value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}
		
		::Vector3 valueVec;

		Vector3::ManagedToUnmanagedVector3(value, valueVec);

		InternalVector3DynamicVectorClassPointer->operator[](index) = valueVec;
	}

	int Vector3DynamicVectorClass::Length::get()
	{
		return InternalVector3DynamicVectorClassPointer->Length();
	}

	int Vector3DynamicVectorClass::Count::get()
	{
		return InternalVector3DynamicVectorClassPointer->Count();
	}

	void Vector3DynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalVector3DynamicVectorClassPointer->Set_Active(value);
	}

	int Vector3DynamicVectorClass::GrowthStep::get()
	{
		return InternalVector3DynamicVectorClassPointer->Growth_Step();
	}

	void Vector3DynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalVector3DynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool Vector3DynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyVector3DynamicVectorClass(InternalVector3DynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::Vector3>* Vector3DynamicVectorClass::InternalVector3DynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::Vector3>*>(Pointer.ToPointer());
	}

	IntPtr Vector3DynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Vector3>*>(InternalVector3DynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void Vector3DynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Vector3>*>(InternalVector3DynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::Vector3*>(value.ToPointer()));
	}

	int Vector3DynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Vector3>*>(InternalVector3DynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void Vector3DynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Vector3>*>(InternalVector3DynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool Vector3DynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Vector3>*>(InternalVector3DynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void Vector3DynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Vector3>*>(InternalVector3DynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool Vector3DynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Vector3>*>(InternalVector3DynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void Vector3DynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Vector3>*>(InternalVector3DynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int Vector3DynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Vector3>*>(InternalVector3DynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void Vector3DynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Vector3>*>(InternalVector3DynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}