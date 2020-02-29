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

#include "MScriptableGameObjDef.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <ScriptZoneGameObjDef.h>
#pragma warning(pop) 
#pragma managed(pop)

using namespace System::Drawing;

namespace RenSharp
{

#pragma warning(push)
#pragma warning(disable : 4099 4251 4244 26495 26454)

	value class Vector3;

#pragma warning(pop)

	public enum class ZoneType : int
	{
		TypeDefault = ZoneConstants::TYPE_DEFAULT,
		TypeCTF = ZoneConstants::TYPE_CTF,
		TypeVehicleConstruction = ZoneConstants::TYPE_VEHICLE_CONSTRUCTION,
		TypeVehicleRepair = ZoneConstants::TYPE_VEHICLE_REPAIR,
		TypeTiberiumField = ZoneConstants::TYPE_TIBERIUM_FIELD,
		TypeBeacon = ZoneConstants::TYPE_BEACON,
		TypeGDITibField = ZoneConstants::TYPE_GDI_TIB_FIELD,
		TypeNodTibField = ZoneConstants::TYPE_NOD_TIB_FIELD,
		TypeNavalSpawn = ZoneConstants::TYPE_NAVAL_SPAWN
	};

	public interface class IScriptZoneGameObjDef : public IScriptableGameObjDef
	{
		literal unsigned int ScriptZoneGameObjDefClassID = 12302;

		property IntPtr ScriptZoneGameObjDefPointer
		{
			IntPtr get();
		}

		property ZoneType ZoneType
		{
			RenSharp::ZoneType get();
			void set(RenSharp::ZoneType value);
		}

		property Drawing::Color Color
		{
			Drawing::Color get();
			void set(Drawing::Color value);
		}

		property bool Unknown1
		{
			bool get();
			void set(bool value);
		}

		property bool CheckStarsOnly
		{
			bool get();
			void set(bool value);
		}

		property bool IsEnvironmentZone
		{
			bool get();
			void set(bool value);
		}

		property bool CheckC4
		{
			bool get();
			void set(bool value);
		}

		property int PresetID
		{
			int get();
			void set(int value);
		}

		property String ^ModelName
		{
			String ^get();
			void set(String ^value);
		}
	};

	public ref class ScriptZoneGameObjDef : public ScriptableGameObjDef, public IScriptZoneGameObjDef
	{
		public:
			ScriptZoneGameObjDef(IntPtr pointer);

			property IntPtr ScriptZoneGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

			property ZoneType ZoneType
			{
				virtual RenSharp::ZoneType get() sealed;
				virtual void set(RenSharp::ZoneType value) sealed;
			}

			property Drawing::Color Color
			{
				virtual Drawing::Color get() sealed;
				virtual void set(Drawing::Color value) sealed;
			}

			property bool Unknown1
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool CheckStarsOnly
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsEnvironmentZone
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool CheckC4
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property int PresetID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property String ^ModelName
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

		protected:
			property ::ScriptableGameObjDef *InternalScriptableGameObjDefPointer
			{
				::ScriptableGameObjDef *get() override;
			}

			property ::ScriptZoneGameObjDef *InternalScriptZoneGameObjDefPointer
			{
				virtual ::ScriptZoneGameObjDef *get();
			}
	};
}