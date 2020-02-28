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

#include "Mcoltest.h"
#include "MPhysDefClass.h"

#pragma managed(push, off)

class PhysRayCollisionTestClass;
class PhysAABoxCollisionTestClass;
class PhysOBBoxCollisionTestClass;
class RenSharpPhysRayCollisionTestClass;
class RenSharpPhysAABoxCollisionTestClass;
class RenSharpPhysOBBoxCollisionTestClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IPhysClass;
	ref class PhysRayCollisionTestClass;
	ref class PhysAABoxCollisionTestClass;
	ref class PhysOBBoxCollisionTestClass;

	public interface class IPhysRayCollisionTestClass : public IRayCollisionTestClass
	{
		PhysRayCollisionTestClass ^ToPhysRayCollisionTestClass();

		property IntPtr PhysRayCollisionTestClassPointer
		{
			IntPtr get();
		}

		property IPhysClass ^CollidedPhysObj
		{
			IPhysClass ^get();
			void set(IPhysClass ^value);
		}

		property CollisionGroupType CollisionGroup
		{
			CollisionGroupType get();
			void set(CollisionGroupType value);
		}

		property bool CheckStaticObjs
		{
			bool get();
			void set(bool value);
		}

		property bool CheckDynamicObjs
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class PhysRayCollisionTestClassRef : public RayCollisionTestClassRef, public IPhysRayCollisionTestClass
	{
		private:
			PhysRayCollisionTestClassRef(LineSegClass ray, CollisionGroupType group, RenSharp::CollisionType type);
			PhysRayCollisionTestClassRef(LineSegClass ray, CollisionGroupType group);

		protected:
			PhysRayCollisionTestClassRef();

		public:
			PhysRayCollisionTestClassRef(IntPtr pointer);

			static IUnmanagedContainer<IPhysRayCollisionTestClass ^> ^CreatePhysRayCollisionTestClassRef(LineSegClass ray, CollisionGroupType group, RenSharp::CollisionType type);
			static IUnmanagedContainer<IPhysRayCollisionTestClass ^> ^CreatePhysRayCollisionTestClassRef(LineSegClass ray, CollisionGroupType group);

			RayCollisionTestClass ^ToRayCollisionTestClass() override;
			virtual PhysRayCollisionTestClass ^ToPhysRayCollisionTestClass();

			property IntPtr PhysRayCollisionTestClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IPhysClass ^CollidedPhysObj
			{
				virtual IPhysClass ^get() sealed;
				virtual void set(IPhysClass ^value) sealed;
			}

			property CollisionGroupType CollisionGroup
			{
				virtual CollisionGroupType get() sealed;
				virtual void set(CollisionGroupType value) sealed;
			}

			property bool CheckStaticObjs
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool CheckDynamicObjs
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::RayCollisionTestClass *InternalRayCollisionTestClassPointer
			{
				::RayCollisionTestClass *get() override;
			}

			property ::PhysRayCollisionTestClass *InternalPhysRayCollisionTestClassPointer
			{
				virtual ::PhysRayCollisionTestClass *get();
			}
	};

	public ref class RenSharpPhysRayCollisionTestClass : public PhysRayCollisionTestClassRef
	{
		private:
			RenSharpPhysRayCollisionTestClass(LineSegClass ray, CollisionGroupType group, RenSharp::CollisionType type);
			RenSharpPhysRayCollisionTestClass(LineSegClass ray, CollisionGroupType group);
			RenSharpPhysRayCollisionTestClass(LineSegClass ray, Nullable<CastResultStruct> res, CollisionGroupType group, RenSharp::CollisionType type);
			RenSharpPhysRayCollisionTestClass(LineSegClass ray, Nullable<CastResultStruct> res, CollisionGroupType group);
			RenSharpPhysRayCollisionTestClass(PhysRayCollisionTestClass ^collisionTestClass);

		public:
			RenSharpPhysRayCollisionTestClass(IntPtr pointer);

			static IUnmanagedContainer<IPhysRayCollisionTestClass ^> ^CreateRenSharpPhysRayCollisionTestClass(LineSegClass ray, CollisionGroupType group, RenSharp::CollisionType type);
			static IUnmanagedContainer<IPhysRayCollisionTestClass ^> ^CreateRenSharpPhysRayCollisionTestClass(LineSegClass ray, CollisionGroupType group);
			static IUnmanagedContainer<IPhysRayCollisionTestClass ^> ^CreateRenSharpPhysRayCollisionTestClass(LineSegClass ray, Nullable<CastResultStruct> res, CollisionGroupType group, RenSharp::CollisionType type);
			static IUnmanagedContainer<IPhysRayCollisionTestClass ^> ^CreateRenSharpPhysRayCollisionTestClass(LineSegClass ray, Nullable<CastResultStruct> res, CollisionGroupType group);
			static IUnmanagedContainer<IPhysRayCollisionTestClass ^> ^CreateRenSharpPhysRayCollisionTestClass(PhysRayCollisionTestClass ^collisionTestClass);

			property IntPtr RenSharpPhysRayCollisionTestClassPointer
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

			property ::RenSharpPhysRayCollisionTestClass *InternalRenSharpPhysRayCollisionTestClassPointer
			{
				virtual ::RenSharpPhysRayCollisionTestClass *get();
			}
	};

	public ref class PhysRayCollisionTestClass : public RayCollisionTestClass
	{
		public:
			IPhysClass ^CollidedPhysObj;
			CollisionGroupType CollisionGroup;
			bool CheckStaticObjs;
			bool CheckDynamicObjs;

			PhysRayCollisionTestClass(LineSegClass ray, CollisionGroupType group, RenSharp::CollisionType type);
			PhysRayCollisionTestClass(LineSegClass ray, CollisionGroupType group);
			PhysRayCollisionTestClass(IPhysRayCollisionTestClass ^collisionTestClass);
			PhysRayCollisionTestClass(PhysRayCollisionTestClass ^collisionTestClass);

			void CopyFrom(IPhysRayCollisionTestClass ^collisionTestClass);
			void CopyFrom(PhysRayCollisionTestClass ^collisionTestClass);
	};

	public interface class IPhysAABoxCollisionTestClass : public IAABoxCollisionTestClass
	{
		PhysAABoxCollisionTestClass ^ToPhysAABoxCollisionTestClass();

		property IntPtr PhysAABoxCollisionTestClassPointer
		{
			IntPtr get();
		}

		property IPhysClass ^CollidedPhysObj
		{
			IPhysClass ^get();
			void set(IPhysClass ^value);
		}

		property CollisionGroupType CollisionGroup
		{
			CollisionGroupType get();
			void set(CollisionGroupType value);
		}

		property bool CheckStaticObjs
		{
			bool get();
			void set(bool value);
		}

		property bool CheckDynamicObjs
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class PhysAABoxCollisionTestClassRef : public AABoxCollisionTestClassRef, public IPhysAABoxCollisionTestClass
	{
		private:
			PhysAABoxCollisionTestClassRef(AABoxClass box, Vector3 move, CollisionGroupType group, RenSharp::CollisionType type);
			PhysAABoxCollisionTestClassRef(AABoxClass box, Vector3 move, CollisionGroupType group);

		protected:
			PhysAABoxCollisionTestClassRef();

		public:
			PhysAABoxCollisionTestClassRef(IntPtr pointer);

			static IUnmanagedContainer<IPhysAABoxCollisionTestClass ^> ^CreatePhysAABoxCollisionTestClassRef(AABoxClass box, Vector3 move, CollisionGroupType group, RenSharp::CollisionType type);
			static IUnmanagedContainer<IPhysAABoxCollisionTestClass ^> ^CreatePhysAABoxCollisionTestClassRef(AABoxClass box, Vector3 move, CollisionGroupType group);

			AABoxCollisionTestClass ^ToAABoxCollisionTestClass() override;
			virtual PhysAABoxCollisionTestClass ^ToPhysAABoxCollisionTestClass();

			property IntPtr PhysAABoxCollisionTestClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IPhysClass ^CollidedPhysObj
			{
				virtual IPhysClass ^get() sealed;
				virtual void set(IPhysClass ^value) sealed;
			}

			property CollisionGroupType CollisionGroup
			{
				virtual CollisionGroupType get() sealed;
				virtual void set(CollisionGroupType value) sealed;
			}

			property bool CheckStaticObjs
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool CheckDynamicObjs
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::AABoxCollisionTestClass *InternalAABoxCollisionTestClassPointer
			{
				::AABoxCollisionTestClass *get() override;
			}

			property ::PhysAABoxCollisionTestClass *InternalPhysAABoxCollisionTestClassPointer
			{
				virtual ::PhysAABoxCollisionTestClass *get();
			}
	};

	public ref class RenSharpPhysAABoxCollisionTestClass : public PhysAABoxCollisionTestClassRef
	{
		private:
			RenSharpPhysAABoxCollisionTestClass(AABoxClass box, Vector3 move, CollisionGroupType group, RenSharp::CollisionType type);
			RenSharpPhysAABoxCollisionTestClass(AABoxClass box, Vector3 move, CollisionGroupType group);
			RenSharpPhysAABoxCollisionTestClass(AABoxClass box, Vector3 move, Nullable<CastResultStruct> res, CollisionGroupType group, RenSharp::CollisionType type);
			RenSharpPhysAABoxCollisionTestClass(AABoxClass box, Vector3 move, Nullable<CastResultStruct> res, CollisionGroupType group);
			RenSharpPhysAABoxCollisionTestClass(PhysAABoxCollisionTestClass ^collisionTestClass);

		public:
			RenSharpPhysAABoxCollisionTestClass(IntPtr pointer);

			static IUnmanagedContainer<IPhysAABoxCollisionTestClass ^> ^CreateRenSharpPhysAABoxCollisionTestClass(AABoxClass box, Vector3 move, CollisionGroupType group, RenSharp::CollisionType type);
			static IUnmanagedContainer<IPhysAABoxCollisionTestClass ^> ^CreateRenSharpPhysAABoxCollisionTestClass(AABoxClass box, Vector3 move, CollisionGroupType group);
			static IUnmanagedContainer<IPhysAABoxCollisionTestClass ^> ^CreateRenSharpPhysAABoxCollisionTestClass(AABoxClass box, Vector3 move, Nullable<CastResultStruct> res, CollisionGroupType group, RenSharp::CollisionType type);
			static IUnmanagedContainer<IPhysAABoxCollisionTestClass ^> ^CreateRenSharpPhysAABoxCollisionTestClass(AABoxClass box, Vector3 move, Nullable<CastResultStruct> res, CollisionGroupType group);
			static IUnmanagedContainer<IPhysAABoxCollisionTestClass ^> ^CreateRenSharpPhysAABoxCollisionTestClass(PhysAABoxCollisionTestClass ^collisionTestClass);

			property IntPtr RenSharpPhysAABoxCollisionTestClassPointer
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

			property ::RenSharpPhysAABoxCollisionTestClass *InternalRenSharpPhysAABoxCollisionTestClassPointer
			{
				virtual ::RenSharpPhysAABoxCollisionTestClass *get();
			}
	};

	public ref class PhysAABoxCollisionTestClass : public AABoxCollisionTestClass
	{
		public:
			IPhysClass ^CollidedPhysObj;
			CollisionGroupType CollisionGroup;
			bool CheckStaticObjs;
			bool CheckDynamicObjs;

			PhysAABoxCollisionTestClass(AABoxClass box, Vector3 move, CollisionGroupType group, RenSharp::CollisionType type);
			PhysAABoxCollisionTestClass(AABoxClass box, Vector3 move, CollisionGroupType group);
			PhysAABoxCollisionTestClass(IPhysAABoxCollisionTestClass ^collisionTestClass);
			PhysAABoxCollisionTestClass(PhysAABoxCollisionTestClass ^collisionTestClass);

			void CopyFrom(IPhysAABoxCollisionTestClass ^collisionTestClass);
			void CopyFrom(PhysAABoxCollisionTestClass ^collisionTestClass);
	};

	public interface class IPhysOBBoxCollisionTestClass : public IOBBoxCollisionTestClass
	{
		PhysOBBoxCollisionTestClass ^ToPhysOBBoxCollisionTestClass();

		property IntPtr PhysOBBoxCollisionTestClassPointer
		{
			IntPtr get();
		}

		property IPhysClass ^CollidedPhysObj
		{
			IPhysClass ^get();
			void set(IPhysClass ^value);
		}

		property CollisionGroupType CollisionGroup
		{
			CollisionGroupType get();
			void set(CollisionGroupType value);
		}

		property bool CheckStaticObjs
		{
			bool get();
			void set(bool value);
		}

		property bool CheckDynamicObjs
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class PhysOBBoxCollisionTestClassRef : public OBBoxCollisionTestClassRef, public IPhysOBBoxCollisionTestClass
	{
		private:
			PhysOBBoxCollisionTestClassRef(OBBoxClass box, Vector3 move, CollisionGroupType group, RenSharp::CollisionType type);
			PhysOBBoxCollisionTestClassRef(OBBoxClass box, Vector3 move, CollisionGroupType group);

		protected:
			PhysOBBoxCollisionTestClassRef();

		public:
			PhysOBBoxCollisionTestClassRef(IntPtr pointer);

			static IUnmanagedContainer<IPhysOBBoxCollisionTestClass ^> ^CreatePhysOBBoxCollisionTestClassRef(OBBoxClass box, Vector3 move, CollisionGroupType group, RenSharp::CollisionType type);
			static IUnmanagedContainer<IPhysOBBoxCollisionTestClass ^> ^CreatePhysOBBoxCollisionTestClassRef(OBBoxClass box, Vector3 move, CollisionGroupType group);

			OBBoxCollisionTestClass ^ToOBBoxCollisionTestClass() override;
			virtual PhysOBBoxCollisionTestClass ^ToPhysOBBoxCollisionTestClass();

			property IntPtr PhysOBBoxCollisionTestClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IPhysClass ^CollidedPhysObj
			{
				virtual IPhysClass ^get() sealed;
				virtual void set(IPhysClass ^value) sealed;
			}

			property CollisionGroupType CollisionGroup
			{
				virtual CollisionGroupType get() sealed;
				virtual void set(CollisionGroupType value) sealed;
			}

			property bool CheckStaticObjs
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool CheckDynamicObjs
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::OBBoxCollisionTestClass *InternalOBBoxCollisionTestClassPointer
			{
				::OBBoxCollisionTestClass *get() override;
			}

			property ::PhysOBBoxCollisionTestClass *InternalPhysOBBoxCollisionTestClassPointer
			{
				virtual ::PhysOBBoxCollisionTestClass *get();
			}
	};

	public ref class RenSharpPhysOBBoxCollisionTestClass : public PhysOBBoxCollisionTestClassRef
	{
		private:
			RenSharpPhysOBBoxCollisionTestClass(OBBoxClass box, Vector3 move, CollisionGroupType group, RenSharp::CollisionType type);
			RenSharpPhysOBBoxCollisionTestClass(OBBoxClass box, Vector3 move, CollisionGroupType group);
			RenSharpPhysOBBoxCollisionTestClass(OBBoxClass box, Vector3 move, Nullable<CastResultStruct> res, CollisionGroupType group, RenSharp::CollisionType type);
			RenSharpPhysOBBoxCollisionTestClass(OBBoxClass box, Vector3 move, Nullable<CastResultStruct> res, CollisionGroupType group);
			RenSharpPhysOBBoxCollisionTestClass(PhysOBBoxCollisionTestClass ^collisionTestClass);

		public:
			RenSharpPhysOBBoxCollisionTestClass(IntPtr pointer);

			static IUnmanagedContainer<IPhysOBBoxCollisionTestClass ^> ^CreateRenSharpPhysOBBoxCollisionTestClass(OBBoxClass box, Vector3 move, CollisionGroupType group, RenSharp::CollisionType type);
			static IUnmanagedContainer<IPhysOBBoxCollisionTestClass ^> ^CreateRenSharpPhysOBBoxCollisionTestClass(OBBoxClass box, Vector3 move, CollisionGroupType group);
			static IUnmanagedContainer<IPhysOBBoxCollisionTestClass ^> ^CreateRenSharpPhysOBBoxCollisionTestClass(OBBoxClass box, Vector3 move, Nullable<CastResultStruct> res, CollisionGroupType group, RenSharp::CollisionType type);
			static IUnmanagedContainer<IPhysOBBoxCollisionTestClass ^> ^CreateRenSharpPhysOBBoxCollisionTestClass(OBBoxClass box, Vector3 move, Nullable<CastResultStruct> res, CollisionGroupType group);
			static IUnmanagedContainer<IPhysOBBoxCollisionTestClass ^> ^CreateRenSharpPhysOBBoxCollisionTestClass(PhysOBBoxCollisionTestClass ^collisionTestClass);

			property IntPtr RenSharpPhysOBBoxCollisionTestClassPointer
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

			property ::RenSharpPhysOBBoxCollisionTestClass *InternalRenSharpPhysOBBoxCollisionTestClassPointer
			{
				virtual ::RenSharpPhysOBBoxCollisionTestClass *get();
			}
	};

	public ref class PhysOBBoxCollisionTestClass : public OBBoxCollisionTestClass
	{
		public:
			IPhysClass ^CollidedPhysObj;
			CollisionGroupType CollisionGroup;
			bool CheckStaticObjs;
			bool CheckDynamicObjs;

			PhysOBBoxCollisionTestClass(OBBoxClass box, Vector3 move, CollisionGroupType group, RenSharp::CollisionType type);
			PhysOBBoxCollisionTestClass(OBBoxClass box, Vector3 move, CollisionGroupType group);
			PhysOBBoxCollisionTestClass(IPhysOBBoxCollisionTestClass ^collisionTestClass);
			PhysOBBoxCollisionTestClass(PhysOBBoxCollisionTestClass ^collisionTestClass);

			void CopyFrom(IPhysOBBoxCollisionTestClass ^collisionTestClass);
			void CopyFrom(PhysOBBoxCollisionTestClass ^collisionTestClass);
	};
}