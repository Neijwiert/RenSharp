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

#include "IUnmanagedObject.h"
#include "AbstractUnmanagedObject.h"
#include "Mengine_io.h"

#pragma managed(push, off)

class PlayerDataClass;

#pragma managed(pop)

using namespace System;

namespace RenSharp
{
	interface class IReferencerClass;
	interface class ISmartGameObj;

	public interface class IPlayerDataClass : public IUnmanagedObject
	{
		void StatsAddGameTime(float time);

		property IntPtr PlayerDataClassPointer
		{
			IntPtr get();
		}

		property float Score
		{
			float get();
			void set(float value);
		}

		property float Money
		{
			float get();
			void set(float value);
		}

		property IReferencerClass ^Owner
		{
			IReferencerClass ^get();
			void set(IReferencerClass ^value);
		}

		property float PunishTimer
		{
			float get();
			void set(float value);
		}

		property float GameTime
		{
			float get();
			void set(float value);
		}

		property float SessionTime
		{
			float get();
			void set(float value);
		}

		property int EnemiesKilled
		{
			int get();
			void set(int value);
		}

		property int AlliesKilled
		{
			int get();
			void set(int value);
		}

		property int ShotsFired
		{
			int get();
			void set(int value);
		}

		property int HeadShots
		{
			int get();
			void set(int value);
		}

		property int TorsoShots
		{
			int get();
			void set(int value);
		}

		property int ArmShots
		{
			int get();
			void set(int value);
		}

		property int LegShots
		{
			int get();
			void set(int value);
		}

		property int CrotchShots
		{
			int get();
			void set(int value);
		}

		property float FinalHealth
		{
			float get();
			void set(float value);
		}

		property int PowerupsCollected
		{
			int get();
			void set(int value);
		}

		property int VehiclesDestroyed
		{
			int get();
			void set(int value);
		}

		property float VehicleTime
		{
			float get();
			void set(float value);
		}

		property int KillsFromVehicle
		{
			int get();
			void set(int value);
		}

		property int Squishes
		{
			int get();
			void set(int value);
		}

		property float CreditGrant
		{
			float get();
			void set(float value);
		}

		property int BuildingDestroyed
		{
			int get();
			void set(int value);
		}

		property int HeadHit
		{
			int get();
			void set(int value);
		}

		property int TorsoHit
		{
			int get();
			void set(int value);
		}

		property int ArmHit
		{
			int get();
			void set(int value);
		}

		property int LegHit
		{
			int get();
			void set(int value);
		}

		property int CrotchHit
		{
			int get();
			void set(int value);
		}

		property int WeaponFired
		{
			int get();
			void set(int value);
		}

		property ISimpleDynVecClass<int> ^WeaponsFiredID
		{
			ISimpleDynVecClass<int> ^get();
			void set(ISimpleDynVecClass<int> ^value);
		}

		property ISimpleDynVecClass<int> ^WeaponsFiredCount
		{
			ISimpleDynVecClass<int> ^get();
			void set(ISimpleDynVecClass<int> ^value);
		}

		property ISmartGameObj ^GameObj
		{
			ISmartGameObj ^get();
			void set(ISmartGameObj ^value);
		}
	};

	public ref class PlayerDataClass : public AbstractUnmanagedObject, public IPlayerDataClass
	{
		public:
			PlayerDataClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual void StatsAddGameTime(float time) sealed;

			property IntPtr PlayerDataClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property float Score
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float Money
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property IReferencerClass ^Owner
			{
				virtual IReferencerClass ^get() sealed;
				virtual void set(IReferencerClass ^value) sealed;
			}

			property float PunishTimer
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float GameTime
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float SessionTime
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int EnemiesKilled
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int AlliesKilled
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int ShotsFired
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int HeadShots
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int TorsoShots
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int ArmShots
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int LegShots
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int CrotchShots
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property float FinalHealth
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int PowerupsCollected
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int VehiclesDestroyed
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property float VehicleTime
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int KillsFromVehicle
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int Squishes
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property float CreditGrant
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property int BuildingDestroyed
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int HeadHit
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int TorsoHit
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int ArmHit
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int LegHit
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int CrotchHit
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int WeaponFired
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property ISimpleDynVecClass<int> ^WeaponsFiredID
			{
				virtual ISimpleDynVecClass<int> ^get() sealed;
				virtual void set(ISimpleDynVecClass<int> ^value) sealed;
			}

			property ISimpleDynVecClass<int> ^WeaponsFiredCount
			{
				virtual ISimpleDynVecClass<int> ^get() sealed;
				virtual void set(ISimpleDynVecClass<int> ^value) sealed;
			}

			property ISmartGameObj ^GameObj
			{
				virtual ISmartGameObj ^get() sealed;
				virtual void set(ISmartGameObj ^value) sealed;
			}

		protected:
			property ::PlayerDataClass *InternalPlayerDataClassPointer
			{
				virtual ::PlayerDataClass *get();
			}
	};
}