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

#include "MStaticPhysClass.h"

#pragma managed(push, off)

class StaticAnimPhysClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IStaticAnimPhysDefClass;
	interface class IAnimCollisionManagerClass;
	interface class IProjectorManagerClass;

	public interface class IStaticAnimPhysClass : public IStaticPhysClass
	{
		property IntPtr StaticAnimPhysClassPointer
		{
			IntPtr get();
		}

		property IStaticAnimPhysDefClass ^StaticAnimPhysDef
		{
			IStaticAnimPhysDefClass ^get();
		}

		property IAnimCollisionManagerClass ^AnimationManager
		{
			IAnimCollisionManagerClass ^get();
		}
	};

	public ref class StaticAnimPhysClass : public StaticPhysClass, public IStaticAnimPhysClass
	{
		public:
			StaticAnimPhysClass(IntPtr pointer);

			IStaticAnimPhysClass ^AsStaticAnimPhysClass() override;

			property IntPtr StaticAnimPhysClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IStaticAnimPhysDefClass ^StaticAnimPhysDef
			{
				virtual IStaticAnimPhysDefClass ^get() sealed;
			}

			property IAnimCollisionManagerClass ^AnimationManager
			{
				virtual IAnimCollisionManagerClass ^get() sealed;
			}

		protected:
			property ::StaticPhysClass *InternalStaticPhysClassPointer
			{
				::StaticPhysClass *get() override;
			}

			property ::StaticAnimPhysClass *InternalStaticAnimPhysClassPointer
			{
				virtual ::StaticAnimPhysClass *get();
			}

			property IProjectorManagerClass ^ProjectorManager
			{
				IProjectorManagerClass ^get();
				void set(IProjectorManagerClass ^value);
			}

			property IntPtr ShadowProjector
			{
				IntPtr get();
				void set(IntPtr value);
			}
	};
}