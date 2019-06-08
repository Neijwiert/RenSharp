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
#include "MSoundSceneObjClassPtrDynamicVectorClass.h"

#include "MSoundSceneObjClass.h"
#include "Imports.h"

namespace RenSharp
{
	SoundSceneObjClassPtrDynamicVectorClass::SoundSceneObjClassPtrDynamicVectorClass()
		: DynamicVectorClass<ISoundSceneObjClass ^>(IntPtr(Imports::CreateSoundSceneObjClassPtrDynamicVectorClass1()))
	{

	}

	SoundSceneObjClassPtrDynamicVectorClass::SoundSceneObjClassPtrDynamicVectorClass(int size)
		: DynamicVectorClass<ISoundSceneObjClass ^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateSoundSceneObjClassPtrDynamicVectorClass2(size));
	}

	SoundSceneObjClassPtrDynamicVectorClass::SoundSceneObjClassPtrDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<ISoundSceneObjClass ^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<ISoundSceneObjClass ^> ^> ^SoundSceneObjClassPtrDynamicVectorClass::CreateSoundSceneObjClassPtrDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<ISoundSceneObjClass ^> ^>(gcnew SoundSceneObjClassPtrDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<ISoundSceneObjClass ^> ^> ^SoundSceneObjClassPtrDynamicVectorClass::CreateSoundSceneObjClassPtrDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<ISoundSceneObjClass ^> ^>(gcnew SoundSceneObjClassPtrDynamicVectorClass(size));
	}

	bool SoundSceneObjClassPtrDynamicVectorClass::Resize(int newSize)
	{
		return InternalSoundSceneObjClassPtrDynamicVectorClassPointer->Resize(newSize);
	}

	void SoundSceneObjClassPtrDynamicVectorClass::Clear()
	{
		InternalSoundSceneObjClassPtrDynamicVectorClassPointer->Clear();
	}

	int SoundSceneObjClassPtrDynamicVectorClass::ID(ISoundSceneObjClass ^object)
	{
		if (object == nullptr || object->SoundSceneObjClassPointer.ToPointer() == nullptr)
		{
			return InternalSoundSceneObjClassPtrDynamicVectorClassPointer->ID(static_cast<::SoundSceneObjClass *>(nullptr));
		}
		else
		{
			return InternalSoundSceneObjClassPtrDynamicVectorClassPointer->ID(reinterpret_cast<::SoundSceneObjClass *>(object->SoundSceneObjClassPointer.ToPointer()));
		}
	}

	void SoundSceneObjClassPtrDynamicVectorClass::Insert(int index, ISoundSceneObjClass ^object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (object == nullptr || object->SoundSceneObjClassPointer.ToPointer() == nullptr)
		{
			InternalSoundSceneObjClassPtrDynamicVectorClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalSoundSceneObjClassPtrDynamicVectorClassPointer->Insert(index, reinterpret_cast<::SoundSceneObjClass *>(object->SoundSceneObjClassPointer.ToPointer()));
		}
	}

	bool SoundSceneObjClassPtrDynamicVectorClass::Add(ISoundSceneObjClass ^object)
	{
		if (object == nullptr || object->SoundSceneObjClassPointer.ToPointer() == nullptr)
		{
			return InternalSoundSceneObjClassPtrDynamicVectorClassPointer->Add(nullptr);
		}
		else
		{
			return InternalSoundSceneObjClassPtrDynamicVectorClassPointer->Add(reinterpret_cast<::SoundSceneObjClass *>(object->SoundSceneObjClassPointer.ToPointer()));
		}
	}

	void SoundSceneObjClassPtrDynamicVectorClass::ResetActive()
	{
		InternalSoundSceneObjClassPtrDynamicVectorClassPointer->Reset_Active();
	}

	bool SoundSceneObjClassPtrDynamicVectorClass::AddHead(ISoundSceneObjClass ^object)
	{
		if (object == nullptr || object->SoundSceneObjClassPointer.ToPointer() == nullptr)
		{
			return InternalSoundSceneObjClassPtrDynamicVectorClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalSoundSceneObjClassPtrDynamicVectorClassPointer->Add_Head(reinterpret_cast<::SoundSceneObjClass *>(object->SoundSceneObjClassPointer.ToPointer()));
		}
	}

	bool SoundSceneObjClassPtrDynamicVectorClass::DeleteObj(ISoundSceneObjClass ^object)
	{
		if (object == nullptr || object->SoundSceneObjClassPointer.ToPointer() == nullptr)
		{
			return InternalSoundSceneObjClassPtrDynamicVectorClassPointer->DeleteObj(nullptr);
		}
		else
		{
			return InternalSoundSceneObjClassPtrDynamicVectorClassPointer->DeleteObj(reinterpret_cast<::SoundSceneObjClass *>(object->SoundSceneObjClassPointer.ToPointer()));
		}
	}

	bool SoundSceneObjClassPtrDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalSoundSceneObjClassPtrDynamicVectorClassPointer->Delete(index);
	}

	void SoundSceneObjClassPtrDynamicVectorClass::DeleteAll()
	{
		InternalSoundSceneObjClassPtrDynamicVectorClassPointer->Delete_All();
	}

	int SoundSceneObjClassPtrDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalSoundSceneObjClassPtrDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void SoundSceneObjClassPtrDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalSoundSceneObjClassPtrDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr SoundSceneObjClassPtrDynamicVectorClass::SoundSceneObjClassPtrDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalSoundSceneObjClassPtrDynamicVectorClassPointer);
	}

	ISoundSceneObjClass ^SoundSceneObjClassPtrDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalSoundSceneObjClassPtrDynamicVectorClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SoundSceneObjClass(IntPtr(result));
		}
	}

	void SoundSceneObjClassPtrDynamicVectorClass::default::set(int index, ISoundSceneObjClass ^value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->SoundSceneObjClassPointer.ToPointer() == nullptr)
		{
			InternalSoundSceneObjClassPtrDynamicVectorClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalSoundSceneObjClassPtrDynamicVectorClassPointer->operator[](index) = reinterpret_cast<::SoundSceneObjClass *>(value->SoundSceneObjClassPointer.ToPointer());
		}
	}

	int SoundSceneObjClassPtrDynamicVectorClass::Length::get()
	{
		return InternalSoundSceneObjClassPtrDynamicVectorClassPointer->Length();
	}

	int SoundSceneObjClassPtrDynamicVectorClass::Count::get()
	{
		return InternalSoundSceneObjClassPtrDynamicVectorClassPointer->Count();
	}

	void SoundSceneObjClassPtrDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalSoundSceneObjClassPtrDynamicVectorClassPointer->Set_Active(value);
	}

	int SoundSceneObjClassPtrDynamicVectorClass::GrowthStep::get()
	{
		return InternalSoundSceneObjClassPtrDynamicVectorClassPointer->Growth_Step();
	}

	void SoundSceneObjClassPtrDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalSoundSceneObjClassPtrDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool SoundSceneObjClassPtrDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroySoundSceneObjClassPtrDynamicVectorClass(InternalSoundSceneObjClassPtrDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::SoundSceneObjClass *> *SoundSceneObjClassPtrDynamicVectorClass::InternalSoundSceneObjClassPtrDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::SoundSceneObjClass *> *>(Pointer.ToPointer());
	}

	IntPtr SoundSceneObjClassPtrDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::SoundSceneObjClass *> *>(InternalSoundSceneObjClassPtrDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void SoundSceneObjClassPtrDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::SoundSceneObjClass *> *>(InternalSoundSceneObjClassPtrDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::SoundSceneObjClass **>(value.ToPointer()));
	}

	int SoundSceneObjClassPtrDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::SoundSceneObjClass *> *>(InternalSoundSceneObjClassPtrDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void SoundSceneObjClassPtrDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::SoundSceneObjClass *> *>(InternalSoundSceneObjClassPtrDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool SoundSceneObjClassPtrDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::SoundSceneObjClass *> *>(InternalSoundSceneObjClassPtrDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void SoundSceneObjClassPtrDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::SoundSceneObjClass *> *>(InternalSoundSceneObjClassPtrDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool SoundSceneObjClassPtrDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::SoundSceneObjClass *> *>(InternalSoundSceneObjClassPtrDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void SoundSceneObjClassPtrDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::SoundSceneObjClass *> *>(InternalSoundSceneObjClassPtrDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int SoundSceneObjClassPtrDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::SoundSceneObjClass *> *>(InternalSoundSceneObjClassPtrDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void SoundSceneObjClassPtrDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::SoundSceneObjClass *> *>(InternalSoundSceneObjClassPtrDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}