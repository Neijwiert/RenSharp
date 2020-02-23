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
#include <PhysicalGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

#include "MDamageableGameObjDef.h"

namespace RenSharp
{
	public enum class TeamVisibilitySetting : int
	{
		TeamVisibilityAll = TEAM_VISIBILITY_ALL,
		TeamVisibilityFriendly = TEAM_VISIBILITY_FRIENDLY,
		TeamVisibilityEnemy = TEAM_VISIBILITY_ENEMY
	};

	public interface class IPhysicalGameObjDef : public IDamageableGameObjDef
	{
		property IntPtr PhysicalGameObjDefPointer
		{
			IntPtr get();
		}

		property int Type
		{
			int get();
			void set(int value);
		}

		property int RadarBlipType
		{
			int get();
			void set(int value);
		}

		property float BullseyeOffsetZ
		{
			float get();
			void set(float value);
		}

		property String ^Animation
		{
			String ^get();
			void set(String ^value);
		}

		property int PhysDefID
		{
			int get();
			void set(int value);
		}

		property int KilledExplosion
		{
			int get();
			void set(int value);
		}

		property bool DefaultHibernationEnable
		{
			bool get();
			void set(bool value);
		}

		property bool AllowInnateConversations
		{
			bool get();
			void set(bool value);
		}

		property int OratorType
		{
			int get();
			void set(int value);
		}

		property bool UseCreationEffect
		{
			bool get();
			void set(bool value);
		}

		property char TeamVisibility
		{
			char get();
			void set(char value);
		}

		property bool IgnoreForTracking
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class PhysicalGameObjDef : public DamageableGameObjDef, public IPhysicalGameObjDef
	{
		public:
			PhysicalGameObjDef(IntPtr pointer);

			property IntPtr PhysicalGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

			property int Type
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int RadarBlipType
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property float BullseyeOffsetZ
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property String ^Animation
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property int PhysDefID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int KilledExplosion
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property bool DefaultHibernationEnable
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool AllowInnateConversations
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property int OratorType
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property bool UseCreationEffect
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property char TeamVisibility
			{
				virtual char get() sealed;
				virtual void set(char value) sealed;
			}

			property bool IgnoreForTracking
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			property ::DamageableGameObjDef *InternalDamageableGameObjDefPointer
			{
				::DamageableGameObjDef *get() override;
			}

			property ::PhysicalGameObjDef *InternalPhysicalGameObjDefPointer
			{
				virtual ::PhysicalGameObjDef *get();
			}
	};
}