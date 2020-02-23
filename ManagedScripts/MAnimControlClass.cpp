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

#include "stdafx.h"
#include "MAnimControlClass.h"

#include "MRenderObjClass.h"
#include "MChunkClass.h"
#include "Imports.h"

namespace RenSharp
{

#pragma managed(push, off)

	class AnimControlClassHelper : public ::AnimControlClass
	{
		private:
			AnimControlClassHelper() = default;

		public:
			::RenderObjClass *&GetModel()
			{
				return Model;
			}
	};

#pragma managed(pop)

	AnimControlClass::AnimControlClass(IntPtr pointer)
		: AbstractUnmanagedObject(pointer)
	{

	}

	bool AnimControlClass::Equals(Object ^other)
	{
		if (AbstractUnmanagedObject::Equals(other))
		{
			return true;
		}

		IAnimControlClass ^otherThis = dynamic_cast<IAnimControlClass ^>(other);
		if (otherThis == nullptr)
		{
			return nullptr;
		}

		return AnimControlClassPointer.Equals(otherThis->AnimControlClassPointer);
	}

	bool AnimControlClass::Save(IChunkSaveClass ^csave)
	{
		if (csave == nullptr || csave->ChunkSaveClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("csave");
		}

		return InternalAnimControlClassPointer->Save(*reinterpret_cast<::ChunkSaveClass *>(csave->ChunkSaveClassPointer.ToPointer()));
	}

	bool AnimControlClass::Load(IChunkLoadClass ^cload)
	{
		if (cload == nullptr || cload->ChunkLoadClassPointer.ToPointer() == nullptr)
		{
			throw gcnew ArgumentNullException("cload");
		}

		return InternalAnimControlClassPointer->Load(*reinterpret_cast<::ChunkLoadClass *>(cload->ChunkLoadClassPointer.ToPointer()));
	}

	void AnimControlClass::SetModel(IRenderObjClass ^animModel)
	{
		if (animModel == nullptr || animModel->RenderObjClassPointer.ToPointer() == nullptr)
		{
			InternalAnimControlClassPointer->Set_Model(nullptr);
		}
		else
		{
			InternalAnimControlClassPointer->Set_Model(reinterpret_cast<::RenderObjClass *>(animModel->RenderObjClassPointer.ToPointer()));
		}
	}

