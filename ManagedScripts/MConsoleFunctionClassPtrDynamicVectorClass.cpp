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
#include "MConsoleFunctionClassPtrDynamicVectorClass.h"

#include "Mengine_tt.h"
#include "Imports.h"

namespace RenSharp
{
	ConsoleFunctionClassPtrDynamicVectorClass::ConsoleFunctionClassPtrDynamicVectorClass()
		: DynamicVectorClass<IConsoleFunctionClass ^>(IntPtr(Imports::CreateConsoleFunctionClassPtrDynamicVectorClass1()))
	{

	}

	ConsoleFunctionClassPtrDynamicVectorClass::ConsoleFunctionClassPtrDynamicVectorClass(int size)
		: DynamicVectorClass<IConsoleFunctionClass ^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateConsoleFunctionClassPtrDynamicVectorClass2(size));
	}

	ConsoleFunctionClassPtrDynamicVectorClass::ConsoleFunctionClassPtrDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<IConsoleFunctionClass ^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<IConsoleFunctionClass ^> ^> ^ConsoleFunctionClassPtrDynamicVectorClass::CreateConsoleFunctionClassPtrDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IConsoleFunctionClass ^> ^>(gcnew ConsoleFunctionClassPtrDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<IConsoleFunctionClass ^> ^> ^ConsoleFunctionClassPtrDynamicVectorClass::CreateConsoleFunctionClassPtrDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IConsoleFunctionClass ^> ^>(gcnew ConsoleFunctionClassPtrDynamicVectorClass(size));
	}

	bool ConsoleFunctionClassPtrDynamicVectorClass::Resize(int newSize)
	{
		return InternalConsoleFunctionClassPtrDynamicVectorClassPointer->Resize(newSize);
	}

	void ConsoleFunctionClassPtrDynamicVectorClass::Clear()
	{
		InternalConsoleFunctionClassPtrDynamicVectorClassPointer->Clear();
	}

	int ConsoleFunctionClassPtrDynamicVectorClass::ID(IConsoleFunctionClass ^object)
	{
		if (object == nullptr || object->ConsoleFunctionClassPointer.ToPointer() == nullptr)
		{
			return InternalConsoleFunctionClassPtrDynamicVectorClassPointer->ID(static_cast<::ConsoleFunctionClass *>(nullptr));
		}
		else
		{
			return InternalConsoleFunctionClassPtrDynamicVectorClassPointer->ID(reinterpret_cast<::ConsoleFunctionClass *>(object->ConsoleFunctionClassPointer.ToPointer()));
		}
	}

	void ConsoleFunctionClassPtrDynamicVectorClass::Insert(int index, IConsoleFunctionClass ^object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (object == nullptr || object->ConsoleFunctionClassPointer.ToPointer() == nullptr)
		{
			InternalConsoleFunctionClassPtrDynamicVectorClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalConsoleFunctionClassPtrDynamicVectorClassPointer->Insert(index, reinterpret_cast<::ConsoleFunctionClass *>(object->ConsoleFunctionClassPointer.ToPointer()));
		}
	}

	bool ConsoleFunctionClassPtrDynamicVectorClass::Add(IConsoleFunctionClass ^object)
	{
		if (object == nullptr || object->ConsoleFunctionClassPointer.ToPointer() == nullptr)
		{
			return InternalConsoleFunctionClassPtrDynamicVectorClassPointer->Add(nullptr);
		}
		else
		{
			return InternalConsoleFunctionClassPtrDynamicVectorClassPointer->Add(reinterpret_cast<::ConsoleFunctionClass *>(object->ConsoleFunctionClassPointer.ToPointer()));
		}
	}

	void ConsoleFunctionClassPtrDynamicVectorClass::ResetActive()
	{
		InternalConsoleFunctionClassPtrDynamicVectorClassPointer->Reset_Active();
	}

	bool ConsoleFunctionClassPtrDynamicVectorClass::AddHead(IConsoleFunctionClass ^object)
	{
		if (object == nullptr || object->ConsoleFunctionClassPointer.ToPointer() == nullptr)
		{
			return InternalConsoleFunctionClassPtrDynamicVectorClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalConsoleFunctionClassPtrDynamicVectorClassPointer->Add_Head(reinterpret_cast<::ConsoleFunctionClass *>(object->ConsoleFunctionClassPointer.ToPointer()));
		}
	}

	bool ConsoleFunctionClassPtrDynamicVectorClass::DeleteObj(IConsoleFunctionClass ^object)
	{
		if (object == nullptr || object->ConsoleFunctionClassPointer.ToPointer() == nullptr)
		{
			return InternalConsoleFunctionClassPtrDynamicVectorClassPointer->DeleteObj(nullptr);
		}
		else
		{
			return InternalConsoleFunctionClassPtrDynamicVectorClassPointer->DeleteObj(reinterpret_cast<::ConsoleFunctionClass *>(object->ConsoleFunctionClassPointer.ToPointer()));
		}
	}

	bool ConsoleFunctionClassPtrDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalConsoleFunctionClassPtrDynamicVectorClassPointer->Delete(index);
	}

	void ConsoleFunctionClassPtrDynamicVectorClass::DeleteAll()
	{
		InternalConsoleFunctionClassPtrDynamicVectorClassPointer->Delete_All();
	}

	int ConsoleFunctionClassPtrDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalConsoleFunctionClassPtrDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void ConsoleFunctionClassPtrDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalConsoleFunctionClassPtrDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr ConsoleFunctionClassPtrDynamicVectorClass::ConsoleFunctionClassPtrDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalConsoleFunctionClassPtrDynamicVectorClassPointer);
	}

	IConsoleFunctionClass ^ConsoleFunctionClassPtrDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalConsoleFunctionClassPtrDynamicVectorClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ConsoleFunctionClass(IntPtr(result));
		}
	}

	void ConsoleFunctionClassPtrDynamicVectorClass::default::set(int index, IConsoleFunctionClass ^value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->ConsoleFunctionClassPointer.ToPointer() == nullptr)
		{
			InternalConsoleFunctionClassPtrDynamicVectorClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalConsoleFunctionClassPtrDynamicVectorClassPointer->operator[](index) = reinterpret_cast<::ConsoleFunctionClass *>(value->ConsoleFunctionClassPointer.ToPointer());
		}
	}

	int ConsoleFunctionClassPtrDynamicVectorClass::Length::get()
	{
		return InternalConsoleFunctionClassPtrDynamicVectorClassPointer->Length();
	}

	int ConsoleFunctionClassPtrDynamicVectorClass::Count::get()
	{
		return InternalConsoleFunctionClassPtrDynamicVectorClassPointer->Count();
	}

	void ConsoleFunctionClassPtrDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalConsoleFunctionClassPtrDynamicVectorClassPointer->Set_Active(value);
	}

	int ConsoleFunctionClassPtrDynamicVectorClass::GrowthStep::get()
	{
		return InternalConsoleFunctionClassPtrDynamicVectorClassPointer->Growth_Step();
	}

	void ConsoleFunctionClassPtrDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalConsoleFunctionClassPtrDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool ConsoleFunctionClassPtrDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyConsoleFunctionClassPtrDynamicVectorClass(InternalConsoleFunctionClassPtrDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::ConsoleFunctionClass *> *ConsoleFunctionClassPtrDynamicVectorClass::InternalConsoleFunctionClassPtrDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::ConsoleFunctionClass *> *>(Pointer.ToPointer());
	}

	IntPtr ConsoleFunctionClassPtrDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::ConsoleFunctionClass *> *>(InternalConsoleFunctionClassPtrDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void ConsoleFunctionClassPtrDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::ConsoleFunctionClass *> *>(InternalConsoleFunctionClassPtrDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::ConsoleFunctionClass **>(value.ToPointer()));
	}

	int ConsoleFunctionClassPtrDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::ConsoleFunctionClass *> *>(InternalConsoleFunctionClassPtrDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void ConsoleFunctionClassPtrDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::ConsoleFunctionClass *> *>(InternalConsoleFunctionClassPtrDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool ConsoleFunctionClassPtrDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::ConsoleFunctionClass *> *>(InternalConsoleFunctionClassPtrDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void ConsoleFunctionClassPtrDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::ConsoleFunctionClass *> *>(InternalConsoleFunctionClassPtrDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool ConsoleFunctionClassPtrDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::ConsoleFunctionClass *> *>(InternalConsoleFunctionClassPtrDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void ConsoleFunctionClassPtrDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::ConsoleFunctionClass *> *>(InternalConsoleFunctionClassPtrDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int ConsoleFunctionClassPtrDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::ConsoleFunctionClass *> *>(InternalConsoleFunctionClassPtrDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void ConsoleFunctionClassPtrDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::ConsoleFunctionClass *> *>(InternalConsoleFunctionClassPtrDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}