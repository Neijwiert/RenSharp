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
#include <PhysDefClass.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MDefinition.h"

namespace RenSharp
{
	interface class IChunkSaveClass;
	interface class IChunkLoadClass;

	public enum class CollisionGroupType : int
	{
		DefaultCollisionGroup = ::DEFAULT_COLLISION_GROUP,
		UncollideableGroup = ::UNCOLLIDEABLE_GROUP,
		TerrainOnlyCollisionGroup = ::TERRAIN_ONLY_COLLISION_GROUP,
		BulletCollisionGroup = ::BULLET_COLLISION_GROUP,
		TerrainAndBulletCollisionGroup = ::TERRAIN_AND_BULLET_COLLISION_GROUP,
		BulletOnlyCollisionGroup = ::BULLET_ONLY_COLLISION_GROUP,
		SoldierCollisionGroup = ::SOLDIER_COLLISION_GROUP,
		SoldierGhostCollisionGroup = ::SOLDIER_GHOST_COLLISION_GROUP,
		C4CollisionGroup = ::C4_COLLISION_GROUP,
		UndergroundCollisionGroup = ::UNDERGROUND_COLLISION_GROUP,
		SoldierOnlyCollisionGroup = ::SOLDIER_ONLY_COLLISION_GROUP,
		SoldierBulletCollisionGroup = ::SOLDIER_BULLET_COLLISION_GROUP,
		TerrainCollisionGroup = ::TERRAIN_COLLISION_GROUP,
		WaterSurfaceCollisionGroup = ::WATER_SURFACE_COLLISION_GROUP,
		WaterEdgeCollisionGroup = ::WATER_EDGE_COLLISION_GROUP,
		WaterEdgeAltCollisionGroup = ::WATER_EDGE_ALT_COLLISION_GROUP,
		BeachEdgeCollisionGroup = ::BEACH_EDGE_COLLISION_GROUP,
		NavalUnitCollisionGroup = ::NAVAL_UNIT_COLLISION_GROUP,
		BeachingUnitCollisionGroup = ::BEACHING_UNIT_COLLISION_GROUP,
		HoverUnitCollisionGroup = ::HOVER_UNIT_COLLISION_GROUP,
		AmphibiousUnitCollisionGroup = ::AMPHIBIOUS_UNIT_COLLISION_GROUP,
		AmphibiousUnitFloorCollisionGroup = ::AMPHIBIOUS_UNIT_FLOOR_COLLISION_GROUP,
		UndergroundTransitionCollisionGroup = ::UNDERGROUND_TRANSITION_COLLISION_GROUP,
		DefaultAndSoldierOnlyCollisionGroup = ::DEFAULT_AND_SOLDIER_ONLY_COLLISION_GROUP,
		PlayerBuildingCollisionGroup = ::PLAYER_BUILDING_COLLISION_GROUP,
		PlayerBuildingGhostCollisionGroup = ::PLAYER_BUILDING_GHOST_COLLISION_GROUP,
		TrainCollisionGroup = ::TRAIN_COLLISION_GROUP,
		TrainTrackCollisionGroup = ::TRAIN_TRACK_COLLISION_GROUP,
		CollisionGroupMax = ::COLLISION_GROUP_MAX
	};

	public enum class VisibilityModeType : int
	{
		VisibilityModeDefault = ::VISIBILITYMODE_DEFAULT,
		VisibilityModeIfCollide = ::VISIBILITYMODE_IFCOLLIDE,
		VisibilityModeIfNoCollide = ::VISIBILITYMODE_IFNOCOLLIDE,
		VisibilityModeMax = ::VISIBILITYMODE_MAX
	};

	public interface class IPhysDefClass : public IDefinitionClass
	{
		bool IsType(String ^typeName);

		property IntPtr PhysDefClassPointer
		{
			IntPtr get();
		}

		property String ^TypeName
		{
			String ^get();
		}

		property String ^ModelName
		{
			String ^get();
		}

		property bool IsPreLit
		{
			bool get();
		}
	};

	public ref class PhysDefClass : public DefinitionClass, public IPhysDefClass
	{
		public:
			PhysDefClass(IntPtr pointer);

			static String ^GetCollisionGroupName(CollisionGroupType group);

			virtual bool IsType(String ^typeName) sealed;

			property IntPtr PhysDefClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property String ^TypeName
			{
				virtual String ^get() sealed;
			}

			property String ^ModelName
			{
				virtual String ^get() sealed;

				protected:
					void set(String ^value);
			}

			property bool IsPreLit
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

		protected:
			property ::DefinitionClass *InternalDefinitionClassPointer
			{
				::DefinitionClass *get() override;
			}

			property ::PhysDefClass *InternalPhysDefClassPointer
			{
				virtual ::PhysDefClass *get();
			}
	};
}
