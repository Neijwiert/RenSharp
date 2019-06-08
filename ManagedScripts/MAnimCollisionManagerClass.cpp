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

#include "stdafx.h"
#include "MAnimCollisionManagerClass.h"

#include "MPhysClassMultiListClass.h"
#include "MRenderObjClass.h"
#include "MMatrix3D.h"
#include "Imports.h"
#include "MCollideableObjClassDynamicVectorClass.h"

using namespace System::Runtime::InteropServices;

namespace RenSharp
{

#pragma managed(push, off)

	class AnimCollisionManagerClassHelper : public ::AnimCollisionManagerClass
	{
		public:
			class CollideableObjClassHelper : public ::AnimCollisionManagerClass::CollideableObjClass
			{
				private:
					CollideableObjClassHelper() = default;

				public:
					::RenderObjClass *&GetCollisionMesh()
					{
						return CollisionMesh;
					}

					::Matrix3D &GetStartTransform()
					{
						return StartTransform;
					}

					::Matrix3D &GetEndTransform()
					{
						return EndTransform;
					}
			};

		private:
			AnimCollisionManagerClassHelper(::PhysClass &parent)
				: AnimCollisionManagerClass(parent)
			{

			}

		public:
			static ::RenderObjClass *CollideableObjClassPeekCollisionObject(void *obj)
			{
				::AnimCollisionManagerClass::CollideableObjClass *castObj = reinterpret_cast<::AnimCollisionManagerClass::CollideableObjClass *>(obj);

				return castObj->Peek_Collision_Object();
			}

			static void CollideableObjClassCacheStartTransform(void *obj)
			{
				::AnimCollisionManagerClass::CollideableObjClass *castObj = reinterpret_cast<::AnimCollisionManagerClass::CollideableObjClass *>(obj);

				castObj->Cache_Start_Transform();
			}

			static void CollideableObjClassCacheEndTransform(void *obj)
			{
				::AnimCollisionManagerClass::CollideableObjClass *castObj = reinterpret_cast<::AnimCollisionManagerClass::CollideableObjClass *>(obj);

				castObj->Cache_End_Transform();
			}

			static void CollideableObjClassInstallStartTransform(void *obj)
			{
				::AnimCollisionManagerClass::CollideableObjClass *castObj = reinterpret_cast<::AnimCollisionManagerClass::CollideableObjClass *>(obj);

				castObj->Install_Start_Transform();
			}

			static void CollideableObjClassInstallEndTransform(void *obj)
			{
				::AnimCollisionManagerClass::CollideableObjClass *castObj = reinterpret_cast<::AnimCollisionManagerClass::CollideableObjClass *>(obj);

				castObj->Install_End_Transform();
			}

			::PhysClass &GetParent()
			{
				return Parent;
			}

			::AnimCollisionManagerClass::AnimModeType &GetAnimationMode()
			{
				return AnimationMode;
			}

			float &GetTargetFrame()
			{
				return TargetFrame;
			}

			float &GetLoopStart()
			{
				return LoopStart;
			}

			float &GetLoopEnd()
			{
				return LoopEnd;
			}

			::HAnimClass *&GetCurAnimation()
			{
				return CurAnimation;
			}

			float &GetCurFrame()
			{
				return CurFrame;
			}

			::HAnimClass *&GetPrevAnimation()
			{
				return PrevAnimation;
			}

			float &GetPrevFrame()
			{
				return PrevFrame;
			}

			::RiderManagerClass &GetRiderManager()
			{
				return RiderManager;
			}

			::AnimCollisionManagerClass::CollisionModeType &GetCollisionMode()
			{
				return CollisionMode;
			}

			void *GetCollisionMeshes()
			{
				return &CollisionMeshes;
			}

			::PushRecordClass *&GetPushList()
			{
				return PushList;
			}
	};

#pragma managed(pop)

