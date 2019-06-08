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

#pragma managed(push, off)

class BoxRenderObjClass;
class OBBoxRenderObjClass;
class AABoxRenderObjClass;
class BoxLoaderClass;

#pragma managed(pop)

using namespace System::Drawing;

namespace RenSharp
{
	value class OBBoxClass;
	value class AABoxClass;

	public interface class IBoxRenderObjClass : public IRenderObjClass
	{
		void UpdateCachedBox();

		void SetOpacity(float opacity);

		void SetLocalCenterExtent(Vector3 center, Vector3 extent);

		property IntPtr BoxRenderObjClassPointer
		{
			IntPtr get();
		}

		property Vector3 ObjSpaceCenter
		{
			Vector3 get();
		}

		property Vector3 ObjSpaceExtent
		{
			Vector3 get();
		}
	};

	public ref class BoxRenderObjClass : public RenderObjClass, public IBoxRenderObjClass
	{
		public:
			BoxRenderObjClass(IntPtr pointer);

			virtual void UpdateCachedBox() sealed;
			virtual void SetOpacity(float opacity) sealed;
			virtual void SetLocalCenterExtent(Vector3 center, Vector3 extent) sealed;

			property IntPtr BoxRenderObjClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property Vector3 ObjSpaceCenter
			{
				virtual Vector3 get() sealed;

				protected:
					void set(Vector3 value);
			}

			property Vector3 ObjSpaceExtent
			{
				virtual Vector3 get() sealed;

				protected:
					void set(Vector3 value);
			}

		protected:
			property ::RenderObjClass *InternalRenderObjClassPointer
			{
				::RenderObjClass *get() override;
			}

			property ::BoxRenderObjClass *InternalBoxRenderObjClassPointer
			{
				virtual ::BoxRenderObjClass *get();
			}
			
			property Color Color
			{
				Drawing::Color get();
				void set(Drawing::Color value);
			}

			property float Opacity
			{
				float get();
				void set(float value);
			}
	};

	public interface class IOBBoxRenderObjClass : public IBoxRenderObjClass
	{
		property IntPtr OBBoxRenderObjClassPointer
		{
			IntPtr get();
		}

		property OBBoxClass CachedBox
		{
			OBBoxClass get();
			void set(OBBoxClass value);
		}

		property OBBoxClass Box
		{
			OBBoxClass get();
		}
	};

	public ref class OBBoxRenderObjClass : public BoxRenderObjClass, public IOBBoxRenderObjClass
	{
		public:
			OBBoxRenderObjClass(IntPtr pointer);

			property IntPtr OBBoxRenderObjClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property OBBoxClass CachedBox
			{
				virtual OBBoxClass get() sealed;
				virtual void set(OBBoxClass value) sealed;
			}

			property OBBoxClass Box
			{
				virtual OBBoxClass get() sealed;
			}

		protected:
			property ::BoxRenderObjClass *InternalBoxRenderObjClassPointer
			{
				::BoxRenderObjClass *get() override;
			}

			property ::OBBoxRenderObjClass *InternalOBBoxRenderObjClassPointer
			{
				virtual ::OBBoxRenderObjClass *get();
			}
	};

	public interface class IAABoxRenderObjClass : public IBoxRenderObjClass
	{
		property IntPtr AABoxRenderObjClassPointer
		{
			IntPtr get();
		}

		property AABoxClass CachedBox
		{
			AABoxClass get();
			void set(AABoxClass value);
		}

		property AABoxClass Box
		{
			AABoxClass get();
		}
	};

	public ref class AABoxRenderObjClass : public BoxRenderObjClass, public IAABoxRenderObjClass
	{
		public:
			AABoxRenderObjClass(IntPtr pointer);

			property IntPtr AABoxRenderObjClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property AABoxClass CachedBox
			{
				virtual AABoxClass get() sealed;
				virtual void set(AABoxClass value) sealed;
			}

			property AABoxClass Box
			{
				virtual AABoxClass get() sealed;
			}

		protected:
			property ::BoxRenderObjClass *InternalBoxRenderObjClassPointer
			{
				::BoxRenderObjClass *get() override;
			}

			property ::AABoxRenderObjClass *InternalAABoxRenderObjClassPointer
			{
				virtual ::AABoxRenderObjClass *get();
			}
	};

	public interface class IBoxLoaderClass : public IPrototypeLoaderClass
	{
		property IntPtr BoxLoaderClassPointer
		{
			IntPtr get();
		}
	};

	public ref class BoxLoaderClass : public PrototypeLoaderClass, public IBoxLoaderClass
	{
		public:
			BoxLoaderClass(IntPtr pointer);

			property IntPtr BoxLoaderClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::PrototypeLoaderClass *InternalPrototypeLoaderClassPointer
			{
				::PrototypeLoaderClass *get() override;
			}

			property ::BoxLoaderClass *InternalBoxLoaderClassPointer
			{
				virtual ::BoxLoaderClass *get();
			}
	};
}