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
#include "MGameObjObserverTimerClassPtrDynamicVectorClass.h"

#include "Imports.h"

namespace RenSharp
{
	GameObjObserverTimerClassPtrDynamicVectorClass::GameObjObserverTimerClassPtrDynamicVectorClass()
		: DynamicVectorClass<IntPtr>(IntPtr(Imports::CreateGameObjObserverTimerClassPtrDynamicVectorClass1()))
	{

	}

	GameObjObserverTimerClassPtrDynamicVectorClass::GameObjObserverTimerClassPtrDynamicVectorClass(int size)
		: DynamicVectorClass<IntPtr>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateGameObjObserverTimerClassPtrDynamicVectorClass2(size));
	}

	GameObjObserverTimerClassPtrDynamicVectorClass::GameObjObserverTimerClassPtrDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<IntPtr>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<IntPtr> ^> ^GameObjObserverTimerClassPtrDynamicVectorClass::CreateGameObjObserverTimerClassPtrDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IntPtr> ^>(gcnew GameObjObserverTimerClassPtrDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<IntPtr> ^> ^GameObjObserverTimerClassPtrDynamicVectorClass::CreateGameObjObserverTimerClassPtrDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IntPtr> ^>(gcnew GameObjObserverTimerClassPtrDynamicVectorClass(size));
	}

	bool GameObjObserverTimerClassPtrDynamicVectorClass::Resize(int newSize)
	{
		return InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer->Resize(newSize);
	}

	void GameObjObserverTimerClassPtrDynamicVectorClass::Clear()
	{
		InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer->Clear();
	}

	int GameObjObserverTimerClassPtrDynamicVectorClass::ID(IntPtr object)
	{
		if (object.ToPointer() == nullptr)
		{
			return InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer->ID(static_cast<::GameObjObserverTimerClass *>(nullptr));
		}
		else
		{
			return InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer->ID(reinterpret_cast<::GameObjObserverTimerClass *>(object.ToPointer()));
		}
	}

	void GameObjObserverTimerClassPtrDynamicVectorClass::Insert(int index, IntPtr object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (object.ToPointer() == nullptr)
		{
			InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer->Insert(index, reinterpret_cast<::GameObjObserverTimerClass *>(object.ToPointer()));
		}
	}

	bool GameObjObserverTimerClassPtrDynamicVectorClass::Add(IntPtr object)
	{
		if (object.ToPointer() == nullptr)
		{
			return InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer->Add(nullptr);
		}
		else
		{
			return InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer->Add(reinterpret_cast<::GameObjObserverTimerClass *>(object.ToPointer()));
		}
	}

	void GameObjObserverTimerClassPtrDynamicVectorClass::ResetActive()
	{
		InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer->Reset_Active();
	}

	bool GameObjObserverTimerClassPtrDynamicVectorClass::AddHead(IntPtr object)
	{
		if (object.ToPointer() == nullptr)
		{
			return InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer->Add_Head(reinterpret_cast<::GameObjObserverTimerClass *>(object.ToPointer()));
		}
	}

	bool GameObjObserverTimerClassPtrDynamicVectorClass::DeleteObj(IntPtr object)
	{
		if (object.ToPointer() == nullptr)
		{
			return InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer->DeleteObj(nullptr);
		}
		else
		{
			return InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer->DeleteObj(reinterpret_cast<::GameObjObserverTimerClass *>(object.ToPointer()));
		}
	}

	bool GameObjObserverTimerClassPtrDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer->Delete(index);
	}

	void GameObjObserverTimerClassPtrDynamicVectorClass::DeleteAll()
	{
		InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer->Delete_All();
	}

	int GameObjObserverTimerClassPtrDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void GameObjObserverTimerClassPtrDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr GameObjObserverTimerClassPtrDynamicVectorClass::GameObjObserverTimerClassPtrDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer);
	}

	IntPtr GameObjObserverTimerClassPtrDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer->operator[](index);
		
		return IntPtr(result);
	}

	void GameObjObserverTimerClassPtrDynamicVectorClass::default::set(int index, IntPtr value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value.ToPointer() == nullptr)
		{
			InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer->operator[](index) = reinterpret_cast<::GameObjObserverTimerClass *>(value.ToPointer());
		}
	}

	int GameObjObserverTimerClassPtrDynamicVectorClass::Length::get()
	{
		return InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer->Length();
	}

	int GameObjObserverTimerClassPtrDynamicVectorClass::Count::get()
	{
		return InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer->Count();
	}

	void GameObjObserverTimerClassPtrDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer->Set_Active(value);
	}

	int GameObjObserverTimerClassPtrDynamicVectorClass::GrowthStep::get()
	{
		return InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer->Growth_Step();
	}

	void GameObjObserverTimerClassPtrDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool GameObjObserverTimerClassPtrDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyGameObjObserverTimerClassPtrDynamicVectorClass(InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::GameObjObserverTimerClass *> *GameObjObserverTimerClassPtrDynamicVectorClass::InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::GameObjObserverTimerClass *> *>(Pointer.ToPointer());
	}

	IntPtr GameObjObserverTimerClassPtrDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::GameObjObserverTimerClass *> *>(InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void GameObjObserverTimerClassPtrDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::GameObjObserverTimerClass *> *>(InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::GameObjObserverTimerClass **>(value.ToPointer()));
	}

	int GameObjObserverTimerClassPtrDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::GameObjObserverTimerClass *> *>(InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void GameObjObserverTimerClassPtrDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::GameObjObserverTimerClass *> *>(InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool GameObjObserverTimerClassPtrDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::GameObjObserverTimerClass *> *>(InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void GameObjObserverTimerClassPtrDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::GameObjObserverTimerClass *> *>(InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool GameObjObserverTimerClassPtrDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::GameObjObserverTimerClass *> *>(InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void GameObjObserverTimerClassPtrDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::GameObjObserverTimerClass *> *>(InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int GameObjObserverTimerClassPtrDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::GameObjObserverTimerClass *> *>(InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void GameObjObserverTimerClassPtrDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::GameObjObserverTimerClass *> *>(InternalGameObjObserverTimerClassPtrDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}