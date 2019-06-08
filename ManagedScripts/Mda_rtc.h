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

#include "Mda_player.h"
#include "Mda_event.h"
#include "Mda_gamefeature.h"

#pragma managed(push, off)

struct DARTCStruct;
class DARTCPlayerDataClass;
class DARTCGameFeatureClass;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IDARTCStruct : public IUnmanagedObject
	{
		property IntPtr DARTCStructPointer
		{
			IntPtr get();
		}

		property IcPlayer^ Player
		{
			IcPlayer^ get();
			void set(IcPlayer^ value);
		}

		property unsigned int Timeout
		{
			unsigned int get();
			void set(unsigned int value);
		}
	};

	public ref class DARTCStruct : public AbstractUnmanagedObject, public IDARTCStruct
	{
		private:
			DARTCStruct();
			DARTCStruct(IcPlayer^ player);

		public:
			DARTCStruct(IntPtr pointer);

			static IUnmanagedContainer<IDARTCStruct^>^ CreateDARTCStruct();
			static IUnmanagedContainer<IDARTCStruct^>^ CreateDARTCStruct(IcPlayer^ player);

			bool Equals(Object^ other) override;

			property IntPtr DARTCStructPointer
			{
				virtual IntPtr get() sealed;
			}

			property IcPlayer^ Player
			{
				virtual IcPlayer^ get() sealed;
				virtual void set(IcPlayer^ value) sealed;
			}

			property unsigned int Timeout
			{
				virtual unsigned int get() sealed;
				virtual void set(unsigned int value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DARTCStruct* InternalDARTCStructPointer
			{
				virtual ::DARTCStruct* get();
			}
	};

	public interface class IDARTCPlayerDataClass : public IDAPlayerDataClass
	{
		property IntPtr DARTCPlayerDataClassPointer
		{
			IntPtr get();
		}

		property bool CanRTC
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class DARTCPlayerDataClass : public DAPlayerDataClass, public IDARTCPlayerDataClass
	{
		private:
			DARTCPlayerDataClass();

		public:
			DARTCPlayerDataClass(IntPtr pointer);

			static IUnmanagedContainer<IDARTCPlayerDataClass^>^ CreateDARTCPlayerDataClass();

			property IntPtr DARTCPlayerDataClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool CanRTC
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			property ::DAPlayerDataClass* InternalDAPlayerDataClassPointer
			{
				::DAPlayerDataClass* get() override;
			}

			property ::DARTCPlayerDataClass* InternalDARTCPlayerDataClassPointer
			{
				virtual ::DARTCPlayerDataClass* get();
			}
	};

	public interface class IDARTCGameFeatureClass : public IDAEventClass, public IDAGameFeatureClass
	{
		property IntPtr DARTCGameFeatureClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DARTCGameFeatureClass : public DAEventClass, public IDARTCGameFeatureClass
	{
		private:
			IDAGameFeatureClass^ daGameFeatureClass;

		public:
			DARTCGameFeatureClass(IntPtr pointer);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual void Init() sealed;
			virtual IRenSharpGameFeatureClass^ AsManagedGameFeature() sealed;

			property IntPtr Pointer
			{
				IntPtr get() override;

				protected:
					void set(IntPtr value) override;
			}

			property IntPtr DARTCGameFeatureClassPointer
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

			property ::DARTCGameFeatureClass* InternalDARTCGameFeatureClassPointer
			{
				virtual ::DARTCGameFeatureClass* get();
			}
	};
}