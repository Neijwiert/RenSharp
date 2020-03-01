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

#include "MSimpleGameObj.h"

#pragma managed(push, off)

class C4GameObj;

#pragma managed(pop)

namespace RenSharp
{
	interface class IC4GameObjDef;
	interface class IScriptableGameObj;
	interface class ISoldierGameObj;
	interface class IAmmoDefinitionClass;
	interface class IPlayerDataClass;

	public interface class IC4GameObj : public ISimpleGameObj
	{
		property IntPtr C4GameObjPointer
		{
			IntPtr get();
		}

		property IC4GameObjDef ^Definition
		{
			IC4GameObjDef ^get();
		}

		property IScriptableGameObj ^StuckObject
		{
			IScriptableGameObj ^get();
		}

		property ISoldierGameObj ^Owner
		{
			ISoldierGameObj ^get();
			void set(ISoldierGameObj ^value);
		}

		property IAmmoDefinitionClass ^AmmoDef
		{
			IAmmoDefinitionClass ^get();
		}

		property IPlayerDataClass ^PlayerData
		{
			IPlayerDataClass ^get();
			void set(IPlayerDataClass ^value);
		}

		property int DetonationMode
		{
			int get();
		}
	};

	public ref class C4GameObj : public SimpleGameObj, public IC4GameObj
	{
		public:
			C4GameObj(IntPtr pointer);

			property IntPtr C4GameObjPointer
			{
				virtual IntPtr get() sealed;
			}

#pragma push_macro("new")
#undef new

			property IC4GameObjDef ^Definition
			{
				virtual IC4GameObjDef ^get() new;
			}

#pragma pop_macro("new")

			property IScriptableGameObj ^StuckObject
			{
				virtual IScriptableGameObj ^get() sealed;
			}

			property ISoldierGameObj ^Owner
			{
				virtual ISoldierGameObj ^get() sealed;
				virtual void set(ISoldierGameObj ^value) sealed;
			}

			property IAmmoDefinitionClass ^AmmoDef
			{
				virtual IAmmoDefinitionClass ^get() sealed;
			}

			property IPlayerDataClass ^PlayerData
			{
				virtual IPlayerDataClass ^get() sealed;
				virtual void set(IPlayerDataClass ^value) sealed;
			}

			property int DetonationMode
			{
				virtual int get() sealed;
			}

		protected:
			property ::SimpleGameObj *InternalSimpleGameObjPointer
			{
				::SimpleGameObj *get() override;
			}

			property ::C4GameObj *InternalC4GameObjPointer
			{
				virtual ::C4GameObj *get();
			}
	};
}