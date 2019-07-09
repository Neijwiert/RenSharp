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
#include "Mda_squad.h"

#include "Imports.h"
#include "McPlayer.h"
#include "UnmanagedContainer.h"
#include "Mda_token.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <engine_da.h>
#include <engine_player.h>
#include <da_squad.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	DASquadInviteStruct::DASquadInviteStruct()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateDASquadInviteStruct1()))
	{

	}

	DASquadInviteStruct::DASquadInviteStruct(IcPlayer^ leader, IcPlayer^ player)
	{
		::cPlayer* leaderPtr;
		if (leader == nullptr || leader->cPlayerPointer.ToPointer() == nullptr)
		{
			leaderPtr = nullptr;
		}
		else
		{
			leaderPtr = reinterpret_cast<::cPlayer*>(leader->cPlayerPointer.ToPointer());
		}

		::cPlayer* playerPtr;
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			playerPtr = nullptr;
		}
		else
		{
			playerPtr = reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer());
		}

		Pointer = IntPtr(Imports::CreateDASquadInviteStruct2(leaderPtr, playerPtr));
	}

	DASquadInviteStruct::DASquadInviteStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IDASquadInviteStruct^>^ DASquadInviteStruct::CreateDASquadInviteStruct()
	{
		return gcnew UnmanagedContainer<IDASquadInviteStruct^>(gcnew DASquadInviteStruct());
	}

	IUnmanagedContainer<IDASquadInviteStruct^>^ DASquadInviteStruct::CreateDASquadInviteStruct(IcPlayer^ leader, IcPlayer^ player)
	{
		return gcnew UnmanagedContainer<IDASquadInviteStruct^>(gcnew DASquadInviteStruct(leader, player));
	}

	bool DASquadInviteStruct::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDASquadInviteStruct^ otherThis = dynamic_cast<IDASquadInviteStruct^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DASquadInviteStructPointer.Equals(otherThis->DASquadInviteStructPointer);
	}

	IntPtr DASquadInviteStruct::DASquadInviteStructPointer::get()
	{
		return IntPtr(InternalDASquadInviteStructPointer);
	}

	IcPlayer^ DASquadInviteStruct::Leader::get()
	{
		auto result = InternalDASquadInviteStructPointer->Leader;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	void DASquadInviteStruct::Leader::set(IcPlayer^ value)
	{
		if (value == nullptr || value->cPlayerPointer.ToPointer() == nullptr)
		{
			InternalDASquadInviteStructPointer->Leader = nullptr;
		}
		else
		{
			InternalDASquadInviteStructPointer->Leader = reinterpret_cast<::cPlayer*>(value->cPlayerPointer.ToPointer());
		}
	}

	IcPlayer^ DASquadInviteStruct::Player::get()
	{
		auto result = InternalDASquadInviteStructPointer->Player;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew cPlayer(IntPtr(result));
		}
	}

	void DASquadInviteStruct::Player::set(IcPlayer^ value)
	{
		if (value == nullptr || value->cPlayerPointer.ToPointer() == nullptr)
		{
			InternalDASquadInviteStructPointer->Player = nullptr;
		}
		else
		{
			InternalDASquadInviteStructPointer->Player = reinterpret_cast<::cPlayer*>(value->cPlayerPointer.ToPointer());
		}
	}

	int DASquadInviteStruct::Timeout::get()
	{
		return InternalDASquadInviteStructPointer->Timeout;
	}

	void DASquadInviteStruct::Timeout::set(int value)
	{
		InternalDASquadInviteStructPointer->Timeout = value;
	}

	bool DASquadInviteStruct::InternalDestroyPointer()
	{
		Imports::DestroyDASquadInviteStruct(InternalDASquadInviteStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DASquadInviteStruct* DASquadInviteStruct::InternalDASquadInviteStructPointer::get()
	{
		return reinterpret_cast<::DASquadInviteStruct*>(Pointer.ToPointer());
	}

	DASquadRemixStruct::DASquadRemixStruct()
		: AbstractUnmanagedObject(IntPtr(Imports::CreateDASquadRemixStruct1()))
	{

	}

	DASquadRemixStruct::DASquadRemixStruct(IDASquadClass^ squad, int team)
	{
		if (squad == nullptr || squad->DASquadClassPointer.ToPointer() == nullptr)
		{
			Pointer = IntPtr(Imports::CreateDASquadRemixStruct2(nullptr, team));
		}
		else
		{
			Pointer = IntPtr(Imports::CreateDASquadRemixStruct2(
				reinterpret_cast<::DASquadClass*>(squad->DASquadClassPointer.ToPointer()),
				team));
		}
	}

	DASquadRemixStruct::DASquadRemixStruct(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IDASquadRemixStruct^>^ DASquadRemixStruct::CreateDASquadRemixStruct()
	{
		return gcnew UnmanagedContainer<IDASquadRemixStruct^>(gcnew DASquadRemixStruct());
	}
	IUnmanagedContainer<IDASquadRemixStruct^>^ DASquadRemixStruct::CreateDASquadRemixStruct(IDASquadClass^ squad, int team)
	{
		return gcnew UnmanagedContainer<IDASquadRemixStruct^>(gcnew DASquadRemixStruct(squad, team));
	}

	bool DASquadRemixStruct::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDASquadRemixStruct^ otherThis = dynamic_cast<IDASquadRemixStruct^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DASquadRemixStructPointer.Equals(otherThis->DASquadRemixStructPointer);
	}

	IntPtr DASquadRemixStruct::DASquadRemixStructPointer::get()
	{
		return IntPtr(InternalDASquadRemixStructPointer);
	}

	IDASquadClass^ DASquadRemixStruct::Squad::get()
	{
		auto result = InternalDASquadRemixStructPointer->Squad;
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DASquadClass(IntPtr(result));
		}
	}

	void DASquadRemixStruct::Squad::set(IDASquadClass^ value)
	{
		if (value == nullptr || value->DASquadClassPointer.ToPointer() == nullptr)
		{
			InternalDASquadRemixStructPointer->Squad = nullptr;
		}
		else
		{
			InternalDASquadRemixStructPointer->Squad = reinterpret_cast<::DASquadClass*>(value->DASquadClassPointer.ToPointer());
		}
	}

	int DASquadRemixStruct::Team::get()
	{
		return InternalDASquadRemixStructPointer->Team;
	}

	void DASquadRemixStruct::Team::set(int value)
	{
		InternalDASquadRemixStructPointer->Team = value;
	}

	bool DASquadRemixStruct::InternalDestroyPointer()
	{
		Imports::DestroyDASquadRemixStruct(InternalDASquadRemixStructPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DASquadRemixStruct* DASquadRemixStruct::InternalDASquadRemixStructPointer::get()
	{
		return reinterpret_cast<::DASquadRemixStruct*>(Pointer.ToPointer());
	}

	DASquadMemberClass::DASquadMemberClass(IDASquadClass^ squad)
	{
		if (squad == nullptr || squad->DASquadClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("squad");
		}

		Pointer = IntPtr(Imports::CreateDASquadMemberClass(
			reinterpret_cast<::DASquadClass*>(squad->DASquadClassPointer.ToPointer())));
	}

	DASquadMemberClass::DASquadMemberClass(IntPtr pointer)
		: DAPlayerObserverClass(pointer)
	{

	}

	IUnmanagedContainer<IDASquadMemberClass^>^ DASquadMemberClass::CreateDASquadMemberClass(IDASquadClass^ squad)
	{
		return gcnew UnmanagedContainer<IDASquadMemberClass^>(gcnew DASquadMemberClass(squad));
	}

	bool DASquadMemberClass::DisbandChatCommand(IDATokenClass^ text, TextMessageEnum chatType)
	{
		if (text == nullptr || text->DATokenClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("text");
		}

		return InternalDASquadMemberClassPointer->Disband_Chat_Command(
			*reinterpret_cast<::DATokenClass*>(text->DATokenClassPointer.ToPointer()),
			static_cast<::TextMessageEnum>(chatType));
	}

	bool DASquadMemberClass::PromoteChatCommand(IDATokenClass^ text, TextMessageEnum chatType)
	{
		if (text == nullptr || text->DATokenClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("text");
		}

		return InternalDASquadMemberClassPointer->Promote_Chat_Command(
			*reinterpret_cast<::DATokenClass*>(text->DATokenClassPointer.ToPointer()),
			static_cast<::TextMessageEnum>(chatType));
	}

	bool DASquadMemberClass::InfoChatCommand(IDATokenClass^ text, TextMessageEnum chatType)
	{
		if (text == nullptr || text->DATokenClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("text");
		}

		return InternalDASquadMemberClassPointer->Info_Chat_Command(
			*reinterpret_cast<::DATokenClass*>(text->DATokenClassPointer.ToPointer()),
			static_cast<::TextMessageEnum>(chatType));
	}

	bool DASquadMemberClass::SKickChatCommand(IDATokenClass^ text, TextMessageEnum chatType)
	{
		if (text == nullptr || text->DATokenClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("text");
		}

		return InternalDASquadMemberClassPointer->SKick_Chat_Command(
			*reinterpret_cast<::DATokenClass*>(text->DATokenClassPointer.ToPointer()),
			static_cast<::TextMessageEnum>(chatType));
	}

	bool DASquadMemberClass::MsgChatCommand(IDATokenClass^ text, TextMessageEnum chatType)
	{
		if (text == nullptr || text->DATokenClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("text");
		}

		return InternalDASquadMemberClassPointer->Msg_Chat_Command(
			*reinterpret_cast<::DATokenClass*>(text->DATokenClassPointer.ToPointer()),
			static_cast<::TextMessageEnum>(chatType));
	}

	void DASquadMemberClass::CreateRadar()
	{
		InternalDASquadMemberClassPointer->Create_Radar();
	}

	void DASquadMemberClass::UpdateRadar()
	{
		InternalDASquadMemberClassPointer->Update_Radar();
	}

	void DASquadMemberClass::AddRadar(IDASquadMemberClass^ member)
	{
		if (member == nullptr || member->DASquadMemberClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("member");
		}

		InternalDASquadMemberClassPointer->Add_Radar(
			reinterpret_cast<::DASquadMemberClass*>(member->DASquadMemberClassPointer.ToPointer()));
	}

	void DASquadMemberClass::RemoveRadar(IDASquadMemberClass^ member)
	{
		if (member == nullptr || member->DASquadMemberClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("member");
		}

		InternalDASquadMemberClassPointer->Remove_Radar(
			reinterpret_cast<::DASquadMemberClass*>(member->DASquadMemberClassPointer.ToPointer()));
	}

	void DASquadMemberClass::LeaveSquad()
	{
		InternalDASquadMemberClassPointer->Leave_Squad();
	}

	IntPtr DASquadMemberClass::DASquadMemberClassPointer::get()
	{
		return IntPtr(InternalDASquadMemberClassPointer);
	}

	IDASquadClass^ DASquadMemberClass::Squad::get()
	{
		auto result = InternalDASquadMemberClassPointer->Get_Squad();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DASquadClass(IntPtr(result));
		}
	}

	bool DASquadMemberClass::IsLeader::get()
	{
		return InternalDASquadMemberClassPointer->Is_Leader();
	}

	::DAPlayerObserverClass* DASquadMemberClass::InternalDAPlayerObserverClassPointer::get()
	{
		return InternalDASquadMemberClassPointer;
	}

	::DASquadMemberClass* DASquadMemberClass::InternalDASquadMemberClassPointer::get()
	{
		return reinterpret_cast<::DASquadMemberClass*>(Pointer.ToPointer());
	}

	DASquadClass::DASquadClass(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		Pointer = IntPtr(Imports::CreateDASquadClass(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer())));
	}

	DASquadClass::DASquadClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	IUnmanagedContainer<IDASquadClass^>^ DASquadClass::CreateDASquadClass(IcPlayer^ player)
	{
		return gcnew UnmanagedContainer<IDASquadClass^>(gcnew DASquadClass(player));
	}

	bool DASquadClass::Equals(Object^ other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IDASquadClass^ otherThis = dynamic_cast<IDASquadClass^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return DASquadClassPointer.Equals(otherThis->DASquadClassPointer);
	}

	void DASquadClass::Add(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		InternalDASquadClassPointer->Add(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	bool DASquadClass::Remove(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		return InternalDASquadClassPointer->Remove(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	void DASquadClass::InternalRemove(IDASquadMemberClass^ member)
	{
		if (member == nullptr || member->DASquadMemberClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("member");
		}

		InternalDASquadClassPointer->Internal_Remove(
			reinterpret_cast<::DASquadMemberClass*>(member->DASquadMemberClassPointer.ToPointer()));
	}

	void DASquadClass::Disband()
	{
		InternalDASquadClassPointer->Disband();
	}

	void DASquadClass::SquadChat(IcPlayer^ player, String^ format, ...array<Object^>^ args)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			InternalDASquadClassPointer->Squad_Chat(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DASquadClass::SquadMessage(String^ format, ...array<Object^>^ args)
	{
		if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			InternalDASquadClassPointer->Squad_Message(
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DASquadClass::SquadMessageExcept(IcPlayer^ player, String^ format, ...array<Object^>^ args)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			InternalDASquadClassPointer->Squad_Message_Except(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	void DASquadClass::LeaderMessage(String^ format, ...array<Object^>^ args)
	{
		if (format == nullptr)
		{
			throw gcnew ArgumentNullException("format");
		}

		IntPtr formatHandle = Marshal::StringToHGlobalAnsi(String::Format(format, args));
		try
		{
			InternalDASquadClassPointer->Leader_Message(
				reinterpret_cast<char*>(formatHandle.ToPointer()));
		}
		finally
		{
			Marshal::FreeHGlobal(formatHandle);
		}
	}

	bool DASquadClass::IsMember(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		return InternalDASquadClassPointer->Is_Member(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	bool DASquadClass::IsLeader(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		return InternalDASquadClassPointer->Is_Leader(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	IDASquadMemberClass^ DASquadClass::FindMember(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		auto result = InternalDASquadClassPointer->Find_Member(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DASquadMemberClass(IntPtr(result));
		}
	}

	IDASquadMemberClass^ DASquadClass::GetMember(int index)
	{
		if (index < 0 || index >= InternalDASquadClassPointer->Size())
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalDASquadClassPointer->Get_Member(index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DASquadMemberClass(IntPtr(result));
		}
	}

	void DASquadClass::CheckTeam()
	{
		InternalDASquadClassPointer->Check_Team();
	}

	void DASquadClass::SetLeader(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		InternalDASquadClassPointer->Set_Leader(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	IntPtr DASquadClass::DASquadClassPointer::get()
	{
		return IntPtr(InternalDASquadClassPointer);
	}

	IDASquadMemberClass^ DASquadClass::Leader::get()
	{
		auto result = InternalDASquadClassPointer->Get_Leader();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DASquadMemberClass(IntPtr(result));
		}
	}

	int DASquadClass::Team::get()
	{
		return InternalDASquadClassPointer->Get_Team();
	}

	void DASquadClass::Team::set(int value)
	{
		InternalDASquadClassPointer->Set_Team(value);
	}

	int DASquadClass::Size::get()
	{
		return InternalDASquadClassPointer->Size();
	}

	bool DASquadClass::IsFull::get()
	{
		return InternalDASquadClassPointer->Is_Full();
	}

	int DASquadClass::ActiveSize::get()
	{
		return InternalDASquadClassPointer->Active_Size();
	}

	bool DASquadClass::InternalDestroyPointer()
	{
		Imports::DestroyDASquadClass(InternalDASquadClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::DASquadClass* DASquadClass::InternalDASquadClassPointer::get()
	{
		return reinterpret_cast<::DASquadClass*>(Pointer.ToPointer());
	}

	DASquadManagerClass::DASquadManagerClass(IntPtr pointer)
		: DAEventClass(pointer)
	{
		daGameFeatureClass = gcnew DAGameFeatureClass(IntPtr(InternalDAGameFeatureClassPointer));
	}

	String^ DASquadManagerClass::ToString()
	{
		return daGameFeatureClass->ToString();
	}

	bool DASquadManagerClass::Equals(Object^ other)
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
			if (daGameFeatureClass->Equals(otherDAGameFeatureClass))
			{
				return true;
			}
		}

		auto otherDASquadManagerClass = dynamic_cast<IDASquadManagerClass^>(other);
		if (otherDASquadManagerClass != nullptr)
		{
			if (DASquadManagerClassPointer.Equals(otherDASquadManagerClass->DASquadManagerClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void DASquadManagerClass::Init()
	{
		daGameFeatureClass->Init();
	}

	IRenSharpGameFeatureClass^ DASquadManagerClass::AsManagedGameFeature()
	{
		return daGameFeatureClass->AsManagedGameFeature();
	}

	IDASquadClass^ DASquadManagerClass::CreateSquad(IcPlayer^ leader)
	{
		if (leader == nullptr || leader->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("leader");
		}

		auto result = InternalDASquadManagerClassPointer->Create_Squad(
			reinterpret_cast<::cPlayer*>(leader->cPlayerPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DASquadClass(IntPtr(result));
		}
	}

	void DASquadManagerClass::Invite(IcPlayer^ player, IcPlayer^ leader)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}
		else if (leader == nullptr || leader->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("leader");
		}

		InternalDASquadManagerClassPointer->Invite(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
			reinterpret_cast<::cPlayer*>(leader->cPlayerPointer.ToPointer()));
	}

	void DASquadManagerClass::JoinAccepted(int joinIndex)
	{
		if (joinIndex < 0)
		{
			throw gcnew ArgumentOutOfRangeException("joinIndex");
		}

		InternalDASquadManagerClassPointer->Join_Accepted(joinIndex);
	}

	void DASquadManagerClass::InviteAccepted(int inviteIndex)
	{
		if (inviteIndex < 0)
		{
			throw gcnew ArgumentOutOfRangeException("inviteIndex");
		}

		InternalDASquadManagerClassPointer->Invite_Accepted(inviteIndex);
	}

	bool DASquadManagerClass::IsJoinPending(IcPlayer^ player, IcPlayer^ leader)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		if (leader == nullptr || leader->cPlayerPointer.ToPointer() == nullptr)
		{
			return InternalDASquadManagerClassPointer->Is_Join_Pending(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
				nullptr);
		}
		else
		{
			return InternalDASquadManagerClassPointer->Is_Join_Pending(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
				reinterpret_cast<::cPlayer*>(leader->cPlayerPointer.ToPointer()));
		}
	}

	bool DASquadManagerClass::IsJoinPending(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		return InternalDASquadManagerClassPointer->Is_Join_Pending(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	bool DASquadManagerClass::IsInvitePending(IcPlayer^ player, IcPlayer^ leader)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		if (leader == nullptr || leader->cPlayerPointer.ToPointer() == nullptr)
		{
			return InternalDASquadManagerClassPointer->Is_Invite_Pending(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
				nullptr);
		}
		else
		{
			return InternalDASquadManagerClassPointer->Is_Invite_Pending(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
				reinterpret_cast<::cPlayer*>(leader->cPlayerPointer.ToPointer()));
		}
	}

	bool DASquadManagerClass::IsInvitePending(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		return InternalDASquadManagerClassPointer->Is_Invite_Pending(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	bool DASquadManagerClass::IsWaitListPending(IcPlayer^ player, IcPlayer^ leader)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		if (leader == nullptr || leader->cPlayerPointer.ToPointer() == nullptr)
		{
			return InternalDASquadManagerClassPointer->Is_WaitList_Pending(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
				nullptr);
		}
		else
		{
			return InternalDASquadManagerClassPointer->Is_WaitList_Pending(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
				reinterpret_cast<::cPlayer*>(leader->cPlayerPointer.ToPointer()));
		}
	}

	bool DASquadManagerClass::IsWaitListPending(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		return InternalDASquadManagerClassPointer->Is_WaitList_Pending(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	bool DASquadManagerClass::RemoveJoin(IcPlayer^ player, IcPlayer^ leader)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		if (leader == nullptr || leader->cPlayerPointer.ToPointer() == nullptr)
		{
			return InternalDASquadManagerClassPointer->Remove_Join(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
				nullptr);
		}
		else
		{
			return InternalDASquadManagerClassPointer->Remove_Join(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
				reinterpret_cast<::cPlayer*>(leader->cPlayerPointer.ToPointer()));
		}
	}

	bool DASquadManagerClass::RemoveJoin(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		return InternalDASquadManagerClassPointer->Remove_Join(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	bool DASquadManagerClass::RemoveInvite(IcPlayer^ player, IcPlayer^ leader)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		if (leader == nullptr || leader->cPlayerPointer.ToPointer() == nullptr)
		{
			return InternalDASquadManagerClassPointer->Remove_Invite(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
				nullptr);
		}
		else
		{
			return InternalDASquadManagerClassPointer->Remove_Invite(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
				reinterpret_cast<::cPlayer*>(leader->cPlayerPointer.ToPointer()));
		}
	}

	bool DASquadManagerClass::RemoveInvite(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		return InternalDASquadManagerClassPointer->Remove_Invite(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	bool DASquadManagerClass::RemoveWaitList(IcPlayer^ player, IcPlayer^ leader)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		if (leader == nullptr || leader->cPlayerPointer.ToPointer() == nullptr)
		{
			return InternalDASquadManagerClassPointer->Remove_WaitList(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
				nullptr);
		}
		else
		{
			return InternalDASquadManagerClassPointer->Remove_WaitList(
				reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()),
				reinterpret_cast<::cPlayer*>(leader->cPlayerPointer.ToPointer()));
		}
	}

	bool DASquadManagerClass::RemoveWaitList(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		return InternalDASquadManagerClassPointer->Remove_WaitList(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	bool DASquadManagerClass::ClearJoins(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		return InternalDASquadManagerClassPointer->Clear_Joins(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	bool DASquadManagerClass::ClearInvites(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		return InternalDASquadManagerClassPointer->Clear_Invites(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	bool DASquadManagerClass::ClearWaitList(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		return InternalDASquadManagerClassPointer->Clear_WaitList(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	void DASquadManagerClass::ClearLists(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		InternalDASquadManagerClassPointer->Clear_Lists(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
	}

	IDASquadClass^ DASquadManagerClass::FindSquad(IcPlayer^ player)
	{
		if (player == nullptr || player->cPlayerPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("player");
		}

		auto result = InternalDASquadManagerClassPointer->Find_Squad(
			reinterpret_cast<::cPlayer*>(player->cPlayerPointer.ToPointer()));
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DASquadClass(IntPtr(result));
		}
	}

	IDASquadClass^ DASquadManagerClass::GetSquad(int index)
	{
		if (index < 0 || index >= InternalDASquadManagerClassPointer->Get_Squad_Count())
		{
			throw gcnew ArgumentOutOfRangeException("index");
		}

		auto result = InternalDASquadManagerClassPointer->Get_Squad(index);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DASquadClass(IntPtr(result));
		}
	}

	void DASquadManagerClass::CheckTeams()
	{
		InternalDASquadManagerClassPointer->Check_Teams();
	}

	void DASquadManagerClass::CheckSize()
	{
		InternalDASquadManagerClassPointer->Check_Size();
	}

	IDAGameFeatureRegistrant<IDASquadManagerClass^>^ DASquadManagerClass::Registrant::get()
	{
		return gcnew DASquadManagerClassDAGameFeatureRegistrant(IntPtr(&::DASquadManagerClassRegistrant));
	}

	IDASquadManagerClass^ DASquadManagerClass::Instance::get()
	{
		auto result = ::DASquadManagerClassRegistrant.Get_Instance();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew DASquadManagerClass(IntPtr(result));
		}
	}

	IntPtr DASquadManagerClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void DASquadManagerClass::Pointer::set(IntPtr value)
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

	IntPtr DASquadManagerClass::DASquadManagerClassPointer::get()
	{
		return IntPtr(InternalDASquadManagerClassPointer);
	}

	IntPtr DASquadManagerClass::DAGameFeatureClassPointer::get()
	{
		return IntPtr(InternalDAGameFeatureClassPointer);
	}

	String^ DASquadManagerClass::Name::get()
	{
		return daGameFeatureClass->Name;
	}

	IDAGameFeatureFactoryClass^ DASquadManagerClass::Factory::get()
	{
		return daGameFeatureClass->Factory;
	}

	void DASquadManagerClass::Factory::set(IDAGameFeatureFactoryClass^ value)
	{
		daGameFeatureClass->Factory = value;
	}

	bool DASquadManagerClass::IsManagedGameFeature::get()
	{
		return daGameFeatureClass->IsManagedGameFeature;
	}

	int DASquadManagerClass::SquadCount::get()
	{
		return InternalDASquadManagerClassPointer->Get_Squad_Count();
	}

	int DASquadManagerClass::MaxSquadSize::get()
	{
		return InternalDASquadManagerClassPointer->Get_Max_Squad_Size();
	}

	bool DASquadManagerClass::CanCreateSquads::get()
	{
		return InternalDASquadManagerClassPointer->Can_Create_Squads();
	}

	::DAEventClass* DASquadManagerClass::InternalDAEventClassPointer::get()
	{
		return InternalDASquadManagerClassPointer;
	}

	::DAGameFeatureClass* DASquadManagerClass::InternalDAGameFeatureClassPointer::get()
	{
		return InternalDASquadManagerClassPointer;
	}

	::DASquadManagerClass* DASquadManagerClass::InternalDASquadManagerClassPointer::get()
	{
		return reinterpret_cast<::DASquadManagerClass*>(Pointer.ToPointer());
	}

	DASquadManagerClassDAGameFeatureRegistrant::DASquadManagerClassDAGameFeatureRegistrant(IntPtr pointer)
		: DAGameFeatureRegistrant<IDASquadManagerClass^>(pointer)
	{

	}

	IntPtr DASquadManagerClassDAGameFeatureRegistrant::DASquadManagerClassDAGameFeatureRegistrantPointer::get()
	{
		return IntPtr(InternalDASquadManagerClassDAGameFeatureRegistrantPointer);
	}

	::DAGameFeatureFactoryClass* DASquadManagerClassDAGameFeatureRegistrant::InternalDAGameFeatureFactoryClassPointer::get()
	{
		return InternalDASquadManagerClassDAGameFeatureRegistrantPointer;
	}

	::DAGameFeatureRegistrant<::DASquadManagerClass>* DASquadManagerClassDAGameFeatureRegistrant::InternalDASquadManagerClassDAGameFeatureRegistrantPointer::get()
	{
		return reinterpret_cast<::DAGameFeatureRegistrant<::DASquadManagerClass>*>(Pointer.ToPointer());
	}
}