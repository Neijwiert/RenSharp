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
#include "Mda_gamefeature.h"
#include "Mda_gameobj.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <da_vehicleownership.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	public enum class DAVehicleOwnershipState : int
	{
		Bound = ::DAVehicleOwnershipState::State::BOUND,
		Locked = ::DAVehicleOwnershipState::State::LOCKED,
		Selling = ::DAVehicleOwnershipState::State::SELLING,
		Free = ::DAVehicleOwnershipState::State::FREE
	};

	public interface class IDAVehicleOwnershipObserverClass : public IDAGameObjObserverClass
	{
		void CreateIcons();

		void DestroyIcons();

		void Lock();

		void Unlock();

		void Sell();

		void Free();

		void Unbind();

		property IntPtr DAVehicleOwnershipObserverClassPointer
		{
			IntPtr get();
		}

		property bool IsLocked
		{
			bool get();
		}

		property bool IsSelling
		{
			bool get();
		}

		property bool IsFree
		{
			bool get();
		}

		property IVehicleGameObj^ Vehicle
		{
			IVehicleGameObj^ get();
		}

		property IcPlayer^ VehicleOwner
		{
			IcPlayer^ get();
		}

		property int Team
		{
			int get();
		}
	};

	public ref class DAVehicleOwnershipObserverClass : public DAGameObjObserverClass, public IDAVehicleOwnershipObserverClass
	{
		private:
			DAVehicleOwnershipObserverClass(IVehicleGameObj^ vehicle, IcPlayer^ player);

		public:
			DAVehicleOwnershipObserverClass(IntPtr pointer);

			static IUnmanagedContainer<IDAVehicleOwnershipObserverClass^>^ CreateDAVehicleOwnershipObserverClass(IVehicleGameObj^ vehicle, IcPlayer^ player);

			virtual void CreateIcons() sealed;
			virtual void DestroyIcons() sealed;
			virtual void Lock() sealed;
			virtual void Unlock() sealed;
			virtual void Sell() sealed;
			virtual void Free() sealed;
			virtual void Unbind() sealed;

			property IntPtr DAVehicleOwnershipObserverClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool IsLocked
			{
				virtual bool get() sealed;
			}

			property bool IsSelling
			{
				virtual bool get() sealed;
			}

			property bool IsFree
			{
				virtual bool get() sealed;
			}

			property IVehicleGameObj^ Vehicle
			{
				virtual IVehicleGameObj^ get() sealed;
			}

			property IcPlayer^ VehicleOwner
			{
				virtual IcPlayer^ get() sealed;
			}

			property int Team
			{
				virtual int get() sealed;
			}

		protected:
			property ::DAGameObjObserverClass* InternalDAGameObjObserverClassPointer
			{
				::DAGameObjObserverClass* get() override;
			}

			property ::DAVehicleOwnershipObserverClass* InternalDAVehicleOwnershipObserverClassPointer
			{
				virtual ::DAVehicleOwnershipObserverClass* get();
			}
	};

	public interface class IDAVehicleOwnershipGameFeatureClass : public IDAEventClass, public IDAGameFeatureClass
	{
		IDAVehicleOwnershipObserverClass^ BindVehicle(IVehicleGameObj^ vehicle, IcPlayer^ player);

		bool UnbindVehicle(IVehicleGameObj^ vehicle);

		bool UnbindVehicle(IcPlayer^ player);

		bool LockVehicle(IVehicleGameObj^ vehicle);

		bool LockVehicle(IcPlayer^ player);

		bool UnlockVehicle(IVehicleGameObj^ vehicle);

		bool UnlockVehicle(IcPlayer^ player);

		IcPlayer^ GetVehicleOwner(IScriptableGameObj^ vehicle);

		IVehicleGameObj^ GetVehicle(IcPlayer^ player);

		IDAVehicleOwnershipObserverClass^ GetVehicleData(IScriptableGameObj^ vehicle);

		IDAVehicleOwnershipObserverClass^ GetVehicleData(IcPlayer^ player);

		IDAVehicleOwnershipObserverClass^ GetVehicleData(ISoldierGameObj^ soldier);

		property IntPtr DAVehicleOwnershipGameFeatureClassPointer
		{
			IntPtr get();
		}

		property float SellPercent
		{
			float get();
		}
	};

	public ref class DAVehicleOwnershipGameFeatureClass : public DAEventClass, public IDAVehicleOwnershipGameFeatureClass
	{
		private:
			IDAGameFeatureClass^ daGameFeatureClass;

		public:
			DAVehicleOwnershipGameFeatureClass(IntPtr pointer);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual void Init() sealed;
			virtual IRenSharpGameFeatureClass^ AsManagedGameFeature() sealed;

			virtual IDAVehicleOwnershipObserverClass^ BindVehicle(IVehicleGameObj^ vehicle, IcPlayer^ player) sealed;
			virtual bool UnbindVehicle(IVehicleGameObj^ vehicle) sealed;
			virtual bool UnbindVehicle(IcPlayer^ player) sealed;
			virtual bool LockVehicle(IVehicleGameObj^ vehicle) sealed;
			virtual bool LockVehicle(IcPlayer^ player) sealed;
			virtual bool UnlockVehicle(IVehicleGameObj^ vehicle) sealed;
			virtual bool UnlockVehicle(IcPlayer^ player) sealed;
			virtual IcPlayer^ GetVehicleOwner(IScriptableGameObj^ vehicle) sealed;
			virtual IVehicleGameObj^ GetVehicle(IcPlayer^ player) sealed;
			virtual IDAVehicleOwnershipObserverClass^ GetVehicleData(IScriptableGameObj^ vehicle) sealed;
			virtual IDAVehicleOwnershipObserverClass^ GetVehicleData(IcPlayer^ player) sealed;
			virtual IDAVehicleOwnershipObserverClass^ GetVehicleData(ISoldierGameObj^ soldier) sealed;

			static property IDAGameFeatureRegistrant<IDAVehicleOwnershipGameFeatureClass^>^ Registrant
			{
				IDAGameFeatureRegistrant<IDAVehicleOwnershipGameFeatureClass^>^ get();
			}

			static property IDAVehicleOwnershipGameFeatureClass^ Instance
			{
				IDAVehicleOwnershipGameFeatureClass^ get();
			}

			property IntPtr Pointer
			{
				IntPtr get() override;

				protected:
					void set(IntPtr value) override;
			}

			property IntPtr DAVehicleOwnershipGameFeatureClassPointer
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

			property float SellPercent
			{
				virtual float get() sealed;
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

			property ::DAVehicleOwnershipGameFeatureClass* InternalDAVehicleOwnershipGameFeatureClassPointer
			{
				virtual ::DAVehicleOwnershipGameFeatureClass* get();
			}
	};

	public ref class DAVehicleOwnershipGameFeatureClassDAGameFeatureRegistrant : public DAGameFeatureRegistrant<IDAVehicleOwnershipGameFeatureClass^>
	{
		public:
			DAVehicleOwnershipGameFeatureClassDAGameFeatureRegistrant(IntPtr pointer);

			property IntPtr DAVehicleOwnershipGameFeatureClassDAGameFeatureRegistrantPointer
			{
				IntPtr get();
			}

		protected:
			property ::DAGameFeatureFactoryClass* InternalDAGameFeatureFactoryClassPointer
			{
				::DAGameFeatureFactoryClass* get() override;
			}

			property ::DAGameFeatureRegistrant<::DAVehicleOwnershipGameFeatureClass>* InternalDAVehicleOwnershipGameFeatureClassDAGameFeatureRegistrantPointer
			{
				virtual ::DAGameFeatureRegistrant<::DAVehicleOwnershipGameFeatureClass>* get();
			}
	};
}