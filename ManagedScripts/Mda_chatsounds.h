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

class DAChatSoundsPlayerDataClass;
class DAChatSoundsGameFeatureClass;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IDAChatSoundsPlayerDataClass : public IDAPlayerDataClass
	{
		property IntPtr DAChatSoundsPlayerDataClassPointer
		{
			IntPtr get();
		}

		property bool Enable
		{
			bool get();
			void set(bool value);
		}

		property bool Mute
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class DAChatSoundsPlayerDataClass : public DAPlayerDataClass, public IDAChatSoundsPlayerDataClass
	{
		private:
			DAChatSoundsPlayerDataClass();

		public:
			DAChatSoundsPlayerDataClass(IntPtr pointer);

			static IUnmanagedContainer<IDAChatSoundsPlayerDataClass^>^ CreateDAChatSoundsPlayerDataClass();

			property IntPtr DAChatSoundsPlayerDataClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool Enable
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool Mute
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			property ::DAPlayerDataClass* InternalDAPlayerDataClassPointer
			{
				::DAPlayerDataClass* get() override;
			}

			property ::DAChatSoundsPlayerDataClass* InternalDAChatSoundsPlayerDataClassPointer
			{
				virtual ::DAChatSoundsPlayerDataClass* get();
			}
	};

	public interface class IDAChatSoundsGameFeatureClass : public IDAEventClass, public IDAGameFeatureClass, public IDAPlayerDataManagerClass<IDAChatSoundsPlayerDataClass^>
	{
		property IntPtr DAChatSoundsGameFeatureClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DAChatSoundsGameFeatureClass : public DAEventClass, public IDAChatSoundsGameFeatureClass
	{
		private:
			IDAGameFeatureClass^ daGameFeatureClass;
			IDAPlayerDataFactoryClass^ daPlayerDataFactoryClass;

		public:
			DAChatSoundsGameFeatureClass(IntPtr pointer);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual void Init() sealed;
			virtual IRenSharpGameFeatureClass^ AsManagedGameFeature() sealed;

			virtual IUnmanagedContainer<IDAPlayerDataClass^>^ CreateData() sealed;
			virtual IRenSharpPlayerDataFactoryClass^ AsManagedPlayerDataFactory() sealed;

			virtual IDAChatSoundsPlayerDataClass^ GetPlayerData(int id) sealed;
			virtual IDAChatSoundsPlayerDataClass^ GetPlayerData(IScriptableGameObj^ obj) sealed;
			virtual IDAChatSoundsPlayerDataClass^ GetPlayerData(IcPlayer^ player) sealed;
			virtual IDAChatSoundsPlayerDataClass^ GetPlayerData(IDAPlayerClass^ player) sealed;

			property IntPtr Pointer
			{
				IntPtr get() override;

				protected:
					void set(IntPtr value) override;
			}

			property IntPtr DAChatSoundsGameFeatureClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr DAGameFeatureClassPointer
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

			property ::DAPlayerDataFactoryClass* InternalDAPlayerDataFactoryClassPointer
			{
				virtual ::DAPlayerDataFactoryClass* get();
			}

			property ::DAPlayerDataManagerClass<::DAChatSoundsPlayerDataClass>* InternalDAPlayerDataManagerClassPointer
			{
				virtual ::DAPlayerDataManagerClass<::DAChatSoundsPlayerDataClass>* get();
			}

			property ::DAChatSoundsGameFeatureClass* InternalDAChatSoundsGameFeatureClassPointer
			{
				virtual ::DAChatSoundsGameFeatureClass* get();
			}
	};
}