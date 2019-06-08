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
#include "Mda_cratemanager.h"

#include "MVector3.h"
#include "MVector3DynamicVectorClass.h"
#include "MVector3PtrDynamicVectorClass.h"
#include "MPhysicalGameObjPtrDynamicVectorClass.h"
#include "MDACrateFactoryClassPtrDynamicVectorClass.h"
#include "MDACrateModifierFactoryClassPtrDynamicVectorClass.h"
#include "Mda_crate.h"
#include "McPlayer.h"
#include "Mda_token.h"
#include "RenSharpCrateModifierClass.h"
#include "RenSharpCrateModifierFactoryClass.h"
#include "RenSharpCrateClass.h"
#include "RenSharpCrateFactoryClass.h"

namespace RenSharp
{
	static DACrateManager::DACrateManager()
	{
		managedCrateModifierFactories = gcnew Generic::Dictionary<IntPtr, IRenSharpCrateModifierFactoryClass^>();
		managedCrateModifiers = gcnew Generic::Dictionary<IntPtr, IRenSharpCrateModifierClass^>();
		managedCrateFactories = gcnew Generic::Dictionary<IntPtr, IRenSharpCrateFactoryClass^>();
		managedCrates = gcnew Generic::Dictionary<IntPtr, IRenSharpCrateClass^>();
	}

	DACrateManager::DACrateManager(IntPtr pointer)
		: DAEventClass(pointer)

	{
		daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
	}

