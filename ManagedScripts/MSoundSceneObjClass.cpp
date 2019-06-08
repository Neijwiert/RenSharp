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
#include "MSoundSceneObjClass.h"

#include "MSound3DClass.h"
#include "MAudibleSoundClass.h"
#include "MVector3.h"
#include "MMatrix3D.h"
#include "MRenderObjClass.h"

namespace RenSharp
{

#pragma managed(push, off)

	class SoundSceneObjClassHelper : public ::SoundSceneObjClass
	{
		private:
			SoundSceneObjClassHelper() = default;

		public:
			::SoundCullObjClass *PeekCullableWrapper()
			{
				return Peek_Cullable_Wrapper();
			}

			void SetCullableWrapper(::SoundCullObjClass *obj)
			{
				Set_Cullable_Wrapper(obj);
			}

			::SoundSceneClass *&GetScene()
			{
				return m_Scene;
			}

			::SoundCullObjClass *&GetPhysWrapper()
			{
				return m_PhysWrapper;
			}

			::AudioCallbackClass *&GetPCallback()
			{
				return m_pCallback;
			}

			::AudioCallbackClass::EVENTS &GetRegisteredEvents()
			{
				return m_RegisteredEvents;
			}

			::RenderObjClass *&GetAttachedObject()
			{
				return m_AttachedObject;
			}

			int &GetAttachedBone()
			{
				return m_AttachedBone;
			}

			uint32 &GetUserData()
			{
				return m_UserData;
			}

			::RefCountClass *&GetUserObj()
			{
				return m_UserObj;
			}
	};

#pragma managed(pop)

	SoundSceneObjClass::SoundSceneObjClass(IntPtr pointer)
		: PersistClass(pointer)
	{
		multiListObjectClass = gcnew MultiListObjectClass(IntPtr(InternalMultiListObjectClassPointer));
		refCountClass = gcnew RefCountClass(IntPtr(InternalRefCountClassPointer));
	}

	bool SoundSceneObjClass::Equals(Object ^other)
	{
		if (PostLoadableClass::Equals(other))
		{
			return true;
		}

		if (ReferenceEquals(other, nullptr))
		{
			return false;
		}

		auto otherUnmanagedObj = dynamic_cast<IUnmanagedObject ^>(other);
		if (otherUnmanagedObj == nullptr || otherUnmanagedObj->Pointer.Equals(IntPtr::Zero))
		{
			return false;
		}

		auto otherMultiListObjectClass = dynamic_cast<IMultiListObjectClass ^>(other);
		if (otherMultiListObjectClass != nullptr)
		{
			if (multiListObjectClass->MultiListObjectClassPointer.Equals(otherMultiListObjectClass->MultiListObjectClassPointer))
			{
				return true;
			}
		}

		auto otherRefCountClass = dynamic_cast<IRefCountClass ^>(other);
		if (otherRefCountClass != nullptr)
		{
			if (refCountClass->RefCountClassPointer.Equals(otherRefCountClass->RefCountClassPointer))
			{
				return true;
			}
		}

		auto otherSoundSceneObjClass = dynamic_cast<ISoundSceneObjClass ^>(other);
		if (otherSoundSceneObjClass != nullptr)
		{
			if (SoundSceneObjClassPointer.Equals(otherSoundSceneObjClass->SoundSceneObjClassPointer))
			{
				return true;
			}
		}

		return false;
	}

	void SoundSceneObjClass::DeleteThis()
	{
		refCountClass->DeleteThis();
	}

	void SoundSceneObjClass::ReleaseRef()
	{
		refCountClass->ReleaseRef();
	}

	void SoundSceneObjClass::AddRef()
	{
		refCountClass->AddRef();
	}

	void SoundSceneObjClass::Release()
	{
		refCountClass->Release();
	}

