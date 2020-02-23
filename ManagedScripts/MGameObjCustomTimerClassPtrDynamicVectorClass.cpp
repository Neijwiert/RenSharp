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
#include "MGameObjCustomTimerClassPtrDynamicVectorClass.h"

#include "Imports.h"

namespace RenSharp
{
	GameObjCustomTimerClassPtrDynamicVectorClass::GameObjCustomTimerClassPtrDynamicVectorClass()
		: DynamicVectorClass<IntPtr>(IntPtr(Imports::CreateGameObjCustomTimerClassPtrDynamicVectorClass1()))
	{

	}

	GameObjCustomTimerClassPtrDynamicVectorClass::GameObjCustomTimerClassPtrDynamicVectorClass(int size)
		: DynamicVectorClass<IntPtr>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateGameObjCustomTimerClassPtrDynamicVectorClass2(size));
	}

	GameObjCustomTimerClassPtrDynamicVectorClass::GameObjCustomTimerClassPtrDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<IntPtr>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<IntPtr> ^> ^GameObjCustomTimerClassPtrDynamicVectorClass::CreateGameObjCustomTimerClassPtrDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IntPtr> ^>(gcnew GameObjCustomTimerClassPtrDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<IntPtr> ^> ^GameObjCustomTimerClassPtrDynamicVectorClass::CreateGameObjCustomTimerClassPtrDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IntPtr> ^>(gcnew GameObjCustomTimerClassPtrDynamicVectorClass(size));
	}

	bool GameObjCustomTimerClassPtrDynamicVectorClass::Resize(int newSize)
	{
		return InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer->Resize(newSize);
	}

	void GameObjCustomTimerClassPtrDynamicVectorClass::Clear()
	{
		InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer->Clear();
	}

	int GameObjCustomTimerClassPtrDynamicVectorClass::ID(IntPtr object)
	{
		if (object.ToPointer() == nullptr)
		{
			return InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer->ID(static_cast<::GameObjCustomTimerClass *>(nullptr));
		}
		else
		{
			return InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer->ID(reinterpret_cast<::GameObjCustomTimerClass *>(object.ToPointer()));
		}
	}

	void GameObjCustomTimerClassPtrDynamicVectorClass::Insert(int index, IntPtr object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (object.ToPointer() == nullptr)
		{
			InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer->Insert(index, reinterpret_cast<::GameObjCustomTimerClass *>(object.ToPointer()));
		}
	}

	bool GameObjCustomTimerClassPtrDynamicVectorClass::Add(IntPtr object)
	{
		if (object.ToPointer() == nullptr)
		{
			return InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer->Add(nullptr);
		}
		else
		{
			return InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer->Add(reinterpret_cast<::GameObjCustomTimerClass *>(object.ToPointer()));
		}
	}

	void GameObjCustomTimerClassPtrDynamicVectorClass::ResetActive()
	{
		InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer->Reset_Active();
	}

	bool GameObjCustomTimerClassPtrDynamicVectorClass::AddHead(IntPtr object)
	{
		if (object.ToPointer() == nullptr)
		{
			return InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer->Add_Head(reinterpret_cast<::GameObjCustomTimerClass *>(object.ToPointer()));
		}
	}

	bool GameObjCustomTimerClassPtrDynamicVectorClass::DeleteObj(IntPtr object)
	{
		if (object.ToPointer() == nullptr)
		{
			return InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer->DeleteObj(nullptr);
		}
		else
		{
			return InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer->DeleteObj(reinterpret_cast<::GameObjCustomTimerClass *>(object.ToPointer()));
		}
	}

	bool GameObjCustomTimerClassPtrDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer->Delete(index);
	}

	void GameObjCustomTimerClassPtrDynamicVectorClass::DeleteAll()
	{
		InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer->Delete_All();
	}

	int GameObjCustomTimerClassPtrDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void GameObjCustomTimerClassPtrDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr GameObjCustomTimerClassPtrDynamicVectorClass::GameObjCustomTimerClassPtrDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer);
	}

	IntPtr GameObjCustomTimerClassPtrDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer->operator[](index);

		return IntPtr(result);
	}

	void GameObjCustomTimerClassPtrDynamicVectorClass::default::set(int index, IntPtr value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value.ToPointer() == nullptr)
		{
			InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer->operator[](index) = reinterpret_cast<::GameObjCustomTimerClass *>(value.ToPointer());
		}
	}

	int GameObjCustomTimerClassPtrDynamicVectorClass::Length::get()
	{
		return InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer->Length();
	}

	int GameObjCustomTimerClassPtrDynamicVectorClass::Count::get()
	{
		return InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer->Count();
	}

	void GameObjCustomTimerClassPtrDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer->Set_Active(value);
	}

	int GameObjCustomTimerClassPtrDynamicVectorClass::GrowthStep::get()
	{
		return InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer->Growth_Step();
	}

	void GameObjCustomTimerClassPtrDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool GameObjCustomTimerClassPtrDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyGameObjCustomTimerClassPtrDynamicVectorClass(InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::GameObjCustomTimerClass *> *GameObjCustomTimerClassPtrDynamicVectorClass::InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::GameObjCustomTimerClass *> *>(Pointer.ToPointer());
	}

	IntPtr GameObjCustomTimerClassPtrDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::GameObjCustomTimerClass *> *>(InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void GameObjCustomTimerClassPtrDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::GameObjCustomTimerClass *> *>(InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::GameObjCustomTimerClass **>(value.ToPointer()));
	}

	int GameObjCustomTimerClassPtrDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::GameObjCustomTimerClass *> *>(InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void GameObjCustomTimerClassPtrDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::GameObjCustomTimerClass *> *>(InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool GameObjCustomTimerClassPtrDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::GameObjCustomTimerClass *> *>(InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void GameObjCustomTimerClassPtrDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::GameObjCustomTimerClass *> *>(InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool GameObjCustomTimerClassPtrDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::GameObjCustomTimerClass *> *>(InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void GameObjCustomTimerClassPtrDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::GameObjCustomTimerClass *> *>(InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int GameObjCustomTimerClassPtrDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::GameObjCustomTimerClass *> *>(InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void GameObjCustomTimerClassPtrDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::GameObjCustomTimerClass *> *>(InternalGameObjCustomTimerClassPtrDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}