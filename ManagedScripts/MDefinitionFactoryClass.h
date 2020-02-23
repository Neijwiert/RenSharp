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

#include "AbstractUnmanagedObject.h"
#include "IUnmanagedContainer.h"

#pragma managed(push, off)

class DefinitionFactoryClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IDefinitionClass;

	public interface class IDefinitionFactoryClass : public IUnmanagedObject
	{
		IUnmanagedContainer<IDefinitionClass^>^ Create();

		property IntPtr DefinitionFactoryClassPointer
		{
			IntPtr get();
		}

		property String^ Name
		{
			String^ get();
		}

		property uint32 ClassID
		{
			uint32 get();
		}

		property bool IsDisplayed
		{
			bool get();
		}
	};

	public ref class DefinitionFactoryClass : public AbstractUnmanagedObject, public IDefinitionFactoryClass
	{
		public:
			DefinitionFactoryClass(IntPtr pointer);

			String^ ToString() override;
			bool Equals(Object^ other) override;

			virtual IUnmanagedContainer<IDefinitionClass^>^ Create() sealed;

			property IntPtr DefinitionFactoryClassPointer
			{
				virtual IntPtr get() sealed;
			}

			property String^ Name
			{
				virtual String^ get() sealed;
			}

			property uint32 ClassID
			{
				virtual uint32 get() sealed;
			}

			property bool IsDisplayed
			{
				virtual bool get();
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::DefinitionFactoryClass* InternalDefinitionFactoryClassPointer
			{
				virtual ::DefinitionFactoryClass* get();
			}
	};
}