	ISound3DClass ^SoundSceneObjClass::AsSound3DClass()
	{
		auto result = InternalSoundSceneObjClassPointer->As_Sound3DClass();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew Sound3DClass(IntPtr(result));
		}
	}

	IntPtr SoundSceneObjClass::AsSoundPseudo3DClass()
	{
		return IntPtr(InternalSoundSceneObjClassPointer->As_SoundPseudo3DClass());
	}

	IntPtr SoundSceneObjClass::AsFilteredSoundClass()
	{
		return IntPtr(InternalSoundSceneObjClassPointer->As_FilteredSoundClass());
	}

	IntPtr SoundSceneObjClass::AsListener3DClass()
	{
		return IntPtr(InternalSoundSceneObjClassPointer->As_Listener3DClass());
	}

	IAudibleSoundClass ^SoundSceneObjClass::AsAudibleSoundClass()
	{
		auto result = InternalSoundSceneObjClassPointer->As_AudibleSoundClass();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew AudibleSoundClass(IntPtr(result));
		}
	}

	bool SoundSceneObjClass::OnFrameUpdate(unsigned int milliseconds)
	{
		return InternalSoundSceneObjClassPointer->On_Frame_Update(milliseconds);
	}

	bool SoundSceneObjClass::OnFrameUpdate()
	{
		return InternalSoundSceneObjClassPointer->On_Frame_Update();
	}

	void SoundSceneObjClass::OnEvent(IAudioCallbackClass::AudioCallbackEvent event, uint32 param1, uint32 param2)
	{
		InternalSoundSceneObjClassPointer->On_Event(
			static_cast<::AudioCallbackClass::EVENTS>(event),
			param1,
			param2);
	}

	void SoundSceneObjClass::OnEvent(IAudioCallbackClass::AudioCallbackEvent event, uint32 param1)
	{
		InternalSoundSceneObjClassPointer->On_Event(
			static_cast<::AudioCallbackClass::EVENTS>(event),
			param1);
	}

	void SoundSceneObjClass::OnEvent(IAudioCallbackClass::AudioCallbackEvent event)
	{
		InternalSoundSceneObjClassPointer->On_Event(
			static_cast<::AudioCallbackClass::EVENTS>(event));
	}

	void SoundSceneObjClass::RegisterCallback(IAudioCallbackClass::AudioCallbackEvent events, IAudioCallbackClass ^callback)
	{
		if (callback == nullptr)
		{
			InternalSoundSceneObjClassPointer->Register_Callback(
				static_cast<::AudioCallbackClass::EVENTS>(events),
				nullptr);
		}
		else
		{
			InternalSoundSceneObjClassPointer->Register_Callback(
				static_cast<::AudioCallbackClass::EVENTS>(events),
				reinterpret_cast<::AudioCallbackClass *>(callback->AudioCallbackClassPointer.ToPointer()));
		}
	}

	void SoundSceneObjClass::RemoveCallback()
	{
		InternalSoundSceneObjClassPointer->Remove_Callback();
	}

	void SoundSceneObjClass::SetListenerTransform(Matrix3D tm)
	{
		::Matrix3D tmMat;

		Matrix3D::ManagedToUnmanagedMatrix3D(tm, tmMat);

		InternalSoundSceneObjClassPointer->Set_Listener_Transform(tmMat);
	}

	void SoundSceneObjClass::CullSound(bool culled)
	{
		InternalSoundSceneObjClassPointer->Cull_Sound(culled);
	}

	void SoundSceneObjClass::CullSound()
	{
		InternalSoundSceneObjClassPointer->Cull_Sound();
	}

	void SoundSceneObjClass::SetUserData(IRefCountClass ^userObj, uint32 user)
	{
		if (userObj == nullptr || userObj->RefCountClassPointer.ToPointer() == nullptr)
		{
			InternalSoundSceneObjClassPointer->Set_User_Data(nullptr, user);
		}
		else
		{
			InternalSoundSceneObjClassPointer->Set_User_Data(
				reinterpret_cast<::RefCountClass *>(userObj->RefCountClassPointer.ToPointer()),
				user);
		}
	}

	void SoundSceneObjClass::SetUserData(IRefCountClass ^userObj)
	{
		if (userObj == nullptr || userObj->RefCountClassPointer.ToPointer() == nullptr)
		{
			InternalSoundSceneObjClassPointer->Set_User_Data(nullptr);
		}
		else
		{
			InternalSoundSceneObjClassPointer->Set_User_Data(
				reinterpret_cast<::RefCountClass *>(userObj->RefCountClassPointer.ToPointer()));
		}
	}

	void SoundSceneObjClass::SetUserData()
	{
		InternalSoundSceneObjClassPointer->Set_User_Data();
	}

	IRefCountClass ^SoundSceneObjClass::PeekUserObj()
	{
		auto result = InternalSoundSceneObjClassPointer->Peek_User_Obj();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RefCountClass(IntPtr(result));
		}
	}

	void SoundSceneObjClass::AttachToObject(IRenderObjClass ^renderObj, int boneIndex)
	{
		if (renderObj == nullptr || renderObj->RenderObjClassPointer.ToPointer() == nullptr)
		{
			InternalSoundSceneObjClassPointer->Attach_To_Object(nullptr, boneIndex);
		}
		else
		{
			InternalSoundSceneObjClassPointer->Attach_To_Object(
				reinterpret_cast<::RenderObjClass *>(renderObj->RenderObjClassPointer.ToPointer()),
				boneIndex);
		}
	}

	void SoundSceneObjClass::AttachToObject(IRenderObjClass ^renderObj)
	{
		if (renderObj == nullptr || renderObj->RenderObjClassPointer.ToPointer() == nullptr)
		{
			InternalSoundSceneObjClassPointer->Attach_To_Object(nullptr);
		}
		else
		{
			InternalSoundSceneObjClassPointer->Attach_To_Object(
				reinterpret_cast<::RenderObjClass *>(renderObj->RenderObjClassPointer.ToPointer()));
		}
	}

	void SoundSceneObjClass::AttachToObject(IRenderObjClass ^renderObj, String ^boneName)
	{
		::RenderObjClass *renderObjPtr;
		if (renderObj == nullptr || renderObj->RenderObjClassPointer.ToPointer() == nullptr)
		{
			renderObjPtr = nullptr;
		}
		else
		{
			renderObjPtr = reinterpret_cast<::RenderObjClass *>(renderObj->RenderObjClassPointer.ToPointer());
		}

		if (boneName == nullptr)
		{
			InternalSoundSceneObjClassPointer->Attach_To_Object(renderObjPtr, nullptr);
		}
		else
		{
			IntPtr boneNameHandle = Marshal::StringToHGlobalAnsi(boneName);
			try
			{
				InternalSoundSceneObjClassPointer->Attach_To_Object(
					renderObjPtr,
					reinterpret_cast<char *>(boneNameHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(boneNameHandle);
			}
		}
	}

	IRenderObjClass ^SoundSceneObjClass::PeekParentObject()
	{
		auto result = InternalSoundSceneObjClassPointer->Peek_Parent_Object();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(result));
		}
	}

	void SoundSceneObjClass::ApplyAutoPosition()
	{
		InternalSoundSceneObjClassPointer->Apply_Auto_Position();
	}

	void SoundSceneObjClass::AddToScene(bool startPlaying)
	{
		InternalSoundSceneObjClassPointer->Add_To_Scene(startPlaying);
	}

	void SoundSceneObjClass::AddToScene()
	{
		InternalSoundSceneObjClassPointer->Add_To_Scene();
	}

	void SoundSceneObjClass::RemoveFromScene()
	{
		InternalSoundSceneObjClassPointer->Remove_From_Scene();
	}

	void SoundSceneObjClass::SetDropOffRadius(float radius)
	{
		InternalSoundSceneObjClassPointer->Set_DropOff_Radius(radius);
	}

	void SoundSceneObjClass::SetDropOffRadius()
	{
		InternalSoundSceneObjClassPointer->Set_DropOff_Radius();
	}

	IntPtr SoundSceneObjClass::Pointer::get()
	{
		return AbstractUnmanagedObject::Pointer::get();
	}

	void SoundSceneObjClass::Pointer::set(IntPtr value)
	{
		AbstractUnmanagedObject::Pointer::set(value);

		if (Pointer == IntPtr::Zero)
		{
			multiListObjectClass = nullptr;
			refCountClass = nullptr;
		}
		else
		{
			multiListObjectClass = gcnew MultiListObjectClass(IntPtr(InternalMultiListObjectClassPointer));
			refCountClass = gcnew RefCountClass(IntPtr(InternalRefCountClassPointer));
		}
	}

	IntPtr SoundSceneObjClass::MultiListObjectClassPointer::get()
	{
		return IntPtr(InternalMultiListObjectClassPointer);
	}

	IntPtr SoundSceneObjClass::RefCountClassPointer::get()
	{
		return IntPtr(InternalRefCountClassPointer);
	}

	IntPtr SoundSceneObjClass::SoundSceneObjClassPointer::get()
	{
		return IntPtr(InternalSoundSceneObjClassPointer);
	}

	IMultiListNodeClass ^SoundSceneObjClass::ListNode::get()
	{
		return multiListObjectClass->ListNode;
	}

	void SoundSceneObjClass::ListNode::set(IMultiListNodeClass ^value)
	{
		multiListObjectClass->ListNode = value;
	}

	int SoundSceneObjClass::NumRefs::get()
	{
		return refCountClass->NumRefs;
	}

	uint32 SoundSceneObjClass::ID::get()
	{
		return InternalSoundSceneObjClassPointer->Get_ID();
	}

	void SoundSceneObjClass::ID::set(uint32 value)
	{
		InternalSoundSceneObjClassPointer->Set_ID(value);
	}

	Vector3 SoundSceneObjClass::Position::get()
	{
		Vector3 result;

		Vector3::UnmanagedToManagedVector3(InternalSoundSceneObjClassPointer->Get_Position(), result);

		return result;
	}

	void SoundSceneObjClass::Position::set(Vector3 value)
	{
		::Vector3 tmp;

		Vector3::ManagedToUnmanagedVector3(value, tmp);

		InternalSoundSceneObjClassPointer->Set_Position(tmp);
	}

	Matrix3D SoundSceneObjClass::Transform::get()
	{
		Matrix3D result;

		Matrix3D::UnmanagedToManagedMatrix3D(InternalSoundSceneObjClassPointer->Get_Transform(), result);

		return result;
	}

	void SoundSceneObjClass::Transform::set(Matrix3D value)
	{
		::Matrix3D tmp;

		Matrix3D::ManagedToUnmanagedMatrix3D(value, tmp);

		InternalSoundSceneObjClassPointer->Set_Transform(tmp);
	}

	bool SoundSceneObjClass::IsSoundCulled::get()
	{
		return InternalSoundSceneObjClassPointer->Is_Sound_Culled();
	}

	uint32 SoundSceneObjClass::UserData::get()
	{
		return InternalSoundSceneObjClassPointer->Get_User_Data();
	}

	void SoundSceneObjClass::UserData::set(uint32 value)
	{
		auto helper = reinterpret_cast<SoundSceneObjClassHelper *>(InternalSoundSceneObjClassPointer);

		auto &userData = helper->GetUserData();

		userData = value;
	}

	int SoundSceneObjClass::AttachedBone::get()
	{
		return InternalSoundSceneObjClassPointer->Get_Parent_Bone();
	}

	void SoundSceneObjClass::AttachedBone::set(int value)
	{
		auto helper = reinterpret_cast<SoundSceneObjClassHelper *>(InternalSoundSceneObjClassPointer);

		auto &attachedBone = helper->GetAttachedBone();

		attachedBone = value;
	}

	bool SoundSceneObjClass::IsInScene::get()
	{
		return InternalSoundSceneObjClassPointer->Is_In_Scene();
	}

	float SoundSceneObjClass::DropOffRadius::get()
	{
		return InternalSoundSceneObjClassPointer->Get_DropOff_Radius();
	}

	bool SoundSceneObjClass::InternalDestroyPointer()
	{
		InternalSoundSceneObjClassPointer->Release();
		Pointer = IntPtr::Zero;

		return true;
	}

	IntPtr SoundSceneObjClass::PeekCullableWrapper()
	{
		auto helper = reinterpret_cast<SoundSceneObjClassHelper *>(InternalSoundSceneObjClassPointer);

		return IntPtr(helper->PeekCullableWrapper());
	}

	void SoundSceneObjClass::SetCullableWrapper(IntPtr obj)
	{
		auto helper = reinterpret_cast<SoundSceneObjClassHelper *>(InternalSoundSceneObjClassPointer);

		helper->SetCullableWrapper(
			reinterpret_cast<::SoundCullObjClass *>(obj.ToPointer()));
	}

	::PersistClass *SoundSceneObjClass::InternalPersistClassPointer::get()
	{
		return InternalSoundSceneObjClassPointer;
	}

	::MultiListObjectClass *SoundSceneObjClass::InternalMultiListObjectClassPointer::get()
	{
		return InternalSoundSceneObjClassPointer;
	}

	::RefCountClass *SoundSceneObjClass::InternalRefCountClassPointer::get()
	{
		return InternalSoundSceneObjClassPointer;
	}

	::SoundSceneObjClass *SoundSceneObjClass::InternalSoundSceneObjClassPointer::get()
	{
		return reinterpret_cast<::SoundSceneObjClass *>(Pointer.ToPointer());
	}

	IntPtr SoundSceneObjClass::Scene::get()
	{
		auto helper = reinterpret_cast<SoundSceneObjClassHelper *>(InternalSoundSceneObjClassPointer);

		auto &scene = helper->GetScene();

		return IntPtr(scene);
	}

	void SoundSceneObjClass::Scene::set(IntPtr value)
	{
		auto helper = reinterpret_cast<SoundSceneObjClassHelper *>(InternalSoundSceneObjClassPointer);

		auto &scene = helper->GetScene();

		scene = reinterpret_cast<::SoundSceneClass *>(value.ToPointer());
	}

	IntPtr SoundSceneObjClass::PhysWrapper::get()
	{
		auto helper = reinterpret_cast<SoundSceneObjClassHelper *>(InternalSoundSceneObjClassPointer);

		auto &physWrapper = helper->GetPhysWrapper();

		return IntPtr(physWrapper);
	}

	void SoundSceneObjClass::PhysWrapper::set(IntPtr value)
	{
		auto helper = reinterpret_cast<SoundSceneObjClassHelper *>(InternalSoundSceneObjClassPointer);

		auto &physWrapper = helper->GetPhysWrapper();

		physWrapper = reinterpret_cast<::SoundCullObjClass *>(value.ToPointer());
	}

	IAudioCallbackClass ^SoundSceneObjClass::PCallback::get()
	{
		auto helper = reinterpret_cast<SoundSceneObjClassHelper *>(InternalSoundSceneObjClassPointer);

		auto &pCallback = helper->GetPCallback();

		if (pCallback == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew AudioCallbackClass(IntPtr(pCallback));
		}
	}

	void SoundSceneObjClass::PCallback::set(IAudioCallbackClass ^value)
	{
		auto helper = reinterpret_cast<SoundSceneObjClassHelper *>(InternalSoundSceneObjClassPointer);

		auto &pCallback = helper->GetPCallback();

		if (value == nullptr || value->AudioCallbackClassPointer.ToPointer() == nullptr)
		{
			pCallback = nullptr;
		}
		else
		{
			pCallback = reinterpret_cast<::AudioCallbackClass *>(value->AudioCallbackClassPointer.ToPointer());
		}
	}

	IAudioCallbackClass::AudioCallbackEvent SoundSceneObjClass::RegisteredEvents::get()
	{
		auto helper = reinterpret_cast<SoundSceneObjClassHelper *>(InternalSoundSceneObjClassPointer);

		auto &registeredEvents = helper->GetRegisteredEvents();

		return static_cast<IAudioCallbackClass::AudioCallbackEvent>(registeredEvents);
	}

	void SoundSceneObjClass::RegisteredEvents::set(IAudioCallbackClass::AudioCallbackEvent value)
	{
		auto helper = reinterpret_cast<SoundSceneObjClassHelper *>(InternalSoundSceneObjClassPointer);

		auto &registeredEvents = helper->GetRegisteredEvents();

		registeredEvents = static_cast<::AudioCallbackClass::EVENTS>(value);
	}

	IRenderObjClass ^SoundSceneObjClass::AttachedObject::get()
	{
		auto helper = reinterpret_cast<SoundSceneObjClassHelper *>(InternalSoundSceneObjClassPointer);

		auto &attachedObject = helper->GetAttachedObject();

		if (attachedObject == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(attachedObject));
		}
	}

	void SoundSceneObjClass::AttachedObject::set(IRenderObjClass ^value)
	{
		auto helper = reinterpret_cast<SoundSceneObjClassHelper *>(InternalSoundSceneObjClassPointer);

		auto &attachedObject = helper->GetAttachedObject();

		if (value == nullptr || value->RenderObjClassPointer.ToPointer() == nullptr)
		{
			attachedObject = nullptr;
		}
		else
		{
			attachedObject = reinterpret_cast<::RenderObjClass *>(value->RenderObjClassPointer.ToPointer());
		}
	}

	IRefCountClass ^SoundSceneObjClass::UserObj::get()
	{
		auto helper = reinterpret_cast<SoundSceneObjClassHelper *>(InternalSoundSceneObjClassPointer);

		auto &userObj = helper->GetUserObj();

		if (userObj == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RefCountClass(IntPtr(userObj));
		}
	}

	void SoundSceneObjClass::UserObj::set(IRefCountClass ^value)
	{
		auto helper = reinterpret_cast<SoundSceneObjClassHelper *>(InternalSoundSceneObjClassPointer);

		auto &userObj = helper->GetUserObj();

		if (value == nullptr || value->RefCountClassPointer.ToPointer() == nullptr)
		{
			userObj = nullptr;
		}
		else
		{
			userObj = reinterpret_cast<::RefCountClass *>(value->RefCountClassPointer.ToPointer());
		}
	}
}