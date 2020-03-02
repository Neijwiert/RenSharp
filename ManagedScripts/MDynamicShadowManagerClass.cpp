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
#include "MDynamicShadowManagerClass.h"

#include "MPhysClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <DynamicShadowManager.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
#pragma managed(push, off)

	class DynamicShadowManagerClassHelper : public ::DynamicShadowManagerClass
	{
		private:
			DynamicShadowManagerClassHelper() = default;

		public:
			::PhysClass &GetParent()
			{
				return Parent;
			}

			::DynTexProjectClass *&GetShadow()
			{
				return Shadow;
			}

			float &GetShadowNearZ()
			{
				return ShadowNearZ;
			}

			float &GetShadowFarZ()
			{
				return ShadowFarZ;
			}
	};

#pragma managed(pop)

	DynamicShadowManagerClass::DynamicShadowManagerClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool DynamicShadowManagerClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDynamicShadowManagerClass ^otherThis = dynamic_cast<IDynamicShadowManagerClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DynamicShadowManagerClassPointer.Equals(otherThis->DynamicShadowManagerClassPointer);
	}

	void DynamicShadowManagerClass::SetShadowPlanes(float zNear, float zFar)
	{
		InternalDynamicShadowManagerClassPointer->Set_Shadow_Planes(zNear, zFar);
	}

	void DynamicShadowManagerClass::SetShadowPlanes(float zNear)
	{
		InternalDynamicShadowManagerClassPointer->Set_Shadow_Planes(zNear);
	}

	void DynamicShadowManagerClass::SetShadowPlanes()
	{
		InternalDynamicShadowManagerClassPointer->Set_Shadow_Planes();
	}

	void DynamicShadowManagerClass::GetShadowPlanes([Out] float %zNear, [Out] float %zFar)
	{
		float tmpZNear;
		float tmpZFar;

		InternalDynamicShadowManagerClassPointer->Get_Shadow_Planes(&tmpZNear, &tmpZFar);

		zNear = tmpZNear;
		zFar = tmpZFar;
	}

	IntPtr DynamicShadowManagerClass::DynamicShadowManagerClassPointer::get()
	{
		return IntPtr(InternalDynamicShadowManagerClassPointer);
	}

	bool DynamicShadowManagerClass::ForceUseBlobBox::get()
	{
		return InternalDynamicShadowManagerClassPointer->Is_Force_Use_Blob_Box_Enabled();
	}

	void DynamicShadowManagerClass::ForceUseBlobBox::set(bool value)
	{
		InternalDynamicShadowManagerClassPointer->Enable_Force_Use_Blob_Box(value);
	}

	Vector3 DynamicShadowManagerClass::BlobBoxProjectionScale::get()
	{
		Vector3 result;

		Vector3::UnmanagedToManagedVector3(InternalDynamicShadowManagerClassPointer->Get_Blob_Box_Projection_Scale(), result);

		return result;
	}

	void DynamicShadowManagerClass::BlobBoxProjectionScale::set(Vector3 value)
	{
		::Vector3 tmp;

		Vector3::ManagedToUnmanagedVector3(value, tmp);

		InternalDynamicShadowManagerClassPointer->Set_Blob_Box_Projection_Scale(tmp);
	}

	bool DynamicShadowManagerClass::IsCastingShadow::get()
	{
		return InternalDynamicShadowManagerClassPointer->Is_Casting_Shadow();
	}

	::DynamicShadowManagerClass *DynamicShadowManagerClass::InternalDynamicShadowManagerClassPointer::get()
	{
		return reinterpret_cast<::DynamicShadowManagerClass *>(Pointer.ToPointer());
	}

	IPhysClass ^DynamicShadowManagerClass::Parent::get()
	{
		auto helper = reinterpret_cast<DynamicShadowManagerClassHelper *>(InternalDynamicShadowManagerClassPointer);

		auto &parent = helper->GetParent();

		return PhysClass::CreatePhysClassWrapper(&parent);
	}

	IntPtr DynamicShadowManagerClass::Shadow::get()
	{
		auto helper = reinterpret_cast<DynamicShadowManagerClassHelper *>(InternalDynamicShadowManagerClassPointer);

		auto &shadow = helper->GetShadow();

		return IntPtr(shadow);
	}

	void DynamicShadowManagerClass::Shadow::set(IntPtr value)
	{
		auto helper = reinterpret_cast<DynamicShadowManagerClassHelper *>(InternalDynamicShadowManagerClassPointer);

		auto &shadow = helper->GetShadow();

		shadow = reinterpret_cast<::DynTexProjectClass *>(value.ToPointer());
	}

	float DynamicShadowManagerClass::ShadowNearZ::get()
	{
		auto helper = reinterpret_cast<DynamicShadowManagerClassHelper *>(InternalDynamicShadowManagerClassPointer);

		auto &shadowNearZ = helper->GetShadowNearZ();

		return shadowNearZ;
	}

	void DynamicShadowManagerClass::ShadowNearZ::set(float value)
	{
		auto helper = reinterpret_cast<DynamicShadowManagerClassHelper *>(InternalDynamicShadowManagerClassPointer);

		auto &shadowNearZ = helper->GetShadowNearZ();

		shadowNearZ = value;
	}

	float DynamicShadowManagerClass::ShadowFarZ::get()
	{
		auto helper = reinterpret_cast<DynamicShadowManagerClassHelper *>(InternalDynamicShadowManagerClassPointer);

		auto &shadowFarZ = helper->GetShadowFarZ();

		return shadowFarZ;
	}

	void DynamicShadowManagerClass::ShadowFarZ::set(float value)
	{
		auto helper = reinterpret_cast<DynamicShadowManagerClassHelper *>(InternalDynamicShadowManagerClassPointer);

		auto &shadowFarZ = helper->GetShadowFarZ();

		shadowFarZ = value;
	}
}