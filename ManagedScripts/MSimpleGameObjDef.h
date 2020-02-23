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

#include "MPhysicalGameObjDef.h"

#pragma managed(push, off)

class SimpleGameObjDef;

#pragma managed(pop)

namespace RenSharp
{
	public interface class ISimpleGameObjDef : public IPhysicalGameObjDef
	{
		property IntPtr SimpleGameObjDefPointer
		{
			IntPtr get();
		}

		property bool IsEditorObject
		{
			bool get();
			void set(bool value);
		}

		property bool IsHiddenObject
		{
			bool get();
			void set(bool value);
		}

		property int PlayerTerminalType
		{
			int get();
			void set(int value);
		}
	};

	public ref class SimpleGameObjDef : public PhysicalGameObjDef, public ISimpleGameObjDef
	{
		public:
			SimpleGameObjDef(IntPtr pointer);

			property IntPtr SimpleGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

			property bool IsEditorObject
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property bool IsHiddenObject
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

			property int PlayerTerminalType
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

		protected:
			property ::PhysicalGameObjDef *InternalPhysicalGameObjDefPointer
			{
				::PhysicalGameObjDef *get() override;
			}

			property ::SimpleGameObjDef *InternalSimpleGameObjDefPointer
			{
				virtual ::SimpleGameObjDef *get();
			}
	};
}