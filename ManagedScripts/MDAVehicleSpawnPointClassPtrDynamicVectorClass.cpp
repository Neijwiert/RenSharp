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
#include "MDAVehicleSpawnPointClassPtrDynamicVectorClass.h"

#include "Imports.h"
#include "Mda_vehiclespawn.h"

namespace RenSharp
{
	DAVehicleSpawnPointClassPtrDynamicVectorClass::DAVehicleSpawnPointClassPtrDynamicVectorClass()
		: DynamicVectorClass<IDAVehicleSpawnPointClass^>(IntPtr(Imports::CreateDAVehicleSpawnPointClassPtrDynamicVectorClass1()))
	{

	}

	DAVehicleSpawnPointClassPtrDynamicVectorClass::DAVehicleSpawnPointClassPtrDynamicVectorClass(int size)
		: DynamicVectorClass<IDAVehicleSpawnPointClass^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateDAVehicleSpawnPointClassPtrDynamicVectorClass2(size));
	}

	DAVehicleSpawnPointClassPtrDynamicVectorClass::DAVehicleSpawnPointClassPtrDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<IDAVehicleSpawnPointClass^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<IDAVehicleSpawnPointClass^>^>^ DAVehicleSpawnPointClassPtrDynamicVectorClass::CreateDAVehicleSpawnPointClassPtrDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IDAVehicleSpawnPointClass^>^>(gcnew DAVehicleSpawnPointClassPtrDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<IDAVehicleSpawnPointClass^>^>^ DAVehicleSpawnPointClassPtrDynamicVectorClass::CreateDAVehicleSpawnPointClassPtrDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IDAVehicleSpawnPointClass^>^>(gcnew DAVehicleSpawnPointClassPtrDynamicVectorClass(size));
	}

	bool DAVehicleSpawnPointClassPtrDynamicVectorClass::Resize(int newSize)
	{
		return InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer->Resize(newSize);
	}

	void DAVehicleSpawnPointClassPtrDynamicVectorClass::Clear()
	{
		InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer->Clear();
	}

	int DAVehicleSpawnPointClassPtrDynamicVectorClass::ID(IDAVehicleSpawnPointClass^ object)
	{
		if (object == nullptr || object->DAVehicleSpawnPointClassPointer.ToPointer() == nullptr)
		{
			return InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer->ID(static_cast<::DAVehicleSpawnPointClass*>(nullptr));
		}
		else
		{
			return InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer->ID(reinterpret_cast<::DAVehicleSpawnPointClass*>(object->DAVehicleSpawnPointClassPointer.ToPointer()));
		}
	}

	void DAVehicleSpawnPointClassPtrDynamicVectorClass::Insert(int index, IDAVehicleSpawnPointClass^ object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (object == nullptr || object->DAVehicleSpawnPointClassPointer.ToPointer() == nullptr)
		{
			InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer->Insert(index, reinterpret_cast<::DAVehicleSpawnPointClass*>(object->DAVehicleSpawnPointClassPointer.ToPointer()));
		}
	}

	bool DAVehicleSpawnPointClassPtrDynamicVectorClass::Add(IDAVehicleSpawnPointClass^ object)
	{
		if (object == nullptr || object->DAVehicleSpawnPointClassPointer.ToPointer() == nullptr)
		{
			return InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer->Add(nullptr);
		}
		else
		{
			return InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer->Add(reinterpret_cast<::DAVehicleSpawnPointClass*>(object->DAVehicleSpawnPointClassPointer.ToPointer()));
		}
	}

	void DAVehicleSpawnPointClassPtrDynamicVectorClass::ResetActive()
	{
		InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer->Reset_Active();
	}

	bool DAVehicleSpawnPointClassPtrDynamicVectorClass::AddHead(IDAVehicleSpawnPointClass^ object)
	{
		if (object == nullptr || object->DAVehicleSpawnPointClassPointer.ToPointer() == nullptr)
		{
			return InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer->Add_Head(reinterpret_cast<::DAVehicleSpawnPointClass*>(object->DAVehicleSpawnPointClassPointer.ToPointer()));
		}
	}

	bool DAVehicleSpawnPointClassPtrDynamicVectorClass::DeleteObj(IDAVehicleSpawnPointClass^ object)
	{
		if (object == nullptr || object->DAVehicleSpawnPointClassPointer.ToPointer() == nullptr)
		{
			return InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer->DeleteObj(nullptr);
		}
		else
		{
			return InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer->DeleteObj(reinterpret_cast<::DAVehicleSpawnPointClass*>(object->DAVehicleSpawnPointClassPointer.ToPointer()));
		}
	}

	bool DAVehicleSpawnPointClassPtrDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer->Delete(index);
	}

	void DAVehicleSpawnPointClassPtrDynamicVectorClass::DeleteAll()
	{
		InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer->Delete_All();
	}

	int DAVehicleSpawnPointClassPtrDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void DAVehicleSpawnPointClassPtrDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr DAVehicleSpawnPointClassPtrDynamicVectorClass::DAVehicleSpawnPointClassPtrDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer);
	}

	IDAVehicleSpawnPointClass^ DAVehicleSpawnPointClassPtrDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAVehicleSpawnPointClass(IntPtr(result));
		}
	}

	void DAVehicleSpawnPointClassPtrDynamicVectorClass::default::set(int index, IDAVehicleSpawnPointClass^ value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->DAVehicleSpawnPointClassPointer.ToPointer() == nullptr)
		{
			InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer->operator[](index) = reinterpret_cast<::DAVehicleSpawnPointClass*>(value->DAVehicleSpawnPointClassPointer.ToPointer());
		}
	}

	int DAVehicleSpawnPointClassPtrDynamicVectorClass::Length::get()
	{
		return InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer->Length();
	}

	int DAVehicleSpawnPointClassPtrDynamicVectorClass::Count::get()
	{
		return InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer->Count();
	}

	void DAVehicleSpawnPointClassPtrDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer->Set_Active(value);
	}

	int DAVehicleSpawnPointClassPtrDynamicVectorClass::GrowthStep::get()
	{
		return InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer->Growth_Step();
	}

	void DAVehicleSpawnPointClassPtrDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool DAVehicleSpawnPointClassPtrDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyDAVehicleSpawnPointClassPtrDynamicVectorClass(InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::DAVehicleSpawnPointClass*>* DAVehicleSpawnPointClassPtrDynamicVectorClass::InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::DAVehicleSpawnPointClass*>*>(Pointer.ToPointer());
	}

	IntPtr DAVehicleSpawnPointClassPtrDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAVehicleSpawnPointClass*>*>(InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void DAVehicleSpawnPointClassPtrDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAVehicleSpawnPointClass*>*>(InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::DAVehicleSpawnPointClass * *>(value.ToPointer()));
	}

	int DAVehicleSpawnPointClassPtrDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAVehicleSpawnPointClass*>*>(InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void DAVehicleSpawnPointClassPtrDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAVehicleSpawnPointClass*>*>(InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool DAVehicleSpawnPointClassPtrDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAVehicleSpawnPointClass*>*>(InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void DAVehicleSpawnPointClassPtrDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAVehicleSpawnPointClass*>*>(InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool DAVehicleSpawnPointClassPtrDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAVehicleSpawnPointClass*>*>(InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void DAVehicleSpawnPointClassPtrDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAVehicleSpawnPointClass*>*>(InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int DAVehicleSpawnPointClassPtrDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAVehicleSpawnPointClass*>*>(InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void DAVehicleSpawnPointClassPtrDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DAVehicleSpawnPointClass*>*>(InternalDAVehicleSpawnPointClassPtrDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}