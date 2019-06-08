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

#include "Mengine_vector.h"
#include "Mda_event.h"

#pragma managed(push, off)

class DAGameManager;

#pragma managed(pop)

namespace RenSharp
{
	interface class IDAGameModeFactoryClass;
	interface class IDAGameFeatureFactoryClass;
	interface class IRenSharpGameFeatureFactoryClass;
	interface class IRenSharpGameFeatureClass;
	interface class IDAGameFeatureClass;
	interface class IRenSharpGameModeClass;
	interface class IRenSharpGameModeFactoryClass;
	interface class IDAGameModeClass;

	public interface class IDAGameManager : public IDAEventClass
	{
		property IntPtr DAGameManagerPointer
		{
			IntPtr get();
		}
	};

	public ref class DAGameManager : public DAEventClass, public IDAGameManager
	{
		private:
			static Generic::IDictionary<IntPtr, IRenSharpGameFeatureFactoryClass^>^ managedGameFeatureFactories;
			static Generic::IDictionary<IntPtr, IRenSharpGameFeatureClass^>^ managedGameFeatures;
			static Generic::IDictionary<IntPtr, IRenSharpGameModeFactoryClass^>^ managedGameModeFactories;
			static Generic::IDictionary<IntPtr, IRenSharpGameModeClass^>^ managedGameModes;

			static DAGameManager();

		// Although you can instantiate a DAGameManager class, it doesn't make any sense so I left it out
		public:
			DAGameManager(IntPtr pointer);
		
			static void OnManagedGameFeatureFactoryDestructed(IntPtr factory);
			static bool IsManagedGameFeatureFactory(IntPtr factory);
			static bool IsManagedGameFeatureFactory(IDAGameFeatureFactoryClass^ factory);
			static IRenSharpGameFeatureFactoryClass^ AsManagedGameFeatureFactory(IntPtr factory);
			static IRenSharpGameFeatureFactoryClass^ AsManagedGameFeatureFactory(IDAGameFeatureFactoryClass^ factory);	
			static void OnManagedGameFeatureDestructed(IntPtr gameFeature);
			static bool IsManagedGameFeature(IntPtr gameFeature);
			static bool IsManagedGameFeature(IDAGameFeatureClass^ gameFeature);
			static IRenSharpGameFeatureClass^ AsManagedGameFeature(IntPtr gameFeature);
			static IRenSharpGameFeatureClass^ AsManagedGameFeature(IDAGameFeatureClass^ gameFeature);		
			static void OnManagedGameModeFactoryDestructed(IntPtr factory);
			static bool IsManagedGameModeFactory(IntPtr factory);
			static bool IsManagedGameModeFactory(IDAGameModeFactoryClass^ factory);
			static IRenSharpGameModeFactoryClass^ AsManagedGameModeFactory(IntPtr factory);
			static IRenSharpGameModeFactoryClass^ AsManagedGameModeFactory(IDAGameModeFactoryClass^ factory);
			static void OnManagedGameModeDestructed(IntPtr gameMode);
			static bool IsManagedGameMode(IntPtr gameMode);
			static bool IsManagedGameMode(IDAGameModeClass^ gameMode);
			static IRenSharpGameModeClass^ AsManagedGameMode(IntPtr gameMode);
			static IRenSharpGameModeClass^ AsManagedGameMode(IDAGameModeClass^ gameMode);

			static bool IsGameMode(String^ name);
			static IDAGameModeFactoryClass^ FindGameMode(String^ name);
			static IDAGameFeatureFactoryClass^ FindGameFeature(String^ name);
			static void AddGameMode(IDAGameModeFactoryClass^ factory);
			static void AddGameMode(IRenSharpGameModeFactoryClass^ factory);
			static void AddGameFeature(IDAGameFeatureFactoryClass^ factory);
			static void AddGameFeature(IRenSharpGameFeatureFactoryClass^ factory);

			property IntPtr DAGameManagerPointer
			{
				virtual IntPtr get() sealed;
			}

			static property IDAGameModeFactoryClass^ GameMode
			{
				IDAGameModeFactoryClass^ get();
			}

			static property String^ GameModeLongName
			{
				String^ get();
			}

			static property String^ GameModeShortName
			{
				String^ get();
			}

			static property IDynamicVectorClass<IDAGameFeatureFactoryClass^>^ GameFeatures
			{
				IDynamicVectorClass<IDAGameFeatureFactoryClass^>^ get();
			}

			static property bool IsShutdownPending
			{
				bool get();
			}

			static property String^ Map
			{
				String^ get();
			}

		internal:
			static void Shutdown();

			static void RegisterManagedGameFeature(IRenSharpGameFeatureClass^ gameFeature);
			static void RegisterManagedGameFeatureFactory(IRenSharpGameFeatureFactoryClass^ factory);
			static void RegisterManagedGameMode(IRenSharpGameModeClass^ gameMode);
			static void RegisterManagedGameModeFactory(IRenSharpGameModeFactoryClass^ factory);
			static void UnregisterManagedGameFeatureFactory(IRenSharpGameFeatureFactoryClass^ factory);
			static void UnregisterManagedGameFeature(IRenSharpGameFeatureClass^ gameFeature);
			static void UnregisterManagedGameModeFactory(IRenSharpGameModeFactoryClass^ factory);
			static void UnregisterManagedGameMode(IRenSharpGameModeClass^ gameMode);

		protected:
			property ::DAEventClass* InternalDAEventClassPointer
			{
				::DAEventClass* get() override;
			}

			property ::DAGameManager* InternalDAGameManagerPointer
			{
				virtual ::DAGameManager* get();
			}
	};
}