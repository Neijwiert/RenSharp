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
#include "MSoldierGameObjPtrVectorClass.h"

#include "Imports.h"
#include "UnmanagedContainer.h"
#include "MSoldierGameObj.h"

namespace RenSharp
{
	SoldierGameObjPtrVectorClass::SoldierGameObjPtrVectorClass()
		: VectorClass<ISoldierGameObj ^>(IntPtr(Imports::CreateSoldierGameObjPtrVectorClass1()))
	{

	}

	SoldierGameObjPtrVectorClass::SoldierGameObjPtrVectorClass(int size)
		: VectorClass<ISoldierGameObj ^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateSoldierGameObjPtrVectorClass2(size));
	}

	SoldierGameObjPtrVectorClass::SoldierGameObjPtrVectorClass(IntPtr pointer)
		: VectorClass<ISoldierGameObj ^>(pointer)
	{

	}

	IUnmanagedContainer<IVectorClass<ISoldierGameObj ^> ^> ^SoldierGameObjPtrVectorClass::CreateSoldierGameObjPtrVectorClass()
	{
		return gcnew UnmanagedContainer<IVectorClass<ISoldierGameObj ^> ^>(gcnew SoldierGameObjPtrVectorClass());
	}

	IUnmanagedContainer<IVectorClass<ISoldierGameObj ^> ^> ^SoldierGameObjPtrVectorClass::CreateSoldierGameObjPtrVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IVectorClass<ISoldierGameObj ^> ^>(gcnew SoldierGameObjPtrVectorClass(size));
	}

	bool SoldierGameObjPtrVectorClass::Resize(int newSize)
	{
		return InternalSoldierGameObjPtrVectorClassPointer->Resize(newSize);
	}

	void SoldierGameObjPtrVectorClass::Clear()
	{
		InternalSoldierGameObjPtrVectorClassPointer->Clear();
	}

	int SoldierGameObjPtrVectorClass::ID(ISoldierGameObj ^object)
	{
		if (object == nullptr || object->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			return InternalSoldierGameObjPtrVectorClassPointer->ID(static_cast<::SoldierGameObj *>(nullptr));
		}
		else
		{
			return InternalSoldierGameObjPtrVectorClassPointer->ID(reinterpret_cast<::SoldierGameObj *>(object->SoldierGameObjPointer.ToPointer()));
		}
	}

	IntPtr SoldierGameObjPtrVectorClass::SoldierGameObjPtrVectorClassPointer::get()
	{
		return IntPtr(InternalSoldierGameObjPtrVectorClassPointer);
	}

	ISoldierGameObj ^SoldierGameObjPtrVectorClass::default::get(int index)
	{
		if (index < 0 || index >= VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalSoldierGameObjPtrVectorClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return safe_cast<ISoldierGameObj^>(BaseGameObj::CreateBaseGameObjWrapper(result));
		}
	}

	void SoldierGameObjPtrVectorClass::default::set(int index, ISoldierGameObj ^value)
	{
		if (index < 0 || index >= VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			InternalSoldierGameObjPtrVectorClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalSoldierGameObjPtrVectorClassPointer->operator[](index) = reinterpret_cast<::SoldierGameObj *>(value->SoldierGameObjPointer.ToPointer());
		}
	}

	int SoldierGameObjPtrVectorClass::Length::get()
	{
		return InternalSoldierGameObjPtrVectorClassPointer->Length();
	}

	bool SoldierGameObjPtrVectorClass::InternalDestroyPointer()
	{
		Imports::DestroySoldierGameObjPtrVectorClass(InternalSoldierGameObjPtrVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::VectorClass<::SoldierGameObj *> *SoldierGameObjPtrVectorClass::InternalSoldierGameObjPtrVectorClassPointer::get()
	{
		return reinterpret_cast<::VectorClass<::SoldierGameObj *> *>(Pointer.ToPointer());
	}

	IntPtr SoldierGameObjPtrVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<VectorClassHelper<::SoldierGameObj *> *>(InternalSoldierGameObjPtrVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void SoldierGameObjPtrVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<VectorClassHelper<::SoldierGameObj *> *>(InternalSoldierGameObjPtrVectorClassPointer);

		helper->SetVector(reinterpret_cast<::SoldierGameObj **>(value.ToPointer()));
	}

	int SoldierGameObjPtrVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<VectorClassHelper<::SoldierGameObj *> *>(InternalSoldierGameObjPtrVectorClassPointer);

		return helper->GetVectorMax();
	}

	void SoldierGameObjPtrVectorClass::VectorMax::set(int value)
	{
		auto helper = reinterpret_cast<VectorClassHelper<::SoldierGameObj *> *>(InternalSoldierGameObjPtrVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool SoldierGameObjPtrVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<VectorClassHelper<::SoldierGameObj *> *>(InternalSoldierGameObjPtrVectorClassPointer);

		return helper->GetIsValid();
	}

	void SoldierGameObjPtrVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<VectorClassHelper<::SoldierGameObj *> *>(InternalSoldierGameObjPtrVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool SoldierGameObjPtrVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<VectorClassHelper<::SoldierGameObj *> *>(InternalSoldierGameObjPtrVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void SoldierGameObjPtrVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<VectorClassHelper<::SoldierGameObj *> *>(InternalSoldierGameObjPtrVectorClassPointer);

		helper->SetIsAllocated(value);
	}
}