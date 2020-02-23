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
#include "MGameObjObserverClassPtrSimpleDynVecClass.h"

#include "Mscripts.h"
#include "Imports.h"

namespace RenSharp
{
	GameObjObserverClassPtrSimpleDynVecClass::GameObjObserverClassPtrSimpleDynVecClass()
		: SimpleDynVecClass<IGameObjObserverClass ^>(IntPtr(Imports::CreateGameObjObserverClassPtrSimpleDynVecClass1()))
	{

	}

	GameObjObserverClassPtrSimpleDynVecClass::GameObjObserverClassPtrSimpleDynVecClass(int size)
		: SimpleDynVecClass<IGameObjObserverClass ^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateGameObjObserverClassPtrSimpleDynVecClass2(size));
	}

	GameObjObserverClassPtrSimpleDynVecClass::GameObjObserverClassPtrSimpleDynVecClass(IntPtr pointer)
		: SimpleDynVecClass<IGameObjObserverClass ^>(pointer)
	{

	}

	IUnmanagedContainer<ISimpleDynVecClass<IGameObjObserverClass ^> ^> ^GameObjObserverClassPtrSimpleDynVecClass::CreateGameObjObserverClassPtrSimpleDynVecClass()
	{
		return gcnew UnmanagedContainer<ISimpleDynVecClass<IGameObjObserverClass ^> ^>(gcnew GameObjObserverClassPtrSimpleDynVecClass());
	}

	IUnmanagedContainer<ISimpleDynVecClass<IGameObjObserverClass ^> ^> ^GameObjObserverClassPtrSimpleDynVecClass::CreateGameObjObserverClassPtrSimpleDynVecClass(int size)
	{
		return gcnew UnmanagedContainer<ISimpleDynVecClass<IGameObjObserverClass ^> ^>(gcnew GameObjObserverClassPtrSimpleDynVecClass(size));
	}

	bool GameObjObserverClassPtrSimpleDynVecClass::Resize(int newSize)
	{
		if (newSize < 0)
		{
			throw gcnew ArgumentOutOfRangeException("newSize");
		}

		return InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Resize(newSize);
	}

	bool GameObjObserverClassPtrSimpleDynVecClass::UninitialisedGrow(int newSize)
	{
		if (newSize < 0)
		{
			throw gcnew ArgumentOutOfRangeException("newSize");
		}

		return InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Uninitialised_Grow(newSize);
	}

	void GameObjObserverClassPtrSimpleDynVecClass::UninitializedResize(int newSize)
	{
		if (newSize < 0)
		{
			throw gcnew ArgumentOutOfRangeException("newSize");
		}

		InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Uninitialized_Resize(newSize);
	}

	IntPtr GameObjObserverClassPtrSimpleDynVecClass::Peek()
	{
		return IntPtr(const_cast<::GameObjObserverClass **>(InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Peek()));
	}

#pragma push_macro("ZeroMemory")
#undef ZeroMemory

	void GameObjObserverClassPtrSimpleDynVecClass::ZeroMemory()

