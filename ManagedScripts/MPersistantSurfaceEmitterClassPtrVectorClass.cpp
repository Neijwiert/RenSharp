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
#include "MPersistantSurfaceEmitterClassPtrVectorClass.h"

#include "Imports.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	PersistantSurfaceEmitterClassPtrVectorClass::PersistantSurfaceEmitterClassPtrVectorClass()
		: VectorClass<IntPtr>(IntPtr(Imports::CreatePersistantSurfaceEmitterClassPtrVectorClass1()))
	{

	}

	PersistantSurfaceEmitterClassPtrVectorClass::PersistantSurfaceEmitterClassPtrVectorClass(int size)
		: VectorClass<IntPtr>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreatePersistantSurfaceEmitterClassPtrVectorClass2(size));
	}

	PersistantSurfaceEmitterClassPtrVectorClass::PersistantSurfaceEmitterClassPtrVectorClass(IntPtr pointer)
		: VectorClass<IntPtr>(pointer)
	{

	}

	IUnmanagedContainer<IVectorClass<IntPtr> ^> ^PersistantSurfaceEmitterClassPtrVectorClass::CreatePersistantSurfaceEmitterClassPtrVectorClass()
	{
		return gcnew UnmanagedContainer<IVectorClass<IntPtr> ^>(gcnew PersistantSurfaceEmitterClassPtrVectorClass());
	}

	IUnmanagedContainer<IVectorClass<IntPtr> ^> ^PersistantSurfaceEmitterClassPtrVectorClass::CreatePersistantSurfaceEmitterClassPtrVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IVectorClass<IntPtr> ^>(gcnew PersistantSurfaceEmitterClassPtrVectorClass(size));
	}

	bool PersistantSurfaceEmitterClassPtrVectorClass::Resize(int newSize)
	{
		return InternalPersistantSurfaceEmitterClassPtrVectorClassPointer->Resize(newSize);
	}

	void PersistantSurfaceEmitterClassPtrVectorClass::Clear()
	{
		InternalPersistantSurfaceEmitterClassPtrVectorClassPointer->Clear();
	}

	int PersistantSurfaceEmitterClassPtrVectorClass::ID(IntPtr object)
	{
		return InternalPersistantSurfaceEmitterClassPtrVectorClassPointer->ID(reinterpret_cast<::PersistantSurfaceEmitterClass *>(object.ToPointer()));
	}

	IntPtr PersistantSurfaceEmitterClassPtrVectorClass::PersistantSurfaceEmitterClassPtrVectorClassPointer::get()
	{
		return IntPtr(InternalPersistantSurfaceEmitterClassPtrVectorClassPointer);
	}

	IntPtr PersistantSurfaceEmitterClassPtrVectorClass::default::get(int index)
	{
		if (index < 0 || index >= VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return IntPtr(InternalPersistantSurfaceEmitterClassPtrVectorClassPointer->operator[](index));
	}

	void PersistantSurfaceEmitterClassPtrVectorClass::default::set(int index, IntPtr value)
	{
		if (index < 0 || index >= VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		InternalPersistantSurfaceEmitterClassPtrVectorClassPointer->operator[](index) = reinterpret_cast<::PersistantSurfaceEmitterClass *>(value.ToPointer());
	}

	int PersistantSurfaceEmitterClassPtrVectorClass::Length::get()
	{
		return InternalPersistantSurfaceEmitterClassPtrVectorClassPointer->Length();
	}

	bool PersistantSurfaceEmitterClassPtrVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyPersistantSurfaceEmitterClassPtrVectorClass(InternalPersistantSurfaceEmitterClassPtrVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::VectorClass<::PersistantSurfaceEmitterClass *> *PersistantSurfaceEmitterClassPtrVectorClass::InternalPersistantSurfaceEmitterClassPtrVectorClassPointer::get()
	{
		return reinterpret_cast<::VectorClass<::PersistantSurfaceEmitterClass *> *>(Pointer.ToPointer());
	}

	IntPtr PersistantSurfaceEmitterClassPtrVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<VectorClassHelper<::PersistantSurfaceEmitterClass *> *>(InternalPersistantSurfaceEmitterClassPtrVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void PersistantSurfaceEmitterClassPtrVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<VectorClassHelper<::PersistantSurfaceEmitterClass *> *>(InternalPersistantSurfaceEmitterClassPtrVectorClassPointer);

		helper->SetVector(reinterpret_cast<::PersistantSurfaceEmitterClass **>(value.ToPointer()));
	}

	int PersistantSurfaceEmitterClassPtrVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<VectorClassHelper<::PersistantSurfaceEmitterClass *> *>(InternalPersistantSurfaceEmitterClassPtrVectorClassPointer);

		return helper->GetVectorMax();
	}

	void PersistantSurfaceEmitterClassPtrVectorClass::VectorMax::set(int value)
	{
		auto helper = reinterpret_cast<VectorClassHelper<::PersistantSurfaceEmitterClass *> *>(InternalPersistantSurfaceEmitterClassPtrVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool PersistantSurfaceEmitterClassPtrVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<VectorClassHelper<::PersistantSurfaceEmitterClass *> *>(InternalPersistantSurfaceEmitterClassPtrVectorClassPointer);

		return helper->GetIsValid();
	}

	void PersistantSurfaceEmitterClassPtrVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<VectorClassHelper<::PersistantSurfaceEmitterClass *> *>(InternalPersistantSurfaceEmitterClassPtrVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool PersistantSurfaceEmitterClassPtrVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<VectorClassHelper<::PersistantSurfaceEmitterClass *> *>(InternalPersistantSurfaceEmitterClassPtrVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void PersistantSurfaceEmitterClassPtrVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<VectorClassHelper<::PersistantSurfaceEmitterClass *> *>(InternalPersistantSurfaceEmitterClassPtrVectorClassPointer);

		helper->SetIsAllocated(value);
	}
}