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

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <coltest.h>

class RenSharpCollisionTestClass;
class RenSharpRayCollisionTestClass;
class RenSharpAABoxCollisionTestClass;
class RenSharpOBBoxCollisionTestClass;

#pragma warning(pop) 
#pragma managed(pop)

#include "Mcoltype.h"
#include "MCastResultStruct.h"
#include "AbstractUnmanagedObject.h"
#include "IUnmanagedContainer.h"
#include "MLineSegClass.h"
#include "MAABoxClass.h"
#include "Mobboxclass.h"

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Runtime::CompilerServices;

namespace RenSharp
{
	interface class IRenderObjClass;
	ref class CollisionTestClass;
	ref class RayCollisionTestClass;
	value class Matrix3D;
	ref class AABoxCollisionTestClass;
	ref class OBBoxCollisionTestClass;

	public interface class ICollisionTestClass : public IUnmanagedObject
	{
		CollisionTestClass ^ToCollisionTestClass();

		property IntPtr CollisionTestClassPointer
		{
			IntPtr get();
		}

		property Nullable<CastResultStruct> Result
		{
			Nullable<CastResultStruct> get();
		}

		property CollisionType CollisionType
		{
			RenSharp::CollisionType get();
			void set(RenSharp::CollisionType value);
		}

		property IRenderObjClass ^CollidedRenderObj
		{
			IRenderObjClass ^get();
			void set(IRenderObjClass ^value);
		}
	};

