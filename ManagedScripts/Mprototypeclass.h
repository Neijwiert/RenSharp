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

#include "AbstractUnmanagedObject.h"
#include "IUnmanagedContainer.h"

#pragma managed(push, off)

class PrototypeClass;
class PrototypeLoaderClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IRenderObjClass;
	interface class IChunkLoadClass;

	public interface class IPrototypeClass : public IUnmanagedObject
	{
		IUnmanagedContainer<IRenderObjClass ^> ^Create();

		property IntPtr PrototypeClassPointer
		{
			IntPtr get();
		}

		property IPrototypeClass ^NextHash
		{
			IPrototypeClass ^get();
			void set(IPrototypeClass ^value);
		}

		property String ^Name
		{
			String ^get();
		}

		property int ClassID
		{
			int get();
		}
	};

	public ref class PrototypeClass : public AbstractUnmanagedObject, public IPrototypeClass
	{
		protected:
			PrototypeClass();

		public:
			PrototypeClass(IntPtr pointer);

			String ^ToString() override;
			bool Equals(Object ^other) override;

			virtual IUnmanagedContainer<IRenderObjClass ^> ^Create() sealed;

			property IntPtr PrototypeClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IPrototypeClass ^NextHash
			{
				virtual IPrototypeClass ^get() sealed;
				virtual void set(IPrototypeClass ^value) sealed;
			}

			property String ^Name
			{
				virtual String ^get() sealed;
			}

			property int ClassID
			{
				virtual int get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::PrototypeClass *InternalPrototypeClassPointer
			{
				virtual ::PrototypeClass *get();
			}
	};

	public interface class IPrototypeLoaderClass : public IUnmanagedObject
	{
		IPrototypeClass ^LoadW3D(IChunkLoadClass ^cLoad);

		property IntPtr PrototypeLoaderClassPointer
		{
			IntPtr get();
		}

		property int ChunkType
		{
			int get();
		}
	};

	public ref class PrototypeLoaderClass : public AbstractUnmanagedObject, public IPrototypeLoaderClass
	{
		public:
			PrototypeLoaderClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual IPrototypeClass ^LoadW3D(IChunkLoadClass ^cLoad) sealed;

			property IntPtr PrototypeLoaderClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property int ChunkType
			{
				virtual int get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::PrototypeLoaderClass *InternalPrototypeLoaderClassPointer
			{
				virtual ::PrototypeLoaderClass *get();
			}
	};
}