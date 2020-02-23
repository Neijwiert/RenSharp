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

#include "RenSharpEventClass.h"
#include "RenSharpKeyHookStruct.h"
#include "IKeyHookInterface.h"

namespace RenSharp
{
	ref class RenSharpKeyHookClass;

	public ref class RenSharpKeyHookManager sealed : public RenSharpEventClass
	{
		private:
			enum class CheckKeyHookResult
			{
				NoneFound,
				FoundReturnFalse,
				FoundReturnTrue
			};

			bool disposedResources;
			
			static Collections::Generic::IDictionary<IKeyHookInterface^, array<Collections::Generic::IList<RenSharpKeyHookStruct^>^>^>^ keyHooks;
			static Collections::Generic::IList<RenSharpKeyHookClass^>^ globalKeyHooks;

		public:
			static RenSharpKeyHookManager();

			RenSharpKeyHookManager();
			~RenSharpKeyHookManager();

			void UnmanagedAttach() override;
			bool KeyHookEvent(IcPlayer^ player, String^ key) override;

		internal:
			static void UnregisterKeyHook(String^ trigger);

			static void RegisterKeyHook(RenSharpKeyHookClass^ keyHook);
			static void UnregisterKeyHook(RenSharpKeyHookClass^ keyHook);

			static void RegisterKeyHook(IKeyHookInterface^ owner, KeyHookGroup group, RenSharpKHDelegate^ func, String^ triggers, Object^ data);
			static void RegisterKeyHook(IKeyHookInterface^ owner, KeyHookGroup group, RenSharpKHDelegate^ func, String^ triggers);
			static void UnregisterKeyHook(IKeyHookInterface^ owner, KeyHookGroup group, String^ trigger);
			static void ClearKeyHooks(IKeyHookInterface^ owner, KeyHookGroup group);
			static Collections::Generic::IEnumerable<RenSharpKeyHookStruct^>^ GetKeyHooks(IKeyHookInterface^ owner, KeyHookGroup group);

			static property Collections::Generic::IEnumerable<RenSharpKeyHookClass^>^ GlobalKeyHooks
			{
				Collections::Generic::IEnumerable<RenSharpKeyHookClass^>^ get();
			}

		private:
			CheckKeyHookResult CheckKeyHook(RenSharpKeyHookClass^ keyHook, IcPlayer^ player, String^ key);
			CheckKeyHookResult CheckKeyHooks(Collections::Generic::IList<RenSharpKeyHookStruct^>^ keyHookCollection, IcPlayer^ player, String^ key);
	};
}