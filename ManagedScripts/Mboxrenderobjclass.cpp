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
#include "Mboxrenderobjclass.h"

#include "MVector3.h"
#include "Mobboxclass.h"
#include "MAABoxClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <boxrenderobjclass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{

#pragma managed(push, off)

	class BoxRenderObjClassHelper : public ::BoxRenderObjClass
	{
		private:
			BoxRenderObjClassHelper() = default;

		public:
			::Vector3 &GetColor()
			{
				return Color;
			}

			::Vector3 &GetObjSpaceCenter()
			{
				return ObjSpaceCenter;
			}

			::Vector3 &GetObjSpaceExtent()
			{
				return ObjSpaceExtent;
			}

			float &GetOpacity()
			{
				return Opacity;
			}
	};

#pragma managed(pop)

	BoxRenderObjClass::BoxRenderObjClass(IntPtr pointer)
		: RenderObjClass(pointer)
	{

	}

	void BoxRenderObjClass::UpdateCachedBox()
	{
		InternalBoxRenderObjClassPointer->update_cached_box();
	}

	void BoxRenderObjClass::SetOpacity(float opacity)
	{
		InternalBoxRenderObjClassPointer->Set_Opacity(opacity);
	}

	void BoxRenderObjClass::SetLocalCenterExtent(Vector3 center, Vector3 extent)
	{
		::Vector3 centerVec;
		::Vector3 extentVec;

		Vector3::ManagedToUnmanagedVector3(center, centerVec);
		Vector3::ManagedToUnmanagedVector3(extent, extentVec);

		InternalBoxRenderObjClassPointer->Set_Local_Center_Extent(centerVec, extentVec);
	}

	IntPtr BoxRenderObjClass::BoxRenderObjClassPointer::get()
	{
		return IntPtr(InternalBoxRenderObjClassPointer);
	}

	Vector3 BoxRenderObjClass::ObjSpaceCenter::get()
	{
		Vector3 result;

		Vector3::UnmanagedToManagedVector3(InternalBoxRenderObjClassPointer->Get_Local_Center(), result);

		return result;
	}

	void BoxRenderObjClass::ObjSpaceCenter::set(Vector3 value)
	{
		auto helper = reinterpret_cast<BoxRenderObjClassHelper *>(InternalBoxRenderObjClassPointer);

		auto &objSpaceCenter = helper->GetObjSpaceCenter();

		Vector3::ManagedToUnmanagedVector3(value, objSpaceCenter);
	}

	Vector3 BoxRenderObjClass::ObjSpaceExtent::get()
	{
		Vector3 result;

		Vector3::UnmanagedToManagedVector3(InternalBoxRenderObjClassPointer->Get_Local_Extent(), result);

		return result;
	}

	void BoxRenderObjClass::ObjSpaceExtent::set(Vector3 value)
	{
		auto helper = reinterpret_cast<BoxRenderObjClassHelper *>(InternalBoxRenderObjClassPointer);

		auto &objSpaceExtent = helper->GetObjSpaceExtent();

		Vector3::ManagedToUnmanagedVector3(value, objSpaceExtent);
	}

	::RenderObjClass *BoxRenderObjClass::InternalRenderObjClassPointer::get()
	{
		return InternalBoxRenderObjClassPointer;
	}

	::BoxRenderObjClass *BoxRenderObjClass::InternalBoxRenderObjClassPointer::get()
	{
		return reinterpret_cast<::BoxRenderObjClass *>(Pointer.ToPointer());
	}

	Color BoxRenderObjClass::Color::get()
	{
		auto helper = reinterpret_cast<BoxRenderObjClassHelper *>(InternalBoxRenderObjClassPointer);

		auto &color = helper->GetColor();

		int r = static_cast<int>(color.X * 255.0f);
		int g = static_cast<int>(color.Y * 255.0f);
		int b = static_cast<int>(color.Z * 255.0f);

		return Drawing::Color::FromArgb(255, r, g, b);
	}

	void BoxRenderObjClass::Color::set(Drawing::Color value)
	{
		auto helper = reinterpret_cast<BoxRenderObjClassHelper *>(InternalBoxRenderObjClassPointer);

		auto &color = helper->GetColor();

		color.X = value.R / 255.0f;
		color.Y = value.G / 255.0f;
		color.Z = value.B / 255.0f;
	}

	float BoxRenderObjClass::Opacity::get()
	{
		auto helper = reinterpret_cast<BoxRenderObjClassHelper *>(InternalBoxRenderObjClassPointer);

		auto &opacity = helper->GetOpacity();

		return opacity;
	}

	void BoxRenderObjClass::Opacity::set(float value)
	{
		auto helper = reinterpret_cast<BoxRenderObjClassHelper *>(InternalBoxRenderObjClassPointer);

		auto &opacity = helper->GetOpacity();

		opacity = value;
	}

	OBBoxRenderObjClass::OBBoxRenderObjClass(IntPtr pointer)
		: BoxRenderObjClass(pointer)
	{

	}

	IntPtr OBBoxRenderObjClass::OBBoxRenderObjClassPointer::get()
	{
		return IntPtr(InternalOBBoxRenderObjClassPointer);
	}

	OBBoxClass OBBoxRenderObjClass::CachedBox::get()
	{
		OBBoxClass result;

		OBBoxClass::UnmanagedToManagedOBBoxClass(InternalOBBoxRenderObjClassPointer->CachedBox, result);

		return result;
	}

	void OBBoxRenderObjClass::CachedBox::set(OBBoxClass value)
	{
		OBBoxClass::ManagedToUnmanagedOBBoxClass(value, InternalOBBoxRenderObjClassPointer->CachedBox);
	}

	OBBoxClass OBBoxRenderObjClass::Box::get()
	{
		OBBoxClass result;

		OBBoxClass::UnmanagedToManagedOBBoxClass(InternalOBBoxRenderObjClassPointer->Get_Box(), result);

		return result;
	}

	::BoxRenderObjClass *OBBoxRenderObjClass::InternalBoxRenderObjClassPointer::get()
	{
		return InternalOBBoxRenderObjClassPointer;
	}

	::OBBoxRenderObjClass *OBBoxRenderObjClass::InternalOBBoxRenderObjClassPointer::get()
	{
		return reinterpret_cast<::OBBoxRenderObjClass *>(Pointer.ToPointer());
	}

	AABoxRenderObjClass::AABoxRenderObjClass(IntPtr pointer)
		: BoxRenderObjClass(pointer)
	{

	}

	IntPtr AABoxRenderObjClass::AABoxRenderObjClassPointer::get()
	{
		return IntPtr(InternalAABoxRenderObjClassPointer);
	}

	AABoxClass AABoxRenderObjClass::CachedBox::get()
	{
		AABoxClass result;

		AABoxClass::UnmanagedToManagedAABoxClass(InternalAABoxRenderObjClassPointer->CachedBox, result);

		return result;
	}

	void AABoxRenderObjClass::CachedBox::set(AABoxClass value)
	{
		AABoxClass::ManagedToUnmanagedAABoxClass(value, InternalAABoxRenderObjClassPointer->CachedBox);
	}

	AABoxClass AABoxRenderObjClass::Box::get()
	{
		AABoxClass result;

		AABoxClass::UnmanagedToManagedAABoxClass(InternalAABoxRenderObjClassPointer->Get_Box(), result);

		return result;
	}

	::BoxRenderObjClass *AABoxRenderObjClass::InternalBoxRenderObjClassPointer::get()
	{
		return InternalAABoxRenderObjClassPointer;
	}

	::AABoxRenderObjClass *AABoxRenderObjClass::InternalAABoxRenderObjClassPointer::get()
	{
		return reinterpret_cast<::AABoxRenderObjClass *>(Pointer.ToPointer());
	}

	BoxLoaderClass::BoxLoaderClass(IntPtr pointer)
		: PrototypeLoaderClass(pointer)
	{

	}

	IntPtr BoxLoaderClass::BoxLoaderClassPointer::get()
	{
		return IntPtr(InternalBoxLoaderClassPointer);
	}

	bool BoxLoaderClass::InternalDestroyPointer()
	{
		return false;
	}

	::PrototypeLoaderClass *BoxLoaderClass::InternalPrototypeLoaderClassPointer::get()
	{
		return InternalBoxLoaderClassPointer;
	}

	::BoxLoaderClass *BoxLoaderClass::InternalBoxLoaderClassPointer::get()
	{
		return reinterpret_cast<::BoxLoaderClass *>(Pointer.ToPointer());
	}
}