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

#include "Mda_event.h"
#include "Mda_gamefeature.h"
#include "Mengine_vector.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_cratemanager.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	interface class IDACrateFactoryClass;
	interface class IDACrateModifierFactoryClass;
	interface class IDACrateClass;
	interface class IDACrateModifierClass;
	value class Vector3;
	interface class IRenSharpCrateModifierClass;
	interface class IRenSharpCrateModifierFactoryClass;
	interface class IRenSharpCrateFactoryClass;
	interface class IRenSharpCrateClass;

#pragma managed(push, off)

	class DACrateManagerHelper : public ::DACrateManager
	{
		private:
			DACrateManagerHelper() = default;

		public:
			static ::DynamicVectorClass<::DACrateFactoryClass*>& GetCrates()
			{
				return Crates;
			}

			static ::DynamicVectorClass<::DACrateModifierFactoryClass*>& GetCrateModifiers()
			{
				return CrateModifiers;
			}

			static float& GetOdds()
			{
				return Odds;
			}

			::DynamicVectorClass<::PhysicalGameObj*>& GetCrateObjs()
			{
				return CrateObjs;
			}

			::Vector3& GetLastCratePosition()
			{
				return LastCratePosition;
			}

			int& GetMaxCrates()
			{
				return MaxCrates;
			}

			::StringClass& GetModel()
			{
				return Model;
			}

			float& GetSpawnTimeMin()
			{
				return SpawnTimeMin;
			}

			float& GetSpawnTimeMax()
			{
				return SpawnTimeMax;
			}

			float& GetFirstSpawnTimeMin()
			{
				return FirstSpawnTimeMin;
			}

			float& GetFirstSpawnTimeMax()
			{
				return FirstSpawnTimeMax;
			}

			::DynamicVectorClass<::Vector3>& GetSpawners()
			{
				return Spawners;
			}

			::DynamicVectorClass<::Vector3*>& GetActiveSpawners()
			{
				return ActiveSpawners;
			}
	};

