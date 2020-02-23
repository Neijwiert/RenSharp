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

#include "MPhysicalGameObj.h"

#pragma managed(push, off)

class ArmedGameObj;

#pragma managed(pop)

namespace RenSharp
{

#pragma warning(push)
#pragma warning(disable : 4099 4251 4244 26495 26454)

	interface class IArmedGameObjDef;
	interface class IWeaponClass;
	value class Matrix3D;
	value class Vector3;
	interface class IWeaponBagClass;

#pragma warning(pop) 

	public interface class IArmedGameObj : public IPhysicalGameObj
	{
		literal int MaxMuzzles = 4;

		void ImportStateCs(IntPtr packet);

		void ExportStateCs(IntPtr packet);

		Matrix3D GetMuzzle(int index);

		Matrix3D GetMuzzle();

		bool SetTargeting(Vector3 pos, bool doTilt);

		bool SetTargeting(Vector3 pos);

		bool IsRecoiling(int index);

		property IntPtr ArmedGameObjPointer
		{
			IntPtr get();
		}

		property IArmedGameObjDef ^Definition
		{
			IArmedGameObjDef ^get();
		}

		property IWeaponClass ^Weapon
		{
			IWeaponClass ^get();
		}

		property IWeaponBagClass ^WeaponBag
		{
			IWeaponBagClass ^get();
		}

		property float WeaponError
		{
			float get();
		}

		property Vector3 TargetingPos
		{
			Vector3 get();
		}
	};

	public ref class ArmedGameObj : public PhysicalGameObj, public IArmedGameObj
	{
		public:
			ArmedGameObj(IntPtr pointer);

			IArmedGameObj ^AsArmedGameObj() override;

			virtual void ImportStateCs(IntPtr packet) sealed;
			virtual void ExportStateCs(IntPtr packet) sealed;
			virtual Matrix3D GetMuzzle(int index) sealed;
			virtual Matrix3D GetMuzzle() sealed;
			virtual bool SetTargeting(Vector3 pos, bool doTilt) sealed;
			virtual bool SetTargeting(Vector3 pos) sealed;
			virtual bool IsRecoiling(int index) sealed;

			property IntPtr ArmedGameObjPointer
			{
				virtual IntPtr get() sealed;
			}

#pragma push_macro("new")
#undef new

			property IArmedGameObjDef ^Definition
			{
				virtual IArmedGameObjDef ^get() new sealed;
			}

#pragma pop_macro("new")

			property IWeaponClass ^Weapon
			{
				virtual IWeaponClass ^get() sealed;
			}

			property IWeaponBagClass ^WeaponBag
			{
				virtual IWeaponBagClass ^get() sealed;

				protected:
					void set(IWeaponBagClass ^value);
			}

			property float WeaponError
			{
				virtual float get() sealed;
			}

			property Vector3 TargetingPos
			{
				virtual Vector3 get() sealed;
			}

		protected:
			property ::PhysicalGameObj *InternalPhysicalGameObjPointer
			{
				::PhysicalGameObj *get() override;
			}

			property ::ArmedGameObj *InternalArmedGameObjPointer
			{
				virtual ::ArmedGameObj *get();
			}
	};
}