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

#pragma managed(push, off)

class CullSystemClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class ICullableClass;
	value class Vector3;
	value class AABoxClass;
	value class OBBoxClass;
	value class FrustumClass;

	public interface class ICullSystemClass : public IUnmanagedObject
	{
		void CollectObjects(Vector3 point);

		void CollectObjects(AABoxClass box);

		void CollectObjects(OBBoxClass box);

		void CollectObjects(FrustumClass frustum);

		void UpdateCulling(ICullableClass ^obj);

		property IntPtr CullSystemClassPointer
		{
			IntPtr get();
		}
	};

	public ref class CullSystemClass : public AbstractUnmanagedObject, public ICullSystemClass
	{
		public:
			CullSystemClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual void CollectObjects(Vector3 point) sealed;
			virtual void CollectObjects(AABoxClass box) sealed;
			virtual void CollectObjects(OBBoxClass box) sealed;
			virtual void CollectObjects(FrustumClass frustum) sealed;
			virtual void UpdateCulling(ICullableClass ^obj) sealed;

			property IntPtr CullSystemClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::CullSystemClass *InternalCullSystemClassPointer
			{
				virtual ::CullSystemClass *get();
			}

			property ICullableClass ^CollectionHead
			{
				ICullableClass ^get();
				void set(ICullableClass ^value);
			}
	};
}