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
#include "MDialogueOptionClassPtrDynamicVectorClass.h"

#include "Imports.h"
#include "MDialogueClass.h"

namespace RenSharp
{
	DialogueOptionClassPtrDynamicVectorClass::DialogueOptionClassPtrDynamicVectorClass()
		: DynamicVectorClass<IDialogueOptionClass ^>(IntPtr(Imports::CreateDialogueOptionClassPtrDynamicVectorClass1()))
	{

	}

	DialogueOptionClassPtrDynamicVectorClass::DialogueOptionClassPtrDynamicVectorClass(int size)
		: DynamicVectorClass<IDialogueOptionClass ^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateDialogueOptionClassPtrDynamicVectorClass2(size));
	}

	DialogueOptionClassPtrDynamicVectorClass::DialogueOptionClassPtrDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<IDialogueOptionClass ^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<IDialogueOptionClass ^> ^> ^DialogueOptionClassPtrDynamicVectorClass::CreateDialogueOptionClassPtrDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IDialogueOptionClass ^> ^>(gcnew DialogueOptionClassPtrDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<IDialogueOptionClass ^> ^> ^DialogueOptionClassPtrDynamicVectorClass::CreateDialogueOptionClassPtrDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IDialogueOptionClass ^> ^>(gcnew DialogueOptionClassPtrDynamicVectorClass(size));
	}

	bool DialogueOptionClassPtrDynamicVectorClass::Resize(int newSize)
	{
		return InternalDialogueOptionClassPtrDynamicVectorClassPointer->Resize(newSize);
	}

	void DialogueOptionClassPtrDynamicVectorClass::Clear()
	{
		InternalDialogueOptionClassPtrDynamicVectorClassPointer->Clear();
	}

	int DialogueOptionClassPtrDynamicVectorClass::ID(IDialogueOptionClass ^object)
	{
		if (object == nullptr || object->DialogueOptionClassPointer.ToPointer() == nullptr)
		{
			return InternalDialogueOptionClassPtrDynamicVectorClassPointer->ID(static_cast<::DialogueOptionClass *>(nullptr));
		}
		else
		{
			return InternalDialogueOptionClassPtrDynamicVectorClassPointer->ID(reinterpret_cast<::DialogueOptionClass *>(object->DialogueOptionClassPointer.ToPointer()));
		}
	}

	void DialogueOptionClassPtrDynamicVectorClass::Insert(int index, IDialogueOptionClass ^object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (object == nullptr || object->DialogueOptionClassPointer.ToPointer() == nullptr)
		{
			InternalDialogueOptionClassPtrDynamicVectorClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalDialogueOptionClassPtrDynamicVectorClassPointer->Insert(index, reinterpret_cast<::DialogueOptionClass *>(object->DialogueOptionClassPointer.ToPointer()));
		}
	}

	bool DialogueOptionClassPtrDynamicVectorClass::Add(IDialogueOptionClass ^object)
	{
		if (object == nullptr || object->DialogueOptionClassPointer.ToPointer() == nullptr)
		{
			return InternalDialogueOptionClassPtrDynamicVectorClassPointer->Add(nullptr);
		}
		else
		{
			return InternalDialogueOptionClassPtrDynamicVectorClassPointer->Add(reinterpret_cast<::DialogueOptionClass *>(object->DialogueOptionClassPointer.ToPointer()));
		}
	}

	void DialogueOptionClassPtrDynamicVectorClass::ResetActive()
	{
		InternalDialogueOptionClassPtrDynamicVectorClassPointer->Reset_Active();
	}

	bool DialogueOptionClassPtrDynamicVectorClass::AddHead(IDialogueOptionClass ^object)
	{
		if (object == nullptr || object->DialogueOptionClassPointer.ToPointer() == nullptr)
		{
			return InternalDialogueOptionClassPtrDynamicVectorClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalDialogueOptionClassPtrDynamicVectorClassPointer->Add_Head(reinterpret_cast<::DialogueOptionClass *>(object->DialogueOptionClassPointer.ToPointer()));
		}
	}

	bool DialogueOptionClassPtrDynamicVectorClass::DeleteObj(IDialogueOptionClass ^object)
	{
		if (object == nullptr || object->DialogueOptionClassPointer.ToPointer() == nullptr)
		{
			return InternalDialogueOptionClassPtrDynamicVectorClassPointer->DeleteObj(nullptr);
		}
		else
		{
			return InternalDialogueOptionClassPtrDynamicVectorClassPointer->DeleteObj(reinterpret_cast<::DialogueOptionClass *>(object->DialogueOptionClassPointer.ToPointer()));
		}
	}

	bool DialogueOptionClassPtrDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalDialogueOptionClassPtrDynamicVectorClassPointer->Delete(index);
	}

	void DialogueOptionClassPtrDynamicVectorClass::DeleteAll()
	{
		InternalDialogueOptionClassPtrDynamicVectorClassPointer->Delete_All();
	}

	int DialogueOptionClassPtrDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalDialogueOptionClassPtrDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void DialogueOptionClassPtrDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalDialogueOptionClassPtrDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr DialogueOptionClassPtrDynamicVectorClass::DialogueOptionClassPtrDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalDialogueOptionClassPtrDynamicVectorClassPointer);
	}

	IDialogueOptionClass ^DialogueOptionClassPtrDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalDialogueOptionClassPtrDynamicVectorClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DialogueOptionClass(IntPtr(result));
		}
	}

	void DialogueOptionClassPtrDynamicVectorClass::default::set(int index, IDialogueOptionClass ^value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->DialogueOptionClassPointer.ToPointer() == nullptr)
		{
			InternalDialogueOptionClassPtrDynamicVectorClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalDialogueOptionClassPtrDynamicVectorClassPointer->operator[](index) = reinterpret_cast<::DialogueOptionClass *>(value->DialogueOptionClassPointer.ToPointer());
		}
	}

	int DialogueOptionClassPtrDynamicVectorClass::Length::get()
	{
		return InternalDialogueOptionClassPtrDynamicVectorClassPointer->Length();
	}

	int DialogueOptionClassPtrDynamicVectorClass::Count::get()
	{
		return InternalDialogueOptionClassPtrDynamicVectorClassPointer->Count();
	}

	void DialogueOptionClassPtrDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalDialogueOptionClassPtrDynamicVectorClassPointer->Set_Active(value);
	}

	int DialogueOptionClassPtrDynamicVectorClass::GrowthStep::get()
	{
		return InternalDialogueOptionClassPtrDynamicVectorClassPointer->Growth_Step();
	}

	void DialogueOptionClassPtrDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalDialogueOptionClassPtrDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool DialogueOptionClassPtrDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyDialogueOptionClassPtrDynamicVectorClass(InternalDialogueOptionClassPtrDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::DialogueOptionClass *> *DialogueOptionClassPtrDynamicVectorClass::InternalDialogueOptionClassPtrDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::DialogueOptionClass *> *>(Pointer.ToPointer());
	}

	IntPtr DialogueOptionClassPtrDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DialogueOptionClass *> *>(InternalDialogueOptionClassPtrDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void DialogueOptionClassPtrDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DialogueOptionClass *> *>(InternalDialogueOptionClassPtrDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::DialogueOptionClass **>(value.ToPointer()));
	}

	int DialogueOptionClassPtrDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DialogueOptionClass *> *>(InternalDialogueOptionClassPtrDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void DialogueOptionClassPtrDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DialogueOptionClass *> *>(InternalDialogueOptionClassPtrDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool DialogueOptionClassPtrDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DialogueOptionClass *> *>(InternalDialogueOptionClassPtrDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void DialogueOptionClassPtrDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DialogueOptionClass *> *>(InternalDialogueOptionClassPtrDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool DialogueOptionClassPtrDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DialogueOptionClass *> *>(InternalDialogueOptionClassPtrDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void DialogueOptionClassPtrDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DialogueOptionClass *> *>(InternalDialogueOptionClassPtrDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int DialogueOptionClassPtrDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DialogueOptionClass *> *>(InternalDialogueOptionClassPtrDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void DialogueOptionClassPtrDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::DialogueOptionClass *> *>(InternalDialogueOptionClassPtrDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}