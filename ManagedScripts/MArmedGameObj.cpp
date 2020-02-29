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
#include "MArmedGameObj.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <ArmedGameObj.h>
#include <ArmedGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MArmedGameObjDef.h"
#include "MWeaponClass.h"
#include "MMatrix3D.h"
#include "MVector3.h"
#include "MWeaponBagClass.h"

namespace RenSharp
{

#pragma managed(push, off)

	class ArmedGameObjHelper : public ::ArmedGameObj
	{
		private:
			ArmedGameObjHelper() = default;

		public:
			::WeaponBagClass *&GetWeaponBag()
			{
				return WeaponBag;
			}
	};

#pragma managed(pop)

	ArmedGameObj::ArmedGameObj(IntPtr pointer)
		: PhysicalGameObj(pointer)
	{

	}

	IArmedGameObj ^ArmedGameObj::AsArmedGameObj()
	{
		return this;
	}

	void ArmedGameObj::ImportStateCs(IntPtr packet)
	{
		if (packet.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("packet");
		}

		InternalArmedGameObjPointer->Import_State_Cs(*reinterpret_cast<::BitStreamClass *>(packet.ToPointer()));
	}

	void ArmedGameObj::ExportStateCs(IntPtr packet)
	{
		if (packet.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("packet");
		}

		InternalArmedGameObjPointer->Export_State_Cs(*reinterpret_cast<::BitStreamClass *>(packet.ToPointer()));
	}

	Matrix3D ArmedGameObj::GetMuzzle(int index)
	{
		if (index < 0 || index <= IArmedGameObj::MaxMuzzles)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		Matrix3D result;
		Matrix3D::UnmanagedToManagedMatrix3D(InternalArmedGameObjPointer->Get_Muzzle(index), result);

		return result;
	}

	Matrix3D ArmedGameObj::GetMuzzle()
	{
		Matrix3D result;
		Matrix3D::UnmanagedToManagedMatrix3D(InternalArmedGameObjPointer->Get_Muzzle(), result);

		return result;
	}

	bool ArmedGameObj::SetTargeting(Vector3 pos, bool doTilt)
	{
		::Vector3 posVec;

		Vector3::ManagedToUnmanagedVector3(pos, posVec);

		return InternalArmedGameObjPointer->Set_Targeting(posVec, doTilt);
	}

	bool ArmedGameObj::SetTargeting(Vector3 pos)
	{
		::Vector3 posVec;

		Vector3::ManagedToUnmanagedVector3(pos, posVec);

		return InternalArmedGameObjPointer->Set_Targeting(posVec);
	}

	bool ArmedGameObj::IsRecoiling(int index)
	{
		if (index < 0 || index <= IArmedGameObj::MaxMuzzles)
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		return InternalArmedGameObjPointer->Is_Recoiling(index);
	}

	IntPtr ArmedGameObj::ArmedGameObjPointer::get()
	{
		return IntPtr(InternalArmedGameObjPointer);
	}

	IArmedGameObjDef ^ArmedGameObj::Definition::get()
	{
		auto result = DefinitionClass::CreateDefinitionClassWrapper(&InternalArmedGameObjPointer->Get_Definition());
		if (result != nullptr)
		{
			return safe_cast<IArmedGameObjDef^>(result);
		}

		return gcnew ArmedGameObjDef(IntPtr(const_cast<::ArmedGameObjDef *>(&InternalArmedGameObjPointer->Get_Definition())));
	}

	IWeaponClass ^ArmedGameObj::Weapon::get()
	{
		auto result = InternalArmedGameObjPointer->Get_Weapon();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew WeaponClass(IntPtr(result));
		}
	}

	IWeaponBagClass ^ArmedGameObj::WeaponBag::get()
	{
		auto result = InternalArmedGameObjPointer->Get_Weapon_Bag();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew WeaponBagClass(IntPtr(result));
		}
	}

	void ArmedGameObj::WeaponBag::set(IWeaponBagClass ^value)
	{
		auto helper = reinterpret_cast<ArmedGameObjHelper *>(InternalArmedGameObjPointer);

		auto &weaponBag = helper->GetWeaponBag();

		if (value == nullptr || value->WeaponBagClassPointer.ToPointer() == nullptr)
		{
			weaponBag = nullptr;
		}
		else
		{
			weaponBag = reinterpret_cast<::WeaponBagClass *>(value->WeaponBagClassPointer.ToPointer());
		}
	}

	float ArmedGameObj::WeaponError::get()
	{
		return InternalArmedGameObjPointer->Get_Weapon_Error();
	}

	Vector3 ArmedGameObj::TargetingPos::get()
	{
		Vector3 result;
		Vector3::UnmanagedToManagedVector3(InternalArmedGameObjPointer->Get_Targeting_Pos(), result);

		return result;
	}

	::PhysicalGameObj *ArmedGameObj::InternalPhysicalGameObjPointer::get()
	{
		return InternalArmedGameObjPointer;
	}

	::ArmedGameObj *ArmedGameObj::InternalArmedGameObjPointer::get()
	{
		return reinterpret_cast<::ArmedGameObj *>(Pointer.ToPointer());
	}
}