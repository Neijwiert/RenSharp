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
#include "MMaterialEffectClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <MaterialEffectClass.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MPhysClass.h"

namespace RenSharp
{
	MaterialEffectClass::MaterialEffectClass(IntPtr pointer)
		: RefCountClass(pointer)
	{
		multiListObjectClass = gcnew MultiListObjectClass(IntPtr(InternalMultiListObjectClassPointer));
	}

	bool MaterialEffectClass::Equals(Object ^other)
	{
		if (RefCountClass::Equals(other))
		{
			return true;
		}

		if (ReferenceEquals(other, nullptr))
		{
			return false;
		}

		auto otherUnmanagedObj = dynamic_cast<IUnmanagedObject ^>(other);
		if (otherUnmanagedObj == nullptr || otherUnmanagedObj->Pointer.Equals(IntPtr::Zero))
		{
			return false;
		}

		auto otherMultiListObjectClass = dynamic_cast<IMultiListObjectClass ^>(other);
		if (otherMultiListObjectClass != nullptr)
		{
			if (multiListObjectClass->Equals(otherMultiListObjectClass))
			{
				return true;
			}
		}

		auto otherMaterialEffectClass = dynamic_cast<IMaterialEffectClass ^>(other);
		if (otherMaterialEffectClass != nullptr)
		{
			if (MaterialEffectClassPointer.Equals(otherMaterialEffectClass->MaterialEffectClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void MaterialEffectClass::Timestep(float dt)
	{
		InternalMaterialEffectClassPointer->Timestep(dt);
	}

	void MaterialEffectClass::RenderPush(IntPtr rinfo, IPhysClass ^obj)
	{
		if (rinfo.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("rinfo");
		}
		else if (obj == nullptr || obj->PhysClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("obj");
		}

		InternalMaterialEffectClassPointer->Render_Push(*reinterpret_cast<::RenderInfoClass *>(rinfo.ToPointer()), reinterpret_cast<::PhysClass *>(obj->PhysClassPointer.ToPointer()));
	}

	void MaterialEffectClass::RenderPop(IntPtr rinfo)
	{
		if (rinfo.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("rinfo");
		}

		InternalMaterialEffectClassPointer->Render_Pop(*reinterpret_cast<::RenderInfoClass *>(rinfo.ToPointer()));
	}

	IntPtr MaterialEffectClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void MaterialEffectClass::Pointer::set(IntPtr value)
	{
		AbstractUnmanagedObject::Pointer::set(value);

		if (Pointer == IntPtr::Zero)
		{
			multiListObjectClass = nullptr;
		}
		else
		{
			multiListObjectClass = gcnew MultiListObjectClass(IntPtr(InternalMultiListObjectClassPointer));
		}
	}

	IntPtr MaterialEffectClass::MultiListObjectClassPointer::get()
	{
		return IntPtr(InternalMultiListObjectClassPointer);
	}

	IntPtr MaterialEffectClass::MaterialEffectClassPointer::get()
	{
		return IntPtr(InternalMaterialEffectClassPointer);
	}

	IMultiListNodeClass ^MaterialEffectClass::ListNode::get()
	{
		return multiListObjectClass->ListNode;
	}

	void MaterialEffectClass::ListNode::set(IMultiListNodeClass ^value)
	{
		multiListObjectClass->ListNode = value;
	}

	bool MaterialEffectClass::AutoRemoveEnabled::get()
	{
		return InternalMaterialEffectClassPointer->Is_Auto_Remove_Enabled();
	}

	void MaterialEffectClass::AutoRemoveEnabled::set(bool value)
	{
		InternalMaterialEffectClassPointer->Enable_Auto_Remove(value);
	}

	bool MaterialEffectClass::SuppressShadows::get()
	{
		return InternalMaterialEffectClassPointer->Are_Shadows_Suppressed();
	}

	void MaterialEffectClass::SuppressShadows::set(bool value)
	{
		InternalMaterialEffectClassPointer->Enable_Suppress_Shadows(value);
	}

	::RefCountClass *MaterialEffectClass::InternalRefCountClassPointer::get()
	{
		return InternalMaterialEffectClassPointer;
	}

	::MultiListObjectClass *MaterialEffectClass::InternalMultiListObjectClassPointer::get()
	{
		return InternalMaterialEffectClassPointer;
	}

	::MaterialEffectClass *MaterialEffectClass::InternalMaterialEffectClassPointer::get()
	{
		return reinterpret_cast<::MaterialEffectClass *>(Pointer.ToPointer());
	}
}