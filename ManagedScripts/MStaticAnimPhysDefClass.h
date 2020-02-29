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

#include "MStaticPhysDefClass.h"

#pragma managed(push, off)

class StaticAnimPhysDefClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IAnimCollisionManagerDefClass;
	interface class IProjectorManagerDefClass;

	public interface class IStaticAnimPhysDefClass : public IStaticPhysDefClass
	{
		literal unsigned int StaticAnimPhysDefClassClassID = 36872;
		literal String^ StaticAnimPhysDefClassTypeName = "StaticAnimPhysDef";

		property IntPtr StaticAnimPhysDefClassPointer
		{
			IntPtr get();
		}

		property bool ShadowDynamicObjs
		{
			bool get();
		}

		property bool ShadowIsAdditive
		{
			bool get();
		}

		property bool ShadowIgnoresZRotation
		{
			bool get();
		}

		property float ShadowNearZ
		{
			float get();
		}

		property float ShadowFarZ
		{
			float get();
		}

		property float ShadowIntensity
		{
			float get();
		}

		property bool DoesCollideInPathfind
		{
			bool get();
		}
	};

	public ref class StaticAnimPhysDefClass : public StaticPhysDefClass, public IStaticAnimPhysDefClass
	{
		public:
			StaticAnimPhysDefClass(IntPtr pointer);

			property IntPtr StaticAnimPhysDefClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool ShadowDynamicObjs
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

			property bool ShadowIsAdditive
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

			property bool ShadowIgnoresZRotation
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

			property float ShadowNearZ
			{
				virtual float get() sealed;

				protected:
					void set(float value);
			}

			property float ShadowFarZ
			{
				virtual float get() sealed;

				protected:
					void set(float value);
			}

			property float ShadowIntensity
			{
				virtual float get() sealed;

				protected:
					void set(float value);
			}

			property bool DoesCollideInPathfind
			{
				virtual bool get() sealed;

				protected:
					void set(bool value);
			}

		protected:
			property ::StaticPhysDefClass *InternalStaticPhysDefClassPointer
			{
				::StaticPhysDefClass *get() override;
			}

			property ::StaticAnimPhysDefClass *InternalStaticAnimPhysDefClassPointer
			{
				virtual ::StaticAnimPhysDefClass *get();
			}

			property bool IsCosmetic
			{
				bool get();
				void set(bool value);
			}

			property IAnimCollisionManagerDefClass ^AnimManagerDef
			{
				IAnimCollisionManagerDefClass ^get();
				void set(IAnimCollisionManagerDefClass ^value);
			}

			property IProjectorManagerDefClass ^ProjectorManagerDef
			{
				IProjectorManagerDefClass ^get();
				void set(IProjectorManagerDefClass ^value);
			}
	};
}