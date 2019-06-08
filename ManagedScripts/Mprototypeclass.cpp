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
#include "Mprototypeclass.h"

#include "Imports.h"
#include "UnmanagedContainer.h"
#include "MRenderObjClass.h"
#include "MChunkClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <prototypeclass.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Text;
using namespace System::Runtime::InteropServices;

namespace RenSharp
{
	PrototypeClass::PrototypeClass()
	{

	}

	PrototypeClass::PrototypeClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	String ^PrototypeClass::ToString()
	{
		StringBuilder ^builder = gcnew StringBuilder();
		builder->Append(Name);

		return builder->ToString();
	}

	bool PrototypeClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IPrototypeClass ^otherThis = dynamic_cast<IPrototypeClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return PrototypeClassPointer.Equals(otherThis->PrototypeClassPointer);
	}

	IUnmanagedContainer<IRenderObjClass ^> ^PrototypeClass::Create()
	{
		auto result = InternalPrototypeClassPointer->Create();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew UnmanagedContainer<IRenderObjClass ^>(gcnew RenderObjClass(IntPtr(result)));
		}
	}

	IntPtr PrototypeClass::PrototypeClassPointer::get()
	{
		return IntPtr(InternalPrototypeClassPointer);
	}

	IPrototypeClass ^PrototypeClass::NextHash::get()
	{
		auto result = InternalPrototypeClassPointer->NextHash;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PrototypeClass(IntPtr(result));
		}
	}

	void PrototypeClass::NextHash::set(IPrototypeClass ^value)
	{
		if (value == nullptr || value->PrototypeClassPointer.ToPointer() == nullptr)
		{
			InternalPrototypeClassPointer->NextHash = nullptr;
		}
		else
		{
			InternalPrototypeClassPointer->NextHash = reinterpret_cast<::PrototypeClass *>(value->PrototypeClassPointer.ToPointer());
		}
	}

	String ^PrototypeClass::Name::get()
	{
		auto result = InternalPrototypeClassPointer->Get_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	int PrototypeClass::ClassID::get()
	{
		return InternalPrototypeClassPointer->Get_Class_ID();
	}

	bool PrototypeClass::InternalDestroyPointer()
	{
		Imports::DestroyPrototypeClass(InternalPrototypeClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::PrototypeClass *PrototypeClass::InternalPrototypeClassPointer::get()
	{
		return reinterpret_cast<::PrototypeClass *>(Pointer.ToPointer());
	}

	PrototypeLoaderClass::PrototypeLoaderClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool PrototypeLoaderClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IPrototypeLoaderClass ^otherThis = dynamic_cast<IPrototypeLoaderClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return PrototypeLoaderClassPointer.Equals(otherThis->PrototypeLoaderClassPointer);
	}

	IPrototypeClass ^PrototypeLoaderClass::LoadW3D(IChunkLoadClass ^cLoad)
	{
		if (cLoad == nullptr || cLoad->ChunkLoadClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("cLoad");
		}

		auto result = InternalPrototypeLoaderClassPointer->Load_W3D(
			*reinterpret_cast<::ChunkLoadClass *>(cLoad->ChunkLoadClassPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PrototypeClass(IntPtr(result));
		}
	}

	IntPtr PrototypeLoaderClass::PrototypeLoaderClassPointer::get()
	{
		return IntPtr(InternalPrototypeLoaderClassPointer);
	}

	int PrototypeLoaderClass::ChunkType::get()
	{
		return InternalPrototypeLoaderClassPointer->Chunk_Type();
	}

	bool PrototypeLoaderClass::InternalDestroyPointer()
	{
		Imports::DestroyPrototypeLoaderClass(InternalPrototypeLoaderClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::PrototypeLoaderClass *PrototypeLoaderClass::InternalPrototypeLoaderClassPointer::get()
	{
		return reinterpret_cast<::PrototypeLoaderClass *>(Pointer.ToPointer());
	}
}