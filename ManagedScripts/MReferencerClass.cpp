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
#include "MReferencerClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <ReferencerClass.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "Imports.h"
#include "MScriptableGameObj.h"
#include "UnmanagedContainer.h"

namespace RenSharp
{
	ReferencerClass::ReferencerClass()
		: PostLoadableClass(IntPtr(Imports::CreateReferencerClass1()))
	{

	}

	ReferencerClass::ReferencerClass(IScriptableGameObj ^object)
		: PostLoadableClass(false)
	{
		if (object == nullptr || object->Pointer.ToPointer() == nullptr)
		{
			Pointer = IntPtr(Imports::CreateReferencerClass2(nullptr));
		}
		else
		{
			Pointer = IntPtr(Imports::CreateReferencerClass2(reinterpret_cast<::ScriptableGameObj *>(object->ScriptableGameObjPointer.ToPointer())));
		}
	}

	ReferencerClass::ReferencerClass(IntPtr pointer)
		: PostLoadableClass(pointer)
	{

	}

	IUnmanagedContainer<IReferencerClass ^> ^ReferencerClass::CreateReferencerClass()
	{
		return gcnew UnmanagedContainer<IReferencerClass ^>(gcnew ReferencerClass());
	}

	IUnmanagedContainer<IReferencerClass ^> ^ReferencerClass::CreateReferencerClass(IScriptableGameObj ^object)
	{
		return gcnew UnmanagedContainer<IReferencerClass ^>(gcnew ReferencerClass(object));
	}

	void ReferencerClass::AssignScriptableGameObj(IScriptableGameObj^ obj)
	{
		if (obj == nullptr || obj->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			InternalReferencerClassPointer->operator=(
				static_cast<::ScriptableGameObj*>(nullptr));
		}
		else
		{
			InternalReferencerClassPointer->operator=(
				reinterpret_cast<::ScriptableGameObj*>(obj->ScriptableGameObjPointer.ToPointer()));
		}
	}

	IntPtr ReferencerClass::ReferencerClassPointer::get()
	{
		return IntPtr(InternalReferencerClassPointer);
	}

	IScriptableGameObj ^ReferencerClass::Ptr::get()
	{
		auto result = InternalReferencerClassPointer->Get_Ptr();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptableGameObj(IntPtr(result));
		}
	}

	void ReferencerClass::Ptr::set(IScriptableGameObj ^value)
	{
		if (value == nullptr || value->ScriptableGameObjPointer.ToPointer() == nullptr)
		{
			InternalReferencerClassPointer->Set_Ptr(nullptr);
		}
		else
		{
			InternalReferencerClassPointer->Set_Ptr(reinterpret_cast<::ScriptableGameObj *>(value->ScriptableGameObjPointer.ToPointer()));
		}
	}

	::PostLoadableClass *ReferencerClass::InternalPostLoadableClassPointer::get()
	{
		return InternalReferencerClassPointer;
	}

	::ReferencerClass *ReferencerClass::InternalReferencerClassPointer::get()
	{
		return reinterpret_cast<::ReferencerClass *>(Pointer.ToPointer());
	}
}