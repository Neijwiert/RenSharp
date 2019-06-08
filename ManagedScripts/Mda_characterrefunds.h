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

class DACharacterRefundsPlayerDataClass;
class DACharacterRefundsGameFeatureClass;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IDACharacterRefundsPlayerDataClass : public IDAPlayerDataClass
	{
		property IntPtr DACharacterRefundsPlayerDataClassPointer
		{
			IntPtr get();
		}

		property float Cost
		{
			float get();
			void set(float value);
		}

		property ISoldierGameObjDef^ Def
		{
			ISoldierGameObjDef^ get();
			void set(ISoldierGameObjDef^ value);
		}
	};

	public ref class DACharacterRefundsPlayerDataClass : public DAPlayerDataClass, public IDACharacterRefundsPlayerDataClass
	{
		private:
			DACharacterRefundsPlayerDataClass();

		public:
			DACharacterRefundsPlayerDataClass(IntPtr pointer);

			static IUnmanagedContainer<IDACharacterRefundsPlayerDataClass^>^ CreateDACharacterRefundsPlayerDataClass();

			property IntPtr DACharacterRefundsPlayerDataClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property float Cost
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property ISoldierGameObjDef^ Def
			{
				virtual ISoldierGameObjDef^ get() sealed;
				virtual void set(ISoldierGameObjDef^ value) sealed;
			}

		protected:
			property ::DAPlayerDataClass* InternalDAPlayerDataClassPointer
			{
				::DAPlayerDataClass* get() override;
			}

			property ::DACharacterRefundsPlayerDataClass* InternalDACharacterRefundsPlayerDataClassPointer
			{
				virtual ::DACharacterRefundsPlayerDataClass* get();
			}
	};

	public interface class IDACharacterRefundsGameFeatureClass : public IDAEventClass, public IDAGameFeatureClass, public IDAPlayerDataManagerClass<IDACharacterRefundsPlayerDataClass^>
	{
		property IntPtr DACharacterRefundsGameFeatureClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DACharacterRefundsGameFeatureClass : public DAEventClass, public IDACharacterRefundsGameFeatureClass
	{
		private:
			IDAGameFeatureClass^ daGameFeatureClass;
			IDAPlayerDataFactoryClass^ daPlayerDataFactoryClass;

		public:
			DACharacterRefundsGameFeatureClass(IntPtr pointer);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual void Init() sealed;
			virtual IRenSharpGameFeatureClass^ AsManagedGameFeature() sealed;

			virtual IUnmanagedContainer<IDAPlayerDataClass^>^ CreateData() sealed;
			virtual IRenSharpPlayerDataFactoryClass^ AsManagedPlayerDataFactory() sealed;

			virtual IDACharacterRefundsPlayerDataClass^ GetPlayerData(int id) sealed;
			virtual IDACharacterRefundsPlayerDataClass^ GetPlayerData(IScriptableGameObj^ obj) sealed;
			virtual IDACharacterRefundsPlayerDataClass^ GetPlayerData(IcPlayer^ player) sealed;
			virtual IDACharacterRefundsPlayerDataClass^ GetPlayerData(IDAPlayerClass^ player) sealed;

			property IntPtr Pointer
			{
				IntPtr get() override;

				protected:
					void set(IntPtr value) override;
			}

			property IntPtr DACharacterRefundsGameFeatureClassPointer
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

			property ::DAPlayerDataManagerClass<::DACharacterRefundsPlayerDataClass>* InternalDAPlayerDataManagerClassPointer
			{
				virtual ::DAPlayerDataManagerClass<::DACharacterRefundsPlayerDataClass>* get();
			}

			property ::DACharacterRefundsGameFeatureClass* InternalDACharacterRefundsGameFeatureClassPointer
			{
				virtual ::DACharacterRefundsGameFeatureClass* get();
			}
	};
}