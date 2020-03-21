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

#pragma managed(push, off)

class GlobalSettingsDef;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IGlobalSettingsDef : public IDefinitionClass
	{
		literal unsigned int GlobalSettingsDefClassID = 61443;

		property IntPtr GlobalSettingsDefPointer
		{
			IntPtr get();
		}

		property int DeathSoundID
		{
			int get();
		}

		property int EVAObjectivesSoundID
		{
			int get();
		}

		property int HUDHelpTextSoundID
		{
			int get();
		}

		property float MaxConversationDist
		{
			float get();
		}

		property float MaxCombatConversationDist
		{
			float get();
		}

		property float SoldierWalkSpeed
		{
			float get();
		}

		property float SoldierCrouchSpeed
		{
			float get();
		}

		property float FallingDamageMinDistance
		{
			float get();
		}

		property float FallingDamageMaxDistance
		{
			float get();
		}

		property String^ PurchaseGDICharactersTexture
		{
			String^ get();
		}

		property String^ PurchaseGDIVehiclesTexture
		{
			String^ get();
		}

		property String^ PurchaseGDIEquipmentTexture
		{
			String^ get();
		}

		property String^ PurchaseNODCharactersTexture
		{
			String^ get();
		}

		property String^ PurchaseNODVehiclesTexture
		{
			String^ get();
		}

		property String^ PurchaseNODEquipmentTexture
		{
			String^ get();
		}

		property String^ PurchaseGDIMUTCharactersTexture
		{
			String^ get();
		}

		property String^ PurchaseGDIMUTVehiclesTexture
		{
			String^ get();
		}

		property String^ PurchaseGDIMUTEquipmentTexture
		{
			String^ get();
		}

		property String^ PurchaseNODMUTCharactersTexture
		{
			String^ get();
		}

		property String^ PurchaseNODMUTVehiclesTexture
		{
			String^ get();
		}

		property String^ PurchaseNODMUTEquipmentTexture
		{
			String^ get();
		}

		property int EncyclopediaEventStringID
		{
			int get();
		}

		property int FallingDamageWarhead
		{
			int get();
		}

		property float StealthDistanceHuman
		{
			float get();
		}

		property float StealthDistanceVehicle
		{
			float get();
		}

		property float MPStealthDistanceHuman
		{
			float get();
		}

		property float MPStealthDistanceVehicle
		{
			float get();
		}

		property float UndergroundFadeDistance
		{
			float get();
		}

		property int GDISoldierID
		{
			int get();
			void set(int value);
		}

		property int NodSoldierID
		{
			int get();
			void set(int value);
		}

		property float SoldierFlySpeed
		{
			float get();
		}

		property String^ VisceroidName
		{
			String^ get();
		}
	};

	public ref class GlobalSettingsDef : public DefinitionClass, public IGlobalSettingsDef
	{
		public:
			GlobalSettingsDef(IntPtr pointer);

			static property IGlobalSettingsDef^ GlobalSettings
			{
				IGlobalSettingsDef^ get();
			}

			property IntPtr GlobalSettingsDefPointer
			{
				virtual IntPtr get() sealed;
			}

			property int DeathSoundID
			{
				virtual int get() sealed;
			}

			property int EVAObjectivesSoundID
			{
				virtual int get() sealed;
			}

			property int HUDHelpTextSoundID
			{
				virtual int get() sealed;
			}

			property float MaxConversationDist
			{
				virtual float get() sealed;
			}

			property float MaxCombatConversationDist
			{
				virtual float get() sealed;
			}

			property float SoldierWalkSpeed
			{
				virtual float get() sealed;
			}

			property float SoldierCrouchSpeed
			{
				virtual float get() sealed;
			}

			property float FallingDamageMinDistance
			{
				virtual float get() sealed;
			}

			property float FallingDamageMaxDistance
			{
				virtual float get() sealed;
			}

			property String^ PurchaseGDICharactersTexture
			{
				virtual String^ get() sealed;
			}

			property String^ PurchaseGDIVehiclesTexture
			{
				virtual String^ get() sealed;
			}

			property String^ PurchaseGDIEquipmentTexture
			{
				virtual String^ get() sealed;
			}

			property String^ PurchaseNODCharactersTexture
			{
				virtual String^ get() sealed;
			}

			property String^ PurchaseNODVehiclesTexture
			{
				virtual String^ get() sealed;
			}

			property String^ PurchaseNODEquipmentTexture
			{
				virtual String^ get() sealed;
			}

			property String^ PurchaseGDIMUTCharactersTexture
			{
				virtual String^ get() sealed;
			}

			property String^ PurchaseGDIMUTVehiclesTexture
			{
				virtual String^ get() sealed;
			}

			property String^ PurchaseGDIMUTEquipmentTexture
			{
				virtual String^ get() sealed;
			}

			property String^ PurchaseNODMUTCharactersTexture
			{
				virtual String^ get() sealed;
			}

			property String^ PurchaseNODMUTVehiclesTexture
			{
				virtual String^ get() sealed;
			}

			property String^ PurchaseNODMUTEquipmentTexture
			{
				virtual String^ get() sealed;
			}

			property int EncyclopediaEventStringID
			{
				virtual int get() sealed;
			}

			property int FallingDamageWarhead
			{
				virtual int get() sealed;
			}

			property float StealthDistanceHuman
			{
				virtual float get() sealed;
			}

			property float StealthDistanceVehicle
			{
				virtual float get() sealed;
			}

			property float MPStealthDistanceHuman
			{
				virtual float get() sealed;
			}

			property float MPStealthDistanceVehicle
			{
				virtual float get() sealed;
			}

			property float UndergroundFadeDistance
			{
				virtual float get() sealed;
			}

			property int GDISoldierID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int NodSoldierID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property float SoldierFlySpeed
			{
				virtual float get() sealed;
			}

			property String^ VisceroidName
			{
				virtual String^ get() sealed;
			}

		protected:
			property ::DefinitionClass* InternalDefinitionClassPointer
			{
				::DefinitionClass* get() override;
			}

			property ::GlobalSettingsDef* InternalGlobalSettingsDefPointer
			{
				virtual ::GlobalSettingsDef* get();
			}
	};
}
