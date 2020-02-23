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
#include "MDAPlayerObserverClassPtrDynamicVectorClass.h"

#include "Imports.h"
#include "Mda_player.h"

namespace RenSharp
{
	DAPlayerObserverClassPtrDynamicVectorClass::DAPlayerObserverClassPtrDynamicVectorClass()
		: DynamicVectorClass<IDAPlayerObserverClass ^>(IntPtr(Imports::CreateDAPlayerObserverClassPtrDynamicVectorClass1()))
	{

	}

	DAPlayerObserverClassPtrDynamicVectorClass::DAPlayerObserverClassPtrDynamicVectorClass(int size)
		: DynamicVectorClass<IDAPlayerObserverClass ^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateDAPlayerObserverClassPtrDynamicVectorClass2(size));
	}

	DAPlayerObserverClassPtrDynamicVectorClass::DAPlayerObserverClassPtrDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<IDAPlayerObserverClass ^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<IDAPlayerObserverClass ^> ^> ^DAPlayerObserverClassPtrDynamicVectorClass::CreateDAPlayerObserverClassPtrDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IDAPlayerObserverClass ^> ^>(gcnew DAPlayerObserverClassPtrDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<IDAPlayerObserverClass ^> ^> ^DAPlayerObserverClassPtrDynamicVectorClass::CreateDAPlayerObserverClassPtrDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IDAPlayerObserverClass ^> ^>(gcnew DAPlayerObserverClassPtrDynamicVectorClass(size));
	}

	bool DAPlayerObserverClassPtrDynamicVectorClass::Resize(int newSize)
	{
		return InternalDAPlayerObserverClassPtrDynamicVectorClassPointer->Resize(newSize);
	}

	void DAPlayerObserverClassPtrDynamicVectorClass::Clear()
	{
		InternalDAPlayerObserverClassPtrDynamicVectorClassPointer->Clear();
	}

	int DAPlayerObserverClassPtrDynamicVectorClass::ID(IDAPlayerObserverClass ^object)
	{
		if (object == nullptr || object->DAPlayerObserverClassPointer.ToPointer() == nullptr)
		{
			return InternalDAPlayerObserverClassPtrDynamicVectorClassPointer->ID(static_cast<::DAPlayerObserverClass *>(nullptr));
		}
		else
		{
			return InternalDAPlayerObserverClassPtrDynamicVectorClassPointer->ID(reinterpret_cast<::DAPlayerObserverClass *>(object->DAPlayerObserverClassPointer.ToPointer()));
		}
	}

	void DAPlayerObserverClassPtrDynamicVectorClass::Insert(int index, IDAPlayerObserverClass ^object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (object == nullptr || object->DAPlayerObserverClassPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerObserverClassPtrDynamicVectorClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalDAPlayerObserverClassPtrDynamicVectorClassPointer->Insert(index, reinterpret_cast<::DAPlayerObserverClass *>(object->DAPlayerObserverClassPointer.ToPointer()));
		}
	}

	bool DAPlayerObserverClassPtrDynamicVectorClass::Add(IDAPlayerObserverClass ^object)
	{
		if (object == nullptr || object->DAPlayerObserverClassPointer.ToPointer() == nullptr)
		{
			return InternalDAPlayerObserverClassPtrDynamicVectorClassPointer->Add(nullptr);
		}
		else
		{
			return InternalDAPlayerObserverClassPtrDynamicVectorClassPointer->Add(reinterpret_cast<::DAPlayerObserverClass *>(object->DAPlayerObserverClassPointer.ToPointer()));
		}
	}

	void DAPlayerObserverClassPtrDynamicVectorClass::ResetActive()
	{
		InternalDAPlayerObserverClassPtrDynamicVectorClassPointer->Reset_Active();
	}

	bool DAPlayerObserverClassPtrDynamicVectorClass::AddHead(IDAPlayerObserverClass ^object)
	{
		if (object == nullptr || object->DAPlayerObserverClassPointer.ToPointer() == nullptr)
		{
			return InternalDAPlayerObserverClassPtrDynamicVectorClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalDAPlayerObserverClassPtrDynamicVectorClassPointer->Add_Head(reinterpret_cast<::DAPlayerObserverClass *>(object->DAPlayerObserverClassPointer.ToPointer()));
		}
	}

	bool DAPlayerObserverClassPtrDynamicVectorClass::DeleteObj(IDAPlayerObserverClass ^object)
	{
		if (object == nullptr || object->DAPlayerObserverClassPointer.ToPointer() == nullptr)
		{
			return InternalDAPlayerObserverClassPtrDynamicVectorClassPointer->DeleteObj(nullptr);
		}
		else
		{
			return InternalDAPlayerObserverClassPtrDynamicVectorClassPointer->DeleteObj(reinterpret_cast<::DAPlayerObserverClass *>(object->DAPlayerObserverClassPointer.ToPointer()));
		}
	}

	bool DAPlayerObserverClassPtrDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalDAPlayerObserverClassPtrDynamicVectorClassPointer->Delete(index);
	}

	void DAPlayerObserverClassPtrDynamicVectorClass::DeleteAll()
	{
		InternalDAPlayerObserverClassPtrDynamicVectorClassPointer->Delete_All();
	}

	int DAPlayerObserverClassPtrDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalDAPlayerObserverClassPtrDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void DAPlayerObserverClassPtrDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalDAPlayerObserverClassPtrDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr DAPlayerObserverClassPtrDynamicVectorClass::DAPlayerObserverClassPtrDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalDAPlayerObserverClassPtrDynamicVectorClassPointer);
	}

	IDAPlayerObserverClass ^DAPlayerObserverClassPtrDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalDAPlayerObserverClassPtrDynamicVectorClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAPlayerObserverClass(IntPtr(result));
		}
	}

	void DAPlayerObserverClassPtrDynamicVectorClass::default::set(int index, IDAPlayerObserverClass ^value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->DAPlayerObserverClassPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerObserverClassPtrDynamicVectorClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalDAPlayerObserverClassPtrDynamicVectorClassPointer->operator[](index) = reinterpret_cast<::DAPlayerObserverClass *>(value->DAPlayerObserverClassPointer.ToPointer());
		}
	}

	int DAPlayerObserverClassPtrDynamicVectorClass::Length::get()
	{
		return InternalDAPlayerObserverClassPtrDynamicVectorClassPointer->Length();
	}

	int DAPlayerObserverClassPtrDynamicVectorClass::Count::get()
	{
		return InternalDAPlayerObserverClassPtrDynamicVectorClassPointer->Count();
	}

	void DAPlayerObserverClassPtrDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalDAPlayerObserverClassPtrDynamicVectorClassPointer->Set_Active(value);
	}

	int DAPlayerObserverClassPtrDynamicVectorClass::GrowthStep::get()
	{
		return InternalDAPlayerObserverClassPtrDynamicVectorClassPointer->Growth_Step();
	}

	void DAPlayerObserverClassPtrDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalDAPlayerObserverClassPtrDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool DAPlayerObserverClassPtrDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyDAPlayerObserverClassPtrDynamicVectorClass(InternalDAPlayerObserverClassPtrDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::DAPlayerObserverClass *> *DAPlayerObserverClassPtrDynamicVectorClass::InternalDAPlayerObserverClassPtrDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::DAPlayerObserverClass *> *>(Pointer.ToPointer());
	}

	IntPtr DAPlayerObserverClassPtrDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverClass *> *>(InternalDAPlayerObserverClassPtrDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void DAPlayerObserverClassPtrDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverClass *> *>(InternalDAPlayerObserverClassPtrDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::DAPlayerObserverClass **>(value.ToPointer()));
	}

	int DAPlayerObserverClassPtrDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverClass *> *>(InternalDAPlayerObserverClassPtrDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void DAPlayerObserverClassPtrDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverClass *> *>(InternalDAPlayerObserverClassPtrDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool DAPlayerObserverClassPtrDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverClass *> *>(InternalDAPlayerObserverClassPtrDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void DAPlayerObserverClassPtrDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverClass *> *>(InternalDAPlayerObserverClassPtrDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool DAPlayerObserverClassPtrDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverClass *> *>(InternalDAPlayerObserverClassPtrDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void DAPlayerObserverClassPtrDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverClass *> *>(InternalDAPlayerObserverClassPtrDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int DAPlayerObserverClassPtrDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverClass *> *>(InternalDAPlayerObserverClassPtrDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void DAPlayerObserverClassPtrDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverClass *> *>(InternalDAPlayerObserverClassPtrDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}