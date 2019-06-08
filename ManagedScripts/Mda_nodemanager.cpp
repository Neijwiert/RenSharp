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
#include "Mda_nodemanager.h"

#include "Imports.h"
#include "AbstractUnmanagedObject.h"
#include "MVector3.h"
#include "Mda_spawnsystem.h"
#include "MPhysicalGameObj.h"
#include "MSoldierGameObj.h"

using namespace System::Text;

namespace RenSharp
{

#pragma managed(push, off)

	class DASpawnNodeClassHelper : public ::DASpawnNodeClass
	{
		private:
			DASpawnNodeClassHelper() = default;

		public:
			::DASpawnPointClass*& GetSpawnPoint()
			{
				return SpawnPoint;
			}
	};

#pragma managed(pop)

	DABaseNodeClass::DABaseNodeClass(IntPtr pointer)
		: DAEventClass(pointer)
	{

	}

	String^ DABaseNodeClass::ToString()
	{
		StringBuilder^ builder = gcnew StringBuilder();
		builder->Append(Type);

		return builder->ToString();
	}

	bool DABaseNodeClass::Equals(System::Object^ other)
	{
		if (DAEventClass::Equals(other))
		{
			return true;
		}

		IRenSharpNodeClass^ otherThis = dynamic_cast<IRenSharpNodeClass^>(other);
		if (otherThis == nullptr)
		{
			return false;
		}

		return DABaseNodeClassPointer.Equals(otherThis->DABaseNodeClassPointer);
	}

	void DABaseNodeClass::SetContested(bool value)
	{
		InternalDABaseNodeClassPointer->Set_Contested(value);
	}

	IRenSharpNodeClass^ DABaseNodeClass::AsManagedNode()
	{
		return DANodeManagerClass::AsManagedNode(this);
	}

	IntPtr DABaseNodeClass::DABaseNodeClassPointer::get()
	{
		return IntPtr(InternalDABaseNodeClassPointer);
	}

	Vector3 DABaseNodeClass::Position::get()
	{
		Vector3 result;

		Vector3::UnmanagedToManagedVector3(InternalDABaseNodeClassPointer->Get_Position(), result);

		return result;
	}

	void DABaseNodeClass::Position::set(Vector3 value)
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& position = helper->GetPosition();