	AnimCollisionManagerDefClass::AnimCollisionManagerDefClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool AnimCollisionManagerDefClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IAnimCollisionManagerDefClass ^otherThis = dynamic_cast<IAnimCollisionManagerDefClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return AnimCollisionManagerDefClassPointer.Equals(otherThis->AnimCollisionManagerDefClassPointer);
	}

	IntPtr AnimCollisionManagerDefClass::AnimCollisionManagerDefClassPointer::get()
	{
		return IntPtr(InternalAnimCollisionManagerDefClassPointer);
	}

	int AnimCollisionManagerDefClass::CollisionMode::get()
	{
		return InternalAnimCollisionManagerDefClassPointer->CollisionMode;
	}

	void AnimCollisionManagerDefClass::CollisionMode::set(int value)
	{
		InternalAnimCollisionManagerDefClassPointer->CollisionMode = value;
	}

	int AnimCollisionManagerDefClass::AnimationMode::get()
	{
		return InternalAnimCollisionManagerDefClassPointer->AnimationMode;
	}

	void AnimCollisionManagerDefClass::AnimationMode::set(int value)
	{
		InternalAnimCollisionManagerDefClassPointer->AnimationMode = value;
	}

	String ^AnimCollisionManagerDefClass::AnimationName::get()
	{
		return gcnew String(InternalAnimCollisionManagerDefClassPointer->AnimationName.Peek_Buffer());
	}

	void AnimCollisionManagerDefClass::AnimationName::set(String ^value)
	{
		if (value == nullptr)
		{
			throw gcnew ArgumentNullException("value");
		}

		IntPtr valueHandle = Marshal::StringToHGlobalAnsi(value);
		try
		{
			InternalAnimCollisionManagerDefClassPointer->AnimationName = reinterpret_cast<char *>(valueHandle.ToPointer());
		}
		finally
		{
			Marshal::FreeHGlobal(valueHandle);
		}
	}

	::AnimCollisionManagerDefClass *AnimCollisionManagerDefClass::InternalAnimCollisionManagerDefClassPointer::get()
	{
		return reinterpret_cast<::AnimCollisionManagerDefClass *>(Pointer.ToPointer());
	}

	RiderManagerClass::RiderManagerClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool RiderManagerClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IRiderManagerClass ^otherThis = dynamic_cast<IRiderManagerClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return RiderManagerClassPointer.Equals(otherThis->RiderManagerClassPointer);
	}

	IntPtr RiderManagerClass::RiderManagerClassPointer::get()
	{
		return IntPtr(InternalRiderManagerClassPointer);
	}

	IMultiListClass<IPhysClass ^> ^RiderManagerClass::RiderList::get()
	{
		auto result = InternalRiderManagerClassPointer->Get_Rider_List();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew PhysClassMultiListClass(IntPtr(result));
		}
	}

	::RiderManagerClass *RiderManagerClass::InternalRiderManagerClassPointer::get()
	{
		return reinterpret_cast<::RiderManagerClass *>(Pointer.ToPointer());
	}

	CollideableObjClass::CollideableObjClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool CollideableObjClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		ICollideableObjClass ^otherThis = dynamic_cast<ICollideableObjClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return CollideableObjClassPointer.Equals(otherThis->CollideableObjClassPointer);
	}

	IRenderObjClass ^CollideableObjClass::PeekCollisionObject()
	{
		auto result = AnimCollisionManagerClassHelper::CollideableObjClassPeekCollisionObject(InternalCollideableObjClassPointer);
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(result));
		}
	}

	void CollideableObjClass::CacheStartTransform()
	{
		AnimCollisionManagerClassHelper::CollideableObjClassCacheStartTransform(InternalCollideableObjClassPointer);
	}

	void CollideableObjClass::CacheEndTransform()
	{
		AnimCollisionManagerClassHelper::CollideableObjClassCacheEndTransform(InternalCollideableObjClassPointer);
	}

	void CollideableObjClass::InstallStartTransform()
	{
		AnimCollisionManagerClassHelper::CollideableObjClassInstallStartTransform(InternalCollideableObjClassPointer);
	}

	void CollideableObjClass::InstallEndTransform()
	{
		AnimCollisionManagerClassHelper::CollideableObjClassInstallEndTransform(InternalCollideableObjClassPointer);
	}

	IntPtr CollideableObjClass::CollideableObjClassPointer::get()
	{
		return IntPtr(InternalCollideableObjClassPointer);
	}

	Matrix3D CollideableObjClass::StartTransform::get()
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper::CollideableObjClassHelper *>(InternalCollideableObjClassPointer);

		auto &startTransform = helper->GetStartTransform();

		Matrix3D result;

		Matrix3D::UnmanagedToManagedMatrix3D(startTransform, result);

		return result;
	}

	void CollideableObjClass::StartTransform::set(Matrix3D value)
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper::CollideableObjClassHelper *>(InternalCollideableObjClassPointer);

		auto &startTransform = helper->GetStartTransform();

		Matrix3D::ManagedToUnmanagedMatrix3D(value, startTransform);
	}

	Matrix3D CollideableObjClass::EndTransform::get()
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper::CollideableObjClassHelper *>(InternalCollideableObjClassPointer);

		auto &endTransform = helper->GetEndTransform();

		Matrix3D result;

		Matrix3D::UnmanagedToManagedMatrix3D(endTransform, result);

		return result;
	}

	void CollideableObjClass::EndTransform::set(Matrix3D value)
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper::CollideableObjClassHelper *>(InternalCollideableObjClassPointer);

		auto &endTransform = helper->GetEndTransform();

		Matrix3D::ManagedToUnmanagedMatrix3D(value, endTransform);
	}

	bool CollideableObjClass::InternalDestroyPointer()
	{
		Imports::DestroyCollideableObjClass(InternalCollideableObjClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	void *CollideableObjClass::InternalCollideableObjClassPointer::get()
	{
		return Pointer.ToPointer();
	}

	IRenderObjClass ^CollideableObjClass::CollisionMesh::get()
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper::CollideableObjClassHelper *>(InternalCollideableObjClassPointer);

		auto &collisionMesh = helper->GetCollisionMesh();

		if (collisionMesh == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(collisionMesh));
		}
	}

	void CollideableObjClass::CollisionMesh::set(IRenderObjClass ^value)
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper::CollideableObjClassHelper *>(InternalCollideableObjClassPointer);

		auto &collisionMesh = helper->GetCollisionMesh();

		if (value == nullptr || value->RenderObjClassPointer.ToPointer() == nullptr)
		{
			collisionMesh = nullptr;
		}
		else
		{
			collisionMesh = reinterpret_cast<::RenderObjClass *>(value->RenderObjClassPointer.ToPointer());
		}
	}

	AnimCollisionManagerClass::AnimCollisionManagerClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool AnimCollisionManagerClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IAnimCollisionManagerClass ^otherThis = dynamic_cast<IAnimCollisionManagerClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return AnimCollisionManagerClassPointer.Equals(otherThis->AnimCollisionManagerClassPointer);
	}

	IntPtr AnimCollisionManagerClass::AnimCollisionManagerClassPointer::get()
	{
		return IntPtr(InternalAnimCollisionManagerClassPointer);
	}

	::AnimCollisionManagerClass *AnimCollisionManagerClass::InternalAnimCollisionManagerClassPointer::get()
	{
		return reinterpret_cast<::AnimCollisionManagerClass *>(Pointer.ToPointer());
	}

	IPhysClass ^AnimCollisionManagerClass::Parent::get()
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper *>(InternalAnimCollisionManagerClassPointer);

		auto &parent = helper->GetParent();

		return gcnew PhysClass(IntPtr(&parent));
	}

	IAnimCollisionManagerClass::AnimModeType AnimCollisionManagerClass::AnimationMode::get()
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper *>(InternalAnimCollisionManagerClassPointer);

		auto &animationMode = helper->GetAnimationMode();

		return static_cast<IAnimCollisionManagerClass::AnimModeType>(animationMode);
	}

	void AnimCollisionManagerClass::AnimationMode::set(IAnimCollisionManagerClass::AnimModeType value)
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper *>(InternalAnimCollisionManagerClassPointer);

		auto &animationMode = helper->GetAnimationMode();

		animationMode = static_cast<::AnimCollisionManagerClass::AnimModeType>(value);
	}

	float AnimCollisionManagerClass::TargetFrame::get()
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper *>(InternalAnimCollisionManagerClassPointer);

		auto &targetFrame = helper->GetTargetFrame();

		return targetFrame;
	}

	void AnimCollisionManagerClass::TargetFrame::set(float value)
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper *>(InternalAnimCollisionManagerClassPointer);

		auto &targetFrame = helper->GetTargetFrame();

		targetFrame = value;
	}

	float AnimCollisionManagerClass::LoopStart::get()
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper *>(InternalAnimCollisionManagerClassPointer);

		auto &loopStart = helper->GetLoopStart();

		return loopStart;
	}

	void AnimCollisionManagerClass::LoopStart::set(float value)
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper *>(InternalAnimCollisionManagerClassPointer);

		auto &loopStart = helper->GetLoopStart();

		loopStart = value;
	}

	float AnimCollisionManagerClass::LoopEnd::get()
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper *>(InternalAnimCollisionManagerClassPointer);

		auto &loopEnd = helper->GetLoopEnd();

		return loopEnd;
	}

	void AnimCollisionManagerClass::LoopEnd::set(float value)
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper *>(InternalAnimCollisionManagerClassPointer);

		auto &loopEnd = helper->GetLoopEnd();

		loopEnd = value;
	}

	IntPtr AnimCollisionManagerClass::CurAnimation::get()
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper *>(InternalAnimCollisionManagerClassPointer);

		auto &curAnimation = helper->GetCurAnimation();

		return IntPtr(curAnimation);
	}

	void AnimCollisionManagerClass::CurAnimation::set(IntPtr value)
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper *>(InternalAnimCollisionManagerClassPointer);

		auto &curAnimation = helper->GetCurAnimation();

		curAnimation = reinterpret_cast<::HAnimClass *>(value.ToPointer());
	}

	float AnimCollisionManagerClass::CurFrame::get()
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper *>(InternalAnimCollisionManagerClassPointer);

		auto &curFrame = helper->GetCurFrame();

		return curFrame;
	}

	void AnimCollisionManagerClass::CurFrame::set(float value)
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper *>(InternalAnimCollisionManagerClassPointer);

		auto &curFrame = helper->GetCurFrame();

		curFrame = value;
	}

	IntPtr AnimCollisionManagerClass::PrevAnimation::get()
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper *>(InternalAnimCollisionManagerClassPointer);

		auto &prevAnimation = helper->GetPrevAnimation();

		return IntPtr(prevAnimation);
	}

	void AnimCollisionManagerClass::PrevAnimation::set(IntPtr value)
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper *>(InternalAnimCollisionManagerClassPointer);

		auto &prevAnimation = helper->GetPrevAnimation();

		prevAnimation = reinterpret_cast<::HAnimClass *>(value.ToPointer());
	}

	float AnimCollisionManagerClass::PrevFrame::get()
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper *>(InternalAnimCollisionManagerClassPointer);

		auto &prevFrame = helper->GetPrevFrame();

		return prevFrame;
	}

	void AnimCollisionManagerClass::PrevFrame::set(float value)
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper *>(InternalAnimCollisionManagerClassPointer);

		auto &prevFrame = helper->GetPrevFrame();

		prevFrame = value;
	}

	IRiderManagerClass ^AnimCollisionManagerClass::RiderManager::get()
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper *>(InternalAnimCollisionManagerClassPointer);

		auto &riderManager = helper->GetRiderManager();

		return gcnew RiderManagerClass(IntPtr(&riderManager));
	}

	IAnimCollisionManagerClass::CollisionModeType AnimCollisionManagerClass::CollisionMode::get()
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper *>(InternalAnimCollisionManagerClassPointer);

		auto &collisionMode = helper->GetCollisionMode();

		return static_cast<IAnimCollisionManagerClass::CollisionModeType>(collisionMode);
	}

	void AnimCollisionManagerClass::CollisionMode::set(IAnimCollisionManagerClass::CollisionModeType value)
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper *>(InternalAnimCollisionManagerClassPointer);

		auto &collisionMode = helper->GetCollisionMode();

		collisionMode = static_cast<::AnimCollisionManagerClass::CollisionModeType>(value);
	}

	IDynamicVectorClass<ICollideableObjClass ^> ^AnimCollisionManagerClass::CollisionMeshes::get()
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper *>(InternalAnimCollisionManagerClassPointer);

		auto collisionMeshes = helper->GetCollisionMeshes();

		return gcnew CollideableObjClassDynamicVectorClass(IntPtr(collisionMeshes));
	}

	IntPtr AnimCollisionManagerClass::PushList::get()
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper *>(InternalAnimCollisionManagerClassPointer);

		auto &pushList = helper->GetPushList();

		return IntPtr(pushList);
	}

	void AnimCollisionManagerClass::PushList::set(IntPtr value)
	{
		auto helper = reinterpret_cast<AnimCollisionManagerClassHelper *>(InternalAnimCollisionManagerClassPointer);

		auto &pushList = helper->GetPushList();

		pushList = reinterpret_cast<::PushRecordClass *>(value.ToPointer());
	}
}