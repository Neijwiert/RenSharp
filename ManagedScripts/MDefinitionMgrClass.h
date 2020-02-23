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

#include "MSaveLoadSubSystemClass.h"

#pragma managed(push, off)
#pragma warning(push)
#pragma warning(disable : 4251 4244 26495 26454)
#include <DefinitionMgrClass.h>
#pragma warning(pop) 
#pragma managed(pop)

namespace RenSharp
{
	interface class IDefinitionClass;

	public interface class IDefinitionMgrClass : public ISaveLoadSubSystemClass
	{
		enum class IDType : int
		{
			IDClass = ::DefinitionMgrClass::ID_CLASS,
			IDSuperClass = ::DefinitionMgrClass::ID_SUPERCLASS
		};

		property IntPtr DefinitionMgrClassPointer
		{
			IntPtr get();
		}
	};

	public ref class DefinitionMgrClass : public SaveLoadSubSystemClass, public IDefinitionMgrClass
	{
		public:
			DefinitionMgrClass(IntPtr pointer);

			static IDefinitionClass ^FindDefinition(uint32 id, bool twiddle);
			static IDefinitionClass ^FindNamedDefinition(String ^name, bool twiddle);
			static IDefinitionClass ^FindTypedDefinition(String ^name, uint32 classID, bool twiddle);
			static void RegisterDefinition(IDefinitionClass ^definition);
			static void UnregisterDefinition(IDefinitionClass ^definition);
			static IDefinitionClass ^GetFirst(uint32 id, IDefinitionMgrClass::IDType type);
			static IDefinitionClass ^GetFirst(uint32 id);
			static IDefinitionClass ^GetFirst();
			static IDefinitionClass ^GetNext(IDefinitionClass ^currDef, uint32 id, IDefinitionMgrClass::IDType type);
			static IDefinitionClass ^GetNext(IDefinitionClass ^currDef, uint32 id);
			static IDefinitionClass ^GetNext(IDefinitionClass ^currDef);
			static void FreeDefinitions();

			property IntPtr DefinitionMgrClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::SaveLoadSubSystemClass *InternalSaveLoadSubSystemClassPointer
			{
				::SaveLoadSubSystemClass *get() override;
			}

			property ::DefinitionMgrClass *InternalDefinitionMgrClassPointer
			{
				virtual ::DefinitionMgrClass *get();
			}
	};
}