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

#include "MArmedGameObjDef.h"

#pragma managed(push, off)

class SmartGameObjDef;

#pragma managed(pop)

namespace RenSharp
{
	public interface class ISmartGameObjDef : public IArmedGameObjDef
	{
		property IntPtr SmartGameObjDefPointer
		{
			IntPtr get();
		}

		property float SightRange
		{
			float get();
			void set(float value);
		}

		property float SightArc
		{
			float get();
			void set(float value);
		}

		property float ListenerScale
		{
			float get();
			void set(float value);
		}

		property bool IsStealthUnit
		{
			bool get();
			void set(bool value);
		}
	};

	public ref class SmartGameObjDef : public ArmedGameObjDef, public ISmartGameObjDef
	{
		public:
			SmartGameObjDef(IntPtr pointer);

			property IntPtr SmartGameObjDefPointer
			{
				virtual IntPtr get() sealed;
			}

			property float SightRange
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float SightArc
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property float ListenerScale
			{
				virtual float get() sealed;
				virtual void set(float value) sealed;
			}

			property bool IsStealthUnit
			{
				virtual bool get() sealed;
				virtual void set(bool value) sealed;
			}

		protected:
			property ::ArmedGameObjDef *InternalArmedGameObjDefPointer
			{
				::ArmedGameObjDef *get() override;
			}

			property ::SmartGameObjDef *InternalSmartGameObjDefPointer
			{
				virtual ::SmartGameObjDef *get();
			}
	};
}