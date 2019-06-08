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
#include "MDAGameFeatureClassPtrDynamicVectorClass.h"

#include "Imports.h"
#include "Mda_gamefeature.h"

namespace RenSharp
{
	DAGameFeatureFactoryClassPtrDynamicVectorClass::DAGameFeatureFactoryClassPtrDynamicVectorClass()
		: DynamicVectorClass<IDAGameFeatureFactoryClass^>(IntPtr(Imports::CreateDAGameFeatureFactoryClassPtrDynamicVectorClass1()))
	{

	}

	DAGameFeatureFactoryClassPtrDynamicVectorClass::DAGameFeatureFactoryClassPtrDynamicVectorClass(int size)
		: DynamicVectorClass<IDAGameFeatureFactoryClass^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateDAGameFeatureFactoryClassPtrDynamicVectorClass2(size));
	}

	DAGameFeatureFactoryClassPtrDynamicVectorClass::DAGameFeatureFactoryClassPtrDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<IDAGameFeatureFactoryClass^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<IDAGameFeatureFactoryClass^>^>^ DAGameFeatureFactoryClassPtrDynamicVectorClass::CreateDAGameFeatureFactoryClassPtrDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IDAGameFeatureFactoryClass^>^>(gcnew DAGameFeatureFactoryClassPtrDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<IDAGameFeatureFactoryClass^>^>^ DAGameFeatureFactoryClassPtrDynamicVectorClass::CreateDAGameFeatureFactoryClassPtrDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IDAGameFeatureFactoryClass^>^>(gcnew DAGameFeatureFactoryClassPtrDynamicVectorClass(size));
	}

	bool DAGameFeatureFactoryClassPtrDynamicVectorClass::Resize(int newSize)
	{
		return InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer->Resize(newSize);
	}

	void DAGameFeatureFactoryClassPtrDynamicVectorClass::Clear()
	{
		InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer->Clear();
	}

	int DAGameFeatureFactoryClassPtrDynamicVectorClass::ID(IDAGameFeatureFactoryClass^ object)
	{
		if (object == nullptr || object->DAGameFeatureFactoryClassPointer.ToPointer() == nullptr)
		{
			return InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer->ID(static_cast<::DAGameFeatureFactoryClass*>(nullptr));
		}
		else
		{
			return InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer->ID(reinterpret_cast<::DAGameFeatureFactoryClass*>(object->DAGameFeatureFactoryClassPointer.ToPointer()));
		}
	}

	void DAGameFeatureFactoryClassPtrDynamicVectorClass::Insert(int index, IDAGameFeatureFactoryClass^ object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (object == nullptr || object->DAGameFeatureFactoryClassPointer.ToPointer() == nullptr)
		{
			InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer->Insert(index, reinterpret_cast<::DAGameFeatureFactoryClass*>(object->DAGameFeatureFactoryClassPointer.ToPointer()));
		}
	}

	bool DAGameFeatureFactoryClassPtrDynamicVectorClass::Add(IDAGameFeatureFactoryClass^ object)
	{
		if (object == nullptr || object->DAGameFeatureFactoryClassPointer.ToPointer() == nullptr)
		{
			return InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer->Add(nullptr);
		}
		else
		{
			return InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer->Add(reinterpret_cast<::DAGameFeatureFactoryClass*>(object->DAGameFeatureFactoryClassPointer.ToPointer()));
		}
	}

	void DAGameFeatureFactoryClassPtrDynamicVectorClass::ResetActive()
	{
		InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer->Reset_Active();
	}

	bool DAGameFeatureFactoryClassPtrDynamicVectorClass::AddHead(IDAGameFeatureFactoryClass^ object)
	{
		if (object == nullptr || object->DAGameFeatureFactoryClassPointer.ToPointer() == nullptr)
		{
			return InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer->Add_Head(reinterpret_cast<::DAGameFeatureFactoryClass*>(object->DAGameFeatureFactoryClassPointer.ToPointer()));
		}
	}

	bool DAGameFeatureFactoryClassPtrDynamicVectorClass::DeleteObj(IDAGameFeatureFactoryClass^ object)
	{
		if (object == nullptr || object->DAGameFeatureFactoryClassPointer.ToPointer() == nullptr)
		{
			return InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer->DeleteObj(nullptr);
		}
		else
		{
			return InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer->DeleteObj(reinterpret_cast<::DAGameFeatureFactoryClass*>(object->DAGameFeatureFactoryClassPointer.ToPointer()));
		}
	}

	bool DAGameFeatureFactoryClassPtrDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer->Delete(index);
	}

	void DAGameFeatureFactoryClassPtrDynamicVectorClass::DeleteAll()
	{
		InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer->Delete_All();
	}

	int DAGameFeatureFactoryClassPtrDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void DAGameFeatureFactoryClassPtrDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr DAGameFeatureFactoryClassPtrDynamicVectorClass::DAGameFeatureFactoryClassPtrDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer);
	}

	IDAGameFeatureFactoryClass^ DAGameFeatureFactoryClassPtrDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAGameFeatureFactoryClass(IntPtr(result));
		}
	}

	void DAGameFeatureFactoryClassPtrDynamicVectorClass::default::set(int index, IDAGameFeatureFactoryClass^ value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->DAGameFeatureFactoryClassPointer.ToPointer() == nullptr)
		{
			InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer->operator[](index) = reinterpret_cast<::DAGameFeatureFactoryClass*>(value->DAGameFeatureFactoryClassPointer.ToPointer());
		}
	}

	int DAGameFeatureFactoryClassPtrDynamicVectorClass::Length::get()
	{
		return InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer->Length();
	}

	int DAGameFeatureFactoryClassPtrDynamicVectorClass::Count::get()
	{
		return InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer->Count();
	}

	void DAGameFeatureFactoryClassPtrDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer->Set_Active(value);
	}

	int DAGameFeatureFactoryClassPtrDynamicVectorClass::GrowthStep::get()
	{
		return InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer->Growth_Step();
	}

	void DAGameFeatureFactoryClassPtrDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool DAGameFeatureFactoryClassPtrDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyDAGameFeatureFactoryClassPtrDynamicVectorClass(InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::DAGameFeatureFactoryClass*>* DAGameFeatureFactoryClassPtrDynamicVectorClass::InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::DAGameFeatureFactoryClass*>*>(Pointer.ToPointer());
	}

	IntPtr DAGameFeatureFactoryClassPtrDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAGameFeatureFactoryClass*>*>(InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void DAGameFeatureFactoryClassPtrDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAGameFeatureFactoryClass*>*>(InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::DAGameFeatureFactoryClass * *>(value.ToPointer()));
	}

	int DAGameFeatureFactoryClassPtrDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAGameFeatureFactoryClass*>*>(InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void DAGameFeatureFactoryClassPtrDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAGameFeatureFactoryClass*>*>(InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool DAGameFeatureFactoryClassPtrDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAGameFeatureFactoryClass*>*>(InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void DAGameFeatureFactoryClassPtrDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAGameFeatureFactoryClass*>*>(InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool DAGameFeatureFactoryClassPtrDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAGameFeatureFactoryClass*>*>(InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void DAGameFeatureFactoryClassPtrDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAGameFeatureFactoryClass*>*>(InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int DAGameFeatureFactoryClassPtrDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAGameFeatureFactoryClass*>*>(InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void DAGameFeatureFactoryClassPtrDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAGameFeatureFactoryClass*>*>(InternalDAGameFeatureFactoryClassPtrDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}