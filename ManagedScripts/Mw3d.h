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

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <w3d.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	public enum class W3DSurfaceType : int
	{
		SurfaceTypeLightMetal = ::W3D_SURFACE_TYPES::SURFACE_TYPE_LIGHT_METAL,
		SurfaceTypeHeavyMetal = ::W3D_SURFACE_TYPES::SURFACE_TYPE_HEAVY_METAL,
		SurfaceTypeWater = ::W3D_SURFACE_TYPES::SURFACE_TYPE_WATER,
		SurfaceTypeSand = ::W3D_SURFACE_TYPES::SURFACE_TYPE_SAND,
		SurfaceTypeDirt = ::W3D_SURFACE_TYPES::SURFACE_TYPE_DIRT,
		SurfaceTypeMud = ::W3D_SURFACE_TYPES::SURFACE_TYPE_MUD,
		SurfaceTypeGrass = ::W3D_SURFACE_TYPES::SURFACE_TYPE_GRASS,
		SurfaceTypeWood = ::W3D_SURFACE_TYPES::SURFACE_TYPE_WOOD,
		SurfaceTypeConcrete = ::W3D_SURFACE_TYPES::SURFACE_TYPE_CONCRETE,
		SurfaceTypeFlesh = ::W3D_SURFACE_TYPES::SURFACE_TYPE_FLESH,
		SurfaceTypeRock = ::W3D_SURFACE_TYPES::SURFACE_TYPE_ROCK,
		SurfaceTypeSnow = ::W3D_SURFACE_TYPES::SURFACE_TYPE_SNOW,
		SurfaceTypeIce = ::W3D_SURFACE_TYPES::SURFACE_TYPE_ICE,
		SurfaceTypeDefault = ::W3D_SURFACE_TYPES::SURFACE_TYPE_DEFAULT,
		SurfaceTypeGlass = ::W3D_SURFACE_TYPES::SURFACE_TYPE_GLASS,
		SurfaceTypeCloth = ::W3D_SURFACE_TYPES::SURFACE_TYPE_CLOTH,
		SurfaceTypeTiberiumField = ::W3D_SURFACE_TYPES::SURFACE_TYPE_TIBERIUM_FIELD,
		SurfaceTypeFoliagePermeable = ::W3D_SURFACE_TYPES::SURFACE_TYPE_FOLIAGE_PERMEABLE,
		SurfaceTypeGlassPermeable = ::W3D_SURFACE_TYPES::SURFACE_TYPE_GLASS_PERMEABLE,
		SurfaceTypeIcePermeable = ::W3D_SURFACE_TYPES::SURFACE_TYPE_ICE_PERMEABLE,
		SurfaceTypeClothPermeable = ::W3D_SURFACE_TYPES::SURFACE_TYPE_CLOTH_PERMEABLE,
		SurfaceTypeElectrical = ::W3D_SURFACE_TYPES::SURFACE_TYPE_ELECTRICAL,
		SurfaceTypeFlammable = ::W3D_SURFACE_TYPES::SURFACE_TYPE_FLAMMABLE,
		SurfaceTypeSteam = ::W3D_SURFACE_TYPES::SURFACE_TYPE_STEAM,
		SurfaceTypeElectricalPermeable = ::W3D_SURFACE_TYPES::SURFACE_TYPE_ELECTRICAL_PERMEABLE,
		SurfaceTypeFlammablePermeable = ::W3D_SURFACE_TYPES::SURFACE_TYPE_FLAMMABLE_PERMEABLE,
		SurfaceTypeSteamPermeable = ::W3D_SURFACE_TYPES::SURFACE_TYPE_STEAM_PERMEABLE,
		SurfaceTypeWaterPermeable = ::W3D_SURFACE_TYPES::SURFACE_TYPE_WATER_PERMEABLE,
		SurfaceTypeTiberiumWater = ::W3D_SURFACE_TYPES::SURFACE_TYPE_TIBERIUM_WATER,
		SurfaceTypeTiberiumWaterPermeable = ::W3D_SURFACE_TYPES::SURFACE_TYPE_TIBERIUM_WATER_PERMEABLE,
		SurfaceTypeUnderwaterDirt = ::W3D_SURFACE_TYPES::SURFACE_TYPE_UNDERWATER_DIRT,
		SurfaceTypeUnderwaterTiberiumDirt = ::W3D_SURFACE_TYPES::SURFACE_TYPE_UNDERWATER_TIBERIUM_DIRT
	};
}