	public ref class CollisionTestClassRef : public AbstractUnmanagedObject, public ICollisionTestClass
	{
		private:
			CollisionTestClassRef(CollisionType collisionType);

		protected:
			CollisionTestClassRef();

		public:
			CollisionTestClassRef(IntPtr pointer);

			static IUnmanagedContainer<ICollisionTestClass ^> ^CreateCollisionTestClassRef(CollisionType collisionType);

			bool Equals(Object ^other) override;

			virtual CollisionTestClass ^ToCollisionTestClass();

			property IntPtr CollisionTestClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property Nullable<CastResultStruct> Result
			{
				virtual Nullable<CastResultStruct> get();
			}

			property CollisionType CollisionType
			{
				virtual RenSharp::CollisionType get() sealed;
				virtual void set(RenSharp::CollisionType value) sealed;
			}

			property IRenderObjClass ^CollidedRenderObj
			{
				virtual IRenderObjClass ^get() sealed;
				virtual void set(IRenderObjClass ^value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::CollisionTestClass *InternalCollisionTestClassPointer
			{
				virtual ::CollisionTestClass *get();
			}
	};

	public ref class RenSharpCollisionTestClass : public CollisionTestClassRef
	{
		private:
			RenSharpCollisionTestClass(Nullable<CastResultStruct> res, RenSharp::CollisionType collisionType);
			RenSharpCollisionTestClass(CollisionTestClass ^colTest);

		public:
			RenSharpCollisionTestClass(IntPtr pointer);

			static IUnmanagedContainer<ICollisionTestClass ^> ^CreateRenSharpCollisionTestClass(Nullable<CastResultStruct> res, RenSharp::CollisionType collisionType);
			static IUnmanagedContainer<ICollisionTestClass ^> ^CreateRenSharpCollisionTestClass(CollisionTestClass ^colTest);

			property IntPtr RenSharpCollisionTestClassPointer
			{
				IntPtr get();
			}

			property Nullable<CastResultStruct> Result
			{
				Nullable<CastResultStruct> get() override;
				void set(Nullable<CastResultStruct> value);
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::RenSharpCollisionTestClass *InternalRenSharpCollisionTestClassPointer
			{
				virtual ::RenSharpCollisionTestClass *get();
			}
	};

	public ref class CollisionTestClass
	{
		private:
			CastResultStruct result;
			CollisionType collisionType;
			IRenderObjClass ^collidedRenderObj;

		public:
			CollisionTestClass(CastResultStruct result, CollisionType collisionType);
			CollisionTestClass(CollisionType collisionType);
			CollisionTestClass(ICollisionTestClass ^colTest);
			CollisionTestClass(CollisionTestClass ^colTest);

			void CopyFrom(ICollisionTestClass ^colTest);
			void CopyFrom(CollisionTestClass ^colTest);

			property CastResultStruct Result
			{
				CastResultStruct get();
				void set(CastResultStruct value);
			}

			property CollisionType CollisionType
			{
				RenSharp::CollisionType get();
				void set(RenSharp::CollisionType value);
			}

			property IRenderObjClass ^CollidedRenderObj
			{
				IRenderObjClass ^get();
				void set(IRenderObjClass ^value);
			}
	};

	public interface class IRayCollisionTestClass : public ICollisionTestClass
	{
		RayCollisionTestClass ^ToRayCollisionTestClass();

		property IntPtr RayCollisionTestClassPointer
		{
			IntPtr get();
		}

		property LineSegClass Ray
		{
			LineSegClass get();
			void set(LineSegClass value);
		}

		property bool IgnoreTranslucentMeshes
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class RayCollisionTestClassRef : public CollisionTestClassRef, public IRayCollisionTestClass
	{
		private:
			RayCollisionTestClassRef(LineSegClass ray, RenSharp::CollisionType collisionType, bool ignoreTranslucentMeshes);
			RayCollisionTestClassRef(LineSegClass ray, RenSharp::CollisionType collisionType);
			RayCollisionTestClassRef(LineSegClass ray);
			RayCollisionTestClassRef(IRayCollisionTestClass ^rayTest, Matrix3D tm);

		protected:
			RayCollisionTestClassRef();

		public:
			RayCollisionTestClassRef(IntPtr pointer);

			static IUnmanagedContainer<IRayCollisionTestClass ^> ^CreateRayCollisionTestClassRef(LineSegClass ray, RenSharp::CollisionType collisionType, bool ignoreTranslucentMeshes);
			static IUnmanagedContainer<IRayCollisionTestClass ^> ^CreateRayCollisionTestClassRef(LineSegClass ray, RenSharp::CollisionType collisionType);
			static IUnmanagedContainer<IRayCollisionTestClass ^> ^CreateRayCollisionTestClassRef(LineSegClass ray);
			static IUnmanagedContainer<IRayCollisionTestClass ^> ^CreateRayCollisionTestClassRef(IRayCollisionTestClass ^rayTest, Matrix3D tm);

			CollisionTestClass ^ToCollisionTestClass() override;
			virtual RayCollisionTestClass ^ToRayCollisionTestClass();

			property IntPtr RayCollisionTestClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property LineSegClass Ray
			{
				virtual LineSegClass get() sealed;
				virtual void set(LineSegClass value) sealed;
			}

			property bool IgnoreTranslucentMeshes
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::CollisionTestClass *InternalCollisionTestClassPointer
			{
				::CollisionTestClass *get() override;
			}

			property ::RayCollisionTestClass *InternalRayCollisionTestClassPointer
			{
				virtual ::RayCollisionTestClass *get();
			}
	};

	public ref class RenSharpRayCollisionTestClass : public RayCollisionTestClassRef
	{
		private:
			RenSharpRayCollisionTestClass(LineSegClass ray, RenSharp::CollisionType collisionType, bool ignoreTranslucentMeshes);
			RenSharpRayCollisionTestClass(LineSegClass ray, RenSharp::CollisionType collisionType);
			RenSharpRayCollisionTestClass(LineSegClass ray);
			RenSharpRayCollisionTestClass(LineSegClass ray, Nullable<CastResultStruct> res, RenSharp::CollisionType collisionType, bool ignoreTranslucentMeshes);
			RenSharpRayCollisionTestClass(LineSegClass ray, Nullable<CastResultStruct> res, RenSharp::CollisionType collisionType);
			RenSharpRayCollisionTestClass(LineSegClass ray, Nullable<CastResultStruct> res);
			RenSharpRayCollisionTestClass(IRayCollisionTestClass ^rayTest, Matrix3D tm);
			RenSharpRayCollisionTestClass(RayCollisionTestClass ^rayTest, Matrix3D tm);
			RenSharpRayCollisionTestClass(RayCollisionTestClass ^rayTest);

		public:
			RenSharpRayCollisionTestClass(IntPtr pointer);

			static IUnmanagedContainer<IRayCollisionTestClass ^> ^CreateRenSharpRayCollisionTestClass(LineSegClass ray, RenSharp::CollisionType collisionType, bool ignoreTranslucentMeshes);
			static IUnmanagedContainer<IRayCollisionTestClass ^> ^CreateRenSharpRayCollisionTestClass(LineSegClass ray, RenSharp::CollisionType collisionType);
			static IUnmanagedContainer<IRayCollisionTestClass ^> ^CreateRenSharpRayCollisionTestClass(LineSegClass ray);
			static IUnmanagedContainer<IRayCollisionTestClass ^> ^CreateRenSharpRayCollisionTestClass(LineSegClass ray, Nullable<CastResultStruct> res, RenSharp::CollisionType collisionType, bool ignoreTranslucentMeshes);
			static IUnmanagedContainer<IRayCollisionTestClass ^> ^CreateRenSharpRayCollisionTestClass(LineSegClass ray, Nullable<CastResultStruct> res, RenSharp::CollisionType collisionType);
			static IUnmanagedContainer<IRayCollisionTestClass ^> ^CreateRenSharpRayCollisionTestClass(LineSegClass ray, Nullable<CastResultStruct> res);
			static IUnmanagedContainer<IRayCollisionTestClass ^> ^CreateRenSharpRayCollisionTestClass(IRayCollisionTestClass ^rayTest, Matrix3D tm);
			static IUnmanagedContainer<IRayCollisionTestClass ^> ^CreateRenSharpRayCollisionTestClass(RayCollisionTestClass ^rayTest, Matrix3D tm);
			static IUnmanagedContainer<IRayCollisionTestClass ^> ^CreateRenSharpRayCollisionTestClass(RayCollisionTestClass ^rayTest);

			property IntPtr RenSharpRayCollisionTestClassPointer
			{
				IntPtr get();
			}

			property Nullable<CastResultStruct> Result
			{
				Nullable<CastResultStruct> get() override;
				void set(Nullable<CastResultStruct> value);
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::RenSharpRayCollisionTestClass *InternalRenSharpRayCollisionTestClassPointer
			{
				virtual ::RenSharpRayCollisionTestClass *get();
			}
	};

	public ref class RayCollisionTestClass : public CollisionTestClass
	{
		private:
			LineSegClass ray;
			bool ignoreTranslucentMeshes;

		public:
			RayCollisionTestClass(LineSegClass ray, CastResultStruct result, RenSharp::CollisionType collisionType, bool ignoreTranslucentMeshes);
			RayCollisionTestClass(LineSegClass ray, CastResultStruct result, RenSharp::CollisionType collisionType);
			RayCollisionTestClass(LineSegClass ray, CastResultStruct result);
			RayCollisionTestClass(LineSegClass ray, RenSharp::CollisionType collisionType, bool ignoreTranslucentMeshes);
			RayCollisionTestClass(LineSegClass ray, RenSharp::CollisionType collisionType);
			RayCollisionTestClass(LineSegClass ray);
			RayCollisionTestClass(IRayCollisionTestClass ^rayTest, Matrix3D tm);
			RayCollisionTestClass(RayCollisionTestClass ^rayTest, Matrix3D tm);
			RayCollisionTestClass(IRayCollisionTestClass ^rayTest);
			RayCollisionTestClass(RayCollisionTestClass ^rayTest);

			void CopyFrom(IRayCollisionTestClass ^rayTest);
			void CopyFrom(RayCollisionTestClass ^rayTest);

			property LineSegClass Ray
			{
				LineSegClass get();
				void set(LineSegClass value);
			}

			property bool IgnoreTranslucentMeshes
			{
				bool get();
				void set(bool value);
			}
	};

	public interface class IAABoxCollisionTestClass : public ICollisionTestClass
	{
		enum class RotationType : int
		{
			RotateNone = ::AABoxCollisionTestClass::ROTATE_NONE,
			RotateZ90 = ::AABoxCollisionTestClass::ROTATE_Z90,
			RotateZ180 = ::AABoxCollisionTestClass::ROTATE_Z180,
			RotateZ270 = ::AABoxCollisionTestClass::ROTATE_Z270
		};

		AABoxCollisionTestClass ^ToAABoxCollisionTestClass();

		bool Cull(Vector3 min, Vector3 max);

		bool Cull(AABoxClass box);

		void Translate(Vector3 translation);

		void Rotate(RotationType rotation);

		void Transform(Matrix3D tm);

		property IntPtr AABoxCollisionTestClassPointer
		{
			IntPtr get();
		}

		property AABoxClass Box
		{
			AABoxClass get();
			void set(AABoxClass value);
		}

		property Vector3 Move
		{
			Vector3 get();
			void set(Vector3 value);
		}

		property Vector3 SweepMin
		{
			Vector3 get();
			void set(Vector3 value);
		}

		property Vector3 SweepMax
		{
			Vector3 get();
			void set(Vector3 value);
		}
	};

	public ref class AABoxCollisionTestClassRef : public CollisionTestClassRef, public IAABoxCollisionTestClass
	{
		private:
			AABoxCollisionTestClassRef(AABoxClass aabox, Vector3 move, RenSharp::CollisionType collisionType);
			AABoxCollisionTestClassRef(AABoxClass aabox, Vector3 move);

		protected:
			AABoxCollisionTestClassRef();

		public:
			AABoxCollisionTestClassRef(IntPtr pointer);

			static IUnmanagedContainer<IAABoxCollisionTestClass ^> ^CreateAABoxCollisionTestClassRef(AABoxClass aabox, Vector3 move, RenSharp::CollisionType collisionType);
			static IUnmanagedContainer<IAABoxCollisionTestClass ^> ^CreateAABoxCollisionTestClassRef(AABoxClass aabox, Vector3 move);

			CollisionTestClass ^ToCollisionTestClass() override;
			virtual AABoxCollisionTestClass ^ToAABoxCollisionTestClass();
			virtual bool Cull(Vector3 min, Vector3 max) sealed;
			virtual bool Cull(AABoxClass box) sealed;
			virtual void Translate(Vector3 translation) sealed;
			virtual void Rotate(IAABoxCollisionTestClass::RotationType rotation) sealed;
			virtual void Transform(Matrix3D tm) sealed;

			property IntPtr AABoxCollisionTestClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property AABoxClass Box
			{
				virtual AABoxClass get() sealed;
				virtual void set(AABoxClass value) sealed;
			}

			property Vector3 Move
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

			property Vector3 SweepMin
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

			property Vector3 SweepMax
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::CollisionTestClass *InternalCollisionTestClassPointer
			{
				::CollisionTestClass *get() override;
			}

			property ::AABoxCollisionTestClass *InternalAABoxCollisionTestClassPointer
			{
				virtual ::AABoxCollisionTestClass *get();
			}
	};

	public ref class RenSharpAABoxCollisionTestClass : public AABoxCollisionTestClassRef
	{
		private:
			RenSharpAABoxCollisionTestClass(AABoxClass aabox, Vector3 move, RenSharp::CollisionType collisionType);
			RenSharpAABoxCollisionTestClass(AABoxClass aabox, Vector3 move);
			RenSharpAABoxCollisionTestClass(AABoxClass aabox, Vector3 move, Nullable<CastResultStruct> res, RenSharp::CollisionType collisionType);
			RenSharpAABoxCollisionTestClass(AABoxClass aabox, Vector3 move, Nullable<CastResultStruct> res);
			RenSharpAABoxCollisionTestClass(AABoxCollisionTestClass ^boxTest);

		public:
			RenSharpAABoxCollisionTestClass(IntPtr pointer);

			static IUnmanagedContainer<IAABoxCollisionTestClass ^> ^CreateRenSharpAABoxCollisionTestClass(AABoxClass aabox, Vector3 move, RenSharp::CollisionType collisionType);
			static IUnmanagedContainer<IAABoxCollisionTestClass ^> ^CreateRenSharpAABoxCollisionTestClass(AABoxClass aabox, Vector3 move);
			static IUnmanagedContainer<IAABoxCollisionTestClass ^> ^CreateRenSharpAABoxCollisionTestClass(AABoxClass aabox, Vector3 move, Nullable<CastResultStruct> res, RenSharp::CollisionType collisionType);
			static IUnmanagedContainer<IAABoxCollisionTestClass ^> ^CreateRenSharpAABoxCollisionTestClass(AABoxClass aabox, Vector3 move, Nullable<CastResultStruct> res);
			static IUnmanagedContainer<IAABoxCollisionTestClass ^> ^CreateRenSharpAABoxCollisionTestClass(AABoxCollisionTestClass ^boxTest);

			property IntPtr RenSharpAABoxCollisionTestClassPointer
			{
				IntPtr get();
			}

			property Nullable<CastResultStruct> Result
			{
				Nullable<CastResultStruct> get() override;
				void set(Nullable<CastResultStruct> value);
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::RenSharpAABoxCollisionTestClass *InternalRenSharpAABoxCollisionTestClassPointer
			{
				virtual ::RenSharpAABoxCollisionTestClass *get();
			}
	};

	public ref class AABoxCollisionTestClass : public CollisionTestClass
	{
		private:
			AABoxClass box;
			Vector3 move;
			Vector3 sweepMin;
			Vector3 sweepMax;

		public:
			AABoxCollisionTestClass(AABoxClass aabox, Vector3 move, RenSharp::CollisionType collisionType);
			AABoxCollisionTestClass(AABoxClass aabox, Vector3 move);
			AABoxCollisionTestClass(AABoxClass aabox, Vector3 move, CastResultStruct res, RenSharp::CollisionType collisionType);
			AABoxCollisionTestClass(AABoxClass aabox, Vector3 move, CastResultStruct res);
			AABoxCollisionTestClass(IAABoxCollisionTestClass ^boxTest);
			AABoxCollisionTestClass(AABoxCollisionTestClass ^boxTest);

			void CopyFrom(IAABoxCollisionTestClass ^boxTest);
			void CopyFrom(AABoxCollisionTestClass ^boxTest);
			bool Cull(Vector3 min, Vector3 max);
			bool Cull(AABoxClass box);
			void Translate(Vector3 translation);
			void Rotate(IAABoxCollisionTestClass::RotationType rotation);
			void Transform(Matrix3D tm);

			property AABoxClass Box
			{
				AABoxClass get();
				void set(AABoxClass value);
			}

			property Vector3 Move
			{
				Vector3 get();
				void set(Vector3 value);
			}

			property Vector3 SweepMin
			{
				Vector3 get();
				void set(Vector3 value);
			}

			property Vector3 SweepMax
			{
				Vector3 get();
				void set(Vector3 value);
			}
	};

	public interface class IOBBoxCollisionTestClass : public ICollisionTestClass
	{
		OBBoxCollisionTestClass ^ToOBBoxCollisionTestClass();

		bool Cull(Vector3 min, Vector3 max);

		bool Cull(AABoxClass box);

		property IntPtr OBBoxCollisionTestClassPointer
		{
			IntPtr get();
		}

		property OBBoxClass Box
		{
			OBBoxClass get();
			void set(OBBoxClass value);
		}

		property Vector3 Move
		{
			Vector3 get();
			void set(Vector3 value);
		}

		property Vector3 SweepMin
		{
			Vector3 get();
			void set(Vector3 value);
		}

		property Vector3 SweepMax
		{
			Vector3 get();
			void set(Vector3 value);
		}
	};

	public ref class OBBoxCollisionTestClassRef : public CollisionTestClassRef, public IOBBoxCollisionTestClass
	{
		private:
			OBBoxCollisionTestClassRef(OBBoxClass obbox, Vector3 move, RenSharp::CollisionType collisionType);
			OBBoxCollisionTestClassRef(OBBoxClass obbox, Vector3 move);
			OBBoxCollisionTestClassRef(IOBBoxCollisionTestClass ^that, Matrix3D tm);
			OBBoxCollisionTestClassRef(IAABoxCollisionTestClass ^that, Matrix3D tm);

		protected:
			OBBoxCollisionTestClassRef();

		public:
			OBBoxCollisionTestClassRef(IntPtr pointer);

			static IUnmanagedContainer<IOBBoxCollisionTestClass ^> ^CreateOBBoxCollisionTestClassRef(OBBoxClass obbox, Vector3 move, RenSharp::CollisionType collisionType);
			static IUnmanagedContainer<IOBBoxCollisionTestClass ^> ^CreateOBBoxCollisionTestClassRef(OBBoxClass obbox, Vector3 move);
			static IUnmanagedContainer<IOBBoxCollisionTestClass ^> ^CreateOBBoxCollisionTestClassRef(IOBBoxCollisionTestClass ^that, Matrix3D tm);
			static IUnmanagedContainer<IOBBoxCollisionTestClass ^> ^CreateOBBoxCollisionTestClassRef(IAABoxCollisionTestClass ^that, Matrix3D tm);

			CollisionTestClass ^ToCollisionTestClass() override;
			virtual OBBoxCollisionTestClass ^ToOBBoxCollisionTestClass();
			virtual bool Cull(Vector3 min, Vector3 max) sealed;
			virtual bool Cull(AABoxClass box) sealed;

			property IntPtr OBBoxCollisionTestClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property OBBoxClass Box
			{
				virtual OBBoxClass get() sealed;
				virtual void set(OBBoxClass value) sealed;
			}

			property Vector3 Move
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

			property Vector3 SweepMin
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

			property Vector3 SweepMax
			{
				virtual Vector3 get() sealed;
				virtual void set(Vector3 value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::CollisionTestClass *InternalCollisionTestClassPointer
			{
				::CollisionTestClass *get() override;
			}

			property ::OBBoxCollisionTestClass *InternalOBBoxCollisionTestClassPointer
			{
				virtual ::OBBoxCollisionTestClass *get();
			}
	};

	public ref class RenSharpOBBoxCollisionTestClass : public OBBoxCollisionTestClassRef
	{
		private:
			RenSharpOBBoxCollisionTestClass(OBBoxClass obbox, Vector3 move, RenSharp::CollisionType collisionType);
			RenSharpOBBoxCollisionTestClass(OBBoxClass obbox, Vector3 move);
			RenSharpOBBoxCollisionTestClass(OBBoxClass obbox, Vector3 move, Nullable<CastResultStruct> res, RenSharp::CollisionType collisionType);
			RenSharpOBBoxCollisionTestClass(OBBoxClass obbox, Vector3 move, Nullable<CastResultStruct> res);
			RenSharpOBBoxCollisionTestClass(IOBBoxCollisionTestClass ^that, Matrix3D tm);
			RenSharpOBBoxCollisionTestClass(IAABoxCollisionTestClass ^that, Matrix3D tm);
			RenSharpOBBoxCollisionTestClass(OBBoxCollisionTestClass ^boxTest);

		public:
			RenSharpOBBoxCollisionTestClass(IntPtr pointer);

			static IUnmanagedContainer<IOBBoxCollisionTestClass ^> ^CreateRenSharpOBBoxCollisionTestClass(OBBoxClass obbox, Vector3 move, RenSharp::CollisionType collisionType);
			static IUnmanagedContainer<IOBBoxCollisionTestClass ^> ^CreateRenSharpOBBoxCollisionTestClass(OBBoxClass obbox, Vector3 move);
			static IUnmanagedContainer<IOBBoxCollisionTestClass ^> ^CreateRenSharpOBBoxCollisionTestClass(OBBoxClass obbox, Vector3 move, Nullable<CastResultStruct> res, RenSharp::CollisionType collisionType);
			static IUnmanagedContainer<IOBBoxCollisionTestClass ^> ^CreateRenSharpOBBoxCollisionTestClass(OBBoxClass obbox, Vector3 move, Nullable<CastResultStruct> res);
			static IUnmanagedContainer<IOBBoxCollisionTestClass ^> ^CreateRenSharpOBBoxCollisionTestClass(IOBBoxCollisionTestClass ^that, Matrix3D tm);
			static IUnmanagedContainer<IOBBoxCollisionTestClass ^> ^CreateRenSharpOBBoxCollisionTestClass(IAABoxCollisionTestClass ^that, Matrix3D tm);
			static IUnmanagedContainer<IOBBoxCollisionTestClass ^> ^CreateRenSharpOBBoxCollisionTestClass(OBBoxCollisionTestClass ^boxTest);

			property IntPtr RenSharpOBBoxCollisionTestClassPointer
			{
				IntPtr get();
			}

			property Nullable<CastResultStruct> Result
			{
				Nullable<CastResultStruct> get() override;
				void set(Nullable<CastResultStruct> value);
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::RenSharpOBBoxCollisionTestClass *InternalRenSharpOBBoxCollisionTestClassPointer
			{
				virtual ::RenSharpOBBoxCollisionTestClass *get();
			}
	};

	public ref class OBBoxCollisionTestClass : public CollisionTestClass
	{
		private:
			OBBoxClass box;
			Vector3 move;
			Vector3 sweepMin;
			Vector3 sweepMax;

		public:
			OBBoxCollisionTestClass(OBBoxClass obbox, Vector3 move, RenSharp::CollisionType collisionType);
			OBBoxCollisionTestClass(OBBoxClass obbox, Vector3 move);
			OBBoxCollisionTestClass(OBBoxClass obbox, Vector3 move, CastResultStruct res, RenSharp::CollisionType collisionType);
			OBBoxCollisionTestClass(OBBoxClass obbox, Vector3 move, CastResultStruct res);
			OBBoxCollisionTestClass(IOBBoxCollisionTestClass ^that, Matrix3D tm);
			OBBoxCollisionTestClass(OBBoxCollisionTestClass ^that, Matrix3D tm);
			OBBoxCollisionTestClass(IAABoxCollisionTestClass ^that, Matrix3D tm);
			OBBoxCollisionTestClass(AABoxCollisionTestClass ^that, Matrix3D tm);
			OBBoxCollisionTestClass(IOBBoxCollisionTestClass ^boxTest);
			OBBoxCollisionTestClass(OBBoxCollisionTestClass ^boxTest);

			void CopyFrom(IOBBoxCollisionTestClass ^boxTest);
			void CopyFrom(OBBoxCollisionTestClass ^boxTest);
			bool Cull(Vector3 min, Vector3 max);
			bool Cull(AABoxClass box);

			property OBBoxClass Box
			{
				OBBoxClass get();
				void set(OBBoxClass value);
			}

			property Vector3 Move
			{
				Vector3 get();
				void set(Vector3 value);
			}

			property Vector3 SweepMin
			{
				Vector3 get();
				void set(Vector3 value);
			}

			property Vector3 SweepMax
			{
				Vector3 get();
				void set(Vector3 value);
			}
	};
}