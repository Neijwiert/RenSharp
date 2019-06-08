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
#include "IUnmanagedContainer.h"
#include "Mengine_vector.h"

#pragma managed(push, off)

class GameDefinition;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IGameDefinition : public IUnmanagedObject
	{
		property IntPtr GameDefinitionPointer
		{
			IntPtr get();
		}

		property String ^Name
		{
			String ^get();
			void set(String ^value);
		}

		property String ^MapName
		{
			String ^get();
			void set(String ^value);
		}

		property String ^ServerPresetsFile
		{
			String ^get();
			void set(String ^value);
		}

		property ISimpleVecClass<uint32> ^Packages
		{
			ISimpleVecClass<uint32> ^get();
			void set(ISimpleVecClass<uint32> ^value);
		}

		property String ^DisplayName
		{
			String ^get();
		}
	};

	public ref class GameDefinition : public AbstractUnmanagedObject, public IGameDefinition
	{
		private:
			GameDefinition();

		public:
			GameDefinition(IntPtr pointer);

			static IUnmanagedContainer<IGameDefinition ^> ^CreateGameDefinition();

			String ^ToString() override;
			bool Equals(Object ^other) override;

			property IntPtr GameDefinitionPointer
			{
				virtual IntPtr get() sealed;
			}

			property String ^Name
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property String ^MapName
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property String ^ServerPresetsFile
			{
				virtual String ^get() sealed;
				virtual void set(String ^value) sealed;
			}

			property ISimpleVecClass<uint32> ^Packages
			{
				virtual ISimpleVecClass<uint32> ^get() sealed;
				virtual void set(ISimpleVecClass<uint32> ^value) sealed;
			}

			property String ^DisplayName
			{
				virtual String ^get() sealed;
			}

		protected:
			bool InternalDestroyPointer() override;

			property ::GameDefinition *InternalGameDefinitionPointer
			{
				virtual ::GameDefinition *get();
			}
	};
}