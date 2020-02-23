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
#include "MTransitionInstanceClassPtrDynamicVectorClass.h"

#include "MTransitionInstanceClass.h"
#include "Imports.h"

namespace RenSharp
{
	TransitionInstanceClassPtrDynamicVectorClass::TransitionInstanceClassPtrDynamicVectorClass()
		: DynamicVectorClass<ITransitionInstanceClass ^>(IntPtr(Imports::CreateTransitionInstanceClassPtrDynamicVectorClass1()))
	{

	}

	TransitionInstanceClassPtrDynamicVectorClass::TransitionInstanceClassPtrDynamicVectorClass(int size)
		: DynamicVectorClass<ITransitionInstanceClass ^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateTransitionInstanceClassPtrDynamicVectorClass2(size));
	}

	TransitionInstanceClassPtrDynamicVectorClass::TransitionInstanceClassPtrDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<ITransitionInstanceClass ^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<ITransitionInstanceClass ^> ^> ^TransitionInstanceClassPtrDynamicVectorClass::CreateTransitionInstanceClassPtrDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<ITransitionInstanceClass ^> ^>(gcnew TransitionInstanceClassPtrDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<ITransitionInstanceClass ^> ^> ^TransitionInstanceClassPtrDynamicVectorClass::CreateTransitionInstanceClassPtrDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<ITransitionInstanceClass ^> ^>(gcnew TransitionInstanceClassPtrDynamicVectorClass(size));
	}

	bool TransitionInstanceClassPtrDynamicVectorClass::Resize(int newSize)
	{
		return InternalTransitionInstanceClassPtrDynamicVectorClassPointer->Resize(newSize);
	}

	void TransitionInstanceClassPtrDynamicVectorClass::Clear()
	{
		InternalTransitionInstanceClassPtrDynamicVectorClassPointer->Clear();
	}

	int TransitionInstanceClassPtrDynamicVectorClass::ID(ITransitionInstanceClass ^object)
	{
		if (object == nullptr || object->TransitionInstanceClassPointer.ToPointer() == nullptr)
		{
			return InternalTransitionInstanceClassPtrDynamicVectorClassPointer->ID(static_cast<::TransitionInstanceClass *>(nullptr));
		}
		else
		{
			return InternalTransitionInstanceClassPtrDynamicVectorClassPointer->ID(reinterpret_cast<::TransitionInstanceClass *>(object->TransitionInstanceClassPointer.ToPointer()));
		}
	}

	void TransitionInstanceClassPtrDynamicVectorClass::Insert(int index, ITransitionInstanceClass ^object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (object == nullptr || object->TransitionInstanceClassPointer.ToPointer() == nullptr)
		{
			InternalTransitionInstanceClassPtrDynamicVectorClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalTransitionInstanceClassPtrDynamicVectorClassPointer->Insert(index, reinterpret_cast<::TransitionInstanceClass *>(object->TransitionInstanceClassPointer.ToPointer()));
		}
	}

	bool TransitionInstanceClassPtrDynamicVectorClass::Add(ITransitionInstanceClass ^object)
	{
		if (object == nullptr || object->TransitionInstanceClassPointer.ToPointer() == nullptr)
		{
			return InternalTransitionInstanceClassPtrDynamicVectorClassPointer->Add(nullptr);
		}
		else
		{
			return InternalTransitionInstanceClassPtrDynamicVectorClassPointer->Add(reinterpret_cast<::TransitionInstanceClass *>(object->TransitionInstanceClassPointer.ToPointer()));
		}
	}

	void TransitionInstanceClassPtrDynamicVectorClass::ResetActive()
	{
		InternalTransitionInstanceClassPtrDynamicVectorClassPointer->Reset_Active();
	}

	bool TransitionInstanceClassPtrDynamicVectorClass::AddHead(ITransitionInstanceClass ^object)
	{
		if (object == nullptr || object->TransitionInstanceClassPointer.ToPointer() == nullptr)
		{
			return InternalTransitionInstanceClassPtrDynamicVectorClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalTransitionInstanceClassPtrDynamicVectorClassPointer->Add_Head(reinterpret_cast<::TransitionInstanceClass *>(object->TransitionInstanceClassPointer.ToPointer()));
		}
	}

	bool TransitionInstanceClassPtrDynamicVectorClass::DeleteObj(ITransitionInstanceClass ^object)
	{
		if (object == nullptr || object->TransitionInstanceClassPointer.ToPointer() == nullptr)
		{
			return InternalTransitionInstanceClassPtrDynamicVectorClassPointer->DeleteObj(nullptr);
		}
		else
		{
			return InternalTransitionInstanceClassPtrDynamicVectorClassPointer->DeleteObj(reinterpret_cast<::TransitionInstanceClass *>(object->TransitionInstanceClassPointer.ToPointer()));
		}
	}

	bool TransitionInstanceClassPtrDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalTransitionInstanceClassPtrDynamicVectorClassPointer->Delete(index);
	}

	void TransitionInstanceClassPtrDynamicVectorClass::DeleteAll()
	{
		InternalTransitionInstanceClassPtrDynamicVectorClassPointer->Delete_All();
	}

	int TransitionInstanceClassPtrDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalTransitionInstanceClassPtrDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void TransitionInstanceClassPtrDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalTransitionInstanceClassPtrDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr TransitionInstanceClassPtrDynamicVectorClass::TransitionInstanceClassPtrDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalTransitionInstanceClassPtrDynamicVectorClassPointer);
	}

	ITransitionInstanceClass ^TransitionInstanceClassPtrDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalTransitionInstanceClassPtrDynamicVectorClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew TransitionInstanceClass(IntPtr(result));
		}
	}

	void TransitionInstanceClassPtrDynamicVectorClass::default::set(int index, ITransitionInstanceClass ^value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->TransitionInstanceClassPointer.ToPointer() == nullptr)
		{
			InternalTransitionInstanceClassPtrDynamicVectorClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalTransitionInstanceClassPtrDynamicVectorClassPointer->operator[](index) = reinterpret_cast<::TransitionInstanceClass *>(value->TransitionInstanceClassPointer.ToPointer());
		}
	}

	int TransitionInstanceClassPtrDynamicVectorClass::Length::get()
	{
		return InternalTransitionInstanceClassPtrDynamicVectorClassPointer->Length();
	}

	int TransitionInstanceClassPtrDynamicVectorClass::Count::get()
	{
		return InternalTransitionInstanceClassPtrDynamicVectorClassPointer->Count();
	}

	void TransitionInstanceClassPtrDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalTransitionInstanceClassPtrDynamicVectorClassPointer->Set_Active(value);
	}

	int TransitionInstanceClassPtrDynamicVectorClass::GrowthStep::get()
	{
		return InternalTransitionInstanceClassPtrDynamicVectorClassPointer->Growth_Step();
	}

	void TransitionInstanceClassPtrDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalTransitionInstanceClassPtrDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool TransitionInstanceClassPtrDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyTransitionInstanceClassPtrDynamicVectorClass(InternalTransitionInstanceClassPtrDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::TransitionInstanceClass *> *TransitionInstanceClassPtrDynamicVectorClass::InternalTransitionInstanceClassPtrDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::TransitionInstanceClass *> *>(Pointer.ToPointer());
	}

	IntPtr TransitionInstanceClassPtrDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TransitionInstanceClass *> *>(InternalTransitionInstanceClassPtrDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void TransitionInstanceClassPtrDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TransitionInstanceClass *> *>(InternalTransitionInstanceClassPtrDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::TransitionInstanceClass **>(value.ToPointer()));
	}

	int TransitionInstanceClassPtrDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TransitionInstanceClass *> *>(InternalTransitionInstanceClassPtrDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void TransitionInstanceClassPtrDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TransitionInstanceClass *> *>(InternalTransitionInstanceClassPtrDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool TransitionInstanceClassPtrDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TransitionInstanceClass *> *>(InternalTransitionInstanceClassPtrDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void TransitionInstanceClassPtrDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TransitionInstanceClass *> *>(InternalTransitionInstanceClassPtrDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool TransitionInstanceClassPtrDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TransitionInstanceClass *> *>(InternalTransitionInstanceClassPtrDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void TransitionInstanceClassPtrDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TransitionInstanceClass *> *>(InternalTransitionInstanceClassPtrDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int TransitionInstanceClassPtrDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TransitionInstanceClass *> *>(InternalTransitionInstanceClassPtrDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void TransitionInstanceClassPtrDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TransitionInstanceClass *> *>(InternalTransitionInstanceClassPtrDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}