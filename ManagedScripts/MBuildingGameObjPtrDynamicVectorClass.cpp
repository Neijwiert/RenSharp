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
#include "MBuildingGameObjPtrDynamicVectorClass.h"

#include "Imports.h"
#include "MBuildingGameObj.h"

namespace RenSharp
{
	BuildingGameObjPtrDynamicVectorClass::BuildingGameObjPtrDynamicVectorClass()
		: DynamicVectorClass<IBuildingGameObj ^>(IntPtr(Imports::CreateBuildingGameObjPtrDynamicVectorClass1()))
	{

	}

	BuildingGameObjPtrDynamicVectorClass::BuildingGameObjPtrDynamicVectorClass(int size)
		: DynamicVectorClass<IBuildingGameObj ^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateBuildingGameObjPtrDynamicVectorClass2(size));
	}

	BuildingGameObjPtrDynamicVectorClass::BuildingGameObjPtrDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<IBuildingGameObj ^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<IBuildingGameObj ^> ^> ^BuildingGameObjPtrDynamicVectorClass::CreateBuildingGameObjPtrDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IBuildingGameObj ^> ^>(gcnew BuildingGameObjPtrDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<IBuildingGameObj ^> ^> ^BuildingGameObjPtrDynamicVectorClass::CreateBuildingGameObjPtrDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IBuildingGameObj ^> ^>(gcnew BuildingGameObjPtrDynamicVectorClass(size));
	}

	bool BuildingGameObjPtrDynamicVectorClass::Resize(int newSize)
	{
		return InternalBuildingGameObjPtrDynamicVectorClassPointer->Resize(newSize);
	}

	void BuildingGameObjPtrDynamicVectorClass::Clear()
	{
		InternalBuildingGameObjPtrDynamicVectorClassPointer->Clear();
	}

	int BuildingGameObjPtrDynamicVectorClass::ID(IBuildingGameObj ^object)
	{
		if (object == nullptr || object->BuildingGameObjPointer.ToPointer() == nullptr)
		{
			return InternalBuildingGameObjPtrDynamicVectorClassPointer->ID(static_cast<::BuildingGameObj *>(nullptr));
		}
		else
		{
			return InternalBuildingGameObjPtrDynamicVectorClassPointer->ID(reinterpret_cast<::BuildingGameObj *>(object->BuildingGameObjPointer.ToPointer()));
		}
	}

	void BuildingGameObjPtrDynamicVectorClass::Insert(int index, IBuildingGameObj ^object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (object == nullptr || object->BuildingGameObjPointer.ToPointer() == nullptr)
		{
			InternalBuildingGameObjPtrDynamicVectorClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalBuildingGameObjPtrDynamicVectorClassPointer->Insert(index, reinterpret_cast<::BuildingGameObj *>(object->BuildingGameObjPointer.ToPointer()));
		}
	}

	bool BuildingGameObjPtrDynamicVectorClass::Add(IBuildingGameObj ^object)
	{
		if (object == nullptr || object->BuildingGameObjPointer.ToPointer() == nullptr)
		{
			return InternalBuildingGameObjPtrDynamicVectorClassPointer->Add(nullptr);
		}
		else
		{
			return InternalBuildingGameObjPtrDynamicVectorClassPointer->Add(reinterpret_cast<::BuildingGameObj *>(object->BuildingGameObjPointer.ToPointer()));
		}
	}

	void BuildingGameObjPtrDynamicVectorClass::ResetActive()
	{
		InternalBuildingGameObjPtrDynamicVectorClassPointer->Reset_Active();
	}

	bool BuildingGameObjPtrDynamicVectorClass::AddHead(IBuildingGameObj ^object)
	{
		if (object == nullptr || object->BuildingGameObjPointer.ToPointer() == nullptr)
		{
			return InternalBuildingGameObjPtrDynamicVectorClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalBuildingGameObjPtrDynamicVectorClassPointer->Add_Head(reinterpret_cast<::BuildingGameObj *>(object->BuildingGameObjPointer.ToPointer()));
		}
	}

	bool BuildingGameObjPtrDynamicVectorClass::DeleteObj(IBuildingGameObj ^object)
	{
		if (object == nullptr || object->BuildingGameObjPointer.ToPointer() == nullptr)
		{
			return InternalBuildingGameObjPtrDynamicVectorClassPointer->DeleteObj(nullptr);
		}
		else
		{
			return InternalBuildingGameObjPtrDynamicVectorClassPointer->DeleteObj(reinterpret_cast<::BuildingGameObj *>(object->BuildingGameObjPointer.ToPointer()));
		}
	}

	bool BuildingGameObjPtrDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalBuildingGameObjPtrDynamicVectorClassPointer->Delete(index);
	}

	void BuildingGameObjPtrDynamicVectorClass::DeleteAll()
	{
		InternalBuildingGameObjPtrDynamicVectorClassPointer->Delete_All();
	}

	int BuildingGameObjPtrDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalBuildingGameObjPtrDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void BuildingGameObjPtrDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalBuildingGameObjPtrDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr BuildingGameObjPtrDynamicVectorClass::BuildingGameObjPtrDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalBuildingGameObjPtrDynamicVectorClassPointer);
	}

	IBuildingGameObj ^BuildingGameObjPtrDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalBuildingGameObjPtrDynamicVectorClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew BuildingGameObj(IntPtr(result));
		}
	}

	void BuildingGameObjPtrDynamicVectorClass::default::set(int index, IBuildingGameObj ^value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->BuildingGameObjPointer.ToPointer() == nullptr)
		{
			InternalBuildingGameObjPtrDynamicVectorClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalBuildingGameObjPtrDynamicVectorClassPointer->operator[](index) = reinterpret_cast<::BuildingGameObj *>(value->BuildingGameObjPointer.ToPointer());
		}
	}

	int BuildingGameObjPtrDynamicVectorClass::Length::get()
	{
		return InternalBuildingGameObjPtrDynamicVectorClassPointer->Length();
	}

	int BuildingGameObjPtrDynamicVectorClass::Count::get()
	{
		return InternalBuildingGameObjPtrDynamicVectorClassPointer->Count();
	}

	void BuildingGameObjPtrDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalBuildingGameObjPtrDynamicVectorClassPointer->Set_Active(value);
	}

	int BuildingGameObjPtrDynamicVectorClass::GrowthStep::get()
	{
		return InternalBuildingGameObjPtrDynamicVectorClassPointer->Growth_Step();
	}

	void BuildingGameObjPtrDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalBuildingGameObjPtrDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool BuildingGameObjPtrDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyBuildingGameObjPtrDynamicVectorClass(InternalBuildingGameObjPtrDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::BuildingGameObj *> *BuildingGameObjPtrDynamicVectorClass::InternalBuildingGameObjPtrDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::BuildingGameObj *> *>(Pointer.ToPointer());
	}

	IntPtr BuildingGameObjPtrDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::BuildingGameObj *> *>(InternalBuildingGameObjPtrDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void BuildingGameObjPtrDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::BuildingGameObj *> *>(InternalBuildingGameObjPtrDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::BuildingGameObj **>(value.ToPointer()));
	}

	int BuildingGameObjPtrDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::BuildingGameObj *> *>(InternalBuildingGameObjPtrDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void BuildingGameObjPtrDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::BuildingGameObj *> *>(InternalBuildingGameObjPtrDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool BuildingGameObjPtrDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::BuildingGameObj *> *>(InternalBuildingGameObjPtrDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void BuildingGameObjPtrDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::BuildingGameObj *> *>(InternalBuildingGameObjPtrDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool BuildingGameObjPtrDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::BuildingGameObj *> *>(InternalBuildingGameObjPtrDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void BuildingGameObjPtrDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::BuildingGameObj *> *>(InternalBuildingGameObjPtrDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int BuildingGameObjPtrDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::BuildingGameObj *> *>(InternalBuildingGameObjPtrDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void BuildingGameObjPtrDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::BuildingGameObj *> *>(InternalBuildingGameObjPtrDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}