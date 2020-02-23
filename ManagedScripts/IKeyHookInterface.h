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

#include "RenSharpKeyHookStruct.h"

namespace RenSharp
{
	public interface class IKeyHookInterface : public IDisposable
	{
		bool FilterKeyHook(IcPlayer^ player, String^ key, Object^ data);

		void RegisterKeyHook(RenSharpKHDelegate^ func, String^ triggers, Object^ data);

		void RegisterKeyHook(RenSharpKHDelegate^ func, String^ triggers);

		void UnregisterKeyHook(String^ trigger);

		void ClearKeyHooks();

		property Collections::Generic::IEnumerable<RenSharpKeyHookStruct^>^ KeyHooks
		{
			Collections::Generic::IEnumerable<RenSharpKeyHookStruct^>^ get();
		}
	};
}