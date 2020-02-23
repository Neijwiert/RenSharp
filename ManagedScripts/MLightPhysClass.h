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

#include "MDecorationPhysClass.h"

#pragma managed(push, off)

class LightPhysClass;

#pragma managed(pop)

namespace RenSharp
{
	public interface class ILightPhysClass : public IDecorationPhysClass
	{
		property IntPtr LightPhysClassPointer
		{
			IntPtr get();
		}

		property int VisSectorID
		{
			int get();
			void set(int value);
		}

		property int GroupID
		{
			int get();
			void set(int value);
		}
	};

	public ref class LightPhysClass : public DecorationPhysClass, public ILightPhysClass
	{
		public:
			LightPhysClass(IntPtr pointer);

			ILightPhysClass ^AsLightPhysClass() override;

			property IntPtr LightPhysClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property int VisSectorID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

			property int GroupID
			{
				virtual int get() sealed;
				virtual void set(int value) sealed;
			}

		protected:
			property ::DecorationPhysClass *InternalDecorationPhysClassPointer
			{
				::DecorationPhysClass *get() override;
			}

			property ::LightPhysClass *InternalLightPhysClassPointer
			{
				virtual ::LightPhysClass *get();
			}
	};
}