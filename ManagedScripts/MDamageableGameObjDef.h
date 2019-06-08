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
#include <DamageableGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MScriptableGameObjDef.h"

namespace RenSharp
{
	interface class IDefenseObjectDefClass;

	public enum class PlayerType : int
	{
		PlayerTypeMutant = PLAYERTYPE_MUTANT,
		PlayerTypeNeutral = PLAYERTYPE_NEUTRAL,
		PlayerTypeRenegade = PLAYERTYPE_RENEGADE,
		PlayerTypeNod = PLAYERTYPE_NOD,
		PlayerTypeGDI = PLAYERTYPE_GDI
	};

	public interface class IDamageableGameObjDef : public IScriptableGameObjDef
	{
		property IntPtr DamageableGameObjDefPointer
		{
			IntPtr get();
		}

		property int NameID
		{
			int get();
			void set(int value);
		}

		property int EncyclopediaType
		{
			int get();
			void set(int value);
		}

		property int EncyclopediaID
		{
			int get();
			void set(int value);
		}

		property String ^InfoIconTextureFilename
		{
			String ^get();
			void set(String ^value);
		}

		property int TranslatedNameID
		{
			int get();
			void set(int value);
		}

		property IDefenseObjectDefClass ^DefenseObjectDef
		{
			IDefenseObjectDefClass ^get();
			void set(IDefenseObjectDefClass ^set);
		}

		property int DefaultPlayerType
		{
			int get();
			void set(int value);
		}
	};

	public ref class DamageableGameObjDef : public ScriptableGameObjDef, public IDamageableGameObjDef
	{
		public:
			DamageableGameObjDef(IntPtr pointer);

			property IntPtr DamageableGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

			property int NameID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int EncyclopediaType
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int EncyclopediaID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property String ^InfoIconTextureFilename
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property int TranslatedNameID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property IDefenseObjectDefClass ^DefenseObjectDef
			{
				virtual IDefenseObjectDefClass ^get() sealed;
				virtual void set(IDefenseObjectDefClass ^set) sealed;
			}

			property int DefaultPlayerType
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

		protected:
			property ::ScriptableGameObjDef *InternalScriptableGameObjDefPointer
			{
				::ScriptableGameObjDef *get() override;
			}

			property ::DamageableGameObjDef *InternalDamageableGameObjDefPointer
			{
				virtual ::DamageableGameObjDef *get();
			}
	};
}
