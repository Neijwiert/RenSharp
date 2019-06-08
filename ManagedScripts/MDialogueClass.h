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
#include <DialogueClass.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "IUnmanagedObject.h"
#include "AbstractUnmanagedObject.h"
#include "Mengine_vector.h"

namespace RenSharp
{
	public enum class DialogueType : int
	{
		DialogOnTakeDamageFromFriend = DIALOG_ON_TAKE_DAMAGE_FROM_FRIEND,
		DialogOnTakeDamageFromEnemy = DIALOG_ON_TAKE_DAMAGE_FROM_ENEMY,
		DialogOnDamageFriend = DIALOG_ON_DAMAGE_FRIEND,
		DialogOnDamageEnemy = DIALOG_ON_DAMAGE_ENEMY,
		DialogOnKilledFriend = DIALOG_ON_KILLED_FRIEND,
		DialogOnKilledEnemy = DIALOG_ON_KILLED_ENEMY,
		DialogOnSawFriend = DIALOG_ON_SAW_FRIEND,
		DialogOnSawEnemy = DIALOG_ON_SAW_ENEMY,
		DialogOnObsolete01 = DIALOG_ON_OBSOLETE_01,
		DialogOnObsolete02 = DIALOG_ON_OBSOLETE_02,
		DialogOnDie = DIALOG_ON_DIE,
		DialogOnPokeIdle = DIALOG_ON_POKE_IDLE,
		DialogOnPokeSearch = DIALOG_ON_POKE_SEARCH,
		DialogOnPokeCombat = DIALOG_ON_POKE_COMBAT,
		DialogOnIdleToCombat = DIALOG_ON_IDLE_TO_COMBAT,
		DialogOnIdleToSearch = DIALOG_ON_IDLE_TO_SEARCH,
		DialogOnSearchToCombat = DIALOG_ON_SEARCH_TO_COMBAT,
		DialogOnSearchToIdle = DIALOG_ON_SEARCH_TO_IDLE,
		DialogOnCombatToSearch = DIALOG_ON_COMBAT_TO_SEARCH,
		DialogOnCombatToIdle = DIALOG_ON_COMBAT_TO_IDLE
	};

	public interface class IDialogueOptionClass : public IUnmanagedObject
	{
		property IntPtr DialogueOptionClassPointer
		{
			IntPtr get();
		}

		property int ConversationID
		{
			int get();
			void set(int value);
		}

		property float Weight
		{
			float get();
			void set(float value);
		}
	};

	public ref class DialogueOptionClass : public AbstractUnmanagedObject, public IDialogueOptionClass
	{
		public:
			DialogueOptionClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			property IntPtr DialogueOptionClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property int ConversationID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property float Weight
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

		protected:
			property ::DialogueOptionClass *InternalDialogueOptionClassPointer
			{
				virtual ::DialogueOptionClass *get();
			}
	};

	public interface class IDialogueClass : public IUnmanagedObject
	{
		property IntPtr DialogueClassPointer
		{
			IntPtr get();
		}

		property IDynamicVectorClass<IDialogueOptionClass ^> ^DialogueOptions
		{
			IDynamicVectorClass<IDialogueOptionClass ^> ^get();
			void set(IDynamicVectorClass<IDialogueOptionClass ^> ^value);
		}

		property float SilenceWeight
		{
			float get();
			void set(float value);
		}
	};

	public ref class DialogueClass : public AbstractUnmanagedObject, public IDialogueClass
	{
		public:
			DialogueClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			property IntPtr DialogueClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IDynamicVectorClass<IDialogueOptionClass ^> ^DialogueOptions
			{
				virtual IDynamicVectorClass<IDialogueOptionClass ^> ^get() sealed;
				virtual void set(IDynamicVectorClass<IDialogueOptionClass ^> ^value) sealed;
			}

			property float SilenceWeight
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

		protected:
			property ::DialogueClass *InternalDialogueClassPointer
			{
				virtual ::DialogueClass *get();
			}
	};
}