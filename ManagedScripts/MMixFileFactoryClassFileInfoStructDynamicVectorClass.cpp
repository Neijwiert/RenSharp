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
#include "MMixFileFactoryClassFileInfoStructDynamicVectorClass.h"

#include "Imports.h"

namespace RenSharp
{
	MixFileFactoryClassFileInfoStructDynamicVectorClass::MixFileFactoryClassFileInfoStructDynamicVectorClass()
		: DynamicVectorClass<MixFileFactoryClass::IFileInfoStruct^>(IntPtr(Imports::CreateMixFileFactoryClassFileInfoStructDynamicVectorClass1()))
	{

	}

	MixFileFactoryClassFileInfoStructDynamicVectorClass::MixFileFactoryClassFileInfoStructDynamicVectorClass(int size)
		: DynamicVectorClass<MixFileFactoryClass::IFileInfoStruct^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateMixFileFactoryClassFileInfoStructDynamicVectorClass2(size));
	}

	MixFileFactoryClassFileInfoStructDynamicVectorClass::MixFileFactoryClassFileInfoStructDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<MixFileFactoryClass::IFileInfoStruct^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<MixFileFactoryClass::IFileInfoStruct^>^>^ MixFileFactoryClassFileInfoStructDynamicVectorClass::CreateMixFileFactoryClassFileInfoStructDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<MixFileFactoryClass::IFileInfoStruct^>^>(gcnew MixFileFactoryClassFileInfoStructDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<MixFileFactoryClass::IFileInfoStruct^>^>^ MixFileFactoryClassFileInfoStructDynamicVectorClass::CreateMixFileFactoryClassFileInfoStructDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<MixFileFactoryClass::IFileInfoStruct^>^>(gcnew MixFileFactoryClassFileInfoStructDynamicVectorClass(size));
	}

	bool MixFileFactoryClassFileInfoStructDynamicVectorClass::Resize(int newSize)
	{
		return InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer->Resize(newSize);
	}

	void MixFileFactoryClassFileInfoStructDynamicVectorClass::Clear()
	{
		InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer->Clear();
	}

	int MixFileFactoryClassFileInfoStructDynamicVectorClass::ID(MixFileFactoryClass::IFileInfoStruct^ object)
	{
		if (object == nullptr || object->FileInfoStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		return InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer->ID(
			*reinterpret_cast<::MixFileFactoryClass::FileInfoStruct*>(object->FileInfoStructPointer.ToPointer()));
	}

	void MixFileFactoryClassFileInfoStructDynamicVectorClass::Insert(int index, MixFileFactoryClass::IFileInfoStruct^ object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}
		else if (object == nullptr || object->FileInfoStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer->Insert(
			index,
			*reinterpret_cast<::MixFileFactoryClass::FileInfoStruct*>(object->FileInfoStructPointer.ToPointer()));
	}

	bool MixFileFactoryClassFileInfoStructDynamicVectorClass::Add(MixFileFactoryClass::IFileInfoStruct^ object)
	{
		if (object == nullptr || object->FileInfoStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		return InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer->Add(
			*reinterpret_cast<::MixFileFactoryClass::FileInfoStruct*>(object->FileInfoStructPointer.ToPointer()));
	}

	void MixFileFactoryClassFileInfoStructDynamicVectorClass::ResetActive()
	{
		InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer->Reset_Active();
	}

	bool MixFileFactoryClassFileInfoStructDynamicVectorClass::AddHead(MixFileFactoryClass::IFileInfoStruct^ object)
	{
		if (object == nullptr || object->FileInfoStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		return InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer->Add_Head(
			*reinterpret_cast<::MixFileFactoryClass::FileInfoStruct*>(object->FileInfoStructPointer.ToPointer()));
	}

	bool MixFileFactoryClassFileInfoStructDynamicVectorClass::DeleteObj(MixFileFactoryClass::IFileInfoStruct^ object)
	{
		if (object == nullptr || object->FileInfoStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("object");
		}

		return InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer->DeleteObj(
			*reinterpret_cast<::MixFileFactoryClass::FileInfoStruct*>(object->FileInfoStructPointer.ToPointer()));
	}

	bool MixFileFactoryClassFileInfoStructDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer->Delete(index);
	}

	void MixFileFactoryClassFileInfoStructDynamicVectorClass::DeleteAll()
	{
		InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer->Delete_All();
	}

	int MixFileFactoryClassFileInfoStructDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void MixFileFactoryClassFileInfoStructDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr MixFileFactoryClassFileInfoStructDynamicVectorClass::MixFileFactoryClassFileInfoStructDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer);
	}

	MixFileFactoryClass::IFileInfoStruct^ MixFileFactoryClassFileInfoStructDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto& result = InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer->operator[](index);

		return gcnew MixFileFactoryClass::FileInfoStruct(IntPtr(&result));
	}

	void MixFileFactoryClassFileInfoStructDynamicVectorClass::default::set(int index, MixFileFactoryClass::IFileInfoStruct^ value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}
		else if (value == nullptr || value->FileInfoStructPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer->operator[](index) =
			*reinterpret_cast<::MixFileFactoryClass::FileInfoStruct*>(value->FileInfoStructPointer.ToPointer());
	}

	int MixFileFactoryClassFileInfoStructDynamicVectorClass::Length::get()
	{
		return InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer->Length();
	}

	int MixFileFactoryClassFileInfoStructDynamicVectorClass::Count::get()
	{
		return InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer->Count();
	}

	void MixFileFactoryClassFileInfoStructDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer->Set_Active(value);
	}

	int MixFileFactoryClassFileInfoStructDynamicVectorClass::GrowthStep::get()
	{
		return InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer->Growth_Step();
	}

	void MixFileFactoryClassFileInfoStructDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool MixFileFactoryClassFileInfoStructDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyMixFileFactoryClassFileInfoStructDynamicVectorClass(InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::MixFileFactoryClass::FileInfoStruct>* MixFileFactoryClassFileInfoStructDynamicVectorClass::InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::MixFileFactoryClass::FileInfoStruct>*>(Pointer.ToPointer());
	}

	IntPtr MixFileFactoryClassFileInfoStructDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileFactoryClass::FileInfoStruct>*>(InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void MixFileFactoryClassFileInfoStructDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileFactoryClass::FileInfoStruct>*>(InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::MixFileFactoryClass::FileInfoStruct*>(value.ToPointer()));
	}

	int MixFileFactoryClassFileInfoStructDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileFactoryClass::FileInfoStruct>*>(InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void MixFileFactoryClassFileInfoStructDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileFactoryClass::FileInfoStruct>*>(InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool MixFileFactoryClassFileInfoStructDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileFactoryClass::FileInfoStruct>*>(InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void MixFileFactoryClassFileInfoStructDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileFactoryClass::FileInfoStruct>*>(InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool MixFileFactoryClassFileInfoStructDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileFactoryClass::FileInfoStruct>*>(InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void MixFileFactoryClassFileInfoStructDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileFactoryClass::FileInfoStruct>*>(InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int MixFileFactoryClassFileInfoStructDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileFactoryClass::FileInfoStruct>*>(InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void MixFileFactoryClassFileInfoStructDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::MixFileFactoryClass::FileInfoStruct>*>(InternalMixFileFactoryClassFileInfoStructDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}