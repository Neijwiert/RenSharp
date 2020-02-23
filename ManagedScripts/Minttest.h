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
#include "MAABoxClass.h"
#include "Mobboxclass.h"
#include "Mcoltype.h"

#pragma managed(push, off)

class IntersectionTestClass;
class AABoxIntersectionTestClass;
class OBBoxIntersectionTestClass;

#pragma managed(pop)

namespace RenSharp
{
	ref class IntersectionTestClass;
	ref class AABoxIntersectionTestClass;
	value class Vector3;
	ref class OBBoxIntersectionTestClass;
	value class Matrix3D;

	public interface class IIntersectionTestClass : public IUnmanagedObject
	{
		IntersectionTestClass ^ToIntersectionTestClass();

		property IntPtr IntersectionTestClassPointer
		{
			IntPtr get();
		}

		property RenSharp::CollisionType CollisionType
		{
			RenSharp::CollisionType get();
			void set(RenSharp::CollisionType value);
		}
	};

	public ref class IntersectionTestClassRef : public AbstractUnmanagedObject, public IIntersectionTestClass
	{
		private:
			IntersectionTestClassRef(RenSharp::CollisionType collisionType);
			IntersectionTestClassRef(IntersectionTestClass ^intersectionTestClass);

		protected:
			IntersectionTestClassRef();

		public:
			IntersectionTestClassRef(IntPtr pointer);

			static IUnmanagedContainer<IIntersectionTestClass ^> ^CreateIntersectionTestClassRef(RenSharp::CollisionType collisionType);
			static IUnmanagedContainer<IIntersectionTestClass ^> ^CreateIntersectionTestClassRef(IntersectionTestClass ^intersectionTestClass);

			bool Equals(Object ^other) override;
			virtual IntersectionTestClass ^ToIntersectionTestClass();

			property IntPtr IntersectionTestClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property RenSharp::CollisionType CollisionType
			{
				virtual RenSharp::CollisionType get() sealed;
				virtual void set(RenSharp::CollisionType value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::IntersectionTestClass *InternalIntersectionTestClassPointer
			{
				virtual ::IntersectionTestClass *get();
			}
	};

	public ref class IntersectionTestClass
	{
		private:
			RenSharp::CollisionType collisionType;

		public:
			IntersectionTestClass(RenSharp::CollisionType collisionType);
			IntersectionTestClass(IIntersectionTestClass ^intersectionTestClass);
			IntersectionTestClass(IntersectionTestClass ^intersectionTestClass);

			void CopyFrom(IIntersectionTestClass ^intersectionTestClass);
			void CopyFrom(IntersectionTestClass ^intersectionTestClass);

			property RenSharp::CollisionType CollisionType
			{
				RenSharp::CollisionType get();
				void set(RenSharp::CollisionType value);
			}
	};

	public interface class IAABoxIntersectionTestClass : public IIntersectionTestClass
	{
		AABoxIntersectionTestClass ^ToAABoxIntersectionTestClass();

		bool Cull(Vector3 cullMin, Vector3 cullMax);

		bool Cull(AABoxClass cullBox);

		property IntPtr AABoxIntersectionTestClassPointer
		{
			IntPtr get();
		}

		property AABoxClass Box
		{
			AABoxClass get();
			void set(AABoxClass value);
		}
	};

	public ref class AABoxIntersectionTestClassRef : public IntersectionTestClassRef, public IAABoxIntersectionTestClass
	{
		private:
			AABoxIntersectionTestClassRef(AABoxClass box, RenSharp::CollisionType collisionType);
			AABoxIntersectionTestClassRef(AABoxIntersectionTestClass ^intersectionTestClass);

		protected:
			AABoxIntersectionTestClassRef();

		public:
			AABoxIntersectionTestClassRef(IntPtr pointer);

			static IUnmanagedContainer<IAABoxIntersectionTestClass ^> ^CreateAABoxIntersectionTestClassRef(AABoxClass box, RenSharp::CollisionType collisionType);
			static IUnmanagedContainer<IAABoxIntersectionTestClass ^> ^CreateAABoxIntersectionTestClassRef(AABoxIntersectionTestClass ^intersectionTestClass);

			IntersectionTestClass ^ToIntersectionTestClass() override;
			virtual AABoxIntersectionTestClass ^ToAABoxIntersectionTestClass();
			virtual bool Cull(Vector3 cullMin, Vector3 cullMax) sealed;
			virtual bool Cull(AABoxClass cullBox) sealed;

			property IntPtr AABoxIntersectionTestClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property AABoxClass Box
			{
				virtual AABoxClass get() sealed;
				virtual void set(AABoxClass value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::IntersectionTestClass *InternalIntersectionTestClassPointer
			{
				::IntersectionTestClass *get() override;
			}

			property ::AABoxIntersectionTestClass *InternalAABoxIntersectionTestClassPointer
			{
				virtual ::AABoxIntersectionTestClass *get();
			}
	};

	public ref class AABoxIntersectionTestClass : public IntersectionTestClass
	{
		private:
			AABoxClass box;

		public:
			AABoxIntersectionTestClass(AABoxClass box, RenSharp::CollisionType collisionType);
			AABoxIntersectionTestClass(IAABoxIntersectionTestClass ^intersectionTestClass);
			AABoxIntersectionTestClass(AABoxIntersectionTestClass ^intersectionTestClass);

			void CopyFrom(IAABoxIntersectionTestClass ^intersectionTestClass);
			void CopyFrom(AABoxIntersectionTestClass ^intersectionTestClass);

			bool Cull(Vector3 cullMin, Vector3 cullMax);
			bool Cull(AABoxClass cullBox);

			property AABoxClass Box
			{
				AABoxClass get();
				void set(AABoxClass value);
			}
	};

	public interface class IOBBoxIntersectionTestClass : public IIntersectionTestClass
	{
		OBBoxIntersectionTestClass ^ToOBBoxIntersectionTestClass();

		bool Cull(Vector3 cullMin, Vector3 cullMax);

		bool Cull(AABoxClass cullBox);

		property IntPtr OBBoxIntersectionTestClassPointer
		{
			IntPtr get();
		}

		property OBBoxClass Box
		{
			OBBoxClass get();
			void set(OBBoxClass value);
		}

		property AABoxClass BoundingBox
		{
			AABoxClass get();
			void set(AABoxClass value);
		}
	};

	public ref class OBBoxIntersectionTestClassRef : public IntersectionTestClassRef, public IOBBoxIntersectionTestClass
	{
		private:
			OBBoxIntersectionTestClassRef(OBBoxClass box, RenSharp::CollisionType collisionType);
			OBBoxIntersectionTestClassRef(IOBBoxIntersectionTestClass ^that, Matrix3D tm);
			OBBoxIntersectionTestClassRef(IAABoxIntersectionTestClass ^that, Matrix3D tm);
			OBBoxIntersectionTestClassRef(OBBoxIntersectionTestClass ^intersectionTestClass);

		protected:
			OBBoxIntersectionTestClassRef();

		public:
			OBBoxIntersectionTestClassRef(IntPtr pointer);

			static IUnmanagedContainer<IOBBoxIntersectionTestClass ^> ^CreateOBBoxIntersectionTestClassRef(OBBoxClass box, RenSharp::CollisionType collisionType);
			static IUnmanagedContainer<IOBBoxIntersectionTestClass ^> ^CreateOBBoxIntersectionTestClassRef(IOBBoxIntersectionTestClass ^that, Matrix3D tm);
			static IUnmanagedContainer<IOBBoxIntersectionTestClass ^> ^CreateOBBoxIntersectionTestClassRef(IAABoxIntersectionTestClass ^that, Matrix3D tm);
			static IUnmanagedContainer<IOBBoxIntersectionTestClass ^> ^CreateOBBoxIntersectionTestClassRef(OBBoxIntersectionTestClass ^intersectionTestClass);

			IntersectionTestClass ^ToIntersectionTestClass() override;
			virtual OBBoxIntersectionTestClass ^ToOBBoxIntersectionTestClass();
			virtual bool Cull(Vector3 cullMin, Vector3 cullMax) sealed;
			virtual bool Cull(AABoxClass cullBox) sealed;

			property IntPtr OBBoxIntersectionTestClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property OBBoxClass Box
			{
				virtual OBBoxClass get() sealed;
				virtual void set(OBBoxClass value) sealed;
			}

			property AABoxClass BoundingBox
			{
				virtual AABoxClass get() sealed;
				virtual void set(AABoxClass value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			void UpdateBoundingBox();

			property ::IntersectionTestClass *InternalIntersectionTestClassPointer
			{
				::IntersectionTestClass *get() override;
			}

			property ::OBBoxIntersectionTestClass *InternalOBBoxIntersectionTestClassPointer
			{
				virtual ::OBBoxIntersectionTestClass *get();
			}
	};

	public ref class OBBoxIntersectionTestClass : public IntersectionTestClass
	{
		private:
			OBBoxClass box;
			AABoxClass boundingBox;

		public:
			OBBoxIntersectionTestClass(OBBoxClass box, RenSharp::CollisionType collisionType);
			OBBoxIntersectionTestClass(IOBBoxIntersectionTestClass ^that, Matrix3D tm);
			OBBoxIntersectionTestClass(OBBoxIntersectionTestClass ^that, Matrix3D tm);
			OBBoxIntersectionTestClass(IAABoxIntersectionTestClass ^that, Matrix3D tm);
			OBBoxIntersectionTestClass(AABoxIntersectionTestClass ^that, Matrix3D tm);
			OBBoxIntersectionTestClass(IOBBoxIntersectionTestClass ^intersectionTestClass);
			OBBoxIntersectionTestClass(OBBoxIntersectionTestClass ^intersectionTestClass);

			void CopyFrom(IOBBoxIntersectionTestClass ^intersectionTestClass);
			void CopyFrom(OBBoxIntersectionTestClass ^intersectionTestClass);

			bool Cull(Vector3 cullMin, Vector3 cullMax);
			bool Cull(AABoxClass cullBox);

			property OBBoxClass Box
			{
				OBBoxClass get();
				void set(OBBoxClass value);
			}

			property AABoxClass BoundingBox
			{
				AABoxClass get();
				void set(AABoxClass value);
			}

		protected:
			void UpdateBoundingBox();
	};
}