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

#include "MPhysClass.h"

#pragma managed(push, off)

class DynamicPhysClass;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IDynamicPhysClass : public IPhysClass
	{
		property IntPtr DynamicPhysClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DynamicPhysClass : public PhysClass, public IDynamicPhysClass
	{
		public:
			DynamicPhysClass(IntPtr pointer);

			IDynamicPhysClass ^AsDynamicPhysClass() override;

			property IntPtr DynamicPhysClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::PostLoadableClass *InternalPostLoadableClassPointer
			{
				::PostLoadableClass *get() override;
			}

			property ::PersistClass *InternalPersistClassPointer
			{
				::PersistClass *get() override;
			}

			property ::MultiListObjectClass *InternalMultiListObjectClassPointer
			{
				::MultiListObjectClass *get() override;
			}

			property ::PhysClass *InternalPhysClassPointer
			{
				::PhysClass *get() override;
			}

			property ::DynamicPhysClass *InternalDynamicPhysClassPointer
			{
				virtual ::DynamicPhysClass *get();
			}

			property bool DirtyVisObjectID
			{
				bool get();
				void set(bool value);
			}

			property int VisNodeID
			{
				int get();
				void set(int value);
			}

			property unsigned int VisStatusLastUpdated
			{
				unsigned int get();
				void set(unsigned int value);
			}
	};
}