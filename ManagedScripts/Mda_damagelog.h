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

#include "Mda_gameobj.h"
#include "Mda_event.h"
#include "MSList.h"
#include "Mengine_vector.h"

#pragma managed(push, off)

struct DADamageEventStruct;
struct DADamageTableStruct;
class DADamageLogObserverClass;
class DADamageLog;

#pragma managed(pop)

using namespace System::Runtime::InteropServices;

namespace RenSharp
{
	public interface class IDADamageEventStruct : public IUnmanagedObject
	{
		property IntPtr DADamageEventStructPointer
		{
			IntPtr get();
		}

		property float Damage
		{
			float get();
			void set(float value);
		}

		property IcPlayer^ Player
		{
			IcPlayer^ get();
			void set(IcPlayer^ value);
		}

		property unsigned int Time
		{
			unsigned int get();
			void set(unsigned int value);
		}
	};

	public ref class DADamageEventStruct : public AbstractUnmanagedObject, public IDADamageEventStruct
	{
		private:
			DADamageEventStruct();

		public:
			DADamageEventStruct(IntPtr pointer);

			static IUnmanagedContainer<IDADamageEventStruct^>^ CreateDADamageEventStruct();

			bool Equals(Object^ other) override;

			property IntPtr DADamageEventStructPointer
			{
				virtual IntPtr get() sealed;
			}

			property float Damage
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property IcPlayer^ Player
			{
				virtual IcPlayer^ get() sealed;
				virtual void set(IcPlayer^ value) sealed;
			}

			property unsigned int Time
			{
				virtual unsigned int get() sealed;
				virtual void set(unsigned int value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DADamageEventStruct* InternalDADamageEventStructPointer
			{
				virtual ::DADamageEventStruct* get();
			}
	};

	public interface class IDADamageTableStruct : public IUnmanagedObject
	{
		property IntPtr DADamageTableStructPointer
		{
			IntPtr get();
		}

		property IcPlayer^ Player
		{
			IcPlayer^ get();
			void set(IcPlayer^ value);
		}

		property float Damage
		{
			float get();
			void set(float value);
		}
	};

	public ref class DADamageTableStruct : public AbstractUnmanagedObject, public IDADamageTableStruct
	{
		private:
			DADamageTableStruct();
			DADamageTableStruct(IcPlayer^ player, float damage);

		public:
			DADamageTableStruct(IntPtr pointer);

			static IUnmanagedContainer<IDADamageTableStruct^>^ CreateDADamageTableStruct();
			static IUnmanagedContainer<IDADamageTableStruct^>^ CreateDADamageTableStruct(IcPlayer^ player, float damage);

			bool Equals(Object^ other) override;

			property IntPtr DADamageTableStructPointer
			{
				virtual IntPtr get() sealed;
			}

			property IcPlayer^ Player
			{
				virtual IcPlayer^ get() sealed;
				virtual void set(IcPlayer^ value) sealed;
			}

			property float Damage
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DADamageTableStruct* InternalDADamageTableStructPointer
			{
				virtual ::DADamageTableStruct* get();
			}
	};

	public interface class IDADamageLogObserverClass : public IDAGameObjObserverClass
	{
		void RemoveDamage(IcPlayer^ player);

		void ClearDamage();

		float CompileDamageTableTeam([Out] array<IUnmanagedContainer<IDADamageTableStruct^>^>^% damageTable, int team);

		float CompileDamageTableOtherTeam([Out] array<IUnmanagedContainer<IDADamageTableStruct^>^>^% damageTable, int team);

		IUnmanagedContainer<IDynamicVectorClass<IDADamageTableStruct^>^>^ GetDamagersByPercentTeam(int team, float minimumPercentTotal, float minimumPercentHighest);

		IUnmanagedContainer<IDynamicVectorClass<IDADamageTableStruct^>^>^ GetDamagersByPercentOtherTeam(int team, float minimumPercentTotal, float minimumPercentHighest);

		IcPlayer^ GetHighestDamagerTeam(int team);

		IcPlayer^ GetHighestDamagerOtherTeam(int team);

		float GetPercentTeamDamage(int team);

		float GetPercentOtherTeamDamage(int team);

		float GetPercentPlayerDamage(IcPlayer^ player);

		float CompileRepairTableTeam([Out] array<IUnmanagedContainer<IDADamageTableStruct^>^>^% damageTable, int team);

		float CompileRepairTableOtherTeam([Out] array<IUnmanagedContainer<IDADamageTableStruct^>^>^% damageTable, int team);

		IUnmanagedContainer<IDynamicVectorClass<IDADamageTableStruct^>^>^ GetRepairersByPercentTeam(int team, float minimumPercentTotal, float minimumPercentHighest);

		IUnmanagedContainer<IDynamicVectorClass<IDADamageTableStruct^>^>^ GetRepairersByPercentOtherTeam(int team, float minimumPercentTotal, float minimumPercentHighest);

		IcPlayer^ GetHighestRepairerTeam(int team);

		IcPlayer^ GetHighestRepairerOtherTeam(int team);

		float GetPercentTeamRepairs(int team);

		float GetPercentOtherTeamRepairs(int team);

		float GetPercentPlayerRepairs(IcPlayer^ player);

		property IntPtr DADamageLogObserverClassPointer
		{
			IntPtr get();
		}

		property ISList<IDADamageEventStruct^>^ DamageEvents
		{
			ISList<IDADamageEventStruct^>^ get();
		}

		property IDADamageEventStruct^ LastDamageEvent
		{
			IDADamageEventStruct^ get();
		}

		property IDADamageEventStruct^ LastRepairEvent
		{
			IDADamageEventStruct^ get();
		}
	};

	public ref class DADamageLogObserverClass : public DAGameObjObserverClass, public IDADamageLogObserverClass
	{
		public:
			DADamageLogObserverClass(IntPtr pointer);

			virtual void RemoveDamage(IcPlayer^ player) sealed;
			virtual void ClearDamage() sealed;
			virtual float CompileDamageTableTeam([Out] array<IUnmanagedContainer<IDADamageTableStruct^>^>^% damageTable, int team) sealed;
			virtual float CompileDamageTableOtherTeam([Out] array<IUnmanagedContainer<IDADamageTableStruct^>^>^% damageTable, int team) sealed;
			virtual IUnmanagedContainer<IDynamicVectorClass<IDADamageTableStruct^>^>^ GetDamagersByPercentTeam(int team, float minimumPercentTotal, float minimumPercentHighest) sealed;
			virtual IUnmanagedContainer<IDynamicVectorClass<IDADamageTableStruct^>^>^ GetDamagersByPercentOtherTeam(int team, float minimumPercentTotal, float minimumPercentHighest) sealed;
			virtual IcPlayer^ GetHighestDamagerTeam(int team) sealed;
			virtual IcPlayer^ GetHighestDamagerOtherTeam(int team) sealed;
			virtual float GetPercentTeamDamage(int team) sealed;
			virtual float GetPercentOtherTeamDamage(int team) sealed;
			virtual float GetPercentPlayerDamage(IcPlayer^ player) sealed;
			virtual float CompileRepairTableTeam([Out] array<IUnmanagedContainer<IDADamageTableStruct^>^>^% damageTable, int team) sealed;
			virtual float CompileRepairTableOtherTeam([Out] array<IUnmanagedContainer<IDADamageTableStruct^>^>^% damageTable, int team) sealed;
			virtual IUnmanagedContainer<IDynamicVectorClass<IDADamageTableStruct^>^>^ GetRepairersByPercentTeam(int team, float minimumPercentTotal, float minimumPercentHighest) sealed;
			virtual IUnmanagedContainer<IDynamicVectorClass<IDADamageTableStruct^>^>^ GetRepairersByPercentOtherTeam(int team, float minimumPercentTotal, float minimumPercentHighest) sealed;
			virtual IcPlayer^ GetHighestRepairerTeam(int team) sealed;
			virtual IcPlayer^ GetHighestRepairerOtherTeam(int team) sealed;
			virtual float GetPercentTeamRepairs(int team) sealed;
			virtual float GetPercentOtherTeamRepairs(int team) sealed;
			virtual float GetPercentPlayerRepairs(IcPlayer^ player) sealed;

			property IntPtr DADamageLogObserverClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property ISList<IDADamageEventStruct^>^ DamageEvents
			{
				virtual ISList<IDADamageEventStruct^>^ get() sealed;
			}

			property IDADamageEventStruct^ LastDamageEvent
			{
				virtual IDADamageEventStruct^ get() sealed;
			}

			property IDADamageEventStruct^ LastRepairEvent
			{
				virtual IDADamageEventStruct^ get() sealed;
			}

		protected:
			property ::DAGameObjObserverClass* InternalDAGameObjObserverClassPointer
			{
				::DAGameObjObserverClass* get() override;
			}

			property ::DADamageLogObserverClass* InternalDADamageLogObserverClassPointer
			{
				virtual ::DADamageLogObserverClass* get() sealed;
			}
	};

	public interface class IDADamageLog : public IDAEventClass
	{
		property IntPtr DADamageLogPointer
		{
			IntPtr get();
		}
	};

	public ref class DADamageLog : public DAEventClass, public IDADamageLog
	{
		// Although you can instantiate a DADamageLog class, it doesn't make any sense so I left it out
		public:
			DADamageLog(IntPtr pointer);

			static IDADamageLogObserverClass^ GetDamageLog(IScriptableGameObj^ obj);
			static ISList<IDADamageEventStruct^>^ GetDamageEvents(IScriptableGameObj^ obj);
			static float CompileDamageTableTeam([Out] array<IUnmanagedContainer<IDADamageTableStruct^>^>^% damageTable, IScriptableGameObj^ obj, int team);
			static float CompileDamageTableOtherTeam([Out] array<IUnmanagedContainer<IDADamageTableStruct^>^>^% damageTable, IScriptableGameObj^ obj, int team);
			static IUnmanagedContainer<IDynamicVectorClass<IDADamageTableStruct^>^>^ GetDamagersByPercentTeam(IScriptableGameObj^ obj, int team, float minimumPercentTotal, float minimumPercentHighest);
			static IUnmanagedContainer<IDynamicVectorClass<IDADamageTableStruct^>^>^ GetDamagersByPercentOtherTeam(IScriptableGameObj^ obj, int team, float minimumPercentTotal, float minimumPercentHighest);
			static IcPlayer^ GetHighestDamagerTeam(IScriptableGameObj^ obj, int team);
			static IcPlayer^ GetHighestDamagerOtherTeam(IScriptableGameObj^ obj, int team);
			static float GetPercentTeamDamage(IScriptableGameObj^ obj, int team);
			static float GetPercentOtherTeamDamage(IScriptableGameObj^ obj, int team);
			static float GetPercentPlayerDamage(IScriptableGameObj^ obj, IcPlayer^ player);
			static IDADamageEventStruct^ GetLastDamageEvent(IScriptableGameObj^ obj);
			static float CompileRepairTableTeam([Out] array<IUnmanagedContainer<IDADamageTableStruct^>^>^% damageTable, IScriptableGameObj^ obj, int team);
			static float CompileRepairTableOtherTeam([Out] array<IUnmanagedContainer<IDADamageTableStruct^>^>^% damageTable, IScriptableGameObj^ obj, int team);
			static IUnmanagedContainer<IDynamicVectorClass<IDADamageTableStruct^>^>^ GetRepairersByPercentTeam(IScriptableGameObj^ obj, int team, float minimumPercentTotal, float minimumPercentHighest);
			static IUnmanagedContainer<IDynamicVectorClass<IDADamageTableStruct^>^>^ GetRepairersByPercentOtherTeam(IScriptableGameObj^ obj, int team, float minimumPercentTotal, float minimumPercentHighest);
			static IcPlayer^ GetHighestRepairerTeam(IScriptableGameObj^ obj, int team);
			static IcPlayer^ GetHighestRepairerOtherTeam(IScriptableGameObj^ obj, int team);
			static float GetPercentTeamRepairs(IScriptableGameObj^ obj, int team);
			static float GetPercentOtherTeamRepairs(IScriptableGameObj^ obj, int team);
			static float GetPercentPlayerRepairs(IScriptableGameObj^ obj, IcPlayer^ player);
			static IDADamageEventStruct^ GetLastRepairEvent(IScriptableGameObj^ obj);

			property IntPtr DADamageLogPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::DAEventClass* InternalDAEventClassPointer
			{
				::DAEventClass* get() override;
			}

			property ::DADamageLog* InternalDADamageLogPointer
			{
				virtual ::DADamageLog* get();
			}
	};
}