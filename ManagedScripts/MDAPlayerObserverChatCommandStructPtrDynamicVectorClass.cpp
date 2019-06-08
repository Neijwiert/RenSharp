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
#include "MDAPlayerObserverChatCommandStructPtrDynamicVectorClass.h"

#include "Imports.h"
#include "Mda_player.h"

namespace RenSharp
{
	DAPlayerObserverChatCommandStructPtrDynamicVectorClass::DAPlayerObserverChatCommandStructPtrDynamicVectorClass()
		: DynamicVectorClass<IDAPlayerObserverChatCommandStruct ^>(IntPtr(Imports::CreateDAPlayerObserverChatCommandStructPtrDynamicVectorClass1()))
	{

	}

	DAPlayerObserverChatCommandStructPtrDynamicVectorClass::DAPlayerObserverChatCommandStructPtrDynamicVectorClass(int size)
		: DynamicVectorClass<IDAPlayerObserverChatCommandStruct ^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateDAPlayerObserverChatCommandStructPtrDynamicVectorClass2(size));
	}

	DAPlayerObserverChatCommandStructPtrDynamicVectorClass::DAPlayerObserverChatCommandStructPtrDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<IDAPlayerObserverChatCommandStruct ^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<IDAPlayerObserverChatCommandStruct ^> ^> ^DAPlayerObserverChatCommandStructPtrDynamicVectorClass::CreateDAPlayerObserverChatCommandStructPtrDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IDAPlayerObserverChatCommandStruct ^> ^>(gcnew DAPlayerObserverChatCommandStructPtrDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<IDAPlayerObserverChatCommandStruct ^> ^> ^DAPlayerObserverChatCommandStructPtrDynamicVectorClass::CreateDAPlayerObserverChatCommandStructPtrDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IDAPlayerObserverChatCommandStruct ^> ^>(gcnew DAPlayerObserverChatCommandStructPtrDynamicVectorClass(size));
	}

	bool DAPlayerObserverChatCommandStructPtrDynamicVectorClass::Resize(int newSize)
	{
		return InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer->Resize(newSize);
	}

	void DAPlayerObserverChatCommandStructPtrDynamicVectorClass::Clear()
	{
		InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer->Clear();
	}

	int DAPlayerObserverChatCommandStructPtrDynamicVectorClass::ID(IDAPlayerObserverChatCommandStruct ^object)
	{
		if (object == nullptr || object->DAPlayerObserverChatCommandStructPointer.ToPointer() == nullptr)
		{
			return InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer->ID(static_cast<::DAPlayerObserverChatCommandStruct *>(nullptr));
		}
		else
		{
			return InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer->ID(reinterpret_cast<::DAPlayerObserverChatCommandStruct *>(object->DAPlayerObserverChatCommandStructPointer.ToPointer()));
		}
	}

	void DAPlayerObserverChatCommandStructPtrDynamicVectorClass::Insert(int index, IDAPlayerObserverChatCommandStruct ^object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (object == nullptr || object->DAPlayerObserverChatCommandStructPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer->Insert(index, reinterpret_cast<::DAPlayerObserverChatCommandStruct *>(object->DAPlayerObserverChatCommandStructPointer.ToPointer()));
		}
	}

	bool DAPlayerObserverChatCommandStructPtrDynamicVectorClass::Add(IDAPlayerObserverChatCommandStruct ^object)
	{
		if (object == nullptr || object->DAPlayerObserverChatCommandStructPointer.ToPointer() == nullptr)
		{
			return InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer->Add(nullptr);
		}
		else
		{
			return InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer->Add(reinterpret_cast<::DAPlayerObserverChatCommandStruct *>(object->DAPlayerObserverChatCommandStructPointer.ToPointer()));
		}
	}

	void DAPlayerObserverChatCommandStructPtrDynamicVectorClass::ResetActive()
	{
		InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer->Reset_Active();
	}

	bool DAPlayerObserverChatCommandStructPtrDynamicVectorClass::AddHead(IDAPlayerObserverChatCommandStruct ^object)
	{
		if (object == nullptr || object->DAPlayerObserverChatCommandStructPointer.ToPointer() == nullptr)
		{
			return InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer->Add_Head(reinterpret_cast<::DAPlayerObserverChatCommandStruct *>(object->DAPlayerObserverChatCommandStructPointer.ToPointer()));
		}
	}

	bool DAPlayerObserverChatCommandStructPtrDynamicVectorClass::DeleteObj(IDAPlayerObserverChatCommandStruct ^object)
	{
		if (object == nullptr || object->DAPlayerObserverChatCommandStructPointer.ToPointer() == nullptr)
		{
			return InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer->DeleteObj(nullptr);
		}
		else
		{
			return InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer->DeleteObj(reinterpret_cast<::DAPlayerObserverChatCommandStruct *>(object->DAPlayerObserverChatCommandStructPointer.ToPointer()));
		}
	}

	bool DAPlayerObserverChatCommandStructPtrDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer->Delete(index);
	}

	void DAPlayerObserverChatCommandStructPtrDynamicVectorClass::DeleteAll()
	{
		InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer->Delete_All();
	}

	int DAPlayerObserverChatCommandStructPtrDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void DAPlayerObserverChatCommandStructPtrDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr DAPlayerObserverChatCommandStructPtrDynamicVectorClass::DAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer);
	}

	IDAPlayerObserverChatCommandStruct ^DAPlayerObserverChatCommandStructPtrDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAPlayerObserverChatCommandStruct(IntPtr(result));
		}
	}

	void DAPlayerObserverChatCommandStructPtrDynamicVectorClass::default::set(int index, IDAPlayerObserverChatCommandStruct ^value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->DAPlayerObserverChatCommandStructPointer.ToPointer() == nullptr)
		{
			InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer->operator[](index) = reinterpret_cast<::DAPlayerObserverChatCommandStruct *>(value->DAPlayerObserverChatCommandStructPointer.ToPointer());
		}
	}

	int DAPlayerObserverChatCommandStructPtrDynamicVectorClass::Length::get()
	{
		return InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer->Length();
	}

	int DAPlayerObserverChatCommandStructPtrDynamicVectorClass::Count::get()
	{
		return InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer->Count();
	}

	void DAPlayerObserverChatCommandStructPtrDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer->Set_Active(value);
	}

	int DAPlayerObserverChatCommandStructPtrDynamicVectorClass::GrowthStep::get()
	{
		return InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer->Growth_Step();
	}

	void DAPlayerObserverChatCommandStructPtrDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool DAPlayerObserverChatCommandStructPtrDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyDAPlayerObserverChatCommandStructPtrDynamicVectorClass(InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::DAPlayerObserverChatCommandStruct *> *DAPlayerObserverChatCommandStructPtrDynamicVectorClass::InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::DAPlayerObserverChatCommandStruct *> *>(Pointer.ToPointer());
	}

	IntPtr DAPlayerObserverChatCommandStructPtrDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverChatCommandStruct *> *>(InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void DAPlayerObserverChatCommandStructPtrDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverChatCommandStruct *> *>(InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::DAPlayerObserverChatCommandStruct **>(value.ToPointer()));
	}

	int DAPlayerObserverChatCommandStructPtrDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverChatCommandStruct *> *>(InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void DAPlayerObserverChatCommandStructPtrDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverChatCommandStruct *> *>(InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool DAPlayerObserverChatCommandStructPtrDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverChatCommandStruct *> *>(InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void DAPlayerObserverChatCommandStructPtrDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverChatCommandStruct *> *>(InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool DAPlayerObserverChatCommandStructPtrDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverChatCommandStruct *> *>(InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void DAPlayerObserverChatCommandStructPtrDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverChatCommandStruct *> *>(InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int DAPlayerObserverChatCommandStructPtrDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverChatCommandStruct *> *>(InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void DAPlayerObserverChatCommandStructPtrDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAPlayerObserverChatCommandStruct *> *>(InternalDAPlayerObserverChatCommandStructPtrDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}