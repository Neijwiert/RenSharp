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

#pragma once

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <ArmorWarheadManager.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System;

namespace RenSharp
{
	public ref class ArmorWarheadManager abstract sealed
	{
		public:
			enum class SpecialDamageType : int
			{
				SpecialDamageTypeNone = ::ArmorWarheadManager::SPECIAL_DAMAGE_TYPE_NONE,
				SpecialDamageTypeFire = ::ArmorWarheadManager::SPECIAL_DAMAGE_TYPE_FIRE,
				SpecialDamageTypeChem = ::ArmorWarheadManager::SPECIAL_DAMAGE_TYPE_CHEM,
				SpecialDamageTypeElectric = ::ArmorWarheadManager::SPECIAL_DAMAGE_TYPE_ELECTRIC,
				SpecialDamageTypeCnCFire = ::ArmorWarheadManager::SPECIAL_DAMAGE_TYPE_CNC_FIRE,
				SpecialDamageTypeCnCChem = ::ArmorWarheadManager::SPECIAL_DAMAGE_TYPE_CNC_CHEM,
				SpecialDamageTypeSuperFire = ::ArmorWarheadManager::SPECIAL_DAMAGE_TYPE_SUPER_FIRE
			};

			static bool	IsArmorSoft(unsigned int armor);
			static unsigned int GetArmorType(System::String^ name);
			static System::String^ GetArmorName(unsigned int type);
			static unsigned int	GetWarheadType(System::String^ name);
			static System::String^ GetWarheadName(unsigned int type);
			static float GetDamageMultiplier(unsigned int armor, unsigned int warhead);
			static float GetShieldAbsorbsion(unsigned int armor, unsigned int warhead);
			static SpecialDamageType GetSpecialDamageType(unsigned int warhead);
			static float GetSpecialDamageProbability(unsigned int warhead);
			static unsigned int GetSpecialDamageWarhead(SpecialDamageType type);
			static float GetSpecialDamageDuration(SpecialDamageType type);
			static float GetSpecialDamageScale(SpecialDamageType type);
			static System::String^ GetSpecialDamageExplosion(SpecialDamageType type);
			static float GetVisceroidProbability(unsigned int warhead);
			static bool	IsSkinImpervious(SpecialDamageType type, unsigned int skin);

			static property unsigned int NumArmorTypes
			{
				unsigned int get();
			}

			static property unsigned int NumWarheadTypes
			{
				unsigned int get();
			}
	};
}