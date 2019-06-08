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

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <AnimControlClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	interface class IRenderObjClass;
	interface class IChunkSaveClass;
	interface class IChunkLoadClass;

	public enum class AnimMode : int
	{
		AnimModeOnce = ::ANIM_MODE_ONCE,
		AnimModeLoop = ::ANIM_MODE_LOOP,
		AnimModeStop = ::ANIM_MODE_STOP,
		AnimModeTarget = ::ANIM_MODE_TARGET
	};

	public interface class IAnimControlClass : public IUnmanagedObject
	{
		bool Save(IChunkSaveClass ^csave);

		bool Load(IChunkLoadClass ^cload);

		void SetModel(IRenderObjClass ^animModel);

		IRenderObjClass	^PeekModel();

		void SetAnimation(String ^name, float blendTime, float startFrame);

		void SetAnimation(String ^name, float blendTime);

		void SetAnimation(String ^name);

		void SetAnimation(IntPtr anim, float blendTime, float startFrame);

		void SetAnimation(IntPtr anim, float blendTime);

		void SetAnimation(IntPtr anim);

		void SetMode(AnimMode mode, float frame);

		IntPtr PeekAnimation();

		void Update(float dtime);

		property IntPtr AnimControlClassPointer
		{
			IntPtr get();
		}

		property AnimMode Mode
		{
			AnimMode get();
			void set(AnimMode value);
		}

		property bool IsComplete
		{
			bool get();
		}

		property String ^AnimationName
		{
			String ^get();
		}

		property float TargetFrame
		{
			float get();
			void set(float value);
		}

		property float CurrentFrame
		{
			float get();
		}
	};

	public ref class AnimControlClass : public AbstractUnmanagedObject, public IAnimControlClass
	{
		public:
			AnimControlClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual bool Save(IChunkSaveClass ^csave) sealed;
			virtual bool Load(IChunkLoadClass ^cload) sealed;
			virtual void SetModel(IRenderObjClass ^animModel) sealed;
			virtual IRenderObjClass	^PeekModel() sealed;
			virtual void SetAnimation(String ^name, float blendTime, float startFrame) sealed;
			virtual void SetAnimation(String ^name, float blendTime) sealed;
			virtual void SetAnimation(String ^name) sealed;
			virtual void SetAnimation(IntPtr anim, float blendTime, float startFrame) sealed;
			virtual void SetAnimation(IntPtr anim, float blendTime) sealed;
			virtual void SetAnimation(IntPtr anim) sealed;
			virtual void SetMode(AnimMode mode, float frame) sealed;
			virtual IntPtr PeekAnimation() sealed;
			virtual void Update(float dtime) sealed;

			property IntPtr AnimControlClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property AnimMode Mode
			{
				virtual AnimMode get() sealed;
				virtual void set(AnimMode value) sealed;
			}

			property bool IsComplete
			{
				virtual bool get() sealed;
			}

			property String ^AnimationName
			{
				virtual String ^get() sealed;
			}

			property float TargetFrame
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float CurrentFrame
			{
				virtual float get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::AnimControlClass *InternalAnimControlClassPointer
			{
				virtual ::AnimControlClass *get();
			}

			property IRenderObjClass ^Model
			{
				IRenderObjClass ^get();
				void set(IRenderObjClass ^value);
			}
	};
}