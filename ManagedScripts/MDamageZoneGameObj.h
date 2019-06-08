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

#include "MBaseGameObj.h"

#pragma managed(push, off)

class DamageZoneGameObj;

#pragma managed(pop)

namespace RenSharp
{
	value class OBBoxClass;
	interface class IDamageZoneGameObjDef;

	public interface class IDamageZoneGameObj : public IBaseGameObj
	{
		property IntPtr DamageZoneGameObjPointer
		{
			IntPtr get();
		}

		property IDamageZoneGameObjDef^ Definition
		{
			IDamageZoneGameObjDef^ get();
		}

		property OBBoxClass BoundingBox
		{
			OBBoxClass get();
			void set(OBBoxClass value);
		}
	};

	public ref class DamageZoneGameObj : public BaseGameObj, public IDamageZoneGameObj
	{
		public:
			DamageZoneGameObj(IntPtr pointer);

			property IntPtr DamageZoneGameObjPointer
			{
				virtual IntPtr get() sealed;
			}

			property IDamageZoneGameObjDef^ Definition
			{
#pragma push_macro("new")
#undef new
				virtual IDamageZoneGameObjDef^ get() new sealed;
#pragma pop_macro("new")
			}

			property OBBoxClass BoundingBox
			{
				virtual OBBoxClass get() sealed;
				virtual void set(OBBoxClass value) sealed;
			}

		protected:
			property ::PostLoadableClass* InternalPostLoadableClassPointer
			{
				::PostLoadableClass* get() override;
			}

			property ::PersistClass* InternalPersistClassPointer
			{
				::PersistClass* get() override;
			}

			property ::BaseGameObj* InternalBaseGameObjPointer
			{
				::BaseGameObj* get() override;
			}

			property ::DamageZoneGameObj* InternalDamageZoneGameObjPointer
			{
				virtual ::DamageZoneGameObj* get();
			}
	};
}