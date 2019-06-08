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
#include "MHTreeClass.h"

#include "Imports.h"
#include "MMatrix3D.h"
#include "UnmanagedContainer.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <HTreeClass.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Runtime::InteropServices;
using namespace System::Text;

namespace RenSharp
{
	PivotClass::PivotClass()
		: AbstractUnmanagedObject(IntPtr(Imports::CreatePivotClass()))
	{

	}

	PivotClass::PivotClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	String ^PivotClass::ToString()
	{
		return Name;
	}

	bool PivotClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IPivotClass ^otherThis = dynamic_cast<IPivotClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return PivotClassPointer.Equals(otherThis->PivotClassPointer);
	}

	IUnmanagedContainer<IPivotClass ^> ^PivotClass::CreatePivotClass()
	{
		return gcnew UnmanagedContainer<IPivotClass ^>(gcnew PivotClass());
	}

	void PivotClass::CaptureUpdate()
	{
		InternalPivotClassPointer->Capture_Update();
	}

	IntPtr PivotClass::PivotClassPointer::get()
	{
		return IntPtr(InternalPivotClassPointer);
	}

	String ^PivotClass::Name::get()
	{
		static constexpr std::size_t NameLength = sizeof(InternalPivotClassPointer->Name) / sizeof(InternalPivotClassPointer->Name[0]);
		if (InternalPivotClassPointer->Name[NameLength - 1] != '\0')
		{
			InternalPivotClassPointer->Name[NameLength - 1] = '\0';
		}

		return gcnew String(InternalPivotClassPointer->Name);
	}

	void PivotClass::Name::set(String ^value)
	{
		static constexpr std::size_t NameLength = sizeof(InternalPivotClassPointer->Name) / sizeof(InternalPivotClassPointer->Name[0]);

		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}
		else if (value->Length >= NameLength)
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			std::size_t realLength = std::strlen(reinterpret_cast<char *>(valueHandle.ToPointer()));
			if (realLength >= NameLength)
			{
				throw gcnew ArgumentOutOfRangeException("value");
			}

			std::memcpy(InternalPivotClassPointer->Name, valueHandle.ToPointer(), realLength * sizeof(char));
			InternalPivotClassPointer->Name[realLength] = '\0';
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	int PivotClass::Index::get()
	{
		return InternalPivotClassPointer->Index;
	}

	void PivotClass::Index::set(int value)
	{
		InternalPivotClassPointer->Index = value;
	}

	IPivotClass ^PivotClass::Parent::get()
	{
		auto result = InternalPivotClassPointer->Parent;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PivotClass(IntPtr(result));
		}
	}

	void PivotClass::Parent::set(IPivotClass ^value)
	{
		if (value == nullptr || value->PivotClassPointer.ToPointer() == nullptr)
		{
			InternalPivotClassPointer->Parent = nullptr;
		}
		else
		{
			InternalPivotClassPointer->Parent = reinterpret_cast<::PivotClass *>(value->PivotClassPointer.ToPointer());
		}
	}

	Matrix3D PivotClass::BaseTransform::get()
	{
		Matrix3D result;

		Matrix3D::UnmanagedToManagedMatrix3D(InternalPivotClassPointer->BaseTransform, result);

		return result;
	}

	void PivotClass::BaseTransform::set(Matrix3D value)
	{
		Matrix3D::ManagedToUnmanagedMatrix3D(value, InternalPivotClassPointer->BaseTransform);
	}

	Matrix3D PivotClass::Transform::get()
	{
		Matrix3D result;

		Matrix3D::UnmanagedToManagedMatrix3D(InternalPivotClassPointer->Transform, result);

		return result;
	}

	void PivotClass::Transform::set(Matrix3D value)
	{
		Matrix3D::ManagedToUnmanagedMatrix3D(value, InternalPivotClassPointer->Transform);
	}

	bool PivotClass::IsVisible::get()
	{
		return InternalPivotClassPointer->IsVisible;
	}

	void PivotClass::IsVisible::set(bool value)
	{
		InternalPivotClassPointer->IsVisible = value;
	}

	bool PivotClass::IsCaptured::get()
	{
		return InternalPivotClassPointer->IsCaptured;
	}

	void PivotClass::IsCaptured::set(bool value)
	{
		InternalPivotClassPointer->IsCaptured = value;
	}

	Matrix3D PivotClass::CapTransform::get()
	{
		Matrix3D result;

		Matrix3D::UnmanagedToManagedMatrix3D(InternalPivotClassPointer->CapTransform, result);

		return result;
	}

	void PivotClass::CapTransform::set(Matrix3D value)
	{
		Matrix3D::ManagedToUnmanagedMatrix3D(value, InternalPivotClassPointer->CapTransform);
	}

	bool PivotClass::WorldSpaceTranslation::get()
	{
		return InternalPivotClassPointer->WorldSpaceTranslation;
	}

	void PivotClass::WorldSpaceTranslation::set(bool value)
	{
		InternalPivotClassPointer->WorldSpaceTranslation = value;
	}

	bool PivotClass::InternalDestroyPointer()
	{
		Imports::DestroyPivotClass(InternalPivotClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::PivotClass *PivotClass::InternalPivotClassPointer::get()
	{
		return reinterpret_cast<::PivotClass *>(Pointer.ToPointer());
	}

	HTreeClass::HTreeClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	String ^HTreeClass::ToString()
	{
		StringBuilder ^builder = gcnew StringBuilder();
		builder->Append(Name);

		return builder->ToString();
	}

	bool HTreeClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IHTreeClass ^otherThis = dynamic_cast<IHTreeClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return HTreeClassPointer.Equals(otherThis->HTreeClassPointer);
	}

	Matrix3D HTreeClass::GetTransform(int pivot)
	{
		if (pivot < 0 || pivot >= InternalHTreeClassPointer->Num_Pivots())
		{
			throw gcnew ArgumentOutOfRangeException("pivot");
		}

		Matrix3D result;

		Matrix3D::UnmanagedToManagedMatrix3D(InternalHTreeClassPointer->Get_Transform(pivot), result);

		return result;
	}

	bool HTreeClass::GetVisibility(int pivot)
	{
		if (pivot < 0 || pivot >= InternalHTreeClassPointer->Num_Pivots())
		{
			throw gcnew ArgumentOutOfRangeException("pivot");
		}

		return InternalHTreeClassPointer->Get_Visibility(pivot);
	}

	IntPtr HTreeClass::HTreeClassPointer::get()
	{
		return IntPtr(InternalHTreeClassPointer);
	}

	String ^HTreeClass::Name::get()
	{
		auto result = InternalHTreeClassPointer->Get_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	int HTreeClass::NumPivots::get()
	{
		return InternalHTreeClassPointer->Num_Pivots();
	}

	Matrix3D HTreeClass::RootTransform::get()
	{
		Matrix3D result;

		Matrix3D::UnmanagedToManagedMatrix3D(InternalHTreeClassPointer->Get_Root_Transform(), result);

		return result;
	}

	::HTreeClass *HTreeClass::InternalHTreeClassPointer::get()
	{
		return reinterpret_cast<::HTreeClass *>(Pointer.ToPointer());
	}
}