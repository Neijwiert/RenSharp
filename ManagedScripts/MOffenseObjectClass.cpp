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
#include "MOffenseObjectClass.h"

#include "MArmedGameObj.h"
#include "UnmanagedContainer.h"
#include "Imports.h"

namespace RenSharp
{
	OffenseObjectClass::OffenseObjectClass(float damage, unsigned int warhead, IArmedGameObj ^owner)
		: AbstractUnmanagedObject(IntPtr(Imports::CreateOffenseObjectClass1(
			damage,
			warhead,
			(owner == nullptr || owner->ArmedGameObjPointer.ToPointer() == nullptr ? nullptr : reinterpret_cast<::ArmedGameObj *>(owner->ArmedGameObjPointer.ToPointer())))))
	{

	}

	OffenseObjectClass::OffenseObjectClass(float damage, unsigned int warhead)
		: AbstractUnmanagedObject(IntPtr(Imports::CreateOffenseObjectClass2(damage, warhead)))
	{

	}

	OffenseObjectClass::OffenseObjectClass(float damage)
		: AbstractUnmanagedObject(IntPtr(Imports::CreateOffenseObjectClass3(damage)))
	{

	}

	OffenseObjectClass::OffenseObjectClass()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateOffenseObjectClass4()))
	{

	}

	OffenseObjectClass::OffenseObjectClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IOffenseObjectClass ^> ^OffenseObjectClass::CreateOffenseObjectClass(float damage, unsigned int warhead, IArmedGameObj ^owner)
	{
		return gcnew UnmanagedContainer<IOffenseObjectClass ^>(gcnew OffenseObjectClass(damage, warhead, owner));
	}

	IUnmanagedContainer<IOffenseObjectClass ^> ^OffenseObjectClass::CreateOffenseObjectClass(float damage, unsigned int warhead)
	{
		return gcnew UnmanagedContainer<IOffenseObjectClass ^>(gcnew OffenseObjectClass(damage, warhead));
	}

	IUnmanagedContainer<IOffenseObjectClass ^> ^OffenseObjectClass::CreateOffenseObjectClass(float damage)
	{
		return gcnew UnmanagedContainer<IOffenseObjectClass ^>(gcnew OffenseObjectClass(damage));
	}

	IUnmanagedContainer<IOffenseObjectClass ^> ^OffenseObjectClass::CreateOffenseObjectClass()
	{
		return gcnew UnmanagedContainer<IOffenseObjectClass ^>(gcnew OffenseObjectClass());
	}

	bool OffenseObjectClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IOffenseObjectClass ^otherThis = dynamic_cast<IOffenseObjectClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return OffenseObjectClassPointer.Equals(otherThis->OffenseObjectClassPointer);
	}

	void OffenseObjectClass::ScaleDamage(float scale)
	{
		InternalOffenseObjectClassPointer->Scale_Damage(scale);
	}

	IntPtr OffenseObjectClass::OffenseObjectClassPointer::get()
	{
		return IntPtr(InternalOffenseObjectClassPointer);
	}

	float OffenseObjectClass::Damage::get()
	{
		return InternalOffenseObjectClassPointer->Get_Damage();
	}

	void OffenseObjectClass::Damage::set(float value)
	{
		InternalOffenseObjectClassPointer->Set_Damage(value);
	}

	unsigned int OffenseObjectClass::Warhead::get()
	{
		return InternalOffenseObjectClassPointer->Get_Warhead();
	}

	void OffenseObjectClass::Warhead::set(unsigned int value)
	{
		InternalOffenseObjectClassPointer->Set_Warhead(value);
	}

	IArmedGameObj ^OffenseObjectClass::Owner::get()
	{
		auto result = InternalOffenseObjectClassPointer->Get_Owner();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ArmedGameObj(IntPtr(result));
		}
	}

	void OffenseObjectClass::Owner::set(IArmedGameObj ^value)
	{
		if (value == nullptr || value->ArmedGameObjPointer.ToPointer() == nullptr)
		{
			InternalOffenseObjectClassPointer->Set_Owner(nullptr);
		}
		else
		{
			InternalOffenseObjectClassPointer->Set_Owner(reinterpret_cast<::ArmedGameObj *>(value->ArmedGameObjPointer.ToPointer()));
		}
	}

	bool OffenseObjectClass::ForceServerDamage::get()
	{
		return InternalOffenseObjectClassPointer->ForceServerDamage;
	}

	void OffenseObjectClass::ForceServerDamage::set(bool value)
	{
		InternalOffenseObjectClassPointer->ForceServerDamage = value;
	}

	bool OffenseObjectClass::EnableClientDamage::get()
	{
		return InternalOffenseObjectClassPointer->EnableClientDamage;
	}

	void OffenseObjectClass::EnableClientDamage::set(bool value)
	{
		InternalOffenseObjectClassPointer->EnableClientDamage = value;
	}

	bool OffenseObjectClass::InternalDestroyPointer()
	{
		Imports::DestroyOffenseObjectClass(InternalOffenseObjectClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::OffenseObjectClass *OffenseObjectClass::InternalOffenseObjectClassPointer::get()
	{
		return reinterpret_cast<::OffenseObjectClass *>(Pointer.ToPointer());
	}
}