#pragma managed(pop)

	public interface class IDACrateManager : public IDAEventClass, public IDAGameFeatureClass
	{
		bool SelectSpawner([Out] Vector3% spawnerPos);

		bool CrateChatCommand(IcPlayer^ player, IDATokenClass^ text, TextMessageEnum chatType);

		bool CratesChatCommand(IcPlayer^ player, IDATokenClass^ text, TextMessageEnum chatType);

		bool ShowCrateSpawnersChatCommand(IcPlayer^ player, IDATokenClass^ text, TextMessageEnum chatType);

		bool HideCrateSpawnersChatCommand(IcPlayer^ player, IDATokenClass^ text, TextMessageEnum chatType);

		property IntPtr DACrateManagerPointer
		{
			IntPtr get();
		}
	};

	public ref class DACrateManager : public DAEventClass, public IDACrateManager
	{
		// Although you can instantiate a DACrateManager class, it doesn't make any sense so I left it out
		private:
			static Generic::IDictionary<IntPtr, IRenSharpCrateModifierFactoryClass^>^ managedCrateModifierFactories;
			static Generic::IDictionary<IntPtr, IRenSharpCrateModifierClass^>^ managedCrateModifiers;
			static Generic::IDictionary<IntPtr, IRenSharpCrateFactoryClass^>^ managedCrateFactories;
			static Generic::IDictionary<IntPtr, IRenSharpCrateClass^>^ managedCrates;

			static DACrateManager();

			IDAGameFeatureClass^ daGameFeatureClass;

		public:
			DACrateManager(IntPtr pointer);

			static void OnManagedCrateModifierFactoryDestructed(IntPtr factory);
			static bool IsManagedCrateModifierFactory(IntPtr factory);
			static bool IsManagedCrateModifierFactory(IDACrateModifierFactoryClass^ factory);
			static IRenSharpCrateModifierFactoryClass^ AsManagedCrateModifierFactory(IntPtr factory);
			static IRenSharpCrateModifierFactoryClass^ AsManagedCrateModifierFactory(IDACrateModifierFactoryClass^ factory);
			static void OnManagedCrateModifierDestructed(IntPtr crateModifier);
			static bool IsManagedCrateModifier(IntPtr crateModifier);
			static bool IsManagedCrateModifier(IDACrateModifierClass^ crateModifier);
			static IRenSharpCrateModifierClass^ AsManagedCrateModifier(IntPtr crateModifier);
			static IRenSharpCrateModifierClass^ AsManagedCrateModifier(IDACrateModifierClass^ crateModifier);
			static void OnManagedCrateFactoryDestructed(IntPtr factory);
			static bool IsManagedCrateFactory(IntPtr factory);
			static bool IsManagedCrateFactory(IDACrateFactoryClass^ factory);
			static IRenSharpCrateFactoryClass^ AsManagedCrateFactory(IntPtr factory);
			static IRenSharpCrateFactoryClass^ AsManagedCrateFactory(IDACrateFactoryClass^ factory);
			static void OnManagedCrateDestructed(IntPtr crate);
			static bool IsManagedCrate(IntPtr crate);
			static bool IsManagedCrate(IDACrateClass^ crate);
			static IRenSharpCrateClass^ AsManagedCrate(IntPtr crate);
			static IRenSharpCrateClass^ AsManagedCrate(IDACrateClass^ crate);

			static void StaticInit();
			static void AddCrate(IDACrateFactoryClass^ factory);
			static void AddCrate(IRenSharpCrateFactoryClass^ factory);
			static void AddCrateModifier(IDACrateModifierFactoryClass^ factory);
			static void AddCrateModifier(IRenSharpCrateModifierFactoryClass^ factory);
			static IDACrateClass^ GetCrate(String^ name);
			static IUnmanagedContainer<IDACrateModifierClass^>^ CreateCrateModifier(String^ name, String^ parameters);
			static void CalculateOdds(IcPlayer^ player);
			static IDACrateClass^ SelectCrate(IcPlayer^ player);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual void Init() sealed;
			virtual IRenSharpGameFeatureClass^ AsManagedGameFeature() sealed;

			virtual bool SelectSpawner([Out] Vector3% spawnerPos) sealed;
			virtual bool CrateChatCommand(IcPlayer^ player, IDATokenClass^ text, TextMessageEnum chatType) sealed;
			virtual bool CratesChatCommand(IcPlayer^ player, IDATokenClass^ text, TextMessageEnum chatType) sealed;
			virtual bool ShowCrateSpawnersChatCommand(IcPlayer^ player, IDATokenClass^ text, TextMessageEnum chatType) sealed;
			virtual bool HideCrateSpawnersChatCommand(IcPlayer^ player, IDATokenClass^ text, TextMessageEnum chatType) sealed;

			static property float Odds
			{
				float get();

				protected:
					void set(float value);
			}

			property IntPtr Pointer
			{
				IntPtr get() override;

				protected:
					void set(IntPtr value) override;
			}

			property IntPtr DACrateManagerPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr DAGameFeatureClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property String^ Name
			{
				virtual String^ get() sealed;
			}

			property IDAGameFeatureFactoryClass^ Factory
			{
				virtual IDAGameFeatureFactoryClass^ get() sealed;
				virtual void set(IDAGameFeatureFactoryClass^ value) sealed;
			}

			property bool IsManagedGameFeature
			{
				virtual bool get() sealed;
			}

		internal:
			static void Shutdown();

			static void RegisterManagedCrateModifierFactory(IRenSharpCrateModifierFactoryClass^ factory);
			static void RegisterManagedCrateModifier(IRenSharpCrateModifierClass^ crateModifier);
			static void RegisterManagedCrateFactory(IRenSharpCrateFactoryClass^ factory);
			static void RegisterManagedCrate(IRenSharpCrateClass^ crate);
			static void UnregisterManagedCrateModifierFactory(IRenSharpCrateModifierFactoryClass^ factory);
			static void UnregisterManagedCrateModifier(IRenSharpCrateModifierClass^ crateModifier);
			static void UnregisterManagedCrateFactory(IRenSharpCrateFactoryClass^ factory);
			static void UnregisterManagedCrate(IRenSharpCrateClass^ crate);

		public:
			static property IDynamicVectorClass<IDACrateFactoryClass^>^ Crates
			{
				IDynamicVectorClass<IDACrateFactoryClass^>^ get();
				void set(IDynamicVectorClass<IDACrateFactoryClass^>^ value);
			}

			static property IDynamicVectorClass<IDACrateModifierFactoryClass^>^ CrateModifiers
			{
				IDynamicVectorClass<IDACrateModifierFactoryClass^>^ get();
				void set(IDynamicVectorClass<IDACrateModifierFactoryClass^>^ value);
			}

			property ::DAEventClass* InternalDAEventClassPointer
			{
				::DAEventClass* get() override;
			}

			property ::DAGameFeatureClass* InternalDAGameFeatureClassPointer
			{
				virtual ::DAGameFeatureClass* get();
			}

			property ::DACrateManager* InternalDACrateManagerPointer
			{
				virtual ::DACrateManager* get();
			}

			property IDynamicVectorClass<IPhysicalGameObj^>^ CrateObjs
			{
				IDynamicVectorClass<IPhysicalGameObj^>^ get();
				void set(IDynamicVectorClass<IPhysicalGameObj^>^ value);
			}

			property Vector3 LastCratePosition
			{
				Vector3 get();
				void set(Vector3 value);
			}

			property int MaxCrates
			{
				int get();
				void set(int value);
			}

			property String^ Model
			{
				String^ get();
				void set(String^ value);
			}

			property float SpawnTimeMin
			{
				float get();
				void set(float value);
			}

			property float SpawnTimeMax
			{
				float get();
				void set(float value);
			}

			property float FirstSpawnTimeMin
			{
				float get();
				void set(float value);
			}

			property float FirstSpawnTimeMax
			{
				float get();
				void set(float value);
			}
			
			property IDynamicVectorClass<Vector3>^ Spawners
			{
				IDynamicVectorClass<Vector3>^ get();
				void set(IDynamicVectorClass<Vector3>^ value);
			}

			property IDynamicVectorClass<Vector3>^ ActiveSpawners
			{
				IDynamicVectorClass<Vector3>^ get();
				void set(IDynamicVectorClass<Vector3>^ value);
			}
	};
}