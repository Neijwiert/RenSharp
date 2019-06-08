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
#include "MMatrix3DDynamicVectorClass.h"

#include "MMatrix3D.h"
#include "Imports.h"

namespace RenSharp
{
	Matrix3DDynamicVectorClass::Matrix3DDynamicVectorClass()
		: DynamicVectorClass<Matrix3D>(IntPtr(Imports::CreateMatrix3DDynamicVectorClass1()))
	{

	}

	Matrix3DDynamicVectorClass::Matrix3DDynamicVectorClass(int size)
		: DynamicVectorClass<Matrix3D>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateMatrix3DDynamicVectorClass2(size));
	}

	Matrix3DDynamicVectorClass::Matrix3DDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<Matrix3D>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<Matrix3D>^>^ Matrix3DDynamicVectorClass::CreateMatrix3DDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<Matrix3D>^>(gcnew Matrix3DDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<Matrix3D>^>^ Matrix3DDynamicVectorClass::CreateMatrix3DDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<Matrix3D>^>(gcnew Matrix3DDynamicVectorClass(size));
	}

	bool Matrix3DDynamicVectorClass::Resize(int newSize)
	{
		return InternalMatrix3DDynamicVectorClassPointer->Resize(newSize);
	}

	void Matrix3DDynamicVectorClass::Clear()
	{
		InternalMatrix3DDynamicVectorClassPointer->Clear();
	}

	int Matrix3DDynamicVectorClass::ID(Matrix3D object)
	{
		::Matrix3D objectVec;

		Matrix3D::ManagedToUnmanagedMatrix3D(object, objectVec);

		return InternalMatrix3DDynamicVectorClassPointer->ID(objectVec);
	}

	void Matrix3DDynamicVectorClass::Insert(int index, Matrix3D object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		::Matrix3D objectVec;

		Matrix3D::ManagedToUnmanagedMatrix3D(object, objectVec);

		InternalMatrix3DDynamicVectorClassPointer->Insert(
			index,
			objectVec);
	}

	bool Matrix3DDynamicVectorClass::Add(Matrix3D object)
	{
		::Matrix3D objectVec;

		Matrix3D::ManagedToUnmanagedMatrix3D(object, objectVec);

		return InternalMatrix3DDynamicVectorClassPointer->Add(objectVec);
	}

	void Matrix3DDynamicVectorClass::ResetActive()
	{
		InternalMatrix3DDynamicVectorClassPointer->Reset_Active();
	}

	bool Matrix3DDynamicVectorClass::AddHead(Matrix3D object)
	{
		::Matrix3D objectVec;

		Matrix3D::ManagedToUnmanagedMatrix3D(object, objectVec);

		return InternalMatrix3DDynamicVectorClassPointer->Add_Head(objectVec);
	}

	bool Matrix3DDynamicVectorClass::DeleteObj(Matrix3D object)
	{
		::Matrix3D objectVec;

		Matrix3D::ManagedToUnmanagedMatrix3D(object, objectVec);

		return InternalMatrix3DDynamicVectorClassPointer->DeleteObj(objectVec);
	}

	bool Matrix3DDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalMatrix3DDynamicVectorClassPointer->Delete(index);
	}

	void Matrix3DDynamicVectorClass::DeleteAll()
	{
		InternalMatrix3DDynamicVectorClassPointer->Delete_All();
	}

	int Matrix3DDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalMatrix3DDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void Matrix3DDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalMatrix3DDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr Matrix3DDynamicVectorClass::Matrix3DDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalMatrix3DDynamicVectorClassPointer);
	}

	Matrix3D Matrix3DDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto& tmp = InternalMatrix3DDynamicVectorClassPointer->operator[](index);

		Matrix3D result;

		Matrix3D::UnmanagedToManagedMatrix3D(tmp, result);

		return result;
	}

	void Matrix3DDynamicVectorClass::default::set(int index, Matrix3D value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		::Matrix3D valueVec;

		Matrix3D::ManagedToUnmanagedMatrix3D(value, valueVec);

		InternalMatrix3DDynamicVectorClassPointer->operator[](index) = valueVec;
	}

	int Matrix3DDynamicVectorClass::Length::get()
	{
		return InternalMatrix3DDynamicVectorClassPointer->Length();
	}

	int Matrix3DDynamicVectorClass::Count::get()
	{
		return InternalMatrix3DDynamicVectorClassPointer->Count();
	}

	void Matrix3DDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalMatrix3DDynamicVectorClassPointer->Set_Active(value);
	}

	int Matrix3DDynamicVectorClass::GrowthStep::get()
	{
		return InternalMatrix3DDynamicVectorClassPointer->Growth_Step();
	}

	void Matrix3DDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalMatrix3DDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool Matrix3DDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyMatrix3DDynamicVectorClass(InternalMatrix3DDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::Matrix3D>* Matrix3DDynamicVectorClass::InternalMatrix3DDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::Matrix3D>*>(Pointer.ToPointer());
	}

	IntPtr Matrix3DDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Matrix3D>*>(InternalMatrix3DDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void Matrix3DDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Matrix3D>*>(InternalMatrix3DDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::Matrix3D*>(value.ToPointer()));
	}

	int Matrix3DDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Matrix3D>*>(InternalMatrix3DDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void Matrix3DDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Matrix3D>*>(InternalMatrix3DDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool Matrix3DDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Matrix3D>*>(InternalMatrix3DDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void Matrix3DDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Matrix3D>*>(InternalMatrix3DDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool Matrix3DDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Matrix3D>*>(InternalMatrix3DDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void Matrix3DDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Matrix3D>*>(InternalMatrix3DDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int Matrix3DDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Matrix3D>*>(InternalMatrix3DDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void Matrix3DDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::Matrix3D>*>(InternalMatrix3DDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}