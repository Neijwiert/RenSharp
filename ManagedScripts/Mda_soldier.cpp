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
#include "Mda_soldier.h"

#include "MUInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass.h"
#include "MUInt32ConstWeaponDefinitionClassPtrHashTemplateClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4091 4251 4244 26495 26454)
#include <da_soldier.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DASoldierManager::DASoldierManager(IntPtr pointer)
		: DAEventClass(pointer)
	{

	}

	IntPtr DASoldierManager::DASoldierManagerPointer::get()
	{
		return IntPtr(InternalDASoldierManagerPointer);
	}

	IHashTemplateClass<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^>^ DASoldierManager::ExclusiveWeapons::get()
	{
		return gcnew UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass(IntPtr(&::DASoldierManager::Get_Exclusive_Weapons()));
	}

	IHashTemplateClass<unsigned int, IWeaponDefinitionClass^>^ DASoldierManager::ReplaceWeapons::get()
	{
		return gcnew UInt32ConstWeaponDefinitionClassPtrHashTemplateClass(IntPtr(&::DASoldierManager::Get_Replace_Weapons()));
	}

	IHashTemplateClass<unsigned int, IDynamicVectorClass<IWeaponDefinitionClass^>^>^ DASoldierManager::RemoveWeapons::get()
	{
		return gcnew UInt32ConstWeaponDefinitionClassPtrDynamicVectorClassHashTemplateClass(IntPtr(&::DASoldierManager::Get_Remove_Weapons()));
	}

	::DAEventClass* DASoldierManager::InternalDAEventClassPointer::get()
	{
		return InternalDASoldierManagerPointer;
	}

	::DASoldierManager* DASoldierManager::InternalDASoldierManagerPointer::get()
	{
		return reinterpret_cast<::DASoldierManager*>(Pointer.ToPointer());
	}
}