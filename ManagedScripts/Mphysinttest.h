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

#include "Minttest.h"
#include "MAABoxClass.h"
#include "Mobboxclass.h"
#include "Mmultilist.h"
#include "MPhysClass.h"
#include "MPhysDefClass.h"

#pragma managed(push, off)

class PhysAABoxIntersectionTestClass;
class PhysOBBoxIntersectionTestClass;
class PhysMeshIntersectionTestClass;
class RenSharpPhysAABoxIntersectionTestClass;
class RenSharpPhysOBBoxIntersectionTestClass;
class RenSharpPhysMeshIntersectionTestClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IMeshClass;
	ref class PhysAABoxIntersectionTestClass;
	ref class PhysOBBoxIntersectionTestClass;
	ref class PhysMeshIntersectionTestClass;

	public interface class IPhysAABoxIntersectionTestClass : public IAABoxIntersectionTestClass
	{
		PhysAABoxIntersectionTestClass ^ToPhysAABoxIntersectionTestClass();

		void AddIntersectedObject(IPhysClass ^obj);

		property IntPtr PhysAABoxIntersectionTestClassPointer
		{
			IntPtr get();
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

	public ref class PhysAABoxIntersectionTestClassRef : public AABoxIntersectionTestClassRef, public IPhysAABoxIntersectionTestClass
	{
		private:
			PhysAABoxIntersectionTestClassRef(AABoxClass box, CollisionGroupType colGroup, RenSharp::CollisionType colType);

		protected:
			PhysAABoxIntersectionTestClassRef();

		public:
			PhysAABoxIntersectionTestClassRef(IntPtr pointer);

			static IUnmanagedContainer<IPhysAABoxIntersectionTestClass ^> ^CreatePhysAABoxIntersectionTestClassRef(AABoxClass box, CollisionGroupType colGroup, RenSharp::CollisionType colType);

			AABoxIntersectionTestClass ^ToAABoxIntersectionTestClass() override;
			virtual PhysAABoxIntersectionTestClass ^ToPhysAABoxIntersectionTestClass();
			virtual void AddIntersectedObject(IPhysClass ^obj) sealed;

			property IntPtr PhysAABoxIntersectionTestClassPointer
			{
				virtual IntPtr get() sealed;
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

			property ::AABoxIntersectionTestClass *InternalAABoxIntersectionTestClassPointer
			{
				::AABoxIntersectionTestClass *get() override;
			}

			property ::PhysAABoxIntersectionTestClass *InternalPhysAABoxIntersectionTestClassPointer
			{
				virtual ::PhysAABoxIntersectionTestClass *get();
			}
	};

	public ref class RenSharpPhysAABoxIntersectionTestClass : public PhysAABoxIntersectionTestClassRef
	{
		private:
			RenSharpPhysAABoxIntersectionTestClass(AABoxClass box, CollisionGroupType colGroup, RenSharp::CollisionType colType, bool enableResultList);
			RenSharpPhysAABoxIntersectionTestClass(PhysAABoxIntersectionTestClass ^intersectionTestClass);

		public:
			RenSharpPhysAABoxIntersectionTestClass(IntPtr pointer);

			static IUnmanagedContainer<IPhysAABoxIntersectionTestClass ^> ^CreateRenSharpPhysAABoxIntersectionTestClass(AABoxClass box, CollisionGroupType colGroup, RenSharp::CollisionType colType, bool enableResultList);
			static IUnmanagedContainer<IPhysAABoxIntersectionTestClass ^> ^CreateRenSharpPhysAABoxIntersectionTestClass(PhysAABoxIntersectionTestClass ^intersectionTestClass);

			property IntPtr RenSharpPhysAABoxIntersectionTestClassPointer
			{
				IntPtr get();
			}

			property IMultiListClass<IPhysClass ^> ^IntersectedObjects
			{
				IMultiListClass<IPhysClass ^> ^get();
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::RenSharpPhysAABoxIntersectionTestClass *InternalRenSharpPhysAABoxIntersectionTestClassPointer
			{
				virtual ::RenSharpPhysAABoxIntersectionTestClass *get();
			}
	};

	public ref class PhysAABoxIntersectionTestClass : public AABoxIntersectionTestClass
	{
		private:
			CollisionGroupType collisionGroup;
			bool checkStaticObjs;
			bool checkDynamicObjs;
			Generic::ICollection<IPhysClass ^> ^intersectedObjects;

		public:
			PhysAABoxIntersectionTestClass(AABoxClass box, CollisionGroupType colGroup, RenSharp::CollisionType colType);
			PhysAABoxIntersectionTestClass(IPhysAABoxIntersectionTestClass ^intersectionTestClass);
			PhysAABoxIntersectionTestClass(PhysAABoxIntersectionTestClass ^intersectionTestClass);

			void CopyFrom(IPhysAABoxIntersectionTestClass ^intersectionTestClass);
			void CopyFrom(PhysAABoxIntersectionTestClass ^intersectionTestClass);

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

			property Generic::ICollection<IPhysClass ^> ^IntersectedObjects
			{
				Generic::ICollection<IPhysClass ^> ^get();

				internal:
					void set(Generic::ICollection<IPhysClass ^> ^value);
			}
	};

	public interface class IPhysOBBoxIntersectionTestClass : public IOBBoxIntersectionTestClass
	{
		PhysOBBoxIntersectionTestClass ^ToPhysOBBoxIntersectionTestClass();

		void AddIntersectedObject(IPhysClass ^obj);

		property IntPtr PhysOBBoxIntersectionTestClassPointer
		{
			IntPtr get();
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

	public ref class PhysOBBoxIntersectionTestClassRef : public OBBoxIntersectionTestClassRef, public IPhysOBBoxIntersectionTestClass
	{
		private:
			PhysOBBoxIntersectionTestClassRef(OBBoxClass box, CollisionGroupType colGroup, RenSharp::CollisionType colType);

		protected:
			PhysOBBoxIntersectionTestClassRef();

		public:
			PhysOBBoxIntersectionTestClassRef(IntPtr pointer);

			static IUnmanagedContainer<IPhysOBBoxIntersectionTestClass ^> ^CreatePhysOBBoxIntersectionTestClassRef(OBBoxClass box, CollisionGroupType colGroup, RenSharp::CollisionType colType);

			OBBoxIntersectionTestClass ^ToOBBoxIntersectionTestClass() override;
			virtual PhysOBBoxIntersectionTestClass ^ToPhysOBBoxIntersectionTestClass();
			virtual void AddIntersectedObject(IPhysClass ^obj) sealed;

			property IntPtr PhysOBBoxIntersectionTestClassPointer
			{
				virtual IntPtr get() sealed;
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

			property ::OBBoxIntersectionTestClass *InternalOBBoxIntersectionTestClassPointer
			{
				::OBBoxIntersectionTestClass *get() override;
			}

			property ::PhysOBBoxIntersectionTestClass *InternalPhysOBBoxIntersectionTestClassPointer
			{
				virtual ::PhysOBBoxIntersectionTestClass *get();
			}
	};

	public ref class RenSharpPhysOBBoxIntersectionTestClass : public PhysOBBoxIntersectionTestClassRef
	{
		private:
			RenSharpPhysOBBoxIntersectionTestClass(OBBoxClass box, CollisionGroupType colGroup, RenSharp::CollisionType colType, bool enableResultList);
			RenSharpPhysOBBoxIntersectionTestClass(PhysOBBoxIntersectionTestClass ^intersectionTestClass);

		public:
			RenSharpPhysOBBoxIntersectionTestClass(IntPtr pointer);

			static IUnmanagedContainer<IPhysOBBoxIntersectionTestClass ^> ^CreateRenSharpPhysOBBoxIntersectionTestClass(OBBoxClass box, CollisionGroupType colGroup, RenSharp::CollisionType colType, bool enableResultList);
			static IUnmanagedContainer<IPhysOBBoxIntersectionTestClass ^> ^CreateRenSharpPhysOBBoxIntersectionTestClass(PhysOBBoxIntersectionTestClass ^intersectionTestClass);

			property IntPtr RenSharpPhysOBBoxIntersectionTestClassPointer
			{
				IntPtr get();
			}

			property IMultiListClass<IPhysClass ^> ^IntersectedObjects
			{
				IMultiListClass<IPhysClass ^> ^get();
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::RenSharpPhysOBBoxIntersectionTestClass *InternalRenSharpPhysOBBoxIntersectionTestClassPointer
			{
				virtual ::RenSharpPhysOBBoxIntersectionTestClass *get();
			}
	};

	public ref class PhysOBBoxIntersectionTestClass : public OBBoxIntersectionTestClass
	{
		private:
			CollisionGroupType collisionGroup;
			bool checkStaticObjs;
			bool checkDynamicObjs;
			Generic::ICollection<IPhysClass ^> ^intersectedObjects;

		public:
			PhysOBBoxIntersectionTestClass(OBBoxClass box, CollisionGroupType colGroup, RenSharp::CollisionType colType);
			PhysOBBoxIntersectionTestClass(IPhysOBBoxIntersectionTestClass ^intersectionTestClass);
			PhysOBBoxIntersectionTestClass(PhysOBBoxIntersectionTestClass ^intersectionTestClass);

			void CopyFrom(IPhysOBBoxIntersectionTestClass ^intersectionTestClass);
			void CopyFrom(PhysOBBoxIntersectionTestClass ^intersectionTestClass);

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

			property Generic::ICollection<IPhysClass ^> ^IntersectedObjects
			{
				Generic::ICollection<IPhysClass ^> ^get();

				internal:
					void set(Generic::ICollection<IPhysClass ^> ^value);
			}
	};

	public interface class IPhysMeshIntersectionTestClass : public IIntersectionTestClass
	{
		PhysMeshIntersectionTestClass ^ToPhysMeshIntersectionTestClass();

		bool Cull(Vector3 min, Vector3 max);

		bool Cull(AABoxClass box);

		void AddIntersectedObject(IPhysClass ^obj);

		property IntPtr PhysMeshIntersectionTestClassPointer
		{
			IntPtr get();
		}

		property IMeshClass ^Mesh
		{
			IMeshClass ^get();
			void set(IMeshClass ^value);
		}

		property AABoxClass BoundingBox
		{
			AABoxClass get();
			void set(AABoxClass value);
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

	public ref class PhysMeshIntersectionTestClassRef : public IntersectionTestClassRef, public IPhysMeshIntersectionTestClass
	{
		private:
			PhysMeshIntersectionTestClassRef(IMeshClass ^mesh, CollisionGroupType colGroup, RenSharp::CollisionType colType);

		protected:
			PhysMeshIntersectionTestClassRef();

		public:
			PhysMeshIntersectionTestClassRef(IntPtr pointer);

			static IUnmanagedContainer<IPhysMeshIntersectionTestClass ^> ^CreatePhysMeshIntersectionTestClassRef();

			IntersectionTestClass ^ToIntersectionTestClass() override;
			virtual PhysMeshIntersectionTestClass ^ToPhysMeshIntersectionTestClass();
			virtual bool Cull(Vector3 min, Vector3 max) sealed;
			virtual bool Cull(AABoxClass box) sealed;
			virtual void AddIntersectedObject(IPhysClass ^obj) sealed;

			property IntPtr PhysMeshIntersectionTestClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IMeshClass ^Mesh
			{
				virtual IMeshClass ^get() sealed;
				virtual void set(IMeshClass ^value) sealed;
			}

			property AABoxClass BoundingBox
			{
				virtual AABoxClass get() sealed;
				virtual void set(AABoxClass value) sealed;
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

			property ::IntersectionTestClass *InternalIntersectionTestClassPointer
			{
				::IntersectionTestClass *get() override;
			}

			property ::PhysMeshIntersectionTestClass *InternalPhysMeshIntersectionTestClassPointer
			{
				virtual ::PhysMeshIntersectionTestClass *get();
			}
	};

	public ref class RenSharpPhysMeshIntersectionTestClass : public PhysMeshIntersectionTestClassRef
	{
		private:
			RenSharpPhysMeshIntersectionTestClass(IMeshClass ^mesh, CollisionGroupType colGroup, RenSharp::CollisionType colType, bool enableResultList);
			RenSharpPhysMeshIntersectionTestClass(PhysMeshIntersectionTestClass ^intersectionTestClass);


		public:
			RenSharpPhysMeshIntersectionTestClass(IntPtr pointer);

			static IUnmanagedContainer<IPhysMeshIntersectionTestClass ^> ^CreateRenSharpPhysMeshIntersectionTestClass(IMeshClass ^mesh, CollisionGroupType colGroup, RenSharp::CollisionType colType, bool enableResultList);
			static IUnmanagedContainer<IPhysMeshIntersectionTestClass ^> ^CreateRenSharpPhysMeshIntersectionTestClass(PhysMeshIntersectionTestClass ^intersectionTestClass);

			property IntPtr RenSharpPhysMeshIntersectionTestClassPointer
			{
				IntPtr get();
			}

			property IMultiListClass<IPhysClass ^> ^IntersectedObjects
			{
				IMultiListClass<IPhysClass ^> ^get();
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::RenSharpPhysMeshIntersectionTestClass *InternalRenSharpPhysMeshIntersectionTestClassPointer
			{
				virtual ::RenSharpPhysMeshIntersectionTestClass *get();
			}
	};

	public ref class PhysMeshIntersectionTestClass : public IntersectionTestClass
	{
		private:
			IMeshClass ^mesh;
			AABoxClass boundingBox;
			CollisionGroupType collisionGroup;
			bool checkStaticObjs;
			bool checkDynamicObjs;
			Generic::ICollection<IPhysClass ^> ^intersectedObjects;

		public:
			PhysMeshIntersectionTestClass(IMeshClass ^mesh, CollisionGroupType colGroup, RenSharp::CollisionType colType);
			PhysMeshIntersectionTestClass(IPhysMeshIntersectionTestClass ^intersectionTestClass);
			PhysMeshIntersectionTestClass(PhysMeshIntersectionTestClass ^intersectionTestClass);

			void CopyFrom(IPhysMeshIntersectionTestClass ^intersectionTestClass);
			void CopyFrom(PhysMeshIntersectionTestClass ^intersectionTestClass);
			bool Cull(Vector3 min, Vector3 max);
			bool Cull(AABoxClass box);

			property IMeshClass ^Mesh
			{
				IMeshClass ^get();
				void set(IMeshClass ^value);
			}

			property AABoxClass BoundingBox
			{
				AABoxClass get();
				void set(AABoxClass value);
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

			property Generic::ICollection<IPhysClass ^> ^IntersectedObjects
			{
				Generic::ICollection<IPhysClass ^> ^get();

				internal:
					void set(Generic::ICollection<IPhysClass ^> ^value);
			}
	};
}