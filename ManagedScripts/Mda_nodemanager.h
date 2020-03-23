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
#include "RenSharpNodeClass.h"
#include "Mengine_io.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <engine_player.h>
#include <da_nodemanager.h>
#include <type_traits>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	value class Vector3;
	interface class IDASpawnPointClass;

#pragma managed(push, off)

	class DABaseNodeClassHelper : public ::DABaseNodeClass
	{
		public:
			static constexpr std::size_t RadarSizeCount = (sizeof(Radar) / sizeof(std::remove_all_extents<decltype(Radar)>::type));
			static constexpr std::size_t SentDefendMessageSizeCount = (sizeof(SentDefendMessage) / sizeof(std::remove_all_extents<decltype(SentDefendMessage)>::type));
			static constexpr std::size_t PlayerCheckSizeCount = (sizeof(PlayerCheck) / sizeof(std::remove_all_extents<decltype(PlayerCheck)>::type));

		private:
			DABaseNodeClassHelper() = default;

		public:
			void _Init(const ::INIClass* ini, const ::StringClass& header)
			{
				Init(ini, header);
			}

			void Captured(int captureTeam)
			{
				::DABaseNodeClass::Captured(captureTeam);
			}

			void AttackTick(int attackTeam)
			{
				Attack_Tick(attackTeam);
			}

			void DefendTick()
			{
				Defend_Tick();
			}

			void ContestedEvent()
			{
				Contested_Event();
			}

			void CaptureEvent()
			{
				Capture_Event();
			}

			void UpdateIconAndRadar()
			{
				Update_Icon_And_Radar();
			}

			bool IsPlayerInRange(::SoldierGameObj* player)
			{
				return Is_Player_In_Range(player);
			}

			void GiveAttackDefendTickPoints(int team)
			{
				Give_Attack_Defend_Tick_Points(team);
			}

			void GiveCapturePoints()
			{
				Give_Capture_Points();
			}

			::Vector3& GetPosition()
			{
				return Position;
			}

			int& GetTeam()
			{
				return Team;
			}

			::StringClass& GetGroup()
			{
				return Group;
			}

			::StringClass& GetName()
			{
				return Name;
			}

			bool& GetIsContested()
			{
				return IsContested;
			}

			::PhysicalGameObj*& GetObject()
			{
				return Object;
			}

			::PhysicalGameObj*& GetIcon()
			{
				return Icon;
			}

			void GetRadar(::PhysicalGameObj** result)
			{
				for (std::size_t x = 0; x < RadarSizeCount; x++)
				{
					result[x] = Radar[x];
				}
			}

			void SetRadar(std::size_t index, ::PhysicalGameObj* obj)
			{
				Radar[index] = obj;
			}

			bool& GetSentAttackMessage()
			{
				return SentAttackMessage;
			}

			void GetSentDefendMessage(bool* result)
			{
				std::memcpy(result, SentDefendMessage, sizeof(SentDefendMessage));
			}

			void SetSentDefendMessage(bool* value)
			{
				std::memcpy(SentDefendMessage, value, sizeof(SentDefendMessage));
			}

			unsigned long& GetLastAttackMessage()
			{
				return LastAttackMessage;
			}

			unsigned long& GetLastAttackTick()
			{
				return LastAttackTick;
			}

			unsigned long& GetLastDefendTick()
			{
				return LastDefendTick;
			}

			void GetPlayerCheck(int* result)
			{
				std::memcpy(result, PlayerCheck, sizeof(PlayerCheck));
			}

			void SetPlayerCheck(int* value)
			{
				std::memcpy(PlayerCheck, value, sizeof(PlayerCheck));
			}

			int& GetLastAttackTeam()
			{
				return LastAttackTeam;
			}

			::StringClass& GetPreset()
			{
				return Preset;
			}

			::StringClass& GetModel()
			{
				return Model;
			}

			::StringClass& GetAnimation()
			{
				return Animation;
			}

			float& GetAttackDefendDistance()
			{
				return AttackDefendDistance;
			}

			bool& GetIgnoreLOS()
			{
				return IgnoreLOS;
			}
	};

	struct DANodeManagerClassNodes
	{
		typedef ::DynamicVectorClass<::DABaseNodeClass*>(::DANodeManagerClass::* type);
		friend type StealValue(DANodeManagerClassNodes);
	};

	template struct Rob<DANodeManagerClassNodes, &::DANodeManagerClass::Nodes>;