	IRenderObjClass	^AnimControlClass::PeekModel()
	{
		auto result = InternalAnimControlClassPointer->Peek_Model();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(result));
		}
	}

	void AnimControlClass::SetAnimation(String ^name, float blendTime, float startFrame)
	{
		if (name == nullptr)
		{
			InternalAnimControlClassPointer->Set_Animation(static_cast<const char *>(nullptr), blendTime, startFrame);
		}
		else
		{
			IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
			try
			{
				InternalAnimControlClassPointer->Set_Animation(reinterpret_cast<char *>(nameHandle.ToPointer()), blendTime, startFrame);
			}
			finally
			{
				Marshal::FreeHGlobal(nameHandle);
			}
		}
	}

	void AnimControlClass::SetAnimation(String ^name, float blendTime)
	{
		if (name == nullptr)
		{
			InternalAnimControlClassPointer->Set_Animation(static_cast<const char *>(nullptr), blendTime);
		}
		else
		{
			IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
			try
			{
				InternalAnimControlClassPointer->Set_Animation(reinterpret_cast<char *>(nameHandle.ToPointer()), blendTime);
			}
			finally
			{
				Marshal::FreeHGlobal(nameHandle);
			}
		}
	}

	void AnimControlClass::SetAnimation(String ^name)
	{
		if (name == nullptr)
		{
			InternalAnimControlClassPointer->Set_Animation(static_cast<const char *>(nullptr));
		}
		else
		{
			IntPtr nameHandle = Marshal::StringToHGlobalAnsi(name);
			try
			{
				InternalAnimControlClassPointer->Set_Animation(reinterpret_cast<char *>(nameHandle.ToPointer()));
			}
			finally
			{
				Marshal::FreeHGlobal(nameHandle);
			}
		}
	}

	void AnimControlClass::SetAnimation(IntPtr anim, float blendTime, float startFrame)
	{
		if (anim.ToPointer() == nullptr)
		{
			InternalAnimControlClassPointer->Set_Animation(static_cast<::HAnimClass *>(nullptr), blendTime, startFrame);
		}
		else
		{
			InternalAnimControlClassPointer->Set_Animation(reinterpret_cast<::HAnimClass *>(anim.ToPointer()), blendTime, startFrame);
		}
	}

	void AnimControlClass::SetAnimation(IntPtr anim, float blendTime)
	{
		if (anim.ToPointer() == nullptr)
		{
			InternalAnimControlClassPointer->Set_Animation(static_cast<::HAnimClass *>(nullptr), blendTime);
		}
		else
		{
			InternalAnimControlClassPointer->Set_Animation(reinterpret_cast<::HAnimClass *>(anim.ToPointer()), blendTime);
		}
	}

	void AnimControlClass::SetAnimation(IntPtr anim)
	{
		if (anim.ToPointer() == nullptr)
		{
			InternalAnimControlClassPointer->Set_Animation(static_cast<::HAnimClass *>(nullptr));
		}
		else
		{
			InternalAnimControlClassPointer->Set_Animation(reinterpret_cast<::HAnimClass *>(anim.ToPointer()));
		}
	}

	void AnimControlClass::SetMode(AnimMode mode, float frame)
	{
		InternalAnimControlClassPointer->Set_Mode(static_cast<::AnimMode>(mode), frame);
	}

	IntPtr AnimControlClass::PeekAnimation()
	{
		return IntPtr(InternalAnimControlClassPointer->Peek_Animation());
	}

	void AnimControlClass::Update(float dtime)
	{
		InternalAnimControlClassPointer->Update(dtime);
	}

	IntPtr AnimControlClass::AnimControlClassPointer::get()
	{
		return IntPtr(InternalAnimControlClassPointer);
	}

	AnimMode AnimControlClass::Mode::get()
	{
		return static_cast<AnimMode>(InternalAnimControlClassPointer->Get_Mode());
	}

	void AnimControlClass::Mode::set(AnimMode value)
	{
		InternalAnimControlClassPointer->Set_Mode(static_cast<::AnimMode>(value));
	}

	bool AnimControlClass::IsComplete::get()
	{
		return InternalAnimControlClassPointer->Is_Complete();
	}

	String ^AnimControlClass::AnimationName::get()
	{
		auto result = InternalAnimControlClassPointer->Get_Animation_Name();
		if (result == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew String(result);
		}
	}

	float AnimControlClass::TargetFrame::get()
	{
		return InternalAnimControlClassPointer->Get_Target_Frame();
	}

	void AnimControlClass::TargetFrame::set(float value)
	{
		InternalAnimControlClassPointer->Set_Target_Frame(value);
	}

	float AnimControlClass::CurrentFrame::get()
	{
		return InternalAnimControlClassPointer->Get_Current_Frame();
	}

	bool AnimControlClass::InternalDestroyPointer()
	{
		Imports::DestroyAnimControlClass(InternalAnimControlClassPointer);
		Pointer = IntPtr::Zero;

		return true;
	}

	::AnimControlClass *AnimControlClass::InternalAnimControlClassPointer::get()
	{
		return reinterpret_cast<::AnimControlClass *>(Pointer.ToPointer());
	}

	IRenderObjClass ^AnimControlClass::Model::get()
	{
		auto helper = reinterpret_cast<AnimControlClassHelper *>(InternalAnimControlClassPointer);

		auto &model = helper->GetModel();

		if (model == nullptr)
		{
			return nullptr;
		}
		else
		{
			return gcnew RenderObjClass(IntPtr(model));
		}
	}

	void AnimControlClass::Model::set(IRenderObjClass ^value)
	{
		auto helper = reinterpret_cast<AnimControlClassHelper *>(InternalAnimControlClassPointer);

		auto &model = helper->GetModel();

		if (value == nullptr || value->RenderObjClassPointer.ToPointer() == nullptr)
		{
			model = nullptr;
		}
		else
		{
			model = reinterpret_cast<::RenderObjClass *>(value->RenderObjClassPointer.ToPointer());
		}
	}
}