		Vector3::ManagedToUnmanagedVector3(value, position);
	}

	String^ DABaseNodeClass::ObjectPreset::get()
	{
		auto result = InternalDABaseNodeClassPointer->Get_Preset();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	String^ DABaseNodeClass::ObjectModel::get()
	{
		auto result = InternalDABaseNodeClassPointer->Get_Model();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	int DABaseNodeClass::Team::get()
	{
		return InternalDABaseNodeClassPointer->Get_Team();
	}

	void DABaseNodeClass::Team::set(int value)
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& team = helper->GetTeam();

		team = value;
	}

	String^ DABaseNodeClass::Group::get()
	{
		return gcnew String(InternalDABaseNodeClassPointer->Get_Group().Peek_Buffer());
	}

	void DABaseNodeClass::Group::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& group = helper->GetGroup();

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			group = reinterpret_cast<char*>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	String^ DABaseNodeClass::Name::get()
	{
		return gcnew String(InternalDABaseNodeClassPointer->Get_Name().Peek_Buffer());
	}

	void DABaseNodeClass::Name::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& name = helper->GetName();

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			name = reinterpret_cast<char*>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	bool DABaseNodeClass::IsContested::get()
	{
		return InternalDABaseNodeClassPointer->Is_Contested();
	}

	void DABaseNodeClass::IsContested::set(bool value)
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& isContested = helper->GetIsContested();

		isContested = value;
	}

	bool DABaseNodeClass::IsCapturable::get()
	{
		return InternalDABaseNodeClassPointer->Is_Capturable();
	}

	void DABaseNodeClass::IsCapturable::set(bool value)
	{
		InternalDABaseNodeClassPointer->Set_Capturable(value);
	}

	bool DABaseNodeClass::IsCaptureOnce::get()
	{
		return InternalDABaseNodeClassPointer->Is_Capture_Once();
	}

	void DABaseNodeClass::IsCaptureOnce::set(bool value)
	{
		InternalDABaseNodeClassPointer->Set_Capture_Once(value);
	}

	String^ DABaseNodeClass::Type::get()
	{
		auto result = InternalDABaseNodeClassPointer->Get_Type();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	bool DABaseNodeClass::IsManagedNode::get()
	{
		return DANodeManagerClass::IsManagedNode(this);
	}

	void DABaseNodeClass::Init(IINIClass^ ini, String^ header)
	{
		if (ini == nullptr || ini->INIClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("ini");
		}
		else if (header == nullptr)
		{
			throw gcnew ArgumentNullException("header");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		IntPtr headerHandle = Marshal::StringToHGlobalAnsi(header);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(headerHandle.ToPointer()));

			helper->_Init(
				reinterpret_cast<::INIClass*>(ini->INIClassPointer.ToPointer()),
				tmp);
		}
		finally
		{
			Marshal::FreeHGlobal(headerHandle);
		}
	}

	void DABaseNodeClass::Captured(int captureTeam)
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		helper->Captured(captureTeam);
	}

	void DABaseNodeClass::AttackTick(int attackTeam)
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		helper->AttackTick(attackTeam);
	}

	void DABaseNodeClass::DefendTick()
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		helper->DefendTick();
	}

	void DABaseNodeClass::ContestedEvent()
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		helper->ContestedEvent();
	}

	void DABaseNodeClass::CaptureEvent()
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		helper->CaptureEvent();
	}

	void DABaseNodeClass::UpdateIconAndRadar()
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		helper->UpdateIconAndRadar();
	}

	bool DABaseNodeClass::IsPlayerInRange(ISoldierGameObj^ player)
	{
		if (player == nullptr || player->SoldierGameObjPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		return helper->IsPlayerInRange(
			reinterpret_cast<::SoldierGameObj*>(player->SoldierGameObjPointer.ToPointer()));
	}

	void DABaseNodeClass::GiveAttackDefendTickPoints(int team)
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		helper->GiveAttackDefendTickPoints(team);
	}

	void DABaseNodeClass::GiveCapturePoints()
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		helper->GiveCapturePoints();
	}

	::DAEventClass* DABaseNodeClass::InternalDAEventClassPointer::get()
	{
		return InternalDABaseNodeClassPointer;
	}

	::DABaseNodeClass* DABaseNodeClass::InternalDABaseNodeClassPointer::get()
	{
		return reinterpret_cast<::DABaseNodeClass*>(Pointer.ToPointer());
	}

	IPhysicalGameObj^ DABaseNodeClass::Object::get()
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& object = helper->GetObject();

		if (object == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PhysicalGameObj(IntPtr(object));
		}
	}

	void DABaseNodeClass::Object::set(IPhysicalGameObj^ value)
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& object = helper->GetObject();

		if (value == nullptr || value->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			object = nullptr;
		}
		else
		{
			object = reinterpret_cast<::PhysicalGameObj*>(value->PhysicalGameObjPointer.ToPointer());
		}
	}

	IPhysicalGameObj^ DABaseNodeClass::Icon::get()
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& icon = helper->GetIcon();

		if (icon == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PhysicalGameObj(IntPtr(icon));
		}
	}

	void DABaseNodeClass::Icon::set(IPhysicalGameObj^ value)
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& icon = helper->GetIcon();

		if (value == nullptr || value->PhysicalGameObjPointer.ToPointer() == nullptr)
		{
			icon = nullptr;
		}
		else
		{
			icon = reinterpret_cast<::PhysicalGameObj*>(value->PhysicalGameObjPointer.ToPointer());
		}
	}

	array<IPhysicalGameObj^>^ DABaseNodeClass::Radar::get()
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		::PhysicalGameObj* tmp[DABaseNodeClassHelper::RadarSizeCount];
		helper->GetRadar(tmp);

		array<IPhysicalGameObj^>^ result = gcnew array<IPhysicalGameObj^>(DABaseNodeClassHelper::RadarSizeCount);
		for (int x = 0; x < result->Length; x++)
		{
			auto currentRadar = tmp[x];
			if (currentRadar == nullptr)
			{
				result[x] = nullptr;
			}
			else
			{
				result[x] = gcnew PhysicalGameObj(IntPtr(currentRadar));
			}
		}

		return result;
	}

	void DABaseNodeClass::Radar::set(array<IPhysicalGameObj^>^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}
		else if (value->Length != static_cast<int>(DABaseNodeClassHelper::RadarSizeCount))
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		for (int x = 0; x < value->Length; x++)
		{
			auto currentRadar = value[x];
			if (currentRadar == nullptr || currentRadar->PhysicalGameObjPointer.ToPointer() == nullptr)
			{
				helper->SetRadar(
					static_cast<std::size_t>(x),
					nullptr);
			}
			else
			{
				helper->SetRadar(
					static_cast<std::size_t>(x),
					reinterpret_cast<::PhysicalGameObj*>(currentRadar->PhysicalGameObjPointer.ToPointer()));
			}
		}
	}

	bool DABaseNodeClass::SentAttackMessage::get()
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& sentAttackMessage = helper->GetSentAttackMessage();

		return sentAttackMessage;
	}

	void DABaseNodeClass::SentAttackMessage::set(bool value)
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& sentAttackMessage = helper->GetSentAttackMessage();

		sentAttackMessage = value;
	}

	array<bool>^ DABaseNodeClass::SentDefendMessage::get()
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		array<bool>^ result = gcnew array<bool>(DABaseNodeClassHelper::SentDefendMessageSizeCount);

		pin_ptr<bool> pinnedResult = &result[0];
		bool* resultPtr = pinnedResult;

		helper->GetSentDefendMessage(resultPtr);

		return result;
	}

	void DABaseNodeClass::SentDefendMessage::set(array<bool>^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}
		else if (value->Length != static_cast<int>(DABaseNodeClassHelper::SentDefendMessageSizeCount))
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		pin_ptr<bool> pinnedValue = &value[0];
		bool* valuePtr = pinnedValue;

		helper->SetSentDefendMessage(valuePtr);
	}

	unsigned long DABaseNodeClass::LastAttackMessage::get()
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& lastAttackMessage = helper->GetLastAttackMessage();

		return lastAttackMessage;
	}

	void DABaseNodeClass::LastAttackMessage::set(unsigned long value)
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& lastAttackMessage = helper->GetLastAttackMessage();

		lastAttackMessage = value;
	}

	unsigned long DABaseNodeClass::LastAttackTick::get()
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& lastAttackTick = helper->GetLastAttackTick();

		return lastAttackTick;
	}

	void DABaseNodeClass::LastAttackTick::set(unsigned long value)
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& lastAttackTick = helper->GetLastAttackTick();

		lastAttackTick = value;
	}

	unsigned long DABaseNodeClass::LastDefendTick::get()
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& lastDefendTick = helper->GetLastDefendTick();

		return lastDefendTick;
	}

	void DABaseNodeClass::LastDefendTick::set(unsigned long value)
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& lastDefendTick = helper->GetLastDefendTick();

		lastDefendTick = value;
	}

	array<int>^ DABaseNodeClass::PlayerCheck::get()
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		array<int>^ result = gcnew array<int>(DABaseNodeClassHelper::PlayerCheckSizeCount);

		pin_ptr<int> pinnedResult = &result[0];
		int* resultPtr = pinnedResult;

		helper->GetPlayerCheck(resultPtr);

		return result;
	}

	void DABaseNodeClass::PlayerCheck::set(array<int>^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}
		else if (value->Length != static_cast<int>(DABaseNodeClassHelper::PlayerCheckSizeCount))
		{
			throw gcnew ArgumentOutOfRangeException("value");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		pin_ptr<int> pinnedValue = &value[0];
		int* valuePtr = pinnedValue;

		helper->SetPlayerCheck(valuePtr);
	}

	int DABaseNodeClass::LastAttackTeam::get()
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& lastAttackTeam = helper->GetLastAttackTeam();

		return lastAttackTeam;
	}

	void DABaseNodeClass::LastAttackTeam::set(int value)
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& lastAttackTeam = helper->GetLastAttackTeam();

		lastAttackTeam = value;
	}

	String^ DABaseNodeClass::Preset::get()
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& preset = helper->GetPreset();

		return gcnew String(preset.Peek_Buffer());
	}

	void DABaseNodeClass::Preset::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& preset = helper->GetPreset();

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			preset = reinterpret_cast<char*>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	String^ DABaseNodeClass::Model::get()
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& model = helper->GetModel();

		return gcnew String(model.Peek_Buffer());
	}

	void DABaseNodeClass::Model::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

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

	String^ DABaseNodeClass::Animation::get()
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& animation = helper->GetAnimation();

		return gcnew String(animation.Peek_Buffer());
	}

	void DABaseNodeClass::Animation::set(String^ value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& animation = helper->GetAnimation();

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			animation = reinterpret_cast<char*>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	float DABaseNodeClass::AttackDefendDistance::get()
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& attackDefendDistance = helper->GetAttackDefendDistance();

		return attackDefendDistance;
	}

	void DABaseNodeClass::AttackDefendDistance::set(float value)
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& attackDefendDistance = helper->GetAttackDefendDistance();

		attackDefendDistance = value;
	}

	bool DABaseNodeClass::IgnoreLOS::get()
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& ignoreLOS = helper->GetIgnoreLOS();

		return ignoreLOS;
	}

	void DABaseNodeClass::IgnoreLOS::set(bool value)
	{
		auto helper = reinterpret_cast<DABaseNodeClassHelper*>(InternalDABaseNodeClassPointer);

		auto& ignoreLOS = helper->GetIgnoreLOS();

		ignoreLOS = value;
	}

	DASpawnNodeClass::DASpawnNodeClass()
		: DABaseNodeClass(IntPtr(Imports::CreateDASpawnNodeClass()))
	{

	}

	DASpawnNodeClass::DASpawnNodeClass(IntPtr pointer)
		: DABaseNodeClass(pointer)
	{

	}

	IUnmanagedContainer<IDASpawnNodeClass^>^ DASpawnNodeClass::CreateDASpawnNodeClass()
	{
		return gcnew UnmanagedContainer<IDASpawnNodeClass^>(gcnew DASpawnNodeClass());
	}

