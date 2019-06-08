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

#include "AbstractUnmanagedObject.h"
#include "MVector3.h"

#pragma managed(push, off)

class DynamicShadowManagerClass;

#pragma managed(pop)

using namespace System::Runtime::InteropServices;

namespace RenSharp
{
	interface class IPhysClass;

	public interface class IDynamicShadowManagerClass : public IUnmanagedObject 
	{
		void SetShadowPlanes(float zNear, float zFar);

		void SetShadowPlanes(float zNear);

		void SetShadowPlanes();

		void GetShadowPlanes([Out] float %zNear, [Out] float %zFar);

		property IntPtr DynamicShadowManagerClassPointer
		{
			IntPtr get();
		}

		property bool ForceUseBlobBox
		{
			bool get();
			void set(bool value);
		}

		property Vector3 BlobBoxProjectionScale
		{
			Vector3 get();
			void set(Vector3 value);
		}

		property bool IsCastingShadow
		{
			bool get();
		}
	};

	public ref class DynamicShadowManagerClass : public AbstractUnmanagedObject, public IDynamicShadowManagerClass
	{
		public:
			DynamicShadowManagerClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual void SetShadowPlanes(float zNear, float zFar) sealed;
			virtual void SetShadowPlanes(float zNear) sealed;
			virtual void SetShadowPlanes() sealed;
			virtual void GetShadowPlanes([Out] float %zNear, [Out] float %zFar) sealed;

			property IntPtr DynamicShadowManagerClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool ForceUseBlobBox
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property Vector3 BlobBoxProjectionScale
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

			property bool IsCastingShadow
			{
				virtual bool get() sealed;
			}

		protected:
			property ::DynamicShadowManagerClass *InternalDynamicShadowManagerClassPointer
			{
				virtual ::DynamicShadowManagerClass *get();
			}

			property IPhysClass ^Parent
			{
				IPhysClass ^get();
			}

			property IntPtr Shadow
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property float ShadowNearZ
			{
				float get();
				void set(float value);
			}

			property float ShadowFarZ
			{
				float get();
				void set(float value);
			}
	};
}