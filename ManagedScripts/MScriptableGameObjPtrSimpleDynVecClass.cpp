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
#include "MScriptableGameObjPtrSimpleDynVecClass.h"

#include "MScriptableGameObj.h"
#include "Imports.h"

namespace RenSharp
{
	ScriptableGameObjPtrSimpleDynVecClass::ScriptableGameObjPtrSimpleDynVecClass()
		: SimpleDynVecClass<IScriptableGameObj ^>(IntPtr(Imports::CreateScriptableGameObjPtrSimpleDynVecClass1()))
	{

	}

	ScriptableGameObjPtrSimpleDynVecClass::ScriptableGameObjPtrSimpleDynVecClass(int size)
		: SimpleDynVecClass<IScriptableGameObj ^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateScriptableGameObjPtrSimpleDynVecClass2(size));
	}

	ScriptableGameObjPtrSimpleDynVecClass::ScriptableGameObjPtrSimpleDynVecClass(IntPtr pointer)
		: SimpleDynVecClass<IScriptableGameObj ^>(pointer)
	{

	}

	IUnmanagedContainer<ISimpleDynVecClass<IScriptableGameObj ^> ^> ^ScriptableGameObjPtrSimpleDynVecClass::CreateScriptableGameObjPtrSimpleDynVecClass()
	{
		return gcnew UnmanagedContainer<ISimpleDynVecClass<IScriptableGameObj ^> ^>(gcnew ScriptableGameObjPtrSimpleDynVecClass());
	}

	IUnmanagedContainer<ISimpleDynVecClass<IScriptableGameObj ^> ^> ^ScriptableGameObjPtrSimpleDynVecClass::CreateScriptableGameObjPtrSimpleDynVecClass(int size)
	{
		return gcnew UnmanagedContainer<ISimpleDynVecClass<IScriptableGameObj ^> ^>(gcnew ScriptableGameObjPtrSimpleDynVecClass(size));
	}

	bool ScriptableGameObjPtrSimpleDynVecClass::Resize(int newSize)
	{
		if (newSize < 0)
		{
			throw gcnew ArgumentOutOfRangeException("newSize");
		}

		return InternalScriptableGameObjPtrSimpleDynVecClassPointer->Resize(newSize);
	}

	bool ScriptableGameObjPtrSimpleDynVecClass::UninitialisedGrow(int newSize)
	{
		if (newSize < 0)
		{
			throw gcnew ArgumentOutOfRangeException("newSize");
		}

		return InternalScriptableGameObjPtrSimpleDynVecClassPointer->Uninitialised_Grow(newSize);
	}

	void ScriptableGameObjPtrSimpleDynVecClass::UninitializedResize(int newSize)
	{
		if (newSize < 0)
		{
			throw gcnew ArgumentOutOfRangeException("newSize");
		}

		InternalScriptableGameObjPtrSimpleDynVecClassPointer->Uninitialized_Resize(newSize);
	}

	IntPtr ScriptableGameObjPtrSimpleDynVecClass::Peek()
	{
		return IntPtr(const_cast<::ScriptableGameObj **>(InternalScriptableGameObjPtrSimpleDynVecClassPointer->Peek()));
	}

#pragma push_macro("ZeroMemory")
#undef ZeroMemory

	void ScriptableGameObjPtrSimpleDynVecClass::ZeroMemory()

