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

struct DAVehicleShellStruct;
class DAVehicleShellObserverClass;
class DAVehicleShellShadowObserverClass;
class DAVehicleShellsGameFeatureClass;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IDAVehicleShellStruct : public IUnmanagedObject
	{
		property IntPtr DAVehicleShellStructPointer
		{
			IntPtr get();
		}

		property IVehicleGameObjDef^ Def
		{
			IVehicleGameObjDef^ get();
			void set(IVehicleGameObjDef^ value);
		}

		property String^ Model
		{
			String^ get();
			void set(String^ value);
		}

		property String^ Explosion
		{
			String^ get();
			void set(String^ value);
		}

		property float ZOffset
		{
			float get();
			void set(float value);
		}
	};

	public ref class DAVehicleShellStruct : public AbstractUnmanagedObject, public IDAVehicleShellStruct
	{
		private:
			DAVehicleShellStruct();

		public:
			DAVehicleShellStruct(IntPtr pointer);

			static IUnmanagedContainer<IDAVehicleShellStruct^>^ CreateDAVehicleShellStruct();

			bool Equals(Object^ other) override;

			property IntPtr DAVehicleShellStructPointer
			{
				virtual IntPtr get() sealed;
			}

			property IVehicleGameObjDef^ Def
			{
				virtual IVehicleGameObjDef^ get() sealed;
				virtual void set(IVehicleGameObjDef^ value) sealed;
			}

			property String^ Model
			{
				virtual String^ get() sealed;
				virtual void set(String^ value) sealed;
			}

			property String^ Explosion
			{
				virtual String^ get() sealed;
				virtual void set(String^ value) sealed;
			}

			property float ZOffset
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DAVehicleShellStruct* InternalDAVehicleShellStructPointer
			{
				virtual ::DAVehicleShellStruct* get();
			}
	};

	public interface class IDAVehicleShellObserverClass : public IDAGameObjObserverClass
	{
		property IntPtr DAVehicleShellObserverClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DAVehicleShellObserverClass : public DAGameObjObserverClass, public IDAVehicleShellObserverClass
	{
		public:
			DAVehicleShellObserverClass(IntPtr pointer);

			property IntPtr DAVehicleShellObserverClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::DAGameObjObserverClass* InternalDAGameObjObserverClassPointer
			{
				::DAGameObjObserverClass* get() override;
			}

			property ::DAVehicleShellObserverClass* InternalDAVehicleShellObserverClassPointer
			{
				virtual ::DAVehicleShellObserverClass* get();
			}
	};

	public interface class IDAVehicleShellShadowObserverClass : public IDAGameObjObserverClass
	{
		property IntPtr DAVehicleShellShadowObserverClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DAVehicleShellShadowObserverClass : public DAGameObjObserverClass, public IDAVehicleShellShadowObserverClass
	{
		public:
			DAVehicleShellShadowObserverClass(IntPtr pointer);

			property IntPtr DAVehicleShellShadowObserverClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::DAGameObjObserverClass* InternalDAGameObjObserverClassPointer
			{
				::DAGameObjObserverClass* get() override;
			}

			property ::DAVehicleShellShadowObserverClass* InternalDAVehicleShellShadowObserverClassPointer
			{
				virtual ::DAVehicleShellShadowObserverClass* get();
			}
	};

	public interface class IDAVehicleShellsGameFeatureClass : public IDAEventClass, public IDAGameFeatureClass
	{
		IDAVehicleShellStruct^ GetShell(IVehicleGameObj^ vehicle);

		property IntPtr DAVehicleShellsGameFeatureClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DAVehicleShellsGameFeatureClass : public DAEventClass, public IDAVehicleShellsGameFeatureClass
	{
		private:
			IDAGameFeatureClass^ daGameFeatureClass;

		public:
			DAVehicleShellsGameFeatureClass(IntPtr pointer);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual void Init() sealed;
			virtual IRenSharpGameFeatureClass^ AsManagedGameFeature() sealed;

			virtual IDAVehicleShellStruct^ GetShell(IVehicleGameObj^ vehicle) sealed;

			property IntPtr Pointer
			{
				IntPtr get() override;

				protected:
					void set(IntPtr value) override;
			}

			property IntPtr DAVehicleShellsGameFeatureClassPointer
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

		protected:
			property ::DAEventClass* InternalDAEventClassPointer
			{
				::DAEventClass* get() override;
			}

			property ::DAGameFeatureClass* InternalDAGameFeatureClassPointer
			{
				virtual ::DAGameFeatureClass* get();
			}

			property ::DAVehicleShellsGameFeatureClass* InternalDAVehicleShellsGameFeatureClassPointer
			{
				virtual ::DAVehicleShellsGameFeatureClass* get();
			}
	};
}