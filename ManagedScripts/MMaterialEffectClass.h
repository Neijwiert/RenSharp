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

#include "Mengine_vector.h"
#include "Mmultilist.h"

#pragma managed(push, off)

class MaterialEffectClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IPhysClass;

	public interface class IMaterialEffectClass : public IMultiListObjectClass, public IRefCountClass
	{
		void Timestep(float dt);

		void RenderPush(IntPtr rinfo, IPhysClass ^obj);

		void RenderPop(IntPtr rinfo);

		property IntPtr MaterialEffectClassPointer
		{
			IntPtr get();
		}

		property bool AutoRemoveEnabled
		{
			bool get();
			void set(bool value);
		}

		property bool SuppressShadows
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class MaterialEffectClass : public RefCountClass, public IMaterialEffectClass
	{
		private:
			IMultiListObjectClass ^multiListObjectClass;

		public:
			MaterialEffectClass(IntPtr pointer);

			bool Equals(Object ^other) override;

			virtual void Timestep(float dt) sealed;
			virtual void RenderPush(IntPtr rinfo, IPhysClass ^obj) sealed;
			virtual void RenderPop(IntPtr rinfo) sealed;

			property IntPtr Pointer
			{
				IntPtr get() override;

				protected:
					void set(IntPtr value) override;
			}

			property IntPtr MultiListObjectClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IntPtr MaterialEffectClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property IMultiListNodeClass ^ListNode
			{
				virtual IMultiListNodeClass ^get() sealed;
				virtual void set(IMultiListNodeClass ^value) sealed;
			}

			property bool AutoRemoveEnabled
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool SuppressShadows
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			property ::RefCountClass *InternalRefCountClassPointer
			{
				::RefCountClass *get() override;
			}

			property ::MultiListObjectClass *InternalMultiListObjectClassPointer
			{
				virtual ::MultiListObjectClass *get();
			}

			property ::MaterialEffectClass *InternalMaterialEffectClassPointer
			{
				virtual ::MaterialEffectClass *get();
			}
	};
}