	void DACrateManager::OnManagedCrateModifierFactoryDestructed(IntPtr factory)
	{
		IRenSharpCrateModifierFactoryClass^ managedFactory = AsManagedCrateModifierFactory(factory);
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

	bool DACrateManager::IsManagedCrateModifierFactory(IntPtr factory)
	{
		return managedCrateModifierFactories->ContainsKey(factory);
	}

	bool DACrateManager::IsManagedCrateModifierFactory(IDACrateModifierFactoryClass^ factory)
	{
		if (factory == nullptr || factory->DACrateModifierFactoryClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}

		return IsManagedCrateModifierFactory(factory->DACrateModifierFactoryClassPointer);
	}

	IRenSharpCrateModifierFactoryClass^ DACrateManager::AsManagedCrateModifierFactory(IntPtr factory)
	{
		IRenSharpCrateModifierFactoryClass^ result = nullptr;
		managedCrateModifierFactories->TryGetValue(factory, result);

		return result;
	}

	IRenSharpCrateModifierFactoryClass^ DACrateManager::AsManagedCrateModifierFactory(IDACrateModifierFactoryClass^ factory)
	{
		if (factory == nullptr || factory->DACrateModifierFactoryClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}

		return AsManagedCrateModifierFactory(factory->DACrateModifierFactoryClassPointer);
	}

	void DACrateManager::OnManagedCrateModifierDestructed(IntPtr crateModifier)
	{
		IRenSharpCrateModifierClass^ managedModifier = AsManagedCrateModifier(crateModifier);
		if (managedModifier != nullptr && managedModifier->IsAttached)
		{
			managedModifier->DestroyPointer = false;

#pragma push_macro("delete")
#undef delete

			delete managedModifier;
			managedModifier = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool DACrateManager::IsManagedCrateModifier(IntPtr crateModifier)
	{
		return managedCrateModifiers->ContainsKey(crateModifier);
	}

	bool DACrateManager::IsManagedCrateModifier(IDACrateModifierClass^ crateModifier)
	{
		if (crateModifier == nullptr || crateModifier->DACrateModifierClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("crateModifier");
		}

		return IsManagedCrateModifier(crateModifier->DACrateModifierClassPointer);
	}

	IRenSharpCrateModifierClass^ DACrateManager::AsManagedCrateModifier(IntPtr crateModifier)
	{
		IRenSharpCrateModifierClass^ result = nullptr;
		managedCrateModifiers->TryGetValue(crateModifier, result);

		return result;
	}

	IRenSharpCrateModifierClass^ DACrateManager::AsManagedCrateModifier(IDACrateModifierClass^ crateModifier)
	{
		if (crateModifier == nullptr || crateModifier->DACrateModifierClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("crateModifier");
		}

		return AsManagedCrateModifier(crateModifier->DACrateModifierClassPointer);
	}

	void DACrateManager::OnManagedCrateFactoryDestructed(IntPtr factory)
	{
		IRenSharpCrateFactoryClass^ managedFactory = AsManagedCrateFactory(factory);
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

	bool DACrateManager::IsManagedCrateFactory(IntPtr factory)
	{
		return managedCrateFactories->ContainsKey(factory);
	}

	bool DACrateManager::IsManagedCrateFactory(IDACrateFactoryClass^ factory)
	{
		if (factory == nullptr || factory->DACrateFactoryClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}

		return IsManagedCrateFactory(factory->DACrateFactoryClassPointer);
	}

	IRenSharpCrateFactoryClass^ DACrateManager::AsManagedCrateFactory(IntPtr factory)
	{
		IRenSharpCrateFactoryClass^ result = nullptr;
		managedCrateFactories->TryGetValue(factory, result);

		return result;
	}

	IRenSharpCrateFactoryClass^ DACrateManager::AsManagedCrateFactory(IDACrateFactoryClass^ factory)
	{
		if (factory == nullptr || factory->DACrateFactoryClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}

		return AsManagedCrateFactory(factory->DACrateFactoryClassPointer);
	}

	void DACrateManager::OnManagedCrateDestructed(IntPtr crate)
	{
		IRenSharpCrateClass^ managed = AsManagedCrate(crate);
		if (managed != nullptr && managed->IsAttached)
		{
			managed->DestroyPointer = false;

#pragma push_macro("delete")
#undef delete

			delete managed;
			managed = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool DACrateManager::IsManagedCrate(IntPtr crate)
	{
		return managedCrates->ContainsKey(crate);
	}

	bool DACrateManager::IsManagedCrate(IDACrateClass^ crate)
	{
		if (crate == nullptr || crate->DACrateClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("crate");
		}

		return IsManagedCrate(crate->DACrateClassPointer);
	}

	IRenSharpCrateClass^ DACrateManager::AsManagedCrate(IntPtr crate)
	{
		IRenSharpCrateClass^ result = nullptr;
		managedCrates->TryGetValue(crate, result);

		return result;
	}

	IRenSharpCrateClass^ DACrateManager::AsManagedCrate(IDACrateClass^ crate)
	{
		if (crate == nullptr || crate->DACrateClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("crate");
		}

		return AsManagedCrate(crate->DACrateClassPointer);
	}

	void DACrateManager::StaticInit()
	{
		::DACrateManager::Static_Init();
	}

	void DACrateManager::AddCrate(IDACrateFactoryClass^ factory)
	{
		if (factory == nullptr || factory->DACrateFactoryClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}

		if (factory->IsManagedCrateFactory)
		{
			AddCrate(factory->AsManagedCrateFactory());
		}
		else
		{
			::DACrateManager::Add_Crate(
				reinterpret_cast<::DACrateFactoryClass*>(factory->DACrateFactoryClassPointer.ToPointer()));
		}
	}

	void DACrateManager::AddCrate(IRenSharpCrateFactoryClass^ factory)
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
			::DACrateManager::Add_Crate(
				reinterpret_cast<::DACrateFactoryClass*>(factory->DACrateFactoryClassPointer.ToPointer()));
		}
	}

	void DACrateManager::AddCrateModifier(IDACrateModifierFactoryClass^ factory)
	{
		if (factory == nullptr || factory->DACrateModifierFactoryClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}

		if (factory->IsManagedCrateModifierFactory)
		{
			AddCrateModifier(factory->AsManagedCrateModifierFactory());
		}
		else
		{
			::DACrateManager::Add_Crate_Modifier(
				reinterpret_cast<::DACrateModifierFactoryClass*>(factory->DACrateModifierFactoryClassPointer.ToPointer()));
		}
	}

	void DACrateManager::AddCrateModifier(IRenSharpCrateModifierFactoryClass^ factory)
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
			::DACrateManager::Add_Crate_Modifier(
				reinterpret_cast<::DACrateModifierFactoryClass*>(factory->DACrateModifierFactoryClassPointer.ToPointer()));
		}
	}

	IDACrateClass^ DACrateManager::GetCrate(String^ name)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			auto result = ::DACrateManager::Get_Crate(
				reinterpret_cast<char*>(nameHandle.ToPointer()));
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew DACrateClass(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	IUnmanagedContainer<IDACrateModifierClass^>^ DACrateManager::CreateCrateModifier(String^ name, String^ parameters)
	{
		if (name == nullptr)
		{
			throw gcnew ArgumentNullException("name");
		}
		else if (parameters == nullptr)
		{
			throw gcnew ArgumentNullException("parameters");
		}

		IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
		try
		{
			IntPtr parametersHandle = Marshal::StringToHGlobalAnsi(parameters);
			try
			{
				auto result = ::DACrateManager::Create_Crate_Modifier(
					reinterpret_cast<char*>(nameHandle.ToPointer()),
					reinterpret_cast<char*>(parametersHandle.ToPointer()));
				if (result == nullptr)
				{
					return nullptr;
				}
				else
				{
					return gcnew UnmanagedContainer<IDACrateModifierClass^>(gcnew DACrateModifierClass(IntPtr(result)));
				}
			}
			finally
			{
				Marshal::FreeHGlobal(parametersHandle);
			}
		}
		finally
		{
			Marshal::FreeHGlobal(nameHandle);
		}
	}

	void DACrateManager::CalculateOdds(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		::DACrateManager::Calculate_Odds(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	IDACrateClass^ DACrateManager::SelectCrate(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		auto result = ::DACrateManager::Select_Crate(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DACrateClass(IntPtr(result));
		}
	}

	String^ DACrateManager::ToString()
	{
		return daGameFeatureClass->ToString();
	}

	bool DACrateManager::Equals(Object^ other)
	{
		if (DAEventClass::Equals(other))
		{
			return true;
		}

		if (ReferenceEquals(other, nullptr))
		{
			return false;
		}

		auto otherUnmanagedObj = dynamic_cast<IUnmanagedObject^>(other);
		if (otherUnmanagedObj == nullptr || otherUnmanagedObj->Pointer.Equals(IntPtr::Zero))
		{
			return false;
		}

		auto otherDAGameFeatureClass = dynamic_cast<IDAGameFeatureClass^>(other);
		if (otherDAGameFeatureClass != nullptr)
		{
			if (daGameFeatureClass->DAGameFeatureClassPointer.Equals(otherDAGameFeatureClass->DAGameFeatureClassPointer))
			{
				return true;
			}
		}

		auto otherDACrateManager = dynamic_cast<IDACrateManager^>(other);
		if (otherDACrateManager != nullptr)
		{
			if (DACrateManagerPointer.Equals(otherDACrateManager->DACrateManagerPointer))
			{
				return true;
			}
		}

		return false;
	}

	void DACrateManager::Init()
	{
		daGameFeatureClass->Init();
	}

	IRenSharpGameFeatureClass^ DACrateManager::AsManagedGameFeature()
	{
		return daGameFeatureClass->AsManagedGameFeature();
	}

	bool DACrateManager::SelectSpawner([Out] Vector3% spawnerPos)
	{
		auto result = InternalDACrateManagerPointer->Select_Spawner();
		if (result == nullptr)
		{
			spawnerPos = Vector3();

			return false;
		}
		else
		{
			Vector3::UnmanagedToManagedVector3(*result, spawnerPos);

			return true;
		}
	}

	bool DACrateManager::CrateChatCommand(IcPlayer^ player, IDATokenClass^ text, TextMessageEnum chatType)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (text == nullptr || text->DATokenClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("text");
		}

		return InternalDACrateManagerPointer->Crate_Chat_Command(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
			*reinterpret_cast<::DATokenClass*>(text->DATokenClassPointer.ToPointer()),
			static_cast<::TextMessageEnum>(chatType));
	}

	bool DACrateManager::CratesChatCommand(IcPlayer^ player, IDATokenClass^ text, TextMessageEnum chatType)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (text == nullptr || text->DATokenClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("text");
		}

		return InternalDACrateManagerPointer->Crates_Chat_Command(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
			*reinterpret_cast<::DATokenClass*>(text->DATokenClassPointer.ToPointer()),
			static_cast<::TextMessageEnum>(chatType));
	}

	bool DACrateManager::ShowCrateSpawnersChatCommand(IcPlayer^ player, IDATokenClass^ text, TextMessageEnum chatType)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (text == nullptr || text->DATokenClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("text");
		}

		return InternalDACrateManagerPointer->ShowCrateSpawners_Chat_Command(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
			*reinterpret_cast<::DATokenClass*>(text->DATokenClassPointer.ToPointer()),
			static_cast<::TextMessageEnum>(chatType));
	}

	bool DACrateManager::HideCrateSpawnersChatCommand(IcPlayer^ player, IDATokenClass^ text, TextMessageEnum chatType)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (text == nullptr || text->DATokenClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("text");
		}

		return InternalDACrateManagerPointer->HideCrateSpawners_Chat_Command(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
			*reinterpret_cast<::DATokenClass*>(text->DATokenClassPointer.ToPointer()),
			static_cast<::TextMessageEnum>(chatType));
	}

	float DACrateManager::Odds::get()
	{
		return ::DACrateManager::Get_Odds();
	}

	void DACrateManager::Odds::set(float value)
	{
		auto& odds = DACrateManagerHelper::GetOdds();

		odds = value;
	}

	IntPtr DACrateManager::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void DACrateManager::Pointer::set(IntPtr value)
	{
		AbstractUnmanagedObject::Pointer::set(value);

		if (Pointer == IntPtr::Zero)
		{
			daGameFeatureClass = nullptr;
		}
		else
		{
			daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
		}
	}

	IntPtr DACrateManager::DACrateManagerPointer::get()
	{
		return IntPtr(InternalDACrateManagerPointer);
	}

	IntPtr DACrateManager::DAGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAGameFeatureClassPointer);
	}

	String^ DACrateManager::Name::get()
	{
		return daGameFeatureClass->Name;
	}

	IDAGameFeatureFactoryClass^ DACrateManager::Factory::get()
	{
		return daGameFeatureClass->Factory;
	}

	void DACrateManager::Factory::set(IDAGameFeatureFactoryClass^ value)
	{
		daGameFeatureClass->Factory = value;
	}

	bool DACrateManager::IsManagedGameFeature::get()
	{
		return daGameFeatureClass->IsManagedGameFeature;
	}

	void DACrateManager::Shutdown()
	{
		auto tmpCrateModifiers = gcnew Generic::Dictionary<IntPtr, IRenSharpCrateModifierClass^>(managedCrateModifiers);

		for each (auto crateModifier in tmpCrateModifiers->Values)
		{
#pragma push_macro("delete")
#undef delete

			delete crateModifier;
			crateModifier = nullptr;

#pragma pop_macro("delete")
		}

		tmpCrateModifiers->Clear();
		managedCrateModifiers->Clear();

		auto tmpCrateModifierFactories = gcnew Generic::Dictionary<IntPtr, IRenSharpCrateModifierFactoryClass^>(managedCrateModifierFactories);

		for each (auto factory in tmpCrateModifierFactories->Values)
		{
#pragma push_macro("delete")
#undef delete

			delete factory;
			factory = nullptr;

#pragma pop_macro("delete")
		}

		tmpCrateModifierFactories->Clear();
		managedCrateModifierFactories->Clear();

		auto tmpCrates = gcnew Generic::Dictionary<IntPtr, IRenSharpCrateClass^>(managedCrates);

		for each (auto crate in tmpCrates->Values)
		{
#pragma push_macro("delete")
#undef delete

			delete crate;
			crate = nullptr;

#pragma pop_macro("delete")
		}

		tmpCrates->Clear();
		managedCrates->Clear();

		auto tmpCrateFactories = gcnew Generic::Dictionary<IntPtr, IRenSharpCrateFactoryClass^>(managedCrateFactories);

		for each (auto factory in tmpCrateFactories->Values)
		{
#pragma push_macro("delete")
#undef delete

			delete factory;
			factory = nullptr;

#pragma pop_macro("delete")
		}

		tmpCrateFactories->Clear();
		managedCrateFactories->Clear();
	}

	void DACrateManager::RegisterManagedCrateModifierFactory(IRenSharpCrateModifierFactoryClass^ factory)
	{
		if (factory == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}
		else if (!factory->IsAttached)
		{
			throw gcnew ArgumentException("Crate modifier factory is not attached.");
		}
		else if (Imports::IsShuttingDown())
		{
			throw gcnew NotSupportedException("Engine is shutting down");
		}

		managedCrateModifierFactories->Add(factory->DACrateModifierFactoryClassPointer, factory);
	}

	void DACrateManager::RegisterManagedCrateModifier(IRenSharpCrateModifierClass^ crateModifier)
	{
		if (crateModifier == nullptr)
		{
			throw gcnew ArgumentNullException("crateModifier");
		}
		else if (!crateModifier->IsAttached)
		{
			throw gcnew ArgumentException("Crate modifier is not attached.");
		}
		else if (Imports::IsShuttingDown())
		{
			throw gcnew NotSupportedException("Engine is shutting down");
		}

		managedCrateModifiers->Add(crateModifier->DACrateModifierClassPointer, crateModifier);
	}

	void DACrateManager::RegisterManagedCrateFactory(IRenSharpCrateFactoryClass^ factory)
	{
		if (factory == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}
		else if (!factory->IsAttached)
		{
			throw gcnew ArgumentException("Crate factory is not attached.");
		}
		else if (Imports::IsShuttingDown())
		{
			throw gcnew NotSupportedException("Engine is shutting down");
		}

		managedCrateFactories->Add(factory->DACrateFactoryClassPointer, factory);
	}

	void DACrateManager::RegisterManagedCrate(IRenSharpCrateClass^ crate)
	{
		if (crate == nullptr)
		{
			throw gcnew ArgumentNullException("crate");
		}
		else if (!crate->IsAttached)
		{
			throw gcnew ArgumentException("Crate is not attached.");
		}
		else if (Imports::IsShuttingDown())
		{
			throw gcnew NotSupportedException("Engine is shutting down");
		}

		managedCrates->Add(crate->DACrateClassPointer, crate);
	}

	void DACrateManager::UnregisterManagedCrateModifierFactory(IRenSharpCrateModifierFactoryClass^ factory)
	{
		if (factory == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}

		managedCrateModifierFactories->Remove(factory->DACrateModifierFactoryClassPointer);
	}

	void DACrateManager::UnregisterManagedCrateModifier(IRenSharpCrateModifierClass^ crateModifier)
	{
		if (crateModifier == nullptr)
		{
			throw gcnew ArgumentNullException("crateModifier");
		}

		managedCrateModifiers->Remove(crateModifier->DACrateModifierClassPointer);
	}

	void DACrateManager::UnregisterManagedCrateFactory(IRenSharpCrateFactoryClass^ factory)
	{
		if (factory == nullptr)
		{
			throw gcnew ArgumentNullException("factory");
		}

		managedCrateFactories->Remove(factory->DACrateFactoryClassPointer);
	}

	void DACrateManager::UnregisterManagedCrate(IRenSharpCrateClass^ crate)
	{
		if (crate == nullptr)
		{
			throw gcnew ArgumentNullException("crate");
		}

		managedCrates->Remove(crate->DACrateClassPointer);
	}

	IDynamicVectorClass<IDACrateFactoryClass^>^ DACrateManager::Crates::get()
	{
		auto& crates = DACrateManagerHelper::GetCrates();

		return gcnew DACrateFactoryClassPtrDynamicVectorClass(IntPtr(&crates));
	}

	void DACrateManager::Crates::set(IDynamicVectorClass<IDACrateFactoryClass^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto& crates = DACrateManagerHelper::GetCrates();

		crates = *reinterpret_cast<::DynamicVectorClass<::DACrateFactoryClass*>*>(value->Pointer.ToPointer());
	}

	IDynamicVectorClass<IDACrateModifierFactoryClass^>^ DACrateManager::CrateModifiers::get()
	{
		auto& crateModifiers = DACrateManagerHelper::GetCrateModifiers();

		return gcnew DACrateModifierFactoryClassPtrDynamicVectorClass(IntPtr(&crateModifiers));
	}

	void DACrateManager::CrateModifiers::set(IDynamicVectorClass<IDACrateModifierFactoryClass^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto& crateModifiers = DACrateManagerHelper::GetCrateModifiers();

		crateModifiers = *reinterpret_cast<::DynamicVectorClass<::DACrateModifierFactoryClass*>*>(value->Pointer.ToPointer());
	}

	::DAEventClass* DACrateManager::InternalDAEventClassPointer::get()
	{
		return InternalDACrateManagerPointer;
	}

	::DAGameFeatureClass* DACrateManager::InternalDAGameFeatureClassPointer::get()
	{
		return InternalDACrateManagerPointer;
	}

	::DACrateManager* DACrateManager::InternalDACrateManagerPointer::get()
	{
		return reinterpret_cast<::DACrateManager*>(Pointer.ToPointer());
	}

	IDynamicVectorClass<IPhysicalGameObj^>^ DACrateManager::CrateObjs::get()
	{
		auto helper = reinterpret_cast<DACrateManagerHelper*>(InternalDACrateManagerPointer);

		auto& crateObjs = helper->GetCrateObjs();

		return gcnew PhysicalGameObjPtrDynamicVectorClass(IntPtr(&crateObjs));
	}

	void DACrateManager::CrateObjs::set(IDynamicVectorClass<IPhysicalGameObj^>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<DACrateManagerHelper*>(InternalDACrateManagerPointer);

		auto& crateObjs = helper->GetCrateObjs();

		crateObjs = *reinterpret_cast<::DynamicVectorClass<::PhysicalGameObj*>*>(value->Pointer.ToPointer());
	}

	Vector3 DACrateManager::LastCratePosition::get()
	{
		auto helper = reinterpret_cast<DACrateManagerHelper*>(InternalDACrateManagerPointer);

		auto& lastCratePosition = helper->GetLastCratePosition();

		Vector3 result;

		Vector3::UnmanagedToManagedVector3(lastCratePosition, result);

		return result;
	}

	void DACrateManager::LastCratePosition::set(Vector3 value)
	{
		auto helper = reinterpret_cast<DACrateManagerHelper*>(InternalDACrateManagerPointer);

		auto& lastCratePosition = helper->GetLastCratePosition();

		Vector3::ManagedToUnmanagedVector3(value, lastCratePosition);
	}

	int DACrateManager::MaxCrates::get()
	{
		auto helper = reinterpret_cast<DACrateManagerHelper*>(InternalDACrateManagerPointer);

		auto& maxCrates = helper->GetMaxCrates();

		return maxCrates;
	}

	void DACrateManager::MaxCrates::set(int value)
	{
		auto helper = reinterpret_cast<DACrateManagerHelper*>(InternalDACrateManagerPointer);

		auto& maxCrates = helper->GetMaxCrates();

		maxCrates = value;
	}

	String^ DACrateManager::Model::get()
	{
		auto helper = reinterpret_cast<DACrateManagerHelper*>(InternalDACrateManagerPointer);

		auto& model = helper->GetModel();

		return gcnew String(model.Peek_Buffer());
	}

	void DACrateManager::Model::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<DACrateManagerHelper*>(InternalDACrateManagerPointer);

		auto& model = helper->GetModel();

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			model = reinterpret_cast<char*>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	float DACrateManager::SpawnTimeMin::get()
	{
		auto helper = reinterpret_cast<DACrateManagerHelper*>(InternalDACrateManagerPointer);

		auto& spawnTimeMin = helper->GetSpawnTimeMin();

		return spawnTimeMin;
	}

	void DACrateManager::SpawnTimeMin::set(float value)
	{
		auto helper = reinterpret_cast<DACrateManagerHelper*>(InternalDACrateManagerPointer);

		auto& spawnTimeMin = helper->GetSpawnTimeMin();

		spawnTimeMin = value;
	}

	float DACrateManager::SpawnTimeMax::get()
	{
		auto helper = reinterpret_cast<DACrateManagerHelper*>(InternalDACrateManagerPointer);

		auto& spawnTimeMax = helper->GetSpawnTimeMax();

		return spawnTimeMax;
	}

	void DACrateManager::SpawnTimeMax::set(float value)
	{
		auto helper = reinterpret_cast<DACrateManagerHelper*>(InternalDACrateManagerPointer);

		auto& spawnTimeMax = helper->GetSpawnTimeMax();

		spawnTimeMax = value;
	}

	float DACrateManager::FirstSpawnTimeMin::get()
	{
		auto helper = reinterpret_cast<DACrateManagerHelper*>(InternalDACrateManagerPointer);

		auto& firstSpawnTimeMin = helper->GetFirstSpawnTimeMin();

		return firstSpawnTimeMin;
	}

	void DACrateManager::FirstSpawnTimeMin::set(float value)
	{
		auto helper = reinterpret_cast<DACrateManagerHelper*>(InternalDACrateManagerPointer);

		auto& firstSpawnTimeMin = helper->GetFirstSpawnTimeMin();

		firstSpawnTimeMin = value;
	}

	float DACrateManager::FirstSpawnTimeMax::get()
	{
		auto helper = reinterpret_cast<DACrateManagerHelper*>(InternalDACrateManagerPointer);

		auto& firstSpawnTimeMax = helper->GetFirstSpawnTimeMax();

		return firstSpawnTimeMax;
	}

	void DACrateManager::FirstSpawnTimeMax::set(float value)
	{
		auto helper = reinterpret_cast<DACrateManagerHelper*>(InternalDACrateManagerPointer);

		auto& firstSpawnTimeMax = helper->GetFirstSpawnTimeMax();

		firstSpawnTimeMax = value;
	}

	IDynamicVectorClass<Vector3>^ DACrateManager::Spawners::get()
	{
		auto helper = reinterpret_cast<DACrateManagerHelper*>(InternalDACrateManagerPointer);

		auto& spawners = helper->GetSpawners();

		return gcnew Vector3DynamicVectorClass(IntPtr(&spawners));
	}

	void DACrateManager::Spawners::set(IDynamicVectorClass<Vector3>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<DACrateManagerHelper*>(InternalDACrateManagerPointer);

		auto& spawners = helper->GetSpawners();

		spawners = *reinterpret_cast<::DynamicVectorClass<::Vector3>*>(value->Pointer.ToPointer());
	}

	IDynamicVectorClass<Vector3>^ DACrateManager::ActiveSpawners::get()
	{
		auto helper = reinterpret_cast<DACrateManagerHelper*>(InternalDACrateManagerPointer);

		auto& activeSpawners = helper->GetActiveSpawners();

		return gcnew Vector3PtrDynamicVectorClass(IntPtr(&activeSpawners));
	}

	void DACrateManager::ActiveSpawners::set(IDynamicVectorClass<Vector3>^ value)
	{
		if (value == nullptr || value->Pointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<DACrateManagerHelper*>(InternalDACrateManagerPointer);

		auto& activeSpawners = helper->GetActiveSpawners();

		activeSpawners = *reinterpret_cast<::DynamicVectorClass<::Vector3*>*>(value->Pointer.ToPointer());
	}
}