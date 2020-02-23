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

#include "Mengine_io.h"

#pragma managed(push, off)

class FileFactoryListClass;

#pragma managed(pop)

namespace RenSharp
{
	public interface class IFileFactoryListClass : public IFileFactoryClass
	{
		void ResetSearchStart();

		property IntPtr FileFactoryListClassPointer
		{
			IntPtr get();
		}
	};

	public ref class FileFactoryListClass : public FileFactoryClass, public IFileFactoryListClass
	{
		public:
			FileFactoryListClass(IntPtr pointer);

			virtual void ResetSearchStart() sealed;

			property IntPtr FileFactoryListClassPointer
			{
				virtual IntPtr get() sealed;
			}

		protected:
			property ::FileFactoryClass* InternalFileFactoryClassPointer
			{
				::FileFactoryClass* get() override;
			}

			property ::FileFactoryListClass* InternalFileFactoryListClassPointer
			{
				virtual ::FileFactoryListClass* get();
			}
	};
}