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

#include "MDefinition.h"
#include "Mengine_vector.h"

#pragma managed(push, off)

class SpawnerDefClass;

#pragma managed(pop)

namespace RenSharp
{
	public interface class ISpawnerDefClass : public IDefinitionClass
	{
		literal unsigned int SpawnerDefClassClassID = 12301;

		property IntPtr SpawnerDefClassPointer
		{
			IntPtr get();
		}

		property IDynamicVectorClass<int>^ SpawnDefinitionIDList
		{
			IDynamicVectorClass<int>^ get();
			void set(IDynamicVectorClass<int>^ value);
		}

		property sint32 PlayerType
		{
			sint32 get();
			void set(sint32 value);
		}

		property sint32 SpawnMax
		{
			sint32 get();
			void set(sint32 value);
		}

		property float SpawnDelay
		{
			float get();
			void set(float value);
		}

		property float SpawnDelayVariation
		{
			float get();
			void set(float value);
		}

		property bool IsPrimary
		{
			bool get();
			void set(bool value);
		}

		property bool IsSoldierStartup
		{
			bool get();
			void set(bool value);
		}

		property bool GotoSpawnerPos
		{
			bool get();
			void set(bool value);
		}

		property float GotoSpawnerPosPriority
		{
			float get();
			void set(float value);
		}

		property bool TeleportFirstSpawn
		{
			bool get();
			void set(bool value);
		}

		property sint32 SpecialEffectsObjID
		{
			sint32 get();
			void set(sint32 value);
		}

		property float PostVisualSpawnDelay
		{
			float get();
			void set(float value);
		}

		property bool StartsDisabled
		{
			bool get();
			void set(bool value);
		}

		property bool KillHibernatingSpawn
		{
			bool get();
			void set(bool value);
		}

		property bool ApplySpawnMaterialEffect
		{
			bool get();
			void set(bool value);
		}

		property bool IsMultiplayWeaponSpawner
		{
			bool get();
			void set(bool value);
		}

		property IDynamicVectorClass<String^>^ ScriptNames
		{
			IDynamicVectorClass<String^>^ get();
			void set(IDynamicVectorClass<String^>^ value);
		}

		property IDynamicVectorClass<String^>^ ScriptParameters
		{
			IDynamicVectorClass<String^>^ get();
			void set(IDynamicVectorClass<String^>^ value);
		}
	};

	public ref class SpawnerDefClass : public DefinitionClass, public ISpawnerDefClass
	{
		public:
			SpawnerDefClass(IntPtr pointer);

			property IntPtr SpawnerDefClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IDynamicVectorClass<int>^ SpawnDefinitionIDList
			{
				virtual IDynamicVectorClass<int>^ get() sealed;
				virtual void set(IDynamicVectorClass<int>^ value) sealed;
			}

			property sint32 PlayerType
			{
				virtual sint32 get() sealed;
				virtual void set(sint32 value) sealed;
			}

			property sint32 SpawnMax
			{
				virtual sint32 get() sealed;
				virtual void set(sint32 value) sealed;
			}

			property float SpawnDelay
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float SpawnDelayVariation
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool IsPrimary
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsSoldierStartup
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool GotoSpawnerPos
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property float GotoSpawnerPosPriority
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool TeleportFirstSpawn
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property sint32 SpecialEffectsObjID
			{
				virtual sint32 get() sealed;
				virtual void set(sint32 value) sealed;
			}

			property float PostVisualSpawnDelay
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool StartsDisabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool KillHibernatingSpawn
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool ApplySpawnMaterialEffect
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsMultiplayWeaponSpawner
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property IDynamicVectorClass<String^>^ ScriptNames
			{
				virtual IDynamicVectorClass<String^>^ get() sealed;
				virtual void set(IDynamicVectorClass<String^>^ value) sealed;
			}

			property IDynamicVectorClass<String^>^ ScriptParameters
			{
				virtual IDynamicVectorClass<String^>^ get() sealed;
				virtual void set(IDynamicVectorClass<String^>^ value) sealed;
			}

		protected:
			property ::DefinitionClass* InternalDefinitionClassPointer
			{
				::DefinitionClass* get() override;
			}

			property ::SpawnerDefClass* InternalSpawnerDefClassPointer
			{
				virtual ::SpawnerDefClass* get();
			}
	};
}