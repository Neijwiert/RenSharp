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
#include "MDAPlayerObserverTimerStructPtrDynamicVectorClass.h"

#include "Imports.h"
#include "Mda_player.h"

namespace RenSharp
{
	DAPlayerObserverTimerStructPtrDynamicVectorClass::DAPlayerObserverTimerStructPtrDynamicVectorClass()
		: DynamicVectorClass<IDAPlayerObserverTimerStruct ^>(IntPtr(Imports::CreateDAPlayerObserverTimerStructPtrDynamicVectorClass1()))
	{

	}

	DAPlayerObserverTimerStructPtrDynamicVectorClass::DAPlayerObserverTimerStructPtrDynamicVectorClass(int size)
		: DynamicVectorClass<IDAPlayerObserverTimerStruct ^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateDAPlayerObserverTimerStructPtrDynamicVectorClass2(size));
	}

	DAPlayerObserverTimerStructPtrDynamicVectorClass::DAPlayerObserverTimerStructPtrDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<IDAPlayerObserverTimerStruct ^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<IDAPlayerObserverTimerStruct ^> ^> ^DAPlayerObserverTimerStructPtrDynamicVectorClass::CreateDAPlayerObserverTimerStructPtrDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IDAPlayerObserverTimerStruct ^> ^>(gcnew DAPlayerObserverTimerStructPtrDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<IDAPlayerObserverTimerStruct ^> ^> ^DAPlayerObserverTimerStructPtrDynamicVectorClass::CreateDAPlayerObserverTimerStructPtrDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IDAPlayerObserverTimerStruct ^> ^>(gcnew DAPlayerObserverTimerStructPtrDynamicVectorClass(size));
	}

	bool DAPlayerObserverTimerStructPtrDynamicVectorClass::Resize(int newSize)
	{
		return InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer->Resize(newSize);
	}

	void DAPlayerObserverTimerStructPtrDynamicVectorClass::Clear()
	{
		InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer->Clear();
	}

	int DAPlayerObserverTimerStructPtrDynamicVectorClass::ID(IDAPlayerObserverTimerStruct ^object)
	{
		if (object == nullptr || object->DAPlayerObserverTimerStructPointer.ToPointer() == nullptr)
		{
			return InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer->ID(static_cast<::DAPlayerObserverTimerStruct *>(nullptr));
		}
		else
		{
			return InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer->ID(reinterpret_cast<::DAPlayerObserverTimerStruct *>(object->DAPlayerObserverTimerStructPointer.ToPointer()));
		}
	}

	void DAPlayerObserverTimerStructPtrDynamicVectorClass::Insert(int index, IDAPlayerObserverTimerStruct ^object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (object == nullptr || object->DAPlayerObserverTimerStructPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer->Insert(index, reinterpret_cast<::DAPlayerObserverTimerStruct *>(object->DAPlayerObserverTimerStructPointer.ToPointer()));
		}
	}

	bool DAPlayerObserverTimerStructPtrDynamicVectorClass::Add(IDAPlayerObserverTimerStruct ^object)
	{
		if (object == nullptr || object->DAPlayerObserverTimerStructPointer.ToPointer() == nullptr)
		{
			return InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer->Add(nullptr);
		}
		else
		{
			return InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer->Add(reinterpret_cast<::DAPlayerObserverTimerStruct *>(object->DAPlayerObserverTimerStructPointer.ToPointer()));
		}
	}

	void DAPlayerObserverTimerStructPtrDynamicVectorClass::ResetActive()
	{
		InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer->Reset_Active();
	}

	bool DAPlayerObserverTimerStructPtrDynamicVectorClass::AddHead(IDAPlayerObserverTimerStruct ^object)
	{
		if (object == nullptr || object->DAPlayerObserverTimerStructPointer.ToPointer() == nullptr)
		{
			return InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer->Add_Head(reinterpret_cast<::DAPlayerObserverTimerStruct *>(object->DAPlayerObserverTimerStructPointer.ToPointer()));
		}
	}

	bool DAPlayerObserverTimerStructPtrDynamicVectorClass::DeleteObj(IDAPlayerObserverTimerStruct ^object)
	{
		if (object == nullptr || object->DAPlayerObserverTimerStructPointer.ToPointer() == nullptr)
		{
			return InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer->DeleteObj(nullptr);
		}
		else
		{
			return InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer->DeleteObj(reinterpret_cast<::DAPlayerObserverTimerStruct *>(object->DAPlayerObserverTimerStructPointer.ToPointer()));
		}
	}

	bool DAPlayerObserverTimerStructPtrDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer->Delete(index);
	}

	void DAPlayerObserverTimerStructPtrDynamicVectorClass::DeleteAll()
	{
		InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer->Delete_All();
	}

	int DAPlayerObserverTimerStructPtrDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void DAPlayerObserverTimerStructPtrDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr DAPlayerObserverTimerStructPtrDynamicVectorClass::DAPlayerObserverTimerStructPtrDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer);
	}

	IDAPlayerObserverTimerStruct ^DAPlayerObserverTimerStructPtrDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAPlayerObserverTimerStruct(IntPtr(result));
		}
	}

	void DAPlayerObserverTimerStructPtrDynamicVectorClass::default::set(int index, IDAPlayerObserverTimerStruct ^value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->DAPlayerObserverTimerStructPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer->operator[](index) = reinterpret_cast<::DAPlayerObserverTimerStruct *>(value->DAPlayerObserverTimerStructPointer.ToPointer());
		}
	}

	int DAPlayerObserverTimerStructPtrDynamicVectorClass::Length::get()
	{
		return InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer->Length();
	}

	int DAPlayerObserverTimerStructPtrDynamicVectorClass::Count::get()
	{
		return InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer->Count();
	}

	void DAPlayerObserverTimerStructPtrDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer->Set_Active(value);
	}

	int DAPlayerObserverTimerStructPtrDynamicVectorClass::GrowthStep::get()
	{
		return InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer->Growth_Step();
	}

	void DAPlayerObserverTimerStructPtrDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool DAPlayerObserverTimerStructPtrDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyDAPlayerObserverTimerStructPtrDynamicVectorClass(InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::DAPlayerObserverTimerStruct *> *DAPlayerObserverTimerStructPtrDynamicVectorClass::InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::DAPlayerObserverTimerStruct *> *>(Pointer.ToPointer());
	}

	IntPtr DAPlayerObserverTimerStructPtrDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverTimerStruct *> *>(InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void DAPlayerObserverTimerStructPtrDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverTimerStruct *> *>(InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::DAPlayerObserverTimerStruct **>(value.ToPointer()));
	}

	int DAPlayerObserverTimerStructPtrDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverTimerStruct *> *>(InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void DAPlayerObserverTimerStructPtrDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverTimerStruct *> *>(InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool DAPlayerObserverTimerStructPtrDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverTimerStruct *> *>(InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void DAPlayerObserverTimerStructPtrDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverTimerStruct *> *>(InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool DAPlayerObserverTimerStructPtrDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverTimerStruct *> *>(InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void DAPlayerObserverTimerStructPtrDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverTimerStruct *> *>(InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int DAPlayerObserverTimerStructPtrDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverTimerStruct *> *>(InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void DAPlayerObserverTimerStructPtrDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverTimerStruct *> *>(InternalDAPlayerObserverTimerStructPtrDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}