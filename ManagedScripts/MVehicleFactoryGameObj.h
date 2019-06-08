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

#include "MBuildingGameObj.h"

#pragma managed(push, off)

class VehicleFactoryGameObj;

#pragma managed(pop)

namespace RenSharp
{
	interface class IVehicleFactoryGameObjDef;
	interface class ISoldierGameObj;
	value class Matrix3D;
	interface class IReferencerClass;
	value class OBBoxClass;

	public interface class IVehicleFactoryGameObj : public IBuildingGameObj
	{
		bool RequestVehicle(int definitionId, float generationTime, ISoldierGameObj ^player);

		bool RequestVehicle(int definitionId, float generationTime);

		property IntPtr VehicleFactoryGameObjPointer
		{
			IntPtr get();
		}

		property IVehicleFactoryGameObjDef ^Definition
		{
			IVehicleFactoryGameObjDef ^get();
		}

		property bool IsAvailable
		{
			bool get();
		}

		property bool IsBusy
		{
			bool get();
			void set(bool value);
		}

		property bool IsDisabled
		{
			bool get();
			void set(bool value);
		}

		property Matrix3D CreationTM
		{
			Matrix3D get();
			void set(Matrix3D value);
		}

		property int GeneratingVehicleID
		{
			int get();
		}

		property IReferencerClass ^Purchaser
		{
			IReferencerClass ^get();
		}
	};

	public ref class VehicleFactoryGameObj : public BuildingGameObj, public IVehicleFactoryGameObj
	{
		public:
			VehicleFactoryGameObj(IntPtr pointer);

			IVehicleFactoryGameObj ^AsVehicleFactoryGameObj() override;

			virtual bool RequestVehicle(int definitionId, float generationTime, ISoldierGameObj ^player) sealed;
			virtual bool RequestVehicle(int definitionId, float generationTime) sealed;

			property IntPtr VehicleFactoryGameObjPointer
			{
				virtual IntPtr get() sealed;
			}

#pragma push_macro("new")
#undef new

			property IVehicleFactoryGameObjDef ^Definition
			{
				virtual IVehicleFactoryGameObjDef ^get() new;
			}

#pragma pop_macro("new")

			property bool IsAvailable
			{
				virtual bool get() sealed;
			}

			property bool IsBusy
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsDisabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property Matrix3D CreationTM
			{
				virtual Matrix3D get() sealed;
				virtual void set(Matrix3D value) sealed;
			}

			property int GeneratingVehicleID
			{
				virtual int get() sealed;

				protected:
					void set(int value);
			}

			property IReferencerClass ^Purchaser
			{
				virtual IReferencerClass ^get() sealed;

				protected:
					void set(IReferencerClass ^value);
			}

		protected:
			void DestroyBlockingObjects();
			void BeginGeneration();
			void OnGenerationComplete();

			property ::BuildingGameObj *InternalBuildingGameObjPointer
			{
				::BuildingGameObj *get() override;
			}

			property ::VehicleFactoryGameObj *InternalVehicleFactoryGameObjPointer
			{
				virtual ::VehicleFactoryGameObj *get();
			}

			property IReferencerClass ^Vehicle
			{
				IReferencerClass ^get();
				void set(IReferencerClass ^value);
			}

			property OBBoxClass GeneratingRegion
			{
				OBBoxClass get();
				void set(OBBoxClass value);
			}

			property float GenerationTime
			{
				float get();
				void set(float value);
			}

			property int LastDeliveryPath
			{
				int get();
				void set(int value);
			}

			property int LastFlyingDeliveryPath
			{
				int get();
				void set(int value);
			}

			property float EndTimer
			{
				float get();
				void set(float value);
			}
	};
}