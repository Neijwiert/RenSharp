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

#include "MSimpleGameObjDef.h"

#pragma managed(push, off)

class PowerUpGameObjDef;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IPowerUpGameObjDef : public ISimpleGameObjDef
	{
		literal unsigned int PowerUpGameObjDefClassID = 12291;

		property IntPtr PowerUpGameObjDefPointer
		{
			IntPtr get();
		}

		property int GrantShieldType
		{
			int get();
			void set(int value);
		}

		property float GrantShieldStrength
		{
			float get();
			void set(float value);
		}

		property float GrantShieldStrengthMax
		{
			float get();
			void set(float value);
		}

		property float GrantHealth
		{
			float get();
			void set(float value);
		}

		property float GrantHealthMax
		{
			float get();
			void set(float value);
		}

		property int GrantWeaponID
		{
			int get();
			void set(int value);
		}

		property bool GrantWeapon
		{
			bool get();
			void set(bool value);
		}

		property int GrantWeaponRounds
		{
			int get();
			void set(int value);
		}

		property bool GrantWeaponClips
		{
			bool get();
			void set(bool value);
		}

		property bool Persistent
		{
			bool get();
			void set(bool value);
		}

		property int GrantKey
		{
			int get();
			void set(int value);
		}

		property bool AlwaysAllowGrant
		{
			bool get();
			void set(bool value);
		}

		property int GrantSoundID
		{
			int get();
			void set(int value);
		}

		property String ^GrantAnimationName
		{
			String ^get();
			void set(String ^value);
		}

		property int IdleSoundID
		{
			int get();
			void set(int value);
		}

		property String ^IdleAnimationName
		{
			String ^get();
			void set(String ^value);
		}

		property bool GrantShieldStrengthMaxIsScaled
		{
			bool get();
			void set(bool value);
		}

		property bool GrantHealthMaxIsScaled
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class PowerUpGameObjDef : public SimpleGameObjDef, public IPowerUpGameObjDef
	{
		public: 
			PowerUpGameObjDef(IntPtr pointer);

			property IntPtr PowerUpGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

			property int GrantShieldType
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property float GrantShieldStrength
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float GrantShieldStrengthMax
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float GrantHealth
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float GrantHealthMax
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int GrantWeaponID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property bool GrantWeapon
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property int GrantWeaponRounds
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property bool GrantWeaponClips
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool Persistent
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property int GrantKey
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property bool AlwaysAllowGrant
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property int GrantSoundID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property String ^GrantAnimationName
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property int IdleSoundID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property String ^IdleAnimationName
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property bool GrantShieldStrengthMaxIsScaled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool GrantHealthMaxIsScaled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			property ::SimpleGameObjDef *InternalSimpleGameObjDefPointer
			{
				::SimpleGameObjDef *get() override;
			}

			property ::PowerUpGameObjDef *InternalPowerUpGameObjDefPointer
			{
				virtual ::PowerUpGameObjDef *get();
			}
	};
}