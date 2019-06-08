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

#include "MNetworkObjectClass.h"
#include "MPersist.h"

#pragma managed(push, off)

class BaseGameObj;

#pragma managed(pop)

namespace RenSharp
{
	interface class IBaseGameObjDef;
	interface class IPhysicalGameObj;
	interface class IVehicleGameObj;
	interface class ISmartGameObj;
	interface class IScriptableGameObj;

	public interface class IBaseGameObj : public IPersistClass, public INetworkObjectClass
	{
		void Think();

		void PostThink();

		IPhysicalGameObj ^AsPhysicalGameObj();

		IVehicleGameObj ^AsVehicleGameObj();

		ISmartGameObj ^AsSmartGameObj();

		IScriptableGameObj ^AsScriptableGameObj();

		property IntPtr BaseGameObjPointer
		{
			IntPtr get();
		}

		property IBaseGameObjDef ^Definition
		{
			IBaseGameObjDef ^get();
		}

		property bool IsHibernating
		{
			bool get();
		}

		property int ID
		{
			int get();
		}

		property bool IsPostThinkAllowed
		{
			bool get();
			void set(bool value);
		}

		property bool EnableCinematicFreeze
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class BaseGameObj : public NetworkObjectClass, public IBaseGameObj
	{
		private:
			IPersistClass ^persistClass;

		public:
			BaseGameObj(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual void OnPostLoad() sealed;
			virtual bool Save(IChunkSaveClass ^csave) sealed;
			virtual bool Load(IChunkLoadClass ^cload) sealed;

			virtual void Think() sealed;
			virtual void PostThink() sealed;
			virtual IPhysicalGameObj ^AsPhysicalGameObj();
			virtual IVehicleGameObj ^AsVehicleGameObj();
			virtual ISmartGameObj ^AsSmartGameObj();
			virtual IScriptableGameObj ^AsScriptableGameObj();

			property IntPtr Pointer
			{
				IntPtr get() override;

				protected:
					void set(IntPtr value) override;
			}

			property IntPtr PostLoadableClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr PersistClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr BaseGameObjPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool IsPostLoadRegistered
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property IPersistFactoryClass ^Factory
			{
				virtual IPersistFactoryClass ^get() sealed;
			}

			property IBaseGameObjDef ^Definition
			{
				virtual IBaseGameObjDef ^get() sealed;
			}

			property bool IsHibernating
			{
				virtual bool get() sealed;
			}

			property int ID
			{
				virtual int get() sealed;
			}

			property bool IsPostThinkAllowed
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool EnableCinematicFreeze
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			property ::NetworkObjectClass *InternalNetworkObjectClassPointer
			{
				::NetworkObjectClass *get() override;
			}

			property ::PostLoadableClass *InternalPostLoadableClassPointer
			{
				virtual ::PostLoadableClass *get();
			}

			property ::PersistClass *InternalPersistClassPointer
			{
				virtual ::PersistClass *get();
			}

			property ::BaseGameObj *InternalBaseGameObjPointer
			{
				virtual ::BaseGameObj *get();
			}
	};
}