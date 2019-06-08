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
#include "Mengine_vector.h"

#pragma managed(push, off)

class DAVehicleSpawnPointClass;
class DAVehicleAirDropPointClass;
class DAVehicleSpawnManagerClass;

#pragma managed(pop)

namespace RenSharp
{
	value class Vector3;
	interface class IINIClass;
	interface class IVehicleFactoryGameObj;

	public interface class IDAVehicleSpawnPointClass : public IUnmanagedObject
	{
		void SpawnVehicle(String^ preset, ISoldierGameObj^ owner);

		void SpawnVehicle(unsigned int defID, ISoldierGameObj^ owner);

		void SpawnVehicle(IVehicleGameObjDef^ def, ISoldierGameObj^ owner);

		void SetEnabled(bool enable);

		void SetTeam(int team);

		float GetDistance(Vector3 pos);

		property IntPtr DAVehicleSpawnPointClassPointer
		{
			IntPtr get();
		}

		property String^ Group
		{
			String^ get();
		}

		property String^ Name
		{
			String^ get();
		}

		property Vector3 Position
		{
			Vector3 get();
		}

		property bool IsEnabled
		{
			bool get();
		}

		property int Team
		{
			int get();
		}

		property int Priority
		{
			int get();
			void set(int value);
		}
	};

	public ref class DAVehicleSpawnPointClass : public AbstractUnmanagedObject, public IDAVehicleSpawnPointClass
	{
		public:
			DAVehicleSpawnPointClass(IntPtr pointer);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual void SpawnVehicle(String^ preset, ISoldierGameObj^ owner) sealed;
			virtual void SpawnVehicle(unsigned int defID, ISoldierGameObj^ owner) sealed;
			virtual void SpawnVehicle(IVehicleGameObjDef^ def, ISoldierGameObj^ owner) sealed;
			virtual void SetEnabled(bool enable) sealed;
			virtual void SetTeam(int team) sealed;
			virtual float GetDistance(Vector3 pos) sealed;

			property IntPtr DAVehicleSpawnPointClassPointer
			{
				virtual IntPtr get() sealed;
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

			property Vector3 Position
			{
				virtual Vector3 get() sealed;

				protected:
					void set(Vector3 value);
			}

			property bool IsEnabled
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

			property int Team
			{
				virtual int get() sealed;

				protected:
					void set(int team);
			}

			property int Priority
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

		protected:
			void Init(IINIClass^ ini, String^ header);

			property ::DAVehicleSpawnPointClass* InternalDAVehicleSpawnPointClassPointer
			{
				virtual ::DAVehicleSpawnPointClass* get();
			}

			property float Facing
			{
				float get();
				void set(float value);
			}
	};

	public interface class IDAVehicleAirDropPointClass : public IDAVehicleSpawnPointClass
	{
		property IntPtr DAVehicleAirDropPointClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DAVehicleAirDropPointClass : public DAVehicleSpawnPointClass, public IDAVehicleAirDropPointClass
	{
		public:
			DAVehicleAirDropPointClass(IntPtr pointer);

			property IntPtr DAVehicleAirDropPointClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::DAVehicleSpawnPointClass* InternalDAVehicleSpawnPointClassPointer
			{
				::DAVehicleSpawnPointClass* get() override;
			}

			property ::DAVehicleAirDropPointClass* InternalDAVehicleAirDropPointClassPointer
			{
				virtual ::DAVehicleAirDropPointClass* get();
			}
	};

	public interface class IDAVehicleSpawnManagerClass : public IDAEventClass, public IDASingleton<IDAVehicleSpawnManagerClass^>
	{
		void Init(IINIClass^ ini);

		void SpawnVehicle(int team, String^ preset, ISoldierGameObj^ owner);

		void SpawnVehicle(int team, unsigned int defID, ISoldierGameObj^ owner);

		void SpawnVehicle(int team, IVehicleGameObjDef^ def, ISoldierGameObj^ owner);

		IDAVehicleSpawnPointClass^ CreateSpawnPoint(IINIClass^ ini, String^ header);

		IDAVehicleAirDropPointClass^ CreateAirDropPoint(IINIClass^ ini, String^ header);

		IDAVehicleSpawnPointClass^ FindSpawnPoint(String^ group);

		void EnableAllSpawnPointsExcept(String^ group);

		void DisableAllSpawnPointsExcept(String^ group);

		void DisableAllSpawnPointsTeam(int team);

		void EnableAllSpawnPointsTeam(int team);

		void SetAllSpawnPointsTeam(int team);

		bool AllSpawnPointsDisabledTeam(int team);

		void EnableVehicleFactory(int team, bool enable);

		void SetVehicleFactoryBusy(int team, bool busy);

		property IntPtr DAVehicleSpawnManagerClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DAVehicleSpawnManagerClass : public DAEventClass, public IDAVehicleSpawnManagerClass
	{
		public:
			DAVehicleSpawnManagerClass(IntPtr pointer);

			static IDAVehicleSpawnManagerClass^ CreateInstance();
			static void DestroyInstance();

			virtual void Init(IINIClass^ ini) sealed;
			virtual void SpawnVehicle(int team, String^ preset, ISoldierGameObj^ owner) sealed;
			virtual void SpawnVehicle(int team, unsigned int defID, ISoldierGameObj^ owner) sealed;
			virtual void SpawnVehicle(int team, IVehicleGameObjDef^ def, ISoldierGameObj^ owner) sealed;
			virtual IDAVehicleSpawnPointClass^ CreateSpawnPoint(IINIClass^ ini, String^ header) sealed;
			virtual IDAVehicleAirDropPointClass^ CreateAirDropPoint(IINIClass^ ini, String^ header) sealed;
			virtual IDAVehicleSpawnPointClass^ FindSpawnPoint(String^ group) sealed;
			virtual void EnableAllSpawnPointsExcept(String^ group) sealed;
			virtual void DisableAllSpawnPointsExcept(String^ group) sealed;
			virtual void DisableAllSpawnPointsTeam(int team) sealed;
			virtual void EnableAllSpawnPointsTeam(int team) sealed;
			virtual void SetAllSpawnPointsTeam(int team) sealed;
			virtual bool AllSpawnPointsDisabledTeam(int team) sealed;
			virtual void EnableVehicleFactory(int team, bool enable) sealed;
			virtual void SetVehicleFactoryBusy(int team, bool busy) sealed;

			static property IDAVehicleSpawnManagerClass^ Instance
			{
				IDAVehicleSpawnManagerClass^ get();
			}

			property IntPtr DAVehicleSpawnManagerClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::DAEventClass* InternalDAEventClassPointer
			{
				::DAEventClass* get() override;
			}

			property ::DAVehicleSpawnManagerClass* InternalDAVehicleSpawnManagerClass
			{
				virtual ::DAVehicleSpawnManagerClass* get();
			}

			property IDynamicVectorClass<IDAVehicleSpawnPointClass^>^ SpawnPoints
			{
				IDynamicVectorClass<IDAVehicleSpawnPointClass^>^ get();
				void set(IDynamicVectorClass<IDAVehicleSpawnPointClass^>^ value);
			}

			property array<IVehicleFactoryGameObj^>^ VF
			{
				array<IVehicleFactoryGameObj^>^ get();
				void set(array<IVehicleFactoryGameObj^>^ value);
			}
	};
}