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

#include "stdafx.h"
#include "Mda_game.h"

#include "Mda_gamemode.h"
#include "Mda_gamefeature.h"
#include "MDAGameFeatureClassPtrDynamicVectorClass.h"
#include "RenSharpGameFeatureClass.h"
#include "RenSharpGameFeatureFactoryClass.h"
#include "RenSharpGameModeClass.h"
#include "RenSharpGameModeFactoryClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_game.h>

class RenSharpGameFeatureFactoryClass;
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	static DAGameManager::DAGameManager()
	{
		managedGameFeatureFactories = gcnew Generic::Dictionary<IntPtr, IRenSharpGameFeatureFactoryClass^>();
		managedGameFeatures = gcnew Generic::Dictionary<IntPtr, IRenSharpGameFeatureClass^>();
		managedGameModeFactories = gcnew Generic::Dictionary<IntPtr, IRenSharpGameModeFactoryClass^>();
		managedGameModes = gcnew Generic::Dictionary<IntPtr, IRenSharpGameModeClass^>();
	}

	DAGameManager::DAGameManager(IntPtr pointer)
		: DAEventClass(pointer)
	{

	}

	void DAGameManager::OnManagedGameFeatureFactoryDestructed(IntPtr factory)
	{
		IRenSharpGameFeatureFactoryClass^ managedFactory = AsManagedGameFeatureFactory(factory);
		if (managedFactory != nullptr && managedFactory->IsAttached)
		{
			managedFactory->DestroyPointer = false;

#pragma push_macro("delete")
#undef delete

			delete managedFactory;
			managedFactory = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool DAGameManager::IsManagedGameFeatureFactory(IntPtr factory)
	{
		return managedGameFeatureFactories->ContainsKey(factory);
	}

	bool DAGameManager::IsManagedGameFeatureFactory(IDAGameFeatureFactoryClass^ factory)
	{
		if (factory == nullptr || factory->DAGameFeatureFactoryClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}

		return IsManagedGameFeatureFactory(factory->DAGameFeatureFactoryClassPointer);
	}

	IRenSharpGameFeatureFactoryClass^ DAGameManager::AsManagedGameFeatureFactory(IntPtr factory)
	{
		IRenSharpGameFeatureFactoryClass^ result = nullptr;
		managedGameFeatureFactories->TryGetValue(factory, result);

		return result;
	}

	IRenSharpGameFeatureFactoryClass^ DAGameManager::AsManagedGameFeatureFactory(IDAGameFeatureFactoryClass^ factory)
	{
		if (factory == nullptr || factory->DAGameFeatureFactoryClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}

		return AsManagedGameFeatureFactory(factory->DAGameFeatureFactoryClassPointer);
	}

	void DAGameManager::OnManagedGameFeatureDestructed(IntPtr gameFeature)
	{
		IRenSharpGameFeatureClass^ managedGameFeature = AsManagedGameFeature(gameFeature);
		if (managedGameFeature != nullptr && managedGameFeature->IsAttached)
		{
			managedGameFeature->DestroyPointer = false;

#pragma push_macro("delete")
#undef delete

			delete managedGameFeature;
			managedGameFeature = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool DAGameManager::IsManagedGameFeature(IntPtr gameFeature)
	{
		return managedGameFeatures->ContainsKey(gameFeature);
	}

	bool DAGameManager::IsManagedGameFeature(IDAGameFeatureClass^ gameFeature)
	{
		if (gameFeature == nullptr || gameFeature->DAGameFeatureClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("gameFeature");
		}

		return IsManagedGameFeature(gameFeature->DAGameFeatureClassPointer);
	}

	IRenSharpGameFeatureClass^ DAGameManager::AsManagedGameFeature(IntPtr gameFeature)
	{
		IRenSharpGameFeatureClass^ result = nullptr;
		managedGameFeatures->TryGetValue(gameFeature, result);

		return result;
	}

	IRenSharpGameFeatureClass^ DAGameManager::AsManagedGameFeature(IDAGameFeatureClass^ gameFeature)
	{
		if (gameFeature == nullptr || gameFeature->DAGameFeatureClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("gameFeature");
		}

		return AsManagedGameFeature(gameFeature->DAGameFeatureClassPointer);
	}

	void DAGameManager::OnManagedGameModeFactoryDestructed(IntPtr factory)
	{
		IRenSharpGameModeFactoryClass^ managedFactory = AsManagedGameModeFactory(factory);
		if (managedFactory != nullptr && managedFactory->IsAttached)
		{
			managedFactory->DestroyPointer = false;

#pragma push_macro("delete")
#undef delete

			delete managedFactory;
			managedFactory = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool DAGameManager::IsManagedGameModeFactory(IntPtr factory)
	{
		return managedGameModeFactories->ContainsKey(factory);
	}

	bool DAGameManager::IsManagedGameModeFactory(IDAGameModeFactoryClass^ factory)
	{
		if (factory == nullptr || factory->DAGameModeFactoryClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}

		return IsManagedGameModeFactory(factory->DAGameModeFactoryClassPointer);
	}

	IRenSharpGameModeFactoryClass^ DAGameManager::AsManagedGameModeFactory(IntPtr factory)
	{
		IRenSharpGameModeFactoryClass^ result = nullptr;
		managedGameModeFactories->TryGetValue(factory, result);

		return result;
	}

	IRenSharpGameModeFactoryClass^ DAGameManager::AsManagedGameModeFactory(IDAGameModeFactoryClass^ factory)
	{
		if (factory == nullptr || factory->DAGameModeFactoryClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}

		return AsManagedGameModeFactory(factory->DAGameModeFactoryClassPointer);
	}

	void DAGameManager::OnManagedGameModeDestructed(IntPtr gameMode)
	{
		IRenSharpGameModeClass^ managedGameMode = AsManagedGameMode(gameMode);
		if (managedGameMode != nullptr && managedGameMode->IsAttached)
		{
			managedGameMode->DestroyPointer = false;

#pragma push_macro("delete")
#undef delete

			delete managedGameMode;
			managedGameMode = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool DAGameManager::IsManagedGameMode(IntPtr gameMode)
	{
		return managedGameModes->ContainsKey(gameMode);
	}

	bool DAGameManager::IsManagedGameMode(IDAGameModeClass^ gameMode)
	{
		if (gameMode == nullptr || gameMode->DAGameModeClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("gameMode");
		}

		return IsManagedGameMode(gameMode->DAGameModeClassPointer);
	}

	IRenSharpGameModeClass^ DAGameManager::AsManagedGameMode(IntPtr gameMode)
	{
		IRenSharpGameModeClass^ result = nullptr;
		managedGameModes->TryGetValue(gameMode, result);

		return result;
	}

	IRenSharpGameModeClass^ DAGameManager::AsManagedGameMode(IDAGameModeClass^ gameMode)
	{
		if (gameMode == nullptr || gameMode->DAGameModeClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("gameMode");
		}

		return AsManagedGameMode(gameMode->DAGameModeClassPointer);
	}

	bool DAGameManager::IsGameMode(String^ name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			return ::DAGameManager::Is_Game_Mode(
				reinterpret_cast<char*>(nameHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	IDAGameModeFactoryClass^ DAGameManager::FindGameMode(String^ name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			auto result = ::DAGameManager::Find_Game_Mode(
				reinterpret_cast<char*>(nameHandle.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew DAGameModeFactoryClass(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	IDAGameFeatureFactoryClass^ DAGameManager::FindGameFeature(String^ name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			auto result = ::DAGameManager::Find_Game_Feature(
				reinterpret_cast<char*>(nameHandle.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew DAGameFeatureFactoryClass(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	void DAGameManager::AddGameMode(IDAGameModeFactoryClass^ factory)
	{
		if (factory == nullptr || factory->DAGameModeFactoryClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}

		if (factory->IsManagedGameModeFactory)
		{
			AddGameMode(factory->AsManagedGameModeFactory());
		}
		else
		{
			::DAGameManager::Add_Game_Mode(
				reinterpret_cast<::DAGameModeFactoryClass*>(factory->DAGameModeFactoryClassPointer.ToPointer()));
		}
	}

	void DAGameManager::AddGameMode(IRenSharpGameModeFactoryClass^ factory)
	{
		if (factory == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}
		
		if (!factory->IsAttached)
		{
			factory->AttachToUnmanagedObject(); // Already added in unmanaged constructor
			factory->RegisterManagedObject();
		}
		else
		{
			::DAGameManager::Add_Game_Mode(
				reinterpret_cast<::DAGameModeFactoryClass*>(factory->DAGameModeFactoryClassPointer.ToPointer()));
		}
	}

	void DAGameManager::AddGameFeature(IDAGameFeatureFactoryClass^ factory)
	{
		if (factory == nullptr || factory->DAGameFeatureFactoryClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}

		if (factory->IsManagedGameFeatureFactory)
		{
			AddGameFeature(factory->AsManagedGameFeatureFactory());
		}
		else
		{
			::DAGameManager::Add_Game_Feature(
				reinterpret_cast<::DAGameFeatureFactoryClass*>(factory->DAGameFeatureFactoryClassPointer.ToPointer()));
		}
	}

	void DAGameManager::AddGameFeature(IRenSharpGameFeatureFactoryClass^ factory)
	{
		if (factory == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}
		
		if (!factory->IsAttached)
		{
			factory->AttachToUnmanagedObject(); // Already added in unmanaged constructor
			factory->RegisterManagedObject();
		}
		else
		{
			::DAGameManager::Add_Game_Feature(
				reinterpret_cast<::DAGameFeatureFactoryClass*>(factory->DAGameFeatureFactoryClassPointer.ToPointer()));
		}
	}

	IntPtr DAGameManager::DAGameManagerPointer::get()
	{
		return IntPtr(InternalDAGameManagerPointer);
	}

	IDAGameModeFactoryClass^ DAGameManager::GameMode::get()
	{
		auto result = ::DAGameManager::Get_Game_Mode();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DAGameModeFactoryClass(IntPtr(result));
		}
	}

	String^ DAGameManager::GameModeLongName::get()
	{
		auto result = ::DAGameManager::Get_Game_Mode_Long_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String^ DAGameManager::GameModeShortName::get()
	{
		auto result = ::DAGameManager::Get_Game_Mode_Short_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	IDynamicVectorClass<IDAGameFeatureFactoryClass^>^ DAGameManager::GameFeatures::get()
	{
		return gcnew DAGameFeatureFactoryClassPtrDynamicVectorClass(IntPtr(const_cast<::DynamicVectorClass<::DAGameFeatureFactoryClass*>*>(&::DAGameManager::Get_Game_Features())));
	}

	bool DAGameManager::IsShutdownPending::get()
	{
		return ::DAGameManager::Is_Shutdown_Pending();
	}

	String^ DAGameManager::Map::get()
	{
		return gcnew String(::DAGameManager::Get_Map());
	}

	void DAGameManager::Shutdown()
	{
		auto tmpGameFeatures = gcnew Generic::Dictionary<IntPtr, IRenSharpGameFeatureClass^>(managedGameFeatures);

		for each (auto gameFeature in tmpGameFeatures->Values)
		{
#pragma push_macro("delete")
#undef delete

			delete gameFeature;
			gameFeature = nullptr;

#pragma pop_macro("delete")
		}

		tmpGameFeatures->Clear();
		managedGameFeatures->Clear();

		Generic::IDictionary<IntPtr, IRenSharpGameFeatureFactoryClass^>^ tmpdGameFeatureFactories = gcnew Generic::Dictionary<IntPtr, IRenSharpGameFeatureFactoryClass^>(managedGameFeatureFactories);

		for each (auto gameFeatureFactory in tmpdGameFeatureFactories->Values)
		{
#pragma push_macro("delete")
#undef delete

			delete gameFeatureFactory;
			gameFeatureFactory = nullptr;

#pragma pop_macro("delete")
		}

		tmpdGameFeatureFactories->Clear();
		managedGameFeatureFactories->Clear();

		auto tmpManagedGameModes = gcnew Generic::Dictionary<IntPtr, IRenSharpGameModeClass^>(managedGameModes);

		for each (auto gameMode in tmpManagedGameModes->Values)
		{
#pragma push_macro("delete")
#undef delete

			delete gameMode;
			gameMode = nullptr;

#pragma pop_macro("delete")
		}

		tmpManagedGameModes->Clear();
		managedGameModes->Clear();

		auto tmpManagedGameModeFactories = gcnew Generic::Dictionary<IntPtr, IRenSharpGameModeFactoryClass^>(managedGameModeFactories);

		for each (auto gameModeFactory in tmpManagedGameModeFactories->Values)
		{
#pragma push_macro("delete")
#undef delete

			delete gameModeFactory;
			gameModeFactory = nullptr;

#pragma pop_macro("delete")
		}

		tmpManagedGameModeFactories->Clear();
		managedGameModeFactories->Clear();
	}

	void DAGameManager::RegisterManagedGameFeature(IRenSharpGameFeatureClass^ gameFeature)
	{
		if (gameFeature == nullptr)
		{
			throw gcnew ArgumentNullException("gameFeature");
		}
		else if (!gameFeature->IsAttached)
		{
			throw gcnew ArgumentException("Game feature is not attached.");
		}
		else if (Imports::IsShuttingDown())
		{
			throw gcnew NotSupportedException("Engine is shutting down");
		}

		managedGameFeatures->Add(gameFeature->DAGameFeatureClassPointer, gameFeature);
	}

	void DAGameManager::RegisterManagedGameFeatureFactory(IRenSharpGameFeatureFactoryClass^ factory)
	{
		if (factory == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}
		else if (!factory->IsAttached)
		{
			throw gcnew ArgumentException("Game feature factory is not attached.");
		}
		else if (Imports::IsShuttingDown())
		{
			throw gcnew NotSupportedException("Engine is shutting down");
		}

		managedGameFeatureFactories->Add(factory->DAGameFeatureFactoryClassPointer, factory);
	}

	void DAGameManager::RegisterManagedGameMode(IRenSharpGameModeClass^ gameMode)
	{
		if (gameMode == nullptr)
		{
			throw gcnew ArgumentNullException("gameMode");
		}
		else if (!gameMode->IsAttached)
		{
			throw gcnew ArgumentException("Game mode is not attached.");
		}
		else if (Imports::IsShuttingDown())
		{
			throw gcnew NotSupportedException("Engine is shutting down");
		}

		managedGameModes->Add(gameMode->DAGameModeClassPointer, gameMode);
	}

	void DAGameManager::RegisterManagedGameModeFactory(IRenSharpGameModeFactoryClass^ factory)
	{
		if (factory == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}
		else if (!factory->IsAttached)
		{
			throw gcnew ArgumentException("Game mode factory is not attached.");
		}
		else if (Imports::IsShuttingDown())
		{
			throw gcnew NotSupportedException("Engine is shutting down");
		}

		managedGameModeFactories->Add(factory->DAGameModeFactoryClassPointer, factory);
	}

	void DAGameManager::UnregisterManagedGameFeatureFactory(IRenSharpGameFeatureFactoryClass^ factory)
	{
		if (factory == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}

		managedGameFeatureFactories->Remove(factory->DAGameFeatureFactoryClassPointer);
	}

	void DAGameManager::UnregisterManagedGameFeature(IRenSharpGameFeatureClass^ gameFeature)
	{
		if (gameFeature == nullptr)
		{
			throw gcnew ArgumentNullException("gameFeature");
		}

		managedGameFeatures->Remove(gameFeature->DAGameFeatureClassPointer);
	}

	void DAGameManager::UnregisterManagedGameModeFactory(IRenSharpGameModeFactoryClass^ factory)
	{
		if (factory == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}

		managedGameModeFactories->Remove(factory->DAGameModeFactoryClassPointer);
	}

	void DAGameManager::UnregisterManagedGameMode(IRenSharpGameModeClass^ gameMode)
	{
		if (gameMode == nullptr)
		{
			throw gcnew ArgumentNullException("gameMode");
		}

		managedGameModes->Remove(gameMode->DAGameModeClassPointer);
	}

	::DAEventClass* DAGameManager::InternalDAEventClassPointer::get()
	{
		return InternalDAGameManagerPointer;
	}

	::DAGameManager* DAGameManager::InternalDAGameManagerPointer::get()
	{
		return reinterpret_cast<::DAGameManager*>(Pointer.ToPointer());
	}
}