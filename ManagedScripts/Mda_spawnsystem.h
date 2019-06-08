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

#include "Mda_event.h"
#include "Mda_player.h"
#include "Mengine_vector.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <engine_player.h>
#include <da_spawnsystem.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	value class Vector3;
	interface class IINIClass;

	public enum class DASpawnState : int
	{
		Dead = ::DASpawnState::State::DEAD,
		WaitingRoom = ::DASpawnState::State::WAITINGROOM,
		Spawning = ::DASpawnState::State::SPAWNING,
		Spawned = ::DASpawnState::State::SPAWNED
	};

	public interface class IDASpawnPlayerDataClass : public IDAPlayerDataClass
	{
		property IntPtr DASpawnPlayerDataClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DASpawnPlayerDataClass : public DAPlayerDataClass, public IDASpawnPlayerDataClass
	{
		private:
			DASpawnPlayerDataClass();

		public:
			DASpawnPlayerDataClass(IntPtr pointer);

			property IntPtr DASpawnPlayerDataClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::DAPlayerDataClass* InternalDAPlayerDataClassPointer
			{
				::DAPlayerDataClass* get() override;
			}

			property ::DASpawnPlayerDataClass* InternalDASpawnPlayerDataClassPointer
			{
				virtual ::DASpawnPlayerDataClass* get();
			}
	};

	public interface class IDistanceCheckStruct : public IUnmanagedObject
	{
		property IntPtr DistanceCheckStructPointer
		{
			IntPtr get();
		}

		property float Both
		{
			float get();
			void set(float value);
		}

		property float Ally
		{
			float get();
			void set(float value);
		}

		property float Enemy
		{
			float get();
			void set(float value);
		}
	};

	public ref class DistanceCheckStruct : public AbstractUnmanagedObject, public IDistanceCheckStruct
	{
		private:
			DistanceCheckStruct();

		public:
			DistanceCheckStruct(IntPtr pointer);

			static IUnmanagedContainer<IDistanceCheckStruct^>^ CreateDistanceCheckStruct();

			bool Equals(Object^ other) override;

			property IntPtr DistanceCheckStructPointer
			{
				virtual IntPtr get() sealed;
			}

			property float Both
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float Ally
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float Enemy
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DASpawnPointClass::DistanceCheckStruct* InternalDistanceCheckStructPointer
			{
				virtual ::DASpawnPointClass::DistanceCheckStruct* get();
			}
	};

	public interface class IDASpawnPointClass : public IDAEventClass
	{
		void ClearSpawnListFindNewSpawn();

		void ClearSpawnList();

		float GetDistance(Vector3 position);

		IUnmanagedContainer<IDistanceCheckStruct^>^ DistanceCheck(Vector3 pos, int team);

		property IntPtr DASpawnPointClassPointer
		{
			IntPtr get();
		}

		property Vector3 CenterPoint
		{
			Vector3 get();
			void set(Vector3 value);
		}

		property IDynamicVectorClass<Vector3>^ Spawners
		{
			IDynamicVectorClass<Vector3>^ get();
		}

		property bool Enabled
		{
			bool get();
			void set(bool value);
		}

		property int Team
		{
			int get();
			void set(int value);
		}

		property String^ Group
		{
			String^ get();
		}

		property String^ Name
		{
			String^ get();
		}

		property unsigned int SpawnTime
		{
			unsigned int get();
			void set(unsigned int value);
		}

		property unsigned int BaseSpawnTime
		{
			unsigned int get();
		}

		property float ProtectTime
		{
			float get();
			void set(float value);
		}

		property int Priority
		{
			int get();
			void set(int value);
		}
	};

	public ref class DASpawnPointClass : public DAEventClass, public IDASpawnPointClass
	{
		public:
			DASpawnPointClass(IntPtr pointer);

			String^ ToString() override;

			virtual void ClearSpawnListFindNewSpawn() sealed;
			virtual void ClearSpawnList() sealed;
			virtual float GetDistance(Vector3 position) sealed;
			virtual IUnmanagedContainer<IDistanceCheckStruct^>^ DistanceCheck(Vector3 pos, int team) sealed;

			property IntPtr DASpawnPointClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property Vector3 CenterPoint
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

			property IDynamicVectorClass<Vector3>^ Spawners
			{
				virtual IDynamicVectorClass<Vector3>^ get() sealed;
			}

			property bool Enabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property int Team
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property String^ Group
			{
				virtual String^ get() sealed;
			}

			property String^ Name
			{
				virtual String^ get() sealed;
			}

			property unsigned int SpawnTime
			{
				virtual unsigned int get() sealed;
				virtual void set(unsigned int value) sealed;
			}

			property unsigned int BaseSpawnTime
			{
				virtual unsigned int get() sealed;
			}

			property float ProtectTime
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int Priority
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

		protected:
			property ::DAEventClass* InternalDAEventClassPointer
			{
				::DAEventClass* get() override;
			}

			property ::DASpawnPointClass* InternalDASpawnPointClassPointer
			{
				virtual ::DASpawnPointClass* get();
			}
	};

	public interface class IDASpawnManagerClass : public IDAEventClass, public IDAPlayerDataManagerClass<IDASpawnPlayerDataClass^>, public IDASingleton<IDASpawnManagerClass^>
	{
		void Init(IINIClass^ ini);

		void ReAddSpawnList(int id);

		void ReAddSpawnList(IScriptableGameObj^ obj);

		void SetNextSpawnLocation(IScriptableGameObj^ obj, String^ name);

		void SetNextSpawnLocation(int id, String^ name);

		void DisplayPT(IScriptableGameObj^ obj);

		IDASpawnPointClass^ CreateSpawnPoint(IINIClass^ ini, String^ header);

		IDASpawnPointClass^ FindSpawnPoint(String^ group);

		void EnableAllExcept(String^ group);

		void DisableAllExcept(String^ group);

		Vector3 GetDeathPosition(int id);

		Vector3 GetDeathPosition(IScriptableGameObj^ obj);

		property IntPtr DASpawnManagerClassPointer
		{
			IntPtr get();
		}

		property unsigned int SpawnTime
		{
			unsigned int get();
		}

		property unsigned int IntermissionTime
		{
			unsigned int get();
		}

		property float MinAllyDistance
		{
			float get();
		}

		property float MaxAllyDistance
		{
			float get();
		}

		property float MinEnemyDistance
		{
			float get();
		}

		property float MaxEnemyDistance
		{
			float get();
		}

		property bool UseWaitingRoom
		{
			bool get();
		}

		property float ProtectTime
		{
			float get();
		}
	};

	public ref class DASpawnManagerClass : public DAEventClass, public IDASpawnManagerClass
	{
		private:
			IDAPlayerDataFactoryClass^ daPlayerDataFactoryClass;

		public:
			DASpawnManagerClass(IntPtr pointer);

			bool Equals(Object^ other) override;

			static IDASpawnManagerClass^ CreateInstance();
			static void DestroyInstance();

			virtual IUnmanagedContainer<IDAPlayerDataClass^>^ CreateData() sealed;
			virtual IRenSharpPlayerDataFactoryClass^ AsManagedPlayerDataFactory() sealed;

			virtual IDASpawnPlayerDataClass^ GetPlayerData(int id) sealed;
			virtual IDASpawnPlayerDataClass^ GetPlayerData(IScriptableGameObj^ obj) sealed;
			virtual IDASpawnPlayerDataClass^ GetPlayerData(IcPlayer^ player) sealed;
			virtual IDASpawnPlayerDataClass^ GetPlayerData(IDAPlayerClass^ player) sealed;

			virtual void Init(IINIClass^ ini) sealed;
			virtual void ReAddSpawnList(int id) sealed;
			virtual void ReAddSpawnList(IScriptableGameObj^ obj) sealed;
			virtual void SetNextSpawnLocation(IScriptableGameObj^ obj, String^ name) sealed;
			virtual void SetNextSpawnLocation(int id, String^ name) sealed;
			virtual void DisplayPT(IScriptableGameObj^ obj) sealed;
			virtual IDASpawnPointClass^ CreateSpawnPoint(IINIClass^ ini, String^ header) sealed;
			virtual IDASpawnPointClass^ FindSpawnPoint(String^ group) sealed;
			virtual void EnableAllExcept(String^ group) sealed;
			virtual void DisableAllExcept(String^ group) sealed;
			virtual Vector3 GetDeathPosition(int id) sealed;
			virtual Vector3 GetDeathPosition(IScriptableGameObj^ obj) sealed;

			static property IDASpawnManagerClass^ Instance
			{
				IDASpawnManagerClass^ get();
			}

			property IntPtr Pointer
			{
				IntPtr get() override;

				protected:
					void set(IntPtr value) override;
			}

			property IntPtr DASpawnManagerClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr DAPlayerDataFactoryClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool IsManagedPlayerDataFactory
			{
				virtual bool get() sealed;
			}

			property unsigned int SpawnTime
			{
				virtual unsigned int get() sealed;
			}

			property unsigned int IntermissionTime
			{
				virtual unsigned int get() sealed;
			}

			property float MinAllyDistance
			{
				virtual float get() sealed;
			}

			property float MaxAllyDistance
			{
				virtual float get() sealed;
			}

			property float MinEnemyDistance
			{
				virtual float get() sealed;
			}

			property float MaxEnemyDistance
			{
				virtual float get() sealed;
			}

			property bool UseWaitingRoom
			{
				virtual bool get() sealed;
			}

			property float ProtectTime
			{
				virtual float get() sealed;
			}

		protected:
			property ::DAEventClass* InternalDAEventClassPointer
			{
				::DAEventClass* get() override;
			}

			property ::DAPlayerDataFactoryClass* InternalDAPlayerDataFactoryClassPointer
			{
				virtual ::DAPlayerDataFactoryClass* get();
			}

			property ::DASpawnManagerClass* InternalDASpawnManagerClassPointer
			{
				virtual ::DASpawnManagerClass* get();
			}
	};
}