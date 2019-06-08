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
#include "MDAPlayerObserverKeyHookStructPtrDynamicVectorClass.h"

#include "Imports.h"
#include "Mda_player.h"

namespace RenSharp
{
	DAPlayerObserverKeyHookStructPtrDynamicVectorClass::DAPlayerObserverKeyHookStructPtrDynamicVectorClass()
		: DynamicVectorClass<IDAPlayerObserverKeyHookStruct ^>(IntPtr(Imports::CreateDAPlayerObserverKeyHookStructPtrDynamicVectorClass1()))
	{

	}

	DAPlayerObserverKeyHookStructPtrDynamicVectorClass::DAPlayerObserverKeyHookStructPtrDynamicVectorClass(int size)
		: DynamicVectorClass<IDAPlayerObserverKeyHookStruct ^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateDAPlayerObserverKeyHookStructPtrDynamicVectorClass2(size));
	}

	DAPlayerObserverKeyHookStructPtrDynamicVectorClass::DAPlayerObserverKeyHookStructPtrDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<IDAPlayerObserverKeyHookStruct ^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<IDAPlayerObserverKeyHookStruct ^> ^> ^DAPlayerObserverKeyHookStructPtrDynamicVectorClass::CreateDAPlayerObserverKeyHookStructPtrDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IDAPlayerObserverKeyHookStruct ^> ^>(gcnew DAPlayerObserverKeyHookStructPtrDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<IDAPlayerObserverKeyHookStruct ^> ^> ^DAPlayerObserverKeyHookStructPtrDynamicVectorClass::CreateDAPlayerObserverKeyHookStructPtrDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IDAPlayerObserverKeyHookStruct ^> ^>(gcnew DAPlayerObserverKeyHookStructPtrDynamicVectorClass(size));
	}

	bool DAPlayerObserverKeyHookStructPtrDynamicVectorClass::Resize(int newSize)
	{
		return InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer->Resize(newSize);
	}

	void DAPlayerObserverKeyHookStructPtrDynamicVectorClass::Clear()
	{
		InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer->Clear();
	}

	int DAPlayerObserverKeyHookStructPtrDynamicVectorClass::ID(IDAPlayerObserverKeyHookStruct ^object)
	{
		if (object == nullptr || object->DAPlayerObserverKeyHookStructPointer.ToPointer() == nullptr)
		{
			return InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer->ID(static_cast<::DAPlayerObserverKeyHookStruct *>(nullptr));
		}
		else
		{
			return InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer->ID(reinterpret_cast<::DAPlayerObserverKeyHookStruct *>(object->DAPlayerObserverKeyHookStructPointer.ToPointer()));
		}
	}

	void DAPlayerObserverKeyHookStructPtrDynamicVectorClass::Insert(int index, IDAPlayerObserverKeyHookStruct ^object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (object == nullptr || object->DAPlayerObserverKeyHookStructPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer->Insert(index, reinterpret_cast<::DAPlayerObserverKeyHookStruct *>(object->DAPlayerObserverKeyHookStructPointer.ToPointer()));
		}
	}

	bool DAPlayerObserverKeyHookStructPtrDynamicVectorClass::Add(IDAPlayerObserverKeyHookStruct ^object)
	{
		if (object == nullptr || object->DAPlayerObserverKeyHookStructPointer.ToPointer() == nullptr)
		{
			return InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer->Add(nullptr);
		}
		else
		{
			return InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer->Add(reinterpret_cast<::DAPlayerObserverKeyHookStruct *>(object->DAPlayerObserverKeyHookStructPointer.ToPointer()));
		}
	}

	void DAPlayerObserverKeyHookStructPtrDynamicVectorClass::ResetActive()
	{
		InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer->Reset_Active();
	}

	bool DAPlayerObserverKeyHookStructPtrDynamicVectorClass::AddHead(IDAPlayerObserverKeyHookStruct ^object)
	{
		if (object == nullptr || object->DAPlayerObserverKeyHookStructPointer.ToPointer() == nullptr)
		{
			return InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer->Add_Head(reinterpret_cast<::DAPlayerObserverKeyHookStruct *>(object->DAPlayerObserverKeyHookStructPointer.ToPointer()));
		}
	}

	bool DAPlayerObserverKeyHookStructPtrDynamicVectorClass::DeleteObj(IDAPlayerObserverKeyHookStruct ^object)
	{
		if (object == nullptr || object->DAPlayerObserverKeyHookStructPointer.ToPointer() == nullptr)
		{
			return InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer->DeleteObj(nullptr);
		}
		else
		{
			return InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer->DeleteObj(reinterpret_cast<::DAPlayerObserverKeyHookStruct *>(object->DAPlayerObserverKeyHookStructPointer.ToPointer()));
		}
	}

	bool DAPlayerObserverKeyHookStructPtrDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer->Delete(index);
	}

	void DAPlayerObserverKeyHookStructPtrDynamicVectorClass::DeleteAll()
	{
		InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer->Delete_All();
	}

	int DAPlayerObserverKeyHookStructPtrDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void DAPlayerObserverKeyHookStructPtrDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr DAPlayerObserverKeyHookStructPtrDynamicVectorClass::DAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer);
	}

	IDAPlayerObserverKeyHookStruct ^DAPlayerObserverKeyHookStructPtrDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAPlayerObserverKeyHookStruct(IntPtr(result));
		}
	}

	void DAPlayerObserverKeyHookStructPtrDynamicVectorClass::default::set(int index, IDAPlayerObserverKeyHookStruct ^value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->DAPlayerObserverKeyHookStructPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer->operator[](index) = reinterpret_cast<::DAPlayerObserverKeyHookStruct *>(value->DAPlayerObserverKeyHookStructPointer.ToPointer());
		}
	}

	int DAPlayerObserverKeyHookStructPtrDynamicVectorClass::Length::get()
	{
		return InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer->Length();
	}

	int DAPlayerObserverKeyHookStructPtrDynamicVectorClass::Count::get()
	{
		return InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer->Count();
	}

	void DAPlayerObserverKeyHookStructPtrDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer->Set_Active(value);
	}

	int DAPlayerObserverKeyHookStructPtrDynamicVectorClass::GrowthStep::get()
	{
		return InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer->Growth_Step();
	}

	void DAPlayerObserverKeyHookStructPtrDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool DAPlayerObserverKeyHookStructPtrDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyDAPlayerObserverKeyHookStructPtrDynamicVectorClass(InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::DAPlayerObserverKeyHookStruct *> *DAPlayerObserverKeyHookStructPtrDynamicVectorClass::InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::DAPlayerObserverKeyHookStruct *> *>(Pointer.ToPointer());
	}

	IntPtr DAPlayerObserverKeyHookStructPtrDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverKeyHookStruct *> *>(InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void DAPlayerObserverKeyHookStructPtrDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverKeyHookStruct *> *>(InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::DAPlayerObserverKeyHookStruct **>(value.ToPointer()));
	}

	int DAPlayerObserverKeyHookStructPtrDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverKeyHookStruct *> *>(InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void DAPlayerObserverKeyHookStructPtrDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverKeyHookStruct *> *>(InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool DAPlayerObserverKeyHookStructPtrDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverKeyHookStruct *> *>(InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void DAPlayerObserverKeyHookStructPtrDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverKeyHookStruct *> *>(InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool DAPlayerObserverKeyHookStructPtrDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverKeyHookStruct *> *>(InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void DAPlayerObserverKeyHookStructPtrDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverKeyHookStruct *> *>(InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int DAPlayerObserverKeyHookStructPtrDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverKeyHookStruct *> *>(InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void DAPlayerObserverKeyHookStructPtrDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverKeyHookStruct *> *>(InternalDAPlayerObserverKeyHookStructPtrDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}