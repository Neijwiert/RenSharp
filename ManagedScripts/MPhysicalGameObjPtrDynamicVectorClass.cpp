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
#include "MPhysicalGameObjPtrDynamicVectorClass.h"

#include "Imports.h"
#include "MPhysicalGameObj.h"

namespace RenSharp
{
	PhysicalGameObjPtrDynamicVectorClass::PhysicalGameObjPtrDynamicVectorClass()
		: DynamicVectorClass<IPhysicalGameObj^>(IntPtr(Imports::CreatePhysicalGameObjPtrDynamicVectorClass1()))
	{

	}

	PhysicalGameObjPtrDynamicVectorClass::PhysicalGameObjPtrDynamicVectorClass(int size)
		: DynamicVectorClass<IPhysicalGameObj^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreatePhysicalGameObjPtrDynamicVectorClass2(size));
	}

	PhysicalGameObjPtrDynamicVectorClass::PhysicalGameObjPtrDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<IPhysicalGameObj^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<IPhysicalGameObj^>^>^ PhysicalGameObjPtrDynamicVectorClass::CreatePhysicalGameObjPtrDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IPhysicalGameObj^>^>(gcnew PhysicalGameObjPtrDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<IPhysicalGameObj^>^>^ PhysicalGameObjPtrDynamicVectorClass::CreatePhysicalGameObjPtrDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IPhysicalGameObj^>^>(gcnew PhysicalGameObjPtrDynamicVectorClass(size));
	}

	bool PhysicalGameObjPtrDynamicVectorClass::Resize(int newSize)
	{
		return InternalPhysicalGameObjPtrDynamicVectorClassPointer->Resize(newSize);
	}

	void PhysicalGameObjPtrDynamicVectorClass::Clear()
	{
		InternalPhysicalGameObjPtrDynamicVectorClassPointer->Clear();
	}

	int PhysicalGameObjPtrDynamicVectorClass::ID(IPhysicalGameObj^ object)
	{
		if (object == nullptr || object->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			return InternalPhysicalGameObjPtrDynamicVectorClassPointer->ID(static_cast<::PhysicalGameObj*>(nullptr));
		}
		else
		{
			return InternalPhysicalGameObjPtrDynamicVectorClassPointer->ID(reinterpret_cast<::PhysicalGameObj*>(object->PhysicalGameObjPointer.ToPointer()));
		}
	}

	void PhysicalGameObjPtrDynamicVectorClass::Insert(int index, IPhysicalGameObj^ object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (object == nullptr || object->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			InternalPhysicalGameObjPtrDynamicVectorClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalPhysicalGameObjPtrDynamicVectorClassPointer->Insert(index, reinterpret_cast<::PhysicalGameObj*>(object->PhysicalGameObjPointer.ToPointer()));
		}
	}

	bool PhysicalGameObjPtrDynamicVectorClass::Add(IPhysicalGameObj^ object)
	{
		if (object == nullptr || object->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			return InternalPhysicalGameObjPtrDynamicVectorClassPointer->Add(nullptr);
		}
		else
		{
			return InternalPhysicalGameObjPtrDynamicVectorClassPointer->Add(reinterpret_cast<::PhysicalGameObj*>(object->PhysicalGameObjPointer.ToPointer()));
		}
	}

	void PhysicalGameObjPtrDynamicVectorClass::ResetActive()
	{
		InternalPhysicalGameObjPtrDynamicVectorClassPointer->Reset_Active();
	}

	bool PhysicalGameObjPtrDynamicVectorClass::AddHead(IPhysicalGameObj^ object)
	{
		if (object == nullptr || object->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			return InternalPhysicalGameObjPtrDynamicVectorClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalPhysicalGameObjPtrDynamicVectorClassPointer->Add_Head(reinterpret_cast<::PhysicalGameObj*>(object->PhysicalGameObjPointer.ToPointer()));
		}
	}

	bool PhysicalGameObjPtrDynamicVectorClass::DeleteObj(IPhysicalGameObj^ object)
	{
		if (object == nullptr || object->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			return InternalPhysicalGameObjPtrDynamicVectorClassPointer->DeleteObj(nullptr);
		}
		else
		{
			return InternalPhysicalGameObjPtrDynamicVectorClassPointer->DeleteObj(reinterpret_cast<::PhysicalGameObj*>(object->PhysicalGameObjPointer.ToPointer()));
		}
	}

	bool PhysicalGameObjPtrDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalPhysicalGameObjPtrDynamicVectorClassPointer->Delete(index);
	}

	void PhysicalGameObjPtrDynamicVectorClass::DeleteAll()
	{
		InternalPhysicalGameObjPtrDynamicVectorClassPointer->Delete_All();
	}

	int PhysicalGameObjPtrDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalPhysicalGameObjPtrDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void PhysicalGameObjPtrDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalPhysicalGameObjPtrDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr PhysicalGameObjPtrDynamicVectorClass::PhysicalGameObjPtrDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalPhysicalGameObjPtrDynamicVectorClassPointer);
	}

	IPhysicalGameObj^ PhysicalGameObjPtrDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalPhysicalGameObjPtrDynamicVectorClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<IPhysicalGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	void PhysicalGameObjPtrDynamicVectorClass::default::set(int index, IPhysicalGameObj^ value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			InternalPhysicalGameObjPtrDynamicVectorClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalPhysicalGameObjPtrDynamicVectorClassPointer->operator[](index) = reinterpret_cast<::PhysicalGameObj*>(value->PhysicalGameObjPointer.ToPointer());
		}
	}

	int PhysicalGameObjPtrDynamicVectorClass::Length::get()
	{
		return InternalPhysicalGameObjPtrDynamicVectorClassPointer->Length();
	}

	int PhysicalGameObjPtrDynamicVectorClass::Count::get()
	{
		return InternalPhysicalGameObjPtrDynamicVectorClassPointer->Count();
	}

	void PhysicalGameObjPtrDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalPhysicalGameObjPtrDynamicVectorClassPointer->Set_Active(value);
	}

	int PhysicalGameObjPtrDynamicVectorClass::GrowthStep::get()
	{
		return InternalPhysicalGameObjPtrDynamicVectorClassPointer->Growth_Step();
	}

	void PhysicalGameObjPtrDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalPhysicalGameObjPtrDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool PhysicalGameObjPtrDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyPhysicalGameObjPtrDynamicVectorClass(InternalPhysicalGameObjPtrDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::PhysicalGameObj*>* PhysicalGameObjPtrDynamicVectorClass::InternalPhysicalGameObjPtrDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::PhysicalGameObj*>*>(Pointer.ToPointer());
	}

	IntPtr PhysicalGameObjPtrDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::PhysicalGameObj*>*>(InternalPhysicalGameObjPtrDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void PhysicalGameObjPtrDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::PhysicalGameObj*>*>(InternalPhysicalGameObjPtrDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::PhysicalGameObj * *>(value.ToPointer()));
	}

	int PhysicalGameObjPtrDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::PhysicalGameObj*>*>(InternalPhysicalGameObjPtrDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void PhysicalGameObjPtrDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::PhysicalGameObj*>*>(InternalPhysicalGameObjPtrDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool PhysicalGameObjPtrDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::PhysicalGameObj*>*>(InternalPhysicalGameObjPtrDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void PhysicalGameObjPtrDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::PhysicalGameObj*>*>(InternalPhysicalGameObjPtrDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool PhysicalGameObjPtrDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::PhysicalGameObj*>*>(InternalPhysicalGameObjPtrDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void PhysicalGameObjPtrDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::PhysicalGameObj*>*>(InternalPhysicalGameObjPtrDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int PhysicalGameObjPtrDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::PhysicalGameObj*>*>(InternalPhysicalGameObjPtrDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void PhysicalGameObjPtrDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::PhysicalGameObj*>*>(InternalPhysicalGameObjPtrDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}