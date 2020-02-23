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

#include "IUnmanagedObject.h"
#include "AbstractUnmanagedObject.h"

#pragma managed(push, off)

class PersistFactoryClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IPersistClass;
	interface class IChunkLoadClass;
	interface class IChunkSaveClass;

	public interface class IPersistFactoryClass : public IUnmanagedObject
	{
		IPersistClass ^Load(IChunkLoadClass ^xLoad);

		void Save(IChunkSaveClass ^xSave, IPersistClass ^object);

		property IntPtr PersistFactoryClassPointer
		{
			IntPtr get();
		}

		property IPersistFactoryClass ^NextFactory
		{
			IPersistFactoryClass ^get();
			void set(IPersistFactoryClass ^value);
		}

		property uint32 ChunkID
		{
			uint32 get();
		}
	};

	public ref class PersistFactoryClass : public AbstractUnmanagedObject, public IPersistFactoryClass
	{
		public:
			PersistFactoryClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual IPersistClass ^Load(IChunkLoadClass ^xLoad) sealed;
			virtual void Save(IChunkSaveClass ^xSave, IPersistClass ^object) sealed;

			property IntPtr PersistFactoryClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IPersistFactoryClass ^NextFactory
			{
				virtual IPersistFactoryClass ^get() sealed;
				virtual void set(IPersistFactoryClass ^value) sealed;
			}

			property uint32 ChunkID
			{
				virtual uint32 get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::PersistFactoryClass *InternalPersistFactoryClassPointer
			{
				virtual ::PersistFactoryClass *get();
			}
	};
}