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
#include "MBaseGameObj.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <BaseGameObj.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MBaseGameObjDef.h"
#include "MPhysicalGameObj.h"
#include "MVehicleGameObj.h"
#include "MSmartGameObj.h"
#include "MScriptableGameObj.h"

namespace RenSharp
{
	BaseGameObj::BaseGameObj(IntPtr pointer)
		: NetworkObjectClass(pointer)
	{
		persistClass = gcnew PersistClass(IntPtr(InternalPersistClassPointer));
	}

	bool BaseGameObj::Equals(Object ^other)
	{
		if (NetworkObjectClass::Equals(other))
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

		auto otherPostLoadableClass = dynamic_cast<IPostLoadableClass^>(other);
		if (otherPostLoadableClass != nullptr)
		{
			if (persistClass->Equals(otherPostLoadableClass))
			{
				return true;
			}
		}

		auto otherBaseGameObj = dynamic_cast<IBaseGameObj ^>(other);
		if (otherBaseGameObj != nullptr)
		{
			if (BaseGameObjPointer.Equals(otherBaseGameObj->BaseGameObjPointer))
			{
				return true;
			}
		}

		return false;
	}

	void BaseGameObj::OnPostLoad()
	{
		persistClass->OnPostLoad();
	}

	bool BaseGameObj::Save(IChunkSaveClass ^csave)
	{
		return persistClass->Save(csave);
	}

	bool BaseGameObj::Load(IChunkLoadClass ^cload)
	{
		return persistClass->Load(cload);
	}

	void BaseGameObj::Think()
	{
		InternalBaseGameObjPointer->Think();
	}

	void BaseGameObj::PostThink()
	{
		InternalBaseGameObjPointer->Post_Think();
	}

	IPhysicalGameObj ^BaseGameObj::AsPhysicalGameObj()
	{
		auto result = InternalBaseGameObjPointer->As_PhysicalGameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PhysicalGameObj(IntPtr(result));
		}
	}

	IVehicleGameObj ^BaseGameObj::AsVehicleGameObj()
	{
		auto result = InternalBaseGameObjPointer->As_VehicleGameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew VehicleGameObj(IntPtr(result));
		}
	}

	ISmartGameObj ^BaseGameObj::AsSmartGameObj()
	{
		auto result = InternalBaseGameObjPointer->As_SmartGameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew SmartGameObj(IntPtr(result));
		}
	}

	IScriptableGameObj ^BaseGameObj::AsScriptableGameObj()
	{
		auto result = InternalBaseGameObjPointer->As_ScriptableGameObj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew ScriptableGameObj(IntPtr(result));
		}
	}

	IntPtr BaseGameObj::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void BaseGameObj::Pointer::set(IntPtr value)
	{
		AbstractUnmanagedObject::Pointer::set(value);

		if (Pointer == IntPtr::Zero)
		{
			persistClass = nullptr;
		}
		else
		{
			persistClass = gcnew PersistClass(IntPtr(InternalPersistClassPointer));
		}
	}

	IntPtr BaseGameObj::PostLoadableClassPointer::get()
	{
		return IntPtr(InternalPostLoadableClassPointer);
	}

	IntPtr BaseGameObj::PersistClassPointer::get()
	{
		return IntPtr(InternalPersistClassPointer);
	}

	IntPtr BaseGameObj::BaseGameObjPointer::get()
	{
		return IntPtr(InternalBaseGameObjPointer);
	}

	bool BaseGameObj::IsPostLoadRegistered::get()
	{
		return persistClass->IsPostLoadRegistered;
	}

	void BaseGameObj::IsPostLoadRegistered::set(bool value)
	{
		persistClass->IsPostLoadRegistered = value;
	}

	IPersistFactoryClass ^BaseGameObj::Factory::get()
	{
		return persistClass->Factory;
	}

	IBaseGameObjDef ^BaseGameObj::Definition::get()
	{
		return gcnew BaseGameObjDef(IntPtr(const_cast<::BaseGameObjDef *>(&InternalBaseGameObjPointer->Get_Definition())));
	}

	bool BaseGameObj::IsHibernating::get()
	{
		return InternalBaseGameObjPointer->Is_Hibernating();
	}

	int BaseGameObj::ID::get()
	{
		return InternalBaseGameObjPointer->Get_ID();
	}

	bool BaseGameObj::IsPostThinkAllowed::get()
	{
		return InternalBaseGameObjPointer->Is_Post_Think_Allowed();
	}

	void BaseGameObj::IsPostThinkAllowed::set(bool value)
	{
		InternalBaseGameObjPointer->IsPostThinkAllowed = value;
	}

	bool BaseGameObj::EnableCinematicFreeze::get()
	{
		return InternalBaseGameObjPointer->Is_Cinematic_Freeze_Enabled();
	}

	void BaseGameObj::EnableCinematicFreeze::set(bool value)
	{
		InternalBaseGameObjPointer->Enable_Cinematic_Freeze(value);
	}

	::NetworkObjectClass *BaseGameObj::InternalNetworkObjectClassPointer::get()
	{
		return InternalBaseGameObjPointer;
	}

	::PostLoadableClass *BaseGameObj::InternalPostLoadableClassPointer::get()
	{
		return InternalBaseGameObjPointer;
	}

	::PersistClass *BaseGameObj::InternalPersistClassPointer::get()
	{
		return InternalBaseGameObjPointer;
	}

	::BaseGameObj *BaseGameObj::InternalBaseGameObjPointer::get()
	{
		return reinterpret_cast<::BaseGameObj *>(Pointer.ToPointer());
	}
}