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
#include "Mda_player.h"

#pragma managed(push, off)

struct DASquadInviteStruct;
struct DASquadRemixStruct;
class DASquadMemberClass;
class DASquadClass;
class DASquadManagerClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IDASquadClass;

	public interface class IDASquadInviteStruct : public IUnmanagedObject
	{
		property IntPtr DASquadInviteStructPointer
		{
			IntPtr get();
		}

		property IcPlayer^ Leader
		{
			IcPlayer^ get();
			void set(IcPlayer^ value);
		}

		property IcPlayer^ Player
		{
			IcPlayer^ get();
			void set(IcPlayer^ value);
		}

		property int Timeout
		{
			int get();
			void set(int value);
		}
	};

	public ref class DASquadInviteStruct : public AbstractUnmanagedObject, public IDASquadInviteStruct
	{
		private:
			DASquadInviteStruct();
			DASquadInviteStruct(IcPlayer^ leader, IcPlayer^ player);

		public:
			DASquadInviteStruct(IntPtr pointer);

			static IUnmanagedContainer<IDASquadInviteStruct^>^ CreateDASquadInviteStruct();
			static IUnmanagedContainer<IDASquadInviteStruct^>^ CreateDASquadInviteStruct(IcPlayer^ leader, IcPlayer^ player);

			bool Equals(Object^ other) override;

			property IntPtr DASquadInviteStructPointer
			{
				virtual IntPtr get() sealed;
			}

			property IcPlayer^ Leader
			{
				virtual IcPlayer^ get() sealed;
				virtual void set(IcPlayer^ value) sealed;
			}

			property IcPlayer^ Player
			{
				virtual IcPlayer^ get() sealed;
				virtual void set(IcPlayer^ value) sealed;
			}

			property int Timeout
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DASquadInviteStruct* InternalDASquadInviteStructPointer
			{
				virtual ::DASquadInviteStruct* get();
			}
	};

	public interface class IDASquadRemixStruct : public IUnmanagedObject
	{
		property IntPtr DASquadRemixStructPointer
		{
			IntPtr get();
		}

		property IDASquadClass^ Squad
		{
			IDASquadClass^ get();
			void set(IDASquadClass^ value);
		}

		property int Team
		{
			int get();
			void set(int value);
		}
	};

	public ref class DASquadRemixStruct : public AbstractUnmanagedObject, public IDASquadRemixStruct
	{
		private:
			DASquadRemixStruct();
			DASquadRemixStruct(IDASquadClass^ squad, int team);

		public:
			DASquadRemixStruct(IntPtr pointer);

			static IUnmanagedContainer<IDASquadRemixStruct^>^ CreateDASquadRemixStruct();
			static IUnmanagedContainer<IDASquadRemixStruct^>^ CreateDASquadRemixStruct(IDASquadClass^ squad, int team);

			bool Equals(Object^ other) override;

			property IntPtr DASquadRemixStructPointer
			{
				virtual IntPtr get() sealed;
			}

			property IDASquadClass^ Squad
			{
				virtual IDASquadClass^ get() sealed;
				virtual void set(IDASquadClass^ value) sealed;
			}

			property int Team
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DASquadRemixStruct* InternalDASquadRemixStructPointer
			{
				virtual ::DASquadRemixStruct* get();
			}
	};

	public interface class IDASquadMemberClass : public IDAPlayerObserverClass
	{
		bool DisbandChatCommand(IDATokenClass^ text, TextMessageEnum chatType);

		bool PromoteChatCommand(IDATokenClass^ text, TextMessageEnum chatType);

		bool InfoChatCommand(IDATokenClass^ text, TextMessageEnum chatType);

		bool SKickChatCommand(IDATokenClass^ text, TextMessageEnum chatType);

		bool MsgChatCommand(IDATokenClass^ text, TextMessageEnum chatType);

		void CreateRadar();

		void UpdateRadar();

		void AddRadar(IDASquadMemberClass^ member);

		void RemoveRadar(IDASquadMemberClass^ member);

		void LeaveSquad();

		property IntPtr DASquadMemberClassPointer
		{
			IntPtr get();
		}

		property IDASquadClass^ Squad
		{
			IDASquadClass^ get();
		}

		property bool IsLeader
		{
			bool get();
		}
	};

	public ref class DASquadMemberClass : public DAPlayerObserverClass, public IDASquadMemberClass
	{
		private:
			DASquadMemberClass(IDASquadClass^ squad);

		public:
			DASquadMemberClass(IntPtr pointer);

			static IUnmanagedContainer<IDASquadMemberClass^>^ CreateDASquadMemberClass(IDASquadClass^ squad);

			virtual bool DisbandChatCommand(IDATokenClass^ text, TextMessageEnum chatType) sealed;
			virtual bool PromoteChatCommand(IDATokenClass^ text, TextMessageEnum chatType) sealed;
			virtual bool InfoChatCommand(IDATokenClass^ text, TextMessageEnum chatType) sealed;
			virtual bool SKickChatCommand(IDATokenClass^ text, TextMessageEnum chatType) sealed;
			virtual bool MsgChatCommand(IDATokenClass^ text, TextMessageEnum chatType) sealed;
			virtual void CreateRadar() sealed;
			virtual void UpdateRadar() sealed;
			virtual void AddRadar(IDASquadMemberClass^ member) sealed;
			virtual void RemoveRadar(IDASquadMemberClass^ member) sealed;
			virtual void LeaveSquad() sealed;

			property IntPtr DASquadMemberClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IDASquadClass^ Squad
			{
				virtual IDASquadClass^ get() sealed;
			}

			property bool IsLeader
			{
				virtual bool get() sealed;
			}

		protected:
			property ::DAPlayerObserverClass* InternalDAPlayerObserverClassPointer
			{
				::DAPlayerObserverClass* get() override;
			}

			property ::DASquadMemberClass* InternalDASquadMemberClassPointer
			{
				virtual ::DASquadMemberClass* get();
			}
	};

	public interface class IDASquadClass : public IUnmanagedObject
	{
		void Add(IcPlayer^ player);

		bool Remove(IcPlayer^ player);

		void InternalRemove(IDASquadMemberClass^ member);

		void Disband();

		void SquadChat(IcPlayer^ player, String^ format, ...array<Object^>^ args);

		void SquadMessage(String^ format, ...array<Object^>^ args);

		void SquadMessageExcept(IcPlayer^ player, String^ format, ...array<Object^>^ args);

		void LeaderMessage(String^ format, ...array<Object^>^ args);

		bool IsMember(IcPlayer^ player);

		bool IsLeader(IcPlayer^ player);

		IDASquadMemberClass^ FindMember(IcPlayer^ player);

		IDASquadMemberClass^ GetMember(int index);

		void SetLeader(IcPlayer^ player);

		void CheckTeam();

		property IntPtr DASquadClassPointer
		{
			IntPtr get();
		}

		property IDASquadMemberClass^ Leader
		{
			IDASquadMemberClass^ get();
		}

		property int Team
		{
			int get();
			void set(int value);
		}

		property int Size
		{
			int get();
		}

		property bool IsFull
		{
			bool get();
		}

		property int ActiveSize
		{
			int get();
		}
	};

	public ref class DASquadClass : public AbstractUnmanagedObject, public IDASquadClass
	{
		private:
			DASquadClass(IcPlayer^ player);

		public:
			DASquadClass(IntPtr pointer);

			static IUnmanagedContainer<IDASquadClass^>^ CreateDASquadClass(IcPlayer^ player);

			bool Equals(Object^ other) override;

			virtual void Add(IcPlayer^ player) sealed;
			virtual bool Remove(IcPlayer^ player) sealed;
			virtual void InternalRemove(IDASquadMemberClass^ member) sealed;
			virtual void Disband() sealed;
			virtual void SquadChat(IcPlayer^ player, String^ format, ...array<Object^>^ args) sealed;
			virtual void SquadMessage(String^ format, ...array<Object^>^ args) sealed;
			virtual void SquadMessageExcept(IcPlayer^ player, String^ format, ...array<Object^>^ args) sealed;
			virtual void LeaderMessage(String^ format, ...array<Object^>^ args) sealed;
			virtual bool IsMember(IcPlayer^ player) sealed;
			virtual bool IsLeader(IcPlayer^ player) sealed;
			virtual IDASquadMemberClass^ FindMember(IcPlayer^ player) sealed;
			virtual IDASquadMemberClass^ GetMember(int index) sealed;
			virtual void CheckTeam() sealed;
			virtual void SetLeader(IcPlayer^ player) sealed;

			property IntPtr DASquadClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IDASquadMemberClass^ Leader
			{
				virtual IDASquadMemberClass^ get() sealed;
			}

			property int Team
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int Size
			{
				virtual int get() sealed;
			}

			property bool IsFull
			{
				virtual bool get() sealed;
			}

			property int ActiveSize
			{
				virtual int get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DASquadClass* InternalDASquadClassPointer
			{
				virtual ::DASquadClass* get();
			}
	};

	public interface class IDASquadManagerClass : public IDAEventClass, public IDAGameFeatureClass
	{
		IDASquadClass^ CreateSquad(IcPlayer^ leader);

		void Invite(IcPlayer^ player, IcPlayer^ leader);

		void JoinAccepted(int joinIndex);

		void InviteAccepted(int inviteIndex);

		bool IsJoinPending(IcPlayer^ player, IcPlayer^ leader);

		bool IsJoinPending(IcPlayer^ player);

		bool IsInvitePending(IcPlayer^ player, IcPlayer^ leader);

		bool IsInvitePending(IcPlayer^ player);

		bool IsWaitListPending(IcPlayer^ player, IcPlayer^ leader);

		bool IsWaitListPending(IcPlayer^ player);

		bool RemoveJoin(IcPlayer^ player, IcPlayer^ leader);

		bool RemoveJoin(IcPlayer^ player);

		bool RemoveInvite(IcPlayer^ player, IcPlayer^ leader);

		bool RemoveInvite(IcPlayer^ player);

		bool RemoveWaitList(IcPlayer^ player, IcPlayer^ leader);

		bool RemoveWaitList(IcPlayer^ player);

		bool ClearJoins(IcPlayer^ player);

		bool ClearInvites(IcPlayer^ player);

		bool ClearWaitList(IcPlayer^ player);

		void ClearLists(IcPlayer^ player);

		IDASquadClass^ FindSquad(IcPlayer^ player);

		IDASquadClass^ GetSquad(int index);

		void CheckTeams();

		void CheckSize();

		property IntPtr DASquadManagerClassPointer
		{
			IntPtr get();
		}

		property int SquadCount
		{
			int get();
		}

		property int MaxSquadSize
		{
			int get();
		}

		property bool CanCreateSquads
		{
			bool get();
		}
	};

	public ref class DASquadManagerClass : public DAEventClass, public IDASquadManagerClass
	{
		private:
			IDAGameFeatureClass^ daGameFeatureClass;

		public:
			DASquadManagerClass(IntPtr pointer);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual void Init() sealed;
			virtual IRenSharpGameFeatureClass^ AsManagedGameFeature() sealed;

			virtual IDASquadClass^ CreateSquad(IcPlayer^ leader) sealed;
			virtual void Invite(IcPlayer^ player, IcPlayer^ leader) sealed;
			virtual void JoinAccepted(int joinIndex) sealed;
			virtual void InviteAccepted(int inviteIndex) sealed;
			virtual bool IsJoinPending(IcPlayer^ player, IcPlayer^ leader) sealed;
			virtual bool IsJoinPending(IcPlayer^ player) sealed;
			virtual bool IsInvitePending(IcPlayer^ player, IcPlayer^ leader) sealed;
			virtual bool IsInvitePending(IcPlayer^ player) sealed;
			virtual bool IsWaitListPending(IcPlayer^ player, IcPlayer^ leader) sealed;
			virtual bool IsWaitListPending(IcPlayer^ player) sealed;
			virtual bool RemoveJoin(IcPlayer^ player, IcPlayer^ leader) sealed;
			virtual bool RemoveJoin(IcPlayer^ player) sealed;
			virtual bool RemoveInvite(IcPlayer^ player, IcPlayer^ leader) sealed;
			virtual bool RemoveInvite(IcPlayer^ player) sealed;
			virtual bool RemoveWaitList(IcPlayer^ player, IcPlayer^ leader) sealed;
			virtual bool RemoveWaitList(IcPlayer^ player) sealed;
			virtual bool ClearJoins(IcPlayer^ player) sealed;
			virtual bool ClearInvites(IcPlayer^ player) sealed;
			virtual bool ClearWaitList(IcPlayer^ player) sealed;
			virtual void ClearLists(IcPlayer^ player) sealed;
			virtual IDASquadClass^ FindSquad(IcPlayer^ player) sealed;
			virtual IDASquadClass^ GetSquad(int index) sealed;
			virtual void CheckTeams() sealed;
			virtual void CheckSize() sealed;

			static property IDAGameFeatureRegistrant<IDASquadManagerClass^>^ Registrant
			{
				IDAGameFeatureRegistrant<IDASquadManagerClass^>^ get();
			}

			static property IDASquadManagerClass^ Instance
			{
				IDASquadManagerClass^ get();
			}

			property IntPtr Pointer
			{
				IntPtr get() override;

				protected:
					void set(IntPtr value) override;
			}

			property IntPtr DASquadManagerClassPointer
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

			property int SquadCount
			{
				virtual int get() sealed;
			}

			property int MaxSquadSize
			{
				virtual int get() sealed;
			}

			property bool CanCreateSquads
			{
				virtual bool get() sealed;
			}

		protected:
			property ::DAEventClass* InternalDAEventClassPointer
			{
				::DAEventClass* get() override;
			}

			property ::DAGameFeatureClass* InternalDAGameFeatureClassPointer
			{
				virtual ::DAGameFeatureClass* get();
			}

			property ::DASquadManagerClass* InternalDASquadManagerClassPointer
			{
				virtual ::DASquadManagerClass* get();
			}
	};

	public ref class DASquadManagerClassDAGameFeatureRegistrant : public DAGameFeatureRegistrant<IDASquadManagerClass^>
	{
		public:
			DASquadManagerClassDAGameFeatureRegistrant(IntPtr pointer);

			property IntPtr DASquadManagerClassDAGameFeatureRegistrantPointer
			{
				IntPtr get();
			}

		protected:
			property ::DAGameFeatureFactoryClass* InternalDAGameFeatureFactoryClassPointer
			{
				::DAGameFeatureFactoryClass* get() override;
			}

			property ::DAGameFeatureRegistrant<::DASquadManagerClass>* InternalDASquadManagerClassDAGameFeatureRegistrantPointer
			{
				virtual ::DAGameFeatureRegistrant<::DASquadManagerClass>* get();
			}
	};
}