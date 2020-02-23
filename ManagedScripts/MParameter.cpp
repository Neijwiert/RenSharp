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
#include "MParameter.h"

#include "Imports.h"

using namespace System::Text;

namespace RenSharp
{
	ParameterClass::ParameterClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	String^ ParameterClass::ToString()
	{
		StringBuilder^ builder = gcnew StringBuilder();
		builder->Append(Name);

		return builder->ToString();
	}

	bool ParameterClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IParameterClass^ otherThis = dynamic_cast<IParameterClass^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return ParameterClassPointer.Equals(otherThis->ParameterClassPointer);
	}

	IntPtr ParameterClass::AsDefParameterClass()
	{
		return IntPtr(InternalParameterClassPointer->As_DefParameterClass());
	}

	bool ParameterClass::IsType(IParameterClass::ParameterType type)
	{
		return InternalParameterClassPointer->Is_Type(
			static_cast<::ParameterClass::Type>(type));
	}

	void ParameterClass::CopyValue(IParameterClass^ src)
	{
		if (src == nullptr || src->ParameterClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("src");
		}

		InternalParameterClassPointer->Copy_Value(
			*reinterpret_cast<::ParameterClass*>(src->ParameterClassPointer.ToPointer()));
	}

	IntPtr ParameterClass::ParameterClassPointer::get()
	{
		return IntPtr(InternalParameterClassPointer);
	}

	IParameterClass::ParameterType ParameterClass::Type::get()
	{
		return static_cast<IParameterClass::ParameterType>(InternalParameterClassPointer->Get_Type());
	}

	bool ParameterClass::IsModified::get()
	{
		return InternalParameterClassPointer->Is_Modifed();
	}

	void ParameterClass::IsModified::set(bool value)
	{
		InternalParameterClassPointer->Set_Modified(value);
	}

	String^ ParameterClass::Name::get()
	{
		auto result = InternalParameterClassPointer->Get_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	void ParameterClass::Name::set(String^ value)
	{
		if (value == nullptr)
		{
			InternalParameterClassPointer->Set_Name(nullptr);
		}
		else
		{
			IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
			try
			{
				InternalParameterClassPointer->Set_Name(
					reinterpret_cast<char*>(valueHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(valueHandle);
			}
		}
	}

	String^ ParameterClass::UnitsName::get()
	{
		auto result = InternalParameterClassPointer->Get_Units_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	void ParameterClass::UnitsName::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalParameterClassPointer->Set_Units_Name(
				reinterpret_cast<char*>(valueHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	bool ParameterClass::InternalDestroyPointer()
	{
		Imports::DestroyParameterClass(InternalParameterClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::ParameterClass* ParameterClass::InternalParameterClassPointer::get()
	{
		return reinterpret_cast<::ParameterClass*>(Pointer.ToPointer());
	}

	ParameterListClass::ParameterListClass()
		: DynamicVectorClass<IParameterClass^>(IntPtr(Imports::CreateParameterListClass()))
	{

	}

	ParameterListClass::ParameterListClass(IntPtr pointer)
		: DynamicVectorClass<IParameterClass^>(pointer)
	{

	}

	bool ParameterListClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		auto otherThis = dynamic_cast<IParameterListClass^>(other);
		if (otherThis == nullptr)
		{
			return false;
		}

		return ParameterListClassPointer.Equals(otherThis->ParameterListClassPointer);
	}

	IUnmanagedContainer<IParameterListClass^>^ ParameterListClass::CreateParameterListClass()
	{
		return gcnew UnmanagedContainer<IParameterListClass^>(gcnew ParameterListClass());
	}

	bool ParameterListClass::Resize(int newSize)
	{
		return InternalParameterClassPtrDynamicVectorClassPointer->Resize(newSize);
	}

	void ParameterListClass::Clear()
	{
		InternalParameterClassPtrDynamicVectorClassPointer->Clear();
	}

	int ParameterListClass::ID(IParameterClass^ object)
	{
		if (object == nullptr || object->ParameterClassPointer.ToPointer() == nullptr)
		{
			return InternalParameterClassPtrDynamicVectorClassPointer->ID(static_cast<::ParameterClass*>(nullptr));
		}
		else
		{
			return InternalParameterClassPtrDynamicVectorClassPointer->ID(reinterpret_cast<::ParameterClass*>(object->ParameterClassPointer.ToPointer()));
		}
	}

	void ParameterListClass::Insert(int index, IParameterClass^ object)
	{
		if (index < 0 || index >= Length)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (object == nullptr || object->ParameterClassPointer.ToPointer() == nullptr)
		{
			InternalParameterClassPtrDynamicVectorClassPointer->Insert(index, nullptr);
		}
		else
		{
			InternalParameterClassPtrDynamicVectorClassPointer->Insert(index, reinterpret_cast<::ParameterClass*>(object->ParameterClassPointer.ToPointer()));
		}
	}

	bool ParameterListClass::Add(IParameterClass^ object)
	{
		if (object == nullptr || object->ParameterClassPointer.ToPointer() == nullptr)
		{
			return InternalParameterClassPtrDynamicVectorClassPointer->Add(nullptr);
		}
		else
		{
			return InternalParameterClassPtrDynamicVectorClassPointer->Add(reinterpret_cast<::ParameterClass*>(object->ParameterClassPointer.ToPointer()));
		}
	}

	void ParameterListClass::ResetActive()
	{
		InternalParameterClassPtrDynamicVectorClassPointer->Reset_Active();
	}

	bool ParameterListClass::AddHead(IParameterClass^ object)
	{
		if (object == nullptr || object->ParameterClassPointer.ToPointer() == nullptr)
		{
			return InternalParameterClassPtrDynamicVectorClassPointer->Add_Head(nullptr);
		}
		else
		{
			return InternalParameterClassPtrDynamicVectorClassPointer->Add_Head(reinterpret_cast<::ParameterClass*>(object->ParameterClassPointer.ToPointer()));
		}
	}

	bool ParameterListClass::DeleteObj(IParameterClass^ object)
	{
		if (object == nullptr || object->ParameterClassPointer.ToPointer() == nullptr)
		{
			return InternalParameterClassPtrDynamicVectorClassPointer->DeleteObj(nullptr);
		}
		else
		{
			return InternalParameterClassPtrDynamicVectorClassPointer->DeleteObj(reinterpret_cast<::ParameterClass*>(object->ParameterClassPointer.ToPointer()));
		}
	}

	bool ParameterListClass::Delete(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalParameterClassPtrDynamicVectorClassPointer->Delete(index);
	}

	void ParameterListClass::DeleteAll()
	{
		InternalParameterClassPtrDynamicVectorClassPointer->Delete_All();
	}

	int ParameterListClass::UninitializedAdd()
	{
		int count = Count;

		InternalParameterClassPtrDynamicVectorClassPointer->Uninitialized_Add();

		return count;
	}

	void ParameterListClass::AddMultiple(int numberToAdd)
	{
		if (numberToAdd < 0)
		{
			throw gcnew ArgumentOutOfRangeException("numberToAdd");
		}

		InternalParameterClassPtrDynamicVectorClassPointer->Add_Multiple(numberToAdd);
	}

	IntPtr ParameterListClass::ParameterListClassPointer::get()
	{
		return IntPtr(InternalParameterListClassPointer);
	}

	IntPtr ParameterListClass::ParameterClassPtrDynamicVectorClassPointer::get()
	{
		return IntPtr(InternalParameterClassPtrDynamicVectorClassPointer);
	}

	IParameterClass^ ParameterListClass::default::get(int index)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalParameterClassPtrDynamicVectorClassPointer->operator[](index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ParameterClass(IntPtr(result));
		}
	}

	void ParameterListClass::default::set(int index, IParameterClass^ value)
	{
		if (index < 0 || index >= Count)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		if (value == nullptr || value->ParameterClassPointer.ToPointer() == nullptr)
		{
			InternalParameterClassPtrDynamicVectorClassPointer->operator[](index) = nullptr;
		}
		else
		{
			InternalParameterClassPtrDynamicVectorClassPointer->operator[](index) = reinterpret_cast<::ParameterClass*>(value->ParameterClassPointer.ToPointer());
		}
	}

	int ParameterListClass::Length::get()
	{
		return InternalParameterClassPtrDynamicVectorClassPointer->Length();
	}

	int ParameterListClass::Count::get()
	{
		return InternalParameterClassPtrDynamicVectorClassPointer->Count();
	}

	void ParameterListClass::Count::set(int value)
	{
		if (value < 0 || value > Length)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalParameterClassPtrDynamicVectorClassPointer->Set_Active(value);
	}

	int ParameterListClass::GrowthStep::get()
	{
		return InternalParameterClassPtrDynamicVectorClassPointer->Growth_Step();
	}

	void ParameterListClass::GrowthStep::set(int value)
	{
		if (value < 1)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		InternalParameterClassPtrDynamicVectorClassPointer->Set_Growth_Step(value);
	}

	bool ParameterListClass::InternalDestroyPointer()
	{
		Imports::DestroyParameterListClass(InternalParameterListClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	void ParameterListClass::FreeParameters()
	{
		Imports::FreeParametersParameterListClass(InternalParameterListClassPointer);
	}

	::DynamicVectorClass<::ParameterClass*>* ParameterListClass::InternalParameterClassPtrDynamicVectorClassPointer::get()
	{
		return InternalParameterListClassPointer;
	}

	::ParameterListClass* ParameterListClass::InternalParameterListClassPointer::get()
	{
		return reinterpret_cast<::ParameterListClass*>(Pointer.ToPointer());
	}

	IntPtr ParameterListClass::Vector::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::ParameterClass*>*>(InternalParameterClassPtrDynamicVectorClassPointer);

		return IntPtr(helper->GetVector());
	}

	void ParameterListClass::Vector::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::ParameterClass*>*>(InternalParameterClassPtrDynamicVectorClassPointer);

		helper->SetVector(reinterpret_cast<::ParameterClass * *>(value.ToPointer()));
	}

	int ParameterListClass::VectorMax::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::ParameterClass*>*>(InternalParameterClassPtrDynamicVectorClassPointer);

		return helper->GetVectorMax();
	}

	void ParameterListClass::VectorMax::set(int value)
	{
		if (value < 0)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::ParameterClass*>*>(InternalParameterClassPtrDynamicVectorClassPointer);

		helper->SetVectorMax(value);
	}

	bool ParameterListClass::IsValid::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::ParameterClass*>*>(InternalParameterClassPtrDynamicVectorClassPointer);

		return helper->GetIsValid();
	}

	void ParameterListClass::IsValid::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::ParameterClass*>*>(InternalParameterClassPtrDynamicVectorClassPointer);

		helper->SetIsValid(value);
	}

	bool ParameterListClass::IsAllocated::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::ParameterClass*>*>(InternalParameterClassPtrDynamicVectorClassPointer);

		return helper->GetIsAllocated();
	}

	void ParameterListClass::IsAllocated::set(bool value)
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::ParameterClass*>*>(InternalParameterClassPtrDynamicVectorClassPointer);

		helper->SetIsAllocated(value);
	}

	int ParameterListClass::ActiveCount::get()
	{
		auto helper = reinterpret_cast<DynamicVectorClassHelper<::ParameterClass*>*>(InternalParameterClassPtrDynamicVectorClassPointer);

		return helper->GetActiveCount();
	}

	void ParameterListClass::ActiveCount::set(int value)
	{
		if (value < 0 || value > VectorMax)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DynamicVectorClassHelper<::ParameterClass*>*>(InternalParameterClassPtrDynamicVectorClassPointer);

		helper->SetActiveCount(value);
	}
}