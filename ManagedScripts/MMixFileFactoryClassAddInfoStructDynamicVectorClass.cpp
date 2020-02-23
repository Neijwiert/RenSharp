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
#include "MMixFileFactoryClassAddInfoStructDynamicVectorClass.h"

#include "Imports.h"

namespace RenSharp
{
	MixFileFactoryClassAddInfoStructDynamicVectorClass::MixFileFactoryClassAddInfoStructDynamicVectorClass()
		: DynamicVectorClass<MixFileFactoryClass::IAddInfoStruct^>(IntPtr(Imports::CreateMixFileFactoryClassAddInfoStructDynamicVectorClass1()))
	{

	}

	MixFileFactoryClassAddInfoStructDynamicVectorClass::MixFileFactoryClassAddInfoStructDynamicVectorClass(int size)
		: DynamicVectorClass<MixFileFactoryClass::IAddInfoStruct^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateMixFileFactoryClassAddInfoStructDynamicVectorClass2(size));
	}

	MixFileFactoryClassAddInfoStructDynamicVectorClass::MixFileFactoryClassAddInfoStructDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<MixFileFactoryClass::IAddInfoStruct^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<MixFileFactoryClass::IAddInfoStruct^>^>^ MixFileFactoryClassAddInfoStructDynamicVectorClass::CreateMixFileFactoryClassAddInfoStructDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<MixFileFactoryClass::IAddInfoStruct^>^>(gcnew MixFileFactoryClassAddInfoStructDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<MixFileFactoryClass::IAddInfoStruct^>^>^ MixFileFactoryClassAddInfoStructDynamicVectorClass::CreateMixFileFactoryClassAddInfoStructDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<MixFileFactoryClass::IAddInfoStruct^>^>(gcnew MixFileFactoryClassAddInfoStructDynamicVectorClass(size));
	}

	bool MixFileFactoryClassAddInfoStructDynamicVectorClass::Resize(int newSize)
	{
		return InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer->Resize(newSize);
	}

	void MixFileFactoryClassAddInfoStructDynamicVectorClass::Clear()
	{
		InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer->Clear();
	}

	int MixFileFactoryClassAddInfoStructDynamicVectorClass::ID(MixFileFactoryClass::IAddInfoStruct^ object)
	{
		if (object == nullptr || object->AddInfoStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		return InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer->ID(
			*reinterpret_cast<::MixFileFactoryClass::AddInfoStruct*>(object->AddInfoStructPointer.ToPointer()));
	}

	void MixFileFactoryClassAddInfoStructDynamicVectorClass::Insert(int index, MixFileFactoryClass::IAddInfoStruct^ object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}
		else if (object == nullptr || object->AddInfoStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer->Insert(
			index,
			*reinterpret_cast<::MixFileFactoryClass::AddInfoStruct*>(object->AddInfoStructPointer.ToPointer()));
	}

	bool MixFileFactoryClassAddInfoStructDynamicVectorClass::Add(MixFileFactoryClass::IAddInfoStruct^ object)
	{
		if (object == nullptr || object->AddInfoStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		return InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer->Add(
			*reinterpret_cast<::MixFileFactoryClass::AddInfoStruct*>(object->AddInfoStructPointer.ToPointer()));
	}

	void MixFileFactoryClassAddInfoStructDynamicVectorClass::ResetActive()
	{
		InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer->Reset_Active();
	}

	bool MixFileFactoryClassAddInfoStructDynamicVectorClass::AddHead(MixFileFactoryClass::IAddInfoStruct^ object)
	{
		if (object == nullptr || object->AddInfoStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		return InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer->Add_Head(
			*reinterpret_cast<::MixFileFactoryClass::AddInfoStruct*>(object->AddInfoStructPointer.ToPointer()));
	}

	bool MixFileFactoryClassAddInfoStructDynamicVectorClass::DeleteObj(MixFileFactoryClass::IAddInfoStruct^ object)
	{
		if (object == nullptr || object->AddInfoStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		return InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer->DeleteObj(
			*reinterpret_cast<::MixFileFactoryClass::AddInfoStruct*>(object->AddInfoStructPointer.ToPointer()));
	}

	bool MixFileFactoryClassAddInfoStructDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer->Delete(index);
	}

	void MixFileFactoryClassAddInfoStructDynamicVectorClass::DeleteAll()
	{
		InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer->Delete_All();
	}

	int MixFileFactoryClassAddInfoStructDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void MixFileFactoryClassAddInfoStructDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr MixFileFactoryClassAddInfoStructDynamicVectorClass::MixFileFactoryClassAddInfoStructDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer);
	}

	MixFileFactoryClass::IAddInfoStruct^ MixFileFactoryClassAddInfoStructDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto& result = InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer->operator[](index);

		return gcnew MixFileFactoryClass::AddInfoStruct(IntPtr(&result));
	}

	void MixFileFactoryClassAddInfoStructDynamicVectorClass::default::set(int index, MixFileFactoryClass::IAddInfoStruct^ value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}
		else if (value == nullptr || value->AddInfoStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer->operator[](index) =
			*reinterpret_cast<::MixFileFactoryClass::AddInfoStruct*>(value->AddInfoStructPointer.ToPointer());
	}

	int MixFileFactoryClassAddInfoStructDynamicVectorClass::Length::get()
	{
		return InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer->Length();
	}

	int MixFileFactoryClassAddInfoStructDynamicVectorClass::Count::get()
	{
		return InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer->Count();
	}

	void MixFileFactoryClassAddInfoStructDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer->Set_Active(value);
	}

	int MixFileFactoryClassAddInfoStructDynamicVectorClass::GrowthStep::get()
	{
		return InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer->Growth_Step();
	}

	void MixFileFactoryClassAddInfoStructDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool MixFileFactoryClassAddInfoStructDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyMixFileFactoryClassAddInfoStructDynamicVectorClass(InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::MixFileFactoryClass::AddInfoStruct>* MixFileFactoryClassAddInfoStructDynamicVectorClass::InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::MixFileFactoryClass::AddInfoStruct>*>(Pointer.ToPointer());
	}

	IntPtr MixFileFactoryClassAddInfoStructDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileFactoryClass::AddInfoStruct>*>(InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void MixFileFactoryClassAddInfoStructDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileFactoryClass::AddInfoStruct>*>(InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::MixFileFactoryClass::AddInfoStruct*>(value.ToPointer()));
	}

	int MixFileFactoryClassAddInfoStructDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileFactoryClass::AddInfoStruct>*>(InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void MixFileFactoryClassAddInfoStructDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileFactoryClass::AddInfoStruct>*>(InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool MixFileFactoryClassAddInfoStructDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileFactoryClass::AddInfoStruct>*>(InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void MixFileFactoryClassAddInfoStructDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileFactoryClass::AddInfoStruct>*>(InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool MixFileFactoryClassAddInfoStructDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileFactoryClass::AddInfoStruct>*>(InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void MixFileFactoryClassAddInfoStructDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileFactoryClass::AddInfoStruct>*>(InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int MixFileFactoryClassAddInfoStructDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileFactoryClass::AddInfoStruct>*>(InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void MixFileFactoryClassAddInfoStructDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileFactoryClass::AddInfoStruct>*>(InternalMixFileFactoryClassAddInfoStructDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}