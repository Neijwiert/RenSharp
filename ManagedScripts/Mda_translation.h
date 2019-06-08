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

#include "Mda_event.h"

#pragma managed(push, off)

class DATranslationManager;

#pragma managed(pop)

namespace RenSharp
{
	interface class IDefinitionClass;

	public interface class IDATranslationManager : public IDAEventClass
	{
		property IntPtr DATranslationManagerPointer
		{
			IntPtr get();
		}
	};

	public ref class DATranslationManager : public DAEventClass, public IDATranslationManager
	{
		// Although you can instantiate a DATranslationManager class, it doesn't make any sense so I left it out
		public:
			DATranslationManager(IntPtr pointer);

			static String^ Translate(IScriptableGameObj^ obj);
			static String^ Translate(IWeaponClass^ weap);
			static String^ Translate(IDefinitionClass^ def);
			static String^ Translate(String^ preset);
			static String^ Translate(unsigned int defID);
			static String^ TranslateWithTeamName(IScriptableGameObj^ obj);
			static String^ TranslateWeapon(IScriptableGameObj^ obj);
			static String^ TranslateSoldier(IScriptableGameObj^ obj);

			property IntPtr DATranslationManagerPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::DAEventClass* InternalDAEventClassPointer
			{
				::DAEventClass* get() override;
			}

			property ::DATranslationManager* InternalDATranslationManagerPointer
			{
				virtual ::DATranslationManager* get();
			}
	};
}