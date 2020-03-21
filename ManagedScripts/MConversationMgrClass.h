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
#include "IUnmanagedContainer.h"

using namespace System;

#pragma managed(push, off)

class ConversationMgrClass;

#pragma managed(pop)

namespace RenSharp
{
	interface class IConversationClass;

	public interface class IConversationMgrClass : public ISaveLoadSubSystemClass
	{
		property IntPtr ConversationMgrClassPointer
		{
			IntPtr get();
		}
	};

	public ref class ConversationMgrClass : public SaveLoadSubSystemClass, public IConversationMgrClass
	{
		public:
			ConversationMgrClass(IntPtr pointer);

			static IUnmanagedContainer<IConversationClass^>^ FindConversation(String^ name);
			static IUnmanagedContainer<IConversationClass^>^ FindConversation(int id);

			property IntPtr ConversationMgrClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::SaveLoadSubSystemClass* InternalSaveLoadSubSystemClassPointer
			{
				::SaveLoadSubSystemClass* get() override;
			}

			property ::ConversationMgrClass* InternalConversationMgrClassPointer
			{
				virtual ::ConversationMgrClass* get();
			}
	};
}