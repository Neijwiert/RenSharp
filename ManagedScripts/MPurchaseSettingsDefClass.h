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
#include "MNetworkObjectClass.h"
#include "MBuildingGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <PurchaseSettingsDefClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	public interface class IPurchaseSettingsDefClass : public IDefinitionClass, public INetworkObjectClass
	{
		enum class TeamEnum : int
		{
			TeamGDI = ::PurchaseSettingsDefClass::TEAM_GDI,
			TeamNod = ::PurchaseSettingsDefClass::TEAM_NOD,
			TeamMutantGDI = ::PurchaseSettingsDefClass::TEAM_MUTANT_GDI,
			TeamMutantNod = ::PurchaseSettingsDefClass::TEAM_MUTANT_NOD
		};

		enum class TypeEnum : int
		{
			TypeClasses = ::PurchaseSettingsDefClass::TYPE_CLASSES,
			TypeVehicles = ::PurchaseSettingsDefClass::TYPE_VEHICLES,
			TypeEquipment = ::PurchaseSettingsDefClass::TYPE_EQUIPMENT,
			TypeSecretClasses = ::PurchaseSettingsDefClass::TYPE_SECRET_CLASSES,
			TypeSecretVehicles = ::PurchaseSettingsDefClass::TYPE_SECRET_VEHICLES,
			TypeAir = ::PurchaseSettingsDefClass::TYPE_AIR,
			TypeNaval = ::PurchaseSettingsDefClass::TYPE_NAVAL
		};

		literal unsigned int PurchaseSettingsDefClassClassID = 0xF008;

		int GetDefinition(int index);

		int GetCost(int index);

		String^ GetName(int index);

		String^ GetTexture(int index);

		int GetAltDefinition(int index, int index2);

		String^ GetAltTexture(int index, int index2);

		int GetString(int index);

		int GetTechLevel(int index);

		bool GetFactoryNotRequired(int index);

		BuildingType GetFactoryBuilding(int index);

		BuildingType GetTechBuilding(int index);

		void SetTechLevel(int index, int level);

		void SetFactoryBuilding(int index, BuildingType type);

		void SetTechBuilding(int index, BuildingType type);

		bool GetHidden(int index);

		bool GetDisabled(int index);

		bool GetBusy(int index);

		void SetHidden(int index, bool set);

		void SetDisabled(int index, bool set);

		void SetBusy(int index, bool set);

		void SetDefinition(int index, int preset);

		void SetAltDefinition(int index, int index2, int preset);

		void SetCost(int index, int cost);

		property IntPtr PurchaseSettingsDefClassPointer
		{
			IntPtr get();
		}

		property TeamEnum Team
		{
			TeamEnum get();
		}

		property TypeEnum Type
		{
			TypeEnum get();
		}

		property bool PageHidden
		{
			bool get();
			void set(bool value);
		}

		property bool PageDisabled
		{
			bool get();
			void set(bool value);
		}

		property bool PageBusy
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class PurchaseSettingsDefClass : public NetworkObjectClass, public IPurchaseSettingsDefClass
	{
		private:
			IDefinitionClass^ definitionClass;

		public:
			PurchaseSettingsDefClass(IntPtr pointer);

			static IUnmanagedContainer<IPostLoadableClass^>^ CreatePostLoadableClass();
			static IPurchaseSettingsDefClass^ FindDefinition(IPurchaseSettingsDefClass::TypeEnum type, IPurchaseSettingsDefClass::TeamEnum team);
			static int TeamToPurchaseTerminalTeam(int team);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual void OnPostLoad() sealed;

			virtual bool Save(IChunkSaveClass^ csave) sealed;
			virtual bool Load(IChunkLoadClass^ cload) sealed;

			virtual IParameterClass^ LockParameter(int index) sealed;
			virtual void UnlockParameter(int index) sealed;

			virtual IPersistClass^ Create() sealed;
			virtual bool IsValidConfig([Out] String^% message) sealed;

			virtual int GetDefinition(int index) sealed;
			virtual int GetCost(int index) sealed;
			virtual String^ GetName(int index) sealed;
			virtual String^ GetTexture(int index) sealed;
			virtual int GetAltDefinition(int index, int index2) sealed;
			virtual String^ GetAltTexture(int index, int index2) sealed;
			virtual int GetString(int index) sealed;
			virtual int GetTechLevel(int index) sealed;
			virtual bool GetFactoryNotRequired(int index) sealed;
			virtual BuildingType GetFactoryBuilding(int index) sealed;
			virtual BuildingType GetTechBuilding(int index) sealed;
			virtual void SetTechLevel(int index, int level) sealed;
			virtual void SetFactoryBuilding(int index, BuildingType type) sealed;
			virtual void SetTechBuilding(int index, BuildingType type) sealed;
			virtual bool GetHidden(int index) sealed;
			virtual bool GetDisabled(int index) sealed;
			virtual bool GetBusy(int index) sealed;
			virtual void SetHidden(int index, bool set) sealed;
			virtual void SetDisabled(int index, bool set) sealed;
			virtual void SetBusy(int index, bool set) sealed;
			virtual void SetDefinition(int index, int preset) sealed;
			virtual void SetAltDefinition(int index, int index2, int preset) sealed;
			virtual void SetCost(int index, int cost) sealed;

			property IntPtr Pointer
			{
				IntPtr get() override;

				protected:
					void set(IntPtr value) override;
			}

			property IntPtr PurchaseSettingsDefClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr PostLoadableClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr PersistClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr EditableClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr DefinitionClassPointer
			{
				virtual IntPtr get() sealed;
			}	

			property bool IsPostLoadRegistered
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property IPersistFactoryClass^ Factory
			{
				virtual IPersistFactoryClass^ get() sealed;
			}

			property int ParameterCount
			{
				virtual int get() sealed;
			}

			property uint32 ClassID
			{
				virtual uint32 get() sealed;
			}

			property uint32 ID
			{
				virtual uint32 get() sealed;
				virtual void set(uint32 value) sealed;
			}

			property String^ Name
			{
				virtual String^ get() sealed;
				virtual void set(String^ value) sealed;
			}

			property uint32 UserData
			{
				virtual uint32 get() sealed;
				virtual void set(uint32 value) sealed;
			}

			property bool IsSaveEnabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property IPurchaseSettingsDefClass::TeamEnum Team
			{
				virtual IPurchaseSettingsDefClass::TeamEnum get() sealed;
			}

			property IPurchaseSettingsDefClass::TypeEnum Type
			{
				virtual IPurchaseSettingsDefClass::TypeEnum get() sealed;
			}

			property bool PageHidden
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool PageDisabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool PageBusy
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			property ::NetworkObjectClass* InternalNetworkObjectClassPointer
			{
				::NetworkObjectClass* get() override;
			}

			property ::PostLoadableClass* InternalPostLoadableClassPointer
			{
				virtual ::PostLoadableClass* get();
			}

			property ::PersistClass* InternalPersistClassPointer
			{
				virtual ::PersistClass* get();
			}

			property ::EditableClass* InternalEditableClassPointer
			{
				virtual ::EditableClass* get();
			}

			property ::DefinitionClass* InternalDefinitionClassPointer
			{
				virtual ::DefinitionClass* get();
			}

			property ::PurchaseSettingsDefClass* InternalPurchaseSettingsDefClassPointer
			{
				virtual ::PurchaseSettingsDefClass* get();
			}

			property int DefinitionMgrLink
			{
				int get();
				void set(int value);
			}
	};
}