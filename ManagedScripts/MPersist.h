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

#include "MPostLoadableClass.h"

#pragma managed(push, off)

class PersistClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IPersistFactoryClass;
	interface class IChunkSaveClass;
	interface class IChunkLoadClass;

	public interface class IPersistClass : public IPostLoadableClass
	{
		bool Save(IChunkSaveClass ^csave);

		bool Load(IChunkLoadClass ^cload);

		property IntPtr PersistClassPointer
		{
			IntPtr get();
		}

		property IPersistFactoryClass ^Factory
		{
			IPersistFactoryClass ^get();
		}
	};

	public ref class PersistClass : public PostLoadableClass, public IPersistClass
	{
		public:
			PersistClass(IntPtr pointer);

			virtual bool Save(IChunkSaveClass ^csave) sealed;
			virtual bool Load(IChunkLoadClass ^cload) sealed;

			property IntPtr PersistClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IPersistFactoryClass ^Factory
			{
				virtual IPersistFactoryClass ^get() sealed;
			}

		protected:
			property ::PostLoadableClass *InternalPostLoadableClassPointer
			{
				::PostLoadableClass *get() override;
			}

			property ::PersistClass *InternalPersistClassPointer
			{
				virtual ::PersistClass *get();
			}
	};
}