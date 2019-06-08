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

class DAExtraRadioCommandsPlayerDataClass;
class DAExtraRadioCommandsGameFeatureClass;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IDAExtraRadioCommandsPlayerDataClass : public IDAPlayerDataClass
	{
		property IntPtr DAExtraRadioCommandsPlayerDataClassPointer
		{
			IntPtr get();
		}

		property IScriptableGameObj^ LastDamage
		{
			IScriptableGameObj^ get();
			void set(IScriptableGameObj^ value);
		}
	};

	public ref class DAExtraRadioCommandsPlayerDataClass : public DAPlayerDataClass, public IDAExtraRadioCommandsPlayerDataClass
	{
		private:
			DAExtraRadioCommandsPlayerDataClass();

		public:
			DAExtraRadioCommandsPlayerDataClass(IntPtr pointer);

			static IUnmanagedContainer<IDAExtraRadioCommandsPlayerDataClass^>^ CreateDAExtraRadioCommandsPlayerDataClass();

			property IntPtr DAExtraRadioCommandsPlayerDataClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IScriptableGameObj^ LastDamage
			{
				virtual IScriptableGameObj^ get() sealed;
				virtual void set(IScriptableGameObj^ value) sealed;
			}

		protected:
			property ::DAPlayerDataClass* InternalDAPlayerDataClassPointer
			{
				::DAPlayerDataClass* get() override;
			}

			property ::DAExtraRadioCommandsPlayerDataClass* InternalDAExtraRadioCommandsPlayerDataClassPointer
			{
				virtual ::DAExtraRadioCommandsPlayerDataClass* get();
			}
	};

	public interface class IDAExtraRadioCommandsGameFeatureClass : public IDAEventClass, public IDAGameFeatureClass, public IDAPlayerDataManagerClass<IDAExtraRadioCommandsPlayerDataClass^>
	{
		property IntPtr DAExtraRadioCommandsGameFeatureClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DAExtraRadioCommandsGameFeatureClass : public DAEventClass, public IDAExtraRadioCommandsGameFeatureClass
	{
		private:
			IDAGameFeatureClass^ daGameFeatureClass;
			IDAPlayerDataFactoryClass^ daPlayerDataFactoryClass;

		public:
			DAExtraRadioCommandsGameFeatureClass(IntPtr pointer);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual void Init() sealed;
			virtual IRenSharpGameFeatureClass^ AsManagedGameFeature() sealed;

			virtual IUnmanagedContainer<IDAPlayerDataClass^>^ CreateData() sealed;
			virtual IRenSharpPlayerDataFactoryClass^ AsManagedPlayerDataFactory() sealed;

			virtual IDAExtraRadioCommandsPlayerDataClass^ GetPlayerData(int id) sealed;
			virtual IDAExtraRadioCommandsPlayerDataClass^ GetPlayerData(IScriptableGameObj^ obj) sealed;
			virtual IDAExtraRadioCommandsPlayerDataClass^ GetPlayerData(IcPlayer^ player) sealed;
			virtual IDAExtraRadioCommandsPlayerDataClass^ GetPlayerData(IDAPlayerClass^ player) sealed;

			property IntPtr Pointer
			{
				IntPtr get() override;

				protected:
					void set(IntPtr value) override;
			}

			property IntPtr DAExtraRadioCommandsGameFeatureClassPointer
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

			property ::DAPlayerDataManagerClass<::DAExtraRadioCommandsPlayerDataClass>* InternalDAPlayerDataManagerClassPointer
			{
				virtual ::DAPlayerDataManagerClass<::DAExtraRadioCommandsPlayerDataClass>* get();
			}

			property ::DAExtraRadioCommandsGameFeatureClass* InternalDAExtraRadioCommandsGameFeatureClassPointer
			{
				virtual ::DAExtraRadioCommandsGameFeatureClass* get();
			}
	};
}