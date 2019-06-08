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
#include "MVisTableMgrClass.h"

#include "Imports.h"
#include "UnmanagedContainer.h"
#include "MVisTableClass.h"
#include "MVisTableClassPtrSimpleVecClass.h"
#include "MVisTableClassMultiListClass.h"
#include "MCompressedVisTableClassPtrSimpleDynVecClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <VisTableMgrClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	VisDecompressionCacheClass::VisDecompressionCacheClass()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateVisDecompressionCacheClass()))
	{

	}

	VisDecompressionCacheClass::VisDecompressionCacheClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IVisDecompressionCacheClass^>^ VisDecompressionCacheClass::CreateVisDecompressionCacheClass()
	{
		return gcnew UnmanagedContainer<IVisDecompressionCacheClass^>(gcnew VisDecompressionCacheClass());
	}

	bool VisDecompressionCacheClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IVisDecompressionCacheClass^ otherThis = dynamic_cast<IVisDecompressionCacheClass^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return VisDecompressionCacheClassPointer.Equals(otherThis->VisDecompressionCacheClassPointer);
	}

	IntPtr VisDecompressionCacheClass::VisDecompressionCacheClassPointer::get()
	{
		return IntPtr(InternalVisDecompressionCacheClassPointer);
	}

	ISimpleVecClass<IVisTableClass^>^ VisDecompressionCacheClass::Cache::get()
	{
		return gcnew VisTableClassPtrSimpleVecClass(IntPtr(&InternalVisDecompressionCacheClassPointer->Cache));
	}

	void VisDecompressionCacheClass::Cache::set(ISimpleVecClass<IVisTableClass^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalVisDecompressionCacheClassPointer->Cache = *reinterpret_cast<::SimpleVecClass<::VisTableClass*>*>(value->Pointer.ToPointer());
	}

	IMultiListClass<IVisTableClass^>^ VisDecompressionCacheClass::TableList::get()
	{
		return gcnew VisTableClassMultiListClass(IntPtr(&InternalVisDecompressionCacheClassPointer->tablelist));
	}

	int VisDecompressionCacheClass::TimeStamp::get()
	{
		return InternalVisDecompressionCacheClassPointer->timestamp;
	}

	void VisDecompressionCacheClass::TimeStamp::set(int value)
	{
		InternalVisDecompressionCacheClassPointer->timestamp = value;
	}

	bool VisDecompressionCacheClass::InternalDestroyPointer()
	{
		Imports::DestroyVisDecompressionCacheClass(InternalVisDecompressionCacheClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::VisDecompressionCacheClass* VisDecompressionCacheClass::InternalVisDecompressionCacheClassPointer::get()
	{
		return reinterpret_cast<::VisDecompressionCacheClass*>(Pointer.ToPointer());
	}

	VisTableMgrClass::VisTableMgrClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool VisTableMgrClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IVisTableMgrClass^ otherThis = dynamic_cast<IVisTableMgrClass^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return VisTableMgrClassPointer.Equals(otherThis->VisTableMgrClassPointer);
	}

	bool VisTableMgrClass::HasVisTable(int table)
	{
		if (table < 0 || table >= InternalVisTableMgrClassPointer->tables.Count())
		{
			throw gcnew ArgumentOutOfRangeException("table");
		}

		return InternalVisTableMgrClassPointer->Has_Vis_Table(table);
	}

	IntPtr VisTableMgrClass::VisTableMgrClassPointer::get()
	{
		return IntPtr(InternalVisTableMgrClassPointer);
	}

	int VisTableMgrClass::Count::get()
	{
		return InternalVisTableMgrClassPointer->count;
	}

	void VisTableMgrClass::Count::set(int value)
	{
		InternalVisTableMgrClassPointer->count = value;
	}

	int VisTableMgrClass::Size::get()
	{
		return InternalVisTableMgrClassPointer->size;
	}

	void VisTableMgrClass::Size::set(int value)
	{
		InternalVisTableMgrClassPointer->size = value;
	}

	ISimpleDynVecClass<ICompressedVisTableClass^>^ VisTableMgrClass::Tables::get()
	{
		return gcnew CompressedVisTableClassPtrSimpleDynVecClass(IntPtr(&InternalVisTableMgrClassPointer->tables));
	}

	void VisTableMgrClass::Tables::set(ISimpleDynVecClass<ICompressedVisTableClass^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		InternalVisTableMgrClassPointer->tables = *reinterpret_cast<::SimpleDynVecClass<::CompressedVisTableClass*>*>(value->Pointer.ToPointer());
	}

	IVisDecompressionCacheClass^ VisTableMgrClass::Cache::get()
	{
		auto result = InternalVisTableMgrClassPointer->cache;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew VisDecompressionCacheClass(IntPtr(result));
		}
	}

	void VisTableMgrClass::Cache::set(IVisDecompressionCacheClass^ value)
	{
		if (value == nullptr || value->VisDecompressionCacheClassPointer.ToPointer() == nullptr)
		{
			InternalVisTableMgrClassPointer->cache = nullptr;
		}
		else
		{
			InternalVisTableMgrClassPointer->cache = reinterpret_cast<::VisDecompressionCacheClass*>(value->VisDecompressionCacheClassPointer.ToPointer());
		}
	}

	int VisTableMgrClass::Frames::get()
	{
		return InternalVisTableMgrClassPointer->frames;
	}

	void VisTableMgrClass::Frames::set(int value)
	{
		InternalVisTableMgrClassPointer->frames = value;
	}

	::VisTableMgrClass* VisTableMgrClass::InternalVisTableMgrClassPointer::get()
	{
		return reinterpret_cast<::VisTableMgrClass*>(Pointer.ToPointer());
	}
}