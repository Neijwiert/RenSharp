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

#include "MSmartGameObjDef.h"

#pragma managed(push, off)

class SoldierGameObjDef;

#pragma managed(pop)

namespace RenSharp
{
	interface class IDialogueClass;

	public interface class ISoldierGameObjDef : public ISmartGameObjDef
	{
		literal unsigned int SoldierGameObjDefClassID = 12289;

		property IntPtr SoldierGameObjDefPointer
		{
			IntPtr get();
		}

		property array<IDialogueClass ^> ^DialogList
		{
			array<IDialogueClass ^> ^get();
		}

		property float SkeletonHeight
		{
			float get();
		}

		property float SkeletonWidth
		{
			float get();
		}

		property bool IsSpy
		{
			bool get();
		}

		property bool CanRefill
		{
			bool get();
		}

		property bool IsUnsquishable
		{
			bool get();
		}

		property bool UseInnateBehavior
		{
			bool get();
		}

		property float InnateAggressiveness
		{
			float get();
		}

		property float InnateTakeCoverProbability
		{
			float get();
		}

		property bool InnateIsStationary
		{
			bool get();
		}
	};

	public ref class SoldierGameObjDef : public SmartGameObjDef, public ISoldierGameObjDef
	{
		public:
			SoldierGameObjDef(IntPtr pointer);

			property IntPtr SoldierGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

			property array<IDialogueClass ^> ^DialogList
			{
				virtual array<IDialogueClass ^> ^get() sealed;
			}

			property float SkeletonHeight
			{
				virtual float get() sealed;

				protected:
					void set(float value);
			}

			property float SkeletonWidth
			{
				virtual float get() sealed;

				protected:
					void set(float value);
			}

			property bool IsSpy
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

			property bool CanRefill
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

			property bool IsUnsquishable
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

			property bool UseInnateBehavior
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

			property float InnateAggressiveness
			{
				virtual float get() sealed;

				protected:
					void set(float value);
			}

			property float InnateTakeCoverProbability
			{
				virtual float get() sealed;

				protected:
					void set(float value);
			}

			property bool InnateIsStationary
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

		protected:
			property ::SmartGameObjDef *InternalSmartGameObjDefPointer
			{
				::SmartGameObjDef *get() override;
			}

			property ::SoldierGameObjDef *InternalSoldierGameObjDefPointer
			{
				virtual ::SoldierGameObjDef *get();
			}

			property float TurnRate
			{
				float get();
				void set(float value);
			}

			property float JumpVelocity
			{
				float get();
				void set(float value);
			}

			property String ^FirstPersonHands
			{
				String ^get();
				void set(String ^value);
			}

			property int HumanAnimOverrideDefID
			{
				int get();
				void set(int value);
			}

			property int HumanLoiterCollectionDefID
			{
				int get();
				void set(int value);
			}

			property int DeathSoundPresetID
			{
				int get();
				void set(int value);
			}

			property bool CanStealVehicles
			{
				bool get();
				void set(bool value);
			}

			property bool CanDriveVehicles
			{
				bool get();
				void set(bool value);
			}
	};
}