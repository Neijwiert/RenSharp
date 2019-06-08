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
#include "McPlayerPtrDynamicVectorClass.h"

#include "Imports.h"
#include "McPlayer.h"

namespace RenSharp
{
	cPlayerPtrDynamicVectorClass::cPlayerPtrDynamicVectorClass()
		: DynamicVectorClass<IcPlayer^>(IntPtr(Imports::CreatecPlayerPtrDynamicVectorClass1()))
	{

	}

	cPlayerPtrDynamicVectorClass::cPlayerPtrDynamicVectorClass(int size)
		: DynamicVectorClass<IcPlayer^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreatecPlayerPtrDynamicVectorClass2(size));
	}

	cPlayerPtrDynamicVectorClass::cPlayerPtrDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<IcPlayer^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<IcPlayer^>^>^ cPlayerPtrDynamicVectorClass::CreatecPlayerPtrDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IcPlayer^>^>(gcnew cPlayerPtrDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<IcPlayer^>^>^ cPlayerPtrDynamicVectorClass::CreatecPlayerPtrDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IcPlayer^>^>(gcnew cPlayerPtrDynamicVectorClass(size));
	}

	bool cPlayerPtrDynamicVectorClass::Resize(int newSize)
	{
		return InternalcPlayerPtrDynamicVectorClassPointer->Resize(newSize);
	}

	void cPlayerPtrDynamicVectorClass::Clear()
	{
		InternalcPlayerPtrDynamicVectorClassPointer->Clear();
	}

	int cPlayerPtrDynamicVectorClass::ID(IcPlayer^ object)
	{
		if (object == nullptr || object->cPlayerPointer.ToPointer() == nullptr)
		{
			return InternalcPlayerPtrDynamicVectorClassPointer->ID(static_cast<::cPlayer*>(nullptr));
		}
		else
		{
			return InternalcPlayerPtrDynamicVectorClassPointer->ID(reinterpret_cast<::cPlayer*>(object->cPlayerPointer.ToPointer()));
		}
	}

	void cPlayerPtrDynamicVectorClass::Insert(int index, IcPlayer^ object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (object == nullptr || object->cPlayerPointer.ToPointer() == nullptr)
		{
			InternalcPlayerPtrDynamicVectorClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalcPlayerPtrDynamicVectorClassPointer->Insert(index, reinterpret_cast<::cPlayer*>(object->cPlayerPointer.ToPointer()));
		}
	}

	bool cPlayerPtrDynamicVectorClass::Add(IcPlayer^ object)
	{
		if (object == nullptr || object->cPlayerPointer.ToPointer() == nullptr)
		{
			return InternalcPlayerPtrDynamicVectorClassPointer->Add(nullptr);
		}
		else
		{
			return InternalcPlayerPtrDynamicVectorClassPointer->Add(reinterpret_cast<::cPlayer*>(object->cPlayerPointer.ToPointer()));
		}
	}

	void cPlayerPtrDynamicVectorClass::ResetActive()
	{
		InternalcPlayerPtrDynamicVectorClassPointer->Reset_Active();
	}

	bool cPlayerPtrDynamicVectorClass::AddHead(IcPlayer^ object)
	{
		if (object == nullptr || object->cPlayerPointer.ToPointer() == nullptr)
		{
			return InternalcPlayerPtrDynamicVectorClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalcPlayerPtrDynamicVectorClassPointer->Add_Head(reinterpret_cast<::cPlayer*>(object->cPlayerPointer.ToPointer()));
		}
	}

	bool cPlayerPtrDynamicVectorClass::DeleteObj(IcPlayer^ object)
	{
		if (object == nullptr || object->cPlayerPointer.ToPointer() == nullptr)
		{
			return InternalcPlayerPtrDynamicVectorClassPointer->DeleteObj(nullptr);
		}
		else
		{
			return InternalcPlayerPtrDynamicVectorClassPointer->DeleteObj(reinterpret_cast<::cPlayer*>(object->cPlayerPointer.ToPointer()));
		}
	}

	bool cPlayerPtrDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalcPlayerPtrDynamicVectorClassPointer->Delete(index);
	}

	void cPlayerPtrDynamicVectorClass::DeleteAll()
	{
		InternalcPlayerPtrDynamicVectorClassPointer->Delete_All();
	}

	int cPlayerPtrDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalcPlayerPtrDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void cPlayerPtrDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalcPlayerPtrDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr cPlayerPtrDynamicVectorClass::cPlayerPtrDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalcPlayerPtrDynamicVectorClassPointer);
	}

	IcPlayer^ cPlayerPtrDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalcPlayerPtrDynamicVectorClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	void cPlayerPtrDynamicVectorClass::default::set(int index, IcPlayer^ value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->cPlayerPointer.ToPointer() == nullptr)
		{
			InternalcPlayerPtrDynamicVectorClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalcPlayerPtrDynamicVectorClassPointer->operator[](index) = reinterpret_cast<::cPlayer*>(value->cPlayerPointer.ToPointer());
		}
	}

	int cPlayerPtrDynamicVectorClass::Length::get()
	{
		return InternalcPlayerPtrDynamicVectorClassPointer->Length();
	}

	int cPlayerPtrDynamicVectorClass::Count::get()
	{
		return InternalcPlayerPtrDynamicVectorClassPointer->Count();
	}

	void cPlayerPtrDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalcPlayerPtrDynamicVectorClassPointer->Set_Active(value);
	}

	int cPlayerPtrDynamicVectorClass::GrowthStep::get()
	{
		return InternalcPlayerPtrDynamicVectorClassPointer->Growth_Step();
	}

	void cPlayerPtrDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalcPlayerPtrDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool cPlayerPtrDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroycPlayerPtrDynamicVectorClass(InternalcPlayerPtrDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::cPlayer*>* cPlayerPtrDynamicVectorClass::InternalcPlayerPtrDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::cPlayer*>*>(Pointer.ToPointer());
	}

	IntPtr cPlayerPtrDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::cPlayer*>*>(InternalcPlayerPtrDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void cPlayerPtrDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::cPlayer*>*>(InternalcPlayerPtrDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::cPlayer * *>(value.ToPointer()));
	}

	int cPlayerPtrDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::cPlayer*>*>(InternalcPlayerPtrDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void cPlayerPtrDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::cPlayer*>*>(InternalcPlayerPtrDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool cPlayerPtrDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::cPlayer*>*>(InternalcPlayerPtrDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void cPlayerPtrDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::cPlayer*>*>(InternalcPlayerPtrDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool cPlayerPtrDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::cPlayer*>*>(InternalcPlayerPtrDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void cPlayerPtrDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::cPlayer*>*>(InternalcPlayerPtrDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int cPlayerPtrDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::cPlayer*>*>(InternalcPlayerPtrDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void cPlayerPtrDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::cPlayer*>*>(InternalcPlayerPtrDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}