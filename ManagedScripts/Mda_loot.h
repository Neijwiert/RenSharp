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
#include "Mda_gameobj.h"
#include "Mda_event.h"
#include "Mda_gamefeature.h"
#include "Mengine_vector.h"

#pragma managed(push, off)

class DALootPlayerDataClass;
class DALootPowerUpClass;
class DALootBackpackClass;
class DALootDNAClass;
class DALootGameFeatureClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IWeaponClass;
	interface class IWeaponDefinitionClass;
	interface class IReferencerClass;
	interface class IPowerUpGameObjDef;

	public interface class IDALootPlayerDataClass : public IDAPlayerDataClass
	{
		void AddWeapon(IWeaponClass^ weapon);

		void AddWeapon(IWeaponDefinitionClass^ weapon);

		void RemoveWeapon(IWeaponClass^ weapon);

		void RemoveWeapon(IWeaponDefinitionClass^ weapon);

		bool HasWeapon(IWeaponClass^ weapon);

		bool HasWeapon(IWeaponDefinitionClass^ weapon);

		void ClearWeapons();

		property IntPtr DALootPlayerDataClassPointer
		{
			IntPtr get();
		}

		property int WeaponCount
		{
			int get();
		}

		property IDynamicVectorClass<IWeaponDefinitionClass^>^ Locker
		{
			IDynamicVectorClass<IWeaponDefinitionClass^>^ get();
			void set(IDynamicVectorClass<IWeaponDefinitionClass^>^ value);
		}
	};

	public ref class DALootPlayerDataClass : public DAPlayerDataClass, public IDALootPlayerDataClass
	{
		private:
			DALootPlayerDataClass();

		public:
			DALootPlayerDataClass(IntPtr pointer);

			static IUnmanagedContainer<IDALootPlayerDataClass^>^ CreateDALootPlayerDataClass();

			virtual void AddWeapon(IWeaponClass^ weapon) sealed;
			virtual void AddWeapon(IWeaponDefinitionClass^ weapon) sealed;
			virtual void RemoveWeapon(IWeaponClass^ weapon) sealed;
			virtual void RemoveWeapon(IWeaponDefinitionClass^ weapon) sealed;
			virtual bool HasWeapon(IWeaponClass^ weapon) sealed;
			virtual bool HasWeapon(IWeaponDefinitionClass^ weapon) sealed;
			virtual void ClearWeapons() sealed;

			property IntPtr DALootPlayerDataClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property int WeaponCount
			{
				virtual int get() sealed;
			}

			property IDynamicVectorClass<IWeaponDefinitionClass^>^ Locker
			{
				virtual IDynamicVectorClass<IWeaponDefinitionClass^>^ get() sealed;
				virtual void set(IDynamicVectorClass<IWeaponDefinitionClass^>^ value) sealed;
			}

		protected:
			property ::DAPlayerDataClass* InternalDAPlayerDataClassPointer
			{
				::DAPlayerDataClass* get() override;
			}

			property ::DALootPlayerDataClass* InternalDALootPlayerDataClassPointer
			{
				virtual ::DALootPlayerDataClass* get();
			}
	};

	public interface class IDALootPowerUpClass : public IDAGameObjObserverClass
	{
		void SetExpireTime(TimeSpan time);

		void InitDamagers(float range, TimeSpan expireTime);

		void InitDamagers(float range, TimeSpan expireTime, ISoldierGameObj^ soldier);

		void AddDamager(IcPlayer^ player);

		property IntPtr DALootPowerUpClassPointer
		{
			IntPtr get();
		}

		property IcPlayer^ Dropper
		{
			IcPlayer^ get();
		}
	};

	public ref class DALootPowerUpClass : public DAGameObjObserverClass, public IDALootPowerUpClass
	{
		protected:
			DALootPowerUpClass(bool create);
			DALootPowerUpClass(ISoldierGameObj^ soldier);

		public:
			DALootPowerUpClass(IntPtr pointer);

			static IUnmanagedContainer<IDALootPowerUpClass^>^ CreateDALootPowerUpClass();
			static IUnmanagedContainer<IDALootPowerUpClass^>^ CreateDALootPowerUpClass(ISoldierGameObj^ soldier);

			virtual void SetExpireTime(TimeSpan time) sealed;
			virtual void InitDamagers(float range, TimeSpan expireTime) sealed;
			virtual void InitDamagers(float range, TimeSpan expireTime, ISoldierGameObj^ soldier) sealed;
			virtual void AddDamager(IcPlayer^ player) sealed;

			property IntPtr DALootPowerUpClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IcPlayer^ Dropper
			{
				virtual IcPlayer^ get() sealed;

				protected:
					void set(IcPlayer^ value);
			}

		protected:
			void CreateIcon();
			void SetIcon(IWeaponDefinitionClass^ weapon);
			void DestroyIcon();

			property ::DAGameObjObserverClass* InternalDAGameObjObserverClassPointer
			{
				::DAGameObjObserverClass* get() override;
			}

			property ::DALootPowerUpClass* InternalDALootPowerUpClassPointer
			{
				virtual ::DALootPowerUpClass* get();
			}

			property IDynamicVectorClass<IcPlayer^>^ Damagers
			{
				IDynamicVectorClass<IcPlayer^>^ get();
				void set(IDynamicVectorClass<IcPlayer^>^ value);
			}

			property IReferencerClass^ Icon
			{
				IReferencerClass^ get();
				void set(IReferencerClass^ value);
			}
	};

	public interface class IDALootBackpackClass : public IDALootPowerUpClass
	{
		void AddWeapon(IWeaponDefinitionClass^ weapon, int rounds);

		property IntPtr DALootBackpackClassPointer
		{
			IntPtr get();
		}

		property int WeaponCount
		{
			int get();
		}
	};

	public ref class DALootBackpackClass : public DALootPowerUpClass, public IDALootBackpackClass
	{
		private:
			DALootBackpackClass();
			DALootBackpackClass(ISoldierGameObj^ soldier);

		public:
			DALootBackpackClass(IntPtr pointer);

			static IUnmanagedContainer<IDALootBackpackClass^>^ CreateDALootBackpackClass();
			static IUnmanagedContainer<IDALootBackpackClass^>^ CreateDALootBackpackClass(ISoldierGameObj^ soldier);

			virtual void AddWeapon(IWeaponDefinitionClass^ weapon, int rounds) sealed;

			property IntPtr DALootBackpackClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property int WeaponCount
			{
				virtual int get() sealed;
			}

		protected:
			property ::DALootPowerUpClass* InternalDALootPowerUpClassPointer
			{
				::DALootPowerUpClass* get() override;
			}

			property ::DALootBackpackClass* InternalDALootBackpackClassPointer
			{
				virtual ::DALootBackpackClass* get();
			}
	};

	public interface class IDALootDNAClass : public IDALootPowerUpClass
	{
		property IntPtr DALootDNAClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DALootDNAClass : public DALootPowerUpClass, public IDALootDNAClass
	{
		private:
			DALootDNAClass(ISoldierGameObjDef^ charDef);
			DALootDNAClass(ISoldierGameObj^ soldier);

		public:
			DALootDNAClass(IntPtr pointer);

			static IUnmanagedContainer<IDALootDNAClass^>^ CreateDALootDNAClass(ISoldierGameObjDef^ charDef);
			static IUnmanagedContainer<IDALootDNAClass^>^ CreateDALootDNAClass(ISoldierGameObj^ soldier);

			property IntPtr DALootDNAClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::DALootPowerUpClass* InternalDALootPowerUpClassPointer
			{
				::DALootPowerUpClass* get() override;
			}

			property ::DALootDNAClass* InternalDALootDNAClassPointer
			{
				virtual ::DALootDNAClass* get();
			}
	};

	public interface class IDALootGameFeatureClass : public IDAEventClass, public IDAGameFeatureClass, public IDAPlayerDataManagerClass<IDALootPlayerDataClass^>
	{
		IPowerUpGameObjDef^ GetCharacterPowerUpDrop(ISoldierGameObj^ soldier);

		IPowerUpGameObjDef^ GetCharacterPowerUpDrop(ISoldierGameObjDef^ soldier);

		IDALootPowerUpClass^ CreatePowerUp(ISoldierGameObj^ soldier);

		IDALootPowerUpClass^ CreatePowerUp(Vector3 position, ISoldierGameObjDef^ soldier);

		IWeaponDefinitionClass^ GetCharacterWeaponDrop(ISoldierGameObj^ soldier);

		IWeaponDefinitionClass^ GetCharacterWeaponDrop(ISoldierGameObjDef^ soldier);

		bool IsDroppable(IWeaponClass^ weapon);

		bool IsDroppable(IWeaponDefinitionClass^ weapon);

		IDALootBackpackClass^ CreateBackpack(ISoldierGameObj^ soldier);

		IDALootBackpackClass^ CreateBackpack(Vector3 position);

		IDALootDNAClass^ CreateDNA(ISoldierGameObj^ soldier);

		IDALootDNAClass^ CreateDNA(Vector3 position, ISoldierGameObjDef^ soldier);

		property IntPtr DALootGameFeatureClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DALootGameFeatureClass : public DAEventClass, public IDALootGameFeatureClass
	{
		private:
			DALootGameFeatureClass();

			IDAGameFeatureClass^ daGameFeatureClass;
			IDAPlayerDataFactoryClass^ daPlayerDataFactoryClass;

		public:
			DALootGameFeatureClass(IntPtr pointer);

			static IUnmanagedContainer<IDALootGameFeatureClass^>^ CreateDALootGameFeatureClass();

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual void Init() sealed;
			virtual IRenSharpGameFeatureClass^ AsManagedGameFeature() sealed;

			virtual IUnmanagedContainer<IDAPlayerDataClass^>^ CreateData() sealed;
			virtual IRenSharpPlayerDataFactoryClass^ AsManagedPlayerDataFactory() sealed;

			virtual IDALootPlayerDataClass^ GetPlayerData(int id) sealed;
			virtual IDALootPlayerDataClass^ GetPlayerData(IScriptableGameObj^ obj) sealed;
			virtual IDALootPlayerDataClass^ GetPlayerData(IcPlayer^ player) sealed;
			virtual IDALootPlayerDataClass^ GetPlayerData(IDAPlayerClass^ player) sealed;

			virtual IPowerUpGameObjDef^ GetCharacterPowerUpDrop(ISoldierGameObj^ soldier) sealed;
			virtual IPowerUpGameObjDef^ GetCharacterPowerUpDrop(ISoldierGameObjDef^ soldier) sealed;
			virtual IDALootPowerUpClass^ CreatePowerUp(ISoldierGameObj^ soldier) sealed;
			virtual IDALootPowerUpClass^ CreatePowerUp(Vector3 position, ISoldierGameObjDef^ soldier) sealed;
			virtual IWeaponDefinitionClass^ GetCharacterWeaponDrop(ISoldierGameObj^ soldier) sealed;
			virtual IWeaponDefinitionClass^ GetCharacterWeaponDrop(ISoldierGameObjDef^ soldier) sealed;
			virtual bool IsDroppable(IWeaponClass^ weapon) sealed;
			virtual bool IsDroppable(IWeaponDefinitionClass^ weapon) sealed;
			virtual IDALootBackpackClass^ CreateBackpack(ISoldierGameObj^ soldier) sealed;
			virtual IDALootBackpackClass^ CreateBackpack(Vector3 position) sealed;
			virtual IDALootDNAClass^ CreateDNA(ISoldierGameObj^ soldier) sealed;
			virtual IDALootDNAClass^ CreateDNA(Vector3 position, ISoldierGameObjDef^ soldier) sealed;

			static property IDALootGameFeatureClass^ Instance
			{
				IDALootGameFeatureClass^ get();
			}

			static property IDAGameFeatureRegistrant<IDALootGameFeatureClass^>^ Registrant
			{
				IDAGameFeatureRegistrant<IDALootGameFeatureClass^>^ get();
			}

			property IntPtr Pointer
			{
				IntPtr get() override;

				protected:
					void set(IntPtr value) override;
			}

			property IntPtr DALootGameFeatureClassPointer
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

			property ::DAPlayerDataManagerClass<::DALootPlayerDataClass>* InternalDAPlayerDataManagerClassPointer
			{
				virtual ::DAPlayerDataManagerClass<::DALootPlayerDataClass>* get();
			}

			property ::DALootGameFeatureClass* InternalDALootGameFeatureClassPointer
			{
				virtual ::DALootGameFeatureClass* get();
			}
	};

	public ref class DALootGameFeatureClassDAGameFeatureRegistrant : public DAGameFeatureRegistrant<IDALootGameFeatureClass^>
	{
		public:
			DALootGameFeatureClassDAGameFeatureRegistrant(IntPtr pointer);

			property IntPtr DALootGameFeatureClassDAGameFeatureRegistrantPointer
			{
				IntPtr get();
			}

		protected:
			property ::DAGameFeatureFactoryClass* InternalDAGameFeatureFactoryClassPointer
			{
				::DAGameFeatureFactoryClass* get() override;
			}

			property ::DAGameFeatureRegistrant<::DALootGameFeatureClass>* InternalDALootGameFeatureClassDAGameFeatureRegistrantPointer
			{
				virtual ::DAGameFeatureRegistrant<::DALootGameFeatureClass>* get();
			}
	};
}