#pragma push_macro("SpawnNodeType")
#undef SpawnNodeType
	String^ DASpawnNodeClass::SpawnNodeType::get()
#pragma pop_macro("SpawnNodeType")
	{
		return gcnew String(SpawnNodeType);
	}

	IntPtr DASpawnNodeClass::DASpawnNodeClassPointer::get()
	{
		return IntPtr(InternalDASpawnNodeClassPointer);
	}

	::DABaseNodeClass* DASpawnNodeClass::InternalDABaseNodeClassPointer::get()
	{
		return InternalDASpawnNodeClassPointer;
	}

	::DASpawnNodeClass* DASpawnNodeClass::InternalDASpawnNodeClassPointer::get()
	{
		return reinterpret_cast<::DASpawnNodeClass*>(Pointer.ToPointer());
	}

	IDASpawnPointClass^ DASpawnNodeClass::SpawnPoint::get()
	{
		auto helper = reinterpret_cast<DASpawnNodeClassHelper*>(InternalDASpawnNodeClassPointer);

		auto& spawnPoint = helper->GetSpawnPoint();

		if (spawnPoint == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DASpawnPointClass(IntPtr(spawnPoint));
		}
	}

	void DASpawnNodeClass::SpawnPoint::set(IDASpawnPointClass^ value)
	{
		auto helper = reinterpret_cast<DASpawnNodeClassHelper*>(InternalDASpawnNodeClassPointer);

		auto& spawnPoint = helper->GetSpawnPoint();

		if (value == nullptr || value->DASpawnPointClassPointer.ToPointer() == nullptr)
		{
			spawnPoint = nullptr;
		}
		else
		{
			spawnPoint = reinterpret_cast<::DASpawnPointClass*>(value->DASpawnPointClassPointer.ToPointer());
		}
	}

	static DANodeManagerClass::DANodeManagerClass()
	{
		managedNodes = gcnew Generic::Dictionary<IntPtr, IRenSharpNodeClass^>();
	}

	DANodeManagerClass::DANodeManagerClass(IntPtr pointer)
		: DAEventClass(pointer)
	{

	}

	void DANodeManagerClass::OnManagedNodeDestructed(IntPtr node)
	{
		IRenSharpNodeClass^ managedNode = AsManagedNode(node);
		if (managedNode != nullptr && static_cast<IUnmanagedAttachable<IDABaseNodeClass^>^>(managedNode)->IsAttached)
		{
			static_cast<IUnmanagedAttachable<IDABaseNodeClass^>^>(managedNode)->DestroyPointer = false;

#pragma push_macro("delete")
#undef delete

			delete managedNode;
			managedNode = nullptr;

#pragma pop_macro("delete")
		}
	}

	bool DANodeManagerClass::IsManagedNode(IntPtr node)
	{
		return managedNodes->ContainsKey(node);
	}

	bool DANodeManagerClass::IsManagedNode(IDABaseNodeClass^ node)
	{
		if (node == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}

		return IsManagedNode(node->DABaseNodeClassPointer);
	}

	IRenSharpNodeClass^ DANodeManagerClass::AsManagedNode(IntPtr node)
	{
		IRenSharpNodeClass^ result = nullptr;
		managedNodes->TryGetValue(node, result);

		return result;
	}

	IRenSharpNodeClass^ DANodeManagerClass::AsManagedNode(IDABaseNodeClass^ node)
	{
		if (node == nullptr || node->DABaseNodeClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}

		return AsManagedNode(node->DABaseNodeClassPointer);
	}

	IDANodeManagerClass^ DANodeManagerClass::CreateInstance()
	{
		auto result = Imports::CreateInstanceDANodeManagerClass();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DANodeManagerClass(IntPtr(result));
		}
	}

	void DANodeManagerClass::DestroyInstance()
	{
		Imports::DestroyInstanceDANodeManagerClass();
	}

	void DANodeManagerClass::Init(IINIClass^ ini)
	{
		if (ini == nullptr || ini->INIClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("ini");
		}

		InternalDANodeManagerClassPointer->Init(
			reinterpret_cast<::INIClass*>(ini->INIClassPointer.ToPointer()));
	}

	IDASpawnNodeClass^ DANodeManagerClass::CreateSpawnNode(IINIClass^ ini, String^ header)
	{
		if (ini == nullptr || ini->INIClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("ini");
		}
		else if (header == nullptr)
		{
			throw gcnew ArgumentNullException("header");
		}

		IntPtr headerHandle = Marshal::StringToHGlobalAnsi(header);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(headerHandle.ToPointer()));

			auto result = Imports::CreateNodeDASpawnNodeClass(
				reinterpret_cast<::INIClass*>(ini->INIClassPointer.ToPointer()),
				&tmp);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew DASpawnNodeClass(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(headerHandle);
		}
	}

	IDABaseNodeClass^ DANodeManagerClass::GetNode(int index)
	{
		if (index < 0 || index >= InternalDANodeManagerClassPointer->Get_Node_Count())
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalDANodeManagerClassPointer->Get_Node(index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DABaseNodeClass(IntPtr(result));
		}
	}

	IDABaseNodeClass^ DANodeManagerClass::FindNode(String^ group)
	{
		if (group == nullptr)
		{
			throw gcnew ArgumentNullException("group");
		}

		IntPtr groupHandle = Marshal::StringToHGlobalAnsi(group);
		try
		{
			::StringClass tmp(reinterpret_cast<char*>(groupHandle.ToPointer()));

			auto result = InternalDANodeManagerClassPointer->Find_Node(tmp);
			if (result == nullptr)
			{
				return nullptr;
			}
			else
			{
				return gcnew DABaseNodeClass(IntPtr(result));
			}
		}
		finally
		{
			Marshal::FreeHGlobal(groupHandle);
		}
	}

	IDANodeManagerClass^ DANodeManagerClass::Instance::get()
	{
		auto result = Imports::GetInstanceDANodeManagerClass();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DANodeManagerClass(IntPtr(result));
		}
	}

	IntPtr DANodeManagerClass::DANodeManagerClassPointer::get()
	{
		return IntPtr(InternalDANodeManagerClassPointer);
	}

	float DANodeManagerClass::AttackDefendDistance::get()
	{
		return InternalDANodeManagerClassPointer->Get_Attack_Defend_Distance();
	}

	float DANodeManagerClass::AttackDefendTickAmount::get()
	{
		return InternalDANodeManagerClassPointer->Get_Attack_Defend_Tick_Amount();
	}

	unsigned int DANodeManagerClass::AttackDefendTickTime::get()
	{
		return InternalDANodeManagerClassPointer->Get_Attack_Defend_Tick_Time();
	}

	float DANodeManagerClass::AttackDefendTickPoints::get()
	{
		return InternalDANodeManagerClassPointer->Get_Attack_Defend_Tick_Points();
	}

	int DANodeManagerClass::AttackDefendTickVeteranPoints::get()
	{
		return InternalDANodeManagerClassPointer->Get_Attack_Defend_Tick_Veteran_Points();
	}

	float DANodeManagerClass::CapturePoints::get()
	{
		return InternalDANodeManagerClassPointer->Get_Capture_Points();
	}

	int DANodeManagerClass::CaptureVeteranPoints::get()
	{
		return InternalDANodeManagerClassPointer->Get_Capture_Veteran_Points();
	}

	unsigned int DANodeManagerClass::ContestedSpawnTime::get()
	{
		return InternalDANodeManagerClassPointer->Get_Contested_Spawn_Time();
	}

	int DANodeManagerClass::NodeCount::get()
	{
		return InternalDANodeManagerClassPointer->Get_Node_Count();
	}

	void DANodeManagerClass::Shutdown()
	{
		auto tmpManagedNodes = gcnew Generic::Dictionary<IntPtr, IRenSharpNodeClass^>(managedNodes);

		for each (auto observer in tmpManagedNodes->Values)
		{
#pragma push_macro("delete")
#undef delete

			delete observer;
			observer = nullptr;

#pragma pop_macro("delete")
		}

		tmpManagedNodes->Clear();
		managedNodes->Clear();
	}

	void DANodeManagerClass::RegisterManagedNode(IRenSharpNodeClass^ node)
	{
		if (node == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}
		else if (!static_cast<IUnmanagedAttachable<IDABaseNodeClass^>^>(node)->IsAttached)
		{
			throw gcnew ArgumentException("Node is not attached");
		}
		else if (Imports::IsShuttingDown())
		{
			throw gcnew NotSupportedException("Engine is shutting down");
		}

		managedNodes->Add(node->DABaseNodeClassPointer, node);
	}

	void DANodeManagerClass::UnregisterManagedNode(IRenSharpNodeClass^ node)
	{
		if (node == nullptr)
		{
			throw gcnew ArgumentNullException("node");
		}

		managedNodes->Remove(node->DABaseNodeClassPointer);
	}

	::DAEventClass* DANodeManagerClass::InternalDAEventClassPointer::get()
	{
		return InternalDANodeManagerClassPointer;
	}

	::DANodeManagerClass* DANodeManagerClass::InternalDANodeManagerClassPointer::get()
	{
		return reinterpret_cast<::DANodeManagerClass*>(Pointer.ToPointer());
	}
}