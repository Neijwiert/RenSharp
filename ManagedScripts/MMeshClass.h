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

#include "MRenderObjClass.h"
#include "Mprototypeclass.h"
#include "IUnmanagedContainer.h"

#pragma managed(push, off)

class MeshClass;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IMeshClass : public IRenderObjClass
	{
		IntPtr PeekModel();

		property IntPtr MeshClassPointer
		{
			IntPtr get();
		}

		property IntPtr LightEnvironment
		{
			IntPtr get();
			void set(IntPtr value);
		}

		property IMeshClass ^NextVisibleSkin
		{
			IMeshClass ^get();
			void set(IMeshClass ^value);
		}

		property int BaseVertexOffset
		{
			int get();
			void set(int value);
		}

		property unsigned int MeshDebugId
		{
			unsigned int get();
		}

		property bool IsDisabledByDebugger
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class MeshClass : public RenderObjClass, public IMeshClass
	{
		public:
			MeshClass(IntPtr pointer);

			virtual IntPtr PeekModel() sealed;

			property IntPtr MeshClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr LightEnvironment
			{
				virtual IntPtr get() sealed;
				virtual void set(IntPtr value) sealed;
			}

			property IMeshClass ^NextVisibleSkin
			{
				virtual IMeshClass ^get() sealed;
				virtual void set(IMeshClass ^value) sealed;
			}

			property int BaseVertexOffset
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property unsigned int MeshDebugId
			{
				virtual unsigned int get() sealed;

				protected:
					void set(unsigned int value);
			}

			property bool IsDisabledByDebugger
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
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

			property ::RenderObjClass *InternalRenderObjClassPointer
			{
				::RenderObjClass *get() override;
			}

			property ::MeshClass *InternalMeshClassPointer
			{
				virtual ::MeshClass *get();
			}

			property IntPtr Model
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property IntPtr DecalMesh
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property IntPtr PolygonRendererList
			{
				IntPtr get();
			}
	};

	public interface class IPrimitivePrototypeClass : public IPrototypeClass
	{
		property IntPtr PrimitivePrototypeClassPointer
		{
			IntPtr get();
		}
	};

	public ref class PrimitivePrototypeClass : public PrototypeClass, public IPrimitivePrototypeClass
	{
		private:
			PrimitivePrototypeClass(IRenderObjClass ^proto);

		public:
			PrimitivePrototypeClass(IntPtr pointer);

			static IUnmanagedContainer<IPrimitivePrototypeClass ^> ^CreatePrimitivePrototypeClass(IRenderObjClass ^proto);

			property IntPtr PrimitivePrototypeClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::PrototypeClass *InternalPrototypeClassPointer
			{
				::PrototypeClass *get() override;
			}

			property ::PrimitivePrototypeClass *InternalPrimitivePrototypeClassPointer
			{
				virtual ::PrimitivePrototypeClass *get();
			}
	};

	public interface class IMeshLoaderClass : public IPrototypeLoaderClass
	{
		property IntPtr MeshLoaderClassPointer
		{
			IntPtr get();
		}
	};

	public ref class MeshLoaderClass : public PrototypeLoaderClass, public IMeshLoaderClass
	{
		public:
			MeshLoaderClass(IntPtr pointer);

			property IntPtr MeshLoaderClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::PrototypeLoaderClass *InternalPrototypeLoaderClassPointer
			{
				::PrototypeLoaderClass *get() override;
			}

			property ::MeshLoaderClass *InternalMeshLoaderClassPointer
			{
				virtual ::MeshLoaderClass *get();
			}
	};
}