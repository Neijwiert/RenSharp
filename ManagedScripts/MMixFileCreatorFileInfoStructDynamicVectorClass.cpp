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
#include "MMixFileCreatorFileInfoStructDynamicVectorClass.h"

#include "Imports.h"

namespace RenSharp
{
	MixFileCreatorFileInfoStructDynamicVectorClass::MixFileCreatorFileInfoStructDynamicVectorClass()
		: DynamicVectorClass<IMixFileCreatorFileInfoStruct^>(IntPtr(Imports::CreateMixFileCreatorFileInfoStructDynamicVectorClass1()))
	{

	}

	MixFileCreatorFileInfoStructDynamicVectorClass::MixFileCreatorFileInfoStructDynamicVectorClass(int size)
		: DynamicVectorClass<IMixFileCreatorFileInfoStruct^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateMixFileCreatorFileInfoStructDynamicVectorClass2(size));
	}

	MixFileCreatorFileInfoStructDynamicVectorClass::MixFileCreatorFileInfoStructDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<IMixFileCreatorFileInfoStruct^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<IMixFileCreatorFileInfoStruct^>^>^ MixFileCreatorFileInfoStructDynamicVectorClass::CreateMixFileCreatorFileInfoStructDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IMixFileCreatorFileInfoStruct^>^>(gcnew MixFileCreatorFileInfoStructDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<IMixFileCreatorFileInfoStruct^>^>^ MixFileCreatorFileInfoStructDynamicVectorClass::CreateMixFileCreatorFileInfoStructDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IMixFileCreatorFileInfoStruct^>^>(gcnew MixFileCreatorFileInfoStructDynamicVectorClass(size));
	}

	bool MixFileCreatorFileInfoStructDynamicVectorClass::Resize(int newSize)
	{
		return InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer->Resize(newSize);
	}

	void MixFileCreatorFileInfoStructDynamicVectorClass::Clear()
	{
		InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer->Clear();
	}

	int MixFileCreatorFileInfoStructDynamicVectorClass::ID(IMixFileCreatorFileInfoStruct^ object)
	{
		if (object == nullptr || object->FileInfoStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		return InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer->ID(
			*reinterpret_cast<::MixFileCreator::FileInfoStruct*>(object->FileInfoStructPointer.ToPointer()));
	}

	void MixFileCreatorFileInfoStructDynamicVectorClass::Insert(int index, IMixFileCreatorFileInfoStruct^ object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}
		else if (object == nullptr || object->FileInfoStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer->Insert(
			index,
			*reinterpret_cast<::MixFileCreator::FileInfoStruct*>(object->FileInfoStructPointer.ToPointer()));
	}

	bool MixFileCreatorFileInfoStructDynamicVectorClass::Add(IMixFileCreatorFileInfoStruct^ object)
	{
		if (object == nullptr || object->FileInfoStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		return InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer->Add(
			*reinterpret_cast<::MixFileCreator::FileInfoStruct*>(object->FileInfoStructPointer.ToPointer()));
	}

	void MixFileCreatorFileInfoStructDynamicVectorClass::ResetActive()
	{
		InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer->Reset_Active();
	}

	bool MixFileCreatorFileInfoStructDynamicVectorClass::AddHead(IMixFileCreatorFileInfoStruct^ object)
	{
		if (object == nullptr || object->FileInfoStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		return InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer->Add_Head(
			*reinterpret_cast<::MixFileCreator::FileInfoStruct*>(object->FileInfoStructPointer.ToPointer()));
	}

	bool MixFileCreatorFileInfoStructDynamicVectorClass::DeleteObj(IMixFileCreatorFileInfoStruct^ object)
	{
		if (object == nullptr || object->FileInfoStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		return InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer->DeleteObj(
			*reinterpret_cast<::MixFileCreator::FileInfoStruct*>(object->FileInfoStructPointer.ToPointer()));
	}

	bool MixFileCreatorFileInfoStructDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer->Delete(index);
	}

	void MixFileCreatorFileInfoStructDynamicVectorClass::DeleteAll()
	{
		InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer->Delete_All();
	}

	int MixFileCreatorFileInfoStructDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void MixFileCreatorFileInfoStructDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr MixFileCreatorFileInfoStructDynamicVectorClass::MixFileCreatorFileInfoStructDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer);
	}

	IMixFileCreatorFileInfoStruct^ MixFileCreatorFileInfoStructDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto& result = InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer->operator[](index);

		return gcnew MixFileCreatorFileInfoStruct(IntPtr(&result));
	}

	void MixFileCreatorFileInfoStructDynamicVectorClass::default::set(int index, IMixFileCreatorFileInfoStruct^ value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}
		else if (value == nullptr || value->FileInfoStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer->operator[](index) =
			*reinterpret_cast<::MixFileCreator::FileInfoStruct*>(value->FileInfoStructPointer.ToPointer());
	}

	int MixFileCreatorFileInfoStructDynamicVectorClass::Length::get()
	{
		return InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer->Length();
	}

	int MixFileCreatorFileInfoStructDynamicVectorClass::Count::get()
	{
		return InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer->Count();
	}

	void MixFileCreatorFileInfoStructDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer->Set_Active(value);
	}

	int MixFileCreatorFileInfoStructDynamicVectorClass::GrowthStep::get()
	{
		return InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer->Growth_Step();
	}

	void MixFileCreatorFileInfoStructDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool MixFileCreatorFileInfoStructDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyMixFileCreatorFileInfoStructDynamicVectorClass(InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::MixFileCreator::FileInfoStruct>* MixFileCreatorFileInfoStructDynamicVectorClass::InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::MixFileCreator::FileInfoStruct>*>(Pointer.ToPointer());
	}

	IntPtr MixFileCreatorFileInfoStructDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileCreator::FileInfoStruct>*>(InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void MixFileCreatorFileInfoStructDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileCreator::FileInfoStruct>*>(InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::MixFileCreator::FileInfoStruct*>(value.ToPointer()));
	}

	int MixFileCreatorFileInfoStructDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileCreator::FileInfoStruct>*>(InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void MixFileCreatorFileInfoStructDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileCreator::FileInfoStruct>*>(InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool MixFileCreatorFileInfoStructDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileCreator::FileInfoStruct>*>(InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void MixFileCreatorFileInfoStructDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileCreator::FileInfoStruct>*>(InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool MixFileCreatorFileInfoStructDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileCreator::FileInfoStruct>*>(InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void MixFileCreatorFileInfoStructDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileCreator::FileInfoStruct>*>(InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int MixFileCreatorFileInfoStructDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileCreator::FileInfoStruct>*>(InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void MixFileCreatorFileInfoStructDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileCreator::FileInfoStruct>*>(InternalMixFileCreatorFileInfoStructDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}