#pragma pop_macro("ZeroMemory")
	{
		InternalScriptableGameObjPtrSimpleDynVecClassPointer->Zero_Memory();
	}

	int ScriptableGameObjPtrSimpleDynVecClass::FindIndex(IScriptableGameObj ^object)
	{
		if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			return InternalScriptableGameObjPtrSimpleDynVecClassPointer->Find_Index(nullptr);
		}
		else
		{
			return InternalScriptableGameObjPtrSimpleDynVecClassPointer->Find_Index(reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
		}
	}

	bool ScriptableGameObjPtrSimpleDynVecClass::Add(IScriptableGameObj ^data, int newSizeHint)
	{
		if (newSizeHint < 0)
		{
			throw gcnew ArgumentOutOfRangeException("newSizeHint");
		}

		if (data == nullptr || data->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			return InternalScriptableGameObjPtrSimpleDynVecClassPointer->Add(nullptr, newSizeHint);
		}
		else
		{
			return InternalScriptableGameObjPtrSimpleDynVecClassPointer->Add(reinterpret_cast<::ScriptableGameObj *>(data->ScriptableGameObjPointer.ToPointer()), newSizeHint);
		}
	}

	bool ScriptableGameObjPtrSimpleDynVecClass::Add(IScriptableGameObj ^data)
	{
		if (data == nullptr || data->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			return InternalScriptableGameObjPtrSimpleDynVecClassPointer->Add(nullptr);
		}
		else
		{
			return InternalScriptableGameObjPtrSimpleDynVecClassPointer->Add(reinterpret_cast<::ScriptableGameObj *>(data->ScriptableGameObjPointer.ToPointer()));
		}
	}

	int ScriptableGameObjPtrSimpleDynVecClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		int index = Count;

		InternalScriptableGameObjPtrSimpleDynVecClassPointer->Add_Multiple(numberToAdd);

		return index;
	}

	bool ScriptableGameObjPtrSimpleDynVecClass::AddHead(IScriptableGameObj ^object)
	{
		if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			return InternalScriptableGameObjPtrSimpleDynVecClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalScriptableGameObjPtrSimpleDynVecClassPointer->Add_Head(reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
		}
	}

	void ScriptableGameObjPtrSimpleDynVecClass::Insert(int index, IScriptableGameObj ^item)
	{
		if (index < 0 || index > Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (item == nullptr || item->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			InternalScriptableGameObjPtrSimpleDynVecClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalScriptableGameObjPtrSimpleDynVecClassPointer->Insert(index, reinterpret_cast<::ScriptableGameObj *>(item->ScriptableGameObjPointer.ToPointer()));
		}
	}

	bool ScriptableGameObjPtrSimpleDynVecClass::DeleteIndex(int index, bool allowShrink)
	{
		if (index < 0 || index > Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalScriptableGameObjPtrSimpleDynVecClassPointer->Delete(index, allowShrink);
	}

	bool ScriptableGameObjPtrSimpleDynVecClass::DeleteIndex(int index)
	{
		if (index < 0 || index > Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalScriptableGameObjPtrSimpleDynVecClassPointer->Delete(index);
	}

	bool ScriptableGameObjPtrSimpleDynVecClass::DeleteObject(IScriptableGameObj ^object, bool allowShrink)
	{
		if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			return InternalScriptableGameObjPtrSimpleDynVecClassPointer->Delete(nullptr, allowShrink);
		}
		else
		{
			return InternalScriptableGameObjPtrSimpleDynVecClassPointer->Delete(reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
		}
	}

	bool ScriptableGameObjPtrSimpleDynVecClass::DeleteObject(IScriptableGameObj ^object)
	{
		if (object == nullptr || object->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			return InternalScriptableGameObjPtrSimpleDynVecClassPointer->Delete(nullptr);
		}
		else
		{
			return InternalScriptableGameObjPtrSimpleDynVecClassPointer->Delete(reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer()));
		}
	}

	bool ScriptableGameObjPtrSimpleDynVecClass::DeleteRange(int start, int count, bool allowShrink)
	{
		if (start < 0 || start > Count)
		{
			throw gcnew ArgumentOutOfRangeException("start");
		}
		else if (start + count > Count)
		{
			throw gcnew ArgumentOutOfRangeException("count");
		}

		return InternalScriptableGameObjPtrSimpleDynVecClassPointer->Delete_Range(start, count, allowShrink);
	}

	bool ScriptableGameObjPtrSimpleDynVecClass::DeleteRange(int start, int count)
	{
		if (start < 0 || start > Count)
		{
			throw gcnew ArgumentOutOfRangeException("start");
		}
		else if (start + count > Count)
		{
			throw gcnew ArgumentOutOfRangeException("count");
		}

		return InternalScriptableGameObjPtrSimpleDynVecClassPointer->Delete_Range(start, count);
	}

	void ScriptableGameObjPtrSimpleDynVecClass::DeleteAll(bool allowShrink)
	{
		InternalScriptableGameObjPtrSimpleDynVecClassPointer->Delete_All(allowShrink);
	}

	void ScriptableGameObjPtrSimpleDynVecClass::DeleteAll()
	{
		InternalScriptableGameObjPtrSimpleDynVecClassPointer->Delete_All();
	}

	IntPtr ScriptableGameObjPtrSimpleDynVecClass::ScriptableGameObjPtrSimpleDynVecClassPointer::get()
	{
		return IntPtr(InternalScriptableGameObjPtrSimpleDynVecClassPointer);
	}

	int ScriptableGameObjPtrSimpleDynVecClass::Length::get()
	{
		return InternalScriptableGameObjPtrSimpleDynVecClassPointer->Length();
	}

	IScriptableGameObj ^ScriptableGameObjPtrSimpleDynVecClass::default::get(int index)
	{
		if (index < 0 || index > Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalScriptableGameObjPtrSimpleDynVecClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptableGameObj(IntPtr(result));
		}
	}

	void ScriptableGameObjPtrSimpleDynVecClass::default::set(int index, IScriptableGameObj ^value)
	{
		if (index < 0 || index > Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			InternalScriptableGameObjPtrSimpleDynVecClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalScriptableGameObjPtrSimpleDynVecClassPointer->operator[](index) = reinterpret_cast<::ScriptableGameObj *>(value->ScriptableGameObjPointer.ToPointer());
		}
	}

	bool ScriptableGameObjPtrSimpleDynVecClass::IsEmpty::get()
	{
		return InternalScriptableGameObjPtrSimpleDynVecClassPointer->isEmpty();
	}

	int ScriptableGameObjPtrSimpleDynVecClass::Count::get()
	{
		return InternalScriptableGameObjPtrSimpleDynVecClassPointer->Count();
	}

	bool ScriptableGameObjPtrSimpleDynVecClass::InternalDestroyPointer()
	{
		Imports::DestroyScriptableGameObjPtrSimpleDynVecClass(InternalScriptableGameObjPtrSimpleDynVecClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	bool ScriptableGameObjPtrSimpleDynVecClass::Grow(int newSizeHint)
	{
		if (newSizeHint < 0)
		{
			throw gcnew ArgumentOutOfRangeException("newSizeHint");
		}

		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::ScriptableGameObj *> *>(InternalScriptableGameObjPtrSimpleDynVecClassPointer);

		return helper->Grow(newSizeHint);
	}

	bool ScriptableGameObjPtrSimpleDynVecClass::Shrink()
	{
		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::ScriptableGameObj *> *>(InternalScriptableGameObjPtrSimpleDynVecClassPointer);

		return helper->Shrink();
	}

	::SimpleDynVecClass<::ScriptableGameObj *> *ScriptableGameObjPtrSimpleDynVecClass::InternalScriptableGameObjPtrSimpleDynVecClassPointer::get()
	{
		return reinterpret_cast<::SimpleDynVecClass<::ScriptableGameObj *> *>(Pointer.ToPointer());
	}

	IntPtr ScriptableGameObjPtrSimpleDynVecClass::Vector::get()
	{
		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::ScriptableGameObj *> *>(InternalScriptableGameObjPtrSimpleDynVecClassPointer);

		return IntPtr(helper->GetVector());
	}

	void ScriptableGameObjPtrSimpleDynVecClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::ScriptableGameObj *> *>(InternalScriptableGameObjPtrSimpleDynVecClassPointer);

		helper->SetVector(reinterpret_cast<::ScriptableGameObj * *>(value.ToPointer()));
	}

	int ScriptableGameObjPtrSimpleDynVecClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::ScriptableGameObj *> *>(InternalScriptableGameObjPtrSimpleDynVecClassPointer);

		return helper->GetVectorMax();
	}

	void ScriptableGameObjPtrSimpleDynVecClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::ScriptableGameObj *> *>(InternalScriptableGameObjPtrSimpleDynVecClassPointer);

		helper->SetVectorMax(value);
	}

	int ScriptableGameObjPtrSimpleDynVecClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::ScriptableGameObj *> *>(InternalScriptableGameObjPtrSimpleDynVecClassPointer);

		return helper->GetActiveCount();
	}

	void ScriptableGameObjPtrSimpleDynVecClass::ActiveCount::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<SimpleDynVecClassHelper<::ScriptableGameObj *> *>(InternalScriptableGameObjPtrSimpleDynVecClassPointer);

		helper->SetActiveCount(value);
	}
}