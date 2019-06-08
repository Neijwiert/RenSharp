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

class StaticPhysClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IStaticPhysDefClass;
	interface class IRenderObjClass;
	value class OBBoxClass;
	value class AABoxClass;
	interface class IChunkSaveClass;
	interface class IChunkLoadClass;

	public interface class IStaticPhysClass : public IPhysClass
	{
		bool Intersects(OBBoxClass box);

		void SaveState(IChunkSaveClass ^cSave);

		void LoadState(IChunkLoadClass ^cLoad);

		property IntPtr StaticPhysClassPointer
		{
			IntPtr get();
		}

		property IStaticPhysDefClass ^StaticPhysDef
		{
			IStaticPhysDefClass ^get();
		}

		property AABoxClass BoundingBox
		{
			AABoxClass get();
		}

		property int VisSectorID
		{
			int get();
		}

		property bool HasDynamicState
		{
			bool get();
		}
	};

	public ref class StaticPhysClass : public PhysClass, public IStaticPhysClass
	{
		public:
			StaticPhysClass(IntPtr pointer);

			IStaticPhysClass ^AsStaticPhysClass() override;
			virtual bool Intersects(OBBoxClass box) sealed;
			virtual void SaveState(IChunkSaveClass ^cSave) sealed;
			virtual void LoadState(IChunkLoadClass ^cLoad) sealed;

			property IntPtr StaticPhysClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IStaticPhysDefClass ^StaticPhysDef
			{
				virtual IStaticPhysDefClass ^get() sealed;
			}

			property AABoxClass BoundingBox
			{
				virtual AABoxClass get() sealed;
			}

			property int VisSectorID
			{
				virtual int get() sealed;

				protected:
					void set(int value);
			}

			property bool HasDynamicState
			{
				virtual bool get() sealed;
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

			property ::StaticPhysClass *InternalStaticPhysClassPointer
			{
				virtual ::StaticPhysClass *get();
			}
	};
}