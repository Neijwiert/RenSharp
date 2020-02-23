/*
Copyright 2020 Neijwiert

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

#include "AbstractUnmanagedObject.h"

#pragma managed(push, off)

class WeaponBagClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IWeaponClass;
	interface class IWeaponDefinitionClass;
	interface class IArmedGameObj;

	public interface class IWeaponBagClass : public IUnmanagedObject
	{
		IWeaponClass ^AddWeapon(IWeaponDefinitionClass ^def, int rounds, bool giveWeapon);

		IWeaponClass ^AddWeapon(IWeaponDefinitionClass ^def, int rounds);

		IWeaponClass ^AddWeapon(IWeaponDefinitionClass ^def);

		IWeaponClass ^AddWeapon(int id, int rounds, bool giveWeapon);

		IWeaponClass ^AddWeapon(int id, int rounds);

		IWeaponClass ^AddWeapon(int id);

		IWeaponClass ^AddWeapon(String ^weaponName, int rounds, bool giveWeapon);

		IWeaponClass ^AddWeapon(String ^weaponName, int rounds);

		IWeaponClass ^AddWeapon(String ^weaponName);

		void RemoveWeapon(int index);

		void RemoveWeapon(IWeaponDefinitionClass ^weaponDef);

		void RemoveWeapon(String ^weapon);

		void RemoveWeapon(unsigned int weaponDefId);

		void ClearWeapons();

		IWeaponClass ^PeekWeapon(int index);

		IWeaponClass ^GetWeapon();

		void SelectIndex(int index);

		void SelectNext();

		void SelectPrev();

		void SelectWeapon(IWeaponClass ^weapon);

		void SelectWeaponID(int weaponId);

		void SelectWeaponName(String ^name);

		void ForceChanged();

		void ResetChanged();

		void HUDResetChanged();

		IWeaponClass ^FindWeapon(IWeaponDefinitionClass ^weaponDef);

		IWeaponClass ^FindWeapon(String ^weapon);

		IWeaponClass ^FindWeapon(unsigned int weaponDefID);

		int GetWeaponPosition(IWeaponDefinitionClass ^weaponDef);

		int GetWeaponPosition(String ^weapon);

		int GetWeaponPosition(unsigned int weaponDefID);

		int GetWeaponPosition(IWeaponClass ^weapon);

		property IntPtr WeaponBagClassPointer
		{
			IntPtr get();
		}

		property int Count
		{
			int get();
		}

		property int Index
		{
			int get();
		}

		property bool IsChanged
		{
			bool get();
		}

		property bool HUDIsChanged
		{
			bool get();
		}

		property IArmedGameObj ^Owner
		{
			IArmedGameObj ^get();
		}

		property bool OwnerInitialized
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class WeaponBagClass : public AbstractUnmanagedObject, public IWeaponBagClass
	{
		public:
			WeaponBagClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual IWeaponClass ^AddWeapon(IWeaponDefinitionClass ^def, int rounds, bool giveWeapon) sealed;
			virtual IWeaponClass ^AddWeapon(IWeaponDefinitionClass ^def, int rounds) sealed;
			virtual IWeaponClass ^AddWeapon(IWeaponDefinitionClass ^def) sealed;
			virtual IWeaponClass ^AddWeapon(int id, int rounds, bool giveWeapon) sealed;
			virtual IWeaponClass ^AddWeapon(int id, int rounds) sealed;
			virtual IWeaponClass ^AddWeapon(int id) sealed;
			virtual IWeaponClass ^AddWeapon(String ^weaponName, int rounds, bool giveWeapon) sealed;
			virtual IWeaponClass ^AddWeapon(String ^weaponName, int rounds) sealed;
			virtual IWeaponClass ^AddWeapon(String ^weaponName) sealed;
			virtual void RemoveWeapon(int index) sealed;
			virtual void RemoveWeapon(IWeaponDefinitionClass ^weaponDef) sealed;
			virtual void RemoveWeapon(String ^weapon) sealed;
			virtual void RemoveWeapon(unsigned int weaponDefId) sealed;
			virtual void ClearWeapons() sealed;
			virtual IWeaponClass ^PeekWeapon(int index) sealed;
			virtual IWeaponClass ^GetWeapon() sealed;
			virtual void SelectIndex(int index) sealed;
			virtual void SelectNext() sealed;
			virtual void SelectPrev() sealed;
			virtual void SelectWeapon(IWeaponClass ^weapon) sealed;
			virtual void SelectWeaponID(int weaponId) sealed;
			virtual void SelectWeaponName(String ^name) sealed;
			virtual void ForceChanged() sealed;
			virtual void ResetChanged() sealed;
			virtual void HUDResetChanged() sealed;
			virtual IWeaponClass ^FindWeapon(IWeaponDefinitionClass ^weaponDef) sealed;
			virtual IWeaponClass ^FindWeapon(String ^weapon) sealed;
			virtual IWeaponClass ^FindWeapon(unsigned int weaponDefID) sealed;
			virtual int GetWeaponPosition(IWeaponDefinitionClass ^weaponDef) sealed;
			virtual int GetWeaponPosition(String ^weapon) sealed;
			virtual int GetWeaponPosition(unsigned int weaponDefID) sealed;
			virtual int GetWeaponPosition(IWeaponClass ^weapon) sealed;

			property IntPtr WeaponBagClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property int Count
			{
				virtual int get() sealed;
			}

			property int Index
			{
				virtual int get() sealed;
			}

			property bool IsChanged
			{
				virtual bool get() sealed;
			}

			property bool HUDIsChanged
			{
				virtual bool get() sealed;
			}

			property IArmedGameObj ^Owner
			{
				virtual IArmedGameObj ^get() sealed;
			}

			property bool OwnerInitialized
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			property ::WeaponBagClass *InternalWeaponBagClassPointer
			{
				virtual ::WeaponBagClass *get();
			}
	};
}