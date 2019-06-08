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
#include "MTransitionDataClassPtrDynamicVectorClass.h"

#include "Imports.h"
#include "MTransitionGameObjDef.h"

namespace RenSharp
{
	TransitionDataClassPtrDynamicVectorClass::TransitionDataClassPtrDynamicVectorClass()
		: DynamicVectorClass<ITransitionDataClass ^>(IntPtr(Imports::CreateTransitionDataClassPtrDynamicVectorClass1()))
	{

	}

	TransitionDataClassPtrDynamicVectorClass::TransitionDataClassPtrDynamicVectorClass(int size)
		: DynamicVectorClass<ITransitionDataClass ^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateTransitionDataClassPtrDynamicVectorClass2(size));
	}

	TransitionDataClassPtrDynamicVectorClass::TransitionDataClassPtrDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<ITransitionDataClass ^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<ITransitionDataClass ^> ^> ^TransitionDataClassPtrDynamicVectorClass::CreateTransitionDataClassPtrDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<ITransitionDataClass ^> ^>(gcnew TransitionDataClassPtrDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<ITransitionDataClass ^> ^> ^TransitionDataClassPtrDynamicVectorClass::CreateTransitionDataClassPtrDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<ITransitionDataClass ^> ^>(gcnew TransitionDataClassPtrDynamicVectorClass(size));
	}

	bool TransitionDataClassPtrDynamicVectorClass::Resize(int newSize)
	{
		return InternalTransitionDataClassPtrDynamicVectorClassPointer->Resize(newSize);
	}

	void TransitionDataClassPtrDynamicVectorClass::Clear()
	{
		InternalTransitionDataClassPtrDynamicVectorClassPointer->Clear();
	}

	int TransitionDataClassPtrDynamicVectorClass::ID(ITransitionDataClass ^object)
	{
		if (object == nullptr || object->TransitionDataClassPointer.ToPointer() == nullptr)
		{
			return InternalTransitionDataClassPtrDynamicVectorClassPointer->ID(static_cast<::TransitionDataClass *>(nullptr));
		}
		else
		{
			return InternalTransitionDataClassPtrDynamicVectorClassPointer->ID(reinterpret_cast<::TransitionDataClass *>(object->TransitionDataClassPointer.ToPointer()));
		}
	}

	void TransitionDataClassPtrDynamicVectorClass::Insert(int index, ITransitionDataClass ^object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (object == nullptr || object->TransitionDataClassPointer.ToPointer() == nullptr)
		{
			InternalTransitionDataClassPtrDynamicVectorClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalTransitionDataClassPtrDynamicVectorClassPointer->Insert(index, reinterpret_cast<::TransitionDataClass *>(object->TransitionDataClassPointer.ToPointer()));
		}
	}

	bool TransitionDataClassPtrDynamicVectorClass::Add(ITransitionDataClass ^object)
	{
		if (object == nullptr || object->TransitionDataClassPointer.ToPointer() == nullptr)
		{
			return InternalTransitionDataClassPtrDynamicVectorClassPointer->Add(nullptr);
		}
		else
		{
			return InternalTransitionDataClassPtrDynamicVectorClassPointer->Add(reinterpret_cast<::TransitionDataClass *>(object->TransitionDataClassPointer.ToPointer()));
		}
	}

	void TransitionDataClassPtrDynamicVectorClass::ResetActive()
	{
		InternalTransitionDataClassPtrDynamicVectorClassPointer->Reset_Active();
	}

	bool TransitionDataClassPtrDynamicVectorClass::AddHead(ITransitionDataClass ^object)
	{
		if (object == nullptr || object->TransitionDataClassPointer.ToPointer() == nullptr)
		{
			return InternalTransitionDataClassPtrDynamicVectorClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalTransitionDataClassPtrDynamicVectorClassPointer->Add_Head(reinterpret_cast<::TransitionDataClass *>(object->TransitionDataClassPointer.ToPointer()));
		}
	}

	bool TransitionDataClassPtrDynamicVectorClass::DeleteObj(ITransitionDataClass ^object)
	{
		if (object == nullptr || object->TransitionDataClassPointer.ToPointer() == nullptr)
		{
			return InternalTransitionDataClassPtrDynamicVectorClassPointer->DeleteObj(nullptr);
		}
		else
		{
			return InternalTransitionDataClassPtrDynamicVectorClassPointer->DeleteObj(reinterpret_cast<::TransitionDataClass *>(object->TransitionDataClassPointer.ToPointer()));
		}
	}

	bool TransitionDataClassPtrDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalTransitionDataClassPtrDynamicVectorClassPointer->Delete(index);
	}

	void TransitionDataClassPtrDynamicVectorClass::DeleteAll()
	{
		InternalTransitionDataClassPtrDynamicVectorClassPointer->Delete_All();
	}

	int TransitionDataClassPtrDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalTransitionDataClassPtrDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void TransitionDataClassPtrDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalTransitionDataClassPtrDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr TransitionDataClassPtrDynamicVectorClass::TransitionDataClassPtrDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalTransitionDataClassPtrDynamicVectorClassPointer);
	}

	ITransitionDataClass ^TransitionDataClassPtrDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalTransitionDataClassPtrDynamicVectorClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew TransitionDataClass(IntPtr(result));
		}
	}

	void TransitionDataClassPtrDynamicVectorClass::default::set(int index, ITransitionDataClass ^value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->TransitionDataClassPointer.ToPointer() == nullptr)
		{
			InternalTransitionDataClassPtrDynamicVectorClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalTransitionDataClassPtrDynamicVectorClassPointer->operator[](index) = reinterpret_cast<::TransitionDataClass *>(value->TransitionDataClassPointer.ToPointer());
		}
	}

	int TransitionDataClassPtrDynamicVectorClass::Length::get()
	{
		return InternalTransitionDataClassPtrDynamicVectorClassPointer->Length();
	}

	int TransitionDataClassPtrDynamicVectorClass::Count::get()
	{
		return InternalTransitionDataClassPtrDynamicVectorClassPointer->Count();
	}

	void TransitionDataClassPtrDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalTransitionDataClassPtrDynamicVectorClassPointer->Set_Active(value);
	}

	int TransitionDataClassPtrDynamicVectorClass::GrowthStep::get()
	{
		return InternalTransitionDataClassPtrDynamicVectorClassPointer->Growth_Step();
	}

	void TransitionDataClassPtrDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalTransitionDataClassPtrDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool TransitionDataClassPtrDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyTransitionDataClassPtrDynamicVectorClass(InternalTransitionDataClassPtrDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::TransitionDataClass *> *TransitionDataClassPtrDynamicVectorClass::InternalTransitionDataClassPtrDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::TransitionDataClass *> *>(Pointer.ToPointer());
	}

	IntPtr TransitionDataClassPtrDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TransitionDataClass *> *>(InternalTransitionDataClassPtrDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void TransitionDataClassPtrDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TransitionDataClass *> *>(InternalTransitionDataClassPtrDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::TransitionDataClass **>(value.ToPointer()));
	}

	int TransitionDataClassPtrDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TransitionDataClass *> *>(InternalTransitionDataClassPtrDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void TransitionDataClassPtrDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TransitionDataClass *> *>(InternalTransitionDataClassPtrDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool TransitionDataClassPtrDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TransitionDataClass *> *>(InternalTransitionDataClassPtrDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void TransitionDataClassPtrDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TransitionDataClass *> *>(InternalTransitionDataClassPtrDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool TransitionDataClassPtrDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TransitionDataClass *> *>(InternalTransitionDataClassPtrDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void TransitionDataClassPtrDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TransitionDataClass *> *>(InternalTransitionDataClassPtrDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int TransitionDataClassPtrDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TransitionDataClass *> *>(InternalTransitionDataClassPtrDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void TransitionDataClassPtrDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::TransitionDataClass *> *>(InternalTransitionDataClassPtrDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}