#pragma managed(pop)

	public ref class DABaseNodeClass : public DAEventClass, public IDABaseNodeClass
	{
		public:
			DABaseNodeClass(IntPtr pointer);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual void SetContested(bool value) sealed;	
			virtual IRenSharpNodeClass^ AsManagedNode() sealed;

			property IntPtr DABaseNodeClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property Vector3 Position
			{
				virtual Vector3 get() sealed;

				protected:
					void set(Vector3 value);
			}

			property String^ ObjectPreset
			{
				virtual String^ get() sealed;
			}

			property String^ ObjectModel
			{
				virtual String^ get() sealed;
			}

			property int Team
			{
				virtual int get() sealed;

				protected:
					void set(int value);
			}

			property String^ Group
			{
				virtual String^ get() sealed;

				protected:
					void set(String^ value);
			}

			property String^ Name
			{
				virtual String^ get() sealed;

				protected:
					void set(String^ value);
			}

			property bool IsContested
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

			property bool IsCapturable
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsCaptureOnce
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property String^ Type
			{
				virtual String^ get() sealed;
			}

			property bool IsManagedNode
			{
				virtual bool get() sealed;
			}

		protected:
			void Init(IINIClass^ ini, String^ header);
			void Captured(int captureTeam);
			void AttackTick(int attackTeam);
			void DefendTick();
			void ContestedEvent();
			void CaptureEvent();
			void UpdateIconAndRadar();
			bool IsPlayerInRange(ISoldierGameObj^ player);
			void GiveAttackDefendTickPoints(int team);
			void GiveCapturePoints();

			property ::DAEventClass* InternalDAEventClassPointer
			{
				::DAEventClass* get() override;
			}

			property ::DABaseNodeClass* InternalDABaseNodeClassPointer
			{
				virtual ::DABaseNodeClass* get();
			}

			property IPhysicalGameObj^ Object
			{
				IPhysicalGameObj^ get();
				void set(IPhysicalGameObj^ value);
			}

			property IPhysicalGameObj^ Icon
			{
				IPhysicalGameObj^ get();
				void set(IPhysicalGameObj^ value);
			}

			property array<IPhysicalGameObj^>^ Radar
			{
				array<IPhysicalGameObj^>^ get();
				void set(array<IPhysicalGameObj^>^ value);
			}

			property bool SentAttackMessage
			{
				bool get();
				void set(bool value);
			}

			property array<bool>^ SentDefendMessage
			{
				array<bool>^ get();
				void set(array<bool>^ value);
			}

			property unsigned long LastAttackMessage
			{
				unsigned long get();
				void set(unsigned long value);
			}

			property unsigned long LastAttackTick
			{
				unsigned long get();
				void set(unsigned long value);
			}

			property unsigned long LastDefendTick
			{
				unsigned long get();
				void set(unsigned long value);
			}

			property array<int>^ PlayerCheck
			{
				array<int>^ get();
				void set(array<int>^ value);
			}

			property int LastAttackTeam
			{
				int get();
				void set(int value);
			}

			property String^ Preset
			{
				String^ get();
				void set(String^ value);
			}

			property String^ Model
			{
				String^ get();
				void set(String^ value);
			}

			property String^ Animation
			{
				String^ get();
				void set(String^ value);
			}

			property float AttackDefendDistance
			{
				float get();
				void set(float value);
			}

			property bool IgnoreLOS
			{
				bool get();
				void set(bool value);
			}
	};

	public interface class IDASpawnNodeClass : public IDABaseNodeClass
	{
		property IntPtr DASpawnNodeClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DASpawnNodeClass : public DABaseNodeClass, public IDASpawnNodeClass
	{
		private:
			DASpawnNodeClass();

		public:
			DASpawnNodeClass(IntPtr pointer);

			static IUnmanagedContainer<IDASpawnNodeClass^>^ CreateDASpawnNodeClass();

#pragma push_macro("SpawnNodeType")
#undef SpawnNodeType
			static property String^ SpawnNodeType
			{
				String^ get();
			}
#pragma pop_macro("SpawnNodeType")

			property IntPtr DASpawnNodeClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::DABaseNodeClass* InternalDABaseNodeClassPointer
			{
				::DABaseNodeClass* get() override;
			}

			property ::DASpawnNodeClass* InternalDASpawnNodeClassPointer
			{
				virtual ::DASpawnNodeClass* get();
			}

			property IDASpawnPointClass^ SpawnPoint
			{
				IDASpawnPointClass^ get();
				void set(IDASpawnPointClass^ value);
			}
	};

	public interface class IDANodeManagerClass : public IDAEventClass, public IDASingleton<IDANodeManagerClass^>
	{
		void Init(IINIClass^ ini);

		IDASpawnNodeClass^ CreateSpawnNode(IINIClass^ ini, String^ header);

		generic<typename T>
		where T : IRenSharpNodeClass, gcnew()
		T CreateNode(IINIClass^ ini, String^ header);

		IDABaseNodeClass^ GetNode(int index);

		IDABaseNodeClass^ FindNode(String^ group);

		property IntPtr DANodeManagerClassPointer
		{
			IntPtr get();
		}

		property float AttackDefendDistance
		{
			float get();
		}

		property float AttackDefendTickAmount
		{
			float get();
		}

		property unsigned int AttackDefendTickTime
		{
			unsigned int get();
		}

		property float AttackDefendTickPoints
		{
			float get();
		}

		property int AttackDefendTickVeteranPoints
		{
			int get();
		}

		property float CapturePoints
		{
			float get();
		}

		property int CaptureVeteranPoints
		{
			int get();
		}

		property unsigned int ContestedSpawnTime
		{
			unsigned int get();
		}

		property int NodeCount
		{
			int get();
		}
	};

	public ref class DANodeManagerClass : public DAEventClass, public IDANodeManagerClass
	{
		private:
			static Generic::IDictionary<IntPtr, IRenSharpNodeClass^>^ managedNodes;

		public:
			static DANodeManagerClass();
			DANodeManagerClass(IntPtr pointer);

			static void OnManagedNodeDestructed(IntPtr node);
			static bool IsManagedNode(IntPtr node);
			static bool IsManagedNode(IDABaseNodeClass^ node);
			static IRenSharpNodeClass^ AsManagedNode(IntPtr node);
			static IRenSharpNodeClass^ AsManagedNode(IDABaseNodeClass^ node);

			static IDANodeManagerClass^ CreateInstance();
			static void DestroyInstance();

			virtual void Init(IINIClass^ ini) sealed;
			virtual IDASpawnNodeClass^ CreateSpawnNode(IINIClass^ ini, String^ header) sealed;
			virtual IDABaseNodeClass^ GetNode(int index) sealed;
			virtual IDABaseNodeClass^ FindNode(String^ group) sealed;

			generic<typename T>
			where T : IRenSharpNodeClass, gcnew()
			virtual T CreateNode(IINIClass^ ini, String^ header) sealed
			{
				if (ini == nullptr || ini->INIClassPointer.ToPointer() == nullptr)
				{
					throw gcnew ArgumentNullException("ini");
				}
				else if (header == nullptr)
				{
					throw gcnew ArgumentNullException("header");
				}

				auto& nodes = (*InternalDANodeManagerClassPointer).*StealValue(DANodeManagerClassNodes());

				T newNode = gcnew T();
				static_cast<IUnmanagedAttachable<IDABaseNodeClass^>^>(newNode)->InitUnmanagedAttachable();
				newNode->Init(ini, header);

				nodes.Add(
					reinterpret_cast<::DABaseNodeClass*>(newNode->DABaseNodeClassPointer.ToPointer()));

				return newNode;
			}

			static property IDANodeManagerClass^ Instance
			{
				IDANodeManagerClass^ get();
			}

			property IntPtr DANodeManagerClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property float AttackDefendDistance
			{
				virtual float get() sealed;
			}

			property float AttackDefendTickAmount
			{
				virtual float get() sealed;
			}

			property unsigned int AttackDefendTickTime
			{
				virtual unsigned int get() sealed;
			}

			property float AttackDefendTickPoints
			{
				virtual float get() sealed;
			}

			property int AttackDefendTickVeteranPoints
			{
				virtual int get() sealed;
			}

			property float CapturePoints
			{
				virtual float get() sealed;
			}

			property int CaptureVeteranPoints
			{
				virtual int get() sealed;
			}

			property unsigned int ContestedSpawnTime
			{
				virtual unsigned int get() sealed;
			}

			property int NodeCount
			{
				virtual int get() sealed;
			}

		internal:
			static void Shutdown();

			static void RegisterManagedNode(IRenSharpNodeClass^ node);
			static void UnregisterManagedNode(IRenSharpNodeClass^ node);

		protected:
			property ::DAEventClass* InternalDAEventClassPointer
			{
				::DAEventClass* get() override;
			}

			property ::DANodeManagerClass* InternalDANodeManagerClassPointer
			{
				virtual ::DANodeManagerClass* get();
			}
	};
}