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

#include "MPostLoadableClass.h"

#pragma managed(push, off)

class SaveLoadSubSystemClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IChunkSaveClass;
	interface class IChunkLoadClass;

	public interface class ISaveLoadSubSystemClass : public IPostLoadableClass
	{
		bool Save(IChunkSaveClass ^cSave);

		bool Load(IChunkLoadClass ^cLoad);

		property IntPtr SaveLoadSubSystemClassPointer
		{
			IntPtr get();
		}

		property ISaveLoadSubSystemClass ^NextSubSystem
		{
			ISaveLoadSubSystemClass ^get();
			void set(ISaveLoadSubSystemClass ^value);
		}

		property uint32 ChunkID
		{
			uint32 get();
		}

		property bool ContainsData
		{
			bool get();
		}

		property String ^Name
		{
			String ^get();
		}
	};

	public ref class SaveLoadSubSystemClass : public PostLoadableClass, public ISaveLoadSubSystemClass
	{
		public:
			SaveLoadSubSystemClass(IntPtr pointer);

			String ^ToString() override;

			virtual bool Save(IChunkSaveClass ^cSave) sealed;
			virtual bool Load(IChunkLoadClass ^cLoad) sealed;

			property IntPtr SaveLoadSubSystemClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property ISaveLoadSubSystemClass ^NextSubSystem
			{
				virtual ISaveLoadSubSystemClass ^get() sealed;
				virtual void set(ISaveLoadSubSystemClass ^value) sealed;
			}

			property uint32 ChunkID
			{
				virtual uint32 get() sealed;
			}

			property bool ContainsData
			{
				virtual bool get() sealed;
			}

			property String ^Name
			{
				virtual String ^get() sealed;
			}

		protected:
			property ::PostLoadableClass *InternalPostLoadableClassPointer
			{
				::PostLoadableClass *get() override;
			}

			property ::SaveLoadSubSystemClass *InternalSaveLoadSubSystemClassPointer
			{
				virtual ::SaveLoadSubSystemClass *get();
			}
	};
}