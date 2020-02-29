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

#include "MDefinition.h"

#pragma managed(push, off)

class TwiddlerClass;

#pragma managed(pop)

namespace RenSharp
{
	public interface class ITwiddlerClass : public IDefinitionClass
	{
		literal unsigned int TwiddlerClassClassID = 57344;

		IDefinitionClass^ Twiddle();

		property IntPtr TwiddlerClassPointer
		{
			IntPtr get();
		}

		property uint32 IndirectClassID
		{
			uint32 get();
			void set(uint32 value);
		}
	};

	public ref class TwiddlerClass : public DefinitionClass, public ITwiddlerClass
	{
		public:
			TwiddlerClass(IntPtr pointer);

			virtual IDefinitionClass^ Twiddle() sealed;

			property IntPtr TwiddlerClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property uint32 IndirectClassID
			{
				virtual uint32 get() sealed;
				virtual void set(uint32 value) sealed;
			}

		protected:
			property ::DefinitionClass* InternalDefinitionClassPointer
			{
				::DefinitionClass* get() override;
			}

			property ::TwiddlerClass* InternalTwiddlerClassPointer
			{
				virtual ::TwiddlerClass* get();
			}
	};
}