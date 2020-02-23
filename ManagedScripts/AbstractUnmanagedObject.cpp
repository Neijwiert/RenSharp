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
#include "AbstractUnmanagedObject.h"

namespace RenSharp
{
	AbstractUnmanagedObject::AbstractUnmanagedObject()
		: pointer(IntPtr::Zero)
	{

	}

	AbstractUnmanagedObject::AbstractUnmanagedObject(IntPtr pointer)
		: pointer(pointer)
	{
		if (pointer.Equals(IntPtr::Zero))
		{
			throw gcnew ArgumentException("Argument 'pointer' may not be zero");
		}
	}

	bool AbstractUnmanagedObject::Equals(Object ^other)
	{
		if (other == nullptr)
		{
			return false;
		}
		else if (other == this)
		{
			return true;
		}

		IUnmanagedObject ^otherUnmanaged = dynamic_cast<IUnmanagedObject ^>(other);
		if (otherUnmanaged == nullptr)
		{
			return false;
		}

		return Pointer.Equals(otherUnmanaged->Pointer);
	}

	int AbstractUnmanagedObject::GetHashCode()
	{
		return pointer.GetHashCode();
	}

	bool AbstractUnmanagedObject::DestroyPointer()
	{
		if (InternalDestroyPointer())
		{
			Pointer = IntPtr::Zero;

			return true;
		}
		else
		{
			return false;
		}
	}

	void AbstractUnmanagedObject::ReleasePointer()
	{
		Pointer = IntPtr::Zero;
	}

	IntPtr AbstractUnmanagedObject::Pointer::get()
	{
		return pointer;
	}

	void AbstractUnmanagedObject::Pointer::set(IntPtr value)
	{
		pointer = value;
	}

	bool AbstractUnmanagedObject::InternalDestroyPointer()
	{
		return false;
	}
}