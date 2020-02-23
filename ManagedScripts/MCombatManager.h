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

#pragma once

#include "AbstractUnmanagedObject.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454 4091)
#include <CombatManager.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	interface class IArmedGameObj;
	interface class IPhysicalGameObj;
	interface class ISoldierGameObj;

	public interface class ICombatNetworkHandlerClass : public IUnmanagedObject
	{
		bool CanDamage(IArmedGameObj^ armedDamager, IPhysicalGameObj^ physVictim);

		float GetDamageFactor(IArmedGameObj^ armedDamager, IPhysicalGameObj^ physVictim);

		void OnSoldierKill(ISoldierGameObj^ soldier, ISoldierGameObj^ victim);

		void OnSoldierDeath(ISoldierGameObj^ soldier);

		bool IsGameplayPermitted();

		property IntPtr CombatNetworkHandlerClassPointer
		{
			IntPtr get();
		}
	};

	public ref class CombatNetworkHandlerClass : public AbstractUnmanagedObject, public ICombatNetworkHandlerClass
	{
		public:
			CombatNetworkHandlerClass(IntPtr pointer);

			bool Equals(Object^ other) override;

			virtual bool CanDamage(IArmedGameObj^ armedDamager, IPhysicalGameObj^ physVictim) sealed;
			virtual float GetDamageFactor(IArmedGameObj^ armedDamager, IPhysicalGameObj^ physVictim) sealed;
			virtual void OnSoldierKill(ISoldierGameObj^ soldier, ISoldierGameObj^ victim) sealed;
			virtual void OnSoldierDeath(ISoldierGameObj^ soldier) sealed;
			virtual bool IsGameplayPermitted() sealed;

			property IntPtr CombatNetworkHandlerClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::CombatNetworkHandlerClass* InternalCombatNetworkHandlerClassPointer
			{
				virtual ::CombatNetworkHandlerClass* get();
			}
	};

	public interface class ICombatMiscHandlerClass : public IUnmanagedObject
	{
		void MissionComplete(bool success);

		void StarKilled();

		property IntPtr CombatMiscHandlerClassPointer
		{
			IntPtr get();
		}
	};

	public ref class CombatMiscHandlerClass : public AbstractUnmanagedObject, public ICombatMiscHandlerClass
	{
		public:
			CombatMiscHandlerClass(IntPtr pointer);

			bool Equals(Object^ other) override;

			virtual void MissionComplete(bool success) sealed;
			virtual void StarKilled() sealed;

			property IntPtr CombatMiscHandlerClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::CombatMiscHandlerClass* InternalCombatMiscHandlerClassPointer
			{
				virtual ::CombatMiscHandlerClass* get();
			}
	};

	public ref class CombatManager abstract sealed
	{
		public:
			enum class CombatMode : int
			{
				CombatModeNone = ::CombatManager::COMBAT_MODE_NONE,
				CombatModeFirstPerson = ::CombatManager::COMBAT_MODE_FIRST_PERSON,
				CombatModeThirdPerson = ::CombatManager::COMBAT_MODE_THIRD_PERSON,
				CombatModeSniping = ::CombatManager::COMBAT_MODE_SNIPING,
				CombatModeInVehicle = ::CombatManager::COMBAT_MODE_IN_VEHICLE,
				CombatModeOnLadder = ::CombatManager::COMBAT_MODE_ON_LADDER,
				CombatModeDieing = ::CombatManager::COMBAT_MODE_DIEING,
				CombatModeCorpse = ::CombatManager::COMBAT_MODE_CORPSE,
				CombatModeSnapShot = ::CombatManager::COMBAT_MODE_SNAP_SHOT
			};

			static property bool IsGameplayPermitted
			{
				bool get();
			}
	};
}