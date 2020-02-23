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

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <TeamPurchaseSettingsDefClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	public interface class ITeamPurchaseSettingsDefClass : public IDefinitionClass, public INetworkObjectClass
	{
		enum class TeamEnum : int
		{
			TeamGDI = ::TeamPurchaseSettingsDefClass::TEAM_GDI,
			TeamNod = ::TeamPurchaseSettingsDefClass::TEAM_NOD
		};

		String^ GetEnlistedName(int index);

		unsigned int GetEnlistedString(int index);

		int GetEnlistedCost(int index);

		int GetEnlistedDefinition(int index);

		String^ GetEnlistedTexture(int index);

		bool GetHidden(int index);

		bool GetDisabled(int index);

		bool GetBusy(int index);

		void SetHidden(int index, bool set);

		void SetDisabled(int index, bool set);

		void SetBusy(int index, bool set);

		void SetEnlistedDefinition(int index, int preset);

		property IntPtr TeamPurchaseSettingsDefClassPointer
		{
			IntPtr get();
		}

		property TeamEnum Team
		{
			TeamEnum get();
		}

		property unsigned int BeaconString
		{
			unsigned int get();
		}

		property String^ BeaconName
		{
			String^ get();
		}

		property int BeaconCost
		{
			int get();
			void set(int value);
		}

		property int BeaconDefinition
		{
			int get();
			void set(int value);
		}

		property String^ BeaconTexture
		{
			String^ get();
		}

		property unsigned int SupplyString
		{
			unsigned int get();
		}

		property String^ SupplyName
		{
			String^ get();
		}

		property String^ SupplyTexture
		{
			String^ get();
		}
	};

	public ref class TeamPurchaseSettingsDefClass : public NetworkObjectClass, public ITeamPurchaseSettingsDefClass
	{
		private:
			IDefinitionClass^ definitionClass;

		public:
			TeamPurchaseSettingsDefClass(IntPtr pointer);

			static IUnmanagedContainer<IPostLoadableClass^>^ CreatePostLoadableClass();
			static ITeamPurchaseSettingsDefClass^ GetDefinition(ITeamPurchaseSettingsDefClass::TeamEnum team);
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

			virtual String^ GetEnlistedName(int index) sealed;
			virtual unsigned int GetEnlistedString(int index) sealed;
			virtual int GetEnlistedCost(int index) sealed;
			virtual int GetEnlistedDefinition(int index) sealed;
			virtual String^ GetEnlistedTexture(int index) sealed;
			virtual bool GetHidden(int index) sealed;
			virtual bool GetDisabled(int index) sealed;
			virtual bool GetBusy(int index) sealed;
			virtual void SetHidden(int index, bool set) sealed;
			virtual void SetDisabled(int index, bool set) sealed;
			virtual void SetBusy(int index, bool set) sealed;
			virtual void SetEnlistedDefinition(int index, int preset) sealed;

			property IntPtr Pointer
			{
				IntPtr get() override;

				protected:
					void set(IntPtr value) override;
			}

			property IntPtr TeamPurchaseSettingsDefClassPointer
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

			property ITeamPurchaseSettingsDefClass::TeamEnum Team
			{
				virtual ITeamPurchaseSettingsDefClass::TeamEnum get() sealed;
			}

			property unsigned int BeaconString
			{
				virtual unsigned int get() sealed;
			}

			property String^ BeaconName
			{
				virtual String^ get() sealed;
			}

			property int BeaconCost
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int BeaconDefinition
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property String^ BeaconTexture
			{
				virtual String^ get() sealed;
			}

			property unsigned int SupplyString
			{
				virtual unsigned int get() sealed;
			}

			property String^ SupplyName
			{
				virtual String^ get() sealed;
			}

			property String^ SupplyTexture
			{
				virtual String^ get() sealed;
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

			property ::TeamPurchaseSettingsDefClass* InternalTeamPurchaseSettingsDefClassPointer
			{
				virtual ::TeamPurchaseSettingsDefClass* get();
			}

			property int DefinitionMgrLink
			{
				int get();
				void set(int value);
			}
	};
}