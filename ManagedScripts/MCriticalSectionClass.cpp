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
#include "MCriticalSectionClass.h"

#include "Imports.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	CriticalSectionClass::LockClass::LockClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool CriticalSectionClass::LockClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		CriticalSectionClass::ILockClass^ otherThis = dynamic_cast<CriticalSectionClass::ILockClass^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return LockClassPointer.Equals(otherThis->LockClassPointer);
	}

	IntPtr CriticalSectionClass::LockClass::LockClassPointer::get()
	{
		return IntPtr(InternalLockClassPointer);
	}

	::CriticalSectionClass::LockClass* CriticalSectionClass::LockClass::InternalLockClassPointer::get()
	{
		return reinterpret_cast<::CriticalSectionClass::LockClass*>(Pointer.ToPointer());
	}

	CriticalSectionClass::CriticalSectionClass()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateCriticalSectionClass()))
	{

	}

	CriticalSectionClass::CriticalSectionClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<ICriticalSectionClass^>^ CriticalSectionClass::CreateCriticalSectionClass()
	{
		return gcnew UnmanagedContainer<ICriticalSectionClass^>(gcnew CriticalSectionClass());
	}

	bool CriticalSectionClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		ICriticalSectionClass^ otherThis = dynamic_cast<ICriticalSectionClass^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return CriticalSectionClassPointer.Equals(otherThis->CriticalSectionClassPointer);
	}

	void CriticalSectionClass::Enter()
	{
		InternalCriticalSectionClassPointer->Enter();
	}
	
	void CriticalSectionClass::Exit()
	{
		InternalCriticalSectionClassPointer->Exit();
	}

	IntPtr CriticalSectionClass::CriticalSectionClassPointer::get()
	{
		return IntPtr(InternalCriticalSectionClassPointer);
	}

	bool CriticalSectionClass::InternalDestroyPointer()
	{
		Imports::DestroyCriticalSectionClass(InternalCriticalSectionClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::CriticalSectionClass* CriticalSectionClass::InternalCriticalSectionClassPointer::get()
	{
		return reinterpret_cast<::CriticalSectionClass*>(Pointer.ToPointer());
	}

	FastCriticalSectionClass::LockClass::LockClass(IFastCriticalSectionClass^ section)
	{
		if (section == nullptr || section->FastCriticalSectionClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("section");
		}

		Pointer = IntPtr(Imports::CreateFastCriticalSectionClassLockClass(
			reinterpret_cast<::FastCriticalSectionClass*>(section->FastCriticalSectionClassPointer.ToPointer())));
	}

	FastCriticalSectionClass::LockClass::LockClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<FastCriticalSectionClass::ILockClass^>^ FastCriticalSectionClass::LockClass::CreateLockClass(IFastCriticalSectionClass^ section)
	{
		return gcnew UnmanagedContainer<FastCriticalSectionClass::ILockClass^>(gcnew FastCriticalSectionClass::LockClass(section));
	}

	bool FastCriticalSectionClass::LockClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		FastCriticalSectionClass::ILockClass^ otherThis = dynamic_cast<FastCriticalSectionClass::ILockClass^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return LockClassPointer.Equals(otherThis->LockClassPointer);
	}

	IntPtr FastCriticalSectionClass::LockClass::LockClassPointer::get()
	{
		return IntPtr(InternalLockClassPointer);
	}

	bool FastCriticalSectionClass::LockClass::InternalDestroyPointer()
	{
		Imports::DestroyFastCriticalSectionClassLockClass(InternalLockClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::FastCriticalSectionClass::LockClass* FastCriticalSectionClass::LockClass::InternalLockClassPointer::get()
	{
		return reinterpret_cast<::FastCriticalSectionClass::LockClass*>(Pointer.ToPointer());
	}

	FastCriticalSectionClass::FastCriticalSectionClass()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateFastCriticalSectionClass()))
	{

	}

	FastCriticalSectionClass::FastCriticalSectionClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{
		
	}

	IUnmanagedContainer<IFastCriticalSectionClass^>^ FastCriticalSectionClass::CreateFastCriticalSectionClass()
	{
		return gcnew UnmanagedContainer<IFastCriticalSectionClass^>(gcnew FastCriticalSectionClass());
	}

	bool FastCriticalSectionClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IFastCriticalSectionClass^ otherThis = dynamic_cast<IFastCriticalSectionClass^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return FastCriticalSectionClassPointer.Equals(otherThis->FastCriticalSectionClassPointer);
	}

	IntPtr FastCriticalSectionClass::FastCriticalSectionClassPointer::get()
	{
		return IntPtr(InternalFastCriticalSectionClassPointer);
	}

	bool FastCriticalSectionClass::InternalDestroyPointer()
	{
		Imports::DestroyFastCriticalSectionClass(InternalFastCriticalSectionClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::FastCriticalSectionClass* FastCriticalSectionClass::InternalFastCriticalSectionClassPointer::get()
	{
		return reinterpret_cast<::FastCriticalSectionClass*>(Pointer.ToPointer());
	}
}