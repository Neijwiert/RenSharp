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

#include "MPhysicalGameObjDef.h"

#pragma managed(push, off)

class SpecialEffectsGameObjDef;

#pragma managed(pop)

namespace RenSharp
{
	public interface class ISpecialEffectsGameObjDef : public IPhysicalGameObjDef
	{
		property IntPtr SpecialEffectsGameObjDefPointer
		{
			IntPtr get();
		}
	};

	public ref class SpecialEffectsGameObjDef : public PhysicalGameObjDef, public ISpecialEffectsGameObjDef
	{
		public:
			SpecialEffectsGameObjDef(IntPtr pointer);

			property IntPtr SpecialEffectsGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::PhysicalGameObjDef* InternalPhysicalGameObjDefPointer
			{
				::PhysicalGameObjDef* get() override;
			}

			property ::SpecialEffectsGameObjDef* InternalSpecialEffectsGameObjDefPointer
			{
				virtual ::SpecialEffectsGameObjDef* get();
			}
	};
}