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

#include "MDamageableGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4091 4251 4244 26495 26454)
#include <BuildingGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	public enum class BuildingType : int
	{
		TypeNone = BuildingConstants::TYPE_NONE,
		TypePowerPlane = BuildingConstants::TYPE_POWER_PLANT,
		TypeSoldierFactory = BuildingConstants::TYPE_SOLDIER_FACTORY,
		TypeVehicleFactory = BuildingConstants::TYPE_VEHICLE_FACTORY,
		TypeRefinery = BuildingConstants::TYPE_REFINERY,
		TypeComCenter = BuildingConstants::TYPE_COM_CENTER,
		TypeRepairBay = BuildingConstants::TYPE_REPAIR_BAY,
		TypeShrine = BuildingConstants::TYPE_SHRINE,
		TypeHelipad = BuildingConstants::TYPE_HELIPAD,
		TypeConyard = BuildingConstants::TYPE_CONYARD,
		TypeBaseDefense = BuildingConstants::TYPE_BASE_DEFENSE,
		TypeTechCenter = BuildingConstants::TYPE_TECH_CENTER,
		TypeNavalFactory = BuildingConstants::TYPE_NAVAL_FACTORY,
		TypeSpecial = BuildingConstants::TYPE_SPECIAL,
	};

	public enum class LegacyBuildingTeam : int
	{
		LegacyTeamGDI = BuildingConstants::LEGACY_TEAM_GDI,
		LegacyTeamNod = BuildingConstants::LEGACY_TEAM_NOD
	};

	public interface class IBuildingGameObjDef : public IDamageableGameObjDef
	{
		literal unsigned int BuildingGameObjDefClassID = 0xD001;
		literal int BaseCount = BuildingConstants::BASE_COUNT;

		property IntPtr BuildingGameObjDefPointer
		{
			IntPtr get();
		}

		property BuildingType Type
		{
			BuildingType get();
			void set(BuildingType value);
		}

		property String ^MeshPrefix
		{
			String ^get();
			void set(String ^value);
		}

		property unsigned int MCTSkin
		{
			unsigned int get();
			void set(unsigned int value);
		}

		property int GDIDamageReportID
		{
			int get();
			void set(int value);
		}

		property int NodDamageReportID
		{
			int get();
			void set(int value);
		}

		property int GDIDestroyReportID
		{
			int get();
			void set(int value);
		}

		property int NodDestroyReportID
		{
			int get();
			void set(int value);
		}
	};

	public ref class BuildingGameObjDef : public DamageableGameObjDef, public IBuildingGameObjDef
	{
		public:
			BuildingGameObjDef(IntPtr pointer);

			property IntPtr BuildingGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

			property BuildingType Type
			{
				virtual BuildingType get() sealed;
				virtual void set(BuildingType value) sealed;
			}

			property String ^MeshPrefix
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property unsigned int MCTSkin
			{
				virtual unsigned int get() sealed;
				virtual void set(unsigned int value) sealed;
			}

			property int GDIDamageReportID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int NodDamageReportID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int GDIDestroyReportID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int NodDestroyReportID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

		protected:
			property ::DamageableGameObjDef *InternalDamageableGameObjDefPointer
			{
				::DamageableGameObjDef *get() override;
			}

			property ::BuildingGameObjDef *InternalBuildingGameObjDefPointer
			{
				virtual ::BuildingGameObjDef *get();
			}
	};
}