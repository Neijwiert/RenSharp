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
#include "MCullSystemClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <CullSystemClass.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MVector3.h"
#include "MAABoxClass.h"
#include "Mobboxclass.h"
#include "MFrustumClass.h"
#include "MCullableClass.h"
#include "Imports.h"

namespace RenSharp
{

#pragma managed(push, off)

	class CullSystemClassHelper : public ::CullSystemClass
	{
		private:
			CullSystemClassHelper() = default;

		public:
			::CullableClass *&GetCollectionHead()
			{
				return CollectionHead;
			}
	};

#pragma managed(pop)

	CullSystemClass::CullSystemClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool CullSystemClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		ICullSystemClass ^otherThis = dynamic_cast<ICullSystemClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return CullSystemClassPointer.Equals(otherThis->CullSystemClassPointer);
	}

	void CullSystemClass::CollectObjects(Vector3 point)
	{
		::Vector3 pointVec;
		Vector3::ManagedToUnmanagedVector3(point, pointVec);

		InternalCullSystemClassPointer->Collect_Objects(pointVec);
	}

	void CullSystemClass::CollectObjects(AABoxClass box)
	{
		::AABoxClass bBox;

		AABoxClass::ManagedToUnmanagedAABoxClass(box, bBox);

		InternalCullSystemClassPointer->Collect_Objects(bBox);
	}

	void CullSystemClass::CollectObjects(OBBoxClass box)
	{
		::OBBoxClass bBox;

		OBBoxClass::ManagedToUnmanagedOBBoxClass(box, bBox);

		InternalCullSystemClassPointer->Collect_Objects(bBox);
	}

	void CullSystemClass::CollectObjects(FrustumClass frustum)
	{
		::FrustumClass fFrustum;

		FrustumClass::ManagedToUnmanagedFrustumClass(frustum, fFrustum);

		InternalCullSystemClassPointer->Collect_Objects(fFrustum);
	}

	void CullSystemClass::UpdateCulling(ICullableClass ^obj)
	{
		if (obj == nullptr || obj->CullableClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalCullSystemClassPointer->Update_Culling(reinterpret_cast<::CullableClass *>(obj->CullableClassPointer.ToPointer()));
	}

	IntPtr CullSystemClass::CullSystemClassPointer::get()
	{
		return IntPtr(InternalCullSystemClassPointer);
	}

	bool CullSystemClass::InternalDestroyPointer()
	{
		Imports::DestroyCullSystemClass(InternalCullSystemClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::CullSystemClass *CullSystemClass::InternalCullSystemClassPointer::get()
	{
		return reinterpret_cast<::CullSystemClass *>(Pointer.ToPointer());
	}

	ICullableClass ^CullSystemClass::CollectionHead::get()
	{
		auto helper = reinterpret_cast<CullSystemClassHelper *>(InternalCullSystemClassPointer);

		auto &collectionHead = helper->GetCollectionHead();

		if (collectionHead == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew CullableClass(IntPtr(collectionHead));
		}
	}

	void CullSystemClass::CollectionHead::set(ICullableClass ^value)
	{
		auto helper = reinterpret_cast<CullSystemClassHelper *>(InternalCullSystemClassPointer);

		auto &collectionHead = helper->GetCollectionHead();

		if (value == nullptr || value->CullableClassPointer.ToPointer() == nullptr)
		{
			collectionHead = nullptr;
		}
		else
		{
			collectionHead = reinterpret_cast<::CullableClass *>(value->CullableClassPointer.ToPointer());
		}
	}
}