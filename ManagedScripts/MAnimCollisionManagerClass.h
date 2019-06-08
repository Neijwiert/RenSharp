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
#include "Mmultilist.h"
#include "MPhysClass.h"
#include "Mengine_vector.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <AnimCollisionManagerClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	interface class IRenderObjClass;
	value class Matrix3D;

	public interface class IAnimCollisionManagerDefClass : public IUnmanagedObject
	{
		property IntPtr AnimCollisionManagerDefClassPointer
		{
			IntPtr get();
		}

		property int CollisionMode
		{
			int get();
			void set(int value);
		}

		property int AnimationMode
		{
			int get();
			void set(int value);
		}

		property String ^AnimationName
		{
			String ^get();
			void set(String ^value);
		}
	};

	public ref class AnimCollisionManagerDefClass : public AbstractUnmanagedObject, public IAnimCollisionManagerDefClass
	{
		public:
			AnimCollisionManagerDefClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			property IntPtr AnimCollisionManagerDefClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property int CollisionMode
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int AnimationMode
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property String ^AnimationName
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

		protected:
			property ::AnimCollisionManagerDefClass *InternalAnimCollisionManagerDefClassPointer
			{
				virtual ::AnimCollisionManagerDefClass *get();
			}
	};

	public interface class IRiderManagerClass : public IUnmanagedObject
	{
		property IntPtr RiderManagerClassPointer
		{
			IntPtr get();
		}

		property IMultiListClass<IPhysClass ^> ^RiderList
		{
			IMultiListClass<IPhysClass ^> ^get();
		}
	};

	public ref class RiderManagerClass : public AbstractUnmanagedObject, public IRiderManagerClass
	{
		public:
			RiderManagerClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			property IntPtr RiderManagerClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IMultiListClass<IPhysClass ^> ^RiderList
			{
				virtual IMultiListClass<IPhysClass ^> ^get() sealed;
			}

		protected:
			property ::RiderManagerClass *InternalRiderManagerClassPointer
			{
				virtual ::RiderManagerClass *get();
			}
	};

	public interface class IAnimCollisionManagerClass : public IUnmanagedObject
	{
		enum class AnimModeType : int
		{
			AnimateLoop = ::AnimCollisionManagerClass::ANIMATE_LOOP,
			AnimateTarget = ::AnimCollisionManagerClass::ANIMATE_TARGET,
			AnimateManual = ::AnimCollisionManagerClass::ANIMATE_MANUAL
		};

		enum class CollisionModeType : int
		{
			CollideNone = ::AnimCollisionManagerClass::COLLIDE_NONE,
			CollideStop = ::AnimCollisionManagerClass::COLLIDE_STOP,
			CollidePush = ::AnimCollisionManagerClass::COLLIDE_PUSH,
			CollideKill = ::AnimCollisionManagerClass::COLLIDE_KILL
		};

		property IntPtr AnimCollisionManagerClassPointer
		{
			IntPtr get();
		}
	};

	public interface class ICollideableObjClass : public IUnmanagedObject
	{
		IRenderObjClass ^PeekCollisionObject();

		void CacheStartTransform();

		void CacheEndTransform();

		void InstallStartTransform();

		void InstallEndTransform();

		property IntPtr CollideableObjClassPointer
		{
			IntPtr get();
		}

		property Matrix3D StartTransform
		{
			Matrix3D get();
		}

		property Matrix3D EndTransform
		{
			Matrix3D get();
		}
	};

	public ref class CollideableObjClass : public AbstractUnmanagedObject, public ICollideableObjClass
	{
		public:
			CollideableObjClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual IRenderObjClass ^PeekCollisionObject() sealed;
			virtual void CacheStartTransform() sealed;
			virtual void CacheEndTransform() sealed;
			virtual void InstallStartTransform() sealed;
			virtual void InstallEndTransform() sealed;

			property IntPtr CollideableObjClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property Matrix3D StartTransform
			{
				virtual Matrix3D get() sealed;

				protected:
					void set(Matrix3D value);
			}

			property Matrix3D EndTransform
			{
				virtual Matrix3D get() sealed;

				protected:
					void set(Matrix3D value);
			}

		protected:
			bool InternalDestroyPointer() override;

			property void *InternalCollideableObjClassPointer
			{
				virtual void *get();
			}

			property IRenderObjClass ^CollisionMesh
			{
				IRenderObjClass ^get();
				void set(IRenderObjClass ^value);
			}
	};

	public ref class AnimCollisionManagerClass : public AbstractUnmanagedObject, public IAnimCollisionManagerClass
	{
		public:
			AnimCollisionManagerClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			property IntPtr AnimCollisionManagerClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::AnimCollisionManagerClass *InternalAnimCollisionManagerClassPointer
			{
				virtual ::AnimCollisionManagerClass *get();
			}

			property IPhysClass ^Parent
			{
				IPhysClass ^get();
			}

			property IAnimCollisionManagerClass::AnimModeType AnimationMode
			{
				IAnimCollisionManagerClass::AnimModeType get();
				void set(IAnimCollisionManagerClass::AnimModeType value);
			}

			property float TargetFrame
			{
				float get();
				void set(float value);
			}

			property float LoopStart
			{
				float get();
				void set(float value);
			}

			property float LoopEnd
			{
				float get();
				void set(float value);
			}

			property IntPtr CurAnimation
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property float CurFrame
			{
				float get();
				void set(float value);
			}

			property IntPtr PrevAnimation
			{
				IntPtr get();
				void set(IntPtr value);
			}

			property float PrevFrame
			{
				float get();
				void set(float value);
			}

			property IRiderManagerClass ^RiderManager
			{
				IRiderManagerClass ^get();
			}

			property IAnimCollisionManagerClass::CollisionModeType CollisionMode
			{
				IAnimCollisionManagerClass::CollisionModeType get();
				void set(IAnimCollisionManagerClass::CollisionModeType value);
			}

			property IDynamicVectorClass<ICollideableObjClass ^> ^CollisionMeshes
			{
				IDynamicVectorClass<ICollideableObjClass ^> ^get();
			}

			property IntPtr PushList
			{
				IntPtr get();
				void set(IntPtr value);
			}
	};
}