#pragma pop_macro("ZeroMemory")
	{
		InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Zero_Memory();
	}

	int GameObjObserverClassPtrSimpleDynVecClass::FindIndex(IGameObjObserverClass ^object)
	{
		if (object == nullptr || object->GameObjObserverClassPointer.ToPointer() == nullptr)
		{
			return InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Find_Index(nullptr);
		}
		else
		{
			return InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Find_Index(reinterpret_cast<::GameObjObserverClass *>(object->GameObjObserverClassPointer.ToPointer()));
		}
	}

	bool GameObjObserverClassPtrSimpleDynVecClass::Add(IGameObjObserverClass ^data, int newSizeHint)
	{
		if (newSizeHint < 0)
		{
			throw gcnew ArgumentOutOfRangeException("newSizeHint");
		}

		if (data == nullptr || data->GameObjObserverClassPointer.ToPointer() == nullptr)
		{
			return InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Add(nullptr, newSizeHint);
		}
		else
		{
			return InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Add(reinterpret_cast<::GameObjObserverClass *>(data->GameObjObserverClassPointer.ToPointer()), newSizeHint);
		}
	}

	bool GameObjObserverClassPtrSimpleDynVecClass::Add(IGameObjObserverClass ^data)
	{
		if (data == nullptr || data->GameObjObserverClassPointer.ToPointer() == nullptr)
		{
			return InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Add(nullptr);
		}
		else
		{
			return InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Add(reinterpret_cast<::GameObjObserverClass *>(data->GameObjObserverClassPointer.ToPointer()));
		}
	}

	int GameObjObserverClassPtrSimpleDynVecClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		int index = Count;

		InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Add_Multiple(numberToAdd);

		return index;
	}

	bool GameObjObserverClassPtrSimpleDynVecClass::AddHead(IGameObjObserverClass ^object)
	{
		if (object == nullptr || object->GameObjObserverClassPointer.ToPointer() == nullptr)
		{
			return InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Add_Head(reinterpret_cast<::GameObjObserverClass *>(object->GameObjObserverClassPointer.ToPointer()));
		}
	}

	void GameObjObserverClassPtrSimpleDynVecClass::Insert(int index, IGameObjObserverClass ^item)
	{
		if (index < 0 || index > Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (item == nullptr || item->GameObjObserverClassPointer.ToPointer() == nullptr)
		{
			InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Insert(index, reinterpret_cast<::GameObjObserverClass *>(item->GameObjObserverClassPointer.ToPointer()));
		}
	}

	bool GameObjObserverClassPtrSimpleDynVecClass::DeleteIndex(int index, bool allowShrink)
	{
		if (index < 0 || index > Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Delete(index, allowShrink);
	}

	bool GameObjObserverClassPtrSimpleDynVecClass::DeleteIndex(int index)
	{
		if (index < 0 || index > Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Delete(index);
	}

	bool GameObjObserverClassPtrSimpleDynVecClass::DeleteObject(IGameObjObserverClass ^object, bool allowShrink)
	{
		if (object == nullptr || object->GameObjObserverClassPointer.ToPointer() == nullptr)
		{
			return InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Delete(nullptr, allowShrink);
		}
		else
		{
			return InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Delete(reinterpret_cast<::GameObjObserverClass *>(object->GameObjObserverClassPointer.ToPointer()));
		}
	}

	bool GameObjObserverClassPtrSimpleDynVecClass::DeleteObject(IGameObjObserverClass ^object)
	{
		if (object == nullptr || object->GameObjObserverClassPointer.ToPointer() == nullptr)
		{
			return InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Delete(nullptr);
		}
		else
		{
			return InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Delete(reinterpret_cast<::GameObjObserverClass *>(object->GameObjObserverClassPointer.ToPointer()));
		}
	}

	bool GameObjObserverClassPtrSimpleDynVecClass::DeleteRange(int start, int count, bool allowShrink)
	{
		if (start < 0 || start > Count)
		{
			throw gcnew ArgumentOutOfRangeException("start");
		}
		else if (start + count > Count)
		{
			throw gcnew ArgumentOutOfRangeException("count");
		}

		return InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Delete_Range(start, count, allowShrink);
	}

	bool GameObjObserverClassPtrSimpleDynVecClass::DeleteRange(int start, int count)
	{
		if (start < 0 || start > Count)
		{
			throw gcnew ArgumentOutOfRangeException("start");
		}
		else if (start + count > Count)
		{
			throw gcnew ArgumentOutOfRangeException("count");
		}

		return InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Delete_Range(start, count);
	}

	void GameObjObserverClassPtrSimpleDynVecClass::DeleteAll(bool allowShrink)
	{
		InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Delete_All(allowShrink);
	}

	void GameObjObserverClassPtrSimpleDynVecClass::DeleteAll()
	{
		InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Delete_All();
	}

	IntPtr GameObjObserverClassPtrSimpleDynVecClass::GameObjObserverClassPtrSimpleDynVecClassPointer::get()
	{
		return IntPtr(InternalGameObjObserverClassPtrSimpleDynVecClassPointer);
	}

	int GameObjObserverClassPtrSimpleDynVecClass::Length::get()
	{
		return InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Length();
	}

	IGameObjObserverClass ^GameObjObserverClassPtrSimpleDynVecClass::default::get(int index)
	{
		if (index < 0 || index > Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalGameObjObserverClassPtrSimpleDynVecClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew GameObjObserverClass(IntPtr(result));
		}
	}

	void GameObjObserverClassPtrSimpleDynVecClass::default::set(int index, IGameObjObserverClass ^value)
	{
		if (index < 0 || index > Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->GameObjObserverClassPointer.ToPointer() == nullptr)
		{
			InternalGameObjObserverClassPtrSimpleDynVecClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalGameObjObserverClassPtrSimpleDynVecClassPointer->operator[](index) = reinterpret_cast<::GameObjObserverClass *>(value->GameObjObserverClassPointer.ToPointer());
		}
	}

	bool GameObjObserverClassPtrSimpleDynVecClass::IsEmpty::get()
	{
		return InternalGameObjObserverClassPtrSimpleDynVecClassPointer->isEmpty();
	}

	int GameObjObserverClassPtrSimpleDynVecClass::Count::get()
	{
		return InternalGameObjObserverClassPtrSimpleDynVecClassPointer->Count();
	}

	bool GameObjObserverClassPtrSimpleDynVecClass::InternalDestroyPointer()
	{
		Imports::DestroyGameObjObserverClassPtrSimpleDynVecClass(InternalGameObjObserverClassPtrSimpleDynVecClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	bool GameObjObserverClassPtrSimpleDynVecClass::Grow(int newSizeHint)
	{
		if (newSizeHint < 0)
		{
			throw gcnew ArgumentOutOfRangeException("newSizeHint");
		}

		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::GameObjObserverClass *> *>(InternalGameObjObserverClassPtrSimpleDynVecClassPointer);

		return helper->Grow(newSizeHint);
	}

	bool GameObjObserverClassPtrSimpleDynVecClass::Shrink()
	{
		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::GameObjObserverClass *> *>(InternalGameObjObserverClassPtrSimpleDynVecClassPointer);

		return helper->Shrink();
	}

	::SimpleDynVecClass<::GameObjObserverClass *> *GameObjObserverClassPtrSimpleDynVecClass::InternalGameObjObserverClassPtrSimpleDynVecClassPointer::get()
	{
		return reinterpret_cast<::SimpleDynVecClass<::GameObjObserverClass *> *>(Pointer.ToPointer());
	}

	IntPtr GameObjObserverClassPtrSimpleDynVecClass::Vector::get()
	{
		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::GameObjObserverClass *> *>(InternalGameObjObserverClassPtrSimpleDynVecClassPointer);

		return IntPtr(helper->GetVector());
	}

	void GameObjObserverClassPtrSimpleDynVecClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::GameObjObserverClass *> *>(InternalGameObjObserverClassPtrSimpleDynVecClassPointer);

		helper->SetVector(reinterpret_cast<::GameObjObserverClass * *>(value.ToPointer()));
	}

	int GameObjObserverClassPtrSimpleDynVecClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::GameObjObserverClass *> *>(InternalGameObjObserverClassPtrSimpleDynVecClassPointer);

		return helper->GetVectorMax();
	}

	void GameObjObserverClassPtrSimpleDynVecClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::GameObjObserverClass *> *>(InternalGameObjObserverClassPtrSimpleDynVecClassPointer);

		helper->SetVectorMax(value);
	}

	int GameObjObserverClassPtrSimpleDynVecClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::GameObjObserverClass *> *>(InternalGameObjObserverClassPtrSimpleDynVecClassPointer);

		return helper->GetActiveCount();
	}

	void GameObjObserverClassPtrSimpleDynVecClass::ActiveCount::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::GameObjObserverClass *> *>(InternalGameObjObserverClassPtrSimpleDynVecClassPointer);

		helper->SetActiveCount(value);
	}
}