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

#include "MScriptableGameObj.h"

#pragma managed(push, off)

class DamageableGameObj;

#pragma managed(pop)

namespace RenSharp
{
	interface class IDamageableGameObjDef;
	interface class IDefenseObjectClass;
	interface class IOffenseObjectClass;

	public interface class IDamageableGameObj : public IScriptableGameObj
	{
		void ApplyDamage(IOffenseObjectClass ^damager, float scale, int alternateSkin);

		void ApplyDamage(IOffenseObjectClass ^damager, float scale);

		void ApplyDamage(IOffenseObjectClass ^damager);

		void CompletelyDamaged(IOffenseObjectClass ^damager);

		bool IsTeamPlayer();

		bool IsTeammate(IDamageableGameObj ^obj);

		bool IsEnemy(IDamageableGameObj ^obj);

		property IntPtr DamageableGameObjPointer
		{
			IntPtr get();
		}

		property IDamageableGameObjDef ^Definition
		{
			IDamageableGameObjDef ^get();
		}
		
		property IDefenseObjectClass ^DefenseObject
		{
			IDefenseObjectClass ^get();
			void set(IDefenseObjectClass ^value);
		}

		property String ^InfoIconTextureFilename
		{
			String ^get();
		}

		property int TranslatedNameID
		{
			int get();
		}

		property bool Targetable
		{
			bool get();
		}

		property bool IsHealthBarDisplayed
		{
			bool get();
			void set(bool value);
		}

		property int PlayerType
		{
			int get();
			void set(int value);
		}

		property bool IsDamaged
		{
			bool get();
		}
	};

	public ref class DamageableGameObj : public ScriptableGameObj, public IDamageableGameObj
	{
		public:
			DamageableGameObj(IntPtr pointer);

			IDamageableGameObj ^AsDamageableGameObj() override;

			virtual void ApplyDamage(IOffenseObjectClass ^damager, float scale, int alternateSkin) sealed;
			virtual void ApplyDamage(IOffenseObjectClass ^damager, float scale) sealed;
			virtual void ApplyDamage(IOffenseObjectClass ^damager) sealed;
			virtual void CompletelyDamaged(IOffenseObjectClass ^damager) sealed;
			virtual bool IsTeamPlayer() sealed;
			virtual bool IsTeammate(IDamageableGameObj ^obj) sealed;
			virtual bool IsEnemy(IDamageableGameObj ^obj) sealed;

			property IntPtr DamageableGameObjPointer
			{
				virtual IntPtr get() sealed;
			}

#pragma push_macro("new")
#undef new

			property IDamageableGameObjDef ^Definition
			{
				virtual IDamageableGameObjDef ^get() new sealed;
			}

#pragma pop_macro("new")

			property IDefenseObjectClass ^DefenseObject
			{
				virtual IDefenseObjectClass ^get() sealed;
				virtual void set(IDefenseObjectClass ^value) sealed;
			}

			property String ^InfoIconTextureFilename
			{
				virtual String ^get() sealed;
			}

			property int TranslatedNameID
			{
				virtual int get() sealed;
			}

			property bool Targetable
			{
				virtual bool get() sealed;
			}

			property bool IsHealthBarDisplayed
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property int PlayerType
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property bool IsDamaged
			{
				virtual bool get() sealed;
			}

		protected:
			property ::ScriptableGameObj *InternalScriptableGameObjPointer
			{
				::ScriptableGameObj *get() override;
			}

			property ::DamageableGameObj *InternalDamageableGameObjPointer
			{
				virtual ::DamageableGameObj *get();
			}
	};
}