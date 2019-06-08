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
#include "MCombatManager.h"

#include "Imports.h"
#include "MArmedGameObj.h"
#include "MPhysicalGameObj.h"
#include "MSoldierGameObj.h"

namespace RenSharp
{
	CombatNetworkHandlerClass::CombatNetworkHandlerClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool CombatNetworkHandlerClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		ICombatNetworkHandlerClass^ otherThis = dynamic_cast<ICombatNetworkHandlerClass^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return CombatNetworkHandlerClassPointer.Equals(otherThis->CombatNetworkHandlerClassPointer);
	}

	bool CombatNetworkHandlerClass::CanDamage(IArmedGameObj^ armedDamager, IPhysicalGameObj^ physVictim)
	{
		if (physVictim == nullptr || physVictim->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("physVictim");
		}

		if (armedDamager == nullptr || armedDamager->ArmedGameObjPointer.ToPointer() == nullptr)
		{
			return InternalCombatNetworkHandlerClassPointer->Can_Damage(
				nullptr,
				reinterpret_cast<::PhysicalGameObj*>(physVictim->PhysicalGameObjPointer.ToPointer()));
		}
		else
		{
			return InternalCombatNetworkHandlerClassPointer->Can_Damage(
				reinterpret_cast<::ArmedGameObj*>(armedDamager->ArmedGameObjPointer.ToPointer()),
				reinterpret_cast<::PhysicalGameObj*>(physVictim->PhysicalGameObjPointer.ToPointer()));
		}
	}

	float CombatNetworkHandlerClass::GetDamageFactor(IArmedGameObj^ armedDamager, IPhysicalGameObj^ physVictim)
	{
		if (physVictim == nullptr || physVictim->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("physVictim");
		}

		if (armedDamager == nullptr || armedDamager->ArmedGameObjPointer.ToPointer() == nullptr)
		{
			return InternalCombatNetworkHandlerClassPointer->Get_Damage_Factor(
				nullptr,
				reinterpret_cast<::PhysicalGameObj*>(physVictim->PhysicalGameObjPointer.ToPointer()));
		}
		else
		{
			return InternalCombatNetworkHandlerClassPointer->Get_Damage_Factor(
				reinterpret_cast<::ArmedGameObj*>(armedDamager->ArmedGameObjPointer.ToPointer()),
				reinterpret_cast<::PhysicalGameObj*>(physVictim->PhysicalGameObjPointer.ToPointer()));
		}
	}

	void CombatNetworkHandlerClass::OnSoldierKill(ISoldierGameObj^ soldier, ISoldierGameObj^ victim)
	{
		if (soldier == nullptr || soldier->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}
		else if (victim == nullptr || victim->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("victim");
		}

		InternalCombatNetworkHandlerClassPointer->On_Soldier_Kill(
			reinterpret_cast<::SoldierGameObj*>(soldier->SoldierGameObjPointer.ToPointer()),
			reinterpret_cast<::SoldierGameObj*>(victim->SoldierGameObjPointer.ToPointer()));
	}

	void CombatNetworkHandlerClass::OnSoldierDeath(ISoldierGameObj^ soldier)
	{
		if (soldier == nullptr || soldier->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("soldier");
		}

		InternalCombatNetworkHandlerClassPointer->On_Soldier_Death(
			reinterpret_cast<::SoldierGameObj*>(soldier->SoldierGameObjPointer.ToPointer()));
	}

	bool CombatNetworkHandlerClass::IsGameplayPermitted()
	{
		return InternalCombatNetworkHandlerClassPointer->Is_Gameplay_Permitted();
	}

	IntPtr CombatNetworkHandlerClass::CombatNetworkHandlerClassPointer::get()
	{
		return IntPtr(InternalCombatNetworkHandlerClassPointer);
	}

	bool CombatNetworkHandlerClass::InternalDestroyPointer()
	{
		Imports::DestroyCombatNetworkHandlerClass(InternalCombatNetworkHandlerClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::CombatNetworkHandlerClass* CombatNetworkHandlerClass::InternalCombatNetworkHandlerClassPointer::get()
	{
		return reinterpret_cast<::CombatNetworkHandlerClass*>(Pointer.ToPointer());
	}

	CombatMiscHandlerClass::CombatMiscHandlerClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool CombatMiscHandlerClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		ICombatMiscHandlerClass^ otherThis = dynamic_cast<ICombatMiscHandlerClass^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return CombatMiscHandlerClassPointer.Equals(otherThis->CombatMiscHandlerClassPointer);
	}

	void CombatMiscHandlerClass::MissionComplete(bool success)
	{
		InternalCombatMiscHandlerClassPointer->Mission_Complete(success);
	}

	void CombatMiscHandlerClass::StarKilled()
	{
		InternalCombatMiscHandlerClassPointer->Star_Killed();
	}

	IntPtr CombatMiscHandlerClass::CombatMiscHandlerClassPointer::get()
	{
		return IntPtr(InternalCombatMiscHandlerClassPointer);
	}

	bool CombatMiscHandlerClass::InternalDestroyPointer()
	{
		Imports::DestroyCombatMiscHandlerClass(InternalCombatMiscHandlerClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::CombatMiscHandlerClass* CombatMiscHandlerClass::InternalCombatMiscHandlerClassPointer::get()
	{
		return reinterpret_cast<::CombatMiscHandlerClass*>(Pointer.ToPointer());
	}

	bool CombatManager::IsGameplayPermitted::get()
	{
		return ::CombatManager::Is_Gameplay_Permitted();
	}
}