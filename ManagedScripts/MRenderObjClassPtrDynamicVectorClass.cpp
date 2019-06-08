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
#include "MRenderObjClassPtrDynamicVectorClass.h"

#include "MRenderObjClass.h"
#include "Imports.h"

namespace RenSharp
{
	RenderObjClassPtrDynamicVectorClass::RenderObjClassPtrDynamicVectorClass()
		: DynamicVectorClass<IRenderObjClass ^>(IntPtr(Imports::CreateRenderObjClassPtrDynamicVectorClass1()))
	{

	}

	RenderObjClassPtrDynamicVectorClass::RenderObjClassPtrDynamicVectorClass(int size)
		: DynamicVectorClass<IRenderObjClass ^>()
	{
		if (size < 0)
		{
			throw gcnew ArgumentOutOfRangeException("size");
		}

		Pointer = IntPtr(Imports::CreateRenderObjClassPtrDynamicVectorClass2(size));
	}

	RenderObjClassPtrDynamicVectorClass::RenderObjClassPtrDynamicVectorClass(IntPtr pointer)
		: DynamicVectorClass<IRenderObjClass ^>(pointer)
	{

	}

	IUnmanagedContainer<IDynamicVectorClass<IRenderObjClass ^> ^> ^RenderObjClassPtrDynamicVectorClass::CreateRenderObjClassPtrDynamicVectorClass()
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IRenderObjClass ^> ^>(gcnew RenderObjClassPtrDynamicVectorClass());
	}

	IUnmanagedContainer<IDynamicVectorClass<IRenderObjClass ^> ^> ^RenderObjClassPtrDynamicVectorClass::CreateRenderObjClassPtrDynamicVectorClass(int size)
	{
		return gcnew UnmanagedContainer<IDynamicVectorClass<IRenderObjClass ^> ^>(gcnew RenderObjClassPtrDynamicVectorClass(size));
	}

	bool RenderObjClassPtrDynamicVectorClass::Resize(int newSize)
	{
		return InternalRenderObjClassPtrDynamicVectorClassPointer->Resize(newSize);
	}

	void RenderObjClassPtrDynamicVectorClass::Clear()
	{
		InternalRenderObjClassPtrDynamicVectorClassPointer->Clear();
	}

	int RenderObjClassPtrDynamicVectorClass::ID(IRenderObjClass ^object)
	{
		if (object == nullptr || object->RenderObjClassPointer.ToPointer() == nullptr)
		{
			return InternalRenderObjClassPtrDynamicVectorClassPointer->ID(static_cast<::RenderObjClass *>(nullptr));
		}
		else
		{
			return InternalRenderObjClassPtrDynamicVectorClassPointer->ID(reinterpret_cast<::RenderObjClass *>(object->RenderObjClassPointer.ToPointer()));
		}
	}

	void RenderObjClassPtrDynamicVectorClass::Insert(int index, IRenderObjClass ^object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (object == nullptr || object->RenderObjClassPointer.ToPointer() == nullptr)
		{
			InternalRenderObjClassPtrDynamicVectorClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalRenderObjClassPtrDynamicVectorClassPointer->Insert(index, reinterpret_cast<::RenderObjClass *>(object->RenderObjClassPointer.ToPointer()));
		}
	}

	bool RenderObjClassPtrDynamicVectorClass::Add(IRenderObjClass ^object)
	{
		if (object == nullptr || object->RenderObjClassPointer.ToPointer() == nullptr)
		{
			return InternalRenderObjClassPtrDynamicVectorClassPointer->Add(nullptr);
		}
		else
		{
			return InternalRenderObjClassPtrDynamicVectorClassPointer->Add(reinterpret_cast<::RenderObjClass *>(object->RenderObjClassPointer.ToPointer()));
		}
	}

	void RenderObjClassPtrDynamicVectorClass::ResetActive()
	{
		InternalRenderObjClassPtrDynamicVectorClassPointer->Reset_Active();
	}

	bool RenderObjClassPtrDynamicVectorClass::AddHead(IRenderObjClass ^object)
	{
		if (object == nullptr || object->RenderObjClassPointer.ToPointer() == nullptr)
		{
			return InternalRenderObjClassPtrDynamicVectorClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalRenderObjClassPtrDynamicVectorClassPointer->Add_Head(reinterpret_cast<::RenderObjClass *>(object->RenderObjClassPointer.ToPointer()));
		}
	}

	bool RenderObjClassPtrDynamicVectorClass::DeleteObj(IRenderObjClass ^object)
	{
		if (object == nullptr || object->RenderObjClassPointer.ToPointer() == nullptr)
		{
			return InternalRenderObjClassPtrDynamicVectorClassPointer->DeleteObj(nullptr);
		}
		else
		{
			return InternalRenderObjClassPtrDynamicVectorClassPointer->DeleteObj(reinterpret_cast<::RenderObjClass *>(object->RenderObjClassPointer.ToPointer()));
		}
	}

	bool RenderObjClassPtrDynamicVectorClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalRenderObjClassPtrDynamicVectorClassPointer->Delete(index);
	}

	void RenderObjClassPtrDynamicVectorClass::DeleteAll()
	{
		InternalRenderObjClassPtrDynamicVectorClassPointer->Delete_All();
	}

	int RenderObjClassPtrDynamicVectorClass::UninitializedAdd()
	{
		int count = Count;

		InternalRenderObjClassPtrDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void RenderObjClassPtrDynamicVectorClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalRenderObjClassPtrDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr RenderObjClassPtrDynamicVectorClass::RenderObjClassPtrDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalRenderObjClassPtrDynamicVectorClassPointer);
	}

	IRenderObjClass ^RenderObjClassPtrDynamicVectorClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalRenderObjClassPtrDynamicVectorClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(result));
		}
	}

	void RenderObjClassPtrDynamicVectorClass::default::set(int index, IRenderObjClass ^value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->RenderObjClassPointer.ToPointer() == nullptr)
		{
			InternalRenderObjClassPtrDynamicVectorClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalRenderObjClassPtrDynamicVectorClassPointer->operator[](index) = reinterpret_cast<::RenderObjClass *>(value->RenderObjClassPointer.ToPointer());
		}
	}

	int RenderObjClassPtrDynamicVectorClass::Length::get()
	{
		return InternalRenderObjClassPtrDynamicVectorClassPointer->Length();
	}

	int RenderObjClassPtrDynamicVectorClass::Count::get()
	{
		return InternalRenderObjClassPtrDynamicVectorClassPointer->Count();
	}

	void RenderObjClassPtrDynamicVectorClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalRenderObjClassPtrDynamicVectorClassPointer->Set_Active(value);
	}

	int RenderObjClassPtrDynamicVectorClass::GrowthStep::get()
	{
		return InternalRenderObjClassPtrDynamicVectorClassPointer->Growth_Step();
	}

	void RenderObjClassPtrDynamicVectorClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalRenderObjClassPtrDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool RenderObjClassPtrDynamicVectorClass::InternalDestroyPointer()
	{
		Imports::DestroyRenderObjClassPtrDynamicVectorClass(InternalRenderObjClassPtrDynamicVectorClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DynamicVectorClass<::RenderObjClass *> *RenderObjClassPtrDynamicVectorClass::InternalRenderObjClassPtrDynamicVectorClassPointer::get()
	{
		return reinterpret_cast<::DynamicVectorClass<::RenderObjClass *> *>(Pointer.ToPointer());
	}

	IntPtr RenderObjClassPtrDynamicVectorClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::RenderObjClass *> *>(InternalRenderObjClassPtrDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void RenderObjClassPtrDynamicVectorClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::RenderObjClass *> *>(InternalRenderObjClassPtrDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::RenderObjClass **>(value.ToPointer()));
	}

	int RenderObjClassPtrDynamicVectorClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::RenderObjClass *> *>(InternalRenderObjClassPtrDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void RenderObjClassPtrDynamicVectorClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::RenderObjClass *> *>(InternalRenderObjClassPtrDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool RenderObjClassPtrDynamicVectorClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::RenderObjClass *> *>(InternalRenderObjClassPtrDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void RenderObjClassPtrDynamicVectorClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::RenderObjClass *> *>(InternalRenderObjClassPtrDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool RenderObjClassPtrDynamicVectorClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::RenderObjClass *> *>(InternalRenderObjClassPtrDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void RenderObjClassPtrDynamicVectorClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::RenderObjClass *> *>(InternalRenderObjClassPtrDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int RenderObjClassPtrDynamicVectorClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::RenderObjClass *> *>(InternalRenderObjClassPtrDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void RenderObjClassPtrDynamicVectorClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::RenderObjClass *> *>(InternalRenderObjClassPtrDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}