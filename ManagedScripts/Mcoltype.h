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
#include <coltype.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	public enum class CollisionType : int
	{
		CollisionTypeAll = ::COLLISION_TYPE_ALL,
		CollisionType0 = ::COLLISION_TYPE_0,
		CollisionType1 = ::COLLISION_TYPE_1,
		CollisionType2 = ::COLLISION_TYPE_2,
		CollisionType3 = ::COLLISION_TYPE_3,
		CollisionType4 = ::COLLISION_TYPE_4,
		CollisionType5 = ::COLLISION_TYPE_5,
		CollisionType6 = ::COLLISION_TYPE_6,
		CollisionTypePhysical = ::COLLISION_TYPE_PHYSICAL,
		CollisionTypeProjectile = ::COLLISION_TYPE_PROJECTILE,
		CollisionTypeVis = ::COLLISION_TYPE_VIS,
		CollisionTypeCamera = ::COLLISION_TYPE_CAMERA,
		CollisionTypeVehicle = ::COLLISION_TYPE_VEHICLE,
		CollisionTypeUser1 = ::COLLISION_TYPE_USER1,
		CollisionTypeUser2 = ::COLLISION_TYPE_USER2,
	};
}