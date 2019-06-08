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
#include "Mda_gameobj.h"

#pragma managed(push, off)

class DAVehicleObserverClass;
class DAAirDroppedVehicleObserverClass;
class DAVehicleManager;

#pragma managed(pop)

namespace RenSharp
{
	value class Vector3;

	public interface class IDAVehicleObserverClass : public IDAGameObjObserverClass
	{
		void ResetLastExitTime();

		void ResetLastTheftTime();

		property IntPtr DAVehicleObserverClassPointer
		{
			IntPtr get();
		}

		property IcPlayer^ VehicleOwner
		{
			IcPlayer^ get();
			void set(IcPlayer^ value);
		}

		property int Team
		{
			int get();
			void set(int value);
		}

		property unsigned int TimeSinceLastExit
		{
			unsigned int get();
		}

		property unsigned int TimeSinceLastTheft
		{
			unsigned int get();
		}

		property IVehicleGameObj^ Vehicle
		{
			IVehicleGameObj^ get();
		}
	};

	public ref class DAVehicleObserverClass : public DAGameObjObserverClass, public IDAVehicleObserverClass
	{
		public:
			DAVehicleObserverClass(IntPtr pointer);

			virtual void ResetLastExitTime() sealed;
			virtual void ResetLastTheftTime() sealed;

			property IntPtr DAVehicleObserverClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IcPlayer^ VehicleOwner
			{
				virtual IcPlayer^ get() sealed;
				virtual void set(IcPlayer^ value) sealed;
			}

			property int Team
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property unsigned int TimeSinceLastExit
			{
				virtual unsigned int get() sealed;
			}

			property unsigned int TimeSinceLastTheft
			{
				virtual unsigned int get() sealed;
			}

			property IVehicleGameObj^ Vehicle
			{
				virtual IVehicleGameObj^ get() sealed;
			}

		protected:
			property ::DAGameObjObserverClass* InternalDAGameObjObserverClassPointer
			{
				::DAGameObjObserverClass* get() override;
			}

			property ::DAVehicleObserverClass* InternalDAVehicleObserverClassPointer
			{
				virtual ::DAVehicleObserverClass* get();
			}
	};

	public interface class IDAAirDroppedVehicleObserverClass : public IDAGameObjObserverClass
	{
		property IntPtr DAAirDroppedVehicleObserverClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DAAirDroppedVehicleObserverClass : public DAGameObjObserverClass, public IDAAirDroppedVehicleObserverClass
	{
		public:
			DAAirDroppedVehicleObserverClass(IntPtr pointer);

			property IntPtr DAAirDroppedVehicleObserverClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::DAGameObjObserverClass* InternalDAGameObjObserverClassPointer
			{
				::DAGameObjObserverClass* get() override;
			}

			property ::DAAirDroppedVehicleObserverClass* InternalDAAirDroppedVehicleObserverClassPointer
			{
				virtual ::DAAirDroppedVehicleObserverClass* get();
			}
	};

	public interface class IDAVehicleManager : public IDAEventClass
	{
		property IntPtr DAVehicleManagerPointer
		{
			IntPtr get();
		}
	};

	public ref class DAVehicleManager : public DAEventClass, public IDAVehicleManager
	{
		// Although you can instantiate a DAVehicleManager class, it doesn't make any sense so I left it out
		public:
			DAVehicleManager(IntPtr pointer);

			static bool CheckLimitForPlayer(IcPlayer^ player);
			static IDAVehicleObserverClass^ GetVehicleData(IScriptableGameObj^ obj);
			static IcPlayer^ GetVehicleOwner(IScriptableGameObj^ obj);
			static int GetTeam(IScriptableGameObj^ obj);
			static void AirDropVehicle(int team, IVehicleGameObj^ vehicle, Vector3 position, float facing);
			static IVehicleGameObj^ AirDropVehicle(int team, IVehicleGameObjDef^ vehicle, Vector3 position, float facing);
			static IVehicleGameObj^ AirDropVehicle(int team, unsigned int vehicle, Vector3 position, float facing);
			static IVehicleGameObj^ AirDropVehicle(int team, String^ vehicle, Vector3 position, float facing);

			property IntPtr DAVehicleManagerPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::DAEventClass* InternalDAEventClassPointer
			{
				::DAEventClass* get() override;
			}

			property ::DAVehicleManager* InternalDAVehicleManagerPointer
			{
				virtual ::DAVehicleManager* get();
			}
	};
}