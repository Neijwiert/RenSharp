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

#include "MBaseGameObjDef.h"

#pragma managed(push, off)

class DamageZoneGameObjDef;

#pragma managed(pop)

namespace RenSharp
{
	value class Vector3;

	public interface class IDamageZoneGameObjDef : public IBaseGameObjDef
	{
		property IntPtr DamageZoneGameObjDefPointer
		{
			IntPtr get();
		}

		property float DamageRate
		{
			float get();
			void set(float value);
		}

		property int DamageWarhead
		{
			int get();
			void set(int value);
		}

		property Vector3 Color
		{
			Vector3 get();
			void set(Vector3 value);
		}
	};

	public ref class DamageZoneGameObjDef : public BaseGameObjDef, public IDamageZoneGameObjDef
	{
		public:
			DamageZoneGameObjDef(IntPtr pointer);

			property IntPtr DamageZoneGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

			property float DamageRate
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int DamageWarhead
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property Vector3 Color
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

		protected:
			property ::BaseGameObjDef* InternalBaseGameObjDefPointer
			{
				::BaseGameObjDef* get() override;
			}

			property ::DamageZoneGameObjDef* InternalDamageZoneGameObjDefPointer
			{
				virtual ::DamageZoneGameObjDef* get();
			}
	};
}